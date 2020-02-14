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
union power_supply_propval {int intval; } ;
typedef  int u8 ;
struct power_supply_config {struct adp5061_state* drv_data; } ;
struct power_supply {int dummy; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;
struct adp5061_state {int /*<<< orphan*/  psy; int /*<<< orphan*/  regmap; struct i2c_client* client; } ;
typedef  enum power_supply_property { ____Placeholder_power_supply_property } power_supply_property ;

/* Variables and functions */
#define  ADP5061_CHG_COMPLETE 145 
 int /*<<< orphan*/  ADP5061_CHG_CURR ; 
 int ADP5061_CHG_CURR_ICHG_MODE (int) ; 
 unsigned int ADP5061_CHG_CURR_ICHG_MSK ; 
 int ADP5061_CHG_CURR_ITRK_DEAD_MODE (int) ; 
 unsigned int ADP5061_CHG_CURR_ITRK_DEAD_MSK ; 
#define  ADP5061_CHG_FAST_CC 144 
#define  ADP5061_CHG_FAST_CV 143 
#define  ADP5061_CHG_OFF 142 
 int /*<<< orphan*/  ADP5061_CHG_STATUS_1 ; 
 int ADP5061_CHG_STATUS_1_CHG_STATUS (int) ; 
 int ADP5061_CHG_STATUS_2_BAT_STATUS (int) ; 
#define  ADP5061_CHG_TIMER_EXP 141 
#define  ADP5061_CHG_TRICKLE 140 
 int ADP5061_ICHG_MAX ; 
 int /*<<< orphan*/  ADP5061_IEND ; 
 int ADP5061_IEND_IEND_MODE (int) ; 
 unsigned int ADP5061_IEND_IEND_MSK ; 
 int ADP5061_NO_BATTERY ; 
 int /*<<< orphan*/  ADP5061_TERM_SET ; 
 int ADP5061_TERM_SET_CHG_VLIM_MODE (int) ; 
 unsigned int ADP5061_TERM_SET_CHG_VLIM_MSK ; 
 int ADP5061_TERM_SET_VTRM_MODE (int) ; 
 unsigned int ADP5061_TERM_SET_VTRM_MSK ; 
 int /*<<< orphan*/  ADP5061_VINX_SET ; 
 int ADP5061_VINX_SET_ILIM_MODE (int) ; 
 unsigned int ADP5061_VINX_SET_ILIM_MSK ; 
 int /*<<< orphan*/  ADP5061_VOLTAGE_TH ; 
 int ADP5061_VOLTAGE_TH_VTRK_DEAD_MODE (int) ; 
 unsigned int ADP5061_VOLTAGE_TH_VTRK_DEAD_MSK ; 
 int ADP5061_VOLTAGE_TH_VWEAK_MODE (int) ; 
 unsigned int ADP5061_VOLTAGE_TH_VWEAK_MSK ; 
 int ARRAY_SIZE (int*) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int POWER_SUPPLY_CAPACITY_LEVEL_CRITICAL ; 
 int POWER_SUPPLY_CAPACITY_LEVEL_LOW ; 
 int POWER_SUPPLY_CAPACITY_LEVEL_NORMAL ; 
 int POWER_SUPPLY_CAPACITY_LEVEL_UNKNOWN ; 
#define  POWER_SUPPLY_PROP_CAPACITY_LEVEL 139 
#define  POWER_SUPPLY_PROP_CHARGE_TERM_CURRENT 138 
#define  POWER_SUPPLY_PROP_CHARGE_TYPE 137 
#define  POWER_SUPPLY_PROP_CONSTANT_CHARGE_CURRENT 136 
#define  POWER_SUPPLY_PROP_CONSTANT_CHARGE_VOLTAGE_MAX 135 
#define  POWER_SUPPLY_PROP_INPUT_CURRENT_LIMIT 134 
#define  POWER_SUPPLY_PROP_PRECHARGE_CURRENT 133 
#define  POWER_SUPPLY_PROP_PRESENT 132 
#define  POWER_SUPPLY_PROP_STATUS 131 
#define  POWER_SUPPLY_PROP_VOLTAGE_AVG 130 
#define  POWER_SUPPLY_PROP_VOLTAGE_MAX 129 
#define  POWER_SUPPLY_PROP_VOLTAGE_MIN 128 
 int POWER_SUPPLY_STATUS_CHARGING ; 
 int POWER_SUPPLY_STATUS_DISCHARGING ; 
 int POWER_SUPPLY_STATUS_FULL ; 
 int POWER_SUPPLY_STATUS_NOT_CHARGING ; 
 void* POWER_SUPPLY_STATUS_UNKNOWN ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int* adp5061_chg_type ; 
 int* adp5061_const_chg_vmax ; 
 int* adp5061_const_ichg ; 
 int /*<<< orphan*/  adp5061_desc ; 
 int* adp5061_iend ; 
 int* adp5061_in_current_lim ; 
 int* adp5061_prechg_current ; 
 int /*<<< orphan*/  adp5061_regmap_config ; 
 int* adp5061_vmax ; 
 int* adp5061_vmin ; 
 int* adp5061_vweak_th ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 struct adp5061_state* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_power_supply_register (int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct power_supply_config*) ; 
 int /*<<< orphan*/  devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct adp5061_state*) ; 
 struct adp5061_state* power_supply_get_drvdata (struct power_supply*) ; 
 int regmap_bulk_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*,int) ; 
 int regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int*) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int,int) ; 

__attribute__((used)) static int adp5061_get_array_index(const int *array, u8 size, int val)
{
	int i;

	for (i = 1; i < size; i++) {
		if (val < array[i])
			break;
	}

	return i-1;
}

__attribute__((used)) static int adp5061_get_status(struct adp5061_state *st,
			      u8 *status1, u8 *status2)
{
	u8 buf[2];
	int ret;

	/* CHG_STATUS1 and CHG_STATUS2 are adjacent regs */
	ret = regmap_bulk_read(st->regmap, ADP5061_CHG_STATUS_1,
			       &buf[0], 2);
	if (ret < 0)
		return ret;

	*status1 = buf[0];
	*status2 = buf[1];

	return ret;
}

__attribute__((used)) static int adp5061_get_input_current_limit(struct adp5061_state *st,
		union power_supply_propval *val)
{
	unsigned int regval;
	int mode, ret;

	ret = regmap_read(st->regmap, ADP5061_VINX_SET, &regval);
	if (ret < 0)
		return ret;

	mode = ADP5061_VINX_SET_ILIM_MODE(regval);
	val->intval = adp5061_in_current_lim[mode] * 1000;

	return ret;
}

__attribute__((used)) static int adp5061_set_input_current_limit(struct adp5061_state *st, int val)
{
	int index;

	/* Convert from uA to mA */
	val /= 1000;
	index = adp5061_get_array_index(adp5061_in_current_lim,
					ARRAY_SIZE(adp5061_in_current_lim),
					val);
	if (index < 0)
		return index;

	return regmap_update_bits(st->regmap, ADP5061_VINX_SET,
				  ADP5061_VINX_SET_ILIM_MSK,
				  ADP5061_VINX_SET_ILIM_MODE(index));
}

__attribute__((used)) static int adp5061_set_min_voltage(struct adp5061_state *st, int val)
{
	int index;

	/* Convert from uV to mV */
	val /= 1000;
	index = adp5061_get_array_index(adp5061_vmin,
					ARRAY_SIZE(adp5061_vmin),
					val);
	if (index < 0)
		return index;

	return regmap_update_bits(st->regmap, ADP5061_VOLTAGE_TH,
				  ADP5061_VOLTAGE_TH_VTRK_DEAD_MSK,
				  ADP5061_VOLTAGE_TH_VTRK_DEAD_MODE(index));
}

__attribute__((used)) static int adp5061_get_min_voltage(struct adp5061_state *st,
				   union power_supply_propval *val)
{
	unsigned int regval;
	int ret;

	ret = regmap_read(st->regmap, ADP5061_VOLTAGE_TH, &regval);
	if (ret < 0)
		return ret;

	regval = ((regval & ADP5061_VOLTAGE_TH_VTRK_DEAD_MSK) >> 3);
	val->intval = adp5061_vmin[regval] * 1000;

	return ret;
}

__attribute__((used)) static int adp5061_get_chg_volt_lim(struct adp5061_state *st,
				    union power_supply_propval *val)
{
	unsigned int regval;
	int mode, ret;

	ret = regmap_read(st->regmap, ADP5061_TERM_SET, &regval);
	if (ret < 0)
		return ret;

	mode = ADP5061_TERM_SET_CHG_VLIM_MODE(regval);
	val->intval = adp5061_const_chg_vmax[mode] * 1000;

	return ret;
}

__attribute__((used)) static int adp5061_get_max_voltage(struct adp5061_state *st,
				   union power_supply_propval *val)
{
	unsigned int regval;
	int ret;

	ret = regmap_read(st->regmap, ADP5061_TERM_SET, &regval);
	if (ret < 0)
		return ret;

	regval = ((regval & ADP5061_TERM_SET_VTRM_MSK) >> 2) - 0x0F;
	if (regval >= ARRAY_SIZE(adp5061_vmax))
		regval = ARRAY_SIZE(adp5061_vmax) - 1;

	val->intval = adp5061_vmax[regval] * 1000;

	return ret;
}

__attribute__((used)) static int adp5061_set_max_voltage(struct adp5061_state *st, int val)
{
	int vmax_index;

	/* Convert from uV to mV */
	val /= 1000;
	if (val > 4500)
		val = 4500;

	vmax_index = adp5061_get_array_index(adp5061_vmax,
					     ARRAY_SIZE(adp5061_vmax), val);
	if (vmax_index < 0)
		return vmax_index;

	vmax_index += 0x0F;

	return regmap_update_bits(st->regmap, ADP5061_TERM_SET,
				  ADP5061_TERM_SET_VTRM_MSK,
				  ADP5061_TERM_SET_VTRM_MODE(vmax_index));
}

__attribute__((used)) static int adp5061_set_const_chg_vmax(struct adp5061_state *st, int val)
{
	int index;

	/* Convert from uV to mV */
	val /= 1000;
	index = adp5061_get_array_index(adp5061_const_chg_vmax,
					ARRAY_SIZE(adp5061_const_chg_vmax),
					val);
	if (index < 0)
		return index;

	return regmap_update_bits(st->regmap, ADP5061_TERM_SET,
				  ADP5061_TERM_SET_CHG_VLIM_MSK,
				  ADP5061_TERM_SET_CHG_VLIM_MODE(index));
}

__attribute__((used)) static int adp5061_set_const_chg_current(struct adp5061_state *st, int val)
{

	int index;

	/* Convert from uA to mA */
	val /= 1000;
	if (val > ADP5061_ICHG_MAX)
		val = ADP5061_ICHG_MAX;

	index = adp5061_get_array_index(adp5061_const_ichg,
					ARRAY_SIZE(adp5061_const_ichg),
					val);
	if (index < 0)
		return index;

	return regmap_update_bits(st->regmap, ADP5061_CHG_CURR,
				  ADP5061_CHG_CURR_ICHG_MSK,
				  ADP5061_CHG_CURR_ICHG_MODE(index));
}

__attribute__((used)) static int adp5061_get_const_chg_current(struct adp5061_state *st,
		union power_supply_propval *val)
{
	unsigned int regval;
	int ret;

	ret = regmap_read(st->regmap, ADP5061_CHG_CURR, &regval);
	if (ret < 0)
		return ret;

	regval = ((regval & ADP5061_CHG_CURR_ICHG_MSK) >> 2);
	if (regval >= ARRAY_SIZE(adp5061_const_ichg))
		regval = ARRAY_SIZE(adp5061_const_ichg) - 1;

	val->intval = adp5061_const_ichg[regval] * 1000;

	return ret;
}

__attribute__((used)) static int adp5061_get_prechg_current(struct adp5061_state *st,
				      union power_supply_propval *val)
{
	unsigned int regval;
	int ret;

	ret = regmap_read(st->regmap, ADP5061_CHG_CURR, &regval);
	if (ret < 0)
		return ret;

	regval &= ADP5061_CHG_CURR_ITRK_DEAD_MSK;
	val->intval = adp5061_prechg_current[regval] * 1000;

	return ret;
}

__attribute__((used)) static int adp5061_set_prechg_current(struct adp5061_state *st, int val)
{
	int index;

	/* Convert from uA to mA */
	val /= 1000;
	index = adp5061_get_array_index(adp5061_prechg_current,
					ARRAY_SIZE(adp5061_prechg_current),
					val);
	if (index < 0)
		return index;

	return regmap_update_bits(st->regmap, ADP5061_CHG_CURR,
				  ADP5061_CHG_CURR_ITRK_DEAD_MSK,
				  ADP5061_CHG_CURR_ITRK_DEAD_MODE(index));
}

__attribute__((used)) static int adp5061_get_vweak_th(struct adp5061_state *st,
				union power_supply_propval *val)
{
	unsigned int regval;
	int ret;

	ret = regmap_read(st->regmap, ADP5061_VOLTAGE_TH, &regval);
	if (ret < 0)
		return ret;

	regval &= ADP5061_VOLTAGE_TH_VWEAK_MSK;
	val->intval = adp5061_vweak_th[regval] * 1000;

	return ret;
}

__attribute__((used)) static int adp5061_set_vweak_th(struct adp5061_state *st, int val)
{
	int index;

	/* Convert from uV to mV */
	val /= 1000;
	index = adp5061_get_array_index(adp5061_vweak_th,
					ARRAY_SIZE(adp5061_vweak_th),
					val);
	if (index < 0)
		return index;

	return regmap_update_bits(st->regmap, ADP5061_VOLTAGE_TH,
				  ADP5061_VOLTAGE_TH_VWEAK_MSK,
				  ADP5061_VOLTAGE_TH_VWEAK_MODE(index));
}

__attribute__((used)) static int adp5061_get_chg_type(struct adp5061_state *st,
				union power_supply_propval *val)
{
	u8 status1, status2;
	int chg_type, ret;

	ret = adp5061_get_status(st, &status1, &status2);
	if (ret < 0)
		return ret;

	chg_type = adp5061_chg_type[ADP5061_CHG_STATUS_1_CHG_STATUS(status1)];
	if (chg_type > ADP5061_CHG_FAST_CV)
		val->intval = POWER_SUPPLY_STATUS_UNKNOWN;
	else
		val->intval = chg_type;

	return ret;
}

__attribute__((used)) static int adp5061_get_charger_status(struct adp5061_state *st,
				      union power_supply_propval *val)
{
	u8 status1, status2;
	int ret;

	ret = adp5061_get_status(st, &status1, &status2);
	if (ret < 0)
		return ret;

	switch (ADP5061_CHG_STATUS_1_CHG_STATUS(status1)) {
	case ADP5061_CHG_OFF:
		val->intval = POWER_SUPPLY_STATUS_NOT_CHARGING;
		break;
	case ADP5061_CHG_TRICKLE:
	case ADP5061_CHG_FAST_CC:
	case ADP5061_CHG_FAST_CV:
		val->intval = POWER_SUPPLY_STATUS_CHARGING;
		break;
	case ADP5061_CHG_COMPLETE:
		val->intval = POWER_SUPPLY_STATUS_FULL;
		break;
	case ADP5061_CHG_TIMER_EXP:
		/* The battery must be discharging if there is a charge fault */
		val->intval = POWER_SUPPLY_STATUS_DISCHARGING;
		break;
	default:
		val->intval = POWER_SUPPLY_STATUS_UNKNOWN;
	}

	return ret;
}

__attribute__((used)) static int adp5061_get_battery_status(struct adp5061_state *st,
				      union power_supply_propval *val)
{
	u8 status1, status2;
	int ret;

	ret = adp5061_get_status(st, &status1, &status2);
	if (ret < 0)
		return ret;

	switch (ADP5061_CHG_STATUS_2_BAT_STATUS(status2)) {
	case 0x0: /* Battery monitor off */
	case 0x1: /* No battery */
		val->intval = POWER_SUPPLY_CAPACITY_LEVEL_UNKNOWN;
		break;
	case 0x2: /* VBAT < VTRK */
		val->intval = POWER_SUPPLY_CAPACITY_LEVEL_CRITICAL;
		break;
	case 0x3: /* VTRK < VBAT_SNS < VWEAK */
		val->intval = POWER_SUPPLY_CAPACITY_LEVEL_LOW;
		break;
	case 0x4: /* VBAT_SNS > VWEAK */
		val->intval = POWER_SUPPLY_CAPACITY_LEVEL_NORMAL;
		break;
	}

	return ret;
}

__attribute__((used)) static int adp5061_get_termination_current(struct adp5061_state *st,
					   union power_supply_propval *val)
{
	unsigned int regval;
	int ret;

	ret = regmap_read(st->regmap, ADP5061_IEND, &regval);
	if (ret < 0)
		return ret;

	regval = (regval & ADP5061_IEND_IEND_MSK) >> 5;
	val->intval = adp5061_iend[regval];

	return ret;
}

__attribute__((used)) static int adp5061_set_termination_current(struct adp5061_state *st, int val)
{
	int index;

	index = adp5061_get_array_index(adp5061_iend,
					ARRAY_SIZE(adp5061_iend),
					val);
	if (index < 0)
		return index;

	return regmap_update_bits(st->regmap, ADP5061_IEND,
				  ADP5061_IEND_IEND_MSK,
				  ADP5061_IEND_IEND_MODE(index));
}

__attribute__((used)) static int adp5061_get_property(struct power_supply *psy,
				enum power_supply_property psp,
				union power_supply_propval *val)
{
	struct adp5061_state *st = power_supply_get_drvdata(psy);
	u8 status1, status2;
	int mode, ret;

	switch (psp) {
	case POWER_SUPPLY_PROP_PRESENT:
		ret = adp5061_get_status(st, &status1, &status2);
		if (ret < 0)
			return ret;

		mode = ADP5061_CHG_STATUS_2_BAT_STATUS(status2);
		if (mode == ADP5061_NO_BATTERY)
			val->intval = 0;
		else
			val->intval = 1;
		break;
	case POWER_SUPPLY_PROP_CHARGE_TYPE:
		return adp5061_get_chg_type(st, val);
	case POWER_SUPPLY_PROP_INPUT_CURRENT_LIMIT:
		/* This property is used to indicate the input current
		 * limit into VINx (ILIM)
		 */
		return adp5061_get_input_current_limit(st, val);
	case POWER_SUPPLY_PROP_VOLTAGE_MAX:
		/* This property is used to indicate the termination
		 * voltage (VTRM)
		 */
		return adp5061_get_max_voltage(st, val);
	case POWER_SUPPLY_PROP_VOLTAGE_MIN:
		/*
		 * This property is used to indicate the trickle to fast
		 * charge threshold (VTRK_DEAD)
		 */
		return adp5061_get_min_voltage(st, val);
	case POWER_SUPPLY_PROP_CONSTANT_CHARGE_VOLTAGE_MAX:
		/* This property is used to indicate the charging
		 * voltage limit (CHG_VLIM)
		 */
		return adp5061_get_chg_volt_lim(st, val);
	case POWER_SUPPLY_PROP_CONSTANT_CHARGE_CURRENT:
		/*
		 * This property is used to indicate the value of the constant
		 * current charge (ICHG)
		 */
		return adp5061_get_const_chg_current(st, val);
	case POWER_SUPPLY_PROP_PRECHARGE_CURRENT:
		/*
		 * This property is used to indicate the value of the trickle
		 * and weak charge currents (ITRK_DEAD)
		 */
		return adp5061_get_prechg_current(st, val);
	case POWER_SUPPLY_PROP_VOLTAGE_AVG:
		/*
		 * This property is used to set the VWEAK threshold
		 * bellow this value, weak charge mode is entered
		 * above this value, fast chargerge mode is entered
		 */
		return adp5061_get_vweak_th(st, val);
	case POWER_SUPPLY_PROP_STATUS:
		/*
		 * Indicate the charger status in relation to power
		 * supply status property
		 */
		return adp5061_get_charger_status(st, val);
	case POWER_SUPPLY_PROP_CAPACITY_LEVEL:
		/*
		 * Indicate the battery status in relation to power
		 * supply capacity level property
		 */
		return adp5061_get_battery_status(st, val);
	case POWER_SUPPLY_PROP_CHARGE_TERM_CURRENT:
		/* Indicate the values of the termination current */
		return adp5061_get_termination_current(st, val);
	default:
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int adp5061_set_property(struct power_supply *psy,
				enum power_supply_property psp,
				const union power_supply_propval *val)
{
	struct adp5061_state *st = power_supply_get_drvdata(psy);

	switch (psp) {
	case POWER_SUPPLY_PROP_INPUT_CURRENT_LIMIT:
		return adp5061_set_input_current_limit(st, val->intval);
	case POWER_SUPPLY_PROP_VOLTAGE_MAX:
		return adp5061_set_max_voltage(st, val->intval);
	case POWER_SUPPLY_PROP_VOLTAGE_MIN:
		return adp5061_set_min_voltage(st, val->intval);
	case POWER_SUPPLY_PROP_CONSTANT_CHARGE_VOLTAGE_MAX:
		return adp5061_set_const_chg_vmax(st, val->intval);
	case POWER_SUPPLY_PROP_CONSTANT_CHARGE_CURRENT:
		return adp5061_set_const_chg_current(st, val->intval);
	case POWER_SUPPLY_PROP_PRECHARGE_CURRENT:
		return adp5061_set_prechg_current(st, val->intval);
	case POWER_SUPPLY_PROP_VOLTAGE_AVG:
		return adp5061_set_vweak_th(st, val->intval);
	case POWER_SUPPLY_PROP_CHARGE_TERM_CURRENT:
		return adp5061_set_termination_current(st, val->intval);
	default:
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int adp5061_prop_writeable(struct power_supply *psy,
				  enum power_supply_property psp)
{
	switch (psp) {
	case POWER_SUPPLY_PROP_INPUT_CURRENT_LIMIT:
	case POWER_SUPPLY_PROP_VOLTAGE_MAX:
	case POWER_SUPPLY_PROP_VOLTAGE_MIN:
	case POWER_SUPPLY_PROP_CONSTANT_CHARGE_VOLTAGE_MAX:
	case POWER_SUPPLY_PROP_CONSTANT_CHARGE_CURRENT:
	case POWER_SUPPLY_PROP_PRECHARGE_CURRENT:
	case POWER_SUPPLY_PROP_VOLTAGE_AVG:
	case POWER_SUPPLY_PROP_CHARGE_TERM_CURRENT:
		return 1;
	default:
		return 0;
	}
}

__attribute__((used)) static int adp5061_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	struct power_supply_config psy_cfg = {};
	struct adp5061_state *st;

	st = devm_kzalloc(&client->dev, sizeof(*st), GFP_KERNEL);
	if (!st)
		return -ENOMEM;

	st->client = client;
	st->regmap = devm_regmap_init_i2c(client,
					  &adp5061_regmap_config);
	if (IS_ERR(st->regmap)) {
		dev_err(&client->dev, "Failed to initialize register map\n");
		return -EINVAL;
	}

	i2c_set_clientdata(client, st);
	psy_cfg.drv_data = st;

	st->psy = devm_power_supply_register(&client->dev,
					     &adp5061_desc,
					     &psy_cfg);

	if (IS_ERR(st->psy)) {
		dev_err(&client->dev, "Failed to register power supply\n");
		return PTR_ERR(st->psy);
	}

	return 0;
}

