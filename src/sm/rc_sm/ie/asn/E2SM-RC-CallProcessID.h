/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-RC-IEs"
 * 	found in "e2sm_rc_v1_03.asn"
 * 	`asn1c -gen-PER -no-gen-OER -fcompound-names -no-gen-example -findirect-choice -fno-include-deps`
 */

#ifndef	_E2SM_RC_CallProcessID_H_
#define	_E2SM_RC_CallProcessID_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_CHOICE.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum E2SM_RC_CallProcessID__ric_callProcessID_formats_PR {
	E2SM_RC_CallProcessID__ric_callProcessID_formats_PR_NOTHING,	/* No components present */
	E2SM_RC_CallProcessID__ric_callProcessID_formats_PR_callProcessID_Format1
	/* Extensions may appear below */
	
} E2SM_RC_CallProcessID__ric_callProcessID_formats_PR;

/* Forward declarations */
struct E2SM_RC_CallProcessID_Format1;

/* E2SM-RC-CallProcessID */
typedef struct E2SM_RC_CallProcessID {
	struct E2SM_RC_CallProcessID__ric_callProcessID_formats {
		E2SM_RC_CallProcessID__ric_callProcessID_formats_PR present;
		union E2SM_RC_CallProcessID__ric_callProcessID_formats_u {
			struct E2SM_RC_CallProcessID_Format1	*callProcessID_Format1;
			/*
			 * This type is extensible,
			 * possible extensions are below.
			 */
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} ric_callProcessID_formats;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} E2SM_RC_CallProcessID_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_E2SM_RC_CallProcessID;

#ifdef __cplusplus
}
#endif

#endif	/* _E2SM_RC_CallProcessID_H_ */
#include <asn_internal.h>
