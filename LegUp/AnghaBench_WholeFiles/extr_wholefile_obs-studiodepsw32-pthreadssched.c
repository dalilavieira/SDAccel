#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_17__   TYPE_3__ ;
typedef  struct TYPE_16__   TYPE_2__ ;
typedef  struct TYPE_15__   TYPE_1__ ;

/* Type definitions */
typedef  struct sched_param {int sched_priority; } const sched_param ;
struct TYPE_15__ {int sched_priority; int /*<<< orphan*/  threadH; int /*<<< orphan*/  threadLock; } ;
typedef  TYPE_1__ ptw32_thread_t ;
typedef  int /*<<< orphan*/  ptw32_mcs_local_node_t ;
struct TYPE_16__ {scalar_t__ p; } ;
typedef  TYPE_2__ pthread_t ;
typedef  TYPE_3__* pthread_attr_t ;
typedef  scalar_t__ pid_t ;
struct TYPE_17__ {int inheritsched; struct sched_param const param; } ;
typedef  int /*<<< orphan*/ * HANDLE ;
typedef  int /*<<< orphan*/  DWORD ;

/* Variables and functions */
 int /*<<< orphan*/  CloseHandle (int /*<<< orphan*/ *) ; 
 int EINVAL ; 
 int ENOSYS ; 
 int ENOTSUP ; 
 int EPERM ; 
 int ERROR_ACCESS_DENIED ; 
 int ESRCH ; 
 scalar_t__ GetCurrentProcessId () ; 
 int GetLastError () ; 
 int /*<<< orphan*/ * OpenProcess (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PROCESS_QUERY_INFORMATION ; 
 int /*<<< orphan*/  PROCESS_SET_INFORMATION ; 
 int PTHREAD_EXPLICIT_SCHED ; 
 int PTHREAD_INHERIT_SCHED ; 
 int /*<<< orphan*/  PTW32_FALSE ; 
 int PTW32_MAX (int,int) ; 
 int PTW32_MIN (int,int) ; 
 int SCHED_MAX ; 
 int SCHED_MIN ; 
 int SCHED_OTHER ; 
 scalar_t__ SetThreadPriority (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  Sleep (int /*<<< orphan*/ ) ; 
 int THREAD_PRIORITY_HIGHEST ; 
 int THREAD_PRIORITY_IDLE ; 
 int THREAD_PRIORITY_LOWEST ; 
 int THREAD_PRIORITY_TIME_CRITICAL ; 
 int errno ; 
 int /*<<< orphan*/  memcpy (struct sched_param const*,struct sched_param const*,int) ; 
 int pthread_kill (TYPE_2__,int /*<<< orphan*/ ) ; 
 scalar_t__ ptw32_is_attr (TYPE_3__* const*) ; 
 int /*<<< orphan*/  ptw32_mcs_lock_acquire (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ptw32_mcs_lock_release (int /*<<< orphan*/ *) ; 
 int ptw32_setthreadpriority (TYPE_2__,int,int) ; 
 int sched_get_priority_max (int) ; 
 int sched_get_priority_min (int) ; 

int
pthread_attr_setschedpolicy (pthread_attr_t * attr, int policy)
{
  if (ptw32_is_attr (attr) != 0)
    {
      return EINVAL;
    }

  if (policy != SCHED_OTHER)
    {
      return ENOTSUP;
    }

  return 0;
}

int
pthread_attr_getschedpolicy (const pthread_attr_t * attr, int *policy)
{
  if (ptw32_is_attr (attr) != 0 || policy == NULL)
    {
      return EINVAL;
    }

  /*
   * Validate the policy arg.
   * Check that a policy constant wasn't passed rather than &policy.
   */
  if (policy <= (int *) SCHED_MAX)
    {
      return EINVAL;
    }

  *policy = SCHED_OTHER;

  return 0;
}

int
pthread_attr_setschedparam (pthread_attr_t * attr,
			    const struct sched_param *param)
{
  int priority;

  if (ptw32_is_attr (attr) != 0 || param == NULL)
    {
      return EINVAL;
    }

  priority = param->sched_priority;

  /* Validate priority level. */
  if (priority < sched_get_priority_min (SCHED_OTHER) ||
      priority > sched_get_priority_max (SCHED_OTHER))
    {
      return EINVAL;
    }

  memcpy (&(*attr)->param, param, sizeof (*param));
  return 0;
}

int
pthread_attr_getschedparam (const pthread_attr_t * attr,
			    struct sched_param *param)
{
  if (ptw32_is_attr (attr) != 0 || param == NULL)
    {
      return EINVAL;
    }

  memcpy (param, &(*attr)->param, sizeof (*param));
  return 0;
}

int
pthread_attr_setinheritsched (pthread_attr_t * attr, int inheritsched)
{
  if (ptw32_is_attr (attr) != 0)
    {
      return EINVAL;
    }

  if (PTHREAD_INHERIT_SCHED != inheritsched
      && PTHREAD_EXPLICIT_SCHED != inheritsched)
    {
      return EINVAL;
    }

  (*attr)->inheritsched = inheritsched;
  return 0;
}

int
pthread_attr_getinheritsched (const pthread_attr_t * attr, int *inheritsched)
{
  if (ptw32_is_attr (attr) != 0 || inheritsched == NULL)
    {
      return EINVAL;
    }

  *inheritsched = (*attr)->inheritsched;
  return 0;
}

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

int
pthread_getschedparam (pthread_t thread, int *policy,
		       struct sched_param *param)
{
  int result;

  /* Validate the thread id. */
  result = pthread_kill (thread, 0);
  if (0 != result)
    {
      return result;
    }

  /*
   * Validate the policy and param args.
   * Check that a policy constant wasn't passed rather than &policy.
   */
  if (policy <= (int *) SCHED_MAX || param == NULL)
    {
      return EINVAL;
    }

  /* Fill out the policy. */
  *policy = SCHED_OTHER;

  /*
   * This function must return the priority value set by
   * the most recent pthread_setschedparam() or pthread_create()
   * for the target thread. It must not return the actual thread
   * priority as altered by any system priority adjustments etc.
   */
  param->sched_priority = ((ptw32_thread_t *)thread.p)->sched_priority;

  return 0;
}

int
sched_get_priority_max (int policy)
{
  if (policy < SCHED_MIN || policy > SCHED_MAX)
    {
      errno = EINVAL;
      return -1;
    }

#if (THREAD_PRIORITY_LOWEST > THREAD_PRIORITY_NORMAL)
  /* WinCE? */
  return PTW32_MAX (THREAD_PRIORITY_IDLE, THREAD_PRIORITY_TIME_CRITICAL);
#else
  /* This is independent of scheduling policy in Win32. */
  return PTW32_MAX (THREAD_PRIORITY_IDLE, THREAD_PRIORITY_TIME_CRITICAL);
#endif
}

int
sched_get_priority_min (int policy)
{
  if (policy < SCHED_MIN || policy > SCHED_MAX)
    {
      errno = EINVAL;
      return -1;
    }

#if (THREAD_PRIORITY_LOWEST > THREAD_PRIORITY_NORMAL)
  /* WinCE? */
  return PTW32_MIN (THREAD_PRIORITY_IDLE, THREAD_PRIORITY_TIME_CRITICAL);
#else
  /* This is independent of scheduling policy in Win32. */
  return PTW32_MIN (THREAD_PRIORITY_IDLE, THREAD_PRIORITY_TIME_CRITICAL);
#endif
}

int
sched_setscheduler (pid_t pid, int policy)
{
  /*
   * Win32 only has one policy which we call SCHED_OTHER.
   * However, we try to provide other valid side-effects
   * such as EPERM and ESRCH errors. Choosing to check
   * for a valid policy last allows us to get the most value out
   * of this function.
   */
  if (0 != pid)
    {
      int selfPid = (int) GetCurrentProcessId ();

      if (pid != selfPid)
	{
	  HANDLE h =
	    OpenProcess (PROCESS_SET_INFORMATION, PTW32_FALSE, (DWORD) pid);

	  if (NULL == h)
	    {
	      errno =
		(GetLastError () ==
		 (0xFF & ERROR_ACCESS_DENIED)) ? EPERM : ESRCH;
	      return -1;
	    }
	  else
	    CloseHandle(h);
	}
    }

  if (SCHED_OTHER != policy)
    {
      errno = ENOSYS;
      return -1;
    }

  /*
   * Don't set anything because there is nothing to set.
   * Just return the current (the only possible) value.
   */
  return SCHED_OTHER;
}

int
sched_getscheduler (pid_t pid)
{
  /*
   * Win32 only has one policy which we call SCHED_OTHER.
   * However, we try to provide other valid side-effects
   * such as EPERM and ESRCH errors.
   */
  if (0 != pid)
    {
      int selfPid = (int) GetCurrentProcessId ();

      if (pid != selfPid)
	{
	  HANDLE h =
	    OpenProcess (PROCESS_QUERY_INFORMATION, PTW32_FALSE, (DWORD) pid);

	  if (NULL == h)
	    {
	      errno =
		(GetLastError () ==
		 (0xFF & ERROR_ACCESS_DENIED)) ? EPERM : ESRCH;
	      return -1;
	    }
	  else
	    CloseHandle(h);
	}
    }

  return SCHED_OTHER;
}

int
sched_yield (void)
     /*
      * ------------------------------------------------------
      * DOCPUBLIC
      *      This function indicates that the calling thread is
      *      willing to give up some time slices to other threads.
      *
      * PARAMETERS
      *      N/A
      *
      *
      * DESCRIPTION
      *      This function indicates that the calling thread is
      *      willing to give up some time slices to other threads.
      *      NOTE: Since this is part of POSIX 1003.1b
      *                (realtime extensions), it is defined as returning
      *                -1 if an error occurs and sets errno to the actual
      *                error.
      *
      * RESULTS
      *              0               successfully created semaphore,
      *              ENOSYS          sched_yield not supported,
      *
      * ------------------------------------------------------
      */
{
  Sleep (0);

  return 0;
}

