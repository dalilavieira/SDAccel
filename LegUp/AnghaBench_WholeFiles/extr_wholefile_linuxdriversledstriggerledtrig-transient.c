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
struct transient_trig_data {int activate; void* restore_state; scalar_t__ duration; void* state; int /*<<< orphan*/  timer; struct led_classdev* led_cdev; } ;
struct timer_list {int dummy; } ;
struct led_classdev {int brightness; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  size_t ssize_t ;

/* Variables and functions */
 size_t EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 void* LED_FULL ; 
 void* LED_OFF ; 
 int /*<<< orphan*/  del_timer (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  del_timer_sync (int /*<<< orphan*/ *) ; 
 struct transient_trig_data* from_timer (int /*<<< orphan*/ ,struct timer_list*,int /*<<< orphan*/ ) ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  kfree (struct transient_trig_data*) ; 
 size_t kstrtoul (char const*,int,unsigned long*) ; 
 struct transient_trig_data* kzalloc (int,int /*<<< orphan*/ ) ; 
 struct transient_trig_data* led_get_trigger_data (struct led_classdev*) ; 
 int /*<<< orphan*/  led_set_brightness_nosleep (struct led_classdev*,void*) ; 
 int /*<<< orphan*/  led_set_trigger_data (struct led_classdev*,struct transient_trig_data*) ; 
 struct transient_trig_data* led_trigger_get_drvdata (struct device*) ; 
 struct led_classdev* led_trigger_get_led (struct device*) ; 
 int /*<<< orphan*/  mod_timer (int /*<<< orphan*/ *,scalar_t__) ; 
 scalar_t__ msecs_to_jiffies (scalar_t__) ; 
 size_t sprintf (char*,char*,int) ; 
 int /*<<< orphan*/  timer ; 
 int /*<<< orphan*/  timer_setup (int /*<<< orphan*/ *,void (*) (struct timer_list*),int /*<<< orphan*/ ) ; 
 struct transient_trig_data* transient_data ; 

__attribute__((used)) static inline int led_get_brightness(struct led_classdev *led_cdev)
{
	return led_cdev->brightness;
}

__attribute__((used)) static void transient_timer_function(struct timer_list *t)
{
	struct transient_trig_data *transient_data =
		from_timer(transient_data, t, timer);
	struct led_classdev *led_cdev = transient_data->led_cdev;

	transient_data->activate = 0;
	led_set_brightness_nosleep(led_cdev, transient_data->restore_state);
}

__attribute__((used)) static ssize_t transient_activate_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct transient_trig_data *transient_data =
		led_trigger_get_drvdata(dev);

	return sprintf(buf, "%d\n", transient_data->activate);
}

__attribute__((used)) static ssize_t transient_activate_store(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t size)
{
	struct led_classdev *led_cdev = led_trigger_get_led(dev);
	struct transient_trig_data *transient_data =
		led_trigger_get_drvdata(dev);
	unsigned long state;
	ssize_t ret;

	ret = kstrtoul(buf, 10, &state);
	if (ret)
		return ret;

	if (state != 1 && state != 0)
		return -EINVAL;

	/* cancel the running timer */
	if (state == 0 && transient_data->activate == 1) {
		del_timer(&transient_data->timer);
		transient_data->activate = state;
		led_set_brightness_nosleep(led_cdev,
					transient_data->restore_state);
		return size;
	}

	/* start timer if there is no active timer */
	if (state == 1 && transient_data->activate == 0 &&
	    transient_data->duration != 0) {
		transient_data->activate = state;
		led_set_brightness_nosleep(led_cdev, transient_data->state);
		transient_data->restore_state =
		    (transient_data->state == LED_FULL) ? LED_OFF : LED_FULL;
		mod_timer(&transient_data->timer,
			  jiffies + msecs_to_jiffies(transient_data->duration));
	}

	/* state == 0 && transient_data->activate == 0
		timer is not active - just return */
	/* state == 1 && transient_data->activate == 1
		timer is already active - just return */

	return size;
}

__attribute__((used)) static ssize_t transient_duration_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct transient_trig_data *transient_data = led_trigger_get_drvdata(dev);

	return sprintf(buf, "%lu\n", transient_data->duration);
}

__attribute__((used)) static ssize_t transient_duration_store(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t size)
{
	struct transient_trig_data *transient_data =
		led_trigger_get_drvdata(dev);
	unsigned long state;
	ssize_t ret;

	ret = kstrtoul(buf, 10, &state);
	if (ret)
		return ret;

	transient_data->duration = state;
	return size;
}

__attribute__((used)) static ssize_t transient_state_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct transient_trig_data *transient_data =
		led_trigger_get_drvdata(dev);
	int state;

	state = (transient_data->state == LED_FULL) ? 1 : 0;
	return sprintf(buf, "%d\n", state);
}

__attribute__((used)) static ssize_t transient_state_store(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t size)
{
	struct transient_trig_data *transient_data =
		led_trigger_get_drvdata(dev);
	unsigned long state;
	ssize_t ret;

	ret = kstrtoul(buf, 10, &state);
	if (ret)
		return ret;

	if (state != 1 && state != 0)
		return -EINVAL;

	transient_data->state = (state == 1) ? LED_FULL : LED_OFF;
	return size;
}

__attribute__((used)) static int transient_trig_activate(struct led_classdev *led_cdev)
{
	struct transient_trig_data *tdata;

	tdata = kzalloc(sizeof(struct transient_trig_data), GFP_KERNEL);
	if (!tdata)
		return -ENOMEM;

	led_set_trigger_data(led_cdev, tdata);
	tdata->led_cdev = led_cdev;

	timer_setup(&tdata->timer, transient_timer_function, 0);

	return 0;
}

__attribute__((used)) static void transient_trig_deactivate(struct led_classdev *led_cdev)
{
	struct transient_trig_data *transient_data = led_get_trigger_data(led_cdev);

	del_timer_sync(&transient_data->timer);
	led_set_brightness_nosleep(led_cdev, transient_data->restore_state);
	kfree(transient_data);
}

