#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uprobe_opcode_t ;
struct arch_uprobe_task {scalar_t__ saved_trap_nr; } ;
struct uprobe_task {scalar_t__ vaddr; struct arch_uprobe_task autask; scalar_t__ xol_vaddr; } ;
struct TYPE_6__ {scalar_t__ trap_nr; } ;
struct task_struct {TYPE_1__ thread; } ;
struct return_instance {scalar_t__ stack; } ;
struct pt_regs {unsigned long link; scalar_t__* gpr; scalar_t__ nip; } ;
struct notifier_block {int dummy; } ;
struct mm_struct {int dummy; } ;
struct die_args {struct pt_regs* regs; } ;
struct arch_uprobe {int /*<<< orphan*/  insn; } ;
typedef  enum rp_check { ____Placeholder_rp_check } rp_check ;
struct TYPE_7__ {scalar_t__ trap_nr; } ;
struct TYPE_8__ {TYPE_2__ thread; struct uprobe_task* utask; } ;

/* Variables and functions */
#define  DIE_BPT 129 
#define  DIE_SSTEP 128 
 int EINVAL ; 
 scalar_t__ MAX_UINSN_BYTES ; 
 int NOTIFY_DONE ; 
 int NOTIFY_STOP ; 
 int RP_CHECK_CHAIN_CALL ; 
 scalar_t__ UPROBE_TRAP_NR ; 
 scalar_t__ WARN_ON (int) ; 
 int /*<<< orphan*/  WARN_ON_ONCE (int) ; 
 TYPE_3__* current ; 
 int emulate_step (struct pt_regs*,int /*<<< orphan*/ ) ; 
 unsigned long instruction_pointer (struct pt_regs*) ; 
 int /*<<< orphan*/  instruction_pointer_set (struct pt_regs*,scalar_t__) ; 
 int is_trap (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uprobe_post_sstep_notifier (struct pt_regs*) ; 
 int /*<<< orphan*/  uprobe_pre_sstep_notifier (struct pt_regs*) ; 
 int /*<<< orphan*/  user_disable_single_step (TYPE_3__*) ; 
 int /*<<< orphan*/  user_enable_single_step (TYPE_3__*) ; 
 int /*<<< orphan*/  user_mode (struct pt_regs*) ; 

bool is_trap_insn(uprobe_opcode_t *insn)
{
	return (is_trap(*insn));
}

int arch_uprobe_analyze_insn(struct arch_uprobe *auprobe,
		struct mm_struct *mm, unsigned long addr)
{
	if (addr & 0x03)
		return -EINVAL;

	return 0;
}

int arch_uprobe_pre_xol(struct arch_uprobe *auprobe, struct pt_regs *regs)
{
	struct arch_uprobe_task *autask = &current->utask->autask;

	autask->saved_trap_nr = current->thread.trap_nr;
	current->thread.trap_nr = UPROBE_TRAP_NR;
	regs->nip = current->utask->xol_vaddr;

	user_enable_single_step(current);
	return 0;
}

unsigned long uprobe_get_swbp_addr(struct pt_regs *regs)
{
	return instruction_pointer(regs);
}

bool arch_uprobe_xol_was_trapped(struct task_struct *t)
{
	if (t->thread.trap_nr != UPROBE_TRAP_NR)
		return true;

	return false;
}

int arch_uprobe_post_xol(struct arch_uprobe *auprobe, struct pt_regs *regs)
{
	struct uprobe_task *utask = current->utask;

	WARN_ON_ONCE(current->thread.trap_nr != UPROBE_TRAP_NR);

	current->thread.trap_nr = utask->autask.saved_trap_nr;

	/*
	 * On powerpc, except for loads and stores, most instructions
	 * including ones that alter code flow (branches, calls, returns)
	 * are emulated in the kernel. We get here only if the emulation
	 * support doesn't exist and have to fix-up the next instruction
	 * to be executed.
	 */
	regs->nip = utask->vaddr + MAX_UINSN_BYTES;

	user_disable_single_step(current);
	return 0;
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
	case DIE_BPT:
		if (uprobe_pre_sstep_notifier(regs))
			return NOTIFY_STOP;
		break;
	case DIE_SSTEP:
		if (uprobe_post_sstep_notifier(regs))
			return NOTIFY_STOP;
	default:
		break;
	}
	return NOTIFY_DONE;
}

void arch_uprobe_abort_xol(struct arch_uprobe *auprobe, struct pt_regs *regs)
{
	struct uprobe_task *utask = current->utask;

	current->thread.trap_nr = utask->autask.saved_trap_nr;
	instruction_pointer_set(regs, utask->vaddr);

	user_disable_single_step(current);
}

bool arch_uprobe_skip_sstep(struct arch_uprobe *auprobe, struct pt_regs *regs)
{
	int ret;

	/*
	 * emulate_step() returns 1 if the insn was successfully emulated.
	 * For all other cases, we need to single-step in hardware.
	 */
	ret = emulate_step(regs, auprobe->insn);
	if (ret > 0)
		return true;

	return false;
}

unsigned long
arch_uretprobe_hijack_return_addr(unsigned long trampoline_vaddr, struct pt_regs *regs)
{
	unsigned long orig_ret_vaddr;

	orig_ret_vaddr = regs->link;

	/* Replace the return addr with trampoline addr */
	regs->link = trampoline_vaddr;

	return orig_ret_vaddr;
}

bool arch_uretprobe_is_alive(struct return_instance *ret, enum rp_check ctx,
				struct pt_regs *regs)
{
	if (ctx == RP_CHECK_CHAIN_CALL)
		return regs->gpr[1] <= ret->stack;
	else
		return regs->gpr[1] < ret->stack;
}

