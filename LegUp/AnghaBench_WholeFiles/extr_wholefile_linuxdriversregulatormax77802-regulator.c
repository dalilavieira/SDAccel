#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct TYPE_10__ {int /*<<< orphan*/  parent; } ;
struct regulator_dev {TYPE_1__* desc; int /*<<< orphan*/  regmap; TYPE_3__ dev; } ;
struct regulator_config {struct max77802_regulator_prv* driver_data; int /*<<< orphan*/  regmap; int /*<<< orphan*/  dev; } ;
struct platform_device {TYPE_3__ dev; } ;
struct max77802_regulator_prv {unsigned int* opmode; } ;
struct max77686_dev {int /*<<< orphan*/  regmap; int /*<<< orphan*/  dev; } ;
struct TYPE_9__ {int id; int /*<<< orphan*/  enable_reg; } ;
struct TYPE_8__ {int name; int /*<<< orphan*/  enable_reg; int /*<<< orphan*/  enable_mask; } ;

/* Variables and functions */
 int ARRAY_SIZE (unsigned int*) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct regulator_dev*) ; 
 int MAX77802_BUCK1 ; 
 int MAX77802_BUCK10 ; 
 int MAX77802_BUCK2 ; 
 int MAX77802_BUCK4 ; 
 int MAX77802_BUCK5 ; 
 int MAX77802_LDO1 ; 
 int MAX77802_LDO35 ; 
 unsigned int MAX77802_LP_PWRREQ ; 
 unsigned int MAX77802_OFF_PWRREQ ; 
 int MAX77802_OPMODE_BUCK234_SHIFT ; 
 unsigned int MAX77802_OPMODE_LP ; 
 int MAX77802_OPMODE_MASK ; 
 unsigned int MAX77802_OPMODE_NORMAL ; 
 int MAX77802_OPMODE_SHIFT_LDO ; 
 int /*<<< orphan*/  MAX77802_RAMP_RATE_MASK_2BIT ; 
 int /*<<< orphan*/  MAX77802_RAMP_RATE_MASK_4BIT ; 
 unsigned int MAX77802_RAMP_RATE_SHIFT_2BIT ; 
 unsigned int MAX77802_RAMP_RATE_SHIFT_4BIT ; 
 int MAX77802_REG_MAX ; 
 int MAX77802_STATUS_OFF ; 
 int PTR_ERR (struct regulator_dev*) ; 
#define  REGULATOR_MODE_NORMAL 129 
#define  REGULATOR_MODE_STANDBY 128 
 int /*<<< orphan*/  dev_err (TYPE_3__*,char*,int,int) ; 
 struct max77686_dev* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_warn (TYPE_3__*,char*,int,...) ; 
 struct max77802_regulator_prv* devm_kzalloc (TYPE_3__*,int,int /*<<< orphan*/ ) ; 
 struct regulator_dev* devm_regulator_register (TYPE_3__*,TYPE_2__*,struct regulator_config*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct max77802_regulator_prv*) ; 
 unsigned int* ramp_table_77802_2bit ; 
 unsigned int* ramp_table_77802_4bit ; 
 struct max77802_regulator_prv* rdev_get_drvdata (struct regulator_dev*) ; 
 int rdev_get_id (struct regulator_dev*) ; 
 int regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int) ; 
 TYPE_2__* regulators ; 

__attribute__((used)) static inline unsigned int max77802_map_mode(unsigned int mode)
{
	return mode == MAX77802_OPMODE_NORMAL ?
		REGULATOR_MODE_NORMAL : REGULATOR_MODE_STANDBY;
}

__attribute__((used)) static int max77802_get_opmode_shift(int id)
{
	if (id == MAX77802_BUCK1 || (id >= MAX77802_BUCK5 &&
				     id <= MAX77802_BUCK10))
		return 0;

	if (id >= MAX77802_BUCK2 && id <= MAX77802_BUCK4)
		return MAX77802_OPMODE_BUCK234_SHIFT;

	if (id >= MAX77802_LDO1 && id <= MAX77802_LDO35)
		return MAX77802_OPMODE_SHIFT_LDO;

	return -EINVAL;
}

__attribute__((used)) static int max77802_set_suspend_disable(struct regulator_dev *rdev)
{
	unsigned int val = MAX77802_OFF_PWRREQ;
	struct max77802_regulator_prv *max77802 = rdev_get_drvdata(rdev);
	int id = rdev_get_id(rdev);
	int shift = max77802_get_opmode_shift(id);

	max77802->opmode[id] = val;
	return regmap_update_bits(rdev->regmap, rdev->desc->enable_reg,
				  rdev->desc->enable_mask, val << shift);
}

__attribute__((used)) static int max77802_set_mode(struct regulator_dev *rdev, unsigned int mode)
{
	struct max77802_regulator_prv *max77802 = rdev_get_drvdata(rdev);
	int id = rdev_get_id(rdev);
	unsigned int val;
	int shift = max77802_get_opmode_shift(id);

	switch (mode) {
	case REGULATOR_MODE_STANDBY:
		val = MAX77802_OPMODE_LP;	/* ON in Low Power Mode */
		break;
	case REGULATOR_MODE_NORMAL:
		val = MAX77802_OPMODE_NORMAL;	/* ON in Normal Mode */
		break;
	default:
		dev_warn(&rdev->dev, "%s: regulator mode: 0x%x not supported\n",
			 rdev->desc->name, mode);
		return -EINVAL;
	}

	max77802->opmode[id] = val;
	return regmap_update_bits(rdev->regmap, rdev->desc->enable_reg,
				  rdev->desc->enable_mask, val << shift);
}

__attribute__((used)) static unsigned max77802_get_mode(struct regulator_dev *rdev)
{
	struct max77802_regulator_prv *max77802 = rdev_get_drvdata(rdev);
	int id = rdev_get_id(rdev);

	return max77802_map_mode(max77802->opmode[id]);
}

__attribute__((used)) static int max77802_set_suspend_mode(struct regulator_dev *rdev,
				     unsigned int mode)
{
	struct max77802_regulator_prv *max77802 = rdev_get_drvdata(rdev);
	int id = rdev_get_id(rdev);
	unsigned int val;
	int shift = max77802_get_opmode_shift(id);

	/*
	 * If the regulator has been disabled for suspend
	 * then is invalid to try setting a suspend mode.
	 */
	if (max77802->opmode[id] == MAX77802_OFF_PWRREQ) {
		dev_warn(&rdev->dev, "%s: is disabled, mode: 0x%x not set\n",
			 rdev->desc->name, mode);
		return 0;
	}

	switch (mode) {
	case REGULATOR_MODE_STANDBY:
		/*
		 * If the regulator opmode is normal then enable
		 * ON in Low Power Mode by PWRREQ. If the mode is
		 * already Low Power then no action is required.
		 */
		if (max77802->opmode[id] == MAX77802_OPMODE_NORMAL)
			val = MAX77802_LP_PWRREQ;
		else
			return 0;
		break;
	case REGULATOR_MODE_NORMAL:
		/*
		 * If the regulator operating mode is Low Power then
		 * normal is not a valid opmode in suspend. If the
		 * mode is already normal then no action is required.
		 */
		if (max77802->opmode[id] == MAX77802_OPMODE_LP)
			dev_warn(&rdev->dev, "%s: in Low Power: 0x%x invalid\n",
				 rdev->desc->name, mode);
		return 0;
	default:
		dev_warn(&rdev->dev, "%s: regulator mode: 0x%x not supported\n",
			 rdev->desc->name, mode);
		return -EINVAL;
	}

	return regmap_update_bits(rdev->regmap, rdev->desc->enable_reg,
				  rdev->desc->enable_mask, val << shift);
}

__attribute__((used)) static int max77802_enable(struct regulator_dev *rdev)
{
	struct max77802_regulator_prv *max77802 = rdev_get_drvdata(rdev);
	int id = rdev_get_id(rdev);
	int shift = max77802_get_opmode_shift(id);

	if (max77802->opmode[id] == MAX77802_OFF_PWRREQ)
		max77802->opmode[id] = MAX77802_OPMODE_NORMAL;

	return regmap_update_bits(rdev->regmap, rdev->desc->enable_reg,
				  rdev->desc->enable_mask,
				  max77802->opmode[id] << shift);
}

__attribute__((used)) static int max77802_find_ramp_value(struct regulator_dev *rdev,
				    const unsigned int limits[], int size,
				    unsigned int ramp_delay)
{
	int i;

	for (i = 0; i < size; i++) {
		if (ramp_delay <= limits[i])
			return i;
	}

	/* Use maximum value for no ramp control */
	dev_warn(&rdev->dev, "%s: ramp_delay: %d not supported, setting 100000\n",
		 rdev->desc->name, ramp_delay);
	return size - 1;
}

__attribute__((used)) static int max77802_set_ramp_delay_2bit(struct regulator_dev *rdev,
					int ramp_delay)
{
	int id = rdev_get_id(rdev);
	unsigned int ramp_value;

	if (id > MAX77802_BUCK4) {
			dev_warn(&rdev->dev,
				 "%s: regulator: ramp delay not supported\n",
				 rdev->desc->name);
		return -EINVAL;
	}
	ramp_value = max77802_find_ramp_value(rdev, ramp_table_77802_2bit,
				ARRAY_SIZE(ramp_table_77802_2bit), ramp_delay);

	return regmap_update_bits(rdev->regmap, rdev->desc->enable_reg,
				  MAX77802_RAMP_RATE_MASK_2BIT,
				  ramp_value << MAX77802_RAMP_RATE_SHIFT_2BIT);
}

__attribute__((used)) static int max77802_set_ramp_delay_4bit(struct regulator_dev *rdev,
					    int ramp_delay)
{
	unsigned int ramp_value;

	ramp_value = max77802_find_ramp_value(rdev, ramp_table_77802_4bit,
				ARRAY_SIZE(ramp_table_77802_4bit), ramp_delay);

	return regmap_update_bits(rdev->regmap, rdev->desc->enable_reg,
				  MAX77802_RAMP_RATE_MASK_4BIT,
				  ramp_value << MAX77802_RAMP_RATE_SHIFT_4BIT);
}

__attribute__((used)) static int max77802_pmic_probe(struct platform_device *pdev)
{
	struct max77686_dev *iodev = dev_get_drvdata(pdev->dev.parent);
	struct max77802_regulator_prv *max77802;
	int i, val;
	struct regulator_config config = { };

	max77802 = devm_kzalloc(&pdev->dev,
				sizeof(struct max77802_regulator_prv),
				GFP_KERNEL);
	if (!max77802)
		return -ENOMEM;

	config.dev = iodev->dev;
	config.regmap = iodev->regmap;
	config.driver_data = max77802;
	platform_set_drvdata(pdev, max77802);

	for (i = 0; i < MAX77802_REG_MAX; i++) {
		struct regulator_dev *rdev;
		int id = regulators[i].id;
		int shift = max77802_get_opmode_shift(id);
		int ret;

		ret = regmap_read(iodev->regmap, regulators[i].enable_reg, &val);
		if (ret < 0) {
			dev_warn(&pdev->dev,
				"cannot read current mode for %d\n", i);
			val = MAX77802_OPMODE_NORMAL;
		} else {
			val = val >> shift & MAX77802_OPMODE_MASK;
		}

		/*
		 * If the regulator is disabled and the system warm rebooted,
		 * the hardware reports OFF as the regulator operating mode.
		 * Default to operating mode NORMAL in that case.
		 */
		if (val == MAX77802_STATUS_OFF)
			max77802->opmode[id] = MAX77802_OPMODE_NORMAL;
		else
			max77802->opmode[id] = val;

		rdev = devm_regulator_register(&pdev->dev,
					       &regulators[i], &config);
		if (IS_ERR(rdev)) {
			ret = PTR_ERR(rdev);
			dev_err(&pdev->dev,
				"regulator init failed for %d: %d\n", i, ret);
			return ret;
		}
	}

	return 0;
}

