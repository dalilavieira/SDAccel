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
typedef  long u32 ;
struct max6621_data {scalar_t__* input_chan2reg; int /*<<< orphan*/  regmap; struct i2c_client* client; } ;
struct i2c_device_id {int dummy; } ;
struct device {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  name; struct device dev; } ;
typedef  long s8 ;
typedef  enum hwmon_sensor_types { ____Placeholder_hwmon_sensor_types } hwmon_sensor_types ;

/* Variables and functions */
 int EIO ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
#define  MAX6621_ALERT_DIS 157 
 int /*<<< orphan*/  MAX6621_CLEAR_ALERT_REG ; 
 long MAX6621_CONFIG0_INIT ; 
#define  MAX6621_CONFIG0_REG 156 
 long MAX6621_CONFIG1_INIT ; 
#define  MAX6621_CONFIG1_REG 155 
#define  MAX6621_CONFIG2_REG 154 
#define  MAX6621_CONFIG3_REG 153 
 int MAX6621_PECI_ERR_MAX ; 
 int MAX6621_PECI_ERR_MIN ; 
#define  MAX6621_POOL_DIS 152 
#define  MAX6621_POOL_UNCOMPLETE 151 
 long MAX6621_REG_TEMP_SHIFT ; 
#define  MAX6621_SD_DIS 150 
#define  MAX6621_TEMP_ALERT_CAUSE_REG 149 
 int MAX6621_TEMP_ALERT_CHAN_SHIFT ; 
 int /*<<< orphan*/  MAX6621_TEMP_INPUT_MAX ; 
 int /*<<< orphan*/  MAX6621_TEMP_INPUT_MIN ; 
 int MAX6621_TEMP_INPUT_REG_NUM ; 
#define  MAX6621_TEMP_MAX_ADDR_REG 148 
#define  MAX6621_TEMP_MAX_REG 147 
#define  MAX6621_TEMP_S0D0_REG 146 
#define  MAX6621_TEMP_S0D1_REG 145 
#define  MAX6621_TEMP_S0_ALERT_REG 144 
#define  MAX6621_TEMP_S1D0_REG 143 
#define  MAX6621_TEMP_S1D1_REG 142 
#define  MAX6621_TEMP_S1_ALERT_REG 141 
#define  MAX6621_TEMP_S2D0_REG 140 
#define  MAX6621_TEMP_S2D1_REG 139 
#define  MAX6621_TEMP_S2_ALERT_REG 138 
#define  MAX6621_TEMP_S3D0_REG 137 
#define  MAX6621_TEMP_S3D1_REG 136 
#define  MAX6621_TEMP_S3_ALERT_REG 135 
#define  MAX6621_TRAN_FAILED 134 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
 long clamp_val (long,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,int) ; 
 struct max6621_data* dev_get_drvdata (struct device*) ; 
 struct device* devm_hwmon_device_register_with_info (struct device*,int /*<<< orphan*/ ,struct max6621_data*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 struct max6621_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
#define  hwmon_temp 133 
#define  hwmon_temp_crit 132 
#define  hwmon_temp_crit_alarm 131 
#define  hwmon_temp_input 130 
#define  hwmon_temp_label 129 
#define  hwmon_temp_offset 128 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct max6621_data*) ; 
 int i2c_smbus_read_word_data (struct i2c_client*,int) ; 
 int i2c_smbus_write_byte (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  max6621_chip_info ; 
 int /*<<< orphan*/  max6621_regmap_config ; 
 void** max6621_temp_alert_chan2reg ; 
 char** max6621_temp_labels ; 
 int* max6621_temp_regs ; 
 int /*<<< orphan*/  regcache_mark_dirty (int /*<<< orphan*/ ) ; 
 int regcache_sync (int /*<<< orphan*/ ) ; 
 int regmap_read (int /*<<< orphan*/ ,int,long*) ; 
 int regmap_write (int /*<<< orphan*/ ,int const,long) ; 

__attribute__((used)) static long max6621_temp_mc2reg(long val)
{
	return (val / 1000L) << MAX6621_REG_TEMP_SHIFT;
}

__attribute__((used)) static umode_t
max6621_is_visible(const void *data, enum hwmon_sensor_types type, u32 attr,
		   int channel)
{
	/* Skip channels which are not physically conncted. */
	if (((struct max6621_data *)data)->input_chan2reg[channel] < 0)
		return 0;

	switch (type) {
	case hwmon_temp:
		switch (attr) {
		case hwmon_temp_input:
		case hwmon_temp_label:
		case hwmon_temp_crit_alarm:
			return 0444;
		case hwmon_temp_offset:
		case hwmon_temp_crit:
			return 0644;
		default:
			break;
		}

	default:
		break;
	}

	return 0;
}

__attribute__((used)) static int max6621_verify_reg_data(struct device *dev, int regval)
{
	if (regval >= MAX6621_PECI_ERR_MIN &&
	    regval <= MAX6621_PECI_ERR_MAX) {
		dev_dbg(dev, "PECI error code - err 0x%04x.\n",
			regval);

		return -EIO;
	}

	switch (regval) {
	case MAX6621_TRAN_FAILED:
		dev_dbg(dev, "PECI transaction failed - err 0x%04x.\n",
			regval);
		return -EIO;
	case MAX6621_POOL_DIS:
		dev_dbg(dev, "Polling disabled - err 0x%04x.\n", regval);
		return -EOPNOTSUPP;
	case MAX6621_POOL_UNCOMPLETE:
		dev_dbg(dev, "First poll not completed on startup - err 0x%04x.\n",
			regval);
		return -EIO;
	case MAX6621_SD_DIS:
		dev_dbg(dev, "Resource is disabled - err 0x%04x.\n", regval);
		return -EOPNOTSUPP;
	case MAX6621_ALERT_DIS:
		dev_dbg(dev, "No alert active - err 0x%04x.\n", regval);
		return -EOPNOTSUPP;
	default:
		return 0;
	}
}

__attribute__((used)) static int
max6621_read(struct device *dev, enum hwmon_sensor_types type, u32 attr,
	     int channel, long *val)
{
	struct max6621_data *data = dev_get_drvdata(dev);
	u32 regval;
	int reg;
	s8 temp;
	int ret;

	switch (type) {
	case hwmon_temp:
		switch (attr) {
		case hwmon_temp_input:
			reg = data->input_chan2reg[channel];
			ret = regmap_read(data->regmap, reg, &regval);
			if (ret)
				return ret;

			ret = max6621_verify_reg_data(dev, regval);
			if (ret)
				return ret;

			/*
			 * Bit MAX6621_REG_TEMP_SHIFT represents 1 degree step.
			 * The temperature is given in two's complement and 8
			 * bits is used for the register conversion.
			 */
			temp = (regval >> MAX6621_REG_TEMP_SHIFT);
			*val = temp * 1000L;

			break;
		case hwmon_temp_offset:
			ret = regmap_read(data->regmap, MAX6621_CONFIG2_REG,
					  &regval);
			if (ret)
				return ret;

			ret = max6621_verify_reg_data(dev, regval);
			if (ret)
				return ret;

			*val = (regval >> MAX6621_REG_TEMP_SHIFT) *
			       1000L;

			break;
		case hwmon_temp_crit:
			channel -= MAX6621_TEMP_ALERT_CHAN_SHIFT;
			reg = max6621_temp_alert_chan2reg[channel];
			ret = regmap_read(data->regmap, reg, &regval);
			if (ret)
				return ret;

			ret = max6621_verify_reg_data(dev, regval);
			if (ret)
				return ret;

			*val = regval * 1000L;

			break;
		case hwmon_temp_crit_alarm:
			/*
			 * Set val to zero to recover the case, when reading
			 * MAX6621_TEMP_ALERT_CAUSE_REG results in for example
			 * MAX6621_ALERT_DIS. Reading will return with error,
			 * but in such case alarm should be returned as 0.
			 */
			*val = 0;
			ret = regmap_read(data->regmap,
					  MAX6621_TEMP_ALERT_CAUSE_REG,
					  &regval);
			if (ret)
				return ret;

			ret = max6621_verify_reg_data(dev, regval);
			if (ret) {
				/* Do not report error if alert is disabled. */
				if (regval == MAX6621_ALERT_DIS)
					return 0;
				else
					return ret;
			}

			/*
			 * Clear the alert automatically, using send-byte
			 * smbus protocol for clearing alert.
			 */
			if (regval) {
				ret = i2c_smbus_write_byte(data->client,
						MAX6621_CLEAR_ALERT_REG);
				if (ret)
					return ret;
			}

			*val = !!regval;

			break;
		default:
			return -EOPNOTSUPP;
		}
		break;

	default:
		return -EOPNOTSUPP;
	}

	return 0;
}

__attribute__((used)) static int
max6621_write(struct device *dev, enum hwmon_sensor_types type, u32 attr,
	      int channel, long val)
{
	struct max6621_data *data = dev_get_drvdata(dev);
	u32 reg;

	switch (type) {
	case hwmon_temp:
		switch (attr) {
		case hwmon_temp_offset:
			/* Clamp to allowed range to prevent overflow. */
			val = clamp_val(val, MAX6621_TEMP_INPUT_MIN,
					MAX6621_TEMP_INPUT_MAX);
			val = max6621_temp_mc2reg(val);

			return regmap_write(data->regmap,
					    MAX6621_CONFIG2_REG, val);
		case hwmon_temp_crit:
			channel -= MAX6621_TEMP_ALERT_CHAN_SHIFT;
			reg = max6621_temp_alert_chan2reg[channel];
			/* Clamp to allowed range to prevent overflow. */
			val = clamp_val(val, MAX6621_TEMP_INPUT_MIN,
					MAX6621_TEMP_INPUT_MAX);
			val = val / 1000L;

			return regmap_write(data->regmap, reg, val);
		default:
			return -EOPNOTSUPP;
		}
		break;

	default:
		return -EOPNOTSUPP;
	}

	return -EOPNOTSUPP;
}

__attribute__((used)) static int
max6621_read_string(struct device *dev, enum hwmon_sensor_types type, u32 attr,
		    int channel, const char **str)
{
	switch (type) {
	case hwmon_temp:
		switch (attr) {
		case hwmon_temp_label:
			*str = max6621_temp_labels[channel];
			return 0;
		default:
			return -EOPNOTSUPP;
		}
		break;
	default:
		return -EOPNOTSUPP;
	}

	return -EOPNOTSUPP;
}

__attribute__((used)) static bool max6621_writeable_reg(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case MAX6621_CONFIG0_REG:
	case MAX6621_CONFIG1_REG:
	case MAX6621_CONFIG2_REG:
	case MAX6621_CONFIG3_REG:
	case MAX6621_TEMP_S0_ALERT_REG:
	case MAX6621_TEMP_S1_ALERT_REG:
	case MAX6621_TEMP_S2_ALERT_REG:
	case MAX6621_TEMP_S3_ALERT_REG:
	case MAX6621_TEMP_ALERT_CAUSE_REG:
		return true;
	}
	return false;
}

__attribute__((used)) static bool max6621_readable_reg(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case MAX6621_TEMP_S0D0_REG:
	case MAX6621_TEMP_S0D1_REG:
	case MAX6621_TEMP_S1D0_REG:
	case MAX6621_TEMP_S1D1_REG:
	case MAX6621_TEMP_S2D0_REG:
	case MAX6621_TEMP_S2D1_REG:
	case MAX6621_TEMP_S3D0_REG:
	case MAX6621_TEMP_S3D1_REG:
	case MAX6621_TEMP_MAX_REG:
	case MAX6621_TEMP_MAX_ADDR_REG:
	case MAX6621_CONFIG0_REG:
	case MAX6621_CONFIG1_REG:
	case MAX6621_CONFIG2_REG:
	case MAX6621_CONFIG3_REG:
	case MAX6621_TEMP_S0_ALERT_REG:
	case MAX6621_TEMP_S1_ALERT_REG:
	case MAX6621_TEMP_S2_ALERT_REG:
	case MAX6621_TEMP_S3_ALERT_REG:
		return true;
	}
	return false;
}

__attribute__((used)) static bool max6621_volatile_reg(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case MAX6621_TEMP_S0D0_REG:
	case MAX6621_TEMP_S0D1_REG:
	case MAX6621_TEMP_S1D0_REG:
	case MAX6621_TEMP_S1D1_REG:
	case MAX6621_TEMP_S2D0_REG:
	case MAX6621_TEMP_S2D1_REG:
	case MAX6621_TEMP_S3D0_REG:
	case MAX6621_TEMP_S3D1_REG:
	case MAX6621_TEMP_MAX_REG:
	case MAX6621_TEMP_S0_ALERT_REG:
	case MAX6621_TEMP_S1_ALERT_REG:
	case MAX6621_TEMP_S2_ALERT_REG:
	case MAX6621_TEMP_S3_ALERT_REG:
	case MAX6621_TEMP_ALERT_CAUSE_REG:
		return true;
	}
	return false;
}

__attribute__((used)) static int max6621_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	struct device *dev = &client->dev;
	struct max6621_data *data;
	struct device *hwmon_dev;
	int i;
	int ret;

	data = devm_kzalloc(dev, sizeof(*data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->regmap = devm_regmap_init_i2c(client, &max6621_regmap_config);
	if (IS_ERR(data->regmap))
		return PTR_ERR(data->regmap);

	i2c_set_clientdata(client, data);
	data->client = client;

	/* Set CONFIG0 register masking temperature alerts and PEC. */
	ret = regmap_write(data->regmap, MAX6621_CONFIG0_REG,
			   MAX6621_CONFIG0_INIT);
	if (ret)
		return ret;

	/* Set CONFIG1 register for PEC access retry number. */
	ret = regmap_write(data->regmap, MAX6621_CONFIG1_REG,
			   MAX6621_CONFIG1_INIT);
	if (ret)
		return ret;

	/* Sync registers with hardware. */
	regcache_mark_dirty(data->regmap);
	ret = regcache_sync(data->regmap);
	if (ret)
		return ret;

	/* Verify which temperature input registers are enabled. */
	for (i = 0; i < MAX6621_TEMP_INPUT_REG_NUM; i++) {
		ret = i2c_smbus_read_word_data(client, max6621_temp_regs[i]);
		if (ret < 0)
			return ret;
		ret = max6621_verify_reg_data(dev, ret);
		if (ret) {
			data->input_chan2reg[i] = -1;
			continue;
		}

		data->input_chan2reg[i] = max6621_temp_regs[i];
	}

	hwmon_dev = devm_hwmon_device_register_with_info(dev, client->name,
							 data,
							 &max6621_chip_info,
							 NULL);

	return PTR_ERR_OR_ZERO(hwmon_dev);
}

