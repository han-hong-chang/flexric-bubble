/* 
 * Layer between flexric E2SM callbacks and WS interface
 * it manages SUBSCRIPTION procedure (indication) and CTRL procedure
 */
#include "e2_sm_kpm_agent.h"
#include <stdio.h>
#include <libwebsockets.h>

#include "sm/kpm_sm/kpm_data_ie_wrapper.h"
#include "../../test/rnd/fill_rnd_data_kpm.h"
#include "util/time_now_us.h"
#include "util/byte_array.h"
#include "util/alg_ds/alg/defer.h"

#include "e2_sm_agent.h"
#include "ran_if.h"
#include "proxy_agent.h"
#include "ran_msg_hdlr.h"
#include "ringbuffer.h"
#include "notif_e2_ran.h"

static
gnb_e2sm_t fill_gnb_data(amarisoft_ue_stats_t ue_stats, global_e2_node_id_t id)
{
  gnb_e2sm_t gnb = {0};

  gnb.amf_ue_ngap_id = ue_stats.amf_ue_id;

  gnb.guami.plmn_id = (e2sm_plmn_t) {.mcc = id.plmn.mcc, .mnc = id.plmn.mnc, .mnc_digit_len = id.plmn.mnc_digit_len};
  // TODO: need metrics from AMR
  gnb.guami.amf_region_id = (rand() % 2^8) + 0;
  // TODO: need metrics from AMR
  gnb.guami.amf_set_id = (rand() % 2^10) + 0;
  // TODO: need metrics from AMR
  gnb.guami.amf_ptr = (rand() % 2^6) + 0;

  gnb.ran_ue_id = (uint64_t*)malloc(sizeof(uint64_t));
  *(gnb.ran_ue_id) = (uint64_t)ue_stats.ran_ue_id;
  return gnb;
}

static
gnb_e2sm_t fill_rnd_gnb_data(void)
{
  gnb_e2sm_t gnb = {0};
  gnb.amf_ue_ngap_id = (rand() % 2^40) + 0;
  gnb.guami.plmn_id = (e2sm_plmn_t) {.mcc = 505, .mnc = 1, .mnc_digit_len = 2};
  gnb.guami.amf_region_id = (rand() % 2^8) + 0;
  gnb.guami.amf_set_id = (rand() % 2^10) + 0;
  gnb.guami.amf_ptr = (rand() % 2^6) + 0;
  gnb.ran_ue_id = (uint64_t*)malloc(sizeof(uint64_t));
  *(gnb.ran_ue_id) = 123;
  return gnb;
}

static
ue_id_e2sm_t fill_ue_id_data(amarisoft_ue_stats_t ue_stats, global_e2_node_id_t id)
{
  ue_id_e2sm_t ue_id_data = {0};

  if (id.type == e2ap_ngran_gNB) {
    ue_id_data.type = GNB_UE_ID_E2SM;
    ue_id_data.gnb = fill_gnb_data(ue_stats, id);
  } else {
    assert(0!=0 && "not support id type");
  }

  return ue_id_data;
}

static
ue_id_e2sm_t fill_rnd_ue_id_data()
{
  ue_id_e2sm_t ue_id_data = {0};
  ue_id_data.type = GNB_UE_ID_E2SM;
  ue_id_data.gnb = fill_rnd_gnb_data();
  return ue_id_data;
}

static
void fill_meas_value(meas_record_lst_t* meas_record, meas_type_t meas_info_type, ue_cell_t ue_cell_stats)
{
  // Get Meas Info Name from Action Definition
  char* meas_info_name_str = copy_ba_to_str(&meas_info_type.name);
  defer({free(meas_info_name_str); } );

  // Get value based on Meas Info Name
  if (strcmp(meas_info_name_str, "DRB.IPThpDl.QCI") == 0 ? true : false) {
    meas_record->value = REAL_MEAS_VALUE;
    meas_record->real_val = ue_cell_stats.dl_bitrate;
  } else if (strcmp(meas_info_name_str, "DRB.IPThpUl.QCI") == 0 ? true : false) {
    meas_record->value = REAL_MEAS_VALUE;
    meas_record->real_val = ue_cell_stats.ul_bitrate;
  } else {
    // TODO: need metrics from AMR and need mapping name from 3GPP
    // printf("not implement value for measurement name %s\n", meas_info_name_str);
    meas_record->value = REAL_MEAS_VALUE;
    meas_record->real_val = 1234;
  }
}

static
kpm_ind_msg_format_1_t fill_kpm_ind_msg_frm_1(kpm_act_def_format_1_t act_def_fr1, amarisoft_ue_stats_t amr_uestats)
{
  kpm_ind_msg_format_1_t msg_frm_1 = {0};

  // Measurement Data
  uint32_t num_cells = amr_uestats.len_cell;
  msg_frm_1.meas_data_lst_len = num_cells;
  msg_frm_1.meas_data_lst = calloc(msg_frm_1.meas_data_lst_len, sizeof(*msg_frm_1.meas_data_lst));
  assert(msg_frm_1.meas_data_lst != NULL && "Memory exhausted" );

  size_t const rec_data_len = act_def_fr1.meas_info_lst_len; // Recoding Data Length
  for (size_t i = 0; i < msg_frm_1.meas_data_lst_len; i++){
    meas_data_lst_t* meas_data = &msg_frm_1.meas_data_lst[i];
    ue_cell_t ue_cell_stats = amr_uestats.cells[i];
    // Measurement Record
    meas_data->meas_record_len = rec_data_len;
    meas_data->meas_record_lst = calloc(meas_data->meas_record_len, sizeof(meas_record_lst_t));
    assert(meas_data->meas_record_lst != NULL && "Memory exhausted" );

    for (size_t j = 0; j < msg_frm_1.meas_data_lst[i].meas_record_len; j++) {
      meas_record_lst_t* meas_record = &meas_data->meas_record_lst[j];
      meas_type_t meas_info_type = act_def_fr1.meas_info_lst[j].meas_type;
      if (meas_info_type.type == NAME_MEAS_TYPE) {
        fill_meas_value(meas_record, meas_info_type, ue_cell_stats);
      } else {
        printf("not implement value for measurement type %d\n", meas_info_type.type);
        meas_record->value = REAL_MEAS_VALUE;
        meas_record->real_val = 1234;
      }
    }
  }

  // Measurement Information - OPTIONAL
  msg_frm_1.meas_info_lst_len = rec_data_len;
  msg_frm_1.meas_info_lst = calloc(msg_frm_1.meas_info_lst_len, sizeof(meas_info_format_1_lst_t));
  assert(msg_frm_1.meas_info_lst != NULL && "Memory exhausted" );

  for (size_t i = 0; i < msg_frm_1.meas_info_lst_len; i++) {
    // Measurement Type
    msg_frm_1.meas_info_lst[i].meas_type.type = act_def_fr1.meas_info_lst[i].meas_type.type;
    // Measurement Name
    if (act_def_fr1.meas_info_lst[i].meas_type.type == NAME_MEAS_TYPE) {
      msg_frm_1.meas_info_lst[i].meas_type.name.buf = calloc(act_def_fr1.meas_info_lst[i].meas_type.name.len, sizeof(uint8_t));
      memcpy(msg_frm_1.meas_info_lst[i].meas_type.name.buf, act_def_fr1.meas_info_lst[i].meas_type.name.buf, act_def_fr1.meas_info_lst[i].meas_type.name.len);
      msg_frm_1.meas_info_lst[i].meas_type.name.len = act_def_fr1.meas_info_lst[i].meas_type.name.len;
    } else {
      msg_frm_1.meas_info_lst[i].meas_type.id = act_def_fr1.meas_info_lst[i].meas_type.id;
    }

    // Label Information
    msg_frm_1.meas_info_lst[i].label_info_lst_len = 1;
    msg_frm_1.meas_info_lst[i].label_info_lst = calloc(msg_frm_1.meas_info_lst[i].label_info_lst_len, sizeof(label_info_lst_t));
    assert(msg_frm_1.meas_info_lst[i].label_info_lst != NULL && "Memory exhausted" );

    for (size_t j = 0; j < msg_frm_1.meas_info_lst[i].label_info_lst_len; j++) {
      msg_frm_1.meas_info_lst[i].label_info_lst[j].noLabel = malloc(sizeof(enum_value_e));
      *msg_frm_1.meas_info_lst[i].label_info_lst[j].noLabel = TRUE_ENUM_VALUE;
    }
  }

  return msg_frm_1;
}

static kpm_ind_msg_format_1_t fill_rnd_kpm_ind_msg_frm_1(void)
{
  kpm_ind_msg_format_1_t msg_frm_1 = {0};

  // Measurement Data
  msg_frm_1.meas_data_lst_len = 1;  // (rand() % 65535) + 1;
  msg_frm_1.meas_data_lst = calloc(msg_frm_1.meas_data_lst_len, sizeof(*msg_frm_1.meas_data_lst));
  assert(msg_frm_1.meas_data_lst != NULL && "Memory exhausted" );

  for (size_t i = 0; i < msg_frm_1.meas_data_lst_len; i++)
  {
    // Incomplete Flag
    msg_frm_1.meas_data_lst[i].incomplete_flag = calloc(1, sizeof(enum_value_e));
    assert(msg_frm_1.meas_data_lst[i].incomplete_flag != NULL && "Memory exhausted");
    *msg_frm_1.meas_data_lst[i].incomplete_flag = TRUE_ENUM_VALUE;

    // Measurement Record
    msg_frm_1.meas_data_lst[i].meas_record_len = 1;
    msg_frm_1.meas_data_lst[i].meas_record_lst = calloc(msg_frm_1.meas_data_lst[i].meas_record_len, sizeof(meas_record_lst_t));
    assert(msg_frm_1.meas_data_lst[i].meas_record_lst != NULL && "Memory exhausted" );

    for (size_t j = 0; j < msg_frm_1.meas_data_lst[i].meas_record_len; j++)
    {
      msg_frm_1.meas_data_lst[i].meas_record_lst[j].value = REAL_MEAS_VALUE;
      msg_frm_1.meas_data_lst[i].meas_record_lst[j].real_val = time_now_us();
    }
  }

  // Measurement Information - OPTIONAL
  msg_frm_1.meas_info_lst_len = 1;
  msg_frm_1.meas_info_lst = calloc(msg_frm_1.meas_info_lst_len, sizeof(meas_info_format_1_lst_t));
  assert(msg_frm_1.meas_info_lst != NULL && "Memory exhausted" );

  for (size_t i = 0; i < msg_frm_1.meas_info_lst_len; i++)
  {
    // Measurement Type
    char* s = "timestamp";
    msg_frm_1.meas_info_lst[i].meas_type.name.len = strlen(s) + 1;
    msg_frm_1.meas_info_lst[i].meas_type.name.buf = malloc(strlen(s) + 1);
    assert(msg_frm_1.meas_info_lst[i].meas_type.name.buf != NULL && "memory exhausted");
    memcpy(msg_frm_1.meas_info_lst[i].meas_type.name.buf, s, strlen(s));
    msg_frm_1.meas_info_lst[i].meas_type.name.buf[strlen(s)] = '\0';

    // Label Information
    msg_frm_1.meas_info_lst[i].label_info_lst_len = 1;
    msg_frm_1.meas_info_lst[i].label_info_lst = calloc(msg_frm_1.meas_info_lst[i].label_info_lst_len, sizeof(label_info_lst_t));
    assert(msg_frm_1.meas_info_lst[i].label_info_lst != NULL && "Memory exhausted" );

    for (size_t j = 0; j < msg_frm_1.meas_info_lst[i].label_info_lst_len; j++)
    {
      msg_frm_1.meas_info_lst[i].label_info_lst[j].noLabel = malloc(sizeof(enum_value_e));
      *msg_frm_1.meas_info_lst[i].label_info_lst[j].noLabel = TRUE_ENUM_VALUE;
    }
  }

  return msg_frm_1;
}

static
kpm_ind_msg_format_3_t fill_kpm_ind_msg_frm_3_sta(kpm_act_def_format_1_t act_def_fr1, ran_ind_t* buf_data)
{
  kpm_ind_msg_format_3_t msg_frm_3 = {0};

  uint32_t num_ues = buf_data->len_ue_stats;
  msg_frm_3.ue_meas_report_lst_len = num_ues == 0 ? 1: num_ues;

  msg_frm_3.meas_report_per_ue = calloc(msg_frm_3.ue_meas_report_lst_len, sizeof(meas_report_per_ue_t));
  assert(msg_frm_3.meas_report_per_ue != NULL && "Memory exhausted");

  if (num_ues > 0) {
    for (size_t i = 0; i < msg_frm_3.ue_meas_report_lst_len; i++)
    {
      size_t ran_cell_idx;
      size_t ue_cell_idx;
      for (ran_cell_idx = 0; ran_cell_idx < buf_data->ran_stats.len_cell; ran_cell_idx++) {
        for (ue_cell_idx = 0; ue_cell_idx < buf_data->ue_stats[i].len_cell; ue_cell_idx++) {
          if (buf_data->ran_stats.cells[ran_cell_idx].cell_id == buf_data->ue_stats[i].cells[ue_cell_idx].cell_id)
            goto end_loops;
        }
      }
      end_loops:
        msg_frm_3.meas_report_per_ue[i].ue_meas_report_lst = fill_ue_id_data(buf_data->ue_stats[i], buf_data->global_e2_node_id);
        printf("type %d\n", msg_frm_3.meas_report_per_ue[i].ue_meas_report_lst.type);
        msg_frm_3.meas_report_per_ue[i].ind_msg_format_1 = fill_kpm_ind_msg_frm_1(act_def_fr1, buf_data->ue_stats[i]);
    }
  } else {
    // case: no ue connected, fill the dummy information with incomplete flag
    msg_frm_3.meas_report_per_ue[0].ue_meas_report_lst = fill_rnd_ue_id_data();
    msg_frm_3.meas_report_per_ue[0].ind_msg_format_1 = fill_rnd_kpm_ind_msg_frm_1();
  }


  return msg_frm_3;
}

static
kpm_ric_ind_hdr_format_1_t fill_kpm_ind_hdr_frm_1(void)
{
  kpm_ric_ind_hdr_format_1_t hdr_frm_1 = {0};
#ifdef KPM_V2
  hdr_frm_1.collectStartTime = time_now_us() / 1000000; // needs to be truncated to 32 bits to arrive to a resolution of seconds
#elif defined(KPM_V3)
  hdr_frm_1.collectStartTime = time_now_us();
#else
  static_assert(0!=0, "Unknown KPM version");
#endif

  hdr_frm_1.fileformat_version = NULL;

  hdr_frm_1.sender_name = calloc(1, sizeof(byte_array_t));
  hdr_frm_1.sender_name->buf = calloc(strlen("AMR-gNB") + 1, sizeof(char));
  memcpy(hdr_frm_1.sender_name->buf, "AMR-gNB", strlen("AMR-gNB"));
  hdr_frm_1.sender_name->len = strlen("AMR-gNB") + 1;

  hdr_frm_1.sender_type = calloc(1, sizeof(byte_array_t));
  hdr_frm_1.sender_type->buf = calloc(strlen("gNB") + 1, sizeof(char));
  memcpy(hdr_frm_1.sender_type->buf, "gNB", strlen("gNB"));
  hdr_frm_1.sender_type->len = strlen("gNB") + 1;

  hdr_frm_1.vendor_name = calloc(1, sizeof(byte_array_t));
  hdr_frm_1.vendor_name->buf = calloc(strlen("Amarisoft") + 1, sizeof(char));
  memcpy(hdr_frm_1.vendor_name->buf, "Amarisoft", strlen("Amarisoft"));
  hdr_frm_1.vendor_name->len = strlen("Amarisoft") + 1;

  return hdr_frm_1;
}

static
kpm_ind_hdr_t fill_kpm_ind_hdr_sta(void)
{
  kpm_ind_hdr_t hdr = {0};

  hdr.type = FORMAT_1_INDICATION_HEADER;
  hdr.kpm_ric_ind_hdr_format_1 = fill_kpm_ind_hdr_frm_1();

  return hdr;
}

void read_kpm_sm(void* data)
{
  ran_ind_t temp = get_ringbuffer_data();
 
  kpm_rd_ind_data_t* kpm = (kpm_rd_ind_data_t*)data;
  kpm_act_def_t const* act_def = kpm->act_def;
  assert(act_def!= NULL && "Cannot be NULL");
  if(act_def->type == FORMAT_4_ACTION_DEFINITION){

    if(act_def->frm_4.matching_cond_lst[0].test_info_lst.test_cond_type == CQI_TEST_COND_TYPE
       && *act_def->frm_4.matching_cond_lst[0].test_info_lst.test_cond == GREATERTHAN_TEST_COND){
      printf("Matching condition: UEs with CQI greater than %ld \n", *act_def->frm_4.matching_cond_lst[0].test_info_lst.int_value );
    }
    for (size_t i = 0; i < act_def->frm_4.action_def_format_1.meas_info_lst_len; i++)
      printf("Parameter to report: %s \n", act_def->frm_4.action_def_format_1.meas_info_lst[i].meas_type.name.buf);

    kpm->ind.hdr = fill_kpm_ind_hdr_sta();
    // 7.8 Supported RIC Styles and E2SM IE Formats
    // Format 4 corresponds to indication message 3
    kpm->ind.msg.type = FORMAT_3_INDICATION_MESSAGE;
    kpm->ind.msg.frm_3 = fill_kpm_ind_msg_frm_3_sta(act_def->frm_4.action_def_format_1, &temp);
  } else {
    printf("Not supported action definition type %d, fill the dummy indication msg\n", act_def->type);
    kpm->ind.hdr = fill_rnd_kpm_ind_hdr();
    kpm->ind.msg = fill_rnd_kpm_ind_msg();
  }
}

void read_kpm_setup_sm(void* e2ap)
{
  assert(e2ap != NULL);
//  assert(e2ap->type == KPM_V3_0_AGENT_IF_E2_SETUP_ANS_V0);

  kpm_e2_setup_t* kpm = (kpm_e2_setup_t*)(e2ap);
  kpm->ran_func_def = fill_rnd_kpm_ran_func_def();
}

sm_ag_if_ans_t write_ctrl_kpm_sm(void const* src)
{
  assert(0 !=0 && "Not supported");
  (void)src;
  sm_ag_if_ans_t ans = {0};
  return ans;
}

