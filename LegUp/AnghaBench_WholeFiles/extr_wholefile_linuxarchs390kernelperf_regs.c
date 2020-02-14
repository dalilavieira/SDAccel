#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int u64 ;
typedef  scalar_t__ u32 ;
struct TYPE_5__ {TYPE_4__* fprs; scalar_t__ vxrs; } ;
struct TYPE_6__ {TYPE_1__ fpu; } ;
struct task_struct {TYPE_2__ thread; } ;
struct TYPE_7__ {int mask; int addr; } ;
struct pt_regs {int* gprs; TYPE_3__ psw; } ;
struct perf_regs {int abi; struct pt_regs* regs; } ;
struct TYPE_8__ {int ui; } ;
typedef  TYPE_4__ freg_t ;

/* Variables and functions */
 int EINVAL ; 
 scalar_t__ MACHINE_HAS_VX ; 
 int PERF_REG_S390_FP0 ; 
 int PERF_REG_S390_FP15 ; 
 int PERF_REG_S390_MASK ; 
 scalar_t__ PERF_REG_S390_MAX ; 
 int PERF_REG_S390_PC ; 
 int PERF_REG_S390_R0 ; 
 int PERF_REG_S390_R15 ; 
 int PERF_SAMPLE_REGS_ABI_32 ; 
 int PERF_SAMPLE_REGS_ABI_64 ; 
 int REG_RESERVED ; 
 int /*<<< orphan*/  TIF_31BIT ; 
 int /*<<< orphan*/  WARN_ON_ONCE (int) ; 
 struct task_struct* current ; 
 int /*<<< orphan*/  save_fpu_regs () ; 
 struct pt_regs* task_pt_regs (struct task_struct*) ; 
 scalar_t__ test_tsk_thread_flag (struct task_struct*,int /*<<< orphan*/ ) ; 
 scalar_t__ user_mode (struct pt_regs*) ; 

u64 perf_reg_value(struct pt_regs *regs, int idx)
{
	freg_t fp;

	if (idx >= PERF_REG_S390_R0 && idx <= PERF_REG_S390_R15)
		return regs->gprs[idx];

	if (idx >= PERF_REG_S390_FP0 && idx <= PERF_REG_S390_FP15) {
		if (!user_mode(regs))
			return 0;

		idx -= PERF_REG_S390_FP0;
		fp = MACHINE_HAS_VX ? *(freg_t *)(current->thread.fpu.vxrs + idx)
				    : current->thread.fpu.fprs[idx];
		return fp.ui;
	}

	if (idx == PERF_REG_S390_MASK)
		return regs->psw.mask;
	if (idx == PERF_REG_S390_PC)
		return regs->psw.addr;

	WARN_ON_ONCE((u32)idx >= PERF_REG_S390_MAX);
	return 0;
}

int perf_reg_validate(u64 mask)
{
	if (!mask || mask & REG_RESERVED)
		return -EINVAL;

	return 0;
}

u64 perf_reg_abi(struct task_struct *task)
{
	if (test_tsk_thread_flag(task, TIF_31BIT))
		return PERF_SAMPLE_REGS_ABI_32;

	return PERF_SAMPLE_REGS_ABI_64;
}

void perf_get_regs_user(struct perf_regs *regs_user,
			struct pt_regs *regs,
			struct pt_regs *regs_user_copy)
{
	/*
	 * Use the regs from the first interruption and let
	 * perf_sample_regs_intr() handle interrupts (regs == get_irq_regs()).
	 *
	 * Also save FPU registers for user-space tasks only.
	 */
	regs_user->regs = task_pt_regs(current);
	if (user_mode(regs_user->regs))
		save_fpu_regs();
	regs_user->abi = perf_reg_abi(current);
}

