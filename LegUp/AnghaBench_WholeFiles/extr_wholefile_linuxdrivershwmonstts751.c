#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct stts751_priv {int interval; int res; int config; int temp; int alert_valid; int max_alert; int min_alert; int therm_trip; int notify_max; int notify_min; int data_valid; int therm; int hyst; int event_max; int event_min; TYPE_2__* dev; int /*<<< orphan*/  access_lock; struct i2c_client* client; void* last_update; void* last_alert_update; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  name; int /*<<< orphan*/  dev; struct i2c_adapter* adapter; } ;
struct i2c_board_info {int /*<<< orphan*/  type; } ;
struct i2c_adapter {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;
typedef  int s32 ;
typedef  int s16 ;
typedef  enum i2c_alert_protocol { ____Placeholder_i2c_alert_protocol } i2c_alert_protocol ;
struct TYPE_8__ {int /*<<< orphan*/  kobj; } ;
struct TYPE_7__ {int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int ARRAY_SIZE (int*) ; 
 int DIV_ROUND_CLOSEST (int,int) ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_BYTE_DATA ; 
 int /*<<< orphan*/  I2C_NAME_SIZE ; 
 int I2C_PROTOCOL_SMBUS_ALERT ; 
 int /*<<< orphan*/  KOBJ_CHANGE ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 int PTR_ERR_OR_ZERO (TYPE_2__*) ; 
#define  STTS751_0_PROD_ID 129 
#define  STTS751_1_PROD_ID 128 
 int STTS751_CONF_EVENT_DIS ; 
 int STTS751_CONF_RES_MASK ; 
 int STTS751_CONF_RES_SHIFT ; 
 int STTS751_CONF_STOP ; 
 int STTS751_REG_CONF ; 
 int STTS751_REG_HLIM_H ; 
 int STTS751_REG_HLIM_L ; 
 int STTS751_REG_HYST ; 
 int STTS751_REG_LLIM_H ; 
 int STTS751_REG_LLIM_L ; 
 int STTS751_REG_MAN_ID ; 
 int STTS751_REG_PROD_ID ; 
 int STTS751_REG_RATE ; 
 int STTS751_REG_REV_ID ; 
 int STTS751_REG_SMBUS_TO ; 
 int STTS751_REG_STATUS ; 
 int STTS751_REG_TEMP_H ; 
 int STTS751_REG_TEMP_L ; 
 int STTS751_REG_TLIM ; 
 int STTS751_STATUS_TRIPH ; 
 int STTS751_STATUS_TRIPL ; 
 int STTS751_STATUS_TRIPT ; 
 int ST_MAN_ID ; 
 long clamp_val (long,int,int) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*,int) ; 
 struct stts751_priv* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_notice (TYPE_2__*,char*) ; 
 int /*<<< orphan*/  dev_warn (TYPE_2__*,char*) ; 
 scalar_t__ device_property_present (int /*<<< orphan*/ *,char*) ; 
 int device_property_read_bool (int /*<<< orphan*/ *,char*) ; 
 TYPE_2__* devm_hwmon_device_register_with_groups (int /*<<< orphan*/ *,int /*<<< orphan*/ ,struct stts751_priv*,int /*<<< orphan*/ ) ; 
 struct stts751_priv* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int find_closest_descending (unsigned long,int*,int) ; 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int /*<<< orphan*/ ) ; 
 struct stts751_priv* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct stts751_priv*) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int,int) ; 
 void* jiffies ; 
 int /*<<< orphan*/  kobject_uevent (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ kstrtol (char const*,int,long*) ; 
 scalar_t__ kstrtoul (char const*,int,unsigned long*) ; 
 int msecs_to_jiffies (int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int snprintf (char*,int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stts751_groups ; 
 TYPE_1__* stts751_id ; 
 int* stts751_intervals ; 
 int /*<<< orphan*/  sysfs_notify (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char*) ; 
 scalar_t__ time_after (void*,void*) ; 

__attribute__((used)) static int stts751_to_deg(s16 hw_val)
{
	return hw_val * 125 / 32;
}

__attribute__((used)) static s32 stts751_to_hw(int val)
{
	return DIV_ROUND_CLOSEST(val, 125) * 32;
}

__attribute__((used)) static int stts751_adjust_resolution(struct stts751_priv *priv)
{
	u8 res;

	switch (priv->interval) {
	case 9:
		/* 10 bits */
		res = 0;
		break;
	case 8:
		/* 11 bits */
		res = 1;
		break;
	default:
		/* 12 bits */
		res = 3;
		break;
	}

	if (priv->res == res)
		return 0;

	priv->config &= ~STTS751_CONF_RES_MASK;
	priv->config |= res << STTS751_CONF_RES_SHIFT;
	dev_dbg(&priv->client->dev, "setting res %d. config %x",
		res, priv->config);
	priv->res = res;

	return i2c_smbus_write_byte_data(priv->client,
				STTS751_REG_CONF, priv->config);
}

__attribute__((used)) static int stts751_update_temp(struct stts751_priv *priv)
{
	s32 integer1, integer2, frac;

	/*
	 * There is a trick here, like in the lm90 driver. We have to read two
	 * registers to get the sensor temperature, but we have to beware a
	 * conversion could occur between the readings. We could use the
	 * one-shot conversion register, but we don't want to do this (disables
	 * hardware monitoring). So the solution used here is to read the high
	 * byte once, then the low byte, then the high byte again. If the new
	 * high byte matches the old one, then we have a valid reading. Else we
	 * have to read the low byte again, and now we believe we have a correct
	 * reading.
	 */
	integer1 = i2c_smbus_read_byte_data(priv->client, STTS751_REG_TEMP_H);
	if (integer1 < 0) {
		dev_dbg(&priv->client->dev,
			"I2C read failed (temp H). ret: %x\n", integer1);
		return integer1;
	}

	frac = i2c_smbus_read_byte_data(priv->client, STTS751_REG_TEMP_L);
	if (frac < 0) {
		dev_dbg(&priv->client->dev,
			"I2C read failed (temp L). ret: %x\n", frac);
		return frac;
	}

	integer2 = i2c_smbus_read_byte_data(priv->client, STTS751_REG_TEMP_H);
	if (integer2 < 0) {
		dev_dbg(&priv->client->dev,
			"I2C 2nd read failed (temp H). ret: %x\n", integer2);
		return integer2;
	}

	if (integer1 != integer2) {
		frac = i2c_smbus_read_byte_data(priv->client,
						STTS751_REG_TEMP_L);
		if (frac < 0) {
			dev_dbg(&priv->client->dev,
				"I2C 2nd read failed (temp L). ret: %x\n",
				frac);
			return frac;
		}
	}

	priv->temp = stts751_to_deg((integer1 << 8) | frac);
	return 0;
}

__attribute__((used)) static int stts751_set_temp_reg16(struct stts751_priv *priv, int temp,
				  u8 hreg, u8 lreg)
{
	s32 hwval;
	int ret;

	hwval = stts751_to_hw(temp);

	ret = i2c_smbus_write_byte_data(priv->client, hreg, hwval >> 8);
	if (ret)
		return ret;

	return i2c_smbus_write_byte_data(priv->client, lreg, hwval & 0xff);
}

__attribute__((used)) static int stts751_set_temp_reg8(struct stts751_priv *priv, int temp, u8 reg)
{
	s32 hwval;

	hwval = stts751_to_hw(temp);
	return i2c_smbus_write_byte_data(priv->client, reg, hwval >> 8);
}

__attribute__((used)) static int stts751_read_reg16(struct stts751_priv *priv, int *temp,
			      u8 hreg, u8 lreg)
{
	int integer, frac;

	integer = i2c_smbus_read_byte_data(priv->client, hreg);
	if (integer < 0)
		return integer;

	frac = i2c_smbus_read_byte_data(priv->client, lreg);
	if (frac < 0)
		return frac;

	*temp = stts751_to_deg((integer << 8) | frac);

	return 0;
}

__attribute__((used)) static int stts751_read_reg8(struct stts751_priv *priv, int *temp, u8 reg)
{
	int integer;

	integer = i2c_smbus_read_byte_data(priv->client, reg);
	if (integer < 0)
		return integer;

	*temp = stts751_to_deg(integer << 8);

	return 0;
}

__attribute__((used)) static int stts751_update_alert(struct stts751_priv *priv)
{
	int ret;
	bool conv_done;
	int cache_time = msecs_to_jiffies(stts751_intervals[priv->interval]);

	/*
	 * Add another 10% because if we run faster than the HW conversion
	 * rate we will end up in reporting incorrectly alarms.
	 */
	cache_time += cache_time / 10;

	ret = i2c_smbus_read_byte_data(priv->client, STTS751_REG_STATUS);
	if (ret < 0)
		return ret;

	dev_dbg(&priv->client->dev, "status reg %x\n", ret);
	conv_done = ret & (STTS751_STATUS_TRIPH | STTS751_STATUS_TRIPL);
	/*
	 * Reset the cache if the cache time expired, or if we are sure
	 * we have valid data from a device conversion, or if we know
	 * our cache has been never written.
	 *
	 * Note that when the cache has been never written the point is
	 * to correctly initialize the timestamp, rather than clearing
	 * the cache values.
	 *
	 * Note that updating the cache timestamp when we get an alarm flag
	 * is required, otherwise we could incorrectly report alarms to be zero.
	 */
	if (time_after(jiffies,	priv->last_alert_update + cache_time) ||
	    conv_done || !priv->alert_valid) {
		priv->max_alert = false;
		priv->min_alert = false;
		priv->alert_valid = true;
		priv->last_alert_update = jiffies;
		dev_dbg(&priv->client->dev, "invalidating alert cache\n");
	}

	priv->max_alert |= !!(ret & STTS751_STATUS_TRIPH);
	priv->min_alert |= !!(ret & STTS751_STATUS_TRIPL);
	priv->therm_trip = !!(ret & STTS751_STATUS_TRIPT);

	dev_dbg(&priv->client->dev, "max_alert: %d, min_alert: %d, therm_trip: %d\n",
		priv->max_alert, priv->min_alert, priv->therm_trip);

	return 0;
}

__attribute__((used)) static void stts751_alert(struct i2c_client *client,
			  enum i2c_alert_protocol type, unsigned int data)
{
	int ret;
	struct stts751_priv *priv = i2c_get_clientdata(client);

	if (type != I2C_PROTOCOL_SMBUS_ALERT)
		return;

	dev_dbg(&client->dev, "alert!");

	mutex_lock(&priv->access_lock);
	ret = stts751_update_alert(priv);
	if (ret < 0) {
		/* default to worst case */
		priv->max_alert = true;
		priv->min_alert = true;

		dev_warn(priv->dev,
			 "Alert received, but can't communicate to the device. Triggering all alarms!");
	}

	if (priv->max_alert) {
		if (priv->notify_max)
			dev_notice(priv->dev, "got alert for HIGH temperature");
		priv->notify_max = false;

		/* unblock alert poll */
		sysfs_notify(&priv->dev->kobj, NULL, "temp1_max_alarm");
	}

	if (priv->min_alert) {
		if (priv->notify_min)
			dev_notice(priv->dev, "got alert for LOW temperature");
		priv->notify_min = false;

		/* unblock alert poll */
		sysfs_notify(&priv->dev->kobj, NULL, "temp1_min_alarm");
	}

	if (priv->min_alert || priv->max_alert)
		kobject_uevent(&priv->dev->kobj, KOBJ_CHANGE);

	mutex_unlock(&priv->access_lock);
}

__attribute__((used)) static int stts751_update(struct stts751_priv *priv)
{
	int ret;
	int cache_time = msecs_to_jiffies(stts751_intervals[priv->interval]);

	if (time_after(jiffies,	priv->last_update + cache_time) ||
	    !priv->data_valid) {
		ret = stts751_update_temp(priv);
		if (ret)
			return ret;

		ret = stts751_update_alert(priv);
		if (ret)
			return ret;
		priv->data_valid = true;
		priv->last_update = jiffies;
	}

	return 0;
}

__attribute__((used)) static ssize_t show_max_alarm(struct device *dev, struct device_attribute *attr,
			      char *buf)
{
	int ret;
	struct stts751_priv *priv = dev_get_drvdata(dev);

	mutex_lock(&priv->access_lock);
	ret = stts751_update(priv);
	if (!ret)
		priv->notify_max = true;
	mutex_unlock(&priv->access_lock);
	if (ret < 0)
		return ret;

	return snprintf(buf, PAGE_SIZE, "%d\n", priv->max_alert);
}

__attribute__((used)) static ssize_t show_min_alarm(struct device *dev, struct device_attribute *attr,
			      char *buf)
{
	int ret;
	struct stts751_priv *priv = dev_get_drvdata(dev);

	mutex_lock(&priv->access_lock);
	ret = stts751_update(priv);
	if (!ret)
		priv->notify_min = true;
	mutex_unlock(&priv->access_lock);
	if (ret < 0)
		return ret;

	return snprintf(buf, PAGE_SIZE, "%d\n", priv->min_alert);
}

__attribute__((used)) static ssize_t show_input(struct device *dev, struct device_attribute *attr,
			  char *buf)
{
	int ret;
	struct stts751_priv *priv = dev_get_drvdata(dev);

	mutex_lock(&priv->access_lock);
	ret = stts751_update(priv);
	mutex_unlock(&priv->access_lock);
	if (ret < 0)
		return ret;

	return snprintf(buf, PAGE_SIZE, "%d\n", priv->temp);
}

__attribute__((used)) static ssize_t show_therm(struct device *dev, struct device_attribute *attr,
			  char *buf)
{
	struct stts751_priv *priv = dev_get_drvdata(dev);

	return snprintf(buf, PAGE_SIZE, "%d\n", priv->therm);
}

__attribute__((used)) static ssize_t set_therm(struct device *dev, struct device_attribute *attr,
			 const char *buf, size_t count)
{
	int ret;
	long temp;
	struct stts751_priv *priv = dev_get_drvdata(dev);

	if (kstrtol(buf, 10, &temp) < 0)
		return -EINVAL;

	/* HW works in range -64C to +127.937C */
	temp = clamp_val(temp, -64000, 127937);
	mutex_lock(&priv->access_lock);
	ret = stts751_set_temp_reg8(priv, temp, STTS751_REG_TLIM);
	if (ret)
		goto exit;

	dev_dbg(&priv->client->dev, "setting therm %ld", temp);

	/*
	 * hysteresis reg is relative to therm, so the HW does not need to be
	 * adjusted, we need to update our local copy only.
	 */
	priv->hyst = temp - (priv->therm - priv->hyst);
	priv->therm = temp;

exit:
	mutex_unlock(&priv->access_lock);
	if (ret)
		return ret;

	return count;
}

__attribute__((used)) static ssize_t show_hyst(struct device *dev, struct device_attribute *attr,
			 char *buf)
{
	struct stts751_priv *priv = dev_get_drvdata(dev);

	return snprintf(buf, PAGE_SIZE, "%d\n", priv->hyst);
}

__attribute__((used)) static ssize_t set_hyst(struct device *dev, struct device_attribute *attr,
			const char *buf, size_t count)
{
	int ret;
	long temp;

	struct stts751_priv *priv = dev_get_drvdata(dev);

	if (kstrtol(buf, 10, &temp) < 0)
		return -EINVAL;

	mutex_lock(&priv->access_lock);
	/* HW works in range -64C to +127.937C */
	temp = clamp_val(temp, -64000, priv->therm);
	priv->hyst = temp;
	dev_dbg(&priv->client->dev, "setting hyst %ld", temp);
	temp = priv->therm - temp;
	ret = stts751_set_temp_reg8(priv, temp, STTS751_REG_HYST);
	mutex_unlock(&priv->access_lock);
	if (ret)
		return ret;

	return count;
}

__attribute__((used)) static ssize_t show_therm_trip(struct device *dev,
			       struct device_attribute *attr, char *buf)
{
	int ret;
	struct stts751_priv *priv = dev_get_drvdata(dev);

	mutex_lock(&priv->access_lock);
	ret = stts751_update(priv);
	mutex_unlock(&priv->access_lock);
	if (ret < 0)
		return ret;

	return snprintf(buf, PAGE_SIZE, "%d\n", priv->therm_trip);
}

__attribute__((used)) static ssize_t show_max(struct device *dev, struct device_attribute *attr,
			char *buf)
{
	struct stts751_priv *priv = dev_get_drvdata(dev);

	return snprintf(buf, PAGE_SIZE, "%d\n", priv->event_max);
}

__attribute__((used)) static ssize_t set_max(struct device *dev, struct device_attribute *attr,
		       const char *buf, size_t count)
{
	int ret;
	long temp;
	struct stts751_priv *priv = dev_get_drvdata(dev);

	if (kstrtol(buf, 10, &temp) < 0)
		return -EINVAL;

	mutex_lock(&priv->access_lock);
	/* HW works in range -64C to +127.937C */
	temp = clamp_val(temp, priv->event_min, 127937);
	ret = stts751_set_temp_reg16(priv, temp,
				     STTS751_REG_HLIM_H, STTS751_REG_HLIM_L);
	if (ret)
		goto exit;

	dev_dbg(&priv->client->dev, "setting event max %ld", temp);
	priv->event_max = temp;
	ret = count;
exit:
	mutex_unlock(&priv->access_lock);
	return ret;
}

__attribute__((used)) static ssize_t show_min(struct device *dev, struct device_attribute *attr,
			char *buf)
{
	struct stts751_priv *priv = dev_get_drvdata(dev);

	return snprintf(buf, PAGE_SIZE, "%d\n", priv->event_min);
}

__attribute__((used)) static ssize_t set_min(struct device *dev, struct device_attribute *attr,
		       const char *buf, size_t count)
{
	int ret;
	long temp;
	struct stts751_priv *priv = dev_get_drvdata(dev);

	if (kstrtol(buf, 10, &temp) < 0)
		return -EINVAL;

	mutex_lock(&priv->access_lock);
	/* HW works in range -64C to +127.937C */
	temp = clamp_val(temp, -64000, priv->event_max);
	ret = stts751_set_temp_reg16(priv, temp,
				     STTS751_REG_LLIM_H, STTS751_REG_LLIM_L);
	if (ret)
		goto exit;

	dev_dbg(&priv->client->dev, "setting event min %ld", temp);
	priv->event_min = temp;
	ret = count;
exit:
	mutex_unlock(&priv->access_lock);
	return ret;
}

__attribute__((used)) static ssize_t show_interval(struct device *dev, struct device_attribute *attr,
			     char *buf)
{
	struct stts751_priv *priv = dev_get_drvdata(dev);

	return snprintf(buf, PAGE_SIZE, "%d\n",
			stts751_intervals[priv->interval]);
}

__attribute__((used)) static ssize_t set_interval(struct device *dev, struct device_attribute *attr,
			    const char *buf, size_t count)
{
	unsigned long val;
	int idx;
	int ret = count;
	struct stts751_priv *priv = dev_get_drvdata(dev);

	if (kstrtoul(buf, 10, &val) < 0)
		return -EINVAL;

	idx = find_closest_descending(val, stts751_intervals,
				      ARRAY_SIZE(stts751_intervals));

	dev_dbg(&priv->client->dev, "setting interval. req:%lu, idx: %d, val: %d",
		val, idx, stts751_intervals[idx]);

	mutex_lock(&priv->access_lock);
	if (priv->interval == idx)
		goto exit;

	/*
	 * In early development stages I've become suspicious about the chip
	 * starting to misbehave if I ever set, even briefly, an invalid
	 * configuration. While I'm not sure this is really needed, be
	 * conservative and set rate/resolution in such an order that avoids
	 * passing through an invalid configuration.
	 */

	/* speed up: lower the resolution, then modify convrate */
	if (priv->interval < idx) {
		dev_dbg(&priv->client->dev, "lower resolution, then modify convrate");
		priv->interval = idx;
		ret = stts751_adjust_resolution(priv);
		if (ret)
			goto exit;
	}

	ret = i2c_smbus_write_byte_data(priv->client, STTS751_REG_RATE, idx);
	if (ret)
		goto exit;
	/* slow down: modify convrate, then raise resolution */
	if (priv->interval != idx) {
		dev_dbg(&priv->client->dev, "modify convrate, then raise resolution");
		priv->interval = idx;
		ret = stts751_adjust_resolution(priv);
		if (ret)
			goto exit;
	}
	ret = count;
exit:
	mutex_unlock(&priv->access_lock);

	return ret;
}

__attribute__((used)) static int stts751_detect(struct i2c_client *new_client,
			  struct i2c_board_info *info)
{
	struct i2c_adapter *adapter = new_client->adapter;
	const char *name;
	int tmp;

	if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
		return -ENODEV;

	tmp = i2c_smbus_read_byte_data(new_client, STTS751_REG_MAN_ID);
	if (tmp != ST_MAN_ID)
		return -ENODEV;

	/* lower temperaure registers always have bits 0-3 set to zero */
	tmp = i2c_smbus_read_byte_data(new_client, STTS751_REG_TEMP_L);
	if (tmp & 0xf)
		return -ENODEV;

	tmp = i2c_smbus_read_byte_data(new_client, STTS751_REG_HLIM_L);
	if (tmp & 0xf)
		return -ENODEV;

	tmp = i2c_smbus_read_byte_data(new_client, STTS751_REG_LLIM_L);
	if (tmp & 0xf)
		return -ENODEV;

	/* smbus timeout register always have bits 0-7 set to zero */
	tmp = i2c_smbus_read_byte_data(new_client, STTS751_REG_SMBUS_TO);
	if (tmp & 0x7f)
		return -ENODEV;

	tmp = i2c_smbus_read_byte_data(new_client, STTS751_REG_PROD_ID);

	switch (tmp) {
	case STTS751_0_PROD_ID:
		name = "STTS751-0";
		break;
	case STTS751_1_PROD_ID:
		name = "STTS751-1";
		break;
	default:
		return -ENODEV;
	}
	dev_dbg(&new_client->dev, "Chip %s detected", name);

	strlcpy(info->type, stts751_id[0].name, I2C_NAME_SIZE);
	return 0;
}

__attribute__((used)) static int stts751_read_chip_config(struct stts751_priv *priv)
{
	int ret;
	int tmp;

	ret = i2c_smbus_read_byte_data(priv->client, STTS751_REG_CONF);
	if (ret < 0)
		return ret;
	priv->config = ret;
	priv->res = (ret & STTS751_CONF_RES_MASK) >> STTS751_CONF_RES_SHIFT;

	ret = i2c_smbus_read_byte_data(priv->client, STTS751_REG_RATE);
	if (ret < 0)
		return ret;
	if (ret >= ARRAY_SIZE(stts751_intervals)) {
		dev_err(priv->dev, "Unrecognized conversion rate 0x%x\n", ret);
		return -ENODEV;
	}
	priv->interval = ret;

	ret = stts751_read_reg16(priv, &priv->event_max,
				 STTS751_REG_HLIM_H, STTS751_REG_HLIM_L);
	if (ret)
		return ret;

	ret = stts751_read_reg16(priv, &priv->event_min,
				 STTS751_REG_LLIM_H, STTS751_REG_LLIM_L);
	if (ret)
		return ret;

	ret = stts751_read_reg8(priv, &priv->therm, STTS751_REG_TLIM);
	if (ret)
		return ret;

	ret = stts751_read_reg8(priv, &tmp, STTS751_REG_HYST);
	if (ret)
		return ret;
	priv->hyst = priv->therm - tmp;

	return 0;
}

__attribute__((used)) static int stts751_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	struct stts751_priv *priv;
	int ret;
	bool smbus_nto;
	int rev_id;

	priv = devm_kzalloc(&client->dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	priv->client = client;
	priv->notify_max = true;
	priv->notify_min = true;
	i2c_set_clientdata(client, priv);
	mutex_init(&priv->access_lock);

	if (device_property_present(&client->dev,
				    "smbus-timeout-disable")) {
		smbus_nto = device_property_read_bool(&client->dev,
						      "smbus-timeout-disable");

		ret = i2c_smbus_write_byte_data(client,	STTS751_REG_SMBUS_TO,
						smbus_nto ? 0 : 0x80);
		if (ret)
			return ret;
	}

	rev_id = i2c_smbus_read_byte_data(client, STTS751_REG_REV_ID);
	if (rev_id < 0)
		return -ENODEV;
	if (rev_id != 0x1) {
		dev_dbg(&client->dev, "Chip revision 0x%x is untested\n",
			rev_id);
	}

	ret = stts751_read_chip_config(priv);
	if (ret)
		return ret;

	priv->config &= ~(STTS751_CONF_STOP | STTS751_CONF_EVENT_DIS);
	ret = i2c_smbus_write_byte_data(client,	STTS751_REG_CONF, priv->config);
	if (ret)
		return ret;

	priv->dev = devm_hwmon_device_register_with_groups(&client->dev,
							client->name, priv,
							stts751_groups);
	return PTR_ERR_OR_ZERO(priv->dev);
}

