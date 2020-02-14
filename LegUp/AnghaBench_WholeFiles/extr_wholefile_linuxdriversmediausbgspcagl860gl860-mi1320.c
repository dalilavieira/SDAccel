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
typedef  int u8 ;
struct TYPE_10__ {int backlight; int brightness; int sharpness; size_t contrast; int gamma; int hue; int saturation; int whitebal; int mirror; int flip; int AC50Hz; } ;
struct TYPE_9__ {int backlight; int brightness; int sharpness; int contrast; int saturation; int gamma; int hue; int whitebal; int mirror; int flip; int AC50Hz; } ;
struct TYPE_8__ {size_t backlight; size_t brightness; int sharpness; int contrast; int gamma; size_t hue; int saturation; size_t whitebal; scalar_t__ mirror; scalar_t__ flip; int AC50Hz; } ;
struct sd {int (* dev_camera_settings ) (struct gspca_dev*) ;int (* dev_init_at_startup ) (struct gspca_dev*) ;int (* dev_configure_alt ) (struct gspca_dev*) ;int (* dev_init_pre_alt ) (struct gspca_dev*) ;void (* dev_post_unset_alt ) (struct gspca_dev*) ;int mirrorMask; int swapRB; TYPE_5__ vmax; TYPE_4__ vold; TYPE_3__ vcur; } ;
struct TYPE_7__ {TYPE_1__* cam_mode; } ;
struct gspca_dev {int alt; scalar_t__ curr_mode; TYPE_2__ cam; } ;
typedef  size_t s32 ;
struct TYPE_6__ {size_t priv; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
#define  IMAGE_1280 130 
#define  IMAGE_640 129 
#define  IMAGE_800 128 
 int /*<<< orphan*/  ctrl_out (struct gspca_dev*,int,int,int,int,int,int*) ; 
 int* dat_common00 ; 
 int* dat_common01 ; 
 int* dat_common02 ; 
 int* dat_common03 ; 
 int* dat_common04 ; 
 int* dat_common05 ; 
 int* dat_common06 ; 
 int* dat_common07 ; 
 int* dat_common08 ; 
 int* dat_common09 ; 
 int* dat_common10 ; 
 int* dat_common11 ; 
 int* dat_hvflip1 ; 
 int* dat_wbalBL ; 
 int* dat_wbalLL ; 
 int* dat_wbalNL ; 
 size_t fetch_validx (struct gspca_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  keep_on_fetching_validx (struct gspca_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,size_t) ; 
static  int mi1320_camera_settings (struct gspca_dev*) ; 
static  int mi1320_configure_alt (struct gspca_dev*) ; 
static  int mi1320_init_at_startup (struct gspca_dev*) ; 
static  int mi1320_init_post_alt (struct gspca_dev*) ; 
static  int mi1320_init_pre_alt (struct gspca_dev*) ; 
static  void mi1320_post_unset_alt (struct gspca_dev*) ; 
static  int mi1320_sensor_settings (struct gspca_dev*) ; 
 int** tbl_1280 ; 
 int** tbl_640 ; 
 int** tbl_800 ; 
 size_t* tbl_backlight ; 
 size_t* tbl_bright ; 
 int* tbl_cntr1 ; 
 int* tbl_cntr2 ; 
 int /*<<< orphan*/  tbl_common ; 
 int /*<<< orphan*/  tbl_init_at_startup ; 
 int /*<<< orphan*/  tbl_post_unset_alt ; 
 size_t* tbl_sat ; 
 int /*<<< orphan*/  tbl_sensor_settings_1280 ; 
 int /*<<< orphan*/  tbl_sensor_settings_640 ; 
 int /*<<< orphan*/  tbl_sensor_settings_800 ; 
 int /*<<< orphan*/  tbl_sensor_settings_common ; 

void mi1320_init_settings(struct gspca_dev *gspca_dev)
{
	struct sd *sd = (struct sd *) gspca_dev;

	sd->vcur.backlight  =  0;
	sd->vcur.brightness =  0;
	sd->vcur.sharpness  =  6;
	sd->vcur.contrast   = 10;
	sd->vcur.gamma      = 20;
	sd->vcur.hue        =  0;
	sd->vcur.saturation =  6;
	sd->vcur.whitebal   =  0;
	sd->vcur.mirror     = 0;
	sd->vcur.flip       = 0;
	sd->vcur.AC50Hz     = 1;

	sd->vmax.backlight  =  2;
	sd->vmax.brightness =  8;
	sd->vmax.sharpness  =  7;
	sd->vmax.contrast   =  0; /* 10 but not working with this driver */
	sd->vmax.gamma      = 40;
	sd->vmax.hue        =  5 + 1;
	sd->vmax.saturation =  8;
	sd->vmax.whitebal   =  2;
	sd->vmax.mirror     = 1;
	sd->vmax.flip       = 1;
	sd->vmax.AC50Hz     = 1;

	sd->dev_camera_settings = mi1320_camera_settings;
	sd->dev_init_at_startup = mi1320_init_at_startup;
	sd->dev_configure_alt   = mi1320_configure_alt;
	sd->dev_init_pre_alt    = mi1320_init_pre_alt;
	sd->dev_post_unset_alt  = mi1320_post_unset_alt;
}

__attribute__((used)) static void common(struct gspca_dev *gspca_dev)
{
	s32 n; /* reserved for FETCH functions */

	ctrl_out(gspca_dev, 0x40, 3, 0x0000, 0x0200, 22, dat_common00);
	ctrl_out(gspca_dev, 0x40, 1, 0x0041, 0x0000, 0, NULL);
	ctrl_out(gspca_dev, 0x40, 3, 0xba00, 0x0200, 32, dat_common01);
	n = fetch_validx(gspca_dev, tbl_common, ARRAY_SIZE(tbl_common));
	ctrl_out(gspca_dev, 0x40, 3, 0xba00, 0x0200, 48, dat_common02);
	ctrl_out(gspca_dev, 0x40, 3, 0xba00, 0x0200, 48, dat_common03);
	ctrl_out(gspca_dev, 0x40, 3, 0xba00, 0x0200, 16, dat_common04);
	ctrl_out(gspca_dev, 0x40, 3, 0xba00, 0x0200, 48, dat_common05);
	ctrl_out(gspca_dev, 0x40, 3, 0xba00, 0x0200, 44, dat_common06);
	keep_on_fetching_validx(gspca_dev, tbl_common,
					ARRAY_SIZE(tbl_common), n);
	ctrl_out(gspca_dev, 0x40, 3, 0xba00, 0x0200, 52, dat_common07);
	ctrl_out(gspca_dev, 0x40, 3, 0xba00, 0x0200, 48, dat_common08);
	ctrl_out(gspca_dev, 0x40, 3, 0xba00, 0x0200, 48, dat_common09);
	ctrl_out(gspca_dev, 0x40, 3, 0xba00, 0x0200, 56, dat_common10);
	keep_on_fetching_validx(gspca_dev, tbl_common,
					ARRAY_SIZE(tbl_common), n);
	ctrl_out(gspca_dev, 0x40, 3, 0xba00, 0x0200, 40, dat_common11);
	keep_on_fetching_validx(gspca_dev, tbl_common,
					ARRAY_SIZE(tbl_common), n);
}

__attribute__((used)) static int mi1320_init_at_startup(struct gspca_dev *gspca_dev)
{
	fetch_validx(gspca_dev, tbl_init_at_startup,
				ARRAY_SIZE(tbl_init_at_startup));

	common(gspca_dev);

/*	ctrl_out(gspca_dev, 0x40, 11, 0x0000, 0x0000, 0, NULL); */

	return 0;
}

__attribute__((used)) static int mi1320_init_pre_alt(struct gspca_dev *gspca_dev)
{
	struct sd *sd = (struct sd *) gspca_dev;

	sd->mirrorMask = 0;

	sd->vold.backlight  = -1;
	sd->vold.brightness = -1;
	sd->vold.sharpness  = -1;
	sd->vold.contrast   = -1;
	sd->vold.saturation = -1;
	sd->vold.gamma    = -1;
	sd->vold.hue      = -1;
	sd->vold.whitebal = -1;
	sd->vold.mirror   = -1;
	sd->vold.flip     = -1;
	sd->vold.AC50Hz   = -1;

	common(gspca_dev);

	mi1320_sensor_settings(gspca_dev);

	mi1320_init_post_alt(gspca_dev);

	return 0;
}

__attribute__((used)) static int mi1320_init_post_alt(struct gspca_dev *gspca_dev)
{
	mi1320_camera_settings(gspca_dev);

	return 0;
}

__attribute__((used)) static int mi1320_sensor_settings(struct gspca_dev *gspca_dev)
{
	s32 reso = gspca_dev->cam.cam_mode[(s32) gspca_dev->curr_mode].priv;

	ctrl_out(gspca_dev, 0x40, 5, 0x0001, 0x0000, 0, NULL);

	fetch_validx(gspca_dev, tbl_sensor_settings_common,
				ARRAY_SIZE(tbl_sensor_settings_common));

	switch (reso) {
	case IMAGE_1280:
		fetch_validx(gspca_dev, tbl_sensor_settings_1280,
					ARRAY_SIZE(tbl_sensor_settings_1280));
		ctrl_out(gspca_dev, 0x40, 3, 0xba00, 0x0200, 64, tbl_1280[0]);
		ctrl_out(gspca_dev, 0x40, 3, 0xba00, 0x0200, 40, tbl_1280[1]);
		ctrl_out(gspca_dev, 0x40, 3, 0x0000, 0x0200, 12, tbl_1280[2]);
		break;

	case IMAGE_800:
		fetch_validx(gspca_dev, tbl_sensor_settings_800,
					ARRAY_SIZE(tbl_sensor_settings_800));
		ctrl_out(gspca_dev, 0x40, 3, 0xba00, 0x0200, 64, tbl_800[0]);
		ctrl_out(gspca_dev, 0x40, 3, 0xba00, 0x0200, 40, tbl_800[1]);
		ctrl_out(gspca_dev, 0x40, 3, 0x0000, 0x0200, 12, tbl_800[2]);
		break;

	default:
		fetch_validx(gspca_dev, tbl_sensor_settings_640,
					ARRAY_SIZE(tbl_sensor_settings_640));
		ctrl_out(gspca_dev, 0x40, 3, 0xba00, 0x0200, 60, tbl_640[0]);
		ctrl_out(gspca_dev, 0x40, 3, 0xba00, 0x0200, 40, tbl_640[1]);
		ctrl_out(gspca_dev, 0x40, 3, 0x0000, 0x0200, 12, tbl_640[2]);
		break;
	}
	return 0;
}

__attribute__((used)) static int mi1320_configure_alt(struct gspca_dev *gspca_dev)
{
	s32 reso = gspca_dev->cam.cam_mode[(s32) gspca_dev->curr_mode].priv;

	switch (reso) {
	case IMAGE_640:
		gspca_dev->alt = 3 + 1;
		break;

	case IMAGE_800:
	case IMAGE_1280:
		gspca_dev->alt = 1 + 1;
		break;
	}
	return 0;
}

__attribute__((used)) static int mi1320_camera_settings(struct gspca_dev *gspca_dev)
{
	struct sd *sd = (struct sd *) gspca_dev;

	s32 backlight = sd->vcur.backlight;
	s32 bright = sd->vcur.brightness;
	s32 sharp  = sd->vcur.sharpness;
	s32 cntr   = sd->vcur.contrast;
	s32 gam	   = sd->vcur.gamma;
	s32 hue    = sd->vcur.hue;
	s32 sat	   = sd->vcur.saturation;
	s32 wbal   = sd->vcur.whitebal;
	s32 mirror = (((sd->vcur.mirror > 0) ^ sd->mirrorMask) > 0);
	s32 flip   = (((sd->vcur.flip   > 0) ^ sd->mirrorMask) > 0);
	s32 freq   = (sd->vcur.AC50Hz > 0);
	s32 i;

	if (freq != sd->vold.AC50Hz) {
		sd->vold.AC50Hz = freq;

		freq = 2 * (freq == 0);
		ctrl_out(gspca_dev, 0x40, 1, 0xba00, 0x00f0, 0, NULL);
		ctrl_out(gspca_dev, 0x40, 1, 0xba02, 0x00f1, 0, NULL);
		ctrl_out(gspca_dev, 0x40, 1, 0xba00       , 0x005b, 0, NULL);
		ctrl_out(gspca_dev, 0x40, 1, 0xba01 + freq, 0x00f1, 0, NULL);
	}

	if (wbal != sd->vold.whitebal) {
		sd->vold.whitebal = wbal;
		if (wbal < 0 || wbal > sd->vmax.whitebal)
			wbal = 0;

		for (i = 0; i < 2; i++) {
			if (wbal == 0) { /* Normal light */
				ctrl_out(gspca_dev, 0x40, 1,
						0x0010, 0x0010, 0, NULL);
				ctrl_out(gspca_dev, 0x40, 1,
						0x0003, 0x00c1, 0, NULL);
				ctrl_out(gspca_dev, 0x40, 1,
						0x0042, 0x00c2, 0, NULL);
				ctrl_out(gspca_dev, 0x40, 3,
						0xba00, 0x0200, 48, dat_wbalNL);
			}

			if (wbal == 1) { /* Low light */
				ctrl_out(gspca_dev, 0x40, 1,
						0x0010, 0x0010, 0, NULL);
				ctrl_out(gspca_dev, 0x40, 1,
						0x0004, 0x00c1, 0, NULL);
				ctrl_out(gspca_dev, 0x40, 1,
						0x0043, 0x00c2, 0, NULL);
				ctrl_out(gspca_dev, 0x40, 3,
						0xba00, 0x0200, 48, dat_wbalLL);
			}

			if (wbal == 2) { /* Back light */
				ctrl_out(gspca_dev, 0x40, 1,
						0x0010, 0x0010, 0, NULL);
				ctrl_out(gspca_dev, 0x40, 1,
						0x0003, 0x00c1, 0, NULL);
				ctrl_out(gspca_dev, 0x40, 1,
						0x0042, 0x00c2, 0, NULL);
				ctrl_out(gspca_dev, 0x40, 3,
						0xba00, 0x0200, 44, dat_wbalBL);
			}
		}
	}

	if (bright != sd->vold.brightness) {
		sd->vold.brightness = bright;
		if (bright < 0 || bright > sd->vmax.brightness)
			bright = 0;

		bright = tbl_bright[bright];
		ctrl_out(gspca_dev, 0x40, 1, 0xba00, 0x00f0, 0, NULL);
		ctrl_out(gspca_dev, 0x40, 1, 0xba01, 0x00f1, 0, NULL);
		ctrl_out(gspca_dev, 0x40, 1, 0xba00 + bright, 0x0034, 0, NULL);
		ctrl_out(gspca_dev, 0x40, 1, 0xba00 + bright, 0x00f1, 0, NULL);
	}

	if (sat != sd->vold.saturation) {
		sd->vold.saturation = sat;
		if (sat < 0 || sat > sd->vmax.saturation)
			sat = 0;

		sat = tbl_sat[sat];
		ctrl_out(gspca_dev, 0x40, 1, 0xba00, 0x00f0, 0, NULL);
		ctrl_out(gspca_dev, 0x40, 1, 0xba01, 0x00f1, 0, NULL);
		ctrl_out(gspca_dev, 0x40, 1, 0xba00      , 0x0025, 0, NULL);
		ctrl_out(gspca_dev, 0x40, 1, 0xba00 + sat, 0x00f1, 0, NULL);
	}

	if (sharp != sd->vold.sharpness) {
		sd->vold.sharpness = sharp;
		if (sharp < 0 || sharp > sd->vmax.sharpness)
			sharp = 0;

		ctrl_out(gspca_dev, 0x40, 1, 0xba00, 0x00f0, 0, NULL);
		ctrl_out(gspca_dev, 0x40, 1, 0xba01, 0x00f1, 0, NULL);
		ctrl_out(gspca_dev, 0x40, 1, 0xba00        , 0x0005, 0, NULL);
		ctrl_out(gspca_dev, 0x40, 1, 0xba00 + sharp, 0x00f1, 0, NULL);
	}

	if (hue != sd->vold.hue) {
		/* 0=normal  1=NB  2="sepia"  3=negative  4=other  5=other2 */
		if (hue < 0 || hue > sd->vmax.hue)
			hue = 0;
		if (hue == sd->vmax.hue)
			sd->swapRB = 1;
		else
			sd->swapRB = 0;

		ctrl_out(gspca_dev, 0x40, 1, 0xba00, 0x00f0, 0, NULL);
		ctrl_out(gspca_dev, 0x40, 1, 0xba01, 0x00f1, 0, NULL);
		ctrl_out(gspca_dev, 0x40, 1, 0xba70, 0x00e2, 0, NULL);
		ctrl_out(gspca_dev, 0x40, 1, 0xba00 + hue * (hue < 6), 0x00f1,
							0, NULL);
	}

	if (backlight != sd->vold.backlight) {
		sd->vold.backlight = backlight;
		if (backlight < 0 || backlight > sd->vmax.backlight)
			backlight = 0;

		backlight = tbl_backlight[backlight];
		for (i = 0; i < 2; i++) {
			ctrl_out(gspca_dev, 0x40, 1, 0xba00, 0x00f0, 0, NULL);
			ctrl_out(gspca_dev, 0x40, 1, 0xba01, 0x00f1, 0, NULL);
			ctrl_out(gspca_dev, 0x40, 1, 0xba74, 0x0006, 0, NULL);
			ctrl_out(gspca_dev, 0x40, 1, 0xba80 + backlight, 0x00f1,
								0, NULL);
		}
	}

	if (hue != sd->vold.hue) {
		sd->vold.hue = hue;

		ctrl_out(gspca_dev, 0x40, 1, 0xba00, 0x00f0, 0, NULL);
		ctrl_out(gspca_dev, 0x40, 1, 0xba01, 0x00f1, 0, NULL);
		ctrl_out(gspca_dev, 0x40, 1, 0xba70, 0x00e2, 0, NULL);
		ctrl_out(gspca_dev, 0x40, 1, 0xba00 + hue * (hue < 6), 0x00f1,
							0, NULL);
	}

	if (mirror != sd->vold.mirror || flip != sd->vold.flip) {
		u8 dat_hvflip2[4] = {0x20, 0x01, 0xf1, 0x00};
		sd->vold.mirror = mirror;
		sd->vold.flip = flip;

		dat_hvflip2[3] = flip + 2 * mirror;
		ctrl_out(gspca_dev, 0x40, 3, 0xba00, 0x0200, 4, dat_hvflip1);
		ctrl_out(gspca_dev, 0x40, 3, 0xba00, 0x0200, 4, dat_hvflip2);
	}

	if (gam != sd->vold.gamma) {
		sd->vold.gamma = gam;
		if (gam < 0 || gam > sd->vmax.gamma)
			gam = 0;

		gam = 2 * gam;
		ctrl_out(gspca_dev, 0x40, 1, 0xba00, 0x00f0, 0, NULL);
		ctrl_out(gspca_dev, 0x40, 1, 0xba01, 0x00f1, 0, NULL);
		ctrl_out(gspca_dev, 0x40, 1, 0xba04      , 0x003b, 0, NULL);
		ctrl_out(gspca_dev, 0x40, 1, 0xba02 + gam, 0x00f1, 0, NULL);
	}

	if (cntr != sd->vold.contrast) {
		sd->vold.contrast = cntr;
		if (cntr < 0 || cntr > sd->vmax.contrast)
			cntr = 0;

		ctrl_out(gspca_dev, 0x40, 1, 0xba00, 0x00f0, 0, NULL);
		ctrl_out(gspca_dev, 0x40, 1, 0xba01, 0x00f1, 0, NULL);
		ctrl_out(gspca_dev, 0x40, 1, 0xba00 + tbl_cntr1[cntr], 0x0035,
							0, NULL);
		ctrl_out(gspca_dev, 0x40, 1, 0xba00 + tbl_cntr2[cntr], 0x00f1,
							0, NULL);
	}

	return 0;
}

__attribute__((used)) static void mi1320_post_unset_alt(struct gspca_dev *gspca_dev)
{
	ctrl_out(gspca_dev, 0x40, 5, 0x0000, 0x0000, 0, NULL);

	fetch_validx(gspca_dev, tbl_post_unset_alt,
				ARRAY_SIZE(tbl_post_unset_alt));
}

