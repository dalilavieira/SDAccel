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
typedef  unsigned int u8 ;
typedef  int u32 ;
struct nct7904_data {unsigned int bank_sel; int fanin_mask; int vsen_mask; int tcpu_mask; unsigned int* fan_mode; int /*<<< orphan*/  bank_lock; struct i2c_client* client; } ;
struct i2c_device_id {int dummy; } ;
struct device {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  name; struct device dev; struct i2c_adapter* adapter; } ;
struct i2c_board_info {int /*<<< orphan*/  type; } ;
struct i2c_adapter {int dummy; } ;
typedef  enum hwmon_sensor_types { ____Placeholder_hwmon_sensor_types } hwmon_sensor_types ;

/* Variables and functions */
 unsigned int BANK_0 ; 
 unsigned int BANK_3 ; 
 unsigned int BANK_SEL_REG ; 
 int BIT (int) ; 
 unsigned int CHIP_ID_REG ; 
 unsigned int DEVICE_ID_REG ; 
 unsigned int DTS_T_CTRL0_REG ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 int FANCTL1_FMR_REG ; 
 int /*<<< orphan*/  FANCTL1_OUT_REG ; 
 int FANCTL_MAX ; 
 int /*<<< orphan*/  FANIN1_HV_REG ; 
 unsigned int FANIN_CTRL0_REG ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int I2C_FUNC_SMBUS_READ_BYTE ; 
 int I2C_FUNC_SMBUS_WRITE_BYTE_DATA ; 
 int /*<<< orphan*/  I2C_NAME_SIZE ; 
 unsigned int LTD_HV_REG ; 
 int NCT7904_ID ; 
 int NUVOTON_ID ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
 int S_IRUGO ; 
 int S_IWUSR ; 
 int /*<<< orphan*/  T_CPU1_HV_REG ; 
 unsigned int VENDOR_ID_REG ; 
 int /*<<< orphan*/  VSEN1_HV_REG ; 
 unsigned int VT_ADC_CTRL0_REG ; 
 unsigned int VT_ADC_CTRL2_REG ; 
 struct nct7904_data* dev_get_drvdata (struct device*) ; 
 struct device* devm_hwmon_device_register_with_info (struct device*,int /*<<< orphan*/ ,struct nct7904_data*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 struct nct7904_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
#define  hwmon_fan 136 
#define  hwmon_fan_input 135 
#define  hwmon_in 134 
#define  hwmon_in_input 133 
#define  hwmon_pwm 132 
#define  hwmon_pwm_enable 131 
#define  hwmon_pwm_input 130 
#define  hwmon_temp 129 
#define  hwmon_temp_input 128 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,unsigned int) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int* nct7904_chan_to_index ; 
 int /*<<< orphan*/  nct7904_chip_info ; 
 int sign_extend32 (int,int) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int nct7904_bank_lock(struct nct7904_data *data, unsigned int bank)
{
	int ret;

	mutex_lock(&data->bank_lock);
	if (data->bank_sel == bank)
		return 0;
	ret = i2c_smbus_write_byte_data(data->client, BANK_SEL_REG, bank);
	if (ret == 0)
		data->bank_sel = bank;
	else
		data->bank_sel = -1;
	return ret;
}

__attribute__((used)) static inline void nct7904_bank_release(struct nct7904_data *data)
{
	mutex_unlock(&data->bank_lock);
}

__attribute__((used)) static int nct7904_read_reg(struct nct7904_data *data,
			    unsigned int bank, unsigned int reg)
{
	struct i2c_client *client = data->client;
	int ret;

	ret = nct7904_bank_lock(data, bank);
	if (ret == 0)
		ret = i2c_smbus_read_byte_data(client, reg);

	nct7904_bank_release(data);
	return ret;
}

__attribute__((used)) static int nct7904_read_reg16(struct nct7904_data *data,
			      unsigned int bank, unsigned int reg)
{
	struct i2c_client *client = data->client;
	int ret, hi;

	ret = nct7904_bank_lock(data, bank);
	if (ret == 0) {
		ret = i2c_smbus_read_byte_data(client, reg);
		if (ret >= 0) {
			hi = ret;
			ret = i2c_smbus_read_byte_data(client, reg + 1);
			if (ret >= 0)
				ret |= hi << 8;
		}
	}

	nct7904_bank_release(data);
	return ret;
}

__attribute__((used)) static int nct7904_write_reg(struct nct7904_data *data,
			     unsigned int bank, unsigned int reg, u8 val)
{
	struct i2c_client *client = data->client;
	int ret;

	ret = nct7904_bank_lock(data, bank);
	if (ret == 0)
		ret = i2c_smbus_write_byte_data(client, reg, val);

	nct7904_bank_release(data);
	return ret;
}

__attribute__((used)) static int nct7904_read_fan(struct device *dev, u32 attr, int channel,
			    long *val)
{
	struct nct7904_data *data = dev_get_drvdata(dev);
	unsigned int cnt, rpm;
	int ret;

	switch (attr) {
	case hwmon_fan_input:
		ret = nct7904_read_reg16(data, BANK_0,
					 FANIN1_HV_REG + channel * 2);
		if (ret < 0)
			return ret;
		cnt = ((ret & 0xff00) >> 3) | (ret & 0x1f);
		if (cnt == 0x1fff)
			rpm = 0;
		else
			rpm = 1350000 / cnt;
		*val = rpm;
		return 0;
	default:
		return -EOPNOTSUPP;
	}
}

__attribute__((used)) static umode_t nct7904_fan_is_visible(const void *_data, u32 attr, int channel)
{
	const struct nct7904_data *data = _data;

	if (attr == hwmon_fan_input && data->fanin_mask & (1 << channel))
		return S_IRUGO;
	return 0;
}

__attribute__((used)) static int nct7904_read_in(struct device *dev, u32 attr, int channel,
			   long *val)
{
	struct nct7904_data *data = dev_get_drvdata(dev);
	int ret, volt, index;

	index = nct7904_chan_to_index[channel];

	switch (attr) {
	case hwmon_in_input:
		ret = nct7904_read_reg16(data, BANK_0,
					 VSEN1_HV_REG + index * 2);
		if (ret < 0)
			return ret;
		volt = ((ret & 0xff00) >> 5) | (ret & 0x7);
		if (index < 14)
			volt *= 2; /* 0.002V scale */
		else
			volt *= 6; /* 0.006V scale */
		*val = volt;
		return 0;
	default:
		return -EOPNOTSUPP;
	}
}

__attribute__((used)) static umode_t nct7904_in_is_visible(const void *_data, u32 attr, int channel)
{
	const struct nct7904_data *data = _data;
	int index = nct7904_chan_to_index[channel];

	if (channel > 0 && attr == hwmon_in_input &&
	    (data->vsen_mask & BIT(index)))
		return S_IRUGO;

	return 0;
}

__attribute__((used)) static int nct7904_read_temp(struct device *dev, u32 attr, int channel,
			     long *val)
{
	struct nct7904_data *data = dev_get_drvdata(dev);
	int ret, temp;

	switch (attr) {
	case hwmon_temp_input:
		if (channel == 0)
			ret = nct7904_read_reg16(data, BANK_0, LTD_HV_REG);
		else
			ret = nct7904_read_reg16(data, BANK_0,
					T_CPU1_HV_REG + (channel - 1) * 2);
		if (ret < 0)
			return ret;
		temp = ((ret & 0xff00) >> 5) | (ret & 0x7);
		*val = sign_extend32(temp, 10) * 125;
		return 0;
	default:
		return -EOPNOTSUPP;
	}
}

__attribute__((used)) static umode_t nct7904_temp_is_visible(const void *_data, u32 attr, int channel)
{
	const struct nct7904_data *data = _data;

	if (attr == hwmon_temp_input) {
		if (channel == 0) {
			if (data->vsen_mask & BIT(17))
				return S_IRUGO;
		} else {
			if (data->tcpu_mask & BIT(channel - 1))
				return S_IRUGO;
		}
	}

	return 0;
}

__attribute__((used)) static int nct7904_read_pwm(struct device *dev, u32 attr, int channel,
			    long *val)
{
	struct nct7904_data *data = dev_get_drvdata(dev);
	int ret;

	switch (attr) {
	case hwmon_pwm_input:
		ret = nct7904_read_reg(data, BANK_3, FANCTL1_OUT_REG + channel);
		if (ret < 0)
			return ret;
		*val = ret;
		return 0;
	case hwmon_pwm_enable:
		ret = nct7904_read_reg(data, BANK_3, FANCTL1_FMR_REG + channel);
		if (ret < 0)
			return ret;

		*val = ret ? 2 : 1;
		return 0;
	default:
		return -EOPNOTSUPP;
	}
}

__attribute__((used)) static int nct7904_write_pwm(struct device *dev, u32 attr, int channel,
			     long val)
{
	struct nct7904_data *data = dev_get_drvdata(dev);
	int ret;

	switch (attr) {
	case hwmon_pwm_input:
		if (val < 0 || val > 255)
			return -EINVAL;
		ret = nct7904_write_reg(data, BANK_3, FANCTL1_OUT_REG + channel,
					val);
		return ret;
	case hwmon_pwm_enable:
		if (val < 1 || val > 2 ||
		    (val == 2 && !data->fan_mode[channel]))
			return -EINVAL;
		ret = nct7904_write_reg(data, BANK_3, FANCTL1_FMR_REG + channel,
					val == 2 ? data->fan_mode[channel] : 0);
		return ret;
	default:
		return -EOPNOTSUPP;
	}
}

__attribute__((used)) static umode_t nct7904_pwm_is_visible(const void *_data, u32 attr, int channel)
{
	switch (attr) {
	case hwmon_pwm_input:
	case hwmon_pwm_enable:
		return S_IRUGO | S_IWUSR;
	default:
		return 0;
	}
}

__attribute__((used)) static int nct7904_read(struct device *dev, enum hwmon_sensor_types type,
			u32 attr, int channel, long *val)
{
	switch (type) {
	case hwmon_in:
		return nct7904_read_in(dev, attr, channel, val);
	case hwmon_fan:
		return nct7904_read_fan(dev, attr, channel, val);
	case hwmon_pwm:
		return nct7904_read_pwm(dev, attr, channel, val);
	case hwmon_temp:
		return nct7904_read_temp(dev, attr, channel, val);
	default:
		return -EOPNOTSUPP;
	}
}

__attribute__((used)) static int nct7904_write(struct device *dev, enum hwmon_sensor_types type,
			 u32 attr, int channel, long val)
{
	switch (type) {
	case hwmon_pwm:
		return nct7904_write_pwm(dev, attr, channel, val);
	default:
		return -EOPNOTSUPP;
	}
}

__attribute__((used)) static umode_t nct7904_is_visible(const void *data,
				  enum hwmon_sensor_types type,
				  u32 attr, int channel)
{
	switch (type) {
	case hwmon_in:
		return nct7904_in_is_visible(data, attr, channel);
	case hwmon_fan:
		return nct7904_fan_is_visible(data, attr, channel);
	case hwmon_pwm:
		return nct7904_pwm_is_visible(data, attr, channel);
	case hwmon_temp:
		return nct7904_temp_is_visible(data, attr, channel);
	default:
		return 0;
	}
}

__attribute__((used)) static int nct7904_detect(struct i2c_client *client,
			  struct i2c_board_info *info)
{
	struct i2c_adapter *adapter = client->adapter;

	if (!i2c_check_functionality(adapter,
				     I2C_FUNC_SMBUS_READ_BYTE |
				     I2C_FUNC_SMBUS_WRITE_BYTE_DATA))
		return -ENODEV;

	/* Determine the chip type. */
	if (i2c_smbus_read_byte_data(client, VENDOR_ID_REG) != NUVOTON_ID ||
	    i2c_smbus_read_byte_data(client, CHIP_ID_REG) != NCT7904_ID ||
	    (i2c_smbus_read_byte_data(client, DEVICE_ID_REG) & 0xf0) != 0x50 ||
	    (i2c_smbus_read_byte_data(client, BANK_SEL_REG) & 0xf8) != 0x00)
		return -ENODEV;

	strlcpy(info->type, "nct7904", I2C_NAME_SIZE);

	return 0;
}

__attribute__((used)) static int nct7904_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	struct nct7904_data *data;
	struct device *hwmon_dev;
	struct device *dev = &client->dev;
	int ret, i;
	u32 mask;

	data = devm_kzalloc(dev, sizeof(struct nct7904_data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->client = client;
	mutex_init(&data->bank_lock);
	data->bank_sel = -1;

	/* Setup sensor groups. */
	/* FANIN attributes */
	ret = nct7904_read_reg16(data, BANK_0, FANIN_CTRL0_REG);
	if (ret < 0)
		return ret;
	data->fanin_mask = (ret >> 8) | ((ret & 0xff) << 8);

	/*
	 * VSEN attributes
	 *
	 * Note: voltage sensors overlap with external temperature
	 * sensors. So, if we ever decide to support the latter
	 * we will have to adjust 'vsen_mask' accordingly.
	 */
	mask = 0;
	ret = nct7904_read_reg16(data, BANK_0, VT_ADC_CTRL0_REG);
	if (ret >= 0)
		mask = (ret >> 8) | ((ret & 0xff) << 8);
	ret = nct7904_read_reg(data, BANK_0, VT_ADC_CTRL2_REG);
	if (ret >= 0)
		mask |= (ret << 16);
	data->vsen_mask = mask;

	/* CPU_TEMP attributes */
	ret = nct7904_read_reg16(data, BANK_0, DTS_T_CTRL0_REG);
	if (ret < 0)
		return ret;
	data->tcpu_mask = ((ret >> 8) & 0xf) | ((ret & 0xf) << 4);

	for (i = 0; i < FANCTL_MAX; i++) {
		ret = nct7904_read_reg(data, BANK_3, FANCTL1_FMR_REG + i);
		if (ret < 0)
			return ret;
		data->fan_mode[i] = ret;
	}

	hwmon_dev =
		devm_hwmon_device_register_with_info(dev, client->name, data,
						     &nct7904_chip_info, NULL);
	return PTR_ERR_OR_ZERO(hwmon_dev);
}

