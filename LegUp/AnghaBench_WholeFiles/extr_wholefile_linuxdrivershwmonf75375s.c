#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_6__ ;
typedef  struct TYPE_13__   TYPE_5__ ;
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u16 ;
struct i2c_device_id {scalar_t__ driver_data; } ;
struct TYPE_14__ {int /*<<< orphan*/  kobj; } ;
struct i2c_client {struct i2c_adapter* adapter; TYPE_6__ dev; } ;
struct i2c_board_info {int /*<<< orphan*/  type; } ;
struct i2c_adapter {int /*<<< orphan*/  dev; } ;
struct f75375s_platform_data {int* pwm_enable; unsigned long* pwm; } ;
struct f75375_data {scalar_t__ kind; int* pwm; int valid; int* temp_high; int* temp_max_hyst; int* fan_max; int* fan_min; int* fan_target; int* in_max; int* in_min; int fan_timer; int* temp11; int* fan; int* in; int* pwm_enable; unsigned long* pwm_mode; int /*<<< orphan*/  hwmon_dev; int /*<<< orphan*/  update_lock; void* last_updated; void* last_limits; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;
struct TYPE_9__ {int /*<<< orphan*/  attr; } ;
struct TYPE_13__ {TYPE_1__ dev_attr; } ;
struct TYPE_10__ {int /*<<< orphan*/  attr; } ;
struct TYPE_12__ {TYPE_2__ dev_attr; } ;
struct TYPE_11__ {int index; } ;

/* Variables and functions */
 int EINVAL ; 
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 int F75375_CHIP_ID ; 
 int F75375_FAN_CTRL_LINEAR (int) ; 
 void* F75375_REG_CONFIG1 ; 
 int F75375_REG_FAN (int) ; 
 int F75375_REG_FAN_EXP (int) ; 
 int F75375_REG_FAN_FULL (int) ; 
 int F75375_REG_FAN_MIN (int) ; 
 int F75375_REG_FAN_PWM_DUTY (int) ; 
 void* F75375_REG_FAN_TIMER ; 
 int F75375_REG_TEMP (int) ; 
 int F75375_REG_TEMP_HIGH (int) ; 
 int F75375_REG_TEMP_HYST (int) ; 
 int F75375_REG_VENDOR ; 
 int F75375_REG_VERSION ; 
 int F75375_REG_VOLT (int) ; 
 int F75375_REG_VOLT_HIGH (int) ; 
 int F75375_REG_VOLT_LOW (int) ; 
 int F75387_FAN_CTRL_LINEAR (int) ; 
 int F75387_FAN_DUTY_MODE (int) ; 
 int F75387_FAN_MANU_MODE (int) ; 
 int F75387_REG_TEMP11_LSB (int) ; 
 int FAN_CTRL_MODE (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HZ ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_BYTE_DATA ; 
 int /*<<< orphan*/  I2C_NAME_SIZE ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int S_IRUGO ; 
 int S_IWUSR ; 
 int TEMP11_FROM_REG (int) ; 
 int TEMP_FROM_REG (int) ; 
 unsigned long TEMP_TO_REG (unsigned long) ; 
 int VOLT_FROM_REG (int) ; 
 unsigned long VOLT_TO_REG (unsigned long) ; 
 int /*<<< orphan*/  WARN (int,char*,int) ; 
 void* clamp_val (unsigned long,int /*<<< orphan*/ ,int) ; 
 struct f75375s_platform_data* dev_get_platdata (TYPE_6__*) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,char const*,int) ; 
 struct f75375_data* devm_kzalloc (TYPE_6__*,int,int /*<<< orphan*/ ) ; 
 scalar_t__ f75373 ; 
 int /*<<< orphan*/  f75375_group ; 
 scalar_t__ f75387 ; 
 int /*<<< orphan*/  hwmon_device_register (TYPE_6__*) ; 
 int /*<<< orphan*/  hwmon_device_unregister (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int /*<<< orphan*/ ) ; 
 struct f75375_data* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct f75375_data*) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int,int) ; 
 void* jiffies ; 
 int kstrtoul (char const*,int,unsigned long*) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 TYPE_5__ sensor_dev_attr_pwm1_mode ; 
 TYPE_4__ sensor_dev_attr_pwm2_mode ; 
 int sprintf (char*,char*,int) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ ) ; 
 int sysfs_chmod_file (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int sysfs_create_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sysfs_remove_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ time_after (void*,void*) ; 
 struct i2c_client* to_i2c_client (struct device*) ; 
 TYPE_3__* to_sensor_dev_attr (struct device_attribute*) ; 

__attribute__((used)) static inline int f75375_read8(struct i2c_client *client, u8 reg)
{
	return i2c_smbus_read_byte_data(client, reg);
}

__attribute__((used)) static inline u16 f75375_read16(struct i2c_client *client, u8 reg)
{
	return (i2c_smbus_read_byte_data(client, reg) << 8)
		| i2c_smbus_read_byte_data(client, reg + 1);
}

__attribute__((used)) static inline void f75375_write8(struct i2c_client *client, u8 reg,
		u8 value)
{
	i2c_smbus_write_byte_data(client, reg, value);
}

__attribute__((used)) static inline void f75375_write16(struct i2c_client *client, u8 reg,
		u16 value)
{
	int err = i2c_smbus_write_byte_data(client, reg, (value >> 8));
	if (err)
		return;
	i2c_smbus_write_byte_data(client, reg + 1, (value & 0xFF));
}

__attribute__((used)) static void f75375_write_pwm(struct i2c_client *client, int nr)
{
	struct f75375_data *data = i2c_get_clientdata(client);
	if (data->kind == f75387)
		f75375_write16(client, F75375_REG_FAN_EXP(nr), data->pwm[nr]);
	else
		f75375_write8(client, F75375_REG_FAN_PWM_DUTY(nr),
			      data->pwm[nr]);
}

__attribute__((used)) static struct f75375_data *f75375_update_device(struct device *dev)
{
	struct i2c_client *client = to_i2c_client(dev);
	struct f75375_data *data = i2c_get_clientdata(client);
	int nr;

	mutex_lock(&data->update_lock);

	/* Limit registers cache is refreshed after 60 seconds */
	if (time_after(jiffies, data->last_limits + 60 * HZ)
		|| !data->valid) {
		for (nr = 0; nr < 2; nr++) {
			data->temp_high[nr] =
				f75375_read8(client, F75375_REG_TEMP_HIGH(nr));
			data->temp_max_hyst[nr] =
				f75375_read8(client, F75375_REG_TEMP_HYST(nr));
			data->fan_max[nr] =
				f75375_read16(client, F75375_REG_FAN_FULL(nr));
			data->fan_min[nr] =
				f75375_read16(client, F75375_REG_FAN_MIN(nr));
			data->fan_target[nr] =
				f75375_read16(client, F75375_REG_FAN_EXP(nr));
		}
		for (nr = 0; nr < 4; nr++) {
			data->in_max[nr] =
				f75375_read8(client, F75375_REG_VOLT_HIGH(nr));
			data->in_min[nr] =
				f75375_read8(client, F75375_REG_VOLT_LOW(nr));
		}
		data->fan_timer = f75375_read8(client, F75375_REG_FAN_TIMER);
		data->last_limits = jiffies;
	}

	/* Measurement registers cache is refreshed after 2 second */
	if (time_after(jiffies, data->last_updated + 2 * HZ)
		|| !data->valid) {
		for (nr = 0; nr < 2; nr++) {
			data->pwm[nr] =	f75375_read8(client,
				F75375_REG_FAN_PWM_DUTY(nr));
			/* assign MSB, therefore shift it by 8 bits */
			data->temp11[nr] =
				f75375_read8(client, F75375_REG_TEMP(nr)) << 8;
			if (data->kind == f75387)
				/* merge F75387's temperature LSB (11-bit) */
				data->temp11[nr] |=
					f75375_read8(client,
						     F75387_REG_TEMP11_LSB(nr));
			data->fan[nr] =
				f75375_read16(client, F75375_REG_FAN(nr));
		}
		for (nr = 0; nr < 4; nr++)
			data->in[nr] =
				f75375_read8(client, F75375_REG_VOLT(nr));

		data->last_updated = jiffies;
		data->valid = 1;
	}

	mutex_unlock(&data->update_lock);
	return data;
}

__attribute__((used)) static inline u16 rpm_from_reg(u16 reg)
{
	if (reg == 0 || reg == 0xffff)
		return 0;
	return 1500000 / reg;
}

__attribute__((used)) static inline u16 rpm_to_reg(int rpm)
{
	if (rpm < 367 || rpm > 0xffff)
		return 0xffff;
	return 1500000 / rpm;
}

__attribute__((used)) static bool duty_mode_enabled(u8 pwm_enable)
{
	switch (pwm_enable) {
	case 0: /* Manual, duty mode (full speed) */
	case 1: /* Manual, duty mode */
	case 4: /* Auto, duty mode */
		return true;
	case 2: /* Auto, speed mode */
	case 3: /* Manual, speed mode */
		return false;
	default:
		WARN(1, "Unexpected pwm_enable value %d\n", pwm_enable);
		return true;
	}
}

__attribute__((used)) static bool auto_mode_enabled(u8 pwm_enable)
{
	switch (pwm_enable) {
	case 0: /* Manual, duty mode (full speed) */
	case 1: /* Manual, duty mode */
	case 3: /* Manual, speed mode */
		return false;
	case 2: /* Auto, speed mode */
	case 4: /* Auto, duty mode */
		return true;
	default:
		WARN(1, "Unexpected pwm_enable value %d\n", pwm_enable);
		return false;
	}
}

__attribute__((used)) static ssize_t set_fan_min(struct device *dev, struct device_attribute *attr,
		const char *buf, size_t count)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct i2c_client *client = to_i2c_client(dev);
	struct f75375_data *data = i2c_get_clientdata(client);
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err < 0)
		return err;

	mutex_lock(&data->update_lock);
	data->fan_min[nr] = rpm_to_reg(val);
	f75375_write16(client, F75375_REG_FAN_MIN(nr), data->fan_min[nr]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t set_fan_target(struct device *dev, struct device_attribute *attr,
		const char *buf, size_t count)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct i2c_client *client = to_i2c_client(dev);
	struct f75375_data *data = i2c_get_clientdata(client);
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err < 0)
		return err;

	if (auto_mode_enabled(data->pwm_enable[nr]))
		return -EINVAL;
	if (data->kind == f75387 && duty_mode_enabled(data->pwm_enable[nr]))
		return -EINVAL;

	mutex_lock(&data->update_lock);
	data->fan_target[nr] = rpm_to_reg(val);
	f75375_write16(client, F75375_REG_FAN_EXP(nr), data->fan_target[nr]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t set_pwm(struct device *dev, struct device_attribute *attr,
		const char *buf, size_t count)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct i2c_client *client = to_i2c_client(dev);
	struct f75375_data *data = i2c_get_clientdata(client);
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err < 0)
		return err;

	if (auto_mode_enabled(data->pwm_enable[nr]) ||
	    !duty_mode_enabled(data->pwm_enable[nr]))
		return -EINVAL;

	mutex_lock(&data->update_lock);
	data->pwm[nr] = clamp_val(val, 0, 255);
	f75375_write_pwm(client, nr);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_pwm_enable(struct device *dev, struct device_attribute
		*attr, char *buf)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct f75375_data *data = f75375_update_device(dev);
	return sprintf(buf, "%d\n", data->pwm_enable[nr]);
}

__attribute__((used)) static int set_pwm_enable_direct(struct i2c_client *client, int nr, int val)
{
	struct f75375_data *data = i2c_get_clientdata(client);
	u8 fanmode;

	if (val < 0 || val > 4)
		return -EINVAL;

	fanmode = f75375_read8(client, F75375_REG_FAN_TIMER);
	if (data->kind == f75387) {
		/* For now, deny dangerous toggling of duty mode */
		if (duty_mode_enabled(data->pwm_enable[nr]) !=
				duty_mode_enabled(val))
			return -EOPNOTSUPP;
		/* clear each fanX_mode bit before setting them properly */
		fanmode &= ~(1 << F75387_FAN_DUTY_MODE(nr));
		fanmode &= ~(1 << F75387_FAN_MANU_MODE(nr));
		switch (val) {
		case 0: /* full speed */
			fanmode |= (1 << F75387_FAN_MANU_MODE(nr));
			fanmode |= (1 << F75387_FAN_DUTY_MODE(nr));
			data->pwm[nr] = 255;
			break;
		case 1: /* PWM */
			fanmode  |= (1 << F75387_FAN_MANU_MODE(nr));
			fanmode  |= (1 << F75387_FAN_DUTY_MODE(nr));
			break;
		case 2: /* Automatic, speed mode */
			break;
		case 3: /* fan speed */
			fanmode |= (1 << F75387_FAN_MANU_MODE(nr));
			break;
		case 4: /* Automatic, pwm */
			fanmode |= (1 << F75387_FAN_DUTY_MODE(nr));
			break;
		}
	} else {
		/* clear each fanX_mode bit before setting them properly */
		fanmode &= ~(3 << FAN_CTRL_MODE(nr));
		switch (val) {
		case 0: /* full speed */
			fanmode  |= (3 << FAN_CTRL_MODE(nr));
			data->pwm[nr] = 255;
			break;
		case 1: /* PWM */
			fanmode  |= (3 << FAN_CTRL_MODE(nr));
			break;
		case 2: /* AUTOMATIC*/
			fanmode  |= (1 << FAN_CTRL_MODE(nr));
			break;
		case 3: /* fan speed */
			break;
		case 4: /* Automatic pwm */
			return -EINVAL;
		}
	}

	f75375_write8(client, F75375_REG_FAN_TIMER, fanmode);
	data->pwm_enable[nr] = val;
	if (val == 0)
		f75375_write_pwm(client, nr);
	return 0;
}

__attribute__((used)) static ssize_t set_pwm_enable(struct device *dev, struct device_attribute *attr,
		const char *buf, size_t count)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct i2c_client *client = to_i2c_client(dev);
	struct f75375_data *data = i2c_get_clientdata(client);
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err < 0)
		return err;

	mutex_lock(&data->update_lock);
	err = set_pwm_enable_direct(client, nr, val);
	mutex_unlock(&data->update_lock);
	return err ? err : count;
}

__attribute__((used)) static ssize_t set_pwm_mode(struct device *dev, struct device_attribute *attr,
		const char *buf, size_t count)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct i2c_client *client = to_i2c_client(dev);
	struct f75375_data *data = i2c_get_clientdata(client);
	unsigned long val;
	int err;
	u8 conf;
	char reg, ctrl;

	err = kstrtoul(buf, 10, &val);
	if (err < 0)
		return err;

	if (!(val == 0 || val == 1))
		return -EINVAL;

	/* F75373 does not support DC (linear voltage) fan control mode */
	if (data->kind == f75373 && val == 0)
		return -EINVAL;

	/* take care for different registers */
	if (data->kind == f75387) {
		reg = F75375_REG_FAN_TIMER;
		ctrl = F75387_FAN_CTRL_LINEAR(nr);
	} else {
		reg = F75375_REG_CONFIG1;
		ctrl = F75375_FAN_CTRL_LINEAR(nr);
	}

	mutex_lock(&data->update_lock);
	conf = f75375_read8(client, reg);
	conf &= ~(1 << ctrl);

	if (val == 0)
		conf |= (1 << ctrl);

	f75375_write8(client, reg, conf);
	data->pwm_mode[nr] = val;
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_pwm(struct device *dev, struct device_attribute
		*attr, char *buf)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct f75375_data *data = f75375_update_device(dev);
	return sprintf(buf, "%d\n", data->pwm[nr]);
}

__attribute__((used)) static ssize_t show_pwm_mode(struct device *dev, struct device_attribute
		*attr, char *buf)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct f75375_data *data = f75375_update_device(dev);
	return sprintf(buf, "%d\n", data->pwm_mode[nr]);
}

__attribute__((used)) static ssize_t show_in(struct device *dev, struct device_attribute *attr,
		char *buf)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct f75375_data *data = f75375_update_device(dev);
	return sprintf(buf, "%d\n", VOLT_FROM_REG(data->in[nr]));
}

__attribute__((used)) static ssize_t show_in_max(struct device *dev, struct device_attribute *attr,
		char *buf)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct f75375_data *data = f75375_update_device(dev);
	return sprintf(buf, "%d\n", VOLT_FROM_REG(data->in_max[nr]));
}

__attribute__((used)) static ssize_t show_in_min(struct device *dev, struct device_attribute *attr,
		char *buf)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct f75375_data *data = f75375_update_device(dev);
	return sprintf(buf, "%d\n", VOLT_FROM_REG(data->in_min[nr]));
}

__attribute__((used)) static ssize_t set_in_max(struct device *dev, struct device_attribute *attr,
		const char *buf, size_t count)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct i2c_client *client = to_i2c_client(dev);
	struct f75375_data *data = i2c_get_clientdata(client);
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err < 0)
		return err;

	val = clamp_val(VOLT_TO_REG(val), 0, 0xff);
	mutex_lock(&data->update_lock);
	data->in_max[nr] = val;
	f75375_write8(client, F75375_REG_VOLT_HIGH(nr), data->in_max[nr]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t set_in_min(struct device *dev, struct device_attribute *attr,
		const char *buf, size_t count)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct i2c_client *client = to_i2c_client(dev);
	struct f75375_data *data = i2c_get_clientdata(client);
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err < 0)
		return err;

	val = clamp_val(VOLT_TO_REG(val), 0, 0xff);
	mutex_lock(&data->update_lock);
	data->in_min[nr] = val;
	f75375_write8(client, F75375_REG_VOLT_LOW(nr), data->in_min[nr]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_temp11(struct device *dev, struct device_attribute *attr,
		char *buf)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct f75375_data *data = f75375_update_device(dev);
	return sprintf(buf, "%d\n", TEMP11_FROM_REG(data->temp11[nr]));
}

__attribute__((used)) static ssize_t show_temp_max(struct device *dev, struct device_attribute *attr,
		char *buf)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct f75375_data *data = f75375_update_device(dev);
	return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp_high[nr]));
}

__attribute__((used)) static ssize_t show_temp_max_hyst(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct f75375_data *data = f75375_update_device(dev);
	return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp_max_hyst[nr]));
}

__attribute__((used)) static ssize_t set_temp_max(struct device *dev, struct device_attribute *attr,
		const char *buf, size_t count)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct i2c_client *client = to_i2c_client(dev);
	struct f75375_data *data = i2c_get_clientdata(client);
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err < 0)
		return err;

	val = clamp_val(TEMP_TO_REG(val), 0, 127);
	mutex_lock(&data->update_lock);
	data->temp_high[nr] = val;
	f75375_write8(client, F75375_REG_TEMP_HIGH(nr), data->temp_high[nr]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t set_temp_max_hyst(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct i2c_client *client = to_i2c_client(dev);
	struct f75375_data *data = i2c_get_clientdata(client);
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err < 0)
		return err;

	val = clamp_val(TEMP_TO_REG(val), 0, 127);
	mutex_lock(&data->update_lock);
	data->temp_max_hyst[nr] = val;
	f75375_write8(client, F75375_REG_TEMP_HYST(nr),
		data->temp_max_hyst[nr]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static void f75375_init(struct i2c_client *client, struct f75375_data *data,
		struct f75375s_platform_data *f75375s_pdata)
{
	int nr;

	if (!f75375s_pdata) {
		u8 conf, mode;
		int nr;

		conf = f75375_read8(client, F75375_REG_CONFIG1);
		mode = f75375_read8(client, F75375_REG_FAN_TIMER);
		for (nr = 0; nr < 2; nr++) {
			if (data->kind == f75387) {
				bool manu, duty;

				if (!(mode & (1 << F75387_FAN_CTRL_LINEAR(nr))))
					data->pwm_mode[nr] = 1;

				manu = ((mode >> F75387_FAN_MANU_MODE(nr)) & 1);
				duty = ((mode >> F75387_FAN_DUTY_MODE(nr)) & 1);
				if (!manu && duty)
					/* auto, pwm */
					data->pwm_enable[nr] = 4;
				else if (manu && !duty)
					/* manual, speed */
					data->pwm_enable[nr] = 3;
				else if (!manu && !duty)
					/* automatic, speed */
					data->pwm_enable[nr] = 2;
				else
					/* manual, pwm */
					data->pwm_enable[nr] = 1;
			} else {
				if (!(conf & (1 << F75375_FAN_CTRL_LINEAR(nr))))
					data->pwm_mode[nr] = 1;

				switch ((mode >> FAN_CTRL_MODE(nr)) & 3) {
				case 0:		/* speed */
					data->pwm_enable[nr] = 3;
					break;
				case 1:		/* automatic */
					data->pwm_enable[nr] = 2;
					break;
				default:	/* manual */
					data->pwm_enable[nr] = 1;
					break;
				}
			}
		}
		return;
	}

	set_pwm_enable_direct(client, 0, f75375s_pdata->pwm_enable[0]);
	set_pwm_enable_direct(client, 1, f75375s_pdata->pwm_enable[1]);
	for (nr = 0; nr < 2; nr++) {
		if (auto_mode_enabled(f75375s_pdata->pwm_enable[nr]) ||
		    !duty_mode_enabled(f75375s_pdata->pwm_enable[nr]))
			continue;
		data->pwm[nr] = clamp_val(f75375s_pdata->pwm[nr], 0, 255);
		f75375_write_pwm(client, nr);
	}

}

__attribute__((used)) static int f75375_probe(struct i2c_client *client,
		const struct i2c_device_id *id)
{
	struct f75375_data *data;
	struct f75375s_platform_data *f75375s_pdata =
			dev_get_platdata(&client->dev);
	int err;

	if (!i2c_check_functionality(client->adapter,
				I2C_FUNC_SMBUS_BYTE_DATA))
		return -EIO;
	data = devm_kzalloc(&client->dev, sizeof(struct f75375_data),
			    GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	i2c_set_clientdata(client, data);
	mutex_init(&data->update_lock);
	data->kind = id->driver_data;

	err = sysfs_create_group(&client->dev.kobj, &f75375_group);
	if (err)
		return err;

	if (data->kind != f75373) {
		err = sysfs_chmod_file(&client->dev.kobj,
			&sensor_dev_attr_pwm1_mode.dev_attr.attr,
			S_IRUGO | S_IWUSR);
		if (err)
			goto exit_remove;
		err = sysfs_chmod_file(&client->dev.kobj,
			&sensor_dev_attr_pwm2_mode.dev_attr.attr,
			S_IRUGO | S_IWUSR);
		if (err)
			goto exit_remove;
	}

	data->hwmon_dev = hwmon_device_register(&client->dev);
	if (IS_ERR(data->hwmon_dev)) {
		err = PTR_ERR(data->hwmon_dev);
		goto exit_remove;
	}

	f75375_init(client, data, f75375s_pdata);

	return 0;

exit_remove:
	sysfs_remove_group(&client->dev.kobj, &f75375_group);
	return err;
}

__attribute__((used)) static int f75375_remove(struct i2c_client *client)
{
	struct f75375_data *data = i2c_get_clientdata(client);
	hwmon_device_unregister(data->hwmon_dev);
	sysfs_remove_group(&client->dev.kobj, &f75375_group);
	return 0;
}

__attribute__((used)) static int f75375_detect(struct i2c_client *client,
			 struct i2c_board_info *info)
{
	struct i2c_adapter *adapter = client->adapter;
	u16 vendid, chipid;
	u8 version;
	const char *name;

	vendid = f75375_read16(client, F75375_REG_VENDOR);
	chipid = f75375_read16(client, F75375_CHIP_ID);
	if (vendid != 0x1934)
		return -ENODEV;

	if (chipid == 0x0306)
		name = "f75375";
	else if (chipid == 0x0204)
		name = "f75373";
	else if (chipid == 0x0410)
		name = "f75387";
	else
		return -ENODEV;

	version = f75375_read8(client, F75375_REG_VERSION);
	dev_info(&adapter->dev, "found %s version: %02X\n", name, version);
	strlcpy(info->type, name, I2C_NAME_SIZE);

	return 0;
}

