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
typedef  int u16 ;
struct phy_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  MII_BCM54XX_AUX_CTL ; 
 int /*<<< orphan*/  MII_BCM54XX_ECR ; 
 int MII_BCM54XX_ECR_IM ; 
 int MII_BCM54XX_EXP_SEL_ER ; 
 int /*<<< orphan*/  MII_BCM54XX_IMR ; 
 int MII_BCM54XX_INT_DUPLEX ; 
 int MII_BCM54XX_INT_LINK ; 
 int MII_BCM54XX_INT_SPEED ; 
 int /*<<< orphan*/  MII_BRCM_CORE_BASE1E ; 
 int MII_BRCM_CORE_EXPB0 ; 
 int MII_BRCM_CORE_EXPB1 ; 
 int bcm_phy_enable_apd (struct phy_device*,int) ; 
 int bcm_phy_set_eee (struct phy_device*,int) ; 
 int bcm_phy_write_exp (struct phy_device*,int,int) ; 
 int bcm_phy_write_misc (struct phy_device*,int,int,int) ; 
 int genphy_config_aneg (struct phy_device*) ; 
 int /*<<< orphan*/  genphy_resume (struct phy_device*) ; 
 int phy_read (struct phy_device*,int /*<<< orphan*/ ) ; 
 int phy_write (struct phy_device*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline int bcm_phy_write_exp_sel(struct phy_device *phydev,
					u16 reg, u16 val)
{
	return bcm_phy_write_exp(phydev, reg | MII_BCM54XX_EXP_SEL_ER, val);
}

__attribute__((used)) static int bcm_cygnus_afe_config(struct phy_device *phydev)
{
	int rc;

	/* ensure smdspclk is enabled */
	rc = phy_write(phydev, MII_BCM54XX_AUX_CTL, 0x0c30);
	if (rc < 0)
		return rc;

	/* AFE_VDAC_ICTRL_0 bit 7:4 Iq=1100 for 1g 10bt, normal modes */
	rc = bcm_phy_write_misc(phydev, 0x39, 0x01, 0xA7C8);
	if (rc < 0)
		return rc;

	/* AFE_HPF_TRIM_OTHERS bit11=1, short cascode enable for all modes*/
	rc = bcm_phy_write_misc(phydev, 0x3A, 0x00, 0x0803);
	if (rc < 0)
		return rc;

	/* AFE_TX_CONFIG_1 bit 7:4 Iq=1100 for test modes */
	rc = bcm_phy_write_misc(phydev, 0x3A, 0x01, 0xA740);
	if (rc < 0)
		return rc;

	/* AFE TEMPSEN_OTHERS rcal_HT, rcal_LT 10000 */
	rc = bcm_phy_write_misc(phydev, 0x3A, 0x03, 0x8400);
	if (rc < 0)
		return rc;

	/* AFE_FUTURE_RSV bit 2:0 rccal <2:0>=100 */
	rc = bcm_phy_write_misc(phydev, 0x3B, 0x00, 0x0004);
	if (rc < 0)
		return rc;

	/* Adjust bias current trim to overcome digital offSet */
	rc = phy_write(phydev, MII_BRCM_CORE_BASE1E, 0x02);
	if (rc < 0)
		return rc;

	/* make rcal=100, since rdb default is 000 */
	rc = bcm_phy_write_exp_sel(phydev, MII_BRCM_CORE_EXPB1, 0x10);
	if (rc < 0)
		return rc;

	/* CORE_EXPB0, Reset R_CAL/RC_CAL Engine */
	rc = bcm_phy_write_exp_sel(phydev, MII_BRCM_CORE_EXPB0, 0x10);
	if (rc < 0)
		return rc;

	/* CORE_EXPB0, Disable Reset R_CAL/RC_CAL Engine */
	rc = bcm_phy_write_exp_sel(phydev, MII_BRCM_CORE_EXPB0, 0x00);

	return 0;
}

__attribute__((used)) static int bcm_cygnus_config_init(struct phy_device *phydev)
{
	int reg, rc;

	reg = phy_read(phydev, MII_BCM54XX_ECR);
	if (reg < 0)
		return reg;

	/* Mask interrupts globally. */
	reg |= MII_BCM54XX_ECR_IM;
	rc = phy_write(phydev, MII_BCM54XX_ECR, reg);
	if (rc)
		return rc;

	/* Unmask events of interest */
	reg = ~(MII_BCM54XX_INT_DUPLEX |
		MII_BCM54XX_INT_SPEED |
		MII_BCM54XX_INT_LINK);
	rc = phy_write(phydev, MII_BCM54XX_IMR, reg);
	if (rc)
		return rc;

	/* Apply AFE settings for the PHY */
	rc = bcm_cygnus_afe_config(phydev);
	if (rc)
		return rc;

	/* Advertise EEE */
	rc = bcm_phy_set_eee(phydev, true);
	if (rc)
		return rc;

	/* Enable APD */
	return bcm_phy_enable_apd(phydev, false);
}

__attribute__((used)) static int bcm_cygnus_resume(struct phy_device *phydev)
{
	int rc;

	genphy_resume(phydev);

	/* Re-initialize the PHY to apply AFE work-arounds and
	 * configurations when coming out of suspend.
	 */
	rc = bcm_cygnus_config_init(phydev);
	if (rc)
		return rc;

	/* restart auto negotiation with the new settings */
	return genphy_config_aneg(phydev);
}

