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
typedef  int u8 ;
typedef  size_t u32 ;
struct max5821_data {int* powerdown_mode; int* powerdown; int vref_mv; int /*<<< orphan*/  vref_reg; int /*<<< orphan*/  lock; struct i2c_client* client; } ;
struct TYPE_2__ {int /*<<< orphan*/ * parent; } ;
struct iio_dev {int /*<<< orphan*/ * info; int /*<<< orphan*/  modes; int /*<<< orphan*/  channels; int /*<<< orphan*/  num_channels; TYPE_1__ dev; int /*<<< orphan*/  name; } ;
struct iio_chan_spec {size_t channel; } ;
struct i2c_device_id {int /*<<< orphan*/  name; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
#define  IIO_CHAN_INFO_RAW 129 
#define  IIO_CHAN_INFO_SCALE 128 
 int IIO_VAL_FRACTIONAL_LOG2 ; 
 int IIO_VAL_INT ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int MAX5821_100KOHM_TO_GND ; 
 int MAX5821_EXTENDED_COMMAND_MODE ; 
 int MAX5821_EXTENDED_DAC_A ; 
 int MAX5821_EXTENDED_DAC_B ; 
 int MAX5821_EXTENDED_POWER_UP ; 
 size_t MAX5821_MAX_DAC_CHANNELS ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int) ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  devm_regulator_get (int /*<<< orphan*/ *,char*) ; 
 struct iio_dev* i2c_get_clientdata (struct i2c_client*) ; 
 int i2c_master_recv (struct i2c_client*,int*,int) ; 
 int i2c_master_send (struct i2c_client*,int*,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 struct max5821_data* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  max5821_channels ; 
 int /*<<< orphan*/  max5821_info ; 
 int* max5821_load_dac_command ; 
 int* max5821_read_dac_command ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  regulator_disable (int /*<<< orphan*/ ) ; 
 int regulator_enable (int /*<<< orphan*/ ) ; 
 int regulator_get_voltage (int /*<<< orphan*/ ) ; 
 int sprintf (char*,char*,int) ; 
 int strtobool (char const*,int*) ; 

__attribute__((used)) static int max5821_get_powerdown_mode(struct iio_dev *indio_dev,
				      const struct iio_chan_spec *chan)
{
	struct max5821_data *st = iio_priv(indio_dev);

	return st->powerdown_mode[chan->channel];
}

__attribute__((used)) static int max5821_set_powerdown_mode(struct iio_dev *indio_dev,
				      const struct iio_chan_spec *chan,
				      unsigned int mode)
{
	struct max5821_data *st = iio_priv(indio_dev);

	st->powerdown_mode[chan->channel] = mode;

	return 0;
}

__attribute__((used)) static ssize_t max5821_read_dac_powerdown(struct iio_dev *indio_dev,
					  uintptr_t private,
					  const struct iio_chan_spec *chan,
					  char *buf)
{
	struct max5821_data *st = iio_priv(indio_dev);

	return sprintf(buf, "%d\n", st->powerdown[chan->channel]);
}

__attribute__((used)) static int max5821_sync_powerdown_mode(struct max5821_data *data,
				       const struct iio_chan_spec *chan)
{
	u8 outbuf[2];

	outbuf[0] = MAX5821_EXTENDED_COMMAND_MODE;

	if (chan->channel == 0)
		outbuf[1] = MAX5821_EXTENDED_DAC_A;
	else
		outbuf[1] = MAX5821_EXTENDED_DAC_B;

	if (data->powerdown[chan->channel])
		outbuf[1] |= data->powerdown_mode[chan->channel] + 1;
	else
		outbuf[1] |= MAX5821_EXTENDED_POWER_UP;

	return i2c_master_send(data->client, outbuf, 2);
}

__attribute__((used)) static ssize_t max5821_write_dac_powerdown(struct iio_dev *indio_dev,
					   uintptr_t private,
					   const struct iio_chan_spec *chan,
					   const char *buf, size_t len)
{
	struct max5821_data *data = iio_priv(indio_dev);
	bool powerdown;
	int ret;

	ret = strtobool(buf, &powerdown);
	if (ret)
		return ret;

	data->powerdown[chan->channel] = powerdown;

	ret = max5821_sync_powerdown_mode(data, chan);
	if (ret < 0)
		return ret;

	return len;
}

__attribute__((used)) static int max5821_get_value(struct iio_dev *indio_dev,
			     int *val, int channel)
{
	struct max5821_data *data = iio_priv(indio_dev);
	struct i2c_client *client = data->client;
	u8 outbuf[1];
	u8 inbuf[2];
	int ret;

	if ((channel != 0) && (channel != 1))
		return -EINVAL;

	outbuf[0] = max5821_read_dac_command[channel];

	mutex_lock(&data->lock);

	ret = i2c_master_send(client, outbuf, 1);
	if (ret < 0) {
		mutex_unlock(&data->lock);
		return ret;
	} else if (ret != 1) {
		mutex_unlock(&data->lock);
		return -EIO;
	}

	ret = i2c_master_recv(client, inbuf, 2);
	if (ret < 0) {
		mutex_unlock(&data->lock);
		return ret;
	} else if (ret != 2) {
		mutex_unlock(&data->lock);
		return -EIO;
	}

	mutex_unlock(&data->lock);

	*val = ((inbuf[0] & 0x0f) << 6) | (inbuf[1] >> 2);

	return IIO_VAL_INT;
}

__attribute__((used)) static int max5821_set_value(struct iio_dev *indio_dev,
			     int val, int channel)
{
	struct max5821_data *data = iio_priv(indio_dev);
	struct i2c_client *client = data->client;
	u8 outbuf[2];
	int ret;

	if ((val < 0) || (val > 1023))
		return -EINVAL;

	if ((channel != 0) && (channel != 1))
		return -EINVAL;

	outbuf[0] = max5821_load_dac_command[channel];
	outbuf[0] |= val >> 6;
	outbuf[1] = (val & 0x3f) << 2;

	ret = i2c_master_send(client, outbuf, 2);
	if (ret < 0)
		return ret;
	else if (ret != 2)
		return -EIO;
	else
		return 0;
}

__attribute__((used)) static int max5821_read_raw(struct iio_dev *indio_dev,
			   struct iio_chan_spec const *chan,
			   int *val, int *val2, long mask)
{
	struct max5821_data *data = iio_priv(indio_dev);

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		return max5821_get_value(indio_dev, val, chan->channel);
	case IIO_CHAN_INFO_SCALE:
		*val = data->vref_mv;
		*val2 = 10;
		return IIO_VAL_FRACTIONAL_LOG2;
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int max5821_write_raw(struct iio_dev *indio_dev,
			     struct iio_chan_spec const *chan,
			     int val, int val2, long mask)
{
	if (val2 != 0)
		return -EINVAL;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		return max5821_set_value(indio_dev, val, chan->channel);
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int max5821_probe(struct i2c_client *client,
			const struct i2c_device_id *id)
{
	struct max5821_data *data;
	struct iio_dev *indio_dev;
	u32 tmp;
	int ret;

	indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
	if (!indio_dev)
		return -ENOMEM;
	data = iio_priv(indio_dev);
	i2c_set_clientdata(client, indio_dev);
	data->client = client;
	mutex_init(&data->lock);

	/* max5821 start in powerdown mode 100Kohm to ground */
	for (tmp = 0; tmp < MAX5821_MAX_DAC_CHANNELS; tmp++) {
		data->powerdown[tmp] = true;
		data->powerdown_mode[tmp] = MAX5821_100KOHM_TO_GND;
	}

	data->vref_reg = devm_regulator_get(&client->dev, "vref");
	if (IS_ERR(data->vref_reg)) {
		ret = PTR_ERR(data->vref_reg);
		dev_err(&client->dev,
			"Failed to get vref regulator: %d\n", ret);
		goto error_free_reg;
	}

	ret = regulator_enable(data->vref_reg);
	if (ret) {
		dev_err(&client->dev,
			"Failed to enable vref regulator: %d\n", ret);
		goto error_free_reg;
	}

	ret = regulator_get_voltage(data->vref_reg);
	if (ret < 0) {
		dev_err(&client->dev,
			"Failed to get voltage on regulator: %d\n", ret);
		goto error_disable_reg;
	}

	data->vref_mv = ret / 1000;

	indio_dev->name = id->name;
	indio_dev->dev.parent = &client->dev;
	indio_dev->num_channels = ARRAY_SIZE(max5821_channels);
	indio_dev->channels = max5821_channels;
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->info = &max5821_info;

	return iio_device_register(indio_dev);

error_disable_reg:
	regulator_disable(data->vref_reg);

error_free_reg:

	return ret;
}

__attribute__((used)) static int max5821_remove(struct i2c_client *client)
{
	struct iio_dev *indio_dev = i2c_get_clientdata(client);
	struct max5821_data *data = iio_priv(indio_dev);

	iio_device_unregister(indio_dev);
	regulator_disable(data->vref_reg);

	return 0;
}

