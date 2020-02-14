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
struct oneshot_trig_data {int invert; } ;
struct led_classdev {int brightness; int blink_delay_on; int blink_delay_off; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  size_t ssize_t ;

/* Variables and functions */
 void* DEFAULT_DELAY ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  LED_FULL ; 
 int /*<<< orphan*/  LED_OFF ; 
 int /*<<< orphan*/  kfree (struct oneshot_trig_data*) ; 
 int kstrtoul (char const*,int /*<<< orphan*/ ,unsigned long*) ; 
 struct oneshot_trig_data* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  led_blink_set_oneshot (struct led_classdev*,int*,int*,int) ; 
 struct oneshot_trig_data* led_get_trigger_data (struct led_classdev*) ; 
 int /*<<< orphan*/  led_set_brightness (struct led_classdev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  led_set_brightness_nosleep (struct led_classdev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  led_set_trigger_data (struct led_classdev*,struct oneshot_trig_data*) ; 
 struct oneshot_trig_data* led_trigger_get_drvdata (struct device*) ; 
 struct led_classdev* led_trigger_get_led (struct device*) ; 
 size_t sprintf (char*,char*,int) ; 

__attribute__((used)) static inline int led_get_brightness(struct led_classdev *led_cdev)
{
	return led_cdev->brightness;
}

__attribute__((used)) static ssize_t led_shot(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t size)
{
	struct led_classdev *led_cdev = led_trigger_get_led(dev);
	struct oneshot_trig_data *oneshot_data = led_trigger_get_drvdata(dev);

	led_blink_set_oneshot(led_cdev,
			&led_cdev->blink_delay_on, &led_cdev->blink_delay_off,
			oneshot_data->invert);

	/* content is ignored */
	return size;
}

__attribute__((used)) static ssize_t led_invert_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct oneshot_trig_data *oneshot_data = led_trigger_get_drvdata(dev);

	return sprintf(buf, "%u\n", oneshot_data->invert);
}

__attribute__((used)) static ssize_t led_invert_store(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t size)
{
	struct led_classdev *led_cdev = led_trigger_get_led(dev);
	struct oneshot_trig_data *oneshot_data = led_trigger_get_drvdata(dev);
	unsigned long state;
	int ret;

	ret = kstrtoul(buf, 0, &state);
	if (ret)
		return ret;

	oneshot_data->invert = !!state;

	if (oneshot_data->invert)
		led_set_brightness_nosleep(led_cdev, LED_FULL);
	else
		led_set_brightness_nosleep(led_cdev, LED_OFF);

	return size;
}

__attribute__((used)) static ssize_t led_delay_on_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct led_classdev *led_cdev = led_trigger_get_led(dev);

	return sprintf(buf, "%lu\n", led_cdev->blink_delay_on);
}

__attribute__((used)) static ssize_t led_delay_on_store(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t size)
{
	struct led_classdev *led_cdev = led_trigger_get_led(dev);
	unsigned long state;
	int ret;

	ret = kstrtoul(buf, 0, &state);
	if (ret)
		return ret;

	led_cdev->blink_delay_on = state;

	return size;
}

__attribute__((used)) static ssize_t led_delay_off_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct led_classdev *led_cdev = led_trigger_get_led(dev);

	return sprintf(buf, "%lu\n", led_cdev->blink_delay_off);
}

__attribute__((used)) static ssize_t led_delay_off_store(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t size)
{
	struct led_classdev *led_cdev = led_trigger_get_led(dev);
	unsigned long state;
	int ret;

	ret = kstrtoul(buf, 0, &state);
	if (ret)
		return ret;

	led_cdev->blink_delay_off = state;

	return size;
}

__attribute__((used)) static int oneshot_trig_activate(struct led_classdev *led_cdev)
{
	struct oneshot_trig_data *oneshot_data;

	oneshot_data = kzalloc(sizeof(*oneshot_data), GFP_KERNEL);
	if (!oneshot_data)
		return -ENOMEM;

	led_set_trigger_data(led_cdev, oneshot_data);

	led_cdev->blink_delay_on = DEFAULT_DELAY;
	led_cdev->blink_delay_off = DEFAULT_DELAY;

	return 0;
}

__attribute__((used)) static void oneshot_trig_deactivate(struct led_classdev *led_cdev)
{
	struct oneshot_trig_data *oneshot_data = led_get_trigger_data(led_cdev);

	kfree(oneshot_data);

	/* Stop blinking */
	led_set_brightness(led_cdev, LED_OFF);
}

