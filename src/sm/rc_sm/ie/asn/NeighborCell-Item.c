/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-RC-IEs"
 * 	found in "e2sm_rc_v1_03.asn"
 * 	`asn1c -gen-PER -no-gen-OER -fcompound-names -no-gen-example -findirect-choice -fno-include-deps`
 */

#include "NeighborCell-Item.h"

#include "NeighborCell-Item-Choice-NR.h"
#include "NeighborCell-Item-Choice-E-UTRA.h"
asn_per_constraints_t asn_PER_type_NeighborCell_Item_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  1,  1,  0,  1 }	/* (0..1,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
asn_TYPE_member_t asn_MBR_NeighborCell_Item_1[] = {
	{ ATF_POINTER, 0, offsetof(struct NeighborCell_Item, choice.ranType_Choice_NR),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NeighborCell_Item_Choice_NR,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ranType-Choice-NR"
		},
	{ ATF_POINTER, 0, offsetof(struct NeighborCell_Item, choice.ranType_Choice_EUTRA),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NeighborCell_Item_Choice_E_UTRA,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ranType-Choice-EUTRA"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_NeighborCell_Item_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* ranType-Choice-NR */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* ranType-Choice-EUTRA */
};
asn_CHOICE_specifics_t asn_SPC_NeighborCell_Item_specs_1 = {
	sizeof(struct NeighborCell_Item),
	offsetof(struct NeighborCell_Item, _asn_ctx),
	offsetof(struct NeighborCell_Item, present),
	sizeof(((struct NeighborCell_Item *)0)->present),
	asn_MAP_NeighborCell_Item_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0,
	2	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_NeighborCell_Item = {
	"NeighborCell-Item",
	"NeighborCell-Item",
	&asn_OP_CHOICE,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	{ 0, &asn_PER_type_NeighborCell_Item_constr_1, CHOICE_constraint },
	asn_MBR_NeighborCell_Item_1,
	2,	/* Elements count */
	&asn_SPC_NeighborCell_Item_specs_1	/* Additional specs */
};

