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
 int /*<<< orphan*/  ipq8074_pinctrl ; 
 int msm_pinctrl_probe (struct platform_device*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int ipq8074_pinctrl_probe(struct platform_device *pdev)
{
	return msm_pinctrl_probe(pdev, &ipq8074_pinctrl);
}

