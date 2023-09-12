/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-KPM-IEs"
 * 	found in "e2sm_kpm_v02.03_modified.asn1"
 * 	`asn1c -gen-APER -no-gen-OER -fcompound-names -no-gen-example -findirect-choice -fno-include-deps`
 */

#ifndef	_E2SM_KPM_ActionDefinition_Format1_H_
#define	_E2SM_KPM_ActionDefinition_Format1_H_


#include <asn_application.h>

/* Including external dependencies */
#include "MeasurementInfoList.h"
#include "GranularityPeriod.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct CGI;
struct DistMeasurementBinRangeList;

/* E2SM-KPM-ActionDefinition-Format1 */
typedef struct E2SM_KPM_ActionDefinition_Format1 {
	MeasurementInfoList_t	 measInfoList;
	GranularityPeriod_t	 granulPeriod;
	struct CGI	*cellGlobalID;	/* OPTIONAL */
	struct DistMeasurementBinRangeList	*distMeasBinRangeInfo;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} E2SM_KPM_ActionDefinition_Format1_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_E2SM_KPM_ActionDefinition_Format1;
extern asn_SEQUENCE_specifics_t asn_SPC_E2SM_KPM_ActionDefinition_Format1_specs_1;
extern asn_TYPE_member_t asn_MBR_E2SM_KPM_ActionDefinition_Format1_1[4];

#ifdef __cplusplus
}
#endif

#endif	/* _E2SM_KPM_ActionDefinition_Format1_H_ */
#include <asn_internal.h>
