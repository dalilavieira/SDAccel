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
typedef  int /*<<< orphan*/  u64 ;
struct notifier_block {int dummy; } ;
struct clocksource {int dummy; } ;
struct clock_event_device {char* name; int features; int rating; int /*<<< orphan*/  set_next_event; int /*<<< orphan*/  cpumask; int /*<<< orphan*/  irq; } ;
struct clk_notifier_data {scalar_t__ new_rate; } ;

/* Variables and functions */
 int CLOCK_EVT_FEAT_C3STOP ; 
 int CLOCK_EVT_FEAT_ONESHOT ; 
 int /*<<< orphan*/  CPUHP_AP_MIPS_GIC_TIMER_STARTING ; 
 int ENXIO ; 
 int /*<<< orphan*/  IRQ_TYPE_NONE ; 
 int NOTIFY_OK ; 
 unsigned long POST_RATE_CHANGE ; 
 int /*<<< orphan*/  clockevents_config_and_register (struct clock_event_device*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  clockevents_update_freq (struct clock_event_device*,unsigned long) ; 
 int /*<<< orphan*/  cpuhp_setup_state (int /*<<< orphan*/ ,char*,int (*) (unsigned int),int (*) (unsigned int)) ; 
 int /*<<< orphan*/  cpumask_of (unsigned int) ; 
 int /*<<< orphan*/  disable_percpu_irq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  enable_percpu_irq (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gic_clockevent_device ; 
 int /*<<< orphan*/  gic_compare_irqaction ; 
 int /*<<< orphan*/  gic_frequency ; 
 int /*<<< orphan*/  gic_next_event ; 
 int /*<<< orphan*/  gic_read_count () ; 
 int /*<<< orphan*/  gic_timer_irq ; 
 int /*<<< orphan*/  on_each_cpu (void (*) (void*),void*,int) ; 
 int /*<<< orphan*/  pr_err (char*,int /*<<< orphan*/ ,int) ; 
 int setup_percpu_irq (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct clock_event_device* this_cpu_ptr (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void gic_clockevent_cpu_init(unsigned int cpu,
				    struct clock_event_device *cd)
{
	cd->name		= "MIPS GIC";
	cd->features		= CLOCK_EVT_FEAT_ONESHOT |
				  CLOCK_EVT_FEAT_C3STOP;

	cd->rating		= 350;
	cd->irq			= gic_timer_irq;
	cd->cpumask		= cpumask_of(cpu);
	cd->set_next_event	= gic_next_event;

	clockevents_config_and_register(cd, gic_frequency, 0x300, 0x7fffffff);

	enable_percpu_irq(gic_timer_irq, IRQ_TYPE_NONE);
}

__attribute__((used)) static void gic_clockevent_cpu_exit(struct clock_event_device *cd)
{
	disable_percpu_irq(gic_timer_irq);
}

__attribute__((used)) static void gic_update_frequency(void *data)
{
	unsigned long rate = (unsigned long)data;

	clockevents_update_freq(this_cpu_ptr(&gic_clockevent_device), rate);
}

__attribute__((used)) static int gic_starting_cpu(unsigned int cpu)
{
	gic_clockevent_cpu_init(cpu, this_cpu_ptr(&gic_clockevent_device));
	return 0;
}

__attribute__((used)) static int gic_clk_notifier(struct notifier_block *nb, unsigned long action,
			    void *data)
{
	struct clk_notifier_data *cnd = data;

	if (action == POST_RATE_CHANGE)
		on_each_cpu(gic_update_frequency, (void *)cnd->new_rate, 1);

	return NOTIFY_OK;
}

__attribute__((used)) static int gic_dying_cpu(unsigned int cpu)
{
	gic_clockevent_cpu_exit(this_cpu_ptr(&gic_clockevent_device));
	return 0;
}

__attribute__((used)) static int gic_clockevent_init(void)
{
	int ret;

	if (!gic_frequency)
		return -ENXIO;

	ret = setup_percpu_irq(gic_timer_irq, &gic_compare_irqaction);
	if (ret < 0) {
		pr_err("IRQ %d setup failed (%d)\n", gic_timer_irq, ret);
		return ret;
	}

	cpuhp_setup_state(CPUHP_AP_MIPS_GIC_TIMER_STARTING,
			  "clockevents/mips/gic/timer:starting",
			  gic_starting_cpu, gic_dying_cpu);
	return 0;
}

__attribute__((used)) static u64 gic_hpt_read(struct clocksource *cs)
{
	return gic_read_count();
}

