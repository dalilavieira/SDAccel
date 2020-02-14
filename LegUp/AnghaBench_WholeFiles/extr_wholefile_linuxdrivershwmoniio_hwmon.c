#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_5__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_8__ {int /*<<< orphan*/  mode; int /*<<< orphan*/ * name; } ;
struct TYPE_7__ {int (* show ) (struct device*,struct device_attribute*,char*) ;TYPE_3__ attr; } ;
struct sensor_device_attribute {size_t index; TYPE_2__ dev_attr; } ;
struct device {TYPE_1__* of_node; } ;
struct platform_device {struct device dev; } ;
struct TYPE_9__ {TYPE_3__** attrs; } ;
struct iio_hwmon_state {size_t num_channels; TYPE_5__** groups; TYPE_5__ attr_group; TYPE_3__** attrs; struct iio_channel* channels; } ;
struct iio_channel {scalar_t__ indio_dev; } ;
struct device_attribute {int dummy; } ;
typedef  int ssize_t ;
typedef  enum iio_chan_type { ____Placeholder_iio_chan_type } iio_chan_type ;
struct TYPE_6__ {char* name; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
#define  IIO_CURRENT 131 
#define  IIO_HUMIDITYRELATIVE 130 
#define  IIO_TEMP 129 
#define  IIO_VOLTAGE 128 
 scalar_t__ IS_ERR (struct iio_channel*) ; 
 int PTR_ERR (struct iio_channel*) ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
 int /*<<< orphan*/  S_IRUGO ; 
 struct iio_hwmon_state* dev_get_drvdata (struct device*) ; 
 struct device* devm_hwmon_device_register_with_groups (struct device*,char*,struct iio_hwmon_state*,TYPE_5__**) ; 
 struct iio_channel* devm_iio_channel_get_all (struct device*) ; 
 void* devm_kasprintf (struct device*,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 TYPE_3__** devm_kcalloc (struct device*,int,int,int /*<<< orphan*/ ) ; 
 char* devm_kstrdup (struct device*,char const*,int /*<<< orphan*/ ) ; 
 void* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int iio_get_channel_type (struct iio_channel*,int*) ; 
 int iio_read_channel_processed (struct iio_channel*,int*) ; 
 int sprintf (char*,char*,int) ; 
 int /*<<< orphan*/  strreplace (char*,char,char) ; 
 int /*<<< orphan*/  sysfs_attr_init (TYPE_3__*) ; 
 struct sensor_device_attribute* to_sensor_dev_attr (struct device_attribute*) ; 

__attribute__((used)) static ssize_t iio_hwmon_read_val(struct device *dev,
				  struct device_attribute *attr,
				  char *buf)
{
	int result;
	int ret;
	struct sensor_device_attribute *sattr = to_sensor_dev_attr(attr);
	struct iio_hwmon_state *state = dev_get_drvdata(dev);

	ret = iio_read_channel_processed(&state->channels[sattr->index],
					&result);
	if (ret < 0)
		return ret;

	return sprintf(buf, "%d\n", result);
}

__attribute__((used)) static int iio_hwmon_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct iio_hwmon_state *st;
	struct sensor_device_attribute *a;
	int ret, i;
	int in_i = 1, temp_i = 1, curr_i = 1, humidity_i = 1;
	enum iio_chan_type type;
	struct iio_channel *channels;
	const char *name = "iio_hwmon";
	struct device *hwmon_dev;
	char *sname;

	if (dev->of_node && dev->of_node->name)
		name = dev->of_node->name;

	channels = devm_iio_channel_get_all(dev);
	if (IS_ERR(channels)) {
		if (PTR_ERR(channels) == -ENODEV)
			return -EPROBE_DEFER;
		return PTR_ERR(channels);
	}

	st = devm_kzalloc(dev, sizeof(*st), GFP_KERNEL);
	if (st == NULL)
		return -ENOMEM;

	st->channels = channels;

	/* count how many attributes we have */
	while (st->channels[st->num_channels].indio_dev)
		st->num_channels++;

	st->attrs = devm_kcalloc(dev,
				 st->num_channels + 1, sizeof(*st->attrs),
				 GFP_KERNEL);
	if (st->attrs == NULL)
		return -ENOMEM;

	for (i = 0; i < st->num_channels; i++) {
		a = devm_kzalloc(dev, sizeof(*a), GFP_KERNEL);
		if (a == NULL)
			return -ENOMEM;

		sysfs_attr_init(&a->dev_attr.attr);
		ret = iio_get_channel_type(&st->channels[i], &type);
		if (ret < 0)
			return ret;

		switch (type) {
		case IIO_VOLTAGE:
			a->dev_attr.attr.name = devm_kasprintf(dev, GFP_KERNEL,
							       "in%d_input",
							       in_i++);
			break;
		case IIO_TEMP:
			a->dev_attr.attr.name = devm_kasprintf(dev, GFP_KERNEL,
							       "temp%d_input",
							       temp_i++);
			break;
		case IIO_CURRENT:
			a->dev_attr.attr.name = devm_kasprintf(dev, GFP_KERNEL,
							       "curr%d_input",
							       curr_i++);
			break;
		case IIO_HUMIDITYRELATIVE:
			a->dev_attr.attr.name = devm_kasprintf(dev, GFP_KERNEL,
							       "humidity%d_input",
							       humidity_i++);
			break;
		default:
			return -EINVAL;
		}
		if (a->dev_attr.attr.name == NULL)
			return -ENOMEM;

		a->dev_attr.show = iio_hwmon_read_val;
		a->dev_attr.attr.mode = S_IRUGO;
		a->index = i;
		st->attrs[i] = &a->dev_attr.attr;
	}

	st->attr_group.attrs = st->attrs;
	st->groups[0] = &st->attr_group;

	sname = devm_kstrdup(dev, name, GFP_KERNEL);
	if (!sname)
		return -ENOMEM;

	strreplace(sname, '-', '_');
	hwmon_dev = devm_hwmon_device_register_with_groups(dev, sname, st,
							   st->groups);
	return PTR_ERR_OR_ZERO(hwmon_dev);
}

