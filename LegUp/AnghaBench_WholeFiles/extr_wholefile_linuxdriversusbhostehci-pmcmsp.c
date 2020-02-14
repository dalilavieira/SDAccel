#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  int u32 ;
struct TYPE_2__ {int /*<<< orphan*/  controller; } ;
struct usb_hcd {int has_tt; int rsrc_len; int /*<<< orphan*/  rsrc_start; int /*<<< orphan*/ * regs; TYPE_1__ self; } ;
struct resource {int /*<<< orphan*/  start; } ;
struct platform_device {char* name; int /*<<< orphan*/  dev; } ;
struct mspusb_device {int /*<<< orphan*/ * mab_regs; int /*<<< orphan*/ * usbid_regs; struct platform_device dev; } ;
struct hc_driver {int dummy; } ;
struct ehci_regs {int dummy; } ;
struct ehci_hcd {int big_endian_mmio; int big_endian_desc; int /*<<< orphan*/ * caps; struct ehci_regs* regs; } ;

/* Variables and functions */
 int EBUSY ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  IORESOURCE_IRQ ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQF_SHARED ; 
 int /*<<< orphan*/  MSP_PIN_USB0_HOST_DEV ; 
 int USB_CTRL_FIFO_THRESH ; 
 int USB_CTRL_MODE_STREAM_DISABLE ; 
 int USB_EHCI_REG_BIT_STAT_STS ; 
 int USB_EHCI_REG_USB_FIFO ; 
 int USB_EHCI_REG_USB_MODE ; 
 int USB_EHCI_REG_USB_STATUS ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  device_wakeup_enable (int /*<<< orphan*/ ) ; 
 struct hc_driver ehci_msp_hc_driver ; 
 int ehci_readl (struct ehci_hcd*,int*) ; 
 int ehci_setup (struct usb_hcd*) ; 
 int /*<<< orphan*/  ehci_writel (struct ehci_hcd*,int,int*) ; 
 int /*<<< orphan*/  gpio_direction_output (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  gpio_free (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpio_request (int /*<<< orphan*/ ,char*) ; 
 struct ehci_hcd* hcd_to_ehci (struct usb_hcd*) ; 
 void* ioremap_nocache (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  iounmap (int /*<<< orphan*/ *) ; 
 struct usb_hcd* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  pr_debug (char*,...) ; 
 int /*<<< orphan*/  release_mem_region (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  request_mem_region (int /*<<< orphan*/ ,int,char*) ; 
 void* resource_size (struct resource*) ; 
 struct mspusb_device* to_mspusb_device (struct platform_device*) ; 
 int usb_add_hcd (struct usb_hcd*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct usb_hcd* usb_create_hcd (struct hc_driver const*,int /*<<< orphan*/ *,char*) ; 
 scalar_t__ usb_disabled () ; 
 int /*<<< orphan*/  usb_put_hcd (struct usb_hcd*) ; 
 int /*<<< orphan*/  usb_remove_hcd (struct usb_hcd*) ; 

__attribute__((used)) static void usb_hcd_tdi_set_mode(struct ehci_hcd *ehci)
{
	u8 *base;
	u8 *statreg;
	u8 *fiforeg;
	u32 val;
	struct ehci_regs *reg_base = ehci->regs;

	/* get register base */
	base = (u8 *)reg_base + USB_EHCI_REG_USB_MODE;
	statreg = (u8 *)reg_base + USB_EHCI_REG_USB_STATUS;
	fiforeg = (u8 *)reg_base + USB_EHCI_REG_USB_FIFO;

	/* Disable controller mode stream */
	val = ehci_readl(ehci, (u32 *)base);
	ehci_writel(ehci, (val | USB_CTRL_MODE_STREAM_DISABLE),
			(u32 *)base);

	/* clear STS to select parallel transceiver interface */
	val = ehci_readl(ehci, (u32 *)statreg);
	val = val & ~USB_EHCI_REG_BIT_STAT_STS;
	ehci_writel(ehci, val, (u32 *)statreg);

	/* write to set the proper fifo threshold */
	ehci_writel(ehci, USB_CTRL_FIFO_THRESH, (u32 *)fiforeg);

	/* set TWI GPIO USB_HOST_DEV pin high */
	gpio_direction_output(MSP_PIN_USB0_HOST_DEV, 1);
}

__attribute__((used)) static int ehci_msp_setup(struct usb_hcd *hcd)
{
	struct ehci_hcd		*ehci = hcd_to_ehci(hcd);
	int			retval;

	ehci->big_endian_mmio = 1;
	ehci->big_endian_desc = 1;

	ehci->caps = hcd->regs;
	hcd->has_tt = 1;

	retval = ehci_setup(hcd);
	if (retval)
		return retval;

	usb_hcd_tdi_set_mode(ehci);

	return retval;
}

__attribute__((used)) static int usb_hcd_msp_map_regs(struct mspusb_device *dev)
{
	struct resource *res;
	struct platform_device *pdev = &dev->dev;
	u32 res_len;
	int retval;

	/* MAB register space */
	res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
	if (res == NULL)
		return -ENOMEM;
	res_len = resource_size(res);
	if (!request_mem_region(res->start, res_len, "mab regs"))
		return -EBUSY;

	dev->mab_regs = ioremap_nocache(res->start, res_len);
	if (dev->mab_regs == NULL) {
		retval = -ENOMEM;
		goto err1;
	}

	/* MSP USB register space */
	res = platform_get_resource(pdev, IORESOURCE_MEM, 2);
	if (res == NULL) {
		retval = -ENOMEM;
		goto err2;
	}
	res_len = resource_size(res);
	if (!request_mem_region(res->start, res_len, "usbid regs")) {
		retval = -EBUSY;
		goto err2;
	}
	dev->usbid_regs = ioremap_nocache(res->start, res_len);
	if (dev->usbid_regs == NULL) {
		retval = -ENOMEM;
		goto err3;
	}

	return 0;
err3:
	res = platform_get_resource(pdev, IORESOURCE_MEM, 2);
	res_len = resource_size(res);
	release_mem_region(res->start, res_len);
err2:
	iounmap(dev->mab_regs);
err1:
	res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
	res_len = resource_size(res);
	release_mem_region(res->start, res_len);
	dev_err(&pdev->dev, "Failed to map non-EHCI regs.\n");
	return retval;
}

int usb_hcd_msp_probe(const struct hc_driver *driver,
			  struct platform_device *dev)
{
	int retval;
	struct usb_hcd *hcd;
	struct resource *res;
	struct ehci_hcd		*ehci ;

	hcd = usb_create_hcd(driver, &dev->dev, "pmcmsp");
	if (!hcd)
		return -ENOMEM;

	res = platform_get_resource(dev, IORESOURCE_MEM, 0);
	if (res == NULL) {
		pr_debug("No IOMEM resource info for %s.\n", dev->name);
		retval = -ENOMEM;
		goto err1;
	}
	hcd->rsrc_start = res->start;
	hcd->rsrc_len = resource_size(res);
	if (!request_mem_region(hcd->rsrc_start, hcd->rsrc_len, dev->name)) {
		retval = -EBUSY;
		goto err1;
	}
	hcd->regs = ioremap_nocache(hcd->rsrc_start, hcd->rsrc_len);
	if (!hcd->regs) {
		pr_debug("ioremap failed");
		retval = -ENOMEM;
		goto err2;
	}

	res = platform_get_resource(dev, IORESOURCE_IRQ, 0);
	if (res == NULL) {
		dev_err(&dev->dev, "No IRQ resource info for %s.\n", dev->name);
		retval = -ENOMEM;
		goto err3;
	}

	/* Map non-EHCI register spaces */
	retval = usb_hcd_msp_map_regs(to_mspusb_device(dev));
	if (retval != 0)
		goto err3;

	ehci = hcd_to_ehci(hcd);
	ehci->big_endian_mmio = 1;
	ehci->big_endian_desc = 1;


	retval = usb_add_hcd(hcd, res->start, IRQF_SHARED);
	if (retval == 0) {
		device_wakeup_enable(hcd->self.controller);
		return 0;
	}

	usb_remove_hcd(hcd);
err3:
	iounmap(hcd->regs);
err2:
	release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
err1:
	usb_put_hcd(hcd);

	return retval;
}

void usb_hcd_msp_remove(struct usb_hcd *hcd, struct platform_device *dev)
{
	usb_remove_hcd(hcd);
	iounmap(hcd->regs);
	release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
	usb_put_hcd(hcd);
}

__attribute__((used)) static int ehci_hcd_msp_drv_probe(struct platform_device *pdev)
{
	int ret;

	pr_debug("In ehci_hcd_msp_drv_probe");

	if (usb_disabled())
		return -ENODEV;

	gpio_request(MSP_PIN_USB0_HOST_DEV, "USB0_HOST_DEV_GPIO");

	ret = usb_hcd_msp_probe(&ehci_msp_hc_driver, pdev);

	return ret;
}

__attribute__((used)) static int ehci_hcd_msp_drv_remove(struct platform_device *pdev)
{
	struct usb_hcd *hcd = platform_get_drvdata(pdev);

	usb_hcd_msp_remove(hcd, pdev);

	/* free TWI GPIO USB_HOST_DEV pin */
	gpio_free(MSP_PIN_USB0_HOST_DEV);

	return 0;
}

