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
typedef  size_t u8 ;
struct ti_lmu {struct regmap* regmap; } ;
struct regulator_dev {int /*<<< orphan*/  regmap; } ;
struct regulator_config {struct gpio_desc* ena_gpiod; struct regmap* regmap; struct device* dev; } ;
struct regmap {int dummy; } ;
struct device {int /*<<< orphan*/  parent; } ;
struct platform_device {int id; struct device dev; } ;
struct gpio_desc {int dummy; } ;
typedef  enum lm363x_regulator_id { ____Placeholder_lm363x_regulator_id } lm363x_regulator_id ;

/* Variables and functions */
 int EINVAL ; 
 size_t ENABLE_TIME_USEC ; 
 int /*<<< orphan*/  GPIOD_OUT_LOW ; 
 scalar_t__ IS_ERR (struct regulator_dev*) ; 
 size_t LM3631_ENTIME_CONT_MASK ; 
 size_t LM3631_ENTIME_MASK ; 
 size_t LM3631_ENTIME_SHIFT ; 
#define  LM3631_LDO_CONT 133 
#define  LM3631_LDO_NEG 132 
#define  LM3631_LDO_OREF 131 
#define  LM3631_LDO_POS 130 
 size_t LM3631_REG_ENTIME_VCONT ; 
 size_t LM3631_REG_ENTIME_VNEG ; 
 size_t LM3631_REG_ENTIME_VOREF ; 
 size_t LM3631_REG_ENTIME_VPOS ; 
 int /*<<< orphan*/  LM3632_EXT_EN_MASK ; 
#define  LM3632_LDO_NEG 129 
#define  LM3632_LDO_POS 128 
 int /*<<< orphan*/  LM3632_REG_BIAS_CONFIG ; 
 int PTR_ERR (struct regulator_dev*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,int,...) ; 
 struct ti_lmu* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 struct gpio_desc* devm_gpiod_get_index_optional (struct device*,char*,int,int /*<<< orphan*/ ) ; 
 struct regulator_dev* devm_regulator_register (struct device*,int /*<<< orphan*/ *,struct regulator_config*) ; 
 int* ldo_cont_enable_time ; 
 int /*<<< orphan*/ * lm363x_regulator_desc ; 
 int rdev_get_id (struct regulator_dev*) ; 
 scalar_t__ regmap_read (int /*<<< orphan*/ ,size_t,unsigned int*) ; 
 int regmap_update_bits (struct regmap*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int lm363x_regulator_enable_time(struct regulator_dev *rdev)
{
	enum lm363x_regulator_id id = rdev_get_id(rdev);
	u8 val, addr, mask;

	switch (id) {
	case LM3631_LDO_CONT:
		addr = LM3631_REG_ENTIME_VCONT;
		mask = LM3631_ENTIME_CONT_MASK;
		break;
	case LM3631_LDO_OREF:
		addr = LM3631_REG_ENTIME_VOREF;
		mask = LM3631_ENTIME_MASK;
		break;
	case LM3631_LDO_POS:
		addr = LM3631_REG_ENTIME_VPOS;
		mask = LM3631_ENTIME_MASK;
		break;
	case LM3631_LDO_NEG:
		addr = LM3631_REG_ENTIME_VNEG;
		mask = LM3631_ENTIME_MASK;
		break;
	default:
		return 0;
	}

	if (regmap_read(rdev->regmap, addr, (unsigned int *)&val))
		return -EINVAL;

	val = (val & mask) >> LM3631_ENTIME_SHIFT;

	if (id == LM3631_LDO_CONT)
		return ldo_cont_enable_time[val];
	else
		return ENABLE_TIME_USEC * val;
}

__attribute__((used)) static struct gpio_desc *lm363x_regulator_of_get_enable_gpio(struct device *dev, int id)
{
	/*
	 * Check LCM_EN1/2_GPIO is configured.
	 * Those pins are used for enabling VPOS/VNEG LDOs.
	 */
	switch (id) {
	case LM3632_LDO_POS:
		return devm_gpiod_get_index_optional(dev, "enable", 0, GPIOD_OUT_LOW);
	case LM3632_LDO_NEG:
		return devm_gpiod_get_index_optional(dev, "enable", 1, GPIOD_OUT_LOW);
	default:
		return NULL;
	}
}

__attribute__((used)) static int lm363x_regulator_probe(struct platform_device *pdev)
{
	struct ti_lmu *lmu = dev_get_drvdata(pdev->dev.parent);
	struct regmap *regmap = lmu->regmap;
	struct regulator_config cfg = { };
	struct regulator_dev *rdev;
	struct device *dev = &pdev->dev;
	int id = pdev->id;
	struct gpio_desc *gpiod;
	int ret;

	cfg.dev = dev;
	cfg.regmap = regmap;

	/*
	 * LM3632 LDOs can be controlled by external pin.
	 * Register update is required if the pin is used.
	 */
	gpiod = lm363x_regulator_of_get_enable_gpio(dev, id);
	if (gpiod) {
		cfg.ena_gpiod = gpiod;

		ret = regmap_update_bits(regmap, LM3632_REG_BIAS_CONFIG,
					 LM3632_EXT_EN_MASK,
					 LM3632_EXT_EN_MASK);
		if (ret) {
			dev_err(dev, "External pin err: %d\n", ret);
			return ret;
		}
	}

	rdev = devm_regulator_register(dev, &lm363x_regulator_desc[id], &cfg);
	if (IS_ERR(rdev)) {
		ret = PTR_ERR(rdev);
		dev_err(dev, "[%d] regulator register err: %d\n", id, ret);
		return ret;
	}

	return 0;
}

