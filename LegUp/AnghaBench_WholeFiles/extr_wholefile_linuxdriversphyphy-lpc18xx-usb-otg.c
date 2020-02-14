#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_8__ {TYPE_1__* of_node; } ;
struct platform_device {TYPE_2__ dev; } ;
struct phy_provider {int dummy; } ;
struct phy {int dummy; } ;
struct lpc18xx_usb_otg_phy {int /*<<< orphan*/  phy; int /*<<< orphan*/  clk; int /*<<< orphan*/  reg; } ;
struct TYPE_7__ {int /*<<< orphan*/  parent; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LPC18XX_CREG_CREG0 ; 
 int /*<<< orphan*/  LPC18XX_CREG_CREG0_USB0PHY ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR_OR_ZERO (struct phy_provider*) ; 
 int /*<<< orphan*/  clk_disable (int /*<<< orphan*/ ) ; 
 int clk_enable (int /*<<< orphan*/ ) ; 
 int clk_prepare (int /*<<< orphan*/ ) ; 
 int clk_set_rate (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  clk_unprepare (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*) ; 
 int /*<<< orphan*/  devm_clk_get (TYPE_2__*,int /*<<< orphan*/ *) ; 
 struct lpc18xx_usb_otg_phy* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 struct phy_provider* devm_of_phy_provider_register (TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_phy_create (TYPE_2__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lpc18xx_usb_otg_phy_ops ; 
 int /*<<< orphan*/  of_phy_simple_xlate ; 
 struct lpc18xx_usb_otg_phy* phy_get_drvdata (struct phy*) ; 
 int /*<<< orphan*/  phy_set_drvdata (int /*<<< orphan*/ ,struct lpc18xx_usb_otg_phy*) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  syscon_node_to_regmap (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int lpc18xx_usb_otg_phy_init(struct phy *phy)
{
	struct lpc18xx_usb_otg_phy *lpc = phy_get_drvdata(phy);
	int ret;

	/* The PHY must be clocked at 480 MHz */
	ret = clk_set_rate(lpc->clk, 480000000);
	if (ret)
		return ret;

	return clk_prepare(lpc->clk);
}

__attribute__((used)) static int lpc18xx_usb_otg_phy_exit(struct phy *phy)
{
	struct lpc18xx_usb_otg_phy *lpc = phy_get_drvdata(phy);

	clk_unprepare(lpc->clk);

	return 0;
}

__attribute__((used)) static int lpc18xx_usb_otg_phy_power_on(struct phy *phy)
{
	struct lpc18xx_usb_otg_phy *lpc = phy_get_drvdata(phy);
	int ret;

	ret = clk_enable(lpc->clk);
	if (ret)
		return ret;

	/* The bit in CREG is cleared to enable the PHY */
	ret = regmap_update_bits(lpc->reg, LPC18XX_CREG_CREG0,
				  LPC18XX_CREG_CREG0_USB0PHY, 0);
	if (ret) {
		clk_disable(lpc->clk);
		return ret;
	}

	return 0;
}

__attribute__((used)) static int lpc18xx_usb_otg_phy_power_off(struct phy *phy)
{
	struct lpc18xx_usb_otg_phy *lpc = phy_get_drvdata(phy);
	int ret;

	ret = regmap_update_bits(lpc->reg, LPC18XX_CREG_CREG0,
				 LPC18XX_CREG_CREG0_USB0PHY,
				 LPC18XX_CREG_CREG0_USB0PHY);
	if (ret)
		return ret;

	clk_disable(lpc->clk);

	return 0;
}

__attribute__((used)) static int lpc18xx_usb_otg_phy_probe(struct platform_device *pdev)
{
	struct phy_provider *phy_provider;
	struct lpc18xx_usb_otg_phy *lpc;

	lpc = devm_kzalloc(&pdev->dev, sizeof(*lpc), GFP_KERNEL);
	if (!lpc)
		return -ENOMEM;

	lpc->reg = syscon_node_to_regmap(pdev->dev.of_node->parent);
	if (IS_ERR(lpc->reg)) {
		dev_err(&pdev->dev, "failed to get syscon\n");
		return PTR_ERR(lpc->reg);
	}

	lpc->clk = devm_clk_get(&pdev->dev, NULL);
	if (IS_ERR(lpc->clk)) {
		dev_err(&pdev->dev, "failed to get clock\n");
		return PTR_ERR(lpc->clk);
	}

	lpc->phy = devm_phy_create(&pdev->dev, NULL, &lpc18xx_usb_otg_phy_ops);
	if (IS_ERR(lpc->phy)) {
		dev_err(&pdev->dev, "failed to create PHY\n");
		return PTR_ERR(lpc->phy);
	}

	phy_set_drvdata(lpc->phy, lpc);

	phy_provider = devm_of_phy_provider_register(&pdev->dev,
						     of_phy_simple_xlate);

	return PTR_ERR_OR_ZERO(phy_provider);
}

