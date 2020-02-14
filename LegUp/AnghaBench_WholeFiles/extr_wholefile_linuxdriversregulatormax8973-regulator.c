#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  scalar_t__ u32 ;
struct thermal_zone_device {int dummy; } ;
struct TYPE_5__ {int /*<<< orphan*/  boot_on; int /*<<< orphan*/  always_on; } ;
struct regulator_init_data {TYPE_1__ constraints; } ;
typedef  struct thermal_zone_device regulator_dev ;
struct regulator_config {struct thermal_zone_device* regmap; struct device_node* of_node; struct max8973_chip* driver_data; struct regulator_init_data* init_data; struct device* dev; struct thermal_zone_device* ena_gpiod; } ;
struct of_device_id {scalar_t__ data; } ;
struct max8973_regulator_platform_data {int control_flags; scalar_t__ junction_temp_warning; int enable_ext_control; int dvs_gpio; int dvs_def_state; struct regulator_init_data* reg_init_data; } ;
struct TYPE_6__ {int ramp_delay; int enable_time; size_t vsel_reg; unsigned int vsel_mask; int enable_reg; unsigned int enable_mask; int /*<<< orphan*/  n_voltages; int /*<<< orphan*/  uV_step; int /*<<< orphan*/  min_uV; int /*<<< orphan*/  owner; int /*<<< orphan*/  type; TYPE_3__* ops; scalar_t__ id; int /*<<< orphan*/  name; } ;
struct TYPE_7__ {int (* set_current_limit ) (struct thermal_zone_device*,int,int) ;int (* get_current_limit ) (struct thermal_zone_device*) ;void* is_enabled; void* disable; void* enable; int /*<<< orphan*/  get_voltage_sel; int /*<<< orphan*/  set_voltage_sel; } ;
struct max8973_chip {int* lru_index; int* curr_vout_val; int curr_vout_reg; int curr_gpio_val; int dvs_gpio; scalar_t__ id; int enable_external_control; int junction_temp_warning; struct device* dev; TYPE_2__ desc; struct thermal_zone_device* regmap; TYPE_3__ ops; int /*<<< orphan*/  irq; int /*<<< orphan*/  tz_device; } ;
struct irq_data {int dummy; } ;
struct i2c_device_id {scalar_t__ driver_data; int /*<<< orphan*/  name; } ;
struct device {struct device_node* of_node; } ;
struct i2c_client {struct device dev; } ;
typedef  struct thermal_zone_device gpio_desc ;
struct device_node {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  enum gpiod_flags { ____Placeholder_gpiod_flags } gpiod_flags ;

/* Variables and functions */
 int EINVAL ; 
 int EIO ; 
 int ENODATA ; 
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int GPIOD_OUT_HIGH ; 
 int GPIOD_OUT_LOW ; 
 int GPIOF_OUT_INIT_HIGH ; 
 int GPIOF_OUT_INIT_LOW ; 
 unsigned long IRQF_ONESHOT ; 
 unsigned long IRQF_SHARED ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (struct thermal_zone_device*) ; 
#define  MAX77621 146 
 unsigned int MAX77621_CHIPID_TJINT_S ; 
 int MAX77621_NORMAL_OPERATING_TEMP ; 
 scalar_t__ MAX77621_TJINT_WARNING_TEMP_120 ; 
 scalar_t__ MAX77621_TJINT_WARNING_TEMP_140 ; 
 int MAX77621_T_JUNCTION_120 ; 
#define  MAX8973 145 
 int MAX8973_AD_ENABLE ; 
 int MAX8973_BIAS_ENABLE ; 
 int /*<<< orphan*/  MAX8973_BUCK_N_VOLTAGE ; 
 int MAX8973_CHIPID1 ; 
#define  MAX8973_CKKADV_TRIP_150mV_PER_US 144 
#define  MAX8973_CKKADV_TRIP_75mV_PER_US 143 
 int MAX8973_CKKADV_TRIP_75mV_PER_US_HIST_DIS ; 
#define  MAX8973_CKKADV_TRIP_DISABLE 142 
 unsigned int MAX8973_CKKADV_TRIP_MASK ; 
 int MAX8973_CONTROL1 ; 
 int MAX8973_CONTROL2 ; 
 int MAX8973_CONTROL_BIAS_ENABLE ; 
#define  MAX8973_CONTROL_CLKADV_TRIP_150mV_PER_US 141 
#define  MAX8973_CONTROL_CLKADV_TRIP_75mV_PER_US 140 
#define  MAX8973_CONTROL_CLKADV_TRIP_75mV_PER_US_HIST_DIS 139 
#define  MAX8973_CONTROL_CLKADV_TRIP_DISABLED 138 
 int MAX8973_CONTROL_CLKADV_TRIP_MASK ; 
 int MAX8973_CONTROL_FALLING_SLEW_RATE_ENABLE ; 
 int MAX8973_CONTROL_FREQ_SHIFT_9PER_ENABLE ; 
 int MAX8973_CONTROL_INDUCTOR_VALUE_MASK ; 
#define  MAX8973_CONTROL_INDUCTOR_VALUE_MINUS_30_PER 137 
#define  MAX8973_CONTROL_INDUCTOR_VALUE_NOMINAL 136 
#define  MAX8973_CONTROL_INDUCTOR_VALUE_PLUS_30_PER 135 
#define  MAX8973_CONTROL_INDUCTOR_VALUE_PLUS_60_PER 134 
 int MAX8973_CONTROL_OUTPUT_ACTIVE_DISCH_ENABLE ; 
 int MAX8973_CONTROL_PULL_DOWN_ENABLE ; 
 int MAX8973_CONTROL_REMOTE_SENSE_ENABLE ; 
 int MAX8973_DISCH_ENBABLE ; 
 unsigned int MAX8973_FPWM_EN_M ; 
 int MAX8973_FREQSHIFT_9PER ; 
 int MAX8973_INDUCTOR_MIN_30_PER ; 
 int MAX8973_INDUCTOR_NOMINAL ; 
 int MAX8973_INDUCTOR_PLUS_30_PER ; 
 int MAX8973_INDUCTOR_PLUS_60_PER ; 
 int MAX8973_MAX_VOUT_REG ; 
 int /*<<< orphan*/  MAX8973_MIN_VOLATGE ; 
 int MAX8973_NFSR_ENABLE ; 
#define  MAX8973_RAMP_12mV_PER_US 133 
#define  MAX8973_RAMP_200mV_PER_US 132 
#define  MAX8973_RAMP_25mV_PER_US 131 
#define  MAX8973_RAMP_50mV_PER_US 130 
 unsigned int MAX8973_RAMP_MASK ; 
 int MAX8973_SNS_ENABLE ; 
 int /*<<< orphan*/  MAX8973_VOLATGE_STEP ; 
 int MAX8973_VOUT ; 
 unsigned int MAX8973_VOUT_ENABLE ; 
 unsigned int MAX8973_VOUT_MASK ; 
 int PTR_ERR (struct thermal_zone_device*) ; 
#define  REGULATOR_MODE_FAST 129 
#define  REGULATOR_MODE_NORMAL 128 
 int /*<<< orphan*/  REGULATOR_VOLTAGE ; 
 int /*<<< orphan*/  THERMAL_EVENT_UNSPECIFIED ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct max8973_regulator_platform_data* dev_get_platdata (struct device*) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  dev_name (struct device*) ; 
 int devm_gpio_request_one (struct device*,int,int,char*) ; 
 struct thermal_zone_device* devm_gpiod_get_optional (struct device*,char*,int) ; 
 void* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 struct thermal_zone_device* devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 struct thermal_zone_device* devm_regulator_register (struct device*,TYPE_2__*,struct regulator_config*) ; 
 int devm_request_threaded_irq (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),unsigned long,int /*<<< orphan*/ ,struct max8973_chip*) ; 
 struct thermal_zone_device* devm_thermal_zone_of_sensor_register (struct device*,int /*<<< orphan*/ ,struct max8973_chip*,int /*<<< orphan*/ *) ; 
 scalar_t__ gpio_is_valid (int) ; 
 int /*<<< orphan*/  gpio_set_value_cansleep (int,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct max8973_chip*) ; 
 struct irq_data* irq_get_irq_data (int /*<<< orphan*/ ) ; 
 unsigned long irqd_get_trigger_type (struct irq_data*) ; 
 int /*<<< orphan*/  max77621_tz_ops ; 
 TYPE_3__ max8973_dcdc_ops ; 
 int /*<<< orphan*/  max8973_regmap_config ; 
 int of_get_named_gpio (struct device_node*,char*,int /*<<< orphan*/ ) ; 
 struct regulator_init_data* of_get_regulator_init_data (struct device*,struct device_node*,TYPE_2__*) ; 
 struct of_device_id* of_match_device (int /*<<< orphan*/ ,struct device*) ; 
 int /*<<< orphan*/  of_match_ptr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  of_max8973_match_tbl ; 
 int of_property_read_bool (struct device_node*,char*) ; 
 int of_property_read_u32 (struct device_node*,char*,scalar_t__*) ; 
 struct max8973_chip* rdev_get_drvdata (struct thermal_zone_device*) ; 
 int regmap_read (struct thermal_zone_device*,int,unsigned int*) ; 
 int regmap_update_bits (struct thermal_zone_device*,int,unsigned int,unsigned int) ; 
 int regmap_write (struct thermal_zone_device*,int,int) ; 
 void* regulator_disable_regmap ; 
 void* regulator_enable_regmap ; 
 int /*<<< orphan*/  regulator_get_voltage_sel_regmap ; 
 void* regulator_is_enabled_regmap ; 
 int /*<<< orphan*/  regulator_set_voltage_sel_regmap ; 
 int /*<<< orphan*/  thermal_zone_device_update (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static bool find_voltage_set_register(struct max8973_chip *tps,
		int req_vsel, int *vout_reg, int *gpio_val)
{
	int i;
	bool found = false;
	int new_vout_reg = tps->lru_index[MAX8973_MAX_VOUT_REG - 1];
	int found_index = MAX8973_MAX_VOUT_REG - 1;

	for (i = 0; i < MAX8973_MAX_VOUT_REG; ++i) {
		if (tps->curr_vout_val[tps->lru_index[i]] == req_vsel) {
			new_vout_reg = tps->lru_index[i];
			found_index = i;
			found = true;
			goto update_lru_index;
		}
	}

update_lru_index:
	for (i = found_index; i > 0; i--)
		tps->lru_index[i] = tps->lru_index[i - 1];

	tps->lru_index[0] = new_vout_reg;
	*gpio_val = new_vout_reg;
	*vout_reg = MAX8973_VOUT + new_vout_reg;
	return found;
}

__attribute__((used)) static int max8973_dcdc_get_voltage_sel(struct regulator_dev *rdev)
{
	struct max8973_chip *max = rdev_get_drvdata(rdev);
	unsigned int data;
	int ret;

	ret = regmap_read(max->regmap, max->curr_vout_reg, &data);
	if (ret < 0) {
		dev_err(max->dev, "register %d read failed, err = %d\n",
			max->curr_vout_reg, ret);
		return ret;
	}
	return data & MAX8973_VOUT_MASK;
}

__attribute__((used)) static int max8973_dcdc_set_voltage_sel(struct regulator_dev *rdev,
	     unsigned vsel)
{
	struct max8973_chip *max = rdev_get_drvdata(rdev);
	int ret;
	bool found = false;
	int vout_reg = max->curr_vout_reg;
	int gpio_val = max->curr_gpio_val;

	/*
	 * If gpios are available to select the VOUT register then least
	 * recently used register for new configuration.
	 */
	if (gpio_is_valid(max->dvs_gpio))
		found = find_voltage_set_register(max, vsel,
					&vout_reg, &gpio_val);

	if (!found) {
		ret = regmap_update_bits(max->regmap, vout_reg,
					MAX8973_VOUT_MASK, vsel);
		if (ret < 0) {
			dev_err(max->dev, "register %d update failed, err %d\n",
				 vout_reg, ret);
			return ret;
		}
		max->curr_vout_reg = vout_reg;
		max->curr_vout_val[gpio_val] = vsel;
	}

	/* Select proper VOUT register vio gpios */
	if (gpio_is_valid(max->dvs_gpio)) {
		gpio_set_value_cansleep(max->dvs_gpio, gpio_val & 0x1);
		max->curr_gpio_val = gpio_val;
	}
	return 0;
}

__attribute__((used)) static int max8973_dcdc_set_mode(struct regulator_dev *rdev, unsigned int mode)
{
	struct max8973_chip *max = rdev_get_drvdata(rdev);
	int ret;
	int pwm;

	/* Enable force PWM mode in FAST mode only. */
	switch (mode) {
	case REGULATOR_MODE_FAST:
		pwm = MAX8973_FPWM_EN_M;
		break;

	case REGULATOR_MODE_NORMAL:
		pwm = 0;
		break;

	default:
		return -EINVAL;
	}

	ret = regmap_update_bits(max->regmap, MAX8973_CONTROL1,
				MAX8973_FPWM_EN_M, pwm);
	if (ret < 0)
		dev_err(max->dev, "register %d update failed, err %d\n",
				MAX8973_CONTROL1, ret);
	return ret;
}

__attribute__((used)) static unsigned int max8973_dcdc_get_mode(struct regulator_dev *rdev)
{
	struct max8973_chip *max = rdev_get_drvdata(rdev);
	unsigned int data;
	int ret;

	ret = regmap_read(max->regmap, MAX8973_CONTROL1, &data);
	if (ret < 0) {
		dev_err(max->dev, "register %d read failed, err %d\n",
				MAX8973_CONTROL1, ret);
		return ret;
	}
	return (data & MAX8973_FPWM_EN_M) ?
		REGULATOR_MODE_FAST : REGULATOR_MODE_NORMAL;
}

__attribute__((used)) static int max8973_set_ramp_delay(struct regulator_dev *rdev,
		int ramp_delay)
{
	struct max8973_chip *max = rdev_get_drvdata(rdev);
	unsigned int control;
	int ret;

	/* Set ramp delay */
	if (ramp_delay <= 12000)
		control = MAX8973_RAMP_12mV_PER_US;
	else if (ramp_delay <= 25000)
		control = MAX8973_RAMP_25mV_PER_US;
	else if (ramp_delay <= 50000)
		control = MAX8973_RAMP_50mV_PER_US;
	else if (ramp_delay <= 200000)
		control = MAX8973_RAMP_200mV_PER_US;
	else
		return -EINVAL;

	ret = regmap_update_bits(max->regmap, MAX8973_CONTROL1,
			MAX8973_RAMP_MASK, control);
	if (ret < 0)
		dev_err(max->dev, "register %d update failed, %d",
				MAX8973_CONTROL1, ret);
	return ret;
}

__attribute__((used)) static int max8973_set_current_limit(struct regulator_dev *rdev,
		int min_ua, int max_ua)
{
	struct max8973_chip *max = rdev_get_drvdata(rdev);
	unsigned int val;
	int ret;

	if (max_ua <= 9000000)
		val = MAX8973_CKKADV_TRIP_75mV_PER_US;
	else if (max_ua <= 12000000)
		val = MAX8973_CKKADV_TRIP_150mV_PER_US;
	else
		val = MAX8973_CKKADV_TRIP_DISABLE;

	ret = regmap_update_bits(max->regmap, MAX8973_CONTROL2,
			MAX8973_CKKADV_TRIP_MASK, val);
	if (ret < 0) {
		dev_err(max->dev, "register %d update failed: %d\n",
				MAX8973_CONTROL2, ret);
		return ret;
	}
	return 0;
}

__attribute__((used)) static int max8973_get_current_limit(struct regulator_dev *rdev)
{
	struct max8973_chip *max = rdev_get_drvdata(rdev);
	unsigned int control2;
	int ret;

	ret = regmap_read(max->regmap, MAX8973_CONTROL2, &control2);
	if (ret < 0) {
		dev_err(max->dev, "register %d read failed: %d\n",
				MAX8973_CONTROL2, ret);
		return ret;
	}
	switch (control2 & MAX8973_CKKADV_TRIP_MASK) {
	case MAX8973_CKKADV_TRIP_DISABLE:
		return 15000000;
	case MAX8973_CKKADV_TRIP_150mV_PER_US:
		return 12000000;
	case MAX8973_CKKADV_TRIP_75mV_PER_US:
		return 9000000;
	default:
		break;
	}
	return 9000000;
}

__attribute__((used)) static int max8973_init_dcdc(struct max8973_chip *max,
			     struct max8973_regulator_platform_data *pdata)
{
	int ret;
	uint8_t	control1 = 0;
	uint8_t control2 = 0;
	unsigned int data;

	ret = regmap_read(max->regmap, MAX8973_CONTROL1, &data);
	if (ret < 0) {
		dev_err(max->dev, "register %d read failed, err = %d",
				MAX8973_CONTROL1, ret);
		return ret;
	}
	control1 = data & MAX8973_RAMP_MASK;
	switch (control1) {
	case MAX8973_RAMP_12mV_PER_US:
		max->desc.ramp_delay = 12000;
		break;
	case MAX8973_RAMP_25mV_PER_US:
		max->desc.ramp_delay = 25000;
		break;
	case MAX8973_RAMP_50mV_PER_US:
		max->desc.ramp_delay = 50000;
		break;
	case MAX8973_RAMP_200mV_PER_US:
		max->desc.ramp_delay = 200000;
		break;
	}

	if (pdata->control_flags & MAX8973_CONTROL_REMOTE_SENSE_ENABLE)
		control1 |= MAX8973_SNS_ENABLE;

	if (!(pdata->control_flags & MAX8973_CONTROL_FALLING_SLEW_RATE_ENABLE))
		control1 |= MAX8973_NFSR_ENABLE;

	if (pdata->control_flags & MAX8973_CONTROL_OUTPUT_ACTIVE_DISCH_ENABLE)
		control1 |= MAX8973_AD_ENABLE;

	if (pdata->control_flags & MAX8973_CONTROL_BIAS_ENABLE) {
		control1 |= MAX8973_BIAS_ENABLE;
		max->desc.enable_time = 20;
	} else {
		max->desc.enable_time = 240;
	}

	if (pdata->control_flags & MAX8973_CONTROL_FREQ_SHIFT_9PER_ENABLE)
		control1 |= MAX8973_FREQSHIFT_9PER;

	if ((pdata->junction_temp_warning == MAX77621_TJINT_WARNING_TEMP_120) &&
	    (max->id == MAX77621))
		control2 |= MAX77621_T_JUNCTION_120;

	if (!(pdata->control_flags & MAX8973_CONTROL_PULL_DOWN_ENABLE))
		control2 |= MAX8973_DISCH_ENBABLE;

	/*  Clock advance trip configuration */
	switch (pdata->control_flags & MAX8973_CONTROL_CLKADV_TRIP_MASK) {
	case MAX8973_CONTROL_CLKADV_TRIP_DISABLED:
		control2 |= MAX8973_CKKADV_TRIP_DISABLE;
		break;

	case MAX8973_CONTROL_CLKADV_TRIP_75mV_PER_US:
		control2 |= MAX8973_CKKADV_TRIP_75mV_PER_US;
		break;

	case MAX8973_CONTROL_CLKADV_TRIP_150mV_PER_US:
		control2 |= MAX8973_CKKADV_TRIP_150mV_PER_US;
		break;

	case MAX8973_CONTROL_CLKADV_TRIP_75mV_PER_US_HIST_DIS:
		control2 |= MAX8973_CKKADV_TRIP_75mV_PER_US_HIST_DIS;
		break;
	}

	/* Configure inductor value */
	switch (pdata->control_flags & MAX8973_CONTROL_INDUCTOR_VALUE_MASK) {
	case MAX8973_CONTROL_INDUCTOR_VALUE_NOMINAL:
		control2 |= MAX8973_INDUCTOR_NOMINAL;
		break;

	case MAX8973_CONTROL_INDUCTOR_VALUE_MINUS_30_PER:
		control2 |= MAX8973_INDUCTOR_MIN_30_PER;
		break;

	case MAX8973_CONTROL_INDUCTOR_VALUE_PLUS_30_PER:
		control2 |= MAX8973_INDUCTOR_PLUS_30_PER;
		break;

	case MAX8973_CONTROL_INDUCTOR_VALUE_PLUS_60_PER:
		control2 |= MAX8973_INDUCTOR_PLUS_60_PER;
		break;
	}

	ret = regmap_write(max->regmap, MAX8973_CONTROL1, control1);
	if (ret < 0) {
		dev_err(max->dev, "register %d write failed, err = %d",
				MAX8973_CONTROL1, ret);
		return ret;
	}

	ret = regmap_write(max->regmap, MAX8973_CONTROL2, control2);
	if (ret < 0) {
		dev_err(max->dev, "register %d write failed, err = %d",
				MAX8973_CONTROL2, ret);
		return ret;
	}

	/* If external control is enabled then disable EN bit */
	if (max->enable_external_control && (max->id == MAX8973)) {
		ret = regmap_update_bits(max->regmap, MAX8973_VOUT,
						MAX8973_VOUT_ENABLE, 0);
		if (ret < 0)
			dev_err(max->dev, "register %d update failed, err = %d",
				MAX8973_VOUT, ret);
	}
	return ret;
}

__attribute__((used)) static int max8973_thermal_read_temp(void *data, int *temp)
{
	struct max8973_chip *mchip = data;
	unsigned int val;
	int ret;

	ret = regmap_read(mchip->regmap, MAX8973_CHIPID1, &val);
	if (ret < 0) {
		dev_err(mchip->dev, "Failed to read register CHIPID1, %d", ret);
		return ret;
	}

	/* +1 degC to trigger cool devive */
	if (val & MAX77621_CHIPID_TJINT_S)
		*temp = mchip->junction_temp_warning + 1000;
	else
		*temp = MAX77621_NORMAL_OPERATING_TEMP;

	return 0;
}

__attribute__((used)) static irqreturn_t max8973_thermal_irq(int irq, void *data)
{
	struct max8973_chip *mchip = data;

	thermal_zone_device_update(mchip->tz_device,
				   THERMAL_EVENT_UNSPECIFIED);

	return IRQ_HANDLED;
}

__attribute__((used)) static int max8973_thermal_init(struct max8973_chip *mchip)
{
	struct thermal_zone_device *tzd;
	struct irq_data *irq_data;
	unsigned long irq_flags = 0;
	int ret;

	if (mchip->id != MAX77621)
		return 0;

	tzd = devm_thermal_zone_of_sensor_register(mchip->dev, 0, mchip,
						   &max77621_tz_ops);
	if (IS_ERR(tzd)) {
		ret = PTR_ERR(tzd);
		dev_err(mchip->dev, "Failed to register thermal sensor: %d\n",
			ret);
		return ret;
	}

	if (mchip->irq <= 0)
		return 0;

	irq_data = irq_get_irq_data(mchip->irq);
	if (irq_data)
		irq_flags = irqd_get_trigger_type(irq_data);

	ret = devm_request_threaded_irq(mchip->dev, mchip->irq, NULL,
					max8973_thermal_irq,
					IRQF_ONESHOT | IRQF_SHARED | irq_flags,
					dev_name(mchip->dev), mchip);
	if (ret < 0) {
		dev_err(mchip->dev, "Failed to request irq %d, %d\n",
			mchip->irq, ret);
		return ret;
	}

	return 0;
}

__attribute__((used)) static struct max8973_regulator_platform_data *max8973_parse_dt(
		struct device *dev)
{
	struct max8973_regulator_platform_data *pdata;
	struct device_node *np = dev->of_node;
	int ret;
	u32 pval;
	bool etr_enable;
	bool etr_sensitivity_high;

	pdata = devm_kzalloc(dev, sizeof(*pdata), GFP_KERNEL);
	if (!pdata)
		return NULL;

	pdata->enable_ext_control = of_property_read_bool(np,
						"maxim,externally-enable");
	pdata->dvs_gpio = of_get_named_gpio(np, "maxim,dvs-gpio", 0);

	ret = of_property_read_u32(np, "maxim,dvs-default-state", &pval);
	if (!ret)
		pdata->dvs_def_state = pval;

	if (of_property_read_bool(np, "maxim,enable-remote-sense"))
		pdata->control_flags  |= MAX8973_CONTROL_REMOTE_SENSE_ENABLE;

	if (of_property_read_bool(np, "maxim,enable-falling-slew-rate"))
		pdata->control_flags  |=
				MAX8973_CONTROL_FALLING_SLEW_RATE_ENABLE;

	if (of_property_read_bool(np, "maxim,enable-active-discharge"))
		pdata->control_flags  |=
				MAX8973_CONTROL_OUTPUT_ACTIVE_DISCH_ENABLE;

	if (of_property_read_bool(np, "maxim,enable-frequency-shift"))
		pdata->control_flags  |= MAX8973_CONTROL_FREQ_SHIFT_9PER_ENABLE;

	if (of_property_read_bool(np, "maxim,enable-bias-control"))
		pdata->control_flags  |= MAX8973_CONTROL_BIAS_ENABLE;

	etr_enable = of_property_read_bool(np, "maxim,enable-etr");
	etr_sensitivity_high = of_property_read_bool(np,
				"maxim,enable-high-etr-sensitivity");
	if (etr_sensitivity_high)
		etr_enable = true;

	if (etr_enable) {
		if (etr_sensitivity_high)
			pdata->control_flags |=
				MAX8973_CONTROL_CLKADV_TRIP_75mV_PER_US;
		else
			pdata->control_flags |=
				MAX8973_CONTROL_CLKADV_TRIP_150mV_PER_US;
	} else {
		pdata->control_flags |= MAX8973_CONTROL_CLKADV_TRIP_DISABLED;
	}

	pdata->junction_temp_warning = MAX77621_TJINT_WARNING_TEMP_140;
	ret = of_property_read_u32(np, "junction-warn-millicelsius", &pval);
	if (!ret && (pval <= MAX77621_TJINT_WARNING_TEMP_120))
		pdata->junction_temp_warning = MAX77621_TJINT_WARNING_TEMP_120;

	return pdata;
}

__attribute__((used)) static int max8973_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	struct max8973_regulator_platform_data *pdata;
	struct regulator_init_data *ridata;
	struct regulator_config config = { };
	struct regulator_dev *rdev;
	struct max8973_chip *max;
	bool pdata_from_dt = false;
	unsigned int chip_id;
	struct gpio_desc *gpiod;
	enum gpiod_flags gflags;
	int ret;

	pdata = dev_get_platdata(&client->dev);

	if (!pdata && client->dev.of_node) {
		pdata = max8973_parse_dt(&client->dev);
		pdata_from_dt = true;
	}

	if (!pdata) {
		dev_err(&client->dev, "No Platform data");
		return -EIO;
	}

	if (pdata->dvs_gpio == -EPROBE_DEFER)
		return -EPROBE_DEFER;

	max = devm_kzalloc(&client->dev, sizeof(*max), GFP_KERNEL);
	if (!max)
		return -ENOMEM;

	max->regmap = devm_regmap_init_i2c(client, &max8973_regmap_config);
	if (IS_ERR(max->regmap)) {
		ret = PTR_ERR(max->regmap);
		dev_err(&client->dev, "regmap init failed, err %d\n", ret);
		return ret;
	}

	if (client->dev.of_node) {
		const struct of_device_id *match;

		match = of_match_device(of_match_ptr(of_max8973_match_tbl),
				&client->dev);
		if (!match)
			return -ENODATA;
		max->id = (u32)((uintptr_t)match->data);
	} else {
		max->id = id->driver_data;
	}

	ret = regmap_read(max->regmap, MAX8973_CHIPID1, &chip_id);
	if (ret < 0) {
		dev_err(&client->dev, "register CHIPID1 read failed, %d", ret);
		return ret;
	}

	dev_info(&client->dev, "CHIP-ID OTP: 0x%02x ID_M: 0x%02x\n",
			(chip_id >> 4) & 0xF, (chip_id >> 1) & 0x7);

	i2c_set_clientdata(client, max);
	max->ops = max8973_dcdc_ops;
	max->dev = &client->dev;
	max->desc.name = id->name;
	max->desc.id = 0;
	max->desc.ops = &max->ops;
	max->desc.type = REGULATOR_VOLTAGE;
	max->desc.owner = THIS_MODULE;
	max->desc.min_uV = MAX8973_MIN_VOLATGE;
	max->desc.uV_step = MAX8973_VOLATGE_STEP;
	max->desc.n_voltages = MAX8973_BUCK_N_VOLTAGE;

	max->dvs_gpio = (pdata->dvs_gpio) ? pdata->dvs_gpio : -EINVAL;
	max->enable_external_control = pdata->enable_ext_control;
	max->curr_gpio_val = pdata->dvs_def_state;
	max->curr_vout_reg = MAX8973_VOUT + pdata->dvs_def_state;
	max->junction_temp_warning = pdata->junction_temp_warning;

	max->lru_index[0] = max->curr_vout_reg;

	if (gpio_is_valid(max->dvs_gpio)) {
		int gpio_flags;
		int i;

		gpio_flags = (pdata->dvs_def_state) ?
				GPIOF_OUT_INIT_HIGH : GPIOF_OUT_INIT_LOW;
		ret = devm_gpio_request_one(&client->dev, max->dvs_gpio,
				gpio_flags, "max8973-dvs");
		if (ret) {
			dev_err(&client->dev,
				"gpio_request for gpio %d failed, err = %d\n",
				max->dvs_gpio, ret);
			return ret;
		}

		/*
		 * Initialize the lru index with vout_reg id
		 * The index 0 will be most recently used and
		 * set with the max->curr_vout_reg */
		for (i = 0; i < MAX8973_MAX_VOUT_REG; ++i)
			max->lru_index[i] = i;
		max->lru_index[0] = max->curr_vout_reg;
		max->lru_index[max->curr_vout_reg] = 0;
	} else {
		/*
		 * If there is no DVS GPIO, the VOUT register
		 * address is fixed.
		 */
		max->ops.set_voltage_sel = regulator_set_voltage_sel_regmap;
		max->ops.get_voltage_sel = regulator_get_voltage_sel_regmap;
		max->desc.vsel_reg = max->curr_vout_reg;
		max->desc.vsel_mask = MAX8973_VOUT_MASK;
	}

	if (pdata_from_dt)
		pdata->reg_init_data = of_get_regulator_init_data(&client->dev,
					client->dev.of_node, &max->desc);

	ridata = pdata->reg_init_data;
	switch (max->id) {
	case MAX8973:
		if (!pdata->enable_ext_control) {
			max->desc.enable_reg = MAX8973_VOUT;
			max->desc.enable_mask = MAX8973_VOUT_ENABLE;
			max->ops.enable = regulator_enable_regmap;
			max->ops.disable = regulator_disable_regmap;
			max->ops.is_enabled = regulator_is_enabled_regmap;
			break;
		}

		if (ridata && (ridata->constraints.always_on ||
			       ridata->constraints.boot_on))
			gflags = GPIOD_OUT_HIGH;
		else
			gflags = GPIOD_OUT_LOW;
		gpiod = devm_gpiod_get_optional(&client->dev,
						"maxim,enable",
						gflags);
		if (IS_ERR(gpiod))
			return PTR_ERR(gpiod);
		if (gpiod) {
			config.ena_gpiod = gpiod;
			max->enable_external_control = true;
		}

		break;

	case MAX77621:
		/*
		 * We do not let the core switch this regulator on/off,
		 * we just leave it on.
		 */
		gpiod = devm_gpiod_get_optional(&client->dev,
						"maxim,enable",
						GPIOD_OUT_HIGH);
		if (IS_ERR(gpiod))
			return PTR_ERR(gpiod);
		if (gpiod)
			max->enable_external_control = true;

		max->desc.enable_reg = MAX8973_VOUT;
		max->desc.enable_mask = MAX8973_VOUT_ENABLE;
		max->ops.enable = regulator_enable_regmap;
		max->ops.disable = regulator_disable_regmap;
		max->ops.is_enabled = regulator_is_enabled_regmap;
		max->ops.set_current_limit = max8973_set_current_limit;
		max->ops.get_current_limit = max8973_get_current_limit;
		break;
	default:
		break;
	}

	ret = max8973_init_dcdc(max, pdata);
	if (ret < 0) {
		dev_err(max->dev, "Max8973 Init failed, err = %d\n", ret);
		return ret;
	}

	config.dev = &client->dev;
	config.init_data = pdata->reg_init_data;
	config.driver_data = max;
	config.of_node = client->dev.of_node;
	config.regmap = max->regmap;

	/* Register the regulators */
	rdev = devm_regulator_register(&client->dev, &max->desc, &config);
	if (IS_ERR(rdev)) {
		ret = PTR_ERR(rdev);
		dev_err(max->dev, "regulator register failed, err %d\n", ret);
		return ret;
	}

	max8973_thermal_init(max);
	return 0;
}

