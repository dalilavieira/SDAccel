#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct st_sensors_platform_data {int dummy; } ;
struct st_sensor_fullscale_avl {int gain; } ;
struct TYPE_6__ {int /*<<< orphan*/  buf_lock; } ;
struct st_sensor_data {int odr; int (* get_irq_data_ready ) (struct iio_dev*) ;TYPE_5__* sensor_settings; struct st_sensor_fullscale_avl* current_fullscale; int /*<<< orphan*/  multiread_bit; int /*<<< orphan*/  num_data_channels; TYPE_1__ tb; } ;
struct iio_dev {int /*<<< orphan*/  name; int /*<<< orphan*/  dev; int /*<<< orphan*/  num_channels; int /*<<< orphan*/  channels; int /*<<< orphan*/ * info; int /*<<< orphan*/  modes; int /*<<< orphan*/  mlock; } ;
struct iio_chan_spec {int dummy; } ;
struct TYPE_9__ {TYPE_3__* odr_avl; } ;
struct TYPE_7__ {int /*<<< orphan*/ * fs_avl; } ;
struct TYPE_10__ {TYPE_4__ odr; TYPE_2__ fs; int /*<<< orphan*/  ch; int /*<<< orphan*/  multi_read_bit; } ;
struct TYPE_8__ {int hz; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
#define  IIO_CHAN_INFO_RAW 130 
#define  IIO_CHAN_INFO_SAMP_FREQ 129 
#define  IIO_CHAN_INFO_SCALE 128 
 int IIO_VAL_INT ; 
 int IIO_VAL_INT_PLUS_MICRO ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int /*<<< orphan*/  ST_GYRO_NUMBER_DATA_CHANNELS ; 
 int /*<<< orphan*/  ST_GYRO_TRIGGER_OPS ; 
 int /*<<< orphan*/  ST_SENSORS_NUMBER_ALL_CHANNELS ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gyro_info ; 
 int /*<<< orphan*/  gyro_pdata ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 struct st_sensor_data* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  st_gyro_sensors_settings ; 
 int st_sensors_allocate_trigger (struct iio_dev*,int /*<<< orphan*/ ) ; 
 int st_sensors_check_device_support (struct iio_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  st_sensors_deallocate_trigger (struct iio_dev*) ; 
 int st_sensors_init_sensor (struct iio_dev*,struct st_sensors_platform_data*) ; 
 int /*<<< orphan*/  st_sensors_power_disable (struct iio_dev*) ; 
 int st_sensors_power_enable (struct iio_dev*) ; 
 int st_sensors_read_info_raw (struct iio_dev*,struct iio_chan_spec const*,int*) ; 
 int st_sensors_set_fullscale_by_gain (struct iio_dev*,int) ; 
 int st_sensors_set_odr (struct iio_dev*,int) ; 
 int stub1 (struct iio_dev*) ; 
 scalar_t__ stub2 (struct iio_dev*) ; 

__attribute__((used)) static inline int st_gyro_allocate_ring(struct iio_dev *indio_dev)
{
	return 0;
}

__attribute__((used)) static inline void st_gyro_deallocate_ring(struct iio_dev *indio_dev)
{
}

__attribute__((used)) static int st_gyro_read_raw(struct iio_dev *indio_dev,
			struct iio_chan_spec const *ch, int *val,
							int *val2, long mask)
{
	int err;
	struct st_sensor_data *gdata = iio_priv(indio_dev);

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		err = st_sensors_read_info_raw(indio_dev, ch, val);
		if (err < 0)
			goto read_error;

		return IIO_VAL_INT;
	case IIO_CHAN_INFO_SCALE:
		*val = 0;
		*val2 = gdata->current_fullscale->gain;
		return IIO_VAL_INT_PLUS_MICRO;
	case IIO_CHAN_INFO_SAMP_FREQ:
		*val = gdata->odr;
		return IIO_VAL_INT;
	default:
		return -EINVAL;
	}

read_error:
	return err;
}

__attribute__((used)) static int st_gyro_write_raw(struct iio_dev *indio_dev,
		struct iio_chan_spec const *chan, int val, int val2, long mask)
{
	int err;

	switch (mask) {
	case IIO_CHAN_INFO_SCALE:
		err = st_sensors_set_fullscale_by_gain(indio_dev, val2);
		break;
	case IIO_CHAN_INFO_SAMP_FREQ:
		if (val2)
			return -EINVAL;
		mutex_lock(&indio_dev->mlock);
		err = st_sensors_set_odr(indio_dev, val);
		mutex_unlock(&indio_dev->mlock);
		return err;
	default:
		err = -EINVAL;
	}

	return err;
}

int st_gyro_common_probe(struct iio_dev *indio_dev)
{
	struct st_sensor_data *gdata = iio_priv(indio_dev);
	int irq = gdata->get_irq_data_ready(indio_dev);
	int err;

	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->info = &gyro_info;
	mutex_init(&gdata->tb.buf_lock);

	err = st_sensors_power_enable(indio_dev);
	if (err)
		return err;

	err = st_sensors_check_device_support(indio_dev,
					ARRAY_SIZE(st_gyro_sensors_settings),
					st_gyro_sensors_settings);
	if (err < 0)
		goto st_gyro_power_off;

	gdata->num_data_channels = ST_GYRO_NUMBER_DATA_CHANNELS;
	gdata->multiread_bit = gdata->sensor_settings->multi_read_bit;
	indio_dev->channels = gdata->sensor_settings->ch;
	indio_dev->num_channels = ST_SENSORS_NUMBER_ALL_CHANNELS;

	gdata->current_fullscale = (struct st_sensor_fullscale_avl *)
					&gdata->sensor_settings->fs.fs_avl[0];
	gdata->odr = gdata->sensor_settings->odr.odr_avl[0].hz;

	err = st_sensors_init_sensor(indio_dev,
				(struct st_sensors_platform_data *)&gyro_pdata);
	if (err < 0)
		goto st_gyro_power_off;

	err = st_gyro_allocate_ring(indio_dev);
	if (err < 0)
		goto st_gyro_power_off;

	if (irq > 0) {
		err = st_sensors_allocate_trigger(indio_dev,
						  ST_GYRO_TRIGGER_OPS);
		if (err < 0)
			goto st_gyro_probe_trigger_error;
	}

	err = iio_device_register(indio_dev);
	if (err)
		goto st_gyro_device_register_error;

	dev_info(&indio_dev->dev, "registered gyroscope %s\n",
		 indio_dev->name);

	return 0;

st_gyro_device_register_error:
	if (irq > 0)
		st_sensors_deallocate_trigger(indio_dev);
st_gyro_probe_trigger_error:
	st_gyro_deallocate_ring(indio_dev);
st_gyro_power_off:
	st_sensors_power_disable(indio_dev);

	return err;
}

void st_gyro_common_remove(struct iio_dev *indio_dev)
{
	struct st_sensor_data *gdata = iio_priv(indio_dev);

	st_sensors_power_disable(indio_dev);

	iio_device_unregister(indio_dev);
	if (gdata->get_irq_data_ready(indio_dev) > 0)
		st_sensors_deallocate_trigger(indio_dev);

	st_gyro_deallocate_ring(indio_dev);
}

