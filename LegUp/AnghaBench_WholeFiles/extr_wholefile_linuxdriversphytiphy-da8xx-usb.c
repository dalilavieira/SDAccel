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
typedef  int /*<<< orphan*/  u32 ;
struct device {struct device_node* of_node; struct da8xx_usb_phy_platform_data* platform_data; } ;
struct platform_device {struct device dev; } ;
struct phy {int dummy; } ;
struct of_phandle_args {int* args; } ;
struct device_node {int dummy; } ;
struct da8xx_usb_phy_platform_data {struct phy* cfgchip; } ;
struct da8xx_usb_phy {struct phy* usb11_phy; struct phy* usb20_phy; struct phy* regmap; struct phy* phy_provider; struct phy* usb20_clk; struct phy* usb11_clk; } ;
typedef  enum phy_mode { ____Placeholder_phy_mode } phy_mode ;

/* Variables and functions */
 int /*<<< orphan*/  CFGCHIP (int) ; 
 int /*<<< orphan*/  CFGCHIP2_OTGMODE_FORCE_DEVICE ; 
 int /*<<< orphan*/  CFGCHIP2_OTGMODE_FORCE_HOST ; 
 int /*<<< orphan*/  CFGCHIP2_OTGMODE_MASK ; 
 int /*<<< orphan*/  CFGCHIP2_OTGMODE_NO_OVERRIDE ; 
 int /*<<< orphan*/  CFGCHIP2_OTGPWRDN ; 
 int /*<<< orphan*/  CFGCHIP2_USB1SUSPENDM ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 struct phy* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct phy*) ; 
 int /*<<< orphan*/  PHY_INIT_BITS ; 
#define  PHY_MODE_USB_DEVICE 130 
#define  PHY_MODE_USB_HOST 129 
#define  PHY_MODE_USB_OTG 128 
 int PTR_ERR (struct phy*) ; 
 int /*<<< orphan*/  clk_disable_unprepare (struct phy*) ; 
 int clk_prepare_enable (struct phy*) ; 
 int /*<<< orphan*/  da8xx_usb11_phy_ops ; 
 int /*<<< orphan*/  da8xx_usb20_phy_ops ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 struct da8xx_usb_phy* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*) ; 
 void* devm_clk_get (struct device*,char*) ; 
 struct da8xx_usb_phy* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 struct phy* devm_of_phy_provider_register (struct device*,struct phy* (*) (struct device*,struct of_phandle_args*)) ; 
 void* devm_phy_create (struct device*,struct device_node*,int /*<<< orphan*/ *) ; 
 int phy_create_lookup (struct phy*,char*,char*) ; 
 struct da8xx_usb_phy* phy_get_drvdata (struct phy*) ; 
 int /*<<< orphan*/  phy_remove_lookup (struct phy*,char*,char*) ; 
 int /*<<< orphan*/  phy_set_drvdata (struct phy*,struct da8xx_usb_phy*) ; 
 struct da8xx_usb_phy* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct da8xx_usb_phy*) ; 
 int /*<<< orphan*/  regmap_write_bits (struct phy*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct phy* syscon_regmap_lookup_by_compatible (char*) ; 

__attribute__((used)) static int da8xx_usb11_phy_power_on(struct phy *phy)
{
	struct da8xx_usb_phy *d_phy = phy_get_drvdata(phy);
	int ret;

	ret = clk_prepare_enable(d_phy->usb11_clk);
	if (ret)
		return ret;

	regmap_write_bits(d_phy->regmap, CFGCHIP(2), CFGCHIP2_USB1SUSPENDM,
			  CFGCHIP2_USB1SUSPENDM);

	return 0;
}

__attribute__((used)) static int da8xx_usb11_phy_power_off(struct phy *phy)
{
	struct da8xx_usb_phy *d_phy = phy_get_drvdata(phy);

	regmap_write_bits(d_phy->regmap, CFGCHIP(2), CFGCHIP2_USB1SUSPENDM, 0);

	clk_disable_unprepare(d_phy->usb11_clk);

	return 0;
}

__attribute__((used)) static int da8xx_usb20_phy_power_on(struct phy *phy)
{
	struct da8xx_usb_phy *d_phy = phy_get_drvdata(phy);
	int ret;

	ret = clk_prepare_enable(d_phy->usb20_clk);
	if (ret)
		return ret;

	regmap_write_bits(d_phy->regmap, CFGCHIP(2), CFGCHIP2_OTGPWRDN, 0);

	return 0;
}

__attribute__((used)) static int da8xx_usb20_phy_power_off(struct phy *phy)
{
	struct da8xx_usb_phy *d_phy = phy_get_drvdata(phy);

	regmap_write_bits(d_phy->regmap, CFGCHIP(2), CFGCHIP2_OTGPWRDN,
			  CFGCHIP2_OTGPWRDN);

	clk_disable_unprepare(d_phy->usb20_clk);

	return 0;
}

__attribute__((used)) static int da8xx_usb20_phy_set_mode(struct phy *phy, enum phy_mode mode)
{
	struct da8xx_usb_phy *d_phy = phy_get_drvdata(phy);
	u32 val;

	switch (mode) {
	case PHY_MODE_USB_HOST:		/* Force VBUS valid, ID = 0 */
		val = CFGCHIP2_OTGMODE_FORCE_HOST;
		break;
	case PHY_MODE_USB_DEVICE:	/* Force VBUS valid, ID = 1 */
		val = CFGCHIP2_OTGMODE_FORCE_DEVICE;
		break;
	case PHY_MODE_USB_OTG:	/* Don't override the VBUS/ID comparators */
		val = CFGCHIP2_OTGMODE_NO_OVERRIDE;
		break;
	default:
		return -EINVAL;
	}

	regmap_write_bits(d_phy->regmap, CFGCHIP(2), CFGCHIP2_OTGMODE_MASK,
			  val);

	return 0;
}

__attribute__((used)) static struct phy *da8xx_usb_phy_of_xlate(struct device *dev,
					 struct of_phandle_args *args)
{
	struct da8xx_usb_phy *d_phy = dev_get_drvdata(dev);

	if (!d_phy)
		return ERR_PTR(-ENODEV);

	switch (args->args[0]) {
	case 0:
		return d_phy->usb20_phy;
	case 1:
		return d_phy->usb11_phy;
	default:
		return ERR_PTR(-EINVAL);
	}
}

__attribute__((used)) static int da8xx_usb_phy_probe(struct platform_device *pdev)
{
	struct device		*dev = &pdev->dev;
	struct da8xx_usb_phy_platform_data *pdata = dev->platform_data;
	struct device_node	*node = dev->of_node;
	struct da8xx_usb_phy	*d_phy;

	d_phy = devm_kzalloc(dev, sizeof(*d_phy), GFP_KERNEL);
	if (!d_phy)
		return -ENOMEM;

	if (pdata)
		d_phy->regmap = pdata->cfgchip;
	else
		d_phy->regmap = syscon_regmap_lookup_by_compatible(
							"ti,da830-cfgchip");
	if (IS_ERR(d_phy->regmap)) {
		dev_err(dev, "Failed to get syscon\n");
		return PTR_ERR(d_phy->regmap);
	}

	d_phy->usb11_clk = devm_clk_get(dev, "usb1_clk48");
	if (IS_ERR(d_phy->usb11_clk)) {
		dev_err(dev, "Failed to get usb1_clk48\n");
		return PTR_ERR(d_phy->usb11_clk);
	}

	d_phy->usb20_clk = devm_clk_get(dev, "usb0_clk48");
	if (IS_ERR(d_phy->usb20_clk)) {
		dev_err(dev, "Failed to get usb0_clk48\n");
		return PTR_ERR(d_phy->usb20_clk);
	}

	d_phy->usb11_phy = devm_phy_create(dev, node, &da8xx_usb11_phy_ops);
	if (IS_ERR(d_phy->usb11_phy)) {
		dev_err(dev, "Failed to create usb11 phy\n");
		return PTR_ERR(d_phy->usb11_phy);
	}

	d_phy->usb20_phy = devm_phy_create(dev, node, &da8xx_usb20_phy_ops);
	if (IS_ERR(d_phy->usb20_phy)) {
		dev_err(dev, "Failed to create usb20 phy\n");
		return PTR_ERR(d_phy->usb20_phy);
	}

	platform_set_drvdata(pdev, d_phy);
	phy_set_drvdata(d_phy->usb11_phy, d_phy);
	phy_set_drvdata(d_phy->usb20_phy, d_phy);

	if (node) {
		d_phy->phy_provider = devm_of_phy_provider_register(dev,
							da8xx_usb_phy_of_xlate);
		if (IS_ERR(d_phy->phy_provider)) {
			dev_err(dev, "Failed to create phy provider\n");
			return PTR_ERR(d_phy->phy_provider);
		}
	} else {
		int ret;

		ret = phy_create_lookup(d_phy->usb11_phy, "usb-phy",
					"ohci-da8xx");
		if (ret)
			dev_warn(dev, "Failed to create usb11 phy lookup\n");
		ret = phy_create_lookup(d_phy->usb20_phy, "usb-phy",
					"musb-da8xx");
		if (ret)
			dev_warn(dev, "Failed to create usb20 phy lookup\n");
	}

	regmap_write_bits(d_phy->regmap, CFGCHIP(2),
			  PHY_INIT_BITS, PHY_INIT_BITS);

	return 0;
}

__attribute__((used)) static int da8xx_usb_phy_remove(struct platform_device *pdev)
{
	struct da8xx_usb_phy *d_phy = platform_get_drvdata(pdev);

	if (!pdev->dev.of_node) {
		phy_remove_lookup(d_phy->usb20_phy, "usb-phy", "musb-da8xx");
		phy_remove_lookup(d_phy->usb11_phy, "usb-phy", "ohci-da8xx");
	}

	return 0;
}

