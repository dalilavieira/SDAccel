#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ suspend_state_t ;
struct TYPE_2__ {int save_count; int (* valid ) (scalar_t__) ;int (* prepare ) () ;int /*<<< orphan*/  (* finish ) () ;int /*<<< orphan*/  (* restore ) (scalar_t__*) ;int /*<<< orphan*/  (* enter ) (scalar_t__) ;int /*<<< orphan*/  (* save ) (scalar_t__*) ;} ;

/* Variables and functions */
 int EINVAL ; 
 scalar_t__ PM_SUSPEND_STANDBY ; 
 int /*<<< orphan*/  cpu_init () ; 
 int /*<<< orphan*/  pr_debug (char*) ; 
 TYPE_1__* puv3_cpu_pm_fns ; 
 scalar_t__* sleep_save ; 
 int /*<<< orphan*/  stub1 (scalar_t__*) ; 
 int /*<<< orphan*/  stub2 (scalar_t__) ; 
 int /*<<< orphan*/  stub3 (scalar_t__) ; 
 int /*<<< orphan*/  stub4 (scalar_t__*) ; 
 int stub5 (scalar_t__) ; 
 int stub6 () ; 
 int /*<<< orphan*/  stub7 () ; 
 unsigned long virt_to_phys (void*) ; 

int puv3_pm_enter(suspend_state_t state)
{
	unsigned long sleep_save_checksum = 0, checksum = 0;
	int i;

	/* skip registers saving for standby */
	if (state != PM_SUSPEND_STANDBY) {
		puv3_cpu_pm_fns->save(sleep_save);
		/* before sleeping, calculate and save a checksum */
		for (i = 0; i < puv3_cpu_pm_fns->save_count - 1; i++)
			sleep_save_checksum += sleep_save[i];
	}

	/* *** go zzz *** */
	puv3_cpu_pm_fns->enter(state);
	cpu_init();
#ifdef CONFIG_INPUT_KEYBOARD
	puv3_ps2_init();
#endif
#ifdef CONFIG_PCI
	pci_puv3_preinit();
#endif
	if (state != PM_SUSPEND_STANDBY) {
		/* after sleeping, validate the checksum */
		for (i = 0; i < puv3_cpu_pm_fns->save_count - 1; i++)
			checksum += sleep_save[i];

		/* if invalid, display message and wait for a hardware reset */
		if (checksum != sleep_save_checksum) {
			while (1)
				puv3_cpu_pm_fns->enter(state);
		}
		puv3_cpu_pm_fns->restore(sleep_save);
	}

	pr_debug("*** made it back from resume\n");

	return 0;
}

unsigned long sleep_phys_sp(void *sp)
{
	return virt_to_phys(sp);
}

__attribute__((used)) static int puv3_pm_valid(suspend_state_t state)
{
	if (puv3_cpu_pm_fns)
		return puv3_cpu_pm_fns->valid(state);

	return -EINVAL;
}

__attribute__((used)) static int puv3_pm_prepare(void)
{
	int ret = 0;

	if (puv3_cpu_pm_fns && puv3_cpu_pm_fns->prepare)
		ret = puv3_cpu_pm_fns->prepare();

	return ret;
}

__attribute__((used)) static void puv3_pm_finish(void)
{
	if (puv3_cpu_pm_fns && puv3_cpu_pm_fns->finish)
		puv3_cpu_pm_fns->finish();
}

