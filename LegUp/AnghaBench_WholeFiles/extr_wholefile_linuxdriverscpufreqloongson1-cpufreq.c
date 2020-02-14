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
struct platform_device {int /*<<< orphan*/  dev; } ;
struct plat_ls1x_cpufreq {int clk_name; int osc_clk_name; unsigned int max_freq; unsigned int min_freq; } ;
struct notifier_block {int dummy; } ;
struct ls1x_cpufreq {int dummy; } ;
struct device {int dummy; } ;
struct cpufreq_policy {unsigned int cur; struct cpufreq_frequency_table* freq_table; struct clk* clk; int /*<<< orphan*/  cpu; } ;
struct cpufreq_frequency_table {unsigned int frequency; } ;
struct clk {int dummy; } ;
struct TYPE_5__ {int /*<<< orphan*/  udelay_val; } ;
struct TYPE_4__ {unsigned int min_freq; unsigned int max_freq; struct clk* osc_clk; struct clk* pll_clk; struct clk* mux_clk; struct clk* clk; int /*<<< orphan*/ * dev; } ;

/* Variables and functions */
 unsigned int CPUFREQ_ENTRY_INVALID ; 
 unsigned long CPUFREQ_POSTCHANGE ; 
 unsigned int CPUFREQ_TABLE_END ; 
 int /*<<< orphan*/  CPUFREQ_TRANSITION_NOTIFIER ; 
 int DIV_CPU_WIDTH ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct clk*) ; 
 int /*<<< orphan*/  LS1X_CLK_PLL_DIV ; 
 int NOTIFY_OK ; 
 int PTR_ERR (struct clk*) ; 
 int RST_CPU ; 
 int RST_CPU_EN ; 
 int __clk_get_name (struct clk*) ; 
 int __raw_readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __raw_writel (int,int /*<<< orphan*/ ) ; 
 struct clk* clk_get_parent (struct clk*) ; 
 int clk_get_rate (struct clk*) ; 
 int /*<<< orphan*/  clk_set_parent (struct clk*,struct clk*) ; 
 int /*<<< orphan*/  clk_set_rate (struct clk*,unsigned int) ; 
 TYPE_1__* cpufreq ; 
 int cpufreq_generic_init (struct cpufreq_policy*,struct cpufreq_frequency_table*,int /*<<< orphan*/ ) ; 
 int cpufreq_register_driver (int /*<<< orphan*/ *) ; 
 int cpufreq_register_notifier (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpufreq_unregister_driver (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cpufreq_unregister_notifier (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 TYPE_2__ current_cpu_data ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,int,unsigned int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 struct plat_ls1x_cpufreq* dev_get_platdata (int /*<<< orphan*/ *) ; 
 struct clk* devm_clk_get (int /*<<< orphan*/ *,int) ; 
 TYPE_1__* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 struct device* get_cpu_device (int /*<<< orphan*/ ) ; 
 struct cpufreq_frequency_table* kcalloc (int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct cpufreq_frequency_table*) ; 
 int /*<<< orphan*/  loops_per_jiffy ; 
 int /*<<< orphan*/  ls1x_cpufreq_driver ; 
 int /*<<< orphan*/  ls1x_cpufreq_notifier_block ; 

__attribute__((used)) static int ls1x_cpufreq_notifier(struct notifier_block *nb,
				 unsigned long val, void *data)
{
	if (val == CPUFREQ_POSTCHANGE)
		current_cpu_data.udelay_val = loops_per_jiffy;

	return NOTIFY_OK;
}

__attribute__((used)) static int ls1x_cpufreq_target(struct cpufreq_policy *policy,
			       unsigned int index)
{
	struct device *cpu_dev = get_cpu_device(policy->cpu);
	unsigned int old_freq, new_freq;

	old_freq = policy->cur;
	new_freq = policy->freq_table[index].frequency;

	/*
	 * The procedure of reconfiguring CPU clk is as below.
	 *
	 *  - Reparent CPU clk to OSC clk
	 *  - Reset CPU clock (very important)
	 *  - Reconfigure CPU DIV
	 *  - Reparent CPU clk back to CPU DIV clk
	 */

	clk_set_parent(policy->clk, cpufreq->osc_clk);
	__raw_writel(__raw_readl(LS1X_CLK_PLL_DIV) | RST_CPU_EN | RST_CPU,
		     LS1X_CLK_PLL_DIV);
	__raw_writel(__raw_readl(LS1X_CLK_PLL_DIV) & ~(RST_CPU_EN | RST_CPU),
		     LS1X_CLK_PLL_DIV);
	clk_set_rate(cpufreq->mux_clk, new_freq * 1000);
	clk_set_parent(policy->clk, cpufreq->mux_clk);
	dev_dbg(cpu_dev, "%u KHz --> %u KHz\n", old_freq, new_freq);

	return 0;
}

__attribute__((used)) static int ls1x_cpufreq_init(struct cpufreq_policy *policy)
{
	struct device *cpu_dev = get_cpu_device(policy->cpu);
	struct cpufreq_frequency_table *freq_tbl;
	unsigned int pll_freq, freq;
	int steps, i, ret;

	pll_freq = clk_get_rate(cpufreq->pll_clk) / 1000;

	steps = 1 << DIV_CPU_WIDTH;
	freq_tbl = kcalloc(steps, sizeof(*freq_tbl), GFP_KERNEL);
	if (!freq_tbl)
		return -ENOMEM;

	for (i = 0; i < (steps - 1); i++) {
		freq = pll_freq / (i + 1);
		if ((freq < cpufreq->min_freq) || (freq > cpufreq->max_freq))
			freq_tbl[i].frequency = CPUFREQ_ENTRY_INVALID;
		else
			freq_tbl[i].frequency = freq;
		dev_dbg(cpu_dev,
			"cpufreq table: index %d: frequency %d\n", i,
			freq_tbl[i].frequency);
	}
	freq_tbl[i].frequency = CPUFREQ_TABLE_END;

	policy->clk = cpufreq->clk;
	ret = cpufreq_generic_init(policy, freq_tbl, 0);
	if (ret)
		kfree(freq_tbl);

	return ret;
}

__attribute__((used)) static int ls1x_cpufreq_exit(struct cpufreq_policy *policy)
{
	kfree(policy->freq_table);
	return 0;
}

__attribute__((used)) static int ls1x_cpufreq_remove(struct platform_device *pdev)
{
	cpufreq_unregister_notifier(&ls1x_cpufreq_notifier_block,
				    CPUFREQ_TRANSITION_NOTIFIER);
	cpufreq_unregister_driver(&ls1x_cpufreq_driver);

	return 0;
}

__attribute__((used)) static int ls1x_cpufreq_probe(struct platform_device *pdev)
{
	struct plat_ls1x_cpufreq *pdata = dev_get_platdata(&pdev->dev);
	struct clk *clk;
	int ret;

	if (!pdata || !pdata->clk_name || !pdata->osc_clk_name) {
		dev_err(&pdev->dev, "platform data missing\n");
		return -EINVAL;
	}

	cpufreq =
	    devm_kzalloc(&pdev->dev, sizeof(struct ls1x_cpufreq), GFP_KERNEL);
	if (!cpufreq)
		return -ENOMEM;

	cpufreq->dev = &pdev->dev;

	clk = devm_clk_get(&pdev->dev, pdata->clk_name);
	if (IS_ERR(clk)) {
		dev_err(&pdev->dev, "unable to get %s clock\n",
			pdata->clk_name);
		return PTR_ERR(clk);
	}
	cpufreq->clk = clk;

	clk = clk_get_parent(clk);
	if (IS_ERR(clk)) {
		dev_err(&pdev->dev, "unable to get parent of %s clock\n",
			__clk_get_name(cpufreq->clk));
		return PTR_ERR(clk);
	}
	cpufreq->mux_clk = clk;

	clk = clk_get_parent(clk);
	if (IS_ERR(clk)) {
		dev_err(&pdev->dev, "unable to get parent of %s clock\n",
			__clk_get_name(cpufreq->mux_clk));
		return PTR_ERR(clk);
	}
	cpufreq->pll_clk = clk;

	clk = devm_clk_get(&pdev->dev, pdata->osc_clk_name);
	if (IS_ERR(clk)) {
		dev_err(&pdev->dev, "unable to get %s clock\n",
			pdata->osc_clk_name);
		return PTR_ERR(clk);
	}
	cpufreq->osc_clk = clk;

	cpufreq->max_freq = pdata->max_freq;
	cpufreq->min_freq = pdata->min_freq;

	ret = cpufreq_register_driver(&ls1x_cpufreq_driver);
	if (ret) {
		dev_err(&pdev->dev,
			"failed to register CPUFreq driver: %d\n", ret);
		return ret;
	}

	ret = cpufreq_register_notifier(&ls1x_cpufreq_notifier_block,
					CPUFREQ_TRANSITION_NOTIFIER);

	if (ret) {
		dev_err(&pdev->dev,
			"failed to register CPUFreq notifier: %d\n",ret);
		cpufreq_unregister_driver(&ls1x_cpufreq_driver);
	}

	return ret;
}

