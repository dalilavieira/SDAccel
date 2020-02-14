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
typedef  int umode_t ;
typedef  int u8 ;
typedef  int u32 ;
struct regmap {int dummy; } ;
struct lm95245_data {int interval; int /*<<< orphan*/  update_lock; struct regmap* regmap; } ;
struct i2c_device_id {int dummy; } ;
struct device {int dummy; } ;
struct i2c_client {int addr; int /*<<< orphan*/  name; struct device dev; struct i2c_adapter* adapter; } ;
struct i2c_board_info {int /*<<< orphan*/  type; } ;
struct i2c_adapter {int dummy; } ;
typedef  enum hwmon_sensor_types { ____Placeholder_hwmon_sensor_types } hwmon_sensor_types ;

/* Variables and functions */
 int CFG2_REMOTE_TT ; 
 int CFG_STOP ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_BYTE_DATA ; 
 int /*<<< orphan*/  I2C_NAME_SIZE ; 
 scalar_t__ IS_ERR (struct regmap*) ; 
#define  LM95235_REVISION 164 
#define  LM95245_REG_RW_COMMON_HYSTERESIS 163 
#define  LM95245_REG_RW_CONFIG1 162 
#define  LM95245_REG_RW_CONFIG2 161 
#define  LM95245_REG_RW_CONVERS_RATE 160 
#define  LM95245_REG_RW_LOCAL_OS_TCRIT_LIMIT 159 
#define  LM95245_REG_RW_REMOTE_OFFH 158 
#define  LM95245_REG_RW_REMOTE_OFFL 157 
#define  LM95245_REG_RW_REMOTE_OS_LIMIT 156 
#define  LM95245_REG_RW_REMOTE_TCRIT_LIMIT 155 
 int /*<<< orphan*/  LM95245_REG_R_CHIP_ID ; 
#define  LM95245_REG_R_LOCAL_TEMPH_S 154 
#define  LM95245_REG_R_LOCAL_TEMPL_S 153 
 int /*<<< orphan*/  LM95245_REG_R_MAN_ID ; 
#define  LM95245_REG_R_REMOTE_TEMPH_S 152 
#define  LM95245_REG_R_REMOTE_TEMPH_U 151 
#define  LM95245_REG_R_REMOTE_TEMPL_S 150 
#define  LM95245_REG_R_REMOTE_TEMPL_U 149 
#define  LM95245_REG_R_STATUS1 148 
#define  LM95245_REG_R_STATUS2 147 
#define  LM95245_REG_W_ONE_SHOT 146 
#define  LM95245_REVISION 145 
 int MANUFACTURER_ID ; 
 int PTR_ERR (struct regmap*) ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
#define  RATE_CR0063 144 
#define  RATE_CR0364 143 
#define  RATE_CR1000 142 
#define  RATE_CR2500 141 
 int STATUS1_DIODE_FAULT ; 
 int STATUS1_LOC ; 
 int STATUS1_ROS ; 
 int STATUS1_RTCRIT ; 
 int S_IRUGO ; 
 int S_IWUSR ; 
 long clamp_val (long,int,int) ; 
 struct lm95245_data* dev_get_drvdata (struct device*) ; 
 struct device* devm_hwmon_device_register_with_info (struct device*,int /*<<< orphan*/ ,struct lm95245_data*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 struct lm95245_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 struct regmap* devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
#define  hwmon_chip 140 
#define  hwmon_chip_update_interval 139 
#define  hwmon_temp 138 
#define  hwmon_temp_crit 137 
#define  hwmon_temp_crit_alarm 136 
#define  hwmon_temp_crit_hyst 135 
#define  hwmon_temp_fault 134 
#define  hwmon_temp_input 133 
#define  hwmon_temp_max 132 
#define  hwmon_temp_max_alarm 131 
#define  hwmon_temp_max_hyst 130 
#define  hwmon_temp_offset 129 
#define  hwmon_temp_type 128 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lm95245_chip_info ; 
 int /*<<< orphan*/  lm95245_regmap_config ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int regmap_read (struct regmap*,int,...) ; 
 int regmap_update_bits (struct regmap*,int,int,int) ; 
 int regmap_write (struct regmap*,int,long) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int temp_from_reg_unsigned(u8 val_h, u8 val_l)
{
	return val_h * 1000 + val_l * 1000 / 256;
}

__attribute__((used)) static int temp_from_reg_signed(u8 val_h, u8 val_l)
{
	if (val_h & 0x80)
		return (val_h - 0x100) * 1000;
	return temp_from_reg_unsigned(val_h, val_l);
}

__attribute__((used)) static int lm95245_read_conversion_rate(struct lm95245_data *data)
{
	unsigned int rate;
	int ret;

	ret = regmap_read(data->regmap, LM95245_REG_RW_CONVERS_RATE, &rate);
	if (ret < 0)
		return ret;

	switch (rate) {
	case RATE_CR0063:
		data->interval = 63;
		break;
	case RATE_CR0364:
		data->interval = 364;
		break;
	case RATE_CR1000:
		data->interval = 1000;
		break;
	case RATE_CR2500:
	default:
		data->interval = 2500;
		break;
	}
	return 0;
}

__attribute__((used)) static int lm95245_set_conversion_rate(struct lm95245_data *data, long interval)
{
	int ret, rate;

	if (interval <= 63) {
		interval = 63;
		rate = RATE_CR0063;
	} else if (interval <= 364) {
		interval = 364;
		rate = RATE_CR0364;
	} else if (interval <= 1000) {
		interval = 1000;
		rate = RATE_CR1000;
	} else {
		interval = 2500;
		rate = RATE_CR2500;
	}

	ret = regmap_write(data->regmap, LM95245_REG_RW_CONVERS_RATE, rate);
	if (ret < 0)
		return ret;

	data->interval = interval;
	return 0;
}

__attribute__((used)) static int lm95245_read_temp(struct device *dev, u32 attr, int channel,
			     long *val)
{
	struct lm95245_data *data = dev_get_drvdata(dev);
	struct regmap *regmap = data->regmap;
	int ret, regl, regh, regvall, regvalh;

	switch (attr) {
	case hwmon_temp_input:
		regl = channel ? LM95245_REG_R_REMOTE_TEMPL_S :
				 LM95245_REG_R_LOCAL_TEMPL_S;
		regh = channel ? LM95245_REG_R_REMOTE_TEMPH_S :
				 LM95245_REG_R_LOCAL_TEMPH_S;
		ret = regmap_read(regmap, regl, &regvall);
		if (ret < 0)
			return ret;
		ret = regmap_read(regmap, regh, &regvalh);
		if (ret < 0)
			return ret;
		/*
		 * Local temp is always signed.
		 * Remote temp has both signed and unsigned data.
		 * Use signed calculation for remote if signed bit is set
		 * or if reported temperature is below signed limit.
		 */
		if (!channel || (regvalh & 0x80) || regvalh < 0x7f) {
			*val = temp_from_reg_signed(regvalh, regvall);
			return 0;
		}
		ret = regmap_read(regmap, LM95245_REG_R_REMOTE_TEMPL_U,
				  &regvall);
		if (ret < 0)
			return ret;
		ret = regmap_read(regmap, LM95245_REG_R_REMOTE_TEMPH_U,
				  &regvalh);
		if (ret < 0)
			return ret;
		*val = temp_from_reg_unsigned(regvalh, regvall);
		return 0;
	case hwmon_temp_max:
		ret = regmap_read(regmap, LM95245_REG_RW_REMOTE_OS_LIMIT,
				  &regvalh);
		if (ret < 0)
			return ret;
		*val = regvalh * 1000;
		return 0;
	case hwmon_temp_crit:
		regh = channel ? LM95245_REG_RW_REMOTE_TCRIT_LIMIT :
				 LM95245_REG_RW_LOCAL_OS_TCRIT_LIMIT;
		ret = regmap_read(regmap, regh, &regvalh);
		if (ret < 0)
			return ret;
		*val = regvalh * 1000;
		return 0;
	case hwmon_temp_max_hyst:
		ret = regmap_read(regmap, LM95245_REG_RW_REMOTE_OS_LIMIT,
				  &regvalh);
		if (ret < 0)
			return ret;
		ret = regmap_read(regmap, LM95245_REG_RW_COMMON_HYSTERESIS,
				  &regvall);
		if (ret < 0)
			return ret;
		*val = (regvalh - regvall) * 1000;
		return 0;
	case hwmon_temp_crit_hyst:
		regh = channel ? LM95245_REG_RW_REMOTE_TCRIT_LIMIT :
				 LM95245_REG_RW_LOCAL_OS_TCRIT_LIMIT;
		ret = regmap_read(regmap, regh, &regvalh);
		if (ret < 0)
			return ret;
		ret = regmap_read(regmap, LM95245_REG_RW_COMMON_HYSTERESIS,
				  &regvall);
		if (ret < 0)
			return ret;
		*val = (regvalh - regvall) * 1000;
		return 0;
	case hwmon_temp_type:
		ret = regmap_read(regmap, LM95245_REG_RW_CONFIG2, &regvalh);
		if (ret < 0)
			return ret;
		*val = (regvalh & CFG2_REMOTE_TT) ? 1 : 2;
		return 0;
	case hwmon_temp_offset:
		ret = regmap_read(regmap, LM95245_REG_RW_REMOTE_OFFL,
				  &regvall);
		if (ret < 0)
			return ret;
		ret = regmap_read(regmap, LM95245_REG_RW_REMOTE_OFFH,
				  &regvalh);
		if (ret < 0)
			return ret;
		*val = temp_from_reg_signed(regvalh, regvall);
		return 0;
	case hwmon_temp_max_alarm:
		ret = regmap_read(regmap, LM95245_REG_R_STATUS1, &regvalh);
		if (ret < 0)
			return ret;
		*val = !!(regvalh & STATUS1_ROS);
		return 0;
	case hwmon_temp_crit_alarm:
		ret = regmap_read(regmap, LM95245_REG_R_STATUS1, &regvalh);
		if (ret < 0)
			return ret;
		*val = !!(regvalh & (channel ? STATUS1_RTCRIT : STATUS1_LOC));
		return 0;
	case hwmon_temp_fault:
		ret = regmap_read(regmap, LM95245_REG_R_STATUS1, &regvalh);
		if (ret < 0)
			return ret;
		*val = !!(regvalh & STATUS1_DIODE_FAULT);
		return 0;
	default:
		return -EOPNOTSUPP;
	}
}

__attribute__((used)) static int lm95245_write_temp(struct device *dev, u32 attr, int channel,
			      long val)
{
	struct lm95245_data *data = dev_get_drvdata(dev);
	struct regmap *regmap = data->regmap;
	unsigned int regval;
	int ret, reg;

	switch (attr) {
	case hwmon_temp_max:
		val = clamp_val(val / 1000, 0, 255);
		ret = regmap_write(regmap, LM95245_REG_RW_REMOTE_OS_LIMIT, val);
		return ret;
	case hwmon_temp_crit:
		reg = channel ? LM95245_REG_RW_REMOTE_TCRIT_LIMIT :
				LM95245_REG_RW_LOCAL_OS_TCRIT_LIMIT;
		val = clamp_val(val / 1000, 0, channel ? 255 : 127);
		ret = regmap_write(regmap, reg, val);
		return ret;
	case hwmon_temp_crit_hyst:
		mutex_lock(&data->update_lock);
		ret = regmap_read(regmap, LM95245_REG_RW_LOCAL_OS_TCRIT_LIMIT,
				  &regval);
		if (ret < 0) {
			mutex_unlock(&data->update_lock);
			return ret;
		}
		/* Clamp to reasonable range to prevent overflow */
		val = clamp_val(val, -1000000, 1000000);
		val = regval - val / 1000;
		val = clamp_val(val, 0, 31);
		ret = regmap_write(regmap, LM95245_REG_RW_COMMON_HYSTERESIS,
				   val);
		mutex_unlock(&data->update_lock);
		return ret;
	case hwmon_temp_offset:
		val = clamp_val(val, -128000, 127875);
		val = val * 256 / 1000;
		mutex_lock(&data->update_lock);
		ret = regmap_write(regmap, LM95245_REG_RW_REMOTE_OFFL,
				   val & 0xe0);
		if (ret < 0) {
			mutex_unlock(&data->update_lock);
			return ret;
		}
		ret = regmap_write(regmap, LM95245_REG_RW_REMOTE_OFFH,
				   (val >> 8) & 0xff);
		mutex_unlock(&data->update_lock);
		return ret;
	case hwmon_temp_type:
		if (val != 1 && val != 2)
			return -EINVAL;
		ret = regmap_update_bits(regmap, LM95245_REG_RW_CONFIG2,
					 CFG2_REMOTE_TT,
					 val == 1 ? CFG2_REMOTE_TT : 0);
		return ret;
	default:
		return -EOPNOTSUPP;
	}
}

__attribute__((used)) static int lm95245_read_chip(struct device *dev, u32 attr, int channel,
			     long *val)
{
	struct lm95245_data *data = dev_get_drvdata(dev);

	switch (attr) {
	case hwmon_chip_update_interval:
		*val = data->interval;
		return 0;
	default:
		return -EOPNOTSUPP;
	}
}

__attribute__((used)) static int lm95245_write_chip(struct device *dev, u32 attr, int channel,
			      long val)
{
	struct lm95245_data *data = dev_get_drvdata(dev);
	int ret;

	switch (attr) {
	case hwmon_chip_update_interval:
		mutex_lock(&data->update_lock);
		ret = lm95245_set_conversion_rate(data, val);
		mutex_unlock(&data->update_lock);
		return ret;
	default:
		return -EOPNOTSUPP;
	}
}

__attribute__((used)) static int lm95245_read(struct device *dev, enum hwmon_sensor_types type,
			u32 attr, int channel, long *val)
{
	switch (type) {
	case hwmon_chip:
		return lm95245_read_chip(dev, attr, channel, val);
	case hwmon_temp:
		return lm95245_read_temp(dev, attr, channel, val);
	default:
		return -EOPNOTSUPP;
	}
}

__attribute__((used)) static int lm95245_write(struct device *dev, enum hwmon_sensor_types type,
			 u32 attr, int channel, long val)
{
	switch (type) {
	case hwmon_chip:
		return lm95245_write_chip(dev, attr, channel, val);
	case hwmon_temp:
		return lm95245_write_temp(dev, attr, channel, val);
	default:
		return -EOPNOTSUPP;
	}
}

__attribute__((used)) static umode_t lm95245_temp_is_visible(const void *data, u32 attr, int channel)
{
	switch (attr) {
	case hwmon_temp_input:
	case hwmon_temp_max_alarm:
	case hwmon_temp_max_hyst:
	case hwmon_temp_crit_alarm:
	case hwmon_temp_fault:
		return S_IRUGO;
	case hwmon_temp_type:
	case hwmon_temp_max:
	case hwmon_temp_crit:
	case hwmon_temp_offset:
		return S_IRUGO | S_IWUSR;
	case hwmon_temp_crit_hyst:
		return (channel == 0) ? S_IRUGO | S_IWUSR : S_IRUGO;
	default:
		return 0;
	}
}

__attribute__((used)) static umode_t lm95245_is_visible(const void *data,
				  enum hwmon_sensor_types type,
				  u32 attr, int channel)
{
	switch (type) {
	case hwmon_chip:
		switch (attr) {
		case hwmon_chip_update_interval:
			return S_IRUGO | S_IWUSR;
		default:
			return 0;
		}
	case hwmon_temp:
		return lm95245_temp_is_visible(data, attr, channel);
	default:
		return 0;
	}
}

__attribute__((used)) static int lm95245_detect(struct i2c_client *new_client,
			  struct i2c_board_info *info)
{
	struct i2c_adapter *adapter = new_client->adapter;
	int address = new_client->addr;
	const char *name;
	int rev, id;

	if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
		return -ENODEV;

	id = i2c_smbus_read_byte_data(new_client, LM95245_REG_R_MAN_ID);
	if (id != MANUFACTURER_ID)
		return -ENODEV;

	rev = i2c_smbus_read_byte_data(new_client, LM95245_REG_R_CHIP_ID);
	switch (rev) {
	case LM95235_REVISION:
		if (address != 0x18 && address != 0x29 && address != 0x4c)
			return -ENODEV;
		name = "lm95235";
		break;
	case LM95245_REVISION:
		name = "lm95245";
		break;
	default:
		return -ENODEV;
	}

	strlcpy(info->type, name, I2C_NAME_SIZE);
	return 0;
}

__attribute__((used)) static int lm95245_init_client(struct lm95245_data *data)
{
	int ret;

	ret = lm95245_read_conversion_rate(data);
	if (ret < 0)
		return ret;

	return regmap_update_bits(data->regmap, LM95245_REG_RW_CONFIG1,
				  CFG_STOP, 0);
}

__attribute__((used)) static bool lm95245_is_writeable_reg(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case LM95245_REG_RW_CONFIG1:
	case LM95245_REG_RW_CONVERS_RATE:
	case LM95245_REG_W_ONE_SHOT:
	case LM95245_REG_RW_CONFIG2:
	case LM95245_REG_RW_REMOTE_OFFH:
	case LM95245_REG_RW_REMOTE_OFFL:
	case LM95245_REG_RW_REMOTE_OS_LIMIT:
	case LM95245_REG_RW_LOCAL_OS_TCRIT_LIMIT:
	case LM95245_REG_RW_REMOTE_TCRIT_LIMIT:
	case LM95245_REG_RW_COMMON_HYSTERESIS:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static bool lm95245_is_volatile_reg(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case LM95245_REG_R_STATUS1:
	case LM95245_REG_R_STATUS2:
	case LM95245_REG_R_LOCAL_TEMPH_S:
	case LM95245_REG_R_LOCAL_TEMPL_S:
	case LM95245_REG_R_REMOTE_TEMPH_S:
	case LM95245_REG_R_REMOTE_TEMPL_S:
	case LM95245_REG_R_REMOTE_TEMPH_U:
	case LM95245_REG_R_REMOTE_TEMPL_U:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static int lm95245_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	struct device *dev = &client->dev;
	struct lm95245_data *data;
	struct device *hwmon_dev;
	int ret;

	data = devm_kzalloc(dev, sizeof(struct lm95245_data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->regmap = devm_regmap_init_i2c(client, &lm95245_regmap_config);
	if (IS_ERR(data->regmap))
		return PTR_ERR(data->regmap);

	mutex_init(&data->update_lock);

	/* Initialize the LM95245 chip */
	ret = lm95245_init_client(data);
	if (ret < 0)
		return ret;

	hwmon_dev = devm_hwmon_device_register_with_info(dev, client->name,
							 data,
							 &lm95245_chip_info,
							 NULL);
	return PTR_ERR_OR_ZERO(hwmon_dev);
}

