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
struct regulator_dev {int /*<<< orphan*/  mutex; } ;
struct regulator_config {scalar_t__ of_node; struct regulator_dev* regmap; struct da9210* driver_data; int /*<<< orphan*/ * init_data; struct device* dev; } ;
struct of_device_id {int dummy; } ;
struct i2c_device_id {int dummy; } ;
struct device {scalar_t__ of_node; } ;
struct i2c_client {int irq; struct device dev; } ;
struct da9210_pdata {int /*<<< orphan*/  da9210_constraints; } ;
struct da9210 {struct regulator_dev* regmap; struct regulator_dev* rdev; } ;
typedef  int irqreturn_t ;

/* Variables and functions */
 int ARRAY_SIZE (int*) ; 
 unsigned int DA9210_BUCK_ILIM_MASK ; 
 unsigned int DA9210_BUCK_ILIM_SHIFT ; 
 unsigned int DA9210_E_NPWRGOOD ; 
 unsigned int DA9210_E_OVCURR ; 
 unsigned int DA9210_E_TEMP_CRIT ; 
 unsigned int DA9210_E_TEMP_WARN ; 
 unsigned int DA9210_E_VMAX ; 
 unsigned int DA9210_M_NPWRGOOD ; 
 unsigned int DA9210_M_OVCURR ; 
 unsigned int DA9210_M_TEMP_CRIT ; 
 unsigned int DA9210_M_TEMP_WARN ; 
 unsigned int DA9210_M_VMAX ; 
 int /*<<< orphan*/  DA9210_REG_BUCK_ILIM ; 
 int /*<<< orphan*/  DA9210_REG_EVENT_B ; 
 int /*<<< orphan*/  DA9210_REG_MASK_A ; 
 int /*<<< orphan*/  DA9210_REG_MASK_B ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int IRQF_ONESHOT ; 
 int IRQF_SHARED ; 
 int IRQF_TRIGGER_LOW ; 
 int IRQ_HANDLED ; 
 int IRQ_NONE ; 
 scalar_t__ IS_ERR (struct regulator_dev*) ; 
 int PTR_ERR (struct regulator_dev*) ; 
 int /*<<< orphan*/  REGULATOR_EVENT_OVER_CURRENT ; 
 int /*<<< orphan*/  REGULATOR_EVENT_OVER_TEMP ; 
 int /*<<< orphan*/  REGULATOR_EVENT_REGULATION_OUT ; 
 int /*<<< orphan*/  REGULATOR_EVENT_UNDER_VOLTAGE ; 
 int* da9210_buck_limits ; 
 int /*<<< orphan*/  da9210_dt_ids ; 
 int /*<<< orphan*/  da9210_reg ; 
 int /*<<< orphan*/  da9210_regmap_config ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct da9210_pdata* dev_get_platdata (struct device*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*) ; 
 struct da9210* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 struct regulator_dev* devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 struct regulator_dev* devm_regulator_register (struct device*,int /*<<< orphan*/ *,struct regulator_config*) ; 
 int devm_request_threaded_irq (struct device*,int,int /*<<< orphan*/ *,int (*) (int,void*),int,char*,struct da9210*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct da9210*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * of_get_regulator_init_data (struct device*,scalar_t__,int /*<<< orphan*/ *) ; 
 struct of_device_id* of_match_device (int /*<<< orphan*/ ,struct device*) ; 
 int /*<<< orphan*/  of_match_ptr (int /*<<< orphan*/ ) ; 
 struct da9210* rdev_get_drvdata (struct regulator_dev*) ; 
 struct device* regmap_get_device (struct regulator_dev*) ; 
 int regmap_read (struct regulator_dev*,int /*<<< orphan*/ ,unsigned int*) ; 
 int regmap_update_bits (struct regulator_dev*,int /*<<< orphan*/ ,unsigned int,unsigned int) ; 
 int regmap_write (struct regulator_dev*,int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  regulator_notifier_call_chain (struct regulator_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int da9210_set_current_limit(struct regulator_dev *rdev, int min_uA,
				    int max_uA)
{
	struct da9210 *chip = rdev_get_drvdata(rdev);
	unsigned int sel;
	int i;

	/* search for closest to maximum */
	for (i = ARRAY_SIZE(da9210_buck_limits)-1; i >= 0; i--) {
		if (min_uA <= da9210_buck_limits[i] &&
		    max_uA >= da9210_buck_limits[i]) {
			sel = i;
			sel = sel << DA9210_BUCK_ILIM_SHIFT;
			return regmap_update_bits(chip->regmap,
						  DA9210_REG_BUCK_ILIM,
						  DA9210_BUCK_ILIM_MASK, sel);
		}
	}

	return -EINVAL;
}

__attribute__((used)) static int da9210_get_current_limit(struct regulator_dev *rdev)
{
	struct da9210 *chip = rdev_get_drvdata(rdev);
	unsigned int data;
	unsigned int sel;
	int ret;

	ret = regmap_read(chip->regmap, DA9210_REG_BUCK_ILIM, &data);
	if (ret < 0)
		return ret;

	/* select one of 16 values: 0000 (1600mA) to 1111 (4600mA) */
	sel = (data & DA9210_BUCK_ILIM_MASK) >> DA9210_BUCK_ILIM_SHIFT;

	return da9210_buck_limits[sel];
}

__attribute__((used)) static irqreturn_t da9210_irq_handler(int irq, void *data)
{
	struct da9210 *chip = data;
	unsigned int val, handled = 0;
	int error, ret = IRQ_NONE;

	error = regmap_read(chip->regmap, DA9210_REG_EVENT_B, &val);
	if (error < 0)
		goto error_i2c;

	mutex_lock(&chip->rdev->mutex);

	if (val & DA9210_E_OVCURR) {
		regulator_notifier_call_chain(chip->rdev,
					      REGULATOR_EVENT_OVER_CURRENT,
					      NULL);
		handled |= DA9210_E_OVCURR;
	}
	if (val & DA9210_E_NPWRGOOD) {
		regulator_notifier_call_chain(chip->rdev,
					      REGULATOR_EVENT_UNDER_VOLTAGE,
					      NULL);
		handled |= DA9210_E_NPWRGOOD;
	}
	if (val & (DA9210_E_TEMP_WARN | DA9210_E_TEMP_CRIT)) {
		regulator_notifier_call_chain(chip->rdev,
					      REGULATOR_EVENT_OVER_TEMP, NULL);
		handled |= val & (DA9210_E_TEMP_WARN | DA9210_E_TEMP_CRIT);
	}
	if (val & DA9210_E_VMAX) {
		regulator_notifier_call_chain(chip->rdev,
					      REGULATOR_EVENT_REGULATION_OUT,
					      NULL);
		handled |= DA9210_E_VMAX;
	}

	mutex_unlock(&chip->rdev->mutex);

	if (handled) {
		/* Clear handled events */
		error = regmap_write(chip->regmap, DA9210_REG_EVENT_B, handled);
		if (error < 0)
			goto error_i2c;

		ret = IRQ_HANDLED;
	}

	return ret;

error_i2c:
	dev_err(regmap_get_device(chip->regmap), "I2C error : %d\n", error);
	return ret;
}

__attribute__((used)) static int da9210_i2c_probe(struct i2c_client *i2c,
			    const struct i2c_device_id *id)
{
	struct da9210 *chip;
	struct device *dev = &i2c->dev;
	struct da9210_pdata *pdata = dev_get_platdata(dev);
	struct regulator_dev *rdev = NULL;
	struct regulator_config config = { };
	int error;
	const struct of_device_id *match;

	if (i2c->dev.of_node && !pdata) {
		match = of_match_device(of_match_ptr(da9210_dt_ids),
						&i2c->dev);
		if (!match) {
			dev_err(&i2c->dev, "Error: No device match found\n");
			return -ENODEV;
		}
	}

	chip = devm_kzalloc(&i2c->dev, sizeof(struct da9210), GFP_KERNEL);
	if (!chip)
		return -ENOMEM;

	chip->regmap = devm_regmap_init_i2c(i2c, &da9210_regmap_config);
	if (IS_ERR(chip->regmap)) {
		error = PTR_ERR(chip->regmap);
		dev_err(&i2c->dev, "Failed to allocate register map: %d\n",
			error);
		return error;
	}

	config.dev = &i2c->dev;
	config.init_data = pdata ? &pdata->da9210_constraints :
		of_get_regulator_init_data(dev, dev->of_node, &da9210_reg);
	config.driver_data = chip;
	config.regmap = chip->regmap;
	config.of_node = dev->of_node;

	/* Mask all interrupt sources to deassert interrupt line */
	error = regmap_write(chip->regmap, DA9210_REG_MASK_A, ~0);
	if (!error)
		error = regmap_write(chip->regmap, DA9210_REG_MASK_B, ~0);
	if (error) {
		dev_err(&i2c->dev, "Failed to write to mask reg: %d\n", error);
		return error;
	}

	rdev = devm_regulator_register(&i2c->dev, &da9210_reg, &config);
	if (IS_ERR(rdev)) {
		dev_err(&i2c->dev, "Failed to register DA9210 regulator\n");
		return PTR_ERR(rdev);
	}

	chip->rdev = rdev;
	if (i2c->irq) {
		error = devm_request_threaded_irq(&i2c->dev, i2c->irq, NULL,
						  da9210_irq_handler,
						  IRQF_TRIGGER_LOW |
						  IRQF_ONESHOT | IRQF_SHARED,
						  "da9210", chip);
		if (error) {
			dev_err(&i2c->dev, "Failed to request IRQ%u: %d\n",
				i2c->irq, error);
			return error;
		}

		error = regmap_update_bits(chip->regmap, DA9210_REG_MASK_B,
					 DA9210_M_OVCURR | DA9210_M_NPWRGOOD |
					 DA9210_M_TEMP_WARN |
					 DA9210_M_TEMP_CRIT | DA9210_M_VMAX, 0);
		if (error < 0) {
			dev_err(&i2c->dev, "Failed to update mask reg: %d\n",
				error);
			return error;
		}
	} else {
		dev_warn(&i2c->dev, "No IRQ configured\n");
	}

	i2c_set_clientdata(i2c, chip);

	return 0;
}

