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
typedef  scalar_t__ u16 ;
struct TYPE_7__ {int /*<<< orphan*/  dc; } ;
struct TYPE_6__ {int* buf; } ;
struct TYPE_5__ {int (* write ) (struct fbtft_par*,int*,int) ;int /*<<< orphan*/  (* reset ) (struct fbtft_par*) ;} ;
struct fbtft_par {TYPE_4__* info; TYPE_3__ gpio; TYPE_2__ txbuf; TYPE_1__ fbtftops; } ;
struct TYPE_8__ {int /*<<< orphan*/  device; scalar_t__ screen_buffer; } ;

/* Variables and functions */
 int LCD_ADV_PROG_CTRL ; 
 int LCD_ADV_PROG_CTRL2 ; 
 int LCD_ALL_PIXEL ; 
 int LCD_BIAS ; 
 int LCD_BOTTOMVIEW ; 
 int LCD_COL_ADDRESS ; 
 int LCD_DISPLAY_ENABLE ; 
 int LCD_DISPLAY_INVERT ; 
 int LCD_NO_OP ; 
 int LCD_PAGE_ADDRESS ; 
 int LCD_POWER_CONTROL ; 
 int LCD_RESET_CMD ; 
 int LCD_SCAN_DIR ; 
 int LCD_START_LINE ; 
 int LCD_TEMPCOMP_HIGH ; 
 int LCD_VOLTAGE ; 
 int LCD_VOLUME_MODE ; 
 int PAGES ; 
 int WIDTH ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  gpio_set_value (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  stub1 (struct fbtft_par*) ; 
 int stub2 (struct fbtft_par*,int*,int) ; 
 int /*<<< orphan*/  write_reg (struct fbtft_par*,int) ; 

__attribute__((used)) static int init_display(struct fbtft_par *par)
{
	par->fbtftops.reset(par);

	/* softreset of LCD */
	write_reg(par, LCD_RESET_CMD);
	mdelay(10);

	/* set startpoint */
	write_reg(par, LCD_START_LINE);

	/* select orientation BOTTOMVIEW */
	write_reg(par, LCD_BOTTOMVIEW | 1);

	/* output mode select (turns display upside-down) */
	write_reg(par, LCD_SCAN_DIR | 0x00);

	/* Normal Pixel mode */
	write_reg(par, LCD_ALL_PIXEL | 0);

	/* positive display */
	write_reg(par, LCD_DISPLAY_INVERT | 0);

	/* bias 1/9 */
	write_reg(par, LCD_BIAS | 0);

	/* power control mode: all features on */
	write_reg(par, LCD_POWER_CONTROL | 0x07);

	/* set voltage regulator R/R */
	write_reg(par, LCD_VOLTAGE | 0x07);

	/* volume mode set */
	write_reg(par, LCD_VOLUME_MODE);
	write_reg(par, 0x09);
	write_reg(par, LCD_NO_OP);

	/* advanced program control */
	write_reg(par, LCD_ADV_PROG_CTRL);
	write_reg(par, LCD_ADV_PROG_CTRL2 | LCD_TEMPCOMP_HIGH);

	/* enable display */
	write_reg(par, LCD_DISPLAY_ENABLE | 1);

	return 0;
}

__attribute__((used)) static void set_addr_win(struct fbtft_par *par, int xs, int ys, int xe, int ye)
{
	/* goto address */
	write_reg(par, LCD_PAGE_ADDRESS);
	write_reg(par, 0x00);
	write_reg(par, LCD_COL_ADDRESS);
}

__attribute__((used)) static int write_vmem(struct fbtft_par *par, size_t offset, size_t len)
{
	u16 *vmem16 = (u16 *)par->info->screen_buffer;
	u8 *buf;
	int x, y, i;
	int ret = 0;

	for (y = 0; y < PAGES; y++) {
		buf = par->txbuf.buf;
		for (x = 0; x < WIDTH; x++) {
			*buf = 0x00;
			for (i = 0; i < 8; i++)
				*buf |= (vmem16[((y * 8 * WIDTH) +
						 (i * WIDTH)) + x] ?
					 1 : 0) << i;
			buf++;
		}

		write_reg(par, LCD_PAGE_ADDRESS | (u8)y);
		write_reg(par, 0x00);
		write_reg(par, LCD_COL_ADDRESS);
		gpio_set_value(par->gpio.dc, 1);
		ret = par->fbtftops.write(par, par->txbuf.buf, WIDTH);
		gpio_set_value(par->gpio.dc, 0);
	}

	if (ret < 0)
		dev_err(par->info->device, "write failed and returned: %d\n",
			ret);

	return ret;
}

