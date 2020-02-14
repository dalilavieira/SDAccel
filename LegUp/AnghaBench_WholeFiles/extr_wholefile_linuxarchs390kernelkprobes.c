#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u64 ;
struct swap_insn_args {int arm_kprobe; struct kprobe* p; } ;
struct TYPE_6__ {int mask; unsigned long addr; } ;
struct pt_regs {unsigned long* gprs; TYPE_3__ psw; } ;
struct per_regs {unsigned long start; unsigned long end; int /*<<< orphan*/  control; } ;
struct notifier_block {int dummy; } ;
struct kretprobe_instance {int /*<<< orphan*/ * ret_addr; } ;
struct TYPE_4__ {int status; struct kprobe* kp; } ;
struct kprobe_ctlblk {int kprobe_saved_imask; int kprobe_status; TYPE_1__ prev_kprobe; struct per_regs kprobe_saved_ctl; } ;
struct TYPE_5__ {int* insn; int is_ftrace_insn; } ;
struct kprobe {int* addr; int opcode; int /*<<< orphan*/  (* fault_handler ) (struct kprobe*,struct pt_regs*,int) ;int /*<<< orphan*/  (* post_handler ) (struct kprobe*,struct pt_regs*,int /*<<< orphan*/ ) ;TYPE_2__ ainsn; scalar_t__ (* pre_handler ) (struct kprobe*,struct pt_regs*) ;} ;
struct ftrace_insn {int opc; scalar_t__ disp; } ;
struct exception_table_entry {int dummy; } ;
struct die_args {int trapnr; struct pt_regs* regs; } ;
typedef  int s64 ;
typedef  int s32 ;
typedef  int /*<<< orphan*/  new_insn ;
typedef  int /*<<< orphan*/  kprobe_opcode_t ;

/* Variables and functions */
 int BREAKPOINT_INSTRUCTION ; 
 int /*<<< orphan*/  BUG () ; 
#define  DIE_BPT 134 
#define  DIE_SSTEP 133 
#define  DIE_TRAP 132 
 int EINVAL ; 
 int ENOMEM ; 
 int FIXUP_BRANCH_NOT_TAKEN ; 
 int FIXUP_PSW_NORMAL ; 
 int FIXUP_RETURN_REGISTER ; 
 int GFP_DMA ; 
 int GFP_KERNEL ; 
#define  KPROBE_HIT_ACTIVE 131 
#define  KPROBE_HIT_SS 130 
#define  KPROBE_HIT_SSDONE 129 
 scalar_t__ KPROBE_ON_FTRACE_CALL ; 
 scalar_t__ KPROBE_ON_FTRACE_NOP ; 
#define  KPROBE_REENTER 128 
 int MCOUNT_INSN_SIZE ; 
 int NOTIFY_DONE ; 
 int NOTIFY_STOP ; 
 int /*<<< orphan*/  PER_EVENT_IFETCH ; 
 int PSW_MASK_EXT ; 
 int PSW_MASK_IO ; 
 int PSW_MASK_PER ; 
 int /*<<< orphan*/  __ctl_load (struct per_regs,int,int) ; 
 int /*<<< orphan*/  __ctl_store (struct per_regs,int,int) ; 
 scalar_t__ __get_free_page (int) ; 
 struct kprobe* __this_cpu_read (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __this_cpu_write (int /*<<< orphan*/ ,struct kprobe*) ; 
 scalar_t__ _end ; 
 int /*<<< orphan*/  current_kprobe ; 
 int /*<<< orphan*/  dump_kprobe (struct kprobe*) ; 
 unsigned long extable_fixup (struct exception_table_entry const*) ; 
 int /*<<< orphan*/  free_dmainsn_slot (int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free_insn_slot (int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free_page (unsigned long) ; 
 int /*<<< orphan*/  ftrace_generate_call_insn (struct ftrace_insn*,unsigned long) ; 
 int /*<<< orphan*/  ftrace_generate_nop_insn (struct ftrace_insn*) ; 
 unsigned long ftrace_location (unsigned long) ; 
 int* get_dmainsn_slot () ; 
 int* get_insn_slot () ; 
 struct kprobe* get_kprobe (void*) ; 
 struct kprobe_ctlblk* get_kprobe_ctlblk () ; 
 int insn_length (int) ; 
 scalar_t__ is_ftrace_nop (struct ftrace_insn*) ; 
 scalar_t__ is_module_addr (int*) ; 
 struct kprobe* kprobe_running () ; 
 int /*<<< orphan*/  kprobes_inc_nmissed_count (struct kprobe*) ; 
 int /*<<< orphan*/  kretprobe_trampoline ; 
 int /*<<< orphan*/  local_irq_disable () ; 
 int /*<<< orphan*/  local_irq_restore (int) ; 
 int /*<<< orphan*/  memcpy (int*,int*,int) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int /*<<< orphan*/  preempt_disable () ; 
 int /*<<< orphan*/  preempt_enable_no_resched () ; 
 int /*<<< orphan*/  preemptible () ; 
 int probe_get_fixup_type (int*) ; 
 int /*<<< orphan*/  probe_is_insn_relative_long (int*) ; 
 scalar_t__ probe_is_prohibited_opcode (int*) ; 
 int /*<<< orphan*/  s390_kernel_write (int*,struct ftrace_insn*,size_t) ; 
 struct exception_table_entry* search_exception_tables (unsigned long) ; 
 int /*<<< orphan*/  set_memory_nx (unsigned long,int) ; 
 int /*<<< orphan*/  set_memory_x (unsigned long,int) ; 
 int /*<<< orphan*/  stop_machine_cpuslocked (int (*) (void*),struct swap_insn_args*,int /*<<< orphan*/ *) ; 
 scalar_t__ stub1 (struct kprobe*,struct pt_regs*) ; 
 int /*<<< orphan*/  stub2 (struct kprobe*,struct pt_regs*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub3 (struct kprobe*,struct pt_regs*,int) ; 

__attribute__((used)) static void *alloc_dmainsn_page(void)
{
	void *page;

	page = (void *) __get_free_page(GFP_KERNEL | GFP_DMA);
	if (page)
		set_memory_x((unsigned long) page, 1);
	return page;
}

__attribute__((used)) static void free_dmainsn_page(void *page)
{
	set_memory_nx((unsigned long) page, 1);
	free_page((unsigned long)page);
}

__attribute__((used)) static void copy_instruction(struct kprobe *p)
{
	unsigned long ip = (unsigned long) p->addr;
	s64 disp, new_disp;
	u64 addr, new_addr;

	if (ftrace_location(ip) == ip) {
		/*
		 * If kprobes patches the instruction that is morphed by
		 * ftrace make sure that kprobes always sees the branch
		 * "jg .+24" that skips the mcount block or the "brcl 0,0"
		 * in case of hotpatch.
		 */
		ftrace_generate_nop_insn((struct ftrace_insn *)p->ainsn.insn);
		p->ainsn.is_ftrace_insn = 1;
	} else
		memcpy(p->ainsn.insn, p->addr, insn_length(*p->addr >> 8));
	p->opcode = p->ainsn.insn[0];
	if (!probe_is_insn_relative_long(p->ainsn.insn))
		return;
	/*
	 * For pc-relative instructions in RIL-b or RIL-c format patch the
	 * RI2 displacement field. We have already made sure that the insn
	 * slot for the patched instruction is within the same 2GB area
	 * as the original instruction (either kernel image or module area).
	 * Therefore the new displacement will always fit.
	 */
	disp = *(s32 *)&p->ainsn.insn[1];
	addr = (u64)(unsigned long)p->addr;
	new_addr = (u64)(unsigned long)p->ainsn.insn;
	new_disp = ((addr + (disp * 2)) - new_addr) / 2;
	*(s32 *)&p->ainsn.insn[1] = new_disp;
}

__attribute__((used)) static inline int is_kernel_addr(void *addr)
{
	return addr < (void *)_end;
}

__attribute__((used)) static int s390_get_insn_slot(struct kprobe *p)
{
	/*
	 * Get an insn slot that is within the same 2GB area like the original
	 * instruction. That way instructions with a 32bit signed displacement
	 * field can be patched and executed within the insn slot.
	 */
	p->ainsn.insn = NULL;
	if (is_kernel_addr(p->addr))
		p->ainsn.insn = get_dmainsn_slot();
	else if (is_module_addr(p->addr))
		p->ainsn.insn = get_insn_slot();
	return p->ainsn.insn ? 0 : -ENOMEM;
}

__attribute__((used)) static void s390_free_insn_slot(struct kprobe *p)
{
	if (!p->ainsn.insn)
		return;
	if (is_kernel_addr(p->addr))
		free_dmainsn_slot(p->ainsn.insn, 0);
	else
		free_insn_slot(p->ainsn.insn, 0);
	p->ainsn.insn = NULL;
}

int arch_prepare_kprobe(struct kprobe *p)
{
	if ((unsigned long) p->addr & 0x01)
		return -EINVAL;
	/* Make sure the probe isn't going on a difficult instruction */
	if (probe_is_prohibited_opcode(p->addr))
		return -EINVAL;
	if (s390_get_insn_slot(p))
		return -ENOMEM;
	copy_instruction(p);
	return 0;
}

int arch_check_ftrace_location(struct kprobe *p)
{
	return 0;
}

__attribute__((used)) static int swap_instruction(void *data)
{
	struct swap_insn_args *args = data;
	struct ftrace_insn new_insn, *insn;
	struct kprobe *p = args->p;
	size_t len;

	new_insn.opc = args->arm_kprobe ? BREAKPOINT_INSTRUCTION : p->opcode;
	len = sizeof(new_insn.opc);
	if (!p->ainsn.is_ftrace_insn)
		goto skip_ftrace;
	len = sizeof(new_insn);
	insn = (struct ftrace_insn *) p->addr;
	if (args->arm_kprobe) {
		if (is_ftrace_nop(insn))
			new_insn.disp = KPROBE_ON_FTRACE_NOP;
		else
			new_insn.disp = KPROBE_ON_FTRACE_CALL;
	} else {
		ftrace_generate_call_insn(&new_insn, (unsigned long)p->addr);
		if (insn->disp == KPROBE_ON_FTRACE_NOP)
			ftrace_generate_nop_insn(&new_insn);
	}
skip_ftrace:
	s390_kernel_write(p->addr, &new_insn, len);
	return 0;
}

void arch_arm_kprobe(struct kprobe *p)
{
	struct swap_insn_args args = {.p = p, .arm_kprobe = 1};

	stop_machine_cpuslocked(swap_instruction, &args, NULL);
}

void arch_disarm_kprobe(struct kprobe *p)
{
	struct swap_insn_args args = {.p = p, .arm_kprobe = 0};

	stop_machine_cpuslocked(swap_instruction, &args, NULL);
}

void arch_remove_kprobe(struct kprobe *p)
{
	s390_free_insn_slot(p);
}

__attribute__((used)) static void enable_singlestep(struct kprobe_ctlblk *kcb,
			      struct pt_regs *regs,
			      unsigned long ip)
{
	struct per_regs per_kprobe;

	/* Set up the PER control registers %cr9-%cr11 */
	per_kprobe.control = PER_EVENT_IFETCH;
	per_kprobe.start = ip;
	per_kprobe.end = ip;

	/* Save control regs and psw mask */
	__ctl_store(kcb->kprobe_saved_ctl, 9, 11);
	kcb->kprobe_saved_imask = regs->psw.mask &
		(PSW_MASK_PER | PSW_MASK_IO | PSW_MASK_EXT);

	/* Set PER control regs, turns on single step for the given address */
	__ctl_load(per_kprobe, 9, 11);
	regs->psw.mask |= PSW_MASK_PER;
	regs->psw.mask &= ~(PSW_MASK_IO | PSW_MASK_EXT);
	regs->psw.addr = ip;
}

__attribute__((used)) static void disable_singlestep(struct kprobe_ctlblk *kcb,
			       struct pt_regs *regs,
			       unsigned long ip)
{
	/* Restore control regs and psw mask, set new psw address */
	__ctl_load(kcb->kprobe_saved_ctl, 9, 11);
	regs->psw.mask &= ~PSW_MASK_PER;
	regs->psw.mask |= kcb->kprobe_saved_imask;
	regs->psw.addr = ip;
}

__attribute__((used)) static void push_kprobe(struct kprobe_ctlblk *kcb, struct kprobe *p)
{
	kcb->prev_kprobe.kp = __this_cpu_read(current_kprobe);
	kcb->prev_kprobe.status = kcb->kprobe_status;
	__this_cpu_write(current_kprobe, p);
}

__attribute__((used)) static void pop_kprobe(struct kprobe_ctlblk *kcb)
{
	__this_cpu_write(current_kprobe, kcb->prev_kprobe.kp);
	kcb->kprobe_status = kcb->prev_kprobe.status;
}

void arch_prepare_kretprobe(struct kretprobe_instance *ri, struct pt_regs *regs)
{
	ri->ret_addr = (kprobe_opcode_t *) regs->gprs[14];

	/* Replace the return addr with trampoline addr */
	regs->gprs[14] = (unsigned long) &kretprobe_trampoline;
}

__attribute__((used)) static void kprobe_reenter_check(struct kprobe_ctlblk *kcb, struct kprobe *p)
{
	switch (kcb->kprobe_status) {
	case KPROBE_HIT_SSDONE:
	case KPROBE_HIT_ACTIVE:
		kprobes_inc_nmissed_count(p);
		break;
	case KPROBE_HIT_SS:
	case KPROBE_REENTER:
	default:
		/*
		 * A kprobe on the code path to single step an instruction
		 * is a BUG. The code path resides in the .kprobes.text
		 * section and is executed with interrupts disabled.
		 */
		pr_err("Invalid kprobe detected.\n");
		dump_kprobe(p);
		BUG();
	}
}

__attribute__((used)) static int kprobe_handler(struct pt_regs *regs)
{
	struct kprobe_ctlblk *kcb;
	struct kprobe *p;

	/*
	 * We want to disable preemption for the entire duration of kprobe
	 * processing. That includes the calls to the pre/post handlers
	 * and single stepping the kprobe instruction.
	 */
	preempt_disable();
	kcb = get_kprobe_ctlblk();
	p = get_kprobe((void *)(regs->psw.addr - 2));

	if (p) {
		if (kprobe_running()) {
			/*
			 * We have hit a kprobe while another is still
			 * active. This can happen in the pre and post
			 * handler. Single step the instruction of the
			 * new probe but do not call any handler function
			 * of this secondary kprobe.
			 * push_kprobe and pop_kprobe saves and restores
			 * the currently active kprobe.
			 */
			kprobe_reenter_check(kcb, p);
			push_kprobe(kcb, p);
			kcb->kprobe_status = KPROBE_REENTER;
		} else {
			/*
			 * If we have no pre-handler or it returned 0, we
			 * continue with single stepping. If we have a
			 * pre-handler and it returned non-zero, it prepped
			 * for changing execution path, so get out doing
			 * nothing more here.
			 */
			push_kprobe(kcb, p);
			kcb->kprobe_status = KPROBE_HIT_ACTIVE;
			if (p->pre_handler && p->pre_handler(p, regs)) {
				pop_kprobe(kcb);
				preempt_enable_no_resched();
				return 1;
			}
			kcb->kprobe_status = KPROBE_HIT_SS;
		}
		enable_singlestep(kcb, regs, (unsigned long) p->ainsn.insn);
		return 1;
	} /* else:
	   * No kprobe at this address and no active kprobe. The trap has
	   * not been caused by a kprobe breakpoint. The race of breakpoint
	   * vs. kprobe remove does not exist because on s390 as we use
	   * stop_machine to arm/disarm the breakpoints.
	   */
	preempt_enable_no_resched();
	return 0;
}

__attribute__((used)) static void resume_execution(struct kprobe *p, struct pt_regs *regs)
{
	struct kprobe_ctlblk *kcb = get_kprobe_ctlblk();
	unsigned long ip = regs->psw.addr;
	int fixup = probe_get_fixup_type(p->ainsn.insn);

	/* Check if the kprobes location is an enabled ftrace caller */
	if (p->ainsn.is_ftrace_insn) {
		struct ftrace_insn *insn = (struct ftrace_insn *) p->addr;
		struct ftrace_insn call_insn;

		ftrace_generate_call_insn(&call_insn, (unsigned long) p->addr);
		/*
		 * A kprobe on an enabled ftrace call site actually single
		 * stepped an unconditional branch (ftrace nop equivalent).
		 * Now we need to fixup things and pretend that a brasl r0,...
		 * was executed instead.
		 */
		if (insn->disp == KPROBE_ON_FTRACE_CALL) {
			ip += call_insn.disp * 2 - MCOUNT_INSN_SIZE;
			regs->gprs[0] = (unsigned long)p->addr + sizeof(*insn);
		}
	}

	if (fixup & FIXUP_PSW_NORMAL)
		ip += (unsigned long) p->addr - (unsigned long) p->ainsn.insn;

	if (fixup & FIXUP_BRANCH_NOT_TAKEN) {
		int ilen = insn_length(p->ainsn.insn[0] >> 8);
		if (ip - (unsigned long) p->ainsn.insn == ilen)
			ip = (unsigned long) p->addr + ilen;
	}

	if (fixup & FIXUP_RETURN_REGISTER) {
		int reg = (p->ainsn.insn[0] & 0xf0) >> 4;
		regs->gprs[reg] += (unsigned long) p->addr -
				   (unsigned long) p->ainsn.insn;
	}

	disable_singlestep(kcb, regs, ip);
}

__attribute__((used)) static int post_kprobe_handler(struct pt_regs *regs)
{
	struct kprobe_ctlblk *kcb = get_kprobe_ctlblk();
	struct kprobe *p = kprobe_running();

	if (!p)
		return 0;

	if (kcb->kprobe_status != KPROBE_REENTER && p->post_handler) {
		kcb->kprobe_status = KPROBE_HIT_SSDONE;
		p->post_handler(p, regs, 0);
	}

	resume_execution(p, regs);
	pop_kprobe(kcb);
	preempt_enable_no_resched();

	/*
	 * if somebody else is singlestepping across a probe point, psw mask
	 * will have PER set, in which case, continue the remaining processing
	 * of do_single_step, as if this is not a probe hit.
	 */
	if (regs->psw.mask & PSW_MASK_PER)
		return 0;

	return 1;
}

__attribute__((used)) static int kprobe_trap_handler(struct pt_regs *regs, int trapnr)
{
	struct kprobe_ctlblk *kcb = get_kprobe_ctlblk();
	struct kprobe *p = kprobe_running();
	const struct exception_table_entry *entry;

	switch(kcb->kprobe_status) {
	case KPROBE_HIT_SS:
	case KPROBE_REENTER:
		/*
		 * We are here because the instruction being single
		 * stepped caused a page fault. We reset the current
		 * kprobe and the nip points back to the probe address
		 * and allow the page fault handler to continue as a
		 * normal page fault.
		 */
		disable_singlestep(kcb, regs, (unsigned long) p->addr);
		pop_kprobe(kcb);
		preempt_enable_no_resched();
		break;
	case KPROBE_HIT_ACTIVE:
	case KPROBE_HIT_SSDONE:
		/*
		 * We increment the nmissed count for accounting,
		 * we can also use npre/npostfault count for accounting
		 * these specific fault cases.
		 */
		kprobes_inc_nmissed_count(p);

		/*
		 * We come here because instructions in the pre/post
		 * handler caused the page_fault, this could happen
		 * if handler tries to access user space by
		 * copy_from_user(), get_user() etc. Let the
		 * user-specified handler try to fix it first.
		 */
		if (p->fault_handler && p->fault_handler(p, regs, trapnr))
			return 1;

		/*
		 * In case the user-specified fault handler returned
		 * zero, try to fix up.
		 */
		entry = search_exception_tables(regs->psw.addr);
		if (entry) {
			regs->psw.addr = extable_fixup(entry);
			return 1;
		}

		/*
		 * fixup_exception() could not handle it,
		 * Let do_page_fault() fix it.
		 */
		break;
	default:
		break;
	}
	return 0;
}

int kprobe_fault_handler(struct pt_regs *regs, int trapnr)
{
	int ret;

	if (regs->psw.mask & (PSW_MASK_IO | PSW_MASK_EXT))
		local_irq_disable();
	ret = kprobe_trap_handler(regs, trapnr);
	if (regs->psw.mask & (PSW_MASK_IO | PSW_MASK_EXT))
		local_irq_restore(regs->psw.mask & ~PSW_MASK_PER);
	return ret;
}

int kprobe_exceptions_notify(struct notifier_block *self,
			     unsigned long val, void *data)
{
	struct die_args *args = (struct die_args *) data;
	struct pt_regs *regs = args->regs;
	int ret = NOTIFY_DONE;

	if (regs->psw.mask & (PSW_MASK_IO | PSW_MASK_EXT))
		local_irq_disable();

	switch (val) {
	case DIE_BPT:
		if (kprobe_handler(regs))
			ret = NOTIFY_STOP;
		break;
	case DIE_SSTEP:
		if (post_kprobe_handler(regs))
			ret = NOTIFY_STOP;
		break;
	case DIE_TRAP:
		if (!preemptible() && kprobe_running() &&
		    kprobe_trap_handler(regs, args->trapnr))
			ret = NOTIFY_STOP;
		break;
	default:
		break;
	}

	if (regs->psw.mask & (PSW_MASK_IO | PSW_MASK_EXT))
		local_irq_restore(regs->psw.mask & ~PSW_MASK_PER);

	return ret;
}

