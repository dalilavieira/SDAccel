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
struct spi_device_id {size_t driver_data; } ;
struct spi_device {int /*<<< orphan*/  dev; } ;
struct maxim_thermocouple_data {void* buffer; struct maxim_thermocouple_chip const* chip; struct spi_device* spi; } ;
struct maxim_thermocouple_chip {unsigned int read_size; int status_bit; int /*<<< orphan*/  num_channels; int /*<<< orphan*/  scan_masks; int /*<<< orphan*/  channels; } ;
struct iio_poll_func {struct iio_dev* indio_dev; } ;
struct TYPE_4__ {int /*<<< orphan*/ * parent; } ;
struct iio_dev {TYPE_2__ dev; int /*<<< orphan*/  modes; int /*<<< orphan*/  num_channels; int /*<<< orphan*/  available_scan_masks; int /*<<< orphan*/  channels; int /*<<< orphan*/  name; int /*<<< orphan*/ * info; int /*<<< orphan*/  trig; } ;
struct TYPE_3__ {int shift; scalar_t__ realbits; } ;
struct iio_chan_spec {int address; int /*<<< orphan*/  channel2; TYPE_1__ scan_type; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  int /*<<< orphan*/  __be32 ;
typedef  int /*<<< orphan*/  __be16 ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
#define  IIO_CHAN_INFO_RAW 130 
#define  IIO_CHAN_INFO_SCALE 129 
#define  IIO_MOD_TEMP_AMBIENT 128 
 int IIO_VAL_INT ; 
 int IIO_VAL_INT_PLUS_MICRO ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  MAXIM_THERMOCOUPLE_DRV_NAME ; 
 int be16_to_cpu (int /*<<< orphan*/ ) ; 
 int be32_to_cpu (int /*<<< orphan*/ ) ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 int iio_device_claim_direct_mode (struct iio_dev*) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_release_direct_mode (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_get_time_ns (struct iio_dev*) ; 
 struct maxim_thermocouple_data* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_push_to_buffers_with_timestamp (struct iio_dev*,void*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iio_trigger_notify_done (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iio_triggered_buffer_cleanup (struct iio_dev*) ; 
 int iio_triggered_buffer_setup (struct iio_dev*,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ *) ; 
 struct maxim_thermocouple_chip* maxim_thermocouple_chips ; 
 int /*<<< orphan*/  maxim_thermocouple_info ; 
 int sign_extend32 (int,scalar_t__) ; 
 struct spi_device_id* spi_get_device_id (struct spi_device*) ; 
 struct iio_dev* spi_get_drvdata (struct spi_device*) ; 
 int spi_read (struct spi_device*,void*,unsigned int) ; 

__attribute__((used)) static int maxim_thermocouple_read(struct maxim_thermocouple_data *data,
				   struct iio_chan_spec const *chan, int *val)
{
	unsigned int storage_bytes = data->chip->read_size;
	unsigned int shift = chan->scan_type.shift + (chan->address * 8);
	__be16 buf16;
	__be32 buf32;
	int ret;

	switch (storage_bytes) {
	case 2:
		ret = spi_read(data->spi, (void *)&buf16, storage_bytes);
		*val = be16_to_cpu(buf16);
		break;
	case 4:
		ret = spi_read(data->spi, (void *)&buf32, storage_bytes);
		*val = be32_to_cpu(buf32);
		break;
	default:
		ret = -EINVAL;
	}

	if (ret)
		return ret;

	/* check to be sure this is a valid reading */
	if (*val & data->chip->status_bit)
		return -EINVAL;

	*val = sign_extend32(*val >> shift, chan->scan_type.realbits - 1);

	return 0;
}

__attribute__((used)) static irqreturn_t maxim_thermocouple_trigger_handler(int irq, void *private)
{
	struct iio_poll_func *pf = private;
	struct iio_dev *indio_dev = pf->indio_dev;
	struct maxim_thermocouple_data *data = iio_priv(indio_dev);
	int ret;

	ret = spi_read(data->spi, data->buffer, data->chip->read_size);
	if (!ret) {
		iio_push_to_buffers_with_timestamp(indio_dev, data->buffer,
						   iio_get_time_ns(indio_dev));
	}

	iio_trigger_notify_done(indio_dev->trig);

	return IRQ_HANDLED;
}

__attribute__((used)) static int maxim_thermocouple_read_raw(struct iio_dev *indio_dev,
				       struct iio_chan_spec const *chan,
				       int *val, int *val2, long mask)
{
	struct maxim_thermocouple_data *data = iio_priv(indio_dev);
	int ret = -EINVAL;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		ret = iio_device_claim_direct_mode(indio_dev);
		if (ret)
			return ret;

		ret = maxim_thermocouple_read(data, chan, val);
		iio_device_release_direct_mode(indio_dev);

		if (!ret)
			return IIO_VAL_INT;

		break;
	case IIO_CHAN_INFO_SCALE:
		switch (chan->channel2) {
		case IIO_MOD_TEMP_AMBIENT:
			*val = 62;
			*val2 = 500000; /* 1000 * 0.0625 */
			ret = IIO_VAL_INT_PLUS_MICRO;
			break;
		default:
			*val = 250; /* 1000 * 0.25 */
			ret = IIO_VAL_INT;
		};
		break;
	}

	return ret;
}

__attribute__((used)) static int maxim_thermocouple_probe(struct spi_device *spi)
{
	const struct spi_device_id *id = spi_get_device_id(spi);
	struct iio_dev *indio_dev;
	struct maxim_thermocouple_data *data;
	const struct maxim_thermocouple_chip *chip =
			&maxim_thermocouple_chips[id->driver_data];
	int ret;

	indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*data));
	if (!indio_dev)
		return -ENOMEM;

	indio_dev->info = &maxim_thermocouple_info;
	indio_dev->name = MAXIM_THERMOCOUPLE_DRV_NAME;
	indio_dev->channels = chip->channels;
	indio_dev->available_scan_masks = chip->scan_masks;
	indio_dev->num_channels = chip->num_channels;
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->dev.parent = &spi->dev;

	data = iio_priv(indio_dev);
	data->spi = spi;
	data->chip = chip;

	ret = iio_triggered_buffer_setup(indio_dev, NULL,
				maxim_thermocouple_trigger_handler, NULL);
	if (ret)
		return ret;

	ret = iio_device_register(indio_dev);
	if (ret)
		goto error_unreg_buffer;

	return 0;

error_unreg_buffer:
	iio_triggered_buffer_cleanup(indio_dev);

	return ret;
}

__attribute__((used)) static int maxim_thermocouple_remove(struct spi_device *spi)
{
	struct iio_dev *indio_dev = spi_get_drvdata(spi);

	iio_device_unregister(indio_dev);
	iio_triggered_buffer_cleanup(indio_dev);

	return 0;
}

