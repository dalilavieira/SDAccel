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
typedef  int u32 ;
struct TYPE_2__ {int /*<<< orphan*/ * parent; } ;
struct iio_dev {int /*<<< orphan*/  num_channels; int /*<<< orphan*/  channels; int /*<<< orphan*/  modes; int /*<<< orphan*/ * info; TYPE_1__ dev; int /*<<< orphan*/  name; } ;
struct iio_chan_spec {scalar_t__ type; } ;
struct iio_buffer {int dummy; } ;
struct acpi_device {int /*<<< orphan*/  dev; struct iio_dev* driver_data; int /*<<< orphan*/  handle; } ;
struct acpi_als {void** evt_buffer; int /*<<< orphan*/  lock; struct acpi_device* device; } ;
typedef  int /*<<< orphan*/  s64 ;
typedef  void* s32 ;
typedef  int /*<<< orphan*/  acpi_status ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_ALS_DEVICE_NAME ; 
 int /*<<< orphan*/  ACPI_ALS_EVT_BUFFER_SIZE ; 
 char* ACPI_ALS_ILLUMINANCE ; 
#define  ACPI_ALS_NOTIFY_ILLUMINANCE 128 
 int /*<<< orphan*/  ACPI_EXCEPTION (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AE_INFO ; 
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 long IIO_CHAN_INFO_PROCESSED ; 
 long IIO_CHAN_INFO_RAW ; 
 scalar_t__ IIO_LIGHT ; 
 int IIO_VAL_INT ; 
 int /*<<< orphan*/  INDIO_BUFFER_SOFTWARE ; 
 int /*<<< orphan*/  acpi_als_channels ; 
 int /*<<< orphan*/  acpi_als_info ; 
 struct iio_dev* acpi_driver_data (struct acpi_device*) ; 
 int /*<<< orphan*/  acpi_evaluate_integer (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *,unsigned long long*) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,int) ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 int devm_iio_device_register (int /*<<< orphan*/ *,struct iio_dev*) ; 
 struct iio_buffer* devm_iio_kfifo_allocate (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  iio_device_attach_buffer (struct iio_dev*,struct iio_buffer*) ; 
 int /*<<< orphan*/  iio_get_time_ns (struct iio_dev*) ; 
 struct acpi_als* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_push_to_buffers_with_timestamp (struct iio_dev*,void**,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (void**,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int acpi_als_read_value(struct acpi_als *als, char *prop, s32 *val)
{
	unsigned long long temp_val;
	acpi_status status;

	status = acpi_evaluate_integer(als->device->handle, prop, NULL,
				       &temp_val);

	if (ACPI_FAILURE(status)) {
		ACPI_EXCEPTION((AE_INFO, status, "Error reading ALS %s", prop));
		return -EIO;
	}

	*val = temp_val;

	return 0;
}

__attribute__((used)) static void acpi_als_notify(struct acpi_device *device, u32 event)
{
	struct iio_dev *indio_dev = acpi_driver_data(device);
	struct acpi_als *als = iio_priv(indio_dev);
	s32 *buffer = als->evt_buffer;
	s64 time_ns = iio_get_time_ns(indio_dev);
	s32 val;
	int ret;

	mutex_lock(&als->lock);

	memset(buffer, 0, ACPI_ALS_EVT_BUFFER_SIZE);

	switch (event) {
	case ACPI_ALS_NOTIFY_ILLUMINANCE:
		ret = acpi_als_read_value(als, ACPI_ALS_ILLUMINANCE, &val);
		if (ret < 0)
			goto out;
		*buffer++ = val;
		break;
	default:
		/* Unhandled event */
		dev_dbg(&device->dev, "Unhandled ACPI ALS event (%08x)!\n",
			event);
		goto out;
	}

	iio_push_to_buffers_with_timestamp(indio_dev, als->evt_buffer, time_ns);

out:
	mutex_unlock(&als->lock);
}

__attribute__((used)) static int acpi_als_read_raw(struct iio_dev *indio_dev,
			     struct iio_chan_spec const *chan, int *val,
			     int *val2, long mask)
{
	struct acpi_als *als = iio_priv(indio_dev);
	s32 temp_val;
	int ret;

	if ((mask != IIO_CHAN_INFO_PROCESSED) && (mask != IIO_CHAN_INFO_RAW))
		return -EINVAL;

	/* we support only illumination (_ALI) so far. */
	if (chan->type != IIO_LIGHT)
		return -EINVAL;

	ret = acpi_als_read_value(als, ACPI_ALS_ILLUMINANCE, &temp_val);
	if (ret < 0)
		return ret;

	*val = temp_val;

	return IIO_VAL_INT;
}

__attribute__((used)) static int acpi_als_add(struct acpi_device *device)
{
	struct acpi_als *als;
	struct iio_dev *indio_dev;
	struct iio_buffer *buffer;

	indio_dev = devm_iio_device_alloc(&device->dev, sizeof(*als));
	if (!indio_dev)
		return -ENOMEM;

	als = iio_priv(indio_dev);

	device->driver_data = indio_dev;
	als->device = device;
	mutex_init(&als->lock);

	indio_dev->name = ACPI_ALS_DEVICE_NAME;
	indio_dev->dev.parent = &device->dev;
	indio_dev->info = &acpi_als_info;
	indio_dev->modes = INDIO_BUFFER_SOFTWARE;
	indio_dev->channels = acpi_als_channels;
	indio_dev->num_channels = ARRAY_SIZE(acpi_als_channels);

	buffer = devm_iio_kfifo_allocate(&device->dev);
	if (!buffer)
		return -ENOMEM;

	iio_device_attach_buffer(indio_dev, buffer);

	return devm_iio_device_register(&device->dev, indio_dev);
}

