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
typedef  int u8 ;
typedef  int u16 ;
struct spi_device_id {size_t driver_data; int /*<<< orphan*/  name; } ;
struct spi_device {int /*<<< orphan*/  dev; int /*<<< orphan*/  max_speed_hz; } ;
struct TYPE_2__ {int /*<<< orphan*/ * parent; } ;
struct iio_dev {int /*<<< orphan*/  modes; int /*<<< orphan*/  num_channels; int /*<<< orphan*/  channels; int /*<<< orphan*/ * info; TYPE_1__ dev; int /*<<< orphan*/  name; int /*<<< orphan*/  mlock; } ;
struct iio_chan_spec {size_t scan_index; int /*<<< orphan*/  channel; int /*<<< orphan*/  type; } ;
struct adis16260_chip_info {int gyro_max_scale; int gyro_max_val; int /*<<< orphan*/  num_channels; int /*<<< orphan*/  channels; } ;
struct adis {struct spi_device* spi; } ;
struct adis16260 {struct adis adis; struct adis16260_chip_info* info; } ;
typedef  int s16 ;

/* Variables and functions */
 int /*<<< orphan*/  ADIS16260_ERROR_ACTIVE ; 
 int ADIS16260_SLP_CNT ; 
 int ADIS16260_SLP_CNT_POWER_OFF ; 
 int ADIS16260_SMPL_PRD ; 
 int ADIS16260_SMPL_PRD_DIV_MASK ; 
 int ADIS16260_SMPL_PRD_TIME_BASE ; 
 int /*<<< orphan*/  ADIS16260_SPI_FAST ; 
 int /*<<< orphan*/  ADIS16260_SPI_SLOW ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
#define  IIO_ANGL_VEL 137 
#define  IIO_CHAN_INFO_CALIBBIAS 136 
#define  IIO_CHAN_INFO_CALIBSCALE 135 
#define  IIO_CHAN_INFO_OFFSET 134 
#define  IIO_CHAN_INFO_RAW 133 
#define  IIO_CHAN_INFO_SAMP_FREQ 132 
#define  IIO_CHAN_INFO_SCALE 131 
 int IIO_DEGREE_TO_RAD (int) ; 
#define  IIO_INCLI 130 
#define  IIO_TEMP 129 
 int IIO_VAL_FRACTIONAL ; 
 int IIO_VAL_INT ; 
 int IIO_VAL_INT_PLUS_MICRO ; 
#define  IIO_VOLTAGE 128 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int** adis16260_addresses ; 
 struct adis16260_chip_info* adis16260_chip_info_table ; 
 int /*<<< orphan*/  adis16260_data ; 
 int /*<<< orphan*/  adis16260_info ; 
 int /*<<< orphan*/  adis_cleanup_buffer_and_trigger (struct adis*,struct iio_dev*) ; 
 int adis_init (struct adis*,struct iio_dev*,struct spi_device*,int /*<<< orphan*/ *) ; 
 int adis_initial_startup (struct adis*) ; 
 int adis_read_reg_16 (struct adis*,int,int*) ; 
 int adis_setup_buffer_and_trigger (struct adis*,struct iio_dev*,int /*<<< orphan*/ *) ; 
 int adis_single_conversion (struct iio_dev*,struct iio_chan_spec const*,int /*<<< orphan*/ ,int*) ; 
 int adis_write_reg_16 (struct adis*,int,int) ; 
 int adis_write_reg_8 (struct adis*,int,int) ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*) ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 struct adis16260* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int sign_extend32 (int,int) ; 
 struct spi_device_id* spi_get_device_id (struct spi_device*) ; 
 struct iio_dev* spi_get_drvdata (struct spi_device*) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct iio_dev*) ; 

__attribute__((used)) static int adis16260_stop_device(struct iio_dev *indio_dev)
{
	struct adis16260 *adis16260 = iio_priv(indio_dev);
	int ret;
	u16 val = ADIS16260_SLP_CNT_POWER_OFF;

	ret = adis_write_reg_16(&adis16260->adis, ADIS16260_SLP_CNT, val);
	if (ret)
		dev_err(&indio_dev->dev, "problem with turning device off: SLP_CNT");

	return ret;
}

__attribute__((used)) static int adis16260_read_raw(struct iio_dev *indio_dev,
			      struct iio_chan_spec const *chan,
			      int *val, int *val2,
			      long mask)
{
	struct adis16260 *adis16260 = iio_priv(indio_dev);
	const struct adis16260_chip_info *info = adis16260->info;
	struct adis *adis = &adis16260->adis;
	int ret;
	u8 addr;
	s16 val16;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		return adis_single_conversion(indio_dev, chan,
				ADIS16260_ERROR_ACTIVE, val);
	case IIO_CHAN_INFO_SCALE:
		switch (chan->type) {
		case IIO_ANGL_VEL:
			*val = info->gyro_max_scale;
			*val2 = info->gyro_max_val;
			return IIO_VAL_FRACTIONAL;
		case IIO_INCLI:
			*val = 0;
			*val2 = IIO_DEGREE_TO_RAD(36630);
			return IIO_VAL_INT_PLUS_MICRO;
		case IIO_VOLTAGE:
			if (chan->channel == 0) {
				*val = 1;
				*val2 = 831500; /* 1.8315 mV */
			} else {
				*val = 0;
				*val2 = 610500; /* 610.5 uV */
			}
			return IIO_VAL_INT_PLUS_MICRO;
		case IIO_TEMP:
			*val = 145;
			*val2 = 300000; /* 0.1453 C */
			return IIO_VAL_INT_PLUS_MICRO;
		default:
			return -EINVAL;
		}
	case IIO_CHAN_INFO_OFFSET:
		*val = 250000 / 1453; /* 25 C = 0x00 */
		return IIO_VAL_INT;
	case IIO_CHAN_INFO_CALIBBIAS:
		addr = adis16260_addresses[chan->scan_index][0];
		ret = adis_read_reg_16(adis, addr, &val16);
		if (ret)
			return ret;

		*val = sign_extend32(val16, 11);
		return IIO_VAL_INT;
	case IIO_CHAN_INFO_CALIBSCALE:
		addr = adis16260_addresses[chan->scan_index][1];
		ret = adis_read_reg_16(adis, addr, &val16);
		if (ret)
			return ret;

		*val = val16;
		return IIO_VAL_INT;
	case IIO_CHAN_INFO_SAMP_FREQ:
		ret = adis_read_reg_16(adis, ADIS16260_SMPL_PRD, &val16);
		if (ret)
			return ret;

		if (spi_get_device_id(adis->spi)->driver_data)
		/* If an adis16251 */
			*val = (val16 & ADIS16260_SMPL_PRD_TIME_BASE) ?
				8 : 256;
		else
			*val = (val16 & ADIS16260_SMPL_PRD_TIME_BASE) ?
				66 : 2048;
		*val /= (val16 & ADIS16260_SMPL_PRD_DIV_MASK) + 1;
		return IIO_VAL_INT;
	}
	return -EINVAL;
}

__attribute__((used)) static int adis16260_write_raw(struct iio_dev *indio_dev,
			       struct iio_chan_spec const *chan,
			       int val,
			       int val2,
			       long mask)
{
	struct adis16260 *adis16260 = iio_priv(indio_dev);
	struct adis *adis = &adis16260->adis;
	int ret;
	u8 addr;
	u8 t;

	switch (mask) {
	case IIO_CHAN_INFO_CALIBBIAS:
		if (val < -2048 || val >= 2048)
			return -EINVAL;

		addr = adis16260_addresses[chan->scan_index][0];
		return adis_write_reg_16(adis, addr, val);
	case IIO_CHAN_INFO_CALIBSCALE:
		if (val < 0 || val >= 4096)
			return -EINVAL;

		addr = adis16260_addresses[chan->scan_index][1];
		return adis_write_reg_16(adis, addr, val);
	case IIO_CHAN_INFO_SAMP_FREQ:
		mutex_lock(&indio_dev->mlock);
		if (spi_get_device_id(adis->spi)->driver_data)
			t = 256 / val;
		else
			t = 2048 / val;

		if (t > ADIS16260_SMPL_PRD_DIV_MASK)
			t = ADIS16260_SMPL_PRD_DIV_MASK;
		else if (t > 0)
			t--;

		if (t >= 0x0A)
			adis->spi->max_speed_hz = ADIS16260_SPI_SLOW;
		else
			adis->spi->max_speed_hz = ADIS16260_SPI_FAST;
		ret = adis_write_reg_8(adis, ADIS16260_SMPL_PRD, t);

		mutex_unlock(&indio_dev->mlock);
		return ret;
	}
	return -EINVAL;
}

__attribute__((used)) static int adis16260_probe(struct spi_device *spi)
{
	const struct spi_device_id *id;
	struct adis16260 *adis16260;
	struct iio_dev *indio_dev;
	int ret;

	id = spi_get_device_id(spi);
	if (!id)
		return -ENODEV;

	/* setup the industrialio driver allocated elements */
	indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*adis16260));
	if (!indio_dev)
		return -ENOMEM;
	adis16260 = iio_priv(indio_dev);
	/* this is only used for removal purposes */
	spi_set_drvdata(spi, indio_dev);

	adis16260->info = &adis16260_chip_info_table[id->driver_data];

	indio_dev->name = id->name;
	indio_dev->dev.parent = &spi->dev;
	indio_dev->info = &adis16260_info;
	indio_dev->channels = adis16260->info->channels;
	indio_dev->num_channels = adis16260->info->num_channels;
	indio_dev->modes = INDIO_DIRECT_MODE;

	ret = adis_init(&adis16260->adis, indio_dev, spi, &adis16260_data);
	if (ret)
		return ret;

	ret = adis_setup_buffer_and_trigger(&adis16260->adis, indio_dev, NULL);
	if (ret)
		return ret;

	/* Get the device into a sane initial state */
	ret = adis_initial_startup(&adis16260->adis);
	if (ret)
		goto error_cleanup_buffer_trigger;
	ret = iio_device_register(indio_dev);
	if (ret)
		goto error_cleanup_buffer_trigger;

	return 0;

error_cleanup_buffer_trigger:
	adis_cleanup_buffer_and_trigger(&adis16260->adis, indio_dev);
	return ret;
}

__attribute__((used)) static int adis16260_remove(struct spi_device *spi)
{
	struct iio_dev *indio_dev = spi_get_drvdata(spi);
	struct adis16260 *adis16260 = iio_priv(indio_dev);

	iio_device_unregister(indio_dev);
	adis16260_stop_device(indio_dev);
	adis_cleanup_buffer_and_trigger(&adis16260->adis, indio_dev);

	return 0;
}

