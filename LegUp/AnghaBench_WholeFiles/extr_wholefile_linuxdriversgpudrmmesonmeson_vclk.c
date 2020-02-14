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
typedef  int u64 ;
typedef  int /*<<< orphan*/  u16 ;
struct meson_drm {int /*<<< orphan*/  hhi; TYPE_1__* dev; } ;
typedef  enum drm_mode_status { ____Placeholder_drm_mode_status } drm_mode_status ;
struct TYPE_4__ {unsigned int pll_base_freq; unsigned int pll_od1; unsigned int pll_od2; unsigned int pll_od3; unsigned int vid_pll_div; unsigned int vclk_div; } ;
struct TYPE_3__ {int /*<<< orphan*/  of_node; } ;

/* Variables and functions */
 int CTS_ENCI_EN ; 
 int CTS_ENCI_SEL_MASK ; 
 int CTS_ENCI_SEL_SHIFT ; 
 int CTS_ENCP_EN ; 
 int CTS_ENCP_SEL_MASK ; 
 int CTS_ENCP_SEL_SHIFT ; 
 int CTS_HDMI_SYS_DIV_MASK ; 
 int CTS_HDMI_SYS_EN ; 
 int CTS_HDMI_SYS_SEL_MASK ; 
 int CTS_VDAC_EN ; 
 int CTS_VDAC_SEL_MASK ; 
 int CTS_VDAC_SEL_SHIFT ; 
 int /*<<< orphan*/  DRM_DEBUG_DRIVER (char*,unsigned int,unsigned int,unsigned int,unsigned int,...) ; 
 int /*<<< orphan*/  DRM_ERROR (char*,unsigned int) ; 
 unsigned int HDMI_FRAC_MAX_GXBB ; 
 unsigned int HDMI_FRAC_MAX_GXL ; 
 unsigned int HDMI_PLL_LOCK ; 
 int HDMI_PLL_RESET ; 
 int HDMI_TX_PIXEL_EN ; 
 int HDMI_TX_PIXEL_SEL_MASK ; 
 int HDMI_TX_PIXEL_SEL_SHIFT ; 
 int /*<<< orphan*/  HHI_HDMI_CLK_CNTL ; 
 int /*<<< orphan*/  HHI_HDMI_PLL_CNTL ; 
 int /*<<< orphan*/  HHI_HDMI_PLL_CNTL2 ; 
 int /*<<< orphan*/  HHI_HDMI_PLL_CNTL3 ; 
 int /*<<< orphan*/  HHI_HDMI_PLL_CNTL4 ; 
 int /*<<< orphan*/  HHI_HDMI_PLL_CNTL5 ; 
 int /*<<< orphan*/  HHI_HDMI_PLL_CNTL6 ; 
 int /*<<< orphan*/  HHI_VID_CLK_CNTL ; 
 int /*<<< orphan*/  HHI_VID_CLK_CNTL2 ; 
 int /*<<< orphan*/  HHI_VID_CLK_DIV ; 
 int /*<<< orphan*/  HHI_VID_PLL_CLK_DIV ; 
 int /*<<< orphan*/  HHI_VIID_CLK_CNTL ; 
 int /*<<< orphan*/  HHI_VIID_CLK_DIV ; 
 unsigned int MESON_VCLK_HDMI_148500 ; 
 unsigned int MESON_VCLK_HDMI_297000 ; 
 unsigned int MESON_VCLK_HDMI_594000 ; 
 unsigned int MESON_VCLK_HDMI_74250 ; 
 unsigned int MESON_VCLK_HDMI_DDR_148500 ; 
 unsigned int MESON_VCLK_HDMI_DDR_54000 ; 
 unsigned int MESON_VCLK_HDMI_ENCI_54000 ; 
 unsigned int MESON_VCLK_TARGET_CVBS ; 
 unsigned int MESON_VCLK_TARGET_DMT ; 
 int MODE_CLOCK_RANGE ; 
 int MODE_OK ; 
 int VCLK2_DIV1_EN ; 
 int VCLK2_DIV_EN ; 
 int VCLK2_DIV_MASK ; 
 int VCLK2_DIV_RESET ; 
 int VCLK2_EN ; 
 int VCLK2_SEL_MASK ; 
 int VCLK2_SEL_SHIFT ; 
 int VCLK2_SOFT_RESET ; 
 int VCLK_DIV12_EN ; 
 int VCLK_DIV1_EN ; 
 int VCLK_DIV2_EN ; 
 int VCLK_DIV4_EN ; 
 int VCLK_DIV6_EN ; 
 int VCLK_DIV_MASK ; 
 int VCLK_EN ; 
 int VCLK_SEL_MASK ; 
 int VID_PLL_BYPASS ; 
 unsigned int VID_PLL_DIV_1 ; 
#define  VID_PLL_DIV_12 141 
#define  VID_PLL_DIV_14 140 
#define  VID_PLL_DIV_15 139 
#define  VID_PLL_DIV_2 138 
#define  VID_PLL_DIV_2p5 137 
#define  VID_PLL_DIV_3 136 
#define  VID_PLL_DIV_3p5 135 
#define  VID_PLL_DIV_3p75 134 
#define  VID_PLL_DIV_4 133 
#define  VID_PLL_DIV_5 132 
#define  VID_PLL_DIV_6 131 
#define  VID_PLL_DIV_6p25 130 
#define  VID_PLL_DIV_7 129 
#define  VID_PLL_DIV_7p5 128 
 int VID_PLL_EN ; 
 int VID_PLL_PRESET ; 
 unsigned int XTAL_FREQ ; 
 unsigned int div_u64 (int,unsigned int) ; 
 unsigned int min (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int of_device_is_compatible (int /*<<< orphan*/ ,char const*) ; 
 TYPE_2__* params ; 
 int /*<<< orphan*/  pr_err (char*,unsigned int) ; 
 int /*<<< orphan*/  regmap_read_poll_timeout (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int,unsigned int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  regmap_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline int meson_vpu_is_compatible(struct meson_drm *priv,
					  const char *compat)
{
	return of_device_is_compatible(priv->dev->of_node, compat);
}

void meson_vid_pll_set(struct meson_drm *priv, unsigned int div)
{
	unsigned int shift_val = 0;
	unsigned int shift_sel = 0;

	/* Disable vid_pll output clock */
	regmap_update_bits(priv->hhi, HHI_VID_PLL_CLK_DIV, VID_PLL_EN, 0);
	regmap_update_bits(priv->hhi, HHI_VID_PLL_CLK_DIV, VID_PLL_PRESET, 0);

	switch (div) {
	case VID_PLL_DIV_2:
		shift_val = 0x0aaa;
		shift_sel = 0;
		break;
	case VID_PLL_DIV_2p5:
		shift_val = 0x5294;
		shift_sel = 2;
		break;
	case VID_PLL_DIV_3:
		shift_val = 0x0db6;
		shift_sel = 0;
		break;
	case VID_PLL_DIV_3p5:
		shift_val = 0x36cc;
		shift_sel = 1;
		break;
	case VID_PLL_DIV_3p75:
		shift_val = 0x6666;
		shift_sel = 2;
		break;
	case VID_PLL_DIV_4:
		shift_val = 0x0ccc;
		shift_sel = 0;
		break;
	case VID_PLL_DIV_5:
		shift_val = 0x739c;
		shift_sel = 2;
		break;
	case VID_PLL_DIV_6:
		shift_val = 0x0e38;
		shift_sel = 0;
		break;
	case VID_PLL_DIV_6p25:
		shift_val = 0x0000;
		shift_sel = 3;
		break;
	case VID_PLL_DIV_7:
		shift_val = 0x3c78;
		shift_sel = 1;
		break;
	case VID_PLL_DIV_7p5:
		shift_val = 0x78f0;
		shift_sel = 2;
		break;
	case VID_PLL_DIV_12:
		shift_val = 0x0fc0;
		shift_sel = 0;
		break;
	case VID_PLL_DIV_14:
		shift_val = 0x3f80;
		shift_sel = 1;
		break;
	case VID_PLL_DIV_15:
		shift_val = 0x7f80;
		shift_sel = 2;
		break;
	}

	if (div == VID_PLL_DIV_1)
		/* Enable vid_pll bypass to HDMI pll */
		regmap_update_bits(priv->hhi, HHI_VID_PLL_CLK_DIV,
				   VID_PLL_BYPASS, VID_PLL_BYPASS);
	else {
		/* Disable Bypass */
		regmap_update_bits(priv->hhi, HHI_VID_PLL_CLK_DIV,
				   VID_PLL_BYPASS, 0);
		/* Clear sel */
		regmap_update_bits(priv->hhi, HHI_VID_PLL_CLK_DIV,
				   3 << 16, 0);
		regmap_update_bits(priv->hhi, HHI_VID_PLL_CLK_DIV,
				   VID_PLL_PRESET, 0);
		regmap_update_bits(priv->hhi, HHI_VID_PLL_CLK_DIV,
				   0x7fff, 0);

		/* Setup sel and val */
		regmap_update_bits(priv->hhi, HHI_VID_PLL_CLK_DIV,
				   3 << 16, shift_sel << 16);
		regmap_update_bits(priv->hhi, HHI_VID_PLL_CLK_DIV,
				   VID_PLL_PRESET, VID_PLL_PRESET);
		regmap_update_bits(priv->hhi, HHI_VID_PLL_CLK_DIV,
				   0x7fff, shift_val);

		regmap_update_bits(priv->hhi, HHI_VID_PLL_CLK_DIV,
				   VID_PLL_PRESET, 0);
	}

	/* Enable the vid_pll output clock */
	regmap_update_bits(priv->hhi, HHI_VID_PLL_CLK_DIV,
				VID_PLL_EN, VID_PLL_EN);
}

__attribute__((used)) static void meson_venci_cvbs_clock_config(struct meson_drm *priv)
{
	unsigned int val;

	/* Setup PLL to output 1.485GHz */
	if (meson_vpu_is_compatible(priv, "amlogic,meson-gxbb-vpu")) {
		regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL, 0x5800023d);
		regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL2, 0x00404e00);
		regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL3, 0x0d5c5091);
		regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL4, 0x801da72c);
		regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL5, 0x71486980);
		regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL6, 0x00000e55);
		regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL, 0x4800023d);
	} else if (meson_vpu_is_compatible(priv, "amlogic,meson-gxm-vpu") ||
		   meson_vpu_is_compatible(priv, "amlogic,meson-gxl-vpu")) {
		regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL, 0x4000027b);
		regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL2, 0x800cb300);
		regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL3, 0xa6212844);
		regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL4, 0x0c4d000c);
		regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL5, 0x001fa729);
		regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL6, 0x01a31500);

		/* Reset PLL */
		regmap_update_bits(priv->hhi, HHI_HDMI_PLL_CNTL,
					HDMI_PLL_RESET, HDMI_PLL_RESET);
		regmap_update_bits(priv->hhi, HHI_HDMI_PLL_CNTL,
					HDMI_PLL_RESET, 0);
	}

	/* Poll for lock bit */
	regmap_read_poll_timeout(priv->hhi, HHI_HDMI_PLL_CNTL, val,
				 (val & HDMI_PLL_LOCK), 10, 0);

	/* Disable VCLK2 */
	regmap_update_bits(priv->hhi, HHI_VIID_CLK_CNTL, VCLK2_EN, 0);

	/* Setup vid_pll to /1 */
	meson_vid_pll_set(priv, VID_PLL_DIV_1);

	/* Setup the VCLK2 divider value to achieve 27MHz */
	regmap_update_bits(priv->hhi, HHI_VIID_CLK_DIV,
				VCLK2_DIV_MASK, (55 - 1));

	/* select vid_pll for vclk2 */
	regmap_update_bits(priv->hhi, HHI_VIID_CLK_CNTL,
				VCLK2_SEL_MASK, (4 << VCLK2_SEL_SHIFT));
	/* enable vclk2 gate */
	regmap_update_bits(priv->hhi, HHI_VIID_CLK_CNTL, VCLK2_EN, VCLK2_EN);

	/* select vclk_div1 for enci */
	regmap_update_bits(priv->hhi, HHI_VID_CLK_DIV,
				CTS_ENCI_SEL_MASK, (8 << CTS_ENCI_SEL_SHIFT));
	/* select vclk_div1 for vdac */
	regmap_update_bits(priv->hhi, HHI_VIID_CLK_DIV,
				CTS_VDAC_SEL_MASK, (8 << CTS_VDAC_SEL_SHIFT));

	/* release vclk2_div_reset and enable vclk2_div */
	regmap_update_bits(priv->hhi, HHI_VIID_CLK_DIV,
				VCLK2_DIV_EN | VCLK2_DIV_RESET, VCLK2_DIV_EN);

	/* enable vclk2_div1 gate */
	regmap_update_bits(priv->hhi, HHI_VIID_CLK_CNTL,
				VCLK2_DIV1_EN, VCLK2_DIV1_EN);

	/* reset vclk2 */
	regmap_update_bits(priv->hhi, HHI_VIID_CLK_CNTL,
				VCLK2_SOFT_RESET, VCLK2_SOFT_RESET);
	regmap_update_bits(priv->hhi, HHI_VIID_CLK_CNTL,
				VCLK2_SOFT_RESET, 0);

	/* enable enci_clk */
	regmap_update_bits(priv->hhi, HHI_VID_CLK_CNTL2,
				CTS_ENCI_EN, CTS_ENCI_EN);
	/* enable vdac_clk */
	regmap_update_bits(priv->hhi, HHI_VID_CLK_CNTL2,
				CTS_VDAC_EN, CTS_VDAC_EN);
}

__attribute__((used)) static inline unsigned int pll_od_to_reg(unsigned int od)
{
	switch (od) {
	case 1:
		return 0;
	case 2:
		return 1;
	case 4:
		return 2;
	case 8:
		return 3;
	}

	/* Invalid */
	return 0;
}

void meson_hdmi_pll_set_params(struct meson_drm *priv, unsigned int m,
			       unsigned int frac, unsigned int od1,
			       unsigned int od2, unsigned int od3)
{
	unsigned int val;

	if (meson_vpu_is_compatible(priv, "amlogic,meson-gxbb-vpu")) {
		regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL, 0x58000200 | m);
		if (frac)
			regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL2,
				     0x00004000 | frac);
		else
			regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL2,
				     0x00000000);
		regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL3, 0x0d5c5091);
		regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL4, 0x801da72c);
		regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL5, 0x71486980);
		regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL6, 0x00000e55);

		/* Enable and unreset */
		regmap_update_bits(priv->hhi, HHI_HDMI_PLL_CNTL,
				   0x7 << 28, 0x4 << 28);

		/* Poll for lock bit */
		regmap_read_poll_timeout(priv->hhi, HHI_HDMI_PLL_CNTL,
					 val, (val & HDMI_PLL_LOCK), 10, 0);
	} else if (meson_vpu_is_compatible(priv, "amlogic,meson-gxm-vpu") ||
		   meson_vpu_is_compatible(priv, "amlogic,meson-gxl-vpu")) {
		regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL, 0x40000200 | m);
		regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL2, 0x800cb000 | frac);
		regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL3, 0x860f30c4);
		regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL4, 0x0c8e0000);
		regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL5, 0x001fa729);
		regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL6, 0x01a31500);

		/* Reset PLL */
		regmap_update_bits(priv->hhi, HHI_HDMI_PLL_CNTL,
				HDMI_PLL_RESET, HDMI_PLL_RESET);
		regmap_update_bits(priv->hhi, HHI_HDMI_PLL_CNTL,
				HDMI_PLL_RESET, 0);

		/* Poll for lock bit */
		regmap_read_poll_timeout(priv->hhi, HHI_HDMI_PLL_CNTL, val,
				(val & HDMI_PLL_LOCK), 10, 0);
	}

	if (meson_vpu_is_compatible(priv, "amlogic,meson-gxbb-vpu"))
		regmap_update_bits(priv->hhi, HHI_HDMI_PLL_CNTL2,
				3 << 16, pll_od_to_reg(od1) << 16);
	else if (meson_vpu_is_compatible(priv, "amlogic,meson-gxm-vpu") ||
			meson_vpu_is_compatible(priv, "amlogic,meson-gxl-vpu"))
		regmap_update_bits(priv->hhi, HHI_HDMI_PLL_CNTL3,
				3 << 21, pll_od_to_reg(od1) << 21);

	if (meson_vpu_is_compatible(priv, "amlogic,meson-gxbb-vpu"))
		regmap_update_bits(priv->hhi, HHI_HDMI_PLL_CNTL2,
				3 << 22, pll_od_to_reg(od2) << 22);
	else if (meson_vpu_is_compatible(priv, "amlogic,meson-gxm-vpu") ||
			meson_vpu_is_compatible(priv, "amlogic,meson-gxl-vpu"))
		regmap_update_bits(priv->hhi, HHI_HDMI_PLL_CNTL3,
				3 << 23, pll_od_to_reg(od2) << 23);

	if (meson_vpu_is_compatible(priv, "amlogic,meson-gxbb-vpu"))
		regmap_update_bits(priv->hhi, HHI_HDMI_PLL_CNTL2,
				3 << 18, pll_od_to_reg(od3) << 18);
	else if (meson_vpu_is_compatible(priv, "amlogic,meson-gxm-vpu") ||
			meson_vpu_is_compatible(priv, "amlogic,meson-gxl-vpu"))
		regmap_update_bits(priv->hhi, HHI_HDMI_PLL_CNTL3,
				3 << 19, pll_od_to_reg(od3) << 19);

}

__attribute__((used)) static unsigned int meson_hdmi_pll_get_m(struct meson_drm *priv,
					 unsigned int pll_freq)
{
	/* The GXBB PLL has a /2 pre-multiplier */
	if (meson_vpu_is_compatible(priv, "amlogic,meson-gxbb-vpu"))
		pll_freq /= 2;

	return pll_freq / XTAL_FREQ;
}

__attribute__((used)) static unsigned int meson_hdmi_pll_get_frac(struct meson_drm *priv,
					    unsigned int m,
					    unsigned int pll_freq)
{
	unsigned int parent_freq = XTAL_FREQ;
	unsigned int frac_max = HDMI_FRAC_MAX_GXL;
	unsigned int frac_m;
	unsigned int frac;

	/* The GXBB PLL has a /2 pre-multiplier and a larger FRAC width */
	if (meson_vpu_is_compatible(priv, "amlogic,meson-gxbb-vpu")) {
		frac_max = HDMI_FRAC_MAX_GXBB;
		parent_freq *= 2;
	}

	/* We can have a perfect match !*/
	if (pll_freq / m == parent_freq &&
	    pll_freq % m == 0)
		return 0;

	frac = div_u64((u64)pll_freq * (u64)frac_max, parent_freq);
	frac_m = m * frac_max;
	if (frac_m > frac)
		return frac_max;
	frac -= frac_m;

	return min((u16)frac, (u16)(frac_max - 1));
}

__attribute__((used)) static bool meson_hdmi_pll_validate_params(struct meson_drm *priv,
					   unsigned int m,
					   unsigned int frac)
{
	if (meson_vpu_is_compatible(priv, "amlogic,meson-gxbb-vpu")) {
		/* Empiric supported min/max dividers */
		if (m < 53 || m > 123)
			return false;
		if (frac >= HDMI_FRAC_MAX_GXBB)
			return false;
	} else if (meson_vpu_is_compatible(priv, "amlogic,meson-gxm-vpu") ||
		   meson_vpu_is_compatible(priv, "amlogic,meson-gxl-vpu")) {
		/* Empiric supported min/max dividers */
		if (m < 106 || m > 247)
			return false;
		if (frac >= HDMI_FRAC_MAX_GXL)
			return false;
	}

	return true;
}

__attribute__((used)) static bool meson_hdmi_pll_find_params(struct meson_drm *priv,
				       unsigned int freq,
				       unsigned int *m,
				       unsigned int *frac,
				       unsigned int *od)
{
	/* Cycle from /16 to /2 */
	for (*od = 16 ; *od > 1 ; *od >>= 1) {
		*m = meson_hdmi_pll_get_m(priv, freq * *od);
		if (!*m)
			continue;
		*frac = meson_hdmi_pll_get_frac(priv, *m, freq * *od);

		DRM_DEBUG_DRIVER("PLL params for %dkHz: m=%x frac=%x od=%d\n",
				 freq, *m, *frac, *od);

		if (meson_hdmi_pll_validate_params(priv, *m, *frac))
			return true;
	}

	return false;
}

enum drm_mode_status
meson_vclk_dmt_supported_freq(struct meson_drm *priv, unsigned int freq)
{
	unsigned int od, m, frac;

	/* In DMT mode, path after PLL is always /10 */
	freq *= 10;

	if (meson_hdmi_pll_find_params(priv, freq, &m, &frac, &od))
		return MODE_OK;

	return MODE_CLOCK_RANGE;
}

__attribute__((used)) static void meson_hdmi_pll_generic_set(struct meson_drm *priv,
				       unsigned int pll_freq)
{
	unsigned int od, m, frac, od1, od2, od3;

	if (meson_hdmi_pll_find_params(priv, pll_freq, &m, &frac, &od)) {
		od3 = 1;
		if (od < 4) {
			od1 = 2;
			od2 = 1;
		} else {
			od2 = od / 4;
			od1 = od / od2;
		}

		DRM_DEBUG_DRIVER("PLL params for %dkHz: m=%x frac=%x od=%d/%d/%d\n",
				 pll_freq, m, frac, od1, od2, od3);

		meson_hdmi_pll_set_params(priv, m, frac, od1, od2, od3);

		return;
	}

	DRM_ERROR("Fatal, unable to find parameters for PLL freq %d\n",
		  pll_freq);
}

__attribute__((used)) static void meson_vclk_set(struct meson_drm *priv, unsigned int pll_base_freq,
			   unsigned int od1, unsigned int od2, unsigned int od3,
			   unsigned int vid_pll_div, unsigned int vclk_div,
			   unsigned int hdmi_tx_div, unsigned int venc_div,
			   bool hdmi_use_enci)
{
	/* Set HDMI-TX sys clock */
	regmap_update_bits(priv->hhi, HHI_HDMI_CLK_CNTL,
			   CTS_HDMI_SYS_SEL_MASK, 0);
	regmap_update_bits(priv->hhi, HHI_HDMI_CLK_CNTL,
			   CTS_HDMI_SYS_DIV_MASK, 0);
	regmap_update_bits(priv->hhi, HHI_HDMI_CLK_CNTL,
			   CTS_HDMI_SYS_EN, CTS_HDMI_SYS_EN);

	/* Set HDMI PLL rate */
	if (!od1 && !od2 && !od3) {
		meson_hdmi_pll_generic_set(priv, pll_base_freq);
	} else if (meson_vpu_is_compatible(priv, "amlogic,meson-gxbb-vpu")) {
		switch (pll_base_freq) {
		case 2970000:
			meson_hdmi_pll_set_params(priv, 0x3d, 0xe00,
						  od1, od2, od3);
			break;
		case 4320000:
			meson_hdmi_pll_set_params(priv, 0x5a, 0,
						  od1, od2, od3);
			break;
		case 5940000:
			meson_hdmi_pll_set_params(priv, 0x7b, 0xc00,
						  od1, od2, od3);
			break;
		}
	} else if (meson_vpu_is_compatible(priv, "amlogic,meson-gxm-vpu") ||
		   meson_vpu_is_compatible(priv, "amlogic,meson-gxl-vpu")) {
		switch (pll_base_freq) {
		case 2970000:
			meson_hdmi_pll_set_params(priv, 0x7b, 0x300,
						  od1, od2, od3);
			break;
		case 4320000:
			meson_hdmi_pll_set_params(priv, 0xb4, 0,
						  od1, od2, od3);
			break;
		case 5940000:
			meson_hdmi_pll_set_params(priv, 0xf7, 0x200,
						  od1, od2, od3);
			break;
		}
	}

	/* Setup vid_pll divider */
	meson_vid_pll_set(priv, vid_pll_div);

	/* Set VCLK div */
	regmap_update_bits(priv->hhi, HHI_VID_CLK_CNTL,
			   VCLK_SEL_MASK, 0);
	regmap_update_bits(priv->hhi, HHI_VID_CLK_DIV,
			   VCLK_DIV_MASK, vclk_div - 1);

	/* Set HDMI-TX source */
	switch (hdmi_tx_div) {
	case 1:
		/* enable vclk_div1 gate */
		regmap_update_bits(priv->hhi, HHI_VID_CLK_CNTL,
				   VCLK_DIV1_EN, VCLK_DIV1_EN);

		/* select vclk_div1 for HDMI-TX */
		regmap_update_bits(priv->hhi, HHI_HDMI_CLK_CNTL,
				   HDMI_TX_PIXEL_SEL_MASK, 0);
		break;
	case 2:
		/* enable vclk_div2 gate */
		regmap_update_bits(priv->hhi, HHI_VID_CLK_CNTL,
				   VCLK_DIV2_EN, VCLK_DIV2_EN);

		/* select vclk_div2 for HDMI-TX */
		regmap_update_bits(priv->hhi, HHI_HDMI_CLK_CNTL,
			HDMI_TX_PIXEL_SEL_MASK, 1 << HDMI_TX_PIXEL_SEL_SHIFT);
		break;
	case 4:
		/* enable vclk_div4 gate */
		regmap_update_bits(priv->hhi, HHI_VID_CLK_CNTL,
				   VCLK_DIV4_EN, VCLK_DIV4_EN);

		/* select vclk_div4 for HDMI-TX */
		regmap_update_bits(priv->hhi, HHI_HDMI_CLK_CNTL,
			HDMI_TX_PIXEL_SEL_MASK, 2 << HDMI_TX_PIXEL_SEL_SHIFT);
		break;
	case 6:
		/* enable vclk_div6 gate */
		regmap_update_bits(priv->hhi, HHI_VID_CLK_CNTL,
				   VCLK_DIV6_EN, VCLK_DIV6_EN);

		/* select vclk_div6 for HDMI-TX */
		regmap_update_bits(priv->hhi, HHI_HDMI_CLK_CNTL,
			HDMI_TX_PIXEL_SEL_MASK, 3 << HDMI_TX_PIXEL_SEL_SHIFT);
		break;
	case 12:
		/* enable vclk_div12 gate */
		regmap_update_bits(priv->hhi, HHI_VID_CLK_CNTL,
				   VCLK_DIV12_EN, VCLK_DIV12_EN);

		/* select vclk_div12 for HDMI-TX */
		regmap_update_bits(priv->hhi, HHI_HDMI_CLK_CNTL,
			HDMI_TX_PIXEL_SEL_MASK, 4 << HDMI_TX_PIXEL_SEL_SHIFT);
		break;
	}
	regmap_update_bits(priv->hhi, HHI_VID_CLK_CNTL2,
				   HDMI_TX_PIXEL_EN, HDMI_TX_PIXEL_EN);

	/* Set ENCI/ENCP Source */
	switch (venc_div) {
	case 1:
		/* enable vclk_div1 gate */
		regmap_update_bits(priv->hhi, HHI_VID_CLK_CNTL,
				   VCLK_DIV1_EN, VCLK_DIV1_EN);

		if (hdmi_use_enci)
			/* select vclk_div1 for enci */
			regmap_update_bits(priv->hhi, HHI_VID_CLK_DIV,
					   CTS_ENCI_SEL_MASK, 0);
		else
			/* select vclk_div1 for encp */
			regmap_update_bits(priv->hhi, HHI_VID_CLK_DIV,
					   CTS_ENCP_SEL_MASK, 0);
		break;
	case 2:
		/* enable vclk_div2 gate */
		regmap_update_bits(priv->hhi, HHI_VID_CLK_CNTL,
				   VCLK_DIV2_EN, VCLK_DIV2_EN);

		if (hdmi_use_enci)
			/* select vclk_div2 for enci */
			regmap_update_bits(priv->hhi, HHI_VID_CLK_DIV,
				CTS_ENCI_SEL_MASK, 1 << CTS_ENCI_SEL_SHIFT);
		else
			/* select vclk_div2 for encp */
			regmap_update_bits(priv->hhi, HHI_VID_CLK_DIV,
				CTS_ENCP_SEL_MASK, 1 << CTS_ENCP_SEL_SHIFT);
		break;
	case 4:
		/* enable vclk_div4 gate */
		regmap_update_bits(priv->hhi, HHI_VID_CLK_CNTL,
				   VCLK_DIV4_EN, VCLK_DIV4_EN);

		if (hdmi_use_enci)
			/* select vclk_div4 for enci */
			regmap_update_bits(priv->hhi, HHI_VID_CLK_DIV,
				CTS_ENCI_SEL_MASK, 2 << CTS_ENCI_SEL_SHIFT);
		else
			/* select vclk_div4 for encp */
			regmap_update_bits(priv->hhi, HHI_VID_CLK_DIV,
				CTS_ENCP_SEL_MASK, 2 << CTS_ENCP_SEL_SHIFT);
		break;
	case 6:
		/* enable vclk_div6 gate */
		regmap_update_bits(priv->hhi, HHI_VID_CLK_CNTL,
				   VCLK_DIV6_EN, VCLK_DIV6_EN);

		if (hdmi_use_enci)
			/* select vclk_div6 for enci */
			regmap_update_bits(priv->hhi, HHI_VID_CLK_DIV,
				CTS_ENCI_SEL_MASK, 3 << CTS_ENCI_SEL_SHIFT);
		else
			/* select vclk_div6 for encp */
			regmap_update_bits(priv->hhi, HHI_VID_CLK_DIV,
				CTS_ENCP_SEL_MASK, 3 << CTS_ENCP_SEL_SHIFT);
		break;
	case 12:
		/* enable vclk_div12 gate */
		regmap_update_bits(priv->hhi, HHI_VID_CLK_CNTL,
				   VCLK_DIV12_EN, VCLK_DIV12_EN);

		if (hdmi_use_enci)
			/* select vclk_div12 for enci */
			regmap_update_bits(priv->hhi, HHI_VID_CLK_DIV,
				CTS_ENCI_SEL_MASK, 4 << CTS_ENCI_SEL_SHIFT);
		else
			/* select vclk_div12 for encp */
			regmap_update_bits(priv->hhi, HHI_VID_CLK_DIV,
				CTS_ENCP_SEL_MASK, 4 << CTS_ENCP_SEL_SHIFT);
		break;
	}

	if (hdmi_use_enci)
		/* Enable ENCI clock gate */
		regmap_update_bits(priv->hhi, HHI_VID_CLK_CNTL2,
				   CTS_ENCI_EN, CTS_ENCI_EN);
	else
		/* Enable ENCP clock gate */
		regmap_update_bits(priv->hhi, HHI_VID_CLK_CNTL2,
				   CTS_ENCP_EN, CTS_ENCP_EN);

	regmap_update_bits(priv->hhi, HHI_VID_CLK_CNTL, VCLK_EN, VCLK_EN);
}

void meson_vclk_setup(struct meson_drm *priv, unsigned int target,
		      unsigned int vclk_freq, unsigned int venc_freq,
		      unsigned int dac_freq, bool hdmi_use_enci)
{
	unsigned int freq;
	unsigned int hdmi_tx_div;
	unsigned int venc_div;

	if (target == MESON_VCLK_TARGET_CVBS) {
		meson_venci_cvbs_clock_config(priv);
		return;
	} else if (target == MESON_VCLK_TARGET_DMT) {
		/* The DMT clock path is fixed after the PLL:
		 * - automatic PLL freq + OD management
		 * - vid_pll_div = VID_PLL_DIV_5
		 * - vclk_div = 2
		 * - hdmi_tx_div = 1
		 * - venc_div = 1
		 * - encp encoder
		 */
		meson_vclk_set(priv, vclk_freq * 10, 0, 0, 0,
			       VID_PLL_DIV_5, 2, 1, 1, false);
		return;
	}

	hdmi_tx_div = vclk_freq / dac_freq;

	if (hdmi_tx_div == 0) {
		pr_err("Fatal Error, invalid HDMI-TX freq %d\n",
		       dac_freq);
		return;
	}

	venc_div = vclk_freq / venc_freq;

	if (venc_div == 0) {
		pr_err("Fatal Error, invalid HDMI venc freq %d\n",
		       venc_freq);
		return;
	}

	switch (vclk_freq) {
	case 54000:
		if (hdmi_use_enci)
			freq = MESON_VCLK_HDMI_ENCI_54000;
		else
			freq = MESON_VCLK_HDMI_DDR_54000;
		break;
	case 74250:
		freq = MESON_VCLK_HDMI_74250;
		break;
	case 148500:
		if (dac_freq != 148500)
			freq = MESON_VCLK_HDMI_DDR_148500;
		else
			freq = MESON_VCLK_HDMI_148500;
		break;
	case 297000:
		freq = MESON_VCLK_HDMI_297000;
		break;
	case 594000:
		freq = MESON_VCLK_HDMI_594000;
		break;
	default:
		pr_err("Fatal Error, invalid HDMI vclk freq %d\n",
		       vclk_freq);
		return;
	}

	meson_vclk_set(priv, params[freq].pll_base_freq,
		       params[freq].pll_od1, params[freq].pll_od2,
		       params[freq].pll_od3, params[freq].vid_pll_div,
		       params[freq].vclk_div, hdmi_tx_div, venc_div,
		       hdmi_use_enci);
}

