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
struct si7005_data {int config; int /*<<< orphan*/  lock; struct i2c_client* client; } ;
struct TYPE_2__ {int /*<<< orphan*/ * parent; } ;
struct iio_dev {int /*<<< orphan*/  num_channels; int /*<<< orphan*/  channels; int /*<<< orphan*/ * info; int /*<<< orphan*/  modes; int /*<<< orphan*/  name; TYPE_1__ dev; } ;
struct iio_chan_spec {int /*<<< orphan*/  type; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; int /*<<< orphan*/  adapter; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_WORD_DATA ; 
#define  IIO_CHAN_INFO_OFFSET 130 
#define  IIO_CHAN_INFO_RAW 129 
#define  IIO_CHAN_INFO_SCALE 128 
 int /*<<< orphan*/  IIO_TEMP ; 
 int IIO_VAL_INT ; 
 int IIO_VAL_INT_PLUS_MICRO ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int /*<<< orphan*/  SI7005_CONFIG ; 
 int SI7005_CONFIG_START ; 
 int SI7005_CONFIG_TEMP ; 
 int /*<<< orphan*/  SI7005_DATA ; 
 int /*<<< orphan*/  SI7005_ID ; 
 int SI7005_ID_7005 ; 
 int SI7005_ID_7015 ; 
 int /*<<< orphan*/  SI7005_STATUS ; 
 int SI7005_STATUS_NRDY ; 
 int /*<<< orphan*/  dev_name (int /*<<< orphan*/ *) ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 int devm_iio_device_register (int /*<<< orphan*/ *,struct iio_dev*) ; 
 int /*<<< orphan*/  i2c_check_functionality (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_read_word_swapped (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 struct si7005_data* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  si7005_channels ; 
 int /*<<< orphan*/  si7005_info ; 

__attribute__((used)) static int si7005_read_measurement(struct si7005_data *data, bool temp)
{
	int tries = 50;
	int ret;

	mutex_lock(&data->lock);

	ret = i2c_smbus_write_byte_data(data->client, SI7005_CONFIG,
		data->config | SI7005_CONFIG_START |
		(temp ? SI7005_CONFIG_TEMP : 0));
	if (ret < 0)
		goto done;

	while (tries-- > 0) {
		msleep(20);
		ret = i2c_smbus_read_byte_data(data->client, SI7005_STATUS);
		if (ret < 0)
			goto done;
		if (!(ret & SI7005_STATUS_NRDY))
			break;
	}
	if (tries < 0) {
		ret = -EIO;
		goto done;
	}

	ret = i2c_smbus_read_word_swapped(data->client, SI7005_DATA);

done:
	mutex_unlock(&data->lock);

	return ret;
}

__attribute__((used)) static int si7005_read_raw(struct iio_dev *indio_dev,
			    struct iio_chan_spec const *chan, int *val,
			    int *val2, long mask)
{
	struct si7005_data *data = iio_priv(indio_dev);
	int ret;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		ret = si7005_read_measurement(data, chan->type == IIO_TEMP);
		if (ret < 0)
			return ret;
		*val = ret;
		return IIO_VAL_INT;
	case IIO_CHAN_INFO_SCALE:
		if (chan->type == IIO_TEMP) {
			*val = 7;
			*val2 = 812500;
		} else {
			*val = 3;
			*val2 = 906250;
		}
		return IIO_VAL_INT_PLUS_MICRO;
	case IIO_CHAN_INFO_OFFSET:
		if (chan->type == IIO_TEMP)
			*val = -50 * 32 * 4;
		else
			*val = -24 * 16 * 16;
		return IIO_VAL_INT;
	default:
		break;
	}

	return -EINVAL;
}

__attribute__((used)) static int si7005_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	struct iio_dev *indio_dev;
	struct si7005_data *data;
	int ret;

	if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_WORD_DATA))
		return -EOPNOTSUPP;

	indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
	if (!indio_dev)
		return -ENOMEM;

	data = iio_priv(indio_dev);
	i2c_set_clientdata(client, indio_dev);
	data->client = client;
	mutex_init(&data->lock);

	indio_dev->dev.parent = &client->dev;
	indio_dev->name = dev_name(&client->dev);
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->info = &si7005_info;

	indio_dev->channels = si7005_channels;
	indio_dev->num_channels = ARRAY_SIZE(si7005_channels);

	ret = i2c_smbus_read_byte_data(client, SI7005_ID);
	if (ret < 0)
		return ret;
	if (ret != SI7005_ID_7005 && ret != SI7005_ID_7015)
		return -ENODEV;

	ret = i2c_smbus_read_byte_data(client, SI7005_CONFIG);
	if (ret < 0)
		return ret;
	data->config = ret;

	return devm_iio_device_register(&client->dev, indio_dev);
}

