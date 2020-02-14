#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u8 ;
typedef  int u32 ;
struct regmap {int dummy; } ;
struct TYPE_6__ {struct device* parent; } ;
struct iio_dev {char const* name; int num_channels; int /*<<< orphan*/  modes; int /*<<< orphan*/ * info; int /*<<< orphan*/  channels; TYPE_1__ dev; } ;
struct iio_chan_spec {int /*<<< orphan*/  type; } ;
struct gpio_desc {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct bmp280_calib {int T1; int T2; int T3; int P1; int P2; int P3; int P4; int P5; int P6; int P7; int P8; int P9; unsigned int H1; int H2; unsigned int H3; int H4; int H5; int H6; } ;
struct bmp180_calib {int AC1; int AC2; int AC3; int AC4; int AC5; int AC6; int B1; int B2; int MB; int MC; int MD; } ;
struct TYPE_7__ {struct bmp280_calib bmp280; struct bmp180_calib bmp180; } ;
struct bmp280_data {int t_fine; int oversampling_humid; int oversampling_press; int oversampling_temp; int use_eoc; int start_up_time; struct gpio_desc* vddd; struct gpio_desc* vdda; struct device* dev; TYPE_2__ calib; TYPE_3__* chip_info; struct regmap* regmap; int /*<<< orphan*/  lock; int /*<<< orphan*/  done; } ;
typedef  size_t ssize_t ;
typedef  int s64 ;
typedef  int s32 ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  int /*<<< orphan*/  buf ;
typedef  unsigned int __le16 ;
typedef  scalar_t__ __be32 ;
typedef  scalar_t__ __be16 ;
struct TYPE_8__ {int (* read_humid ) (struct bmp280_data*,int*,int*) ;int (* read_press ) (struct bmp280_data*,int*,int*) ;int (* read_temp ) (struct bmp280_data*,int*) ;int* oversampling_humid_avail; int num_oversampling_humid_avail; int (* chip_config ) (struct bmp280_data*) ;int* oversampling_temp_avail; int num_oversampling_temp_avail; int* oversampling_press_avail; int num_oversampling_press_avail; } ;

/* Variables and functions */
 size_t AC1 ; 
 size_t AC2 ; 
 size_t AC3 ; 
 size_t AC4 ; 
 size_t AC5 ; 
 size_t AC6 ; 
 int ARRAY_SIZE (scalar_t__*) ; 
 size_t B1 ; 
 size_t B2 ; 
#define  BME280_CHIP_ID 135 
#define  BMP180_CHIP_ID 134 
 scalar_t__ BMP180_MEAS_PRESS_X (scalar_t__) ; 
 unsigned int BMP180_MEAS_SCO ; 
 scalar_t__ BMP180_MEAS_TEMP ; 
 int BMP180_REG_CALIB_COUNT ; 
 int /*<<< orphan*/  BMP180_REG_CALIB_START ; 
 int /*<<< orphan*/  BMP180_REG_OUT_MSB ; 
#define  BMP280_CHIP_ID 133 
 int BMP280_COMP_PRESS_REG_COUNT ; 
 int BMP280_COMP_TEMP_REG_COUNT ; 
 scalar_t__ BMP280_FILTER_4X ; 
 int /*<<< orphan*/  BMP280_FILTER_MASK ; 
 int BMP280_HUMIDITY_SKIPPED ; 
 int BMP280_MODE_MASK ; 
 scalar_t__ BMP280_MODE_NORMAL ; 
 scalar_t__ BMP280_OSRS_HUMIDITIY_X (int) ; 
 int /*<<< orphan*/  BMP280_OSRS_HUMIDITY_MASK ; 
 int BMP280_OSRS_PRESS_MASK ; 
 scalar_t__ BMP280_OSRS_PRESS_X (int) ; 
 int BMP280_OSRS_TEMP_MASK ; 
 scalar_t__ BMP280_OSRS_TEMP_X (int) ; 
 int BMP280_PRESS_SKIPPED ; 
 int /*<<< orphan*/  BMP280_REG_COMP_H1 ; 
 int /*<<< orphan*/  BMP280_REG_COMP_H2 ; 
 int /*<<< orphan*/  BMP280_REG_COMP_H3 ; 
 int /*<<< orphan*/  BMP280_REG_COMP_H4 ; 
 int /*<<< orphan*/  BMP280_REG_COMP_H5 ; 
 int /*<<< orphan*/  BMP280_REG_COMP_H6 ; 
 int /*<<< orphan*/  BMP280_REG_COMP_PRESS_START ; 
 int /*<<< orphan*/  BMP280_REG_COMP_TEMP_START ; 
 int /*<<< orphan*/  BMP280_REG_CONFIG ; 
 int /*<<< orphan*/  BMP280_REG_CTRL_HUMIDITY ; 
 int /*<<< orphan*/  BMP280_REG_CTRL_MEAS ; 
 int /*<<< orphan*/  BMP280_REG_HUMIDITY_MSB ; 
 int /*<<< orphan*/  BMP280_REG_ID ; 
 int /*<<< orphan*/  BMP280_REG_PRESS_MSB ; 
 int /*<<< orphan*/  BMP280_REG_TEMP_MSB ; 
 int BMP280_TEMP_SKIPPED ; 
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GPIOD_OUT_HIGH ; 
#define  IIO_CHAN_INFO_OVERSAMPLING_RATIO 132 
#define  IIO_CHAN_INFO_PROCESSED 131 
#define  IIO_HUMIDITYRELATIVE 130 
#define  IIO_PRESSURE 129 
#define  IIO_TEMP 128 
 int IIO_VAL_FRACTIONAL ; 
 int IIO_VAL_INT ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 unsigned long IRQF_TRIGGER_RISING ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (struct gpio_desc*) ; 
 size_t MB ; 
 size_t MC ; 
 size_t MD ; 
 size_t P1 ; 
 size_t P2 ; 
 size_t P3 ; 
 size_t P4 ; 
 size_t P5 ; 
 size_t P6 ; 
 size_t P7 ; 
 size_t P8 ; 
 size_t P9 ; 
 scalar_t__ PAGE_SIZE ; 
 int PTR_ERR (struct gpio_desc*) ; 
 size_t T1 ; 
 size_t T2 ; 
 size_t T3 ; 
 int /*<<< orphan*/  add_device_randomness (scalar_t__*,int) ; 
 int be16_to_cpu (scalar_t__) ; 
 int be32_to_cpu (scalar_t__) ; 
 TYPE_3__ bme280_chip_info ; 
 TYPE_3__ bmp180_chip_info ; 
 int /*<<< orphan*/  bmp280_channels ; 
 TYPE_3__ bmp280_chip_info ; 
 int /*<<< orphan*/  bmp280_info ; 
 int /*<<< orphan*/  complete (int /*<<< orphan*/ *) ; 
 scalar_t__ cpu_to_be16 (int) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct iio_dev* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct iio_dev*) ; 
 struct iio_dev* dev_to_iio_dev (struct device*) ; 
 struct gpio_desc* devm_gpiod_get (struct device*,char*,int /*<<< orphan*/ ) ; 
 struct iio_dev* devm_iio_device_alloc (struct device*,int) ; 
 void* devm_regulator_get (struct device*,char*) ; 
 int devm_request_threaded_irq (struct device*,int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ *,unsigned long,char const*,struct bmp280_data*) ; 
 int div64_s64 (int,int) ; 
 int /*<<< orphan*/  gpiod_set_value (struct gpio_desc*,int /*<<< orphan*/ ) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 struct bmp280_data* iio_priv (struct iio_dev*) ; 
 void* ilog2 (int) ; 
 int /*<<< orphan*/  init_completion (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  irq_get_irq_data (int) ; 
 unsigned long irqd_get_trigger_type (int /*<<< orphan*/ ) ; 
 int le16_to_cpu (unsigned int) ; 
 scalar_t__ msecs_to_jiffies (int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_runtime_disable (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_enable (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_get_noresume (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_get_sync (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_mark_last_busy (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_put (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_put_autosuspend (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_put_noidle (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_set_active (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_set_autosuspend_delay (struct device*,int) ; 
 int /*<<< orphan*/  pm_runtime_use_autosuspend (struct device*) ; 
 int regmap_bulk_read (struct regmap*,int /*<<< orphan*/ ,...) ; 
 int regmap_read (struct regmap*,int /*<<< orphan*/ ,unsigned int*) ; 
 int regmap_update_bits (struct regmap*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__) ; 
 int regmap_write (struct regmap*,int /*<<< orphan*/ ,scalar_t__) ; 
 int regmap_write_bits (struct regmap*,int /*<<< orphan*/ ,int,scalar_t__) ; 
 int /*<<< orphan*/  regulator_disable (struct gpio_desc*) ; 
 int regulator_enable (struct gpio_desc*) ; 
 scalar_t__ scnprintf (char*,scalar_t__,char*,int const) ; 
 void* sign_extend32 (unsigned int,int) ; 
 int stub1 (struct bmp280_data*,int*,int*) ; 
 int stub2 (struct bmp280_data*,int*,int*) ; 
 int stub3 (struct bmp280_data*,int*) ; 
 int stub4 (struct bmp280_data*) ; 
 int stub5 (struct bmp280_data*) ; 
 int stub6 (struct bmp280_data*) ; 
 int stub7 (struct bmp280_data*) ; 
 int /*<<< orphan*/  usleep_range (unsigned int,int) ; 
 int wait_for_completion_timeout (int /*<<< orphan*/ *,scalar_t__) ; 

__attribute__((used)) static int bmp280_read_calib(struct bmp280_data *data,
			     struct bmp280_calib *calib,
			     unsigned int chip)
{
	int ret;
	unsigned int tmp;
	struct device *dev = data->dev;
	__le16 t_buf[BMP280_COMP_TEMP_REG_COUNT / 2];
	__le16 p_buf[BMP280_COMP_PRESS_REG_COUNT / 2];

	/* Read temperature calibration values. */
	ret = regmap_bulk_read(data->regmap, BMP280_REG_COMP_TEMP_START,
			       t_buf, BMP280_COMP_TEMP_REG_COUNT);
	if (ret < 0) {
		dev_err(data->dev,
			"failed to read temperature calibration parameters\n");
		return ret;
	}

	calib->T1 = le16_to_cpu(t_buf[T1]);
	calib->T2 = le16_to_cpu(t_buf[T2]);
	calib->T3 = le16_to_cpu(t_buf[T3]);

	/* Read pressure calibration values. */
	ret = regmap_bulk_read(data->regmap, BMP280_REG_COMP_PRESS_START,
			       p_buf, BMP280_COMP_PRESS_REG_COUNT);
	if (ret < 0) {
		dev_err(data->dev,
			"failed to read pressure calibration parameters\n");
		return ret;
	}

	calib->P1 = le16_to_cpu(p_buf[P1]);
	calib->P2 = le16_to_cpu(p_buf[P2]);
	calib->P3 = le16_to_cpu(p_buf[P3]);
	calib->P4 = le16_to_cpu(p_buf[P4]);
	calib->P5 = le16_to_cpu(p_buf[P5]);
	calib->P6 = le16_to_cpu(p_buf[P6]);
	calib->P7 = le16_to_cpu(p_buf[P7]);
	calib->P8 = le16_to_cpu(p_buf[P8]);
	calib->P9 = le16_to_cpu(p_buf[P9]);

	/*
	 * Read humidity calibration values.
	 * Due to some odd register addressing we cannot just
	 * do a big bulk read. Instead, we have to read each Hx
	 * value separately and sometimes do some bit shifting...
	 * Humidity data is only available on BME280.
	 */
	if (chip != BME280_CHIP_ID)
		return 0;

	ret = regmap_read(data->regmap, BMP280_REG_COMP_H1, &tmp);
	if (ret < 0) {
		dev_err(dev, "failed to read H1 comp value\n");
		return ret;
	}
	calib->H1 = tmp;

	ret = regmap_bulk_read(data->regmap, BMP280_REG_COMP_H2, &tmp, 2);
	if (ret < 0) {
		dev_err(dev, "failed to read H2 comp value\n");
		return ret;
	}
	calib->H2 = sign_extend32(le16_to_cpu(tmp), 15);

	ret = regmap_read(data->regmap, BMP280_REG_COMP_H3, &tmp);
	if (ret < 0) {
		dev_err(dev, "failed to read H3 comp value\n");
		return ret;
	}
	calib->H3 = tmp;

	ret = regmap_bulk_read(data->regmap, BMP280_REG_COMP_H4, &tmp, 2);
	if (ret < 0) {
		dev_err(dev, "failed to read H4 comp value\n");
		return ret;
	}
	calib->H4 = sign_extend32(((be16_to_cpu(tmp) >> 4) & 0xff0) |
				  (be16_to_cpu(tmp) & 0xf), 11);

	ret = regmap_bulk_read(data->regmap, BMP280_REG_COMP_H5, &tmp, 2);
	if (ret < 0) {
		dev_err(dev, "failed to read H5 comp value\n");
		return ret;
	}
	calib->H5 = sign_extend32(((le16_to_cpu(tmp) >> 4) & 0xfff), 11);

	ret = regmap_read(data->regmap, BMP280_REG_COMP_H6, &tmp);
	if (ret < 0) {
		dev_err(dev, "failed to read H6 comp value\n");
		return ret;
	}
	calib->H6 = sign_extend32(tmp, 7);

	return 0;
}

__attribute__((used)) static u32 bmp280_compensate_humidity(struct bmp280_data *data,
				      s32 adc_humidity)
{
	s32 var;
	struct bmp280_calib *calib = &data->calib.bmp280;

	var = ((s32)data->t_fine) - (s32)76800;
	var = ((((adc_humidity << 14) - (calib->H4 << 20) - (calib->H5 * var))
		+ (s32)16384) >> 15) * (((((((var * calib->H6) >> 10)
		* (((var * (s32)calib->H3) >> 11) + (s32)32768)) >> 10)
		+ (s32)2097152) * calib->H2 + 8192) >> 14);
	var -= ((((var >> 15) * (var >> 15)) >> 7) * (s32)calib->H1) >> 4;

	return var >> 12;
}

__attribute__((used)) static s32 bmp280_compensate_temp(struct bmp280_data *data,
				  s32 adc_temp)
{
	s32 var1, var2;
	struct bmp280_calib *calib = &data->calib.bmp280;

	var1 = (((adc_temp >> 3) - ((s32)calib->T1 << 1)) *
		((s32)calib->T2)) >> 11;
	var2 = (((((adc_temp >> 4) - ((s32)calib->T1)) *
		  ((adc_temp >> 4) - ((s32)calib->T1))) >> 12) *
		((s32)calib->T3)) >> 14;
	data->t_fine = var1 + var2;

	return (data->t_fine * 5 + 128) >> 8;
}

__attribute__((used)) static u32 bmp280_compensate_press(struct bmp280_data *data,
				   s32 adc_press)
{
	s64 var1, var2, p;
	struct bmp280_calib *calib = &data->calib.bmp280;

	var1 = ((s64)data->t_fine) - 128000;
	var2 = var1 * var1 * (s64)calib->P6;
	var2 += (var1 * (s64)calib->P5) << 17;
	var2 += ((s64)calib->P4) << 35;
	var1 = ((var1 * var1 * (s64)calib->P3) >> 8) +
		((var1 * (s64)calib->P2) << 12);
	var1 = ((((s64)1) << 47) + var1) * ((s64)calib->P1) >> 33;

	if (var1 == 0)
		return 0;

	p = ((((s64)1048576 - adc_press) << 31) - var2) * 3125;
	p = div64_s64(p, var1);
	var1 = (((s64)calib->P9) * (p >> 13) * (p >> 13)) >> 25;
	var2 = ((s64)(calib->P8) * p) >> 19;
	p = ((p + var1 + var2) >> 8) + (((s64)calib->P7) << 4);

	return (u32)p;
}

__attribute__((used)) static int bmp280_read_temp(struct bmp280_data *data,
			    int *val)
{
	int ret;
	__be32 tmp = 0;
	s32 adc_temp, comp_temp;

	ret = regmap_bulk_read(data->regmap, BMP280_REG_TEMP_MSB,
			       (u8 *) &tmp, 3);
	if (ret < 0) {
		dev_err(data->dev, "failed to read temperature\n");
		return ret;
	}

	adc_temp = be32_to_cpu(tmp) >> 12;
	if (adc_temp == BMP280_TEMP_SKIPPED) {
		/* reading was skipped */
		dev_err(data->dev, "reading temperature skipped\n");
		return -EIO;
	}
	comp_temp = bmp280_compensate_temp(data, adc_temp);

	/*
	 * val might be NULL if we're called by the read_press routine,
	 * who only cares about the carry over t_fine value.
	 */
	if (val) {
		*val = comp_temp * 10;
		return IIO_VAL_INT;
	}

	return 0;
}

__attribute__((used)) static int bmp280_read_press(struct bmp280_data *data,
			     int *val, int *val2)
{
	int ret;
	__be32 tmp = 0;
	s32 adc_press;
	u32 comp_press;

	/* Read and compensate temperature so we get a reading of t_fine. */
	ret = bmp280_read_temp(data, NULL);
	if (ret < 0)
		return ret;

	ret = regmap_bulk_read(data->regmap, BMP280_REG_PRESS_MSB,
			       (u8 *) &tmp, 3);
	if (ret < 0) {
		dev_err(data->dev, "failed to read pressure\n");
		return ret;
	}

	adc_press = be32_to_cpu(tmp) >> 12;
	if (adc_press == BMP280_PRESS_SKIPPED) {
		/* reading was skipped */
		dev_err(data->dev, "reading pressure skipped\n");
		return -EIO;
	}
	comp_press = bmp280_compensate_press(data, adc_press);

	*val = comp_press;
	*val2 = 256000;

	return IIO_VAL_FRACTIONAL;
}

__attribute__((used)) static int bmp280_read_humid(struct bmp280_data *data, int *val, int *val2)
{
	int ret;
	__be16 tmp = 0;
	s32 adc_humidity;
	u32 comp_humidity;

	/* Read and compensate temperature so we get a reading of t_fine. */
	ret = bmp280_read_temp(data, NULL);
	if (ret < 0)
		return ret;

	ret = regmap_bulk_read(data->regmap, BMP280_REG_HUMIDITY_MSB,
			       (u8 *) &tmp, 2);
	if (ret < 0) {
		dev_err(data->dev, "failed to read humidity\n");
		return ret;
	}

	adc_humidity = be16_to_cpu(tmp);
	if (adc_humidity == BMP280_HUMIDITY_SKIPPED) {
		/* reading was skipped */
		dev_err(data->dev, "reading humidity skipped\n");
		return -EIO;
	}
	comp_humidity = bmp280_compensate_humidity(data, adc_humidity);

	*val = comp_humidity * 1000 / 1024;

	return IIO_VAL_INT;
}

__attribute__((used)) static int bmp280_read_raw(struct iio_dev *indio_dev,
			   struct iio_chan_spec const *chan,
			   int *val, int *val2, long mask)
{
	int ret;
	struct bmp280_data *data = iio_priv(indio_dev);

	pm_runtime_get_sync(data->dev);
	mutex_lock(&data->lock);

	switch (mask) {
	case IIO_CHAN_INFO_PROCESSED:
		switch (chan->type) {
		case IIO_HUMIDITYRELATIVE:
			ret = data->chip_info->read_humid(data, val, val2);
			break;
		case IIO_PRESSURE:
			ret = data->chip_info->read_press(data, val, val2);
			break;
		case IIO_TEMP:
			ret = data->chip_info->read_temp(data, val);
			break;
		default:
			ret = -EINVAL;
			break;
		}
		break;
	case IIO_CHAN_INFO_OVERSAMPLING_RATIO:
		switch (chan->type) {
		case IIO_HUMIDITYRELATIVE:
			*val = 1 << data->oversampling_humid;
			ret = IIO_VAL_INT;
			break;
		case IIO_PRESSURE:
			*val = 1 << data->oversampling_press;
			ret = IIO_VAL_INT;
			break;
		case IIO_TEMP:
			*val = 1 << data->oversampling_temp;
			ret = IIO_VAL_INT;
			break;
		default:
			ret = -EINVAL;
			break;
		}
		break;
	default:
		ret = -EINVAL;
		break;
	}

	mutex_unlock(&data->lock);
	pm_runtime_mark_last_busy(data->dev);
	pm_runtime_put_autosuspend(data->dev);

	return ret;
}

__attribute__((used)) static int bmp280_write_oversampling_ratio_humid(struct bmp280_data *data,
					       int val)
{
	int i;
	const int *avail = data->chip_info->oversampling_humid_avail;
	const int n = data->chip_info->num_oversampling_humid_avail;

	for (i = 0; i < n; i++) {
		if (avail[i] == val) {
			data->oversampling_humid = ilog2(val);

			return data->chip_info->chip_config(data);
		}
	}
	return -EINVAL;
}

__attribute__((used)) static int bmp280_write_oversampling_ratio_temp(struct bmp280_data *data,
					       int val)
{
	int i;
	const int *avail = data->chip_info->oversampling_temp_avail;
	const int n = data->chip_info->num_oversampling_temp_avail;

	for (i = 0; i < n; i++) {
		if (avail[i] == val) {
			data->oversampling_temp = ilog2(val);

			return data->chip_info->chip_config(data);
		}
	}
	return -EINVAL;
}

__attribute__((used)) static int bmp280_write_oversampling_ratio_press(struct bmp280_data *data,
					       int val)
{
	int i;
	const int *avail = data->chip_info->oversampling_press_avail;
	const int n = data->chip_info->num_oversampling_press_avail;

	for (i = 0; i < n; i++) {
		if (avail[i] == val) {
			data->oversampling_press = ilog2(val);

			return data->chip_info->chip_config(data);
		}
	}
	return -EINVAL;
}

__attribute__((used)) static int bmp280_write_raw(struct iio_dev *indio_dev,
			    struct iio_chan_spec const *chan,
			    int val, int val2, long mask)
{
	int ret = 0;
	struct bmp280_data *data = iio_priv(indio_dev);

	switch (mask) {
	case IIO_CHAN_INFO_OVERSAMPLING_RATIO:
		pm_runtime_get_sync(data->dev);
		mutex_lock(&data->lock);
		switch (chan->type) {
		case IIO_HUMIDITYRELATIVE:
			ret = bmp280_write_oversampling_ratio_humid(data, val);
			break;
		case IIO_PRESSURE:
			ret = bmp280_write_oversampling_ratio_press(data, val);
			break;
		case IIO_TEMP:
			ret = bmp280_write_oversampling_ratio_temp(data, val);
			break;
		default:
			ret = -EINVAL;
			break;
		}
		mutex_unlock(&data->lock);
		pm_runtime_mark_last_busy(data->dev);
		pm_runtime_put_autosuspend(data->dev);
		break;
	default:
		return -EINVAL;
	}

	return ret;
}

__attribute__((used)) static ssize_t bmp280_show_avail(char *buf, const int *vals, const int n)
{
	size_t len = 0;
	int i;

	for (i = 0; i < n; i++)
		len += scnprintf(buf + len, PAGE_SIZE - len, "%d ", vals[i]);

	buf[len - 1] = '\n';

	return len;
}

__attribute__((used)) static ssize_t bmp280_show_temp_oversampling_avail(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	struct bmp280_data *data = iio_priv(dev_to_iio_dev(dev));

	return bmp280_show_avail(buf, data->chip_info->oversampling_temp_avail,
				 data->chip_info->num_oversampling_temp_avail);
}

__attribute__((used)) static ssize_t bmp280_show_press_oversampling_avail(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	struct bmp280_data *data = iio_priv(dev_to_iio_dev(dev));

	return bmp280_show_avail(buf, data->chip_info->oversampling_press_avail,
				 data->chip_info->num_oversampling_press_avail);
}

__attribute__((used)) static int bmp280_chip_config(struct bmp280_data *data)
{
	int ret;
	u8 osrs = BMP280_OSRS_TEMP_X(data->oversampling_temp + 1) |
		  BMP280_OSRS_PRESS_X(data->oversampling_press + 1);

	ret = regmap_write_bits(data->regmap, BMP280_REG_CTRL_MEAS,
				 BMP280_OSRS_TEMP_MASK |
				 BMP280_OSRS_PRESS_MASK |
				 BMP280_MODE_MASK,
				 osrs | BMP280_MODE_NORMAL);
	if (ret < 0) {
		dev_err(data->dev,
			"failed to write ctrl_meas register\n");
		return ret;
	}

	ret = regmap_update_bits(data->regmap, BMP280_REG_CONFIG,
				 BMP280_FILTER_MASK,
				 BMP280_FILTER_4X);
	if (ret < 0) {
		dev_err(data->dev,
			"failed to write config register\n");
		return ret;
	}

	return ret;
}

__attribute__((used)) static int bme280_chip_config(struct bmp280_data *data)
{
	int ret;
	u8 osrs = BMP280_OSRS_HUMIDITIY_X(data->oversampling_humid + 1);

	/*
	 * Oversampling of humidity must be set before oversampling of
	 * temperature/pressure is set to become effective.
	 */
	ret = regmap_update_bits(data->regmap, BMP280_REG_CTRL_HUMIDITY,
				  BMP280_OSRS_HUMIDITY_MASK, osrs);

	if (ret < 0)
		return ret;

	return bmp280_chip_config(data);
}

__attribute__((used)) static int bmp180_measure(struct bmp280_data *data, u8 ctrl_meas)
{
	int ret;
	const int conversion_time_max[] = { 4500, 7500, 13500, 25500 };
	unsigned int delay_us;
	unsigned int ctrl;

	if (data->use_eoc)
		init_completion(&data->done);

	ret = regmap_write(data->regmap, BMP280_REG_CTRL_MEAS, ctrl_meas);
	if (ret)
		return ret;

	if (data->use_eoc) {
		/*
		 * If we have a completion interrupt, use it, wait up to
		 * 100ms. The longest conversion time listed is 76.5 ms for
		 * advanced resolution mode.
		 */
		ret = wait_for_completion_timeout(&data->done,
						  1 + msecs_to_jiffies(100));
		if (!ret)
			dev_err(data->dev, "timeout waiting for completion\n");
	} else {
		if (ctrl_meas == BMP180_MEAS_TEMP)
			delay_us = 4500;
		else
			delay_us =
				conversion_time_max[data->oversampling_press];

		usleep_range(delay_us, delay_us + 1000);
	}

	ret = regmap_read(data->regmap, BMP280_REG_CTRL_MEAS, &ctrl);
	if (ret)
		return ret;

	/* The value of this bit reset to "0" after conversion is complete */
	if (ctrl & BMP180_MEAS_SCO)
		return -EIO;

	return 0;
}

__attribute__((used)) static int bmp180_read_adc_temp(struct bmp280_data *data, int *val)
{
	int ret;
	__be16 tmp = 0;

	ret = bmp180_measure(data, BMP180_MEAS_TEMP);
	if (ret)
		return ret;

	ret = regmap_bulk_read(data->regmap, BMP180_REG_OUT_MSB, (u8 *)&tmp, 2);
	if (ret)
		return ret;

	*val = be16_to_cpu(tmp);

	return 0;
}

__attribute__((used)) static int bmp180_read_calib(struct bmp280_data *data,
			     struct bmp180_calib *calib)
{
	int ret;
	int i;
	__be16 buf[BMP180_REG_CALIB_COUNT / 2];

	ret = regmap_bulk_read(data->regmap, BMP180_REG_CALIB_START, buf,
			       sizeof(buf));

	if (ret < 0)
		return ret;

	/* None of the words has the value 0 or 0xFFFF */
	for (i = 0; i < ARRAY_SIZE(buf); i++) {
		if (buf[i] == cpu_to_be16(0) || buf[i] == cpu_to_be16(0xffff))
			return -EIO;
	}

	/* Toss the calibration data into the entropy pool */
	add_device_randomness(buf, sizeof(buf));

	calib->AC1 = be16_to_cpu(buf[AC1]);
	calib->AC2 = be16_to_cpu(buf[AC2]);
	calib->AC3 = be16_to_cpu(buf[AC3]);
	calib->AC4 = be16_to_cpu(buf[AC4]);
	calib->AC5 = be16_to_cpu(buf[AC5]);
	calib->AC6 = be16_to_cpu(buf[AC6]);
	calib->B1 = be16_to_cpu(buf[B1]);
	calib->B2 = be16_to_cpu(buf[B2]);
	calib->MB = be16_to_cpu(buf[MB]);
	calib->MC = be16_to_cpu(buf[MC]);
	calib->MD = be16_to_cpu(buf[MD]);

	return 0;
}

__attribute__((used)) static s32 bmp180_compensate_temp(struct bmp280_data *data, s32 adc_temp)
{
	s32 x1, x2;
	struct bmp180_calib *calib = &data->calib.bmp180;

	x1 = ((adc_temp - calib->AC6) * calib->AC5) >> 15;
	x2 = (calib->MC << 11) / (x1 + calib->MD);
	data->t_fine = x1 + x2;

	return (data->t_fine + 8) >> 4;
}

__attribute__((used)) static int bmp180_read_temp(struct bmp280_data *data, int *val)
{
	int ret;
	s32 adc_temp, comp_temp;

	ret = bmp180_read_adc_temp(data, &adc_temp);
	if (ret)
		return ret;

	comp_temp = bmp180_compensate_temp(data, adc_temp);

	/*
	 * val might be NULL if we're called by the read_press routine,
	 * who only cares about the carry over t_fine value.
	 */
	if (val) {
		*val = comp_temp * 100;
		return IIO_VAL_INT;
	}

	return 0;
}

__attribute__((used)) static int bmp180_read_adc_press(struct bmp280_data *data, int *val)
{
	int ret;
	__be32 tmp = 0;
	u8 oss = data->oversampling_press;

	ret = bmp180_measure(data, BMP180_MEAS_PRESS_X(oss));
	if (ret)
		return ret;

	ret = regmap_bulk_read(data->regmap, BMP180_REG_OUT_MSB, (u8 *)&tmp, 3);
	if (ret)
		return ret;

	*val = (be32_to_cpu(tmp) >> 8) >> (8 - oss);

	return 0;
}

__attribute__((used)) static u32 bmp180_compensate_press(struct bmp280_data *data, s32 adc_press)
{
	s32 x1, x2, x3, p;
	s32 b3, b6;
	u32 b4, b7;
	s32 oss = data->oversampling_press;
	struct bmp180_calib *calib = &data->calib.bmp180;

	b6 = data->t_fine - 4000;
	x1 = (calib->B2 * (b6 * b6 >> 12)) >> 11;
	x2 = calib->AC2 * b6 >> 11;
	x3 = x1 + x2;
	b3 = ((((s32)calib->AC1 * 4 + x3) << oss) + 2) / 4;
	x1 = calib->AC3 * b6 >> 13;
	x2 = (calib->B1 * ((b6 * b6) >> 12)) >> 16;
	x3 = (x1 + x2 + 2) >> 2;
	b4 = calib->AC4 * (u32)(x3 + 32768) >> 15;
	b7 = ((u32)adc_press - b3) * (50000 >> oss);
	if (b7 < 0x80000000)
		p = (b7 * 2) / b4;
	else
		p = (b7 / b4) * 2;

	x1 = (p >> 8) * (p >> 8);
	x1 = (x1 * 3038) >> 16;
	x2 = (-7357 * p) >> 16;

	return p + ((x1 + x2 + 3791) >> 4);
}

__attribute__((used)) static int bmp180_read_press(struct bmp280_data *data,
			     int *val, int *val2)
{
	int ret;
	s32 adc_press;
	u32 comp_press;

	/* Read and compensate temperature so we get a reading of t_fine. */
	ret = bmp180_read_temp(data, NULL);
	if (ret)
		return ret;

	ret = bmp180_read_adc_press(data, &adc_press);
	if (ret)
		return ret;

	comp_press = bmp180_compensate_press(data, adc_press);

	*val = comp_press;
	*val2 = 1000;

	return IIO_VAL_FRACTIONAL;
}

__attribute__((used)) static int bmp180_chip_config(struct bmp280_data *data)
{
	return 0;
}

__attribute__((used)) static irqreturn_t bmp085_eoc_irq(int irq, void *d)
{
	struct bmp280_data *data = d;

	complete(&data->done);

	return IRQ_HANDLED;
}

__attribute__((used)) static int bmp085_fetch_eoc_irq(struct device *dev,
				const char *name,
				int irq,
				struct bmp280_data *data)
{
	unsigned long irq_trig;
	int ret;

	irq_trig = irqd_get_trigger_type(irq_get_irq_data(irq));
	if (irq_trig != IRQF_TRIGGER_RISING) {
		dev_err(dev, "non-rising trigger given for EOC interrupt, "
			"trying to enforce it\n");
		irq_trig = IRQF_TRIGGER_RISING;
	}
	ret = devm_request_threaded_irq(dev,
			irq,
			bmp085_eoc_irq,
			NULL,
			irq_trig,
			name,
			data);
	if (ret) {
		/* Bail out without IRQ but keep the driver in place */
		dev_err(dev, "unable to request DRDY IRQ\n");
		return 0;
	}

	data->use_eoc = true;
	return 0;
}

int bmp280_common_probe(struct device *dev,
			struct regmap *regmap,
			unsigned int chip,
			const char *name,
			int irq)
{
	int ret;
	struct iio_dev *indio_dev;
	struct bmp280_data *data;
	unsigned int chip_id;
	struct gpio_desc *gpiod;

	indio_dev = devm_iio_device_alloc(dev, sizeof(*data));
	if (!indio_dev)
		return -ENOMEM;

	data = iio_priv(indio_dev);
	mutex_init(&data->lock);
	data->dev = dev;

	indio_dev->dev.parent = dev;
	indio_dev->name = name;
	indio_dev->channels = bmp280_channels;
	indio_dev->info = &bmp280_info;
	indio_dev->modes = INDIO_DIRECT_MODE;

	switch (chip) {
	case BMP180_CHIP_ID:
		indio_dev->num_channels = 2;
		data->chip_info = &bmp180_chip_info;
		data->oversampling_press = ilog2(8);
		data->oversampling_temp = ilog2(1);
		data->start_up_time = 10000;
		break;
	case BMP280_CHIP_ID:
		indio_dev->num_channels = 2;
		data->chip_info = &bmp280_chip_info;
		data->oversampling_press = ilog2(16);
		data->oversampling_temp = ilog2(2);
		data->start_up_time = 2000;
		break;
	case BME280_CHIP_ID:
		indio_dev->num_channels = 3;
		data->chip_info = &bme280_chip_info;
		data->oversampling_press = ilog2(16);
		data->oversampling_humid = ilog2(16);
		data->oversampling_temp = ilog2(2);
		data->start_up_time = 2000;
		break;
	default:
		return -EINVAL;
	}

	/* Bring up regulators */
	data->vddd = devm_regulator_get(dev, "vddd");
	if (IS_ERR(data->vddd)) {
		dev_err(dev, "failed to get VDDD regulator\n");
		return PTR_ERR(data->vddd);
	}
	ret = regulator_enable(data->vddd);
	if (ret) {
		dev_err(dev, "failed to enable VDDD regulator\n");
		return ret;
	}
	data->vdda = devm_regulator_get(dev, "vdda");
	if (IS_ERR(data->vdda)) {
		dev_err(dev, "failed to get VDDA regulator\n");
		ret = PTR_ERR(data->vdda);
		goto out_disable_vddd;
	}
	ret = regulator_enable(data->vdda);
	if (ret) {
		dev_err(dev, "failed to enable VDDA regulator\n");
		goto out_disable_vddd;
	}
	/* Wait to make sure we started up properly */
	usleep_range(data->start_up_time, data->start_up_time + 100);

	/* Bring chip out of reset if there is an assigned GPIO line */
	gpiod = devm_gpiod_get(dev, "reset", GPIOD_OUT_HIGH);
	/* Deassert the signal */
	if (!IS_ERR(gpiod)) {
		dev_info(dev, "release reset\n");
		gpiod_set_value(gpiod, 0);
	}

	data->regmap = regmap;
	ret = regmap_read(regmap, BMP280_REG_ID, &chip_id);
	if (ret < 0)
		goto out_disable_vdda;
	if (chip_id != chip) {
		dev_err(dev, "bad chip id: expected %x got %x\n",
			chip, chip_id);
		ret = -EINVAL;
		goto out_disable_vdda;
	}

	ret = data->chip_info->chip_config(data);
	if (ret < 0)
		goto out_disable_vdda;

	dev_set_drvdata(dev, indio_dev);

	/*
	 * Some chips have calibration parameters "programmed into the devices'
	 * non-volatile memory during production". Let's read them out at probe
	 * time once. They will not change.
	 */
	if (chip_id  == BMP180_CHIP_ID) {
		ret = bmp180_read_calib(data, &data->calib.bmp180);
		if (ret < 0) {
			dev_err(data->dev,
				"failed to read calibration coefficients\n");
			goto out_disable_vdda;
		}
	} else if (chip_id == BMP280_CHIP_ID || chip_id == BME280_CHIP_ID) {
		ret = bmp280_read_calib(data, &data->calib.bmp280, chip_id);
		if (ret < 0) {
			dev_err(data->dev,
				"failed to read calibration coefficients\n");
			goto out_disable_vdda;
		}
	}

	/*
	 * Attempt to grab an optional EOC IRQ - only the BMP085 has this
	 * however as it happens, the BMP085 shares the chip ID of BMP180
	 * so we look for an IRQ if we have that.
	 */
	if (irq > 0 || (chip_id  == BMP180_CHIP_ID)) {
		ret = bmp085_fetch_eoc_irq(dev, name, irq, data);
		if (ret)
			goto out_disable_vdda;
	}

	/* Enable runtime PM */
	pm_runtime_get_noresume(dev);
	pm_runtime_set_active(dev);
	pm_runtime_enable(dev);
	/*
	 * Set autosuspend to two orders of magnitude larger than the
	 * start-up time.
	 */
	pm_runtime_set_autosuspend_delay(dev, data->start_up_time / 10);
	pm_runtime_use_autosuspend(dev);
	pm_runtime_put(dev);

	ret = iio_device_register(indio_dev);
	if (ret)
		goto out_runtime_pm_disable;


	return 0;

out_runtime_pm_disable:
	pm_runtime_get_sync(data->dev);
	pm_runtime_put_noidle(data->dev);
	pm_runtime_disable(data->dev);
out_disable_vdda:
	regulator_disable(data->vdda);
out_disable_vddd:
	regulator_disable(data->vddd);
	return ret;
}

int bmp280_common_remove(struct device *dev)
{
	struct iio_dev *indio_dev = dev_get_drvdata(dev);
	struct bmp280_data *data = iio_priv(indio_dev);

	iio_device_unregister(indio_dev);
	pm_runtime_get_sync(data->dev);
	pm_runtime_put_noidle(data->dev);
	pm_runtime_disable(data->dev);
	regulator_disable(data->vdda);
	regulator_disable(data->vddd);
	return 0;
}

