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
typedef  int u32 ;
typedef  int u16 ;
struct phy_device {scalar_t__ interrupts; } ;

/* Variables and functions */
 int ADVERTISED_MPD ; 
 int /*<<< orphan*/  MDIO_MMD_VEND2 ; 
 int /*<<< orphan*/  MII_CTRL1000 ; 
 scalar_t__ PHY_INTERRUPT_ENABLED ; 
 int /*<<< orphan*/  XWAY_MDIO_IMASK ; 
 int XWAY_MDIO_INIT_MASK ; 
 int /*<<< orphan*/  XWAY_MDIO_ISTAT ; 
 int /*<<< orphan*/  XWAY_MMD_LED0H ; 
 int /*<<< orphan*/  XWAY_MMD_LED0L ; 
 int /*<<< orphan*/  XWAY_MMD_LED1H ; 
 int /*<<< orphan*/  XWAY_MMD_LED1L ; 
 int /*<<< orphan*/  XWAY_MMD_LED2H ; 
 int /*<<< orphan*/  XWAY_MMD_LED2L ; 
 int /*<<< orphan*/  XWAY_MMD_LEDCH ; 
 int XWAY_MMD_LEDCH_CBLINK_NONE ; 
 int XWAY_MMD_LEDCH_FBF_F16HZ ; 
 int XWAY_MMD_LEDCH_NACS_NONE ; 
 int XWAY_MMD_LEDCH_SBF_F02HZ ; 
 int XWAY_MMD_LEDCH_SCAN_NONE ; 
 int /*<<< orphan*/  XWAY_MMD_LEDCL ; 
 int XWAY_MMD_LEDxH_BLINKF_NONE ; 
 int XWAY_MMD_LEDxH_CON_LINK10XX ; 
 int XWAY_MMD_LEDxL_BLINKS_NONE ; 
 int XWAY_MMD_LEDxL_PULSE_RXACT ; 
 int XWAY_MMD_LEDxL_PULSE_TXACT ; 
 int genphy_config_aneg (struct phy_device*) ; 
 int phy_read (struct phy_device*,int /*<<< orphan*/ ) ; 
 int phy_write (struct phy_device*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  phy_write_mmd (struct phy_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int xway_gphy_config_init(struct phy_device *phydev)
{
	int err;
	u32 ledxh;
	u32 ledxl;

	/* Mask all interrupts */
	err = phy_write(phydev, XWAY_MDIO_IMASK, 0);
	if (err)
		return err;

	/* Clear all pending interrupts */
	phy_read(phydev, XWAY_MDIO_ISTAT);

	phy_write_mmd(phydev, MDIO_MMD_VEND2, XWAY_MMD_LEDCH,
		      XWAY_MMD_LEDCH_NACS_NONE |
		      XWAY_MMD_LEDCH_SBF_F02HZ |
		      XWAY_MMD_LEDCH_FBF_F16HZ);
	phy_write_mmd(phydev, MDIO_MMD_VEND2, XWAY_MMD_LEDCL,
		      XWAY_MMD_LEDCH_CBLINK_NONE |
		      XWAY_MMD_LEDCH_SCAN_NONE);

	/**
	 * In most cases only one LED is connected to this phy, so
	 * configure them all to constant on and pulse mode. LED3 is
	 * only available in some packages, leave it in its reset
	 * configuration.
	 */
	ledxh = XWAY_MMD_LEDxH_BLINKF_NONE | XWAY_MMD_LEDxH_CON_LINK10XX;
	ledxl = XWAY_MMD_LEDxL_PULSE_TXACT | XWAY_MMD_LEDxL_PULSE_RXACT |
		XWAY_MMD_LEDxL_BLINKS_NONE;
	phy_write_mmd(phydev, MDIO_MMD_VEND2, XWAY_MMD_LED0H, ledxh);
	phy_write_mmd(phydev, MDIO_MMD_VEND2, XWAY_MMD_LED0L, ledxl);
	phy_write_mmd(phydev, MDIO_MMD_VEND2, XWAY_MMD_LED1H, ledxh);
	phy_write_mmd(phydev, MDIO_MMD_VEND2, XWAY_MMD_LED1L, ledxl);
	phy_write_mmd(phydev, MDIO_MMD_VEND2, XWAY_MMD_LED2H, ledxh);
	phy_write_mmd(phydev, MDIO_MMD_VEND2, XWAY_MMD_LED2L, ledxl);

	return 0;
}

__attribute__((used)) static int xway_gphy14_config_aneg(struct phy_device *phydev)
{
	int reg, err;

	/* Advertise as multi-port device, see IEEE802.3-2002 40.5.1.1 */
	/* This is a workaround for an errata in rev < 1.5 devices */
	reg = phy_read(phydev, MII_CTRL1000);
	reg |= ADVERTISED_MPD;
	err = phy_write(phydev, MII_CTRL1000, reg);
	if (err)
		return err;

	return genphy_config_aneg(phydev);
}

__attribute__((used)) static int xway_gphy_ack_interrupt(struct phy_device *phydev)
{
	int reg;

	reg = phy_read(phydev, XWAY_MDIO_ISTAT);
	return (reg < 0) ? reg : 0;
}

__attribute__((used)) static int xway_gphy_did_interrupt(struct phy_device *phydev)
{
	int reg;

	reg = phy_read(phydev, XWAY_MDIO_ISTAT);
	return reg & XWAY_MDIO_INIT_MASK;
}

__attribute__((used)) static int xway_gphy_config_intr(struct phy_device *phydev)
{
	u16 mask = 0;

	if (phydev->interrupts == PHY_INTERRUPT_ENABLED)
		mask = XWAY_MDIO_INIT_MASK;

	return phy_write(phydev, XWAY_MDIO_IMASK, mask);
}

