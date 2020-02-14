#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct platform_device {int dummy; } ;
struct pinctrl_dev {int /*<<< orphan*/  pin_desc_tree; } ;
struct pin_desc {int dummy; } ;
struct TYPE_3__ {int number; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_1__*) ; 
 int /*<<< orphan*/  aspeed_g4_pinctrl_data ; 
 int /*<<< orphan*/  aspeed_g4_pinctrl_desc ; 
 int /*<<< orphan*/  aspeed_g4_pinctrl_driver ; 
 TYPE_1__* aspeed_g4_pins ; 
 int aspeed_pinctrl_probe (struct platform_device*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int platform_driver_register (int /*<<< orphan*/ *) ; 
 struct pin_desc* radix_tree_lookup (int /*<<< orphan*/ *,unsigned int) ; 

__attribute__((used)) static inline struct pin_desc *pin_desc_get(struct pinctrl_dev *pctldev,
					    unsigned int pin)
{
	return radix_tree_lookup(&pctldev->pin_desc_tree, pin);
}

__attribute__((used)) static int aspeed_g4_pinctrl_probe(struct platform_device *pdev)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(aspeed_g4_pins); i++)
		aspeed_g4_pins[i].number = i;

	return aspeed_pinctrl_probe(pdev, &aspeed_g4_pinctrl_desc,
			&aspeed_g4_pinctrl_data);
}

__attribute__((used)) static int aspeed_g4_pinctrl_init(void)
{
	return platform_driver_register(&aspeed_g4_pinctrl_driver);
}

