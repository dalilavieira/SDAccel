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
 int /*<<< orphan*/  lubbock_set_hexled (int) ; 
 int /*<<< orphan*/  pr_debug (char*) ; 
 TYPE_1__* pxa_cpu_pm_fns ; 
 scalar_t__* sleep_save ; 
 int /*<<< orphan*/  stub1 (scalar_t__*) ; 
 int /*<<< orphan*/  stub2 (scalar_t__) ; 
 int /*<<< orphan*/  stub3 (scalar_t__) ; 
 int /*<<< orphan*/  stub4 (scalar_t__*) ; 
 int stub5 (scalar_t__) ; 
 int stub6 () ; 
 int /*<<< orphan*/  stub7 () ; 

int pxa_pm_enter(suspend_state_t state)
{
	unsigned long sleep_save_checksum = 0, checksum = 0;
	int i;

#ifdef CONFIG_IWMMXT
	/* force any iWMMXt context to ram **/
	if (elf_hwcap & HWCAP_IWMMXT)
		iwmmxt_task_disable(NULL);
#endif

	/* skip registers saving for standby */
	if (state != PM_SUSPEND_STANDBY && pxa_cpu_pm_fns->save) {
		pxa_cpu_pm_fns->save(sleep_save);
		/* before sleeping, calculate and save a checksum */
		for (i = 0; i < pxa_cpu_pm_fns->save_count - 1; i++)
			sleep_save_checksum += sleep_save[i];
	}

	/* *** go zzz *** */
	pxa_cpu_pm_fns->enter(state);

	if (state != PM_SUSPEND_STANDBY && pxa_cpu_pm_fns->restore) {
		/* after sleeping, validate the checksum */
		for (i = 0; i < pxa_cpu_pm_fns->save_count - 1; i++)
			checksum += sleep_save[i];

		/* if invalid, display message and wait for a hardware reset */
		if (checksum != sleep_save_checksum) {

			lubbock_set_hexled(0xbadbadc5);

			while (1)
				pxa_cpu_pm_fns->enter(state);
		}
		pxa_cpu_pm_fns->restore(sleep_save);
	}

	pr_debug("*** made it back from resume\n");

	return 0;
}

__attribute__((used)) static int pxa_pm_valid(suspend_state_t state)
{
	if (pxa_cpu_pm_fns)
		return pxa_cpu_pm_fns->valid(state);

	return -EINVAL;
}

int pxa_pm_prepare(void)
{
	int ret = 0;

	if (pxa_cpu_pm_fns && pxa_cpu_pm_fns->prepare)
		ret = pxa_cpu_pm_fns->prepare();

	return ret;
}

void pxa_pm_finish(void)
{
	if (pxa_cpu_pm_fns && pxa_cpu_pm_fns->finish)
		pxa_cpu_pm_fns->finish();
}

