#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct vcnl4200_channel {int /*<<< orphan*/  reg; int /*<<< orphan*/  lock; void* last_measurement; void* sampling_rate; } ;
struct vcnl4000_data {size_t id; int rev; int al_scale; TYPE_2__* chip_spec; struct i2c_client* client; struct vcnl4200_channel vcnl4200_ps; struct vcnl4200_channel vcnl4200_al; int /*<<< orphan*/  vcnl4000_lock; } ;
struct TYPE_3__ {int /*<<< orphan*/ * parent; } ;
struct iio_dev {int /*<<< orphan*/  modes; int /*<<< orphan*/  name; int /*<<< orphan*/  num_channels; int /*<<< orphan*/  channels; int /*<<< orphan*/ * info; TYPE_1__ dev; } ;
struct iio_chan_spec {int const type; } ;
struct i2c_device_id {size_t driver_data; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;
typedef  scalar_t__ s64 ;
typedef  int /*<<< orphan*/  ktime_t ;
typedef  int /*<<< orphan*/  buf ;
typedef  int /*<<< orphan*/  __be16 ;
struct TYPE_4__ {int (* measure_light ) (struct vcnl4000_data*,int*) ;int (* measure_proximity ) (struct vcnl4000_data*,int*) ;int (* init ) (struct vcnl4000_data*) ;int /*<<< orphan*/  prod; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
#define  IIO_CHAN_INFO_RAW 133 
#define  IIO_CHAN_INFO_SCALE 132 
#define  IIO_LIGHT 131 
#define  IIO_PROXIMITY 130 
 int IIO_VAL_INT ; 
 int IIO_VAL_INT_PLUS_MICRO ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 size_t VCNL4000 ; 
 int VCNL4000_AL_OD ; 
 int VCNL4000_AL_RDY ; 
 int VCNL4000_AL_RESULT_HI ; 
 int /*<<< orphan*/  VCNL4000_COMMAND ; 
 int /*<<< orphan*/  VCNL4000_DRV_NAME ; 
#define  VCNL4000_PROD_ID 129 
 int /*<<< orphan*/  VCNL4000_PROD_REV ; 
 int VCNL4000_PS_OD ; 
 int VCNL4000_PS_RDY ; 
 int VCNL4000_PS_RESULT_HI ; 
 size_t VCNL4010 ; 
#define  VCNL4010_PROD_ID 128 
 int /*<<< orphan*/  VCNL4200_AL_CONF ; 
 int /*<<< orphan*/  VCNL4200_AL_DATA ; 
 int /*<<< orphan*/  VCNL4200_DEV_ID ; 
 int VCNL4200_PROD_ID ; 
 int /*<<< orphan*/  VCNL4200_PS_CONF1 ; 
 int /*<<< orphan*/  VCNL4200_PS_DATA ; 
 int be16_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*) ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 int devm_iio_device_register (int /*<<< orphan*/ *,struct iio_dev*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_read_i2c_block_data (struct i2c_client*,int,int,int*) ; 
 int i2c_smbus_read_word_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 struct vcnl4000_data* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  ktime_add (void*,void*) ; 
 void* ktime_get () ; 
 void* ktime_set (int /*<<< orphan*/ ,int) ; 
 scalar_t__ ktime_us_delta (int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int stub1 (struct vcnl4000_data*,int*) ; 
 int stub2 (struct vcnl4000_data*,int*) ; 
 int stub3 (struct vcnl4000_data*) ; 
 int /*<<< orphan*/  usleep_range (scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  vcnl4000_channels ; 
 TYPE_2__* vcnl4000_chip_spec_cfg ; 
 int /*<<< orphan*/  vcnl4000_info ; 

__attribute__((used)) static int vcnl4000_init(struct vcnl4000_data *data)
{
	int ret, prod_id;

	ret = i2c_smbus_read_byte_data(data->client, VCNL4000_PROD_REV);
	if (ret < 0)
		return ret;

	prod_id = ret >> 4;
	switch (prod_id) {
	case VCNL4000_PROD_ID:
		if (data->id != VCNL4000)
			dev_warn(&data->client->dev,
					"wrong device id, use vcnl4000");
		break;
	case VCNL4010_PROD_ID:
		if (data->id != VCNL4010)
			dev_warn(&data->client->dev,
					"wrong device id, use vcnl4010/4020");
		break;
	default:
		return -ENODEV;
	}

	data->rev = ret & 0xf;
	data->al_scale = 250000;
	mutex_init(&data->vcnl4000_lock);

	return 0;
}

__attribute__((used)) static int vcnl4200_init(struct vcnl4000_data *data)
{
	int ret;

	ret = i2c_smbus_read_word_data(data->client, VCNL4200_DEV_ID);
	if (ret < 0)
		return ret;

	if ((ret & 0xff) != VCNL4200_PROD_ID)
		return -ENODEV;

	data->rev = (ret >> 8) & 0xf;

	/* Set defaults and enable both channels */
	ret = i2c_smbus_write_byte_data(data->client, VCNL4200_AL_CONF, 0x00);
	if (ret < 0)
		return ret;
	ret = i2c_smbus_write_byte_data(data->client, VCNL4200_PS_CONF1, 0x00);
	if (ret < 0)
		return ret;

	data->al_scale = 24000;
	data->vcnl4200_al.reg = VCNL4200_AL_DATA;
	data->vcnl4200_ps.reg = VCNL4200_PS_DATA;
	/* Integration time is 50ms, but the experiments show 54ms in total. */
	data->vcnl4200_al.sampling_rate = ktime_set(0, 54000 * 1000);
	data->vcnl4200_ps.sampling_rate = ktime_set(0, 4200 * 1000);
	data->vcnl4200_al.last_measurement = ktime_set(0, 0);
	data->vcnl4200_ps.last_measurement = ktime_set(0, 0);
	mutex_init(&data->vcnl4200_al.lock);
	mutex_init(&data->vcnl4200_ps.lock);

	return 0;
}

__attribute__((used)) static int vcnl4000_measure(struct vcnl4000_data *data, u8 req_mask,
				u8 rdy_mask, u8 data_reg, int *val)
{
	int tries = 20;
	__be16 buf;
	int ret;

	mutex_lock(&data->vcnl4000_lock);

	ret = i2c_smbus_write_byte_data(data->client, VCNL4000_COMMAND,
					req_mask);
	if (ret < 0)
		goto fail;

	/* wait for data to become ready */
	while (tries--) {
		ret = i2c_smbus_read_byte_data(data->client, VCNL4000_COMMAND);
		if (ret < 0)
			goto fail;
		if (ret & rdy_mask)
			break;
		msleep(20); /* measurement takes up to 100 ms */
	}

	if (tries < 0) {
		dev_err(&data->client->dev,
			"vcnl4000_measure() failed, data not ready\n");
		ret = -EIO;
		goto fail;
	}

	ret = i2c_smbus_read_i2c_block_data(data->client,
		data_reg, sizeof(buf), (u8 *) &buf);
	if (ret < 0)
		goto fail;

	mutex_unlock(&data->vcnl4000_lock);
	*val = be16_to_cpu(buf);

	return 0;

fail:
	mutex_unlock(&data->vcnl4000_lock);
	return ret;
}

__attribute__((used)) static int vcnl4200_measure(struct vcnl4000_data *data,
		struct vcnl4200_channel *chan, int *val)
{
	int ret;
	s64 delta;
	ktime_t next_measurement;

	mutex_lock(&chan->lock);

	next_measurement = ktime_add(chan->last_measurement,
			chan->sampling_rate);
	delta = ktime_us_delta(next_measurement, ktime_get());
	if (delta > 0)
		usleep_range(delta, delta + 500);
	chan->last_measurement = ktime_get();

	mutex_unlock(&chan->lock);

	ret = i2c_smbus_read_word_data(data->client, chan->reg);
	if (ret < 0)
		return ret;

	*val = ret;

	return 0;
}

__attribute__((used)) static int vcnl4000_measure_light(struct vcnl4000_data *data, int *val)
{
	return vcnl4000_measure(data,
			VCNL4000_AL_OD, VCNL4000_AL_RDY,
			VCNL4000_AL_RESULT_HI, val);
}

__attribute__((used)) static int vcnl4200_measure_light(struct vcnl4000_data *data, int *val)
{
	return vcnl4200_measure(data, &data->vcnl4200_al, val);
}

__attribute__((used)) static int vcnl4000_measure_proximity(struct vcnl4000_data *data, int *val)
{
	return vcnl4000_measure(data,
			VCNL4000_PS_OD, VCNL4000_PS_RDY,
			VCNL4000_PS_RESULT_HI, val);
}

__attribute__((used)) static int vcnl4200_measure_proximity(struct vcnl4000_data *data, int *val)
{
	return vcnl4200_measure(data, &data->vcnl4200_ps, val);
}

__attribute__((used)) static int vcnl4000_read_raw(struct iio_dev *indio_dev,
				struct iio_chan_spec const *chan,
				int *val, int *val2, long mask)
{
	int ret;
	struct vcnl4000_data *data = iio_priv(indio_dev);

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		switch (chan->type) {
		case IIO_LIGHT:
			ret = data->chip_spec->measure_light(data, val);
			if (ret < 0)
				return ret;
			return IIO_VAL_INT;
		case IIO_PROXIMITY:
			ret = data->chip_spec->measure_proximity(data, val);
			if (ret < 0)
				return ret;
			return IIO_VAL_INT;
		default:
			return -EINVAL;
		}
	case IIO_CHAN_INFO_SCALE:
		if (chan->type != IIO_LIGHT)
			return -EINVAL;

		*val = 0;
		*val2 = data->al_scale;
		return IIO_VAL_INT_PLUS_MICRO;
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int vcnl4000_probe(struct i2c_client *client,
			  const struct i2c_device_id *id)
{
	struct vcnl4000_data *data;
	struct iio_dev *indio_dev;
	int ret;

	indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
	if (!indio_dev)
		return -ENOMEM;

	data = iio_priv(indio_dev);
	i2c_set_clientdata(client, indio_dev);
	data->client = client;
	data->id = id->driver_data;
	data->chip_spec = &vcnl4000_chip_spec_cfg[data->id];

	ret = data->chip_spec->init(data);
	if (ret < 0)
		return ret;

	dev_dbg(&client->dev, "%s Ambient light/proximity sensor, Rev: %02x\n",
		data->chip_spec->prod, data->rev);

	indio_dev->dev.parent = &client->dev;
	indio_dev->info = &vcnl4000_info;
	indio_dev->channels = vcnl4000_channels;
	indio_dev->num_channels = ARRAY_SIZE(vcnl4000_channels);
	indio_dev->name = VCNL4000_DRV_NAME;
	indio_dev->modes = INDIO_DIRECT_MODE;

	return devm_iio_device_register(&client->dev, indio_dev);
}

