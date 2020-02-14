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
typedef  int uint32_t ;
struct stmmac_resources {int /*<<< orphan*/  mac; } ;
struct stmmac_priv {TYPE_1__* plat; } ;
struct device {int /*<<< orphan*/  of_node; } ;
struct platform_device {struct device dev; } ;
struct plat_stmmacenet_data {int has_gmac; void (* fix_mac_speed ) (void*,unsigned int) ;struct ipq806x_gmac* bsp_priv; } ;
struct net_device {int dummy; } ;
struct ipq806x_gmac {int phy_mode; int id; struct plat_stmmacenet_data* qsgmii_csr; struct plat_stmmacenet_data* nss_common; struct platform_device* pdev; struct plat_stmmacenet_data* core_clk; } ;
struct TYPE_2__ {void* bsp_priv; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct plat_stmmacenet_data*) ; 
 int /*<<< orphan*/  NSS_COMMON_CLK_DIV0 ; 
 int NSS_COMMON_CLK_DIV_MASK ; 
 int NSS_COMMON_CLK_DIV_OFFSET (int) ; 
 int NSS_COMMON_CLK_DIV_RGMII_10 ; 
 int NSS_COMMON_CLK_DIV_RGMII_100 ; 
 int NSS_COMMON_CLK_DIV_RGMII_1000 ; 
 int NSS_COMMON_CLK_DIV_SGMII_10 ; 
 int NSS_COMMON_CLK_DIV_SGMII_100 ; 
 int NSS_COMMON_CLK_DIV_SGMII_1000 ; 
 int /*<<< orphan*/  NSS_COMMON_CLK_GATE ; 
 int NSS_COMMON_CLK_GATE_GMII_RX_EN (int) ; 
 int NSS_COMMON_CLK_GATE_GMII_TX_EN (int) ; 
 int NSS_COMMON_CLK_GATE_PTP_EN (int) ; 
 int NSS_COMMON_CLK_GATE_RGMII_RX_EN (int) ; 
 int NSS_COMMON_CLK_GATE_RGMII_TX_EN (int) ; 
 int /*<<< orphan*/  NSS_COMMON_CLK_SRC_CTRL ; 
 int NSS_COMMON_CLK_SRC_CTRL_OFFSET (int) ; 
 int NSS_COMMON_CLK_SRC_CTRL_RGMII (int) ; 
 int NSS_COMMON_CLK_SRC_CTRL_SGMII (int) ; 
 int /*<<< orphan*/  NSS_COMMON_GMAC_CTL (int) ; 
 int NSS_COMMON_GMAC_CTL_CSYS_REQ ; 
 int NSS_COMMON_GMAC_CTL_IFG_LIMIT_OFFSET ; 
 int NSS_COMMON_GMAC_CTL_IFG_OFFSET ; 
 int NSS_COMMON_GMAC_CTL_PHY_IFACE_SEL ; 
#define  PHY_INTERFACE_MODE_RGMII 132 
#define  PHY_INTERFACE_MODE_SGMII 131 
 int PTR_ERR (struct plat_stmmacenet_data*) ; 
 int PTR_ERR_OR_ZERO (struct plat_stmmacenet_data*) ; 
 int /*<<< orphan*/  QSGMII_PCS_CAL_LCKDT_CTL ; 
 int QSGMII_PCS_CAL_LCKDT_CTL_RST ; 
 int QSGMII_PHY_CDR_EN ; 
 int QSGMII_PHY_CDR_PI_SLEW_OFFSET ; 
 int QSGMII_PHY_PHASE_LOOP_GAIN_OFFSET ; 
 int QSGMII_PHY_QSGMII_EN ; 
 int QSGMII_PHY_RX_DC_BIAS_OFFSET ; 
 int QSGMII_PHY_RX_FRONT_EN ; 
 int QSGMII_PHY_RX_INPUT_EQU_OFFSET ; 
 int QSGMII_PHY_RX_SIGNAL_DETECT_EN ; 
 int /*<<< orphan*/  QSGMII_PHY_SGMII_CTL (int) ; 
 int QSGMII_PHY_TX_DRIVER_EN ; 
 int QSGMII_PHY_TX_DRV_AMP_OFFSET ; 
#define  SPEED_10 130 
#define  SPEED_100 129 
#define  SPEED_1000 128 
 int /*<<< orphan*/  clk_set_rate (struct plat_stmmacenet_data*,int) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct net_device* dev_get_drvdata (struct device*) ; 
 struct plat_stmmacenet_data* devm_clk_get (struct device*,char*) ; 
 struct ipq806x_gmac* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 struct stmmac_priv* netdev_priv (struct net_device*) ; 
 int of_get_phy_mode (int /*<<< orphan*/ ) ; 
 scalar_t__ of_property_read_u32 (int /*<<< orphan*/ ,char*,int*) ; 
 unsigned int phy_modes (int) ; 
 int /*<<< orphan*/  regmap_read (struct plat_stmmacenet_data*,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  regmap_write (struct plat_stmmacenet_data*,int /*<<< orphan*/ ,int) ; 
 int stmmac_dvr_probe (struct device*,struct plat_stmmacenet_data*,struct stmmac_resources*) ; 
 int stmmac_get_platform_resources (struct platform_device*,struct stmmac_resources*) ; 
 struct plat_stmmacenet_data* stmmac_probe_config_dt (struct platform_device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stmmac_remove_config_dt (struct platform_device*,struct plat_stmmacenet_data*) ; 
 void* syscon_regmap_lookup_by_phandle (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static inline void *get_stmmac_bsp_priv(struct device *dev)
{
	struct net_device *ndev = dev_get_drvdata(dev);
	struct stmmac_priv *priv = netdev_priv(ndev);

	return priv->plat->bsp_priv;
}

__attribute__((used)) static int get_clk_div_sgmii(struct ipq806x_gmac *gmac, unsigned int speed)
{
	struct device *dev = &gmac->pdev->dev;
	int div;

	switch (speed) {
	case SPEED_1000:
		div = NSS_COMMON_CLK_DIV_SGMII_1000;
		break;

	case SPEED_100:
		div = NSS_COMMON_CLK_DIV_SGMII_100;
		break;

	case SPEED_10:
		div = NSS_COMMON_CLK_DIV_SGMII_10;
		break;

	default:
		dev_err(dev, "Speed %dMbps not supported in SGMII\n", speed);
		return -EINVAL;
	}

	return div;
}

__attribute__((used)) static int get_clk_div_rgmii(struct ipq806x_gmac *gmac, unsigned int speed)
{
	struct device *dev = &gmac->pdev->dev;
	int div;

	switch (speed) {
	case SPEED_1000:
		div = NSS_COMMON_CLK_DIV_RGMII_1000;
		break;

	case SPEED_100:
		div = NSS_COMMON_CLK_DIV_RGMII_100;
		break;

	case SPEED_10:
		div = NSS_COMMON_CLK_DIV_RGMII_10;
		break;

	default:
		dev_err(dev, "Speed %dMbps not supported in RGMII\n", speed);
		return -EINVAL;
	}

	return div;
}

__attribute__((used)) static int ipq806x_gmac_set_speed(struct ipq806x_gmac *gmac, unsigned int speed)
{
	uint32_t clk_bits, val;
	int div;

	switch (gmac->phy_mode) {
	case PHY_INTERFACE_MODE_RGMII:
		div = get_clk_div_rgmii(gmac, speed);
		clk_bits = NSS_COMMON_CLK_GATE_RGMII_RX_EN(gmac->id) |
			   NSS_COMMON_CLK_GATE_RGMII_TX_EN(gmac->id);
		break;

	case PHY_INTERFACE_MODE_SGMII:
		div = get_clk_div_sgmii(gmac, speed);
		clk_bits = NSS_COMMON_CLK_GATE_GMII_RX_EN(gmac->id) |
			   NSS_COMMON_CLK_GATE_GMII_TX_EN(gmac->id);
		break;

	default:
		dev_err(&gmac->pdev->dev, "Unsupported PHY mode: \"%s\"\n",
			phy_modes(gmac->phy_mode));
		return -EINVAL;
	}

	/* Disable the clocks */
	regmap_read(gmac->nss_common, NSS_COMMON_CLK_GATE, &val);
	val &= ~clk_bits;
	regmap_write(gmac->nss_common, NSS_COMMON_CLK_GATE, val);

	/* Set the divider */
	regmap_read(gmac->nss_common, NSS_COMMON_CLK_DIV0, &val);
	val &= ~(NSS_COMMON_CLK_DIV_MASK
		 << NSS_COMMON_CLK_DIV_OFFSET(gmac->id));
	val |= div << NSS_COMMON_CLK_DIV_OFFSET(gmac->id);
	regmap_write(gmac->nss_common, NSS_COMMON_CLK_DIV0, val);

	/* Enable the clock back */
	regmap_read(gmac->nss_common, NSS_COMMON_CLK_GATE, &val);
	val |= clk_bits;
	regmap_write(gmac->nss_common, NSS_COMMON_CLK_GATE, val);

	return 0;
}

__attribute__((used)) static int ipq806x_gmac_of_parse(struct ipq806x_gmac *gmac)
{
	struct device *dev = &gmac->pdev->dev;

	gmac->phy_mode = of_get_phy_mode(dev->of_node);
	if (gmac->phy_mode < 0) {
		dev_err(dev, "missing phy mode property\n");
		return -EINVAL;
	}

	if (of_property_read_u32(dev->of_node, "qcom,id", &gmac->id) < 0) {
		dev_err(dev, "missing qcom id property\n");
		return -EINVAL;
	}

	/* The GMACs are called 1 to 4 in the documentation, but to simplify the
	 * code and keep it consistent with the Linux convention, we'll number
	 * them from 0 to 3 here.
	 */
	if (gmac->id > 3) {
		dev_err(dev, "invalid gmac id\n");
		return -EINVAL;
	}

	gmac->core_clk = devm_clk_get(dev, "stmmaceth");
	if (IS_ERR(gmac->core_clk)) {
		dev_err(dev, "missing stmmaceth clk property\n");
		return PTR_ERR(gmac->core_clk);
	}
	clk_set_rate(gmac->core_clk, 266000000);

	/* Setup the register map for the nss common registers */
	gmac->nss_common = syscon_regmap_lookup_by_phandle(dev->of_node,
							   "qcom,nss-common");
	if (IS_ERR(gmac->nss_common)) {
		dev_err(dev, "missing nss-common node\n");
		return PTR_ERR(gmac->nss_common);
	}

	/* Setup the register map for the qsgmii csr registers */
	gmac->qsgmii_csr = syscon_regmap_lookup_by_phandle(dev->of_node,
							   "qcom,qsgmii-csr");
	if (IS_ERR(gmac->qsgmii_csr))
		dev_err(dev, "missing qsgmii-csr node\n");

	return PTR_ERR_OR_ZERO(gmac->qsgmii_csr);
}

__attribute__((used)) static void ipq806x_gmac_fix_mac_speed(void *priv, unsigned int speed)
{
	struct ipq806x_gmac *gmac = priv;

	ipq806x_gmac_set_speed(gmac, speed);
}

__attribute__((used)) static int ipq806x_gmac_probe(struct platform_device *pdev)
{
	struct plat_stmmacenet_data *plat_dat;
	struct stmmac_resources stmmac_res;
	struct device *dev = &pdev->dev;
	struct ipq806x_gmac *gmac;
	int val;
	int err;

	val = stmmac_get_platform_resources(pdev, &stmmac_res);
	if (val)
		return val;

	plat_dat = stmmac_probe_config_dt(pdev, &stmmac_res.mac);
	if (IS_ERR(plat_dat))
		return PTR_ERR(plat_dat);

	gmac = devm_kzalloc(dev, sizeof(*gmac), GFP_KERNEL);
	if (!gmac) {
		err = -ENOMEM;
		goto err_remove_config_dt;
	}

	gmac->pdev = pdev;

	err = ipq806x_gmac_of_parse(gmac);
	if (err) {
		dev_err(dev, "device tree parsing error\n");
		goto err_remove_config_dt;
	}

	regmap_write(gmac->qsgmii_csr, QSGMII_PCS_CAL_LCKDT_CTL,
		     QSGMII_PCS_CAL_LCKDT_CTL_RST);

	/* Inter frame gap is set to 12 */
	val = 12 << NSS_COMMON_GMAC_CTL_IFG_OFFSET |
	      12 << NSS_COMMON_GMAC_CTL_IFG_LIMIT_OFFSET;
	/* We also initiate an AXI low power exit request */
	val |= NSS_COMMON_GMAC_CTL_CSYS_REQ;
	switch (gmac->phy_mode) {
	case PHY_INTERFACE_MODE_RGMII:
		val |= NSS_COMMON_GMAC_CTL_PHY_IFACE_SEL;
		break;
	case PHY_INTERFACE_MODE_SGMII:
		val &= ~NSS_COMMON_GMAC_CTL_PHY_IFACE_SEL;
		break;
	default:
		dev_err(&pdev->dev, "Unsupported PHY mode: \"%s\"\n",
			phy_modes(gmac->phy_mode));
		err = -EINVAL;
		goto err_remove_config_dt;
	}
	regmap_write(gmac->nss_common, NSS_COMMON_GMAC_CTL(gmac->id), val);

	/* Configure the clock src according to the mode */
	regmap_read(gmac->nss_common, NSS_COMMON_CLK_SRC_CTRL, &val);
	val &= ~(1 << NSS_COMMON_CLK_SRC_CTRL_OFFSET(gmac->id));
	switch (gmac->phy_mode) {
	case PHY_INTERFACE_MODE_RGMII:
		val |= NSS_COMMON_CLK_SRC_CTRL_RGMII(gmac->id) <<
			NSS_COMMON_CLK_SRC_CTRL_OFFSET(gmac->id);
		break;
	case PHY_INTERFACE_MODE_SGMII:
		val |= NSS_COMMON_CLK_SRC_CTRL_SGMII(gmac->id) <<
			NSS_COMMON_CLK_SRC_CTRL_OFFSET(gmac->id);
		break;
	default:
		dev_err(&pdev->dev, "Unsupported PHY mode: \"%s\"\n",
			phy_modes(gmac->phy_mode));
		err = -EINVAL;
		goto err_remove_config_dt;
	}
	regmap_write(gmac->nss_common, NSS_COMMON_CLK_SRC_CTRL, val);

	/* Enable PTP clock */
	regmap_read(gmac->nss_common, NSS_COMMON_CLK_GATE, &val);
	val |= NSS_COMMON_CLK_GATE_PTP_EN(gmac->id);
	regmap_write(gmac->nss_common, NSS_COMMON_CLK_GATE, val);

	if (gmac->phy_mode == PHY_INTERFACE_MODE_SGMII) {
		regmap_write(gmac->qsgmii_csr, QSGMII_PHY_SGMII_CTL(gmac->id),
			     QSGMII_PHY_CDR_EN |
			     QSGMII_PHY_RX_FRONT_EN |
			     QSGMII_PHY_RX_SIGNAL_DETECT_EN |
			     QSGMII_PHY_TX_DRIVER_EN |
			     QSGMII_PHY_QSGMII_EN |
			     0x4ul << QSGMII_PHY_PHASE_LOOP_GAIN_OFFSET |
			     0x3ul << QSGMII_PHY_RX_DC_BIAS_OFFSET |
			     0x1ul << QSGMII_PHY_RX_INPUT_EQU_OFFSET |
			     0x2ul << QSGMII_PHY_CDR_PI_SLEW_OFFSET |
			     0xCul << QSGMII_PHY_TX_DRV_AMP_OFFSET);
	}

	plat_dat->has_gmac = true;
	plat_dat->bsp_priv = gmac;
	plat_dat->fix_mac_speed = ipq806x_gmac_fix_mac_speed;

	err = stmmac_dvr_probe(&pdev->dev, plat_dat, &stmmac_res);
	if (err)
		goto err_remove_config_dt;

	return 0;

err_remove_config_dt:
	stmmac_remove_config_dt(pdev, plat_dat);

	return err;
}

