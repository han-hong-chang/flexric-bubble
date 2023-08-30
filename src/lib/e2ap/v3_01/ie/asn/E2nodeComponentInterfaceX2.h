/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2AP-IEs"
 * 	found in "e42ap_v3_01.asn"
 * 	`asn1c -gen-APER -no-gen-OER -fcompound-names -no-gen-example -findirect-choice -fno-include-deps`
 */

#ifndef	_E2nodeComponentInterfaceX2_H_
#define	_E2nodeComponentInterfaceX2_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct GlobalENB_ID;
struct GlobalenGNB_ID;

/* E2nodeComponentInterfaceX2 */
typedef struct E2nodeComponentInterfaceX2 {
	struct GlobalENB_ID	*global_eNB_ID;	/* OPTIONAL */
	struct GlobalenGNB_ID	*global_en_gNB_ID;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} E2nodeComponentInterfaceX2_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_E2nodeComponentInterfaceX2;
extern asn_SEQUENCE_specifics_t asn_SPC_E2nodeComponentInterfaceX2_specs_1;
extern asn_TYPE_member_t asn_MBR_E2nodeComponentInterfaceX2_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _E2nodeComponentInterfaceX2_H_ */
#include <asn_internal.h>
