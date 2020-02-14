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
struct TYPE_6__ {int /*<<< orphan*/  of_node; } ;
struct platform_device {TYPE_1__ dev; } ;
struct pistachio_usb_phy {unsigned int refclk; TYPE_1__* dev; struct phy_provider* phy_clk; struct phy_provider* cr_top; } ;
struct phy_provider {int dummy; } ;
typedef  struct phy_provider phy ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (unsigned long*) ; 
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 int ETIMEDOUT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct phy_provider*) ; 
 int PTR_ERR (struct phy_provider*) ; 
 unsigned int REFCLK_XO_CRYSTAL ; 
 int /*<<< orphan*/  USB_PHY_CONTROL1 ; 
 unsigned int USB_PHY_CONTROL1_FSEL_MASK ; 
 unsigned int USB_PHY_CONTROL1_FSEL_SHIFT ; 
 int /*<<< orphan*/  USB_PHY_STATUS ; 
 unsigned int USB_PHY_STATUS_RX_PHY_CLK ; 
 unsigned int USB_PHY_STATUS_RX_UTMI_CLK ; 
 unsigned int USB_PHY_STATUS_VBUS_FAULT ; 
 int /*<<< orphan*/  USB_PHY_STRAP_CONTROL ; 
 unsigned int USB_PHY_STRAP_CONTROL_REFCLK_MASK ; 
 unsigned int USB_PHY_STRAP_CONTROL_REFCLK_SHIFT ; 
 int /*<<< orphan*/  clk_disable_unprepare (struct phy_provider*) ; 
 unsigned long clk_get_rate (struct phy_provider*) ; 
 int clk_prepare_enable (struct phy_provider*) ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*,...) ; 
 struct phy_provider* devm_clk_get (TYPE_1__*,char*) ; 
 struct pistachio_usb_phy* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 struct phy_provider* devm_of_phy_provider_register (TYPE_1__*,int /*<<< orphan*/ ) ; 
 struct phy_provider* devm_phy_create (TYPE_1__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 unsigned long* fsel_rate_map ; 
 unsigned long jiffies ; 
 unsigned long msecs_to_jiffies (int) ; 
 int /*<<< orphan*/  of_phy_simple_xlate ; 
 int of_property_read_u32 (int /*<<< orphan*/ ,char*,unsigned int*) ; 
 struct pistachio_usb_phy* phy_get_drvdata (struct phy_provider*) ; 
 int /*<<< orphan*/  phy_set_drvdata (struct phy_provider*,struct pistachio_usb_phy*) ; 
 int /*<<< orphan*/  pistachio_usb_phy_ops ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct pistachio_usb_phy*) ; 
 int /*<<< orphan*/  regmap_read (struct phy_provider*,int /*<<< orphan*/ ,unsigned int*) ; 
 int /*<<< orphan*/  regmap_update_bits (struct phy_provider*,int /*<<< orphan*/ ,unsigned int,unsigned int) ; 
 struct phy_provider* syscon_regmap_lookup_by_phandle (int /*<<< orphan*/ ,char*) ; 
 scalar_t__ time_before (unsigned long,unsigned long) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static int pistachio_usb_phy_power_on(struct phy *phy)
{
	struct pistachio_usb_phy *p_phy = phy_get_drvdata(phy);
	unsigned long timeout, rate;
	unsigned int i;
	int ret;

	ret = clk_prepare_enable(p_phy->phy_clk);
	if (ret < 0) {
		dev_err(p_phy->dev, "Failed to enable PHY clock: %d\n", ret);
		return ret;
	}

	regmap_update_bits(p_phy->cr_top, USB_PHY_STRAP_CONTROL,
			   USB_PHY_STRAP_CONTROL_REFCLK_MASK <<
			   USB_PHY_STRAP_CONTROL_REFCLK_SHIFT,
			   p_phy->refclk << USB_PHY_STRAP_CONTROL_REFCLK_SHIFT);

	rate = clk_get_rate(p_phy->phy_clk);
	if (p_phy->refclk == REFCLK_XO_CRYSTAL && rate != 12000000) {
		dev_err(p_phy->dev, "Unsupported rate for XO crystal: %ld\n",
			rate);
		ret = -EINVAL;
		goto disable_clk;
	}

	for (i = 0; i < ARRAY_SIZE(fsel_rate_map); i++) {
		if (rate == fsel_rate_map[i])
			break;
	}
	if (i == ARRAY_SIZE(fsel_rate_map)) {
		dev_err(p_phy->dev, "Unsupported clock rate: %lu\n", rate);
		ret = -EINVAL;
		goto disable_clk;
	}

	regmap_update_bits(p_phy->cr_top, USB_PHY_CONTROL1,
			   USB_PHY_CONTROL1_FSEL_MASK <<
			   USB_PHY_CONTROL1_FSEL_SHIFT,
			   i << USB_PHY_CONTROL1_FSEL_SHIFT);

	timeout = jiffies + msecs_to_jiffies(200);
	while (time_before(jiffies, timeout)) {
		unsigned int val;

		regmap_read(p_phy->cr_top, USB_PHY_STATUS, &val);
		if (val & USB_PHY_STATUS_VBUS_FAULT) {
			dev_err(p_phy->dev, "VBUS fault detected\n");
			ret = -EIO;
			goto disable_clk;
		}
		if ((val & USB_PHY_STATUS_RX_PHY_CLK) &&
		    (val & USB_PHY_STATUS_RX_UTMI_CLK))
			return 0;
		usleep_range(1000, 1500);
	}

	dev_err(p_phy->dev, "Timed out waiting for PHY to power on\n");
	ret = -ETIMEDOUT;

disable_clk:
	clk_disable_unprepare(p_phy->phy_clk);
	return ret;
}

__attribute__((used)) static int pistachio_usb_phy_power_off(struct phy *phy)
{
	struct pistachio_usb_phy *p_phy = phy_get_drvdata(phy);

	clk_disable_unprepare(p_phy->phy_clk);

	return 0;
}

__attribute__((used)) static int pistachio_usb_phy_probe(struct platform_device *pdev)
{
	struct pistachio_usb_phy *p_phy;
	struct phy_provider *provider;
	struct phy *phy;
	int ret;

	p_phy = devm_kzalloc(&pdev->dev, sizeof(*p_phy), GFP_KERNEL);
	if (!p_phy)
		return -ENOMEM;
	p_phy->dev = &pdev->dev;
	platform_set_drvdata(pdev, p_phy);

	p_phy->cr_top = syscon_regmap_lookup_by_phandle(p_phy->dev->of_node,
							"img,cr-top");
	if (IS_ERR(p_phy->cr_top)) {
		dev_err(p_phy->dev, "Failed to get CR_TOP registers: %ld\n",
			PTR_ERR(p_phy->cr_top));
		return PTR_ERR(p_phy->cr_top);
	}

	p_phy->phy_clk = devm_clk_get(p_phy->dev, "usb_phy");
	if (IS_ERR(p_phy->phy_clk)) {
		dev_err(p_phy->dev, "Failed to get usb_phy clock: %ld\n",
			PTR_ERR(p_phy->phy_clk));
		return PTR_ERR(p_phy->phy_clk);
	}

	ret = of_property_read_u32(p_phy->dev->of_node, "img,refclk",
				   &p_phy->refclk);
	if (ret < 0) {
		dev_err(p_phy->dev, "No reference clock selector specified\n");
		return ret;
	}

	phy = devm_phy_create(p_phy->dev, NULL, &pistachio_usb_phy_ops);
	if (IS_ERR(phy)) {
		dev_err(p_phy->dev, "Failed to create PHY: %ld\n",
			PTR_ERR(phy));
		return PTR_ERR(phy);
	}
	phy_set_drvdata(phy, p_phy);

	provider = devm_of_phy_provider_register(p_phy->dev,
						 of_phy_simple_xlate);
	if (IS_ERR(provider)) {
		dev_err(p_phy->dev, "Failed to register PHY provider: %ld\n",
			PTR_ERR(provider));
		return PTR_ERR(provider);
	}

	return 0;
}

