#ifndef RRC_COMMON_READER_H
#define RRC_COMMON_READER_H

/* Generated by flatcc 0.6.1-dev FlatBuffers schema compiler for C by dvide.com */

#ifndef FLATBUFFERS_COMMON_READER_H
#include "flatbuffers_common_reader.h"
#endif
#include "flatcc/flatcc_flatbuffers.h"
#ifndef __alignas_is_defined
#include <stdalign.h>
#endif
#include "flatcc/flatcc_prologue.h"
#ifndef flatbuffers_identifier
#define flatbuffers_identifier 0
#endif
#ifndef flatbuffers_extension
#define flatbuffers_extension ".bin"
#endif


typedef const struct rrc_common_Snssai_table *rrc_common_Snssai_table_t;
typedef struct rrc_common_Snssai_table *rrc_common_Snssai_mutable_table_t;
typedef const flatbuffers_uoffset_t *rrc_common_Snssai_vec_t;
typedef flatbuffers_uoffset_t *rrc_common_Snssai_mutable_vec_t;
typedef const struct rrc_common_Plmn_table *rrc_common_Plmn_table_t;
typedef struct rrc_common_Plmn_table *rrc_common_Plmn_mutable_table_t;
typedef const flatbuffers_uoffset_t *rrc_common_Plmn_vec_t;
typedef flatbuffers_uoffset_t *rrc_common_Plmn_mutable_vec_t;
typedef const struct rrc_common_PlmnInfo_table *rrc_common_PlmnInfo_table_t;
typedef struct rrc_common_PlmnInfo_table *rrc_common_PlmnInfo_mutable_table_t;
typedef const flatbuffers_uoffset_t *rrc_common_PlmnInfo_vec_t;
typedef flatbuffers_uoffset_t *rrc_common_PlmnInfo_mutable_vec_t;
#ifndef rrc_common_Snssai_file_identifier
#define rrc_common_Snssai_file_identifier flatbuffers_identifier
#endif
/* deprecated, use rrc_common_Snssai_file_identifier */
#ifndef rrc_common_Snssai_identifier
#define rrc_common_Snssai_identifier flatbuffers_identifier
#endif
#define rrc_common_Snssai_type_hash ((flatbuffers_thash_t)0x3824d084)
#define rrc_common_Snssai_type_identifier "\x84\xd0\x24\x38"
#ifndef rrc_common_Plmn_file_identifier
#define rrc_common_Plmn_file_identifier flatbuffers_identifier
#endif
/* deprecated, use rrc_common_Plmn_file_identifier */
#ifndef rrc_common_Plmn_identifier
#define rrc_common_Plmn_identifier flatbuffers_identifier
#endif
#define rrc_common_Plmn_type_hash ((flatbuffers_thash_t)0x1d006aa)
#define rrc_common_Plmn_type_identifier "\xaa\x06\xd0\x01"
#ifndef rrc_common_PlmnInfo_file_identifier
#define rrc_common_PlmnInfo_file_identifier flatbuffers_identifier
#endif
/* deprecated, use rrc_common_PlmnInfo_file_identifier */
#ifndef rrc_common_PlmnInfo_identifier
#define rrc_common_PlmnInfo_identifier flatbuffers_identifier
#endif
#define rrc_common_PlmnInfo_type_hash ((flatbuffers_thash_t)0x66cc0712)
#define rrc_common_PlmnInfo_type_identifier "\x12\x07\xcc\x66"

typedef uint8_t rrc_common_RAT_enum_t;
__flatbuffers_define_integer_type(rrc_common_RAT, rrc_common_RAT_enum_t, 8)
#define rrc_common_RAT_LTE ((rrc_common_RAT_enum_t)UINT8_C(0))
#define rrc_common_RAT_NR ((rrc_common_RAT_enum_t)UINT8_C(1))

static inline const char *rrc_common_RAT_name(rrc_common_RAT_enum_t value)
{
    switch (value) {
    case rrc_common_RAT_LTE: return "LTE";
    case rrc_common_RAT_NR: return "NR";
    default: return "";
    }
}

static inline int rrc_common_RAT_is_known_value(rrc_common_RAT_enum_t value)
{
    switch (value) {
    case rrc_common_RAT_LTE: return 1;
    case rrc_common_RAT_NR: return 1;
    default: return 0;
    }
}



struct rrc_common_Snssai_table { uint8_t unused__; };

static inline size_t rrc_common_Snssai_vec_len(rrc_common_Snssai_vec_t vec)
__flatbuffers_vec_len(vec)
static inline rrc_common_Snssai_table_t rrc_common_Snssai_vec_at(rrc_common_Snssai_vec_t vec, size_t i)
__flatbuffers_offset_vec_at(rrc_common_Snssai_table_t, vec, i, 0)
__flatbuffers_table_as_root(rrc_common_Snssai)

__flatbuffers_define_scalar_field(0, rrc_common_Snssai, sst, flatbuffers_uint8, uint8_t, UINT8_C(0))
__flatbuffers_define_scalar_field(1, rrc_common_Snssai, sd, flatbuffers_uint32, uint32_t, UINT32_C(0))

struct rrc_common_Plmn_table { uint8_t unused__; };

static inline size_t rrc_common_Plmn_vec_len(rrc_common_Plmn_vec_t vec)
__flatbuffers_vec_len(vec)
static inline rrc_common_Plmn_table_t rrc_common_Plmn_vec_at(rrc_common_Plmn_vec_t vec, size_t i)
__flatbuffers_offset_vec_at(rrc_common_Plmn_table_t, vec, i, 0)
__flatbuffers_table_as_root(rrc_common_Plmn)

__flatbuffers_define_scalar_field(0, rrc_common_Plmn, mcc, flatbuffers_uint16, uint16_t, UINT16_C(0))
__flatbuffers_define_scalar_field(1, rrc_common_Plmn, mnc, flatbuffers_uint16, uint16_t, UINT16_C(0))
__flatbuffers_define_scalar_field(2, rrc_common_Plmn, mnc_length, flatbuffers_uint8, uint8_t, UINT8_C(0))
__flatbuffers_define_vector_field(3, rrc_common_Plmn, snssai, rrc_common_Snssai_vec_t, 0)

struct rrc_common_PlmnInfo_table { uint8_t unused__; };

static inline size_t rrc_common_PlmnInfo_vec_len(rrc_common_PlmnInfo_vec_t vec)
__flatbuffers_vec_len(vec)
static inline rrc_common_PlmnInfo_table_t rrc_common_PlmnInfo_vec_at(rrc_common_PlmnInfo_vec_t vec, size_t i)
__flatbuffers_offset_vec_at(rrc_common_PlmnInfo_table_t, vec, i, 0)
__flatbuffers_table_as_root(rrc_common_PlmnInfo)

__flatbuffers_define_table_field(0, rrc_common_PlmnInfo, plmn, rrc_common_Plmn_table_t, 0)
__flatbuffers_define_scalar_field(1, rrc_common_PlmnInfo, tac, flatbuffers_uint32, uint32_t, UINT32_C(0))
__flatbuffers_define_scalar_field(2, rrc_common_PlmnInfo, ranac, flatbuffers_uint8, uint8_t, UINT8_C(0))
__flatbuffers_define_scalar_field(3, rrc_common_PlmnInfo, cellId, flatbuffers_uint64, uint64_t, UINT64_C(0))


#include "flatcc/flatcc_epilogue.h"
#endif /* RRC_COMMON_READER_H */
