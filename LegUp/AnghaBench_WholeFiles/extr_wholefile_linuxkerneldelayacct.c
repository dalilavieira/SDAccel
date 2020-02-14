#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u64 ;
typedef  scalar_t__ u32 ;
struct taskstats {unsigned long cpu_count; scalar_t__ blkio_delay_total; scalar_t__ swapin_delay_total; scalar_t__ freepages_delay_total; int /*<<< orphan*/  freepages_count; int /*<<< orphan*/  swapin_count; int /*<<< orphan*/  blkio_count; scalar_t__ cpu_run_virtual_total; scalar_t__ cpu_delay_total; scalar_t__ cpu_scaled_run_real_total; scalar_t__ cpu_run_real_total; } ;
struct TYPE_7__ {unsigned long long sum_exec_runtime; } ;
struct TYPE_6__ {unsigned long pcount; unsigned long long run_delay; } ;
struct task_struct {struct task_delay_info* delays; TYPE_3__ se; TYPE_2__ sched_info; } ;
struct task_delay_info {int flags; scalar_t__ swapin_delay; scalar_t__ blkio_delay; scalar_t__ blkio_start; scalar_t__ freepages_delay; int /*<<< orphan*/  lock; scalar_t__ freepages_count; scalar_t__ swapin_count; scalar_t__ blkio_count; } ;
typedef  scalar_t__ s64 ;
typedef  int /*<<< orphan*/  raw_spinlock_t ;
typedef  int /*<<< orphan*/  __u64 ;
struct TYPE_8__ {TYPE_1__* delays; } ;
struct TYPE_5__ {scalar_t__ freepages_start; scalar_t__ freepages_delay; scalar_t__ freepages_count; int /*<<< orphan*/  lock; scalar_t__ blkio_start; } ;

/* Variables and functions */
 int DELAYACCT_PF_SWAPIN ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  KMEM_CACHE (int /*<<< orphan*/ ,int) ; 
 int SLAB_ACCOUNT ; 
 int SLAB_PANIC ; 
 TYPE_4__* current ; 
 int /*<<< orphan*/  delayacct_cache ; 
 int /*<<< orphan*/  delayacct_tsk_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  init_task ; 
 struct task_delay_info* kmem_cache_zalloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ ktime_get_ns () ; 
 int /*<<< orphan*/  nsec_to_clock_t (scalar_t__) ; 
 int /*<<< orphan*/  raw_spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  raw_spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  raw_spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  task_cputime (struct task_struct*,scalar_t__*,scalar_t__*) ; 
 int /*<<< orphan*/  task_cputime_scaled (struct task_struct*,scalar_t__*,scalar_t__*) ; 
 int /*<<< orphan*/  task_delay_info ; 

void delayacct_init(void)
{
	delayacct_cache = KMEM_CACHE(task_delay_info, SLAB_PANIC|SLAB_ACCOUNT);
	delayacct_tsk_init(&init_task);
}

void __delayacct_tsk_init(struct task_struct *tsk)
{
	tsk->delays = kmem_cache_zalloc(delayacct_cache, GFP_KERNEL);
	if (tsk->delays)
		raw_spin_lock_init(&tsk->delays->lock);
}

__attribute__((used)) static void delayacct_end(raw_spinlock_t *lock, u64 *start, u64 *total,
			  u32 *count)
{
	s64 ns = ktime_get_ns() - *start;
	unsigned long flags;

	if (ns > 0) {
		raw_spin_lock_irqsave(lock, flags);
		*total += ns;
		(*count)++;
		raw_spin_unlock_irqrestore(lock, flags);
	}
}

void __delayacct_blkio_start(void)
{
	current->delays->blkio_start = ktime_get_ns();
}

void __delayacct_blkio_end(struct task_struct *p)
{
	struct task_delay_info *delays = p->delays;
	u64 *total;
	u32 *count;

	if (p->delays->flags & DELAYACCT_PF_SWAPIN) {
		total = &delays->swapin_delay;
		count = &delays->swapin_count;
	} else {
		total = &delays->blkio_delay;
		count = &delays->blkio_count;
	}

	delayacct_end(&delays->lock, &delays->blkio_start, total, count);
}

int __delayacct_add_tsk(struct taskstats *d, struct task_struct *tsk)
{
	u64 utime, stime, stimescaled, utimescaled;
	unsigned long long t2, t3;
	unsigned long flags, t1;
	s64 tmp;

	task_cputime(tsk, &utime, &stime);
	tmp = (s64)d->cpu_run_real_total;
	tmp += utime + stime;
	d->cpu_run_real_total = (tmp < (s64)d->cpu_run_real_total) ? 0 : tmp;

	task_cputime_scaled(tsk, &utimescaled, &stimescaled);
	tmp = (s64)d->cpu_scaled_run_real_total;
	tmp += utimescaled + stimescaled;
	d->cpu_scaled_run_real_total =
		(tmp < (s64)d->cpu_scaled_run_real_total) ? 0 : tmp;

	/*
	 * No locking available for sched_info (and too expensive to add one)
	 * Mitigate by taking snapshot of values
	 */
	t1 = tsk->sched_info.pcount;
	t2 = tsk->sched_info.run_delay;
	t3 = tsk->se.sum_exec_runtime;

	d->cpu_count += t1;

	tmp = (s64)d->cpu_delay_total + t2;
	d->cpu_delay_total = (tmp < (s64)d->cpu_delay_total) ? 0 : tmp;

	tmp = (s64)d->cpu_run_virtual_total + t3;
	d->cpu_run_virtual_total =
		(tmp < (s64)d->cpu_run_virtual_total) ?	0 : tmp;

	/* zero XXX_total, non-zero XXX_count implies XXX stat overflowed */

	raw_spin_lock_irqsave(&tsk->delays->lock, flags);
	tmp = d->blkio_delay_total + tsk->delays->blkio_delay;
	d->blkio_delay_total = (tmp < d->blkio_delay_total) ? 0 : tmp;
	tmp = d->swapin_delay_total + tsk->delays->swapin_delay;
	d->swapin_delay_total = (tmp < d->swapin_delay_total) ? 0 : tmp;
	tmp = d->freepages_delay_total + tsk->delays->freepages_delay;
	d->freepages_delay_total = (tmp < d->freepages_delay_total) ? 0 : tmp;
	d->blkio_count += tsk->delays->blkio_count;
	d->swapin_count += tsk->delays->swapin_count;
	d->freepages_count += tsk->delays->freepages_count;
	raw_spin_unlock_irqrestore(&tsk->delays->lock, flags);

	return 0;
}

__u64 __delayacct_blkio_ticks(struct task_struct *tsk)
{
	__u64 ret;
	unsigned long flags;

	raw_spin_lock_irqsave(&tsk->delays->lock, flags);
	ret = nsec_to_clock_t(tsk->delays->blkio_delay +
				tsk->delays->swapin_delay);
	raw_spin_unlock_irqrestore(&tsk->delays->lock, flags);
	return ret;
}

void __delayacct_freepages_start(void)
{
	current->delays->freepages_start = ktime_get_ns();
}

void __delayacct_freepages_end(void)
{
	delayacct_end(
		&current->delays->lock,
		&current->delays->freepages_start,
		&current->delays->freepages_delay,
		&current->delays->freepages_count);
}

