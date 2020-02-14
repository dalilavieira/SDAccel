#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_5__ ;
typedef  struct TYPE_15__   TYPE_4__ ;
typedef  struct TYPE_14__   TYPE_3__ ;
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct regulator_init_data {int dummy; } ;
struct regulator_dev {TYPE_2__* desc; } ;
struct regulator_desc {int n_voltages; int min_uV; int uV_step; int enable_val; int disable_val; int enable_time; int /*<<< orphan*/ * ops; void* volt_table; int /*<<< orphan*/  vsel_reg; } ;
struct regulator_config {struct device_node* of_node; struct pfuze_chip* driver_data; struct regulator_init_data* init_data; TYPE_3__* dev; } ;
struct pfuze_regulator_platform_data {struct regulator_init_data** init_data; } ;
struct pfuze_chip {int chip_id; int flags; int /*<<< orphan*/ * regulators; TYPE_5__* pfuze_regulators; TYPE_4__* regulator_descs; int /*<<< orphan*/  regmap; TYPE_3__* dev; } ;
struct of_device_id {scalar_t__ data; } ;
struct i2c_device_id {int driver_data; } ;
struct TYPE_14__ {scalar_t__ of_node; } ;
struct i2c_client {TYPE_3__ dev; } ;
struct device_node {int dummy; } ;
struct TYPE_12__ {int name; } ;
struct TYPE_16__ {TYPE_1__ desc; } ;
struct TYPE_15__ {scalar_t__ sw_reg; struct regulator_desc desc; } ;
struct TYPE_13__ {scalar_t__ vsel_reg; } ;

/* Variables and functions */
 void* ARRAY_SIZE (void*) ; 
 int EACCES ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
#define  PFUZE100 131 
 int /*<<< orphan*/  PFUZE100_DEVICEID ; 
 int /*<<< orphan*/  PFUZE100_FABID ; 
 int /*<<< orphan*/  PFUZE100_REVID ; 
 int PFUZE100_SW2 ; 
 int PFUZE100_SW4 ; 
 int PFUZE100_SWBST ; 
#define  PFUZE200 130 
 int PFUZE200_SW2 ; 
 int PFUZE200_SW3B ; 
 int PFUZE200_SWBST ; 
#define  PFUZE3000 129 
 int PFUZE3000_SW2 ; 
 int PFUZE3000_SWBST ; 
#define  PFUZE3001 128 
 int PFUZE3001_SW2 ; 
 int PFUZE_FLAG_DISABLE_SW ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (TYPE_3__*,char*,...) ; 
 struct pfuze_regulator_platform_data* dev_get_platdata (TYPE_3__*) ; 
 int /*<<< orphan*/  dev_info (TYPE_3__*,char*,...) ; 
 int /*<<< orphan*/  dev_warn (TYPE_3__*,char*,unsigned int) ; 
 struct pfuze_chip* devm_kzalloc (TYPE_3__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  devm_regulator_register (TYPE_3__*,struct regulator_desc*,struct regulator_config*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct pfuze_chip*) ; 
 int /*<<< orphan*/  memcpy (TYPE_4__*,TYPE_5__*,int) ; 
 struct of_device_id* of_match_device (int /*<<< orphan*/ ,TYPE_3__*) ; 
 int /*<<< orphan*/  of_match_ptr (int /*<<< orphan*/ ) ; 
 void* pfuze100_regulators ; 
 int /*<<< orphan*/  pfuze100_sw_disable_regulator_ops ; 
 void* pfuze200_regulators ; 
 void* pfuze3000_regulators ; 
 void* pfuze3000_sw2hi ; 
 void* pfuze3001_regulators ; 
 int /*<<< orphan*/  pfuze_dt_ids ; 
 int /*<<< orphan*/  pfuze_regmap_config ; 
 struct pfuze_chip* rdev_get_drvdata (struct regulator_dev*) ; 
 int rdev_get_id (struct regulator_dev*) ; 
 int regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,...) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,scalar_t__,int,unsigned int) ; 

__attribute__((used)) static int pfuze100_set_ramp_delay(struct regulator_dev *rdev, int ramp_delay)
{
	struct pfuze_chip *pfuze100 = rdev_get_drvdata(rdev);
	int id = rdev_get_id(rdev);
	bool reg_has_ramp_delay;
	unsigned int ramp_bits;
	int ret;

	switch (pfuze100->chip_id) {
	case PFUZE3001:
		/* no dynamic voltage scaling for PF3001 */
		reg_has_ramp_delay = false;
		break;
	case PFUZE3000:
		reg_has_ramp_delay = (id < PFUZE3000_SWBST);
		break;
	case PFUZE200:
		reg_has_ramp_delay = (id < PFUZE200_SWBST);
		break;
	case PFUZE100:
	default:
		reg_has_ramp_delay = (id < PFUZE100_SWBST);
		break;
	}

	if (reg_has_ramp_delay) {
		ramp_delay = 12500 / ramp_delay;
		ramp_bits = (ramp_delay >> 1) - (ramp_delay >> 3);
		ret = regmap_update_bits(pfuze100->regmap,
					 rdev->desc->vsel_reg + 4,
					 0xc0, ramp_bits << 6);
		if (ret < 0)
			dev_err(pfuze100->dev, "ramp failed, err %d\n", ret);
	} else {
		ret = -EACCES;
	}

	return ret;
}

__attribute__((used)) static int pfuze_parse_regulators_dt(struct pfuze_chip *chip)
{
	return 0;
}

__attribute__((used)) static inline struct regulator_init_data *match_init_data(int index)
{
	return NULL;
}

__attribute__((used)) static inline struct device_node *match_of_node(int index)
{
	return NULL;
}

__attribute__((used)) static int pfuze_identify(struct pfuze_chip *pfuze_chip)
{
	unsigned int value;
	int ret;

	ret = regmap_read(pfuze_chip->regmap, PFUZE100_DEVICEID, &value);
	if (ret)
		return ret;

	if (((value & 0x0f) == 0x8) && (pfuze_chip->chip_id == PFUZE100)) {
		/*
		 * Freescale misprogrammed 1-3% of parts prior to week 8 of 2013
		 * as ID=8 in PFUZE100
		 */
		dev_info(pfuze_chip->dev, "Assuming misprogrammed ID=0x8");
	} else if ((value & 0x0f) != pfuze_chip->chip_id &&
		   (value & 0xf0) >> 4 != pfuze_chip->chip_id &&
		   (value != pfuze_chip->chip_id)) {
		/* device id NOT match with your setting */
		dev_warn(pfuze_chip->dev, "Illegal ID: %x\n", value);
		return -ENODEV;
	}

	ret = regmap_read(pfuze_chip->regmap, PFUZE100_REVID, &value);
	if (ret)
		return ret;
	dev_info(pfuze_chip->dev,
		 "Full layer: %x, Metal layer: %x\n",
		 (value & 0xf0) >> 4, value & 0x0f);

	ret = regmap_read(pfuze_chip->regmap, PFUZE100_FABID, &value);
	if (ret)
		return ret;
	dev_info(pfuze_chip->dev, "FAB: %x, FIN: %x\n",
		 (value & 0xc) >> 2, value & 0x3);

	return 0;
}

__attribute__((used)) static int pfuze100_regulator_probe(struct i2c_client *client,
				    const struct i2c_device_id *id)
{
	struct pfuze_chip *pfuze_chip;
	struct pfuze_regulator_platform_data *pdata =
	    dev_get_platdata(&client->dev);
	struct regulator_config config = { };
	int i, ret;
	const struct of_device_id *match;
	u32 regulator_num;
	u32 sw_check_start, sw_check_end, sw_hi = 0x40;

	pfuze_chip = devm_kzalloc(&client->dev, sizeof(*pfuze_chip),
			GFP_KERNEL);
	if (!pfuze_chip)
		return -ENOMEM;

	if (client->dev.of_node) {
		match = of_match_device(of_match_ptr(pfuze_dt_ids),
				&client->dev);
		if (!match) {
			dev_err(&client->dev, "Error: No device match found\n");
			return -ENODEV;
		}
		pfuze_chip->chip_id = (int)(long)match->data;
	} else if (id) {
		pfuze_chip->chip_id = id->driver_data;
	} else {
		dev_err(&client->dev, "No dts match or id table match found\n");
		return -ENODEV;
	}

	i2c_set_clientdata(client, pfuze_chip);
	pfuze_chip->dev = &client->dev;

	pfuze_chip->regmap = devm_regmap_init_i2c(client, &pfuze_regmap_config);
	if (IS_ERR(pfuze_chip->regmap)) {
		ret = PTR_ERR(pfuze_chip->regmap);
		dev_err(&client->dev,
			"regmap allocation failed with err %d\n", ret);
		return ret;
	}

	ret = pfuze_identify(pfuze_chip);
	if (ret) {
		dev_err(&client->dev, "unrecognized pfuze chip ID!\n");
		return ret;
	}

	/* use the right regulators after identify the right device */
	switch (pfuze_chip->chip_id) {
	case PFUZE3001:
		pfuze_chip->pfuze_regulators = pfuze3001_regulators;
		regulator_num = ARRAY_SIZE(pfuze3001_regulators);
		sw_check_start = PFUZE3001_SW2;
		sw_check_end = PFUZE3001_SW2;
		sw_hi = 1 << 3;
		break;
	case PFUZE3000:
		pfuze_chip->pfuze_regulators = pfuze3000_regulators;
		regulator_num = ARRAY_SIZE(pfuze3000_regulators);
		sw_check_start = PFUZE3000_SW2;
		sw_check_end = PFUZE3000_SW2;
		sw_hi = 1 << 3;
		break;
	case PFUZE200:
		pfuze_chip->pfuze_regulators = pfuze200_regulators;
		regulator_num = ARRAY_SIZE(pfuze200_regulators);
		sw_check_start = PFUZE200_SW2;
		sw_check_end = PFUZE200_SW3B;
		break;
	case PFUZE100:
	default:
		pfuze_chip->pfuze_regulators = pfuze100_regulators;
		regulator_num = ARRAY_SIZE(pfuze100_regulators);
		sw_check_start = PFUZE100_SW2;
		sw_check_end = PFUZE100_SW4;
		break;
	}
	dev_info(&client->dev, "pfuze%s found.\n",
		(pfuze_chip->chip_id == PFUZE100) ? "100" :
		(((pfuze_chip->chip_id == PFUZE200) ? "200" :
		((pfuze_chip->chip_id == PFUZE3000) ? "3000" : "3001"))));

	memcpy(pfuze_chip->regulator_descs, pfuze_chip->pfuze_regulators,
		sizeof(pfuze_chip->regulator_descs));

	ret = pfuze_parse_regulators_dt(pfuze_chip);
	if (ret)
		return ret;

	for (i = 0; i < regulator_num; i++) {
		struct regulator_init_data *init_data;
		struct regulator_desc *desc;
		int val;

		desc = &pfuze_chip->regulator_descs[i].desc;

		if (pdata)
			init_data = pdata->init_data[i];
		else
			init_data = match_init_data(i);

		/* SW2~SW4 high bit check and modify the voltage value table */
		if (i >= sw_check_start && i <= sw_check_end) {
			regmap_read(pfuze_chip->regmap, desc->vsel_reg, &val);
			if (val & sw_hi) {
				if (pfuze_chip->chip_id == PFUZE3000 ||
					pfuze_chip->chip_id == PFUZE3001) {
					desc->volt_table = pfuze3000_sw2hi;
					desc->n_voltages = ARRAY_SIZE(pfuze3000_sw2hi);
				} else {
					desc->min_uV = 800000;
					desc->uV_step = 50000;
					desc->n_voltages = 51;
				}
			}
		}

		/*
		 * Allow SW regulators to turn off. Checking it trough a flag is
		 * a workaround to keep the backward compatibility with existing
		 * old dtb's which may relay on the fact that we didn't disable
		 * the switched regulator till yet.
		 */
		if (pfuze_chip->flags & PFUZE_FLAG_DISABLE_SW) {
			if (pfuze_chip->regulator_descs[i].sw_reg) {
				desc->ops = &pfuze100_sw_disable_regulator_ops;
				desc->enable_val = 0x8;
				desc->disable_val = 0x0;
				desc->enable_time = 500;
			}
		}

		config.dev = &client->dev;
		config.init_data = init_data;
		config.driver_data = pfuze_chip;
		config.of_node = match_of_node(i);

		pfuze_chip->regulators[i] =
			devm_regulator_register(&client->dev, desc, &config);
		if (IS_ERR(pfuze_chip->regulators[i])) {
			dev_err(&client->dev, "register regulator%s failed\n",
				pfuze_chip->pfuze_regulators[i].desc.name);
			return PTR_ERR(pfuze_chip->regulators[i]);
		}
	}

	return 0;
}

