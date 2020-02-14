#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct device {struct device_node* of_node; } ;
struct platform_device {struct device dev; } ;
struct iio_poll_func {int /*<<< orphan*/  timestamp; struct iio_dev* indio_dev; } ;
struct iio_dev_attr {int address; } ;
struct TYPE_5__ {struct device* parent; } ;
struct iio_dev {int masklength; char* name; int /*<<< orphan*/  num_channels; TYPE_3__* channels; int /*<<< orphan*/  modes; int /*<<< orphan*/ * info; TYPE_1__ dev; int /*<<< orphan*/  trig; int /*<<< orphan*/  active_scan_mask; } ;
struct iio_chan_spec {int channel; } ;
struct hx711_data {int data_ready_delay_ns; int gain_set; int gain_chan_a; int* buffer; int clock_frequency; void* reg_avdd; void* gpiod_dout; void* gpiod_pd_sck; int /*<<< orphan*/  lock; struct device* dev; } ;
struct device_node {int dummy; } ;
struct device_attribute {int dummy; } ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_7__ {int channel; } ;
struct TYPE_6__ {int gain; int gain_pulse; int scale; int channel; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (TYPE_3__*) ; 
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GPIOD_IN ; 
 int /*<<< orphan*/  GPIOD_OUT_LOW ; 
 int HX711_GAIN_MAX ; 
#define  IIO_CHAN_INFO_RAW 129 
#define  IIO_CHAN_INFO_SCALE 128 
 int IIO_VAL_INT ; 
 int IIO_VAL_INT_PLUS_NANO ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (void*) ; 
 int PTR_ERR (void*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*) ; 
 void* devm_gpiod_get (struct device*,char*,int /*<<< orphan*/ ) ; 
 struct iio_dev* devm_iio_device_alloc (struct device*,int) ; 
 void* devm_regulator_get (struct device*,char*) ; 
 int gpiod_get_value (void*) ; 
 int /*<<< orphan*/  gpiod_set_value (void*,int) ; 
 TYPE_3__* hx711_chan_spec ; 
 TYPE_2__* hx711_gain_to_scale ; 
 int /*<<< orphan*/  hx711_iio_info ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_pollfunc_store_time ; 
 struct hx711_data* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_push_to_buffers_with_timestamp (struct iio_dev*,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iio_trigger_notify_done (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iio_triggered_buffer_cleanup (struct iio_dev*) ; 
 int iio_triggered_buffer_setup (struct iio_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memset (int*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ndelay (int) ; 
 int of_property_read_u32 (struct device_node*,char*,int*) ; 
 struct iio_dev* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct iio_dev*) ; 
 int /*<<< orphan*/  preempt_disable () ; 
 int /*<<< orphan*/  preempt_enable () ; 
 int /*<<< orphan*/  regulator_disable (void*) ; 
 int regulator_enable (void*) ; 
 int regulator_get_voltage (void*) ; 
 scalar_t__ sprintf (char*,char*,...) ; 
 int /*<<< orphan*/  test_bit (int,int /*<<< orphan*/ ) ; 
 struct iio_dev_attr* to_iio_dev_attr (struct device_attribute*) ; 

__attribute__((used)) static int hx711_get_gain_to_pulse(int gain)
{
	int i;

	for (i = 0; i < HX711_GAIN_MAX; i++)
		if (hx711_gain_to_scale[i].gain == gain)
			return hx711_gain_to_scale[i].gain_pulse;
	return 1;
}

__attribute__((used)) static int hx711_get_gain_to_scale(int gain)
{
	int i;

	for (i = 0; i < HX711_GAIN_MAX; i++)
		if (hx711_gain_to_scale[i].gain == gain)
			return hx711_gain_to_scale[i].scale;
	return 0;
}

__attribute__((used)) static int hx711_get_scale_to_gain(int scale)
{
	int i;

	for (i = 0; i < HX711_GAIN_MAX; i++)
		if (hx711_gain_to_scale[i].scale == scale)
			return hx711_gain_to_scale[i].gain;
	return -EINVAL;
}

__attribute__((used)) static int hx711_cycle(struct hx711_data *hx711_data)
{
	int val;

	/*
	 * if preempted for more then 60us while PD_SCK is high:
	 * hx711 is going in reset
	 * ==> measuring is false
	 */
	preempt_disable();
	gpiod_set_value(hx711_data->gpiod_pd_sck, 1);

	/*
	 * wait until DOUT is ready
	 * it turned out that parasitic capacities are extending the time
	 * until DOUT has reached it's value
	 */
	ndelay(hx711_data->data_ready_delay_ns);

	val = gpiod_get_value(hx711_data->gpiod_dout);
	/*
	 * here we are not waiting for 0.2 us as suggested by the datasheet,
	 * because the oscilloscope showed in a test scenario
	 * at least 1.15 us for PD_SCK high (T3 in datasheet)
	 * and 0.56 us for PD_SCK low on TI Sitara with 800 MHz
	 */
	gpiod_set_value(hx711_data->gpiod_pd_sck, 0);
	preempt_enable();

	/*
	 * make it a square wave for addressing cases with capacitance on
	 * PC_SCK
	 */
	ndelay(hx711_data->data_ready_delay_ns);

	return val;
}

__attribute__((used)) static int hx711_read(struct hx711_data *hx711_data)
{
	int i, ret;
	int value = 0;
	int val = gpiod_get_value(hx711_data->gpiod_dout);

	/* we double check if it's really down */
	if (val)
		return -EIO;

	for (i = 0; i < 24; i++) {
		value <<= 1;
		ret = hx711_cycle(hx711_data);
		if (ret)
			value++;
	}

	value ^= 0x800000;

	for (i = 0; i < hx711_get_gain_to_pulse(hx711_data->gain_set); i++)
		hx711_cycle(hx711_data);

	return value;
}

__attribute__((used)) static int hx711_wait_for_ready(struct hx711_data *hx711_data)
{
	int i, val;

	/*
	 * in some rare cases the reset takes quite a long time
	 * especially when the channel is changed.
	 * Allow up to one second for it
	 */
	for (i = 0; i < 100; i++) {
		val = gpiod_get_value(hx711_data->gpiod_dout);
		if (!val)
			break;
		/* sleep at least 10 ms */
		msleep(10);
	}
	if (val)
		return -EIO;

	return 0;
}

__attribute__((used)) static int hx711_reset(struct hx711_data *hx711_data)
{
	int ret;
	int val = gpiod_get_value(hx711_data->gpiod_dout);

	if (val) {
		/*
		 * an examination with the oszilloscope indicated
		 * that the first value read after the reset is not stable
		 * if we reset too short;
		 * the shorter the reset cycle
		 * the less reliable the first value after reset is;
		 * there were no problems encountered with a value
		 * of 10 ms or higher
		 */
		gpiod_set_value(hx711_data->gpiod_pd_sck, 1);
		msleep(10);
		gpiod_set_value(hx711_data->gpiod_pd_sck, 0);

		ret = hx711_wait_for_ready(hx711_data);
		if (ret)
			return ret;
		/*
		 * after a reset the gain is 128 so we do a dummy read
		 * to set the gain for the next read
		 */
		ret = hx711_read(hx711_data);
		if (ret < 0)
			return ret;

		/*
		 * after a dummy read we need to wait vor readiness
		 * for not mixing gain pulses with the clock
		 */
		val = hx711_wait_for_ready(hx711_data);
	}

	return val;
}

__attribute__((used)) static int hx711_set_gain_for_channel(struct hx711_data *hx711_data, int chan)
{
	int ret;

	if (chan == 0) {
		if (hx711_data->gain_set == 32) {
			hx711_data->gain_set = hx711_data->gain_chan_a;

			ret = hx711_read(hx711_data);
			if (ret < 0)
				return ret;

			ret = hx711_wait_for_ready(hx711_data);
			if (ret)
				return ret;
		}
	} else {
		if (hx711_data->gain_set != 32) {
			hx711_data->gain_set = 32;

			ret = hx711_read(hx711_data);
			if (ret < 0)
				return ret;

			ret = hx711_wait_for_ready(hx711_data);
			if (ret)
				return ret;
		}
	}

	return 0;
}

__attribute__((used)) static int hx711_reset_read(struct hx711_data *hx711_data, int chan)
{
	int ret;
	int val;

	/*
	 * hx711_reset() must be called from here
	 * because it could be calling hx711_read() by itself
	 */
	if (hx711_reset(hx711_data)) {
		dev_err(hx711_data->dev, "reset failed!");
		return -EIO;
	}

	ret = hx711_set_gain_for_channel(hx711_data, chan);
	if (ret < 0)
		return ret;

	val = hx711_read(hx711_data);

	return val;
}

__attribute__((used)) static int hx711_read_raw(struct iio_dev *indio_dev,
				const struct iio_chan_spec *chan,
				int *val, int *val2, long mask)
{
	struct hx711_data *hx711_data = iio_priv(indio_dev);

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		mutex_lock(&hx711_data->lock);

		*val = hx711_reset_read(hx711_data, chan->channel);

		mutex_unlock(&hx711_data->lock);

		if (*val < 0)
			return *val;
		return IIO_VAL_INT;
	case IIO_CHAN_INFO_SCALE:
		*val = 0;
		mutex_lock(&hx711_data->lock);

		*val2 = hx711_get_gain_to_scale(hx711_data->gain_set);

		mutex_unlock(&hx711_data->lock);

		return IIO_VAL_INT_PLUS_NANO;
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int hx711_write_raw(struct iio_dev *indio_dev,
				struct iio_chan_spec const *chan,
				int val,
				int val2,
				long mask)
{
	struct hx711_data *hx711_data = iio_priv(indio_dev);
	int ret;
	int gain;

	switch (mask) {
	case IIO_CHAN_INFO_SCALE:
		/*
		 * a scale greater than 1 mV per LSB is not possible
		 * with the HX711, therefore val must be 0
		 */
		if (val != 0)
			return -EINVAL;

		mutex_lock(&hx711_data->lock);

		gain = hx711_get_scale_to_gain(val2);
		if (gain < 0) {
			mutex_unlock(&hx711_data->lock);
			return gain;
		}

		if (gain != hx711_data->gain_set) {
			hx711_data->gain_set = gain;
			if (gain != 32)
				hx711_data->gain_chan_a = gain;

			ret = hx711_read(hx711_data);
			if (ret < 0) {
				mutex_unlock(&hx711_data->lock);
				return ret;
			}
		}

		mutex_unlock(&hx711_data->lock);
		return 0;
	default:
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int hx711_write_raw_get_fmt(struct iio_dev *indio_dev,
		struct iio_chan_spec const *chan,
		long mask)
{
	return IIO_VAL_INT_PLUS_NANO;
}

__attribute__((used)) static irqreturn_t hx711_trigger(int irq, void *p)
{
	struct iio_poll_func *pf = p;
	struct iio_dev *indio_dev = pf->indio_dev;
	struct hx711_data *hx711_data = iio_priv(indio_dev);
	int i, j = 0;

	mutex_lock(&hx711_data->lock);

	memset(hx711_data->buffer, 0, sizeof(hx711_data->buffer));

	for (i = 0; i < indio_dev->masklength; i++) {
		if (!test_bit(i, indio_dev->active_scan_mask))
			continue;

		hx711_data->buffer[j] = hx711_reset_read(hx711_data,
					indio_dev->channels[i].channel);
		j++;
	}

	iio_push_to_buffers_with_timestamp(indio_dev, hx711_data->buffer,
							pf->timestamp);

	mutex_unlock(&hx711_data->lock);

	iio_trigger_notify_done(indio_dev->trig);

	return IRQ_HANDLED;
}

__attribute__((used)) static ssize_t hx711_scale_available_show(struct device *dev,
				struct device_attribute *attr,
				char *buf)
{
	struct iio_dev_attr *iio_attr = to_iio_dev_attr(attr);
	int channel = iio_attr->address;
	int i, len = 0;

	for (i = 0; i < HX711_GAIN_MAX; i++)
		if (hx711_gain_to_scale[i].channel == channel)
			len += sprintf(buf + len, "0.%09d ",
					hx711_gain_to_scale[i].scale);

	len += sprintf(buf + len, "\n");

	return len;
}

__attribute__((used)) static int hx711_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct device_node *np = dev->of_node;
	struct hx711_data *hx711_data;
	struct iio_dev *indio_dev;
	int ret;
	int i;

	indio_dev = devm_iio_device_alloc(dev, sizeof(struct hx711_data));
	if (!indio_dev) {
		dev_err(dev, "failed to allocate IIO device\n");
		return -ENOMEM;
	}

	hx711_data = iio_priv(indio_dev);
	hx711_data->dev = dev;

	mutex_init(&hx711_data->lock);

	/*
	 * PD_SCK stands for power down and serial clock input of HX711
	 * in the driver it is an output
	 */
	hx711_data->gpiod_pd_sck = devm_gpiod_get(dev, "sck", GPIOD_OUT_LOW);
	if (IS_ERR(hx711_data->gpiod_pd_sck)) {
		dev_err(dev, "failed to get sck-gpiod: err=%ld\n",
					PTR_ERR(hx711_data->gpiod_pd_sck));
		return PTR_ERR(hx711_data->gpiod_pd_sck);
	}

	/*
	 * DOUT stands for serial data output of HX711
	 * for the driver it is an input
	 */
	hx711_data->gpiod_dout = devm_gpiod_get(dev, "dout", GPIOD_IN);
	if (IS_ERR(hx711_data->gpiod_dout)) {
		dev_err(dev, "failed to get dout-gpiod: err=%ld\n",
					PTR_ERR(hx711_data->gpiod_dout));
		return PTR_ERR(hx711_data->gpiod_dout);
	}

	hx711_data->reg_avdd = devm_regulator_get(dev, "avdd");
	if (IS_ERR(hx711_data->reg_avdd))
		return PTR_ERR(hx711_data->reg_avdd);

	ret = regulator_enable(hx711_data->reg_avdd);
	if (ret < 0)
		return ret;

	/*
	 * with
	 * full scale differential input range: AVDD / GAIN
	 * full scale output data: 2^24
	 * we can say:
	 *     AVDD / GAIN = 2^24
	 * therefore:
	 *     1 LSB = AVDD / GAIN / 2^24
	 * AVDD is in uV, but we need 10^-9 mV
	 * approximately to fit into a 32 bit number:
	 * 1 LSB = (AVDD * 100) / GAIN / 1678 [10^-9 mV]
	 */
	ret = regulator_get_voltage(hx711_data->reg_avdd);
	if (ret < 0)
		goto error_regulator;

	/* we need 10^-9 mV */
	ret *= 100;

	for (i = 0; i < HX711_GAIN_MAX; i++)
		hx711_gain_to_scale[i].scale =
			ret / hx711_gain_to_scale[i].gain / 1678;

	hx711_data->gain_set = 128;
	hx711_data->gain_chan_a = 128;

	hx711_data->clock_frequency = 400000;
	ret = of_property_read_u32(np, "clock-frequency",
					&hx711_data->clock_frequency);

	/*
	 * datasheet says the high level of PD_SCK has a maximum duration
	 * of 50 microseconds
	 */
	if (hx711_data->clock_frequency < 20000) {
		dev_warn(dev, "clock-frequency too low - assuming 400 kHz\n");
		hx711_data->clock_frequency = 400000;
	}

	hx711_data->data_ready_delay_ns =
				1000000000 / hx711_data->clock_frequency;

	platform_set_drvdata(pdev, indio_dev);

	indio_dev->name = "hx711";
	indio_dev->dev.parent = &pdev->dev;
	indio_dev->info = &hx711_iio_info;
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->channels = hx711_chan_spec;
	indio_dev->num_channels = ARRAY_SIZE(hx711_chan_spec);

	ret = iio_triggered_buffer_setup(indio_dev, iio_pollfunc_store_time,
							hx711_trigger, NULL);
	if (ret < 0) {
		dev_err(dev, "setup of iio triggered buffer failed\n");
		goto error_regulator;
	}

	ret = iio_device_register(indio_dev);
	if (ret < 0) {
		dev_err(dev, "Couldn't register the device\n");
		goto error_buffer;
	}

	return 0;

error_buffer:
	iio_triggered_buffer_cleanup(indio_dev);

error_regulator:
	regulator_disable(hx711_data->reg_avdd);

	return ret;
}

__attribute__((used)) static int hx711_remove(struct platform_device *pdev)
{
	struct hx711_data *hx711_data;
	struct iio_dev *indio_dev;

	indio_dev = platform_get_drvdata(pdev);
	hx711_data = iio_priv(indio_dev);

	iio_device_unregister(indio_dev);

	iio_triggered_buffer_cleanup(indio_dev);

	regulator_disable(hx711_data->reg_avdd);

	return 0;
}

