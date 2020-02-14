#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct ti_adc_data {int read_size; int shift; int /*<<< orphan*/  ref; struct spi_device* spi; int /*<<< orphan*/  buffer; } ;
struct TYPE_9__ {int /*<<< orphan*/  of_node; } ;
struct spi_device {TYPE_4__ dev; } ;
struct iio_poll_func {struct iio_dev* indio_dev; } ;
struct TYPE_7__ {int /*<<< orphan*/  of_node; TYPE_4__* parent; } ;
struct iio_dev {void* num_channels; struct iio_chan_spec* channels; int /*<<< orphan*/  modes; int /*<<< orphan*/  name; TYPE_2__ dev; int /*<<< orphan*/ * info; int /*<<< orphan*/  trig; } ;
struct TYPE_6__ {int realbits; } ;
struct iio_chan_spec {TYPE_1__ scan_type; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  int /*<<< orphan*/  __be32 ;
typedef  int /*<<< orphan*/  __be16 ;
struct TYPE_8__ {int driver_data; } ;

/* Variables and functions */
 void* ARRAY_SIZE (void*) ; 
 int EINVAL ; 
 int ENOMEM ; 
#define  IIO_CHAN_INFO_OFFSET 132 
#define  IIO_CHAN_INFO_RAW 131 
#define  IIO_CHAN_INFO_SCALE 130 
 int IIO_VAL_FRACTIONAL_LOG2 ; 
 int IIO_VAL_INT ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IS_ERR (int /*<<< orphan*/ ) ; 
#define  TI_ADC141S626 129 
#define  TI_ADC161S626 128 
 int /*<<< orphan*/  TI_ADC_DRV_NAME ; 
 int be16_to_cpu (int /*<<< orphan*/ ) ; 
 int be32_to_cpu (int /*<<< orphan*/ ) ; 
 struct iio_dev* devm_iio_device_alloc (TYPE_4__*,int) ; 
 int /*<<< orphan*/  devm_regulator_get (TYPE_4__*,char*) ; 
 int iio_device_claim_direct_mode (struct iio_dev*) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_release_direct_mode (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_get_time_ns (struct iio_dev*) ; 
 struct ti_adc_data* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_push_to_buffers_with_timestamp (struct iio_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iio_trigger_notify_done (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iio_triggered_buffer_cleanup (struct iio_dev*) ; 
 int iio_triggered_buffer_setup (struct iio_dev*,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  regulator_disable (int /*<<< orphan*/ ) ; 
 int regulator_enable (int /*<<< orphan*/ ) ; 
 int regulator_get_voltage (int /*<<< orphan*/ ) ; 
 int sign_extend32 (int,int) ; 
 TYPE_3__* spi_get_device_id (struct spi_device*) ; 
 struct iio_dev* spi_get_drvdata (struct spi_device*) ; 
 int spi_read (struct spi_device*,void*,int) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct iio_dev*) ; 
 void* ti_adc141s626_channels ; 
 void* ti_adc161s626_channels ; 
 int /*<<< orphan*/  ti_adc_info ; 

__attribute__((used)) static int ti_adc_read_measurement(struct ti_adc_data *data,
				   struct iio_chan_spec const *chan, int *val)
{
	int ret;

	switch (data->read_size) {
	case 2: {
		__be16 buf;

		ret = spi_read(data->spi, (void *) &buf, 2);
		if (ret)
			return ret;

		*val = be16_to_cpu(buf);
		break;
	}
	case 3: {
		__be32 buf;

		ret = spi_read(data->spi, (void *) &buf, 3);
		if (ret)
			return ret;

		*val = be32_to_cpu(buf) >> 8;
		break;
	}
	default:
		return -EINVAL;
	}

	*val = sign_extend32(*val >> data->shift, chan->scan_type.realbits - 1);

	return 0;
}

__attribute__((used)) static irqreturn_t ti_adc_trigger_handler(int irq, void *private)
{
	struct iio_poll_func *pf = private;
	struct iio_dev *indio_dev = pf->indio_dev;
	struct ti_adc_data *data = iio_priv(indio_dev);
	int ret;

	ret = ti_adc_read_measurement(data, &indio_dev->channels[0],
				     (int *) &data->buffer);
	if (!ret)
		iio_push_to_buffers_with_timestamp(indio_dev,
					data->buffer,
					iio_get_time_ns(indio_dev));

	iio_trigger_notify_done(indio_dev->trig);

	return IRQ_HANDLED;
}

__attribute__((used)) static int ti_adc_read_raw(struct iio_dev *indio_dev,
			   struct iio_chan_spec const *chan,
			   int *val, int *val2, long mask)
{
	struct ti_adc_data *data = iio_priv(indio_dev);
	int ret;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		ret = iio_device_claim_direct_mode(indio_dev);
		if (ret)
			return ret;

		ret = ti_adc_read_measurement(data, chan, val);
		iio_device_release_direct_mode(indio_dev);

		if (ret)
			return ret;

		return IIO_VAL_INT;
	case IIO_CHAN_INFO_SCALE:
		ret = regulator_get_voltage(data->ref);
		if (ret < 0)
			return ret;

		*val = ret / 1000;
		*val2 = chan->scan_type.realbits;

		return IIO_VAL_FRACTIONAL_LOG2;
	case IIO_CHAN_INFO_OFFSET:
		*val = 1 << (chan->scan_type.realbits - 1);
		return IIO_VAL_INT;
	}

	return 0;
}

__attribute__((used)) static int ti_adc_probe(struct spi_device *spi)
{
	struct iio_dev *indio_dev;
	struct ti_adc_data *data;
	int ret;

	indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*data));
	if (!indio_dev)
		return -ENOMEM;

	indio_dev->info = &ti_adc_info;
	indio_dev->dev.parent = &spi->dev;
	indio_dev->dev.of_node = spi->dev.of_node;
	indio_dev->name = TI_ADC_DRV_NAME;
	indio_dev->modes = INDIO_DIRECT_MODE;
	spi_set_drvdata(spi, indio_dev);

	data = iio_priv(indio_dev);
	data->spi = spi;

	switch (spi_get_device_id(spi)->driver_data) {
	case TI_ADC141S626:
		indio_dev->channels = ti_adc141s626_channels;
		indio_dev->num_channels = ARRAY_SIZE(ti_adc141s626_channels);
		data->shift = 0;
		data->read_size = 2;
		break;
	case TI_ADC161S626:
		indio_dev->channels = ti_adc161s626_channels;
		indio_dev->num_channels = ARRAY_SIZE(ti_adc161s626_channels);
		data->shift = 6;
		data->read_size = 3;
		break;
	}

	data->ref = devm_regulator_get(&spi->dev, "vdda");
	if (!IS_ERR(data->ref)) {
		ret = regulator_enable(data->ref);
		if (ret < 0)
			return ret;
	}

	ret = iio_triggered_buffer_setup(indio_dev, NULL,
					 ti_adc_trigger_handler, NULL);
	if (ret)
		goto error_regulator_disable;

	ret = iio_device_register(indio_dev);
	if (ret)
		goto error_unreg_buffer;

	return 0;

error_unreg_buffer:
	iio_triggered_buffer_cleanup(indio_dev);

error_regulator_disable:
	regulator_disable(data->ref);

	return ret;
}

__attribute__((used)) static int ti_adc_remove(struct spi_device *spi)
{
	struct iio_dev *indio_dev = spi_get_drvdata(spi);
	struct ti_adc_data *data = iio_priv(indio_dev);

	iio_device_unregister(indio_dev);
	iio_triggered_buffer_cleanup(indio_dev);
	regulator_disable(data->ref);

	return 0;
}

