#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u16 ;
struct mma9553_event {int enabled; TYPE_3__* info; } ;
struct TYPE_5__ {int config; int height_weight; int filter; int speed_step; int actthd; int /*<<< orphan*/  sleepthd; int /*<<< orphan*/  sleepmax; int /*<<< orphan*/  sleepmin; } ;
struct mma9553_data {int num_events; int gpio_bitnum; int activity; int stepcnt; int stepcnt_enabled; int /*<<< orphan*/  mutex; struct i2c_client* client; int /*<<< orphan*/  timestamp; TYPE_1__ conf; struct mma9553_event* events; } ;
struct TYPE_8__ {struct device* parent; } ;
struct iio_dev {int* channels; char const* name; TYPE_4__ dev; int /*<<< orphan*/ * info; int /*<<< orphan*/  modes; int /*<<< orphan*/  num_channels; } ;
struct iio_chan_spec {int type; int channel2; } ;
struct i2c_device_id {char* name; } ;
struct device {TYPE_2__* driver; } ;
struct i2c_client {scalar_t__ irq; struct device dev; } ;
struct acpi_device_id {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  enum iio_modifier { ____Placeholder_iio_modifier } iio_modifier ;
typedef  enum iio_event_type { ____Placeholder_iio_event_type } iio_event_type ;
typedef  enum iio_event_info { ____Placeholder_iio_event_info } iio_event_info ;
typedef  enum iio_event_direction { ____Placeholder_iio_event_direction } iio_event_direction ;
typedef  enum iio_chan_type { ____Placeholder_iio_chan_type } iio_chan_type ;
typedef  enum activity_level { ____Placeholder_activity_level } activity_level ;
struct TYPE_7__ {int type; int mod; int dir; } ;
struct TYPE_6__ {int /*<<< orphan*/  acpi_match_table; } ;

/* Variables and functions */
 scalar_t__ ACPI_HANDLE (struct device*) ; 
#define  ACTIVITY_JOGGING 149 
#define  ACTIVITY_REST 148 
#define  ACTIVITY_RUNNING 147 
#define  ACTIVITY_UNKNOWN 146 
#define  ACTIVITY_WALKING 145 
 int /*<<< orphan*/  ARRAY_SIZE (int*) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int ENOSYS ; 
#define  IIO_ACCEL 144 
#define  IIO_ACTIVITY 143 
#define  IIO_CHAN_INFO_CALIBHEIGHT 142 
#define  IIO_CHAN_INFO_CALIBWEIGHT 141 
#define  IIO_CHAN_INFO_DEBOUNCE_COUNT 140 
#define  IIO_CHAN_INFO_DEBOUNCE_TIME 139 
#define  IIO_CHAN_INFO_ENABLE 138 
#define  IIO_CHAN_INFO_INT_TIME 137 
#define  IIO_CHAN_INFO_PROCESSED 136 
#define  IIO_CHAN_INFO_RAW 135 
#define  IIO_CHAN_INFO_SCALE 134 
#define  IIO_DISTANCE 133 
#define  IIO_ENERGY 132 
 int /*<<< orphan*/  IIO_EVENT_CODE (int,int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int IIO_EV_DIR_FALLING ; 
 int IIO_EV_DIR_NONE ; 
 int IIO_EV_DIR_RISING ; 
#define  IIO_EV_INFO_PERIOD 131 
#define  IIO_EV_INFO_VALUE 130 
 int /*<<< orphan*/  IIO_EV_TYPE_CHANGE ; 
 int /*<<< orphan*/  IIO_EV_TYPE_THRESH ; 
 int IIO_MOD_JOGGING ; 
 int IIO_MOD_ROOT_SUM_SQUARED_X_Y_Z ; 
 int IIO_MOD_RUNNING ; 
 int IIO_MOD_STILL ; 
 int IIO_MOD_WALKING ; 
 int IIO_NO_MOD ; 
#define  IIO_STEPS 129 
 int IIO_VAL_INT ; 
 int IIO_VAL_INT_PLUS_MICRO ; 
#define  IIO_VELOCITY 128 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int /*<<< orphan*/  IRQF_TRIGGER_RISING ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_WAKE_THREAD ; 
 int MMA9551_APPID_NONE ; 
 int MMA9551_APPID_PEDOMETER ; 
 int /*<<< orphan*/  MMA9551_AUTO_SUSPEND_DELAY_MS ; 
 int /*<<< orphan*/  MMA9551_RSC_PED ; 
 int MMA9553_ACTIVITY_SEC_TO_THD (int) ; 
 int MMA9553_ACTIVITY_THD_TO_SEC (int) ; 
 int MMA9553_CONFIG_RETRIES ; 
 int /*<<< orphan*/  MMA9553_DEFAULT_GPIO_PIN ; 
 int /*<<< orphan*/  MMA9553_DEFAULT_GPIO_POLARITY ; 
 int /*<<< orphan*/  MMA9553_DEFAULT_SAMPLE_RATE ; 
 int /*<<< orphan*/  MMA9553_DEFAULT_SLEEPMAX ; 
 int /*<<< orphan*/  MMA9553_DEFAULT_SLEEPMIN ; 
 int /*<<< orphan*/  MMA9553_DEFAULT_SLEEPTHD ; 
 int MMA9553_EVENTS_INFO_SIZE ; 
 int /*<<< orphan*/  MMA9553_IRQ_NAME ; 
 int MMA9553_MASK_CONF_ACT_DBCNTM ; 
 int MMA9553_MASK_CONF_CONFIG ; 
 int MMA9553_MASK_CONF_FILTSTEP ; 
 int MMA9553_MASK_CONF_FILTTIME ; 
 int MMA9553_MASK_CONF_HEIGHT ; 
 int MMA9553_MASK_CONF_MALE ; 
 int MMA9553_MASK_CONF_SPDPRD ; 
 int MMA9553_MASK_CONF_STEPCOALESCE ; 
 int MMA9553_MASK_CONF_WEIGHT ; 
 int MMA9553_MASK_CONF_WORD ; 
 int /*<<< orphan*/  MMA9553_MASK_STATUS_ACTCHG ; 
 int MMA9553_MASK_STATUS_ACTIVITY ; 
 int /*<<< orphan*/  MMA9553_MASK_STATUS_MRGFL ; 
 int /*<<< orphan*/  MMA9553_MASK_STATUS_STEPCHG ; 
 int MMA9553_MAX_ACTTHD ; 
 int MMA9553_MAX_BITNUM ; 
 int MMA9553_REG_CALORIES ; 
 int MMA9553_REG_CONF_ACTTHD ; 
 int MMA9553_REG_CONF_CONF_STEPLEN ; 
 int MMA9553_REG_CONF_FILTER ; 
 int MMA9553_REG_CONF_HEIGHT_WEIGHT ; 
 int /*<<< orphan*/  MMA9553_REG_CONF_SLEEPMIN ; 
 int MMA9553_REG_CONF_SPEED_STEP ; 
 int MMA9553_REG_DISTANCE ; 
 int MMA9553_REG_SPEED ; 
 int MMA9553_REG_STATUS ; 
 int MMA9553_REG_STEPCNT ; 
 int MMA9553_STATUS_TO_BITNUM (int /*<<< orphan*/ ) ; 
 struct acpi_device_id* acpi_match_device (int /*<<< orphan*/ ,struct device*) ; 
 int /*<<< orphan*/  dev_dbg (TYPE_4__*,char*,char const*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 char const* dev_name (struct device*) ; 
 struct iio_dev* devm_iio_device_alloc (struct device*,int) ; 
 int devm_request_threaded_irq (struct device*,scalar_t__,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct iio_dev*) ; 
 int ffs (int) ; 
 struct iio_dev* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_get_time_ns (struct iio_dev*) ; 
 struct mma9553_data* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_push_event (struct iio_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int mma9551_app_reset (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int mma9551_gpio_config (struct i2c_client*,int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ) ; 
 int mma9551_read_accel_chan (struct i2c_client*,struct iio_chan_spec const*,int*,int*) ; 
 int mma9551_read_accel_scale (int*,int*) ; 
 int mma9551_read_config_word (struct i2c_client*,int,int,int*) ; 
 int mma9551_read_config_words (struct i2c_client*,int,int /*<<< orphan*/ ,int,int*) ; 
 int mma9551_read_status_word (struct i2c_client*,int,int,int*) ; 
 int mma9551_read_status_words (struct i2c_client*,int,int,int /*<<< orphan*/ ,int*) ; 
 int mma9551_read_version (struct i2c_client*) ; 
 int mma9551_set_device_state (struct i2c_client*,int) ; 
 int mma9551_set_power_state (struct i2c_client*,int) ; 
 int /*<<< orphan*/  mma9551_sleep (int /*<<< orphan*/ ) ; 
 int mma9551_write_config_word (struct i2c_client*,int,int,int) ; 
 int mma9551_write_config_words (struct i2c_client*,int,int /*<<< orphan*/ ,int,int*) ; 
 int* mma9553_channels ; 
 TYPE_3__* mma9553_events_info ; 
 int /*<<< orphan*/  mma9553_info ; 
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

__attribute__((used)) static u8 mma9553_get_bits(u16 val, u16 mask)
{
	return (val & mask) >> (ffs(mask) - 1);
}

__attribute__((used)) static u16 mma9553_set_bits(u16 current_val, u16 val, u16 mask)
{
	return (current_val & ~mask) | (val << (ffs(mask) - 1));
}

__attribute__((used)) static enum iio_modifier mma9553_activity_to_mod(enum activity_level activity)
{
	switch (activity) {
	case ACTIVITY_RUNNING:
		return IIO_MOD_RUNNING;
	case ACTIVITY_JOGGING:
		return IIO_MOD_JOGGING;
	case ACTIVITY_WALKING:
		return IIO_MOD_WALKING;
	case ACTIVITY_REST:
		return IIO_MOD_STILL;
	case ACTIVITY_UNKNOWN:
	default:
		return IIO_NO_MOD;
	}
}

__attribute__((used)) static void mma9553_init_events(struct mma9553_data *data)
{
	int i;

	data->num_events = MMA9553_EVENTS_INFO_SIZE;
	for (i = 0; i < data->num_events; i++) {
		data->events[i].info = &mma9553_events_info[i];
		data->events[i].enabled = false;
	}
}

__attribute__((used)) static struct mma9553_event *mma9553_get_event(struct mma9553_data *data,
					       enum iio_chan_type type,
					       enum iio_modifier mod,
					       enum iio_event_direction dir)
{
	int i;

	for (i = 0; i < data->num_events; i++)
		if (data->events[i].info->type == type &&
		    data->events[i].info->mod == mod &&
		    data->events[i].info->dir == dir)
			return &data->events[i];

	return NULL;
}

__attribute__((used)) static bool mma9553_is_any_event_enabled(struct mma9553_data *data,
					 bool check_type,
					 enum iio_chan_type type)
{
	int i;

	for (i = 0; i < data->num_events; i++)
		if ((check_type && data->events[i].info->type == type &&
		     data->events[i].enabled) ||
		     (!check_type && data->events[i].enabled))
			return true;

	return false;
}

__attribute__((used)) static int mma9553_set_config(struct mma9553_data *data, u16 reg,
			      u16 *p_reg_val, u16 val, u16 mask)
{
	int ret, retries;
	u16 reg_val, config;

	reg_val = *p_reg_val;
	if (val == mma9553_get_bits(reg_val, mask))
		return 0;

	reg_val = mma9553_set_bits(reg_val, val, mask);
	ret = mma9551_write_config_word(data->client, MMA9551_APPID_PEDOMETER,
					reg, reg_val);
	if (ret < 0) {
		dev_err(&data->client->dev,
			"error writing config register 0x%x\n", reg);
		return ret;
	}

	*p_reg_val = reg_val;

	/* Reinitializes the pedometer with current configuration values */
	config = mma9553_set_bits(data->conf.config, 1,
				  MMA9553_MASK_CONF_CONFIG);

	ret = mma9551_write_config_word(data->client, MMA9551_APPID_PEDOMETER,
					MMA9553_REG_CONF_CONF_STEPLEN, config);
	if (ret < 0) {
		dev_err(&data->client->dev,
			"error writing config register 0x%x\n",
			MMA9553_REG_CONF_CONF_STEPLEN);
		return ret;
	}

	retries = MMA9553_CONFIG_RETRIES;
	do {
		mma9551_sleep(MMA9553_DEFAULT_SAMPLE_RATE);
		ret = mma9551_read_config_word(data->client,
					       MMA9551_APPID_PEDOMETER,
					       MMA9553_REG_CONF_CONF_STEPLEN,
					       &config);
		if (ret < 0)
			return ret;
	} while (mma9553_get_bits(config, MMA9553_MASK_CONF_CONFIG) &&
		 --retries > 0);

	return 0;
}

__attribute__((used)) static int mma9553_read_activity_stepcnt(struct mma9553_data *data,
					 u8 *activity, u16 *stepcnt)
{
	u16 buf[2];
	int ret;

	ret = mma9551_read_status_words(data->client, MMA9551_APPID_PEDOMETER,
					MMA9553_REG_STATUS, ARRAY_SIZE(buf),
					buf);
	if (ret < 0) {
		dev_err(&data->client->dev,
			"error reading status and stepcnt\n");
		return ret;
	}

	*activity = mma9553_get_bits(buf[0], MMA9553_MASK_STATUS_ACTIVITY);
	*stepcnt = buf[1];

	return 0;
}

__attribute__((used)) static int mma9553_conf_gpio(struct mma9553_data *data)
{
	u8 bitnum = 0, appid = MMA9551_APPID_PEDOMETER;
	int ret;
	struct mma9553_event *ev_step_detect;
	bool activity_enabled;

	activity_enabled = mma9553_is_any_event_enabled(data, true,
							IIO_ACTIVITY);
	ev_step_detect = mma9553_get_event(data, IIO_STEPS, IIO_NO_MOD,
					   IIO_EV_DIR_NONE);

	/*
	 * If both step detector and activity are enabled, use the MRGFL bit.
	 * This bit is the logical OR of the SUSPCHG, STEPCHG, and ACTCHG flags.
	 */
	if (activity_enabled && ev_step_detect->enabled)
		bitnum = MMA9553_STATUS_TO_BITNUM(MMA9553_MASK_STATUS_MRGFL);
	else if (ev_step_detect->enabled)
		bitnum = MMA9553_STATUS_TO_BITNUM(MMA9553_MASK_STATUS_STEPCHG);
	else if (activity_enabled)
		bitnum = MMA9553_STATUS_TO_BITNUM(MMA9553_MASK_STATUS_ACTCHG);
	else			/* Reset */
		appid = MMA9551_APPID_NONE;

	if (data->gpio_bitnum == bitnum)
		return 0;

	/* Save initial values for activity and stepcnt */
	if (activity_enabled || ev_step_detect->enabled) {
		ret = mma9553_read_activity_stepcnt(data, &data->activity,
						    &data->stepcnt);
		if (ret < 0)
			return ret;
	}

	ret = mma9551_gpio_config(data->client, MMA9553_DEFAULT_GPIO_PIN, appid,
				  bitnum, MMA9553_DEFAULT_GPIO_POLARITY);
	if (ret < 0)
		return ret;
	data->gpio_bitnum = bitnum;

	return 0;
}

__attribute__((used)) static int mma9553_init(struct mma9553_data *data)
{
	int ret;

	ret = mma9551_read_version(data->client);
	if (ret)
		return ret;

	/*
	 * Read all the pedometer configuration registers. This is used as
	 * a device identification command to differentiate the MMA9553L
	 * from the MMA9550L.
	 */
	ret = mma9551_read_config_words(data->client, MMA9551_APPID_PEDOMETER,
					MMA9553_REG_CONF_SLEEPMIN,
					sizeof(data->conf) / sizeof(u16),
					(u16 *)&data->conf);
	if (ret < 0) {
		dev_err(&data->client->dev,
			"failed to read configuration registers\n");
		return ret;
	}

	/* Reset GPIO */
	data->gpio_bitnum = MMA9553_MAX_BITNUM;
	ret = mma9553_conf_gpio(data);
	if (ret < 0)
		return ret;

	ret = mma9551_app_reset(data->client, MMA9551_RSC_PED);
	if (ret < 0)
		return ret;

	/* Init config registers */
	data->conf.sleepmin = MMA9553_DEFAULT_SLEEPMIN;
	data->conf.sleepmax = MMA9553_DEFAULT_SLEEPMAX;
	data->conf.sleepthd = MMA9553_DEFAULT_SLEEPTHD;
	data->conf.config = mma9553_set_bits(data->conf.config, 1,
					     MMA9553_MASK_CONF_CONFIG);
	/*
	 * Clear the activity debounce counter when the activity level changes,
	 * so that the confidence level applies for any activity level.
	 */
	data->conf.config = mma9553_set_bits(data->conf.config, 1,
					     MMA9553_MASK_CONF_ACT_DBCNTM);
	ret = mma9551_write_config_words(data->client, MMA9551_APPID_PEDOMETER,
					 MMA9553_REG_CONF_SLEEPMIN,
					 sizeof(data->conf) / sizeof(u16),
					 (u16 *)&data->conf);
	if (ret < 0) {
		dev_err(&data->client->dev,
			"failed to write configuration registers\n");
		return ret;
	}

	return mma9551_set_device_state(data->client, true);
}

__attribute__((used)) static int mma9553_read_status_word(struct mma9553_data *data, u16 reg,
				    u16 *tmp)
{
	bool powered_on;
	int ret;

	/*
	 * The HW only counts steps and other dependent
	 * parameters (speed, distance, calories, activity)
	 * if power is on (from enabling an event or the
	 * step counter).
	 */
	powered_on = mma9553_is_any_event_enabled(data, false, 0) ||
		     data->stepcnt_enabled;
	if (!powered_on) {
		dev_err(&data->client->dev, "No channels enabled\n");
		return -EINVAL;
	}

	mutex_lock(&data->mutex);
	ret = mma9551_read_status_word(data->client, MMA9551_APPID_PEDOMETER,
				       reg, tmp);
	mutex_unlock(&data->mutex);
	return ret;
}

__attribute__((used)) static int mma9553_read_raw(struct iio_dev *indio_dev,
			    struct iio_chan_spec const *chan,
			    int *val, int *val2, long mask)
{
	struct mma9553_data *data = iio_priv(indio_dev);
	int ret;
	u16 tmp;
	u8 activity;

	switch (mask) {
	case IIO_CHAN_INFO_PROCESSED:
		switch (chan->type) {
		case IIO_STEPS:
			ret = mma9553_read_status_word(data,
						       MMA9553_REG_STEPCNT,
						       &tmp);
			if (ret < 0)
				return ret;
			*val = tmp;
			return IIO_VAL_INT;
		case IIO_DISTANCE:
			ret = mma9553_read_status_word(data,
						       MMA9553_REG_DISTANCE,
						       &tmp);
			if (ret < 0)
				return ret;
			*val = tmp;
			return IIO_VAL_INT;
		case IIO_ACTIVITY:
			ret = mma9553_read_status_word(data,
						       MMA9553_REG_STATUS,
						       &tmp);
			if (ret < 0)
				return ret;

			activity =
			    mma9553_get_bits(tmp, MMA9553_MASK_STATUS_ACTIVITY);

			/*
			 * The device does not support confidence value levels,
			 * so we will always have 100% for current activity and
			 * 0% for the others.
			 */
			if (chan->channel2 == mma9553_activity_to_mod(activity))
				*val = 100;
			else
				*val = 0;
			return IIO_VAL_INT;
		default:
			return -EINVAL;
		}
	case IIO_CHAN_INFO_RAW:
		switch (chan->type) {
		case IIO_VELOCITY:	/* m/h */
			if (chan->channel2 != IIO_MOD_ROOT_SUM_SQUARED_X_Y_Z)
				return -EINVAL;
			ret = mma9553_read_status_word(data,
						       MMA9553_REG_SPEED,
						       &tmp);
			if (ret < 0)
				return ret;
			*val = tmp;
			return IIO_VAL_INT;
		case IIO_ENERGY:	/* Cal or kcal */
			ret = mma9553_read_status_word(data,
						       MMA9553_REG_CALORIES,
						       &tmp);
			if (ret < 0)
				return ret;
			*val = tmp;
			return IIO_VAL_INT;
		case IIO_ACCEL:
			mutex_lock(&data->mutex);
			ret = mma9551_read_accel_chan(data->client,
						      chan, val, val2);
			mutex_unlock(&data->mutex);
			return ret;
		default:
			return -EINVAL;
		}
	case IIO_CHAN_INFO_SCALE:
		switch (chan->type) {
		case IIO_VELOCITY:	/* m/h to m/s */
			if (chan->channel2 != IIO_MOD_ROOT_SUM_SQUARED_X_Y_Z)
				return -EINVAL;
			*val = 0;
			*val2 = 277;	/* 0.000277 */
			return IIO_VAL_INT_PLUS_MICRO;
		case IIO_ENERGY:	/* Cal or kcal to J */
			*val = 4184;
			return IIO_VAL_INT;
		case IIO_ACCEL:
			return mma9551_read_accel_scale(val, val2);
		default:
			return -EINVAL;
		}
	case IIO_CHAN_INFO_ENABLE:
		*val = data->stepcnt_enabled;
		return IIO_VAL_INT;
	case IIO_CHAN_INFO_CALIBHEIGHT:
		tmp = mma9553_get_bits(data->conf.height_weight,
				       MMA9553_MASK_CONF_HEIGHT);
		*val = tmp / 100;	/* cm to m */
		*val2 = (tmp % 100) * 10000;
		return IIO_VAL_INT_PLUS_MICRO;
	case IIO_CHAN_INFO_CALIBWEIGHT:
		*val = mma9553_get_bits(data->conf.height_weight,
					MMA9553_MASK_CONF_WEIGHT);
		return IIO_VAL_INT;
	case IIO_CHAN_INFO_DEBOUNCE_COUNT:
		switch (chan->type) {
		case IIO_STEPS:
			*val = mma9553_get_bits(data->conf.filter,
						MMA9553_MASK_CONF_FILTSTEP);
			return IIO_VAL_INT;
		default:
			return -EINVAL;
		}
	case IIO_CHAN_INFO_DEBOUNCE_TIME:
		switch (chan->type) {
		case IIO_STEPS:
			*val = mma9553_get_bits(data->conf.filter,
						MMA9553_MASK_CONF_FILTTIME);
			return IIO_VAL_INT;
		default:
			return -EINVAL;
		}
	case IIO_CHAN_INFO_INT_TIME:
		switch (chan->type) {
		case IIO_VELOCITY:
			if (chan->channel2 != IIO_MOD_ROOT_SUM_SQUARED_X_Y_Z)
				return -EINVAL;
			*val = mma9553_get_bits(data->conf.speed_step,
						MMA9553_MASK_CONF_SPDPRD);
			return IIO_VAL_INT;
		default:
			return -EINVAL;
		}
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int mma9553_write_raw(struct iio_dev *indio_dev,
			     struct iio_chan_spec const *chan,
			     int val, int val2, long mask)
{
	struct mma9553_data *data = iio_priv(indio_dev);
	int ret, tmp;

	switch (mask) {
	case IIO_CHAN_INFO_ENABLE:
		if (data->stepcnt_enabled == !!val)
			return 0;
		mutex_lock(&data->mutex);
		ret = mma9551_set_power_state(data->client, val);
		if (ret < 0) {
			mutex_unlock(&data->mutex);
			return ret;
		}
		data->stepcnt_enabled = val;
		mutex_unlock(&data->mutex);
		return 0;
	case IIO_CHAN_INFO_CALIBHEIGHT:
		/* m to cm */
		tmp = val * 100 + val2 / 10000;
		if (tmp < 0 || tmp > 255)
			return -EINVAL;
		mutex_lock(&data->mutex);
		ret = mma9553_set_config(data,
					 MMA9553_REG_CONF_HEIGHT_WEIGHT,
					 &data->conf.height_weight,
					 tmp, MMA9553_MASK_CONF_HEIGHT);
		mutex_unlock(&data->mutex);
		return ret;
	case IIO_CHAN_INFO_CALIBWEIGHT:
		if (val < 0 || val > 255)
			return -EINVAL;
		mutex_lock(&data->mutex);
		ret = mma9553_set_config(data,
					 MMA9553_REG_CONF_HEIGHT_WEIGHT,
					 &data->conf.height_weight,
					 val, MMA9553_MASK_CONF_WEIGHT);
		mutex_unlock(&data->mutex);
		return ret;
	case IIO_CHAN_INFO_DEBOUNCE_COUNT:
		switch (chan->type) {
		case IIO_STEPS:
			/*
			 * Set to 0 to disable step filtering. If the value
			 * specified is greater than 6, then 6 will be used.
			 */
			if (val < 0)
				return -EINVAL;
			if (val > 6)
				val = 6;
			mutex_lock(&data->mutex);
			ret = mma9553_set_config(data, MMA9553_REG_CONF_FILTER,
						 &data->conf.filter, val,
						 MMA9553_MASK_CONF_FILTSTEP);
			mutex_unlock(&data->mutex);
			return ret;
		default:
			return -EINVAL;
		}
	case IIO_CHAN_INFO_DEBOUNCE_TIME:
		switch (chan->type) {
		case IIO_STEPS:
			if (val < 0 || val > 127)
				return -EINVAL;
			mutex_lock(&data->mutex);
			ret = mma9553_set_config(data, MMA9553_REG_CONF_FILTER,
						 &data->conf.filter, val,
						 MMA9553_MASK_CONF_FILTTIME);
			mutex_unlock(&data->mutex);
			return ret;
		default:
			return -EINVAL;
		}
	case IIO_CHAN_INFO_INT_TIME:
		switch (chan->type) {
		case IIO_VELOCITY:
			if (chan->channel2 != IIO_MOD_ROOT_SUM_SQUARED_X_Y_Z)
				return -EINVAL;
			/*
			 * If set to a value greater than 5, then 5 will be
			 * used. Warning: Do not set SPDPRD to 0 or 1 as
			 * this may cause undesirable behavior.
			 */
			if (val < 2)
				return -EINVAL;
			if (val > 5)
				val = 5;
			mutex_lock(&data->mutex);
			ret = mma9553_set_config(data,
						 MMA9553_REG_CONF_SPEED_STEP,
						 &data->conf.speed_step, val,
						 MMA9553_MASK_CONF_SPDPRD);
			mutex_unlock(&data->mutex);
			return ret;
		default:
			return -EINVAL;
		}
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int mma9553_read_event_config(struct iio_dev *indio_dev,
				     const struct iio_chan_spec *chan,
				     enum iio_event_type type,
				     enum iio_event_direction dir)
{
	struct mma9553_data *data = iio_priv(indio_dev);
	struct mma9553_event *event;

	event = mma9553_get_event(data, chan->type, chan->channel2, dir);
	if (!event)
		return -EINVAL;

	return event->enabled;
}

__attribute__((used)) static int mma9553_write_event_config(struct iio_dev *indio_dev,
				      const struct iio_chan_spec *chan,
				      enum iio_event_type type,
				      enum iio_event_direction dir, int state)
{
	struct mma9553_data *data = iio_priv(indio_dev);
	struct mma9553_event *event;
	int ret;

	event = mma9553_get_event(data, chan->type, chan->channel2, dir);
	if (!event)
		return -EINVAL;

	if (event->enabled == state)
		return 0;

	mutex_lock(&data->mutex);

	ret = mma9551_set_power_state(data->client, state);
	if (ret < 0)
		goto err_out;
	event->enabled = state;

	ret = mma9553_conf_gpio(data);
	if (ret < 0)
		goto err_conf_gpio;

	mutex_unlock(&data->mutex);

	return 0;

err_conf_gpio:
	if (state) {
		event->enabled = false;
		mma9551_set_power_state(data->client, false);
	}
err_out:
	mutex_unlock(&data->mutex);
	return ret;
}

__attribute__((used)) static int mma9553_read_event_value(struct iio_dev *indio_dev,
				    const struct iio_chan_spec *chan,
				    enum iio_event_type type,
				    enum iio_event_direction dir,
				    enum iio_event_info info,
				    int *val, int *val2)
{
	struct mma9553_data *data = iio_priv(indio_dev);

	*val2 = 0;
	switch (info) {
	case IIO_EV_INFO_VALUE:
		switch (chan->type) {
		case IIO_STEPS:
			*val = mma9553_get_bits(data->conf.speed_step,
						MMA9553_MASK_CONF_STEPCOALESCE);
			return IIO_VAL_INT;
		case IIO_ACTIVITY:
			/*
			 * The device does not support confidence value levels.
			 * We set an average of 50%.
			 */
			*val = 50;
			return IIO_VAL_INT;
		default:
			return -EINVAL;
		}
	case IIO_EV_INFO_PERIOD:
		switch (chan->type) {
		case IIO_ACTIVITY:
			*val = MMA9553_ACTIVITY_THD_TO_SEC(data->conf.actthd);
			return IIO_VAL_INT;
		default:
			return -EINVAL;
		}
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int mma9553_write_event_value(struct iio_dev *indio_dev,
				     const struct iio_chan_spec *chan,
				     enum iio_event_type type,
				     enum iio_event_direction dir,
				     enum iio_event_info info,
				     int val, int val2)
{
	struct mma9553_data *data = iio_priv(indio_dev);
	int ret;

	switch (info) {
	case IIO_EV_INFO_VALUE:
		switch (chan->type) {
		case IIO_STEPS:
			if (val < 0 || val > 255)
				return -EINVAL;
			mutex_lock(&data->mutex);
			ret = mma9553_set_config(data,
						MMA9553_REG_CONF_SPEED_STEP,
						&data->conf.speed_step, val,
						MMA9553_MASK_CONF_STEPCOALESCE);
			mutex_unlock(&data->mutex);
			return ret;
		default:
			return -EINVAL;
		}
	case IIO_EV_INFO_PERIOD:
		switch (chan->type) {
		case IIO_ACTIVITY:
			if (val < 0 || val > MMA9553_ACTIVITY_THD_TO_SEC(
			    MMA9553_MAX_ACTTHD))
				return -EINVAL;
			mutex_lock(&data->mutex);
			ret = mma9553_set_config(data, MMA9553_REG_CONF_ACTTHD,
						 &data->conf.actthd,
						 MMA9553_ACTIVITY_SEC_TO_THD
						 (val), MMA9553_MASK_CONF_WORD);
			mutex_unlock(&data->mutex);
			return ret;
		default:
			return -EINVAL;
		}
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int mma9553_get_calibgender_mode(struct iio_dev *indio_dev,
					const struct iio_chan_spec *chan)
{
	struct mma9553_data *data = iio_priv(indio_dev);
	u8 gender;

	gender = mma9553_get_bits(data->conf.filter, MMA9553_MASK_CONF_MALE);
	/*
	 * HW expects 0 for female and 1 for male,
	 * while iio index is 0 for male and 1 for female.
	 */
	return !gender;
}

__attribute__((used)) static int mma9553_set_calibgender_mode(struct iio_dev *indio_dev,
					const struct iio_chan_spec *chan,
					unsigned int mode)
{
	struct mma9553_data *data = iio_priv(indio_dev);
	u8 gender = !mode;
	int ret;

	if ((mode != 0) && (mode != 1))
		return -EINVAL;
	mutex_lock(&data->mutex);
	ret = mma9553_set_config(data, MMA9553_REG_CONF_FILTER,
				 &data->conf.filter, gender,
				 MMA9553_MASK_CONF_MALE);
	mutex_unlock(&data->mutex);

	return ret;
}

__attribute__((used)) static irqreturn_t mma9553_irq_handler(int irq, void *private)
{
	struct iio_dev *indio_dev = private;
	struct mma9553_data *data = iio_priv(indio_dev);

	data->timestamp = iio_get_time_ns(indio_dev);
	/*
	 * Since we only configure the interrupt pin when an
	 * event is enabled, we are sure we have at least
	 * one event enabled at this point.
	 */
	return IRQ_WAKE_THREAD;
}

__attribute__((used)) static irqreturn_t mma9553_event_handler(int irq, void *private)
{
	struct iio_dev *indio_dev = private;
	struct mma9553_data *data = iio_priv(indio_dev);
	u16 stepcnt;
	u8 activity;
	struct mma9553_event *ev_activity, *ev_prev_activity, *ev_step_detect;
	int ret;

	mutex_lock(&data->mutex);
	ret = mma9553_read_activity_stepcnt(data, &activity, &stepcnt);
	if (ret < 0) {
		mutex_unlock(&data->mutex);
		return IRQ_HANDLED;
	}

	ev_prev_activity = mma9553_get_event(data, IIO_ACTIVITY,
					     mma9553_activity_to_mod(
					     data->activity),
					     IIO_EV_DIR_FALLING);
	ev_activity = mma9553_get_event(data, IIO_ACTIVITY,
					mma9553_activity_to_mod(activity),
					IIO_EV_DIR_RISING);
	ev_step_detect = mma9553_get_event(data, IIO_STEPS, IIO_NO_MOD,
					   IIO_EV_DIR_NONE);

	if (ev_step_detect->enabled && (stepcnt != data->stepcnt)) {
		data->stepcnt = stepcnt;
		iio_push_event(indio_dev,
			       IIO_EVENT_CODE(IIO_STEPS, 0, IIO_NO_MOD,
					      IIO_EV_DIR_NONE,
					      IIO_EV_TYPE_CHANGE, 0, 0, 0),
			       data->timestamp);
	}

	if (activity != data->activity) {
		data->activity = activity;
		/* ev_activity can be NULL if activity == ACTIVITY_UNKNOWN */
		if (ev_prev_activity && ev_prev_activity->enabled)
			iio_push_event(indio_dev,
				       IIO_EVENT_CODE(IIO_ACTIVITY, 0,
						    ev_prev_activity->info->mod,
						    IIO_EV_DIR_FALLING,
						    IIO_EV_TYPE_THRESH, 0, 0,
						    0),
				       data->timestamp);

		if (ev_activity && ev_activity->enabled)
			iio_push_event(indio_dev,
				       IIO_EVENT_CODE(IIO_ACTIVITY, 0,
						      ev_activity->info->mod,
						      IIO_EV_DIR_RISING,
						      IIO_EV_TYPE_THRESH, 0, 0,
						      0),
				       data->timestamp);
	}
	mutex_unlock(&data->mutex);

	return IRQ_HANDLED;
}

__attribute__((used)) static const char *mma9553_match_acpi_device(struct device *dev)
{
	const struct acpi_device_id *id;

	id = acpi_match_device(dev->driver->acpi_match_table, dev);
	if (!id)
		return NULL;

	return dev_name(dev);
}

__attribute__((used)) static int mma9553_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	struct mma9553_data *data;
	struct iio_dev *indio_dev;
	const char *name = NULL;
	int ret;

	indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
	if (!indio_dev)
		return -ENOMEM;

	data = iio_priv(indio_dev);
	i2c_set_clientdata(client, indio_dev);
	data->client = client;

	if (id)
		name = id->name;
	else if (ACPI_HANDLE(&client->dev))
		name = mma9553_match_acpi_device(&client->dev);
	else
		return -ENOSYS;

	mutex_init(&data->mutex);
	mma9553_init_events(data);

	ret = mma9553_init(data);
	if (ret < 0)
		return ret;

	indio_dev->dev.parent = &client->dev;
	indio_dev->channels = mma9553_channels;
	indio_dev->num_channels = ARRAY_SIZE(mma9553_channels);
	indio_dev->name = name;
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->info = &mma9553_info;

	if (client->irq > 0) {
		ret = devm_request_threaded_irq(&client->dev, client->irq,
						mma9553_irq_handler,
						mma9553_event_handler,
						IRQF_TRIGGER_RISING,
						MMA9553_IRQ_NAME, indio_dev);
		if (ret < 0) {
			dev_err(&client->dev, "request irq %d failed\n",
				client->irq);
			goto out_poweroff;
		}
	}

	ret = pm_runtime_set_active(&client->dev);
	if (ret < 0)
		goto out_poweroff;

	pm_runtime_enable(&client->dev);
	pm_runtime_set_autosuspend_delay(&client->dev,
					 MMA9551_AUTO_SUSPEND_DELAY_MS);
	pm_runtime_use_autosuspend(&client->dev);

	ret = iio_device_register(indio_dev);
	if (ret < 0) {
		dev_err(&client->dev, "unable to register iio device\n");
		goto out_poweroff;
	}

	dev_dbg(&indio_dev->dev, "Registered device %s\n", name);
	return 0;

out_poweroff:
	mma9551_set_device_state(client, false);
	return ret;
}

__attribute__((used)) static int mma9553_remove(struct i2c_client *client)
{
	struct iio_dev *indio_dev = i2c_get_clientdata(client);
	struct mma9553_data *data = iio_priv(indio_dev);

	iio_device_unregister(indio_dev);

	pm_runtime_disable(&client->dev);
	pm_runtime_set_suspended(&client->dev);
	pm_runtime_put_noidle(&client->dev);

	mutex_lock(&data->mutex);
	mma9551_set_device_state(data->client, false);
	mutex_unlock(&data->mutex);

	return 0;
}

