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
typedef  scalar_t__ u32 ;
typedef  int u16 ;
struct pch_gbe_phy_info {int id; int /*<<< orphan*/  autoneg_advertised; int /*<<< orphan*/  addr; scalar_t__ revision; } ;
struct TYPE_3__ {int /*<<< orphan*/  autoneg; int /*<<< orphan*/  link_duplex; int /*<<< orphan*/  link_speed; } ;
struct pch_gbe_hw {struct pch_gbe_phy_info phy; TYPE_1__ mac; } ;
struct pch_gbe_adapter {int /*<<< orphan*/  netdev; TYPE_2__* pdata; int /*<<< orphan*/  mii; } ;
struct ethtool_cmd {int /*<<< orphan*/  autoneg; int /*<<< orphan*/  advertising; int /*<<< orphan*/  duplex; int /*<<< orphan*/  cmd; } ;
typedef  int s32 ;
struct TYPE_4__ {scalar_t__ phy_tx_clk_delay; } ;

/* Variables and functions */
 int BMCR_RESET ; 
 int EINVAL ; 
 int /*<<< orphan*/  ETHTOOL_GSET ; 
 scalar_t__ MII_BMCR ; 
 int MII_CR_POWER_DOWN ; 
 int MII_CR_RESET ; 
 int /*<<< orphan*/  PCH_GBE_HAL_MIIM_READ ; 
 int /*<<< orphan*/  PCH_GBE_HAL_MIIM_WRITE ; 
 int PHYSP_CTRL_ASSERT_CRS_TX ; 
 scalar_t__ PHY_1000T_CTRL ; 
 int PHY_1000T_CTRL_DEFAULT ; 
 scalar_t__ PHY_AR8031_DBG_DAT ; 
 scalar_t__ PHY_AR8031_DBG_OFF ; 
 int PHY_AR8031_HIBERNATE ; 
 int PHY_AR8031_PS_HIB_EN ; 
 int PHY_AR8031_SERDES ; 
 int PHY_AR8031_SERDES_TX_CLK_DLY ; 
#define  PHY_AR803X_ID 128 
 scalar_t__ PHY_AUTONEG_ADV ; 
 int PHY_AUTONEG_ADV_DEFAULT ; 
 scalar_t__ PHY_CONTROL ; 
 int PHY_CONTROL_DEFAULT ; 
 scalar_t__ PHY_ID1 ; 
 scalar_t__ PHY_ID2 ; 
 scalar_t__ PHY_MAX_REG_ADDRESS ; 
 scalar_t__ PHY_NEXT_PAGE_TX ; 
 int PHY_NEXT_PAGE_TX_DEFAULT ; 
 scalar_t__ PHY_PHYSP_CONTROL ; 
 int PHY_PHYSP_CONTROL_DEFAULT ; 
 int /*<<< orphan*/  ethtool_cmd_speed_set (struct ethtool_cmd*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int mii_ethtool_gset (int /*<<< orphan*/ *,struct ethtool_cmd*) ; 
 int mii_ethtool_sset (int /*<<< orphan*/ *,struct ethtool_cmd*) ; 
 int /*<<< orphan*/  netdev_dbg (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  netdev_err (int /*<<< orphan*/ ,char*,...) ; 
 struct pch_gbe_adapter* pch_gbe_hw_to_adapter (struct pch_gbe_hw*) ; 
 int pch_gbe_mac_ctrl_miim (struct pch_gbe_hw*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__,int) ; 
 int pch_gbe_phy_read_reg_miic (struct pch_gbe_hw*,scalar_t__,int*) ; 
 int /*<<< orphan*/  udelay (int) ; 

s32 pch_gbe_phy_get_id(struct pch_gbe_hw *hw)
{
	struct pch_gbe_adapter *adapter = pch_gbe_hw_to_adapter(hw);
	struct pch_gbe_phy_info *phy = &hw->phy;
	s32 ret;
	u16 phy_id1;
	u16 phy_id2;

	ret = pch_gbe_phy_read_reg_miic(hw, PHY_ID1, &phy_id1);
	if (ret)
		return ret;
	ret = pch_gbe_phy_read_reg_miic(hw, PHY_ID2, &phy_id2);
	if (ret)
		return ret;
	/*
	 * PHY_ID1: [bit15-0:ID(21-6)]
	 * PHY_ID2: [bit15-10:ID(5-0)][bit9-4:Model][bit3-0:revision]
	 */
	phy->id = (u32)phy_id1;
	phy->id = ((phy->id << 6) | ((phy_id2 & 0xFC00) >> 10));
	phy->revision = (u32) (phy_id2 & 0x000F);
	netdev_dbg(adapter->netdev,
		   "phy->id : 0x%08x  phy->revision : 0x%08x\n",
		   phy->id, phy->revision);
	return 0;
}

s32 pch_gbe_phy_read_reg_miic(struct pch_gbe_hw *hw, u32 offset, u16 *data)
{
	struct pch_gbe_phy_info *phy = &hw->phy;

	if (offset > PHY_MAX_REG_ADDRESS) {
		struct pch_gbe_adapter *adapter = pch_gbe_hw_to_adapter(hw);

		netdev_err(adapter->netdev, "PHY Address %d is out of range\n",
			   offset);
		return -EINVAL;
	}
	*data = pch_gbe_mac_ctrl_miim(hw, phy->addr, PCH_GBE_HAL_MIIM_READ,
				      offset, (u16)0);
	return 0;
}

s32 pch_gbe_phy_write_reg_miic(struct pch_gbe_hw *hw, u32 offset, u16 data)
{
	struct pch_gbe_phy_info *phy = &hw->phy;

	if (offset > PHY_MAX_REG_ADDRESS) {
		struct pch_gbe_adapter *adapter = pch_gbe_hw_to_adapter(hw);

		netdev_err(adapter->netdev, "PHY Address %d is out of range\n",
			   offset);
		return -EINVAL;
	}
	pch_gbe_mac_ctrl_miim(hw, phy->addr, PCH_GBE_HAL_MIIM_WRITE,
				 offset, data);
	return 0;
}

__attribute__((used)) static void pch_gbe_phy_sw_reset(struct pch_gbe_hw *hw)
{
	u16 phy_ctrl;

	pch_gbe_phy_read_reg_miic(hw, PHY_CONTROL, &phy_ctrl);
	phy_ctrl |= MII_CR_RESET;
	pch_gbe_phy_write_reg_miic(hw, PHY_CONTROL, phy_ctrl);
	udelay(1);
}

void pch_gbe_phy_hw_reset(struct pch_gbe_hw *hw)
{
	pch_gbe_phy_write_reg_miic(hw, PHY_CONTROL, PHY_CONTROL_DEFAULT);
	pch_gbe_phy_write_reg_miic(hw, PHY_AUTONEG_ADV,
					PHY_AUTONEG_ADV_DEFAULT);
	pch_gbe_phy_write_reg_miic(hw, PHY_NEXT_PAGE_TX,
					PHY_NEXT_PAGE_TX_DEFAULT);
	pch_gbe_phy_write_reg_miic(hw, PHY_1000T_CTRL, PHY_1000T_CTRL_DEFAULT);
	pch_gbe_phy_write_reg_miic(hw, PHY_PHYSP_CONTROL,
					PHY_PHYSP_CONTROL_DEFAULT);
}

void pch_gbe_phy_power_up(struct pch_gbe_hw *hw)
{
	u16 mii_reg;

	mii_reg = 0;
	/* Just clear the power down bit to wake the phy back up */
	/* according to the manual, the phy will retain its
	 * settings across a power-down/up cycle */
	pch_gbe_phy_read_reg_miic(hw, PHY_CONTROL, &mii_reg);
	mii_reg &= ~MII_CR_POWER_DOWN;
	pch_gbe_phy_write_reg_miic(hw, PHY_CONTROL, mii_reg);
}

void pch_gbe_phy_power_down(struct pch_gbe_hw *hw)
{
	u16 mii_reg;

	mii_reg = 0;
	/* Power down the PHY so no link is implied when interface is down *
	 * The PHY cannot be powered down if any of the following is TRUE *
	 * (a) WoL is enabled
	 * (b) AMT is active
	 */
	pch_gbe_phy_read_reg_miic(hw, PHY_CONTROL, &mii_reg);
	mii_reg |= MII_CR_POWER_DOWN;
	pch_gbe_phy_write_reg_miic(hw, PHY_CONTROL, mii_reg);
	mdelay(1);
}

void pch_gbe_phy_set_rgmii(struct pch_gbe_hw *hw)
{
	pch_gbe_phy_sw_reset(hw);
}

__attribute__((used)) static int pch_gbe_phy_tx_clk_delay(struct pch_gbe_hw *hw)
{
	/* The RGMII interface requires a ~2ns TX clock delay. This is typically
	 * done in layout with a longer trace or via PHY strapping, but can also
	 * be done via PHY configuration registers.
	 */
	struct pch_gbe_adapter *adapter = pch_gbe_hw_to_adapter(hw);
	u16 mii_reg;
	int ret = 0;

	switch (hw->phy.id) {
	case PHY_AR803X_ID:
		netdev_dbg(adapter->netdev,
			   "Configuring AR803X PHY for 2ns TX clock delay\n");
		pch_gbe_phy_read_reg_miic(hw, PHY_AR8031_DBG_OFF, &mii_reg);
		ret = pch_gbe_phy_write_reg_miic(hw, PHY_AR8031_DBG_OFF,
						 PHY_AR8031_SERDES);
		if (ret)
			break;

		pch_gbe_phy_read_reg_miic(hw, PHY_AR8031_DBG_DAT, &mii_reg);
		mii_reg |= PHY_AR8031_SERDES_TX_CLK_DLY;
		ret = pch_gbe_phy_write_reg_miic(hw, PHY_AR8031_DBG_DAT,
						 mii_reg);
		break;
	default:
		netdev_err(adapter->netdev,
			   "Unknown PHY (%x), could not set TX clock delay\n",
			   hw->phy.id);
		return -EINVAL;
	}

	if (ret)
		netdev_err(adapter->netdev,
			   "Could not configure tx clock delay for PHY\n");
	return ret;
}

void pch_gbe_phy_init_setting(struct pch_gbe_hw *hw)
{
	struct pch_gbe_adapter *adapter = pch_gbe_hw_to_adapter(hw);
	struct ethtool_cmd     cmd = { .cmd = ETHTOOL_GSET };
	int ret;
	u16 mii_reg;

	ret = mii_ethtool_gset(&adapter->mii, &cmd);
	if (ret)
		netdev_err(adapter->netdev, "Error: mii_ethtool_gset\n");

	ethtool_cmd_speed_set(&cmd, hw->mac.link_speed);
	cmd.duplex = hw->mac.link_duplex;
	cmd.advertising = hw->phy.autoneg_advertised;
	cmd.autoneg = hw->mac.autoneg;
	pch_gbe_phy_write_reg_miic(hw, MII_BMCR, BMCR_RESET);
	ret = mii_ethtool_sset(&adapter->mii, &cmd);
	if (ret)
		netdev_err(adapter->netdev, "Error: mii_ethtool_sset\n");

	pch_gbe_phy_sw_reset(hw);

	pch_gbe_phy_read_reg_miic(hw, PHY_PHYSP_CONTROL, &mii_reg);
	mii_reg |= PHYSP_CTRL_ASSERT_CRS_TX;
	pch_gbe_phy_write_reg_miic(hw, PHY_PHYSP_CONTROL, mii_reg);

	/* Setup a TX clock delay on certain platforms */
	if (adapter->pdata && adapter->pdata->phy_tx_clk_delay)
		pch_gbe_phy_tx_clk_delay(hw);
}

int pch_gbe_phy_disable_hibernate(struct pch_gbe_hw *hw)
{
	struct pch_gbe_adapter *adapter = pch_gbe_hw_to_adapter(hw);
	u16 mii_reg;
	int ret = 0;

	switch (hw->phy.id) {
	case PHY_AR803X_ID:
		netdev_dbg(adapter->netdev,
			   "Disabling hibernation for AR803X PHY\n");
		ret = pch_gbe_phy_write_reg_miic(hw, PHY_AR8031_DBG_OFF,
						 PHY_AR8031_HIBERNATE);
		if (ret)
			break;

		pch_gbe_phy_read_reg_miic(hw, PHY_AR8031_DBG_DAT, &mii_reg);
		mii_reg &= ~PHY_AR8031_PS_HIB_EN;
		ret = pch_gbe_phy_write_reg_miic(hw, PHY_AR8031_DBG_DAT,
						 mii_reg);
		break;
	default:
		netdev_err(adapter->netdev,
			   "Unknown PHY (%x), could not disable hibernation\n",
			   hw->phy.id);
		return -EINVAL;
	}

	if (ret)
		netdev_err(adapter->netdev,
			   "Could not disable PHY hibernation\n");
	return ret;
}

