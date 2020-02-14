#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_20__   TYPE_1__ ;

/* Type definitions */
typedef  int uint32_t ;
typedef  scalar_t__ thread_t ;
struct TYPE_20__ {int /*<<< orphan*/  lck_mtx_state; } ;
typedef  TYPE_1__ lck_mtx_t ;
typedef  int /*<<< orphan*/  boolean_t ;

/* Variables and functions */
 int /*<<< orphan*/  FALSE ; 
 int LCK_MTX_ILOCKED_MSK ; 
 int LCK_MTX_MLOCKED_MSK ; 
 int LCK_MTX_PROMOTED_MSK ; 
 int LCK_MTX_SPIN_MSK ; 
 int LCK_MTX_WAITERS_MSK ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  atomic_compare_exchange32 (int /*<<< orphan*/ *,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ current_thread () ; 
 int /*<<< orphan*/  disable_preemption () ; 
 int /*<<< orphan*/  enable_preemption () ; 
 int /*<<< orphan*/  lck_mtx_lock_finish_inline (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 void lck_mtx_lock_slow (TYPE_1__*) ; 
 void lck_mtx_lock_spin_slow (TYPE_1__*) ; 
 int /*<<< orphan*/  lck_mtx_try_lock_finish_inline (TYPE_1__*,int) ; 
 int /*<<< orphan*/  lck_mtx_try_lock_slow (TYPE_1__*) ; 
 int /*<<< orphan*/  lck_mtx_try_lock_spin_slow (TYPE_1__*) ; 
 int /*<<< orphan*/  lck_mtx_unlock_finish_inline (TYPE_1__*,int /*<<< orphan*/ ) ; 
 void lck_mtx_unlock_slow (TYPE_1__*) ; 
 int /*<<< orphan*/  memory_order_acquire_smp ; 
 int ordered_load_mtx_state (TYPE_1__*) ; 
 int /*<<< orphan*/  ordered_store_mtx_owner (TYPE_1__*,uintptr_t) ; 
 int /*<<< orphan*/  ordered_store_mtx_state_release (TYPE_1__*,int) ; 

void __inline__
lck_mtx_check_preemption(void)
{
	return;
}

__attribute__((noinline))
void
lck_mtx_lock(
	lck_mtx_t       *lock)
{
	uint32_t prev, state;

	lck_mtx_check_preemption();
	state = ordered_load_mtx_state(lock);

	/*
	 * Fast path only if the mutex is not held
	 * interlock is not contended and there are no waiters.
	 * Indirect mutexes will fall through the slow path as
	 * well as destroyed mutexes.
	 */

	prev = state & ~(LCK_MTX_ILOCKED_MSK | LCK_MTX_MLOCKED_MSK | LCK_MTX_WAITERS_MSK);
	state = prev | LCK_MTX_ILOCKED_MSK | LCK_MTX_MLOCKED_MSK;

	disable_preemption();
	if (!atomic_compare_exchange32(&lock->lck_mtx_state, prev, state, memory_order_acquire_smp, FALSE)) {
		enable_preemption();
		return lck_mtx_lock_slow(lock);
	}

	/* mutex acquired, interlock acquired and preemption disabled */

	thread_t thread = current_thread();
	/* record owner of mutex */
	ordered_store_mtx_owner(lock, (uintptr_t)thread);

#if MACH_LDEBUG
	if (thread) {
		thread->mutex_count++;          /* lock statistic */
	}
#endif

	/* release interlock and re-enable preemption */
	lck_mtx_lock_finish_inline(lock, state, FALSE);
}

__attribute__((noinline))
boolean_t
lck_mtx_try_lock(
	lck_mtx_t	*lock)
{
	uint32_t prev, state;

	state = ordered_load_mtx_state(lock);

	/*
	 * Fast path only if the mutex is not held
	 * interlock is not contended and there are no waiters.
	 * Indirect mutexes will fall through the slow path as
	 * well as destroyed mutexes.
	 */

	prev = state & ~(LCK_MTX_ILOCKED_MSK | LCK_MTX_MLOCKED_MSK | LCK_MTX_WAITERS_MSK);
	state = prev | LCK_MTX_ILOCKED_MSK | LCK_MTX_MLOCKED_MSK;

	disable_preemption();
	if (!atomic_compare_exchange32(&lock->lck_mtx_state, prev, state, memory_order_acquire_smp, FALSE)) {
		enable_preemption();
		return lck_mtx_try_lock_slow(lock);
	}

	/* mutex acquired, interlock acquired and preemption disabled */

	thread_t thread = current_thread();
	/* record owner of mutex */
	ordered_store_mtx_owner(lock, (uintptr_t)thread);

#if MACH_LDEBUG
	if (thread) {
		thread->mutex_count++;          /* lock statistic */
	}
#endif

	/* release interlock and re-enable preemption */
	lck_mtx_try_lock_finish_inline(lock, state);

	return TRUE;
}

__attribute__((noinline))
void
lck_mtx_lock_spin_always(
	lck_mtx_t	*lock)
{
	uint32_t prev, state;

	state = ordered_load_mtx_state(lock);

	/*
	 * Fast path only if the mutex is not held
	 * neither as mutex nor as spin and
	 * interlock is not contended.
	 * Indirect mutexes will fall through the slow path as
	 * well as destroyed mutexes.
	 */

	/* Note LCK_MTX_SPIN_MSK is set only if LCK_MTX_ILOCKED_MSK is set */
	prev = state & ~(LCK_MTX_ILOCKED_MSK | LCK_MTX_MLOCKED_MSK);
	state = prev | LCK_MTX_ILOCKED_MSK | LCK_MTX_SPIN_MSK;

	disable_preemption();
	if (!atomic_compare_exchange32(&lock->lck_mtx_state, prev, state, memory_order_acquire_smp, FALSE)) {
		enable_preemption();
		return lck_mtx_lock_spin_slow(lock);
	}

	/* mutex acquired as spinlock, interlock acquired and preemption disabled */

	thread_t thread = current_thread();
	/* record owner of mutex */
	ordered_store_mtx_owner(lock, (uintptr_t)thread);

#if MACH_LDEBUG
	if (thread) {
		thread->mutex_count++;          /* lock statistic */
	}
#endif

#if	CONFIG_DTRACE
	LOCKSTAT_RECORD(LS_LCK_MTX_LOCK_SPIN_ACQUIRE, lock, 0);
#endif
	/* return with the interlock held and preemption disabled */
	return;
}

void
lck_mtx_lock_spin(
	lck_mtx_t	*lock)
{
	lck_mtx_check_preemption();
	lck_mtx_lock_spin_always(lock);
}

__attribute__((noinline))
boolean_t
lck_mtx_try_lock_spin_always(
	lck_mtx_t       *lock)
{
	uint32_t prev, state;

	state = ordered_load_mtx_state(lock);

	/*
	 * Fast path only if the mutex is not held
	 * neither as mutex nor as spin and
	 * interlock is not contended.
	 * Indirect mutexes will fall through the slow path as
	 * well as destroyed mutexes.
	 */

	/* Note LCK_MTX_SPIN_MSK is set only if LCK_MTX_ILOCKED_MSK is set */
	prev = state & ~(LCK_MTX_ILOCKED_MSK | LCK_MTX_MLOCKED_MSK);
	state = prev | LCK_MTX_ILOCKED_MSK | LCK_MTX_SPIN_MSK;

	disable_preemption();
	if (!atomic_compare_exchange32(&lock->lck_mtx_state, prev, state, memory_order_acquire_smp, FALSE)) {
		enable_preemption();
		return lck_mtx_try_lock_spin_slow(lock);
	}

	/* mutex acquired as spinlock, interlock acquired and preemption disabled */

	thread_t thread = current_thread();
	/* record owner of mutex */
	ordered_store_mtx_owner(lock, (uintptr_t)thread);

#if MACH_LDEBUG
	if (thread) {
		thread->mutex_count++;          /* lock statistic */
	}
#endif

#if     CONFIG_DTRACE
	LOCKSTAT_RECORD(LS_LCK_MTX_TRY_SPIN_LOCK_ACQUIRE, lock, 0);
#endif

	/* return with the interlock held and preemption disabled */
	return TRUE;
}

boolean_t
lck_mtx_try_lock_spin(
	lck_mtx_t       *lock)
{
	return lck_mtx_try_lock_spin_always(lock);
}

__attribute__((noinline))
void
lck_mtx_unlock(
	lck_mtx_t	*lock)
{
	uint32_t prev, state;

	state = ordered_load_mtx_state(lock);

	if (state & LCK_MTX_SPIN_MSK)
		return lck_mtx_unlock_slow(lock);

	/*
	 * Only full mutex will go through the fast path
	 * (if the lock was acquired as a spinlock it will
	 * fall through the slow path).
	 * If there are waiters or promotions it will fall
	 * through the slow path.
	 * If it is indirect it will fall through the slow path.
	 */

	 /*
	  * Fast path state:
	  * interlock not held, no waiters, no promotion and mutex held.
	  */
	prev = state & ~(LCK_MTX_ILOCKED_MSK | LCK_MTX_WAITERS_MSK | LCK_MTX_PROMOTED_MSK);
	prev |= LCK_MTX_MLOCKED_MSK;

	state = prev | LCK_MTX_ILOCKED_MSK;
	state &= ~LCK_MTX_MLOCKED_MSK;

	disable_preemption();

	/* the memory order needs to be acquire because it is acquiring the interlock */
	if (!atomic_compare_exchange32(&lock->lck_mtx_state, prev, state, memory_order_acquire_smp, FALSE)) {
		enable_preemption();
		return lck_mtx_unlock_slow(lock);
	}

	/* mutex released, interlock acquired and preemption disabled */

#if DEVELOPMENT | DEBUG
	thread_t owner = (thread_t)lock->lck_mtx_owner;
	if(__improbable(owner != current_thread()))
		return lck_mtx_owner_check_panic(lock);
#endif

	/* clear owner */
	ordered_store_mtx_owner(lock, 0);
	/* release interlock */
	state &= ~LCK_MTX_ILOCKED_MSK;
	ordered_store_mtx_state_release(lock, state);

#if     MACH_LDEBUG
	thread_t thread = current_thread();
	if (thread)
		thread->mutex_count--;
#endif  /* MACH_LDEBUG */

	/* re-enable preemption */
	lck_mtx_unlock_finish_inline(lock, FALSE);
}

