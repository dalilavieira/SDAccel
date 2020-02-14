#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_6__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned int u8 ;
typedef  void* u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct seq_file {int dummy; } ;
struct device {TYPE_6__* parent; int /*<<< orphan*/  of_node; } ;
struct platform_device {struct device dev; } ;
struct pinctrl_setting {int dummy; } ;
struct pinctrl_map {int dummy; } ;
struct pinctrl_dev {int /*<<< orphan*/  pin_desc_tree; } ;
struct pin_desc {int dummy; } ;
struct max77620_pctrl_info {int num_pin_groups; int num_functions; int /*<<< orphan*/  pctl; struct max77620_fps_config* fps_config; TYPE_3__* pin_groups; TYPE_2__* functions; void* num_pins; void* pins; int /*<<< orphan*/  rmap; struct device* dev; TYPE_1__* pin_info; } ;
struct max77620_fps_config {int active_fps_src; int suspend_fps_src; int active_power_up_slots; int suspend_power_up_slots; int active_power_down_slots; int suspend_power_down_slots; } ;
struct max77620_chip {int /*<<< orphan*/  rmap; } ;
struct dentry {int dummy; } ;
typedef  enum pin_config_param { ____Placeholder_pin_config_param } pin_config_param ;
struct TYPE_11__ {int /*<<< orphan*/  of_node; } ;
struct TYPE_10__ {void* custom_params; void* num_custom_params; void* npins; void* pins; int /*<<< orphan*/  name; } ;
struct TYPE_9__ {char const* name; unsigned int* pins; unsigned int npins; unsigned int alt_option; } ;
struct TYPE_8__ {char const* name; char** groups; unsigned int ngroups; } ;
struct TYPE_7__ {void* drv_type; } ;

/* Variables and functions */
 void* ARRAY_SIZE (void*) ; 
 int BIT (unsigned int) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int ENOTSUPP ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
#define  MAX77620_ACTIVE_FPS_POWER_DOWN_SLOTS 137 
#define  MAX77620_ACTIVE_FPS_POWER_ON_SLOTS 136 
#define  MAX77620_ACTIVE_FPS_SOURCE 135 
 int MAX77620_CNFG_GPIO_DRV_MASK ; 
 int MAX77620_FPS_PD_PERIOD_MASK ; 
 int MAX77620_FPS_PD_PERIOD_SHIFT ; 
 int MAX77620_FPS_PU_PERIOD_MASK ; 
 int MAX77620_FPS_PU_PERIOD_SHIFT ; 
 void* MAX77620_FPS_SRC_DEF ; 
 unsigned int MAX77620_FPS_SRC_MASK ; 
 unsigned int MAX77620_FPS_SRC_SHIFT ; 
 int MAX77620_GPIO1 ; 
 int MAX77620_GPIO3 ; 
 unsigned int MAX77620_PINMUX_GPIO ; 
 int MAX77620_PIN_NUM ; 
 void* MAX77620_PIN_OD_DRV ; 
 void* MAX77620_PIN_PP_DRV ; 
 unsigned int MAX77620_REG_AME_GPIO ; 
 int MAX77620_REG_FPS_GPIO1 ; 
 unsigned int MAX77620_REG_GPIO0 ; 
 unsigned int MAX77620_REG_PDE_GPIO ; 
 unsigned int MAX77620_REG_PUE_GPIO ; 
#define  MAX77620_SUSPEND_FPS_POWER_DOWN_SLOTS 134 
#define  MAX77620_SUSPEND_FPS_POWER_ON_SLOTS 133 
#define  MAX77620_SUSPEND_FPS_SOURCE 132 
#define  PIN_CONFIG_BIAS_PULL_DOWN 131 
#define  PIN_CONFIG_BIAS_PULL_UP 130 
#define  PIN_CONFIG_DRIVE_OPEN_DRAIN 129 
#define  PIN_CONFIG_DRIVE_PUSH_PULL 128 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct max77620_chip* dev_get_drvdata (TYPE_6__*) ; 
 int /*<<< orphan*/  dev_name (struct device*) ; 
 struct max77620_pctrl_info* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_pinctrl_register (struct device*,TYPE_4__*,struct max77620_pctrl_info*) ; 
 void* max77620_cfg_params ; 
 void* max77620_pin_function ; 
 TYPE_4__ max77620_pinctrl_desc ; 
 void* max77620_pingroups ; 
 void* max77620_pins_desc ; 
 void* pinconf_to_config_argument (unsigned long) ; 
 unsigned long pinconf_to_config_packed (int,int /*<<< orphan*/ ) ; 
 int pinconf_to_config_param (unsigned long) ; 
 struct max77620_pctrl_info* pinctrl_dev_get_drvdata (struct pinctrl_dev*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct max77620_pctrl_info*) ; 
 struct pin_desc* radix_tree_lookup (int /*<<< orphan*/ *,unsigned int) ; 
 int regmap_read (int /*<<< orphan*/ ,int,unsigned int*) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,unsigned int,int,unsigned int) ; 

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

__attribute__((used)) static int max77620_pinctrl_get_groups_count(struct pinctrl_dev *pctldev)
{
	struct max77620_pctrl_info *mpci = pinctrl_dev_get_drvdata(pctldev);

	return mpci->num_pin_groups;
}

__attribute__((used)) static const char *max77620_pinctrl_get_group_name(
		struct pinctrl_dev *pctldev, unsigned int group)
{
	struct max77620_pctrl_info *mpci = pinctrl_dev_get_drvdata(pctldev);

	return mpci->pin_groups[group].name;
}

__attribute__((used)) static int max77620_pinctrl_get_group_pins(
		struct pinctrl_dev *pctldev, unsigned int group,
		const unsigned int **pins, unsigned int *num_pins)
{
	struct max77620_pctrl_info *mpci = pinctrl_dev_get_drvdata(pctldev);

	*pins = mpci->pin_groups[group].pins;
	*num_pins = mpci->pin_groups[group].npins;

	return 0;
}

__attribute__((used)) static int max77620_pinctrl_get_funcs_count(struct pinctrl_dev *pctldev)
{
	struct max77620_pctrl_info *mpci = pinctrl_dev_get_drvdata(pctldev);

	return mpci->num_functions;
}

__attribute__((used)) static const char *max77620_pinctrl_get_func_name(struct pinctrl_dev *pctldev,
						  unsigned int function)
{
	struct max77620_pctrl_info *mpci = pinctrl_dev_get_drvdata(pctldev);

	return mpci->functions[function].name;
}

__attribute__((used)) static int max77620_pinctrl_get_func_groups(struct pinctrl_dev *pctldev,
					    unsigned int function,
					    const char * const **groups,
					    unsigned int * const num_groups)
{
	struct max77620_pctrl_info *mpci = pinctrl_dev_get_drvdata(pctldev);

	*groups = mpci->functions[function].groups;
	*num_groups = mpci->functions[function].ngroups;

	return 0;
}

__attribute__((used)) static int max77620_pinctrl_enable(struct pinctrl_dev *pctldev,
				   unsigned int function, unsigned int group)
{
	struct max77620_pctrl_info *mpci = pinctrl_dev_get_drvdata(pctldev);
	u8 val;
	int ret;

	if (function == MAX77620_PINMUX_GPIO) {
		val = 0;
	} else if (function == mpci->pin_groups[group].alt_option) {
		val = 1 << group;
	} else {
		dev_err(mpci->dev, "GPIO %u doesn't have function %u\n",
			group, function);
		return -EINVAL;
	}
	ret = regmap_update_bits(mpci->rmap, MAX77620_REG_AME_GPIO,
				 BIT(group), val);
	if (ret < 0)
		dev_err(mpci->dev, "REG AME GPIO update failed: %d\n", ret);

	return ret;
}

__attribute__((used)) static int max77620_pinconf_get(struct pinctrl_dev *pctldev,
				unsigned int pin, unsigned long *config)
{
	struct max77620_pctrl_info *mpci = pinctrl_dev_get_drvdata(pctldev);
	struct device *dev = mpci->dev;
	enum pin_config_param param = pinconf_to_config_param(*config);
	unsigned int val;
	int arg = 0;
	int ret;

	switch (param) {
	case PIN_CONFIG_DRIVE_OPEN_DRAIN:
		if (mpci->pin_info[pin].drv_type == MAX77620_PIN_OD_DRV)
			arg = 1;
		break;

	case PIN_CONFIG_DRIVE_PUSH_PULL:
		if (mpci->pin_info[pin].drv_type == MAX77620_PIN_PP_DRV)
			arg = 1;
		break;

	case PIN_CONFIG_BIAS_PULL_UP:
		ret = regmap_read(mpci->rmap, MAX77620_REG_PUE_GPIO, &val);
		if (ret < 0) {
			dev_err(dev, "Reg PUE_GPIO read failed: %d\n", ret);
			return ret;
		}
		if (val & BIT(pin))
			arg = 1;
		break;

	case PIN_CONFIG_BIAS_PULL_DOWN:
		ret = regmap_read(mpci->rmap, MAX77620_REG_PDE_GPIO, &val);
		if (ret < 0) {
			dev_err(dev, "Reg PDE_GPIO read failed: %d\n", ret);
			return ret;
		}
		if (val & BIT(pin))
			arg = 1;
		break;

	default:
		dev_err(dev, "Properties not supported\n");
		return -ENOTSUPP;
	}

	*config = pinconf_to_config_packed(param, (u16)arg);

	return 0;
}

__attribute__((used)) static int max77620_get_default_fps(struct max77620_pctrl_info *mpci,
				    int addr, int *fps)
{
	unsigned int val;
	int ret;

	ret = regmap_read(mpci->rmap, addr, &val);
	if (ret < 0) {
		dev_err(mpci->dev, "Reg PUE_GPIO read failed: %d\n", ret);
		return ret;
	}
	*fps = (val & MAX77620_FPS_SRC_MASK) >> MAX77620_FPS_SRC_SHIFT;

	return 0;
}

__attribute__((used)) static int max77620_set_fps_param(struct max77620_pctrl_info *mpci,
				  int pin, int param)
{
	struct max77620_fps_config *fps_config = &mpci->fps_config[pin];
	int addr, ret;
	int param_val;
	int mask, shift;

	if ((pin < MAX77620_GPIO1) || (pin > MAX77620_GPIO3))
		return 0;

	addr = MAX77620_REG_FPS_GPIO1 + pin - 1;
	switch (param) {
	case MAX77620_ACTIVE_FPS_SOURCE:
	case MAX77620_SUSPEND_FPS_SOURCE:
		mask = MAX77620_FPS_SRC_MASK;
		shift = MAX77620_FPS_SRC_SHIFT;
		param_val = fps_config->active_fps_src;
		if (param == MAX77620_SUSPEND_FPS_SOURCE)
			param_val = fps_config->suspend_fps_src;
		break;

	case MAX77620_ACTIVE_FPS_POWER_ON_SLOTS:
	case MAX77620_SUSPEND_FPS_POWER_ON_SLOTS:
		mask = MAX77620_FPS_PU_PERIOD_MASK;
		shift = MAX77620_FPS_PU_PERIOD_SHIFT;
		param_val = fps_config->active_power_up_slots;
		if (param == MAX77620_SUSPEND_FPS_POWER_ON_SLOTS)
			param_val = fps_config->suspend_power_up_slots;
		break;

	case MAX77620_ACTIVE_FPS_POWER_DOWN_SLOTS:
	case MAX77620_SUSPEND_FPS_POWER_DOWN_SLOTS:
		mask = MAX77620_FPS_PD_PERIOD_MASK;
		shift = MAX77620_FPS_PD_PERIOD_SHIFT;
		param_val = fps_config->active_power_down_slots;
		if (param == MAX77620_SUSPEND_FPS_POWER_DOWN_SLOTS)
			param_val = fps_config->suspend_power_down_slots;
		break;

	default:
		dev_err(mpci->dev, "Invalid parameter %d for pin %d\n",
			param, pin);
		return -EINVAL;
	}

	if (param_val < 0)
		return 0;

	ret = regmap_update_bits(mpci->rmap, addr, mask, param_val << shift);
	if (ret < 0)
		dev_err(mpci->dev, "Reg 0x%02x update failed %d\n", addr, ret);

	return ret;
}

__attribute__((used)) static int max77620_pinconf_set(struct pinctrl_dev *pctldev,
				unsigned int pin, unsigned long *configs,
				unsigned int num_configs)
{
	struct max77620_pctrl_info *mpci = pinctrl_dev_get_drvdata(pctldev);
	struct device *dev = mpci->dev;
	struct max77620_fps_config *fps_config;
	int param;
	u32 param_val;
	unsigned int val;
	unsigned int pu_val;
	unsigned int pd_val;
	int addr, ret;
	int i;

	for (i = 0; i < num_configs; i++) {
		param = pinconf_to_config_param(configs[i]);
		param_val = pinconf_to_config_argument(configs[i]);

		switch (param) {
		case PIN_CONFIG_DRIVE_OPEN_DRAIN:
			val = param_val ? 0 : 1;
			ret = regmap_update_bits(mpci->rmap,
						 MAX77620_REG_GPIO0 + pin,
						 MAX77620_CNFG_GPIO_DRV_MASK,
						 val);
			if (ret)
				goto report_update_failure;

			mpci->pin_info[pin].drv_type = val ?
				MAX77620_PIN_PP_DRV : MAX77620_PIN_OD_DRV;
			break;

		case PIN_CONFIG_DRIVE_PUSH_PULL:
			val = param_val ? 1 : 0;
			ret = regmap_update_bits(mpci->rmap,
						 MAX77620_REG_GPIO0 + pin,
						 MAX77620_CNFG_GPIO_DRV_MASK,
						 val);
			if (ret)
				goto report_update_failure;

			mpci->pin_info[pin].drv_type = val ?
				MAX77620_PIN_PP_DRV : MAX77620_PIN_OD_DRV;
			break;

		case MAX77620_ACTIVE_FPS_SOURCE:
		case MAX77620_ACTIVE_FPS_POWER_ON_SLOTS:
		case MAX77620_ACTIVE_FPS_POWER_DOWN_SLOTS:
			if ((pin < MAX77620_GPIO1) || (pin > MAX77620_GPIO3))
				return -EINVAL;

			fps_config = &mpci->fps_config[pin];

			if ((param == MAX77620_ACTIVE_FPS_SOURCE) &&
			    (param_val == MAX77620_FPS_SRC_DEF)) {
				addr = MAX77620_REG_FPS_GPIO1 + pin - 1;
				ret = max77620_get_default_fps(
						mpci, addr,
						&fps_config->active_fps_src);
				if (ret < 0)
					return ret;
				break;
			}

			if (param == MAX77620_ACTIVE_FPS_SOURCE)
				fps_config->active_fps_src = param_val;
			else if (param == MAX77620_ACTIVE_FPS_POWER_ON_SLOTS)
				fps_config->active_power_up_slots = param_val;
			else
				fps_config->active_power_down_slots = param_val;

			ret = max77620_set_fps_param(mpci, pin, param);
			if (ret < 0)
				return ret;
			break;

		case MAX77620_SUSPEND_FPS_SOURCE:
		case MAX77620_SUSPEND_FPS_POWER_ON_SLOTS:
		case MAX77620_SUSPEND_FPS_POWER_DOWN_SLOTS:
			if ((pin < MAX77620_GPIO1) || (pin > MAX77620_GPIO3))
				return -EINVAL;

			fps_config = &mpci->fps_config[pin];

			if ((param == MAX77620_SUSPEND_FPS_SOURCE) &&
			    (param_val == MAX77620_FPS_SRC_DEF)) {
				addr = MAX77620_REG_FPS_GPIO1 + pin - 1;
				ret = max77620_get_default_fps(
						mpci, addr,
						&fps_config->suspend_fps_src);
				if (ret < 0)
					return ret;
				break;
			}

			if (param == MAX77620_SUSPEND_FPS_SOURCE)
				fps_config->suspend_fps_src = param_val;
			else if (param == MAX77620_SUSPEND_FPS_POWER_ON_SLOTS)
				fps_config->suspend_power_up_slots = param_val;
			else
				fps_config->suspend_power_down_slots =
								param_val;
			break;

		case PIN_CONFIG_BIAS_PULL_UP:
		case PIN_CONFIG_BIAS_PULL_DOWN:
			pu_val = (param == PIN_CONFIG_BIAS_PULL_UP) ?
							BIT(pin) : 0;
			pd_val = (param == PIN_CONFIG_BIAS_PULL_DOWN) ?
							BIT(pin) : 0;

			ret = regmap_update_bits(mpci->rmap,
						 MAX77620_REG_PUE_GPIO,
						 BIT(pin), pu_val);
			if (ret < 0) {
				dev_err(dev, "PUE_GPIO update failed: %d\n",
					ret);
				return ret;
			}

			ret = regmap_update_bits(mpci->rmap,
						 MAX77620_REG_PDE_GPIO,
						 BIT(pin), pd_val);
			if (ret < 0) {
				dev_err(dev, "PDE_GPIO update failed: %d\n",
					ret);
				return ret;
			}
			break;

		default:
			dev_err(dev, "Properties not supported\n");
			return -ENOTSUPP;
		}
	}

	return 0;

report_update_failure:
	dev_err(dev, "Reg 0x%02x update failed %d\n",
		MAX77620_REG_GPIO0 + pin, ret);
	return ret;
}

__attribute__((used)) static int max77620_pinctrl_probe(struct platform_device *pdev)
{
	struct max77620_chip *max77620 = dev_get_drvdata(pdev->dev.parent);
	struct max77620_pctrl_info *mpci;
	int i;

	mpci = devm_kzalloc(&pdev->dev, sizeof(*mpci), GFP_KERNEL);
	if (!mpci)
		return -ENOMEM;

	mpci->dev = &pdev->dev;
	mpci->dev->of_node = pdev->dev.parent->of_node;
	mpci->rmap = max77620->rmap;

	mpci->pins = max77620_pins_desc;
	mpci->num_pins = ARRAY_SIZE(max77620_pins_desc);
	mpci->functions = max77620_pin_function;
	mpci->num_functions = ARRAY_SIZE(max77620_pin_function);
	mpci->pin_groups = max77620_pingroups;
	mpci->num_pin_groups = ARRAY_SIZE(max77620_pingroups);
	platform_set_drvdata(pdev, mpci);

	max77620_pinctrl_desc.name = dev_name(&pdev->dev);
	max77620_pinctrl_desc.pins = max77620_pins_desc;
	max77620_pinctrl_desc.npins = ARRAY_SIZE(max77620_pins_desc);
	max77620_pinctrl_desc.num_custom_params =
				ARRAY_SIZE(max77620_cfg_params);
	max77620_pinctrl_desc.custom_params = max77620_cfg_params;

	for (i = 0; i < MAX77620_PIN_NUM; ++i) {
		mpci->fps_config[i].active_fps_src = -1;
		mpci->fps_config[i].active_power_up_slots = -1;
		mpci->fps_config[i].active_power_down_slots = -1;
		mpci->fps_config[i].suspend_fps_src = -1;
		mpci->fps_config[i].suspend_power_up_slots = -1;
		mpci->fps_config[i].suspend_power_down_slots = -1;
	}

	mpci->pctl = devm_pinctrl_register(&pdev->dev, &max77620_pinctrl_desc,
					   mpci);
	if (IS_ERR(mpci->pctl)) {
		dev_err(&pdev->dev, "Couldn't register pinctrl driver\n");
		return PTR_ERR(mpci->pctl);
	}

	return 0;
}

