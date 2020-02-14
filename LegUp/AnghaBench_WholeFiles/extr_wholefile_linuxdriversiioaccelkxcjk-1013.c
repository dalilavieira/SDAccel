#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u8 ;
struct kxcjk_1013_platform_data {int active_high_intr; } ;
struct kxcjk1013_data {int range; int odr_bits; int active_high_intr; int wake_thres; int wake_dur; scalar_t__ chipset; int ev_enable_state; int motion_trigger_on; int dready_trigger_on; int is_smo8500_device; int /*<<< orphan*/  mutex; struct iio_trigger* motion_trig; struct iio_trigger* dready_trig; struct i2c_client* client; int /*<<< orphan*/  timestamp; scalar_t__ buffer; } ;
struct kx_odr_map {int gsel_0; int gsel_1; int val; int val2; int odr_bits; int wuf_bits; int scale; } ;
struct TYPE_6__ {struct device* parent; } ;
struct iio_trigger {int /*<<< orphan*/ * ops; TYPE_3__ dev; } ;
struct iio_poll_func {struct iio_dev* indio_dev; } ;
struct TYPE_5__ {struct device* parent; } ;
struct iio_dev {int num_channels; char const* name; struct iio_trigger* trig; int /*<<< orphan*/  id; int /*<<< orphan*/ * info; int /*<<< orphan*/  modes; int /*<<< orphan*/  available_scan_masks; struct kx_odr_map* channels; TYPE_2__ dev; } ;
struct iio_chan_spec {int scan_index; } ;
struct i2c_device_id {char* name; scalar_t__ driver_data; } ;
struct device {TYPE_1__* driver; } ;
struct i2c_client {scalar_t__ irq; struct device dev; } ;
struct device_attribute {int dummy; } ;
struct acpi_device_id {scalar_t__ driver_data; int /*<<< orphan*/  id; } ;
typedef  int /*<<< orphan*/  ssize_t ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  enum kxcjk1013_mode { ____Placeholder_kxcjk1013_mode } kxcjk1013_mode ;
typedef  enum kx_chipset { ____Placeholder_kx_chipset } kx_chipset ;
typedef  enum iio_event_type { ____Placeholder_iio_event_type } iio_event_type ;
typedef  enum iio_event_info { ____Placeholder_iio_event_info } iio_event_info ;
typedef  enum iio_event_direction { ____Placeholder_iio_event_direction } iio_event_direction ;
struct TYPE_4__ {int /*<<< orphan*/  acpi_match_table; } ;

/* Variables and functions */
 scalar_t__ ACPI_HANDLE (struct device*) ; 
 int ARRAY_SIZE (struct kx_odr_map*) ; 
 int AXIS_MAX ; 
 int EBUSY ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 struct kx_odr_map const* ERR_PTR (int) ; 
 int /*<<< orphan*/  IIO_ACCEL ; 
#define  IIO_CHAN_INFO_RAW 132 
#define  IIO_CHAN_INFO_SAMP_FREQ 131 
#define  IIO_CHAN_INFO_SCALE 130 
 int /*<<< orphan*/  IIO_EV_DIR_FALLING ; 
 int /*<<< orphan*/  IIO_EV_DIR_RISING ; 
#define  IIO_EV_INFO_PERIOD 129 
#define  IIO_EV_INFO_VALUE 128 
 int /*<<< orphan*/  IIO_EV_TYPE_THRESH ; 
 int /*<<< orphan*/  IIO_MOD_EVENT_CODE (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IIO_MOD_X ; 
 int /*<<< orphan*/  IIO_MOD_X_AND_Y_AND_Z ; 
 int /*<<< orphan*/  IIO_MOD_Y ; 
 int /*<<< orphan*/  IIO_MOD_Z ; 
 int IIO_VAL_INT ; 
 int IIO_VAL_INT_PLUS_MICRO ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int /*<<< orphan*/  IRQF_TRIGGER_RISING ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_WAKE_THREAD ; 
 scalar_t__ IS_ERR (struct kx_odr_map const*) ; 
 int KXCJK1013_DEFAULT_WAKE_THRES ; 
 int /*<<< orphan*/  KXCJK1013_IRQ_NAME ; 
 int KXCJK1013_RANGE_4G ; 
 int KXCJK1013_REG_CTRL1 ; 
 int KXCJK1013_REG_CTRL1_BIT_DRDY ; 
 int KXCJK1013_REG_CTRL1_BIT_GSEL0 ; 
 int KXCJK1013_REG_CTRL1_BIT_GSEL1 ; 
 int KXCJK1013_REG_CTRL1_BIT_PC1 ; 
 int KXCJK1013_REG_CTRL1_BIT_RES ; 
 int KXCJK1013_REG_CTRL1_BIT_WUFE ; 
 int KXCJK1013_REG_CTRL2 ; 
 int KXCJK1013_REG_DATA_CTRL ; 
 int KXCJK1013_REG_INT_CTRL1 ; 
 int KXCJK1013_REG_INT_CTRL1_BIT_IEA ; 
 int KXCJK1013_REG_INT_CTRL1_BIT_IEN ; 
 int KXCJK1013_REG_INT_REL ; 
 int KXCJK1013_REG_INT_SRC1 ; 
 int KXCJK1013_REG_INT_SRC1_BIT_WUFS ; 
 int KXCJK1013_REG_INT_SRC2 ; 
 int KXCJK1013_REG_INT_SRC2_BIT_XN ; 
 int KXCJK1013_REG_INT_SRC2_BIT_XP ; 
 int KXCJK1013_REG_INT_SRC2_BIT_YN ; 
 int KXCJK1013_REG_INT_SRC2_BIT_YP ; 
 int KXCJK1013_REG_INT_SRC2_BIT_ZN ; 
 int KXCJK1013_REG_INT_SRC2_BIT_ZP ; 
 int KXCJK1013_REG_WAKE_THRES ; 
 int KXCJK1013_REG_WAKE_TIMER ; 
 int KXCJK1013_REG_WHO_AM_I ; 
 scalar_t__ KXCJK1013_REG_XOUT_L ; 
 int /*<<< orphan*/  KXCJK1013_SLEEP_DELAY_MS ; 
 struct kx_odr_map* KXCJK1013_scale_table ; 
 scalar_t__ KXTF9 ; 
 int KXTF9_REG_WAKE_THRESH ; 
 int OPERATION ; 
 int PTR_ERR (struct kx_odr_map const*) ; 
 int STANDBY ; 
 struct acpi_device_id* acpi_match_device (int /*<<< orphan*/ ,struct device*) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,int) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct kxcjk_1013_platform_data* dev_get_platdata (struct device*) ; 
 char const* dev_name (struct device*) ; 
 struct iio_dev* dev_to_iio_dev (struct device*) ; 
 struct iio_dev* devm_iio_device_alloc (struct device*,int) ; 
 void* devm_iio_trigger_alloc (struct device*,char*,char const*,int /*<<< orphan*/ ) ; 
 int devm_request_threaded_irq (struct device*,scalar_t__,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct iio_dev*) ; 
 struct iio_dev* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int) ; 
 int i2c_smbus_read_i2c_block_data_or_emulated (struct i2c_client*,scalar_t__,int,scalar_t__*) ; 
 int i2c_smbus_read_word_data (struct i2c_client*,scalar_t__) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int,int) ; 
 int /*<<< orphan*/  iio_buffer_enabled (struct iio_dev*) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_get_time_ns (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_pollfunc_store_time ; 
 struct kxcjk1013_data* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_push_event (struct iio_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iio_push_to_buffers_with_timestamp (struct iio_dev*,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iio_trigger_get (struct iio_trigger*) ; 
 struct iio_dev* iio_trigger_get_drvdata (struct iio_trigger*) ; 
 int /*<<< orphan*/  iio_trigger_notify_done (struct iio_trigger*) ; 
 int /*<<< orphan*/  iio_trigger_poll (struct iio_trigger*) ; 
 int iio_trigger_register (struct iio_trigger*) ; 
 int /*<<< orphan*/  iio_trigger_set_drvdata (struct iio_trigger*,struct iio_dev*) ; 
 int /*<<< orphan*/  iio_trigger_unregister (struct iio_trigger*) ; 
 int /*<<< orphan*/  iio_triggered_buffer_cleanup (struct iio_dev*) ; 
 int iio_triggered_buffer_setup (struct iio_dev*,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kxcjk1013_buffer_setup_ops ; 
 struct kx_odr_map* kxcjk1013_channels ; 
 int /*<<< orphan*/  kxcjk1013_info ; 
 char* kxcjk1013_samp_freq_avail ; 
 int /*<<< orphan*/  kxcjk1013_scan_masks ; 
 int /*<<< orphan*/  kxcjk1013_trigger_ops ; 
 char* kxtf9_samp_freq_avail ; 
 struct kx_odr_map* kxtf9_samp_freq_table ; 
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
 struct kx_odr_map* samp_freq_table ; 
 int sign_extend32 (int,int) ; 
 int /*<<< orphan*/  sprintf (char*,char*,char const*) ; 
 scalar_t__ strcmp (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static int kxcjk1013_set_mode(struct kxcjk1013_data *data,
			      enum kxcjk1013_mode mode)
{
	int ret;

	ret = i2c_smbus_read_byte_data(data->client, KXCJK1013_REG_CTRL1);
	if (ret < 0) {
		dev_err(&data->client->dev, "Error reading reg_ctrl1\n");
		return ret;
	}

	if (mode == STANDBY)
		ret &= ~KXCJK1013_REG_CTRL1_BIT_PC1;
	else
		ret |= KXCJK1013_REG_CTRL1_BIT_PC1;

	ret = i2c_smbus_write_byte_data(data->client,
					KXCJK1013_REG_CTRL1, ret);
	if (ret < 0) {
		dev_err(&data->client->dev, "Error writing reg_ctrl1\n");
		return ret;
	}

	return 0;
}

__attribute__((used)) static int kxcjk1013_get_mode(struct kxcjk1013_data *data,
			      enum kxcjk1013_mode *mode)
{
	int ret;

	ret = i2c_smbus_read_byte_data(data->client, KXCJK1013_REG_CTRL1);
	if (ret < 0) {
		dev_err(&data->client->dev, "Error reading reg_ctrl1\n");
		return ret;
	}

	if (ret & KXCJK1013_REG_CTRL1_BIT_PC1)
		*mode = OPERATION;
	else
		*mode = STANDBY;

	return 0;
}

__attribute__((used)) static int kxcjk1013_set_range(struct kxcjk1013_data *data, int range_index)
{
	int ret;

	ret = i2c_smbus_read_byte_data(data->client, KXCJK1013_REG_CTRL1);
	if (ret < 0) {
		dev_err(&data->client->dev, "Error reading reg_ctrl1\n");
		return ret;
	}

	ret &= ~(KXCJK1013_REG_CTRL1_BIT_GSEL0 |
		 KXCJK1013_REG_CTRL1_BIT_GSEL1);
	ret |= (KXCJK1013_scale_table[range_index].gsel_0 << 3);
	ret |= (KXCJK1013_scale_table[range_index].gsel_1 << 4);

	ret = i2c_smbus_write_byte_data(data->client,
					KXCJK1013_REG_CTRL1,
					ret);
	if (ret < 0) {
		dev_err(&data->client->dev, "Error writing reg_ctrl1\n");
		return ret;
	}

	data->range = range_index;

	return 0;
}

__attribute__((used)) static int kxcjk1013_chip_init(struct kxcjk1013_data *data)
{
	int ret;

	ret = i2c_smbus_read_byte_data(data->client, KXCJK1013_REG_WHO_AM_I);
	if (ret < 0) {
		dev_err(&data->client->dev, "Error reading who_am_i\n");
		return ret;
	}

	dev_dbg(&data->client->dev, "KXCJK1013 Chip Id %x\n", ret);

	ret = kxcjk1013_set_mode(data, STANDBY);
	if (ret < 0)
		return ret;

	ret = i2c_smbus_read_byte_data(data->client, KXCJK1013_REG_CTRL1);
	if (ret < 0) {
		dev_err(&data->client->dev, "Error reading reg_ctrl1\n");
		return ret;
	}

	/* Set 12 bit mode */
	ret |= KXCJK1013_REG_CTRL1_BIT_RES;

	ret = i2c_smbus_write_byte_data(data->client, KXCJK1013_REG_CTRL1,
					ret);
	if (ret < 0) {
		dev_err(&data->client->dev, "Error reading reg_ctrl\n");
		return ret;
	}

	/* Setting range to 4G */
	ret = kxcjk1013_set_range(data, KXCJK1013_RANGE_4G);
	if (ret < 0)
		return ret;

	ret = i2c_smbus_read_byte_data(data->client, KXCJK1013_REG_DATA_CTRL);
	if (ret < 0) {
		dev_err(&data->client->dev, "Error reading reg_data_ctrl\n");
		return ret;
	}

	data->odr_bits = ret;

	/* Set up INT polarity */
	ret = i2c_smbus_read_byte_data(data->client, KXCJK1013_REG_INT_CTRL1);
	if (ret < 0) {
		dev_err(&data->client->dev, "Error reading reg_int_ctrl1\n");
		return ret;
	}

	if (data->active_high_intr)
		ret |= KXCJK1013_REG_INT_CTRL1_BIT_IEA;
	else
		ret &= ~KXCJK1013_REG_INT_CTRL1_BIT_IEA;

	ret = i2c_smbus_write_byte_data(data->client, KXCJK1013_REG_INT_CTRL1,
					ret);
	if (ret < 0) {
		dev_err(&data->client->dev, "Error writing reg_int_ctrl1\n");
		return ret;
	}

	ret = kxcjk1013_set_mode(data, OPERATION);
	if (ret < 0)
		return ret;

	data->wake_thres = KXCJK1013_DEFAULT_WAKE_THRES;

	return 0;
}

__attribute__((used)) static int kxcjk1013_set_power_state(struct kxcjk1013_data *data, bool on)
{
#ifdef CONFIG_PM
	int ret;

	if (on)
		ret = pm_runtime_get_sync(&data->client->dev);
	else {
		pm_runtime_mark_last_busy(&data->client->dev);
		ret = pm_runtime_put_autosuspend(&data->client->dev);
	}
	if (ret < 0) {
		dev_err(&data->client->dev,
			"Failed: kxcjk1013_set_power_state for %d\n", on);
		if (on)
			pm_runtime_put_noidle(&data->client->dev);
		return ret;
	}
#endif

	return 0;
}

__attribute__((used)) static int kxcjk1013_chip_update_thresholds(struct kxcjk1013_data *data)
{
	int waketh_reg, ret;

	ret = i2c_smbus_write_byte_data(data->client,
					KXCJK1013_REG_WAKE_TIMER,
					data->wake_dur);
	if (ret < 0) {
		dev_err(&data->client->dev,
			"Error writing reg_wake_timer\n");
		return ret;
	}

	waketh_reg = data->chipset == KXTF9 ?
		KXTF9_REG_WAKE_THRESH : KXCJK1013_REG_WAKE_THRES;
	ret = i2c_smbus_write_byte_data(data->client, waketh_reg,
					data->wake_thres);
	if (ret < 0) {
		dev_err(&data->client->dev, "Error writing reg_wake_thres\n");
		return ret;
	}

	return 0;
}

__attribute__((used)) static int kxcjk1013_setup_any_motion_interrupt(struct kxcjk1013_data *data,
						bool status)
{
	int ret;
	enum kxcjk1013_mode store_mode;

	ret = kxcjk1013_get_mode(data, &store_mode);
	if (ret < 0)
		return ret;

	/* This is requirement by spec to change state to STANDBY */
	ret = kxcjk1013_set_mode(data, STANDBY);
	if (ret < 0)
		return ret;

	ret = kxcjk1013_chip_update_thresholds(data);
	if (ret < 0)
		return ret;

	ret = i2c_smbus_read_byte_data(data->client, KXCJK1013_REG_INT_CTRL1);
	if (ret < 0) {
		dev_err(&data->client->dev, "Error reading reg_int_ctrl1\n");
		return ret;
	}

	if (status)
		ret |= KXCJK1013_REG_INT_CTRL1_BIT_IEN;
	else
		ret &= ~KXCJK1013_REG_INT_CTRL1_BIT_IEN;

	ret = i2c_smbus_write_byte_data(data->client, KXCJK1013_REG_INT_CTRL1,
					ret);
	if (ret < 0) {
		dev_err(&data->client->dev, "Error writing reg_int_ctrl1\n");
		return ret;
	}

	ret = i2c_smbus_read_byte_data(data->client, KXCJK1013_REG_CTRL1);
	if (ret < 0) {
		dev_err(&data->client->dev, "Error reading reg_ctrl1\n");
		return ret;
	}

	if (status)
		ret |= KXCJK1013_REG_CTRL1_BIT_WUFE;
	else
		ret &= ~KXCJK1013_REG_CTRL1_BIT_WUFE;

	ret = i2c_smbus_write_byte_data(data->client,
					KXCJK1013_REG_CTRL1, ret);
	if (ret < 0) {
		dev_err(&data->client->dev, "Error writing reg_ctrl1\n");
		return ret;
	}

	if (store_mode == OPERATION) {
		ret = kxcjk1013_set_mode(data, OPERATION);
		if (ret < 0)
			return ret;
	}

	return 0;
}

__attribute__((used)) static int kxcjk1013_setup_new_data_interrupt(struct kxcjk1013_data *data,
					      bool status)
{
	int ret;
	enum kxcjk1013_mode store_mode;

	ret = kxcjk1013_get_mode(data, &store_mode);
	if (ret < 0)
		return ret;

	/* This is requirement by spec to change state to STANDBY */
	ret = kxcjk1013_set_mode(data, STANDBY);
	if (ret < 0)
		return ret;

	ret = i2c_smbus_read_byte_data(data->client, KXCJK1013_REG_INT_CTRL1);
	if (ret < 0) {
		dev_err(&data->client->dev, "Error reading reg_int_ctrl1\n");
		return ret;
	}

	if (status)
		ret |= KXCJK1013_REG_INT_CTRL1_BIT_IEN;
	else
		ret &= ~KXCJK1013_REG_INT_CTRL1_BIT_IEN;

	ret = i2c_smbus_write_byte_data(data->client, KXCJK1013_REG_INT_CTRL1,
					ret);
	if (ret < 0) {
		dev_err(&data->client->dev, "Error writing reg_int_ctrl1\n");
		return ret;
	}

	ret = i2c_smbus_read_byte_data(data->client, KXCJK1013_REG_CTRL1);
	if (ret < 0) {
		dev_err(&data->client->dev, "Error reading reg_ctrl1\n");
		return ret;
	}

	if (status)
		ret |= KXCJK1013_REG_CTRL1_BIT_DRDY;
	else
		ret &= ~KXCJK1013_REG_CTRL1_BIT_DRDY;

	ret = i2c_smbus_write_byte_data(data->client,
					KXCJK1013_REG_CTRL1, ret);
	if (ret < 0) {
		dev_err(&data->client->dev, "Error writing reg_ctrl1\n");
		return ret;
	}

	if (store_mode == OPERATION) {
		ret = kxcjk1013_set_mode(data, OPERATION);
		if (ret < 0)
			return ret;
	}

	return 0;
}

__attribute__((used)) static const struct kx_odr_map *kxcjk1013_find_odr_value(
	const struct kx_odr_map *map, size_t map_size, int val, int val2)
{
	int i;

	for (i = 0; i < map_size; ++i) {
		if (map[i].val == val && map[i].val2 == val2)
			return &map[i];
	}

	return ERR_PTR(-EINVAL);
}

__attribute__((used)) static int kxcjk1013_convert_odr_value(const struct kx_odr_map *map,
				       size_t map_size, int odr_bits,
				       int *val, int *val2)
{
	int i;

	for (i = 0; i < map_size; ++i) {
		if (map[i].odr_bits == odr_bits) {
			*val = map[i].val;
			*val2 = map[i].val2;
			return IIO_VAL_INT_PLUS_MICRO;
		}
	}

	return -EINVAL;
}

__attribute__((used)) static int kxcjk1013_set_odr(struct kxcjk1013_data *data, int val, int val2)
{
	int ret;
	enum kxcjk1013_mode store_mode;
	const struct kx_odr_map *odr_setting;

	ret = kxcjk1013_get_mode(data, &store_mode);
	if (ret < 0)
		return ret;

	if (data->chipset == KXTF9)
		odr_setting = kxcjk1013_find_odr_value(kxtf9_samp_freq_table,
						       ARRAY_SIZE(kxtf9_samp_freq_table),
						       val, val2);
	else
		odr_setting = kxcjk1013_find_odr_value(samp_freq_table,
						       ARRAY_SIZE(samp_freq_table),
						       val, val2);

	if (IS_ERR(odr_setting))
		return PTR_ERR(odr_setting);

	/* To change ODR, the chip must be set to STANDBY as per spec */
	ret = kxcjk1013_set_mode(data, STANDBY);
	if (ret < 0)
		return ret;

	ret = i2c_smbus_write_byte_data(data->client, KXCJK1013_REG_DATA_CTRL,
					odr_setting->odr_bits);
	if (ret < 0) {
		dev_err(&data->client->dev, "Error writing data_ctrl\n");
		return ret;
	}

	data->odr_bits = odr_setting->odr_bits;

	ret = i2c_smbus_write_byte_data(data->client, KXCJK1013_REG_CTRL2,
					odr_setting->wuf_bits);
	if (ret < 0) {
		dev_err(&data->client->dev, "Error writing reg_ctrl2\n");
		return ret;
	}

	if (store_mode == OPERATION) {
		ret = kxcjk1013_set_mode(data, OPERATION);
		if (ret < 0)
			return ret;
	}

	return 0;
}

__attribute__((used)) static int kxcjk1013_get_odr(struct kxcjk1013_data *data, int *val, int *val2)
{
	if (data->chipset == KXTF9)
		return kxcjk1013_convert_odr_value(kxtf9_samp_freq_table,
						   ARRAY_SIZE(kxtf9_samp_freq_table),
						   data->odr_bits, val, val2);
	else
		return kxcjk1013_convert_odr_value(samp_freq_table,
						   ARRAY_SIZE(samp_freq_table),
						   data->odr_bits, val, val2);
}

__attribute__((used)) static int kxcjk1013_get_acc_reg(struct kxcjk1013_data *data, int axis)
{
	u8 reg = KXCJK1013_REG_XOUT_L + axis * 2;
	int ret;

	ret = i2c_smbus_read_word_data(data->client, reg);
	if (ret < 0) {
		dev_err(&data->client->dev,
			"failed to read accel_%c registers\n", 'x' + axis);
		return ret;
	}

	return ret;
}

__attribute__((used)) static int kxcjk1013_set_scale(struct kxcjk1013_data *data, int val)
{
	int ret, i;
	enum kxcjk1013_mode store_mode;

	for (i = 0; i < ARRAY_SIZE(KXCJK1013_scale_table); ++i) {
		if (KXCJK1013_scale_table[i].scale == val) {
			ret = kxcjk1013_get_mode(data, &store_mode);
			if (ret < 0)
				return ret;

			ret = kxcjk1013_set_mode(data, STANDBY);
			if (ret < 0)
				return ret;

			ret = kxcjk1013_set_range(data, i);
			if (ret < 0)
				return ret;

			if (store_mode == OPERATION) {
				ret = kxcjk1013_set_mode(data, OPERATION);
				if (ret)
					return ret;
			}

			return 0;
		}
	}

	return -EINVAL;
}

__attribute__((used)) static int kxcjk1013_read_raw(struct iio_dev *indio_dev,
			      struct iio_chan_spec const *chan, int *val,
			      int *val2, long mask)
{
	struct kxcjk1013_data *data = iio_priv(indio_dev);
	int ret;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		mutex_lock(&data->mutex);
		if (iio_buffer_enabled(indio_dev))
			ret = -EBUSY;
		else {
			ret = kxcjk1013_set_power_state(data, true);
			if (ret < 0) {
				mutex_unlock(&data->mutex);
				return ret;
			}
			ret = kxcjk1013_get_acc_reg(data, chan->scan_index);
			if (ret < 0) {
				kxcjk1013_set_power_state(data, false);
				mutex_unlock(&data->mutex);
				return ret;
			}
			*val = sign_extend32(ret >> 4, 11);
			ret = kxcjk1013_set_power_state(data, false);
		}
		mutex_unlock(&data->mutex);

		if (ret < 0)
			return ret;

		return IIO_VAL_INT;

	case IIO_CHAN_INFO_SCALE:
		*val = 0;
		*val2 = KXCJK1013_scale_table[data->range].scale;
		return IIO_VAL_INT_PLUS_MICRO;

	case IIO_CHAN_INFO_SAMP_FREQ:
		mutex_lock(&data->mutex);
		ret = kxcjk1013_get_odr(data, val, val2);
		mutex_unlock(&data->mutex);
		return ret;

	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int kxcjk1013_write_raw(struct iio_dev *indio_dev,
			       struct iio_chan_spec const *chan, int val,
			       int val2, long mask)
{
	struct kxcjk1013_data *data = iio_priv(indio_dev);
	int ret;

	switch (mask) {
	case IIO_CHAN_INFO_SAMP_FREQ:
		mutex_lock(&data->mutex);
		ret = kxcjk1013_set_odr(data, val, val2);
		mutex_unlock(&data->mutex);
		break;
	case IIO_CHAN_INFO_SCALE:
		if (val)
			return -EINVAL;

		mutex_lock(&data->mutex);
		ret = kxcjk1013_set_scale(data, val2);
		mutex_unlock(&data->mutex);
		break;
	default:
		ret = -EINVAL;
	}

	return ret;
}

__attribute__((used)) static int kxcjk1013_read_event(struct iio_dev *indio_dev,
				   const struct iio_chan_spec *chan,
				   enum iio_event_type type,
				   enum iio_event_direction dir,
				   enum iio_event_info info,
				   int *val, int *val2)
{
	struct kxcjk1013_data *data = iio_priv(indio_dev);

	*val2 = 0;
	switch (info) {
	case IIO_EV_INFO_VALUE:
		*val = data->wake_thres;
		break;
	case IIO_EV_INFO_PERIOD:
		*val = data->wake_dur;
		break;
	default:
		return -EINVAL;
	}

	return IIO_VAL_INT;
}

__attribute__((used)) static int kxcjk1013_write_event(struct iio_dev *indio_dev,
				    const struct iio_chan_spec *chan,
				    enum iio_event_type type,
				    enum iio_event_direction dir,
				    enum iio_event_info info,
				    int val, int val2)
{
	struct kxcjk1013_data *data = iio_priv(indio_dev);

	if (data->ev_enable_state)
		return -EBUSY;

	switch (info) {
	case IIO_EV_INFO_VALUE:
		data->wake_thres = val;
		break;
	case IIO_EV_INFO_PERIOD:
		data->wake_dur = val;
		break;
	default:
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int kxcjk1013_read_event_config(struct iio_dev *indio_dev,
					  const struct iio_chan_spec *chan,
					  enum iio_event_type type,
					  enum iio_event_direction dir)
{
	struct kxcjk1013_data *data = iio_priv(indio_dev);

	return data->ev_enable_state;
}

__attribute__((used)) static int kxcjk1013_write_event_config(struct iio_dev *indio_dev,
					   const struct iio_chan_spec *chan,
					   enum iio_event_type type,
					   enum iio_event_direction dir,
					   int state)
{
	struct kxcjk1013_data *data = iio_priv(indio_dev);
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
	ret = kxcjk1013_set_power_state(data, state);
	if (ret < 0) {
		mutex_unlock(&data->mutex);
		return ret;
	}

	ret =  kxcjk1013_setup_any_motion_interrupt(data, state);
	if (ret < 0) {
		kxcjk1013_set_power_state(data, false);
		data->ev_enable_state = 0;
		mutex_unlock(&data->mutex);
		return ret;
	}

	data->ev_enable_state = state;
	mutex_unlock(&data->mutex);

	return 0;
}

__attribute__((used)) static int kxcjk1013_buffer_preenable(struct iio_dev *indio_dev)
{
	struct kxcjk1013_data *data = iio_priv(indio_dev);

	return kxcjk1013_set_power_state(data, true);
}

__attribute__((used)) static int kxcjk1013_buffer_postdisable(struct iio_dev *indio_dev)
{
	struct kxcjk1013_data *data = iio_priv(indio_dev);

	return kxcjk1013_set_power_state(data, false);
}

__attribute__((used)) static ssize_t kxcjk1013_get_samp_freq_avail(struct device *dev,
					     struct device_attribute *attr,
					     char *buf)
{
	struct iio_dev *indio_dev = dev_to_iio_dev(dev);
	struct kxcjk1013_data *data = iio_priv(indio_dev);
	const char *str;

	if (data->chipset == KXTF9)
		str = kxtf9_samp_freq_avail;
	else
		str = kxcjk1013_samp_freq_avail;

	return sprintf(buf, "%s\n", str);
}

__attribute__((used)) static irqreturn_t kxcjk1013_trigger_handler(int irq, void *p)
{
	struct iio_poll_func *pf = p;
	struct iio_dev *indio_dev = pf->indio_dev;
	struct kxcjk1013_data *data = iio_priv(indio_dev);
	int ret;

	mutex_lock(&data->mutex);
	ret = i2c_smbus_read_i2c_block_data_or_emulated(data->client,
							KXCJK1013_REG_XOUT_L,
							AXIS_MAX * 2,
							(u8 *)data->buffer);
	mutex_unlock(&data->mutex);
	if (ret < 0)
		goto err;

	iio_push_to_buffers_with_timestamp(indio_dev, data->buffer,
					   data->timestamp);
err:
	iio_trigger_notify_done(indio_dev->trig);

	return IRQ_HANDLED;
}

__attribute__((used)) static int kxcjk1013_trig_try_reen(struct iio_trigger *trig)
{
	struct iio_dev *indio_dev = iio_trigger_get_drvdata(trig);
	struct kxcjk1013_data *data = iio_priv(indio_dev);
	int ret;

	ret = i2c_smbus_read_byte_data(data->client, KXCJK1013_REG_INT_REL);
	if (ret < 0) {
		dev_err(&data->client->dev, "Error reading reg_int_rel\n");
		return ret;
	}

	return 0;
}

__attribute__((used)) static int kxcjk1013_data_rdy_trigger_set_state(struct iio_trigger *trig,
						bool state)
{
	struct iio_dev *indio_dev = iio_trigger_get_drvdata(trig);
	struct kxcjk1013_data *data = iio_priv(indio_dev);
	int ret;

	mutex_lock(&data->mutex);

	if (!state && data->ev_enable_state && data->motion_trigger_on) {
		data->motion_trigger_on = false;
		mutex_unlock(&data->mutex);
		return 0;
	}

	ret = kxcjk1013_set_power_state(data, state);
	if (ret < 0) {
		mutex_unlock(&data->mutex);
		return ret;
	}
	if (data->motion_trig == trig)
		ret = kxcjk1013_setup_any_motion_interrupt(data, state);
	else
		ret = kxcjk1013_setup_new_data_interrupt(data, state);
	if (ret < 0) {
		kxcjk1013_set_power_state(data, false);
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

__attribute__((used)) static void kxcjk1013_report_motion_event(struct iio_dev *indio_dev)
{
	struct kxcjk1013_data *data = iio_priv(indio_dev);

	int ret = i2c_smbus_read_byte_data(data->client,
					   KXCJK1013_REG_INT_SRC2);
	if (ret < 0) {
		dev_err(&data->client->dev, "Error reading reg_int_src2\n");
		return;
	}

	if (ret & KXCJK1013_REG_INT_SRC2_BIT_XN)
		iio_push_event(indio_dev,
			       IIO_MOD_EVENT_CODE(IIO_ACCEL,
						  0,
						  IIO_MOD_X,
						  IIO_EV_TYPE_THRESH,
						  IIO_EV_DIR_FALLING),
			       data->timestamp);

	if (ret & KXCJK1013_REG_INT_SRC2_BIT_XP)
		iio_push_event(indio_dev,
			       IIO_MOD_EVENT_CODE(IIO_ACCEL,
						  0,
						  IIO_MOD_X,
						  IIO_EV_TYPE_THRESH,
						  IIO_EV_DIR_RISING),
			       data->timestamp);

	if (ret & KXCJK1013_REG_INT_SRC2_BIT_YN)
		iio_push_event(indio_dev,
			       IIO_MOD_EVENT_CODE(IIO_ACCEL,
						  0,
						  IIO_MOD_Y,
						  IIO_EV_TYPE_THRESH,
						  IIO_EV_DIR_FALLING),
			       data->timestamp);

	if (ret & KXCJK1013_REG_INT_SRC2_BIT_YP)
		iio_push_event(indio_dev,
			       IIO_MOD_EVENT_CODE(IIO_ACCEL,
						  0,
						  IIO_MOD_Y,
						  IIO_EV_TYPE_THRESH,
						  IIO_EV_DIR_RISING),
			       data->timestamp);

	if (ret & KXCJK1013_REG_INT_SRC2_BIT_ZN)
		iio_push_event(indio_dev,
			       IIO_MOD_EVENT_CODE(IIO_ACCEL,
						  0,
						  IIO_MOD_Z,
						  IIO_EV_TYPE_THRESH,
						  IIO_EV_DIR_FALLING),
			       data->timestamp);

	if (ret & KXCJK1013_REG_INT_SRC2_BIT_ZP)
		iio_push_event(indio_dev,
			       IIO_MOD_EVENT_CODE(IIO_ACCEL,
						  0,
						  IIO_MOD_Z,
						  IIO_EV_TYPE_THRESH,
						  IIO_EV_DIR_RISING),
			       data->timestamp);
}

__attribute__((used)) static irqreturn_t kxcjk1013_event_handler(int irq, void *private)
{
	struct iio_dev *indio_dev = private;
	struct kxcjk1013_data *data = iio_priv(indio_dev);
	int ret;

	ret = i2c_smbus_read_byte_data(data->client, KXCJK1013_REG_INT_SRC1);
	if (ret < 0) {
		dev_err(&data->client->dev, "Error reading reg_int_src1\n");
		goto ack_intr;
	}

	if (ret & KXCJK1013_REG_INT_SRC1_BIT_WUFS) {
		if (data->chipset == KXTF9)
			iio_push_event(indio_dev,
				       IIO_MOD_EVENT_CODE(IIO_ACCEL,
				       0,
				       IIO_MOD_X_AND_Y_AND_Z,
				       IIO_EV_TYPE_THRESH,
				       IIO_EV_DIR_RISING),
				       data->timestamp);
		else
			kxcjk1013_report_motion_event(indio_dev);
	}

ack_intr:
	if (data->dready_trigger_on)
		return IRQ_HANDLED;

	ret = i2c_smbus_read_byte_data(data->client, KXCJK1013_REG_INT_REL);
	if (ret < 0)
		dev_err(&data->client->dev, "Error reading reg_int_rel\n");

	return IRQ_HANDLED;
}

__attribute__((used)) static irqreturn_t kxcjk1013_data_rdy_trig_poll(int irq, void *private)
{
	struct iio_dev *indio_dev = private;
	struct kxcjk1013_data *data = iio_priv(indio_dev);

	data->timestamp = iio_get_time_ns(indio_dev);

	if (data->dready_trigger_on)
		iio_trigger_poll(data->dready_trig);
	else if (data->motion_trigger_on)
		iio_trigger_poll(data->motion_trig);

	if (data->ev_enable_state)
		return IRQ_WAKE_THREAD;
	else
		return IRQ_HANDLED;
}

__attribute__((used)) static const char *kxcjk1013_match_acpi_device(struct device *dev,
					       enum kx_chipset *chipset,
					       bool *is_smo8500_device)
{
	const struct acpi_device_id *id;

	id = acpi_match_device(dev->driver->acpi_match_table, dev);
	if (!id)
		return NULL;

	if (strcmp(id->id, "SMO8500") == 0)
		*is_smo8500_device = true;

	*chipset = (enum kx_chipset)id->driver_data;

	return dev_name(dev);
}

__attribute__((used)) static int kxcjk1013_probe(struct i2c_client *client,
			   const struct i2c_device_id *id)
{
	struct kxcjk1013_data *data;
	struct iio_dev *indio_dev;
	struct kxcjk_1013_platform_data *pdata;
	const char *name;
	int ret;

	indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
	if (!indio_dev)
		return -ENOMEM;

	data = iio_priv(indio_dev);
	i2c_set_clientdata(client, indio_dev);
	data->client = client;

	pdata = dev_get_platdata(&client->dev);
	if (pdata)
		data->active_high_intr = pdata->active_high_intr;
	else
		data->active_high_intr = true; /* default polarity */

	if (id) {
		data->chipset = (enum kx_chipset)(id->driver_data);
		name = id->name;
	} else if (ACPI_HANDLE(&client->dev)) {
		name = kxcjk1013_match_acpi_device(&client->dev,
						   &data->chipset,
						   &data->is_smo8500_device);
	} else
		return -ENODEV;

	ret = kxcjk1013_chip_init(data);
	if (ret < 0)
		return ret;

	mutex_init(&data->mutex);

	indio_dev->dev.parent = &client->dev;
	indio_dev->channels = kxcjk1013_channels;
	indio_dev->num_channels = ARRAY_SIZE(kxcjk1013_channels);
	indio_dev->available_scan_masks = kxcjk1013_scan_masks;
	indio_dev->name = name;
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->info = &kxcjk1013_info;

	if (client->irq > 0 && !data->is_smo8500_device) {
		ret = devm_request_threaded_irq(&client->dev, client->irq,
						kxcjk1013_data_rdy_trig_poll,
						kxcjk1013_event_handler,
						IRQF_TRIGGER_RISING,
						KXCJK1013_IRQ_NAME,
						indio_dev);
		if (ret)
			goto err_poweroff;

		data->dready_trig = devm_iio_trigger_alloc(&client->dev,
							   "%s-dev%d",
							   indio_dev->name,
							   indio_dev->id);
		if (!data->dready_trig) {
			ret = -ENOMEM;
			goto err_poweroff;
		}

		data->motion_trig = devm_iio_trigger_alloc(&client->dev,
							  "%s-any-motion-dev%d",
							  indio_dev->name,
							  indio_dev->id);
		if (!data->motion_trig) {
			ret = -ENOMEM;
			goto err_poweroff;
		}

		data->dready_trig->dev.parent = &client->dev;
		data->dready_trig->ops = &kxcjk1013_trigger_ops;
		iio_trigger_set_drvdata(data->dready_trig, indio_dev);
		indio_dev->trig = data->dready_trig;
		iio_trigger_get(indio_dev->trig);
		ret = iio_trigger_register(data->dready_trig);
		if (ret)
			goto err_poweroff;

		data->motion_trig->dev.parent = &client->dev;
		data->motion_trig->ops = &kxcjk1013_trigger_ops;
		iio_trigger_set_drvdata(data->motion_trig, indio_dev);
		ret = iio_trigger_register(data->motion_trig);
		if (ret) {
			data->motion_trig = NULL;
			goto err_trigger_unregister;
		}
	}

	ret = iio_triggered_buffer_setup(indio_dev,
					 &iio_pollfunc_store_time,
					 kxcjk1013_trigger_handler,
					 &kxcjk1013_buffer_setup_ops);
	if (ret < 0) {
		dev_err(&client->dev, "iio triggered buffer setup failed\n");
		goto err_trigger_unregister;
	}

	ret = pm_runtime_set_active(&client->dev);
	if (ret)
		goto err_buffer_cleanup;

	pm_runtime_enable(&client->dev);
	pm_runtime_set_autosuspend_delay(&client->dev,
					 KXCJK1013_SLEEP_DELAY_MS);
	pm_runtime_use_autosuspend(&client->dev);

	ret = iio_device_register(indio_dev);
	if (ret < 0) {
		dev_err(&client->dev, "unable to register iio device\n");
		goto err_buffer_cleanup;
	}

	return 0;

err_buffer_cleanup:
	if (data->dready_trig)
		iio_triggered_buffer_cleanup(indio_dev);
err_trigger_unregister:
	if (data->dready_trig)
		iio_trigger_unregister(data->dready_trig);
	if (data->motion_trig)
		iio_trigger_unregister(data->motion_trig);
err_poweroff:
	kxcjk1013_set_mode(data, STANDBY);

	return ret;
}

__attribute__((used)) static int kxcjk1013_remove(struct i2c_client *client)
{
	struct iio_dev *indio_dev = i2c_get_clientdata(client);
	struct kxcjk1013_data *data = iio_priv(indio_dev);

	iio_device_unregister(indio_dev);

	pm_runtime_disable(&client->dev);
	pm_runtime_set_suspended(&client->dev);
	pm_runtime_put_noidle(&client->dev);

	if (data->dready_trig) {
		iio_triggered_buffer_cleanup(indio_dev);
		iio_trigger_unregister(data->dready_trig);
		iio_trigger_unregister(data->motion_trig);
	}

	mutex_lock(&data->mutex);
	kxcjk1013_set_mode(data, STANDBY);
	mutex_unlock(&data->mutex);

	return 0;
}

