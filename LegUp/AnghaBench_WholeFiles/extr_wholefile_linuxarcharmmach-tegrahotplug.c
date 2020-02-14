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

/* Variables and functions */
 int /*<<< orphan*/  BUG () ; 
 int /*<<< orphan*/  TEGRA_FLUSH_CACHE_LOUIS ; 
 int /*<<< orphan*/  WARN (int,char*) ; 
 unsigned int cpu_logical_map (unsigned int) ; 
 int /*<<< orphan*/  tegra_disable_clean_inv_dcache (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  tegra_disable_cpu_clock (unsigned int) ; 
 int /*<<< orphan*/  tegra_hotplug_shutdown () ; 
 int /*<<< orphan*/  tegra_wait_cpu_in_reset (unsigned int) ; 

__attribute__((used)) static inline void tegra20_cpu_set_resettable_soon(void) {}

int tegra_cpu_kill(unsigned cpu)
{
	cpu = cpu_logical_map(cpu);

	/* Clock gate the CPU */
	tegra_wait_cpu_in_reset(cpu);
	tegra_disable_cpu_clock(cpu);

	return 1;
}

void tegra_cpu_die(unsigned int cpu)
{
	if (!tegra_hotplug_shutdown) {
		WARN(1, "hotplug is not yet initialized\n");
		return;
	}

	/* Clean L1 data cache */
	tegra_disable_clean_inv_dcache(TEGRA_FLUSH_CACHE_LOUIS);

	/* Shut down the current CPU. */
	tegra_hotplug_shutdown();

	/* Should never return here. */
	BUG();
}

