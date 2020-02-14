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
struct timecounter {int cycle_last; int nsec; unsigned long long mask; int frac; struct cyclecounter const* cc; } ;
typedef  struct cyclecounter {int (* read ) (struct cyclecounter const*) ;unsigned long long shift; int mask; int mult; } const cyclecounter ;

/* Variables and functions */
 int cyclecounter_cyc2ns (struct cyclecounter const*,int,unsigned long long,int*) ; 
 int stub1 (struct cyclecounter const*) ; 
 int stub2 (struct cyclecounter const*) ; 

void timecounter_init(struct timecounter *tc,
		      const struct cyclecounter *cc,
		      u64 start_tstamp)
{
	tc->cc = cc;
	tc->cycle_last = cc->read(cc);
	tc->nsec = start_tstamp;
	tc->mask = (1ULL << cc->shift) - 1;
	tc->frac = 0;
}

__attribute__((used)) static u64 timecounter_read_delta(struct timecounter *tc)
{
	u64 cycle_now, cycle_delta;
	u64 ns_offset;

	/* read cycle counter: */
	cycle_now = tc->cc->read(tc->cc);

	/* calculate the delta since the last timecounter_read_delta(): */
	cycle_delta = (cycle_now - tc->cycle_last) & tc->cc->mask;

	/* convert to nanoseconds: */
	ns_offset = cyclecounter_cyc2ns(tc->cc, cycle_delta,
					tc->mask, &tc->frac);

	/* update time stamp of timecounter_read_delta() call: */
	tc->cycle_last = cycle_now;

	return ns_offset;
}

u64 timecounter_read(struct timecounter *tc)
{
	u64 nsec;

	/* increment time by nanoseconds since last call */
	nsec = timecounter_read_delta(tc);
	nsec += tc->nsec;
	tc->nsec = nsec;

	return nsec;
}

__attribute__((used)) static u64 cc_cyc2ns_backwards(const struct cyclecounter *cc,
			       u64 cycles, u64 mask, u64 frac)
{
	u64 ns = (u64) cycles;

	ns = ((ns * cc->mult) - frac) >> cc->shift;

	return ns;
}

u64 timecounter_cyc2time(struct timecounter *tc,
			 u64 cycle_tstamp)
{
	u64 delta = (cycle_tstamp - tc->cycle_last) & tc->cc->mask;
	u64 nsec = tc->nsec, frac = tc->frac;

	/*
	 * Instead of always treating cycle_tstamp as more recent
	 * than tc->cycle_last, detect when it is too far in the
	 * future and treat it as old time stamp instead.
	 */
	if (delta > tc->cc->mask / 2) {
		delta = (tc->cycle_last - cycle_tstamp) & tc->cc->mask;
		nsec -= cc_cyc2ns_backwards(tc->cc, delta, tc->mask, frac);
	} else {
		nsec += cyclecounter_cyc2ns(tc->cc, delta, tc->mask, &frac);
	}

	return nsec;
}

