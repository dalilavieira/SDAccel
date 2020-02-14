#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_7__ ;
typedef  struct TYPE_13__   TYPE_6__ ;
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uprobe_opcode_t ;
struct TYPE_10__ {int /*<<< orphan*/  rt; } ;
struct TYPE_9__ {int /*<<< orphan*/  func; } ;
struct TYPE_8__ {int opcode; int /*<<< orphan*/  rt; } ;
union mips_instruction {TYPE_3__ u_format; TYPE_2__ r_format; TYPE_1__ i_format; scalar_t__ word; } ;
struct TYPE_12__ {scalar_t__ saved_trap_nr; } ;
struct uprobe_task {unsigned long xol_vaddr; int /*<<< orphan*/  vaddr; TYPE_5__ autask; } ;
struct TYPE_13__ {scalar_t__ trap_nr; } ;
struct task_struct {TYPE_6__ thread; } ;
struct pt_regs {unsigned long cp0_epc; unsigned long* regs; } ;
struct notifier_block {int dummy; } ;
struct mm_struct {int dummy; } ;
struct die_args {struct pt_regs* regs; } ;
struct arch_uprobe {unsigned long resume_epc; scalar_t__* insn; scalar_t__* ixol; } ;
struct TYPE_11__ {scalar_t__ trap_nr; } ;
struct TYPE_14__ {struct uprobe_task* utask; TYPE_4__ thread; } ;

/* Variables and functions */
#define  DIE_UPROBE 166 
#define  DIE_UPROBE_XOL 165 
 int EINVAL ; 
 int NOTIFY_DONE ; 
 int NOTIFY_STOP ; 
 scalar_t__ UPROBE_BRK_UPROBE_XOL ; 
 scalar_t__ UPROBE_TRAP_NR ; 
 scalar_t__ WARN_ON (int) ; 
 int /*<<< orphan*/  __compute_return_epc_for_insn (struct pt_regs*,union mips_instruction) ; 
 scalar_t__ __insn_is_compact_branch (union mips_instruction) ; 
#define  bcond_op 164 
#define  beq_op 163 
#define  beql_op 162 
#define  bgez_op 161 
#define  bgezal_op 160 
#define  bgezall_op 159 
#define  bgezl_op 158 
#define  bgtz_op 157 
#define  bgtzl_op 156 
#define  blez_op 155 
#define  blezl_op 154 
#define  bltz_op 153 
#define  bltzal_op 152 
#define  bltzall_op 151 
#define  bltzl_op 150 
#define  bne_op 149 
#define  bnel_op 148 
#define  bposge32_op 147 
#define  break_op 146 
#define  cop1_op 145 
 TYPE_7__* current ; 
 int /*<<< orphan*/  instruction_pointer_set (struct pt_regs*,int /*<<< orphan*/ ) ; 
#define  j_op 144 
#define  jal_op 143 
#define  jalr_op 142 
#define  jr_op 141 
 int /*<<< orphan*/  pr_notice (char*) ; 
#define  spec_op 140 
#define  teq_op 139 
#define  teqi_op 138 
#define  tge_op 137 
#define  tgei_op 136 
#define  tgeiu_op 135 
#define  tgeu_op 134 
#define  tlt_op 133 
#define  tlti_op 132 
#define  tltiu_op 131 
#define  tltu_op 130 
#define  tne_op 129 
#define  tnei_op 128 
 int /*<<< orphan*/  uprobe_post_sstep_notifier (struct pt_regs*) ; 
 int /*<<< orphan*/  uprobe_pre_sstep_notifier (struct pt_regs*) ; 
 int /*<<< orphan*/  user_mode (struct pt_regs*) ; 

__attribute__((used)) static inline int __insn_has_delay_slot(const union mips_instruction insn)
{
	switch (insn.i_format.opcode) {
	/*
	 * jr and jalr are in r_format format.
	 */
	case spec_op:
		switch (insn.r_format.func) {
		case jalr_op:
		case jr_op:
			return 1;
		}
		break;

	/*
	 * This group contains:
	 * bltz_op, bgez_op, bltzl_op, bgezl_op,
	 * bltzal_op, bgezal_op, bltzall_op, bgezall_op.
	 */
	case bcond_op:
		switch (insn.i_format.rt) {
		case bltz_op:
		case bltzl_op:
		case bgez_op:
		case bgezl_op:
		case bltzal_op:
		case bltzall_op:
		case bgezal_op:
		case bgezall_op:
		case bposge32_op:
			return 1;
		}
		break;

	/*
	 * These are unconditional and in j_format.
	 */
	case jal_op:
	case j_op:
	case beq_op:
	case beql_op:
	case bne_op:
	case bnel_op:
	case blez_op: /* not really i_format */
	case blezl_op:
	case bgtz_op:
	case bgtzl_op:
		return 1;

	/*
	 * And now the FPA/cp1 branch instructions.
	 */
	case cop1_op:
#ifdef CONFIG_CPU_CAVIUM_OCTEON
	case lwc2_op: /* This is bbit0 on Octeon */
	case ldc2_op: /* This is bbit032 on Octeon */
	case swc2_op: /* This is bbit1 on Octeon */
	case sdc2_op: /* This is bbit132 on Octeon */
#endif
		return 1;
	}

	return 0;
}

__attribute__((used)) static inline int insn_has_delay_slot(const union mips_instruction insn)
{
	return __insn_has_delay_slot(insn);
}

int arch_uprobe_analyze_insn(struct arch_uprobe *aup,
	struct mm_struct *mm, unsigned long addr)
{
	union mips_instruction inst;

	/*
	 * For the time being this also blocks attempts to use uprobes with
	 * MIPS16 and microMIPS.
	 */
	if (addr & 0x03)
		return -EINVAL;

	inst.word = aup->insn[0];

	if (__insn_is_compact_branch(inst)) {
		pr_notice("Uprobes for compact branches are not supported\n");
		return -EINVAL;
	}

	aup->ixol[0] = aup->insn[insn_has_delay_slot(inst)];
	aup->ixol[1] = UPROBE_BRK_UPROBE_XOL;		/* NOP  */

	return 0;
}

bool is_trap_insn(uprobe_opcode_t *insn)
{
	union mips_instruction inst;

	inst.word = *insn;

	switch (inst.i_format.opcode) {
	case spec_op:
		switch (inst.r_format.func) {
		case break_op:
		case teq_op:
		case tge_op:
		case tgeu_op:
		case tlt_op:
		case tltu_op:
		case tne_op:
			return 1;
		}
		break;

	case bcond_op:	/* Yes, really ...  */
		switch (inst.u_format.rt) {
		case teqi_op:
		case tgei_op:
		case tgeiu_op:
		case tlti_op:
		case tltiu_op:
		case tnei_op:
			return 1;
		}
		break;
	}

	return 0;
}

int arch_uprobe_pre_xol(struct arch_uprobe *aup, struct pt_regs *regs)
{
	struct uprobe_task *utask = current->utask;

	/*
	 * Now find the EPC where to resume after the breakpoint has been
	 * dealt with.  This may require emulation of a branch.
	 */
	aup->resume_epc = regs->cp0_epc + 4;
	if (insn_has_delay_slot((union mips_instruction) aup->insn[0])) {
		unsigned long epc;

		epc = regs->cp0_epc;
		__compute_return_epc_for_insn(regs,
			(union mips_instruction) aup->insn[0]);
		aup->resume_epc = regs->cp0_epc;
	}
	utask->autask.saved_trap_nr = current->thread.trap_nr;
	current->thread.trap_nr = UPROBE_TRAP_NR;
	regs->cp0_epc = current->utask->xol_vaddr;

	return 0;
}

int arch_uprobe_post_xol(struct arch_uprobe *aup, struct pt_regs *regs)
{
	struct uprobe_task *utask = current->utask;

	current->thread.trap_nr = utask->autask.saved_trap_nr;
	regs->cp0_epc = aup->resume_epc;

	return 0;
}

bool arch_uprobe_xol_was_trapped(struct task_struct *tsk)
{
	if (tsk->thread.trap_nr != UPROBE_TRAP_NR)
		return true;

	return false;
}

int arch_uprobe_exception_notify(struct notifier_block *self,
	unsigned long val, void *data)
{
	struct die_args *args = data;
	struct pt_regs *regs = args->regs;

	/* regs == NULL is a kernel bug */
	if (WARN_ON(!regs))
		return NOTIFY_DONE;

	/* We are only interested in userspace traps */
	if (!user_mode(regs))
		return NOTIFY_DONE;

	switch (val) {
	case DIE_UPROBE:
		if (uprobe_pre_sstep_notifier(regs))
			return NOTIFY_STOP;
		break;
	case DIE_UPROBE_XOL:
		if (uprobe_post_sstep_notifier(regs))
			return NOTIFY_STOP;
	default:
		break;
	}

	return 0;
}

void arch_uprobe_abort_xol(struct arch_uprobe *aup,
	struct pt_regs *regs)
{
	struct uprobe_task *utask = current->utask;

	instruction_pointer_set(regs, utask->vaddr);
}

unsigned long arch_uretprobe_hijack_return_addr(
	unsigned long trampoline_vaddr, struct pt_regs *regs)
{
	unsigned long ra;

	ra = regs->regs[31];

	/* Replace the return address with the trampoline address */
	regs->regs[31] = trampoline_vaddr;

	return ra;
}

