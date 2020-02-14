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
 int imx1_pinctrl_core_probe (struct platform_device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  imx27_pinctrl_info ; 

__attribute__((used)) static int imx27_pinctrl_probe(struct platform_device *pdev)
{
	return imx1_pinctrl_core_probe(pdev, &imx27_pinctrl_info);
}

