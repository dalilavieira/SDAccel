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
struct TYPE_2__ {struct device* parent; } ;
struct iio_dev {TYPE_1__ dev; int /*<<< orphan*/  name; int /*<<< orphan*/  num_channels; int /*<<< orphan*/  channels; int /*<<< orphan*/  modes; int /*<<< orphan*/ * info; } ;
struct iio_chan_spec {size_t channel; } ;
struct device {int dummy; } ;
struct cio_dac_iio {int* chan_out_states; scalar_t__ base; } ;

/* Variables and functions */
 scalar_t__ CIO_DAC_EXTENT ; 
 int /*<<< orphan*/  CIO_DAC_NUM_CHAN ; 
 int EBUSY ; 
 int EINVAL ; 
 int ENOMEM ; 
 long IIO_CHAN_INFO_RAW ; 
 int IIO_VAL_INT ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 scalar_t__* base ; 
 int /*<<< orphan*/  cio_dac_channels ; 
 int /*<<< orphan*/  cio_dac_info ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  dev_name (struct device*) ; 
 struct iio_dev* devm_iio_device_alloc (struct device*,int) ; 
 int devm_iio_device_register (struct device*,struct iio_dev*) ; 
 int /*<<< orphan*/  devm_request_region (struct device*,scalar_t__,scalar_t__,int /*<<< orphan*/ ) ; 
 void* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  outw (int,scalar_t__) ; 

__attribute__((used)) static int cio_dac_read_raw(struct iio_dev *indio_dev,
	struct iio_chan_spec const *chan, int *val, int *val2, long mask)
{
	struct cio_dac_iio *const priv = iio_priv(indio_dev);

	if (mask != IIO_CHAN_INFO_RAW)
		return -EINVAL;

	*val = priv->chan_out_states[chan->channel];

	return IIO_VAL_INT;
}

__attribute__((used)) static int cio_dac_write_raw(struct iio_dev *indio_dev,
	struct iio_chan_spec const *chan, int val, int val2, long mask)
{
	struct cio_dac_iio *const priv = iio_priv(indio_dev);
	const unsigned int chan_addr_offset = 2 * chan->channel;

	if (mask != IIO_CHAN_INFO_RAW)
		return -EINVAL;

	/* DAC can only accept up to a 16-bit value */
	if ((unsigned int)val > 65535)
		return -EINVAL;

	priv->chan_out_states[chan->channel] = val;
	outw(val, priv->base + chan_addr_offset);

	return 0;
}

__attribute__((used)) static int cio_dac_probe(struct device *dev, unsigned int id)
{
	struct iio_dev *indio_dev;
	struct cio_dac_iio *priv;
	unsigned int i;

	indio_dev = devm_iio_device_alloc(dev, sizeof(*priv));
	if (!indio_dev)
		return -ENOMEM;

	if (!devm_request_region(dev, base[id], CIO_DAC_EXTENT,
		dev_name(dev))) {
		dev_err(dev, "Unable to request port addresses (0x%X-0x%X)\n",
			base[id], base[id] + CIO_DAC_EXTENT);
		return -EBUSY;
	}

	indio_dev->info = &cio_dac_info;
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->channels = cio_dac_channels;
	indio_dev->num_channels = CIO_DAC_NUM_CHAN;
	indio_dev->name = dev_name(dev);
	indio_dev->dev.parent = dev;

	priv = iio_priv(indio_dev);
	priv->base = base[id];

	/* initialize DAC outputs to 0V */
	for (i = 0; i < 32; i += 2)
		outw(0, base[id] + i);

	return devm_iio_device_register(dev, indio_dev);
}

