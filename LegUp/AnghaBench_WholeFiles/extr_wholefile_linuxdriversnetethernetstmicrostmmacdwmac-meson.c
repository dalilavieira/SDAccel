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
struct stmmac_resources {int /*<<< orphan*/  mac; } ;
struct stmmac_priv {TYPE_1__* plat; } ;
struct resource {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct plat_stmmacenet_data {void (* fix_mac_speed ) (void*,unsigned int) ;struct meson_dwmac* bsp_priv; } ;
struct net_device {int dummy; } ;
struct meson_dwmac {struct plat_stmmacenet_data* reg; } ;
struct device {int dummy; } ;
struct TYPE_2__ {void* bsp_priv; } ;

/* Variables and functions */
 int ENOMEM ; 
 unsigned int ETHMAC_SPEED_100 ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (struct plat_stmmacenet_data*) ; 
 int PTR_ERR (struct plat_stmmacenet_data*) ; 
#define  SPEED_10 129 
#define  SPEED_100 128 
 struct net_device* dev_get_drvdata (struct device*) ; 
 struct plat_stmmacenet_data* devm_ioremap_resource (int /*<<< orphan*/ *,struct resource*) ; 
 struct meson_dwmac* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 struct stmmac_priv* netdev_priv (struct net_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int) ; 
 unsigned int readl (struct plat_stmmacenet_data*) ; 
 int stmmac_dvr_probe (int /*<<< orphan*/ *,struct plat_stmmacenet_data*,struct stmmac_resources*) ; 
 int stmmac_get_platform_resources (struct platform_device*,struct stmmac_resources*) ; 
 struct plat_stmmacenet_data* stmmac_probe_config_dt (struct platform_device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stmmac_remove_config_dt (struct platform_device*,struct plat_stmmacenet_data*) ; 
 int /*<<< orphan*/  writel (unsigned int,struct plat_stmmacenet_data*) ; 

__attribute__((used)) static inline void *get_stmmac_bsp_priv(struct device *dev)
{
	struct net_device *ndev = dev_get_drvdata(dev);
	struct stmmac_priv *priv = netdev_priv(ndev);

	return priv->plat->bsp_priv;
}

__attribute__((used)) static void meson6_dwmac_fix_mac_speed(void *priv, unsigned int speed)
{
	struct meson_dwmac *dwmac = priv;
	unsigned int val;

	val = readl(dwmac->reg);

	switch (speed) {
	case SPEED_10:
		val &= ~ETHMAC_SPEED_100;
		break;
	case SPEED_100:
		val |= ETHMAC_SPEED_100;
		break;
	}

	writel(val, dwmac->reg);
}

__attribute__((used)) static int meson6_dwmac_probe(struct platform_device *pdev)
{
	struct plat_stmmacenet_data *plat_dat;
	struct stmmac_resources stmmac_res;
	struct meson_dwmac *dwmac;
	struct resource *res;
	int ret;

	ret = stmmac_get_platform_resources(pdev, &stmmac_res);
	if (ret)
		return ret;

	plat_dat = stmmac_probe_config_dt(pdev, &stmmac_res.mac);
	if (IS_ERR(plat_dat))
		return PTR_ERR(plat_dat);

	dwmac = devm_kzalloc(&pdev->dev, sizeof(*dwmac), GFP_KERNEL);
	if (!dwmac) {
		ret = -ENOMEM;
		goto err_remove_config_dt;
	}

	res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
	dwmac->reg = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(dwmac->reg)) {
		ret = PTR_ERR(dwmac->reg);
		goto err_remove_config_dt;
	}

	plat_dat->bsp_priv = dwmac;
	plat_dat->fix_mac_speed = meson6_dwmac_fix_mac_speed;

	ret = stmmac_dvr_probe(&pdev->dev, plat_dat, &stmmac_res);
	if (ret)
		goto err_remove_config_dt;

	return 0;

err_remove_config_dt:
	stmmac_remove_config_dt(pdev, plat_dat);

	return ret;
}

