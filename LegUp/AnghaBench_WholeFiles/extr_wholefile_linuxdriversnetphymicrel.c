#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u64 ;
typedef  int u32 ;
typedef  int u16 ;
struct device {struct device_node const* of_node; struct device* parent; } ;
struct TYPE_4__ {struct device dev; } ;
struct phy_device {scalar_t__ interrupts; int dev_flags; int supported; int advertising; int link; TYPE_2__ mdio; struct kszphy_priv* priv; TYPE_1__* drv; scalar_t__ asym_pause; scalar_t__ pause; void* speed; int /*<<< orphan*/  duplex; int /*<<< orphan*/  autoneg; } ;
typedef  struct kszphy_type {int interrupt_level_mask; int led_mode_reg; int has_rmii_ref_clk_sel; scalar_t__ has_nand_tree_disable; scalar_t__ has_broadcast_disable; } const kszphy_type ;
struct kszphy_priv {int rmii_ref_clk_sel; int rmii_ref_clk_sel_val; int led_mode; int* stats; struct kszphy_type const* type; } ;
struct kszphy_hw_stat {int reg; int bits; int /*<<< orphan*/  string; } ;
struct ethtool_stats {int dummy; } ;
typedef  struct device_node const device_node ;
struct clk {int dummy; } ;
struct TYPE_3__ {struct kszphy_type const* driver_data; int /*<<< orphan*/  (* config_intr ) (struct phy_device*) ;} ;

/* Variables and functions */
 int ADVERTISED_100baseT_Full ; 
 int ADVERTISED_100baseT_Half ; 
 int ADVERTISED_FIBRE ; 
 int ARRAY_SIZE (struct kszphy_hw_stat*) ; 
 int /*<<< orphan*/  AUTONEG_DISABLE ; 
 int CTL1000_AS_MASTER ; 
 int CTL1000_ENABLE_MASTER ; 
 int /*<<< orphan*/  DUPLEX_FULL ; 
 int /*<<< orphan*/  DUPLEX_HALF ; 
 int EINVAL ; 
 int ENOMEM ; 
 int ETH_GSTRING_LEN ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IS_ERR_OR_NULL (struct clk*) ; 
 int KSZ8873MLL_GLOBAL_CONTROL_4 ; 
 int KSZ8873MLL_GLOBAL_CONTROL_4_DUPLEX ; 
 int KSZ8873MLL_GLOBAL_CONTROL_4_SPEED ; 
 int KSZ9031_PS_TO_REG ; 
 int KSZPHY_CTRL_INT_ACTIVE_HIGH ; 
 int KSZPHY_EXTREG_WRITE ; 
 int KSZPHY_INTCS_ALL ; 
 int KSZPHY_OMSO_B_CAST_OFF ; 
 int KSZPHY_OMSO_NAND_TREE_ON ; 
 int KSZPHY_RMII_REF_CLK_SEL ; 
 int /*<<< orphan*/  MDIO_DEVID1 ; 
 int /*<<< orphan*/  MDIO_MMD_PMAPMD ; 
 int MICREL_PHY_50MHZ_CLK ; 
 int MICREL_PHY_FXEN ; 
 int MII_CTRL1000 ; 
 int MII_KSZ9031RN_CLK_PAD_SKEW ; 
 int MII_KSZ9031RN_CONTROL_PAD_SKEW ; 
 int MII_KSZ9031RN_EDPD ; 
 int MII_KSZ9031RN_EDPD_ENABLE ; 
 int MII_KSZ9031RN_FLP_BURST_TX_HI ; 
 int MII_KSZ9031RN_FLP_BURST_TX_LO ; 
 int MII_KSZ9031RN_MMD_CTRL_REG ; 
 int MII_KSZ9031RN_MMD_REGDATA_REG ; 
 int MII_KSZ9031RN_RX_DATA_PAD_SKEW ; 
 int MII_KSZ9031RN_TX_DATA_PAD_SKEW ; 
 int MII_KSZPHY_CLK_CONTROL_PAD_SKEW ; 
 int MII_KSZPHY_CTRL ; 
#define  MII_KSZPHY_CTRL_1 129 
#define  MII_KSZPHY_CTRL_2 128 
 int MII_KSZPHY_EXTREG ; 
 int MII_KSZPHY_EXTREG_READ ; 
 int MII_KSZPHY_EXTREG_WRITE ; 
 int MII_KSZPHY_INTCS ; 
 int MII_KSZPHY_OMSO ; 
 int MII_KSZPHY_RX_DATA_PAD_SKEW ; 
 int MII_KSZPHY_TX_DATA_PAD_SKEW ; 
 int MII_STAT1000 ; 
 int OP_DATA ; 
 scalar_t__ PHY_INTERRUPT_DISABLED ; 
 scalar_t__ PHY_INTERRUPT_ENABLED ; 
 int PS_TO_REG ; 
 void* SPEED_10 ; 
 void* SPEED_100 ; 
 int SUPPORTED_100baseT_Full ; 
 int SUPPORTED_100baseT_Half ; 
 int SUPPORTED_FIBRE ; 
 int U64_MAX ; 
 unsigned long clk_get_rate (struct clk*) ; 
 struct clk* devm_clk_get (struct device*,char*) ; 
 struct kszphy_priv* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int genphy_config_aneg (struct phy_device*) ; 
 int genphy_read_status (struct phy_device*) ; 
 int genphy_restart_aneg (struct phy_device*) ; 
 int /*<<< orphan*/  genphy_resume (struct phy_device*) ; 
 int genphy_suspend (struct phy_device*) ; 
 struct kszphy_hw_stat* kszphy_hw_stats ; 
 int of_property_read_bool (struct device_node const*,char*) ; 
 int of_property_read_u32 (struct device_node const*,char const*,int*) ; 
 int /*<<< orphan*/  phy_init_hw (struct phy_device*) ; 
 scalar_t__ phy_interrupt_is_valid (struct phy_device*) ; 
 int phy_read (struct phy_device*,int) ; 
 int phy_write (struct phy_device*,int,int) ; 
 int phy_write_mmd (struct phy_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  phydev_err (struct phy_device*,char*,...) ; 
 int /*<<< orphan*/  strlcpy (int*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub1 (struct phy_device*) ; 
 int /*<<< orphan*/  stub2 (struct phy_device*) ; 
 int /*<<< orphan*/  stub3 (struct phy_device*) ; 

__attribute__((used)) static int kszphy_extended_write(struct phy_device *phydev,
				u32 regnum, u16 val)
{
	phy_write(phydev, MII_KSZPHY_EXTREG, KSZPHY_EXTREG_WRITE | regnum);
	return phy_write(phydev, MII_KSZPHY_EXTREG_WRITE, val);
}

__attribute__((used)) static int kszphy_extended_read(struct phy_device *phydev,
				u32 regnum)
{
	phy_write(phydev, MII_KSZPHY_EXTREG, regnum);
	return phy_read(phydev, MII_KSZPHY_EXTREG_READ);
}

__attribute__((used)) static int kszphy_ack_interrupt(struct phy_device *phydev)
{
	/* bit[7..0] int status, which is a read and clear register. */
	int rc;

	rc = phy_read(phydev, MII_KSZPHY_INTCS);

	return (rc < 0) ? rc : 0;
}

__attribute__((used)) static int kszphy_config_intr(struct phy_device *phydev)
{
	const struct kszphy_type *type = phydev->drv->driver_data;
	int temp;
	u16 mask;

	if (type && type->interrupt_level_mask)
		mask = type->interrupt_level_mask;
	else
		mask = KSZPHY_CTRL_INT_ACTIVE_HIGH;

	/* set the interrupt pin active low */
	temp = phy_read(phydev, MII_KSZPHY_CTRL);
	if (temp < 0)
		return temp;
	temp &= ~mask;
	phy_write(phydev, MII_KSZPHY_CTRL, temp);

	/* enable / disable interrupts */
	if (phydev->interrupts == PHY_INTERRUPT_ENABLED)
		temp = KSZPHY_INTCS_ALL;
	else
		temp = 0;

	return phy_write(phydev, MII_KSZPHY_INTCS, temp);
}

__attribute__((used)) static int kszphy_rmii_clk_sel(struct phy_device *phydev, bool val)
{
	int ctrl;

	ctrl = phy_read(phydev, MII_KSZPHY_CTRL);
	if (ctrl < 0)
		return ctrl;

	if (val)
		ctrl |= KSZPHY_RMII_REF_CLK_SEL;
	else
		ctrl &= ~KSZPHY_RMII_REF_CLK_SEL;

	return phy_write(phydev, MII_KSZPHY_CTRL, ctrl);
}

__attribute__((used)) static int kszphy_setup_led(struct phy_device *phydev, u32 reg, int val)
{
	int rc, temp, shift;

	switch (reg) {
	case MII_KSZPHY_CTRL_1:
		shift = 14;
		break;
	case MII_KSZPHY_CTRL_2:
		shift = 4;
		break;
	default:
		return -EINVAL;
	}

	temp = phy_read(phydev, reg);
	if (temp < 0) {
		rc = temp;
		goto out;
	}

	temp &= ~(3 << shift);
	temp |= val << shift;
	rc = phy_write(phydev, reg, temp);
out:
	if (rc < 0)
		phydev_err(phydev, "failed to set led mode\n");

	return rc;
}

__attribute__((used)) static int kszphy_broadcast_disable(struct phy_device *phydev)
{
	int ret;

	ret = phy_read(phydev, MII_KSZPHY_OMSO);
	if (ret < 0)
		goto out;

	ret = phy_write(phydev, MII_KSZPHY_OMSO, ret | KSZPHY_OMSO_B_CAST_OFF);
out:
	if (ret)
		phydev_err(phydev, "failed to disable broadcast address\n");

	return ret;
}

__attribute__((used)) static int kszphy_nand_tree_disable(struct phy_device *phydev)
{
	int ret;

	ret = phy_read(phydev, MII_KSZPHY_OMSO);
	if (ret < 0)
		goto out;

	if (!(ret & KSZPHY_OMSO_NAND_TREE_ON))
		return 0;

	ret = phy_write(phydev, MII_KSZPHY_OMSO,
			ret & ~KSZPHY_OMSO_NAND_TREE_ON);
out:
	if (ret)
		phydev_err(phydev, "failed to disable NAND tree mode\n");

	return ret;
}

__attribute__((used)) static int kszphy_config_reset(struct phy_device *phydev)
{
	struct kszphy_priv *priv = phydev->priv;
	int ret;

	if (priv->rmii_ref_clk_sel) {
		ret = kszphy_rmii_clk_sel(phydev, priv->rmii_ref_clk_sel_val);
		if (ret) {
			phydev_err(phydev,
				   "failed to set rmii reference clock\n");
			return ret;
		}
	}

	if (priv->led_mode >= 0)
		kszphy_setup_led(phydev, priv->type->led_mode_reg, priv->led_mode);

	return 0;
}

__attribute__((used)) static int kszphy_config_init(struct phy_device *phydev)
{
	struct kszphy_priv *priv = phydev->priv;
	const struct kszphy_type *type;

	if (!priv)
		return 0;

	type = priv->type;

	if (type->has_broadcast_disable)
		kszphy_broadcast_disable(phydev);

	if (type->has_nand_tree_disable)
		kszphy_nand_tree_disable(phydev);

	return kszphy_config_reset(phydev);
}

__attribute__((used)) static int ksz8041_config_init(struct phy_device *phydev)
{
	struct device_node *of_node = phydev->mdio.dev.of_node;

	/* Limit supported and advertised modes in fiber mode */
	if (of_property_read_bool(of_node, "micrel,fiber-mode")) {
		phydev->dev_flags |= MICREL_PHY_FXEN;
		phydev->supported &= SUPPORTED_100baseT_Full |
				     SUPPORTED_100baseT_Half;
		phydev->supported |= SUPPORTED_FIBRE;
		phydev->advertising &= ADVERTISED_100baseT_Full |
				       ADVERTISED_100baseT_Half;
		phydev->advertising |= ADVERTISED_FIBRE;
		phydev->autoneg = AUTONEG_DISABLE;
	}

	return kszphy_config_init(phydev);
}

__attribute__((used)) static int ksz8041_config_aneg(struct phy_device *phydev)
{
	/* Skip auto-negotiation in fiber mode */
	if (phydev->dev_flags & MICREL_PHY_FXEN) {
		phydev->speed = SPEED_100;
		return 0;
	}

	return genphy_config_aneg(phydev);
}

__attribute__((used)) static int ksz8061_config_init(struct phy_device *phydev)
{
	int ret;

	ret = phy_write_mmd(phydev, MDIO_MMD_PMAPMD, MDIO_DEVID1, 0xB61A);
	if (ret)
		return ret;

	return kszphy_config_init(phydev);
}

__attribute__((used)) static int ksz9021_load_values_from_of(struct phy_device *phydev,
				       const struct device_node *of_node,
				       u16 reg,
				       const char *field1, const char *field2,
				       const char *field3, const char *field4)
{
	int val1 = -1;
	int val2 = -2;
	int val3 = -3;
	int val4 = -4;
	int newval;
	int matches = 0;

	if (!of_property_read_u32(of_node, field1, &val1))
		matches++;

	if (!of_property_read_u32(of_node, field2, &val2))
		matches++;

	if (!of_property_read_u32(of_node, field3, &val3))
		matches++;

	if (!of_property_read_u32(of_node, field4, &val4))
		matches++;

	if (!matches)
		return 0;

	if (matches < 4)
		newval = kszphy_extended_read(phydev, reg);
	else
		newval = 0;

	if (val1 != -1)
		newval = ((newval & 0xfff0) | ((val1 / PS_TO_REG) & 0xf) << 0);

	if (val2 != -2)
		newval = ((newval & 0xff0f) | ((val2 / PS_TO_REG) & 0xf) << 4);

	if (val3 != -3)
		newval = ((newval & 0xf0ff) | ((val3 / PS_TO_REG) & 0xf) << 8);

	if (val4 != -4)
		newval = ((newval & 0x0fff) | ((val4 / PS_TO_REG) & 0xf) << 12);

	return kszphy_extended_write(phydev, reg, newval);
}

__attribute__((used)) static int ksz9021_config_init(struct phy_device *phydev)
{
	const struct device *dev = &phydev->mdio.dev;
	const struct device_node *of_node = dev->of_node;
	const struct device *dev_walker;

	/* The Micrel driver has a deprecated option to place phy OF
	 * properties in the MAC node. Walk up the tree of devices to
	 * find a device with an OF node.
	 */
	dev_walker = &phydev->mdio.dev;
	do {
		of_node = dev_walker->of_node;
		dev_walker = dev_walker->parent;

	} while (!of_node && dev_walker);

	if (of_node) {
		ksz9021_load_values_from_of(phydev, of_node,
				    MII_KSZPHY_CLK_CONTROL_PAD_SKEW,
				    "txen-skew-ps", "txc-skew-ps",
				    "rxdv-skew-ps", "rxc-skew-ps");
		ksz9021_load_values_from_of(phydev, of_node,
				    MII_KSZPHY_RX_DATA_PAD_SKEW,
				    "rxd0-skew-ps", "rxd1-skew-ps",
				    "rxd2-skew-ps", "rxd3-skew-ps");
		ksz9021_load_values_from_of(phydev, of_node,
				    MII_KSZPHY_TX_DATA_PAD_SKEW,
				    "txd0-skew-ps", "txd1-skew-ps",
				    "txd2-skew-ps", "txd3-skew-ps");
	}
	return 0;
}

__attribute__((used)) static int ksz9031_extended_write(struct phy_device *phydev,
				  u8 mode, u32 dev_addr, u32 regnum, u16 val)
{
	phy_write(phydev, MII_KSZ9031RN_MMD_CTRL_REG, dev_addr);
	phy_write(phydev, MII_KSZ9031RN_MMD_REGDATA_REG, regnum);
	phy_write(phydev, MII_KSZ9031RN_MMD_CTRL_REG, (mode << 14) | dev_addr);
	return phy_write(phydev, MII_KSZ9031RN_MMD_REGDATA_REG, val);
}

__attribute__((used)) static int ksz9031_extended_read(struct phy_device *phydev,
				 u8 mode, u32 dev_addr, u32 regnum)
{
	phy_write(phydev, MII_KSZ9031RN_MMD_CTRL_REG, dev_addr);
	phy_write(phydev, MII_KSZ9031RN_MMD_REGDATA_REG, regnum);
	phy_write(phydev, MII_KSZ9031RN_MMD_CTRL_REG, (mode << 14) | dev_addr);
	return phy_read(phydev, MII_KSZ9031RN_MMD_REGDATA_REG);
}

__attribute__((used)) static int ksz9031_of_load_skew_values(struct phy_device *phydev,
				       const struct device_node *of_node,
				       u16 reg, size_t field_sz,
				       const char *field[], u8 numfields)
{
	int val[4] = {-1, -2, -3, -4};
	int matches = 0;
	u16 mask;
	u16 maxval;
	u16 newval;
	int i;

	for (i = 0; i < numfields; i++)
		if (!of_property_read_u32(of_node, field[i], val + i))
			matches++;

	if (!matches)
		return 0;

	if (matches < numfields)
		newval = ksz9031_extended_read(phydev, OP_DATA, 2, reg);
	else
		newval = 0;

	maxval = (field_sz == 4) ? 0xf : 0x1f;
	for (i = 0; i < numfields; i++)
		if (val[i] != -(i + 1)) {
			mask = 0xffff;
			mask ^= maxval << (field_sz * i);
			newval = (newval & mask) |
				(((val[i] / KSZ9031_PS_TO_REG) & maxval)
					<< (field_sz * i));
		}

	return ksz9031_extended_write(phydev, OP_DATA, 2, reg, newval);
}

__attribute__((used)) static int ksz9031_center_flp_timing(struct phy_device *phydev)
{
	int result;

	result = ksz9031_extended_write(phydev, OP_DATA, 0,
					MII_KSZ9031RN_FLP_BURST_TX_HI, 0x0006);
	if (result)
		return result;

	result = ksz9031_extended_write(phydev, OP_DATA, 0,
					MII_KSZ9031RN_FLP_BURST_TX_LO, 0x1A80);
	if (result)
		return result;

	return genphy_restart_aneg(phydev);
}

__attribute__((used)) static int ksz9031_enable_edpd(struct phy_device *phydev)
{
	int reg;

	reg = ksz9031_extended_read(phydev, OP_DATA, 0x1C, MII_KSZ9031RN_EDPD);
	if (reg < 0)
		return reg;
	return ksz9031_extended_write(phydev, OP_DATA, 0x1C, MII_KSZ9031RN_EDPD,
				      reg | MII_KSZ9031RN_EDPD_ENABLE);
}

__attribute__((used)) static int ksz9031_config_init(struct phy_device *phydev)
{
	const struct device *dev = &phydev->mdio.dev;
	const struct device_node *of_node = dev->of_node;
	static const char *clk_skews[2] = {"rxc-skew-ps", "txc-skew-ps"};
	static const char *rx_data_skews[4] = {
		"rxd0-skew-ps", "rxd1-skew-ps",
		"rxd2-skew-ps", "rxd3-skew-ps"
	};
	static const char *tx_data_skews[4] = {
		"txd0-skew-ps", "txd1-skew-ps",
		"txd2-skew-ps", "txd3-skew-ps"
	};
	static const char *control_skews[2] = {"txen-skew-ps", "rxdv-skew-ps"};
	const struct device *dev_walker;
	int result;

	result = ksz9031_enable_edpd(phydev);
	if (result < 0)
		return result;

	/* The Micrel driver has a deprecated option to place phy OF
	 * properties in the MAC node. Walk up the tree of devices to
	 * find a device with an OF node.
	 */
	dev_walker = &phydev->mdio.dev;
	do {
		of_node = dev_walker->of_node;
		dev_walker = dev_walker->parent;
	} while (!of_node && dev_walker);

	if (of_node) {
		ksz9031_of_load_skew_values(phydev, of_node,
				MII_KSZ9031RN_CLK_PAD_SKEW, 5,
				clk_skews, 2);

		ksz9031_of_load_skew_values(phydev, of_node,
				MII_KSZ9031RN_CONTROL_PAD_SKEW, 4,
				control_skews, 2);

		ksz9031_of_load_skew_values(phydev, of_node,
				MII_KSZ9031RN_RX_DATA_PAD_SKEW, 4,
				rx_data_skews, 4);

		ksz9031_of_load_skew_values(phydev, of_node,
				MII_KSZ9031RN_TX_DATA_PAD_SKEW, 4,
				tx_data_skews, 4);

		/* Silicon Errata Sheet (DS80000691D or DS80000692D):
		 * When the device links in the 1000BASE-T slave mode only,
		 * the optional 125MHz reference output clock (CLK125_NDO)
		 * has wide duty cycle variation.
		 *
		 * The optional CLK125_NDO clock does not meet the RGMII
		 * 45/55 percent (min/max) duty cycle requirement and therefore
		 * cannot be used directly by the MAC side for clocking
		 * applications that have setup/hold time requirements on
		 * rising and falling clock edges.
		 *
		 * Workaround:
		 * Force the phy to be the master to receive a stable clock
		 * which meets the duty cycle requirement.
		 */
		if (of_property_read_bool(of_node, "micrel,force-master")) {
			result = phy_read(phydev, MII_CTRL1000);
			if (result < 0)
				goto err_force_master;

			/* enable master mode, config & prefer master */
			result |= CTL1000_ENABLE_MASTER | CTL1000_AS_MASTER;
			result = phy_write(phydev, MII_CTRL1000, result);
			if (result < 0)
				goto err_force_master;
		}
	}

	return ksz9031_center_flp_timing(phydev);

err_force_master:
	phydev_err(phydev, "failed to force the phy to master mode\n");
	return result;
}

__attribute__((used)) static int ksz8873mll_read_status(struct phy_device *phydev)
{
	int regval;

	/* dummy read */
	regval = phy_read(phydev, KSZ8873MLL_GLOBAL_CONTROL_4);

	regval = phy_read(phydev, KSZ8873MLL_GLOBAL_CONTROL_4);

	if (regval & KSZ8873MLL_GLOBAL_CONTROL_4_DUPLEX)
		phydev->duplex = DUPLEX_HALF;
	else
		phydev->duplex = DUPLEX_FULL;

	if (regval & KSZ8873MLL_GLOBAL_CONTROL_4_SPEED)
		phydev->speed = SPEED_10;
	else
		phydev->speed = SPEED_100;

	phydev->link = 1;
	phydev->pause = phydev->asym_pause = 0;

	return 0;
}

__attribute__((used)) static int ksz9031_read_status(struct phy_device *phydev)
{
	int err;
	int regval;

	err = genphy_read_status(phydev);
	if (err)
		return err;

	/* Make sure the PHY is not broken. Read idle error count,
	 * and reset the PHY if it is maxed out.
	 */
	regval = phy_read(phydev, MII_STAT1000);
	if ((regval & 0xFF) == 0xFF) {
		phy_init_hw(phydev);
		phydev->link = 0;
		if (phydev->drv->config_intr && phy_interrupt_is_valid(phydev))
			phydev->drv->config_intr(phydev);
		return genphy_config_aneg(phydev);
	}

	return 0;
}

__attribute__((used)) static int ksz8873mll_config_aneg(struct phy_device *phydev)
{
	return 0;
}

__attribute__((used)) static int kszphy_get_sset_count(struct phy_device *phydev)
{
	return ARRAY_SIZE(kszphy_hw_stats);
}

__attribute__((used)) static void kszphy_get_strings(struct phy_device *phydev, u8 *data)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(kszphy_hw_stats); i++) {
		strlcpy(data + i * ETH_GSTRING_LEN,
			kszphy_hw_stats[i].string, ETH_GSTRING_LEN);
	}
}

__attribute__((used)) static u64 kszphy_get_stat(struct phy_device *phydev, int i)
{
	struct kszphy_hw_stat stat = kszphy_hw_stats[i];
	struct kszphy_priv *priv = phydev->priv;
	int val;
	u64 ret;

	val = phy_read(phydev, stat.reg);
	if (val < 0) {
		ret = U64_MAX;
	} else {
		val = val & ((1 << stat.bits) - 1);
		priv->stats[i] += val;
		ret = priv->stats[i];
	}

	return ret;
}

__attribute__((used)) static void kszphy_get_stats(struct phy_device *phydev,
			     struct ethtool_stats *stats, u64 *data)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(kszphy_hw_stats); i++)
		data[i] = kszphy_get_stat(phydev, i);
}

__attribute__((used)) static int kszphy_suspend(struct phy_device *phydev)
{
	/* Disable PHY Interrupts */
	if (phy_interrupt_is_valid(phydev)) {
		phydev->interrupts = PHY_INTERRUPT_DISABLED;
		if (phydev->drv->config_intr)
			phydev->drv->config_intr(phydev);
	}

	return genphy_suspend(phydev);
}

__attribute__((used)) static int kszphy_resume(struct phy_device *phydev)
{
	int ret;

	genphy_resume(phydev);

	ret = kszphy_config_reset(phydev);
	if (ret)
		return ret;

	/* Enable PHY Interrupts */
	if (phy_interrupt_is_valid(phydev)) {
		phydev->interrupts = PHY_INTERRUPT_ENABLED;
		if (phydev->drv->config_intr)
			phydev->drv->config_intr(phydev);
	}

	return 0;
}

__attribute__((used)) static int kszphy_probe(struct phy_device *phydev)
{
	const struct kszphy_type *type = phydev->drv->driver_data;
	const struct device_node *np = phydev->mdio.dev.of_node;
	struct kszphy_priv *priv;
	struct clk *clk;
	int ret;

	priv = devm_kzalloc(&phydev->mdio.dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	phydev->priv = priv;

	priv->type = type;

	if (type->led_mode_reg) {
		ret = of_property_read_u32(np, "micrel,led-mode",
				&priv->led_mode);
		if (ret)
			priv->led_mode = -1;

		if (priv->led_mode > 3) {
			phydev_err(phydev, "invalid led mode: 0x%02x\n",
				   priv->led_mode);
			priv->led_mode = -1;
		}
	} else {
		priv->led_mode = -1;
	}

	clk = devm_clk_get(&phydev->mdio.dev, "rmii-ref");
	/* NOTE: clk may be NULL if building without CONFIG_HAVE_CLK */
	if (!IS_ERR_OR_NULL(clk)) {
		unsigned long rate = clk_get_rate(clk);
		bool rmii_ref_clk_sel_25_mhz;

		priv->rmii_ref_clk_sel = type->has_rmii_ref_clk_sel;
		rmii_ref_clk_sel_25_mhz = of_property_read_bool(np,
				"micrel,rmii-reference-clock-select-25-mhz");

		if (rate > 24500000 && rate < 25500000) {
			priv->rmii_ref_clk_sel_val = rmii_ref_clk_sel_25_mhz;
		} else if (rate > 49500000 && rate < 50500000) {
			priv->rmii_ref_clk_sel_val = !rmii_ref_clk_sel_25_mhz;
		} else {
			phydev_err(phydev, "Clock rate out of range: %ld\n",
				   rate);
			return -EINVAL;
		}
	}

	/* Support legacy board-file configuration */
	if (phydev->dev_flags & MICREL_PHY_50MHZ_CLK) {
		priv->rmii_ref_clk_sel = true;
		priv->rmii_ref_clk_sel_val = true;
	}

	return 0;
}

