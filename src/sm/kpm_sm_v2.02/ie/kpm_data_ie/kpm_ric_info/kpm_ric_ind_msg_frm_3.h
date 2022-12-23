#ifndef RIC_INDICATION_MESSAGE_FORMAT_3_KPM_V2_H
#define RIC_INDICATION_MESSAGE_FORMAT_3_KPM_V2_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>

#include "../../../../lib/e2sm_common_ie/sm_common_ie/ue_id.h"
#include "kpm_ric_ind_msg_frm_1.h"

//  8.2.1.4.3  E2SM-KPM Indication Message Format 3

typedef struct {
    size_t ue_meas_report_lst_len;  // [1, 65535]
    ue_id_t *ue_meas_report_lst;  // 8.3.24

    kpm_ind_msg_format_1_t ind_msg_format_1;  // 8.2.1.4.1

} kpm_ind_msg_format_3_t;


#ifdef __cplusplus
}
#endif

#endif

// done