#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct twl6040 {int dummy; } ;
struct TYPE_8__ {struct device* parent; } ;
struct platform_device {TYPE_3__ dev; } ;
struct gpio_chip {TYPE_1__* parent; } ;
struct device {int dummy; } ;
struct TYPE_7__ {int base; int ngpio; TYPE_3__* parent; } ;
struct TYPE_6__ {struct device* parent; } ;

/* Variables and functions */
 int /*<<< orphan*/  TWL6040_REG_GPOCTL ; 
 scalar_t__ TWL6041_REV_ES2_0 ; 
 int /*<<< orphan*/  dev_err (TYPE_3__*,char*,int) ; 
 struct twl6040* dev_get_drvdata (struct device*) ; 
 int devm_gpiochip_add_data (TYPE_3__*,TYPE_2__*,int /*<<< orphan*/ *) ; 
 scalar_t__ twl6040_get_revid (struct twl6040*) ; 
 int twl6040_reg_read (struct twl6040*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  twl6040_reg_write (struct twl6040*,int /*<<< orphan*/ ,int) ; 
 TYPE_2__ twl6040gpo_chip ; 

__attribute__((used)) static int twl6040gpo_get(struct gpio_chip *chip, unsigned offset)
{
	struct twl6040 *twl6040 = dev_get_drvdata(chip->parent->parent);
	int ret = 0;

	ret = twl6040_reg_read(twl6040, TWL6040_REG_GPOCTL);
	if (ret < 0)
		return ret;

	return (ret >> offset) & 1;
}

__attribute__((used)) static int twl6040gpo_direction_out(struct gpio_chip *chip, unsigned offset,
				    int value)
{
	/* This only drives GPOs, and can't change direction */
	return 0;
}

__attribute__((used)) static void twl6040gpo_set(struct gpio_chip *chip, unsigned offset, int value)
{
	struct twl6040 *twl6040 = dev_get_drvdata(chip->parent->parent);
	int ret;
	u8 gpoctl;

	ret = twl6040_reg_read(twl6040, TWL6040_REG_GPOCTL);
	if (ret < 0)
		return;

	if (value)
		gpoctl = ret | (1 << offset);
	else
		gpoctl = ret & ~(1 << offset);

	twl6040_reg_write(twl6040, TWL6040_REG_GPOCTL, gpoctl);
}

__attribute__((used)) static int gpo_twl6040_probe(struct platform_device *pdev)
{
	struct device *twl6040_core_dev = pdev->dev.parent;
	struct twl6040 *twl6040 = dev_get_drvdata(twl6040_core_dev);
	int ret;

	twl6040gpo_chip.base = -1;

	if (twl6040_get_revid(twl6040) < TWL6041_REV_ES2_0)
		twl6040gpo_chip.ngpio = 3; /* twl6040 have 3 GPO */
	else
		twl6040gpo_chip.ngpio = 1; /* twl6041 have 1 GPO */

	twl6040gpo_chip.parent = &pdev->dev;
#ifdef CONFIG_OF_GPIO
	twl6040gpo_chip.of_node = twl6040_core_dev->of_node;
#endif

	ret = devm_gpiochip_add_data(&pdev->dev, &twl6040gpo_chip, NULL);
	if (ret < 0) {
		dev_err(&pdev->dev, "could not register gpiochip, %d\n", ret);
		twl6040gpo_chip.ngpio = 0;
	}

	return ret;
}

