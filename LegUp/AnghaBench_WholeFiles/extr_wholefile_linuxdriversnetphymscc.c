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
typedef  scalar_t__ u8 ;
typedef  int u16 ;
struct vsc8531_private {scalar_t__ rate_magic; scalar_t__ led_1_mode; scalar_t__ led_0_mode; } ;
struct TYPE_4__ {int /*<<< orphan*/  dev; } ;
struct phy_device {scalar_t__ mdix_ctrl; int interface; scalar_t__ interrupts; scalar_t__ mdix; struct vsc8531_private* priv; TYPE_2__ mdio; int /*<<< orphan*/  lock; TYPE_1__* attached_dev; } ;
struct ethtool_wolinfo {int wolopts; int* sopass; } ;
struct ethtool_tunable {int id; } ;
typedef  int phy_interface_t ;
struct TYPE_3__ {scalar_t__* dev_addr; } ;

/* Variables and functions */
 scalar_t__ ARRAY_SIZE (int*) ; 
 int DISABLE_HP_AUTO_MDIX_MASK ; 
 int DISABLE_PAIR_SWAP_CORR_MASK ; 
 int DISABLE_POLARITY_CORR_MASK ; 
 int DOWNSHIFT_CNTL_MASK ; 
 int DOWNSHIFT_CNTL_POS ; 
 scalar_t__ DOWNSHIFT_COUNT_MAX ; 
 scalar_t__ DOWNSHIFT_DEV_DEFAULT_COUNT ; 
 scalar_t__ DOWNSHIFT_DEV_DISABLE ; 
 int DOWNSHIFT_EN ; 
 int EDGE_RATE_CNTL_MASK ; 
 scalar_t__ EDGE_RATE_CNTL_POS ; 
 int EINVAL ; 
 int ENOMEM ; 
 int ERANGE ; 
#define  ETHTOOL_PHY_DOWNSHIFT 132 
 scalar_t__ ETH_TP_MDI ; 
 scalar_t__ ETH_TP_MDI_AUTO ; 
 scalar_t__ ETH_TP_MDI_X ; 
 int FORCE_MDI_CROSSOVER_MASK ; 
 int FORCE_MDI_CROSSOVER_MDI ; 
 int FORCE_MDI_CROSSOVER_MDIX ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HP_AUTO_MDIX_X_OVER_IND_MASK ; 
 int LED_0_MODE_SEL_MASK ; 
 int LED_1_MODE_SEL_MASK ; 
 int LED_1_MODE_SEL_POS ; 
 int MAC_IF_SELECTION_GMII ; 
 int MAC_IF_SELECTION_MASK ; 
 int MAC_IF_SELECTION_POS ; 
 int MAC_IF_SELECTION_RGMII ; 
 int MAC_IF_SELECTION_RMII ; 
 int /*<<< orphan*/  MII_VSC85XX_INT_MASK ; 
 int MII_VSC85XX_INT_MASK_MASK ; 
 int MII_VSC85XX_INT_MASK_WOL ; 
 int /*<<< orphan*/  MII_VSC85XX_INT_STATUS ; 
 int /*<<< orphan*/  MSCC_EXT_PAGE_ACCESS ; 
 int /*<<< orphan*/  MSCC_PHY_ACTIPHY_CNTL ; 
 int /*<<< orphan*/  MSCC_PHY_BYPASS_CONTROL ; 
 int /*<<< orphan*/  MSCC_PHY_DEV_AUX_CNTL ; 
 int /*<<< orphan*/  MSCC_PHY_EXT_MODE_CNTL ; 
 int /*<<< orphan*/  MSCC_PHY_EXT_PHY_CNTL_1 ; 
 int /*<<< orphan*/  MSCC_PHY_LED_MODE_SEL ; 
 int MSCC_PHY_PAGE_EXTENDED ; 
 int MSCC_PHY_PAGE_EXTENDED_2 ; 
 int MSCC_PHY_PAGE_STANDARD ; 
 int /*<<< orphan*/  MSCC_PHY_RGMII_CNTL ; 
 int /*<<< orphan*/  MSCC_PHY_WOL_LOWER_MAC_ADDR ; 
 int /*<<< orphan*/  MSCC_PHY_WOL_LOWER_PASSWD ; 
 int /*<<< orphan*/  MSCC_PHY_WOL_MAC_CONTROL ; 
 int /*<<< orphan*/  MSCC_PHY_WOL_MID_MAC_ADDR ; 
 int /*<<< orphan*/  MSCC_PHY_WOL_MID_PASSWD ; 
 int /*<<< orphan*/  MSCC_PHY_WOL_UPPER_MAC_ADDR ; 
 int /*<<< orphan*/  MSCC_PHY_WOL_UPPER_PASSWD ; 
#define  PHY_INTERFACE_MODE_GMII 131 
#define  PHY_INTERFACE_MODE_MII 130 
#define  PHY_INTERFACE_MODE_RGMII 129 
#define  PHY_INTERFACE_MODE_RMII 128 
 scalar_t__ PHY_INTERRUPT_ENABLED ; 
 int RGMII_RX_CLK_DELAY_1_1_NS ; 
 int RGMII_RX_CLK_DELAY_MASK ; 
 int RGMII_RX_CLK_DELAY_POS ; 
 int SECURE_ON_ENABLE ; 
 scalar_t__ VSC8531_LINK_1000_ACTIVITY ; 
 scalar_t__ VSC8531_LINK_100_ACTIVITY ; 
 int WAKE_MAGIC ; 
 int WAKE_MAGICSECURE ; 
 struct vsc8531_private* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int genphy_config_aneg (struct phy_device*) ; 
 int genphy_config_init (struct phy_device*) ; 
 int genphy_read_status (struct phy_device*) ; 
 int genphy_restart_aneg (struct phy_device*) ; 
 int genphy_soft_reset (struct phy_device*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int phy_read (struct phy_device*,int /*<<< orphan*/ ) ; 
 int phy_write (struct phy_device*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  phydev_err (struct phy_device*,char*) ; 

__attribute__((used)) static int vsc85xx_phy_page_set(struct phy_device *phydev, u16 page)
{
	int rc;

	rc = phy_write(phydev, MSCC_EXT_PAGE_ACCESS, page);
	return rc;
}

__attribute__((used)) static int vsc85xx_led_cntl_set(struct phy_device *phydev,
				u8 led_num,
				u8 mode)
{
	int rc;
	u16 reg_val;

	mutex_lock(&phydev->lock);
	reg_val = phy_read(phydev, MSCC_PHY_LED_MODE_SEL);
	if (led_num) {
		reg_val &= ~LED_1_MODE_SEL_MASK;
		reg_val |= (((u16)mode << LED_1_MODE_SEL_POS) &
			    LED_1_MODE_SEL_MASK);
	} else {
		reg_val &= ~LED_0_MODE_SEL_MASK;
		reg_val |= ((u16)mode & LED_0_MODE_SEL_MASK);
	}
	rc = phy_write(phydev, MSCC_PHY_LED_MODE_SEL, reg_val);
	mutex_unlock(&phydev->lock);

	return rc;
}

__attribute__((used)) static int vsc85xx_mdix_get(struct phy_device *phydev, u8 *mdix)
{
	u16 reg_val;

	reg_val = phy_read(phydev, MSCC_PHY_DEV_AUX_CNTL);
	if (reg_val & HP_AUTO_MDIX_X_OVER_IND_MASK)
		*mdix = ETH_TP_MDI_X;
	else
		*mdix = ETH_TP_MDI;

	return 0;
}

__attribute__((used)) static int vsc85xx_mdix_set(struct phy_device *phydev, u8 mdix)
{
	int rc;
	u16 reg_val;

	reg_val = phy_read(phydev, MSCC_PHY_BYPASS_CONTROL);
	if ((mdix == ETH_TP_MDI) || (mdix == ETH_TP_MDI_X)) {
		reg_val |= (DISABLE_PAIR_SWAP_CORR_MASK |
			    DISABLE_POLARITY_CORR_MASK  |
			    DISABLE_HP_AUTO_MDIX_MASK);
	} else {
		reg_val &= ~(DISABLE_PAIR_SWAP_CORR_MASK |
			     DISABLE_POLARITY_CORR_MASK  |
			     DISABLE_HP_AUTO_MDIX_MASK);
	}
	rc = phy_write(phydev, MSCC_PHY_BYPASS_CONTROL, reg_val);
	if (rc != 0)
		return rc;

	rc = vsc85xx_phy_page_set(phydev, MSCC_PHY_PAGE_EXTENDED);
	if (rc != 0)
		return rc;

	reg_val = phy_read(phydev, MSCC_PHY_EXT_MODE_CNTL);
	reg_val &= ~(FORCE_MDI_CROSSOVER_MASK);
	if (mdix == ETH_TP_MDI)
		reg_val |= FORCE_MDI_CROSSOVER_MDI;
	else if (mdix == ETH_TP_MDI_X)
		reg_val |= FORCE_MDI_CROSSOVER_MDIX;
	rc = phy_write(phydev, MSCC_PHY_EXT_MODE_CNTL, reg_val);
	if (rc != 0)
		return rc;

	rc = vsc85xx_phy_page_set(phydev, MSCC_PHY_PAGE_STANDARD);
	if (rc != 0)
		return rc;

	return genphy_restart_aneg(phydev);
}

__attribute__((used)) static int vsc85xx_downshift_get(struct phy_device *phydev, u8 *count)
{
	int rc;
	u16 reg_val;

	rc = vsc85xx_phy_page_set(phydev, MSCC_PHY_PAGE_EXTENDED);
	if (rc != 0)
		goto out;

	reg_val = phy_read(phydev, MSCC_PHY_ACTIPHY_CNTL);
	reg_val &= DOWNSHIFT_CNTL_MASK;
	if (!(reg_val & DOWNSHIFT_EN))
		*count = DOWNSHIFT_DEV_DISABLE;
	else
		*count = ((reg_val & ~DOWNSHIFT_EN) >> DOWNSHIFT_CNTL_POS) + 2;
	rc = vsc85xx_phy_page_set(phydev, MSCC_PHY_PAGE_STANDARD);

out:
	return rc;
}

__attribute__((used)) static int vsc85xx_downshift_set(struct phy_device *phydev, u8 count)
{
	int rc;
	u16 reg_val;

	if (count == DOWNSHIFT_DEV_DEFAULT_COUNT) {
		/* Default downshift count 3 (i.e. Bit3:2 = 0b01) */
		count = ((1 << DOWNSHIFT_CNTL_POS) | DOWNSHIFT_EN);
	} else if (count > DOWNSHIFT_COUNT_MAX || count == 1) {
		phydev_err(phydev, "Downshift count should be 2,3,4 or 5\n");
		return -ERANGE;
	} else if (count) {
		/* Downshift count is either 2,3,4 or 5 */
		count = (((count - 2) << DOWNSHIFT_CNTL_POS) | DOWNSHIFT_EN);
	}

	rc = vsc85xx_phy_page_set(phydev, MSCC_PHY_PAGE_EXTENDED);
	if (rc != 0)
		goto out;

	reg_val = phy_read(phydev, MSCC_PHY_ACTIPHY_CNTL);
	reg_val &= ~(DOWNSHIFT_CNTL_MASK);
	reg_val |= count;
	rc = phy_write(phydev, MSCC_PHY_ACTIPHY_CNTL, reg_val);
	if (rc != 0)
		goto out;

	rc = vsc85xx_phy_page_set(phydev, MSCC_PHY_PAGE_STANDARD);

out:
	return rc;
}

__attribute__((used)) static int vsc85xx_wol_set(struct phy_device *phydev,
			   struct ethtool_wolinfo *wol)
{
	int rc;
	u16 reg_val;
	u8  i;
	u16 pwd[3] = {0, 0, 0};
	struct ethtool_wolinfo *wol_conf = wol;
	u8 *mac_addr = phydev->attached_dev->dev_addr;

	mutex_lock(&phydev->lock);
	rc = vsc85xx_phy_page_set(phydev, MSCC_PHY_PAGE_EXTENDED_2);
	if (rc != 0)
		goto out_unlock;

	if (wol->wolopts & WAKE_MAGIC) {
		/* Store the device address for the magic packet */
		for (i = 0; i < ARRAY_SIZE(pwd); i++)
			pwd[i] = mac_addr[5 - (i * 2 + 1)] << 8 |
				 mac_addr[5 - i * 2];
		phy_write(phydev, MSCC_PHY_WOL_LOWER_MAC_ADDR, pwd[0]);
		phy_write(phydev, MSCC_PHY_WOL_MID_MAC_ADDR, pwd[1]);
		phy_write(phydev, MSCC_PHY_WOL_UPPER_MAC_ADDR, pwd[2]);
	} else {
		phy_write(phydev, MSCC_PHY_WOL_LOWER_MAC_ADDR, 0);
		phy_write(phydev, MSCC_PHY_WOL_MID_MAC_ADDR, 0);
		phy_write(phydev, MSCC_PHY_WOL_UPPER_MAC_ADDR, 0);
	}

	if (wol_conf->wolopts & WAKE_MAGICSECURE) {
		for (i = 0; i < ARRAY_SIZE(pwd); i++)
			pwd[i] = wol_conf->sopass[5 - (i * 2 + 1)] << 8 |
				 wol_conf->sopass[5 - i * 2];
		phy_write(phydev, MSCC_PHY_WOL_LOWER_PASSWD, pwd[0]);
		phy_write(phydev, MSCC_PHY_WOL_MID_PASSWD, pwd[1]);
		phy_write(phydev, MSCC_PHY_WOL_UPPER_PASSWD, pwd[2]);
	} else {
		phy_write(phydev, MSCC_PHY_WOL_LOWER_PASSWD, 0);
		phy_write(phydev, MSCC_PHY_WOL_MID_PASSWD, 0);
		phy_write(phydev, MSCC_PHY_WOL_UPPER_PASSWD, 0);
	}

	reg_val = phy_read(phydev, MSCC_PHY_WOL_MAC_CONTROL);
	if (wol_conf->wolopts & WAKE_MAGICSECURE)
		reg_val |= SECURE_ON_ENABLE;
	else
		reg_val &= ~SECURE_ON_ENABLE;
	phy_write(phydev, MSCC_PHY_WOL_MAC_CONTROL, reg_val);

	rc = vsc85xx_phy_page_set(phydev, MSCC_PHY_PAGE_STANDARD);
	if (rc != 0)
		goto out_unlock;

	if (wol->wolopts & WAKE_MAGIC) {
		/* Enable the WOL interrupt */
		reg_val = phy_read(phydev, MII_VSC85XX_INT_MASK);
		reg_val |= MII_VSC85XX_INT_MASK_WOL;
		rc = phy_write(phydev, MII_VSC85XX_INT_MASK, reg_val);
		if (rc != 0)
			goto out_unlock;
	} else {
		/* Disable the WOL interrupt */
		reg_val = phy_read(phydev, MII_VSC85XX_INT_MASK);
		reg_val &= (~MII_VSC85XX_INT_MASK_WOL);
		rc = phy_write(phydev, MII_VSC85XX_INT_MASK, reg_val);
		if (rc != 0)
			goto out_unlock;
	}
	/* Clear WOL iterrupt status */
	reg_val = phy_read(phydev, MII_VSC85XX_INT_STATUS);

out_unlock:
	mutex_unlock(&phydev->lock);

	return rc;
}

__attribute__((used)) static void vsc85xx_wol_get(struct phy_device *phydev,
			    struct ethtool_wolinfo *wol)
{
	int rc;
	u16 reg_val;
	u8  i;
	u16 pwd[3] = {0, 0, 0};
	struct ethtool_wolinfo *wol_conf = wol;

	mutex_lock(&phydev->lock);
	rc = vsc85xx_phy_page_set(phydev, MSCC_PHY_PAGE_EXTENDED_2);
	if (rc != 0)
		goto out_unlock;

	reg_val = phy_read(phydev, MSCC_PHY_WOL_MAC_CONTROL);
	if (reg_val & SECURE_ON_ENABLE)
		wol_conf->wolopts |= WAKE_MAGICSECURE;
	if (wol_conf->wolopts & WAKE_MAGICSECURE) {
		pwd[0] = phy_read(phydev, MSCC_PHY_WOL_LOWER_PASSWD);
		pwd[1] = phy_read(phydev, MSCC_PHY_WOL_MID_PASSWD);
		pwd[2] = phy_read(phydev, MSCC_PHY_WOL_UPPER_PASSWD);
		for (i = 0; i < ARRAY_SIZE(pwd); i++) {
			wol_conf->sopass[5 - i * 2] = pwd[i] & 0x00ff;
			wol_conf->sopass[5 - (i * 2 + 1)] = (pwd[i] & 0xff00)
							    >> 8;
		}
	}

	rc = vsc85xx_phy_page_set(phydev, MSCC_PHY_PAGE_STANDARD);

out_unlock:
	mutex_unlock(&phydev->lock);
}

__attribute__((used)) static int vsc85xx_edge_rate_magic_get(struct phy_device *phydev)
{
	return 0;
}

__attribute__((used)) static int vsc85xx_dt_led_mode_get(struct phy_device *phydev,
				   char *led,
				   u8 default_mode)
{
	return default_mode;
}

__attribute__((used)) static int vsc85xx_edge_rate_cntl_set(struct phy_device *phydev, u8 edge_rate)
{
	int rc;
	u16 reg_val;

	mutex_lock(&phydev->lock);
	rc = vsc85xx_phy_page_set(phydev, MSCC_PHY_PAGE_EXTENDED_2);
	if (rc != 0)
		goto out_unlock;
	reg_val = phy_read(phydev, MSCC_PHY_WOL_MAC_CONTROL);
	reg_val &= ~(EDGE_RATE_CNTL_MASK);
	reg_val |= (edge_rate << EDGE_RATE_CNTL_POS);
	rc = phy_write(phydev, MSCC_PHY_WOL_MAC_CONTROL, reg_val);
	if (rc != 0)
		goto out_unlock;
	rc = vsc85xx_phy_page_set(phydev, MSCC_PHY_PAGE_STANDARD);

out_unlock:
	mutex_unlock(&phydev->lock);

	return rc;
}

__attribute__((used)) static int vsc85xx_mac_if_set(struct phy_device *phydev,
			      phy_interface_t interface)
{
	int rc;
	u16 reg_val;

	mutex_lock(&phydev->lock);
	reg_val = phy_read(phydev, MSCC_PHY_EXT_PHY_CNTL_1);
	reg_val &= ~(MAC_IF_SELECTION_MASK);
	switch (interface) {
	case PHY_INTERFACE_MODE_RGMII:
		reg_val |= (MAC_IF_SELECTION_RGMII << MAC_IF_SELECTION_POS);
		break;
	case PHY_INTERFACE_MODE_RMII:
		reg_val |= (MAC_IF_SELECTION_RMII << MAC_IF_SELECTION_POS);
		break;
	case PHY_INTERFACE_MODE_MII:
	case PHY_INTERFACE_MODE_GMII:
		reg_val |= (MAC_IF_SELECTION_GMII << MAC_IF_SELECTION_POS);
		break;
	default:
		rc = -EINVAL;
		goto out_unlock;
	}
	rc = phy_write(phydev, MSCC_PHY_EXT_PHY_CNTL_1, reg_val);
	if (rc != 0)
		goto out_unlock;

	rc = genphy_soft_reset(phydev);

out_unlock:
	mutex_unlock(&phydev->lock);

	return rc;
}

__attribute__((used)) static int vsc85xx_default_config(struct phy_device *phydev)
{
	int rc;
	u16 reg_val;

	phydev->mdix_ctrl = ETH_TP_MDI_AUTO;
	mutex_lock(&phydev->lock);
	rc = vsc85xx_phy_page_set(phydev, MSCC_PHY_PAGE_EXTENDED_2);
	if (rc != 0)
		goto out_unlock;

	reg_val = phy_read(phydev, MSCC_PHY_RGMII_CNTL);
	reg_val &= ~(RGMII_RX_CLK_DELAY_MASK);
	reg_val |= (RGMII_RX_CLK_DELAY_1_1_NS << RGMII_RX_CLK_DELAY_POS);
	phy_write(phydev, MSCC_PHY_RGMII_CNTL, reg_val);
	rc = vsc85xx_phy_page_set(phydev, MSCC_PHY_PAGE_STANDARD);

out_unlock:
	mutex_unlock(&phydev->lock);

	return rc;
}

__attribute__((used)) static int vsc85xx_get_tunable(struct phy_device *phydev,
			       struct ethtool_tunable *tuna, void *data)
{
	switch (tuna->id) {
	case ETHTOOL_PHY_DOWNSHIFT:
		return vsc85xx_downshift_get(phydev, (u8 *)data);
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int vsc85xx_set_tunable(struct phy_device *phydev,
			       struct ethtool_tunable *tuna,
			       const void *data)
{
	switch (tuna->id) {
	case ETHTOOL_PHY_DOWNSHIFT:
		return vsc85xx_downshift_set(phydev, *(u8 *)data);
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int vsc85xx_config_init(struct phy_device *phydev)
{
	int rc;
	struct vsc8531_private *vsc8531 = phydev->priv;

	rc = vsc85xx_default_config(phydev);
	if (rc)
		return rc;

	rc = vsc85xx_mac_if_set(phydev, phydev->interface);
	if (rc)
		return rc;

	rc = vsc85xx_edge_rate_cntl_set(phydev, vsc8531->rate_magic);
	if (rc)
		return rc;

	rc = vsc85xx_led_cntl_set(phydev, 1, vsc8531->led_1_mode);
	if (rc)
		return rc;

	rc = vsc85xx_led_cntl_set(phydev, 0, vsc8531->led_0_mode);
	if (rc)
		return rc;

	rc = genphy_config_init(phydev);

	return rc;
}

__attribute__((used)) static int vsc85xx_ack_interrupt(struct phy_device *phydev)
{
	int rc = 0;

	if (phydev->interrupts == PHY_INTERRUPT_ENABLED)
		rc = phy_read(phydev, MII_VSC85XX_INT_STATUS);

	return (rc < 0) ? rc : 0;
}

__attribute__((used)) static int vsc85xx_config_intr(struct phy_device *phydev)
{
	int rc;

	if (phydev->interrupts == PHY_INTERRUPT_ENABLED) {
		rc = phy_write(phydev, MII_VSC85XX_INT_MASK,
			       MII_VSC85XX_INT_MASK_MASK);
	} else {
		rc = phy_write(phydev, MII_VSC85XX_INT_MASK, 0);
		if (rc < 0)
			return rc;
		rc = phy_read(phydev, MII_VSC85XX_INT_STATUS);
	}

	return rc;
}

__attribute__((used)) static int vsc85xx_config_aneg(struct phy_device *phydev)
{
	int rc;

	rc = vsc85xx_mdix_set(phydev, phydev->mdix_ctrl);
	if (rc < 0)
		return rc;

	return genphy_config_aneg(phydev);
}

__attribute__((used)) static int vsc85xx_read_status(struct phy_device *phydev)
{
	int rc;

	rc = vsc85xx_mdix_get(phydev, &phydev->mdix);
	if (rc < 0)
		return rc;

	return genphy_read_status(phydev);
}

__attribute__((used)) static int vsc85xx_probe(struct phy_device *phydev)
{
	struct vsc8531_private *vsc8531;
	int rate_magic;
	int led_mode;

	rate_magic = vsc85xx_edge_rate_magic_get(phydev);
	if (rate_magic < 0)
		return rate_magic;

	vsc8531 = devm_kzalloc(&phydev->mdio.dev, sizeof(*vsc8531), GFP_KERNEL);
	if (!vsc8531)
		return -ENOMEM;

	phydev->priv = vsc8531;

	vsc8531->rate_magic = rate_magic;

	/* LED[0] and LED[1] mode */
	led_mode = vsc85xx_dt_led_mode_get(phydev, "vsc8531,led-0-mode",
					   VSC8531_LINK_1000_ACTIVITY);
	if (led_mode < 0)
		return led_mode;
	vsc8531->led_0_mode = led_mode;

	led_mode = vsc85xx_dt_led_mode_get(phydev, "vsc8531,led-1-mode",
					   VSC8531_LINK_100_ACTIVITY);
	if (led_mode < 0)
		return led_mode;
	vsc8531->led_1_mode = led_mode;

	return 0;
}

