#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct sched_param {int sched_priority; } ;
struct TYPE_6__ {int sched_priority; int /*<<< orphan*/  threadH; int /*<<< orphan*/  threadLock; } ;
typedef  TYPE_1__ ptw32_thread_t ;
typedef  int /*<<< orphan*/  ptw32_mcs_local_node_t ;
struct TYPE_7__ {scalar_t__ p; } ;
typedef  TYPE_2__ pthread_t ;

/* Variables and functions */
 int EINVAL ; 
 int ENOTSUP ; 
 int SCHED_MAX ; 
 int SCHED_MIN ; 
 int SCHED_OTHER ; 
 scalar_t__ SetThreadPriority (int /*<<< orphan*/ ,int) ; 
 int THREAD_PRIORITY_HIGHEST ; 
 int THREAD_PRIORITY_IDLE ; 
 int THREAD_PRIORITY_LOWEST ; 
 int THREAD_PRIORITY_TIME_CRITICAL ; 
 int pthread_kill (TYPE_2__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ptw32_mcs_lock_acquire (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ptw32_mcs_lock_release (int /*<<< orphan*/ *) ; 
 int ptw32_setthreadpriority (TYPE_2__,int,int) ; 
 int sched_get_priority_max (int) ; 
 int sched_get_priority_min (int) ; 

int
pthread_setschedparam (pthread_t thread, int policy,
		       const struct sched_param *param)
{
  int result;

  /* Validate the thread id. */
  result = pthread_kill (thread, 0);
  if (0 != result)
    {
      return result;
    }

  /* Validate the scheduling policy. */
  if (policy < SCHED_MIN || policy > SCHED_MAX)
    {
      return EINVAL;
    }

  /* Ensure the policy is SCHED_OTHER. */
  if (policy != SCHED_OTHER)
    {
      return ENOTSUP;
    }

  return (ptw32_setthreadpriority (thread, policy, param->sched_priority));
}

int
ptw32_setthreadpriority (pthread_t thread, int policy, int priority)
{
  int prio;
  ptw32_mcs_local_node_t threadLock;
  int result = 0;
  ptw32_thread_t * tp = (ptw32_thread_t *) thread.p;

  prio = priority;

  /* Validate priority level. */
  if (prio < sched_get_priority_min (policy) ||
      prio > sched_get_priority_max (policy))
    {
      return EINVAL;
    }

#if (THREAD_PRIORITY_LOWEST > THREAD_PRIORITY_NORMAL)
/* WinCE */
#else
/* Everything else */

  if (THREAD_PRIORITY_IDLE < prio && THREAD_PRIORITY_LOWEST > prio)
    {
      prio = THREAD_PRIORITY_LOWEST;
    }
  else if (THREAD_PRIORITY_TIME_CRITICAL > prio
	   && THREAD_PRIORITY_HIGHEST < prio)
    {
      prio = THREAD_PRIORITY_HIGHEST;
    }

#endif

  ptw32_mcs_lock_acquire (&tp->threadLock, &threadLock);

  /* If this fails, the current priority is unchanged. */
  if (0 == SetThreadPriority (tp->threadH, prio))
    {
      result = EINVAL;
    }
  else
    {
      /*
       * Must record the thread's sched_priority as given,
       * not as finally adjusted.
       */
      tp->sched_priority = priority;
    }

  ptw32_mcs_lock_release (&threadLock);

  return result;
}

