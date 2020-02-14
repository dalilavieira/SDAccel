#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned int uint32_t ;
struct cpufreq_policy {TYPE_2__* freq_table; } ;
struct cpufreq_frequency_table {unsigned long frequency; int driver_data; } ;
struct TYPE_4__ {unsigned int driver_data; } ;
struct TYPE_3__ {unsigned int clk_mult; int max_freqs; int bmips_type; } ;

/* Variables and functions */
#define  BMIPS5000 129 
#define  BMIPS5200 128 
 unsigned int BMIPS5_CLK_DIV_MASK ; 
 int BMIPS5_CLK_DIV_SET_SHIFT ; 
 unsigned int BMIPS5_CLK_DIV_SHIFT ; 
 int /*<<< orphan*/  BMIPS_CPUFREQ_NAME ; 
 unsigned long CPUFREQ_TABLE_END ; 
 int /*<<< orphan*/  ENOMEM ; 
 int ENOTSUPP ; 
 struct cpufreq_frequency_table* ERR_PTR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct cpufreq_frequency_table*) ; 
 int PTR_ERR (struct cpufreq_frequency_table*) ; 
 int /*<<< orphan*/  TRANSITION_LATENCY ; 
 int /*<<< orphan*/  change_c0_brcm_mode (unsigned int,int) ; 
 int cpufreq_generic_init (struct cpufreq_policy*,struct cpufreq_frequency_table*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (TYPE_2__*) ; 
 struct cpufreq_frequency_table* kmalloc_array (int,int,int /*<<< orphan*/ ) ; 
 unsigned int mips_hpt_frequency ; 
 int /*<<< orphan*/  pr_err (char*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  pr_info (char*,int /*<<< orphan*/ ) ; 
 TYPE_1__* priv ; 
 unsigned int read_c0_brcm_mode () ; 

__attribute__((used)) static int htp_freq_to_cpu_freq(unsigned int clk_mult)
{
	return mips_hpt_frequency * clk_mult / 1000;
}

__attribute__((used)) static struct cpufreq_frequency_table *
bmips_cpufreq_get_freq_table(const struct cpufreq_policy *policy)
{
	struct cpufreq_frequency_table *table;
	unsigned long cpu_freq;
	int i;

	cpu_freq = htp_freq_to_cpu_freq(priv->clk_mult);

	table = kmalloc_array(priv->max_freqs + 1, sizeof(*table), GFP_KERNEL);
	if (!table)
		return ERR_PTR(-ENOMEM);

	for (i = 0; i < priv->max_freqs; i++) {
		table[i].frequency = cpu_freq / (1 << i);
		table[i].driver_data = i;
	}
	table[i].frequency = CPUFREQ_TABLE_END;

	return table;
}

__attribute__((used)) static unsigned int bmips_cpufreq_get(unsigned int cpu)
{
	unsigned int div;
	uint32_t mode;

	switch (priv->bmips_type) {
	case BMIPS5200:
	case BMIPS5000:
		mode = read_c0_brcm_mode();
		div = ((mode >> BMIPS5_CLK_DIV_SHIFT) & BMIPS5_CLK_DIV_MASK);
		break;
	default:
		div = 0;
	}

	return htp_freq_to_cpu_freq(priv->clk_mult) / (1 << div);
}

__attribute__((used)) static int bmips_cpufreq_target_index(struct cpufreq_policy *policy,
				      unsigned int index)
{
	unsigned int div = policy->freq_table[index].driver_data;

	switch (priv->bmips_type) {
	case BMIPS5200:
	case BMIPS5000:
		change_c0_brcm_mode(BMIPS5_CLK_DIV_MASK << BMIPS5_CLK_DIV_SHIFT,
				    (1 << BMIPS5_CLK_DIV_SET_SHIFT) |
				    (div << BMIPS5_CLK_DIV_SHIFT));
		break;
	default:
		return -ENOTSUPP;
	}

	return 0;
}

__attribute__((used)) static int bmips_cpufreq_exit(struct cpufreq_policy *policy)
{
	kfree(policy->freq_table);

	return 0;
}

__attribute__((used)) static int bmips_cpufreq_init(struct cpufreq_policy *policy)
{
	struct cpufreq_frequency_table *freq_table;
	int ret;

	freq_table = bmips_cpufreq_get_freq_table(policy);
	if (IS_ERR(freq_table)) {
		ret = PTR_ERR(freq_table);
		pr_err("%s: couldn't determine frequency table (%d).\n",
			BMIPS_CPUFREQ_NAME, ret);
		return ret;
	}

	ret = cpufreq_generic_init(policy, freq_table, TRANSITION_LATENCY);
	if (ret)
		bmips_cpufreq_exit(policy);
	else
		pr_info("%s: registered\n", BMIPS_CPUFREQ_NAME);

	return ret;
}

