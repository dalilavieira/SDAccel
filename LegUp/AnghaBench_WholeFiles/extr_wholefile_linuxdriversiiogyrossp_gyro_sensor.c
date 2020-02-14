#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_4__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int u64 ;
typedef  int u32 ;
struct ssp_sensor_data {int (* process_data ) (struct iio_dev*,void*,int /*<<< orphan*/ ) ;int /*<<< orphan*/  type; } ;
struct ssp_data {int dummy; } ;
struct TYPE_5__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_1__ dev; } ;
struct TYPE_6__ {TYPE_1__* parent; } ;
struct iio_dev {int /*<<< orphan*/ * setup_ops; int /*<<< orphan*/  available_scan_masks; int /*<<< orphan*/  num_channels; int /*<<< orphan*/  channels; int /*<<< orphan*/  modes; int /*<<< orphan*/ * info; TYPE_4__ dev; int /*<<< orphan*/  name; } ;
struct iio_chan_spec {int dummy; } ;
struct iio_buffer {int dummy; } ;
typedef  int /*<<< orphan*/  int64_t ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int ENOMEM ; 
#define  IIO_CHAN_INFO_SAMP_FREQ 128 
 int IIO_VAL_INT_PLUS_MICRO ; 
 int /*<<< orphan*/  INDIO_BUFFER_SOFTWARE ; 
 int SSP_FACTOR_WITH_MS ; 
 int /*<<< orphan*/  SSP_GYROSCOPE_SENSOR ; 
 int /*<<< orphan*/  SSP_GYROSCOPE_SIZE ; 
 int SSP_INVERTED_SCALING_FACTOR ; 
 int /*<<< orphan*/  dev_err (TYPE_4__*,char*) ; 
 struct ssp_data* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 struct iio_dev* devm_iio_device_alloc (TYPE_1__*,int) ; 
 int devm_iio_device_register (TYPE_1__*,struct iio_dev*) ; 
 struct iio_buffer* devm_iio_kfifo_allocate (TYPE_1__*) ; 
 int div64_u64 (int,int) ; 
 int /*<<< orphan*/  iio_device_attach_buffer (struct iio_dev*,struct iio_buffer*) ; 
 struct ssp_sensor_data* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct iio_dev*) ; 
 int ssp_change_delay (struct ssp_data*,int /*<<< orphan*/ ,int) ; 
 int ssp_common_process_data (struct iio_dev*,void*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int ssp_get_sensor_delay (struct ssp_data*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ssp_gyro_buffer_ops ; 
 int /*<<< orphan*/  ssp_gyro_channels ; 
 int /*<<< orphan*/  ssp_gyro_iio_info ; 
 int /*<<< orphan*/  ssp_gyro_name ; 
 int /*<<< orphan*/  ssp_gyro_scan_mask ; 
 int /*<<< orphan*/  ssp_register_consumer (struct iio_dev*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void ssp_convert_to_freq(u32 time, int *integer_part,
				       int *fractional)
{
	if (time == 0) {
		*fractional = 0;
		*integer_part = 0;
		return;
	}

	*integer_part = SSP_FACTOR_WITH_MS / time;
	*fractional = *integer_part % SSP_INVERTED_SCALING_FACTOR;
	*integer_part = *integer_part / SSP_INVERTED_SCALING_FACTOR;
}

__attribute__((used)) static inline int ssp_convert_to_time(int integer_part, int fractional)
{
	u64 value;

	value = (u64)integer_part * SSP_INVERTED_SCALING_FACTOR + fractional;
	if (value == 0)
		return 0;

	return div64_u64((u64)SSP_FACTOR_WITH_MS, value);
}

__attribute__((used)) static int ssp_gyro_read_raw(struct iio_dev *indio_dev,
			     struct iio_chan_spec const *chan, int *val,
			     int *val2, long mask)
{
	u32 t;
	struct ssp_data *data = dev_get_drvdata(indio_dev->dev.parent->parent);

	switch (mask) {
	case IIO_CHAN_INFO_SAMP_FREQ:
		t = ssp_get_sensor_delay(data, SSP_GYROSCOPE_SENSOR);
		ssp_convert_to_freq(t, val, val2);
		return IIO_VAL_INT_PLUS_MICRO;
	default:
		break;
	}

	return -EINVAL;
}

__attribute__((used)) static int ssp_gyro_write_raw(struct iio_dev *indio_dev,
			      struct iio_chan_spec const *chan, int val,
			      int val2, long mask)
{
	int ret;
	struct ssp_data *data = dev_get_drvdata(indio_dev->dev.parent->parent);

	switch (mask) {
	case IIO_CHAN_INFO_SAMP_FREQ:
		ret = ssp_convert_to_time(val, val2);
		ret = ssp_change_delay(data, SSP_GYROSCOPE_SENSOR, ret);
		if (ret < 0)
			dev_err(&indio_dev->dev, "gyro sensor enable fail\n");

		return ret;
	default:
		break;
	}

	return -EINVAL;
}

__attribute__((used)) static int ssp_process_gyro_data(struct iio_dev *indio_dev, void *buf,
				 int64_t timestamp)
{
	return ssp_common_process_data(indio_dev, buf, SSP_GYROSCOPE_SIZE,
				       timestamp);
}

__attribute__((used)) static int ssp_gyro_probe(struct platform_device *pdev)
{
	int ret;
	struct iio_dev *indio_dev;
	struct ssp_sensor_data *spd;
	struct iio_buffer *buffer;

	indio_dev = devm_iio_device_alloc(&pdev->dev, sizeof(*spd));
	if (!indio_dev)
		return -ENOMEM;

	spd = iio_priv(indio_dev);

	spd->process_data = ssp_process_gyro_data;
	spd->type = SSP_GYROSCOPE_SENSOR;

	indio_dev->name = ssp_gyro_name;
	indio_dev->dev.parent = &pdev->dev;
	indio_dev->info = &ssp_gyro_iio_info;
	indio_dev->modes = INDIO_BUFFER_SOFTWARE;
	indio_dev->channels = ssp_gyro_channels;
	indio_dev->num_channels = ARRAY_SIZE(ssp_gyro_channels);
	indio_dev->available_scan_masks = ssp_gyro_scan_mask;

	buffer = devm_iio_kfifo_allocate(&pdev->dev);
	if (!buffer)
		return -ENOMEM;

	iio_device_attach_buffer(indio_dev, buffer);

	indio_dev->setup_ops = &ssp_gyro_buffer_ops;

	platform_set_drvdata(pdev, indio_dev);

	ret = devm_iio_device_register(&pdev->dev, indio_dev);
	if (ret < 0)
		return ret;

	/* ssp registering should be done after all iio setup */
	ssp_register_consumer(indio_dev, SSP_GYROSCOPE_SENSOR);

	return 0;
}

