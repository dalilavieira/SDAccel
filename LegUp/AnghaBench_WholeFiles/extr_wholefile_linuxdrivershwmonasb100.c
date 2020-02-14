#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned int u8 ;
typedef  int u16 ;
struct i2c_device_id {int dummy; } ;
struct TYPE_7__ {int /*<<< orphan*/  kobj; } ;
struct i2c_client {int addr; TYPE_2__ dev; struct i2c_adapter* adapter; } ;
struct i2c_board_info {int /*<<< orphan*/  type; } ;
struct i2c_adapter {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct asb100_data {unsigned int* fan; unsigned int* fan_div; unsigned int* fan_min; int vid; int vrm; int alarms; int pwm; int valid; int* in; int* in_min; int* in_max; int* temp; int* temp_max; int* temp_hyst; int /*<<< orphan*/  update_lock; scalar_t__ last_updated; int /*<<< orphan*/  lock; struct i2c_client** lm75; int /*<<< orphan*/  hwmon_dev; } ;
typedef  int ssize_t ;
typedef  int s8 ;
typedef  int s16 ;
struct TYPE_6__ {int index; } ;

/* Variables and functions */
 int ASB100_IN_MAX ; 
 int ASB100_IN_MIN ; 
 int ASB100_REG_ALARM1 ; 
 int ASB100_REG_ALARM2 ; 
 int ASB100_REG_BANK ; 
 int ASB100_REG_CHIPID ; 
 int ASB100_REG_CHIPMAN ; 
 int ASB100_REG_CONFIG ; 
 int ASB100_REG_FAN (int) ; 
 int ASB100_REG_FAN_MIN (int) ; 
 int ASB100_REG_I2C_SUBADDR ; 
 int ASB100_REG_IN (int) ; 
 int ASB100_REG_IN_MAX (int) ; 
 int ASB100_REG_IN_MIN (int) ; 
 int ASB100_REG_PIN ; 
 int ASB100_REG_PWM1 ; 
 int ASB100_REG_TEMP (int) ; 
 int ASB100_REG_TEMP_HYST (int) ; 
 int ASB100_REG_TEMP_MAX (int) ; 
 int ASB100_REG_VID_FANDIV ; 
 int ASB100_REG_WCHIPID ; 
 int ASB100_TEMP_MAX ; 
 int ASB100_TEMP_MIN ; 
 int DIV_FROM_REG (unsigned int) ; 
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
 int /*<<< orphan*/  asb100_group ; 
static  void asb100_init_client (struct i2c_client*) ; 
static  int asb100_read_value (struct i2c_client*,int) ; 
static  struct asb100_data* asb100_update_device (struct device*) ; 
static  void asb100_write_value (struct i2c_client*,int,int) ; 
 unsigned int clamp_val (int,int,int) ; 
 int /*<<< orphan*/  dev_dbg (TYPE_2__*,char*) ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*,int,...) ; 
 struct asb100_data* dev_get_drvdata (struct device*) ; 
 struct asb100_data* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 int* force_subclients ; 
 int /*<<< orphan*/  hwmon_device_register (TYPE_2__*) ; 
 int /*<<< orphan*/  hwmon_device_unregister (int /*<<< orphan*/ ) ; 
 int i2c_adapter_id (struct i2c_adapter*) ; 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int /*<<< orphan*/ ) ; 
 struct asb100_data* i2c_get_clientdata (struct i2c_client*) ; 
 void* i2c_new_dummy (struct i2c_adapter*,unsigned short) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct asb100_data*) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int) ; 
 int i2c_smbus_read_word_swapped (struct i2c_client*,int) ; 
 int /*<<< orphan*/  i2c_smbus_write_byte_data (struct i2c_client*,int,int) ; 
 int /*<<< orphan*/  i2c_smbus_write_word_swapped (struct i2c_client*,int,int) ; 
 int /*<<< orphan*/  i2c_unregister_device (struct i2c_client*) ; 
 scalar_t__ jiffies ; 
 int kstrtoul (char const*,int,unsigned long*) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pr_debug (char*,...) ; 
 int sprintf (char*,char*,int) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int sysfs_create_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sysfs_remove_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ time_after (scalar_t__,scalar_t__) ; 
 struct i2c_client* to_i2c_client (struct device*) ; 
 TYPE_1__* to_sensor_dev_attr (struct device_attribute*) ; 
 int vid_from_reg (int,int) ; 
 unsigned long vid_which_vrm () ; 

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

__attribute__((used)) static u8 IN_TO_REG(unsigned val)
{
	unsigned nval = clamp_val(val, ASB100_IN_MIN, ASB100_IN_MAX);
	return (nval + 8) / 16;
}

__attribute__((used)) static unsigned IN_FROM_REG(u8 reg)
{
	return reg * 16;
}

__attribute__((used)) static u8 FAN_TO_REG(long rpm, int div)
{
	if (rpm == -1)
		return 0;
	if (rpm == 0)
		return 255;
	rpm = clamp_val(rpm, 1, 1000000);
	return clamp_val((1350000 + rpm * div / 2) / (rpm * div), 1, 254);
}

__attribute__((used)) static int FAN_FROM_REG(u8 val, int div)
{
	return val == 0 ? -1 : val == 255 ? 0 : 1350000 / (val * div);
}

__attribute__((used)) static u8 TEMP_TO_REG(long temp)
{
	int ntemp = clamp_val(temp, ASB100_TEMP_MIN, ASB100_TEMP_MAX);
	ntemp += (ntemp < 0 ? -500 : 500);
	return (u8)(ntemp / 1000);
}

__attribute__((used)) static int TEMP_FROM_REG(u8 reg)
{
	return (s8)reg * 1000;
}

__attribute__((used)) static u8 ASB100_PWM_TO_REG(int pwm)
{
	pwm = clamp_val(pwm, 0, 255);
	return (u8)(pwm / 16);
}

__attribute__((used)) static int ASB100_PWM_FROM_REG(u8 reg)
{
	return reg * 16;
}

__attribute__((used)) static u8 DIV_TO_REG(long val)
{
	return val == 8 ? 3 : val == 4 ? 2 : val == 1 ? 0 : 1;
}

__attribute__((used)) static ssize_t show_fan(struct device *dev, struct device_attribute *attr,
		char *buf)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct asb100_data *data = asb100_update_device(dev);
	return sprintf(buf, "%d\n", FAN_FROM_REG(data->fan[nr],
		DIV_FROM_REG(data->fan_div[nr])));
}

__attribute__((used)) static ssize_t show_fan_min(struct device *dev, struct device_attribute *attr,
		char *buf)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct asb100_data *data = asb100_update_device(dev);
	return sprintf(buf, "%d\n", FAN_FROM_REG(data->fan_min[nr],
		DIV_FROM_REG(data->fan_div[nr])));
}

__attribute__((used)) static ssize_t show_fan_div(struct device *dev, struct device_attribute *attr,
		char *buf)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct asb100_data *data = asb100_update_device(dev);
	return sprintf(buf, "%d\n", DIV_FROM_REG(data->fan_div[nr]));
}

__attribute__((used)) static ssize_t set_fan_min(struct device *dev, struct device_attribute *attr,
		const char *buf, size_t count)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct i2c_client *client = to_i2c_client(dev);
	struct asb100_data *data = i2c_get_clientdata(client);
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	data->fan_min[nr] = FAN_TO_REG(val, DIV_FROM_REG(data->fan_div[nr]));
	asb100_write_value(client, ASB100_REG_FAN_MIN(nr), data->fan_min[nr]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t set_fan_div(struct device *dev, struct device_attribute *attr,
		const char *buf, size_t count)
{
	int nr = to_sensor_dev_attr(attr)->index;
	struct i2c_client *client = to_i2c_client(dev);
	struct asb100_data *data = i2c_get_clientdata(client);
	unsigned long min;
	int reg;
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);

	min = FAN_FROM_REG(data->fan_min[nr],
			DIV_FROM_REG(data->fan_div[nr]));
	data->fan_div[nr] = DIV_TO_REG(val);

	switch (nr) {
	case 0:	/* fan 1 */
		reg = asb100_read_value(client, ASB100_REG_VID_FANDIV);
		reg = (reg & 0xcf) | (data->fan_div[0] << 4);
		asb100_write_value(client, ASB100_REG_VID_FANDIV, reg);
		break;

	case 1:	/* fan 2 */
		reg = asb100_read_value(client, ASB100_REG_VID_FANDIV);
		reg = (reg & 0x3f) | (data->fan_div[1] << 6);
		asb100_write_value(client, ASB100_REG_VID_FANDIV, reg);
		break;

	case 2:	/* fan 3 */
		reg = asb100_read_value(client, ASB100_REG_PIN);
		reg = (reg & 0x3f) | (data->fan_div[2] << 6);
		asb100_write_value(client, ASB100_REG_PIN, reg);
		break;
	}

	data->fan_min[nr] =
		FAN_TO_REG(min, DIV_FROM_REG(data->fan_div[nr]));
	asb100_write_value(client, ASB100_REG_FAN_MIN(nr), data->fan_min[nr]);

	mutex_unlock(&data->update_lock);

	return count;
}

__attribute__((used)) static int sprintf_temp_from_reg(u16 reg, char *buf, int nr)
{
	int ret = 0;

	switch (nr) {
	case 1: case 2:
		ret = sprintf(buf, "%d\n", LM75_TEMP_FROM_REG(reg));
		break;
	case 0: case 3: default:
		ret = sprintf(buf, "%d\n", TEMP_FROM_REG(reg));
		break;
	}
	return ret;
}

__attribute__((used)) static ssize_t cpu0_vid_show(struct device *dev,
			     struct device_attribute *attr, char *buf)
{
	struct asb100_data *data = asb100_update_device(dev);
	return sprintf(buf, "%d\n", vid_from_reg(data->vid, data->vrm));
}

__attribute__((used)) static ssize_t vrm_show(struct device *dev, struct device_attribute *attr,
		char *buf)
{
	struct asb100_data *data = dev_get_drvdata(dev);
	return sprintf(buf, "%d\n", data->vrm);
}

__attribute__((used)) static ssize_t vrm_store(struct device *dev, struct device_attribute *attr,
			 const char *buf, size_t count)
{
	struct asb100_data *data = dev_get_drvdata(dev);
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

__attribute__((used)) static ssize_t alarms_show(struct device *dev, struct device_attribute *attr,
		char *buf)
{
	struct asb100_data *data = asb100_update_device(dev);
	return sprintf(buf, "%u\n", data->alarms);
}

__attribute__((used)) static ssize_t show_alarm(struct device *dev, struct device_attribute *attr,
		char *buf)
{
	int bitnr = to_sensor_dev_attr(attr)->index;
	struct asb100_data *data = asb100_update_device(dev);
	return sprintf(buf, "%u\n", (data->alarms >> bitnr) & 1);
}

__attribute__((used)) static ssize_t pwm1_show(struct device *dev, struct device_attribute *attr,
		char *buf)
{
	struct asb100_data *data = asb100_update_device(dev);
	return sprintf(buf, "%d\n", ASB100_PWM_FROM_REG(data->pwm & 0x0f));
}

__attribute__((used)) static ssize_t pwm1_store(struct device *dev, struct device_attribute *attr,
			  const char *buf, size_t count)
{
	struct i2c_client *client = to_i2c_client(dev);
	struct asb100_data *data = i2c_get_clientdata(client);
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	data->pwm &= 0x80; /* keep the enable bit */
	data->pwm |= (0x0f & ASB100_PWM_TO_REG(val));
	asb100_write_value(client, ASB100_REG_PWM1, data->pwm);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t pwm1_enable_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct asb100_data *data = asb100_update_device(dev);
	return sprintf(buf, "%d\n", (data->pwm & 0x80) ? 1 : 0);
}

__attribute__((used)) static ssize_t pwm1_enable_store(struct device *dev,
				 struct device_attribute *attr,
				 const char *buf, size_t count)
{
	struct i2c_client *client = to_i2c_client(dev);
	struct asb100_data *data = i2c_get_clientdata(client);
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	data->pwm &= 0x0f; /* keep the duty cycle bits */
	data->pwm |= (val ? 0x80 : 0x00);
	asb100_write_value(client, ASB100_REG_PWM1, data->pwm);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static int asb100_detect_subclients(struct i2c_client *client)
{
	int i, id, err;
	int address = client->addr;
	unsigned short sc_addr[2];
	struct asb100_data *data = i2c_get_clientdata(client);
	struct i2c_adapter *adapter = client->adapter;

	id = i2c_adapter_id(adapter);

	if (force_subclients[0] == id && force_subclients[1] == address) {
		for (i = 2; i <= 3; i++) {
			if (force_subclients[i] < 0x48 ||
			    force_subclients[i] > 0x4f) {
				dev_err(&client->dev,
					"invalid subclient address %d; must be 0x48-0x4f\n",
					force_subclients[i]);
				err = -ENODEV;
				goto ERROR_SC_2;
			}
		}
		asb100_write_value(client, ASB100_REG_I2C_SUBADDR,
					(force_subclients[2] & 0x07) |
					((force_subclients[3] & 0x07) << 4));
		sc_addr[0] = force_subclients[2];
		sc_addr[1] = force_subclients[3];
	} else {
		int val = asb100_read_value(client, ASB100_REG_I2C_SUBADDR);
		sc_addr[0] = 0x48 + (val & 0x07);
		sc_addr[1] = 0x48 + ((val >> 4) & 0x07);
	}

	if (sc_addr[0] == sc_addr[1]) {
		dev_err(&client->dev,
			"duplicate addresses 0x%x for subclients\n",
			sc_addr[0]);
		err = -ENODEV;
		goto ERROR_SC_2;
	}

	data->lm75[0] = i2c_new_dummy(adapter, sc_addr[0]);
	if (!data->lm75[0]) {
		dev_err(&client->dev,
			"subclient %d registration at address 0x%x failed.\n",
			1, sc_addr[0]);
		err = -ENOMEM;
		goto ERROR_SC_2;
	}

	data->lm75[1] = i2c_new_dummy(adapter, sc_addr[1]);
	if (!data->lm75[1]) {
		dev_err(&client->dev,
			"subclient %d registration at address 0x%x failed.\n",
			2, sc_addr[1]);
		err = -ENOMEM;
		goto ERROR_SC_3;
	}

	return 0;

/* Undo inits in case of errors */
ERROR_SC_3:
	i2c_unregister_device(data->lm75[0]);
ERROR_SC_2:
	return err;
}

__attribute__((used)) static int asb100_detect(struct i2c_client *client,
			 struct i2c_board_info *info)
{
	struct i2c_adapter *adapter = client->adapter;
	int val1, val2;

	if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA)) {
		pr_debug("detect failed, smbus byte data not supported!\n");
		return -ENODEV;
	}

	val1 = i2c_smbus_read_byte_data(client, ASB100_REG_BANK);
	val2 = i2c_smbus_read_byte_data(client, ASB100_REG_CHIPMAN);

	/* If we're in bank 0 */
	if ((!(val1 & 0x07)) &&
			/* Check for ASB100 ID (low byte) */
			(((!(val1 & 0x80)) && (val2 != 0x94)) ||
			/* Check for ASB100 ID (high byte ) */
			((val1 & 0x80) && (val2 != 0x06)))) {
		pr_debug("detect failed, bad chip id 0x%02x!\n", val2);
		return -ENODEV;
	}

	/* Put it now into bank 0 and Vendor ID High Byte */
	i2c_smbus_write_byte_data(client, ASB100_REG_BANK,
		(i2c_smbus_read_byte_data(client, ASB100_REG_BANK) & 0x78)
		| 0x80);

	/* Determine the chip type. */
	val1 = i2c_smbus_read_byte_data(client, ASB100_REG_WCHIPID);
	val2 = i2c_smbus_read_byte_data(client, ASB100_REG_CHIPMAN);

	if (val1 != 0x31 || val2 != 0x06)
		return -ENODEV;

	strlcpy(info->type, "asb100", I2C_NAME_SIZE);

	return 0;
}

__attribute__((used)) static int asb100_probe(struct i2c_client *client,
			const struct i2c_device_id *id)
{
	int err;
	struct asb100_data *data;

	data = devm_kzalloc(&client->dev, sizeof(struct asb100_data),
			    GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	i2c_set_clientdata(client, data);
	mutex_init(&data->lock);
	mutex_init(&data->update_lock);

	/* Attach secondary lm75 clients */
	err = asb100_detect_subclients(client);
	if (err)
		return err;

	/* Initialize the chip */
	asb100_init_client(client);

	/* A few vars need to be filled upon startup */
	data->fan_min[0] = asb100_read_value(client, ASB100_REG_FAN_MIN(0));
	data->fan_min[1] = asb100_read_value(client, ASB100_REG_FAN_MIN(1));
	data->fan_min[2] = asb100_read_value(client, ASB100_REG_FAN_MIN(2));

	/* Register sysfs hooks */
	err = sysfs_create_group(&client->dev.kobj, &asb100_group);
	if (err)
		goto ERROR3;

	data->hwmon_dev = hwmon_device_register(&client->dev);
	if (IS_ERR(data->hwmon_dev)) {
		err = PTR_ERR(data->hwmon_dev);
		goto ERROR4;
	}

	return 0;

ERROR4:
	sysfs_remove_group(&client->dev.kobj, &asb100_group);
ERROR3:
	i2c_unregister_device(data->lm75[1]);
	i2c_unregister_device(data->lm75[0]);
	return err;
}

__attribute__((used)) static int asb100_remove(struct i2c_client *client)
{
	struct asb100_data *data = i2c_get_clientdata(client);

	hwmon_device_unregister(data->hwmon_dev);
	sysfs_remove_group(&client->dev.kobj, &asb100_group);

	i2c_unregister_device(data->lm75[1]);
	i2c_unregister_device(data->lm75[0]);

	return 0;
}

__attribute__((used)) static int asb100_read_value(struct i2c_client *client, u16 reg)
{
	struct asb100_data *data = i2c_get_clientdata(client);
	struct i2c_client *cl;
	int res, bank;

	mutex_lock(&data->lock);

	bank = (reg >> 8) & 0x0f;
	if (bank > 2)
		/* switch banks */
		i2c_smbus_write_byte_data(client, ASB100_REG_BANK, bank);

	if (bank == 0 || bank > 2) {
		res = i2c_smbus_read_byte_data(client, reg & 0xff);
	} else {
		/* switch to subclient */
		cl = data->lm75[bank - 1];

		/* convert from ISA to LM75 I2C addresses */
		switch (reg & 0xff) {
		case 0x50: /* TEMP */
			res = i2c_smbus_read_word_swapped(cl, 0);
			break;
		case 0x52: /* CONFIG */
			res = i2c_smbus_read_byte_data(cl, 1);
			break;
		case 0x53: /* HYST */
			res = i2c_smbus_read_word_swapped(cl, 2);
			break;
		case 0x55: /* MAX */
		default:
			res = i2c_smbus_read_word_swapped(cl, 3);
			break;
		}
	}

	if (bank > 2)
		i2c_smbus_write_byte_data(client, ASB100_REG_BANK, 0);

	mutex_unlock(&data->lock);

	return res;
}

__attribute__((used)) static void asb100_write_value(struct i2c_client *client, u16 reg, u16 value)
{
	struct asb100_data *data = i2c_get_clientdata(client);
	struct i2c_client *cl;
	int bank;

	mutex_lock(&data->lock);

	bank = (reg >> 8) & 0x0f;
	if (bank > 2)
		/* switch banks */
		i2c_smbus_write_byte_data(client, ASB100_REG_BANK, bank);

	if (bank == 0 || bank > 2) {
		i2c_smbus_write_byte_data(client, reg & 0xff, value & 0xff);
	} else {
		/* switch to subclient */
		cl = data->lm75[bank - 1];

		/* convert from ISA to LM75 I2C addresses */
		switch (reg & 0xff) {
		case 0x52: /* CONFIG */
			i2c_smbus_write_byte_data(cl, 1, value & 0xff);
			break;
		case 0x53: /* HYST */
			i2c_smbus_write_word_swapped(cl, 2, value);
			break;
		case 0x55: /* MAX */
			i2c_smbus_write_word_swapped(cl, 3, value);
			break;
		}
	}

	if (bank > 2)
		i2c_smbus_write_byte_data(client, ASB100_REG_BANK, 0);

	mutex_unlock(&data->lock);
}

__attribute__((used)) static void asb100_init_client(struct i2c_client *client)
{
	struct asb100_data *data = i2c_get_clientdata(client);

	data->vrm = vid_which_vrm();

	/* Start monitoring */
	asb100_write_value(client, ASB100_REG_CONFIG,
		(asb100_read_value(client, ASB100_REG_CONFIG) & 0xf7) | 0x01);
}

__attribute__((used)) static struct asb100_data *asb100_update_device(struct device *dev)
{
	struct i2c_client *client = to_i2c_client(dev);
	struct asb100_data *data = i2c_get_clientdata(client);
	int i;

	mutex_lock(&data->update_lock);

	if (time_after(jiffies, data->last_updated + HZ + HZ / 2)
		|| !data->valid) {

		dev_dbg(&client->dev, "starting device update...\n");

		/* 7 voltage inputs */
		for (i = 0; i < 7; i++) {
			data->in[i] = asb100_read_value(client,
				ASB100_REG_IN(i));
			data->in_min[i] = asb100_read_value(client,
				ASB100_REG_IN_MIN(i));
			data->in_max[i] = asb100_read_value(client,
				ASB100_REG_IN_MAX(i));
		}

		/* 3 fan inputs */
		for (i = 0; i < 3; i++) {
			data->fan[i] = asb100_read_value(client,
					ASB100_REG_FAN(i));
			data->fan_min[i] = asb100_read_value(client,
					ASB100_REG_FAN_MIN(i));
		}

		/* 4 temperature inputs */
		for (i = 1; i <= 4; i++) {
			data->temp[i-1] = asb100_read_value(client,
					ASB100_REG_TEMP(i));
			data->temp_max[i-1] = asb100_read_value(client,
					ASB100_REG_TEMP_MAX(i));
			data->temp_hyst[i-1] = asb100_read_value(client,
					ASB100_REG_TEMP_HYST(i));
		}

		/* VID and fan divisors */
		i = asb100_read_value(client, ASB100_REG_VID_FANDIV);
		data->vid = i & 0x0f;
		data->vid |= (asb100_read_value(client,
				ASB100_REG_CHIPID) & 0x01) << 4;
		data->fan_div[0] = (i >> 4) & 0x03;
		data->fan_div[1] = (i >> 6) & 0x03;
		data->fan_div[2] = (asb100_read_value(client,
				ASB100_REG_PIN) >> 6) & 0x03;

		/* PWM */
		data->pwm = asb100_read_value(client, ASB100_REG_PWM1);

		/* alarms */
		data->alarms = asb100_read_value(client, ASB100_REG_ALARM1) +
			(asb100_read_value(client, ASB100_REG_ALARM2) << 8);

		data->last_updated = jiffies;
		data->valid = 1;

		dev_dbg(&client->dev, "... device update complete\n");
	}

	mutex_unlock(&data->update_lock);

	return data;
}

