#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct regulator_dev {int dummy; } ;
struct regulator_config {int /*<<< orphan*/  regmap; struct rc5t583_regulator* driver_data; int /*<<< orphan*/  init_data; TYPE_1__* dev; } ;
struct TYPE_7__ {int /*<<< orphan*/  name; } ;
struct rc5t583_regulator_info {scalar_t__ deepsleep_id; TYPE_2__ desc; int /*<<< orphan*/  enable_uv_per_us; } ;
struct rc5t583_regulator {struct regulator_dev* rdev; struct rc5t583_regulator_info* reg_info; } ;
struct rc5t583_platform_data {int /*<<< orphan*/ * reg_init_data; int /*<<< orphan*/ * regulator_deepsleep_slot; int /*<<< orphan*/ * regulator_ext_pwr_control; } ;
struct rc5t583 {int /*<<< orphan*/  regmap; int /*<<< orphan*/  dev; } ;
struct TYPE_6__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_1__ dev; } ;

/* Variables and functions */
 int DIV_ROUND_UP (int,int /*<<< orphan*/ ) ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct regulator_dev*) ; 
 int PTR_ERR (struct regulator_dev*) ; 
 scalar_t__ RC5T583_DS_NONE ; 
 int RC5T583_REGULATOR_MAX ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*,...) ; 
 struct rc5t583* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 struct rc5t583_platform_data* dev_get_platdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_warn (TYPE_1__*,char*,int) ; 
 struct rc5t583_regulator* devm_kcalloc (TYPE_1__*,int,int,int /*<<< orphan*/ ) ; 
 struct regulator_dev* devm_regulator_register (TYPE_1__*,TYPE_2__*,struct regulator_config*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct rc5t583_regulator*) ; 
 int rc5t583_ext_power_req_config (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct rc5t583_regulator_info* rc5t583_reg_info ; 
 struct rc5t583_regulator* rdev_get_drvdata (struct regulator_dev*) ; 
 int regulator_get_voltage_sel_regmap (struct regulator_dev*) ; 
 int regulator_list_voltage_linear (struct regulator_dev*,int) ; 

__attribute__((used)) static int rc5t583_regulator_enable_time(struct regulator_dev *rdev)
{
	struct rc5t583_regulator *reg = rdev_get_drvdata(rdev);
	int vsel = regulator_get_voltage_sel_regmap(rdev);
	int curr_uV = regulator_list_voltage_linear(rdev, vsel);

	return DIV_ROUND_UP(curr_uV, reg->reg_info->enable_uv_per_us);
}

__attribute__((used)) static int rc5t583_regulator_probe(struct platform_device *pdev)
{
	struct rc5t583 *rc5t583 = dev_get_drvdata(pdev->dev.parent);
	struct rc5t583_platform_data *pdata = dev_get_platdata(rc5t583->dev);
	struct regulator_config config = { };
	struct rc5t583_regulator *reg = NULL;
	struct rc5t583_regulator *regs;
	struct regulator_dev *rdev;
	struct rc5t583_regulator_info *ri;
	int ret;
	int id;

	if (!pdata) {
		dev_err(&pdev->dev, "No platform data, exiting...\n");
		return -ENODEV;
	}

	regs = devm_kcalloc(&pdev->dev,
			    RC5T583_REGULATOR_MAX,
			    sizeof(struct rc5t583_regulator),
			    GFP_KERNEL);
	if (!regs)
		return -ENOMEM;


	for (id = 0; id < RC5T583_REGULATOR_MAX; ++id) {
		reg = &regs[id];
		ri = &rc5t583_reg_info[id];
		reg->reg_info = ri;

		if (ri->deepsleep_id == RC5T583_DS_NONE)
			goto skip_ext_pwr_config;

		ret = rc5t583_ext_power_req_config(rc5t583->dev,
				ri->deepsleep_id,
				pdata->regulator_ext_pwr_control[id],
				pdata->regulator_deepsleep_slot[id]);
		/*
		 * Configuring external control is not a major issue,
		 * just give warning.
		 */
		if (ret < 0)
			dev_warn(&pdev->dev,
				"Failed to configure ext control %d\n", id);

skip_ext_pwr_config:
		config.dev = &pdev->dev;
		config.init_data = pdata->reg_init_data[id];
		config.driver_data = reg;
		config.regmap = rc5t583->regmap;

		rdev = devm_regulator_register(&pdev->dev, &ri->desc, &config);
		if (IS_ERR(rdev)) {
			dev_err(&pdev->dev, "Failed to register regulator %s\n",
						ri->desc.name);
			return PTR_ERR(rdev);
		}
		reg->rdev = rdev;
	}
	platform_set_drvdata(pdev, regs);
	return 0;
}

