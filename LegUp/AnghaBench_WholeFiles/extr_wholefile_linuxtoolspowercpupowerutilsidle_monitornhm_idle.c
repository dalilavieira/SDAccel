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
typedef  enum intel_nhm_id { ____Placeholder_intel_nhm_id } intel_nhm_id ;
struct TYPE_4__ {scalar_t__ vendor; int caps; } ;
struct TYPE_3__ {int /*<<< orphan*/  name; } ;

/* Variables and functions */
#define  C3 132 
#define  C6 131 
 int CPUPOWER_CAP_APERF ; 
 int CPUPOWER_CAP_INV_TSC ; 
 int MSR_CORE_C3_RESIDENCY ; 
 int MSR_CORE_C6_RESIDENCY ; 
 int MSR_PKG_C3_RESIDENCY ; 
 int MSR_PKG_C6_RESIDENCY ; 
 int MSR_TSC ; 
 int NHM_CSTATE_COUNT ; 
#define  PC3 130 
#define  PC6 129 
#define  TSC 128 
 scalar_t__ X86_VENDOR_INTEL ; 
 unsigned int base_cpu ; 
 double* calloc (int,int) ; 
 int cpu_count ; 
 TYPE_2__ cpupower_cpu_info ; 
 double** current_count ; 
 int /*<<< orphan*/  dprint (char*,int,...) ; 
 int /*<<< orphan*/  free (double*) ; 
 struct cpuidle_monitor intel_nhm_monitor ; 
 double* is_valid ; 
 TYPE_1__* nhm_cstates ; 
 double** previous_count ; 
 scalar_t__ read_msr (unsigned int,int,unsigned long long*) ; 
 int /*<<< orphan*/  strlen (int /*<<< orphan*/ ) ; 
 unsigned long long tsc_at_measure_end ; 
 unsigned long long tsc_at_measure_start ; 

__attribute__((used)) static int nhm_get_count(enum intel_nhm_id id, unsigned long long *val,
			unsigned int cpu)
{
	int msr;

	switch (id) {
	case C3:
		msr = MSR_CORE_C3_RESIDENCY;
		break;
	case C6:
		msr = MSR_CORE_C6_RESIDENCY;
		break;
	case PC3:
		msr = MSR_PKG_C3_RESIDENCY;
		break;
	case PC6:
		msr = MSR_PKG_C6_RESIDENCY;
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

__attribute__((used)) static int nhm_get_count_percent(unsigned int id, double *percent,
				 unsigned int cpu)
{
	*percent = 0.0;

	if (!is_valid[cpu])
		return -1;

	*percent = (100.0 *
		(current_count[id][cpu] - previous_count[id][cpu])) /
		(tsc_at_measure_end - tsc_at_measure_start);

	dprint("%s: previous: %llu - current: %llu - (%u)\n",
		nhm_cstates[id].name, previous_count[id][cpu],
		current_count[id][cpu], cpu);

	dprint("%s: tsc_diff: %llu - count_diff: %llu - percent: %2.f (%u)\n",
	       nhm_cstates[id].name,
	       (unsigned long long) tsc_at_measure_end - tsc_at_measure_start,
	       current_count[id][cpu] - previous_count[id][cpu],
	       *percent, cpu);

	return 0;
}

__attribute__((used)) static int nhm_start(void)
{
	int num, cpu;
	unsigned long long dbg, val;

	nhm_get_count(TSC, &tsc_at_measure_start, base_cpu);

	for (num = 0; num < NHM_CSTATE_COUNT; num++) {
		for (cpu = 0; cpu < cpu_count; cpu++) {
			is_valid[cpu] = !nhm_get_count(num, &val, cpu);
			previous_count[num][cpu] = val;
		}
	}
	nhm_get_count(TSC, &dbg, base_cpu);
	dprint("TSC diff: %llu\n", dbg - tsc_at_measure_start);
	return 0;
}

__attribute__((used)) static int nhm_stop(void)
{
	unsigned long long val;
	unsigned long long dbg;
	int num, cpu;

	nhm_get_count(TSC, &tsc_at_measure_end, base_cpu);

	for (num = 0; num < NHM_CSTATE_COUNT; num++) {
		for (cpu = 0; cpu < cpu_count; cpu++) {
			is_valid[cpu] = !nhm_get_count(num, &val, cpu);
			current_count[num][cpu] = val;
		}
	}
	nhm_get_count(TSC, &dbg, base_cpu);
	dprint("TSC diff: %llu\n", dbg - tsc_at_measure_end);

	return 0;
}

struct cpuidle_monitor *intel_nhm_register(void)
{
	int num;

	if (cpupower_cpu_info.vendor != X86_VENDOR_INTEL)
		return NULL;

	if (!(cpupower_cpu_info.caps & CPUPOWER_CAP_INV_TSC))
		return NULL;

	if (!(cpupower_cpu_info.caps & CPUPOWER_CAP_APERF))
		return NULL;

	/* Free this at program termination */
	is_valid = calloc(cpu_count, sizeof(int));
	for (num = 0; num < NHM_CSTATE_COUNT; num++) {
		previous_count[num] = calloc(cpu_count,
					sizeof(unsigned long long));
		current_count[num]  = calloc(cpu_count,
					sizeof(unsigned long long));
	}

	intel_nhm_monitor.name_len = strlen(intel_nhm_monitor.name);
	return &intel_nhm_monitor;
}

void intel_nhm_unregister(void)
{
	int num;

	for (num = 0; num < NHM_CSTATE_COUNT; num++) {
		free(previous_count[num]);
		free(current_count[num]);
	}
	free(is_valid);
}

