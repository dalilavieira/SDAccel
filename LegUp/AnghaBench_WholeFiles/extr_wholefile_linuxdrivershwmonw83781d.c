#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct w83781d_data {int* fan_min; int* fan_div; int vid; int vrm; int alarms; int type; int beep_mask; int* pwm; unsigned long pwm2_enable; unsigned long* sens; int valid; int* in; int* in_min; int* in_max; int* fan; int temp; int temp_max; int temp_max_hyst; int* temp_add; int* temp_max_add; int* temp_max_hyst_add; int /*<<< orphan*/  lock; int /*<<< orphan*/  update_lock; scalar_t__ last_updated; struct i2c_client* client; struct i2c_client** lm75; int /*<<< orphan*/  hwmon_dev; } ;
struct sensor_device_attribute {int index; } ;
struct i2c_device_id {int driver_data; } ;
struct device {int /*<<< orphan*/  kobj; } ;
struct i2c_client {int addr; struct device dev; struct i2c_adapter* adapter; } ;
struct i2c_board_info {int /*<<< orphan*/  type; } ;
struct i2c_adapter {struct device dev; } ;
struct device_attribute {int dummy; } ;
typedef  int ssize_t ;
typedef  int s16 ;
typedef  enum chips { ____Placeholder_chips } chips ;
struct TYPE_10__ {int /*<<< orphan*/  dev_attr; } ;
struct TYPE_9__ {int /*<<< orphan*/  dev_attr; } ;
struct TYPE_6__ {int /*<<< orphan*/  attr; } ;
struct TYPE_8__ {TYPE_1__ dev_attr; } ;
struct TYPE_7__ {int /*<<< orphan*/  dev_attr; } ;

/* Variables and functions */
 scalar_t__ BEEP_MASK_FROM_REG (int,int) ; 
 int BEEP_MASK_TO_REG (unsigned long,int) ; 
 int* BIT_SCFG1 ; 
 int* BIT_SCFG2 ; 
 int DIV_FROM_REG (int) ; 
 int EBUSY ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HZ ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_BYTE_DATA ; 
 int /*<<< orphan*/  I2C_NAME_SIZE ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int LM75_TEMP_MAX ; 
 int LM75_TEMP_MIN ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int S_IRUGO ; 
 int S_IWUSR ; 
#define  W83781D_DEFAULT_BETA 128 
 int W83781D_REG_ALARM1 ; 
 int W83781D_REG_ALARM2 ; 
 int W83781D_REG_BANK ; 
 int W83781D_REG_BEEP_CONFIG ; 
 int W83781D_REG_BEEP_INTS1 ; 
 int W83781D_REG_BEEP_INTS2 ; 
 int W83781D_REG_BEEP_INTS3 ; 
 int W83781D_REG_CHIPID ; 
 int W83781D_REG_CHIPMAN ; 
 int W83781D_REG_CONFIG ; 
 int W83781D_REG_FAN (int) ; 
 int W83781D_REG_FAN_MIN (int) ; 
 int W83781D_REG_I2C_ADDR ; 
 int W83781D_REG_I2C_SUBADDR ; 
 int W83781D_REG_IN (int) ; 
 int W83781D_REG_IN_MAX (int) ; 
 int W83781D_REG_IN_MIN (int) ; 
 int W83781D_REG_PIN ; 
 int* W83781D_REG_PWM ; 
 int W83781D_REG_PWMCLK12 ; 
 int W83781D_REG_SCFG1 ; 
 int W83781D_REG_SCFG2 ; 
 int W83781D_REG_TEMP (int) ; 
 int W83781D_REG_TEMP2_CONFIG ; 
 int W83781D_REG_TEMP3_CONFIG ; 
 int W83781D_REG_TEMP_HYST (int) ; 
 int W83781D_REG_TEMP_OVER (int) ; 
 int W83781D_REG_VBAT ; 
 int W83781D_REG_VID_FANDIV ; 
 int W83781D_REG_WCHIPID ; 
 int W83782D_REG_ALARM1 ; 
 int W83782D_REG_ALARM2 ; 
 int W83782D_REG_ALARM3 ; 
 int as99127f ; 
 int clamp_val (unsigned long,int,int) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,int,...) ; 
 struct w83781d_data* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*,...) ; 
 int device_create_file (struct device*,int /*<<< orphan*/ *) ; 
 struct w83781d_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int* force_subclients ; 
 int /*<<< orphan*/  hwmon_device_register (struct device*) ; 
 int /*<<< orphan*/  hwmon_device_unregister (int /*<<< orphan*/ ) ; 
 int i2c_adapter_id (struct i2c_adapter*) ; 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int /*<<< orphan*/ ) ; 
 struct w83781d_data* i2c_get_clientdata (struct i2c_client*) ; 
 struct i2c_client* i2c_new_dummy (struct i2c_adapter*,unsigned short) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct w83781d_data*) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int) ; 
 int i2c_smbus_read_word_swapped (struct i2c_client*,int) ; 
 int /*<<< orphan*/  i2c_smbus_write_byte_data (struct i2c_client*,int,int) ; 
 int /*<<< orphan*/  i2c_smbus_write_word_swapped (struct i2c_client*,int,int) ; 
 int /*<<< orphan*/  i2c_unregister_device (struct i2c_client*) ; 
 scalar_t__ init ; 
 scalar_t__ jiffies ; 
 int kstrtoul (char const*,int,unsigned long*) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 scalar_t__ reset ; 
 TYPE_5__ sensor_dev_attr_temp1_type ; 
 TYPE_4__ sensor_dev_attr_temp2_type ; 
 TYPE_3__ sensor_dev_attr_temp3_alarm ; 
 TYPE_2__ sensor_dev_attr_temp3_type ; 
 int sprintf (char*,char*,int) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ ) ; 
 int sysfs_chmod_file (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int sysfs_create_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sysfs_remove_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ time_after (scalar_t__,scalar_t__) ; 
 struct sensor_device_attribute* to_sensor_dev_attr (struct device_attribute*) ; 
 scalar_t__ vid_from_reg (int,int) ; 
 int vid_which_vrm () ; 
 int w83781d ; 
static  int w83781d_alias_detect (struct i2c_client*,int) ; 
static  struct w83781d_data* w83781d_data_if_isa () ; 
 int /*<<< orphan*/  w83781d_group ; 
 int /*<<< orphan*/  w83781d_group_in1 ; 
 int /*<<< orphan*/  w83781d_group_in78 ; 
 int /*<<< orphan*/  w83781d_group_other ; 
 int /*<<< orphan*/  w83781d_group_pwm12 ; 
 int /*<<< orphan*/  w83781d_group_pwm34 ; 
 int /*<<< orphan*/  w83781d_group_temp3 ; 
static  void w83781d_init_device (struct device*) ; 
static  int w83781d_read_value (struct w83781d_data*,int) ; 
static  struct w83781d_data* w83781d_update_device (struct device*) ; 
static  int w83781d_write_value (struct w83781d_data*,int,int) ; 
 int w83782d ; 
 int w83783s ; 

__attribute__((used)) static inline u16 LM75_TEMP_TO_REG(long temp)
{
	int ntemp = clamp_val(temp, LM75_TEMP_MIN, LM75_TEMP_MAX);
	ntemp += (ntemp < 0 ? -250 : 250);
	return (u16)((ntemp / 500) << 7);
}

__attribute__((used)) static inline int LM75_TEMP_FROM_REG(u16 reg)
{
	/* use integer division instead of equivalent right shift to
	   guarantee arithmetic shift and preserve the sign */
	return ((s16)reg / 128) * 500;
}

__attribute__((used)) static inline u8
FAN_TO_REG(long rpm, int div)
{
	if (rpm == 0)
		return 255;
	rpm = clamp_val(rpm, 1, 1000000);
	return clamp_val((1350000 + rpm * div / 2) / (rpm * div), 1, 254);
}

__attribute__((used)) static inline long
FAN_FROM_REG(u8 val, int div)
{
	if (val == 0)
		return -1;
	if (val == 255)
		return 0;
	return 1350000 / (val * div);
}

__attribute__((used)) static inline u8
DIV_TO_REG(long val, enum chips type)
{
	int i;
	val = clamp_val(val, 1,
			((type == w83781d || type == as99127f) ? 8 : 128)) >> 1;
	for (i = 0; i < 7; i++) {
		if (val == 0)
			break;
		val >>= 1;
	}
	return i;
}

__attribute__((used)) static ssize_t
store_fan_min(struct device *dev, struct device_attribute *da,
		const char *buf, size_t count)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
	struct w83781d_data *data = dev_get_drvdata(dev);
	int nr = attr->index;
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	data->fan_min[nr] =
	    FAN_TO_REG(val, DIV_FROM_REG(data->fan_div[nr]));
	w83781d_write_value(data, W83781D_REG_FAN_MIN(nr),
			    data->fan_min[nr]);

	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t
cpu0_vid_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct w83781d_data *data = w83781d_update_device(dev);
	return sprintf(buf, "%ld\n", (long) vid_from_reg(data->vid, data->vrm));
}

__attribute__((used)) static ssize_t
vrm_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct w83781d_data *data = dev_get_drvdata(dev);
	return sprintf(buf, "%ld\n", (long) data->vrm);
}

__attribute__((used)) static ssize_t
vrm_store(struct device *dev, struct device_attribute *attr, const char *buf,
	  size_t count)
{
	struct w83781d_data *data = dev_get_drvdata(dev);
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;
	data->vrm = clamp_val(val, 0, 255);

	return count;
}

__attribute__((used)) static ssize_t
alarms_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct w83781d_data *data = w83781d_update_device(dev);
	return sprintf(buf, "%u\n", data->alarms);
}

__attribute__((used)) static ssize_t show_alarm(struct device *dev, struct device_attribute *attr,
		char *buf)
{
	struct w83781d_data *data = w83781d_update_device(dev);
	int bitnr = to_sensor_dev_attr(attr)->index;
	return sprintf(buf, "%u\n", (data->alarms >> bitnr) & 1);
}

__attribute__((used)) static ssize_t show_temp3_alarm(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct w83781d_data *data = w83781d_update_device(dev);
	int bitnr = (data->type == w83781d) ? 5 : 13;
	return sprintf(buf, "%u\n", (data->alarms >> bitnr) & 1);
}

__attribute__((used)) static ssize_t beep_mask_show(struct device *dev,
			       struct device_attribute *attr, char *buf)
{
	struct w83781d_data *data = w83781d_update_device(dev);
	return sprintf(buf, "%ld\n",
		       (long)BEEP_MASK_FROM_REG(data->beep_mask, data->type));
}

__attribute__((used)) static ssize_t
beep_mask_store(struct device *dev, struct device_attribute *attr,
		const char *buf, size_t count)
{
	struct w83781d_data *data = dev_get_drvdata(dev);
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	data->beep_mask &= 0x8000; /* preserve beep enable */
	data->beep_mask |= BEEP_MASK_TO_REG(val, data->type);
	w83781d_write_value(data, W83781D_REG_BEEP_INTS1,
			    data->beep_mask & 0xff);
	w83781d_write_value(data, W83781D_REG_BEEP_INTS2,
			    (data->beep_mask >> 8) & 0xff);
	if (data->type != w83781d && data->type != as99127f) {
		w83781d_write_value(data, W83781D_REG_BEEP_INTS3,
				    ((data->beep_mask) >> 16) & 0xff);
	}
	mutex_unlock(&data->update_lock);

	return count;
}

__attribute__((used)) static ssize_t show_beep(struct device *dev, struct device_attribute *attr,
		char *buf)
{
	struct w83781d_data *data = w83781d_update_device(dev);
	int bitnr = to_sensor_dev_attr(attr)->index;
	return sprintf(buf, "%u\n", (data->beep_mask >> bitnr) & 1);
}

__attribute__((used)) static ssize_t
store_beep(struct device *dev, struct device_attribute *attr,
		const char *buf, size_t count)
{
	struct w83781d_data *data = dev_get_drvdata(dev);
	int bitnr = to_sensor_dev_attr(attr)->index;
	u8 reg;
	unsigned long bit;
	int err;

	err = kstrtoul(buf, 10, &bit);
	if (err)
		return err;

	if (bit & ~1)
		return -EINVAL;

	mutex_lock(&data->update_lock);
	if (bit)
		data->beep_mask |= (1 << bitnr);
	else
		data->beep_mask &= ~(1 << bitnr);

	if (bitnr < 8) {
		reg = w83781d_read_value(data, W83781D_REG_BEEP_INTS1);
		if (bit)
			reg |= (1 << bitnr);
		else
			reg &= ~(1 << bitnr);
		w83781d_write_value(data, W83781D_REG_BEEP_INTS1, reg);
	} else if (bitnr < 16) {
		reg = w83781d_read_value(data, W83781D_REG_BEEP_INTS2);
		if (bit)
			reg |= (1 << (bitnr - 8));
		else
			reg &= ~(1 << (bitnr - 8));
		w83781d_write_value(data, W83781D_REG_BEEP_INTS2, reg);
	} else {
		reg = w83781d_read_value(data, W83781D_REG_BEEP_INTS3);
		if (bit)
			reg |= (1 << (bitnr - 16));
		else
			reg &= ~(1 << (bitnr - 16));
		w83781d_write_value(data, W83781D_REG_BEEP_INTS3, reg);
	}
	mutex_unlock(&data->update_lock);

	return count;
}

__attribute__((used)) static ssize_t show_temp3_beep(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct w83781d_data *data = w83781d_update_device(dev);
	int bitnr = (data->type == w83781d) ? 5 : 13;
	return sprintf(buf, "%u\n", (data->beep_mask >> bitnr) & 1);
}

__attribute__((used)) static ssize_t
show_fan_div(struct device *dev, struct device_attribute *da, char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
	struct w83781d_data *data = w83781d_update_device(dev);
	return sprintf(buf, "%ld\n",
		       (long) DIV_FROM_REG(data->fan_div[attr->index]));
}

__attribute__((used)) static ssize_t
store_fan_div(struct device *dev, struct device_attribute *da,
		const char *buf, size_t count)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
	struct w83781d_data *data = dev_get_drvdata(dev);
	unsigned long min;
	int nr = attr->index;
	u8 reg;
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);

	/* Save fan_min */
	min = FAN_FROM_REG(data->fan_min[nr],
			   DIV_FROM_REG(data->fan_div[nr]));

	data->fan_div[nr] = DIV_TO_REG(val, data->type);

	reg = (w83781d_read_value(data, nr == 2 ?
				  W83781D_REG_PIN : W83781D_REG_VID_FANDIV)
		& (nr == 0 ? 0xcf : 0x3f))
	      | ((data->fan_div[nr] & 0x03) << (nr == 0 ? 4 : 6));
	w83781d_write_value(data, nr == 2 ?
			    W83781D_REG_PIN : W83781D_REG_VID_FANDIV, reg);

	/* w83781d and as99127f don't have extended divisor bits */
	if (data->type != w83781d && data->type != as99127f) {
		reg = (w83781d_read_value(data, W83781D_REG_VBAT)
		       & ~(1 << (5 + nr)))
		    | ((data->fan_div[nr] & 0x04) << (3 + nr));
		w83781d_write_value(data, W83781D_REG_VBAT, reg);
	}

	/* Restore fan_min */
	data->fan_min[nr] = FAN_TO_REG(min, DIV_FROM_REG(data->fan_div[nr]));
	w83781d_write_value(data, W83781D_REG_FAN_MIN(nr), data->fan_min[nr]);

	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t
show_pwm(struct device *dev, struct device_attribute *da, char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
	struct w83781d_data *data = w83781d_update_device(dev);
	return sprintf(buf, "%d\n", (int)data->pwm[attr->index]);
}

__attribute__((used)) static ssize_t
pwm2_enable_show(struct device *dev, struct device_attribute *da, char *buf)
{
	struct w83781d_data *data = w83781d_update_device(dev);
	return sprintf(buf, "%d\n", (int)data->pwm2_enable);
}

__attribute__((used)) static ssize_t
store_pwm(struct device *dev, struct device_attribute *da, const char *buf,
		size_t count)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
	struct w83781d_data *data = dev_get_drvdata(dev);
	int nr = attr->index;
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	data->pwm[nr] = clamp_val(val, 0, 255);
	w83781d_write_value(data, W83781D_REG_PWM[nr], data->pwm[nr]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t
pwm2_enable_store(struct device *dev, struct device_attribute *da,
		const char *buf, size_t count)
{
	struct w83781d_data *data = dev_get_drvdata(dev);
	unsigned long val;
	u32 reg;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);

	switch (val) {
	case 0:
	case 1:
		reg = w83781d_read_value(data, W83781D_REG_PWMCLK12);
		w83781d_write_value(data, W83781D_REG_PWMCLK12,
				    (reg & 0xf7) | (val << 3));

		reg = w83781d_read_value(data, W83781D_REG_BEEP_CONFIG);
		w83781d_write_value(data, W83781D_REG_BEEP_CONFIG,
				    (reg & 0xef) | (!val << 4));

		data->pwm2_enable = val;
		break;

	default:
		mutex_unlock(&data->update_lock);
		return -EINVAL;
	}

	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t
show_sensor(struct device *dev, struct device_attribute *da, char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
	struct w83781d_data *data = w83781d_update_device(dev);
	return sprintf(buf, "%d\n", (int)data->sens[attr->index]);
}

__attribute__((used)) static ssize_t
store_sensor(struct device *dev, struct device_attribute *da,
		const char *buf, size_t count)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
	struct w83781d_data *data = dev_get_drvdata(dev);
	int nr = attr->index;
	unsigned long val;
	u32 tmp;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);

	switch (val) {
	case 1:		/* PII/Celeron diode */
		tmp = w83781d_read_value(data, W83781D_REG_SCFG1);
		w83781d_write_value(data, W83781D_REG_SCFG1,
				    tmp | BIT_SCFG1[nr]);
		tmp = w83781d_read_value(data, W83781D_REG_SCFG2);
		w83781d_write_value(data, W83781D_REG_SCFG2,
				    tmp | BIT_SCFG2[nr]);
		data->sens[nr] = val;
		break;
	case 2:		/* 3904 */
		tmp = w83781d_read_value(data, W83781D_REG_SCFG1);
		w83781d_write_value(data, W83781D_REG_SCFG1,
				    tmp | BIT_SCFG1[nr]);
		tmp = w83781d_read_value(data, W83781D_REG_SCFG2);
		w83781d_write_value(data, W83781D_REG_SCFG2,
				    tmp & ~BIT_SCFG2[nr]);
		data->sens[nr] = val;
		break;
	case W83781D_DEFAULT_BETA:
		dev_warn(dev,
			 "Sensor type %d is deprecated, please use 4 instead\n",
			 W83781D_DEFAULT_BETA);
		/* fall through */
	case 4:		/* thermistor */
		tmp = w83781d_read_value(data, W83781D_REG_SCFG1);
		w83781d_write_value(data, W83781D_REG_SCFG1,
				    tmp & ~BIT_SCFG1[nr]);
		data->sens[nr] = val;
		break;
	default:
		dev_err(dev, "Invalid sensor type %ld; must be 1, 2, or 4\n",
		       (long) val);
		break;
	}

	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static int
w83781d_detect_subclients(struct i2c_client *new_client)
{
	int i, val1 = 0, id;
	int err;
	int address = new_client->addr;
	unsigned short sc_addr[2];
	struct i2c_adapter *adapter = new_client->adapter;
	struct w83781d_data *data = i2c_get_clientdata(new_client);
	enum chips kind = data->type;
	int num_sc = 1;

	id = i2c_adapter_id(adapter);

	if (force_subclients[0] == id && force_subclients[1] == address) {
		for (i = 2; i <= 3; i++) {
			if (force_subclients[i] < 0x48 ||
			    force_subclients[i] > 0x4f) {
				dev_err(&new_client->dev,
					"Invalid subclient address %d; must be 0x48-0x4f\n",
					force_subclients[i]);
				err = -EINVAL;
				goto ERROR_SC_1;
			}
		}
		w83781d_write_value(data, W83781D_REG_I2C_SUBADDR,
				(force_subclients[2] & 0x07) |
				((force_subclients[3] & 0x07) << 4));
		sc_addr[0] = force_subclients[2];
	} else {
		val1 = w83781d_read_value(data, W83781D_REG_I2C_SUBADDR);
		sc_addr[0] = 0x48 + (val1 & 0x07);
	}

	if (kind != w83783s) {
		num_sc = 2;
		if (force_subclients[0] == id &&
		    force_subclients[1] == address) {
			sc_addr[1] = force_subclients[3];
		} else {
			sc_addr[1] = 0x48 + ((val1 >> 4) & 0x07);
		}
		if (sc_addr[0] == sc_addr[1]) {
			dev_err(&new_client->dev,
			       "Duplicate addresses 0x%x for subclients.\n",
			       sc_addr[0]);
			err = -EBUSY;
			goto ERROR_SC_2;
		}
	}

	for (i = 0; i < num_sc; i++) {
		data->lm75[i] = i2c_new_dummy(adapter, sc_addr[i]);
		if (!data->lm75[i]) {
			dev_err(&new_client->dev,
				"Subclient %d registration at address 0x%x failed.\n",
				i, sc_addr[i]);
			err = -ENOMEM;
			if (i == 1)
				goto ERROR_SC_3;
			goto ERROR_SC_2;
		}
	}

	return 0;

/* Undo inits in case of errors */
ERROR_SC_3:
	i2c_unregister_device(data->lm75[0]);
ERROR_SC_2:
ERROR_SC_1:
	return err;
}

__attribute__((used)) static int
w83781d_create_files(struct device *dev, int kind, int is_isa)
{
	int err;

	err = sysfs_create_group(&dev->kobj, &w83781d_group);
	if (err)
		return err;

	if (kind != w83783s) {
		err = sysfs_create_group(&dev->kobj, &w83781d_group_in1);
		if (err)
			return err;
	}
	if (kind != as99127f && kind != w83781d && kind != w83783s) {
		err = sysfs_create_group(&dev->kobj, &w83781d_group_in78);
		if (err)
			return err;
	}
	if (kind != w83783s) {
		err = sysfs_create_group(&dev->kobj, &w83781d_group_temp3);
		if (err)
			return err;

		if (kind != w83781d) {
			err = sysfs_chmod_file(&dev->kobj,
				&sensor_dev_attr_temp3_alarm.dev_attr.attr,
				S_IRUGO | S_IWUSR);
			if (err)
				return err;
		}
	}

	if (kind != w83781d && kind != as99127f) {
		err = sysfs_create_group(&dev->kobj, &w83781d_group_pwm12);
		if (err)
			return err;
	}
	if (kind == w83782d && !is_isa) {
		err = sysfs_create_group(&dev->kobj, &w83781d_group_pwm34);
		if (err)
			return err;
	}

	if (kind != as99127f && kind != w83781d) {
		err = device_create_file(dev,
					 &sensor_dev_attr_temp1_type.dev_attr);
		if (err)
			return err;
		err = device_create_file(dev,
					 &sensor_dev_attr_temp2_type.dev_attr);
		if (err)
			return err;
		if (kind != w83783s) {
			err = device_create_file(dev,
					&sensor_dev_attr_temp3_type.dev_attr);
			if (err)
				return err;
		}
	}

	return 0;
}

__attribute__((used)) static int
w83781d_detect(struct i2c_client *client, struct i2c_board_info *info)
{
	int val1, val2;
	struct w83781d_data *isa = w83781d_data_if_isa();
	struct i2c_adapter *adapter = client->adapter;
	int address = client->addr;
	const char *client_name;
	enum vendor { winbond, asus } vendid;

	if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
		return -ENODEV;

	/*
	 * We block updates of the ISA device to minimize the risk of
	 * concurrent access to the same W83781D chip through different
	 * interfaces.
	 */
	if (isa)
		mutex_lock(&isa->update_lock);

	if (i2c_smbus_read_byte_data(client, W83781D_REG_CONFIG) & 0x80) {
		dev_dbg(&adapter->dev,
			"Detection of w83781d chip failed at step 3\n");
		goto err_nodev;
	}

	val1 = i2c_smbus_read_byte_data(client, W83781D_REG_BANK);
	val2 = i2c_smbus_read_byte_data(client, W83781D_REG_CHIPMAN);
	/* Check for Winbond or Asus ID if in bank 0 */
	if (!(val1 & 0x07) &&
	    ((!(val1 & 0x80) && val2 != 0xa3 && val2 != 0xc3) ||
	     ((val1 & 0x80) && val2 != 0x5c && val2 != 0x12))) {
		dev_dbg(&adapter->dev,
			"Detection of w83781d chip failed at step 4\n");
		goto err_nodev;
	}
	/*
	 * If Winbond SMBus, check address at 0x48.
	 * Asus doesn't support, except for as99127f rev.2
	 */
	if ((!(val1 & 0x80) && val2 == 0xa3) ||
	    ((val1 & 0x80) && val2 == 0x5c)) {
		if (i2c_smbus_read_byte_data(client, W83781D_REG_I2C_ADDR)
		    != address) {
			dev_dbg(&adapter->dev,
				"Detection of w83781d chip failed at step 5\n");
			goto err_nodev;
		}
	}

	/* Put it now into bank 0 and Vendor ID High Byte */
	i2c_smbus_write_byte_data(client, W83781D_REG_BANK,
		(i2c_smbus_read_byte_data(client, W83781D_REG_BANK)
		 & 0x78) | 0x80);

	/* Get the vendor ID */
	val2 = i2c_smbus_read_byte_data(client, W83781D_REG_CHIPMAN);
	if (val2 == 0x5c)
		vendid = winbond;
	else if (val2 == 0x12)
		vendid = asus;
	else {
		dev_dbg(&adapter->dev,
			"w83781d chip vendor is neither Winbond nor Asus\n");
		goto err_nodev;
	}

	/* Determine the chip type. */
	val1 = i2c_smbus_read_byte_data(client, W83781D_REG_WCHIPID);
	if ((val1 == 0x10 || val1 == 0x11) && vendid == winbond)
		client_name = "w83781d";
	else if (val1 == 0x30 && vendid == winbond)
		client_name = "w83782d";
	else if (val1 == 0x40 && vendid == winbond && address == 0x2d)
		client_name = "w83783s";
	else if (val1 == 0x31)
		client_name = "as99127f";
	else
		goto err_nodev;

	if (val1 <= 0x30 && w83781d_alias_detect(client, val1)) {
		dev_dbg(&adapter->dev,
			"Device at 0x%02x appears to be the same as ISA device\n",
			address);
		goto err_nodev;
	}

	if (isa)
		mutex_unlock(&isa->update_lock);

	strlcpy(info->type, client_name, I2C_NAME_SIZE);

	return 0;

 err_nodev:
	if (isa)
		mutex_unlock(&isa->update_lock);
	return -ENODEV;
}

__attribute__((used)) static void w83781d_remove_files(struct device *dev)
{
	sysfs_remove_group(&dev->kobj, &w83781d_group);
	sysfs_remove_group(&dev->kobj, &w83781d_group_in1);
	sysfs_remove_group(&dev->kobj, &w83781d_group_in78);
	sysfs_remove_group(&dev->kobj, &w83781d_group_temp3);
	sysfs_remove_group(&dev->kobj, &w83781d_group_pwm12);
	sysfs_remove_group(&dev->kobj, &w83781d_group_pwm34);
	sysfs_remove_group(&dev->kobj, &w83781d_group_other);
}

__attribute__((used)) static int
w83781d_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	struct device *dev = &client->dev;
	struct w83781d_data *data;
	int err;

	data = devm_kzalloc(dev, sizeof(struct w83781d_data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	i2c_set_clientdata(client, data);
	mutex_init(&data->lock);
	mutex_init(&data->update_lock);

	data->type = id->driver_data;
	data->client = client;

	/* attach secondary i2c lm75-like clients */
	err = w83781d_detect_subclients(client);
	if (err)
		return err;

	/* Initialize the chip */
	w83781d_init_device(dev);

	/* Register sysfs hooks */
	err = w83781d_create_files(dev, data->type, 0);
	if (err)
		goto exit_remove_files;

	data->hwmon_dev = hwmon_device_register(dev);
	if (IS_ERR(data->hwmon_dev)) {
		err = PTR_ERR(data->hwmon_dev);
		goto exit_remove_files;
	}

	return 0;

 exit_remove_files:
	w83781d_remove_files(dev);
	i2c_unregister_device(data->lm75[0]);
	i2c_unregister_device(data->lm75[1]);
	return err;
}

__attribute__((used)) static int
w83781d_remove(struct i2c_client *client)
{
	struct w83781d_data *data = i2c_get_clientdata(client);
	struct device *dev = &client->dev;

	hwmon_device_unregister(data->hwmon_dev);
	w83781d_remove_files(dev);

	i2c_unregister_device(data->lm75[0]);
	i2c_unregister_device(data->lm75[1]);

	return 0;
}

__attribute__((used)) static int
w83781d_read_value_i2c(struct w83781d_data *data, u16 reg)
{
	struct i2c_client *client = data->client;
	int res, bank;
	struct i2c_client *cl;

	bank = (reg >> 8) & 0x0f;
	if (bank > 2)
		/* switch banks */
		i2c_smbus_write_byte_data(client, W83781D_REG_BANK,
					  bank);
	if (bank == 0 || bank > 2) {
		res = i2c_smbus_read_byte_data(client, reg & 0xff);
	} else {
		/* switch to subclient */
		cl = data->lm75[bank - 1];
		/* convert from ISA to LM75 I2C addresses */
		switch (reg & 0xff) {
		case 0x50:	/* TEMP */
			res = i2c_smbus_read_word_swapped(cl, 0);
			break;
		case 0x52:	/* CONFIG */
			res = i2c_smbus_read_byte_data(cl, 1);
			break;
		case 0x53:	/* HYST */
			res = i2c_smbus_read_word_swapped(cl, 2);
			break;
		case 0x55:	/* OVER */
		default:
			res = i2c_smbus_read_word_swapped(cl, 3);
			break;
		}
	}
	if (bank > 2)
		i2c_smbus_write_byte_data(client, W83781D_REG_BANK, 0);

	return res;
}

__attribute__((used)) static int
w83781d_write_value_i2c(struct w83781d_data *data, u16 reg, u16 value)
{
	struct i2c_client *client = data->client;
	int bank;
	struct i2c_client *cl;

	bank = (reg >> 8) & 0x0f;
	if (bank > 2)
		/* switch banks */
		i2c_smbus_write_byte_data(client, W83781D_REG_BANK,
					  bank);
	if (bank == 0 || bank > 2) {
		i2c_smbus_write_byte_data(client, reg & 0xff,
					  value & 0xff);
	} else {
		/* switch to subclient */
		cl = data->lm75[bank - 1];
		/* convert from ISA to LM75 I2C addresses */
		switch (reg & 0xff) {
		case 0x52:	/* CONFIG */
			i2c_smbus_write_byte_data(cl, 1, value & 0xff);
			break;
		case 0x53:	/* HYST */
			i2c_smbus_write_word_swapped(cl, 2, value);
			break;
		case 0x55:	/* OVER */
			i2c_smbus_write_word_swapped(cl, 3, value);
			break;
		}
	}
	if (bank > 2)
		i2c_smbus_write_byte_data(client, W83781D_REG_BANK, 0);

	return 0;
}

__attribute__((used)) static void
w83781d_init_device(struct device *dev)
{
	struct w83781d_data *data = dev_get_drvdata(dev);
	int i, p;
	int type = data->type;
	u8 tmp;

	if (reset && type != as99127f) { /*
					  * this resets registers we don't have
					  * documentation for on the as99127f
					  */
		/*
		 * Resetting the chip has been the default for a long time,
		 * but it causes the BIOS initializations (fan clock dividers,
		 * thermal sensor types...) to be lost, so it is now optional.
		 * It might even go away if nobody reports it as being useful,
		 * as I see very little reason why this would be needed at
		 * all.
		 */
		dev_info(dev,
			 "If reset=1 solved a problem you were having, please report!\n");

		/* save these registers */
		i = w83781d_read_value(data, W83781D_REG_BEEP_CONFIG);
		p = w83781d_read_value(data, W83781D_REG_PWMCLK12);
		/*
		 * Reset all except Watchdog values and last conversion values
		 * This sets fan-divs to 2, among others
		 */
		w83781d_write_value(data, W83781D_REG_CONFIG, 0x80);
		/*
		 * Restore the registers and disable power-on abnormal beep.
		 * This saves FAN 1/2/3 input/output values set by BIOS.
		 */
		w83781d_write_value(data, W83781D_REG_BEEP_CONFIG, i | 0x80);
		w83781d_write_value(data, W83781D_REG_PWMCLK12, p);
		/*
		 * Disable master beep-enable (reset turns it on).
		 * Individual beep_mask should be reset to off but for some
		 * reason disabling this bit helps some people not get beeped
		 */
		w83781d_write_value(data, W83781D_REG_BEEP_INTS2, 0);
	}

	/*
	 * Disable power-on abnormal beep, as advised by the datasheet.
	 * Already done if reset=1.
	 */
	if (init && !reset && type != as99127f) {
		i = w83781d_read_value(data, W83781D_REG_BEEP_CONFIG);
		w83781d_write_value(data, W83781D_REG_BEEP_CONFIG, i | 0x80);
	}

	data->vrm = vid_which_vrm();

	if ((type != w83781d) && (type != as99127f)) {
		tmp = w83781d_read_value(data, W83781D_REG_SCFG1);
		for (i = 1; i <= 3; i++) {
			if (!(tmp & BIT_SCFG1[i - 1])) {
				data->sens[i - 1] = 4;
			} else {
				if (w83781d_read_value
				    (data,
				     W83781D_REG_SCFG2) & BIT_SCFG2[i - 1])
					data->sens[i - 1] = 1;
				else
					data->sens[i - 1] = 2;
			}
			if (type == w83783s && i == 2)
				break;
		}
	}

	if (init && type != as99127f) {
		/* Enable temp2 */
		tmp = w83781d_read_value(data, W83781D_REG_TEMP2_CONFIG);
		if (tmp & 0x01) {
			dev_warn(dev,
				 "Enabling temp2, readings might not make sense\n");
			w83781d_write_value(data, W83781D_REG_TEMP2_CONFIG,
				tmp & 0xfe);
		}

		/* Enable temp3 */
		if (type != w83783s) {
			tmp = w83781d_read_value(data,
				W83781D_REG_TEMP3_CONFIG);
			if (tmp & 0x01) {
				dev_warn(dev,
					 "Enabling temp3, readings might not make sense\n");
				w83781d_write_value(data,
					W83781D_REG_TEMP3_CONFIG, tmp & 0xfe);
			}
		}
	}

	/* Start monitoring */
	w83781d_write_value(data, W83781D_REG_CONFIG,
			    (w83781d_read_value(data,
						W83781D_REG_CONFIG) & 0xf7)
			    | 0x01);

	/* A few vars need to be filled upon startup */
	for (i = 0; i < 3; i++) {
		data->fan_min[i] = w83781d_read_value(data,
					W83781D_REG_FAN_MIN(i));
	}

	mutex_init(&data->update_lock);
}

__attribute__((used)) static struct w83781d_data *w83781d_update_device(struct device *dev)
{
	struct w83781d_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	int i;

	mutex_lock(&data->update_lock);

	if (time_after(jiffies, data->last_updated + HZ + HZ / 2)
	    || !data->valid) {
		dev_dbg(dev, "Starting device update\n");

		for (i = 0; i <= 8; i++) {
			if (data->type == w83783s && i == 1)
				continue;	/* 783S has no in1 */
			data->in[i] =
			    w83781d_read_value(data, W83781D_REG_IN(i));
			data->in_min[i] =
			    w83781d_read_value(data, W83781D_REG_IN_MIN(i));
			data->in_max[i] =
			    w83781d_read_value(data, W83781D_REG_IN_MAX(i));
			if ((data->type != w83782d) && (i == 6))
				break;
		}
		for (i = 0; i < 3; i++) {
			data->fan[i] =
			    w83781d_read_value(data, W83781D_REG_FAN(i));
			data->fan_min[i] =
			    w83781d_read_value(data, W83781D_REG_FAN_MIN(i));
		}
		if (data->type != w83781d && data->type != as99127f) {
			for (i = 0; i < 4; i++) {
				data->pwm[i] =
				    w83781d_read_value(data,
						       W83781D_REG_PWM[i]);
				/* Only W83782D on SMBus has PWM3 and PWM4 */
				if ((data->type != w83782d || !client)
				    && i == 1)
					break;
			}
			/* Only PWM2 can be disabled */
			data->pwm2_enable = (w83781d_read_value(data,
					     W83781D_REG_PWMCLK12) & 0x08) >> 3;
		}

		data->temp = w83781d_read_value(data, W83781D_REG_TEMP(1));
		data->temp_max =
		    w83781d_read_value(data, W83781D_REG_TEMP_OVER(1));
		data->temp_max_hyst =
		    w83781d_read_value(data, W83781D_REG_TEMP_HYST(1));
		data->temp_add[0] =
		    w83781d_read_value(data, W83781D_REG_TEMP(2));
		data->temp_max_add[0] =
		    w83781d_read_value(data, W83781D_REG_TEMP_OVER(2));
		data->temp_max_hyst_add[0] =
		    w83781d_read_value(data, W83781D_REG_TEMP_HYST(2));
		if (data->type != w83783s) {
			data->temp_add[1] =
			    w83781d_read_value(data, W83781D_REG_TEMP(3));
			data->temp_max_add[1] =
			    w83781d_read_value(data,
					       W83781D_REG_TEMP_OVER(3));
			data->temp_max_hyst_add[1] =
			    w83781d_read_value(data,
					       W83781D_REG_TEMP_HYST(3));
		}
		i = w83781d_read_value(data, W83781D_REG_VID_FANDIV);
		data->vid = i & 0x0f;
		data->vid |= (w83781d_read_value(data,
					W83781D_REG_CHIPID) & 0x01) << 4;
		data->fan_div[0] = (i >> 4) & 0x03;
		data->fan_div[1] = (i >> 6) & 0x03;
		data->fan_div[2] = (w83781d_read_value(data,
					W83781D_REG_PIN) >> 6) & 0x03;
		if ((data->type != w83781d) && (data->type != as99127f)) {
			i = w83781d_read_value(data, W83781D_REG_VBAT);
			data->fan_div[0] |= (i >> 3) & 0x04;
			data->fan_div[1] |= (i >> 4) & 0x04;
			data->fan_div[2] |= (i >> 5) & 0x04;
		}
		if (data->type == w83782d) {
			data->alarms = w83781d_read_value(data,
						W83782D_REG_ALARM1)
				     | (w83781d_read_value(data,
						W83782D_REG_ALARM2) << 8)
				     | (w83781d_read_value(data,
						W83782D_REG_ALARM3) << 16);
		} else if (data->type == w83783s) {
			data->alarms = w83781d_read_value(data,
						W83782D_REG_ALARM1)
				     | (w83781d_read_value(data,
						W83782D_REG_ALARM2) << 8);
		} else {
			/*
			 * No real-time status registers, fall back to
			 * interrupt status registers
			 */
			data->alarms = w83781d_read_value(data,
						W83781D_REG_ALARM1)
				     | (w83781d_read_value(data,
						W83781D_REG_ALARM2) << 8);
		}
		i = w83781d_read_value(data, W83781D_REG_BEEP_INTS2);
		data->beep_mask = (i << 8) +
		    w83781d_read_value(data, W83781D_REG_BEEP_INTS1);
		if ((data->type != w83781d) && (data->type != as99127f)) {
			data->beep_mask |=
			    w83781d_read_value(data,
					       W83781D_REG_BEEP_INTS3) << 16;
		}
		data->last_updated = jiffies;
		data->valid = 1;
	}

	mutex_unlock(&data->update_lock);

	return data;
}

__attribute__((used)) static struct w83781d_data *w83781d_data_if_isa(void)
{
	return NULL;
}

__attribute__((used)) static int
w83781d_alias_detect(struct i2c_client *client, u8 chipid)
{
	return 0;
}

__attribute__((used)) static int
w83781d_read_value(struct w83781d_data *data, u16 reg)
{
	int res;

	mutex_lock(&data->lock);
	res = w83781d_read_value_i2c(data, reg);
	mutex_unlock(&data->lock);

	return res;
}

__attribute__((used)) static int
w83781d_write_value(struct w83781d_data *data, u16 reg, u16 value)
{
	mutex_lock(&data->lock);
	w83781d_write_value_i2c(data, reg, value);
	mutex_unlock(&data->lock);

	return 0;
}

