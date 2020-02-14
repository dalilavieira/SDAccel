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
struct fb_info {int dummy; } ;

/* Variables and functions */
 unsigned int IMS332_REG_COLOR_PALETTE ; 
 scalar_t__ MAXINEFB_IMS332_ADDRESS ; 

void maxinefb_ims332_write_register(int regno, register unsigned int val)
{
	register unsigned char *regs = (char *) MAXINEFB_IMS332_ADDRESS;
	unsigned char *wptr;

	wptr = regs + 0xa0000 + (regno << 4);
	*((volatile unsigned int *) (regs)) = (val >> 8) & 0xff00;
	*((volatile unsigned short *) (wptr)) = val;
}

unsigned int maxinefb_ims332_read_register(int regno)
{
	register unsigned char *regs = (char *) MAXINEFB_IMS332_ADDRESS;
	unsigned char *rptr;
	register unsigned int j, k;

	rptr = regs + 0x80000 + (regno << 4);
	j = *((volatile unsigned short *) rptr);
	k = *((volatile unsigned short *) regs);

	return (j & 0xffff) | ((k & 0xff00) << 8);
}

__attribute__((used)) static int maxinefb_setcolreg(unsigned regno, unsigned red, unsigned green,
			      unsigned blue, unsigned transp, struct fb_info *info)
{
	/* value to be written into the palette reg. */
	unsigned long hw_colorvalue = 0;

	if (regno > 255)
		return 1;

	red   >>= 8;    /* The cmap fields are 16 bits    */
	green >>= 8;    /* wide, but the harware colormap */
	blue  >>= 8;    /* registers are only 8 bits wide */

	hw_colorvalue = (blue << 16) + (green << 8) + (red);

	maxinefb_ims332_write_register(IMS332_REG_COLOR_PALETTE + regno,
				       hw_colorvalue);
	return 0;
}

