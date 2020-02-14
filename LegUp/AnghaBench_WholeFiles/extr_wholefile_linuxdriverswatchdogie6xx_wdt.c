#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_5__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  unsigned int u64 ;
typedef  int u32 ;
struct watchdog_device {unsigned int timeout; } ;
struct resource {scalar_t__ start; } ;
struct platform_device {int /*<<< orphan*/  dev; int /*<<< orphan*/  name; } ;
struct TYPE_7__ {scalar_t__ sch_wdtba; int /*<<< orphan*/  unlock_sequence; } ;
struct TYPE_6__ {int /*<<< orphan*/ * parent; int /*<<< orphan*/  timeout; } ;

/* Variables and functions */
 int EBUSY ; 
 int ENODEV ; 
 int /*<<< orphan*/  IORESOURCE_IO ; 
 scalar_t__ PV1 ; 
 scalar_t__ PV2 ; 
 scalar_t__ RR0 ; 
 scalar_t__ RR1 ; 
 scalar_t__ WDTCR ; 
 scalar_t__ WDTLR ; 
 int WDT_ENABLE ; 
 int WDT_LOCK ; 
 int WDT_RELOAD ; 
 int WDT_TOUT ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,scalar_t__) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*,int) ; 
 TYPE_5__ ie6xx_wdt_data ; 
 TYPE_1__ ie6xx_wdt_dev ; 
 int inb (scalar_t__) ; 
 int /*<<< orphan*/  nowayout ; 
 int /*<<< orphan*/  outb (int,scalar_t__) ; 
 int /*<<< orphan*/  outl (int,scalar_t__) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  release_region (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  request_region (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int resetmode ; 
 int /*<<< orphan*/  resource_size (struct resource*) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  timeout ; 
 int watchdog_register_device (TYPE_1__*) ; 
 int /*<<< orphan*/  watchdog_set_nowayout (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  watchdog_unregister_device (TYPE_1__*) ; 

__attribute__((used)) static void ie6xx_wdt_unlock_registers(void)
{
	outb(0x80, ie6xx_wdt_data.sch_wdtba + RR0);
	outb(0x86, ie6xx_wdt_data.sch_wdtba + RR0);
}

__attribute__((used)) static int ie6xx_wdt_ping(struct watchdog_device *wdd)
{
	spin_lock(&ie6xx_wdt_data.unlock_sequence);
	ie6xx_wdt_unlock_registers();
	outb(WDT_RELOAD, ie6xx_wdt_data.sch_wdtba + RR1);
	spin_unlock(&ie6xx_wdt_data.unlock_sequence);
	return 0;
}

__attribute__((used)) static int ie6xx_wdt_set_timeout(struct watchdog_device *wdd, unsigned int t)
{
	u32 preload;
	u64 clock;
	u8 wdtcr;

	/* Watchdog clock is PCI Clock (33MHz) */
	clock = 33000000;
	/* and the preload value is loaded into [34:15] of the down counter */
	preload = (t * clock) >> 15;
	/*
	 * Manual states preload must be one less.
	 * Does not wrap as t is at least 1
	 */
	preload -= 1;

	spin_lock(&ie6xx_wdt_data.unlock_sequence);

	/* Set ResetMode & Enable prescaler for range 10ms to 10 min */
	wdtcr = resetmode & 0x38;
	outb(wdtcr, ie6xx_wdt_data.sch_wdtba + WDTCR);

	ie6xx_wdt_unlock_registers();
	outl(0, ie6xx_wdt_data.sch_wdtba + PV1);

	ie6xx_wdt_unlock_registers();
	outl(preload, ie6xx_wdt_data.sch_wdtba + PV2);

	ie6xx_wdt_unlock_registers();
	outb(WDT_RELOAD | WDT_TOUT, ie6xx_wdt_data.sch_wdtba + RR1);

	spin_unlock(&ie6xx_wdt_data.unlock_sequence);

	wdd->timeout = t;
	return 0;
}

__attribute__((used)) static int ie6xx_wdt_start(struct watchdog_device *wdd)
{
	ie6xx_wdt_set_timeout(wdd, wdd->timeout);

	/* Enable the watchdog timer */
	spin_lock(&ie6xx_wdt_data.unlock_sequence);
	outb(WDT_ENABLE, ie6xx_wdt_data.sch_wdtba + WDTLR);
	spin_unlock(&ie6xx_wdt_data.unlock_sequence);

	return 0;
}

__attribute__((used)) static int ie6xx_wdt_stop(struct watchdog_device *wdd)
{
	if (inb(ie6xx_wdt_data.sch_wdtba + WDTLR) & WDT_LOCK)
		return -1;

	/* Disable the watchdog timer */
	spin_lock(&ie6xx_wdt_data.unlock_sequence);
	outb(0, ie6xx_wdt_data.sch_wdtba + WDTLR);
	spin_unlock(&ie6xx_wdt_data.unlock_sequence);

	return 0;
}

__attribute__((used)) static void ie6xx_wdt_debugfs_init(void)
{
}

__attribute__((used)) static void ie6xx_wdt_debugfs_exit(void)
{
}

__attribute__((used)) static int ie6xx_wdt_probe(struct platform_device *pdev)
{
	struct resource *res;
	u8 wdtlr;
	int ret;

	res = platform_get_resource(pdev, IORESOURCE_IO, 0);
	if (!res)
		return -ENODEV;

	if (!request_region(res->start, resource_size(res), pdev->name)) {
		dev_err(&pdev->dev, "Watchdog region 0x%llx already in use!\n",
			(u64)res->start);
		return -EBUSY;
	}

	ie6xx_wdt_data.sch_wdtba = res->start;
	dev_dbg(&pdev->dev, "WDT = 0x%X\n", ie6xx_wdt_data.sch_wdtba);

	ie6xx_wdt_dev.timeout = timeout;
	watchdog_set_nowayout(&ie6xx_wdt_dev, nowayout);
	ie6xx_wdt_dev.parent = &pdev->dev;

	spin_lock_init(&ie6xx_wdt_data.unlock_sequence);

	wdtlr = inb(ie6xx_wdt_data.sch_wdtba + WDTLR);
	if (wdtlr & WDT_LOCK)
		dev_warn(&pdev->dev,
			"Watchdog Timer is Locked (Reg=0x%x)\n", wdtlr);

	ie6xx_wdt_debugfs_init();

	ret = watchdog_register_device(&ie6xx_wdt_dev);
	if (ret) {
		dev_err(&pdev->dev,
			"Watchdog timer: cannot register device (err =%d)\n",
									ret);
		goto misc_register_error;
	}

	return 0;

misc_register_error:
	ie6xx_wdt_debugfs_exit();
	release_region(res->start, resource_size(res));
	ie6xx_wdt_data.sch_wdtba = 0;
	return ret;
}

__attribute__((used)) static int ie6xx_wdt_remove(struct platform_device *pdev)
{
	struct resource *res;

	res = platform_get_resource(pdev, IORESOURCE_IO, 0);
	ie6xx_wdt_stop(NULL);
	watchdog_unregister_device(&ie6xx_wdt_dev);
	ie6xx_wdt_debugfs_exit();
	release_region(res->start, resource_size(res));
	ie6xx_wdt_data.sch_wdtba = 0;

	return 0;
}

