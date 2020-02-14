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
typedef  void* uint32_t ;
typedef  int u64 ;
typedef  unsigned long u32 ;
struct gxfb_par {scalar_t__ enable_crt; scalar_t__ vid_regs; scalar_t__ dc_regs; scalar_t__ gp_regs; } ;
struct gx_pll_entry {int sys_rstpll_bits; scalar_t__ dotpll_value; scalar_t__ pixclock; } ;
struct TYPE_3__ {unsigned long yres; int sync; scalar_t__ pixclock; } ;
struct fb_info {struct gxfb_par* par; TYPE_1__ var; } ;
struct TYPE_4__ {int x86_stepping; } ;

/* Variables and functions */
 int ARRAY_SIZE (struct gx_pll_entry*) ; 
 int EINVAL ; 
#define  FB_BLANK_HSYNC_SUSPEND 132 
#define  FB_BLANK_NORMAL 131 
#define  FB_BLANK_POWERDOWN 130 
#define  FB_BLANK_UNBLANK 129 
#define  FB_BLANK_VSYNC_SUSPEND 128 
 int FB_SYNC_HOR_HIGH_ACT ; 
 int FB_SYNC_VERT_HIGH_ACT ; 
 int FP_DFC ; 
 void* FP_DFC_NFI ; 
 int FP_PM ; 
 unsigned long FP_PM_P ; 
 int FP_PT1 ; 
 unsigned long FP_PT1_VSIZE_MASK ; 
 unsigned long FP_PT1_VSIZE_SHIFT ; 
 int FP_PT2 ; 
 unsigned long FP_PT2_HSP ; 
 unsigned long FP_PT2_VSP ; 
 int /*<<< orphan*/  MSR_GLCP_DOTPLL ; 
 int MSR_GLCP_DOTPLL_BYPASS ; 
 int MSR_GLCP_DOTPLL_DOTRESET ; 
 int MSR_GLCP_DOTPLL_LOCK ; 
 int /*<<< orphan*/  MSR_GLCP_SYS_RSTPLL ; 
 int MSR_GLCP_SYS_RSTPLL_DOTPOSTDIV3 ; 
 int MSR_GLCP_SYS_RSTPLL_DOTPREDIV2 ; 
 int MSR_GLCP_SYS_RSTPLL_DOTPREMULT2 ; 
 int /*<<< orphan*/  MSR_GX_MSR_PADSEL ; 
 unsigned long MSR_GX_MSR_PADSEL_MASK ; 
 unsigned long MSR_GX_MSR_PADSEL_TFT ; 
 int VP_DCFG ; 
 unsigned long VP_DCFG_CRT_EN ; 
 unsigned long VP_DCFG_CRT_HSYNC_POL ; 
 unsigned long VP_DCFG_CRT_SYNC_SKW ; 
 unsigned long VP_DCFG_CRT_SYNC_SKW_DEFAULT ; 
 unsigned long VP_DCFG_CRT_VSYNC_POL ; 
 unsigned long VP_DCFG_DAC_BL_EN ; 
 unsigned long VP_DCFG_FP_DATA_EN ; 
 unsigned long VP_DCFG_FP_PWR_EN ; 
 unsigned long VP_DCFG_HSYNC_EN ; 
 unsigned long VP_DCFG_VSYNC_EN ; 
 scalar_t__ VP_FP_START ; 
 int VP_MISC ; 
 unsigned long VP_MISC_APWRDN ; 
 unsigned long VP_MISC_DACPWRDN ; 
 unsigned long VP_MISC_GAM_EN ; 
 long abs (scalar_t__) ; 
 TYPE_2__ cpu_data (int /*<<< orphan*/ ) ; 
 struct gx_pll_entry* gx_pll_table_14MHz ; 
 struct gx_pll_entry* gx_pll_table_48MHz ; 
 int /*<<< orphan*/  rdmsrl (int /*<<< orphan*/ ,unsigned long) ; 
 void* readl (scalar_t__) ; 
 int /*<<< orphan*/  writel (void*,scalar_t__) ; 
 int /*<<< orphan*/  wrmsrl (int /*<<< orphan*/ ,unsigned long) ; 

__attribute__((used)) static inline uint32_t read_gp(struct gxfb_par *par, int reg)
{
	return readl(par->gp_regs + 4*reg);
}

__attribute__((used)) static inline void write_gp(struct gxfb_par *par, int reg, uint32_t val)
{
	writel(val, par->gp_regs + 4*reg);
}

__attribute__((used)) static inline uint32_t read_dc(struct gxfb_par *par, int reg)
{
	return readl(par->dc_regs + 4*reg);
}

__attribute__((used)) static inline void write_dc(struct gxfb_par *par, int reg, uint32_t val)
{
	writel(val, par->dc_regs + 4*reg);
}

__attribute__((used)) static inline uint32_t read_vp(struct gxfb_par *par, int reg)
{
	return readl(par->vid_regs + 8*reg);
}

__attribute__((used)) static inline void write_vp(struct gxfb_par *par, int reg, uint32_t val)
{
	writel(val, par->vid_regs + 8*reg);
}

__attribute__((used)) static inline uint32_t read_fp(struct gxfb_par *par, int reg)
{
	return readl(par->vid_regs + 8*reg + VP_FP_START);
}

__attribute__((used)) static inline void write_fp(struct gxfb_par *par, int reg, uint32_t val)
{
	writel(val, par->vid_regs + 8*reg + VP_FP_START);
}

void gx_set_dclk_frequency(struct fb_info *info)
{
	const struct gx_pll_entry *pll_table;
	int pll_table_len;
	int i, best_i;
	long min, diff;
	u64 dotpll, sys_rstpll;
	int timeout = 1000;

	/* Rev. 1 Geode GXs use a 14 MHz reference clock instead of 48 MHz. */
	if (cpu_data(0).x86_stepping == 1) {
		pll_table = gx_pll_table_14MHz;
		pll_table_len = ARRAY_SIZE(gx_pll_table_14MHz);
	} else {
		pll_table = gx_pll_table_48MHz;
		pll_table_len = ARRAY_SIZE(gx_pll_table_48MHz);
	}

	/* Search the table for the closest pixclock. */
	best_i = 0;
	min = abs(pll_table[0].pixclock - info->var.pixclock);
	for (i = 1; i < pll_table_len; i++) {
		diff = abs(pll_table[i].pixclock - info->var.pixclock);
		if (diff < min) {
			min = diff;
			best_i = i;
		}
	}

	rdmsrl(MSR_GLCP_SYS_RSTPLL, sys_rstpll);
	rdmsrl(MSR_GLCP_DOTPLL, dotpll);

	/* Program new M, N and P. */
	dotpll &= 0x00000000ffffffffull;
	dotpll |= (u64)pll_table[best_i].dotpll_value << 32;
	dotpll |= MSR_GLCP_DOTPLL_DOTRESET;
	dotpll &= ~MSR_GLCP_DOTPLL_BYPASS;

	wrmsrl(MSR_GLCP_DOTPLL, dotpll);

	/* Program dividers. */
	sys_rstpll &= ~( MSR_GLCP_SYS_RSTPLL_DOTPREDIV2
			 | MSR_GLCP_SYS_RSTPLL_DOTPREMULT2
			 | MSR_GLCP_SYS_RSTPLL_DOTPOSTDIV3 );
	sys_rstpll |= pll_table[best_i].sys_rstpll_bits;

	wrmsrl(MSR_GLCP_SYS_RSTPLL, sys_rstpll);

	/* Clear reset bit to start PLL. */
	dotpll &= ~(MSR_GLCP_DOTPLL_DOTRESET);
	wrmsrl(MSR_GLCP_DOTPLL, dotpll);

	/* Wait for LOCK bit. */
	do {
		rdmsrl(MSR_GLCP_DOTPLL, dotpll);
	} while (timeout-- && !(dotpll & MSR_GLCP_DOTPLL_LOCK));
}

__attribute__((used)) static void
gx_configure_tft(struct fb_info *info)
{
	struct gxfb_par *par = info->par;
	unsigned long val;
	unsigned long fp;

	/* Set up the DF pad select MSR */

	rdmsrl(MSR_GX_MSR_PADSEL, val);
	val &= ~MSR_GX_MSR_PADSEL_MASK;
	val |= MSR_GX_MSR_PADSEL_TFT;
	wrmsrl(MSR_GX_MSR_PADSEL, val);

	/* Turn off the panel */

	fp = read_fp(par, FP_PM);
	fp &= ~FP_PM_P;
	write_fp(par, FP_PM, fp);

	/* Set timing 1 */

	fp = read_fp(par, FP_PT1);
	fp &= FP_PT1_VSIZE_MASK;
	fp |= info->var.yres << FP_PT1_VSIZE_SHIFT;
	write_fp(par, FP_PT1, fp);

	/* Timing 2 */
	/* Set bits that are always on for TFT */

	fp = 0x0F100000;

	/* Configure sync polarity */

	if (!(info->var.sync & FB_SYNC_VERT_HIGH_ACT))
		fp |= FP_PT2_VSP;

	if (!(info->var.sync & FB_SYNC_HOR_HIGH_ACT))
		fp |= FP_PT2_HSP;

	write_fp(par, FP_PT2, fp);

	/*  Set the dither control */
	write_fp(par, FP_DFC, FP_DFC_NFI);

	/* Enable the FP data and power (in case the BIOS didn't) */

	fp = read_vp(par, VP_DCFG);
	fp |= VP_DCFG_FP_PWR_EN | VP_DCFG_FP_DATA_EN;
	write_vp(par, VP_DCFG, fp);

	/* Unblank the panel */

	fp = read_fp(par, FP_PM);
	fp |= FP_PM_P;
	write_fp(par, FP_PM, fp);
}

void gx_configure_display(struct fb_info *info)
{
	struct gxfb_par *par = info->par;
	u32 dcfg, misc;

	/* Write the display configuration */
	dcfg = read_vp(par, VP_DCFG);

	/* Disable hsync and vsync */
	dcfg &= ~(VP_DCFG_VSYNC_EN | VP_DCFG_HSYNC_EN);
	write_vp(par, VP_DCFG, dcfg);

	/* Clear bits from existing mode. */
	dcfg &= ~(VP_DCFG_CRT_SYNC_SKW
		  | VP_DCFG_CRT_HSYNC_POL   | VP_DCFG_CRT_VSYNC_POL
		  | VP_DCFG_VSYNC_EN        | VP_DCFG_HSYNC_EN);

	/* Set default sync skew.  */
	dcfg |= VP_DCFG_CRT_SYNC_SKW_DEFAULT;

	/* Enable hsync and vsync. */
	dcfg |= VP_DCFG_HSYNC_EN | VP_DCFG_VSYNC_EN;

	misc = read_vp(par, VP_MISC);

	/* Disable gamma correction */
	misc |= VP_MISC_GAM_EN;

	if (par->enable_crt) {

		/* Power up the CRT DACs */
		misc &= ~(VP_MISC_APWRDN | VP_MISC_DACPWRDN);
		write_vp(par, VP_MISC, misc);

		/* Only change the sync polarities if we are running
		 * in CRT mode.  The FP polarities will be handled in
		 * gxfb_configure_tft */
		if (!(info->var.sync & FB_SYNC_HOR_HIGH_ACT))
			dcfg |= VP_DCFG_CRT_HSYNC_POL;
		if (!(info->var.sync & FB_SYNC_VERT_HIGH_ACT))
			dcfg |= VP_DCFG_CRT_VSYNC_POL;
	} else {
		/* Power down the CRT DACs if in FP mode */
		misc |= (VP_MISC_APWRDN | VP_MISC_DACPWRDN);
		write_vp(par, VP_MISC, misc);
	}

	/* Enable the display logic */
	/* Set up the DACS to blank normally */

	dcfg |= VP_DCFG_CRT_EN | VP_DCFG_DAC_BL_EN;

	/* Enable the external DAC VREF? */

	write_vp(par, VP_DCFG, dcfg);

	/* Set up the flat panel (if it is enabled) */

	if (par->enable_crt == 0)
		gx_configure_tft(info);
}

int gx_blank_display(struct fb_info *info, int blank_mode)
{
	struct gxfb_par *par = info->par;
	u32 dcfg, fp_pm;
	int blank, hsync, vsync, crt;

	/* CRT power saving modes. */
	switch (blank_mode) {
	case FB_BLANK_UNBLANK:
		blank = 0; hsync = 1; vsync = 1; crt = 1;
		break;
	case FB_BLANK_NORMAL:
		blank = 1; hsync = 1; vsync = 1; crt = 1;
		break;
	case FB_BLANK_VSYNC_SUSPEND:
		blank = 1; hsync = 1; vsync = 0; crt = 1;
		break;
	case FB_BLANK_HSYNC_SUSPEND:
		blank = 1; hsync = 0; vsync = 1; crt = 1;
		break;
	case FB_BLANK_POWERDOWN:
		blank = 1; hsync = 0; vsync = 0; crt = 0;
		break;
	default:
		return -EINVAL;
	}
	dcfg = read_vp(par, VP_DCFG);
	dcfg &= ~(VP_DCFG_DAC_BL_EN | VP_DCFG_HSYNC_EN | VP_DCFG_VSYNC_EN |
			VP_DCFG_CRT_EN);
	if (!blank)
		dcfg |= VP_DCFG_DAC_BL_EN;
	if (hsync)
		dcfg |= VP_DCFG_HSYNC_EN;
	if (vsync)
		dcfg |= VP_DCFG_VSYNC_EN;
	if (crt)
		dcfg |= VP_DCFG_CRT_EN;
	write_vp(par, VP_DCFG, dcfg);

	/* Power on/off flat panel. */

	if (par->enable_crt == 0) {
		fp_pm = read_fp(par, FP_PM);
		if (blank_mode == FB_BLANK_POWERDOWN)
			fp_pm &= ~FP_PM_P;
		else
			fp_pm |= FP_PM_P;
		write_fp(par, FP_PM, fp_pm);
	}

	return 0;
}

