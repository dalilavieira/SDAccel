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
typedef  int u32 ;
typedef  int u16 ;
struct i2c_device_id {int dummy; } ;
struct device {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  name; int /*<<< orphan*/  adapter; struct device dev; } ;
struct g762_platform_data {unsigned long fan_gear_mode; unsigned long pwm_polarity; unsigned long fan_startv; unsigned long clk_freq; } ;
struct g762_data {int valid; int set_cnt; int act_cnt; int fan_sta; int set_out; int fan_cmd1; int fan_cmd2; unsigned long clk_freq; int /*<<< orphan*/  update_lock; struct i2c_client* client; scalar_t__ last_updated; } ;
struct device_attribute {int dummy; } ;
typedef  int ssize_t ;

/* Variables and functions */
 unsigned char DIV_ROUND_CLOSEST (unsigned long,unsigned long) ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 struct g762_data* ERR_PTR (int) ; 
 int G762_CLKDIV_FROM_REG (unsigned long) ; 
#define  G762_FAN_MODE_CLOSED_LOOP 133 
#define  G762_FAN_MODE_OPEN_LOOP 132 
 int G762_GEARMULT_FROM_REG (unsigned long) ; 
#define  G762_OUT_MODE_DC 131 
#define  G762_OUT_MODE_PWM 130 
 int G762_PULSE_FROM_REG (unsigned long) ; 
#define  G762_PWM_POLARITY_NEGATIVE 129 
#define  G762_PWM_POLARITY_POSITIVE 128 
 int /*<<< orphan*/  G762_REG_ACT_CNT ; 
 int /*<<< orphan*/  G762_REG_FAN_CMD1 ; 
 unsigned long G762_REG_FAN_CMD1_CLK_DIV_ID0 ; 
 unsigned long G762_REG_FAN_CMD1_CLK_DIV_ID1 ; 
 unsigned long G762_REG_FAN_CMD1_DET_FAN_FAIL ; 
 unsigned long G762_REG_FAN_CMD1_DET_FAN_OOC ; 
 int G762_REG_FAN_CMD1_FAN_MODE ; 
 int G762_REG_FAN_CMD1_OUT_MODE ; 
 unsigned long G762_REG_FAN_CMD1_PULSE_PER_REV ; 
 unsigned long G762_REG_FAN_CMD1_PWM_POLARITY ; 
 int /*<<< orphan*/  G762_REG_FAN_CMD2 ; 
 unsigned long G762_REG_FAN_CMD2_FAN_STARTV_0 ; 
 unsigned long G762_REG_FAN_CMD2_FAN_STARTV_1 ; 
 int G762_REG_FAN_CMD2_GEAR_MODE_0 ; 
 int G762_REG_FAN_CMD2_GEAR_MODE_1 ; 
 int /*<<< orphan*/  G762_REG_FAN_STA ; 
 int G762_REG_FAN_STA_FAIL ; 
 int G762_REG_FAN_STA_OOC ; 
 int /*<<< orphan*/  G762_REG_SET_CNT ; 
 int /*<<< orphan*/  G762_REG_SET_OUT ; 
 scalar_t__ G762_UPDATE_INTERVAL ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_BYTE_DATA ; 
 scalar_t__ IS_ERR (struct g762_data*) ; 
 int PTR_ERR (struct g762_data*) ; 
 int PTR_ERR_OR_ZERO (struct device*) ; 
 unsigned long ULONG_MAX ; 
 unsigned long clamp_val (unsigned long,unsigned long,unsigned long) ; 
 struct g762_data* dev_get_drvdata (struct device*) ; 
 struct g762_platform_data* dev_get_platdata (struct device*) ; 
 struct device* devm_hwmon_device_register_with_groups (struct device*,int /*<<< orphan*/ ,struct g762_data*,int /*<<< orphan*/ ) ; 
 struct g762_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  g762_groups ; 
 int /*<<< orphan*/  i2c_check_functionality (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct g762_data*) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int /*<<< orphan*/ ,unsigned long) ; 
 scalar_t__ jiffies ; 
 scalar_t__ kstrtoul (char const*,int,unsigned long*) ; 
 scalar_t__ likely (int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int sprintf (char*,char*,int) ; 
 scalar_t__ time_before (scalar_t__,scalar_t__) ; 

__attribute__((used)) static inline unsigned int rpm_from_cnt(u8 cnt, u32 clk_freq, u16 p,
					u8 clk_div, u8 gear_mult)
{
	if (cnt == 0xff)  /* setting cnt to 255 stops the fan */
		return 0;

	return (clk_freq * 30 * gear_mult) / ((cnt ? cnt : 1) * p * clk_div);
}

__attribute__((used)) static inline unsigned char cnt_from_rpm(unsigned long rpm, u32 clk_freq, u16 p,
					 u8 clk_div, u8 gear_mult)
{
	unsigned long f1 = clk_freq * 30 * gear_mult;
	unsigned long f2 = p * clk_div;

	if (!rpm)	/* to stop the fan, set cnt to 255 */
		return 0xff;

	rpm = clamp_val(rpm, f1 / (255 * f2), ULONG_MAX / f2);
	return DIV_ROUND_CLOSEST(f1, rpm * f2);
}

__attribute__((used)) static struct g762_data *g762_update_client(struct device *dev)
{
	struct g762_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	int ret = 0;

	mutex_lock(&data->update_lock);
	if (time_before(jiffies, data->last_updated + G762_UPDATE_INTERVAL) &&
	    likely(data->valid))
		goto out;

	ret = i2c_smbus_read_byte_data(client, G762_REG_SET_CNT);
	if (ret < 0)
		goto out;
	data->set_cnt = ret;

	ret = i2c_smbus_read_byte_data(client, G762_REG_ACT_CNT);
	if (ret < 0)
		goto out;
	data->act_cnt = ret;

	ret = i2c_smbus_read_byte_data(client, G762_REG_FAN_STA);
	if (ret < 0)
		goto out;
	data->fan_sta = ret;

	ret = i2c_smbus_read_byte_data(client, G762_REG_SET_OUT);
	if (ret < 0)
		goto out;
	data->set_out = ret;

	ret = i2c_smbus_read_byte_data(client, G762_REG_FAN_CMD1);
	if (ret < 0)
		goto out;
	data->fan_cmd1 = ret;

	ret = i2c_smbus_read_byte_data(client, G762_REG_FAN_CMD2);
	if (ret < 0)
		goto out;
	data->fan_cmd2 = ret;

	data->last_updated = jiffies;
	data->valid = true;
 out:
	mutex_unlock(&data->update_lock);

	if (ret < 0) /* upon error, encode it in return value */
		data = ERR_PTR(ret);

	return data;
}

__attribute__((used)) static int do_set_clk_freq(struct device *dev, unsigned long val)
{
	struct g762_data *data = dev_get_drvdata(dev);

	if (val > 0xffffff)
		return -EINVAL;
	if (!val)
		val = 32768;

	data->clk_freq = val;

	return 0;
}

__attribute__((used)) static int do_set_pwm_mode(struct device *dev, unsigned long val)
{
	struct g762_data *data = g762_update_client(dev);
	int ret;

	if (IS_ERR(data))
		return PTR_ERR(data);

	mutex_lock(&data->update_lock);
	switch (val) {
	case G762_OUT_MODE_PWM:
		data->fan_cmd1 |=  G762_REG_FAN_CMD1_OUT_MODE;
		break;
	case G762_OUT_MODE_DC:
		data->fan_cmd1 &= ~G762_REG_FAN_CMD1_OUT_MODE;
		break;
	default:
		ret = -EINVAL;
		goto out;
	}
	ret = i2c_smbus_write_byte_data(data->client, G762_REG_FAN_CMD1,
					data->fan_cmd1);
	data->valid = false;
 out:
	mutex_unlock(&data->update_lock);

	return ret;
}

__attribute__((used)) static int do_set_fan_div(struct device *dev, unsigned long val)
{
	struct g762_data *data = g762_update_client(dev);
	int ret;

	if (IS_ERR(data))
		return PTR_ERR(data);

	mutex_lock(&data->update_lock);
	switch (val) {
	case 1:
		data->fan_cmd1 &= ~G762_REG_FAN_CMD1_CLK_DIV_ID0;
		data->fan_cmd1 &= ~G762_REG_FAN_CMD1_CLK_DIV_ID1;
		break;
	case 2:
		data->fan_cmd1 |=  G762_REG_FAN_CMD1_CLK_DIV_ID0;
		data->fan_cmd1 &= ~G762_REG_FAN_CMD1_CLK_DIV_ID1;
		break;
	case 4:
		data->fan_cmd1 &= ~G762_REG_FAN_CMD1_CLK_DIV_ID0;
		data->fan_cmd1 |=  G762_REG_FAN_CMD1_CLK_DIV_ID1;
		break;
	case 8:
		data->fan_cmd1 |=  G762_REG_FAN_CMD1_CLK_DIV_ID0;
		data->fan_cmd1 |=  G762_REG_FAN_CMD1_CLK_DIV_ID1;
		break;
	default:
		ret = -EINVAL;
		goto out;
	}
	ret = i2c_smbus_write_byte_data(data->client, G762_REG_FAN_CMD1,
					data->fan_cmd1);
	data->valid = false;
 out:
	mutex_unlock(&data->update_lock);

	return ret;
}

__attribute__((used)) static int do_set_fan_gear_mode(struct device *dev, unsigned long val)
{
	struct g762_data *data = g762_update_client(dev);
	int ret;

	if (IS_ERR(data))
		return PTR_ERR(data);

	mutex_lock(&data->update_lock);
	switch (val) {
	case 0:
		data->fan_cmd2 &= ~G762_REG_FAN_CMD2_GEAR_MODE_0;
		data->fan_cmd2 &= ~G762_REG_FAN_CMD2_GEAR_MODE_1;
		break;
	case 1:
		data->fan_cmd2 |=  G762_REG_FAN_CMD2_GEAR_MODE_0;
		data->fan_cmd2 &= ~G762_REG_FAN_CMD2_GEAR_MODE_1;
		break;
	case 2:
		data->fan_cmd2 &= ~G762_REG_FAN_CMD2_GEAR_MODE_0;
		data->fan_cmd2 |=  G762_REG_FAN_CMD2_GEAR_MODE_1;
		break;
	default:
		ret = -EINVAL;
		goto out;
	}
	ret = i2c_smbus_write_byte_data(data->client, G762_REG_FAN_CMD2,
					data->fan_cmd2);
	data->valid = false;
 out:
	mutex_unlock(&data->update_lock);

	return ret;
}

__attribute__((used)) static int do_set_fan_pulses(struct device *dev, unsigned long val)
{
	struct g762_data *data = g762_update_client(dev);
	int ret;

	if (IS_ERR(data))
		return PTR_ERR(data);

	mutex_lock(&data->update_lock);
	switch (val) {
	case 2:
		data->fan_cmd1 &= ~G762_REG_FAN_CMD1_PULSE_PER_REV;
		break;
	case 4:
		data->fan_cmd1 |=  G762_REG_FAN_CMD1_PULSE_PER_REV;
		break;
	default:
		ret = -EINVAL;
		goto out;
	}
	ret = i2c_smbus_write_byte_data(data->client, G762_REG_FAN_CMD1,
					data->fan_cmd1);
	data->valid = false;
 out:
	mutex_unlock(&data->update_lock);

	return ret;
}

__attribute__((used)) static int do_set_pwm_enable(struct device *dev, unsigned long val)
{
	struct g762_data *data = g762_update_client(dev);
	int ret;

	if (IS_ERR(data))
		return PTR_ERR(data);

	mutex_lock(&data->update_lock);
	switch (val) {
	case G762_FAN_MODE_CLOSED_LOOP:
		data->fan_cmd1 |=  G762_REG_FAN_CMD1_FAN_MODE;
		break;
	case G762_FAN_MODE_OPEN_LOOP:
		data->fan_cmd1 &= ~G762_REG_FAN_CMD1_FAN_MODE;
		/*
		 * BUG FIX: if SET_CNT register value is 255 then, for some
		 * unknown reason, fan will not rotate as expected, no matter
		 * the value of SET_OUT (to be specific, this seems to happen
		 * only in PWM mode). To workaround this bug, we give SET_CNT
		 * value of 254 if it is 255 when switching to open-loop.
		 */
		if (data->set_cnt == 0xff)
			i2c_smbus_write_byte_data(data->client,
						  G762_REG_SET_CNT, 254);
		break;
	default:
		ret = -EINVAL;
		goto out;
	}

	ret = i2c_smbus_write_byte_data(data->client, G762_REG_FAN_CMD1,
					data->fan_cmd1);
	data->valid = false;
 out:
	mutex_unlock(&data->update_lock);

	return ret;
}

__attribute__((used)) static int do_set_pwm_polarity(struct device *dev, unsigned long val)
{
	struct g762_data *data = g762_update_client(dev);
	int ret;

	if (IS_ERR(data))
		return PTR_ERR(data);

	mutex_lock(&data->update_lock);
	switch (val) {
	case G762_PWM_POLARITY_POSITIVE:
		data->fan_cmd1 &= ~G762_REG_FAN_CMD1_PWM_POLARITY;
		break;
	case G762_PWM_POLARITY_NEGATIVE:
		data->fan_cmd1 |=  G762_REG_FAN_CMD1_PWM_POLARITY;
		break;
	default:
		ret = -EINVAL;
		goto out;
	}
	ret = i2c_smbus_write_byte_data(data->client, G762_REG_FAN_CMD1,
					data->fan_cmd1);
	data->valid = false;
 out:
	mutex_unlock(&data->update_lock);

	return ret;
}

__attribute__((used)) static int do_set_pwm(struct device *dev, unsigned long val)
{
	struct g762_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	int ret;

	if (val > 255)
		return -EINVAL;

	mutex_lock(&data->update_lock);
	ret = i2c_smbus_write_byte_data(client, G762_REG_SET_OUT, val);
	data->valid = false;
	mutex_unlock(&data->update_lock);

	return ret;
}

__attribute__((used)) static int do_set_fan_target(struct device *dev, unsigned long val)
{
	struct g762_data *data = g762_update_client(dev);
	int ret;

	if (IS_ERR(data))
		return PTR_ERR(data);

	mutex_lock(&data->update_lock);
	data->set_cnt = cnt_from_rpm(val, data->clk_freq,
				     G762_PULSE_FROM_REG(data->fan_cmd1),
				     G762_CLKDIV_FROM_REG(data->fan_cmd1),
				     G762_GEARMULT_FROM_REG(data->fan_cmd2));
	ret = i2c_smbus_write_byte_data(data->client, G762_REG_SET_CNT,
					data->set_cnt);
	data->valid = false;
	mutex_unlock(&data->update_lock);

	return ret;
}

__attribute__((used)) static int do_set_fan_startv(struct device *dev, unsigned long val)
{
	struct g762_data *data = g762_update_client(dev);
	int ret;

	if (IS_ERR(data))
		return PTR_ERR(data);

	mutex_lock(&data->update_lock);
	switch (val) {
	case 0:
		data->fan_cmd2 &= ~G762_REG_FAN_CMD2_FAN_STARTV_0;
		data->fan_cmd2 &= ~G762_REG_FAN_CMD2_FAN_STARTV_1;
		break;
	case 1:
		data->fan_cmd2 |=  G762_REG_FAN_CMD2_FAN_STARTV_0;
		data->fan_cmd2 &= ~G762_REG_FAN_CMD2_FAN_STARTV_1;
		break;
	case 2:
		data->fan_cmd2 &= ~G762_REG_FAN_CMD2_FAN_STARTV_0;
		data->fan_cmd2 |=  G762_REG_FAN_CMD2_FAN_STARTV_1;
		break;
	case 3:
		data->fan_cmd2 |=  G762_REG_FAN_CMD2_FAN_STARTV_0;
		data->fan_cmd2 |=  G762_REG_FAN_CMD2_FAN_STARTV_1;
		break;
	default:
		ret = -EINVAL;
		goto out;
	}
	ret = i2c_smbus_write_byte_data(data->client, G762_REG_FAN_CMD2,
					data->fan_cmd2);
	data->valid = false;
 out:
	mutex_unlock(&data->update_lock);

	return ret;
}

__attribute__((used)) static int g762_of_prop_import(struct i2c_client *client)
{
	return 0;
}

__attribute__((used)) static int g762_of_clock_enable(struct i2c_client *client)
{
	return 0;
}

__attribute__((used)) static int g762_pdata_prop_import(struct i2c_client *client)
{
	struct g762_platform_data *pdata = dev_get_platdata(&client->dev);
	int ret;

	if (!pdata)
		return 0;

	ret = do_set_fan_gear_mode(&client->dev, pdata->fan_gear_mode);
	if (ret)
		return ret;

	ret = do_set_pwm_polarity(&client->dev, pdata->pwm_polarity);
	if (ret)
		return ret;

	ret = do_set_fan_startv(&client->dev, pdata->fan_startv);
	if (ret)
		return ret;

	return do_set_clk_freq(&client->dev, pdata->clk_freq);
}

__attribute__((used)) static ssize_t fan1_input_show(struct device *dev,
			       struct device_attribute *da, char *buf)
{
	struct g762_data *data = g762_update_client(dev);
	unsigned int rpm = 0;

	if (IS_ERR(data))
		return PTR_ERR(data);

	mutex_lock(&data->update_lock);
	/* reverse logic: fan out of control reporting is enabled low */
	if (data->fan_sta & G762_REG_FAN_STA_OOC) {
		rpm = rpm_from_cnt(data->act_cnt, data->clk_freq,
				   G762_PULSE_FROM_REG(data->fan_cmd1),
				   G762_CLKDIV_FROM_REG(data->fan_cmd1),
				   G762_GEARMULT_FROM_REG(data->fan_cmd2));
	}
	mutex_unlock(&data->update_lock);

	return sprintf(buf, "%u\n", rpm);
}

__attribute__((used)) static ssize_t pwm1_mode_show(struct device *dev, struct device_attribute *da,
			      char *buf)
{
	struct g762_data *data = g762_update_client(dev);

	if (IS_ERR(data))
		return PTR_ERR(data);

	return sprintf(buf, "%d\n",
		       !!(data->fan_cmd1 & G762_REG_FAN_CMD1_OUT_MODE));
}

__attribute__((used)) static ssize_t pwm1_mode_store(struct device *dev,
			       struct device_attribute *da, const char *buf,
			       size_t count)
{
	unsigned long val;
	int ret;

	if (kstrtoul(buf, 10, &val))
		return -EINVAL;

	ret = do_set_pwm_mode(dev, val);
	if (ret < 0)
		return ret;

	return count;
}

__attribute__((used)) static ssize_t fan1_div_show(struct device *dev, struct device_attribute *da,
			     char *buf)
{
	struct g762_data *data = g762_update_client(dev);

	if (IS_ERR(data))
		return PTR_ERR(data);

	return sprintf(buf, "%d\n", G762_CLKDIV_FROM_REG(data->fan_cmd1));
}

__attribute__((used)) static ssize_t fan1_div_store(struct device *dev, struct device_attribute *da,
			      const char *buf, size_t count)
{
	unsigned long val;
	int ret;

	if (kstrtoul(buf, 10, &val))
		return -EINVAL;

	ret = do_set_fan_div(dev, val);
	if (ret < 0)
		return ret;

	return count;
}

__attribute__((used)) static ssize_t fan1_pulses_show(struct device *dev,
				struct device_attribute *da, char *buf)
{
	struct g762_data *data = g762_update_client(dev);

	if (IS_ERR(data))
		return PTR_ERR(data);

	return sprintf(buf, "%d\n", G762_PULSE_FROM_REG(data->fan_cmd1));
}

__attribute__((used)) static ssize_t fan1_pulses_store(struct device *dev,
				 struct device_attribute *da, const char *buf,
				 size_t count)
{
	unsigned long val;
	int ret;

	if (kstrtoul(buf, 10, &val))
		return -EINVAL;

	ret = do_set_fan_pulses(dev, val);
	if (ret < 0)
		return ret;

	return count;
}

__attribute__((used)) static ssize_t pwm1_enable_show(struct device *dev,
				struct device_attribute *da, char *buf)
{
	struct g762_data *data = g762_update_client(dev);

	if (IS_ERR(data))
		return PTR_ERR(data);

	return sprintf(buf, "%d\n",
		       (!!(data->fan_cmd1 & G762_REG_FAN_CMD1_FAN_MODE)) + 1);
}

__attribute__((used)) static ssize_t pwm1_enable_store(struct device *dev,
				 struct device_attribute *da, const char *buf,
				 size_t count)
{
	unsigned long val;
	int ret;

	if (kstrtoul(buf, 10, &val))
		return -EINVAL;

	ret = do_set_pwm_enable(dev, val);
	if (ret < 0)
		return ret;

	return count;
}

__attribute__((used)) static ssize_t pwm1_show(struct device *dev, struct device_attribute *da,
			 char *buf)
{
	struct g762_data *data = g762_update_client(dev);

	if (IS_ERR(data))
		return PTR_ERR(data);

	return sprintf(buf, "%d\n", data->set_out);
}

__attribute__((used)) static ssize_t pwm1_store(struct device *dev, struct device_attribute *da,
			  const char *buf, size_t count)
{
	unsigned long val;
	int ret;

	if (kstrtoul(buf, 10, &val))
		return -EINVAL;

	ret = do_set_pwm(dev, val);
	if (ret < 0)
		return ret;

	return count;
}

__attribute__((used)) static ssize_t fan1_target_show(struct device *dev,
				struct device_attribute *da, char *buf)
{
	struct g762_data *data = g762_update_client(dev);
	unsigned int rpm;

	if (IS_ERR(data))
		return PTR_ERR(data);

	mutex_lock(&data->update_lock);
	rpm = rpm_from_cnt(data->set_cnt, data->clk_freq,
			   G762_PULSE_FROM_REG(data->fan_cmd1),
			   G762_CLKDIV_FROM_REG(data->fan_cmd1),
			   G762_GEARMULT_FROM_REG(data->fan_cmd2));
	mutex_unlock(&data->update_lock);

	return sprintf(buf, "%u\n", rpm);
}

__attribute__((used)) static ssize_t fan1_target_store(struct device *dev,
				 struct device_attribute *da, const char *buf,
				 size_t count)
{
	unsigned long val;
	int ret;

	if (kstrtoul(buf, 10, &val))
		return -EINVAL;

	ret = do_set_fan_target(dev, val);
	if (ret < 0)
		return ret;

	return count;
}

__attribute__((used)) static ssize_t fan1_fault_show(struct device *dev, struct device_attribute *da,
			       char *buf)
{
	struct g762_data *data = g762_update_client(dev);

	if (IS_ERR(data))
		return PTR_ERR(data);

	return sprintf(buf, "%u\n", !!(data->fan_sta & G762_REG_FAN_STA_FAIL));
}

__attribute__((used)) static ssize_t fan1_alarm_show(struct device *dev,
			       struct device_attribute *da, char *buf)
{
	struct g762_data *data = g762_update_client(dev);

	if (IS_ERR(data))
		return PTR_ERR(data);

	return sprintf(buf, "%u\n", !(data->fan_sta & G762_REG_FAN_STA_OOC));
}

__attribute__((used)) static inline int g762_fan_init(struct device *dev)
{
	struct g762_data *data = g762_update_client(dev);

	if (IS_ERR(data))
		return PTR_ERR(data);

	data->fan_cmd1 |= G762_REG_FAN_CMD1_DET_FAN_FAIL;
	data->fan_cmd1 |= G762_REG_FAN_CMD1_DET_FAN_OOC;
	data->valid = false;

	return i2c_smbus_write_byte_data(data->client, G762_REG_FAN_CMD1,
					 data->fan_cmd1);
}

__attribute__((used)) static int g762_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	struct device *dev = &client->dev;
	struct device *hwmon_dev;
	struct g762_data *data;
	int ret;

	if (!i2c_check_functionality(client->adapter,
				     I2C_FUNC_SMBUS_BYTE_DATA))
		return -ENODEV;

	data = devm_kzalloc(dev, sizeof(struct g762_data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	i2c_set_clientdata(client, data);
	data->client = client;
	mutex_init(&data->update_lock);

	/* Enable fan failure detection and fan out of control protection */
	ret = g762_fan_init(dev);
	if (ret)
		return ret;

	/* Get configuration via DT ... */
	ret = g762_of_clock_enable(client);
	if (ret)
		return ret;
	ret = g762_of_prop_import(client);
	if (ret)
		return ret;
	/* ... or platform_data */
	ret = g762_pdata_prop_import(client);
	if (ret)
		return ret;

	hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
							    data, g762_groups);
	return PTR_ERR_OR_ZERO(hwmon_dev);
}

