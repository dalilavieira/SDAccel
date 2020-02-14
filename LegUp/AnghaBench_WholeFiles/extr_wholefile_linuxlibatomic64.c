#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_6__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  raw_spinlock_t ;
struct TYPE_10__ {long long counter; } ;
typedef  TYPE_1__ atomic64_t ;
struct TYPE_11__ {int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 unsigned long L1_CACHE_SHIFT ; 
 int NR_LOCKS ; 
 TYPE_6__* atomic64_lock ; 
 int /*<<< orphan*/  raw_spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  raw_spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static inline raw_spinlock_t *lock_addr(const atomic64_t *v)
{
	unsigned long addr = (unsigned long) v;

	addr >>= L1_CACHE_SHIFT;
	addr ^= (addr >> 8) ^ (addr >> 16);
	return &atomic64_lock[addr & (NR_LOCKS - 1)].lock;
}

long long atomic64_read(const atomic64_t *v)
{
	unsigned long flags;
	raw_spinlock_t *lock = lock_addr(v);
	long long val;

	raw_spin_lock_irqsave(lock, flags);
	val = v->counter;
	raw_spin_unlock_irqrestore(lock, flags);
	return val;
}

void atomic64_set(atomic64_t *v, long long i)
{
	unsigned long flags;
	raw_spinlock_t *lock = lock_addr(v);

	raw_spin_lock_irqsave(lock, flags);
	v->counter = i;
	raw_spin_unlock_irqrestore(lock, flags);
}

long long atomic64_dec_if_positive(atomic64_t *v)
{
	unsigned long flags;
	raw_spinlock_t *lock = lock_addr(v);
	long long val;

	raw_spin_lock_irqsave(lock, flags);
	val = v->counter - 1;
	if (val >= 0)
		v->counter = val;
	raw_spin_unlock_irqrestore(lock, flags);
	return val;
}

long long atomic64_cmpxchg(atomic64_t *v, long long o, long long n)
{
	unsigned long flags;
	raw_spinlock_t *lock = lock_addr(v);
	long long val;

	raw_spin_lock_irqsave(lock, flags);
	val = v->counter;
	if (val == o)
		v->counter = n;
	raw_spin_unlock_irqrestore(lock, flags);
	return val;
}

long long atomic64_xchg(atomic64_t *v, long long new)
{
	unsigned long flags;
	raw_spinlock_t *lock = lock_addr(v);
	long long val;

	raw_spin_lock_irqsave(lock, flags);
	val = v->counter;
	v->counter = new;
	raw_spin_unlock_irqrestore(lock, flags);
	return val;
}

long long atomic64_fetch_add_unless(atomic64_t *v, long long a, long long u)
{
	unsigned long flags;
	raw_spinlock_t *lock = lock_addr(v);
	long long val;

	raw_spin_lock_irqsave(lock, flags);
	val = v->counter;
	if (val != u)
		v->counter += a;
	raw_spin_unlock_irqrestore(lock, flags);

	return val;
}

