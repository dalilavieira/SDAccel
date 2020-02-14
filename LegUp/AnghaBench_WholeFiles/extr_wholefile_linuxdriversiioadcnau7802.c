#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  unsigned long long u64 ;
typedef  int u32 ;
struct nau7802_state {int* scale_avail; scalar_t__ conversion_count; int last_value; scalar_t__ sample_rate; int vref_mv; int /*<<< orphan*/  data_lock; int /*<<< orphan*/  lock; struct i2c_client* client; int /*<<< orphan*/  value_ok; } ;
struct TYPE_7__ {struct device_node* of_node; TYPE_3__* parent; } ;
struct iio_dev {int num_channels; int* channels; int /*<<< orphan*/ * info; int /*<<< orphan*/  modes; int /*<<< orphan*/  name; TYPE_1__ dev; } ;
struct iio_chan_spec {int /*<<< orphan*/  channel; } ;
struct i2c_device_id {int dummy; } ;
struct TYPE_9__ {TYPE_2__* driver; struct device_node* of_node; } ;
struct i2c_client {scalar_t__ irq; TYPE_3__ dev; } ;
struct device_node {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_8__ {int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int ARRAY_SIZE (int*) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int ETIMEDOUT ; 
#define  IIO_CHAN_INFO_RAW 130 
#define  IIO_CHAN_INFO_SAMP_FREQ 129 
#define  IIO_CHAN_INFO_SCALE 128 
 int IIO_VAL_FRACTIONAL_LOG2 ; 
 int IIO_VAL_INT ; 
 int IIO_VAL_INT_PLUS_NANO ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int IRQF_ONESHOT ; 
 int IRQF_TRIGGER_HIGH ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 int NAU7802_CTRL1_GAINS_BITS ; 
 int NAU7802_CTRL1_VLDO (int) ; 
 int NAU7802_CTRL2_CHS (int /*<<< orphan*/ ) ; 
 int NAU7802_CTRL2_CHS_BIT ; 
 int NAU7802_CTRL2_CRS (scalar_t__) ; 
 scalar_t__ NAU7802_MIN_CONVERSIONS ; 
 int NAU7802_PUCTRL_AVDDS_BIT ; 
 int NAU7802_PUCTRL_CR_BIT ; 
 int NAU7802_PUCTRL_CS_BIT ; 
 int NAU7802_PUCTRL_PUA_BIT ; 
 int NAU7802_PUCTRL_PUD_BIT ; 
 int NAU7802_PUCTRL_PUR_BIT ; 
 int NAU7802_PUCTRL_RR_BIT ; 
 int /*<<< orphan*/  NAU7802_REG_ADC_B0 ; 
 int /*<<< orphan*/  NAU7802_REG_ADC_B1 ; 
 int /*<<< orphan*/  NAU7802_REG_ADC_B2 ; 
 int /*<<< orphan*/  NAU7802_REG_ADC_CTRL ; 
 int /*<<< orphan*/  NAU7802_REG_CTRL1 ; 
 int /*<<< orphan*/  NAU7802_REG_CTRL2 ; 
 int /*<<< orphan*/  NAU7802_REG_PUCTRL ; 
 scalar_t__ NAU7802_SAMP_FREQ_320 ; 
 scalar_t__ PAGE_SIZE ; 
 int /*<<< orphan*/  complete (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_err (TYPE_3__*,char*) ; 
 int /*<<< orphan*/  dev_info (TYPE_3__*,char*) ; 
 int /*<<< orphan*/  dev_name (TYPE_3__*) ; 
 struct iio_dev* dev_to_iio_dev (struct device*) ; 
 struct iio_dev* devm_iio_device_alloc (TYPE_3__*,int) ; 
 int /*<<< orphan*/  disable_irq (scalar_t__) ; 
 int /*<<< orphan*/  enable_irq (scalar_t__) ; 
 int /*<<< orphan*/  free_irq (scalar_t__,struct iio_dev*) ; 
 struct iio_dev* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 struct nau7802_state* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  init_completion (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  msecs_to_jiffies (int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  mutex_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int* nau7802_chan_array ; 
 int /*<<< orphan*/  nau7802_info ; 
 int* nau7802_sample_freq_avail ; 
 int /*<<< orphan*/  of_property_read_u32 (struct device_node*,char*,int*) ; 
 int /*<<< orphan*/  reinit_completion (int /*<<< orphan*/ *) ; 
 int request_threaded_irq (scalar_t__,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int,int /*<<< orphan*/ ,struct iio_dev*) ; 
 scalar_t__ scnprintf (char*,scalar_t__,char*,int) ; 
 int sign_extend32 (int,int) ; 
 int /*<<< orphan*/  udelay (int) ; 
 int wait_for_completion_interruptible_timeout (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static ssize_t nau7802_show_scales(struct device *dev,
				   struct device_attribute *attr, char *buf)
{
	struct nau7802_state *st = iio_priv(dev_to_iio_dev(dev));
	int i, len = 0;

	for (i = 0; i < ARRAY_SIZE(st->scale_avail); i++)
		len += scnprintf(buf + len, PAGE_SIZE - len, "0.%09d ",
				 st->scale_avail[i]);

	buf[len-1] = '\n';

	return len;
}

__attribute__((used)) static int nau7802_set_gain(struct nau7802_state *st, int gain)
{
	int ret;

	mutex_lock(&st->lock);
	st->conversion_count = 0;

	ret = i2c_smbus_read_byte_data(st->client, NAU7802_REG_CTRL1);
	if (ret < 0)
		goto nau7802_sysfs_set_gain_out;
	ret = i2c_smbus_write_byte_data(st->client, NAU7802_REG_CTRL1,
					(ret & (~NAU7802_CTRL1_GAINS_BITS)) |
					gain);

nau7802_sysfs_set_gain_out:
	mutex_unlock(&st->lock);

	return ret;
}

__attribute__((used)) static int nau7802_read_conversion(struct nau7802_state *st)
{
	int data;

	mutex_lock(&st->data_lock);
	data = i2c_smbus_read_byte_data(st->client, NAU7802_REG_ADC_B2);
	if (data < 0)
		goto nau7802_read_conversion_out;
	st->last_value = data << 16;

	data = i2c_smbus_read_byte_data(st->client, NAU7802_REG_ADC_B1);
	if (data < 0)
		goto nau7802_read_conversion_out;
	st->last_value |= data << 8;

	data = i2c_smbus_read_byte_data(st->client, NAU7802_REG_ADC_B0);
	if (data < 0)
		goto nau7802_read_conversion_out;
	st->last_value |= data;

	st->last_value = sign_extend32(st->last_value, 23);

nau7802_read_conversion_out:
	mutex_unlock(&st->data_lock);

	return data;
}

__attribute__((used)) static int nau7802_sync(struct nau7802_state *st)
{
	int ret;

	ret = i2c_smbus_read_byte_data(st->client, NAU7802_REG_PUCTRL);
	if (ret < 0)
		return ret;
	ret = i2c_smbus_write_byte_data(st->client, NAU7802_REG_PUCTRL,
				ret | NAU7802_PUCTRL_CS_BIT);

	return ret;
}

__attribute__((used)) static irqreturn_t nau7802_eoc_trigger(int irq, void *private)
{
	struct iio_dev *indio_dev = private;
	struct nau7802_state *st = iio_priv(indio_dev);
	int status;

	status = i2c_smbus_read_byte_data(st->client, NAU7802_REG_PUCTRL);
	if (status < 0)
		return IRQ_HANDLED;

	if (!(status & NAU7802_PUCTRL_CR_BIT))
		return IRQ_NONE;

	if (nau7802_read_conversion(st) < 0)
		return IRQ_HANDLED;

	/*
	 * Because there is actually only one ADC for both channels, we have to
	 * wait for enough conversions to happen before getting a significant
	 * value when changing channels and the values are far apart.
	 */
	if (st->conversion_count < NAU7802_MIN_CONVERSIONS)
		st->conversion_count++;
	if (st->conversion_count >= NAU7802_MIN_CONVERSIONS)
		complete(&st->value_ok);

	return IRQ_HANDLED;
}

__attribute__((used)) static int nau7802_read_irq(struct iio_dev *indio_dev,
			struct iio_chan_spec const *chan,
			int *val)
{
	struct nau7802_state *st = iio_priv(indio_dev);
	int ret;

	reinit_completion(&st->value_ok);
	enable_irq(st->client->irq);

	nau7802_sync(st);

	/* read registers to ensure we flush everything */
	ret = nau7802_read_conversion(st);
	if (ret < 0)
		goto read_chan_info_failure;

	/* Wait for a conversion to finish */
	ret = wait_for_completion_interruptible_timeout(&st->value_ok,
			msecs_to_jiffies(1000));
	if (ret == 0)
		ret = -ETIMEDOUT;

	if (ret < 0)
		goto read_chan_info_failure;

	disable_irq(st->client->irq);

	*val = st->last_value;

	return IIO_VAL_INT;

read_chan_info_failure:
	disable_irq(st->client->irq);

	return ret;
}

__attribute__((used)) static int nau7802_read_poll(struct iio_dev *indio_dev,
			struct iio_chan_spec const *chan,
			int *val)
{
	struct nau7802_state *st = iio_priv(indio_dev);
	int ret;

	nau7802_sync(st);

	/* read registers to ensure we flush everything */
	ret = nau7802_read_conversion(st);
	if (ret < 0)
		return ret;

	/*
	 * Because there is actually only one ADC for both channels, we have to
	 * wait for enough conversions to happen before getting a significant
	 * value when changing channels and the values are far appart.
	 */
	do {
		ret = i2c_smbus_read_byte_data(st->client, NAU7802_REG_PUCTRL);
		if (ret < 0)
			return ret;

		while (!(ret & NAU7802_PUCTRL_CR_BIT)) {
			if (st->sample_rate != NAU7802_SAMP_FREQ_320)
				msleep(20);
			else
				mdelay(4);
			ret = i2c_smbus_read_byte_data(st->client,
							NAU7802_REG_PUCTRL);
			if (ret < 0)
				return ret;
		}

		ret = nau7802_read_conversion(st);
		if (ret < 0)
			return ret;
		if (st->conversion_count < NAU7802_MIN_CONVERSIONS)
			st->conversion_count++;
	} while (st->conversion_count < NAU7802_MIN_CONVERSIONS);

	*val = st->last_value;

	return IIO_VAL_INT;
}

__attribute__((used)) static int nau7802_read_raw(struct iio_dev *indio_dev,
			    struct iio_chan_spec const *chan,
			    int *val, int *val2, long mask)
{
	struct nau7802_state *st = iio_priv(indio_dev);
	int ret;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		mutex_lock(&st->lock);
		/*
		 * Select the channel to use
		 *   - Channel 1 is value 0 in the CHS register
		 *   - Channel 2 is value 1 in the CHS register
		 */
		ret = i2c_smbus_read_byte_data(st->client, NAU7802_REG_CTRL2);
		if (ret < 0) {
			mutex_unlock(&st->lock);
			return ret;
		}

		if (((ret & NAU7802_CTRL2_CHS_BIT) && !chan->channel) ||
				(!(ret & NAU7802_CTRL2_CHS_BIT) &&
				 chan->channel)) {
			st->conversion_count = 0;
			ret = i2c_smbus_write_byte_data(st->client,
					NAU7802_REG_CTRL2,
					NAU7802_CTRL2_CHS(chan->channel) |
					NAU7802_CTRL2_CRS(st->sample_rate));

			if (ret < 0) {
				mutex_unlock(&st->lock);
				return ret;
			}
		}

		if (st->client->irq)
			ret = nau7802_read_irq(indio_dev, chan, val);
		else
			ret = nau7802_read_poll(indio_dev, chan, val);

		mutex_unlock(&st->lock);
		return ret;

	case IIO_CHAN_INFO_SCALE:
		ret = i2c_smbus_read_byte_data(st->client, NAU7802_REG_CTRL1);
		if (ret < 0)
			return ret;

		/*
		 * We have 24 bits of signed data, that means 23 bits of data
		 * plus the sign bit
		 */
		*val = st->vref_mv;
		*val2 = 23 + (ret & NAU7802_CTRL1_GAINS_BITS);

		return IIO_VAL_FRACTIONAL_LOG2;

	case IIO_CHAN_INFO_SAMP_FREQ:
		*val =  nau7802_sample_freq_avail[st->sample_rate];
		*val2 = 0;
		return IIO_VAL_INT;

	default:
		break;
	}

	return -EINVAL;
}

__attribute__((used)) static int nau7802_write_raw(struct iio_dev *indio_dev,
			     struct iio_chan_spec const *chan,
			     int val, int val2, long mask)
{
	struct nau7802_state *st = iio_priv(indio_dev);
	int i, ret;

	switch (mask) {
	case IIO_CHAN_INFO_SCALE:
		for (i = 0; i < ARRAY_SIZE(st->scale_avail); i++)
			if (val2 == st->scale_avail[i])
				return nau7802_set_gain(st, i);

		break;

	case IIO_CHAN_INFO_SAMP_FREQ:
		for (i = 0; i < ARRAY_SIZE(nau7802_sample_freq_avail); i++)
			if (val == nau7802_sample_freq_avail[i]) {
				mutex_lock(&st->lock);
				st->sample_rate = i;
				st->conversion_count = 0;
				ret = i2c_smbus_write_byte_data(st->client,
					NAU7802_REG_CTRL2,
					NAU7802_CTRL2_CRS(st->sample_rate));
				mutex_unlock(&st->lock);
				return ret;
			}

		break;

	default:
		break;
	}

	return -EINVAL;
}

__attribute__((used)) static int nau7802_write_raw_get_fmt(struct iio_dev *indio_dev,
				     struct iio_chan_spec const *chan,
				     long mask)
{
	return IIO_VAL_INT_PLUS_NANO;
}

__attribute__((used)) static int nau7802_probe(struct i2c_client *client,
			const struct i2c_device_id *id)
{
	struct iio_dev *indio_dev;
	struct nau7802_state *st;
	struct device_node *np = client->dev.of_node;
	int i, ret;
	u8 data;
	u32 tmp = 0;

	if (!client->dev.of_node) {
		dev_err(&client->dev, "No device tree node available.\n");
		return -EINVAL;
	}

	indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*st));
	if (indio_dev == NULL)
		return -ENOMEM;

	st = iio_priv(indio_dev);

	i2c_set_clientdata(client, indio_dev);

	indio_dev->dev.parent = &client->dev;
	indio_dev->dev.of_node = client->dev.of_node;
	indio_dev->name = dev_name(&client->dev);
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->info = &nau7802_info;

	st->client = client;

	/* Reset the device */
	ret = i2c_smbus_write_byte_data(st->client, NAU7802_REG_PUCTRL,
				  NAU7802_PUCTRL_RR_BIT);
	if (ret < 0)
		return ret;

	/* Enter normal operation mode */
	ret = i2c_smbus_write_byte_data(st->client, NAU7802_REG_PUCTRL,
				  NAU7802_PUCTRL_PUD_BIT);
	if (ret < 0)
		return ret;

	/*
	 * After about 200 usecs, the device should be ready and then
	 * the Power Up bit will be set to 1. If not, wait for it.
	 */
	udelay(210);
	ret = i2c_smbus_read_byte_data(st->client, NAU7802_REG_PUCTRL);
	if (ret < 0)
		return ret;
	if (!(ret & NAU7802_PUCTRL_PUR_BIT))
		return ret;

	of_property_read_u32(np, "nuvoton,vldo", &tmp);
	st->vref_mv = tmp;

	data = NAU7802_PUCTRL_PUD_BIT | NAU7802_PUCTRL_PUA_BIT |
		NAU7802_PUCTRL_CS_BIT;
	if (tmp >= 2400)
		data |= NAU7802_PUCTRL_AVDDS_BIT;

	ret = i2c_smbus_write_byte_data(st->client, NAU7802_REG_PUCTRL, data);
	if (ret < 0)
		return ret;
	ret = i2c_smbus_write_byte_data(st->client, NAU7802_REG_ADC_CTRL, 0x30);
	if (ret < 0)
		return ret;

	if (tmp >= 2400) {
		data = NAU7802_CTRL1_VLDO((4500 - tmp) / 300);
		ret = i2c_smbus_write_byte_data(st->client, NAU7802_REG_CTRL1,
						data);
		if (ret < 0)
			return ret;
	}

	/* Populate available ADC input ranges */
	for (i = 0; i < ARRAY_SIZE(st->scale_avail); i++)
		st->scale_avail[i] = (((u64)st->vref_mv) * 1000000000ULL)
					   >> (23 + i);

	init_completion(&st->value_ok);

	/*
	 * The ADC fires continuously and we can't do anything about
	 * it. So we need to have the IRQ disabled by default, and we
	 * will enable them back when we will need them..
	 */
	if (client->irq) {
		ret = request_threaded_irq(client->irq,
				NULL,
				nau7802_eoc_trigger,
				IRQF_TRIGGER_HIGH | IRQF_ONESHOT,
				client->dev.driver->name,
				indio_dev);
		if (ret) {
			/*
			 * What may happen here is that our IRQ controller is
			 * not able to get level interrupt but this is required
			 * by this ADC as when going over 40 sample per second,
			 * the interrupt line may stay high between conversions.
			 * So, we continue no matter what but we switch to
			 * polling mode.
			 */
			dev_info(&client->dev,
				"Failed to allocate IRQ, using polling mode\n");
			client->irq = 0;
		} else
			disable_irq(client->irq);
	}

	if (!client->irq) {
		/*
		 * We are polling, use the fastest sample rate by
		 * default
		 */
		st->sample_rate = NAU7802_SAMP_FREQ_320;
		ret = i2c_smbus_write_byte_data(st->client, NAU7802_REG_CTRL2,
					  NAU7802_CTRL2_CRS(st->sample_rate));
		if (ret)
			goto error_free_irq;
	}

	/* Setup the ADC channels available on the board */
	indio_dev->num_channels = ARRAY_SIZE(nau7802_chan_array);
	indio_dev->channels = nau7802_chan_array;

	mutex_init(&st->lock);
	mutex_init(&st->data_lock);

	ret = iio_device_register(indio_dev);
	if (ret < 0) {
		dev_err(&client->dev, "Couldn't register the device.\n");
		goto error_device_register;
	}

	return 0;

error_device_register:
	mutex_destroy(&st->lock);
	mutex_destroy(&st->data_lock);
error_free_irq:
	if (client->irq)
		free_irq(client->irq, indio_dev);

	return ret;
}

__attribute__((used)) static int nau7802_remove(struct i2c_client *client)
{
	struct iio_dev *indio_dev = i2c_get_clientdata(client);
	struct nau7802_state *st = iio_priv(indio_dev);

	iio_device_unregister(indio_dev);
	mutex_destroy(&st->lock);
	mutex_destroy(&st->data_lock);
	if (client->irq)
		free_irq(client->irq, indio_dev);

	return 0;
}

