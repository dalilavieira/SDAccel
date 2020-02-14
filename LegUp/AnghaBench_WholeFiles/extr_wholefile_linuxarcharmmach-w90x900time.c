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
struct clock_event_device {int /*<<< orphan*/  (* event_handler ) (struct clock_event_device*) ;} ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 unsigned int COUNTEN ; 
 unsigned int INTEN ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 unsigned int ONESHOT ; 
 unsigned int PERIOD ; 
 unsigned int PRESCALE ; 
 int /*<<< orphan*/  REG_TCSR0 ; 
 int /*<<< orphan*/  REG_TICR0 ; 
 int /*<<< orphan*/  REG_TISR ; 
 int __raw_readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __raw_writel (int,int /*<<< orphan*/ ) ; 
 struct clock_event_device nuc900_clockevent_device ; 
 int /*<<< orphan*/  stub1 (struct clock_event_device*) ; 
 int timer0_load ; 

__attribute__((used)) static int nuc900_clockevent_shutdown(struct clock_event_device *evt)
{
	unsigned int val = __raw_readl(REG_TCSR0) & ~(0x03 << 27);

	__raw_writel(val, REG_TCSR0);
	return 0;
}

__attribute__((used)) static int nuc900_clockevent_set_oneshot(struct clock_event_device *evt)
{
	unsigned int val = __raw_readl(REG_TCSR0) & ~(0x03 << 27);

	val |= (ONESHOT | COUNTEN | INTEN | PRESCALE);

	__raw_writel(val, REG_TCSR0);
	return 0;
}

__attribute__((used)) static int nuc900_clockevent_set_periodic(struct clock_event_device *evt)
{
	unsigned int val = __raw_readl(REG_TCSR0) & ~(0x03 << 27);

	__raw_writel(timer0_load, REG_TICR0);
	val |= (PERIOD | COUNTEN | INTEN | PRESCALE);
	__raw_writel(val, REG_TCSR0);
	return 0;
}

__attribute__((used)) static int nuc900_clockevent_setnextevent(unsigned long evt,
		struct clock_event_device *clk)
{
	unsigned int val;

	__raw_writel(evt, REG_TICR0);

	val = __raw_readl(REG_TCSR0);
	val |= (COUNTEN | INTEN | PRESCALE);
	__raw_writel(val, REG_TCSR0);

	return 0;
}

__attribute__((used)) static irqreturn_t nuc900_timer0_interrupt(int irq, void *dev_id)
{
	struct clock_event_device *evt = &nuc900_clockevent_device;

	__raw_writel(0x01, REG_TISR); /* clear TIF0 */

	evt->event_handler(evt);
	return IRQ_HANDLED;
}

