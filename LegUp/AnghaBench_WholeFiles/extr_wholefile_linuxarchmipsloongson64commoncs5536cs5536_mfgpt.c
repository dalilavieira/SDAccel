#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct clock_event_device {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_3__ {int /*<<< orphan*/  (* event_handler ) (TYPE_1__*) ;} ;

/* Variables and functions */
 int COMPARE ; 
 int /*<<< orphan*/  DIVIL_LBAR_MFGPT ; 
 int /*<<< orphan*/  DIVIL_MSR_REG (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  MFGPT0_CMP2 ; 
 int /*<<< orphan*/  MFGPT0_CNT ; 
 int /*<<< orphan*/  MFGPT0_SETUP ; 
 int /*<<< orphan*/  _rdmsr (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ clockevent_state_oneshot (struct clock_event_device*) ; 
 scalar_t__ clockevent_state_periodic (struct clock_event_device*) ; 
 int inw (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mfgpt_base ; 
 TYPE_1__ mfgpt_clockevent ; 
 int /*<<< orphan*/  mfgpt_lock ; 
 int /*<<< orphan*/  outw (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  raw_spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  raw_spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (TYPE_1__*) ; 

void disable_mfgpt0_counter(void)
{
	outw(inw(MFGPT0_SETUP) & 0x7fff, MFGPT0_SETUP);
}

void enable_mfgpt0_counter(void)
{
	outw(0xe310, MFGPT0_SETUP);
}

__attribute__((used)) static int mfgpt_timer_set_periodic(struct clock_event_device *evt)
{
	raw_spin_lock(&mfgpt_lock);

	outw(COMPARE, MFGPT0_CMP2);	/* set comparator2 */
	outw(0, MFGPT0_CNT);		/* set counter to 0 */
	enable_mfgpt0_counter();

	raw_spin_unlock(&mfgpt_lock);
	return 0;
}

__attribute__((used)) static int mfgpt_timer_shutdown(struct clock_event_device *evt)
{
	if (clockevent_state_periodic(evt) || clockevent_state_oneshot(evt)) {
		raw_spin_lock(&mfgpt_lock);
		disable_mfgpt0_counter();
		raw_spin_unlock(&mfgpt_lock);
	}

	return 0;
}

__attribute__((used)) static irqreturn_t timer_interrupt(int irq, void *dev_id)
{
	u32 basehi;

	/*
	 * get MFGPT base address
	 *
	 * NOTE: do not remove me, it's need for the value of mfgpt_base is
	 * variable
	 */
	_rdmsr(DIVIL_MSR_REG(DIVIL_LBAR_MFGPT), &basehi, &mfgpt_base);

	/* ack */
	outw(inw(MFGPT0_SETUP) | 0x4000, MFGPT0_SETUP);

	mfgpt_clockevent.event_handler(&mfgpt_clockevent);

	return IRQ_HANDLED;
}

