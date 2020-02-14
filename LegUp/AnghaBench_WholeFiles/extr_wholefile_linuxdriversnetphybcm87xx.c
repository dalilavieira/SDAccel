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
struct TYPE_2__ {scalar_t__* device_ids; } ;
struct phy_device {int speed; int link; int duplex; scalar_t__ interrupts; TYPE_1__ c45_ids; int /*<<< orphan*/  autoneg; int /*<<< orphan*/  state; int /*<<< orphan*/  advertising; int /*<<< orphan*/  supported; } ;

/* Variables and functions */
 int /*<<< orphan*/  ADVERTISED_10000baseR_FEC ; 
 int /*<<< orphan*/  AUTONEG_DISABLE ; 
 int /*<<< orphan*/  BCM87XX_10GBASER_PCS_STATUS ; 
 int /*<<< orphan*/  BCM87XX_LASI_CONTROL ; 
 int /*<<< orphan*/  BCM87XX_LASI_STATUS ; 
 int /*<<< orphan*/  BCM87XX_PMD_RX_SIGNAL_DETECT ; 
 int /*<<< orphan*/  BCM87XX_XGXS_LANE_STATUS ; 
 int EINVAL ; 
 scalar_t__ PHY_ID_BCM8706 ; 
 scalar_t__ PHY_ID_BCM8727 ; 
 scalar_t__ PHY_INTERRUPT_ENABLED ; 
 int /*<<< orphan*/  PHY_NOLINK ; 
 int /*<<< orphan*/  SUPPORTED_10000baseR_FEC ; 
 int phy_read (struct phy_device*,int /*<<< orphan*/ ) ; 
 int phy_write (struct phy_device*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  phydev_err (struct phy_device*,char*,int) ; 

__attribute__((used)) static int bcm87xx_of_reg_init(struct phy_device *phydev)
{
	return 0;
}

__attribute__((used)) static int bcm87xx_config_init(struct phy_device *phydev)
{
	phydev->supported = SUPPORTED_10000baseR_FEC;
	phydev->advertising = ADVERTISED_10000baseR_FEC;
	phydev->state = PHY_NOLINK;
	phydev->autoneg = AUTONEG_DISABLE;

	bcm87xx_of_reg_init(phydev);

	return 0;
}

__attribute__((used)) static int bcm87xx_config_aneg(struct phy_device *phydev)
{
	return -EINVAL;
}

__attribute__((used)) static int bcm87xx_read_status(struct phy_device *phydev)
{
	int rx_signal_detect;
	int pcs_status;
	int xgxs_lane_status;

	rx_signal_detect = phy_read(phydev, BCM87XX_PMD_RX_SIGNAL_DETECT);
	if (rx_signal_detect < 0)
		return rx_signal_detect;

	if ((rx_signal_detect & 1) == 0)
		goto no_link;

	pcs_status = phy_read(phydev, BCM87XX_10GBASER_PCS_STATUS);
	if (pcs_status < 0)
		return pcs_status;

	if ((pcs_status & 1) == 0)
		goto no_link;

	xgxs_lane_status = phy_read(phydev, BCM87XX_XGXS_LANE_STATUS);
	if (xgxs_lane_status < 0)
		return xgxs_lane_status;

	if ((xgxs_lane_status & 0x1000) == 0)
		goto no_link;

	phydev->speed = 10000;
	phydev->link = 1;
	phydev->duplex = 1;
	return 0;

no_link:
	phydev->link = 0;
	return 0;
}

__attribute__((used)) static int bcm87xx_config_intr(struct phy_device *phydev)
{
	int reg, err;

	reg = phy_read(phydev, BCM87XX_LASI_CONTROL);

	if (reg < 0)
		return reg;

	if (phydev->interrupts == PHY_INTERRUPT_ENABLED)
		reg |= 1;
	else
		reg &= ~1;

	err = phy_write(phydev, BCM87XX_LASI_CONTROL, reg);
	return err;
}

__attribute__((used)) static int bcm87xx_did_interrupt(struct phy_device *phydev)
{
	int reg;

	reg = phy_read(phydev, BCM87XX_LASI_STATUS);

	if (reg < 0) {
		phydev_err(phydev,
			   "Error: Read of BCM87XX_LASI_STATUS failed: %d\n",
			   reg);
		return 0;
	}
	return (reg & 1) != 0;
}

__attribute__((used)) static int bcm87xx_ack_interrupt(struct phy_device *phydev)
{
	/* Reading the LASI status clears it. */
	bcm87xx_did_interrupt(phydev);
	return 0;
}

__attribute__((used)) static int bcm8706_match_phy_device(struct phy_device *phydev)
{
	return phydev->c45_ids.device_ids[4] == PHY_ID_BCM8706;
}

__attribute__((used)) static int bcm8727_match_phy_device(struct phy_device *phydev)
{
	return phydev->c45_ids.device_ids[4] == PHY_ID_BCM8727;
}

