import xapp_sdk as ric

import time
from helpers import SubscriptionHelper, ts_grouping, promscale_jsonize

import polars as pl
import json, snappy, requests, traceback, queue
from concurrent.futures import ThreadPoolExecutor

import signal
from multiprocessing import set_start_method, Manager, Process
from configs import CONFIGS

# import faulthandler
# faulthandler.enable()


##############
# SUBSCRIBER #
##############
class MACCallback(ric.mac_cb, SubscriptionHelper):
    # Define Python class 'constructor'
    def __init__(self, e2_id, target_metrics, test_checkpoint):
        # Call C++ base class constructor
        ric.mac_cb.__init__(self)

        # Call SubscriptionHelper's constructor
        SubscriptionHelper.__init__(self, e2_id, target_metrics, test_checkpoint)

    # Override C++ method: virtual void handle(swig_mac_ind_msg_t a) = 0;
    def handle(self, ind):
        if len(ind.ue_stats) > 0:
            ricmont_ms = time.time_ns()//1_000_000
            tstamp_ms = ind.tstamp // 1000

            try:
                global msg_queue
                for ue_stat in ind.ue_stats:
                    for metric in self.target_metrics:
                        msg_queue.put_nowait({
                            '__name__': metric, 'rnti': f"{ue_stat.rnti}",
                            'nb_id': f"{self.nb_id}", 'cu_du_id': f"{self.cu_du_id}",
                            'mcc': f"{self.mcc}", 'mnc': f"{self.mnc}",
                            'timestamp': tstamp_ms, 'value': getattr(ue_stat, metric),
                            'ricmonstamp': ricmont_ms
                        })

                # Report the latencies
                self.report_latency('MAC', tstamp_ms, ricmont_ms)
            except Exception as e:
                print("[MAC-callback] Exception caught:", e)
                return

class PDCPCallback(ric.pdcp_cb, SubscriptionHelper):
    # Define Python class 'constructor'
    def __init__(self, e2_id, target_metrics, test_checkpoint):
        # Call C++ base class constructor
        ric.pdcp_cb.__init__(self)

        # Call SubscriptionHelper's constructor
        SubscriptionHelper.__init__(self, e2_id, target_metrics, test_checkpoint)

    # Override C++ method: virtual void handle(swig_pdcp_ind_msg_t a) = 0;
    def handle(self, ind):
        if len(ind.rb_stats) > 0:
            ricmont_ms = time.time_ns()//1_000_000
            tstamp_ms = ind.tstamp // 1000

            try:
                global msg_queue
                for rb_stat in ind.rb_stats:
                    for metric in self.target_metrics:
                        msg_queue.put_nowait({
                            '__name__': f"pdcp_{metric}", 'rnti': f"{rb_stat.rnti}",
                            'nb_id': f"{self.nb_id}", 'cu_du_id': f"{self.cu_du_id}",
                            'mcc': f"{self.mcc}", 'mnc': f"{self.mnc}",
                            'timestamp': tstamp_ms, 'value': getattr(rb_stat, metric),
                            'ricmonstamp': ricmont_ms
                        })

                # Report the latencies
                self.report_latency('PDCP', tstamp_ms, ricmont_ms)
            except Exception as e:
                print("[PDCP-callback] Exception caught:", e)
                return

def subscriber(test_checkpoint=0):
    # Targeted metrics and intervals for each Service Model
    sm_book = {
        'PDCP': {'metrics': ['rxsdu_bytes', 'rxsdu_pkts', 'txsdu_bytes', 'txsdu_pkts'], 
                 'interval': 'Interval_ms_10'},
        'MAC':  {'metrics': ['dl_curr_tbs', 'ul_curr_tbs', 'dl_bler', 'ul_bler', 
                             'dl_mcs1', 'ul_mcs1', 'phr', 'wb_cqi'], 
                 'interval': 'Interval_ms_10'}
    }

    # E2-Node dictionary for status, subscriptions, and callback-handlers:
    e2_nodes_book = {
        (505, 1, 1, 0):     {'is_on': False,
                             'PDCP': [True, None, None], 'MAC': [True, None, None]},
        (505, 1, 2, 21):    {'is_on': False,
                             'PDCP': [True, None, None], 'MAC': [False]},
        (505, 1, 2, 22):    {'is_on': False,
                             'PDCP': [False],            'MAC': [True, None, None]},
        (505, 1, 3584, 0):  {'is_on': False,
                             'PDCP': [True, None, None], 'MAC': [True, None, None]}
    }

    # For reporting cycle times during testing
    lastcycle_ms, maxcycle_ms = 0, 0
    test_counter = 0

    ric.init()
    global is_running
    while True:
        conns = ric.conn_e2_nodes()
        conns_ids = {
            (conn.id.plmn.mcc, conn.id.plmn.mnc, conn.id.nb_id, conn.id.cu_du_id): conn.id
            for conn in conns
        }

        # [REMARK] ignore E2-Node that is NOT in the book!
        for e2_id, e2_sub in e2_nodes_book.items():
            if e2_sub['is_on'] and (not e2_id in conns_ids):
                e2_sub['is_on'] = False

                for sm in ['PDCP', 'MAC']:
                    if e2_sub[sm][0]:
                        # Cannot unsubscribe from a dead E2-Node:
                        # => TODO: Fix at FlexRIC
                        e2_sub[sm][2] = None

                print(f"[RICMon] Drop handlers of E2-Node: {e2_id}!")

            if (not e2_sub['is_on']) and (e2_id in conns_ids):
                e2_sub['is_on'] = True

                for sm in ['PDCP', 'MAC']:
                    if e2_sub[sm][0]:
                        if e2_sub[sm][1] is None:
                            e2_sub[sm][1] = globals()[f"{sm}Callback"](
                                                e2_id, target_metrics=sm_book[sm]['metrics'], 
                                                test_checkpoint=test_checkpoint
                                            )
                        e2_sub[sm][2] = getattr(ric, f"report_{sm.lower()}_sm")(
                                            conns_ids[e2_id], 
                                            getattr(ric, sm_book[sm]['interval']), 
                                            e2_sub[sm][1]
                                        )

                print(f"[RICMon] Subscribed to E2-Node: {e2_id}!")

        # Report the cycle times
        if test_checkpoint > 0:
            if test_counter != 0:
                maxcycle_ms = max(maxcycle_ms, time.time_ns()//1_000_000 - lastcycle_ms)
            lastcycle_ms = time.time_ns()//1_000_000

            if test_counter < test_checkpoint*100:
                test_counter += 1
            else:
                print(f"[RICMon] conn_e2_nodes(): {list(conns_ids.keys())};")
                print(f"\tmax-cycled every: {maxcycle_ms} (ms).")
                test_counter = 0
                maxcycle_ms = 0

        try:
            if not is_running.value:
                break
        except EOFError:
            break

    # When exiting, unsubscribe all existing handlers
    print('[Ctrl+C] Unsubscribing...')
    for _, e2_sub in e2_nodes_book.items():
        e2_sub['is_on'] = False

        for sm in ['PDCP', 'MAC']:
            if e2_sub[sm][0]:
                e2_sub[sm][1] = None

                if e2_sub[sm][2]:
                    getattr(ric, f"rm_report_{sm.lower()}_sm")(e2_sub[sm][2])
                    e2_sub[sm][2] = None

    # Stopping the SDK...
    print('[Ctrl+C] Stopping the SDK...')
    while ric.try_stop == 0:
        time.sleep(0.01)


##########
# WRITER #
##########
def publish(idx, msg_queue, session, min_batch_size=16,
            promscale_url='http://localhost:9201/write', is_test=False):
    # For reporting Througput & HOL-sojourn when exiting
    pushes_count, total_samples, total_sojourn = 0, 0, 0

    # Set the DataFrame schema & pick labels for GROUP BY
    msg_dtype = [('__name__', pl.Utf8), ('rnti', pl.Utf8), ('nb_id', pl.Utf8), 
                 ('cu_du_id', pl.Utf8), ('mcc', pl.Utf8), ('mnc', pl.Utf8), 
                 ('timestamp', pl.UInt64), ('value', pl.Float32), ('ricmonstamp', pl.UInt64)]
    labels_list = ['__name__', 'rnti', 'nb_id', 'cu_du_id', 'mcc', 'mnc']

    global is_running
    msgs_df = pl.DataFrame({}, schema=msg_dtype)
    while is_running:
        try:
            cur_size = msg_queue.qsize()
            msgs = [msg_queue.get(timeout=1) for _ in range(cur_size)]
            msgs_df.vstack(pl.DataFrame(msgs, schema=msg_dtype), in_place=True)
        except queue.Empty:
            print(f"[PUSHER-{idx}] Timeout while dequeuing; Ctrl+C?")
            break
        except Exception as e:
            print(f"[PUSHER-{idx}] Exception caught:", e)
            break

        if msgs_df.height >= min_batch_size:
            # GROUP into TimeSeries using the picked labels
            msgs_df.rechunk()
            ts_df = ts_grouping(labels_list, msgs_df)

            # SNAPPY Compression
            payload = "".join([json.dumps(promscale_jsonize(ts))
                               for ts in ts_df.iter_rows(named=True)])
            snappy_payload = snappy.compress(payload.encode('utf-8'))

            # POST to a Promscale (exception-prone)
            try:
                response = session.post(promscale_url, data=snappy_payload, timeout=1)
                if response.status_code != 200:
                    print(f"\n\t[PUSHER-{idx}] ERROR returned by Promscale!!!\n")
            except requests.exceptions.Timeout:
                print(f"\n\t[PUSHER-{idx}] Pushing to Promscale takes too long!!!\n")
            except Exception:
                traceback.print_exc()
            finally:
                response.close()

            # BENCHMARK
            endt_ms = time.time_ns()//1_000_000
            ricmont_ms = msgs_df['ricmonstamp'][0]
            total_sojourn += (endt_ms-ricmont_ms)

            pushes_count += 1
            total_samples += msgs_df.height
            if is_test:
                print(f"[PUSHER-{idx}] HOL-sojourn of {msgs_df.height} messages: \
                      {endt_ms-ricmont_ms} (ms).")

            msgs_df = pl.DataFrame({}, schema=msg_dtype)

    print(f"[PUSHER-{idx}] {total_samples} records \
          with AVG(HOL-sojourn) = {total_sojourn//pushes_count} (ms).")

def stats_writer(msg_queue, promscale_url, is_test, num_threads=2):
    # Session (connection pool) sharing between threads
    session = requests.Session()
    session.mount('http://', requests.adapters.HTTPAdapter(max_retries=0, pool_block=True,
                  pool_connections=1, pool_maxsize=num_threads*2))
    session.headers.update({'Content-Type': 'application/json', 'Content-Encoding': 'snappy'})

    # Handling Ctrl+C in the "spawned" Writer process
    def writer_sighandler(signal, frame):
        global is_running
        is_running = False
    signal.signal(signal.SIGINT, writer_sighandler)

    global is_running
    is_running = True
    with ThreadPoolExecutor(num_threads) as executor:
        for idx in range(num_threads):
            executor.submit(publish, idx, msg_queue, session,
                            promscale_url=promscale_url, is_test=is_test)

    try:
        print("[Ctrl+C] Clearing the shared queues...")
        while not msg_queue.empty():
            msg_queue.get()
    except Exception as e:
        print("[StatsWriter] Exception caught:", e)
    finally:
        session.close()


########
# MAIN #
########
def subscriber_sighandler(signal, frame):
    global is_running
    is_running.value = False

if __name__ == '__main__':
    set_start_method('spawn')

    global is_running, msg_queue
    manager = Manager()
    is_running = manager.Value(bool, True)
    msg_queue = manager.Queue()

    signal.signal(signal.SIGINT, subscriber_sighandler)
    stats_writer_proc = Process(target=stats_writer, 
                                args=(msg_queue, CONFIGS['promscale_url'], False))

    stats_writer_proc.start()
    subscriber(test_checkpoint=0)

    stats_writer_proc.join()
