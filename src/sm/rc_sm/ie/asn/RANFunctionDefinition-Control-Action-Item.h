/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-RC-IEs"
 * 	found in "e2sm_rc_v1_03.asn"
 * 	`asn1c -gen-PER -no-gen-OER -fcompound-names -no-gen-example -findirect-choice -fno-include-deps`
 */

#ifndef	_RANFunctionDefinition_Control_Action_Item_H_
#define	_RANFunctionDefinition_Control_Action_Item_H_


#include <asn_application.h>

/* Including external dependencies */
#include "RIC-ControlAction-ID.h"
#include "RIC-ControlAction-Name.h"
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ControlAction_RANParameter_Item;

/* RANFunctionDefinition-Control-Action-Item */
typedef struct RANFunctionDefinition_Control_Action_Item {
	RIC_ControlAction_ID_t	 ric_ControlAction_ID;
	RIC_ControlAction_Name_t	 ric_ControlAction_Name;
	struct RANFunctionDefinition_Control_Action_Item__ran_ControlActionParameters_List {
		A_SEQUENCE_OF(struct ControlAction_RANParameter_Item) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *ran_ControlActionParameters_List;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RANFunctionDefinition_Control_Action_Item_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RANFunctionDefinition_Control_Action_Item;
extern asn_SEQUENCE_specifics_t asn_SPC_RANFunctionDefinition_Control_Action_Item_specs_1;
extern asn_TYPE_member_t asn_MBR_RANFunctionDefinition_Control_Action_Item_1[3];

#ifdef __cplusplus
}
#endif

#endif	/* _RANFunctionDefinition_Control_Action_Item_H_ */
#include <asn_internal.h>
