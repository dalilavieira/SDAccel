#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {scalar_t__ brightness; int /*<<< orphan*/  power; } ;
struct TYPE_5__ {int /*<<< orphan*/  kobj; struct device* parent; } ;
struct sky81452_bl_platform_data {unsigned long enable; int boost_current_limit; int short_detection_threshold; char* name; int /*<<< orphan*/  gpio_enable; TYPE_3__ props; TYPE_2__ dev; scalar_t__ phase_shift; scalar_t__ dpwm_mode; scalar_t__ ignore_pwm; } ;
struct regmap {int dummy; } ;
struct device {int /*<<< orphan*/  parent; } ;
struct platform_device {struct device dev; } ;
struct TYPE_4__ {int /*<<< orphan*/  name; } ;
struct device_attribute {TYPE_1__ attr; } ;
struct backlight_properties {int /*<<< orphan*/  max_brightness; } ;
struct backlight_device {unsigned long enable; int boost_current_limit; int short_detection_threshold; char* name; int /*<<< orphan*/  gpio_enable; TYPE_3__ props; TYPE_2__ dev; scalar_t__ phase_shift; scalar_t__ dpwm_mode; scalar_t__ ignore_pwm; } ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  props ;

/* Variables and functions */
 int CTZ (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 struct sky81452_bl_platform_data* ERR_PTR (int) ; 
 int /*<<< orphan*/  FB_BLANK_UNBLANK ; 
 int /*<<< orphan*/  GPIOF_OUT_INIT_HIGH ; 
 scalar_t__ IS_ERR (struct sky81452_bl_platform_data*) ; 
 int PTR_ERR (struct sky81452_bl_platform_data*) ; 
 char* SKY81452_DEFAULT_NAME ; 
 int /*<<< orphan*/  SKY81452_EN ; 
 unsigned int SKY81452_IGPW ; 
 unsigned int SKY81452_ILIM ; 
 int /*<<< orphan*/  SKY81452_MAX_BRIGHTNESS ; 
 unsigned int SKY81452_OCP ; 
 unsigned int SKY81452_OTMP ; 
 unsigned int SKY81452_PHASE ; 
 unsigned int SKY81452_PWMMD ; 
 int /*<<< orphan*/  SKY81452_REG0 ; 
 int /*<<< orphan*/  SKY81452_REG1 ; 
 int /*<<< orphan*/  SKY81452_REG2 ; 
 unsigned int SKY81452_REG4 ; 
 unsigned int SKY81452_REG5 ; 
 unsigned int SKY81452_SHRT ; 
 int /*<<< orphan*/  SKY81452_VSHRT ; 
 int /*<<< orphan*/  backlight_update_status (struct sky81452_bl_platform_data*) ; 
 struct regmap* bl_get_data (struct sky81452_bl_platform_data*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,int) ; 
 struct regmap* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 void* dev_get_platdata (struct device*) ; 
 struct sky81452_bl_platform_data* devm_backlight_device_register (struct device*,char const*,struct device*,struct regmap*,int /*<<< orphan*/ *,struct backlight_properties*) ; 
 int devm_gpio_request_one (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 scalar_t__ gpio_is_valid (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpio_set_value_cansleep (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int kstrtoul (char const*,int,unsigned long*) ; 
 int /*<<< orphan*/  memset (struct backlight_properties*,int /*<<< orphan*/ ,int) ; 
 struct sky81452_bl_platform_data* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct sky81452_bl_platform_data*) ; 
 int regmap_read (struct regmap*,unsigned int,unsigned int*) ; 
 int regmap_update_bits (struct regmap*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned long) ; 
 int regmap_write (struct regmap*,int /*<<< orphan*/ ,unsigned int const) ; 
 int /*<<< orphan*/  sky81452_bl_attr_group ; 
 int /*<<< orphan*/  sky81452_bl_ops ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 
 int /*<<< orphan*/  strcat (char*,char*) ; 
 int /*<<< orphan*/  strcmp (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  strcpy (char*,char*) ; 
 int strlen (char*) ; 
 int sysfs_create_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sysfs_remove_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 struct sky81452_bl_platform_data* to_backlight_device (struct device*) ; 

__attribute__((used)) static int sky81452_bl_update_status(struct backlight_device *bd)
{
	const struct sky81452_bl_platform_data *pdata =
			dev_get_platdata(bd->dev.parent);
	const unsigned int brightness = (unsigned int)bd->props.brightness;
	struct regmap *regmap = bl_get_data(bd);
	int ret;

	if (brightness > 0) {
		ret = regmap_write(regmap, SKY81452_REG0, brightness - 1);
		if (ret < 0)
			return ret;

		return regmap_update_bits(regmap, SKY81452_REG1, SKY81452_EN,
					pdata->enable << CTZ(SKY81452_EN));
	}

	return regmap_update_bits(regmap, SKY81452_REG1, SKY81452_EN, 0);
}

__attribute__((used)) static ssize_t sky81452_bl_store_enable(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t count)
{
	struct regmap *regmap = bl_get_data(to_backlight_device(dev));
	unsigned long value;
	int ret;

	ret = kstrtoul(buf, 16, &value);
	if (ret < 0)
		return ret;

	ret = regmap_update_bits(regmap, SKY81452_REG1, SKY81452_EN,
					value << CTZ(SKY81452_EN));
	if (ret < 0)
		return ret;

	return count;
}

__attribute__((used)) static ssize_t sky81452_bl_show_open_short(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct regmap *regmap = bl_get_data(to_backlight_device(dev));
	unsigned int reg, value = 0;
	char tmp[3];
	int i, ret;

	reg = !strcmp(attr->attr.name, "open") ? SKY81452_REG5 : SKY81452_REG4;
	ret = regmap_read(regmap, reg, &value);
	if (ret < 0)
		return ret;

	if (value & SKY81452_SHRT) {
		*buf = 0;
		for (i = 0; i < 6; i++) {
			if (value & 0x01) {
				sprintf(tmp, "%d ", i + 1);
				strcat(buf, tmp);
			}
			value >>= 1;
		}
		strcat(buf, "\n");
	} else {
		strcpy(buf, "none\n");
	}

	return strlen(buf);
}

__attribute__((used)) static ssize_t sky81452_bl_show_fault(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct regmap *regmap = bl_get_data(to_backlight_device(dev));
	unsigned int value = 0;
	int ret;

	ret = regmap_read(regmap, SKY81452_REG4, &value);
	if (ret < 0)
		return ret;

	*buf = 0;

	if (value & SKY81452_OCP)
		strcat(buf, "over-current ");

	if (value & SKY81452_OTMP)
		strcat(buf, "over-temperature");

	strcat(buf, "\n");
	return strlen(buf);
}

__attribute__((used)) static struct sky81452_bl_platform_data *sky81452_bl_parse_dt(
							struct device *dev)
{
	return ERR_PTR(-EINVAL);
}

__attribute__((used)) static int sky81452_bl_init_device(struct regmap *regmap,
		struct sky81452_bl_platform_data *pdata)
{
	unsigned int value;

	value = pdata->ignore_pwm ? SKY81452_IGPW : 0;
	value |= pdata->dpwm_mode ? SKY81452_PWMMD : 0;
	value |= pdata->phase_shift ? 0 : SKY81452_PHASE;

	if (pdata->boost_current_limit == 2300)
		value |= SKY81452_ILIM;
	else if (pdata->boost_current_limit != 2750)
		return -EINVAL;

	if (pdata->short_detection_threshold < 4 ||
				pdata->short_detection_threshold > 7)
		return -EINVAL;
	value |= (7 - pdata->short_detection_threshold) << CTZ(SKY81452_VSHRT);

	return regmap_write(regmap, SKY81452_REG2, value);
}

__attribute__((used)) static int sky81452_bl_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct regmap *regmap = dev_get_drvdata(dev->parent);
	struct sky81452_bl_platform_data *pdata = dev_get_platdata(dev);
	struct backlight_device *bd;
	struct backlight_properties props;
	const char *name;
	int ret;

	if (!pdata) {
		pdata = sky81452_bl_parse_dt(dev);
		if (IS_ERR(pdata))
			return PTR_ERR(pdata);
	}

	if (gpio_is_valid(pdata->gpio_enable)) {
		ret = devm_gpio_request_one(dev, pdata->gpio_enable,
					GPIOF_OUT_INIT_HIGH, "sky81452-en");
		if (ret < 0) {
			dev_err(dev, "failed to request GPIO. err=%d\n", ret);
			return ret;
		}
	}

	ret = sky81452_bl_init_device(regmap, pdata);
	if (ret < 0) {
		dev_err(dev, "failed to initialize. err=%d\n", ret);
		return ret;
	}

	memset(&props, 0, sizeof(props));
	props.max_brightness = SKY81452_MAX_BRIGHTNESS,
	name = pdata->name ? pdata->name : SKY81452_DEFAULT_NAME;
	bd = devm_backlight_device_register(dev, name, dev, regmap,
						&sky81452_bl_ops, &props);
	if (IS_ERR(bd)) {
		dev_err(dev, "failed to register. err=%ld\n", PTR_ERR(bd));
		return PTR_ERR(bd);
	}

	platform_set_drvdata(pdev, bd);

	ret = sysfs_create_group(&bd->dev.kobj, &sky81452_bl_attr_group);
	if (ret < 0) {
		dev_err(dev, "failed to create attribute. err=%d\n", ret);
		return ret;
	}

	return ret;
}

__attribute__((used)) static int sky81452_bl_remove(struct platform_device *pdev)
{
	const struct sky81452_bl_platform_data *pdata =
						dev_get_platdata(&pdev->dev);
	struct backlight_device *bd = platform_get_drvdata(pdev);

	sysfs_remove_group(&bd->dev.kobj, &sky81452_bl_attr_group);

	bd->props.power = FB_BLANK_UNBLANK;
	bd->props.brightness = 0;
	backlight_update_status(bd);

	if (gpio_is_valid(pdata->gpio_enable))
		gpio_set_value_cansleep(pdata->gpio_enable, 0);

	return 0;
}

