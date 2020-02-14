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
typedef  int u32 ;
typedef  int u16 ;
struct device {int /*<<< orphan*/  of_node; } ;
struct TYPE_2__ {struct device dev; } ;
struct phy_device {scalar_t__ interrupts; int mdix_ctrl; struct lan88xx_priv* priv; TYPE_1__ mdio; } ;
struct lan88xx_priv {scalar_t__ wolopts; void* chip_rev; void* chip_id; } ;
struct ethtool_wolinfo {scalar_t__ wolopts; } ;

/* Variables and functions */
 int ARRAY_SIZE (int*) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int EOVERFLOW ; 
#define  ETH_TP_MDI 130 
#define  ETH_TP_MDI_AUTO 129 
#define  ETH_TP_MDI_X 128 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int LAN78XX_FORCE_LED_OFF ; 
 int /*<<< orphan*/  LAN78XX_PHY_CTRL3 ; 
 int LAN78XX_PHY_CTRL3_AUTO_DOWNSHIFT ; 
 int LAN78XX_PHY_CTRL3_DOWNSHIFT_CTRL_2 ; 
 int LAN78XX_PHY_CTRL3_DOWNSHIFT_CTRL_3 ; 
 int LAN78XX_PHY_CTRL3_DOWNSHIFT_CTRL_4 ; 
 int LAN78XX_PHY_CTRL3_DOWNSHIFT_CTRL_5 ; 
 int LAN78XX_PHY_CTRL3_DOWNSHIFT_CTRL_MASK ; 
 int /*<<< orphan*/  LAN78XX_PHY_LED_MODE_SELECT ; 
 int /*<<< orphan*/  LAN88XX_EXT_MODE_CTRL ; 
 int LAN88XX_EXT_MODE_CTRL_AUTO_MDIX_ ; 
 int LAN88XX_EXT_MODE_CTRL_MDIX_MASK_ ; 
 int LAN88XX_EXT_MODE_CTRL_MDI_ ; 
 int LAN88XX_EXT_MODE_CTRL_MDI_X_ ; 
 int /*<<< orphan*/  LAN88XX_EXT_PAGE_ACCESS ; 
 int LAN88XX_EXT_PAGE_ACCESS_TR ; 
 int LAN88XX_EXT_PAGE_SPACE_0 ; 
 int LAN88XX_EXT_PAGE_SPACE_1 ; 
 int /*<<< orphan*/  LAN88XX_EXT_PAGE_TR_CR ; 
 int /*<<< orphan*/  LAN88XX_EXT_PAGE_TR_HIGH_DATA ; 
 int /*<<< orphan*/  LAN88XX_EXT_PAGE_TR_LOW_DATA ; 
 int /*<<< orphan*/  LAN88XX_INT_MASK ; 
 int LAN88XX_INT_MASK_LINK_CHANGE_ ; 
 int LAN88XX_INT_MASK_MDINTPIN_EN_ ; 
 int /*<<< orphan*/  LAN88XX_INT_STS ; 
 int /*<<< orphan*/  LAN88XX_MMD3_CHIP_ID ; 
 int /*<<< orphan*/  LAN88XX_MMD3_CHIP_REV ; 
 int MDIO_MMD_PCS ; 
 int /*<<< orphan*/  PHY_ARDENNES_MMD_DEV_3_PHY_CFG ; 
 int PHY_ARDENNES_MMD_DEV_3_PHY_CFG_ZD_DLY_EN_ ; 
 scalar_t__ PHY_INTERRUPT_ENABLED ; 
 int __phy_read (struct phy_device*,int /*<<< orphan*/ ) ; 
 int __phy_write (struct phy_device*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  devm_kfree (struct device*,struct lan88xx_priv*) ; 
 struct lan88xx_priv* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int genphy_config_aneg (struct phy_device*) ; 
 int /*<<< orphan*/  genphy_config_init (struct phy_device*) ; 
 int /*<<< orphan*/  genphy_suspend (struct phy_device*) ; 
 int /*<<< orphan*/  of_property_read_u32 (int /*<<< orphan*/ ,char*,int*) ; 
 int of_property_read_variable_u32_array (int /*<<< orphan*/ ,char*,int*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  phy_modify_paged (struct phy_device*,int,int /*<<< orphan*/ ,int,int) ; 
 int phy_read (struct phy_device*,int /*<<< orphan*/ ) ; 
 void* phy_read_mmd (struct phy_device*,int,int /*<<< orphan*/ ) ; 
 int phy_restore_page (struct phy_device*,int,int) ; 
 int phy_save_page (struct phy_device*) ; 
 int phy_write (struct phy_device*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  phy_write_mmd (struct phy_device*,int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  pr_warn (char*,...) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static int lan88xx_read_page(struct phy_device *phydev)
{
	return __phy_read(phydev, LAN88XX_EXT_PAGE_ACCESS);
}

__attribute__((used)) static int lan88xx_write_page(struct phy_device *phydev, int page)
{
	return __phy_write(phydev, LAN88XX_EXT_PAGE_ACCESS, page);
}

__attribute__((used)) static int lan88xx_phy_config_intr(struct phy_device *phydev)
{
	int rc;

	if (phydev->interrupts == PHY_INTERRUPT_ENABLED) {
		/* unmask all source and clear them before enable */
		rc = phy_write(phydev, LAN88XX_INT_MASK, 0x7FFF);
		rc = phy_read(phydev, LAN88XX_INT_STS);
		rc = phy_write(phydev, LAN88XX_INT_MASK,
			       LAN88XX_INT_MASK_MDINTPIN_EN_ |
			       LAN88XX_INT_MASK_LINK_CHANGE_);
	} else {
		rc = phy_write(phydev, LAN88XX_INT_MASK, 0);
	}

	return rc < 0 ? rc : 0;
}

__attribute__((used)) static int lan88xx_phy_ack_interrupt(struct phy_device *phydev)
{
	int rc = phy_read(phydev, LAN88XX_INT_STS);

	return rc < 0 ? rc : 0;
}

__attribute__((used)) static int lan88xx_suspend(struct phy_device *phydev)
{
	struct lan88xx_priv *priv = phydev->priv;

	/* do not power down PHY when WOL is enabled */
	if (!priv->wolopts)
		genphy_suspend(phydev);

	return 0;
}

__attribute__((used)) static int lan88xx_TR_reg_set(struct phy_device *phydev, u16 regaddr,
			      u32 data)
{
	int val, save_page, ret = 0;
	u16 buf;

	/* Save current page */
	save_page = phy_save_page(phydev);
	if (save_page < 0) {
		pr_warn("Failed to get current page\n");
		goto err;
	}

	/* Switch to TR page */
	lan88xx_write_page(phydev, LAN88XX_EXT_PAGE_ACCESS_TR);

	ret = __phy_write(phydev, LAN88XX_EXT_PAGE_TR_LOW_DATA,
			  (data & 0xFFFF));
	if (ret < 0) {
		pr_warn("Failed to write TR low data\n");
		goto err;
	}

	ret = __phy_write(phydev, LAN88XX_EXT_PAGE_TR_HIGH_DATA,
			  (data & 0x00FF0000) >> 16);
	if (ret < 0) {
		pr_warn("Failed to write TR high data\n");
		goto err;
	}

	/* Config control bits [15:13] of register */
	buf = (regaddr & ~(0x3 << 13));/* Clr [14:13] to write data in reg */
	buf |= 0x8000; /* Set [15] to Packet transmit */

	ret = __phy_write(phydev, LAN88XX_EXT_PAGE_TR_CR, buf);
	if (ret < 0) {
		pr_warn("Failed to write data in reg\n");
		goto err;
	}

	usleep_range(1000, 2000);/* Wait for Data to be written */
	val = __phy_read(phydev, LAN88XX_EXT_PAGE_TR_CR);
	if (!(val & 0x8000))
		pr_warn("TR Register[0x%X] configuration failed\n", regaddr);
err:
	return phy_restore_page(phydev, save_page, ret);
}

__attribute__((used)) static void lan88xx_config_TR_regs(struct phy_device *phydev)
{
	int err;

	/* Get access to Channel 0x1, Node 0xF , Register 0x01.
	 * Write 24-bit value 0x12B00A to register. Setting MrvlTrFix1000Kf,
	 * MrvlTrFix1000Kp, MasterEnableTR bits.
	 */
	err = lan88xx_TR_reg_set(phydev, 0x0F82, 0x12B00A);
	if (err < 0)
		pr_warn("Failed to Set Register[0x0F82]\n");

	/* Get access to Channel b'10, Node b'1101, Register 0x06.
	 * Write 24-bit value 0xD2C46F to register. Setting SSTrKf1000Slv,
	 * SSTrKp1000Mas bits.
	 */
	err = lan88xx_TR_reg_set(phydev, 0x168C, 0xD2C46F);
	if (err < 0)
		pr_warn("Failed to Set Register[0x168C]\n");

	/* Get access to Channel b'10, Node b'1111, Register 0x11.
	 * Write 24-bit value 0x620 to register. Setting rem_upd_done_thresh
	 * bits
	 */
	err = lan88xx_TR_reg_set(phydev, 0x17A2, 0x620);
	if (err < 0)
		pr_warn("Failed to Set Register[0x17A2]\n");

	/* Get access to Channel b'10, Node b'1101, Register 0x10.
	 * Write 24-bit value 0xEEFFDD to register. Setting
	 * eee_TrKp1Long_1000, eee_TrKp2Long_1000, eee_TrKp3Long_1000,
	 * eee_TrKp1Short_1000,eee_TrKp2Short_1000, eee_TrKp3Short_1000 bits.
	 */
	err = lan88xx_TR_reg_set(phydev, 0x16A0, 0xEEFFDD);
	if (err < 0)
		pr_warn("Failed to Set Register[0x16A0]\n");

	/* Get access to Channel b'10, Node b'1101, Register 0x13.
	 * Write 24-bit value 0x071448 to register. Setting
	 * slv_lpi_tr_tmr_val1, slv_lpi_tr_tmr_val2 bits.
	 */
	err = lan88xx_TR_reg_set(phydev, 0x16A6, 0x071448);
	if (err < 0)
		pr_warn("Failed to Set Register[0x16A6]\n");

	/* Get access to Channel b'10, Node b'1101, Register 0x12.
	 * Write 24-bit value 0x13132F to register. Setting
	 * slv_sigdet_timer_val1, slv_sigdet_timer_val2 bits.
	 */
	err = lan88xx_TR_reg_set(phydev, 0x16A4, 0x13132F);
	if (err < 0)
		pr_warn("Failed to Set Register[0x16A4]\n");

	/* Get access to Channel b'10, Node b'1101, Register 0x14.
	 * Write 24-bit value 0x0 to register. Setting eee_3level_delay,
	 * eee_TrKf_freeze_delay bits.
	 */
	err = lan88xx_TR_reg_set(phydev, 0x16A8, 0x0);
	if (err < 0)
		pr_warn("Failed to Set Register[0x16A8]\n");

	/* Get access to Channel b'01, Node b'1111, Register 0x34.
	 * Write 24-bit value 0x91B06C to register. Setting
	 * FastMseSearchThreshLong1000, FastMseSearchThreshShort1000,
	 * FastMseSearchUpdGain1000 bits.
	 */
	err = lan88xx_TR_reg_set(phydev, 0x0FE8, 0x91B06C);
	if (err < 0)
		pr_warn("Failed to Set Register[0x0FE8]\n");

	/* Get access to Channel b'01, Node b'1111, Register 0x3E.
	 * Write 24-bit value 0xC0A028 to register. Setting
	 * FastMseKp2ThreshLong1000, FastMseKp2ThreshShort1000,
	 * FastMseKp2UpdGain1000, FastMseKp2ExitEn1000 bits.
	 */
	err = lan88xx_TR_reg_set(phydev, 0x0FFC, 0xC0A028);
	if (err < 0)
		pr_warn("Failed to Set Register[0x0FFC]\n");

	/* Get access to Channel b'01, Node b'1111, Register 0x35.
	 * Write 24-bit value 0x041600 to register. Setting
	 * FastMseSearchPhShNum1000, FastMseSearchClksPerPh1000,
	 * FastMsePhChangeDelay1000 bits.
	 */
	err = lan88xx_TR_reg_set(phydev, 0x0FEA, 0x041600);
	if (err < 0)
		pr_warn("Failed to Set Register[0x0FEA]\n");

	/* Get access to Channel b'10, Node b'1101, Register 0x03.
	 * Write 24-bit value 0x000004 to register. Setting TrFreeze bits.
	 */
	err = lan88xx_TR_reg_set(phydev, 0x1686, 0x000004);
	if (err < 0)
		pr_warn("Failed to Set Register[0x1686]\n");
}

__attribute__((used)) static int lan88xx_probe(struct phy_device *phydev)
{
	struct device *dev = &phydev->mdio.dev;
	struct lan88xx_priv *priv;
	u32 led_modes[4];
	u32 downshift_after = 0;
	int len;

	priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	priv->wolopts = 0;

	len = of_property_read_variable_u32_array(dev->of_node,
						  "microchip,led-modes",
						  led_modes,
						  0,
						  ARRAY_SIZE(led_modes));
	if (len >= 0) {
		u32 reg = 0;
		int i;

		for (i = 0; i < len; i++) {
			if (led_modes[i] > 15)
				return -EINVAL;
			reg |= led_modes[i] << (i * 4);
		}
		for (; i < ARRAY_SIZE(led_modes); i++)
			reg |= LAN78XX_FORCE_LED_OFF << (i * 4);
		(void)phy_write(phydev, LAN78XX_PHY_LED_MODE_SELECT, reg);
	} else if (len == -EOVERFLOW) {
		return -EINVAL;
	}

	if (!of_property_read_u32(dev->of_node,
				  "microchip,downshift-after",
				  &downshift_after)) {
		u32 mask = LAN78XX_PHY_CTRL3_DOWNSHIFT_CTRL_MASK;
		u32 val = LAN78XX_PHY_CTRL3_AUTO_DOWNSHIFT;

		switch (downshift_after) {
		case 2:
			val |= LAN78XX_PHY_CTRL3_DOWNSHIFT_CTRL_2;
			break;
		case 3:
			val |= LAN78XX_PHY_CTRL3_DOWNSHIFT_CTRL_3;
			break;
		case 4:
			val |= LAN78XX_PHY_CTRL3_DOWNSHIFT_CTRL_4;
			break;
		case 5:
			val |= LAN78XX_PHY_CTRL3_DOWNSHIFT_CTRL_5;
			break;
		case 0:
			/* Disable completely */
			mask = LAN78XX_PHY_CTRL3_AUTO_DOWNSHIFT;
			val = 0;
			break;
		default:
			return -EINVAL;
		}
		(void)phy_modify_paged(phydev, 1, LAN78XX_PHY_CTRL3,
				       mask, val);
	}

	/* these values can be used to identify internal PHY */
	priv->chip_id = phy_read_mmd(phydev, 3, LAN88XX_MMD3_CHIP_ID);
	priv->chip_rev = phy_read_mmd(phydev, 3, LAN88XX_MMD3_CHIP_REV);

	phydev->priv = priv;

	return 0;
}

__attribute__((used)) static void lan88xx_remove(struct phy_device *phydev)
{
	struct device *dev = &phydev->mdio.dev;
	struct lan88xx_priv *priv = phydev->priv;

	if (priv)
		devm_kfree(dev, priv);
}

__attribute__((used)) static int lan88xx_set_wol(struct phy_device *phydev,
			   struct ethtool_wolinfo *wol)
{
	struct lan88xx_priv *priv = phydev->priv;

	priv->wolopts = wol->wolopts;

	return 0;
}

__attribute__((used)) static void lan88xx_set_mdix(struct phy_device *phydev)
{
	int buf;
	int val;

	switch (phydev->mdix_ctrl) {
	case ETH_TP_MDI:
		val = LAN88XX_EXT_MODE_CTRL_MDI_;
		break;
	case ETH_TP_MDI_X:
		val = LAN88XX_EXT_MODE_CTRL_MDI_X_;
		break;
	case ETH_TP_MDI_AUTO:
		val = LAN88XX_EXT_MODE_CTRL_AUTO_MDIX_;
		break;
	default:
		return;
	}

	phy_write(phydev, LAN88XX_EXT_PAGE_ACCESS, LAN88XX_EXT_PAGE_SPACE_1);
	buf = phy_read(phydev, LAN88XX_EXT_MODE_CTRL);
	buf &= ~LAN88XX_EXT_MODE_CTRL_MDIX_MASK_;
	buf |= val;
	phy_write(phydev, LAN88XX_EXT_MODE_CTRL, buf);
	phy_write(phydev, LAN88XX_EXT_PAGE_ACCESS, LAN88XX_EXT_PAGE_SPACE_0);
}

__attribute__((used)) static int lan88xx_config_init(struct phy_device *phydev)
{
	int val;

	genphy_config_init(phydev);
	/*Zerodetect delay enable */
	val = phy_read_mmd(phydev, MDIO_MMD_PCS,
			   PHY_ARDENNES_MMD_DEV_3_PHY_CFG);
	val |= PHY_ARDENNES_MMD_DEV_3_PHY_CFG_ZD_DLY_EN_;

	phy_write_mmd(phydev, MDIO_MMD_PCS, PHY_ARDENNES_MMD_DEV_3_PHY_CFG,
		      val);

	/* Config DSP registers */
	lan88xx_config_TR_regs(phydev);

	return 0;
}

__attribute__((used)) static int lan88xx_config_aneg(struct phy_device *phydev)
{
	lan88xx_set_mdix(phydev);

	return genphy_config_aneg(phydev);
}

