#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct seq_file {int dummy; } ;
struct resource {int dummy; } ;
struct TYPE_12__ {struct device_node* of_node; } ;
struct platform_device {TYPE_2__ dev; } ;
struct pinctrl_setting {int dummy; } ;
struct pinctrl_map {int dummy; } ;
struct pinctrl_gpio_range {int dummy; } ;
struct pinctrl_dev {int /*<<< orphan*/  dev; int /*<<< orphan*/  pin_desc_tree; } ;
struct pin_desc {int dummy; } ;
struct of_device_id {TYPE_1__* data; } ;
struct gpio_chip {int base; int (* direction_input ) (struct gpio_chip*,unsigned int) ;int (* direction_output ) (struct gpio_chip*,unsigned int,int) ;int (* get ) (struct gpio_chip*,unsigned int) ;void (* set ) (struct gpio_chip*,unsigned int,int) ;int (* to_irq ) (struct gpio_chip*,unsigned int) ;int (* set_config ) (struct gpio_chip*,unsigned int,unsigned long) ;int of_gpio_n_cells; int /*<<< orphan*/  ngpio; struct device_node* of_node; int /*<<< orphan*/  free; int /*<<< orphan*/  request; TYPE_2__* parent; int /*<<< orphan*/  label; } ;
struct mtk_pinctrl {int base; int /*<<< orphan*/  pctrl; TYPE_1__* soc; TYPE_2__* dev; struct mtk_eint* eint; struct gpio_chip chip; } ;
struct mtk_pin_reg_calc {int nranges; struct mtk_pin_field_calc* range; } ;
struct mtk_pin_field_calc {int s_pin; int e_pin; int s_bit; int x_bits; int s_addr; int x_addrs; } ;
struct mtk_pin_field {int offset; int bitpos; int mask; int next; } ;
struct mtk_eint {int base; int /*<<< orphan*/ * gpio_xlate; struct mtk_pinctrl* pctl; int /*<<< orphan*/  hw; TYPE_2__* dev; int /*<<< orphan*/  irq; } ;
struct group_desc {int num_pins; int* data; int* pins; int /*<<< orphan*/  name; } ;
struct function_desc {int /*<<< orphan*/  name; int /*<<< orphan*/  data; int /*<<< orphan*/  num_group_names; int /*<<< orphan*/  group_names; } ;
struct device_node {int dummy; } ;
struct dentry {int dummy; } ;
struct TYPE_13__ {int /*<<< orphan*/  custom_params; int /*<<< orphan*/  num_custom_params; int /*<<< orphan*/  npins; int /*<<< orphan*/  pins; } ;
struct TYPE_11__ {int ngrps; int nfuncs; int /*<<< orphan*/  npins; int /*<<< orphan*/  pins; int /*<<< orphan*/  eint_hw; struct function_desc* funcs; struct group_desc* grps; struct mtk_pin_reg_calc* reg_cal; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int BIT (int) ; 
 int /*<<< orphan*/  CONFIG_EINT_MTK ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ENOTSUPP ; 
 int ENXIO ; 
 int EOPNOTSUPP ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IS_ENABLED (int /*<<< orphan*/ ) ; 
 scalar_t__ IS_ERR (int) ; 
 int MTK_DISABLE ; 
 int MTK_ENABLE ; 
 int MTK_GPIO_MODE ; 
 int MTK_INPUT ; 
 int MTK_OUTPUT ; 
#define  MTK_PIN_CONFIG_RDSEL 138 
#define  MTK_PIN_CONFIG_TDSEL 137 
 int /*<<< orphan*/  PINCTRL_PINCTRL_DEV ; 
 int PINCTRL_PIN_REG_DI ; 
 int PINCTRL_PIN_REG_DIR ; 
 int PINCTRL_PIN_REG_DO ; 
 int PINCTRL_PIN_REG_E4 ; 
 int PINCTRL_PIN_REG_E8 ; 
 int PINCTRL_PIN_REG_MAX ; 
 int PINCTRL_PIN_REG_MODE ; 
 int PINCTRL_PIN_REG_PD ; 
 int PINCTRL_PIN_REG_PU ; 
 int PINCTRL_PIN_REG_RDSEL ; 
 int PINCTRL_PIN_REG_SMT ; 
 int PINCTRL_PIN_REG_SR ; 
 int PINCTRL_PIN_REG_TDSEL ; 
#define  PIN_CONFIG_BIAS_DISABLE 136 
#define  PIN_CONFIG_BIAS_PULL_DOWN 135 
#define  PIN_CONFIG_BIAS_PULL_UP 134 
#define  PIN_CONFIG_DRIVE_STRENGTH 133 
 scalar_t__ PIN_CONFIG_INPUT_DEBOUNCE ; 
#define  PIN_CONFIG_INPUT_ENABLE 132 
#define  PIN_CONFIG_INPUT_SCHMITT_ENABLE 131 
#define  PIN_CONFIG_OUTPUT 130 
#define  PIN_CONFIG_OUTPUT_ENABLE 129 
#define  PIN_CONFIG_SLEW_RATE 128 
 int PTR_ERR (int) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*,...) ; 
 int /*<<< orphan*/  dev_name (TYPE_2__*) ; 
 int /*<<< orphan*/  dev_warn (TYPE_2__*,char*) ; 
 void* devm_ioremap_resource (TYPE_2__*,struct resource*) ; 
 void* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 int devm_pinctrl_register_and_init (TYPE_2__*,TYPE_3__*,struct mtk_pinctrl*,int /*<<< orphan*/ *) ; 
 int get_count_order (int) ; 
 int gpiochip_add_data (struct gpio_chip*,struct mtk_pinctrl*) ; 
 int gpiochip_add_pin_range (struct gpio_chip*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpiochip_generic_free ; 
 int /*<<< orphan*/  gpiochip_generic_request ; 
 struct mtk_pinctrl* gpiochip_get_data (struct gpio_chip*) ; 
 int /*<<< orphan*/  gpiochip_remove (struct gpio_chip*) ; 
 int /*<<< orphan*/  irq_of_parse_and_map (struct device_node*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mtk_custom_bindings ; 
 TYPE_3__ mtk_desc ; 
 int /*<<< orphan*/  mtk_eint_xt ; 
 int /*<<< orphan*/  mtk_pinctrl_of_match ; 
 int /*<<< orphan*/  of_find_property (struct device_node*,char*,int /*<<< orphan*/ *) ; 
 struct of_device_id* of_match_device (int /*<<< orphan*/ ,TYPE_2__*) ; 
 int /*<<< orphan*/  of_property_read_bool (struct device_node*,char*) ; 
 int pinconf_to_config_argument (unsigned long) ; 
 unsigned long pinconf_to_config_packed (int,int) ; 
 scalar_t__ pinconf_to_config_param (unsigned long) ; 
 struct mtk_pinctrl* pinctrl_dev_get_drvdata (struct pinctrl_dev*) ; 
 int pinctrl_enable (int /*<<< orphan*/ ) ; 
 int pinctrl_generic_add_group (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*,int,int*) ; 
 struct group_desc* pinctrl_generic_get_group (struct pinctrl_dev*,unsigned int) ; 
 int pinctrl_generic_get_group_pins (struct pinctrl_dev*,unsigned int,unsigned int const**,unsigned int*) ; 
 int pinctrl_gpio_direction_input (int) ; 
 int pinctrl_gpio_direction_output (int) ; 
 int pinmux_generic_add_function (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct function_desc* pinmux_generic_get_function (struct pinctrl_dev*,unsigned int) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource_byname (struct platform_device*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct mtk_pinctrl*) ; 
 struct pin_desc* radix_tree_lookup (int /*<<< orphan*/ *,unsigned int) ; 
 int readl_relaxed (int) ; 
 int /*<<< orphan*/  writel_relaxed (int,int) ; 

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

__attribute__((used)) static inline int pinmux_check_ops(struct pinctrl_dev *pctldev)
{
	return 0;
}

__attribute__((used)) static inline int pinmux_validate_map(const struct pinctrl_map *map, int i)
{
	return 0;
}

__attribute__((used)) static inline int pinmux_request_gpio(struct pinctrl_dev *pctldev,
			struct pinctrl_gpio_range *range,
			unsigned pin, unsigned gpio)
{
	return 0;
}

__attribute__((used)) static inline void pinmux_free_gpio(struct pinctrl_dev *pctldev,
				    unsigned pin,
				    struct pinctrl_gpio_range *range)
{
}

__attribute__((used)) static inline int pinmux_gpio_direction(struct pinctrl_dev *pctldev,
					struct pinctrl_gpio_range *range,
					unsigned pin, bool input)
{
	return 0;
}

__attribute__((used)) static inline int pinmux_map_to_setting(const struct pinctrl_map *map,
			  struct pinctrl_setting *setting)
{
	return 0;
}

__attribute__((used)) static inline void pinmux_free_setting(const struct pinctrl_setting *setting)
{
}

__attribute__((used)) static inline int pinmux_enable_setting(const struct pinctrl_setting *setting)
{
	return 0;
}

__attribute__((used)) static inline void pinmux_disable_setting(const struct pinctrl_setting *setting)
{
}

__attribute__((used)) static inline void pinmux_show_map(struct seq_file *s,
				   const struct pinctrl_map *map)
{
}

__attribute__((used)) static inline void pinmux_show_setting(struct seq_file *s,
				       const struct pinctrl_setting *setting)
{
}

__attribute__((used)) static inline void pinmux_init_device_debugfs(struct dentry *devroot,
					      struct pinctrl_dev *pctldev)
{
}

__attribute__((used)) static inline void pinmux_generic_free_functions(struct pinctrl_dev *pctldev)
{
}

__attribute__((used)) static inline int mtk_eint_do_init(struct mtk_eint *eint)
{
	return -EOPNOTSUPP;
}

__attribute__((used)) static inline int mtk_eint_do_suspend(struct mtk_eint *eint)
{
	return -EOPNOTSUPP;
}

__attribute__((used)) static inline int mtk_eint_do_resume(struct mtk_eint *eint)
{
	return -EOPNOTSUPP;
}

int mtk_eint_set_debounce(struct mtk_eint *eint, unsigned long eint_n,
			  unsigned int debounce)
{
	return -EOPNOTSUPP;
}

int mtk_eint_find_irq(struct mtk_eint *eint, unsigned long eint_n)
{
	return -EOPNOTSUPP;
}

__attribute__((used)) static void mtk_w32(struct mtk_pinctrl *pctl, u32 reg, u32 val)
{
	writel_relaxed(val, pctl->base + reg);
}

__attribute__((used)) static u32 mtk_r32(struct mtk_pinctrl *pctl, u32 reg)
{
	return readl_relaxed(pctl->base + reg);
}

__attribute__((used)) static void mtk_rmw(struct mtk_pinctrl *pctl, u32 reg, u32 mask, u32 set)
{
	u32 val;

	val = mtk_r32(pctl, reg);
	val &= ~mask;
	val |= set;
	mtk_w32(pctl, reg, val);
}

__attribute__((used)) static int mtk_hw_pin_field_lookup(struct mtk_pinctrl *hw, int pin,
				   const struct mtk_pin_reg_calc *rc,
				   struct mtk_pin_field *pfd)
{
	const struct mtk_pin_field_calc *c, *e;
	u32 bits;

	c = rc->range;
	e = c + rc->nranges;

	while (c < e) {
		if (pin >= c->s_pin && pin <= c->e_pin)
			break;
		c++;
	}

	if (c >= e) {
		dev_err(hw->dev, "Out of range for pin = %d\n", pin);
		return -EINVAL;
	}

	/* Caculated bits as the overall offset the pin is located at */
	bits = c->s_bit + (pin - c->s_pin) * (c->x_bits);

	/* Fill pfd from bits and 32-bit register applied is assumed */
	pfd->offset = c->s_addr + c->x_addrs * (bits / 32);
	pfd->bitpos = bits % 32;
	pfd->mask = (1 << c->x_bits) - 1;

	/* pfd->next is used for indicating that bit wrapping-around happens
	 * which requires the manipulation for bit 0 starting in the next
	 * register to form the complete field read/write.
	 */
	pfd->next = pfd->bitpos + c->x_bits - 1 > 31 ? c->x_addrs : 0;

	return 0;
}

__attribute__((used)) static int mtk_hw_pin_field_get(struct mtk_pinctrl *hw, int pin,
				int field, struct mtk_pin_field *pfd)
{
	const struct mtk_pin_reg_calc *rc;

	if (field < 0 || field >= PINCTRL_PIN_REG_MAX) {
		dev_err(hw->dev, "Invalid Field %d\n", field);
		return -EINVAL;
	}

	if (hw->soc->reg_cal && hw->soc->reg_cal[field].range) {
		rc = &hw->soc->reg_cal[field];
	} else {
		dev_err(hw->dev, "Undefined range for field %d\n", field);
		return -EINVAL;
	}

	return mtk_hw_pin_field_lookup(hw, pin, rc, pfd);
}

__attribute__((used)) static void mtk_hw_bits_part(struct mtk_pin_field *pf, int *h, int *l)
{
	*l = 32 - pf->bitpos;
	*h = get_count_order(pf->mask) - *l;
}

__attribute__((used)) static void mtk_hw_write_cross_field(struct mtk_pinctrl *hw,
				     struct mtk_pin_field *pf, int value)
{
	int nbits_l, nbits_h;

	mtk_hw_bits_part(pf, &nbits_h, &nbits_l);

	mtk_rmw(hw, pf->offset, pf->mask << pf->bitpos,
		(value & pf->mask) << pf->bitpos);

	mtk_rmw(hw, pf->offset + pf->next, BIT(nbits_h) - 1,
		(value & pf->mask) >> nbits_l);
}

__attribute__((used)) static void mtk_hw_read_cross_field(struct mtk_pinctrl *hw,
				    struct mtk_pin_field *pf, int *value)
{
	int nbits_l, nbits_h, h, l;

	mtk_hw_bits_part(pf, &nbits_h, &nbits_l);

	l  = (mtk_r32(hw, pf->offset) >> pf->bitpos) & (BIT(nbits_l) - 1);
	h  = (mtk_r32(hw, pf->offset + pf->next)) & (BIT(nbits_h) - 1);

	*value = (h << nbits_l) | l;
}

__attribute__((used)) static int mtk_hw_set_value(struct mtk_pinctrl *hw, int pin, int field,
			    int value)
{
	struct mtk_pin_field pf;
	int err;

	err = mtk_hw_pin_field_get(hw, pin, field, &pf);
	if (err)
		return err;

	if (!pf.next)
		mtk_rmw(hw, pf.offset, pf.mask << pf.bitpos,
			(value & pf.mask) << pf.bitpos);
	else
		mtk_hw_write_cross_field(hw, &pf, value);

	return 0;
}

__attribute__((used)) static int mtk_hw_get_value(struct mtk_pinctrl *hw, int pin, int field,
			    int *value)
{
	struct mtk_pin_field pf;
	int err;

	err = mtk_hw_pin_field_get(hw, pin, field, &pf);
	if (err)
		return err;

	if (!pf.next)
		*value = (mtk_r32(hw, pf.offset) >> pf.bitpos) & pf.mask;
	else
		mtk_hw_read_cross_field(hw, &pf, value);

	return 0;
}

__attribute__((used)) static int mtk_pinmux_set_mux(struct pinctrl_dev *pctldev,
			      unsigned int selector, unsigned int group)
{
	struct mtk_pinctrl *hw = pinctrl_dev_get_drvdata(pctldev);
	struct function_desc *func;
	struct group_desc *grp;
	int i;

	func = pinmux_generic_get_function(pctldev, selector);
	if (!func)
		return -EINVAL;

	grp = pinctrl_generic_get_group(pctldev, group);
	if (!grp)
		return -EINVAL;

	dev_dbg(pctldev->dev, "enable function %s group %s\n",
		func->name, grp->name);

	for (i = 0; i < grp->num_pins; i++) {
		int *pin_modes = grp->data;

		mtk_hw_set_value(hw, grp->pins[i], PINCTRL_PIN_REG_MODE,
				 pin_modes[i]);
	}

	return 0;
}

__attribute__((used)) static int mtk_pinmux_gpio_request_enable(struct pinctrl_dev *pctldev,
					  struct pinctrl_gpio_range *range,
					  unsigned int pin)
{
	struct mtk_pinctrl *hw = pinctrl_dev_get_drvdata(pctldev);

	return mtk_hw_set_value(hw, pin, PINCTRL_PIN_REG_MODE, MTK_GPIO_MODE);
}

__attribute__((used)) static int mtk_pinmux_gpio_set_direction(struct pinctrl_dev *pctldev,
					 struct pinctrl_gpio_range *range,
					 unsigned int pin, bool input)
{
	struct mtk_pinctrl *hw = pinctrl_dev_get_drvdata(pctldev);

	/* hardware would take 0 as input direction */
	return mtk_hw_set_value(hw, pin, PINCTRL_PIN_REG_DIR, !input);
}

__attribute__((used)) static int mtk_pinconf_get(struct pinctrl_dev *pctldev,
			   unsigned int pin, unsigned long *config)
{
	struct mtk_pinctrl *hw = pinctrl_dev_get_drvdata(pctldev);
	u32 param = pinconf_to_config_param(*config);
	int val, val2, err, reg, ret = 1;

	switch (param) {
	case PIN_CONFIG_BIAS_DISABLE:
		err = mtk_hw_get_value(hw, pin, PINCTRL_PIN_REG_PU, &val);
		if (err)
			return err;

		err = mtk_hw_get_value(hw, pin, PINCTRL_PIN_REG_PD, &val2);
		if (err)
			return err;

		if (val || val2)
			return -EINVAL;

		break;
	case PIN_CONFIG_BIAS_PULL_UP:
	case PIN_CONFIG_BIAS_PULL_DOWN:
	case PIN_CONFIG_SLEW_RATE:
		reg = (param == PIN_CONFIG_BIAS_PULL_UP) ?
		      PINCTRL_PIN_REG_PU :
		      (param == PIN_CONFIG_BIAS_PULL_DOWN) ?
		      PINCTRL_PIN_REG_PD : PINCTRL_PIN_REG_SR;

		err = mtk_hw_get_value(hw, pin, reg, &val);
		if (err)
			return err;

		if (!val)
			return -EINVAL;

		break;
	case PIN_CONFIG_INPUT_ENABLE:
	case PIN_CONFIG_OUTPUT_ENABLE:
		err = mtk_hw_get_value(hw, pin, PINCTRL_PIN_REG_DIR, &val);
		if (err)
			return err;

		/* HW takes input mode as zero; output mode as non-zero */
		if ((val && param == PIN_CONFIG_INPUT_ENABLE) ||
		    (!val && param == PIN_CONFIG_OUTPUT_ENABLE))
			return -EINVAL;

		break;
	case PIN_CONFIG_INPUT_SCHMITT_ENABLE:
		err = mtk_hw_get_value(hw, pin, PINCTRL_PIN_REG_DIR, &val);
		if (err)
			return err;

		err = mtk_hw_get_value(hw, pin, PINCTRL_PIN_REG_SMT, &val2);
		if (err)
			return err;

		if (val || !val2)
			return -EINVAL;

		break;
	case PIN_CONFIG_DRIVE_STRENGTH:
		err = mtk_hw_get_value(hw, pin, PINCTRL_PIN_REG_E4, &val);
		if (err)
			return err;

		err = mtk_hw_get_value(hw, pin, PINCTRL_PIN_REG_E8, &val2);
		if (err)
			return err;

		/* 4mA when (e8, e4) = (0, 0); 8mA when (e8, e4) = (0, 1)
		 * 12mA when (e8, e4) = (1, 0); 16mA when (e8, e4) = (1, 1)
		 */
		ret = ((val2 << 1) + val + 1) * 4;

		break;
	case MTK_PIN_CONFIG_TDSEL:
	case MTK_PIN_CONFIG_RDSEL:
		reg = (param == MTK_PIN_CONFIG_TDSEL) ?
		       PINCTRL_PIN_REG_TDSEL : PINCTRL_PIN_REG_RDSEL;

		err = mtk_hw_get_value(hw, pin, reg, &val);
		if (err)
			return err;

		ret = val;

		break;
	default:
		return -ENOTSUPP;
	}

	*config = pinconf_to_config_packed(param, ret);

	return 0;
}

__attribute__((used)) static int mtk_pinconf_set(struct pinctrl_dev *pctldev, unsigned int pin,
			   unsigned long *configs, unsigned int num_configs)
{
	struct mtk_pinctrl *hw = pinctrl_dev_get_drvdata(pctldev);
	u32 reg, param, arg;
	int cfg, err = 0;

	for (cfg = 0; cfg < num_configs; cfg++) {
		param = pinconf_to_config_param(configs[cfg]);
		arg = pinconf_to_config_argument(configs[cfg]);

		switch (param) {
		case PIN_CONFIG_BIAS_DISABLE:
		case PIN_CONFIG_BIAS_PULL_UP:
		case PIN_CONFIG_BIAS_PULL_DOWN:
			arg = (param == PIN_CONFIG_BIAS_DISABLE) ? 0 :
			       (param == PIN_CONFIG_BIAS_PULL_UP) ? 1 : 2;

			err = mtk_hw_set_value(hw, pin, PINCTRL_PIN_REG_PU,
					       arg & 1);
			if (err)
				goto err;

			err = mtk_hw_set_value(hw, pin, PINCTRL_PIN_REG_PD,
					       !!(arg & 2));
			if (err)
				goto err;
			break;
		case PIN_CONFIG_OUTPUT_ENABLE:
			err = mtk_hw_set_value(hw, pin, PINCTRL_PIN_REG_SMT,
					       MTK_DISABLE);
			if (err)
				goto err;
			/* else: fall through */
		case PIN_CONFIG_INPUT_ENABLE:
		case PIN_CONFIG_SLEW_RATE:
			reg = (param == PIN_CONFIG_SLEW_RATE) ?
			       PINCTRL_PIN_REG_SR : PINCTRL_PIN_REG_DIR;

			arg = (param == PIN_CONFIG_INPUT_ENABLE) ? 0 :
			      (param == PIN_CONFIG_OUTPUT_ENABLE) ? 1 : arg;
			err = mtk_hw_set_value(hw, pin, reg, arg);
			if (err)
				goto err;

			break;
		case PIN_CONFIG_OUTPUT:
			err = mtk_hw_set_value(hw, pin, PINCTRL_PIN_REG_DIR,
					       MTK_OUTPUT);
			if (err)
				goto err;

			err = mtk_hw_set_value(hw, pin, PINCTRL_PIN_REG_DO,
					       arg);
			if (err)
				goto err;
			break;
		case PIN_CONFIG_INPUT_SCHMITT_ENABLE:
			/* arg = 1: Input mode & SMT enable ;
			 * arg = 0: Output mode & SMT disable
			 */
			arg = arg ? 2 : 1;
			err = mtk_hw_set_value(hw, pin, PINCTRL_PIN_REG_DIR,
					       arg & 1);
			if (err)
				goto err;

			err = mtk_hw_set_value(hw, pin, PINCTRL_PIN_REG_SMT,
					       !!(arg & 2));
			if (err)
				goto err;
			break;
		case PIN_CONFIG_DRIVE_STRENGTH:
			/* 4mA when (e8, e4) = (0, 0);
			 * 8mA when (e8, e4) = (0, 1);
			 * 12mA when (e8, e4) = (1, 0);
			 * 16mA when (e8, e4) = (1, 1)
			 */
			if (!(arg % 4) && (arg >= 4 && arg <= 16)) {
				arg = arg / 4 - 1;
				err = mtk_hw_set_value(hw, pin,
						       PINCTRL_PIN_REG_E4,
						       arg & 0x1);
				if (err)
					goto err;

				err = mtk_hw_set_value(hw, pin,
						       PINCTRL_PIN_REG_E8,
						       (arg & 0x2) >> 1);
				if (err)
					goto err;
			} else {
				err = -ENOTSUPP;
			}
			break;
		case MTK_PIN_CONFIG_TDSEL:
		case MTK_PIN_CONFIG_RDSEL:
			reg = (param == MTK_PIN_CONFIG_TDSEL) ?
			       PINCTRL_PIN_REG_TDSEL : PINCTRL_PIN_REG_RDSEL;

			err = mtk_hw_set_value(hw, pin, reg, arg);
			if (err)
				goto err;
			break;
		default:
			err = -ENOTSUPP;
		}
	}
err:
	return err;
}

__attribute__((used)) static int mtk_pinconf_group_get(struct pinctrl_dev *pctldev,
				 unsigned int group, unsigned long *config)
{
	const unsigned int *pins;
	unsigned int i, npins, old = 0;
	int ret;

	ret = pinctrl_generic_get_group_pins(pctldev, group, &pins, &npins);
	if (ret)
		return ret;

	for (i = 0; i < npins; i++) {
		if (mtk_pinconf_get(pctldev, pins[i], config))
			return -ENOTSUPP;

		/* configs do not match between two pins */
		if (i && old != *config)
			return -ENOTSUPP;

		old = *config;
	}

	return 0;
}

__attribute__((used)) static int mtk_pinconf_group_set(struct pinctrl_dev *pctldev,
				 unsigned int group, unsigned long *configs,
				 unsigned int num_configs)
{
	const unsigned int *pins;
	unsigned int i, npins;
	int ret;

	ret = pinctrl_generic_get_group_pins(pctldev, group, &pins, &npins);
	if (ret)
		return ret;

	for (i = 0; i < npins; i++) {
		ret = mtk_pinconf_set(pctldev, pins[i], configs, num_configs);
		if (ret)
			return ret;
	}

	return 0;
}

__attribute__((used)) static int mtk_gpio_get(struct gpio_chip *chip, unsigned int gpio)
{
	struct mtk_pinctrl *hw = gpiochip_get_data(chip);
	int value, err;

	err = mtk_hw_get_value(hw, gpio, PINCTRL_PIN_REG_DI, &value);
	if (err)
		return err;

	return !!value;
}

__attribute__((used)) static void mtk_gpio_set(struct gpio_chip *chip, unsigned int gpio, int value)
{
	struct mtk_pinctrl *hw = gpiochip_get_data(chip);

	mtk_hw_set_value(hw, gpio, PINCTRL_PIN_REG_DO, !!value);
}

__attribute__((used)) static int mtk_gpio_direction_input(struct gpio_chip *chip, unsigned int gpio)
{
	return pinctrl_gpio_direction_input(chip->base + gpio);
}

__attribute__((used)) static int mtk_gpio_direction_output(struct gpio_chip *chip, unsigned int gpio,
				     int value)
{
	mtk_gpio_set(chip, gpio, value);

	return pinctrl_gpio_direction_output(chip->base + gpio);
}

__attribute__((used)) static int mtk_gpio_to_irq(struct gpio_chip *chip, unsigned int offset)
{
	struct mtk_pinctrl *hw = gpiochip_get_data(chip);
	unsigned long eint_n;

	if (!hw->eint)
		return -ENOTSUPP;

	eint_n = offset;

	return mtk_eint_find_irq(hw->eint, eint_n);
}

__attribute__((used)) static int mtk_gpio_set_config(struct gpio_chip *chip, unsigned int offset,
			       unsigned long config)
{
	struct mtk_pinctrl *hw = gpiochip_get_data(chip);
	unsigned long eint_n;
	u32 debounce;

	if (!hw->eint ||
	    pinconf_to_config_param(config) != PIN_CONFIG_INPUT_DEBOUNCE)
		return -ENOTSUPP;

	debounce = pinconf_to_config_argument(config);
	eint_n = offset;

	return mtk_eint_set_debounce(hw->eint, eint_n, debounce);
}

__attribute__((used)) static int mtk_build_gpiochip(struct mtk_pinctrl *hw, struct device_node *np)
{
	struct gpio_chip *chip = &hw->chip;
	int ret;

	chip->label		= PINCTRL_PINCTRL_DEV;
	chip->parent		= hw->dev;
	chip->request		= gpiochip_generic_request;
	chip->free		= gpiochip_generic_free;
	chip->direction_input	= mtk_gpio_direction_input;
	chip->direction_output	= mtk_gpio_direction_output;
	chip->get		= mtk_gpio_get;
	chip->set		= mtk_gpio_set;
	chip->to_irq		= mtk_gpio_to_irq,
	chip->set_config	= mtk_gpio_set_config,
	chip->base		= -1;
	chip->ngpio		= hw->soc->npins;
	chip->of_node		= np;
	chip->of_gpio_n_cells	= 2;

	ret = gpiochip_add_data(chip, hw);
	if (ret < 0)
		return ret;

	/* Just for backward compatible for these old pinctrl nodes without
	 * "gpio-ranges" property. Otherwise, called directly from a
	 * DeviceTree-supported pinctrl driver is DEPRECATED.
	 * Please see Section 2.1 of
	 * Documentation/devicetree/bindings/gpio/gpio.txt on how to
	 * bind pinctrl and gpio drivers via the "gpio-ranges" property.
	 */
	if (!of_find_property(np, "gpio-ranges", NULL)) {
		ret = gpiochip_add_pin_range(chip, dev_name(hw->dev), 0, 0,
					     chip->ngpio);
		if (ret < 0) {
			gpiochip_remove(chip);
			return ret;
		}
	}

	return 0;
}

__attribute__((used)) static int mtk_build_groups(struct mtk_pinctrl *hw)
{
	int err, i;

	for (i = 0; i < hw->soc->ngrps; i++) {
		const struct group_desc *group = hw->soc->grps + i;

		err = pinctrl_generic_add_group(hw->pctrl, group->name,
						group->pins, group->num_pins,
						group->data);
		if (err < 0) {
			dev_err(hw->dev, "Failed to register group %s\n",
				group->name);
			return err;
		}
	}

	return 0;
}

__attribute__((used)) static int mtk_build_functions(struct mtk_pinctrl *hw)
{
	int i, err;

	for (i = 0; i < hw->soc->nfuncs ; i++) {
		const struct function_desc *func = hw->soc->funcs + i;

		err = pinmux_generic_add_function(hw->pctrl, func->name,
						  func->group_names,
						  func->num_group_names,
						  func->data);
		if (err < 0) {
			dev_err(hw->dev, "Failed to register function %s\n",
				func->name);
			return err;
		}
	}

	return 0;
}

__attribute__((used)) static int mtk_xt_get_gpio_n(void *data, unsigned long eint_n,
			     unsigned int *gpio_n,
			     struct gpio_chip **gpio_chip)
{
	struct mtk_pinctrl *hw = (struct mtk_pinctrl *)data;

	*gpio_chip = &hw->chip;
	*gpio_n = eint_n;

	return 0;
}

__attribute__((used)) static int mtk_xt_get_gpio_state(void *data, unsigned long eint_n)
{
	struct mtk_pinctrl *hw = (struct mtk_pinctrl *)data;
	struct gpio_chip *gpio_chip;
	unsigned int gpio_n;
	int err;

	err = mtk_xt_get_gpio_n(hw, eint_n, &gpio_n, &gpio_chip);
	if (err)
		return err;

	return mtk_gpio_get(gpio_chip, gpio_n);
}

__attribute__((used)) static int mtk_xt_set_gpio_as_eint(void *data, unsigned long eint_n)
{
	struct mtk_pinctrl *hw = (struct mtk_pinctrl *)data;
	struct gpio_chip *gpio_chip;
	unsigned int gpio_n;
	int err;

	err = mtk_xt_get_gpio_n(hw, eint_n, &gpio_n, &gpio_chip);
	if (err)
		return err;

	err = mtk_hw_set_value(hw, gpio_n, PINCTRL_PIN_REG_MODE,
			       MTK_GPIO_MODE);
	if (err)
		return err;

	err = mtk_hw_set_value(hw, gpio_n, PINCTRL_PIN_REG_DIR, MTK_INPUT);
	if (err)
		return err;

	err = mtk_hw_set_value(hw, gpio_n, PINCTRL_PIN_REG_SMT, MTK_ENABLE);
	if (err)
		return err;

	return 0;
}

__attribute__((used)) static int
mtk_build_eint(struct mtk_pinctrl *hw, struct platform_device *pdev)
{
	struct device_node *np = pdev->dev.of_node;
	struct resource *res;

	if (!IS_ENABLED(CONFIG_EINT_MTK))
		return 0;

	if (!of_property_read_bool(np, "interrupt-controller"))
		return -ENODEV;

	hw->eint = devm_kzalloc(hw->dev, sizeof(*hw->eint), GFP_KERNEL);
	if (!hw->eint)
		return -ENOMEM;

	res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "eint");
	if (!res) {
		dev_err(&pdev->dev, "Unable to get eint resource\n");
		return -ENODEV;
	}

	hw->eint->base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(hw->eint->base))
		return PTR_ERR(hw->eint->base);

	hw->eint->irq = irq_of_parse_and_map(np, 0);
	if (!hw->eint->irq)
		return -EINVAL;

	hw->eint->dev = &pdev->dev;
	hw->eint->hw = hw->soc->eint_hw;
	hw->eint->pctl = hw;
	hw->eint->gpio_xlate = &mtk_eint_xt;

	return mtk_eint_do_init(hw->eint);
}

__attribute__((used)) static int mtk_pinctrl_probe(struct platform_device *pdev)
{
	struct resource *res;
	struct mtk_pinctrl *hw;
	const struct of_device_id *of_id =
		of_match_device(mtk_pinctrl_of_match, &pdev->dev);
	int err;

	hw = devm_kzalloc(&pdev->dev, sizeof(*hw), GFP_KERNEL);
	if (!hw)
		return -ENOMEM;

	hw->soc = of_id->data;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!res) {
		dev_err(&pdev->dev, "missing IO resource\n");
		return -ENXIO;
	}

	hw->dev = &pdev->dev;
	hw->base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(hw->base))
		return PTR_ERR(hw->base);

	/* Setup pins descriptions per SoC types */
	mtk_desc.pins = hw->soc->pins;
	mtk_desc.npins = hw->soc->npins;
	mtk_desc.num_custom_params = ARRAY_SIZE(mtk_custom_bindings);
	mtk_desc.custom_params = mtk_custom_bindings;
#ifdef CONFIG_DEBUG_FS
	mtk_desc.custom_conf_items = mtk_conf_items;
#endif

	err = devm_pinctrl_register_and_init(&pdev->dev, &mtk_desc, hw,
					     &hw->pctrl);
	if (err)
		return err;

	/* Setup groups descriptions per SoC types */
	err = mtk_build_groups(hw);
	if (err) {
		dev_err(&pdev->dev, "Failed to build groups\n");
		return err;
	}

	/* Setup functions descriptions per SoC types */
	err = mtk_build_functions(hw);
	if (err) {
		dev_err(&pdev->dev, "Failed to build functions\n");
		return err;
	}

	/* For able to make pinctrl_claim_hogs, we must not enable pinctrl
	 * until all groups and functions are being added one.
	 */
	err = pinctrl_enable(hw->pctrl);
	if (err)
		return err;

	err = mtk_build_eint(hw, pdev);
	if (err)
		dev_warn(&pdev->dev,
			 "Failed to add EINT, but pinctrl still can work\n");

	/* Build gpiochip should be after pinctrl_enable is done */
	err = mtk_build_gpiochip(hw, pdev->dev.of_node);
	if (err) {
		dev_err(&pdev->dev, "Failed to add gpio_chip\n");
		return err;
	}

	platform_set_drvdata(pdev, hw);

	return 0;
}

