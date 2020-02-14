#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u16 ;
struct rfd77402_data {int /*<<< orphan*/  lock; struct i2c_client* client; } ;
struct TYPE_5__ {int /*<<< orphan*/ * parent; } ;
struct iio_dev {int num_channels; int /*<<< orphan*/  modes; int /*<<< orphan*/  name; TYPE_2__* channels; int /*<<< orphan*/ * info; TYPE_1__ dev; } ;
struct iio_chan_spec {int dummy; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;
struct TYPE_6__ {int val; int /*<<< orphan*/  reg; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_2__*) ; 
 int EINVAL ; 
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ETIMEDOUT ; 
#define  IIO_CHAN_INFO_RAW 129 
#define  IIO_CHAN_INFO_SCALE 128 
 int IIO_VAL_INT ; 
 int IIO_VAL_INT_PLUS_MICRO ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int RFD77402_CMD_MCPU_OFF ; 
 int RFD77402_CMD_MCPU_ON ; 
 int /*<<< orphan*/  RFD77402_CMD_R ; 
 int RFD77402_CMD_SINGLE ; 
 int RFD77402_CMD_STANDBY ; 
 int RFD77402_CMD_VALID ; 
 int /*<<< orphan*/  RFD77402_DRV_NAME ; 
 int RFD77402_I2C_ADDR_INCR ; 
 int RFD77402_I2C_DATA_INCR ; 
 int RFD77402_I2C_HOST_DEBUG ; 
 int /*<<< orphan*/  RFD77402_I2C_INIT_CFG ; 
 int RFD77402_I2C_MCPU_DEBUG ; 
 int /*<<< orphan*/  RFD77402_ICSR ; 
 int RFD77402_ICSR_INT_MODE ; 
 int RFD77402_ICSR_RESULT ; 
 int /*<<< orphan*/  RFD77402_MOD_CHIP_ID ; 
 int /*<<< orphan*/  RFD77402_PMU_CFG ; 
 int RFD77402_RESULT_DIST_MASK ; 
 int RFD77402_RESULT_ERR_MASK ; 
 int /*<<< orphan*/  RFD77402_RESULT_R ; 
 int RFD77402_RESULT_VALID ; 
 int RFD77402_STATUS_MCPU_OFF ; 
 int RFD77402_STATUS_MCPU_ON ; 
 int RFD77402_STATUS_PM_MASK ; 
 int /*<<< orphan*/  RFD77402_STATUS_R ; 
 int RFD77402_STATUS_STANDBY ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 struct iio_dev* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_read_word_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 int i2c_smbus_write_word_data (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 struct rfd77402_data* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 TYPE_2__* rf77402_tof_config ; 
 TYPE_2__* rfd77402_channels ; 
 int /*<<< orphan*/  rfd77402_info ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static int rfd77402_set_state(struct rfd77402_data *data, u8 state, u16 check)
{
	int ret;

	ret = i2c_smbus_write_byte_data(data->client, RFD77402_CMD_R,
					state | RFD77402_CMD_VALID);
	if (ret < 0)
		return ret;

	usleep_range(10000, 20000);

	ret = i2c_smbus_read_word_data(data->client, RFD77402_STATUS_R);
	if (ret < 0)
		return ret;
	if ((ret & RFD77402_STATUS_PM_MASK) != check)
		return -ENODEV;

	return 0;
}

__attribute__((used)) static int rfd77402_measure(struct rfd77402_data *data)
{
	int ret;
	int tries = 10;

	ret = rfd77402_set_state(data, RFD77402_CMD_MCPU_ON,
				 RFD77402_STATUS_MCPU_ON);
	if (ret < 0)
		return ret;

	ret = i2c_smbus_write_byte_data(data->client, RFD77402_CMD_R,
					RFD77402_CMD_SINGLE |
					RFD77402_CMD_VALID);
	if (ret < 0)
		goto err;

	while (tries-- > 0) {
		ret = i2c_smbus_read_byte_data(data->client, RFD77402_ICSR);
		if (ret < 0)
			goto err;
		if (ret & RFD77402_ICSR_RESULT)
			break;
		msleep(20);
	}

	if (tries < 0) {
		ret = -ETIMEDOUT;
		goto err;
	}

	ret = i2c_smbus_read_word_data(data->client, RFD77402_RESULT_R);
	if (ret < 0)
		goto err;

	if ((ret & RFD77402_RESULT_ERR_MASK) ||
	    !(ret & RFD77402_RESULT_VALID)) {
		ret = -EIO;
		goto err;
	}

	return (ret & RFD77402_RESULT_DIST_MASK) >> 2;

err:
	rfd77402_set_state(data, RFD77402_CMD_MCPU_OFF,
			   RFD77402_STATUS_MCPU_OFF);
	return ret;
}

__attribute__((used)) static int rfd77402_read_raw(struct iio_dev *indio_dev,
			     struct iio_chan_spec const *chan,
			     int *val, int *val2, long mask)
{
	struct rfd77402_data *data = iio_priv(indio_dev);
	int ret;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		mutex_lock(&data->lock);
		ret = rfd77402_measure(data);
		mutex_unlock(&data->lock);
		if (ret < 0)
			return ret;
		*val = ret;
		return IIO_VAL_INT;
	case IIO_CHAN_INFO_SCALE:
		/* 1 LSB is 1 mm */
		*val = 0;
		*val2 = 1000;
		return IIO_VAL_INT_PLUS_MICRO;
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int rfd77402_init(struct rfd77402_data *data)
{
	int ret, i;

	ret = rfd77402_set_state(data, RFD77402_CMD_STANDBY,
				 RFD77402_STATUS_STANDBY);
	if (ret < 0)
		return ret;

	/* configure INT pad as push-pull, active low */
	ret = i2c_smbus_write_byte_data(data->client, RFD77402_ICSR,
					RFD77402_ICSR_INT_MODE);
	if (ret < 0)
		return ret;

	/* I2C configuration */
	ret = i2c_smbus_write_word_data(data->client, RFD77402_I2C_INIT_CFG,
					RFD77402_I2C_ADDR_INCR |
					RFD77402_I2C_DATA_INCR |
					RFD77402_I2C_HOST_DEBUG	|
					RFD77402_I2C_MCPU_DEBUG);
	if (ret < 0)
		return ret;

	/* set initialization */
	ret = i2c_smbus_write_word_data(data->client, RFD77402_PMU_CFG, 0x0500);
	if (ret < 0)
		return ret;

	ret = rfd77402_set_state(data, RFD77402_CMD_MCPU_OFF,
				 RFD77402_STATUS_MCPU_OFF);
	if (ret < 0)
		return ret;

	/* set initialization */
	ret = i2c_smbus_write_word_data(data->client, RFD77402_PMU_CFG, 0x0600);
	if (ret < 0)
		return ret;

	ret = rfd77402_set_state(data, RFD77402_CMD_MCPU_ON,
				 RFD77402_STATUS_MCPU_ON);
	if (ret < 0)
		return ret;

	for (i = 0; i < ARRAY_SIZE(rf77402_tof_config); i++) {
		ret = i2c_smbus_write_word_data(data->client,
						rf77402_tof_config[i].reg,
						rf77402_tof_config[i].val);
		if (ret < 0)
			return ret;
	}

	ret = rfd77402_set_state(data, RFD77402_CMD_STANDBY,
				 RFD77402_STATUS_STANDBY);

	return ret;
}

__attribute__((used)) static int rfd77402_powerdown(struct rfd77402_data *data)
{
	return rfd77402_set_state(data, RFD77402_CMD_STANDBY,
				  RFD77402_STATUS_STANDBY);
}

__attribute__((used)) static int rfd77402_probe(struct i2c_client *client,
			  const struct i2c_device_id *id)
{
	struct rfd77402_data *data;
	struct iio_dev *indio_dev;
	int ret;

	ret = i2c_smbus_read_word_data(client, RFD77402_MOD_CHIP_ID);
	if (ret < 0)
		return ret;
	if (ret != 0xad01 && ret != 0xad02) /* known chip ids */
		return -ENODEV;

	indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
	if (!indio_dev)
		return -ENOMEM;

	data = iio_priv(indio_dev);
	i2c_set_clientdata(client, indio_dev);
	data->client = client;
	mutex_init(&data->lock);

	indio_dev->dev.parent = &client->dev;
	indio_dev->info = &rfd77402_info;
	indio_dev->channels = rfd77402_channels;
	indio_dev->num_channels = ARRAY_SIZE(rfd77402_channels);
	indio_dev->name = RFD77402_DRV_NAME;
	indio_dev->modes = INDIO_DIRECT_MODE;

	ret = rfd77402_init(data);
	if (ret < 0)
		return ret;

	ret = iio_device_register(indio_dev);
	if (ret)
		goto err_powerdown;

	return 0;

err_powerdown:
	rfd77402_powerdown(data);
	return ret;
}

__attribute__((used)) static int rfd77402_remove(struct i2c_client *client)
{
	struct iio_dev *indio_dev = i2c_get_clientdata(client);

	iio_device_unregister(indio_dev);
	rfd77402_powerdown(iio_priv(indio_dev));

	return 0;
}

