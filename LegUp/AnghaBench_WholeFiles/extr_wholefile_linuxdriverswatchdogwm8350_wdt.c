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
typedef  int u16 ;
struct wm8350 {int dummy; } ;
struct watchdog_device {unsigned int timeout; int /*<<< orphan*/ * parent; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct TYPE_3__ {unsigned int time; int val; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_1__*) ; 
 int EINVAL ; 
 int ENODEV ; 
 int /*<<< orphan*/  WM8350_SYSTEM_CONTROL_2 ; 
 int WM8350_WDOG_MODE_MASK ; 
 int WM8350_WDOG_TO_MASK ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nowayout ; 
 struct wm8350* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 struct wm8350* watchdog_get_drvdata (struct watchdog_device*) ; 
 int watchdog_register_device (struct watchdog_device*) ; 
 int /*<<< orphan*/  watchdog_set_drvdata (struct watchdog_device*,struct wm8350*) ; 
 int /*<<< orphan*/  watchdog_set_nowayout (struct watchdog_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  watchdog_unregister_device (struct watchdog_device*) ; 
 int /*<<< orphan*/  wdt_mutex ; 
 int /*<<< orphan*/  wm8350_reg_lock (struct wm8350*) ; 
 int wm8350_reg_read (struct wm8350*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wm8350_reg_unlock (struct wm8350*) ; 
 int wm8350_reg_write (struct wm8350*,int /*<<< orphan*/ ,int) ; 
 struct watchdog_device wm8350_wdt ; 
 TYPE_1__* wm8350_wdt_cfgs ; 

__attribute__((used)) static int wm8350_wdt_set_timeout(struct watchdog_device *wdt_dev,
				  unsigned int timeout)
{
	struct wm8350 *wm8350 = watchdog_get_drvdata(wdt_dev);
	int ret, i;
	u16 reg;

	for (i = 0; i < ARRAY_SIZE(wm8350_wdt_cfgs); i++)
		if (wm8350_wdt_cfgs[i].time == timeout)
			break;
	if (i == ARRAY_SIZE(wm8350_wdt_cfgs))
		return -EINVAL;

	mutex_lock(&wdt_mutex);
	wm8350_reg_unlock(wm8350);

	reg = wm8350_reg_read(wm8350, WM8350_SYSTEM_CONTROL_2);
	reg &= ~WM8350_WDOG_TO_MASK;
	reg |= wm8350_wdt_cfgs[i].val;
	ret = wm8350_reg_write(wm8350, WM8350_SYSTEM_CONTROL_2, reg);

	wm8350_reg_lock(wm8350);
	mutex_unlock(&wdt_mutex);

	wdt_dev->timeout = timeout;
	return ret;
}

__attribute__((used)) static int wm8350_wdt_start(struct watchdog_device *wdt_dev)
{
	struct wm8350 *wm8350 = watchdog_get_drvdata(wdt_dev);
	int ret;
	u16 reg;

	mutex_lock(&wdt_mutex);
	wm8350_reg_unlock(wm8350);

	reg = wm8350_reg_read(wm8350, WM8350_SYSTEM_CONTROL_2);
	reg &= ~WM8350_WDOG_MODE_MASK;
	reg |= 0x20;
	ret = wm8350_reg_write(wm8350, WM8350_SYSTEM_CONTROL_2, reg);

	wm8350_reg_lock(wm8350);
	mutex_unlock(&wdt_mutex);

	return ret;
}

__attribute__((used)) static int wm8350_wdt_stop(struct watchdog_device *wdt_dev)
{
	struct wm8350 *wm8350 = watchdog_get_drvdata(wdt_dev);
	int ret;
	u16 reg;

	mutex_lock(&wdt_mutex);
	wm8350_reg_unlock(wm8350);

	reg = wm8350_reg_read(wm8350, WM8350_SYSTEM_CONTROL_2);
	reg &= ~WM8350_WDOG_MODE_MASK;
	ret = wm8350_reg_write(wm8350, WM8350_SYSTEM_CONTROL_2, reg);

	wm8350_reg_lock(wm8350);
	mutex_unlock(&wdt_mutex);

	return ret;
}

__attribute__((used)) static int wm8350_wdt_ping(struct watchdog_device *wdt_dev)
{
	struct wm8350 *wm8350 = watchdog_get_drvdata(wdt_dev);
	int ret;
	u16 reg;

	mutex_lock(&wdt_mutex);

	reg = wm8350_reg_read(wm8350, WM8350_SYSTEM_CONTROL_2);
	ret = wm8350_reg_write(wm8350, WM8350_SYSTEM_CONTROL_2, reg);

	mutex_unlock(&wdt_mutex);

	return ret;
}

__attribute__((used)) static int wm8350_wdt_probe(struct platform_device *pdev)
{
	struct wm8350 *wm8350 = platform_get_drvdata(pdev);

	if (!wm8350) {
		pr_err("No driver data supplied\n");
		return -ENODEV;
	}

	watchdog_set_nowayout(&wm8350_wdt, nowayout);
	watchdog_set_drvdata(&wm8350_wdt, wm8350);
	wm8350_wdt.parent = &pdev->dev;

	/* Default to 4s timeout */
	wm8350_wdt_set_timeout(&wm8350_wdt, 4);

	return watchdog_register_device(&wm8350_wdt);
}

__attribute__((used)) static int wm8350_wdt_remove(struct platform_device *pdev)
{
	watchdog_unregister_device(&wm8350_wdt);
	return 0;
}

