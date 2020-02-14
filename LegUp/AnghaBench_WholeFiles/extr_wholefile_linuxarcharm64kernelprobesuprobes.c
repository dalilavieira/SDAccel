#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_7__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct uprobe_task {scalar_t__ xol_vaddr; scalar_t__ vaddr; } ;
struct TYPE_10__ {scalar_t__ fault_code; } ;
struct task_struct {TYPE_3__ thread; } ;
struct return_instance {scalar_t__ stack; } ;
struct pt_regs {scalar_t__ sp; } ;
struct page {int dummy; } ;
struct notifier_block {int dummy; } ;
struct TYPE_8__ {int flags; } ;
struct mm_struct {TYPE_1__ context; } ;
struct TYPE_12__ {int /*<<< orphan*/  (* handler ) (int /*<<< orphan*/ ,unsigned long,struct pt_regs*) ;} ;
struct arch_uprobe {int simulate; TYPE_7__ api; int /*<<< orphan*/ * insn; } ;
typedef  int /*<<< orphan*/  probe_opcode_t ;
typedef  enum rp_check { ____Placeholder_rp_check } rp_check ;
struct TYPE_9__ {scalar_t__ fault_code; } ;
struct TYPE_11__ {struct uprobe_task* utask; TYPE_2__ thread; } ;

/* Variables and functions */
 int /*<<< orphan*/  AARCH64_INSN_SIZE ; 
 int DBG_HOOK_ERROR ; 
 int DBG_HOOK_HANDLED ; 
 int EINVAL ; 
 int ENOTSUPP ; 
#define  INSN_GOOD_NO_SLOT 129 
#define  INSN_REJECTED 128 
 int /*<<< orphan*/  IS_ALIGNED (unsigned long,int /*<<< orphan*/ ) ; 
 int MMCF_AARCH32 ; 
 int NOTIFY_DONE ; 
 unsigned long PAGE_MASK ; 
 int RP_CHECK_CHAIN_CALL ; 
 scalar_t__ UPROBE_INV_FAULT_CODE ; 
 int /*<<< orphan*/  WARN_ON (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WARN_ON_ONCE (int) ; 
 int arm_probe_decode_insn (int /*<<< orphan*/ ,TYPE_7__*) ; 
 TYPE_4__* current ; 
 scalar_t__ instruction_pointer (struct pt_regs*) ; 
 int /*<<< orphan*/  instruction_pointer_set (struct pt_regs*,scalar_t__) ; 
 void* kmap_atomic (struct page*) ; 
 int /*<<< orphan*/  kunmap_atomic (void*) ; 
 int /*<<< orphan*/  memcpy (void*,void*,unsigned long) ; 
 unsigned long procedure_link_pointer (struct pt_regs*) ; 
 int /*<<< orphan*/  procedure_link_pointer_set (struct pt_regs*,unsigned long) ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ,unsigned long,struct pt_regs*) ; 
 int /*<<< orphan*/  sync_icache_aliases (void*,unsigned long) ; 
 scalar_t__ uprobe_post_sstep_notifier (struct pt_regs*) ; 
 scalar_t__ uprobe_pre_sstep_notifier (struct pt_regs*) ; 
 int /*<<< orphan*/  user_disable_single_step (TYPE_4__*) ; 
 int /*<<< orphan*/  user_enable_single_step (TYPE_4__*) ; 
 scalar_t__ user_mode (struct pt_regs*) ; 

void arch_uprobe_copy_ixol(struct page *page, unsigned long vaddr,
		void *src, unsigned long len)
{
	void *xol_page_kaddr = kmap_atomic(page);
	void *dst = xol_page_kaddr + (vaddr & ~PAGE_MASK);

	/* Initialize the slot */
	memcpy(dst, src, len);

	/* flush caches (dcache/icache) */
	sync_icache_aliases(dst, len);

	kunmap_atomic(xol_page_kaddr);
}

unsigned long uprobe_get_swbp_addr(struct pt_regs *regs)
{
	return instruction_pointer(regs);
}

int arch_uprobe_analyze_insn(struct arch_uprobe *auprobe, struct mm_struct *mm,
		unsigned long addr)
{
	probe_opcode_t insn;

	/* TODO: Currently we do not support AARCH32 instruction probing */
	if (mm->context.flags & MMCF_AARCH32)
		return -ENOTSUPP;
	else if (!IS_ALIGNED(addr, AARCH64_INSN_SIZE))
		return -EINVAL;

	insn = *(probe_opcode_t *)(&auprobe->insn[0]);

	switch (arm_probe_decode_insn(insn, &auprobe->api)) {
	case INSN_REJECTED:
		return -EINVAL;

	case INSN_GOOD_NO_SLOT:
		auprobe->simulate = true;
		break;

	default:
		break;
	}

	return 0;
}

int arch_uprobe_pre_xol(struct arch_uprobe *auprobe, struct pt_regs *regs)
{
	struct uprobe_task *utask = current->utask;

	/* Initialize with an invalid fault code to detect if ol insn trapped */
	current->thread.fault_code = UPROBE_INV_FAULT_CODE;

	/* Instruction points to execute ol */
	instruction_pointer_set(regs, utask->xol_vaddr);

	user_enable_single_step(current);

	return 0;
}

int arch_uprobe_post_xol(struct arch_uprobe *auprobe, struct pt_regs *regs)
{
	struct uprobe_task *utask = current->utask;

	WARN_ON_ONCE(current->thread.fault_code != UPROBE_INV_FAULT_CODE);

	/* Instruction points to execute next to breakpoint address */
	instruction_pointer_set(regs, utask->vaddr + 4);

	user_disable_single_step(current);

	return 0;
}

bool arch_uprobe_xol_was_trapped(struct task_struct *t)
{
	/*
	 * Between arch_uprobe_pre_xol and arch_uprobe_post_xol, if an xol
	 * insn itself is trapped, then detect the case with the help of
	 * invalid fault code which is being set in arch_uprobe_pre_xol
	 */
	if (t->thread.fault_code != UPROBE_INV_FAULT_CODE)
		return true;

	return false;
}

bool arch_uprobe_skip_sstep(struct arch_uprobe *auprobe, struct pt_regs *regs)
{
	probe_opcode_t insn;
	unsigned long addr;

	if (!auprobe->simulate)
		return false;

	insn = *(probe_opcode_t *)(&auprobe->insn[0]);
	addr = instruction_pointer(regs);

	if (auprobe->api.handler)
		auprobe->api.handler(insn, addr, regs);

	return true;
}

void arch_uprobe_abort_xol(struct arch_uprobe *auprobe, struct pt_regs *regs)
{
	struct uprobe_task *utask = current->utask;

	/*
	 * Task has received a fatal signal, so reset back to probbed
	 * address.
	 */
	instruction_pointer_set(regs, utask->vaddr);

	user_disable_single_step(current);
}

bool arch_uretprobe_is_alive(struct return_instance *ret, enum rp_check ctx,
		struct pt_regs *regs)
{
	/*
	 * If a simple branch instruction (B) was called for retprobed
	 * assembly label then return true even when regs->sp and ret->stack
	 * are same. It will ensure that cleanup and reporting of return
	 * instances corresponding to callee label is done when
	 * handle_trampoline for called function is executed.
	 */
	if (ctx == RP_CHECK_CHAIN_CALL)
		return regs->sp <= ret->stack;
	else
		return regs->sp < ret->stack;
}

unsigned long
arch_uretprobe_hijack_return_addr(unsigned long trampoline_vaddr,
				  struct pt_regs *regs)
{
	unsigned long orig_ret_vaddr;

	orig_ret_vaddr = procedure_link_pointer(regs);
	/* Replace the return addr with trampoline addr */
	procedure_link_pointer_set(regs, trampoline_vaddr);

	return orig_ret_vaddr;
}

int arch_uprobe_exception_notify(struct notifier_block *self,
				 unsigned long val, void *data)
{
	return NOTIFY_DONE;
}

__attribute__((used)) static int uprobe_breakpoint_handler(struct pt_regs *regs,
		unsigned int esr)
{
	if (user_mode(regs) && uprobe_pre_sstep_notifier(regs))
		return DBG_HOOK_HANDLED;

	return DBG_HOOK_ERROR;
}

__attribute__((used)) static int uprobe_single_step_handler(struct pt_regs *regs,
		unsigned int esr)
{
	struct uprobe_task *utask = current->utask;

	if (user_mode(regs)) {
		WARN_ON(utask &&
			(instruction_pointer(regs) != utask->xol_vaddr + 4));

		if (uprobe_post_sstep_notifier(regs))
			return DBG_HOOK_HANDLED;
	}

	return DBG_HOOK_ERROR;
}

