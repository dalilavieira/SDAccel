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
typedef  int u8 ;
typedef  int u16 ;
struct phy_device {scalar_t__ interrupts; scalar_t__ interface; scalar_t__ autoneg; struct net_device* attached_dev; } ;
struct net_device {scalar_t__ dev_addr; } ;
struct ethtool_wolinfo {int wolopts; int* sopass; int supported; } ;

/* Variables and functions */
 scalar_t__ AUTONEG_ENABLE ; 
 int DP83811_ANEG_COMPLETE_INT_EN ; 
 int /*<<< orphan*/  DP83811_DEVADDR ; 
 int DP83811_ENERGY_DET_INT_EN ; 
 int DP83811_ESD_EVENT_INT_EN ; 
 int DP83811_HW_RESET ; 
 int DP83811_JABBER_DET_INT_EN ; 
 int DP83811_LINK_QUAL_INT_EN ; 
 int DP83811_LINK_STAT_INT_EN ; 
 int DP83811_LPS_INT_EN ; 
 int DP83811_MS_TRAINING_INT_EN ; 
 int DP83811_NO_FRAME_INT_EN ; 
 int DP83811_OVERTEMP_INT_EN ; 
 int DP83811_OVERVOLTAGE_INT_EN ; 
 int DP83811_POLARITY_INT_EN ; 
 int DP83811_POR_DONE_INT_EN ; 
 int DP83811_RX_ERR_HF_INT_EN ; 
 int DP83811_SGMII_AUTO_NEG_EN ; 
 int DP83811_SGMII_EN ; 
 int DP83811_SLEEP_MODE_INT_EN ; 
 int DP83811_UNDERVOLTAGE_INT_EN ; 
 int DP83811_WOL_CLR_INDICATION ; 
 int DP83811_WOL_EN ; 
 int DP83811_WOL_INDICATION_SEL ; 
 int DP83811_WOL_INT_EN ; 
 int DP83811_WOL_MAGIC_EN ; 
 int DP83811_WOL_SECURE_ON ; 
 int EINVAL ; 
 int /*<<< orphan*/  MII_DP83811_INT_STAT1 ; 
 int /*<<< orphan*/  MII_DP83811_INT_STAT2 ; 
 int /*<<< orphan*/  MII_DP83811_INT_STAT3 ; 
 int /*<<< orphan*/  MII_DP83811_RESET_CTRL ; 
 int /*<<< orphan*/  MII_DP83811_RXSOP1 ; 
 int /*<<< orphan*/  MII_DP83811_RXSOP2 ; 
 int /*<<< orphan*/  MII_DP83811_RXSOP3 ; 
 int /*<<< orphan*/  MII_DP83811_SGMII_CTRL ; 
 int /*<<< orphan*/  MII_DP83811_WOL_CFG ; 
 int /*<<< orphan*/  MII_DP83811_WOL_DA1 ; 
 int /*<<< orphan*/  MII_DP83811_WOL_DA2 ; 
 int /*<<< orphan*/  MII_DP83811_WOL_DA3 ; 
 scalar_t__ PHY_INTERFACE_MODE_SGMII ; 
 scalar_t__ PHY_INTERRUPT_ENABLED ; 
 int WAKE_MAGIC ; 
 int WAKE_MAGICSECURE ; 
 int genphy_config_aneg (struct phy_device*) ; 
 int genphy_config_init (struct phy_device*) ; 
 int /*<<< orphan*/  genphy_resume (struct phy_device*) ; 
 int /*<<< orphan*/  genphy_suspend (struct phy_device*) ; 
 int /*<<< orphan*/  is_valid_ether_addr (int const*) ; 
 int phy_read (struct phy_device*,int /*<<< orphan*/ ) ; 
 int phy_read_mmd (struct phy_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int phy_write (struct phy_device*,int /*<<< orphan*/ ,int) ; 
 int phy_write_mmd (struct phy_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int const) ; 

__attribute__((used)) static int dp83811_ack_interrupt(struct phy_device *phydev)
{
	int err;

	err = phy_read(phydev, MII_DP83811_INT_STAT1);
	if (err < 0)
		return err;

	err = phy_read(phydev, MII_DP83811_INT_STAT2);
	if (err < 0)
		return err;

	err = phy_read(phydev, MII_DP83811_INT_STAT3);
	if (err < 0)
		return err;

	return 0;
}

__attribute__((used)) static int dp83811_set_wol(struct phy_device *phydev,
			   struct ethtool_wolinfo *wol)
{
	struct net_device *ndev = phydev->attached_dev;
	const u8 *mac;
	u16 value;

	if (wol->wolopts & (WAKE_MAGIC | WAKE_MAGICSECURE)) {
		mac = (const u8 *)ndev->dev_addr;

		if (!is_valid_ether_addr(mac))
			return -EINVAL;

		/* MAC addresses start with byte 5, but stored in mac[0].
		 * 811 PHYs store bytes 4|5, 2|3, 0|1
		 */
		phy_write_mmd(phydev, DP83811_DEVADDR, MII_DP83811_WOL_DA1,
			      (mac[1] << 8) | mac[0]);
		phy_write_mmd(phydev, DP83811_DEVADDR, MII_DP83811_WOL_DA2,
			      (mac[3] << 8) | mac[2]);
		phy_write_mmd(phydev, DP83811_DEVADDR, MII_DP83811_WOL_DA3,
			      (mac[5] << 8) | mac[4]);

		value = phy_read_mmd(phydev, DP83811_DEVADDR,
				     MII_DP83811_WOL_CFG);
		if (wol->wolopts & WAKE_MAGIC)
			value |= DP83811_WOL_MAGIC_EN;
		else
			value &= ~DP83811_WOL_MAGIC_EN;

		if (wol->wolopts & WAKE_MAGICSECURE) {
			phy_write_mmd(phydev, DP83811_DEVADDR,
				      MII_DP83811_RXSOP1,
				      (wol->sopass[1] << 8) | wol->sopass[0]);
			phy_write_mmd(phydev, DP83811_DEVADDR,
				      MII_DP83811_RXSOP2,
				      (wol->sopass[3] << 8) | wol->sopass[2]);
			phy_write_mmd(phydev, DP83811_DEVADDR,
				      MII_DP83811_RXSOP3,
				      (wol->sopass[5] << 8) | wol->sopass[4]);
			value |= DP83811_WOL_SECURE_ON;
		} else {
			value &= ~DP83811_WOL_SECURE_ON;
		}

		value |= (DP83811_WOL_EN | DP83811_WOL_INDICATION_SEL |
			  DP83811_WOL_CLR_INDICATION);
		phy_write_mmd(phydev, DP83811_DEVADDR, MII_DP83811_WOL_CFG,
			      value);
	} else {
		value = phy_read_mmd(phydev, DP83811_DEVADDR,
				     MII_DP83811_WOL_CFG);
		value &= ~DP83811_WOL_EN;
		phy_write_mmd(phydev, DP83811_DEVADDR, MII_DP83811_WOL_CFG,
			      value);
	}

	return 0;
}

__attribute__((used)) static void dp83811_get_wol(struct phy_device *phydev,
			    struct ethtool_wolinfo *wol)
{
	u16 sopass_val;
	int value;

	wol->supported = (WAKE_MAGIC | WAKE_MAGICSECURE);
	wol->wolopts = 0;

	value = phy_read_mmd(phydev, DP83811_DEVADDR, MII_DP83811_WOL_CFG);

	if (value & DP83811_WOL_MAGIC_EN)
		wol->wolopts |= WAKE_MAGIC;

	if (value & DP83811_WOL_SECURE_ON) {
		sopass_val = phy_read_mmd(phydev, DP83811_DEVADDR,
					  MII_DP83811_RXSOP1);
		wol->sopass[0] = (sopass_val & 0xff);
		wol->sopass[1] = (sopass_val >> 8);

		sopass_val = phy_read_mmd(phydev, DP83811_DEVADDR,
					  MII_DP83811_RXSOP2);
		wol->sopass[2] = (sopass_val & 0xff);
		wol->sopass[3] = (sopass_val >> 8);

		sopass_val = phy_read_mmd(phydev, DP83811_DEVADDR,
					  MII_DP83811_RXSOP3);
		wol->sopass[4] = (sopass_val & 0xff);
		wol->sopass[5] = (sopass_val >> 8);

		wol->wolopts |= WAKE_MAGICSECURE;
	}

	/* WoL is not enabled so set wolopts to 0 */
	if (!(value & DP83811_WOL_EN))
		wol->wolopts = 0;
}

__attribute__((used)) static int dp83811_config_intr(struct phy_device *phydev)
{
	int misr_status, err;

	if (phydev->interrupts == PHY_INTERRUPT_ENABLED) {
		misr_status = phy_read(phydev, MII_DP83811_INT_STAT1);
		if (misr_status < 0)
			return misr_status;

		misr_status |= (DP83811_RX_ERR_HF_INT_EN |
				DP83811_MS_TRAINING_INT_EN |
				DP83811_ANEG_COMPLETE_INT_EN |
				DP83811_ESD_EVENT_INT_EN |
				DP83811_WOL_INT_EN |
				DP83811_LINK_STAT_INT_EN |
				DP83811_ENERGY_DET_INT_EN |
				DP83811_LINK_QUAL_INT_EN);

		err = phy_write(phydev, MII_DP83811_INT_STAT1, misr_status);
		if (err < 0)
			return err;

		misr_status = phy_read(phydev, MII_DP83811_INT_STAT2);
		if (misr_status < 0)
			return misr_status;

		misr_status |= (DP83811_JABBER_DET_INT_EN |
				DP83811_POLARITY_INT_EN |
				DP83811_SLEEP_MODE_INT_EN |
				DP83811_OVERTEMP_INT_EN |
				DP83811_OVERVOLTAGE_INT_EN |
				DP83811_UNDERVOLTAGE_INT_EN);

		err = phy_write(phydev, MII_DP83811_INT_STAT2, misr_status);
		if (err < 0)
			return err;

		misr_status = phy_read(phydev, MII_DP83811_INT_STAT3);
		if (misr_status < 0)
			return misr_status;

		misr_status |= (DP83811_LPS_INT_EN |
				DP83811_NO_FRAME_INT_EN |
				DP83811_POR_DONE_INT_EN);

		err = phy_write(phydev, MII_DP83811_INT_STAT3, misr_status);

	} else {
		err = phy_write(phydev, MII_DP83811_INT_STAT1, 0);
		if (err < 0)
			return err;

		err = phy_write(phydev, MII_DP83811_INT_STAT2, 0);
		if (err < 0)
			return err;

		err = phy_write(phydev, MII_DP83811_INT_STAT3, 0);
	}

	return err;
}

__attribute__((used)) static int dp83811_config_aneg(struct phy_device *phydev)
{
	int value, err;

	if (phydev->interface == PHY_INTERFACE_MODE_SGMII) {
		value = phy_read(phydev, MII_DP83811_SGMII_CTRL);
		if (phydev->autoneg == AUTONEG_ENABLE) {
			err = phy_write(phydev, MII_DP83811_SGMII_CTRL,
					(DP83811_SGMII_AUTO_NEG_EN | value));
			if (err < 0)
				return err;
		} else {
			err = phy_write(phydev, MII_DP83811_SGMII_CTRL,
					(~DP83811_SGMII_AUTO_NEG_EN & value));
			if (err < 0)
				return err;
		}
	}

	return genphy_config_aneg(phydev);
}

__attribute__((used)) static int dp83811_config_init(struct phy_device *phydev)
{
	int value, err;

	err = genphy_config_init(phydev);
	if (err < 0)
		return err;

	value = phy_read(phydev, MII_DP83811_SGMII_CTRL);
	if (phydev->interface == PHY_INTERFACE_MODE_SGMII) {
		err = phy_write(phydev, MII_DP83811_SGMII_CTRL,
					(DP83811_SGMII_EN | value));
	} else {
		err = phy_write(phydev, MII_DP83811_SGMII_CTRL,
				(~DP83811_SGMII_EN & value));
	}

	if (err < 0)

		return err;

	value = DP83811_WOL_MAGIC_EN | DP83811_WOL_SECURE_ON | DP83811_WOL_EN;

	return phy_write_mmd(phydev, DP83811_DEVADDR, MII_DP83811_WOL_CFG,
	      value);
}

__attribute__((used)) static int dp83811_phy_reset(struct phy_device *phydev)
{
	int err;

	err = phy_write(phydev, MII_DP83811_RESET_CTRL, DP83811_HW_RESET);
	if (err < 0)
		return err;

	return 0;
}

__attribute__((used)) static int dp83811_suspend(struct phy_device *phydev)
{
	int value;

	value = phy_read_mmd(phydev, DP83811_DEVADDR, MII_DP83811_WOL_CFG);

	if (!(value & DP83811_WOL_EN))
		genphy_suspend(phydev);

	return 0;
}

__attribute__((used)) static int dp83811_resume(struct phy_device *phydev)
{
	int value;

	genphy_resume(phydev);

	value = phy_read_mmd(phydev, DP83811_DEVADDR, MII_DP83811_WOL_CFG);

	phy_write_mmd(phydev, DP83811_DEVADDR, MII_DP83811_WOL_CFG, value |
		      DP83811_WOL_CLR_INDICATION);

	return 0;
}

