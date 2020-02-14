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
typedef  int u32 ;
struct mcp3422 {int config; int* pga; int id; int /*<<< orphan*/  lock; struct i2c_client* i2c; } ;
struct TYPE_5__ {int /*<<< orphan*/  of_node; TYPE_2__* parent; } ;
struct iio_dev {int* channels; int num_channels; int /*<<< orphan*/ * info; int /*<<< orphan*/  modes; int /*<<< orphan*/  name; TYPE_1__ dev; } ;
struct iio_chan_spec {int channel; } ;
struct i2c_device_id {scalar_t__ driver_data; } ;
struct TYPE_6__ {int /*<<< orphan*/  of_node; } ;
struct i2c_client {TYPE_2__ dev; int /*<<< orphan*/  adapter; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int ARRAY_SIZE (int*) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 int /*<<< orphan*/  I2C_FUNC_I2C ; 
#define  IIO_CHAN_INFO_RAW 130 
#define  IIO_CHAN_INFO_SAMP_FREQ 129 
#define  IIO_CHAN_INFO_SCALE 128 
 int IIO_VAL_INT ; 
 int IIO_VAL_INT_PLUS_MICRO ; 
 int IIO_VAL_INT_PLUS_NANO ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int MCP3422_CHANNEL (int) ; 
 int MCP3422_CHANNEL_MASK ; 
 int MCP3422_CHANNEL_VALUE (int) ; 
 int MCP3422_CONT_SAMPLING ; 
 int MCP3422_PGA (int) ; 
 int MCP3422_PGA_1 ; 
 int MCP3422_PGA_MASK ; 
 int MCP3422_PGA_VALUE (int) ; 
 size_t MCP3422_SAMPLE_RATE (int) ; 
 int MCP3422_SAMPLE_RATE_VALUE (int) ; 
 int MCP3422_SRATE_15 ; 
 int MCP3422_SRATE_240 ; 
 int MCP3422_SRATE_3 ; 
 int MCP3422_SRATE_60 ; 
 int MCP3422_SRATE_MASK ; 
 int /*<<< orphan*/  dev_name (TYPE_2__*) ; 
 struct iio_dev* dev_to_iio_dev (struct device*) ; 
 struct iio_dev* devm_iio_device_alloc (TYPE_2__*,int) ; 
 int devm_iio_device_register (TYPE_2__*,struct iio_dev*) ; 
 int /*<<< orphan*/  i2c_check_functionality (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int i2c_master_recv (struct i2c_client*,int*,int) ; 
 int i2c_master_send (struct i2c_client*,int*,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 struct mcp3422* iio_priv (struct iio_dev*) ; 
 int* mcp3421_channels ; 
 int* mcp3422_channels ; 
 int /*<<< orphan*/  mcp3422_info ; 
 int /*<<< orphan*/ * mcp3422_read_times ; 
 int* mcp3422_sample_rates ; 
 int** mcp3422_scales ; 
 int /*<<< orphan*/ * mcp3422_sign_extend ; 
 int* mcp3424_channels ; 
 int /*<<< orphan*/  msleep (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int sign_extend32 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sprintf (char*,char*,...) ; 

__attribute__((used)) static int mcp3422_update_config(struct mcp3422 *adc, u8 newconfig)
{
	int ret;

	mutex_lock(&adc->lock);

	ret = i2c_master_send(adc->i2c, &newconfig, 1);
	if (ret > 0) {
		adc->config = newconfig;
		ret = 0;
	}

	mutex_unlock(&adc->lock);

	return ret;
}

__attribute__((used)) static int mcp3422_read(struct mcp3422 *adc, int *value, u8 *config)
{
	int ret = 0;
	u8 sample_rate = MCP3422_SAMPLE_RATE(adc->config);
	u8 buf[4] = {0, 0, 0, 0};
	u32 temp;

	if (sample_rate == MCP3422_SRATE_3) {
		ret = i2c_master_recv(adc->i2c, buf, 4);
		temp = buf[0] << 16 | buf[1] << 8 | buf[2];
		*config = buf[3];
	} else {
		ret = i2c_master_recv(adc->i2c, buf, 3);
		temp = buf[0] << 8 | buf[1];
		*config = buf[2];
	}

	*value = sign_extend32(temp, mcp3422_sign_extend[sample_rate]);

	return ret;
}

__attribute__((used)) static int mcp3422_read_channel(struct mcp3422 *adc,
				struct iio_chan_spec const *channel, int *value)
{
	int ret;
	u8 config;
	u8 req_channel = channel->channel;

	if (req_channel != MCP3422_CHANNEL(adc->config)) {
		config = adc->config;
		config &= ~MCP3422_CHANNEL_MASK;
		config |= MCP3422_CHANNEL_VALUE(req_channel);
		config &= ~MCP3422_PGA_MASK;
		config |= MCP3422_PGA_VALUE(adc->pga[req_channel]);
		ret = mcp3422_update_config(adc, config);
		if (ret < 0)
			return ret;
		msleep(mcp3422_read_times[MCP3422_SAMPLE_RATE(adc->config)]);
	}

	return mcp3422_read(adc, value, &config);
}

__attribute__((used)) static int mcp3422_read_raw(struct iio_dev *iio,
			struct iio_chan_spec const *channel, int *val1,
			int *val2, long mask)
{
	struct mcp3422 *adc = iio_priv(iio);
	int err;

	u8 sample_rate = MCP3422_SAMPLE_RATE(adc->config);
	u8 pga		 = MCP3422_PGA(adc->config);

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		err = mcp3422_read_channel(adc, channel, val1);
		if (err < 0)
			return -EINVAL;
		return IIO_VAL_INT;

	case IIO_CHAN_INFO_SCALE:

		*val1 = 0;
		*val2 = mcp3422_scales[sample_rate][pga];
		return IIO_VAL_INT_PLUS_NANO;

	case IIO_CHAN_INFO_SAMP_FREQ:
		*val1 = mcp3422_sample_rates[MCP3422_SAMPLE_RATE(adc->config)];
		return IIO_VAL_INT;

	default:
		break;
	}

	return -EINVAL;
}

__attribute__((used)) static int mcp3422_write_raw(struct iio_dev *iio,
			struct iio_chan_spec const *channel, int val1,
			int val2, long mask)
{
	struct mcp3422 *adc = iio_priv(iio);
	u8 temp;
	u8 config = adc->config;
	u8 req_channel = channel->channel;
	u8 sample_rate = MCP3422_SAMPLE_RATE(config);
	u8 i;

	switch (mask) {
	case IIO_CHAN_INFO_SCALE:
		if (val1 != 0)
			return -EINVAL;

		for (i = 0; i < ARRAY_SIZE(mcp3422_scales[0]); i++) {
			if (val2 == mcp3422_scales[sample_rate][i]) {
				adc->pga[req_channel] = i;

				config &= ~MCP3422_CHANNEL_MASK;
				config |= MCP3422_CHANNEL_VALUE(req_channel);
				config &= ~MCP3422_PGA_MASK;
				config |= MCP3422_PGA_VALUE(adc->pga[req_channel]);

				return mcp3422_update_config(adc, config);
			}
		}
		return -EINVAL;

	case IIO_CHAN_INFO_SAMP_FREQ:
		switch (val1) {
		case 240:
			temp = MCP3422_SRATE_240;
			break;
		case 60:
			temp = MCP3422_SRATE_60;
			break;
		case 15:
			temp = MCP3422_SRATE_15;
			break;
		case 3:
			if (adc->id > 4)
				return -EINVAL;
			temp = MCP3422_SRATE_3;
			break;
		default:
			return -EINVAL;
		}

		config &= ~MCP3422_CHANNEL_MASK;
		config |= MCP3422_CHANNEL_VALUE(req_channel);
		config &= ~MCP3422_SRATE_MASK;
		config |= MCP3422_SAMPLE_RATE_VALUE(temp);

		return mcp3422_update_config(adc, config);

	default:
		break;
	}

	return -EINVAL;
}

__attribute__((used)) static int mcp3422_write_raw_get_fmt(struct iio_dev *indio_dev,
		struct iio_chan_spec const *chan, long mask)
{
	switch (mask) {
	case IIO_CHAN_INFO_SCALE:
		return IIO_VAL_INT_PLUS_NANO;
	case IIO_CHAN_INFO_SAMP_FREQ:
		return IIO_VAL_INT_PLUS_MICRO;
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static ssize_t mcp3422_show_samp_freqs(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct mcp3422 *adc = iio_priv(dev_to_iio_dev(dev));

	if (adc->id > 4)
		return sprintf(buf, "240 60 15\n");

	return sprintf(buf, "240 60 15 3\n");
}

__attribute__((used)) static ssize_t mcp3422_show_scales(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct mcp3422 *adc = iio_priv(dev_to_iio_dev(dev));
	u8 sample_rate = MCP3422_SAMPLE_RATE(adc->config);

	return sprintf(buf, "0.%09u 0.%09u 0.%09u 0.%09u\n",
		mcp3422_scales[sample_rate][0],
		mcp3422_scales[sample_rate][1],
		mcp3422_scales[sample_rate][2],
		mcp3422_scales[sample_rate][3]);
}

__attribute__((used)) static int mcp3422_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	struct iio_dev *indio_dev;
	struct mcp3422 *adc;
	int err;
	u8 config;

	if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C))
		return -EOPNOTSUPP;

	indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*adc));
	if (!indio_dev)
		return -ENOMEM;

	adc = iio_priv(indio_dev);
	adc->i2c = client;
	adc->id = (u8)(id->driver_data);

	mutex_init(&adc->lock);

	indio_dev->dev.parent = &client->dev;
	indio_dev->dev.of_node = client->dev.of_node;
	indio_dev->name = dev_name(&client->dev);
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->info = &mcp3422_info;

	switch (adc->id) {
	case 1:
	case 5:
		indio_dev->channels = mcp3421_channels;
		indio_dev->num_channels = ARRAY_SIZE(mcp3421_channels);
		break;
	case 2:
	case 3:
	case 6:
	case 7:
		indio_dev->channels = mcp3422_channels;
		indio_dev->num_channels = ARRAY_SIZE(mcp3422_channels);
		break;
	case 4:
	case 8:
		indio_dev->channels = mcp3424_channels;
		indio_dev->num_channels = ARRAY_SIZE(mcp3424_channels);
		break;
	}

	/* meaningful default configuration */
	config = (MCP3422_CONT_SAMPLING
		| MCP3422_CHANNEL_VALUE(0)
		| MCP3422_PGA_VALUE(MCP3422_PGA_1)
		| MCP3422_SAMPLE_RATE_VALUE(MCP3422_SRATE_240));
	err = mcp3422_update_config(adc, config);
	if (err < 0)
		return err;

	err = devm_iio_device_register(&client->dev, indio_dev);
	if (err < 0)
		return err;

	i2c_set_clientdata(client, indio_dev);

	return 0;
}

