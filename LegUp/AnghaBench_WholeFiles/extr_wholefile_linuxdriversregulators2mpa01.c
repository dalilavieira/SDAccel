#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_8__ ;
typedef  struct TYPE_13__   TYPE_4__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
struct sec_pmic_dev {int /*<<< orphan*/  regmap_pmic; TYPE_8__* dev; } ;
struct sec_platform_data {TYPE_1__* regulators; } ;
struct s2mpa01_info {unsigned int ramp_delay24; unsigned int ramp_delay3; unsigned int ramp_delay5; unsigned int ramp_delay16; unsigned int ramp_delay7; unsigned int ramp_delay8910; struct of_regulator_match* rdata; } ;
struct regulator_dev {int /*<<< orphan*/  regmap; int /*<<< orphan*/  dev; TYPE_2__* desc; } ;
struct regulator_config {int /*<<< orphan*/  of_node; int /*<<< orphan*/  init_data; struct s2mpa01_info* driver_data; int /*<<< orphan*/  regmap; TYPE_4__* dev; } ;
struct TYPE_13__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_4__ dev; } ;
struct of_regulator_match {int /*<<< orphan*/  of_node; int /*<<< orphan*/  init_data; int /*<<< orphan*/  name; } ;
struct device_node {int dummy; } ;
struct TYPE_14__ {scalar_t__ of_node; } ;
struct TYPE_12__ {int /*<<< orphan*/  name; } ;
struct TYPE_11__ {unsigned int ramp_delay; unsigned int min_uV; unsigned int uV_step; } ;
struct TYPE_10__ {int /*<<< orphan*/  initdata; } ;

/* Variables and functions */
 int DIV_ROUND_UP (int /*<<< orphan*/ ,unsigned int) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct regulator_dev*) ; 
 int PTR_ERR (struct regulator_dev*) ; 
#define  S2MPA01_BUCK1 137 
#define  S2MPA01_BUCK10 136 
 unsigned int S2MPA01_BUCK16_RAMP_SHIFT ; 
 unsigned int S2MPA01_BUCK1_RAMP_EN_SHIFT ; 
#define  S2MPA01_BUCK2 135 
 unsigned int S2MPA01_BUCK24_RAMP_SHIFT ; 
 unsigned int S2MPA01_BUCK2_RAMP_EN_SHIFT ; 
#define  S2MPA01_BUCK3 134 
 unsigned int S2MPA01_BUCK3_RAMP_EN_SHIFT ; 
 unsigned int S2MPA01_BUCK3_RAMP_SHIFT ; 
#define  S2MPA01_BUCK4 133 
 unsigned int S2MPA01_BUCK4_RAMP_EN_SHIFT ; 
#define  S2MPA01_BUCK5 132 
 unsigned int S2MPA01_BUCK5_RAMP_SHIFT ; 
#define  S2MPA01_BUCK6 131 
#define  S2MPA01_BUCK7 130 
 unsigned int S2MPA01_BUCK7_RAMP_SHIFT ; 
#define  S2MPA01_BUCK8 129 
 unsigned int S2MPA01_BUCK8910_RAMP_SHIFT ; 
#define  S2MPA01_BUCK9 128 
 int S2MPA01_REGULATOR_CNT ; 
 int S2MPA01_REGULATOR_MAX ; 
 unsigned int S2MPA01_REG_RAMP1 ; 
 unsigned int S2MPA01_REG_RAMP2 ; 
 int /*<<< orphan*/  abs (int) ; 
 int /*<<< orphan*/  dev_err (TYPE_4__*,char*,...) ; 
 struct sec_pmic_dev* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 struct sec_platform_data* dev_get_platdata (TYPE_8__*) ; 
 struct s2mpa01_info* devm_kzalloc (TYPE_4__*,int,int /*<<< orphan*/ ) ; 
 struct regulator_dev* devm_regulator_register (TYPE_4__*,TYPE_3__*,struct regulator_config*) ; 
 struct device_node* of_get_child_by_name (scalar_t__,char*) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 int /*<<< orphan*/  of_regulator_match (TYPE_4__*,struct device_node*,struct of_regulator_match*,int) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct s2mpa01_info*) ; 
 struct s2mpa01_info* rdev_get_drvdata (struct regulator_dev*) ; 
 int const rdev_get_id (struct regulator_dev*) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,unsigned int,int,unsigned int) ; 
 TYPE_3__* regulators ; 

__attribute__((used)) static int get_ramp_delay(int ramp_delay)
{
	unsigned char cnt = 0;

	ramp_delay /= 6250;

	while (true) {
		ramp_delay = ramp_delay >> 1;
		if (ramp_delay == 0)
			break;
		cnt++;
	}

	if (cnt > 3)
		cnt = 3;

	return cnt;
}

__attribute__((used)) static int s2mpa01_regulator_set_voltage_time_sel(struct regulator_dev *rdev,
				   unsigned int old_selector,
				   unsigned int new_selector)
{
	struct s2mpa01_info *s2mpa01 = rdev_get_drvdata(rdev);
	unsigned int ramp_delay = 0;
	int old_volt, new_volt;

	switch (rdev_get_id(rdev)) {
	case S2MPA01_BUCK2:
	case S2MPA01_BUCK4:
		ramp_delay = s2mpa01->ramp_delay24;
		break;
	case S2MPA01_BUCK3:
		ramp_delay = s2mpa01->ramp_delay3;
		break;
	case S2MPA01_BUCK5:
		ramp_delay = s2mpa01->ramp_delay5;
		break;
	case S2MPA01_BUCK1:
	case S2MPA01_BUCK6:
		ramp_delay = s2mpa01->ramp_delay16;
		break;
	case S2MPA01_BUCK7:
		ramp_delay = s2mpa01->ramp_delay7;
		break;
	case S2MPA01_BUCK8:
	case S2MPA01_BUCK9:
	case S2MPA01_BUCK10:
		ramp_delay = s2mpa01->ramp_delay8910;
		break;
	}

	if (ramp_delay == 0)
		ramp_delay = rdev->desc->ramp_delay;

	old_volt = rdev->desc->min_uV + (rdev->desc->uV_step * old_selector);
	new_volt = rdev->desc->min_uV + (rdev->desc->uV_step * new_selector);

	return DIV_ROUND_UP(abs(new_volt - old_volt), ramp_delay);
}

__attribute__((used)) static int s2mpa01_set_ramp_delay(struct regulator_dev *rdev, int ramp_delay)
{
	struct s2mpa01_info *s2mpa01 = rdev_get_drvdata(rdev);
	unsigned int ramp_val, ramp_shift, ramp_reg = S2MPA01_REG_RAMP2;
	unsigned int ramp_enable = 1, enable_shift = 0;
	int ret;

	switch (rdev_get_id(rdev)) {
	case S2MPA01_BUCK1:
		enable_shift = S2MPA01_BUCK1_RAMP_EN_SHIFT;
		if (!ramp_delay) {
			ramp_enable = 0;
			break;
		}

		if (ramp_delay > s2mpa01->ramp_delay16)
			s2mpa01->ramp_delay16 = ramp_delay;
		else
			ramp_delay = s2mpa01->ramp_delay16;

		ramp_shift = S2MPA01_BUCK16_RAMP_SHIFT;
		break;
	case S2MPA01_BUCK2:
		enable_shift = S2MPA01_BUCK2_RAMP_EN_SHIFT;
		if (!ramp_delay) {
			ramp_enable = 0;
			break;
		}

		if (ramp_delay > s2mpa01->ramp_delay24)
			s2mpa01->ramp_delay24 = ramp_delay;
		else
			ramp_delay = s2mpa01->ramp_delay24;

		ramp_shift = S2MPA01_BUCK24_RAMP_SHIFT;
		ramp_reg = S2MPA01_REG_RAMP1;
		break;
	case S2MPA01_BUCK3:
		enable_shift = S2MPA01_BUCK3_RAMP_EN_SHIFT;
		if (!ramp_delay) {
			ramp_enable = 0;
			break;
		}

		s2mpa01->ramp_delay3 = ramp_delay;
		ramp_shift = S2MPA01_BUCK3_RAMP_SHIFT;
		ramp_reg = S2MPA01_REG_RAMP1;
		break;
	case S2MPA01_BUCK4:
		enable_shift = S2MPA01_BUCK4_RAMP_EN_SHIFT;
		if (!ramp_delay) {
			ramp_enable = 0;
			break;
		}

		if (ramp_delay > s2mpa01->ramp_delay24)
			s2mpa01->ramp_delay24 = ramp_delay;
		else
			ramp_delay = s2mpa01->ramp_delay24;

		ramp_shift = S2MPA01_BUCK24_RAMP_SHIFT;
		ramp_reg = S2MPA01_REG_RAMP1;
		break;
	case S2MPA01_BUCK5:
		s2mpa01->ramp_delay5 = ramp_delay;
		ramp_shift = S2MPA01_BUCK5_RAMP_SHIFT;
		break;
	case S2MPA01_BUCK6:
		if (ramp_delay > s2mpa01->ramp_delay16)
			s2mpa01->ramp_delay16 = ramp_delay;
		else
			ramp_delay = s2mpa01->ramp_delay16;

		ramp_shift = S2MPA01_BUCK16_RAMP_SHIFT;
		break;
	case S2MPA01_BUCK7:
		s2mpa01->ramp_delay7 = ramp_delay;
		ramp_shift = S2MPA01_BUCK7_RAMP_SHIFT;
		break;
	case S2MPA01_BUCK8:
	case S2MPA01_BUCK9:
	case S2MPA01_BUCK10:
		if (ramp_delay > s2mpa01->ramp_delay8910)
			s2mpa01->ramp_delay8910 = ramp_delay;
		else
			ramp_delay = s2mpa01->ramp_delay8910;

		ramp_shift = S2MPA01_BUCK8910_RAMP_SHIFT;
		break;
	default:
		return 0;
	}

	if (!ramp_enable)
		goto ramp_disable;

	/* Ramp delay can be enabled/disabled only for buck[1234] */
	if (rdev_get_id(rdev) >= S2MPA01_BUCK1 &&
			rdev_get_id(rdev) <= S2MPA01_BUCK4) {
		ret = regmap_update_bits(rdev->regmap, S2MPA01_REG_RAMP1,
					 1 << enable_shift, 1 << enable_shift);
		if (ret) {
			dev_err(&rdev->dev, "failed to enable ramp rate\n");
			return ret;
		}
	}

	ramp_val = get_ramp_delay(ramp_delay);

	return regmap_update_bits(rdev->regmap, ramp_reg, 0x3 << ramp_shift,
				  ramp_val << ramp_shift);

ramp_disable:
	return regmap_update_bits(rdev->regmap, S2MPA01_REG_RAMP1,
				  1 << enable_shift, 0);
}

__attribute__((used)) static int s2mpa01_pmic_probe(struct platform_device *pdev)
{
	struct sec_pmic_dev *iodev = dev_get_drvdata(pdev->dev.parent);
	struct sec_platform_data *pdata = dev_get_platdata(iodev->dev);
	struct device_node *reg_np = NULL;
	struct regulator_config config = { };
	struct of_regulator_match *rdata;
	struct s2mpa01_info *s2mpa01;
	int i;

	s2mpa01 = devm_kzalloc(&pdev->dev, sizeof(*s2mpa01), GFP_KERNEL);
	if (!s2mpa01)
		return -ENOMEM;

	rdata = s2mpa01->rdata;
	for (i = 0; i < S2MPA01_REGULATOR_CNT; i++)
		rdata[i].name = regulators[i].name;

	if (iodev->dev->of_node) {
		reg_np = of_get_child_by_name(iodev->dev->of_node,
							"regulators");
		if (!reg_np) {
			dev_err(&pdev->dev,
				"could not find regulators sub-node\n");
			return -EINVAL;
		}

		of_regulator_match(&pdev->dev, reg_np, rdata,
						S2MPA01_REGULATOR_MAX);
		of_node_put(reg_np);
	}

	platform_set_drvdata(pdev, s2mpa01);

	config.dev = &pdev->dev;
	config.regmap = iodev->regmap_pmic;
	config.driver_data = s2mpa01;

	for (i = 0; i < S2MPA01_REGULATOR_MAX; i++) {
		struct regulator_dev *rdev;
		if (pdata)
			config.init_data = pdata->regulators[i].initdata;
		else
			config.init_data = rdata[i].init_data;

		if (reg_np)
			config.of_node = rdata[i].of_node;

		rdev = devm_regulator_register(&pdev->dev,
						&regulators[i], &config);
		if (IS_ERR(rdev)) {
			dev_err(&pdev->dev, "regulator init failed for %d\n",
				i);
			return PTR_ERR(rdev);
		}
	}

	return 0;
}

