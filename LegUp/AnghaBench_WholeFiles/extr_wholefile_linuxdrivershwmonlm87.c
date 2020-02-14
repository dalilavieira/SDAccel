#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct regulator {int dummy; } ;
struct lm87_data {int valid; int channel; int* in; int* in_min; int* in_max; int* fan; int* fan_min; int* temp; int* temp_high; int* temp_low; int temp_crit_int; int temp_crit_ext; int* fan_div; int vid; int alarms; int aout; int* in_scale; int vrm; int config; int /*<<< orphan*/ ** attr_groups; int /*<<< orphan*/  update_lock; scalar_t__ last_updated; } ;
struct i2c_device_id {int dummy; } ;
struct TYPE_9__ {struct device_node* of_node; } ;
struct i2c_client {int /*<<< orphan*/  name; TYPE_2__ dev; int /*<<< orphan*/  addr; struct i2c_adapter* adapter; } ;
struct i2c_board_info {int /*<<< orphan*/  type; } ;
struct i2c_adapter {int /*<<< orphan*/  dev; } ;
struct device_node {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;
struct TYPE_8__ {int index; } ;

/* Variables and functions */
 int AOUT_FROM_REG (int) ; 
 int AOUT_TO_REG (long) ; 
 int CHAN_NO_FAN (int) ; 
 int CHAN_NO_VID ; 
 int CHAN_TEMP3 ; 
 int CHAN_VCC_5V ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 long FAN_DIV_FROM_REG (int) ; 
 int FAN_FROM_REG (int,long) ; 
 void* FAN_TO_REG (unsigned long,long) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ HZ ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_BYTE_DATA ; 
 int /*<<< orphan*/  I2C_NAME_SIZE ; 
 int IN_FROM_REG (int,int) ; 
 void* IN_TO_REG (long,int) ; 
 int /*<<< orphan*/  IS_ERR (struct regulator*) ; 
 int LM87_REG_AIN (int) ; 
 int LM87_REG_AIN_MAX (int) ; 
 int LM87_REG_AIN_MIN (int) ; 
 int LM87_REG_ALARMS1 ; 
 int LM87_REG_ALARMS2 ; 
 int LM87_REG_AOUT ; 
 int LM87_REG_CHANNEL_MODE ; 
 int LM87_REG_COMPANY_ID ; 
 int LM87_REG_CONFIG ; 
 int LM87_REG_FAN (int) ; 
 int LM87_REG_FAN_MIN (int) ; 
 int LM87_REG_IN (int) ; 
 int LM87_REG_IN_MAX (int) ; 
 int LM87_REG_IN_MIN (int) ; 
 int LM87_REG_REVISION ; 
 int* LM87_REG_TEMP ; 
 int* LM87_REG_TEMP_HIGH ; 
 int LM87_REG_TEMP_HW_EXT ; 
 int LM87_REG_TEMP_HW_EXT_LOCK ; 
 int LM87_REG_TEMP_HW_INT ; 
 int LM87_REG_TEMP_HW_INT_LOCK ; 
 int* LM87_REG_TEMP_LOW ; 
 int LM87_REG_VID4 ; 
 int LM87_REG_VID_FAN_DIV ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
 int TEMP_FROM_REG (int) ; 
 void* TEMP_TO_REG (long) ; 
 int /*<<< orphan*/  dev_dbg (TYPE_2__*,char*,...) ; 
 void* dev_get_drvdata (struct device*) ; 
 scalar_t__ dev_get_platdata (TYPE_2__*) ; 
 int devm_add_action (TYPE_2__*,void (*) (void*),struct i2c_client*) ; 
 struct device* devm_hwmon_device_register_with_groups (TYPE_2__*,int /*<<< orphan*/ ,struct i2c_client*,int /*<<< orphan*/ **) ; 
 struct lm87_data* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 struct regulator* devm_regulator_get_optional (TYPE_2__*,char*) ; 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int /*<<< orphan*/ ) ; 
 struct lm87_data* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct lm87_data*) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int,int) ; 
 scalar_t__ jiffies ; 
 int kstrtol (char const*,int,long*) ; 
 int kstrtoul (char const*,int,unsigned long*) ; 
 int /*<<< orphan*/  lm87_group ; 
 int /*<<< orphan*/  lm87_group_fan1 ; 
 int /*<<< orphan*/  lm87_group_fan2 ; 
 int /*<<< orphan*/  lm87_group_in0_5 ; 
 int /*<<< orphan*/  lm87_group_in6 ; 
 int /*<<< orphan*/  lm87_group_in7 ; 
 int /*<<< orphan*/  lm87_group_temp3 ; 
 int /*<<< orphan*/  lm87_group_vid ; 
 void* min (int,int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 scalar_t__ of_property_read_bool (struct device_node*,char*) ; 
 int regulator_get_voltage (struct regulator*) ; 
 int sprintf (char*,char*,int) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ ) ; 
 scalar_t__ time_after (scalar_t__,scalar_t__) ; 
 TYPE_1__* to_sensor_dev_attr (struct device_attribute*) ; 
 int vid_from_reg (int,int) ; 
 unsigned long vid_which_vrm () ; 

__attribute__((used)) static inline int lm87_read_value(struct i2c_client *client, u8 reg)
{
	return i2c_smbus_read_byte_data(client, reg);
}

__attribute__((used)) static inline int lm87_write_value(struct i2c_client *client, u8 reg, u8 value)
{
	return i2c_smbus_write_byte_data(client, reg, value);
}

__attribute__((used)) static struct lm87_data *lm87_update_device(struct device *dev)
{
	struct i2c_client *client = dev_get_drvdata(dev);
	struct lm87_data *data = i2c_get_clientdata(client);

	mutex_lock(&data->update_lock);

	if (time_after(jiffies, data->last_updated + HZ) || !data->valid) {
		int i, j;

		dev_dbg(&client->dev, "Updating data.\n");

		i = (data->channel & CHAN_TEMP3) ? 1 : 0;
		j = (data->channel & CHAN_TEMP3) ? 5 : 6;
		for (; i < j; i++) {
			data->in[i] = lm87_read_value(client,
				      LM87_REG_IN(i));
			data->in_min[i] = lm87_read_value(client,
					  LM87_REG_IN_MIN(i));
			data->in_max[i] = lm87_read_value(client,
					  LM87_REG_IN_MAX(i));
		}

		for (i = 0; i < 2; i++) {
			if (data->channel & CHAN_NO_FAN(i)) {
				data->in[6+i] = lm87_read_value(client,
						LM87_REG_AIN(i));
				data->in_max[6+i] = lm87_read_value(client,
						    LM87_REG_AIN_MAX(i));
				data->in_min[6+i] = lm87_read_value(client,
						    LM87_REG_AIN_MIN(i));

			} else {
				data->fan[i] = lm87_read_value(client,
					       LM87_REG_FAN(i));
				data->fan_min[i] = lm87_read_value(client,
						   LM87_REG_FAN_MIN(i));
			}
		}

		j = (data->channel & CHAN_TEMP3) ? 3 : 2;
		for (i = 0 ; i < j; i++) {
			data->temp[i] = lm87_read_value(client,
					LM87_REG_TEMP[i]);
			data->temp_high[i] = lm87_read_value(client,
					     LM87_REG_TEMP_HIGH[i]);
			data->temp_low[i] = lm87_read_value(client,
					    LM87_REG_TEMP_LOW[i]);
		}

		i = lm87_read_value(client, LM87_REG_TEMP_HW_INT_LOCK);
		j = lm87_read_value(client, LM87_REG_TEMP_HW_INT);
		data->temp_crit_int = min(i, j);

		i = lm87_read_value(client, LM87_REG_TEMP_HW_EXT_LOCK);
		j = lm87_read_value(client, LM87_REG_TEMP_HW_EXT);
		data->temp_crit_ext = min(i, j);

		i = lm87_read_value(client, LM87_REG_VID_FAN_DIV);
		data->fan_div[0] = (i >> 4) & 0x03;
		data->fan_div[1] = (i >> 6) & 0x03;
		data->vid = (i & 0x0F)
			  | (lm87_read_value(client, LM87_REG_VID4) & 0x01)
			     << 4;

		data->alarms = lm87_read_value(client, LM87_REG_ALARMS1)
			     | (lm87_read_value(client, LM87_REG_ALARMS2)
				<< 8);
		data->aout = lm87_read_value(client, LM87_REG_AOUT);

		data->last_updated = jiffies;
		data->valid = 1;
	}

	mutex_unlock(&data->update_lock);

	return data;
}

__attribute__((used)) static ssize_t show_in_input(struct device *dev, struct device_attribute *attr,
			     char *buf)
{
	struct lm87_data *data = lm87_update_device(dev);
	int nr = to_sensor_dev_attr(attr)->index;

	return sprintf(buf, "%u\n", IN_FROM_REG(data->in[nr],
		       data->in_scale[nr]));
}

__attribute__((used)) static ssize_t show_in_min(struct device *dev,
				     struct device_attribute *attr, char *buf)
{
	struct lm87_data *data = lm87_update_device(dev);
	int nr = to_sensor_dev_attr(attr)->index;

	return sprintf(buf, "%u\n", IN_FROM_REG(data->in_min[nr],
		       data->in_scale[nr]));
}

__attribute__((used)) static ssize_t show_in_max(struct device *dev,
				     struct device_attribute *attr, char *buf)
{
	struct lm87_data *data = lm87_update_device(dev);
	int nr = to_sensor_dev_attr(attr)->index;

	return sprintf(buf, "%u\n", IN_FROM_REG(data->in_max[nr],
		       data->in_scale[nr]));
}

__attribute__((used)) static ssize_t set_in_min(struct device *dev, struct device_attribute *attr,
			  const char *buf, size_t count)
{
	struct i2c_client *client = dev_get_drvdata(dev);
	struct lm87_data *data = i2c_get_clientdata(client);
	int nr = to_sensor_dev_attr(attr)->index;
	long val;
	int err;

	err = kstrtol(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	data->in_min[nr] = IN_TO_REG(val, data->in_scale[nr]);
	lm87_write_value(client, nr < 6 ? LM87_REG_IN_MIN(nr) :
			 LM87_REG_AIN_MIN(nr - 6), data->in_min[nr]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t set_in_max(struct device *dev,  struct device_attribute *attr,
			  const char *buf, size_t count)
{
	struct i2c_client *client = dev_get_drvdata(dev);
	struct lm87_data *data = i2c_get_clientdata(client);
	int nr = to_sensor_dev_attr(attr)->index;
	long val;
	int err;

	err = kstrtol(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	data->in_max[nr] = IN_TO_REG(val, data->in_scale[nr]);
	lm87_write_value(client, nr < 6 ? LM87_REG_IN_MAX(nr) :
			 LM87_REG_AIN_MAX(nr - 6), data->in_max[nr]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_temp_input(struct device *dev,
			       struct device_attribute *attr, char *buf)
{
	struct lm87_data *data = lm87_update_device(dev);
	int nr = to_sensor_dev_attr(attr)->index;

	return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp[nr]));
}

__attribute__((used)) static ssize_t show_temp_low(struct device *dev,
			     struct device_attribute *attr, char *buf)
{
	struct lm87_data *data = lm87_update_device(dev);
	int nr = to_sensor_dev_attr(attr)->index;

	return sprintf(buf, "%d\n",
		       TEMP_FROM_REG(data->temp_low[nr]));
}

__attribute__((used)) static ssize_t show_temp_high(struct device *dev,
			      struct device_attribute *attr, char *buf)
{
	struct lm87_data *data = lm87_update_device(dev);
	int nr = to_sensor_dev_attr(attr)->index;

	return sprintf(buf, "%d\n",
		       TEMP_FROM_REG(data->temp_high[nr]));
}

__attribute__((used)) static ssize_t set_temp_low(struct device *dev, struct device_attribute *attr,
			    const char *buf, size_t count)
{
	struct i2c_client *client = dev_get_drvdata(dev);
	struct lm87_data *data = i2c_get_clientdata(client);
	int nr = to_sensor_dev_attr(attr)->index;
	long val;
	int err;

	err = kstrtol(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	data->temp_low[nr] = TEMP_TO_REG(val);
	lm87_write_value(client, LM87_REG_TEMP_LOW[nr], data->temp_low[nr]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t set_temp_high(struct device *dev, struct device_attribute *attr,
			     const char *buf, size_t count)
{
	struct i2c_client *client = dev_get_drvdata(dev);
	struct lm87_data *data = i2c_get_clientdata(client);
	int nr = to_sensor_dev_attr(attr)->index;
	long val;
	int err;

	err = kstrtol(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	data->temp_high[nr] = TEMP_TO_REG(val);
	lm87_write_value(client, LM87_REG_TEMP_HIGH[nr], data->temp_high[nr]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t temp1_crit_show(struct device *dev,
			       struct device_attribute *attr, char *buf)
{
	struct lm87_data *data = lm87_update_device(dev);
	return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp_crit_int));
}

__attribute__((used)) static ssize_t temp2_crit_show(struct device *dev,
			       struct device_attribute *attr, char *buf)
{
	struct lm87_data *data = lm87_update_device(dev);
	return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp_crit_ext));
}

__attribute__((used)) static ssize_t show_fan_input(struct device *dev,
			      struct device_attribute *attr, char *buf)
{
	struct lm87_data *data = lm87_update_device(dev);
	int nr = to_sensor_dev_attr(attr)->index;

	return sprintf(buf, "%d\n", FAN_FROM_REG(data->fan[nr],
		       FAN_DIV_FROM_REG(data->fan_div[nr])));
}

__attribute__((used)) static ssize_t show_fan_min(struct device *dev,
			    struct device_attribute *attr, char *buf)
{
	struct lm87_data *data = lm87_update_device(dev);
	int nr = to_sensor_dev_attr(attr)->index;

	return sprintf(buf, "%d\n", FAN_FROM_REG(data->fan_min[nr],
		       FAN_DIV_FROM_REG(data->fan_div[nr])));
}

__attribute__((used)) static ssize_t show_fan_div(struct device *dev,
			    struct device_attribute *attr, char *buf)
{
	struct lm87_data *data = lm87_update_device(dev);
	int nr = to_sensor_dev_attr(attr)->index;

	return sprintf(buf, "%d\n",
		       FAN_DIV_FROM_REG(data->fan_div[nr]));
}

__attribute__((used)) static ssize_t set_fan_min(struct device *dev, struct device_attribute *attr,
			   const char *buf, size_t count)
{
	struct i2c_client *client = dev_get_drvdata(dev);
	struct lm87_data *data = i2c_get_clientdata(client);
	int nr = to_sensor_dev_attr(attr)->index;
	long val;
	int err;

	err = kstrtol(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	data->fan_min[nr] = FAN_TO_REG(val,
			    FAN_DIV_FROM_REG(data->fan_div[nr]));
	lm87_write_value(client, LM87_REG_FAN_MIN(nr), data->fan_min[nr]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t set_fan_div(struct device *dev, struct device_attribute *attr,
			   const char *buf, size_t count)
{
	struct i2c_client *client = dev_get_drvdata(dev);
	struct lm87_data *data = i2c_get_clientdata(client);
	int nr = to_sensor_dev_attr(attr)->index;
	long val;
	int err;
	unsigned long min;
	u8 reg;

	err = kstrtol(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	min = FAN_FROM_REG(data->fan_min[nr],
			   FAN_DIV_FROM_REG(data->fan_div[nr]));

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
		mutex_unlock(&data->update_lock);
		return -EINVAL;
	}

	reg = lm87_read_value(client, LM87_REG_VID_FAN_DIV);
	switch (nr) {
	case 0:
	    reg = (reg & 0xCF) | (data->fan_div[0] << 4);
	    break;
	case 1:
	    reg = (reg & 0x3F) | (data->fan_div[1] << 6);
	    break;
	}
	lm87_write_value(client, LM87_REG_VID_FAN_DIV, reg);

	data->fan_min[nr] = FAN_TO_REG(min, val);
	lm87_write_value(client, LM87_REG_FAN_MIN(nr),
			 data->fan_min[nr]);
	mutex_unlock(&data->update_lock);

	return count;
}

__attribute__((used)) static ssize_t alarms_show(struct device *dev, struct device_attribute *attr,
			   char *buf)
{
	struct lm87_data *data = lm87_update_device(dev);
	return sprintf(buf, "%d\n", data->alarms);
}

__attribute__((used)) static ssize_t cpu0_vid_show(struct device *dev,
			     struct device_attribute *attr, char *buf)
{
	struct lm87_data *data = lm87_update_device(dev);
	return sprintf(buf, "%d\n", vid_from_reg(data->vid, data->vrm));
}

__attribute__((used)) static ssize_t vrm_show(struct device *dev, struct device_attribute *attr,
			char *buf)
{
	struct lm87_data *data = dev_get_drvdata(dev);
	return sprintf(buf, "%d\n", data->vrm);
}

__attribute__((used)) static ssize_t vrm_store(struct device *dev, struct device_attribute *attr,
			 const char *buf, size_t count)
{
	struct lm87_data *data = dev_get_drvdata(dev);
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	if (val > 255)
		return -EINVAL;

	data->vrm = val;
	return count;
}

__attribute__((used)) static ssize_t aout_output_show(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	struct lm87_data *data = lm87_update_device(dev);
	return sprintf(buf, "%d\n", AOUT_FROM_REG(data->aout));
}

__attribute__((used)) static ssize_t aout_output_store(struct device *dev,
				 struct device_attribute *attr,
				 const char *buf, size_t count)
{
	struct i2c_client *client = dev_get_drvdata(dev);
	struct lm87_data *data = i2c_get_clientdata(client);
	long val;
	int err;

	err = kstrtol(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	data->aout = AOUT_TO_REG(val);
	lm87_write_value(client, LM87_REG_AOUT, data->aout);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_alarm(struct device *dev, struct device_attribute *attr,
			  char *buf)
{
	struct lm87_data *data = lm87_update_device(dev);
	int bitnr = to_sensor_dev_attr(attr)->index;
	return sprintf(buf, "%u\n", (data->alarms >> bitnr) & 1);
}

__attribute__((used)) static int lm87_detect(struct i2c_client *client, struct i2c_board_info *info)
{
	struct i2c_adapter *adapter = client->adapter;
	const char *name;
	u8 cid, rev;

	if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
		return -ENODEV;

	if (lm87_read_value(client, LM87_REG_CONFIG) & 0x80)
		return -ENODEV;

	/* Now, we do the remaining detection. */
	cid = lm87_read_value(client, LM87_REG_COMPANY_ID);
	rev = lm87_read_value(client, LM87_REG_REVISION);

	if (cid == 0x02			/* National Semiconductor */
	 && (rev >= 0x01 && rev <= 0x08))
		name = "lm87";
	else if (cid == 0x41		/* Analog Devices */
	      && (rev & 0xf0) == 0x10)
		name = "adm1024";
	else {
		dev_dbg(&adapter->dev, "LM87 detection failed at 0x%02x\n",
			client->addr);
		return -ENODEV;
	}

	strlcpy(info->type, name, I2C_NAME_SIZE);

	return 0;
}

__attribute__((used)) static void lm87_restore_config(void *arg)
{
	struct i2c_client *client = arg;
	struct lm87_data *data = i2c_get_clientdata(client);

	lm87_write_value(client, LM87_REG_CONFIG, data->config);
}

__attribute__((used)) static int lm87_init_client(struct i2c_client *client)
{
	struct lm87_data *data = i2c_get_clientdata(client);
	int rc;
	struct device_node *of_node = client->dev.of_node;
	u8 val = 0;
	struct regulator *vcc = NULL;

	if (of_node) {
		if (of_property_read_bool(of_node, "has-temp3"))
			val |= CHAN_TEMP3;
		if (of_property_read_bool(of_node, "has-in6"))
			val |= CHAN_NO_FAN(0);
		if (of_property_read_bool(of_node, "has-in7"))
			val |= CHAN_NO_FAN(1);
		vcc = devm_regulator_get_optional(&client->dev, "vcc");
		if (!IS_ERR(vcc)) {
			if (regulator_get_voltage(vcc) == 5000000)
				val |= CHAN_VCC_5V;
		}
		data->channel = val;
		lm87_write_value(client,
				LM87_REG_CHANNEL_MODE, data->channel);
	} else if (dev_get_platdata(&client->dev)) {
		data->channel = *(u8 *)dev_get_platdata(&client->dev);
		lm87_write_value(client,
				 LM87_REG_CHANNEL_MODE, data->channel);
	} else {
		data->channel = lm87_read_value(client, LM87_REG_CHANNEL_MODE);
	}
	data->config = lm87_read_value(client, LM87_REG_CONFIG) & 0x6F;

	rc = devm_add_action(&client->dev, lm87_restore_config, client);
	if (rc)
		return rc;

	if (!(data->config & 0x01)) {
		int i;

		/* Limits are left uninitialized after power-up */
		for (i = 1; i < 6; i++) {
			lm87_write_value(client, LM87_REG_IN_MIN(i), 0x00);
			lm87_write_value(client, LM87_REG_IN_MAX(i), 0xFF);
		}
		for (i = 0; i < 2; i++) {
			lm87_write_value(client, LM87_REG_TEMP_HIGH[i], 0x7F);
			lm87_write_value(client, LM87_REG_TEMP_LOW[i], 0x00);
			lm87_write_value(client, LM87_REG_AIN_MIN(i), 0x00);
			lm87_write_value(client, LM87_REG_AIN_MAX(i), 0xFF);
		}
		if (data->channel & CHAN_TEMP3) {
			lm87_write_value(client, LM87_REG_TEMP_HIGH[2], 0x7F);
			lm87_write_value(client, LM87_REG_TEMP_LOW[2], 0x00);
		} else {
			lm87_write_value(client, LM87_REG_IN_MIN(0), 0x00);
			lm87_write_value(client, LM87_REG_IN_MAX(0), 0xFF);
		}
	}

	/* Make sure Start is set and INT#_Clear is clear */
	if ((data->config & 0x09) != 0x01)
		lm87_write_value(client, LM87_REG_CONFIG,
				 (data->config & 0x77) | 0x01);
	return 0;
}

__attribute__((used)) static int lm87_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	struct lm87_data *data;
	struct device *hwmon_dev;
	int err;
	unsigned int group_tail = 0;

	data = devm_kzalloc(&client->dev, sizeof(struct lm87_data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	i2c_set_clientdata(client, data);
	mutex_init(&data->update_lock);

	/* Initialize the LM87 chip */
	err = lm87_init_client(client);
	if (err)
		return err;

	data->in_scale[0] = 2500;
	data->in_scale[1] = 2700;
	data->in_scale[2] = (data->channel & CHAN_VCC_5V) ? 5000 : 3300;
	data->in_scale[3] = 5000;
	data->in_scale[4] = 12000;
	data->in_scale[5] = 2700;
	data->in_scale[6] = 1875;
	data->in_scale[7] = 1875;

	/*
	 * Construct the list of attributes, the list depends on the
	 * configuration of the chip
	 */
	data->attr_groups[group_tail++] = &lm87_group;
	if (data->channel & CHAN_NO_FAN(0))
		data->attr_groups[group_tail++] = &lm87_group_in6;
	else
		data->attr_groups[group_tail++] = &lm87_group_fan1;

	if (data->channel & CHAN_NO_FAN(1))
		data->attr_groups[group_tail++] = &lm87_group_in7;
	else
		data->attr_groups[group_tail++] = &lm87_group_fan2;

	if (data->channel & CHAN_TEMP3)
		data->attr_groups[group_tail++] = &lm87_group_temp3;
	else
		data->attr_groups[group_tail++] = &lm87_group_in0_5;

	if (!(data->channel & CHAN_NO_VID)) {
		data->vrm = vid_which_vrm();
		data->attr_groups[group_tail++] = &lm87_group_vid;
	}

	hwmon_dev = devm_hwmon_device_register_with_groups(
	    &client->dev, client->name, client, data->attr_groups);
	return PTR_ERR_OR_ZERO(hwmon_dev);
}

