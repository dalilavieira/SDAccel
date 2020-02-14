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
typedef  scalar_t__ u32 ;
struct pmf_args {int count; TYPE_1__* u; } ;
struct cpufreq_policy {int dummy; } ;
struct TYPE_5__ {unsigned long frequency; } ;
struct TYPE_4__ {scalar_t__* p; } ;

/* Variables and functions */
 int CPUFREQ_HIGH ; 
 int CPUFREQ_LOW ; 
 int /*<<< orphan*/  DBG (char*,int) ; 
 int HZ ; 
 int cpufreq_generic_init (struct cpufreq_policy*,TYPE_2__*,int /*<<< orphan*/ ) ; 
 TYPE_2__* g5_cpu_freqs ; 
 int g5_pmode_cur ; 
 int g5_switch_freq (unsigned int) ; 
 int /*<<< orphan*/  g5_switch_volt (int) ; 
 int jiffies ; 
 scalar_t__ pfunc_cpu0_volt_high ; 
 scalar_t__ pfunc_cpu0_volt_low ; 
 scalar_t__ pfunc_cpu1_volt_high ; 
 scalar_t__ pfunc_cpu1_volt_low ; 
 scalar_t__ pfunc_cpu_getfreq ; 
 scalar_t__ pfunc_cpu_setfreq_high ; 
 scalar_t__ pfunc_cpu_setfreq_low ; 
 scalar_t__ pfunc_slewing_done ; 
 int pmf_call_one (scalar_t__,struct pmf_args*) ; 
 unsigned long ppc_proc_freq ; 
 int /*<<< orphan*/  pr_warn (char*,...) ; 
 int /*<<< orphan*/  time_after (int,unsigned long) ; 
 int /*<<< orphan*/  transition_latency ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static void g5_pfunc_switch_volt(int speed_mode)
{
	if (speed_mode == CPUFREQ_HIGH) {
		if (pfunc_cpu0_volt_high)
			pmf_call_one(pfunc_cpu0_volt_high, NULL);
		if (pfunc_cpu1_volt_high)
			pmf_call_one(pfunc_cpu1_volt_high, NULL);
	} else {
		if (pfunc_cpu0_volt_low)
			pmf_call_one(pfunc_cpu0_volt_low, NULL);
		if (pfunc_cpu1_volt_low)
			pmf_call_one(pfunc_cpu1_volt_low, NULL);
	}
	usleep_range(10000, 10000); /* should be faster , to fix */
}

__attribute__((used)) static int g5_pfunc_switch_freq(int speed_mode)
{
	struct pmf_args args;
	u32 done = 0;
	unsigned long timeout;
	int rc;

	DBG("g5_pfunc_switch_freq(%d)\n", speed_mode);

	/* If frequency is going up, first ramp up the voltage */
	if (speed_mode < g5_pmode_cur)
		g5_switch_volt(speed_mode);

	/* Do it */
	if (speed_mode == CPUFREQ_HIGH)
		rc = pmf_call_one(pfunc_cpu_setfreq_high, NULL);
	else
		rc = pmf_call_one(pfunc_cpu_setfreq_low, NULL);

	if (rc)
		pr_warn("pfunc switch error %d\n", rc);

	/* It's an irq GPIO so we should be able to just block here,
	 * I'll do that later after I've properly tested the IRQ code for
	 * platform functions
	 */
	timeout = jiffies + HZ/10;
	while(!time_after(jiffies, timeout)) {
		args.count = 1;
		args.u[0].p = &done;
		pmf_call_one(pfunc_slewing_done, &args);
		if (done)
			break;
		usleep_range(500, 500);
	}
	if (done == 0)
		pr_warn("Timeout in clock slewing !\n");

	/* If frequency is going down, last ramp the voltage */
	if (speed_mode > g5_pmode_cur)
		g5_switch_volt(speed_mode);

	g5_pmode_cur = speed_mode;
	ppc_proc_freq = g5_cpu_freqs[speed_mode].frequency * 1000ul;

	return 0;
}

__attribute__((used)) static int g5_pfunc_query_freq(void)
{
	struct pmf_args args;
	u32 val = 0;

	args.count = 1;
	args.u[0].p = &val;
	pmf_call_one(pfunc_cpu_getfreq, &args);
	return val ? CPUFREQ_HIGH : CPUFREQ_LOW;
}

__attribute__((used)) static int g5_cpufreq_target(struct cpufreq_policy *policy, unsigned int index)
{
	return g5_switch_freq(index);
}

__attribute__((used)) static unsigned int g5_cpufreq_get_speed(unsigned int cpu)
{
	return g5_cpu_freqs[g5_pmode_cur].frequency;
}

__attribute__((used)) static int g5_cpufreq_cpu_init(struct cpufreq_policy *policy)
{
	return cpufreq_generic_init(policy, g5_cpu_freqs, transition_latency);
}

