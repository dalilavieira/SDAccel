#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct pcf8591_data {int aout; int control; int /*<<< orphan*/  update_lock; int /*<<< orphan*/  hwmon_dev; } ;
struct i2c_device_id {int dummy; } ;
struct TYPE_4__ {int /*<<< orphan*/  kobj; } ;
struct i2c_client {TYPE_1__ dev; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PCF8591_CONTROL_AICH_MASK ; 
 int PCF8591_CONTROL_AOEF ; 
 unsigned long PCF8591_INIT_AOUT ; 
 int PCF8591_INIT_CONTROL ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int REG_TO_SIGNED (int) ; 
 int /*<<< orphan*/  dev_attr_in2_input ; 
 int /*<<< orphan*/  dev_attr_in3_input ; 
 int device_create_file (TYPE_1__*,int /*<<< orphan*/ *) ; 
 struct pcf8591_data* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hwmon_device_register (TYPE_1__*) ; 
 int /*<<< orphan*/  hwmon_device_unregister (int /*<<< orphan*/ ) ; 
 struct pcf8591_data* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct pcf8591_data*) ; 
 int i2c_smbus_read_byte (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_smbus_write_byte (struct i2c_client*,int) ; 
 int /*<<< orphan*/  i2c_smbus_write_byte_data (struct i2c_client*,int,unsigned long) ; 
 int input_mode ; 
 int kstrtoul (char const*,int,unsigned long*) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pcf8591_attr_group ; 
 int /*<<< orphan*/  pcf8591_attr_group_opt ; 
static  void pcf8591_init_client (struct i2c_client*) ; 
 int sprintf (char*,char*,int) ; 
 int sysfs_create_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sysfs_remove_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 struct i2c_client* to_i2c_client (struct device*) ; 

__attribute__((used)) static ssize_t out0_output_show(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	struct pcf8591_data *data = i2c_get_clientdata(to_i2c_client(dev));
	return sprintf(buf, "%d\n", data->aout * 10);
}

__attribute__((used)) static ssize_t out0_output_store(struct device *dev,
				 struct device_attribute *attr,
				 const char *buf, size_t count)
{
	unsigned long val;
	struct i2c_client *client = to_i2c_client(dev);
	struct pcf8591_data *data = i2c_get_clientdata(client);
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	val /= 10;
	if (val > 255)
		return -EINVAL;

	data->aout = val;
	i2c_smbus_write_byte_data(client, data->control, data->aout);
	return count;
}

__attribute__((used)) static ssize_t out0_enable_show(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	struct pcf8591_data *data = i2c_get_clientdata(to_i2c_client(dev));
	return sprintf(buf, "%u\n", !(!(data->control & PCF8591_CONTROL_AOEF)));
}

__attribute__((used)) static ssize_t out0_enable_store(struct device *dev,
				 struct device_attribute *attr,
				 const char *buf, size_t count)
{
	struct i2c_client *client = to_i2c_client(dev);
	struct pcf8591_data *data = i2c_get_clientdata(client);
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	if (val)
		data->control |= PCF8591_CONTROL_AOEF;
	else
		data->control &= ~PCF8591_CONTROL_AOEF;
	i2c_smbus_write_byte(client, data->control);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static int pcf8591_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	struct pcf8591_data *data;
	int err;

	data = devm_kzalloc(&client->dev, sizeof(struct pcf8591_data),
			    GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	i2c_set_clientdata(client, data);
	mutex_init(&data->update_lock);

	/* Initialize the PCF8591 chip */
	pcf8591_init_client(client);

	/* Register sysfs hooks */
	err = sysfs_create_group(&client->dev.kobj, &pcf8591_attr_group);
	if (err)
		return err;

	/* Register input2 if not in "two differential inputs" mode */
	if (input_mode != 3) {
		err = device_create_file(&client->dev, &dev_attr_in2_input);
		if (err)
			goto exit_sysfs_remove;
	}

	/* Register input3 only in "four single ended inputs" mode */
	if (input_mode == 0) {
		err = device_create_file(&client->dev, &dev_attr_in3_input);
		if (err)
			goto exit_sysfs_remove;
	}

	data->hwmon_dev = hwmon_device_register(&client->dev);
	if (IS_ERR(data->hwmon_dev)) {
		err = PTR_ERR(data->hwmon_dev);
		goto exit_sysfs_remove;
	}

	return 0;

exit_sysfs_remove:
	sysfs_remove_group(&client->dev.kobj, &pcf8591_attr_group_opt);
	sysfs_remove_group(&client->dev.kobj, &pcf8591_attr_group);
	return err;
}

__attribute__((used)) static int pcf8591_remove(struct i2c_client *client)
{
	struct pcf8591_data *data = i2c_get_clientdata(client);

	hwmon_device_unregister(data->hwmon_dev);
	sysfs_remove_group(&client->dev.kobj, &pcf8591_attr_group_opt);
	sysfs_remove_group(&client->dev.kobj, &pcf8591_attr_group);
	return 0;
}

__attribute__((used)) static void pcf8591_init_client(struct i2c_client *client)
{
	struct pcf8591_data *data = i2c_get_clientdata(client);
	data->control = PCF8591_INIT_CONTROL;
	data->aout = PCF8591_INIT_AOUT;

	i2c_smbus_write_byte_data(client, data->control, data->aout);

	/*
	 * The first byte transmitted contains the conversion code of the
	 * previous read cycle. FLUSH IT!
	 */
	i2c_smbus_read_byte(client);
}

__attribute__((used)) static int pcf8591_read_channel(struct device *dev, int channel)
{
	u8 value;
	struct i2c_client *client = to_i2c_client(dev);
	struct pcf8591_data *data = i2c_get_clientdata(client);

	mutex_lock(&data->update_lock);

	if ((data->control & PCF8591_CONTROL_AICH_MASK) != channel) {
		data->control = (data->control & ~PCF8591_CONTROL_AICH_MASK)
			      | channel;
		i2c_smbus_write_byte(client, data->control);

		/*
		 * The first byte transmitted contains the conversion code of
		 * the previous read cycle. FLUSH IT!
		 */
		i2c_smbus_read_byte(client);
	}
	value = i2c_smbus_read_byte(client);

	mutex_unlock(&data->update_lock);

	if ((channel == 2 && input_mode == 2) ||
	    (channel != 3 && (input_mode == 1 || input_mode == 3)))
		return 10 * REG_TO_SIGNED(value);
	else
		return 10 * value;
}

