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
typedef  int u16 ;
struct TYPE_2__ {int /*<<< orphan*/ * parent; } ;
struct iio_dev {int /*<<< orphan*/ * info; int /*<<< orphan*/  modes; int /*<<< orphan*/  name; int /*<<< orphan*/  num_channels; int /*<<< orphan*/  channels; TYPE_1__ dev; } ;
struct iio_chan_spec {int type; int channel; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; scalar_t__ irq; } ;
struct apds9300_data {int power_state; int thresh_low; int thresh_hi; int intr_en; int /*<<< orphan*/  mutex; struct i2c_client* client; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  enum iio_event_type { ____Placeholder_iio_event_type } iio_event_type ;
typedef  enum iio_event_info { ____Placeholder_iio_event_info } iio_event_info ;
typedef  enum iio_event_direction { ____Placeholder_iio_event_direction } iio_event_direction ;

/* Variables and functions */
 int APDS9300_CLEAR ; 
 int APDS9300_CMD ; 
 int APDS9300_CONTROL ; 
 int APDS9300_DATA0LOW ; 
 int APDS9300_DATA1LOW ; 
 int /*<<< orphan*/  APDS9300_DRV_NAME ; 
 int APDS9300_INTERRUPT ; 
 int APDS9300_INTR_ENABLE ; 
 int /*<<< orphan*/  APDS9300_IRQ_NAME ; 
 int APDS9300_POWER_OFF ; 
 int APDS9300_POWER_ON ; 
 int APDS9300_THRESHHIGHLOW ; 
 int APDS9300_THRESHLOWLOW ; 
 int APDS9300_THRESH_INTR ; 
 int APDS9300_THRESH_MAX ; 
 int APDS9300_WORD ; 
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 unsigned long DIV_ROUND_UP (int,int) ; 
 scalar_t__ DIV_ROUND_UP_ULL (int,int) ; 
 int EBUSY ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  IIO_EV_DIR_EITHER ; 
#define  IIO_EV_DIR_FALLING 131 
#define  IIO_EV_DIR_RISING 130 
 int /*<<< orphan*/  IIO_EV_TYPE_THRESH ; 
#define  IIO_INTENSITY 129 
#define  IIO_LIGHT 128 
 int /*<<< orphan*/  IIO_UNMOD_EVENT_CODE (int const,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int IIO_VAL_INT ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int IRQF_ONESHOT ; 
 int IRQF_TRIGGER_FALLING ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  apds9300_channels ; 
 int /*<<< orphan*/  apds9300_info ; 
 int /*<<< orphan*/  apds9300_info_no_irq ; 
 int* apds9300_lux_ratio ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 int devm_request_threaded_irq (int /*<<< orphan*/ *,scalar_t__,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int,int /*<<< orphan*/ ,struct iio_dev*) ; 
 struct iio_dev* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int) ; 
 int i2c_smbus_read_word_data (struct i2c_client*,int) ; 
 int i2c_smbus_write_byte (struct i2c_client*,int) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int,int) ; 
 int i2c_smbus_write_word_data (struct i2c_client*,int,int) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_get_time_ns (struct iio_dev*) ; 
 struct apds9300_data* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_push_event (struct iio_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static unsigned long apds9300_calculate_lux(u16 ch0, u16 ch1)
{
	unsigned long lux, tmp;

	/* avoid division by zero */
	if (ch0 == 0)
		return 0;

	tmp = DIV_ROUND_UP(ch1 * 100, ch0);
	if (tmp <= 52) {
		lux = 3150 * ch0 - (unsigned long)DIV_ROUND_UP_ULL(ch0
				* apds9300_lux_ratio[tmp] * 5930ull, 1000);
	} else if (tmp <= 65) {
		lux = 2290 * ch0 - 2910 * ch1;
	} else if (tmp <= 80) {
		lux = 1570 * ch0 - 1800 * ch1;
	} else if (tmp <= 130) {
		lux = 338 * ch0 - 260 * ch1;
	} else {
		lux = 0;
	}

	return lux / 100000;
}

__attribute__((used)) static int apds9300_get_adc_val(struct apds9300_data *data, int adc_number)
{
	int ret;
	u8 flags = APDS9300_CMD | APDS9300_WORD;

	if (!data->power_state)
		return -EBUSY;

	/* Select ADC0 or ADC1 data register */
	flags |= adc_number ? APDS9300_DATA1LOW : APDS9300_DATA0LOW;

	ret = i2c_smbus_read_word_data(data->client, flags);
	if (ret < 0)
		dev_err(&data->client->dev,
			"failed to read ADC%d value\n", adc_number);

	return ret;
}

__attribute__((used)) static int apds9300_set_thresh_low(struct apds9300_data *data, int value)
{
	int ret;

	if (!data->power_state)
		return -EBUSY;

	if (value > APDS9300_THRESH_MAX)
		return -EINVAL;

	ret = i2c_smbus_write_word_data(data->client, APDS9300_THRESHLOWLOW
			| APDS9300_CMD | APDS9300_WORD, value);
	if (ret) {
		dev_err(&data->client->dev, "failed to set thresh_low\n");
		return ret;
	}
	data->thresh_low = value;

	return 0;
}

__attribute__((used)) static int apds9300_set_thresh_hi(struct apds9300_data *data, int value)
{
	int ret;

	if (!data->power_state)
		return -EBUSY;

	if (value > APDS9300_THRESH_MAX)
		return -EINVAL;

	ret = i2c_smbus_write_word_data(data->client, APDS9300_THRESHHIGHLOW
			| APDS9300_CMD | APDS9300_WORD, value);
	if (ret) {
		dev_err(&data->client->dev, "failed to set thresh_hi\n");
		return ret;
	}
	data->thresh_hi = value;

	return 0;
}

__attribute__((used)) static int apds9300_set_intr_state(struct apds9300_data *data, int state)
{
	int ret;
	u8 cmd;

	if (!data->power_state)
		return -EBUSY;

	cmd = state ? APDS9300_INTR_ENABLE | APDS9300_THRESH_INTR : 0x00;
	ret = i2c_smbus_write_byte_data(data->client,
			APDS9300_INTERRUPT | APDS9300_CMD, cmd);
	if (ret) {
		dev_err(&data->client->dev,
			"failed to set interrupt state %d\n", state);
		return ret;
	}
	data->intr_en = state;

	return 0;
}

__attribute__((used)) static int apds9300_set_power_state(struct apds9300_data *data, int state)
{
	int ret;
	u8 cmd;

	cmd = state ? APDS9300_POWER_ON : APDS9300_POWER_OFF;
	ret = i2c_smbus_write_byte_data(data->client,
			APDS9300_CONTROL | APDS9300_CMD, cmd);
	if (ret) {
		dev_err(&data->client->dev,
			"failed to set power state %d\n", state);
		return ret;
	}
	data->power_state = state;

	return 0;
}

__attribute__((used)) static void apds9300_clear_intr(struct apds9300_data *data)
{
	int ret;

	ret = i2c_smbus_write_byte(data->client, APDS9300_CLEAR | APDS9300_CMD);
	if (ret < 0)
		dev_err(&data->client->dev, "failed to clear interrupt\n");
}

__attribute__((used)) static int apds9300_chip_init(struct apds9300_data *data)
{
	int ret;

	/* Need to set power off to ensure that the chip is off */
	ret = apds9300_set_power_state(data, 0);
	if (ret < 0)
		goto err;
	/*
	 * Probe the chip. To do so we try to power up the device and then to
	 * read back the 0x03 code
	 */
	ret = apds9300_set_power_state(data, 1);
	if (ret < 0)
		goto err;
	ret = i2c_smbus_read_byte_data(data->client,
			APDS9300_CONTROL | APDS9300_CMD);
	if (ret != APDS9300_POWER_ON) {
		ret = -ENODEV;
		goto err;
	}
	/*
	 * Disable interrupt to ensure thai it is doesn't enable
	 * i.e. after device soft reset
	 */
	ret = apds9300_set_intr_state(data, 0);
	if (ret < 0)
		goto err;

	return 0;

err:
	dev_err(&data->client->dev, "failed to init the chip\n");
	return ret;
}

__attribute__((used)) static int apds9300_read_raw(struct iio_dev *indio_dev,
		struct iio_chan_spec const *chan, int *val, int *val2,
		long mask)
{
	int ch0, ch1, ret = -EINVAL;
	struct apds9300_data *data = iio_priv(indio_dev);

	mutex_lock(&data->mutex);
	switch (chan->type) {
	case IIO_LIGHT:
		ch0 = apds9300_get_adc_val(data, 0);
		if (ch0 < 0) {
			ret = ch0;
			break;
		}
		ch1 = apds9300_get_adc_val(data, 1);
		if (ch1 < 0) {
			ret = ch1;
			break;
		}
		*val = apds9300_calculate_lux(ch0, ch1);
		ret = IIO_VAL_INT;
		break;
	case IIO_INTENSITY:
		ret = apds9300_get_adc_val(data, chan->channel);
		if (ret < 0)
			break;
		*val = ret;
		ret = IIO_VAL_INT;
		break;
	default:
		break;
	}
	mutex_unlock(&data->mutex);

	return ret;
}

__attribute__((used)) static int apds9300_read_thresh(struct iio_dev *indio_dev,
		const struct iio_chan_spec *chan, enum iio_event_type type,
		enum iio_event_direction dir, enum iio_event_info info,
		int *val, int *val2)
{
	struct apds9300_data *data = iio_priv(indio_dev);

	switch (dir) {
	case IIO_EV_DIR_RISING:
		*val = data->thresh_hi;
		break;
	case IIO_EV_DIR_FALLING:
		*val = data->thresh_low;
		break;
	default:
		return -EINVAL;
	}

	return IIO_VAL_INT;
}

__attribute__((used)) static int apds9300_write_thresh(struct iio_dev *indio_dev,
		const struct iio_chan_spec *chan, enum iio_event_type type,
		enum iio_event_direction dir, enum iio_event_info info, int val,
		int val2)
{
	struct apds9300_data *data = iio_priv(indio_dev);
	int ret;

	mutex_lock(&data->mutex);
	if (dir == IIO_EV_DIR_RISING)
		ret = apds9300_set_thresh_hi(data, val);
	else
		ret = apds9300_set_thresh_low(data, val);
	mutex_unlock(&data->mutex);

	return ret;
}

__attribute__((used)) static int apds9300_read_interrupt_config(struct iio_dev *indio_dev,
		const struct iio_chan_spec *chan,
		enum iio_event_type type,
		enum iio_event_direction dir)
{
	struct apds9300_data *data = iio_priv(indio_dev);

	return data->intr_en;
}

__attribute__((used)) static int apds9300_write_interrupt_config(struct iio_dev *indio_dev,
		const struct iio_chan_spec *chan, enum iio_event_type type,
		enum iio_event_direction dir, int state)
{
	struct apds9300_data *data = iio_priv(indio_dev);
	int ret;

	mutex_lock(&data->mutex);
	ret = apds9300_set_intr_state(data, state);
	mutex_unlock(&data->mutex);

	return ret;
}

__attribute__((used)) static irqreturn_t apds9300_interrupt_handler(int irq, void *private)
{
	struct iio_dev *dev_info = private;
	struct apds9300_data *data = iio_priv(dev_info);

	iio_push_event(dev_info,
		       IIO_UNMOD_EVENT_CODE(IIO_INTENSITY, 0,
					    IIO_EV_TYPE_THRESH,
					    IIO_EV_DIR_EITHER),
		       iio_get_time_ns(dev_info));

	apds9300_clear_intr(data);

	return IRQ_HANDLED;
}

__attribute__((used)) static int apds9300_probe(struct i2c_client *client,
		const struct i2c_device_id *id)
{
	struct apds9300_data *data;
	struct iio_dev *indio_dev;
	int ret;

	indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
	if (!indio_dev)
		return -ENOMEM;

	data = iio_priv(indio_dev);
	i2c_set_clientdata(client, indio_dev);
	data->client = client;

	ret = apds9300_chip_init(data);
	if (ret < 0)
		goto err;

	mutex_init(&data->mutex);

	indio_dev->dev.parent = &client->dev;
	indio_dev->channels = apds9300_channels;
	indio_dev->num_channels = ARRAY_SIZE(apds9300_channels);
	indio_dev->name = APDS9300_DRV_NAME;
	indio_dev->modes = INDIO_DIRECT_MODE;

	if (client->irq)
		indio_dev->info = &apds9300_info;
	else
		indio_dev->info = &apds9300_info_no_irq;

	if (client->irq) {
		ret = devm_request_threaded_irq(&client->dev, client->irq,
				NULL, apds9300_interrupt_handler,
				IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
				APDS9300_IRQ_NAME, indio_dev);
		if (ret) {
			dev_err(&client->dev, "irq request error %d\n", -ret);
			goto err;
		}
	}

	ret = iio_device_register(indio_dev);
	if (ret < 0)
		goto err;

	return 0;

err:
	/* Ensure that power off in case of error */
	apds9300_set_power_state(data, 0);
	return ret;
}

__attribute__((used)) static int apds9300_remove(struct i2c_client *client)
{
	struct iio_dev *indio_dev = i2c_get_clientdata(client);
	struct apds9300_data *data = iio_priv(indio_dev);

	iio_device_unregister(indio_dev);

	/* Ensure that power off and interrupts are disabled */
	apds9300_set_intr_state(data, 0);
	apds9300_set_power_state(data, 0);

	return 0;
}

