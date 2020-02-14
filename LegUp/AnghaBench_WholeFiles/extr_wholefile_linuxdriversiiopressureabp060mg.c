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
typedef  int u16 ;
struct TYPE_2__ {int /*<<< orphan*/ * parent; } ;
struct iio_dev {int /*<<< orphan*/  num_channels; int /*<<< orphan*/  channels; int /*<<< orphan*/ * info; int /*<<< orphan*/  modes; int /*<<< orphan*/  name; TYPE_1__ dev; } ;
struct iio_chan_spec {int dummy; } ;
struct i2c_device_id {unsigned long driver_data; } ;
struct i2c_client {int /*<<< orphan*/  dev; int /*<<< orphan*/  adapter; } ;
struct abp_state {int mreq_len; int offset; int scale; int /*<<< orphan*/  lock; struct i2c_client* client; } ;
struct abp_config {scalar_t__ max; scalar_t__ min; } ;
typedef  int /*<<< orphan*/  buf ;
typedef  scalar_t__ __be16 ;

/* Variables and functions */
 int ABP060MG_ERROR_MASK ; 
 int ABP060MG_MAX_COUNTS ; 
 int ABP060MG_MIN_COUNTS ; 
 int ABP060MG_NUM_COUNTS ; 
 int /*<<< orphan*/  ABP060MG_RESP_TIME_MS ; 
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_QUICK ; 
#define  IIO_CHAN_INFO_OFFSET 130 
#define  IIO_CHAN_INFO_RAW 129 
#define  IIO_CHAN_INFO_SCALE 128 
 int IIO_VAL_FRACTIONAL ; 
 int IIO_VAL_INT ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int /*<<< orphan*/  abp060mg_channels ; 
 int /*<<< orphan*/  abp060mg_info ; 
 struct abp_config* abp_config ; 
 int be16_to_cpu (scalar_t__) ; 
 int /*<<< orphan*/  dev_name (int /*<<< orphan*/ *) ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 int devm_iio_device_register (int /*<<< orphan*/ *,struct iio_dev*) ; 
 int /*<<< orphan*/  i2c_check_functionality (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int i2c_master_recv (struct i2c_client*,int /*<<< orphan*/ *,int) ; 
 int i2c_master_send (struct i2c_client*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct abp_state*) ; 
 struct abp_state* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  msleep_interruptible (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int abp060mg_get_measurement(struct abp_state *state, int *val)
{
	struct i2c_client *client = state->client;
	__be16 buf[2];
	u16 pressure;
	int ret;

	buf[0] = 0;
	ret = i2c_master_send(client, (u8 *)&buf, state->mreq_len);
	if (ret < 0)
		return ret;

	msleep_interruptible(ABP060MG_RESP_TIME_MS);

	ret = i2c_master_recv(client, (u8 *)&buf, sizeof(buf));
	if (ret < 0)
		return ret;

	pressure = be16_to_cpu(buf[0]);
	if (pressure & ABP060MG_ERROR_MASK)
		return -EIO;

	if (pressure < ABP060MG_MIN_COUNTS || pressure > ABP060MG_MAX_COUNTS)
		return -EIO;

	*val = pressure;

	return IIO_VAL_INT;
}

__attribute__((used)) static int abp060mg_read_raw(struct iio_dev *indio_dev,
			struct iio_chan_spec const *chan, int *val,
			int *val2, long mask)
{
	struct abp_state *state = iio_priv(indio_dev);
	int ret;

	mutex_lock(&state->lock);

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		ret = abp060mg_get_measurement(state, val);
		break;
	case IIO_CHAN_INFO_OFFSET:
		*val = state->offset;
		ret = IIO_VAL_INT;
		break;
	case IIO_CHAN_INFO_SCALE:
		*val = state->scale;
		*val2 = ABP060MG_NUM_COUNTS * 1000; /* to kPa */
		ret = IIO_VAL_FRACTIONAL;
		break;
	default:
		ret = -EINVAL;
		break;
	}

	mutex_unlock(&state->lock);
	return ret;
}

__attribute__((used)) static void abp060mg_init_device(struct iio_dev *indio_dev, unsigned long id)
{
	struct abp_state *state = iio_priv(indio_dev);
	struct abp_config *cfg = &abp_config[id];

	state->scale = cfg->max - cfg->min;
	state->offset = -ABP060MG_MIN_COUNTS;

	if (cfg->min < 0) /* differential */
		state->offset -= ABP060MG_NUM_COUNTS >> 1;
}

__attribute__((used)) static int abp060mg_probe(struct i2c_client *client,
			const struct i2c_device_id *id)
{
	struct iio_dev *indio_dev;
	struct abp_state *state;
	unsigned long cfg_id = id->driver_data;

	indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*state));
	if (!indio_dev)
		return -ENOMEM;

	state = iio_priv(indio_dev);
	i2c_set_clientdata(client, state);
	state->client = client;

	if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_QUICK))
		state->mreq_len = 1;

	abp060mg_init_device(indio_dev, cfg_id);

	indio_dev->dev.parent = &client->dev;
	indio_dev->name = dev_name(&client->dev);
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->info = &abp060mg_info;

	indio_dev->channels = abp060mg_channels;
	indio_dev->num_channels = ARRAY_SIZE(abp060mg_channels);

	mutex_init(&state->lock);

	return devm_iio_device_register(&client->dev, indio_dev);
}

