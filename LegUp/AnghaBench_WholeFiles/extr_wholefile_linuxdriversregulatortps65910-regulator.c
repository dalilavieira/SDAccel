#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct tps_info {int* voltage_table; unsigned int n_voltages; int /*<<< orphan*/  enable_time_us; int /*<<< orphan*/  vin_name; int /*<<< orphan*/  name; } ;
struct tps65910_reg {int (* get_ctrl_reg ) (int) ;int* ext_sleep_control; int* board_ext_control; int num_regulators; struct regulator_dev** rdev; TYPE_3__* desc; struct tps_info** info; struct tps65910* mfd; } ;
struct tps65910_board {int* regulator_ext_sleep_control; int /*<<< orphan*/ * tps65910_pmic_init_data; } ;
struct tps65910 {TYPE_2__* dev; int /*<<< orphan*/  regmap; } ;
struct regulator_dev {TYPE_1__* desc; } ;
struct regulator_desc {int dummy; } ;
struct regulator_config {int /*<<< orphan*/  of_node; int /*<<< orphan*/  regmap; struct tps65910_reg* driver_data; int /*<<< orphan*/  init_data; TYPE_2__* dev; } ;
struct TYPE_10__ {scalar_t__ of_node; int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_2__ dev; int /*<<< orphan*/  name; } ;
struct of_regulator_match {int /*<<< orphan*/  of_node; } ;
struct TYPE_11__ {int id; unsigned int n_voltages; int ramp_delay; int* volt_table; int enable_reg; int /*<<< orphan*/  enable_mask; int /*<<< orphan*/  owner; int /*<<< orphan*/  type; int /*<<< orphan*/ * ops; int /*<<< orphan*/  enable_time; int /*<<< orphan*/  supply_name; int /*<<< orphan*/  name; } ;
struct TYPE_9__ {int* volt_table; } ;

/* Variables and functions */
 void* ARRAY_SIZE (struct tps_info*) ; 
 int BBCH_BBSEL_MASK ; 
 int BBCH_BBSEL_SHIFT ; 
 int /*<<< orphan*/  BUG () ; 
 int /*<<< orphan*/  BUILD_BUG_ON (int) ; 
 int DCDCCTRL_DCDCCKSYNC_MASK ; 
 int DEVCTRL_SR_CTL_I2C_SEL_MASK ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int EXT_SLEEP_CONTROL ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct regulator_dev*) ; 
 unsigned int LDO1_SEL_MASK ; 
 unsigned int LDO3_SEL_MASK ; 
 unsigned int LDO_MIN_VOLT ; 
 int LDO_SEL_MASK ; 
 int LDO_SEL_SHIFT ; 
 int LDO_ST_MODE_BIT ; 
 int LDO_ST_ON_BIT ; 
 int PTR_ERR (struct regulator_dev*) ; 
#define  REGULATOR_MODE_IDLE 155 
#define  REGULATOR_MODE_NORMAL 154 
#define  REGULATOR_MODE_STANDBY 153 
 int /*<<< orphan*/  REGULATOR_VOLTAGE ; 
 int /*<<< orphan*/  THIS_MODULE ; 
#define  TPS65910 152 
 int TPS65910_BBCH ; 
 int TPS65910_DCDCCTRL ; 
 int TPS65910_DEVCTRL ; 
 int TPS65910_EN1_LDO_ASS ; 
 int TPS65910_EN2_LDO_ASS ; 
 int TPS65910_EN3_LDO_ASS ; 
 void* TPS65910_NUM_REGS ; 
#define  TPS65910_REG_VAUX1 151 
#define  TPS65910_REG_VAUX2 150 
#define  TPS65910_REG_VAUX33 149 
#define  TPS65910_REG_VBB 148 
#define  TPS65910_REG_VDAC 147 
#define  TPS65910_REG_VDD1 146 
#define  TPS65910_REG_VDD2 145 
#define  TPS65910_REG_VDD3 144 
#define  TPS65910_REG_VDIG1 143 
#define  TPS65910_REG_VDIG2 142 
#define  TPS65910_REG_VIO 141 
#define  TPS65910_REG_VMMC 140 
#define  TPS65910_REG_VPLL 139 
#define  TPS65910_REG_VRTC 138 
 int TPS65910_SLEEP_CONTROL_EXT_INPUT_EN1 ; 
 int TPS65910_SLEEP_CONTROL_EXT_INPUT_EN2 ; 
 int TPS65910_SLEEP_CONTROL_EXT_INPUT_EN3 ; 
 int TPS65910_SLEEP_KEEP_LDO_ON ; 
 int TPS65910_SLEEP_SET_LDO_OFF ; 
 int /*<<< orphan*/  TPS65910_SUPPLY_STATE_ENABLED ; 
 int TPS65910_VAUX1 ; 
 int TPS65910_VAUX2 ; 
 int TPS65910_VAUX33 ; 
 int TPS65910_VDAC ; 
 int TPS65910_VDD1 ; 
 int TPS65910_VDD1_OP ; 
 int TPS65910_VDD1_SR ; 
 int TPS65910_VDD2 ; 
 int TPS65910_VDD2_OP ; 
 int TPS65910_VDD2_SR ; 
 int TPS65910_VDD3 ; 
 int TPS65910_VDIG1 ; 
 int TPS65910_VDIG2 ; 
 int TPS65910_VIO ; 
 int TPS65910_VMMC ; 
 int TPS65910_VPLL ; 
 int TPS65910_VRTC ; 
#define  TPS65911 137 
 int TPS65911_LDO1 ; 
 int TPS65911_LDO2 ; 
 int TPS65911_LDO3 ; 
 int TPS65911_LDO4 ; 
 int TPS65911_LDO5 ; 
 int TPS65911_LDO6 ; 
 int TPS65911_LDO7 ; 
 int TPS65911_LDO8 ; 
#define  TPS65911_REG_LDO1 136 
#define  TPS65911_REG_LDO2 135 
#define  TPS65911_REG_LDO3 134 
#define  TPS65911_REG_LDO4 133 
#define  TPS65911_REG_LDO5 132 
#define  TPS65911_REG_LDO6 131 
#define  TPS65911_REG_LDO7 130 
#define  TPS65911_REG_LDO8 129 
#define  TPS65911_REG_VDDCTRL 128 
 int TPS65911_SLEEP_CONTROL_EXT_INPUT_SLEEP ; 
 int TPS65911_VDDCTRL ; 
 int TPS65911_VDDCTRL_OP ; 
 int TPS65911_VDDCTRL_SR ; 
 unsigned int VDD1_2_MIN_VOLT ; 
 unsigned int VDD1_2_NUM_VOLT_COARSE ; 
 unsigned int VDD1_2_NUM_VOLT_FINE ; 
 unsigned int VDD1_2_OFFSET ; 
 int VDD1_OP_CMD_MASK ; 
 int VDD1_OP_SEL_MASK ; 
 int VDD1_SR_SEL_MASK ; 
 int VDD1_VGAIN_SEL_MASK ; 
 int VDD1_VGAIN_SEL_SHIFT ; 
 int VDD2_OP_CMD_MASK ; 
 int VDD2_OP_SEL_MASK ; 
 int VDD2_SR_SEL_MASK ; 
 int VDD2_VGAIN_SEL_MASK ; 
 int VDD2_VGAIN_SEL_SHIFT ; 
 unsigned int VDDCTRL_MIN_VOLT ; 
 unsigned int VDDCTRL_OFFSET ; 
 int VDDCTRL_OP_CMD_MASK ; 
 int VDDCTRL_OP_SEL_MASK ; 
 int VDDCTRL_SR_SEL_MASK ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*,...) ; 
 struct tps65910* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 struct tps65910_board* dev_get_platdata (TYPE_2__*) ; 
 int /*<<< orphan*/  dev_warn (TYPE_2__*,char*) ; 
 void* devm_kcalloc (TYPE_2__*,int,int,int /*<<< orphan*/ ) ; 
 struct tps65910_reg* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 struct regulator_dev* devm_regulator_register (TYPE_2__*,TYPE_3__*,struct regulator_config*) ; 
 struct tps65910_reg* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct tps65910_reg*) ; 
 struct tps65910_reg* rdev_get_drvdata (struct regulator_dev*) ; 
 int rdev_get_id (struct regulator_dev*) ; 
 int stub1 (int) ; 
 int stub2 (int) ; 
 int stub3 (int) ; 
 unsigned int stub4 (int) ; 
 int stub5 (int) ; 
 int stub6 (int) ; 
 int stub7 (int) ; 
 int stub8 (int) ; 
 int stub9 (int) ; 
 int tps65910_chip_id (struct tps65910*) ; 
 int* tps65910_ext_sleep_control ; 
 int /*<<< orphan*/  tps65910_ops ; 
 int /*<<< orphan*/  tps65910_ops_dcdc ; 
 int /*<<< orphan*/  tps65910_ops_vbb ; 
 int /*<<< orphan*/  tps65910_ops_vdd3 ; 
 int tps65910_reg_clear_bits (struct tps65910*,int,int) ; 
 int tps65910_reg_read (struct tps65910*,int,...) ; 
 int tps65910_reg_set_bits (struct tps65910*,int,int) ; 
 int tps65910_reg_update_bits (struct tps65910*,int,int,unsigned int) ; 
 int tps65910_reg_write (struct tps65910*,int,int) ; 
 struct tps_info* tps65910_regs ; 
 int* tps65911_ext_sleep_control ; 
 int /*<<< orphan*/  tps65911_ops ; 
 struct tps_info* tps65911_regs ; 

__attribute__((used)) static int tps65910_get_ctrl_register(int id)
{
	switch (id) {
	case TPS65910_REG_VRTC:
		return TPS65910_VRTC;
	case TPS65910_REG_VIO:
		return TPS65910_VIO;
	case TPS65910_REG_VDD1:
		return TPS65910_VDD1;
	case TPS65910_REG_VDD2:
		return TPS65910_VDD2;
	case TPS65910_REG_VDD3:
		return TPS65910_VDD3;
	case TPS65910_REG_VDIG1:
		return TPS65910_VDIG1;
	case TPS65910_REG_VDIG2:
		return TPS65910_VDIG2;
	case TPS65910_REG_VPLL:
		return TPS65910_VPLL;
	case TPS65910_REG_VDAC:
		return TPS65910_VDAC;
	case TPS65910_REG_VAUX1:
		return TPS65910_VAUX1;
	case TPS65910_REG_VAUX2:
		return TPS65910_VAUX2;
	case TPS65910_REG_VAUX33:
		return TPS65910_VAUX33;
	case TPS65910_REG_VMMC:
		return TPS65910_VMMC;
	case TPS65910_REG_VBB:
		return TPS65910_BBCH;
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int tps65911_get_ctrl_register(int id)
{
	switch (id) {
	case TPS65910_REG_VRTC:
		return TPS65910_VRTC;
	case TPS65910_REG_VIO:
		return TPS65910_VIO;
	case TPS65910_REG_VDD1:
		return TPS65910_VDD1;
	case TPS65910_REG_VDD2:
		return TPS65910_VDD2;
	case TPS65911_REG_VDDCTRL:
		return TPS65911_VDDCTRL;
	case TPS65911_REG_LDO1:
		return TPS65911_LDO1;
	case TPS65911_REG_LDO2:
		return TPS65911_LDO2;
	case TPS65911_REG_LDO3:
		return TPS65911_LDO3;
	case TPS65911_REG_LDO4:
		return TPS65911_LDO4;
	case TPS65911_REG_LDO5:
		return TPS65911_LDO5;
	case TPS65911_REG_LDO6:
		return TPS65911_LDO6;
	case TPS65911_REG_LDO7:
		return TPS65911_LDO7;
	case TPS65911_REG_LDO8:
		return TPS65911_LDO8;
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int tps65910_set_mode(struct regulator_dev *dev, unsigned int mode)
{
	struct tps65910_reg *pmic = rdev_get_drvdata(dev);
	struct tps65910 *mfd = pmic->mfd;
	int reg, value, id = rdev_get_id(dev);

	reg = pmic->get_ctrl_reg(id);
	if (reg < 0)
		return reg;

	switch (mode) {
	case REGULATOR_MODE_NORMAL:
		return tps65910_reg_update_bits(pmic->mfd, reg,
						LDO_ST_MODE_BIT | LDO_ST_ON_BIT,
						LDO_ST_ON_BIT);
	case REGULATOR_MODE_IDLE:
		value = LDO_ST_ON_BIT | LDO_ST_MODE_BIT;
		return tps65910_reg_set_bits(mfd, reg, value);
	case REGULATOR_MODE_STANDBY:
		return tps65910_reg_clear_bits(mfd, reg, LDO_ST_ON_BIT);
	}

	return -EINVAL;
}

__attribute__((used)) static unsigned int tps65910_get_mode(struct regulator_dev *dev)
{
	struct tps65910_reg *pmic = rdev_get_drvdata(dev);
	int ret, reg, value, id = rdev_get_id(dev);

	reg = pmic->get_ctrl_reg(id);
	if (reg < 0)
		return reg;

	ret = tps65910_reg_read(pmic->mfd, reg, &value);
	if (ret < 0)
		return ret;

	if (!(value & LDO_ST_ON_BIT))
		return REGULATOR_MODE_STANDBY;
	else if (value & LDO_ST_MODE_BIT)
		return REGULATOR_MODE_IDLE;
	else
		return REGULATOR_MODE_NORMAL;
}

__attribute__((used)) static int tps65910_get_voltage_dcdc_sel(struct regulator_dev *dev)
{
	struct tps65910_reg *pmic = rdev_get_drvdata(dev);
	int ret, id = rdev_get_id(dev);
	int opvsel = 0, srvsel = 0, vselmax = 0, mult = 0, sr = 0;

	switch (id) {
	case TPS65910_REG_VDD1:
		ret = tps65910_reg_read(pmic->mfd, TPS65910_VDD1_OP, &opvsel);
		if (ret < 0)
			return ret;
		ret = tps65910_reg_read(pmic->mfd, TPS65910_VDD1, &mult);
		if (ret < 0)
			return ret;
		mult = (mult & VDD1_VGAIN_SEL_MASK) >> VDD1_VGAIN_SEL_SHIFT;
		ret = tps65910_reg_read(pmic->mfd, TPS65910_VDD1_SR, &srvsel);
		if (ret < 0)
			return ret;
		sr = opvsel & VDD1_OP_CMD_MASK;
		opvsel &= VDD1_OP_SEL_MASK;
		srvsel &= VDD1_SR_SEL_MASK;
		vselmax = 75;
		break;
	case TPS65910_REG_VDD2:
		ret = tps65910_reg_read(pmic->mfd, TPS65910_VDD2_OP, &opvsel);
		if (ret < 0)
			return ret;
		ret = tps65910_reg_read(pmic->mfd, TPS65910_VDD2, &mult);
		if (ret < 0)
			return ret;
		mult = (mult & VDD2_VGAIN_SEL_MASK) >> VDD2_VGAIN_SEL_SHIFT;
		ret = tps65910_reg_read(pmic->mfd, TPS65910_VDD2_SR, &srvsel);
		if (ret < 0)
			return ret;
		sr = opvsel & VDD2_OP_CMD_MASK;
		opvsel &= VDD2_OP_SEL_MASK;
		srvsel &= VDD2_SR_SEL_MASK;
		vselmax = 75;
		break;
	case TPS65911_REG_VDDCTRL:
		ret = tps65910_reg_read(pmic->mfd, TPS65911_VDDCTRL_OP,
					&opvsel);
		if (ret < 0)
			return ret;
		ret = tps65910_reg_read(pmic->mfd, TPS65911_VDDCTRL_SR,
					&srvsel);
		if (ret < 0)
			return ret;
		sr = opvsel & VDDCTRL_OP_CMD_MASK;
		opvsel &= VDDCTRL_OP_SEL_MASK;
		srvsel &= VDDCTRL_SR_SEL_MASK;
		vselmax = 64;
		break;
	}

	/* multiplier 0 == 1 but 2,3 normal */
	if (!mult)
		mult = 1;

	if (sr) {
		/* normalise to valid range */
		if (srvsel < 3)
			srvsel = 3;
		if (srvsel > vselmax)
			srvsel = vselmax;
		return srvsel - 3;
	} else {

		/* normalise to valid range*/
		if (opvsel < 3)
			opvsel = 3;
		if (opvsel > vselmax)
			opvsel = vselmax;
		return opvsel - 3;
	}
	return -EINVAL;
}

__attribute__((used)) static int tps65910_get_voltage_sel(struct regulator_dev *dev)
{
	struct tps65910_reg *pmic = rdev_get_drvdata(dev);
	int ret, reg, value, id = rdev_get_id(dev);

	reg = pmic->get_ctrl_reg(id);
	if (reg < 0)
		return reg;

	ret = tps65910_reg_read(pmic->mfd, reg, &value);
	if (ret < 0)
		return ret;

	switch (id) {
	case TPS65910_REG_VIO:
	case TPS65910_REG_VDIG1:
	case TPS65910_REG_VDIG2:
	case TPS65910_REG_VPLL:
	case TPS65910_REG_VDAC:
	case TPS65910_REG_VAUX1:
	case TPS65910_REG_VAUX2:
	case TPS65910_REG_VAUX33:
	case TPS65910_REG_VMMC:
		value &= LDO_SEL_MASK;
		value >>= LDO_SEL_SHIFT;
		break;
	case TPS65910_REG_VBB:
		value &= BBCH_BBSEL_MASK;
		value >>= BBCH_BBSEL_SHIFT;
		break;
	default:
		return -EINVAL;
	}

	return value;
}

__attribute__((used)) static int tps65910_get_voltage_vdd3(struct regulator_dev *dev)
{
	return dev->desc->volt_table[0];
}

__attribute__((used)) static int tps65911_get_voltage_sel(struct regulator_dev *dev)
{
	struct tps65910_reg *pmic = rdev_get_drvdata(dev);
	int ret, id = rdev_get_id(dev);
	unsigned int value, reg;

	reg = pmic->get_ctrl_reg(id);

	ret = tps65910_reg_read(pmic->mfd, reg, &value);
	if (ret < 0)
		return ret;

	switch (id) {
	case TPS65911_REG_LDO1:
	case TPS65911_REG_LDO2:
	case TPS65911_REG_LDO4:
		value &= LDO1_SEL_MASK;
		value >>= LDO_SEL_SHIFT;
		break;
	case TPS65911_REG_LDO3:
	case TPS65911_REG_LDO5:
	case TPS65911_REG_LDO6:
	case TPS65911_REG_LDO7:
	case TPS65911_REG_LDO8:
		value &= LDO3_SEL_MASK;
		value >>= LDO_SEL_SHIFT;
		break;
	case TPS65910_REG_VIO:
		value &= LDO_SEL_MASK;
		value >>= LDO_SEL_SHIFT;
		break;
	default:
		return -EINVAL;
	}

	return value;
}

__attribute__((used)) static int tps65910_set_voltage_dcdc_sel(struct regulator_dev *dev,
					 unsigned selector)
{
	struct tps65910_reg *pmic = rdev_get_drvdata(dev);
	int id = rdev_get_id(dev), vsel;
	int dcdc_mult = 0;

	switch (id) {
	case TPS65910_REG_VDD1:
		dcdc_mult = (selector / VDD1_2_NUM_VOLT_FINE) + 1;
		if (dcdc_mult == 1)
			dcdc_mult--;
		vsel = (selector % VDD1_2_NUM_VOLT_FINE) + 3;

		tps65910_reg_update_bits(pmic->mfd, TPS65910_VDD1,
					 VDD1_VGAIN_SEL_MASK,
					 dcdc_mult << VDD1_VGAIN_SEL_SHIFT);
		tps65910_reg_write(pmic->mfd, TPS65910_VDD1_OP, vsel);
		break;
	case TPS65910_REG_VDD2:
		dcdc_mult = (selector / VDD1_2_NUM_VOLT_FINE) + 1;
		if (dcdc_mult == 1)
			dcdc_mult--;
		vsel = (selector % VDD1_2_NUM_VOLT_FINE) + 3;

		tps65910_reg_update_bits(pmic->mfd, TPS65910_VDD2,
					 VDD1_VGAIN_SEL_MASK,
					 dcdc_mult << VDD2_VGAIN_SEL_SHIFT);
		tps65910_reg_write(pmic->mfd, TPS65910_VDD2_OP, vsel);
		break;
	case TPS65911_REG_VDDCTRL:
		vsel = selector + 3;
		tps65910_reg_write(pmic->mfd, TPS65911_VDDCTRL_OP, vsel);
	}

	return 0;
}

__attribute__((used)) static int tps65910_set_voltage_sel(struct regulator_dev *dev,
				    unsigned selector)
{
	struct tps65910_reg *pmic = rdev_get_drvdata(dev);
	int reg, id = rdev_get_id(dev);

	reg = pmic->get_ctrl_reg(id);
	if (reg < 0)
		return reg;

	switch (id) {
	case TPS65910_REG_VIO:
	case TPS65910_REG_VDIG1:
	case TPS65910_REG_VDIG2:
	case TPS65910_REG_VPLL:
	case TPS65910_REG_VDAC:
	case TPS65910_REG_VAUX1:
	case TPS65910_REG_VAUX2:
	case TPS65910_REG_VAUX33:
	case TPS65910_REG_VMMC:
		return tps65910_reg_update_bits(pmic->mfd, reg, LDO_SEL_MASK,
						selector << LDO_SEL_SHIFT);
	case TPS65910_REG_VBB:
		return tps65910_reg_update_bits(pmic->mfd, reg, BBCH_BBSEL_MASK,
						selector << BBCH_BBSEL_SHIFT);
	}

	return -EINVAL;
}

__attribute__((used)) static int tps65911_set_voltage_sel(struct regulator_dev *dev,
				    unsigned selector)
{
	struct tps65910_reg *pmic = rdev_get_drvdata(dev);
	int reg, id = rdev_get_id(dev);

	reg = pmic->get_ctrl_reg(id);
	if (reg < 0)
		return reg;

	switch (id) {
	case TPS65911_REG_LDO1:
	case TPS65911_REG_LDO2:
	case TPS65911_REG_LDO4:
		return tps65910_reg_update_bits(pmic->mfd, reg, LDO1_SEL_MASK,
						selector << LDO_SEL_SHIFT);
	case TPS65911_REG_LDO3:
	case TPS65911_REG_LDO5:
	case TPS65911_REG_LDO6:
	case TPS65911_REG_LDO7:
	case TPS65911_REG_LDO8:
		return tps65910_reg_update_bits(pmic->mfd, reg, LDO3_SEL_MASK,
						selector << LDO_SEL_SHIFT);
	case TPS65910_REG_VIO:
		return tps65910_reg_update_bits(pmic->mfd, reg, LDO_SEL_MASK,
						selector << LDO_SEL_SHIFT);
	case TPS65910_REG_VBB:
		return tps65910_reg_update_bits(pmic->mfd, reg, BBCH_BBSEL_MASK,
						selector << BBCH_BBSEL_SHIFT);
	}

	return -EINVAL;
}

__attribute__((used)) static int tps65910_list_voltage_dcdc(struct regulator_dev *dev,
					unsigned selector)
{
	int volt, mult = 1, id = rdev_get_id(dev);

	switch (id) {
	case TPS65910_REG_VDD1:
	case TPS65910_REG_VDD2:
		mult = (selector / VDD1_2_NUM_VOLT_FINE) + 1;
		volt = VDD1_2_MIN_VOLT +
			(selector % VDD1_2_NUM_VOLT_FINE) * VDD1_2_OFFSET;
		break;
	case TPS65911_REG_VDDCTRL:
		volt = VDDCTRL_MIN_VOLT + (selector * VDDCTRL_OFFSET);
		break;
	default:
		BUG();
		return -EINVAL;
	}

	return  volt * 100 * mult;
}

__attribute__((used)) static int tps65911_list_voltage(struct regulator_dev *dev, unsigned selector)
{
	struct tps65910_reg *pmic = rdev_get_drvdata(dev);
	int step_mv = 0, id = rdev_get_id(dev);

	switch (id) {
	case TPS65911_REG_LDO1:
	case TPS65911_REG_LDO2:
	case TPS65911_REG_LDO4:
		/* The first 5 values of the selector correspond to 1V */
		if (selector < 5)
			selector = 0;
		else
			selector -= 4;

		step_mv = 50;
		break;
	case TPS65911_REG_LDO3:
	case TPS65911_REG_LDO5:
	case TPS65911_REG_LDO6:
	case TPS65911_REG_LDO7:
	case TPS65911_REG_LDO8:
		/* The first 3 values of the selector correspond to 1V */
		if (selector < 3)
			selector = 0;
		else
			selector -= 2;

		step_mv = 100;
		break;
	case TPS65910_REG_VIO:
		return pmic->info[id]->voltage_table[selector];
	default:
		return -EINVAL;
	}

	return (LDO_MIN_VOLT + selector * step_mv) * 1000;
}

__attribute__((used)) static int tps65910_set_ext_sleep_config(struct tps65910_reg *pmic,
		int id, int ext_sleep_config)
{
	struct tps65910 *mfd = pmic->mfd;
	u8 regoffs = (pmic->ext_sleep_control[id] >> 8) & 0xFF;
	u8 bit_pos = (1 << pmic->ext_sleep_control[id] & 0xFF);
	int ret;

	/*
	 * Regulator can not be control from multiple external input EN1, EN2
	 * and EN3 together.
	 */
	if (ext_sleep_config & EXT_SLEEP_CONTROL) {
		int en_count;
		en_count = ((ext_sleep_config &
				TPS65910_SLEEP_CONTROL_EXT_INPUT_EN1) != 0);
		en_count += ((ext_sleep_config &
				TPS65910_SLEEP_CONTROL_EXT_INPUT_EN2) != 0);
		en_count += ((ext_sleep_config &
				TPS65910_SLEEP_CONTROL_EXT_INPUT_EN3) != 0);
		en_count += ((ext_sleep_config &
				TPS65911_SLEEP_CONTROL_EXT_INPUT_SLEEP) != 0);
		if (en_count > 1) {
			dev_err(mfd->dev,
				"External sleep control flag is not proper\n");
			return -EINVAL;
		}
	}

	pmic->board_ext_control[id] = ext_sleep_config;

	/* External EN1 control */
	if (ext_sleep_config & TPS65910_SLEEP_CONTROL_EXT_INPUT_EN1)
		ret = tps65910_reg_set_bits(mfd,
				TPS65910_EN1_LDO_ASS + regoffs, bit_pos);
	else
		ret = tps65910_reg_clear_bits(mfd,
				TPS65910_EN1_LDO_ASS + regoffs, bit_pos);
	if (ret < 0) {
		dev_err(mfd->dev,
			"Error in configuring external control EN1\n");
		return ret;
	}

	/* External EN2 control */
	if (ext_sleep_config & TPS65910_SLEEP_CONTROL_EXT_INPUT_EN2)
		ret = tps65910_reg_set_bits(mfd,
				TPS65910_EN2_LDO_ASS + regoffs, bit_pos);
	else
		ret = tps65910_reg_clear_bits(mfd,
				TPS65910_EN2_LDO_ASS + regoffs, bit_pos);
	if (ret < 0) {
		dev_err(mfd->dev,
			"Error in configuring external control EN2\n");
		return ret;
	}

	/* External EN3 control for TPS65910 LDO only */
	if ((tps65910_chip_id(mfd) == TPS65910) &&
			(id >= TPS65910_REG_VDIG1)) {
		if (ext_sleep_config & TPS65910_SLEEP_CONTROL_EXT_INPUT_EN3)
			ret = tps65910_reg_set_bits(mfd,
				TPS65910_EN3_LDO_ASS + regoffs, bit_pos);
		else
			ret = tps65910_reg_clear_bits(mfd,
				TPS65910_EN3_LDO_ASS + regoffs, bit_pos);
		if (ret < 0) {
			dev_err(mfd->dev,
				"Error in configuring external control EN3\n");
			return ret;
		}
	}

	/* Return if no external control is selected */
	if (!(ext_sleep_config & EXT_SLEEP_CONTROL)) {
		/* Clear all sleep controls */
		ret = tps65910_reg_clear_bits(mfd,
			TPS65910_SLEEP_KEEP_LDO_ON + regoffs, bit_pos);
		if (!ret)
			ret = tps65910_reg_clear_bits(mfd,
				TPS65910_SLEEP_SET_LDO_OFF + regoffs, bit_pos);
		if (ret < 0)
			dev_err(mfd->dev,
				"Error in configuring SLEEP register\n");
		return ret;
	}

	/*
	 * For regulator that has separate operational and sleep register make
	 * sure that operational is used and clear sleep register to turn
	 * regulator off when external control is inactive
	 */
	if ((id == TPS65910_REG_VDD1) ||
		(id == TPS65910_REG_VDD2) ||
			((id == TPS65911_REG_VDDCTRL) &&
				(tps65910_chip_id(mfd) == TPS65911))) {
		int op_reg_add = pmic->get_ctrl_reg(id) + 1;
		int sr_reg_add = pmic->get_ctrl_reg(id) + 2;
		int opvsel, srvsel;

		ret = tps65910_reg_read(pmic->mfd, op_reg_add, &opvsel);
		if (ret < 0)
			return ret;
		ret = tps65910_reg_read(pmic->mfd, sr_reg_add, &srvsel);
		if (ret < 0)
			return ret;

		if (opvsel & VDD1_OP_CMD_MASK) {
			u8 reg_val = srvsel & VDD1_OP_SEL_MASK;

			ret = tps65910_reg_write(pmic->mfd, op_reg_add,
						 reg_val);
			if (ret < 0) {
				dev_err(mfd->dev,
					"Error in configuring op register\n");
				return ret;
			}
		}
		ret = tps65910_reg_write(pmic->mfd, sr_reg_add, 0);
		if (ret < 0) {
			dev_err(mfd->dev, "Error in setting sr register\n");
			return ret;
		}
	}

	ret = tps65910_reg_clear_bits(mfd,
			TPS65910_SLEEP_KEEP_LDO_ON + regoffs, bit_pos);
	if (!ret) {
		if (ext_sleep_config & TPS65911_SLEEP_CONTROL_EXT_INPUT_SLEEP)
			ret = tps65910_reg_set_bits(mfd,
				TPS65910_SLEEP_SET_LDO_OFF + regoffs, bit_pos);
		else
			ret = tps65910_reg_clear_bits(mfd,
				TPS65910_SLEEP_SET_LDO_OFF + regoffs, bit_pos);
	}
	if (ret < 0)
		dev_err(mfd->dev,
			"Error in configuring SLEEP register\n");

	return ret;
}

__attribute__((used)) static inline struct tps65910_board *tps65910_parse_dt_reg_data(
			struct platform_device *pdev,
			struct of_regulator_match **tps65910_reg_matches)
{
	*tps65910_reg_matches = NULL;
	return NULL;
}

__attribute__((used)) static int tps65910_probe(struct platform_device *pdev)
{
	struct tps65910 *tps65910 = dev_get_drvdata(pdev->dev.parent);
	struct regulator_config config = { };
	struct tps_info *info;
	struct regulator_dev *rdev;
	struct tps65910_reg *pmic;
	struct tps65910_board *pmic_plat_data;
	struct of_regulator_match *tps65910_reg_matches = NULL;
	int i, err;

	pmic_plat_data = dev_get_platdata(tps65910->dev);
	if (!pmic_plat_data && tps65910->dev->of_node)
		pmic_plat_data = tps65910_parse_dt_reg_data(pdev,
						&tps65910_reg_matches);

	if (!pmic_plat_data) {
		dev_err(&pdev->dev, "Platform data not found\n");
		return -EINVAL;
	}

	pmic = devm_kzalloc(&pdev->dev, sizeof(*pmic), GFP_KERNEL);
	if (!pmic)
		return -ENOMEM;

	pmic->mfd = tps65910;
	platform_set_drvdata(pdev, pmic);

	/* Give control of all register to control port */
	tps65910_reg_set_bits(pmic->mfd, TPS65910_DEVCTRL,
				DEVCTRL_SR_CTL_I2C_SEL_MASK);

	switch (tps65910_chip_id(tps65910)) {
	case TPS65910:
		BUILD_BUG_ON(TPS65910_NUM_REGS < ARRAY_SIZE(tps65910_regs));
		pmic->get_ctrl_reg = &tps65910_get_ctrl_register;
		pmic->num_regulators = ARRAY_SIZE(tps65910_regs);
		pmic->ext_sleep_control = tps65910_ext_sleep_control;
		info = tps65910_regs;
		/* Work around silicon erratum SWCZ010: output programmed
		 * voltage level can go higher than expected or crash
		 * Workaround: use no synchronization of DCDC clocks
		 */
		tps65910_reg_clear_bits(pmic->mfd, TPS65910_DCDCCTRL,
					DCDCCTRL_DCDCCKSYNC_MASK);
		break;
	case TPS65911:
		BUILD_BUG_ON(TPS65910_NUM_REGS < ARRAY_SIZE(tps65911_regs));
		pmic->get_ctrl_reg = &tps65911_get_ctrl_register;
		pmic->num_regulators = ARRAY_SIZE(tps65911_regs);
		pmic->ext_sleep_control = tps65911_ext_sleep_control;
		info = tps65911_regs;
		break;
	default:
		dev_err(&pdev->dev, "Invalid tps chip version\n");
		return -ENODEV;
	}

	pmic->desc = devm_kcalloc(&pdev->dev,
				  pmic->num_regulators,
				  sizeof(struct regulator_desc),
				  GFP_KERNEL);
	if (!pmic->desc)
		return -ENOMEM;

	pmic->info = devm_kcalloc(&pdev->dev,
				  pmic->num_regulators,
				  sizeof(struct tps_info *),
				  GFP_KERNEL);
	if (!pmic->info)
		return -ENOMEM;

	pmic->rdev = devm_kcalloc(&pdev->dev,
				  pmic->num_regulators,
				  sizeof(struct regulator_dev *),
				  GFP_KERNEL);
	if (!pmic->rdev)
		return -ENOMEM;

	for (i = 0; i < pmic->num_regulators; i++, info++) {
		/* Register the regulators */
		pmic->info[i] = info;

		pmic->desc[i].name = info->name;
		pmic->desc[i].supply_name = info->vin_name;
		pmic->desc[i].id = i;
		pmic->desc[i].n_voltages = info->n_voltages;
		pmic->desc[i].enable_time = info->enable_time_us;

		if (i == TPS65910_REG_VDD1 || i == TPS65910_REG_VDD2) {
			pmic->desc[i].ops = &tps65910_ops_dcdc;
			pmic->desc[i].n_voltages = VDD1_2_NUM_VOLT_FINE *
							VDD1_2_NUM_VOLT_COARSE;
			pmic->desc[i].ramp_delay = 12500;
		} else if (i == TPS65910_REG_VDD3) {
			if (tps65910_chip_id(tps65910) == TPS65910) {
				pmic->desc[i].ops = &tps65910_ops_vdd3;
				pmic->desc[i].volt_table = info->voltage_table;
			} else {
				pmic->desc[i].ops = &tps65910_ops_dcdc;
				pmic->desc[i].ramp_delay = 5000;
			}
		} else if (i == TPS65910_REG_VBB &&
				tps65910_chip_id(tps65910) == TPS65910) {
			pmic->desc[i].ops = &tps65910_ops_vbb;
			pmic->desc[i].volt_table = info->voltage_table;
		} else {
			if (tps65910_chip_id(tps65910) == TPS65910) {
				pmic->desc[i].ops = &tps65910_ops;
				pmic->desc[i].volt_table = info->voltage_table;
			} else {
				pmic->desc[i].ops = &tps65911_ops;
			}
		}

		err = tps65910_set_ext_sleep_config(pmic, i,
				pmic_plat_data->regulator_ext_sleep_control[i]);
		/*
		 * Failing on regulator for configuring externally control
		 * is not a serious issue, just throw warning.
		 */
		if (err < 0)
			dev_warn(tps65910->dev,
				"Failed to initialise ext control config\n");

		pmic->desc[i].type = REGULATOR_VOLTAGE;
		pmic->desc[i].owner = THIS_MODULE;
		pmic->desc[i].enable_reg = pmic->get_ctrl_reg(i);
		pmic->desc[i].enable_mask = TPS65910_SUPPLY_STATE_ENABLED;

		config.dev = tps65910->dev;
		config.init_data = pmic_plat_data->tps65910_pmic_init_data[i];
		config.driver_data = pmic;
		config.regmap = tps65910->regmap;

		if (tps65910_reg_matches)
			config.of_node = tps65910_reg_matches[i].of_node;

		rdev = devm_regulator_register(&pdev->dev, &pmic->desc[i],
					       &config);
		if (IS_ERR(rdev)) {
			dev_err(tps65910->dev,
				"failed to register %s regulator\n",
				pdev->name);
			return PTR_ERR(rdev);
		}

		/* Save regulator for cleanup */
		pmic->rdev[i] = rdev;
	}
	return 0;
}

__attribute__((used)) static void tps65910_shutdown(struct platform_device *pdev)
{
	struct tps65910_reg *pmic = platform_get_drvdata(pdev);
	int i;

	/*
	 * Before bootloader jumps to kernel, it makes sure that required
	 * external control signals are in desired state so that given rails
	 * can be configure accordingly.
	 * If rails are configured to be controlled from external control
	 * then before shutting down/rebooting the system, the external
	 * control configuration need to be remove from the rails so that
	 * its output will be available as per register programming even
	 * if external controls are removed. This is require when the POR
	 * value of the control signals are not in active state and before
	 * bootloader initializes it, the system requires the rail output
	 * to be active for booting.
	 */
	for (i = 0; i < pmic->num_regulators; i++) {
		int err;
		if (!pmic->rdev[i])
			continue;

		err = tps65910_set_ext_sleep_config(pmic, i, 0);
		if (err < 0)
			dev_err(&pdev->dev,
				"Error in clearing external control\n");
	}
}

