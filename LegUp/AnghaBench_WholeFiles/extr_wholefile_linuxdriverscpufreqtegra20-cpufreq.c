#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {int (* init ) (struct cpufreq_policy*) ;int (* exit ) (struct cpufreq_policy*) ;int (* target_index ) (struct cpufreq_policy*,unsigned int) ;unsigned int (* get_intermediate ) (struct cpufreq_policy*,unsigned int) ;int (* target_intermediate ) (struct cpufreq_policy*,unsigned int) ;int /*<<< orphan*/  name; struct tegra20_cpufreq* driver_data; int /*<<< orphan*/  suspend; int /*<<< orphan*/  verify; int /*<<< orphan*/  flags; int /*<<< orphan*/  attr; int /*<<< orphan*/  get; } ;
struct tegra20_cpufreq {int pll_x_prepared; void* cpu_clk; void* pll_x_clk; void* pll_p_clk; TYPE_2__ driver; int /*<<< orphan*/ * dev; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct cpufreq_policy {unsigned int cur; unsigned long suspend_freq; void* clk; } ;
struct TYPE_5__ {unsigned int frequency; } ;

/* Variables and functions */
 int /*<<< orphan*/  CPUFREQ_NAME_LEN ; 
 int /*<<< orphan*/  CPUFREQ_NEED_INITIAL_FREQ_CHECK ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (void*) ; 
 int PTR_ERR (void*) ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int /*<<< orphan*/  clk_disable_unprepare (void*) ; 
 int clk_get_rate (void*) ; 
 void* clk_get_sys (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  clk_prepare_enable (void*) ; 
 int /*<<< orphan*/  clk_put (void*) ; 
 int clk_set_parent (void*,void*) ; 
 int clk_set_rate (void*,unsigned long) ; 
 int /*<<< orphan*/  cpufreq_generic_attr ; 
 int /*<<< orphan*/  cpufreq_generic_frequency_table_verify ; 
 int /*<<< orphan*/  cpufreq_generic_get ; 
 int cpufreq_generic_init (struct cpufreq_policy*,TYPE_1__*,int) ; 
 int /*<<< orphan*/  cpufreq_generic_suspend ; 
 struct tegra20_cpufreq* cpufreq_get_driver_data () ; 
 int cpufreq_register_driver (TYPE_2__*) ; 
 int /*<<< orphan*/  cpufreq_unregister_driver (TYPE_2__*) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,unsigned long) ; 
 struct tegra20_cpufreq* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 TYPE_1__* freq_table ; 
 struct tegra20_cpufreq* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct tegra20_cpufreq*) ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static unsigned int tegra_get_intermediate(struct cpufreq_policy *policy,
					   unsigned int index)
{
	struct tegra20_cpufreq *cpufreq = cpufreq_get_driver_data();
	unsigned int ifreq = clk_get_rate(cpufreq->pll_p_clk) / 1000;

	/*
	 * Don't switch to intermediate freq if:
	 * - we are already at it, i.e. policy->cur == ifreq
	 * - index corresponds to ifreq
	 */
	if (freq_table[index].frequency == ifreq || policy->cur == ifreq)
		return 0;

	return ifreq;
}

__attribute__((used)) static int tegra_target_intermediate(struct cpufreq_policy *policy,
				     unsigned int index)
{
	struct tegra20_cpufreq *cpufreq = cpufreq_get_driver_data();
	int ret;

	/*
	 * Take an extra reference to the main pll so it doesn't turn
	 * off when we move the cpu off of it as enabling it again while we
	 * switch to it from tegra_target() would take additional time.
	 *
	 * When target-freq is equal to intermediate freq we don't need to
	 * switch to an intermediate freq and so this routine isn't called.
	 * Also, we wouldn't be using pll_x anymore and must not take extra
	 * reference to it, as it can be disabled now to save some power.
	 */
	clk_prepare_enable(cpufreq->pll_x_clk);

	ret = clk_set_parent(cpufreq->cpu_clk, cpufreq->pll_p_clk);
	if (ret)
		clk_disable_unprepare(cpufreq->pll_x_clk);
	else
		cpufreq->pll_x_prepared = true;

	return ret;
}

__attribute__((used)) static int tegra_target(struct cpufreq_policy *policy, unsigned int index)
{
	struct tegra20_cpufreq *cpufreq = cpufreq_get_driver_data();
	unsigned long rate = freq_table[index].frequency;
	unsigned int ifreq = clk_get_rate(cpufreq->pll_p_clk) / 1000;
	int ret;

	/*
	 * target freq == pll_p, don't need to take extra reference to pll_x_clk
	 * as it isn't used anymore.
	 */
	if (rate == ifreq)
		return clk_set_parent(cpufreq->cpu_clk, cpufreq->pll_p_clk);

	ret = clk_set_rate(cpufreq->pll_x_clk, rate * 1000);
	/* Restore to earlier frequency on error, i.e. pll_x */
	if (ret)
		dev_err(cpufreq->dev, "Failed to change pll_x to %lu\n", rate);

	ret = clk_set_parent(cpufreq->cpu_clk, cpufreq->pll_x_clk);
	/* This shouldn't fail while changing or restoring */
	WARN_ON(ret);

	/*
	 * Drop count to pll_x clock only if we switched to intermediate freq
	 * earlier while transitioning to a target frequency.
	 */
	if (cpufreq->pll_x_prepared) {
		clk_disable_unprepare(cpufreq->pll_x_clk);
		cpufreq->pll_x_prepared = false;
	}

	return ret;
}

__attribute__((used)) static int tegra_cpu_init(struct cpufreq_policy *policy)
{
	struct tegra20_cpufreq *cpufreq = cpufreq_get_driver_data();
	int ret;

	clk_prepare_enable(cpufreq->cpu_clk);

	/* FIXME: what's the actual transition time? */
	ret = cpufreq_generic_init(policy, freq_table, 300 * 1000);
	if (ret) {
		clk_disable_unprepare(cpufreq->cpu_clk);
		return ret;
	}

	policy->clk = cpufreq->cpu_clk;
	policy->suspend_freq = freq_table[0].frequency;
	return 0;
}

__attribute__((used)) static int tegra_cpu_exit(struct cpufreq_policy *policy)
{
	struct tegra20_cpufreq *cpufreq = cpufreq_get_driver_data();

	clk_disable_unprepare(cpufreq->cpu_clk);
	return 0;
}

__attribute__((used)) static int tegra20_cpufreq_probe(struct platform_device *pdev)
{
	struct tegra20_cpufreq *cpufreq;
	int err;

	cpufreq = devm_kzalloc(&pdev->dev, sizeof(*cpufreq), GFP_KERNEL);
	if (!cpufreq)
		return -ENOMEM;

	cpufreq->cpu_clk = clk_get_sys(NULL, "cclk");
	if (IS_ERR(cpufreq->cpu_clk))
		return PTR_ERR(cpufreq->cpu_clk);

	cpufreq->pll_x_clk = clk_get_sys(NULL, "pll_x");
	if (IS_ERR(cpufreq->pll_x_clk)) {
		err = PTR_ERR(cpufreq->pll_x_clk);
		goto put_cpu;
	}

	cpufreq->pll_p_clk = clk_get_sys(NULL, "pll_p");
	if (IS_ERR(cpufreq->pll_p_clk)) {
		err = PTR_ERR(cpufreq->pll_p_clk);
		goto put_pll_x;
	}

	cpufreq->dev = &pdev->dev;
	cpufreq->driver.get = cpufreq_generic_get;
	cpufreq->driver.attr = cpufreq_generic_attr;
	cpufreq->driver.init = tegra_cpu_init;
	cpufreq->driver.exit = tegra_cpu_exit;
	cpufreq->driver.flags = CPUFREQ_NEED_INITIAL_FREQ_CHECK;
	cpufreq->driver.verify = cpufreq_generic_frequency_table_verify;
	cpufreq->driver.suspend = cpufreq_generic_suspend;
	cpufreq->driver.driver_data = cpufreq;
	cpufreq->driver.target_index = tegra_target;
	cpufreq->driver.get_intermediate = tegra_get_intermediate;
	cpufreq->driver.target_intermediate = tegra_target_intermediate;
	snprintf(cpufreq->driver.name, CPUFREQ_NAME_LEN, "tegra");

	err = cpufreq_register_driver(&cpufreq->driver);
	if (err)
		goto put_pll_p;

	platform_set_drvdata(pdev, cpufreq);

	return 0;

put_pll_p:
	clk_put(cpufreq->pll_p_clk);
put_pll_x:
	clk_put(cpufreq->pll_x_clk);
put_cpu:
	clk_put(cpufreq->cpu_clk);

	return err;
}

__attribute__((used)) static int tegra20_cpufreq_remove(struct platform_device *pdev)
{
	struct tegra20_cpufreq *cpufreq = platform_get_drvdata(pdev);

	cpufreq_unregister_driver(&cpufreq->driver);

	clk_put(cpufreq->pll_p_clk);
	clk_put(cpufreq->pll_x_clk);
	clk_put(cpufreq->cpu_clk);

	return 0;
}

