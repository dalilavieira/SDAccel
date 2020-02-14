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
struct device {struct device_node* of_node; } ;
struct platform_device {struct device dev; } ;
struct mtk_ahci_plat {struct ahci_host_priv* mode; struct ahci_host_priv* axi_rst; struct ahci_host_priv* sw_rst; struct ahci_host_priv* reg_rst; } ;
struct device_node {int dummy; } ;
struct ahci_host_priv {struct mtk_ahci_plat* plat_data; int /*<<< orphan*/  force_port_map; } ;

/* Variables and functions */
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct ahci_host_priv*) ; 
 int PTR_ERR (struct ahci_host_priv*) ; 
 int /*<<< orphan*/  SYS_CFG ; 
 int /*<<< orphan*/  SYS_CFG_SATA_EN ; 
 int /*<<< orphan*/  SYS_CFG_SATA_MSK ; 
 int /*<<< orphan*/  ahci_platform_disable_resources (struct ahci_host_priv*) ; 
 int ahci_platform_enable_resources (struct ahci_host_priv*) ; 
 struct ahci_host_priv* ahci_platform_get_resources (struct platform_device*,int /*<<< orphan*/ ) ; 
 int ahci_platform_init_host (struct platform_device*,struct ahci_host_priv*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ahci_platform_sht ; 
 int /*<<< orphan*/  ahci_port_info ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 struct mtk_ahci_plat* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 void* devm_reset_control_get_optional_exclusive (struct device*,char*) ; 
 scalar_t__ of_find_property (struct device_node*,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  of_property_read_u32 (struct device_node*,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  regmap_update_bits (struct ahci_host_priv*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int reset_control_assert (struct ahci_host_priv*) ; 
 int reset_control_deassert (struct ahci_host_priv*) ; 
 struct ahci_host_priv* syscon_regmap_lookup_by_phandle (struct device_node*,char*) ; 

__attribute__((used)) static int mtk_ahci_platform_resets(struct ahci_host_priv *hpriv,
				    struct device *dev)
{
	struct mtk_ahci_plat *plat = hpriv->plat_data;
	int err;

	/* reset AXI bus and PHY part */
	plat->axi_rst = devm_reset_control_get_optional_exclusive(dev, "axi");
	if (PTR_ERR(plat->axi_rst) == -EPROBE_DEFER)
		return PTR_ERR(plat->axi_rst);

	plat->sw_rst = devm_reset_control_get_optional_exclusive(dev, "sw");
	if (PTR_ERR(plat->sw_rst) == -EPROBE_DEFER)
		return PTR_ERR(plat->sw_rst);

	plat->reg_rst = devm_reset_control_get_optional_exclusive(dev, "reg");
	if (PTR_ERR(plat->reg_rst) == -EPROBE_DEFER)
		return PTR_ERR(plat->reg_rst);

	err = reset_control_assert(plat->axi_rst);
	if (err) {
		dev_err(dev, "failed to assert AXI bus\n");
		return err;
	}

	err = reset_control_assert(plat->sw_rst);
	if (err) {
		dev_err(dev, "failed to assert PHY digital part\n");
		return err;
	}

	err = reset_control_assert(plat->reg_rst);
	if (err) {
		dev_err(dev, "failed to assert PHY register part\n");
		return err;
	}

	err = reset_control_deassert(plat->reg_rst);
	if (err) {
		dev_err(dev, "failed to deassert PHY register part\n");
		return err;
	}

	err = reset_control_deassert(plat->sw_rst);
	if (err) {
		dev_err(dev, "failed to deassert PHY digital part\n");
		return err;
	}

	err = reset_control_deassert(plat->axi_rst);
	if (err) {
		dev_err(dev, "failed to deassert AXI bus\n");
		return err;
	}

	return 0;
}

__attribute__((used)) static int mtk_ahci_parse_property(struct ahci_host_priv *hpriv,
				   struct device *dev)
{
	struct mtk_ahci_plat *plat = hpriv->plat_data;
	struct device_node *np = dev->of_node;

	/* enable SATA function if needed */
	if (of_find_property(np, "mediatek,phy-mode", NULL)) {
		plat->mode = syscon_regmap_lookup_by_phandle(
					np, "mediatek,phy-mode");
		if (IS_ERR(plat->mode)) {
			dev_err(dev, "missing phy-mode phandle\n");
			return PTR_ERR(plat->mode);
		}

		regmap_update_bits(plat->mode, SYS_CFG, SYS_CFG_SATA_MSK,
				   SYS_CFG_SATA_EN);
	}

	of_property_read_u32(np, "ports-implemented", &hpriv->force_port_map);

	return 0;
}

__attribute__((used)) static int mtk_ahci_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct mtk_ahci_plat *plat;
	struct ahci_host_priv *hpriv;
	int err;

	plat = devm_kzalloc(dev, sizeof(*plat), GFP_KERNEL);
	if (!plat)
		return -ENOMEM;

	hpriv = ahci_platform_get_resources(pdev, 0);
	if (IS_ERR(hpriv))
		return PTR_ERR(hpriv);

	hpriv->plat_data = plat;

	err = mtk_ahci_parse_property(hpriv, dev);
	if (err)
		return err;

	err = mtk_ahci_platform_resets(hpriv, dev);
	if (err)
		return err;

	err = ahci_platform_enable_resources(hpriv);
	if (err)
		return err;

	err = ahci_platform_init_host(pdev, hpriv, &ahci_port_info,
				      &ahci_platform_sht);
	if (err)
		goto disable_resources;

	return 0;

disable_resources:
	ahci_platform_disable_resources(hpriv);
	return err;
}

