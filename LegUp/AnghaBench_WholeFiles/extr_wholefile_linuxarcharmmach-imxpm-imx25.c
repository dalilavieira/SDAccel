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
typedef  int suspend_state_t ;

/* Variables and functions */
 int /*<<< orphan*/  CONFIG_PM ; 
 int EINVAL ; 
 int /*<<< orphan*/  IS_ENABLED (int /*<<< orphan*/ ) ; 
#define  PM_SUSPEND_MEM 128 
 int /*<<< orphan*/  cpu_do_idle () ; 

__attribute__((used)) static int imx25_suspend_enter(suspend_state_t state)
{
	if (!IS_ENABLED(CONFIG_PM))
		return 0;

	switch (state) {
	case PM_SUSPEND_MEM:
		cpu_do_idle();
		break;
	default:
		return -EINVAL;
	}

	return 0;
}

