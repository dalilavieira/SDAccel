#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
struct tps6586x_settings {int slew_rate; } ;
struct TYPE_6__ {int id; int name; } ;
struct tps6586x_regulator {scalar_t__* enable_reg; int* enable_bit; TYPE_2__ desc; } ;
struct tps6586x_platform_data {struct regulator_init_data** reg_init_data; } ;
struct regulator_init_data {struct tps6586x_settings* driver_data; } ;
struct regulator_dev {int dummy; } ;
struct regulator_config {int /*<<< orphan*/  of_node; struct tps6586x_regulator* driver_data; struct regulator_init_data* init_data; struct device* dev; } ;
struct TYPE_5__ {struct device* parent; } ;
struct platform_device {TYPE_1__ dev; } ;
struct of_regulator_match {int /*<<< orphan*/  of_node; } ;
struct device {scalar_t__ of_node; } ;

/* Variables and functions */
 int ARRAY_SIZE (struct tps6586x_regulator*) ; 
 int EINVAL ; 
 int ENODEV ; 
 scalar_t__ IS_ERR (struct regulator_dev*) ; 
 int PTR_ERR (struct regulator_dev*) ; 
#define  TPS658623 134 
#define  TPS658624 133 
#define  TPS658640 132 
#define  TPS658640v2 131 
#define  TPS658643 130 
 int TPS6586X_ID_MAX_REGULATOR ; 
#define  TPS6586X_ID_SM_0 129 
#define  TPS6586X_ID_SM_1 128 
 int TPS6586X_SLEW_RATE_MASK ; 
 int TPS6586X_SLEW_RATE_SET ; 
 int TPS6586X_SM0SL ; 
 int TPS6586X_SM1SL ; 
 int /*<<< orphan*/  dev_dbg (TYPE_1__*,char*) ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*,...) ; 
 struct tps6586x_platform_data* dev_get_platdata (struct device*) ; 
 struct regulator_dev* devm_regulator_register (TYPE_1__*,TYPE_2__*,struct regulator_config*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct regulator_dev*) ; 
 struct tps6586x_regulator* tps658623_regulator ; 
 struct tps6586x_regulator* tps658640_regulator ; 
 struct tps6586x_regulator* tps658643_regulator ; 
 int tps6586x_clr_bits (struct device*,scalar_t__,int) ; 
 int tps6586x_get_version (struct device*) ; 
 int tps6586x_read (struct device*,scalar_t__,int*) ; 
 struct tps6586x_regulator* tps6586x_regulator ; 
 int tps6586x_set_bits (struct device*,scalar_t__,int) ; 
 int tps6586x_write (struct device*,int,int) ; 

__attribute__((used)) static inline int tps6586x_regulator_preinit(struct device *parent,
					     struct tps6586x_regulator *ri)
{
	uint8_t val1, val2;
	int ret;

	if (ri->enable_reg[0] == ri->enable_reg[1] &&
	    ri->enable_bit[0] == ri->enable_bit[1])
			return 0;

	ret = tps6586x_read(parent, ri->enable_reg[0], &val1);
	if (ret)
		return ret;

	ret = tps6586x_read(parent, ri->enable_reg[1], &val2);
	if (ret)
		return ret;

	if (!(val2 & (1 << ri->enable_bit[1])))
		return 0;

	/*
	 * The regulator is on, but it's enabled with the bit we don't
	 * want to use, so we switch the enable bits
	 */
	if (!(val1 & (1 << ri->enable_bit[0]))) {
		ret = tps6586x_set_bits(parent, ri->enable_reg[0],
					1 << ri->enable_bit[0]);
		if (ret)
			return ret;
	}

	return tps6586x_clr_bits(parent, ri->enable_reg[1],
				 1 << ri->enable_bit[1]);
}

__attribute__((used)) static int tps6586x_regulator_set_slew_rate(struct platform_device *pdev,
			int id, struct regulator_init_data *p)
{
	struct device *parent = pdev->dev.parent;
	struct tps6586x_settings *setting = p->driver_data;
	uint8_t reg;

	if (setting == NULL)
		return 0;

	if (!(setting->slew_rate & TPS6586X_SLEW_RATE_SET))
		return 0;

	/* only SM0 and SM1 can have the slew rate settings */
	switch (id) {
	case TPS6586X_ID_SM_0:
		reg = TPS6586X_SM0SL;
		break;
	case TPS6586X_ID_SM_1:
		reg = TPS6586X_SM1SL;
		break;
	default:
		dev_err(&pdev->dev, "Only SM0/SM1 can set slew rate\n");
		return -EINVAL;
	}

	return tps6586x_write(parent, reg,
			setting->slew_rate & TPS6586X_SLEW_RATE_MASK);
}

__attribute__((used)) static struct tps6586x_regulator *find_regulator_info(int id, int version)
{
	struct tps6586x_regulator *ri;
	struct tps6586x_regulator *table = NULL;
	int num;
	int i;

	switch (version) {
	case TPS658623:
	case TPS658624:
		table = tps658623_regulator;
		num = ARRAY_SIZE(tps658623_regulator);
		break;
	case TPS658640:
	case TPS658640v2:
		table = tps658640_regulator;
		num = ARRAY_SIZE(tps658640_regulator);
		break;
	case TPS658643:
		table = tps658643_regulator;
		num = ARRAY_SIZE(tps658643_regulator);
		break;
	}

	/* Search version specific table first */
	if (table) {
		for (i = 0; i < num; i++) {
			ri = &table[i];
			if (ri->desc.id == id)
				return ri;
		}
	}

	for (i = 0; i < ARRAY_SIZE(tps6586x_regulator); i++) {
		ri = &tps6586x_regulator[i];
		if (ri->desc.id == id)
			return ri;
	}
	return NULL;
}

__attribute__((used)) static struct tps6586x_platform_data *tps6586x_parse_regulator_dt(
		struct platform_device *pdev,
		struct of_regulator_match **tps6586x_reg_matches)
{
	*tps6586x_reg_matches = NULL;
	return NULL;
}

__attribute__((used)) static int tps6586x_regulator_probe(struct platform_device *pdev)
{
	struct tps6586x_regulator *ri = NULL;
	struct regulator_config config = { };
	struct regulator_dev *rdev;
	struct regulator_init_data *reg_data;
	struct tps6586x_platform_data *pdata;
	struct of_regulator_match *tps6586x_reg_matches = NULL;
	int version;
	int id;
	int err;

	dev_dbg(&pdev->dev, "Probing regulator\n");

	pdata = dev_get_platdata(pdev->dev.parent);
	if ((!pdata) && (pdev->dev.parent->of_node))
		pdata = tps6586x_parse_regulator_dt(pdev,
					&tps6586x_reg_matches);

	if (!pdata) {
		dev_err(&pdev->dev, "Platform data not available, exiting\n");
		return -ENODEV;
	}

	version = tps6586x_get_version(pdev->dev.parent);

	for (id = 0; id < TPS6586X_ID_MAX_REGULATOR; ++id) {
		reg_data = pdata->reg_init_data[id];

		ri = find_regulator_info(id, version);

		if (!ri) {
			dev_err(&pdev->dev, "invalid regulator ID specified\n");
			return -EINVAL;
		}

		err = tps6586x_regulator_preinit(pdev->dev.parent, ri);
		if (err) {
			dev_err(&pdev->dev,
				"regulator %d preinit failed, e %d\n", id, err);
			return err;
		}

		config.dev = pdev->dev.parent;
		config.init_data = reg_data;
		config.driver_data = ri;

		if (tps6586x_reg_matches)
			config.of_node = tps6586x_reg_matches[id].of_node;

		rdev = devm_regulator_register(&pdev->dev, &ri->desc, &config);
		if (IS_ERR(rdev)) {
			dev_err(&pdev->dev, "failed to register regulator %s\n",
					ri->desc.name);
			return PTR_ERR(rdev);
		}

		if (reg_data) {
			err = tps6586x_regulator_set_slew_rate(pdev, id,
					reg_data);
			if (err < 0) {
				dev_err(&pdev->dev,
					"Slew rate config failed, e %d\n", err);
				return err;
			}
		}
	}

	platform_set_drvdata(pdev, rdev);
	return 0;
}

