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
struct watchdog_device {scalar_t__ pretimeout; scalar_t__ timeout; } ;
struct hrtimer {int dummy; } ;
typedef  enum hrtimer_restart { ____Placeholder_hrtimer_restart } hrtimer_restart ;

/* Variables and functions */
 int /*<<< orphan*/  CONFIG_SOFT_WATCHDOG_PRETIMEOUT ; 
 int /*<<< orphan*/  HRTIMER_MODE_REL ; 
 int HRTIMER_NORESTART ; 
 scalar_t__ IS_ENABLED (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  __module_get (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  emergency_restart () ; 
 int /*<<< orphan*/  hrtimer_active (int /*<<< orphan*/ *) ; 
 scalar_t__ hrtimer_cancel (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  hrtimer_start (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ktime_set (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  module_put (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  panic (char*) ; 
 int /*<<< orphan*/  pr_crit (char*) ; 
 scalar_t__ soft_noboot ; 
 scalar_t__ soft_panic ; 
 int /*<<< orphan*/  softdog_dev ; 
 int /*<<< orphan*/  softdog_preticktock ; 
 int /*<<< orphan*/  softdog_ticktock ; 
 int /*<<< orphan*/  watchdog_notify_pretimeout (int /*<<< orphan*/ *) ; 

__attribute__((used)) static enum hrtimer_restart softdog_fire(struct hrtimer *timer)
{
	module_put(THIS_MODULE);
	if (soft_noboot) {
		pr_crit("Triggered - Reboot ignored\n");
	} else if (soft_panic) {
		pr_crit("Initiating panic\n");
		panic("Software Watchdog Timer expired");
	} else {
		pr_crit("Initiating system reboot\n");
		emergency_restart();
		pr_crit("Reboot didn't ?????\n");
	}

	return HRTIMER_NORESTART;
}

__attribute__((used)) static enum hrtimer_restart softdog_pretimeout(struct hrtimer *timer)
{
	watchdog_notify_pretimeout(&softdog_dev);

	return HRTIMER_NORESTART;
}

__attribute__((used)) static int softdog_ping(struct watchdog_device *w)
{
	if (!hrtimer_active(&softdog_ticktock))
		__module_get(THIS_MODULE);
	hrtimer_start(&softdog_ticktock, ktime_set(w->timeout, 0),
		      HRTIMER_MODE_REL);

	if (IS_ENABLED(CONFIG_SOFT_WATCHDOG_PRETIMEOUT)) {
		if (w->pretimeout)
			hrtimer_start(&softdog_preticktock,
				      ktime_set(w->timeout - w->pretimeout, 0),
				      HRTIMER_MODE_REL);
		else
			hrtimer_cancel(&softdog_preticktock);
	}

	return 0;
}

__attribute__((used)) static int softdog_stop(struct watchdog_device *w)
{
	if (hrtimer_cancel(&softdog_ticktock))
		module_put(THIS_MODULE);

	if (IS_ENABLED(CONFIG_SOFT_WATCHDOG_PRETIMEOUT))
		hrtimer_cancel(&softdog_preticktock);

	return 0;
}

