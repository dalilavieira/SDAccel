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
struct max77693_dev {int /*<<< orphan*/  irq_data_topsys; int /*<<< orphan*/  irq; int /*<<< orphan*/ * dev; void* regmap; int /*<<< orphan*/  type; struct i2c_client* i2c; struct i2c_client* i2c_chg; void* regmap_chg; } ;
struct i2c_device_id {int /*<<< orphan*/  driver_data; } ;
struct i2c_client {int /*<<< orphan*/  dev; int /*<<< orphan*/  irq; int /*<<< orphan*/  adapter; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  I2C_ADDR_CHG ; 
 int IRQF_ONESHOT ; 
 int IRQF_SHARED ; 
 int IRQF_TRIGGER_LOW ; 
 scalar_t__ IS_ERR (void*) ; 
 scalar_t__ MAX77843_INTSRC_MASK_MASK ; 
 int /*<<< orphan*/  MAX77843_SYS_REG_INTSRCMASK ; 
 int /*<<< orphan*/  MAX77843_SYS_REG_PMICID ; 
 int PTR_ERR (void*) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,unsigned int) ; 
 int /*<<< orphan*/  device_init_wakeup (int /*<<< orphan*/ *,int) ; 
 struct max77693_dev* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 void* devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 struct i2c_client* i2c_new_dummy (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct max77693_dev*) ; 
 int /*<<< orphan*/  i2c_unregister_device (struct i2c_client*) ; 
 int /*<<< orphan*/  max77843_charger_regmap_config ; 
 int /*<<< orphan*/  max77843_devs ; 
 int /*<<< orphan*/  max77843_irq_chip ; 
 int /*<<< orphan*/  max77843_regmap_config ; 
 int mfd_add_devices (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int regmap_add_irq_chip (void*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  regmap_del_irq_chip (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int regmap_read (void*,int /*<<< orphan*/ ,unsigned int*) ; 
 int regmap_update_bits (void*,int /*<<< orphan*/ ,scalar_t__,unsigned int) ; 

__attribute__((used)) static int max77843_chg_init(struct max77693_dev *max77843)
{
	int ret;

	max77843->i2c_chg = i2c_new_dummy(max77843->i2c->adapter, I2C_ADDR_CHG);
	if (!max77843->i2c_chg) {
		dev_err(&max77843->i2c->dev,
				"Cannot allocate I2C device for Charger\n");
		return -ENODEV;
	}
	i2c_set_clientdata(max77843->i2c_chg, max77843);

	max77843->regmap_chg = devm_regmap_init_i2c(max77843->i2c_chg,
			&max77843_charger_regmap_config);
	if (IS_ERR(max77843->regmap_chg)) {
		ret = PTR_ERR(max77843->regmap_chg);
		goto err_chg_i2c;
	}

	return 0;

err_chg_i2c:
	i2c_unregister_device(max77843->i2c_chg);

	return ret;
}

__attribute__((used)) static int max77843_probe(struct i2c_client *i2c,
			  const struct i2c_device_id *id)
{
	struct max77693_dev *max77843;
	unsigned int reg_data;
	int ret;

	max77843 = devm_kzalloc(&i2c->dev, sizeof(*max77843), GFP_KERNEL);
	if (!max77843)
		return -ENOMEM;

	i2c_set_clientdata(i2c, max77843);
	max77843->dev = &i2c->dev;
	max77843->i2c = i2c;
	max77843->irq = i2c->irq;
	max77843->type = id->driver_data;

	max77843->regmap = devm_regmap_init_i2c(i2c,
			&max77843_regmap_config);
	if (IS_ERR(max77843->regmap)) {
		dev_err(&i2c->dev, "Failed to allocate topsys register map\n");
		return PTR_ERR(max77843->regmap);
	}

	ret = regmap_add_irq_chip(max77843->regmap, max77843->irq,
			IRQF_TRIGGER_LOW | IRQF_ONESHOT | IRQF_SHARED,
			0, &max77843_irq_chip, &max77843->irq_data_topsys);
	if (ret) {
		dev_err(&i2c->dev, "Failed to add TOPSYS IRQ chip\n");
		return ret;
	}

	ret = regmap_read(max77843->regmap,
			MAX77843_SYS_REG_PMICID, &reg_data);
	if (ret < 0) {
		dev_err(&i2c->dev, "Failed to read PMIC ID\n");
		goto err_pmic_id;
	}
	dev_info(&i2c->dev, "device ID: 0x%x\n", reg_data);

	ret = max77843_chg_init(max77843);
	if (ret) {
		dev_err(&i2c->dev, "Failed to init Charger\n");
		goto err_pmic_id;
	}

	ret = regmap_update_bits(max77843->regmap,
				 MAX77843_SYS_REG_INTSRCMASK,
				 MAX77843_INTSRC_MASK_MASK,
				 (unsigned int)~MAX77843_INTSRC_MASK_MASK);
	if (ret < 0) {
		dev_err(&i2c->dev, "Failed to unmask interrupt source\n");
		goto err_pmic_id;
	}

	ret = mfd_add_devices(max77843->dev, -1, max77843_devs,
			      ARRAY_SIZE(max77843_devs), NULL, 0, NULL);
	if (ret < 0) {
		dev_err(&i2c->dev, "Failed to add mfd device\n");
		goto err_pmic_id;
	}

	device_init_wakeup(max77843->dev, true);

	return 0;

err_pmic_id:
	regmap_del_irq_chip(max77843->irq, max77843->irq_data_topsys);

	return ret;
}

