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
typedef  unsigned long u32 ;
typedef  unsigned long u16 ;
struct clocksource {int dummy; } ;
struct clock_event_device {int max_delta_ticks; int min_delta_ticks; void* min_delta_ns; void* max_delta_ns; int /*<<< orphan*/  mult; int /*<<< orphan*/  cpumask; int /*<<< orphan*/  (* event_handler ) (struct clock_event_device*) ;} ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  int /*<<< orphan*/  irq_handler_t ;

/* Variables and functions */
 int /*<<< orphan*/  FREQ ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  MCFPIT_PCNTR ; 
 int /*<<< orphan*/  MCFPIT_PCSR ; 
 unsigned long MCFPIT_PCSR_CLK64 ; 
 unsigned long MCFPIT_PCSR_DISABLE ; 
 unsigned long MCFPIT_PCSR_EN ; 
 unsigned long MCFPIT_PCSR_OVW ; 
 unsigned long MCFPIT_PCSR_PIE ; 
 unsigned long MCFPIT_PCSR_PIF ; 
 unsigned long MCFPIT_PCSR_RLD ; 
 int /*<<< orphan*/  MCFPIT_PMR ; 
 int /*<<< orphan*/  MCF_IRQ_PIT1 ; 
 int /*<<< orphan*/  NSEC_PER_SEC ; 
 unsigned long PIT_CYCLES_PER_JIFFY ; 
 int /*<<< orphan*/  TA (int /*<<< orphan*/ ) ; 
 unsigned long __raw_readw (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __raw_writew (unsigned long,int /*<<< orphan*/ ) ; 
 struct clock_event_device cf_pit_clockevent ; 
 void* clockevent_delta2ns (int,struct clock_event_device*) ; 
 int /*<<< orphan*/  clockevents_register_device (struct clock_event_device*) ; 
 int /*<<< orphan*/  clocksource_register_hz (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpumask_of (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  div_sc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 int /*<<< orphan*/  pit_clk ; 
 unsigned long pit_cnt ; 
 int /*<<< orphan*/  pit_irq ; 
 int /*<<< orphan*/  setup_irq (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  smp_processor_id () ; 
 int /*<<< orphan*/  stub1 (struct clock_event_device*) ; 

__attribute__((used)) static int cf_pit_set_periodic(struct clock_event_device *evt)
{
	__raw_writew(MCFPIT_PCSR_DISABLE, TA(MCFPIT_PCSR));
	__raw_writew(PIT_CYCLES_PER_JIFFY, TA(MCFPIT_PMR));
	__raw_writew(MCFPIT_PCSR_EN | MCFPIT_PCSR_PIE |
		     MCFPIT_PCSR_OVW | MCFPIT_PCSR_RLD |
		     MCFPIT_PCSR_CLK64, TA(MCFPIT_PCSR));
	return 0;
}

__attribute__((used)) static int cf_pit_set_oneshot(struct clock_event_device *evt)
{
	__raw_writew(MCFPIT_PCSR_DISABLE, TA(MCFPIT_PCSR));
	__raw_writew(MCFPIT_PCSR_EN | MCFPIT_PCSR_PIE |
		     MCFPIT_PCSR_OVW | MCFPIT_PCSR_CLK64, TA(MCFPIT_PCSR));
	return 0;
}

__attribute__((used)) static int cf_pit_shutdown(struct clock_event_device *evt)
{
	__raw_writew(MCFPIT_PCSR_DISABLE, TA(MCFPIT_PCSR));
	return 0;
}

__attribute__((used)) static int cf_pit_next_event(unsigned long delta,
		struct clock_event_device *evt)
{
	__raw_writew(delta, TA(MCFPIT_PMR));
	return 0;
}

__attribute__((used)) static irqreturn_t pit_tick(int irq, void *dummy)
{
	struct clock_event_device *evt = &cf_pit_clockevent;
	u16 pcsr;

	/* Reset the ColdFire timer */
	pcsr = __raw_readw(TA(MCFPIT_PCSR));
	__raw_writew(pcsr | MCFPIT_PCSR_PIF, TA(MCFPIT_PCSR));

	pit_cnt += PIT_CYCLES_PER_JIFFY;
	evt->event_handler(evt);
	return IRQ_HANDLED;
}

__attribute__((used)) static u64 pit_read_clk(struct clocksource *cs)
{
	unsigned long flags;
	u32 cycles;
	u16 pcntr;

	local_irq_save(flags);
	pcntr = __raw_readw(TA(MCFPIT_PCNTR));
	cycles = pit_cnt;
	local_irq_restore(flags);

	return cycles + PIT_CYCLES_PER_JIFFY - pcntr;
}

void hw_timer_init(irq_handler_t handler)
{
	cf_pit_clockevent.cpumask = cpumask_of(smp_processor_id());
	cf_pit_clockevent.mult = div_sc(FREQ, NSEC_PER_SEC, 32);
	cf_pit_clockevent.max_delta_ns =
		clockevent_delta2ns(0xFFFF, &cf_pit_clockevent);
	cf_pit_clockevent.max_delta_ticks = 0xFFFF;
	cf_pit_clockevent.min_delta_ns =
		clockevent_delta2ns(0x3f, &cf_pit_clockevent);
	cf_pit_clockevent.min_delta_ticks = 0x3f;
	clockevents_register_device(&cf_pit_clockevent);

	setup_irq(MCF_IRQ_PIT1, &pit_irq);

	clocksource_register_hz(&pit_clk, FREQ);
}

