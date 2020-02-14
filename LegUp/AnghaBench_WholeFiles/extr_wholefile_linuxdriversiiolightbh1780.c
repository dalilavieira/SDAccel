#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_17__   TYPE_2__ ;
typedef  struct TYPE_16__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct TYPE_16__ {TYPE_2__* parent; } ;
struct iio_dev {char* name; int /*<<< orphan*/  modes; int /*<<< orphan*/  num_channels; int /*<<< orphan*/  channels; int /*<<< orphan*/ * info; TYPE_1__ dev; } ;
struct iio_chan_spec {int /*<<< orphan*/  type; } ;
struct i2c_device_id {int dummy; } ;
struct TYPE_17__ {int /*<<< orphan*/  parent; } ;
struct i2c_client {TYPE_2__ dev; } ;
struct i2c_adapter {int dummy; } ;
struct bh1780_data {struct i2c_client* client; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int BH1780_CMD_BIT ; 
 int BH1780_INTERVAL ; 
 int BH1780_POFF ; 
 int BH1780_PON ; 
 int /*<<< orphan*/  BH1780_PON_DELAY ; 
 int BH1780_REG_CONTROL ; 
 int BH1780_REG_DLOW ; 
 int BH1780_REG_PARTID ; 
 int BH1780_REVMASK ; 
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_BYTE ; 
#define  IIO_CHAN_INFO_INT_TIME 130 
#define  IIO_CHAN_INFO_RAW 129 
#define  IIO_LIGHT 128 
 int IIO_VAL_INT ; 
 int IIO_VAL_INT_PLUS_MICRO ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int /*<<< orphan*/  bh1780_channels ; 
 int /*<<< orphan*/  bh1780_info ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*,...) ; 
 int /*<<< orphan*/  dev_info (TYPE_2__*,char*,int) ; 
 struct iio_dev* devm_iio_device_alloc (TYPE_2__*,int) ; 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int /*<<< orphan*/ ) ; 
 struct iio_dev* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int) ; 
 int i2c_smbus_read_word_data (struct i2c_client*,int) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int,int) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 struct bh1780_data* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  msleep (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pm_runtime_disable (TYPE_2__*) ; 
 int /*<<< orphan*/  pm_runtime_enable (TYPE_2__*) ; 
 int /*<<< orphan*/  pm_runtime_get_noresume (TYPE_2__*) ; 
 int /*<<< orphan*/  pm_runtime_get_sync (TYPE_2__*) ; 
 int /*<<< orphan*/  pm_runtime_mark_last_busy (TYPE_2__*) ; 
 int /*<<< orphan*/  pm_runtime_put (TYPE_2__*) ; 
 int /*<<< orphan*/  pm_runtime_put_autosuspend (TYPE_2__*) ; 
 int /*<<< orphan*/  pm_runtime_put_noidle (TYPE_2__*) ; 
 int /*<<< orphan*/  pm_runtime_set_active (TYPE_2__*) ; 
 int /*<<< orphan*/  pm_runtime_set_autosuspend_delay (TYPE_2__*,int) ; 
 int /*<<< orphan*/  pm_runtime_use_autosuspend (TYPE_2__*) ; 
 struct i2c_adapter* to_i2c_adapter (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int bh1780_write(struct bh1780_data *bh1780, u8 reg, u8 val)
{
	int ret = i2c_smbus_write_byte_data(bh1780->client,
					    BH1780_CMD_BIT | reg,
					    val);
	if (ret < 0)
		dev_err(&bh1780->client->dev,
			"i2c_smbus_write_byte_data failed error "
			"%d, register %01x\n",
			ret, reg);
	return ret;
}

__attribute__((used)) static int bh1780_read(struct bh1780_data *bh1780, u8 reg)
{
	int ret = i2c_smbus_read_byte_data(bh1780->client,
					   BH1780_CMD_BIT | reg);
	if (ret < 0)
		dev_err(&bh1780->client->dev,
			"i2c_smbus_read_byte_data failed error "
			"%d, register %01x\n",
			ret, reg);
	return ret;
}

__attribute__((used)) static int bh1780_read_word(struct bh1780_data *bh1780, u8 reg)
{
	int ret = i2c_smbus_read_word_data(bh1780->client,
					   BH1780_CMD_BIT | reg);
	if (ret < 0)
		dev_err(&bh1780->client->dev,
			"i2c_smbus_read_word_data failed error "
			"%d, register %01x\n",
			ret, reg);
	return ret;
}

__attribute__((used)) static int bh1780_debugfs_reg_access(struct iio_dev *indio_dev,
			      unsigned int reg, unsigned int writeval,
			      unsigned int *readval)
{
	struct bh1780_data *bh1780 = iio_priv(indio_dev);
	int ret;

	if (!readval)
		return bh1780_write(bh1780, (u8)reg, (u8)writeval);

	ret = bh1780_read(bh1780, (u8)reg);
	if (ret < 0)
		return ret;

	*readval = ret;

	return 0;
}

__attribute__((used)) static int bh1780_read_raw(struct iio_dev *indio_dev,
			   struct iio_chan_spec const *chan,
			   int *val, int *val2, long mask)
{
	struct bh1780_data *bh1780 = iio_priv(indio_dev);
	int value;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		switch (chan->type) {
		case IIO_LIGHT:
			pm_runtime_get_sync(&bh1780->client->dev);
			value = bh1780_read_word(bh1780, BH1780_REG_DLOW);
			if (value < 0)
				return value;
			pm_runtime_mark_last_busy(&bh1780->client->dev);
			pm_runtime_put_autosuspend(&bh1780->client->dev);
			*val = value;

			return IIO_VAL_INT;
		default:
			return -EINVAL;
		}
	case IIO_CHAN_INFO_INT_TIME:
		*val = 0;
		*val2 = BH1780_INTERVAL * 1000;
		return IIO_VAL_INT_PLUS_MICRO;
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int bh1780_probe(struct i2c_client *client,
			const struct i2c_device_id *id)
{
	int ret;
	struct bh1780_data *bh1780;
	struct i2c_adapter *adapter = to_i2c_adapter(client->dev.parent);
	struct iio_dev *indio_dev;

	if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE))
		return -EIO;

	indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*bh1780));
	if (!indio_dev)
		return -ENOMEM;

	bh1780 = iio_priv(indio_dev);
	bh1780->client = client;
	i2c_set_clientdata(client, indio_dev);

	/* Power up the device */
	ret = bh1780_write(bh1780, BH1780_REG_CONTROL, BH1780_PON);
	if (ret < 0)
		return ret;
	msleep(BH1780_PON_DELAY);
	pm_runtime_get_noresume(&client->dev);
	pm_runtime_set_active(&client->dev);
	pm_runtime_enable(&client->dev);

	ret = bh1780_read(bh1780, BH1780_REG_PARTID);
	if (ret < 0)
		goto out_disable_pm;
	dev_info(&client->dev,
		 "Ambient Light Sensor, Rev : %lu\n",
		 (ret & BH1780_REVMASK));

	/*
	 * As the device takes 250 ms to even come up with a fresh
	 * measurement after power-on, do not shut it down unnecessarily.
	 * Set autosuspend to a five seconds.
	 */
	pm_runtime_set_autosuspend_delay(&client->dev, 5000);
	pm_runtime_use_autosuspend(&client->dev);
	pm_runtime_put(&client->dev);

	indio_dev->dev.parent = &client->dev;
	indio_dev->info = &bh1780_info;
	indio_dev->name = "bh1780";
	indio_dev->channels = bh1780_channels;
	indio_dev->num_channels = ARRAY_SIZE(bh1780_channels);
	indio_dev->modes = INDIO_DIRECT_MODE;

	ret = iio_device_register(indio_dev);
	if (ret)
		goto out_disable_pm;
	return 0;

out_disable_pm:
	pm_runtime_put_noidle(&client->dev);
	pm_runtime_disable(&client->dev);
	return ret;
}

__attribute__((used)) static int bh1780_remove(struct i2c_client *client)
{
	struct iio_dev *indio_dev = i2c_get_clientdata(client);
	struct bh1780_data *bh1780 = iio_priv(indio_dev);
	int ret;

	iio_device_unregister(indio_dev);
	pm_runtime_get_sync(&client->dev);
	pm_runtime_put_noidle(&client->dev);
	pm_runtime_disable(&client->dev);
	ret = bh1780_write(bh1780, BH1780_REG_CONTROL, BH1780_POFF);
	if (ret < 0) {
		dev_err(&client->dev, "failed to power off\n");
		return ret;
	}

	return 0;
}

