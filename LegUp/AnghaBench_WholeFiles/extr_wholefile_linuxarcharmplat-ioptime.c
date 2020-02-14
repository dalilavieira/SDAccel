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
 int IOP_TMR_EN ; 
 int IOP_TMR_RELOAD ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 unsigned long iop_tick_rate ; 
 int read_tmr0 () ; 
 int /*<<< orphan*/  stub1 (struct clock_event_device*) ; 
 scalar_t__ ticks_per_jiffy ; 
 int /*<<< orphan*/  write_tcr0 (scalar_t__) ; 
 int /*<<< orphan*/  write_tisr (int) ; 
 int /*<<< orphan*/  write_tmr0 (int) ; 
 int /*<<< orphan*/  write_trr0 (scalar_t__) ; 

__attribute__((used)) static int iop_set_periodic(struct clock_event_device *evt)
{
	u32 tmr = read_tmr0();

	write_tmr0(tmr & ~IOP_TMR_EN);
	write_tcr0(ticks_per_jiffy - 1);
	write_trr0(ticks_per_jiffy - 1);
	tmr |= (IOP_TMR_RELOAD | IOP_TMR_EN);

	write_tmr0(tmr);
	return 0;
}

__attribute__((used)) static int iop_set_oneshot(struct clock_event_device *evt)
{
	u32 tmr = read_tmr0();

	/* ->set_next_event sets period and enables timer */
	tmr &= ~(IOP_TMR_RELOAD | IOP_TMR_EN);
	write_tmr0(tmr);
	return 0;
}

__attribute__((used)) static int iop_shutdown(struct clock_event_device *evt)
{
	u32 tmr = read_tmr0();

	tmr &= ~IOP_TMR_EN;
	write_tmr0(tmr);
	return 0;
}

__attribute__((used)) static int iop_resume(struct clock_event_device *evt)
{
	u32 tmr = read_tmr0();

	tmr |= IOP_TMR_EN;
	write_tmr0(tmr);
	return 0;
}

__attribute__((used)) static irqreturn_t
iop_timer_interrupt(int irq, void *dev_id)
{
	struct clock_event_device *evt = dev_id;

	write_tisr(1);
	evt->event_handler(evt);
	return IRQ_HANDLED;
}

unsigned long get_iop_tick_rate(void)
{
	return iop_tick_rate;
}

