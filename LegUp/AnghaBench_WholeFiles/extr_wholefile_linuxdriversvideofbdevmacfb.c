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
typedef  unsigned int u32 ;
struct toby_cmap_regs {int /*<<< orphan*/  lut; int /*<<< orphan*/  addr; } ;
struct mdc_cmap_regs {int /*<<< orphan*/  lut; int /*<<< orphan*/  addr; } ;
struct jet_cmap_regs {int /*<<< orphan*/  lut; int /*<<< orphan*/  addr; } ;
struct TYPE_14__ {unsigned int offset; } ;
struct TYPE_13__ {unsigned int offset; } ;
struct TYPE_12__ {int offset; } ;
struct TYPE_16__ {unsigned int bits_per_pixel; TYPE_3__ blue; TYPE_2__ green; TYPE_1__ red; } ;
struct TYPE_15__ {int* red; int* green; int* blue; unsigned int len; } ;
struct fb_info {TYPE_5__ var; scalar_t__ pseudo_palette; TYPE_4__ cmap; } ;
struct TYPE_20__ {int /*<<< orphan*/  clut_data; int /*<<< orphan*/  clut_waddr; } ;
struct TYPE_19__ {int /*<<< orphan*/  lut; int /*<<< orphan*/  reset; } ;
struct TYPE_18__ {int /*<<< orphan*/  lut; int /*<<< orphan*/  addr; int /*<<< orphan*/  cntl; } ;
struct TYPE_17__ {int /*<<< orphan*/  lut; int /*<<< orphan*/  addr; } ;
struct TYPE_11__ {int /*<<< orphan*/  lut; int /*<<< orphan*/  status2; int /*<<< orphan*/  addr; } ;

/* Variables and functions */
 TYPE_10__* civic_cmap_regs ; 
 TYPE_9__* csc_cmap_regs ; 
 TYPE_8__* dafb_cmap_regs ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 int /*<<< orphan*/  macfb_setpalette (unsigned int,unsigned int,unsigned int,unsigned int,struct fb_info*) ; 
 int /*<<< orphan*/  nop () ; 
 void* nubus_readb (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nubus_writeb (unsigned int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nubus_writel (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 TYPE_7__* rbv_cmap_regs ; 
 void* slot_addr ; 
 int /*<<< orphan*/  udelay (int) ; 
 TYPE_6__* v8_brazil_cmap_regs ; 

__attribute__((used)) static int dafb_setpalette(unsigned int regno, unsigned int red,
			   unsigned int green, unsigned int blue,
			   struct fb_info *info)
{
	static int lastreg = -1;
	unsigned long flags;

	local_irq_save(flags);

	/*
	 * fbdev will set an entire colourmap, but X won't.  Hopefully
	 * this should accommodate both of them
	 */
	if (regno != lastreg + 1) {
		int i;

		/* Stab in the dark trying to reset the CLUT pointer */
		nubus_writel(0, &dafb_cmap_regs->reset);
		nop();

		/* Loop until we get to the register we want */
		for (i = 0; i < regno; i++) {
			nubus_writeb(info->cmap.red[i] >> 8,
				     &dafb_cmap_regs->lut);
			nop();
			nubus_writeb(info->cmap.green[i] >> 8,
				     &dafb_cmap_regs->lut);
			nop();
			nubus_writeb(info->cmap.blue[i] >> 8,
				     &dafb_cmap_regs->lut);
			nop();
		}
	}

	nubus_writeb(red, &dafb_cmap_regs->lut);
	nop();
	nubus_writeb(green, &dafb_cmap_regs->lut);
	nop();
	nubus_writeb(blue, &dafb_cmap_regs->lut);

	local_irq_restore(flags);
	lastreg = regno;
	return 0;
}

__attribute__((used)) static int v8_brazil_setpalette(unsigned int regno, unsigned int red,
				unsigned int green, unsigned int blue,
				struct fb_info *info)
{
	unsigned int bpp = info->var.bits_per_pixel;
	unsigned long flags;

	if (bpp > 8)
		return 1; /* failsafe */

	local_irq_save(flags);

	/* On these chips, the CLUT register numbers are spread out
	 * across the register space.  Thus:
	 * In 8bpp, all regnos are valid.
	 * In 4bpp, the regnos are 0x0f, 0x1f, 0x2f, etc, etc
	 * In 2bpp, the regnos are 0x3f, 0x7f, 0xbf, 0xff
	 */
	regno = (regno << (8 - bpp)) | (0xFF >> bpp);
	nubus_writeb(regno, &v8_brazil_cmap_regs->addr);
	nop();

	/* send one color channel at a time */
	nubus_writeb(red, &v8_brazil_cmap_regs->lut);
	nop();
	nubus_writeb(green, &v8_brazil_cmap_regs->lut);
	nop();
	nubus_writeb(blue, &v8_brazil_cmap_regs->lut);

	local_irq_restore(flags);
	return 0;
}

__attribute__((used)) static int rbv_setpalette(unsigned int regno, unsigned int red,
			  unsigned int green, unsigned int blue,
			  struct fb_info *info)
{
	unsigned long flags;

	if (info->var.bits_per_pixel > 8)
		return 1; /* failsafe */

	local_irq_save(flags);

	/* From the VideoToolbox driver.  Seems to be saying that
	 * regno #254 and #255 are the important ones for 1-bit color,
	 * regno #252-255 are the important ones for 2-bit color, etc.
	 */
	regno += 256 - (1 << info->var.bits_per_pixel);

	/* reset clut? (VideoToolbox sez "not necessary") */
	nubus_writeb(0xFF, &rbv_cmap_regs->cntl);
	nop();

	/* tell clut which address to use. */
	nubus_writeb(regno, &rbv_cmap_regs->addr);
	nop();

	/* send one color channel at a time. */
	nubus_writeb(red, &rbv_cmap_regs->lut);
	nop();
	nubus_writeb(green, &rbv_cmap_regs->lut);
	nop();
	nubus_writeb(blue, &rbv_cmap_regs->lut);

	local_irq_restore(flags);
	return 0;
}

__attribute__((used)) static int mdc_setpalette(unsigned int regno, unsigned int red,
			  unsigned int green, unsigned int blue,
			  struct fb_info *info)
{
	struct mdc_cmap_regs *cmap_regs = slot_addr;
	unsigned long flags;

	local_irq_save(flags);

	/* the nop's are there to order writes. */
	nubus_writeb(regno, &cmap_regs->addr);
	nop();
	nubus_writeb(red, &cmap_regs->lut);
	nop();
	nubus_writeb(green, &cmap_regs->lut);
	nop();
	nubus_writeb(blue, &cmap_regs->lut);

	local_irq_restore(flags);
	return 0;
}

__attribute__((used)) static int toby_setpalette(unsigned int regno, unsigned int red,
			   unsigned int green, unsigned int blue,
			   struct fb_info *info)
{
	struct toby_cmap_regs *cmap_regs = slot_addr;
	unsigned int bpp = info->var.bits_per_pixel;
	unsigned long flags;

	red = ~red;
	green = ~green;
	blue = ~blue;
	regno = (regno << (8 - bpp)) | (0xFF >> bpp);

	local_irq_save(flags);

	nubus_writeb(regno, &cmap_regs->addr);
	nop();
	nubus_writeb(red, &cmap_regs->lut);
	nop();
	nubus_writeb(green, &cmap_regs->lut);
	nop();
	nubus_writeb(blue, &cmap_regs->lut);

	local_irq_restore(flags);
	return 0;
}

__attribute__((used)) static int jet_setpalette(unsigned int regno, unsigned int red,
			  unsigned int green, unsigned int blue,
			  struct fb_info *info)
{
	struct jet_cmap_regs *cmap_regs = slot_addr;
	unsigned long flags;

	local_irq_save(flags);

	nubus_writeb(regno, &cmap_regs->addr);
	nop();
	nubus_writeb(red, &cmap_regs->lut);
	nop();
	nubus_writeb(green, &cmap_regs->lut);
	nop();
	nubus_writeb(blue, &cmap_regs->lut);

	local_irq_restore(flags);
	return 0;
}

__attribute__((used)) static int civic_setpalette(unsigned int regno, unsigned int red,
			    unsigned int green, unsigned int blue,
			    struct fb_info *info)
{
	unsigned long flags;
	int clut_status;
	
	if (info->var.bits_per_pixel > 8)
		return 1; /* failsafe */

	local_irq_save(flags);

	/* Set the register address */
	nubus_writeb(regno, &civic_cmap_regs->addr);
	nop();

	/*
	 * Grab a status word and do some checking;
	 * Then finally write the clut!
	 */
	clut_status =  nubus_readb(&civic_cmap_regs->status2);

	if ((clut_status & 0x0008) == 0)
	{
#if 0
		if ((clut_status & 0x000D) != 0)
		{
			nubus_writeb(0x00, &civic_cmap_regs->lut);
			nop();
			nubus_writeb(0x00, &civic_cmap_regs->lut);
			nop();
		}
#endif

		nubus_writeb(red, &civic_cmap_regs->lut);
		nop();
		nubus_writeb(green, &civic_cmap_regs->lut);
		nop();
		nubus_writeb(blue, &civic_cmap_regs->lut);
		nop();
		nubus_writeb(0x00, &civic_cmap_regs->lut);
	}
	else
	{
		unsigned char junk;

		junk = nubus_readb(&civic_cmap_regs->lut);
		nop();
		junk = nubus_readb(&civic_cmap_regs->lut);
		nop();
		junk = nubus_readb(&civic_cmap_regs->lut);
		nop();
		junk = nubus_readb(&civic_cmap_regs->lut);
		nop();

		if ((clut_status & 0x000D) != 0)
		{
			nubus_writeb(0x00, &civic_cmap_regs->lut);
			nop();
			nubus_writeb(0x00, &civic_cmap_regs->lut);
			nop();
		}

		nubus_writeb(red, &civic_cmap_regs->lut);
		nop();
		nubus_writeb(green, &civic_cmap_regs->lut);
		nop();
		nubus_writeb(blue, &civic_cmap_regs->lut);
		nop();
		nubus_writeb(junk, &civic_cmap_regs->lut);
	}

	local_irq_restore(flags);
	return 0;
}

__attribute__((used)) static int csc_setpalette(unsigned int regno, unsigned int red,
			  unsigned int green, unsigned int blue,
			  struct fb_info *info)
{
	unsigned long flags;

	local_irq_save(flags);

	udelay(1); /* mklinux on PB 5300 waits for 260 ns */
	nubus_writeb(regno, &csc_cmap_regs->clut_waddr);
	nubus_writeb(red, &csc_cmap_regs->clut_data);
	nubus_writeb(green, &csc_cmap_regs->clut_data);
	nubus_writeb(blue, &csc_cmap_regs->clut_data);

	local_irq_restore(flags);
	return 0;
}

__attribute__((used)) static int macfb_setcolreg(unsigned regno, unsigned red, unsigned green,
			   unsigned blue, unsigned transp,
			   struct fb_info *fb_info)
{
	/*
	 * Set a single color register. The values supplied are
	 * already rounded down to the hardware's capabilities
	 * (according to the entries in the `var' structure).
	 * Return non-zero for invalid regno.
	 */
	
	if (regno >= fb_info->cmap.len)
		return 1;

	if (fb_info->var.bits_per_pixel <= 8) {
		switch (fb_info->var.bits_per_pixel) {
		case 1:
			/* We shouldn't get here */
			break;
		case 2:
		case 4:
		case 8:
			if (macfb_setpalette)
				macfb_setpalette(regno, red >> 8, green >> 8,
						 blue >> 8, fb_info);
			else
				return 1;
			break;
		}
	} else if (regno < 16) {
		switch (fb_info->var.bits_per_pixel) {
		case 16:
			if (fb_info->var.red.offset == 10) {
				/* 1:5:5:5 */
				((u32*) (fb_info->pseudo_palette))[regno] =
					((red   & 0xf800) >>  1) |
					((green & 0xf800) >>  6) |
					((blue  & 0xf800) >> 11) |
					((transp != 0) << 15);
			} else {
				/* 0:5:6:5 */
				((u32*) (fb_info->pseudo_palette))[regno] =
					((red   & 0xf800) >>  0) |
					((green & 0xfc00) >>  5) |
					((blue  & 0xf800) >> 11);
			}
			break;
		/*
		 * 24-bit colour almost doesn't exist on 68k Macs --
		 * http://support.apple.com/kb/TA28634 (Old Article: 10992)
		 */
		case 24:
		case 32:
			red   >>= 8;
			green >>= 8;
			blue  >>= 8;
			((u32 *)(fb_info->pseudo_palette))[regno] =
				(red   << fb_info->var.red.offset) |
				(green << fb_info->var.green.offset) |
				(blue  << fb_info->var.blue.offset);
			break;
		}
	}

	return 0;
}

