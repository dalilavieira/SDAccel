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
struct sensor_device_attribute {unsigned int index; } ;
struct ina3221_data {int* shunt_resistors; struct device** fields; struct device* regmap; } ;
struct i2c_device_id {int dummy; } ;
struct device {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  name; struct device dev; } ;
struct device_attribute {int dummy; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int DIV_ROUND_CLOSEST (int,int) ; 
 int ENOMEM ; 
 int F_MAX_FIELDS ; 
 size_t F_RST ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int INA3221_NUM_CHANNELS ; 
 int INA3221_RSHUNT_DEFAULT ; 
 int INT_MAX ; 
 int INT_MIN ; 
 scalar_t__ IS_ERR (struct device*) ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 int PTR_ERR (struct device*) ; 
 int clamp_val (int,int,int) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 struct ina3221_data* dev_get_drvdata (struct device*) ; 
 struct device* devm_hwmon_device_register_with_groups (struct device*,int /*<<< orphan*/ ,struct ina3221_data*,int /*<<< orphan*/ ) ; 
 struct ina3221_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 struct device* devm_regmap_field_alloc (struct device*,struct device*,int /*<<< orphan*/ ) ; 
 struct device* devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ina3221_groups ; 
 int /*<<< orphan*/ * ina3221_reg_fields ; 
 int /*<<< orphan*/  ina3221_regmap_config ; 
 int kstrtoint (char const*,int /*<<< orphan*/ ,int*) ; 
 unsigned int* register_channel ; 
 int regmap_field_read (struct device*,unsigned int*) ; 
 int regmap_field_write (struct device*,int) ; 
 int regmap_read (struct device*,unsigned int,unsigned int*) ; 
 int regmap_write (struct device*,unsigned int,int) ; 
 int sign_extend32 (unsigned int,int) ; 
 int snprintf (char*,int /*<<< orphan*/ ,char*,unsigned int) ; 
 struct sensor_device_attribute* to_sensor_dev_attr (struct device_attribute*) ; 

__attribute__((used)) static int ina3221_read_value(struct ina3221_data *ina, unsigned int reg,
			      int *val)
{
	unsigned int regval;
	int ret;

	ret = regmap_read(ina->regmap, reg, &regval);
	if (ret)
		return ret;

	*val = sign_extend32(regval >> 3, 12);

	return 0;
}

__attribute__((used)) static ssize_t ina3221_show_bus_voltage(struct device *dev,
					struct device_attribute *attr,
					char *buf)
{
	struct sensor_device_attribute *sd_attr = to_sensor_dev_attr(attr);
	struct ina3221_data *ina = dev_get_drvdata(dev);
	unsigned int reg = sd_attr->index;
	int val, voltage_mv, ret;

	ret = ina3221_read_value(ina, reg, &val);
	if (ret)
		return ret;

	voltage_mv = val * 8;

	return snprintf(buf, PAGE_SIZE, "%d\n", voltage_mv);
}

__attribute__((used)) static ssize_t ina3221_show_shunt_voltage(struct device *dev,
					  struct device_attribute *attr,
					  char *buf)
{
	struct sensor_device_attribute *sd_attr = to_sensor_dev_attr(attr);
	struct ina3221_data *ina = dev_get_drvdata(dev);
	unsigned int reg = sd_attr->index;
	int val, voltage_uv, ret;

	ret = ina3221_read_value(ina, reg, &val);
	if (ret)
		return ret;
	voltage_uv = val * 40;

	return snprintf(buf, PAGE_SIZE, "%d\n", voltage_uv);
}

__attribute__((used)) static ssize_t ina3221_show_current(struct device *dev,
				    struct device_attribute *attr, char *buf)
{
	struct sensor_device_attribute *sd_attr = to_sensor_dev_attr(attr);
	struct ina3221_data *ina = dev_get_drvdata(dev);
	unsigned int reg = sd_attr->index;
	unsigned int channel = register_channel[reg];
	int resistance_uo = ina->shunt_resistors[channel];
	int val, current_ma, voltage_nv, ret;

	ret = ina3221_read_value(ina, reg, &val);
	if (ret)
		return ret;
	voltage_nv = val * 40000;

	current_ma = DIV_ROUND_CLOSEST(voltage_nv, resistance_uo);

	return snprintf(buf, PAGE_SIZE, "%d\n", current_ma);
}

__attribute__((used)) static ssize_t ina3221_set_current(struct device *dev,
				   struct device_attribute *attr,
				   const char *buf, size_t count)
{
	struct sensor_device_attribute *sd_attr = to_sensor_dev_attr(attr);
	struct ina3221_data *ina = dev_get_drvdata(dev);
	unsigned int reg = sd_attr->index;
	unsigned int channel = register_channel[reg];
	int resistance_uo = ina->shunt_resistors[channel];
	int val, current_ma, voltage_uv, ret;

	ret = kstrtoint(buf, 0, &current_ma);
	if (ret)
		return ret;

	/* clamp current */
	current_ma = clamp_val(current_ma,
			       INT_MIN / resistance_uo,
			       INT_MAX / resistance_uo);

	voltage_uv = DIV_ROUND_CLOSEST(current_ma * resistance_uo, 1000);

	/* clamp voltage */
	voltage_uv = clamp_val(voltage_uv, -163800, 163800);

	/* 1 / 40uV(scale) << 3(register shift) = 5 */
	val = DIV_ROUND_CLOSEST(voltage_uv, 5) & 0xfff8;

	ret = regmap_write(ina->regmap, reg, val);
	if (ret)
		return ret;

	return count;
}

__attribute__((used)) static ssize_t ina3221_show_shunt(struct device *dev,
				  struct device_attribute *attr, char *buf)
{
	struct sensor_device_attribute *sd_attr = to_sensor_dev_attr(attr);
	struct ina3221_data *ina = dev_get_drvdata(dev);
	unsigned int channel = sd_attr->index;
	unsigned int resistance_uo;

	resistance_uo = ina->shunt_resistors[channel];

	return snprintf(buf, PAGE_SIZE, "%d\n", resistance_uo);
}

__attribute__((used)) static ssize_t ina3221_set_shunt(struct device *dev,
				 struct device_attribute *attr,
				 const char *buf, size_t count)
{
	struct sensor_device_attribute *sd_attr = to_sensor_dev_attr(attr);
	struct ina3221_data *ina = dev_get_drvdata(dev);
	unsigned int channel = sd_attr->index;
	int val;
	int ret;

	ret = kstrtoint(buf, 0, &val);
	if (ret)
		return ret;

	val = clamp_val(val, 1, INT_MAX);

	ina->shunt_resistors[channel] = val;

	return count;
}

__attribute__((used)) static ssize_t ina3221_show_alert(struct device *dev,
				  struct device_attribute *attr, char *buf)
{
	struct sensor_device_attribute *sd_attr = to_sensor_dev_attr(attr);
	struct ina3221_data *ina = dev_get_drvdata(dev);
	unsigned int field = sd_attr->index;
	unsigned int regval;
	int ret;

	ret = regmap_field_read(ina->fields[field], &regval);
	if (ret)
		return ret;

	return snprintf(buf, PAGE_SIZE, "%d\n", regval);
}

__attribute__((used)) static int ina3221_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	struct device *dev = &client->dev;
	struct ina3221_data *ina;
	struct device *hwmon_dev;
	int i, ret;

	ina = devm_kzalloc(dev, sizeof(*ina), GFP_KERNEL);
	if (!ina)
		return -ENOMEM;

	ina->regmap = devm_regmap_init_i2c(client, &ina3221_regmap_config);
	if (IS_ERR(ina->regmap)) {
		dev_err(dev, "Unable to allocate register map\n");
		return PTR_ERR(ina->regmap);
	}

	for (i = 0; i < F_MAX_FIELDS; i++) {
		ina->fields[i] = devm_regmap_field_alloc(dev,
							 ina->regmap,
							 ina3221_reg_fields[i]);
		if (IS_ERR(ina->fields[i])) {
			dev_err(dev, "Unable to allocate regmap fields\n");
			return PTR_ERR(ina->fields[i]);
		}
	}

	for (i = 0; i < INA3221_NUM_CHANNELS; i++)
		ina->shunt_resistors[i] = INA3221_RSHUNT_DEFAULT;

	ret = regmap_field_write(ina->fields[F_RST], true);
	if (ret) {
		dev_err(dev, "Unable to reset device\n");
		return ret;
	}

	hwmon_dev = devm_hwmon_device_register_with_groups(dev,
							   client->name,
							   ina, ina3221_groups);
	if (IS_ERR(hwmon_dev)) {
		dev_err(dev, "Unable to register hwmon device\n");
		return PTR_ERR(hwmon_dev);
	}

	return 0;
}

