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
 int /*<<< orphan*/  dnv_soc_data ; 
 int intel_pinctrl_probe (struct platform_device*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int dnv_pinctrl_probe(struct platform_device *pdev)
{
	return intel_pinctrl_probe(pdev, &dnv_soc_data);
}

