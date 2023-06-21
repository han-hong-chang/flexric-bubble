/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-RC-IEs"
 * 	found in "e2sm_rc_v1_03.asn"
 * 	`asn1c -gen-PER -no-gen-OER -fcompound-names -no-gen-example -findirect-choice -fno-include-deps`
 */

#ifndef	_RRC_State_H_
#define	_RRC_State_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum RRC_State {
	RRC_State_rrc_connected	= 0,
	RRC_State_rrc_inactive	= 1,
	RRC_State_rrc_idle	= 2,
	RRC_State_any	= 3
	/*
	 * Enumeration is extensible
	 */
} e_RRC_State;

/* RRC-State */
typedef long	 RRC_State_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_RRC_State_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_RRC_State;
extern const asn_INTEGER_specifics_t asn_SPC_RRC_State_specs_1;
asn_struct_free_f RRC_State_free;
asn_struct_print_f RRC_State_print;
asn_constr_check_f RRC_State_constraint;
ber_type_decoder_f RRC_State_decode_ber;
der_type_encoder_f RRC_State_encode_der;
xer_type_decoder_f RRC_State_decode_xer;
xer_type_encoder_f RRC_State_encode_xer;
per_type_decoder_f RRC_State_decode_uper;
per_type_encoder_f RRC_State_encode_uper;
per_type_decoder_f RRC_State_decode_aper;
per_type_encoder_f RRC_State_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _RRC_State_H_ */
#include <asn_internal.h>
