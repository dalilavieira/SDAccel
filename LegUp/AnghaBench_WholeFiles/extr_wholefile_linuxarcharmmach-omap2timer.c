#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u64 ;
typedef  int u32 ;
struct property {char* name; char* value; int /*<<< orphan*/  length; } ;
struct TYPE_10__ {struct omap_device* od; } ;
struct platform_device {TYPE_1__ archdata; } ;
struct omap_device {int dummy; } ;
struct device_node {struct device_node* parent; } ;
struct clocksource {int dummy; } ;
struct clock_event_device {int /*<<< orphan*/  (* event_handler ) (struct clock_event_device*) ;} ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  enum reboot_mode { ____Placeholder_reboot_mode } reboot_mode ;
struct TYPE_11__ {int rate; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HZ ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int OMAP_TIMER_CTRL_AR ; 
 int OMAP_TIMER_CTRL_ST ; 
 int /*<<< orphan*/  OMAP_TIMER_INT_OVERFLOW ; 
 int /*<<< orphan*/  OMAP_TIMER_LOAD_REG ; 
 int /*<<< orphan*/  OMAP_TIMER_NONPOSTED ; 
 int /*<<< orphan*/  OMAP_TIMER_POSTED ; 
 int /*<<< orphan*/  __omap_dm_timer_int_enable (TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __omap_dm_timer_load_start (TYPE_2__*,int,int,int /*<<< orphan*/ ) ; 
 int __omap_dm_timer_read_counter (TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __omap_dm_timer_stop (TYPE_2__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  __omap_dm_timer_write (TYPE_2__*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __omap_dm_timer_write_status (TYPE_2__*,int /*<<< orphan*/ ) ; 
 TYPE_2__ clkev ; 
 TYPE_2__ clksrc ; 
 struct clock_event_device clockevent_gpt ; 
 int /*<<< orphan*/  clockevent_gpt_hwmod ; 
 int /*<<< orphan*/  clocksource_gpt_hwmod ; 
 int /*<<< orphan*/  cpu_do_idle () ; 
 struct property* kzalloc (int,int /*<<< orphan*/ ) ; 
 int of_add_property (struct device_node*,struct property*) ; 
 int /*<<< orphan*/  of_device_is_compatible (struct device_node*,char*) ; 
 scalar_t__ of_get_property (struct device_node*,char*,int /*<<< orphan*/ *) ; 
 int omap2_gptimer_clksrc_load ; 
 int /*<<< orphan*/  omap_hwmod_enable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  omap_hwmod_idle (int /*<<< orphan*/ ) ; 
 scalar_t__ omap_rev () ; 
 int /*<<< orphan*/  strlen (char*) ; 
 int /*<<< orphan*/  stub1 (struct clock_event_device*) ; 

__attribute__((used)) static inline struct omap_device *to_omap_device(struct platform_device *pdev)
{
	return pdev ? pdev->archdata.od : NULL;
}

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

__attribute__((used)) static inline void set_cntfreq(void)
{
}

__attribute__((used)) static irqreturn_t omap2_gp_timer_interrupt(int irq, void *dev_id)
{
	struct clock_event_device *evt = &clockevent_gpt;

	__omap_dm_timer_write_status(&clkev, OMAP_TIMER_INT_OVERFLOW);

	evt->event_handler(evt);
	return IRQ_HANDLED;
}

__attribute__((used)) static int omap2_gp_timer_set_next_event(unsigned long cycles,
					 struct clock_event_device *evt)
{
	__omap_dm_timer_load_start(&clkev, OMAP_TIMER_CTRL_ST,
				   0xffffffff - cycles, OMAP_TIMER_POSTED);

	return 0;
}

__attribute__((used)) static int omap2_gp_timer_shutdown(struct clock_event_device *evt)
{
	__omap_dm_timer_stop(&clkev, OMAP_TIMER_POSTED, clkev.rate);
	return 0;
}

__attribute__((used)) static int omap2_gp_timer_set_periodic(struct clock_event_device *evt)
{
	u32 period;

	__omap_dm_timer_stop(&clkev, OMAP_TIMER_POSTED, clkev.rate);

	period = clkev.rate / HZ;
	period -= 1;
	/* Looks like we need to first set the load value separately */
	__omap_dm_timer_write(&clkev, OMAP_TIMER_LOAD_REG, 0xffffffff - period,
			      OMAP_TIMER_POSTED);
	__omap_dm_timer_load_start(&clkev,
				   OMAP_TIMER_CTRL_AR | OMAP_TIMER_CTRL_ST,
				   0xffffffff - period, OMAP_TIMER_POSTED);
	return 0;
}

__attribute__((used)) static void omap_clkevt_idle(struct clock_event_device *unused)
{
	if (!clockevent_gpt_hwmod)
		return;

	omap_hwmod_idle(clockevent_gpt_hwmod);
}

__attribute__((used)) static void omap_clkevt_unidle(struct clock_event_device *unused)
{
	if (!clockevent_gpt_hwmod)
		return;

	omap_hwmod_enable(clockevent_gpt_hwmod);
	__omap_dm_timer_int_enable(&clkev, OMAP_TIMER_INT_OVERFLOW);
}

__attribute__((used)) static int omap_timer_add_disabled_property(struct device_node *np)
{
	struct property *prop;

	prop = kzalloc(sizeof(*prop), GFP_KERNEL);
	if (!prop)
		return -ENOMEM;

	prop->name = "status";
	prop->value = "disabled";
	prop->length = strlen(prop->value);

	return of_add_property(np, prop);
}

__attribute__((used)) static int omap_timer_update_dt(struct device_node *np)
{
	int error = 0;

	if (!of_device_is_compatible(np, "ti,omap-counter32k")) {
		error = omap_timer_add_disabled_property(np);
		if (error)
			return error;
	}

	/* No parent interconnect target module configured? */
	if (of_get_property(np, "ti,hwmods", NULL))
		return error;

	/* Tag parent interconnect target module disabled */
	error = omap_timer_add_disabled_property(np->parent);
	if (error)
		return error;

	return 0;
}

__attribute__((used)) static u64 clocksource_read_cycles(struct clocksource *cs)
{
	return (u64)__omap_dm_timer_read_counter(&clksrc,
						     OMAP_TIMER_NONPOSTED);
}

__attribute__((used)) static void omap2_gptimer_clksrc_suspend(struct clocksource *unused)
{
	omap2_gptimer_clksrc_load =
		__omap_dm_timer_read_counter(&clksrc, OMAP_TIMER_NONPOSTED);

	omap_hwmod_idle(clocksource_gpt_hwmod);
}

__attribute__((used)) static void omap2_gptimer_clksrc_resume(struct clocksource *unused)
{
	omap_hwmod_enable(clocksource_gpt_hwmod);

	__omap_dm_timer_load_start(&clksrc,
				   OMAP_TIMER_CTRL_ST | OMAP_TIMER_CTRL_AR,
				   omap2_gptimer_clksrc_load,
				   OMAP_TIMER_NONPOSTED);
}

