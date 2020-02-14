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
struct task_struct {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  CONFIG_ARCH_TEGRA_114_SOC ; 
 int /*<<< orphan*/  CONFIG_ARCH_TEGRA_124_SOC ; 
 int /*<<< orphan*/  CONFIG_ARCH_TEGRA_2x_SOC ; 
 int /*<<< orphan*/  CONFIG_ARCH_TEGRA_3x_SOC ; 
 int EINVAL ; 
 int FLOW_CTRL_SCLK_RESUME ; 
 int FLOW_CTRL_WAITEVENT ; 
 scalar_t__ IS_ENABLED (int /*<<< orphan*/ ) ; 
 scalar_t__ TEGRA114 ; 
 scalar_t__ TEGRA124 ; 
 scalar_t__ TEGRA20 ; 
 scalar_t__ TEGRA30 ; 
 unsigned int cpu_logical_map (unsigned int) ; 
 int /*<<< orphan*/  cpumask_set_cpu (unsigned int,int /*<<< orphan*/ *) ; 
 scalar_t__ cpumask_test_cpu (unsigned int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  flowctrl_write_cpu_csr (unsigned int,int) ; 
 int /*<<< orphan*/  flowctrl_write_cpu_halt (unsigned int,int) ; 
 unsigned long jiffies ; 
 unsigned long msecs_to_jiffies (int) ; 
 int /*<<< orphan*/  tegra_cpu_init_mask ; 
 int /*<<< orphan*/  tegra_cpu_out_of_reset (unsigned int) ; 
 int /*<<< orphan*/  tegra_enable_cpu_clock (unsigned int) ; 
 scalar_t__ tegra_get_chip_id () ; 
 scalar_t__ tegra_pmc_cpu_is_powered (unsigned int) ; 
 int tegra_pmc_cpu_power_on (unsigned int) ; 
 int tegra_pmc_cpu_remove_clamping (unsigned int) ; 
 int /*<<< orphan*/  tegra_put_cpu_in_reset (unsigned int) ; 
 scalar_t__ time_before (unsigned long,unsigned long) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static void tegra_secondary_init(unsigned int cpu)
{
	cpumask_set_cpu(cpu, &tegra_cpu_init_mask);
}

__attribute__((used)) static int tegra20_boot_secondary(unsigned int cpu, struct task_struct *idle)
{
	cpu = cpu_logical_map(cpu);

	/*
	 * Force the CPU into reset. The CPU must remain in reset when
	 * the flow controller state is cleared (which will cause the
	 * flow controller to stop driving reset if the CPU has been
	 * power-gated via the flow controller). This will have no
	 * effect on first boot of the CPU since it should already be
	 * in reset.
	 */
	tegra_put_cpu_in_reset(cpu);

	/*
	 * Unhalt the CPU. If the flow controller was used to
	 * power-gate the CPU this will cause the flow controller to
	 * stop driving reset. The CPU will remain in reset because the
	 * clock and reset block is now driving reset.
	 */
	flowctrl_write_cpu_halt(cpu, 0);

	tegra_enable_cpu_clock(cpu);
	flowctrl_write_cpu_csr(cpu, 0); /* Clear flow controller CSR. */
	tegra_cpu_out_of_reset(cpu);
	return 0;
}

__attribute__((used)) static int tegra30_boot_secondary(unsigned int cpu, struct task_struct *idle)
{
	int ret;
	unsigned long timeout;

	cpu = cpu_logical_map(cpu);
	tegra_put_cpu_in_reset(cpu);
	flowctrl_write_cpu_halt(cpu, 0);

	/*
	 * The power up sequence of cold boot CPU and warm boot CPU
	 * was different.
	 *
	 * For warm boot CPU that was resumed from CPU hotplug, the
	 * power will be resumed automatically after un-halting the
	 * flow controller of the warm boot CPU. We need to wait for
	 * the confirmaiton that the CPU is powered then removing
	 * the IO clamps.
	 * For cold boot CPU, do not wait. After the cold boot CPU be
	 * booted, it will run to tegra_secondary_init() and set
	 * tegra_cpu_init_mask which influences what tegra30_boot_secondary()
	 * next time around.
	 */
	if (cpumask_test_cpu(cpu, &tegra_cpu_init_mask)) {
		timeout = jiffies + msecs_to_jiffies(50);
		do {
			if (tegra_pmc_cpu_is_powered(cpu))
				goto remove_clamps;
			udelay(10);
		} while (time_before(jiffies, timeout));
	}

	/*
	 * The power status of the cold boot CPU is power gated as
	 * default. To power up the cold boot CPU, the power should
	 * be un-gated by un-toggling the power gate register
	 * manually.
	 */
	ret = tegra_pmc_cpu_power_on(cpu);
	if (ret)
		return ret;

remove_clamps:
	/* CPU partition is powered. Enable the CPU clock. */
	tegra_enable_cpu_clock(cpu);
	udelay(10);

	/* Remove I/O clamps. */
	ret = tegra_pmc_cpu_remove_clamping(cpu);
	if (ret)
		return ret;

	udelay(10);

	flowctrl_write_cpu_csr(cpu, 0); /* Clear flow controller CSR. */
	tegra_cpu_out_of_reset(cpu);
	return 0;
}

__attribute__((used)) static int tegra114_boot_secondary(unsigned int cpu, struct task_struct *idle)
{
	int ret = 0;

	cpu = cpu_logical_map(cpu);

	if (cpumask_test_cpu(cpu, &tegra_cpu_init_mask)) {
		/*
		 * Warm boot flow
		 * The flow controller in charge of the power state and
		 * control for each CPU.
		 */
		/* set SCLK as event trigger for flow controller */
		flowctrl_write_cpu_csr(cpu, 1);
		flowctrl_write_cpu_halt(cpu,
				FLOW_CTRL_WAITEVENT | FLOW_CTRL_SCLK_RESUME);
	} else {
		/*
		 * Cold boot flow
		 * The CPU is powered up by toggling PMC directly. It will
		 * also initial power state in flow controller. After that,
		 * the CPU's power state is maintained by flow controller.
		 */
		ret = tegra_pmc_cpu_power_on(cpu);
	}

	return ret;
}

__attribute__((used)) static int tegra_boot_secondary(unsigned int cpu,
					  struct task_struct *idle)
{
	if (IS_ENABLED(CONFIG_ARCH_TEGRA_2x_SOC) && tegra_get_chip_id() == TEGRA20)
		return tegra20_boot_secondary(cpu, idle);
	if (IS_ENABLED(CONFIG_ARCH_TEGRA_3x_SOC) && tegra_get_chip_id() == TEGRA30)
		return tegra30_boot_secondary(cpu, idle);
	if (IS_ENABLED(CONFIG_ARCH_TEGRA_114_SOC) && tegra_get_chip_id() == TEGRA114)
		return tegra114_boot_secondary(cpu, idle);
	if (IS_ENABLED(CONFIG_ARCH_TEGRA_124_SOC) && tegra_get_chip_id() == TEGRA124)
		return tegra114_boot_secondary(cpu, idle);

	return -EINVAL;
}

