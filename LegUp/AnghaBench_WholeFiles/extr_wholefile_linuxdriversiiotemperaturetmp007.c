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
struct tmp007_data {int config; int status_mask; struct i2c_client* client; int /*<<< orphan*/  lock; } ;
struct TYPE_2__ {int /*<<< orphan*/ * parent; } ;
struct iio_dev {char* name; int** channels; int num_channels; int /*<<< orphan*/ * info; int /*<<< orphan*/  modes; TYPE_1__ dev; } ;
struct iio_chan_spec {int channel2; } ;
struct i2c_device_id {int /*<<< orphan*/  name; } ;
struct i2c_client {int /*<<< orphan*/  dev; scalar_t__ irq; int /*<<< orphan*/  adapter; } ;
typedef  int s32 ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  enum iio_event_type { ____Placeholder_iio_event_type } iio_event_type ;
typedef  enum iio_event_info { ____Placeholder_iio_event_info } iio_event_info ;
typedef  enum iio_event_direction { ____Placeholder_iio_event_direction } iio_event_direction ;

/* Variables and functions */
 int ARRAY_SIZE (int**) ; 
 int EINVAL ; 
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_WORD_DATA ; 
#define  IIO_CHAN_INFO_RAW 132 
#define  IIO_CHAN_INFO_SAMP_FREQ 131 
#define  IIO_CHAN_INFO_SCALE 130 
 int IIO_EV_DIR_FALLING ; 
 int IIO_EV_DIR_RISING ; 
 int /*<<< orphan*/  IIO_EV_TYPE_THRESH ; 
 int /*<<< orphan*/  IIO_MOD_EVENT_CODE (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int const,int /*<<< orphan*/ ,int) ; 
#define  IIO_MOD_TEMP_AMBIENT 129 
#define  IIO_MOD_TEMP_OBJECT 128 
 int /*<<< orphan*/  IIO_TEMP ; 
 int IIO_VAL_INT ; 
 int IIO_VAL_INT_PLUS_MICRO ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int IRQF_ONESHOT ; 
 int IRQF_TRIGGER_FALLING ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 int /*<<< orphan*/  TMP007_CONFIG ; 
 int TMP007_CONFIG_ALERT_EN ; 
 int TMP007_CONFIG_CONV_EN ; 
 int TMP007_CONFIG_CR_MASK ; 
 int TMP007_CONFIG_CR_SHIFT ; 
 int TMP007_CONFIG_TC_EN ; 
 int /*<<< orphan*/  TMP007_DEVICE_ID ; 
 int TMP007_DEVICE_MAGIC ; 
 int /*<<< orphan*/  TMP007_MANUFACTURER_ID ; 
 int TMP007_MANUFACTURER_MAGIC ; 
 int /*<<< orphan*/  TMP007_STATUS ; 
 int TMP007_STATUS_CONV_READY ; 
 int TMP007_STATUS_DATA_VALID ; 
 int TMP007_STATUS_LHF ; 
 int TMP007_STATUS_LLF ; 
 int /*<<< orphan*/  TMP007_STATUS_MASK ; 
 int TMP007_STATUS_OHF ; 
 int TMP007_STATUS_OLF ; 
 int /*<<< orphan*/  TMP007_TDIE ; 
 int /*<<< orphan*/  TMP007_TDIE_HIGH_LIMIT ; 
 int /*<<< orphan*/  TMP007_TDIE_LOW_LIMIT ; 
 int TMP007_TEMP_SHIFT ; 
 int /*<<< orphan*/  TMP007_TOBJECT ; 
 int /*<<< orphan*/  TMP007_TOBJ_HIGH_LIMIT ; 
 int /*<<< orphan*/  TMP007_TOBJ_LOW_LIMIT ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 int devm_request_threaded_irq (int /*<<< orphan*/ *,scalar_t__,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int,int /*<<< orphan*/ ,struct iio_dev*) ; 
 int /*<<< orphan*/  i2c_check_functionality (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct iio_dev* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 int i2c_smbus_read_word_swapped (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_write_word_swapped (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_get_time_ns (struct iio_dev*) ; 
 struct tmp007_data* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_push_event (struct iio_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int sign_extend32 (int,int) ; 
 int** tmp007_avgs ; 
 int** tmp007_channels ; 
 int /*<<< orphan*/  tmp007_info ; 

__attribute__((used)) static int tmp007_read_temperature(struct tmp007_data *data, u8 reg)
{
	s32 ret;
	int tries = 50;

	while (tries-- > 0) {
		ret = i2c_smbus_read_word_swapped(data->client,
			TMP007_STATUS);
		if (ret < 0)
			return ret;
		if ((ret & TMP007_STATUS_CONV_READY) &&
			!(ret & TMP007_STATUS_DATA_VALID))
				break;
		msleep(100);
	}

	if (tries < 0)
		return -EIO;

	return i2c_smbus_read_word_swapped(data->client, reg);
}

__attribute__((used)) static int tmp007_powerdown(struct tmp007_data *data)
{
	return i2c_smbus_write_word_swapped(data->client, TMP007_CONFIG,
			data->config & ~TMP007_CONFIG_CONV_EN);
}

__attribute__((used)) static int tmp007_read_raw(struct iio_dev *indio_dev,
		struct iio_chan_spec const *channel, int *val,
		int *val2, long mask)
{
	struct tmp007_data *data = iio_priv(indio_dev);
	s32 ret;
	int conv_rate;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		switch (channel->channel2) {
		case IIO_MOD_TEMP_AMBIENT: /* LSB: 0.03125 degree Celsius */
			ret = i2c_smbus_read_word_swapped(data->client, TMP007_TDIE);
			if (ret < 0)
				return ret;
			break;
		case IIO_MOD_TEMP_OBJECT:
			ret = tmp007_read_temperature(data, TMP007_TOBJECT);
			if (ret < 0)
				return ret;
			break;
		default:
			return -EINVAL;
		}

		*val = sign_extend32(ret, 15) >> TMP007_TEMP_SHIFT;

		return IIO_VAL_INT;
	case IIO_CHAN_INFO_SCALE:
		*val = 31;
		*val2 = 250000;

		return IIO_VAL_INT_PLUS_MICRO;
	case IIO_CHAN_INFO_SAMP_FREQ:
		conv_rate = (data->config & TMP007_CONFIG_CR_MASK)
				>> TMP007_CONFIG_CR_SHIFT;
		*val = tmp007_avgs[conv_rate][0];
		*val2 = tmp007_avgs[conv_rate][1];

		return IIO_VAL_INT_PLUS_MICRO;
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int tmp007_write_raw(struct iio_dev *indio_dev,
		struct iio_chan_spec const *channel, int val,
		int val2, long mask)
{
	struct tmp007_data *data = iio_priv(indio_dev);
	int i;
	u16 tmp;

	if (mask == IIO_CHAN_INFO_SAMP_FREQ) {
		for (i = 0; i < ARRAY_SIZE(tmp007_avgs); i++) {
			if ((val == tmp007_avgs[i][0]) &&
			(val2 == tmp007_avgs[i][1])) {
				tmp = data->config & ~TMP007_CONFIG_CR_MASK;
				tmp |= (i << TMP007_CONFIG_CR_SHIFT);

				return i2c_smbus_write_word_swapped(data->client,
								TMP007_CONFIG,
								data->config = tmp);
			}
		}
	}

	return -EINVAL;
}

__attribute__((used)) static irqreturn_t tmp007_interrupt_handler(int irq, void *private)
{
	struct iio_dev *indio_dev = private;
	struct tmp007_data *data = iio_priv(indio_dev);
	int ret;

	ret = i2c_smbus_read_word_swapped(data->client, TMP007_STATUS);
	if ((ret < 0) || !(ret & (TMP007_STATUS_OHF | TMP007_STATUS_OLF |
				TMP007_STATUS_LHF | TMP007_STATUS_LLF)))
		return IRQ_NONE;

	if (ret & TMP007_STATUS_OHF)
		iio_push_event(indio_dev,
				IIO_MOD_EVENT_CODE(IIO_TEMP, 0,
					IIO_MOD_TEMP_OBJECT,
					IIO_EV_TYPE_THRESH,
					IIO_EV_DIR_RISING),
				iio_get_time_ns(indio_dev));

	if (ret & TMP007_STATUS_OLF)
		iio_push_event(indio_dev,
				IIO_MOD_EVENT_CODE(IIO_TEMP, 0,
					IIO_MOD_TEMP_OBJECT,
					IIO_EV_TYPE_THRESH,
					IIO_EV_DIR_FALLING),
				iio_get_time_ns(indio_dev));

	if (ret & TMP007_STATUS_LHF)
		iio_push_event(indio_dev,
				IIO_MOD_EVENT_CODE(IIO_TEMP, 0,
					IIO_MOD_TEMP_AMBIENT,
					IIO_EV_TYPE_THRESH,
					IIO_EV_DIR_RISING),
				iio_get_time_ns(indio_dev));

	if (ret & TMP007_STATUS_LLF)
		iio_push_event(indio_dev,
				IIO_MOD_EVENT_CODE(IIO_TEMP, 0,
					IIO_MOD_TEMP_AMBIENT,
					IIO_EV_TYPE_THRESH,
					IIO_EV_DIR_FALLING),
				iio_get_time_ns(indio_dev));

	return IRQ_HANDLED;
}

__attribute__((used)) static int tmp007_write_event_config(struct iio_dev *indio_dev,
		const struct iio_chan_spec *chan, enum iio_event_type type,
		enum iio_event_direction dir, int state)
{
	struct tmp007_data *data = iio_priv(indio_dev);
	unsigned int status_mask;
	int ret;

	switch (chan->channel2) {
	case IIO_MOD_TEMP_AMBIENT:
	if (dir == IIO_EV_DIR_RISING)
			status_mask = TMP007_STATUS_LHF;
		else
			status_mask = TMP007_STATUS_LLF;
		break;
	case IIO_MOD_TEMP_OBJECT:
		if (dir == IIO_EV_DIR_RISING)
			status_mask = TMP007_STATUS_OHF;
		else
			status_mask = TMP007_STATUS_OLF;
		break;
	default:
		return -EINVAL;
	}

	mutex_lock(&data->lock);
	ret = i2c_smbus_read_word_swapped(data->client, TMP007_STATUS_MASK);
	mutex_unlock(&data->lock);
	if (ret < 0)
		return ret;

	if (state)
		ret |= status_mask;
	else
		ret &= ~status_mask;

	return i2c_smbus_write_word_swapped(data->client, TMP007_STATUS_MASK,
					data->status_mask = ret);
}

__attribute__((used)) static int tmp007_read_event_config(struct iio_dev *indio_dev,
		const struct iio_chan_spec *chan, enum iio_event_type type,
		enum iio_event_direction dir)
{
	struct tmp007_data *data = iio_priv(indio_dev);
	unsigned int mask;

	switch (chan->channel2) {
	case IIO_MOD_TEMP_AMBIENT:
		if (dir == IIO_EV_DIR_RISING)
			mask = TMP007_STATUS_LHF;
		else
			mask = TMP007_STATUS_LLF;
		break;
	case IIO_MOD_TEMP_OBJECT:
		if (dir == IIO_EV_DIR_RISING)
			mask = TMP007_STATUS_OHF;
		else
			mask = TMP007_STATUS_OLF;
		break;
	default:
		return -EINVAL;
	}

	return !!(data->status_mask & mask);
}

__attribute__((used)) static int tmp007_read_thresh(struct iio_dev *indio_dev,
		const struct iio_chan_spec *chan, enum iio_event_type type,
		enum iio_event_direction dir, enum iio_event_info info,
		int *val, int *val2)
{
	struct tmp007_data *data = iio_priv(indio_dev);
	int ret;
	u8 reg;

	switch (chan->channel2) {
	case IIO_MOD_TEMP_AMBIENT: /* LSB: 0.5 degree Celsius */
		if (dir == IIO_EV_DIR_RISING)
			reg = TMP007_TDIE_HIGH_LIMIT;
		else
			reg = TMP007_TDIE_LOW_LIMIT;
		break;
	case IIO_MOD_TEMP_OBJECT:
		if (dir == IIO_EV_DIR_RISING)
			reg = TMP007_TOBJ_HIGH_LIMIT;
	else
			reg = TMP007_TOBJ_LOW_LIMIT;
		break;
	default:
		return -EINVAL;
	}

	ret = i2c_smbus_read_word_swapped(data->client, reg);
	if (ret < 0)
		return ret;

	/* Shift length 7 bits = 6(15:6) + 1(0.5 LSB) */
	*val = sign_extend32(ret, 15) >> 7;

	return IIO_VAL_INT;
}

__attribute__((used)) static int tmp007_write_thresh(struct iio_dev *indio_dev,
		const struct iio_chan_spec *chan, enum iio_event_type type,
		enum iio_event_direction dir, enum iio_event_info info,
		int val, int val2)
{
	struct tmp007_data *data = iio_priv(indio_dev);
	u8 reg;

	switch (chan->channel2) {
	case IIO_MOD_TEMP_AMBIENT:
		if (dir == IIO_EV_DIR_RISING)
			reg = TMP007_TDIE_HIGH_LIMIT;
		else
			reg = TMP007_TDIE_LOW_LIMIT;
		break;
	case IIO_MOD_TEMP_OBJECT:
		if (dir == IIO_EV_DIR_RISING)
			reg = TMP007_TOBJ_HIGH_LIMIT;
		else
			reg = TMP007_TOBJ_LOW_LIMIT;
		break;
	default:
		return -EINVAL;
	}

	/* Full scale threshold value is +/- 256 degree Celsius */
	if (val < -256 || val > 255)
		return -EINVAL;

	/* Shift length 7 bits = 6(15:6) + 1(0.5 LSB) */
	return i2c_smbus_write_word_swapped(data->client, reg, (val << 7));
}

__attribute__((used)) static bool tmp007_identify(struct i2c_client *client)
{
	int manf_id, dev_id;

	manf_id = i2c_smbus_read_word_swapped(client, TMP007_MANUFACTURER_ID);
	if (manf_id < 0)
		return false;

	dev_id = i2c_smbus_read_word_swapped(client, TMP007_DEVICE_ID);
	if (dev_id < 0)
		return false;

	return (manf_id == TMP007_MANUFACTURER_MAGIC && dev_id == TMP007_DEVICE_MAGIC);
}

__attribute__((used)) static int tmp007_probe(struct i2c_client *client,
			const struct i2c_device_id *tmp007_id)
{
	struct tmp007_data *data;
	struct iio_dev *indio_dev;
	int ret;

	if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_WORD_DATA))
		return -EOPNOTSUPP;

	if (!tmp007_identify(client)) {
		dev_err(&client->dev, "TMP007 not found\n");
		return -ENODEV;
	}

	indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
	if (!indio_dev)
		return -ENOMEM;

	data = iio_priv(indio_dev);
	i2c_set_clientdata(client, indio_dev);
	data->client = client;
	mutex_init(&data->lock);

	indio_dev->dev.parent = &client->dev;
	indio_dev->name = "tmp007";
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->info = &tmp007_info;

	indio_dev->channels = tmp007_channels;
	indio_dev->num_channels = ARRAY_SIZE(tmp007_channels);

	/*
	 * Set Configuration register:
	 * 1. Conversion ON
	 * 2. ALERT enable
	 * 3. Transient correction enable
	 */

	ret = i2c_smbus_read_word_swapped(data->client, TMP007_CONFIG);
	if (ret < 0)
		return ret;

	data->config = ret;
	data->config |= (TMP007_CONFIG_CONV_EN | TMP007_CONFIG_ALERT_EN | TMP007_CONFIG_TC_EN);

	ret = i2c_smbus_write_word_swapped(data->client, TMP007_CONFIG,
					data->config);
	if (ret < 0)
		return ret;

	/*
	 * Only the following flags can activate ALERT pin. Data conversion/validity flags
	 * flags can still be polled for getting temperature data
	 *
	 * Set Status Mask register:
	 * 1. Object temperature high limit enable
	 * 2. Object temperature low limit enable
	 * 3. TDIE temperature high limit enable
	 * 4. TDIE temperature low limit enable
	 */

	ret = i2c_smbus_read_word_swapped(data->client, TMP007_STATUS_MASK);
	if (ret < 0)
		goto error_powerdown;

	data->status_mask = ret;
	data->status_mask |= (TMP007_STATUS_OHF | TMP007_STATUS_OLF
				| TMP007_STATUS_LHF | TMP007_STATUS_LLF);

	ret = i2c_smbus_write_word_swapped(data->client, TMP007_STATUS_MASK, data->status_mask);
	if (ret < 0)
		goto error_powerdown;

	if (client->irq) {
		ret = devm_request_threaded_irq(&client->dev, client->irq,
				NULL, tmp007_interrupt_handler,
				IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
				tmp007_id->name, indio_dev);
		if (ret) {
			dev_err(&client->dev, "irq request error %d\n", -ret);
			goto error_powerdown;
		}
	}

	return iio_device_register(indio_dev);

error_powerdown:
	tmp007_powerdown(data);

	return ret;
}

__attribute__((used)) static int tmp007_remove(struct i2c_client *client)
{
	struct iio_dev *indio_dev = i2c_get_clientdata(client);
	struct tmp007_data *data = iio_priv(indio_dev);

	iio_device_unregister(indio_dev);
	tmp007_powerdown(data);

	return 0;
}

