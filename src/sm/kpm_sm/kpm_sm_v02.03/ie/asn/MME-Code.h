/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-COMMON-IEs"
 * 	found in "e2sm_kpm_v02.03_modified.asn1"
 * 	`asn1c -gen-APER -no-gen-OER -fcompound-names -no-gen-example -findirect-choice -fno-include-deps`
 */

#ifndef	_MME_Code_H_
#define	_MME_Code_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OCTET_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* MME-Code */
typedef OCTET_STRING_t	 MME_Code_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_MME_Code_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_MME_Code;
asn_struct_free_f MME_Code_free;
asn_struct_print_f MME_Code_print;
asn_constr_check_f MME_Code_constraint;
ber_type_decoder_f MME_Code_decode_ber;
der_type_encoder_f MME_Code_encode_der;
xer_type_decoder_f MME_Code_decode_xer;
xer_type_encoder_f MME_Code_encode_xer;
jer_type_encoder_f MME_Code_encode_jer;
per_type_decoder_f MME_Code_decode_uper;
per_type_encoder_f MME_Code_encode_uper;
per_type_decoder_f MME_Code_decode_aper;
per_type_encoder_f MME_Code_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _MME_Code_H_ */
#include <asn_internal.h>
