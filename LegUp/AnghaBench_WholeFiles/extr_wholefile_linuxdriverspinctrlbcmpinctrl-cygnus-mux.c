#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct seq_file {int dummy; } ;
struct resource {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct pinctrl_pin_desc {char const* name; int /*<<< orphan*/ * drv_data; int /*<<< orphan*/  number; } ;
struct pinctrl_gpio_range {int dummy; } ;
struct pinctrl_dev {int /*<<< orphan*/  dev; TYPE_2__* desc; int /*<<< orphan*/  pin_desc_tree; } ;
struct pin_desc {int dummy; } ;
struct cygnus_pinctrl {int num_groups; int num_functions; scalar_t__ base0; scalar_t__ base1; scalar_t__ pctl; struct cygnus_pin_group* functions; struct cygnus_pin_group* groups; int /*<<< orphan*/  lock; int /*<<< orphan*/ * dev; struct cygnus_mux_log* mux_log; } ;
struct cygnus_mux {scalar_t__ offset; scalar_t__ shift; scalar_t__ alt; } ;
struct cygnus_pin_group {char const* name; unsigned int* pins; unsigned int num_pins; char** groups; unsigned int num_groups; int /*<<< orphan*/  gpio_mux; int /*<<< orphan*/  pin; struct cygnus_mux mux; } ;
struct cygnus_pin_function {char const* name; unsigned int* pins; unsigned int num_pins; char** groups; unsigned int num_groups; int /*<<< orphan*/  gpio_mux; int /*<<< orphan*/  pin; struct cygnus_mux mux; } ;
struct TYPE_8__ {scalar_t__ offset; scalar_t__ shift; scalar_t__ alt; } ;
struct cygnus_mux_log {int is_configured; TYPE_3__ mux; } ;
struct cygnus_gpio_mux {scalar_t__ offset; int shift; int /*<<< orphan*/  is_supported; } ;
struct TYPE_9__ {unsigned int npins; struct pinctrl_pin_desc* pins; } ;
struct TYPE_7__ {TYPE_1__* pins; } ;
struct TYPE_6__ {struct cygnus_gpio_mux* drv_data; } ;

/* Variables and functions */
 void* ARRAY_SIZE (struct cygnus_pin_group*) ; 
 int CYGNUS_NUM_IOMUX ; 
 unsigned int CYGNUS_NUM_IOMUX_REGS ; 
 unsigned int CYGNUS_NUM_MUX_PER_REG ; 
 int EINVAL ; 
 int ENOMEM ; 
 int ENOTSUPP ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int PTR_ERR (scalar_t__) ; 
 struct cygnus_pin_group* cygnus_pin_functions ; 
 struct cygnus_pin_group* cygnus_pin_groups ; 
 TYPE_4__ cygnus_pinctrl_desc ; 
 struct cygnus_pin_group* cygnus_pins ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,unsigned int,scalar_t__,int,...) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  dev_name (int /*<<< orphan*/ ) ; 
 void* devm_ioremap_resource (int /*<<< orphan*/ *,struct resource*) ; 
 void* devm_kcalloc (int /*<<< orphan*/ *,unsigned int,int,int /*<<< orphan*/ ) ; 
 struct cygnus_pinctrl* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 scalar_t__ devm_pinctrl_register (int /*<<< orphan*/ *,TYPE_4__*,struct cygnus_pinctrl*) ; 
 struct cygnus_pinctrl* pinctrl_dev_get_drvdata (struct pinctrl_dev*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct cygnus_pinctrl*) ; 
 struct pin_desc* radix_tree_lookup (int /*<<< orphan*/ *,unsigned int) ; 
 int readl (scalar_t__) ; 
 int /*<<< orphan*/  seq_printf (struct seq_file*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static inline struct pin_desc *pin_desc_get(struct pinctrl_dev *pctldev,
					    unsigned int pin)
{
	return radix_tree_lookup(&pctldev->pin_desc_tree, pin);
}

__attribute__((used)) static int cygnus_get_groups_count(struct pinctrl_dev *pctrl_dev)
{
	struct cygnus_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctrl_dev);

	return pinctrl->num_groups;
}

__attribute__((used)) static const char *cygnus_get_group_name(struct pinctrl_dev *pctrl_dev,
					 unsigned selector)
{
	struct cygnus_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctrl_dev);

	return pinctrl->groups[selector].name;
}

__attribute__((used)) static int cygnus_get_group_pins(struct pinctrl_dev *pctrl_dev,
				 unsigned selector, const unsigned **pins,
				 unsigned *num_pins)
{
	struct cygnus_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctrl_dev);

	*pins = pinctrl->groups[selector].pins;
	*num_pins = pinctrl->groups[selector].num_pins;

	return 0;
}

__attribute__((used)) static void cygnus_pin_dbg_show(struct pinctrl_dev *pctrl_dev,
				struct seq_file *s, unsigned offset)
{
	seq_printf(s, " %s", dev_name(pctrl_dev->dev));
}

__attribute__((used)) static int cygnus_get_functions_count(struct pinctrl_dev *pctrl_dev)
{
	struct cygnus_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctrl_dev);

	return pinctrl->num_functions;
}

__attribute__((used)) static const char *cygnus_get_function_name(struct pinctrl_dev *pctrl_dev,
					    unsigned selector)
{
	struct cygnus_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctrl_dev);

	return pinctrl->functions[selector].name;
}

__attribute__((used)) static int cygnus_get_function_groups(struct pinctrl_dev *pctrl_dev,
				      unsigned selector,
				      const char * const **groups,
				      unsigned * const num_groups)
{
	struct cygnus_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctrl_dev);

	*groups = pinctrl->functions[selector].groups;
	*num_groups = pinctrl->functions[selector].num_groups;

	return 0;
}

__attribute__((used)) static int cygnus_pinmux_set(struct cygnus_pinctrl *pinctrl,
			     const struct cygnus_pin_function *func,
			     const struct cygnus_pin_group *grp,
			     struct cygnus_mux_log *mux_log)
{
	const struct cygnus_mux *mux = &grp->mux;
	int i;
	u32 val, mask = 0x7;
	unsigned long flags;

	for (i = 0; i < CYGNUS_NUM_IOMUX; i++) {
		if (mux->offset != mux_log[i].mux.offset ||
		    mux->shift != mux_log[i].mux.shift)
			continue;

		/* match found if we reach here */

		/* if this is a new configuration, just do it! */
		if (!mux_log[i].is_configured)
			break;

		/*
		 * IOMUX has been configured previously and one is trying to
		 * configure it to a different function
		 */
		if (mux_log[i].mux.alt != mux->alt) {
			dev_err(pinctrl->dev,
				"double configuration error detected!\n");
			dev_err(pinctrl->dev, "func:%s grp:%s\n",
				func->name, grp->name);
			return -EINVAL;
		} else {
			/*
			 * One tries to configure it to the same function.
			 * Just quit and don't bother
			 */
			return 0;
		}
	}

	mux_log[i].mux.alt = mux->alt;
	mux_log[i].is_configured = true;

	spin_lock_irqsave(&pinctrl->lock, flags);

	val = readl(pinctrl->base0 + grp->mux.offset);
	val &= ~(mask << grp->mux.shift);
	val |= grp->mux.alt << grp->mux.shift;
	writel(val, pinctrl->base0 + grp->mux.offset);

	spin_unlock_irqrestore(&pinctrl->lock, flags);

	return 0;
}

__attribute__((used)) static int cygnus_pinmux_set_mux(struct pinctrl_dev *pctrl_dev,
				 unsigned func_select, unsigned grp_select)
{
	struct cygnus_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctrl_dev);
	const struct cygnus_pin_function *func =
		&pinctrl->functions[func_select];
	const struct cygnus_pin_group *grp = &pinctrl->groups[grp_select];

	dev_dbg(pctrl_dev->dev, "func:%u name:%s grp:%u name:%s\n",
		func_select, func->name, grp_select, grp->name);

	dev_dbg(pctrl_dev->dev, "offset:0x%08x shift:%u alt:%u\n",
		grp->mux.offset, grp->mux.shift, grp->mux.alt);

	return cygnus_pinmux_set(pinctrl, func, grp, pinctrl->mux_log);
}

__attribute__((used)) static int cygnus_gpio_request_enable(struct pinctrl_dev *pctrl_dev,
				      struct pinctrl_gpio_range *range,
				      unsigned pin)
{
	struct cygnus_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctrl_dev);
	const struct cygnus_gpio_mux *mux = pctrl_dev->desc->pins[pin].drv_data;
	u32 val;
	unsigned long flags;

	/* not all pins support GPIO pinmux override */
	if (!mux->is_supported)
		return -ENOTSUPP;

	spin_lock_irqsave(&pinctrl->lock, flags);

	val = readl(pinctrl->base1 + mux->offset);
	val |= 0x3 << mux->shift;
	writel(val, pinctrl->base1 + mux->offset);

	spin_unlock_irqrestore(&pinctrl->lock, flags);

	dev_dbg(pctrl_dev->dev,
		"gpio request enable pin=%u offset=0x%x shift=%u\n",
		pin, mux->offset, mux->shift);

	return 0;
}

__attribute__((used)) static void cygnus_gpio_disable_free(struct pinctrl_dev *pctrl_dev,
				     struct pinctrl_gpio_range *range,
				     unsigned pin)
{
	struct cygnus_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctrl_dev);
	struct cygnus_gpio_mux *mux = pctrl_dev->desc->pins[pin].drv_data;
	u32 val;
	unsigned long flags;

	if (!mux->is_supported)
		return;

	spin_lock_irqsave(&pinctrl->lock, flags);

	val = readl(pinctrl->base1 + mux->offset);
	val &= ~(0x3 << mux->shift);
	writel(val, pinctrl->base1 + mux->offset);

	spin_unlock_irqrestore(&pinctrl->lock, flags);

	dev_err(pctrl_dev->dev,
		"gpio disable free pin=%u offset=0x%x shift=%u\n",
		pin, mux->offset, mux->shift);
}

__attribute__((used)) static int cygnus_mux_log_init(struct cygnus_pinctrl *pinctrl)
{
	struct cygnus_mux_log *log;
	unsigned int i, j;

	pinctrl->mux_log = devm_kcalloc(pinctrl->dev, CYGNUS_NUM_IOMUX,
					sizeof(struct cygnus_mux_log),
					GFP_KERNEL);
	if (!pinctrl->mux_log)
		return -ENOMEM;

	log = pinctrl->mux_log;
	for (i = 0; i < CYGNUS_NUM_IOMUX_REGS; i++) {
		for (j = 0; j < CYGNUS_NUM_MUX_PER_REG; j++) {
			log = &pinctrl->mux_log[i * CYGNUS_NUM_MUX_PER_REG
				+ j];
			log->mux.offset = i * 4;
			log->mux.shift = j * 4;
			log->mux.alt = 0;
			log->is_configured = false;
		}
	}

	return 0;
}

__attribute__((used)) static int cygnus_pinmux_probe(struct platform_device *pdev)
{
	struct cygnus_pinctrl *pinctrl;
	struct resource *res;
	int i, ret;
	struct pinctrl_pin_desc *pins;
	unsigned num_pins = ARRAY_SIZE(cygnus_pins);

	pinctrl = devm_kzalloc(&pdev->dev, sizeof(*pinctrl), GFP_KERNEL);
	if (!pinctrl)
		return -ENOMEM;

	pinctrl->dev = &pdev->dev;
	platform_set_drvdata(pdev, pinctrl);
	spin_lock_init(&pinctrl->lock);

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	pinctrl->base0 = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(pinctrl->base0)) {
		dev_err(&pdev->dev, "unable to map I/O space\n");
		return PTR_ERR(pinctrl->base0);
	}

	res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
	pinctrl->base1 = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(pinctrl->base1)) {
		dev_err(&pdev->dev, "unable to map I/O space\n");
		return PTR_ERR(pinctrl->base1);
	}

	ret = cygnus_mux_log_init(pinctrl);
	if (ret) {
		dev_err(&pdev->dev, "unable to initialize IOMUX log\n");
		return ret;
	}

	pins = devm_kcalloc(&pdev->dev, num_pins, sizeof(*pins), GFP_KERNEL);
	if (!pins)
		return -ENOMEM;

	for (i = 0; i < num_pins; i++) {
		pins[i].number = cygnus_pins[i].pin;
		pins[i].name = cygnus_pins[i].name;
		pins[i].drv_data = &cygnus_pins[i].gpio_mux;
	}

	pinctrl->groups = cygnus_pin_groups;
	pinctrl->num_groups = ARRAY_SIZE(cygnus_pin_groups);
	pinctrl->functions = cygnus_pin_functions;
	pinctrl->num_functions = ARRAY_SIZE(cygnus_pin_functions);
	cygnus_pinctrl_desc.pins = pins;
	cygnus_pinctrl_desc.npins = num_pins;

	pinctrl->pctl = devm_pinctrl_register(&pdev->dev, &cygnus_pinctrl_desc,
			pinctrl);
	if (IS_ERR(pinctrl->pctl)) {
		dev_err(&pdev->dev, "unable to register Cygnus IOMUX pinctrl\n");
		return PTR_ERR(pinctrl->pctl);
	}

	return 0;
}

