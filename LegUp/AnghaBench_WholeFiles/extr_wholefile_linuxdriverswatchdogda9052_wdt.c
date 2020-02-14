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
struct da9052_wdt_data {unsigned long jpast; struct watchdog_device wdt; struct da9052* da9052; } ;
struct da9052 {TYPE_1__* dev; } ;
struct TYPE_7__ {unsigned int time; int reg_val; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_4__*) ; 
 int /*<<< orphan*/  DA9052_CONTROLD_TWDSCALE ; 
 int /*<<< orphan*/  DA9052_CONTROLD_WATCHDOG ; 
 int /*<<< orphan*/  DA9052_CONTROL_D_REG ; 
 unsigned int DA9052_DEF_TIMEOUT ; 
 unsigned long DA9052_TWDMIN ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 unsigned long HZ ; 
 int da9052_reg_update (struct da9052*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  da9052_wdt_info ; 
 TYPE_4__* da9052_wdt_maps ; 
 int /*<<< orphan*/  da9052_wdt_ops ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*,int) ; 
 struct da9052* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 struct da9052_wdt_data* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 int devm_watchdog_register_device (TYPE_1__*,struct watchdog_device*) ; 
 void* jiffies ; 
 int /*<<< orphan*/  mdelay (unsigned long) ; 
 int /*<<< orphan*/  udelay (int) ; 
 struct da9052_wdt_data* watchdog_get_drvdata (struct watchdog_device*) ; 
 int /*<<< orphan*/  watchdog_set_drvdata (struct watchdog_device*,struct da9052_wdt_data*) ; 

__attribute__((used)) static int da9052_wdt_set_timeout(struct watchdog_device *wdt_dev,
				  unsigned int timeout)
{
	struct da9052_wdt_data *driver_data = watchdog_get_drvdata(wdt_dev);
	struct da9052 *da9052 = driver_data->da9052;
	int ret, i;

	/*
	 * Disable the Watchdog timer before setting
	 * new time out.
	 */
	ret = da9052_reg_update(da9052, DA9052_CONTROL_D_REG,
				DA9052_CONTROLD_TWDSCALE, 0);
	if (ret < 0) {
		dev_err(da9052->dev, "Failed to disable watchdog bit, %d\n",
			ret);
		return ret;
	}
	if (timeout) {
		/*
		 * To change the timeout, da9052 needs to
		 * be disabled for at least 150 us.
		 */
		udelay(150);

		/* Set the desired timeout */
		for (i = 0; i < ARRAY_SIZE(da9052_wdt_maps); i++)
			if (da9052_wdt_maps[i].time == timeout)
				break;

		if (i == ARRAY_SIZE(da9052_wdt_maps))
			ret = -EINVAL;
		else
			ret = da9052_reg_update(da9052, DA9052_CONTROL_D_REG,
						DA9052_CONTROLD_TWDSCALE,
						da9052_wdt_maps[i].reg_val);
		if (ret < 0) {
			dev_err(da9052->dev,
				"Failed to update timescale bit, %d\n", ret);
			return ret;
		}

		wdt_dev->timeout = timeout;
		driver_data->jpast = jiffies;
	}

	return 0;
}

__attribute__((used)) static int da9052_wdt_start(struct watchdog_device *wdt_dev)
{
	return da9052_wdt_set_timeout(wdt_dev, wdt_dev->timeout);
}

__attribute__((used)) static int da9052_wdt_stop(struct watchdog_device *wdt_dev)
{
	return da9052_wdt_set_timeout(wdt_dev, 0);
}

__attribute__((used)) static int da9052_wdt_ping(struct watchdog_device *wdt_dev)
{
	struct da9052_wdt_data *driver_data = watchdog_get_drvdata(wdt_dev);
	struct da9052 *da9052 = driver_data->da9052;
	unsigned long msec, jnow = jiffies;
	int ret;

	/*
	 * We have a minimum time for watchdog window called TWDMIN. A write
	 * to the watchdog before this elapsed time should cause an error.
	 */
	msec = (jnow - driver_data->jpast) * 1000/HZ;
	if (msec < DA9052_TWDMIN)
		mdelay(msec);

	/* Reset the watchdog timer */
	ret = da9052_reg_update(da9052, DA9052_CONTROL_D_REG,
				DA9052_CONTROLD_WATCHDOG, 1 << 7);
	if (ret < 0)
		return ret;

	/*
	 * FIXME: Reset the watchdog core, in general PMIC
	 * is supposed to do this
	 */
	return da9052_reg_update(da9052, DA9052_CONTROL_D_REG,
				 DA9052_CONTROLD_WATCHDOG, 0 << 7);
}

__attribute__((used)) static int da9052_wdt_probe(struct platform_device *pdev)
{
	struct da9052 *da9052 = dev_get_drvdata(pdev->dev.parent);
	struct da9052_wdt_data *driver_data;
	struct watchdog_device *da9052_wdt;
	int ret;

	driver_data = devm_kzalloc(&pdev->dev, sizeof(*driver_data),
				   GFP_KERNEL);
	if (!driver_data)
		return -ENOMEM;
	driver_data->da9052 = da9052;

	da9052_wdt = &driver_data->wdt;

	da9052_wdt->timeout = DA9052_DEF_TIMEOUT;
	da9052_wdt->info = &da9052_wdt_info;
	da9052_wdt->ops = &da9052_wdt_ops;
	da9052_wdt->parent = &pdev->dev;
	watchdog_set_drvdata(da9052_wdt, driver_data);

	ret = da9052_reg_update(da9052, DA9052_CONTROL_D_REG,
				DA9052_CONTROLD_TWDSCALE, 0);
	if (ret < 0) {
		dev_err(&pdev->dev, "Failed to disable watchdog bits, %d\n",
			ret);
		return ret;
	}

	ret = devm_watchdog_register_device(&pdev->dev, &driver_data->wdt);
	if (ret != 0) {
		dev_err(da9052->dev, "watchdog_register_device() failed: %d\n",
			ret);
		return ret;
	}

	return ret;
}

