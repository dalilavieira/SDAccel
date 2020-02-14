#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct ti_sysc_cookie {int /*<<< orphan*/  data; } ;
struct TYPE_3__ {struct omap_device* od; } ;
struct platform_device {TYPE_1__ archdata; } ;
struct pdata_init {int /*<<< orphan*/  (* fn ) () ;scalar_t__ compatible; } ;
struct omap_device {int dummy; } ;
struct omap2_hsmmc_info {int dummy; } ;
struct device {int /*<<< orphan*/ * platform_data; } ;
typedef  enum reboot_mode { ____Placeholder_reboot_mode } reboot_mode ;
struct TYPE_4__ {int irq; void (* rearm ) () ;} ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  cpu_do_idle () ; 
 int /*<<< orphan*/  dev_name (struct device*) ; 
 scalar_t__ of_machine_is_compatible (scalar_t__) ; 
 int omap_hwmod_enable (int /*<<< orphan*/ ) ; 
 int omap_hwmod_idle (int /*<<< orphan*/ ) ; 
 int omap_hwmod_shutdown (int /*<<< orphan*/ ) ; 
 scalar_t__ omap_rev () ; 
 TYPE_2__ pcs_pdata ; 
 scalar_t__ strcmp (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 () ; 
 int /*<<< orphan*/  twl_gpio_auxdata ; 

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

__attribute__((used)) static inline struct omap_device *to_omap_device(struct platform_device *pdev)
{
	return pdev ? pdev->archdata.od : NULL;
}

__attribute__((used)) static inline void set_cntfreq(void)
{
}

__attribute__((used)) static inline int soc_is_omap(void)
{
	return omap_rev() != 0;
}

__attribute__((used)) static inline void omap_hsmmc_init(struct omap2_hsmmc_info *info)
{
}

__attribute__((used)) static inline void omap_hsmmc_late_init(struct omap2_hsmmc_info *info)
{
}

__attribute__((used)) static int ti_sysc_enable_module(struct device *dev,
				 const struct ti_sysc_cookie *cookie)
{
	if (!cookie->data)
		return -EINVAL;

	return omap_hwmod_enable(cookie->data);
}

__attribute__((used)) static int ti_sysc_idle_module(struct device *dev,
			       const struct ti_sysc_cookie *cookie)
{
	if (!cookie->data)
		return -EINVAL;

	return omap_hwmod_idle(cookie->data);
}

__attribute__((used)) static int ti_sysc_shutdown_module(struct device *dev,
				   const struct ti_sysc_cookie *cookie)
{
	if (!cookie->data)
		return -EINVAL;

	return omap_hwmod_shutdown(cookie->data);
}

void omap_pcs_legacy_init(int irq, void (*rearm)(void))
{
	pcs_pdata.irq = irq;
	pcs_pdata.rearm = rearm;
}

void omap_auxdata_legacy_init(struct device *dev)
{
	if (dev->platform_data)
		return;

	if (strcmp("twl4030-gpio", dev_name(dev)))
		return;

	dev->platform_data = &twl_gpio_auxdata;
}

__attribute__((used)) static void pdata_quirks_check(struct pdata_init *quirks)
{
	while (quirks->compatible) {
		if (of_machine_is_compatible(quirks->compatible)) {
			if (quirks->fn)
				quirks->fn();
		}
		quirks++;
	}
}

