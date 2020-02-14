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
typedef  int /*<<< orphan*/  val ;
typedef  int u16 ;
struct max44000_data {int /*<<< orphan*/  regmap; int /*<<< orphan*/  lock; } ;
struct iio_poll_func {struct iio_dev* indio_dev; } ;
struct TYPE_2__ {int /*<<< orphan*/ * parent; } ;
struct iio_dev {int* channels; int /*<<< orphan*/  num_channels; int /*<<< orphan*/  name; int /*<<< orphan*/ * info; TYPE_1__ dev; int /*<<< orphan*/  trig; int /*<<< orphan*/  active_scan_mask; } ;
struct iio_chan_spec {int const type; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;
struct device {int dummy; } ;
typedef  int s64 ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  int /*<<< orphan*/  __be16 ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int*) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int ERANGE ; 
#define  IIO_CHAN_INFO_INT_TIME 149 
#define  IIO_CHAN_INFO_RAW 148 
#define  IIO_CHAN_INFO_SCALE 147 
#define  IIO_CURRENT 146 
#define  IIO_LIGHT 145 
#define  IIO_PROXIMITY 144 
 int IIO_VAL_FRACTIONAL_LOG2 ; 
 int IIO_VAL_INT ; 
 int IIO_VAL_INT_PLUS_MICRO ; 
 int IIO_VAL_INT_PLUS_NANO ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int MAX44000_ALSDATA_OVERFLOW ; 
 int MAX44000_ALSPGA_MAX_SHIFT ; 
 int MAX44000_ALSTIM_SHIFT (int) ; 
 int MAX44000_ALS_TO_LUX_DEFAULT_FRACTION_LOG2 ; 
 int MAX44000_CFG_MODE_ALS_PRX ; 
 unsigned int MAX44000_CFG_RX_ALSPGA_MASK ; 
 unsigned int MAX44000_CFG_RX_ALSPGA_SHIFT ; 
 unsigned int MAX44000_CFG_RX_ALSTIM_MASK ; 
 unsigned int MAX44000_CFG_RX_ALSTIM_SHIFT ; 
 int MAX44000_CFG_TRIM ; 
 int /*<<< orphan*/  MAX44000_DRV_NAME ; 
 int MAX44000_LED_CURRENT_DEFAULT ; 
 unsigned int MAX44000_LED_CURRENT_MASK ; 
 int MAX44000_LED_CURRENT_MAX ; 
#define  MAX44000_REG_ALS_DATA_HI 143 
#define  MAX44000_REG_ALS_DATA_LO 142 
#define  MAX44000_REG_ALS_LOTHR_HI 141 
#define  MAX44000_REG_ALS_LOTHR_LO 140 
#define  MAX44000_REG_ALS_UPTHR_HI 139 
#define  MAX44000_REG_ALS_UPTHR_LO 138 
#define  MAX44000_REG_CFG_MAIN 137 
#define  MAX44000_REG_CFG_RX 136 
 int MAX44000_REG_CFG_RX_DEFAULT ; 
#define  MAX44000_REG_CFG_TX 135 
#define  MAX44000_REG_PRX_DATA 134 
#define  MAX44000_REG_PRX_IND 133 
#define  MAX44000_REG_PRX_THR 132 
#define  MAX44000_REG_PST 131 
#define  MAX44000_REG_STATUS 130 
#define  MAX44000_REG_TRIM_GAIN_GREEN 129 
#define  MAX44000_REG_TRIM_GAIN_IR 128 
 int /*<<< orphan*/  MAX44000_SCAN_INDEX_ALS ; 
 int /*<<< orphan*/  MAX44000_SCAN_INDEX_PRX ; 
 int NSEC_PER_SEC ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int USEC_PER_SEC ; 
 int be16_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int find_closest (int,int*,int /*<<< orphan*/ ) ; 
 int find_closest_descending (int,int*,int /*<<< orphan*/ ) ; 
 struct iio_dev* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_get_time_ns (struct iio_dev*) ; 
 struct max44000_data* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_push_to_buffers_with_timestamp (struct iio_dev*,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iio_trigger_notify_done (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iio_triggered_buffer_cleanup (struct iio_dev*) ; 
 int iio_triggered_buffer_setup (struct iio_dev*,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ *) ; 
 int* max44000_alspga_shift ; 
 int* max44000_channels ; 
 int /*<<< orphan*/  max44000_info ; 
 int* max44000_int_time_avail_ns_array ; 
 int /*<<< orphan*/  max44000_regmap_config ; 
 int* max44000_scale_avail_ulux_array ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int regmap_bulk_read (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,int) ; 
 int regmap_read (int /*<<< orphan*/ ,int const,...) ; 
 int regmap_write (int /*<<< orphan*/ ,int const,int) ; 
 int regmap_write_bits (int /*<<< orphan*/ ,int,unsigned int,int) ; 
 scalar_t__ test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int max44000_read_alstim(struct max44000_data *data)
{
	unsigned int val;
	int ret;

	ret = regmap_read(data->regmap, MAX44000_REG_CFG_RX, &val);
	if (ret < 0)
		return ret;
	return (val & MAX44000_CFG_RX_ALSTIM_MASK) >> MAX44000_CFG_RX_ALSTIM_SHIFT;
}

__attribute__((used)) static int max44000_write_alstim(struct max44000_data *data, int val)
{
	return regmap_write_bits(data->regmap, MAX44000_REG_CFG_RX,
				 MAX44000_CFG_RX_ALSTIM_MASK,
				 val << MAX44000_CFG_RX_ALSTIM_SHIFT);
}

__attribute__((used)) static int max44000_read_alspga(struct max44000_data *data)
{
	unsigned int val;
	int ret;

	ret = regmap_read(data->regmap, MAX44000_REG_CFG_RX, &val);
	if (ret < 0)
		return ret;
	return (val & MAX44000_CFG_RX_ALSPGA_MASK) >> MAX44000_CFG_RX_ALSPGA_SHIFT;
}

__attribute__((used)) static int max44000_write_alspga(struct max44000_data *data, int val)
{
	return regmap_write_bits(data->regmap, MAX44000_REG_CFG_RX,
				 MAX44000_CFG_RX_ALSPGA_MASK,
				 val << MAX44000_CFG_RX_ALSPGA_SHIFT);
}

__attribute__((used)) static int max44000_read_alsval(struct max44000_data *data)
{
	u16 regval;
	__be16 val;
	int alstim, ret;

	ret = regmap_bulk_read(data->regmap, MAX44000_REG_ALS_DATA_HI,
			       &val, sizeof(val));
	if (ret < 0)
		return ret;
	alstim = ret = max44000_read_alstim(data);
	if (ret < 0)
		return ret;

	regval = be16_to_cpu(val);

	/*
	 * Overflow is explained on datasheet page 17.
	 *
	 * It's a warning that either the G or IR channel has become saturated
	 * and that the value in the register is likely incorrect.
	 *
	 * The recommendation is to change the scale (ALSPGA).
	 * The driver just returns the max representable value.
	 */
	if (regval & MAX44000_ALSDATA_OVERFLOW)
		return 0x3FFF;

	return regval << MAX44000_ALSTIM_SHIFT(alstim);
}

__attribute__((used)) static int max44000_write_led_current_raw(struct max44000_data *data, int val)
{
	/* Maybe we should clamp the value instead? */
	if (val < 0 || val > MAX44000_LED_CURRENT_MAX)
		return -ERANGE;
	if (val >= 8)
		val += 4;
	return regmap_write_bits(data->regmap, MAX44000_REG_CFG_TX,
				 MAX44000_LED_CURRENT_MASK, val);
}

__attribute__((used)) static int max44000_read_led_current_raw(struct max44000_data *data)
{
	unsigned int regval;
	int ret;

	ret = regmap_read(data->regmap, MAX44000_REG_CFG_TX, &regval);
	if (ret < 0)
		return ret;
	regval &= MAX44000_LED_CURRENT_MASK;
	if (regval >= 8)
		regval -= 4;
	return regval;
}

__attribute__((used)) static int max44000_read_raw(struct iio_dev *indio_dev,
			     struct iio_chan_spec const *chan,
			     int *val, int *val2, long mask)
{
	struct max44000_data *data = iio_priv(indio_dev);
	int alstim, alspga;
	unsigned int regval;
	int ret;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		switch (chan->type) {
		case IIO_LIGHT:
			mutex_lock(&data->lock);
			ret = max44000_read_alsval(data);
			mutex_unlock(&data->lock);
			if (ret < 0)
				return ret;
			*val = ret;
			return IIO_VAL_INT;

		case IIO_PROXIMITY:
			mutex_lock(&data->lock);
			ret = regmap_read(data->regmap, MAX44000_REG_PRX_DATA, &regval);
			mutex_unlock(&data->lock);
			if (ret < 0)
				return ret;
			*val = regval;
			return IIO_VAL_INT;

		case IIO_CURRENT:
			mutex_lock(&data->lock);
			ret = max44000_read_led_current_raw(data);
			mutex_unlock(&data->lock);
			if (ret < 0)
				return ret;
			*val = ret;
			return IIO_VAL_INT;

		default:
			return -EINVAL;
		}

	case IIO_CHAN_INFO_SCALE:
		switch (chan->type) {
		case IIO_CURRENT:
			/* Output register is in 10s of miliamps */
			*val = 10;
			return IIO_VAL_INT;

		case IIO_LIGHT:
			mutex_lock(&data->lock);
			alspga = ret = max44000_read_alspga(data);
			mutex_unlock(&data->lock);
			if (ret < 0)
				return ret;

			/* Avoid negative shifts */
			*val = (1 << MAX44000_ALSPGA_MAX_SHIFT);
			*val2 = MAX44000_ALS_TO_LUX_DEFAULT_FRACTION_LOG2
					+ MAX44000_ALSPGA_MAX_SHIFT
					- max44000_alspga_shift[alspga];
			return IIO_VAL_FRACTIONAL_LOG2;

		default:
			return -EINVAL;
		}

	case IIO_CHAN_INFO_INT_TIME:
		mutex_lock(&data->lock);
		alstim = ret = max44000_read_alstim(data);
		mutex_unlock(&data->lock);

		if (ret < 0)
			return ret;
		*val = 0;
		*val2 = max44000_int_time_avail_ns_array[alstim];
		return IIO_VAL_INT_PLUS_NANO;

	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int max44000_write_raw(struct iio_dev *indio_dev,
			      struct iio_chan_spec const *chan,
			      int val, int val2, long mask)
{
	struct max44000_data *data = iio_priv(indio_dev);
	int ret;

	if (mask == IIO_CHAN_INFO_RAW && chan->type == IIO_CURRENT) {
		mutex_lock(&data->lock);
		ret = max44000_write_led_current_raw(data, val);
		mutex_unlock(&data->lock);
		return ret;
	} else if (mask == IIO_CHAN_INFO_INT_TIME && chan->type == IIO_LIGHT) {
		s64 valns = val * NSEC_PER_SEC + val2;
		int alstim = find_closest_descending(valns,
				max44000_int_time_avail_ns_array,
				ARRAY_SIZE(max44000_int_time_avail_ns_array));
		mutex_lock(&data->lock);
		ret = max44000_write_alstim(data, alstim);
		mutex_unlock(&data->lock);
		return ret;
	} else if (mask == IIO_CHAN_INFO_SCALE && chan->type == IIO_LIGHT) {
		s64 valus = val * USEC_PER_SEC + val2;
		int alspga = find_closest(valus,
				max44000_scale_avail_ulux_array,
				ARRAY_SIZE(max44000_scale_avail_ulux_array));
		mutex_lock(&data->lock);
		ret = max44000_write_alspga(data, alspga);
		mutex_unlock(&data->lock);
		return ret;
	}

	return -EINVAL;
}

__attribute__((used)) static int max44000_write_raw_get_fmt(struct iio_dev *indio_dev,
				      struct iio_chan_spec const *chan,
				      long mask)
{
	if (mask == IIO_CHAN_INFO_INT_TIME && chan->type == IIO_LIGHT)
		return IIO_VAL_INT_PLUS_NANO;
	else if (mask == IIO_CHAN_INFO_SCALE && chan->type == IIO_LIGHT)
		return IIO_VAL_INT_PLUS_MICRO;
	else
		return IIO_VAL_INT;
}

__attribute__((used)) static bool max44000_readable_reg(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case MAX44000_REG_STATUS:
	case MAX44000_REG_CFG_MAIN:
	case MAX44000_REG_CFG_RX:
	case MAX44000_REG_CFG_TX:
	case MAX44000_REG_ALS_DATA_HI:
	case MAX44000_REG_ALS_DATA_LO:
	case MAX44000_REG_PRX_DATA:
	case MAX44000_REG_ALS_UPTHR_HI:
	case MAX44000_REG_ALS_UPTHR_LO:
	case MAX44000_REG_ALS_LOTHR_HI:
	case MAX44000_REG_ALS_LOTHR_LO:
	case MAX44000_REG_PST:
	case MAX44000_REG_PRX_IND:
	case MAX44000_REG_PRX_THR:
	case MAX44000_REG_TRIM_GAIN_GREEN:
	case MAX44000_REG_TRIM_GAIN_IR:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static bool max44000_writeable_reg(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case MAX44000_REG_CFG_MAIN:
	case MAX44000_REG_CFG_RX:
	case MAX44000_REG_CFG_TX:
	case MAX44000_REG_ALS_UPTHR_HI:
	case MAX44000_REG_ALS_UPTHR_LO:
	case MAX44000_REG_ALS_LOTHR_HI:
	case MAX44000_REG_ALS_LOTHR_LO:
	case MAX44000_REG_PST:
	case MAX44000_REG_PRX_IND:
	case MAX44000_REG_PRX_THR:
	case MAX44000_REG_TRIM_GAIN_GREEN:
	case MAX44000_REG_TRIM_GAIN_IR:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static bool max44000_volatile_reg(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case MAX44000_REG_STATUS:
	case MAX44000_REG_ALS_DATA_HI:
	case MAX44000_REG_ALS_DATA_LO:
	case MAX44000_REG_PRX_DATA:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static bool max44000_precious_reg(struct device *dev, unsigned int reg)
{
	return reg == MAX44000_REG_STATUS;
}

__attribute__((used)) static irqreturn_t max44000_trigger_handler(int irq, void *p)
{
	struct iio_poll_func *pf = p;
	struct iio_dev *indio_dev = pf->indio_dev;
	struct max44000_data *data = iio_priv(indio_dev);
	u16 buf[8]; /* 2x u16 + padding + 8 bytes timestamp */
	int index = 0;
	unsigned int regval;
	int ret;

	mutex_lock(&data->lock);
	if (test_bit(MAX44000_SCAN_INDEX_ALS, indio_dev->active_scan_mask)) {
		ret = max44000_read_alsval(data);
		if (ret < 0)
			goto out_unlock;
		buf[index++] = ret;
	}
	if (test_bit(MAX44000_SCAN_INDEX_PRX, indio_dev->active_scan_mask)) {
		ret = regmap_read(data->regmap, MAX44000_REG_PRX_DATA, &regval);
		if (ret < 0)
			goto out_unlock;
		buf[index] = regval;
	}
	mutex_unlock(&data->lock);

	iio_push_to_buffers_with_timestamp(indio_dev, buf,
					   iio_get_time_ns(indio_dev));
	iio_trigger_notify_done(indio_dev->trig);
	return IRQ_HANDLED;

out_unlock:
	mutex_unlock(&data->lock);
	iio_trigger_notify_done(indio_dev->trig);
	return IRQ_HANDLED;
}

__attribute__((used)) static int max44000_probe(struct i2c_client *client,
			  const struct i2c_device_id *id)
{
	struct max44000_data *data;
	struct iio_dev *indio_dev;
	int ret, reg;

	indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
	if (!indio_dev)
		return -ENOMEM;
	data = iio_priv(indio_dev);
	data->regmap = devm_regmap_init_i2c(client, &max44000_regmap_config);
	if (IS_ERR(data->regmap)) {
		dev_err(&client->dev, "regmap_init failed!\n");
		return PTR_ERR(data->regmap);
	}

	i2c_set_clientdata(client, indio_dev);
	mutex_init(&data->lock);
	indio_dev->dev.parent = &client->dev;
	indio_dev->info = &max44000_info;
	indio_dev->name = MAX44000_DRV_NAME;
	indio_dev->channels = max44000_channels;
	indio_dev->num_channels = ARRAY_SIZE(max44000_channels);

	/*
	 * The device doesn't have a reset function so we just clear some
	 * important bits at probe time to ensure sane operation.
	 *
	 * Since we don't support interrupts/events the threshold values are
	 * not important. We also don't touch trim values.
	 */

	/* Reset ALS scaling bits */
	ret = regmap_write(data->regmap, MAX44000_REG_CFG_RX,
			   MAX44000_REG_CFG_RX_DEFAULT);
	if (ret < 0) {
		dev_err(&client->dev, "failed to write default CFG_RX: %d\n",
			ret);
		return ret;
	}

	/*
	 * By default the LED pulse used for the proximity sensor is disabled.
	 * Set a middle value so that we get some sort of valid data by default.
	 */
	ret = max44000_write_led_current_raw(data, MAX44000_LED_CURRENT_DEFAULT);
	if (ret < 0) {
		dev_err(&client->dev, "failed to write init config: %d\n", ret);
		return ret;
	}

	/* Reset CFG bits to ALS_PRX mode which allows easy reading of both values. */
	reg = MAX44000_CFG_TRIM | MAX44000_CFG_MODE_ALS_PRX;
	ret = regmap_write(data->regmap, MAX44000_REG_CFG_MAIN, reg);
	if (ret < 0) {
		dev_err(&client->dev, "failed to write init config: %d\n", ret);
		return ret;
	}

	/* Read status at least once to clear any stale interrupt bits. */
	ret = regmap_read(data->regmap, MAX44000_REG_STATUS, &reg);
	if (ret < 0) {
		dev_err(&client->dev, "failed to read init status: %d\n", ret);
		return ret;
	}

	ret = iio_triggered_buffer_setup(indio_dev, NULL, max44000_trigger_handler, NULL);
	if (ret < 0) {
		dev_err(&client->dev, "iio triggered buffer setup failed\n");
		return ret;
	}

	return iio_device_register(indio_dev);
}

__attribute__((used)) static int max44000_remove(struct i2c_client *client)
{
	struct iio_dev *indio_dev = i2c_get_clientdata(client);

	iio_device_unregister(indio_dev);
	iio_triggered_buffer_cleanup(indio_dev);

	return 0;
}

