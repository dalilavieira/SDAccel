#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
struct TYPE_10__ {scalar_t__ x; } ;
struct TYPE_11__ {scalar_t__ detachState; scalar_t__ state; void* exitStatus; int /*<<< orphan*/  threadH; TYPE_1__ ptHandle; int /*<<< orphan*/  stateLock; } ;
typedef  TYPE_2__ ptw32_thread_t ;
typedef  int /*<<< orphan*/  ptw32_mcs_local_node_t ;
struct TYPE_12__ {scalar_t__ x; int /*<<< orphan*/ * p; } ;
typedef  TYPE_3__ pthread_t ;
typedef  scalar_t__ BOOL ;

/* Variables and functions */
 int EDEADLK ; 
 int EINVAL ; 
 int ENOENT ; 
 int ESRCH ; 
 int /*<<< orphan*/  INFINITE ; 
 scalar_t__ PTHREAD_CREATE_DETACHED ; 
 scalar_t__ PTW32_FALSE ; 
 scalar_t__ PTW32_TRUE ; 
 scalar_t__ PThreadStateLast ; 
 int /*<<< orphan*/  WaitForSingleObject (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int pthreadCancelableWait (int /*<<< orphan*/ ) ; 
 scalar_t__ pthread_equal (TYPE_3__,TYPE_3__) ; 
 TYPE_3__ pthread_self () ; 
 int /*<<< orphan*/  ptw32_mcs_lock_acquire (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ptw32_mcs_lock_release (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ptw32_threadDestroy (TYPE_3__) ; 
 int /*<<< orphan*/  ptw32_thread_reuse_lock ; 

int
pthread_detach (pthread_t thread)
     /*
      * ------------------------------------------------------
      * DOCPUBLIC
      *      This function detaches the given thread.
      *
      * PARAMETERS
      *      thread
      *              an instance of a pthread_t
      *
      *
      * DESCRIPTION
      *      This function detaches the given thread. You may use it to
      *      detach the main thread or to detach a joinable thread.
      *      NOTE:   detached threads cannot be joined;
      *              storage is freed immediately on termination.
      *
      * RESULTS
      *              0               successfully detached the thread,
      *              EINVAL          thread is not a joinable thread,
      *              ENOSPC          a required resource has been exhausted,
      *              ESRCH           no thread could be found for 'thread',
      *
      * ------------------------------------------------------
      */
{
  int result;
  BOOL destroyIt = PTW32_FALSE;
  ptw32_thread_t * tp = (ptw32_thread_t *) thread.p;
  ptw32_mcs_local_node_t node;

  ptw32_mcs_lock_acquire(&ptw32_thread_reuse_lock, &node);

  if (NULL == tp
      || thread.x != tp->ptHandle.x)
    {
      result = ESRCH;
    }
  else if (PTHREAD_CREATE_DETACHED == tp->detachState)
    {
      result = EINVAL;
    }
  else
    {
      ptw32_mcs_local_node_t stateLock;
      /*
       * Joinable ptw32_thread_t structs are not scavenged until
       * a join or detach is done. The thread may have exited already,
       * but all of the state and locks etc are still there.
       */
      result = 0;

      ptw32_mcs_lock_acquire (&tp->stateLock, &stateLock);
      if (tp->state != PThreadStateLast)
        {
          tp->detachState = PTHREAD_CREATE_DETACHED;
        }
      else if (tp->detachState != PTHREAD_CREATE_DETACHED)
        {
          /*
           * Thread is joinable and has exited or is exiting.
           */
          destroyIt = PTW32_TRUE;
        }
      ptw32_mcs_lock_release (&stateLock);
    }

  ptw32_mcs_lock_release(&node);

  if (result == 0)
    {
      /* Thread is joinable */

      if (destroyIt)
	{
	  /* The thread has exited or is exiting but has not been joined or
	   * detached. Need to wait in case it's still exiting.
	   */
	  (void) WaitForSingleObject(tp->threadH, INFINITE);
	  ptw32_threadDestroy (thread);
	}
    }

  return (result);

}

int
pthread_join (pthread_t thread, void **value_ptr)
     /*
      * ------------------------------------------------------
      * DOCPUBLIC
      *      This function waits for 'thread' to terminate and
      *      returns the thread's exit value if 'value_ptr' is not
      *      NULL. This also detaches the thread on successful
      *      completion.
      *
      * PARAMETERS
      *      thread
      *              an instance of pthread_t
      *
      *      value_ptr
      *              pointer to an instance of pointer to void
      *
      *
      * DESCRIPTION
      *      This function waits for 'thread' to terminate and
      *      returns the thread's exit value if 'value_ptr' is not
      *      NULL. This also detaches the thread on successful
      *      completion.
      *      NOTE:   detached threads cannot be joined or canceled
      *
      * RESULTS
      *              0               'thread' has completed
      *              EINVAL          thread is not a joinable thread,
      *              ESRCH           no thread could be found with ID 'thread',
      *              ENOENT          thread couldn't find it's own valid handle,
      *              EDEADLK         attempt to join thread with self
      *
      * ------------------------------------------------------
      */
{
  int result;
  pthread_t self;
  ptw32_thread_t * tp = (ptw32_thread_t *) thread.p;
  ptw32_mcs_local_node_t node;

  ptw32_mcs_lock_acquire(&ptw32_thread_reuse_lock, &node);

  if (NULL == tp
      || thread.x != tp->ptHandle.x)
    {
      result = ESRCH;
    }
  else if (PTHREAD_CREATE_DETACHED == tp->detachState)
    {
      result = EINVAL;
    }
  else
    {
      result = 0;
    }

  ptw32_mcs_lock_release(&node);

  if (result == 0)
    {
      /* 
       * The target thread is joinable and can't be reused before we join it.
       */
      self = pthread_self();

      if (NULL == self.p)
	{
	  result = ENOENT;
	}
      else if (pthread_equal (self, thread))
	{
	  result = EDEADLK;
	}
      else
	{
	  /*
	   * Pthread_join is a cancelation point.
	   * If we are canceled then our target thread must not be
	   * detached (destroyed). This is guarranteed because
	   * pthreadCancelableWait will not return if we
	   * are canceled.
	   */
	  result = pthreadCancelableWait (tp->threadH);

	  if (0 == result)
	    {
	      if (value_ptr != NULL)
		{
		  *value_ptr = tp->exitStatus;
		}

	      /*
	       * The result of making multiple simultaneous calls to
	       * pthread_join() or pthread_detach() specifying the same
	       * target is undefined.
	       */
	      result = pthread_detach (thread);
	    }
	  else
	    {
	      result = ESRCH;
	    }
	}
    }

  return (result);

}

