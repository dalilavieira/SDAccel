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
typedef  int u16 ;
struct w83l786ng_data {int valid; int* in; int* in_min; int* in_max; int* fan; int* fan_min; int* fan_div; int* pwm_mode; int* pwm_enable; int* pwm; int** temp; int* tolerance; int /*<<< orphan*/  update_lock; struct i2c_client* client; scalar_t__ last_updated; } ;
struct sensor_device_attribute_2 {int nr; int index; } ;
struct i2c_device_id {int dummy; } ;
struct device {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  name; struct device dev; int /*<<< orphan*/  addr; struct i2c_adapter* adapter; } ;
struct i2c_board_info {int /*<<< orphan*/  type; } ;
struct i2c_adapter {int /*<<< orphan*/  dev; } ;
struct device_attribute {int dummy; } ;
typedef  int ssize_t ;
struct TYPE_2__ {int index; } ;

/* Variables and functions */
 int DIV_FROM_REG (int) ; 
 unsigned long DIV_ROUND_CLOSEST (unsigned long,int) ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 unsigned long FAN_FROM_REG (int,int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HZ ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_BYTE_DATA ; 
 int /*<<< orphan*/  I2C_NAME_SIZE ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
 int TEMP_FROM_REG (int) ; 
 int TEMP_TO_REG (long) ; 
 int* W83L786NG_PWM_ENABLE_SHIFT ; 
 int* W83L786NG_PWM_MODE_SHIFT ; 
 int W83L786NG_REG_CHIP_ID ; 
 int W83L786NG_REG_CONFIG ; 
 int W83L786NG_REG_FAN (int) ; 
 int W83L786NG_REG_FAN_CFG ; 
 int W83L786NG_REG_FAN_DIV ; 
 int W83L786NG_REG_FAN_MIN (int) ; 
 int W83L786NG_REG_IN (int) ; 
 int W83L786NG_REG_IN_MAX (int) ; 
 int W83L786NG_REG_IN_MIN (int) ; 
 int W83L786NG_REG_MAN_ID1 ; 
 int W83L786NG_REG_MAN_ID2 ; 
 int* W83L786NG_REG_PWM ; 
 int** W83L786NG_REG_TEMP ; 
 int W83L786NG_REG_TOLERANCE ; 
 int clamp_val (unsigned long,int,int) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,...) ; 
 struct w83l786ng_data* dev_get_drvdata (struct device*) ; 
 struct device* devm_hwmon_device_register_with_groups (struct device*,int /*<<< orphan*/ ,struct w83l786ng_data*,int /*<<< orphan*/ ) ; 
 struct w83l786ng_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int,int) ; 
 scalar_t__ jiffies ; 
 int kstrtol (char const*,int,long*) ; 
 int kstrtoul (char const*,int,unsigned long*) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 scalar_t__ reset ; 
 int sprintf (char*,char*,long) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 scalar_t__ time_after (scalar_t__,scalar_t__) ; 
 TYPE_1__* to_sensor_dev_attr (struct device_attribute*) ; 
 struct sensor_device_attribute_2* to_sensor_dev_attr_2 (struct device_attribute*) ; 
 int /*<<< orphan*/  w83l786ng_groups ; 

__attribute__((used)) static inline u8
FAN_TO_REG(long rpm, int div)
{
	if (rpm == 0)
		return 255;
	rpm = clamp_val(rpm, 1, 1000000);
	return clamp_val((1350000 + rpm * div / 2) / (rpm * div), 1, 254);
}

__attribute__((used)) static inline u8
DIV_TO_REG(long val)
{
	int i;
	val = clamp_val(val, 1, 128) >> 1;
	for (i = 0; i < 7; i++) {
		if (val == 0)
			break;
		val >>= 1;
	}
	return (u8)i;
}

__attribute__((used)) static u8
w83l786ng_read_value(struct i2c_client *client, u8 reg)
{
	return i2c_smbus_read_byte_data(client, reg);
}

__attribute__((used)) static int
w83l786ng_write_value(struct i2c_client *client, u8 reg, u8 value)
{
	return i2c_smbus_write_byte_data(client, reg, value);
}

__attribute__((used)) static struct w83l786ng_data *w83l786ng_update_device(struct device *dev)
{
	struct w83l786ng_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	int i, j;
	u8 reg_tmp, pwmcfg;

	mutex_lock(&data->update_lock);
	if (time_after(jiffies, data->last_updated + HZ + HZ / 2)
	    || !data->valid) {
		dev_dbg(&client->dev, "Updating w83l786ng data.\n");

		/* Update the voltages measured value and limits */
		for (i = 0; i < 3; i++) {
			data->in[i] = w83l786ng_read_value(client,
			    W83L786NG_REG_IN(i));
			data->in_min[i] = w83l786ng_read_value(client,
			    W83L786NG_REG_IN_MIN(i));
			data->in_max[i] = w83l786ng_read_value(client,
			    W83L786NG_REG_IN_MAX(i));
		}

		/* Update the fan counts and limits */
		for (i = 0; i < 2; i++) {
			data->fan[i] = w83l786ng_read_value(client,
			    W83L786NG_REG_FAN(i));
			data->fan_min[i] = w83l786ng_read_value(client,
			    W83L786NG_REG_FAN_MIN(i));
		}

		/* Update the fan divisor */
		reg_tmp = w83l786ng_read_value(client, W83L786NG_REG_FAN_DIV);
		data->fan_div[0] = reg_tmp & 0x07;
		data->fan_div[1] = (reg_tmp >> 4) & 0x07;

		pwmcfg = w83l786ng_read_value(client, W83L786NG_REG_FAN_CFG);
		for (i = 0; i < 2; i++) {
			data->pwm_mode[i] =
			    ((pwmcfg >> W83L786NG_PWM_MODE_SHIFT[i]) & 1)
			    ? 0 : 1;
			data->pwm_enable[i] =
			    ((pwmcfg >> W83L786NG_PWM_ENABLE_SHIFT[i]) & 3) + 1;
			data->pwm[i] =
			    (w83l786ng_read_value(client, W83L786NG_REG_PWM[i])
			     & 0x0f) * 0x11;
		}


		/* Update the temperature sensors */
		for (i = 0; i < 2; i++) {
			for (j = 0; j < 3; j++) {
				data->temp[i][j] = w83l786ng_read_value(client,
				    W83L786NG_REG_TEMP[i][j]);
			}
		}

		/* Update Smart Fan I/II tolerance */
		reg_tmp = w83l786ng_read_value(client, W83L786NG_REG_TOLERANCE);
		data->tolerance[0] = reg_tmp & 0x0f;
		data->tolerance[1] = (reg_tmp >> 4) & 0x0f;

		data->last_updated = jiffies;
		data->valid = 1;

	}

	mutex_unlock(&data->update_lock);

	return data;
}

__attribute__((used)) static ssize_t
store_fan_min(struct device *dev, struct device_attribute *attr,
	      const char *buf, size_t count)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct w83l786ng_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	data->fan_min[nr] = FAN_TO_REG(val, DIV_FROM_REG(data->fan_div[nr]));
	w83l786ng_write_value(client, W83L786NG_REG_FAN_MIN(nr),
			      data->fan_min[nr]);
	mutex_unlock(&data->update_lock);

	return count;
}

__attribute__((used)) static ssize_t
show_fan_div(struct device *dev, struct device_attribute *attr,
	     char *buf)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct w83l786ng_data *data = w83l786ng_update_device(dev);
	return sprintf(buf, "%u\n", DIV_FROM_REG(data->fan_div[nr]));
}

__attribute__((used)) static ssize_t
store_fan_div(struct device *dev, struct device_attribute *attr,
	      const char *buf, size_t count)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct w83l786ng_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;

	unsigned long min;
	u8 tmp_fan_div;
	u8 fan_div_reg;
	u8 keep_mask = 0;
	u8 new_shift = 0;

	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	/* Save fan_min */
	mutex_lock(&data->update_lock);
	min = FAN_FROM_REG(data->fan_min[nr], DIV_FROM_REG(data->fan_div[nr]));

	data->fan_div[nr] = DIV_TO_REG(val);

	switch (nr) {
	case 0:
		keep_mask = 0xf8;
		new_shift = 0;
		break;
	case 1:
		keep_mask = 0x8f;
		new_shift = 4;
		break;
	}

	fan_div_reg = w83l786ng_read_value(client, W83L786NG_REG_FAN_DIV)
					   & keep_mask;

	tmp_fan_div = (data->fan_div[nr] << new_shift) & ~keep_mask;

	w83l786ng_write_value(client, W83L786NG_REG_FAN_DIV,
			      fan_div_reg | tmp_fan_div);

	/* Restore fan_min */
	data->fan_min[nr] = FAN_TO_REG(min, DIV_FROM_REG(data->fan_div[nr]));
	w83l786ng_write_value(client, W83L786NG_REG_FAN_MIN(nr),
			      data->fan_min[nr]);
	mutex_unlock(&data->update_lock);

	return count;
}

__attribute__((used)) static ssize_t
show_temp(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct sensor_device_attribute_2 *sensor_attr =
	    to_sensor_dev_attr_2(attr);
	int nr = sensor_attr->nr;
	int index = sensor_attr->index;
	struct w83l786ng_data *data = w83l786ng_update_device(dev);
	return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp[nr][index]));
}

__attribute__((used)) static ssize_t
store_temp(struct device *dev, struct device_attribute *attr,
	   const char *buf, size_t count)
{
	struct sensor_device_attribute_2 *sensor_attr =
	    to_sensor_dev_attr_2(attr);
	int nr = sensor_attr->nr;
	int index = sensor_attr->index;
	struct w83l786ng_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	long val;
	int err;

	err = kstrtol(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	data->temp[nr][index] = TEMP_TO_REG(val);
	w83l786ng_write_value(client, W83L786NG_REG_TEMP[nr][index],
			      data->temp[nr][index]);
	mutex_unlock(&data->update_lock);

	return count;
}

__attribute__((used)) static ssize_t
store_pwm_mode(struct device *dev, struct device_attribute *attr,
	       const char *buf, size_t count)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct w83l786ng_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	u8 reg;
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	if (val > 1)
		return -EINVAL;
	mutex_lock(&data->update_lock);
	data->pwm_mode[nr] = val;
	reg = w83l786ng_read_value(client, W83L786NG_REG_FAN_CFG);
	reg &= ~(1 << W83L786NG_PWM_MODE_SHIFT[nr]);
	if (!val)
		reg |= 1 << W83L786NG_PWM_MODE_SHIFT[nr];
	w83l786ng_write_value(client, W83L786NG_REG_FAN_CFG, reg);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t
store_pwm(struct device *dev, struct device_attribute *attr,
	  const char *buf, size_t count)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct w83l786ng_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;
	val = clamp_val(val, 0, 255);
	val = DIV_ROUND_CLOSEST(val, 0x11);

	mutex_lock(&data->update_lock);
	data->pwm[nr] = val * 0x11;
	val |= w83l786ng_read_value(client, W83L786NG_REG_PWM[nr]) & 0xf0;
	w83l786ng_write_value(client, W83L786NG_REG_PWM[nr], val);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t
store_pwm_enable(struct device *dev, struct device_attribute *attr,
		 const char *buf, size_t count)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct w83l786ng_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	u8 reg;
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	if (!val || val > 2)  /* only modes 1 and 2 are supported */
		return -EINVAL;

	mutex_lock(&data->update_lock);
	reg = w83l786ng_read_value(client, W83L786NG_REG_FAN_CFG);
	data->pwm_enable[nr] = val;
	reg &= ~(0x03 << W83L786NG_PWM_ENABLE_SHIFT[nr]);
	reg |= (val - 1) << W83L786NG_PWM_ENABLE_SHIFT[nr];
	w83l786ng_write_value(client, W83L786NG_REG_FAN_CFG, reg);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t
show_tolerance(struct device *dev, struct device_attribute *attr, char *buf)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct w83l786ng_data *data = w83l786ng_update_device(dev);
	return sprintf(buf, "%ld\n", (long)data->tolerance[nr]);
}

__attribute__((used)) static ssize_t
store_tolerance(struct device *dev, struct device_attribute *attr,
		const char *buf, size_t count)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct w83l786ng_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	u8 tol_tmp, tol_mask;
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	tol_mask = w83l786ng_read_value(client,
	    W83L786NG_REG_TOLERANCE) & ((nr == 1) ? 0x0f : 0xf0);
	tol_tmp = clamp_val(val, 0, 15);
	tol_tmp &= 0x0f;
	data->tolerance[nr] = tol_tmp;
	if (nr == 1)
		tol_tmp <<= 4;

	w83l786ng_write_value(client, W83L786NG_REG_TOLERANCE,
			      tol_mask | tol_tmp);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static int
w83l786ng_detect(struct i2c_client *client, struct i2c_board_info *info)
{
	struct i2c_adapter *adapter = client->adapter;
	u16 man_id;
	u8 chip_id;

	if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
		return -ENODEV;

	/* Detection */
	if ((w83l786ng_read_value(client, W83L786NG_REG_CONFIG) & 0x80)) {
		dev_dbg(&adapter->dev, "W83L786NG detection failed at 0x%02x\n",
			client->addr);
		return -ENODEV;
	}

	/* Identification */
	man_id = (w83l786ng_read_value(client, W83L786NG_REG_MAN_ID1) << 8) +
		 w83l786ng_read_value(client, W83L786NG_REG_MAN_ID2);
	chip_id = w83l786ng_read_value(client, W83L786NG_REG_CHIP_ID);

	if (man_id != 0x5CA3 ||		/* Winbond */
	    chip_id != 0x80) {		/* W83L786NG */
		dev_dbg(&adapter->dev,
			"Unsupported chip (man_id=0x%04X, chip_id=0x%02X)\n",
			man_id, chip_id);
		return -ENODEV;
	}

	strlcpy(info->type, "w83l786ng", I2C_NAME_SIZE);

	return 0;
}

__attribute__((used)) static void w83l786ng_init_client(struct i2c_client *client)
{
	u8 tmp;

	if (reset)
		w83l786ng_write_value(client, W83L786NG_REG_CONFIG, 0x80);

	/* Start monitoring */
	tmp = w83l786ng_read_value(client, W83L786NG_REG_CONFIG);
	if (!(tmp & 0x01))
		w83l786ng_write_value(client, W83L786NG_REG_CONFIG, tmp | 0x01);
}

__attribute__((used)) static int
w83l786ng_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	struct device *dev = &client->dev;
	struct w83l786ng_data *data;
	struct device *hwmon_dev;
	int i;
	u8 reg_tmp;

	data = devm_kzalloc(dev, sizeof(struct w83l786ng_data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->client = client;
	mutex_init(&data->update_lock);

	/* Initialize the chip */
	w83l786ng_init_client(client);

	/* A few vars need to be filled upon startup */
	for (i = 0; i < 2; i++) {
		data->fan_min[i] = w83l786ng_read_value(client,
		    W83L786NG_REG_FAN_MIN(i));
	}

	/* Update the fan divisor */
	reg_tmp = w83l786ng_read_value(client, W83L786NG_REG_FAN_DIV);
	data->fan_div[0] = reg_tmp & 0x07;
	data->fan_div[1] = (reg_tmp >> 4) & 0x07;

	hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
							   data,
							   w83l786ng_groups);
	return PTR_ERR_OR_ZERO(hwmon_dev);
}

