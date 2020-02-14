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
struct clock_event_device {int /*<<< orphan*/  (* event_handler ) (struct clock_event_device*) ;} ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int COUNTER_BIT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  NETX_GPIO_COUNTER_CTRL (int /*<<< orphan*/ ) ; 
 int NETX_GPIO_COUNTER_CTRL_IRQ_EN ; 
 int NETX_GPIO_COUNTER_CTRL_RST_EN ; 
 int NETX_GPIO_COUNTER_CTRL_RUN ; 
 int /*<<< orphan*/  NETX_GPIO_COUNTER_CURRENT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NETX_GPIO_COUNTER_MAX (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NETX_GPIO_IRQ ; 
 int NETX_LATCH ; 
 int /*<<< orphan*/  TIMER_CLOCKEVENT ; 
 struct clock_event_device netx_clockevent ; 
 int /*<<< orphan*/  stub1 (struct clock_event_device*) ; 
 int /*<<< orphan*/  writel (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void timer_shutdown(struct clock_event_device *evt)
{
	/* disable timer */
	writel(0, NETX_GPIO_COUNTER_CTRL(TIMER_CLOCKEVENT));
}

__attribute__((used)) static int netx_shutdown(struct clock_event_device *evt)
{
	timer_shutdown(evt);

	return 0;
}

__attribute__((used)) static int netx_set_oneshot(struct clock_event_device *evt)
{
	u32 tmode = NETX_GPIO_COUNTER_CTRL_IRQ_EN | NETX_GPIO_COUNTER_CTRL_RUN;

	timer_shutdown(evt);
	writel(0, NETX_GPIO_COUNTER_MAX(TIMER_CLOCKEVENT));
	writel(tmode, NETX_GPIO_COUNTER_CTRL(TIMER_CLOCKEVENT));

	return 0;
}

__attribute__((used)) static int netx_set_periodic(struct clock_event_device *evt)
{
	u32 tmode = NETX_GPIO_COUNTER_CTRL_RST_EN |
		    NETX_GPIO_COUNTER_CTRL_IRQ_EN | NETX_GPIO_COUNTER_CTRL_RUN;

	timer_shutdown(evt);
	writel(NETX_LATCH, NETX_GPIO_COUNTER_MAX(TIMER_CLOCKEVENT));
	writel(tmode, NETX_GPIO_COUNTER_CTRL(TIMER_CLOCKEVENT));

	return 0;
}

__attribute__((used)) static int netx_set_next_event(unsigned long evt,
		struct clock_event_device *clk)
{
	writel(0 - evt, NETX_GPIO_COUNTER_CURRENT(TIMER_CLOCKEVENT));
	return 0;
}

__attribute__((used)) static irqreturn_t
netx_timer_interrupt(int irq, void *dev_id)
{
	struct clock_event_device *evt = &netx_clockevent;

	/* acknowledge interrupt */
	writel(COUNTER_BIT(0), NETX_GPIO_IRQ);

	evt->event_handler(evt);

	return IRQ_HANDLED;
}

