/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-RC-IEs"
 * 	found in "e2sm_rc_v1_03.asn"
 * 	`asn1c -gen-PER -no-gen-OER -fcompound-names -no-gen-example -findirect-choice -fno-include-deps`
 */

#ifndef	_RANFunctionDefinition_Policy_Item_H_
#define	_RANFunctionDefinition_Policy_Item_H_


#include <asn_application.h>

/* Including external dependencies */
#include "RIC-Style-Type.h"
#include "RIC-Style-Name.h"
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct RANFunctionDefinition_Policy_Action_Item;

/* RANFunctionDefinition-Policy-Item */
typedef struct RANFunctionDefinition_Policy_Item {
	RIC_Style_Type_t	 ric_PolicyStyle_Type;
	RIC_Style_Name_t	 ric_PolicyStyle_Name;
	RIC_Style_Type_t	 ric_SupportedEventTriggerStyle_Type;
	struct RANFunctionDefinition_Policy_Item__ric_PolicyAction_List {
		A_SEQUENCE_OF(struct RANFunctionDefinition_Policy_Action_Item) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *ric_PolicyAction_List;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RANFunctionDefinition_Policy_Item_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RANFunctionDefinition_Policy_Item;
extern asn_SEQUENCE_specifics_t asn_SPC_RANFunctionDefinition_Policy_Item_specs_1;
extern asn_TYPE_member_t asn_MBR_RANFunctionDefinition_Policy_Item_1[4];

#ifdef __cplusplus
}
#endif

#endif	/* _RANFunctionDefinition_Policy_Item_H_ */
#include <asn_internal.h>
