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
typedef  int uint32_t ;
struct pxa3xx_freq_info {int cpufreq_mhz; int core_xn; int /*<<< orphan*/  dmcfs; int /*<<< orphan*/  hss; int /*<<< orphan*/  sflfs; int /*<<< orphan*/  smcfs; int /*<<< orphan*/  core_xl; } ;
struct TYPE_2__ {int min_freq; int max_freq; int transition_latency; } ;
struct cpufreq_policy {scalar_t__ cpu; int min; int max; TYPE_1__ cpuinfo; struct cpufreq_frequency_table* freq_table; } ;
struct cpufreq_frequency_table {int driver_data; int frequency; } ;

/* Variables and functions */
 int ACCR ; 
 int ACCR_DMCFS (int /*<<< orphan*/ ) ; 
 int ACCR_DMCFS_MASK ; 
 int ACCR_HSS (int /*<<< orphan*/ ) ; 
 int ACCR_HSS_MASK ; 
 int ACCR_SFLFS (int /*<<< orphan*/ ) ; 
 int ACCR_SFLFS_MASK ; 
 int ACCR_SMCFS (int /*<<< orphan*/ ) ; 
 int ACCR_SMCFS_MASK ; 
 int ACCR_XL (int /*<<< orphan*/ ) ; 
 int ACCR_XL_MASK ; 
 int ACCR_XN (int) ; 
 int ACCR_XN_MASK ; 
 int ACCR_XSPCLK (int /*<<< orphan*/ ) ; 
 int ACCR_XSPCLK_MASK ; 
 int ACSR ; 
 int ARRAY_SIZE (struct pxa3xx_freq_info*) ; 
 int CPUFREQ_TABLE_END ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  XSPCLK_NONE ; 
 scalar_t__ cpu_is_pxa300 () ; 
 scalar_t__ cpu_is_pxa310 () ; 
 scalar_t__ cpu_is_pxa320 () ; 
 int /*<<< orphan*/  cpu_relax () ; 
 struct cpufreq_frequency_table* kcalloc (int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int /*<<< orphan*/  pr_info (char*) ; 
 struct pxa3xx_freq_info* pxa300_freqs ; 
 struct pxa3xx_freq_info* pxa320_freqs ; 
 struct pxa3xx_freq_info* pxa3xx_freqs ; 
 int pxa3xx_freqs_num ; 
 struct cpufreq_frequency_table* pxa3xx_freqs_table ; 
 unsigned int pxa3xx_get_clk_frequency_khz (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int setup_freqs_table(struct cpufreq_policy *policy,
			     struct pxa3xx_freq_info *freqs, int num)
{
	struct cpufreq_frequency_table *table;
	int i;

	table = kcalloc(num + 1, sizeof(*table), GFP_KERNEL);
	if (table == NULL)
		return -ENOMEM;

	for (i = 0; i < num; i++) {
		table[i].driver_data = i;
		table[i].frequency = freqs[i].cpufreq_mhz * 1000;
	}
	table[num].driver_data = i;
	table[num].frequency = CPUFREQ_TABLE_END;

	pxa3xx_freqs = freqs;
	pxa3xx_freqs_num = num;
	pxa3xx_freqs_table = table;

	policy->freq_table = table;

	return 0;
}

__attribute__((used)) static void __update_core_freq(struct pxa3xx_freq_info *info)
{
	uint32_t mask = ACCR_XN_MASK | ACCR_XL_MASK;
	uint32_t accr = ACCR;
	uint32_t xclkcfg;

	accr &= ~(ACCR_XN_MASK | ACCR_XL_MASK | ACCR_XSPCLK_MASK);
	accr |= ACCR_XN(info->core_xn) | ACCR_XL(info->core_xl);

	/* No clock until core PLL is re-locked */
	accr |= ACCR_XSPCLK(XSPCLK_NONE);

	xclkcfg = (info->core_xn == 2) ? 0x3 : 0x2;	/* turbo bit */

	ACCR = accr;
	__asm__("mcr p14, 0, %0, c6, c0, 0\n" : : "r"(xclkcfg));

	while ((ACSR & mask) != (accr & mask))
		cpu_relax();
}

__attribute__((used)) static void __update_bus_freq(struct pxa3xx_freq_info *info)
{
	uint32_t mask;
	uint32_t accr = ACCR;

	mask = ACCR_SMCFS_MASK | ACCR_SFLFS_MASK | ACCR_HSS_MASK |
		ACCR_DMCFS_MASK;

	accr &= ~mask;
	accr |= ACCR_SMCFS(info->smcfs) | ACCR_SFLFS(info->sflfs) |
		ACCR_HSS(info->hss) | ACCR_DMCFS(info->dmcfs);

	ACCR = accr;

	while ((ACSR & mask) != (accr & mask))
		cpu_relax();
}

__attribute__((used)) static unsigned int pxa3xx_cpufreq_get(unsigned int cpu)
{
	return pxa3xx_get_clk_frequency_khz(0);
}

__attribute__((used)) static int pxa3xx_cpufreq_set(struct cpufreq_policy *policy, unsigned int index)
{
	struct pxa3xx_freq_info *next;
	unsigned long flags;

	if (policy->cpu != 0)
		return -EINVAL;

	next = &pxa3xx_freqs[index];

	local_irq_save(flags);
	__update_core_freq(next);
	__update_bus_freq(next);
	local_irq_restore(flags);

	return 0;
}

__attribute__((used)) static int pxa3xx_cpufreq_init(struct cpufreq_policy *policy)
{
	int ret = -EINVAL;

	/* set default policy and cpuinfo */
	policy->min = policy->cpuinfo.min_freq = 104000;
	policy->max = policy->cpuinfo.max_freq =
		(cpu_is_pxa320()) ? 806000 : 624000;
	policy->cpuinfo.transition_latency = 1000; /* FIXME: 1 ms, assumed */

	if (cpu_is_pxa300() || cpu_is_pxa310())
		ret = setup_freqs_table(policy, pxa300_freqs,
					ARRAY_SIZE(pxa300_freqs));

	if (cpu_is_pxa320())
		ret = setup_freqs_table(policy, pxa320_freqs,
					ARRAY_SIZE(pxa320_freqs));

	if (ret) {
		pr_err("failed to setup frequency table\n");
		return ret;
	}

	pr_info("CPUFREQ support for PXA3xx initialized\n");
	return 0;
}

