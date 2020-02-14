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
typedef  scalar_t__ uint64_t ;
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  i386_intr_func_t ;
typedef  int /*<<< orphan*/  TSC_deadline_timer ;

/* Variables and functions */
 int CPUID_FEATURE_TSCTMR ; 
 int DBG_FUNC_NONE ; 
 int DECR_SET_APIC_DEADLINE ; 
 int DECR_SET_TSC_DEADLINE ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  KERNEL_DEBUG_CONSTANT (int,scalar_t__,scalar_t__,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LAPIC_READ (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MAX (scalar_t__,scalar_t__) ; 
 scalar_t__ MIN (int /*<<< orphan*/ ,scalar_t__) ; 
 int NSEC_PER_USEC ; 
 int /*<<< orphan*/  PE_parse_boot_argn (char*,int*,int) ; 
 int /*<<< orphan*/  TIMER_CURRENT_COUNT ; 
 int /*<<< orphan*/  TRUE ; 
 scalar_t__ UINT64_MAX ; 
 int /*<<< orphan*/  busFCvtn2t ; 
 int /*<<< orphan*/  busFCvtt2n ; 
 int cpuid_features () ; 
 int /*<<< orphan*/  divide_by_1 ; 
 int /*<<< orphan*/  kprintf (char*,scalar_t__) ; 
 int /*<<< orphan*/  lapic_config_timer (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lapic_config_tsc_deadline_timer () ; 
 int /*<<< orphan*/  lapic_get_tsc_deadline_timer () ; 
 int /*<<< orphan*/  lapic_set_timer (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lapic_set_timer_fast (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lapic_set_timer_func (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lapic_set_tsc_deadline_timer (scalar_t__) ; 
 int /*<<< orphan*/  one_shot ; 
 int /*<<< orphan*/  printf (char*,char*) ; 
 scalar_t__ rdtsc64 () ; 
 scalar_t__ rtc_decrementer_max ; 
 scalar_t__ rtc_decrementer_min ; 
 int /*<<< orphan*/ * rtc_timer ; 
 int /*<<< orphan*/  rtc_timer_tsc_deadline ; 
 scalar_t__ rtclock_intr ; 
 scalar_t__ tmrCvt (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  tscFCvtn2t ; 

__attribute__((used)) static uint64_t
deadline_to_decrementer(
	uint64_t	deadline,
	uint64_t	now)
{
	uint64_t	delta;

	if (deadline <= now)
		return rtc_decrementer_min;
	else {
		delta = deadline - now;
		return MIN(MAX(rtc_decrementer_min,delta),rtc_decrementer_max); 
	}
}

__attribute__((used)) static void
rtc_lapic_config_timer(void)
{
	lapic_config_timer(TRUE, one_shot, divide_by_1);
}

__attribute__((used)) static uint64_t
rtc_lapic_set_timer(uint64_t deadline, uint64_t now)
{
	uint64_t count;
	uint64_t set = 0;

	if (deadline > 0) {
		/*
		 * Convert delta to bus ticks
		 * - time now is not relevant
		 */
		count = deadline_to_decrementer(deadline, now);
		set = now + count;
		lapic_set_timer_fast((uint32_t) tmrCvt(count, busFCvtn2t));
	} else {
		lapic_set_timer(FALSE, one_shot, divide_by_1, 0);
	}

	KERNEL_DEBUG_CONSTANT(
		DECR_SET_APIC_DEADLINE | DBG_FUNC_NONE,
		now, deadline,
		set, LAPIC_READ(TIMER_CURRENT_COUNT),
		0);

	return set;
}

__attribute__((used)) static void
rtc_lapic_config_tsc_deadline_timer(void)
{
	lapic_config_tsc_deadline_timer();
}

__attribute__((used)) static uint64_t
rtc_lapic_set_tsc_deadline_timer(uint64_t deadline, uint64_t now)
{
	uint64_t delta;
	uint64_t delta_tsc;
	uint64_t tsc = rdtsc64();
	uint64_t set = 0;

	if (deadline > 0) {
		/*
		 * Convert to TSC
		 */
		delta = deadline_to_decrementer(deadline, now);
		set = now + delta;
		delta_tsc = tmrCvt(delta, tscFCvtn2t);
		lapic_set_tsc_deadline_timer(tsc + delta_tsc);
	} else {
		lapic_set_tsc_deadline_timer(0);
	}
	
	KERNEL_DEBUG_CONSTANT(
		DECR_SET_TSC_DEADLINE | DBG_FUNC_NONE,
		now, deadline,
		tsc, lapic_get_tsc_deadline_timer(),
		0);

	return set;
}

void
rtc_timer_init(void)
{
	int	TSC_deadline_timer = 0;

	/* See whether we can use the local apic in TSC-deadline mode */
	if ((cpuid_features() & CPUID_FEATURE_TSCTMR)) {
		TSC_deadline_timer = 1;
		PE_parse_boot_argn("TSC_deadline_timer", &TSC_deadline_timer,
				   sizeof(TSC_deadline_timer));
		printf("TSC Deadline Timer supported %s enabled\n",
			TSC_deadline_timer ? "and" : "but not");
	}

	if (TSC_deadline_timer) {
		rtc_timer = &rtc_timer_tsc_deadline;
		rtc_decrementer_max = UINT64_MAX;	/* effectively none */
		/*
		 * The min could be as low as 1nsec,
		 * but we're being conservative for now and making it the same
		 * as for the local apic timer.
		 */
		rtc_decrementer_min = 1*NSEC_PER_USEC;	/* 1 usec */
	} else {
		/*
		 * Compute the longest interval using LAPIC timer.
		 */
		rtc_decrementer_max = tmrCvt(0x7fffffffULL, busFCvtt2n);
		kprintf("maxDec: %lld\n", rtc_decrementer_max);
		rtc_decrementer_min = 1*NSEC_PER_USEC;	/* 1 usec */
	}

	/* Point LAPIC interrupts to hardclock() */
	lapic_set_timer_func((i386_intr_func_t) rtclock_intr);
}

