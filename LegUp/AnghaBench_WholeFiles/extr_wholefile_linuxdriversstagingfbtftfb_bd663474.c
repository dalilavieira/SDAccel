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
struct TYPE_6__ {int /*<<< orphan*/  (* reset ) (struct fbtft_par*) ;} ;
struct TYPE_5__ {int cs; } ;
struct fbtft_par {TYPE_4__* info; TYPE_2__ fbtftops; TYPE_1__ gpio; } ;
struct TYPE_7__ {int rotate; } ;
struct TYPE_8__ {TYPE_3__ var; } ;

/* Variables and functions */
 int /*<<< orphan*/  HEIGHT ; 
 int /*<<< orphan*/  WIDTH ; 
 int /*<<< orphan*/  gpio_set_value (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  stub1 (struct fbtft_par*) ; 
 int /*<<< orphan*/  write_reg (struct fbtft_par*,int,...) ; 

__attribute__((used)) static int init_display(struct fbtft_par *par)
{
	if (par->gpio.cs != -1)
		gpio_set_value(par->gpio.cs, 0);  /* Activate chip */

	par->fbtftops.reset(par);

	/* Initialization sequence from Lib_UTFT */

	/* oscillator start */
	write_reg(par, 0x000, 0x0001);	/*oscillator 0: stop, 1: operation */
	mdelay(10);

	/* Power settings */
	write_reg(par, 0x100, 0x0000); /* power supply setup */
	write_reg(par, 0x101, 0x0000);
	write_reg(par, 0x102, 0x3110);
	write_reg(par, 0x103, 0xe200);
	write_reg(par, 0x110, 0x009d);
	write_reg(par, 0x111, 0x0022);
	write_reg(par, 0x100, 0x0120);
	mdelay(20);

	write_reg(par, 0x100, 0x3120);
	mdelay(80);
	/* Display control */
	write_reg(par, 0x001, 0x0100);
	write_reg(par, 0x002, 0x0000);
	write_reg(par, 0x003, 0x1230);
	write_reg(par, 0x006, 0x0000);
	write_reg(par, 0x007, 0x0101);
	write_reg(par, 0x008, 0x0808);
	write_reg(par, 0x009, 0x0000);
	write_reg(par, 0x00b, 0x0000);
	write_reg(par, 0x00c, 0x0000);
	write_reg(par, 0x00d, 0x0018);
	/* LTPS control settings */
	write_reg(par, 0x012, 0x0000);
	write_reg(par, 0x013, 0x0000);
	write_reg(par, 0x018, 0x0000);
	write_reg(par, 0x019, 0x0000);

	write_reg(par, 0x203, 0x0000);
	write_reg(par, 0x204, 0x0000);

	write_reg(par, 0x210, 0x0000);
	write_reg(par, 0x211, 0x00ef);
	write_reg(par, 0x212, 0x0000);
	write_reg(par, 0x213, 0x013f);
	write_reg(par, 0x214, 0x0000);
	write_reg(par, 0x215, 0x0000);
	write_reg(par, 0x216, 0x0000);
	write_reg(par, 0x217, 0x0000);

	/* Gray scale settings */
	write_reg(par, 0x300, 0x5343);
	write_reg(par, 0x301, 0x1021);
	write_reg(par, 0x302, 0x0003);
	write_reg(par, 0x303, 0x0011);
	write_reg(par, 0x304, 0x050a);
	write_reg(par, 0x305, 0x4342);
	write_reg(par, 0x306, 0x1100);
	write_reg(par, 0x307, 0x0003);
	write_reg(par, 0x308, 0x1201);
	write_reg(par, 0x309, 0x050a);

	/* RAM access settings */
	write_reg(par, 0x400, 0x4027);
	write_reg(par, 0x401, 0x0000);
	write_reg(par, 0x402, 0x0000);  /* First screen drive position (1) */
	write_reg(par, 0x403, 0x013f);  /* First screen drive position (2) */
	write_reg(par, 0x404, 0x0000);

	write_reg(par, 0x200, 0x0000);
	write_reg(par, 0x201, 0x0000);
	write_reg(par, 0x100, 0x7120);
	write_reg(par, 0x007, 0x0103);
	mdelay(10);
	write_reg(par, 0x007, 0x0113);

	return 0;
}

__attribute__((used)) static void set_addr_win(struct fbtft_par *par, int xs, int ys, int xe, int ye)
{
	switch (par->info->var.rotate) {
	/* R200h = Horizontal GRAM Start Address */
	/* R201h = Vertical GRAM Start Address */
	case 0:
		write_reg(par, 0x0200, xs);
		write_reg(par, 0x0201, ys);
		break;
	case 180:
		write_reg(par, 0x0200, WIDTH - 1 - xs);
		write_reg(par, 0x0201, HEIGHT - 1 - ys);
		break;
	case 270:
		write_reg(par, 0x0200, WIDTH - 1 - ys);
		write_reg(par, 0x0201, xs);
		break;
	case 90:
		write_reg(par, 0x0200, ys);
		write_reg(par, 0x0201, HEIGHT - 1 - xs);
		break;
	}
	write_reg(par, 0x202); /* Write Data to GRAM */
}

__attribute__((used)) static int set_var(struct fbtft_par *par)
{
	switch (par->info->var.rotate) {
	/* AM: GRAM update direction */
	case 0:
		write_reg(par, 0x003, 0x1230);
		break;
	case 180:
		write_reg(par, 0x003, 0x1200);
		break;
	case 270:
		write_reg(par, 0x003, 0x1228);
		break;
	case 90:
		write_reg(par, 0x003, 0x1218);
		break;
	}

	return 0;
}

