#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_19__   TYPE_5__ ;
typedef  struct TYPE_18__   TYPE_4__ ;
typedef  struct TYPE_17__   TYPE_3__ ;
typedef  struct TYPE_16__   TYPE_2__ ;
typedef  struct TYPE_15__   TYPE_1__ ;
typedef  struct TYPE_14__   TYPE_11__ ;
typedef  struct TYPE_13__   TYPE_10__ ;

/* Type definitions */
typedef  unsigned int u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct seq_file {int dummy; } ;
struct gpio_chip {void* ngpio; int /*<<< orphan*/  of_node; TYPE_5__* parent; scalar_t__ base; } ;
struct TYPE_18__ {void* npins; void* pins; } ;
struct rk805_pctrl_info {int num_pin_groups; int num_functions; struct gpio_chip gpio_chip; int /*<<< orphan*/  pctl; TYPE_4__ pinctrl_desc; TYPE_10__* rk808; TYPE_3__* pin_cfg; TYPE_2__* groups; TYPE_1__* functions; void* num_pins; void* pins; TYPE_5__* dev; } ;
struct TYPE_19__ {TYPE_11__* parent; int /*<<< orphan*/  of_node; } ;
struct platform_device {TYPE_5__ dev; } ;
struct pinctrl_setting {int dummy; } ;
struct pinctrl_map {int dummy; } ;
struct pinctrl_gpio_range {int dummy; } ;
struct pinctrl_dev {int /*<<< orphan*/  pin_desc_tree; } ;
struct pin_desc {int dummy; } ;
struct dentry {int dummy; } ;
typedef  enum pin_config_param { ____Placeholder_pin_config_param } pin_config_param ;
struct TYPE_17__ {int val_msk; unsigned int dir_msk; unsigned int fun_msk; int /*<<< orphan*/  reg; } ;
struct TYPE_16__ {char const* name; unsigned int* pins; unsigned int npins; } ;
struct TYPE_15__ {char const* name; char** groups; unsigned int ngroups; int mux_option; } ;
struct TYPE_14__ {int /*<<< orphan*/  of_node; } ;
struct TYPE_13__ {int variant; int /*<<< orphan*/  regmap; } ;

/* Variables and functions */
 void* ARRAY_SIZE (void*) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int ENOTSUPP ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
#define  PIN_CONFIG_OUTPUT 129 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
#define  RK805_ID 128 
 int RK805_PINMUX_GPIO ; 
 int /*<<< orphan*/  dev_err (TYPE_5__*,char*,...) ; 
 TYPE_10__* dev_get_drvdata (TYPE_11__*) ; 
 int /*<<< orphan*/  dev_name (TYPE_5__*) ; 
 int devm_gpiochip_add_data (TYPE_5__*,struct gpio_chip*,struct rk805_pctrl_info*) ; 
 struct rk805_pctrl_info* devm_kzalloc (TYPE_5__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_pinctrl_register (TYPE_5__*,TYPE_4__*,struct rk805_pctrl_info*) ; 
 int gpiochip_add_pin_range (struct gpio_chip*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*) ; 
 struct rk805_pctrl_info* gpiochip_get_data (struct gpio_chip*) ; 
 unsigned int pinconf_to_config_argument (unsigned long) ; 
 unsigned long pinconf_to_config_packed (int,int /*<<< orphan*/ ) ; 
 int pinconf_to_config_param (unsigned long) ; 
 struct rk805_pctrl_info* pinctrl_dev_get_drvdata (struct pinctrl_dev*) ; 
 int pinctrl_gpio_direction_input (scalar_t__) ; 
 int pinctrl_gpio_direction_output (scalar_t__) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct rk805_pctrl_info*) ; 
 struct pin_desc* radix_tree_lookup (int /*<<< orphan*/ *,unsigned int) ; 
 int regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,...) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int,unsigned int) ; 
 void* rk805_gpio_cfgs ; 
 struct gpio_chip rk805_gpio_chip ; 
 void* rk805_pin_functions ; 
 void* rk805_pin_groups ; 
 TYPE_4__ rk805_pinctrl_desc ; 
 void* rk805_pins_desc ; 

__attribute__((used)) static inline struct pin_desc *pin_desc_get(struct pinctrl_dev *pctldev,
					    unsigned int pin)
{
	return radix_tree_lookup(&pctldev->pin_desc_tree, pin);
}

__attribute__((used)) static inline int pinconf_check_ops(struct pinctrl_dev *pctldev)
{
	return 0;
}

__attribute__((used)) static inline int pinconf_validate_map(const struct pinctrl_map *map, int i)
{
	return 0;
}

__attribute__((used)) static inline int pinconf_map_to_setting(const struct pinctrl_map *map,
			  struct pinctrl_setting *setting)
{
	return 0;
}

__attribute__((used)) static inline void pinconf_free_setting(const struct pinctrl_setting *setting)
{
}

__attribute__((used)) static inline int pinconf_apply_setting(const struct pinctrl_setting *setting)
{
	return 0;
}

__attribute__((used)) static inline int pinconf_set_config(struct pinctrl_dev *pctldev, unsigned pin,
				     unsigned long *configs, size_t nconfigs)
{
	return -ENOTSUPP;
}

__attribute__((used)) static inline void pinconf_show_map(struct seq_file *s,
				    const struct pinctrl_map *map)
{
}

__attribute__((used)) static inline void pinconf_show_setting(struct seq_file *s,
					const struct pinctrl_setting *setting)
{
}

__attribute__((used)) static inline void pinconf_init_device_debugfs(struct dentry *devroot,
					       struct pinctrl_dev *pctldev)
{
}

__attribute__((used)) static inline void pinconf_generic_dump_pins(struct pinctrl_dev *pctldev,
					     struct seq_file *s,
					     const char *gname, unsigned pin)
{
	return;
}

__attribute__((used)) static inline void pinconf_generic_dump_config(struct pinctrl_dev *pctldev,
					       struct seq_file *s,
					       unsigned long config)
{
	return;
}

__attribute__((used)) static int rk805_gpio_get(struct gpio_chip *chip, unsigned int offset)
{
	struct rk805_pctrl_info *pci = gpiochip_get_data(chip);
	int ret, val;

	ret = regmap_read(pci->rk808->regmap, pci->pin_cfg[offset].reg, &val);
	if (ret) {
		dev_err(pci->dev, "get gpio%d value failed\n", offset);
		return ret;
	}

	return !!(val & pci->pin_cfg[offset].val_msk);
}

__attribute__((used)) static void rk805_gpio_set(struct gpio_chip *chip,
			   unsigned int offset,
			   int value)
{
	struct rk805_pctrl_info *pci = gpiochip_get_data(chip);
	int ret;

	ret = regmap_update_bits(pci->rk808->regmap,
				 pci->pin_cfg[offset].reg,
				 pci->pin_cfg[offset].val_msk,
				 value ? pci->pin_cfg[offset].val_msk : 0);
	if (ret)
		dev_err(pci->dev, "set gpio%d value %d failed\n",
			offset, value);
}

__attribute__((used)) static int rk805_gpio_direction_input(struct gpio_chip *chip,
				      unsigned int offset)
{
	return pinctrl_gpio_direction_input(chip->base + offset);
}

__attribute__((used)) static int rk805_gpio_direction_output(struct gpio_chip *chip,
				       unsigned int offset, int value)
{
	rk805_gpio_set(chip, offset, value);
	return pinctrl_gpio_direction_output(chip->base + offset);
}

__attribute__((used)) static int rk805_gpio_get_direction(struct gpio_chip *chip, unsigned int offset)
{
	struct rk805_pctrl_info *pci = gpiochip_get_data(chip);
	unsigned int val;
	int ret;

	/* default output*/
	if (!pci->pin_cfg[offset].dir_msk)
		return 0;

	ret = regmap_read(pci->rk808->regmap,
			  pci->pin_cfg[offset].reg,
			  &val);
	if (ret) {
		dev_err(pci->dev, "get gpio%d direction failed\n", offset);
		return ret;
	}

	return !(val & pci->pin_cfg[offset].dir_msk);
}

__attribute__((used)) static int rk805_pinctrl_get_groups_count(struct pinctrl_dev *pctldev)
{
	struct rk805_pctrl_info *pci = pinctrl_dev_get_drvdata(pctldev);

	return pci->num_pin_groups;
}

__attribute__((used)) static const char *rk805_pinctrl_get_group_name(struct pinctrl_dev *pctldev,
						unsigned int group)
{
	struct rk805_pctrl_info *pci = pinctrl_dev_get_drvdata(pctldev);

	return pci->groups[group].name;
}

__attribute__((used)) static int rk805_pinctrl_get_group_pins(struct pinctrl_dev *pctldev,
					unsigned int group,
					const unsigned int **pins,
					unsigned int *num_pins)
{
	struct rk805_pctrl_info *pci = pinctrl_dev_get_drvdata(pctldev);

	*pins = pci->groups[group].pins;
	*num_pins = pci->groups[group].npins;

	return 0;
}

__attribute__((used)) static int rk805_pinctrl_get_funcs_count(struct pinctrl_dev *pctldev)
{
	struct rk805_pctrl_info *pci = pinctrl_dev_get_drvdata(pctldev);

	return pci->num_functions;
}

__attribute__((used)) static const char *rk805_pinctrl_get_func_name(struct pinctrl_dev *pctldev,
					       unsigned int function)
{
	struct rk805_pctrl_info *pci = pinctrl_dev_get_drvdata(pctldev);

	return pci->functions[function].name;
}

__attribute__((used)) static int rk805_pinctrl_get_func_groups(struct pinctrl_dev *pctldev,
					 unsigned int function,
					 const char *const **groups,
					 unsigned int *const num_groups)
{
	struct rk805_pctrl_info *pci = pinctrl_dev_get_drvdata(pctldev);

	*groups = pci->functions[function].groups;
	*num_groups = pci->functions[function].ngroups;

	return 0;
}

__attribute__((used)) static int _rk805_pinctrl_set_mux(struct pinctrl_dev *pctldev,
				  unsigned int offset,
				  int mux)
{
	struct rk805_pctrl_info *pci = pinctrl_dev_get_drvdata(pctldev);
	int ret;

	if (!pci->pin_cfg[offset].fun_msk)
		return 0;

	if (mux == RK805_PINMUX_GPIO) {
		ret = regmap_update_bits(pci->rk808->regmap,
					 pci->pin_cfg[offset].reg,
					 pci->pin_cfg[offset].fun_msk,
					 pci->pin_cfg[offset].fun_msk);
		if (ret) {
			dev_err(pci->dev, "set gpio%d GPIO failed\n", offset);
			return ret;
		}
	} else {
		dev_err(pci->dev, "Couldn't find function mux %d\n", mux);
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int rk805_pinctrl_set_mux(struct pinctrl_dev *pctldev,
				 unsigned int function,
				 unsigned int group)
{
	struct rk805_pctrl_info *pci = pinctrl_dev_get_drvdata(pctldev);
	int mux = pci->functions[function].mux_option;
	int offset = group;

	return _rk805_pinctrl_set_mux(pctldev, offset, mux);
}

__attribute__((used)) static int rk805_pmx_gpio_set_direction(struct pinctrl_dev *pctldev,
					struct pinctrl_gpio_range *range,
					unsigned int offset, bool input)
{
	struct rk805_pctrl_info *pci = pinctrl_dev_get_drvdata(pctldev);
	int ret;

	/* switch to gpio function */
	ret = _rk805_pinctrl_set_mux(pctldev, offset, RK805_PINMUX_GPIO);
	if (ret) {
		dev_err(pci->dev, "set gpio%d mux failed\n", offset);
		return ret;
	}

	/* set direction */
	if (!pci->pin_cfg[offset].dir_msk)
		return 0;

	ret = regmap_update_bits(pci->rk808->regmap,
				 pci->pin_cfg[offset].reg,
				 pci->pin_cfg[offset].dir_msk,
				 input ? 0 : pci->pin_cfg[offset].dir_msk);
	if (ret) {
		dev_err(pci->dev, "set gpio%d direction failed\n", offset);
		return ret;
	}

	return ret;
}

__attribute__((used)) static int rk805_pinconf_get(struct pinctrl_dev *pctldev,
			     unsigned int pin, unsigned long *config)
{
	struct rk805_pctrl_info *pci = pinctrl_dev_get_drvdata(pctldev);
	enum pin_config_param param = pinconf_to_config_param(*config);
	u32 arg = 0;

	switch (param) {
	case PIN_CONFIG_OUTPUT:
		arg = rk805_gpio_get(&pci->gpio_chip, pin);
		break;
	default:
		dev_err(pci->dev, "Properties not supported\n");
		return -ENOTSUPP;
	}

	*config = pinconf_to_config_packed(param, (u16)arg);

	return 0;
}

__attribute__((used)) static int rk805_pinconf_set(struct pinctrl_dev *pctldev,
			     unsigned int pin, unsigned long *configs,
			     unsigned int num_configs)
{
	struct rk805_pctrl_info *pci = pinctrl_dev_get_drvdata(pctldev);
	enum pin_config_param param;
	u32 i, arg = 0;

	for (i = 0; i < num_configs; i++) {
		param = pinconf_to_config_param(configs[i]);
		arg = pinconf_to_config_argument(configs[i]);

		switch (param) {
		case PIN_CONFIG_OUTPUT:
			rk805_gpio_set(&pci->gpio_chip, pin, arg);
			rk805_pmx_gpio_set_direction(pctldev, NULL, pin, false);
			break;
		default:
			dev_err(pci->dev, "Properties not supported\n");
			return -ENOTSUPP;
		}
	}

	return 0;
}

__attribute__((used)) static int rk805_pinctrl_probe(struct platform_device *pdev)
{
	struct rk805_pctrl_info *pci;
	int ret;

	pci = devm_kzalloc(&pdev->dev, sizeof(*pci), GFP_KERNEL);
	if (!pci)
		return -ENOMEM;

	pci->dev = &pdev->dev;
	pci->dev->of_node = pdev->dev.parent->of_node;
	pci->rk808 = dev_get_drvdata(pdev->dev.parent);

	pci->pinctrl_desc = rk805_pinctrl_desc;
	pci->gpio_chip = rk805_gpio_chip;
	pci->gpio_chip.parent = &pdev->dev;
	pci->gpio_chip.of_node = pdev->dev.parent->of_node;

	platform_set_drvdata(pdev, pci);

	switch (pci->rk808->variant) {
	case RK805_ID:
		pci->pins = rk805_pins_desc;
		pci->num_pins = ARRAY_SIZE(rk805_pins_desc);
		pci->functions = rk805_pin_functions;
		pci->num_functions = ARRAY_SIZE(rk805_pin_functions);
		pci->groups = rk805_pin_groups;
		pci->num_pin_groups = ARRAY_SIZE(rk805_pin_groups);
		pci->pinctrl_desc.pins = rk805_pins_desc;
		pci->pinctrl_desc.npins = ARRAY_SIZE(rk805_pins_desc);
		pci->pin_cfg = rk805_gpio_cfgs;
		pci->gpio_chip.ngpio = ARRAY_SIZE(rk805_gpio_cfgs);
		break;
	default:
		dev_err(&pdev->dev, "unsupported RK805 ID %lu\n",
			pci->rk808->variant);
		return -EINVAL;
	}

	/* Add gpio chip */
	ret = devm_gpiochip_add_data(&pdev->dev, &pci->gpio_chip, pci);
	if (ret < 0) {
		dev_err(&pdev->dev, "Couldn't add gpiochip\n");
		return ret;
	}

	/* Add pinctrl */
	pci->pctl = devm_pinctrl_register(&pdev->dev, &pci->pinctrl_desc, pci);
	if (IS_ERR(pci->pctl)) {
		dev_err(&pdev->dev, "Couldn't add pinctrl\n");
		return PTR_ERR(pci->pctl);
	}

	/* Add pin range */
	ret = gpiochip_add_pin_range(&pci->gpio_chip, dev_name(&pdev->dev),
				     0, 0, pci->gpio_chip.ngpio);
	if (ret < 0) {
		dev_err(&pdev->dev, "Couldn't add gpiochip pin range\n");
		return ret;
	}

	return 0;
}

