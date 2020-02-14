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
struct TYPE_2__ {int /*<<< orphan*/ * parent; } ;
struct iio_dev {int** channels; int num_channels; int /*<<< orphan*/  modes; int /*<<< orphan*/  name; int /*<<< orphan*/ * info; TYPE_1__ dev; } ;
struct iio_chan_spec {int dummy; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;
struct al3320a_data {struct i2c_client* client; } ;

/* Variables and functions */
 int AL3320A_CONFIG_DISABLE ; 
 int AL3320A_CONFIG_ENABLE ; 
 int AL3320A_DEFAULT_MEAN_TIME ; 
 int AL3320A_DEFAULT_WAIT_TIME ; 
 int /*<<< orphan*/  AL3320A_DRV_NAME ; 
 int AL3320A_GAIN_MASK ; 
 int AL3320A_GAIN_SHIFT ; 
 int AL3320A_RANGE_3 ; 
 int /*<<< orphan*/  AL3320A_REG_CONFIG ; 
 int /*<<< orphan*/  AL3320A_REG_CONFIG_RANGE ; 
 int /*<<< orphan*/  AL3320A_REG_DATA_LOW ; 
 int /*<<< orphan*/  AL3320A_REG_MEAN_TIME ; 
 int /*<<< orphan*/  AL3320A_REG_WAIT ; 
 int ARRAY_SIZE (int**) ; 
 int EINVAL ; 
 int ENOMEM ; 
#define  IIO_CHAN_INFO_RAW 129 
#define  IIO_CHAN_INFO_SCALE 128 
 int IIO_VAL_INT ; 
 int IIO_VAL_INT_PLUS_MICRO ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int** al3320a_channels ; 
 int /*<<< orphan*/  al3320a_info ; 
 int** al3320a_scales ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 int devm_iio_device_register (int /*<<< orphan*/ *,struct iio_dev*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_read_word_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 struct al3320a_data* iio_priv (struct iio_dev*) ; 

__attribute__((used)) static int al3320a_init(struct al3320a_data *data)
{
	int ret;

	/* power on */
	ret = i2c_smbus_write_byte_data(data->client, AL3320A_REG_CONFIG,
					AL3320A_CONFIG_ENABLE);
	if (ret < 0)
		return ret;

	ret = i2c_smbus_write_byte_data(data->client, AL3320A_REG_CONFIG_RANGE,
					AL3320A_RANGE_3 << AL3320A_GAIN_SHIFT);
	if (ret < 0)
		return ret;

	ret = i2c_smbus_write_byte_data(data->client, AL3320A_REG_MEAN_TIME,
					AL3320A_DEFAULT_MEAN_TIME);
	if (ret < 0)
		return ret;

	ret = i2c_smbus_write_byte_data(data->client, AL3320A_REG_WAIT,
					AL3320A_DEFAULT_WAIT_TIME);
	if (ret < 0)
		return ret;

	return 0;
}

__attribute__((used)) static int al3320a_read_raw(struct iio_dev *indio_dev,
			    struct iio_chan_spec const *chan, int *val,
			    int *val2, long mask)
{
	struct al3320a_data *data = iio_priv(indio_dev);
	int ret;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		/*
		 * ALS ADC value is stored in two adjacent registers:
		 * - low byte of output is stored at AL3320A_REG_DATA_LOW
		 * - high byte of output is stored at AL3320A_REG_DATA_LOW + 1
		 */
		ret = i2c_smbus_read_word_data(data->client,
					       AL3320A_REG_DATA_LOW);
		if (ret < 0)
			return ret;
		*val = ret;
		return IIO_VAL_INT;
	case IIO_CHAN_INFO_SCALE:
		ret = i2c_smbus_read_byte_data(data->client,
					       AL3320A_REG_CONFIG_RANGE);
		if (ret < 0)
			return ret;

		ret = (ret & AL3320A_GAIN_MASK) >> AL3320A_GAIN_SHIFT;
		*val = al3320a_scales[ret][0];
		*val2 = al3320a_scales[ret][1];

		return IIO_VAL_INT_PLUS_MICRO;
	}
	return -EINVAL;
}

__attribute__((used)) static int al3320a_write_raw(struct iio_dev *indio_dev,
			     struct iio_chan_spec const *chan, int val,
			     int val2, long mask)
{
	struct al3320a_data *data = iio_priv(indio_dev);
	int i;

	switch (mask) {
	case IIO_CHAN_INFO_SCALE:
		for (i = 0; i < ARRAY_SIZE(al3320a_scales); i++) {
			if (val == al3320a_scales[i][0] &&
			    val2 == al3320a_scales[i][1])
				return i2c_smbus_write_byte_data(data->client,
					AL3320A_REG_CONFIG_RANGE,
					i << AL3320A_GAIN_SHIFT);
		}
		break;
	}
	return -EINVAL;
}

__attribute__((used)) static int al3320a_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	struct al3320a_data *data;
	struct iio_dev *indio_dev;
	int ret;

	indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
	if (!indio_dev)
		return -ENOMEM;

	data = iio_priv(indio_dev);
	i2c_set_clientdata(client, indio_dev);
	data->client = client;

	indio_dev->dev.parent = &client->dev;
	indio_dev->info = &al3320a_info;
	indio_dev->name = AL3320A_DRV_NAME;
	indio_dev->channels = al3320a_channels;
	indio_dev->num_channels = ARRAY_SIZE(al3320a_channels);
	indio_dev->modes = INDIO_DIRECT_MODE;

	ret = al3320a_init(data);
	if (ret < 0) {
		dev_err(&client->dev, "al3320a chip init failed\n");
		return ret;
	}
	return devm_iio_device_register(&client->dev, indio_dev);
}

__attribute__((used)) static int al3320a_remove(struct i2c_client *client)
{
	return i2c_smbus_write_byte_data(client, AL3320A_REG_CONFIG,
					 AL3320A_CONFIG_DISABLE);
}

