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
typedef  int u64 ;
struct clocksource {int dummy; } ;
struct clock_event_device {int /*<<< orphan*/  (* event_handler ) (struct clock_event_device*) ;} ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_4__ {int (* read ) (TYPE_1__*) ;} ;

/* Variables and functions */
 int ETIME ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int MIN_OSCR_DELTA ; 
 scalar_t__ TIMER_AS_VAL ; 
 int TIMER_COUNT_R_ACTIVE ; 
 scalar_t__ TIMER_COUNT_VAL ; 
 scalar_t__ TIMER_CTRL_VAL ; 
 scalar_t__ TIMER_IER_VAL ; 
 scalar_t__ TIMER_MATCH_VAL ; 
 int TIMER_MATCH_W_ACTIVE ; 
 scalar_t__ TIMER_STATUS_VAL ; 
 TYPE_1__ clocksource ; 
 int /*<<< orphan*/  cpu_relax () ; 
 int msecs_to_loops (int) ; 
 int readl (scalar_t__) ; 
 scalar_t__ regbase ; 
 int stub1 (TYPE_1__*) ; 
 int stub2 (TYPE_1__*) ; 
 int /*<<< orphan*/  stub3 (struct clock_event_device*) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static u64 vt8500_timer_read(struct clocksource *cs)
{
	int loops = msecs_to_loops(10);
	writel(3, regbase + TIMER_CTRL_VAL);
	while ((readl((regbase + TIMER_AS_VAL)) & TIMER_COUNT_R_ACTIVE)
						&& --loops)
		cpu_relax();
	return readl(regbase + TIMER_COUNT_VAL);
}

__attribute__((used)) static int vt8500_timer_set_next_event(unsigned long cycles,
				    struct clock_event_device *evt)
{
	int loops = msecs_to_loops(10);
	u64 alarm = clocksource.read(&clocksource) + cycles;
	while ((readl(regbase + TIMER_AS_VAL) & TIMER_MATCH_W_ACTIVE)
						&& --loops)
		cpu_relax();
	writel((unsigned long)alarm, regbase + TIMER_MATCH_VAL);

	if ((signed)(alarm - clocksource.read(&clocksource)) <= MIN_OSCR_DELTA)
		return -ETIME;

	writel(1, regbase + TIMER_IER_VAL);

	return 0;
}

__attribute__((used)) static int vt8500_shutdown(struct clock_event_device *evt)
{
	writel(readl(regbase + TIMER_CTRL_VAL) | 1, regbase + TIMER_CTRL_VAL);
	writel(0, regbase + TIMER_IER_VAL);
	return 0;
}

__attribute__((used)) static irqreturn_t vt8500_timer_interrupt(int irq, void *dev_id)
{
	struct clock_event_device *evt = dev_id;
	writel(0xf, regbase + TIMER_STATUS_VAL);
	evt->event_handler(evt);

	return IRQ_HANDLED;
}

