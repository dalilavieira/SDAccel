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
struct watchdog_device {unsigned int timeout; struct device* parent; int /*<<< orphan*/  min_timeout; int /*<<< orphan*/  max_timeout; int /*<<< orphan*/ * ops; int /*<<< orphan*/ * info; } ;
struct uniphier_wdt_dev {struct watchdog_device wdt_dev; struct regmap* regmap; } ;
struct regmap {int dummy; } ;
struct device {int /*<<< orphan*/  of_node; } ;
struct platform_device {struct device dev; } ;
struct device_node {int dummy; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct regmap*) ; 
 int PTR_ERR (struct regmap*) ; 
 int SEC_TO_WDTTIMSET_PRD (unsigned int) ; 
 int /*<<< orphan*/  WDTCTRL ; 
 int WDTCTRL_CLEAR ; 
 int WDTCTRL_ENABLE ; 
 unsigned int WDTCTRL_STATUS ; 
 int /*<<< orphan*/  WDTRSTSEL ; 
 int WDTRSTSEL_RSTSEL_BOTH ; 
 int /*<<< orphan*/  WDTST_TIMEOUT ; 
 int /*<<< orphan*/  WDTTIMSET ; 
 unsigned int WDT_DEFAULT_TIMEOUT ; 
 int /*<<< orphan*/  WDT_PERIOD_MAX ; 
 int /*<<< orphan*/  WDT_PERIOD_MIN ; 
 int /*<<< orphan*/  dev_info (struct device*,char*,unsigned int,int /*<<< orphan*/ ) ; 
 struct uniphier_wdt_dev* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_watchdog_register_device (struct device*,struct watchdog_device*) ; 
 int /*<<< orphan*/  nowayout ; 
 struct device_node* of_get_parent (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct uniphier_wdt_dev*) ; 
 int regmap_read_poll_timeout (struct regmap*,int /*<<< orphan*/ ,unsigned int,unsigned int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int regmap_write (struct regmap*,int /*<<< orphan*/ ,int) ; 
 int regmap_write_bits (struct regmap*,int /*<<< orphan*/ ,int,int) ; 
 unsigned int roundup_pow_of_two (unsigned int) ; 
 struct regmap* syscon_node_to_regmap (struct device_node*) ; 
 int /*<<< orphan*/  timeout ; 
 int /*<<< orphan*/  uniphier_wdt_info ; 
 int /*<<< orphan*/  uniphier_wdt_ops ; 
 scalar_t__ watchdog_active (struct watchdog_device*) ; 
 struct uniphier_wdt_dev* watchdog_get_drvdata (struct watchdog_device*) ; 
 int /*<<< orphan*/  watchdog_init_timeout (struct watchdog_device*,int /*<<< orphan*/ ,struct device*) ; 
 int /*<<< orphan*/  watchdog_set_drvdata (struct watchdog_device*,struct uniphier_wdt_dev*) ; 
 int /*<<< orphan*/  watchdog_set_nowayout (struct watchdog_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  watchdog_stop_on_reboot (struct watchdog_device*) ; 

__attribute__((used)) static int uniphier_watchdog_ping(struct watchdog_device *w)
{
	struct uniphier_wdt_dev *wdev = watchdog_get_drvdata(w);
	unsigned int val;
	int ret;

	/* Clear counter */
	ret = regmap_write_bits(wdev->regmap, WDTCTRL,
				WDTCTRL_CLEAR, WDTCTRL_CLEAR);
	if (!ret)
		/*
		 * As SoC specification, after clear counter,
		 * it needs to wait until counter status is 1.
		 */
		ret = regmap_read_poll_timeout(wdev->regmap, WDTCTRL, val,
					       (val & WDTCTRL_STATUS),
					       0, WDTST_TIMEOUT);

	return ret;
}

__attribute__((used)) static int __uniphier_watchdog_start(struct regmap *regmap, unsigned int sec)
{
	unsigned int val;
	int ret;

	ret = regmap_read_poll_timeout(regmap, WDTCTRL, val,
				       !(val & WDTCTRL_STATUS),
				       0, WDTST_TIMEOUT);
	if (ret)
		return ret;

	/* Setup period */
	ret = regmap_write(regmap, WDTTIMSET,
			   SEC_TO_WDTTIMSET_PRD(sec));
	if (ret)
		return ret;

	/* Enable and clear watchdog */
	ret = regmap_write(regmap, WDTCTRL, WDTCTRL_ENABLE | WDTCTRL_CLEAR);
	if (!ret)
		/*
		 * As SoC specification, after clear counter,
		 * it needs to wait until counter status is 1.
		 */
		ret = regmap_read_poll_timeout(regmap, WDTCTRL, val,
					       (val & WDTCTRL_STATUS),
					       0, WDTST_TIMEOUT);

	return ret;
}

__attribute__((used)) static int __uniphier_watchdog_stop(struct regmap *regmap)
{
	/* Disable and stop watchdog */
	return regmap_write_bits(regmap, WDTCTRL, WDTCTRL_ENABLE, 0);
}

__attribute__((used)) static int __uniphier_watchdog_restart(struct regmap *regmap, unsigned int sec)
{
	int ret;

	ret = __uniphier_watchdog_stop(regmap);
	if (ret)
		return ret;

	return __uniphier_watchdog_start(regmap, sec);
}

__attribute__((used)) static int uniphier_watchdog_start(struct watchdog_device *w)
{
	struct uniphier_wdt_dev *wdev = watchdog_get_drvdata(w);
	unsigned int tmp_timeout;

	tmp_timeout = roundup_pow_of_two(w->timeout);

	return __uniphier_watchdog_start(wdev->regmap, tmp_timeout);
}

__attribute__((used)) static int uniphier_watchdog_stop(struct watchdog_device *w)
{
	struct uniphier_wdt_dev *wdev = watchdog_get_drvdata(w);

	return __uniphier_watchdog_stop(wdev->regmap);
}

__attribute__((used)) static int uniphier_watchdog_set_timeout(struct watchdog_device *w,
					 unsigned int t)
{
	struct uniphier_wdt_dev *wdev = watchdog_get_drvdata(w);
	unsigned int tmp_timeout;
	int ret;

	tmp_timeout = roundup_pow_of_two(t);
	if (tmp_timeout == w->timeout)
		return 0;

	if (watchdog_active(w)) {
		ret = __uniphier_watchdog_restart(wdev->regmap, tmp_timeout);
		if (ret)
			return ret;
	}

	w->timeout = tmp_timeout;

	return 0;
}

__attribute__((used)) static int uniphier_wdt_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct uniphier_wdt_dev *wdev;
	struct regmap *regmap;
	struct device_node *parent;
	int ret;

	wdev = devm_kzalloc(dev, sizeof(*wdev), GFP_KERNEL);
	if (!wdev)
		return -ENOMEM;

	platform_set_drvdata(pdev, wdev);

	parent = of_get_parent(dev->of_node); /* parent should be syscon node */
	regmap = syscon_node_to_regmap(parent);
	of_node_put(parent);
	if (IS_ERR(regmap))
		return PTR_ERR(regmap);

	wdev->regmap = regmap;
	wdev->wdt_dev.info = &uniphier_wdt_info;
	wdev->wdt_dev.ops = &uniphier_wdt_ops;
	wdev->wdt_dev.max_timeout = WDT_PERIOD_MAX;
	wdev->wdt_dev.min_timeout = WDT_PERIOD_MIN;
	wdev->wdt_dev.timeout = WDT_DEFAULT_TIMEOUT;
	wdev->wdt_dev.parent = dev;

	watchdog_init_timeout(&wdev->wdt_dev, timeout, dev);
	watchdog_set_nowayout(&wdev->wdt_dev, nowayout);
	watchdog_stop_on_reboot(&wdev->wdt_dev);

	watchdog_set_drvdata(&wdev->wdt_dev, wdev);

	uniphier_watchdog_stop(&wdev->wdt_dev);
	ret = regmap_write(wdev->regmap, WDTRSTSEL, WDTRSTSEL_RSTSEL_BOTH);
	if (ret)
		return ret;

	ret = devm_watchdog_register_device(dev, &wdev->wdt_dev);
	if (ret)
		return ret;

	dev_info(dev, "watchdog driver (timeout=%d sec, nowayout=%d)\n",
		 wdev->wdt_dev.timeout, nowayout);

	return 0;
}

