#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct regmap {int dummy; } ;
struct TYPE_10__ {struct device* parent; } ;
struct iio_trigger {int /*<<< orphan*/ * ops; TYPE_3__ dev; } ;
struct iio_poll_func {int /*<<< orphan*/  timestamp; struct iio_dev* indio_dev; } ;
struct TYPE_9__ {struct device* parent; } ;
struct iio_dev {int num_channels; char const* name; int /*<<< orphan*/  id; int /*<<< orphan*/ * info; int /*<<< orphan*/  modes; int /*<<< orphan*/  available_scan_masks; TYPE_4__* channels; TYPE_2__ dev; int /*<<< orphan*/  trig; } ;
struct iio_chan_spec {int const type; int scan_index; } ;
struct device {TYPE_1__* driver; } ;
struct bmg160_data {int dps_range; unsigned int slope_thres; int dready_trigger_on; int ev_enable_state; int motion_trigger_on; int irq; int /*<<< orphan*/  mutex; struct iio_trigger* motion_trig; struct iio_trigger* dready_trig; struct regmap* regmap; int /*<<< orphan*/ * buffer; } ;
struct acpi_device_id {int dummy; } ;
typedef  int /*<<< orphan*/  raw_val ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  enum iio_event_type { ____Placeholder_iio_event_type } iio_event_type ;
typedef  enum iio_event_info { ____Placeholder_iio_event_info } iio_event_info ;
typedef  enum iio_event_direction { ____Placeholder_iio_event_direction } iio_event_direction ;
typedef  int /*<<< orphan*/  __le16 ;
struct TYPE_11__ {int odr; int bw_bits; int filter; int scale; int dps_range; } ;
struct TYPE_8__ {int /*<<< orphan*/  acpi_match_table; } ;

/* Variables and functions */
 scalar_t__ ACPI_HANDLE (struct device*) ; 
 int ARRAY_SIZE (TYPE_4__*) ; 
 int AXIS_MAX ; 
 unsigned int BMG160_ANY_MOTION_BIT_X ; 
 unsigned int BMG160_ANY_MOTION_BIT_Y ; 
 unsigned int BMG160_ANY_MOTION_BIT_Z ; 
 int /*<<< orphan*/  BMG160_AUTO_SUSPEND_DELAY_MS ; 
 int /*<<< orphan*/  BMG160_AXIS_TO_REG (int) ; 
 unsigned int BMG160_CHIP_ID_VAL ; 
 int BMG160_DATA_ENABLE_INT ; 
 int BMG160_DEF_BW ; 
 int /*<<< orphan*/  BMG160_GYRO_REG_RESET ; 
 int BMG160_GYRO_RESET_VAL ; 
 int /*<<< orphan*/  BMG160_INT1_BIT_OD ; 
 int /*<<< orphan*/  BMG160_INT_MAP_0_BIT_ANY ; 
 int /*<<< orphan*/  BMG160_INT_MAP_1_BIT_NEW_DATA ; 
 int BMG160_INT_MODE_LATCH_INT ; 
 int BMG160_INT_MODE_LATCH_RESET ; 
 int BMG160_INT_MODE_NON_LATCH_INT ; 
 int BMG160_INT_MOTION_X ; 
 int BMG160_INT_MOTION_Y ; 
 int BMG160_INT_MOTION_Z ; 
 int /*<<< orphan*/  BMG160_IRQ_NAME ; 
 int BMG160_MODE_DEEP_SUSPEND ; 
 int BMG160_MODE_NORMAL ; 
 int BMG160_RANGE_500DPS ; 
 int /*<<< orphan*/  BMG160_REG_CHIP_ID ; 
 int /*<<< orphan*/  BMG160_REG_INT_EN_0 ; 
 int /*<<< orphan*/  BMG160_REG_INT_EN_1 ; 
 int /*<<< orphan*/  BMG160_REG_INT_MAP_0 ; 
 int /*<<< orphan*/  BMG160_REG_INT_MAP_1 ; 
 int /*<<< orphan*/  BMG160_REG_INT_RST_LATCH ; 
 int /*<<< orphan*/  BMG160_REG_INT_STATUS_2 ; 
 int /*<<< orphan*/  BMG160_REG_MOTION_INTR ; 
 int /*<<< orphan*/  BMG160_REG_PMU_BW ; 
 unsigned int BMG160_REG_PMU_BW_RES ; 
 int /*<<< orphan*/  BMG160_REG_PMU_LPW ; 
 int /*<<< orphan*/  BMG160_REG_RANGE ; 
 int /*<<< orphan*/  BMG160_REG_SLOPE_THRES ; 
 int /*<<< orphan*/  BMG160_REG_TEMP ; 
 int /*<<< orphan*/  BMG160_REG_XOUT_L ; 
 int BMG160_SLOPE_THRES_MASK ; 
 int BMG160_TEMP_CENTER_VAL ; 
 int EBUSY ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
#define  IIO_ANGL_VEL 135 
#define  IIO_CHAN_INFO_LOW_PASS_FILTER_3DB_FREQUENCY 134 
#define  IIO_CHAN_INFO_OFFSET 133 
#define  IIO_CHAN_INFO_RAW 132 
#define  IIO_CHAN_INFO_SAMP_FREQ 131 
#define  IIO_CHAN_INFO_SCALE 130 
 int IIO_EV_DIR_FALLING ; 
 int IIO_EV_DIR_RISING ; 
#define  IIO_EV_INFO_VALUE 129 
 int /*<<< orphan*/  IIO_EV_TYPE_ROC ; 
 int /*<<< orphan*/  IIO_MOD_EVENT_CODE (int const,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  IIO_MOD_X ; 
 int /*<<< orphan*/  IIO_MOD_Y ; 
 int /*<<< orphan*/  IIO_MOD_Z ; 
#define  IIO_TEMP 128 
 int IIO_VAL_INT ; 
 int IIO_VAL_INT_PLUS_MICRO ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int /*<<< orphan*/  IRQF_TRIGGER_RISING ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_WAKE_THREAD ; 
 struct acpi_device_id* acpi_match_device (int /*<<< orphan*/ ,struct device*) ; 
 int /*<<< orphan*/  bmg160_accel_scan_masks ; 
 int /*<<< orphan*/  bmg160_buffer_setup_ops ; 
 TYPE_4__* bmg160_channels ; 
 int /*<<< orphan*/  bmg160_info ; 
 TYPE_4__* bmg160_samp_freq_table ; 
 TYPE_4__* bmg160_scale_table ; 
 int /*<<< orphan*/  bmg160_trigger_ops ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,unsigned int) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct iio_dev* dev_get_drvdata (struct device*) ; 
 char const* dev_name (struct device*) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct iio_dev*) ; 
 struct iio_dev* devm_iio_device_alloc (struct device*,int) ; 
 void* devm_iio_trigger_alloc (struct device*,char*,char const*,int /*<<< orphan*/ ) ; 
 int devm_request_threaded_irq (struct device*,int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct iio_dev*) ; 
 int /*<<< orphan*/  iio_buffer_enabled (struct iio_dev*) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_get_time_ns (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_pollfunc_store_time ; 
 struct bmg160_data* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_push_event (struct iio_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iio_push_to_buffers_with_timestamp (struct iio_dev*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 struct iio_dev* iio_trigger_get_drvdata (struct iio_trigger*) ; 
 int /*<<< orphan*/  iio_trigger_notify_done (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iio_trigger_poll (struct iio_trigger*) ; 
 int iio_trigger_register (struct iio_trigger*) ; 
 int /*<<< orphan*/  iio_trigger_set_drvdata (struct iio_trigger*,struct iio_dev*) ; 
 int /*<<< orphan*/  iio_trigger_unregister (struct iio_trigger*) ; 
 int /*<<< orphan*/  iio_triggered_buffer_cleanup (struct iio_dev*) ; 
 int iio_triggered_buffer_setup (struct iio_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ *) ; 
 unsigned int le16_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_runtime_disable (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_enable (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_put_noidle (struct device*) ; 
 int pm_runtime_set_active (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_set_autosuspend_delay (struct device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pm_runtime_set_suspended (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_use_autosuspend (struct device*) ; 
 int regmap_bulk_read (struct regmap*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 struct device* regmap_get_device (struct regmap*) ; 
 int regmap_read (struct regmap*,int /*<<< orphan*/ ,unsigned int*) ; 
 int regmap_update_bits (struct regmap*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int regmap_write (struct regmap*,int /*<<< orphan*/ ,int) ; 
 int sign_extend32 (unsigned int,int) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static int bmg160_set_mode(struct bmg160_data *data, u8 mode)
{
	struct device *dev = regmap_get_device(data->regmap);
	int ret;

	ret = regmap_write(data->regmap, BMG160_REG_PMU_LPW, mode);
	if (ret < 0) {
		dev_err(dev, "Error writing reg_pmu_lpw\n");
		return ret;
	}

	return 0;
}

__attribute__((used)) static int bmg160_convert_freq_to_bit(int val)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(bmg160_samp_freq_table); ++i) {
		if (bmg160_samp_freq_table[i].odr == val)
			return bmg160_samp_freq_table[i].bw_bits;
	}

	return -EINVAL;
}

__attribute__((used)) static int bmg160_set_bw(struct bmg160_data *data, int val)
{
	struct device *dev = regmap_get_device(data->regmap);
	int ret;
	int bw_bits;

	bw_bits = bmg160_convert_freq_to_bit(val);
	if (bw_bits < 0)
		return bw_bits;

	ret = regmap_write(data->regmap, BMG160_REG_PMU_BW, bw_bits);
	if (ret < 0) {
		dev_err(dev, "Error writing reg_pmu_bw\n");
		return ret;
	}

	return 0;
}

__attribute__((used)) static int bmg160_get_filter(struct bmg160_data *data, int *val)
{
	struct device *dev = regmap_get_device(data->regmap);
	int ret;
	int i;
	unsigned int bw_bits;

	ret = regmap_read(data->regmap, BMG160_REG_PMU_BW, &bw_bits);
	if (ret < 0) {
		dev_err(dev, "Error reading reg_pmu_bw\n");
		return ret;
	}

	/* Ignore the readonly reserved bit. */
	bw_bits &= ~BMG160_REG_PMU_BW_RES;

	for (i = 0; i < ARRAY_SIZE(bmg160_samp_freq_table); ++i) {
		if (bmg160_samp_freq_table[i].bw_bits == bw_bits)
			break;
	}

	*val = bmg160_samp_freq_table[i].filter;

	return ret ? ret : IIO_VAL_INT;
}

__attribute__((used)) static int bmg160_set_filter(struct bmg160_data *data, int val)
{
	struct device *dev = regmap_get_device(data->regmap);
	int ret;
	int i;

	for (i = 0; i < ARRAY_SIZE(bmg160_samp_freq_table); ++i) {
		if (bmg160_samp_freq_table[i].filter == val)
			break;
	}

	ret = regmap_write(data->regmap, BMG160_REG_PMU_BW,
			   bmg160_samp_freq_table[i].bw_bits);
	if (ret < 0) {
		dev_err(dev, "Error writing reg_pmu_bw\n");
		return ret;
	}

	return 0;
}

__attribute__((used)) static int bmg160_chip_init(struct bmg160_data *data)
{
	struct device *dev = regmap_get_device(data->regmap);
	int ret;
	unsigned int val;

	/*
	 * Reset chip to get it in a known good state. A delay of 30ms after
	 * reset is required according to the datasheet.
	 */
	regmap_write(data->regmap, BMG160_GYRO_REG_RESET,
		     BMG160_GYRO_RESET_VAL);
	usleep_range(30000, 30700);

	ret = regmap_read(data->regmap, BMG160_REG_CHIP_ID, &val);
	if (ret < 0) {
		dev_err(dev, "Error reading reg_chip_id\n");
		return ret;
	}

	dev_dbg(dev, "Chip Id %x\n", val);
	if (val != BMG160_CHIP_ID_VAL) {
		dev_err(dev, "invalid chip %x\n", val);
		return -ENODEV;
	}

	ret = bmg160_set_mode(data, BMG160_MODE_NORMAL);
	if (ret < 0)
		return ret;

	/* Wait upto 500 ms to be ready after changing mode */
	usleep_range(500, 1000);

	/* Set Bandwidth */
	ret = bmg160_set_bw(data, BMG160_DEF_BW);
	if (ret < 0)
		return ret;

	/* Set Default Range */
	ret = regmap_write(data->regmap, BMG160_REG_RANGE, BMG160_RANGE_500DPS);
	if (ret < 0) {
		dev_err(dev, "Error writing reg_range\n");
		return ret;
	}
	data->dps_range = BMG160_RANGE_500DPS;

	ret = regmap_read(data->regmap, BMG160_REG_SLOPE_THRES, &val);
	if (ret < 0) {
		dev_err(dev, "Error reading reg_slope_thres\n");
		return ret;
	}
	data->slope_thres = val;

	/* Set default interrupt mode */
	ret = regmap_update_bits(data->regmap, BMG160_REG_INT_EN_1,
				 BMG160_INT1_BIT_OD, 0);
	if (ret < 0) {
		dev_err(dev, "Error updating bits in reg_int_en_1\n");
		return ret;
	}

	ret = regmap_write(data->regmap, BMG160_REG_INT_RST_LATCH,
			   BMG160_INT_MODE_LATCH_INT |
			   BMG160_INT_MODE_LATCH_RESET);
	if (ret < 0) {
		dev_err(dev,
			"Error writing reg_motion_intr\n");
		return ret;
	}

	return 0;
}

__attribute__((used)) static int bmg160_set_power_state(struct bmg160_data *data, bool on)
{
#ifdef CONFIG_PM
	struct device *dev = regmap_get_device(data->regmap);
	int ret;

	if (on)
		ret = pm_runtime_get_sync(dev);
	else {
		pm_runtime_mark_last_busy(dev);
		ret = pm_runtime_put_autosuspend(dev);
	}

	if (ret < 0) {
		dev_err(dev, "Failed: bmg160_set_power_state for %d\n", on);

		if (on)
			pm_runtime_put_noidle(dev);

		return ret;
	}
#endif

	return 0;
}

__attribute__((used)) static int bmg160_setup_any_motion_interrupt(struct bmg160_data *data,
					     bool status)
{
	struct device *dev = regmap_get_device(data->regmap);
	int ret;

	/* Enable/Disable INT_MAP0 mapping */
	ret = regmap_update_bits(data->regmap, BMG160_REG_INT_MAP_0,
				 BMG160_INT_MAP_0_BIT_ANY,
				 (status ? BMG160_INT_MAP_0_BIT_ANY : 0));
	if (ret < 0) {
		dev_err(dev, "Error updating bits reg_int_map0\n");
		return ret;
	}

	/* Enable/Disable slope interrupts */
	if (status) {
		/* Update slope thres */
		ret = regmap_write(data->regmap, BMG160_REG_SLOPE_THRES,
				   data->slope_thres);
		if (ret < 0) {
			dev_err(dev, "Error writing reg_slope_thres\n");
			return ret;
		}

		ret = regmap_write(data->regmap, BMG160_REG_MOTION_INTR,
				   BMG160_INT_MOTION_X | BMG160_INT_MOTION_Y |
				   BMG160_INT_MOTION_Z);
		if (ret < 0) {
			dev_err(dev, "Error writing reg_motion_intr\n");
			return ret;
		}

		/*
		 * New data interrupt is always non-latched,
		 * which will have higher priority, so no need
		 * to set latched mode, we will be flooded anyway with INTR
		 */
		if (!data->dready_trigger_on) {
			ret = regmap_write(data->regmap,
					   BMG160_REG_INT_RST_LATCH,
					   BMG160_INT_MODE_LATCH_INT |
					   BMG160_INT_MODE_LATCH_RESET);
			if (ret < 0) {
				dev_err(dev, "Error writing reg_rst_latch\n");
				return ret;
			}
		}

		ret = regmap_write(data->regmap, BMG160_REG_INT_EN_0,
				   BMG160_DATA_ENABLE_INT);

	} else {
		ret = regmap_write(data->regmap, BMG160_REG_INT_EN_0, 0);
	}

	if (ret < 0) {
		dev_err(dev, "Error writing reg_int_en0\n");
		return ret;
	}

	return 0;
}

__attribute__((used)) static int bmg160_setup_new_data_interrupt(struct bmg160_data *data,
					   bool status)
{
	struct device *dev = regmap_get_device(data->regmap);
	int ret;

	/* Enable/Disable INT_MAP1 mapping */
	ret = regmap_update_bits(data->regmap, BMG160_REG_INT_MAP_1,
				 BMG160_INT_MAP_1_BIT_NEW_DATA,
				 (status ? BMG160_INT_MAP_1_BIT_NEW_DATA : 0));
	if (ret < 0) {
		dev_err(dev, "Error updating bits in reg_int_map1\n");
		return ret;
	}

	if (status) {
		ret = regmap_write(data->regmap, BMG160_REG_INT_RST_LATCH,
				   BMG160_INT_MODE_NON_LATCH_INT |
				   BMG160_INT_MODE_LATCH_RESET);
		if (ret < 0) {
			dev_err(dev, "Error writing reg_rst_latch\n");
			return ret;
		}

		ret = regmap_write(data->regmap, BMG160_REG_INT_EN_0,
				   BMG160_DATA_ENABLE_INT);

	} else {
		/* Restore interrupt mode */
		ret = regmap_write(data->regmap, BMG160_REG_INT_RST_LATCH,
				   BMG160_INT_MODE_LATCH_INT |
				   BMG160_INT_MODE_LATCH_RESET);
		if (ret < 0) {
			dev_err(dev, "Error writing reg_rst_latch\n");
			return ret;
		}

		ret = regmap_write(data->regmap, BMG160_REG_INT_EN_0, 0);
	}

	if (ret < 0) {
		dev_err(dev, "Error writing reg_int_en0\n");
		return ret;
	}

	return 0;
}

__attribute__((used)) static int bmg160_get_bw(struct bmg160_data *data, int *val)
{
	struct device *dev = regmap_get_device(data->regmap);	
	int i;
	unsigned int bw_bits;
	int ret;

	ret = regmap_read(data->regmap, BMG160_REG_PMU_BW, &bw_bits);
	if (ret < 0) {
		dev_err(dev, "Error reading reg_pmu_bw\n");
		return ret;
	}

	/* Ignore the readonly reserved bit. */
	bw_bits &= ~BMG160_REG_PMU_BW_RES;

	for (i = 0; i < ARRAY_SIZE(bmg160_samp_freq_table); ++i) {
		if (bmg160_samp_freq_table[i].bw_bits == bw_bits) {
			*val = bmg160_samp_freq_table[i].odr;
			return IIO_VAL_INT;
		}
	}

	return -EINVAL;
}

__attribute__((used)) static int bmg160_set_scale(struct bmg160_data *data, int val)
{
	struct device *dev = regmap_get_device(data->regmap);
	int ret, i;

	for (i = 0; i < ARRAY_SIZE(bmg160_scale_table); ++i) {
		if (bmg160_scale_table[i].scale == val) {
			ret = regmap_write(data->regmap, BMG160_REG_RANGE,
					   bmg160_scale_table[i].dps_range);
			if (ret < 0) {
				dev_err(dev, "Error writing reg_range\n");
				return ret;
			}
			data->dps_range = bmg160_scale_table[i].dps_range;
			return 0;
		}
	}

	return -EINVAL;
}

__attribute__((used)) static int bmg160_get_temp(struct bmg160_data *data, int *val)
{
	struct device *dev = regmap_get_device(data->regmap);
	int ret;
	unsigned int raw_val;

	mutex_lock(&data->mutex);
	ret = bmg160_set_power_state(data, true);
	if (ret < 0) {
		mutex_unlock(&data->mutex);
		return ret;
	}

	ret = regmap_read(data->regmap, BMG160_REG_TEMP, &raw_val);
	if (ret < 0) {
		dev_err(dev, "Error reading reg_temp\n");
		bmg160_set_power_state(data, false);
		mutex_unlock(&data->mutex);
		return ret;
	}

	*val = sign_extend32(raw_val, 7);
	ret = bmg160_set_power_state(data, false);
	mutex_unlock(&data->mutex);
	if (ret < 0)
		return ret;

	return IIO_VAL_INT;
}

__attribute__((used)) static int bmg160_get_axis(struct bmg160_data *data, int axis, int *val)
{
	struct device *dev = regmap_get_device(data->regmap);
	int ret;
	__le16 raw_val;

	mutex_lock(&data->mutex);
	ret = bmg160_set_power_state(data, true);
	if (ret < 0) {
		mutex_unlock(&data->mutex);
		return ret;
	}

	ret = regmap_bulk_read(data->regmap, BMG160_AXIS_TO_REG(axis), &raw_val,
			       sizeof(raw_val));
	if (ret < 0) {
		dev_err(dev, "Error reading axis %d\n", axis);
		bmg160_set_power_state(data, false);
		mutex_unlock(&data->mutex);
		return ret;
	}

	*val = sign_extend32(le16_to_cpu(raw_val), 15);
	ret = bmg160_set_power_state(data, false);
	mutex_unlock(&data->mutex);
	if (ret < 0)
		return ret;

	return IIO_VAL_INT;
}

__attribute__((used)) static int bmg160_read_raw(struct iio_dev *indio_dev,
			   struct iio_chan_spec const *chan,
			   int *val, int *val2, long mask)
{
	struct bmg160_data *data = iio_priv(indio_dev);
	int ret;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		switch (chan->type) {
		case IIO_TEMP:
			return bmg160_get_temp(data, val);
		case IIO_ANGL_VEL:
			if (iio_buffer_enabled(indio_dev))
				return -EBUSY;
			else
				return bmg160_get_axis(data, chan->scan_index,
						       val);
		default:
			return -EINVAL;
		}
	case IIO_CHAN_INFO_OFFSET:
		if (chan->type == IIO_TEMP) {
			*val = BMG160_TEMP_CENTER_VAL;
			return IIO_VAL_INT;
		} else
			return -EINVAL;
	case IIO_CHAN_INFO_LOW_PASS_FILTER_3DB_FREQUENCY:
		return bmg160_get_filter(data, val);
	case IIO_CHAN_INFO_SCALE:
		switch (chan->type) {
		case IIO_TEMP:
			*val = 500;
			return IIO_VAL_INT;
		case IIO_ANGL_VEL:
		{
			int i;

			for (i = 0; i < ARRAY_SIZE(bmg160_scale_table); ++i) {
				if (bmg160_scale_table[i].dps_range ==
							data->dps_range) {
					*val = 0;
					*val2 = bmg160_scale_table[i].scale;
					return IIO_VAL_INT_PLUS_MICRO;
				}
			}
			return -EINVAL;
		}
		default:
			return -EINVAL;
		}
	case IIO_CHAN_INFO_SAMP_FREQ:
		*val2 = 0;
		mutex_lock(&data->mutex);
		ret = bmg160_get_bw(data, val);
		mutex_unlock(&data->mutex);
		return ret;
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int bmg160_write_raw(struct iio_dev *indio_dev,
			    struct iio_chan_spec const *chan,
			    int val, int val2, long mask)
{
	struct bmg160_data *data = iio_priv(indio_dev);
	int ret;

	switch (mask) {
	case IIO_CHAN_INFO_SAMP_FREQ:
		mutex_lock(&data->mutex);
		/*
		 * Section 4.2 of spec
		 * In suspend mode, the only supported operations are reading
		 * registers as well as writing to the (0x14) softreset
		 * register. Since we will be in suspend mode by default, change
		 * mode to power on for other writes.
		 */
		ret = bmg160_set_power_state(data, true);
		if (ret < 0) {
			mutex_unlock(&data->mutex);
			return ret;
		}
		ret = bmg160_set_bw(data, val);
		if (ret < 0) {
			bmg160_set_power_state(data, false);
			mutex_unlock(&data->mutex);
			return ret;
		}
		ret = bmg160_set_power_state(data, false);
		mutex_unlock(&data->mutex);
		return ret;
	case IIO_CHAN_INFO_LOW_PASS_FILTER_3DB_FREQUENCY:
		if (val2)
			return -EINVAL;

		mutex_lock(&data->mutex);
		ret = bmg160_set_power_state(data, true);
		if (ret < 0) {
			bmg160_set_power_state(data, false);
			mutex_unlock(&data->mutex);
			return ret;
		}
		ret = bmg160_set_filter(data, val);
		if (ret < 0) {
			bmg160_set_power_state(data, false);
			mutex_unlock(&data->mutex);
			return ret;
		}
		ret = bmg160_set_power_state(data, false);
		mutex_unlock(&data->mutex);
		return ret;
	case IIO_CHAN_INFO_SCALE:
		if (val)
			return -EINVAL;

		mutex_lock(&data->mutex);
		/* Refer to comments above for the suspend mode ops */
		ret = bmg160_set_power_state(data, true);
		if (ret < 0) {
			mutex_unlock(&data->mutex);
			return ret;
		}
		ret = bmg160_set_scale(data, val2);
		if (ret < 0) {
			bmg160_set_power_state(data, false);
			mutex_unlock(&data->mutex);
			return ret;
		}
		ret = bmg160_set_power_state(data, false);
		mutex_unlock(&data->mutex);
		return ret;
	default:
		return -EINVAL;
	}

	return -EINVAL;
}

__attribute__((used)) static int bmg160_read_event(struct iio_dev *indio_dev,
			     const struct iio_chan_spec *chan,
			     enum iio_event_type type,
			     enum iio_event_direction dir,
			     enum iio_event_info info,
			     int *val, int *val2)
{
	struct bmg160_data *data = iio_priv(indio_dev);

	*val2 = 0;
	switch (info) {
	case IIO_EV_INFO_VALUE:
		*val = data->slope_thres & BMG160_SLOPE_THRES_MASK;
		break;
	default:
		return -EINVAL;
	}

	return IIO_VAL_INT;
}

__attribute__((used)) static int bmg160_write_event(struct iio_dev *indio_dev,
			      const struct iio_chan_spec *chan,
			      enum iio_event_type type,
			      enum iio_event_direction dir,
			      enum iio_event_info info,
			      int val, int val2)
{
	struct bmg160_data *data = iio_priv(indio_dev);

	switch (info) {
	case IIO_EV_INFO_VALUE:
		if (data->ev_enable_state)
			return -EBUSY;
		data->slope_thres &= ~BMG160_SLOPE_THRES_MASK;
		data->slope_thres |= (val & BMG160_SLOPE_THRES_MASK);
		break;
	default:
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int bmg160_read_event_config(struct iio_dev *indio_dev,
				    const struct iio_chan_spec *chan,
				    enum iio_event_type type,
				    enum iio_event_direction dir)
{

	struct bmg160_data *data = iio_priv(indio_dev);

	return data->ev_enable_state;
}

__attribute__((used)) static int bmg160_write_event_config(struct iio_dev *indio_dev,
				     const struct iio_chan_spec *chan,
				     enum iio_event_type type,
				     enum iio_event_direction dir,
				     int state)
{
	struct bmg160_data *data = iio_priv(indio_dev);
	int ret;

	if (state && data->ev_enable_state)
		return 0;

	mutex_lock(&data->mutex);

	if (!state && data->motion_trigger_on) {
		data->ev_enable_state = 0;
		mutex_unlock(&data->mutex);
		return 0;
	}
	/*
	 * We will expect the enable and disable to do operation in
	 * in reverse order. This will happen here anyway as our
	 * resume operation uses sync mode runtime pm calls, the
	 * suspend operation will be delayed by autosuspend delay
	 * So the disable operation will still happen in reverse of
	 * enable operation. When runtime pm is disabled the mode
	 * is always on so sequence doesn't matter
	 */
	ret = bmg160_set_power_state(data, state);
	if (ret < 0) {
		mutex_unlock(&data->mutex);
		return ret;
	}

	ret =  bmg160_setup_any_motion_interrupt(data, state);
	if (ret < 0) {
		bmg160_set_power_state(data, false);
		mutex_unlock(&data->mutex);
		return ret;
	}

	data->ev_enable_state = state;
	mutex_unlock(&data->mutex);

	return 0;
}

__attribute__((used)) static irqreturn_t bmg160_trigger_handler(int irq, void *p)
{
	struct iio_poll_func *pf = p;
	struct iio_dev *indio_dev = pf->indio_dev;
	struct bmg160_data *data = iio_priv(indio_dev);
	int ret;

	mutex_lock(&data->mutex);
	ret = regmap_bulk_read(data->regmap, BMG160_REG_XOUT_L,
			       data->buffer, AXIS_MAX * 2);
	mutex_unlock(&data->mutex);
	if (ret < 0)
		goto err;

	iio_push_to_buffers_with_timestamp(indio_dev, data->buffer,
					   pf->timestamp);
err:
	iio_trigger_notify_done(indio_dev->trig);

	return IRQ_HANDLED;
}

__attribute__((used)) static int bmg160_trig_try_reen(struct iio_trigger *trig)
{
	struct iio_dev *indio_dev = iio_trigger_get_drvdata(trig);
	struct bmg160_data *data = iio_priv(indio_dev);
	struct device *dev = regmap_get_device(data->regmap);
	int ret;

	/* new data interrupts don't need ack */
	if (data->dready_trigger_on)
		return 0;

	/* Set latched mode interrupt and clear any latched interrupt */
	ret = regmap_write(data->regmap, BMG160_REG_INT_RST_LATCH,
			   BMG160_INT_MODE_LATCH_INT |
			   BMG160_INT_MODE_LATCH_RESET);
	if (ret < 0) {
		dev_err(dev, "Error writing reg_rst_latch\n");
		return ret;
	}

	return 0;
}

__attribute__((used)) static int bmg160_data_rdy_trigger_set_state(struct iio_trigger *trig,
					     bool state)
{
	struct iio_dev *indio_dev = iio_trigger_get_drvdata(trig);
	struct bmg160_data *data = iio_priv(indio_dev);
	int ret;

	mutex_lock(&data->mutex);

	if (!state && data->ev_enable_state && data->motion_trigger_on) {
		data->motion_trigger_on = false;
		mutex_unlock(&data->mutex);
		return 0;
	}

	/*
	 * Refer to comment in bmg160_write_event_config for
	 * enable/disable operation order
	 */
	ret = bmg160_set_power_state(data, state);
	if (ret < 0) {
		mutex_unlock(&data->mutex);
		return ret;
	}
	if (data->motion_trig == trig)
		ret =  bmg160_setup_any_motion_interrupt(data, state);
	else
		ret = bmg160_setup_new_data_interrupt(data, state);
	if (ret < 0) {
		bmg160_set_power_state(data, false);
		mutex_unlock(&data->mutex);
		return ret;
	}
	if (data->motion_trig == trig)
		data->motion_trigger_on = state;
	else
		data->dready_trigger_on = state;

	mutex_unlock(&data->mutex);

	return 0;
}

__attribute__((used)) static irqreturn_t bmg160_event_handler(int irq, void *private)
{
	struct iio_dev *indio_dev = private;
	struct bmg160_data *data = iio_priv(indio_dev);
	struct device *dev = regmap_get_device(data->regmap);
	int ret;
	int dir;
	unsigned int val;

	ret = regmap_read(data->regmap, BMG160_REG_INT_STATUS_2, &val);
	if (ret < 0) {
		dev_err(dev, "Error reading reg_int_status2\n");
		goto ack_intr_status;
	}

	if (val & 0x08)
		dir = IIO_EV_DIR_RISING;
	else
		dir = IIO_EV_DIR_FALLING;

	if (val & BMG160_ANY_MOTION_BIT_X)
		iio_push_event(indio_dev, IIO_MOD_EVENT_CODE(IIO_ANGL_VEL,
							     0,
							     IIO_MOD_X,
							     IIO_EV_TYPE_ROC,
							     dir),
			       iio_get_time_ns(indio_dev));
	if (val & BMG160_ANY_MOTION_BIT_Y)
		iio_push_event(indio_dev, IIO_MOD_EVENT_CODE(IIO_ANGL_VEL,
							     0,
							     IIO_MOD_Y,
							     IIO_EV_TYPE_ROC,
							     dir),
			       iio_get_time_ns(indio_dev));
	if (val & BMG160_ANY_MOTION_BIT_Z)
		iio_push_event(indio_dev, IIO_MOD_EVENT_CODE(IIO_ANGL_VEL,
							     0,
							     IIO_MOD_Z,
							     IIO_EV_TYPE_ROC,
							     dir),
			       iio_get_time_ns(indio_dev));

ack_intr_status:
	if (!data->dready_trigger_on) {
		ret = regmap_write(data->regmap, BMG160_REG_INT_RST_LATCH,
				   BMG160_INT_MODE_LATCH_INT |
				   BMG160_INT_MODE_LATCH_RESET);
		if (ret < 0)
			dev_err(dev, "Error writing reg_rst_latch\n");
	}

	return IRQ_HANDLED;
}

__attribute__((used)) static irqreturn_t bmg160_data_rdy_trig_poll(int irq, void *private)
{
	struct iio_dev *indio_dev = private;
	struct bmg160_data *data = iio_priv(indio_dev);

	if (data->dready_trigger_on)
		iio_trigger_poll(data->dready_trig);
	else if (data->motion_trigger_on)
		iio_trigger_poll(data->motion_trig);

	if (data->ev_enable_state)
		return IRQ_WAKE_THREAD;
	else
		return IRQ_HANDLED;

}

__attribute__((used)) static int bmg160_buffer_preenable(struct iio_dev *indio_dev)
{
	struct bmg160_data *data = iio_priv(indio_dev);

	return bmg160_set_power_state(data, true);
}

__attribute__((used)) static int bmg160_buffer_postdisable(struct iio_dev *indio_dev)
{
	struct bmg160_data *data = iio_priv(indio_dev);

	return bmg160_set_power_state(data, false);
}

__attribute__((used)) static const char *bmg160_match_acpi_device(struct device *dev)
{
	const struct acpi_device_id *id;

	id = acpi_match_device(dev->driver->acpi_match_table, dev);
	if (!id)
		return NULL;

	return dev_name(dev);
}

int bmg160_core_probe(struct device *dev, struct regmap *regmap, int irq,
		      const char *name)
{
	struct bmg160_data *data;
	struct iio_dev *indio_dev;
	int ret;

	indio_dev = devm_iio_device_alloc(dev, sizeof(*data));
	if (!indio_dev)
		return -ENOMEM;

	data = iio_priv(indio_dev);
	dev_set_drvdata(dev, indio_dev);
	data->irq = irq;
	data->regmap = regmap;

	ret = bmg160_chip_init(data);
	if (ret < 0)
		return ret;

	mutex_init(&data->mutex);

	if (ACPI_HANDLE(dev))
		name = bmg160_match_acpi_device(dev);

	indio_dev->dev.parent = dev;
	indio_dev->channels = bmg160_channels;
	indio_dev->num_channels = ARRAY_SIZE(bmg160_channels);
	indio_dev->name = name;
	indio_dev->available_scan_masks = bmg160_accel_scan_masks;
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->info = &bmg160_info;

	if (data->irq > 0) {
		ret = devm_request_threaded_irq(dev,
						data->irq,
						bmg160_data_rdy_trig_poll,
						bmg160_event_handler,
						IRQF_TRIGGER_RISING,
						BMG160_IRQ_NAME,
						indio_dev);
		if (ret)
			return ret;

		data->dready_trig = devm_iio_trigger_alloc(dev,
							   "%s-dev%d",
							   indio_dev->name,
							   indio_dev->id);
		if (!data->dready_trig)
			return -ENOMEM;

		data->motion_trig = devm_iio_trigger_alloc(dev,
							  "%s-any-motion-dev%d",
							  indio_dev->name,
							  indio_dev->id);
		if (!data->motion_trig)
			return -ENOMEM;

		data->dready_trig->dev.parent = dev;
		data->dready_trig->ops = &bmg160_trigger_ops;
		iio_trigger_set_drvdata(data->dready_trig, indio_dev);
		ret = iio_trigger_register(data->dready_trig);
		if (ret)
			return ret;

		data->motion_trig->dev.parent = dev;
		data->motion_trig->ops = &bmg160_trigger_ops;
		iio_trigger_set_drvdata(data->motion_trig, indio_dev);
		ret = iio_trigger_register(data->motion_trig);
		if (ret) {
			data->motion_trig = NULL;
			goto err_trigger_unregister;
		}
	}

	ret = iio_triggered_buffer_setup(indio_dev,
					 iio_pollfunc_store_time,
					 bmg160_trigger_handler,
					 &bmg160_buffer_setup_ops);
	if (ret < 0) {
		dev_err(dev,
			"iio triggered buffer setup failed\n");
		goto err_trigger_unregister;
	}

	ret = pm_runtime_set_active(dev);
	if (ret)
		goto err_buffer_cleanup;

	pm_runtime_enable(dev);
	pm_runtime_set_autosuspend_delay(dev,
					 BMG160_AUTO_SUSPEND_DELAY_MS);
	pm_runtime_use_autosuspend(dev);

	ret = iio_device_register(indio_dev);
	if (ret < 0) {
		dev_err(dev, "unable to register iio device\n");
		goto err_buffer_cleanup;
	}

	return 0;

err_buffer_cleanup:
	iio_triggered_buffer_cleanup(indio_dev);
err_trigger_unregister:
	if (data->dready_trig)
		iio_trigger_unregister(data->dready_trig);
	if (data->motion_trig)
		iio_trigger_unregister(data->motion_trig);

	return ret;
}

void bmg160_core_remove(struct device *dev)
{
	struct iio_dev *indio_dev = dev_get_drvdata(dev);
	struct bmg160_data *data = iio_priv(indio_dev);

	iio_device_unregister(indio_dev);

	pm_runtime_disable(dev);
	pm_runtime_set_suspended(dev);
	pm_runtime_put_noidle(dev);

	iio_triggered_buffer_cleanup(indio_dev);

	if (data->dready_trig) {
		iio_trigger_unregister(data->dready_trig);
		iio_trigger_unregister(data->motion_trig);
	}

	mutex_lock(&data->mutex);
	bmg160_set_mode(data, BMG160_MODE_DEEP_SUSPEND);
	mutex_unlock(&data->mutex);
}

