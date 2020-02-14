#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int int64 ;
typedef  int /*<<< orphan*/  TimestampTz ;
struct TYPE_4__ {int (* wait ) (int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* get_current_timestamp ) () ;} ;
typedef  TYPE_1__ Timer ;

/* Variables and functions */
 int /*<<< orphan*/  ERRCODE_ADMIN_SHUTDOWN ; 
 int /*<<< orphan*/  FATAL ; 
 int /*<<< orphan*/  GetCurrentTimestamp () ; 
 int INT_MAX ; 
 int MAX_TIMEOUT ; 
 int MILLISECS_PER_SEC ; 
 int /*<<< orphan*/  MyLatch ; 
 int /*<<< orphan*/  ResetLatch (int /*<<< orphan*/ ) ; 
 scalar_t__ TIMESTAMP_IS_NOBEGIN (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TimestampDifference (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*,int*) ; 
 int USECS_PER_MILLISEC ; 
 int WL_LATCH_SET ; 
 int WL_POSTMASTER_DEATH ; 
 int WL_TIMEOUT ; 
 int WaitLatchCompat (int /*<<< orphan*/ ,int,int) ; 
 TYPE_1__ const* current_timer_implementation ; 
 int /*<<< orphan*/  ereport (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  errcode (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  errmsg (char*) ; 
 int /*<<< orphan*/  on_exit_reset () ; 
 int stub1 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub2 () ; 

__attribute__((used)) static inline void
on_postmaster_death(void)
{
	/*
	 * Don't call exit hooks cause we want to bail out quickly. We don't care
	 * about cleaning up shared memory in this case anyway since it's
	 * potentially corrupt.
	 */
	on_exit_reset();
	ereport(FATAL,
			(errcode(ERRCODE_ADMIN_SHUTDOWN),
			 errmsg("postmaster exited while timescaledb scheduler was working")));
}

__attribute__((used)) static int64
get_timeout_millisec(TimestampTz by_time)
{
	int64 timeout_sec = 0;
	int timeout_usec = 0;

	if (TIMESTAMP_IS_NOBEGIN(by_time))
		return 0;

	TimestampDifference(GetCurrentTimestamp(), by_time, &timeout_sec, &timeout_usec);

	if (timeout_sec <= 0 && timeout_usec <= 0)
		return 0;

	return timeout_sec * MILLISECS_PER_SEC + timeout_usec / USECS_PER_MILLISEC;
}

__attribute__((used)) static bool
wait_using_wait_latch(TimestampTz until)
{
	int wl_rc;

	int64 timeout = get_timeout_millisec(until);

	if (timeout > MAX_TIMEOUT)
		timeout = MAX_TIMEOUT;

	/* Wait latch requires timeout to be <= INT_MAX */
	if ((int64) timeout > (int64) INT_MAX)
		timeout = INT_MAX;

	wl_rc = WaitLatchCompat(MyLatch, WL_LATCH_SET | WL_TIMEOUT | WL_POSTMASTER_DEATH, timeout);
	ResetLatch(MyLatch);
	if (wl_rc & WL_POSTMASTER_DEATH)
		on_postmaster_death();

	return true;
}

__attribute__((used)) static inline const Timer *
timer_get()
{
	return current_timer_implementation;
}

bool
ts_timer_wait(TimestampTz until)
{
	return timer_get()->wait(until);
}

TimestampTz
ts_timer_get_current_timestamp()
{
	return timer_get()->get_current_timestamp();
}

