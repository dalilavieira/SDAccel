#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct watchdog_device {unsigned int timeout; unsigned int min_timeout; unsigned int max_timeout; int /*<<< orphan*/ * ops; int /*<<< orphan*/ * info; TYPE_1__* parent; } ;
struct ts4800_wdt {struct watchdog_device wdd; int /*<<< orphan*/  regmap; int /*<<< orphan*/  feed_offset; int /*<<< orphan*/  feed_val; } ;
struct TYPE_6__ {struct device_node* of_node; } ;
struct platform_device {TYPE_1__ dev; } ;
struct device_node {int dummy; } ;
struct TYPE_7__ {unsigned int timeout; int /*<<< orphan*/  regval; } ;

/* Variables and functions */
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int MAX_TIMEOUT_INDEX ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TS4800_WDT_DISABLE ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*) ; 
 int /*<<< orphan*/  dev_info (TYPE_1__*,char*,unsigned int,int /*<<< orphan*/ ) ; 
 struct ts4800_wdt* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nowayout ; 
 struct device_node* of_parse_phandle (struct device_node*,char*,int /*<<< orphan*/ ) ; 
 int of_property_read_u32_index (struct device_node*,char*,int,int /*<<< orphan*/ *) ; 
 struct ts4800_wdt* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct ts4800_wdt*) ; 
 int /*<<< orphan*/  regmap_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  syscon_node_to_regmap (struct device_node*) ; 
 int /*<<< orphan*/  ts4800_wdt_info ; 
 TYPE_2__* ts4800_wdt_map ; 
 int /*<<< orphan*/  ts4800_wdt_ops ; 
 struct ts4800_wdt* watchdog_get_drvdata (struct watchdog_device*) ; 
 int /*<<< orphan*/  watchdog_init_timeout (struct watchdog_device*,int /*<<< orphan*/ ,TYPE_1__*) ; 
 int watchdog_register_device (struct watchdog_device*) ; 
 int /*<<< orphan*/  watchdog_set_drvdata (struct watchdog_device*,struct ts4800_wdt*) ; 
 int /*<<< orphan*/  watchdog_set_nowayout (struct watchdog_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  watchdog_unregister_device (struct watchdog_device*) ; 

__attribute__((used)) static void ts4800_write_feed(struct ts4800_wdt *wdt, u32 val)
{
	regmap_write(wdt->regmap, wdt->feed_offset, val);
}

__attribute__((used)) static int ts4800_wdt_start(struct watchdog_device *wdd)
{
	struct ts4800_wdt *wdt = watchdog_get_drvdata(wdd);

	ts4800_write_feed(wdt, wdt->feed_val);
	return 0;
}

__attribute__((used)) static int ts4800_wdt_stop(struct watchdog_device *wdd)
{
	struct ts4800_wdt *wdt = watchdog_get_drvdata(wdd);

	ts4800_write_feed(wdt, TS4800_WDT_DISABLE);
	return 0;
}

__attribute__((used)) static int ts4800_wdt_set_timeout(struct watchdog_device *wdd,
				  unsigned int timeout)
{
	struct ts4800_wdt *wdt = watchdog_get_drvdata(wdd);
	int i;

	for (i = 0; i < MAX_TIMEOUT_INDEX; i++) {
		if (ts4800_wdt_map[i].timeout >= timeout)
			break;
	}

	wdd->timeout = ts4800_wdt_map[i].timeout;
	wdt->feed_val = ts4800_wdt_map[i].regval;

	return 0;
}

__attribute__((used)) static int ts4800_wdt_probe(struct platform_device *pdev)
{
	struct device_node *np = pdev->dev.of_node;
	struct device_node *syscon_np;
	struct watchdog_device *wdd;
	struct ts4800_wdt *wdt;
	u32 reg;
	int ret;

	syscon_np = of_parse_phandle(np, "syscon", 0);
	if (!syscon_np) {
		dev_err(&pdev->dev, "no syscon property\n");
		return -ENODEV;
	}

	ret = of_property_read_u32_index(np, "syscon", 1, &reg);
	if (ret < 0) {
		dev_err(&pdev->dev, "no offset in syscon\n");
		return ret;
	}

	/* allocate memory for watchdog struct */
	wdt = devm_kzalloc(&pdev->dev, sizeof(*wdt), GFP_KERNEL);
	if (!wdt)
		return -ENOMEM;

	/* set regmap and offset to know where to write */
	wdt->feed_offset = reg;
	wdt->regmap = syscon_node_to_regmap(syscon_np);
	if (IS_ERR(wdt->regmap)) {
		dev_err(&pdev->dev, "cannot get parent's regmap\n");
		return PTR_ERR(wdt->regmap);
	}

	/* Initialize struct watchdog_device */
	wdd = &wdt->wdd;
	wdd->parent = &pdev->dev;
	wdd->info = &ts4800_wdt_info;
	wdd->ops = &ts4800_wdt_ops;
	wdd->min_timeout = ts4800_wdt_map[0].timeout;
	wdd->max_timeout = ts4800_wdt_map[MAX_TIMEOUT_INDEX].timeout;

	watchdog_set_drvdata(wdd, wdt);
	watchdog_set_nowayout(wdd, nowayout);
	watchdog_init_timeout(wdd, 0, &pdev->dev);

	/*
	 * As this watchdog supports only a few values, ts4800_wdt_set_timeout
	 * must be called to initialize timeout and feed_val with valid values.
	 * Default to maximum timeout if none, or an invalid one, is provided in
	 * device tree.
	 */
	if (!wdd->timeout)
		wdd->timeout = wdd->max_timeout;
	ts4800_wdt_set_timeout(wdd, wdd->timeout);

	/*
	 * The feed register is write-only, so it is not possible to determine
	 * watchdog's state. Disable it to be in a known state.
	 */
	ts4800_wdt_stop(wdd);

	ret = watchdog_register_device(wdd);
	if (ret) {
		dev_err(&pdev->dev,
			"failed to register watchdog device\n");
		return ret;
	}

	platform_set_drvdata(pdev, wdt);

	dev_info(&pdev->dev,
		 "initialized (timeout = %d sec, nowayout = %d)\n",
		 wdd->timeout, nowayout);

	return 0;
}

__attribute__((used)) static int ts4800_wdt_remove(struct platform_device *pdev)
{
	struct ts4800_wdt *wdt = platform_get_drvdata(pdev);

	watchdog_unregister_device(&wdt->wdd);

	return 0;
}

