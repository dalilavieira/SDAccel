#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u64 ;
typedef  int u32 ;
struct ssp_sensor_data {int /*<<< orphan*/  buffer; int /*<<< orphan*/  type; } ;
struct ssp_data {int dummy; } ;
struct TYPE_4__ {TYPE_1__* parent; } ;
struct iio_dev {scalar_t__ scan_bytes; scalar_t__ scan_timestamp; TYPE_2__ dev; } ;
typedef  int int64_t ;
typedef  int /*<<< orphan*/  __le32 ;
struct TYPE_3__ {int /*<<< orphan*/  parent; } ;

/* Variables and functions */
 int ENOMEM ; 
 int GFP_DMA ; 
 int GFP_KERNEL ; 
 int SSP_FACTOR_WITH_MS ; 
 int SSP_INVERTED_SCALING_FACTOR ; 
 int /*<<< orphan*/  SSP_TIME_SIZE ; 
 struct ssp_data* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int div64_u64 (int,int) ; 
 struct ssp_sensor_data* iio_priv (struct iio_dev*) ; 
 int iio_push_to_buffers_with_timestamp (struct iio_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kmalloc (scalar_t__,int) ; 
 scalar_t__ le32_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,char*,unsigned int) ; 
 int ssp_disable_sensor (struct ssp_data*,int /*<<< orphan*/ ) ; 
 int ssp_enable_sensor (struct ssp_data*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ssp_get_sensor_delay (struct ssp_data*,int /*<<< orphan*/ ) ; 

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

int ssp_common_buffer_postenable(struct iio_dev *indio_dev)
{
	struct ssp_sensor_data *spd = iio_priv(indio_dev);
	struct ssp_data *data = dev_get_drvdata(indio_dev->dev.parent->parent);

	/* the allocation is made in post because scan size is known in this
	 * moment
	 * */
	spd->buffer = kmalloc(indio_dev->scan_bytes, GFP_KERNEL | GFP_DMA);
	if (!spd->buffer)
		return -ENOMEM;

	return ssp_enable_sensor(data, spd->type,
				 ssp_get_sensor_delay(data, spd->type));
}

int ssp_common_buffer_postdisable(struct iio_dev *indio_dev)
{
	int ret;
	struct ssp_sensor_data *spd = iio_priv(indio_dev);
	struct ssp_data *data = dev_get_drvdata(indio_dev->dev.parent->parent);

	ret = ssp_disable_sensor(data, spd->type);
	if (ret < 0)
		return ret;

	kfree(spd->buffer);

	return ret;
}

int ssp_common_process_data(struct iio_dev *indio_dev, void *buf,
			    unsigned int len, int64_t timestamp)
{
	__le32 time;
	int64_t calculated_time;
	struct ssp_sensor_data *spd = iio_priv(indio_dev);

	if (indio_dev->scan_bytes == 0)
		return 0;

	/*
	 * it always sends full set of samples, remember about available masks
	 */
	memcpy(spd->buffer, buf, len);

	if (indio_dev->scan_timestamp) {
		memcpy(&time, &((char *)buf)[len], SSP_TIME_SIZE);
		calculated_time =
			timestamp + (int64_t)le32_to_cpu(time) * 1000000;
	}

	return iio_push_to_buffers_with_timestamp(indio_dev, spd->buffer,
						  calculated_time);
}

