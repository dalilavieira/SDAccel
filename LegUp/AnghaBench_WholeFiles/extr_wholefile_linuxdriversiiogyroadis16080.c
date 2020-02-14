#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int u16 ;
struct spi_transfer {int len; int cs_change; int /*<<< orphan*/ * rx_buf; int /*<<< orphan*/ * tx_buf; } ;
struct spi_device_id {size_t driver_data; } ;
struct TYPE_7__ {TYPE_1__* driver; } ;
struct spi_device {TYPE_3__ dev; } ;
struct TYPE_6__ {TYPE_3__* parent; } ;
struct iio_dev {int /*<<< orphan*/  modes; int /*<<< orphan*/ * info; TYPE_2__ dev; int /*<<< orphan*/  num_channels; struct spi_transfer* channels; int /*<<< orphan*/  name; int /*<<< orphan*/  mlock; } ;
struct iio_chan_spec {int address; int /*<<< orphan*/  type; } ;
struct adis16080_state {TYPE_4__* info; struct spi_device* us; int /*<<< orphan*/  buf; } ;
struct TYPE_8__ {int scale_val; int scale_val2; } ;
struct TYPE_5__ {int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int ADIS16080_DIN_WRITE ; 
 int /*<<< orphan*/  ARRAY_SIZE (struct spi_transfer*) ; 
 int DIV_ROUND_CLOSEST (int,int) ; 
 int EINVAL ; 
 int ENOMEM ; 
#define  IIO_ANGL_VEL 133 
#define  IIO_CHAN_INFO_OFFSET 132 
#define  IIO_CHAN_INFO_RAW 131 
#define  IIO_CHAN_INFO_SCALE 130 
#define  IIO_TEMP 129 
 int IIO_VAL_FRACTIONAL ; 
 int IIO_VAL_FRACTIONAL_LOG2 ; 
 int IIO_VAL_INT ; 
#define  IIO_VOLTAGE 128 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 struct spi_transfer* adis16080_channels ; 
 TYPE_4__* adis16080_chip_info ; 
 int /*<<< orphan*/  adis16080_info ; 
 int /*<<< orphan*/  be16_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_to_be16 (int) ; 
 struct iio_dev* devm_iio_device_alloc (TYPE_3__*,int) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (int /*<<< orphan*/ ) ; 
 struct adis16080_state* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int sign_extend32 (int /*<<< orphan*/ ,int) ; 
 struct spi_device_id* spi_get_device_id (struct spi_device*) ; 
 int /*<<< orphan*/  spi_get_drvdata (struct spi_device*) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct iio_dev*) ; 
 int spi_sync_transfer (struct spi_device*,struct spi_transfer*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int adis16080_read_sample(struct iio_dev *indio_dev,
		u16 addr, int *val)
{
	struct adis16080_state *st = iio_priv(indio_dev);
	int ret;
	struct spi_transfer	t[] = {
		{
			.tx_buf		= &st->buf,
			.len		= 2,
			.cs_change	= 1,
		}, {
			.rx_buf		= &st->buf,
			.len		= 2,
		},
	};

	st->buf = cpu_to_be16(addr | ADIS16080_DIN_WRITE);

	ret = spi_sync_transfer(st->us, t, ARRAY_SIZE(t));
	if (ret == 0)
		*val = sign_extend32(be16_to_cpu(st->buf), 11);

	return ret;
}

__attribute__((used)) static int adis16080_read_raw(struct iio_dev *indio_dev,
			     struct iio_chan_spec const *chan,
			     int *val,
			     int *val2,
			     long mask)
{
	struct adis16080_state *st = iio_priv(indio_dev);
	int ret;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		mutex_lock(&indio_dev->mlock);
		ret = adis16080_read_sample(indio_dev, chan->address, val);
		mutex_unlock(&indio_dev->mlock);
		return ret ? ret : IIO_VAL_INT;
	case IIO_CHAN_INFO_SCALE:
		switch (chan->type) {
		case IIO_ANGL_VEL:
			*val = st->info->scale_val;
			*val2 = st->info->scale_val2;
			return IIO_VAL_FRACTIONAL;
		case IIO_VOLTAGE:
			/* VREF = 5V, 12 bits */
			*val = 5000;
			*val2 = 12;
			return IIO_VAL_FRACTIONAL_LOG2;
		case IIO_TEMP:
			/* 85 C = 585, 25 C = 0 */
			*val = 85000 - 25000;
			*val2 = 585;
			return IIO_VAL_FRACTIONAL;
		default:
			return -EINVAL;
		}
	case IIO_CHAN_INFO_OFFSET:
		switch (chan->type) {
		case IIO_VOLTAGE:
			/* 2.5 V = 0 */
			*val = 2048;
			return IIO_VAL_INT;
		case IIO_TEMP:
			/* 85 C = 585, 25 C = 0 */
			*val = DIV_ROUND_CLOSEST(25 * 585, 85 - 25);
			return IIO_VAL_INT;
		default:
			return -EINVAL;
		}
	default:
		break;
	}

	return -EINVAL;
}

__attribute__((used)) static int adis16080_probe(struct spi_device *spi)
{
	const struct spi_device_id *id = spi_get_device_id(spi);
	struct adis16080_state *st;
	struct iio_dev *indio_dev;

	/* setup the industrialio driver allocated elements */
	indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
	if (!indio_dev)
		return -ENOMEM;
	st = iio_priv(indio_dev);
	/* this is only used for removal purposes */
	spi_set_drvdata(spi, indio_dev);

	/* Allocate the comms buffers */
	st->us = spi;
	st->info = &adis16080_chip_info[id->driver_data];

	indio_dev->name = spi->dev.driver->name;
	indio_dev->channels = adis16080_channels;
	indio_dev->num_channels = ARRAY_SIZE(adis16080_channels);
	indio_dev->dev.parent = &spi->dev;
	indio_dev->info = &adis16080_info;
	indio_dev->modes = INDIO_DIRECT_MODE;

	return iio_device_register(indio_dev);
}

__attribute__((used)) static int adis16080_remove(struct spi_device *spi)
{
	iio_device_unregister(spi_get_drvdata(spi));
	return 0;
}

