#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u32 ;
struct TYPE_10__ {int /*<<< orphan*/  controller; } ;
struct usb_hcd {TYPE_2__ self; int /*<<< orphan*/  regs; int /*<<< orphan*/  rsrc_len; int /*<<< orphan*/  rsrc_start; } ;
struct uhci_hcd {int is_aspeed; int /*<<< orphan*/  clk; scalar_t__ rh_numports; int /*<<< orphan*/  regs; int /*<<< orphan*/ * global_suspend_mode_is_broken; int /*<<< orphan*/ * resume_detect_interrupts_are_broken; int /*<<< orphan*/ * configure_hc; int /*<<< orphan*/  check_and_reset_hc; int /*<<< orphan*/  reset_hc; } ;
struct resource {int /*<<< orphan*/  start; } ;
struct TYPE_11__ {struct device_node* of_node; } ;
struct platform_device {TYPE_1__* resource; TYPE_3__ dev; int /*<<< orphan*/  name; } ;
struct device_node {int dummy; } ;
struct TYPE_9__ {int /*<<< orphan*/  start; } ;

/* Variables and functions */
 int /*<<< orphan*/  DMA_BIT_MASK (int) ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQF_SHARED ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  check_and_reset_hc (struct uhci_hcd*) ; 
 int /*<<< orphan*/  clk_disable_unprepare (int /*<<< orphan*/ ) ; 
 int clk_prepare_enable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (TYPE_3__*,char*,int) ; 
 int /*<<< orphan*/  dev_info (TYPE_3__*,char*,...) ; 
 int /*<<< orphan*/  device_wakeup_enable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_clk_get (TYPE_3__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  devm_ioremap_resource (TYPE_3__*,struct resource*) ; 
 int dma_coerce_mask_and_coherent (TYPE_3__*,int /*<<< orphan*/ ) ; 
 struct uhci_hcd* hcd_to_uhci (struct usb_hcd*) ; 
 scalar_t__ of_device_is_compatible (struct device_node*,char*) ; 
 scalar_t__ of_property_read_u32 (struct device_node*,char*,scalar_t__*) ; 
 struct usb_hcd* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  resource_size (struct resource*) ; 
 scalar_t__ uhci_count_ports (struct usb_hcd*) ; 
 int /*<<< orphan*/  uhci_generic_check_and_reset_hc ; 
 int /*<<< orphan*/  uhci_generic_reset_hc ; 
 int /*<<< orphan*/  uhci_hc_died (struct uhci_hcd*) ; 
 int /*<<< orphan*/  uhci_platform_hc_driver ; 
 int usb_add_hcd (struct usb_hcd*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct usb_hcd* usb_create_hcd (int /*<<< orphan*/ *,TYPE_3__*,int /*<<< orphan*/ ) ; 
 scalar_t__ usb_disabled () ; 
 int /*<<< orphan*/  usb_put_hcd (struct usb_hcd*) ; 
 int /*<<< orphan*/  usb_remove_hcd (struct usb_hcd*) ; 

__attribute__((used)) static int uhci_platform_init(struct usb_hcd *hcd)
{
	struct uhci_hcd *uhci = hcd_to_uhci(hcd);

	/* Probe number of ports if not already provided by DT */
	if (!uhci->rh_numports)
		uhci->rh_numports = uhci_count_ports(hcd);

	/* Set up pointers to to generic functions */
	uhci->reset_hc = uhci_generic_reset_hc;
	uhci->check_and_reset_hc = uhci_generic_check_and_reset_hc;

	/* No special actions need to be taken for the functions below */
	uhci->configure_hc = NULL;
	uhci->resume_detect_interrupts_are_broken = NULL;
	uhci->global_suspend_mode_is_broken = NULL;

	/* Reset if the controller isn't already safely quiescent. */
	check_and_reset_hc(uhci);
	return 0;
}

__attribute__((used)) static int uhci_hcd_platform_probe(struct platform_device *pdev)
{
	struct device_node *np = pdev->dev.of_node;
	struct usb_hcd *hcd;
	struct uhci_hcd	*uhci;
	struct resource *res;
	int ret;

	if (usb_disabled())
		return -ENODEV;

	/*
	 * Right now device-tree probed devices don't get dma_mask set.
	 * Since shared usb code relies on it, set it here for now.
	 * Once we have dma capability bindings this can go away.
	 */
	ret = dma_coerce_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(32));
	if (ret)
		return ret;

	hcd = usb_create_hcd(&uhci_platform_hc_driver, &pdev->dev,
			pdev->name);
	if (!hcd)
		return -ENOMEM;

	uhci = hcd_to_uhci(hcd);

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	hcd->regs = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(hcd->regs)) {
		ret = PTR_ERR(hcd->regs);
		goto err_rmr;
	}
	hcd->rsrc_start = res->start;
	hcd->rsrc_len = resource_size(res);

	uhci->regs = hcd->regs;

	/* Grab some things from the device-tree */
	if (np) {
		u32 num_ports;

		if (of_property_read_u32(np, "#ports", &num_ports) == 0) {
			uhci->rh_numports = num_ports;
			dev_info(&pdev->dev,
				"Detected %d ports from device-tree\n",
				num_ports);
		}
		if (of_device_is_compatible(np, "aspeed,ast2400-uhci") ||
		    of_device_is_compatible(np, "aspeed,ast2500-uhci")) {
			uhci->is_aspeed = 1;
			dev_info(&pdev->dev,
				 "Enabled Aspeed implementation workarounds\n");
		}
	}

	/* Get and enable clock if any specified */
	uhci->clk = devm_clk_get(&pdev->dev, NULL);
	if (IS_ERR(uhci->clk)) {
		ret = PTR_ERR(uhci->clk);
		goto err_rmr;
	}
	ret = clk_prepare_enable(uhci->clk);
	if (ret) {
		dev_err(&pdev->dev, "Error couldn't enable clock (%d)\n", ret);
		goto err_rmr;
	}

	ret = usb_add_hcd(hcd, pdev->resource[1].start, IRQF_SHARED);
	if (ret)
		goto err_clk;

	device_wakeup_enable(hcd->self.controller);
	return 0;

err_clk:
	clk_disable_unprepare(uhci->clk);
err_rmr:
	usb_put_hcd(hcd);

	return ret;
}

__attribute__((used)) static int uhci_hcd_platform_remove(struct platform_device *pdev)
{
	struct usb_hcd *hcd = platform_get_drvdata(pdev);
	struct uhci_hcd *uhci = hcd_to_uhci(hcd);

	clk_disable_unprepare(uhci->clk);
	usb_remove_hcd(hcd);
	usb_put_hcd(hcd);

	return 0;
}

__attribute__((used)) static void uhci_hcd_platform_shutdown(struct platform_device *op)
{
	struct usb_hcd *hcd = platform_get_drvdata(op);

	uhci_hc_died(hcd_to_uhci(hcd));
}

