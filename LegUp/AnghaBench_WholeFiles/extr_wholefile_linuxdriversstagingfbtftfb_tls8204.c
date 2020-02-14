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
typedef  int u8 ;
typedef  int u32 ;
typedef  scalar_t__ u16 ;
struct TYPE_7__ {int* buf; } ;
struct TYPE_6__ {int (* write ) (struct fbtft_par*,int*,int) ;int /*<<< orphan*/  (* reset ) (struct fbtft_par*) ;} ;
struct TYPE_5__ {int /*<<< orphan*/  dc; } ;
struct fbtft_par {TYPE_4__* info; TYPE_3__ txbuf; TYPE_2__ fbtftops; TYPE_1__ gpio; } ;
struct TYPE_8__ {int /*<<< orphan*/  device; scalar_t__ screen_buffer; } ;

/* Variables and functions */
 int HEIGHT ; 
 int WIDTH ; 
 int bs ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  gpio_set_value (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub1 (struct fbtft_par*) ; 
 int stub2 (struct fbtft_par*,int*,int) ; 
 int /*<<< orphan*/  write_reg (struct fbtft_par*,int) ; 

__attribute__((used)) static int init_display(struct fbtft_par *par)
{
	par->fbtftops.reset(par);

	/* Enter extended command mode */
	write_reg(par, 0x21);	/* 5:1  1
				 * 2:0  PD - Powerdown control: chip is active
				 * 1:0  V  - Entry mode: horizontal addressing
				 * 0:1  H  - Extended instruction set control:
				 *	     extended
				 */

	/* H=1 Bias system */
	write_reg(par, 0x10 | (bs & 0x7));
				/* 4:1  1
				 * 3:0  0
				 * 2:x  BS2 - Bias System
				 * 1:x  BS1
				 * 0:x  BS0
				 */

	/* Set the address of the first display line. */
	write_reg(par, 0x04 | (64 >> 6));
	write_reg(par, 0x40 | (64 & 0x3F));

	/* Enter H=0 standard command mode */
	write_reg(par, 0x20);

	/* H=0 Display control */
	write_reg(par, 0x08 | 4);
				/* 3:1  1
				 * 2:1  D - DE: 10=normal mode
				 * 1:0  0
				 * 0:0  E
				 */

	return 0;
}

__attribute__((used)) static void set_addr_win(struct fbtft_par *par, int xs, int ys, int xe, int ye)
{
	/* H=0 Set X address of RAM */
	write_reg(par, 0x80);	/* 7:1  1
				 * 6-0: X[6:0] - 0x00
				 */

	/* H=0 Set Y address of RAM */
	write_reg(par, 0x40);	/* 7:0  0
				 * 6:1  1
				 * 2-0: Y[2:0] - 0x0
				 */
}

__attribute__((used)) static int write_vmem(struct fbtft_par *par, size_t offset, size_t len)
{
	u16 *vmem16 = (u16 *)par->info->screen_buffer;
	int x, y, i;
	int ret = 0;

	for (y = 0; y < HEIGHT / 8; y++) {
		u8 *buf = par->txbuf.buf;
		/* The display is 102x68 but the LCD is 84x48.
		 * Set the write pointer at the start of each row.
		 */
		gpio_set_value(par->gpio.dc, 0);
		write_reg(par, 0x80 | 0);
		write_reg(par, 0x40 | y);

		for (x = 0; x < WIDTH; x++) {
			u8 ch = 0;

			for (i = 0; i < 8 * WIDTH; i += WIDTH) {
				ch >>= 1;
				if (vmem16[(y * 8 * WIDTH) + i + x])
					ch |= 0x80;
			}
			*buf++ = ch;
		}
		/* Write the row */
		gpio_set_value(par->gpio.dc, 1);
		ret = par->fbtftops.write(par, par->txbuf.buf, WIDTH);
		if (ret < 0) {
			dev_err(par->info->device,
				"write failed and returned: %d\n", ret);
			break;
		}
	}

	return ret;
}

__attribute__((used)) static int set_gamma(struct fbtft_par *par, u32 *curves)
{
	/* apply mask */
	curves[0] &= 0x7F;

	write_reg(par, 0x21); /* turn on extended instruction set */
	write_reg(par, 0x80 | curves[0]);
	write_reg(par, 0x20); /* turn off extended instruction set */

	return 0;
}

