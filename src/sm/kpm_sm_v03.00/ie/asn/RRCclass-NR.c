/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-COMMON-IEs"
 * 	found in "e2sm_kpm_v03.00_modified.asn1"
 * 	`asn1c -gen-APER -no-gen-OER -fcompound-names -no-gen-example -findirect-choice -fno-include-deps`
 */

#include "RRCclass-NR.h"

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
asn_per_constraints_t asn_PER_type_RRCclass_NR_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  3,  3,  0,  7 }	/* (0..7,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
static const asn_INTEGER_enum_map_t asn_MAP_RRCclass_NR_value2enum_1[] = {
	{ 0,	8,	"bCCH-BCH" },
	{ 1,	11,	"bCCH-DL-SCH" },
	{ 2,	7,	"dL-CCCH" },
	{ 3,	7,	"dL-DCCH" },
	{ 4,	4,	"pCCH" },
	{ 5,	7,	"uL-CCCH" },
	{ 6,	8,	"uL-CCCH1" },
	{ 7,	7,	"uL-DCCH" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_RRCclass_NR_enum2value_1[] = {
	0,	/* bCCH-BCH(0) */
	1,	/* bCCH-DL-SCH(1) */
	2,	/* dL-CCCH(2) */
	3,	/* dL-DCCH(3) */
	4,	/* pCCH(4) */
	5,	/* uL-CCCH(5) */
	6,	/* uL-CCCH1(6) */
	7	/* uL-DCCH(7) */
	/* This list is extensible */
};
const asn_INTEGER_specifics_t asn_SPC_RRCclass_NR_specs_1 = {
	asn_MAP_RRCclass_NR_value2enum_1,	/* "tag" => N; sorted by tag */
	asn_MAP_RRCclass_NR_enum2value_1,	/* N => "tag"; sorted by N */
	8,	/* Number of elements in the maps */
	9,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_RRCclass_NR_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
asn_TYPE_descriptor_t asn_DEF_RRCclass_NR = {
	"RRCclass-NR",
	"RRCclass-NR",
	&asn_OP_NativeEnumerated,
	asn_DEF_RRCclass_NR_tags_1,
	sizeof(asn_DEF_RRCclass_NR_tags_1)
		/sizeof(asn_DEF_RRCclass_NR_tags_1[0]), /* 1 */
	asn_DEF_RRCclass_NR_tags_1,	/* Same as above */
	sizeof(asn_DEF_RRCclass_NR_tags_1)
		/sizeof(asn_DEF_RRCclass_NR_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		&asn_PER_type_RRCclass_NR_constr_1,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		NativeEnumerated_constraint
	},
	0, 0,	/* Defined elsewhere */
	&asn_SPC_RRCclass_NR_specs_1	/* Additional specs */
};
