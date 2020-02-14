#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_5__ ;
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u16 ;
struct ti_dac_spec {int resolution; int /*<<< orphan*/  num_channels; } ;
struct TYPE_7__ {struct spi_device* spi; } ;
struct TYPE_8__ {int** tx_buf; int len; } ;
struct ti_dac_chip {int resolution; int* buf; int powerdown_mode; int powerdown; int* val; int /*<<< orphan*/  vref; int /*<<< orphan*/  lock; TYPE_2__ mesg; TYPE_4__ xfer; } ;
struct device {int dummy; } ;
struct spi_device {int /*<<< orphan*/  modalias; struct device dev; } ;
struct TYPE_6__ {struct device* parent; } ;
struct iio_dev {int /*<<< orphan*/  num_channels; int /*<<< orphan*/  channels; int /*<<< orphan*/  modes; int /*<<< orphan*/  name; int /*<<< orphan*/ * info; TYPE_1__ dev; } ;
struct iio_chan_spec {size_t channel; } ;
typedef  int ssize_t ;
struct TYPE_9__ {size_t driver_data; } ;

/* Variables and functions */
 int EBUSY ; 
 int EINVAL ; 
 int ENOMEM ; 
#define  IIO_CHAN_INFO_RAW 129 
#define  IIO_CHAN_INFO_SCALE 128 
 int IIO_VAL_FRACTIONAL_LOG2 ; 
 int IIO_VAL_INT ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int POWERDOWN (unsigned int) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int WRITE_ALL_UPDATE ; 
 int WRITE_AND_UPDATE (size_t) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 struct iio_dev* devm_iio_device_alloc (struct device*,int) ; 
 int /*<<< orphan*/  devm_regulator_get (struct device*,char*) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 struct ti_dac_chip* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  mutex_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  regulator_disable (int /*<<< orphan*/ ) ; 
 int regulator_enable (int /*<<< orphan*/ ) ; 
 int regulator_get_voltage (int /*<<< orphan*/ ) ; 
 TYPE_5__* spi_get_device_id (struct spi_device*) ; 
 struct iio_dev* spi_get_drvdata (struct spi_device*) ; 
 int /*<<< orphan*/  spi_message_init_with_transfers (TYPE_2__*,TYPE_4__*,int) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct iio_dev*) ; 
 int spi_sync (struct spi_device*,TYPE_2__*) ; 
 int sprintf (char*,char*,int) ; 
 int strtobool (char const*,int*) ; 
 int /*<<< orphan*/  ti_dac_channels ; 
 int /*<<< orphan*/  ti_dac_info ; 
 struct ti_dac_spec* ti_dac_spec ; 

__attribute__((used)) static int ti_dac_cmd(struct ti_dac_chip *ti_dac, u8 cmd, u16 val)
{
	u8 shift = 12 - ti_dac->resolution;

	ti_dac->buf[0] = cmd | (val >> (8 - shift));
	ti_dac->buf[1] = (val << shift) & 0xff;
	return spi_sync(ti_dac->mesg.spi, &ti_dac->mesg);
}

__attribute__((used)) static int ti_dac_get_powerdown_mode(struct iio_dev *indio_dev,
				     const struct iio_chan_spec *chan)
{
	struct ti_dac_chip *ti_dac = iio_priv(indio_dev);

	return ti_dac->powerdown_mode;
}

__attribute__((used)) static int ti_dac_set_powerdown_mode(struct iio_dev *indio_dev,
				     const struct iio_chan_spec *chan,
				     unsigned int mode)
{
	struct ti_dac_chip *ti_dac = iio_priv(indio_dev);
	int ret = 0;

	if (ti_dac->powerdown_mode == mode)
		return 0;

	mutex_lock(&ti_dac->lock);
	if (ti_dac->powerdown) {
		ret = ti_dac_cmd(ti_dac, POWERDOWN(mode), 0);
		if (ret)
			goto out;
	}
	ti_dac->powerdown_mode = mode;

out:
	mutex_unlock(&ti_dac->lock);
	return ret;
}

__attribute__((used)) static ssize_t ti_dac_read_powerdown(struct iio_dev *indio_dev,
				     uintptr_t private,
				     const struct iio_chan_spec *chan,
				     char *buf)
{
	struct ti_dac_chip *ti_dac = iio_priv(indio_dev);

	return sprintf(buf, "%d\n", ti_dac->powerdown);
}

__attribute__((used)) static ssize_t ti_dac_write_powerdown(struct iio_dev *indio_dev,
				      uintptr_t private,
				      const struct iio_chan_spec *chan,
				      const char *buf, size_t len)
{
	struct ti_dac_chip *ti_dac = iio_priv(indio_dev);
	bool powerdown;
	int ret;

	ret = strtobool(buf, &powerdown);
	if (ret)
		return ret;

	if (ti_dac->powerdown == powerdown)
		return len;

	mutex_lock(&ti_dac->lock);
	if (powerdown)
		ret = ti_dac_cmd(ti_dac, POWERDOWN(ti_dac->powerdown_mode), 0);
	else
		ret = ti_dac_cmd(ti_dac, WRITE_AND_UPDATE(0), ti_dac->val[0]);
	if (!ret)
		ti_dac->powerdown = powerdown;
	mutex_unlock(&ti_dac->lock);

	return ret ? ret : len;
}

__attribute__((used)) static int ti_dac_read_raw(struct iio_dev *indio_dev,
			   struct iio_chan_spec const *chan,
			   int *val, int *val2, long mask)
{
	struct ti_dac_chip *ti_dac = iio_priv(indio_dev);
	int ret;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		*val = ti_dac->val[chan->channel];
		ret = IIO_VAL_INT;
		break;

	case IIO_CHAN_INFO_SCALE:
		ret = regulator_get_voltage(ti_dac->vref);
		if (ret < 0)
			return ret;

		*val = ret / 1000;
		*val2 = ti_dac->resolution;
		ret = IIO_VAL_FRACTIONAL_LOG2;
		break;

	default:
		ret = -EINVAL;
	}

	return ret;
}

__attribute__((used)) static int ti_dac_write_raw(struct iio_dev *indio_dev,
			    struct iio_chan_spec const *chan,
			    int val, int val2, long mask)
{
	struct ti_dac_chip *ti_dac = iio_priv(indio_dev);
	int ret;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		if (ti_dac->val[chan->channel] == val)
			return 0;

		if (val >= (1 << ti_dac->resolution) || val < 0)
			return -EINVAL;

		if (ti_dac->powerdown)
			return -EBUSY;

		mutex_lock(&ti_dac->lock);
		ret = ti_dac_cmd(ti_dac, WRITE_AND_UPDATE(chan->channel), val);
		if (!ret)
			ti_dac->val[chan->channel] = val;
		mutex_unlock(&ti_dac->lock);
		break;

	default:
		ret = -EINVAL;
	}

	return ret;
}

__attribute__((used)) static int ti_dac_write_raw_get_fmt(struct iio_dev *indio_dev,
				    struct iio_chan_spec const *chan, long mask)
{
	return IIO_VAL_INT;
}

__attribute__((used)) static int ti_dac_probe(struct spi_device *spi)
{
	struct device *dev = &spi->dev;
	const struct ti_dac_spec *spec;
	struct ti_dac_chip *ti_dac;
	struct iio_dev *indio_dev;
	int ret;

	indio_dev = devm_iio_device_alloc(dev, sizeof(*ti_dac));
	if (!indio_dev)
		return -ENOMEM;

	indio_dev->dev.parent = dev;
	indio_dev->info = &ti_dac_info;
	indio_dev->name = spi->modalias;
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->channels = ti_dac_channels;
	spi_set_drvdata(spi, indio_dev);

	ti_dac = iio_priv(indio_dev);
	ti_dac->xfer.tx_buf = &ti_dac->buf;
	ti_dac->xfer.len = sizeof(ti_dac->buf);
	spi_message_init_with_transfers(&ti_dac->mesg, &ti_dac->xfer, 1);
	ti_dac->mesg.spi = spi;

	spec = &ti_dac_spec[spi_get_device_id(spi)->driver_data];
	indio_dev->num_channels = spec->num_channels;
	ti_dac->resolution = spec->resolution;

	ti_dac->vref = devm_regulator_get(dev, "vref");
	if (IS_ERR(ti_dac->vref))
		return PTR_ERR(ti_dac->vref);

	ret = regulator_enable(ti_dac->vref);
	if (ret < 0)
		return ret;

	mutex_init(&ti_dac->lock);

	ret = ti_dac_cmd(ti_dac, WRITE_ALL_UPDATE, 0);
	if (ret) {
		dev_err(dev, "failed to initialize outputs to 0\n");
		goto err;
	}

	ret = iio_device_register(indio_dev);
	if (ret)
		goto err;

	return 0;

err:
	mutex_destroy(&ti_dac->lock);
	regulator_disable(ti_dac->vref);
	return ret;
}

__attribute__((used)) static int ti_dac_remove(struct spi_device *spi)
{
	struct iio_dev *indio_dev = spi_get_drvdata(spi);
	struct ti_dac_chip *ti_dac = iio_priv(indio_dev);

	iio_device_unregister(indio_dev);
	mutex_destroy(&ti_dac->lock);
	regulator_disable(ti_dac->vref);

	return 0;
}

