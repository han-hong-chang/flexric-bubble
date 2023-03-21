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

#include "../common/fill_ind_data.h"
#include "../../../src/sm/pdcp_sm/pdcp_sm_agent.h"
#include "../../../src/sm/pdcp_sm/pdcp_sm_ric.h"
#include "../../../src/util/alg_ds/alg/defer.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

///
// Functions implemented and specific to the RAN
//

static
pdcp_ind_data_t cp;

/////
// AGENT
////

static
void read_RAN(sm_ag_if_rd_t* read)
{
  assert(read != NULL);
  assert(read->type == PDCP_STATS_V0);
  assert(read->ind.pdcp_ind != NULL);

  pdcp_ind_data_t* ind = read->ind.pdcp_ind;

  fill_pdcp_ind_data(ind);
  cp.hdr = cp_pdcp_ind_hdr(&ind->hdr);
  cp.msg = cp_pdcp_ind_msg(&ind->msg);
}


static 
sm_ag_if_ans_t write_RAN(const sm_ag_if_wr_t* data)
{
  assert(data != NULL);

  sm_ag_if_ans_t ans = {.type = NONE_SM_AG_IF_ANS_V0};

  if(data->type == CONTROL_SM_AG_IF_WR){
    assert(data->ctrl.type == PDCP_CTRL_REQ_V0);
    pdcp_ctrl_req_data_t const* req = data->ctrl.pdcp_req_ctrl;

    assert(req->hdr.dummy == 0); 
    assert(req->msg.action == 42); 

    ans.ctrl_out.pdcp = calloc(1, sizeof(pdcp_ctrl_out_t ));
    assert(ans.ctrl_out.pdcp != NULL && "Memory exhausted" );
    ans.type = CTRL_OUTCOME_SM_AG_IF_ANS_V0;
  } else if(data->type == SUBSCRIPTION_SM_AG_IF_WR){
    assert(data->subs.type == PDCP_SUBS_V0); 
    assert(data->subs.pdcp != NULL);

    printf("SUBSCRIBE_TIMER called with ms = %u \n", data->subs.pdcp->et.ms);

  } else {
    assert(0!=0 && "Unknown type");
  }

  return ans;
}


/////////////////////////////
// Check Functions
// //////////////////////////

static
void check_eq_ran_function(sm_agent_t const* ag, sm_ric_t const* ric)
{
  assert(ag != NULL);
  assert(ric != NULL);
  assert(ag->ran_func_id == ric->ran_func_id);
}

// RIC -> E2
static
void check_subscription(sm_agent_t* ag, sm_ric_t* ric)
{
  assert(ag != NULL);
  assert(ric != NULL);
 
  sm_subs_data_t data = ric->proc.on_subscription(ric, "2_ms");
  ag->proc.on_subscription(ag, &data); 

  free_sm_subs_data(&data);
}

// E2 -> RIC
static
void check_indication(sm_agent_t* ag, sm_ric_t* ric)
{
  assert(ag != NULL);
  assert(ric != NULL);

  sm_ind_data_t sm_data = ag->proc.on_indication(ag);
  defer({free_sm_ind_data(&sm_data);}); 

  sm_ag_if_rd_t msg = ric->proc.on_indication(ric, &sm_data);

  assert(msg.type == PDCP_STATS_V0);
  pdcp_ind_data_t* data = msg.ind.pdcp_ind;
  defer({ ric->alloc.free_ind_data(data); });

  assert(eq_pdcp_ind_hdr(&data->hdr, &cp.hdr) == true);
  assert(eq_pdcp_ind_msg(&data->msg, &cp.msg) == true);
  assert(eq_pdcp_call_proc_id(data->proc_id, cp.proc_id) == true);

  free_pdcp_ind_hdr(&cp.hdr);
  free_pdcp_ind_msg(&cp.msg);
}

// RIC -> E2
static
void check_control(sm_agent_t* ag, sm_ric_t* ric)
{
  assert(ag != NULL);
  assert(ric != NULL);

  pdcp_ctrl_req_data_t data = {0};
  data.hdr.dummy = 0; 
  data.msg.action = 42; 

  sm_ag_if_wr_t wr = {.type =CONTROL_SM_AG_IF_WR }; 
  wr.ctrl.type = PDCP_CTRL_REQ_V0 ;

  sm_ctrl_req_data_t sm_data = ric->proc.on_control_req(ric, &wr);
  defer({ ric->alloc.free_ctrl_req_data(&sm_data); } );

  sm_ctrl_out_data_t out = ag->proc.on_control(ag, &sm_data);
  defer({ free_sm_ctrl_out_data(&out); });

  sm_ag_if_ans_t sm_data_out = ric->proc.on_control_out(ric, &out);
  assert(sm_data_out.type == CTRL_OUTCOME_SM_AG_IF_ANS_V0 );
  assert(sm_data_out.ctrl_out.type == PDCP_AGENT_IF_CTRL_ANS_V0);
  assert(sm_data_out.ctrl_out.pdcp->ans == PDCP_CTRL_OUT_OK );
}


int main()
{
  sm_io_ag_t io_ag = {.read = read_RAN, .write = write_RAN};  
  sm_agent_t* sm_ag = make_pdcp_sm_agent(io_ag);

  sm_ric_t* sm_ric = make_pdcp_sm_ric();

  for(int i =0; i < 262144; ++i){
    check_eq_ran_function(sm_ag, sm_ric);
    check_subscription(sm_ag, sm_ric);
    check_indication(sm_ag, sm_ric);
    check_control(sm_ag, sm_ric);
  }

  sm_ag->free_sm(sm_ag);
  sm_ric->free_sm(sm_ric);

  printf("Success\n");
  return EXIT_SUCCESS;
}

