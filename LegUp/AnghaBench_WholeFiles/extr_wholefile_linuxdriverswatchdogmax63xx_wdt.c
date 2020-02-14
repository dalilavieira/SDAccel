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
typedef  int u8 ;
struct watchdog_device {int dummy; } ;
struct resource {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; TYPE_1__* id_entry; } ;
struct TYPE_7__ {int timeout; int /*<<< orphan*/ * ops; int /*<<< orphan*/ * info; int /*<<< orphan*/ * parent; } ;
struct max63xx_wdt {void (* ping ) (struct max63xx_wdt*) ;void (* set ) (struct max63xx_wdt*,int) ;struct max63xx_timeout* timeout; TYPE_2__ wdd; int /*<<< orphan*/  lock; int /*<<< orphan*/  base; } ;
struct max63xx_timeout {int twd; scalar_t__ tdelay; int wdset; } ;
struct TYPE_6__ {scalar_t__ driver_data; } ;

/* Variables and functions */
 int DEFAULT_HEARTBEAT ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int MAX6369_WDI ; 
 int MAX6369_WDSET ; 
 int MAX6369_WDSET_DISABLED ; 
 int MAX_HEARTBEAT ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int __raw_readb (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __raw_writeb (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,int,scalar_t__) ; 
 int /*<<< orphan*/  devm_ioremap_resource (int /*<<< orphan*/ *,struct resource*) ; 
 struct max63xx_wdt* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int heartbeat ; 
 int /*<<< orphan*/  max63xx_wdt_info ; 
 int /*<<< orphan*/  max63xx_wdt_ops ; 
 scalar_t__ nodelay ; 
 int /*<<< orphan*/  nowayout ; 
 struct watchdog_device* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,TYPE_2__*) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 void stub1 (struct max63xx_wdt*) ; 
 void stub2 (struct max63xx_wdt*,int) ; 
 void stub3 (struct max63xx_wdt*) ; 
 void stub4 (struct max63xx_wdt*,int) ; 
 struct max63xx_wdt* watchdog_get_drvdata (struct watchdog_device*) ; 
 int watchdog_register_device (TYPE_2__*) ; 
 int /*<<< orphan*/  watchdog_set_drvdata (TYPE_2__*,struct max63xx_wdt*) ; 
 int /*<<< orphan*/  watchdog_set_nowayout (TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  watchdog_unregister_device (struct watchdog_device*) ; 

__attribute__((used)) static struct max63xx_timeout *
max63xx_select_timeout(struct max63xx_timeout *table, int value)
{
	while (table->twd) {
		if (value <= table->twd) {
			if (nodelay && table->tdelay == 0)
				return table;

			if (!nodelay)
				return table;
		}

		table++;
	}

	return NULL;
}

__attribute__((used)) static int max63xx_wdt_ping(struct watchdog_device *wdd)
{
	struct max63xx_wdt *wdt = watchdog_get_drvdata(wdd);

	wdt->ping(wdt);
	return 0;
}

__attribute__((used)) static int max63xx_wdt_start(struct watchdog_device *wdd)
{
	struct max63xx_wdt *wdt = watchdog_get_drvdata(wdd);

	wdt->set(wdt, wdt->timeout->wdset);

	/* check for a edge triggered startup */
	if (wdt->timeout->tdelay == 0)
		wdt->ping(wdt);
	return 0;
}

__attribute__((used)) static int max63xx_wdt_stop(struct watchdog_device *wdd)
{
	struct max63xx_wdt *wdt = watchdog_get_drvdata(wdd);

	wdt->set(wdt, MAX6369_WDSET_DISABLED);
	return 0;
}

__attribute__((used)) static void max63xx_mmap_ping(struct max63xx_wdt *wdt)
{
	u8 val;

	spin_lock(&wdt->lock);

	val = __raw_readb(wdt->base);

	__raw_writeb(val | MAX6369_WDI, wdt->base);
	__raw_writeb(val & ~MAX6369_WDI, wdt->base);

	spin_unlock(&wdt->lock);
}

__attribute__((used)) static void max63xx_mmap_set(struct max63xx_wdt *wdt, u8 set)
{
	u8 val;

	spin_lock(&wdt->lock);

	val = __raw_readb(wdt->base);
	val &= ~MAX6369_WDSET;
	val |= set & MAX6369_WDSET;
	__raw_writeb(val, wdt->base);

	spin_unlock(&wdt->lock);
}

__attribute__((used)) static int max63xx_mmap_init(struct platform_device *p, struct max63xx_wdt *wdt)
{
	struct resource *mem = platform_get_resource(p, IORESOURCE_MEM, 0);

	wdt->base = devm_ioremap_resource(&p->dev, mem);
	if (IS_ERR(wdt->base))
		return PTR_ERR(wdt->base);

	spin_lock_init(&wdt->lock);

	wdt->ping = max63xx_mmap_ping;
	wdt->set = max63xx_mmap_set;
	return 0;
}

__attribute__((used)) static int max63xx_wdt_probe(struct platform_device *pdev)
{
	struct max63xx_wdt *wdt;
	struct max63xx_timeout *table;
	int err;

	wdt = devm_kzalloc(&pdev->dev, sizeof(*wdt), GFP_KERNEL);
	if (!wdt)
		return -ENOMEM;

	table = (struct max63xx_timeout *)pdev->id_entry->driver_data;

	if (heartbeat < 1 || heartbeat > MAX_HEARTBEAT)
		heartbeat = DEFAULT_HEARTBEAT;

	wdt->timeout = max63xx_select_timeout(table, heartbeat);
	if (!wdt->timeout) {
		dev_err(&pdev->dev, "unable to satisfy %ds heartbeat request\n",
			heartbeat);
		return -EINVAL;
	}

	err = max63xx_mmap_init(pdev, wdt);
	if (err)
		return err;

	platform_set_drvdata(pdev, &wdt->wdd);
	watchdog_set_drvdata(&wdt->wdd, wdt);

	wdt->wdd.parent = &pdev->dev;
	wdt->wdd.timeout = wdt->timeout->twd;
	wdt->wdd.info = &max63xx_wdt_info;
	wdt->wdd.ops = &max63xx_wdt_ops;

	watchdog_set_nowayout(&wdt->wdd, nowayout);

	err = watchdog_register_device(&wdt->wdd);
	if (err)
		return err;

	dev_info(&pdev->dev, "using %ds heartbeat with %ds initial delay\n",
		 wdt->timeout->twd, wdt->timeout->tdelay);
	return 0;
}

__attribute__((used)) static int max63xx_wdt_remove(struct platform_device *pdev)
{
	struct watchdog_device *wdd = platform_get_drvdata(pdev);

	watchdog_unregister_device(wdd);
	return 0;
}

