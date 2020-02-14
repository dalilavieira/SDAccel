#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int uint16_t ;
struct cs5535_mfgpt_timer {int dummy; } ;
struct clock_event_device {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_6__ {int /*<<< orphan*/  (* event_handler ) (TYPE_1__*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 int MFGPT_PERIODIC ; 
 int /*<<< orphan*/  MFGPT_REG_CMP2 ; 
 int /*<<< orphan*/  MFGPT_REG_COUNTER ; 
 int /*<<< orphan*/  MFGPT_REG_SETUP ; 
 int MFGPT_SETUP_CMP1 ; 
 int MFGPT_SETUP_CMP2 ; 
 int MFGPT_SETUP_CNTEN ; 
 int MFGPT_SETUP_SETUP ; 
 scalar_t__ clockevent_state_detached (TYPE_1__*) ; 
 scalar_t__ clockevent_state_periodic (TYPE_1__*) ; 
 scalar_t__ clockevent_state_shutdown (TYPE_1__*) ; 
 TYPE_1__ cs5535_clockevent ; 
 struct cs5535_mfgpt_timer* cs5535_event_clock ; 
 int cs5535_mfgpt_read (struct cs5535_mfgpt_timer*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cs5535_mfgpt_write (struct cs5535_mfgpt_timer*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub1 (TYPE_1__*) ; 

__attribute__((used)) static void disable_timer(struct cs5535_mfgpt_timer *timer)
{
	/* avoid races by clearing CMP1 and CMP2 unconditionally */
	cs5535_mfgpt_write(timer, MFGPT_REG_SETUP,
			(uint16_t) ~MFGPT_SETUP_CNTEN | MFGPT_SETUP_CMP1 |
				MFGPT_SETUP_CMP2);
}

__attribute__((used)) static void start_timer(struct cs5535_mfgpt_timer *timer, uint16_t delta)
{
	cs5535_mfgpt_write(timer, MFGPT_REG_CMP2, delta);
	cs5535_mfgpt_write(timer, MFGPT_REG_COUNTER, 0);

	cs5535_mfgpt_write(timer, MFGPT_REG_SETUP,
			MFGPT_SETUP_CNTEN | MFGPT_SETUP_CMP2);
}

__attribute__((used)) static int mfgpt_shutdown(struct clock_event_device *evt)
{
	disable_timer(cs5535_event_clock);
	return 0;
}

__attribute__((used)) static int mfgpt_set_periodic(struct clock_event_device *evt)
{
	disable_timer(cs5535_event_clock);
	start_timer(cs5535_event_clock, MFGPT_PERIODIC);
	return 0;
}

__attribute__((used)) static int mfgpt_next_event(unsigned long delta, struct clock_event_device *evt)
{
	start_timer(cs5535_event_clock, delta);
	return 0;
}

__attribute__((used)) static irqreturn_t mfgpt_tick(int irq, void *dev_id)
{
	uint16_t val = cs5535_mfgpt_read(cs5535_event_clock, MFGPT_REG_SETUP);

	/* See if the interrupt was for us */
	if (!(val & (MFGPT_SETUP_SETUP | MFGPT_SETUP_CMP2 | MFGPT_SETUP_CMP1)))
		return IRQ_NONE;

	/* Turn off the clock (and clear the event) */
	disable_timer(cs5535_event_clock);

	if (clockevent_state_detached(&cs5535_clockevent) ||
	    clockevent_state_shutdown(&cs5535_clockevent))
		return IRQ_HANDLED;

	/* Clear the counter */
	cs5535_mfgpt_write(cs5535_event_clock, MFGPT_REG_COUNTER, 0);

	/* Restart the clock in periodic mode */

	if (clockevent_state_periodic(&cs5535_clockevent))
		cs5535_mfgpt_write(cs5535_event_clock, MFGPT_REG_SETUP,
				MFGPT_SETUP_CNTEN | MFGPT_SETUP_CMP2);

	cs5535_clockevent.event_handler(&cs5535_clockevent);
	return IRQ_HANDLED;
}

