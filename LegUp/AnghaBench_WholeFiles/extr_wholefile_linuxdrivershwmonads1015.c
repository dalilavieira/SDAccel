#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_8__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int u16 ;
struct sensor_device_attribute {int index; } ;
struct i2c_device_id {int driver_data; } ;
struct TYPE_9__ {scalar_t__ of_node; } ;
struct i2c_client {TYPE_1__ dev; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct ads1015_platform_data {int /*<<< orphan*/  channel_data; } ;
struct ads1015_data {scalar_t__ id; int /*<<< orphan*/  hwmon_dev; TYPE_2__* channel_data; int /*<<< orphan*/  update_lock; } ;
typedef  int ssize_t ;
typedef  int s16 ;
typedef  enum ads1015_chips { ____Placeholder_ads1015_chips } ads1015_chips ;
struct TYPE_11__ {int /*<<< orphan*/  dev_attr; } ;
struct TYPE_10__ {unsigned int pga; unsigned int data_rate; int enabled; } ;

/* Variables and functions */
 int ADS1015_CHANNELS ; 
 int /*<<< orphan*/  ADS1015_CONFIG ; 
 int /*<<< orphan*/  ADS1015_CONVERSION ; 
 unsigned int ADS1015_DEFAULT_DATA_RATE ; 
 unsigned int ADS1015_DEFAULT_PGA ; 
 int DIV_ROUND_CLOSEST (int,int const) ; 
 unsigned int DIV_ROUND_UP (int,unsigned int const) ; 
 int EIO ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 TYPE_8__* ads1015_in ; 
 scalar_t__ ads1115 ; 
 unsigned int* data_rate_table_1015 ; 
 unsigned int* data_rate_table_1115 ; 
 struct ads1015_platform_data* dev_get_platdata (TYPE_1__*) ; 
 int device_create_file (TYPE_1__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  device_remove_file (TYPE_1__*,int /*<<< orphan*/ *) ; 
 struct ads1015_data* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 int* fullscale_table ; 
 int /*<<< orphan*/  hwmon_device_register (TYPE_1__*) ; 
 int /*<<< orphan*/  hwmon_device_unregister (int /*<<< orphan*/ ) ; 
 struct ads1015_data* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct ads1015_data*) ; 
 int i2c_smbus_read_word_swapped (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_write_word_swapped (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  memcpy (TYPE_2__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  msleep (unsigned int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 scalar_t__ of_device_get_match_data (TYPE_1__*) ; 
 int sprintf (char*,char*,int) ; 
 struct i2c_client* to_i2c_client (struct device*) ; 
 struct sensor_device_attribute* to_sensor_dev_attr (struct device_attribute*) ; 

__attribute__((used)) static int ads1015_read_adc(struct i2c_client *client, unsigned int channel)
{
	u16 config;
	struct ads1015_data *data = i2c_get_clientdata(client);
	unsigned int pga = data->channel_data[channel].pga;
	unsigned int data_rate = data->channel_data[channel].data_rate;
	unsigned int conversion_time_ms;
	const unsigned int * const rate_table = data->id == ads1115 ?
		data_rate_table_1115 : data_rate_table_1015;
	int res;

	mutex_lock(&data->update_lock);

	/* get channel parameters */
	res = i2c_smbus_read_word_swapped(client, ADS1015_CONFIG);
	if (res < 0)
		goto err_unlock;
	config = res;
	conversion_time_ms = DIV_ROUND_UP(1000, rate_table[data_rate]);

	/* setup and start single conversion */
	config &= 0x001f;
	config |= (1 << 15) | (1 << 8);
	config |= (channel & 0x0007) << 12;
	config |= (pga & 0x0007) << 9;
	config |= (data_rate & 0x0007) << 5;

	res = i2c_smbus_write_word_swapped(client, ADS1015_CONFIG, config);
	if (res < 0)
		goto err_unlock;

	/* wait until conversion finished */
	msleep(conversion_time_ms);
	res = i2c_smbus_read_word_swapped(client, ADS1015_CONFIG);
	if (res < 0)
		goto err_unlock;
	config = res;
	if (!(config & (1 << 15))) {
		/* conversion not finished in time */
		res = -EIO;
		goto err_unlock;
	}

	res = i2c_smbus_read_word_swapped(client, ADS1015_CONVERSION);

err_unlock:
	mutex_unlock(&data->update_lock);
	return res;
}

__attribute__((used)) static int ads1015_reg_to_mv(struct i2c_client *client, unsigned int channel,
			     s16 reg)
{
	struct ads1015_data *data = i2c_get_clientdata(client);
	unsigned int pga = data->channel_data[channel].pga;
	int fullscale = fullscale_table[pga];
	const int mask = data->id == ads1115 ? 0x7fff : 0x7ff0;

	return DIV_ROUND_CLOSEST(reg * fullscale, mask);
}

__attribute__((used)) static ssize_t show_in(struct device *dev, struct device_attribute *da,
	char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
	struct i2c_client *client = to_i2c_client(dev);
	int res;
	int index = attr->index;

	res = ads1015_read_adc(client, index);
	if (res < 0)
		return res;

	return sprintf(buf, "%d\n", ads1015_reg_to_mv(client, index, res));
}

__attribute__((used)) static int ads1015_remove(struct i2c_client *client)
{
	struct ads1015_data *data = i2c_get_clientdata(client);
	int k;

	hwmon_device_unregister(data->hwmon_dev);
	for (k = 0; k < ADS1015_CHANNELS; ++k)
		device_remove_file(&client->dev, &ads1015_in[k].dev_attr);
	return 0;
}

__attribute__((used)) static void ads1015_get_channels_config(struct i2c_client *client)
{
	unsigned int k;
	struct ads1015_data *data = i2c_get_clientdata(client);
	struct ads1015_platform_data *pdata = dev_get_platdata(&client->dev);

	/* prefer platform data */
	if (pdata) {
		memcpy(data->channel_data, pdata->channel_data,
		       sizeof(data->channel_data));
		return;
	}

#ifdef CONFIG_OF
	if (!ads1015_get_channels_config_of(client))
		return;
#endif

	/* fallback on default configuration */
	for (k = 0; k < ADS1015_CHANNELS; ++k) {
		data->channel_data[k].enabled = true;
		data->channel_data[k].pga = ADS1015_DEFAULT_PGA;
		data->channel_data[k].data_rate = ADS1015_DEFAULT_DATA_RATE;
	}
}

__attribute__((used)) static int ads1015_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	struct ads1015_data *data;
	int err;
	unsigned int k;

	data = devm_kzalloc(&client->dev, sizeof(struct ads1015_data),
			    GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	if (client->dev.of_node)
		data->id = (enum ads1015_chips)
			of_device_get_match_data(&client->dev);
	else
		data->id = id->driver_data;
	i2c_set_clientdata(client, data);
	mutex_init(&data->update_lock);

	/* build sysfs attribute group */
	ads1015_get_channels_config(client);
	for (k = 0; k < ADS1015_CHANNELS; ++k) {
		if (!data->channel_data[k].enabled)
			continue;
		err = device_create_file(&client->dev, &ads1015_in[k].dev_attr);
		if (err)
			goto exit_remove;
	}

	data->hwmon_dev = hwmon_device_register(&client->dev);
	if (IS_ERR(data->hwmon_dev)) {
		err = PTR_ERR(data->hwmon_dev);
		goto exit_remove;
	}

	return 0;

exit_remove:
	for (k = 0; k < ADS1015_CHANNELS; ++k)
		device_remove_file(&client->dev, &ads1015_in[k].dev_attr);
	return err;
}

