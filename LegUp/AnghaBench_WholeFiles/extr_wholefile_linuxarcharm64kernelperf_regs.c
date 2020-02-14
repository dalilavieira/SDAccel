#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int u64 ;
typedef  scalar_t__ u32 ;
struct task_struct {int dummy; } ;
struct pt_regs {int compat_sp; int compat_lr; int sp; int pc; int* regs; } ;
struct perf_regs {int abi; int /*<<< orphan*/  regs; } ;

/* Variables and functions */
 int EINVAL ; 
 scalar_t__ PERF_REG_ARM64_LR ; 
 scalar_t__ PERF_REG_ARM64_MAX ; 
 scalar_t__ PERF_REG_ARM64_PC ; 
 scalar_t__ PERF_REG_ARM64_SP ; 
 int PERF_SAMPLE_REGS_ABI_32 ; 
 int PERF_SAMPLE_REGS_ABI_64 ; 
 int REG_RESERVED ; 
 scalar_t__ WARN_ON_ONCE (int) ; 
 scalar_t__ compat_user_mode (struct pt_regs*) ; 
 struct task_struct* current ; 
 scalar_t__ is_compat_thread (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  task_pt_regs (struct task_struct*) ; 
 int /*<<< orphan*/  task_thread_info (struct task_struct*) ; 

u64 perf_reg_value(struct pt_regs *regs, int idx)
{
	if (WARN_ON_ONCE((u32)idx >= PERF_REG_ARM64_MAX))
		return 0;

	/*
	 * Compat (i.e. 32 bit) mode:
	 * - PC has been set in the pt_regs struct in kernel_entry,
	 * - Handle SP and LR here.
	 */
	if (compat_user_mode(regs)) {
		if ((u32)idx == PERF_REG_ARM64_SP)
			return regs->compat_sp;
		if ((u32)idx == PERF_REG_ARM64_LR)
			return regs->compat_lr;
	}

	if ((u32)idx == PERF_REG_ARM64_SP)
		return regs->sp;

	if ((u32)idx == PERF_REG_ARM64_PC)
		return regs->pc;

	return regs->regs[idx];
}

int perf_reg_validate(u64 mask)
{
	if (!mask || mask & REG_RESERVED)
		return -EINVAL;

	return 0;
}

u64 perf_reg_abi(struct task_struct *task)
{
	if (is_compat_thread(task_thread_info(task)))
		return PERF_SAMPLE_REGS_ABI_32;
	else
		return PERF_SAMPLE_REGS_ABI_64;
}

void perf_get_regs_user(struct perf_regs *regs_user,
			struct pt_regs *regs,
			struct pt_regs *regs_user_copy)
{
	regs_user->regs = task_pt_regs(current);
	regs_user->abi = perf_reg_abi(current);
}

