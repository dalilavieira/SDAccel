#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct regulator_init_data {int dummy; } ;
struct TYPE_5__ {TYPE_4__* parent; } ;
struct regulator_dev {TYPE_2__* desc; int /*<<< orphan*/  regmap; TYPE_1__ dev; } ;
struct regulator_config {struct device_node* of_node; struct regmap* regmap; struct hi6421_regulator_info* driver_data; struct regulator_init_data* init_data; struct device* dev; } ;
struct regmap {int dummy; } ;
struct device {TYPE_4__* parent; } ;
struct platform_device {struct device dev; } ;
struct hi6421_regulator_pdata {int /*<<< orphan*/  lock; } ;
struct TYPE_7__ {int name; } ;
struct hi6421_regulator_info {int mode_mask; int eco_microamp; struct device_node* of_node; struct regulator_init_data* init_data; TYPE_3__ desc; } ;
struct hi6421_pmic {struct regmap* regmap; } ;
struct device_node {int dummy; } ;
struct TYPE_8__ {int /*<<< orphan*/  of_node; } ;
struct TYPE_6__ {int /*<<< orphan*/  enable_reg; } ;

/* Variables and functions */
 int ARRAY_SIZE (struct hi6421_regulator_info*) ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct regulator_dev*) ; 
 int PTR_ERR (struct regulator_dev*) ; 
#define  REGULATOR_MODE_IDLE 130 
#define  REGULATOR_MODE_NORMAL 129 
#define  REGULATOR_MODE_STANDBY 128 
 int /*<<< orphan*/  dev_err (struct device*,char*,int) ; 
 void* dev_get_drvdata (TYPE_4__*) ; 
 struct hi6421_regulator_pdata* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 struct regulator_dev* devm_regulator_register (struct device*,TYPE_3__*,struct regulator_config*) ; 
 struct hi6421_regulator_info* hi6421_regulator_info ; 
 struct hi6421_regulator_info* hi6421_regulator_match ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct device_node* of_get_child_by_name (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 int of_regulator_match (struct device*,struct device_node*,struct hi6421_regulator_info*,int) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct hi6421_regulator_pdata*) ; 
 struct hi6421_regulator_info* rdev_get_drvdata (struct regulator_dev*) ; 
 int /*<<< orphan*/  regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  regulator_enable_regmap (struct regulator_dev*) ; 

__attribute__((used)) static int hi6421_regulator_enable(struct regulator_dev *rdev)
{
	struct hi6421_regulator_pdata *pdata;

	pdata = dev_get_drvdata(rdev->dev.parent);
	/* hi6421 spec requires regulator enablement must be serialized:
	 *  - Because when BUCK, LDO switching from off to on, it will have
	 *    a huge instantaneous current; so you can not turn on two or
	 *    more LDO or BUCKs simultaneously, or it may burn the chip.
	 */
	mutex_lock(&pdata->lock);

	/* call regulator regmap helper */
	regulator_enable_regmap(rdev);

	mutex_unlock(&pdata->lock);
	return 0;
}

__attribute__((used)) static unsigned int hi6421_regulator_ldo_get_mode(struct regulator_dev *rdev)
{
	struct hi6421_regulator_info *info = rdev_get_drvdata(rdev);
	u32 reg_val;

	regmap_read(rdev->regmap, rdev->desc->enable_reg, &reg_val);
	if (reg_val & info->mode_mask)
		return REGULATOR_MODE_IDLE;

	return REGULATOR_MODE_NORMAL;
}

__attribute__((used)) static unsigned int hi6421_regulator_buck_get_mode(struct regulator_dev *rdev)
{
	struct hi6421_regulator_info *info = rdev_get_drvdata(rdev);
	u32 reg_val;

	regmap_read(rdev->regmap, rdev->desc->enable_reg, &reg_val);
	if (reg_val & info->mode_mask)
		return REGULATOR_MODE_STANDBY;

	return REGULATOR_MODE_NORMAL;
}

__attribute__((used)) static int hi6421_regulator_ldo_set_mode(struct regulator_dev *rdev,
						unsigned int mode)
{
	struct hi6421_regulator_info *info = rdev_get_drvdata(rdev);
	u32 new_mode;

	switch (mode) {
	case REGULATOR_MODE_NORMAL:
		new_mode = 0;
		break;
	case REGULATOR_MODE_IDLE:
		new_mode = info->mode_mask;
		break;
	default:
		return -EINVAL;
	}

	/* set mode */
	regmap_update_bits(rdev->regmap, rdev->desc->enable_reg,
			   info->mode_mask, new_mode);

	return 0;
}

__attribute__((used)) static int hi6421_regulator_buck_set_mode(struct regulator_dev *rdev,
						unsigned int mode)
{
	struct hi6421_regulator_info *info = rdev_get_drvdata(rdev);
	u32 new_mode;

	switch (mode) {
	case REGULATOR_MODE_NORMAL:
		new_mode = 0;
		break;
	case REGULATOR_MODE_STANDBY:
		new_mode = info->mode_mask;
		break;
	default:
		return -EINVAL;
	}

	/* set mode */
	regmap_update_bits(rdev->regmap, rdev->desc->enable_reg,
			   info->mode_mask, new_mode);

	return 0;
}

__attribute__((used)) static unsigned int
hi6421_regulator_ldo_get_optimum_mode(struct regulator_dev *rdev,
			int input_uV, int output_uV, int load_uA)
{
	struct hi6421_regulator_info *info = rdev_get_drvdata(rdev);

	if (load_uA > info->eco_microamp)
		return REGULATOR_MODE_NORMAL;

	return REGULATOR_MODE_IDLE;
}

__attribute__((used)) static int hi6421_regulator_register(struct platform_device *pdev,
				     struct regmap *rmap,
				     struct regulator_init_data *init_data,
				     int id, struct device_node *np)
{
	struct hi6421_regulator_info *info = NULL;
	struct regulator_config config = { };
	struct regulator_dev *rdev;

	/* assign per-regulator data */
	info = &hi6421_regulator_info[id];

	config.dev = &pdev->dev;
	config.init_data = init_data;
	config.driver_data = info;
	config.regmap = rmap;
	config.of_node = np;

	/* register regulator with framework */
	rdev = devm_regulator_register(&pdev->dev, &info->desc, &config);
	if (IS_ERR(rdev)) {
		dev_err(&pdev->dev, "failed to register regulator %s\n",
			info->desc.name);
		return PTR_ERR(rdev);
	}

	return 0;
}

__attribute__((used)) static int hi6421_regulator_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct device_node *np;
	struct hi6421_pmic *pmic;
	struct hi6421_regulator_pdata *pdata;
	int i, ret = 0;

	pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
	if (!pdata)
		return -ENOMEM;
	mutex_init(&pdata->lock);
	platform_set_drvdata(pdev, pdata);

	np = of_get_child_by_name(dev->parent->of_node, "regulators");
	if (!np)
		return -ENODEV;

	ret = of_regulator_match(dev, np,
				 hi6421_regulator_match,
				 ARRAY_SIZE(hi6421_regulator_match));
	of_node_put(np);
	if (ret < 0) {
		dev_err(dev, "Error parsing regulator init data: %d\n", ret);
		return ret;
	}

	pmic = dev_get_drvdata(dev->parent);

	for (i = 0; i < ARRAY_SIZE(hi6421_regulator_info); i++) {
		ret = hi6421_regulator_register(pdev, pmic->regmap,
			hi6421_regulator_match[i].init_data, i,
			hi6421_regulator_match[i].of_node);
		if (ret)
			return ret;
	}

	return 0;
}

