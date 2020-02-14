#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  unsigned long u8 ;
struct sensor_device_attribute {size_t index; } ;
struct lm78_data {int* in; int* in_min; int* in_max; int temp; int temp_over; int temp_hyst; unsigned long* fan; int* fan_div; unsigned long* fan_min; int vid; int alarms; scalar_t__ type; int valid; int /*<<< orphan*/  update_lock; scalar_t__ last_updated; struct i2c_client* client; } ;
struct i2c_device_id {scalar_t__ driver_data; } ;
struct device {int dummy; } ;
struct i2c_client {int addr; int /*<<< orphan*/  name; struct device dev; struct i2c_adapter* adapter; } ;
struct i2c_board_info {int /*<<< orphan*/  type; } ;
struct i2c_adapter {int /*<<< orphan*/  dev; } ;
struct device_attribute {int dummy; } ;
typedef  int ssize_t ;
typedef  int s8 ;

/* Variables and functions */
 int DIV_FROM_REG (int) ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HZ ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_BYTE_DATA ; 
 int /*<<< orphan*/  I2C_NAME_SIZE ; 
 int IN_FROM_REG (int) ; 
 unsigned long LM78_REG_ALARM1 ; 
 unsigned long LM78_REG_ALARM2 ; 
 unsigned long LM78_REG_CHIPID ; 
 unsigned long LM78_REG_CONFIG ; 
 unsigned long LM78_REG_FAN (int) ; 
 unsigned long LM78_REG_FAN_MIN (int) ; 
 unsigned long LM78_REG_I2C_ADDR ; 
 unsigned long LM78_REG_IN (int) ; 
 unsigned long LM78_REG_IN_MAX (int) ; 
 unsigned long LM78_REG_IN_MIN (int) ; 
 unsigned long LM78_REG_TEMP ; 
 unsigned long LM78_REG_TEMP_HYST ; 
 unsigned long LM78_REG_TEMP_OVER ; 
 unsigned long LM78_REG_VID_FANDIV ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
 unsigned long clamp_val (long,int,int) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,unsigned long) ; 
 struct lm78_data* dev_get_drvdata (struct device*) ; 
 struct device* devm_hwmon_device_register_with_groups (struct device*,int /*<<< orphan*/ ,struct lm78_data*,int /*<<< orphan*/ ) ; 
 struct lm78_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,unsigned long) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,unsigned long,unsigned long) ; 
 scalar_t__ jiffies ; 
 int kstrtol (char const*,int,long*) ; 
 int kstrtoul (char const*,int,unsigned long*) ; 
 int /*<<< orphan*/  lm78_groups ; 
static  void lm78_init_device (struct lm78_data*) ; 
static  int lm78_read_value (struct lm78_data*,unsigned long) ; 
static  struct lm78_data* lm78_update_device (struct device*) ; 
static  int lm78_write_value (struct lm78_data*,unsigned long,unsigned long) ; 
 scalar_t__ lm79 ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int sprintf (char*,char*,int) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ ) ; 
 scalar_t__ time_after (scalar_t__,scalar_t__) ; 
 struct sensor_device_attribute* to_sensor_dev_attr (struct device_attribute*) ; 
 int vid_from_reg (int,int) ; 

__attribute__((used)) static inline u8 IN_TO_REG(unsigned long val)
{
	unsigned long nval = clamp_val(val, 0, 4080);
	return (nval + 8) / 16;
}

__attribute__((used)) static inline u8 FAN_TO_REG(long rpm, int div)
{
	if (rpm <= 0)
		return 255;
	if (rpm > 1350000)
		return 1;
	return clamp_val((1350000 + rpm * div / 2) / (rpm * div), 1, 254);
}

__attribute__((used)) static inline int FAN_FROM_REG(u8 val, int div)
{
	return val == 0 ? -1 : val == 255 ? 0 : 1350000 / (val * div);
}

__attribute__((used)) static inline s8 TEMP_TO_REG(long val)
{
	int nval = clamp_val(val, -128000, 127000) ;
	return nval < 0 ? (nval - 500) / 1000 : (nval + 500) / 1000;
}

__attribute__((used)) static inline int TEMP_FROM_REG(s8 val)
{
	return val * 1000;
}

__attribute__((used)) static ssize_t show_in(struct device *dev, struct device_attribute *da,
		       char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
	struct lm78_data *data = lm78_update_device(dev);
	return sprintf(buf, "%d\n", IN_FROM_REG(data->in[attr->index]));
}

__attribute__((used)) static ssize_t show_in_min(struct device *dev, struct device_attribute *da,
			   char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
	struct lm78_data *data = lm78_update_device(dev);
	return sprintf(buf, "%d\n", IN_FROM_REG(data->in_min[attr->index]));
}

__attribute__((used)) static ssize_t show_in_max(struct device *dev, struct device_attribute *da,
			   char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
	struct lm78_data *data = lm78_update_device(dev);
	return sprintf(buf, "%d\n", IN_FROM_REG(data->in_max[attr->index]));
}

__attribute__((used)) static ssize_t set_in_min(struct device *dev, struct device_attribute *da,
			  const char *buf, size_t count)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
	struct lm78_data *data = dev_get_drvdata(dev);
	int nr = attr->index;
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	data->in_min[nr] = IN_TO_REG(val);
	lm78_write_value(data, LM78_REG_IN_MIN(nr), data->in_min[nr]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t set_in_max(struct device *dev, struct device_attribute *da,
			  const char *buf, size_t count)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
	struct lm78_data *data = dev_get_drvdata(dev);
	int nr = attr->index;
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	data->in_max[nr] = IN_TO_REG(val);
	lm78_write_value(data, LM78_REG_IN_MAX(nr), data->in_max[nr]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t temp1_input_show(struct device *dev,
				struct device_attribute *da, char *buf)
{
	struct lm78_data *data = lm78_update_device(dev);
	return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp));
}

__attribute__((used)) static ssize_t temp1_max_show(struct device *dev, struct device_attribute *da,
			      char *buf)
{
	struct lm78_data *data = lm78_update_device(dev);
	return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp_over));
}

__attribute__((used)) static ssize_t temp1_max_store(struct device *dev,
			       struct device_attribute *da, const char *buf,
			       size_t count)
{
	struct lm78_data *data = dev_get_drvdata(dev);
	long val;
	int err;

	err = kstrtol(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	data->temp_over = TEMP_TO_REG(val);
	lm78_write_value(data, LM78_REG_TEMP_OVER, data->temp_over);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t temp1_max_hyst_show(struct device *dev,
				   struct device_attribute *da, char *buf)
{
	struct lm78_data *data = lm78_update_device(dev);
	return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp_hyst));
}

__attribute__((used)) static ssize_t temp1_max_hyst_store(struct device *dev,
				    struct device_attribute *da,
				    const char *buf, size_t count)
{
	struct lm78_data *data = dev_get_drvdata(dev);
	long val;
	int err;

	err = kstrtol(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	data->temp_hyst = TEMP_TO_REG(val);
	lm78_write_value(data, LM78_REG_TEMP_HYST, data->temp_hyst);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_fan(struct device *dev, struct device_attribute *da,
			char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
	struct lm78_data *data = lm78_update_device(dev);
	int nr = attr->index;
	return sprintf(buf, "%d\n", FAN_FROM_REG(data->fan[nr],
		DIV_FROM_REG(data->fan_div[nr])));
}

__attribute__((used)) static ssize_t show_fan_min(struct device *dev, struct device_attribute *da,
			    char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
	struct lm78_data *data = lm78_update_device(dev);
	int nr = attr->index;
	return sprintf(buf, "%d\n", FAN_FROM_REG(data->fan_min[nr],
		DIV_FROM_REG(data->fan_div[nr])));
}

__attribute__((used)) static ssize_t set_fan_min(struct device *dev, struct device_attribute *da,
			   const char *buf, size_t count)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
	struct lm78_data *data = dev_get_drvdata(dev);
	int nr = attr->index;
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	data->fan_min[nr] = FAN_TO_REG(val, DIV_FROM_REG(data->fan_div[nr]));
	lm78_write_value(data, LM78_REG_FAN_MIN(nr), data->fan_min[nr]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_fan_div(struct device *dev, struct device_attribute *da,
			    char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
	struct lm78_data *data = lm78_update_device(dev);
	return sprintf(buf, "%d\n", DIV_FROM_REG(data->fan_div[attr->index]));
}

__attribute__((used)) static ssize_t set_fan_div(struct device *dev, struct device_attribute *da,
			   const char *buf, size_t count)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
	struct lm78_data *data = dev_get_drvdata(dev);
	int nr = attr->index;
	unsigned long min;
	u8 reg;
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	min = FAN_FROM_REG(data->fan_min[nr],
			   DIV_FROM_REG(data->fan_div[nr]));

	switch (val) {
	case 1:
		data->fan_div[nr] = 0;
		break;
	case 2:
		data->fan_div[nr] = 1;
		break;
	case 4:
		data->fan_div[nr] = 2;
		break;
	case 8:
		data->fan_div[nr] = 3;
		break;
	default:
		dev_err(dev,
			"fan_div value %ld not supported. Choose one of 1, 2, 4 or 8!\n",
			val);
		mutex_unlock(&data->update_lock);
		return -EINVAL;
	}

	reg = lm78_read_value(data, LM78_REG_VID_FANDIV);
	switch (nr) {
	case 0:
		reg = (reg & 0xcf) | (data->fan_div[nr] << 4);
		break;
	case 1:
		reg = (reg & 0x3f) | (data->fan_div[nr] << 6);
		break;
	}
	lm78_write_value(data, LM78_REG_VID_FANDIV, reg);

	data->fan_min[nr] =
		FAN_TO_REG(min, DIV_FROM_REG(data->fan_div[nr]));
	lm78_write_value(data, LM78_REG_FAN_MIN(nr), data->fan_min[nr]);
	mutex_unlock(&data->update_lock);

	return count;
}

__attribute__((used)) static ssize_t cpu0_vid_show(struct device *dev, struct device_attribute *da,
			     char *buf)
{
	struct lm78_data *data = lm78_update_device(dev);
	return sprintf(buf, "%d\n", vid_from_reg(data->vid, 82));
}

__attribute__((used)) static ssize_t alarms_show(struct device *dev, struct device_attribute *da,
			   char *buf)
{
	struct lm78_data *data = lm78_update_device(dev);
	return sprintf(buf, "%u\n", data->alarms);
}

__attribute__((used)) static ssize_t show_alarm(struct device *dev, struct device_attribute *da,
			  char *buf)
{
	struct lm78_data *data = lm78_update_device(dev);
	int nr = to_sensor_dev_attr(da)->index;
	return sprintf(buf, "%u\n", (data->alarms >> nr) & 1);
}

__attribute__((used)) static int lm78_alias_detect(struct i2c_client *client, u8 chipid)
{
	return 0;
}

__attribute__((used)) static struct lm78_data *lm78_data_if_isa(void)
{
	return NULL;
}

__attribute__((used)) static int lm78_i2c_detect(struct i2c_client *client,
			   struct i2c_board_info *info)
{
	int i;
	struct lm78_data *isa = lm78_data_if_isa();
	const char *client_name;
	struct i2c_adapter *adapter = client->adapter;
	int address = client->addr;

	if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
		return -ENODEV;

	/*
	 * We block updates of the ISA device to minimize the risk of
	 * concurrent access to the same LM78 chip through different
	 * interfaces.
	 */
	if (isa)
		mutex_lock(&isa->update_lock);

	if ((i2c_smbus_read_byte_data(client, LM78_REG_CONFIG) & 0x80)
	 || i2c_smbus_read_byte_data(client, LM78_REG_I2C_ADDR) != address)
		goto err_nodev;

	/* Explicitly prevent the misdetection of Winbond chips */
	i = i2c_smbus_read_byte_data(client, 0x4f);
	if (i == 0xa3 || i == 0x5c)
		goto err_nodev;

	/* Determine the chip type. */
	i = i2c_smbus_read_byte_data(client, LM78_REG_CHIPID);
	if (i == 0x00 || i == 0x20	/* LM78 */
	 || i == 0x40)			/* LM78-J */
		client_name = "lm78";
	else if ((i & 0xfe) == 0xc0)
		client_name = "lm79";
	else
		goto err_nodev;

	if (lm78_alias_detect(client, i)) {
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

__attribute__((used)) static int lm78_i2c_probe(struct i2c_client *client,
			  const struct i2c_device_id *id)
{
	struct device *dev = &client->dev;
	struct device *hwmon_dev;
	struct lm78_data *data;

	data = devm_kzalloc(dev, sizeof(struct lm78_data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->client = client;
	data->type = id->driver_data;

	/* Initialize the LM78 chip */
	lm78_init_device(data);

	hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
							   data, lm78_groups);
	return PTR_ERR_OR_ZERO(hwmon_dev);
}

__attribute__((used)) static int lm78_read_value(struct lm78_data *data, u8 reg)
{
	struct i2c_client *client = data->client;

#ifdef CONFIG_ISA
	if (!client) { /* ISA device */
		int res;
		mutex_lock(&data->lock);
		outb_p(reg, data->isa_addr + LM78_ADDR_REG_OFFSET);
		res = inb_p(data->isa_addr + LM78_DATA_REG_OFFSET);
		mutex_unlock(&data->lock);
		return res;
	} else
#endif
		return i2c_smbus_read_byte_data(client, reg);
}

__attribute__((used)) static int lm78_write_value(struct lm78_data *data, u8 reg, u8 value)
{
	struct i2c_client *client = data->client;

#ifdef CONFIG_ISA
	if (!client) { /* ISA device */
		mutex_lock(&data->lock);
		outb_p(reg, data->isa_addr + LM78_ADDR_REG_OFFSET);
		outb_p(value, data->isa_addr + LM78_DATA_REG_OFFSET);
		mutex_unlock(&data->lock);
		return 0;
	} else
#endif
		return i2c_smbus_write_byte_data(client, reg, value);
}

__attribute__((used)) static void lm78_init_device(struct lm78_data *data)
{
	u8 config;
	int i;

	/* Start monitoring */
	config = lm78_read_value(data, LM78_REG_CONFIG);
	if ((config & 0x09) != 0x01)
		lm78_write_value(data, LM78_REG_CONFIG,
				 (config & 0xf7) | 0x01);

	/* A few vars need to be filled upon startup */
	for (i = 0; i < 3; i++) {
		data->fan_min[i] = lm78_read_value(data,
					LM78_REG_FAN_MIN(i));
	}

	mutex_init(&data->update_lock);
}

__attribute__((used)) static struct lm78_data *lm78_update_device(struct device *dev)
{
	struct lm78_data *data = dev_get_drvdata(dev);
	int i;

	mutex_lock(&data->update_lock);

	if (time_after(jiffies, data->last_updated + HZ + HZ / 2)
	    || !data->valid) {

		dev_dbg(dev, "Starting lm78 update\n");

		for (i = 0; i <= 6; i++) {
			data->in[i] =
			    lm78_read_value(data, LM78_REG_IN(i));
			data->in_min[i] =
			    lm78_read_value(data, LM78_REG_IN_MIN(i));
			data->in_max[i] =
			    lm78_read_value(data, LM78_REG_IN_MAX(i));
		}
		for (i = 0; i < 3; i++) {
			data->fan[i] =
			    lm78_read_value(data, LM78_REG_FAN(i));
			data->fan_min[i] =
			    lm78_read_value(data, LM78_REG_FAN_MIN(i));
		}
		data->temp = lm78_read_value(data, LM78_REG_TEMP);
		data->temp_over =
		    lm78_read_value(data, LM78_REG_TEMP_OVER);
		data->temp_hyst =
		    lm78_read_value(data, LM78_REG_TEMP_HYST);
		i = lm78_read_value(data, LM78_REG_VID_FANDIV);
		data->vid = i & 0x0f;
		if (data->type == lm79)
			data->vid |=
			    (lm78_read_value(data, LM78_REG_CHIPID) &
			     0x01) << 4;
		else
			data->vid |= 0x10;
		data->fan_div[0] = (i >> 4) & 0x03;
		data->fan_div[1] = i >> 6;
		data->alarms = lm78_read_value(data, LM78_REG_ALARM1) +
		    (lm78_read_value(data, LM78_REG_ALARM2) << 8);
		data->last_updated = jiffies;
		data->valid = 1;

		data->fan_div[2] = 1;
	}

	mutex_unlock(&data->update_lock);

	return data;
}

