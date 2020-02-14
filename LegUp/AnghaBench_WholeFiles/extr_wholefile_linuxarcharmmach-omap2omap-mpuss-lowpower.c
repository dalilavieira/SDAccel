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
typedef  scalar_t__ u32 ;
typedef  enum reboot_mode { ____Placeholder_reboot_mode } reboot_mode ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  cpu_do_idle () ; 
 scalar_t__ old_cpu1_ns_pa_addr ; 
 scalar_t__ omap_rev () ; 

__attribute__((used)) static inline int soc_is_omap(void)
{
	return omap_rev() != 0;
}

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

__attribute__((used)) static inline int omap3_idle_init(void)
{
	return 0;
}

__attribute__((used)) static inline int omap4_idle_init(void)
{
	return 0;
}

__attribute__((used)) static inline int omap3_opp_init(void)
{
	return -EINVAL;
}

__attribute__((used)) static inline int omap4_opp_init(void)
{
	return -EINVAL;
}

__attribute__((used)) static inline void enable_omap3630_toggle_l2_on_restore(void) { }

__attribute__((used)) static inline int omap_devinit_smartreflex(void)
{
	return -EINVAL;
}

__attribute__((used)) static inline void omap_enable_smartreflex_on_init(void) {}

__attribute__((used)) static inline int omap3_twl_init(void)
{
	return -EINVAL;
}

__attribute__((used)) static inline int omap4_twl_init(void)
{
	return -EINVAL;
}

__attribute__((used)) static inline void omap_pm_setup_oscillator(u32 tstart, u32 tshut) { }

__attribute__((used)) static inline void omap_pm_get_oscillator(u32 *tstart, u32 *tshut) { *tstart = *tshut = 0; }

__attribute__((used)) static inline void omap_pm_setup_sr_i2c_pcb_length(u32 mm) { }

__attribute__((used)) static inline void omap_common_suspend_init(void *pm_suspend)
{
}

u32 omap4_get_cpu1_ns_pa_addr(void)
{
	return old_cpu1_ns_pa_addr;
}

