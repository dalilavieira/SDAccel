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
struct regmap {int dummy; } ;
struct device {int /*<<< orphan*/  of_node; } ;
struct platform_device {struct device dev; } ;
struct phy_provider {int dummy; } ;
typedef  struct regmap phy ;
struct hi6220_priv {struct regmap* reg; struct device* dev; } ;

/* Variables and functions */
 int CTRL4_OTG_PHY_SEL ; 
 int CTRL4_PICO_OGDISABLE ; 
 int CTRL4_PICO_SIDDQ ; 
 int CTRL4_PICO_VBUSVLDEXT ; 
 int CTRL4_PICO_VBUSVLDEXTSEL ; 
 int CTRL5_PICOPHY_ACAENB ; 
 int CTRL5_PICOPHY_BC_MODE ; 
 int CTRL5_USBOTG_RES_SEL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  EYE_PATTERN_PARA ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct regmap*) ; 
 int PTR_ERR (struct regmap*) ; 
 int PTR_ERR_OR_ZERO (struct phy_provider*) ; 
 int RST0_POR_PICOPHY ; 
 int RST0_USBOTG ; 
 int RST0_USBOTG_32K ; 
 int RST0_USBOTG_BUS ; 
 int /*<<< orphan*/  SC_PERIPH_CTRL4 ; 
 int /*<<< orphan*/  SC_PERIPH_CTRL5 ; 
 int /*<<< orphan*/  SC_PERIPH_CTRL8 ; 
 int /*<<< orphan*/  SC_PERIPH_RSTDIS0 ; 
 int /*<<< orphan*/  SC_PERIPH_RSTEN0 ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct hi6220_priv* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 struct phy_provider* devm_of_phy_provider_register (struct device*,int /*<<< orphan*/ ) ; 
 struct regmap* devm_phy_create (struct device*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  hi6220_phy_ops ; 
 int /*<<< orphan*/  of_phy_simple_xlate ; 
 struct hi6220_priv* phy_get_drvdata (struct regmap*) ; 
 int /*<<< orphan*/  phy_set_drvdata (struct regmap*,struct hi6220_priv*) ; 
 int regmap_update_bits (struct regmap*,int /*<<< orphan*/ ,int,int) ; 
 int regmap_write (struct regmap*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct regmap* syscon_regmap_lookup_by_phandle (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static void hi6220_phy_init(struct hi6220_priv *priv)
{
	struct regmap *reg = priv->reg;
	u32 val, mask;

	val = RST0_USBOTG_BUS | RST0_POR_PICOPHY |
	      RST0_USBOTG | RST0_USBOTG_32K;
	mask = val;
	regmap_update_bits(reg, SC_PERIPH_RSTEN0, mask, val);
	regmap_update_bits(reg, SC_PERIPH_RSTDIS0, mask, val);
}

__attribute__((used)) static int hi6220_phy_setup(struct hi6220_priv *priv, bool on)
{
	struct regmap *reg = priv->reg;
	u32 val, mask;
	int ret;

	if (on) {
		val = CTRL5_USBOTG_RES_SEL | CTRL5_PICOPHY_ACAENB;
		mask = val | CTRL5_PICOPHY_BC_MODE;
		ret = regmap_update_bits(reg, SC_PERIPH_CTRL5, mask, val);
		if (ret)
			goto out;

		val =  CTRL4_PICO_VBUSVLDEXT | CTRL4_PICO_VBUSVLDEXTSEL |
		       CTRL4_OTG_PHY_SEL;
		mask = val | CTRL4_PICO_SIDDQ | CTRL4_PICO_OGDISABLE;
		ret = regmap_update_bits(reg, SC_PERIPH_CTRL4, mask, val);
		if (ret)
			goto out;

		ret = regmap_write(reg, SC_PERIPH_CTRL8, EYE_PATTERN_PARA);
		if (ret)
			goto out;
	} else {
		val = CTRL4_PICO_SIDDQ;
		mask = val;
		ret = regmap_update_bits(reg, SC_PERIPH_CTRL4, mask, val);
		if (ret)
			goto out;
	}

	return 0;
out:
	dev_err(priv->dev, "failed to setup phy ret: %d\n", ret);
	return ret;
}

__attribute__((used)) static int hi6220_phy_start(struct phy *phy)
{
	struct hi6220_priv *priv = phy_get_drvdata(phy);

	return hi6220_phy_setup(priv, true);
}

__attribute__((used)) static int hi6220_phy_exit(struct phy *phy)
{
	struct hi6220_priv *priv = phy_get_drvdata(phy);

	return hi6220_phy_setup(priv, false);
}

__attribute__((used)) static int hi6220_phy_probe(struct platform_device *pdev)
{
	struct phy_provider *phy_provider;
	struct device *dev = &pdev->dev;
	struct phy *phy;
	struct hi6220_priv *priv;

	priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	priv->dev = dev;
	priv->reg = syscon_regmap_lookup_by_phandle(dev->of_node,
					"hisilicon,peripheral-syscon");
	if (IS_ERR(priv->reg)) {
		dev_err(dev, "no hisilicon,peripheral-syscon\n");
		return PTR_ERR(priv->reg);
	}

	hi6220_phy_init(priv);

	phy = devm_phy_create(dev, NULL, &hi6220_phy_ops);
	if (IS_ERR(phy))
		return PTR_ERR(phy);

	phy_set_drvdata(phy, priv);
	phy_provider = devm_of_phy_provider_register(dev, of_phy_simple_xlate);
	return PTR_ERR_OR_ZERO(phy_provider);
}

