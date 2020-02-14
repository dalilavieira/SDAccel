#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct resource {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct device_node {int dummy; } ;
struct cpufreq_policy {int dummy; } ;
struct TYPE_5__ {unsigned int driver_data; int frequency; } ;
struct TYPE_4__ {void* cpu_clk; void* ddr_clk; void* powersave_clk; int /*<<< orphan*/ * dev; void* base; } ;

/* Variables and functions */
 unsigned long CPU_SW_INT_BLK ; 
 int ENODEV ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (void*) ; 
 int PTR_ERR (void*) ; 
#define  STATE_CPU_FREQ 129 
#define  STATE_DDR_FREQ 128 
 int /*<<< orphan*/  clk_disable_unprepare (void*) ; 
 int clk_get_rate (void*) ; 
 int clk_prepare_enable (void*) ; 
 int /*<<< orphan*/  clk_set_parent (void*,void*) ; 
 int /*<<< orphan*/  cpu_do_idle () ; 
 int cpufreq_generic_init (struct cpufreq_policy*,TYPE_2__*,int) ; 
 int cpufreq_register_driver (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cpufreq_unregister_driver (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 void* devm_ioremap_resource (int /*<<< orphan*/ *,struct resource*) ; 
 int /*<<< orphan*/  kirkwood_cpufreq_driver ; 
 TYPE_2__* kirkwood_freq_table ; 
 int /*<<< orphan*/  local_irq_disable () ; 
 int /*<<< orphan*/  local_irq_enable () ; 
 void* of_clk_get_by_name (struct device_node*,char*) ; 
 struct device_node* of_cpu_device_node_get (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_1__ priv ; 
 unsigned long readl_relaxed (void*) ; 
 int /*<<< orphan*/  writel_relaxed (unsigned long,void*) ; 

__attribute__((used)) static unsigned int kirkwood_cpufreq_get_cpu_frequency(unsigned int cpu)
{
	return clk_get_rate(priv.powersave_clk) / 1000;
}

__attribute__((used)) static int kirkwood_cpufreq_target(struct cpufreq_policy *policy,
			    unsigned int index)
{
	unsigned int state = kirkwood_freq_table[index].driver_data;
	unsigned long reg;

	local_irq_disable();

	/* Disable interrupts to the CPU */
	reg = readl_relaxed(priv.base);
	reg |= CPU_SW_INT_BLK;
	writel_relaxed(reg, priv.base);

	switch (state) {
	case STATE_CPU_FREQ:
		clk_set_parent(priv.powersave_clk, priv.cpu_clk);
		break;
	case STATE_DDR_FREQ:
		clk_set_parent(priv.powersave_clk, priv.ddr_clk);
		break;
	}

	/* Wait-for-Interrupt, while the hardware changes frequency */
	cpu_do_idle();

	/* Enable interrupts to the CPU */
	reg = readl_relaxed(priv.base);
	reg &= ~CPU_SW_INT_BLK;
	writel_relaxed(reg, priv.base);

	local_irq_enable();

	return 0;
}

__attribute__((used)) static int kirkwood_cpufreq_cpu_init(struct cpufreq_policy *policy)
{
	return cpufreq_generic_init(policy, kirkwood_freq_table, 5000);
}

__attribute__((used)) static int kirkwood_cpufreq_probe(struct platform_device *pdev)
{
	struct device_node *np;
	struct resource *res;
	int err;

	priv.dev = &pdev->dev;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	priv.base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(priv.base))
		return PTR_ERR(priv.base);

	np = of_cpu_device_node_get(0);
	if (!np) {
		dev_err(&pdev->dev, "failed to get cpu device node\n");
		return -ENODEV;
	}

	priv.cpu_clk = of_clk_get_by_name(np, "cpu_clk");
	if (IS_ERR(priv.cpu_clk)) {
		dev_err(priv.dev, "Unable to get cpuclk\n");
		return PTR_ERR(priv.cpu_clk);
	}

	err = clk_prepare_enable(priv.cpu_clk);
	if (err) {
		dev_err(priv.dev, "Unable to prepare cpuclk\n");
		return err;
	}

	kirkwood_freq_table[0].frequency = clk_get_rate(priv.cpu_clk) / 1000;

	priv.ddr_clk = of_clk_get_by_name(np, "ddrclk");
	if (IS_ERR(priv.ddr_clk)) {
		dev_err(priv.dev, "Unable to get ddrclk\n");
		err = PTR_ERR(priv.ddr_clk);
		goto out_cpu;
	}

	err = clk_prepare_enable(priv.ddr_clk);
	if (err) {
		dev_err(priv.dev, "Unable to prepare ddrclk\n");
		goto out_cpu;
	}
	kirkwood_freq_table[1].frequency = clk_get_rate(priv.ddr_clk) / 1000;

	priv.powersave_clk = of_clk_get_by_name(np, "powersave");
	if (IS_ERR(priv.powersave_clk)) {
		dev_err(priv.dev, "Unable to get powersave\n");
		err = PTR_ERR(priv.powersave_clk);
		goto out_ddr;
	}
	err = clk_prepare_enable(priv.powersave_clk);
	if (err) {
		dev_err(priv.dev, "Unable to prepare powersave clk\n");
		goto out_ddr;
	}

	of_node_put(np);
	np = NULL;

	err = cpufreq_register_driver(&kirkwood_cpufreq_driver);
	if (!err)
		return 0;

	dev_err(priv.dev, "Failed to register cpufreq driver\n");

	clk_disable_unprepare(priv.powersave_clk);
out_ddr:
	clk_disable_unprepare(priv.ddr_clk);
out_cpu:
	clk_disable_unprepare(priv.cpu_clk);
	of_node_put(np);

	return err;
}

__attribute__((used)) static int kirkwood_cpufreq_remove(struct platform_device *pdev)
{
	cpufreq_unregister_driver(&kirkwood_cpufreq_driver);

	clk_disable_unprepare(priv.powersave_clk);
	clk_disable_unprepare(priv.ddr_clk);
	clk_disable_unprepare(priv.cpu_clk);

	return 0;
}

