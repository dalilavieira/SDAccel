#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_3__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  of_node; } ;
struct spi_device {TYPE_1__ dev; } ;
struct max11100_state {int* buffer; int /*<<< orphan*/  vref_reg; struct spi_device* spi; } ;
struct TYPE_5__ {int /*<<< orphan*/  of_node; TYPE_1__* parent; } ;
struct iio_dev {char* name; int /*<<< orphan*/  num_channels; int /*<<< orphan*/  channels; int /*<<< orphan*/  modes; int /*<<< orphan*/ * info; TYPE_3__ dev; } ;
struct iio_chan_spec {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int ENOMEM ; 
#define  IIO_CHAN_INFO_RAW 129 
#define  IIO_CHAN_INFO_SCALE 128 
 int IIO_VAL_FRACTIONAL ; 
 int IIO_VAL_INT ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int MAX11100_LSB_DIV ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (TYPE_3__*,char*) ; 
 struct iio_dev* devm_iio_device_alloc (TYPE_1__*,int) ; 
 int /*<<< orphan*/  devm_regulator_get (TYPE_1__*,char*) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 struct max11100_state* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  max11100_channels ; 
 int /*<<< orphan*/  max11100_info ; 
 int /*<<< orphan*/  regulator_disable (int /*<<< orphan*/ ) ; 
 int regulator_enable (int /*<<< orphan*/ ) ; 
 int regulator_get_voltage (int /*<<< orphan*/ ) ; 
 struct iio_dev* spi_get_drvdata (struct spi_device*) ; 
 int spi_read (struct spi_device*,int*,int) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct iio_dev*) ; 

__attribute__((used)) static int max11100_read_single(struct iio_dev *indio_dev, int *val)
{
	int ret;
	struct max11100_state *state = iio_priv(indio_dev);

	ret = spi_read(state->spi, state->buffer, sizeof(state->buffer));
	if (ret) {
		dev_err(&indio_dev->dev, "SPI transfer failed\n");
		return ret;
	}

	/* the first 8 bits sent out from ADC must be 0s */
	if (state->buffer[0]) {
		dev_err(&indio_dev->dev, "Invalid value: buffer[0] != 0\n");
		return -EINVAL;
	}

	*val = (state->buffer[1] << 8) | state->buffer[2];

	return 0;
}

__attribute__((used)) static int max11100_read_raw(struct iio_dev *indio_dev,
			     struct iio_chan_spec const *chan,
			     int *val, int *val2, long info)
{
	int ret, vref_uv;
	struct max11100_state *state = iio_priv(indio_dev);

	switch (info) {
	case IIO_CHAN_INFO_RAW:
		ret = max11100_read_single(indio_dev, val);
		if (ret)
			return ret;

		return IIO_VAL_INT;

	case IIO_CHAN_INFO_SCALE:
		vref_uv = regulator_get_voltage(state->vref_reg);
		if (vref_uv < 0)
			/* dummy regulator "get_voltage" returns -EINVAL */
			return -EINVAL;

		*val =  vref_uv / 1000;
		*val2 = MAX11100_LSB_DIV;
		return IIO_VAL_FRACTIONAL;
	}

	return -EINVAL;
}

__attribute__((used)) static int max11100_probe(struct spi_device *spi)
{
	int ret;
	struct iio_dev *indio_dev;
	struct max11100_state *state;

	indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*state));
	if (!indio_dev)
		return -ENOMEM;

	spi_set_drvdata(spi, indio_dev);

	state = iio_priv(indio_dev);
	state->spi = spi;

	indio_dev->dev.parent = &spi->dev;
	indio_dev->dev.of_node = spi->dev.of_node;
	indio_dev->name = "max11100";
	indio_dev->info = &max11100_info;
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->channels = max11100_channels;
	indio_dev->num_channels = ARRAY_SIZE(max11100_channels);

	state->vref_reg = devm_regulator_get(&spi->dev, "vref");
	if (IS_ERR(state->vref_reg))
		return PTR_ERR(state->vref_reg);

	ret = regulator_enable(state->vref_reg);
	if (ret)
		return ret;

	ret = iio_device_register(indio_dev);
	if (ret)
		goto disable_regulator;

	return 0;

disable_regulator:
	regulator_disable(state->vref_reg);

	return ret;
}

__attribute__((used)) static int max11100_remove(struct spi_device *spi)
{
	struct iio_dev *indio_dev = spi_get_drvdata(spi);
	struct max11100_state *state = iio_priv(indio_dev);

	iio_device_unregister(indio_dev);
	regulator_disable(state->vref_reg);

	return 0;
}

