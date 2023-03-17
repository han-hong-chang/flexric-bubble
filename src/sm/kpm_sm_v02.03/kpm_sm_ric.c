/*
 * Licensed to the OpenAirInterface (OAI) Software Alliance under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The OpenAirInterface Software Alliance licenses this file to You under
 * the OAI Public License, Version 1.1  (the "License"); you may not use this file
 * except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.openairinterface.org/?page_id=698
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *-------------------------------------------------------------------------------
 * For more information about the OpenAirInterface (OAI) Software Alliance:
 *      contact@openairinterface.org
 */


#include "kpm_sm_ric.h"
#include "kpm_sm_id.h"

#include <assert.h>
#include <stdlib.h>
#include "../../util/alg_ds/alg/defer.h"

#include "enc/kpm_enc_generic.h"
#include "dec/kpm_dec_generic.h"

#include "test/fill_rnd_data_kpm.h"

typedef struct{
  sm_ric_t base;
//  kpm_enc_asn_t enc;

  #ifdef ASN
    kpm_enc_asn_t enc;
  #elif FLATBUFFERS 
    static_assert(false, "Flatbuffer not implemented");
  #elif PLAIN
    kpm_enc_plain_t enc;
  #else
    static_assert(false, "No encryption type selected");
  #endif

} sm_kpm_ric_t;

/**
 * @param cmd Set trigger value in milliseconds. Range of permitted values are {"1_ms, "2_ms", "5_ms"} are defined in xApp that 
 *            specifies the E42 interface. See 'src/xApp/e42_xapp.c' for further information.
 */
static sm_subs_data_t on_subscription_kpm_sm_ric(sm_ric_t const* sm_ric)
{
  assert(sm_ric != NULL); 
  sm_kpm_ric_t* sm = (sm_kpm_ric_t*)sm_ric;  
 

  kpm_ric_subscription_t *subscription = calloc(1, sizeof(kpm_ric_subscription_t));
  assert(subscription != NULL && "Memory exhausted");

  subscription->kpm_event_trigger_def = fill_kpm_event_trigger_def();
  subscription->kpm_act_def = fill_kpm_action_def();

  const byte_array_t ba_event_trigger = kpm_enc_event_trigger(&sm->enc, &subscription->kpm_event_trigger_def); 

  const byte_array_t ba_action_definition = kpm_enc_action_def(&sm->enc, &subscription->kpm_act_def);
  
  sm_subs_data_t data = {0}; 

  data.event_trigger = ba_event_trigger.buf;
  data.len_et = ba_event_trigger.len;

  data.action_def = ba_action_definition.buf;
  data.len_ad = ba_action_definition.len;

  return data;
}

static 
void free_subs_data_kpm_sm_ric(void* msg)
{
  assert(msg != NULL);

  sm_subs_data_t *data = (sm_subs_data_t *)msg;
  
  free(data->action_def);
  free(data->event_trigger);
}

static
sm_ag_if_rd_t on_indication_kpm_sm_ric(sm_ric_t const* sm_ric, sm_ind_data_t* data)
{
  assert(sm_ric != NULL); 
  assert(data != NULL); 
  sm_kpm_ric_t* sm = (sm_kpm_ric_t*)sm_ric;  

  sm_ag_if_rd_t rd_if = {.type = KPM_STATS_V0};

  rd_if.kpm_stats.kpm_ind_msg = kpm_dec_ind_msg(&sm->enc, data->len_msg, data->ind_msg);
  rd_if.kpm_stats.kpm_ind_hdr = kpm_dec_ind_hdr(&sm->enc, data->len_hdr, data->ind_hdr);

  return rd_if;
}


void free_ind_data_kpm_sm_ric(void* msg) 
{
  assert(msg != NULL);

  kpm_ric_indication_t* ind  = (kpm_ric_indication_t*)msg;

  free_kpm_ind_data(ind);
}

static
void ric_on_e2_setup_kpm_sm_ric(sm_ric_t const* sm_ric, sm_e2_setup_t const* data)
{
  assert(sm_ric != NULL); 
  assert(data != NULL); 

  sm_kpm_ric_t* sm = (sm_kpm_ric_t*)sm_ric;
 
  kpm_ran_function_def_t fdef = kpm_dec_func_def(&sm->enc, data->len_rfd, data->ran_fun_def);
  // we do nothing with function definition for the moment, so we can free here with defer()
  free_kpm_ran_function_def(&fdef);
  
}

static
sm_ric_service_update_t on_ric_service_update_kpm_sm_ric(sm_ric_t const* sm_ric, const char* data)
{
  assert(sm_ric != NULL); 
  assert(data != NULL); 

  assert(0!=0 && "Not implemented: here you have to decode ran function definition IE.");
}



void free_kpm_sm_ric(sm_ric_t* sm_ric)
{
  assert(sm_ric != NULL);
  sm_kpm_ric_t* sm = (sm_kpm_ric_t*)sm_ric;
  free(sm);
}



sm_ric_t* make_kpm_sm_ric(void /* sm_io_ric_t io */)
{
  sm_kpm_ric_t* sm = calloc(1, sizeof(sm_kpm_ric_t));
  assert(sm != NULL && "Memory exhausted");

  *((uint16_t*)&sm->base.ran_func_id) = SM_KPM_ID; 

  sm->base.free_sm = free_kpm_sm_ric;

  // Memory (De)Allocation
  sm->base.alloc.free_subs_data_msg = free_subs_data_kpm_sm_ric; 
  sm->base.alloc.free_ind_data = free_ind_data_kpm_sm_ric ; 
  sm->base.alloc.free_ctrl_req_data = NULL;
  sm->base.alloc.free_ctrl_out_data = NULL;
  sm->base.alloc.free_e2_setup = NULL;//free_e2_setup_kpm_sm_ric; 
  sm->base.alloc.free_ric_service_update = NULL;//free_ric_service_update_kpm_sm_ric; 

  // ORAN E2SM 5 Procedures
  sm->base.proc.on_subscription = on_subscription_kpm_sm_ric; 
  sm->base.proc.on_indication = on_indication_kpm_sm_ric;
  // Control needs two calls
  sm->base.proc.on_control_req = NULL; 
  sm->base.proc.on_control_out = NULL; 

  sm->base.proc.on_e2_setup = ric_on_e2_setup_kpm_sm_ric;
  sm->base.proc.on_ric_service_update = on_ric_service_update_kpm_sm_ric; 

  assert(strlen(SM_KPM_STR) < sizeof( sm->base.ran_func_name) );
  memcpy(sm->base.ran_func_name, SM_KPM_STR, strlen(SM_KPM_STR)); 

  return &sm->base;
}
