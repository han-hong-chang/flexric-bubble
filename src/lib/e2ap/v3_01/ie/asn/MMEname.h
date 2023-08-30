/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2AP-IEs"
 * 	found in "e42ap_v3_01.asn"
 * 	`asn1c -gen-APER -no-gen-OER -fcompound-names -no-gen-example -findirect-choice -fno-include-deps`
 */

#ifndef	_MMEname_H_
#define	_MMEname_H_


#include <asn_application.h>

/* Including external dependencies */
#include <PrintableString.h>

#ifdef __cplusplus
extern "C" {
#endif

/* MMEname */
typedef PrintableString_t	 MMEname_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_MMEname_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_MMEname;
asn_struct_free_f MMEname_free;
asn_struct_print_f MMEname_print;
asn_constr_check_f MMEname_constraint;
ber_type_decoder_f MMEname_decode_ber;
der_type_encoder_f MMEname_encode_der;
xer_type_decoder_f MMEname_decode_xer;
xer_type_encoder_f MMEname_encode_xer;
jer_type_encoder_f MMEname_encode_jer;
per_type_decoder_f MMEname_decode_uper;
per_type_encoder_f MMEname_encode_uper;
per_type_decoder_f MMEname_decode_aper;
per_type_encoder_f MMEname_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _MMEname_H_ */
#include <asn_internal.h>
