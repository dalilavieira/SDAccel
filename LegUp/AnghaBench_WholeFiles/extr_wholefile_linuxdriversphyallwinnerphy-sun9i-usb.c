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
typedef  int u32 ;
struct sun9i_usb_phy {scalar_t__ type; void* phy; void* pmu; void* reset; void* clk; void* hsic_clk; } ;
struct resource {int dummy; } ;
struct device {struct device_node* of_node; } ;
struct platform_device {struct device dev; } ;
struct phy_provider {int dummy; } ;
struct phy {int dummy; } ;
struct device_node {int dummy; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (void*) ; 
 int PTR_ERR (void*) ; 
 int PTR_ERR_OR_ZERO (struct phy_provider*) ; 
 int SUNXI_AHB_INCR16_BURST_EN ; 
 int SUNXI_AHB_INCR4_BURST_EN ; 
 int SUNXI_AHB_INCR8_BURST_EN ; 
 int SUNXI_AHB_INCRX_ALIGN_EN ; 
 int SUNXI_EHCI_HS_FORCE ; 
 int SUNXI_HSIC ; 
 int SUNXI_HSIC_CONNECT_DET ; 
 int SUNXI_HSIC_CONNECT_INT ; 
 int SUNXI_ULPI_BYPASS_EN ; 
 scalar_t__ USBPHY_INTERFACE_MODE_HSIC ; 
 int /*<<< orphan*/  clk_disable_unprepare (void*) ; 
 int clk_prepare_enable (void*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 void* devm_clk_get (struct device*,char*) ; 
 void* devm_ioremap_resource (struct device*,struct resource*) ; 
 struct sun9i_usb_phy* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 struct phy_provider* devm_of_phy_provider_register (struct device*,int /*<<< orphan*/ ) ; 
 void* devm_phy_create (struct device*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 void* devm_reset_control_get (struct device*,char*) ; 
 int /*<<< orphan*/  of_phy_simple_xlate ; 
 scalar_t__ of_usb_get_phy_mode (struct device_node*) ; 
 struct sun9i_usb_phy* phy_get_drvdata (struct phy*) ; 
 int /*<<< orphan*/  phy_set_drvdata (void*,struct sun9i_usb_phy*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int readl (void*) ; 
 int /*<<< orphan*/  reset_control_assert (void*) ; 
 int reset_control_deassert (void*) ; 
 int /*<<< orphan*/  sun9i_usb_phy_ops ; 
 int /*<<< orphan*/  writel (int,void*) ; 

__attribute__((used)) static void sun9i_usb_phy_passby(struct sun9i_usb_phy *phy, int enable)
{
	u32 bits, reg_value;

	bits = SUNXI_AHB_INCR16_BURST_EN | SUNXI_AHB_INCR8_BURST_EN |
		SUNXI_AHB_INCR4_BURST_EN | SUNXI_AHB_INCRX_ALIGN_EN |
		SUNXI_ULPI_BYPASS_EN;

	if (phy->type == USBPHY_INTERFACE_MODE_HSIC)
		bits |= SUNXI_HSIC | SUNXI_EHCI_HS_FORCE |
			SUNXI_HSIC_CONNECT_DET | SUNXI_HSIC_CONNECT_INT;

	reg_value = readl(phy->pmu);

	if (enable)
		reg_value |= bits;
	else
		reg_value &= ~bits;

	writel(reg_value, phy->pmu);
}

__attribute__((used)) static int sun9i_usb_phy_init(struct phy *_phy)
{
	struct sun9i_usb_phy *phy = phy_get_drvdata(_phy);
	int ret;

	ret = clk_prepare_enable(phy->clk);
	if (ret)
		goto err_clk;

	ret = clk_prepare_enable(phy->hsic_clk);
	if (ret)
		goto err_hsic_clk;

	ret = reset_control_deassert(phy->reset);
	if (ret)
		goto err_reset;

	sun9i_usb_phy_passby(phy, 1);
	return 0;

err_reset:
	clk_disable_unprepare(phy->hsic_clk);

err_hsic_clk:
	clk_disable_unprepare(phy->clk);

err_clk:
	return ret;
}

__attribute__((used)) static int sun9i_usb_phy_exit(struct phy *_phy)
{
	struct sun9i_usb_phy *phy = phy_get_drvdata(_phy);

	sun9i_usb_phy_passby(phy, 0);
	reset_control_assert(phy->reset);
	clk_disable_unprepare(phy->hsic_clk);
	clk_disable_unprepare(phy->clk);

	return 0;
}

__attribute__((used)) static int sun9i_usb_phy_probe(struct platform_device *pdev)
{
	struct sun9i_usb_phy *phy;
	struct device *dev = &pdev->dev;
	struct device_node *np = dev->of_node;
	struct phy_provider *phy_provider;
	struct resource *res;

	phy = devm_kzalloc(dev, sizeof(*phy), GFP_KERNEL);
	if (!phy)
		return -ENOMEM;

	phy->type = of_usb_get_phy_mode(np);
	if (phy->type == USBPHY_INTERFACE_MODE_HSIC) {
		phy->clk = devm_clk_get(dev, "hsic_480M");
		if (IS_ERR(phy->clk)) {
			dev_err(dev, "failed to get hsic_480M clock\n");
			return PTR_ERR(phy->clk);
		}

		phy->hsic_clk = devm_clk_get(dev, "hsic_12M");
		if (IS_ERR(phy->hsic_clk)) {
			dev_err(dev, "failed to get hsic_12M clock\n");
			return PTR_ERR(phy->hsic_clk);
		}

		phy->reset = devm_reset_control_get(dev, "hsic");
		if (IS_ERR(phy->reset)) {
			dev_err(dev, "failed to get reset control\n");
			return PTR_ERR(phy->reset);
		}
	} else {
		phy->clk = devm_clk_get(dev, "phy");
		if (IS_ERR(phy->clk)) {
			dev_err(dev, "failed to get phy clock\n");
			return PTR_ERR(phy->clk);
		}

		phy->reset = devm_reset_control_get(dev, "phy");
		if (IS_ERR(phy->reset)) {
			dev_err(dev, "failed to get reset control\n");
			return PTR_ERR(phy->reset);
		}
	}

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	phy->pmu = devm_ioremap_resource(dev, res);
	if (IS_ERR(phy->pmu))
		return PTR_ERR(phy->pmu);

	phy->phy = devm_phy_create(dev, NULL, &sun9i_usb_phy_ops);
	if (IS_ERR(phy->phy)) {
		dev_err(dev, "failed to create PHY\n");
		return PTR_ERR(phy->phy);
	}

	phy_set_drvdata(phy->phy, phy);
	phy_provider = devm_of_phy_provider_register(dev, of_phy_simple_xlate);

	return PTR_ERR_OR_ZERO(phy_provider);
}

