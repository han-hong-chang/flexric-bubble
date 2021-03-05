#ifndef RRC_CONF_BUILDER_H
#define RRC_CONF_BUILDER_H

/* Generated by flatcc 0.6.1-dev FlatBuffers schema compiler for C by dvide.com */

#ifndef RRC_CONF_READER_H
#include "rrc_conf_reader.h"
#endif
#ifndef FLATBUFFERS_COMMON_BUILDER_H
#include "flatbuffers_common_builder.h"
#endif
#ifndef RRC_COMMON_BUILDER_H
#include "rrc_common_builder.h"
#endif
#include "flatcc/flatcc_prologue.h"
#ifndef flatbuffers_identifier
#define flatbuffers_identifier 0
#endif
#ifndef flatbuffers_extension
#define flatbuffers_extension ".bin"
#endif

#define __rrc_conf_ReportOccasion_formal_args , rrc_conf_ReportOccasion_enum_t v0
#define __rrc_conf_ReportOccasion_call_args , v0
__flatbuffers_build_scalar(flatbuffers_, rrc_conf_ReportOccasion, rrc_conf_ReportOccasion_enum_t)
#define __rrc_conf_ReportStyleType_formal_args , rrc_conf_ReportStyleType_enum_t v0
#define __rrc_conf_ReportStyleType_call_args , v0
__flatbuffers_build_scalar(flatbuffers_, rrc_conf_ReportStyleType, rrc_conf_ReportStyleType_enum_t)

static const flatbuffers_voffset_t __rrc_conf_EventTrigger_required[] = { 0 };
typedef flatbuffers_ref_t rrc_conf_EventTrigger_ref_t;
static rrc_conf_EventTrigger_ref_t rrc_conf_EventTrigger_clone(flatbuffers_builder_t *B, rrc_conf_EventTrigger_table_t t);
__flatbuffers_build_table(flatbuffers_, rrc_conf_EventTrigger, 1)

static const flatbuffers_voffset_t __rrc_conf_ReportStyle_required[] = { 0 };
typedef flatbuffers_ref_t rrc_conf_ReportStyle_ref_t;
static rrc_conf_ReportStyle_ref_t rrc_conf_ReportStyle_clone(flatbuffers_builder_t *B, rrc_conf_ReportStyle_table_t t);
__flatbuffers_build_table(flatbuffers_, rrc_conf_ReportStyle, 1)

static const flatbuffers_voffset_t __rrc_conf_ActionDefinition_required[] = { 0 };
typedef flatbuffers_ref_t rrc_conf_ActionDefinition_ref_t;
static rrc_conf_ActionDefinition_ref_t rrc_conf_ActionDefinition_clone(flatbuffers_builder_t *B, rrc_conf_ActionDefinition_table_t t);
__flatbuffers_build_table(flatbuffers_, rrc_conf_ActionDefinition, 1)

static const flatbuffers_voffset_t __rrc_conf_IndicationHeader_required[] = { 0 };
typedef flatbuffers_ref_t rrc_conf_IndicationHeader_ref_t;
static rrc_conf_IndicationHeader_ref_t rrc_conf_IndicationHeader_clone(flatbuffers_builder_t *B, rrc_conf_IndicationHeader_table_t t);
__flatbuffers_build_table(flatbuffers_, rrc_conf_IndicationHeader, 0)

static const flatbuffers_voffset_t __rrc_conf_Lte_required[] = { 0 };
typedef flatbuffers_ref_t rrc_conf_Lte_ref_t;
static rrc_conf_Lte_ref_t rrc_conf_Lte_clone(flatbuffers_builder_t *B, rrc_conf_Lte_table_t t);
__flatbuffers_build_table(flatbuffers_, rrc_conf_Lte, 0)

static const flatbuffers_voffset_t __rrc_conf_Nr_required[] = { 0 };
typedef flatbuffers_ref_t rrc_conf_Nr_ref_t;
static rrc_conf_Nr_ref_t rrc_conf_Nr_clone(flatbuffers_builder_t *B, rrc_conf_Nr_table_t t);
__flatbuffers_build_table(flatbuffers_, rrc_conf_Nr, 1)

static const flatbuffers_voffset_t __rrc_conf_CarrierInfo_required[] = { 0 };
typedef flatbuffers_ref_t rrc_conf_CarrierInfo_ref_t;
static rrc_conf_CarrierInfo_ref_t rrc_conf_CarrierInfo_clone(flatbuffers_builder_t *B, rrc_conf_CarrierInfo_table_t t);
__flatbuffers_build_table(flatbuffers_, rrc_conf_CarrierInfo, 11)

static const flatbuffers_voffset_t __rrc_conf_BSStats_required[] = { 0 };
typedef flatbuffers_ref_t rrc_conf_BSStats_ref_t;
static rrc_conf_BSStats_ref_t rrc_conf_BSStats_clone(flatbuffers_builder_t *B, rrc_conf_BSStats_table_t t);
__flatbuffers_build_table(flatbuffers_, rrc_conf_BSStats, 5)

static const flatbuffers_voffset_t __rrc_conf_IndicationMessage_required[] = { 0 };
typedef flatbuffers_ref_t rrc_conf_IndicationMessage_ref_t;
static rrc_conf_IndicationMessage_ref_t rrc_conf_IndicationMessage_clone(flatbuffers_builder_t *B, rrc_conf_IndicationMessage_table_t t);
__flatbuffers_build_table(flatbuffers_, rrc_conf_IndicationMessage, 1)

static const flatbuffers_voffset_t __rrc_conf_RanFunctionDefinition_required[] = { 0 };
typedef flatbuffers_ref_t rrc_conf_RanFunctionDefinition_ref_t;
static rrc_conf_RanFunctionDefinition_ref_t rrc_conf_RanFunctionDefinition_clone(flatbuffers_builder_t *B, rrc_conf_RanFunctionDefinition_table_t t);
__flatbuffers_build_table(flatbuffers_, rrc_conf_RanFunctionDefinition, 1)

#define __rrc_conf_EventTrigger_formal_args , rrc_conf_ReportOccasion_enum_t v0
#define __rrc_conf_EventTrigger_call_args , v0
static inline rrc_conf_EventTrigger_ref_t rrc_conf_EventTrigger_create(flatbuffers_builder_t *B __rrc_conf_EventTrigger_formal_args);
__flatbuffers_build_table_prolog(flatbuffers_, rrc_conf_EventTrigger, rrc_conf_EventTrigger_file_identifier, rrc_conf_EventTrigger_type_identifier)

#define __rrc_conf_ReportStyle_formal_args , rrc_conf_ReportStyleType_enum_t v0
#define __rrc_conf_ReportStyle_call_args , v0
static inline rrc_conf_ReportStyle_ref_t rrc_conf_ReportStyle_create(flatbuffers_builder_t *B __rrc_conf_ReportStyle_formal_args);
__flatbuffers_build_table_prolog(flatbuffers_, rrc_conf_ReportStyle, rrc_conf_ReportStyle_file_identifier, rrc_conf_ReportStyle_type_identifier)

#define __rrc_conf_ActionDefinition_formal_args , rrc_conf_ReportStyle_ref_t v0
#define __rrc_conf_ActionDefinition_call_args , v0
static inline rrc_conf_ActionDefinition_ref_t rrc_conf_ActionDefinition_create(flatbuffers_builder_t *B __rrc_conf_ActionDefinition_formal_args);
__flatbuffers_build_table_prolog(flatbuffers_, rrc_conf_ActionDefinition, rrc_conf_ActionDefinition_file_identifier, rrc_conf_ActionDefinition_type_identifier)

#define __rrc_conf_IndicationHeader_formal_args 
#define __rrc_conf_IndicationHeader_call_args 
static inline rrc_conf_IndicationHeader_ref_t rrc_conf_IndicationHeader_create(flatbuffers_builder_t *B __rrc_conf_IndicationHeader_formal_args);
__flatbuffers_build_table_prolog(flatbuffers_, rrc_conf_IndicationHeader, rrc_conf_IndicationHeader_file_identifier, rrc_conf_IndicationHeader_type_identifier)

#define __rrc_conf_Lte_formal_args 
#define __rrc_conf_Lte_call_args 
static inline rrc_conf_Lte_ref_t rrc_conf_Lte_create(flatbuffers_builder_t *B __rrc_conf_Lte_formal_args);
__flatbuffers_build_table_prolog(flatbuffers_, rrc_conf_Lte, rrc_conf_Lte_file_identifier, rrc_conf_Lte_type_identifier)

#define __rrc_conf_Nr_formal_args , uint8_t v0
#define __rrc_conf_Nr_call_args , v0
static inline rrc_conf_Nr_ref_t rrc_conf_Nr_create(flatbuffers_builder_t *B __rrc_conf_Nr_formal_args);
__flatbuffers_build_table_prolog(flatbuffers_, rrc_conf_Nr, rrc_conf_Nr_file_identifier, rrc_conf_Nr_type_identifier)

#define __rrc_conf_CarrierInfo_formal_args ,\
  uint8_t v0, uint16_t v1, uint16_t v2, uint64_t v3,\
  uint64_t v4, uint16_t v5, uint16_t v6, uint8_t v7,\
  uint8_t v8, rrc_conf_Lte_ref_t v9, rrc_conf_Nr_ref_t v10
#define __rrc_conf_CarrierInfo_call_args ,\
  v0, v1, v2, v3,\
  v4, v5, v6, v7,\
  v8, v9, v10
static inline rrc_conf_CarrierInfo_ref_t rrc_conf_CarrierInfo_create(flatbuffers_builder_t *B __rrc_conf_CarrierInfo_formal_args);
__flatbuffers_build_table_prolog(flatbuffers_, rrc_conf_CarrierInfo, rrc_conf_CarrierInfo_file_identifier, rrc_conf_CarrierInfo_type_identifier)

#define __rrc_conf_BSStats_formal_args ,\
  rrc_common_RAT_enum_t v0, flatbuffers_string_ref_t v1, rrc_common_PlmnInfo_vec_ref_t v2, rrc_common_PlmnInfo_ref_t v3, rrc_conf_CarrierInfo_vec_ref_t v4
#define __rrc_conf_BSStats_call_args ,\
  v0, v1, v2, v3, v4
static inline rrc_conf_BSStats_ref_t rrc_conf_BSStats_create(flatbuffers_builder_t *B __rrc_conf_BSStats_formal_args);
__flatbuffers_build_table_prolog(flatbuffers_, rrc_conf_BSStats, rrc_conf_BSStats_file_identifier, rrc_conf_BSStats_type_identifier)

#define __rrc_conf_IndicationMessage_formal_args , rrc_conf_BSStats_ref_t v0
#define __rrc_conf_IndicationMessage_call_args , v0
static inline rrc_conf_IndicationMessage_ref_t rrc_conf_IndicationMessage_create(flatbuffers_builder_t *B __rrc_conf_IndicationMessage_formal_args);
__flatbuffers_build_table_prolog(flatbuffers_, rrc_conf_IndicationMessage, rrc_conf_IndicationMessage_file_identifier, rrc_conf_IndicationMessage_type_identifier)

#define __rrc_conf_RanFunctionDefinition_formal_args , rrc_conf_ReportStyle_vec_ref_t v0
#define __rrc_conf_RanFunctionDefinition_call_args , v0
static inline rrc_conf_RanFunctionDefinition_ref_t rrc_conf_RanFunctionDefinition_create(flatbuffers_builder_t *B __rrc_conf_RanFunctionDefinition_formal_args);
__flatbuffers_build_table_prolog(flatbuffers_, rrc_conf_RanFunctionDefinition, rrc_conf_RanFunctionDefinition_file_identifier, rrc_conf_RanFunctionDefinition_type_identifier)

__flatbuffers_build_scalar_field(0, flatbuffers_, rrc_conf_EventTrigger_reportOccasion, rrc_conf_ReportOccasion, rrc_conf_ReportOccasion_enum_t, 1, 1, UINT8_C(0), rrc_conf_EventTrigger)

static inline rrc_conf_EventTrigger_ref_t rrc_conf_EventTrigger_create(flatbuffers_builder_t *B __rrc_conf_EventTrigger_formal_args)
{
    if (rrc_conf_EventTrigger_start(B)
        || rrc_conf_EventTrigger_reportOccasion_add(B, v0)) {
        return 0;
    }
    return rrc_conf_EventTrigger_end(B);
}

static rrc_conf_EventTrigger_ref_t rrc_conf_EventTrigger_clone(flatbuffers_builder_t *B, rrc_conf_EventTrigger_table_t t)
{
    __flatbuffers_memoize_begin(B, t);
    if (rrc_conf_EventTrigger_start(B)
        || rrc_conf_EventTrigger_reportOccasion_pick(B, t)) {
        return 0;
    }
    __flatbuffers_memoize_end(B, t, rrc_conf_EventTrigger_end(B));
}

__flatbuffers_build_scalar_field(0, flatbuffers_, rrc_conf_ReportStyle_type, rrc_conf_ReportStyleType, rrc_conf_ReportStyleType_enum_t, 1, 1, UINT8_C(0), rrc_conf_ReportStyle)

static inline rrc_conf_ReportStyle_ref_t rrc_conf_ReportStyle_create(flatbuffers_builder_t *B __rrc_conf_ReportStyle_formal_args)
{
    if (rrc_conf_ReportStyle_start(B)
        || rrc_conf_ReportStyle_type_add(B, v0)) {
        return 0;
    }
    return rrc_conf_ReportStyle_end(B);
}

static rrc_conf_ReportStyle_ref_t rrc_conf_ReportStyle_clone(flatbuffers_builder_t *B, rrc_conf_ReportStyle_table_t t)
{
    __flatbuffers_memoize_begin(B, t);
    if (rrc_conf_ReportStyle_start(B)
        || rrc_conf_ReportStyle_type_pick(B, t)) {
        return 0;
    }
    __flatbuffers_memoize_end(B, t, rrc_conf_ReportStyle_end(B));
}

__flatbuffers_build_table_field(0, flatbuffers_, rrc_conf_ActionDefinition_reportStyle, rrc_conf_ReportStyle, rrc_conf_ActionDefinition)

static inline rrc_conf_ActionDefinition_ref_t rrc_conf_ActionDefinition_create(flatbuffers_builder_t *B __rrc_conf_ActionDefinition_formal_args)
{
    if (rrc_conf_ActionDefinition_start(B)
        || rrc_conf_ActionDefinition_reportStyle_add(B, v0)) {
        return 0;
    }
    return rrc_conf_ActionDefinition_end(B);
}

static rrc_conf_ActionDefinition_ref_t rrc_conf_ActionDefinition_clone(flatbuffers_builder_t *B, rrc_conf_ActionDefinition_table_t t)
{
    __flatbuffers_memoize_begin(B, t);
    if (rrc_conf_ActionDefinition_start(B)
        || rrc_conf_ActionDefinition_reportStyle_pick(B, t)) {
        return 0;
    }
    __flatbuffers_memoize_end(B, t, rrc_conf_ActionDefinition_end(B));
}


static inline rrc_conf_IndicationHeader_ref_t rrc_conf_IndicationHeader_create(flatbuffers_builder_t *B __rrc_conf_IndicationHeader_formal_args)
{
    if (rrc_conf_IndicationHeader_start(B)) {
        return 0;
    }
    return rrc_conf_IndicationHeader_end(B);
}

static rrc_conf_IndicationHeader_ref_t rrc_conf_IndicationHeader_clone(flatbuffers_builder_t *B, rrc_conf_IndicationHeader_table_t t)
{
    __flatbuffers_memoize_begin(B, t);
    if (rrc_conf_IndicationHeader_start(B)) {
        return 0;
    }
    __flatbuffers_memoize_end(B, t, rrc_conf_IndicationHeader_end(B));
}


static inline rrc_conf_Lte_ref_t rrc_conf_Lte_create(flatbuffers_builder_t *B __rrc_conf_Lte_formal_args)
{
    if (rrc_conf_Lte_start(B)) {
        return 0;
    }
    return rrc_conf_Lte_end(B);
}

static rrc_conf_Lte_ref_t rrc_conf_Lte_clone(flatbuffers_builder_t *B, rrc_conf_Lte_table_t t)
{
    __flatbuffers_memoize_begin(B, t);
    if (rrc_conf_Lte_start(B)) {
        return 0;
    }
    __flatbuffers_memoize_end(B, t, rrc_conf_Lte_end(B));
}

__flatbuffers_build_scalar_field(0, flatbuffers_, rrc_conf_Nr_numerology, flatbuffers_uint8, uint8_t, 1, 1, UINT8_C(0), rrc_conf_Nr)

static inline rrc_conf_Nr_ref_t rrc_conf_Nr_create(flatbuffers_builder_t *B __rrc_conf_Nr_formal_args)
{
    if (rrc_conf_Nr_start(B)
        || rrc_conf_Nr_numerology_add(B, v0)) {
        return 0;
    }
    return rrc_conf_Nr_end(B);
}

static rrc_conf_Nr_ref_t rrc_conf_Nr_clone(flatbuffers_builder_t *B, rrc_conf_Nr_table_t t)
{
    __flatbuffers_memoize_begin(B, t);
    if (rrc_conf_Nr_start(B)
        || rrc_conf_Nr_numerology_pick(B, t)) {
        return 0;
    }
    __flatbuffers_memoize_end(B, t, rrc_conf_Nr_end(B));
}

__flatbuffers_build_scalar_field(0, flatbuffers_, rrc_conf_CarrierInfo_id, flatbuffers_uint8, uint8_t, 1, 1, UINT8_C(0), rrc_conf_CarrierInfo)
__flatbuffers_build_scalar_field(1, flatbuffers_, rrc_conf_CarrierInfo_phyCellId, flatbuffers_uint16, uint16_t, 2, 2, UINT16_C(0), rrc_conf_CarrierInfo)
__flatbuffers_build_scalar_field(2, flatbuffers_, rrc_conf_CarrierInfo_band, flatbuffers_uint16, uint16_t, 2, 2, UINT16_C(0), rrc_conf_CarrierInfo)
__flatbuffers_build_scalar_field(3, flatbuffers_, rrc_conf_CarrierInfo_dlFreqHz, flatbuffers_uint64, uint64_t, 8, 8, UINT64_C(0), rrc_conf_CarrierInfo)
__flatbuffers_build_scalar_field(4, flatbuffers_, rrc_conf_CarrierInfo_ulFreqHz, flatbuffers_uint64, uint64_t, 8, 8, UINT64_C(0), rrc_conf_CarrierInfo)
__flatbuffers_build_scalar_field(5, flatbuffers_, rrc_conf_CarrierInfo_dlBandwidthPrb, flatbuffers_uint16, uint16_t, 2, 2, UINT16_C(0), rrc_conf_CarrierInfo)
__flatbuffers_build_scalar_field(6, flatbuffers_, rrc_conf_CarrierInfo_ulBandwidthPrb, flatbuffers_uint16, uint16_t, 2, 2, UINT16_C(0), rrc_conf_CarrierInfo)
__flatbuffers_build_scalar_field(7, flatbuffers_, rrc_conf_CarrierInfo_txAntennaPorts, flatbuffers_uint8, uint8_t, 1, 1, UINT8_C(0), rrc_conf_CarrierInfo)
__flatbuffers_build_scalar_field(8, flatbuffers_, rrc_conf_CarrierInfo_rxAnennaPorts, flatbuffers_uint8, uint8_t, 1, 1, UINT8_C(0), rrc_conf_CarrierInfo)
__flatbuffers_build_table_field(9, flatbuffers_, rrc_conf_CarrierInfo_lte, rrc_conf_Lte, rrc_conf_CarrierInfo)
__flatbuffers_build_table_field(10, flatbuffers_, rrc_conf_CarrierInfo_nr, rrc_conf_Nr, rrc_conf_CarrierInfo)

static inline rrc_conf_CarrierInfo_ref_t rrc_conf_CarrierInfo_create(flatbuffers_builder_t *B __rrc_conf_CarrierInfo_formal_args)
{
    if (rrc_conf_CarrierInfo_start(B)
        || rrc_conf_CarrierInfo_dlFreqHz_add(B, v3)
        || rrc_conf_CarrierInfo_ulFreqHz_add(B, v4)
        || rrc_conf_CarrierInfo_lte_add(B, v9)
        || rrc_conf_CarrierInfo_nr_add(B, v10)
        || rrc_conf_CarrierInfo_phyCellId_add(B, v1)
        || rrc_conf_CarrierInfo_band_add(B, v2)
        || rrc_conf_CarrierInfo_dlBandwidthPrb_add(B, v5)
        || rrc_conf_CarrierInfo_ulBandwidthPrb_add(B, v6)
        || rrc_conf_CarrierInfo_id_add(B, v0)
        || rrc_conf_CarrierInfo_txAntennaPorts_add(B, v7)
        || rrc_conf_CarrierInfo_rxAnennaPorts_add(B, v8)) {
        return 0;
    }
    return rrc_conf_CarrierInfo_end(B);
}

static rrc_conf_CarrierInfo_ref_t rrc_conf_CarrierInfo_clone(flatbuffers_builder_t *B, rrc_conf_CarrierInfo_table_t t)
{
    __flatbuffers_memoize_begin(B, t);
    if (rrc_conf_CarrierInfo_start(B)
        || rrc_conf_CarrierInfo_dlFreqHz_pick(B, t)
        || rrc_conf_CarrierInfo_ulFreqHz_pick(B, t)
        || rrc_conf_CarrierInfo_lte_pick(B, t)
        || rrc_conf_CarrierInfo_nr_pick(B, t)
        || rrc_conf_CarrierInfo_phyCellId_pick(B, t)
        || rrc_conf_CarrierInfo_band_pick(B, t)
        || rrc_conf_CarrierInfo_dlBandwidthPrb_pick(B, t)
        || rrc_conf_CarrierInfo_ulBandwidthPrb_pick(B, t)
        || rrc_conf_CarrierInfo_id_pick(B, t)
        || rrc_conf_CarrierInfo_txAntennaPorts_pick(B, t)
        || rrc_conf_CarrierInfo_rxAnennaPorts_pick(B, t)) {
        return 0;
    }
    __flatbuffers_memoize_end(B, t, rrc_conf_CarrierInfo_end(B));
}

__flatbuffers_build_scalar_field(0, flatbuffers_, rrc_conf_BSStats_rat, rrc_common_RAT, rrc_common_RAT_enum_t, 1, 1, UINT8_C(0), rrc_conf_BSStats)
__flatbuffers_build_string_field(1, flatbuffers_, rrc_conf_BSStats_baseStationName, rrc_conf_BSStats)
__flatbuffers_build_table_vector_field(2, flatbuffers_, rrc_conf_BSStats_plmnInfo, rrc_common_PlmnInfo, rrc_conf_BSStats)
__flatbuffers_build_table_field(3, flatbuffers_, rrc_conf_BSStats_targetPCell, rrc_common_PlmnInfo, rrc_conf_BSStats)
__flatbuffers_build_table_vector_field(4, flatbuffers_, rrc_conf_BSStats_carriers, rrc_conf_CarrierInfo, rrc_conf_BSStats)

static inline rrc_conf_BSStats_ref_t rrc_conf_BSStats_create(flatbuffers_builder_t *B __rrc_conf_BSStats_formal_args)
{
    if (rrc_conf_BSStats_start(B)
        || rrc_conf_BSStats_baseStationName_add(B, v1)
        || rrc_conf_BSStats_plmnInfo_add(B, v2)
        || rrc_conf_BSStats_targetPCell_add(B, v3)
        || rrc_conf_BSStats_carriers_add(B, v4)
        || rrc_conf_BSStats_rat_add(B, v0)) {
        return 0;
    }
    return rrc_conf_BSStats_end(B);
}

static rrc_conf_BSStats_ref_t rrc_conf_BSStats_clone(flatbuffers_builder_t *B, rrc_conf_BSStats_table_t t)
{
    __flatbuffers_memoize_begin(B, t);
    if (rrc_conf_BSStats_start(B)
        || rrc_conf_BSStats_baseStationName_pick(B, t)
        || rrc_conf_BSStats_plmnInfo_pick(B, t)
        || rrc_conf_BSStats_targetPCell_pick(B, t)
        || rrc_conf_BSStats_carriers_pick(B, t)
        || rrc_conf_BSStats_rat_pick(B, t)) {
        return 0;
    }
    __flatbuffers_memoize_end(B, t, rrc_conf_BSStats_end(B));
}

__flatbuffers_build_table_field(0, flatbuffers_, rrc_conf_IndicationMessage_bsStats, rrc_conf_BSStats, rrc_conf_IndicationMessage)

static inline rrc_conf_IndicationMessage_ref_t rrc_conf_IndicationMessage_create(flatbuffers_builder_t *B __rrc_conf_IndicationMessage_formal_args)
{
    if (rrc_conf_IndicationMessage_start(B)
        || rrc_conf_IndicationMessage_bsStats_add(B, v0)) {
        return 0;
    }
    return rrc_conf_IndicationMessage_end(B);
}

static rrc_conf_IndicationMessage_ref_t rrc_conf_IndicationMessage_clone(flatbuffers_builder_t *B, rrc_conf_IndicationMessage_table_t t)
{
    __flatbuffers_memoize_begin(B, t);
    if (rrc_conf_IndicationMessage_start(B)
        || rrc_conf_IndicationMessage_bsStats_pick(B, t)) {
        return 0;
    }
    __flatbuffers_memoize_end(B, t, rrc_conf_IndicationMessage_end(B));
}

__flatbuffers_build_table_vector_field(0, flatbuffers_, rrc_conf_RanFunctionDefinition_supportedReportStyles, rrc_conf_ReportStyle, rrc_conf_RanFunctionDefinition)

static inline rrc_conf_RanFunctionDefinition_ref_t rrc_conf_RanFunctionDefinition_create(flatbuffers_builder_t *B __rrc_conf_RanFunctionDefinition_formal_args)
{
    if (rrc_conf_RanFunctionDefinition_start(B)
        || rrc_conf_RanFunctionDefinition_supportedReportStyles_add(B, v0)) {
        return 0;
    }
    return rrc_conf_RanFunctionDefinition_end(B);
}

static rrc_conf_RanFunctionDefinition_ref_t rrc_conf_RanFunctionDefinition_clone(flatbuffers_builder_t *B, rrc_conf_RanFunctionDefinition_table_t t)
{
    __flatbuffers_memoize_begin(B, t);
    if (rrc_conf_RanFunctionDefinition_start(B)
        || rrc_conf_RanFunctionDefinition_supportedReportStyles_pick(B, t)) {
        return 0;
    }
    __flatbuffers_memoize_end(B, t, rrc_conf_RanFunctionDefinition_end(B));
}

#include "flatcc/flatcc_epilogue.h"
#endif /* RRC_CONF_BUILDER_H */
