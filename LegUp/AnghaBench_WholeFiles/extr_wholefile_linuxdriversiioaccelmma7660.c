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
typedef  int /*<<< orphan*/  u8 ;
struct mma7660_data {int mode; int /*<<< orphan*/  lock; struct i2c_client* client; } ;
struct TYPE_2__ {int /*<<< orphan*/ * parent; } ;
struct iio_dev {int /*<<< orphan*/  num_channels; int /*<<< orphan*/  channels; int /*<<< orphan*/  modes; int /*<<< orphan*/  name; int /*<<< orphan*/ * info; TYPE_1__ dev; } ;
struct iio_chan_spec {int /*<<< orphan*/  address; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;
typedef  enum mma7660_mode { ____Placeholder_mma7660_mode } mma7660_mode ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int ETIMEDOUT ; 
#define  IIO_CHAN_INFO_RAW 129 
#define  IIO_CHAN_INFO_SCALE 128 
 int IIO_VAL_INT ; 
 int IIO_VAL_INT_PLUS_NANO ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int /*<<< orphan*/  MMA7660_DRIVER_NAME ; 
 int MMA7660_I2C_READ_RETRIES ; 
 int MMA7660_MODE_ACTIVE ; 
 void* MMA7660_MODE_STANDBY ; 
 int /*<<< orphan*/  MMA7660_REG_MODE ; 
 int MMA7660_REG_MODE_BIT_MODE ; 
 int MMA7660_REG_MODE_BIT_TON ; 
 int MMA7660_REG_OUT_BIT_ALERT ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 struct iio_dev* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 struct mma7660_data* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  mma7660_channels ; 
 int /*<<< orphan*/  mma7660_info ; 
 int mma7660_nscale ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int sign_extend32 (int,int) ; 

__attribute__((used)) static int mma7660_set_mode(struct mma7660_data *data,
				enum mma7660_mode mode)
{
	int ret;
	struct i2c_client *client = data->client;

	if (mode == data->mode)
		return 0;

	ret = i2c_smbus_read_byte_data(client, MMA7660_REG_MODE);
	if (ret < 0) {
		dev_err(&client->dev, "failed to read sensor mode\n");
		return ret;
	}

	if (mode == MMA7660_MODE_ACTIVE) {
		ret &= ~MMA7660_REG_MODE_BIT_TON;
		ret |= MMA7660_REG_MODE_BIT_MODE;
	} else {
		ret &= ~MMA7660_REG_MODE_BIT_TON;
		ret &= ~MMA7660_REG_MODE_BIT_MODE;
	}

	ret = i2c_smbus_write_byte_data(client, MMA7660_REG_MODE, ret);
	if (ret < 0) {
		dev_err(&client->dev, "failed to change sensor mode\n");
		return ret;
	}

	data->mode = mode;

	return ret;
}

__attribute__((used)) static int mma7660_read_accel(struct mma7660_data *data, u8 address)
{
	int ret, retries = MMA7660_I2C_READ_RETRIES;
	struct i2c_client *client = data->client;

	/*
	 * Read data. If the Alert bit is set, the register was read at
	 * the same time as the device was attempting to update the content.
	 * The solution is to read the register again. Do this only
	 * MMA7660_I2C_READ_RETRIES times to avoid spending too much time
	 * in the kernel.
	 */
	do {
		ret = i2c_smbus_read_byte_data(client, address);
		if (ret < 0) {
			dev_err(&client->dev, "register read failed\n");
			return ret;
		}
	} while (retries-- > 0 && ret & MMA7660_REG_OUT_BIT_ALERT);

	if (ret & MMA7660_REG_OUT_BIT_ALERT) {
		dev_err(&client->dev, "all register read retries failed\n");
		return -ETIMEDOUT;
	}

	return ret;
}

__attribute__((used)) static int mma7660_read_raw(struct iio_dev *indio_dev,
				struct iio_chan_spec const *chan,
				int *val, int *val2, long mask)
{
	struct mma7660_data *data = iio_priv(indio_dev);
	int ret;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		mutex_lock(&data->lock);
		ret = mma7660_read_accel(data, chan->address);
		mutex_unlock(&data->lock);
		if (ret < 0)
			return ret;
		*val = sign_extend32(ret, 5);
		return IIO_VAL_INT;
	case IIO_CHAN_INFO_SCALE:
		*val = 0;
		*val2 = mma7660_nscale;
		return IIO_VAL_INT_PLUS_NANO;
	default:
		return -EINVAL;
	}

	return -EINVAL;
}

__attribute__((used)) static int mma7660_probe(struct i2c_client *client,
			const struct i2c_device_id *id)
{
	int ret;
	struct iio_dev *indio_dev;
	struct mma7660_data *data;

	indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
	if (!indio_dev) {
		dev_err(&client->dev, "iio allocation failed!\n");
		return -ENOMEM;
	}

	data = iio_priv(indio_dev);
	data->client = client;
	i2c_set_clientdata(client, indio_dev);
	mutex_init(&data->lock);
	data->mode = MMA7660_MODE_STANDBY;

	indio_dev->dev.parent = &client->dev;
	indio_dev->info = &mma7660_info;
	indio_dev->name = MMA7660_DRIVER_NAME;
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->channels = mma7660_channels;
	indio_dev->num_channels = ARRAY_SIZE(mma7660_channels);

	ret = mma7660_set_mode(data, MMA7660_MODE_ACTIVE);
	if (ret < 0)
		return ret;

	ret = iio_device_register(indio_dev);
	if (ret < 0) {
		dev_err(&client->dev, "device_register failed\n");
		mma7660_set_mode(data, MMA7660_MODE_STANDBY);
	}

	return ret;
}

__attribute__((used)) static int mma7660_remove(struct i2c_client *client)
{
	struct iio_dev *indio_dev = i2c_get_clientdata(client);

	iio_device_unregister(indio_dev);

	return mma7660_set_mode(iio_priv(indio_dev), MMA7660_MODE_STANDBY);
}

