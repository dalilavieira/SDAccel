#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct notifier_block {int dummy; } ;
struct TYPE_7__ {int /*<<< orphan*/  tp_value; } ;
struct TYPE_6__ {scalar_t__ mm; } ;

/* Variables and functions */
#define  CPU_PM_ENTER 130 
#define  CPU_PM_ENTER_FAILED 129 
#define  CPU_PM_EXIT 128 
 int NOTIFY_OK ; 
 int NOTIFY_STOP ; 
 int /*<<< orphan*/  __restore_watch (TYPE_1__*) ; 
 int /*<<< orphan*/  cpu_asid (unsigned int,scalar_t__) ; 
 scalar_t__ cpu_has_userlocal ; 
 TYPE_1__* current ; 
 TYPE_3__* current_thread_info () ; 
 int /*<<< orphan*/  lose_fpu (int) ; 
 int /*<<< orphan*/  restore_dsp (TYPE_1__*) ; 
 int /*<<< orphan*/  save_dsp (TYPE_1__*) ; 
 unsigned int smp_processor_id () ; 
 int /*<<< orphan*/  write_c0_entryhi (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  write_c0_userlocal (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int mips_cpu_save(void)
{
	/* Save FPU state */
	lose_fpu(1);

	/* Save DSP state */
	save_dsp(current);

	return 0;
}

__attribute__((used)) static void mips_cpu_restore(void)
{
	unsigned int cpu = smp_processor_id();

	/* Restore ASID */
	if (current->mm)
		write_c0_entryhi(cpu_asid(cpu, current->mm));

	/* Restore DSP state */
	restore_dsp(current);

	/* Restore UserLocal */
	if (cpu_has_userlocal)
		write_c0_userlocal(current_thread_info()->tp_value);

	/* Restore watch registers */
	__restore_watch(current);
}

__attribute__((used)) static int mips_pm_notifier(struct notifier_block *self, unsigned long cmd,
			    void *v)
{
	int ret;

	switch (cmd) {
	case CPU_PM_ENTER:
		ret = mips_cpu_save();
		if (ret)
			return NOTIFY_STOP;
		break;
	case CPU_PM_ENTER_FAILED:
	case CPU_PM_EXIT:
		mips_cpu_restore();
		break;
	}

	return NOTIFY_OK;
}

