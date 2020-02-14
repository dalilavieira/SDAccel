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
typedef  int u64 ;
typedef  int /*<<< orphan*/  u32 ;
typedef  int u16 ;
struct phy_device {scalar_t__ interrupts; scalar_t__ autoneg; } ;
struct ethtool_stats {int dummy; } ;
struct bcm_phy_hw_stat {int shift; int bits; int /*<<< orphan*/  reg; int /*<<< orphan*/  string; } ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (struct bcm_phy_hw_stat*) ; 
 scalar_t__ AUTONEG_ENABLE ; 
 int BCM54XX_SHD_APD ; 
 int BCM54XX_SHD_APD_EN ; 
 int BCM54XX_SHD_SCR2 ; 
 int BCM54XX_SHD_SCR2_WSPD_RTRY_DIS ; 
 int BCM54XX_SHD_SCR2_WSPD_RTRY_LMT_MASK ; 
 int BCM54XX_SHD_SCR2_WSPD_RTRY_LMT_OFFSET ; 
 int BCM54XX_SHD_SCR2_WSPD_RTRY_LMT_SHIFT ; 
 int BCM54XX_SHD_SCR3 ; 
 int BCM54XX_SHD_SCR3_DLLAPD_DIS ; 
 int BCM_APD_CLR_MASK ; 
 int BCM_APD_SINGLELP_EN ; 
 int /*<<< orphan*/  BCM_CL45VEN_EEE_ADV ; 
 int BCM_NO_ANEG_APD_EN ; 
 int /*<<< orphan*/  BRCM_CL45VEN_EEE_CONTROL ; 
#define  DOWNSHIFT_DEV_DEFAULT_COUNT 128 
 int DOWNSHIFT_DEV_DISABLE ; 
 int ERANGE ; 
 unsigned int ETH_GSTRING_LEN ; 
 int LPI_FEATURE_EN ; 
 int LPI_FEATURE_EN_DIG1000X ; 
 int MDIO_EEE_1000T ; 
 int MDIO_EEE_100TX ; 
 int /*<<< orphan*/  MDIO_MMD_AN ; 
 int MII_BCM54XX_AUXCTL_ACTL_SMDSP_ENA ; 
 int MII_BCM54XX_AUXCTL_MISC_WREN ; 
 int MII_BCM54XX_AUXCTL_SHDWSEL_MASK ; 
 int MII_BCM54XX_AUXCTL_SHDWSEL_MISC ; 
 int MII_BCM54XX_AUXCTL_SHDWSEL_MISC_WIRESPEED_EN ; 
 int MII_BCM54XX_AUXCTL_SHDWSEL_READ_SHIFT ; 
 int /*<<< orphan*/  MII_BCM54XX_AUX_CTL ; 
 int /*<<< orphan*/  MII_BCM54XX_ECR ; 
 int MII_BCM54XX_ECR_IM ; 
 int /*<<< orphan*/  MII_BCM54XX_EXP_DATA ; 
 int /*<<< orphan*/  MII_BCM54XX_EXP_SEL ; 
 int MII_BCM54XX_EXP_SEL_ER ; 
 int /*<<< orphan*/  MII_BCM54XX_ISR ; 
 int /*<<< orphan*/  MII_BCM54XX_SHD ; 
 int MII_BCM54XX_SHD_DATA (int) ; 
 int MII_BCM54XX_SHD_VAL (int) ; 
 int MII_BCM54XX_SHD_WRITE ; 
 int MII_BCM_CHANNEL_WIDTH ; 
 scalar_t__ PHY_INTERRUPT_ENABLED ; 
 int U64_MAX ; 
 struct bcm_phy_hw_stat* bcm_phy_hw_stats ; 
 int bcm_phy_write_exp (struct phy_device*,int,int) ; 
 int phy_read (struct phy_device*,int /*<<< orphan*/ ) ; 
 int phy_read_mmd (struct phy_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int phy_write (struct phy_device*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  phy_write_mmd (struct phy_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strlcpy (int*,int /*<<< orphan*/ ,unsigned int) ; 

__attribute__((used)) static inline int bcm_phy_write_exp_sel(struct phy_device *phydev,
					u16 reg, u16 val)
{
	return bcm_phy_write_exp(phydev, reg | MII_BCM54XX_EXP_SEL_ER, val);
}

int bcm_phy_write_exp(struct phy_device *phydev, u16 reg, u16 val)
{
	int rc;

	rc = phy_write(phydev, MII_BCM54XX_EXP_SEL, reg);
	if (rc < 0)
		return rc;

	return phy_write(phydev, MII_BCM54XX_EXP_DATA, val);
}

int bcm_phy_read_exp(struct phy_device *phydev, u16 reg)
{
	int val;

	val = phy_write(phydev, MII_BCM54XX_EXP_SEL, reg);
	if (val < 0)
		return val;

	val = phy_read(phydev, MII_BCM54XX_EXP_DATA);

	/* Restore default value.  It's O.K. if this write fails. */
	phy_write(phydev, MII_BCM54XX_EXP_SEL, 0);

	return val;
}

int bcm54xx_auxctl_read(struct phy_device *phydev, u16 regnum)
{
	/* The register must be written to both the Shadow Register Select and
	 * the Shadow Read Register Selector
	 */
	phy_write(phydev, MII_BCM54XX_AUX_CTL, MII_BCM54XX_AUXCTL_SHDWSEL_MASK |
		  regnum << MII_BCM54XX_AUXCTL_SHDWSEL_READ_SHIFT);
	return phy_read(phydev, MII_BCM54XX_AUX_CTL);
}

int bcm54xx_auxctl_write(struct phy_device *phydev, u16 regnum, u16 val)
{
	return phy_write(phydev, MII_BCM54XX_AUX_CTL, regnum | val);
}

int bcm_phy_write_misc(struct phy_device *phydev,
		       u16 reg, u16 chl, u16 val)
{
	int rc;
	int tmp;

	rc = phy_write(phydev, MII_BCM54XX_AUX_CTL,
		       MII_BCM54XX_AUXCTL_SHDWSEL_MISC);
	if (rc < 0)
		return rc;

	tmp = phy_read(phydev, MII_BCM54XX_AUX_CTL);
	tmp |= MII_BCM54XX_AUXCTL_ACTL_SMDSP_ENA;
	rc = phy_write(phydev, MII_BCM54XX_AUX_CTL, tmp);
	if (rc < 0)
		return rc;

	tmp = (chl * MII_BCM_CHANNEL_WIDTH) | reg;
	rc = bcm_phy_write_exp(phydev, tmp, val);

	return rc;
}

int bcm_phy_read_misc(struct phy_device *phydev,
		      u16 reg, u16 chl)
{
	int rc;
	int tmp;

	rc = phy_write(phydev, MII_BCM54XX_AUX_CTL,
		       MII_BCM54XX_AUXCTL_SHDWSEL_MISC);
	if (rc < 0)
		return rc;

	tmp = phy_read(phydev, MII_BCM54XX_AUX_CTL);
	tmp |= MII_BCM54XX_AUXCTL_ACTL_SMDSP_ENA;
	rc = phy_write(phydev, MII_BCM54XX_AUX_CTL, tmp);
	if (rc < 0)
		return rc;

	tmp = (chl * MII_BCM_CHANNEL_WIDTH) | reg;
	rc = bcm_phy_read_exp(phydev, tmp);

	return rc;
}

int bcm_phy_ack_intr(struct phy_device *phydev)
{
	int reg;

	/* Clear pending interrupts.  */
	reg = phy_read(phydev, MII_BCM54XX_ISR);
	if (reg < 0)
		return reg;

	return 0;
}

int bcm_phy_config_intr(struct phy_device *phydev)
{
	int reg;

	reg = phy_read(phydev, MII_BCM54XX_ECR);
	if (reg < 0)
		return reg;

	if (phydev->interrupts == PHY_INTERRUPT_ENABLED)
		reg &= ~MII_BCM54XX_ECR_IM;
	else
		reg |= MII_BCM54XX_ECR_IM;

	return phy_write(phydev, MII_BCM54XX_ECR, reg);
}

int bcm_phy_read_shadow(struct phy_device *phydev, u16 shadow)
{
	phy_write(phydev, MII_BCM54XX_SHD, MII_BCM54XX_SHD_VAL(shadow));
	return MII_BCM54XX_SHD_DATA(phy_read(phydev, MII_BCM54XX_SHD));
}

int bcm_phy_write_shadow(struct phy_device *phydev, u16 shadow,
			 u16 val)
{
	return phy_write(phydev, MII_BCM54XX_SHD,
			 MII_BCM54XX_SHD_WRITE |
			 MII_BCM54XX_SHD_VAL(shadow) |
			 MII_BCM54XX_SHD_DATA(val));
}

int bcm_phy_enable_apd(struct phy_device *phydev, bool dll_pwr_down)
{
	int val;

	if (dll_pwr_down) {
		val = bcm_phy_read_shadow(phydev, BCM54XX_SHD_SCR3);
		if (val < 0)
			return val;

		val |= BCM54XX_SHD_SCR3_DLLAPD_DIS;
		bcm_phy_write_shadow(phydev, BCM54XX_SHD_SCR3, val);
	}

	val = bcm_phy_read_shadow(phydev, BCM54XX_SHD_APD);
	if (val < 0)
		return val;

	/* Clear APD bits */
	val &= BCM_APD_CLR_MASK;

	if (phydev->autoneg == AUTONEG_ENABLE)
		val |= BCM54XX_SHD_APD_EN;
	else
		val |= BCM_NO_ANEG_APD_EN;

	/* Enable energy detect single link pulse for easy wakeup */
	val |= BCM_APD_SINGLELP_EN;

	/* Enable Auto Power-Down (APD) for the PHY */
	return bcm_phy_write_shadow(phydev, BCM54XX_SHD_APD, val);
}

int bcm_phy_set_eee(struct phy_device *phydev, bool enable)
{
	int val;

	/* Enable EEE at PHY level */
	val = phy_read_mmd(phydev, MDIO_MMD_AN, BRCM_CL45VEN_EEE_CONTROL);
	if (val < 0)
		return val;

	if (enable)
		val |= LPI_FEATURE_EN | LPI_FEATURE_EN_DIG1000X;
	else
		val &= ~(LPI_FEATURE_EN | LPI_FEATURE_EN_DIG1000X);

	phy_write_mmd(phydev, MDIO_MMD_AN, BRCM_CL45VEN_EEE_CONTROL, (u32)val);

	/* Advertise EEE */
	val = phy_read_mmd(phydev, MDIO_MMD_AN, BCM_CL45VEN_EEE_ADV);
	if (val < 0)
		return val;

	if (enable)
		val |= (MDIO_EEE_100TX | MDIO_EEE_1000T);
	else
		val &= ~(MDIO_EEE_100TX | MDIO_EEE_1000T);

	phy_write_mmd(phydev, MDIO_MMD_AN, BCM_CL45VEN_EEE_ADV, (u32)val);

	return 0;
}

int bcm_phy_downshift_get(struct phy_device *phydev, u8 *count)
{
	int val;

	val = bcm54xx_auxctl_read(phydev, MII_BCM54XX_AUXCTL_SHDWSEL_MISC);
	if (val < 0)
		return val;

	/* Check if wirespeed is enabled or not */
	if (!(val & MII_BCM54XX_AUXCTL_SHDWSEL_MISC_WIRESPEED_EN)) {
		*count = DOWNSHIFT_DEV_DISABLE;
		return 0;
	}

	val = bcm_phy_read_shadow(phydev, BCM54XX_SHD_SCR2);
	if (val < 0)
		return val;

	/* Downgrade after one link attempt */
	if (val & BCM54XX_SHD_SCR2_WSPD_RTRY_DIS) {
		*count = 1;
	} else {
		/* Downgrade after configured retry count */
		val >>= BCM54XX_SHD_SCR2_WSPD_RTRY_LMT_SHIFT;
		val &= BCM54XX_SHD_SCR2_WSPD_RTRY_LMT_MASK;
		*count = val + BCM54XX_SHD_SCR2_WSPD_RTRY_LMT_OFFSET;
	}

	return 0;
}

int bcm_phy_downshift_set(struct phy_device *phydev, u8 count)
{
	int val = 0, ret = 0;

	/* Range check the number given */
	if (count - BCM54XX_SHD_SCR2_WSPD_RTRY_LMT_OFFSET >
	    BCM54XX_SHD_SCR2_WSPD_RTRY_LMT_MASK &&
	    count != DOWNSHIFT_DEV_DEFAULT_COUNT) {
		return -ERANGE;
	}

	val = bcm54xx_auxctl_read(phydev, MII_BCM54XX_AUXCTL_SHDWSEL_MISC);
	if (val < 0)
		return val;

	/* Se the write enable bit */
	val |= MII_BCM54XX_AUXCTL_MISC_WREN;

	if (count == DOWNSHIFT_DEV_DISABLE) {
		val &= ~MII_BCM54XX_AUXCTL_SHDWSEL_MISC_WIRESPEED_EN;
		return bcm54xx_auxctl_write(phydev,
					    MII_BCM54XX_AUXCTL_SHDWSEL_MISC,
					    val);
	} else {
		val |= MII_BCM54XX_AUXCTL_SHDWSEL_MISC_WIRESPEED_EN;
		ret = bcm54xx_auxctl_write(phydev,
					   MII_BCM54XX_AUXCTL_SHDWSEL_MISC,
					   val);
		if (ret < 0)
			return ret;
	}

	val = bcm_phy_read_shadow(phydev, BCM54XX_SHD_SCR2);
	val &= ~(BCM54XX_SHD_SCR2_WSPD_RTRY_LMT_MASK <<
		 BCM54XX_SHD_SCR2_WSPD_RTRY_LMT_SHIFT |
		 BCM54XX_SHD_SCR2_WSPD_RTRY_DIS);

	switch (count) {
	case 1:
		val |= BCM54XX_SHD_SCR2_WSPD_RTRY_DIS;
		break;
	case DOWNSHIFT_DEV_DEFAULT_COUNT:
		val |= 1 << BCM54XX_SHD_SCR2_WSPD_RTRY_LMT_SHIFT;
		break;
	default:
		val |= (count - BCM54XX_SHD_SCR2_WSPD_RTRY_LMT_OFFSET) <<
			BCM54XX_SHD_SCR2_WSPD_RTRY_LMT_SHIFT;
		break;
	}

	return bcm_phy_write_shadow(phydev, BCM54XX_SHD_SCR2, val);
}

int bcm_phy_get_sset_count(struct phy_device *phydev)
{
	return ARRAY_SIZE(bcm_phy_hw_stats);
}

void bcm_phy_get_strings(struct phy_device *phydev, u8 *data)
{
	unsigned int i;

	for (i = 0; i < ARRAY_SIZE(bcm_phy_hw_stats); i++)
		strlcpy(data + i * ETH_GSTRING_LEN,
			bcm_phy_hw_stats[i].string, ETH_GSTRING_LEN);
}

__attribute__((used)) static u64 bcm_phy_get_stat(struct phy_device *phydev, u64 *shadow,
			    unsigned int i)
{
	struct bcm_phy_hw_stat stat = bcm_phy_hw_stats[i];
	int val;
	u64 ret;

	val = phy_read(phydev, stat.reg);
	if (val < 0) {
		ret = U64_MAX;
	} else {
		val >>= stat.shift;
		val = val & ((1 << stat.bits) - 1);
		shadow[i] += val;
		ret = shadow[i];
	}

	return ret;
}

void bcm_phy_get_stats(struct phy_device *phydev, u64 *shadow,
		       struct ethtool_stats *stats, u64 *data)
{
	unsigned int i;

	for (i = 0; i < ARRAY_SIZE(bcm_phy_hw_stats); i++)
		data[i] = bcm_phy_get_stat(phydev, shadow, i);
}

