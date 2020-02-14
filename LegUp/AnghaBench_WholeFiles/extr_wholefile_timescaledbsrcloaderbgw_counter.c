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
struct TYPE_4__ {int total_workers; int /*<<< orphan*/  mutex; } ;
typedef  int /*<<< orphan*/  CounterState ;

/* Variables and functions */
 int /*<<< orphan*/  AddinShmemInitLock ; 
 int /*<<< orphan*/  BGW_COUNTER_STATE_NAME ; 
 int /*<<< orphan*/  DefineCustomIntVariable (char*,char*,char*,int*,int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  FATAL ; 
 int /*<<< orphan*/  LWLockAcquire (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LWLockRelease (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LW_EXCLUSIVE ; 
 int /*<<< orphan*/  PGC_POSTMASTER ; 
 int /*<<< orphan*/  RequestAddinShmemSpace (int) ; 
 TYPE_1__* ShmemInitStruct (int /*<<< orphan*/ ,int,int*) ; 
 int /*<<< orphan*/  SpinLockAcquire (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SpinLockInit (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SpinLockRelease (int /*<<< orphan*/ *) ; 
 TYPE_1__* ct ; 
 int /*<<< orphan*/  ereport (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  errhint (char*) ; 
 int /*<<< orphan*/  errmsg (char*) ; 
 int /*<<< orphan*/  memset (TYPE_1__*,int /*<<< orphan*/ ,int) ; 
 int ts_guc_max_background_workers ; 

__attribute__((used)) static void
bgw_counter_state_init()
{
	bool found;

	LWLockAcquire(AddinShmemInitLock, LW_EXCLUSIVE);
	ct = ShmemInitStruct(BGW_COUNTER_STATE_NAME, sizeof(CounterState), &found);
	if (!found)
	{
		memset(ct, 0, sizeof(CounterState));
		SpinLockInit(&ct->mutex);
		ct->total_workers = 0;
	}
	LWLockRelease(AddinShmemInitLock);
}

extern void
ts_bgw_counter_setup_gucs(void)
{
	DefineCustomIntVariable("timescaledb.max_background_workers",
							"Maximum background worker processes allocated to TimescaleDB",
							"Max background worker processes allocated to TimescaleDB - set to at "
							"least 1 + number of databases in Postgres instance to use background "
							"workers ",
							&ts_guc_max_background_workers,
							ts_guc_max_background_workers,
							0,
							1000, /* no reasonable way to have more than
								   * 1000 background workers */
							PGC_POSTMASTER,
							0,
							NULL,
							NULL,
							NULL);
}

extern void
ts_bgw_counter_shmem_alloc(void)
{
	RequestAddinShmemSpace(sizeof(CounterState));
}

extern void
ts_bgw_counter_shmem_startup(void)
{
	bgw_counter_state_init();
}

extern void
ts_bgw_counter_reinit(void)
{
	/* set counter back to zero on startup */
	SpinLockAcquire(&ct->mutex);
	ct->total_workers = 0;
	SpinLockRelease(&ct->mutex);
}

extern bool
ts_bgw_total_workers_increment_by(int increment_by)
{
	bool incremented = false;
	int max_workers = ts_guc_max_background_workers;

	SpinLockAcquire(&ct->mutex);
	if (ct->total_workers + increment_by <= max_workers)
	{
		ct->total_workers += increment_by;
		incremented = true;
	}
	SpinLockRelease(&ct->mutex);
	return incremented;
}

extern bool
ts_bgw_total_workers_increment()
{
	return ts_bgw_total_workers_increment_by(1);
}

extern void
ts_bgw_total_workers_decrement_by(int decrement_by)
{
	/*
	 * Launcher is 1 worker, and when it dies we reinitialize, so we should
	 * never be below 1
	 */
	SpinLockAcquire(&ct->mutex);
	if (ct->total_workers - decrement_by >= 1)
	{
		ct->total_workers -= decrement_by;
		SpinLockRelease(&ct->mutex);
	}
	else
	{
		SpinLockRelease(&ct->mutex);
		ereport(FATAL,
				(errmsg("TimescaleDB background worker cannot decrement workers below 1"),
				 errhint("The background worker scheduler is in an invalid state and may not be "
						 "keeping track of workers allocated to TimescaleDB properly, please "
						 "submit a bug report.")));
	}
}

extern void
ts_bgw_total_workers_decrement()
{
	ts_bgw_total_workers_decrement_by(1);
}

extern int
ts_bgw_total_workers_get()
{
	int nworkers;

	SpinLockAcquire(&ct->mutex);
	nworkers = ct->total_workers;
	SpinLockRelease(&ct->mutex);
	return nworkers;
}

