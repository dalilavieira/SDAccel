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
struct led_classdev {int brightness; int max_brightness; int flags; char* name; int /*<<< orphan*/  led_access; int /*<<< orphan*/  node; struct device* dev; int /*<<< orphan*/  set_brightness_work; scalar_t__ work_flags; int /*<<< orphan*/  groups; int /*<<< orphan*/  (* flash_resume ) (struct led_classdev*) ;} ;
typedef  void led_cdev ;
struct device_node {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {struct device_node* of_node; } ;
typedef  size_t ssize_t ;
typedef  int /*<<< orphan*/  name ;

/* Variables and functions */
 size_t EBUSY ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct device*) ; 
 int LED_BRIGHT_HW_CHANGED ; 
 int LED_FULL ; 
 int LED_MAX_NAME_SIZE ; 
 unsigned long LED_OFF ; 
 int LED_SUSPENDED ; 
 int LED_UNREGISTERING ; 
 int PTR_ERR (struct device*) ; 
 scalar_t__ WARN_ON (int) ; 
 struct device* class_find_device (int /*<<< orphan*/ ,int /*<<< orphan*/ *,char*,int (*) (struct device*,void const*)) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,char*) ; 
 struct led_classdev* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_name (struct device*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*,char*,int /*<<< orphan*/ ) ; 
 struct device* device_create_with_groups (int /*<<< orphan*/ ,struct device*,int /*<<< orphan*/ ,struct led_classdev*,int /*<<< orphan*/ ,char*,char*) ; 
 int /*<<< orphan*/  device_unregister (struct device*) ; 
 int /*<<< orphan*/  devres_add (struct device*,struct led_classdev**) ; 
 struct led_classdev** devres_alloc (void (*) (struct device*,void*),int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devres_free (struct led_classdev**) ; 
 int devres_release (struct device*,void (*) (struct device*,void*),int (*) (struct device*,void*,void*),struct led_classdev*) ; 
 int /*<<< orphan*/  down_write (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  flush_work (int /*<<< orphan*/ *) ; 
 size_t kstrtoul (char const*,int,unsigned long*) ; 
 int /*<<< orphan*/  led_init_core (struct led_classdev*) ; 
 int /*<<< orphan*/  led_set_brightness (struct led_classdev*,unsigned long) ; 
 int /*<<< orphan*/  led_set_brightness_nopm (struct led_classdev*,int) ; 
 int /*<<< orphan*/  led_stop_software_blink (struct led_classdev*) ; 
 scalar_t__ led_sysfs_is_disabled (struct led_classdev*) ; 
 int /*<<< orphan*/  led_trigger_remove (struct led_classdev*) ; 
 int /*<<< orphan*/  led_update_brightness (struct led_classdev*) ; 
 int /*<<< orphan*/  leds_class ; 
 int /*<<< orphan*/  leds_list ; 
 int /*<<< orphan*/  leds_list_lock ; 
 int /*<<< orphan*/  list_add_tail (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  list_del (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  put_device (struct device*) ; 
 int snprintf (char*,size_t,char*,char const*,unsigned int) ; 
 size_t sprintf (char*,char*,int) ; 
 int /*<<< orphan*/  strcmp (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  strlcpy (char*,char const*,size_t) ; 
 int /*<<< orphan*/  stub1 (struct led_classdev*) ; 
 int /*<<< orphan*/  up_write (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline int led_get_brightness(struct led_classdev *led_cdev)
{
	return led_cdev->brightness;
}

__attribute__((used)) static ssize_t brightness_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct led_classdev *led_cdev = dev_get_drvdata(dev);

	/* no lock needed for this */
	led_update_brightness(led_cdev);

	return sprintf(buf, "%u\n", led_cdev->brightness);
}

__attribute__((used)) static ssize_t brightness_store(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t size)
{
	struct led_classdev *led_cdev = dev_get_drvdata(dev);
	unsigned long state;
	ssize_t ret;

	mutex_lock(&led_cdev->led_access);

	if (led_sysfs_is_disabled(led_cdev)) {
		ret = -EBUSY;
		goto unlock;
	}

	ret = kstrtoul(buf, 10, &state);
	if (ret)
		goto unlock;

	if (state == LED_OFF)
		led_trigger_remove(led_cdev);
	led_set_brightness(led_cdev, state);

	ret = size;
unlock:
	mutex_unlock(&led_cdev->led_access);
	return ret;
}

__attribute__((used)) static ssize_t max_brightness_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct led_classdev *led_cdev = dev_get_drvdata(dev);

	return sprintf(buf, "%u\n", led_cdev->max_brightness);
}

__attribute__((used)) static int led_add_brightness_hw_changed(struct led_classdev *led_cdev)
{
	return 0;
}

__attribute__((used)) static void led_remove_brightness_hw_changed(struct led_classdev *led_cdev)
{
}

void led_classdev_suspend(struct led_classdev *led_cdev)
{
	led_cdev->flags |= LED_SUSPENDED;
	led_set_brightness_nopm(led_cdev, 0);
}

void led_classdev_resume(struct led_classdev *led_cdev)
{
	led_set_brightness_nopm(led_cdev, led_cdev->brightness);

	if (led_cdev->flash_resume)
		led_cdev->flash_resume(led_cdev);

	led_cdev->flags &= ~LED_SUSPENDED;
}

__attribute__((used)) static int match_name(struct device *dev, const void *data)
{
	if (!dev_name(dev))
		return 0;
	return !strcmp(dev_name(dev), (char *)data);
}

__attribute__((used)) static int led_classdev_next_name(const char *init_name, char *name,
				  size_t len)
{
	unsigned int i = 0;
	int ret = 0;
	struct device *dev;

	strlcpy(name, init_name, len);

	while ((ret < len) &&
	       (dev = class_find_device(leds_class, NULL, name, match_name))) {
		put_device(dev);
		ret = snprintf(name, len, "%s_%u", init_name, ++i);
	}

	if (ret >= len)
		return -ENOMEM;

	return i;
}

int of_led_classdev_register(struct device *parent, struct device_node *np,
			    struct led_classdev *led_cdev)
{
	char name[LED_MAX_NAME_SIZE];
	int ret;

	ret = led_classdev_next_name(led_cdev->name, name, sizeof(name));
	if (ret < 0)
		return ret;

	mutex_init(&led_cdev->led_access);
	mutex_lock(&led_cdev->led_access);
	led_cdev->dev = device_create_with_groups(leds_class, parent, 0,
				led_cdev, led_cdev->groups, "%s", name);
	if (IS_ERR(led_cdev->dev)) {
		mutex_unlock(&led_cdev->led_access);
		return PTR_ERR(led_cdev->dev);
	}
	led_cdev->dev->of_node = np;

	if (ret)
		dev_warn(parent, "Led %s renamed to %s due to name collision",
				led_cdev->name, dev_name(led_cdev->dev));

	if (led_cdev->flags & LED_BRIGHT_HW_CHANGED) {
		ret = led_add_brightness_hw_changed(led_cdev);
		if (ret) {
			device_unregister(led_cdev->dev);
			mutex_unlock(&led_cdev->led_access);
			return ret;
		}
	}

	led_cdev->work_flags = 0;
#ifdef CONFIG_LEDS_TRIGGERS
	init_rwsem(&led_cdev->trigger_lock);
#endif
#ifdef CONFIG_LEDS_BRIGHTNESS_HW_CHANGED
	led_cdev->brightness_hw_changed = -1;
#endif
	/* add to the list of leds */
	down_write(&leds_list_lock);
	list_add_tail(&led_cdev->node, &leds_list);
	up_write(&leds_list_lock);

	if (!led_cdev->max_brightness)
		led_cdev->max_brightness = LED_FULL;

	led_update_brightness(led_cdev);

	led_init_core(led_cdev);

#ifdef CONFIG_LEDS_TRIGGERS
	led_trigger_set_default(led_cdev);
#endif

	mutex_unlock(&led_cdev->led_access);

	dev_dbg(parent, "Registered led device: %s\n",
			led_cdev->name);

	return 0;
}

void led_classdev_unregister(struct led_classdev *led_cdev)
{
#ifdef CONFIG_LEDS_TRIGGERS
	down_write(&led_cdev->trigger_lock);
	if (led_cdev->trigger)
		led_trigger_set(led_cdev, NULL);
	up_write(&led_cdev->trigger_lock);
#endif

	led_cdev->flags |= LED_UNREGISTERING;

	/* Stop blinking */
	led_stop_software_blink(led_cdev);

	led_set_brightness(led_cdev, LED_OFF);

	flush_work(&led_cdev->set_brightness_work);

	if (led_cdev->flags & LED_BRIGHT_HW_CHANGED)
		led_remove_brightness_hw_changed(led_cdev);

	device_unregister(led_cdev->dev);

	down_write(&leds_list_lock);
	list_del(&led_cdev->node);
	up_write(&leds_list_lock);

	mutex_destroy(&led_cdev->led_access);
}

__attribute__((used)) static void devm_led_classdev_release(struct device *dev, void *res)
{
	led_classdev_unregister(*(struct led_classdev **)res);
}

int devm_of_led_classdev_register(struct device *parent,
				  struct device_node *np,
				  struct led_classdev *led_cdev)
{
	struct led_classdev **dr;
	int rc;

	dr = devres_alloc(devm_led_classdev_release, sizeof(*dr), GFP_KERNEL);
	if (!dr)
		return -ENOMEM;

	rc = of_led_classdev_register(parent, np, led_cdev);
	if (rc) {
		devres_free(dr);
		return rc;
	}

	*dr = led_cdev;
	devres_add(parent, dr);

	return 0;
}

__attribute__((used)) static int devm_led_classdev_match(struct device *dev, void *res, void *data)
{
	struct led_cdev **p = res;

	if (WARN_ON(!p || !*p))
		return 0;

	return *p == data;
}

void devm_led_classdev_unregister(struct device *dev,
				  struct led_classdev *led_cdev)
{
	WARN_ON(devres_release(dev,
			       devm_led_classdev_release,
			       devm_led_classdev_match, led_cdev));
}

