#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  ptw32_mcs_local_node_t ;
typedef  TYPE_1__* pthread_barrierattr_t ;
typedef  TYPE_1__* pthread_barrier_t ;
struct TYPE_12__ {int pshared; unsigned int nCurrentBarrierHeight; unsigned int nInitialBarrierHeight; int /*<<< orphan*/  proxynode; int /*<<< orphan*/  semBarrierBreeched; scalar_t__ lock; } ;
typedef  int /*<<< orphan*/  PTW32_INTERLOCKED_LONGPTR ;
typedef  scalar_t__ PTW32_INTERLOCKED_LONG ;

/* Variables and functions */
 int EBUSY ; 
 int EINVAL ; 
 int ENOMEM ; 
 int ENOSYS ; 
 int PTHREAD_BARRIER_SERIAL_THREAD ; 
 int PTHREAD_PROCESS_PRIVATE ; 
 int PTHREAD_PROCESS_SHARED ; 
 scalar_t__ PTW32_INTERLOCKED_INCREMENT_LONG (int /*<<< orphan*/ ) ; 
 scalar_t__ PTW32_OBJECT_INVALID ; 
 scalar_t__ calloc (int,int) ; 
 int /*<<< orphan*/  free (TYPE_1__*) ; 
 int /*<<< orphan*/  ptw32_mcs_lock_acquire (scalar_t__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ptw32_mcs_lock_release (int /*<<< orphan*/ *) ; 
 scalar_t__ ptw32_mcs_lock_try_acquire (scalar_t__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ptw32_mcs_node_transfer (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int ptw32_semwait (int /*<<< orphan*/ *) ; 
 int sem_destroy (int /*<<< orphan*/ *) ; 
 scalar_t__ sem_init (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int sem_post_multiple (int /*<<< orphan*/ *,int) ; 

int
pthread_barrier_init (pthread_barrier_t * barrier,
		      const pthread_barrierattr_t * attr, unsigned int count)
{
  pthread_barrier_t b;

  if (barrier == NULL || count == 0)
    {
      return EINVAL;
    }

  if (NULL != (b = (pthread_barrier_t) calloc (1, sizeof (*b))))
    {
      b->pshared = (attr != NULL && *attr != NULL
		    ? (*attr)->pshared : PTHREAD_PROCESS_PRIVATE);

      b->nCurrentBarrierHeight = b->nInitialBarrierHeight = count;
      b->lock = 0;

      if (0 == sem_init (&(b->semBarrierBreeched), b->pshared, 0))
	    {
	      *barrier = b;
	      return 0;
	    }
      (void) free (b);
    }

  return ENOMEM;
}

int
pthread_barrier_destroy (pthread_barrier_t * barrier)
{
  int result = 0;
  pthread_barrier_t b;
  ptw32_mcs_local_node_t node;

  if (barrier == NULL || *barrier == (pthread_barrier_t) PTW32_OBJECT_INVALID)
    {
      return EINVAL;
    }

  if (0 != ptw32_mcs_lock_try_acquire(&(*barrier)->lock, &node))
    {
      return EBUSY;
    }

  b = *barrier;

  if (b->nCurrentBarrierHeight < b->nInitialBarrierHeight)
    {
      result = EBUSY;
    }
  else
	{
      if (0 == (result = sem_destroy (&(b->semBarrierBreeched))))
        {
          *barrier = (pthread_barrier_t) PTW32_OBJECT_INVALID;
          /*
           * Release the lock before freeing b.
           *
           * FIXME: There may be successors which, when we release the lock,
           * will be linked into b->lock, which will be corrupted at some
           * point with undefined results for the application. To fix this
           * will require changing pthread_barrier_t from a pointer to
           * pthread_barrier_t_ to an instance. This is a change to the ABI
           * and will require a major version number increment.
           */
          ptw32_mcs_lock_release(&node);
	  (void) free (b);
	  return 0;
	}
      else
        {
          /*
           * This should not ever be reached.
           * Restore the barrier to working condition before returning.
           */
          (void) sem_init (&(b->semBarrierBreeched), b->pshared, 0);
        }

      if (result != 0)
        {
          /*
           * The barrier still exists and is valid
           * in the event of any error above.
           */
          result = EBUSY;
        }
    }

  ptw32_mcs_lock_release(&node);
  return (result);
}

int
pthread_barrier_wait (pthread_barrier_t * barrier)
{
  int result;
  pthread_barrier_t b;

  ptw32_mcs_local_node_t node;

  if (barrier == NULL || *barrier == (pthread_barrier_t) PTW32_OBJECT_INVALID)
    {
      return EINVAL;
    }

  ptw32_mcs_lock_acquire(&(*barrier)->lock, &node);

  b = *barrier;
  if (--b->nCurrentBarrierHeight == 0)
    {
      /*
       * We are the last thread to arrive at the barrier before it releases us.
       * Move our MCS local node to the global scope barrier handle so that the
       * last thread out (not necessarily us) can release the lock.
       */
      ptw32_mcs_node_transfer(&b->proxynode, &node);

      /*
       * Any threads that have not quite entered sem_wait below when the
       * multiple_post has completed will nevertheless continue through
       * the semaphore (barrier).
       */
      result = (b->nInitialBarrierHeight > 1
                ? sem_post_multiple (&(b->semBarrierBreeched),
				     b->nInitialBarrierHeight - 1) : 0);
    }
  else
    {
      ptw32_mcs_lock_release(&node);
      /*
       * Use the non-cancelable version of sem_wait().
       *
       * It is possible that all nInitialBarrierHeight-1 threads are
       * at this point when the last thread enters the barrier, resets
       * nCurrentBarrierHeight = nInitialBarrierHeight and leaves.
       * If pthread_barrier_destroy is called at that moment then the
       * barrier will be destroyed along with the semas.
       */
      result = ptw32_semwait (&(b->semBarrierBreeched));
    }

  if ((PTW32_INTERLOCKED_LONG)PTW32_INTERLOCKED_INCREMENT_LONG((PTW32_INTERLOCKED_LONGPTR)&b->nCurrentBarrierHeight)
		  == (PTW32_INTERLOCKED_LONG)b->nInitialBarrierHeight)
    {
      /*
       * We are the last thread to cross this barrier
       */
      ptw32_mcs_lock_release(&b->proxynode);
      if (0 == result)
        {
          result = PTHREAD_BARRIER_SERIAL_THREAD;
        }
    }

  return (result);
}

int
pthread_barrierattr_init (pthread_barrierattr_t * attr)
     /*
      * ------------------------------------------------------
      * DOCPUBLIC
      *      Initializes a barrier attributes object with default
      *      attributes.
      *
      * PARAMETERS
      *      attr
      *              pointer to an instance of pthread_barrierattr_t
      *
      *
      * DESCRIPTION
      *      Initializes a barrier attributes object with default
      *      attributes.
      *
      *      NOTES:
      *              1)      Used to define barrier types
      *
      * RESULTS
      *              0               successfully initialized attr,
      *              ENOMEM          insufficient memory for attr.
      *
      * ------------------------------------------------------
      */
{
  pthread_barrierattr_t ba;
  int result = 0;

  ba = (pthread_barrierattr_t) calloc (1, sizeof (*ba));

  if (ba == NULL)
    {
      result = ENOMEM;
    }
  else
    {
      ba->pshared = PTHREAD_PROCESS_PRIVATE;
    }

  *attr = ba;

  return (result);
}

int
pthread_barrierattr_destroy (pthread_barrierattr_t * attr)
     /*
      * ------------------------------------------------------
      * DOCPUBLIC
      *      Destroys a barrier attributes object. The object can
      *      no longer be used.
      *
      * PARAMETERS
      *      attr
      *              pointer to an instance of pthread_barrierattr_t
      *
      *
      * DESCRIPTION
      *      Destroys a barrier attributes object. The object can
      *      no longer be used.
      *
      *      NOTES:
      *              1)      Does not affect barrieres created using 'attr'
      *
      * RESULTS
      *              0               successfully released attr,
      *              EINVAL          'attr' is invalid.
      *
      * ------------------------------------------------------
      */
{
  int result = 0;

  if (attr == NULL || *attr == NULL)
    {
      result = EINVAL;
    }
  else
    {
      pthread_barrierattr_t ba = *attr;

      *attr = NULL;
      free (ba);
    }

  return (result);
}

int
pthread_barrierattr_getpshared (const pthread_barrierattr_t * attr,
				int *pshared)
     /*
      * ------------------------------------------------------
      * DOCPUBLIC
      *      Determine whether barriers created with 'attr' can be
      *      shared between processes.
      *
      * PARAMETERS
      *      attr
      *              pointer to an instance of pthread_barrierattr_t
      *
      *      pshared
      *              will be set to one of:
      *
      *                      PTHREAD_PROCESS_SHARED
      *                              May be shared if in shared memory
      *
      *                      PTHREAD_PROCESS_PRIVATE
      *                              Cannot be shared.
      *
      *
      * DESCRIPTION
      *      Mutexes creatd with 'attr' can be shared between
      *      processes if pthread_barrier_t variable is allocated
      *      in memory shared by these processes.
      *      NOTES:
      *              1)      pshared barriers MUST be allocated in shared
      *                      memory.
      *              2)      The following macro is defined if shared barriers
      *                      are supported:
      *                              _POSIX_THREAD_PROCESS_SHARED
      *
      * RESULTS
      *              0               successfully retrieved attribute,
      *              EINVAL          'attr' is invalid,
      *
      * ------------------------------------------------------
      */
{
  int result;

  if ((attr != NULL && *attr != NULL) && (pshared != NULL))
    {
      *pshared = (*attr)->pshared;
      result = 0;
    }
  else
    {
      result = EINVAL;
    }

  return (result);
}

int
pthread_barrierattr_setpshared (pthread_barrierattr_t * attr, int pshared)
     /*
      * ------------------------------------------------------
      * DOCPUBLIC
      *      Barriers created with 'attr' can be shared between
      *      processes if pthread_barrier_t variable is allocated
      *      in memory shared by these processes.
      *
      * PARAMETERS
      *      attr
      *              pointer to an instance of pthread_barrierattr_t
      *
      *      pshared
      *              must be one of:
      *
      *                      PTHREAD_PROCESS_SHARED
      *                              May be shared if in shared memory
      *
      *                      PTHREAD_PROCESS_PRIVATE
      *                              Cannot be shared.
      *
      * DESCRIPTION
      *      Mutexes creatd with 'attr' can be shared between
      *      processes if pthread_barrier_t variable is allocated
      *      in memory shared by these processes.
      *
      *      NOTES:
      *              1)      pshared barriers MUST be allocated in shared
      *                      memory.
      *
      *              2)      The following macro is defined if shared barriers
      *                      are supported:
      *                              _POSIX_THREAD_PROCESS_SHARED
      *
      * RESULTS
      *              0               successfully set attribute,
      *              EINVAL          'attr' or pshared is invalid,
      *              ENOSYS          PTHREAD_PROCESS_SHARED not supported,
      *
      * ------------------------------------------------------
      */
{
  int result;

  if ((attr != NULL && *attr != NULL) &&
      ((pshared == PTHREAD_PROCESS_SHARED) ||
       (pshared == PTHREAD_PROCESS_PRIVATE)))
    {
      if (pshared == PTHREAD_PROCESS_SHARED)
	{

#if !defined( _POSIX_THREAD_PROCESS_SHARED )

	  result = ENOSYS;
	  pshared = PTHREAD_PROCESS_PRIVATE;

#else

	  result = 0;

#endif /* _POSIX_THREAD_PROCESS_SHARED */

	}
      else
	{
	  result = 0;
	}

      (*attr)->pshared = pshared;
    }
  else
    {
      result = EINVAL;
    }

  return (result);

}

