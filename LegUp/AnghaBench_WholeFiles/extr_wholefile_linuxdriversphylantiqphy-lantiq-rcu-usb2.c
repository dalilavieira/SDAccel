#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct device {TYPE_1__* of_node; } ;
struct platform_device {struct device dev; } ;
struct phy_provider {int dummy; } ;
struct phy {int dummy; } ;
struct ltq_rcu_usb2_priv {struct device* dev; struct phy_provider* phy; struct phy_provider* phy_reset; struct phy_provider* ctrl_reset; struct phy_provider* phy_gate_clk; void* ana_cfg1_reg_offset; TYPE_2__* reg_bits; void* phy_reg_offset; struct phy_provider* regmap; } ;
typedef  int /*<<< orphan*/  __be32 ;
struct TYPE_5__ {scalar_t__ have_ana_cfg; int /*<<< orphan*/  host_endianness; int /*<<< orphan*/  slave_endianness; int /*<<< orphan*/  hostmode; } ;
struct TYPE_4__ {int /*<<< orphan*/  parent; } ;

/* Variables and functions */
 int BIT (int /*<<< orphan*/ ) ; 
 int ENOENT ; 
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct phy_provider*) ; 
 int PTR_ERR (struct phy_provider*) ; 
 int RCU_CFG1_DIS_THR_MASK ; 
 int RCU_CFG1_DIS_THR_SHIFT ; 
 int RCU_CFG1_TX_PEE ; 
 void* __be32_to_cpu (int /*<<< orphan*/  const) ; 
 int /*<<< orphan*/  clk_disable_unprepare (struct phy_provider*) ; 
 int clk_prepare_enable (struct phy_provider*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct ltq_rcu_usb2_priv*) ; 
 struct phy_provider* devm_clk_get (struct device*,char*) ; 
 struct ltq_rcu_usb2_priv* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 struct phy_provider* devm_of_phy_provider_register (struct device*,int /*<<< orphan*/ ) ; 
 struct phy_provider* devm_phy_create (struct device*,TYPE_1__*,int /*<<< orphan*/ *) ; 
 struct phy_provider* devm_reset_control_get_optional (struct device*,char*) ; 
 struct phy_provider* devm_reset_control_get_shared (struct device*,char*) ; 
 int /*<<< orphan*/  ltq_rcu_usb2_phy_ops ; 
 TYPE_2__* of_device_get_match_data (struct device*) ; 
 int /*<<< orphan*/ * of_get_address (TYPE_1__*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  of_phy_simple_xlate ; 
 struct ltq_rcu_usb2_priv* phy_get_drvdata (struct phy*) ; 
 int /*<<< orphan*/  phy_set_drvdata (struct phy_provider*,struct ltq_rcu_usb2_priv*) ; 
 int /*<<< orphan*/  regmap_update_bits (struct phy_provider*,void*,int,int) ; 
 int /*<<< orphan*/  reset_control_assert (struct phy_provider*) ; 
 int /*<<< orphan*/  reset_control_deassert (struct phy_provider*) ; 
 struct phy_provider* syscon_node_to_regmap (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int ltq_rcu_usb2_phy_init(struct phy *phy)
{
	struct ltq_rcu_usb2_priv *priv = phy_get_drvdata(phy);

	if (priv->reg_bits->have_ana_cfg) {
		regmap_update_bits(priv->regmap, priv->ana_cfg1_reg_offset,
			RCU_CFG1_TX_PEE, RCU_CFG1_TX_PEE);
		regmap_update_bits(priv->regmap, priv->ana_cfg1_reg_offset,
			RCU_CFG1_DIS_THR_MASK, 7 << RCU_CFG1_DIS_THR_SHIFT);
	}

	/* Configure core to host mode */
	regmap_update_bits(priv->regmap, priv->phy_reg_offset,
			   BIT(priv->reg_bits->hostmode), 0);

	/* Select DMA endianness (Host-endian: big-endian) */
	regmap_update_bits(priv->regmap, priv->phy_reg_offset,
		BIT(priv->reg_bits->slave_endianness), 0);
	regmap_update_bits(priv->regmap, priv->phy_reg_offset,
		BIT(priv->reg_bits->host_endianness),
		BIT(priv->reg_bits->host_endianness));

	return 0;
}

__attribute__((used)) static int ltq_rcu_usb2_phy_power_on(struct phy *phy)
{
	struct ltq_rcu_usb2_priv *priv = phy_get_drvdata(phy);
	struct device *dev = priv->dev;
	int ret;

	reset_control_deassert(priv->phy_reset);

	ret = clk_prepare_enable(priv->phy_gate_clk);
	if (ret)
		dev_err(dev, "failed to enable PHY gate\n");

	return ret;
}

__attribute__((used)) static int ltq_rcu_usb2_phy_power_off(struct phy *phy)
{
	struct ltq_rcu_usb2_priv *priv = phy_get_drvdata(phy);

	reset_control_assert(priv->phy_reset);

	clk_disable_unprepare(priv->phy_gate_clk);

	return 0;
}

__attribute__((used)) static int ltq_rcu_usb2_of_parse(struct ltq_rcu_usb2_priv *priv,
				 struct platform_device *pdev)
{
	struct device *dev = priv->dev;
	const __be32 *offset;
	int ret;

	priv->reg_bits = of_device_get_match_data(dev);

	priv->regmap = syscon_node_to_regmap(dev->of_node->parent);
	if (IS_ERR(priv->regmap)) {
		dev_err(dev, "Failed to lookup RCU regmap\n");
		return PTR_ERR(priv->regmap);
	}

	offset = of_get_address(dev->of_node, 0, NULL, NULL);
	if (!offset) {
		dev_err(dev, "Failed to get RCU PHY reg offset\n");
		return -ENOENT;
	}
	priv->phy_reg_offset = __be32_to_cpu(*offset);

	if (priv->reg_bits->have_ana_cfg) {
		offset = of_get_address(dev->of_node, 1, NULL, NULL);
		if (!offset) {
			dev_err(dev, "Failed to get RCU ANA CFG1 reg offset\n");
			return -ENOENT;
		}
		priv->ana_cfg1_reg_offset = __be32_to_cpu(*offset);
	}

	priv->phy_gate_clk = devm_clk_get(dev, "phy");
	if (IS_ERR(priv->phy_gate_clk)) {
		dev_err(dev, "Unable to get USB phy gate clk\n");
		return PTR_ERR(priv->phy_gate_clk);
	}

	priv->ctrl_reset = devm_reset_control_get_shared(dev, "ctrl");
	if (IS_ERR(priv->ctrl_reset)) {
		if (PTR_ERR(priv->ctrl_reset) != -EPROBE_DEFER)
			dev_err(dev, "failed to get 'ctrl' reset\n");
		return PTR_ERR(priv->ctrl_reset);
	}

	priv->phy_reset = devm_reset_control_get_optional(dev, "phy");
	if (IS_ERR(priv->phy_reset))
		return PTR_ERR(priv->phy_reset);

	return 0;
}

__attribute__((used)) static int ltq_rcu_usb2_phy_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct ltq_rcu_usb2_priv *priv;
	struct phy_provider *provider;
	int ret;

	priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	priv->dev = dev;

	ret = ltq_rcu_usb2_of_parse(priv, pdev);
	if (ret)
		return ret;

	/* Reset USB core through reset controller */
	reset_control_deassert(priv->ctrl_reset);

	reset_control_assert(priv->phy_reset);

	priv->phy = devm_phy_create(dev, dev->of_node, &ltq_rcu_usb2_phy_ops);
	if (IS_ERR(priv->phy)) {
		dev_err(dev, "failed to create PHY\n");
		return PTR_ERR(priv->phy);
	}

	phy_set_drvdata(priv->phy, priv);

	provider = devm_of_phy_provider_register(dev, of_phy_simple_xlate);
	if (IS_ERR(provider))
		return PTR_ERR(provider);

	dev_set_drvdata(priv->dev, priv);
	return 0;
}

