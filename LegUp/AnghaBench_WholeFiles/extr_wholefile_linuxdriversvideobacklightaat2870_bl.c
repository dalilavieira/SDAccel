#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct TYPE_8__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_2__ dev; int /*<<< orphan*/  id; } ;
struct fb_info {int dummy; } ;
struct backlight_properties {int /*<<< orphan*/  type; } ;
struct TYPE_7__ {int max_brightness; int brightness; scalar_t__ power; int state; } ;
struct backlight_device {TYPE_1__ props; int /*<<< orphan*/  dev; } ;
struct aat2870_data {int (* write ) (struct aat2870_data*,int /*<<< orphan*/ ,int) ;} ;
struct aat2870_bl_platform_data {scalar_t__ channels; scalar_t__ max_current; scalar_t__ max_brightness; } ;
struct aat2870_bl_driver_data {int max_current; scalar_t__ channels; int brightness; struct backlight_device* bd; struct platform_device* pdev; } ;

/* Variables and functions */
 int /*<<< orphan*/  AAT2870_BLM ; 
 scalar_t__ AAT2870_BL_CH_ALL ; 
 int /*<<< orphan*/  AAT2870_BL_CH_EN ; 
 int AAT2870_CURRENT_27_9 ; 
 int /*<<< orphan*/  AAT2870_ID_BL ; 
 int /*<<< orphan*/  BACKLIGHT_RAW ; 
 int BL_CORE_FBBLANK ; 
 int BL_CORE_SUSPENDED ; 
 int EINVAL ; 
 int ENOMEM ; 
 int ENXIO ; 
 scalar_t__ FB_BLANK_POWERDOWN ; 
 scalar_t__ FB_BLANK_UNBLANK ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct backlight_device*) ; 
 int PTR_ERR (struct backlight_device*) ; 
 int /*<<< orphan*/  aat2870_bl_ops ; 
 int /*<<< orphan*/  backlight_update_status (struct backlight_device*) ; 
 struct aat2870_bl_driver_data* bl_get_data (struct backlight_device*) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,int,scalar_t__,int) ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*,...) ; 
 struct aat2870_data* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 struct aat2870_bl_platform_data* dev_get_platdata (TYPE_2__*) ; 
 struct backlight_device* devm_backlight_device_register (TYPE_2__*,char*,TYPE_2__*,struct aat2870_bl_driver_data*,int /*<<< orphan*/ *,struct backlight_properties*) ; 
 struct aat2870_bl_driver_data* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (struct backlight_properties*,int /*<<< orphan*/ ,int) ; 
 struct aat2870_bl_driver_data* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct aat2870_bl_driver_data*) ; 
 int stub1 (struct aat2870_data*,int /*<<< orphan*/ ,int) ; 
 int stub2 (struct aat2870_data*,int /*<<< orphan*/ ,int) ; 
 int stub3 (struct aat2870_data*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline int aat2870_brightness(struct aat2870_bl_driver_data *aat2870_bl,
				     int brightness)
{
	struct backlight_device *bd = aat2870_bl->bd;
	int val;

	val = brightness * (aat2870_bl->max_current - 1);
	val /= bd->props.max_brightness;

	return val;
}

__attribute__((used)) static inline int aat2870_bl_enable(struct aat2870_bl_driver_data *aat2870_bl)
{
	struct aat2870_data *aat2870
			= dev_get_drvdata(aat2870_bl->pdev->dev.parent);

	return aat2870->write(aat2870, AAT2870_BL_CH_EN,
			      (u8)aat2870_bl->channels);
}

__attribute__((used)) static inline int aat2870_bl_disable(struct aat2870_bl_driver_data *aat2870_bl)
{
	struct aat2870_data *aat2870
			= dev_get_drvdata(aat2870_bl->pdev->dev.parent);

	return aat2870->write(aat2870, AAT2870_BL_CH_EN, 0x0);
}

__attribute__((used)) static int aat2870_bl_update_status(struct backlight_device *bd)
{
	struct aat2870_bl_driver_data *aat2870_bl = bl_get_data(bd);
	struct aat2870_data *aat2870 =
			dev_get_drvdata(aat2870_bl->pdev->dev.parent);
	int brightness = bd->props.brightness;
	int ret;

	if ((brightness < 0) || (bd->props.max_brightness < brightness)) {
		dev_err(&bd->dev, "invalid brightness, %d\n", brightness);
		return -EINVAL;
	}

	dev_dbg(&bd->dev, "brightness=%d, power=%d, state=%d\n",
		 bd->props.brightness, bd->props.power, bd->props.state);

	if ((bd->props.power != FB_BLANK_UNBLANK) ||
			(bd->props.state & BL_CORE_FBBLANK) ||
			(bd->props.state & BL_CORE_SUSPENDED))
		brightness = 0;

	ret = aat2870->write(aat2870, AAT2870_BLM,
			     (u8)aat2870_brightness(aat2870_bl, brightness));
	if (ret < 0)
		return ret;

	if (brightness == 0) {
		ret = aat2870_bl_disable(aat2870_bl);
		if (ret < 0)
			return ret;
	} else if (aat2870_bl->brightness == 0) {
		ret = aat2870_bl_enable(aat2870_bl);
		if (ret < 0)
			return ret;
	}

	aat2870_bl->brightness = brightness;

	return 0;
}

__attribute__((used)) static int aat2870_bl_check_fb(struct backlight_device *bd, struct fb_info *fi)
{
	return 1;
}

__attribute__((used)) static int aat2870_bl_probe(struct platform_device *pdev)
{
	struct aat2870_bl_platform_data *pdata = dev_get_platdata(&pdev->dev);
	struct aat2870_bl_driver_data *aat2870_bl;
	struct backlight_device *bd;
	struct backlight_properties props;
	int ret = 0;

	if (!pdata) {
		dev_err(&pdev->dev, "No platform data\n");
		ret = -ENXIO;
		goto out;
	}

	if (pdev->id != AAT2870_ID_BL) {
		dev_err(&pdev->dev, "Invalid device ID, %d\n", pdev->id);
		ret = -EINVAL;
		goto out;
	}

	aat2870_bl = devm_kzalloc(&pdev->dev,
				  sizeof(struct aat2870_bl_driver_data),
				  GFP_KERNEL);
	if (!aat2870_bl) {
		ret = -ENOMEM;
		goto out;
	}

	memset(&props, 0, sizeof(struct backlight_properties));

	props.type = BACKLIGHT_RAW;
	bd = devm_backlight_device_register(&pdev->dev, "aat2870-backlight",
					&pdev->dev, aat2870_bl, &aat2870_bl_ops,
					&props);
	if (IS_ERR(bd)) {
		dev_err(&pdev->dev,
			"Failed allocate memory for backlight device\n");
		ret = PTR_ERR(bd);
		goto out;
	}

	aat2870_bl->pdev = pdev;
	platform_set_drvdata(pdev, aat2870_bl);

	aat2870_bl->bd = bd;

	if (pdata->channels > 0)
		aat2870_bl->channels = pdata->channels;
	else
		aat2870_bl->channels = AAT2870_BL_CH_ALL;

	if (pdata->max_current > 0)
		aat2870_bl->max_current = pdata->max_current;
	else
		aat2870_bl->max_current = AAT2870_CURRENT_27_9;

	if (pdata->max_brightness > 0)
		bd->props.max_brightness = pdata->max_brightness;
	else
		bd->props.max_brightness = 255;

	aat2870_bl->brightness = 0;
	bd->props.power = FB_BLANK_UNBLANK;
	bd->props.brightness = bd->props.max_brightness;

	ret = aat2870_bl_update_status(bd);
	if (ret < 0) {
		dev_err(&pdev->dev, "Failed to initialize\n");
		return ret;
	}

	return 0;

out:
	return ret;
}

__attribute__((used)) static int aat2870_bl_remove(struct platform_device *pdev)
{
	struct aat2870_bl_driver_data *aat2870_bl = platform_get_drvdata(pdev);
	struct backlight_device *bd = aat2870_bl->bd;

	bd->props.power = FB_BLANK_POWERDOWN;
	bd->props.brightness = 0;
	backlight_update_status(bd);

	return 0;
}

