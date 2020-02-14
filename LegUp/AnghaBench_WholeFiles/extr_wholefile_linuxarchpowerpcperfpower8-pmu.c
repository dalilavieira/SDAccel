#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int u64 ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int PERF_SAMPLE_BRANCH_ANY ; 
 int PERF_SAMPLE_BRANCH_ANY_CALL ; 
 int PERF_SAMPLE_BRANCH_ANY_RETURN ; 
 int PERF_SAMPLE_BRANCH_CALL ; 
 int PERF_SAMPLE_BRANCH_IND_CALL ; 
 int POWER8_MMCRA_IFM1 ; 
 int /*<<< orphan*/  SPRN_MMCRA ; 
 int /*<<< orphan*/  event_alternatives ; 
 int isa207_get_alternatives (int,int*,int /*<<< orphan*/ ,unsigned int,int /*<<< orphan*/ ) ; 
 int mfspr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mtspr (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int power8_get_alternatives(u64 event, unsigned int flags, u64 alt[])
{
	int num_alt = 0;

	num_alt = isa207_get_alternatives(event, alt,
					  ARRAY_SIZE(event_alternatives), flags,
					  event_alternatives);

	return num_alt;
}

__attribute__((used)) static u64 power8_bhrb_filter_map(u64 branch_sample_type)
{
	u64 pmu_bhrb_filter = 0;

	/* BHRB and regular PMU events share the same privilege state
	 * filter configuration. BHRB is always recorded along with a
	 * regular PMU event. As the privilege state filter is handled
	 * in the basic PMC configuration of the accompanying regular
	 * PMU event, we ignore any separate BHRB specific request.
	 */

	/* No branch filter requested */
	if (branch_sample_type & PERF_SAMPLE_BRANCH_ANY)
		return pmu_bhrb_filter;

	/* Invalid branch filter options - HW does not support */
	if (branch_sample_type & PERF_SAMPLE_BRANCH_ANY_RETURN)
		return -1;

	if (branch_sample_type & PERF_SAMPLE_BRANCH_IND_CALL)
		return -1;

	if (branch_sample_type & PERF_SAMPLE_BRANCH_CALL)
		return -1;

	if (branch_sample_type & PERF_SAMPLE_BRANCH_ANY_CALL) {
		pmu_bhrb_filter |= POWER8_MMCRA_IFM1;
		return pmu_bhrb_filter;
	}

	/* Every thing else is unsupported */
	return -1;
}

__attribute__((used)) static void power8_config_bhrb(u64 pmu_bhrb_filter)
{
	/* Enable BHRB filter in PMU */
	mtspr(SPRN_MMCRA, (mfspr(SPRN_MMCRA) | pmu_bhrb_filter));
}

