#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct watchdog_device {int dummy; } ;
struct ux500_wdt_data {scalar_t__ timeout; scalar_t__ has_28_bits_resolution; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct TYPE_5__ {int /*<<< orphan*/ * parent; int /*<<< orphan*/  max_timeout; } ;

/* Variables and functions */
 int /*<<< orphan*/  PRCMU_WDOG_ALL ; 
 int /*<<< orphan*/  PRCMU_WDOG_CPU1 ; 
 int /*<<< orphan*/  WATCHDOG_MAX28 ; 
 struct ux500_wdt_data* dev_get_platdata (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  nowayout ; 
 int /*<<< orphan*/  prcmu_config_a9wdog (int /*<<< orphan*/ ,int) ; 
 int prcmu_disable_a9wdog (int /*<<< orphan*/ ) ; 
 int prcmu_enable_a9wdog (int /*<<< orphan*/ ) ; 
 int prcmu_kick_a9wdog (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  prcmu_load_a9wdog (int /*<<< orphan*/ ,int) ; 
 int timeout ; 
 TYPE_1__ ux500_wdt ; 
 int watchdog_register_device (TYPE_1__*) ; 
 int /*<<< orphan*/  watchdog_set_nowayout (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  watchdog_unregister_device (TYPE_1__*) ; 

__attribute__((used)) static int ux500_wdt_start(struct watchdog_device *wdd)
{
	return prcmu_enable_a9wdog(PRCMU_WDOG_ALL);
}

__attribute__((used)) static int ux500_wdt_stop(struct watchdog_device *wdd)
{
	return prcmu_disable_a9wdog(PRCMU_WDOG_ALL);
}

__attribute__((used)) static int ux500_wdt_keepalive(struct watchdog_device *wdd)
{
	return prcmu_kick_a9wdog(PRCMU_WDOG_ALL);
}

__attribute__((used)) static int ux500_wdt_set_timeout(struct watchdog_device *wdd,
				 unsigned int timeout)
{
	ux500_wdt_stop(wdd);
	prcmu_load_a9wdog(PRCMU_WDOG_ALL, timeout * 1000);
	ux500_wdt_start(wdd);

	return 0;
}

__attribute__((used)) static int ux500_wdt_probe(struct platform_device *pdev)
{
	int ret;
	struct ux500_wdt_data *pdata = dev_get_platdata(&pdev->dev);

	if (pdata) {
		if (pdata->timeout > 0)
			timeout = pdata->timeout;
		if (pdata->has_28_bits_resolution)
			ux500_wdt.max_timeout = WATCHDOG_MAX28;
	}

	ux500_wdt.parent = &pdev->dev;
	watchdog_set_nowayout(&ux500_wdt, nowayout);

	/* disable auto off on sleep */
	prcmu_config_a9wdog(PRCMU_WDOG_CPU1, false);

	/* set HW initial value */
	prcmu_load_a9wdog(PRCMU_WDOG_ALL, timeout * 1000);

	ret = watchdog_register_device(&ux500_wdt);
	if (ret)
		return ret;

	dev_info(&pdev->dev, "initialized\n");

	return 0;
}

__attribute__((used)) static int ux500_wdt_remove(struct platform_device *dev)
{
	watchdog_unregister_device(&ux500_wdt);

	return 0;
}

