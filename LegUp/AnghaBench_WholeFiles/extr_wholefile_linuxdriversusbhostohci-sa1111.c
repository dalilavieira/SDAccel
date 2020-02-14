#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  controller; } ;
struct usb_hcd {TYPE_2__* driver; int /*<<< orphan*/  flags; int /*<<< orphan*/  rsrc_len; int /*<<< orphan*/  rsrc_start; TYPE_1__ self; scalar_t__ regs; } ;
struct TYPE_6__ {int /*<<< orphan*/  start; } ;
struct sa1111_dev {scalar_t__ mapbase; int /*<<< orphan*/  dev; TYPE_3__ res; } ;
struct ohci_hcd {int dummy; } ;
struct device {int dummy; } ;
struct TYPE_5__ {int /*<<< orphan*/  (* shutdown ) (struct usb_hcd*) ;} ;

/* Variables and functions */
 int EBUSY ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ENXIO ; 
 int /*<<< orphan*/  HCD_FLAG_HW_ACCESSIBLE ; 
 scalar_t__ USB_RESET ; 
 unsigned int USB_RESET_FORCEHCRESET ; 
 unsigned int USB_RESET_FORCEIFRESET ; 
 unsigned int USB_RESET_PWRCTRLLOW ; 
 unsigned int USB_RESET_PWRSENSELOW ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  device_wakeup_enable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hcd_name ; 
 struct ohci_hcd* hcd_to_ohci (struct usb_hcd*) ; 
 scalar_t__ machine_is_assabet () ; 
 scalar_t__ machine_is_badge4 () ; 
 scalar_t__ machine_is_pfs168 () ; 
 scalar_t__ machine_is_xp860 () ; 
 int /*<<< orphan*/  ohci_err (struct ohci_hcd*,char*) ; 
 int /*<<< orphan*/  ohci_hcd_init (struct ohci_hcd*) ; 
 int ohci_init (struct ohci_hcd*) ; 
 int ohci_run (struct ohci_hcd*) ; 
 int /*<<< orphan*/  ohci_sa1111_hc_driver ; 
 int /*<<< orphan*/  ohci_stop (struct usb_hcd*) ; 
 unsigned int readl_relaxed (scalar_t__) ; 
 int /*<<< orphan*/  release_mem_region (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  request_mem_region (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  resource_size (TYPE_3__*) ; 
 int /*<<< orphan*/  sa1111_disable_device (struct sa1111_dev*) ; 
 int sa1111_enable_device (struct sa1111_dev*) ; 
 struct usb_hcd* sa1111_get_drvdata (struct sa1111_dev*) ; 
 int sa1111_get_irq (struct sa1111_dev*,int) ; 
 int /*<<< orphan*/  stub1 (struct usb_hcd*) ; 
 scalar_t__ test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct sa1111_dev* to_sa1111_device (struct device*) ; 
 int /*<<< orphan*/  udelay (int) ; 
 int usb_add_hcd (struct usb_hcd*,int,int /*<<< orphan*/ ) ; 
 struct usb_hcd* usb_create_hcd (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char*) ; 
 scalar_t__ usb_disabled () ; 
 int /*<<< orphan*/  usb_put_hcd (struct usb_hcd*) ; 
 int /*<<< orphan*/  usb_remove_hcd (struct usb_hcd*) ; 
 int /*<<< orphan*/  writel_relaxed (unsigned int,scalar_t__) ; 

__attribute__((used)) static int ohci_sa1111_reset(struct usb_hcd *hcd)
{
	struct ohci_hcd *ohci = hcd_to_ohci(hcd);

	ohci_hcd_init(ohci);
	return ohci_init(ohci);
}

__attribute__((used)) static int ohci_sa1111_start(struct usb_hcd *hcd)
{
	struct ohci_hcd	*ohci = hcd_to_ohci(hcd);
	int ret;

	ret = ohci_run(ohci);
	if (ret < 0) {
		ohci_err(ohci, "can't start\n");
		ohci_stop(hcd);
	}
	return ret;
}

__attribute__((used)) static int sa1111_start_hc(struct sa1111_dev *dev)
{
	unsigned int usb_rst = 0;
	int ret;

	dev_dbg(&dev->dev, "starting SA-1111 OHCI USB Controller\n");

	if (machine_is_xp860() ||
	    machine_is_assabet() ||
	    machine_is_pfs168() ||
	    machine_is_badge4())
		usb_rst = USB_RESET_PWRSENSELOW | USB_RESET_PWRCTRLLOW;

	/*
	 * Configure the power sense and control lines.  Place the USB
	 * host controller in reset.
	 */
	writel_relaxed(usb_rst | USB_RESET_FORCEIFRESET | USB_RESET_FORCEHCRESET,
		      dev->mapbase + USB_RESET);

	/*
	 * Now, carefully enable the USB clock, and take
	 * the USB host controller out of reset.
	 */
	ret = sa1111_enable_device(dev);
	if (ret == 0) {
		udelay(11);
		writel_relaxed(usb_rst, dev->mapbase + USB_RESET);
	}

	return ret;
}

__attribute__((used)) static void sa1111_stop_hc(struct sa1111_dev *dev)
{
	unsigned int usb_rst;

	dev_dbg(&dev->dev, "stopping SA-1111 OHCI USB Controller\n");

	/*
	 * Put the USB host controller into reset.
	 */
	usb_rst = readl_relaxed(dev->mapbase + USB_RESET);
	writel_relaxed(usb_rst | USB_RESET_FORCEIFRESET | USB_RESET_FORCEHCRESET,
		      dev->mapbase + USB_RESET);

	/*
	 * Stop the USB clock.
	 */
	sa1111_disable_device(dev);
}

__attribute__((used)) static int ohci_hcd_sa1111_probe(struct sa1111_dev *dev)
{
	struct usb_hcd *hcd;
	int ret, irq;

	if (usb_disabled())
		return -ENODEV;

	/*
	 * We don't call dma_set_mask_and_coherent() here because the
	 * DMA mask has already been appropraitely setup by the core
	 * SA-1111 bus code (which includes bug workarounds.)
	 */

	hcd = usb_create_hcd(&ohci_sa1111_hc_driver, &dev->dev, "sa1111");
	if (!hcd)
		return -ENOMEM;

	hcd->rsrc_start = dev->res.start;
	hcd->rsrc_len = resource_size(&dev->res);

	irq = sa1111_get_irq(dev, 1);
	if (irq <= 0) {
		ret = irq ? : -ENXIO;
		goto err1;
	}

	if (!request_mem_region(hcd->rsrc_start, hcd->rsrc_len, hcd_name)) {
		dev_dbg(&dev->dev, "request_mem_region failed\n");
		ret = -EBUSY;
		goto err1;
	}

	hcd->regs = dev->mapbase;

	ret = sa1111_start_hc(dev);
	if (ret)
		goto err2;

	ret = usb_add_hcd(hcd, irq, 0);
	if (ret == 0) {
		device_wakeup_enable(hcd->self.controller);
		return ret;
	}

	sa1111_stop_hc(dev);
 err2:
	release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
 err1:
	usb_put_hcd(hcd);
	return ret;
}

__attribute__((used)) static int ohci_hcd_sa1111_remove(struct sa1111_dev *dev)
{
	struct usb_hcd *hcd = sa1111_get_drvdata(dev);

	usb_remove_hcd(hcd);
	sa1111_stop_hc(dev);
	release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
	usb_put_hcd(hcd);

	return 0;
}

__attribute__((used)) static void ohci_hcd_sa1111_shutdown(struct device *_dev)
{
	struct sa1111_dev *dev = to_sa1111_device(_dev);
	struct usb_hcd *hcd = sa1111_get_drvdata(dev);

	if (test_bit(HCD_FLAG_HW_ACCESSIBLE, &hcd->flags)) {
		hcd->driver->shutdown(hcd);
		sa1111_stop_hc(dev);
	}
}

