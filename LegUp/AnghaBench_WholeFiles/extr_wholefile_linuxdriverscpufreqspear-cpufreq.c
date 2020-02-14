#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct property {int length; int /*<<< orphan*/ * value; } ;
struct platform_device {int dummy; } ;
struct device_node {int dummy; } ;
struct cpufreq_policy {struct clk* clk; } ;
struct cpufreq_frequency_table {int frequency; } ;
struct clk {int dummy; } ;
typedef  int /*<<< orphan*/  __be32 ;
struct TYPE_2__ {struct clk* clk; struct cpufreq_frequency_table* freq_tbl; int /*<<< orphan*/  transition_latency; } ;

/* Variables and functions */
 int /*<<< orphan*/  CPUFREQ_ETERNAL ; 
 int CPUFREQ_TABLE_END ; 
 int /*<<< orphan*/  EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 struct clk* ERR_PTR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct clk*) ; 
 int PTR_ERR (struct clk*) ; 
 int be32_to_cpup (int /*<<< orphan*/ ) ; 
 void* clk_get (int /*<<< orphan*/ *,char const*) ; 
 struct clk* clk_get_parent (struct clk*) ; 
 int /*<<< orphan*/  clk_put (struct clk*) ; 
 long clk_round_rate (struct clk*,long) ; 
 int clk_set_parent (struct clk*,struct clk*) ; 
 int clk_set_rate (struct clk*,long) ; 
 int cpufreq_generic_init (struct cpufreq_policy*,struct cpufreq_frequency_table*,int /*<<< orphan*/ ) ; 
 int cpufreq_register_driver (int /*<<< orphan*/ *) ; 
 struct cpufreq_frequency_table* kcalloc (int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct cpufreq_frequency_table*) ; 
 struct device_node* of_cpu_device_node_get (int /*<<< orphan*/ ) ; 
 struct property* of_find_property (struct device_node*,char*,int /*<<< orphan*/ *) ; 
 scalar_t__ of_machine_is_compatible (char*) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 scalar_t__ of_property_read_u32 (struct device_node*,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pr_err (char*,...) ; 
 TYPE_1__ spear_cpufreq ; 
 int /*<<< orphan*/  spear_cpufreq_driver ; 

__attribute__((used)) static struct clk *spear1340_cpu_get_possible_parent(unsigned long newfreq)
{
	struct clk *sys_pclk;
	int pclk;
	/*
	 * In SPEAr1340, cpu clk's parent sys clk can take input from
	 * following sources
	 */
	const char *sys_clk_src[] = {
		"sys_syn_clk",
		"pll1_clk",
		"pll2_clk",
		"pll3_clk",
	};

	/*
	 * As sys clk can have multiple source with their own range
	 * limitation so we choose possible sources accordingly
	 */
	if (newfreq <= 300000000)
		pclk = 0; /* src is sys_syn_clk */
	else if (newfreq > 300000000 && newfreq <= 500000000)
		pclk = 3; /* src is pll3_clk */
	else if (newfreq == 600000000)
		pclk = 1; /* src is pll1_clk */
	else
		return ERR_PTR(-EINVAL);

	/* Get parent to sys clock */
	sys_pclk = clk_get(NULL, sys_clk_src[pclk]);
	if (IS_ERR(sys_pclk))
		pr_err("Failed to get %s clock\n", sys_clk_src[pclk]);

	return sys_pclk;
}

__attribute__((used)) static int spear1340_set_cpu_rate(struct clk *sys_pclk, unsigned long newfreq)
{
	struct clk *sys_clk;
	int ret = 0;

	sys_clk = clk_get_parent(spear_cpufreq.clk);
	if (IS_ERR(sys_clk)) {
		pr_err("failed to get cpu's parent (sys) clock\n");
		return PTR_ERR(sys_clk);
	}

	/* Set the rate of the source clock before changing the parent */
	ret = clk_set_rate(sys_pclk, newfreq);
	if (ret) {
		pr_err("Failed to set sys clk rate to %lu\n", newfreq);
		return ret;
	}

	ret = clk_set_parent(sys_clk, sys_pclk);
	if (ret) {
		pr_err("Failed to set sys clk parent\n");
		return ret;
	}

	return 0;
}

__attribute__((used)) static int spear_cpufreq_target(struct cpufreq_policy *policy,
		unsigned int index)
{
	long newfreq;
	struct clk *srcclk;
	int ret, mult = 1;

	newfreq = spear_cpufreq.freq_tbl[index].frequency * 1000;

	if (of_machine_is_compatible("st,spear1340")) {
		/*
		 * SPEAr1340 is special in the sense that due to the possibility
		 * of multiple clock sources for cpu clk's parent we can have
		 * different clock source for different frequency of cpu clk.
		 * Hence we need to choose one from amongst these possible clock
		 * sources.
		 */
		srcclk = spear1340_cpu_get_possible_parent(newfreq);
		if (IS_ERR(srcclk)) {
			pr_err("Failed to get src clk\n");
			return PTR_ERR(srcclk);
		}

		/* SPEAr1340: src clk is always 2 * intended cpu clk */
		mult = 2;
	} else {
		/*
		 * src clock to be altered is ancestor of cpu clock. Hence we
		 * can directly work on cpu clk
		 */
		srcclk = spear_cpufreq.clk;
	}

	newfreq = clk_round_rate(srcclk, newfreq * mult);
	if (newfreq <= 0) {
		pr_err("clk_round_rate failed for cpu src clock\n");
		return newfreq;
	}

	if (mult == 2)
		ret = spear1340_set_cpu_rate(srcclk, newfreq);
	else
		ret = clk_set_rate(spear_cpufreq.clk, newfreq);

	if (ret)
		pr_err("CPU Freq: cpu clk_set_rate failed: %d\n", ret);

	return ret;
}

__attribute__((used)) static int spear_cpufreq_init(struct cpufreq_policy *policy)
{
	policy->clk = spear_cpufreq.clk;
	return cpufreq_generic_init(policy, spear_cpufreq.freq_tbl,
			spear_cpufreq.transition_latency);
}

__attribute__((used)) static int spear_cpufreq_probe(struct platform_device *pdev)
{
	struct device_node *np;
	const struct property *prop;
	struct cpufreq_frequency_table *freq_tbl;
	const __be32 *val;
	int cnt, i, ret;

	np = of_cpu_device_node_get(0);
	if (!np) {
		pr_err("No cpu node found\n");
		return -ENODEV;
	}

	if (of_property_read_u32(np, "clock-latency",
				&spear_cpufreq.transition_latency))
		spear_cpufreq.transition_latency = CPUFREQ_ETERNAL;

	prop = of_find_property(np, "cpufreq_tbl", NULL);
	if (!prop || !prop->value) {
		pr_err("Invalid cpufreq_tbl\n");
		ret = -ENODEV;
		goto out_put_node;
	}

	cnt = prop->length / sizeof(u32);
	val = prop->value;

	freq_tbl = kcalloc(cnt + 1, sizeof(*freq_tbl), GFP_KERNEL);
	if (!freq_tbl) {
		ret = -ENOMEM;
		goto out_put_node;
	}

	for (i = 0; i < cnt; i++)
		freq_tbl[i].frequency = be32_to_cpup(val++);

	freq_tbl[i].frequency = CPUFREQ_TABLE_END;

	spear_cpufreq.freq_tbl = freq_tbl;

	of_node_put(np);

	spear_cpufreq.clk = clk_get(NULL, "cpu_clk");
	if (IS_ERR(spear_cpufreq.clk)) {
		pr_err("Unable to get CPU clock\n");
		ret = PTR_ERR(spear_cpufreq.clk);
		goto out_put_mem;
	}

	ret = cpufreq_register_driver(&spear_cpufreq_driver);
	if (!ret)
		return 0;

	pr_err("failed register driver: %d\n", ret);
	clk_put(spear_cpufreq.clk);

out_put_mem:
	kfree(freq_tbl);
	return ret;

out_put_node:
	of_node_put(np);
	return ret;
}

