#ifndef GLOBAL_ENB_ID_H
#define GLOBAL_ENB_ID_H

#ifdef __cplusplus
extern "C" {
#endif

#include "plmn_identity.h"

//  6.2.3.9 Global eNB ID

typedef enum {
    MACRO_ENB_TYPE_ID,
    HOME_ENB_TYPE_ID,
    SHORT_MACRO_ENB_TYPE_ID,
    LONG_MACRO_ENB_TYPE_ID,

    END_ENB_TYPE_ID

} enb_type_id_e;


typedef struct {
    plmn_t plmn_id;

    enb_type_id_e type;
    union {
        uint8_t macro_enb_id[3];
        uint8_t home_enb_id[4];
        uint8_t short_macro_enb_id[3];
        uint8_t long_macro_enb_id[3];
    };
    

} global_enb_id_t;


#ifdef __cplusplus
}
#endif

#endif

// done