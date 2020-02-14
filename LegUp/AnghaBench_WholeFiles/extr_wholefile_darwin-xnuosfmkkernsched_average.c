#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  size_t uint64_t ;
typedef  size_t uint32_t ;
typedef  TYPE_1__* sched_average_t ;
struct TYPE_3__ {size_t deadline; size_t period; int /*<<< orphan*/  param; int /*<<< orphan*/  (* comp ) (int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int DBG_FUNC_NONE ; 
 int /*<<< orphan*/  DBG_MACH_SCHED ; 
 int /*<<< orphan*/  KDEBUG_TRACE ; 
 int /*<<< orphan*/  KERNEL_DEBUG_CONSTANT_IST (int /*<<< orphan*/ ,int,size_t,size_t,size_t,size_t,int /*<<< orphan*/ ) ; 
 size_t LOAD_SCALE ; 
 int MACHDBG_CODE (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MACH_SCHED_LOAD ; 
 int /*<<< orphan*/  MACH_SCHED_LOAD_EFFECTIVE ; 
 size_t MAX_LOAD ; 
 size_t MIN (size_t,int /*<<< orphan*/ ) ; 
 size_t SCHED_LOAD_EWMA_ALPHA_NEW ; 
 size_t SCHED_LOAD_EWMA_ALPHA_OLD ; 
 size_t SCHED_LOAD_EWMA_ALPHA_SHIFT ; 
 size_t SCHED_LOAD_EWMA_UNSCALE (size_t) ; 
 int /*<<< orphan*/  SCHED_TICK_MAX_DELTA ; 
 size_t TH_BUCKET_FIXPRI ; 
 int TH_BUCKET_MAX ; 
 size_t TH_BUCKET_RUN ; 
 size_t TH_BUCKET_SHARE_BG ; 
 size_t TH_BUCKET_SHARE_DF ; 
 size_t TH_BUCKET_SHARE_FG ; 
 size_t TH_BUCKET_SHARE_UT ; 
 int /*<<< orphan*/  assert (int) ; 
 size_t* avenrun ; 
 size_t* fract ; 
 size_t mach_absolute_time () ; 
 size_t* mach_factor ; 
 size_t processor_avail_count ; 
 TYPE_1__* sched_average ; 
 scalar_t__ sched_fixed_shift ; 
 size_t* sched_load ; 
 int sched_load_average ; 
 scalar_t__* sched_load_shifts ; 
 int sched_mach_factor ; 
 size_t sched_nrun ; 
 size_t sched_one_second_interval ; 
 scalar_t__* sched_pri_shifts ; 
 size_t* sched_run_buckets ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ) ; 

void
compute_sched_load(void)
{
	/*
	 * Retrieve a snapshot of the current run counts.
	 *
	 * Why not a bcopy()? Because we need atomic word-sized reads of sched_run_buckets,
	 * not byte-by-byte copy.
	 */
	uint32_t ncpus = processor_avail_count;
	uint32_t load_now[TH_BUCKET_MAX];

	load_now[TH_BUCKET_RUN]      = sched_run_buckets[TH_BUCKET_RUN];
	load_now[TH_BUCKET_FIXPRI]   = sched_run_buckets[TH_BUCKET_FIXPRI];
	load_now[TH_BUCKET_SHARE_FG] = sched_run_buckets[TH_BUCKET_SHARE_FG];
	load_now[TH_BUCKET_SHARE_DF] = sched_run_buckets[TH_BUCKET_SHARE_DF];
	load_now[TH_BUCKET_SHARE_UT] = sched_run_buckets[TH_BUCKET_SHARE_UT];
	load_now[TH_BUCKET_SHARE_BG] = sched_run_buckets[TH_BUCKET_SHARE_BG];

	assert(load_now[TH_BUCKET_RUN] >= 0);
	assert(load_now[TH_BUCKET_FIXPRI] >= 0);

	uint32_t nthreads = load_now[TH_BUCKET_RUN];
	uint32_t nfixpri  = load_now[TH_BUCKET_FIXPRI];

	KERNEL_DEBUG_CONSTANT_IST(KDEBUG_TRACE,
	        MACHDBG_CODE(DBG_MACH_SCHED, MACH_SCHED_LOAD) | DBG_FUNC_NONE,
	        load_now[TH_BUCKET_FIXPRI], (load_now[TH_BUCKET_SHARE_FG] + load_now[TH_BUCKET_SHARE_DF]),
	        load_now[TH_BUCKET_SHARE_BG],   load_now[TH_BUCKET_SHARE_UT], 0);

	/*
	 * Compute the timeshare priority conversion factor based on loading.
	 * Because our counters may be incremented and accessed
	 * concurrently with respect to each other, we may have
	 * windows where the invariant (nthreads - nfixpri) == (fg + df + bg + ut)
	 * is broken, so truncate values in these cases.
	 */
	uint32_t timeshare_threads = (nthreads - nfixpri);
	for (uint32_t i = TH_BUCKET_SHARE_FG; i <= TH_BUCKET_SHARE_BG ; i++) {
		if (load_now[i] > timeshare_threads)
			load_now[i] = timeshare_threads;
	}

	/* 
	 * Default threads contribute up to (NCPUS * 2) of load to FG threads 
	 */
	if (load_now[TH_BUCKET_SHARE_DF] <= (ncpus * 2)) {
		load_now[TH_BUCKET_SHARE_FG] += load_now[TH_BUCKET_SHARE_DF];
	} else {
		load_now[TH_BUCKET_SHARE_FG] += (ncpus * 2);
	}
	
	/*
	 * Utility threads contribute up to NCPUS of load to FG & DF threads
	 */
	if (load_now[TH_BUCKET_SHARE_UT] <= ncpus) {
		load_now[TH_BUCKET_SHARE_FG] += load_now[TH_BUCKET_SHARE_UT];
		load_now[TH_BUCKET_SHARE_DF] += load_now[TH_BUCKET_SHARE_UT];
	} else {
		load_now[TH_BUCKET_SHARE_FG] += ncpus;
		load_now[TH_BUCKET_SHARE_DF] += ncpus;
	}

	/*
	 * BG threads contribute up to 1 thread worth of load to FG, DF and UT threads
	 */
	if (load_now[TH_BUCKET_SHARE_BG] > 0) {
		load_now[TH_BUCKET_SHARE_FG] += 1;
		load_now[TH_BUCKET_SHARE_DF] += 1;
		load_now[TH_BUCKET_SHARE_UT] += 1;
	}

	/*
	 * The conversion factor consists of two components:
	 * a fixed value based on the absolute time unit (sched_fixed_shift),
	 * and a dynamic portion based on load (sched_load_shifts).
	 *
	 * Zero load results in a out of range shift count.
	 */

	for (uint32_t i = TH_BUCKET_SHARE_FG; i <= TH_BUCKET_SHARE_BG ; i++) {
		uint32_t bucket_load = 0;

		if (load_now[i] > ncpus) {
			/* Normalize the load to number of CPUs */
			if (ncpus > 1)
				bucket_load = load_now[i] / ncpus;
			else
				bucket_load = load_now[i];

			if (bucket_load > MAX_LOAD)
				bucket_load = MAX_LOAD;
		}
		/* Plug the load values into the EWMA algorithm to calculate (scaled for fixpoint) sched_load */
		sched_load[i] = (sched_load[i] * SCHED_LOAD_EWMA_ALPHA_OLD) + ((bucket_load << SCHED_LOAD_EWMA_ALPHA_SHIFT) * SCHED_LOAD_EWMA_ALPHA_NEW);
		sched_load[i] = sched_load[i] >> SCHED_LOAD_EWMA_ALPHA_SHIFT;
	}

	KERNEL_DEBUG_CONSTANT_IST(KDEBUG_TRACE,
	        MACHDBG_CODE(DBG_MACH_SCHED, MACH_SCHED_LOAD_EFFECTIVE) | DBG_FUNC_NONE, 
			SCHED_LOAD_EWMA_UNSCALE(sched_load[TH_BUCKET_SHARE_FG]), SCHED_LOAD_EWMA_UNSCALE(sched_load[TH_BUCKET_SHARE_DF]),
			SCHED_LOAD_EWMA_UNSCALE(sched_load[TH_BUCKET_SHARE_UT]), SCHED_LOAD_EWMA_UNSCALE(sched_load[TH_BUCKET_SHARE_BG]), 0);
}

void
compute_averages(uint64_t stdelta)
{
	
	uint32_t nthreads = sched_run_buckets[TH_BUCKET_RUN] - 1;
	uint32_t ncpus = processor_avail_count;
	
	/* Update the global pri_shifts based on the latest values */
	for (uint32_t i = TH_BUCKET_SHARE_FG; i <= TH_BUCKET_SHARE_BG ; i++) {
		uint32_t bucket_load = SCHED_LOAD_EWMA_UNSCALE(sched_load[i]);
		sched_pri_shifts[i] = sched_fixed_shift - sched_load_shifts[bucket_load];
	}

	/*
	 * Sample total running threads for the load average calculation.
	 */
	sched_nrun = nthreads;

	/*
	 * Load average and mach factor calculations for
	 * those which ask about these things.
	 */
	uint32_t average_now = nthreads * LOAD_SCALE;
	uint32_t factor_now;

	if (nthreads > ncpus)
		factor_now = (ncpus * LOAD_SCALE) / (nthreads + 1);
	else
		factor_now = (ncpus - nthreads) * LOAD_SCALE;

	/*
	 * For those statistics that formerly relied on being recomputed
	 * on timer ticks, advance by the approximate number of corresponding
	 * elapsed intervals, thus compensating for potential idle intervals.
	 */
	for (uint32_t index = 0; index < stdelta; index++) {
		sched_mach_factor = ((sched_mach_factor << 2) + factor_now) / 5;
		sched_load_average = ((sched_load_average << 2) + average_now) / 5;
	}

	/*
	 * Compute old-style Mach load averages.
	 */
	for (uint32_t index = 0; index < stdelta; index++) {
		for (uint32_t i = 0; i < 3; i++) {
			mach_factor[i] = ((mach_factor[i] * fract[i]) +
						(factor_now * (LOAD_SCALE - fract[i]))) / LOAD_SCALE;

			avenrun[i] = ((avenrun[i] * fract[i]) +
						(average_now * (LOAD_SCALE - fract[i]))) / LOAD_SCALE;
		}
	}

	/*
	 * Compute averages in other components.
	 */
	uint64_t abstime = mach_absolute_time();

	for (sched_average_t avg = sched_average; avg->comp != NULL; ++avg) {
		if (abstime >= avg->deadline) {
			uint64_t period_abs = (avg->period * sched_one_second_interval);
			uint64_t ninvokes = 1;

			ninvokes += (abstime - avg->deadline) / period_abs;
			ninvokes = MIN(ninvokes, SCHED_TICK_MAX_DELTA);

			for (uint32_t index = 0; index < ninvokes; index++) {
				(*avg->comp)(avg->param);
			}
			avg->deadline = abstime + period_abs;
		}
	}
}

