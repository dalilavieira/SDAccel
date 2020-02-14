#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u_int ;
typedef  int u32 ;
typedef  int u16 ;
struct TYPE_4__ {int /*<<< orphan*/  mirror; } ;
struct omapfb_plane_struct {TYPE_1__ info; } ;
struct omapfb_mem_region {int size; unsigned long paddr; int alloc; int /*<<< orphan*/ * vaddr; } ;
struct omapfb_mem_desc {int region_cnt; struct omapfb_mem_region* region; } ;
struct omapfb_device {int /*<<< orphan*/  dev; struct lcd_panel* panel; TYPE_2__** fb_info; } ;
struct omapfb_caps {int dummy; } ;
struct lcd_panel {int x_res; int y_res; int config; int hsw; int hfp; int hbp; int vsw; int vfp; int vbp; unsigned long pcd; int pixel_clock; int acb; int bpp; int /*<<< orphan*/  name; } ;
struct fb_var_screeninfo {int rotate; } ;
struct clk {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  enum omapfb_update_mode { ____Placeholder_omapfb_update_mode } omapfb_update_mode ;
typedef  enum lcdc_load_mode { ____Placeholder_lcdc_load_mode } lcdc_load_mode ;
struct TYPE_6__ {int irq_mask; unsigned long vram_phys; unsigned long frame_offset; int color_mode; int xres; int bpp; int yres; int screen_width; int palette_code; int palette_size; int ext_mode; scalar_t__ update_mode; unsigned long palette_phys; void (* dma_callback ) (void*) ;void* dma_callback_data; int vram_size; struct clk* lcd_ck; struct omapfb_device* fbdev; int /*<<< orphan*/ * vram_virt; int /*<<< orphan*/ * palette_virt; int /*<<< orphan*/  palette_load_complete; int /*<<< orphan*/  last_frame_complete; } ;
struct TYPE_5__ {struct fb_var_screeninfo var; struct omapfb_plane_struct* par; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG () ; 
 int /*<<< orphan*/  BUG_ON (int /*<<< orphan*/ ) ; 
 int EBUSY ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ HZ ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (struct clk*) ; 
 int MAX_PALETTE_SIZE ; 
 int /*<<< orphan*/  MODULE_NAME ; 
#define  OMAPFB_AUTO_UPDATE 140 
#define  OMAPFB_COLOR_CLUT_8BPP 139 
#define  OMAPFB_COLOR_RGB444 138 
#define  OMAPFB_COLOR_RGB565 137 
#define  OMAPFB_COLOR_YUV420 136 
#define  OMAPFB_COLOR_YUV422 135 
 int OMAPFB_PLANE_GFX ; 
#define  OMAPFB_UPDATE_DISABLED 134 
#define  OMAP_DMA_DATA_TYPE_S16 133 
#define  OMAP_DMA_DATA_TYPE_S32 132 
#define  OMAP_DMA_DATA_TYPE_S8 131 
 int /*<<< orphan*/  OMAP_LCDC_CONTROL ; 
 int OMAP_LCDC_CTRL_LCD_EN ; 
 int OMAP_LCDC_CTRL_LCD_TFT ; 
 int /*<<< orphan*/  OMAP_LCDC_IRQ ; 
 int OMAP_LCDC_IRQ_DONE ; 
 int OMAP_LCDC_IRQ_LOADED_PALETTE ; 
 int OMAP_LCDC_IRQ_MASK ; 
#define  OMAP_LCDC_LOAD_FRAME 130 
#define  OMAP_LCDC_LOAD_PALETTE 129 
#define  OMAP_LCDC_LOAD_PALETTE_AND_FRAME 128 
 int OMAP_LCDC_PANEL_TFT ; 
 int OMAP_LCDC_SIGNAL_MASK ; 
 int /*<<< orphan*/  OMAP_LCDC_STATUS ; 
 int OMAP_LCDC_STAT_ABC ; 
 int OMAP_LCDC_STAT_DONE ; 
 int OMAP_LCDC_STAT_FUF ; 
 int OMAP_LCDC_STAT_LINE_INT ; 
 int OMAP_LCDC_STAT_LOADED_PALETTE ; 
 int OMAP_LCDC_STAT_SYNC_LOST ; 
 int OMAP_LCDC_STAT_VSYNC ; 
 int /*<<< orphan*/  OMAP_LCDC_TIMING0 ; 
 int /*<<< orphan*/  OMAP_LCDC_TIMING1 ; 
 int /*<<< orphan*/  OMAP_LCDC_TIMING2 ; 
 int PAGE_ALIGN (int) ; 
 int PTR_ERR (struct clk*) ; 
 int /*<<< orphan*/  clk_disable (struct clk*) ; 
 int /*<<< orphan*/  clk_enable (struct clk*) ; 
 void* clk_get (int /*<<< orphan*/ ,char*) ; 
 void* clk_get_rate (struct clk*) ; 
 int /*<<< orphan*/  clk_put (struct clk*) ; 
 int clk_set_rate (struct clk*,int) ; 
 int /*<<< orphan*/  complete (int /*<<< orphan*/ *) ; 
 scalar_t__ cpu_is_omap15xx () ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,int,...) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ ,char*,unsigned long,...) ; 
 void* dma_alloc_wc (int /*<<< orphan*/ ,int,unsigned long*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dma_free_wc (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  free_irq (int /*<<< orphan*/ ,struct omapfb_device*) ; 
 int /*<<< orphan*/  init_completion (int /*<<< orphan*/ *) ; 
 unsigned long jiffies ; 
 TYPE_3__ lcdc ; 
 scalar_t__ machine_is_ams_delta () ; 
 scalar_t__ machine_is_omap_h3 () ; 
 int max (int,int) ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  msecs_to_jiffies (int) ; 
 int /*<<< orphan*/  omap_free_lcd_dma () ; 
 int omap_readl (int /*<<< orphan*/ ) ; 
 int omap_request_lcd_dma (void (*) (int,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  omap_set_lcd_dma_b1 (unsigned long,int,int,int const) ; 
 int /*<<< orphan*/  omap_set_lcd_dma_b1_mirror (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  omap_set_lcd_dma_b1_rotation (int) ; 
 int /*<<< orphan*/  omap_set_lcd_dma_b1_vxres (int) ; 
 int /*<<< orphan*/  omap_set_lcd_dma_ext_controller (int) ; 
 int /*<<< orphan*/  omap_set_lcd_dma_single_transfer (int) ; 
 int /*<<< orphan*/  omap_setup_lcd_dma () ; 
 int /*<<< orphan*/  omap_stop_lcd_dma () ; 
 int /*<<< orphan*/  omap_writel (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_info (char*) ; 
 int request_irq (int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct omapfb_device*) ; 
 void stub1 (void*) ; 
 scalar_t__ time_after (unsigned long,scalar_t__) ; 
 int /*<<< orphan*/  wait_for_completion_timeout (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void enable_irqs(int mask)
{
	lcdc.irq_mask |= mask;
}

__attribute__((used)) static inline void disable_irqs(int mask)
{
	lcdc.irq_mask &= ~mask;
}

__attribute__((used)) static void set_load_mode(enum lcdc_load_mode mode)
{
	u32 l;

	l = omap_readl(OMAP_LCDC_CONTROL);
	l &= ~(3 << 20);
	switch (mode) {
	case OMAP_LCDC_LOAD_PALETTE:
		l |= 1 << 20;
		break;
	case OMAP_LCDC_LOAD_FRAME:
		l |= 2 << 20;
		break;
	case OMAP_LCDC_LOAD_PALETTE_AND_FRAME:
		break;
	default:
		BUG();
	}
	omap_writel(l, OMAP_LCDC_CONTROL);
}

__attribute__((used)) static void enable_controller(void)
{
	u32 l;

	l = omap_readl(OMAP_LCDC_CONTROL);
	l |= OMAP_LCDC_CTRL_LCD_EN;
	l &= ~OMAP_LCDC_IRQ_MASK;
	l |= lcdc.irq_mask | OMAP_LCDC_IRQ_DONE;	/* enabled IRQs */
	omap_writel(l, OMAP_LCDC_CONTROL);
}

__attribute__((used)) static void disable_controller_async(void)
{
	u32 l;
	u32 mask;

	l = omap_readl(OMAP_LCDC_CONTROL);
	mask = OMAP_LCDC_CTRL_LCD_EN | OMAP_LCDC_IRQ_MASK;
	/*
	 * Preserve the DONE mask, since we still want to get the
	 * final DONE irq. It will be disabled in the IRQ handler.
	 */
	mask &= ~OMAP_LCDC_IRQ_DONE;
	l &= ~mask;
	omap_writel(l, OMAP_LCDC_CONTROL);
}

__attribute__((used)) static void disable_controller(void)
{
	init_completion(&lcdc.last_frame_complete);
	disable_controller_async();
	if (!wait_for_completion_timeout(&lcdc.last_frame_complete,
				msecs_to_jiffies(500)))
		dev_err(lcdc.fbdev->dev, "timeout waiting for FRAME DONE\n");
}

__attribute__((used)) static void reset_controller(u32 status)
{
	static unsigned long reset_count;
	static unsigned long last_jiffies;

	disable_controller_async();
	reset_count++;
	if (reset_count == 1 || time_after(jiffies, last_jiffies + HZ)) {
		dev_err(lcdc.fbdev->dev,
			  "resetting (status %#010x,reset count %lu)\n",
			  status, reset_count);
		last_jiffies = jiffies;
	}
	if (reset_count < 100) {
		enable_controller();
	} else {
		reset_count = 0;
		dev_err(lcdc.fbdev->dev,
			"too many reset attempts, giving up.\n");
	}
}

__attribute__((used)) static void setup_lcd_dma(void)
{
	static const int dma_elem_type[] = {
		0,
		OMAP_DMA_DATA_TYPE_S8,
		OMAP_DMA_DATA_TYPE_S16,
		0,
		OMAP_DMA_DATA_TYPE_S32,
	};
	struct omapfb_plane_struct *plane = lcdc.fbdev->fb_info[0]->par;
	struct fb_var_screeninfo *var = &lcdc.fbdev->fb_info[0]->var;
	unsigned long	src;
	int		esize, xelem, yelem;

	src = lcdc.vram_phys + lcdc.frame_offset;

	switch (var->rotate) {
	case 0:
		if (plane->info.mirror || (src & 3) ||
		    lcdc.color_mode == OMAPFB_COLOR_YUV420 ||
		    (lcdc.xres & 1))
			esize = 2;
		else
			esize = 4;
		xelem = lcdc.xres * lcdc.bpp / 8 / esize;
		yelem = lcdc.yres;
		break;
	case 90:
	case 180:
	case 270:
		if (cpu_is_omap15xx()) {
			BUG();
		}
		esize = 2;
		xelem = lcdc.yres * lcdc.bpp / 16;
		yelem = lcdc.xres;
		break;
	default:
		BUG();
		return;
	}
#ifdef VERBOSE
	dev_dbg(lcdc.fbdev->dev,
		 "setup_dma: src %#010lx esize %d xelem %d yelem %d\n",
		 src, esize, xelem, yelem);
#endif
	omap_set_lcd_dma_b1(src, xelem, yelem, dma_elem_type[esize]);
	if (!cpu_is_omap15xx()) {
		int bpp = lcdc.bpp;

		/*
		 * YUV support is only for external mode when we have the
		 * YUV window embedded in a 16bpp frame buffer.
		 */
		if (lcdc.color_mode == OMAPFB_COLOR_YUV420)
			bpp = 16;
		/* Set virtual xres elem size */
		omap_set_lcd_dma_b1_vxres(
			lcdc.screen_width * bpp / 8 / esize);
		/* Setup transformations */
		omap_set_lcd_dma_b1_rotation(var->rotate);
		omap_set_lcd_dma_b1_mirror(plane->info.mirror);
	}
	omap_setup_lcd_dma();
}

__attribute__((used)) static irqreturn_t lcdc_irq_handler(int irq, void *dev_id)
{
	u32 status;

	status = omap_readl(OMAP_LCDC_STATUS);

	if (status & (OMAP_LCDC_STAT_FUF | OMAP_LCDC_STAT_SYNC_LOST))
		reset_controller(status);
	else {
		if (status & OMAP_LCDC_STAT_DONE) {
			u32 l;

			/*
			 * Disable IRQ_DONE. The status bit will be cleared
			 * only when the controller is reenabled and we don't
			 * want to get more interrupts.
			 */
			l = omap_readl(OMAP_LCDC_CONTROL);
			l &= ~OMAP_LCDC_IRQ_DONE;
			omap_writel(l, OMAP_LCDC_CONTROL);
			complete(&lcdc.last_frame_complete);
		}
		if (status & OMAP_LCDC_STAT_LOADED_PALETTE) {
			disable_controller_async();
			complete(&lcdc.palette_load_complete);
		}
	}

	/*
	 * Clear these interrupt status bits.
	 * Sync_lost, FUF bits were cleared by disabling the LCD controller
	 * LOADED_PALETTE can be cleared this way only in palette only
	 * load mode. In other load modes it's cleared by disabling the
	 * controller.
	 */
	status &= ~(OMAP_LCDC_STAT_VSYNC |
		    OMAP_LCDC_STAT_LOADED_PALETTE |
		    OMAP_LCDC_STAT_ABC |
		    OMAP_LCDC_STAT_LINE_INT);
	omap_writel(status, OMAP_LCDC_STATUS);
	return IRQ_HANDLED;
}

__attribute__((used)) static int omap_lcdc_setup_plane(int plane, int channel_out,
				 unsigned long offset, int screen_width,
				 int pos_x, int pos_y, int width, int height,
				 int color_mode)
{
	struct fb_var_screeninfo *var = &lcdc.fbdev->fb_info[0]->var;
	struct lcd_panel *panel = lcdc.fbdev->panel;
	int rot_x, rot_y;

	if (var->rotate == 0) {
		rot_x = panel->x_res;
		rot_y = panel->y_res;
	} else {
		rot_x = panel->y_res;
		rot_y = panel->x_res;
	}
	if (plane != 0 || channel_out != 0 || pos_x != 0 || pos_y != 0 ||
	    width > rot_x || height > rot_y) {
#ifdef VERBOSE
		dev_dbg(lcdc.fbdev->dev,
			"invalid plane params plane %d pos_x %d pos_y %d "
			"w %d h %d\n", plane, pos_x, pos_y, width, height);
#endif
		return -EINVAL;
	}

	lcdc.frame_offset = offset;
	lcdc.xres = width;
	lcdc.yres = height;
	lcdc.screen_width = screen_width;
	lcdc.color_mode = color_mode;

	switch (color_mode) {
	case OMAPFB_COLOR_CLUT_8BPP:
		lcdc.bpp = 8;
		lcdc.palette_code = 0x3000;
		lcdc.palette_size = 512;
		break;
	case OMAPFB_COLOR_RGB565:
		lcdc.bpp = 16;
		lcdc.palette_code = 0x4000;
		lcdc.palette_size = 32;
		break;
	case OMAPFB_COLOR_RGB444:
		lcdc.bpp = 16;
		lcdc.palette_code = 0x4000;
		lcdc.palette_size = 32;
		break;
	case OMAPFB_COLOR_YUV420:
		if (lcdc.ext_mode) {
			lcdc.bpp = 12;
			break;
		}
		/* fallthrough */
	case OMAPFB_COLOR_YUV422:
		if (lcdc.ext_mode) {
			lcdc.bpp = 16;
			break;
		}
		/* fallthrough */
	default:
		/* FIXME: other BPPs.
		 * bpp1: code  0,     size 256
		 * bpp2: code  0x1000 size 256
		 * bpp4: code  0x2000 size 256
		 * bpp12: code 0x4000 size 32
		 */
		dev_dbg(lcdc.fbdev->dev, "invalid color mode %d\n", color_mode);
		BUG();
		return -1;
	}

	if (lcdc.ext_mode) {
		setup_lcd_dma();
		return 0;
	}

	if (lcdc.update_mode == OMAPFB_AUTO_UPDATE) {
		disable_controller();
		omap_stop_lcd_dma();
		setup_lcd_dma();
		enable_controller();
	}

	return 0;
}

__attribute__((used)) static int omap_lcdc_enable_plane(int plane, int enable)
{
	dev_dbg(lcdc.fbdev->dev,
		"plane %d enable %d update_mode %d ext_mode %d\n",
		plane, enable, lcdc.update_mode, lcdc.ext_mode);
	if (plane != OMAPFB_PLANE_GFX)
		return -EINVAL;

	return 0;
}

__attribute__((used)) static void load_palette(void)
{
	u16	*palette;

	palette = (u16 *)lcdc.palette_virt;

	*(u16 *)palette &= 0x0fff;
	*(u16 *)palette |= lcdc.palette_code;

	omap_set_lcd_dma_b1(lcdc.palette_phys,
		lcdc.palette_size / 4 + 1, 1, OMAP_DMA_DATA_TYPE_S32);

	omap_set_lcd_dma_single_transfer(1);
	omap_setup_lcd_dma();

	init_completion(&lcdc.palette_load_complete);
	enable_irqs(OMAP_LCDC_IRQ_LOADED_PALETTE);
	set_load_mode(OMAP_LCDC_LOAD_PALETTE);
	enable_controller();
	if (!wait_for_completion_timeout(&lcdc.palette_load_complete,
				msecs_to_jiffies(500)))
		dev_err(lcdc.fbdev->dev, "timeout waiting for FRAME DONE\n");
	/* The controller gets disabled in the irq handler */
	disable_irqs(OMAP_LCDC_IRQ_LOADED_PALETTE);
	omap_stop_lcd_dma();

	omap_set_lcd_dma_single_transfer(lcdc.ext_mode);
}

__attribute__((used)) static int omap_lcdc_setcolreg(u_int regno, u16 red, u16 green, u16 blue,
			       u16 transp, int update_hw_pal)
{
	u16 *palette;

	if (lcdc.color_mode != OMAPFB_COLOR_CLUT_8BPP || regno > 255)
		return -EINVAL;

	palette = (u16 *)lcdc.palette_virt;

	palette[regno] &= ~0x0fff;
	palette[regno] |= ((red >> 12) << 8) | ((green >> 12) << 4 ) |
			   (blue >> 12);

	if (update_hw_pal) {
		disable_controller();
		omap_stop_lcd_dma();
		load_palette();
		setup_lcd_dma();
		set_load_mode(OMAP_LCDC_LOAD_FRAME);
		enable_controller();
	}

	return 0;
}

__attribute__((used)) static void calc_ck_div(int is_tft, int pck, int *pck_div)
{
	unsigned long lck;

	pck = max(1, pck);
	lck = clk_get_rate(lcdc.lcd_ck);
	*pck_div = (lck + pck - 1) / pck;
	if (is_tft)
		*pck_div = max(2, *pck_div);
	else
		*pck_div = max(3, *pck_div);
	if (*pck_div > 255) {
		/* FIXME: try to adjust logic clock divider as well */
		*pck_div = 255;
		dev_warn(lcdc.fbdev->dev, "pixclock %d kHz too low.\n",
			 pck / 1000);
	}
}

__attribute__((used)) static inline void setup_regs(void)
{
	u32 l;
	struct lcd_panel *panel = lcdc.fbdev->panel;
	int is_tft = panel->config & OMAP_LCDC_PANEL_TFT;
	unsigned long lck;
	int pcd;

	l = omap_readl(OMAP_LCDC_CONTROL);
	l &= ~OMAP_LCDC_CTRL_LCD_TFT;
	l |= is_tft ? OMAP_LCDC_CTRL_LCD_TFT : 0;
#ifdef CONFIG_MACH_OMAP_PALMTE
/* FIXME:if (machine_is_omap_palmte()) { */
		/* PalmTE uses alternate TFT setting in 8BPP mode */
		l |= (is_tft && panel->bpp == 8) ? 0x810000 : 0;
/*	} */
#endif
	omap_writel(l, OMAP_LCDC_CONTROL);

	l = omap_readl(OMAP_LCDC_TIMING2);
	l &= ~(((1 << 6) - 1) << 20);
	l |= (panel->config & OMAP_LCDC_SIGNAL_MASK) << 20;
	omap_writel(l, OMAP_LCDC_TIMING2);

	l = panel->x_res - 1;
	l |= (panel->hsw - 1) << 10;
	l |= (panel->hfp - 1) << 16;
	l |= (panel->hbp - 1) << 24;
	omap_writel(l, OMAP_LCDC_TIMING0);

	l = panel->y_res - 1;
	l |= (panel->vsw - 1) << 10;
	l |= panel->vfp << 16;
	l |= panel->vbp << 24;
	omap_writel(l, OMAP_LCDC_TIMING1);

	l = omap_readl(OMAP_LCDC_TIMING2);
	l &= ~0xff;

	lck = clk_get_rate(lcdc.lcd_ck);

	if (!panel->pcd)
		calc_ck_div(is_tft, panel->pixel_clock * 1000, &pcd);
	else {
		dev_warn(lcdc.fbdev->dev,
		    "Pixel clock divider value is obsolete.\n"
		    "Try to set pixel_clock to %lu and pcd to 0 "
		    "in drivers/video/omap/lcd_%s.c and submit a patch.\n",
			lck / panel->pcd / 1000, panel->name);

		pcd = panel->pcd;
	}
	l |= pcd & 0xff;
	l |= panel->acb << 8;
	omap_writel(l, OMAP_LCDC_TIMING2);

	/* update panel info with the exact clock */
	panel->pixel_clock = lck / pcd / 1000;
}

__attribute__((used)) static int omap_lcdc_set_update_mode(enum omapfb_update_mode mode)
{
	int r = 0;

	if (mode != lcdc.update_mode) {
		switch (mode) {
		case OMAPFB_AUTO_UPDATE:
			setup_regs();
			load_palette();

			/* Setup and start LCD DMA */
			setup_lcd_dma();

			set_load_mode(OMAP_LCDC_LOAD_FRAME);
			enable_irqs(OMAP_LCDC_IRQ_DONE);
			/* This will start the actual DMA transfer */
			enable_controller();
			lcdc.update_mode = mode;
			break;
		case OMAPFB_UPDATE_DISABLED:
			disable_controller();
			omap_stop_lcd_dma();
			lcdc.update_mode = mode;
			break;
		default:
			r = -EINVAL;
		}
	}

	return r;
}

__attribute__((used)) static enum omapfb_update_mode omap_lcdc_get_update_mode(void)
{
	return lcdc.update_mode;
}

__attribute__((used)) static void omap_lcdc_suspend(void)
{
	omap_lcdc_set_update_mode(OMAPFB_UPDATE_DISABLED);
}

__attribute__((used)) static void omap_lcdc_resume(void)
{
	omap_lcdc_set_update_mode(OMAPFB_AUTO_UPDATE);
}

__attribute__((used)) static void omap_lcdc_get_caps(int plane, struct omapfb_caps *caps)
{
	return;
}

int omap_lcdc_set_dma_callback(void (*callback)(void *data), void *data)
{
	BUG_ON(callback == NULL);

	if (lcdc.dma_callback)
		return -EBUSY;
	else {
		lcdc.dma_callback = callback;
		lcdc.dma_callback_data = data;
	}
	return 0;
}

void omap_lcdc_free_dma_callback(void)
{
	lcdc.dma_callback = NULL;
}

__attribute__((used)) static void lcdc_dma_handler(u16 status, void *data)
{
	if (lcdc.dma_callback)
		lcdc.dma_callback(lcdc.dma_callback_data);
}

__attribute__((used)) static int alloc_palette_ram(void)
{
	lcdc.palette_virt = dma_alloc_wc(lcdc.fbdev->dev, MAX_PALETTE_SIZE,
					 &lcdc.palette_phys, GFP_KERNEL);
	if (lcdc.palette_virt == NULL) {
		dev_err(lcdc.fbdev->dev, "failed to alloc palette memory\n");
		return -ENOMEM;
	}
	memset(lcdc.palette_virt, 0, MAX_PALETTE_SIZE);

	return 0;
}

__attribute__((used)) static void free_palette_ram(void)
{
	dma_free_wc(lcdc.fbdev->dev, MAX_PALETTE_SIZE, lcdc.palette_virt,
		    lcdc.palette_phys);
}

__attribute__((used)) static int alloc_fbmem(struct omapfb_mem_region *region)
{
	int bpp;
	int frame_size;
	struct lcd_panel *panel = lcdc.fbdev->panel;

	bpp = panel->bpp;
	if (bpp == 12)
		bpp = 16;
	frame_size = PAGE_ALIGN(panel->x_res * bpp / 8 * panel->y_res);
	if (region->size > frame_size)
		frame_size = region->size;
	lcdc.vram_size = frame_size;
	lcdc.vram_virt = dma_alloc_wc(lcdc.fbdev->dev, lcdc.vram_size,
				      &lcdc.vram_phys, GFP_KERNEL);
	if (lcdc.vram_virt == NULL) {
		dev_err(lcdc.fbdev->dev, "unable to allocate FB DMA memory\n");
		return -ENOMEM;
	}
	region->size = frame_size;
	region->paddr = lcdc.vram_phys;
	region->vaddr = lcdc.vram_virt;
	region->alloc = 1;

	memset(lcdc.vram_virt, 0, lcdc.vram_size);

	return 0;
}

__attribute__((used)) static void free_fbmem(void)
{
	dma_free_wc(lcdc.fbdev->dev, lcdc.vram_size, lcdc.vram_virt,
		    lcdc.vram_phys);
}

__attribute__((used)) static int setup_fbmem(struct omapfb_mem_desc *req_md)
{
	if (!req_md->region_cnt) {
		dev_err(lcdc.fbdev->dev, "no memory regions defined\n");
		return -EINVAL;
	}

	if (req_md->region_cnt > 1) {
		dev_err(lcdc.fbdev->dev, "only one plane is supported\n");
		req_md->region_cnt = 1;
	}

	return alloc_fbmem(&req_md->region[0]);
}

__attribute__((used)) static int omap_lcdc_init(struct omapfb_device *fbdev, int ext_mode,
			  struct omapfb_mem_desc *req_vram)
{
	int r;
	u32 l;
	int rate;
	struct clk *tc_ck;

	lcdc.irq_mask = 0;

	lcdc.fbdev = fbdev;
	lcdc.ext_mode = ext_mode;

	l = 0;
	omap_writel(l, OMAP_LCDC_CONTROL);

	/* FIXME:
	 * According to errata some platforms have a clock rate limitiation
	 */
	lcdc.lcd_ck = clk_get(fbdev->dev, "lcd_ck");
	if (IS_ERR(lcdc.lcd_ck)) {
		dev_err(fbdev->dev, "unable to access LCD clock\n");
		r = PTR_ERR(lcdc.lcd_ck);
		goto fail0;
	}

	tc_ck = clk_get(fbdev->dev, "tc_ck");
	if (IS_ERR(tc_ck)) {
		dev_err(fbdev->dev, "unable to access TC clock\n");
		r = PTR_ERR(tc_ck);
		goto fail1;
	}

	rate = clk_get_rate(tc_ck);
	clk_put(tc_ck);

	if (machine_is_ams_delta())
		rate /= 4;
	if (machine_is_omap_h3())
		rate /= 3;
	r = clk_set_rate(lcdc.lcd_ck, rate);
	if (r) {
		dev_err(fbdev->dev, "failed to adjust LCD rate\n");
		goto fail1;
	}
	clk_enable(lcdc.lcd_ck);

	r = request_irq(OMAP_LCDC_IRQ, lcdc_irq_handler, 0, MODULE_NAME, fbdev);
	if (r) {
		dev_err(fbdev->dev, "unable to get IRQ\n");
		goto fail2;
	}

	r = omap_request_lcd_dma(lcdc_dma_handler, NULL);
	if (r) {
		dev_err(fbdev->dev, "unable to get LCD DMA\n");
		goto fail3;
	}

	omap_set_lcd_dma_single_transfer(ext_mode);
	omap_set_lcd_dma_ext_controller(ext_mode);

	if (!ext_mode)
		if ((r = alloc_palette_ram()) < 0)
			goto fail4;

	if ((r = setup_fbmem(req_vram)) < 0)
		goto fail5;

	pr_info("omapfb: LCDC initialized\n");

	return 0;
fail5:
	if (!ext_mode)
		free_palette_ram();
fail4:
	omap_free_lcd_dma();
fail3:
	free_irq(OMAP_LCDC_IRQ, lcdc.fbdev);
fail2:
	clk_disable(lcdc.lcd_ck);
fail1:
	clk_put(lcdc.lcd_ck);
fail0:
	return r;
}

__attribute__((used)) static void omap_lcdc_cleanup(void)
{
	if (!lcdc.ext_mode)
		free_palette_ram();
	free_fbmem();
	omap_free_lcd_dma();
	free_irq(OMAP_LCDC_IRQ, lcdc.fbdev);
	clk_disable(lcdc.lcd_ck);
	clk_put(lcdc.lcd_ck);
}

