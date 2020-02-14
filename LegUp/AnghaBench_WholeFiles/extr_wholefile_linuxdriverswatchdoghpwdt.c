#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct watchdog_device {unsigned int timeout; unsigned int pretimeout; int /*<<< orphan*/  parent; } ;
struct pci_device_id {int /*<<< orphan*/  device; int /*<<< orphan*/  vendor; } ;
struct pci_dev {scalar_t__ subsystem_vendor; int subsystem_device; int /*<<< orphan*/  dev; } ;
struct TYPE_6__ {int /*<<< orphan*/  timeout; int /*<<< orphan*/ * parent; } ;

/* Variables and functions */
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  HPWDT_VERSION ; 
 scalar_t__ PCI_VENDOR_ID_HP ; 
 scalar_t__ PCI_VENDOR_ID_HP_3PAR ; 
 int SECS_TO_TICKS (unsigned int) ; 
 unsigned int TICKS_TO_SECS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*,...) ; 
 TYPE_1__ hpwdt_dev ; 
 void* hpwdt_nmistat ; 
 void* hpwdt_timer_con ; 
 void* hpwdt_timer_reg ; 
 int ilo5 ; 
 int /*<<< orphan*/  ioread16 (void*) ; 
 unsigned long ioread8 (void*) ; 
 int /*<<< orphan*/  iowrite16 (int,void*) ; 
 int /*<<< orphan*/  iowrite8 (unsigned long,void*) ; 
 int /*<<< orphan*/  nowayout ; 
 int /*<<< orphan*/  pci_disable_device (struct pci_dev*) ; 
 scalar_t__ pci_enable_device (struct pci_dev*) ; 
 void* pci_iomap (struct pci_dev*,int,int) ; 
 int /*<<< orphan*/  pci_iounmap (struct pci_dev*,void*) ; 
 void* pci_mem_addr ; 
 int /*<<< orphan*/  pr_debug (char*) ; 
 scalar_t__ pretimeout ; 
 int /*<<< orphan*/  soft_margin ; 
 scalar_t__ watchdog_active (struct watchdog_device*) ; 
 scalar_t__ watchdog_init_timeout (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int watchdog_register_device (TYPE_1__*) ; 
 int /*<<< orphan*/  watchdog_set_nowayout (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  watchdog_unregister_device (TYPE_1__*) ; 

__attribute__((used)) static int hpwdt_start(struct watchdog_device *wdd)
{
	int control = 0x81 | (pretimeout ? 0x4 : 0);
	int reload = SECS_TO_TICKS(wdd->timeout);

	dev_dbg(wdd->parent, "start watchdog 0x%08x:0x%02x\n", reload, control);
	iowrite16(reload, hpwdt_timer_reg);
	iowrite8(control, hpwdt_timer_con);

	return 0;
}

__attribute__((used)) static void hpwdt_stop(void)
{
	unsigned long data;

	pr_debug("stop  watchdog\n");

	data = ioread8(hpwdt_timer_con);
	data &= 0xFE;
	iowrite8(data, hpwdt_timer_con);
}

__attribute__((used)) static int hpwdt_stop_core(struct watchdog_device *wdd)
{
	hpwdt_stop();

	return 0;
}

__attribute__((used)) static int hpwdt_ping(struct watchdog_device *wdd)
{
	int reload = SECS_TO_TICKS(wdd->timeout);

	dev_dbg(wdd->parent, "ping  watchdog 0x%08x\n", reload);
	iowrite16(reload, hpwdt_timer_reg);

	return 0;
}

__attribute__((used)) static unsigned int hpwdt_gettimeleft(struct watchdog_device *wdd)
{
	return TICKS_TO_SECS(ioread16(hpwdt_timer_reg));
}

__attribute__((used)) static int hpwdt_settimeout(struct watchdog_device *wdd, unsigned int val)
{
	dev_dbg(wdd->parent, "set_timeout = %d\n", val);

	wdd->timeout = val;
	if (val <= wdd->pretimeout) {
		dev_dbg(wdd->parent, "pretimeout < timeout. Setting to zero\n");
		wdd->pretimeout = 0;
		pretimeout = 0;
		if (watchdog_active(wdd))
			hpwdt_start(wdd);
	}
	hpwdt_ping(wdd);

	return 0;
}

__attribute__((used)) static int hpwdt_init_nmi_decoding(struct pci_dev *dev)
{
#ifdef CONFIG_HPWDT_NMI_DECODING
	int retval;
	/*
	 * Only one function can register for NMI_UNKNOWN
	 */
	retval = register_nmi_handler(NMI_UNKNOWN, hpwdt_pretimeout, 0, "hpwdt");
	if (retval)
		goto error;
	retval = register_nmi_handler(NMI_SERR, hpwdt_pretimeout, 0, "hpwdt");
	if (retval)
		goto error1;
	retval = register_nmi_handler(NMI_IO_CHECK, hpwdt_pretimeout, 0, "hpwdt");
	if (retval)
		goto error2;

	dev_info(&dev->dev,
		"HPE Watchdog Timer Driver: NMI decoding initialized\n");

	return 0;

error2:
	unregister_nmi_handler(NMI_SERR, "hpwdt");
error1:
	unregister_nmi_handler(NMI_UNKNOWN, "hpwdt");
error:
	dev_warn(&dev->dev,
		"Unable to register a die notifier (err=%d).\n",
		retval);
	return retval;
#endif	/* CONFIG_HPWDT_NMI_DECODING */
	return 0;
}

__attribute__((used)) static void hpwdt_exit_nmi_decoding(void)
{
#ifdef CONFIG_HPWDT_NMI_DECODING
	unregister_nmi_handler(NMI_UNKNOWN, "hpwdt");
	unregister_nmi_handler(NMI_SERR, "hpwdt");
	unregister_nmi_handler(NMI_IO_CHECK, "hpwdt");
#endif
}

__attribute__((used)) static int hpwdt_init_one(struct pci_dev *dev,
					const struct pci_device_id *ent)
{
	int retval;

	/*
	 * First let's find out if we are on an iLO2+ server. We will
	 * not run on a legacy ASM box.
	 * So we only support the G5 ProLiant servers and higher.
	 */
	if (dev->subsystem_vendor != PCI_VENDOR_ID_HP &&
	    dev->subsystem_vendor != PCI_VENDOR_ID_HP_3PAR) {
		dev_warn(&dev->dev,
			"This server does not have an iLO2+ ASIC.\n");
		return -ENODEV;
	}

	/*
	 * Ignore all auxilary iLO devices with the following PCI ID
	 */
	if (dev->subsystem_vendor == PCI_VENDOR_ID_HP &&
	    dev->subsystem_device == 0x1979)
		return -ENODEV;

	if (pci_enable_device(dev)) {
		dev_warn(&dev->dev,
			"Not possible to enable PCI Device: 0x%x:0x%x.\n",
			ent->vendor, ent->device);
		return -ENODEV;
	}

	pci_mem_addr = pci_iomap(dev, 1, 0x80);
	if (!pci_mem_addr) {
		dev_warn(&dev->dev,
			"Unable to detect the iLO2+ server memory.\n");
		retval = -ENOMEM;
		goto error_pci_iomap;
	}
	hpwdt_nmistat	= pci_mem_addr + 0x6e;
	hpwdt_timer_reg = pci_mem_addr + 0x70;
	hpwdt_timer_con = pci_mem_addr + 0x72;

	/* Make sure that timer is disabled until /dev/watchdog is opened */
	hpwdt_stop();

	/* Initialize NMI Decoding functionality */
	retval = hpwdt_init_nmi_decoding(dev);
	if (retval != 0)
		goto error_init_nmi_decoding;

	watchdog_set_nowayout(&hpwdt_dev, nowayout);
	if (watchdog_init_timeout(&hpwdt_dev, soft_margin, NULL))
		dev_warn(&dev->dev, "Invalid soft_margin: %d.\n", soft_margin);

	hpwdt_dev.parent = &dev->dev;
	retval = watchdog_register_device(&hpwdt_dev);
	if (retval < 0) {
		dev_err(&dev->dev, "watchdog register failed: %d.\n", retval);
		goto error_wd_register;
	}

	dev_info(&dev->dev, "HPE Watchdog Timer Driver: %s"
			", timer margin: %d seconds (nowayout=%d).\n",
			HPWDT_VERSION, hpwdt_dev.timeout, nowayout);

	if (dev->subsystem_vendor == PCI_VENDOR_ID_HP_3PAR)
		ilo5 = true;

	return 0;

error_wd_register:
	hpwdt_exit_nmi_decoding();
error_init_nmi_decoding:
	pci_iounmap(dev, pci_mem_addr);
error_pci_iomap:
	pci_disable_device(dev);
	return retval;
}

__attribute__((used)) static void hpwdt_exit(struct pci_dev *dev)
{
	if (!nowayout)
		hpwdt_stop();

	watchdog_unregister_device(&hpwdt_dev);
	hpwdt_exit_nmi_decoding();
	pci_iounmap(dev, pci_mem_addr);
	pci_disable_device(dev);
}

