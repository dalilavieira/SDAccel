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
struct TYPE_2__ {int addr; int /*<<< orphan*/  bus; } ;
struct phy_device {int link; scalar_t__ interface; TYPE_1__ mdio; int /*<<< orphan*/  irq; int /*<<< orphan*/  attached_dev; int /*<<< orphan*/  duplex; int /*<<< orphan*/  speed; int /*<<< orphan*/  state; } ;

/* Variables and functions */
 int BMCR_RESET ; 
 int /*<<< orphan*/  DUPLEX_FULL ; 
 int IP1001_APS_ON ; 
 int IP1001_RXPHASE_SEL ; 
 int IP1001_SPEC_CTRL_STATUS_2 ; 
 int IP1001_TXPHASE_SEL ; 
 int IP101A_G_APS_ON ; 
 int IP101A_G_IRQ_CONF_STATUS ; 
 int IP101A_G_IRQ_DEFAULT ; 
 int IP10XX_SPEC_CTRL_STATUS ; 
 int MII_BMCR ; 
 int /*<<< orphan*/  PHY_IGNORE_INTERRUPT ; 
 scalar_t__ PHY_INTERFACE_MODE_RGMII_ID ; 
 scalar_t__ PHY_INTERFACE_MODE_RGMII_RXID ; 
 scalar_t__ PHY_INTERFACE_MODE_RGMII_TXID ; 
 int /*<<< orphan*/  PHY_RUNNING ; 
 int /*<<< orphan*/  SPEED_100 ; 
 int /*<<< orphan*/  genphy_config_aneg (struct phy_device*) ; 
 int /*<<< orphan*/  genphy_read_status (struct phy_device*) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int mdiobus_read (int /*<<< orphan*/ ,int,int) ; 
 int mdiobus_write (int /*<<< orphan*/ ,int,int,int) ; 
 int /*<<< orphan*/  netif_carrier_on (int /*<<< orphan*/ ) ; 
 scalar_t__ phy_interface_is_rgmii (struct phy_device*) ; 
 int phy_read (struct phy_device*,int) ; 
 int phy_write (struct phy_device*,int,int) ; 

__attribute__((used)) static int ip175c_config_init(struct phy_device *phydev)
{
	int err, i;
	static int full_reset_performed;

	if (full_reset_performed == 0) {

		/* master reset */
		err = mdiobus_write(phydev->mdio.bus, 30, 0, 0x175c);
		if (err < 0)
			return err;

		/* ensure no bus delays overlap reset period */
		err = mdiobus_read(phydev->mdio.bus, 30, 0);

		/* data sheet specifies reset period is 2 msec */
		mdelay(2);

		/* enable IP175C mode */
		err = mdiobus_write(phydev->mdio.bus, 29, 31, 0x175c);
		if (err < 0)
			return err;

		/* Set MII0 speed and duplex (in PHY mode) */
		err = mdiobus_write(phydev->mdio.bus, 29, 22, 0x420);
		if (err < 0)
			return err;

		/* reset switch ports */
		for (i = 0; i < 5; i++) {
			err = mdiobus_write(phydev->mdio.bus, i,
					    MII_BMCR, BMCR_RESET);
			if (err < 0)
				return err;
		}

		for (i = 0; i < 5; i++)
			err = mdiobus_read(phydev->mdio.bus, i, MII_BMCR);

		mdelay(2);

		full_reset_performed = 1;
	}

	if (phydev->mdio.addr != 4) {
		phydev->state = PHY_RUNNING;
		phydev->speed = SPEED_100;
		phydev->duplex = DUPLEX_FULL;
		phydev->link = 1;
		netif_carrier_on(phydev->attached_dev);
	}

	return 0;
}

__attribute__((used)) static int ip1xx_reset(struct phy_device *phydev)
{
	int bmcr;

	/* Software Reset PHY */
	bmcr = phy_read(phydev, MII_BMCR);
	if (bmcr < 0)
		return bmcr;
	bmcr |= BMCR_RESET;
	bmcr = phy_write(phydev, MII_BMCR, bmcr);
	if (bmcr < 0)
		return bmcr;

	do {
		bmcr = phy_read(phydev, MII_BMCR);
		if (bmcr < 0)
			return bmcr;
	} while (bmcr & BMCR_RESET);

	return 0;
}

__attribute__((used)) static int ip1001_config_init(struct phy_device *phydev)
{
	int c;

	c = ip1xx_reset(phydev);
	if (c < 0)
		return c;

	/* Enable Auto Power Saving mode */
	c = phy_read(phydev, IP1001_SPEC_CTRL_STATUS_2);
	if (c < 0)
		return c;
	c |= IP1001_APS_ON;
	c = phy_write(phydev, IP1001_SPEC_CTRL_STATUS_2, c);
	if (c < 0)
		return c;

	if (phy_interface_is_rgmii(phydev)) {

		c = phy_read(phydev, IP10XX_SPEC_CTRL_STATUS);
		if (c < 0)
			return c;

		c &= ~(IP1001_RXPHASE_SEL | IP1001_TXPHASE_SEL);

		if (phydev->interface == PHY_INTERFACE_MODE_RGMII_ID)
			c |= (IP1001_RXPHASE_SEL | IP1001_TXPHASE_SEL);
		else if (phydev->interface == PHY_INTERFACE_MODE_RGMII_RXID)
			c |= IP1001_RXPHASE_SEL;
		else if (phydev->interface == PHY_INTERFACE_MODE_RGMII_TXID)
			c |= IP1001_TXPHASE_SEL;

		c = phy_write(phydev, IP10XX_SPEC_CTRL_STATUS, c);
		if (c < 0)
			return c;
	}

	return 0;
}

__attribute__((used)) static int ip101a_g_config_init(struct phy_device *phydev)
{
	int c;

	c = ip1xx_reset(phydev);
	if (c < 0)
		return c;

	/* INTR pin used: speed/link/duplex will cause an interrupt */
	c = phy_write(phydev, IP101A_G_IRQ_CONF_STATUS, IP101A_G_IRQ_DEFAULT);
	if (c < 0)
		return c;

	/* Enable Auto Power Saving mode */
	c = phy_read(phydev, IP10XX_SPEC_CTRL_STATUS);
	c |= IP101A_G_APS_ON;

	return phy_write(phydev, IP10XX_SPEC_CTRL_STATUS, c);
}

__attribute__((used)) static int ip175c_read_status(struct phy_device *phydev)
{
	if (phydev->mdio.addr == 4) /* WAN port */
		genphy_read_status(phydev);
	else
		/* Don't need to read status for switch ports */
		phydev->irq = PHY_IGNORE_INTERRUPT;

	return 0;
}

__attribute__((used)) static int ip175c_config_aneg(struct phy_device *phydev)
{
	if (phydev->mdio.addr == 4) /* WAN port */
		genphy_config_aneg(phydev);

	return 0;
}

__attribute__((used)) static int ip101a_g_ack_interrupt(struct phy_device *phydev)
{
	int err = phy_read(phydev, IP101A_G_IRQ_CONF_STATUS);
	if (err < 0)
		return err;

	return 0;
}

