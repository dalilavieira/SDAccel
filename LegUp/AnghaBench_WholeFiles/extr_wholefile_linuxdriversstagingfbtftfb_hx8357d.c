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
typedef  int u8 ;
struct TYPE_4__ {int /*<<< orphan*/  (* reset ) (struct fbtft_par*) ;} ;
struct fbtft_par {scalar_t__ bgr; TYPE_3__* info; TYPE_1__ fbtftops; } ;
struct TYPE_5__ {int rotate; } ;
struct TYPE_6__ {TYPE_2__ var; } ;

/* Variables and functions */
 int HX8357D_MADCTL_BGR ; 
 int HX8357D_MADCTL_MV ; 
 int HX8357D_MADCTL_MX ; 
 int HX8357D_MADCTL_MY ; 
 int HX8357D_MADCTL_RGB ; 
 int /*<<< orphan*/  HX8357D_SETC ; 
 int /*<<< orphan*/  HX8357D_SETCOM ; 
 int /*<<< orphan*/  HX8357D_SETCYC ; 
 int /*<<< orphan*/  HX8357D_SETGAMMA ; 
 int /*<<< orphan*/  HX8357D_SETSTBA ; 
 int /*<<< orphan*/  HX8357_SETOSC ; 
 int /*<<< orphan*/  HX8357_SETPANEL ; 
 int /*<<< orphan*/  HX8357_SETPWR1 ; 
 int /*<<< orphan*/  HX8357_SETRGB ; 
 int /*<<< orphan*/  MIPI_DCS_EXIT_SLEEP_MODE ; 
 int /*<<< orphan*/  MIPI_DCS_SET_ADDRESS_MODE ; 
 int /*<<< orphan*/  MIPI_DCS_SET_COLUMN_ADDRESS ; 
 int /*<<< orphan*/  MIPI_DCS_SET_DISPLAY_ON ; 
 int /*<<< orphan*/  MIPI_DCS_SET_PAGE_ADDRESS ; 
 int /*<<< orphan*/  MIPI_DCS_SET_PIXEL_FORMAT ; 
 int /*<<< orphan*/  MIPI_DCS_SET_TEAR_ON ; 
 int /*<<< orphan*/  MIPI_DCS_SET_TEAR_SCANLINE ; 
 int /*<<< orphan*/  MIPI_DCS_SOFT_RESET ; 
 int /*<<< orphan*/  MIPI_DCS_WRITE_MEMORY_START ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  stub1 (struct fbtft_par*) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 
 int /*<<< orphan*/  write_reg (struct fbtft_par*,int /*<<< orphan*/ ,...) ; 

__attribute__((used)) static int init_display(struct fbtft_par *par)
{
	par->fbtftops.reset(par);

	/* Reset things like Gamma */
	write_reg(par, MIPI_DCS_SOFT_RESET);
	usleep_range(5000, 7000);

	/* setextc */
	write_reg(par, HX8357D_SETC, 0xFF, 0x83, 0x57);
	msleep(150);

	/* setRGB which also enables SDO */
	write_reg(par, HX8357_SETRGB, 0x00, 0x00, 0x06, 0x06);

	/* -1.52V */
	write_reg(par, HX8357D_SETCOM, 0x25);

	/* Normal mode 70Hz, Idle mode 55 Hz */
	write_reg(par, HX8357_SETOSC, 0x68);

	/* Set Panel - BGR, Gate direction swapped */
	write_reg(par, HX8357_SETPANEL, 0x05);

	write_reg(par, HX8357_SETPWR1,
		  0x00,  /* Not deep standby */
		  0x15,  /* BT */
		  0x1C,  /* VSPR */
		  0x1C,  /* VSNR */
		  0x83,  /* AP */
		  0xAA);  /* FS */

	write_reg(par, HX8357D_SETSTBA,
		  0x50,  /* OPON normal */
		  0x50,  /* OPON idle */
		  0x01,  /* STBA */
		  0x3C,  /* STBA */
		  0x1E,  /* STBA */
		  0x08);  /* GEN */

	write_reg(par, HX8357D_SETCYC,
		  0x02,  /* NW 0x02 */
		  0x40,  /* RTN */
		  0x00,  /* DIV */
		  0x2A,  /* DUM */
		  0x2A,  /* DUM */
		  0x0D,  /* GDON */
		  0x78);  /* GDOFF */

	write_reg(par, HX8357D_SETGAMMA,
		  0x02,
		  0x0A,
		  0x11,
		  0x1d,
		  0x23,
		  0x35,
		  0x41,
		  0x4b,
		  0x4b,
		  0x42,
		  0x3A,
		  0x27,
		  0x1B,
		  0x08,
		  0x09,
		  0x03,
		  0x02,
		  0x0A,
		  0x11,
		  0x1d,
		  0x23,
		  0x35,
		  0x41,
		  0x4b,
		  0x4b,
		  0x42,
		  0x3A,
		  0x27,
		  0x1B,
		  0x08,
		  0x09,
		  0x03,
		  0x00,
		  0x01);

	/* 16 bit */
	write_reg(par, MIPI_DCS_SET_PIXEL_FORMAT, 0x55);

	write_reg(par, MIPI_DCS_SET_ADDRESS_MODE, 0xC0);

	/* TE off */
	write_reg(par, MIPI_DCS_SET_TEAR_ON, 0x00);

	/* tear line */
	write_reg(par, MIPI_DCS_SET_TEAR_SCANLINE, 0x00, 0x02);

	/* Exit Sleep */
	write_reg(par, MIPI_DCS_EXIT_SLEEP_MODE);
	msleep(150);

	/* display on */
	write_reg(par, MIPI_DCS_SET_DISPLAY_ON);
	usleep_range(5000, 7000);

	return 0;
}

__attribute__((used)) static void set_addr_win(struct fbtft_par *par, int xs, int ys, int xe, int ye)
{
	write_reg(par, MIPI_DCS_SET_COLUMN_ADDRESS,
		  xs >> 8, xs & 0xff,  /* XSTART */
		  xe >> 8, xe & 0xff); /* XEND */

	write_reg(par, MIPI_DCS_SET_PAGE_ADDRESS,
		  ys >> 8, ys & 0xff,  /* YSTART */
		  ye >> 8, ye & 0xff); /* YEND */

	write_reg(par, MIPI_DCS_WRITE_MEMORY_START);
}

__attribute__((used)) static int set_var(struct fbtft_par *par)
{
	u8 val;

	switch (par->info->var.rotate) {
	case 270:
		val = HX8357D_MADCTL_MV | HX8357D_MADCTL_MX;
		break;
	case 180:
		val = 0;
		break;
	case 90:
		val = HX8357D_MADCTL_MV | HX8357D_MADCTL_MY;
		break;
	default:
		val = HX8357D_MADCTL_MX | HX8357D_MADCTL_MY;
		break;
	}

	val |= (par->bgr ? HX8357D_MADCTL_RGB : HX8357D_MADCTL_BGR);

	/* Memory Access Control */
	write_reg(par, MIPI_DCS_SET_ADDRESS_MODE, val);

	return 0;
}

