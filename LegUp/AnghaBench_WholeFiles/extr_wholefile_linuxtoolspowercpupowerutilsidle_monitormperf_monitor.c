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
struct cpuidle_monitor {int /*<<< orphan*/  name; int /*<<< orphan*/  name_len; } ;
struct TYPE_4__ {int caps; scalar_t__ vendor; } ;
struct TYPE_3__ {int /*<<< orphan*/  name; } ;

/* Variables and functions */
 unsigned int AVG_FREQ ; 
 unsigned int C0 ; 
 int /*<<< orphan*/  CLOCK_REALTIME ; 
 int CPUPOWER_CAP_APERF ; 
 int CPUPOWER_CAP_INV_TSC ; 
 unsigned int Cx ; 
 scalar_t__ MAX_FREQ_SYSFS ; 
 scalar_t__ MAX_FREQ_TSC_REF ; 
 int /*<<< orphan*/  MSR_AMD_HWCR ; 
 int /*<<< orphan*/  MSR_APERF ; 
 int /*<<< orphan*/  MSR_MPERF ; 
 int /*<<< orphan*/  MSR_TSC ; 
 scalar_t__ X86_VENDOR_AMD ; 
 scalar_t__ X86_VENDOR_INTEL ; 
 unsigned long long* aperf_current_count ; 
 unsigned long long* aperf_previous_count ; 
 unsigned int base_cpu ; 
 unsigned long long* calloc (int,int) ; 
 int /*<<< orphan*/  clock_gettime (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int cpu_count ; 
 scalar_t__ cpufreq_get_hardware_limits (int /*<<< orphan*/ ,unsigned long*,double*) ; 
 TYPE_2__ cpupower_cpu_info ; 
 int /*<<< orphan*/  dprint (char*,...) ; 
 int /*<<< orphan*/  free (unsigned long long*) ; 
 unsigned long long* is_valid ; 
 scalar_t__ max_freq_mode ; 
 double max_frequency ; 
 TYPE_1__* mperf_cstates ; 
 unsigned long long* mperf_current_count ; 
 struct cpuidle_monitor mperf_monitor ; 
 unsigned long long* mperf_previous_count ; 
 int read_msr (unsigned int,int /*<<< orphan*/ ,unsigned long long*) ; 
 int /*<<< orphan*/  strlen (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  time_end ; 
 int /*<<< orphan*/  time_start ; 
 double timespec_diff_us (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 unsigned long long tsc_at_measure_end ; 
 unsigned long long tsc_at_measure_start ; 

__attribute__((used)) static int mperf_get_tsc(unsigned long long *tsc)
{
	int ret;

	ret = read_msr(base_cpu, MSR_TSC, tsc);
	if (ret)
		dprint("Reading TSC MSR failed, returning %llu\n", *tsc);
	return ret;
}

__attribute__((used)) static int mperf_init_stats(unsigned int cpu)
{
	unsigned long long val;
	int ret;

	ret = read_msr(cpu, MSR_APERF, &val);
	aperf_previous_count[cpu] = val;
	ret |= read_msr(cpu, MSR_MPERF, &val);
	mperf_previous_count[cpu] = val;
	is_valid[cpu] = !ret;

	return 0;
}

__attribute__((used)) static int mperf_measure_stats(unsigned int cpu)
{
	unsigned long long val;
	int ret;

	ret = read_msr(cpu, MSR_APERF, &val);
	aperf_current_count[cpu] = val;
	ret |= read_msr(cpu, MSR_MPERF, &val);
	mperf_current_count[cpu] = val;
	is_valid[cpu] = !ret;

	return 0;
}

__attribute__((used)) static int mperf_get_count_percent(unsigned int id, double *percent,
				   unsigned int cpu)
{
	unsigned long long aperf_diff, mperf_diff, tsc_diff;
	unsigned long long timediff;

	if (!is_valid[cpu])
		return -1;

	if (id != C0 && id != Cx)
		return -1;

	mperf_diff = mperf_current_count[cpu] - mperf_previous_count[cpu];
	aperf_diff = aperf_current_count[cpu] - aperf_previous_count[cpu];

	if (max_freq_mode == MAX_FREQ_TSC_REF) {
		tsc_diff = tsc_at_measure_end - tsc_at_measure_start;
		*percent = 100.0 * mperf_diff / tsc_diff;
		dprint("%s: TSC Ref - mperf_diff: %llu, tsc_diff: %llu\n",
		       mperf_cstates[id].name, mperf_diff, tsc_diff);
	} else if (max_freq_mode == MAX_FREQ_SYSFS) {
		timediff = max_frequency * timespec_diff_us(time_start, time_end);
		*percent = 100.0 * mperf_diff / timediff;
		dprint("%s: MAXFREQ - mperf_diff: %llu, time_diff: %llu\n",
		       mperf_cstates[id].name, mperf_diff, timediff);
	} else
		return -1;

	if (id == Cx)
		*percent = 100.0 - *percent;

	dprint("%s: previous: %llu - current: %llu - (%u)\n",
		mperf_cstates[id].name, mperf_diff, aperf_diff, cpu);
	dprint("%s: %f\n", mperf_cstates[id].name, *percent);
	return 0;
}

__attribute__((used)) static int mperf_get_count_freq(unsigned int id, unsigned long long *count,
				unsigned int cpu)
{
	unsigned long long aperf_diff, mperf_diff, time_diff, tsc_diff;

	if (id != AVG_FREQ)
		return 1;

	if (!is_valid[cpu])
		return -1;

	mperf_diff = mperf_current_count[cpu] - mperf_previous_count[cpu];
	aperf_diff = aperf_current_count[cpu] - aperf_previous_count[cpu];

	if (max_freq_mode == MAX_FREQ_TSC_REF) {
		/* Calculate max_freq from TSC count */
		tsc_diff = tsc_at_measure_end - tsc_at_measure_start;
		time_diff = timespec_diff_us(time_start, time_end);
		max_frequency = tsc_diff / time_diff;
	}

	*count = max_frequency * ((double)aperf_diff / mperf_diff);
	dprint("%s: Average freq based on %s maximum frequency:\n",
	       mperf_cstates[id].name,
	       (max_freq_mode == MAX_FREQ_TSC_REF) ? "TSC calculated" : "sysfs read");
	dprint("max_frequency: %lu\n", max_frequency);
	dprint("aperf_diff: %llu\n", aperf_diff);
	dprint("mperf_diff: %llu\n", mperf_diff);
	dprint("avg freq:   %llu\n", *count);
	return 0;
}

__attribute__((used)) static int mperf_start(void)
{
	int cpu;
	unsigned long long dbg;

	clock_gettime(CLOCK_REALTIME, &time_start);
	mperf_get_tsc(&tsc_at_measure_start);

	for (cpu = 0; cpu < cpu_count; cpu++)
		mperf_init_stats(cpu);

	mperf_get_tsc(&dbg);
	dprint("TSC diff: %llu\n", dbg - tsc_at_measure_start);
	return 0;
}

__attribute__((used)) static int mperf_stop(void)
{
	unsigned long long dbg;
	int cpu;

	for (cpu = 0; cpu < cpu_count; cpu++)
		mperf_measure_stats(cpu);

	mperf_get_tsc(&tsc_at_measure_end);
	clock_gettime(CLOCK_REALTIME, &time_end);

	mperf_get_tsc(&dbg);
	dprint("TSC diff: %llu\n", dbg - tsc_at_measure_end);

	return 0;
}

__attribute__((used)) static int init_maxfreq_mode(void)
{
	int ret;
	unsigned long long hwcr;
	unsigned long min;

	if (!(cpupower_cpu_info.caps & CPUPOWER_CAP_INV_TSC))
		goto use_sysfs;

	if (cpupower_cpu_info.vendor == X86_VENDOR_AMD) {
		/* MSR_AMD_HWCR tells us whether TSC runs at P0/mperf
		 * freq.
		 * A test whether hwcr is accessable/available would be:
		 * (cpupower_cpu_info.family > 0x10 ||
		 *   cpupower_cpu_info.family == 0x10 &&
		 *   cpupower_cpu_info.model >= 0x2))
		 * This should be the case for all aperf/mperf
		 * capable AMD machines and is therefore safe to test here.
		 * Compare with Linus kernel git commit: acf01734b1747b1ec4
		 */
		ret = read_msr(0, MSR_AMD_HWCR, &hwcr);
		/*
		 * If the MSR read failed, assume a Xen system that did
		 * not explicitly provide access to it and assume TSC works
		*/
		if (ret != 0) {
			dprint("TSC read 0x%x failed - assume TSC working\n",
			       MSR_AMD_HWCR);
			return 0;
		} else if (1 & (hwcr >> 24)) {
			max_freq_mode = MAX_FREQ_TSC_REF;
			return 0;
		} else { /* Use sysfs max frequency if available */ }
	} else if (cpupower_cpu_info.vendor == X86_VENDOR_INTEL) {
		/*
		 * On Intel we assume mperf (in C0) is ticking at same
		 * rate than TSC
		 */
		max_freq_mode = MAX_FREQ_TSC_REF;
		return 0;
	}
use_sysfs:
	if (cpufreq_get_hardware_limits(0, &min, &max_frequency)) {
		dprint("Cannot retrieve max freq from cpufreq kernel "
		       "subsystem\n");
		return -1;
	}
	max_freq_mode = MAX_FREQ_SYSFS;
	max_frequency /= 1000; /* Default automatically to MHz value */
	return 0;
}

struct cpuidle_monitor *mperf_register(void)
{
	if (!(cpupower_cpu_info.caps & CPUPOWER_CAP_APERF))
		return NULL;

	if (init_maxfreq_mode())
		return NULL;

	/* Free this at program termination */
	is_valid = calloc(cpu_count, sizeof(int));
	mperf_previous_count = calloc(cpu_count, sizeof(unsigned long long));
	aperf_previous_count = calloc(cpu_count, sizeof(unsigned long long));
	mperf_current_count = calloc(cpu_count, sizeof(unsigned long long));
	aperf_current_count = calloc(cpu_count, sizeof(unsigned long long));

	mperf_monitor.name_len = strlen(mperf_monitor.name);
	return &mperf_monitor;
}

void mperf_unregister(void)
{
	free(mperf_previous_count);
	free(aperf_previous_count);
	free(mperf_current_count);
	free(aperf_current_count);
	free(is_valid);
}

