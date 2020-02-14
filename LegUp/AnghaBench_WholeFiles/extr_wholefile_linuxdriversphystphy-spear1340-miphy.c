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
struct spear1340_miphy_priv {scalar_t__ mode; struct phy_provider* phy; struct phy_provider* misc; } ;
struct device {int /*<<< orphan*/  of_node; } ;
struct platform_device {struct device dev; } ;
struct phy_provider {int dummy; } ;
typedef  struct phy_provider phy ;
struct of_phandle_args {int args_count; scalar_t__* args; } ;

/* Variables and functions */
 int /*<<< orphan*/  ENODEV ; 
 int ENOMEM ; 
 struct phy_provider* ERR_PTR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct phy_provider*) ; 
 scalar_t__ PCIE ; 
 int PTR_ERR (struct phy_provider*) ; 
 scalar_t__ SATA ; 
 int /*<<< orphan*/  SPEAR1340_PCIE_CFG_VAL ; 
 int /*<<< orphan*/  SPEAR1340_PCIE_MIPHY_CFG ; 
 int /*<<< orphan*/  SPEAR1340_PCIE_MIPHY_CFG_MASK ; 
 int /*<<< orphan*/  SPEAR1340_PCIE_SATA_CFG ; 
 int /*<<< orphan*/  SPEAR1340_PCIE_SATA_CFG_MASK ; 
 int /*<<< orphan*/  SPEAR1340_PCIE_SATA_MIPHY_CFG_PCIE ; 
 int /*<<< orphan*/  SPEAR1340_PCIE_SATA_MIPHY_CFG_SATA_25M_CRYSTAL_CLK ; 
 int /*<<< orphan*/  SPEAR1340_PCM_CFG ; 
 int /*<<< orphan*/  SPEAR1340_PCM_CFG_SATA_POWER_EN ; 
 int /*<<< orphan*/  SPEAR1340_PERIP1_SW_RSATA ; 
 int /*<<< orphan*/  SPEAR1340_PERIP1_SW_RST ; 
 int /*<<< orphan*/  SPEAR1340_SATA_CFG_VAL ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 struct spear1340_miphy_priv* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct spear1340_miphy_priv*) ; 
 struct spear1340_miphy_priv* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 struct phy_provider* devm_of_phy_provider_register (struct device*,struct phy_provider* (*) (struct device*,struct of_phandle_args*)) ; 
 struct phy_provider* devm_phy_create (struct device*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  msleep (int) ; 
 struct spear1340_miphy_priv* phy_get_drvdata (struct phy_provider*) ; 
 int /*<<< orphan*/  phy_set_drvdata (struct phy_provider*,struct spear1340_miphy_priv*) ; 
 int /*<<< orphan*/  regmap_update_bits (struct phy_provider*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spear1340_miphy_ops ; 
 struct phy_provider* syscon_regmap_lookup_by_phandle (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static int spear1340_miphy_sata_init(struct spear1340_miphy_priv *priv)
{
	regmap_update_bits(priv->misc, SPEAR1340_PCIE_SATA_CFG,
			   SPEAR1340_PCIE_SATA_CFG_MASK,
			   SPEAR1340_SATA_CFG_VAL);
	regmap_update_bits(priv->misc, SPEAR1340_PCIE_MIPHY_CFG,
			   SPEAR1340_PCIE_MIPHY_CFG_MASK,
			   SPEAR1340_PCIE_SATA_MIPHY_CFG_SATA_25M_CRYSTAL_CLK);
	/* Switch on sata power domain */
	regmap_update_bits(priv->misc, SPEAR1340_PCM_CFG,
			   SPEAR1340_PCM_CFG_SATA_POWER_EN,
			   SPEAR1340_PCM_CFG_SATA_POWER_EN);
	/* Wait for SATA power domain on */
	msleep(20);

	/* Disable PCIE SATA Controller reset */
	regmap_update_bits(priv->misc, SPEAR1340_PERIP1_SW_RST,
			   SPEAR1340_PERIP1_SW_RSATA, 0);
	/* Wait for SATA reset de-assert completion */
	msleep(20);

	return 0;
}

__attribute__((used)) static int spear1340_miphy_sata_exit(struct spear1340_miphy_priv *priv)
{
	regmap_update_bits(priv->misc, SPEAR1340_PCIE_SATA_CFG,
			   SPEAR1340_PCIE_SATA_CFG_MASK, 0);
	regmap_update_bits(priv->misc, SPEAR1340_PCIE_MIPHY_CFG,
			   SPEAR1340_PCIE_MIPHY_CFG_MASK, 0);

	/* Enable PCIE SATA Controller reset */
	regmap_update_bits(priv->misc, SPEAR1340_PERIP1_SW_RST,
			   SPEAR1340_PERIP1_SW_RSATA,
			   SPEAR1340_PERIP1_SW_RSATA);
	/* Wait for SATA power domain off */
	msleep(20);
	/* Switch off sata power domain */
	regmap_update_bits(priv->misc, SPEAR1340_PCM_CFG,
			   SPEAR1340_PCM_CFG_SATA_POWER_EN, 0);
	/* Wait for SATA reset assert completion */
	msleep(20);

	return 0;
}

__attribute__((used)) static int spear1340_miphy_pcie_init(struct spear1340_miphy_priv *priv)
{
	regmap_update_bits(priv->misc, SPEAR1340_PCIE_MIPHY_CFG,
			   SPEAR1340_PCIE_MIPHY_CFG_MASK,
			   SPEAR1340_PCIE_SATA_MIPHY_CFG_PCIE);
	regmap_update_bits(priv->misc, SPEAR1340_PCIE_SATA_CFG,
			   SPEAR1340_PCIE_SATA_CFG_MASK,
			   SPEAR1340_PCIE_CFG_VAL);

	return 0;
}

__attribute__((used)) static int spear1340_miphy_pcie_exit(struct spear1340_miphy_priv *priv)
{
	regmap_update_bits(priv->misc, SPEAR1340_PCIE_MIPHY_CFG,
			   SPEAR1340_PCIE_MIPHY_CFG_MASK, 0);
	regmap_update_bits(priv->misc, SPEAR1340_PCIE_SATA_CFG,
			   SPEAR1340_PCIE_SATA_CFG_MASK, 0);

	return 0;
}

__attribute__((used)) static int spear1340_miphy_init(struct phy *phy)
{
	struct spear1340_miphy_priv *priv = phy_get_drvdata(phy);
	int ret = 0;

	if (priv->mode == SATA)
		ret = spear1340_miphy_sata_init(priv);
	else if (priv->mode == PCIE)
		ret = spear1340_miphy_pcie_init(priv);

	return ret;
}

__attribute__((used)) static int spear1340_miphy_exit(struct phy *phy)
{
	struct spear1340_miphy_priv *priv = phy_get_drvdata(phy);
	int ret = 0;

	if (priv->mode == SATA)
		ret = spear1340_miphy_sata_exit(priv);
	else if (priv->mode == PCIE)
		ret = spear1340_miphy_pcie_exit(priv);

	return ret;
}

__attribute__((used)) static struct phy *spear1340_miphy_xlate(struct device *dev,
					 struct of_phandle_args *args)
{
	struct spear1340_miphy_priv *priv = dev_get_drvdata(dev);

	if (args->args_count < 1) {
		dev_err(dev, "DT did not pass correct no of args\n");
		return ERR_PTR(-ENODEV);
	}

	priv->mode = args->args[0];

	if (priv->mode != SATA && priv->mode != PCIE) {
		dev_err(dev, "DT did not pass correct phy mode\n");
		return ERR_PTR(-ENODEV);
	}

	return priv->phy;
}

__attribute__((used)) static int spear1340_miphy_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct spear1340_miphy_priv *priv;
	struct phy_provider *phy_provider;

	priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	priv->misc =
		syscon_regmap_lookup_by_phandle(dev->of_node, "misc");
	if (IS_ERR(priv->misc)) {
		dev_err(dev, "failed to find misc regmap\n");
		return PTR_ERR(priv->misc);
	}

	priv->phy = devm_phy_create(dev, NULL, &spear1340_miphy_ops);
	if (IS_ERR(priv->phy)) {
		dev_err(dev, "failed to create SATA PCIe PHY\n");
		return PTR_ERR(priv->phy);
	}

	dev_set_drvdata(dev, priv);
	phy_set_drvdata(priv->phy, priv);

	phy_provider =
		devm_of_phy_provider_register(dev, spear1340_miphy_xlate);
	if (IS_ERR(phy_provider)) {
		dev_err(dev, "failed to register phy provider\n");
		return PTR_ERR(phy_provider);
	}

	return 0;
}

