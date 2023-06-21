/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-RC-IEs"
 * 	found in "e2sm_rc_v1_03.asn"
 * 	`asn1c -gen-PER -no-gen-OER -fcompound-names -no-gen-example -findirect-choice -fno-include-deps`
 */

#include "E2SM-RC-RANFunctionDefinition.h"

#include "RANFunctionDefinition-EventTrigger.h"
#include "RANFunctionDefinition-Report.h"
#include "RANFunctionDefinition-Insert.h"
#include "RANFunctionDefinition-Control.h"
#include "RANFunctionDefinition-Policy.h"
static asn_TYPE_member_t asn_MBR_E2SM_RC_RANFunctionDefinition_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_RC_RANFunctionDefinition, ranFunction_Name),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RANfunction_Name,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ranFunction-Name"
		},
	{ ATF_POINTER, 5, offsetof(struct E2SM_RC_RANFunctionDefinition, ranFunctionDefinition_EventTrigger),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RANFunctionDefinition_EventTrigger,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ranFunctionDefinition-EventTrigger"
		},
	{ ATF_POINTER, 4, offsetof(struct E2SM_RC_RANFunctionDefinition, ranFunctionDefinition_Report),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RANFunctionDefinition_Report,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ranFunctionDefinition-Report"
		},
	{ ATF_POINTER, 3, offsetof(struct E2SM_RC_RANFunctionDefinition, ranFunctionDefinition_Insert),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RANFunctionDefinition_Insert,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ranFunctionDefinition-Insert"
		},
	{ ATF_POINTER, 2, offsetof(struct E2SM_RC_RANFunctionDefinition, ranFunctionDefinition_Control),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RANFunctionDefinition_Control,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ranFunctionDefinition-Control"
		},
	{ ATF_POINTER, 1, offsetof(struct E2SM_RC_RANFunctionDefinition, ranFunctionDefinition_Policy),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RANFunctionDefinition_Policy,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ranFunctionDefinition-Policy"
		},
};
static const int asn_MAP_E2SM_RC_RANFunctionDefinition_oms_1[] = { 1, 2, 3, 4, 5 };
static const ber_tlv_tag_t asn_DEF_E2SM_RC_RANFunctionDefinition_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_E2SM_RC_RANFunctionDefinition_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* ranFunction-Name */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* ranFunctionDefinition-EventTrigger */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* ranFunctionDefinition-Report */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* ranFunctionDefinition-Insert */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* ranFunctionDefinition-Control */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 } /* ranFunctionDefinition-Policy */
};
static asn_SEQUENCE_specifics_t asn_SPC_E2SM_RC_RANFunctionDefinition_specs_1 = {
	sizeof(struct E2SM_RC_RANFunctionDefinition),
	offsetof(struct E2SM_RC_RANFunctionDefinition, _asn_ctx),
	asn_MAP_E2SM_RC_RANFunctionDefinition_tag2el_1,
	6,	/* Count of tags in the map */
	asn_MAP_E2SM_RC_RANFunctionDefinition_oms_1,	/* Optional members */
	5, 0,	/* Root/Additions */
	6,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_E2SM_RC_RANFunctionDefinition = {
	"E2SM-RC-RANFunctionDefinition",
	"E2SM-RC-RANFunctionDefinition",
	&asn_OP_SEQUENCE,
	asn_DEF_E2SM_RC_RANFunctionDefinition_tags_1,
	sizeof(asn_DEF_E2SM_RC_RANFunctionDefinition_tags_1)
		/sizeof(asn_DEF_E2SM_RC_RANFunctionDefinition_tags_1[0]), /* 1 */
	asn_DEF_E2SM_RC_RANFunctionDefinition_tags_1,	/* Same as above */
	sizeof(asn_DEF_E2SM_RC_RANFunctionDefinition_tags_1)
		/sizeof(asn_DEF_E2SM_RC_RANFunctionDefinition_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_E2SM_RC_RANFunctionDefinition_1,
	6,	/* Elements count */
	&asn_SPC_E2SM_RC_RANFunctionDefinition_specs_1	/* Additional specs */
};

