#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_6__ ;
typedef  struct TYPE_15__   TYPE_3__ ;
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  int uint16_t ;
struct spi_device {int /*<<< orphan*/  dev; } ;
struct TYPE_15__ {int /*<<< orphan*/ * parent; } ;
struct iio_dev {unsigned int num_channels; int /*<<< orphan*/ * available_scan_masks; int /*<<< orphan*/  modes; int /*<<< orphan*/ * info; struct iio_chan_spec* channels; int /*<<< orphan*/  name; TYPE_3__ dev; int /*<<< orphan*/  mlock; } ;
struct iio_chan_spec {size_t scan_index; int /*<<< orphan*/  channel; int /*<<< orphan*/  type; } ;
struct TYPE_16__ {TYPE_1__* spi; } ;
struct adis16400_state {int filt_int; TYPE_6__ adis; int /*<<< orphan*/ * avail_scan_mask; struct adis16400_chip_info* variant; } ;
struct adis16400_chip_info {int flags; int (* get_freq ) (struct adis16400_state*) ;int (* set_freq ) (struct adis16400_state*,int) ;int gyro_scale_micro; int accel_scale_micro; int temp_scale_nano; int temp_offset; unsigned int num_channels; struct iio_chan_spec* channels; } ;
typedef  int int16_t ;
struct TYPE_14__ {size_t driver_data; int /*<<< orphan*/  name; } ;
struct TYPE_13__ {void* max_speed_hz; int /*<<< orphan*/  irq; int /*<<< orphan*/  chip_select; int /*<<< orphan*/  mode; } ;

/* Variables and functions */
 int ADIS16334_RATE_DIV_SHIFT ; 
 unsigned int ADIS16334_RATE_INT_CLK ; 
 int ADIS16400_HAS_PROD_ID ; 
 int ADIS16400_HAS_SLOW_MODE ; 
 int ADIS16400_NO_BURST ; 
 int /*<<< orphan*/  ADIS16400_PRODUCT_ID ; 
 scalar_t__ ADIS16400_SCAN_TIMESTAMP ; 
 int /*<<< orphan*/  ADIS16400_SENS_AVG ; 
 int /*<<< orphan*/  ADIS16400_SLP_CNT ; 
 int ADIS16400_SLP_CNT_POWER_OFF ; 
 int /*<<< orphan*/  ADIS16400_SMPL_PRD ; 
 int ADIS16400_SMPL_PRD_DIV_MASK ; 
 int ADIS16400_SMPL_PRD_TIME_BASE ; 
 void* ADIS16400_SPI_FAST ; 
 void* ADIS16400_SPI_SLOW ; 
 int ARRAY_SIZE (int*) ; 
 int /*<<< orphan*/  BIT (scalar_t__) ; 
 int EINVAL ; 
 int ENOMEM ; 
#define  IIO_ACCEL 139 
#define  IIO_ANGL_VEL 138 
#define  IIO_CHAN_INFO_CALIBBIAS 137 
#define  IIO_CHAN_INFO_LOW_PASS_FILTER_3DB_FREQUENCY 136 
#define  IIO_CHAN_INFO_OFFSET 135 
#define  IIO_CHAN_INFO_RAW 134 
#define  IIO_CHAN_INFO_SAMP_FREQ 133 
#define  IIO_CHAN_INFO_SCALE 132 
#define  IIO_MAGN 131 
#define  IIO_PRESSURE 130 
#define  IIO_TEMP 129 
 int IIO_VAL_INT ; 
 int IIO_VAL_INT_PLUS_MICRO ; 
#define  IIO_VOLTAGE 128 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int /*<<< orphan*/  SPI_MODE_3 ; 
 int* adis16400_3db_divisors ; 
 int /*<<< orphan*/ * adis16400_addresses ; 
 struct adis16400_chip_info* adis16400_chips ; 
 int /*<<< orphan*/  adis16400_data ; 
 int /*<<< orphan*/  adis16400_info ; 
 int /*<<< orphan*/  adis16400_trigger_handler ; 
 int /*<<< orphan*/  adis_cleanup_buffer_and_trigger (TYPE_6__*,struct iio_dev*) ; 
 int adis_init (TYPE_6__*,struct iio_dev*,struct spi_device*,int /*<<< orphan*/ *) ; 
 int adis_initial_startup (TYPE_6__*) ; 
 int adis_read_reg_16 (TYPE_6__*,int /*<<< orphan*/ ,int*) ; 
 int adis_setup_buffer_and_trigger (TYPE_6__*,struct iio_dev*,int /*<<< orphan*/ ) ; 
 int adis_single_conversion (struct iio_dev*,struct iio_chan_spec const*,int /*<<< orphan*/ ,int*) ; 
 int adis_write_reg_16 (TYPE_6__*,int /*<<< orphan*/ ,int) ; 
 int adis_write_reg_8 (TYPE_6__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  dev_err (TYPE_3__*,char*) ; 
 int /*<<< orphan*/  dev_info (TYPE_3__*,char*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_warn (TYPE_3__*,char*,unsigned int,int) ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 struct adis16400_state* iio_priv (struct iio_dev*) ; 
 unsigned int ilog2 (int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int sign_extend32 (int,int) ; 
 TYPE_2__* spi_get_device_id (struct spi_device*) ; 
 struct iio_dev* spi_get_drvdata (struct spi_device*) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct iio_dev*) ; 
 int /*<<< orphan*/  spi_setup (TYPE_1__*) ; 
 int sscanf (int /*<<< orphan*/ ,char*,unsigned int*) ; 
 int stub1 (struct adis16400_state*) ; 
 int stub2 (struct adis16400_state*,int) ; 
 int stub3 (struct adis16400_state*) ; 
 int stub4 (struct adis16400_state*) ; 

__attribute__((used)) static int adis16400_debugfs_init(struct iio_dev *indio_dev)
{
	return 0;
}

__attribute__((used)) static int adis16334_get_freq(struct adis16400_state *st)
{
	int ret;
	uint16_t t;

	ret = adis_read_reg_16(&st->adis, ADIS16400_SMPL_PRD, &t);
	if (ret < 0)
		return ret;

	t >>= ADIS16334_RATE_DIV_SHIFT;

	return 819200 >> t;
}

__attribute__((used)) static int adis16334_set_freq(struct adis16400_state *st, unsigned int freq)
{
	unsigned int t;

	if (freq < 819200)
		t = ilog2(819200 / freq);
	else
		t = 0;

	if (t > 0x31)
		t = 0x31;

	t <<= ADIS16334_RATE_DIV_SHIFT;
	t |= ADIS16334_RATE_INT_CLK;

	return adis_write_reg_16(&st->adis, ADIS16400_SMPL_PRD, t);
}

__attribute__((used)) static int adis16400_get_freq(struct adis16400_state *st)
{
	int sps, ret;
	uint16_t t;

	ret = adis_read_reg_16(&st->adis, ADIS16400_SMPL_PRD, &t);
	if (ret < 0)
		return ret;

	sps = (t & ADIS16400_SMPL_PRD_TIME_BASE) ? 52851 : 1638404;
	sps /= (t & ADIS16400_SMPL_PRD_DIV_MASK) + 1;

	return sps;
}

__attribute__((used)) static int adis16400_set_freq(struct adis16400_state *st, unsigned int freq)
{
	unsigned int t;
	uint8_t val = 0;

	t = 1638404 / freq;
	if (t >= 128) {
		val |= ADIS16400_SMPL_PRD_TIME_BASE;
		t = 52851 / freq;
		if (t >= 128)
			t = 127;
	} else if (t != 0) {
		t--;
	}

	val |= t;

	if (t >= 0x0A || (val & ADIS16400_SMPL_PRD_TIME_BASE))
		st->adis.spi->max_speed_hz = ADIS16400_SPI_SLOW;
	else
		st->adis.spi->max_speed_hz = ADIS16400_SPI_FAST;

	return adis_write_reg_8(&st->adis, ADIS16400_SMPL_PRD, val);
}

__attribute__((used)) static int adis16400_set_filter(struct iio_dev *indio_dev, int sps, int val)
{
	struct adis16400_state *st = iio_priv(indio_dev);
	uint16_t val16;
	int i, ret;

	for (i = ARRAY_SIZE(adis16400_3db_divisors) - 1; i >= 1; i--) {
		if (sps / adis16400_3db_divisors[i] >= val)
			break;
	}

	ret = adis_read_reg_16(&st->adis, ADIS16400_SENS_AVG, &val16);
	if (ret < 0)
		return ret;

	ret = adis_write_reg_16(&st->adis, ADIS16400_SENS_AVG,
					 (val16 & ~0x07) | i);
	return ret;
}

__attribute__((used)) static int adis16400_stop_device(struct iio_dev *indio_dev)
{
	struct adis16400_state *st = iio_priv(indio_dev);
	int ret;

	ret = adis_write_reg_16(&st->adis, ADIS16400_SLP_CNT,
			ADIS16400_SLP_CNT_POWER_OFF);
	if (ret)
		dev_err(&indio_dev->dev,
			"problem with turning device off: SLP_CNT");

	return ret;
}

__attribute__((used)) static int adis16400_initial_setup(struct iio_dev *indio_dev)
{
	struct adis16400_state *st = iio_priv(indio_dev);
	uint16_t prod_id, smp_prd;
	unsigned int device_id;
	int ret;

	/* use low spi speed for init if the device has a slow mode */
	if (st->variant->flags & ADIS16400_HAS_SLOW_MODE)
		st->adis.spi->max_speed_hz = ADIS16400_SPI_SLOW;
	else
		st->adis.spi->max_speed_hz = ADIS16400_SPI_FAST;
	st->adis.spi->mode = SPI_MODE_3;
	spi_setup(st->adis.spi);

	ret = adis_initial_startup(&st->adis);
	if (ret)
		return ret;

	if (st->variant->flags & ADIS16400_HAS_PROD_ID) {
		ret = adis_read_reg_16(&st->adis,
						ADIS16400_PRODUCT_ID, &prod_id);
		if (ret)
			goto err_ret;

		ret = sscanf(indio_dev->name, "adis%u\n", &device_id);
		if (ret != 1) {
			ret = -EINVAL;
			goto err_ret;
		}

		if (prod_id != device_id)
			dev_warn(&indio_dev->dev, "Device ID(%u) and product ID(%u) do not match.",
					device_id, prod_id);

		dev_info(&indio_dev->dev, "%s: prod_id 0x%04x at CS%d (irq %d)\n",
			indio_dev->name, prod_id,
			st->adis.spi->chip_select, st->adis.spi->irq);
	}
	/* use high spi speed if possible */
	if (st->variant->flags & ADIS16400_HAS_SLOW_MODE) {
		ret = adis_read_reg_16(&st->adis, ADIS16400_SMPL_PRD, &smp_prd);
		if (ret)
			goto err_ret;

		if ((smp_prd & ADIS16400_SMPL_PRD_DIV_MASK) < 0x0A) {
			st->adis.spi->max_speed_hz = ADIS16400_SPI_FAST;
			spi_setup(st->adis.spi);
		}
	}

err_ret:
	return ret;
}

__attribute__((used)) static int adis16400_write_raw(struct iio_dev *indio_dev,
	struct iio_chan_spec const *chan, int val, int val2, long info)
{
	struct adis16400_state *st = iio_priv(indio_dev);
	int ret, sps;

	switch (info) {
	case IIO_CHAN_INFO_CALIBBIAS:
		mutex_lock(&indio_dev->mlock);
		ret = adis_write_reg_16(&st->adis,
				adis16400_addresses[chan->scan_index], val);
		mutex_unlock(&indio_dev->mlock);
		return ret;
	case IIO_CHAN_INFO_LOW_PASS_FILTER_3DB_FREQUENCY:
		/*
		 * Need to cache values so we can update if the frequency
		 * changes.
		 */
		mutex_lock(&indio_dev->mlock);
		st->filt_int = val;
		/* Work out update to current value */
		sps = st->variant->get_freq(st);
		if (sps < 0) {
			mutex_unlock(&indio_dev->mlock);
			return sps;
		}

		ret = adis16400_set_filter(indio_dev, sps,
			val * 1000 + val2 / 1000);
		mutex_unlock(&indio_dev->mlock);
		return ret;
	case IIO_CHAN_INFO_SAMP_FREQ:
		sps = val * 1000 + val2 / 1000;

		if (sps <= 0)
			return -EINVAL;

		mutex_lock(&indio_dev->mlock);
		ret = st->variant->set_freq(st, sps);
		mutex_unlock(&indio_dev->mlock);
		return ret;
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int adis16400_read_raw(struct iio_dev *indio_dev,
	struct iio_chan_spec const *chan, int *val, int *val2, long info)
{
	struct adis16400_state *st = iio_priv(indio_dev);
	int16_t val16;
	int ret;

	switch (info) {
	case IIO_CHAN_INFO_RAW:
		return adis_single_conversion(indio_dev, chan, 0, val);
	case IIO_CHAN_INFO_SCALE:
		switch (chan->type) {
		case IIO_ANGL_VEL:
			*val = 0;
			*val2 = st->variant->gyro_scale_micro;
			return IIO_VAL_INT_PLUS_MICRO;
		case IIO_VOLTAGE:
			*val = 0;
			if (chan->channel == 0) {
				*val = 2;
				*val2 = 418000; /* 2.418 mV */
			} else {
				*val = 0;
				*val2 = 805800; /* 805.8 uV */
			}
			return IIO_VAL_INT_PLUS_MICRO;
		case IIO_ACCEL:
			*val = 0;
			*val2 = st->variant->accel_scale_micro;
			return IIO_VAL_INT_PLUS_MICRO;
		case IIO_MAGN:
			*val = 0;
			*val2 = 500; /* 0.5 mgauss */
			return IIO_VAL_INT_PLUS_MICRO;
		case IIO_TEMP:
			*val = st->variant->temp_scale_nano / 1000000;
			*val2 = (st->variant->temp_scale_nano % 1000000);
			return IIO_VAL_INT_PLUS_MICRO;
		case IIO_PRESSURE:
			/* 20 uBar = 0.002kPascal */
			*val = 0;
			*val2 = 2000;
			return IIO_VAL_INT_PLUS_MICRO;
		default:
			return -EINVAL;
		}
	case IIO_CHAN_INFO_CALIBBIAS:
		mutex_lock(&indio_dev->mlock);
		ret = adis_read_reg_16(&st->adis,
				adis16400_addresses[chan->scan_index], &val16);
		mutex_unlock(&indio_dev->mlock);
		if (ret)
			return ret;
		val16 = sign_extend32(val16, 11);
		*val = val16;
		return IIO_VAL_INT;
	case IIO_CHAN_INFO_OFFSET:
		/* currently only temperature */
		*val = st->variant->temp_offset;
		return IIO_VAL_INT;
	case IIO_CHAN_INFO_LOW_PASS_FILTER_3DB_FREQUENCY:
		mutex_lock(&indio_dev->mlock);
		/* Need both the number of taps and the sampling frequency */
		ret = adis_read_reg_16(&st->adis,
						ADIS16400_SENS_AVG,
						&val16);
		if (ret < 0) {
			mutex_unlock(&indio_dev->mlock);
			return ret;
		}
		ret = st->variant->get_freq(st);
		if (ret >= 0) {
			ret /= adis16400_3db_divisors[val16 & 0x07];
			*val = ret / 1000;
			*val2 = (ret % 1000) * 1000;
		}
		mutex_unlock(&indio_dev->mlock);
		if (ret < 0)
			return ret;
		return IIO_VAL_INT_PLUS_MICRO;
	case IIO_CHAN_INFO_SAMP_FREQ:
		ret = st->variant->get_freq(st);
		if (ret < 0)
			return ret;
		*val = ret / 1000;
		*val2 = (ret % 1000) * 1000;
		return IIO_VAL_INT_PLUS_MICRO;
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static void adis16400_setup_chan_mask(struct adis16400_state *st)
{
	const struct adis16400_chip_info *chip_info = st->variant;
	unsigned int i;

	for (i = 0; i < chip_info->num_channels; i++) {
		const struct iio_chan_spec *ch = &chip_info->channels[i];

		if (ch->scan_index >= 0 &&
		    ch->scan_index != ADIS16400_SCAN_TIMESTAMP)
			st->avail_scan_mask[0] |= BIT(ch->scan_index);
	}
}

__attribute__((used)) static int adis16400_probe(struct spi_device *spi)
{
	struct adis16400_state *st;
	struct iio_dev *indio_dev;
	int ret;

	indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
	if (indio_dev == NULL)
		return -ENOMEM;

	st = iio_priv(indio_dev);
	/* this is only used for removal purposes */
	spi_set_drvdata(spi, indio_dev);

	/* setup the industrialio driver allocated elements */
	st->variant = &adis16400_chips[spi_get_device_id(spi)->driver_data];
	indio_dev->dev.parent = &spi->dev;
	indio_dev->name = spi_get_device_id(spi)->name;
	indio_dev->channels = st->variant->channels;
	indio_dev->num_channels = st->variant->num_channels;
	indio_dev->info = &adis16400_info;
	indio_dev->modes = INDIO_DIRECT_MODE;

	if (!(st->variant->flags & ADIS16400_NO_BURST)) {
		adis16400_setup_chan_mask(st);
		indio_dev->available_scan_masks = st->avail_scan_mask;
	}

	ret = adis_init(&st->adis, indio_dev, spi, &adis16400_data);
	if (ret)
		return ret;

	ret = adis_setup_buffer_and_trigger(&st->adis, indio_dev,
			adis16400_trigger_handler);
	if (ret)
		return ret;

	/* Get the device into a sane initial state */
	ret = adis16400_initial_setup(indio_dev);
	if (ret)
		goto error_cleanup_buffer;
	ret = iio_device_register(indio_dev);
	if (ret)
		goto error_cleanup_buffer;

	adis16400_debugfs_init(indio_dev);
	return 0;

error_cleanup_buffer:
	adis_cleanup_buffer_and_trigger(&st->adis, indio_dev);
	return ret;
}

__attribute__((used)) static int adis16400_remove(struct spi_device *spi)
{
	struct iio_dev *indio_dev = spi_get_drvdata(spi);
	struct adis16400_state *st = iio_priv(indio_dev);

	iio_device_unregister(indio_dev);
	adis16400_stop_device(indio_dev);

	adis_cleanup_buffer_and_trigger(&st->adis, indio_dev);

	return 0;
}

