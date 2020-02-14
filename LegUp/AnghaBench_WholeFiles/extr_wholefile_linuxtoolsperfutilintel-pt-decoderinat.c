#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_8__ ;
typedef  struct TYPE_15__   TYPE_7__ ;
typedef  struct TYPE_14__   TYPE_6__ ;
typedef  struct TYPE_13__   TYPE_5__ ;
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct TYPE_16__ {int nbytes; size_t* bytes; scalar_t__ got; } ;
struct TYPE_15__ {int nbytes; scalar_t__* bytes; scalar_t__ got; } ;
struct TYPE_14__ {int nbytes; scalar_t__ got; } ;
struct TYPE_13__ {int nbytes; scalar_t__ got; } ;
struct TYPE_12__ {scalar_t__ value; int nbytes; int /*<<< orphan*/ * bytes; } ;
struct TYPE_11__ {int nbytes; } ;
struct TYPE_10__ {size_t* bytes; int nbytes; int /*<<< orphan*/  got; } ;
struct TYPE_9__ {scalar_t__ got; } ;
struct insn {TYPE_8__ modrm; TYPE_7__ opcode; TYPE_6__ displacement; TYPE_5__ sib; TYPE_4__ vex_prefix; TYPE_3__ rex_prefix; TYPE_2__ prefixes; TYPE_1__ immediate; } ;
typedef  size_t insn_byte_t ;
typedef  int insn_attr_t ;

/* Variables and functions */
 int INAT_ESC_MASK ; 
 int INAT_ESC_OFFS ; 
 int INAT_EVEXONLY ; 
 int INAT_FORCE64 ; 
 int INAT_GRP_MASK ; 
 int INAT_GRP_OFFS ; 
 int INAT_IMM_MASK ; 
 int INAT_IMM_OFFS ; 
 int INAT_LGCPFX_MAX ; 
 int INAT_LSTPFX_MAX ; 
 int INAT_MODRM ; 
 int INAT_MOFFSET ; 
 int INAT_PFX_ADDRSZ ; 
 int INAT_PFX_EVEX ; 
 int INAT_PFX_MASK ; 
 int INAT_PFX_OPNDSZ ; 
 int INAT_PFX_REX ; 
 int INAT_PFX_VEX2 ; 
 int INAT_PFX_VEX3 ; 
 int INAT_SCNDIMM ; 
 int INAT_VARIANT ; 
 int INAT_VEXOK ; 
 int INAT_VEXONLY ; 
 scalar_t__ MOV_SREG_OPCODE ; 
 scalar_t__ POP_SS_OPCODE ; 
 size_t X86_EVEX_M (int /*<<< orphan*/ ) ; 
 size_t X86_MODRM_REG (size_t) ; 
 size_t X86_VEX2_M ; 
 size_t X86_VEX3_M (int /*<<< orphan*/ ) ; 
 size_t X86_VEX_M_MAX ; 
 size_t X86_VEX_P (int /*<<< orphan*/ ) ; 
 int*** inat_avx_tables ; 
 int*** inat_escape_tables ; 
 int inat_get_last_prefix_id (size_t) ; 
 int*** inat_group_tables ; 
 int* inat_primary_table ; 
 int /*<<< orphan*/  insn_get_modrm (struct insn*) ; 
 int /*<<< orphan*/  insn_get_prefixes (struct insn*) ; 
 int /*<<< orphan*/  insn_init (struct insn*,void const*,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int inat_is_legacy_prefix(insn_attr_t attr)
{
	attr &= INAT_PFX_MASK;
	return attr && attr <= INAT_LGCPFX_MAX;
}

__attribute__((used)) static inline int inat_is_address_size_prefix(insn_attr_t attr)
{
	return (attr & INAT_PFX_MASK) == INAT_PFX_ADDRSZ;
}

__attribute__((used)) static inline int inat_is_operand_size_prefix(insn_attr_t attr)
{
	return (attr & INAT_PFX_MASK) == INAT_PFX_OPNDSZ;
}

__attribute__((used)) static inline int inat_is_rex_prefix(insn_attr_t attr)
{
	return (attr & INAT_PFX_MASK) == INAT_PFX_REX;
}

__attribute__((used)) static inline int inat_last_prefix_id(insn_attr_t attr)
{
	if ((attr & INAT_PFX_MASK) > INAT_LSTPFX_MAX)
		return 0;
	else
		return attr & INAT_PFX_MASK;
}

__attribute__((used)) static inline int inat_is_vex_prefix(insn_attr_t attr)
{
	attr &= INAT_PFX_MASK;
	return attr == INAT_PFX_VEX2 || attr == INAT_PFX_VEX3 ||
	       attr == INAT_PFX_EVEX;
}

__attribute__((used)) static inline int inat_is_evex_prefix(insn_attr_t attr)
{
	return (attr & INAT_PFX_MASK) == INAT_PFX_EVEX;
}

__attribute__((used)) static inline int inat_is_vex3_prefix(insn_attr_t attr)
{
	return (attr & INAT_PFX_MASK) == INAT_PFX_VEX3;
}

__attribute__((used)) static inline int inat_is_escape(insn_attr_t attr)
{
	return attr & INAT_ESC_MASK;
}

__attribute__((used)) static inline int inat_escape_id(insn_attr_t attr)
{
	return (attr & INAT_ESC_MASK) >> INAT_ESC_OFFS;
}

__attribute__((used)) static inline int inat_is_group(insn_attr_t attr)
{
	return attr & INAT_GRP_MASK;
}

__attribute__((used)) static inline int inat_group_id(insn_attr_t attr)
{
	return (attr & INAT_GRP_MASK) >> INAT_GRP_OFFS;
}

__attribute__((used)) static inline int inat_group_common_attribute(insn_attr_t attr)
{
	return attr & ~INAT_GRP_MASK;
}

__attribute__((used)) static inline int inat_has_immediate(insn_attr_t attr)
{
	return attr & INAT_IMM_MASK;
}

__attribute__((used)) static inline int inat_immediate_size(insn_attr_t attr)
{
	return (attr & INAT_IMM_MASK) >> INAT_IMM_OFFS;
}

__attribute__((used)) static inline int inat_has_modrm(insn_attr_t attr)
{
	return attr & INAT_MODRM;
}

__attribute__((used)) static inline int inat_is_force64(insn_attr_t attr)
{
	return attr & INAT_FORCE64;
}

__attribute__((used)) static inline int inat_has_second_immediate(insn_attr_t attr)
{
	return attr & INAT_SCNDIMM;
}

__attribute__((used)) static inline int inat_has_moffset(insn_attr_t attr)
{
	return attr & INAT_MOFFSET;
}

__attribute__((used)) static inline int inat_has_variant(insn_attr_t attr)
{
	return attr & INAT_VARIANT;
}

__attribute__((used)) static inline int inat_accept_vex(insn_attr_t attr)
{
	return attr & INAT_VEXOK;
}

__attribute__((used)) static inline int inat_must_vex(insn_attr_t attr)
{
	return attr & (INAT_VEXONLY | INAT_EVEXONLY);
}

__attribute__((used)) static inline int inat_must_evex(insn_attr_t attr)
{
	return attr & INAT_EVEXONLY;
}

__attribute__((used)) static inline void insn_get_attribute(struct insn *insn)
{
	insn_get_modrm(insn);
}

__attribute__((used)) static inline void kernel_insn_init(struct insn *insn,
				    const void *kaddr, int buf_len)
{
#ifdef CONFIG_X86_64
	insn_init(insn, kaddr, buf_len, 1);
#else /* CONFIG_X86_32 */
	insn_init(insn, kaddr, buf_len, 0);
#endif
}

__attribute__((used)) static inline int insn_is_avx(struct insn *insn)
{
	if (!insn->prefixes.got)
		insn_get_prefixes(insn);
	return (insn->vex_prefix.value != 0);
}

__attribute__((used)) static inline int insn_is_evex(struct insn *insn)
{
	if (!insn->prefixes.got)
		insn_get_prefixes(insn);
	return (insn->vex_prefix.nbytes == 4);
}

__attribute__((used)) static inline int insn_complete(struct insn *insn)
{
	return insn->opcode.got && insn->modrm.got && insn->sib.got &&
		insn->displacement.got && insn->immediate.got;
}

__attribute__((used)) static inline insn_byte_t insn_vex_m_bits(struct insn *insn)
{
	if (insn->vex_prefix.nbytes == 2)	/* 2 bytes VEX */
		return X86_VEX2_M;
	else if (insn->vex_prefix.nbytes == 3)	/* 3 bytes VEX */
		return X86_VEX3_M(insn->vex_prefix.bytes[1]);
	else					/* EVEX */
		return X86_EVEX_M(insn->vex_prefix.bytes[1]);
}

__attribute__((used)) static inline insn_byte_t insn_vex_p_bits(struct insn *insn)
{
	if (insn->vex_prefix.nbytes == 2)	/* 2 bytes VEX */
		return X86_VEX_P(insn->vex_prefix.bytes[1]);
	else
		return X86_VEX_P(insn->vex_prefix.bytes[2]);
}

__attribute__((used)) static inline int insn_last_prefix_id(struct insn *insn)
{
	if (insn_is_avx(insn))
		return insn_vex_p_bits(insn);	/* VEX_p is a SIMD prefix id */

	if (insn->prefixes.bytes[3])
		return inat_get_last_prefix_id(insn->prefixes.bytes[3]);

	return 0;
}

__attribute__((used)) static inline int insn_offset_rex_prefix(struct insn *insn)
{
	return insn->prefixes.nbytes;
}

__attribute__((used)) static inline int insn_offset_vex_prefix(struct insn *insn)
{
	return insn_offset_rex_prefix(insn) + insn->rex_prefix.nbytes;
}

__attribute__((used)) static inline int insn_offset_opcode(struct insn *insn)
{
	return insn_offset_vex_prefix(insn) + insn->vex_prefix.nbytes;
}

__attribute__((used)) static inline int insn_offset_modrm(struct insn *insn)
{
	return insn_offset_opcode(insn) + insn->opcode.nbytes;
}

__attribute__((used)) static inline int insn_offset_sib(struct insn *insn)
{
	return insn_offset_modrm(insn) + insn->modrm.nbytes;
}

__attribute__((used)) static inline int insn_offset_displacement(struct insn *insn)
{
	return insn_offset_sib(insn) + insn->sib.nbytes;
}

__attribute__((used)) static inline int insn_offset_immediate(struct insn *insn)
{
	return insn_offset_displacement(insn) + insn->displacement.nbytes;
}

__attribute__((used)) static inline int insn_masking_exception(struct insn *insn)
{
	return insn->opcode.bytes[0] == POP_SS_OPCODE ||
		(insn->opcode.bytes[0] == MOV_SREG_OPCODE &&
		 X86_MODRM_REG(insn->modrm.bytes[0]) == 2);
}

insn_attr_t inat_get_opcode_attribute(insn_byte_t opcode)
{
	return inat_primary_table[opcode];
}

int inat_get_last_prefix_id(insn_byte_t last_pfx)
{
	insn_attr_t lpfx_attr;

	lpfx_attr = inat_get_opcode_attribute(last_pfx);
	return inat_last_prefix_id(lpfx_attr);
}

insn_attr_t inat_get_escape_attribute(insn_byte_t opcode, int lpfx_id,
				      insn_attr_t esc_attr)
{
	const insn_attr_t *table;
	int n;

	n = inat_escape_id(esc_attr);

	table = inat_escape_tables[n][0];
	if (!table)
		return 0;
	if (inat_has_variant(table[opcode]) && lpfx_id) {
		table = inat_escape_tables[n][lpfx_id];
		if (!table)
			return 0;
	}
	return table[opcode];
}

insn_attr_t inat_get_group_attribute(insn_byte_t modrm, int lpfx_id,
				     insn_attr_t grp_attr)
{
	const insn_attr_t *table;
	int n;

	n = inat_group_id(grp_attr);

	table = inat_group_tables[n][0];
	if (!table)
		return inat_group_common_attribute(grp_attr);
	if (inat_has_variant(table[X86_MODRM_REG(modrm)]) && lpfx_id) {
		table = inat_group_tables[n][lpfx_id];
		if (!table)
			return inat_group_common_attribute(grp_attr);
	}
	return table[X86_MODRM_REG(modrm)] |
	       inat_group_common_attribute(grp_attr);
}

insn_attr_t inat_get_avx_attribute(insn_byte_t opcode, insn_byte_t vex_m,
				   insn_byte_t vex_p)
{
	const insn_attr_t *table;
	if (vex_m > X86_VEX_M_MAX || vex_p > INAT_LSTPFX_MAX)
		return 0;
	/* At first, this checks the master table */
	table = inat_avx_tables[vex_m][0];
	if (!table)
		return 0;
	if (!inat_is_group(table[opcode]) && vex_p) {
		/* If this is not a group, get attribute directly */
		table = inat_avx_tables[vex_m][vex_p];
		if (!table)
			return 0;
	}
	return table[opcode];
}

