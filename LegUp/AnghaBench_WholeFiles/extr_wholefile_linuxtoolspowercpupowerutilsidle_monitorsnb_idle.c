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
typedef  enum intel_snb_id { ____Placeholder_intel_snb_id } intel_snb_id ;
struct TYPE_4__ {scalar_t__ vendor; int family; int model; } ;
struct TYPE_3__ {int /*<<< orphan*/  name; } ;

/* Variables and functions */
#define  C7 131 
 int MSR_CORE_C7_RESIDENCY ; 
 int MSR_PKG_C2_RESIDENCY ; 
 int MSR_PKG_C7_RESIDENCY ; 
 int MSR_TSC ; 
#define  PC2 130 
#define  PC7 129 
 int SNB_CSTATE_COUNT ; 
#define  TSC 128 
 scalar_t__ X86_VENDOR_INTEL ; 
 unsigned int base_cpu ; 
 double* calloc (int,int) ; 
 int cpu_count ; 
 TYPE_2__ cpupower_cpu_info ; 
 double** current_count ; 
 int /*<<< orphan*/  dprint (char*,int /*<<< orphan*/ ,unsigned long long,double,double,...) ; 
 int /*<<< orphan*/  free (double*) ; 
 struct cpuidle_monitor intel_snb_monitor ; 
 double* is_valid ; 
 double** previous_count ; 
 scalar_t__ read_msr (unsigned int,int,unsigned long long*) ; 
 TYPE_1__* snb_cstates ; 
 int /*<<< orphan*/  strlen (int /*<<< orphan*/ ) ; 
 unsigned long long tsc_at_measure_end ; 
 unsigned long long tsc_at_measure_start ; 

__attribute__((used)) static int snb_get_count(enum intel_snb_id id, unsigned long long *val,
			unsigned int cpu)
{
	int msr;

	switch (id) {
	case C7:
		msr = MSR_CORE_C7_RESIDENCY;
		break;
	case PC2:
		msr = MSR_PKG_C2_RESIDENCY;
		break;
	case PC7:
		msr = MSR_PKG_C7_RESIDENCY;
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

__attribute__((used)) static int snb_get_count_percent(unsigned int id, double *percent,
				 unsigned int cpu)
{
	*percent = 0.0;

	if (!is_valid[cpu])
		return -1;

	*percent = (100.0 *
		(current_count[id][cpu] - previous_count[id][cpu])) /
		(tsc_at_measure_end - tsc_at_measure_start);

	dprint("%s: previous: %llu - current: %llu - (%u)\n",
		snb_cstates[id].name, previous_count[id][cpu],
		current_count[id][cpu], cpu);

	dprint("%s: tsc_diff: %llu - count_diff: %llu - percent: %2.f (%u)\n",
	       snb_cstates[id].name,
	       (unsigned long long) tsc_at_measure_end - tsc_at_measure_start,
	       current_count[id][cpu] - previous_count[id][cpu],
	       *percent, cpu);

	return 0;
}

__attribute__((used)) static int snb_start(void)
{
	int num, cpu;
	unsigned long long val;

	for (num = 0; num < SNB_CSTATE_COUNT; num++) {
		for (cpu = 0; cpu < cpu_count; cpu++) {
			snb_get_count(num, &val, cpu);
			previous_count[num][cpu] = val;
		}
	}
	snb_get_count(TSC, &tsc_at_measure_start, base_cpu);
	return 0;
}

__attribute__((used)) static int snb_stop(void)
{
	unsigned long long val;
	int num, cpu;

	snb_get_count(TSC, &tsc_at_measure_end, base_cpu);

	for (num = 0; num < SNB_CSTATE_COUNT; num++) {
		for (cpu = 0; cpu < cpu_count; cpu++) {
			is_valid[cpu] = !snb_get_count(num, &val, cpu);
			current_count[num][cpu] = val;
		}
	}
	return 0;
}

__attribute__((used)) static struct cpuidle_monitor *snb_register(void)
{
	int num;

	if (cpupower_cpu_info.vendor != X86_VENDOR_INTEL
	    || cpupower_cpu_info.family != 6)
		return NULL;

	switch (cpupower_cpu_info.model) {
	case 0x2A: /* SNB */
	case 0x2D: /* SNB Xeon */
	case 0x3A: /* IVB */
	case 0x3E: /* IVB Xeon */
	case 0x3C: /* HSW */
	case 0x3F: /* HSW */
	case 0x45: /* HSW */
	case 0x46: /* HSW */
		break;
	default:
		return NULL;
	}

	is_valid = calloc(cpu_count, sizeof(int));
	for (num = 0; num < SNB_CSTATE_COUNT; num++) {
		previous_count[num] = calloc(cpu_count,
					sizeof(unsigned long long));
		current_count[num]  = calloc(cpu_count,
					sizeof(unsigned long long));
	}
	intel_snb_monitor.name_len = strlen(intel_snb_monitor.name);
	return &intel_snb_monitor;
}

void snb_unregister(void)
{
	int num;
	free(is_valid);
	for (num = 0; num < SNB_CSTATE_COUNT; num++) {
		free(previous_count[num]);
		free(current_count[num]);
	}
}

