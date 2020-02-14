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
typedef  int u8 ;
struct smsc47m192_data {int valid; int* in; int* in_min; int* in_max; int* temp; int* temp_max; int* temp_min; int* temp_offset; int vid; int alarms; int vrm; int /*<<< orphan*/ ** groups; int /*<<< orphan*/  update_lock; struct i2c_client* client; scalar_t__ last_updated; } ;
struct sensor_device_attribute {int index; } ;
struct i2c_device_id {int dummy; } ;
struct device {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  name; struct device dev; int /*<<< orphan*/  addr; struct i2c_adapter* adapter; } ;
struct i2c_board_info {int /*<<< orphan*/  type; } ;
struct i2c_adapter {int /*<<< orphan*/  dev; } ;
struct device_attribute {int dummy; } ;
typedef  int ssize_t ;
typedef  int s8 ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HZ ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_BYTE_DATA ; 
 int /*<<< orphan*/  I2C_NAME_SIZE ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
 int /*<<< orphan*/  SMSC47M192_REG_ALARM1 ; 
 int /*<<< orphan*/  SMSC47M192_REG_ALARM2 ; 
 int /*<<< orphan*/  SMSC47M192_REG_COMPANY_ID ; 
 int /*<<< orphan*/  SMSC47M192_REG_CONFIG ; 
 int /*<<< orphan*/  SMSC47M192_REG_IN (int) ; 
 int /*<<< orphan*/  SMSC47M192_REG_IN_MAX (int) ; 
 int /*<<< orphan*/  SMSC47M192_REG_IN_MIN (int) ; 
 int /*<<< orphan*/  SMSC47M192_REG_SFR ; 
 int /*<<< orphan*/ * SMSC47M192_REG_TEMP ; 
 int /*<<< orphan*/ * SMSC47M192_REG_TEMP_MAX ; 
 int /*<<< orphan*/ * SMSC47M192_REG_TEMP_MIN ; 
 int /*<<< orphan*/  SMSC47M192_REG_TEMP_OFFSET (int) ; 
 int /*<<< orphan*/  SMSC47M192_REG_VERSION ; 
 int /*<<< orphan*/  SMSC47M192_REG_VID ; 
 int /*<<< orphan*/  SMSC47M192_REG_VID4 ; 
 void* clamp_val (long,int,int) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,...) ; 
 struct smsc47m192_data* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,int) ; 
 struct device* devm_hwmon_device_register_with_groups (struct device*,int /*<<< orphan*/ ,struct smsc47m192_data*,int /*<<< orphan*/ **) ; 
 struct smsc47m192_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_smbus_write_byte_data (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ jiffies ; 
 int kstrtol (char const*,int,long*) ; 
 int kstrtoul (char const*,int,unsigned long*) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int* nom_mv ; 
 int /*<<< orphan*/  smsc47m192_group ; 
 int /*<<< orphan*/  smsc47m192_group_in4 ; 
 int sprintf (char*,char*,int) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 scalar_t__ time_after (scalar_t__,scalar_t__) ; 
 struct sensor_device_attribute* to_sensor_dev_attr (struct device_attribute*) ; 
 int vid_from_reg (int,int) ; 
 unsigned long vid_which_vrm () ; 

__attribute__((used)) static inline int SCALE(long val, int mul, int div)
{
	if (val < 0)
		return (val * mul - div / 2) / div;
	else
		return (val * mul + div / 2) / div;
}

__attribute__((used)) static inline unsigned int IN_FROM_REG(u8 reg, int n)
{
	return SCALE(reg, nom_mv[n], 192);
}

__attribute__((used)) static inline u8 IN_TO_REG(unsigned long val, int n)
{
	val = clamp_val(val, 0, nom_mv[n] * 255 / 192);
	return SCALE(val, 192, nom_mv[n]);
}

__attribute__((used)) static inline s8 TEMP_TO_REG(long val)
{
	return SCALE(clamp_val(val, -128000, 127000), 1, 1000);
}

__attribute__((used)) static inline int TEMP_FROM_REG(s8 val)
{
	return val * 1000;
}

__attribute__((used)) static struct smsc47m192_data *smsc47m192_update_device(struct device *dev)
{
	struct smsc47m192_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	int i, config;

	mutex_lock(&data->update_lock);

	if (time_after(jiffies, data->last_updated + HZ + HZ / 2)
	 || !data->valid) {
		u8 sfr = i2c_smbus_read_byte_data(client, SMSC47M192_REG_SFR);

		dev_dbg(&client->dev, "Starting smsc47m192 update\n");

		for (i = 0; i <= 7; i++) {
			data->in[i] = i2c_smbus_read_byte_data(client,
						SMSC47M192_REG_IN(i));
			data->in_min[i] = i2c_smbus_read_byte_data(client,
						SMSC47M192_REG_IN_MIN(i));
			data->in_max[i] = i2c_smbus_read_byte_data(client,
						SMSC47M192_REG_IN_MAX(i));
		}
		for (i = 0; i < 3; i++) {
			data->temp[i] = i2c_smbus_read_byte_data(client,
						SMSC47M192_REG_TEMP[i]);
			data->temp_max[i] = i2c_smbus_read_byte_data(client,
						SMSC47M192_REG_TEMP_MAX[i]);
			data->temp_min[i] = i2c_smbus_read_byte_data(client,
						SMSC47M192_REG_TEMP_MIN[i]);
		}
		for (i = 1; i < 3; i++)
			data->temp_offset[i] = i2c_smbus_read_byte_data(client,
						SMSC47M192_REG_TEMP_OFFSET(i));
		/*
		 * first offset is temp_offset[0] if SFR bit 4 is set,
		 * temp_offset[1] otherwise
		 */
		if (sfr & 0x10) {
			data->temp_offset[0] = data->temp_offset[1];
			data->temp_offset[1] = 0;
		} else
			data->temp_offset[0] = 0;

		data->vid = i2c_smbus_read_byte_data(client, SMSC47M192_REG_VID)
			    & 0x0f;
		config = i2c_smbus_read_byte_data(client,
						  SMSC47M192_REG_CONFIG);
		if (config & 0x20)
			data->vid |= (i2c_smbus_read_byte_data(client,
					SMSC47M192_REG_VID4) & 0x01) << 4;
		data->alarms = i2c_smbus_read_byte_data(client,
						SMSC47M192_REG_ALARM1) |
			       (i2c_smbus_read_byte_data(client,
						SMSC47M192_REG_ALARM2) << 8);

		data->last_updated = jiffies;
		data->valid = 1;
	}

	mutex_unlock(&data->update_lock);

	return data;
}

__attribute__((used)) static ssize_t show_in(struct device *dev, struct device_attribute *attr,
		char *buf)
{
	struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
	int nr = sensor_attr->index;
	struct smsc47m192_data *data = smsc47m192_update_device(dev);
	return sprintf(buf, "%d\n", IN_FROM_REG(data->in[nr], nr));
}

__attribute__((used)) static ssize_t show_in_min(struct device *dev, struct device_attribute *attr,
		char *buf)
{
	struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
	int nr = sensor_attr->index;
	struct smsc47m192_data *data = smsc47m192_update_device(dev);
	return sprintf(buf, "%d\n", IN_FROM_REG(data->in_min[nr], nr));
}

__attribute__((used)) static ssize_t show_in_max(struct device *dev, struct device_attribute *attr,
		char *buf)
{
	struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
	int nr = sensor_attr->index;
	struct smsc47m192_data *data = smsc47m192_update_device(dev);
	return sprintf(buf, "%d\n", IN_FROM_REG(data->in_max[nr], nr));
}

__attribute__((used)) static ssize_t set_in_min(struct device *dev, struct device_attribute *attr,
		const char *buf, size_t count)
{
	struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
	int nr = sensor_attr->index;
	struct smsc47m192_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	data->in_min[nr] = IN_TO_REG(val, nr);
	i2c_smbus_write_byte_data(client, SMSC47M192_REG_IN_MIN(nr),
							data->in_min[nr]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t set_in_max(struct device *dev, struct device_attribute *attr,
		const char *buf, size_t count)
{
	struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
	int nr = sensor_attr->index;
	struct smsc47m192_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	data->in_max[nr] = IN_TO_REG(val, nr);
	i2c_smbus_write_byte_data(client, SMSC47M192_REG_IN_MAX(nr),
							data->in_max[nr]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_temp(struct device *dev, struct device_attribute *attr,
		char *buf)
{
	struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
	int nr = sensor_attr->index;
	struct smsc47m192_data *data = smsc47m192_update_device(dev);
	return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp[nr]));
}

__attribute__((used)) static ssize_t show_temp_min(struct device *dev, struct device_attribute *attr,
		char *buf)
{
	struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
	int nr = sensor_attr->index;
	struct smsc47m192_data *data = smsc47m192_update_device(dev);
	return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp_min[nr]));
}

__attribute__((used)) static ssize_t show_temp_max(struct device *dev, struct device_attribute *attr,
		char *buf)
{
	struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
	int nr = sensor_attr->index;
	struct smsc47m192_data *data = smsc47m192_update_device(dev);
	return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp_max[nr]));
}

__attribute__((used)) static ssize_t set_temp_min(struct device *dev, struct device_attribute *attr,
		const char *buf, size_t count)
{
	struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
	int nr = sensor_attr->index;
	struct smsc47m192_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	long val;
	int err;

	err = kstrtol(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	data->temp_min[nr] = TEMP_TO_REG(val);
	i2c_smbus_write_byte_data(client, SMSC47M192_REG_TEMP_MIN[nr],
						data->temp_min[nr]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t set_temp_max(struct device *dev, struct device_attribute *attr,
		const char *buf, size_t count)
{
	struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
	int nr = sensor_attr->index;
	struct smsc47m192_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	long val;
	int err;

	err = kstrtol(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	data->temp_max[nr] = TEMP_TO_REG(val);
	i2c_smbus_write_byte_data(client, SMSC47M192_REG_TEMP_MAX[nr],
						data->temp_max[nr]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_temp_offset(struct device *dev, struct device_attribute
		*attr, char *buf)
{
	struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
	int nr = sensor_attr->index;
	struct smsc47m192_data *data = smsc47m192_update_device(dev);
	return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp_offset[nr]));
}

__attribute__((used)) static ssize_t set_temp_offset(struct device *dev, struct device_attribute
		*attr, const char *buf, size_t count)
{
	struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
	int nr = sensor_attr->index;
	struct smsc47m192_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	u8 sfr = i2c_smbus_read_byte_data(client, SMSC47M192_REG_SFR);
	long val;
	int err;

	err = kstrtol(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	data->temp_offset[nr] = TEMP_TO_REG(val);
	if (nr > 1)
		i2c_smbus_write_byte_data(client,
			SMSC47M192_REG_TEMP_OFFSET(nr), data->temp_offset[nr]);
	else if (data->temp_offset[nr] != 0) {
		/*
		 * offset[0] and offset[1] share the same register,
		 * SFR bit 4 activates offset[0]
		 */
		i2c_smbus_write_byte_data(client, SMSC47M192_REG_SFR,
					(sfr & 0xef) | (nr == 0 ? 0x10 : 0));
		data->temp_offset[1-nr] = 0;
		i2c_smbus_write_byte_data(client,
			SMSC47M192_REG_TEMP_OFFSET(nr), data->temp_offset[nr]);
	} else if ((sfr & 0x10) == (nr == 0 ? 0x10 : 0))
		i2c_smbus_write_byte_data(client,
					SMSC47M192_REG_TEMP_OFFSET(nr), 0);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t cpu0_vid_show(struct device *dev,
			     struct device_attribute *attr, char *buf)
{
	struct smsc47m192_data *data = smsc47m192_update_device(dev);
	return sprintf(buf, "%d\n", vid_from_reg(data->vid, data->vrm));
}

__attribute__((used)) static ssize_t vrm_show(struct device *dev, struct device_attribute *attr,
		char *buf)
{
	struct smsc47m192_data *data = dev_get_drvdata(dev);
	return sprintf(buf, "%d\n", data->vrm);
}

__attribute__((used)) static ssize_t vrm_store(struct device *dev, struct device_attribute *attr,
			 const char *buf, size_t count)
{
	struct smsc47m192_data *data = dev_get_drvdata(dev);
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

__attribute__((used)) static ssize_t show_alarm(struct device *dev, struct device_attribute *attr,
		char *buf)
{
	struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
	int nr = sensor_attr->index;
	struct smsc47m192_data *data = smsc47m192_update_device(dev);
	return sprintf(buf, "%u\n", (data->alarms & nr) ? 1 : 0);
}

__attribute__((used)) static void smsc47m192_init_client(struct i2c_client *client)
{
	int i;
	u8 config = i2c_smbus_read_byte_data(client, SMSC47M192_REG_CONFIG);
	u8 sfr = i2c_smbus_read_byte_data(client, SMSC47M192_REG_SFR);

	/* select cycle mode (pause 1 sec between updates) */
	i2c_smbus_write_byte_data(client, SMSC47M192_REG_SFR,
						(sfr & 0xfd) | 0x02);
	if (!(config & 0x01)) {
		/* initialize alarm limits */
		for (i = 0; i < 8; i++) {
			i2c_smbus_write_byte_data(client,
				SMSC47M192_REG_IN_MIN(i), 0);
			i2c_smbus_write_byte_data(client,
				SMSC47M192_REG_IN_MAX(i), 0xff);
		}
		for (i = 0; i < 3; i++) {
			i2c_smbus_write_byte_data(client,
				SMSC47M192_REG_TEMP_MIN[i], 0x80);
			i2c_smbus_write_byte_data(client,
				SMSC47M192_REG_TEMP_MAX[i], 0x7f);
		}

		/* start monitoring */
		i2c_smbus_write_byte_data(client, SMSC47M192_REG_CONFIG,
						(config & 0xf7) | 0x01);
	}
}

__attribute__((used)) static int smsc47m192_detect(struct i2c_client *client,
			     struct i2c_board_info *info)
{
	struct i2c_adapter *adapter = client->adapter;
	int version;

	if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
		return -ENODEV;

	/* Detection criteria from sensors_detect script */
	version = i2c_smbus_read_byte_data(client, SMSC47M192_REG_VERSION);
	if (i2c_smbus_read_byte_data(client,
				SMSC47M192_REG_COMPANY_ID) == 0x55
	 && (version & 0xf0) == 0x20
	 && (i2c_smbus_read_byte_data(client,
				SMSC47M192_REG_VID) & 0x70) == 0x00
	 && (i2c_smbus_read_byte_data(client,
				SMSC47M192_REG_VID4) & 0xfe) == 0x80) {
		dev_info(&adapter->dev,
			 "found SMSC47M192 or compatible, "
			 "version 2, stepping A%d\n", version & 0x0f);
	} else {
		dev_dbg(&adapter->dev,
			"SMSC47M192 detection failed at 0x%02x\n",
			client->addr);
		return -ENODEV;
	}

	strlcpy(info->type, "smsc47m192", I2C_NAME_SIZE);

	return 0;
}

__attribute__((used)) static int smsc47m192_probe(struct i2c_client *client,
			    const struct i2c_device_id *id)
{
	struct device *dev = &client->dev;
	struct device *hwmon_dev;
	struct smsc47m192_data *data;
	int config;

	data = devm_kzalloc(dev, sizeof(struct smsc47m192_data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->client = client;
	data->vrm = vid_which_vrm();
	mutex_init(&data->update_lock);

	/* Initialize the SMSC47M192 chip */
	smsc47m192_init_client(client);

	/* sysfs hooks */
	data->groups[0] = &smsc47m192_group;
	/* Pin 110 is either in4 (+12V) or VID4 */
	config = i2c_smbus_read_byte_data(client, SMSC47M192_REG_CONFIG);
	if (!(config & 0x20))
		data->groups[1] = &smsc47m192_group_in4;

	hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
							   data, data->groups);
	return PTR_ERR_OR_ZERO(hwmon_dev);
}

