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
struct TYPE_10__ {int backlight; int brightness; int sharpness; int contrast; int saturation; int gamma; int hue; int whitebal; int mirror; int flip; } ;
struct TYPE_9__ {int backlight; int brightness; int sharpness; int contrast; int gamma; int hue; int saturation; int whitebal; int mirror; int flip; scalar_t__ AC50Hz; } ;
struct TYPE_8__ {int backlight; size_t brightness; int sharpness; size_t contrast; int gamma; size_t hue; int saturation; int whitebal; scalar_t__ mirror; scalar_t__ flip; } ;
struct sd {int (* dev_camera_settings ) (struct gspca_dev*) ;int (* dev_init_at_startup ) (struct gspca_dev*) ;int (* dev_configure_alt ) (struct gspca_dev*) ;int (* dev_init_pre_alt ) (struct gspca_dev*) ;void (* dev_post_unset_alt ) (struct gspca_dev*) ;int mirrorMask; int swapRB; TYPE_5__ vold; TYPE_4__ vmax; TYPE_3__ vcur; } ;
struct TYPE_7__ {TYPE_1__* cam_mode; } ;
struct gspca_dev {int alt; scalar_t__ curr_mode; TYPE_2__ cam; } ;
typedef  size_t s32 ;
struct TYPE_6__ {size_t priv; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
#define  IMAGE_1280 131 
#define  IMAGE_1600 130 
#define  IMAGE_640 129 
#define  IMAGE_800 128 
 int /*<<< orphan*/  c28 ; 
 int /*<<< orphan*/  c50 ; 
 int /*<<< orphan*/  c51 ; 
 int /*<<< orphan*/  c61 ; 
 int /*<<< orphan*/  ca8 ; 
 int /*<<< orphan*/  ctrl_in (struct gspca_dev*,int,int,int,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ctrl_out (struct gspca_dev*,int,int,int,int,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * dat_1280 ; 
 int /*<<< orphan*/ * dat_1600 ; 
 int /*<<< orphan*/ * dat_640 ; 
 int /*<<< orphan*/ * dat_800 ; 
 int /*<<< orphan*/ * dat_init1 ; 
 int /*<<< orphan*/ * dat_post ; 
 size_t fetch_validx (struct gspca_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  keep_on_fetching_validx (struct gspca_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,size_t) ; 
 int /*<<< orphan*/  msleep (int) ; 
static  int ov2640_camera_settings (struct gspca_dev*) ; 
static  int ov2640_configure_alt (struct gspca_dev*) ; 
static  int ov2640_init_at_startup (struct gspca_dev*) ; 
static  int ov2640_init_post_alt (struct gspca_dev*) ; 
static  int ov2640_init_pre_alt (struct gspca_dev*) ; 
static  void ov2640_post_unset_alt (struct gspca_dev*) ; 
 int /*<<< orphan*/  tbl_640 ; 
 int /*<<< orphan*/  tbl_800 ; 
 int /*<<< orphan*/  tbl_big1 ; 
 int /*<<< orphan*/  tbl_big2 ; 
 int /*<<< orphan*/  tbl_big3 ; 
 int /*<<< orphan*/  tbl_common ; 
 int /*<<< orphan*/  tbl_init_at_startup ; 
 int /*<<< orphan*/  tbl_post_unset_alt ; 
 int /*<<< orphan*/  tbl_sensor_settings_common1 ; 
 int /*<<< orphan*/  tbl_sensor_settings_common2 ; 

void ov2640_init_settings(struct gspca_dev *gspca_dev)
{
	struct sd *sd = (struct sd *) gspca_dev;

	sd->vcur.backlight  =  32;
	sd->vcur.brightness =   0;
	sd->vcur.sharpness  =   6;
	sd->vcur.contrast   =   0;
	sd->vcur.gamma      =  32;
	sd->vcur.hue        =   0;
	sd->vcur.saturation = 128;
	sd->vcur.whitebal   =  64;
	sd->vcur.mirror     =   0;
	sd->vcur.flip       =   0;

	sd->vmax.backlight  =  64;
	sd->vmax.brightness = 255;
	sd->vmax.sharpness  =  31;
	sd->vmax.contrast   = 255;
	sd->vmax.gamma      =  64;
	sd->vmax.hue        = 254 + 2;
	sd->vmax.saturation = 255;
	sd->vmax.whitebal   = 128;
	sd->vmax.mirror     = 1;
	sd->vmax.flip       = 1;
	sd->vmax.AC50Hz     = 0;

	sd->dev_camera_settings = ov2640_camera_settings;
	sd->dev_init_at_startup = ov2640_init_at_startup;
	sd->dev_configure_alt   = ov2640_configure_alt;
	sd->dev_init_pre_alt    = ov2640_init_pre_alt;
	sd->dev_post_unset_alt  = ov2640_post_unset_alt;
}

__attribute__((used)) static void common(struct gspca_dev *gspca_dev)
{
	fetch_validx(gspca_dev, tbl_common, ARRAY_SIZE(tbl_common));
}

__attribute__((used)) static int ov2640_init_at_startup(struct gspca_dev *gspca_dev)
{
	fetch_validx(gspca_dev, tbl_init_at_startup,
			ARRAY_SIZE(tbl_init_at_startup));

	ctrl_out(gspca_dev, 0x40, 3, 0x0000, 0x0200, 12, dat_init1);

	common(gspca_dev);

	ctrl_in(gspca_dev, 0xc0, 2, 0x0000, 0x0006, 1, c61);

	ctrl_out(gspca_dev, 0x40, 1, 0x00ef, 0x0006, 0, NULL);

	ctrl_in(gspca_dev, 0xc0, 2, 0x0000, 0x0000, 1, c51);

	ctrl_out(gspca_dev, 0x40, 1, 0x0051, 0x0000, 0, NULL);
/*	ctrl_out(gspca_dev, 0x40, 11, 0x0000, 0x0000, 0, NULL); */

	return 0;
}

__attribute__((used)) static int ov2640_init_pre_alt(struct gspca_dev *gspca_dev)
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
	sd->vold.mirror = -1;
	sd->vold.flip   = -1;

	ov2640_init_post_alt(gspca_dev);

	return 0;
}

__attribute__((used)) static int ov2640_init_post_alt(struct gspca_dev *gspca_dev)
{
	s32 reso = gspca_dev->cam.cam_mode[(s32) gspca_dev->curr_mode].priv;
	s32 n; /* reserved for FETCH functions */

	ctrl_out(gspca_dev, 0x40, 5, 0x0001, 0x0000, 0, NULL);

	n = fetch_validx(gspca_dev, tbl_sensor_settings_common1,
			ARRAY_SIZE(tbl_sensor_settings_common1));
	ctrl_out(gspca_dev, 0x40, 3, 0x0000, 0x0200, 12, dat_post);
	common(gspca_dev);
	keep_on_fetching_validx(gspca_dev, tbl_sensor_settings_common1,
				ARRAY_SIZE(tbl_sensor_settings_common1), n);

	switch (reso) {
	case IMAGE_640:
		n = fetch_validx(gspca_dev, tbl_640, ARRAY_SIZE(tbl_640));
		ctrl_out(gspca_dev, 0x40, 3, 0x0000, 0x0200, 12, dat_640);
		break;

	case IMAGE_800:
		n = fetch_validx(gspca_dev, tbl_800, ARRAY_SIZE(tbl_800));
		ctrl_out(gspca_dev, 0x40, 3, 0x0000, 0x0200, 12, dat_800);
		break;

	case IMAGE_1600:
	case IMAGE_1280:
		n = fetch_validx(gspca_dev, tbl_big1, ARRAY_SIZE(tbl_big1));

		if (reso == IMAGE_1280) {
			n = fetch_validx(gspca_dev, tbl_big2,
					ARRAY_SIZE(tbl_big2));
		} else {
			ctrl_out(gspca_dev, 0x40, 1, 0x601d, 0x0086, 0, NULL);
			ctrl_out(gspca_dev, 0x40, 1, 0x6001, 0x00d7, 0, NULL);
			ctrl_out(gspca_dev, 0x40, 1, 0x6082, 0x00d3, 0, NULL);
		}

		n = fetch_validx(gspca_dev, tbl_big3, ARRAY_SIZE(tbl_big3));

		if (reso == IMAGE_1280) {
			ctrl_out(gspca_dev, 0x40, 1, 0x6001, 0x00ff, 0, NULL);
			ctrl_out(gspca_dev, 0x40, 3, 0x0000, 0x0200,
					12, dat_1280);
		} else {
			ctrl_out(gspca_dev, 0x40, 1, 0x6020, 0x008c, 0, NULL);
			ctrl_out(gspca_dev, 0x40, 1, 0x6001, 0x00ff, 0, NULL);
			ctrl_out(gspca_dev, 0x40, 1, 0x6076, 0x0018, 0, NULL);
			ctrl_out(gspca_dev, 0x40, 3, 0x0000, 0x0200,
					12, dat_1600);
		}
		break;
	}

	n = fetch_validx(gspca_dev, tbl_sensor_settings_common2,
			ARRAY_SIZE(tbl_sensor_settings_common2));

	ov2640_camera_settings(gspca_dev);

	return 0;
}

__attribute__((used)) static int ov2640_configure_alt(struct gspca_dev *gspca_dev)
{
	s32 reso = gspca_dev->cam.cam_mode[(s32) gspca_dev->curr_mode].priv;

	switch (reso) {
	case IMAGE_640:
		gspca_dev->alt = 3 + 1;
		break;

	case IMAGE_800:
	case IMAGE_1280:
	case IMAGE_1600:
		gspca_dev->alt = 1 + 1;
		break;
	}
	return 0;
}

__attribute__((used)) static int ov2640_camera_settings(struct gspca_dev *gspca_dev)
{
	struct sd *sd = (struct sd *) gspca_dev;

	s32 backlight = sd->vcur.backlight;
	s32 bright = sd->vcur.brightness;
	s32 sharp  = sd->vcur.sharpness;
	s32 gam    = sd->vcur.gamma;
	s32 cntr   = sd->vcur.contrast;
	s32 sat    = sd->vcur.saturation;
	s32 hue    = sd->vcur.hue;
	s32 wbal   = sd->vcur.whitebal;
	s32 mirror = (((sd->vcur.mirror > 0) ^ sd->mirrorMask) == 0);
	s32 flip   = (((sd->vcur.flip   > 0) ^ sd->mirrorMask) == 0);

	if (backlight != sd->vold.backlight) {
		/* No sd->vold.backlight=backlight; (to be done again later) */
		if (backlight < 0 || backlight > sd->vmax.backlight)
			backlight = 0;

		ctrl_out(gspca_dev, 0x40, 1, 0x6001                 , 0x00ff,
				0, NULL);
		ctrl_out(gspca_dev, 0x40, 1, 0x601e + backlight     , 0x0024,
				0, NULL);
		ctrl_out(gspca_dev, 0x40, 1, 0x601e + backlight - 10, 0x0025,
				0, NULL);
	}

	if (bright != sd->vold.brightness) {
		sd->vold.brightness = bright;
		if (bright < 0 || bright > sd->vmax.brightness)
			bright = 0;

		ctrl_out(gspca_dev, 0x40, 1, 0x6000         , 0x00ff, 0, NULL);
		ctrl_out(gspca_dev, 0x40, 1, 0x6009         , 0x007c, 0, NULL);
		ctrl_out(gspca_dev, 0x40, 1, 0x6000 + bright, 0x007d, 0, NULL);
	}

	if (wbal != sd->vold.whitebal) {
		sd->vold.whitebal = wbal;
		if (wbal < 0 || wbal > sd->vmax.whitebal)
			wbal = 0;

		ctrl_out(gspca_dev, 0x40, 1, 0x6000       , 0x00ff, 0, NULL);
		ctrl_out(gspca_dev, 0x40, 1, 0x6003       , 0x007c, 0, NULL);
		ctrl_out(gspca_dev, 0x40, 1, 0x6000 + wbal, 0x007d, 0, NULL);
	}

	if (cntr != sd->vold.contrast) {
		sd->vold.contrast = cntr;
		if (cntr < 0 || cntr > sd->vmax.contrast)
			cntr = 0;

		ctrl_out(gspca_dev, 0x40, 1, 0x6000       , 0x00ff, 0, NULL);
		ctrl_out(gspca_dev, 0x40, 1, 0x6007       , 0x007c, 0, NULL);
		ctrl_out(gspca_dev, 0x40, 1, 0x6000 + cntr, 0x007d, 0, NULL);
	}

	if (sat != sd->vold.saturation) {
		sd->vold.saturation = sat;
		if (sat < 0 || sat > sd->vmax.saturation)
			sat = 0;

		ctrl_out(gspca_dev, 0x40, 1, 0x6000      , 0x00ff, 0, NULL);
		ctrl_out(gspca_dev, 0x40, 1, 0x6001      , 0x007c, 0, NULL);
		ctrl_out(gspca_dev, 0x40, 1, 0x6000 + sat, 0x007d, 0, NULL);
	}

	if (sharp != sd->vold.sharpness) {
		sd->vold.sharpness = sharp;
		if (sharp < 0 || sharp > sd->vmax.sharpness)
			sharp = 0;

		ctrl_out(gspca_dev, 0x40, 1, 0x6000        , 0x00ff, 0, NULL);
		ctrl_out(gspca_dev, 0x40, 1, 0x6001        , 0x0092, 0, NULL);
		ctrl_out(gspca_dev, 0x40, 1, 0x60c0 + sharp, 0x0093, 0, NULL);
	}

	if (hue != sd->vold.hue) {
		sd->vold.hue = hue;
		if (hue < 0 || hue > sd->vmax.hue)
			hue = 0;

		ctrl_out(gspca_dev, 0x40, 1, 0x6000     , 0x00ff, 0, NULL);
		ctrl_out(gspca_dev, 0x40, 1, 0x6002     , 0x007c, 0, NULL);
		ctrl_out(gspca_dev, 0x40, 1, 0x6000 + hue * (hue < 255), 0x007d,
				0, NULL);
		if (hue >= 255)
			sd->swapRB = 1;
		else
			sd->swapRB = 0;
	}

	if (gam != sd->vold.gamma) {
		sd->vold.gamma = gam;
		if (gam < 0 || gam > sd->vmax.gamma)
			gam = 0;

		ctrl_out(gspca_dev, 0x40, 1, 0x6000      , 0x00ff, 0, NULL);
		ctrl_out(gspca_dev, 0x40, 1, 0x6008      , 0x007c, 0, NULL);
		ctrl_out(gspca_dev, 0x40, 1, 0x6000 + gam, 0x007d, 0, NULL);
	}

	if (mirror != sd->vold.mirror || flip != sd->vold.flip) {
		sd->vold.mirror = mirror;
		sd->vold.flip   = flip;

		mirror = 0x80 * mirror;
		ctrl_out(gspca_dev, 0x40, 1, 0x6001, 0x00ff, 0, NULL);
		ctrl_out(gspca_dev, 0x40, 1, 0x6000, 0x8004, 0, NULL);
		ctrl_in(gspca_dev, 0xc0, 2, 0x6000, 0x8004, 1, c28);
		ctrl_out(gspca_dev, 0x40, 1, 0x6028 + mirror, 0x0004, 0, NULL);

		flip = 0x50 * flip + mirror;
		ctrl_out(gspca_dev, 0x40, 1, 0x6001, 0x00ff, 0, NULL);
		ctrl_out(gspca_dev, 0x40, 1, 0x6000, 0x8004, 0, NULL);
		ctrl_in(gspca_dev, 0xc0, 2, 0x6000, 0x8004, 1, ca8);
		ctrl_out(gspca_dev, 0x40, 1, 0x6028 + flip, 0x0004, 0, NULL);

		ctrl_in(gspca_dev, 0xc0, 2, 0x0000, 0x0000, 1, c50);
	}

	if (backlight != sd->vold.backlight) {
		sd->vold.backlight = backlight;

		ctrl_out(gspca_dev, 0x40, 1, 0x6001                 , 0x00ff,
				0, NULL);
		ctrl_out(gspca_dev, 0x40, 1, 0x601e + backlight     , 0x0024,
				0, NULL);
		ctrl_out(gspca_dev, 0x40, 1, 0x601e + backlight - 10, 0x0025,
				0, NULL);
	}

	return 0;
}

__attribute__((used)) static void ov2640_post_unset_alt(struct gspca_dev *gspca_dev)
{
	ctrl_out(gspca_dev, 0x40, 5, 0x0000, 0x0000, 0, NULL);
	msleep(20);
	fetch_validx(gspca_dev, tbl_post_unset_alt,
			ARRAY_SIZE(tbl_post_unset_alt));
}

