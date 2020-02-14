#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct resource {int dummy; } ;
struct device {struct device_node* of_node; int /*<<< orphan*/ * driver; } ;
struct platform_device {struct device dev; } ;
struct of_device_id {int /*<<< orphan*/  (* data ) (struct cpsw_phy_sel_priv*,int,int) ;} ;
struct device_node {int dummy; } ;
struct cpsw_phy_sel_priv {int rmii_clock_external; int /*<<< orphan*/  gmii_sel; int /*<<< orphan*/  (* cpsw_phy_sel ) (struct cpsw_phy_sel_priv*,int,int) ;struct device* dev; } ;
typedef  int phy_interface_t ;
struct TYPE_2__ {int /*<<< orphan*/  driver; } ;

/* Variables and functions */
 int AM33XX_GMII_SEL_MODE_MII ; 
 int AM33XX_GMII_SEL_MODE_RGMII ; 
 int AM33XX_GMII_SEL_MODE_RMII ; 
 int AM33XX_GMII_SEL_RGMII1_IDMODE ; 
 int AM33XX_GMII_SEL_RGMII2_IDMODE ; 
 int AM33XX_GMII_SEL_RMII1_IO_CLK_EN ; 
 int AM33XX_GMII_SEL_RMII2_IO_CLK_EN ; 
 int BIT (int) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int GMII_SEL_MODE_MASK ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
#define  PHY_INTERFACE_MODE_MII 133 
#define  PHY_INTERFACE_MODE_RGMII 132 
#define  PHY_INTERFACE_MODE_RGMII_ID 131 
#define  PHY_INTERFACE_MODE_RGMII_RXID 130 
#define  PHY_INTERFACE_MODE_RGMII_TXID 129 
#define  PHY_INTERFACE_MODE_RMII 128 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 struct device* bus_find_device (int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct device_node*,int (*) (struct device*,void*)) ; 
 TYPE_1__ cpsw_phy_sel_driver ; 
 int /*<<< orphan*/  cpsw_phy_sel_id_table ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct cpsw_phy_sel_priv* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct cpsw_phy_sel_priv*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_ioremap_resource (struct device*,struct resource*) ; 
 struct cpsw_phy_sel_priv* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 scalar_t__ of_find_property (struct device_node*,char*,int /*<<< orphan*/ *) ; 
 struct device_node* of_get_child_by_name (struct device_node*,char*) ; 
 struct of_device_id* of_match_node (int /*<<< orphan*/ ,struct device_node*) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 struct device_node* of_parse_phandle (struct device_node*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  phy_modes (int) ; 
 int /*<<< orphan*/  platform_bus_type ; 
 struct resource* platform_get_resource_byname (struct platform_device*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  put_device (struct device*) ; 
 int readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (struct cpsw_phy_sel_priv*,int,int) ; 
 int /*<<< orphan*/  writel (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void cpsw_gmii_sel_am3352(struct cpsw_phy_sel_priv *priv,
				 phy_interface_t phy_mode, int slave)
{
	u32 reg;
	u32 mask;
	u32 mode = 0;
	bool rgmii_id = false;

	reg = readl(priv->gmii_sel);

	switch (phy_mode) {
	case PHY_INTERFACE_MODE_RMII:
		mode = AM33XX_GMII_SEL_MODE_RMII;
		break;

	case PHY_INTERFACE_MODE_RGMII:
		mode = AM33XX_GMII_SEL_MODE_RGMII;
		break;

	case PHY_INTERFACE_MODE_RGMII_ID:
	case PHY_INTERFACE_MODE_RGMII_RXID:
	case PHY_INTERFACE_MODE_RGMII_TXID:
		mode = AM33XX_GMII_SEL_MODE_RGMII;
		rgmii_id = true;
		break;

	default:
		dev_warn(priv->dev,
			 "Unsupported PHY mode: \"%s\". Defaulting to MII.\n",
			phy_modes(phy_mode));
		/* fallthrough */
	case PHY_INTERFACE_MODE_MII:
		mode = AM33XX_GMII_SEL_MODE_MII;
		break;
	};

	mask = GMII_SEL_MODE_MASK << (slave * 2) | BIT(slave + 6);
	mask |= BIT(slave + 4);
	mode <<= slave * 2;

	if (priv->rmii_clock_external) {
		if (slave == 0)
			mode |= AM33XX_GMII_SEL_RMII1_IO_CLK_EN;
		else
			mode |= AM33XX_GMII_SEL_RMII2_IO_CLK_EN;
	}

	if (rgmii_id) {
		if (slave == 0)
			mode |= AM33XX_GMII_SEL_RGMII1_IDMODE;
		else
			mode |= AM33XX_GMII_SEL_RGMII2_IDMODE;
	}

	reg &= ~mask;
	reg |= mode;

	writel(reg, priv->gmii_sel);
}

__attribute__((used)) static void cpsw_gmii_sel_dra7xx(struct cpsw_phy_sel_priv *priv,
				 phy_interface_t phy_mode, int slave)
{
	u32 reg;
	u32 mask;
	u32 mode = 0;

	reg = readl(priv->gmii_sel);

	switch (phy_mode) {
	case PHY_INTERFACE_MODE_RMII:
		mode = AM33XX_GMII_SEL_MODE_RMII;
		break;

	case PHY_INTERFACE_MODE_RGMII:
	case PHY_INTERFACE_MODE_RGMII_ID:
	case PHY_INTERFACE_MODE_RGMII_RXID:
	case PHY_INTERFACE_MODE_RGMII_TXID:
		mode = AM33XX_GMII_SEL_MODE_RGMII;
		break;

	default:
		dev_warn(priv->dev,
			 "Unsupported PHY mode: \"%s\". Defaulting to MII.\n",
			phy_modes(phy_mode));
		/* fallthrough */
	case PHY_INTERFACE_MODE_MII:
		mode = AM33XX_GMII_SEL_MODE_MII;
		break;
	};

	switch (slave) {
	case 0:
		mask = GMII_SEL_MODE_MASK;
		break;
	case 1:
		mask = GMII_SEL_MODE_MASK << 4;
		mode <<= 4;
		break;
	default:
		dev_err(priv->dev, "invalid slave number...\n");
		return;
	}

	if (priv->rmii_clock_external)
		dev_err(priv->dev, "RMII External clock is not supported\n");

	reg &= ~mask;
	reg |= mode;

	writel(reg, priv->gmii_sel);
}

__attribute__((used)) static int match(struct device *dev, void *data)
{
	struct device_node *node = (struct device_node *)data;
	return dev->of_node == node &&
		dev->driver == &cpsw_phy_sel_driver.driver;
}

void cpsw_phy_sel(struct device *dev, phy_interface_t phy_mode, int slave)
{
	struct device_node *node;
	struct cpsw_phy_sel_priv *priv;

	node = of_parse_phandle(dev->of_node, "cpsw-phy-sel", 0);
	if (!node) {
		node = of_get_child_by_name(dev->of_node, "cpsw-phy-sel");
		if (!node) {
			dev_err(dev, "Phy mode driver DT not found\n");
			return;
		}
	}

	dev = bus_find_device(&platform_bus_type, NULL, node, match);
	if (!dev) {
		dev_err(dev, "unable to find platform device for %pOF\n", node);
		goto out;
	}

	priv = dev_get_drvdata(dev);

	priv->cpsw_phy_sel(priv, phy_mode, slave);

	put_device(dev);
out:
	of_node_put(node);
}

__attribute__((used)) static int cpsw_phy_sel_probe(struct platform_device *pdev)
{
	struct resource	*res;
	const struct of_device_id *of_id;
	struct cpsw_phy_sel_priv *priv;

	of_id = of_match_node(cpsw_phy_sel_id_table, pdev->dev.of_node);
	if (!of_id)
		return -EINVAL;

	priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
	if (!priv) {
		dev_err(&pdev->dev, "unable to alloc memory for cpsw phy sel\n");
		return -ENOMEM;
	}

	priv->dev = &pdev->dev;
	priv->cpsw_phy_sel = of_id->data;

	res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "gmii-sel");
	priv->gmii_sel = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(priv->gmii_sel))
		return PTR_ERR(priv->gmii_sel);

	if (of_find_property(pdev->dev.of_node, "rmii-clock-ext", NULL))
		priv->rmii_clock_external = true;

	dev_set_drvdata(&pdev->dev, priv);

	return 0;
}

