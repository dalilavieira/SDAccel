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
typedef  int u_int ;
struct fb_var_screeninfo {unsigned int yoffset; scalar_t__ xoffset; } ;
struct TYPE_2__ {int yoffset; scalar_t__ yres; scalar_t__ yres_virtual; unsigned int xres; } ;
struct fb_info {TYPE_1__ var; } ;
struct fb_cursor {int enable; } ;

/* Variables and functions */
 scalar_t__ CLR_PAL_REG ; 
#define  CM_DRAW 130 
#define  CM_ERASE 129 
#define  CM_MOVE 128 
 scalar_t__ CTLA_REG ; 
 scalar_t__ CURS_POS_REG ; 
 unsigned int CURS_TOGGLE ; 
 int EINVAL ; 
 unsigned int FORCE_BLANK ; 
 scalar_t__ TOP_REG ; 
 int fontheight (int /*<<< orphan*/ ) ; 
 int fontwidth (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  p ; 
 int x ; 
 int y ; 

int g364fb_cursor(struct fb_info *info, struct fb_cursor *cursor)
{
	
	switch (cursor->enable) {
	case CM_ERASE:
		*(unsigned int *) CTLA_REG |= CURS_TOGGLE;
		break;

	case CM_MOVE:
	case CM_DRAW:
		*(unsigned int *) CTLA_REG &= ~CURS_TOGGLE;
		*(unsigned int *) CURS_POS_REG =
		    ((x * fontwidth(p)) << 12) | ((y * fontheight(p)) -
						  info->var.yoffset);
		break;
	}
	return 0;
}

__attribute__((used)) static int g364fb_pan_display(struct fb_var_screeninfo *var, 
			      struct fb_info *info)
{
	if (var->xoffset ||
	    var->yoffset + info->var.yres > info->var.yres_virtual)
		return -EINVAL;

	*(unsigned int *) TOP_REG = var->yoffset * info->var.xres;
	return 0;
}

__attribute__((used)) static int g364fb_blank(int blank, struct fb_info *info)
{
	if (blank)
		*(unsigned int *) CTLA_REG |= FORCE_BLANK;
	else
		*(unsigned int *) CTLA_REG &= ~FORCE_BLANK;
	return 0;
}

__attribute__((used)) static int g364fb_setcolreg(u_int regno, u_int red, u_int green,
			    u_int blue, u_int transp, struct fb_info *info)
{
	volatile unsigned int *ptr = (volatile unsigned int *) CLR_PAL_REG;

	if (regno > 255)
		return 1;

	red >>= 8;
	green >>= 8;
	blue >>= 8;

	ptr[regno << 1] = (red << 16) | (green << 8) | blue;

	return 0;
}

