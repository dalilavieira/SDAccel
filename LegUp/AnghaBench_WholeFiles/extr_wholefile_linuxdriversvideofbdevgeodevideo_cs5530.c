#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct geodefb_par {scalar_t__ panel_x; scalar_t__ vid_regs; scalar_t__ enable_crt; } ;
struct TYPE_4__ {long pixclock; int sync; } ;
struct fb_info {struct geodefb_par* par; TYPE_1__ var; } ;
struct TYPE_5__ {int pll_value; long pixclock; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_2__*) ; 
 int CS5530_DCFG_CRT_HSYNC_POL ; 
 int CS5530_DCFG_CRT_SYNC_SKW_INIT ; 
 int CS5530_DCFG_CRT_SYNC_SKW_MASK ; 
 int CS5530_DCFG_CRT_VSYNC_POL ; 
 int CS5530_DCFG_DAC_BL_EN ; 
 int CS5530_DCFG_DAC_PWR_EN ; 
 int CS5530_DCFG_FP_DATA_EN ; 
 int CS5530_DCFG_FP_PWR_EN ; 
 int CS5530_DCFG_GV_PAL_BYP ; 
 int CS5530_DCFG_HSYNC_EN ; 
 int CS5530_DCFG_PWR_SEQ_DLY_INIT ; 
 int CS5530_DCFG_PWR_SEQ_DLY_MASK ; 
 int CS5530_DCFG_VSYNC_EN ; 
 scalar_t__ CS5530_DISPLAY_CONFIG ; 
 scalar_t__ CS5530_DOT_CLK_CONFIG ; 
 int EINVAL ; 
#define  FB_BLANK_HSYNC_SUSPEND 132 
#define  FB_BLANK_NORMAL 131 
#define  FB_BLANK_POWERDOWN 130 
#define  FB_BLANK_UNBLANK 129 
#define  FB_BLANK_VSYNC_SUSPEND 128 
 int FB_SYNC_HOR_HIGH_ACT ; 
 int FB_SYNC_VERT_HIGH_ACT ; 
 TYPE_2__* cs5530_pll_table ; 
 int readl (scalar_t__) ; 
 int /*<<< orphan*/  udelay (int) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static void cs5530_set_dclk_frequency(struct fb_info *info)
{
	struct geodefb_par *par = info->par;
	int i;
	u32 value;
	long min, diff;

	/* Search the table for the closest pixclock. */
	value = cs5530_pll_table[0].pll_value;
	min = cs5530_pll_table[0].pixclock - info->var.pixclock;
	if (min < 0) min = -min;
	for (i = 1; i < ARRAY_SIZE(cs5530_pll_table); i++) {
		diff = cs5530_pll_table[i].pixclock - info->var.pixclock;
		if (diff < 0L) diff = -diff;
		if (diff < min) {
			min = diff;
			value = cs5530_pll_table[i].pll_value;
		}
	}

	writel(value, par->vid_regs + CS5530_DOT_CLK_CONFIG);
	writel(value | 0x80000100, par->vid_regs + CS5530_DOT_CLK_CONFIG); /* set reset and bypass */
	udelay(500); /* wait for PLL to settle */
	writel(value & 0x7FFFFFFF, par->vid_regs + CS5530_DOT_CLK_CONFIG); /* clear reset */
	writel(value & 0x7FFFFEFF, par->vid_regs + CS5530_DOT_CLK_CONFIG); /* clear bypass */
}

__attribute__((used)) static void cs5530_configure_display(struct fb_info *info)
{
	struct geodefb_par *par = info->par;
	u32 dcfg;

	dcfg = readl(par->vid_regs + CS5530_DISPLAY_CONFIG);

	/* Clear bits from existing mode. */
	dcfg &= ~(CS5530_DCFG_CRT_SYNC_SKW_MASK | CS5530_DCFG_PWR_SEQ_DLY_MASK
		  | CS5530_DCFG_CRT_HSYNC_POL   | CS5530_DCFG_CRT_VSYNC_POL
		  | CS5530_DCFG_FP_PWR_EN       | CS5530_DCFG_FP_DATA_EN
		  | CS5530_DCFG_DAC_PWR_EN      | CS5530_DCFG_VSYNC_EN
		  | CS5530_DCFG_HSYNC_EN);

	/* Set default sync skew and power sequence delays.  */
	dcfg |= (CS5530_DCFG_CRT_SYNC_SKW_INIT | CS5530_DCFG_PWR_SEQ_DLY_INIT
		 | CS5530_DCFG_GV_PAL_BYP);

	/* Enable DACs, hsync and vsync for CRTs */
	if (par->enable_crt) {
		dcfg |= CS5530_DCFG_DAC_PWR_EN;
		dcfg |= CS5530_DCFG_HSYNC_EN | CS5530_DCFG_VSYNC_EN;
	}
	/* Enable panel power and data if using a flat panel. */
	if (par->panel_x > 0) {
		dcfg |= CS5530_DCFG_FP_PWR_EN;
		dcfg |= CS5530_DCFG_FP_DATA_EN;
	}

	/* Sync polarities. */
	if (info->var.sync & FB_SYNC_HOR_HIGH_ACT)
		dcfg |= CS5530_DCFG_CRT_HSYNC_POL;
	if (info->var.sync & FB_SYNC_VERT_HIGH_ACT)
		dcfg |= CS5530_DCFG_CRT_VSYNC_POL;

	writel(dcfg, par->vid_regs + CS5530_DISPLAY_CONFIG);
}

__attribute__((used)) static int cs5530_blank_display(struct fb_info *info, int blank_mode)
{
	struct geodefb_par *par = info->par;
	u32 dcfg;
	int blank, hsync, vsync;

	switch (blank_mode) {
	case FB_BLANK_UNBLANK:
		blank = 0; hsync = 1; vsync = 1;
		break;
	case FB_BLANK_NORMAL:
		blank = 1; hsync = 1; vsync = 1;
		break;
	case FB_BLANK_VSYNC_SUSPEND:
		blank = 1; hsync = 1; vsync = 0;
		break;
	case FB_BLANK_HSYNC_SUSPEND:
		blank = 1; hsync = 0; vsync = 1;
		break;
	case FB_BLANK_POWERDOWN:
		blank = 1; hsync = 0; vsync = 0;
		break;
	default:
		return -EINVAL;
	}

	dcfg = readl(par->vid_regs + CS5530_DISPLAY_CONFIG);

	dcfg &= ~(CS5530_DCFG_DAC_BL_EN | CS5530_DCFG_DAC_PWR_EN
		  | CS5530_DCFG_HSYNC_EN | CS5530_DCFG_VSYNC_EN
		  | CS5530_DCFG_FP_DATA_EN | CS5530_DCFG_FP_PWR_EN);

	if (par->enable_crt) {
		if (!blank)
			dcfg |= CS5530_DCFG_DAC_BL_EN | CS5530_DCFG_DAC_PWR_EN;
		if (hsync)
			dcfg |= CS5530_DCFG_HSYNC_EN;
		if (vsync)
			dcfg |= CS5530_DCFG_VSYNC_EN;
	}
	if (par->panel_x > 0) {
		if (!blank)
			dcfg |= CS5530_DCFG_FP_DATA_EN;
		if (hsync && vsync)
			dcfg |= CS5530_DCFG_FP_PWR_EN;
	}

	writel(dcfg, par->vid_regs + CS5530_DISPLAY_CONFIG);

	return 0;
}

