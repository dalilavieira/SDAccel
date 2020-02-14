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
struct watchdog_device {int timeout; int min_timeout; int max_timeout; int /*<<< orphan*/ * parent; scalar_t__ status; int /*<<< orphan*/ * ops; int /*<<< orphan*/ * info; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  TWL4030_WATCHDOG_CFG_REG_OFFS ; 
 int /*<<< orphan*/  TWL_MODULE_PM_RECEIVER ; 
 struct watchdog_device* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nowayout ; 
 struct watchdog_device* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct watchdog_device*) ; 
 int /*<<< orphan*/  twl4030_wdt_info ; 
 int /*<<< orphan*/  twl4030_wdt_ops ; 
 int twl_i2c_write_u8 (int /*<<< orphan*/ ,unsigned char,int /*<<< orphan*/ ) ; 
 int watchdog_register_device (struct watchdog_device*) ; 
 int /*<<< orphan*/  watchdog_set_nowayout (struct watchdog_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  watchdog_unregister_device (struct watchdog_device*) ; 

__attribute__((used)) static int twl4030_wdt_write(unsigned char val)
{
	return twl_i2c_write_u8(TWL_MODULE_PM_RECEIVER, val,
					TWL4030_WATCHDOG_CFG_REG_OFFS);
}

__attribute__((used)) static int twl4030_wdt_start(struct watchdog_device *wdt)
{
	return twl4030_wdt_write(wdt->timeout + 1);
}

__attribute__((used)) static int twl4030_wdt_stop(struct watchdog_device *wdt)
{
	return twl4030_wdt_write(0);
}

__attribute__((used)) static int twl4030_wdt_set_timeout(struct watchdog_device *wdt,
				   unsigned int timeout)
{
	wdt->timeout = timeout;
	return 0;
}

__attribute__((used)) static int twl4030_wdt_probe(struct platform_device *pdev)
{
	int ret = 0;
	struct watchdog_device *wdt;

	wdt = devm_kzalloc(&pdev->dev, sizeof(*wdt), GFP_KERNEL);
	if (!wdt)
		return -ENOMEM;

	wdt->info		= &twl4030_wdt_info;
	wdt->ops		= &twl4030_wdt_ops;
	wdt->status		= 0;
	wdt->timeout		= 30;
	wdt->min_timeout	= 1;
	wdt->max_timeout	= 30;
	wdt->parent = &pdev->dev;

	watchdog_set_nowayout(wdt, nowayout);
	platform_set_drvdata(pdev, wdt);

	twl4030_wdt_stop(wdt);

	ret = watchdog_register_device(wdt);
	if (ret)
		return ret;

	return 0;
}

__attribute__((used)) static int twl4030_wdt_remove(struct platform_device *pdev)
{
	struct watchdog_device *wdt = platform_get_drvdata(pdev);

	watchdog_unregister_device(wdt);

	return 0;
}

