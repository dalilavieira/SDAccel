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
struct device {int /*<<< orphan*/  of_node; } ;
struct platform_device {struct device dev; } ;
struct gic_clk_data {unsigned int num_clocks; int /*<<< orphan*/ * clocks; } ;
struct gic_chip_data {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct gic_chip_data* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*) ; 
 int /*<<< orphan*/  gic_cpu_restore (struct gic_chip_data*) ; 
 int /*<<< orphan*/  gic_cpu_save (struct gic_chip_data*) ; 
 int /*<<< orphan*/  gic_dist_restore (struct gic_chip_data*) ; 
 int /*<<< orphan*/  gic_dist_save (struct gic_chip_data*) ; 
 int gic_of_init_child (struct device*,struct gic_chip_data**,int) ; 
 int /*<<< orphan*/  irq_dispose_mapping (int) ; 
 int irq_of_parse_and_map (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct gic_clk_data* of_device_get_match_data (struct device*) ; 
 int of_pm_clk_add_clk (struct device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct gic_chip_data*) ; 
 int pm_clk_create (struct device*) ; 
 int /*<<< orphan*/  pm_clk_destroy (struct device*) ; 
 int pm_clk_resume (struct device*) ; 
 int pm_clk_suspend (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_disable (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_enable (struct device*) ; 
 int pm_runtime_get_sync (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_put (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_put_sync (struct device*) ; 

__attribute__((used)) static int gic_runtime_resume(struct device *dev)
{
	struct gic_chip_data *gic = dev_get_drvdata(dev);
	int ret;

	ret = pm_clk_resume(dev);
	if (ret)
		return ret;

	/*
	 * On the very first resume, the pointer to the driver data
	 * will be NULL and this is intentional, because we do not
	 * want to restore the GIC on the very first resume. So if
	 * the pointer is not valid just return.
	 */
	if (!gic)
		return 0;

	gic_dist_restore(gic);
	gic_cpu_restore(gic);

	return 0;
}

__attribute__((used)) static int gic_runtime_suspend(struct device *dev)
{
	struct gic_chip_data *gic = dev_get_drvdata(dev);

	gic_dist_save(gic);
	gic_cpu_save(gic);

	return pm_clk_suspend(dev);
}

__attribute__((used)) static int gic_get_clocks(struct device *dev, const struct gic_clk_data *data)
{
	unsigned int i;
	int ret;

	if (!dev || !data)
		return -EINVAL;

	ret = pm_clk_create(dev);
	if (ret)
		return ret;

	for (i = 0; i < data->num_clocks; i++) {
		ret = of_pm_clk_add_clk(dev, data->clocks[i]);
		if (ret) {
			dev_err(dev, "failed to add clock %s\n",
				data->clocks[i]);
			pm_clk_destroy(dev);
			return ret;
		}
	}

	return 0;
}

__attribute__((used)) static int gic_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	const struct gic_clk_data *data;
	struct gic_chip_data *gic;
	int ret, irq;

	data = of_device_get_match_data(&pdev->dev);
	if (!data) {
		dev_err(&pdev->dev, "no device match found\n");
		return -ENODEV;
	}

	irq = irq_of_parse_and_map(dev->of_node, 0);
	if (!irq) {
		dev_err(dev, "no parent interrupt found!\n");
		return -EINVAL;
	}

	ret = gic_get_clocks(dev, data);
	if (ret)
		goto irq_dispose;

	pm_runtime_enable(dev);

	ret = pm_runtime_get_sync(dev);
	if (ret < 0)
		goto rpm_disable;

	ret = gic_of_init_child(dev, &gic, irq);
	if (ret)
		goto rpm_put;

	platform_set_drvdata(pdev, gic);

	pm_runtime_put(dev);

	dev_info(dev, "GIC IRQ controller registered\n");

	return 0;

rpm_put:
	pm_runtime_put_sync(dev);
rpm_disable:
	pm_runtime_disable(dev);
	pm_clk_destroy(dev);
irq_dispose:
	irq_dispose_mapping(irq);

	return ret;
}

