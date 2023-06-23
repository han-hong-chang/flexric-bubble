/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2AP-IEs"
 * 	found in "e2ap-v01.01.asn1"
 * 	`asn1c -gen-APER -no-gen-BER -no-gen-JER -no-gen-OER -gen-UPER -fcompound-names -no-gen-example -findirect-choice -fno-include-deps`
 */

#ifndef	_E2nodeComponentID_H_
#define	_E2nodeComponentID_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum E2nodeComponentID_PR {
	E2nodeComponentID_PR_NOTHING,	/* No components present */
	E2nodeComponentID_PR_e2nodeComponentTypeGNB_CU_UP,
	E2nodeComponentID_PR_e2nodeComponentTypeGNB_DU
	/* Extensions may appear below */
	
} E2nodeComponentID_PR;

/* Forward declarations */
struct E2nodeComponentGNB_CU_UP_ID;
struct E2nodeComponentGNB_DU_ID;

/* E2nodeComponentID */
typedef struct E2nodeComponentID {
	E2nodeComponentID_PR present;
	union E2nodeComponentID_u {
		struct E2nodeComponentGNB_CU_UP_ID	*e2nodeComponentTypeGNB_CU_UP;
		struct E2nodeComponentGNB_DU_ID	*e2nodeComponentTypeGNB_DU;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} E2nodeComponentID_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_E2nodeComponentID;
extern asn_CHOICE_specifics_t asn_SPC_E2nodeComponentID_specs_1;
extern asn_TYPE_member_t asn_MBR_E2nodeComponentID_1[2];
extern asn_per_constraints_t asn_PER_type_E2nodeComponentID_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _E2nodeComponentID_H_ */
#include <asn_internal.h>
