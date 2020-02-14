#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct st_irq_syscfg {unsigned int syscfg; int /*<<< orphan*/  regmap; int /*<<< orphan*/  config; } ;
struct TYPE_6__ {struct device_node* of_node; } ;
struct platform_device {TYPE_1__ dev; } ;
struct of_device_id {scalar_t__ data; } ;
struct device_node {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ST_A9_EXTIRQ_INV_SEL (int) ; 
 int /*<<< orphan*/  ST_A9_FIQ_N_SEL (int,int) ; 
 int /*<<< orphan*/  ST_A9_IRQ_EN_CTI_0 ; 
 int /*<<< orphan*/  ST_A9_IRQ_EN_CTI_1 ; 
 int /*<<< orphan*/  ST_A9_IRQ_EN_EXT_0 ; 
 int /*<<< orphan*/  ST_A9_IRQ_EN_EXT_1 ; 
 int /*<<< orphan*/  ST_A9_IRQ_EN_EXT_2 ; 
 int /*<<< orphan*/  ST_A9_IRQ_EN_PL310_L2 ; 
 int /*<<< orphan*/  ST_A9_IRQ_EN_PMU_0 ; 
 int /*<<< orphan*/  ST_A9_IRQ_EN_PMU_1 ; 
 int /*<<< orphan*/  ST_A9_IRQ_MASK ; 
 int ST_A9_IRQ_MAX_CHANS ; 
 int /*<<< orphan*/  ST_A9_IRQ_N_SEL (int,int) ; 
#define  ST_IRQ_SYSCFG_CTI_0 136 
#define  ST_IRQ_SYSCFG_CTI_1 135 
#define  ST_IRQ_SYSCFG_DISABLED 134 
#define  ST_IRQ_SYSCFG_EXT_0 133 
#define  ST_IRQ_SYSCFG_EXT_1 132 
#define  ST_IRQ_SYSCFG_EXT_2 131 
#define  ST_IRQ_SYSCFG_PMU_0 130 
#define  ST_IRQ_SYSCFG_PMU_1 129 
#define  ST_IRQ_SYSCFG_pl310_L2 128 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*,...) ; 
 struct st_irq_syscfg* dev_get_drvdata (TYPE_1__*) ; 
 int /*<<< orphan*/  dev_set_drvdata (TYPE_1__*,struct st_irq_syscfg*) ; 
 struct st_irq_syscfg* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 struct of_device_id* of_match_device (int /*<<< orphan*/ ,TYPE_1__*) ; 
 int of_property_count_u32_elems (struct device_node*,char*) ; 
 int /*<<< orphan*/  of_property_read_u32 (struct device_node*,char*,int*) ; 
 int /*<<< orphan*/  of_property_read_u32_index (struct device_node*,char*,int,int*) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,unsigned int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  st_irq_syscfg_match ; 
 int /*<<< orphan*/  syscon_regmap_lookup_by_phandle (struct device_node*,char*) ; 

__attribute__((used)) static int st_irq_xlate(struct platform_device *pdev,
			int device, int channel, bool irq)
{
	struct st_irq_syscfg *ddata = dev_get_drvdata(&pdev->dev);

	/* Set the device enable bit. */
	switch (device) {
	case ST_IRQ_SYSCFG_EXT_0:
		ddata->config |= ST_A9_IRQ_EN_EXT_0;
		break;
	case ST_IRQ_SYSCFG_EXT_1:
		ddata->config |= ST_A9_IRQ_EN_EXT_1;
		break;
	case ST_IRQ_SYSCFG_EXT_2:
		ddata->config |= ST_A9_IRQ_EN_EXT_2;
		break;
	case ST_IRQ_SYSCFG_CTI_0:
		ddata->config |= ST_A9_IRQ_EN_CTI_0;
		break;
	case ST_IRQ_SYSCFG_CTI_1:
		ddata->config |= ST_A9_IRQ_EN_CTI_1;
		break;
	case ST_IRQ_SYSCFG_PMU_0:
		ddata->config |= ST_A9_IRQ_EN_PMU_0;
		break;
	case ST_IRQ_SYSCFG_PMU_1:
		ddata->config |= ST_A9_IRQ_EN_PMU_1;
		break;
	case ST_IRQ_SYSCFG_pl310_L2:
		ddata->config |= ST_A9_IRQ_EN_PL310_L2;
		break;
	case ST_IRQ_SYSCFG_DISABLED:
		return 0;
	default:
		dev_err(&pdev->dev, "Unrecognised device %d\n", device);
		return -EINVAL;
	}

	/* Select IRQ/FIQ channel for device. */
	ddata->config |= irq ?
		ST_A9_IRQ_N_SEL(device, channel) :
		ST_A9_FIQ_N_SEL(device, channel);

	return 0;
}

__attribute__((used)) static int st_irq_syscfg_enable(struct platform_device *pdev)
{
	struct device_node *np = pdev->dev.of_node;
	struct st_irq_syscfg *ddata = dev_get_drvdata(&pdev->dev);
	int channels, ret, i;
	u32 device, invert;

	channels = of_property_count_u32_elems(np, "st,irq-device");
	if (channels != ST_A9_IRQ_MAX_CHANS) {
		dev_err(&pdev->dev, "st,enable-irq-device must have 2 elems\n");
		return -EINVAL;
	}

	channels = of_property_count_u32_elems(np, "st,fiq-device");
	if (channels != ST_A9_IRQ_MAX_CHANS) {
		dev_err(&pdev->dev, "st,enable-fiq-device must have 2 elems\n");
		return -EINVAL;
	}

	for (i = 0; i < ST_A9_IRQ_MAX_CHANS; i++) {
		of_property_read_u32_index(np, "st,irq-device", i, &device);

		ret = st_irq_xlate(pdev, device, i, true);
		if (ret)
			return ret;

		of_property_read_u32_index(np, "st,fiq-device", i, &device);

		ret = st_irq_xlate(pdev, device, i, false);
		if (ret)
			return ret;
	}

	/* External IRQs may be inverted. */
	of_property_read_u32(np, "st,invert-ext", &invert);
	ddata->config |= ST_A9_EXTIRQ_INV_SEL(invert);

	return regmap_update_bits(ddata->regmap, ddata->syscfg,
				  ST_A9_IRQ_MASK, ddata->config);
}

__attribute__((used)) static int st_irq_syscfg_probe(struct platform_device *pdev)
{
	struct device_node *np = pdev->dev.of_node;
	const struct of_device_id *match;
	struct st_irq_syscfg *ddata;

	ddata = devm_kzalloc(&pdev->dev, sizeof(*ddata), GFP_KERNEL);
	if (!ddata)
		return -ENOMEM;

	match = of_match_device(st_irq_syscfg_match, &pdev->dev);
	if (!match)
		return -ENODEV;

	ddata->syscfg = (unsigned int)match->data;

	ddata->regmap = syscon_regmap_lookup_by_phandle(np, "st,syscfg");
	if (IS_ERR(ddata->regmap)) {
		dev_err(&pdev->dev, "syscfg phandle missing\n");
		return PTR_ERR(ddata->regmap);
	}

	dev_set_drvdata(&pdev->dev, ddata);

	return st_irq_syscfg_enable(pdev);
}

