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
struct resource {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct cpuidle_driver {int dummy; } ;
struct cpuidle_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_do_idle () ; 
 int cpuidle_register (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cpuidle_unregister (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ddr_operation_base ; 
 int /*<<< orphan*/  devm_ioremap_resource (int /*<<< orphan*/ *,struct resource*) ; 
 int /*<<< orphan*/  kirkwood_idle_driver ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  writel (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int kirkwood_enter_idle(struct cpuidle_device *dev,
			       struct cpuidle_driver *drv,
			       int index)
{
	writel(0x7, ddr_operation_base);
	cpu_do_idle();

	return index;
}

__attribute__((used)) static int kirkwood_cpuidle_probe(struct platform_device *pdev)
{
	struct resource *res;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	ddr_operation_base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(ddr_operation_base))
		return PTR_ERR(ddr_operation_base);

	return cpuidle_register(&kirkwood_idle_driver, NULL);
}

__attribute__((used)) static int kirkwood_cpuidle_remove(struct platform_device *pdev)
{
	cpuidle_unregister(&kirkwood_idle_driver);
	return 0;
}

