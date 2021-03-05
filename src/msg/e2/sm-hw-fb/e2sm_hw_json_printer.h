#ifndef E2SM_HW_JSON_PRINTER_H
#define E2SM_HW_JSON_PRINTER_H

/* Generated by flatcc 0.6.1-dev FlatBuffers schema compiler for C by dvide.com */

#include "flatcc/flatcc_json_printer.h"
#include "flatcc/flatcc_prologue.h"

static void hw_EventTriggerDefinitionFormat1_print_json_table(flatcc_json_printer_t *ctx, flatcc_json_printer_table_descriptor_t *td);
static void hw_EventTriggerUnion_print_json_union_type(flatcc_json_printer_t *ctx, flatbuffers_utype_t type);
static void hw_EventTriggerUnion_print_json_union(flatcc_json_printer_t *ctx, flatcc_json_printer_union_descriptor_t *ud);
static void hw_EventTrigger_print_json_table(flatcc_json_printer_t *ctx, flatcc_json_printer_table_descriptor_t *td);
static void hw_RanParameterItem_print_json_table(flatcc_json_printer_t *ctx, flatcc_json_printer_table_descriptor_t *td);
static void hw_ActionDefinitionFormat1_print_json_table(flatcc_json_printer_t *ctx, flatcc_json_printer_table_descriptor_t *td);
static void hw_ActionDefinitionUnion_print_json_union_type(flatcc_json_printer_t *ctx, flatbuffers_utype_t type);
static void hw_ActionDefinitionUnion_print_json_union(flatcc_json_printer_t *ctx, flatcc_json_printer_union_descriptor_t *ud);
static void hw_ActionDefinition_print_json_table(flatcc_json_printer_t *ctx, flatcc_json_printer_table_descriptor_t *td);
static void hw_IndicationHeaderFormat1_print_json_table(flatcc_json_printer_t *ctx, flatcc_json_printer_table_descriptor_t *td);
static void hw_IndicationHeaderUnion_print_json_union_type(flatcc_json_printer_t *ctx, flatbuffers_utype_t type);
static void hw_IndicationHeaderUnion_print_json_union(flatcc_json_printer_t *ctx, flatcc_json_printer_union_descriptor_t *ud);
static void hw_IndicationHeader_print_json_table(flatcc_json_printer_t *ctx, flatcc_json_printer_table_descriptor_t *td);
static void hw_IndicationMessageFormat1_print_json_table(flatcc_json_printer_t *ctx, flatcc_json_printer_table_descriptor_t *td);
static void hw_IndicationMessageUnion_print_json_union_type(flatcc_json_printer_t *ctx, flatbuffers_utype_t type);
static void hw_IndicationMessageUnion_print_json_union(flatcc_json_printer_t *ctx, flatcc_json_printer_union_descriptor_t *ud);
static void hw_IndicationMessage_print_json_table(flatcc_json_printer_t *ctx, flatcc_json_printer_table_descriptor_t *td);
static void hw_ControlHeaderFormat1_print_json_table(flatcc_json_printer_t *ctx, flatcc_json_printer_table_descriptor_t *td);
static void hw_ControlHeaderUnion_print_json_union_type(flatcc_json_printer_t *ctx, flatbuffers_utype_t type);
static void hw_ControlHeaderUnion_print_json_union(flatcc_json_printer_t *ctx, flatcc_json_printer_union_descriptor_t *ud);
static void hw_ControlHeader_print_json_table(flatcc_json_printer_t *ctx, flatcc_json_printer_table_descriptor_t *td);
static void hw_ControlMessageFormat1_print_json_table(flatcc_json_printer_t *ctx, flatcc_json_printer_table_descriptor_t *td);
static void hw_ControlMessageUnion_print_json_union_type(flatcc_json_printer_t *ctx, flatbuffers_utype_t type);
static void hw_ControlMessageUnion_print_json_union(flatcc_json_printer_t *ctx, flatcc_json_printer_union_descriptor_t *ud);
static void hw_ControlMessage_print_json_table(flatcc_json_printer_t *ctx, flatcc_json_printer_table_descriptor_t *td);

static void hw_TriggerNature_print_json_enum(flatcc_json_printer_t *ctx, uint8_t v)
{

    switch (v) {
    case 0: flatcc_json_printer_enum(ctx, "Now", 3); break;
    case 1: flatcc_json_printer_enum(ctx, "OnChange", 8); break;
    default: flatcc_json_printer_uint8(ctx, v); break;
    }
}

static void hw_RanParameterTest_print_json_enum(flatcc_json_printer_t *ctx, uint8_t v)
{

    switch (v) {
    case 0: flatcc_json_printer_enum(ctx, "equal", 5); break;
    case 1: flatcc_json_printer_enum(ctx, "greaterThan", 11); break;
    case 2: flatcc_json_printer_enum(ctx, "lessThan", 8); break;
    case 3: flatcc_json_printer_enum(ctx, "contains", 8); break;
    case 4: flatcc_json_printer_enum(ctx, "present", 7); break;
    default: flatcc_json_printer_uint8(ctx, v); break;
    }
}

static void hw_EventTriggerUnion_print_json_union_type(flatcc_json_printer_t *ctx, flatbuffers_utype_t type)
{
    switch (type) {
    case 1:
        flatcc_json_printer_enum(ctx, "eventDefF1", 10);
        break;
    default:
        flatcc_json_printer_enum(ctx, "NONE", 4);
        break;
    }
}

static void hw_EventTriggerUnion_print_json_union(flatcc_json_printer_t *ctx, flatcc_json_printer_union_descriptor_t *ud)
{
    switch (ud->type) {
    case 1:
        flatcc_json_printer_union_table(ctx, ud, hw_EventTriggerDefinitionFormat1_print_json_table);
        break;
    default:
        break;
    }
}

static void hw_ActionDefinitionUnion_print_json_union_type(flatcc_json_printer_t *ctx, flatbuffers_utype_t type)
{
    switch (type) {
    case 1:
        flatcc_json_printer_enum(ctx, "actionDefF1", 11);
        break;
    default:
        flatcc_json_printer_enum(ctx, "NONE", 4);
        break;
    }
}

static void hw_ActionDefinitionUnion_print_json_union(flatcc_json_printer_t *ctx, flatcc_json_printer_union_descriptor_t *ud)
{
    switch (ud->type) {
    case 1:
        flatcc_json_printer_union_table(ctx, ud, hw_ActionDefinitionFormat1_print_json_table);
        break;
    default:
        break;
    }
}

static void hw_IndicationHeaderUnion_print_json_union_type(flatcc_json_printer_t *ctx, flatbuffers_utype_t type)
{
    switch (type) {
    case 1:
        flatcc_json_printer_enum(ctx, "indHeaderF1", 11);
        break;
    default:
        flatcc_json_printer_enum(ctx, "NONE", 4);
        break;
    }
}

static void hw_IndicationHeaderUnion_print_json_union(flatcc_json_printer_t *ctx, flatcc_json_printer_union_descriptor_t *ud)
{
    switch (ud->type) {
    case 1:
        flatcc_json_printer_union_table(ctx, ud, hw_IndicationHeaderFormat1_print_json_table);
        break;
    default:
        break;
    }
}

static void hw_IndicationMessageUnion_print_json_union_type(flatcc_json_printer_t *ctx, flatbuffers_utype_t type)
{
    switch (type) {
    case 1:
        flatcc_json_printer_enum(ctx, "indMessageF1", 12);
        break;
    default:
        flatcc_json_printer_enum(ctx, "NONE", 4);
        break;
    }
}

static void hw_IndicationMessageUnion_print_json_union(flatcc_json_printer_t *ctx, flatcc_json_printer_union_descriptor_t *ud)
{
    switch (ud->type) {
    case 1:
        flatcc_json_printer_union_table(ctx, ud, hw_IndicationMessageFormat1_print_json_table);
        break;
    default:
        break;
    }
}

static void hw_ControlHeaderUnion_print_json_union_type(flatcc_json_printer_t *ctx, flatbuffers_utype_t type)
{
    switch (type) {
    case 1:
        flatcc_json_printer_enum(ctx, "ctrlHeaderF1", 12);
        break;
    default:
        flatcc_json_printer_enum(ctx, "NONE", 4);
        break;
    }
}

static void hw_ControlHeaderUnion_print_json_union(flatcc_json_printer_t *ctx, flatcc_json_printer_union_descriptor_t *ud)
{
    switch (ud->type) {
    case 1:
        flatcc_json_printer_union_table(ctx, ud, hw_ControlHeaderFormat1_print_json_table);
        break;
    default:
        break;
    }
}

static void hw_ControlMessageUnion_print_json_union_type(flatcc_json_printer_t *ctx, flatbuffers_utype_t type)
{
    switch (type) {
    case 1:
        flatcc_json_printer_enum(ctx, "ctrlMessageF1", 13);
        break;
    default:
        flatcc_json_printer_enum(ctx, "NONE", 4);
        break;
    }
}

static void hw_ControlMessageUnion_print_json_union(flatcc_json_printer_t *ctx, flatcc_json_printer_union_descriptor_t *ud)
{
    switch (ud->type) {
    case 1:
        flatcc_json_printer_union_table(ctx, ud, hw_ControlMessageFormat1_print_json_table);
        break;
    default:
        break;
    }
}

static void hw_EventTriggerDefinitionFormat1_print_json_table(flatcc_json_printer_t *ctx, flatcc_json_printer_table_descriptor_t *td)
{
    flatcc_json_printer_uint8_enum_field(ctx, td, 0, "triggerNature", 13, 0, hw_TriggerNature_print_json_enum);
}

static inline int hw_EventTriggerDefinitionFormat1_print_json_as_root(flatcc_json_printer_t *ctx, const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_json_printer_table_as_root(ctx, buf, bufsiz, fid, hw_EventTriggerDefinitionFormat1_print_json_table);
}

static void hw_EventTrigger_print_json_table(flatcc_json_printer_t *ctx, flatcc_json_printer_table_descriptor_t *td)
{
    flatcc_json_printer_union_field(ctx, td, 1, "trig", 4, hw_EventTriggerUnion_print_json_union_type, hw_EventTriggerUnion_print_json_union);
}

static inline int hw_EventTrigger_print_json_as_root(flatcc_json_printer_t *ctx, const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_json_printer_table_as_root(ctx, buf, bufsiz, fid, hw_EventTrigger_print_json_table);
}

static void hw_RanParameterItem_print_json_table(flatcc_json_printer_t *ctx, flatcc_json_printer_table_descriptor_t *td)
{
    flatcc_json_printer_uint32_field(ctx, td, 0, "id", 2, 0);
    flatcc_json_printer_string_field(ctx, td, 1, "name", 4);
    flatcc_json_printer_uint8_enum_field(ctx, td, 2, "test", 4, 0, hw_RanParameterTest_print_json_enum);
    flatcc_json_printer_string_field(ctx, td, 3, "value", 5);
}

static inline int hw_RanParameterItem_print_json_as_root(flatcc_json_printer_t *ctx, const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_json_printer_table_as_root(ctx, buf, bufsiz, fid, hw_RanParameterItem_print_json_table);
}

static void hw_ActionDefinitionFormat1_print_json_table(flatcc_json_printer_t *ctx, flatcc_json_printer_table_descriptor_t *td)
{
    flatcc_json_printer_table_vector_field(ctx, td, 0, "ranParameterList", 16, hw_RanParameterItem_print_json_table);
}

static inline int hw_ActionDefinitionFormat1_print_json_as_root(flatcc_json_printer_t *ctx, const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_json_printer_table_as_root(ctx, buf, bufsiz, fid, hw_ActionDefinitionFormat1_print_json_table);
}

static void hw_ActionDefinition_print_json_table(flatcc_json_printer_t *ctx, flatcc_json_printer_table_descriptor_t *td)
{
    flatcc_json_printer_union_field(ctx, td, 1, "def", 3, hw_ActionDefinitionUnion_print_json_union_type, hw_ActionDefinitionUnion_print_json_union);
}

static inline int hw_ActionDefinition_print_json_as_root(flatcc_json_printer_t *ctx, const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_json_printer_table_as_root(ctx, buf, bufsiz, fid, hw_ActionDefinition_print_json_table);
}

static void hw_IndicationHeaderFormat1_print_json_table(flatcc_json_printer_t *ctx, flatcc_json_printer_table_descriptor_t *td)
{
    flatcc_json_printer_uint32_field(ctx, td, 0, "param", 5, 0);
}

static inline int hw_IndicationHeaderFormat1_print_json_as_root(flatcc_json_printer_t *ctx, const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_json_printer_table_as_root(ctx, buf, bufsiz, fid, hw_IndicationHeaderFormat1_print_json_table);
}

static void hw_IndicationHeader_print_json_table(flatcc_json_printer_t *ctx, flatcc_json_printer_table_descriptor_t *td)
{
    flatcc_json_printer_union_field(ctx, td, 1, "hdr", 3, hw_IndicationHeaderUnion_print_json_union_type, hw_IndicationHeaderUnion_print_json_union);
}

static inline int hw_IndicationHeader_print_json_as_root(flatcc_json_printer_t *ctx, const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_json_printer_table_as_root(ctx, buf, bufsiz, fid, hw_IndicationHeader_print_json_table);
}

static void hw_IndicationMessageFormat1_print_json_table(flatcc_json_printer_t *ctx, flatcc_json_printer_table_descriptor_t *td)
{
    flatcc_json_printer_uint8_vector_field(ctx, td, 0, "param", 5);
}

static inline int hw_IndicationMessageFormat1_print_json_as_root(flatcc_json_printer_t *ctx, const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_json_printer_table_as_root(ctx, buf, bufsiz, fid, hw_IndicationMessageFormat1_print_json_table);
}

static void hw_IndicationMessage_print_json_table(flatcc_json_printer_t *ctx, flatcc_json_printer_table_descriptor_t *td)
{
    flatcc_json_printer_union_field(ctx, td, 1, "msg", 3, hw_IndicationMessageUnion_print_json_union_type, hw_IndicationMessageUnion_print_json_union);
}

static inline int hw_IndicationMessage_print_json_as_root(flatcc_json_printer_t *ctx, const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_json_printer_table_as_root(ctx, buf, bufsiz, fid, hw_IndicationMessage_print_json_table);
}

static void hw_ControlHeaderFormat1_print_json_table(flatcc_json_printer_t *ctx, flatcc_json_printer_table_descriptor_t *td)
{
    flatcc_json_printer_uint32_field(ctx, td, 0, "param", 5, 0);
}

static inline int hw_ControlHeaderFormat1_print_json_as_root(flatcc_json_printer_t *ctx, const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_json_printer_table_as_root(ctx, buf, bufsiz, fid, hw_ControlHeaderFormat1_print_json_table);
}

static void hw_ControlHeader_print_json_table(flatcc_json_printer_t *ctx, flatcc_json_printer_table_descriptor_t *td)
{
    flatcc_json_printer_union_field(ctx, td, 1, "hdr", 3, hw_ControlHeaderUnion_print_json_union_type, hw_ControlHeaderUnion_print_json_union);
}

static inline int hw_ControlHeader_print_json_as_root(flatcc_json_printer_t *ctx, const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_json_printer_table_as_root(ctx, buf, bufsiz, fid, hw_ControlHeader_print_json_table);
}

static void hw_ControlMessageFormat1_print_json_table(flatcc_json_printer_t *ctx, flatcc_json_printer_table_descriptor_t *td)
{
    flatcc_json_printer_uint8_vector_field(ctx, td, 0, "param", 5);
}

static inline int hw_ControlMessageFormat1_print_json_as_root(flatcc_json_printer_t *ctx, const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_json_printer_table_as_root(ctx, buf, bufsiz, fid, hw_ControlMessageFormat1_print_json_table);
}

static void hw_ControlMessage_print_json_table(flatcc_json_printer_t *ctx, flatcc_json_printer_table_descriptor_t *td)
{
    flatcc_json_printer_union_field(ctx, td, 1, "msg", 3, hw_ControlMessageUnion_print_json_union_type, hw_ControlMessageUnion_print_json_union);
}

static inline int hw_ControlMessage_print_json_as_root(flatcc_json_printer_t *ctx, const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_json_printer_table_as_root(ctx, buf, bufsiz, fid, hw_ControlMessage_print_json_table);
}

#include "flatcc/flatcc_epilogue.h"
#endif /* E2SM_HW_JSON_PRINTER_H */
