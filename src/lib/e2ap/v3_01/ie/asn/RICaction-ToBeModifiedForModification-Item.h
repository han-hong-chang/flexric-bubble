/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2AP-PDU-Contents"
 * 	found in "../e42ap_v3_01.asn"
 * 	`asn1c -gen-APER -no-gen-OER -fcompound-names -no-gen-example -findirect-choice -fno-include-deps`
 */

#ifndef	_RICaction_ToBeModifiedForModification_Item_H_
#define	_RICaction_ToBeModifiedForModification_Item_H_


#include <asn_application.h>

/* Including external dependencies */
#include "RICactionID.h"
#include "RICactionDefinition.h"
#include "RICactionExecutionOrder.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct RICsubsequentAction;

/* RICaction-ToBeModifiedForModification-Item */
typedef struct RICaction_ToBeModifiedForModification_Item {
	RICactionID_t	 ricActionID;
	RICactionDefinition_t	*ricActionDefinition;	/* OPTIONAL */
	RICactionExecutionOrder_t	*ricActionExecutionOrder;	/* OPTIONAL */
	struct RICsubsequentAction	*ricSubsequentAction;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RICaction_ToBeModifiedForModification_Item_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RICaction_ToBeModifiedForModification_Item;
extern asn_SEQUENCE_specifics_t asn_SPC_RICaction_ToBeModifiedForModification_Item_specs_1;
extern asn_TYPE_member_t asn_MBR_RICaction_ToBeModifiedForModification_Item_1[4];

#ifdef __cplusplus
}
#endif

#endif	/* _RICaction_ToBeModifiedForModification_Item_H_ */
#include <asn_internal.h>
