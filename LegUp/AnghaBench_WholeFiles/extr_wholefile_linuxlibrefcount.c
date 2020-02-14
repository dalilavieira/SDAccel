#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_1__ ;

/* Type definitions */
struct mutex {int dummy; } ;
typedef  int /*<<< orphan*/  spinlock_t ;
struct TYPE_15__ {int /*<<< orphan*/  refs; } ;
typedef  TYPE_1__ refcount_t ;

/* Variables and functions */
 unsigned int UINT_MAX ; 
 int /*<<< orphan*/  WARN_ONCE (int,char*) ; 
 unsigned int atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  atomic_try_cmpxchg_relaxed (int /*<<< orphan*/ *,unsigned int*,unsigned int) ; 
 int atomic_try_cmpxchg_release (int /*<<< orphan*/ *,...) ; 
 int /*<<< orphan*/  mutex_lock (struct mutex*) ; 
 int /*<<< orphan*/  mutex_unlock (struct mutex*) ; 
 int /*<<< orphan*/  refcount_dec_and_test (TYPE_1__*) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 scalar_t__ unlikely (int) ; 

bool refcount_add_not_zero_checked(unsigned int i, refcount_t *r)
{
	unsigned int new, val = atomic_read(&r->refs);

	do {
		if (!val)
			return false;

		if (unlikely(val == UINT_MAX))
			return true;

		new = val + i;
		if (new < val)
			new = UINT_MAX;

	} while (!atomic_try_cmpxchg_relaxed(&r->refs, &val, new));

	WARN_ONCE(new == UINT_MAX, "refcount_t: saturated; leaking memory.\n");

	return true;
}

void refcount_add_checked(unsigned int i, refcount_t *r)
{
	WARN_ONCE(!refcount_add_not_zero_checked(i, r), "refcount_t: addition on 0; use-after-free.\n");
}

bool refcount_inc_not_zero_checked(refcount_t *r)
{
	unsigned int new, val = atomic_read(&r->refs);

	do {
		new = val + 1;

		if (!val)
			return false;

		if (unlikely(!new))
			return true;

	} while (!atomic_try_cmpxchg_relaxed(&r->refs, &val, new));

	WARN_ONCE(new == UINT_MAX, "refcount_t: saturated; leaking memory.\n");

	return true;
}

void refcount_inc_checked(refcount_t *r)
{
	WARN_ONCE(!refcount_inc_not_zero_checked(r), "refcount_t: increment on 0; use-after-free.\n");
}

bool refcount_sub_and_test_checked(unsigned int i, refcount_t *r)
{
	unsigned int new, val = atomic_read(&r->refs);

	do {
		if (unlikely(val == UINT_MAX))
			return false;

		new = val - i;
		if (new > val) {
			WARN_ONCE(new > val, "refcount_t: underflow; use-after-free.\n");
			return false;
		}

	} while (!atomic_try_cmpxchg_release(&r->refs, &val, new));

	return !new;
}

bool refcount_dec_and_test_checked(refcount_t *r)
{
	return refcount_sub_and_test_checked(1, r);
}

void refcount_dec_checked(refcount_t *r)
{
	WARN_ONCE(refcount_dec_and_test_checked(r), "refcount_t: decrement hit 0; leaking memory.\n");
}

bool refcount_dec_if_one(refcount_t *r)
{
	int val = 1;

	return atomic_try_cmpxchg_release(&r->refs, &val, 0);
}

bool refcount_dec_not_one(refcount_t *r)
{
	unsigned int new, val = atomic_read(&r->refs);

	do {
		if (unlikely(val == UINT_MAX))
			return true;

		if (val == 1)
			return false;

		new = val - 1;
		if (new > val) {
			WARN_ONCE(new > val, "refcount_t: underflow; use-after-free.\n");
			return true;
		}

	} while (!atomic_try_cmpxchg_release(&r->refs, &val, new));

	return true;
}

bool refcount_dec_and_mutex_lock(refcount_t *r, struct mutex *lock)
{
	if (refcount_dec_not_one(r))
		return false;

	mutex_lock(lock);
	if (!refcount_dec_and_test(r)) {
		mutex_unlock(lock);
		return false;
	}

	return true;
}

bool refcount_dec_and_lock(refcount_t *r, spinlock_t *lock)
{
	if (refcount_dec_not_one(r))
		return false;

	spin_lock(lock);
	if (!refcount_dec_and_test(r)) {
		spin_unlock(lock);
		return false;
	}

	return true;
}

bool refcount_dec_and_lock_irqsave(refcount_t *r, spinlock_t *lock,
				   unsigned long *flags)
{
	if (refcount_dec_not_one(r))
		return false;

	spin_lock_irqsave(lock, *flags);
	if (!refcount_dec_and_test(r)) {
		spin_unlock_irqrestore(lock, *flags);
		return false;
	}

	return true;
}

