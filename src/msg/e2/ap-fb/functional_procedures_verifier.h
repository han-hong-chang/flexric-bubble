#ifndef FUNCTIONAL_PROCEDURES_VERIFIER_H
#define FUNCTIONAL_PROCEDURES_VERIFIER_H

/* Generated by flatcc 0.6.1-dev FlatBuffers schema compiler for C by dvide.com */

#ifndef FUNCTIONAL_PROCEDURES_READER_H
#include "functional_procedures_reader.h"
#endif
#include "flatcc/flatcc_verifier.h"
#ifndef IE_DEFINITIONS_VERIFIER_H
#include "ie_definitions_verifier.h"
#endif
#include "flatcc/flatcc_prologue.h"

static int e2ap_RicSubscriptionRequest_verify_table(flatcc_table_verifier_descriptor_t *td);
static int e2ap_Action_verify_table(flatcc_table_verifier_descriptor_t *td);
static int e2ap_RicSubscriptionResponse_verify_table(flatcc_table_verifier_descriptor_t *td);
static int e2ap_RicActionAdmitted_verify_table(flatcc_table_verifier_descriptor_t *td);
static int e2ap_RicActionNotAdmitted_verify_table(flatcc_table_verifier_descriptor_t *td);
static int e2ap_RicSubscriptionFailure_verify_table(flatcc_table_verifier_descriptor_t *td);
static int e2ap_RicSubscriptionDeleteRequest_verify_table(flatcc_table_verifier_descriptor_t *td);
static int e2ap_RicSubscriptionDeleteResponse_verify_table(flatcc_table_verifier_descriptor_t *td);
static int e2ap_RicSubscriptionDeleteFailure_verify_table(flatcc_table_verifier_descriptor_t *td);
static int e2ap_RicIndication_verify_table(flatcc_table_verifier_descriptor_t *td);
static int e2ap_RicControlRequest_verify_table(flatcc_table_verifier_descriptor_t *td);
static int e2ap_RicControlAcknowledge_verify_table(flatcc_table_verifier_descriptor_t *td);
static int e2ap_RicControlFailure_verify_table(flatcc_table_verifier_descriptor_t *td);

static int e2ap_RicSubscriptionRequest_verify_table(flatcc_table_verifier_descriptor_t *td)
{
    int ret;
    if ((ret = flatcc_verify_field(td, 0, 4, 2) /* requestId */)) return ret;
    if ((ret = flatcc_verify_field(td, 1, 2, 2) /* ranFunctionId */)) return ret;
    if ((ret = flatcc_verify_vector_field(td, 2, 0, 1, 1, INT64_C(4294967295)) /* eventTriggerDefinition */)) return ret;
    if ((ret = flatcc_verify_table_vector_field(td, 3, 0, &e2ap_Action_verify_table) /* actions */)) return ret;
    return flatcc_verify_ok;
}

static inline int e2ap_RicSubscriptionRequest_verify_as_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_RicSubscriptionRequest_identifier, &e2ap_RicSubscriptionRequest_verify_table);
}

static inline int e2ap_RicSubscriptionRequest_verify_as_typed_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_RicSubscriptionRequest_type_identifier, &e2ap_RicSubscriptionRequest_verify_table);
}

static inline int e2ap_RicSubscriptionRequest_verify_as_root_with_identifier(const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_verify_table_as_root(buf, bufsiz, fid, &e2ap_RicSubscriptionRequest_verify_table);
}

static inline int e2ap_RicSubscriptionRequest_verify_as_root_with_type_hash(const void *buf, size_t bufsiz, flatbuffers_thash_t thash)
{
    return flatcc_verify_table_as_typed_root(buf, bufsiz, thash, &e2ap_RicSubscriptionRequest_verify_table);
}

static int e2ap_Action_verify_table(flatcc_table_verifier_descriptor_t *td)
{
    int ret;
    if ((ret = flatcc_verify_field(td, 0, 1, 1) /* id */)) return ret;
    if ((ret = flatcc_verify_field(td, 1, 1, 1) /* type */)) return ret;
    if ((ret = flatcc_verify_vector_field(td, 2, 0, 1, 1, INT64_C(4294967295)) /* definition */)) return ret;
    if ((ret = flatcc_verify_table_field(td, 3, 0, &e2ap_RicSubsequentAction_verify_table) /* subsequentAction */)) return ret;
    return flatcc_verify_ok;
}

static inline int e2ap_Action_verify_as_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_Action_identifier, &e2ap_Action_verify_table);
}

static inline int e2ap_Action_verify_as_typed_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_Action_type_identifier, &e2ap_Action_verify_table);
}

static inline int e2ap_Action_verify_as_root_with_identifier(const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_verify_table_as_root(buf, bufsiz, fid, &e2ap_Action_verify_table);
}

static inline int e2ap_Action_verify_as_root_with_type_hash(const void *buf, size_t bufsiz, flatbuffers_thash_t thash)
{
    return flatcc_verify_table_as_typed_root(buf, bufsiz, thash, &e2ap_Action_verify_table);
}

static int e2ap_RicSubscriptionResponse_verify_table(flatcc_table_verifier_descriptor_t *td)
{
    int ret;
    if ((ret = flatcc_verify_field(td, 0, 4, 2) /* requestId */)) return ret;
    if ((ret = flatcc_verify_field(td, 1, 2, 2) /* ranFunctionId */)) return ret;
    if ((ret = flatcc_verify_table_vector_field(td, 2, 0, &e2ap_RicActionAdmitted_verify_table) /* admittedActions */)) return ret;
    if ((ret = flatcc_verify_table_vector_field(td, 3, 0, &e2ap_RicActionNotAdmitted_verify_table) /* notAdmittedActions */)) return ret;
    return flatcc_verify_ok;
}

static inline int e2ap_RicSubscriptionResponse_verify_as_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_RicSubscriptionResponse_identifier, &e2ap_RicSubscriptionResponse_verify_table);
}

static inline int e2ap_RicSubscriptionResponse_verify_as_typed_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_RicSubscriptionResponse_type_identifier, &e2ap_RicSubscriptionResponse_verify_table);
}

static inline int e2ap_RicSubscriptionResponse_verify_as_root_with_identifier(const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_verify_table_as_root(buf, bufsiz, fid, &e2ap_RicSubscriptionResponse_verify_table);
}

static inline int e2ap_RicSubscriptionResponse_verify_as_root_with_type_hash(const void *buf, size_t bufsiz, flatbuffers_thash_t thash)
{
    return flatcc_verify_table_as_typed_root(buf, bufsiz, thash, &e2ap_RicSubscriptionResponse_verify_table);
}

static int e2ap_RicActionAdmitted_verify_table(flatcc_table_verifier_descriptor_t *td)
{
    int ret;
    if ((ret = flatcc_verify_field(td, 0, 1, 1) /* id */)) return ret;
    return flatcc_verify_ok;
}

static inline int e2ap_RicActionAdmitted_verify_as_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_RicActionAdmitted_identifier, &e2ap_RicActionAdmitted_verify_table);
}

static inline int e2ap_RicActionAdmitted_verify_as_typed_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_RicActionAdmitted_type_identifier, &e2ap_RicActionAdmitted_verify_table);
}

static inline int e2ap_RicActionAdmitted_verify_as_root_with_identifier(const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_verify_table_as_root(buf, bufsiz, fid, &e2ap_RicActionAdmitted_verify_table);
}

static inline int e2ap_RicActionAdmitted_verify_as_root_with_type_hash(const void *buf, size_t bufsiz, flatbuffers_thash_t thash)
{
    return flatcc_verify_table_as_typed_root(buf, bufsiz, thash, &e2ap_RicActionAdmitted_verify_table);
}

static int e2ap_RicActionNotAdmitted_verify_table(flatcc_table_verifier_descriptor_t *td)
{
    int ret;
    if ((ret = flatcc_verify_field(td, 0, 1, 1) /* id */)) return ret;
    if ((ret = flatcc_verify_union_field(td, 2, 0, &e2ap_Cause_union_verifier) /* cause */)) return ret;
    return flatcc_verify_ok;
}

static inline int e2ap_RicActionNotAdmitted_verify_as_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_RicActionNotAdmitted_identifier, &e2ap_RicActionNotAdmitted_verify_table);
}

static inline int e2ap_RicActionNotAdmitted_verify_as_typed_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_RicActionNotAdmitted_type_identifier, &e2ap_RicActionNotAdmitted_verify_table);
}

static inline int e2ap_RicActionNotAdmitted_verify_as_root_with_identifier(const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_verify_table_as_root(buf, bufsiz, fid, &e2ap_RicActionNotAdmitted_verify_table);
}

static inline int e2ap_RicActionNotAdmitted_verify_as_root_with_type_hash(const void *buf, size_t bufsiz, flatbuffers_thash_t thash)
{
    return flatcc_verify_table_as_typed_root(buf, bufsiz, thash, &e2ap_RicActionNotAdmitted_verify_table);
}

static int e2ap_RicSubscriptionFailure_verify_table(flatcc_table_verifier_descriptor_t *td)
{
    int ret;
    if ((ret = flatcc_verify_field(td, 0, 4, 2) /* requestId */)) return ret;
    if ((ret = flatcc_verify_field(td, 1, 2, 2) /* ranFunctionId */)) return ret;
    if ((ret = flatcc_verify_table_vector_field(td, 2, 0, &e2ap_RicActionNotAdmitted_verify_table) /* notAdmittedActions */)) return ret;
    if ((ret = flatcc_verify_table_field(td, 3, 0, &e2ap_CriticalityDiagnostics_verify_table) /* criticalityDiagnostics */)) return ret;
    return flatcc_verify_ok;
}

static inline int e2ap_RicSubscriptionFailure_verify_as_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_RicSubscriptionFailure_identifier, &e2ap_RicSubscriptionFailure_verify_table);
}

static inline int e2ap_RicSubscriptionFailure_verify_as_typed_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_RicSubscriptionFailure_type_identifier, &e2ap_RicSubscriptionFailure_verify_table);
}

static inline int e2ap_RicSubscriptionFailure_verify_as_root_with_identifier(const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_verify_table_as_root(buf, bufsiz, fid, &e2ap_RicSubscriptionFailure_verify_table);
}

static inline int e2ap_RicSubscriptionFailure_verify_as_root_with_type_hash(const void *buf, size_t bufsiz, flatbuffers_thash_t thash)
{
    return flatcc_verify_table_as_typed_root(buf, bufsiz, thash, &e2ap_RicSubscriptionFailure_verify_table);
}

static int e2ap_RicSubscriptionDeleteRequest_verify_table(flatcc_table_verifier_descriptor_t *td)
{
    int ret;
    if ((ret = flatcc_verify_field(td, 0, 4, 2) /* requestId */)) return ret;
    if ((ret = flatcc_verify_field(td, 1, 2, 2) /* ranFunctionId */)) return ret;
    return flatcc_verify_ok;
}

static inline int e2ap_RicSubscriptionDeleteRequest_verify_as_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_RicSubscriptionDeleteRequest_identifier, &e2ap_RicSubscriptionDeleteRequest_verify_table);
}

static inline int e2ap_RicSubscriptionDeleteRequest_verify_as_typed_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_RicSubscriptionDeleteRequest_type_identifier, &e2ap_RicSubscriptionDeleteRequest_verify_table);
}

static inline int e2ap_RicSubscriptionDeleteRequest_verify_as_root_with_identifier(const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_verify_table_as_root(buf, bufsiz, fid, &e2ap_RicSubscriptionDeleteRequest_verify_table);
}

static inline int e2ap_RicSubscriptionDeleteRequest_verify_as_root_with_type_hash(const void *buf, size_t bufsiz, flatbuffers_thash_t thash)
{
    return flatcc_verify_table_as_typed_root(buf, bufsiz, thash, &e2ap_RicSubscriptionDeleteRequest_verify_table);
}

static int e2ap_RicSubscriptionDeleteResponse_verify_table(flatcc_table_verifier_descriptor_t *td)
{
    int ret;
    if ((ret = flatcc_verify_field(td, 0, 4, 2) /* requestId */)) return ret;
    if ((ret = flatcc_verify_field(td, 1, 2, 2) /* ranFunctionId */)) return ret;
    return flatcc_verify_ok;
}

static inline int e2ap_RicSubscriptionDeleteResponse_verify_as_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_RicSubscriptionDeleteResponse_identifier, &e2ap_RicSubscriptionDeleteResponse_verify_table);
}

static inline int e2ap_RicSubscriptionDeleteResponse_verify_as_typed_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_RicSubscriptionDeleteResponse_type_identifier, &e2ap_RicSubscriptionDeleteResponse_verify_table);
}

static inline int e2ap_RicSubscriptionDeleteResponse_verify_as_root_with_identifier(const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_verify_table_as_root(buf, bufsiz, fid, &e2ap_RicSubscriptionDeleteResponse_verify_table);
}

static inline int e2ap_RicSubscriptionDeleteResponse_verify_as_root_with_type_hash(const void *buf, size_t bufsiz, flatbuffers_thash_t thash)
{
    return flatcc_verify_table_as_typed_root(buf, bufsiz, thash, &e2ap_RicSubscriptionDeleteResponse_verify_table);
}

static int e2ap_RicSubscriptionDeleteFailure_verify_table(flatcc_table_verifier_descriptor_t *td)
{
    int ret;
    if ((ret = flatcc_verify_field(td, 0, 4, 2) /* requestId */)) return ret;
    if ((ret = flatcc_verify_field(td, 1, 2, 2) /* ranFunctionId */)) return ret;
    if ((ret = flatcc_verify_union_field(td, 3, 0, &e2ap_Cause_union_verifier) /* cause */)) return ret;
    if ((ret = flatcc_verify_table_field(td, 4, 0, &e2ap_CriticalityDiagnostics_verify_table) /* criticalityDiagnostics */)) return ret;
    return flatcc_verify_ok;
}

static inline int e2ap_RicSubscriptionDeleteFailure_verify_as_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_RicSubscriptionDeleteFailure_identifier, &e2ap_RicSubscriptionDeleteFailure_verify_table);
}

static inline int e2ap_RicSubscriptionDeleteFailure_verify_as_typed_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_RicSubscriptionDeleteFailure_type_identifier, &e2ap_RicSubscriptionDeleteFailure_verify_table);
}

static inline int e2ap_RicSubscriptionDeleteFailure_verify_as_root_with_identifier(const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_verify_table_as_root(buf, bufsiz, fid, &e2ap_RicSubscriptionDeleteFailure_verify_table);
}

static inline int e2ap_RicSubscriptionDeleteFailure_verify_as_root_with_type_hash(const void *buf, size_t bufsiz, flatbuffers_thash_t thash)
{
    return flatcc_verify_table_as_typed_root(buf, bufsiz, thash, &e2ap_RicSubscriptionDeleteFailure_verify_table);
}

static int e2ap_RicIndication_verify_table(flatcc_table_verifier_descriptor_t *td)
{
    int ret;
    if ((ret = flatcc_verify_field(td, 0, 4, 2) /* requestId */)) return ret;
    if ((ret = flatcc_verify_field(td, 1, 2, 2) /* ranFunctionId */)) return ret;
    if ((ret = flatcc_verify_field(td, 2, 1, 1) /* actionId */)) return ret;
    if ((ret = flatcc_verify_field(td, 3, 2, 2) /* sn */)) return ret;
    if ((ret = flatcc_verify_field(td, 4, 1, 1) /* indicationType */)) return ret;
    if ((ret = flatcc_verify_vector_field(td, 5, 0, 1, 1, INT64_C(4294967295)) /* header */)) return ret;
    if ((ret = flatcc_verify_vector_field(td, 6, 0, 1, 1, INT64_C(4294967295)) /* message */)) return ret;
    if ((ret = flatcc_verify_vector_field(td, 7, 0, 1, 1, INT64_C(4294967295)) /* callProcessId */)) return ret;
    return flatcc_verify_ok;
}

static inline int e2ap_RicIndication_verify_as_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_RicIndication_identifier, &e2ap_RicIndication_verify_table);
}

static inline int e2ap_RicIndication_verify_as_typed_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_RicIndication_type_identifier, &e2ap_RicIndication_verify_table);
}

static inline int e2ap_RicIndication_verify_as_root_with_identifier(const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_verify_table_as_root(buf, bufsiz, fid, &e2ap_RicIndication_verify_table);
}

static inline int e2ap_RicIndication_verify_as_root_with_type_hash(const void *buf, size_t bufsiz, flatbuffers_thash_t thash)
{
    return flatcc_verify_table_as_typed_root(buf, bufsiz, thash, &e2ap_RicIndication_verify_table);
}

static int e2ap_RicControlRequest_verify_table(flatcc_table_verifier_descriptor_t *td)
{
    int ret;
    if ((ret = flatcc_verify_field(td, 0, 4, 2) /* requestId */)) return ret;
    if ((ret = flatcc_verify_field(td, 1, 2, 2) /* ranFunctionId */)) return ret;
    if ((ret = flatcc_verify_vector_field(td, 2, 0, 1, 1, INT64_C(4294967295)) /* callProcessId */)) return ret;
    if ((ret = flatcc_verify_vector_field(td, 3, 0, 1, 1, INT64_C(4294967295)) /* header */)) return ret;
    if ((ret = flatcc_verify_vector_field(td, 4, 0, 1, 1, INT64_C(4294967295)) /* message */)) return ret;
    if ((ret = flatcc_verify_field(td, 5, 1, 1) /* ackRequest */)) return ret;
    return flatcc_verify_ok;
}

static inline int e2ap_RicControlRequest_verify_as_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_RicControlRequest_identifier, &e2ap_RicControlRequest_verify_table);
}

static inline int e2ap_RicControlRequest_verify_as_typed_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_RicControlRequest_type_identifier, &e2ap_RicControlRequest_verify_table);
}

static inline int e2ap_RicControlRequest_verify_as_root_with_identifier(const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_verify_table_as_root(buf, bufsiz, fid, &e2ap_RicControlRequest_verify_table);
}

static inline int e2ap_RicControlRequest_verify_as_root_with_type_hash(const void *buf, size_t bufsiz, flatbuffers_thash_t thash)
{
    return flatcc_verify_table_as_typed_root(buf, bufsiz, thash, &e2ap_RicControlRequest_verify_table);
}

static int e2ap_RicControlAcknowledge_verify_table(flatcc_table_verifier_descriptor_t *td)
{
    int ret;
    if ((ret = flatcc_verify_field(td, 0, 4, 2) /* requestId */)) return ret;
    if ((ret = flatcc_verify_field(td, 1, 2, 2) /* ranFunctionId */)) return ret;
    if ((ret = flatcc_verify_vector_field(td, 2, 0, 1, 1, INT64_C(4294967295)) /* callProcessId */)) return ret;
    if ((ret = flatcc_verify_field(td, 3, 1, 1) /* status */)) return ret;
    if ((ret = flatcc_verify_vector_field(td, 4, 0, 1, 1, INT64_C(4294967295)) /* outcome */)) return ret;
    return flatcc_verify_ok;
}

static inline int e2ap_RicControlAcknowledge_verify_as_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_RicControlAcknowledge_identifier, &e2ap_RicControlAcknowledge_verify_table);
}

static inline int e2ap_RicControlAcknowledge_verify_as_typed_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_RicControlAcknowledge_type_identifier, &e2ap_RicControlAcknowledge_verify_table);
}

static inline int e2ap_RicControlAcknowledge_verify_as_root_with_identifier(const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_verify_table_as_root(buf, bufsiz, fid, &e2ap_RicControlAcknowledge_verify_table);
}

static inline int e2ap_RicControlAcknowledge_verify_as_root_with_type_hash(const void *buf, size_t bufsiz, flatbuffers_thash_t thash)
{
    return flatcc_verify_table_as_typed_root(buf, bufsiz, thash, &e2ap_RicControlAcknowledge_verify_table);
}

static int e2ap_RicControlFailure_verify_table(flatcc_table_verifier_descriptor_t *td)
{
    int ret;
    if ((ret = flatcc_verify_field(td, 0, 4, 2) /* requestId */)) return ret;
    if ((ret = flatcc_verify_field(td, 1, 2, 2) /* ranFunctionId */)) return ret;
    if ((ret = flatcc_verify_vector_field(td, 2, 0, 1, 1, INT64_C(4294967295)) /* callProcessId */)) return ret;
    if ((ret = flatcc_verify_union_field(td, 4, 0, &e2ap_Cause_union_verifier) /* cause */)) return ret;
    if ((ret = flatcc_verify_vector_field(td, 5, 0, 1, 1, INT64_C(4294967295)) /* outcome */)) return ret;
    return flatcc_verify_ok;
}

static inline int e2ap_RicControlFailure_verify_as_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_RicControlFailure_identifier, &e2ap_RicControlFailure_verify_table);
}

static inline int e2ap_RicControlFailure_verify_as_typed_root(const void *buf, size_t bufsiz)
{
    return flatcc_verify_table_as_root(buf, bufsiz, e2ap_RicControlFailure_type_identifier, &e2ap_RicControlFailure_verify_table);
}

static inline int e2ap_RicControlFailure_verify_as_root_with_identifier(const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_verify_table_as_root(buf, bufsiz, fid, &e2ap_RicControlFailure_verify_table);
}

static inline int e2ap_RicControlFailure_verify_as_root_with_type_hash(const void *buf, size_t bufsiz, flatbuffers_thash_t thash)
{
    return flatcc_verify_table_as_typed_root(buf, bufsiz, thash, &e2ap_RicControlFailure_verify_table);
}

#include "flatcc/flatcc_epilogue.h"
#endif /* FUNCTIONAL_PROCEDURES_VERIFIER_H */
