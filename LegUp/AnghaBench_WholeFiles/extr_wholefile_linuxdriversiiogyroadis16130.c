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
typedef  int u8 ;
typedef  int u32 ;
struct spi_transfer {int* tx_buf; int* rx_buf; int len; } ;
struct TYPE_7__ {TYPE_1__* driver; } ;
struct spi_device {TYPE_3__ dev; } ;
struct TYPE_6__ {TYPE_3__* parent; } ;
struct iio_dev {int /*<<< orphan*/  modes; int /*<<< orphan*/ * info; TYPE_2__ dev; int /*<<< orphan*/  num_channels; int /*<<< orphan*/  channels; int /*<<< orphan*/  name; int /*<<< orphan*/  mlock; } ;
struct iio_chan_spec {int address; int /*<<< orphan*/  type; } ;
struct adis16130_state {int* buf; int /*<<< orphan*/  buf_lock; struct spi_device* us; } ;
struct TYPE_5__ {int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int ADIS16130_CON_RD ; 
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int ENOMEM ; 
#define  IIO_ANGL_VEL 132 
#define  IIO_CHAN_INFO_OFFSET 131 
#define  IIO_CHAN_INFO_RAW 130 
#define  IIO_CHAN_INFO_SCALE 129 
#define  IIO_TEMP 128 
 int IIO_VAL_FRACTIONAL ; 
 int IIO_VAL_INT ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int /*<<< orphan*/  adis16130_channels ; 
 int /*<<< orphan*/  adis16130_info ; 
 struct iio_dev* devm_iio_device_alloc (TYPE_3__*,int) ; 
 int devm_iio_device_register (TYPE_3__*,struct iio_dev*) ; 
 struct adis16130_state* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct iio_dev*) ; 
 int spi_sync_transfer (struct spi_device*,struct spi_transfer*,int) ; 

__attribute__((used)) static int adis16130_spi_read(struct iio_dev *indio_dev, u8 reg_addr, u32 *val)
{
	int ret;
	struct adis16130_state *st = iio_priv(indio_dev);
	struct spi_transfer xfer = {
		.tx_buf = st->buf,
		.rx_buf = st->buf,
		.len = 4,
	};

	mutex_lock(&st->buf_lock);

	st->buf[0] = ADIS16130_CON_RD | reg_addr;
	st->buf[1] = st->buf[2] = st->buf[3] = 0;

	ret = spi_sync_transfer(st->us, &xfer, 1);
	if (ret == 0)
		*val = (st->buf[1] << 16) | (st->buf[2] << 8) | st->buf[3];
	mutex_unlock(&st->buf_lock);

	return ret;
}

__attribute__((used)) static int adis16130_read_raw(struct iio_dev *indio_dev,
			      struct iio_chan_spec const *chan,
			      int *val, int *val2,
			      long mask)
{
	int ret;
	u32 temp;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		/* Take the iio_dev status lock */
		mutex_lock(&indio_dev->mlock);
		ret = adis16130_spi_read(indio_dev, chan->address, &temp);
		mutex_unlock(&indio_dev->mlock);
		if (ret)
			return ret;
		*val = temp;
		return IIO_VAL_INT;
	case IIO_CHAN_INFO_SCALE:
		switch (chan->type) {
		case IIO_ANGL_VEL:
			/* 0 degree = 838860, 250 degree = 14260608 */
			*val = 250;
			*val2 = 336440817; /* RAD_TO_DEGREE(14260608 - 8388608) */
			return IIO_VAL_FRACTIONAL;
		case IIO_TEMP:
			/* 0C = 8036283, 105C = 9516048 */
			*val = 105000;
			*val2 = 9516048 - 8036283;
			return IIO_VAL_FRACTIONAL;
		default:
			return -EINVAL;
		}
	case IIO_CHAN_INFO_OFFSET:
		switch (chan->type) {
		case IIO_ANGL_VEL:
			*val = -8388608;
			return IIO_VAL_INT;
		case IIO_TEMP:
			*val = -8036283;
			return IIO_VAL_INT;
		default:
			return -EINVAL;
		}
	}

	return -EINVAL;
}

__attribute__((used)) static int adis16130_probe(struct spi_device *spi)
{
	struct adis16130_state *st;
	struct iio_dev *indio_dev;

	/* setup the industrialio driver allocated elements */
	indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
	if (!indio_dev)
		return -ENOMEM;
	st = iio_priv(indio_dev);
	/* this is only used for removal purposes */
	spi_set_drvdata(spi, indio_dev);
	st->us = spi;
	mutex_init(&st->buf_lock);
	indio_dev->name = spi->dev.driver->name;
	indio_dev->channels = adis16130_channels;
	indio_dev->num_channels = ARRAY_SIZE(adis16130_channels);
	indio_dev->dev.parent = &spi->dev;
	indio_dev->info = &adis16130_info;
	indio_dev->modes = INDIO_DIRECT_MODE;

	return devm_iio_device_register(&spi->dev, indio_dev);
}

