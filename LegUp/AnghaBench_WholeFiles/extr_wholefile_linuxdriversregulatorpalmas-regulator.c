#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned int u32 ;
struct regulator_dev {int dummy; } ;
struct regulator_desc {unsigned int enable_val; int id; int n_voltages; int min_uV; int uV_step; int linear_min_sel; int enable_time; unsigned int enable_mask; int ramp_delay; int n_linear_ranges; int /*<<< orphan*/  supply_name; void* owner; void* type; void* enable_reg; void* vsel_mask; void* vsel_reg; int /*<<< orphan*/ * ops; void* linear_ranges; int /*<<< orphan*/  name; void* bypass_mask; void* bypass_val_on; void* bypass_reg; } ;
struct regulator_config {struct palmas_pmic* driver_data; struct device* dev; int /*<<< orphan*/  regmap; struct device_node* of_node; int /*<<< orphan*/ * init_data; } ;
struct device {struct device_node* of_node; int /*<<< orphan*/  parent; } ;
struct platform_device {char* name; struct device dev; } ;
struct palmas_regs_info {unsigned int ctrl_addr; unsigned int tstep_addr; unsigned int vsel_addr; int /*<<< orphan*/  sname; int /*<<< orphan*/  name; int /*<<< orphan*/  sleep_id; } ;
struct palmas_reg_init {int roof_floor; unsigned int mode_sleep; unsigned int vsel; void* warm_reset; } ;
struct palmas_pmic_platform_data {void* ldo6_vibrator; void* enable_ldo8_tracking; struct palmas_reg_init** reg_init; int /*<<< orphan*/ ** reg_data; } ;
struct palmas_pmic_driver_data {int ldo_begin; int max_reg; int ldo_end; int smps_start; int smps_end; int (* smps_register ) (struct palmas_pmic*,struct palmas_pmic_driver_data*,struct palmas_pmic_platform_data*,char const*,struct regulator_config) ;int (* ldo_register ) (struct palmas_pmic*,struct palmas_pmic_driver_data*,struct palmas_pmic_platform_data*,char const*,struct regulator_config) ;struct of_regulator_match* palmas_matches; struct palmas_regs_info* palmas_regs_info; int /*<<< orphan*/  has_regen3; } ;
struct palmas_pmic {unsigned int* current_reg_mode; int* ramp_delay; int smps123; int smps457; int* range; int smps12; struct palmas* palmas; struct device* dev; struct regulator_dev** rdev; struct regulator_desc* desc; } ;
struct palmas {int /*<<< orphan*/ * regmap; struct palmas_pmic_driver_data* pmic_ddata; struct palmas_pmic* pmic; struct device* dev; } ;
struct of_regulator_match {int /*<<< orphan*/  name; int /*<<< orphan*/ * init_data; struct device_node* of_node; } ;
struct of_device_id {scalar_t__ data; } ;
struct device_node {int dummy; } ;
struct TYPE_4__ {int has_regen3; } ;
struct TYPE_3__ {int /*<<< orphan*/  ctrl_addr; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODATA ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct regulator_dev*) ; 
 void* PALMAS_BASE_TO_REG (int /*<<< orphan*/ ,unsigned int) ; 
 int PALMAS_EXT_CONTROL_ENABLE1 ; 
 int PALMAS_EXT_CONTROL_ENABLE2 ; 
 int PALMAS_EXT_CONTROL_NSLEEP ; 
 unsigned int PALMAS_LDO1_CTRL_MODE_ACTIVE ; 
 unsigned int PALMAS_LDO1_CTRL_MODE_SLEEP ; 
 unsigned int PALMAS_LDO1_CTRL_STATUS ; 
 unsigned int PALMAS_LDO1_CTRL_WR_S ; 
 void* PALMAS_LDO1_VOLTAGE_VSEL_MASK ; 
 unsigned int PALMAS_LDO8_CTRL_LDO_TRACKING_EN ; 
 unsigned int PALMAS_LDO8_VOLTAGE_VSEL_MASK ; 
 void* PALMAS_LDO9_CTRL_LDO_BYPASS_EN ; 
 int /*<<< orphan*/  PALMAS_LDO_BASE ; 
 void* PALMAS_LDO_NUM_VOLTAGES ; 
 int /*<<< orphan*/  PALMAS_PMIC_HAS (struct palmas*,int /*<<< orphan*/ ) ; 
 unsigned int PALMAS_REGEN1_CTRL_MODE_ACTIVE ; 
 unsigned int PALMAS_REGEN1_CTRL_MODE_SLEEP ; 
 int PALMAS_REG_LDO6 ; 
 size_t PALMAS_REG_LDO8 ; 
 int PALMAS_REG_LDO9 ; 
 int PALMAS_REG_REGEN1 ; 
 size_t PALMAS_REG_REGEN2 ; 
 int PALMAS_REG_REGEN3 ; 
#define  PALMAS_REG_SMPS10_OUT1 141 
#define  PALMAS_REG_SMPS10_OUT2 140 
#define  PALMAS_REG_SMPS12 139 
#define  PALMAS_REG_SMPS123 138 
#define  PALMAS_REG_SMPS3 137 
#define  PALMAS_REG_SMPS45 136 
#define  PALMAS_REG_SMPS457 135 
 int PALMAS_REG_SMPS6 ; 
#define  PALMAS_REG_SMPS7 134 
 int PALMAS_REG_SMPS8 ; 
 int /*<<< orphan*/  PALMAS_RESOURCE_BASE ; 
 unsigned int PALMAS_SMPS10_CTRL ; 
 unsigned int PALMAS_SMPS10_CTRL_MODE_SLEEP_MASK ; 
 unsigned int PALMAS_SMPS10_CTRL_MODE_SLEEP_SHIFT ; 
 int PALMAS_SMPS10_NUM_VOLTAGES ; 
 unsigned int PALMAS_SMPS12_CTRL_MODE_ACTIVE_MASK ; 
 unsigned int PALMAS_SMPS12_CTRL_MODE_SLEEP_MASK ; 
 unsigned int PALMAS_SMPS12_CTRL_MODE_SLEEP_SHIFT ; 
 unsigned int PALMAS_SMPS12_CTRL_ROOF_FLOOR_EN ; 
 unsigned int PALMAS_SMPS12_CTRL_WR_S ; 
 unsigned int PALMAS_SMPS12_VOLTAGE_RANGE ; 
 void* PALMAS_SMPS12_VOLTAGE_VSEL_MASK ; 
 int /*<<< orphan*/  PALMAS_SMPS_BASE ; 
 unsigned int PALMAS_SMPS_CTRL ; 
 unsigned int PALMAS_SMPS_CTRL_SMPS12_SMPS123_EN ; 
 unsigned int PALMAS_SMPS_CTRL_SMPS45_SMPS457_EN ; 
 void* PALMAS_SMPS_NUM_VOLTAGES ; 
 int PTR_ERR (struct regulator_dev*) ; 
#define  REGULATOR_MODE_FAST 133 
#define  REGULATOR_MODE_IDLE 132 
#define  REGULATOR_MODE_NORMAL 131 
 size_t REGULATOR_SLAVE ; 
 void* REGULATOR_VOLTAGE ; 
 int /*<<< orphan*/  SMPS10_BOOST ; 
 unsigned int SMPS10_BOOST_EN ; 
 void* SMPS10_BYPASS_EN ; 
 unsigned int SMPS10_SWITCH_EN ; 
 void* SMPS10_VSEL ; 
#define  SMPS_CTRL_MODE_ECO 130 
 unsigned int SMPS_CTRL_MODE_OFF ; 
#define  SMPS_CTRL_MODE_ON 129 
#define  SMPS_CTRL_MODE_PWM 128 
 void* THIS_MODULE ; 
 int /*<<< orphan*/  TPS659038_REGEN2_CTRL ; 
 void* TPS65917_LDO1_CTRL_BYPASS_EN ; 
 int TPS65917_REG_LDO1 ; 
 int TPS65917_REG_LDO2 ; 
 int TPS65917_REG_REGEN1 ; 
 int TPS65917_REG_SMPS1 ; 
 int TPS65917_REG_SMPS2 ; 
 unsigned int TPS65917_SMPS1_VOLTAGE_RANGE ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct palmas* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 struct palmas_pmic_platform_data* dev_get_platdata (struct device*) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*,int /*<<< orphan*/ ,unsigned int) ; 
 void* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 struct regulator_dev* devm_regulator_register (struct device*,struct regulator_desc*,struct regulator_config*) ; 
 scalar_t__ of_device_is_compatible (struct device_node*,char*) ; 
 struct device_node* of_get_child_by_name (struct device_node*,char*) ; 
 struct of_device_id* of_match_device (int /*<<< orphan*/ ,struct device*) ; 
 int /*<<< orphan*/  of_match_ptr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 int /*<<< orphan*/  of_palmas_match_tbl ; 
 void* of_property_read_bool (struct device_node*,char*) ; 
 int of_property_read_u32 (struct device_node*,char*,unsigned int*) ; 
 int of_regulator_match (struct device*,struct device_node*,struct of_regulator_match*,int) ; 
 TYPE_2__ palmas_ddata ; 
 int palmas_ext_control_req_config (struct palmas*,int /*<<< orphan*/ ,int,int) ; 
 TYPE_1__* palmas_generic_regs_info ; 
 int /*<<< orphan*/  palmas_ops_ext_control_extreg ; 
 int /*<<< orphan*/  palmas_ops_ext_control_ldo ; 
 int /*<<< orphan*/  palmas_ops_ext_control_smps ; 
 int /*<<< orphan*/  palmas_ops_extreg ; 
 int /*<<< orphan*/  palmas_ops_ldo ; 
 int /*<<< orphan*/  palmas_ops_ldo9 ; 
 int /*<<< orphan*/  palmas_ops_smps ; 
 int /*<<< orphan*/  palmas_ops_smps10 ; 
 void** palmas_smps_ramp_delay ; 
 int palmas_update_bits (struct palmas*,int /*<<< orphan*/ ,unsigned int,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct palmas_pmic*) ; 
 struct palmas_pmic* rdev_get_drvdata (struct regulator_dev*) ; 
 int rdev_get_id (struct regulator_dev*) ; 
 int regmap_read (int /*<<< orphan*/ ,unsigned int,unsigned int*) ; 
 int regmap_write (int /*<<< orphan*/ ,unsigned int,unsigned int) ; 
 void* smps_high_ranges ; 
 void* smps_low_ranges ; 
 int stub1 (struct palmas_pmic*,struct palmas_pmic_driver_data*,struct palmas_pmic_platform_data*,char const*,struct regulator_config) ; 
 int stub2 (struct palmas_pmic*,struct palmas_pmic_driver_data*,struct palmas_pmic_platform_data*,char const*,struct regulator_config) ; 
 int /*<<< orphan*/  tps65917_ops_ext_control_smps ; 
 int /*<<< orphan*/  tps65917_ops_ldo ; 
 int /*<<< orphan*/  tps65917_ops_ldo_1_2 ; 
 int /*<<< orphan*/  tps65917_ops_smps ; 

__attribute__((used)) static int palmas_smps_read(struct palmas *palmas, unsigned int reg,
		unsigned int *dest)
{
	unsigned int addr;

	addr = PALMAS_BASE_TO_REG(PALMAS_SMPS_BASE, reg);

	return regmap_read(palmas->regmap[REGULATOR_SLAVE], addr, dest);
}

__attribute__((used)) static int palmas_smps_write(struct palmas *palmas, unsigned int reg,
		unsigned int value)
{
	unsigned int addr;

	addr = PALMAS_BASE_TO_REG(PALMAS_SMPS_BASE, reg);

	return regmap_write(palmas->regmap[REGULATOR_SLAVE], addr, value);
}

__attribute__((used)) static int palmas_ldo_read(struct palmas *palmas, unsigned int reg,
		unsigned int *dest)
{
	unsigned int addr;

	addr = PALMAS_BASE_TO_REG(PALMAS_LDO_BASE, reg);

	return regmap_read(palmas->regmap[REGULATOR_SLAVE], addr, dest);
}

__attribute__((used)) static int palmas_ldo_write(struct palmas *palmas, unsigned int reg,
		unsigned int value)
{
	unsigned int addr;

	addr = PALMAS_BASE_TO_REG(PALMAS_LDO_BASE, reg);

	return regmap_write(palmas->regmap[REGULATOR_SLAVE], addr, value);
}

__attribute__((used)) static int palmas_set_mode_smps(struct regulator_dev *dev, unsigned int mode)
{
	int id = rdev_get_id(dev);
	struct palmas_pmic *pmic = rdev_get_drvdata(dev);
	struct palmas_pmic_driver_data *ddata = pmic->palmas->pmic_ddata;
	struct palmas_regs_info *rinfo = &ddata->palmas_regs_info[id];
	unsigned int reg;
	bool rail_enable = true;

	palmas_smps_read(pmic->palmas, rinfo->ctrl_addr, &reg);

	reg &= ~PALMAS_SMPS12_CTRL_MODE_ACTIVE_MASK;

	if (reg == SMPS_CTRL_MODE_OFF)
		rail_enable = false;

	switch (mode) {
	case REGULATOR_MODE_NORMAL:
		reg |= SMPS_CTRL_MODE_ON;
		break;
	case REGULATOR_MODE_IDLE:
		reg |= SMPS_CTRL_MODE_ECO;
		break;
	case REGULATOR_MODE_FAST:
		reg |= SMPS_CTRL_MODE_PWM;
		break;
	default:
		return -EINVAL;
	}

	pmic->current_reg_mode[id] = reg & PALMAS_SMPS12_CTRL_MODE_ACTIVE_MASK;
	if (rail_enable)
		palmas_smps_write(pmic->palmas, rinfo->ctrl_addr, reg);

	/* Switch the enable value to ensure this is used for enable */
	pmic->desc[id].enable_val = pmic->current_reg_mode[id];

	return 0;
}

__attribute__((used)) static unsigned int palmas_get_mode_smps(struct regulator_dev *dev)
{
	struct palmas_pmic *pmic = rdev_get_drvdata(dev);
	int id = rdev_get_id(dev);
	unsigned int reg;

	reg = pmic->current_reg_mode[id] & PALMAS_SMPS12_CTRL_MODE_ACTIVE_MASK;

	switch (reg) {
	case SMPS_CTRL_MODE_ON:
		return REGULATOR_MODE_NORMAL;
	case SMPS_CTRL_MODE_ECO:
		return REGULATOR_MODE_IDLE;
	case SMPS_CTRL_MODE_PWM:
		return REGULATOR_MODE_FAST;
	}

	return 0;
}

__attribute__((used)) static int palmas_smps_set_ramp_delay(struct regulator_dev *rdev,
		 int ramp_delay)
{
	int id = rdev_get_id(rdev);
	struct palmas_pmic *pmic = rdev_get_drvdata(rdev);
	struct palmas_pmic_driver_data *ddata = pmic->palmas->pmic_ddata;
	struct palmas_regs_info *rinfo = &ddata->palmas_regs_info[id];
	unsigned int reg = 0;
	int ret;

	/* SMPS3 and SMPS7 do not have tstep_addr setting */
	switch (id) {
	case PALMAS_REG_SMPS3:
	case PALMAS_REG_SMPS7:
		return 0;
	}

	if (ramp_delay <= 0)
		reg = 0;
	else if (ramp_delay <= 2500)
		reg = 3;
	else if (ramp_delay <= 5000)
		reg = 2;
	else
		reg = 1;

	ret = palmas_smps_write(pmic->palmas, rinfo->tstep_addr, reg);
	if (ret < 0) {
		dev_err(pmic->palmas->dev, "TSTEP write failed: %d\n", ret);
		return ret;
	}

	pmic->ramp_delay[id] = palmas_smps_ramp_delay[reg];
	return ret;
}

__attribute__((used)) static int palmas_is_enabled_ldo(struct regulator_dev *dev)
{
	int id = rdev_get_id(dev);
	struct palmas_pmic *pmic = rdev_get_drvdata(dev);
	struct palmas_pmic_driver_data *ddata = pmic->palmas->pmic_ddata;
	struct palmas_regs_info *rinfo = &ddata->palmas_regs_info[id];
	unsigned int reg;

	palmas_ldo_read(pmic->palmas, rinfo->ctrl_addr, &reg);

	reg &= PALMAS_LDO1_CTRL_STATUS;

	return !!(reg);
}

__attribute__((used)) static int palmas_regulator_config_external(struct palmas *palmas, int id,
		struct palmas_reg_init *reg_init)
{
	struct palmas_pmic_driver_data *ddata = palmas->pmic_ddata;
	struct palmas_regs_info *rinfo = &ddata->palmas_regs_info[id];
	int ret;

	ret = palmas_ext_control_req_config(palmas, rinfo->sleep_id,
					    reg_init->roof_floor, true);
	if (ret < 0)
		dev_err(palmas->dev,
			"Ext control config for regulator %d failed %d\n",
			id, ret);
	return ret;
}

__attribute__((used)) static int palmas_smps_init(struct palmas *palmas, int id,
		struct palmas_reg_init *reg_init)
{
	unsigned int reg;
	int ret;
	struct palmas_pmic_driver_data *ddata = palmas->pmic_ddata;
	struct palmas_regs_info *rinfo = &ddata->palmas_regs_info[id];
	unsigned int addr = rinfo->ctrl_addr;

	ret = palmas_smps_read(palmas, addr, &reg);
	if (ret)
		return ret;

	switch (id) {
	case PALMAS_REG_SMPS10_OUT1:
	case PALMAS_REG_SMPS10_OUT2:
		reg &= ~PALMAS_SMPS10_CTRL_MODE_SLEEP_MASK;
		if (reg_init->mode_sleep)
			reg |= reg_init->mode_sleep <<
					PALMAS_SMPS10_CTRL_MODE_SLEEP_SHIFT;
		break;
	default:
		if (reg_init->warm_reset)
			reg |= PALMAS_SMPS12_CTRL_WR_S;
		else
			reg &= ~PALMAS_SMPS12_CTRL_WR_S;

		if (reg_init->roof_floor)
			reg |= PALMAS_SMPS12_CTRL_ROOF_FLOOR_EN;
		else
			reg &= ~PALMAS_SMPS12_CTRL_ROOF_FLOOR_EN;

		reg &= ~PALMAS_SMPS12_CTRL_MODE_SLEEP_MASK;
		if (reg_init->mode_sleep)
			reg |= reg_init->mode_sleep <<
					PALMAS_SMPS12_CTRL_MODE_SLEEP_SHIFT;
	}

	ret = palmas_smps_write(palmas, addr, reg);
	if (ret)
		return ret;

	if (rinfo->vsel_addr && reg_init->vsel) {

		reg = reg_init->vsel;

		ret = palmas_smps_write(palmas, rinfo->vsel_addr, reg);
		if (ret)
			return ret;
	}

	if (reg_init->roof_floor && (id != PALMAS_REG_SMPS10_OUT1) &&
			(id != PALMAS_REG_SMPS10_OUT2)) {
		/* Enable externally controlled regulator */
		ret = palmas_smps_read(palmas, addr, &reg);
		if (ret < 0)
			return ret;

		if (!(reg & PALMAS_SMPS12_CTRL_MODE_ACTIVE_MASK)) {
			reg |= SMPS_CTRL_MODE_ON;
			ret = palmas_smps_write(palmas, addr, reg);
			if (ret < 0)
				return ret;
		}
		return palmas_regulator_config_external(palmas, id, reg_init);
	}
	return 0;
}

__attribute__((used)) static int palmas_ldo_init(struct palmas *palmas, int id,
		struct palmas_reg_init *reg_init)
{
	unsigned int reg;
	unsigned int addr;
	int ret;
	struct palmas_pmic_driver_data *ddata = palmas->pmic_ddata;
	struct palmas_regs_info *rinfo = &ddata->palmas_regs_info[id];

	addr = rinfo->ctrl_addr;

	ret = palmas_ldo_read(palmas, addr, &reg);
	if (ret)
		return ret;

	if (reg_init->warm_reset)
		reg |= PALMAS_LDO1_CTRL_WR_S;
	else
		reg &= ~PALMAS_LDO1_CTRL_WR_S;

	if (reg_init->mode_sleep)
		reg |= PALMAS_LDO1_CTRL_MODE_SLEEP;
	else
		reg &= ~PALMAS_LDO1_CTRL_MODE_SLEEP;

	ret = palmas_ldo_write(palmas, addr, reg);
	if (ret)
		return ret;

	if (reg_init->roof_floor) {
		/* Enable externally controlled regulator */
		ret = palmas_update_bits(palmas, PALMAS_LDO_BASE,
				addr, PALMAS_LDO1_CTRL_MODE_ACTIVE,
				PALMAS_LDO1_CTRL_MODE_ACTIVE);
		if (ret < 0) {
			dev_err(palmas->dev,
				"LDO Register 0x%02x update failed %d\n",
				addr, ret);
			return ret;
		}
		return palmas_regulator_config_external(palmas, id, reg_init);
	}
	return 0;
}

__attribute__((used)) static int palmas_extreg_init(struct palmas *palmas, int id,
		struct palmas_reg_init *reg_init)
{
	unsigned int addr;
	int ret;
	unsigned int val = 0;
	struct palmas_pmic_driver_data *ddata = palmas->pmic_ddata;
	struct palmas_regs_info *rinfo = &ddata->palmas_regs_info[id];

	addr = rinfo->ctrl_addr;

	if (reg_init->mode_sleep)
		val = PALMAS_REGEN1_CTRL_MODE_SLEEP;

	ret = palmas_update_bits(palmas, PALMAS_RESOURCE_BASE,
			addr, PALMAS_REGEN1_CTRL_MODE_SLEEP, val);
	if (ret < 0) {
		dev_err(palmas->dev, "Resource reg 0x%02x update failed %d\n",
			addr, ret);
		return ret;
	}

	if (reg_init->roof_floor) {
		/* Enable externally controlled regulator */
		ret = palmas_update_bits(palmas, PALMAS_RESOURCE_BASE,
				addr, PALMAS_REGEN1_CTRL_MODE_ACTIVE,
				PALMAS_REGEN1_CTRL_MODE_ACTIVE);
		if (ret < 0) {
			dev_err(palmas->dev,
				"Resource Register 0x%02x update failed %d\n",
				addr, ret);
			return ret;
		}
		return palmas_regulator_config_external(palmas, id, reg_init);
	}
	return 0;
}

__attribute__((used)) static void palmas_enable_ldo8_track(struct palmas *palmas)
{
	unsigned int reg;
	unsigned int addr;
	int ret;
	struct palmas_pmic_driver_data *ddata = palmas->pmic_ddata;
	struct palmas_regs_info *rinfo;

	rinfo = &ddata->palmas_regs_info[PALMAS_REG_LDO8];
	addr = rinfo->ctrl_addr;

	ret = palmas_ldo_read(palmas, addr, &reg);
	if (ret) {
		dev_err(palmas->dev, "Error in reading ldo8 control reg\n");
		return;
	}

	reg |= PALMAS_LDO8_CTRL_LDO_TRACKING_EN;
	ret = palmas_ldo_write(palmas, addr, reg);
	if (ret < 0) {
		dev_err(palmas->dev, "Error in enabling tracking mode\n");
		return;
	}
	/*
	 * When SMPS45 is set to off and LDO8 tracking is enabled, the LDO8
	 * output is defined by the LDO8_VOLTAGE.VSEL register divided by two,
	 * and can be set from 0.45 to 1.65 V.
	 */
	addr = rinfo->vsel_addr;
	ret = palmas_ldo_read(palmas, addr, &reg);
	if (ret) {
		dev_err(palmas->dev, "Error in reading ldo8 voltage reg\n");
		return;
	}

	reg = (reg << 1) & PALMAS_LDO8_VOLTAGE_VSEL_MASK;
	ret = palmas_ldo_write(palmas, addr, reg);
	if (ret < 0)
		dev_err(palmas->dev, "Error in setting ldo8 voltage reg\n");

	return;
}

__attribute__((used)) static int palmas_ldo_registration(struct palmas_pmic *pmic,
				   struct palmas_pmic_driver_data *ddata,
				   struct palmas_pmic_platform_data *pdata,
				   const char *pdev_name,
				   struct regulator_config config)
{
	int id, ret;
	struct regulator_dev *rdev;
	struct palmas_reg_init *reg_init;
	struct palmas_regs_info *rinfo;
	struct regulator_desc *desc;

	for (id = ddata->ldo_begin; id < ddata->max_reg; id++) {
		if (pdata && pdata->reg_init[id])
			reg_init = pdata->reg_init[id];
		else
			reg_init = NULL;

		rinfo = &ddata->palmas_regs_info[id];
		/* Miss out regulators which are not available due
		 * to alternate functions.
		 */

		/* Register the regulators */
		desc = &pmic->desc[id];
		desc->name = rinfo->name;
		desc->id = id;
		desc->type = REGULATOR_VOLTAGE;
		desc->owner = THIS_MODULE;

		if (id < PALMAS_REG_REGEN1) {
			desc->n_voltages = PALMAS_LDO_NUM_VOLTAGES;
			if (reg_init && reg_init->roof_floor)
				desc->ops = &palmas_ops_ext_control_ldo;
			else
				desc->ops = &palmas_ops_ldo;
			desc->min_uV = 900000;
			desc->uV_step = 50000;
			desc->linear_min_sel = 1;
			desc->enable_time = 500;
			desc->vsel_reg = PALMAS_BASE_TO_REG(PALMAS_LDO_BASE,
							    rinfo->vsel_addr);
			desc->vsel_mask = PALMAS_LDO1_VOLTAGE_VSEL_MASK;
			desc->enable_reg = PALMAS_BASE_TO_REG(PALMAS_LDO_BASE,
							      rinfo->ctrl_addr);
			desc->enable_mask = PALMAS_LDO1_CTRL_MODE_ACTIVE;

			/* Check if LDO8 is in tracking mode or not */
			if (pdata && (id == PALMAS_REG_LDO8) &&
			    pdata->enable_ldo8_tracking) {
				palmas_enable_ldo8_track(pmic->palmas);
				desc->min_uV = 450000;
				desc->uV_step = 25000;
			}

			/* LOD6 in vibrator mode will have enable time 2000us */
			if (pdata && pdata->ldo6_vibrator &&
			    (id == PALMAS_REG_LDO6))
				desc->enable_time = 2000;

			if (id == PALMAS_REG_LDO9) {
				desc->ops = &palmas_ops_ldo9;
				desc->bypass_reg = desc->enable_reg;
				desc->bypass_val_on =
						PALMAS_LDO9_CTRL_LDO_BYPASS_EN;
				desc->bypass_mask =
						PALMAS_LDO9_CTRL_LDO_BYPASS_EN;
			}
		} else {
			if (!ddata->has_regen3 && id == PALMAS_REG_REGEN3)
				continue;

			desc->n_voltages = 1;
			if (reg_init && reg_init->roof_floor)
				desc->ops = &palmas_ops_ext_control_extreg;
			else
				desc->ops = &palmas_ops_extreg;
			desc->enable_reg =
					PALMAS_BASE_TO_REG(PALMAS_RESOURCE_BASE,
							   rinfo->ctrl_addr);
			desc->enable_mask = PALMAS_REGEN1_CTRL_MODE_ACTIVE;
		}

		if (pdata)
			config.init_data = pdata->reg_data[id];
		else
			config.init_data = NULL;

		desc->supply_name = rinfo->sname;
		config.of_node = ddata->palmas_matches[id].of_node;

		rdev = devm_regulator_register(pmic->dev, desc, &config);
		if (IS_ERR(rdev)) {
			dev_err(pmic->dev,
				"failed to register %s regulator\n",
				pdev_name);
			return PTR_ERR(rdev);
		}

		/* Save regulator for cleanup */
		pmic->rdev[id] = rdev;

		/* Initialise sleep/init values from platform data */
		if (pdata) {
			reg_init = pdata->reg_init[id];
			if (reg_init) {
				if (id <= ddata->ldo_end)
					ret = palmas_ldo_init(pmic->palmas, id,
							      reg_init);
				else
					ret = palmas_extreg_init(pmic->palmas,
								 id, reg_init);
				if (ret)
					return ret;
			}
		}
	}

	return 0;
}

__attribute__((used)) static int tps65917_ldo_registration(struct palmas_pmic *pmic,
				     struct palmas_pmic_driver_data *ddata,
				     struct palmas_pmic_platform_data *pdata,
				     const char *pdev_name,
				     struct regulator_config config)
{
	int id, ret;
	struct regulator_dev *rdev;
	struct palmas_reg_init *reg_init;
	struct palmas_regs_info *rinfo;
	struct regulator_desc *desc;

	for (id = ddata->ldo_begin; id < ddata->max_reg; id++) {
		if (pdata && pdata->reg_init[id])
			reg_init = pdata->reg_init[id];
		else
			reg_init = NULL;

		/* Miss out regulators which are not available due
		 * to alternate functions.
		 */
		rinfo = &ddata->palmas_regs_info[id];

		/* Register the regulators */
		desc = &pmic->desc[id];
		desc->name = rinfo->name;
		desc->id = id;
		desc->type = REGULATOR_VOLTAGE;
		desc->owner = THIS_MODULE;

		if (id < TPS65917_REG_REGEN1) {
			desc->n_voltages = PALMAS_LDO_NUM_VOLTAGES;
			if (reg_init && reg_init->roof_floor)
				desc->ops = &palmas_ops_ext_control_ldo;
			else
				desc->ops = &tps65917_ops_ldo;
			desc->min_uV = 900000;
			desc->uV_step = 50000;
			desc->linear_min_sel = 1;
			desc->enable_time = 500;
			desc->vsel_reg = PALMAS_BASE_TO_REG(PALMAS_LDO_BASE,
							    rinfo->vsel_addr);
			desc->vsel_mask = PALMAS_LDO1_VOLTAGE_VSEL_MASK;
			desc->enable_reg = PALMAS_BASE_TO_REG(PALMAS_LDO_BASE,
							      rinfo->ctrl_addr);
			desc->enable_mask = PALMAS_LDO1_CTRL_MODE_ACTIVE;
			/*
			 * To be confirmed. Discussion on going with PMIC Team.
			 * It is of the order of ~60mV/uS.
			 */
			desc->ramp_delay = 2500;
			if (id == TPS65917_REG_LDO1 ||
			    id == TPS65917_REG_LDO2) {
				desc->ops = &tps65917_ops_ldo_1_2;
				desc->bypass_reg = desc->enable_reg;
				desc->bypass_val_on =
						TPS65917_LDO1_CTRL_BYPASS_EN;
				desc->bypass_mask =
						TPS65917_LDO1_CTRL_BYPASS_EN;
			}
		} else {
			desc->n_voltages = 1;
			if (reg_init && reg_init->roof_floor)
				desc->ops = &palmas_ops_ext_control_extreg;
			else
				desc->ops = &palmas_ops_extreg;
			desc->enable_reg =
					PALMAS_BASE_TO_REG(PALMAS_RESOURCE_BASE,
							   rinfo->ctrl_addr);
			desc->enable_mask = PALMAS_REGEN1_CTRL_MODE_ACTIVE;
		}

		if (pdata)
			config.init_data = pdata->reg_data[id];
		else
			config.init_data = NULL;

		desc->supply_name = rinfo->sname;
		config.of_node = ddata->palmas_matches[id].of_node;

		rdev = devm_regulator_register(pmic->dev, desc, &config);
		if (IS_ERR(rdev)) {
			dev_err(pmic->dev,
				"failed to register %s regulator\n",
				pdev_name);
			return PTR_ERR(rdev);
		}

		/* Save regulator for cleanup */
		pmic->rdev[id] = rdev;

		/* Initialise sleep/init values from platform data */
		if (pdata) {
			reg_init = pdata->reg_init[id];
			if (reg_init) {
				if (id < TPS65917_REG_REGEN1)
					ret = palmas_ldo_init(pmic->palmas,
							      id, reg_init);
				else
					ret = palmas_extreg_init(pmic->palmas,
								 id, reg_init);
				if (ret)
					return ret;
			}
		}
	}

	return 0;
}

__attribute__((used)) static int palmas_smps_registration(struct palmas_pmic *pmic,
				    struct palmas_pmic_driver_data *ddata,
				    struct palmas_pmic_platform_data *pdata,
				    const char *pdev_name,
				    struct regulator_config config)
{
	int id, ret;
	unsigned int addr, reg;
	struct regulator_dev *rdev;
	struct palmas_reg_init *reg_init;
	struct palmas_regs_info *rinfo;
	struct regulator_desc *desc;

	for (id = ddata->smps_start; id <= ddata->smps_end; id++) {
		bool ramp_delay_support = false;

		/*
		 * Miss out regulators which are not available due
		 * to slaving configurations.
		 */
		switch (id) {
		case PALMAS_REG_SMPS12:
		case PALMAS_REG_SMPS3:
			if (pmic->smps123)
				continue;
			if (id == PALMAS_REG_SMPS12)
				ramp_delay_support = true;
			break;
		case PALMAS_REG_SMPS123:
			if (!pmic->smps123)
				continue;
			ramp_delay_support = true;
			break;
		case PALMAS_REG_SMPS45:
		case PALMAS_REG_SMPS7:
			if (pmic->smps457)
				continue;
			if (id == PALMAS_REG_SMPS45)
				ramp_delay_support = true;
			break;
		case PALMAS_REG_SMPS457:
			if (!pmic->smps457)
				continue;
			ramp_delay_support = true;
			break;
		case PALMAS_REG_SMPS10_OUT1:
		case PALMAS_REG_SMPS10_OUT2:
			if (!PALMAS_PMIC_HAS(pmic->palmas, SMPS10_BOOST))
				continue;
		}
		rinfo = &ddata->palmas_regs_info[id];
		desc = &pmic->desc[id];

		if ((id == PALMAS_REG_SMPS6) || (id == PALMAS_REG_SMPS8))
			ramp_delay_support = true;

		if (ramp_delay_support) {
			addr = rinfo->tstep_addr;
			ret = palmas_smps_read(pmic->palmas, addr, &reg);
			if (ret < 0) {
				dev_err(pmic->dev,
					"reading TSTEP reg failed: %d\n", ret);
				return ret;
			}
			desc->ramp_delay = palmas_smps_ramp_delay[reg & 0x3];
			pmic->ramp_delay[id] = desc->ramp_delay;
		}

		/* Initialise sleep/init values from platform data */
		if (pdata && pdata->reg_init[id]) {
			reg_init = pdata->reg_init[id];
			ret = palmas_smps_init(pmic->palmas, id, reg_init);
			if (ret)
				return ret;
		} else {
			reg_init = NULL;
		}

		/* Register the regulators */
		desc->name = rinfo->name;
		desc->id = id;

		switch (id) {
		case PALMAS_REG_SMPS10_OUT1:
		case PALMAS_REG_SMPS10_OUT2:
			desc->n_voltages = PALMAS_SMPS10_NUM_VOLTAGES;
			desc->ops = &palmas_ops_smps10;
			desc->vsel_reg = PALMAS_BASE_TO_REG(PALMAS_SMPS_BASE,
							    PALMAS_SMPS10_CTRL);
			desc->vsel_mask = SMPS10_VSEL;
			desc->enable_reg = PALMAS_BASE_TO_REG(PALMAS_SMPS_BASE,
							    PALMAS_SMPS10_CTRL);
			if (id == PALMAS_REG_SMPS10_OUT1)
				desc->enable_mask = SMPS10_SWITCH_EN;
			else
				desc->enable_mask = SMPS10_BOOST_EN;
			desc->bypass_reg = PALMAS_BASE_TO_REG(PALMAS_SMPS_BASE,
							    PALMAS_SMPS10_CTRL);
			desc->bypass_val_on = SMPS10_BYPASS_EN;
			desc->bypass_mask = SMPS10_BYPASS_EN;
			desc->min_uV = 3750000;
			desc->uV_step = 1250000;
			break;
		default:
			/*
			 * Read and store the RANGE bit for later use
			 * This must be done before regulator is probed,
			 * otherwise we error in probe with unsupportable
			 * ranges. Read the current smps mode for later use.
			 */
			addr = rinfo->vsel_addr;
			desc->n_linear_ranges = 3;

			ret = palmas_smps_read(pmic->palmas, addr, &reg);
			if (ret)
				return ret;
			if (reg & PALMAS_SMPS12_VOLTAGE_RANGE)
				pmic->range[id] = 1;
			if (pmic->range[id])
				desc->linear_ranges = smps_high_ranges;
			else
				desc->linear_ranges = smps_low_ranges;

			if (reg_init && reg_init->roof_floor)
				desc->ops = &palmas_ops_ext_control_smps;
			else
				desc->ops = &palmas_ops_smps;
			desc->n_voltages = PALMAS_SMPS_NUM_VOLTAGES;
			desc->vsel_reg = PALMAS_BASE_TO_REG(PALMAS_SMPS_BASE,
							    rinfo->vsel_addr);
			desc->vsel_mask = PALMAS_SMPS12_VOLTAGE_VSEL_MASK;

			/* Read the smps mode for later use. */
			addr = rinfo->ctrl_addr;
			ret = palmas_smps_read(pmic->palmas, addr, &reg);
			if (ret)
				return ret;
			pmic->current_reg_mode[id] = reg &
					PALMAS_SMPS12_CTRL_MODE_ACTIVE_MASK;

			desc->enable_reg = PALMAS_BASE_TO_REG(PALMAS_SMPS_BASE,
							      rinfo->ctrl_addr);
			desc->enable_mask = PALMAS_SMPS12_CTRL_MODE_ACTIVE_MASK;
			/* set_mode overrides this value */
			desc->enable_val = SMPS_CTRL_MODE_ON;
		}

		desc->type = REGULATOR_VOLTAGE;
		desc->owner = THIS_MODULE;

		if (pdata)
			config.init_data = pdata->reg_data[id];
		else
			config.init_data = NULL;

		desc->supply_name = rinfo->sname;
		config.of_node = ddata->palmas_matches[id].of_node;

		rdev = devm_regulator_register(pmic->dev, desc, &config);
		if (IS_ERR(rdev)) {
			dev_err(pmic->dev,
				"failed to register %s regulator\n",
				pdev_name);
			return PTR_ERR(rdev);
		}

		/* Save regulator for cleanup */
		pmic->rdev[id] = rdev;
	}

	return 0;
}

__attribute__((used)) static int tps65917_smps_registration(struct palmas_pmic *pmic,
				      struct palmas_pmic_driver_data *ddata,
				      struct palmas_pmic_platform_data *pdata,
				      const char *pdev_name,
				      struct regulator_config config)
{
	int id, ret;
	unsigned int addr, reg;
	struct regulator_dev *rdev;
	struct palmas_reg_init *reg_init;
	struct palmas_regs_info *rinfo;
	struct regulator_desc *desc;

	for (id = ddata->smps_start; id <= ddata->smps_end; id++) {
		/*
		 * Miss out regulators which are not available due
		 * to slaving configurations.
		 */
		desc = &pmic->desc[id];
		desc->n_linear_ranges = 3;
		if ((id == TPS65917_REG_SMPS2 || id == TPS65917_REG_SMPS1) &&
		    pmic->smps12)
			continue;

		/* Initialise sleep/init values from platform data */
		if (pdata && pdata->reg_init[id]) {
			reg_init = pdata->reg_init[id];
			ret = palmas_smps_init(pmic->palmas, id, reg_init);
			if (ret)
				return ret;
		} else {
			reg_init = NULL;
		}
		rinfo = &ddata->palmas_regs_info[id];

		/* Register the regulators */
		desc->name = rinfo->name;
		desc->id = id;

		/*
		 * Read and store the RANGE bit for later use
		 * This must be done before regulator is probed,
		 * otherwise we error in probe with unsupportable
		 * ranges. Read the current smps mode for later use.
		 */
		addr = rinfo->vsel_addr;

		ret = palmas_smps_read(pmic->palmas, addr, &reg);
		if (ret)
			return ret;
		if (reg & TPS65917_SMPS1_VOLTAGE_RANGE)
			pmic->range[id] = 1;

		if (pmic->range[id])
			desc->linear_ranges = smps_high_ranges;
		else
			desc->linear_ranges = smps_low_ranges;

		if (reg_init && reg_init->roof_floor)
			desc->ops = &tps65917_ops_ext_control_smps;
		else
			desc->ops = &tps65917_ops_smps;
		desc->n_voltages = PALMAS_SMPS_NUM_VOLTAGES;
		desc->vsel_reg = PALMAS_BASE_TO_REG(PALMAS_SMPS_BASE,
						    rinfo->vsel_addr);
		desc->vsel_mask = PALMAS_SMPS12_VOLTAGE_VSEL_MASK;
		desc->ramp_delay = 2500;

		/* Read the smps mode for later use. */
		addr = rinfo->ctrl_addr;
		ret = palmas_smps_read(pmic->palmas, addr, &reg);
		if (ret)
			return ret;
		pmic->current_reg_mode[id] = reg &
				PALMAS_SMPS12_CTRL_MODE_ACTIVE_MASK;
		desc->enable_reg = PALMAS_BASE_TO_REG(PALMAS_SMPS_BASE,
						      rinfo->ctrl_addr);
		desc->enable_mask = PALMAS_SMPS12_CTRL_MODE_ACTIVE_MASK;
		/* set_mode overrides this value */
		desc->enable_val = SMPS_CTRL_MODE_ON;

		desc->type = REGULATOR_VOLTAGE;
		desc->owner = THIS_MODULE;

		if (pdata)
			config.init_data = pdata->reg_data[id];
		else
			config.init_data = NULL;

		desc->supply_name = rinfo->sname;
		config.of_node = ddata->palmas_matches[id].of_node;

		rdev = devm_regulator_register(pmic->dev, desc, &config);
		if (IS_ERR(rdev)) {
			dev_err(pmic->dev,
				"failed to register %s regulator\n",
				pdev_name);
			return PTR_ERR(rdev);
		}

		/* Save regulator for cleanup */
		pmic->rdev[id] = rdev;
	}

	return 0;
}

__attribute__((used)) static int palmas_dt_to_pdata(struct device *dev,
			      struct device_node *node,
			      struct palmas_pmic_platform_data *pdata,
			      struct palmas_pmic_driver_data *ddata)
{
	struct device_node *regulators;
	u32 prop;
	int idx, ret;

	regulators = of_get_child_by_name(node, "regulators");
	if (!regulators) {
		dev_info(dev, "regulator node not found\n");
		return 0;
	}

	ret = of_regulator_match(dev, regulators, ddata->palmas_matches,
				 ddata->max_reg);
	of_node_put(regulators);
	if (ret < 0) {
		dev_err(dev, "Error parsing regulator init data: %d\n", ret);
		return 0;
	}

	for (idx = 0; idx < ddata->max_reg; idx++) {
		struct of_regulator_match *match;
		struct palmas_reg_init *rinit;
		struct device_node *np;

		match = &ddata->palmas_matches[idx];
		np = match->of_node;

		if (!match->init_data || !np)
			continue;

		rinit = devm_kzalloc(dev, sizeof(*rinit), GFP_KERNEL);
		if (!rinit)
			return -ENOMEM;

		pdata->reg_data[idx] = match->init_data;
		pdata->reg_init[idx] = rinit;

		rinit->warm_reset = of_property_read_bool(np, "ti,warm-reset");
		ret = of_property_read_u32(np, "ti,roof-floor", &prop);
		/* EINVAL: Property not found */
		if (ret != -EINVAL) {
			int econtrol;

			/* use default value, when no value is specified */
			econtrol = PALMAS_EXT_CONTROL_NSLEEP;
			if (!ret) {
				switch (prop) {
				case 1:
					econtrol = PALMAS_EXT_CONTROL_ENABLE1;
					break;
				case 2:
					econtrol = PALMAS_EXT_CONTROL_ENABLE2;
					break;
				case 3:
					econtrol = PALMAS_EXT_CONTROL_NSLEEP;
					break;
				default:
					WARN_ON(1);
					dev_warn(dev,
						 "%s: Invalid roof-floor option: %u\n",
						 match->name, prop);
					break;
				}
			}
			rinit->roof_floor = econtrol;
		}

		ret = of_property_read_u32(np, "ti,mode-sleep", &prop);
		if (!ret)
			rinit->mode_sleep = prop;

		ret = of_property_read_bool(np, "ti,smps-range");
		if (ret)
			rinit->vsel = PALMAS_SMPS12_VOLTAGE_RANGE;

		if (idx == PALMAS_REG_LDO8)
			pdata->enable_ldo8_tracking = of_property_read_bool(
						np, "ti,enable-ldo8-tracking");
	}

	pdata->ldo6_vibrator = of_property_read_bool(node, "ti,ldo6-vibrator");

	return 0;
}

__attribute__((used)) static int palmas_regulators_probe(struct platform_device *pdev)
{
	struct palmas *palmas = dev_get_drvdata(pdev->dev.parent);
	struct palmas_pmic_platform_data *pdata = dev_get_platdata(&pdev->dev);
	struct device_node *node = pdev->dev.of_node;
	struct palmas_pmic_driver_data *driver_data;
	struct regulator_config config = { };
	struct palmas_pmic *pmic;
	const char *pdev_name;
	const struct of_device_id *match;
	int ret = 0;
	unsigned int reg;

	match = of_match_device(of_match_ptr(of_palmas_match_tbl), &pdev->dev);

	if (!match)
		return -ENODATA;

	driver_data = (struct palmas_pmic_driver_data *)match->data;
	pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
	if (!pdata)
		return -ENOMEM;

	pmic = devm_kzalloc(&pdev->dev, sizeof(*pmic), GFP_KERNEL);
	if (!pmic)
		return -ENOMEM;

	if (of_device_is_compatible(node, "ti,tps659038-pmic")) {
		palmas_generic_regs_info[PALMAS_REG_REGEN2].ctrl_addr =
							TPS659038_REGEN2_CTRL;
		palmas_ddata.has_regen3 = false;
	}

	pmic->dev = &pdev->dev;
	pmic->palmas = palmas;
	palmas->pmic = pmic;
	platform_set_drvdata(pdev, pmic);
	pmic->palmas->pmic_ddata = driver_data;

	ret = palmas_dt_to_pdata(&pdev->dev, node, pdata, driver_data);
	if (ret)
		return ret;

	ret = palmas_smps_read(palmas, PALMAS_SMPS_CTRL, &reg);
	if (ret)
		return ret;

	if (reg & PALMAS_SMPS_CTRL_SMPS12_SMPS123_EN) {
		pmic->smps123 = 1;
		pmic->smps12 = 1;
	}

	if (reg & PALMAS_SMPS_CTRL_SMPS45_SMPS457_EN)
		pmic->smps457 = 1;

	config.regmap = palmas->regmap[REGULATOR_SLAVE];
	config.dev = &pdev->dev;
	config.driver_data = pmic;
	pdev_name = pdev->name;

	ret = driver_data->smps_register(pmic, driver_data, pdata, pdev_name,
					 config);
	if (ret)
		return ret;

	ret = driver_data->ldo_register(pmic, driver_data, pdata, pdev_name,
					config);

	return ret;
}

