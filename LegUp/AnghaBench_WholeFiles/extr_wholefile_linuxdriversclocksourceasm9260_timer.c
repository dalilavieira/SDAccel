#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct clock_event_device {int /*<<< orphan*/  (* event_handler ) (struct clock_event_device*) ;} ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_2__ {unsigned long ticks_per_jiffy; scalar_t__ base; } ;

/* Variables and functions */
 unsigned long BM_C0_EN ; 
 unsigned long BM_IR_MR0 ; 
 unsigned long BM_MCR_RES_EN (int /*<<< orphan*/ ) ; 
 unsigned long BM_MCR_STOP_EN (int /*<<< orphan*/ ) ; 
 scalar_t__ CLR_REG ; 
 scalar_t__ HW_IR ; 
 scalar_t__ HW_MCR ; 
 scalar_t__ HW_MR0 ; 
 scalar_t__ HW_TCR ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ SET_REG ; 
 TYPE_1__ priv ; 
 int /*<<< orphan*/  stub1 (struct clock_event_device*) ; 
 int /*<<< orphan*/  writel_relaxed (unsigned long,scalar_t__) ; 

__attribute__((used)) static int asm9260_timer_set_next_event(unsigned long delta,
					 struct clock_event_device *evt)
{
	/* configure match count for TC0 */
	writel_relaxed(delta, priv.base + HW_MR0);
	/* enable TC0 */
	writel_relaxed(BM_C0_EN, priv.base + HW_TCR + SET_REG);
	return 0;
}

__attribute__((used)) static inline void __asm9260_timer_shutdown(struct clock_event_device *evt)
{
	/* stop timer0 */
	writel_relaxed(BM_C0_EN, priv.base + HW_TCR + CLR_REG);
}

__attribute__((used)) static int asm9260_timer_shutdown(struct clock_event_device *evt)
{
	__asm9260_timer_shutdown(evt);
	return 0;
}

__attribute__((used)) static int asm9260_timer_set_oneshot(struct clock_event_device *evt)
{
	__asm9260_timer_shutdown(evt);

	/* enable reset and stop on match */
	writel_relaxed(BM_MCR_RES_EN(0) | BM_MCR_STOP_EN(0),
		       priv.base + HW_MCR + SET_REG);
	return 0;
}

__attribute__((used)) static int asm9260_timer_set_periodic(struct clock_event_device *evt)
{
	__asm9260_timer_shutdown(evt);

	/* disable reset and stop on match */
	writel_relaxed(BM_MCR_RES_EN(0) | BM_MCR_STOP_EN(0),
		       priv.base + HW_MCR + CLR_REG);
	/* configure match count for TC0 */
	writel_relaxed(priv.ticks_per_jiffy, priv.base + HW_MR0);
	/* enable TC0 */
	writel_relaxed(BM_C0_EN, priv.base + HW_TCR + SET_REG);
	return 0;
}

__attribute__((used)) static irqreturn_t asm9260_timer_interrupt(int irq, void *dev_id)
{
	struct clock_event_device *evt = dev_id;

	evt->event_handler(evt);

	writel_relaxed(BM_IR_MR0, priv.base + HW_IR);

	return IRQ_HANDLED;
}

