#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  rb_root; } ;
struct task_struct {int pi_blocked_on; TYPE_1__ pi_waiters; int /*<<< orphan*/  prio; int /*<<< orphan*/  comm; } ;
struct rt_mutex_waiter {int dummy; } ;
struct rt_mutex {int /*<<< orphan*/  owner; int /*<<< orphan*/  line; int /*<<< orphan*/  file; scalar_t__ name; } ;
typedef  enum rtmutex_chainwalk { ____Placeholder_rtmutex_chainwalk } rtmutex_chainwalk ;

/* Variables and functions */
 int /*<<< orphan*/  DEBUG_LOCKS_WARN_ON (int) ; 
 int /*<<< orphan*/  RB_EMPTY_ROOT (int /*<<< orphan*/ *) ; 
 scalar_t__ READ_ONCE (int /*<<< orphan*/ ) ; 
 int RT_MUTEX_FULL_CHAINWALK ; 
 unsigned long RT_MUTEX_HAS_WAITERS ; 
 int /*<<< orphan*/  WARN (int,char*) ; 
 int /*<<< orphan*/  printk (char*,...) ; 
 int /*<<< orphan*/  task_pid_nr (struct task_struct*) ; 

__attribute__((used)) static inline int rt_mutex_has_waiters(struct rt_mutex *lock)
{
	return false;
}

__attribute__((used)) static inline struct rt_mutex_waiter *
rt_mutex_top_waiter(struct rt_mutex *lock)
{
	return NULL;
}

__attribute__((used)) static inline int task_has_pi_waiters(struct task_struct *p)
{
	return false;
}

__attribute__((used)) static inline struct rt_mutex_waiter *
task_top_pi_waiter(struct task_struct *p)
{
	return NULL;
}

__attribute__((used)) static inline struct task_struct *rt_mutex_owner(struct rt_mutex *lock)
{
	unsigned long owner = (unsigned long) READ_ONCE(lock->owner);

	return (struct task_struct *) (owner & ~RT_MUTEX_HAS_WAITERS);
}

__attribute__((used)) static inline void rt_mutex_print_deadlock(struct rt_mutex_waiter *w)
{
	WARN(1, "rtmutex deadlock detected\n");
}

__attribute__((used)) static inline bool debug_rt_mutex_detect_deadlock(struct rt_mutex_waiter *w,
						  enum rtmutex_chainwalk walk)
{
	return walk == RT_MUTEX_FULL_CHAINWALK;
}

__attribute__((used)) static void printk_task(struct task_struct *p)
{
	if (p)
		printk("%16s:%5d [%p, %3d]", p->comm, task_pid_nr(p), p, p->prio);
	else
		printk("<none>");
}

__attribute__((used)) static void printk_lock(struct rt_mutex *lock, int print_owner)
{
	if (lock->name)
		printk(" [%p] {%s}\n",
			lock, lock->name);
	else
		printk(" [%p] {%s:%d}\n",
			lock, lock->file, lock->line);

	if (print_owner && rt_mutex_owner(lock)) {
		printk(".. ->owner: %p\n", lock->owner);
		printk(".. held by:  ");
		printk_task(rt_mutex_owner(lock));
		printk("\n");
	}
}

void rt_mutex_debug_task_free(struct task_struct *task)
{
	DEBUG_LOCKS_WARN_ON(!RB_EMPTY_ROOT(&task->pi_waiters.rb_root));
	DEBUG_LOCKS_WARN_ON(task->pi_blocked_on);
}

