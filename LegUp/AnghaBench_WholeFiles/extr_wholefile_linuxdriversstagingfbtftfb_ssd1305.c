#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_6__ ;
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
typedef  scalar_t__ u16 ;
struct TYPE_10__ {int* buf; } ;
struct TYPE_9__ {int (* write ) (struct fbtft_par*,int*,int) ;int /*<<< orphan*/  (* reset ) (struct fbtft_par*) ;} ;
struct TYPE_8__ {int /*<<< orphan*/  dc; } ;
struct TYPE_7__ {int* curves; int /*<<< orphan*/  lock; } ;
struct fbtft_par {TYPE_6__* info; TYPE_4__ txbuf; TYPE_3__ fbtftops; TYPE_2__ gpio; TYPE_1__ gamma; } ;
struct TYPE_11__ {int yres; int rotate; int xres; } ;
struct TYPE_12__ {int /*<<< orphan*/  device; TYPE_5__ var; scalar_t__ screen_buffer; } ;

/* Variables and functions */
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  gpio_set_value (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (struct fbtft_par*) ; 
 int stub2 (struct fbtft_par*,int*,int) ; 
 int /*<<< orphan*/  write_reg (struct fbtft_par*,int) ; 

__attribute__((used)) static int init_display(struct fbtft_par *par)
{
	par->fbtftops.reset(par);

	if (par->gamma.curves[0] == 0) {
		mutex_lock(&par->gamma.lock);
		if (par->info->var.yres == 64)
			par->gamma.curves[0] = 0xCF;
		else
			par->gamma.curves[0] = 0x8F;
		mutex_unlock(&par->gamma.lock);
	}

	/* Set Display OFF */
	write_reg(par, 0xAE);

	/* Set Display Clock Divide Ratio/ Oscillator Frequency */
	write_reg(par, 0xD5);
	write_reg(par, 0x80);

	/* Set Multiplex Ratio */
	write_reg(par, 0xA8);
	if (par->info->var.yres == 64)
		write_reg(par, 0x3F);
	else
		write_reg(par, 0x1F);

	/* Set Display Offset */
	write_reg(par, 0xD3);
	write_reg(par, 0x0);

	/* Set Display Start Line */
	write_reg(par, 0x40 | 0x0);

	/* Charge Pump Setting */
	write_reg(par, 0x8D);
	/* A[2] = 1b, Enable charge pump during display on */
	write_reg(par, 0x14);

	/* Set Memory Addressing Mode */
	write_reg(par, 0x20);
	/* Vertical addressing mode  */
	write_reg(par, 0x01);

	/*
	 * Set Segment Re-map
	 * column address 127 is mapped to SEG0
	 */
	write_reg(par, 0xA0 | ((par->info->var.rotate == 180) ? 0x0 : 0x1));

	/*
	 * Set COM Output Scan Direction
	 * remapped mode. Scan from COM[N-1] to COM0
	 */
	write_reg(par, ((par->info->var.rotate == 180) ? 0xC8 : 0xC0));

	/* Set COM Pins Hardware Configuration */
	write_reg(par, 0xDA);
	if (par->info->var.yres == 64) {
		/* A[4]=1b, Alternative COM pin configuration */
		write_reg(par, 0x12);
	} else {
		/* A[4]=0b, Sequential COM pin configuration */
		write_reg(par, 0x02);
	}

	/* Set Pre-charge Period */
	write_reg(par, 0xD9);
	write_reg(par, 0xF1);

	/*
	 * Entire Display ON
	 * Resume to RAM content display. Output follows RAM content
	 */
	write_reg(par, 0xA4);

	/*
	 * Set Normal Display
	 *  0 in RAM: OFF in display panel
	 *  1 in RAM: ON in display panel
	 */
	write_reg(par, 0xA6);

	/* Set Display ON */
	write_reg(par, 0xAF);

	return 0;
}

__attribute__((used)) static void set_addr_win(struct fbtft_par *par, int xs, int ys, int xe, int ye)
{
	/* Set Lower Column Start Address for Page Addressing Mode */
	write_reg(par, 0x00 | ((par->info->var.rotate == 180) ? 0x0 : 0x4));
	/* Set Higher Column Start Address for Page Addressing Mode */
	write_reg(par, 0x10 | 0x0);
	/* Set Display Start Line */
	write_reg(par, 0x40 | 0x0);
}

__attribute__((used)) static int blank(struct fbtft_par *par, bool on)
{
	if (on)
		write_reg(par, 0xAE);
	else
		write_reg(par, 0xAF);
	return 0;
}

__attribute__((used)) static int set_gamma(struct fbtft_par *par, u32 *curves)
{
	curves[0] &= 0xFF;
	/* Set Contrast Control for BANK0 */
	write_reg(par, 0x81);
	write_reg(par, curves[0]);

	return 0;
}

__attribute__((used)) static int write_vmem(struct fbtft_par *par, size_t offset, size_t len)
{
	u16 *vmem16 = (u16 *)par->info->screen_buffer;
	u8 *buf = par->txbuf.buf;
	int x, y, i;
	int ret;

	for (x = 0; x < par->info->var.xres; x++) {
		for (y = 0; y < par->info->var.yres / 8; y++) {
			*buf = 0x00;
			for (i = 0; i < 8; i++)
				*buf |= (vmem16[(y * 8 + i) *
						par->info->var.xres + x] ?
					 1 : 0) << i;
			buf++;
		}
	}

	/* Write data */
	gpio_set_value(par->gpio.dc, 1);
	ret = par->fbtftops.write(par, par->txbuf.buf,
				  par->info->var.xres * par->info->var.yres /
				  8);
	if (ret < 0)
		dev_err(par->info->device, "write failed and returned: %d\n",
			ret);
	return ret;
}

