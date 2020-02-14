#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int uint16_t ;
typedef  int u16 ;
struct ms5611_state {int (* read_prom_word ) (struct device*,int,int*) ;int (* read_adc_temp_and_pressure ) (struct device*,int*,int*) ;int (* reset ) (struct device*) ;struct ms5611_osr const* pressure_osr; struct ms5611_osr const* temp_osr; TYPE_1__* chip_info; int /*<<< orphan*/  lock; int /*<<< orphan*/  vdd; } ;
typedef  struct ms5611_osr {unsigned short rate; } const ms5611_osr ;
struct ms5611_chip_info {int* prom; } ;
struct iio_poll_func {struct iio_dev const* indio_dev; } ;
struct device {struct device* parent; } ;
typedef  struct iio_dev {char const* name; int num_channels; int /*<<< orphan*/  available_scan_masks; int /*<<< orphan*/  modes; struct ms5611_osr const* channels; int /*<<< orphan*/ * info; struct device dev; int /*<<< orphan*/  trig; } const iio_dev ;
struct iio_chan_spec {int const type; } ;
typedef  int s64 ;
typedef  int s32 ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_3__ {int* prom; int (* temp_and_pressure_compensate ) (TYPE_1__*,int*,int*) ;} ;

/* Variables and functions */
 int ARRAY_SIZE (struct ms5611_osr const*) ; 
 int EINVAL ; 
 int ENODEV ; 
#define  IIO_CHAN_INFO_OVERSAMPLING_RATIO 132 
#define  IIO_CHAN_INFO_PROCESSED 131 
#define  IIO_CHAN_INFO_SCALE 130 
#define  IIO_PRESSURE 129 
#define  IIO_TEMP 128 
 int IIO_VAL_INT ; 
 int IIO_VAL_INT_PLUS_MICRO ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int MS5611_PROM_WORDS_NB ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 TYPE_1__* chip_info_tbl ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 int /*<<< orphan*/  devm_regulator_get (struct device*,char*) ; 
 int iio_device_claim_direct_mode (struct iio_dev const*) ; 
 int iio_device_register (struct iio_dev const*) ; 
 int /*<<< orphan*/  iio_device_release_direct_mode (struct iio_dev const*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev const*) ; 
 int /*<<< orphan*/  iio_get_time_ns (struct iio_dev const*) ; 
 void* iio_priv (struct iio_dev const*) ; 
 int /*<<< orphan*/  iio_push_to_buffers_with_timestamp (struct iio_dev const*,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iio_trigger_notify_done (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iio_triggered_buffer_cleanup (struct iio_dev const*) ; 
 int iio_triggered_buffer_setup (struct iio_dev const*,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ *) ; 
 struct ms5611_osr const* ms5611_avail_pressure_osr ; 
 struct ms5611_osr const* ms5611_avail_temp_osr ; 
 struct ms5611_osr const* ms5611_channels ; 
 int /*<<< orphan*/  ms5611_info ; 
 int /*<<< orphan*/  ms5611_scan_masks ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  regulator_disable (int /*<<< orphan*/ ) ; 
 int regulator_enable (int /*<<< orphan*/ ) ; 
 int stub1 (struct device*,int,int*) ; 
 int stub2 (struct device*,int*,int*) ; 
 int stub3 (TYPE_1__*,int*,int*) ; 
 int stub4 (struct device*) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static bool ms5611_prom_is_valid(u16 *prom, size_t len)
{
	int i, j;
	uint16_t crc = 0, crc_orig = prom[7] & 0x000F;

	prom[7] &= 0xFF00;

	for (i = 0; i < len * 2; i++) {
		if (i % 2 == 1)
			crc ^= prom[i >> 1] & 0x00FF;
		else
			crc ^= prom[i >> 1] >> 8;

		for (j = 0; j < 8; j++) {
			if (crc & 0x8000)
				crc = (crc << 1) ^ 0x3000;
			else
				crc <<= 1;
		}
	}

	crc = (crc >> 12) & 0x000F;

	return crc_orig != 0x0000 && crc == crc_orig;
}

__attribute__((used)) static int ms5611_read_prom(struct iio_dev *indio_dev)
{
	int ret, i;
	struct ms5611_state *st = iio_priv(indio_dev);

	for (i = 0; i < MS5611_PROM_WORDS_NB; i++) {
		ret = st->read_prom_word(&indio_dev->dev,
					 i, &st->chip_info->prom[i]);
		if (ret < 0) {
			dev_err(&indio_dev->dev,
				"failed to read prom at %d\n", i);
			return ret;
		}
	}

	if (!ms5611_prom_is_valid(st->chip_info->prom, MS5611_PROM_WORDS_NB)) {
		dev_err(&indio_dev->dev, "PROM integrity check failed\n");
		return -ENODEV;
	}

	return 0;
}

__attribute__((used)) static int ms5611_read_temp_and_pressure(struct iio_dev *indio_dev,
					 s32 *temp, s32 *pressure)
{
	int ret;
	struct ms5611_state *st = iio_priv(indio_dev);

	ret = st->read_adc_temp_and_pressure(&indio_dev->dev, temp, pressure);
	if (ret < 0) {
		dev_err(&indio_dev->dev,
			"failed to read temperature and pressure\n");
		return ret;
	}

	return st->chip_info->temp_and_pressure_compensate(st->chip_info,
							   temp, pressure);
}

__attribute__((used)) static int ms5611_temp_and_pressure_compensate(struct ms5611_chip_info *chip_info,
					       s32 *temp, s32 *pressure)
{
	s32 t = *temp, p = *pressure;
	s64 off, sens, dt;

	dt = t - (chip_info->prom[5] << 8);
	off = ((s64)chip_info->prom[2] << 16) + ((chip_info->prom[4] * dt) >> 7);
	sens = ((s64)chip_info->prom[1] << 15) + ((chip_info->prom[3] * dt) >> 8);

	t = 2000 + ((chip_info->prom[6] * dt) >> 23);
	if (t < 2000) {
		s64 off2, sens2, t2;

		t2 = (dt * dt) >> 31;
		off2 = (5 * (t - 2000) * (t - 2000)) >> 1;
		sens2 = off2 >> 1;

		if (t < -1500) {
			s64 tmp = (t + 1500) * (t + 1500);

			off2 += 7 * tmp;
			sens2 += (11 * tmp) >> 1;
		}

		t -= t2;
		off -= off2;
		sens -= sens2;
	}

	*temp = t;
	*pressure = (((p * sens) >> 21) - off) >> 15;

	return 0;
}

__attribute__((used)) static int ms5607_temp_and_pressure_compensate(struct ms5611_chip_info *chip_info,
					       s32 *temp, s32 *pressure)
{
	s32 t = *temp, p = *pressure;
	s64 off, sens, dt;

	dt = t - (chip_info->prom[5] << 8);
	off = ((s64)chip_info->prom[2] << 17) + ((chip_info->prom[4] * dt) >> 6);
	sens = ((s64)chip_info->prom[1] << 16) + ((chip_info->prom[3] * dt) >> 7);

	t = 2000 + ((chip_info->prom[6] * dt) >> 23);
	if (t < 2000) {
		s64 off2, sens2, t2, tmp;

		t2 = (dt * dt) >> 31;
		tmp = (t - 2000) * (t - 2000);
		off2 = (61 * tmp) >> 4;
		sens2 = tmp << 1;

		if (t < -1500) {
			tmp = (t + 1500) * (t + 1500);
			off2 += 15 * tmp;
			sens2 += 8 * tmp;
		}

		t -= t2;
		off -= off2;
		sens -= sens2;
	}

	*temp = t;
	*pressure = (((p * sens) >> 21) - off) >> 15;

	return 0;
}

__attribute__((used)) static int ms5611_reset(struct iio_dev *indio_dev)
{
	int ret;
	struct ms5611_state *st = iio_priv(indio_dev);

	ret = st->reset(&indio_dev->dev);
	if (ret < 0) {
		dev_err(&indio_dev->dev, "failed to reset device\n");
		return ret;
	}

	usleep_range(3000, 4000);

	return 0;
}

__attribute__((used)) static irqreturn_t ms5611_trigger_handler(int irq, void *p)
{
	struct iio_poll_func *pf = p;
	struct iio_dev *indio_dev = pf->indio_dev;
	struct ms5611_state *st = iio_priv(indio_dev);
	s32 buf[4]; /* s32 (pressure) + s32 (temp) + 2 * s32 (timestamp) */
	int ret;

	mutex_lock(&st->lock);
	ret = ms5611_read_temp_and_pressure(indio_dev, &buf[1], &buf[0]);
	mutex_unlock(&st->lock);
	if (ret < 0)
		goto err;

	iio_push_to_buffers_with_timestamp(indio_dev, buf,
					   iio_get_time_ns(indio_dev));

err:
	iio_trigger_notify_done(indio_dev->trig);

	return IRQ_HANDLED;
}

__attribute__((used)) static int ms5611_read_raw(struct iio_dev *indio_dev,
			   struct iio_chan_spec const *chan,
			   int *val, int *val2, long mask)
{
	int ret;
	s32 temp, pressure;
	struct ms5611_state *st = iio_priv(indio_dev);

	switch (mask) {
	case IIO_CHAN_INFO_PROCESSED:
		mutex_lock(&st->lock);
		ret = ms5611_read_temp_and_pressure(indio_dev,
						    &temp, &pressure);
		mutex_unlock(&st->lock);
		if (ret < 0)
			return ret;

		switch (chan->type) {
		case IIO_TEMP:
			*val = temp * 10;
			return IIO_VAL_INT;
		case IIO_PRESSURE:
			*val = pressure / 1000;
			*val2 = (pressure % 1000) * 1000;
			return IIO_VAL_INT_PLUS_MICRO;
		default:
			return -EINVAL;
		}
	case IIO_CHAN_INFO_SCALE:
		switch (chan->type) {
		case IIO_TEMP:
			*val = 10;
			return IIO_VAL_INT;
		case IIO_PRESSURE:
			*val = 0;
			*val2 = 1000;
			return IIO_VAL_INT_PLUS_MICRO;
		default:
			return -EINVAL;
		}
	case IIO_CHAN_INFO_OVERSAMPLING_RATIO:
		if (chan->type != IIO_TEMP && chan->type != IIO_PRESSURE)
			break;
		mutex_lock(&st->lock);
		if (chan->type == IIO_TEMP)
			*val = (int)st->temp_osr->rate;
		else
			*val = (int)st->pressure_osr->rate;
		mutex_unlock(&st->lock);
		return IIO_VAL_INT;
	}

	return -EINVAL;
}

__attribute__((used)) static const struct ms5611_osr *ms5611_find_osr(int rate,
						const struct ms5611_osr *osr,
						size_t count)
{
	unsigned int r;

	for (r = 0; r < count; r++)
		if ((unsigned short)rate == osr[r].rate)
			break;
	if (r >= count)
		return NULL;
	return &osr[r];
}

__attribute__((used)) static int ms5611_write_raw(struct iio_dev *indio_dev,
			    struct iio_chan_spec const *chan,
			    int val, int val2, long mask)
{
	struct ms5611_state *st = iio_priv(indio_dev);
	const struct ms5611_osr *osr = NULL;
	int ret;

	if (mask != IIO_CHAN_INFO_OVERSAMPLING_RATIO)
		return -EINVAL;

	if (chan->type == IIO_TEMP)
		osr = ms5611_find_osr(val, ms5611_avail_temp_osr,
				      ARRAY_SIZE(ms5611_avail_temp_osr));
	else if (chan->type == IIO_PRESSURE)
		osr = ms5611_find_osr(val, ms5611_avail_pressure_osr,
				      ARRAY_SIZE(ms5611_avail_pressure_osr));
	if (!osr)
		return -EINVAL;

	ret = iio_device_claim_direct_mode(indio_dev);
	if (ret)
		return ret;

	mutex_lock(&st->lock);

	if (chan->type == IIO_TEMP)
		st->temp_osr = osr;
	else
		st->pressure_osr = osr;

	mutex_unlock(&st->lock);
	iio_device_release_direct_mode(indio_dev);

	return 0;
}

__attribute__((used)) static int ms5611_init(struct iio_dev *indio_dev)
{
	int ret;
	struct ms5611_state *st = iio_priv(indio_dev);

	/* Enable attached regulator if any. */
	st->vdd = devm_regulator_get(indio_dev->dev.parent, "vdd");
	if (IS_ERR(st->vdd))
		return PTR_ERR(st->vdd);

	ret = regulator_enable(st->vdd);
	if (ret) {
		dev_err(indio_dev->dev.parent,
			"failed to enable Vdd supply: %d\n", ret);
		return ret;
	}

	ret = ms5611_reset(indio_dev);
	if (ret < 0)
		goto err_regulator_disable;

	ret = ms5611_read_prom(indio_dev);
	if (ret < 0)
		goto err_regulator_disable;

	return 0;

err_regulator_disable:
	regulator_disable(st->vdd);
	return ret;
}

__attribute__((used)) static void ms5611_fini(const struct iio_dev *indio_dev)
{
	const struct ms5611_state *st = iio_priv(indio_dev);

	regulator_disable(st->vdd);
}

int ms5611_probe(struct iio_dev *indio_dev, struct device *dev,
		 const char *name, int type)
{
	int ret;
	struct ms5611_state *st = iio_priv(indio_dev);

	mutex_init(&st->lock);
	st->chip_info = &chip_info_tbl[type];
	st->temp_osr =
		&ms5611_avail_temp_osr[ARRAY_SIZE(ms5611_avail_temp_osr) - 1];
	st->pressure_osr =
		&ms5611_avail_pressure_osr[ARRAY_SIZE(ms5611_avail_pressure_osr)
					   - 1];
	indio_dev->dev.parent = dev;
	indio_dev->name = name;
	indio_dev->info = &ms5611_info;
	indio_dev->channels = ms5611_channels;
	indio_dev->num_channels = ARRAY_SIZE(ms5611_channels);
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->available_scan_masks = ms5611_scan_masks;

	ret = ms5611_init(indio_dev);
	if (ret < 0)
		return ret;

	ret = iio_triggered_buffer_setup(indio_dev, NULL,
					 ms5611_trigger_handler, NULL);
	if (ret < 0) {
		dev_err(dev, "iio triggered buffer setup failed\n");
		goto err_fini;
	}

	ret = iio_device_register(indio_dev);
	if (ret < 0) {
		dev_err(dev, "unable to register iio device\n");
		goto err_buffer_cleanup;
	}

	return 0;

err_buffer_cleanup:
	iio_triggered_buffer_cleanup(indio_dev);
err_fini:
	ms5611_fini(indio_dev);
	return ret;
}

int ms5611_remove(struct iio_dev *indio_dev)
{
	iio_device_unregister(indio_dev);
	iio_triggered_buffer_cleanup(indio_dev);
	ms5611_fini(indio_dev);

	return 0;
}

