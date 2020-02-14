#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_6__ ;
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned int uprobe_opcode_t ;
struct TYPE_10__ {scalar_t__ saved_trap_no; } ;
struct uprobe_task {int xol_vaddr; int vaddr; TYPE_3__ autask; } ;
struct TYPE_8__ {scalar_t__ trap_no; } ;
struct task_struct {TYPE_1__ thread; } ;
struct pt_regs {int ARM_pc; unsigned long ARM_lr; int /*<<< orphan*/  ARM_cpsr; } ;
struct page {int dummy; } ;
struct notifier_block {int dummy; } ;
struct mm_struct {int dummy; } ;
struct TYPE_11__ {int /*<<< orphan*/  (* insn_singlestep ) (int,TYPE_5__*,struct pt_regs*) ;int /*<<< orphan*/  (* insn_check_cc ) (int /*<<< orphan*/ ) ;} ;
struct arch_uprobe {int bpinsn; int simulate; int /*<<< orphan*/  (* posthandler ) (struct arch_uprobe*,TYPE_3__*,struct pt_regs*) ;int /*<<< orphan*/  (* prehandler ) (struct arch_uprobe*,TYPE_3__*,struct pt_regs*) ;TYPE_5__ asi; void** ixol; scalar_t__ insn; } ;
typedef  int probes_opcode_t ;
typedef  enum probes_insn { ____Placeholder_probes_insn } probes_insn ;
struct TYPE_9__ {scalar_t__ trap_no; } ;
struct TYPE_12__ {TYPE_2__ thread; struct uprobe_task* utask; } ;

/* Variables and functions */
 int EINVAL ; 
#define  INSN_GOOD 130 
#define  INSN_GOOD_NO_SLOT 129 
#define  INSN_REJECTED 128 
 int NOTIFY_DONE ; 
 unsigned long PAGE_MASK ; 
 unsigned long PSR_IT_MASK ; 
 int UPROBE_SS_ARM_INSN ; 
 int UPROBE_SWBP_ARM_INSN ; 
 scalar_t__ UPROBE_TRAP_NR ; 
 int /*<<< orphan*/  WARN_ON_ONCE (int) ; 
 int __mem_to_opcode_arm (unsigned int) ; 
 void* __opcode_to_mem_arm (int) ; 
 int arm_probes_decode_insn (unsigned int,TYPE_5__*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 TYPE_6__* current ; 
 int /*<<< orphan*/  flush_uprobe_xol_access (struct page*,unsigned long,void*,unsigned long) ; 
 unsigned long instruction_pointer (struct pt_regs*) ; 
 int /*<<< orphan*/  instruction_pointer_set (struct pt_regs*,int) ; 
 void* kmap_atomic (struct page*) ; 
 int /*<<< orphan*/  kunmap_atomic (void*) ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 int /*<<< orphan*/  memcpy (void*,void*,unsigned long) ; 
 int /*<<< orphan*/  preempt_disable () ; 
 int /*<<< orphan*/  preempt_enable () ; 
 int /*<<< orphan*/  register_undef_hook (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub2 (int,TYPE_5__*,struct pt_regs*) ; 
 int /*<<< orphan*/  stub3 (struct arch_uprobe*,TYPE_3__*,struct pt_regs*) ; 
 int /*<<< orphan*/  stub4 (struct arch_uprobe*,TYPE_3__*,struct pt_regs*) ; 
 int /*<<< orphan*/  uprobe_post_sstep_notifier (struct pt_regs*) ; 
 int /*<<< orphan*/  uprobe_pre_sstep_notifier (struct pt_regs*) ; 
 int uprobe_write_opcode (struct arch_uprobe*,struct mm_struct*,unsigned long,void*) ; 
 int /*<<< orphan*/  uprobes_arm_break_hook ; 
 int /*<<< orphan*/  uprobes_arm_ss_hook ; 
 int /*<<< orphan*/  uprobes_probes_actions ; 

__attribute__((used)) static inline unsigned long it_advance(unsigned long cpsr)
	{
	if ((cpsr & 0x06000400) == 0) {
		/* ITSTATE<2:0> == 0 means end of IT block, so clear IT state */
		cpsr &= ~PSR_IT_MASK;
	} else {
		/* We need to shift left ITSTATE<4:0> */
		const unsigned long mask = 0x06001c00;  /* Mask ITSTATE<4:0> */
		unsigned long it = cpsr & mask;
		it <<= 1;
		it |= it >> (27 - 10);  /* Carry ITSTATE<2> to correct place */
		it &= mask;
		cpsr &= ~mask;
		cpsr |= it;
	}
	return cpsr;
}

bool is_swbp_insn(uprobe_opcode_t *insn)
{
	return (__mem_to_opcode_arm(*insn) & 0x0fffffff) ==
		(UPROBE_SWBP_ARM_INSN & 0x0fffffff);
}

int set_swbp(struct arch_uprobe *auprobe, struct mm_struct *mm,
	     unsigned long vaddr)
{
	return uprobe_write_opcode(auprobe, mm, vaddr,
		   __opcode_to_mem_arm(auprobe->bpinsn));
}

bool arch_uprobe_ignore(struct arch_uprobe *auprobe, struct pt_regs *regs)
{
	if (!auprobe->asi.insn_check_cc(regs->ARM_cpsr)) {
		regs->ARM_pc += 4;
		return true;
	}

	return false;
}

bool arch_uprobe_skip_sstep(struct arch_uprobe *auprobe, struct pt_regs *regs)
{
	probes_opcode_t opcode;

	if (!auprobe->simulate)
		return false;

	opcode = __mem_to_opcode_arm(*(unsigned int *) auprobe->insn);

	auprobe->asi.insn_singlestep(opcode, &auprobe->asi, regs);

	return true;
}

unsigned long
arch_uretprobe_hijack_return_addr(unsigned long trampoline_vaddr,
				  struct pt_regs *regs)
{
	unsigned long orig_ret_vaddr;

	orig_ret_vaddr = regs->ARM_lr;
	/* Replace the return addr with trampoline addr */
	regs->ARM_lr = trampoline_vaddr;
	return orig_ret_vaddr;
}

int arch_uprobe_analyze_insn(struct arch_uprobe *auprobe, struct mm_struct *mm,
			     unsigned long addr)
{
	unsigned int insn;
	unsigned int bpinsn;
	enum probes_insn ret;

	/* Thumb not yet support */
	if (addr & 0x3)
		return -EINVAL;

	insn = __mem_to_opcode_arm(*(unsigned int *)auprobe->insn);
	auprobe->ixol[0] = __opcode_to_mem_arm(insn);
	auprobe->ixol[1] = __opcode_to_mem_arm(UPROBE_SS_ARM_INSN);

	ret = arm_probes_decode_insn(insn, &auprobe->asi, false,
				     uprobes_probes_actions, NULL);
	switch (ret) {
	case INSN_REJECTED:
		return -EINVAL;

	case INSN_GOOD_NO_SLOT:
		auprobe->simulate = true;
		break;

	case INSN_GOOD:
	default:
		break;
	}

	bpinsn = UPROBE_SWBP_ARM_INSN & 0x0fffffff;
	if (insn >= 0xe0000000)
		bpinsn |= 0xe0000000;  /* Unconditional instruction */
	else
		bpinsn |= insn & 0xf0000000;  /* Copy condition from insn */

	auprobe->bpinsn = bpinsn;

	return 0;
}

void arch_uprobe_copy_ixol(struct page *page, unsigned long vaddr,
			   void *src, unsigned long len)
{
	void *xol_page_kaddr = kmap_atomic(page);
	void *dst = xol_page_kaddr + (vaddr & ~PAGE_MASK);

	preempt_disable();

	/* Initialize the slot */
	memcpy(dst, src, len);

	/* flush caches (dcache/icache) */
	flush_uprobe_xol_access(page, vaddr, dst, len);

	preempt_enable();

	kunmap_atomic(xol_page_kaddr);
}

int arch_uprobe_pre_xol(struct arch_uprobe *auprobe, struct pt_regs *regs)
{
	struct uprobe_task *utask = current->utask;

	if (auprobe->prehandler)
		auprobe->prehandler(auprobe, &utask->autask, regs);

	utask->autask.saved_trap_no = current->thread.trap_no;
	current->thread.trap_no = UPROBE_TRAP_NR;
	regs->ARM_pc = utask->xol_vaddr;

	return 0;
}

int arch_uprobe_post_xol(struct arch_uprobe *auprobe, struct pt_regs *regs)
{
	struct uprobe_task *utask = current->utask;

	WARN_ON_ONCE(current->thread.trap_no != UPROBE_TRAP_NR);

	current->thread.trap_no = utask->autask.saved_trap_no;
	regs->ARM_pc = utask->vaddr + 4;

	if (auprobe->posthandler)
		auprobe->posthandler(auprobe, &utask->autask, regs);

	return 0;
}

bool arch_uprobe_xol_was_trapped(struct task_struct *t)
{
	if (t->thread.trap_no != UPROBE_TRAP_NR)
		return true;

	return false;
}

void arch_uprobe_abort_xol(struct arch_uprobe *auprobe, struct pt_regs *regs)
{
	struct uprobe_task *utask = current->utask;

	current->thread.trap_no = utask->autask.saved_trap_no;
	instruction_pointer_set(regs, utask->vaddr);
}

int arch_uprobe_exception_notify(struct notifier_block *self,
				 unsigned long val, void *data)
{
	return NOTIFY_DONE;
}

__attribute__((used)) static int uprobe_trap_handler(struct pt_regs *regs, unsigned int instr)
{
	unsigned long flags;

	local_irq_save(flags);
	instr &= 0x0fffffff;
	if (instr == (UPROBE_SWBP_ARM_INSN & 0x0fffffff))
		uprobe_pre_sstep_notifier(regs);
	else if (instr == (UPROBE_SS_ARM_INSN & 0x0fffffff))
		uprobe_post_sstep_notifier(regs);
	local_irq_restore(flags);

	return 0;
}

unsigned long uprobe_get_swbp_addr(struct pt_regs *regs)
{
	return instruction_pointer(regs);
}

__attribute__((used)) static int arch_uprobes_init(void)
{
	register_undef_hook(&uprobes_arm_break_hook);
	register_undef_hook(&uprobes_arm_ss_hook);

	return 0;
}

