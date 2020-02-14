#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_6__ ;
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct timer_list {int dummy; } ;
struct notifier_block {int dummy; } ;
struct TYPE_12__ {int /*<<< orphan*/  control; } ;
struct TYPE_8__ {unsigned long misc; } ;
struct TYPE_9__ {TYPE_1__ ctrl; } ;
struct TYPE_11__ {TYPE_2__ perif; } ;
struct TYPE_10__ {scalar_t__ expires; } ;

/* Variables and functions */
 int /*<<< orphan*/  CRIME_CONTROL_HARD_RESET ; 
 int HZ ; 
 unsigned long MACEISA_LED_GREEN ; 
 unsigned long MACEISA_LED_RED ; 
 int NOTIFY_DONE ; 
 scalar_t__ PANIC_FREQ ; 
 scalar_t__ POWERDOWN_FREQ ; 
 int POWERDOWN_TIMEOUT ; 
 int /*<<< orphan*/  SIGINT ; 
 int /*<<< orphan*/  add_timer (TYPE_3__*) ; 
 struct timer_list blink_timer ; 
 scalar_t__ blink_timer_timeout ; 
 TYPE_6__* crime ; 
 int has_panicked ; 
 int /*<<< orphan*/  ip32_poweroff (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ip32_rtc_device ; 
 scalar_t__ jiffies ; 
 scalar_t__ kill_cad_pid (int /*<<< orphan*/ ,int) ; 
 TYPE_5__* mace ; 
 int /*<<< orphan*/  mod_timer (struct timer_list*,scalar_t__) ; 
 int /*<<< orphan*/  msleep (int) ; 
 TYPE_3__ power_timer ; 
 int shutting_down ; 
 int /*<<< orphan*/  timer_setup (TYPE_3__*,void (*) (struct timer_list*),int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  unreachable () ; 

__attribute__((used)) static void ip32_machine_restart(char *cmd)
{
	msleep(20);
	crime->control = CRIME_CONTROL_HARD_RESET;
	unreachable();
}

__attribute__((used)) static void blink_timeout(struct timer_list *unused)
{
	unsigned long led = mace->perif.ctrl.misc ^ MACEISA_LED_RED;
	mace->perif.ctrl.misc = led;
	mod_timer(&blink_timer, jiffies + blink_timer_timeout);
}

__attribute__((used)) static void ip32_machine_halt(void)
{
	ip32_poweroff(&ip32_rtc_device);
}

__attribute__((used)) static void power_timeout(struct timer_list *unused)
{
	ip32_poweroff(&ip32_rtc_device);
}

void ip32_prepare_poweroff(void)
{
	if (has_panicked)
		return;

	if (shutting_down || kill_cad_pid(SIGINT, 1)) {
		/* No init process or button pressed twice.  */
		ip32_poweroff(&ip32_rtc_device);
	}

	shutting_down = 1;
	blink_timer_timeout = POWERDOWN_FREQ;
	blink_timeout(&blink_timer);

	timer_setup(&power_timer, power_timeout, 0);
	power_timer.expires = jiffies + POWERDOWN_TIMEOUT * HZ;
	add_timer(&power_timer);
}

__attribute__((used)) static int panic_event(struct notifier_block *this, unsigned long event,
		       void *ptr)
{
	unsigned long led;

	if (has_panicked)
		return NOTIFY_DONE;
	has_panicked = 1;

	/* turn off the green LED */
	led = mace->perif.ctrl.misc | MACEISA_LED_GREEN;
	mace->perif.ctrl.misc = led;

	blink_timer_timeout = PANIC_FREQ;
	blink_timeout(&blink_timer);

	return NOTIFY_DONE;
}

