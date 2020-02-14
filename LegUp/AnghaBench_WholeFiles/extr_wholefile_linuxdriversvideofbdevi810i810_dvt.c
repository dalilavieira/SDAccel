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
typedef  scalar_t__ u8 ;
typedef  int u32 ;
struct mode_registers {scalar_t__ cr01; int pixclock; int cr00; int cr35; int cr04; int cr05; int msr; int cr06; int cr30; int cr10; int cr32; int cr11; int bpp8_100; int bpp16_100; int bpp24_100; int bpp8_133; int bpp16_133; int bpp24_133; } ;
struct i810fb_par {int ovract; int mem_freq; struct mode_registers regs; } ;
struct fb_var_screeninfo {int right_margin; int hsync_len; int left_margin; int xres; int yres; int pixclock; int lower_margin; int vsync_len; int upper_margin; int bits_per_pixel; int /*<<< orphan*/  sync; } ;

/* Variables and functions */
 int ARRAY_SIZE (struct mode_registers*) ; 
 int /*<<< orphan*/  FB_SYNC_HOR_HIGH_ACT ; 
 int /*<<< orphan*/  FB_SYNC_ON_GREEN ; 
 int /*<<< orphan*/  FB_SYNC_VERT_HIGH_ACT ; 
 struct mode_registers* std_modes ; 

void round_off_xres(u32 *xres) 
{
	if (*xres <= 640)
		*xres = 640;
	else if (*xres <= 800)
		*xres = 800;
	else if (*xres <= 1024)
		*xres = 1024;
	else if (*xres <= 1152)
		*xres = 1152;
	else if (*xres <= 1280)
		*xres = 1280;
	else
		*xres = 1600;
}

inline void round_off_yres(u32 *xres, u32 *yres)
{
	*yres = (*xres * 3) >> 2;
}

__attribute__((used)) static int i810fb_find_best_mode(u32 xres, u32 yres, u32 pixclock)
{ 
	u32 diff = 0, diff_best = 0xFFFFFFFF, i = 0, i_best = 0; 
	u8 hfl = (u8) ((xres >> 3) - 1);

	for (i = 0; i < ARRAY_SIZE(std_modes); i++) { 
		if (std_modes[i].cr01 == hfl) { 
			if (std_modes[i].pixclock <= pixclock)
				diff = pixclock - std_modes[i].pixclock;
			if (diff < diff_best) {	 
		    		i_best = i;
		    		diff_best = diff;
			}
		}
	}
	return i_best;
}

void i810fb_encode_registers(const struct fb_var_screeninfo *var,
			     struct i810fb_par *par, u32 xres, u32 yres)
{
	u32 i_best = i810fb_find_best_mode(xres, yres, par->regs.pixclock);

	par->regs = std_modes[i_best];

	/* overlay */
	par->ovract = ((xres + var->right_margin + var->hsync_len + 
			var->left_margin - 32) | ((xres - 32) << 16));
}

void i810fb_fill_var_timings(struct fb_var_screeninfo *var)
{
	u32 total, xres, yres;
	u32 mode, pixclock;

	xres = var->xres;
	yres = var->yres;
	
	pixclock = 1000000000 / var->pixclock;
	mode = i810fb_find_best_mode(xres, yres, pixclock);
	
	total = (std_modes[mode].cr00 | (std_modes[mode].cr35 & 1) << 8) + 3;
	total <<= 3;
	
	var->pixclock = 1000000000 / std_modes[mode].pixclock;
	var->right_margin = (std_modes[mode].cr04 << 3) - xres;
	var->hsync_len = ((std_modes[mode].cr05 & 0x1F) -
			 (std_modes[mode].cr04 & 0x1F)) << 3;
	var->left_margin = (total - (xres + var->right_margin + 
				     var->hsync_len));
	var->sync = FB_SYNC_ON_GREEN;
	if (~(std_modes[mode].msr & (1 << 6)))
		var->sync |= FB_SYNC_HOR_HIGH_ACT;
	if (~(std_modes[mode].msr & (1 << 7)))
		var->sync |= FB_SYNC_VERT_HIGH_ACT;

	total = (std_modes[mode].cr06 | (std_modes[mode].cr30 & 0xF)  << 8) + 2;
	var->lower_margin = (std_modes[mode].cr10 |
			    (std_modes[mode].cr32 & 0x0F) << 8) - yres;
	var->vsync_len = (std_modes[mode].cr11 & 0x0F) -
			 (var->lower_margin & 0x0F);
	var->upper_margin = total - (yres + var->lower_margin + var->vsync_len);
}

u32 i810_get_watermark(struct fb_var_screeninfo *var,
		       struct i810fb_par *par)
{
	struct mode_registers *params = &par->regs;
	u32 wmark = 0;
	
	if (par->mem_freq == 100) {
		switch (var->bits_per_pixel) {
		case 8:
			wmark = params->bpp8_100;
			break;
		case 16:
			wmark = params->bpp16_100;
			break;
		case 24:
		case 32:
			wmark = params->bpp24_100;
		}
	} else {					
		switch (var->bits_per_pixel) {
		case 8:
			wmark = params->bpp8_133;
			break;
		case 16:
			wmark = params->bpp16_133;
			break;
		case 24:
		case 32:
			wmark = params->bpp24_133;
		}
	}
	return wmark;
}

