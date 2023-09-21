/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-COMMON-IEs"
 * 	found in "e2sm_kpm_v03.00_modified.asn1"
 * 	`asn1c -gen-APER -no-gen-OER -fcompound-names -no-gen-example -findirect-choice -fno-include-deps`
 */

#ifndef	_GlobalGNB_ID_H_
#define	_GlobalGNB_ID_H_


#include <asn_application.h>

/* Including external dependencies */
#include "PLMNIdentity.h"
#include "GNB-ID.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* GlobalGNB-ID */
typedef struct GlobalGNB_ID {
	PLMNIdentity_t	 pLMNIdentity;
	GNB_ID_t	 gNB_ID;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} GlobalGNB_ID_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_GlobalGNB_ID;
extern asn_SEQUENCE_specifics_t asn_SPC_GlobalGNB_ID_specs_1;
extern asn_TYPE_member_t asn_MBR_GlobalGNB_ID_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _GlobalGNB_ID_H_ */
#include <asn_internal.h>