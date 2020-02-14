#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_7__ ;
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int u64 ;
struct uml_pt_regs {int dummy; } ;
struct siginfo {int dummy; } ;
struct clocksource {int dummy; } ;
struct clock_event_device {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_13__ {TYPE_4__* mm; } ;
struct TYPE_12__ {int /*<<< orphan*/  (* event_handler ) (TYPE_5__*) ;} ;
struct TYPE_8__ {int /*<<< orphan*/  pid; } ;
struct TYPE_9__ {TYPE_1__ u; } ;
struct TYPE_10__ {TYPE_2__ id; } ;
struct TYPE_11__ {TYPE_3__ context; } ;

/* Variables and functions */
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  TIMER_IRQ ; 
 int TIMER_MULTIPLIER ; 
 int /*<<< orphan*/  do_IRQ (int /*<<< orphan*/ ,struct uml_pt_regs*) ; 
 TYPE_7__* get_current () ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 int /*<<< orphan*/  os_alarm_process (int /*<<< orphan*/ ) ; 
 int os_nsecs () ; 
 int /*<<< orphan*/  os_timer_disable () ; 
 int os_timer_one_shot (int) ; 
 int /*<<< orphan*/  os_timer_set_interval (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (TYPE_5__*) ; 
 TYPE_5__ timer_clockevent ; 

void timer_handler(int sig, struct siginfo *unused_si, struct uml_pt_regs *regs)
{
	unsigned long flags;

	local_irq_save(flags);
	do_IRQ(TIMER_IRQ, regs);
	local_irq_restore(flags);
}

__attribute__((used)) static int itimer_shutdown(struct clock_event_device *evt)
{
	os_timer_disable();
	return 0;
}

__attribute__((used)) static int itimer_set_periodic(struct clock_event_device *evt)
{
	os_timer_set_interval(NULL, NULL);
	return 0;
}

__attribute__((used)) static int itimer_next_event(unsigned long delta,
			     struct clock_event_device *evt)
{
	return os_timer_one_shot(delta);
}

__attribute__((used)) static int itimer_one_shot(struct clock_event_device *evt)
{
	os_timer_one_shot(1);
	return 0;
}

__attribute__((used)) static irqreturn_t um_timer(int irq, void *dev)
{
	if (get_current()->mm != NULL)
	{
        /* userspace - relay signal, results in correct userspace timers */
		os_alarm_process(get_current()->mm->context.id.u.pid);
	}

	(*timer_clockevent.event_handler)(&timer_clockevent);

	return IRQ_HANDLED;
}

__attribute__((used)) static u64 timer_read(struct clocksource *cs)
{
	return os_nsecs() / TIMER_MULTIPLIER;
}

