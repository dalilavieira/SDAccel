#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct tps65132_regulator {TYPE_2__** rdesc; void** rdev; void* rmap; struct device* dev; struct tps65132_reg_pdata* reg_pdata; } ;
struct tps65132_reg_pdata {int ena_gpio_state; scalar_t__ act_dis_time_us; void* act_dis_gpiod; void* en_gpiod; } ;
struct regulator_dev {TYPE_1__* constraints; } ;
struct regulator_desc {size_t id; } ;
struct regulator_config {struct tps65132_regulator* driver_data; struct device* dev; void* regmap; } ;
struct i2c_device_id {int dummy; } ;
struct device {int dummy; } ;
struct i2c_client {struct device dev; } ;
struct device_node {int /*<<< orphan*/  fwnode; } ;
struct TYPE_5__ {int /*<<< orphan*/  name; } ;
struct TYPE_4__ {scalar_t__ active_discharge; } ;

/* Variables and functions */
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (void*) ; 
 int PTR_ERR (void*) ; 
 scalar_t__ REGULATOR_ACTIVE_DISCHARGE_DISABLE ; 
 scalar_t__ TPS65132_ACT_DIS_TIME_SLACK ; 
 int TPS65132_MAX_REGULATORS ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,int,...) ; 
 void* devm_fwnode_get_index_gpiod_from_child (struct device*,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*) ; 
 struct tps65132_regulator* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 void* devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 void* devm_regulator_register (struct device*,TYPE_2__*,struct regulator_config*) ; 
 int /*<<< orphan*/  gpiod_set_value_cansleep (void*,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct tps65132_regulator*) ; 
 int of_property_read_u32 (struct device_node*,char*,scalar_t__*) ; 
 struct tps65132_regulator* rdev_get_drvdata (struct regulator_dev*) ; 
 int rdev_get_id (struct regulator_dev*) ; 
 int regulator_set_active_discharge_regmap (struct regulator_dev*,int) ; 
 int /*<<< orphan*/  tps65132_regmap_config ; 
 TYPE_2__* tps_regs_desc ; 
 int /*<<< orphan*/  usleep_range (scalar_t__,scalar_t__) ; 

__attribute__((used)) static int tps65132_regulator_enable(struct regulator_dev *rdev)
{
	struct tps65132_regulator *tps = rdev_get_drvdata(rdev);
	int id = rdev_get_id(rdev);
	struct tps65132_reg_pdata *rpdata = &tps->reg_pdata[id];
	int ret;

	if (!IS_ERR(rpdata->en_gpiod)) {
		gpiod_set_value_cansleep(rpdata->en_gpiod, 1);
		rpdata->ena_gpio_state = 1;
	}

	/* Hardware automatically enable discharge bit in enable */
	if (rdev->constraints->active_discharge ==
			REGULATOR_ACTIVE_DISCHARGE_DISABLE) {
		ret = regulator_set_active_discharge_regmap(rdev, false);
		if (ret < 0) {
			dev_err(tps->dev, "Failed to disable active discharge: %d\n",
				ret);
			return ret;
		}
	}

	return 0;
}

__attribute__((used)) static int tps65132_regulator_disable(struct regulator_dev *rdev)
{
	struct tps65132_regulator *tps = rdev_get_drvdata(rdev);
	int id = rdev_get_id(rdev);
	struct tps65132_reg_pdata *rpdata = &tps->reg_pdata[id];

	if (!IS_ERR(rpdata->en_gpiod)) {
		gpiod_set_value_cansleep(rpdata->en_gpiod, 0);
		rpdata->ena_gpio_state = 0;
	}

	if (!IS_ERR(rpdata->act_dis_gpiod)) {
		gpiod_set_value_cansleep(rpdata->act_dis_gpiod, 1);
		usleep_range(rpdata->act_dis_time_us, rpdata->act_dis_time_us +
			     TPS65132_ACT_DIS_TIME_SLACK);
		gpiod_set_value_cansleep(rpdata->act_dis_gpiod, 0);
	}

	return 0;
}

__attribute__((used)) static int tps65132_regulator_is_enabled(struct regulator_dev *rdev)
{
	struct tps65132_regulator *tps = rdev_get_drvdata(rdev);
	int id = rdev_get_id(rdev);
	struct tps65132_reg_pdata *rpdata = &tps->reg_pdata[id];

	if (!IS_ERR(rpdata->en_gpiod))
		return rpdata->ena_gpio_state;

	return 1;
}

__attribute__((used)) static int tps65132_of_parse_cb(struct device_node *np,
				const struct regulator_desc *desc,
				struct regulator_config *config)
{
	struct tps65132_regulator *tps = config->driver_data;
	struct tps65132_reg_pdata *rpdata = &tps->reg_pdata[desc->id];
	int ret;

	rpdata->en_gpiod = devm_fwnode_get_index_gpiod_from_child(tps->dev,
					"enable", 0, &np->fwnode, 0, "enable");
	if (IS_ERR(rpdata->en_gpiod)) {
		ret = PTR_ERR(rpdata->en_gpiod);

		/* Ignore the error other than probe defer */
		if (ret == -EPROBE_DEFER)
			return ret;
		return 0;
	}

	rpdata->act_dis_gpiod = devm_fwnode_get_index_gpiod_from_child(
					tps->dev, "active-discharge", 0,
					&np->fwnode, 0, "active-discharge");
	if (IS_ERR(rpdata->act_dis_gpiod)) {
		ret = PTR_ERR(rpdata->act_dis_gpiod);

		/* Ignore the error other than probe defer */
		if (ret == -EPROBE_DEFER)
			return ret;

		return 0;
	}

	ret = of_property_read_u32(np, "ti,active-discharge-time-us",
				   &rpdata->act_dis_time_us);
	if (ret < 0) {
		dev_err(tps->dev, "Failed to read active discharge time:%d\n",
			ret);
		return ret;
	}

	return 0;
}

__attribute__((used)) static int tps65132_probe(struct i2c_client *client,
			  const struct i2c_device_id *client_id)
{
	struct device *dev = &client->dev;
	struct tps65132_regulator *tps;
	struct regulator_config config = { };
	int id;
	int ret;

	tps = devm_kzalloc(dev, sizeof(*tps), GFP_KERNEL);
	if (!tps)
		return -ENOMEM;

	tps->rmap = devm_regmap_init_i2c(client, &tps65132_regmap_config);
	if (IS_ERR(tps->rmap)) {
		ret = PTR_ERR(tps->rmap);
		dev_err(dev, "regmap init failed: %d\n", ret);
		return ret;
	}

	i2c_set_clientdata(client, tps);
	tps->dev = dev;

	for (id = 0; id < TPS65132_MAX_REGULATORS; ++id) {
		tps->rdesc[id] = &tps_regs_desc[id];

		config.regmap = tps->rmap;
		config.dev = dev;
		config.driver_data = tps;

		tps->rdev[id] = devm_regulator_register(dev,
					tps->rdesc[id], &config);
		if (IS_ERR(tps->rdev[id])) {
			ret = PTR_ERR(tps->rdev[id]);
			dev_err(dev, "regulator %s register failed: %d\n",
				tps->rdesc[id]->name, ret);
			return ret;
		}
	}
	return 0;
}

