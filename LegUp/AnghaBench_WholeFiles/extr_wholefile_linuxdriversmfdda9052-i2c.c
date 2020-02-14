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
struct i2c_device_id {int /*<<< orphan*/  driver_data; } ;
struct i2c_client {int /*<<< orphan*/  dev; int /*<<< orphan*/  irq; } ;
struct da9052 {int chip_id; int (* fix_io ) (struct da9052*,unsigned char) ;int /*<<< orphan*/  regmap; int /*<<< orphan*/  chip_irq; int /*<<< orphan*/ * dev; } ;

/* Variables and functions */
#define  DA9052 149 
#define  DA9052_ADCIN4_RES_REG 148 
#define  DA9052_ADCIN5_RES_REG 147 
#define  DA9052_ADCIN6_RES_REG 146 
#define  DA9052_ADC_RES_H_REG 145 
#define  DA9052_ADC_RES_L_REG 144 
 int /*<<< orphan*/  DA9052_CONTROL_B_REG ; 
 int DA9052_CONTROL_B_WRITEMODE ; 
#define  DA9052_ICHG_AV_REG 143 
 int /*<<< orphan*/  DA9052_PARK_REGISTER ; 
#define  DA9052_STATUS_A_REG 142 
#define  DA9052_STATUS_B_REG 141 
#define  DA9052_STATUS_C_REG 140 
#define  DA9052_STATUS_D_REG 139 
#define  DA9052_TBAT_RES_REG 138 
#define  DA9052_TJUNC_RES_REG 137 
#define  DA9052_TSI_LSB_REG 136 
#define  DA9052_TSI_X_MSB_REG 135 
#define  DA9052_TSI_Y_MSB_REG 134 
#define  DA9052_TSI_Z_MSB_REG 133 
#define  DA9052_VDD_RES_REG 132 
#define  DA9053_AA 131 
#define  DA9053_BA 130 
#define  DA9053_BB 129 
#define  DA9053_BC 128 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  da9052_device_exit (struct da9052*) ; 
 int da9052_device_init (struct da9052*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  da9052_regmap_config ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 struct da9052* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 struct da9052* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct da9052*) ; 
 int regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int regmap_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline bool i2c_safe_reg(unsigned char reg)
{
	switch (reg) {
	case DA9052_STATUS_A_REG:
	case DA9052_STATUS_B_REG:
	case DA9052_STATUS_C_REG:
	case DA9052_STATUS_D_REG:
	case DA9052_ADC_RES_L_REG:
	case DA9052_ADC_RES_H_REG:
	case DA9052_VDD_RES_REG:
	case DA9052_ICHG_AV_REG:
	case DA9052_TBAT_RES_REG:
	case DA9052_ADCIN4_RES_REG:
	case DA9052_ADCIN5_RES_REG:
	case DA9052_ADCIN6_RES_REG:
	case DA9052_TJUNC_RES_REG:
	case DA9052_TSI_X_MSB_REG:
	case DA9052_TSI_Y_MSB_REG:
	case DA9052_TSI_LSB_REG:
	case DA9052_TSI_Z_MSB_REG:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static int da9052_i2c_fix(struct da9052 *da9052, unsigned char reg)
{
	int val;

	switch (da9052->chip_id) {
	case DA9052:
	case DA9053_AA:
	case DA9053_BA:
	case DA9053_BB:
		/* A dummy read to a safe register address. */
		if (!i2c_safe_reg(reg))
			return regmap_read(da9052->regmap,
					   DA9052_PARK_REGISTER,
					   &val);
		break;
	case DA9053_BC:
	default:
		/*
		 * For other chips parking of I2C register
		 * to a safe place is not required.
		 */
		break;
	}

	return 0;
}

__attribute__((used)) static int da9052_i2c_disable_multiwrite(struct da9052 *da9052)
{
	int reg_val, ret;

	ret = regmap_read(da9052->regmap, DA9052_CONTROL_B_REG, &reg_val);
	if (ret < 0)
		return ret;

	if (!(reg_val & DA9052_CONTROL_B_WRITEMODE)) {
		reg_val |= DA9052_CONTROL_B_WRITEMODE;
		ret = regmap_write(da9052->regmap, DA9052_CONTROL_B_REG,
				   reg_val);
		if (ret < 0)
			return ret;
	}

	return 0;
}

__attribute__((used)) static int da9052_i2c_probe(struct i2c_client *client,
				       const struct i2c_device_id *id)
{
	struct da9052 *da9052;
	int ret;

	da9052 = devm_kzalloc(&client->dev, sizeof(struct da9052), GFP_KERNEL);
	if (!da9052)
		return -ENOMEM;

	da9052->dev = &client->dev;
	da9052->chip_irq = client->irq;
	da9052->fix_io = da9052_i2c_fix;

	i2c_set_clientdata(client, da9052);

	da9052->regmap = devm_regmap_init_i2c(client, &da9052_regmap_config);
	if (IS_ERR(da9052->regmap)) {
		ret = PTR_ERR(da9052->regmap);
		dev_err(&client->dev, "Failed to allocate register map: %d\n",
			ret);
		return ret;
	}

	ret = da9052_i2c_disable_multiwrite(da9052);
	if (ret < 0)
		return ret;

#ifdef CONFIG_OF
	if (!id) {
		struct device_node *np = client->dev.of_node;
		const struct of_device_id *deviceid;

		deviceid = of_match_node(dialog_dt_ids, np);
		id = deviceid->data;
	}
#endif

	if (!id) {
		ret = -ENODEV;
		dev_err(&client->dev, "id is null.\n");
		return ret;
	}

	return da9052_device_init(da9052, id->driver_data);
}

__attribute__((used)) static int da9052_i2c_remove(struct i2c_client *client)
{
	struct da9052 *da9052 = i2c_get_clientdata(client);

	da9052_device_exit(da9052);
	return 0;
}

