#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct watchdog_device {int timeout; } ;
struct timer_list {int dummy; } ;
struct pci_device_id {int dummy; } ;
struct pci_dev {int /*<<< orphan*/  dev; } ;
struct TYPE_10__ {int timeout; int /*<<< orphan*/  bootstatus; int /*<<< orphan*/ * parent; } ;
struct TYPE_9__ {int /*<<< orphan*/  start; } ;

/* Variables and functions */
 int ENODEV ; 
 int HZ ; 
 int /*<<< orphan*/  VIA_WDT_CONF ; 
 unsigned char VIA_WDT_CONF_ENABLE ; 
 unsigned char VIA_WDT_CONF_MMIO ; 
 int VIA_WDT_COUNT ; 
 int VIA_WDT_FIRED ; 
 int /*<<< orphan*/  VIA_WDT_MMIO_BASE ; 
 int /*<<< orphan*/  VIA_WDT_MMIO_LEN ; 
 unsigned int VIA_WDT_RUNNING ; 
 unsigned int VIA_WDT_TRIGGER ; 
 int /*<<< orphan*/  WDIOF_CARDRESET ; 
 scalar_t__ WDT_HEARTBEAT ; 
 int WDT_TIMEOUT ; 
 int WDT_TIMEOUT_MAX ; 
 scalar_t__ allocate_resource (int /*<<< orphan*/ *,TYPE_1__*,int /*<<< orphan*/ ,int,int,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  del_timer_sync (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,scalar_t__) ; 
 int /*<<< orphan*/  iomem_resource ; 
 int /*<<< orphan*/ * ioremap (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iounmap (int /*<<< orphan*/ *) ; 
 scalar_t__ jiffies ; 
 scalar_t__ mmio ; 
 int /*<<< orphan*/  mod_timer (int /*<<< orphan*/ *,scalar_t__) ; 
 scalar_t__ next_heartbeat ; 
 int /*<<< orphan*/  nowayout ; 
 int /*<<< orphan*/  pci_disable_device (struct pci_dev*) ; 
 scalar_t__ pci_enable_device (struct pci_dev*) ; 
 int /*<<< orphan*/  pci_read_config_byte (struct pci_dev*,int /*<<< orphan*/ ,unsigned char*) ; 
 int /*<<< orphan*/  pci_read_config_dword (struct pci_dev*,int /*<<< orphan*/ ,scalar_t__*) ; 
 int /*<<< orphan*/  pci_write_config_byte (struct pci_dev*,int /*<<< orphan*/ ,unsigned char) ; 
 int /*<<< orphan*/  pci_write_config_dword (struct pci_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_crit (char*) ; 
 int readl (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  release_mem_region (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  release_resource (TYPE_1__*) ; 
 int /*<<< orphan*/  request_mem_region (scalar_t__,int /*<<< orphan*/ ,char*) ; 
 scalar_t__ time_before (scalar_t__,scalar_t__) ; 
 int timeout ; 
 int /*<<< orphan*/  timer ; 
 int /*<<< orphan*/  watchdog_active (TYPE_2__*) ; 
 int watchdog_register_device (TYPE_2__*) ; 
 int /*<<< orphan*/  watchdog_set_nowayout (TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  watchdog_unregister_device (TYPE_2__*) ; 
 TYPE_2__ wdt_dev ; 
 int /*<<< orphan*/ * wdt_mem ; 
 TYPE_1__ wdt_res ; 
 int /*<<< orphan*/  writel (unsigned int,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void wdt_reset(void)
{
	unsigned int ctl = readl(wdt_mem);

	writel(ctl | VIA_WDT_TRIGGER, wdt_mem);
}

__attribute__((used)) static void wdt_timer_tick(struct timer_list *unused)
{
	if (time_before(jiffies, next_heartbeat) ||
	   (!watchdog_active(&wdt_dev))) {
		wdt_reset();
		mod_timer(&timer, jiffies + WDT_HEARTBEAT);
	} else
		pr_crit("I will reboot your machine !\n");
}

__attribute__((used)) static int wdt_ping(struct watchdog_device *wdd)
{
	/* calculate when the next userspace timeout will be */
	next_heartbeat = jiffies + wdd->timeout * HZ;
	return 0;
}

__attribute__((used)) static int wdt_start(struct watchdog_device *wdd)
{
	unsigned int ctl = readl(wdt_mem);

	writel(wdd->timeout, wdt_mem + VIA_WDT_COUNT);
	writel(ctl | VIA_WDT_RUNNING | VIA_WDT_TRIGGER, wdt_mem);
	wdt_ping(wdd);
	mod_timer(&timer, jiffies + WDT_HEARTBEAT);
	return 0;
}

__attribute__((used)) static int wdt_stop(struct watchdog_device *wdd)
{
	unsigned int ctl = readl(wdt_mem);

	writel(ctl & ~VIA_WDT_RUNNING, wdt_mem);
	return 0;
}

__attribute__((used)) static int wdt_set_timeout(struct watchdog_device *wdd,
			   unsigned int new_timeout)
{
	writel(new_timeout, wdt_mem + VIA_WDT_COUNT);
	wdd->timeout = new_timeout;
	return 0;
}

__attribute__((used)) static int wdt_probe(struct pci_dev *pdev,
			       const struct pci_device_id *ent)
{
	unsigned char conf;
	int ret = -ENODEV;

	if (pci_enable_device(pdev)) {
		dev_err(&pdev->dev, "cannot enable PCI device\n");
		return -ENODEV;
	}

	/*
	 * Allocate a MMIO region which contains watchdog control register
	 * and counter, then configure the watchdog to use this region.
	 * This is possible only if PnP is properly enabled in BIOS.
	 * If not, the watchdog must be configured in BIOS manually.
	 */
	if (allocate_resource(&iomem_resource, &wdt_res, VIA_WDT_MMIO_LEN,
			      0xf0000000, 0xffffff00, 0xff, NULL, NULL)) {
		dev_err(&pdev->dev, "MMIO allocation failed\n");
		goto err_out_disable_device;
	}

	pci_write_config_dword(pdev, VIA_WDT_MMIO_BASE, wdt_res.start);
	pci_read_config_byte(pdev, VIA_WDT_CONF, &conf);
	conf |= VIA_WDT_CONF_ENABLE | VIA_WDT_CONF_MMIO;
	pci_write_config_byte(pdev, VIA_WDT_CONF, conf);

	pci_read_config_dword(pdev, VIA_WDT_MMIO_BASE, &mmio);
	if (mmio) {
		dev_info(&pdev->dev, "VIA Chipset watchdog MMIO: %x\n", mmio);
	} else {
		dev_err(&pdev->dev, "MMIO setting failed. Check BIOS.\n");
		goto err_out_resource;
	}

	if (!request_mem_region(mmio, VIA_WDT_MMIO_LEN, "via_wdt")) {
		dev_err(&pdev->dev, "MMIO region busy\n");
		goto err_out_resource;
	}

	wdt_mem = ioremap(mmio, VIA_WDT_MMIO_LEN);
	if (wdt_mem == NULL) {
		dev_err(&pdev->dev, "cannot remap VIA wdt MMIO registers\n");
		goto err_out_release;
	}

	if (timeout < 1 || timeout > WDT_TIMEOUT_MAX)
		timeout = WDT_TIMEOUT;

	wdt_dev.timeout = timeout;
	wdt_dev.parent = &pdev->dev;
	watchdog_set_nowayout(&wdt_dev, nowayout);
	if (readl(wdt_mem) & VIA_WDT_FIRED)
		wdt_dev.bootstatus |= WDIOF_CARDRESET;

	ret = watchdog_register_device(&wdt_dev);
	if (ret)
		goto err_out_iounmap;

	/* start triggering, in case of watchdog already enabled by BIOS */
	mod_timer(&timer, jiffies + WDT_HEARTBEAT);
	return 0;

err_out_iounmap:
	iounmap(wdt_mem);
err_out_release:
	release_mem_region(mmio, VIA_WDT_MMIO_LEN);
err_out_resource:
	release_resource(&wdt_res);
err_out_disable_device:
	pci_disable_device(pdev);
	return ret;
}

__attribute__((used)) static void wdt_remove(struct pci_dev *pdev)
{
	watchdog_unregister_device(&wdt_dev);
	del_timer_sync(&timer);
	iounmap(wdt_mem);
	release_mem_region(mmio, VIA_WDT_MMIO_LEN);
	release_resource(&wdt_res);
	pci_disable_device(pdev);
}

