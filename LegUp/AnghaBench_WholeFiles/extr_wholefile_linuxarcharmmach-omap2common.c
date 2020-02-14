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
typedef  enum reboot_mode { ____Placeholder_reboot_mode } reboot_mode ;

/* Variables and functions */
 int /*<<< orphan*/  cpu_do_idle () ; 

__attribute__((used)) static inline int omap2_pm_init(void)
{
	return 0;
}

__attribute__((used)) static inline int omap3_pm_init(void)
{
	return 0;
}

__attribute__((used)) static inline int omap4_pm_init(void)
{
	return 0;
}

__attribute__((used)) static inline int omap4_pm_init_early(void)
{
	return 0;
}

__attribute__((used)) static inline int amx3_common_pm_init(void)
{
	return 0;
}

__attribute__((used)) static inline int omap_l2_cache_init(void)
{
	return 0;
}

__attribute__((used)) static inline void omap_soc_device_init(void)
{
}

__attribute__((used)) static inline void omap2xxx_restart(enum reboot_mode mode, const char *cmd)
{
}

__attribute__((used)) static inline void am33xx_restart(enum reboot_mode mode, const char *cmd)
{
}

__attribute__((used)) static inline void omap3xxx_restart(enum reboot_mode mode, const char *cmd)
{
}

__attribute__((used)) static inline void ti81xx_restart(enum reboot_mode mode, const char *cmd)
{
}

__attribute__((used)) static inline void omap44xx_restart(enum reboot_mode mode, const char *cmd)
{
}

__attribute__((used)) static inline void omap_barrier_reserve_memblock(void)
{
}

__attribute__((used)) static inline int omap4_enter_lowpower(unsigned int cpu,
					unsigned int power_state)
{
	cpu_do_idle();
	return 0;
}

__attribute__((used)) static inline int omap4_hotplug_cpu(unsigned int cpu, unsigned int power_state)
{
	cpu_do_idle();
	return 0;
}

__attribute__((used)) static inline int omap4_mpuss_init(void)
{
	return 0;
}

__attribute__((used)) static inline void omap4_secondary_startup(void)
{
}

__attribute__((used)) static inline void omap4460_secondary_startup(void)
{
}

__attribute__((used)) static inline int omap4_finish_suspend(unsigned long cpu_state)
{
	return 0;
}

__attribute__((used)) static inline void omap4_cpu_resume(void)
{
}

__attribute__((used)) static inline void omap5_secondary_startup(void)
{
}

__attribute__((used)) static inline void omap5_secondary_hyp_startup(void)
{
}

__attribute__((used)) static inline void set_cntfreq(void)
{
}

