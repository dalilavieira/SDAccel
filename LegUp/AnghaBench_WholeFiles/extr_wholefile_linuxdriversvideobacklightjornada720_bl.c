#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct platform_device {int /*<<< orphan*/  dev; } ;
struct backlight_properties {int max_brightness; int /*<<< orphan*/  type; } ;
struct TYPE_2__ {scalar_t__ power; scalar_t__ fb_blank; int brightness; } ;
struct backlight_device {TYPE_1__ props; int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  BACKLIGHT_RAW ; 
 int BL_DEF_BRIGHT ; 
 int BL_MAX_BRIGHT ; 
 int BRIGHTNESSOFF ; 
 int ETIMEDOUT ; 
 scalar_t__ FB_BLANK_UNBLANK ; 
 int GETBRIGHTNESS ; 
 scalar_t__ IS_ERR (struct backlight_device*) ; 
 int PPC_LDD1 ; 
 int PPDR ; 
 int PPSR ; 
 int PTR_ERR (struct backlight_device*) ; 
 int /*<<< orphan*/  S1D_DEVICENAME ; 
 int SETBRIGHTNESS ; 
 int TXDUMMY ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*) ; 
 struct backlight_device* devm_backlight_device_register (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct backlight_properties*) ; 
 int /*<<< orphan*/  jornada_bl_ops ; 
 int jornada_ssp_byte (int) ; 
 int /*<<< orphan*/  jornada_ssp_end () ; 
 int /*<<< orphan*/  jornada_ssp_start () ; 
 int /*<<< orphan*/  memset (struct backlight_properties*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct backlight_device*) ; 

__attribute__((used)) static int jornada_bl_get_brightness(struct backlight_device *bd)
{
	int ret;

	/* check if backlight is on */
	if (!(PPSR & PPC_LDD1))
		return 0;

	jornada_ssp_start();

	/* cmd should return txdummy */
	ret = jornada_ssp_byte(GETBRIGHTNESS);

	if (jornada_ssp_byte(GETBRIGHTNESS) != TXDUMMY) {
		dev_err(&bd->dev, "get brightness timeout\n");
		jornada_ssp_end();
		return -ETIMEDOUT;
	}

	/* exchange txdummy for value */
	ret = jornada_ssp_byte(TXDUMMY);

	jornada_ssp_end();

	return BL_MAX_BRIGHT - ret;
}

__attribute__((used)) static int jornada_bl_update_status(struct backlight_device *bd)
{
	int ret = 0;

	jornada_ssp_start();

	/* If backlight is off then really turn it off */
	if ((bd->props.power != FB_BLANK_UNBLANK) || (bd->props.fb_blank != FB_BLANK_UNBLANK)) {
		ret = jornada_ssp_byte(BRIGHTNESSOFF);
		if (ret != TXDUMMY) {
			dev_info(&bd->dev, "brightness off timeout\n");
			/* turn off backlight */
			PPSR &= ~PPC_LDD1;
			PPDR |= PPC_LDD1;
			ret = -ETIMEDOUT;
		}
	} else  /* turn on backlight */
		PPSR |= PPC_LDD1;

		/* send command to our mcu */
		if (jornada_ssp_byte(SETBRIGHTNESS) != TXDUMMY) {
			dev_info(&bd->dev, "failed to set brightness\n");
			ret = -ETIMEDOUT;
			goto out;
		}

		/*
		 * at this point we expect that the mcu has accepted
		 * our command and is waiting for our new value
		 * please note that maximum brightness is 255,
		 * but due to physical layout it is equal to 0, so we simply
		 * invert the value (MAX VALUE - NEW VALUE).
		 */
		if (jornada_ssp_byte(BL_MAX_BRIGHT - bd->props.brightness)
			!= TXDUMMY) {
			dev_err(&bd->dev, "set brightness failed\n");
			ret = -ETIMEDOUT;
		}

		/*
		 * If infact we get an TXDUMMY as output we are happy and dont
		 * make any further comments about it
		 */
out:
	jornada_ssp_end();

	return ret;
}

__attribute__((used)) static int jornada_bl_probe(struct platform_device *pdev)
{
	struct backlight_properties props;
	int ret;
	struct backlight_device *bd;

	memset(&props, 0, sizeof(struct backlight_properties));
	props.type = BACKLIGHT_RAW;
	props.max_brightness = BL_MAX_BRIGHT;

	bd = devm_backlight_device_register(&pdev->dev, S1D_DEVICENAME,
					&pdev->dev, NULL, &jornada_bl_ops,
					&props);
	if (IS_ERR(bd)) {
		ret = PTR_ERR(bd);
		dev_err(&pdev->dev, "failed to register device, err=%x\n", ret);
		return ret;
	}

	bd->props.power = FB_BLANK_UNBLANK;
	bd->props.brightness = BL_DEF_BRIGHT;
	/*
	 * note. make sure max brightness is set otherwise
	 * you will get seemingly non-related errors when
	 * trying to change brightness
	 */
	jornada_bl_update_status(bd);

	platform_set_drvdata(pdev, bd);
	dev_info(&pdev->dev, "HP Jornada 700 series backlight driver\n");

	return 0;
}

