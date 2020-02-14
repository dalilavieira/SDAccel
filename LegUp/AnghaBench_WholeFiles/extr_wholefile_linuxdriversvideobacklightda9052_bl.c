#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct TYPE_10__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_3__ dev; int /*<<< orphan*/  name; } ;
struct da9052_bl {scalar_t__ state; size_t led_reg; char brightness; TYPE_5__* da9052; } ;
struct backlight_properties {void* max_brightness; int /*<<< orphan*/  type; } ;
struct TYPE_8__ {int brightness; void* max_brightness; } ;
struct backlight_device {TYPE_1__ props; } ;
struct TYPE_11__ {int /*<<< orphan*/  dev; } ;
struct TYPE_9__ {size_t driver_data; } ;

/* Variables and functions */
 int /*<<< orphan*/  BACKLIGHT_RAW ; 
 int /*<<< orphan*/  DA9052_BOOST_REG ; 
 int /*<<< orphan*/  DA9052_LED_CONT_REG ; 
 void* DA9052_MAX_BRIGHTNESS ; 
 scalar_t__ DA9052_WLEDS_OFF ; 
 scalar_t__ DA9052_WLEDS_ON ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct backlight_device*) ; 
 int PTR_ERR (struct backlight_device*) ; 
 struct da9052_bl* bl_get_data (struct backlight_device*) ; 
 int /*<<< orphan*/  da9052_backlight_ops ; 
 int da9052_reg_write (TYPE_5__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  dev_err (TYPE_3__*,char*) ; 
 TYPE_5__* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 struct backlight_device* devm_backlight_device_register (TYPE_3__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct da9052_bl*,int /*<<< orphan*/ *,struct backlight_properties*) ; 
 struct da9052_bl* devm_kzalloc (TYPE_3__*,int,int /*<<< orphan*/ ) ; 
 TYPE_2__* platform_get_device_id (struct platform_device*) ; 
 struct backlight_device* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct backlight_device*) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 
 int /*<<< orphan*/ * wled_bank ; 

__attribute__((used)) static int da9052_adjust_wled_brightness(struct da9052_bl *wleds)
{
	unsigned char boost_en;
	unsigned char i_sink;
	int ret;

	boost_en = 0x3F;
	i_sink = 0xFF;
	if (wleds->state == DA9052_WLEDS_OFF) {
		boost_en = 0x00;
		i_sink = 0x00;
	}

	ret = da9052_reg_write(wleds->da9052, DA9052_BOOST_REG, boost_en);
	if (ret < 0)
		return ret;

	ret = da9052_reg_write(wleds->da9052, DA9052_LED_CONT_REG, i_sink);
	if (ret < 0)
		return ret;

	ret = da9052_reg_write(wleds->da9052, wled_bank[wleds->led_reg], 0x0);
	if (ret < 0)
		return ret;

	usleep_range(10000, 11000);

	if (wleds->brightness) {
		ret = da9052_reg_write(wleds->da9052, wled_bank[wleds->led_reg],
				       wleds->brightness);
		if (ret < 0)
			return ret;
	}

	return 0;
}

__attribute__((used)) static int da9052_backlight_update_status(struct backlight_device *bl)
{
	int brightness = bl->props.brightness;
	struct da9052_bl *wleds = bl_get_data(bl);

	wleds->brightness = brightness;
	wleds->state = DA9052_WLEDS_ON;

	return da9052_adjust_wled_brightness(wleds);
}

__attribute__((used)) static int da9052_backlight_get_brightness(struct backlight_device *bl)
{
	struct da9052_bl *wleds = bl_get_data(bl);

	return wleds->brightness;
}

__attribute__((used)) static int da9052_backlight_probe(struct platform_device *pdev)
{
	struct backlight_device *bl;
	struct backlight_properties props;
	struct da9052_bl *wleds;

	wleds = devm_kzalloc(&pdev->dev, sizeof(struct da9052_bl), GFP_KERNEL);
	if (!wleds)
		return -ENOMEM;

	wleds->da9052 = dev_get_drvdata(pdev->dev.parent);
	wleds->brightness = 0;
	wleds->led_reg = platform_get_device_id(pdev)->driver_data;
	wleds->state = DA9052_WLEDS_OFF;

	props.type = BACKLIGHT_RAW;
	props.max_brightness = DA9052_MAX_BRIGHTNESS;

	bl = devm_backlight_device_register(&pdev->dev, pdev->name,
					wleds->da9052->dev, wleds,
					&da9052_backlight_ops, &props);
	if (IS_ERR(bl)) {
		dev_err(&pdev->dev, "Failed to register backlight\n");
		return PTR_ERR(bl);
	}

	bl->props.max_brightness = DA9052_MAX_BRIGHTNESS;
	bl->props.brightness = 0;
	platform_set_drvdata(pdev, bl);

	return da9052_adjust_wled_brightness(wleds);
}

__attribute__((used)) static int da9052_backlight_remove(struct platform_device *pdev)
{
	struct backlight_device *bl = platform_get_drvdata(pdev);
	struct da9052_bl *wleds = bl_get_data(bl);

	wleds->brightness = 0;
	wleds->state = DA9052_WLEDS_OFF;
	da9052_adjust_wled_brightness(wleds);

	return 0;
}

