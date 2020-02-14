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
typedef  unsigned long u64 ;
struct clocksource {int dummy; } ;
struct clock_event_device {int /*<<< orphan*/  (* event_handler ) (struct clock_event_device*) ;} ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int ETIME ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int MIN_OSCR_DELTA ; 
 int /*<<< orphan*/  OST_OIER ; 
 unsigned long OST_OIER_E0 ; 
 int /*<<< orphan*/  OST_OSCR ; 
 int /*<<< orphan*/  OST_OSMR0 ; 
 int /*<<< orphan*/  OST_OSSR ; 
 unsigned long OST_OSSR_M0 ; 
 unsigned long readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (struct clock_event_device*) ; 
 int /*<<< orphan*/  writel (unsigned long,int /*<<< orphan*/ ) ; 

__attribute__((used)) static irqreturn_t puv3_ost0_interrupt(int irq, void *dev_id)
{
	struct clock_event_device *c = dev_id;

	/* Disarm the compare/match, signal the event. */
	writel(readl(OST_OIER) & ~OST_OIER_E0, OST_OIER);
	writel(readl(OST_OSSR) & ~OST_OSSR_M0, OST_OSSR);
	c->event_handler(c);

	return IRQ_HANDLED;
}

__attribute__((used)) static int
puv3_osmr0_set_next_event(unsigned long delta, struct clock_event_device *c)
{
	unsigned long next, oscr;

	writel(readl(OST_OIER) | OST_OIER_E0, OST_OIER);
	next = readl(OST_OSCR) + delta;
	writel(next, OST_OSMR0);
	oscr = readl(OST_OSCR);

	return (signed)(next - oscr) <= MIN_OSCR_DELTA ? -ETIME : 0;
}

__attribute__((used)) static int puv3_osmr0_shutdown(struct clock_event_device *evt)
{
	writel(readl(OST_OIER) & ~OST_OIER_E0, OST_OIER);
	writel(readl(OST_OSSR) & ~OST_OSSR_M0, OST_OSSR);
	return 0;
}

__attribute__((used)) static u64 puv3_read_oscr(struct clocksource *cs)
{
	return readl(OST_OSCR);
}

void puv3_timer_resume(void) { }

