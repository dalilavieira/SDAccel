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
typedef  scalar_t__ u8 ;
struct i2c_device_id {scalar_t__ driver_data; } ;
struct device {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  name; struct device dev; struct i2c_adapter* adapter; } ;
struct i2c_board_info {int /*<<< orphan*/  type; } ;
struct i2c_adapter {int dummy; } ;
struct device_attribute {int dummy; } ;
struct adm1031_data {unsigned long last_updated; int update_interval; int valid; scalar_t__ chip_type; int* ext_temp; unsigned int* temp_offset; unsigned int* temp_min; int* temp_max; unsigned int* temp_crit; int* auto_temp; scalar_t__ conf1; int alarm; int* fan_div; long* fan_min; long* fan; int* pwm; scalar_t__*** chan_select_table; int* old_pwm; int /*<<< orphan*/ ** groups; int /*<<< orphan*/  update_lock; struct i2c_client* client; scalar_t__* temp; scalar_t__ conf2; } ;
typedef  int ssize_t ;
struct TYPE_2__ {int index; } ;

/* Variables and functions */
 scalar_t__ ADM1031_CONF1_AUTO_MODE ; 
 unsigned int ADM1031_CONF1_MONITOR_ENABLE ; 
 unsigned int ADM1031_CONF2_PWM1_ENABLE ; 
 unsigned int ADM1031_CONF2_PWM2_ENABLE ; 
 unsigned int ADM1031_CONF2_TACH1_ENABLE ; 
 unsigned int ADM1031_CONF2_TACH2_ENABLE ; 
 scalar_t__ ADM1031_REG_AUTO_TEMP (int) ; 
 scalar_t__ ADM1031_REG_CONF1 ; 
 scalar_t__ ADM1031_REG_CONF2 ; 
 scalar_t__ ADM1031_REG_EXT_TEMP ; 
 scalar_t__ ADM1031_REG_FAN_DIV (int) ; 
 scalar_t__ ADM1031_REG_FAN_FILTER ; 
 scalar_t__ ADM1031_REG_FAN_MIN (int) ; 
 scalar_t__ ADM1031_REG_FAN_SPEED (int) ; 
 scalar_t__ ADM1031_REG_PWM ; 
 scalar_t__ ADM1031_REG_STATUS (int) ; 
 scalar_t__ ADM1031_REG_TEMP (int) ; 
 scalar_t__ ADM1031_REG_TEMP_CRIT (int) ; 
 scalar_t__ ADM1031_REG_TEMP_MAX (int) ; 
 scalar_t__ ADM1031_REG_TEMP_MIN (int) ; 
 scalar_t__ ADM1031_REG_TEMP_OFFSET (int) ; 
 scalar_t__ ADM1031_UPDATE_RATE_MASK ; 
 int ADM1031_UPDATE_RATE_SHIFT ; 
 int ARRAY_SIZE (unsigned long*) ; 
 int AUTO_TEMP_MAX_FROM_REG (unsigned int) ; 
 int AUTO_TEMP_MIN_FROM_REG (int) ; 
 scalar_t__ AUTO_TEMP_MIN_FROM_REG_DEG (int) ; 
 int AUTO_TEMP_MIN_TO_REG (long,int) ; 
 int AUTO_TEMP_OFF_FROM_REG (int) ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 size_t FAN_CHAN_FROM_REG (scalar_t__) ; 
 void* FAN_CHAN_TO_REG (scalar_t__,scalar_t__) ; 
 int FAN_DIV_FROM_REG (int) ; 
 int FAN_FROM_REG (long,int) ; 
 int GET_FAN_AUTO_BITFIELD (struct adm1031_data*,int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_BYTE_DATA ; 
 int /*<<< orphan*/  I2C_NAME_SIZE ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
 int PWM_FROM_REG (int) ; 
 int PWM_TO_REG (long) ; 
 int TEMP_FROM_REG (unsigned int) ; 
 int TEMP_FROM_REG_EXT (scalar_t__,int) ; 
 int TEMP_OFFSET_FROM_REG (unsigned int) ; 
 unsigned int TEMP_OFFSET_TO_REG (long) ; 
 void* TEMP_TO_REG (long) ; 
 scalar_t__ adm1030 ; 
 scalar_t__ adm1031 ; 
 int /*<<< orphan*/  adm1031_group ; 
 int /*<<< orphan*/  adm1031_group_opt ; 
 scalar_t__** auto_channel_select_table_adm1030 ; 
 scalar_t__** auto_channel_select_table_adm1031 ; 
 long clamp_val (long,int,int) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*) ; 
 struct adm1031_data* dev_get_drvdata (struct device*) ; 
 struct device* devm_hwmon_device_register_with_groups (struct device*,int /*<<< orphan*/ ,struct adm1031_data*,int /*<<< orphan*/ **) ; 
 struct adm1031_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int /*<<< orphan*/ ) ; 
 struct adm1031_data* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct adm1031_data*) ; 
 scalar_t__ i2c_smbus_read_byte_data (struct i2c_client*,int) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,scalar_t__,unsigned int) ; 
 unsigned long jiffies ; 
 int kstrtol (char const*,int,long*) ; 
 int kstrtoul (char const*,int,unsigned long*) ; 
 unsigned long msecs_to_jiffies (int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int sprintf (char*,char*,int) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ ) ; 
 scalar_t__ time_after (unsigned long,unsigned long) ; 
 TYPE_1__* to_sensor_dev_attr (struct device_attribute*) ; 
 unsigned long* update_intervals ; 

__attribute__((used)) static inline u8 adm1031_read_value(struct i2c_client *client, u8 reg)
{
	return i2c_smbus_read_byte_data(client, reg);
}

__attribute__((used)) static inline int
adm1031_write_value(struct i2c_client *client, u8 reg, unsigned int value)
{
	return i2c_smbus_write_byte_data(client, reg, value);
}

__attribute__((used)) static struct adm1031_data *adm1031_update_device(struct device *dev)
{
	struct adm1031_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	unsigned long next_update;
	int chan;

	mutex_lock(&data->update_lock);

	next_update = data->last_updated
	  + msecs_to_jiffies(data->update_interval);
	if (time_after(jiffies, next_update) || !data->valid) {

		dev_dbg(&client->dev, "Starting adm1031 update\n");
		for (chan = 0;
		     chan < ((data->chip_type == adm1031) ? 3 : 2); chan++) {
			u8 oldh, newh;

			oldh =
			    adm1031_read_value(client, ADM1031_REG_TEMP(chan));
			data->ext_temp[chan] =
			    adm1031_read_value(client, ADM1031_REG_EXT_TEMP);
			newh =
			    adm1031_read_value(client, ADM1031_REG_TEMP(chan));
			if (newh != oldh) {
				data->ext_temp[chan] =
				    adm1031_read_value(client,
						       ADM1031_REG_EXT_TEMP);
#ifdef DEBUG
				oldh =
				    adm1031_read_value(client,
						       ADM1031_REG_TEMP(chan));

				/* oldh is actually newer */
				if (newh != oldh)
					dev_warn(&client->dev,
					  "Remote temperature may be wrong.\n");
#endif
			}
			data->temp[chan] = newh;

			data->temp_offset[chan] =
			    adm1031_read_value(client,
					       ADM1031_REG_TEMP_OFFSET(chan));
			data->temp_min[chan] =
			    adm1031_read_value(client,
					       ADM1031_REG_TEMP_MIN(chan));
			data->temp_max[chan] =
			    adm1031_read_value(client,
					       ADM1031_REG_TEMP_MAX(chan));
			data->temp_crit[chan] =
			    adm1031_read_value(client,
					       ADM1031_REG_TEMP_CRIT(chan));
			data->auto_temp[chan] =
			    adm1031_read_value(client,
					       ADM1031_REG_AUTO_TEMP(chan));

		}

		data->conf1 = adm1031_read_value(client, ADM1031_REG_CONF1);
		data->conf2 = adm1031_read_value(client, ADM1031_REG_CONF2);

		data->alarm = adm1031_read_value(client, ADM1031_REG_STATUS(0))
		    | (adm1031_read_value(client, ADM1031_REG_STATUS(1)) << 8);
		if (data->chip_type == adm1030)
			data->alarm &= 0xc0ff;

		for (chan = 0; chan < (data->chip_type == adm1030 ? 1 : 2);
		     chan++) {
			data->fan_div[chan] =
			    adm1031_read_value(client,
					       ADM1031_REG_FAN_DIV(chan));
			data->fan_min[chan] =
			    adm1031_read_value(client,
					       ADM1031_REG_FAN_MIN(chan));
			data->fan[chan] =
			    adm1031_read_value(client,
					       ADM1031_REG_FAN_SPEED(chan));
			data->pwm[chan] =
			  (adm1031_read_value(client,
					ADM1031_REG_PWM) >> (4 * chan)) & 0x0f;
		}
		data->last_updated = jiffies;
		data->valid = 1;
	}

	mutex_unlock(&data->update_lock);

	return data;
}

__attribute__((used)) static int FAN_TO_REG(int reg, int div)
{
	int tmp;
	tmp = FAN_FROM_REG(clamp_val(reg, 0, 65535), div);
	return tmp > 255 ? 255 : tmp;
}

__attribute__((used)) static int AUTO_TEMP_MAX_TO_REG(int val, int reg, int pwm)
{
	int ret;
	int range = val - AUTO_TEMP_MIN_FROM_REG(reg);

	range = ((val - AUTO_TEMP_MIN_FROM_REG(reg))*10)/(16 - pwm);
	ret = ((reg & 0xf8) |
	       (range < 10000 ? 0 :
		range < 20000 ? 1 :
		range < 40000 ? 2 : range < 80000 ? 3 : 4));
	return ret;
}

__attribute__((used)) static int
get_fan_auto_nearest(struct adm1031_data *data, int chan, u8 val, u8 reg)
{
	int i;
	int first_match = -1, exact_match = -1;
	u8 other_reg_val =
	    (*data->chan_select_table)[FAN_CHAN_FROM_REG(reg)][chan ? 0 : 1];

	if (val == 0)
		return 0;

	for (i = 0; i < 8; i++) {
		if ((val == (*data->chan_select_table)[i][chan]) &&
		    ((*data->chan_select_table)[i][chan ? 0 : 1] ==
		     other_reg_val)) {
			/* We found an exact match */
			exact_match = i;
			break;
		} else if (val == (*data->chan_select_table)[i][chan] &&
			   first_match == -1) {
			/*
			 * Save the first match in case of an exact match has
			 * not been found
			 */
			first_match = i;
		}
	}

	if (exact_match >= 0)
		return exact_match;
	else if (first_match >= 0)
		return first_match;

	return -EINVAL;
}

__attribute__((used)) static ssize_t show_fan_auto_channel(struct device *dev,
				     struct device_attribute *attr, char *buf)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct adm1031_data *data = adm1031_update_device(dev);
	return sprintf(buf, "%d\n", GET_FAN_AUTO_BITFIELD(data, nr));
}

__attribute__((used)) static ssize_t
set_fan_auto_channel(struct device *dev, struct device_attribute *attr,
		     const char *buf, size_t count)
{
	struct adm1031_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	int nr = to_sensor_dev_attr(attr)->index;
	long val;
	u8 reg;
	int ret;
	u8 old_fan_mode;

	ret = kstrtol(buf, 10, &val);
	if (ret)
		return ret;

	old_fan_mode = data->conf1;

	mutex_lock(&data->update_lock);

	ret = get_fan_auto_nearest(data, nr, val, data->conf1);
	if (ret < 0) {
		mutex_unlock(&data->update_lock);
		return ret;
	}
	reg = ret;
	data->conf1 = FAN_CHAN_TO_REG(reg, data->conf1);
	if ((data->conf1 & ADM1031_CONF1_AUTO_MODE) ^
	    (old_fan_mode & ADM1031_CONF1_AUTO_MODE)) {
		if (data->conf1 & ADM1031_CONF1_AUTO_MODE) {
			/*
			 * Switch to Auto Fan Mode
			 * Save PWM registers
			 * Set PWM registers to 33% Both
			 */
			data->old_pwm[0] = data->pwm[0];
			data->old_pwm[1] = data->pwm[1];
			adm1031_write_value(client, ADM1031_REG_PWM, 0x55);
		} else {
			/* Switch to Manual Mode */
			data->pwm[0] = data->old_pwm[0];
			data->pwm[1] = data->old_pwm[1];
			/* Restore PWM registers */
			adm1031_write_value(client, ADM1031_REG_PWM,
					    data->pwm[0] | (data->pwm[1] << 4));
		}
	}
	data->conf1 = FAN_CHAN_TO_REG(reg, data->conf1);
	adm1031_write_value(client, ADM1031_REG_CONF1, data->conf1);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_auto_temp_off(struct device *dev,
				  struct device_attribute *attr, char *buf)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct adm1031_data *data = adm1031_update_device(dev);
	return sprintf(buf, "%d\n",
		       AUTO_TEMP_OFF_FROM_REG(data->auto_temp[nr]));
}

__attribute__((used)) static ssize_t show_auto_temp_min(struct device *dev,
				  struct device_attribute *attr, char *buf)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct adm1031_data *data = adm1031_update_device(dev);
	return sprintf(buf, "%d\n",
		       AUTO_TEMP_MIN_FROM_REG(data->auto_temp[nr]));
}

__attribute__((used)) static ssize_t
set_auto_temp_min(struct device *dev, struct device_attribute *attr,
		  const char *buf, size_t count)
{
	struct adm1031_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	int nr = to_sensor_dev_attr(attr)->index;
	long val;
	int ret;

	ret = kstrtol(buf, 10, &val);
	if (ret)
		return ret;

	val = clamp_val(val, 0, 127000);
	mutex_lock(&data->update_lock);
	data->auto_temp[nr] = AUTO_TEMP_MIN_TO_REG(val, data->auto_temp[nr]);
	adm1031_write_value(client, ADM1031_REG_AUTO_TEMP(nr),
			    data->auto_temp[nr]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_auto_temp_max(struct device *dev,
				  struct device_attribute *attr, char *buf)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct adm1031_data *data = adm1031_update_device(dev);
	return sprintf(buf, "%d\n",
		       AUTO_TEMP_MAX_FROM_REG(data->auto_temp[nr]));
}

__attribute__((used)) static ssize_t
set_auto_temp_max(struct device *dev, struct device_attribute *attr,
		  const char *buf, size_t count)
{
	struct adm1031_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	int nr = to_sensor_dev_attr(attr)->index;
	long val;
	int ret;

	ret = kstrtol(buf, 10, &val);
	if (ret)
		return ret;

	val = clamp_val(val, 0, 127000);
	mutex_lock(&data->update_lock);
	data->temp_max[nr] = AUTO_TEMP_MAX_TO_REG(val, data->auto_temp[nr],
						  data->pwm[nr]);
	adm1031_write_value(client, ADM1031_REG_AUTO_TEMP(nr),
			    data->temp_max[nr]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_pwm(struct device *dev,
			struct device_attribute *attr, char *buf)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct adm1031_data *data = adm1031_update_device(dev);
	return sprintf(buf, "%d\n", PWM_FROM_REG(data->pwm[nr]));
}

__attribute__((used)) static ssize_t set_pwm(struct device *dev, struct device_attribute *attr,
		       const char *buf, size_t count)
{
	struct adm1031_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	int nr = to_sensor_dev_attr(attr)->index;
	long val;
	int ret, reg;

	ret = kstrtol(buf, 10, &val);
	if (ret)
		return ret;

	mutex_lock(&data->update_lock);
	if ((data->conf1 & ADM1031_CONF1_AUTO_MODE) &&
	    (((val>>4) & 0xf) != 5)) {
		/* In automatic mode, the only PWM accepted is 33% */
		mutex_unlock(&data->update_lock);
		return -EINVAL;
	}
	data->pwm[nr] = PWM_TO_REG(val);
	reg = adm1031_read_value(client, ADM1031_REG_PWM);
	adm1031_write_value(client, ADM1031_REG_PWM,
			    nr ? ((data->pwm[nr] << 4) & 0xf0) | (reg & 0xf)
			    : (data->pwm[nr] & 0xf) | (reg & 0xf0));
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static int trust_fan_readings(struct adm1031_data *data, int chan)
{
	int res = 0;

	if (data->conf1 & ADM1031_CONF1_AUTO_MODE) {
		switch (data->conf1 & 0x60) {
		case 0x00:
			/*
			 * remote temp1 controls fan1,
			 * remote temp2 controls fan2
			 */
			res = data->temp[chan+1] >=
			    AUTO_TEMP_MIN_FROM_REG_DEG(data->auto_temp[chan+1]);
			break;
		case 0x20:	/* remote temp1 controls both fans */
			res =
			    data->temp[1] >=
			    AUTO_TEMP_MIN_FROM_REG_DEG(data->auto_temp[1]);
			break;
		case 0x40:	/* remote temp2 controls both fans */
			res =
			    data->temp[2] >=
			    AUTO_TEMP_MIN_FROM_REG_DEG(data->auto_temp[2]);
			break;
		case 0x60:	/* max controls both fans */
			res =
			    data->temp[0] >=
			    AUTO_TEMP_MIN_FROM_REG_DEG(data->auto_temp[0])
			    || data->temp[1] >=
			    AUTO_TEMP_MIN_FROM_REG_DEG(data->auto_temp[1])
			    || (data->chip_type == adm1031
				&& data->temp[2] >=
				AUTO_TEMP_MIN_FROM_REG_DEG(data->auto_temp[2]));
			break;
		}
	} else {
		res = data->pwm[chan] > 0;
	}
	return res;
}

__attribute__((used)) static ssize_t show_fan(struct device *dev,
			struct device_attribute *attr, char *buf)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct adm1031_data *data = adm1031_update_device(dev);
	int value;

	value = trust_fan_readings(data, nr) ? FAN_FROM_REG(data->fan[nr],
				 FAN_DIV_FROM_REG(data->fan_div[nr])) : 0;
	return sprintf(buf, "%d\n", value);
}

__attribute__((used)) static ssize_t show_fan_div(struct device *dev,
			    struct device_attribute *attr, char *buf)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct adm1031_data *data = adm1031_update_device(dev);
	return sprintf(buf, "%d\n", FAN_DIV_FROM_REG(data->fan_div[nr]));
}

__attribute__((used)) static ssize_t show_fan_min(struct device *dev,
			    struct device_attribute *attr, char *buf)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct adm1031_data *data = adm1031_update_device(dev);
	return sprintf(buf, "%d\n",
		       FAN_FROM_REG(data->fan_min[nr],
				    FAN_DIV_FROM_REG(data->fan_div[nr])));
}

__attribute__((used)) static ssize_t set_fan_min(struct device *dev, struct device_attribute *attr,
			   const char *buf, size_t count)
{
	struct adm1031_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	int nr = to_sensor_dev_attr(attr)->index;
	long val;
	int ret;

	ret = kstrtol(buf, 10, &val);
	if (ret)
		return ret;

	mutex_lock(&data->update_lock);
	if (val) {
		data->fan_min[nr] =
			FAN_TO_REG(val, FAN_DIV_FROM_REG(data->fan_div[nr]));
	} else {
		data->fan_min[nr] = 0xff;
	}
	adm1031_write_value(client, ADM1031_REG_FAN_MIN(nr), data->fan_min[nr]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t set_fan_div(struct device *dev, struct device_attribute *attr,
			   const char *buf, size_t count)
{
	struct adm1031_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	int nr = to_sensor_dev_attr(attr)->index;
	long val;
	u8 tmp;
	int old_div;
	int new_min;
	int ret;

	ret = kstrtol(buf, 10, &val);
	if (ret)
		return ret;

	tmp = val == 8 ? 0xc0 :
	      val == 4 ? 0x80 :
	      val == 2 ? 0x40 :
	      val == 1 ? 0x00 :
	      0xff;
	if (tmp == 0xff)
		return -EINVAL;

	mutex_lock(&data->update_lock);
	/* Get fresh readings */
	data->fan_div[nr] = adm1031_read_value(client,
					       ADM1031_REG_FAN_DIV(nr));
	data->fan_min[nr] = adm1031_read_value(client,
					       ADM1031_REG_FAN_MIN(nr));

	/* Write the new clock divider and fan min */
	old_div = FAN_DIV_FROM_REG(data->fan_div[nr]);
	data->fan_div[nr] = tmp | (0x3f & data->fan_div[nr]);
	new_min = data->fan_min[nr] * old_div / val;
	data->fan_min[nr] = new_min > 0xff ? 0xff : new_min;

	adm1031_write_value(client, ADM1031_REG_FAN_DIV(nr),
			    data->fan_div[nr]);
	adm1031_write_value(client, ADM1031_REG_FAN_MIN(nr),
			    data->fan_min[nr]);

	/* Invalidate the cache: fan speed is no longer valid */
	data->valid = 0;
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_temp(struct device *dev,
			 struct device_attribute *attr, char *buf)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct adm1031_data *data = adm1031_update_device(dev);
	int ext;
	ext = nr == 0 ?
	    ((data->ext_temp[nr] >> 6) & 0x3) * 2 :
	    (((data->ext_temp[nr] >> ((nr - 1) * 3)) & 7));
	return sprintf(buf, "%d\n", TEMP_FROM_REG_EXT(data->temp[nr], ext));
}

__attribute__((used)) static ssize_t show_temp_offset(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct adm1031_data *data = adm1031_update_device(dev);
	return sprintf(buf, "%d\n",
		       TEMP_OFFSET_FROM_REG(data->temp_offset[nr]));
}

__attribute__((used)) static ssize_t show_temp_min(struct device *dev,
			     struct device_attribute *attr, char *buf)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct adm1031_data *data = adm1031_update_device(dev);
	return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp_min[nr]));
}

__attribute__((used)) static ssize_t show_temp_max(struct device *dev,
			     struct device_attribute *attr, char *buf)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct adm1031_data *data = adm1031_update_device(dev);
	return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp_max[nr]));
}

__attribute__((used)) static ssize_t show_temp_crit(struct device *dev,
			      struct device_attribute *attr, char *buf)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct adm1031_data *data = adm1031_update_device(dev);
	return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp_crit[nr]));
}

__attribute__((used)) static ssize_t set_temp_offset(struct device *dev,
			       struct device_attribute *attr, const char *buf,
			       size_t count)
{
	struct adm1031_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	int nr = to_sensor_dev_attr(attr)->index;
	long val;
	int ret;

	ret = kstrtol(buf, 10, &val);
	if (ret)
		return ret;

	val = clamp_val(val, -15000, 15000);
	mutex_lock(&data->update_lock);
	data->temp_offset[nr] = TEMP_OFFSET_TO_REG(val);
	adm1031_write_value(client, ADM1031_REG_TEMP_OFFSET(nr),
			    data->temp_offset[nr]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t set_temp_min(struct device *dev, struct device_attribute *attr,
			    const char *buf, size_t count)
{
	struct adm1031_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	int nr = to_sensor_dev_attr(attr)->index;
	long val;
	int ret;

	ret = kstrtol(buf, 10, &val);
	if (ret)
		return ret;

	val = clamp_val(val, -55000, 127000);
	mutex_lock(&data->update_lock);
	data->temp_min[nr] = TEMP_TO_REG(val);
	adm1031_write_value(client, ADM1031_REG_TEMP_MIN(nr),
			    data->temp_min[nr]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t set_temp_max(struct device *dev, struct device_attribute *attr,
			    const char *buf, size_t count)
{
	struct adm1031_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	int nr = to_sensor_dev_attr(attr)->index;
	long val;
	int ret;

	ret = kstrtol(buf, 10, &val);
	if (ret)
		return ret;

	val = clamp_val(val, -55000, 127000);
	mutex_lock(&data->update_lock);
	data->temp_max[nr] = TEMP_TO_REG(val);
	adm1031_write_value(client, ADM1031_REG_TEMP_MAX(nr),
			    data->temp_max[nr]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t set_temp_crit(struct device *dev, struct device_attribute *attr,
			     const char *buf, size_t count)
{
	struct adm1031_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	int nr = to_sensor_dev_attr(attr)->index;
	long val;
	int ret;

	ret = kstrtol(buf, 10, &val);
	if (ret)
		return ret;

	val = clamp_val(val, -55000, 127000);
	mutex_lock(&data->update_lock);
	data->temp_crit[nr] = TEMP_TO_REG(val);
	adm1031_write_value(client, ADM1031_REG_TEMP_CRIT(nr),
			    data->temp_crit[nr]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t alarms_show(struct device *dev, struct device_attribute *attr,
			   char *buf)
{
	struct adm1031_data *data = adm1031_update_device(dev);
	return sprintf(buf, "%d\n", data->alarm);
}

__attribute__((used)) static ssize_t show_alarm(struct device *dev,
			  struct device_attribute *attr, char *buf)
{
	int bitnr = to_sensor_dev_attr(attr)->index;
	struct adm1031_data *data = adm1031_update_device(dev);
	return sprintf(buf, "%d\n", (data->alarm >> bitnr) & 1);
}

__attribute__((used)) static ssize_t update_interval_show(struct device *dev,
				    struct device_attribute *attr, char *buf)
{
	struct adm1031_data *data = dev_get_drvdata(dev);

	return sprintf(buf, "%u\n", data->update_interval);
}

__attribute__((used)) static ssize_t update_interval_store(struct device *dev,
				     struct device_attribute *attr,
				     const char *buf, size_t count)
{
	struct adm1031_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	unsigned long val;
	int i, err;
	u8 reg;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	/*
	 * Find the nearest update interval from the table.
	 * Use it to determine the matching update rate.
	 */
	for (i = 0; i < ARRAY_SIZE(update_intervals) - 1; i++) {
		if (val >= update_intervals[i])
			break;
	}
	/* if not found, we point to the last entry (lowest update interval) */

	/* set the new update rate while preserving other settings */
	reg = adm1031_read_value(client, ADM1031_REG_FAN_FILTER);
	reg &= ~ADM1031_UPDATE_RATE_MASK;
	reg |= i << ADM1031_UPDATE_RATE_SHIFT;
	adm1031_write_value(client, ADM1031_REG_FAN_FILTER, reg);

	mutex_lock(&data->update_lock);
	data->update_interval = update_intervals[i];
	mutex_unlock(&data->update_lock);

	return count;
}

__attribute__((used)) static int adm1031_detect(struct i2c_client *client,
			  struct i2c_board_info *info)
{
	struct i2c_adapter *adapter = client->adapter;
	const char *name;
	int id, co;

	if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
		return -ENODEV;

	id = i2c_smbus_read_byte_data(client, 0x3d);
	co = i2c_smbus_read_byte_data(client, 0x3e);

	if (!((id == 0x31 || id == 0x30) && co == 0x41))
		return -ENODEV;
	name = (id == 0x30) ? "adm1030" : "adm1031";

	strlcpy(info->type, name, I2C_NAME_SIZE);

	return 0;
}

__attribute__((used)) static void adm1031_init_client(struct i2c_client *client)
{
	unsigned int read_val;
	unsigned int mask;
	int i;
	struct adm1031_data *data = i2c_get_clientdata(client);

	mask = (ADM1031_CONF2_PWM1_ENABLE | ADM1031_CONF2_TACH1_ENABLE);
	if (data->chip_type == adm1031) {
		mask |= (ADM1031_CONF2_PWM2_ENABLE |
			ADM1031_CONF2_TACH2_ENABLE);
	}
	/* Initialize the ADM1031 chip (enables fan speed reading ) */
	read_val = adm1031_read_value(client, ADM1031_REG_CONF2);
	if ((read_val | mask) != read_val)
		adm1031_write_value(client, ADM1031_REG_CONF2, read_val | mask);

	read_val = adm1031_read_value(client, ADM1031_REG_CONF1);
	if ((read_val | ADM1031_CONF1_MONITOR_ENABLE) != read_val) {
		adm1031_write_value(client, ADM1031_REG_CONF1,
				    read_val | ADM1031_CONF1_MONITOR_ENABLE);
	}

	/* Read the chip's update rate */
	mask = ADM1031_UPDATE_RATE_MASK;
	read_val = adm1031_read_value(client, ADM1031_REG_FAN_FILTER);
	i = (read_val & mask) >> ADM1031_UPDATE_RATE_SHIFT;
	/* Save it as update interval */
	data->update_interval = update_intervals[i];
}

__attribute__((used)) static int adm1031_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	struct device *dev = &client->dev;
	struct device *hwmon_dev;
	struct adm1031_data *data;

	data = devm_kzalloc(dev, sizeof(struct adm1031_data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	i2c_set_clientdata(client, data);
	data->client = client;
	data->chip_type = id->driver_data;
	mutex_init(&data->update_lock);

	if (data->chip_type == adm1030)
		data->chan_select_table = &auto_channel_select_table_adm1030;
	else
		data->chan_select_table = &auto_channel_select_table_adm1031;

	/* Initialize the ADM1031 chip */
	adm1031_init_client(client);

	/* sysfs hooks */
	data->groups[0] = &adm1031_group;
	if (data->chip_type == adm1031)
		data->groups[1] = &adm1031_group_opt;

	hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
							   data, data->groups);
	return PTR_ERR_OR_ZERO(hwmon_dev);
}

