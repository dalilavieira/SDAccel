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
struct TYPE_6__ {int cs; } ;
struct TYPE_5__ {int /*<<< orphan*/  (* reset ) (struct fbtft_par*) ;} ;
struct fbtft_par {scalar_t__ bgr; TYPE_4__* info; TYPE_2__ gpio; TYPE_1__ fbtftops; } ;
struct TYPE_7__ {int rotate; } ;
struct TYPE_8__ {TYPE_3__ var; } ;

/* Variables and functions */
 int BIT (int) ; 
 int /*<<< orphan*/  CMD_DFUNCTR ; 
 int /*<<< orphan*/  CMD_DINVCTR ; 
 int /*<<< orphan*/  CMD_FRMCTR1 ; 
 int /*<<< orphan*/  CMD_PWCTR1 ; 
 int /*<<< orphan*/  CMD_PWCTR2 ; 
 int /*<<< orphan*/  CMD_VCOMCTR1 ; 
 int /*<<< orphan*/  CMD_VCOMOFFS ; 
 int /*<<< orphan*/  HEIGHT ; 
 int /*<<< orphan*/  MIPI_DCS_ENTER_NORMAL_MODE ; 
 int /*<<< orphan*/  MIPI_DCS_EXIT_SLEEP_MODE ; 
 int /*<<< orphan*/  MIPI_DCS_PIXEL_FMT_16BIT ; 
 int /*<<< orphan*/  MIPI_DCS_SET_ADDRESS_MODE ; 
 int /*<<< orphan*/  MIPI_DCS_SET_COLUMN_ADDRESS ; 
 int /*<<< orphan*/  MIPI_DCS_SET_DISPLAY_ON ; 
 int /*<<< orphan*/  MIPI_DCS_SET_GAMMA_CURVE ; 
 int /*<<< orphan*/  MIPI_DCS_SET_PAGE_ADDRESS ; 
 int /*<<< orphan*/  MIPI_DCS_SET_PIXEL_FORMAT ; 
 int /*<<< orphan*/  MIPI_DCS_SOFT_RESET ; 
 int /*<<< orphan*/  MIPI_DCS_WRITE_MEMORY_START ; 
 int /*<<< orphan*/  WIDTH ; 
 int /*<<< orphan*/  __OFFSET ; 
 int /*<<< orphan*/  gpio_set_value (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  stub1 (struct fbtft_par*) ; 
 int /*<<< orphan*/  write_reg (struct fbtft_par*,int /*<<< orphan*/ ,...) ; 

__attribute__((used)) static int init_display(struct fbtft_par *par)
{
	par->fbtftops.reset(par);

	if (par->gpio.cs != -1)
		gpio_set_value(par->gpio.cs, 0);  /* Activate chip */

	write_reg(par, MIPI_DCS_SOFT_RESET); /* software reset */
	mdelay(500);
	write_reg(par, MIPI_DCS_EXIT_SLEEP_MODE); /* exit sleep */
	mdelay(5);
	write_reg(par, MIPI_DCS_SET_PIXEL_FORMAT, MIPI_DCS_PIXEL_FMT_16BIT);
	/* default gamma curve 3 */
	write_reg(par, MIPI_DCS_SET_GAMMA_CURVE, 0x02);
#ifdef GAMMA_ADJ
	write_reg(par, CMD_GAMRSEL, 0x01); /* Enable Gamma adj */
#endif
	write_reg(par, MIPI_DCS_ENTER_NORMAL_MODE);
	write_reg(par, CMD_DFUNCTR, 0xff, 0x06);
	/* Frame Rate Control (In normal mode/Full colors) */
	write_reg(par, CMD_FRMCTR1, 0x08, 0x02);
	write_reg(par, CMD_DINVCTR, 0x07); /* display inversion  */
	/* Set VRH1[4:0] & VC[2:0] for VCI1 & GVDD */
	write_reg(par, CMD_PWCTR1, 0x0A, 0x02);
	/* Set BT[2:0] for AVDD & VCL & VGH & VGL  */
	write_reg(par, CMD_PWCTR2, 0x02);
	/* Set VMH[6:0] & VML[6:0] for VOMH & VCOML */
	write_reg(par, CMD_VCOMCTR1, 0x50, 0x63);
	write_reg(par, CMD_VCOMOFFS, 0);

	write_reg(par, MIPI_DCS_SET_COLUMN_ADDRESS, 0, 0, 0, WIDTH);
	write_reg(par, MIPI_DCS_SET_PAGE_ADDRESS, 0, 0, 0, HEIGHT);

	write_reg(par, MIPI_DCS_SET_DISPLAY_ON); /* display ON */
	write_reg(par, MIPI_DCS_WRITE_MEMORY_START); /* Memory Write */

	return 0;
}

__attribute__((used)) static void set_addr_win(struct fbtft_par *par, int xs, int ys,
			 int xe, int ye)
{
	switch (par->info->var.rotate) {
	case 0:
		write_reg(par, MIPI_DCS_SET_COLUMN_ADDRESS,
			  xs >> 8, xs & 0xff, xe >> 8, xe & 0xff);
		write_reg(par, MIPI_DCS_SET_PAGE_ADDRESS,
			  (ys + __OFFSET) >> 8, (ys + __OFFSET) & 0xff,
			  (ye + __OFFSET) >> 8, (ye + __OFFSET) & 0xff);
		break;
	case 90:
		write_reg(par, MIPI_DCS_SET_COLUMN_ADDRESS,
			  (xs + __OFFSET) >> 8, (xs + __OFFSET) & 0xff,
			  (xe + __OFFSET) >> 8, (xe + __OFFSET) & 0xff);
		write_reg(par, MIPI_DCS_SET_PAGE_ADDRESS,
			  ys >> 8, ys & 0xff, ye >> 8, ye & 0xff);
		break;
	case 180:
	case 270:
		write_reg(par, MIPI_DCS_SET_COLUMN_ADDRESS,
			  xs >> 8, xs & 0xff, xe >> 8, xe & 0xff);
		write_reg(par, MIPI_DCS_SET_PAGE_ADDRESS,
			  ys >> 8, ys & 0xff, ye >> 8, ye & 0xff);
		break;
	default:
		/* Fix incorrect setting */
		par->info->var.rotate = 0;
	}
	write_reg(par, MIPI_DCS_WRITE_MEMORY_START);
}

__attribute__((used)) static int set_var(struct fbtft_par *par)
{
	u8 mactrl_data = 0; /* Avoid compiler warning */

	switch (par->info->var.rotate) {
	case 0:
		mactrl_data = 0x08;
		break;
	case 180:
		mactrl_data = 0xC8;
		break;
	case 270:
		mactrl_data = 0xA8;
		break;
	case 90:
		mactrl_data = 0x68;
		break;
	}

	/* Colorspcae */
	if (par->bgr)
		mactrl_data |= BIT(2);
	write_reg(par, MIPI_DCS_SET_ADDRESS_MODE, mactrl_data);
	write_reg(par, MIPI_DCS_WRITE_MEMORY_START);
	return 0;
}

