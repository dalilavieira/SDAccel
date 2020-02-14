#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_20__   TYPE_9__ ;
typedef  struct TYPE_19__   TYPE_8__ ;
typedef  struct TYPE_18__   TYPE_7__ ;
typedef  struct TYPE_17__   TYPE_6__ ;
typedef  struct TYPE_16__   TYPE_5__ ;
typedef  struct TYPE_15__   TYPE_4__ ;
typedef  struct TYPE_14__   TYPE_3__ ;
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;
typedef  struct TYPE_11__   TYPE_10__ ;

/* Type definitions */
typedef  int u32 ;
typedef  int u16 ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct TYPE_15__ {int /*<<< orphan*/  length; int /*<<< orphan*/  offset; } ;
struct TYPE_14__ {int length; int /*<<< orphan*/  offset; } ;
struct TYPE_13__ {int offset; int length; } ;
struct TYPE_12__ {int offset; int length; } ;
struct fb_var_screeninfo {int xoffset; int yoffset; int xres; int xres_virtual; int yres; int bits_per_pixel; int yres_virtual; TYPE_4__ transp; TYPE_3__ blue; TYPE_2__ green; TYPE_1__ red; } ;
struct TYPE_11__ {int line_length; int smem_len; int ypanstep; int mmio_len; int /*<<< orphan*/  id; void* smem_start; void* visual; void* mmio_start; } ;
struct TYPE_19__ {int /*<<< orphan*/  length; int /*<<< orphan*/  offset; } ;
struct TYPE_18__ {int length; int /*<<< orphan*/  offset; } ;
struct TYPE_17__ {int offset; int length; } ;
struct TYPE_16__ {int offset; int length; } ;
struct TYPE_20__ {int bits_per_pixel; int xres; int yres; unsigned short xres_virtual; unsigned short yres_virtual; TYPE_8__ transp; TYPE_7__ blue; TYPE_6__ green; TYPE_5__ red; } ;
struct fb_info {int flags; int /*<<< orphan*/  cmap; TYPE_10__ fix; void* screen_base; scalar_t__ par; scalar_t__ pseudo_palette; TYPE_9__ var; int /*<<< orphan*/ * fbops; } ;
struct fb_fillrect {scalar_t__ rop; size_t color; int dx; int dy; int width; int height; } ;
struct fb_copyarea {int sx; int sy; int dx; int dy; int width; int height; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int FBINFO_DEFAULT ; 
 int FBINFO_HWACCEL_COPYAREA ; 
 int FBINFO_HWACCEL_FILLRECT ; 
 int FBINFO_HWACCEL_YPAN ; 
 void* FB_VISUAL_PSEUDOCOLOR ; 
 void* FB_VISUAL_TRUECOLOR ; 
 int /*<<< orphan*/  HD64461_BBTDHR ; 
 int /*<<< orphan*/  HD64461_BBTDSARH ; 
 int /*<<< orphan*/  HD64461_BBTDSARL ; 
 int /*<<< orphan*/  HD64461_BBTDWR ; 
 int /*<<< orphan*/  HD64461_BBTMARH ; 
 int /*<<< orphan*/  HD64461_BBTMARL ; 
 int /*<<< orphan*/  HD64461_BBTMDR ; 
 int /*<<< orphan*/  HD64461_BBTROPR ; 
 int /*<<< orphan*/  HD64461_BBTSSARH ; 
 int /*<<< orphan*/  HD64461_BBTSSARL ; 
 int /*<<< orphan*/  HD64461_CPTWAR ; 
 int /*<<< orphan*/  HD64461_CPTWDR ; 
 int /*<<< orphan*/  HD64461_GRCFGR ; 
 int HD64461_GRCFGR_ACCSTATUS ; 
 int /*<<< orphan*/  HD64461_GRSCR ; 
 void* HD64461_IO_OFFSET (int) ; 
 int /*<<< orphan*/  HD64461_LCDCBAR ; 
 int /*<<< orphan*/  HD64461_LCDCCR ; 
 unsigned short HD64461_LCDCCR_MOFF ; 
 unsigned short HD64461_LCDCCR_STBACK ; 
 unsigned short HD64461_LCDCCR_STREQ ; 
 int /*<<< orphan*/  HD64461_LCDCLOR ; 
 int /*<<< orphan*/  HD64461_LDR1 ; 
 unsigned short HD64461_LDR1_DON ; 
 int /*<<< orphan*/  HD64461_LDR3 ; 
 int /*<<< orphan*/  HD64461_LDVNDR ; 
 int /*<<< orphan*/  HD64461_STBCR ; 
 unsigned short HD64461_STBCR_SLCDST ; 
 int HD64461_STBCR_SLCKE_IST ; 
 int HD64461_STBCR_SLCKE_OST ; 
 scalar_t__ ROP_COPY ; 
 int WIDTH ; 
 int /*<<< orphan*/  cfb_fillrect (struct fb_info*,struct fb_fillrect const*) ; 
 int fb_alloc_cmap (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fb_dealloc_cmap (int /*<<< orphan*/ *) ; 
 scalar_t__ fb_get_options (char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  fb_info (struct fb_info*,char*,int /*<<< orphan*/ ) ; 
 int fb_readw (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fb_writew (int,int /*<<< orphan*/ ) ; 
 struct fb_info* framebuffer_alloc (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  framebuffer_release (struct fb_info*) ; 
 TYPE_10__ hitfb_fix ; 
 int /*<<< orphan*/  hitfb_ops ; 
 TYPE_9__ hitfb_var ; 
 int /*<<< orphan*/  msleep (int) ; 
 struct fb_info* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct fb_info*) ; 
 int register_framebuffer (struct fb_info*) ; 
 scalar_t__ unlikely (int) ; 
 int /*<<< orphan*/  unregister_framebuffer (struct fb_info*) ; 

__attribute__((used)) static inline void hitfb_accel_wait(void)
{
	while (fb_readw(HD64461_GRCFGR) & HD64461_GRCFGR_ACCSTATUS) ;
}

__attribute__((used)) static inline void hitfb_accel_start(int truecolor)
{
	if (truecolor) {
		fb_writew(6, HD64461_GRCFGR);
	} else {
		fb_writew(7, HD64461_GRCFGR);
	}
}

__attribute__((used)) static inline void hitfb_accel_set_dest(int truecolor, u16 dx, u16 dy,
					u16 width, u16 height)
{
	u32 saddr = WIDTH * dy + dx;
	if (truecolor)
		saddr <<= 1;

	fb_writew(width-1, HD64461_BBTDWR);
	fb_writew(height-1, HD64461_BBTDHR);

	fb_writew(saddr & 0xffff, HD64461_BBTDSARL);
	fb_writew(saddr >> 16, HD64461_BBTDSARH);

}

__attribute__((used)) static inline void hitfb_accel_bitblt(int truecolor, u16 sx, u16 sy, u16 dx,
				      u16 dy, u16 width, u16 height, u16 rop,
				      u32 mask_addr)
{
	u32 saddr, daddr;
	u32 maddr = 0;

	height--;
	width--;
	fb_writew(rop, HD64461_BBTROPR);
	if ((sy < dy) || ((sy == dy) && (sx <= dx))) {
		saddr = WIDTH * (sy + height) + sx + width;
		daddr = WIDTH * (dy + height) + dx + width;
		if (mask_addr) {
			if (truecolor)
				maddr = ((width >> 3) + 1) * (height + 1) - 1;
			else
				maddr =
				    (((width >> 4) + 1) * (height + 1) - 1) * 2;

			fb_writew((1 << 5) | 1, HD64461_BBTMDR);
		} else
			fb_writew(1, HD64461_BBTMDR);
	} else {
		saddr = WIDTH * sy + sx;
		daddr = WIDTH * dy + dx;
		if (mask_addr) {
			fb_writew((1 << 5), HD64461_BBTMDR);
		} else {
			fb_writew(0, HD64461_BBTMDR);
		}
	}
	if (truecolor) {
		saddr <<= 1;
		daddr <<= 1;
	}
	fb_writew(width, HD64461_BBTDWR);
	fb_writew(height, HD64461_BBTDHR);
	fb_writew(saddr & 0xffff, HD64461_BBTSSARL);
	fb_writew(saddr >> 16, HD64461_BBTSSARH);
	fb_writew(daddr & 0xffff, HD64461_BBTDSARL);
	fb_writew(daddr >> 16, HD64461_BBTDSARH);
	if (mask_addr) {
		maddr += mask_addr;
		fb_writew(maddr & 0xffff, HD64461_BBTMARL);
		fb_writew(maddr >> 16, HD64461_BBTMARH);
	}
	hitfb_accel_start(truecolor);
}

__attribute__((used)) static void hitfb_fillrect(struct fb_info *p, const struct fb_fillrect *rect)
{
	if (rect->rop != ROP_COPY)
		cfb_fillrect(p, rect);
	else {
		hitfb_accel_wait();
		fb_writew(0x00f0, HD64461_BBTROPR);
		fb_writew(16, HD64461_BBTMDR);

		if (p->var.bits_per_pixel == 16) {
			fb_writew(((u32 *) (p->pseudo_palette))[rect->color],
				  HD64461_GRSCR);
			hitfb_accel_set_dest(1, rect->dx, rect->dy, rect->width,
					     rect->height);
			hitfb_accel_start(1);
		} else {
			fb_writew(rect->color, HD64461_GRSCR);
			hitfb_accel_set_dest(0, rect->dx, rect->dy, rect->width,
					     rect->height);
			hitfb_accel_start(0);
		}
	}
}

__attribute__((used)) static void hitfb_copyarea(struct fb_info *p, const struct fb_copyarea *area)
{
	hitfb_accel_wait();
	hitfb_accel_bitblt(p->var.bits_per_pixel == 16, area->sx, area->sy,
			   area->dx, area->dy, area->width, area->height,
			   0x00cc, 0);
}

__attribute__((used)) static int hitfb_pan_display(struct fb_var_screeninfo *var,
			     struct fb_info *info)
{
	int xoffset = var->xoffset;
	int yoffset = var->yoffset;

	if (xoffset != 0)
		return -EINVAL;

	fb_writew((yoffset*info->fix.line_length)>>10, HD64461_LCDCBAR);

	return 0;
}

int hitfb_blank(int blank_mode, struct fb_info *info)
{
	unsigned short v;

	if (blank_mode) {
		v = fb_readw(HD64461_LDR1);
		v &= ~HD64461_LDR1_DON;
		fb_writew(v, HD64461_LDR1);

		v = fb_readw(HD64461_LCDCCR);
		v |= HD64461_LCDCCR_MOFF;
		fb_writew(v, HD64461_LCDCCR);

		v = fb_readw(HD64461_STBCR);
		v |= HD64461_STBCR_SLCDST;
		fb_writew(v, HD64461_STBCR);
	} else {
		v = fb_readw(HD64461_STBCR);
		v &= ~HD64461_STBCR_SLCDST;
		fb_writew(v, HD64461_STBCR);

		v = fb_readw(HD64461_LCDCCR);
		v &= ~(HD64461_LCDCCR_MOFF | HD64461_LCDCCR_STREQ);
		fb_writew(v, HD64461_LCDCCR);

		do {
		    v = fb_readw(HD64461_LCDCCR);
		} while(v&HD64461_LCDCCR_STBACK);

		v = fb_readw(HD64461_LDR1);
		v |= HD64461_LDR1_DON;
		fb_writew(v, HD64461_LDR1);
	}
	return 0;
}

__attribute__((used)) static int hitfb_setcolreg(unsigned regno, unsigned red, unsigned green,
			   unsigned blue, unsigned transp, struct fb_info *info)
{
	if (regno >= 256)
		return 1;

	switch (info->var.bits_per_pixel) {
	case 8:
		fb_writew(regno << 8, HD64461_CPTWAR);
		fb_writew(red >> 10, HD64461_CPTWDR);
		fb_writew(green >> 10, HD64461_CPTWDR);
		fb_writew(blue >> 10, HD64461_CPTWDR);
		break;
	case 16:
		if (regno >= 16)
			return 1;
		((u32 *) (info->pseudo_palette))[regno] =
		    ((red & 0xf800)) |
		    ((green & 0xfc00) >> 5) | ((blue & 0xf800) >> 11);
		break;
	}
	return 0;
}

__attribute__((used)) static int hitfb_sync(struct fb_info *info)
{
	hitfb_accel_wait();

	return 0;
}

__attribute__((used)) static int hitfb_check_var(struct fb_var_screeninfo *var, struct fb_info *info)
{
	int maxy;

	var->xres = info->var.xres;
	var->xres_virtual = info->var.xres;
	var->yres = info->var.yres;

	if ((var->bits_per_pixel != 8) && (var->bits_per_pixel != 16))
		var->bits_per_pixel = info->var.bits_per_pixel;

	if (var->yres_virtual < var->yres)
		var->yres_virtual = var->yres;

	maxy = info->fix.smem_len / var->xres;

	if (var->bits_per_pixel == 16)
		maxy /= 2;

	if (var->yres_virtual > maxy)
		var->yres_virtual = maxy;

	var->xoffset = 0;
	var->yoffset = 0;

	switch (var->bits_per_pixel) {
	case 8:
		var->red.offset = 0;
		var->red.length = 8;
		var->green.offset = 0;
		var->green.length = 8;
		var->blue.offset = 0;
		var->blue.length = 8;
		var->transp.offset = 0;
		var->transp.length = 0;
		break;
	case 16:		/* RGB 565 */
		var->red.offset = 11;
		var->red.length = 5;
		var->green.offset = 5;
		var->green.length = 6;
		var->blue.offset = 0;
		var->blue.length = 5;
		var->transp.offset = 0;
		var->transp.length = 0;
		break;
	}

	return 0;
}

__attribute__((used)) static int hitfb_set_par(struct fb_info *info)
{
	unsigned short ldr3;

	switch (info->var.bits_per_pixel) {
	case 8:
		info->fix.line_length = info->var.xres;
		info->fix.visual = FB_VISUAL_PSEUDOCOLOR;
		info->fix.ypanstep = 16;
		break;
	case 16:
		info->fix.line_length = info->var.xres*2;
		info->fix.visual = FB_VISUAL_TRUECOLOR;
		info->fix.ypanstep = 8;
		break;
	}

	fb_writew(info->fix.line_length, HD64461_LCDCLOR);
	ldr3 = fb_readw(HD64461_LDR3);
	ldr3 &= ~15;
	ldr3 |= (info->var.bits_per_pixel == 8) ? 4 : 8;
	fb_writew(ldr3, HD64461_LDR3);
	return 0;
}

__attribute__((used)) static int hitfb_probe(struct platform_device *dev)
{
	unsigned short lcdclor, ldr3, ldvndr;
	struct fb_info *info;
	int ret;

	if (fb_get_options("hitfb", NULL))
		return -ENODEV;

	hitfb_fix.mmio_start = HD64461_IO_OFFSET(0x1000);
	hitfb_fix.mmio_len = 0x1000;
	hitfb_fix.smem_start = HD64461_IO_OFFSET(0x02000000);
	hitfb_fix.smem_len = 512 * 1024;

	lcdclor = fb_readw(HD64461_LCDCLOR);
	ldvndr = fb_readw(HD64461_LDVNDR);
	ldr3 = fb_readw(HD64461_LDR3);

	switch (ldr3 & 15) {
	default:
	case 4:
		hitfb_var.bits_per_pixel = 8;
		hitfb_var.xres = lcdclor;
		break;
	case 8:
		hitfb_var.bits_per_pixel = 16;
		hitfb_var.xres = lcdclor / 2;
		break;
	}
	hitfb_fix.line_length = lcdclor;
	hitfb_fix.visual = (hitfb_var.bits_per_pixel == 8) ?
	    FB_VISUAL_PSEUDOCOLOR : FB_VISUAL_TRUECOLOR;
	hitfb_var.yres = ldvndr + 1;
	hitfb_var.xres_virtual = hitfb_var.xres;
	hitfb_var.yres_virtual = hitfb_fix.smem_len / lcdclor;
	switch (hitfb_var.bits_per_pixel) {
	case 8:
		hitfb_var.red.offset = 0;
		hitfb_var.red.length = 8;
		hitfb_var.green.offset = 0;
		hitfb_var.green.length = 8;
		hitfb_var.blue.offset = 0;
		hitfb_var.blue.length = 8;
		hitfb_var.transp.offset = 0;
		hitfb_var.transp.length = 0;
		break;
	case 16:		/* RGB 565 */
		hitfb_var.red.offset = 11;
		hitfb_var.red.length = 5;
		hitfb_var.green.offset = 5;
		hitfb_var.green.length = 6;
		hitfb_var.blue.offset = 0;
		hitfb_var.blue.length = 5;
		hitfb_var.transp.offset = 0;
		hitfb_var.transp.length = 0;
		break;
	}

	info = framebuffer_alloc(sizeof(u32) * 16, &dev->dev);
	if (unlikely(!info))
		return -ENOMEM;

	info->fbops = &hitfb_ops;
	info->var = hitfb_var;
	info->fix = hitfb_fix;
	info->pseudo_palette = info->par;
	info->flags = FBINFO_DEFAULT | FBINFO_HWACCEL_YPAN |
		FBINFO_HWACCEL_FILLRECT | FBINFO_HWACCEL_COPYAREA;

	info->screen_base = (void *)hitfb_fix.smem_start;

	ret = fb_alloc_cmap(&info->cmap, 256, 0);
	if (unlikely(ret < 0))
		goto err_fb;

	ret = register_framebuffer(info);
	if (unlikely(ret < 0))
		goto err;

	platform_set_drvdata(dev, info);

	fb_info(info, "%s frame buffer device\n", info->fix.id);

	return 0;

err:
	fb_dealloc_cmap(&info->cmap);
err_fb:
	framebuffer_release(info);
	return ret;
}

__attribute__((used)) static int hitfb_remove(struct platform_device *dev)
{
	struct fb_info *info = platform_get_drvdata(dev);

	unregister_framebuffer(info);
	fb_dealloc_cmap(&info->cmap);
	framebuffer_release(info);

	return 0;
}

__attribute__((used)) static int hitfb_suspend(struct device *dev)
{
	u16 v;

	hitfb_blank(1,0);
	v = fb_readw(HD64461_STBCR);
	v |= HD64461_STBCR_SLCKE_IST;
	fb_writew(v, HD64461_STBCR);

	return 0;
}

__attribute__((used)) static int hitfb_resume(struct device *dev)
{
	u16 v;

	v = fb_readw(HD64461_STBCR);
	v &= ~HD64461_STBCR_SLCKE_OST;
	msleep(100);
	v = fb_readw(HD64461_STBCR);
	v &= ~HD64461_STBCR_SLCKE_IST;
	fb_writew(v, HD64461_STBCR);
	hitfb_blank(0,0);

	return 0;
}

