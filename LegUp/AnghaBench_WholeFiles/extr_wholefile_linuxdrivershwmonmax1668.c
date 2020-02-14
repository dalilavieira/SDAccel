#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_42__   TYPE_9__ ;
typedef  struct TYPE_41__   TYPE_8__ ;
typedef  struct TYPE_40__   TYPE_7__ ;
typedef  struct TYPE_39__   TYPE_6__ ;
typedef  struct TYPE_38__   TYPE_5__ ;
typedef  struct TYPE_37__   TYPE_4__ ;
typedef  struct TYPE_36__   TYPE_3__ ;
typedef  struct TYPE_35__   TYPE_2__ ;
typedef  struct TYPE_34__   TYPE_21__ ;
typedef  struct TYPE_33__   TYPE_20__ ;
typedef  struct TYPE_32__   TYPE_1__ ;
typedef  struct TYPE_31__   TYPE_19__ ;
typedef  struct TYPE_30__   TYPE_18__ ;
typedef  struct TYPE_29__   TYPE_17__ ;
typedef  struct TYPE_28__   TYPE_16__ ;
typedef  struct TYPE_27__   TYPE_15__ ;
typedef  struct TYPE_26__   TYPE_14__ ;
typedef  struct TYPE_25__   TYPE_13__ ;
typedef  struct TYPE_24__   TYPE_12__ ;
typedef  struct TYPE_23__   TYPE_11__ ;
typedef  struct TYPE_22__   TYPE_10__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  umode_t ;
struct max1668_data {int valid; int* temp; int* temp_max; int* temp_min; int alarms; scalar_t__ type; int /*<<< orphan*/ ** groups; int /*<<< orphan*/  update_lock; struct i2c_client* client; scalar_t__ last_updated; } ;
struct kobject {int dummy; } ;
struct i2c_device_id {scalar_t__ driver_data; } ;
struct device {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  name; struct device dev; struct i2c_adapter* adapter; } ;
struct i2c_board_info {int /*<<< orphan*/  type; } ;
struct i2c_adapter {int dummy; } ;
struct device_attribute {int dummy; } ;
struct attribute {int dummy; } ;
typedef  int ssize_t ;
typedef  void* s8 ;
typedef  int s32 ;
struct TYPE_42__ {struct attribute attr; } ;
struct TYPE_41__ {struct attribute attr; } ;
struct TYPE_40__ {struct attribute attr; } ;
struct TYPE_39__ {struct attribute attr; } ;
struct TYPE_38__ {struct attribute attr; } ;
struct TYPE_37__ {struct attribute attr; } ;
struct TYPE_36__ {struct attribute attr; } ;
struct TYPE_35__ {struct attribute attr; } ;
struct TYPE_32__ {struct attribute attr; } ;
struct TYPE_34__ {TYPE_1__ dev_attr; } ;
struct TYPE_33__ {TYPE_6__ dev_attr; } ;
struct TYPE_31__ {TYPE_2__ dev_attr; } ;
struct TYPE_30__ {TYPE_7__ dev_attr; } ;
struct TYPE_29__ {TYPE_3__ dev_attr; } ;
struct TYPE_28__ {TYPE_8__ dev_attr; } ;
struct TYPE_27__ {TYPE_4__ dev_attr; } ;
struct TYPE_26__ {TYPE_9__ dev_attr; } ;
struct TYPE_25__ {TYPE_5__ dev_attr; } ;
struct TYPE_22__ {struct attribute attr; } ;
struct TYPE_24__ {TYPE_10__ dev_attr; } ;
struct TYPE_23__ {int index; } ;

/* Variables and functions */
 int DEV_ID_MAX1668 ; 
 int DEV_ID_MAX1805 ; 
 int DEV_ID_MAX1989 ; 
 int ENODEV ; 
 int ENOMEM ; 
 struct max1668_data* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HZ ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_BYTE_DATA ; 
 int /*<<< orphan*/  I2C_NAME_SIZE ; 
 scalar_t__ IS_ERR (struct max1668_data*) ; 
 int MAN_ID_MAXIM ; 
 int /*<<< orphan*/  MAX1668_REG_DEV_ID ; 
 int /*<<< orphan*/  MAX1668_REG_LIMH_RD (int) ; 
 int /*<<< orphan*/  MAX1668_REG_LIMH_WR (int) ; 
 int /*<<< orphan*/  MAX1668_REG_LIML_RD (int) ; 
 int /*<<< orphan*/  MAX1668_REG_LIML_WR (int) ; 
 int /*<<< orphan*/  MAX1668_REG_MAN_ID ; 
 int /*<<< orphan*/  MAX1668_REG_STAT1 ; 
 int /*<<< orphan*/  MAX1668_REG_STAT2 ; 
 int /*<<< orphan*/  MAX1668_REG_TEMP (int) ; 
 int PTR_ERR (struct max1668_data*) ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
 int /*<<< orphan*/  S_IRUGO ; 
 int /*<<< orphan*/  S_IWUSR ; 
 void* clamp_val (long,int,int) ; 
 struct max1668_data* dev_get_drvdata (struct device*) ; 
 struct device* devm_hwmon_device_register_with_groups (struct device*,int /*<<< orphan*/ ,struct max1668_data*,int /*<<< orphan*/ **) ; 
 struct max1668_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ jiffies ; 
 int kstrtol (char const*,int,long*) ; 
 scalar_t__ max1668 ; 
 int /*<<< orphan*/  max1668_group_common ; 
 int /*<<< orphan*/  max1668_group_unique ; 
 scalar_t__ max1989 ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 scalar_t__ read_only ; 
 TYPE_21__ sensor_dev_attr_temp1_max ; 
 TYPE_20__ sensor_dev_attr_temp1_min ; 
 TYPE_19__ sensor_dev_attr_temp2_max ; 
 TYPE_18__ sensor_dev_attr_temp2_min ; 
 TYPE_17__ sensor_dev_attr_temp3_max ; 
 TYPE_16__ sensor_dev_attr_temp3_min ; 
 TYPE_15__ sensor_dev_attr_temp4_max ; 
 TYPE_14__ sensor_dev_attr_temp4_min ; 
 TYPE_13__ sensor_dev_attr_temp5_max ; 
 TYPE_12__ sensor_dev_attr_temp5_min ; 
 int sprintf (char*,char*,int) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  time_after (scalar_t__,scalar_t__) ; 
 TYPE_11__* to_sensor_dev_attr (struct device_attribute*) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static struct max1668_data *max1668_update_device(struct device *dev)
{
	struct max1668_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	struct max1668_data *ret = data;
	s32 val;
	int i;

	mutex_lock(&data->update_lock);

	if (data->valid && !time_after(jiffies,
			data->last_updated + HZ + HZ / 2))
		goto abort;

	for (i = 0; i < 5; i++) {
		val = i2c_smbus_read_byte_data(client, MAX1668_REG_TEMP(i));
		if (unlikely(val < 0)) {
			ret = ERR_PTR(val);
			goto abort;
		}
		data->temp[i] = (s8) val;

		val = i2c_smbus_read_byte_data(client, MAX1668_REG_LIMH_RD(i));
		if (unlikely(val < 0)) {
			ret = ERR_PTR(val);
			goto abort;
		}
		data->temp_max[i] = (s8) val;

		val = i2c_smbus_read_byte_data(client, MAX1668_REG_LIML_RD(i));
		if (unlikely(val < 0)) {
			ret = ERR_PTR(val);
			goto abort;
		}
		data->temp_min[i] = (s8) val;
	}

	val = i2c_smbus_read_byte_data(client, MAX1668_REG_STAT1);
	if (unlikely(val < 0)) {
		ret = ERR_PTR(val);
		goto abort;
	}
	data->alarms = val << 8;

	val = i2c_smbus_read_byte_data(client, MAX1668_REG_STAT2);
	if (unlikely(val < 0)) {
		ret = ERR_PTR(val);
		goto abort;
	}
	data->alarms |= val;

	data->last_updated = jiffies;
	data->valid = 1;
abort:
	mutex_unlock(&data->update_lock);

	return ret;
}

__attribute__((used)) static ssize_t show_temp(struct device *dev,
			 struct device_attribute *devattr, char *buf)
{
	int index = to_sensor_dev_attr(devattr)->index;
	struct max1668_data *data = max1668_update_device(dev);

	if (IS_ERR(data))
		return PTR_ERR(data);

	return sprintf(buf, "%d\n", data->temp[index] * 1000);
}

__attribute__((used)) static ssize_t show_temp_max(struct device *dev,
			     struct device_attribute *devattr, char *buf)
{
	int index = to_sensor_dev_attr(devattr)->index;
	struct max1668_data *data = max1668_update_device(dev);

	if (IS_ERR(data))
		return PTR_ERR(data);

	return sprintf(buf, "%d\n", data->temp_max[index] * 1000);
}

__attribute__((used)) static ssize_t show_temp_min(struct device *dev,
			     struct device_attribute *devattr, char *buf)
{
	int index = to_sensor_dev_attr(devattr)->index;
	struct max1668_data *data = max1668_update_device(dev);

	if (IS_ERR(data))
		return PTR_ERR(data);

	return sprintf(buf, "%d\n", data->temp_min[index] * 1000);
}

__attribute__((used)) static ssize_t show_alarm(struct device *dev, struct device_attribute *attr,
			  char *buf)
{
	int index = to_sensor_dev_attr(attr)->index;
	struct max1668_data *data = max1668_update_device(dev);

	if (IS_ERR(data))
		return PTR_ERR(data);

	return sprintf(buf, "%u\n", (data->alarms >> index) & 0x1);
}

__attribute__((used)) static ssize_t show_fault(struct device *dev,
			  struct device_attribute *devattr, char *buf)
{
	int index = to_sensor_dev_attr(devattr)->index;
	struct max1668_data *data = max1668_update_device(dev);

	if (IS_ERR(data))
		return PTR_ERR(data);

	return sprintf(buf, "%u\n",
		       (data->alarms & (1 << 12)) && data->temp[index] == 127);
}

__attribute__((used)) static ssize_t set_temp_max(struct device *dev,
			    struct device_attribute *devattr,
			    const char *buf, size_t count)
{
	int index = to_sensor_dev_attr(devattr)->index;
	struct max1668_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	long temp;
	int ret;

	ret = kstrtol(buf, 10, &temp);
	if (ret < 0)
		return ret;

	mutex_lock(&data->update_lock);
	data->temp_max[index] = clamp_val(temp/1000, -128, 127);
	ret = i2c_smbus_write_byte_data(client,
					MAX1668_REG_LIMH_WR(index),
					data->temp_max[index]);
	if (ret < 0)
		count = ret;
	mutex_unlock(&data->update_lock);

	return count;
}

__attribute__((used)) static ssize_t set_temp_min(struct device *dev,
			    struct device_attribute *devattr,
			    const char *buf, size_t count)
{
	int index = to_sensor_dev_attr(devattr)->index;
	struct max1668_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	long temp;
	int ret;

	ret = kstrtol(buf, 10, &temp);
	if (ret < 0)
		return ret;

	mutex_lock(&data->update_lock);
	data->temp_min[index] = clamp_val(temp/1000, -128, 127);
	ret = i2c_smbus_write_byte_data(client,
					MAX1668_REG_LIML_WR(index),
					data->temp_min[index]);
	if (ret < 0)
		count = ret;
	mutex_unlock(&data->update_lock);

	return count;
}

__attribute__((used)) static umode_t max1668_attribute_mode(struct kobject *kobj,
				     struct attribute *attr, int index)
{
	umode_t ret = S_IRUGO;
	if (read_only)
		return ret;
	if (attr == &sensor_dev_attr_temp1_max.dev_attr.attr ||
	    attr == &sensor_dev_attr_temp2_max.dev_attr.attr ||
	    attr == &sensor_dev_attr_temp3_max.dev_attr.attr ||
	    attr == &sensor_dev_attr_temp4_max.dev_attr.attr ||
	    attr == &sensor_dev_attr_temp5_max.dev_attr.attr ||
	    attr == &sensor_dev_attr_temp1_min.dev_attr.attr ||
	    attr == &sensor_dev_attr_temp2_min.dev_attr.attr ||
	    attr == &sensor_dev_attr_temp3_min.dev_attr.attr ||
	    attr == &sensor_dev_attr_temp4_min.dev_attr.attr ||
	    attr == &sensor_dev_attr_temp5_min.dev_attr.attr)
		ret |= S_IWUSR;
	return ret;
}

__attribute__((used)) static int max1668_detect(struct i2c_client *client,
			  struct i2c_board_info *info)
{
	struct i2c_adapter *adapter = client->adapter;
	const char *type_name;
	int man_id, dev_id;

	if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
		return -ENODEV;

	/* Check for unsupported part */
	man_id = i2c_smbus_read_byte_data(client, MAX1668_REG_MAN_ID);
	if (man_id != MAN_ID_MAXIM)
		return -ENODEV;

	dev_id = i2c_smbus_read_byte_data(client, MAX1668_REG_DEV_ID);
	if (dev_id < 0)
		return -ENODEV;

	type_name = NULL;
	if (dev_id == DEV_ID_MAX1668)
		type_name = "max1668";
	else if (dev_id == DEV_ID_MAX1805)
		type_name = "max1805";
	else if (dev_id == DEV_ID_MAX1989)
		type_name = "max1989";

	if (!type_name)
		return -ENODEV;

	strlcpy(info->type, type_name, I2C_NAME_SIZE);

	return 0;
}

__attribute__((used)) static int max1668_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	struct i2c_adapter *adapter = client->adapter;
	struct device *dev = &client->dev;
	struct device *hwmon_dev;
	struct max1668_data *data;

	if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
		return -ENODEV;

	data = devm_kzalloc(dev, sizeof(struct max1668_data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->client = client;
	data->type = id->driver_data;
	mutex_init(&data->update_lock);

	/* sysfs hooks */
	data->groups[0] = &max1668_group_common;
	if (data->type == max1668 || data->type == max1989)
		data->groups[1] = &max1668_group_unique;

	hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
							   data, data->groups);
	return PTR_ERR_OR_ZERO(hwmon_dev);
}

