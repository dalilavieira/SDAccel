#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
struct TYPE_9__ {struct device* parent; } ;
struct platform_device {TYPE_3__ dev; int /*<<< orphan*/  name; int /*<<< orphan*/  id; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct backlight_properties {int max_brightness; int /*<<< orphan*/  type; } ;
struct TYPE_7__ {int /*<<< orphan*/  kobj; } ;
struct TYPE_8__ {int brightness; scalar_t__ power; scalar_t__ fb_blank; } ;
struct backlight_device {TYPE_1__ dev; TYPE_2__ props; } ;
struct adp5520_bl {unsigned long cached_daylight_max; int current_brightness; struct adp5520_backlight_platform_data* pdata; struct device* master; int /*<<< orphan*/  lock; int /*<<< orphan*/  id; } ;
struct adp5520_backlight_platform_data {unsigned long l1_daylight_max; unsigned long l1_daylight_dim; unsigned long l2_office_max; unsigned long l2_office_dim; unsigned long l3_dark_max; unsigned long l3_dark_dim; unsigned long l2_trip; unsigned long l2_hyst; unsigned long l3_trip; unsigned long l3_hyst; scalar_t__ en_ambl_sens; int /*<<< orphan*/  fade_out; int /*<<< orphan*/  fade_in; int /*<<< orphan*/  fade_led_law; int /*<<< orphan*/  abml_filt; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int ADP5020_MAX_BRIGHTNESS ; 
 int ADP5520_ALS_CMPR_CFG ; 
 int ADP5520_BL_AUTO_ADJ ; 
 int ADP5520_BL_CONTROL ; 
 int ADP5520_BL_EN ; 
 int ADP5520_BL_FADE ; 
 int ADP5520_BL_VALUE ; 
 int ADP5520_DARK_DIM ; 
 int ADP5520_DARK_MAX ; 
 int ADP5520_DAYLIGHT_DIM ; 
 int ADP5520_DAYLIGHT_MAX ; 
 int ADP5520_DIM_EN ; 
 int ADP5520_L2_HYS ; 
 int ADP5520_L2_TRIP ; 
 int /*<<< orphan*/  ADP5520_L3_EN ; 
 int ADP5520_L3_HYS ; 
 int ADP5520_L3_TRIP ; 
 int ADP5520_MODE_STATUS ; 
 int ADP5520_OFFICE_DIM ; 
 int ADP5520_OFFICE_MAX ; 
 unsigned long ALS_CMPR_CFG_VAL (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BACKLIGHT_RAW ; 
 unsigned long BL_CTRL_VAL (int /*<<< orphan*/ ,scalar_t__) ; 
 int ENODEV ; 
 int ENOMEM ; 
 unsigned long FADE_VAL (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ FB_BLANK_UNBLANK ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct backlight_device*) ; 
 int PTR_ERR (struct backlight_device*) ; 
 int /*<<< orphan*/  adp5520_bl_attr_group ; 
 int /*<<< orphan*/  adp5520_bl_ops ; 
 int adp5520_clr_bits (struct device*,int,int) ; 
 int adp5520_read (struct device*,int,int*) ; 
 int adp5520_set_bits (struct device*,int,int) ; 
 int adp5520_write (struct device*,int,unsigned long) ; 
 int /*<<< orphan*/  backlight_update_status (struct backlight_device*) ; 
 struct adp5520_bl* bl_get_data (struct backlight_device*) ; 
 int /*<<< orphan*/  dev_err (TYPE_3__*,char*) ; 
 struct adp5520_bl* dev_get_drvdata (struct device*) ; 
 struct adp5520_backlight_platform_data* dev_get_platdata (TYPE_3__*) ; 
 struct backlight_device* devm_backlight_device_register (TYPE_3__*,int /*<<< orphan*/ ,struct device*,struct adp5520_bl*,int /*<<< orphan*/ *,struct backlight_properties*) ; 
 struct adp5520_bl* devm_kzalloc (TYPE_3__*,int,int /*<<< orphan*/ ) ; 
 int kstrtoul (char const*,int,unsigned long*) ; 
 int /*<<< orphan*/  memset (struct backlight_properties*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct backlight_device* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct backlight_device*) ; 
 int sprintf (char*,char*,int) ; 
 int sysfs_create_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sysfs_remove_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int adp5520_bl_set(struct backlight_device *bl, int brightness)
{
	struct adp5520_bl *data = bl_get_data(bl);
	struct device *master = data->master;
	int ret = 0;

	if (data->pdata->en_ambl_sens) {
		if ((brightness > 0) && (brightness < ADP5020_MAX_BRIGHTNESS)) {
			/* Disable Ambient Light auto adjust */
			ret |= adp5520_clr_bits(master, ADP5520_BL_CONTROL,
					ADP5520_BL_AUTO_ADJ);
			ret |= adp5520_write(master, ADP5520_DAYLIGHT_MAX,
					brightness);
		} else {
			/*
			 * MAX_BRIGHTNESS -> Enable Ambient Light auto adjust
			 * restore daylight l3 sysfs brightness
			 */
			ret |= adp5520_write(master, ADP5520_DAYLIGHT_MAX,
					 data->cached_daylight_max);
			ret |= adp5520_set_bits(master, ADP5520_BL_CONTROL,
					 ADP5520_BL_AUTO_ADJ);
		}
	} else {
		ret |= adp5520_write(master, ADP5520_DAYLIGHT_MAX, brightness);
	}

	if (data->current_brightness && brightness == 0)
		ret |= adp5520_set_bits(master,
				ADP5520_MODE_STATUS, ADP5520_DIM_EN);
	else if (data->current_brightness == 0 && brightness)
		ret |= adp5520_clr_bits(master,
				ADP5520_MODE_STATUS, ADP5520_DIM_EN);

	if (!ret)
		data->current_brightness = brightness;

	return ret;
}

__attribute__((used)) static int adp5520_bl_update_status(struct backlight_device *bl)
{
	int brightness = bl->props.brightness;

	if (bl->props.power != FB_BLANK_UNBLANK)
		brightness = 0;

	if (bl->props.fb_blank != FB_BLANK_UNBLANK)
		brightness = 0;

	return adp5520_bl_set(bl, brightness);
}

__attribute__((used)) static int adp5520_bl_get_brightness(struct backlight_device *bl)
{
	struct adp5520_bl *data = bl_get_data(bl);
	int error;
	uint8_t reg_val;

	error = adp5520_read(data->master, ADP5520_BL_VALUE, &reg_val);

	return error ? data->current_brightness : reg_val;
}

__attribute__((used)) static int adp5520_bl_setup(struct backlight_device *bl)
{
	struct adp5520_bl *data = bl_get_data(bl);
	struct device *master = data->master;
	struct adp5520_backlight_platform_data *pdata = data->pdata;
	int ret = 0;

	ret |= adp5520_write(master, ADP5520_DAYLIGHT_MAX,
				pdata->l1_daylight_max);
	ret |= adp5520_write(master, ADP5520_DAYLIGHT_DIM,
				pdata->l1_daylight_dim);

	if (pdata->en_ambl_sens) {
		data->cached_daylight_max = pdata->l1_daylight_max;
		ret |= adp5520_write(master, ADP5520_OFFICE_MAX,
				pdata->l2_office_max);
		ret |= adp5520_write(master, ADP5520_OFFICE_DIM,
				pdata->l2_office_dim);
		ret |= adp5520_write(master, ADP5520_DARK_MAX,
				pdata->l3_dark_max);
		ret |= adp5520_write(master, ADP5520_DARK_DIM,
				pdata->l3_dark_dim);
		ret |= adp5520_write(master, ADP5520_L2_TRIP,
				pdata->l2_trip);
		ret |= adp5520_write(master, ADP5520_L2_HYS,
				pdata->l2_hyst);
		ret |= adp5520_write(master, ADP5520_L3_TRIP,
				 pdata->l3_trip);
		ret |= adp5520_write(master, ADP5520_L3_HYS,
				pdata->l3_hyst);
		ret |= adp5520_write(master, ADP5520_ALS_CMPR_CFG,
				ALS_CMPR_CFG_VAL(pdata->abml_filt,
				ADP5520_L3_EN));
	}

	ret |= adp5520_write(master, ADP5520_BL_CONTROL,
			BL_CTRL_VAL(pdata->fade_led_law,
					pdata->en_ambl_sens));

	ret |= adp5520_write(master, ADP5520_BL_FADE, FADE_VAL(pdata->fade_in,
			pdata->fade_out));

	ret |= adp5520_set_bits(master, ADP5520_MODE_STATUS,
			ADP5520_BL_EN | ADP5520_DIM_EN);

	return ret;
}

__attribute__((used)) static ssize_t adp5520_show(struct device *dev, char *buf, int reg)
{
	struct adp5520_bl *data = dev_get_drvdata(dev);
	int ret;
	uint8_t reg_val;

	mutex_lock(&data->lock);
	ret = adp5520_read(data->master, reg, &reg_val);
	mutex_unlock(&data->lock);

	if (ret < 0)
		return ret;

	return sprintf(buf, "%u\n", reg_val);
}

__attribute__((used)) static ssize_t adp5520_store(struct device *dev, const char *buf,
			 size_t count, int reg)
{
	struct adp5520_bl *data = dev_get_drvdata(dev);
	unsigned long val;
	int ret;

	ret = kstrtoul(buf, 10, &val);
	if (ret)
		return ret;

	mutex_lock(&data->lock);
	adp5520_write(data->master, reg, val);
	mutex_unlock(&data->lock);

	return count;
}

__attribute__((used)) static ssize_t adp5520_bl_dark_max_show(struct device *dev,
			struct device_attribute *attr, char *buf)
{
	return adp5520_show(dev, buf, ADP5520_DARK_MAX);
}

__attribute__((used)) static ssize_t adp5520_bl_dark_max_store(struct device *dev,
			struct device_attribute *attr,
			const char *buf, size_t count)
{
	return adp5520_store(dev, buf, count, ADP5520_DARK_MAX);
}

__attribute__((used)) static ssize_t adp5520_bl_office_max_show(struct device *dev,
			struct device_attribute *attr, char *buf)
{
	return adp5520_show(dev, buf, ADP5520_OFFICE_MAX);
}

__attribute__((used)) static ssize_t adp5520_bl_office_max_store(struct device *dev,
			struct device_attribute *attr,
			const char *buf, size_t count)
{
	return adp5520_store(dev, buf, count, ADP5520_OFFICE_MAX);
}

__attribute__((used)) static ssize_t adp5520_bl_daylight_max_show(struct device *dev,
			struct device_attribute *attr, char *buf)
{
	return adp5520_show(dev, buf, ADP5520_DAYLIGHT_MAX);
}

__attribute__((used)) static ssize_t adp5520_bl_daylight_max_store(struct device *dev,
			struct device_attribute *attr,
			const char *buf, size_t count)
{
	struct adp5520_bl *data = dev_get_drvdata(dev);
	int ret;

	ret = kstrtoul(buf, 10, &data->cached_daylight_max);
	if (ret < 0)
		return ret;

	return adp5520_store(dev, buf, count, ADP5520_DAYLIGHT_MAX);
}

__attribute__((used)) static ssize_t adp5520_bl_dark_dim_show(struct device *dev,
			struct device_attribute *attr, char *buf)
{
	return adp5520_show(dev, buf, ADP5520_DARK_DIM);
}

__attribute__((used)) static ssize_t adp5520_bl_dark_dim_store(struct device *dev,
			struct device_attribute *attr,
			const char *buf, size_t count)
{
	return adp5520_store(dev, buf, count, ADP5520_DARK_DIM);
}

__attribute__((used)) static ssize_t adp5520_bl_office_dim_show(struct device *dev,
			struct device_attribute *attr, char *buf)
{
	return adp5520_show(dev, buf, ADP5520_OFFICE_DIM);
}

__attribute__((used)) static ssize_t adp5520_bl_office_dim_store(struct device *dev,
			struct device_attribute *attr,
			const char *buf, size_t count)
{
	return adp5520_store(dev, buf, count, ADP5520_OFFICE_DIM);
}

__attribute__((used)) static ssize_t adp5520_bl_daylight_dim_show(struct device *dev,
			struct device_attribute *attr, char *buf)
{
	return adp5520_show(dev, buf, ADP5520_DAYLIGHT_DIM);
}

__attribute__((used)) static ssize_t adp5520_bl_daylight_dim_store(struct device *dev,
			struct device_attribute *attr,
			const char *buf, size_t count)
{
	return adp5520_store(dev, buf, count, ADP5520_DAYLIGHT_DIM);
}

__attribute__((used)) static int adp5520_bl_probe(struct platform_device *pdev)
{
	struct backlight_properties props;
	struct backlight_device *bl;
	struct adp5520_bl *data;
	int ret = 0;

	data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
	if (data == NULL)
		return -ENOMEM;

	data->master = pdev->dev.parent;
	data->pdata = dev_get_platdata(&pdev->dev);

	if (data->pdata  == NULL) {
		dev_err(&pdev->dev, "missing platform data\n");
		return -ENODEV;
	}

	data->id = pdev->id;
	data->current_brightness = 0;

	mutex_init(&data->lock);

	memset(&props, 0, sizeof(struct backlight_properties));
	props.type = BACKLIGHT_RAW;
	props.max_brightness = ADP5020_MAX_BRIGHTNESS;
	bl = devm_backlight_device_register(&pdev->dev, pdev->name,
					data->master, data, &adp5520_bl_ops,
					&props);
	if (IS_ERR(bl)) {
		dev_err(&pdev->dev, "failed to register backlight\n");
		return PTR_ERR(bl);
	}

	bl->props.brightness = ADP5020_MAX_BRIGHTNESS;
	if (data->pdata->en_ambl_sens)
		ret = sysfs_create_group(&bl->dev.kobj,
			&adp5520_bl_attr_group);

	if (ret) {
		dev_err(&pdev->dev, "failed to register sysfs\n");
		return ret;
	}

	platform_set_drvdata(pdev, bl);
	ret = adp5520_bl_setup(bl);
	if (ret) {
		dev_err(&pdev->dev, "failed to setup\n");
		if (data->pdata->en_ambl_sens)
			sysfs_remove_group(&bl->dev.kobj,
					&adp5520_bl_attr_group);
		return ret;
	}

	backlight_update_status(bl);

	return 0;
}

__attribute__((used)) static int adp5520_bl_remove(struct platform_device *pdev)
{
	struct backlight_device *bl = platform_get_drvdata(pdev);
	struct adp5520_bl *data = bl_get_data(bl);

	adp5520_clr_bits(data->master, ADP5520_MODE_STATUS, ADP5520_BL_EN);

	if (data->pdata->en_ambl_sens)
		sysfs_remove_group(&bl->dev.kobj,
				&adp5520_bl_attr_group);

	return 0;
}

