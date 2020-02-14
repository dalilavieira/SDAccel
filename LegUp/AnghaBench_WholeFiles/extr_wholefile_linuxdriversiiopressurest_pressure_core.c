#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_18__   TYPE_9__ ;
typedef  struct TYPE_17__   TYPE_8__ ;
typedef  struct TYPE_16__   TYPE_7__ ;
typedef  struct TYPE_15__   TYPE_6__ ;
typedef  struct TYPE_14__   TYPE_5__ ;
typedef  struct TYPE_13__   TYPE_4__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
struct st_sensors_platform_data {int dummy; } ;
struct st_sensor_fullscale_avl {int gain; int gain2; } ;
struct TYPE_11__ {int /*<<< orphan*/  buf_lock; } ;
struct st_sensor_data {int odr; int (* get_irq_data_ready ) (struct iio_dev*) ;TYPE_9__* sensor_settings; struct st_sensor_fullscale_avl* current_fullscale; int /*<<< orphan*/  multiread_bit; scalar_t__ num_data_channels; TYPE_2__ tb; TYPE_1__* dev; } ;
struct iio_dev {int /*<<< orphan*/  name; int /*<<< orphan*/  dev; scalar_t__ num_channels; int /*<<< orphan*/  channels; int /*<<< orphan*/ * info; int /*<<< orphan*/  modes; int /*<<< orphan*/  mlock; } ;
struct iio_chan_spec {int /*<<< orphan*/  type; } ;
struct TYPE_16__ {scalar_t__ addr; } ;
struct TYPE_15__ {scalar_t__ addr; } ;
struct TYPE_17__ {TYPE_7__ int2; TYPE_6__ int1; } ;
struct TYPE_14__ {TYPE_4__* odr_avl; } ;
struct TYPE_12__ {int /*<<< orphan*/ * fs_avl; } ;
struct TYPE_18__ {TYPE_8__ drdy_irq; TYPE_5__ odr; TYPE_3__ fs; scalar_t__ num_ch; int /*<<< orphan*/  ch; int /*<<< orphan*/  multi_read_bit; } ;
struct TYPE_13__ {int hz; } ;
struct TYPE_10__ {scalar_t__ platform_data; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
#define  IIO_CHAN_INFO_OFFSET 133 
#define  IIO_CHAN_INFO_RAW 132 
#define  IIO_CHAN_INFO_SAMP_FREQ 131 
#define  IIO_CHAN_INFO_SCALE 130 
#define  IIO_PRESSURE 129 
#define  IIO_TEMP 128 
 int IIO_VAL_FRACTIONAL ; 
 int IIO_VAL_INT ; 
 int IIO_VAL_INT_PLUS_NANO ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int MCELSIUS_PER_CELSIUS ; 
 int ST_PRESS_MILLI_CELSIUS_OFFSET ; 
 int /*<<< orphan*/  ST_PRESS_TRIGGER_OPS ; 
 int /*<<< orphan*/  default_press_pdata ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 struct st_sensor_data* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  press_info ; 
 int /*<<< orphan*/  st_press_sensors_settings ; 
 int st_sensors_allocate_trigger (struct iio_dev*,int /*<<< orphan*/ ) ; 
 int st_sensors_check_device_support (struct iio_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  st_sensors_deallocate_trigger (struct iio_dev*) ; 
 int st_sensors_init_sensor (struct iio_dev*,struct st_sensors_platform_data*) ; 
 int /*<<< orphan*/  st_sensors_power_disable (struct iio_dev*) ; 
 int st_sensors_power_enable (struct iio_dev*) ; 
 int st_sensors_read_info_raw (struct iio_dev*,struct iio_chan_spec const*,int*) ; 
 int st_sensors_set_odr (struct iio_dev*,int) ; 
 int stub1 (struct iio_dev*) ; 
 scalar_t__ stub2 (struct iio_dev*) ; 

__attribute__((used)) static inline int st_press_allocate_ring(struct iio_dev *indio_dev)
{
	return 0;
}

__attribute__((used)) static inline void st_press_deallocate_ring(struct iio_dev *indio_dev)
{
}

__attribute__((used)) static int st_press_write_raw(struct iio_dev *indio_dev,
			      struct iio_chan_spec const *ch,
			      int val,
			      int val2,
			      long mask)
{
	int err;

	switch (mask) {
	case IIO_CHAN_INFO_SAMP_FREQ:
		if (val2)
			return -EINVAL;
		mutex_lock(&indio_dev->mlock);
		err = st_sensors_set_odr(indio_dev, val);
		mutex_unlock(&indio_dev->mlock);
		return err;
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int st_press_read_raw(struct iio_dev *indio_dev,
			struct iio_chan_spec const *ch, int *val,
							int *val2, long mask)
{
	int err;
	struct st_sensor_data *press_data = iio_priv(indio_dev);

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		err = st_sensors_read_info_raw(indio_dev, ch, val);
		if (err < 0)
			goto read_error;

		return IIO_VAL_INT;
	case IIO_CHAN_INFO_SCALE:
		switch (ch->type) {
		case IIO_PRESSURE:
			*val = 0;
			*val2 = press_data->current_fullscale->gain;
			return IIO_VAL_INT_PLUS_NANO;
		case IIO_TEMP:
			*val = MCELSIUS_PER_CELSIUS;
			*val2 = press_data->current_fullscale->gain2;
			return IIO_VAL_FRACTIONAL;
		default:
			err = -EINVAL;
			goto read_error;
		}

	case IIO_CHAN_INFO_OFFSET:
		switch (ch->type) {
		case IIO_TEMP:
			*val = ST_PRESS_MILLI_CELSIUS_OFFSET *
			       press_data->current_fullscale->gain2;
			*val2 = MCELSIUS_PER_CELSIUS;
			break;
		default:
			err = -EINVAL;
			goto read_error;
		}

		return IIO_VAL_FRACTIONAL;
	case IIO_CHAN_INFO_SAMP_FREQ:
		*val = press_data->odr;
		return IIO_VAL_INT;
	default:
		return -EINVAL;
	}

read_error:
	return err;
}

int st_press_common_probe(struct iio_dev *indio_dev)
{
	struct st_sensor_data *press_data = iio_priv(indio_dev);
	struct st_sensors_platform_data *pdata =
		(struct st_sensors_platform_data *)press_data->dev->platform_data;
	int irq = press_data->get_irq_data_ready(indio_dev);
	int err;

	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->info = &press_info;
	mutex_init(&press_data->tb.buf_lock);

	err = st_sensors_power_enable(indio_dev);
	if (err)
		return err;

	err = st_sensors_check_device_support(indio_dev,
					ARRAY_SIZE(st_press_sensors_settings),
					st_press_sensors_settings);
	if (err < 0)
		goto st_press_power_off;

	/*
	 * Skip timestamping channel while declaring available channels to
	 * common st_sensor layer. Look at st_sensors_get_buffer_element() to
	 * see how timestamps are explicitly pushed as last samples block
	 * element.
	 */
	press_data->num_data_channels = press_data->sensor_settings->num_ch - 1;
	press_data->multiread_bit = press_data->sensor_settings->multi_read_bit;
	indio_dev->channels = press_data->sensor_settings->ch;
	indio_dev->num_channels = press_data->sensor_settings->num_ch;

	press_data->current_fullscale =
		(struct st_sensor_fullscale_avl *)
			&press_data->sensor_settings->fs.fs_avl[0];

	press_data->odr = press_data->sensor_settings->odr.odr_avl[0].hz;

	/* Some devices don't support a data ready pin. */
	if (!pdata && (press_data->sensor_settings->drdy_irq.int1.addr ||
		       press_data->sensor_settings->drdy_irq.int2.addr))
		pdata =	(struct st_sensors_platform_data *)&default_press_pdata;

	err = st_sensors_init_sensor(indio_dev, pdata);
	if (err < 0)
		goto st_press_power_off;

	err = st_press_allocate_ring(indio_dev);
	if (err < 0)
		goto st_press_power_off;

	if (irq > 0) {
		err = st_sensors_allocate_trigger(indio_dev,
						  ST_PRESS_TRIGGER_OPS);
		if (err < 0)
			goto st_press_probe_trigger_error;
	}

	err = iio_device_register(indio_dev);
	if (err)
		goto st_press_device_register_error;

	dev_info(&indio_dev->dev, "registered pressure sensor %s\n",
		 indio_dev->name);

	return err;

st_press_device_register_error:
	if (irq > 0)
		st_sensors_deallocate_trigger(indio_dev);
st_press_probe_trigger_error:
	st_press_deallocate_ring(indio_dev);
st_press_power_off:
	st_sensors_power_disable(indio_dev);

	return err;
}

void st_press_common_remove(struct iio_dev *indio_dev)
{
	struct st_sensor_data *press_data = iio_priv(indio_dev);

	st_sensors_power_disable(indio_dev);

	iio_device_unregister(indio_dev);
	if (press_data->get_irq_data_ready(indio_dev) > 0)
		st_sensors_deallocate_trigger(indio_dev);

	st_press_deallocate_ring(indio_dev);
}

