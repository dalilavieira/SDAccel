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
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int uint16_t ;
struct spi_device_id {size_t driver_data; int /*<<< orphan*/  name; } ;
struct spi_device {int /*<<< orphan*/  dev; } ;
struct TYPE_4__ {int /*<<< orphan*/ * parent; } ;
struct iio_dev {unsigned int* channels; int num_channels; int /*<<< orphan*/  modes; int /*<<< orphan*/ * info; int /*<<< orphan*/  name; TYPE_1__ dev; int /*<<< orphan*/  mlock; } ;
struct iio_chan_spec {int /*<<< orphan*/  type; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct adis16136 {int /*<<< orphan*/  adis; TYPE_3__* chip_info; } ;
typedef  int ssize_t ;
struct TYPE_5__ {int precision; int fullscale; } ;

/* Variables and functions */
 int /*<<< orphan*/  ADIS16136_REG_AVG_CNT ; 
 int /*<<< orphan*/  ADIS16136_REG_GYRO_OFF2 ; 
 int /*<<< orphan*/  ADIS16136_REG_PROD_ID ; 
 int /*<<< orphan*/  ADIS16136_REG_SLP_CTRL ; 
 int /*<<< orphan*/  ADIS16136_REG_SMPL_PRD ; 
 int ARRAY_SIZE (unsigned int*) ; 
 int EINVAL ; 
 int ENOMEM ; 
#define  IIO_ANGL_VEL 133 
#define  IIO_CHAN_INFO_CALIBBIAS 132 
#define  IIO_CHAN_INFO_LOW_PASS_FILTER_3DB_FREQUENCY 131 
#define  IIO_CHAN_INFO_RAW 130 
#define  IIO_CHAN_INFO_SCALE 129 
#define  IIO_TEMP 128 
 int IIO_VAL_FRACTIONAL ; 
 int IIO_VAL_INT ; 
 int IIO_VAL_INT_PLUS_MICRO ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 unsigned int* adis16136_3db_divisors ; 
 unsigned int* adis16136_channels ; 
 TYPE_3__* adis16136_chip_info ; 
 int /*<<< orphan*/  adis16136_data ; 
 int /*<<< orphan*/  adis16136_info ; 
 int /*<<< orphan*/  adis_cleanup_buffer_and_trigger (int /*<<< orphan*/ *,struct iio_dev*) ; 
 int adis_init (int /*<<< orphan*/ *,struct iio_dev*,struct spi_device*,int /*<<< orphan*/ *) ; 
 int adis_initial_startup (int /*<<< orphan*/ *) ; 
 int adis_read_reg_16 (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int*) ; 
 int adis_read_reg_32 (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int adis_setup_buffer_and_trigger (int /*<<< orphan*/ *,struct iio_dev*,int /*<<< orphan*/ *) ; 
 int adis_single_conversion (struct iio_dev*,struct iio_chan_spec const*,int /*<<< orphan*/ ,int*) ; 
 int adis_write_reg_16 (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int adis_write_reg_32 (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*,int) ; 
 struct iio_dev* dev_to_iio_dev (struct device*) ; 
 int /*<<< orphan*/  dev_warn (TYPE_1__*,char*,unsigned int,int) ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 struct adis16136* iio_priv (struct iio_dev*) ; 
 int kstrtouint (char const*,int,unsigned int*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int sign_extend32 (int /*<<< orphan*/ ,int) ; 
 struct spi_device_id* spi_get_device_id (struct spi_device*) ; 
 struct iio_dev* spi_get_drvdata (struct spi_device*) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct iio_dev*) ; 
 int sprintf (char*,char*,unsigned int) ; 
 int sscanf (int /*<<< orphan*/ ,char*,unsigned int*) ; 

__attribute__((used)) static int adis16136_debugfs_init(struct iio_dev *indio_dev)
{
	return 0;
}

__attribute__((used)) static int adis16136_set_freq(struct adis16136 *adis16136, unsigned int freq)
{
	unsigned int t;

	t = 32768 / freq;
	if (t < 0xf)
		t = 0xf;
	else if (t > 0xffff)
		t = 0xffff;
	else
		t--;

	return adis_write_reg_16(&adis16136->adis, ADIS16136_REG_SMPL_PRD, t);
}

__attribute__((used)) static int adis16136_get_freq(struct adis16136 *adis16136, unsigned int *freq)
{
	uint16_t t;
	int ret;

	ret = adis_read_reg_16(&adis16136->adis, ADIS16136_REG_SMPL_PRD, &t);
	if (ret < 0)
		return ret;

	*freq = 32768 / (t + 1);

	return 0;
}

__attribute__((used)) static ssize_t adis16136_write_frequency(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len)
{
	struct iio_dev *indio_dev = dev_to_iio_dev(dev);
	struct adis16136 *adis16136 = iio_priv(indio_dev);
	unsigned int val;
	int ret;

	ret = kstrtouint(buf, 10, &val);
	if (ret)
		return ret;

	if (val == 0)
		return -EINVAL;

	ret = adis16136_set_freq(adis16136, val);

	return ret ? ret : len;
}

__attribute__((used)) static ssize_t adis16136_read_frequency(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	struct iio_dev *indio_dev = dev_to_iio_dev(dev);
	struct adis16136 *adis16136 = iio_priv(indio_dev);
	unsigned int freq;
	int ret;

	ret = adis16136_get_freq(adis16136, &freq);
	if (ret < 0)
		return ret;

	return sprintf(buf, "%d\n", freq);
}

__attribute__((used)) static int adis16136_set_filter(struct iio_dev *indio_dev, int val)
{
	struct adis16136 *adis16136 = iio_priv(indio_dev);
	unsigned int freq;
	int i, ret;

	ret = adis16136_get_freq(adis16136, &freq);
	if (ret < 0)
		return ret;

	for (i = ARRAY_SIZE(adis16136_3db_divisors) - 1; i >= 1; i--) {
		if (freq / adis16136_3db_divisors[i] >= val)
			break;
	}

	return adis_write_reg_16(&adis16136->adis, ADIS16136_REG_AVG_CNT, i);
}

__attribute__((used)) static int adis16136_get_filter(struct iio_dev *indio_dev, int *val)
{
	struct adis16136 *adis16136 = iio_priv(indio_dev);
	unsigned int freq;
	uint16_t val16;
	int ret;

	mutex_lock(&indio_dev->mlock);

	ret = adis_read_reg_16(&adis16136->adis, ADIS16136_REG_AVG_CNT, &val16);
	if (ret < 0)
		goto err_unlock;

	ret = adis16136_get_freq(adis16136, &freq);
	if (ret < 0)
		goto err_unlock;

	*val = freq / adis16136_3db_divisors[val16 & 0x07];

err_unlock:
	mutex_unlock(&indio_dev->mlock);

	return ret ? ret : IIO_VAL_INT;
}

__attribute__((used)) static int adis16136_read_raw(struct iio_dev *indio_dev,
	const struct iio_chan_spec *chan, int *val, int *val2, long info)
{
	struct adis16136 *adis16136 = iio_priv(indio_dev);
	uint32_t val32;
	int ret;

	switch (info) {
	case IIO_CHAN_INFO_RAW:
		return adis_single_conversion(indio_dev, chan, 0, val);
	case IIO_CHAN_INFO_SCALE:
		switch (chan->type) {
		case IIO_ANGL_VEL:
			*val = adis16136->chip_info->precision;
			*val2 = (adis16136->chip_info->fullscale << 16);
			return IIO_VAL_FRACTIONAL;
		case IIO_TEMP:
			*val = 10;
			*val2 = 697000; /* 0.010697 degree Celsius */
			return IIO_VAL_INT_PLUS_MICRO;
		default:
			return -EINVAL;
		}
	case IIO_CHAN_INFO_CALIBBIAS:
		ret = adis_read_reg_32(&adis16136->adis,
			ADIS16136_REG_GYRO_OFF2, &val32);
		if (ret < 0)
			return ret;

		*val = sign_extend32(val32, 31);

		return IIO_VAL_INT;
	case IIO_CHAN_INFO_LOW_PASS_FILTER_3DB_FREQUENCY:
		return adis16136_get_filter(indio_dev, val);
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int adis16136_write_raw(struct iio_dev *indio_dev,
	const struct iio_chan_spec *chan, int val, int val2, long info)
{
	struct adis16136 *adis16136 = iio_priv(indio_dev);

	switch (info) {
	case IIO_CHAN_INFO_CALIBBIAS:
		return adis_write_reg_32(&adis16136->adis,
			ADIS16136_REG_GYRO_OFF2, val);
	case IIO_CHAN_INFO_LOW_PASS_FILTER_3DB_FREQUENCY:
		return adis16136_set_filter(indio_dev, val);
	default:
		break;
	}

	return -EINVAL;
}

__attribute__((used)) static int adis16136_stop_device(struct iio_dev *indio_dev)
{
	struct adis16136 *adis16136 = iio_priv(indio_dev);
	int ret;

	ret = adis_write_reg_16(&adis16136->adis, ADIS16136_REG_SLP_CTRL, 0xff);
	if (ret)
		dev_err(&indio_dev->dev,
			"Could not power down device: %d\n", ret);

	return ret;
}

__attribute__((used)) static int adis16136_initial_setup(struct iio_dev *indio_dev)
{
	struct adis16136 *adis16136 = iio_priv(indio_dev);
	unsigned int device_id;
	uint16_t prod_id;
	int ret;

	ret = adis_initial_startup(&adis16136->adis);
	if (ret)
		return ret;

	ret = adis_read_reg_16(&adis16136->adis, ADIS16136_REG_PROD_ID,
		&prod_id);
	if (ret)
		return ret;

	ret = sscanf(indio_dev->name, "adis%u\n", &device_id);
	if (ret != 1)
		return -EINVAL;

	if (prod_id != device_id)
		dev_warn(&indio_dev->dev, "Device ID(%u) and product ID(%u) do not match.",
				device_id, prod_id);

	return 0;
}

__attribute__((used)) static int adis16136_probe(struct spi_device *spi)
{
	const struct spi_device_id *id = spi_get_device_id(spi);
	struct adis16136 *adis16136;
	struct iio_dev *indio_dev;
	int ret;

	indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*adis16136));
	if (indio_dev == NULL)
		return -ENOMEM;

	spi_set_drvdata(spi, indio_dev);

	adis16136 = iio_priv(indio_dev);

	adis16136->chip_info = &adis16136_chip_info[id->driver_data];
	indio_dev->dev.parent = &spi->dev;
	indio_dev->name = spi_get_device_id(spi)->name;
	indio_dev->channels = adis16136_channels;
	indio_dev->num_channels = ARRAY_SIZE(adis16136_channels);
	indio_dev->info = &adis16136_info;
	indio_dev->modes = INDIO_DIRECT_MODE;

	ret = adis_init(&adis16136->adis, indio_dev, spi, &adis16136_data);
	if (ret)
		return ret;

	ret = adis_setup_buffer_and_trigger(&adis16136->adis, indio_dev, NULL);
	if (ret)
		return ret;

	ret = adis16136_initial_setup(indio_dev);
	if (ret)
		goto error_cleanup_buffer;

	ret = iio_device_register(indio_dev);
	if (ret)
		goto error_stop_device;

	adis16136_debugfs_init(indio_dev);

	return 0;

error_stop_device:
	adis16136_stop_device(indio_dev);
error_cleanup_buffer:
	adis_cleanup_buffer_and_trigger(&adis16136->adis, indio_dev);
	return ret;
}

__attribute__((used)) static int adis16136_remove(struct spi_device *spi)
{
	struct iio_dev *indio_dev = spi_get_drvdata(spi);
	struct adis16136 *adis16136 = iio_priv(indio_dev);

	iio_device_unregister(indio_dev);
	adis16136_stop_device(indio_dev);

	adis_cleanup_buffer_and_trigger(&adis16136->adis, indio_dev);

	return 0;
}

