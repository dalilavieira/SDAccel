#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_4__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct watchdog_device {unsigned int timeout; TYPE_1__* parent; int /*<<< orphan*/ * ops; int /*<<< orphan*/ * info; } ;
struct TYPE_6__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_1__ dev; } ;
struct da9055_wdt_data {struct watchdog_device wdt; struct da9055* da9055; } ;
struct da9055 {TYPE_1__* dev; } ;
struct TYPE_7__ {unsigned int user_time; int reg_val; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_4__*) ; 
 unsigned int DA9055_DEF_TIMEOUT ; 
 int /*<<< orphan*/  DA9055_REG_CONTROL_B ; 
 int /*<<< orphan*/  DA9055_REG_CONTROL_E ; 
 int /*<<< orphan*/  DA9055_TWDMIN ; 
 int /*<<< orphan*/  DA9055_TWDSCALE_MASK ; 
 int DA9055_TWDSCALE_SHIFT ; 
 int /*<<< orphan*/  DA9055_WATCHDOG_MASK ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int da9055_reg_update (struct da9055*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  da9055_wdt_info ; 
 TYPE_4__* da9055_wdt_maps ; 
 int /*<<< orphan*/  da9055_wdt_ops ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*,int) ; 
 struct da9055* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 struct da9055_wdt_data* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 int devm_watchdog_register_device (TYPE_1__*,struct watchdog_device*) ; 
 int /*<<< orphan*/  mdelay (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nowayout ; 
 struct da9055_wdt_data* watchdog_get_drvdata (struct watchdog_device*) ; 
 int /*<<< orphan*/  watchdog_set_drvdata (struct watchdog_device*,struct da9055_wdt_data*) ; 
 int /*<<< orphan*/  watchdog_set_nowayout (struct watchdog_device*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int da9055_wdt_set_timeout(struct watchdog_device *wdt_dev,
				  unsigned int timeout)
{
	struct da9055_wdt_data *driver_data = watchdog_get_drvdata(wdt_dev);
	struct da9055 *da9055 = driver_data->da9055;
	int ret, i;

	for (i = 0; i < ARRAY_SIZE(da9055_wdt_maps); i++)
		if (da9055_wdt_maps[i].user_time == timeout)
			break;

	if (i == ARRAY_SIZE(da9055_wdt_maps))
		ret = -EINVAL;
	else
		ret = da9055_reg_update(da9055, DA9055_REG_CONTROL_B,
					DA9055_TWDSCALE_MASK,
					da9055_wdt_maps[i].reg_val <<
					DA9055_TWDSCALE_SHIFT);
	if (ret < 0) {
		dev_err(da9055->dev,
			"Failed to update timescale bit, %d\n", ret);
		return ret;
	}

	wdt_dev->timeout = timeout;

	return 0;
}

__attribute__((used)) static int da9055_wdt_ping(struct watchdog_device *wdt_dev)
{
	struct da9055_wdt_data *driver_data = watchdog_get_drvdata(wdt_dev);
	struct da9055 *da9055 = driver_data->da9055;

	/*
	 * We have a minimum time for watchdog window called TWDMIN. A write
	 * to the watchdog before this elapsed time will cause an error.
	 */
	mdelay(DA9055_TWDMIN);

	/* Reset the watchdog timer */
	return da9055_reg_update(da9055, DA9055_REG_CONTROL_E,
				 DA9055_WATCHDOG_MASK, 1);
}

__attribute__((used)) static int da9055_wdt_start(struct watchdog_device *wdt_dev)
{
	return da9055_wdt_set_timeout(wdt_dev, wdt_dev->timeout);
}

__attribute__((used)) static int da9055_wdt_stop(struct watchdog_device *wdt_dev)
{
	return da9055_wdt_set_timeout(wdt_dev, 0);
}

__attribute__((used)) static int da9055_wdt_probe(struct platform_device *pdev)
{
	struct da9055 *da9055 = dev_get_drvdata(pdev->dev.parent);
	struct da9055_wdt_data *driver_data;
	struct watchdog_device *da9055_wdt;
	int ret;

	driver_data = devm_kzalloc(&pdev->dev, sizeof(*driver_data),
				   GFP_KERNEL);
	if (!driver_data)
		return -ENOMEM;

	driver_data->da9055 = da9055;

	da9055_wdt = &driver_data->wdt;

	da9055_wdt->timeout = DA9055_DEF_TIMEOUT;
	da9055_wdt->info = &da9055_wdt_info;
	da9055_wdt->ops = &da9055_wdt_ops;
	da9055_wdt->parent = &pdev->dev;
	watchdog_set_nowayout(da9055_wdt, nowayout);
	watchdog_set_drvdata(da9055_wdt, driver_data);

	ret = da9055_wdt_stop(da9055_wdt);
	if (ret < 0) {
		dev_err(&pdev->dev, "Failed to stop watchdog, %d\n", ret);
		return ret;
	}

	ret = devm_watchdog_register_device(&pdev->dev, &driver_data->wdt);
	if (ret != 0)
		dev_err(da9055->dev, "watchdog_register_device() failed: %d\n",
			ret);

	return ret;
}

