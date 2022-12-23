#ifndef ACTION_DEFINITION_FORMAT_3_KPM_V2_H
#define ACTION_DEFINITION_FORMAT_3_KPM_V2_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdint.h>

#include "../data/meas_info_frm_3_lst.h"
#include "../../../../lib/e2sm_common_ie/sm_common_ie/cell_global_id.h"

//  8.2.1.2.3  E2SM-KPM Action Definition Format 3

typedef struct {
    size_t meas_info_lst_len;  // [1, 65535]
    meas_info_format_3_lst_t *meas_info_lst;

    uint32_t gran_period_ms;  // 8.3.8 [0, 4294967295]

    cell_global_id_t* cell_global_id; /* OPTIONAL - 8.3.20 */

} kpm_act_def_format_3_t;



#ifdef __cplusplus
}
#endif

#endif

// done