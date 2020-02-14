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
struct resource {int /*<<< orphan*/  start; } ;
struct device {int /*<<< orphan*/  of_node; } ;
struct platform_device {struct device dev; } ;
struct phy_provider {int dummy; } ;
struct phy {struct device dev; } ;
struct hix5hd2_priv {struct phy* peri_ctrl; scalar_t__ base; } ;

/* Variables and functions */
 int AMPLITUDE_GEN1 ; 
 int AMPLITUDE_GEN1_SHIFT ; 
 int AMPLITUDE_GEN2 ; 
 int AMPLITUDE_GEN2_SHIFT ; 
 int AMPLITUDE_GEN3 ; 
 int AMPLITUDE_GEN3_SHIFT ; 
 int AMPLITUDE_MASK ; 
 int /*<<< orphan*/  BIT (int) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int GEN2_EN_SHIFT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HALF_RATE_SHIFT ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (struct phy*) ; 
 int MPLL_MULTIPLIER_50M ; 
 int MPLL_MULTIPLIER_MASK ; 
 int MPLL_MULTIPLIER_SHIFT ; 
 int PHY_CONFIG_SHIFT ; 
 int PHY_RESET ; 
 int PREEMPH_GEN1 ; 
 int PREEMPH_GEN1_SHIFT ; 
 int PREEMPH_GEN2 ; 
 int PREEMPH_GEN2_SHIFT ; 
 int PREEMPH_GEN3 ; 
 int PREEMPH_GEN3_SHIFT ; 
 int PREEMPH_MASK ; 
 int PTR_ERR (struct phy*) ; 
 int PTR_ERR_OR_ZERO (struct phy_provider*) ; 
 int REF_SSP_EN ; 
 int REF_USE_PAD ; 
 scalar_t__ SATA_PHY0_CTLL ; 
 scalar_t__ SATA_PORT_PHYCTL ; 
 scalar_t__ SATA_PORT_PHYCTL1 ; 
 scalar_t__ SATA_PORT_PHYCTL2 ; 
 int SPEED_CTRL ; 
 int SPEED_MODE_GEN1 ; 
 int SPEED_MODE_GEN2 ; 
 int SPEED_MODE_GEN3 ; 
 int SPEED_MODE_MASK ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 scalar_t__ devm_ioremap (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct hix5hd2_priv* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 struct phy_provider* devm_of_phy_provider_register (struct device*,int /*<<< orphan*/ ) ; 
 struct phy* devm_phy_create (struct device*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  hix5hd2_sata_phy_ops ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  of_phy_simple_xlate ; 
 int of_property_read_u32_array (int /*<<< orphan*/ ,char*,int*,int) ; 
 struct hix5hd2_priv* phy_get_drvdata (struct phy*) ; 
 int /*<<< orphan*/  phy_set_drvdata (struct phy*,struct hix5hd2_priv*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int readl_relaxed (scalar_t__) ; 
 int /*<<< orphan*/  regmap_update_bits (struct phy*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  resource_size (struct resource*) ; 
 struct phy* syscon_regmap_lookup_by_phandle (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  writel_relaxed (int,scalar_t__) ; 

__attribute__((used)) static int hix5hd2_sata_phy_init(struct phy *phy)
{
	struct hix5hd2_priv *priv = phy_get_drvdata(phy);
	u32 val, data[2];
	int ret;

	if (priv->peri_ctrl) {
		ret = of_property_read_u32_array(phy->dev.of_node,
						 "hisilicon,power-reg",
						 &data[0], 2);
		if (ret) {
			dev_err(&phy->dev, "Fail read hisilicon,power-reg\n");
			return ret;
		}

		regmap_update_bits(priv->peri_ctrl, data[0],
				   BIT(data[1]), BIT(data[1]));
	}

	/* reset phy */
	val = readl_relaxed(priv->base + SATA_PHY0_CTLL);
	val &= ~(MPLL_MULTIPLIER_MASK | REF_USE_PAD);
	val |= MPLL_MULTIPLIER_50M << MPLL_MULTIPLIER_SHIFT |
	       REF_SSP_EN | PHY_RESET;
	writel_relaxed(val, priv->base + SATA_PHY0_CTLL);
	msleep(20);
	val &= ~PHY_RESET;
	writel_relaxed(val, priv->base + SATA_PHY0_CTLL);

	val = readl_relaxed(priv->base + SATA_PORT_PHYCTL1);
	val &= ~AMPLITUDE_MASK;
	val |= AMPLITUDE_GEN3 << AMPLITUDE_GEN3_SHIFT |
	       AMPLITUDE_GEN2 << AMPLITUDE_GEN2_SHIFT |
	       AMPLITUDE_GEN1 << AMPLITUDE_GEN1_SHIFT;
	writel_relaxed(val, priv->base + SATA_PORT_PHYCTL1);

	val = readl_relaxed(priv->base + SATA_PORT_PHYCTL2);
	val &= ~PREEMPH_MASK;
	val |= PREEMPH_GEN3 << PREEMPH_GEN3_SHIFT |
	       PREEMPH_GEN2 << PREEMPH_GEN2_SHIFT |
	       PREEMPH_GEN1 << PREEMPH_GEN1_SHIFT;
	writel_relaxed(val, priv->base + SATA_PORT_PHYCTL2);

	/* ensure PHYCTRL setting takes effect */
	val = readl_relaxed(priv->base + SATA_PORT_PHYCTL);
	val &= ~SPEED_MODE_MASK;
	val |= SPEED_MODE_GEN1 << HALF_RATE_SHIFT |
	       SPEED_MODE_GEN1 << PHY_CONFIG_SHIFT |
	       SPEED_MODE_GEN1 << GEN2_EN_SHIFT | SPEED_CTRL;
	writel_relaxed(val, priv->base + SATA_PORT_PHYCTL);

	msleep(20);
	val &= ~SPEED_MODE_MASK;
	val |= SPEED_MODE_GEN3 << HALF_RATE_SHIFT |
	       SPEED_MODE_GEN3 << PHY_CONFIG_SHIFT |
	       SPEED_MODE_GEN3 << GEN2_EN_SHIFT | SPEED_CTRL;
	writel_relaxed(val, priv->base + SATA_PORT_PHYCTL);

	val &= ~(SPEED_MODE_MASK | SPEED_CTRL);
	val |= SPEED_MODE_GEN2 << HALF_RATE_SHIFT |
	       SPEED_MODE_GEN2 << PHY_CONFIG_SHIFT |
	       SPEED_MODE_GEN2 << GEN2_EN_SHIFT;
	writel_relaxed(val, priv->base + SATA_PORT_PHYCTL);

	return 0;
}

__attribute__((used)) static int hix5hd2_sata_phy_probe(struct platform_device *pdev)
{
	struct phy_provider *phy_provider;
	struct device *dev = &pdev->dev;
	struct resource *res;
	struct phy *phy;
	struct hix5hd2_priv *priv;

	priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!res)
		return -EINVAL;

	priv->base = devm_ioremap(dev, res->start, resource_size(res));
	if (!priv->base)
		return -ENOMEM;

	priv->peri_ctrl = syscon_regmap_lookup_by_phandle(dev->of_node,
					"hisilicon,peripheral-syscon");
	if (IS_ERR(priv->peri_ctrl))
		priv->peri_ctrl = NULL;

	phy = devm_phy_create(dev, NULL, &hix5hd2_sata_phy_ops);
	if (IS_ERR(phy)) {
		dev_err(dev, "failed to create PHY\n");
		return PTR_ERR(phy);
	}

	phy_set_drvdata(phy, priv);
	phy_provider = devm_of_phy_provider_register(dev, of_phy_simple_xlate);
	return PTR_ERR_OR_ZERO(phy_provider);
}

