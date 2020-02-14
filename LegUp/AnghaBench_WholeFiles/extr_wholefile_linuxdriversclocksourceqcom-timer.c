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
typedef  unsigned long u32 ;
struct clock_event_device {char* name; int rating; int (* set_state_shutdown ) (struct clock_event_device*) ;int (* set_state_oneshot ) (struct clock_event_device*) ;int (* tick_resume ) (struct clock_event_device*) ;int (* set_next_event ) (unsigned long,struct clock_event_device*) ;int /*<<< orphan*/  irq; int /*<<< orphan*/  cpumask; int /*<<< orphan*/  features; int /*<<< orphan*/  (* event_handler ) (struct clock_event_device*) ;} ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  CLOCK_EVT_FEAT_ONESHOT ; 
 int /*<<< orphan*/  GPT_HZ ; 
 int IRQF_NOBALANCING ; 
 int IRQF_TIMER ; 
 int IRQF_TRIGGER_RISING ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_TYPE_EDGE_RISING ; 
 scalar_t__ TIMER_CLEAR ; 
 scalar_t__ TIMER_ENABLE ; 
 unsigned long TIMER_ENABLE_CLR_ON_MATCH_EN ; 
 unsigned long TIMER_ENABLE_EN ; 
 scalar_t__ TIMER_MATCH_VAL ; 
 int TIMER_STS_GPT0_CLR_PEND ; 
 scalar_t__ clockevent_state_oneshot (struct clock_event_device*) ; 
 int /*<<< orphan*/  clockevents_config_and_register (struct clock_event_device*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  cpu_relax () ; 
 int /*<<< orphan*/  cpumask_of (unsigned int) ; 
 int /*<<< orphan*/  disable_percpu_irq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  enable_percpu_irq (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ event_base ; 
 int /*<<< orphan*/  msm_evt ; 
 scalar_t__ msm_timer_has_ppi ; 
 int /*<<< orphan*/  msm_timer_irq ; 
 struct clock_event_device* per_cpu_ptr (int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int readl_relaxed (scalar_t__) ; 
 int request_irq (int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (int,void*),int,char*,struct clock_event_device*) ; 
 scalar_t__ sts_base ; 
 int /*<<< orphan*/  stub1 (struct clock_event_device*) ; 
 int stub2 (struct clock_event_device*) ; 
 int /*<<< orphan*/  writel_relaxed (unsigned long,scalar_t__) ; 

__attribute__((used)) static irqreturn_t msm_timer_interrupt(int irq, void *dev_id)
{
	struct clock_event_device *evt = dev_id;
	/* Stop the timer tick */
	if (clockevent_state_oneshot(evt)) {
		u32 ctrl = readl_relaxed(event_base + TIMER_ENABLE);
		ctrl &= ~TIMER_ENABLE_EN;
		writel_relaxed(ctrl, event_base + TIMER_ENABLE);
	}
	evt->event_handler(evt);
	return IRQ_HANDLED;
}

__attribute__((used)) static int msm_timer_set_next_event(unsigned long cycles,
				    struct clock_event_device *evt)
{
	u32 ctrl = readl_relaxed(event_base + TIMER_ENABLE);

	ctrl &= ~TIMER_ENABLE_EN;
	writel_relaxed(ctrl, event_base + TIMER_ENABLE);

	writel_relaxed(ctrl, event_base + TIMER_CLEAR);
	writel_relaxed(cycles, event_base + TIMER_MATCH_VAL);

	if (sts_base)
		while (readl_relaxed(sts_base) & TIMER_STS_GPT0_CLR_PEND)
			cpu_relax();

	writel_relaxed(ctrl | TIMER_ENABLE_EN, event_base + TIMER_ENABLE);
	return 0;
}

__attribute__((used)) static int msm_timer_shutdown(struct clock_event_device *evt)
{
	u32 ctrl;

	ctrl = readl_relaxed(event_base + TIMER_ENABLE);
	ctrl &= ~(TIMER_ENABLE_EN | TIMER_ENABLE_CLR_ON_MATCH_EN);
	writel_relaxed(ctrl, event_base + TIMER_ENABLE);
	return 0;
}

__attribute__((used)) static int msm_local_timer_starting_cpu(unsigned int cpu)
{
	struct clock_event_device *evt = per_cpu_ptr(msm_evt, cpu);
	int err;

	evt->irq = msm_timer_irq;
	evt->name = "msm_timer";
	evt->features = CLOCK_EVT_FEAT_ONESHOT;
	evt->rating = 200;
	evt->set_state_shutdown = msm_timer_shutdown;
	evt->set_state_oneshot = msm_timer_shutdown;
	evt->tick_resume = msm_timer_shutdown;
	evt->set_next_event = msm_timer_set_next_event;
	evt->cpumask = cpumask_of(cpu);

	clockevents_config_and_register(evt, GPT_HZ, 4, 0xffffffff);

	if (msm_timer_has_ppi) {
		enable_percpu_irq(evt->irq, IRQ_TYPE_EDGE_RISING);
	} else {
		err = request_irq(evt->irq, msm_timer_interrupt,
				IRQF_TIMER | IRQF_NOBALANCING |
				IRQF_TRIGGER_RISING, "gp_timer", evt);
		if (err)
			pr_err("request_irq failed\n");
	}

	return 0;
}

__attribute__((used)) static int msm_local_timer_dying_cpu(unsigned int cpu)
{
	struct clock_event_device *evt = per_cpu_ptr(msm_evt, cpu);

	evt->set_state_shutdown(evt);
	disable_percpu_irq(evt->irq);
	return 0;
}

