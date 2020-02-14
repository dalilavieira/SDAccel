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
struct stmmac_resources {int /*<<< orphan*/  mac; } ;
struct stmmac_priv {TYPE_1__* plat; } ;
struct TYPE_8__ {int /*<<< orphan*/  of_node; } ;
struct platform_device {TYPE_2__ dev; } ;
struct plat_stmmacenet_data {int (* init ) (struct platform_device*,void*) ;void (* exit ) (struct platform_device*,void*) ;struct oxnas_dwmac* bsp_priv; } ;
struct oxnas_dwmac {struct plat_stmmacenet_data* clk; struct plat_stmmacenet_data* regmap; TYPE_2__* dev; } ;
struct net_device {int dummy; } ;
struct device {int dummy; } ;
struct TYPE_7__ {void* bsp_priv; } ;

/* Variables and functions */
 unsigned int BIT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DWMAC_AUTO_TX_SOURCE ; 
 int /*<<< orphan*/  DWMAC_CKEN_GTX ; 
 int /*<<< orphan*/  DWMAC_CKEN_RXN_OUT ; 
 int /*<<< orphan*/  DWMAC_CKEN_RX_IN ; 
 int /*<<< orphan*/  DWMAC_CKEN_RX_OUT ; 
 int /*<<< orphan*/  DWMAC_CKEN_TXN_OUT ; 
 int /*<<< orphan*/  DWMAC_CKEN_TX_IN ; 
 int /*<<< orphan*/  DWMAC_CKEN_TX_OUT ; 
 unsigned int DWMAC_RXN_VARDELAY (int) ; 
 unsigned int DWMAC_RX_VARDELAY (int) ; 
 int /*<<< orphan*/  DWMAC_SIMPLE_MUX ; 
 unsigned int DWMAC_TXN_VARDELAY (int) ; 
 unsigned int DWMAC_TX_VARDELAY (int) ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct plat_stmmacenet_data*) ; 
 int /*<<< orphan*/  OXNAS_DWMAC_CTRL_REGOFFSET ; 
 int /*<<< orphan*/  OXNAS_DWMAC_DELAY_REGOFFSET ; 
 int PTR_ERR (struct plat_stmmacenet_data*) ; 
 int /*<<< orphan*/  clk_disable_unprepare (struct plat_stmmacenet_data*) ; 
 int clk_prepare_enable (struct plat_stmmacenet_data*) ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*) ; 
 struct net_device* dev_get_drvdata (struct device*) ; 
 int device_reset (TYPE_2__*) ; 
 struct plat_stmmacenet_data* devm_clk_get (TYPE_2__*,char*) ; 
 struct oxnas_dwmac* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 struct stmmac_priv* netdev_priv (struct net_device*) ; 
 int regmap_read (struct plat_stmmacenet_data*,int /*<<< orphan*/ ,unsigned int*) ; 
 int /*<<< orphan*/  regmap_write (struct plat_stmmacenet_data*,int /*<<< orphan*/ ,unsigned int) ; 
 int stmmac_dvr_probe (TYPE_2__*,struct plat_stmmacenet_data*,struct stmmac_resources*) ; 
 int stmmac_get_platform_resources (struct platform_device*,struct stmmac_resources*) ; 
 struct plat_stmmacenet_data* stmmac_probe_config_dt (struct platform_device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stmmac_remove_config_dt (struct platform_device*,struct plat_stmmacenet_data*) ; 
 struct plat_stmmacenet_data* syscon_regmap_lookup_by_phandle (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static inline void *get_stmmac_bsp_priv(struct device *dev)
{
	struct net_device *ndev = dev_get_drvdata(dev);
	struct stmmac_priv *priv = netdev_priv(ndev);

	return priv->plat->bsp_priv;
}

__attribute__((used)) static int oxnas_dwmac_init(struct platform_device *pdev, void *priv)
{
	struct oxnas_dwmac *dwmac = priv;
	unsigned int value;
	int ret;

	/* Reset HW here before changing the glue configuration */
	ret = device_reset(dwmac->dev);
	if (ret)
		return ret;

	ret = clk_prepare_enable(dwmac->clk);
	if (ret)
		return ret;

	ret = regmap_read(dwmac->regmap, OXNAS_DWMAC_CTRL_REGOFFSET, &value);
	if (ret < 0) {
		clk_disable_unprepare(dwmac->clk);
		return ret;
	}

	/* Enable GMII_GTXCLK to follow GMII_REFCLK, required for gigabit PHY */
	value |= BIT(DWMAC_CKEN_GTX)		|
		 /* Use simple mux for 25/125 Mhz clock switching */
		 BIT(DWMAC_SIMPLE_MUX)		|
		 /* set auto switch tx clock source */
		 BIT(DWMAC_AUTO_TX_SOURCE)	|
		 /* enable tx & rx vardelay */
		 BIT(DWMAC_CKEN_TX_OUT)		|
		 BIT(DWMAC_CKEN_TXN_OUT)	|
		 BIT(DWMAC_CKEN_TX_IN)		|
		 BIT(DWMAC_CKEN_RX_OUT)		|
		 BIT(DWMAC_CKEN_RXN_OUT)	|
		 BIT(DWMAC_CKEN_RX_IN);
	regmap_write(dwmac->regmap, OXNAS_DWMAC_CTRL_REGOFFSET, value);

	/* set tx & rx vardelay */
	value = DWMAC_TX_VARDELAY(4)	|
		DWMAC_TXN_VARDELAY(2)	|
		DWMAC_RX_VARDELAY(10)	|
		DWMAC_RXN_VARDELAY(8);
	regmap_write(dwmac->regmap, OXNAS_DWMAC_DELAY_REGOFFSET, value);

	return 0;
}

__attribute__((used)) static void oxnas_dwmac_exit(struct platform_device *pdev, void *priv)
{
	struct oxnas_dwmac *dwmac = priv;

	clk_disable_unprepare(dwmac->clk);
}

__attribute__((used)) static int oxnas_dwmac_probe(struct platform_device *pdev)
{
	struct plat_stmmacenet_data *plat_dat;
	struct stmmac_resources stmmac_res;
	struct oxnas_dwmac *dwmac;
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

	dwmac->dev = &pdev->dev;
	plat_dat->bsp_priv = dwmac;
	plat_dat->init = oxnas_dwmac_init;
	plat_dat->exit = oxnas_dwmac_exit;

	dwmac->regmap = syscon_regmap_lookup_by_phandle(pdev->dev.of_node,
							"oxsemi,sys-ctrl");
	if (IS_ERR(dwmac->regmap)) {
		dev_err(&pdev->dev, "failed to have sysctrl regmap\n");
		ret = PTR_ERR(dwmac->regmap);
		goto err_remove_config_dt;
	}

	dwmac->clk = devm_clk_get(&pdev->dev, "gmac");
	if (IS_ERR(dwmac->clk)) {
		ret = PTR_ERR(dwmac->clk);
		goto err_remove_config_dt;
	}

	ret = oxnas_dwmac_init(pdev, plat_dat->bsp_priv);
	if (ret)
		goto err_remove_config_dt;

	ret = stmmac_dvr_probe(&pdev->dev, plat_dat, &stmmac_res);
	if (ret)
		goto err_dwmac_exit;


	return 0;

err_dwmac_exit:
	oxnas_dwmac_exit(pdev, plat_dat->bsp_priv);
err_remove_config_dt:
	stmmac_remove_config_dt(pdev, plat_dat);

	return ret;
}

