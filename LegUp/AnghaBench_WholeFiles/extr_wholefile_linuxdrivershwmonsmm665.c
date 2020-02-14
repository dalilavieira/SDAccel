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
typedef  int u16 ;
struct smm665_data {int valid; int faults; int* adc; int* alarm_min_limit; int* alarm_max_limit; int* critical_min_limit; int* critical_max_limit; int type; struct i2c_client* cmdreg; int /*<<< orphan*/  conversion_time; struct i2c_client* client; int /*<<< orphan*/  update_lock; scalar_t__ last_updated; } ;
struct sensor_device_attribute {int index; } ;
struct i2c_device_id {int driver_data; } ;
struct i2c_client {int addr; int /*<<< orphan*/  name; int /*<<< orphan*/  dev; struct i2c_adapter* adapter; } ;
struct i2c_adapter {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {int valid; int faults; int* adc; int* alarm_min_limit; int* alarm_max_limit; int* critical_min_limit; int* critical_max_limit; int type; struct i2c_client* cmdreg; int /*<<< orphan*/  conversion_time; struct i2c_client* client; int /*<<< orphan*/  update_lock; scalar_t__ last_updated; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ENXIO ; 
 struct smm665_data* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ HZ ; 
 int I2C_FUNC_SMBUS_BYTE_DATA ; 
 int I2C_FUNC_SMBUS_WORD_DATA ; 
 scalar_t__ IS_ERR (struct smm665_data*) ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 int PTR_ERR (struct smm665_data*) ; 
 int SMM665_12VIN_ADC_TO_VOLTS (int) ; 
 int SMM665_ADC_MASK ; 
 int /*<<< orphan*/  SMM665_ADC_WAIT_SMM665 ; 
 int /*<<< orphan*/  SMM665_ADC_WAIT_SMM766 ; 
 int SMM665_ADOC_ENABLE ; 
 int SMM665_AIN_ADC_TO_VOLTS (int) ; 
 int SMM665_CMDREG_BASE ; 
 int SMM665_LIMIT_BASE ; 
#define  SMM665_MISC16_ADC_DATA_12V 143 
#define  SMM665_MISC16_ADC_DATA_A 142 
#define  SMM665_MISC16_ADC_DATA_AIN1 141 
#define  SMM665_MISC16_ADC_DATA_AIN2 140 
#define  SMM665_MISC16_ADC_DATA_B 139 
#define  SMM665_MISC16_ADC_DATA_C 138 
#define  SMM665_MISC16_ADC_DATA_D 137 
#define  SMM665_MISC16_ADC_DATA_E 136 
#define  SMM665_MISC16_ADC_DATA_F 135 
#define  SMM665_MISC16_ADC_DATA_INT_TEMP 134 
#define  SMM665_MISC16_ADC_DATA_VDD 133 
 int SMM665_MISC8_CMD_STS ; 
 int SMM665_MISC8_STATUS1 ; 
 int SMM665_NUM_ADC ; 
 int SMM665_REGMASK ; 
 int SMM665_TEMP_ADC_TO_CELSIUS (int) ; 
 int SMM665_VMON_ADC_TO_VOLTS (int) ; 
 int /*<<< orphan*/  WARN_ON_ONCE (int) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,int,...) ; 
 struct smm665_data* dev_get_drvdata (struct smm665_data*) ; 
 struct smm665_data* devm_hwmon_device_register_with_groups (int /*<<< orphan*/ *,int /*<<< orphan*/ ,struct smm665_data*,int /*<<< orphan*/ ) ; 
 struct smm665_data* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int) ; 
 struct smm665_data* i2c_get_clientdata (struct i2c_client*) ; 
 struct i2c_client* i2c_new_dummy (struct i2c_adapter*,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct smm665_data*) ; 
 scalar_t__ i2c_smbus_read_byte_data (struct i2c_client*,int) ; 
 int i2c_smbus_read_word_swapped (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_unregister_device (struct i2c_client*) ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
#define  smm465 132 
#define  smm665 131 
 int /*<<< orphan*/  smm665_groups ; 
 scalar_t__ smm665_is_critical (int) ; 
#define  smm665c 130 
#define  smm764 129 
#define  smm766 128 
 int snprintf (char*,int /*<<< orphan*/ ,char*,int) ; 
 scalar_t__ time_after (scalar_t__,scalar_t__) ; 
 struct sensor_device_attribute* to_sensor_dev_attr (struct device_attribute*) ; 
 int /*<<< orphan*/  udelay (int /*<<< orphan*/ ) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static int smm665_read16(struct i2c_client *client, int reg)
{
	int rv, val;

	rv = i2c_smbus_read_byte_data(client, reg);
	if (rv < 0)
		return rv;
	val = rv << 8;
	rv = i2c_smbus_read_byte_data(client, reg + 1);
	if (rv < 0)
		return rv;
	val |= rv;
	return val;
}

__attribute__((used)) static int smm665_read_adc(struct smm665_data *data, int adc)
{
	struct i2c_client *client = data->cmdreg;
	int rv;
	int radc;

	/*
	 * Algorithm for reading ADC, per SMM665 datasheet
	 *
	 *  {[S][addr][W][Ack]} {[offset][Ack]} {[S][addr][R][Nack]}
	 * [wait conversion time]
	 *  {[S][addr][R][Ack]} {[datahi][Ack]} {[datalo][Ack][P]}
	 *
	 * To implement the first part of this exchange,
	 * do a full read transaction and expect a failure/Nack.
	 * This sets up the address pointer on the SMM665
	 * and starts the ADC conversion.
	 * Then do a two-byte read transaction.
	 */
	rv = i2c_smbus_read_byte_data(client, adc << 3);
	if (rv != -ENXIO) {
		/*
		 * We expect ENXIO to reflect NACK
		 * (per Documentation/i2c/fault-codes).
		 * Everything else is an error.
		 */
		dev_dbg(&client->dev,
			"Unexpected return code %d when setting ADC index", rv);
		return (rv < 0) ? rv : -EIO;
	}

	udelay(data->conversion_time);

	/*
	 * Now read two bytes.
	 *
	 * Neither i2c_smbus_read_byte() nor
	 * i2c_smbus_read_block_data() worked here,
	 * so use i2c_smbus_read_word_swapped() instead.
	 * We could also try to use i2c_master_recv(),
	 * but that is not always supported.
	 */
	rv = i2c_smbus_read_word_swapped(client, 0);
	if (rv < 0) {
		dev_dbg(&client->dev, "Failed to read ADC value: error %d", rv);
		return rv;
	}
	/*
	 * Validate/verify readback adc channel (in bit 11..14).
	 */
	radc = (rv >> 11) & 0x0f;
	if (radc != adc) {
		dev_dbg(&client->dev, "Unexpected RADC: Expected %d got %d",
			adc, radc);
		return -EIO;
	}

	return rv & SMM665_ADC_MASK;
}

__attribute__((used)) static struct smm665_data *smm665_update_device(struct device *dev)
{
	struct smm665_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	struct smm665_data *ret = data;

	mutex_lock(&data->update_lock);

	if (time_after(jiffies, data->last_updated + HZ) || !data->valid) {
		int i, val;

		/*
		 * read status registers
		 */
		val = smm665_read16(client, SMM665_MISC8_STATUS1);
		if (unlikely(val < 0)) {
			ret = ERR_PTR(val);
			goto abort;
		}
		data->faults = val;

		/* Read adc registers */
		for (i = 0; i < SMM665_NUM_ADC; i++) {
			val = smm665_read_adc(data, i);
			if (unlikely(val < 0)) {
				ret = ERR_PTR(val);
				goto abort;
			}
			data->adc[i] = val;
		}
		data->last_updated = jiffies;
		data->valid = 1;
	}
abort:
	mutex_unlock(&data->update_lock);
	return ret;
}

__attribute__((used)) static int smm665_convert(u16 adcval, int index)
{
	int val = 0;

	switch (index) {
	case SMM665_MISC16_ADC_DATA_12V:
		val = SMM665_12VIN_ADC_TO_VOLTS(adcval & SMM665_ADC_MASK);
		break;

	case SMM665_MISC16_ADC_DATA_VDD:
	case SMM665_MISC16_ADC_DATA_A:
	case SMM665_MISC16_ADC_DATA_B:
	case SMM665_MISC16_ADC_DATA_C:
	case SMM665_MISC16_ADC_DATA_D:
	case SMM665_MISC16_ADC_DATA_E:
	case SMM665_MISC16_ADC_DATA_F:
		val = SMM665_VMON_ADC_TO_VOLTS(adcval & SMM665_ADC_MASK);
		break;

	case SMM665_MISC16_ADC_DATA_AIN1:
	case SMM665_MISC16_ADC_DATA_AIN2:
		val = SMM665_AIN_ADC_TO_VOLTS(adcval & SMM665_ADC_MASK);
		break;

	case SMM665_MISC16_ADC_DATA_INT_TEMP:
		val = SMM665_TEMP_ADC_TO_CELSIUS(adcval & SMM665_ADC_MASK);
		break;

	default:
		/* If we get here, the developer messed up */
		WARN_ON_ONCE(1);
		break;
	}

	return val;
}

__attribute__((used)) static int smm665_get_min(struct device *dev, int index)
{
	struct smm665_data *data = dev_get_drvdata(dev);

	return data->alarm_min_limit[index];
}

__attribute__((used)) static int smm665_get_max(struct device *dev, int index)
{
	struct smm665_data *data = dev_get_drvdata(dev);

	return data->alarm_max_limit[index];
}

__attribute__((used)) static int smm665_get_lcrit(struct device *dev, int index)
{
	struct smm665_data *data = dev_get_drvdata(dev);

	return data->critical_min_limit[index];
}

__attribute__((used)) static int smm665_get_crit(struct device *dev, int index)
{
	struct smm665_data *data = dev_get_drvdata(dev);

	return data->critical_max_limit[index];
}

__attribute__((used)) static ssize_t smm665_show_crit_alarm(struct device *dev,
				      struct device_attribute *da, char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
	struct smm665_data *data = smm665_update_device(dev);
	int val = 0;

	if (IS_ERR(data))
		return PTR_ERR(data);

	if (data->faults & (1 << attr->index))
		val = 1;

	return snprintf(buf, PAGE_SIZE, "%d\n", val);
}

__attribute__((used)) static ssize_t smm665_show_input(struct device *dev,
				 struct device_attribute *da, char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
	struct smm665_data *data = smm665_update_device(dev);
	int adc = attr->index;
	int val;

	if (IS_ERR(data))
		return PTR_ERR(data);

	val = smm665_convert(data->adc[adc], adc);
	return snprintf(buf, PAGE_SIZE, "%d\n", val);
}

__attribute__((used)) static int smm665_probe(struct i2c_client *client,
			const struct i2c_device_id *id)
{
	struct i2c_adapter *adapter = client->adapter;
	struct smm665_data *data;
	struct device *hwmon_dev;
	int i, ret;

	if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA
				     | I2C_FUNC_SMBUS_WORD_DATA))
		return -ENODEV;

	if (i2c_smbus_read_byte_data(client, SMM665_ADOC_ENABLE) < 0)
		return -ENODEV;

	data = devm_kzalloc(&client->dev, sizeof(*data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	i2c_set_clientdata(client, data);
	mutex_init(&data->update_lock);

	data->client = client;
	data->type = id->driver_data;
	data->cmdreg = i2c_new_dummy(adapter, (client->addr & ~SMM665_REGMASK)
				     | SMM665_CMDREG_BASE);
	if (!data->cmdreg)
		return -ENOMEM;

	switch (data->type) {
	case smm465:
	case smm665:
		data->conversion_time = SMM665_ADC_WAIT_SMM665;
		break;
	case smm665c:
	case smm764:
	case smm766:
		data->conversion_time = SMM665_ADC_WAIT_SMM766;
		break;
	}

	ret = -ENODEV;
	if (i2c_smbus_read_byte_data(data->cmdreg, SMM665_MISC8_CMD_STS) < 0)
		goto out_unregister;

	/*
	 * Read limits.
	 *
	 * Limit registers start with register SMM665_LIMIT_BASE.
	 * Each channel uses 8 registers, providing four limit values
	 * per channel. Each limit value requires two registers, with the
	 * high byte in the first register and the low byte in the second
	 * register. The first two limits are under limit values, followed
	 * by two over limit values.
	 *
	 * Limit register order matches the ADC register order, so we use
	 * ADC register defines throughout the code to index limit registers.
	 *
	 * We save the first retrieved value both as "critical" and "alarm"
	 * value. The second value overwrites either the critical or the
	 * alarm value, depending on its configuration. This ensures that both
	 * critical and alarm values are initialized, even if both registers are
	 * configured as critical or non-critical.
	 */
	for (i = 0; i < SMM665_NUM_ADC; i++) {
		int val;

		val = smm665_read16(client, SMM665_LIMIT_BASE + i * 8);
		if (unlikely(val < 0))
			goto out_unregister;
		data->critical_min_limit[i] = data->alarm_min_limit[i]
		  = smm665_convert(val, i);
		val = smm665_read16(client, SMM665_LIMIT_BASE + i * 8 + 2);
		if (unlikely(val < 0))
			goto out_unregister;
		if (smm665_is_critical(val))
			data->critical_min_limit[i] = smm665_convert(val, i);
		else
			data->alarm_min_limit[i] = smm665_convert(val, i);
		val = smm665_read16(client, SMM665_LIMIT_BASE + i * 8 + 4);
		if (unlikely(val < 0))
			goto out_unregister;
		data->critical_max_limit[i] = data->alarm_max_limit[i]
		  = smm665_convert(val, i);
		val = smm665_read16(client, SMM665_LIMIT_BASE + i * 8 + 6);
		if (unlikely(val < 0))
			goto out_unregister;
		if (smm665_is_critical(val))
			data->critical_max_limit[i] = smm665_convert(val, i);
		else
			data->alarm_max_limit[i] = smm665_convert(val, i);
	}

	hwmon_dev = devm_hwmon_device_register_with_groups(&client->dev,
							   client->name, data,
							   smm665_groups);
	if (IS_ERR(hwmon_dev)) {
		ret = PTR_ERR(hwmon_dev);
		goto out_unregister;
	}

	return 0;

out_unregister:
	i2c_unregister_device(data->cmdreg);
	return ret;
}

__attribute__((used)) static int smm665_remove(struct i2c_client *client)
{
	struct smm665_data *data = i2c_get_clientdata(client);

	i2c_unregister_device(data->cmdreg);
	return 0;
}

