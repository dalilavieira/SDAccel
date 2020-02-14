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
struct watchdog_device {unsigned int timeout; int /*<<< orphan*/  status; TYPE_1__* parent; int /*<<< orphan*/  min_hw_heartbeat_ms; int /*<<< orphan*/  max_timeout; int /*<<< orphan*/  min_timeout; int /*<<< orphan*/ * ops; int /*<<< orphan*/ * info; } ;
struct TYPE_3__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_1__ dev; } ;
struct da9063 {int /*<<< orphan*/  dev; int /*<<< orphan*/  regmap; } ;

/* Variables and functions */
 int /*<<< orphan*/  DA9063_REG_CONTROL_D ; 
 int /*<<< orphan*/  DA9063_REG_CONTROL_F ; 
 int /*<<< orphan*/  DA9063_RESET_PROTECTION_MS ; 
 int /*<<< orphan*/  DA9063_SHUTDOWN ; 
 unsigned int DA9063_TWDSCALE_DISABLE ; 
 unsigned int DA9063_TWDSCALE_MASK ; 
 unsigned int DA9063_TWDSCALE_MAX ; 
 unsigned int DA9063_TWDSCALE_MIN ; 
 int /*<<< orphan*/  DA9063_WATCHDOG ; 
 void* DA9063_WDG_TIMEOUT ; 
 int /*<<< orphan*/  DA9063_WDT_MAX_TIMEOUT ; 
 int /*<<< orphan*/  DA9063_WDT_MIN_TIMEOUT ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  WATCHDOG_NOWAYOUT_INIT_STATUS ; 
 int /*<<< orphan*/  WDOG_HW_RUNNING ; 
 int /*<<< orphan*/  da9063_watchdog_info ; 
 int /*<<< orphan*/  da9063_watchdog_ops ; 
 int /*<<< orphan*/  dev_alert (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,int) ; 
 struct da9063* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 struct watchdog_device* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 int devm_watchdog_register_device (TYPE_1__*,struct watchdog_device*) ; 
 int /*<<< orphan*/  regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int*) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int,unsigned int) ; 
 int regmap_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 
 scalar_t__ watchdog_active (struct watchdog_device*) ; 
 struct da9063* watchdog_get_drvdata (struct watchdog_device*) ; 
 int /*<<< orphan*/  watchdog_set_drvdata (struct watchdog_device*,struct da9063*) ; 
 int /*<<< orphan*/  watchdog_set_restart_priority (struct watchdog_device*,int) ; 
 unsigned int* wdt_timeout ; 

__attribute__((used)) static unsigned int da9063_wdt_timeout_to_sel(unsigned int secs)
{
	unsigned int i;

	for (i = DA9063_TWDSCALE_MIN; i <= DA9063_TWDSCALE_MAX; i++) {
		if (wdt_timeout[i] >= secs)
			return i;
	}

	return DA9063_TWDSCALE_MAX;
}

__attribute__((used)) static unsigned int da9063_wdt_is_running(struct da9063 *da9063)
{
	unsigned int val;

	regmap_read(da9063->regmap, DA9063_REG_CONTROL_D, &val);

	return val & DA9063_TWDSCALE_MASK;
}

__attribute__((used)) static int da9063_wdt_disable_timer(struct da9063 *da9063)
{
	return regmap_update_bits(da9063->regmap, DA9063_REG_CONTROL_D,
				  DA9063_TWDSCALE_MASK,
				  DA9063_TWDSCALE_DISABLE);
}

__attribute__((used)) static int
da9063_wdt_update_timeout(struct da9063 *da9063, unsigned int timeout)
{
	unsigned int regval;
	int ret;

	/*
	 * The watchdog triggers a reboot if a timeout value is already
	 * programmed because the timeout value combines two functions
	 * in one: indicating the counter limit and starting the watchdog.
	 * The watchdog must be disabled to be able to change the timeout
	 * value if the watchdog is already running. Then we can set the
	 * new timeout value which enables the watchdog again.
	 */
	ret = da9063_wdt_disable_timer(da9063);
	if (ret)
		return ret;

	usleep_range(150, 300);
	regval = da9063_wdt_timeout_to_sel(timeout);

	return regmap_update_bits(da9063->regmap, DA9063_REG_CONTROL_D,
				  DA9063_TWDSCALE_MASK, regval);
}

__attribute__((used)) static int da9063_wdt_start(struct watchdog_device *wdd)
{
	struct da9063 *da9063 = watchdog_get_drvdata(wdd);
	int ret;

	ret = da9063_wdt_update_timeout(da9063, wdd->timeout);
	if (ret)
		dev_err(da9063->dev, "Watchdog failed to start (err = %d)\n",
			ret);

	return ret;
}

__attribute__((used)) static int da9063_wdt_stop(struct watchdog_device *wdd)
{
	struct da9063 *da9063 = watchdog_get_drvdata(wdd);
	int ret;

	ret = da9063_wdt_disable_timer(da9063);
	if (ret)
		dev_alert(da9063->dev, "Watchdog failed to stop (err = %d)\n",
			  ret);

	return ret;
}

__attribute__((used)) static int da9063_wdt_ping(struct watchdog_device *wdd)
{
	struct da9063 *da9063 = watchdog_get_drvdata(wdd);
	int ret;

	ret = regmap_write(da9063->regmap, DA9063_REG_CONTROL_F,
			   DA9063_WATCHDOG);
	if (ret)
		dev_alert(da9063->dev, "Failed to ping the watchdog (err = %d)\n",
			  ret);

	return ret;
}

__attribute__((used)) static int da9063_wdt_set_timeout(struct watchdog_device *wdd,
				  unsigned int timeout)
{
	struct da9063 *da9063 = watchdog_get_drvdata(wdd);
	int ret = 0;

	/*
	 * There are two cases when a set_timeout() will be called:
	 * 1. The watchdog is off and someone wants to set the timeout for the
	 *    further use.
	 * 2. The watchdog is already running and a new timeout value should be
	 *    set.
	 *
	 * The watchdog can't store a timeout value not equal zero without
	 * enabling the watchdog, so the timeout must be buffered by the driver.
	 */
	if (watchdog_active(wdd))
		ret = da9063_wdt_update_timeout(da9063, timeout);

	if (ret)
		dev_err(da9063->dev, "Failed to set watchdog timeout (err = %d)\n",
			ret);
	else
		wdd->timeout = wdt_timeout[da9063_wdt_timeout_to_sel(timeout)];

	return ret;
}

__attribute__((used)) static int da9063_wdt_restart(struct watchdog_device *wdd, unsigned long action,
			      void *data)
{
	struct da9063 *da9063 = watchdog_get_drvdata(wdd);
	int ret;

	ret = regmap_write(da9063->regmap, DA9063_REG_CONTROL_F,
			   DA9063_SHUTDOWN);
	if (ret)
		dev_alert(da9063->dev, "Failed to shutdown (err = %d)\n",
			  ret);

	return ret;
}

__attribute__((used)) static int da9063_wdt_probe(struct platform_device *pdev)
{
	struct da9063 *da9063;
	struct watchdog_device *wdd;

	if (!pdev->dev.parent)
		return -EINVAL;

	da9063 = dev_get_drvdata(pdev->dev.parent);
	if (!da9063)
		return -EINVAL;

	wdd = devm_kzalloc(&pdev->dev, sizeof(*wdd), GFP_KERNEL);
	if (!wdd)
		return -ENOMEM;

	wdd->info = &da9063_watchdog_info;
	wdd->ops = &da9063_watchdog_ops;
	wdd->min_timeout = DA9063_WDT_MIN_TIMEOUT;
	wdd->max_timeout = DA9063_WDT_MAX_TIMEOUT;
	wdd->min_hw_heartbeat_ms = DA9063_RESET_PROTECTION_MS;
	wdd->timeout = DA9063_WDG_TIMEOUT;
	wdd->parent = &pdev->dev;

	wdd->status = WATCHDOG_NOWAYOUT_INIT_STATUS;

	watchdog_set_restart_priority(wdd, 128);

	watchdog_set_drvdata(wdd, da9063);

	/* Change the timeout to the default value if the watchdog is running */
	if (da9063_wdt_is_running(da9063)) {
		da9063_wdt_update_timeout(da9063, DA9063_WDG_TIMEOUT);
		set_bit(WDOG_HW_RUNNING, &wdd->status);
	}

	return devm_watchdog_register_device(&pdev->dev, wdd);
}

