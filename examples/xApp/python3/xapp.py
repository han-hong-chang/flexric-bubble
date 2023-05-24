import xapp_sdk as ric
import time
import pdb
import json
from tabulate import tabulate
import curses
from curses import wrapper
from curses.textpad import rectangle, Textbox
import math
from enum import Enum


class ServiceModelEnum(Enum):
    MAC = "mac_sm"
    SLICE = "slice_sm"
    KPM = "kpm_sm"
ServiceModel: ServiceModelEnum
ServiceModel = ServiceModelEnum.KPM

class SubTTIEnum(Enum):
    ms1 = ric.Interval_ms_1
    ms2 = ric.Interval_ms_2
    ms5 = ric.Interval_ms_5
    ms10 = ric.Interval_ms_10
SubTimeInterval: SubTTIEnum
SubTimeInterval = SubTTIEnum.ms10

####################
#### MAC INDICATION CALLBACK
####################
# Create a callback for KPM which derived it from C++ class kpm_cb
class KPMCallback(ric.kpm_cb):
    def __init__(self):
        # Inherit C++ kpm_cb class
        ric.kpm_cb.__init__(self)
    # Create an override C++ method
    def handle(self, ind):
        t_now = int(time.time() * 1000000)
        # # MeasData
        # ts = -1
        # if len(ind.MeasData) > 0:
        #     if len(ind.MeasData[0].measRecord) > 0:
        #         ts = ind.MeasData[0].measRecord[0].real_val
        #
        # # MeasInfo
        # for i in range(0, ind.MeasInfo_len):
        #     meas_infotype = ind.MeasInfo[i].meas_type
        #     measName = ind.MeasInfo[i].measName
        #     measID = ind.MeasInfo[i].measID
        #     measRecord = ind.MeasData[0].measRecord[i].real_val
        #     meas_recordtype = ind.MeasData[0].measRecord[i].type # need to check why type is equal to 0 when is real
        #     print(f"KPM ind_msg latency = {t_now - ts} us, "
        #               f"meas_infotype = {meas_infotype}, "
        #               f"measName = {measName}, "
        #               f"measRecord = {measRecord}, "
        #               f"meas_recordtype = {meas_recordtype}, "
        #               f"from E2 node type = {ind.id.type} nb_id = {ind.id.nb_id}")
        kpm_ind_to_dict_json(ind, t_now, ind.id)


####################
####  GLOBAL VALUE
####################
e2nodes = 0
MAX_E2_NODES = 10
slice_hndlr = []
mac_hndlr = []
kpm_hndlr = []
slice_cb = [0 for i in range(0, MAX_E2_NODES)]
mac_cb = [0 for i in range(0, MAX_E2_NODES)]
kpm_cb = [0 for i in range(0, MAX_E2_NODES)]
mac_cb_idx = 0
slice_cb_idx = 0
kpm_cb_idx = 0

# TODO: only support one UE
graph_dl_thr_val_arr = [[] for i in range(0, MAX_E2_NODES)]
graph_ul_thr_val_arr = [[] for i in range(0, MAX_E2_NODES)]
graph_add = [0 for i in range(0, MAX_E2_NODES)]

####################
####  KPM INDICATION MSG TO JSON
####################

kpm_stats_struct = {
    "Latency" : {},
    "RAN" : {
        "nb_id" : {},
        "ran_type" : {},
    },
    "UE" : {
        "num_of_meas" : {},
        "Measurement" : {}
    }
}

global global_kpm_stats
global_kpm_stats = [kpm_stats_struct for i in range(0, MAX_E2_NODES)]

def kpm_ind_to_dict_json(ind, t_now, id):
    global e2nodes
    # find e2 node idx
    n_idx = -1
    for n in e2nodes:
        if n.id.nb_id == id.nb_id:
            if n.id.type == id.type:
                n_idx = e2nodes.index(n)

                break
    if n_idx == -1:
        print("cannot find e2 node idx")
        return

    global global_kpm_stats
    global_kpm_stats[n_idx] = {
        "Latency" : {},
        "RAN" : {
            "nb_id" : {},
            "ran_type" : {},
        },
        "UEs" : []
    }

    kpm_stats = global_kpm_stats[n_idx]

    # e2 node id
    kpm_stats["RAN"]["nb_id"] = id.nb_id
    kpm_stats["RAN"]["ran_type"] = get_ngran_name(id.type)

    # initial
    kpm_dict = kpm_stats

    # latency
    if ind.MeasData_len > 0:
        if ind.MeasData[0].measRecord_len > 0:
            t_diff = t_now - ind.MeasData[0].measRecord[0].real_val
            kpm_dict.update({"Latency" :  t_diff})

    # measurement data for each UE
    for ue in range(0, ind.MeasData_len):
        ue_dict = {
            "num_of_meas" : 0,
            "Measurement" : [],
        }

        # get measurement value
        meas_record_arr = []
        num_of_meas_record = ind.MeasData[ue].measRecord_len
        ue_dict.update({"num_of_meas" : num_of_meas_record})
        for i in range(0, num_of_meas_record):
            value = "null"
            if ind.MeasData[ue].measRecord[i].type == 0:
                value = ind.MeasData[ue].measRecord[i].real_val
            elif ind.MeasData[ue].measRecord[i].type == 1:
                value = ind.MeasData[ue].measRecord[i].int_val
            else:
                value = "null"
            meas_record_arr.append(value)

        # get measurement name
        meas_name_arr = []
        if ind.MeasInfo_len > 0:
            num_of_meas_info = ind.MeasInfo_len
            for i in range(0, num_of_meas_info):
                name = ind.MeasInfo[i].measName
                meas_name_arr.append(name)

        # store measurement name and value to global_kpm_stats
        # store the first UE's current measurement value to graph
        graph_dl_thr_val_cur = -1
        graph_ul_thr_val_cur = -1
        for mrecord, mname in zip(meas_record_arr, meas_name_arr):
            meas_dict = {
                "name": mname,
                "value": mrecord
            }
            ue_dict["Measurement"].append(meas_dict)
            if ue == 0 and str(mname).rstrip('\x00') == "dl_thr":
                graph_dl_thr_val_cur = round(float(mrecord/1000000), 2)
            if ue == 0 and str(mname).rstrip('\x00') == "ul_thr":
                graph_ul_thr_val_cur = round(float(mrecord/1000000), 2)
        kpm_dict["UEs"].append(ue_dict)

        # add value per 100*sample rate
        global graph_dl_thr_val_arr, graph_ul_thr_val_arr, graph_add
        if ue == 0 and graph_add[n_idx]%10 == 0:
            graph_dl_thr_val_arr[n_idx].append(graph_dl_thr_val_cur)
            graph_ul_thr_val_arr[n_idx].append(graph_ul_thr_val_cur)
    graph_add[n_idx] += 1


def print_kpm_stats(n_idx):
    global global_kpm_stats
    kpm_stats = global_kpm_stats[n_idx]
    # RAN
    kpm_stats_table = []
    kpm_ind_col_names = []
    if len(kpm_stats["UEs"]) > 0:
        len_meas = int(kpm_stats["UEs"][0]["num_of_meas"])
        kpm_ind_col_names.append("Latency (us)")
        kpm_ind_col_names.append("UE - rnti")
        for i in range(0, len_meas):
            meas_name_str = str(kpm_stats["UEs"][0]["Measurement"][i]["name"]).rstrip('\x00')
            # print(meas_name_str)
            if meas_name_str == "timestamp" or meas_name_str == "rnti":
                continue

            meas_name_unit = ""
            if meas_name_str == "dl_thr" or meas_name_str == "ul_thr":
                meas_name_unit = meas_name_str + " (Mbps)"
            elif meas_name_str == "dl_tx" or meas_name_str == "ul_tx":
                meas_name_unit = meas_name_str + " (Bytes)"
            elif meas_name_str == "dl_bler":
                meas_name_unit = meas_name_str + " (%)"
            else:
                meas_name_unit = meas_name_str
            if len(meas_name_unit) > 0:
                kpm_ind_col_names.append(meas_name_unit)
    # print(kpm_ind_col_names)

    lat = kpm_stats["Latency"]
    for ue in range(0, len(kpm_stats["UEs"])):
        len_meas = int(kpm_stats["UEs"][ue]["num_of_meas"])

        info = [lat]
        rnti = -1
        tmp_value = []
        for i in range(0, len_meas):
            meas_name_str = str(kpm_stats["UEs"][ue]["Measurement"][i]["name"]).rstrip('\x00')
            # print(meas_name_str)
            if meas_name_str == "timestamp":
                continue
            elif meas_name_str == "rnti":
                rnti = kpm_stats["UEs"][ue]["Measurement"][i]["value"]
                info.append(rnti)
            elif meas_name_str == "dl_thr" or meas_name_str == "ul_thr":
                print_value = round(float(kpm_stats["UEs"][ue]["Measurement"][i]["value"])/1000000, 2)
                tmp_value.append(print_value)
            else:
                print_value = kpm_stats["UEs"][ue]["Measurement"][i]["value"]
                tmp_value.append(print_value)

        for v in tmp_value:
            info.append(v)
        if len(info) > 0:
            kpm_stats_table.append(info)

    print(tabulate(kpm_stats_table, headers=kpm_ind_col_names, tablefmt="grid"))

def print_dl_ul_graph(n_idx):
    def main(stdscr):
        global graph_ul_thr_val_arr
        ul_val = graph_ul_thr_val_arr[n_idx]
        global graph_dl_thr_val_arr
        dl_val = graph_dl_thr_val_arr[n_idx]

        MIN_ul = 0
        MAX_ul = 0
        MIN_dl = 0
        MAX_dl = 0

        # run for 10 secs
        for i in range(100):
            time.sleep(0.1)
            scr_maxx, scr_maxy = stdscr.getmaxyx()

            dl_thr_name = "dl_thr"
            ul_thr_name = "ul_thr"

            stdscr.clear()
            win_ul = curses.newwin(15, scr_maxy-30, scr_maxx-20, 14)
            win_dl = curses.newwin(15, scr_maxy-30, scr_maxx-38, 14)

            stdscr.addstr(scr_maxx-22, 30, "{0}: {1} Mbps".format(ul_thr_name.rstrip('\x00'), ul_val[-1]))
            stdscr.addstr(scr_maxx-40, 30, "{0}: {1} Mbps".format(dl_thr_name.rstrip('\x00'), dl_val[-1]))

            box_ul = curses.textpad.Textbox(win_ul)
            box_dl = curses.textpad.Textbox(win_dl)

            curses.textpad.rectangle(stdscr, 14, scr_maxx-40, scr_maxx-23, scr_maxy-10)
            curses.textpad.rectangle(stdscr, 32, scr_maxx-40, scr_maxx-5, scr_maxy-10)

            filter_ul_val = [x for x in ul_val if x>=0]
            MIN_ul = min(filter_ul_val)
            MAX_ul = max(filter_ul_val)

            filter_dl_val = [x for x in dl_val if x>=0]
            MIN_dl = min(filter_dl_val)
            MAX_dl = max(filter_dl_val)

            ul_norm_value = [0 for i in range(0, len(ul_val))]
            dl_norm_value = [0 for i in range(0, len(ul_val))]


            for i in range(len(ul_norm_value)):
                if MAX_ul == MIN_ul:
                    ul_norm_value[i] = 1
                else:
                    tmp = math.trunc(round((ul_val[i] - MIN_ul) / (MAX_ul - MIN_ul) * 9 + 1))
                    ul_norm_value[i] = tmp

            for i in range(len(dl_norm_value)):
                if MAX_dl == MIN_dl:
                    dl_norm_value[i] = 1
                else:
                    tmp = math.trunc(round((dl_val[i] - MIN_dl) / (MAX_dl - MIN_dl) * 9 + 1))
                    dl_norm_value[i] = tmp

            position = 40
            for i in range(1, 16):

                if len(ul_norm_value) >= i and  len(ul_val) >= 1:
                    win_ul.vline(14-ul_norm_value[-i], scr_maxy-position, '|', ul_norm_value[-i])
                    win_ul.addstr(13-ul_norm_value[-i], scr_maxy-position-1, "{}" .format(ul_val[-i]))
                else:
                    win_ul.vline(14-1, scr_maxy-position, '|', 1)
                    win_ul.addstr(13-1, scr_maxy-position+1, "{}" .format(0))

                position += 10


            position = 40
            for i in range(1, 16):

                if len(dl_norm_value) >= i and  len(dl_val) >= 1:
                    win_dl.vline(14-dl_norm_value[-i], scr_maxy-position, '|', dl_norm_value[-i])
                    win_dl.addstr(13-dl_norm_value[-i], scr_maxy-position-1, "{}" .format(dl_val[-i]))
                else:
                    win_dl.vline(14-1, scr_maxy-position, '|', 1)
                    win_dl.addstr(13-1, scr_maxy-position+1, "{}" .format(0))

                position += 10

            stdscr.addstr(scr_maxx-37,2, "MAX:{0} Mbps" .format(MAX_dl))
            stdscr.addstr(scr_maxx-(38-14),2, "MIN:{0} Mbps" .format(MIN_dl))
            stdscr.addstr(scr_maxx-19,2, "MAX:{0} Mbps" .format(MAX_ul))
            stdscr.addstr(scr_maxx-(20-14),2, "MIN:{0} Mbps" .format(MIN_ul))

            stdscr.refresh()
            win_ul.refresh()
            win_dl.refresh()

        curses.endwin()
    wrapper(main)

####################
#### MAC INDICATION CALLBACK
####################
class MACCallback(ric.mac_cb):
    # Define Python class 'constructor'
    def __init__(self):
        # Call C++ base class constructor
        ric.mac_cb.__init__(self)
    # Override C++ method: virtual void handle(swig_mac_ind_msg_t a) = 0;
    def handle(self, ind):
        # Print swig_mac_ind_msg_t
        if len(ind.ue_stats) > 0:
            t_now = time.time_ns() / 1000.0
            t_mac = ind.tstamp / 1.0
            t_diff = t_now - t_mac
            # print(f"MAC Indication tstamp {t_now} diff {t_diff} e2 node type {ind.id.type} nb_id {ind.id.nb_id}")
            # print('MAC rnti = ' + str(ind.ue_stats[0].rnti))

####################
####  SLICE INDICATION MSG TO JSON
####################
slice_stats_struct = {
    "RAN" : {
        "nb_id" : {},
        "ran_type" : {},
        "dl" : {}
        # TODO: handle the ul slice stats, currently there is no ul slice stats in database(SLICE table)
        # "ul" : {}
    },
    "UE" : {}
}

global global_slice_stats
global_slice_stats = [slice_stats_struct for i in range(0, MAX_E2_NODES)]

def slice_ind_to_dict_json(ind, id):
    global e2nodes
    # find e2 node idx
    n_idx = -1
    for n in e2nodes:
        if n.id.nb_id == id.nb_id:
            if n.id.type == id.type:
                n_idx = e2nodes.index(n)
                break
    if n_idx == -1:
        print("cannot find e2 node idx")
        return

    global global_slice_stats
    global_slice_stats[n_idx] = {
        "RAN" : {
            "nb_id" : {},
            "ran_type" : {},
            "dl" : {}
            # TODO: handle the ul slice stats, currently there is no ul slice stats in database(SLICE table)
            # "ul" : {}
        },
        "UE" : {}
    }
    slice_stats = global_slice_stats[n_idx]

    # RAN - e2 node id
    slice_stats["RAN"]["nb_id"] = id.nb_id
    slice_stats["RAN"]["ran_type"] = get_ngran_name(id.type)
    # RAN - dl
    dl_dict = slice_stats["RAN"]["dl"]
    if ind.slice_stats.dl.len_slices <= 0:
        dl_dict["num_of_slices"] = ind.slice_stats.dl.len_slices
        dl_dict["slice_sched_algo"] = "null"
        dl_dict["ue_sched_algo"] = ind.slice_stats.dl.sched_name[0]
    else:
        dl_dict["num_of_slices"] = ind.slice_stats.dl.len_slices
        dl_dict["slice_sched_algo"] = "null"
        dl_dict["slices"] = []
        slice_algo = ""
        for s in ind.slice_stats.dl.slices:
            if s.params.type == 1: # TODO: convert from int to string, ex: type = 1 -> STATIC
                slice_algo = "STATIC"
            elif s.params.type == 2:
                slice_algo = "NVS"
            elif s.params.type == 4:
                slice_algo = "EDF"
            else:
                slice_algo = "unknown"
            dl_dict.update({"slice_sched_algo" : slice_algo})

            slices_dict = {
                "index" : s.id,
                "label" : s.label[0],
                "ue_sched_algo" : s.sched[0],
            }
            if dl_dict["slice_sched_algo"] == "STATIC":
                slices_dict["slice_algo_params"] = {
                    "pos_low" : s.params.u.sta.pos_low,
                    "pos_high" : s.params.u.sta.pos_high
                }
            elif dl_dict["slice_sched_algo"] == "NVS":
                if s.params.u.nvs.conf == 0: # TODO: convert from int to string, ex: conf = 0 -> RATE
                    slices_dict["slice_algo_params"] = {
                        "type" : "RATE",
                        "mbps_rsvd" : s.params.u.nvs.u.rate.u1.mbps_required,
                        "mbps_ref" : s.params.u.nvs.u.rate.u2.mbps_reference
                    }
                elif s.params.u.nvs.conf == 1: # TODO: convert from int to string, ex: conf = 1 -> CAPACITY
                    slices_dict["slice_algo_params"] = {
                        "type" : "CAPACITY",
                        "pct_rsvd" : s.params.u.nvs.u.capacity.u.pct_reserved
                    }
                else:
                    slices_dict["slice_algo_params"] = {"type" : "unknown"}
            elif dl_dict["slice_sched_algo"] == "EDF":
                slices_dict["slice_algo_params"] = {
                    "deadline" : s.params.u.edf.deadline,
                    "guaranteed_prbs" : s.params.u.edf.guaranteed_prbs,
                    "max_replenish" : s.params.u.edf.max_replenish
                }
            else:
                print("unknown slice algorithm, cannot handle params")
            dl_dict["slices"].append(slices_dict)

    # RAN - ul
    # TODO: handle the ul slice stats, currently there is no ul slice stats in database(SLICE table)
    # ul_dict = slice_stats["RAN"]["ul"]
    # if ind.slice_stats.ul.len_slices <= 0:
    #     dl_dict["num_of_slices"] = ind.slice_stats.ul.len_slices
    #     dl_dict["slice_sched_algo"] = "null"
    #     dl_dict["ue_sched_algo"] = ind.slice_stats.ul.sched_name

    # UE
    ue_dict = slice_stats["UE"]
    if ind.ue_slice_stats.len_ue_slice <= 0:
        ue_dict["num_of_ues"] = ind.ue_slice_stats.len_ue_slice
    else:
        ue_dict["num_of_ues"] = ind.ue_slice_stats.len_ue_slice
        ue_dict["ues"] = []
        for u in ind.ue_slice_stats.ues:
            ues_dict = {}
            dl_id = "null"
            if u.dl_id >= 0 and dl_dict["num_of_slices"] > 0:
                dl_id = u.dl_id
            ues_dict = {
                "rnti" : hex(u.rnti),
                "assoc_dl_slice_id" : dl_id
                # TODO: handle the associated ul slice id, currently there is no ul slice id in database(UE_SLICE table)
                # "assoc_ul_slice_id" : ul_id
            }
            ue_dict["ues"].append(ues_dict)

    ind_dict = slice_stats
    ind_json = json.dumps(ind_dict)

    json_fname = "rt_slice_stats_nb_id" + str(id.nb_id)+ ".json"
    with open(json_fname, "w") as outfile:
        outfile.write(ind_json)
    # print(ind_dict)



####################
#### SLICE INDICATION CALLBACK
####################
class SLICECallback(ric.slice_cb):
    # Define Python class 'constructor'
    def __init__(self):
        # Call C++ base class constructor
        ric.slice_cb.__init__(self)
    # Override C++ method: virtual void handle(swig_slice_ind_msg_t a) = 0;
    def handle(self, ind):
        # Print swig_slice_ind_msg_t
        #if (ind.slice_stats.dl.len_slices > 0):
        #     print('SLICE Indication tstamp = ' + str(ind.tstamp))
        #     print('SLICE STATE: len_slices = ' + str(ind.slice_stats.dl.len_slices))
        #     print('SLICE STATE: sched_name = ' + str(ind.slice_stats.dl.sched_name[0]))
        #if (ind.ue_slice_stats.len_ue_slice > 0):
        #    print('UE ASSOC SLICE STATE: len_ue_slice = ' + str(ind.ue_slice_stats.len_ue_slice))
        slice_ind_to_dict_json(ind, ind.id)

####################
####  SLICE CONTROL FUNCS
####################
def fill_slice_conf(slice_params, slice_sched_algo):
    s = ric.fr_slice_t()
    s.id = slice_params["index"]
    s.label = slice_params["label"]
    s.len_label = len(slice_params["label"])
    s.sched = slice_params["ue_sched_algo"]
    s.len_sched = len(slice_params["ue_sched_algo"])
    if slice_sched_algo == "STATIC":
        s.params.type = ric.SLICE_ALG_SM_V0_STATIC
        s.params.u.sta.pos_low = slice_params["slice_algo_params"]["pos_low"]
        s.params.u.sta.pos_high = slice_params["slice_algo_params"]["pos_high"]
    elif slice_sched_algo == "NVS":
        s.params.type = ric.SLICE_ALG_SM_V0_NVS
        if slice_params["slice_algo_params"]["type"] == "RATE":
            s.params.u.nvs.conf = ric.SLICE_SM_NVS_V0_RATE
            s.params.u.nvs.u.rate.u1.mbps_required = slice_params["slice_algo_params"]["mbps_rsvd"]
            s.params.u.nvs.u.rate.u2.mbps_reference = slice_params["slice_algo_params"]["mbps_ref"]
            # print("ADD NVS DL SLCIE: id", s.id,
            # ", conf", s.params.u.nvs.conf,
            # ", mbps_rsrv", s.params.u.nvs.u.rate.u1.mbps_required,
            # ", mbps_ref", s.params.u.nvs.u.rate.u2.mbps_reference)
        elif slice_params["slice_algo_params"]["type"] == "CAPACITY":
            s.params.u.nvs.conf = ric.SLICE_SM_NVS_V0_CAPACITY
            s.params.u.nvs.u.capacity.u.pct_reserved = slice_params["slice_algo_params"]["pct_rsvd"]
            # print("ADD NVS DL SLCIE: id", s.id,
            # ", conf", s.params.u.nvs.conf,
            # ", pct_rsvd", s.params.u.nvs.u.capacity.u.pct_reserved)
        else:
            print("Unkown NVS conf")
    elif slice_sched_algo == "EDF":
        s.params.type = ric.SLICE_ALG_SM_V0_EDF
        s.params.u.edf.deadline = slice_params["slice_algo_params"]["deadline"]
        s.params.u.edf.guaranteed_prbs = slice_params["slice_algo_params"]["guaranteed_prbs"]
        s.params.u.edf.max_replenish = slice_params["slice_algo_params"]["max_replenish"]
    else:
        print("Unkown slice algo type")


    return s

####################
####  SLICE CONTROL PARAMETER EXAMPLE - ADD/MOD SLICE
####################
conf_static_slices = {
    "num_of_slices" : 3,
    "slice_sched_algo" : "STATIC",
    "slices" : [
        {
            "index" : 0,
            "label" : "s1",
            "ue_sched_algo" : "PF",
            "slice_algo_params" : {"pos_low" : 0, "pos_high" : 2},
        },
        {
            "index" : 2,
            "label" : "s2",
            "ue_sched_algo" : "PF",
            "slice_algo_params" : {"pos_low" : 3, "pos_high" : 10},
        },
        {
            "index" : 5,
            "label" : "s3",
            "ue_sched_algo" : "PF",
            "slice_algo_params" : {"pos_low" : 11, "pos_high" : 13},
        }
    ]
}

conf_nvs_slices_rate1 = {
    "num_of_slices" : 2,
    "slice_sched_algo" : "NVS",
    "slices" : [
        {
            "index" : 0,
            "label" : "s1",
            "ue_sched_algo" : "PF",
            "type" : "SLICE_SM_NVS_V0_RATE",
            "slice_algo_params" : {"type": "RATE", "mbps_rsvd" : 60, "mbps_ref" : 120},
        }
    ]
}

conf_nvs_slices_rate2 = {
    "num_of_slices" : 2,
    "slice_sched_algo" : "NVS",
    "slices" : [
        {
            "index" : 0,
            "label" : "s1",
            "ue_sched_algo" : "PF",
            "type" : "SLICE_SM_NVS_V0_RATE",
            "slice_algo_params" : {"type": "RATE", "mbps_rsvd" : 20, "mbps_ref" : 120},
        },
        {
            "index" : 2,
            "label" : "s2",
            "ue_sched_algo" : "PF",
            "type" : "SLICE_SM_NVS_V0_RATE",
            "slice_algo_params" : {"type": "RATE", "mbps_rsvd" : 100, "mbps_ref" : 120},
        }
    ]
}

conf_nvs_slices_cap2 = {
    "num_of_slices" : 2,
    "slice_sched_algo" : "NVS",
    "slices" : [
        {
            "index" : 0,
            "label" : "s1",
            "ue_sched_algo" : "PF",
            "type" : "SLICE_SM_NVS_V0_CAPACITY",
            "slice_algo_params" : {"type": "CAPACITY", "pct_rsvd" : 0.7},
        },
        {
            "index" : 2,
            "label" : "s2",
            "ue_sched_algo" : "PF",
            "type" : "SLICE_SM_NVS_V0_CAPACITY",
            "slice_algo_params" : {"type": "CAPACITY", "pct_rsvd" : 0.29},
        }
    ]
}

conf_nvs_slices_cap3 = {
    "num_of_slices" : 3,
    "slice_sched_algo" : "NVS",
    "slices" : [
        {
            "index" : 0,
            "label" : "s1",
            "ue_sched_algo" : "PF",
            "type" : "SLICE_SM_NVS_V0_CAPACITY",
            "slice_algo_params" : {"type": "CAPACITY", "pct_rsvd" : 0.5},
        },
        {
            "index" : 2,
            "label" : "s2",
            "ue_sched_algo" : "PF",
            "type" : "SLICE_SM_NVS_V0_CAPACITY",
            "slice_algo_params" : {"type": "CAPACITY", "pct_rsvd" : 0.3},
        },
        {
            "index" : 5,
            "label" : "s3",
            "ue_sched_algo" : "PF",
            "type" : "SLICE_SM_NVS_V0_CAPACITY",
            "slice_algo_params" : {"type": "CAPACITY", "pct_rsvd" : 0.2},
        }
    ]
}

conf_nvs_slices = {
    "num_of_slices" : 3,
    "slice_sched_algo" : "NVS",
    "slices" : [
        {
            "index" : 0,
            "label" : "s1",
            "ue_sched_algo" : "PF",
            "type" : "SLICE_SM_NVS_V0_CAPACITY",
            "slice_algo_params" : {"type": "CAPACITY", "pct_rsvd" : 0.5},
        },
        {
            "index" : 2,
            "label" : "s2",
            "ue_sched_algo" : "PF",
            "type" : "SLICE_SM_NVS_V0_RATE",
            "slice_algo_params" : {"type": "RATE", "mbps_rsvd" : 50, "mbps_ref" : 120},
        },
        {
            "index" : 5,
            "label" : "s3",
            "ue_sched_algo" : "PF",
            "type" : "SLICE_SM_NVS_V0_RATE",
            "slice_algo_params" : {"type": "RATE", "mbps_rsvd" : 5, "mbps_ref" : 120},
        }
    ]
}

conf_edf_slices = {
    "num_of_slices" : 3,
    "slice_sched_algo" : "EDF",
    "slices" : [
        {
            "index" : 0,
            "label" : "s1",
            "ue_sched_algo" : "PF",
            "slice_algo_params" : {"deadline" : 10, "guaranteed_prbs" : 20, "max_replenish" : 0},
        },
        {
            "index" : 2,
            "label" : "s2",
            "ue_sched_algo" : "RR",
            "slice_algo_params" : {"deadline" : 20, "guaranteed_prbs" : 20, "max_replenish" : 0},
        },
        {
            "index" : 5,
            "label" : "s3",
            "ue_sched_algo" : "MT",
            "slice_algo_params" : {"deadline" : 40, "guaranteed_prbs" : 10, "max_replenish" : 0},
        }
    ]
}

conf_reset_slices = {
    "num_of_slices" : 0
}

####################
####  SLICE CONTROL PARAMETER EXAMPLE - DELETE SLICE
####################
conf_delete_slices = {
    "num_of_slices" : 1,
    "delete_dl_slice_id" : [5]
}

####################
####  SLICE CONTROL PARAMETER EXAMPLE - ASSOC UE SLICE
####################
conf_assoc_ue_slice = {
    "num_of_ues" : 1,
    "ues" : [
        {
            "rnti" : 0, # TODO: get rnti from slice_ind_to_dict_json()
            "assoc_dl_slice_id" : 2
        }
    ]
}

def fill_slice_ctrl_msg(ctrl_type, ctrl_msg):
    msg = ric.slice_ctrl_msg_t()
    if ctrl_type == "ADDMOD":
        msg.type = ric.SLICE_CTRL_SM_V0_ADD
        dl = ric.ul_dl_slice_conf_t()
        # TODO: UL SLICE CTRL ADD
        # ul = ric.ul_dl_slice_conf_t()

        # ue_sched_algo can be "RR"(round-robin), "PF"(proportional fair) or "MT"(maximum throughput) and it has to be set in any len_slices
        ue_sched_algo = "PF"
        dl.sched_name = ue_sched_algo
        dl.len_sched_name = len(ue_sched_algo)

        dl.len_slices = ctrl_msg["num_of_slices"]
        slices = ric.slice_array(ctrl_msg["num_of_slices"])
        for i in range(0, ctrl_msg["num_of_slices"]):
            slices[i] = fill_slice_conf(ctrl_msg["slices"][i], ctrl_msg["slice_sched_algo"])

        dl.slices = slices
        msg.u.add_mod_slice.dl = dl
        # TODO: UL SLICE CTRL ADD
        # msg.u.add_mod_slice.ul = ul;
    elif ctrl_type == "DEL":
        msg.type = ric.SLICE_CTRL_SM_V0_DEL

        msg.u.del_slice.len_dl = ctrl_msg["num_of_slices"]
        del_dl_id = ric.del_dl_array(ctrl_msg["num_of_slices"])
        for i in range(ctrl_msg["num_of_slices"]):
            del_dl_id[i] = ctrl_msg["delete_dl_slice_id"][i]
        # print("DEL DL SLICE: id", del_dl_id)

        # TODO: UL SLCIE CTRL DEL
        msg.u.del_slice.dl = del_dl_id
    elif ctrl_type == "ASSOC_UE":
        msg.type = ric.SLICE_CTRL_SM_V0_UE_SLICE_ASSOC

        msg.u.ue_slice.len_ue_slice = ctrl_msg["num_of_ues"]
        assoc = ric.ue_slice_assoc_array(ctrl_msg["num_of_ues"])
        for i in range(ctrl_msg["num_of_ues"]):
            a = ric.ue_slice_assoc_t()
            a.rnti = ctrl_msg["ues"][i]["rnti"] # TODO: assign the rnti after get the indication msg from slice_ind_to_dict_json()
            a.dl_id = ctrl_msg["ues"][i]["assoc_dl_slice_id"]
            # TODO: UL SLICE CTRL ASSOC
            # a.ul_id = 0
            assoc[i] = a
            # print("ASSOC DL SLICE: <rnti:", a.rnti, "(NEED TO FIX)>, id", a.dl_id)
        msg.u.ue_slice.ues = assoc

    return msg

####################
#### CONVERT RAN TYPE TO STRING
####################
def get_ngran_name(ran_type):
    if ran_type == 0:
        return "ngran_eNB"
    elif ran_type == 2:
        return "ngran_gNB"
    elif ran_type == 5:
        return "ngran_gNB_CU"
    elif ran_type == 7:
        return "ngran_gNB_DU"
    else:
        return "Unknown"

####################
#### UPDATE CONNECTED E2 NODES
####################
def get_e2_nodes():
    return ric.conn_e2_nodes()

e2nodes_col_names = ["idx", "nb_id", "mcc", "mnc", "ran_type"]
def print_e2_nodes():
    global e2nodes
    e2nodes = get_e2_nodes()
    e2nodes_data = []
    conn = ric.conn_e2_nodes()
    for i in range(0, len(conn)):
        # TODO: need to fix cu_du_id in swig
        # cu_du_id = -1
        # if conn[i].id.cu_du_id:
        #     cu_du_id = conn[i].id.cu_du_id
        info = [i,
                conn[i].id.nb_id,
                conn[i].id.plmn.mcc,
                conn[i].id.plmn.mnc,
                get_ngran_name(conn[i].id.type)]
        # print(info)
        e2nodes_data.append(info)
    print(tabulate(e2nodes_data, headers=e2nodes_col_names, tablefmt="grid"))
    # print("E2 node : "
    #       "nb_id " + str(e2node.id.nb_id) + ",",
    #       "mcc " + str(e2node.id.plmn.mcc) + ",",
    #       "mnc " + str(e2node.id.plmn.mnc) + ",",
    #       "mnc_digit_len " + str(e2node.id.plmn.mnc_digit_len) + ",",
    #       "ran_type " + get_ngran_name(e2node.id.type) + ',',
    #       "cu_du_id " + str(e2node.id.cu_du_id if e2node.id.cu_du_id else -1))

slice_stats_col_names = ["nb_id", "ran_type", "slice_id", "label", "slice_sched_algo", "slice_algo_param1", "slice_algo_param2", "slice_algo_param3", "ue_sched_algo"]
ue_stats_col_names = ["rnti", "assoc_slice_id"]
def print_slice_stats(n_idx):
    global global_slice_stats
    s = global_slice_stats[n_idx]
    # RAN
    slice_stats_table = []
    nb_id = s["RAN"]["nb_id"]
    ran_type = s["RAN"]["ran_type"]
    len_slices = s["RAN"]["dl"]["num_of_slices"]
    for i in range(0, len_slices):
        param = []
        for key in s["RAN"]["dl"]["slices"][i]["slice_algo_params"].keys():
            param.append(key)

        slice_algo = s["RAN"]["dl"]["slice_sched_algo"]
        info = []
        if slice_algo == "STATIC":
            info = [nb_id,
                    ran_type,
                    s["RAN"]["dl"]["slices"][i]["index"],
                    s["RAN"]["dl"]["slices"][i]["label"],
                    slice_algo,
                    str(param[0]) + ":" + str(s["RAN"]["dl"]["slices"][i]["slice_algo_params"][param[0]]),
                    str(param[1]) + ":" + str(s["RAN"]["dl"]["slices"][i]["slice_algo_params"][param[1]]),
                    "null",
                    s["RAN"]["dl"]["slices"][i]["ue_sched_algo"]]
        elif slice_algo == "NVS":
            nvs_type = s["RAN"]["dl"]["slices"][i]["slice_algo_params"][param[0]]
            if nvs_type == "RATE":
                mbps_rsvd = float("{:.2f}".format(s["RAN"]["dl"]["slices"][i]["slice_algo_params"][param[1]]))
                mbps_ref = float("{:.2f}".format(s["RAN"]["dl"]["slices"][i]["slice_algo_params"][param[2]]))
                info = [nb_id,
                        ran_type,
                        s["RAN"]["dl"]["slices"][i]["index"],
                        s["RAN"]["dl"]["slices"][i]["label"],
                        str(slice_algo) + "-" + str(nvs_type),
                        str(param[1]) + ":" + str(mbps_rsvd),
                        str(param[2]) + ":" + str(mbps_ref),
                        "null",
                        s["RAN"]["dl"]["slices"][i]["ue_sched_algo"]]
            elif nvs_type == "CAPACITY":
                pct_rsvd = float("{:.2f}".format(s["RAN"]["dl"]["slices"][i]["slice_algo_params"][param[1]]))
                info = [nb_id,
                        ran_type,
                        s["RAN"]["dl"]["slices"][i]["index"],
                        s["RAN"]["dl"]["slices"][i]["label"],
                        str(slice_algo) + "-" + str(nvs_type),
                        str(param[1]) + ":" + str(pct_rsvd),
                        "null",
                        "null",
                        s["RAN"]["dl"]["slices"][i]["ue_sched_algo"]]
        elif slice_algo == "EDF":
            info = [nb_id,
                    ran_type,
                    s["RAN"]["dl"]["slices"][i]["index"],
                    s["RAN"]["dl"]["slices"][i]["label"],
                    str(slice_algo),
                    str(param[0]) + ":" + str(s["RAN"]["dl"]["slices"][i]["slice_algo_params"][param[0]]),
                    str(param[1]) + ":" + str(s["RAN"]["dl"]["slices"][i]["slice_algo_params"][param[1]]),
                    str(param[2]) + ":" + str(s["RAN"]["dl"]["slices"][i]["slice_algo_params"][param[2]]),
                    s["RAN"]["dl"]["slices"][i]["ue_sched_algo"]]
        if len(info) > 0:
            slice_stats_table.append(info)
    if len_slices == 0:
        info = [nb_id, ran_type]
        slice_stats_table.append(info)

    # UE
    ue_slice_stats_table = []
    len_ues = s['UE']["num_of_ues"]
    for i in range(0, len_ues):
        info = [s['UE']["ues"][i]["rnti"],
                s['UE']["ues"][i]["assoc_dl_slice_id"]]
        if len(info) > 0:
            ue_slice_stats_table.append(info)

    print(tabulate(slice_stats_table, headers=slice_stats_col_names, tablefmt="grid"))
    print(tabulate(ue_slice_stats_table, headers=ue_stats_col_names, tablefmt="grid"))

mod_slice_conf_col_names = ["slice_id", "label", "slice_sched_algo", "slice_algo_param1", "slice_algo_param2", "slice_algo_param3", "ue_sched_algo"]
del_slice_conf_col_names = ["slice_id"]
assoc_ue_conf_col_names = ["rnti", "assoc_slice_id"]
def print_slice_conf(type, conf):
    if type == "ADDMOD":
        # RAN
        mod_slice_conf_table = []
        len_slices = conf["num_of_slices"]
        for i in range(0, len_slices):
            param = []
            for key in conf["slices"][i]["slice_algo_params"].keys():
                param.append(key)

            slice_algo = conf["slice_sched_algo"]
            info = []
            if slice_algo == "STATIC":
                info = [conf["slices"][i]["index"],
                        conf["slices"][i]["label"],
                        slice_algo,
                        str(param[0]) + ":" + str(conf["slices"][i]["slice_algo_params"][param[0]]),
                        str(param[1]) + ":" + str(conf["slices"][i]["slice_algo_params"][param[1]]),
                        "null",
                        conf["slices"][i]["ue_sched_algo"]]
            elif slice_algo == "NVS":
                nvs_type = conf["slices"][i]["slice_algo_params"][param[0]]
                if nvs_type == "RATE":
                    mbps_rsvd = float("{:.2f}".format(conf["slices"][i]["slice_algo_params"][param[1]]))
                    mbps_ref = float("{:.2f}".format(conf["slices"][i]["slice_algo_params"][param[2]]))
                    info = [conf["slices"][i]["index"],
                            conf["slices"][i]["label"],
                            str(slice_algo) + "-" + str(nvs_type),
                            str(param[1]) + ":" + str(mbps_rsvd),
                            str(param[2]) + ":" + str(mbps_ref),
                            "null",
                            conf["slices"][i]["ue_sched_algo"]]
                elif nvs_type == "CAPACITY":
                    pct_rsvd = float("{:.2f}".format(conf["slices"][i]["slice_algo_params"][param[1]]))
                    info = [conf["slices"][i]["index"],
                            conf["slices"][i]["label"],
                            str(slice_algo) + "-" + str(nvs_type),
                            str(param[1]) + ":" + str(pct_rsvd),
                            "null",
                            "null",
                            conf["slices"][i]["ue_sched_algo"]]
            elif slice_algo == "EDF":
                info = [conf["slices"][i]["index"],
                        conf["slices"][i]["label"],
                        str(slice_algo),
                        str(param[0]) + ":" + str(conf["slices"][i]["slice_algo_params"][param[0]]),
                        str(param[1]) + ":" + str(conf["slices"][i]["slice_algo_params"][param[1]]),
                        str(param[2]) + ":" + str(conf["slices"][i]["slice_algo_params"][param[2]]),
                        conf["slices"][i]["ue_sched_algo"]]
            if len(info) > 0:
                mod_slice_conf_table.append(info)
        print(tabulate(mod_slice_conf_table, headers=mod_slice_conf_col_names))
    elif type == "DEL":
        del_slice_conf_table = []
        len_slices = conf["num_of_slices"]
        for i in range(0, len_slices):
            info = [conf["delete_dl_slice_id"][i]]
            if len(info) > 0:
                del_slice_conf_table.append(info)
        print(tabulate(del_slice_conf_table, headers=del_slice_conf_col_names))
    elif type == "ASSOC_UE":
        # UE
        assoc_ue_slice_conf_table = []
        len_ues = conf["num_of_ues"]
        for i in range(0, len_ues):
            info = [conf["ues"][i]["rnti"],
                    conf["ues"][i]["assoc_dl_slice_id"]]
            if len(info) > 0:
                assoc_ue_slice_conf_table.append(info)
        print(tabulate(assoc_ue_slice_conf_table, headers=assoc_ue_conf_col_names))

def subscribe_sm(n_idx, enum_sm, tti_enum):
    global e2nodes
    # default tti is 10 ms
    tti = ric.Interval_ms_10
    if tti_enum.value:
        tti = tti_enum.value
    else:
        print("unknown tti")

    sub_sm_str = enum_sm.value
    if sub_sm_str == "mac_sm":
        global mac_cb
        global mac_cb_idx
        mac_cb[mac_cb_idx] = MACCallback()
        global mac_hndlr
        hndlr = ric.report_mac_sm(e2nodes[n_idx].id, tti, mac_cb[mac_cb_idx])
        mac_hndlr.append(hndlr)
        mac_cb_idx+=1
    elif sub_sm_str == "slice_sm":
        global slice_cb
        global slice_cb_idx
        slice_cb[slice_cb_idx] = SLICECallback()
        global slice_hndlr
        hndlr = ric.report_slice_sm(e2nodes[n_idx].id, tti, slice_cb[slice_cb_idx])
        slice_hndlr.append(hndlr)
        slice_cb_idx+=1
    elif sub_sm_str == "kpm_sm":
        global kpm_cb
        global kpm_cb_idx
        kpm_cb[kpm_cb_idx] = KPMCallback()
        global kpm_hndlr
        hndlr = ric.report_kpm_sm(e2nodes[n_idx].id, tti, kpm_cb[kpm_cb_idx])
        kpm_hndlr.append(hndlr)
        kpm_cb_idx+=1
    else:
        print("unknown sm")

####################
####  xAPP INIT
####################
def init():
    # 0. init
    ric.init()
    # 1. get the length of connected e2 nodes
    global e2nodes
    e2nodes = get_e2_nodes()
    e2nodes_len = len(e2nodes)
    while e2nodes_len <= 0:
        temp_e2nodes = get_e2_nodes()
        if e2nodes != temp_e2nodes:
            print("Update connected E2 nodes")
            e2nodes = temp_e2nodes
            e2nodes_len = len(e2nodes)
        else:
            print("No E2 node connects")
            time.sleep(1)
    assert(len(e2nodes) > 0)

    print_e2_nodes()

    # TODO: need to process multi e2 nodes
    # e2node = e2nodes[0]
    # for n in e2nodes:
    #     # 3. subscribe slice sm and mac sm
    #     n_idx = e2nodes.index(n)
    #     global slice_cb
    #     slice_cb[n_idx] = SLICECallback()
    #     global slice_hndlr
    #     hndlr = ric.report_slice_sm(n.id, ric.Interval_ms_10, slice_cb[n_idx])
    #     slice_hndlr.append(hndlr)
    #
    #     global mac_cb
    #     mac_cb[n_idx] = MACCallback()
    #     global mac_hndlr
    #     hndlr = ric.report_mac_sm(n.id, ric.Interval_ms_10, mac_cb[n_idx])
    #     mac_hndlr.append(hndlr)
    #     time.sleep(2)
    #
    #     # 4. create slices, adding nvs_slices_rate1 by default
    #     msg = fill_slice_ctrl_msg("ADDMOD", conf_nvs_slices_cap2)
    #     ric.control_slice_sm(n.id, msg)

####################
####  SEND SLICE CONTROL MSG
####################
# cmd = "ADDMOD", "DEL", "ASSOC_UE"
# conf = conf_nvs_slices, conf_delete_slices, conf_assoc_ue_slice
def send_slice_ctrl_msg(n_idx, cmd, conf):
    msg = fill_slice_ctrl_msg(cmd, conf)
    global e2nodes
    ric.control_slice_sm(e2nodes[n_idx].id, msg)


####################
####  GET STATS in JSON
####################
def print_slice_stats_json():
    # TODO: need to process multi e2 nodes
    global global_slice_stats
    print(global_slice_stats)

def print_kpm_stats_json():
    # TODO: need to process multi e2 nodes
    global global_kpm_stats
    print(global_kpm_stats)

####################
####  END
####################
def end():
    global slice_hndlr
    for i in range(0, len(slice_hndlr)):
        ric.rm_report_slice_sm(slice_hndlr[i])
    global mac_hndlr
    for i in range(0, len(mac_hndlr)):
        ric.rm_report_mac_sm(mac_hndlr[i])
    global kpm_hndlr
    for i in range(0, len(kpm_hndlr)):
        ric.rm_report_kpm_sm(kpm_hndlr[i])

    for n in e2nodes:
        json_fname = "rt_slice_stats_nb_id" + str(n.id.nb_id)+ ".json"
        with open(json_fname, "w") as outfile:
            outfile.write(json.dumps({}))

    while ric.try_stop == 0:
        time.sleep(1)
    print('Test finished')



