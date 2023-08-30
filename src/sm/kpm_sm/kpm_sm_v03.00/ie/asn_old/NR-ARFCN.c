/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-COMMON-IEs"
 * 	found in "e2sm_kpm_v03.00_modified.asn1"
 * 	`asn1c -gen-PER -no-gen-OER -fcompound-names -no-gen-example -findirect-choice -fno-include-deps -D asn`
 */

#include "NR-ARFCN.h"

static int
memb_nRARFCN_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 3279165)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_memb_nRARFCN_constr_2 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 22, -1,  0,  3279165 }	/* (0..3279165) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
asn_TYPE_member_t asn_MBR_NR_ARFCN_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct NR_ARFCN, nRARFCN),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ 0, &asn_PER_memb_nRARFCN_constr_2,  memb_nRARFCN_constraint_1 },
		0, 0, /* No default value */
		"nRARFCN"
		},
};
static const ber_tlv_tag_t asn_DEF_NR_ARFCN_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_NR_ARFCN_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 } /* nRARFCN */
};
asn_SEQUENCE_specifics_t asn_SPC_NR_ARFCN_specs_1 = {
	sizeof(struct NR_ARFCN),
	offsetof(struct NR_ARFCN, _asn_ctx),
	asn_MAP_NR_ARFCN_tag2el_1,
	1,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_NR_ARFCN = {
	"NR-ARFCN",
	"NR-ARFCN",
	&asn_OP_SEQUENCE,
	asn_DEF_NR_ARFCN_tags_1,
	sizeof(asn_DEF_NR_ARFCN_tags_1)
		/sizeof(asn_DEF_NR_ARFCN_tags_1[0]), /* 1 */
	asn_DEF_NR_ARFCN_tags_1,	/* Same as above */
	sizeof(asn_DEF_NR_ARFCN_tags_1)
		/sizeof(asn_DEF_NR_ARFCN_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_NR_ARFCN_1,
	1,	/* Elements count */
	&asn_SPC_NR_ARFCN_specs_1	/* Additional specs */
};

