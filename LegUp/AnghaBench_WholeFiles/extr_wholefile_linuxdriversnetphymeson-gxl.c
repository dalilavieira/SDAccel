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
typedef  int uint16_t ;
typedef  int u16 ;
struct phy_device {scalar_t__ autoneg; scalar_t__ interrupts; } ;

/* Variables and functions */
 scalar_t__ AUTONEG_ENABLE ; 
 unsigned int BANK_BIST ; 
 unsigned int BANK_WOL ; 
 int EXPANSION_NWAY ; 
 int FIELD_PREP (int /*<<< orphan*/ ,unsigned int) ; 
 unsigned int FR_PLL_CONTROL ; 
 unsigned int FR_PLL_DIV0 ; 
 unsigned int FR_PLL_DIV1 ; 
 int INTSRC_ANEG_COMPLETE ; 
 int INTSRC_ANEG_LP_ACK ; 
 int INTSRC_ANEG_PR ; 
 int /*<<< orphan*/  INTSRC_FLAG ; 
 int INTSRC_LINK_DOWN ; 
 int /*<<< orphan*/  INTSRC_MASK ; 
 int INTSRC_PARALLEL_FAULT ; 
 int INTSRC_REMOTE_FAULT ; 
 int LPA_LPACK ; 
 unsigned int LPI_STATUS ; 
 int LPI_STATUS_RSV12 ; 
 int /*<<< orphan*/  MII_EXPANSION ; 
 int /*<<< orphan*/  MII_LPA ; 
 scalar_t__ PHY_INTERRUPT_ENABLED ; 
 int /*<<< orphan*/  TSTCNTL ; 
 int TSTCNTL_READ ; 
 int /*<<< orphan*/  TSTCNTL_READ_ADDRESS ; 
 int /*<<< orphan*/  TSTCNTL_REG_BANK_SEL ; 
 int TSTCNTL_TEST_MODE ; 
 int TSTCNTL_WRITE ; 
 int /*<<< orphan*/  TSTCNTL_WRITE_ADDRESS ; 
 int /*<<< orphan*/  TSTREAD1 ; 
 int /*<<< orphan*/  TSTWRITE ; 
 int genphy_aneg_done (struct phy_device*) ; 
 int genphy_config_init (struct phy_device*) ; 
 int genphy_read_status (struct phy_device*) ; 
 int genphy_restart_aneg (struct phy_device*) ; 
 int phy_read (struct phy_device*,int /*<<< orphan*/ ) ; 
 int phy_write (struct phy_device*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  phydev_dbg (struct phy_device*,char*) ; 

__attribute__((used)) static int meson_gxl_open_banks(struct phy_device *phydev)
{
	int ret;

	/* Enable Analog and DSP register Bank access by
	 * toggling TSTCNTL_TEST_MODE bit in the TSTCNTL register
	 */
	ret = phy_write(phydev, TSTCNTL, 0);
	if (ret)
		return ret;
	ret = phy_write(phydev, TSTCNTL, TSTCNTL_TEST_MODE);
	if (ret)
		return ret;
	ret = phy_write(phydev, TSTCNTL, 0);
	if (ret)
		return ret;
	return phy_write(phydev, TSTCNTL, TSTCNTL_TEST_MODE);
}

__attribute__((used)) static void meson_gxl_close_banks(struct phy_device *phydev)
{
	phy_write(phydev, TSTCNTL, 0);
}

__attribute__((used)) static int meson_gxl_read_reg(struct phy_device *phydev,
			      unsigned int bank, unsigned int reg)
{
	int ret;

	ret = meson_gxl_open_banks(phydev);
	if (ret)
		goto out;

	ret = phy_write(phydev, TSTCNTL, TSTCNTL_READ |
			FIELD_PREP(TSTCNTL_REG_BANK_SEL, bank) |
			TSTCNTL_TEST_MODE |
			FIELD_PREP(TSTCNTL_READ_ADDRESS, reg));
	if (ret)
		goto out;

	ret = phy_read(phydev, TSTREAD1);
out:
	/* Close the bank access on our way out */
	meson_gxl_close_banks(phydev);
	return ret;
}

__attribute__((used)) static int meson_gxl_write_reg(struct phy_device *phydev,
			       unsigned int bank, unsigned int reg,
			       uint16_t value)
{
	int ret;

	ret = meson_gxl_open_banks(phydev);
	if (ret)
		goto out;

	ret = phy_write(phydev, TSTWRITE, value);
	if (ret)
		goto out;

	ret = phy_write(phydev, TSTCNTL, TSTCNTL_WRITE |
			FIELD_PREP(TSTCNTL_REG_BANK_SEL, bank) |
			TSTCNTL_TEST_MODE |
			FIELD_PREP(TSTCNTL_WRITE_ADDRESS, reg));

out:
	/* Close the bank access on our way out */
	meson_gxl_close_banks(phydev);
	return ret;
}

__attribute__((used)) static int meson_gxl_config_init(struct phy_device *phydev)
{
	int ret;

	/* Enable fractional PLL */
	ret = meson_gxl_write_reg(phydev, BANK_BIST, FR_PLL_CONTROL, 0x5);
	if (ret)
		return ret;

	/* Program fraction FR_PLL_DIV1 */
	ret = meson_gxl_write_reg(phydev, BANK_BIST, FR_PLL_DIV1, 0x029a);
	if (ret)
		return ret;

	/* Program fraction FR_PLL_DIV1 */
	ret = meson_gxl_write_reg(phydev, BANK_BIST, FR_PLL_DIV0, 0xaaaa);
	if (ret)
		return ret;

	return genphy_config_init(phydev);
}

__attribute__((used)) static int meson_gxl_read_status(struct phy_device *phydev)
{
	int ret, wol, lpa, exp;

	if (phydev->autoneg == AUTONEG_ENABLE) {
		ret = genphy_aneg_done(phydev);
		if (ret < 0)
			return ret;
		else if (!ret)
			goto read_status_continue;

		/* Aneg is done, let's check everything is fine */
		wol = meson_gxl_read_reg(phydev, BANK_WOL, LPI_STATUS);
		if (wol < 0)
			return wol;

		lpa = phy_read(phydev, MII_LPA);
		if (lpa < 0)
			return lpa;

		exp = phy_read(phydev, MII_EXPANSION);
		if (exp < 0)
			return exp;

		if (!(wol & LPI_STATUS_RSV12) ||
		    ((exp & EXPANSION_NWAY) && !(lpa & LPA_LPACK))) {
			/* Looks like aneg failed after all */
			phydev_dbg(phydev, "LPA corruption - aneg restart\n");
			return genphy_restart_aneg(phydev);
		}
	}

read_status_continue:
	return genphy_read_status(phydev);
}

__attribute__((used)) static int meson_gxl_ack_interrupt(struct phy_device *phydev)
{
	int ret = phy_read(phydev, INTSRC_FLAG);

	return ret < 0 ? ret : 0;
}

__attribute__((used)) static int meson_gxl_config_intr(struct phy_device *phydev)
{
	u16 val;
	int ret;

	if (phydev->interrupts == PHY_INTERRUPT_ENABLED) {
		val = INTSRC_ANEG_PR
			| INTSRC_PARALLEL_FAULT
			| INTSRC_ANEG_LP_ACK
			| INTSRC_LINK_DOWN
			| INTSRC_REMOTE_FAULT
			| INTSRC_ANEG_COMPLETE;
	} else {
		val = 0;
	}

	/* Ack any pending IRQ */
	ret = meson_gxl_ack_interrupt(phydev);
	if (ret)
		return ret;

	return phy_write(phydev, INTSRC_MASK, val);
}

