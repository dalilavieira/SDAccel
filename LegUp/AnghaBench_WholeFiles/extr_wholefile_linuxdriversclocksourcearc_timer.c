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
struct clock_event_device {int /*<<< orphan*/  cpumask; int /*<<< orphan*/  (* event_handler ) (struct clock_event_device*) ;} ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  ARC_REG_TIMER0_CNT ; 
 int /*<<< orphan*/  ARC_REG_TIMER0_CTRL ; 
 int /*<<< orphan*/  ARC_REG_TIMER0_LIMIT ; 
 int /*<<< orphan*/  ARC_TIMERN_MAX ; 
 unsigned int HZ ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int TIMER_CTRL_IE ; 
 int TIMER_CTRL_NH ; 
 int /*<<< orphan*/  arc_clockevent_device ; 
 unsigned int arc_timer_freq ; 
 int /*<<< orphan*/  arc_timer_irq ; 
 int clockevent_state_periodic (struct clock_event_device*) ; 
 int /*<<< orphan*/  clockevents_config_and_register (struct clock_event_device*,unsigned int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpumask_of (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  disable_percpu_irq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  enable_percpu_irq (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  smp_processor_id () ; 
 int /*<<< orphan*/  stub1 (struct clock_event_device*) ; 
 struct clock_event_device* this_cpu_ptr (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  write_aux_reg (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void arc_timer_event_setup(unsigned int cycles)
{
	write_aux_reg(ARC_REG_TIMER0_LIMIT, cycles);
	write_aux_reg(ARC_REG_TIMER0_CNT, 0);	/* start from 0 */

	write_aux_reg(ARC_REG_TIMER0_CTRL, TIMER_CTRL_IE | TIMER_CTRL_NH);
}

__attribute__((used)) static int arc_clkevent_set_next_event(unsigned long delta,
				       struct clock_event_device *dev)
{
	arc_timer_event_setup(delta);
	return 0;
}

__attribute__((used)) static int arc_clkevent_set_periodic(struct clock_event_device *dev)
{
	/*
	 * At X Hz, 1 sec = 1000ms -> X cycles;
	 *		      10ms -> X / 100 cycles
	 */
	arc_timer_event_setup(arc_timer_freq / HZ);
	return 0;
}

__attribute__((used)) static irqreturn_t timer_irq_handler(int irq, void *dev_id)
{
	/*
	 * Note that generic IRQ core could have passed @evt for @dev_id if
	 * irq_set_chip_and_handler() asked for handle_percpu_devid_irq()
	 */
	struct clock_event_device *evt = this_cpu_ptr(&arc_clockevent_device);
	int irq_reenable = clockevent_state_periodic(evt);

	/*
	 * 1. ACK the interrupt
	 *    - For ARC700, any write to CTRL reg ACKs it, so just rewrite
	 *      Count when [N]ot [H]alted bit.
	 *    - For HS3x, it is a bit subtle. On taken count-down interrupt,
	 *      IP bit [3] is set, which needs to be cleared for ACK'ing.
	 *      The write below can only update the other two bits, hence
	 *      explicitly clears IP bit
	 * 2. Re-arm interrupt if periodic by writing to IE bit [0]
	 */
	write_aux_reg(ARC_REG_TIMER0_CTRL, irq_reenable | TIMER_CTRL_NH);

	evt->event_handler(evt);

	return IRQ_HANDLED;
}

__attribute__((used)) static int arc_timer_starting_cpu(unsigned int cpu)
{
	struct clock_event_device *evt = this_cpu_ptr(&arc_clockevent_device);

	evt->cpumask = cpumask_of(smp_processor_id());

	clockevents_config_and_register(evt, arc_timer_freq, 0, ARC_TIMERN_MAX);
	enable_percpu_irq(arc_timer_irq, 0);
	return 0;
}

__attribute__((used)) static int arc_timer_dying_cpu(unsigned int cpu)
{
	disable_percpu_irq(arc_timer_irq);
	return 0;
}

