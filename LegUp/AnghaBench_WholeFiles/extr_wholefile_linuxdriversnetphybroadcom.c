#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u64 ;
typedef  int u32 ;
typedef  int u16 ;
struct TYPE_7__ {struct device_node* of_node; } ;
struct TYPE_6__ {TYPE_3__ dev; } ;
struct phy_device {int dev_flags; scalar_t__ interface; scalar_t__ interrupts; struct bcm53xx_phy_priv* priv; TYPE_2__ mdio; void* duplex; void* speed; scalar_t__ link; int /*<<< orphan*/  autoneg; TYPE_1__* drv; } ;
struct ethtool_stats {int dummy; } ;
struct device_node {int dummy; } ;
struct bcm53xx_phy_priv {int /*<<< orphan*/  stats; } ;
struct TYPE_5__ {scalar_t__ phy_id; } ;

/* Variables and functions */
 int /*<<< orphan*/  AUTONEG_DISABLE ; 
 int BCM54612E_EXP_SPARE0 ; 
 int BCM54612E_LED4_CLK125OUT_EN ; 
 int BCM54810_EXP_BROADREACH_LRE_MISC_CTL ; 
 int BCM54810_EXP_BROADREACH_LRE_MISC_CTL_EN ; 
 int BCM54810_SHD_CLK_CTL ; 
 int BCM54810_SHD_CLK_CTL_GTXCLK_EN ; 
 int BCM5482_SHD_LEDS1 ; 
 int BCM5482_SHD_LEDS1_LED1 (int /*<<< orphan*/ ) ; 
 int BCM5482_SHD_LEDS1_LED3 (int /*<<< orphan*/ ) ; 
 int BCM5482_SHD_MODE ; 
 int BCM5482_SHD_MODE_1000BX ; 
 int BCM5482_SHD_SSD ; 
 int BCM5482_SHD_SSD_EN ; 
 int BCM5482_SHD_SSD_LEDM ; 
 int BCM5482_SSD_1000BX_CTL ; 
 int BCM5482_SSD_1000BX_CTL_PWRDOWN ; 
 int BCM5482_SSD_SGMII_SLAVE ; 
 int BCM5482_SSD_SGMII_SLAVE_AD ; 
 int BCM5482_SSD_SGMII_SLAVE_EN ; 
 int BCM54XX_SHD_APD ; 
 int BCM54XX_SHD_APD_EN ; 
 int BCM54XX_SHD_RGMII_MODE ; 
 int BCM54XX_SHD_SCR3 ; 
 int BCM54XX_SHD_SCR3_DEF_CLK125 ; 
 int BCM54XX_SHD_SCR3_DLLAPD_DIS ; 
 int BCM54XX_SHD_SCR3_TRDDAPD ; 
 int /*<<< orphan*/  BCM_LED_SRC_ACTIVITYLED ; 
 int /*<<< orphan*/  BCM_LED_SRC_LINKSPD2 ; 
 int BMCR_RESET ; 
 scalar_t__ BRCM_PHY_MODEL (struct phy_device*) ; 
 int BRCM_PHY_REV (struct phy_device*) ; 
 int CTL1000_AS_MASTER ; 
 int CTL1000_ENABLE_MASTER ; 
 void* DUPLEX_FULL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int MII_BCM54XX_AUXCTL_ACTL_SMDSP_ENA ; 
 int MII_BCM54XX_AUXCTL_ACTL_TX_6DB ; 
 int MII_BCM54XX_AUXCTL_MISC_WREN ; 
 int /*<<< orphan*/  MII_BCM54XX_AUXCTL_SHDWSEL_AUXCTL ; 
 int MII_BCM54XX_AUXCTL_SHDWSEL_MASK ; 
 int /*<<< orphan*/  MII_BCM54XX_AUXCTL_SHDWSEL_MISC ; 
 int MII_BCM54XX_AUXCTL_SHDWSEL_MISC_RGMII_SKEW_EN ; 
 int MII_BCM54XX_ECR ; 
 int MII_BCM54XX_ECR_IM ; 
 int MII_BCM54XX_EXP_AADJ1CH0 ; 
 int MII_BCM54XX_EXP_AADJ1CH0_SWP_ABCD_OEN ; 
 int MII_BCM54XX_EXP_AADJ1CH0_SWSEL_THPF ; 
 int MII_BCM54XX_EXP_AADJ1CH3 ; 
 int MII_BCM54XX_EXP_AADJ1CH3_ADCCKADJ ; 
 int MII_BCM54XX_EXP_EXP08 ; 
 int MII_BCM54XX_EXP_EXP08_RJCT_2MHZ ; 
 int MII_BCM54XX_EXP_EXP75 ; 
 int MII_BCM54XX_EXP_EXP75_CM_OSC ; 
 int MII_BCM54XX_EXP_EXP75_VDACCTRL ; 
 int MII_BCM54XX_EXP_EXP96 ; 
 int MII_BCM54XX_EXP_EXP96_MYST ; 
 int MII_BCM54XX_EXP_EXP97 ; 
 int MII_BCM54XX_EXP_EXP97_MYST ; 
 int MII_BCM54XX_EXP_SEL_ER ; 
 int MII_BCM54XX_EXP_SEL_SSD ; 
 int MII_BCM54XX_IMR ; 
 int MII_BCM54XX_INT_DUPLEX ; 
 int MII_BCM54XX_INT_LINK ; 
 int MII_BCM54XX_INT_SPEED ; 
 int MII_BMCR ; 
 int MII_BRCM_FET_BRCMTEST ; 
 int MII_BRCM_FET_BT_SRE ; 
 int MII_BRCM_FET_INTREG ; 
 int MII_BRCM_FET_IR_DUPLEX_EN ; 
 int MII_BRCM_FET_IR_ENABLE ; 
 int MII_BRCM_FET_IR_LINK_EN ; 
 int MII_BRCM_FET_IR_MASK ; 
 int MII_BRCM_FET_IR_SPEED_EN ; 
 int MII_BRCM_FET_SHDW_AM4_LED_MASK ; 
 int MII_BRCM_FET_SHDW_AM4_LED_MODE1 ; 
 int MII_BRCM_FET_SHDW_AS2_APDE ; 
 int MII_BRCM_FET_SHDW_AUXMODE4 ; 
 int MII_BRCM_FET_SHDW_AUXSTAT2 ; 
 int MII_BRCM_FET_SHDW_MC_FAME ; 
 int MII_BRCM_FET_SHDW_MISCCTRL ; 
 int MII_CTRL1000 ; 
 int PHY_BCM_FLAGS_MODE_1000BX ; 
 int PHY_BRCM_AUTO_PWRDWN_ENABLE ; 
 int PHY_BRCM_CLEAR_RGMII_MODE ; 
 int PHY_BRCM_DIS_TXCRXC_NOENRGY ; 
 int PHY_BRCM_EN_MASTER_MODE ; 
 int PHY_BRCM_RX_REFCLK_UNUSED ; 
 scalar_t__ PHY_ID_BCM50610 ; 
 scalar_t__ PHY_ID_BCM50610M ; 
 scalar_t__ PHY_ID_BCM54210E ; 
 scalar_t__ PHY_ID_BCM54612E ; 
 scalar_t__ PHY_ID_BCM54810 ; 
 scalar_t__ PHY_ID_BCM57780 ; 
 scalar_t__ PHY_INTERFACE_MODE_RGMII ; 
 scalar_t__ PHY_INTERFACE_MODE_RGMII_ID ; 
 scalar_t__ PHY_INTERFACE_MODE_RGMII_RXID ; 
 scalar_t__ PHY_INTERFACE_MODE_RGMII_TXID ; 
 scalar_t__ PHY_INTERRUPT_ENABLED ; 
 void* SPEED_1000 ; 
 int bcm54xx_auxctl_read (struct phy_device*,int /*<<< orphan*/ ) ; 
 int bcm54xx_auxctl_write (struct phy_device*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  bcm_phy_get_sset_count (struct phy_device*) ; 
 int /*<<< orphan*/  bcm_phy_get_stats (struct phy_device*,int /*<<< orphan*/ ,struct ethtool_stats*,int /*<<< orphan*/ *) ; 
 int bcm_phy_read_exp (struct phy_device*,int) ; 
 int bcm_phy_read_shadow (struct phy_device*,int) ; 
 int bcm_phy_write_exp (struct phy_device*,int,int) ; 
 int bcm_phy_write_shadow (struct phy_device*,int,int) ; 
 int /*<<< orphan*/  devm_kcalloc (TYPE_3__*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 struct bcm53xx_phy_priv* devm_kzalloc (TYPE_3__*,int,int /*<<< orphan*/ ) ; 
 int genphy_config_aneg (struct phy_device*) ; 
 int genphy_read_status (struct phy_device*) ; 
 scalar_t__ of_property_read_bool (struct device_node*,char*) ; 
 int phy_read (struct phy_device*,int) ; 
 int phy_write (struct phy_device*,int,int) ; 

__attribute__((used)) static inline int bcm_phy_write_exp_sel(struct phy_device *phydev,
					u16 reg, u16 val)
{
	return bcm_phy_write_exp(phydev, reg | MII_BCM54XX_EXP_SEL_ER, val);
}

__attribute__((used)) static int bcm54210e_config_init(struct phy_device *phydev)
{
	int val;

	val = bcm54xx_auxctl_read(phydev, MII_BCM54XX_AUXCTL_SHDWSEL_MISC);
	val &= ~MII_BCM54XX_AUXCTL_SHDWSEL_MISC_RGMII_SKEW_EN;
	val |= MII_BCM54XX_AUXCTL_MISC_WREN;
	bcm54xx_auxctl_write(phydev, MII_BCM54XX_AUXCTL_SHDWSEL_MISC, val);

	val = bcm_phy_read_shadow(phydev, BCM54810_SHD_CLK_CTL);
	val &= ~BCM54810_SHD_CLK_CTL_GTXCLK_EN;
	bcm_phy_write_shadow(phydev, BCM54810_SHD_CLK_CTL, val);

	if (phydev->dev_flags & PHY_BRCM_EN_MASTER_MODE) {
		val = phy_read(phydev, MII_CTRL1000);
		val |= CTL1000_AS_MASTER | CTL1000_ENABLE_MASTER;
		phy_write(phydev, MII_CTRL1000, val);
	}

	return 0;
}

__attribute__((used)) static int bcm54612e_config_init(struct phy_device *phydev)
{
	int reg;

	/* Clear TX internal delay unless requested. */
	if ((phydev->interface != PHY_INTERFACE_MODE_RGMII_ID) &&
	    (phydev->interface != PHY_INTERFACE_MODE_RGMII_TXID)) {
		/* Disable TXD to GTXCLK clock delay (default set) */
		/* Bit 9 is the only field in shadow register 00011 */
		bcm_phy_write_shadow(phydev, 0x03, 0);
	}

	/* Clear RX internal delay unless requested. */
	if ((phydev->interface != PHY_INTERFACE_MODE_RGMII_ID) &&
	    (phydev->interface != PHY_INTERFACE_MODE_RGMII_RXID)) {
		reg = bcm54xx_auxctl_read(phydev,
					  MII_BCM54XX_AUXCTL_SHDWSEL_MISC);
		/* Disable RXD to RXC delay (default set) */
		reg &= ~MII_BCM54XX_AUXCTL_SHDWSEL_MISC_RGMII_SKEW_EN;
		/* Clear shadow selector field */
		reg &= ~MII_BCM54XX_AUXCTL_SHDWSEL_MASK;
		bcm54xx_auxctl_write(phydev, MII_BCM54XX_AUXCTL_SHDWSEL_MISC,
				     MII_BCM54XX_AUXCTL_MISC_WREN | reg);
	}

	/* Enable CLK125 MUX on LED4 if ref clock is enabled. */
	if (!(phydev->dev_flags & PHY_BRCM_RX_REFCLK_UNUSED)) {
		int err;

		reg = bcm_phy_read_exp(phydev, BCM54612E_EXP_SPARE0);
		err = bcm_phy_write_exp(phydev, BCM54612E_EXP_SPARE0,
					BCM54612E_LED4_CLK125OUT_EN | reg);

		if (err < 0)
			return err;
	}

	return 0;
}

__attribute__((used)) static int bcm5481x_config(struct phy_device *phydev)
{
	int rc, val;

	/* handling PHY's internal RX clock delay */
	val = bcm54xx_auxctl_read(phydev, MII_BCM54XX_AUXCTL_SHDWSEL_MISC);
	val |= MII_BCM54XX_AUXCTL_MISC_WREN;
	if (phydev->interface == PHY_INTERFACE_MODE_RGMII ||
	    phydev->interface == PHY_INTERFACE_MODE_RGMII_TXID) {
		/* Disable RGMII RXC-RXD skew */
		val &= ~MII_BCM54XX_AUXCTL_SHDWSEL_MISC_RGMII_SKEW_EN;
	}
	if (phydev->interface == PHY_INTERFACE_MODE_RGMII_ID ||
	    phydev->interface == PHY_INTERFACE_MODE_RGMII_RXID) {
		/* Enable RGMII RXC-RXD skew */
		val |= MII_BCM54XX_AUXCTL_SHDWSEL_MISC_RGMII_SKEW_EN;
	}
	rc = bcm54xx_auxctl_write(phydev, MII_BCM54XX_AUXCTL_SHDWSEL_MISC,
				  val);
	if (rc < 0)
		return rc;

	/* handling PHY's internal TX clock delay */
	val = bcm_phy_read_shadow(phydev, BCM54810_SHD_CLK_CTL);
	if (phydev->interface == PHY_INTERFACE_MODE_RGMII ||
	    phydev->interface == PHY_INTERFACE_MODE_RGMII_RXID) {
		/* Disable internal TX clock delay */
		val &= ~BCM54810_SHD_CLK_CTL_GTXCLK_EN;
	}
	if (phydev->interface == PHY_INTERFACE_MODE_RGMII_ID ||
	    phydev->interface == PHY_INTERFACE_MODE_RGMII_TXID) {
		/* Enable internal TX clock delay */
		val |= BCM54810_SHD_CLK_CTL_GTXCLK_EN;
	}
	rc = bcm_phy_write_shadow(phydev, BCM54810_SHD_CLK_CTL, val);
	if (rc < 0)
		return rc;

	return 0;
}

__attribute__((used)) static int bcm50610_a0_workaround(struct phy_device *phydev)
{
	int err;

	err = bcm_phy_write_exp(phydev, MII_BCM54XX_EXP_AADJ1CH0,
				MII_BCM54XX_EXP_AADJ1CH0_SWP_ABCD_OEN |
				MII_BCM54XX_EXP_AADJ1CH0_SWSEL_THPF);
	if (err < 0)
		return err;

	err = bcm_phy_write_exp(phydev, MII_BCM54XX_EXP_AADJ1CH3,
				MII_BCM54XX_EXP_AADJ1CH3_ADCCKADJ);
	if (err < 0)
		return err;

	err = bcm_phy_write_exp(phydev, MII_BCM54XX_EXP_EXP75,
				MII_BCM54XX_EXP_EXP75_VDACCTRL);
	if (err < 0)
		return err;

	err = bcm_phy_write_exp(phydev, MII_BCM54XX_EXP_EXP96,
				MII_BCM54XX_EXP_EXP96_MYST);
	if (err < 0)
		return err;

	err = bcm_phy_write_exp(phydev, MII_BCM54XX_EXP_EXP97,
				MII_BCM54XX_EXP_EXP97_MYST);

	return err;
}

__attribute__((used)) static int bcm54xx_phydsp_config(struct phy_device *phydev)
{
	int err, err2;

	/* Enable the SMDSP clock */
	err = bcm54xx_auxctl_write(phydev,
				   MII_BCM54XX_AUXCTL_SHDWSEL_AUXCTL,
				   MII_BCM54XX_AUXCTL_ACTL_SMDSP_ENA |
				   MII_BCM54XX_AUXCTL_ACTL_TX_6DB);
	if (err < 0)
		return err;

	if (BRCM_PHY_MODEL(phydev) == PHY_ID_BCM50610 ||
	    BRCM_PHY_MODEL(phydev) == PHY_ID_BCM50610M) {
		/* Clear bit 9 to fix a phy interop issue. */
		err = bcm_phy_write_exp(phydev, MII_BCM54XX_EXP_EXP08,
					MII_BCM54XX_EXP_EXP08_RJCT_2MHZ);
		if (err < 0)
			goto error;

		if (phydev->drv->phy_id == PHY_ID_BCM50610) {
			err = bcm50610_a0_workaround(phydev);
			if (err < 0)
				goto error;
		}
	}

	if (BRCM_PHY_MODEL(phydev) == PHY_ID_BCM57780) {
		int val;

		val = bcm_phy_read_exp(phydev, MII_BCM54XX_EXP_EXP75);
		if (val < 0)
			goto error;

		val |= MII_BCM54XX_EXP_EXP75_CM_OSC;
		err = bcm_phy_write_exp(phydev, MII_BCM54XX_EXP_EXP75, val);
	}

error:
	/* Disable the SMDSP clock */
	err2 = bcm54xx_auxctl_write(phydev,
				    MII_BCM54XX_AUXCTL_SHDWSEL_AUXCTL,
				    MII_BCM54XX_AUXCTL_ACTL_TX_6DB);

	/* Return the first error reported. */
	return err ? err : err2;
}

__attribute__((used)) static void bcm54xx_adjust_rxrefclk(struct phy_device *phydev)
{
	u32 orig;
	int val;
	bool clk125en = true;

	/* Abort if we are using an untested phy. */
	if (BRCM_PHY_MODEL(phydev) != PHY_ID_BCM57780 &&
	    BRCM_PHY_MODEL(phydev) != PHY_ID_BCM50610 &&
	    BRCM_PHY_MODEL(phydev) != PHY_ID_BCM50610M)
		return;

	val = bcm_phy_read_shadow(phydev, BCM54XX_SHD_SCR3);
	if (val < 0)
		return;

	orig = val;

	if ((BRCM_PHY_MODEL(phydev) == PHY_ID_BCM50610 ||
	     BRCM_PHY_MODEL(phydev) == PHY_ID_BCM50610M) &&
	    BRCM_PHY_REV(phydev) >= 0x3) {
		/*
		 * Here, bit 0 _disables_ CLK125 when set.
		 * This bit is set by default.
		 */
		clk125en = false;
	} else {
		if (phydev->dev_flags & PHY_BRCM_RX_REFCLK_UNUSED) {
			/* Here, bit 0 _enables_ CLK125 when set */
			val &= ~BCM54XX_SHD_SCR3_DEF_CLK125;
			clk125en = false;
		}
	}

	if (!clk125en || (phydev->dev_flags & PHY_BRCM_AUTO_PWRDWN_ENABLE))
		val &= ~BCM54XX_SHD_SCR3_DLLAPD_DIS;
	else
		val |= BCM54XX_SHD_SCR3_DLLAPD_DIS;

	if (phydev->dev_flags & PHY_BRCM_DIS_TXCRXC_NOENRGY)
		val |= BCM54XX_SHD_SCR3_TRDDAPD;

	if (orig != val)
		bcm_phy_write_shadow(phydev, BCM54XX_SHD_SCR3, val);

	val = bcm_phy_read_shadow(phydev, BCM54XX_SHD_APD);
	if (val < 0)
		return;

	orig = val;

	if (!clk125en || (phydev->dev_flags & PHY_BRCM_AUTO_PWRDWN_ENABLE))
		val |= BCM54XX_SHD_APD_EN;
	else
		val &= ~BCM54XX_SHD_APD_EN;

	if (orig != val)
		bcm_phy_write_shadow(phydev, BCM54XX_SHD_APD, val);
}

__attribute__((used)) static int bcm54xx_config_init(struct phy_device *phydev)
{
	int reg, err, val;

	reg = phy_read(phydev, MII_BCM54XX_ECR);
	if (reg < 0)
		return reg;

	/* Mask interrupts globally.  */
	reg |= MII_BCM54XX_ECR_IM;
	err = phy_write(phydev, MII_BCM54XX_ECR, reg);
	if (err < 0)
		return err;

	/* Unmask events we are interested in.  */
	reg = ~(MII_BCM54XX_INT_DUPLEX |
		MII_BCM54XX_INT_SPEED |
		MII_BCM54XX_INT_LINK);
	err = phy_write(phydev, MII_BCM54XX_IMR, reg);
	if (err < 0)
		return err;

	if ((BRCM_PHY_MODEL(phydev) == PHY_ID_BCM50610 ||
	     BRCM_PHY_MODEL(phydev) == PHY_ID_BCM50610M) &&
	    (phydev->dev_flags & PHY_BRCM_CLEAR_RGMII_MODE))
		bcm_phy_write_shadow(phydev, BCM54XX_SHD_RGMII_MODE, 0);

	if ((phydev->dev_flags & PHY_BRCM_RX_REFCLK_UNUSED) ||
	    (phydev->dev_flags & PHY_BRCM_DIS_TXCRXC_NOENRGY) ||
	    (phydev->dev_flags & PHY_BRCM_AUTO_PWRDWN_ENABLE))
		bcm54xx_adjust_rxrefclk(phydev);

	if (BRCM_PHY_MODEL(phydev) == PHY_ID_BCM54210E) {
		err = bcm54210e_config_init(phydev);
		if (err)
			return err;
	} else if (BRCM_PHY_MODEL(phydev) == PHY_ID_BCM54612E) {
		err = bcm54612e_config_init(phydev);
		if (err)
			return err;
	} else if (BRCM_PHY_MODEL(phydev) == PHY_ID_BCM54810) {
		/* For BCM54810, we need to disable BroadR-Reach function */
		val = bcm_phy_read_exp(phydev,
				       BCM54810_EXP_BROADREACH_LRE_MISC_CTL);
		val &= ~BCM54810_EXP_BROADREACH_LRE_MISC_CTL_EN;
		err = bcm_phy_write_exp(phydev,
					BCM54810_EXP_BROADREACH_LRE_MISC_CTL,
					val);
		if (err < 0)
			return err;
	}

	bcm54xx_phydsp_config(phydev);

	return 0;
}

__attribute__((used)) static int bcm5482_config_init(struct phy_device *phydev)
{
	int err, reg;

	err = bcm54xx_config_init(phydev);

	if (phydev->dev_flags & PHY_BCM_FLAGS_MODE_1000BX) {
		/*
		 * Enable secondary SerDes and its use as an LED source
		 */
		reg = bcm_phy_read_shadow(phydev, BCM5482_SHD_SSD);
		bcm_phy_write_shadow(phydev, BCM5482_SHD_SSD,
				     reg |
				     BCM5482_SHD_SSD_LEDM |
				     BCM5482_SHD_SSD_EN);

		/*
		 * Enable SGMII slave mode and auto-detection
		 */
		reg = BCM5482_SSD_SGMII_SLAVE | MII_BCM54XX_EXP_SEL_SSD;
		err = bcm_phy_read_exp(phydev, reg);
		if (err < 0)
			return err;
		err = bcm_phy_write_exp(phydev, reg, err |
					BCM5482_SSD_SGMII_SLAVE_EN |
					BCM5482_SSD_SGMII_SLAVE_AD);
		if (err < 0)
			return err;

		/*
		 * Disable secondary SerDes powerdown
		 */
		reg = BCM5482_SSD_1000BX_CTL | MII_BCM54XX_EXP_SEL_SSD;
		err = bcm_phy_read_exp(phydev, reg);
		if (err < 0)
			return err;
		err = bcm_phy_write_exp(phydev, reg,
					err & ~BCM5482_SSD_1000BX_CTL_PWRDOWN);
		if (err < 0)
			return err;

		/*
		 * Select 1000BASE-X register set (primary SerDes)
		 */
		reg = bcm_phy_read_shadow(phydev, BCM5482_SHD_MODE);
		bcm_phy_write_shadow(phydev, BCM5482_SHD_MODE,
				     reg | BCM5482_SHD_MODE_1000BX);

		/*
		 * LED1=ACTIVITYLED, LED3=LINKSPD[2]
		 * (Use LED1 as secondary SerDes ACTIVITY LED)
		 */
		bcm_phy_write_shadow(phydev, BCM5482_SHD_LEDS1,
			BCM5482_SHD_LEDS1_LED1(BCM_LED_SRC_ACTIVITYLED) |
			BCM5482_SHD_LEDS1_LED3(BCM_LED_SRC_LINKSPD2));

		/*
		 * Auto-negotiation doesn't seem to work quite right
		 * in this mode, so we disable it and force it to the
		 * right speed/duplex setting.  Only 'link status'
		 * is important.
		 */
		phydev->autoneg = AUTONEG_DISABLE;
		phydev->speed = SPEED_1000;
		phydev->duplex = DUPLEX_FULL;
	}

	return err;
}

__attribute__((used)) static int bcm5482_read_status(struct phy_device *phydev)
{
	int err;

	err = genphy_read_status(phydev);

	if (phydev->dev_flags & PHY_BCM_FLAGS_MODE_1000BX) {
		/*
		 * Only link status matters for 1000Base-X mode, so force
		 * 1000 Mbit/s full-duplex status
		 */
		if (phydev->link) {
			phydev->speed = SPEED_1000;
			phydev->duplex = DUPLEX_FULL;
		}
	}

	return err;
}

__attribute__((used)) static int bcm5481_config_aneg(struct phy_device *phydev)
{
	struct device_node *np = phydev->mdio.dev.of_node;
	int ret;

	/* Aneg firsly. */
	ret = genphy_config_aneg(phydev);

	/* Then we can set up the delay. */
	bcm5481x_config(phydev);

	if (of_property_read_bool(np, "enet-phy-lane-swap")) {
		/* Lane Swap - Undocumented register...magic! */
		ret = bcm_phy_write_exp(phydev, MII_BCM54XX_EXP_SEL_ER + 0x9,
					0x11B);
		if (ret < 0)
			return ret;
	}

	return ret;
}

__attribute__((used)) static int brcm_phy_setbits(struct phy_device *phydev, int reg, int set)
{
	int val;

	val = phy_read(phydev, reg);
	if (val < 0)
		return val;

	return phy_write(phydev, reg, val | set);
}

__attribute__((used)) static int brcm_fet_config_init(struct phy_device *phydev)
{
	int reg, err, err2, brcmtest;

	/* Reset the PHY to bring it to a known state. */
	err = phy_write(phydev, MII_BMCR, BMCR_RESET);
	if (err < 0)
		return err;

	reg = phy_read(phydev, MII_BRCM_FET_INTREG);
	if (reg < 0)
		return reg;

	/* Unmask events we are interested in and mask interrupts globally. */
	reg = MII_BRCM_FET_IR_DUPLEX_EN |
	      MII_BRCM_FET_IR_SPEED_EN |
	      MII_BRCM_FET_IR_LINK_EN |
	      MII_BRCM_FET_IR_ENABLE |
	      MII_BRCM_FET_IR_MASK;

	err = phy_write(phydev, MII_BRCM_FET_INTREG, reg);
	if (err < 0)
		return err;

	/* Enable shadow register access */
	brcmtest = phy_read(phydev, MII_BRCM_FET_BRCMTEST);
	if (brcmtest < 0)
		return brcmtest;

	reg = brcmtest | MII_BRCM_FET_BT_SRE;

	err = phy_write(phydev, MII_BRCM_FET_BRCMTEST, reg);
	if (err < 0)
		return err;

	/* Set the LED mode */
	reg = phy_read(phydev, MII_BRCM_FET_SHDW_AUXMODE4);
	if (reg < 0) {
		err = reg;
		goto done;
	}

	reg &= ~MII_BRCM_FET_SHDW_AM4_LED_MASK;
	reg |= MII_BRCM_FET_SHDW_AM4_LED_MODE1;

	err = phy_write(phydev, MII_BRCM_FET_SHDW_AUXMODE4, reg);
	if (err < 0)
		goto done;

	/* Enable auto MDIX */
	err = brcm_phy_setbits(phydev, MII_BRCM_FET_SHDW_MISCCTRL,
				       MII_BRCM_FET_SHDW_MC_FAME);
	if (err < 0)
		goto done;

	if (phydev->dev_flags & PHY_BRCM_AUTO_PWRDWN_ENABLE) {
		/* Enable auto power down */
		err = brcm_phy_setbits(phydev, MII_BRCM_FET_SHDW_AUXSTAT2,
					       MII_BRCM_FET_SHDW_AS2_APDE);
	}

done:
	/* Disable shadow register access */
	err2 = phy_write(phydev, MII_BRCM_FET_BRCMTEST, brcmtest);
	if (!err)
		err = err2;

	return err;
}

__attribute__((used)) static int brcm_fet_ack_interrupt(struct phy_device *phydev)
{
	int reg;

	/* Clear pending interrupts.  */
	reg = phy_read(phydev, MII_BRCM_FET_INTREG);
	if (reg < 0)
		return reg;

	return 0;
}

__attribute__((used)) static int brcm_fet_config_intr(struct phy_device *phydev)
{
	int reg, err;

	reg = phy_read(phydev, MII_BRCM_FET_INTREG);
	if (reg < 0)
		return reg;

	if (phydev->interrupts == PHY_INTERRUPT_ENABLED)
		reg &= ~MII_BRCM_FET_IR_MASK;
	else
		reg |= MII_BRCM_FET_IR_MASK;

	err = phy_write(phydev, MII_BRCM_FET_INTREG, reg);
	return err;
}

__attribute__((used)) static int bcm53xx_phy_probe(struct phy_device *phydev)
{
	struct bcm53xx_phy_priv *priv;

	priv = devm_kzalloc(&phydev->mdio.dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	phydev->priv = priv;

	priv->stats = devm_kcalloc(&phydev->mdio.dev,
				   bcm_phy_get_sset_count(phydev), sizeof(u64),
				   GFP_KERNEL);
	if (!priv->stats)
		return -ENOMEM;

	return 0;
}

__attribute__((used)) static void bcm53xx_phy_get_stats(struct phy_device *phydev,
				  struct ethtool_stats *stats, u64 *data)
{
	struct bcm53xx_phy_priv *priv = phydev->priv;

	bcm_phy_get_stats(phydev, priv->stats, stats, data);
}

