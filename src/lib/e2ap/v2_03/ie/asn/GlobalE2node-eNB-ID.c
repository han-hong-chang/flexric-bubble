/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2AP-IEs"
 * 	found in "../e42ap_v2_03.asn"
 * 	`asn1c -gen-APER -no-gen-OER -fcompound-names -no-gen-example -findirect-choice -fno-include-deps`
 */

#include "GlobalE2node-eNB-ID.h"

asn_TYPE_member_t asn_MBR_GlobalE2node_eNB_ID_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct GlobalE2node_eNB_ID, global_eNB_ID),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_GlobalENB_ID,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"global-eNB-ID"
		},
};
static const ber_tlv_tag_t asn_DEF_GlobalE2node_eNB_ID_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_GlobalE2node_eNB_ID_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 } /* global-eNB-ID */
};
asn_SEQUENCE_specifics_t asn_SPC_GlobalE2node_eNB_ID_specs_1 = {
	sizeof(struct GlobalE2node_eNB_ID),
	offsetof(struct GlobalE2node_eNB_ID, _asn_ctx),
	asn_MAP_GlobalE2node_eNB_ID_tag2el_1,
	1,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_GlobalE2node_eNB_ID = {
	"GlobalE2node-eNB-ID",
	"GlobalE2node-eNB-ID",
	&asn_OP_SEQUENCE,
	asn_DEF_GlobalE2node_eNB_ID_tags_1,
	sizeof(asn_DEF_GlobalE2node_eNB_ID_tags_1)
		/sizeof(asn_DEF_GlobalE2node_eNB_ID_tags_1[0]), /* 1 */
	asn_DEF_GlobalE2node_eNB_ID_tags_1,	/* Same as above */
	sizeof(asn_DEF_GlobalE2node_eNB_ID_tags_1)
		/sizeof(asn_DEF_GlobalE2node_eNB_ID_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_GlobalE2node_eNB_ID_1,
	1,	/* Elements count */
	&asn_SPC_GlobalE2node_eNB_ID_specs_1	/* Additional specs */
};

