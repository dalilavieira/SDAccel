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
typedef  int u8 ;
struct w83791d_data {int beep_mask; int alarms; int* fan_min; int* fan_div; int* pwm; int* pwm_enable; int* temp_target; int* temp_tolerance; int* temp1; int** temp_add; int beep_enable; int vid; int vrm; int valid; int* in; int* in_max; int* in_min; int* fan; int /*<<< orphan*/  update_lock; scalar_t__ last_updated; TYPE_1__** lm75; int /*<<< orphan*/  hwmon_dev; } ;
struct sensor_device_attribute_2 {int nr; int index; } ;
struct sensor_device_attribute {int index; } ;
struct i2c_device_id {int dummy; } ;
struct device {int /*<<< orphan*/  kobj; } ;
struct i2c_client {int addr; struct device dev; struct i2c_adapter* adapter; } ;
struct i2c_board_info {int /*<<< orphan*/  type; } ;
struct i2c_adapter {int dummy; } ;
struct device_attribute {int dummy; } ;
typedef  int ssize_t ;
struct TYPE_2__ {int addr; } ;

/* Variables and functions */
 int BEEP_MASK_FROM_REG (int) ; 
 int BEEP_MASK_TO_REG (long) ; 
 int DIV_FROM_REG (int) ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 unsigned long FAN_FROM_REG (int,int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int GLOBAL_BEEP_ENABLE_MASK ; 
 int GLOBAL_BEEP_ENABLE_SHIFT ; 
 int HZ ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_BYTE_DATA ; 
 int /*<<< orphan*/  I2C_NAME_SIZE ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int NUMBER_OF_FANIN ; 
 int NUMBER_OF_PWM ; 
 int NUMBER_OF_VIN ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int TARGET_TEMP_TO_REG (long) ; 
 int TEMP1_FROM_REG (int) ; 
 int TEMP1_TO_REG (long) ; 
 int TEMP23_FROM_REG (int) ; 
 int TEMP23_TO_REG (long) ; 
 int TOL_TEMP_TO_REG (unsigned long) ; 
 int W83791D_REG_ALARM1 ; 
 int W83791D_REG_ALARM2 ; 
 int W83791D_REG_ALARM3 ; 
 int W83791D_REG_BANK ; 
 int W83791D_REG_BEEP_CONFIG ; 
 int* W83791D_REG_BEEP_CTRL ; 
 int W83791D_REG_CHIPMAN ; 
 int W83791D_REG_CONFIG ; 
 int W83791D_REG_DID_VID4 ; 
 int* W83791D_REG_FAN ; 
 int* W83791D_REG_FAN_CFG ; 
 int* W83791D_REG_FAN_DIV ; 
 int* W83791D_REG_FAN_MIN ; 
 int W83791D_REG_GPIO ; 
 int W83791D_REG_I2C_ADDR ; 
 int W83791D_REG_I2C_SUBADDR ; 
 int* W83791D_REG_IN ; 
 int* W83791D_REG_IN_MAX ; 
 int* W83791D_REG_IN_MIN ; 
 int* W83791D_REG_PWM ; 
 int* W83791D_REG_TEMP1 ; 
 int W83791D_REG_TEMP2_CONFIG ; 
 int W83791D_REG_TEMP3_CONFIG ; 
 int** W83791D_REG_TEMP_ADD ; 
 int* W83791D_REG_TEMP_TARGET ; 
 int* W83791D_REG_TEMP_TOL ; 
 int W83791D_REG_VBAT ; 
 int W83791D_REG_VID_FANDIV ; 
 int W83791D_REG_WCHIPID ; 
 int clamp_val (unsigned long,int,int) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,int) ; 
 struct w83791d_data* dev_get_drvdata (struct device*) ; 
 struct w83791d_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int* force_subclients ; 
 int /*<<< orphan*/  hwmon_device_register (struct device*) ; 
 int /*<<< orphan*/  hwmon_device_unregister (int /*<<< orphan*/ ) ; 
 int i2c_adapter_id (struct i2c_adapter*) ; 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int /*<<< orphan*/ ) ; 
 struct w83791d_data* i2c_get_clientdata (struct i2c_client*) ; 
 void* i2c_new_dummy (struct i2c_adapter*,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct w83791d_data*) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int,int) ; 
 int /*<<< orphan*/  i2c_unregister_device (TYPE_1__*) ; 
 scalar_t__ init ; 
 scalar_t__ jiffies ; 
 int kstrtol (char const*,int,long*) ; 
 int kstrtoul (char const*,int,unsigned long*) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 scalar_t__ reset ; 
 int sprintf (char*,char*,int) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int sysfs_create_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sysfs_remove_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ time_after (scalar_t__,scalar_t__) ; 
 struct i2c_client* to_i2c_client (struct device*) ; 
 struct sensor_device_attribute* to_sensor_dev_attr (struct device_attribute*) ; 
 struct sensor_device_attribute_2* to_sensor_dev_attr_2 (struct device_attribute*) ; 
 int vid_from_reg (int,int) ; 
 unsigned long vid_which_vrm () ; 
 int /*<<< orphan*/  w83791d_group ; 
 int /*<<< orphan*/  w83791d_group_fanpwm45 ; 
static  void w83791d_init_client (struct i2c_client*) ; 
static  struct w83791d_data* w83791d_update_device (struct device*) ; 

__attribute__((used)) static inline int w83791d_read(struct i2c_client *client, u8 reg)
{
	return i2c_smbus_read_byte_data(client, reg);
}

__attribute__((used)) static inline int w83791d_write(struct i2c_client *client, u8 reg, u8 value)
{
	return i2c_smbus_write_byte_data(client, reg, value);
}

__attribute__((used)) static u8 fan_to_reg(long rpm, int div)
{
	if (rpm == 0)
		return 255;
	rpm = clamp_val(rpm, 1, 1000000);
	return clamp_val((1350000 + rpm * div / 2) / (rpm * div), 1, 254);
}

__attribute__((used)) static u8 div_to_reg(int nr, long val)
{
	int i;

	/* fan divisors max out at 128 */
	val = clamp_val(val, 1, 128) >> 1;
	for (i = 0; i < 7; i++) {
		if (val == 0)
			break;
		val >>= 1;
	}
	return (u8) i;
}

__attribute__((used)) static ssize_t show_beep(struct device *dev, struct device_attribute *attr,
			char *buf)
{
	struct sensor_device_attribute *sensor_attr =
						to_sensor_dev_attr(attr);
	struct w83791d_data *data = w83791d_update_device(dev);
	int bitnr = sensor_attr->index;

	return sprintf(buf, "%d\n", (data->beep_mask >> bitnr) & 1);
}

__attribute__((used)) static ssize_t store_beep(struct device *dev, struct device_attribute *attr,
			const char *buf, size_t count)
{
	struct sensor_device_attribute *sensor_attr =
						to_sensor_dev_attr(attr);
	struct i2c_client *client = to_i2c_client(dev);
	struct w83791d_data *data = i2c_get_clientdata(client);
	int bitnr = sensor_attr->index;
	int bytenr = bitnr / 8;
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	val = val ? 1 : 0;

	mutex_lock(&data->update_lock);

	data->beep_mask &= ~(0xff << (bytenr * 8));
	data->beep_mask |= w83791d_read(client, W83791D_REG_BEEP_CTRL[bytenr])
		<< (bytenr * 8);

	data->beep_mask &= ~(1 << bitnr);
	data->beep_mask |= val << bitnr;

	w83791d_write(client, W83791D_REG_BEEP_CTRL[bytenr],
		(data->beep_mask >> (bytenr * 8)) & 0xff);

	mutex_unlock(&data->update_lock);

	return count;
}

__attribute__((used)) static ssize_t show_alarm(struct device *dev, struct device_attribute *attr,
			char *buf)
{
	struct sensor_device_attribute *sensor_attr =
						to_sensor_dev_attr(attr);
	struct w83791d_data *data = w83791d_update_device(dev);
	int bitnr = sensor_attr->index;

	return sprintf(buf, "%d\n", (data->alarms >> bitnr) & 1);
}

__attribute__((used)) static ssize_t store_fan_min(struct device *dev, struct device_attribute *attr,
				const char *buf, size_t count)
{
	struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
	struct i2c_client *client = to_i2c_client(dev);
	struct w83791d_data *data = i2c_get_clientdata(client);
	int nr = sensor_attr->index;
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	data->fan_min[nr] = fan_to_reg(val, DIV_FROM_REG(data->fan_div[nr]));
	w83791d_write(client, W83791D_REG_FAN_MIN[nr], data->fan_min[nr]);
	mutex_unlock(&data->update_lock);

	return count;
}

__attribute__((used)) static ssize_t show_fan_div(struct device *dev, struct device_attribute *attr,
				char *buf)
{
	struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
	int nr = sensor_attr->index;
	struct w83791d_data *data = w83791d_update_device(dev);
	return sprintf(buf, "%u\n", DIV_FROM_REG(data->fan_div[nr]));
}

__attribute__((used)) static ssize_t store_fan_div(struct device *dev, struct device_attribute *attr,
				const char *buf, size_t count)
{
	struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
	struct i2c_client *client = to_i2c_client(dev);
	struct w83791d_data *data = i2c_get_clientdata(client);
	int nr = sensor_attr->index;
	unsigned long min;
	u8 tmp_fan_div;
	u8 fan_div_reg;
	u8 vbat_reg;
	int indx = 0;
	u8 keep_mask = 0;
	u8 new_shift = 0;
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	/* Save fan_min */
	min = FAN_FROM_REG(data->fan_min[nr], DIV_FROM_REG(data->fan_div[nr]));

	mutex_lock(&data->update_lock);
	data->fan_div[nr] = div_to_reg(nr, val);

	switch (nr) {
	case 0:
		indx = 0;
		keep_mask = 0xcf;
		new_shift = 4;
		break;
	case 1:
		indx = 0;
		keep_mask = 0x3f;
		new_shift = 6;
		break;
	case 2:
		indx = 1;
		keep_mask = 0x3f;
		new_shift = 6;
		break;
	case 3:
		indx = 2;
		keep_mask = 0xf8;
		new_shift = 0;
		break;
	case 4:
		indx = 2;
		keep_mask = 0x8f;
		new_shift = 4;
		break;
#ifdef DEBUG
	default:
		dev_warn(dev, "store_fan_div: Unexpected nr seen: %d\n", nr);
		count = -EINVAL;
		goto err_exit;
#endif
	}

	fan_div_reg = w83791d_read(client, W83791D_REG_FAN_DIV[indx])
			& keep_mask;
	tmp_fan_div = (data->fan_div[nr] << new_shift) & ~keep_mask;

	w83791d_write(client, W83791D_REG_FAN_DIV[indx],
				fan_div_reg | tmp_fan_div);

	/* Bit 2 of fans 0-2 is stored in the vbat register (bits 5-7) */
	if (nr < 3) {
		keep_mask = ~(1 << (nr + 5));
		vbat_reg = w83791d_read(client, W83791D_REG_VBAT)
				& keep_mask;
		tmp_fan_div = (data->fan_div[nr] << (3 + nr)) & ~keep_mask;
		w83791d_write(client, W83791D_REG_VBAT,
				vbat_reg | tmp_fan_div);
	}

	/* Restore fan_min */
	data->fan_min[nr] = fan_to_reg(min, DIV_FROM_REG(data->fan_div[nr]));
	w83791d_write(client, W83791D_REG_FAN_MIN[nr], data->fan_min[nr]);

#ifdef DEBUG
err_exit:
#endif
	mutex_unlock(&data->update_lock);

	return count;
}

__attribute__((used)) static ssize_t show_pwm(struct device *dev, struct device_attribute *attr,
				char *buf)
{
	struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
	int nr = sensor_attr->index;
	struct w83791d_data *data = w83791d_update_device(dev);
	return sprintf(buf, "%u\n", data->pwm[nr]);
}

__attribute__((used)) static ssize_t store_pwm(struct device *dev, struct device_attribute *attr,
		const char *buf, size_t count)
{
	struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
	struct i2c_client *client = to_i2c_client(dev);
	struct w83791d_data *data = i2c_get_clientdata(client);
	int nr = sensor_attr->index;
	unsigned long val;

	if (kstrtoul(buf, 10, &val))
		return -EINVAL;

	mutex_lock(&data->update_lock);
	data->pwm[nr] = clamp_val(val, 0, 255);
	w83791d_write(client, W83791D_REG_PWM[nr], data->pwm[nr]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_pwmenable(struct device *dev, struct device_attribute *attr,
				char *buf)
{
	struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
	int nr = sensor_attr->index;
	struct w83791d_data *data = w83791d_update_device(dev);
	return sprintf(buf, "%u\n", data->pwm_enable[nr] + 1);
}

__attribute__((used)) static ssize_t store_pwmenable(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t count)
{
	struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
	struct i2c_client *client = to_i2c_client(dev);
	struct w83791d_data *data = i2c_get_clientdata(client);
	int nr = sensor_attr->index;
	unsigned long val;
	u8 reg_cfg_tmp;
	u8 reg_idx = 0;
	u8 val_shift = 0;
	u8 keep_mask = 0;

	int ret = kstrtoul(buf, 10, &val);

	if (ret || val < 1 || val > 3)
		return -EINVAL;

	mutex_lock(&data->update_lock);
	data->pwm_enable[nr] = val - 1;
	switch (nr) {
	case 0:
		reg_idx = 0;
		val_shift = 2;
		keep_mask = 0xf3;
		break;
	case 1:
		reg_idx = 0;
		val_shift = 4;
		keep_mask = 0xcf;
		break;
	case 2:
		reg_idx = 1;
		val_shift = 2;
		keep_mask = 0xf3;
		break;
	}

	reg_cfg_tmp = w83791d_read(client, W83791D_REG_FAN_CFG[reg_idx]);
	reg_cfg_tmp = (reg_cfg_tmp & keep_mask) |
					data->pwm_enable[nr] << val_shift;

	w83791d_write(client, W83791D_REG_FAN_CFG[reg_idx], reg_cfg_tmp);
	mutex_unlock(&data->update_lock);

	return count;
}

__attribute__((used)) static ssize_t show_temp_target(struct device *dev,
			struct device_attribute *attr, char *buf)
{
	struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
	struct w83791d_data *data = w83791d_update_device(dev);
	int nr = sensor_attr->index;
	return sprintf(buf, "%d\n", TEMP1_FROM_REG(data->temp_target[nr]));
}

__attribute__((used)) static ssize_t store_temp_target(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t count)
{
	struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
	struct i2c_client *client = to_i2c_client(dev);
	struct w83791d_data *data = i2c_get_clientdata(client);
	int nr = sensor_attr->index;
	long val;
	u8 target_mask;

	if (kstrtol(buf, 10, &val))
		return -EINVAL;

	mutex_lock(&data->update_lock);
	data->temp_target[nr] = TARGET_TEMP_TO_REG(val);
	target_mask = w83791d_read(client,
				W83791D_REG_TEMP_TARGET[nr]) & 0x80;
	w83791d_write(client, W83791D_REG_TEMP_TARGET[nr],
				data->temp_target[nr] | target_mask);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_temp_tolerance(struct device *dev,
			struct device_attribute *attr, char *buf)
{
	struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
	struct w83791d_data *data = w83791d_update_device(dev);
	int nr = sensor_attr->index;
	return sprintf(buf, "%d\n", TEMP1_FROM_REG(data->temp_tolerance[nr]));
}

__attribute__((used)) static ssize_t store_temp_tolerance(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t count)
{
	struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
	struct i2c_client *client = to_i2c_client(dev);
	struct w83791d_data *data = i2c_get_clientdata(client);
	int nr = sensor_attr->index;
	unsigned long val;
	u8 target_mask;
	u8 reg_idx = 0;
	u8 val_shift = 0;
	u8 keep_mask = 0;

	if (kstrtoul(buf, 10, &val))
		return -EINVAL;

	switch (nr) {
	case 0:
		reg_idx = 0;
		val_shift = 0;
		keep_mask = 0xf0;
		break;
	case 1:
		reg_idx = 0;
		val_shift = 4;
		keep_mask = 0x0f;
		break;
	case 2:
		reg_idx = 1;
		val_shift = 0;
		keep_mask = 0xf0;
		break;
	}

	mutex_lock(&data->update_lock);
	data->temp_tolerance[nr] = TOL_TEMP_TO_REG(val);
	target_mask = w83791d_read(client,
			W83791D_REG_TEMP_TOL[reg_idx]) & keep_mask;
	w83791d_write(client, W83791D_REG_TEMP_TOL[reg_idx],
			(data->temp_tolerance[nr] << val_shift) | target_mask);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_temp1(struct device *dev, struct device_attribute *devattr,
				char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
	struct w83791d_data *data = w83791d_update_device(dev);
	return sprintf(buf, "%d\n", TEMP1_FROM_REG(data->temp1[attr->index]));
}

__attribute__((used)) static ssize_t store_temp1(struct device *dev, struct device_attribute *devattr,
				const char *buf, size_t count)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
	struct i2c_client *client = to_i2c_client(dev);
	struct w83791d_data *data = i2c_get_clientdata(client);
	int nr = attr->index;
	long val;
	int err;

	err = kstrtol(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	data->temp1[nr] = TEMP1_TO_REG(val);
	w83791d_write(client, W83791D_REG_TEMP1[nr], data->temp1[nr]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_temp23(struct device *dev, struct device_attribute *devattr,
				char *buf)
{
	struct sensor_device_attribute_2 *attr = to_sensor_dev_attr_2(devattr);
	struct w83791d_data *data = w83791d_update_device(dev);
	int nr = attr->nr;
	int index = attr->index;
	return sprintf(buf, "%d\n", TEMP23_FROM_REG(data->temp_add[nr][index]));
}

__attribute__((used)) static ssize_t store_temp23(struct device *dev,
				struct device_attribute *devattr,
				const char *buf, size_t count)
{
	struct sensor_device_attribute_2 *attr = to_sensor_dev_attr_2(devattr);
	struct i2c_client *client = to_i2c_client(dev);
	struct w83791d_data *data = i2c_get_clientdata(client);
	long val;
	int err;
	int nr = attr->nr;
	int index = attr->index;

	err = kstrtol(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	data->temp_add[nr][index] = TEMP23_TO_REG(val);
	w83791d_write(client, W83791D_REG_TEMP_ADD[nr][index * 2],
				data->temp_add[nr][index] >> 8);
	w83791d_write(client, W83791D_REG_TEMP_ADD[nr][index * 2 + 1],
				data->temp_add[nr][index] & 0x80);
	mutex_unlock(&data->update_lock);

	return count;
}

__attribute__((used)) static ssize_t alarms_show(struct device *dev, struct device_attribute *attr,
			   char *buf)
{
	struct w83791d_data *data = w83791d_update_device(dev);
	return sprintf(buf, "%u\n", data->alarms);
}

__attribute__((used)) static ssize_t show_beep_enable(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	struct w83791d_data *data = w83791d_update_device(dev);
	return sprintf(buf, "%d\n", data->beep_enable);
}

__attribute__((used)) static ssize_t show_beep_mask(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	struct w83791d_data *data = w83791d_update_device(dev);
	return sprintf(buf, "%d\n", BEEP_MASK_FROM_REG(data->beep_mask));
}

__attribute__((used)) static ssize_t store_beep_mask(struct device *dev,
				struct device_attribute *attr,
				const char *buf, size_t count)
{
	struct i2c_client *client = to_i2c_client(dev);
	struct w83791d_data *data = i2c_get_clientdata(client);
	int i;
	long val;
	int err;

	err = kstrtol(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);

	/*
	 * The beep_enable state overrides any enabling request from
	 * the masks
	 */
	data->beep_mask = BEEP_MASK_TO_REG(val) & ~GLOBAL_BEEP_ENABLE_MASK;
	data->beep_mask |= (data->beep_enable << GLOBAL_BEEP_ENABLE_SHIFT);

	val = data->beep_mask;

	for (i = 0; i < 3; i++) {
		w83791d_write(client, W83791D_REG_BEEP_CTRL[i], (val & 0xff));
		val >>= 8;
	}

	mutex_unlock(&data->update_lock);

	return count;
}

__attribute__((used)) static ssize_t store_beep_enable(struct device *dev,
				struct device_attribute *attr,
				const char *buf, size_t count)
{
	struct i2c_client *client = to_i2c_client(dev);
	struct w83791d_data *data = i2c_get_clientdata(client);
	long val;
	int err;

	err = kstrtol(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);

	data->beep_enable = val ? 1 : 0;

	/* Keep the full mask value in sync with the current enable */
	data->beep_mask &= ~GLOBAL_BEEP_ENABLE_MASK;
	data->beep_mask |= (data->beep_enable << GLOBAL_BEEP_ENABLE_SHIFT);

	/*
	 * The global control is in the second beep control register
	 * so only need to update that register
	 */
	val = (data->beep_mask >> 8) & 0xff;

	w83791d_write(client, W83791D_REG_BEEP_CTRL[1], val);

	mutex_unlock(&data->update_lock);

	return count;
}

__attribute__((used)) static ssize_t cpu0_vid_show(struct device *dev,
			     struct device_attribute *attr, char *buf)
{
	struct w83791d_data *data = w83791d_update_device(dev);
	return sprintf(buf, "%d\n", vid_from_reg(data->vid, data->vrm));
}

__attribute__((used)) static ssize_t vrm_show(struct device *dev, struct device_attribute *attr,
			char *buf)
{
	struct w83791d_data *data = dev_get_drvdata(dev);
	return sprintf(buf, "%d\n", data->vrm);
}

__attribute__((used)) static ssize_t vrm_store(struct device *dev, struct device_attribute *attr,
			 const char *buf, size_t count)
{
	struct w83791d_data *data = dev_get_drvdata(dev);
	unsigned long val;
	int err;

	/*
	 * No lock needed as vrm is internal to the driver
	 * (not read from a chip register) and so is not
	 * updated in w83791d_update_device()
	 */

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	if (val > 255)
		return -EINVAL;

	data->vrm = val;
	return count;
}

__attribute__((used)) static int w83791d_detect_subclients(struct i2c_client *client)
{
	struct i2c_adapter *adapter = client->adapter;
	struct w83791d_data *data = i2c_get_clientdata(client);
	int address = client->addr;
	int i, id, err;
	u8 val;

	id = i2c_adapter_id(adapter);
	if (force_subclients[0] == id && force_subclients[1] == address) {
		for (i = 2; i <= 3; i++) {
			if (force_subclients[i] < 0x48 ||
			    force_subclients[i] > 0x4f) {
				dev_err(&client->dev,
					"invalid subclient "
					"address %d; must be 0x48-0x4f\n",
					force_subclients[i]);
				err = -ENODEV;
				goto error_sc_0;
			}
		}
		w83791d_write(client, W83791D_REG_I2C_SUBADDR,
					(force_subclients[2] & 0x07) |
					((force_subclients[3] & 0x07) << 4));
	}

	val = w83791d_read(client, W83791D_REG_I2C_SUBADDR);
	if (!(val & 0x08))
		data->lm75[0] = i2c_new_dummy(adapter, 0x48 + (val & 0x7));
	if (!(val & 0x80)) {
		if ((data->lm75[0] != NULL) &&
				((val & 0x7) == ((val >> 4) & 0x7))) {
			dev_err(&client->dev,
				"duplicate addresses 0x%x, "
				"use force_subclient\n",
				data->lm75[0]->addr);
			err = -ENODEV;
			goto error_sc_1;
		}
		data->lm75[1] = i2c_new_dummy(adapter,
					      0x48 + ((val >> 4) & 0x7));
	}

	return 0;

/* Undo inits in case of errors */

error_sc_1:
	i2c_unregister_device(data->lm75[0]);
error_sc_0:
	return err;
}

__attribute__((used)) static int w83791d_detect(struct i2c_client *client,
			  struct i2c_board_info *info)
{
	struct i2c_adapter *adapter = client->adapter;
	int val1, val2;
	unsigned short address = client->addr;

	if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
		return -ENODEV;

	if (w83791d_read(client, W83791D_REG_CONFIG) & 0x80)
		return -ENODEV;

	val1 = w83791d_read(client, W83791D_REG_BANK);
	val2 = w83791d_read(client, W83791D_REG_CHIPMAN);
	/* Check for Winbond ID if in bank 0 */
	if (!(val1 & 0x07)) {
		if ((!(val1 & 0x80) && val2 != 0xa3) ||
		    ((val1 & 0x80) && val2 != 0x5c)) {
			return -ENODEV;
		}
	}
	/*
	 * If Winbond chip, address of chip and W83791D_REG_I2C_ADDR
	 * should match
	 */
	if (w83791d_read(client, W83791D_REG_I2C_ADDR) != address)
		return -ENODEV;

	/* We want bank 0 and Vendor ID high byte */
	val1 = w83791d_read(client, W83791D_REG_BANK) & 0x78;
	w83791d_write(client, W83791D_REG_BANK, val1 | 0x80);

	/* Verify it is a Winbond w83791d */
	val1 = w83791d_read(client, W83791D_REG_WCHIPID);
	val2 = w83791d_read(client, W83791D_REG_CHIPMAN);
	if (val1 != 0x71 || val2 != 0x5c)
		return -ENODEV;

	strlcpy(info->type, "w83791d", I2C_NAME_SIZE);

	return 0;
}

__attribute__((used)) static int w83791d_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	struct w83791d_data *data;
	struct device *dev = &client->dev;
	int i, err;
	u8 has_fanpwm45;

#ifdef DEBUG
	int val1;
	val1 = w83791d_read(client, W83791D_REG_DID_VID4);
	dev_dbg(dev, "Device ID version: %d.%d (0x%02x)\n",
			(val1 >> 5) & 0x07, (val1 >> 1) & 0x0f, val1);
#endif

	data = devm_kzalloc(&client->dev, sizeof(struct w83791d_data),
			    GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	i2c_set_clientdata(client, data);
	mutex_init(&data->update_lock);

	err = w83791d_detect_subclients(client);
	if (err)
		return err;

	/* Initialize the chip */
	w83791d_init_client(client);

	/*
	 * If the fan_div is changed, make sure there is a rational
	 * fan_min in place
	 */
	for (i = 0; i < NUMBER_OF_FANIN; i++)
		data->fan_min[i] = w83791d_read(client, W83791D_REG_FAN_MIN[i]);

	/* Register sysfs hooks */
	err = sysfs_create_group(&client->dev.kobj, &w83791d_group);
	if (err)
		goto error3;

	/* Check if pins of fan/pwm 4-5 are in use as GPIO */
	has_fanpwm45 = w83791d_read(client, W83791D_REG_GPIO) & 0x10;
	if (has_fanpwm45) {
		err = sysfs_create_group(&client->dev.kobj,
					 &w83791d_group_fanpwm45);
		if (err)
			goto error4;
	}

	/* Everything is ready, now register the working device */
	data->hwmon_dev = hwmon_device_register(dev);
	if (IS_ERR(data->hwmon_dev)) {
		err = PTR_ERR(data->hwmon_dev);
		goto error5;
	}

	return 0;

error5:
	if (has_fanpwm45)
		sysfs_remove_group(&client->dev.kobj, &w83791d_group_fanpwm45);
error4:
	sysfs_remove_group(&client->dev.kobj, &w83791d_group);
error3:
	i2c_unregister_device(data->lm75[0]);
	i2c_unregister_device(data->lm75[1]);
	return err;
}

__attribute__((used)) static int w83791d_remove(struct i2c_client *client)
{
	struct w83791d_data *data = i2c_get_clientdata(client);

	hwmon_device_unregister(data->hwmon_dev);
	sysfs_remove_group(&client->dev.kobj, &w83791d_group);

	i2c_unregister_device(data->lm75[0]);
	i2c_unregister_device(data->lm75[1]);

	return 0;
}

__attribute__((used)) static void w83791d_init_client(struct i2c_client *client)
{
	struct w83791d_data *data = i2c_get_clientdata(client);
	u8 tmp;
	u8 old_beep;

	/*
	 * The difference between reset and init is that reset
	 * does a hard reset of the chip via index 0x40, bit 7,
	 * but init simply forces certain registers to have "sane"
	 * values. The hope is that the BIOS has done the right
	 * thing (which is why the default is reset=0, init=0),
	 * but if not, reset is the hard hammer and init
	 * is the soft mallet both of which are trying to whack
	 * things into place...
	 * NOTE: The data sheet makes a distinction between
	 * "power on defaults" and "reset by MR". As far as I can tell,
	 * the hard reset puts everything into a power-on state so I'm
	 * not sure what "reset by MR" means or how it can happen.
	 */
	if (reset || init) {
		/* keep some BIOS settings when we... */
		old_beep = w83791d_read(client, W83791D_REG_BEEP_CONFIG);

		if (reset) {
			/* ... reset the chip and ... */
			w83791d_write(client, W83791D_REG_CONFIG, 0x80);
		}

		/* ... disable power-on abnormal beep */
		w83791d_write(client, W83791D_REG_BEEP_CONFIG, old_beep | 0x80);

		/* disable the global beep (not done by hard reset) */
		tmp = w83791d_read(client, W83791D_REG_BEEP_CTRL[1]);
		w83791d_write(client, W83791D_REG_BEEP_CTRL[1], tmp & 0xef);

		if (init) {
			/* Make sure monitoring is turned on for add-ons */
			tmp = w83791d_read(client, W83791D_REG_TEMP2_CONFIG);
			if (tmp & 1) {
				w83791d_write(client, W83791D_REG_TEMP2_CONFIG,
					tmp & 0xfe);
			}

			tmp = w83791d_read(client, W83791D_REG_TEMP3_CONFIG);
			if (tmp & 1) {
				w83791d_write(client, W83791D_REG_TEMP3_CONFIG,
					tmp & 0xfe);
			}

			/* Start monitoring */
			tmp = w83791d_read(client, W83791D_REG_CONFIG) & 0xf7;
			w83791d_write(client, W83791D_REG_CONFIG, tmp | 0x01);
		}
	}

	data->vrm = vid_which_vrm();
}

__attribute__((used)) static struct w83791d_data *w83791d_update_device(struct device *dev)
{
	struct i2c_client *client = to_i2c_client(dev);
	struct w83791d_data *data = i2c_get_clientdata(client);
	int i, j;
	u8 reg_array_tmp[3];
	u8 vbat_reg;

	mutex_lock(&data->update_lock);

	if (time_after(jiffies, data->last_updated + (HZ * 3))
			|| !data->valid) {
		dev_dbg(dev, "Starting w83791d device update\n");

		/* Update the voltages measured value and limits */
		for (i = 0; i < NUMBER_OF_VIN; i++) {
			data->in[i] = w83791d_read(client,
						W83791D_REG_IN[i]);
			data->in_max[i] = w83791d_read(client,
						W83791D_REG_IN_MAX[i]);
			data->in_min[i] = w83791d_read(client,
						W83791D_REG_IN_MIN[i]);
		}

		/* Update the fan counts and limits */
		for (i = 0; i < NUMBER_OF_FANIN; i++) {
			/* Update the Fan measured value and limits */
			data->fan[i] = w83791d_read(client,
						W83791D_REG_FAN[i]);
			data->fan_min[i] = w83791d_read(client,
						W83791D_REG_FAN_MIN[i]);
		}

		/* Update the fan divisor */
		for (i = 0; i < 3; i++) {
			reg_array_tmp[i] = w83791d_read(client,
						W83791D_REG_FAN_DIV[i]);
		}
		data->fan_div[0] = (reg_array_tmp[0] >> 4) & 0x03;
		data->fan_div[1] = (reg_array_tmp[0] >> 6) & 0x03;
		data->fan_div[2] = (reg_array_tmp[1] >> 6) & 0x03;
		data->fan_div[3] = reg_array_tmp[2] & 0x07;
		data->fan_div[4] = (reg_array_tmp[2] >> 4) & 0x07;

		/*
		 * The fan divisor for fans 0-2 get bit 2 from
		 * bits 5-7 respectively of vbat register
		 */
		vbat_reg = w83791d_read(client, W83791D_REG_VBAT);
		for (i = 0; i < 3; i++)
			data->fan_div[i] |= (vbat_reg >> (3 + i)) & 0x04;

		/* Update PWM duty cycle */
		for (i = 0; i < NUMBER_OF_PWM; i++) {
			data->pwm[i] =  w83791d_read(client,
						W83791D_REG_PWM[i]);
		}

		/* Update PWM enable status */
		for (i = 0; i < 2; i++) {
			reg_array_tmp[i] = w83791d_read(client,
						W83791D_REG_FAN_CFG[i]);
		}
		data->pwm_enable[0] = (reg_array_tmp[0] >> 2) & 0x03;
		data->pwm_enable[1] = (reg_array_tmp[0] >> 4) & 0x03;
		data->pwm_enable[2] = (reg_array_tmp[1] >> 2) & 0x03;

		/* Update PWM target temperature */
		for (i = 0; i < 3; i++) {
			data->temp_target[i] = w83791d_read(client,
				W83791D_REG_TEMP_TARGET[i]) & 0x7f;
		}

		/* Update PWM temperature tolerance */
		for (i = 0; i < 2; i++) {
			reg_array_tmp[i] = w83791d_read(client,
					W83791D_REG_TEMP_TOL[i]);
		}
		data->temp_tolerance[0] = reg_array_tmp[0] & 0x0f;
		data->temp_tolerance[1] = (reg_array_tmp[0] >> 4) & 0x0f;
		data->temp_tolerance[2] = reg_array_tmp[1] & 0x0f;

		/* Update the first temperature sensor */
		for (i = 0; i < 3; i++) {
			data->temp1[i] = w83791d_read(client,
						W83791D_REG_TEMP1[i]);
		}

		/* Update the rest of the temperature sensors */
		for (i = 0; i < 2; i++) {
			for (j = 0; j < 3; j++) {
				data->temp_add[i][j] =
					(w83791d_read(client,
					W83791D_REG_TEMP_ADD[i][j * 2]) << 8) |
					w83791d_read(client,
					W83791D_REG_TEMP_ADD[i][j * 2 + 1]);
			}
		}

		/* Update the realtime status */
		data->alarms =
			w83791d_read(client, W83791D_REG_ALARM1) +
			(w83791d_read(client, W83791D_REG_ALARM2) << 8) +
			(w83791d_read(client, W83791D_REG_ALARM3) << 16);

		/* Update the beep configuration information */
		data->beep_mask =
			w83791d_read(client, W83791D_REG_BEEP_CTRL[0]) +
			(w83791d_read(client, W83791D_REG_BEEP_CTRL[1]) << 8) +
			(w83791d_read(client, W83791D_REG_BEEP_CTRL[2]) << 16);

		/* Extract global beep enable flag */
		data->beep_enable =
			(data->beep_mask >> GLOBAL_BEEP_ENABLE_SHIFT) & 0x01;

		/* Update the cpu voltage information */
		i = w83791d_read(client, W83791D_REG_VID_FANDIV);
		data->vid = i & 0x0f;
		data->vid |= (w83791d_read(client, W83791D_REG_DID_VID4) & 0x01)
				<< 4;

		data->last_updated = jiffies;
		data->valid = 1;
	}

	mutex_unlock(&data->update_lock);

#ifdef DEBUG
	w83791d_print_debug(data, dev);
#endif

	return data;
}

