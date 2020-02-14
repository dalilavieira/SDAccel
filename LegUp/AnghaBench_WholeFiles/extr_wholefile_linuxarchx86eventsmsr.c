#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  size_t u64 ;
struct TYPE_8__ {int idx; scalar_t__ event_base; size_t config; int /*<<< orphan*/  prev_count; } ;
struct TYPE_7__ {size_t config; scalar_t__ type; scalar_t__ sample_period; scalar_t__ exclude_guest; scalar_t__ exclude_host; scalar_t__ exclude_idle; scalar_t__ exclude_hv; scalar_t__ exclude_kernel; scalar_t__ exclude_user; } ;
struct perf_event {TYPE_3__ hw; int /*<<< orphan*/  count; TYPE_2__ attr; TYPE_1__* pmu; } ;
typedef  size_t s64 ;
struct TYPE_10__ {scalar_t__ x86_vendor; int x86; int x86_model; } ;
struct TYPE_9__ {scalar_t__ msr; int /*<<< orphan*/  attr; } ;
struct TYPE_6__ {scalar_t__ type; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOENT ; 
#define  INTEL_FAM6_ATOM_AIRMONT 159 
#define  INTEL_FAM6_ATOM_DENVERTON 158 
#define  INTEL_FAM6_ATOM_GEMINI_LAKE 157 
#define  INTEL_FAM6_ATOM_GOLDMONT 156 
#define  INTEL_FAM6_ATOM_SILVERMONT1 155 
#define  INTEL_FAM6_ATOM_SILVERMONT2 154 
#define  INTEL_FAM6_BROADWELL_CORE 153 
#define  INTEL_FAM6_BROADWELL_GT3E 152 
#define  INTEL_FAM6_BROADWELL_X 151 
#define  INTEL_FAM6_BROADWELL_XEON_D 150 
#define  INTEL_FAM6_HASWELL_CORE 149 
#define  INTEL_FAM6_HASWELL_GT3E 148 
#define  INTEL_FAM6_HASWELL_ULT 147 
#define  INTEL_FAM6_HASWELL_X 146 
#define  INTEL_FAM6_IVYBRIDGE 145 
#define  INTEL_FAM6_IVYBRIDGE_X 144 
#define  INTEL_FAM6_KABYLAKE_DESKTOP 143 
#define  INTEL_FAM6_KABYLAKE_MOBILE 142 
#define  INTEL_FAM6_NEHALEM 141 
#define  INTEL_FAM6_NEHALEM_EP 140 
#define  INTEL_FAM6_NEHALEM_EX 139 
#define  INTEL_FAM6_NEHALEM_G 138 
#define  INTEL_FAM6_SANDYBRIDGE 137 
#define  INTEL_FAM6_SANDYBRIDGE_X 136 
#define  INTEL_FAM6_SKYLAKE_DESKTOP 135 
#define  INTEL_FAM6_SKYLAKE_MOBILE 134 
#define  INTEL_FAM6_SKYLAKE_X 133 
#define  INTEL_FAM6_WESTMERE 132 
#define  INTEL_FAM6_WESTMERE_EP 131 
#define  INTEL_FAM6_WESTMERE_EX 130 
#define  INTEL_FAM6_XEON_PHI_KNL 129 
#define  INTEL_FAM6_XEON_PHI_KNM 128 
 scalar_t__ MSR_IA32_THERM_STATUS ; 
 scalar_t__ MSR_SMI_COUNT ; 
 int PERF_EF_START ; 
 int PERF_EF_UPDATE ; 
 size_t PERF_MSR_EVENT_MAX ; 
 int PERF_MSR_PPERF ; 
 int PERF_MSR_SMI ; 
 int /*<<< orphan*/  X86_FEATURE_APERFMPERF ; 
 int /*<<< orphan*/  X86_FEATURE_DTHERM ; 
 int /*<<< orphan*/  X86_FEATURE_IRPERF ; 
 int /*<<< orphan*/  X86_FEATURE_PTSC ; 
 scalar_t__ X86_VENDOR_INTEL ; 
 size_t array_index_nospec (unsigned long,size_t) ; 
 TYPE_5__ boot_cpu_data ; 
 int boot_cpu_has (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  local64_add (size_t,int /*<<< orphan*/ *) ; 
 size_t local64_cmpxchg (int /*<<< orphan*/ *,size_t,size_t) ; 
 size_t local64_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  local64_set (int /*<<< orphan*/ *,size_t) ; 
 TYPE_4__* msr ; 
 int /*<<< orphan*/  rdmsrl (scalar_t__,size_t) ; 
 size_t rdtsc_ordered () ; 
 size_t sign_extend64 (size_t,int) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static bool test_aperfmperf(int idx)
{
	return boot_cpu_has(X86_FEATURE_APERFMPERF);
}

__attribute__((used)) static bool test_ptsc(int idx)
{
	return boot_cpu_has(X86_FEATURE_PTSC);
}

__attribute__((used)) static bool test_irperf(int idx)
{
	return boot_cpu_has(X86_FEATURE_IRPERF);
}

__attribute__((used)) static bool test_therm_status(int idx)
{
	return boot_cpu_has(X86_FEATURE_DTHERM);
}

__attribute__((used)) static bool test_intel(int idx)
{
	if (boot_cpu_data.x86_vendor != X86_VENDOR_INTEL ||
	    boot_cpu_data.x86 != 6)
		return false;

	switch (boot_cpu_data.x86_model) {
	case INTEL_FAM6_NEHALEM:
	case INTEL_FAM6_NEHALEM_G:
	case INTEL_FAM6_NEHALEM_EP:
	case INTEL_FAM6_NEHALEM_EX:

	case INTEL_FAM6_WESTMERE:
	case INTEL_FAM6_WESTMERE_EP:
	case INTEL_FAM6_WESTMERE_EX:

	case INTEL_FAM6_SANDYBRIDGE:
	case INTEL_FAM6_SANDYBRIDGE_X:

	case INTEL_FAM6_IVYBRIDGE:
	case INTEL_FAM6_IVYBRIDGE_X:

	case INTEL_FAM6_HASWELL_CORE:
	case INTEL_FAM6_HASWELL_X:
	case INTEL_FAM6_HASWELL_ULT:
	case INTEL_FAM6_HASWELL_GT3E:

	case INTEL_FAM6_BROADWELL_CORE:
	case INTEL_FAM6_BROADWELL_XEON_D:
	case INTEL_FAM6_BROADWELL_GT3E:
	case INTEL_FAM6_BROADWELL_X:

	case INTEL_FAM6_ATOM_SILVERMONT1:
	case INTEL_FAM6_ATOM_SILVERMONT2:
	case INTEL_FAM6_ATOM_AIRMONT:

	case INTEL_FAM6_ATOM_GOLDMONT:
	case INTEL_FAM6_ATOM_DENVERTON:

	case INTEL_FAM6_ATOM_GEMINI_LAKE:

	case INTEL_FAM6_XEON_PHI_KNL:
	case INTEL_FAM6_XEON_PHI_KNM:
		if (idx == PERF_MSR_SMI)
			return true;
		break;

	case INTEL_FAM6_SKYLAKE_MOBILE:
	case INTEL_FAM6_SKYLAKE_DESKTOP:
	case INTEL_FAM6_SKYLAKE_X:
	case INTEL_FAM6_KABYLAKE_MOBILE:
	case INTEL_FAM6_KABYLAKE_DESKTOP:
		if (idx == PERF_MSR_SMI || idx == PERF_MSR_PPERF)
			return true;
		break;
	}

	return false;
}

__attribute__((used)) static int msr_event_init(struct perf_event *event)
{
	u64 cfg = event->attr.config;

	if (event->attr.type != event->pmu->type)
		return -ENOENT;

	/* unsupported modes and filters */
	if (event->attr.exclude_user   ||
	    event->attr.exclude_kernel ||
	    event->attr.exclude_hv     ||
	    event->attr.exclude_idle   ||
	    event->attr.exclude_host   ||
	    event->attr.exclude_guest  ||
	    event->attr.sample_period) /* no sampling */
		return -EINVAL;

	if (cfg >= PERF_MSR_EVENT_MAX)
		return -EINVAL;

	cfg = array_index_nospec((unsigned long)cfg, PERF_MSR_EVENT_MAX);

	if (!msr[cfg].attr)
		return -EINVAL;

	event->hw.idx		= -1;
	event->hw.event_base	= msr[cfg].msr;
	event->hw.config	= cfg;

	return 0;
}

__attribute__((used)) static inline u64 msr_read_counter(struct perf_event *event)
{
	u64 now;

	if (event->hw.event_base)
		rdmsrl(event->hw.event_base, now);
	else
		now = rdtsc_ordered();

	return now;
}

__attribute__((used)) static void msr_event_update(struct perf_event *event)
{
	u64 prev, now;
	s64 delta;

	/* Careful, an NMI might modify the previous event value: */
again:
	prev = local64_read(&event->hw.prev_count);
	now = msr_read_counter(event);

	if (local64_cmpxchg(&event->hw.prev_count, prev, now) != prev)
		goto again;

	delta = now - prev;
	if (unlikely(event->hw.event_base == MSR_SMI_COUNT)) {
		delta = sign_extend64(delta, 31);
		local64_add(delta, &event->count);
	} else if (unlikely(event->hw.event_base == MSR_IA32_THERM_STATUS)) {
		/* If valid, extract digital readout, otherwise set to -1: */
		now = now & (1ULL << 31) ? (now >> 16) & 0x3f :  -1;
		local64_set(&event->count, now);
	} else {
		local64_add(delta, &event->count);
	}
}

__attribute__((used)) static void msr_event_start(struct perf_event *event, int flags)
{
	u64 now = msr_read_counter(event);

	local64_set(&event->hw.prev_count, now);
}

__attribute__((used)) static void msr_event_stop(struct perf_event *event, int flags)
{
	msr_event_update(event);
}

__attribute__((used)) static void msr_event_del(struct perf_event *event, int flags)
{
	msr_event_stop(event, PERF_EF_UPDATE);
}

__attribute__((used)) static int msr_event_add(struct perf_event *event, int flags)
{
	if (flags & PERF_EF_START)
		msr_event_start(event, flags);

	return 0;
}

