#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_8__ ;
typedef  struct TYPE_14__   TYPE_5__ ;
typedef  struct TYPE_13__   TYPE_4__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct resource {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct pinctrl_xway_soc {int pin_count; int /*<<< orphan*/  num_exin; int /*<<< orphan*/  exin; int /*<<< orphan*/  num_funcs; int /*<<< orphan*/  funcs; int /*<<< orphan*/  num_grps; int /*<<< orphan*/  grps; int /*<<< orphan*/  mfp; } ;
struct pinctrl_pin_desc {int dummy; } ;
struct pinctrl_dev {int /*<<< orphan*/  dev; int /*<<< orphan*/  pin_desc_tree; } ;
struct pin_desc {int dummy; } ;
struct of_device_id {scalar_t__ data; } ;
struct ltq_pinmux_info {int num_exin; unsigned int* exin; int /*<<< orphan*/ * membase; TYPE_1__* grps; } ;
struct gpio_chip {int /*<<< orphan*/  parent; } ;
typedef  enum ltq_pinconf_param { ____Placeholder_ltq_pinconf_param } ltq_pinconf_param ;
struct TYPE_15__ {char* name; scalar_t__ number; } ;
struct TYPE_14__ {int ngpio; int /*<<< orphan*/  base; int /*<<< orphan*/ * parent; } ;
struct TYPE_13__ {int npins; int /*<<< orphan*/  base; } ;
struct TYPE_12__ {int num_pads; int num_mfp; int /*<<< orphan*/  pctrl; int /*<<< orphan*/  num_exin; int /*<<< orphan*/  exin; int /*<<< orphan*/  num_funcs; int /*<<< orphan*/  funcs; int /*<<< orphan*/  num_grps; int /*<<< orphan*/  grps; int /*<<< orphan*/  mfp; TYPE_8__* pads; int /*<<< orphan*/ * membase; } ;
struct TYPE_11__ {int npins; int /*<<< orphan*/  name; TYPE_8__* pins; } ;
struct TYPE_10__ {int npins; unsigned int* pins; } ;

/* Variables and functions */
 int ENOMEM ; 
 int ENOTSUPP ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ GPIO0 ; 
 int /*<<< orphan*/  GPIO3_ALT1 ; 
 int /*<<< orphan*/  GPIO3_OD ; 
 int /*<<< orphan*/  GPIO3_PUDEN ; 
 int /*<<< orphan*/  GPIO3_PUDSEL ; 
 int /*<<< orphan*/  GPIO_ALT0 (int) ; 
 int /*<<< orphan*/  GPIO_ALT1 (int) ; 
 int /*<<< orphan*/  GPIO_DIR (unsigned int) ; 
 int /*<<< orphan*/  GPIO_IN (unsigned int) ; 
 int /*<<< orphan*/  GPIO_OD (unsigned int) ; 
 int /*<<< orphan*/  GPIO_OUT (unsigned int) ; 
 int /*<<< orphan*/  GPIO_PUDEN (unsigned int) ; 
 int /*<<< orphan*/  GPIO_PUDSEL (unsigned int) ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 unsigned long LTQ_PINCONF_PACK (int,int) ; 
#define  LTQ_PINCONF_PARAM_OPEN_DRAIN 130 
#define  LTQ_PINCONF_PARAM_OUTPUT 129 
#define  LTQ_PINCONF_PARAM_PULL 128 
 int LTQ_PINCONF_UNPACK_ARG (unsigned long) ; 
 int LTQ_PINCONF_UNPACK_PARAM (unsigned long) ; 
 int MUX_ALT0 ; 
 int MUX_ALT1 ; 
 int PORT (unsigned int) ; 
 int PORT3 ; 
 int /*<<< orphan*/  PORT_PIN (unsigned int) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 struct pinctrl_xway_soc danube_pinctrl ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 struct ltq_pinmux_info* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  dev_name (int /*<<< orphan*/ *) ; 
 int devm_gpiochip_add_data (int /*<<< orphan*/ *,TYPE_5__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  devm_ioremap_resource (int /*<<< orphan*/ *,struct resource*) ; 
 TYPE_8__* devm_kcalloc (int /*<<< orphan*/ *,int,int,int /*<<< orphan*/ ) ; 
 char* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpio_clearbit (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int gpio_getbit (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpio_setbit (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int ltq_eiu_get_irq (int) ; 
 int ltq_pinctrl_register (struct platform_device*,TYPE_3__*) ; 
 struct of_device_id* of_match_device (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pinctrl_add_gpio_range (int /*<<< orphan*/ ,TYPE_4__*) ; 
 struct ltq_pinmux_info* pinctrl_dev_get_drvdata (struct pinctrl_dev*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct pin_desc* radix_tree_lookup (int /*<<< orphan*/ *,unsigned int) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,int) ; 
 TYPE_5__ xway_chip ; 
 TYPE_4__ xway_gpio_range ; 
 TYPE_3__ xway_info ; 
 int /*<<< orphan*/  xway_match ; 
 TYPE_2__ xway_pctrl_desc ; 

__attribute__((used)) static inline struct pin_desc *pin_desc_get(struct pinctrl_dev *pctldev,
					    unsigned int pin)
{
	return radix_tree_lookup(&pctldev->pin_desc_tree, pin);
}

__attribute__((used)) static int xway_pinconf_get(struct pinctrl_dev *pctldev,
				unsigned pin,
				unsigned long *config)
{
	struct ltq_pinmux_info *info = pinctrl_dev_get_drvdata(pctldev);
	enum ltq_pinconf_param param = LTQ_PINCONF_UNPACK_PARAM(*config);
	int port = PORT(pin);
	u32 reg;

	switch (param) {
	case LTQ_PINCONF_PARAM_OPEN_DRAIN:
		if (port == PORT3)
			reg = GPIO3_OD;
		else
			reg = GPIO_OD(pin);
		*config = LTQ_PINCONF_PACK(param,
			!gpio_getbit(info->membase[0], reg, PORT_PIN(pin)));
		break;

	case LTQ_PINCONF_PARAM_PULL:
		if (port == PORT3)
			reg = GPIO3_PUDEN;
		else
			reg = GPIO_PUDEN(pin);
		if (!gpio_getbit(info->membase[0], reg, PORT_PIN(pin))) {
			*config = LTQ_PINCONF_PACK(param, 0);
			break;
		}

		if (port == PORT3)
			reg = GPIO3_PUDSEL;
		else
			reg = GPIO_PUDSEL(pin);
		if (!gpio_getbit(info->membase[0], reg, PORT_PIN(pin)))
			*config = LTQ_PINCONF_PACK(param, 2);
		else
			*config = LTQ_PINCONF_PACK(param, 1);
		break;

	case LTQ_PINCONF_PARAM_OUTPUT:
		reg = GPIO_DIR(pin);
		*config = LTQ_PINCONF_PACK(param,
			gpio_getbit(info->membase[0], reg, PORT_PIN(pin)));
		break;
	default:
		dev_err(pctldev->dev, "Invalid config param %04x\n", param);
		return -ENOTSUPP;
	}
	return 0;
}

__attribute__((used)) static int xway_pinconf_set(struct pinctrl_dev *pctldev,
				unsigned pin,
				unsigned long *configs,
				unsigned num_configs)
{
	struct ltq_pinmux_info *info = pinctrl_dev_get_drvdata(pctldev);
	enum ltq_pinconf_param param;
	int arg;
	int port = PORT(pin);
	u32 reg;
	int i;

	for (i = 0; i < num_configs; i++) {
		param = LTQ_PINCONF_UNPACK_PARAM(configs[i]);
		arg = LTQ_PINCONF_UNPACK_ARG(configs[i]);

		switch (param) {
		case LTQ_PINCONF_PARAM_OPEN_DRAIN:
			if (port == PORT3)
				reg = GPIO3_OD;
			else
				reg = GPIO_OD(pin);
			if (arg == 0)
				gpio_setbit(info->membase[0],
					reg,
					PORT_PIN(pin));
			else
				gpio_clearbit(info->membase[0],
					reg,
					PORT_PIN(pin));
			break;

		case LTQ_PINCONF_PARAM_PULL:
			if (port == PORT3)
				reg = GPIO3_PUDEN;
			else
				reg = GPIO_PUDEN(pin);
			if (arg == 0) {
				gpio_clearbit(info->membase[0],
					reg,
					PORT_PIN(pin));
				break;
			}
			gpio_setbit(info->membase[0], reg, PORT_PIN(pin));

			if (port == PORT3)
				reg = GPIO3_PUDSEL;
			else
				reg = GPIO_PUDSEL(pin);
			if (arg == 1)
				gpio_clearbit(info->membase[0],
					reg,
					PORT_PIN(pin));
			else if (arg == 2)
				gpio_setbit(info->membase[0],
					reg,
					PORT_PIN(pin));
			else
				dev_err(pctldev->dev,
					"Invalid pull value %d\n", arg);
			break;

		case LTQ_PINCONF_PARAM_OUTPUT:
			reg = GPIO_DIR(pin);
			if (arg == 0)
				gpio_clearbit(info->membase[0],
					reg,
					PORT_PIN(pin));
			else
				gpio_setbit(info->membase[0],
					reg,
					PORT_PIN(pin));
			break;

		default:
			dev_err(pctldev->dev,
				"Invalid config param %04x\n", param);
			return -ENOTSUPP;
		}
	} /* for each config */

	return 0;
}

int xway_pinconf_group_set(struct pinctrl_dev *pctldev,
			unsigned selector,
			unsigned long *configs,
			unsigned num_configs)
{
	struct ltq_pinmux_info *info = pinctrl_dev_get_drvdata(pctldev);
	int i, ret = 0;

	for (i = 0; i < info->grps[selector].npins && !ret; i++)
		ret = xway_pinconf_set(pctldev,
				info->grps[selector].pins[i],
				configs,
				num_configs);

	return ret;
}

__attribute__((used)) static inline int xway_mux_apply(struct pinctrl_dev *pctrldev,
				int pin, int mux)
{
	struct ltq_pinmux_info *info = pinctrl_dev_get_drvdata(pctrldev);
	int port = PORT(pin);
	u32 alt1_reg = GPIO_ALT1(pin);

	if (port == PORT3)
		alt1_reg = GPIO3_ALT1;

	if (mux & MUX_ALT0)
		gpio_setbit(info->membase[0], GPIO_ALT0(pin), PORT_PIN(pin));
	else
		gpio_clearbit(info->membase[0], GPIO_ALT0(pin), PORT_PIN(pin));

	if (mux & MUX_ALT1)
		gpio_setbit(info->membase[0], alt1_reg, PORT_PIN(pin));
	else
		gpio_clearbit(info->membase[0], alt1_reg, PORT_PIN(pin));

	return 0;
}

__attribute__((used)) static void xway_gpio_set(struct gpio_chip *chip, unsigned int pin, int val)
{
	struct ltq_pinmux_info *info = dev_get_drvdata(chip->parent);

	if (val)
		gpio_setbit(info->membase[0], GPIO_OUT(pin), PORT_PIN(pin));
	else
		gpio_clearbit(info->membase[0], GPIO_OUT(pin), PORT_PIN(pin));
}

__attribute__((used)) static int xway_gpio_get(struct gpio_chip *chip, unsigned int pin)
{
	struct ltq_pinmux_info *info = dev_get_drvdata(chip->parent);

	return !!gpio_getbit(info->membase[0], GPIO_IN(pin), PORT_PIN(pin));
}

__attribute__((used)) static int xway_gpio_dir_in(struct gpio_chip *chip, unsigned int pin)
{
	struct ltq_pinmux_info *info = dev_get_drvdata(chip->parent);

	gpio_clearbit(info->membase[0], GPIO_DIR(pin), PORT_PIN(pin));

	return 0;
}

__attribute__((used)) static int xway_gpio_dir_out(struct gpio_chip *chip, unsigned int pin, int val)
{
	struct ltq_pinmux_info *info = dev_get_drvdata(chip->parent);

	if (PORT(pin) == PORT3)
		gpio_setbit(info->membase[0], GPIO3_OD, PORT_PIN(pin));
	else
		gpio_setbit(info->membase[0], GPIO_OD(pin), PORT_PIN(pin));
	gpio_setbit(info->membase[0], GPIO_DIR(pin), PORT_PIN(pin));
	xway_gpio_set(chip, pin, val);

	return 0;
}

__attribute__((used)) static int xway_gpio_to_irq(struct gpio_chip *chip, unsigned offset)
{
	struct ltq_pinmux_info *info = dev_get_drvdata(chip->parent);
	int i;

	for (i = 0; i < info->num_exin; i++)
		if (info->exin[i] == offset)
			return ltq_eiu_get_irq(i);

	return -1;
}

__attribute__((used)) static int pinmux_xway_probe(struct platform_device *pdev)
{
	const struct of_device_id *match;
	const struct pinctrl_xway_soc *xway_soc;
	struct resource *res;
	int ret, i;

	/* get and remap our register range */
	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	xway_info.membase[0] = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(xway_info.membase[0]))
		return PTR_ERR(xway_info.membase[0]);

	match = of_match_device(xway_match, &pdev->dev);
	if (match)
		xway_soc = (const struct pinctrl_xway_soc *) match->data;
	else
		xway_soc = &danube_pinctrl;

	/* find out how many pads we have */
	xway_chip.ngpio = xway_soc->pin_count;

	/* load our pad descriptors */
	xway_info.pads = devm_kcalloc(&pdev->dev,
			xway_chip.ngpio, sizeof(struct pinctrl_pin_desc),
			GFP_KERNEL);
	if (!xway_info.pads)
		return -ENOMEM;

	for (i = 0; i < xway_chip.ngpio; i++) {
		/* strlen("ioXY") + 1 = 5 */
		char *name = devm_kzalloc(&pdev->dev, 5, GFP_KERNEL);

		if (!name)
			return -ENOMEM;

		snprintf(name, 5, "io%d", i);
		xway_info.pads[i].number = GPIO0 + i;
		xway_info.pads[i].name = name;
	}
	xway_pctrl_desc.pins = xway_info.pads;

	/* register the gpio chip */
	xway_chip.parent = &pdev->dev;
	ret = devm_gpiochip_add_data(&pdev->dev, &xway_chip, NULL);
	if (ret) {
		dev_err(&pdev->dev, "Failed to register gpio chip\n");
		return ret;
	}

	/* setup the data needed by pinctrl */
	xway_pctrl_desc.name	= dev_name(&pdev->dev);
	xway_pctrl_desc.npins	= xway_chip.ngpio;

	xway_info.num_pads	= xway_chip.ngpio;
	xway_info.num_mfp	= xway_chip.ngpio;
	xway_info.mfp		= xway_soc->mfp;
	xway_info.grps		= xway_soc->grps;
	xway_info.num_grps	= xway_soc->num_grps;
	xway_info.funcs		= xway_soc->funcs;
	xway_info.num_funcs	= xway_soc->num_funcs;
	xway_info.exin		= xway_soc->exin;
	xway_info.num_exin	= xway_soc->num_exin;

	/* register with the generic lantiq layer */
	ret = ltq_pinctrl_register(pdev, &xway_info);
	if (ret) {
		dev_err(&pdev->dev, "Failed to register pinctrl driver\n");
		return ret;
	}

	/* finish with registering the gpio range in pinctrl */
	xway_gpio_range.npins = xway_chip.ngpio;
	xway_gpio_range.base = xway_chip.base;
	pinctrl_add_gpio_range(xway_info.pctrl, &xway_gpio_range);
	dev_info(&pdev->dev, "Init done\n");
	return 0;
}

