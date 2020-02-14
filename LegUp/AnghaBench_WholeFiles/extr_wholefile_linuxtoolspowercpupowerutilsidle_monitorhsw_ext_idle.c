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
typedef  enum intel_hsw_ext_id { ____Placeholder_intel_hsw_ext_id } intel_hsw_ext_id ;
struct TYPE_4__ {scalar_t__ vendor; int family; int model; } ;
struct TYPE_3__ {int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int HSW_EXT_CSTATE_COUNT ; 
 int MSR_PKG_C10_RESIDENCY ; 
 int MSR_PKG_C8_RESIDENCY ; 
 int MSR_PKG_C9_RESIDENCY ; 
 int MSR_TSC ; 
#define  PC10 131 
#define  PC8 130 
#define  PC9 129 
#define  TSC 128 
 scalar_t__ X86_VENDOR_INTEL ; 
 unsigned int base_cpu ; 
 double* calloc (int,int) ; 
 int cpu_count ; 
 TYPE_2__ cpupower_cpu_info ; 
 double** current_count ; 
 int /*<<< orphan*/  dprint (char*,int /*<<< orphan*/ ,unsigned long long,double,double,...) ; 
 int /*<<< orphan*/  free (double*) ; 
 TYPE_1__* hsw_ext_cstates ; 
 struct cpuidle_monitor intel_hsw_ext_monitor ; 
 double* is_valid ; 
 double** previous_count ; 
 scalar_t__ read_msr (unsigned int,int,unsigned long long*) ; 
 int /*<<< orphan*/  strlen (int /*<<< orphan*/ ) ; 
 unsigned long long tsc_at_measure_end ; 
 unsigned long long tsc_at_measure_start ; 

__attribute__((used)) static int hsw_ext_get_count(enum intel_hsw_ext_id id, unsigned long long *val,
			unsigned int cpu)
{
	int msr;

	switch (id) {
	case PC8:
		msr = MSR_PKG_C8_RESIDENCY;
		break;
	case PC9:
		msr = MSR_PKG_C9_RESIDENCY;
		break;
	case PC10:
		msr = MSR_PKG_C10_RESIDENCY;
		break;
	case TSC:
		msr = MSR_TSC;
		break;
	default:
		return -1;
	};
	if (read_msr(cpu, msr, val))
		return -1;
	return 0;
}

__attribute__((used)) static int hsw_ext_get_count_percent(unsigned int id, double *percent,
				 unsigned int cpu)
{
	*percent = 0.0;

	if (!is_valid[cpu])
		return -1;

	*percent = (100.0 *
		(current_count[id][cpu] - previous_count[id][cpu])) /
		(tsc_at_measure_end - tsc_at_measure_start);

	dprint("%s: previous: %llu - current: %llu - (%u)\n",
		hsw_ext_cstates[id].name, previous_count[id][cpu],
		current_count[id][cpu], cpu);

	dprint("%s: tsc_diff: %llu - count_diff: %llu - percent: %2.f (%u)\n",
	       hsw_ext_cstates[id].name,
	       (unsigned long long) tsc_at_measure_end - tsc_at_measure_start,
	       current_count[id][cpu] - previous_count[id][cpu],
	       *percent, cpu);

	return 0;
}

__attribute__((used)) static int hsw_ext_start(void)
{
	int num, cpu;
	unsigned long long val;

	for (num = 0; num < HSW_EXT_CSTATE_COUNT; num++) {
		for (cpu = 0; cpu < cpu_count; cpu++) {
			hsw_ext_get_count(num, &val, cpu);
			previous_count[num][cpu] = val;
		}
	}
	hsw_ext_get_count(TSC, &tsc_at_measure_start, base_cpu);
	return 0;
}

__attribute__((used)) static int hsw_ext_stop(void)
{
	unsigned long long val;
	int num, cpu;

	hsw_ext_get_count(TSC, &tsc_at_measure_end, base_cpu);

	for (num = 0; num < HSW_EXT_CSTATE_COUNT; num++) {
		for (cpu = 0; cpu < cpu_count; cpu++) {
			is_valid[cpu] = !hsw_ext_get_count(num, &val, cpu);
			current_count[num][cpu] = val;
		}
	}
	return 0;
}

__attribute__((used)) static struct cpuidle_monitor *hsw_ext_register(void)
{
	int num;

	if (cpupower_cpu_info.vendor != X86_VENDOR_INTEL
	    || cpupower_cpu_info.family != 6)
		return NULL;

	switch (cpupower_cpu_info.model) {
	case 0x45: /* HSW */
		break;
	default:
		return NULL;
	}

	is_valid = calloc(cpu_count, sizeof(int));
	for (num = 0; num < HSW_EXT_CSTATE_COUNT; num++) {
		previous_count[num] = calloc(cpu_count,
					sizeof(unsigned long long));
		current_count[num]  = calloc(cpu_count,
					sizeof(unsigned long long));
	}
	intel_hsw_ext_monitor.name_len = strlen(intel_hsw_ext_monitor.name);
	return &intel_hsw_ext_monitor;
}

void hsw_ext_unregister(void)
{
	int num;
	free(is_valid);
	for (num = 0; num < HSW_EXT_CSTATE_COUNT; num++) {
		free(previous_count[num]);
		free(current_count[num]);
	}
}

