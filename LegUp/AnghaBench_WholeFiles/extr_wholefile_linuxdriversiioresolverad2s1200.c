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
struct spi_device {int /*<<< orphan*/  dev; int /*<<< orphan*/  mode; int /*<<< orphan*/  max_speed_hz; } ;
struct TYPE_3__ {int /*<<< orphan*/ * parent; } ;
struct iio_dev {int /*<<< orphan*/  name; int /*<<< orphan*/  num_channels; int /*<<< orphan*/  channels; int /*<<< orphan*/  modes; int /*<<< orphan*/ * info; TYPE_1__ dev; } ;
struct iio_chan_spec {int const type; } ;
struct ad2s1200_state {void* rdvel; void* sample; struct spi_device* sdev; int /*<<< orphan*/  lock; int /*<<< orphan*/  rx; } ;
struct TYPE_4__ {int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int /*<<< orphan*/  AD2S1200_HZ ; 
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GPIOD_OUT_LOW ; 
#define  IIO_ANGL 131 
#define  IIO_ANGL_VEL 130 
#define  IIO_CHAN_INFO_RAW 129 
#define  IIO_CHAN_INFO_SCALE 128 
 int IIO_VAL_INT ; 
 int IIO_VAL_INT_PLUS_MICRO ; 
 int IIO_VAL_INT_PLUS_NANO ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 scalar_t__ IS_ERR (void*) ; 
 int PTR_ERR (void*) ; 
 int /*<<< orphan*/  SPI_MODE_3 ; 
 int /*<<< orphan*/  ad2s1200_channels ; 
 int /*<<< orphan*/  ad2s1200_info ; 
 int be16_to_cpup (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 void* devm_gpiod_get (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 int devm_iio_device_register (int /*<<< orphan*/ *,struct iio_dev*) ; 
 int /*<<< orphan*/  gpiod_set_value (void*,int) ; 
 struct ad2s1200_state* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int sign_extend32 (int,int) ; 
 TYPE_2__* spi_get_device_id (struct spi_device*) ; 
 int spi_read (struct spi_device*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct iio_dev*) ; 
 int spi_setup (struct spi_device*) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static int ad2s1200_read_raw(struct iio_dev *indio_dev,
			     struct iio_chan_spec const *chan,
			     int *val,
			     int *val2,
			     long m)
{
	struct ad2s1200_state *st = iio_priv(indio_dev);
	int ret;

	switch (m) {
	case IIO_CHAN_INFO_SCALE:
		switch (chan->type) {
		case IIO_ANGL:
			/* 2 * Pi / (2^12 - 1) ~= 0.001534355 */
			*val = 0;
			*val2 = 1534355;
			return IIO_VAL_INT_PLUS_NANO;
		case IIO_ANGL_VEL:
			/* 2 * Pi ~= 6.283185 */
			*val = 6;
			*val2 = 283185;
			return IIO_VAL_INT_PLUS_MICRO;
		default:
			return -EINVAL;
		}
		break;
	case IIO_CHAN_INFO_RAW:
		mutex_lock(&st->lock);
		gpiod_set_value(st->sample, 0);

		/* delay (6 * AD2S1200_TSCLK + 20) nano seconds */
		udelay(1);
		gpiod_set_value(st->sample, 1);
		gpiod_set_value(st->rdvel, !!(chan->type == IIO_ANGL));

		ret = spi_read(st->sdev, &st->rx, 2);
		if (ret < 0) {
			mutex_unlock(&st->lock);
			return ret;
		}

		switch (chan->type) {
		case IIO_ANGL:
			*val = be16_to_cpup(&st->rx) >> 4;
			break;
		case IIO_ANGL_VEL:
			*val = sign_extend32(be16_to_cpup(&st->rx) >> 4, 11);
			break;
		default:
			mutex_unlock(&st->lock);
			return -EINVAL;
		}

		/* delay (2 * AD2S1200_TSCLK + 20) ns for sample pulse */
		udelay(1);
		mutex_unlock(&st->lock);

		return IIO_VAL_INT;
	default:
		break;
	}

	return -EINVAL;
}

__attribute__((used)) static int ad2s1200_probe(struct spi_device *spi)
{
	struct ad2s1200_state *st;
	struct iio_dev *indio_dev;
	int ret;

	indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
	if (!indio_dev)
		return -ENOMEM;

	spi_set_drvdata(spi, indio_dev);
	st = iio_priv(indio_dev);
	mutex_init(&st->lock);
	st->sdev = spi;

	st->sample = devm_gpiod_get(&spi->dev, "adi,sample", GPIOD_OUT_LOW);
	if (IS_ERR(st->sample)) {
		dev_err(&spi->dev, "Failed to claim SAMPLE gpio: err=%ld\n",
			PTR_ERR(st->sample));
		return PTR_ERR(st->sample);
	}

	st->rdvel = devm_gpiod_get(&spi->dev, "adi,rdvel", GPIOD_OUT_LOW);
	if (IS_ERR(st->rdvel)) {
		dev_err(&spi->dev, "Failed to claim RDVEL gpio: err=%ld\n",
			PTR_ERR(st->rdvel));
		return PTR_ERR(st->rdvel);
	}

	indio_dev->dev.parent = &spi->dev;
	indio_dev->info = &ad2s1200_info;
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->channels = ad2s1200_channels;
	indio_dev->num_channels = ARRAY_SIZE(ad2s1200_channels);
	indio_dev->name = spi_get_device_id(spi)->name;

	spi->max_speed_hz = AD2S1200_HZ;
	spi->mode = SPI_MODE_3;
	ret = spi_setup(spi);

	if (ret < 0) {
		dev_err(&spi->dev, "spi_setup failed!\n");
		return ret;
	}

	return devm_iio_device_register(&spi->dev, indio_dev);
}

