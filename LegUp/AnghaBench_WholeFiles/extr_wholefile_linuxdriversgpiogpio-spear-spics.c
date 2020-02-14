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
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned int u32 ;
struct TYPE_9__ {int base; int (* request ) (struct gpio_chip*,unsigned int) ;void (* free ) (struct gpio_chip*,unsigned int) ;int (* direction_input ) (struct gpio_chip*,unsigned int) ;int (* direction_output ) (struct gpio_chip*,unsigned int,int) ;int (* get ) (struct gpio_chip*,unsigned int) ;void (* set ) (struct gpio_chip*,unsigned int,int) ;int /*<<< orphan*/  owner; TYPE_1__* parent; int /*<<< orphan*/  label; int /*<<< orphan*/  ngpio; } ;
struct spear_spics {unsigned int base; unsigned int perip_cfg; unsigned int last_off; unsigned int cs_enable_mask; unsigned int cs_enable_shift; int cs_value_bit; int sw_enable_bit; TYPE_4__ chip; int /*<<< orphan*/  use_count; } ;
struct resource {int dummy; } ;
struct TYPE_8__ {struct device_node* of_node; } ;
struct platform_device {TYPE_1__ dev; } ;
struct gpio_chip {int dummy; } ;
struct device_node {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int ENXIO ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (unsigned int) ; 
 int /*<<< orphan*/  NUM_OF_GPIO ; 
 int PTR_ERR (unsigned int) ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*) ; 
 int /*<<< orphan*/  dev_info (TYPE_1__*,char*) ; 
 int /*<<< orphan*/  dev_name (TYPE_1__*) ; 
 int devm_gpiochip_add_data (TYPE_1__*,TYPE_4__*,struct spear_spics*) ; 
 unsigned int devm_ioremap_resource (TYPE_1__*,struct resource*) ; 
 struct spear_spics* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 struct spear_spics* gpiochip_get_data (struct gpio_chip*) ; 
 scalar_t__ of_property_read_u32 (struct device_node*,char*,unsigned int*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct spear_spics*) ; 
 unsigned int readl_relaxed (unsigned int) ; 
 int /*<<< orphan*/  writel_relaxed (unsigned int,unsigned int) ; 

__attribute__((used)) static int spics_get_value(struct gpio_chip *chip, unsigned offset)
{
	return -ENXIO;
}

__attribute__((used)) static void spics_set_value(struct gpio_chip *chip, unsigned offset, int value)
{
	struct spear_spics *spics = gpiochip_get_data(chip);
	u32 tmp;

	/* select chip select from register */
	tmp = readl_relaxed(spics->base + spics->perip_cfg);
	if (spics->last_off != offset) {
		spics->last_off = offset;
		tmp &= ~(spics->cs_enable_mask << spics->cs_enable_shift);
		tmp |= offset << spics->cs_enable_shift;
	}

	/* toggle chip select line */
	tmp &= ~(0x1 << spics->cs_value_bit);
	tmp |= value << spics->cs_value_bit;
	writel_relaxed(tmp, spics->base + spics->perip_cfg);
}

__attribute__((used)) static int spics_direction_input(struct gpio_chip *chip, unsigned offset)
{
	return -ENXIO;
}

__attribute__((used)) static int spics_direction_output(struct gpio_chip *chip, unsigned offset,
		int value)
{
	spics_set_value(chip, offset, value);
	return 0;
}

__attribute__((used)) static int spics_request(struct gpio_chip *chip, unsigned offset)
{
	struct spear_spics *spics = gpiochip_get_data(chip);
	u32 tmp;

	if (!spics->use_count++) {
		tmp = readl_relaxed(spics->base + spics->perip_cfg);
		tmp |= 0x1 << spics->sw_enable_bit;
		tmp |= 0x1 << spics->cs_value_bit;
		writel_relaxed(tmp, spics->base + spics->perip_cfg);
	}

	return 0;
}

__attribute__((used)) static void spics_free(struct gpio_chip *chip, unsigned offset)
{
	struct spear_spics *spics = gpiochip_get_data(chip);
	u32 tmp;

	if (!--spics->use_count) {
		tmp = readl_relaxed(spics->base + spics->perip_cfg);
		tmp &= ~(0x1 << spics->sw_enable_bit);
		writel_relaxed(tmp, spics->base + spics->perip_cfg);
	}
}

__attribute__((used)) static int spics_gpio_probe(struct platform_device *pdev)
{
	struct device_node *np = pdev->dev.of_node;
	struct spear_spics *spics;
	struct resource *res;
	int ret;

	spics = devm_kzalloc(&pdev->dev, sizeof(*spics), GFP_KERNEL);
	if (!spics)
		return -ENOMEM;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	spics->base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(spics->base))
		return PTR_ERR(spics->base);

	if (of_property_read_u32(np, "st-spics,peripcfg-reg",
				&spics->perip_cfg))
		goto err_dt_data;
	if (of_property_read_u32(np, "st-spics,sw-enable-bit",
				&spics->sw_enable_bit))
		goto err_dt_data;
	if (of_property_read_u32(np, "st-spics,cs-value-bit",
				&spics->cs_value_bit))
		goto err_dt_data;
	if (of_property_read_u32(np, "st-spics,cs-enable-mask",
				&spics->cs_enable_mask))
		goto err_dt_data;
	if (of_property_read_u32(np, "st-spics,cs-enable-shift",
				&spics->cs_enable_shift))
		goto err_dt_data;

	platform_set_drvdata(pdev, spics);

	spics->chip.ngpio = NUM_OF_GPIO;
	spics->chip.base = -1;
	spics->chip.request = spics_request;
	spics->chip.free = spics_free;
	spics->chip.direction_input = spics_direction_input;
	spics->chip.direction_output = spics_direction_output;
	spics->chip.get = spics_get_value;
	spics->chip.set = spics_set_value;
	spics->chip.label = dev_name(&pdev->dev);
	spics->chip.parent = &pdev->dev;
	spics->chip.owner = THIS_MODULE;
	spics->last_off = -1;

	ret = devm_gpiochip_add_data(&pdev->dev, &spics->chip, spics);
	if (ret) {
		dev_err(&pdev->dev, "unable to add gpio chip\n");
		return ret;
	}

	dev_info(&pdev->dev, "spear spics registered\n");
	return 0;

err_dt_data:
	dev_err(&pdev->dev, "DT probe failed\n");
	return -EINVAL;
}

