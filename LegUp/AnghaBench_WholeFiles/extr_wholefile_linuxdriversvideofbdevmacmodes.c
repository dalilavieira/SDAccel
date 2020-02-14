#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct monitor_map {int sense; int vmode; } ;
struct mode_map {int vmode; struct fb_videomode* mode; } ;
struct fb_videomode {scalar_t__ xres; scalar_t__ yres; scalar_t__ pixclock; int vmode; int /*<<< orphan*/  sync; int /*<<< orphan*/  vsync_len; int /*<<< orphan*/  hsync_len; int /*<<< orphan*/  lower_margin; int /*<<< orphan*/  upper_margin; int /*<<< orphan*/  right_margin; int /*<<< orphan*/  left_margin; } ;
struct TYPE_8__ {int offset; int length; } ;
struct TYPE_7__ {int length; int /*<<< orphan*/  offset; } ;
struct TYPE_6__ {int offset; int length; } ;
struct TYPE_5__ {int offset; int length; } ;
struct fb_var_screeninfo {int bits_per_pixel; scalar_t__ xres; scalar_t__ yres; scalar_t__ xres_virtual; scalar_t__ yres_virtual; int height; int width; scalar_t__ pixclock; int vmode; int /*<<< orphan*/  sync; int /*<<< orphan*/  vsync_len; int /*<<< orphan*/  hsync_len; int /*<<< orphan*/  lower_margin; int /*<<< orphan*/  upper_margin; int /*<<< orphan*/  right_margin; int /*<<< orphan*/  left_margin; TYPE_4__ transp; TYPE_3__ blue; TYPE_2__ green; TYPE_1__ red; } ;
struct fb_info {int dummy; } ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (struct fb_videomode*) ; 
#define  CMODE_16 130 
#define  CMODE_32 129 
#define  CMODE_8 128 
 size_t DEFAULT_MODEDB_INDEX ; 
 int EINVAL ; 
 int FB_VMODE_MASK ; 
 int fb_find_mode (struct fb_var_screeninfo*,struct fb_info*,char const*,struct fb_videomode const*,unsigned int,struct fb_videomode*,unsigned int) ; 
 struct fb_videomode* mac_modedb ; 
 struct mode_map* mac_modes ; 
 struct monitor_map* mac_monitors ; 
 int /*<<< orphan*/  memset (struct fb_var_screeninfo*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  strncmp (char const*,char*,int) ; 

int mac_vmode_to_var(int vmode, int cmode, struct fb_var_screeninfo *var)
{
    const struct fb_videomode *mode = NULL;
    const struct mode_map *map;

    for (map = mac_modes; map->vmode != -1; map++)
	if (map->vmode == vmode) {
	    mode = map->mode;
	    break;
	}
    if (!mode)
	return -EINVAL;

    memset(var, 0, sizeof(struct fb_var_screeninfo));
    switch (cmode) {
	case CMODE_8:
	    var->bits_per_pixel = 8;
	    var->red.offset = 0;
	    var->red.length = 8;   
	    var->green.offset = 0;
	    var->green.length = 8;
	    var->blue.offset = 0;
	    var->blue.length = 8;
	    break;

	case CMODE_16:
	    var->bits_per_pixel = 16;
	    var->red.offset = 10;
	    var->red.length = 5;
	    var->green.offset = 5;
	    var->green.length = 5;
	    var->blue.offset = 0;
	    var->blue.length = 5;
	    break;

	case CMODE_32:
	    var->bits_per_pixel = 32;
	    var->red.offset = 16;
	    var->red.length = 8;
	    var->green.offset = 8;
	    var->green.length = 8;
	    var->blue.offset = 0;
	    var->blue.length = 8;
	    var->transp.offset = 24;
	    var->transp.length = 8;
	    break;

	default:
	    return -EINVAL;
    }
    var->xres = mode->xres;
    var->yres = mode->yres;
    var->xres_virtual = mode->xres;
    var->yres_virtual = mode->yres;
    var->height = -1;
    var->width = -1;
    var->pixclock = mode->pixclock;
    var->left_margin = mode->left_margin;
    var->right_margin = mode->right_margin;
    var->upper_margin = mode->upper_margin;
    var->lower_margin = mode->lower_margin;
    var->hsync_len = mode->hsync_len;
    var->vsync_len = mode->vsync_len;
    var->sync = mode->sync;
    var->vmode = mode->vmode;
    return 0;
}

int mac_var_to_vmode(const struct fb_var_screeninfo *var, int *vmode,
		     int *cmode)
{
    const struct mode_map *map;

    if (var->bits_per_pixel <= 8)
	*cmode = CMODE_8;
    else if (var->bits_per_pixel <= 16)
	*cmode = CMODE_16;
    else if (var->bits_per_pixel <= 32)
	*cmode = CMODE_32;
    else
	return -EINVAL;

    /*
     * Find the mac_mode with a matching resolution or failing that, the
     * closest larger resolution. Skip modes with a shorter pixel clock period.
     */
    for (map = mac_modes; map->vmode != -1; map++) {
	const struct fb_videomode *mode = map->mode;

	if (var->xres > mode->xres || var->yres > mode->yres)
	    continue;
	if (var->xres_virtual > mode->xres || var->yres_virtual > mode->yres)
	    continue;
	if (var->pixclock > mode->pixclock)
	    continue;
	if ((var->vmode & FB_VMODE_MASK) != mode->vmode)
	    continue;
	*vmode = map->vmode;

	/*
	 * Having found a good resolution, find the matching pixel clock
	 * or failing that, the closest longer pixel clock period.
	 */
	map++;
	while (map->vmode != -1) {
	    const struct fb_videomode *clk_mode = map->mode;

	    if (mode->xres != clk_mode->xres || mode->yres != clk_mode->yres)
		break;
	    if (var->pixclock > mode->pixclock)
	        break;
	    if (mode->vmode != clk_mode->vmode)
		continue;
	    *vmode = map->vmode;
	    map++;
	}
	return 0;
    }
    return -EINVAL;
}

int mac_map_monitor_sense(int sense)
{
    const struct monitor_map *map;

    for (map = mac_monitors; map->sense != -1; map++)
	if (map->sense == sense)
	    break;
    return map->vmode;
}

int mac_find_mode(struct fb_var_screeninfo *var, struct fb_info *info,
		  const char *mode_option, unsigned int default_bpp)
{
    const struct fb_videomode *db = NULL;
    unsigned int dbsize = 0;

    if (mode_option && !strncmp(mode_option, "mac", 3)) {
	mode_option += 3;
	db = mac_modedb;
	dbsize = ARRAY_SIZE(mac_modedb);
    }
    return fb_find_mode(var, info, mode_option, db, dbsize,
			&mac_modedb[DEFAULT_MODEDB_INDEX], default_bpp);
}

