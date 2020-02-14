#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned long u64 ;
typedef  int u32 ;
struct clocksource {int dummy; } ;
struct clock_event_device {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_4__ {int /*<<< orphan*/  (* event_handler ) (TYPE_1__*) ;} ;

/* Variables and functions */
 int AT91_ST_ALMS ; 
 int /*<<< orphan*/  AT91_ST_CRTR ; 
 int AT91_ST_CRTV ; 
 int /*<<< orphan*/  AT91_ST_IDR ; 
 int /*<<< orphan*/  AT91_ST_IER ; 
 int /*<<< orphan*/  AT91_ST_PIMR ; 
 int AT91_ST_PITS ; 
 int /*<<< orphan*/  AT91_ST_RTAR ; 
 int /*<<< orphan*/  AT91_ST_SR ; 
 int /*<<< orphan*/  BUG_ON (int) ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 int /*<<< orphan*/  WARN_ON_ONCE (int) ; 
 TYPE_1__ clkevt ; 
 int irqmask ; 
 int /*<<< orphan*/  irqs_disabled () ; 
 int last_crtr ; 
 int /*<<< orphan*/  regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,...) ; 
 int /*<<< orphan*/  regmap_st ; 
 int /*<<< orphan*/  regmap_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub1 (TYPE_1__*) ; 
 int /*<<< orphan*/  stub2 (TYPE_1__*) ; 
 int timer_latch ; 

__attribute__((used)) static inline unsigned long read_CRTR(void)
{
	unsigned int x1, x2;

	regmap_read(regmap_st, AT91_ST_CRTR, &x1);
	do {
		regmap_read(regmap_st, AT91_ST_CRTR, &x2);
		if (x1 == x2)
			break;
		x1 = x2;
	} while (1);
	return x1;
}

__attribute__((used)) static irqreturn_t at91rm9200_timer_interrupt(int irq, void *dev_id)
{
	u32 sr;

	regmap_read(regmap_st, AT91_ST_SR, &sr);
	sr &= irqmask;

	/*
	 * irqs should be disabled here, but as the irq is shared they are only
	 * guaranteed to be off if the timer irq is registered first.
	 */
	WARN_ON_ONCE(!irqs_disabled());

	/* simulate "oneshot" timer with alarm */
	if (sr & AT91_ST_ALMS) {
		clkevt.event_handler(&clkevt);
		return IRQ_HANDLED;
	}

	/* periodic mode should handle delayed ticks */
	if (sr & AT91_ST_PITS) {
		u32	crtr = read_CRTR();

		while (((crtr - last_crtr) & AT91_ST_CRTV) >= timer_latch) {
			last_crtr += timer_latch;
			clkevt.event_handler(&clkevt);
		}
		return IRQ_HANDLED;
	}

	/* this irq is shared ... */
	return IRQ_NONE;
}

__attribute__((used)) static u64 read_clk32k(struct clocksource *cs)
{
	return read_CRTR();
}

__attribute__((used)) static void clkdev32k_disable_and_flush_irq(void)
{
	unsigned int val;

	/* Disable and flush pending timer interrupts */
	regmap_write(regmap_st, AT91_ST_IDR, AT91_ST_PITS | AT91_ST_ALMS);
	regmap_read(regmap_st, AT91_ST_SR, &val);
	last_crtr = read_CRTR();
}

__attribute__((used)) static int clkevt32k_shutdown(struct clock_event_device *evt)
{
	clkdev32k_disable_and_flush_irq();
	irqmask = 0;
	regmap_write(regmap_st, AT91_ST_IER, irqmask);
	return 0;
}

__attribute__((used)) static int clkevt32k_set_oneshot(struct clock_event_device *dev)
{
	clkdev32k_disable_and_flush_irq();

	/*
	 * ALM for oneshot irqs, set by next_event()
	 * before 32 seconds have passed.
	 */
	irqmask = AT91_ST_ALMS;
	regmap_write(regmap_st, AT91_ST_RTAR, last_crtr);
	regmap_write(regmap_st, AT91_ST_IER, irqmask);
	return 0;
}

__attribute__((used)) static int clkevt32k_set_periodic(struct clock_event_device *dev)
{
	clkdev32k_disable_and_flush_irq();

	/* PIT for periodic irqs; fixed rate of 1/HZ */
	irqmask = AT91_ST_PITS;
	regmap_write(regmap_st, AT91_ST_PIMR, timer_latch);
	regmap_write(regmap_st, AT91_ST_IER, irqmask);
	return 0;
}

__attribute__((used)) static int
clkevt32k_next_event(unsigned long delta, struct clock_event_device *dev)
{
	u32		alm;
	int		status = 0;
	unsigned int	val;

	BUG_ON(delta < 2);

	/* The alarm IRQ uses absolute time (now+delta), not the relative
	 * time (delta) in our calling convention.  Like all clockevents
	 * using such "match" hardware, we have a race to defend against.
	 *
	 * Our defense here is to have set up the clockevent device so the
	 * delta is at least two.  That way we never end up writing RTAR
	 * with the value then held in CRTR ... which would mean the match
	 * wouldn't trigger until 32 seconds later, after CRTR wraps.
	 */
	alm = read_CRTR();

	/* Cancel any pending alarm; flush any pending IRQ */
	regmap_write(regmap_st, AT91_ST_RTAR, alm);
	regmap_read(regmap_st, AT91_ST_SR, &val);

	/* Schedule alarm by writing RTAR. */
	alm += delta;
	regmap_write(regmap_st, AT91_ST_RTAR, alm);

	return status;
}

