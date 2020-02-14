#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct wm831x_status_pdata {int default_src; int /*<<< orphan*/  default_trigger; int /*<<< orphan*/  name; } ;
struct TYPE_5__ {int (* brightness_set_blocking ) (struct led_classdev*,int) ;int (* blink_set ) (struct led_classdev*,unsigned long*,unsigned long*) ;int /*<<< orphan*/  groups; int /*<<< orphan*/  default_trigger; int /*<<< orphan*/  name; } ;
struct wm831x_status {int reg_val; int src; int blink; int blink_time; int blink_cyc; scalar_t__ brightness; TYPE_1__ cdev; int /*<<< orphan*/  reg; int /*<<< orphan*/  value_lock; int /*<<< orphan*/  mutex; struct wm831x* wm831x; } ;
struct wm831x_pdata {char** status; } ;
struct wm831x {int /*<<< orphan*/  dev; } ;
struct resource {int /*<<< orphan*/  start; } ;
struct TYPE_6__ {struct device* parent; } ;
struct platform_device {int id; TYPE_2__ dev; } ;
struct led_classdev {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  size_t ssize_t ;
typedef  int /*<<< orphan*/  pdata ;
typedef  enum led_brightness { ____Placeholder_led_brightness } led_brightness ;

/* Variables and functions */
 int ARRAY_SIZE (char**) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_REG ; 
 int LED_FULL ; 
 scalar_t__ LED_OFF ; 
 int WM831X_LED_DUR_MASK ; 
 int WM831X_LED_DUR_SHIFT ; 
 int WM831X_LED_DUTY_CYC_MASK ; 
 int WM831X_LED_MODE_MASK ; 
 int WM831X_LED_MODE_SHIFT ; 
 int WM831X_LED_SRC_MASK ; 
 int WM831X_LED_SRC_SHIFT ; 
 int WM831X_STATUS_PRESERVE ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*,...) ; 
 void* dev_get_drvdata (struct device*) ; 
 struct wm831x_pdata* dev_get_platdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_name (TYPE_2__*) ; 
 struct wm831x_status* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 int devm_led_classdev_register (int /*<<< orphan*/ ,TYPE_1__*) ; 
 char** led_src_texts ; 
 int /*<<< orphan*/  memcpy (struct wm831x_status_pdata*,char*,int) ; 
 int /*<<< orphan*/  memset (struct wm831x_status_pdata*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 scalar_t__ sprintf (char*,char*,...) ; 
 int sysfs_match_string (char**,char const*) ; 
 struct wm831x_status* to_wm831x_status (struct led_classdev*) ; 
 int wm831x_reg_read (struct wm831x*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wm831x_reg_write (struct wm831x*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  wm831x_status_groups ; 

__attribute__((used)) static void wm831x_status_set(struct wm831x_status *led)
{
	unsigned long flags;

	mutex_lock(&led->mutex);

	led->reg_val &= ~(WM831X_LED_SRC_MASK | WM831X_LED_MODE_MASK |
			  WM831X_LED_DUTY_CYC_MASK | WM831X_LED_DUR_MASK);

	spin_lock_irqsave(&led->value_lock, flags);

	led->reg_val |= led->src << WM831X_LED_SRC_SHIFT;
	if (led->blink) {
		led->reg_val |= 2 << WM831X_LED_MODE_SHIFT;
		led->reg_val |= led->blink_time << WM831X_LED_DUR_SHIFT;
		led->reg_val |= led->blink_cyc;
	} else {
		if (led->brightness != LED_OFF)
			led->reg_val |= 1 << WM831X_LED_MODE_SHIFT;
	}

	spin_unlock_irqrestore(&led->value_lock, flags);

	wm831x_reg_write(led->wm831x, led->reg, led->reg_val);

	mutex_unlock(&led->mutex);
}

__attribute__((used)) static int wm831x_status_brightness_set(struct led_classdev *led_cdev,
					 enum led_brightness value)
{
	struct wm831x_status *led = to_wm831x_status(led_cdev);
	unsigned long flags;

	spin_lock_irqsave(&led->value_lock, flags);
	led->brightness = value;
	if (value == LED_OFF)
		led->blink = 0;
	spin_unlock_irqrestore(&led->value_lock, flags);
	wm831x_status_set(led);

	return 0;
}

__attribute__((used)) static int wm831x_status_blink_set(struct led_classdev *led_cdev,
				   unsigned long *delay_on,
				   unsigned long *delay_off)
{
	struct wm831x_status *led = to_wm831x_status(led_cdev);
	unsigned long flags;
	int ret = 0;

	/* Pick some defaults if we've not been given times */
	if (*delay_on == 0 && *delay_off == 0) {
		*delay_on = 250;
		*delay_off = 250;
	}

	spin_lock_irqsave(&led->value_lock, flags);

	/* We only have a limited selection of settings, see if we can
	 * support the configuration we're being given */
	switch (*delay_on) {
	case 1000:
		led->blink_time = 0;
		break;
	case 250:
		led->blink_time = 1;
		break;
	case 125:
		led->blink_time = 2;
		break;
	case 62:
	case 63:
		/* Actually 62.5ms */
		led->blink_time = 3;
		break;
	default:
		ret = -EINVAL;
		break;
	}

	if (ret == 0) {
		switch (*delay_off / *delay_on) {
		case 1:
			led->blink_cyc = 0;
			break;
		case 3:
			led->blink_cyc = 1;
			break;
		case 4:
			led->blink_cyc = 2;
			break;
		case 8:
			led->blink_cyc = 3;
			break;
		default:
			ret = -EINVAL;
			break;
		}
	}

	if (ret == 0)
		led->blink = 1;
	else
		led->blink = 0;

	spin_unlock_irqrestore(&led->value_lock, flags);
	wm831x_status_set(led);

	return ret;
}

__attribute__((used)) static ssize_t wm831x_status_src_show(struct device *dev,
				      struct device_attribute *attr, char *buf)
{
	struct led_classdev *led_cdev = dev_get_drvdata(dev);
	struct wm831x_status *led = to_wm831x_status(led_cdev);
	int i;
	ssize_t ret = 0;

	mutex_lock(&led->mutex);

	for (i = 0; i < ARRAY_SIZE(led_src_texts); i++)
		if (i == led->src)
			ret += sprintf(&buf[ret], "[%s] ", led_src_texts[i]);
		else
			ret += sprintf(&buf[ret], "%s ", led_src_texts[i]);

	mutex_unlock(&led->mutex);

	ret += sprintf(&buf[ret], "\n");

	return ret;
}

__attribute__((used)) static ssize_t wm831x_status_src_store(struct device *dev,
				       struct device_attribute *attr,
				       const char *buf, size_t size)
{
	struct led_classdev *led_cdev = dev_get_drvdata(dev);
	struct wm831x_status *led = to_wm831x_status(led_cdev);
	int i;

	i = sysfs_match_string(led_src_texts, buf);
	if (i >= 0) {
		mutex_lock(&led->mutex);
		led->src = i;
		mutex_unlock(&led->mutex);
		wm831x_status_set(led);
	}

	return size;
}

__attribute__((used)) static int wm831x_status_probe(struct platform_device *pdev)
{
	struct wm831x *wm831x = dev_get_drvdata(pdev->dev.parent);
	struct wm831x_pdata *chip_pdata;
	struct wm831x_status_pdata pdata;
	struct wm831x_status *drvdata;
	struct resource *res;
	int id = pdev->id % ARRAY_SIZE(chip_pdata->status);
	int ret;

	res = platform_get_resource(pdev, IORESOURCE_REG, 0);
	if (res == NULL) {
		dev_err(&pdev->dev, "No register resource\n");
		return -EINVAL;
	}

	drvdata = devm_kzalloc(&pdev->dev, sizeof(struct wm831x_status),
			       GFP_KERNEL);
	if (!drvdata)
		return -ENOMEM;

	drvdata->wm831x = wm831x;
	drvdata->reg = res->start;

	if (dev_get_platdata(wm831x->dev))
		chip_pdata = dev_get_platdata(wm831x->dev);
	else
		chip_pdata = NULL;

	memset(&pdata, 0, sizeof(pdata));
	if (chip_pdata && chip_pdata->status[id])
		memcpy(&pdata, chip_pdata->status[id], sizeof(pdata));
	else
		pdata.name = dev_name(&pdev->dev);

	mutex_init(&drvdata->mutex);
	spin_lock_init(&drvdata->value_lock);

	/* We cache the configuration register and read startup values
	 * from it. */
	drvdata->reg_val = wm831x_reg_read(wm831x, drvdata->reg);

	if (drvdata->reg_val & WM831X_LED_MODE_MASK)
		drvdata->brightness = LED_FULL;
	else
		drvdata->brightness = LED_OFF;

	/* Set a default source if configured, otherwise leave the
	 * current hardware setting.
	 */
	if (pdata.default_src == WM831X_STATUS_PRESERVE) {
		drvdata->src = drvdata->reg_val;
		drvdata->src &= WM831X_LED_SRC_MASK;
		drvdata->src >>= WM831X_LED_SRC_SHIFT;
	} else {
		drvdata->src = pdata.default_src - 1;
	}

	drvdata->cdev.name = pdata.name;
	drvdata->cdev.default_trigger = pdata.default_trigger;
	drvdata->cdev.brightness_set_blocking = wm831x_status_brightness_set;
	drvdata->cdev.blink_set = wm831x_status_blink_set;
	drvdata->cdev.groups = wm831x_status_groups;

	ret = devm_led_classdev_register(wm831x->dev, &drvdata->cdev);
	if (ret < 0) {
		dev_err(&pdev->dev, "Failed to register LED: %d\n", ret);
		return ret;
	}

	return 0;
}

