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
struct device {int /*<<< orphan*/  of_node; } ;
struct platform_device {struct device dev; } ;
struct net_device {int dummy; } ;
struct arc_emac_priv {int /*<<< orphan*/  clk; int /*<<< orphan*/  drv_version; int /*<<< orphan*/  drv_name; scalar_t__ regs; } ;

/* Variables and functions */
 int /*<<< orphan*/  DRV_NAME ; 
 int /*<<< orphan*/  DRV_VERSION ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PHY_INTERFACE_MODE_MII ; 
 int /*<<< orphan*/  SET_NETDEV_DEV (struct net_device*,struct device*) ; 
 struct net_device* alloc_etherdev (int) ; 
 int arc_emac_probe (struct net_device*,int) ; 
 int arc_emac_remove (struct net_device*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 int /*<<< orphan*/  devm_clk_get (struct device*,char*) ; 
 int /*<<< orphan*/  free_netdev (struct net_device*) ; 
 unsigned int ioread32 (scalar_t__) ; 
 int /*<<< orphan*/  iowrite32 (int,scalar_t__) ; 
 struct arc_emac_priv* netdev_priv (struct net_device*) ; 
 int of_get_phy_mode (int /*<<< orphan*/ ) ; 
 struct net_device* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct net_device*) ; 

__attribute__((used)) static inline void arc_reg_set(struct arc_emac_priv *priv, int reg, int value)
{
	iowrite32(value, priv->regs + reg * sizeof(int));
}

__attribute__((used)) static inline unsigned int arc_reg_get(struct arc_emac_priv *priv, int reg)
{
	return ioread32(priv->regs + reg * sizeof(int));
}

__attribute__((used)) static inline void arc_reg_or(struct arc_emac_priv *priv, int reg, int mask)
{
	unsigned int value = arc_reg_get(priv, reg);

	arc_reg_set(priv, reg, value | mask);
}

__attribute__((used)) static inline void arc_reg_clr(struct arc_emac_priv *priv, int reg, int mask)
{
	unsigned int value = arc_reg_get(priv, reg);

	arc_reg_set(priv, reg, value & ~mask);
}

__attribute__((used)) static int emac_arc_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct net_device *ndev;
	struct arc_emac_priv *priv;
	int interface, err;

	if (!dev->of_node)
		return -ENODEV;

	ndev = alloc_etherdev(sizeof(struct arc_emac_priv));
	if (!ndev)
		return -ENOMEM;
	platform_set_drvdata(pdev, ndev);
	SET_NETDEV_DEV(ndev, dev);

	priv = netdev_priv(ndev);
	priv->drv_name = DRV_NAME;
	priv->drv_version = DRV_VERSION;

	interface = of_get_phy_mode(dev->of_node);
	if (interface < 0)
		interface = PHY_INTERFACE_MODE_MII;

	priv->clk = devm_clk_get(dev, "hclk");
	if (IS_ERR(priv->clk)) {
		dev_err(dev, "failed to retrieve host clock from device tree\n");
		err = -EINVAL;
		goto out_netdev;
	}

	err = arc_emac_probe(ndev, interface);
out_netdev:
	if (err)
		free_netdev(ndev);
	return err;
}

__attribute__((used)) static int emac_arc_remove(struct platform_device *pdev)
{
	struct net_device *ndev = platform_get_drvdata(pdev);
	int err;

	err = arc_emac_remove(ndev);
	free_netdev(ndev);
	return err;
}

