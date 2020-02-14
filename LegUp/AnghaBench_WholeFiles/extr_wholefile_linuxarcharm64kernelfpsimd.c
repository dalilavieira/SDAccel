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
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct user_fpsimd_state {int /*<<< orphan*/  fpsr; } ;
struct TYPE_7__ {int /*<<< orphan*/ * sve_state; } ;
struct task_struct {TYPE_1__ thread; } ;
struct TYPE_10__ {int /*<<< orphan*/  fpsr; } ;
struct TYPE_8__ {TYPE_4__ fpsimd_state; } ;
struct TYPE_9__ {unsigned int sve_vl; TYPE_2__ uw; } ;
struct TYPE_12__ {TYPE_3__ thread; } ;
struct TYPE_11__ {int /*<<< orphan*/  st; } ;

/* Variables and functions */
 int /*<<< orphan*/  SIGKILL ; 
 int /*<<< orphan*/  SI_KERNEL ; 
 void* SVE_VL_MIN ; 
 unsigned int SVE_VQ_MAX ; 
 int /*<<< orphan*/  TIF_FOREIGN_FPSTATE ; 
 int /*<<< orphan*/  TIF_SVE ; 
 scalar_t__ WARN_ON (int) ; 
 struct user_fpsimd_state* __this_cpu_read (int /*<<< orphan*/ ) ; 
 TYPE_6__* current ; 
 int find_next_bit (int /*<<< orphan*/ ,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  force_signal_inject (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_5__ fpsimd_last_state ; 
 int /*<<< orphan*/  fpsimd_load_state (TYPE_4__*) ; 
 int /*<<< orphan*/  fpsimd_save_state (struct user_fpsimd_state*) ; 
 int /*<<< orphan*/  in_softirq () ; 
 int /*<<< orphan*/  irqs_disabled () ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ *) ; 
 scalar_t__ sve_get_vl () ; 
 int /*<<< orphan*/  sve_load_state (int /*<<< orphan*/ ,int /*<<< orphan*/ *,unsigned int) ; 
 int sve_max_vl ; 
 int /*<<< orphan*/  sve_pffr (TYPE_3__*) ; 
 int /*<<< orphan*/  sve_save_state (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 unsigned int sve_vl_from_vq (unsigned int) ; 
 int /*<<< orphan*/  sve_vl_valid (int) ; 
 unsigned int sve_vq_from_vl (unsigned int) ; 
 int /*<<< orphan*/  sve_vq_map ; 
 scalar_t__ system_supports_sve () ; 
 scalar_t__ test_thread_flag (int /*<<< orphan*/ ) ; 
 int test_tsk_thread_flag (struct task_struct*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void __sve_free(struct task_struct *task)
{
	kfree(task->thread.sve_state);
	task->thread.sve_state = NULL;
}

__attribute__((used)) static void sve_free(struct task_struct *task)
{
	WARN_ON(test_tsk_thread_flag(task, TIF_SVE));

	__sve_free(task);
}

__attribute__((used)) static void task_fpsimd_load(void)
{
	WARN_ON(!in_softirq() && !irqs_disabled());

	if (system_supports_sve() && test_thread_flag(TIF_SVE))
		sve_load_state(sve_pffr(&current->thread),
			       &current->thread.uw.fpsimd_state.fpsr,
			       sve_vq_from_vl(current->thread.sve_vl) - 1);
	else
		fpsimd_load_state(&current->thread.uw.fpsimd_state);
}

void fpsimd_save(void)
{
	struct user_fpsimd_state *st = __this_cpu_read(fpsimd_last_state.st);
	/* set by fpsimd_bind_task_to_cpu() or fpsimd_bind_state_to_cpu() */

	WARN_ON(!in_softirq() && !irqs_disabled());

	if (!test_thread_flag(TIF_FOREIGN_FPSTATE)) {
		if (system_supports_sve() && test_thread_flag(TIF_SVE)) {
			if (WARN_ON(sve_get_vl() != current->thread.sve_vl)) {
				/*
				 * Can't save the user regs, so current would
				 * re-enter user with corrupt state.
				 * There's no way to recover, so kill it:
				 */
				force_signal_inject(SIGKILL, SI_KERNEL, 0);
				return;
			}

			sve_save_state(sve_pffr(&current->thread), &st->fpsr);
		} else
			fpsimd_save_state(st);
	}
}

__attribute__((used)) static unsigned int vq_to_bit(unsigned int vq)
{
	return SVE_VQ_MAX - vq;
}

__attribute__((used)) static unsigned int bit_to_vq(unsigned int bit)
{
	if (WARN_ON(bit >= SVE_VQ_MAX))
		bit = SVE_VQ_MAX - 1;

	return SVE_VQ_MAX - bit;
}

__attribute__((used)) static unsigned int find_supported_vector_length(unsigned int vl)
{
	int bit;
	int max_vl = sve_max_vl;

	if (WARN_ON(!sve_vl_valid(vl)))
		vl = SVE_VL_MIN;

	if (WARN_ON(!sve_vl_valid(max_vl)))
		max_vl = SVE_VL_MIN;

	if (vl > max_vl)
		vl = max_vl;

	bit = find_next_bit(sve_vq_map, SVE_VQ_MAX,
			    vq_to_bit(sve_vq_from_vl(vl)));
	return sve_vl_from_vq(bit_to_vq(bit));
}

