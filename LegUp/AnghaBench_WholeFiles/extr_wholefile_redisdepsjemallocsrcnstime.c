#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_24__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint64_t ;
struct timeval {scalar_t__ tv_sec; int tv_usec; } ;
struct TYPE_24__ {scalar_t__ ns; } ;
typedef  TYPE_1__ nstime_t ;

/* Variables and functions */
 scalar_t__ BILLION ; 
 scalar_t__ MILLION ; 
 int NSTIME_MONOTONIC ; 
 int UINT64_MAX ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  gettimeofday (struct timeval*,int /*<<< orphan*/ *) ; 
 scalar_t__ unlikely (int) ; 

void
nstime_init(nstime_t *time, uint64_t ns) {
	time->ns = ns;
}

void
nstime_init2(nstime_t *time, uint64_t sec, uint64_t nsec) {
	time->ns = sec * BILLION + nsec;
}

uint64_t
nstime_ns(const nstime_t *time) {
	return time->ns;
}

uint64_t
nstime_msec(const nstime_t *time) {
	return time->ns / MILLION;
}

uint64_t
nstime_sec(const nstime_t *time) {
	return time->ns / BILLION;
}

uint64_t
nstime_nsec(const nstime_t *time) {
	return time->ns % BILLION;
}

void
nstime_copy(nstime_t *time, const nstime_t *source) {
	*time = *source;
}

int
nstime_compare(const nstime_t *a, const nstime_t *b) {
	return (a->ns > b->ns) - (a->ns < b->ns);
}

void
nstime_add(nstime_t *time, const nstime_t *addend) {
	assert(UINT64_MAX - time->ns >= addend->ns);

	time->ns += addend->ns;
}

void
nstime_iadd(nstime_t *time, uint64_t addend) {
	assert(UINT64_MAX - time->ns >= addend);

	time->ns += addend;
}

void
nstime_subtract(nstime_t *time, const nstime_t *subtrahend) {
	assert(nstime_compare(time, subtrahend) >= 0);

	time->ns -= subtrahend->ns;
}

void
nstime_isubtract(nstime_t *time, uint64_t subtrahend) {
	assert(time->ns >= subtrahend);

	time->ns -= subtrahend;
}

void
nstime_imultiply(nstime_t *time, uint64_t multiplier) {
	assert((((time->ns | multiplier) & (UINT64_MAX << (sizeof(uint64_t) <<
	    2))) == 0) || ((time->ns * multiplier) / multiplier == time->ns));

	time->ns *= multiplier;
}

void
nstime_idivide(nstime_t *time, uint64_t divisor) {
	assert(divisor != 0);

	time->ns /= divisor;
}

uint64_t
nstime_divide(const nstime_t *time, const nstime_t *divisor) {
	assert(divisor->ns != 0);

	return time->ns / divisor->ns;
}

__attribute__((used)) static void
nstime_get(nstime_t *time) {
	struct timeval tv;

	gettimeofday(&tv, NULL);
	nstime_init2(time, tv.tv_sec, tv.tv_usec * 1000);
}

__attribute__((used)) static bool
nstime_monotonic_impl(void) {
	return NSTIME_MONOTONIC;
#undef NSTIME_MONOTONIC
}

__attribute__((used)) static bool
nstime_update_impl(nstime_t *time) {
	nstime_t old_time;

	nstime_copy(&old_time, time);
	nstime_get(time);

	/* Handle non-monotonic clocks. */
	if (unlikely(nstime_compare(&old_time, time) > 0)) {
		nstime_copy(time, &old_time);
		return true;
	}

	return false;
}

