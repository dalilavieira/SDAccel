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
typedef  int ushort ;
typedef  int uint ;
typedef  int /*<<< orphan*/  u_char ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct TYPE_6__ {int line_length; scalar_t__ smem_start; } ;
struct TYPE_4__ {int length; scalar_t__ offset; } ;
struct TYPE_5__ {TYPE_1__ red; TYPE_1__ blue; TYPE_1__ green; } ;
struct fb_info {int /*<<< orphan*/  cmap; TYPE_3__ fix; int /*<<< orphan*/ * screen_base; TYPE_2__ var; int /*<<< orphan*/ * fbops; } ;
struct fb_copyarea {int dy; int sy; int sx; int dx; int width; short height; } ;

/* Variables and functions */
 int AD_BLT ; 
 int /*<<< orphan*/  AP_CONTROL_0 ; 
 int /*<<< orphan*/  AP_CONTROL_1 ; 
 int /*<<< orphan*/  AP_CONTROL_2 ; 
 int /*<<< orphan*/  AP_CONTROL_3A ; 
 int /*<<< orphan*/  AP_ROP_1 ; 
 int /*<<< orphan*/  AP_WRITE_ENABLE ; 
 int DST_EQ_SRC ; 
 int ENOMEM ; 
 int NORMAL_MODE ; 
 int NORM_CREG1 ; 
 int RESET_CREG ; 
 int SWAP (int) ; 
 int S_DATA_PLN ; 
 int /*<<< orphan*/  dn_fb_ops ; 
 TYPE_3__ dnfb_fix ; 
 TYPE_2__ dnfb_var ; 
 int fb_alloc_cmap (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fb_dealloc_cmap (int /*<<< orphan*/ *) ; 
 struct fb_info* framebuffer_alloc (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  framebuffer_release (struct fb_info*) ; 
 int /*<<< orphan*/  out_8 (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  out_be16 (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct fb_info*) ; 
 int /*<<< orphan*/  printk (char*) ; 
 int register_framebuffer (struct fb_info*) ; 

__attribute__((used)) static int dnfb_blank(int blank, struct fb_info *info)
{
	if (blank)
		out_8(AP_CONTROL_3A, 0x0);
	else
		out_8(AP_CONTROL_3A, 0x1);
	return 0;
}

__attribute__((used)) static
void dnfb_copyarea(struct fb_info *info, const struct fb_copyarea *area)
{

	int incr, y_delta, pre_read = 0, x_end, x_word_count;
	uint start_mask, end_mask, dest;
	ushort *src, dummy;
	short i, j;

	incr = (area->dy <= area->sy) ? 1 : -1;

	src = (ushort *)(info->screen_base + area->sy * info->fix.line_length +
			(area->sx >> 4));
	dest = area->dy * (info->fix.line_length >> 1) + (area->dx >> 4);

	if (incr > 0) {
		y_delta = (info->fix.line_length * 8) - area->sx - area->width;
		x_end = area->dx + area->width - 1;
		x_word_count = (x_end >> 4) - (area->dx >> 4) + 1;
		start_mask = 0xffff0000 >> (area->dx & 0xf);
		end_mask = 0x7ffff >> (x_end & 0xf);
		out_8(AP_CONTROL_0,
		     (((area->dx & 0xf) - (area->sx & 0xf)) % 16) | (0x4 << 5));
		if ((area->dx & 0xf) < (area->sx & 0xf))
			pre_read = 1;
	} else {
		y_delta = -((info->fix.line_length * 8) - area->sx - area->width);
		x_end = area->dx - area->width + 1;
		x_word_count = (area->dx >> 4) - (x_end >> 4) + 1;
		start_mask = 0x7ffff >> (area->dx & 0xf);
		end_mask = 0xffff0000 >> (x_end & 0xf);
		out_8(AP_CONTROL_0,
		     ((-((area->sx & 0xf) - (area->dx & 0xf))) % 16) |
		     (0x4 << 5));
		if ((area->dx & 0xf) > (area->sx & 0xf))
			pre_read = 1;
	}

	for (i = 0; i < area->height; i++) {

		out_8(AP_CONTROL_3A, 0xc | (dest >> 16));

		if (pre_read) {
			dummy = *src;
			src += incr;
		}

		if (x_word_count) {
			out_8(AP_WRITE_ENABLE, start_mask);
			*src = dest;
			src += incr;
			dest += incr;
			out_8(AP_WRITE_ENABLE, 0);

			for (j = 1; j < (x_word_count - 1); j++) {
				*src = dest;
				src += incr;
				dest += incr;
			}

			out_8(AP_WRITE_ENABLE, start_mask);
			*src = dest;
			dest += incr;
			src += incr;
		} else {
			out_8(AP_WRITE_ENABLE, start_mask | end_mask);
			*src = dest;
			dest += incr;
			src += incr;
		}
		src += (y_delta / 16);
		dest += (y_delta / 16);
	}
	out_8(AP_CONTROL_0, NORMAL_MODE);
}

__attribute__((used)) static int dnfb_probe(struct platform_device *dev)
{
	struct fb_info *info;
	int err = 0;

	info = framebuffer_alloc(0, &dev->dev);
	if (!info)
		return -ENOMEM;

	info->fbops = &dn_fb_ops;
	info->fix = dnfb_fix;
	info->var = dnfb_var;
	info->var.red.length = 1;
	info->var.red.offset = 0;
	info->var.green = info->var.blue = info->var.red;
	info->screen_base = (u_char *) info->fix.smem_start;

	err = fb_alloc_cmap(&info->cmap, 2, 0);
	if (err < 0)
		goto release_framebuffer;

	err = register_framebuffer(info);
	if (err < 0) {
		fb_dealloc_cmap(&info->cmap);
		goto release_framebuffer;
	}
	platform_set_drvdata(dev, info);

	/* now we have registered we can safely setup the hardware */
	out_8(AP_CONTROL_3A, RESET_CREG);
	out_be16(AP_WRITE_ENABLE, 0x0);
	out_8(AP_CONTROL_0, NORMAL_MODE);
	out_8(AP_CONTROL_1, (AD_BLT | DST_EQ_SRC | NORM_CREG1));
	out_8(AP_CONTROL_2, S_DATA_PLN);
	out_be16(AP_ROP_1, SWAP(0x3));

	printk("apollo frame buffer alive and kicking !\n");
	return err;

release_framebuffer:
	framebuffer_release(info);
	return err;
}

