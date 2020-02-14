#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct TYPE_9__ {int /*<<< orphan*/  brightness; } ;
struct tps65217_bl_pdata {int isel; int /*<<< orphan*/  dft_brightness; TYPE_2__ props; int /*<<< orphan*/  fdim; } ;
struct tps65217_bl {int is_enabled; struct tps65217_bl_pdata* bl; TYPE_3__* dev; struct tps65217* tps; } ;
struct tps65217 {int dummy; } ;
struct TYPE_10__ {int /*<<< orphan*/  parent; } ;
struct platform_device {int /*<<< orphan*/  name; TYPE_3__ dev; } ;
struct backlight_properties {int max_brightness; int /*<<< orphan*/  type; } ;
struct TYPE_8__ {int brightness; int state; scalar_t__ power; scalar_t__ fb_blank; } ;
struct backlight_device {TYPE_1__ props; } ;

/* Variables and functions */
 int /*<<< orphan*/  BACKLIGHT_RAW ; 
 int BL_CORE_SUSPENDED ; 
 int EINVAL ; 
 int ENOMEM ; 
 scalar_t__ FB_BLANK_UNBLANK ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct tps65217_bl_pdata*) ; 
 int PTR_ERR (struct tps65217_bl_pdata*) ; 
#define  TPS65217_BL_ISET1 129 
#define  TPS65217_BL_ISET2 128 
 int /*<<< orphan*/  TPS65217_PROTECT_NONE ; 
 int /*<<< orphan*/  TPS65217_REG_WLEDCTRL1 ; 
 int /*<<< orphan*/  TPS65217_REG_WLEDCTRL2 ; 
 int /*<<< orphan*/  TPS65217_WLEDCTRL1_FDIM_MASK ; 
 int /*<<< orphan*/  TPS65217_WLEDCTRL1_ISEL ; 
 int /*<<< orphan*/  TPS65217_WLEDCTRL1_ISINK_ENABLE ; 
 int /*<<< orphan*/  backlight_update_status (struct tps65217_bl_pdata*) ; 
 struct tps65217_bl* bl_get_data (struct backlight_device*) ; 
 int /*<<< orphan*/  dev_dbg (TYPE_3__*,char*,...) ; 
 int /*<<< orphan*/  dev_err (TYPE_3__*,char*,int) ; 
 struct tps65217* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 struct tps65217_bl_pdata* devm_backlight_device_register (TYPE_3__*,int /*<<< orphan*/ ,TYPE_3__*,struct tps65217_bl*,int /*<<< orphan*/ *,struct backlight_properties*) ; 
 struct tps65217_bl* devm_kzalloc (TYPE_3__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (struct backlight_properties*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct tps65217_bl*) ; 
 int /*<<< orphan*/  tps65217_bl_ops ; 
 int tps65217_clear_bits (struct tps65217*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int tps65217_reg_write (struct tps65217*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int tps65217_set_bits (struct tps65217*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int tps65217_bl_enable(struct tps65217_bl *tps65217_bl)
{
	int rc;

	rc = tps65217_set_bits(tps65217_bl->tps, TPS65217_REG_WLEDCTRL1,
			TPS65217_WLEDCTRL1_ISINK_ENABLE,
			TPS65217_WLEDCTRL1_ISINK_ENABLE, TPS65217_PROTECT_NONE);
	if (rc) {
		dev_err(tps65217_bl->dev,
			"failed to enable backlight: %d\n", rc);
		return rc;
	}

	tps65217_bl->is_enabled = true;

	dev_dbg(tps65217_bl->dev, "backlight enabled\n");

	return 0;
}

__attribute__((used)) static int tps65217_bl_disable(struct tps65217_bl *tps65217_bl)
{
	int rc;

	rc = tps65217_clear_bits(tps65217_bl->tps,
				TPS65217_REG_WLEDCTRL1,
				TPS65217_WLEDCTRL1_ISINK_ENABLE,
				TPS65217_PROTECT_NONE);
	if (rc) {
		dev_err(tps65217_bl->dev,
			"failed to disable backlight: %d\n", rc);
		return rc;
	}

	tps65217_bl->is_enabled = false;

	dev_dbg(tps65217_bl->dev, "backlight disabled\n");

	return 0;
}

__attribute__((used)) static int tps65217_bl_update_status(struct backlight_device *bl)
{
	struct tps65217_bl *tps65217_bl = bl_get_data(bl);
	int rc;
	int brightness = bl->props.brightness;

	if (bl->props.state & BL_CORE_SUSPENDED)
		brightness = 0;

	if ((bl->props.power != FB_BLANK_UNBLANK) ||
		(bl->props.fb_blank != FB_BLANK_UNBLANK))
		/* framebuffer in low power mode or blanking active */
		brightness = 0;

	if (brightness > 0) {
		rc = tps65217_reg_write(tps65217_bl->tps,
					TPS65217_REG_WLEDCTRL2,
					brightness - 1,
					TPS65217_PROTECT_NONE);
		if (rc) {
			dev_err(tps65217_bl->dev,
				"failed to set brightness level: %d\n", rc);
			return rc;
		}

		dev_dbg(tps65217_bl->dev, "brightness set to %d\n", brightness);

		if (!tps65217_bl->is_enabled)
			rc = tps65217_bl_enable(tps65217_bl);
	} else {
		rc = tps65217_bl_disable(tps65217_bl);
	}

	return rc;
}

__attribute__((used)) static int tps65217_bl_hw_init(struct tps65217_bl *tps65217_bl,
			struct tps65217_bl_pdata *pdata)
{
	int rc;

	rc = tps65217_bl_disable(tps65217_bl);
	if (rc)
		return rc;

	switch (pdata->isel) {
	case TPS65217_BL_ISET1:
		/* select ISET_1 current level */
		rc = tps65217_clear_bits(tps65217_bl->tps,
					TPS65217_REG_WLEDCTRL1,
					TPS65217_WLEDCTRL1_ISEL,
					TPS65217_PROTECT_NONE);
		if (rc) {
			dev_err(tps65217_bl->dev,
				"failed to select ISET1 current level: %d)\n",
				rc);
			return rc;
		}

		dev_dbg(tps65217_bl->dev, "selected ISET1 current level\n");

		break;

	case TPS65217_BL_ISET2:
		/* select ISET2 current level */
		rc = tps65217_set_bits(tps65217_bl->tps, TPS65217_REG_WLEDCTRL1,
				TPS65217_WLEDCTRL1_ISEL,
				TPS65217_WLEDCTRL1_ISEL, TPS65217_PROTECT_NONE);
		if (rc) {
			dev_err(tps65217_bl->dev,
				"failed to select ISET2 current level: %d\n",
				rc);
			return rc;
		}

		dev_dbg(tps65217_bl->dev, "selected ISET2 current level\n");

		break;

	default:
		dev_err(tps65217_bl->dev,
			"invalid value for current level: %d\n", pdata->isel);
		return -EINVAL;
	}

	/* set PWM frequency */
	rc = tps65217_set_bits(tps65217_bl->tps,
			TPS65217_REG_WLEDCTRL1,
			TPS65217_WLEDCTRL1_FDIM_MASK,
			pdata->fdim,
			TPS65217_PROTECT_NONE);
	if (rc) {
		dev_err(tps65217_bl->dev,
			"failed to select PWM dimming frequency: %d\n",
			rc);
		return rc;
	}

	return 0;
}

__attribute__((used)) static struct tps65217_bl_pdata *
tps65217_bl_parse_dt(struct platform_device *pdev)
{
	return NULL;
}

__attribute__((used)) static int tps65217_bl_probe(struct platform_device *pdev)
{
	int rc;
	struct tps65217 *tps = dev_get_drvdata(pdev->dev.parent);
	struct tps65217_bl *tps65217_bl;
	struct tps65217_bl_pdata *pdata;
	struct backlight_properties bl_props;

	pdata = tps65217_bl_parse_dt(pdev);
	if (IS_ERR(pdata))
		return PTR_ERR(pdata);

	tps65217_bl = devm_kzalloc(&pdev->dev, sizeof(*tps65217_bl),
				GFP_KERNEL);
	if (tps65217_bl == NULL)
		return -ENOMEM;

	tps65217_bl->tps = tps;
	tps65217_bl->dev = &pdev->dev;
	tps65217_bl->is_enabled = false;

	rc = tps65217_bl_hw_init(tps65217_bl, pdata);
	if (rc)
		return rc;

	memset(&bl_props, 0, sizeof(struct backlight_properties));
	bl_props.type = BACKLIGHT_RAW;
	bl_props.max_brightness = 100;

	tps65217_bl->bl = devm_backlight_device_register(&pdev->dev, pdev->name,
						tps65217_bl->dev, tps65217_bl,
						&tps65217_bl_ops, &bl_props);
	if (IS_ERR(tps65217_bl->bl)) {
		dev_err(tps65217_bl->dev,
			"registration of backlight device failed: %d\n", rc);
		return PTR_ERR(tps65217_bl->bl);
	}

	tps65217_bl->bl->props.brightness = pdata->dft_brightness;
	backlight_update_status(tps65217_bl->bl);
	platform_set_drvdata(pdev, tps65217_bl);

	return 0;
}

