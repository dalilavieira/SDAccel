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
typedef  int u32 ;
typedef  int suspend_state_t ;

/* Variables and functions */
 int EINVAL ; 
#define  PM_SUSPEND_STANDBY 128 
 int /*<<< orphan*/  cpu_do_idle () ; 
 int /*<<< orphan*/  ddr_operation_base ; 
 int /*<<< orphan*/  memory_pm_ctrl ; 
 int readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  writel_relaxed (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void kirkwood_pm_init(void) {}

__attribute__((used)) static void kirkwood_low_power(void)
{
	u32 mem_pm_ctrl;

	mem_pm_ctrl = readl(memory_pm_ctrl);

	/* Set peripherals to low-power mode */
	writel_relaxed(~0, memory_pm_ctrl);

	/* Set DDR in self-refresh */
	writel_relaxed(0x7, ddr_operation_base);

	/*
	 * Set CPU in wait-for-interrupt state.
	 * This disables the CPU core clocks,
	 * the array clocks, and also the L2 controller.
	 */
	cpu_do_idle();

	writel_relaxed(mem_pm_ctrl, memory_pm_ctrl);
}

__attribute__((used)) static int kirkwood_suspend_enter(suspend_state_t state)
{
	switch (state) {
	case PM_SUSPEND_STANDBY:
		kirkwood_low_power();
		break;
	default:
		return -EINVAL;
	}
	return 0;
}

__attribute__((used)) static int kirkwood_pm_valid_standby(suspend_state_t state)
{
	return state == PM_SUSPEND_STANDBY;
}

