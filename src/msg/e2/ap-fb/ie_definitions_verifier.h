#ifndef IE_DEFINITIONS_VERIFIER_H
#define IE_DEFINITIONS_VERIFIER_H

/* Generated by flatcc 0.6.1-dev FlatBuffers schema compiler for C by dvide.com */

#ifndef IE_DEFINITIONS_READER_H
#include "ie_definitions_reader.h"
#endif
#include "flatcc/flatcc_verifier.h"
#include "flatcc/flatcc_prologue.h"

static int e2ap_RicRequest_verify_table(flatcc_table_verifier_descriptor_t *td);
static int e2ap_RicService_verify_table(flatcc_table_verifier_descriptor_t *td);
static int e2ap_TransportLayer_verify_table(flatcc_table_verifier_descriptor_t *td);
static int e2ap_Protocol_verify_table(flatcc_table_verifier_descriptor_t *td);
static int e2ap_Misc_verify_table(flatcc_table_verifier_descriptor_t *td);
static int e2ap_IECriticalityDiagnostics_verify_table(flatcc_table_verifier_descriptor_t *td);
static int e2ap_CriticalityDiagnostics_verify_table(flatcc_table_verifier_descriptor_t *td);
static int e2ap_GlobalRicId_verify_table(flatcc_table_verifier_descriptor_t *td);
static int e2ap_RicSubsequentAction_verify_table(flatcc_table_verifier_descriptor_t *td);
static int e2ap_gnbE2NodeCompConfUpdate_verify_table(flatcc_table_verifier_descriptor_t *td);
static int e2ap_en_gnbE2NodeCompConfUpdate_verify_table(flatcc_table_verifier_descriptor_t *td);
static int e2ap_ng_enbE2NodeCompConfUpdate_verify_table(flatcc_table_verifier_descriptor_t *td);
static int e2ap_enbE2NodeCompConfUpdate_verify_table(flatcc_table_verifier_descriptor_t *td);
static int e2ap_E2NodeCompConfUpdateAck_verify_table(flatcc_table_verifier_descriptor_t *td);
static int e2ap_TransportLayerInformation_verify_table(flatcc_table_verifier_descriptor_t *td);
static int e2ap_GNB_verify_table(flatcc_table_verifier_descriptor_t *td);

static int e2ap_Cause_union_verifier(flatcc_union_verifier_descriptor_t *ud)
{
    switch (ud->type) {
    case 1: return flatcc_verify_union_table(ud, e2ap_RicRequest_verify_table); /* ricRequest */
    case 2: return flatcc_verify_union_table(ud, e2ap_RicService_verify_table); /* ricService */
    case 3: return flatcc_verify_union_table(ud, e2ap_TransportLayer_verify_table); /* transportLayer */
    case 4: return flatcc_verify_union_table(ud, e2ap_Protocol_verify_table); /* protocol */
    case 5: return flatcc_verify_union_table(ud, e2ap_Misc_verify_table); /* misc */
    default: return flatcc_verify_ok;
    }
}

static int e2ap_GlobalE2NodeId_union_verifier(flatcc_union_verifier_descriptor_t *ud)
{
    switch (ud->type) {
    case 1: return flatcc_verify_union_table(ud, e2ap_GNB_verify_table); /* gNB */
    case 2: return flatcc_verify_union_struct(ud, 12, 4); /* engNB */
    case 3: return flatcc_verify_union_struct(ud, 12, 4); /* ngeNB */
    case 4: return flatcc_verify_union_struct(ud, 12, 4); /* eNB */
    default: return flatcc_verify_ok;
    }
}

static int e2ap_E2NodeCompConfUpdate_union_verifier(flatcc_union_verifier_descriptor_t *ud)
{
    switch (ud->type) {
    case 1: return flatcc_verify_union_table(ud, e2ap_gnbE2NodeCompConfUpdate_verify_table); /* gnb */
    case 2: return flatcc_verify_union_table(ud, e2ap_en_gnbE2NodeCompConfUpdate_verify_table); /* en_gnb */
    case 3: return flatcc_verify_union_table(ud, e2ap_ng_enbE2NodeCompConfUpdate_verify_table); /* ng_enb */
    case 4: return flatcc_verify_union_table(ud, e2ap_enbE2NodeCompConfUpdate_verify_table); /* enb */
    default: return flatcc_verify_ok;
    }
}

static int e2ap_E2NodeCompId_union_verifier(flatcc_union_verifier_descriptor_t *ud)
{
    switch (ud->type) {
    case 1: return flatcc_verify_union_struct(ud, 8, 8); /* gnb_cu_up */
    case 2: return flatcc_verify_union_struct(ud, 8, 8); /* gnb_du */
    default: return flatcc_verify_ok;
    }
}

static inline int e2ap_RicRequestId_verify_as_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_struct_as_root(buf, bufsiz, e2ap_RicRequestId_identifier, 4, 2);
}

static inline int e2ap_RicRequestId_verify_as_typed_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_struct_as_typed_root(buf, bufsiz, e2ap_RicRequestId_type_hash, 4, 2);
}

static inline int e2ap_RicRequestId_verify_as_root_with_type_hash(const void *buf, size_t bufsiz, flatbuffers_thash_t thash)
{
    return flatcc_verify_struct_as_typed_root(buf, bufsiz, thash, 4, 2);
}

static inline int e2ap_RicRequestId_verify_as_root_with_identifier(const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_verify_struct_as_root(buf, bufsiz, fid, 4, 2);
}

static inline int e2ap_E2NCId_verify_as_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_struct_as_root(buf, bufsiz, e2ap_E2NCId_identifier, 8, 8);
}

static inline int e2ap_E2NCId_verify_as_typed_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_struct_as_typed_root(buf, bufsiz, e2ap_E2NCId_type_hash, 8, 8);
}

static inline int e2ap_E2NCId_verify_as_root_with_type_hash(const void *buf, size_t bufsiz, flatbuffers_thash_t thash)
{
    return flatcc_verify_struct_as_typed_root(buf, bufsiz, thash, 8, 8);
}

static inline int e2ap_E2NCId_verify_as_root_with_identifier(const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_verify_struct_as_root(buf, bufsiz, fid, 8, 8);
}

static inline int e2ap_Plmn_verify_as_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_struct_as_root(buf, bufsiz, e2ap_Plmn_identifier, 6, 2);
}

static inline int e2ap_Plmn_verify_as_typed_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_struct_as_typed_root(buf, bufsiz, e2ap_Plmn_type_hash, 6, 2);
}

static inline int e2ap_Plmn_verify_as_root_with_type_hash(const void *buf, size_t bufsiz, flatbuffers_thash_t thash)
{
    return flatcc_verify_struct_as_typed_root(buf, bufsiz, thash, 6, 2);
}

static inline int e2ap_Plmn_verify_as_root_with_identifier(const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_verify_struct_as_root(buf, bufsiz, fid, 6, 2);
}

static inline int e2ap_EngNB_verify_as_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_struct_as_root(buf, bufsiz, e2ap_EngNB_identifier, 12, 4);
}

static inline int e2ap_EngNB_verify_as_typed_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_struct_as_typed_root(buf, bufsiz, e2ap_EngNB_type_hash, 12, 4);
}

static inline int e2ap_EngNB_verify_as_root_with_type_hash(const void *buf, size_t bufsiz, flatbuffers_thash_t thash)
{
    return flatcc_verify_struct_as_typed_root(buf, bufsiz, thash, 12, 4);
}

static inline int e2ap_EngNB_verify_as_root_with_identifier(const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_verify_struct_as_root(buf, bufsiz, fid, 12, 4);
}

static inline int e2ap_NgeNB_verify_as_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_struct_as_root(buf, bufsiz, e2ap_NgeNB_identifier, 12, 4);
}

static inline int e2ap_NgeNB_verify_as_typed_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_struct_as_typed_root(buf, bufsiz, e2ap_NgeNB_type_hash, 12, 4);
}

static inline int e2ap_NgeNB_verify_as_root_with_type_hash(const void *buf, size_t bufsiz, flatbuffers_thash_t thash)
{
    return flatcc_verify_struct_as_typed_root(buf, bufsiz, thash, 12, 4);
}

static inline int e2ap_NgeNB_verify_as_root_with_identifier(const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_verify_struct_as_root(buf, bufsiz, fid, 12, 4);
}

static inline int e2ap_ENB_verify_as_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_struct_as_root(buf, bufsiz, e2ap_ENB_identifier, 12, 4);
}

static inline int e2ap_ENB_verify_as_typed_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_struct_as_typed_root(buf, bufsiz, e2ap_ENB_type_hash, 12, 4);
}

static inline int e2ap_ENB_verify_as_root_with_type_hash(const void *buf, size_t bufsiz, flatbuffers_thash_t thash)
{
    return flatcc_verify_struct_as_typed_root(buf, bufsiz, thash, 12, 4);
}

static inline int e2ap_ENB_verify_as_root_with_identifier(const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_verify_struct_as_root(buf, bufsiz, fid, 12, 4);
}

static int e2ap_RicRequest_verify_table(flatcc_table_verifier_descriptor_t *td)
{
    int ret;
    if ((ret = flatcc_verify_field(td, 0, 1, 1) /* ricRequestCause */)) return ret;
    return flatcc_verify_ok;
}

static inline int e2ap_RicRequest_verify_as_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_RicRequest_identifier, &e2ap_RicRequest_verify_table);
}

static inline int e2ap_RicRequest_verify_as_typed_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_RicRequest_type_identifier, &e2ap_RicRequest_verify_table);
}

static inline int e2ap_RicRequest_verify_as_root_with_identifier(const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_verify_table_as_root(buf, bufsiz, fid, &e2ap_RicRequest_verify_table);
}

static inline int e2ap_RicRequest_verify_as_root_with_type_hash(const void *buf, size_t bufsiz, flatbuffers_thash_t thash)
{
    return flatcc_verify_table_as_typed_root(buf, bufsiz, thash, &e2ap_RicRequest_verify_table);
}

static int e2ap_RicService_verify_table(flatcc_table_verifier_descriptor_t *td)
{
    int ret;
    if ((ret = flatcc_verify_field(td, 0, 1, 1) /* ricServiceCause */)) return ret;
    return flatcc_verify_ok;
}

static inline int e2ap_RicService_verify_as_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_RicService_identifier, &e2ap_RicService_verify_table);
}

static inline int e2ap_RicService_verify_as_typed_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_RicService_type_identifier, &e2ap_RicService_verify_table);
}

static inline int e2ap_RicService_verify_as_root_with_identifier(const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_verify_table_as_root(buf, bufsiz, fid, &e2ap_RicService_verify_table);
}

static inline int e2ap_RicService_verify_as_root_with_type_hash(const void *buf, size_t bufsiz, flatbuffers_thash_t thash)
{
    return flatcc_verify_table_as_typed_root(buf, bufsiz, thash, &e2ap_RicService_verify_table);
}

static int e2ap_TransportLayer_verify_table(flatcc_table_verifier_descriptor_t *td)
{
    int ret;
    if ((ret = flatcc_verify_field(td, 0, 1, 1) /* transportLayerCause */)) return ret;
    return flatcc_verify_ok;
}

static inline int e2ap_TransportLayer_verify_as_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_TransportLayer_identifier, &e2ap_TransportLayer_verify_table);
}

static inline int e2ap_TransportLayer_verify_as_typed_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_TransportLayer_type_identifier, &e2ap_TransportLayer_verify_table);
}

static inline int e2ap_TransportLayer_verify_as_root_with_identifier(const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_verify_table_as_root(buf, bufsiz, fid, &e2ap_TransportLayer_verify_table);
}

static inline int e2ap_TransportLayer_verify_as_root_with_type_hash(const void *buf, size_t bufsiz, flatbuffers_thash_t thash)
{
    return flatcc_verify_table_as_typed_root(buf, bufsiz, thash, &e2ap_TransportLayer_verify_table);
}

static int e2ap_Protocol_verify_table(flatcc_table_verifier_descriptor_t *td)
{
    int ret;
    if ((ret = flatcc_verify_field(td, 0, 1, 1) /* protocolCause */)) return ret;
    return flatcc_verify_ok;
}

static inline int e2ap_Protocol_verify_as_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_Protocol_identifier, &e2ap_Protocol_verify_table);
}

static inline int e2ap_Protocol_verify_as_typed_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_Protocol_type_identifier, &e2ap_Protocol_verify_table);
}

static inline int e2ap_Protocol_verify_as_root_with_identifier(const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_verify_table_as_root(buf, bufsiz, fid, &e2ap_Protocol_verify_table);
}

static inline int e2ap_Protocol_verify_as_root_with_type_hash(const void *buf, size_t bufsiz, flatbuffers_thash_t thash)
{
    return flatcc_verify_table_as_typed_root(buf, bufsiz, thash, &e2ap_Protocol_verify_table);
}

static int e2ap_Misc_verify_table(flatcc_table_verifier_descriptor_t *td)
{
    int ret;
    if ((ret = flatcc_verify_field(td, 0, 1, 1) /* miscellaneousCause */)) return ret;
    return flatcc_verify_ok;
}

static inline int e2ap_Misc_verify_as_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_Misc_identifier, &e2ap_Misc_verify_table);
}

static inline int e2ap_Misc_verify_as_typed_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_Misc_type_identifier, &e2ap_Misc_verify_table);
}

static inline int e2ap_Misc_verify_as_root_with_identifier(const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_verify_table_as_root(buf, bufsiz, fid, &e2ap_Misc_verify_table);
}

static inline int e2ap_Misc_verify_as_root_with_type_hash(const void *buf, size_t bufsiz, flatbuffers_thash_t thash)
{
    return flatcc_verify_table_as_typed_root(buf, bufsiz, thash, &e2ap_Misc_verify_table);
}

static int e2ap_IECriticalityDiagnostics_verify_table(flatcc_table_verifier_descriptor_t *td)
{
    int ret;
    if ((ret = flatcc_verify_field(td, 0, 1, 1) /* criticality */)) return ret;
    if ((ret = flatcc_verify_field(td, 1, 2, 2) /* ieId */)) return ret;
    if ((ret = flatcc_verify_field(td, 2, 1, 1) /* typeOfError */)) return ret;
    return flatcc_verify_ok;
}

static inline int e2ap_IECriticalityDiagnostics_verify_as_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_IECriticalityDiagnostics_identifier, &e2ap_IECriticalityDiagnostics_verify_table);
}

static inline int e2ap_IECriticalityDiagnostics_verify_as_typed_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_IECriticalityDiagnostics_type_identifier, &e2ap_IECriticalityDiagnostics_verify_table);
}

static inline int e2ap_IECriticalityDiagnostics_verify_as_root_with_identifier(const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_verify_table_as_root(buf, bufsiz, fid, &e2ap_IECriticalityDiagnostics_verify_table);
}

static inline int e2ap_IECriticalityDiagnostics_verify_as_root_with_type_hash(const void *buf, size_t bufsiz, flatbuffers_thash_t thash)
{
    return flatcc_verify_table_as_typed_root(buf, bufsiz, thash, &e2ap_IECriticalityDiagnostics_verify_table);
}

static int e2ap_CriticalityDiagnostics_verify_table(flatcc_table_verifier_descriptor_t *td)
{
    int ret;
    if ((ret = flatcc_verify_field(td, 0, 1, 1) /* procedureCode */)) return ret;
    if ((ret = flatcc_verify_field(td, 1, 1, 1) /* triggeringMessage */)) return ret;
    if ((ret = flatcc_verify_field(td, 2, 1, 1) /* procedureCriticality */)) return ret;
    if ((ret = flatcc_verify_table_vector_field(td, 3, 0, &e2ap_IECriticalityDiagnostics_verify_table) /* ieCriticalityDiagnostics */)) return ret;
    return flatcc_verify_ok;
}

static inline int e2ap_CriticalityDiagnostics_verify_as_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_CriticalityDiagnostics_identifier, &e2ap_CriticalityDiagnostics_verify_table);
}

static inline int e2ap_CriticalityDiagnostics_verify_as_typed_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_CriticalityDiagnostics_type_identifier, &e2ap_CriticalityDiagnostics_verify_table);
}

static inline int e2ap_CriticalityDiagnostics_verify_as_root_with_identifier(const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_verify_table_as_root(buf, bufsiz, fid, &e2ap_CriticalityDiagnostics_verify_table);
}

static inline int e2ap_CriticalityDiagnostics_verify_as_root_with_type_hash(const void *buf, size_t bufsiz, flatbuffers_thash_t thash)
{
    return flatcc_verify_table_as_typed_root(buf, bufsiz, thash, &e2ap_CriticalityDiagnostics_verify_table);
}

static int e2ap_GlobalRicId_verify_table(flatcc_table_verifier_descriptor_t *td)
{
    int ret;
    if ((ret = flatcc_verify_field(td, 0, 6, 2) /* plmn */)) return ret;
    if ((ret = flatcc_verify_field(td, 1, 4, 4) /* nearRtRicId */)) return ret;
    return flatcc_verify_ok;
}

static inline int e2ap_GlobalRicId_verify_as_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_GlobalRicId_identifier, &e2ap_GlobalRicId_verify_table);
}

static inline int e2ap_GlobalRicId_verify_as_typed_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_GlobalRicId_type_identifier, &e2ap_GlobalRicId_verify_table);
}

static inline int e2ap_GlobalRicId_verify_as_root_with_identifier(const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_verify_table_as_root(buf, bufsiz, fid, &e2ap_GlobalRicId_verify_table);
}

static inline int e2ap_GlobalRicId_verify_as_root_with_type_hash(const void *buf, size_t bufsiz, flatbuffers_thash_t thash)
{
    return flatcc_verify_table_as_typed_root(buf, bufsiz, thash, &e2ap_GlobalRicId_verify_table);
}

static int e2ap_RicSubsequentAction_verify_table(flatcc_table_verifier_descriptor_t *td)
{
    int ret;
    if ((ret = flatcc_verify_field(td, 0, 1, 1) /* type */)) return ret;
    if ((ret = flatcc_verify_field(td, 1, 4, 4) /* timeToWait */)) return ret;
    return flatcc_verify_ok;
}

static inline int e2ap_RicSubsequentAction_verify_as_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_RicSubsequentAction_identifier, &e2ap_RicSubsequentAction_verify_table);
}

static inline int e2ap_RicSubsequentAction_verify_as_typed_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_RicSubsequentAction_type_identifier, &e2ap_RicSubsequentAction_verify_table);
}

static inline int e2ap_RicSubsequentAction_verify_as_root_with_identifier(const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_verify_table_as_root(buf, bufsiz, fid, &e2ap_RicSubsequentAction_verify_table);
}

static inline int e2ap_RicSubsequentAction_verify_as_root_with_type_hash(const void *buf, size_t bufsiz, flatbuffers_thash_t thash)
{
    return flatcc_verify_table_as_typed_root(buf, bufsiz, thash, &e2ap_RicSubsequentAction_verify_table);
}

static int e2ap_gnbE2NodeCompConfUpdate_verify_table(flatcc_table_verifier_descriptor_t *td)
{
    int ret;
    if ((ret = flatcc_verify_vector_field(td, 0, 0, 1, 1, INT64_C(4294967295)) /* ngap_gnb_cu_cp */)) return ret;
    if ((ret = flatcc_verify_vector_field(td, 1, 0, 1, 1, INT64_C(4294967295)) /* xnap_gnb_cu_cp */)) return ret;
    if ((ret = flatcc_verify_vector_field(td, 2, 0, 1, 1, INT64_C(4294967295)) /* e1ap_gnb_cu_cp */)) return ret;
    if ((ret = flatcc_verify_vector_field(td, 3, 0, 1, 1, INT64_C(4294967295)) /* f1ap_gnb_cu_cp */)) return ret;
    return flatcc_verify_ok;
}

static inline int e2ap_gnbE2NodeCompConfUpdate_verify_as_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_gnbE2NodeCompConfUpdate_identifier, &e2ap_gnbE2NodeCompConfUpdate_verify_table);
}

static inline int e2ap_gnbE2NodeCompConfUpdate_verify_as_typed_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_gnbE2NodeCompConfUpdate_type_identifier, &e2ap_gnbE2NodeCompConfUpdate_verify_table);
}

static inline int e2ap_gnbE2NodeCompConfUpdate_verify_as_root_with_identifier(const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_verify_table_as_root(buf, bufsiz, fid, &e2ap_gnbE2NodeCompConfUpdate_verify_table);
}

static inline int e2ap_gnbE2NodeCompConfUpdate_verify_as_root_with_type_hash(const void *buf, size_t bufsiz, flatbuffers_thash_t thash)
{
    return flatcc_verify_table_as_typed_root(buf, bufsiz, thash, &e2ap_gnbE2NodeCompConfUpdate_verify_table);
}

static int e2ap_en_gnbE2NodeCompConfUpdate_verify_table(flatcc_table_verifier_descriptor_t *td)
{
    int ret;
    if ((ret = flatcc_verify_vector_field(td, 0, 0, 1, 1, INT64_C(4294967295)) /* x2ap_en_gnb */)) return ret;
    return flatcc_verify_ok;
}

static inline int e2ap_en_gnbE2NodeCompConfUpdate_verify_as_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_en_gnbE2NodeCompConfUpdate_identifier, &e2ap_en_gnbE2NodeCompConfUpdate_verify_table);
}

static inline int e2ap_en_gnbE2NodeCompConfUpdate_verify_as_typed_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_en_gnbE2NodeCompConfUpdate_type_identifier, &e2ap_en_gnbE2NodeCompConfUpdate_verify_table);
}

static inline int e2ap_en_gnbE2NodeCompConfUpdate_verify_as_root_with_identifier(const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_verify_table_as_root(buf, bufsiz, fid, &e2ap_en_gnbE2NodeCompConfUpdate_verify_table);
}

static inline int e2ap_en_gnbE2NodeCompConfUpdate_verify_as_root_with_type_hash(const void *buf, size_t bufsiz, flatbuffers_thash_t thash)
{
    return flatcc_verify_table_as_typed_root(buf, bufsiz, thash, &e2ap_en_gnbE2NodeCompConfUpdate_verify_table);
}

static int e2ap_ng_enbE2NodeCompConfUpdate_verify_table(flatcc_table_verifier_descriptor_t *td)
{
    int ret;
    if ((ret = flatcc_verify_vector_field(td, 0, 0, 1, 1, INT64_C(4294967295)) /* ngap_ng_enb */)) return ret;
    if ((ret = flatcc_verify_vector_field(td, 1, 0, 1, 1, INT64_C(4294967295)) /* xap_ng_enb */)) return ret;
    return flatcc_verify_ok;
}

static inline int e2ap_ng_enbE2NodeCompConfUpdate_verify_as_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_ng_enbE2NodeCompConfUpdate_identifier, &e2ap_ng_enbE2NodeCompConfUpdate_verify_table);
}

static inline int e2ap_ng_enbE2NodeCompConfUpdate_verify_as_typed_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_ng_enbE2NodeCompConfUpdate_type_identifier, &e2ap_ng_enbE2NodeCompConfUpdate_verify_table);
}

static inline int e2ap_ng_enbE2NodeCompConfUpdate_verify_as_root_with_identifier(const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_verify_table_as_root(buf, bufsiz, fid, &e2ap_ng_enbE2NodeCompConfUpdate_verify_table);
}

static inline int e2ap_ng_enbE2NodeCompConfUpdate_verify_as_root_with_type_hash(const void *buf, size_t bufsiz, flatbuffers_thash_t thash)
{
    return flatcc_verify_table_as_typed_root(buf, bufsiz, thash, &e2ap_ng_enbE2NodeCompConfUpdate_verify_table);
}

static int e2ap_enbE2NodeCompConfUpdate_verify_table(flatcc_table_verifier_descriptor_t *td)
{
    int ret;
    if ((ret = flatcc_verify_vector_field(td, 0, 0, 1, 1, INT64_C(4294967295)) /* s1ap_enb */)) return ret;
    if ((ret = flatcc_verify_vector_field(td, 1, 0, 1, 1, INT64_C(4294967295)) /* x2ap_enb */)) return ret;
    return flatcc_verify_ok;
}

static inline int e2ap_enbE2NodeCompConfUpdate_verify_as_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_enbE2NodeCompConfUpdate_identifier, &e2ap_enbE2NodeCompConfUpdate_verify_table);
}

static inline int e2ap_enbE2NodeCompConfUpdate_verify_as_typed_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_enbE2NodeCompConfUpdate_type_identifier, &e2ap_enbE2NodeCompConfUpdate_verify_table);
}

static inline int e2ap_enbE2NodeCompConfUpdate_verify_as_root_with_identifier(const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_verify_table_as_root(buf, bufsiz, fid, &e2ap_enbE2NodeCompConfUpdate_verify_table);
}

static inline int e2ap_enbE2NodeCompConfUpdate_verify_as_root_with_type_hash(const void *buf, size_t bufsiz, flatbuffers_thash_t thash)
{
    return flatcc_verify_table_as_typed_root(buf, bufsiz, thash, &e2ap_enbE2NodeCompConfUpdate_verify_table);
}

static int e2ap_E2NodeCompConfUpdateAck_verify_table(flatcc_table_verifier_descriptor_t *td)
{
    int ret;
    if ((ret = flatcc_verify_field(td, 0, 1, 1) /* outcome */)) return ret;
    if ((ret = flatcc_verify_union_field(td, 2, 0, &e2ap_Cause_union_verifier) /* cause */)) return ret;
    return flatcc_verify_ok;
}

static inline int e2ap_E2NodeCompConfUpdateAck_verify_as_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_E2NodeCompConfUpdateAck_identifier, &e2ap_E2NodeCompConfUpdateAck_verify_table);
}

static inline int e2ap_E2NodeCompConfUpdateAck_verify_as_typed_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_E2NodeCompConfUpdateAck_type_identifier, &e2ap_E2NodeCompConfUpdateAck_verify_table);
}

static inline int e2ap_E2NodeCompConfUpdateAck_verify_as_root_with_identifier(const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_verify_table_as_root(buf, bufsiz, fid, &e2ap_E2NodeCompConfUpdateAck_verify_table);
}

static inline int e2ap_E2NodeCompConfUpdateAck_verify_as_root_with_type_hash(const void *buf, size_t bufsiz, flatbuffers_thash_t thash)
{
    return flatcc_verify_table_as_typed_root(buf, bufsiz, thash, &e2ap_E2NodeCompConfUpdateAck_verify_table);
}

static int e2ap_TransportLayerInformation_verify_table(flatcc_table_verifier_descriptor_t *td)
{
    int ret;
    if ((ret = flatcc_verify_vector_field(td, 0, 0, 1, 1, INT64_C(4294967295)) /* transportLayerAddress */)) return ret;
    if ((ret = flatcc_verify_field(td, 1, 2, 2) /* transportLayerPort */)) return ret;
    return flatcc_verify_ok;
}

static inline int e2ap_TransportLayerInformation_verify_as_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_TransportLayerInformation_identifier, &e2ap_TransportLayerInformation_verify_table);
}

static inline int e2ap_TransportLayerInformation_verify_as_typed_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_TransportLayerInformation_type_identifier, &e2ap_TransportLayerInformation_verify_table);
}

static inline int e2ap_TransportLayerInformation_verify_as_root_with_identifier(const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_verify_table_as_root(buf, bufsiz, fid, &e2ap_TransportLayerInformation_verify_table);
}

static inline int e2ap_TransportLayerInformation_verify_as_root_with_type_hash(const void *buf, size_t bufsiz, flatbuffers_thash_t thash)
{
    return flatcc_verify_table_as_typed_root(buf, bufsiz, thash, &e2ap_TransportLayerInformation_verify_table);
}

static int e2ap_GNB_verify_table(flatcc_table_verifier_descriptor_t *td)
{
    int ret;
    if ((ret = flatcc_verify_field(td, 0, 6, 2) /* plmn */)) return ret;
    if ((ret = flatcc_verify_field(td, 1, 4, 4) /* id */)) return ret;
    if ((ret = flatcc_verify_field(td, 2, 8, 8) /* cu_up_id */)) return ret;
    if ((ret = flatcc_verify_field(td, 3, 8, 8) /* du_id */)) return ret;
    return flatcc_verify_ok;
}

static inline int e2ap_GNB_verify_as_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_GNB_identifier, &e2ap_GNB_verify_table);
}

static inline int e2ap_GNB_verify_as_typed_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_GNB_type_identifier, &e2ap_GNB_verify_table);
}

static inline int e2ap_GNB_verify_as_root_with_identifier(const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_verify_table_as_root(buf, bufsiz, fid, &e2ap_GNB_verify_table);
}

static inline int e2ap_GNB_verify_as_root_with_type_hash(const void *buf, size_t bufsiz, flatbuffers_thash_t thash)
{
    return flatcc_verify_table_as_typed_root(buf, bufsiz, thash, &e2ap_GNB_verify_table);
}

#include "flatcc/flatcc_epilogue.h"
#endif /* IE_DEFINITIONS_VERIFIER_H */
