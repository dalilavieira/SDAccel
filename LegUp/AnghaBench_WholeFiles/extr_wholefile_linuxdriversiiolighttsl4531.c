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
struct tsl4531_data {int int_time; struct i2c_client* client; int /*<<< orphan*/  lock; } ;
struct TYPE_2__ {int /*<<< orphan*/ * parent; } ;
struct iio_dev {int /*<<< orphan*/  modes; int /*<<< orphan*/  name; int /*<<< orphan*/  num_channels; int /*<<< orphan*/  channels; int /*<<< orphan*/ * info; TYPE_1__ dev; } ;
struct iio_chan_spec {int dummy; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
#define  IIO_CHAN_INFO_INT_TIME 134 
#define  IIO_CHAN_INFO_RAW 133 
#define  IIO_CHAN_INFO_SCALE 132 
 int IIO_VAL_INT ; 
 int IIO_VAL_INT_PLUS_MICRO ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
#define  TSL45311_ID 131 
#define  TSL45313_ID 130 
#define  TSL45315_ID 129 
#define  TSL45317_ID 128 
 int /*<<< orphan*/  TSL4531_CONFIG ; 
 int /*<<< orphan*/  TSL4531_CONTROL ; 
 int /*<<< orphan*/  TSL4531_DATA ; 
 int /*<<< orphan*/  TSL4531_DRV_NAME ; 
 int /*<<< orphan*/  TSL4531_ID ; 
 int TSL4531_ID_SHIFT ; 
 int TSL4531_MODE_NORMAL ; 
 int TSL4531_MODE_POWERDOWN ; 
 int TSL4531_TCNTRL_400MS ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_read_word_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (int /*<<< orphan*/ ) ; 
 struct tsl4531_data* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  tsl4531_channels ; 
 int /*<<< orphan*/  tsl4531_info ; 

__attribute__((used)) static int tsl4531_read_raw(struct iio_dev *indio_dev,
				struct iio_chan_spec const *chan,
				int *val, int *val2, long mask)
{
	struct tsl4531_data *data = iio_priv(indio_dev);
	int ret;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		ret = i2c_smbus_read_word_data(data->client,
			TSL4531_DATA);
		if (ret < 0)
			return ret;
		*val = ret;
		return IIO_VAL_INT;
	case IIO_CHAN_INFO_SCALE:
		/* 0.. 1x, 1 .. 2x, 2 .. 4x */
		*val = 1 << data->int_time;
		return IIO_VAL_INT;
	case IIO_CHAN_INFO_INT_TIME:
		if (data->int_time == 0)
			*val2 = 400000;
		else if (data->int_time == 1)
			*val2 = 200000;
		else if (data->int_time == 2)
			*val2 = 100000;
		else
			return -EINVAL;
		*val = 0;
		return IIO_VAL_INT_PLUS_MICRO;
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int tsl4531_write_raw(struct iio_dev *indio_dev,
			     struct iio_chan_spec const *chan,
			     int val, int val2, long mask)
{
	struct tsl4531_data *data = iio_priv(indio_dev);
	int int_time, ret;

	switch (mask) {
	case IIO_CHAN_INFO_INT_TIME:
		if (val != 0)
			return -EINVAL;
		if (val2 == 400000)
			int_time = 0;
		else if (val2 == 200000)
			int_time = 1;
		else if (val2 == 100000)
			int_time = 2;
		else
			return -EINVAL;
		mutex_lock(&data->lock);
		ret = i2c_smbus_write_byte_data(data->client,
			TSL4531_CONFIG, int_time);
		if (ret >= 0)
			data->int_time = int_time;
		mutex_unlock(&data->lock);
		return ret;
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int tsl4531_check_id(struct i2c_client *client)
{
	int ret = i2c_smbus_read_byte_data(client, TSL4531_ID);
	if (ret < 0)
		return ret;

	switch (ret >> TSL4531_ID_SHIFT) {
	case TSL45311_ID:
	case TSL45313_ID:
	case TSL45315_ID:
	case TSL45317_ID:
		return 0;
	default:
		return -ENODEV;
	}
}

__attribute__((used)) static int tsl4531_probe(struct i2c_client *client,
			  const struct i2c_device_id *id)
{
	struct tsl4531_data *data;
	struct iio_dev *indio_dev;
	int ret;

	indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
	if (!indio_dev)
		return -ENOMEM;

	data = iio_priv(indio_dev);
	i2c_set_clientdata(client, indio_dev);
	data->client = client;
	mutex_init(&data->lock);

	ret = tsl4531_check_id(client);
	if (ret) {
		dev_err(&client->dev, "no TSL4531 sensor\n");
		return ret;
	}

	ret = i2c_smbus_write_byte_data(data->client, TSL4531_CONTROL,
		TSL4531_MODE_NORMAL);
	if (ret < 0)
		return ret;

	ret = i2c_smbus_write_byte_data(data->client, TSL4531_CONFIG,
		TSL4531_TCNTRL_400MS);
	if (ret < 0)
		return ret;

	indio_dev->dev.parent = &client->dev;
	indio_dev->info = &tsl4531_info;
	indio_dev->channels = tsl4531_channels;
	indio_dev->num_channels = ARRAY_SIZE(tsl4531_channels);
	indio_dev->name = TSL4531_DRV_NAME;
	indio_dev->modes = INDIO_DIRECT_MODE;

	return iio_device_register(indio_dev);
}

__attribute__((used)) static int tsl4531_powerdown(struct i2c_client *client)
{
	return i2c_smbus_write_byte_data(client, TSL4531_CONTROL,
		TSL4531_MODE_POWERDOWN);
}

__attribute__((used)) static int tsl4531_remove(struct i2c_client *client)
{
	iio_device_unregister(i2c_get_clientdata(client));
	tsl4531_powerdown(client);

	return 0;
}

