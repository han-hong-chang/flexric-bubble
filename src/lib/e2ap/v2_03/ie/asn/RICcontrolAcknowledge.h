/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2AP-PDU-Contents"
 * 	found in "../e42ap_v2_03.asn"
 * 	`asn1c -gen-APER -no-gen-OER -fcompound-names -no-gen-example -findirect-choice -fno-include-deps`
 */

#ifndef	_RICcontrolAcknowledge_H_
#define	_RICcontrolAcknowledge_H_


#include <asn_application.h>

/* Including external dependencies */
#include "ProtocolIE-Container.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* RICcontrolAcknowledge */
typedef struct RICcontrolAcknowledge {
	ProtocolIE_Container_2162P12_t	 protocolIEs;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RICcontrolAcknowledge_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RICcontrolAcknowledge;
extern asn_SEQUENCE_specifics_t asn_SPC_RICcontrolAcknowledge_specs_1;
extern asn_TYPE_member_t asn_MBR_RICcontrolAcknowledge_1[1];

#ifdef __cplusplus
}
#endif

#endif	/* _RICcontrolAcknowledge_H_ */
#include <asn_internal.h>
