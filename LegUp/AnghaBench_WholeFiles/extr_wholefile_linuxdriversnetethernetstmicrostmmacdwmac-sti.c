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
typedef  scalar_t__ u32 ;
struct stmmac_resources {int /*<<< orphan*/  mac; } ;
struct stmmac_priv {TYPE_1__* plat; } ;
struct sti_dwmac_of_data {int /*<<< orphan*/  (* fix_retime_src ) (struct sti_dwmac*,scalar_t__) ;} ;
struct sti_dwmac {scalar_t__ tx_retime_src; scalar_t__ ctrl_reg; scalar_t__ interface; struct regmap* clk; int /*<<< orphan*/  (* fix_retime_src ) (struct sti_dwmac*,scalar_t__) ;scalar_t__ speed; void* ext_phyclk; void* gmac_en; struct regmap* regmap; int /*<<< orphan*/  clk_sel_reg; } ;
struct resource {int /*<<< orphan*/  start; } ;
struct regmap {int /*<<< orphan*/  (* fix_mac_speed ) (struct sti_dwmac*,scalar_t__) ;struct sti_dwmac* bsp_priv; } ;
struct device {struct device_node* of_node; } ;
struct platform_device {struct device dev; } ;
struct plat_stmmacenet_data {int /*<<< orphan*/  (* fix_mac_speed ) (struct sti_dwmac*,scalar_t__) ;struct sti_dwmac* bsp_priv; } ;
struct net_device {int dummy; } ;
struct device_node {int dummy; } ;
struct TYPE_2__ {void* bsp_priv; } ;

/* Variables and functions */
 scalar_t__ DWMAC_125MHZ ; 
 scalar_t__ DWMAC_25MHZ ; 
 scalar_t__ DWMAC_2_5MHZ ; 
 scalar_t__ DWMAC_50MHZ ; 
 int EINVAL ; 
 scalar_t__ EN ; 
 scalar_t__ ENMII ; 
 int /*<<< orphan*/  ENMII_MASK ; 
 int ENOMEM ; 
 int /*<<< orphan*/  ENXIO ; 
 int /*<<< orphan*/  EN_MASK ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (struct regmap*) ; 
 scalar_t__ IS_PHY_IF_MODE_GBIT (int) ; 
 scalar_t__ IS_PHY_IF_MODE_RGMII (scalar_t__) ; 
 int /*<<< orphan*/  MII_PHY_SEL_MASK ; 
 scalar_t__ PHY_INTERFACE_MODE_MII ; 
 int PHY_INTERFACE_MODE_REVMII ; 
 scalar_t__ PHY_INTERFACE_MODE_RMII ; 
 int PTR_ERR (struct regmap*) ; 
 scalar_t__ SPEED_10 ; 
 scalar_t__ SPEED_100 ; 
 scalar_t__ SPEED_1000 ; 
 scalar_t__ STID127_ETH_SEL_INTERNAL_NOTEXT_PHYCLK ; 
 scalar_t__ STID127_ETH_SEL_INTERNAL_NOTEXT_TXCLK ; 
 int /*<<< orphan*/  STID127_RETIME_SRC_MASK ; 
 int /*<<< orphan*/  STIH4XX_RETIME_SRC_MASK ; 
 scalar_t__ TX_RETIME_SRC_CLKGEN ; 
 scalar_t__ TX_RETIME_SRC_CLK_125 ; 
 scalar_t__ TX_RETIME_SRC_NA ; 
 scalar_t__ TX_RETIME_SRC_PHYCLK ; 
 scalar_t__ TX_RETIME_SRC_TXCLK ; 
 int /*<<< orphan*/  clk_disable_unprepare (struct regmap*) ; 
 int clk_prepare_enable (struct regmap*) ; 
 int /*<<< orphan*/  clk_set_rate (struct regmap*,scalar_t__) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct net_device* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*) ; 
 struct regmap* devm_clk_get (struct device*,char*) ; 
 struct sti_dwmac* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 struct stmmac_priv* netdev_priv (struct net_device*) ; 
 struct sti_dwmac_of_data* of_device_get_match_data (struct device*) ; 
 int of_get_phy_mode (struct device_node*) ; 
 void* of_property_read_bool (struct device_node*,char*) ; 
 int of_property_read_string (struct device_node*,char*,char const**) ; 
 int of_property_read_u32_index (struct device_node*,char*,int,scalar_t__*) ; 
 scalar_t__* phy_intf_sels ; 
 struct resource* platform_get_resource_byname (struct platform_device*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  regmap_update_bits (struct regmap*,scalar_t__,int /*<<< orphan*/ ,scalar_t__) ; 
 scalar_t__* stih4xx_tx_retime_val ; 
 int stmmac_dvr_probe (struct device*,struct regmap*,struct stmmac_resources*) ; 
 int stmmac_dvr_remove (struct device*) ; 
 int stmmac_get_platform_resources (struct platform_device*,struct stmmac_resources*) ; 
 struct regmap* stmmac_probe_config_dt (struct platform_device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stmmac_remove_config_dt (struct platform_device*,struct regmap*) ; 
 int /*<<< orphan*/  strcasecmp (char const*,char*) ; 
 int /*<<< orphan*/  stub1 (struct sti_dwmac*,scalar_t__) ; 
 struct regmap* syscon_regmap_lookup_by_phandle (struct device_node*,char*) ; 

__attribute__((used)) static inline void *get_stmmac_bsp_priv(struct device *dev)
{
	struct net_device *ndev = dev_get_drvdata(dev);
	struct stmmac_priv *priv = netdev_priv(ndev);

	return priv->plat->bsp_priv;
}

__attribute__((used)) static void stih4xx_fix_retime_src(void *priv, u32 spd)
{
	struct sti_dwmac *dwmac = priv;
	u32 src = dwmac->tx_retime_src;
	u32 reg = dwmac->ctrl_reg;
	u32 freq = 0;

	if (dwmac->interface == PHY_INTERFACE_MODE_MII) {
		src = TX_RETIME_SRC_TXCLK;
	} else if (dwmac->interface == PHY_INTERFACE_MODE_RMII) {
		if (dwmac->ext_phyclk) {
			src = TX_RETIME_SRC_PHYCLK;
		} else {
			src = TX_RETIME_SRC_CLKGEN;
			freq = DWMAC_50MHZ;
		}
	} else if (IS_PHY_IF_MODE_RGMII(dwmac->interface)) {
		/* On GiGa clk source can be either ext or from clkgen */
		if (spd == SPEED_1000) {
			freq = DWMAC_125MHZ;
		} else {
			/* Switch to clkgen for these speeds */
			src = TX_RETIME_SRC_CLKGEN;
			if (spd == SPEED_100)
				freq = DWMAC_25MHZ;
			else if (spd == SPEED_10)
				freq = DWMAC_2_5MHZ;
		}
	}

	if (src == TX_RETIME_SRC_CLKGEN && freq)
		clk_set_rate(dwmac->clk, freq);

	regmap_update_bits(dwmac->regmap, reg, STIH4XX_RETIME_SRC_MASK,
			   stih4xx_tx_retime_val[src]);
}

__attribute__((used)) static void stid127_fix_retime_src(void *priv, u32 spd)
{
	struct sti_dwmac *dwmac = priv;
	u32 reg = dwmac->ctrl_reg;
	u32 freq = 0;
	u32 val = 0;

	if (dwmac->interface == PHY_INTERFACE_MODE_MII) {
		val = STID127_ETH_SEL_INTERNAL_NOTEXT_TXCLK;
	} else if (dwmac->interface == PHY_INTERFACE_MODE_RMII) {
		if (!dwmac->ext_phyclk) {
			val = STID127_ETH_SEL_INTERNAL_NOTEXT_PHYCLK;
			freq = DWMAC_50MHZ;
		}
	} else if (IS_PHY_IF_MODE_RGMII(dwmac->interface)) {
		val = STID127_ETH_SEL_INTERNAL_NOTEXT_TXCLK;
		if (spd == SPEED_1000)
			freq = DWMAC_125MHZ;
		else if (spd == SPEED_100)
			freq = DWMAC_25MHZ;
		else if (spd == SPEED_10)
			freq = DWMAC_2_5MHZ;
	}

	if (freq)
		clk_set_rate(dwmac->clk, freq);

	regmap_update_bits(dwmac->regmap, reg, STID127_RETIME_SRC_MASK, val);
}

__attribute__((used)) static int sti_dwmac_set_mode(struct sti_dwmac *dwmac)
{
	struct regmap *regmap = dwmac->regmap;
	int iface = dwmac->interface;
	u32 reg = dwmac->ctrl_reg;
	u32 val;

	if (dwmac->gmac_en)
		regmap_update_bits(regmap, reg, EN_MASK, EN);

	regmap_update_bits(regmap, reg, MII_PHY_SEL_MASK, phy_intf_sels[iface]);

	val = (iface == PHY_INTERFACE_MODE_REVMII) ? 0 : ENMII;
	regmap_update_bits(regmap, reg, ENMII_MASK, val);

	dwmac->fix_retime_src(dwmac, dwmac->speed);

	return 0;
}

__attribute__((used)) static int sti_dwmac_parse_data(struct sti_dwmac *dwmac,
				struct platform_device *pdev)
{
	struct resource *res;
	struct device *dev = &pdev->dev;
	struct device_node *np = dev->of_node;
	struct regmap *regmap;
	int err;

	/* clk selection from extra syscfg register */
	dwmac->clk_sel_reg = -ENXIO;
	res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "sti-clkconf");
	if (res)
		dwmac->clk_sel_reg = res->start;

	regmap = syscon_regmap_lookup_by_phandle(np, "st,syscon");
	if (IS_ERR(regmap))
		return PTR_ERR(regmap);

	err = of_property_read_u32_index(np, "st,syscon", 1, &dwmac->ctrl_reg);
	if (err) {
		dev_err(dev, "Can't get sysconfig ctrl offset (%d)\n", err);
		return err;
	}

	dwmac->interface = of_get_phy_mode(np);
	dwmac->regmap = regmap;
	dwmac->gmac_en = of_property_read_bool(np, "st,gmac_en");
	dwmac->ext_phyclk = of_property_read_bool(np, "st,ext-phyclk");
	dwmac->tx_retime_src = TX_RETIME_SRC_NA;
	dwmac->speed = SPEED_100;

	if (IS_PHY_IF_MODE_GBIT(dwmac->interface)) {
		const char *rs;

		dwmac->tx_retime_src = TX_RETIME_SRC_CLKGEN;

		err = of_property_read_string(np, "st,tx-retime-src", &rs);
		if (err < 0) {
			dev_warn(dev, "Use internal clock source\n");
		} else {
			if (!strcasecmp(rs, "clk_125"))
				dwmac->tx_retime_src = TX_RETIME_SRC_CLK_125;
			else if (!strcasecmp(rs, "txclk"))
				dwmac->tx_retime_src = TX_RETIME_SRC_TXCLK;
		}
		dwmac->speed = SPEED_1000;
	}

	dwmac->clk = devm_clk_get(dev, "sti-ethclk");
	if (IS_ERR(dwmac->clk)) {
		dev_warn(dev, "No phy clock provided...\n");
		dwmac->clk = NULL;
	}

	return 0;
}

__attribute__((used)) static int sti_dwmac_probe(struct platform_device *pdev)
{
	struct plat_stmmacenet_data *plat_dat;
	const struct sti_dwmac_of_data *data;
	struct stmmac_resources stmmac_res;
	struct sti_dwmac *dwmac;
	int ret;

	data = of_device_get_match_data(&pdev->dev);
	if (!data) {
		dev_err(&pdev->dev, "No OF match data provided\n");
		return -EINVAL;
	}

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

	ret = sti_dwmac_parse_data(dwmac, pdev);
	if (ret) {
		dev_err(&pdev->dev, "Unable to parse OF data\n");
		goto err_remove_config_dt;
	}

	dwmac->fix_retime_src = data->fix_retime_src;

	plat_dat->bsp_priv = dwmac;
	plat_dat->fix_mac_speed = data->fix_retime_src;

	ret = clk_prepare_enable(dwmac->clk);
	if (ret)
		goto err_remove_config_dt;

	ret = sti_dwmac_set_mode(dwmac);
	if (ret)
		goto disable_clk;

	ret = stmmac_dvr_probe(&pdev->dev, plat_dat, &stmmac_res);
	if (ret)
		goto disable_clk;

	return 0;

disable_clk:
	clk_disable_unprepare(dwmac->clk);
err_remove_config_dt:
	stmmac_remove_config_dt(pdev, plat_dat);

	return ret;
}

__attribute__((used)) static int sti_dwmac_remove(struct platform_device *pdev)
{
	struct sti_dwmac *dwmac = get_stmmac_bsp_priv(&pdev->dev);
	int ret = stmmac_dvr_remove(&pdev->dev);

	clk_disable_unprepare(dwmac->clk);

	return ret;
}

