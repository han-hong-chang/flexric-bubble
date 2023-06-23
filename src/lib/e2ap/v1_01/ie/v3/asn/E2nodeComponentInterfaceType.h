/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2AP-IEs"
 * 	found in "e2ap_v3_01.asn"
 * 	`asn1c -fcompound-names`
 */

#ifndef	_E2nodeComponentInterfaceType_H_
#define	_E2nodeComponentInterfaceType_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum E2nodeComponentInterfaceType {
	E2nodeComponentInterfaceType_ng	= 0,
	E2nodeComponentInterfaceType_xn	= 1,
	E2nodeComponentInterfaceType_e1	= 2,
	E2nodeComponentInterfaceType_f1	= 3,
	E2nodeComponentInterfaceType_w1	= 4,
	E2nodeComponentInterfaceType_s1	= 5,
	E2nodeComponentInterfaceType_x2	= 6
	/*
	 * Enumeration is extensible
	 */
} e_E2nodeComponentInterfaceType;

/* E2nodeComponentInterfaceType */
typedef long	 E2nodeComponentInterfaceType_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_E2nodeComponentInterfaceType_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_E2nodeComponentInterfaceType;
extern const asn_INTEGER_specifics_t asn_SPC_E2nodeComponentInterfaceType_specs_1;
asn_struct_free_f E2nodeComponentInterfaceType_free;
asn_struct_print_f E2nodeComponentInterfaceType_print;
asn_constr_check_f E2nodeComponentInterfaceType_constraint;
ber_type_decoder_f E2nodeComponentInterfaceType_decode_ber;
der_type_encoder_f E2nodeComponentInterfaceType_encode_der;
xer_type_decoder_f E2nodeComponentInterfaceType_decode_xer;
xer_type_encoder_f E2nodeComponentInterfaceType_encode_xer;
oer_type_decoder_f E2nodeComponentInterfaceType_decode_oer;
oer_type_encoder_f E2nodeComponentInterfaceType_encode_oer;
per_type_decoder_f E2nodeComponentInterfaceType_decode_uper;
per_type_encoder_f E2nodeComponentInterfaceType_encode_uper;
per_type_decoder_f E2nodeComponentInterfaceType_decode_aper;
per_type_encoder_f E2nodeComponentInterfaceType_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _E2nodeComponentInterfaceType_H_ */
#include <asn_internal.h>
