#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_7__ ;
typedef  struct TYPE_11__   TYPE_6__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
struct watchdog_device {unsigned int timeout; } ;
struct TYPE_10__ {int min_timeout; int max_timeout; int timeout; TYPE_6__* parent; int /*<<< orphan*/ * ops; int /*<<< orphan*/ * info; } ;
struct rn5t618_wdt {TYPE_1__ wdt_dev; struct rn5t618* rn5t618; } ;
struct rn5t618 {int /*<<< orphan*/  regmap; } ;
struct TYPE_11__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_6__ dev; } ;
struct TYPE_12__ {int time; int /*<<< orphan*/  reg_val; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_7__*) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  RN5T618_PWRIREN ; 
 int /*<<< orphan*/  RN5T618_PWRIRQ ; 
 int /*<<< orphan*/  RN5T618_PWRIRQ_IR_WDOG ; 
 int /*<<< orphan*/  RN5T618_REPCNT ; 
 int /*<<< orphan*/  RN5T618_REPCNT_REPWRON ; 
 int /*<<< orphan*/  RN5T618_WATCHDOG ; 
 int /*<<< orphan*/  RN5T618_WATCHDOG_WDOGEN ; 
 int /*<<< orphan*/  RN5T618_WATCHDOG_WDOGTIM_M ; 
 struct rn5t618* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 struct rn5t618_wdt* devm_kzalloc (TYPE_6__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nowayout ; 
 struct rn5t618_wdt* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct rn5t618_wdt*) ; 
 int regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int*) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int regmap_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  rn5t618_wdt_info ; 
 TYPE_7__* rn5t618_wdt_map ; 
 int /*<<< orphan*/  rn5t618_wdt_ops ; 
 int /*<<< orphan*/  timeout ; 
 struct rn5t618_wdt* watchdog_get_drvdata (struct watchdog_device*) ; 
 int /*<<< orphan*/  watchdog_init_timeout (TYPE_1__*,int /*<<< orphan*/ ,TYPE_6__*) ; 
 int watchdog_register_device (TYPE_1__*) ; 
 int /*<<< orphan*/  watchdog_set_drvdata (TYPE_1__*,struct rn5t618_wdt*) ; 
 int /*<<< orphan*/  watchdog_set_nowayout (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  watchdog_unregister_device (TYPE_1__*) ; 

__attribute__((used)) static int rn5t618_wdt_set_timeout(struct watchdog_device *wdt_dev,
				   unsigned int t)
{
	struct rn5t618_wdt *wdt = watchdog_get_drvdata(wdt_dev);
	int ret, i;

	for (i = 0; i < ARRAY_SIZE(rn5t618_wdt_map); i++) {
		if (rn5t618_wdt_map[i].time + 1 >= t)
			break;
	}

	if (i == ARRAY_SIZE(rn5t618_wdt_map))
		return -EINVAL;

	ret = regmap_update_bits(wdt->rn5t618->regmap, RN5T618_WATCHDOG,
				 RN5T618_WATCHDOG_WDOGTIM_M,
				 rn5t618_wdt_map[i].reg_val);
	if (!ret)
		wdt_dev->timeout = rn5t618_wdt_map[i].time;

	return ret;
}

__attribute__((used)) static int rn5t618_wdt_start(struct watchdog_device *wdt_dev)
{
	struct rn5t618_wdt *wdt = watchdog_get_drvdata(wdt_dev);
	int ret;

	ret = rn5t618_wdt_set_timeout(wdt_dev, wdt_dev->timeout);
	if (ret)
		return ret;

	/* enable repower-on */
	ret = regmap_update_bits(wdt->rn5t618->regmap, RN5T618_REPCNT,
				 RN5T618_REPCNT_REPWRON,
				 RN5T618_REPCNT_REPWRON);
	if (ret)
		return ret;

	/* enable watchdog */
	ret = regmap_update_bits(wdt->rn5t618->regmap, RN5T618_WATCHDOG,
				 RN5T618_WATCHDOG_WDOGEN,
				 RN5T618_WATCHDOG_WDOGEN);
	if (ret)
		return ret;

	/* enable watchdog interrupt */
	return regmap_update_bits(wdt->rn5t618->regmap, RN5T618_PWRIREN,
				  RN5T618_PWRIRQ_IR_WDOG,
				  RN5T618_PWRIRQ_IR_WDOG);
}

__attribute__((used)) static int rn5t618_wdt_stop(struct watchdog_device *wdt_dev)
{
	struct rn5t618_wdt *wdt = watchdog_get_drvdata(wdt_dev);

	return regmap_update_bits(wdt->rn5t618->regmap, RN5T618_WATCHDOG,
				  RN5T618_WATCHDOG_WDOGEN, 0);
}

__attribute__((used)) static int rn5t618_wdt_ping(struct watchdog_device *wdt_dev)
{
	struct rn5t618_wdt *wdt = watchdog_get_drvdata(wdt_dev);
	unsigned int val;
	int ret;

	/* The counter is restarted after a R/W access to watchdog register */
	ret = regmap_read(wdt->rn5t618->regmap, RN5T618_WATCHDOG, &val);
	if (ret)
		return ret;

	ret = regmap_write(wdt->rn5t618->regmap, RN5T618_WATCHDOG, val);
	if (ret)
		return ret;

	/* Clear pending watchdog interrupt */
	return regmap_update_bits(wdt->rn5t618->regmap, RN5T618_PWRIRQ,
				  RN5T618_PWRIRQ_IR_WDOG, 0);
}

__attribute__((used)) static int rn5t618_wdt_probe(struct platform_device *pdev)
{
	struct rn5t618 *rn5t618 = dev_get_drvdata(pdev->dev.parent);
	struct rn5t618_wdt *wdt;
	int min_timeout, max_timeout;

	wdt = devm_kzalloc(&pdev->dev, sizeof(struct rn5t618_wdt), GFP_KERNEL);
	if (!wdt)
		return -ENOMEM;

	min_timeout = rn5t618_wdt_map[0].time;
	max_timeout = rn5t618_wdt_map[ARRAY_SIZE(rn5t618_wdt_map) - 1].time;

	wdt->rn5t618 = rn5t618;
	wdt->wdt_dev.info = &rn5t618_wdt_info;
	wdt->wdt_dev.ops = &rn5t618_wdt_ops;
	wdt->wdt_dev.min_timeout = min_timeout;
	wdt->wdt_dev.max_timeout = max_timeout;
	wdt->wdt_dev.timeout = max_timeout;
	wdt->wdt_dev.parent = &pdev->dev;

	watchdog_set_drvdata(&wdt->wdt_dev, wdt);
	watchdog_init_timeout(&wdt->wdt_dev, timeout, &pdev->dev);
	watchdog_set_nowayout(&wdt->wdt_dev, nowayout);

	platform_set_drvdata(pdev, wdt);

	return watchdog_register_device(&wdt->wdt_dev);
}

__attribute__((used)) static int rn5t618_wdt_remove(struct platform_device *pdev)
{
	struct rn5t618_wdt *wdt = platform_get_drvdata(pdev);

	watchdog_unregister_device(&wdt->wdt_dev);

	return 0;
}

