#ifndef E2_SM_KPM_READ_WRITE_AGENT_H
#define E2_SM_KPM_READ_WRITE_AGENT_H

#include "agent/e2_agent_api.h"

void read_kpm_sm(void*);

void read_kpm_setup_sm(void*);

sm_ag_if_ans_t write_ctrl_kpm_sm(void const* src);

#endif