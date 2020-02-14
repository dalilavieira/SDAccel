#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct led_classdev {int max_brightness; int (* brightness_set_blocking ) (struct led_classdev*,int) ;int name; int brightness; int /*<<< orphan*/  flags; int /*<<< orphan*/ * dev; } ;
struct regulator_led {int enabled; struct led_classdev cdev; int /*<<< orphan*/  mutex; struct regulator* vcc; } ;
struct regulator {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct led_regulator_platform_data {int name; int brightness; } ;
typedef  enum led_brightness { ____Placeholder_led_brightness } led_brightness ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct regulator*) ; 
 int /*<<< orphan*/  LED_CORE_SUSPENDRESUME ; 
 int LED_OFF ; 
 int PTR_ERR (struct regulator*) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,int,int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 struct led_regulator_platform_data* dev_get_platdata (int /*<<< orphan*/ *) ; 
 struct regulator_led* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 struct regulator* devm_regulator_get_exclusive (int /*<<< orphan*/ *,char*) ; 
 int led_classdev_register (int /*<<< orphan*/ *,struct led_classdev*) ; 
 int /*<<< orphan*/  led_classdev_unregister (struct led_classdev*) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct regulator_led* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct regulator_led*) ; 
 int regulator_count_voltages (struct regulator*) ; 
 int regulator_disable (struct regulator*) ; 
 int regulator_enable (struct regulator*) ; 
 scalar_t__ regulator_is_enabled (struct regulator*) ; 
 int regulator_list_voltage (struct regulator*,int) ; 
 int regulator_set_voltage (struct regulator*,int,int) ; 
 struct regulator_led* to_regulator_led (struct led_classdev*) ; 

__attribute__((used)) static inline int led_regulator_get_max_brightness(struct regulator *supply)
{
	int ret;
	int voltage = regulator_list_voltage(supply, 0);

	if (voltage <= 0)
		return 1;

	/* even if regulator can't change voltages,
	 * we still assume it can change status
	 * and the LED can be turned on and off.
	 */
	ret = regulator_set_voltage(supply, voltage, voltage);
	if (ret < 0)
		return 1;

	return regulator_count_voltages(supply);
}

__attribute__((used)) static int led_regulator_get_voltage(struct regulator *supply,
		enum led_brightness brightness)
{
	if (brightness == 0)
		return -EINVAL;

	return regulator_list_voltage(supply, brightness - 1);
}

__attribute__((used)) static void regulator_led_enable(struct regulator_led *led)
{
	int ret;

	if (led->enabled)
		return;

	ret = regulator_enable(led->vcc);
	if (ret != 0) {
		dev_err(led->cdev.dev, "Failed to enable vcc: %d\n", ret);
		return;
	}

	led->enabled = 1;
}

__attribute__((used)) static void regulator_led_disable(struct regulator_led *led)
{
	int ret;

	if (!led->enabled)
		return;

	ret = regulator_disable(led->vcc);
	if (ret != 0) {
		dev_err(led->cdev.dev, "Failed to disable vcc: %d\n", ret);
		return;
	}

	led->enabled = 0;
}

__attribute__((used)) static int regulator_led_brightness_set(struct led_classdev *led_cdev,
					 enum led_brightness value)
{
	struct regulator_led *led = to_regulator_led(led_cdev);
	int voltage;
	int ret = 0;

	mutex_lock(&led->mutex);

	if (value == LED_OFF) {
		regulator_led_disable(led);
		goto out;
	}

	if (led->cdev.max_brightness > 1) {
		voltage = led_regulator_get_voltage(led->vcc, value);
		dev_dbg(led->cdev.dev, "brightness: %d voltage: %d\n",
				value, voltage);

		ret = regulator_set_voltage(led->vcc, voltage, voltage);
		if (ret != 0)
			dev_err(led->cdev.dev, "Failed to set voltage %d: %d\n",
				voltage, ret);
	}

	regulator_led_enable(led);

out:
	mutex_unlock(&led->mutex);
	return ret;
}

__attribute__((used)) static int regulator_led_probe(struct platform_device *pdev)
{
	struct led_regulator_platform_data *pdata =
			dev_get_platdata(&pdev->dev);
	struct regulator_led *led;
	struct regulator *vcc;
	int ret = 0;

	if (pdata == NULL) {
		dev_err(&pdev->dev, "no platform data\n");
		return -ENODEV;
	}

	vcc = devm_regulator_get_exclusive(&pdev->dev, "vled");
	if (IS_ERR(vcc)) {
		dev_err(&pdev->dev, "Cannot get vcc for %s\n", pdata->name);
		return PTR_ERR(vcc);
	}

	led = devm_kzalloc(&pdev->dev, sizeof(*led), GFP_KERNEL);
	if (led == NULL)
		return -ENOMEM;

	led->cdev.max_brightness = led_regulator_get_max_brightness(vcc);
	if (pdata->brightness > led->cdev.max_brightness) {
		dev_err(&pdev->dev, "Invalid default brightness %d\n",
				pdata->brightness);
		return -EINVAL;
	}

	led->cdev.brightness_set_blocking = regulator_led_brightness_set;
	led->cdev.name = pdata->name;
	led->cdev.flags |= LED_CORE_SUSPENDRESUME;
	led->vcc = vcc;

	/* to handle correctly an already enabled regulator */
	if (regulator_is_enabled(led->vcc))
		led->enabled = 1;

	mutex_init(&led->mutex);

	platform_set_drvdata(pdev, led);

	ret = led_classdev_register(&pdev->dev, &led->cdev);
	if (ret < 0)
		return ret;

	/* to expose the default value to userspace */
	led->cdev.brightness = pdata->brightness;

	/* Set the default led status */
	regulator_led_brightness_set(&led->cdev, led->cdev.brightness);

	return 0;
}

__attribute__((used)) static int regulator_led_remove(struct platform_device *pdev)
{
	struct regulator_led *led = platform_get_drvdata(pdev);

	led_classdev_unregister(&led->cdev);
	regulator_led_disable(led);
	return 0;
}

