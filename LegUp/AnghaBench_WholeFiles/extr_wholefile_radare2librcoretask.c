#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct TYPE_9__ {int /*<<< orphan*/  tasks_lock; } ;
struct TYPE_8__ {int /*<<< orphan*/  cons_context; int /*<<< orphan*/  dispatch_lock; int /*<<< orphan*/  dispatch_cond; int /*<<< orphan*/ * running_sem; int /*<<< orphan*/  thread; struct TYPE_8__* res; struct TYPE_8__* cmd; } ;
typedef  int /*<<< orphan*/  TASK_SIGSET_T ;
typedef  int /*<<< orphan*/  RThreadSemaphore ;
typedef  TYPE_1__ RCoreTask ;
typedef  TYPE_2__ RCore ;

/* Variables and functions */
 int /*<<< orphan*/  free (TYPE_1__*) ; 
 int /*<<< orphan*/  r_cons_context_free (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  r_th_cond_free (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  r_th_free (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  r_th_lock_enter (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  r_th_lock_free (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  r_th_lock_leave (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  r_th_sem_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  r_th_sem_post (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  r_th_sem_wait (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void tasks_lock_block_signals(TASK_SIGSET_T *old_sigset) { (void)old_sigset; }

__attribute__((used)) static void tasks_lock_block_signals_reset(TASK_SIGSET_T *old_sigset) { (void)old_sigset; }

__attribute__((used)) static void tasks_lock_enter(RCore *core, TASK_SIGSET_T *old_sigset) {
	tasks_lock_block_signals (old_sigset);
	r_th_lock_enter (core->tasks_lock);
}

__attribute__((used)) static void tasks_lock_leave(RCore *core, TASK_SIGSET_T *old_sigset) {
	r_th_lock_leave (core->tasks_lock);
	tasks_lock_block_signals_reset (old_sigset);
}

__attribute__((used)) static void task_join(RCoreTask *task) {
	RThreadSemaphore *sem = task->running_sem;
	if (!sem) {
		return;
	}

	r_th_sem_wait (sem);
	r_th_sem_post (sem);
}

__attribute__((used)) static void task_free (RCoreTask *task) {
	if (!task) {
		return;
	}
	free (task->cmd);
	free (task->res);
	r_th_free (task->thread);
	r_th_sem_free (task->running_sem);
	r_th_cond_free (task->dispatch_cond);
	r_th_lock_free (task->dispatch_lock);
	r_cons_context_free (task->cons_context);
	free (task);
}

