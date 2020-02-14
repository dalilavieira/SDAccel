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
struct platform_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int platform_driver_register (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  platform_driver_unregister (int /*<<< orphan*/ *) ; 
 int sprd_pinctrl_core_probe (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sprd_pinctrl_driver ; 
 int /*<<< orphan*/  sprd_sc9860_pins_info ; 

__attribute__((used)) static int sprd_pinctrl_probe(struct platform_device *pdev)
{
	return sprd_pinctrl_core_probe(pdev, sprd_sc9860_pins_info,
				       ARRAY_SIZE(sprd_sc9860_pins_info));
}

__attribute__((used)) static int sprd_pinctrl_init(void)
{
	return platform_driver_register(&sprd_pinctrl_driver);
}

__attribute__((used)) static void sprd_pinctrl_exit(void)
{
	platform_driver_unregister(&sprd_pinctrl_driver);
}

