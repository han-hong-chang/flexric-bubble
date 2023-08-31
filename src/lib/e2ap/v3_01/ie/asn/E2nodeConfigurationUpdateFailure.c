/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2AP-PDU-Contents"
 * 	found in "../e42ap_v3_01.asn"
 * 	`asn1c -gen-APER -no-gen-OER -fcompound-names -no-gen-example -findirect-choice -fno-include-deps`
 */

#include "E2nodeConfigurationUpdateFailure.h"

asn_TYPE_member_t asn_MBR_E2nodeConfigurationUpdateFailure_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct E2nodeConfigurationUpdateFailure, protocolIEs),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ProtocolIE_Container_2697P34,
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
		"protocolIEs"
		},
};
static const ber_tlv_tag_t asn_DEF_E2nodeConfigurationUpdateFailure_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_E2nodeConfigurationUpdateFailure_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 } /* protocolIEs */
};
asn_SEQUENCE_specifics_t asn_SPC_E2nodeConfigurationUpdateFailure_specs_1 = {
	sizeof(struct E2nodeConfigurationUpdateFailure),
	offsetof(struct E2nodeConfigurationUpdateFailure, _asn_ctx),
	asn_MAP_E2nodeConfigurationUpdateFailure_tag2el_1,
	1,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_E2nodeConfigurationUpdateFailure = {
	"E2nodeConfigurationUpdateFailure",
	"E2nodeConfigurationUpdateFailure",
	&asn_OP_SEQUENCE,
	asn_DEF_E2nodeConfigurationUpdateFailure_tags_1,
	sizeof(asn_DEF_E2nodeConfigurationUpdateFailure_tags_1)
		/sizeof(asn_DEF_E2nodeConfigurationUpdateFailure_tags_1[0]), /* 1 */
	asn_DEF_E2nodeConfigurationUpdateFailure_tags_1,	/* Same as above */
	sizeof(asn_DEF_E2nodeConfigurationUpdateFailure_tags_1)
		/sizeof(asn_DEF_E2nodeConfigurationUpdateFailure_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_E2nodeConfigurationUpdateFailure_1,
	1,	/* Elements count */
	&asn_SPC_E2nodeConfigurationUpdateFailure_specs_1	/* Additional specs */
};

