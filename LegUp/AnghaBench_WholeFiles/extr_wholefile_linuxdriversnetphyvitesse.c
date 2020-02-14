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
typedef  int u16 ;
struct phy_device {scalar_t__ interface; scalar_t__ interrupts; scalar_t__ autoneg; scalar_t__ speed; TYPE_1__* drv; } ;
struct TYPE_2__ {scalar_t__ phy_id; } ;

/* Variables and functions */
 scalar_t__ AUTONEG_ENABLE ; 
 int MII_PHYSID2 ; 
 int MII_TPISTATUS ; 
 int MII_VSC8221_AUXCONSTAT_INIT ; 
 int MII_VSC8221_IMASK_MASK ; 
 int MII_VSC8244_AUXCONSTAT_INIT ; 
 int MII_VSC8244_AUX_CONSTAT ; 
 int MII_VSC8244_EXTCON1_RX_SKEW ; 
 int MII_VSC8244_EXTCON1_RX_SKEW_MASK ; 
 int MII_VSC8244_EXTCON1_TX_SKEW ; 
 int MII_VSC8244_EXTCON1_TX_SKEW_MASK ; 
 int MII_VSC8244_EXT_CON1 ; 
 int MII_VSC8244_IMASK ; 
 int MII_VSC8244_IMASK_MASK ; 
 int MII_VSC8244_ISTAT ; 
 int MII_VSC82X4_EXT_PAGE_16E ; 
 int MII_VSC82X4_EXT_PAGE_17E ; 
 int MII_VSC82X4_EXT_PAGE_18E ; 
 int MII_VSC82X4_EXT_PAGE_ACCESS ; 
 int MII_VSC8601_EPHY_CTL ; 
 int MII_VSC8601_EPHY_CTL_RGMII_SKEW ; 
 scalar_t__ PHY_ID_VSC8234 ; 
 scalar_t__ PHY_ID_VSC8244 ; 
 scalar_t__ PHY_ID_VSC8514 ; 
 scalar_t__ PHY_ID_VSC8572 ; 
 scalar_t__ PHY_ID_VSC8574 ; 
 scalar_t__ PHY_ID_VSC8601 ; 
 scalar_t__ PHY_INTERFACE_MODE_RGMII_ID ; 
 scalar_t__ PHY_INTERRUPT_ENABLED ; 
 scalar_t__ SPEED_100 ; 
 int /*<<< orphan*/  VSC73XX_EXT_PAGE_ACCESS ; 
 int __phy_read (struct phy_device*,int /*<<< orphan*/ ) ; 
 int __phy_write (struct phy_device*,int /*<<< orphan*/ ,int) ; 
 int genphy_config_aneg (struct phy_device*) ; 
 int genphy_config_init (struct phy_device*) ; 
 int genphy_setup_forced (struct phy_device*) ; 
 int /*<<< orphan*/  phy_modify (struct phy_device*,int,int,int) ; 
 int phy_read (struct phy_device*,int) ; 
 int phy_write (struct phy_device*,int,int) ; 

__attribute__((used)) static int vsc824x_add_skew(struct phy_device *phydev)
{
	int err;
	int extcon;

	extcon = phy_read(phydev, MII_VSC8244_EXT_CON1);

	if (extcon < 0)
		return extcon;

	extcon &= ~(MII_VSC8244_EXTCON1_TX_SKEW_MASK |
			MII_VSC8244_EXTCON1_RX_SKEW_MASK);

	extcon |= (MII_VSC8244_EXTCON1_TX_SKEW |
			MII_VSC8244_EXTCON1_RX_SKEW);

	err = phy_write(phydev, MII_VSC8244_EXT_CON1, extcon);

	return err;
}

__attribute__((used)) static int vsc824x_config_init(struct phy_device *phydev)
{
	int err;

	err = phy_write(phydev, MII_VSC8244_AUX_CONSTAT,
			MII_VSC8244_AUXCONSTAT_INIT);
	if (err < 0)
		return err;

	if (phydev->interface == PHY_INTERFACE_MODE_RGMII_ID)
		err = vsc824x_add_skew(phydev);

	return err;
}

__attribute__((used)) static int vsc73xx_read_page(struct phy_device *phydev)
{
	return __phy_read(phydev, VSC73XX_EXT_PAGE_ACCESS);
}

__attribute__((used)) static int vsc73xx_write_page(struct phy_device *phydev, int page)
{
	return __phy_write(phydev, VSC73XX_EXT_PAGE_ACCESS, page);
}

__attribute__((used)) static void vsc73xx_config_init(struct phy_device *phydev)
{
	/* Receiver init */
	phy_write(phydev, 0x1f, 0x2a30);
	phy_modify(phydev, 0x0c, 0x0300, 0x0200);
	phy_write(phydev, 0x1f, 0x0000);

	/* Config LEDs 0x61 */
	phy_modify(phydev, MII_TPISTATUS, 0xff00, 0x0061);
}

__attribute__((used)) static int vsc738x_config_init(struct phy_device *phydev)
{
	u16 rev;
	/* This magic sequence appear in the application note
	 * "VSC7385/7388 PHY Configuration".
	 *
	 * Maybe one day we will get to know what it all means.
	 */
	phy_write(phydev, 0x1f, 0x2a30);
	phy_modify(phydev, 0x08, 0x0200, 0x0200);
	phy_write(phydev, 0x1f, 0x52b5);
	phy_write(phydev, 0x10, 0xb68a);
	phy_modify(phydev, 0x12, 0xff07, 0x0003);
	phy_modify(phydev, 0x11, 0x00ff, 0x00a2);
	phy_write(phydev, 0x10, 0x968a);
	phy_write(phydev, 0x1f, 0x2a30);
	phy_modify(phydev, 0x08, 0x0200, 0x0000);
	phy_write(phydev, 0x1f, 0x0000);

	/* Read revision */
	rev = phy_read(phydev, MII_PHYSID2);
	rev &= 0x0f;

	/* Special quirk for revision 0 */
	if (rev == 0) {
		phy_write(phydev, 0x1f, 0x2a30);
		phy_modify(phydev, 0x08, 0x0200, 0x0200);
		phy_write(phydev, 0x1f, 0x52b5);
		phy_write(phydev, 0x12, 0x0000);
		phy_write(phydev, 0x11, 0x0689);
		phy_write(phydev, 0x10, 0x8f92);
		phy_write(phydev, 0x1f, 0x52b5);
		phy_write(phydev, 0x12, 0x0000);
		phy_write(phydev, 0x11, 0x0e35);
		phy_write(phydev, 0x10, 0x9786);
		phy_write(phydev, 0x1f, 0x2a30);
		phy_modify(phydev, 0x08, 0x0200, 0x0000);
		phy_write(phydev, 0x17, 0xff80);
		phy_write(phydev, 0x17, 0x0000);
	}

	phy_write(phydev, 0x1f, 0x0000);
	phy_write(phydev, 0x12, 0x0048);

	if (rev == 0) {
		phy_write(phydev, 0x1f, 0x2a30);
		phy_write(phydev, 0x14, 0x6600);
		phy_write(phydev, 0x1f, 0x0000);
		phy_write(phydev, 0x18, 0xa24e);
	} else {
		phy_write(phydev, 0x1f, 0x2a30);
		phy_modify(phydev, 0x16, 0x0fc0, 0x0240);
		phy_modify(phydev, 0x14, 0x6000, 0x4000);
		/* bits 14-15 in extended register 0x14 controls DACG amplitude
		 * 6 = -8%, 2 is hardware default
		 */
		phy_write(phydev, 0x1f, 0x0001);
		phy_modify(phydev, 0x14, 0xe000, 0x6000);
		phy_write(phydev, 0x1f, 0x0000);
	}

	vsc73xx_config_init(phydev);

	return genphy_config_init(phydev);
}

__attribute__((used)) static int vsc739x_config_init(struct phy_device *phydev)
{
	/* This magic sequence appears in the VSC7395 SparX-G5e application
	 * note "VSC7395/VSC7398 PHY Configuration"
	 *
	 * Maybe one day we will get to know what it all means.
	 */
	phy_write(phydev, 0x1f, 0x2a30);
	phy_modify(phydev, 0x08, 0x0200, 0x0200);
	phy_write(phydev, 0x1f, 0x52b5);
	phy_write(phydev, 0x10, 0xb68a);
	phy_modify(phydev, 0x12, 0xff07, 0x0003);
	phy_modify(phydev, 0x11, 0x00ff, 0x00a2);
	phy_write(phydev, 0x10, 0x968a);
	phy_write(phydev, 0x1f, 0x2a30);
	phy_modify(phydev, 0x08, 0x0200, 0x0000);
	phy_write(phydev, 0x1f, 0x0000);

	phy_write(phydev, 0x1f, 0x0000);
	phy_write(phydev, 0x12, 0x0048);
	phy_write(phydev, 0x1f, 0x2a30);
	phy_modify(phydev, 0x16, 0x0fc0, 0x0240);
	phy_modify(phydev, 0x14, 0x6000, 0x4000);
	phy_write(phydev, 0x1f, 0x0001);
	phy_modify(phydev, 0x14, 0xe000, 0x6000);
	phy_write(phydev, 0x1f, 0x0000);

	vsc73xx_config_init(phydev);

	return genphy_config_init(phydev);
}

__attribute__((used)) static int vsc73xx_config_aneg(struct phy_device *phydev)
{
	/* The VSC73xx switches does not like to be instructed to
	 * do autonegotiation in any way, it prefers that you just go
	 * with the power-on/reset defaults. Writing some registers will
	 * just make autonegotiation permanently fail.
	 */
	return 0;
}

__attribute__((used)) static int vsc8601_add_skew(struct phy_device *phydev)
{
	int ret;

	ret = phy_read(phydev, MII_VSC8601_EPHY_CTL);
	if (ret < 0)
		return ret;

	ret |= MII_VSC8601_EPHY_CTL_RGMII_SKEW;
	return phy_write(phydev, MII_VSC8601_EPHY_CTL, ret);
}

__attribute__((used)) static int vsc8601_config_init(struct phy_device *phydev)
{
	int ret = 0;

	if (phydev->interface == PHY_INTERFACE_MODE_RGMII_ID)
		ret = vsc8601_add_skew(phydev);

	if (ret < 0)
		return ret;

	return genphy_config_init(phydev);
}

__attribute__((used)) static int vsc824x_ack_interrupt(struct phy_device *phydev)
{
	int err = 0;

	/* Don't bother to ACK the interrupts if interrupts
	 * are disabled.  The 824x cannot clear the interrupts
	 * if they are disabled.
	 */
	if (phydev->interrupts == PHY_INTERRUPT_ENABLED)
		err = phy_read(phydev, MII_VSC8244_ISTAT);

	return (err < 0) ? err : 0;
}

__attribute__((used)) static int vsc82xx_config_intr(struct phy_device *phydev)
{
	int err;

	if (phydev->interrupts == PHY_INTERRUPT_ENABLED)
		err = phy_write(phydev, MII_VSC8244_IMASK,
			(phydev->drv->phy_id == PHY_ID_VSC8234 ||
			 phydev->drv->phy_id == PHY_ID_VSC8244 ||
			 phydev->drv->phy_id == PHY_ID_VSC8514 ||
			 phydev->drv->phy_id == PHY_ID_VSC8572 ||
			 phydev->drv->phy_id == PHY_ID_VSC8574 ||
			 phydev->drv->phy_id == PHY_ID_VSC8601) ?
				MII_VSC8244_IMASK_MASK :
				MII_VSC8221_IMASK_MASK);
	else {
		/* The Vitesse PHY cannot clear the interrupt
		 * once it has disabled them, so we clear them first
		 */
		err = phy_read(phydev, MII_VSC8244_ISTAT);

		if (err < 0)
			return err;

		err = phy_write(phydev, MII_VSC8244_IMASK, 0);
	}

	return err;
}

__attribute__((used)) static int vsc8221_config_init(struct phy_device *phydev)
{
	int err;

	err = phy_write(phydev, MII_VSC8244_AUX_CONSTAT,
			MII_VSC8221_AUXCONSTAT_INIT);
	return err;

	/* Perhaps we should set EXT_CON1 based on the interface?
	 * Options are 802.3Z SerDes or SGMII
	 */
}

__attribute__((used)) static int vsc82x4_config_autocross_enable(struct phy_device *phydev)
{
	int ret;

	if (phydev->autoneg == AUTONEG_ENABLE || phydev->speed > SPEED_100)
		return 0;

	/* map extended registers set 0x10 - 0x1e */
	ret = phy_write(phydev, MII_VSC82X4_EXT_PAGE_ACCESS, 0x52b5);
	if (ret >= 0)
		ret = phy_write(phydev, MII_VSC82X4_EXT_PAGE_18E, 0x0012);
	if (ret >= 0)
		ret = phy_write(phydev, MII_VSC82X4_EXT_PAGE_17E, 0x2803);
	if (ret >= 0)
		ret = phy_write(phydev, MII_VSC82X4_EXT_PAGE_16E, 0x87fa);
	/* map standard registers set 0x10 - 0x1e */
	if (ret >= 0)
		ret = phy_write(phydev, MII_VSC82X4_EXT_PAGE_ACCESS, 0x0000);
	else
		phy_write(phydev, MII_VSC82X4_EXT_PAGE_ACCESS, 0x0000);

	return ret;
}

__attribute__((used)) static int vsc82x4_config_aneg(struct phy_device *phydev)
{
	int ret;

	/* Enable auto MDI/MDI-X when in 10/100 forced link speeds by
	 * writing special values in the VSC8234 extended reserved registers
	 */
	if (phydev->autoneg != AUTONEG_ENABLE && phydev->speed <= SPEED_100) {
		ret = genphy_setup_forced(phydev);

		if (ret < 0) /* error */
			return ret;

		return vsc82x4_config_autocross_enable(phydev);
	}

	return genphy_config_aneg(phydev);
}

