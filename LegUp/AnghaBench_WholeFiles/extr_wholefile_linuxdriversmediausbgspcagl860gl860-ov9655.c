#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  char u8 ;
struct TYPE_10__ {int brightness; int hue; } ;
struct TYPE_9__ {int brightness; scalar_t__ AC50Hz; scalar_t__ flip; scalar_t__ mirror; scalar_t__ whitebal; scalar_t__ saturation; scalar_t__ hue; scalar_t__ gamma; scalar_t__ contrast; scalar_t__ sharpness; scalar_t__ backlight; } ;
struct TYPE_8__ {int brightness; size_t hue; scalar_t__ whitebal; scalar_t__ saturation; scalar_t__ gamma; scalar_t__ contrast; scalar_t__ sharpness; scalar_t__ backlight; } ;
struct sd {int (* dev_camera_settings ) (struct gspca_dev*) ;int (* dev_init_at_startup ) (struct gspca_dev*) ;int (* dev_configure_alt ) (struct gspca_dev*) ;int (* dev_init_pre_alt ) (struct gspca_dev*) ;void (* dev_post_unset_alt ) (struct gspca_dev*) ;int swapRB; TYPE_5__ vold; TYPE_4__ vmax; TYPE_3__ vcur; } ;
struct TYPE_7__ {TYPE_1__* cam_mode; } ;
struct gspca_dev {int alt; scalar_t__ curr_mode; TYPE_2__ cam; } ;
typedef  size_t s32 ;
struct TYPE_6__ {size_t priv; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
#define  IMAGE_640 128 
 int /*<<< orphan*/  c04 ; 
 int /*<<< orphan*/  ctrl_in (struct gspca_dev*,int,int,int,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ctrl_out (struct gspca_dev*,int,int,int,int,int,char*) ; 
 char* dat_post1 ; 
 char* dat_post2 ; 
 char* dat_post3 ; 
 char* dat_post4 ; 
 char* dat_post5 ; 
 char* dat_post6 ; 
 char* dat_post7 ; 
 char* dat_post8 ; 
 size_t fetch_validx (struct gspca_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  keep_on_fetching_validx (struct gspca_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,size_t) ; 
static  int ov9655_camera_settings (struct gspca_dev*) ; 
static  int ov9655_configure_alt (struct gspca_dev*) ; 
static  int ov9655_init_at_startup (struct gspca_dev*) ; 
static  int ov9655_init_post_alt (struct gspca_dev*) ; 
static  int ov9655_init_pre_alt (struct gspca_dev*) ; 
static  void ov9655_post_unset_alt (struct gspca_dev*) ; 
 char** tbl_1280 ; 
 char** tbl_640 ; 
 int /*<<< orphan*/  tbl_commmon ; 
 int /*<<< orphan*/  tbl_init_at_startup ; 
 int /*<<< orphan*/  tbl_init_post_alt ; 
 int* tbl_length ; 

void ov9655_init_settings(struct gspca_dev *gspca_dev)
{
	struct sd *sd = (struct sd *) gspca_dev;

	sd->vcur.backlight  =   0;
	sd->vcur.brightness = 128;
	sd->vcur.sharpness  =   0;
	sd->vcur.contrast   =   0;
	sd->vcur.gamma      =   0;
	sd->vcur.hue        =   0;
	sd->vcur.saturation =   0;
	sd->vcur.whitebal   =   0;

	sd->vmax.backlight  =   0;
	sd->vmax.brightness = 255;
	sd->vmax.sharpness  =   0;
	sd->vmax.contrast   =   0;
	sd->vmax.gamma      =   0;
	sd->vmax.hue        =   0 + 1;
	sd->vmax.saturation =   0;
	sd->vmax.whitebal   =   0;
	sd->vmax.mirror     = 0;
	sd->vmax.flip       = 0;
	sd->vmax.AC50Hz     = 0;

	sd->dev_camera_settings = ov9655_camera_settings;
	sd->dev_init_at_startup = ov9655_init_at_startup;
	sd->dev_configure_alt   = ov9655_configure_alt;
	sd->dev_init_pre_alt    = ov9655_init_pre_alt;
	sd->dev_post_unset_alt  = ov9655_post_unset_alt;
}

__attribute__((used)) static int ov9655_init_at_startup(struct gspca_dev *gspca_dev)
{
	fetch_validx(gspca_dev, tbl_init_at_startup,
			ARRAY_SIZE(tbl_init_at_startup));
	fetch_validx(gspca_dev, tbl_commmon, ARRAY_SIZE(tbl_commmon));
/*	ctrl_out(gspca_dev, 0x40, 11, 0x0000, 0x0000, 0, NULL);*/

	return 0;
}

__attribute__((used)) static int ov9655_init_pre_alt(struct gspca_dev *gspca_dev)
{
	struct sd *sd = (struct sd *) gspca_dev;

	sd->vold.brightness = -1;
	sd->vold.hue = -1;

	fetch_validx(gspca_dev, tbl_commmon, ARRAY_SIZE(tbl_commmon));

	ov9655_init_post_alt(gspca_dev);

	return 0;
}

__attribute__((used)) static int ov9655_init_post_alt(struct gspca_dev *gspca_dev)
{
	s32 reso = gspca_dev->cam.cam_mode[(s32) gspca_dev->curr_mode].priv;
	s32 n; /* reserved for FETCH functions */
	s32 i;
	u8 **tbl;

	ctrl_out(gspca_dev, 0x40, 5, 0x0001, 0x0000, 0, NULL);

	tbl = (reso == IMAGE_640) ? tbl_640 : tbl_1280;

	ctrl_out(gspca_dev, 0x40, 3, 0x0000, 0x0200,
			tbl_length[0], tbl[0]);
	for (i = 1; i < 7; i++)
		ctrl_out(gspca_dev, 0x40, 3, 0x6000, 0x0200,
				tbl_length[i], tbl[i]);
	ctrl_out(gspca_dev, 0x40, 3, 0x0000, 0x0200,
			tbl_length[7], tbl[7]);

	n = fetch_validx(gspca_dev, tbl_init_post_alt,
			ARRAY_SIZE(tbl_init_post_alt));

	ctrl_in(gspca_dev, 0xc0, 2, 0x6000, 0x801e, 1, c04);
	keep_on_fetching_validx(gspca_dev, tbl_init_post_alt,
					ARRAY_SIZE(tbl_init_post_alt), n);
	ctrl_in(gspca_dev, 0xc0, 2, 0x6000, 0x801e, 1, c04);
	keep_on_fetching_validx(gspca_dev, tbl_init_post_alt,
					ARRAY_SIZE(tbl_init_post_alt), n);
	ctrl_in(gspca_dev, 0xc0, 2, 0x6000, 0x801e, 1, c04);
	keep_on_fetching_validx(gspca_dev, tbl_init_post_alt,
					ARRAY_SIZE(tbl_init_post_alt), n);
	ctrl_in(gspca_dev, 0xc0, 2, 0x6000, 0x801e, 1, c04);
	keep_on_fetching_validx(gspca_dev, tbl_init_post_alt,
					ARRAY_SIZE(tbl_init_post_alt), n);
	ctrl_out(gspca_dev, 0x40, 3, 0x6000, 0x0200, 8, dat_post1);
	keep_on_fetching_validx(gspca_dev, tbl_init_post_alt,
					ARRAY_SIZE(tbl_init_post_alt), n);

	ctrl_in(gspca_dev, 0xc0, 2, 0x6000, 0x801e, 1, c04);
	keep_on_fetching_validx(gspca_dev, tbl_init_post_alt,
					ARRAY_SIZE(tbl_init_post_alt), n);
	ctrl_in(gspca_dev, 0xc0, 2, 0x6000, 0x801e, 1, c04);
	keep_on_fetching_validx(gspca_dev, tbl_init_post_alt,
					ARRAY_SIZE(tbl_init_post_alt), n);
	ctrl_in(gspca_dev, 0xc0, 2, 0x6000, 0x801e, 1, c04);
	keep_on_fetching_validx(gspca_dev, tbl_init_post_alt,
					ARRAY_SIZE(tbl_init_post_alt), n);
	ctrl_in(gspca_dev, 0xc0, 2, 0x6000, 0x801e, 1, c04);
	keep_on_fetching_validx(gspca_dev, tbl_init_post_alt,
					ARRAY_SIZE(tbl_init_post_alt), n);
	ctrl_out(gspca_dev, 0x40, 3, 0x6000, 0x0200, 8, dat_post1);
	keep_on_fetching_validx(gspca_dev, tbl_init_post_alt,
					ARRAY_SIZE(tbl_init_post_alt), n);

	ctrl_in(gspca_dev, 0xc0, 2, 0x6000, 0x801e, 1, c04);
	keep_on_fetching_validx(gspca_dev, tbl_init_post_alt,
					ARRAY_SIZE(tbl_init_post_alt), n);
	ctrl_in(gspca_dev, 0xc0, 2, 0x6000, 0x801e, 1, c04);
	keep_on_fetching_validx(gspca_dev, tbl_init_post_alt,
					ARRAY_SIZE(tbl_init_post_alt), n);

	ctrl_out(gspca_dev, 0x40, 3, 0x6000, 0x0200, 8, dat_post1);

	ctrl_out(gspca_dev, 0x40, 3, 0x0000, 0x0200, 4, dat_post2);
	ctrl_out(gspca_dev, 0x40, 3, 0x6000, 0x0200, 8, dat_post3);

	ctrl_out(gspca_dev, 0x40, 3, 0x0000, 0x0200, 4, dat_post4);
	ctrl_out(gspca_dev, 0x40, 3, 0x6000, 0x0200, 8, dat_post5);

	ctrl_out(gspca_dev, 0x40, 3, 0x0000, 0x0200, 4, dat_post6);
	ctrl_out(gspca_dev, 0x40, 3, 0x6000, 0x0200, 8, dat_post7);

	ctrl_out(gspca_dev, 0x40, 3, 0x6000, 0x0200, 8, dat_post8);

	ov9655_camera_settings(gspca_dev);

	return 0;
}

__attribute__((used)) static int ov9655_configure_alt(struct gspca_dev *gspca_dev)
{
	s32 reso = gspca_dev->cam.cam_mode[(s32) gspca_dev->curr_mode].priv;

	switch (reso) {
	case IMAGE_640:
		gspca_dev->alt = 1 + 1;
		break;

	default:
		gspca_dev->alt = 1 + 1;
		break;
	}
	return 0;
}

__attribute__((used)) static int ov9655_camera_settings(struct gspca_dev *gspca_dev)
{
	struct sd *sd = (struct sd *) gspca_dev;

	u8 dat_bright[] = "\x04\x00\x10\x7c\xa1\x00\x00\x70";

	s32 bright = sd->vcur.brightness;
	s32 hue    = sd->vcur.hue;

	if (bright != sd->vold.brightness) {
		sd->vold.brightness = bright;
		if (bright < 0 || bright > sd->vmax.brightness)
			bright = 0;

		dat_bright[3] = bright;
		ctrl_out(gspca_dev, 0x40, 3, 0x6000, 0x0200, 8, dat_bright);
	}

	if (hue != sd->vold.hue) {
		sd->vold.hue = hue;
		sd->swapRB = (hue != 0);
	}

	return 0;
}

__attribute__((used)) static void ov9655_post_unset_alt(struct gspca_dev *gspca_dev)
{
	ctrl_out(gspca_dev, 0x40, 5, 0x0000, 0x0000, 0, NULL);
	ctrl_out(gspca_dev, 0x40, 1, 0x0061, 0x0000, 0, NULL);
}

