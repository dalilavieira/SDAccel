#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct iio_sw_device {struct iio_dev* device; } ;
struct iio_dummy_state {int dac_val; int* differential_adc_val; int single_ended_adc_val; int accel_val; int steps; int activity_running; int activity_walking; int accel_calibbias; int steps_enabled; int height; int /*<<< orphan*/  lock; TYPE_1__* accel_calibscale; } ;
struct iio_dev {int num_channels; struct iio_sw_device* name; int /*<<< orphan*/  modes; int /*<<< orphan*/ * info; TYPE_1__* channels; } ;
struct iio_chan_spec {int channel; int /*<<< orphan*/  type; int /*<<< orphan*/  channel2; int /*<<< orphan*/  output; int /*<<< orphan*/  differential; } ;
struct TYPE_4__ {int val; int val2; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_1__*) ; 
 int EINVAL ; 
 int ENOMEM ; 
 struct iio_sw_device* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
#define  IIO_ACCEL 142 
#define  IIO_ACTIVITY 141 
#define  IIO_CHAN_INFO_CALIBBIAS 140 
#define  IIO_CHAN_INFO_CALIBHEIGHT 139 
#define  IIO_CHAN_INFO_CALIBSCALE 138 
#define  IIO_CHAN_INFO_ENABLE 137 
#define  IIO_CHAN_INFO_OFFSET 136 
#define  IIO_CHAN_INFO_PROCESSED 135 
#define  IIO_CHAN_INFO_RAW 134 
#define  IIO_CHAN_INFO_SAMP_FREQ 133 
#define  IIO_CHAN_INFO_SCALE 132 
#define  IIO_MOD_RUNNING 131 
#define  IIO_MOD_WALKING 130 
#define  IIO_STEPS 129 
 int IIO_VAL_INT ; 
 int IIO_VAL_INT_PLUS_MICRO ; 
 int IIO_VAL_INT_PLUS_NANO ; 
#define  IIO_VOLTAGE 128 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 TYPE_1__* dummy_scales ; 
 struct iio_dev* iio_device_alloc (int) ; 
 int /*<<< orphan*/  iio_device_free (struct iio_dev*) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 TYPE_1__* iio_dummy_channels ; 
 int /*<<< orphan*/  iio_dummy_info ; 
 int /*<<< orphan*/  iio_dummy_type ; 
 struct iio_dummy_state* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_swd_group_init_type_name (struct iio_sw_device*,char const*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree (struct iio_sw_device*) ; 
 struct iio_sw_device* kstrdup (char const*,int /*<<< orphan*/ ) ; 
 struct iio_sw_device* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline int
iio_simple_dummy_events_register(struct iio_dev *indio_dev)
{
	return 0;
}

__attribute__((used)) static inline void
iio_simple_dummy_events_unregister(struct iio_dev *indio_dev)
{}

__attribute__((used)) static inline int iio_simple_dummy_configure_buffer(struct iio_dev *indio_dev)
{
	return 0;
}

__attribute__((used)) static inline
void iio_simple_dummy_unconfigure_buffer(struct iio_dev *indio_dev)
{}

__attribute__((used)) static int iio_dummy_read_raw(struct iio_dev *indio_dev,
			      struct iio_chan_spec const *chan,
			      int *val,
			      int *val2,
			      long mask)
{
	struct iio_dummy_state *st = iio_priv(indio_dev);
	int ret = -EINVAL;

	mutex_lock(&st->lock);
	switch (mask) {
	case IIO_CHAN_INFO_RAW: /* magic value - channel value read */
		switch (chan->type) {
		case IIO_VOLTAGE:
			if (chan->output) {
				/* Set integer part to cached value */
				*val = st->dac_val;
				ret = IIO_VAL_INT;
			} else if (chan->differential) {
				if (chan->channel == 1)
					*val = st->differential_adc_val[0];
				else
					*val = st->differential_adc_val[1];
				ret = IIO_VAL_INT;
			} else {
				*val = st->single_ended_adc_val;
				ret = IIO_VAL_INT;
			}
			break;
		case IIO_ACCEL:
			*val = st->accel_val;
			ret = IIO_VAL_INT;
			break;
		default:
			break;
		}
		break;
	case IIO_CHAN_INFO_PROCESSED:
		switch (chan->type) {
		case IIO_STEPS:
			*val = st->steps;
			ret = IIO_VAL_INT;
			break;
		case IIO_ACTIVITY:
			switch (chan->channel2) {
			case IIO_MOD_RUNNING:
				*val = st->activity_running;
				ret = IIO_VAL_INT;
				break;
			case IIO_MOD_WALKING:
				*val = st->activity_walking;
				ret = IIO_VAL_INT;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
		break;
	case IIO_CHAN_INFO_OFFSET:
		/* only single ended adc -> 7 */
		*val = 7;
		ret = IIO_VAL_INT;
		break;
	case IIO_CHAN_INFO_SCALE:
		switch (chan->type) {
		case IIO_VOLTAGE:
			switch (chan->differential) {
			case 0:
				/* only single ended adc -> 0.001333 */
				*val = 0;
				*val2 = 1333;
				ret = IIO_VAL_INT_PLUS_MICRO;
				break;
			case 1:
				/* all differential adc -> 0.000001344 */
				*val = 0;
				*val2 = 1344;
				ret = IIO_VAL_INT_PLUS_NANO;
			}
			break;
		default:
			break;
		}
		break;
	case IIO_CHAN_INFO_CALIBBIAS:
		/* only the acceleration axis - read from cache */
		*val = st->accel_calibbias;
		ret = IIO_VAL_INT;
		break;
	case IIO_CHAN_INFO_CALIBSCALE:
		*val = st->accel_calibscale->val;
		*val2 = st->accel_calibscale->val2;
		ret = IIO_VAL_INT_PLUS_MICRO;
		break;
	case IIO_CHAN_INFO_SAMP_FREQ:
		*val = 3;
		*val2 = 33;
		ret = IIO_VAL_INT_PLUS_NANO;
		break;
	case IIO_CHAN_INFO_ENABLE:
		switch (chan->type) {
		case IIO_STEPS:
			*val = st->steps_enabled;
			ret = IIO_VAL_INT;
			break;
		default:
			break;
		}
		break;
	case IIO_CHAN_INFO_CALIBHEIGHT:
		switch (chan->type) {
		case IIO_STEPS:
			*val = st->height;
			ret = IIO_VAL_INT;
			break;
		default:
			break;
		}
		break;

	default:
		break;
	}
	mutex_unlock(&st->lock);
	return ret;
}

__attribute__((used)) static int iio_dummy_write_raw(struct iio_dev *indio_dev,
			       struct iio_chan_spec const *chan,
			       int val,
			       int val2,
			       long mask)
{
	int i;
	int ret = 0;
	struct iio_dummy_state *st = iio_priv(indio_dev);

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		switch (chan->type) {
		case IIO_VOLTAGE:
			if (chan->output == 0)
				return -EINVAL;

			/* Locking not required as writing single value */
			mutex_lock(&st->lock);
			st->dac_val = val;
			mutex_unlock(&st->lock);
			return 0;
		default:
			return -EINVAL;
		}
	case IIO_CHAN_INFO_PROCESSED:
		switch (chan->type) {
		case IIO_STEPS:
			mutex_lock(&st->lock);
			st->steps = val;
			mutex_unlock(&st->lock);
			return 0;
		case IIO_ACTIVITY:
			if (val < 0)
				val = 0;
			if (val > 100)
				val = 100;
			switch (chan->channel2) {
			case IIO_MOD_RUNNING:
				st->activity_running = val;
				return 0;
			case IIO_MOD_WALKING:
				st->activity_walking = val;
				return 0;
			default:
				return -EINVAL;
			}
			break;
		default:
			return -EINVAL;
		}
	case IIO_CHAN_INFO_CALIBSCALE:
		mutex_lock(&st->lock);
		/* Compare against table - hard matching here */
		for (i = 0; i < ARRAY_SIZE(dummy_scales); i++)
			if (val == dummy_scales[i].val &&
			    val2 == dummy_scales[i].val2)
				break;
		if (i == ARRAY_SIZE(dummy_scales))
			ret = -EINVAL;
		else
			st->accel_calibscale = &dummy_scales[i];
		mutex_unlock(&st->lock);
		return ret;
	case IIO_CHAN_INFO_CALIBBIAS:
		mutex_lock(&st->lock);
		st->accel_calibbias = val;
		mutex_unlock(&st->lock);
		return 0;
	case IIO_CHAN_INFO_ENABLE:
		switch (chan->type) {
		case IIO_STEPS:
			mutex_lock(&st->lock);
			st->steps_enabled = val;
			mutex_unlock(&st->lock);
			return 0;
		default:
			return -EINVAL;
		}
	case IIO_CHAN_INFO_CALIBHEIGHT:
		switch (chan->type) {
		case IIO_STEPS:
			st->height = val;
			return 0;
		default:
			return -EINVAL;
		}

	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int iio_dummy_init_device(struct iio_dev *indio_dev)
{
	struct iio_dummy_state *st = iio_priv(indio_dev);

	st->dac_val = 0;
	st->single_ended_adc_val = 73;
	st->differential_adc_val[0] = 33;
	st->differential_adc_val[1] = -34;
	st->accel_val = 34;
	st->accel_calibbias = -7;
	st->accel_calibscale = &dummy_scales[0];
	st->steps = 47;
	st->activity_running = 98;
	st->activity_walking = 4;

	return 0;
}

__attribute__((used)) static struct iio_sw_device *iio_dummy_probe(const char *name)
{
	int ret;
	struct iio_dev *indio_dev;
	struct iio_dummy_state *st;
	struct iio_sw_device *swd;

	swd = kzalloc(sizeof(*swd), GFP_KERNEL);
	if (!swd) {
		ret = -ENOMEM;
		goto error_kzalloc;
	}
	/*
	 * Allocate an IIO device.
	 *
	 * This structure contains all generic state
	 * information about the device instance.
	 * It also has a region (accessed by iio_priv()
	 * for chip specific state information.
	 */
	indio_dev = iio_device_alloc(sizeof(*st));
	if (!indio_dev) {
		ret = -ENOMEM;
		goto error_ret;
	}

	st = iio_priv(indio_dev);
	mutex_init(&st->lock);

	iio_dummy_init_device(indio_dev);
	/*
	 * With hardware: Set the parent device.
	 * indio_dev->dev.parent = &spi->dev;
	 * indio_dev->dev.parent = &client->dev;
	 */

	 /*
	 * Make the iio_dev struct available to remove function.
	 * Bus equivalents
	 * i2c_set_clientdata(client, indio_dev);
	 * spi_set_drvdata(spi, indio_dev);
	 */
	swd->device = indio_dev;

	/*
	 * Set the device name.
	 *
	 * This is typically a part number and obtained from the module
	 * id table.
	 * e.g. for i2c and spi:
	 *    indio_dev->name = id->name;
	 *    indio_dev->name = spi_get_device_id(spi)->name;
	 */
	indio_dev->name = kstrdup(name, GFP_KERNEL);

	/* Provide description of available channels */
	indio_dev->channels = iio_dummy_channels;
	indio_dev->num_channels = ARRAY_SIZE(iio_dummy_channels);

	/*
	 * Provide device type specific interface functions and
	 * constant data.
	 */
	indio_dev->info = &iio_dummy_info;

	/* Specify that device provides sysfs type interfaces */
	indio_dev->modes = INDIO_DIRECT_MODE;

	ret = iio_simple_dummy_events_register(indio_dev);
	if (ret < 0)
		goto error_free_device;

	ret = iio_simple_dummy_configure_buffer(indio_dev);
	if (ret < 0)
		goto error_unregister_events;

	ret = iio_device_register(indio_dev);
	if (ret < 0)
		goto error_unconfigure_buffer;

	iio_swd_group_init_type_name(swd, name, &iio_dummy_type);

	return swd;
error_unconfigure_buffer:
	iio_simple_dummy_unconfigure_buffer(indio_dev);
error_unregister_events:
	iio_simple_dummy_events_unregister(indio_dev);
error_free_device:
	iio_device_free(indio_dev);
error_ret:
	kfree(swd);
error_kzalloc:
	return ERR_PTR(ret);
}

__attribute__((used)) static int iio_dummy_remove(struct iio_sw_device *swd)
{
	/*
	 * Get a pointer to the device instance iio_dev structure
	 * from the bus subsystem. E.g.
	 * struct iio_dev *indio_dev = i2c_get_clientdata(client);
	 * struct iio_dev *indio_dev = spi_get_drvdata(spi);
	 */
	struct iio_dev *indio_dev = swd->device;

	/* Unregister the device */
	iio_device_unregister(indio_dev);

	/* Device specific code to power down etc */

	/* Buffered capture related cleanup */
	iio_simple_dummy_unconfigure_buffer(indio_dev);

	iio_simple_dummy_events_unregister(indio_dev);

	/* Free all structures */
	kfree(indio_dev->name);
	iio_device_free(indio_dev);

	return 0;
}

