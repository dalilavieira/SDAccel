#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u16 ;
struct sensor_device_attribute_2 {int index; int nr; } ;
struct sensor_device_attribute {int index; } ;
struct block1_t {int host_status_2; int host_status_4; int host_status_3; int fan_status; int p1_prochot_status; int p2_prochot_status; int host_status_1; } ;
struct TYPE_9__ {int* base; int* offset; } ;
struct lm93_data {int* boost_hyst; int* boost; int valid; void (* update ) (struct lm93_data*,struct i2c_client*) ;int config; int* vid; int* prochot_max; int* vccp_limits; int gpi; int prochot_override; int prochot_interval; int* auto_pwm_min_hyst; int pwm_ramp_ctl; int sfc1; int sfc2; int sf_tach_to_pwm; int* block3; int* block2; int* block5; int* block8; int** block9; long* pwm_override; int /*<<< orphan*/  update_lock; struct i2c_client* client; struct block1_t block1; TYPE_1__* block4; TYPE_4__ block10; TYPE_3__* temp_lim; TYPE_2__* block7; scalar_t__ last_updated; } ;
struct i2c_device_id {int dummy; } ;
struct device {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  name; struct i2c_adapter* adapter; struct device dev; int /*<<< orphan*/  addr; } ;
struct i2c_board_info {int /*<<< orphan*/  type; } ;
struct i2c_adapter {int /*<<< orphan*/  dev; } ;
struct device_attribute {int dummy; } ;
typedef  int ssize_t ;
typedef  int s8 ;
typedef  enum pwm_freq { ____Placeholder_pwm_freq } pwm_freq ;
struct TYPE_10__ {int len; int /*<<< orphan*/  cmd; } ;
struct TYPE_8__ {int min; int max; } ;
struct TYPE_7__ {int min; int max; } ;
struct TYPE_6__ {int cur; int avg; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HZ ; 
 int /*<<< orphan*/  I2C_NAME_SIZE ; 
 long LM93_IN_MAX_FROM_REG (int,long) ; 
 long LM93_IN_MIN_FROM_REG (int,long) ; 
#define  LM93_MFR_ID 132 
#define  LM93_MFR_ID_PROTOTYPE 131 
 size_t LM93_PWM_CTL1 ; 
 size_t LM93_PWM_CTL2 ; 
 size_t LM93_PWM_CTL3 ; 
 size_t LM93_PWM_CTL4 ; 
 int LM93_PWM_MAP_HI_FREQ ; 
 int LM93_PWM_MAP_LO_FREQ ; 
 int LM93_RAMP_MAX ; 
 int LM93_RAMP_MIN ; 
 int LM93_REG_BOOST (int) ; 
 int LM93_REG_BOOST_HYST (int) ; 
 int LM93_REG_BOOST_HYST_12 ; 
 int LM93_REG_BOOST_HYST_34 ; 
 int LM93_REG_CONFIG ; 
 int LM93_REG_FAN (int) ; 
 int LM93_REG_FAN_MIN (int) ; 
 int LM93_REG_GPI ; 
 int LM93_REG_GPI_VID_CTL ; 
 int LM93_REG_HOST_ERROR_1 ; 
 int LM93_REG_IN (int) ; 
 int LM93_REG_IN_MAX (int) ; 
 int LM93_REG_IN_MIN (int) ; 
 int LM93_REG_MFR_ID ; 
 int LM93_REG_MISC_ERR_MASK ; 
 int LM93_REG_PROCHOT_AVG (int) ; 
 int LM93_REG_PROCHOT_CUR (int) ; 
 int LM93_REG_PROCHOT_INTERVAL ; 
 int LM93_REG_PROCHOT_MAX (int) ; 
 int LM93_REG_PROCHOT_OVERRIDE ; 
 int LM93_REG_PWM_CTL (int,size_t) ; 
 int LM93_REG_PWM_MIN_HYST (int) ; 
 int LM93_REG_PWM_MIN_HYST_12 ; 
 int LM93_REG_PWM_MIN_HYST_34 ; 
 int LM93_REG_PWM_RAMP_CTL ; 
 int LM93_REG_SFC1 ; 
 int LM93_REG_SFC2 ; 
 int LM93_REG_SF_TACH_TO_PWM ; 
 int LM93_REG_SLEEP_CONTROL ; 
 int LM93_REG_STATUS_CONTROL ; 
 int LM93_REG_TEMP (int) ; 
 int LM93_REG_TEMP_BASE (int) ; 
 int LM93_REG_TEMP_MAX (int) ; 
 int LM93_REG_TEMP_MIN (int) ; 
 int LM93_REG_TEMP_OFFSET (int) ; 
 int LM93_REG_VCCP_LIMIT_OFF (int) ; 
 int LM93_REG_VER ; 
 int LM93_REG_VID (int) ; 
 int LM93_SMBUS_FUNC_FULL ; 
 int LM93_SMBUS_FUNC_MIN ; 
 int LM93_TEMP_MAX ; 
 int LM93_TEMP_MIN ; 
 int LM93_TEMP_OFFSET_MAX0 ; 
 int LM93_TEMP_OFFSET_MAX1 ; 
 int LM93_TEMP_OFFSET_MIN ; 
#define  LM94_MFR_ID 130 
#define  LM94_MFR_ID_2 129 
#define  LM94_MFR_ID_PROTOTYPE 128 
 int MAX_RETRIES ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
 int clamp_val (unsigned long,long const,long const) ; 
 int cpu_to_le16 (int) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 struct lm93_data* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*,...) ; 
 struct device* devm_hwmon_device_register_with_groups (struct device*,int /*<<< orphan*/ ,struct lm93_data*,int /*<<< orphan*/ ) ; 
 struct lm93_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  disable_block ; 
 int /*<<< orphan*/  i2c_adapter_id (struct i2c_adapter*) ; 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int) ; 
 int i2c_get_functionality (struct i2c_adapter*) ; 
 int i2c_smbus_read_block_data (struct i2c_client*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int) ; 
 int i2c_smbus_read_word_data (struct i2c_client*,int) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int,int) ; 
 int i2c_smbus_write_word_data (struct i2c_client*,int,int) ; 
 scalar_t__ init ; 
 scalar_t__ jiffies ; 
 int kstrtol (char const*,int,long*) ; 
 int kstrtoul (char const*,int,unsigned long*) ; 
 int le16_to_cpu (int) ; 
 int /*<<< orphan*/  lm93_block_buffer ; 
 TYPE_5__* lm93_block_read_cmds ; 
 int /*<<< orphan*/  lm93_groups ; 
 int* lm93_interval_map ; 
 int* lm93_pwm_freq_map ; 
 int** lm93_pwm_map ; 
 int* lm93_spinup_time_map ; 
 long const* lm93_vin_reg_max ; 
 long const* lm93_vin_reg_min ; 
 int* lm93_vin_val_max ; 
 int* lm93_vin_val_min ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  memcpy (int*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int* prochot_override_mask ; 
 int sprintf (char*,char*,int) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ ) ; 
 void stub1 (struct lm93_data*,struct i2c_client*) ; 
 scalar_t__ time_after (scalar_t__,scalar_t__) ; 
 struct sensor_device_attribute* to_sensor_dev_attr (struct device_attribute*) ; 
 struct sensor_device_attribute_2* to_sensor_dev_attr_2 (struct device_attribute*) ; 
 scalar_t__* vccp_limit_type ; 
 scalar_t__ vid_agtl ; 
 int vid_from_reg (int,int) ; 

__attribute__((used)) static int LM93_VID_FROM_REG(u8 reg)
{
	return vid_from_reg((reg & 0x3f), 100);
}

__attribute__((used)) static unsigned LM93_IN_FROM_REG(int nr, u8 reg)
{
	const long uv_max = lm93_vin_val_max[nr] * 1000;
	const long uv_min = lm93_vin_val_min[nr] * 1000;

	const long slope = (uv_max - uv_min) /
		(lm93_vin_reg_max[nr] - lm93_vin_reg_min[nr]);
	const long intercept = uv_min - slope * lm93_vin_reg_min[nr];

	return (slope * reg + intercept + 500) / 1000;
}

__attribute__((used)) static u8 LM93_IN_TO_REG(int nr, unsigned val)
{
	/* range limit */
	const long mv = clamp_val(val,
				  lm93_vin_val_min[nr], lm93_vin_val_max[nr]);

	/* try not to lose too much precision here */
	const long uv = mv * 1000;
	const long uv_max = lm93_vin_val_max[nr] * 1000;
	const long uv_min = lm93_vin_val_min[nr] * 1000;

	/* convert */
	const long slope = (uv_max - uv_min) /
		(lm93_vin_reg_max[nr] - lm93_vin_reg_min[nr]);
	const long intercept = uv_min - slope * lm93_vin_reg_min[nr];

	u8 result = ((uv - intercept + (slope/2)) / slope);
	result = clamp_val(result,
			   lm93_vin_reg_min[nr], lm93_vin_reg_max[nr]);
	return result;
}

__attribute__((used)) static unsigned LM93_IN_REL_FROM_REG(u8 reg, int upper, int vid)
{
	const long uv_offset = upper ? (((reg >> 4 & 0x0f) + 1) * 12500) :
				(((reg >> 0 & 0x0f) + 1) * -25000);
	const long uv_vid = vid * 1000;
	return (uv_vid + uv_offset + 5000) / 10000;
}

__attribute__((used)) static u8 LM93_IN_REL_TO_REG(unsigned val, int upper, int vid)
{
	long uv_offset = vid * 1000 - val * 10000;
	if (upper) {
		uv_offset = clamp_val(uv_offset, 12500, 200000);
		return (u8)((uv_offset /  12500 - 1) << 4);
	} else {
		uv_offset = clamp_val(uv_offset, -400000, -25000);
		return (u8)((uv_offset / -25000 - 1) << 0);
	}
}

__attribute__((used)) static int LM93_TEMP_FROM_REG(u8 reg)
{
	return (s8)reg * 1000;
}

__attribute__((used)) static u8 LM93_TEMP_TO_REG(long temp)
{
	int ntemp = clamp_val(temp, LM93_TEMP_MIN, LM93_TEMP_MAX);
	ntemp += (ntemp < 0 ? -500 : 500);
	return (u8)(ntemp / 1000);
}

__attribute__((used)) static int LM93_TEMP_OFFSET_MODE_FROM_REG(u8 sfc2, int nr)
{
	/* mode: 0 => 1C/bit, nonzero => 0.5C/bit */
	return sfc2 & (nr < 2 ? 0x10 : 0x20);
}

__attribute__((used)) static int LM93_TEMP_OFFSET_FROM_REG(u8 reg, int mode)
{
	return (reg & 0x0f) * (mode ? 5 : 10);
}

__attribute__((used)) static u8 LM93_TEMP_OFFSET_TO_REG(int off, int mode)
{
	int factor = mode ? 5 : 10;

	off = clamp_val(off, LM93_TEMP_OFFSET_MIN,
		mode ? LM93_TEMP_OFFSET_MAX1 : LM93_TEMP_OFFSET_MAX0);
	return (u8)((off + factor/2) / factor);
}

__attribute__((used)) static int LM93_TEMP_AUTO_OFFSET_FROM_REG(u8 reg, int nr, int mode)
{
	/* temp1-temp2 (nr=0,1) use lower nibble */
	if (nr < 2)
		return LM93_TEMP_OFFSET_FROM_REG(reg & 0x0f, mode);

	/* temp3-temp4 (nr=2,3) use upper nibble */
	else
		return LM93_TEMP_OFFSET_FROM_REG(reg >> 4 & 0x0f, mode);
}

__attribute__((used)) static u8 LM93_TEMP_AUTO_OFFSET_TO_REG(u8 old, int off, int nr, int mode)
{
	u8 new = LM93_TEMP_OFFSET_TO_REG(off, mode);

	/* temp1-temp2 (nr=0,1) use lower nibble */
	if (nr < 2)
		return (old & 0xf0) | (new & 0x0f);

	/* temp3-temp4 (nr=2,3) use upper nibble */
	else
		return (new << 4 & 0xf0) | (old & 0x0f);
}

__attribute__((used)) static int LM93_AUTO_BOOST_HYST_FROM_REGS(struct lm93_data *data, int nr,
		int mode)
{
	u8 reg;

	switch (nr) {
	case 0:
		reg = data->boost_hyst[0] & 0x0f;
		break;
	case 1:
		reg = data->boost_hyst[0] >> 4 & 0x0f;
		break;
	case 2:
		reg = data->boost_hyst[1] & 0x0f;
		break;
	case 3:
	default:
		reg = data->boost_hyst[1] >> 4 & 0x0f;
		break;
	}

	return LM93_TEMP_FROM_REG(data->boost[nr]) -
			LM93_TEMP_OFFSET_FROM_REG(reg, mode);
}

__attribute__((used)) static u8 LM93_AUTO_BOOST_HYST_TO_REG(struct lm93_data *data, long hyst,
		int nr, int mode)
{
	u8 reg = LM93_TEMP_OFFSET_TO_REG(
			(LM93_TEMP_FROM_REG(data->boost[nr]) - hyst), mode);

	switch (nr) {
	case 0:
		reg = (data->boost_hyst[0] & 0xf0) | (reg & 0x0f);
		break;
	case 1:
		reg = (reg << 4 & 0xf0) | (data->boost_hyst[0] & 0x0f);
		break;
	case 2:
		reg = (data->boost_hyst[1] & 0xf0) | (reg & 0x0f);
		break;
	case 3:
	default:
		reg = (reg << 4 & 0xf0) | (data->boost_hyst[1] & 0x0f);
		break;
	}

	return reg;
}

__attribute__((used)) static int LM93_PWM_FROM_REG(u8 reg, enum pwm_freq freq)
{
	return lm93_pwm_map[freq][reg & 0x0f];
}

__attribute__((used)) static u8 LM93_PWM_TO_REG(int pwm, enum pwm_freq freq)
{
	int i;
	for (i = 0; i < 13; i++)
		if (pwm <= lm93_pwm_map[freq][i])
			break;

	/* can fall through with i==13 */
	return (u8)i;
}

__attribute__((used)) static int LM93_FAN_FROM_REG(u16 regs)
{
	const u16 count = le16_to_cpu(regs) >> 2;
	return count == 0 ? -1 : count == 0x3fff ? 0 : 1350000 / count;
}

__attribute__((used)) static u16 LM93_FAN_TO_REG(long rpm)
{
	u16 count, regs;

	if (rpm == 0) {
		count = 0x3fff;
	} else {
		rpm = clamp_val(rpm, 1, 1000000);
		count = clamp_val((1350000 + rpm) / rpm, 1, 0x3ffe);
	}

	regs = count << 2;
	return cpu_to_le16(regs);
}

__attribute__((used)) static int LM93_PWM_FREQ_FROM_REG(u8 reg)
{
	return lm93_pwm_freq_map[reg & 0x07];
}

__attribute__((used)) static u8 LM93_PWM_FREQ_TO_REG(int freq)
{
	int i;
	for (i = 7; i > 0; i--)
		if (freq <= lm93_pwm_freq_map[i])
			break;

	/* can fall through with i==0 */
	return (u8)i;
}

__attribute__((used)) static int LM93_SPINUP_TIME_FROM_REG(u8 reg)
{
	return lm93_spinup_time_map[reg >> 5 & 0x07];
}

__attribute__((used)) static u8 LM93_SPINUP_TIME_TO_REG(int time)
{
	int i;
	for (i = 0; i < 7; i++)
		if (time <= lm93_spinup_time_map[i])
			break;

	/* can fall through with i==8 */
	return (u8)i;
}

__attribute__((used)) static int LM93_RAMP_FROM_REG(u8 reg)
{
	return (reg & 0x0f) * 5;
}

__attribute__((used)) static u8 LM93_RAMP_TO_REG(int ramp)
{
	ramp = clamp_val(ramp, LM93_RAMP_MIN, LM93_RAMP_MAX);
	return (u8)((ramp + 2) / 5);
}

__attribute__((used)) static u8 LM93_PROCHOT_TO_REG(long prochot)
{
	prochot = clamp_val(prochot, 0, 255);
	return (u8)prochot;
}

__attribute__((used)) static int LM93_INTERVAL_FROM_REG(u8 reg)
{
	return lm93_interval_map[reg & 0x0f];
}

__attribute__((used)) static u8 LM93_INTERVAL_TO_REG(long interval)
{
	int i;
	for (i = 0; i < 9; i++)
		if (interval <= lm93_interval_map[i])
			break;

	/* can fall through with i==9 */
	return (u8)i;
}

__attribute__((used)) static unsigned LM93_GPI_FROM_REG(u8 reg)
{
	return ~reg & 0xff;
}

__attribute__((used)) static unsigned LM93_ALARMS_FROM_REG(struct block1_t b1)
{
	unsigned result;
	result  = b1.host_status_2 & 0x3f;

	if (vccp_limit_type[0])
		result |= (b1.host_status_4 & 0x10) << 2;
	else
		result |= b1.host_status_2 & 0x40;

	if (vccp_limit_type[1])
		result |= (b1.host_status_4 & 0x20) << 2;
	else
		result |= b1.host_status_2 & 0x80;

	result |= b1.host_status_3 << 8;
	result |= (b1.fan_status & 0x0f) << 16;
	result |= (b1.p1_prochot_status & 0x80) << 13;
	result |= (b1.p2_prochot_status & 0x80) << 14;
	result |= (b1.host_status_4 & 0xfc) << 20;
	result |= (b1.host_status_1 & 0x07) << 28;
	return result;
}

__attribute__((used)) static u8 lm93_read_byte(struct i2c_client *client, u8 reg)
{
	int value, i;

	/* retry in case of read errors */
	for (i = 1; i <= MAX_RETRIES; i++) {
		value = i2c_smbus_read_byte_data(client, reg);
		if (value >= 0) {
			return value;
		} else {
			dev_warn(&client->dev,
				 "lm93: read byte data failed, address 0x%02x.\n",
				 reg);
			mdelay(i + 3);
		}

	}

	/* <TODO> what to return in case of error? */
	dev_err(&client->dev, "lm93: All read byte retries failed!!\n");
	return 0;
}

__attribute__((used)) static int lm93_write_byte(struct i2c_client *client, u8 reg, u8 value)
{
	int result;

	/* <TODO> how to handle write errors? */
	result = i2c_smbus_write_byte_data(client, reg, value);

	if (result < 0)
		dev_warn(&client->dev,
			 "lm93: write byte data failed, 0x%02x at address 0x%02x.\n",
			 value, reg);

	return result;
}

__attribute__((used)) static u16 lm93_read_word(struct i2c_client *client, u8 reg)
{
	int value, i;

	/* retry in case of read errors */
	for (i = 1; i <= MAX_RETRIES; i++) {
		value = i2c_smbus_read_word_data(client, reg);
		if (value >= 0) {
			return value;
		} else {
			dev_warn(&client->dev,
				 "lm93: read word data failed, address 0x%02x.\n",
				 reg);
			mdelay(i + 3);
		}

	}

	/* <TODO> what to return in case of error? */
	dev_err(&client->dev, "lm93: All read word retries failed!!\n");
	return 0;
}

__attribute__((used)) static int lm93_write_word(struct i2c_client *client, u8 reg, u16 value)
{
	int result;

	/* <TODO> how to handle write errors? */
	result = i2c_smbus_write_word_data(client, reg, value);

	if (result < 0)
		dev_warn(&client->dev,
			 "lm93: write word data failed, 0x%04x at address 0x%02x.\n",
			 value, reg);

	return result;
}

__attribute__((used)) static void lm93_read_block(struct i2c_client *client, u8 fbn, u8 *values)
{
	int i, result = 0;

	for (i = 1; i <= MAX_RETRIES; i++) {
		result = i2c_smbus_read_block_data(client,
			lm93_block_read_cmds[fbn].cmd, lm93_block_buffer);

		if (result == lm93_block_read_cmds[fbn].len) {
			break;
		} else {
			dev_warn(&client->dev,
				 "lm93: block read data failed, command 0x%02x.\n",
				 lm93_block_read_cmds[fbn].cmd);
			mdelay(i + 3);
		}
	}

	if (result == lm93_block_read_cmds[fbn].len) {
		memcpy(values, lm93_block_buffer,
		       lm93_block_read_cmds[fbn].len);
	} else {
		/* <TODO> what to do in case of error? */
	}
}

__attribute__((used)) static struct lm93_data *lm93_update_device(struct device *dev)
{
	struct lm93_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	const unsigned long interval = HZ + (HZ / 2);

	mutex_lock(&data->update_lock);

	if (time_after(jiffies, data->last_updated + interval) ||
		!data->valid) {

		data->update(data, client);
		data->last_updated = jiffies;
		data->valid = 1;
	}

	mutex_unlock(&data->update_lock);
	return data;
}

__attribute__((used)) static void lm93_update_client_common(struct lm93_data *data,
				      struct i2c_client *client)
{
	int i;
	u8 *ptr;

	/* temp1 - temp4: limits */
	for (i = 0; i < 4; i++) {
		data->temp_lim[i].min =
			lm93_read_byte(client, LM93_REG_TEMP_MIN(i));
		data->temp_lim[i].max =
			lm93_read_byte(client, LM93_REG_TEMP_MAX(i));
	}

	/* config register */
	data->config = lm93_read_byte(client, LM93_REG_CONFIG);

	/* vid1 - vid2: values */
	for (i = 0; i < 2; i++)
		data->vid[i] = lm93_read_byte(client, LM93_REG_VID(i));

	/* prochot1 - prochot2: limits */
	for (i = 0; i < 2; i++)
		data->prochot_max[i] = lm93_read_byte(client,
				LM93_REG_PROCHOT_MAX(i));

	/* vccp1 - vccp2: VID relative limits */
	for (i = 0; i < 2; i++)
		data->vccp_limits[i] = lm93_read_byte(client,
				LM93_REG_VCCP_LIMIT_OFF(i));

	/* GPIO input state */
	data->gpi = lm93_read_byte(client, LM93_REG_GPI);

	/* #PROCHOT override state */
	data->prochot_override = lm93_read_byte(client,
			LM93_REG_PROCHOT_OVERRIDE);

	/* #PROCHOT intervals */
	data->prochot_interval = lm93_read_byte(client,
			LM93_REG_PROCHOT_INTERVAL);

	/* Fan Boost Temperature registers */
	for (i = 0; i < 4; i++)
		data->boost[i] = lm93_read_byte(client, LM93_REG_BOOST(i));

	/* Fan Boost Temperature Hyst. registers */
	data->boost_hyst[0] = lm93_read_byte(client, LM93_REG_BOOST_HYST_12);
	data->boost_hyst[1] = lm93_read_byte(client, LM93_REG_BOOST_HYST_34);

	/* Temperature Zone Min. PWM & Hysteresis registers */
	data->auto_pwm_min_hyst[0] =
			lm93_read_byte(client, LM93_REG_PWM_MIN_HYST_12);
	data->auto_pwm_min_hyst[1] =
			lm93_read_byte(client, LM93_REG_PWM_MIN_HYST_34);

	/* #PROCHOT & #VRDHOT PWM Ramp Control register */
	data->pwm_ramp_ctl = lm93_read_byte(client, LM93_REG_PWM_RAMP_CTL);

	/* misc setup registers */
	data->sfc1 = lm93_read_byte(client, LM93_REG_SFC1);
	data->sfc2 = lm93_read_byte(client, LM93_REG_SFC2);
	data->sf_tach_to_pwm = lm93_read_byte(client,
			LM93_REG_SF_TACH_TO_PWM);

	/* write back alarm values to clear */
	for (i = 0, ptr = (u8 *)(&data->block1); i < 8; i++)
		lm93_write_byte(client, LM93_REG_HOST_ERROR_1 + i, *(ptr + i));
}

__attribute__((used)) static void lm93_update_client_full(struct lm93_data *data,
				    struct i2c_client *client)
{
	dev_dbg(&client->dev, "starting device update (block data enabled)\n");

	/* in1 - in16: values & limits */
	lm93_read_block(client, 3, (u8 *)(data->block3));
	lm93_read_block(client, 7, (u8 *)(data->block7));

	/* temp1 - temp4: values */
	lm93_read_block(client, 2, (u8 *)(data->block2));

	/* prochot1 - prochot2: values */
	lm93_read_block(client, 4, (u8 *)(data->block4));

	/* fan1 - fan4: values & limits */
	lm93_read_block(client, 5, (u8 *)(data->block5));
	lm93_read_block(client, 8, (u8 *)(data->block8));

	/* pmw control registers */
	lm93_read_block(client, 9, (u8 *)(data->block9));

	/* alarm values */
	lm93_read_block(client, 1, (u8 *)(&data->block1));

	/* auto/pwm registers */
	lm93_read_block(client, 10, (u8 *)(&data->block10));

	lm93_update_client_common(data, client);
}

__attribute__((used)) static void lm93_update_client_min(struct lm93_data *data,
				   struct i2c_client *client)
{
	int i, j;
	u8 *ptr;

	dev_dbg(&client->dev, "starting device update (block data disabled)\n");

	/* in1 - in16: values & limits */
	for (i = 0; i < 16; i++) {
		data->block3[i] =
			lm93_read_byte(client, LM93_REG_IN(i));
		data->block7[i].min =
			lm93_read_byte(client, LM93_REG_IN_MIN(i));
		data->block7[i].max =
			lm93_read_byte(client, LM93_REG_IN_MAX(i));
	}

	/* temp1 - temp4: values */
	for (i = 0; i < 4; i++) {
		data->block2[i] =
			lm93_read_byte(client, LM93_REG_TEMP(i));
	}

	/* prochot1 - prochot2: values */
	for (i = 0; i < 2; i++) {
		data->block4[i].cur =
			lm93_read_byte(client, LM93_REG_PROCHOT_CUR(i));
		data->block4[i].avg =
			lm93_read_byte(client, LM93_REG_PROCHOT_AVG(i));
	}

	/* fan1 - fan4: values & limits */
	for (i = 0; i < 4; i++) {
		data->block5[i] =
			lm93_read_word(client, LM93_REG_FAN(i));
		data->block8[i] =
			lm93_read_word(client, LM93_REG_FAN_MIN(i));
	}

	/* pwm control registers */
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 4; j++) {
			data->block9[i][j] =
				lm93_read_byte(client, LM93_REG_PWM_CTL(i, j));
		}
	}

	/* alarm values */
	for (i = 0, ptr = (u8 *)(&data->block1); i < 8; i++) {
		*(ptr + i) =
			lm93_read_byte(client, LM93_REG_HOST_ERROR_1 + i);
	}

	/* auto/pwm (base temp) registers */
	for (i = 0; i < 4; i++) {
		data->block10.base[i] =
			lm93_read_byte(client, LM93_REG_TEMP_BASE(i));
	}

	/* auto/pwm (offset temp) registers */
	for (i = 0; i < 12; i++) {
		data->block10.offset[i] =
			lm93_read_byte(client, LM93_REG_TEMP_OFFSET(i));
	}

	lm93_update_client_common(data, client);
}

__attribute__((used)) static ssize_t show_in(struct device *dev, struct device_attribute *attr,
			char *buf)
{
	int nr = (to_sensor_dev_attr(attr))->index;

	struct lm93_data *data = lm93_update_device(dev);
	return sprintf(buf, "%d\n", LM93_IN_FROM_REG(nr, data->block3[nr]));
}

__attribute__((used)) static ssize_t show_in_min(struct device *dev,
			struct device_attribute *attr, char *buf)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = lm93_update_device(dev);
	int vccp = nr - 6;
	long rc, vid;

	if ((nr == 6 || nr == 7) && vccp_limit_type[vccp]) {
		vid = LM93_VID_FROM_REG(data->vid[vccp]);
		rc = LM93_IN_MIN_FROM_REG(data->vccp_limits[vccp], vid);
	} else {
		rc = LM93_IN_FROM_REG(nr, data->block7[nr].min);
	}
	return sprintf(buf, "%ld\n", rc);
}

__attribute__((used)) static ssize_t store_in_min(struct device *dev, struct device_attribute *attr,
			    const char *buf, size_t count)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	int vccp = nr - 6;
	long vid;
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	if ((nr == 6 || nr == 7) && vccp_limit_type[vccp]) {
		vid = LM93_VID_FROM_REG(data->vid[vccp]);
		data->vccp_limits[vccp] = (data->vccp_limits[vccp] & 0xf0) |
				LM93_IN_REL_TO_REG(val, 0, vid);
		lm93_write_byte(client, LM93_REG_VCCP_LIMIT_OFF(vccp),
				data->vccp_limits[vccp]);
	} else {
		data->block7[nr].min = LM93_IN_TO_REG(nr, val);
		lm93_write_byte(client, LM93_REG_IN_MIN(nr),
				data->block7[nr].min);
	}
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_in_max(struct device *dev,
			   struct device_attribute *attr, char *buf)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = lm93_update_device(dev);
	int vccp = nr - 6;
	long rc, vid;

	if ((nr == 6 || nr == 7) && vccp_limit_type[vccp]) {
		vid = LM93_VID_FROM_REG(data->vid[vccp]);
		rc = LM93_IN_MAX_FROM_REG(data->vccp_limits[vccp], vid);
	} else {
		rc = LM93_IN_FROM_REG(nr, data->block7[nr].max);
	}
	return sprintf(buf, "%ld\n", rc);
}

__attribute__((used)) static ssize_t store_in_max(struct device *dev, struct device_attribute *attr,
			    const char *buf, size_t count)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	int vccp = nr - 6;
	long vid;
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	if ((nr == 6 || nr == 7) && vccp_limit_type[vccp]) {
		vid = LM93_VID_FROM_REG(data->vid[vccp]);
		data->vccp_limits[vccp] = (data->vccp_limits[vccp] & 0x0f) |
				LM93_IN_REL_TO_REG(val, 1, vid);
		lm93_write_byte(client, LM93_REG_VCCP_LIMIT_OFF(vccp),
				data->vccp_limits[vccp]);
	} else {
		data->block7[nr].max = LM93_IN_TO_REG(nr, val);
		lm93_write_byte(client, LM93_REG_IN_MAX(nr),
				data->block7[nr].max);
	}
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_temp(struct device *dev,
			 struct device_attribute *attr, char *buf)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = lm93_update_device(dev);
	return sprintf(buf, "%d\n", LM93_TEMP_FROM_REG(data->block2[nr]));
}

__attribute__((used)) static ssize_t show_temp_min(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = lm93_update_device(dev);
	return sprintf(buf, "%d\n", LM93_TEMP_FROM_REG(data->temp_lim[nr].min));
}

__attribute__((used)) static ssize_t store_temp_min(struct device *dev, struct device_attribute *attr,
			      const char *buf, size_t count)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	long val;
	int err;

	err = kstrtol(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	data->temp_lim[nr].min = LM93_TEMP_TO_REG(val);
	lm93_write_byte(client, LM93_REG_TEMP_MIN(nr), data->temp_lim[nr].min);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_temp_max(struct device *dev,
			     struct device_attribute *attr, char *buf)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = lm93_update_device(dev);
	return sprintf(buf, "%d\n", LM93_TEMP_FROM_REG(data->temp_lim[nr].max));
}

__attribute__((used)) static ssize_t store_temp_max(struct device *dev, struct device_attribute *attr,
			      const char *buf, size_t count)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	long val;
	int err;

	err = kstrtol(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	data->temp_lim[nr].max = LM93_TEMP_TO_REG(val);
	lm93_write_byte(client, LM93_REG_TEMP_MAX(nr), data->temp_lim[nr].max);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_temp_auto_base(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = lm93_update_device(dev);
	return sprintf(buf, "%d\n", LM93_TEMP_FROM_REG(data->block10.base[nr]));
}

__attribute__((used)) static ssize_t store_temp_auto_base(struct device *dev,
					struct device_attribute *attr,
					const char *buf, size_t count)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	long val;
	int err;

	err = kstrtol(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	data->block10.base[nr] = LM93_TEMP_TO_REG(val);
	lm93_write_byte(client, LM93_REG_TEMP_BASE(nr), data->block10.base[nr]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_temp_auto_boost(struct device *dev,
				    struct device_attribute *attr, char *buf)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = lm93_update_device(dev);
	return sprintf(buf, "%d\n", LM93_TEMP_FROM_REG(data->boost[nr]));
}

__attribute__((used)) static ssize_t store_temp_auto_boost(struct device *dev,
				     struct device_attribute *attr,
				     const char *buf, size_t count)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	long val;
	int err;

	err = kstrtol(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	data->boost[nr] = LM93_TEMP_TO_REG(val);
	lm93_write_byte(client, LM93_REG_BOOST(nr), data->boost[nr]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_temp_auto_boost_hyst(struct device *dev,
					 struct device_attribute *attr,
					 char *buf)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = lm93_update_device(dev);
	int mode = LM93_TEMP_OFFSET_MODE_FROM_REG(data->sfc2, nr);
	return sprintf(buf, "%d\n",
		       LM93_AUTO_BOOST_HYST_FROM_REGS(data, nr, mode));
}

__attribute__((used)) static ssize_t store_temp_auto_boost_hyst(struct device *dev,
					  struct device_attribute *attr,
					  const char *buf, size_t count)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	/* force 0.5C/bit mode */
	data->sfc2 = lm93_read_byte(client, LM93_REG_SFC2);
	data->sfc2 |= ((nr < 2) ? 0x10 : 0x20);
	lm93_write_byte(client, LM93_REG_SFC2, data->sfc2);
	data->boost_hyst[nr/2] = LM93_AUTO_BOOST_HYST_TO_REG(data, val, nr, 1);
	lm93_write_byte(client, LM93_REG_BOOST_HYST(nr),
			data->boost_hyst[nr/2]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_temp_auto_offset(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	struct sensor_device_attribute_2 *s_attr = to_sensor_dev_attr_2(attr);
	int nr = s_attr->index;
	int ofs = s_attr->nr;
	struct lm93_data *data = lm93_update_device(dev);
	int mode = LM93_TEMP_OFFSET_MODE_FROM_REG(data->sfc2, nr);
	return sprintf(buf, "%d\n",
	       LM93_TEMP_AUTO_OFFSET_FROM_REG(data->block10.offset[ofs],
					      nr, mode));
}

__attribute__((used)) static ssize_t store_temp_auto_offset(struct device *dev,
					struct device_attribute *attr,
					const char *buf, size_t count)
{
	struct sensor_device_attribute_2 *s_attr = to_sensor_dev_attr_2(attr);
	int nr = s_attr->index;
	int ofs = s_attr->nr;
	struct lm93_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	/* force 0.5C/bit mode */
	data->sfc2 = lm93_read_byte(client, LM93_REG_SFC2);
	data->sfc2 |= ((nr < 2) ? 0x10 : 0x20);
	lm93_write_byte(client, LM93_REG_SFC2, data->sfc2);
	data->block10.offset[ofs] = LM93_TEMP_AUTO_OFFSET_TO_REG(
			data->block10.offset[ofs], val, nr, 1);
	lm93_write_byte(client, LM93_REG_TEMP_OFFSET(ofs),
			data->block10.offset[ofs]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_temp_auto_pwm_min(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	u8 reg, ctl4;
	struct lm93_data *data = lm93_update_device(dev);
	reg = data->auto_pwm_min_hyst[nr/2] >> 4 & 0x0f;
	ctl4 = data->block9[nr][LM93_PWM_CTL4];
	return sprintf(buf, "%d\n", LM93_PWM_FROM_REG(reg, (ctl4 & 0x07) ?
				LM93_PWM_MAP_LO_FREQ : LM93_PWM_MAP_HI_FREQ));
}

__attribute__((used)) static ssize_t store_temp_auto_pwm_min(struct device *dev,
					struct device_attribute *attr,
					const char *buf, size_t count)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	u8 reg, ctl4;
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	reg = lm93_read_byte(client, LM93_REG_PWM_MIN_HYST(nr));
	ctl4 = lm93_read_byte(client, LM93_REG_PWM_CTL(nr, LM93_PWM_CTL4));
	reg = (reg & 0x0f) |
		LM93_PWM_TO_REG(val, (ctl4 & 0x07) ?
				LM93_PWM_MAP_LO_FREQ :
				LM93_PWM_MAP_HI_FREQ) << 4;
	data->auto_pwm_min_hyst[nr/2] = reg;
	lm93_write_byte(client, LM93_REG_PWM_MIN_HYST(nr), reg);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_temp_auto_offset_hyst(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = lm93_update_device(dev);
	int mode = LM93_TEMP_OFFSET_MODE_FROM_REG(data->sfc2, nr);
	return sprintf(buf, "%d\n", LM93_TEMP_OFFSET_FROM_REG(
					data->auto_pwm_min_hyst[nr / 2], mode));
}

__attribute__((used)) static ssize_t store_temp_auto_offset_hyst(struct device *dev,
						struct device_attribute *attr,
						const char *buf, size_t count)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	u8 reg;
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	/* force 0.5C/bit mode */
	data->sfc2 = lm93_read_byte(client, LM93_REG_SFC2);
	data->sfc2 |= ((nr < 2) ? 0x10 : 0x20);
	lm93_write_byte(client, LM93_REG_SFC2, data->sfc2);
	reg = data->auto_pwm_min_hyst[nr/2];
	reg = (reg & 0xf0) | (LM93_TEMP_OFFSET_TO_REG(val, 1) & 0x0f);
	data->auto_pwm_min_hyst[nr/2] = reg;
	lm93_write_byte(client, LM93_REG_PWM_MIN_HYST(nr), reg);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_fan_input(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct sensor_device_attribute *s_attr = to_sensor_dev_attr(attr);
	int nr = s_attr->index;
	struct lm93_data *data = lm93_update_device(dev);

	return sprintf(buf, "%d\n", LM93_FAN_FROM_REG(data->block5[nr]));
}

__attribute__((used)) static ssize_t show_fan_min(struct device *dev,
			      struct device_attribute *attr, char *buf)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = lm93_update_device(dev);

	return sprintf(buf, "%d\n", LM93_FAN_FROM_REG(data->block8[nr]));
}

__attribute__((used)) static ssize_t store_fan_min(struct device *dev, struct device_attribute *attr,
				const char *buf, size_t count)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	data->block8[nr] = LM93_FAN_TO_REG(val);
	lm93_write_word(client, LM93_REG_FAN_MIN(nr), data->block8[nr]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_fan_smart_tach(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = lm93_update_device(dev);
	long rc = 0;
	int mapping;

	/* extract the relevant mapping */
	mapping = (data->sf_tach_to_pwm >> (nr * 2)) & 0x03;

	/* if there's a mapping and it's enabled */
	if (mapping && ((data->sfc2 >> nr) & 0x01))
		rc = mapping;
	return sprintf(buf, "%ld\n", rc);
}

__attribute__((used)) static void lm93_write_fan_smart_tach(struct i2c_client *client,
	struct lm93_data *data, int fan, long value)
{
	/* insert the new mapping and write it out */
	data->sf_tach_to_pwm = lm93_read_byte(client, LM93_REG_SF_TACH_TO_PWM);
	data->sf_tach_to_pwm &= ~(0x3 << fan * 2);
	data->sf_tach_to_pwm |= value << fan * 2;
	lm93_write_byte(client, LM93_REG_SF_TACH_TO_PWM, data->sf_tach_to_pwm);

	/* insert the enable bit and write it out */
	data->sfc2 = lm93_read_byte(client, LM93_REG_SFC2);
	if (value)
		data->sfc2 |= 1 << fan;
	else
		data->sfc2 &= ~(1 << fan);
	lm93_write_byte(client, LM93_REG_SFC2, data->sfc2);
}

__attribute__((used)) static ssize_t store_fan_smart_tach(struct device *dev,
					struct device_attribute *attr,
					const char *buf, size_t count)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	/* sanity test, ignore the write otherwise */
	if (val <= 2) {
		/* can't enable if pwm freq is 22.5KHz */
		if (val) {
			u8 ctl4 = lm93_read_byte(client,
				LM93_REG_PWM_CTL(val - 1, LM93_PWM_CTL4));
			if ((ctl4 & 0x07) == 0)
				val = 0;
		}
		lm93_write_fan_smart_tach(client, data, nr, val);
	}
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_pwm(struct device *dev, struct device_attribute *attr,
			char *buf)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = lm93_update_device(dev);
	u8 ctl2, ctl4;
	long rc;

	ctl2 = data->block9[nr][LM93_PWM_CTL2];
	ctl4 = data->block9[nr][LM93_PWM_CTL4];
	if (ctl2 & 0x01) /* show user commanded value if enabled */
		rc = data->pwm_override[nr];
	else /* show present h/w value if manual pwm disabled */
		rc = LM93_PWM_FROM_REG(ctl2 >> 4, (ctl4 & 0x07) ?
			LM93_PWM_MAP_LO_FREQ : LM93_PWM_MAP_HI_FREQ);
	return sprintf(buf, "%ld\n", rc);
}

__attribute__((used)) static ssize_t store_pwm(struct device *dev, struct device_attribute *attr,
				const char *buf, size_t count)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	u8 ctl2, ctl4;
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	ctl2 = lm93_read_byte(client, LM93_REG_PWM_CTL(nr, LM93_PWM_CTL2));
	ctl4 = lm93_read_byte(client, LM93_REG_PWM_CTL(nr, LM93_PWM_CTL4));
	ctl2 = (ctl2 & 0x0f) | LM93_PWM_TO_REG(val, (ctl4 & 0x07) ?
			LM93_PWM_MAP_LO_FREQ : LM93_PWM_MAP_HI_FREQ) << 4;
	/* save user commanded value */
	data->pwm_override[nr] = LM93_PWM_FROM_REG(ctl2 >> 4,
			(ctl4 & 0x07) ?  LM93_PWM_MAP_LO_FREQ :
			LM93_PWM_MAP_HI_FREQ);
	lm93_write_byte(client, LM93_REG_PWM_CTL(nr, LM93_PWM_CTL2), ctl2);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_pwm_enable(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = lm93_update_device(dev);
	u8 ctl2;
	long rc;

	ctl2 = data->block9[nr][LM93_PWM_CTL2];
	if (ctl2 & 0x01) /* manual override enabled ? */
		rc = ((ctl2 & 0xF0) == 0xF0) ? 0 : 1;
	else
		rc = 2;
	return sprintf(buf, "%ld\n", rc);
}

__attribute__((used)) static ssize_t store_pwm_enable(struct device *dev,
				struct device_attribute *attr,
				const char *buf, size_t count)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	u8 ctl2;
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	ctl2 = lm93_read_byte(client, LM93_REG_PWM_CTL(nr, LM93_PWM_CTL2));

	switch (val) {
	case 0:
		ctl2 |= 0xF1; /* enable manual override, set PWM to max */
		break;
	case 1:
		ctl2 |= 0x01; /* enable manual override */
		break;
	case 2:
		ctl2 &= ~0x01; /* disable manual override */
		break;
	default:
		mutex_unlock(&data->update_lock);
		return -EINVAL;
	}

	lm93_write_byte(client, LM93_REG_PWM_CTL(nr, LM93_PWM_CTL2), ctl2);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_pwm_freq(struct device *dev, struct device_attribute *attr,
				char *buf)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = lm93_update_device(dev);
	u8 ctl4;

	ctl4 = data->block9[nr][LM93_PWM_CTL4];
	return sprintf(buf, "%d\n", LM93_PWM_FREQ_FROM_REG(ctl4));
}

__attribute__((used)) static void lm93_disable_fan_smart_tach(struct i2c_client *client,
	struct lm93_data *data, int pwm)
{
	int mapping = lm93_read_byte(client, LM93_REG_SF_TACH_TO_PWM);
	int mask;

	/* collapse the mapping into a mask of enable bits */
	mapping = (mapping >> pwm) & 0x55;
	mask = mapping & 0x01;
	mask |= (mapping & 0x04) >> 1;
	mask |= (mapping & 0x10) >> 2;
	mask |= (mapping & 0x40) >> 3;

	/* disable smart tach according to the mask */
	data->sfc2 = lm93_read_byte(client, LM93_REG_SFC2);
	data->sfc2 &= ~mask;
	lm93_write_byte(client, LM93_REG_SFC2, data->sfc2);
}

__attribute__((used)) static ssize_t store_pwm_freq(struct device *dev,
				struct device_attribute *attr,
				const char *buf, size_t count)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	u8 ctl4;
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	ctl4 = lm93_read_byte(client, LM93_REG_PWM_CTL(nr, LM93_PWM_CTL4));
	ctl4 = (ctl4 & 0xf8) | LM93_PWM_FREQ_TO_REG(val);
	data->block9[nr][LM93_PWM_CTL4] = ctl4;
	/* ctl4 == 0 -> 22.5KHz -> disable smart tach */
	if (!ctl4)
		lm93_disable_fan_smart_tach(client, data, nr);
	lm93_write_byte(client, LM93_REG_PWM_CTL(nr, LM93_PWM_CTL4), ctl4);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_pwm_auto_channels(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = lm93_update_device(dev);
	return sprintf(buf, "%d\n", data->block9[nr][LM93_PWM_CTL1]);
}

__attribute__((used)) static ssize_t store_pwm_auto_channels(struct device *dev,
					struct device_attribute *attr,
					const char *buf, size_t count)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	data->block9[nr][LM93_PWM_CTL1] = clamp_val(val, 0, 255);
	lm93_write_byte(client, LM93_REG_PWM_CTL(nr, LM93_PWM_CTL1),
				data->block9[nr][LM93_PWM_CTL1]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_pwm_auto_spinup_min(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = lm93_update_device(dev);
	u8 ctl3, ctl4;

	ctl3 = data->block9[nr][LM93_PWM_CTL3];
	ctl4 = data->block9[nr][LM93_PWM_CTL4];
	return sprintf(buf, "%d\n",
		       LM93_PWM_FROM_REG(ctl3 & 0x0f, (ctl4 & 0x07) ?
			LM93_PWM_MAP_LO_FREQ : LM93_PWM_MAP_HI_FREQ));
}

__attribute__((used)) static ssize_t store_pwm_auto_spinup_min(struct device *dev,
						struct device_attribute *attr,
						const char *buf, size_t count)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	u8 ctl3, ctl4;
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	ctl3 = lm93_read_byte(client, LM93_REG_PWM_CTL(nr, LM93_PWM_CTL3));
	ctl4 = lm93_read_byte(client, LM93_REG_PWM_CTL(nr, LM93_PWM_CTL4));
	ctl3 = (ctl3 & 0xf0) | LM93_PWM_TO_REG(val, (ctl4 & 0x07) ?
			LM93_PWM_MAP_LO_FREQ :
			LM93_PWM_MAP_HI_FREQ);
	data->block9[nr][LM93_PWM_CTL3] = ctl3;
	lm93_write_byte(client, LM93_REG_PWM_CTL(nr, LM93_PWM_CTL3), ctl3);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_pwm_auto_spinup_time(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = lm93_update_device(dev);
	return sprintf(buf, "%d\n", LM93_SPINUP_TIME_FROM_REG(
				data->block9[nr][LM93_PWM_CTL3]));
}

__attribute__((used)) static ssize_t store_pwm_auto_spinup_time(struct device *dev,
						struct device_attribute *attr,
						const char *buf, size_t count)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	u8 ctl3;
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	ctl3 = lm93_read_byte(client, LM93_REG_PWM_CTL(nr, LM93_PWM_CTL3));
	ctl3 = (ctl3 & 0x1f) | (LM93_SPINUP_TIME_TO_REG(val) << 5 & 0xe0);
	data->block9[nr][LM93_PWM_CTL3] = ctl3;
	lm93_write_byte(client, LM93_REG_PWM_CTL(nr, LM93_PWM_CTL3), ctl3);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t pwm_auto_prochot_ramp_show(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	struct lm93_data *data = lm93_update_device(dev);
	return sprintf(buf, "%d\n",
		       LM93_RAMP_FROM_REG(data->pwm_ramp_ctl >> 4 & 0x0f));
}

__attribute__((used)) static ssize_t pwm_auto_prochot_ramp_store(struct device *dev,
						struct device_attribute *attr,
						const char *buf, size_t count)
{
	struct lm93_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	u8 ramp;
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	ramp = lm93_read_byte(client, LM93_REG_PWM_RAMP_CTL);
	ramp = (ramp & 0x0f) | (LM93_RAMP_TO_REG(val) << 4 & 0xf0);
	lm93_write_byte(client, LM93_REG_PWM_RAMP_CTL, ramp);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t pwm_auto_vrdhot_ramp_show(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	struct lm93_data *data = lm93_update_device(dev);
	return sprintf(buf, "%d\n",
		       LM93_RAMP_FROM_REG(data->pwm_ramp_ctl & 0x0f));
}

__attribute__((used)) static ssize_t pwm_auto_vrdhot_ramp_store(struct device *dev,
						struct device_attribute *attr,
						const char *buf, size_t count)
{
	struct lm93_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	u8 ramp;
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	ramp = lm93_read_byte(client, LM93_REG_PWM_RAMP_CTL);
	ramp = (ramp & 0xf0) | (LM93_RAMP_TO_REG(val) & 0x0f);
	lm93_write_byte(client, LM93_REG_PWM_RAMP_CTL, ramp);
	mutex_unlock(&data->update_lock);
	return 0;
}

__attribute__((used)) static ssize_t show_vid(struct device *dev, struct device_attribute *attr,
			char *buf)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = lm93_update_device(dev);
	return sprintf(buf, "%d\n", LM93_VID_FROM_REG(data->vid[nr]));
}

__attribute__((used)) static ssize_t show_prochot(struct device *dev, struct device_attribute *attr,
				char *buf)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = lm93_update_device(dev);
	return sprintf(buf, "%d\n", data->block4[nr].cur);
}

__attribute__((used)) static ssize_t show_prochot_avg(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = lm93_update_device(dev);
	return sprintf(buf, "%d\n", data->block4[nr].avg);
}

__attribute__((used)) static ssize_t show_prochot_max(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = lm93_update_device(dev);
	return sprintf(buf, "%d\n", data->prochot_max[nr]);
}

__attribute__((used)) static ssize_t store_prochot_max(struct device *dev,
					struct device_attribute *attr,
					const char *buf, size_t count)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	data->prochot_max[nr] = LM93_PROCHOT_TO_REG(val);
	lm93_write_byte(client, LM93_REG_PROCHOT_MAX(nr),
			data->prochot_max[nr]);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_prochot_override(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = lm93_update_device(dev);
	return sprintf(buf, "%d\n",
		(data->prochot_override & prochot_override_mask[nr]) ? 1 : 0);
}

__attribute__((used)) static ssize_t store_prochot_override(struct device *dev,
					struct device_attribute *attr,
					const char *buf, size_t count)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	if (val)
		data->prochot_override |= prochot_override_mask[nr];
	else
		data->prochot_override &= (~prochot_override_mask[nr]);
	lm93_write_byte(client, LM93_REG_PROCHOT_OVERRIDE,
			data->prochot_override);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_prochot_interval(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = lm93_update_device(dev);
	u8 tmp;
	if (nr == 1)
		tmp = (data->prochot_interval & 0xf0) >> 4;
	else
		tmp = data->prochot_interval & 0x0f;
	return sprintf(buf, "%d\n", LM93_INTERVAL_FROM_REG(tmp));
}

__attribute__((used)) static ssize_t store_prochot_interval(struct device *dev,
					struct device_attribute *attr,
					const char *buf, size_t count)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	u8 tmp;
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	tmp = lm93_read_byte(client, LM93_REG_PROCHOT_INTERVAL);
	if (nr == 1)
		tmp = (tmp & 0x0f) | (LM93_INTERVAL_TO_REG(val) << 4);
	else
		tmp = (tmp & 0xf0) | LM93_INTERVAL_TO_REG(val);
	data->prochot_interval = tmp;
	lm93_write_byte(client, LM93_REG_PROCHOT_INTERVAL, tmp);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t prochot_override_duty_cycle_show(struct device *dev,
						struct device_attribute *attr,
						char *buf)
{
	struct lm93_data *data = lm93_update_device(dev);
	return sprintf(buf, "%d\n", data->prochot_override & 0x0f);
}

__attribute__((used)) static ssize_t prochot_override_duty_cycle_store(struct device *dev,
						struct device_attribute *attr,
						const char *buf, size_t count)
{
	struct lm93_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	data->prochot_override = (data->prochot_override & 0xf0) |
					clamp_val(val, 0, 15);
	lm93_write_byte(client, LM93_REG_PROCHOT_OVERRIDE,
			data->prochot_override);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t prochot_short_show(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	struct lm93_data *data = lm93_update_device(dev);
	return sprintf(buf, "%d\n", (data->config & 0x10) ? 1 : 0);
}

__attribute__((used)) static ssize_t prochot_short_store(struct device *dev,
					struct device_attribute *attr,
					const char *buf, size_t count)
{
	struct lm93_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	if (val)
		data->config |= 0x10;
	else
		data->config &= ~0x10;
	lm93_write_byte(client, LM93_REG_CONFIG, data->config);
	mutex_unlock(&data->update_lock);
	return count;
}

__attribute__((used)) static ssize_t show_vrdhot(struct device *dev, struct device_attribute *attr,
				char *buf)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = lm93_update_device(dev);
	return sprintf(buf, "%d\n",
		       data->block1.host_status_1 & (1 << (nr + 4)) ? 1 : 0);
}

__attribute__((used)) static ssize_t gpio_show(struct device *dev, struct device_attribute *attr,
				char *buf)
{
	struct lm93_data *data = lm93_update_device(dev);
	return sprintf(buf, "%d\n", LM93_GPI_FROM_REG(data->gpi));
}

__attribute__((used)) static ssize_t alarms_show(struct device *dev, struct device_attribute *attr,
				char *buf)
{
	struct lm93_data *data = lm93_update_device(dev);
	return sprintf(buf, "%d\n", LM93_ALARMS_FROM_REG(data->block1));
}

__attribute__((used)) static void lm93_init_client(struct i2c_client *client)
{
	int i;
	u8 reg;

	/* configure VID pin input thresholds */
	reg = lm93_read_byte(client, LM93_REG_GPI_VID_CTL);
	lm93_write_byte(client, LM93_REG_GPI_VID_CTL,
			reg | (vid_agtl ? 0x03 : 0x00));

	if (init) {
		/* enable #ALERT pin */
		reg = lm93_read_byte(client, LM93_REG_CONFIG);
		lm93_write_byte(client, LM93_REG_CONFIG, reg | 0x08);

		/* enable ASF mode for BMC status registers */
		reg = lm93_read_byte(client, LM93_REG_STATUS_CONTROL);
		lm93_write_byte(client, LM93_REG_STATUS_CONTROL, reg | 0x02);

		/* set sleep state to S0 */
		lm93_write_byte(client, LM93_REG_SLEEP_CONTROL, 0);

		/* unmask #VRDHOT and dynamic VCCP (if nec) error events */
		reg = lm93_read_byte(client, LM93_REG_MISC_ERR_MASK);
		reg &= ~0x03;
		reg &= ~(vccp_limit_type[0] ? 0x10 : 0);
		reg &= ~(vccp_limit_type[1] ? 0x20 : 0);
		lm93_write_byte(client, LM93_REG_MISC_ERR_MASK, reg);
	}

	/* start monitoring */
	reg = lm93_read_byte(client, LM93_REG_CONFIG);
	lm93_write_byte(client, LM93_REG_CONFIG, reg | 0x01);

	/* spin until ready */
	for (i = 0; i < 20; i++) {
		msleep(10);
		if ((lm93_read_byte(client, LM93_REG_CONFIG) & 0x80) == 0x80)
			return;
	}

	dev_warn(&client->dev,
		 "timed out waiting for sensor chip to signal ready!\n");
}

__attribute__((used)) static int lm93_detect(struct i2c_client *client, struct i2c_board_info *info)
{
	struct i2c_adapter *adapter = client->adapter;
	int mfr, ver;
	const char *name;

	if (!i2c_check_functionality(adapter, LM93_SMBUS_FUNC_MIN))
		return -ENODEV;

	/* detection */
	mfr = lm93_read_byte(client, LM93_REG_MFR_ID);
	if (mfr != 0x01) {
		dev_dbg(&adapter->dev,
			"detect failed, bad manufacturer id 0x%02x!\n", mfr);
		return -ENODEV;
	}

	ver = lm93_read_byte(client, LM93_REG_VER);
	switch (ver) {
	case LM93_MFR_ID:
	case LM93_MFR_ID_PROTOTYPE:
		name = "lm93";
		break;
	case LM94_MFR_ID_2:
	case LM94_MFR_ID:
	case LM94_MFR_ID_PROTOTYPE:
		name = "lm94";
		break;
	default:
		dev_dbg(&adapter->dev,
			"detect failed, bad version id 0x%02x!\n", ver);
		return -ENODEV;
	}

	strlcpy(info->type, name, I2C_NAME_SIZE);
	dev_dbg(&adapter->dev, "loading %s at %d, 0x%02x\n",
		client->name, i2c_adapter_id(client->adapter),
		client->addr);

	return 0;
}

__attribute__((used)) static int lm93_probe(struct i2c_client *client,
		      const struct i2c_device_id *id)
{
	struct device *dev = &client->dev;
	struct lm93_data *data;
	struct device *hwmon_dev;
	int func;
	void (*update)(struct lm93_data *, struct i2c_client *);

	/* choose update routine based on bus capabilities */
	func = i2c_get_functionality(client->adapter);
	if (((LM93_SMBUS_FUNC_FULL & func) == LM93_SMBUS_FUNC_FULL) &&
			(!disable_block)) {
		dev_dbg(dev, "using SMBus block data transactions\n");
		update = lm93_update_client_full;
	} else if ((LM93_SMBUS_FUNC_MIN & func) == LM93_SMBUS_FUNC_MIN) {
		dev_dbg(dev, "disabled SMBus block data transactions\n");
		update = lm93_update_client_min;
	} else {
		dev_dbg(dev, "detect failed, smbus byte and/or word data not supported!\n");
		return -ENODEV;
	}

	data = devm_kzalloc(dev, sizeof(struct lm93_data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	/* housekeeping */
	data->client = client;
	data->update = update;
	mutex_init(&data->update_lock);

	/* initialize the chip */
	lm93_init_client(client);

	hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
							   data,
							   lm93_groups);
	return PTR_ERR_OR_ZERO(hwmon_dev);
}

