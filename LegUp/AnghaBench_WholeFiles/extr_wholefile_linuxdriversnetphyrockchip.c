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
struct phy_device {scalar_t__ autoneg; int speed; int mdix; } ;

/* Variables and functions */
 scalar_t__ AUTONEG_ENABLE ; 
 int BMCR_SPEED100 ; 
#define  ETH_TP_MDI 131 
#define  ETH_TP_MDI_AUTO 130 
#define  ETH_TP_MDI_INVALID 129 
#define  ETH_TP_MDI_X 128 
 int MII_AUTO_MDIX_EN ; 
 int /*<<< orphan*/  MII_BMCR ; 
 int /*<<< orphan*/  MII_INTERNAL_CTRL_STATUS ; 
 int MII_MDIX_EN ; 
 int /*<<< orphan*/  MII_SPECIAL_CONTROL_STATUS ; 
 int MII_SPEED_10 ; 
 int MII_SPEED_100 ; 
 int /*<<< orphan*/  SMI_ADDR_TSTCNTL ; 
 int /*<<< orphan*/  SMI_ADDR_TSTWRITE ; 
 int SPEED_10 ; 
 int SPEED_100 ; 
 int TSTCNTL_WR ; 
 int TSTMODE_DISABLE ; 
 int TSTMODE_ENABLE ; 
 int WR_ADDR_A7CFG ; 
 int genphy_config_aneg (struct phy_device*) ; 
 int /*<<< orphan*/  genphy_resume (struct phy_device*) ; 
 int phy_read (struct phy_device*,int /*<<< orphan*/ ) ; 
 int phy_write (struct phy_device*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  phydev_err (struct phy_device*,char*,int) ; 

__attribute__((used)) static int rockchip_init_tstmode(struct phy_device *phydev)
{
	int ret;

	/* Enable access to Analog and DSP register banks */
	ret = phy_write(phydev, SMI_ADDR_TSTCNTL, TSTMODE_ENABLE);
	if (ret)
		return ret;

	ret = phy_write(phydev, SMI_ADDR_TSTCNTL, TSTMODE_DISABLE);
	if (ret)
		return ret;

	return phy_write(phydev, SMI_ADDR_TSTCNTL, TSTMODE_ENABLE);
}

__attribute__((used)) static int rockchip_close_tstmode(struct phy_device *phydev)
{
	/* Back to basic register bank */
	return phy_write(phydev, SMI_ADDR_TSTCNTL, TSTMODE_DISABLE);
}

__attribute__((used)) static int rockchip_integrated_phy_analog_init(struct phy_device *phydev)
{
	int ret;

	ret = rockchip_init_tstmode(phydev);
	if (ret)
		return ret;

	/*
	 * Adjust tx amplitude to make sginal better,
	 * the default value is 0x8.
	 */
	ret = phy_write(phydev, SMI_ADDR_TSTWRITE, 0xB);
	if (ret)
		return ret;
	ret = phy_write(phydev, SMI_ADDR_TSTCNTL, TSTCNTL_WR | WR_ADDR_A7CFG);
	if (ret)
		return ret;

	return rockchip_close_tstmode(phydev);
}

__attribute__((used)) static int rockchip_integrated_phy_config_init(struct phy_device *phydev)
{
	int val, ret;

	/*
	 * The auto MIDX has linked problem on some board,
	 * workround to disable auto MDIX.
	 */
	val = phy_read(phydev, MII_INTERNAL_CTRL_STATUS);
	if (val < 0)
		return val;
	val &= ~MII_AUTO_MDIX_EN;
	ret = phy_write(phydev, MII_INTERNAL_CTRL_STATUS, val);
	if (ret)
		return ret;

	return rockchip_integrated_phy_analog_init(phydev);
}

__attribute__((used)) static void rockchip_link_change_notify(struct phy_device *phydev)
{
	int speed = SPEED_10;

	if (phydev->autoneg == AUTONEG_ENABLE) {
		int reg = phy_read(phydev, MII_SPECIAL_CONTROL_STATUS);

		if (reg < 0) {
			phydev_err(phydev, "phy_read err: %d.\n", reg);
			return;
		}

		if (reg & MII_SPEED_100)
			speed = SPEED_100;
		else if (reg & MII_SPEED_10)
			speed = SPEED_10;
	} else {
		int bmcr = phy_read(phydev, MII_BMCR);

		if (bmcr < 0) {
			phydev_err(phydev, "phy_read err: %d.\n", bmcr);
			return;
		}

		if (bmcr & BMCR_SPEED100)
			speed = SPEED_100;
		else
			speed = SPEED_10;
	}

	/*
	 * If mode switch happens from 10BT to 100BT, all DSP/AFE
	 * registers are set to default values. So any AFE/DSP
	 * registers have to be re-initialized in this case.
	 */
	if ((phydev->speed == SPEED_10) && (speed == SPEED_100)) {
		int ret = rockchip_integrated_phy_analog_init(phydev);
		if (ret)
			phydev_err(phydev, "rockchip_integrated_phy_analog_init err: %d.\n",
				   ret);
	}
}

__attribute__((used)) static int rockchip_set_polarity(struct phy_device *phydev, int polarity)
{
	int reg, err, val;

	/* get the current settings */
	reg = phy_read(phydev, MII_INTERNAL_CTRL_STATUS);
	if (reg < 0)
		return reg;

	reg &= ~MII_AUTO_MDIX_EN;
	val = reg;
	switch (polarity) {
	case ETH_TP_MDI:
		val &= ~MII_MDIX_EN;
		break;
	case ETH_TP_MDI_X:
		val |= MII_MDIX_EN;
		break;
	case ETH_TP_MDI_AUTO:
	case ETH_TP_MDI_INVALID:
	default:
		return 0;
	}

	if (val != reg) {
		/* Set the new polarity value in the register */
		err = phy_write(phydev, MII_INTERNAL_CTRL_STATUS, val);
		if (err)
			return err;
	}

	return 0;
}

__attribute__((used)) static int rockchip_config_aneg(struct phy_device *phydev)
{
	int err;

	err = rockchip_set_polarity(phydev, phydev->mdix);
	if (err < 0)
		return err;

	return genphy_config_aneg(phydev);
}

__attribute__((used)) static int rockchip_phy_resume(struct phy_device *phydev)
{
	genphy_resume(phydev);

	return rockchip_integrated_phy_config_init(phydev);
}

