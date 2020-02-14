#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u64 ;
struct ms_ht_dev {size_t res_index; int /*<<< orphan*/  lock; struct i2c_client* client; } ;
struct TYPE_2__ {int /*<<< orphan*/ * parent; } ;
struct iio_dev {int* channels; void* num_channels; int /*<<< orphan*/  modes; TYPE_1__ dev; int /*<<< orphan*/  name; int /*<<< orphan*/ * info; } ;
struct iio_chan_spec {int /*<<< orphan*/  type; } ;
struct i2c_device_id {scalar_t__ driver_data; int /*<<< orphan*/  name; } ;
struct i2c_client {int /*<<< orphan*/  dev; int /*<<< orphan*/  adapter; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 void* ARRAY_SIZE (int*) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 int /*<<< orphan*/  HTU21_RESET ; 
 int I2C_FUNC_SMBUS_READ_I2C_BLOCK ; 
 int I2C_FUNC_SMBUS_WRITE_BYTE ; 
 int I2C_FUNC_SMBUS_WRITE_BYTE_DATA ; 
#define  IIO_CHAN_INFO_PROCESSED 131 
#define  IIO_CHAN_INFO_SAMP_FREQ 130 
#define  IIO_HUMIDITYRELATIVE 129 
#define  IIO_TEMP 128 
 int IIO_VAL_INT ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 scalar_t__ MS8607 ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 struct iio_dev* dev_to_iio_dev (struct device*) ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 int devm_iio_device_register (int /*<<< orphan*/ *,struct iio_dev*) ; 
 int* htu21_channels ; 
 int /*<<< orphan*/  htu21_info ; 
 int* htu21_samp_freq ; 
 int /*<<< orphan*/  i2c_check_functionality (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 struct ms_ht_dev* iio_priv (struct iio_dev*) ; 
 int* ms8607_channels ; 
 int ms_sensors_ht_read_humidity (struct ms_ht_dev*,unsigned int*) ; 
 int ms_sensors_ht_read_temperature (struct ms_ht_dev*,int*) ; 
 int ms_sensors_read_serial (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int ms_sensors_reset (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ms_sensors_show_battery_low (struct ms_ht_dev*,char*) ; 
 int /*<<< orphan*/  ms_sensors_show_heater (struct ms_ht_dev*,char*) ; 
 int /*<<< orphan*/  ms_sensors_write_heater (struct ms_ht_dev*,char const*,size_t) ; 
 int ms_sensors_write_resolution (struct ms_ht_dev*,int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int htu21_read_raw(struct iio_dev *indio_dev,
			  struct iio_chan_spec const *channel, int *val,
			  int *val2, long mask)
{
	int ret, temperature;
	unsigned int humidity;
	struct ms_ht_dev *dev_data = iio_priv(indio_dev);

	switch (mask) {
	case IIO_CHAN_INFO_PROCESSED:
		switch (channel->type) {
		case IIO_TEMP:	/* in milli °C */
			ret = ms_sensors_ht_read_temperature(dev_data,
							     &temperature);
			if (ret)
				return ret;
			*val = temperature;

			return IIO_VAL_INT;
		case IIO_HUMIDITYRELATIVE:	/* in milli %RH */
			ret = ms_sensors_ht_read_humidity(dev_data,
							  &humidity);
			if (ret)
				return ret;
			*val = humidity;

			return IIO_VAL_INT;
		default:
			return -EINVAL;
		}
	case IIO_CHAN_INFO_SAMP_FREQ:
		*val = htu21_samp_freq[dev_data->res_index];

		return IIO_VAL_INT;
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int htu21_write_raw(struct iio_dev *indio_dev,
			   struct iio_chan_spec const *chan,
			   int val, int val2, long mask)
{
	struct ms_ht_dev *dev_data = iio_priv(indio_dev);
	int i, ret;

	switch (mask) {
	case IIO_CHAN_INFO_SAMP_FREQ:
		i = ARRAY_SIZE(htu21_samp_freq);
		while (i-- > 0)
			if (val == htu21_samp_freq[i])
				break;
		if (i < 0)
			return -EINVAL;
		mutex_lock(&dev_data->lock);
		dev_data->res_index = i;
		ret = ms_sensors_write_resolution(dev_data, i);
		mutex_unlock(&dev_data->lock);

		return ret;
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static ssize_t htu21_show_battery_low(struct device *dev,
				      struct device_attribute *attr, char *buf)
{
	struct iio_dev *indio_dev = dev_to_iio_dev(dev);
	struct ms_ht_dev *dev_data = iio_priv(indio_dev);

	return ms_sensors_show_battery_low(dev_data, buf);
}

__attribute__((used)) static ssize_t htu21_show_heater(struct device *dev,
				 struct device_attribute *attr, char *buf)
{
	struct iio_dev *indio_dev = dev_to_iio_dev(dev);
	struct ms_ht_dev *dev_data = iio_priv(indio_dev);

	return ms_sensors_show_heater(dev_data, buf);
}

__attribute__((used)) static ssize_t htu21_write_heater(struct device *dev,
				  struct device_attribute *attr,
				  const char *buf, size_t len)
{
	struct iio_dev *indio_dev = dev_to_iio_dev(dev);
	struct ms_ht_dev *dev_data = iio_priv(indio_dev);

	return ms_sensors_write_heater(dev_data, buf, len);
}

__attribute__((used)) static int htu21_probe(struct i2c_client *client,
		       const struct i2c_device_id *id)
{
	struct ms_ht_dev *dev_data;
	struct iio_dev *indio_dev;
	int ret;
	u64 serial_number;

	if (!i2c_check_functionality(client->adapter,
				     I2C_FUNC_SMBUS_WRITE_BYTE_DATA |
				     I2C_FUNC_SMBUS_WRITE_BYTE |
				     I2C_FUNC_SMBUS_READ_I2C_BLOCK)) {
		dev_err(&client->dev,
			"Adapter does not support some i2c transaction\n");
		return -EOPNOTSUPP;
	}

	indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*dev_data));
	if (!indio_dev)
		return -ENOMEM;

	dev_data = iio_priv(indio_dev);
	dev_data->client = client;
	dev_data->res_index = 0;
	mutex_init(&dev_data->lock);

	indio_dev->info = &htu21_info;
	indio_dev->name = id->name;
	indio_dev->dev.parent = &client->dev;
	indio_dev->modes = INDIO_DIRECT_MODE;

	if (id->driver_data == MS8607) {
		indio_dev->channels = ms8607_channels;
		indio_dev->num_channels = ARRAY_SIZE(ms8607_channels);
	} else {
		indio_dev->channels = htu21_channels;
		indio_dev->num_channels = ARRAY_SIZE(htu21_channels);
	}

	i2c_set_clientdata(client, indio_dev);

	ret = ms_sensors_reset(client, HTU21_RESET, 15000);
	if (ret)
		return ret;

	ret = ms_sensors_read_serial(client, &serial_number);
	if (ret)
		return ret;
	dev_info(&client->dev, "Serial number : %llx", serial_number);

	return devm_iio_device_register(&client->dev, indio_dev);
}

