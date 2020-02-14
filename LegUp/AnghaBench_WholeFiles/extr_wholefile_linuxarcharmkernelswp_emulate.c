#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct pt_regs {int ARM_pc; unsigned int* uregs; int /*<<< orphan*/  ARM_cpsr; } ;
struct TYPE_7__ {void* si_addr; scalar_t__ si_errno; int /*<<< orphan*/  si_signo; int /*<<< orphan*/  si_code; } ;
typedef  TYPE_1__ siginfo_t ;
struct TYPE_9__ {int /*<<< orphan*/  mmap_sem; } ;
struct TYPE_8__ {scalar_t__ pid; int /*<<< orphan*/  comm; TYPE_3__* mm; } ;

/* Variables and functions */
#define  ARM_OPCODE_CONDTEST_FAIL 130 
#define  ARM_OPCODE_CONDTEST_PASS 129 
#define  ARM_OPCODE_CONDTEST_UNCOND 128 
 unsigned int EAGAIN ; 
 int EFAULT ; 
 int EINVAL ; 
 size_t EXTRACT_REG_NUM (unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PERF_COUNT_SW_EMULATION_FAULTS ; 
 int /*<<< orphan*/  RN_OFFSET ; 
 int /*<<< orphan*/  RT2_OFFSET ; 
 int /*<<< orphan*/  RT_OFFSET ; 
 int /*<<< orphan*/  SEGV_ACCERR ; 
 int /*<<< orphan*/  SEGV_MAPERR ; 
 int /*<<< orphan*/  SIGSEGV ; 
 unsigned int TYPE_SWPB ; 
 int /*<<< orphan*/  VERIFY_WRITE ; 
 int /*<<< orphan*/  __user_swp_asm (unsigned int,unsigned int,unsigned int,unsigned long) ; 
 int /*<<< orphan*/  __user_swpb_asm (unsigned int,unsigned int,unsigned int,unsigned long) ; 
 int /*<<< orphan*/  abtcounter ; 
 int /*<<< orphan*/  access_ok (int /*<<< orphan*/ ,unsigned int,int) ; 
 unsigned int arm_check_condition (unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  arm_notify_die (char*,struct pt_regs*,TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clear_siginfo (TYPE_1__*) ; 
 int /*<<< orphan*/  cond_resched () ; 
 TYPE_2__* current ; 
 int /*<<< orphan*/  down_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * find_vma (TYPE_3__*,unsigned long) ; 
 scalar_t__ instruction_pointer (struct pt_regs*) ; 
 scalar_t__ likely (int) ; 
 int /*<<< orphan*/  perf_sw_event (int /*<<< orphan*/ ,int,struct pt_regs*,int) ; 
 int /*<<< orphan*/  pr_debug (char*,...) ; 
 scalar_t__ previous_pid ; 
 scalar_t__ signal_pending (TYPE_2__*) ; 
 int /*<<< orphan*/  swpbcounter ; 
 int /*<<< orphan*/  swpcounter ; 
 int /*<<< orphan*/  uaccess_restore (unsigned int) ; 
 unsigned int uaccess_save_and_enable () ; 
 int /*<<< orphan*/  up_read (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void set_segfault(struct pt_regs *regs, unsigned long addr)
{
	siginfo_t info;

	clear_siginfo(&info);
	down_read(&current->mm->mmap_sem);
	if (find_vma(current->mm, addr) == NULL)
		info.si_code = SEGV_MAPERR;
	else
		info.si_code = SEGV_ACCERR;
	up_read(&current->mm->mmap_sem);

	info.si_signo = SIGSEGV;
	info.si_errno = 0;
	info.si_addr  = (void *) instruction_pointer(regs);

	pr_debug("SWP{B} emulation: access caused memory abort!\n");
	arm_notify_die("Illegal memory access", regs, &info, 0, 0);

	abtcounter++;
}

__attribute__((used)) static int emulate_swpX(unsigned int address, unsigned int *data,
			unsigned int type)
{
	unsigned int res = 0;

	if ((type != TYPE_SWPB) && (address & 0x3)) {
		/* SWP to unaligned address not permitted */
		pr_debug("SWP instruction on unaligned pointer!\n");
		return -EFAULT;
	}

	while (1) {
		unsigned long temp;
		unsigned int __ua_flags;

		__ua_flags = uaccess_save_and_enable();
		if (type == TYPE_SWPB)
			__user_swpb_asm(*data, address, res, temp);
		else
			__user_swp_asm(*data, address, res, temp);
		uaccess_restore(__ua_flags);

		if (likely(res != -EAGAIN) || signal_pending(current))
			break;

		cond_resched();
	}

	if (res == 0) {
		if (type == TYPE_SWPB)
			swpbcounter++;
		else
			swpcounter++;
	}

	return res;
}

__attribute__((used)) static int swp_handler(struct pt_regs *regs, unsigned int instr)
{
	unsigned int address, destreg, data, type;
	unsigned int res = 0;

	perf_sw_event(PERF_COUNT_SW_EMULATION_FAULTS, 1, regs, regs->ARM_pc);

	res = arm_check_condition(instr, regs->ARM_cpsr);
	switch (res) {
	case ARM_OPCODE_CONDTEST_PASS:
		break;
	case ARM_OPCODE_CONDTEST_FAIL:
		/* Condition failed - return to next instruction */
		regs->ARM_pc += 4;
		return 0;
	case ARM_OPCODE_CONDTEST_UNCOND:
		/* If unconditional encoding - not a SWP, undef */
		return -EFAULT;
	default:
		return -EINVAL;
	}

	if (current->pid != previous_pid) {
		pr_debug("\"%s\" (%ld) uses deprecated SWP{B} instruction\n",
			 current->comm, (unsigned long)current->pid);
		previous_pid = current->pid;
	}

	address = regs->uregs[EXTRACT_REG_NUM(instr, RN_OFFSET)];
	data	= regs->uregs[EXTRACT_REG_NUM(instr, RT2_OFFSET)];
	destreg = EXTRACT_REG_NUM(instr, RT_OFFSET);

	type = instr & TYPE_SWPB;

	pr_debug("addr in r%d->0x%08x, dest is r%d, source in r%d->0x%08x)\n",
		 EXTRACT_REG_NUM(instr, RN_OFFSET), address,
		 destreg, EXTRACT_REG_NUM(instr, RT2_OFFSET), data);

	/* Check access in reasonable access range for both SWP and SWPB */
	if (!access_ok(VERIFY_WRITE, (address & ~3), 4)) {
		pr_debug("SWP{B} emulation: access to %p not allowed!\n",
			 (void *)address);
		res = -EFAULT;
	} else {
		res = emulate_swpX(address, &data, type);
	}

	if (res == 0) {
		/*
		 * On successful emulation, revert the adjustment to the PC
		 * made in kernel/traps.c in order to resume execution at the
		 * instruction following the SWP{B}.
		 */
		regs->ARM_pc += 4;
		regs->uregs[destreg] = data;
	} else if (res == -EFAULT) {
		/*
		 * Memory errors do not mean emulation failed.
		 * Set up signal info to return SEGV, then return OK
		 */
		set_segfault(regs, address);
	}

	return 0;
}

