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
struct timespec {int dummy; } ;
typedef  int /*<<< orphan*/  ptw32_mcs_local_node_t ;
typedef  TYPE_1__* pthread_rwlockattr_t ;
typedef  TYPE_1__* pthread_rwlock_t ;
struct TYPE_20__ {scalar_t__ nSharedAccessCount; scalar_t__ nCompletedSharedAccessCount; scalar_t__ nExclusiveAccessCount; scalar_t__ nMagic; int pshared; int /*<<< orphan*/  mtxExclusiveAccess; int /*<<< orphan*/  mtxSharedAccessCompleted; int /*<<< orphan*/  cndSharedAccessCompleted; } ;

/* Variables and functions */
 int EBUSY ; 
 int EINVAL ; 
 int ENOMEM ; 
 int ENOSYS ; 
 int ETIMEDOUT ; 
 scalar_t__ INT_MAX ; 
 int PTHREAD_PROCESS_PRIVATE ; 
 int PTHREAD_PROCESS_SHARED ; 
 TYPE_1__* PTHREAD_RWLOCK_INITIALIZER ; 
 scalar_t__ PTW32_RWLOCK_MAGIC ; 
 scalar_t__ calloc (int,int) ; 
 int /*<<< orphan*/  free (TYPE_1__*) ; 
 int /*<<< orphan*/  pthread_cleanup_pop (int) ; 
 int /*<<< orphan*/  pthread_cleanup_push (void (*) (void*),void*) ; 
 int pthread_cond_destroy (int /*<<< orphan*/ *) ; 
 int pthread_cond_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int pthread_cond_signal (int /*<<< orphan*/ *) ; 
 int pthread_cond_timedwait (int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct timespec const*) ; 
 int pthread_cond_wait (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int pthread_mutex_destroy (int /*<<< orphan*/ *) ; 
 int pthread_mutex_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int pthread_mutex_lock (int /*<<< orphan*/ *) ; 
 int pthread_mutex_timedlock (int /*<<< orphan*/ *,struct timespec const*) ; 
 int pthread_mutex_trylock (int /*<<< orphan*/ *) ; 
 int pthread_mutex_unlock (int /*<<< orphan*/ *) ; 
 int pthread_rwlock_init (TYPE_1__**,TYPE_1__* const*) ; 
 int /*<<< orphan*/  ptw32_mcs_lock_acquire (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ptw32_mcs_lock_release (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ptw32_rwlock_test_init_lock ; 

int
ptw32_rwlock_check_need_init (pthread_rwlock_t * rwlock)
{
  int result = 0;
  ptw32_mcs_local_node_t node;

  /*
   * The following guarded test is specifically for statically
   * initialised rwlocks (via PTHREAD_RWLOCK_INITIALIZER).
   */
  ptw32_mcs_lock_acquire(&ptw32_rwlock_test_init_lock, &node);

  /*
   * We got here possibly under race
   * conditions. Check again inside the critical section
   * and only initialise if the rwlock is valid (not been destroyed).
   * If a static rwlock has been destroyed, the application can
   * re-initialise it only by calling pthread_rwlock_init()
   * explicitly.
   */
  if (*rwlock == PTHREAD_RWLOCK_INITIALIZER)
    {
      result = pthread_rwlock_init (rwlock, NULL);
    }
  else if (*rwlock == NULL)
    {
      /*
       * The rwlock has been destroyed while we were waiting to
       * initialise it, so the operation that caused the
       * auto-initialisation should fail.
       */
      result = EINVAL;
    }

  ptw32_mcs_lock_release(&node);

  return result;
}

void
ptw32_rwlock_cancelwrwait (void *arg)
{
  pthread_rwlock_t rwl = (pthread_rwlock_t) arg;

  rwl->nSharedAccessCount = -rwl->nCompletedSharedAccessCount;
  rwl->nCompletedSharedAccessCount = 0;

  (void) pthread_mutex_unlock (&(rwl->mtxSharedAccessCompleted));
  (void) pthread_mutex_unlock (&(rwl->mtxExclusiveAccess));
}

int
pthread_rwlock_init (pthread_rwlock_t * rwlock,
		     const pthread_rwlockattr_t * attr)
{
  int result;
  pthread_rwlock_t rwl = 0;

  if (rwlock == NULL)
    {
      return EINVAL;
    }

  if (attr != NULL && *attr != NULL)
    {
      result = EINVAL;		/* Not supported */
      goto DONE;
    }

  rwl = (pthread_rwlock_t) calloc (1, sizeof (*rwl));

  if (rwl == NULL)
    {
      result = ENOMEM;
      goto DONE;
    }

  rwl->nSharedAccessCount = 0;
  rwl->nExclusiveAccessCount = 0;
  rwl->nCompletedSharedAccessCount = 0;

  result = pthread_mutex_init (&rwl->mtxExclusiveAccess, NULL);
  if (result != 0)
    {
      goto FAIL0;
    }

  result = pthread_mutex_init (&rwl->mtxSharedAccessCompleted, NULL);
  if (result != 0)
    {
      goto FAIL1;
    }

  result = pthread_cond_init (&rwl->cndSharedAccessCompleted, NULL);
  if (result != 0)
    {
      goto FAIL2;
    }

  rwl->nMagic = PTW32_RWLOCK_MAGIC;

  result = 0;
  goto DONE;

FAIL2:
  (void) pthread_mutex_destroy (&(rwl->mtxSharedAccessCompleted));

FAIL1:
  (void) pthread_mutex_destroy (&(rwl->mtxExclusiveAccess));

FAIL0:
  (void) free (rwl);
  rwl = NULL;

DONE:
  *rwlock = rwl;

  return result;
}

int
pthread_rwlock_destroy (pthread_rwlock_t * rwlock)
{
  pthread_rwlock_t rwl;
  int result = 0, result1 = 0, result2 = 0;

  if (rwlock == NULL || *rwlock == NULL)
    {
      return EINVAL;
    }

  if (*rwlock != PTHREAD_RWLOCK_INITIALIZER)
    {
      rwl = *rwlock;

      if (rwl->nMagic != PTW32_RWLOCK_MAGIC)
	{
	  return EINVAL;
	}

      if ((result = pthread_mutex_lock (&(rwl->mtxExclusiveAccess))) != 0)
	{
	  return result;
	}

      if ((result =
	   pthread_mutex_lock (&(rwl->mtxSharedAccessCompleted))) != 0)
	{
	  (void) pthread_mutex_unlock (&(rwl->mtxExclusiveAccess));
	  return result;
	}

      /*
       * Check whether any threads own/wait for the lock (wait for ex.access);
       * report "BUSY" if so.
       */
      if (rwl->nExclusiveAccessCount > 0
	  || rwl->nSharedAccessCount > rwl->nCompletedSharedAccessCount)
	{
	  result = pthread_mutex_unlock (&(rwl->mtxSharedAccessCompleted));
	  result1 = pthread_mutex_unlock (&(rwl->mtxExclusiveAccess));
	  result2 = EBUSY;
	}
      else
	{
	  rwl->nMagic = 0;

	  if ((result =
	       pthread_mutex_unlock (&(rwl->mtxSharedAccessCompleted))) != 0)
	    {
	      pthread_mutex_unlock (&rwl->mtxExclusiveAccess);
	      return result;
	    }

	  if ((result =
	       pthread_mutex_unlock (&(rwl->mtxExclusiveAccess))) != 0)
	    {
	      return result;
	    }

	  *rwlock = NULL;	/* Invalidate rwlock before anything else */
	  result = pthread_cond_destroy (&(rwl->cndSharedAccessCompleted));
	  result1 = pthread_mutex_destroy (&(rwl->mtxSharedAccessCompleted));
	  result2 = pthread_mutex_destroy (&(rwl->mtxExclusiveAccess));
	  (void) free (rwl);
	}
    }
  else
    {
      ptw32_mcs_local_node_t node;
      /*
       * See notes in ptw32_rwlock_check_need_init() above also.
       */
      ptw32_mcs_lock_acquire(&ptw32_rwlock_test_init_lock, &node);

      /*
       * Check again.
       */
      if (*rwlock == PTHREAD_RWLOCK_INITIALIZER)
	{
	  /*
	   * This is all we need to do to destroy a statically
	   * initialised rwlock that has not yet been used (initialised).
	   * If we get to here, another thread
	   * waiting to initialise this rwlock will get an EINVAL.
	   */
	  *rwlock = NULL;
	}
      else
	{
	  /*
	   * The rwlock has been initialised while we were waiting
	   * so assume it's in use.
	   */
	  result = EBUSY;
	}

      ptw32_mcs_lock_release(&node);
    }

  return ((result != 0) ? result : ((result1 != 0) ? result1 : result2));
}

int
pthread_rwlockattr_init (pthread_rwlockattr_t * attr)
     /*
      * ------------------------------------------------------
      * DOCPUBLIC
      *      Initializes a rwlock attributes object with default
      *      attributes.
      *
      * PARAMETERS
      *      attr
      *              pointer to an instance of pthread_rwlockattr_t
      *
      *
      * DESCRIPTION
      *      Initializes a rwlock attributes object with default
      *      attributes.
      *
      * RESULTS
      *              0               successfully initialized attr,
      *              ENOMEM          insufficient memory for attr.
      *
      * ------------------------------------------------------
      */
{
  int result = 0;
  pthread_rwlockattr_t rwa;

  rwa = (pthread_rwlockattr_t) calloc (1, sizeof (*rwa));

  if (rwa == NULL)
    {
      result = ENOMEM;
    }
  else
    {
      rwa->pshared = PTHREAD_PROCESS_PRIVATE;
    }

  *attr = rwa;

  return (result);
}

int
pthread_rwlockattr_destroy (pthread_rwlockattr_t * attr)
     /*
      * ------------------------------------------------------
      * DOCPUBLIC
      *      Destroys a rwlock attributes object. The object can
      *      no longer be used.
      *
      * PARAMETERS
      *      attr
      *              pointer to an instance of pthread_rwlockattr_t
      *
      *
      * DESCRIPTION
      *      Destroys a rwlock attributes object. The object can
      *      no longer be used.
      *
      *      NOTES:
      *              1)      Does not affect rwlockss created using 'attr'
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
      pthread_rwlockattr_t rwa = *attr;

      *attr = NULL;
      free (rwa);
    }

  return (result);
}

int
pthread_rwlockattr_getpshared (const pthread_rwlockattr_t * attr,
			       int *pshared)
     /*
      * ------------------------------------------------------
      * DOCPUBLIC
      *      Determine whether rwlocks created with 'attr' can be
      *      shared between processes.
      *
      * PARAMETERS
      *      attr
      *              pointer to an instance of pthread_rwlockattr_t
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
      *      Rwlocks creatd with 'attr' can be shared between
      *      processes if pthread_rwlock_t variable is allocated
      *      in memory shared by these processes.
      *      NOTES:
      *              1)      pshared rwlocks MUST be allocated in shared
      *                      memory.
      *              2)      The following macro is defined if shared rwlocks
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
pthread_rwlockattr_setpshared (pthread_rwlockattr_t * attr, int pshared)
     /*
      * ------------------------------------------------------
      * DOCPUBLIC
      *      Rwlocks created with 'attr' can be shared between
      *      processes if pthread_rwlock_t variable is allocated
      *      in memory shared by these processes.
      *
      * PARAMETERS
      *      attr
      *              pointer to an instance of pthread_rwlockattr_t
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
      *      Rwlocks creatd with 'attr' can be shared between
      *      processes if pthread_rwlock_t variable is allocated
      *      in memory shared by these processes.
      *
      *      NOTES:
      *              1)      pshared rwlocks MUST be allocated in shared
      *                      memory.
      *
      *              2)      The following macro is defined if shared rwlocks
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

int
pthread_rwlock_rdlock (pthread_rwlock_t * rwlock)
{
  int result;
  pthread_rwlock_t rwl;

  if (rwlock == NULL || *rwlock == NULL)
    {
      return EINVAL;
    }

  /*
   * We do a quick check to see if we need to do more work
   * to initialise a static rwlock. We check
   * again inside the guarded section of ptw32_rwlock_check_need_init()
   * to avoid race conditions.
   */
  if (*rwlock == PTHREAD_RWLOCK_INITIALIZER)
    {
      result = ptw32_rwlock_check_need_init (rwlock);

      if (result != 0 && result != EBUSY)
	{
	  return result;
	}
    }

  rwl = *rwlock;

  if (rwl->nMagic != PTW32_RWLOCK_MAGIC)
    {
      return EINVAL;
    }

  if ((result = pthread_mutex_lock (&(rwl->mtxExclusiveAccess))) != 0)
    {
      return result;
    }

  if (++rwl->nSharedAccessCount == INT_MAX)
    {
      if ((result =
	   pthread_mutex_lock (&(rwl->mtxSharedAccessCompleted))) != 0)
	{
	  (void) pthread_mutex_unlock (&(rwl->mtxExclusiveAccess));
	  return result;
	}

      rwl->nSharedAccessCount -= rwl->nCompletedSharedAccessCount;
      rwl->nCompletedSharedAccessCount = 0;

      if ((result =
	   pthread_mutex_unlock (&(rwl->mtxSharedAccessCompleted))) != 0)
	{
	  (void) pthread_mutex_unlock (&(rwl->mtxExclusiveAccess));
	  return result;
	}
    }

  return (pthread_mutex_unlock (&(rwl->mtxExclusiveAccess)));
}

int
pthread_rwlock_timedrdlock (pthread_rwlock_t * rwlock,
			    const struct timespec *abstime)
{
  int result;
  pthread_rwlock_t rwl;

  if (rwlock == NULL || *rwlock == NULL)
    {
      return EINVAL;
    }

  /*
   * We do a quick check to see if we need to do more work
   * to initialise a static rwlock. We check
   * again inside the guarded section of ptw32_rwlock_check_need_init()
   * to avoid race conditions.
   */
  if (*rwlock == PTHREAD_RWLOCK_INITIALIZER)
    {
      result = ptw32_rwlock_check_need_init (rwlock);

      if (result != 0 && result != EBUSY)
	{
	  return result;
	}
    }

  rwl = *rwlock;

  if (rwl->nMagic != PTW32_RWLOCK_MAGIC)
    {
      return EINVAL;
    }

  if ((result =
       pthread_mutex_timedlock (&(rwl->mtxExclusiveAccess), abstime)) != 0)
    {
      return result;
    }

  if (++rwl->nSharedAccessCount == INT_MAX)
    {
      if ((result =
	   pthread_mutex_timedlock (&(rwl->mtxSharedAccessCompleted),
				    abstime)) != 0)
	{
	  if (result == ETIMEDOUT)
	    {
	      ++rwl->nCompletedSharedAccessCount;
	    }
	  (void) pthread_mutex_unlock (&(rwl->mtxExclusiveAccess));
	  return result;
	}

      rwl->nSharedAccessCount -= rwl->nCompletedSharedAccessCount;
      rwl->nCompletedSharedAccessCount = 0;

      if ((result =
	   pthread_mutex_unlock (&(rwl->mtxSharedAccessCompleted))) != 0)
	{
	  (void) pthread_mutex_unlock (&(rwl->mtxExclusiveAccess));
	  return result;
	}
    }

  return (pthread_mutex_unlock (&(rwl->mtxExclusiveAccess)));
}

int
pthread_rwlock_wrlock (pthread_rwlock_t * rwlock)
{
  int result;
  pthread_rwlock_t rwl;

  if (rwlock == NULL || *rwlock == NULL)
    {
      return EINVAL;
    }

  /*
   * We do a quick check to see if we need to do more work
   * to initialise a static rwlock. We check
   * again inside the guarded section of ptw32_rwlock_check_need_init()
   * to avoid race conditions.
   */
  if (*rwlock == PTHREAD_RWLOCK_INITIALIZER)
    {
      result = ptw32_rwlock_check_need_init (rwlock);

      if (result != 0 && result != EBUSY)
	{
	  return result;
	}
    }

  rwl = *rwlock;

  if (rwl->nMagic != PTW32_RWLOCK_MAGIC)
    {
      return EINVAL;
    }

  if ((result = pthread_mutex_lock (&(rwl->mtxExclusiveAccess))) != 0)
    {
      return result;
    }

  if ((result = pthread_mutex_lock (&(rwl->mtxSharedAccessCompleted))) != 0)
    {
      (void) pthread_mutex_unlock (&(rwl->mtxExclusiveAccess));
      return result;
    }

  if (rwl->nExclusiveAccessCount == 0)
    {
      if (rwl->nCompletedSharedAccessCount > 0)
	{
	  rwl->nSharedAccessCount -= rwl->nCompletedSharedAccessCount;
	  rwl->nCompletedSharedAccessCount = 0;
	}

      if (rwl->nSharedAccessCount > 0)
	{
	  rwl->nCompletedSharedAccessCount = -rwl->nSharedAccessCount;

	  /*
	   * This routine may be a cancelation point
	   * according to POSIX 1003.1j section 18.1.2.
	   */
#if defined(_MSC_VER) && _MSC_VER < 1400
#pragma inline_depth(0)
#endif
	  pthread_cleanup_push (ptw32_rwlock_cancelwrwait, (void *) rwl);

	  do
	    {
	      result = pthread_cond_wait (&(rwl->cndSharedAccessCompleted),
					  &(rwl->mtxSharedAccessCompleted));
	    }
	  while (result == 0 && rwl->nCompletedSharedAccessCount < 0);

	  pthread_cleanup_pop ((result != 0) ? 1 : 0);
#if defined(_MSC_VER) && _MSC_VER < 1400
#pragma inline_depth()
#endif

	  if (result == 0)
	    {
	      rwl->nSharedAccessCount = 0;
	    }
	}
    }

  if (result == 0)
    {
      rwl->nExclusiveAccessCount++;
    }

  return result;
}

int
pthread_rwlock_timedwrlock (pthread_rwlock_t * rwlock,
			    const struct timespec *abstime)
{
  int result;
  pthread_rwlock_t rwl;

  if (rwlock == NULL || *rwlock == NULL)
    {
      return EINVAL;
    }

  /*
   * We do a quick check to see if we need to do more work
   * to initialise a static rwlock. We check
   * again inside the guarded section of ptw32_rwlock_check_need_init()
   * to avoid race conditions.
   */
  if (*rwlock == PTHREAD_RWLOCK_INITIALIZER)
    {
      result = ptw32_rwlock_check_need_init (rwlock);

      if (result != 0 && result != EBUSY)
	{
	  return result;
	}
    }

  rwl = *rwlock;

  if (rwl->nMagic != PTW32_RWLOCK_MAGIC)
    {
      return EINVAL;
    }

  if ((result =
       pthread_mutex_timedlock (&(rwl->mtxExclusiveAccess), abstime)) != 0)
    {
      return result;
    }

  if ((result =
       pthread_mutex_timedlock (&(rwl->mtxSharedAccessCompleted),
				abstime)) != 0)
    {
      (void) pthread_mutex_unlock (&(rwl->mtxExclusiveAccess));
      return result;
    }

  if (rwl->nExclusiveAccessCount == 0)
    {
      if (rwl->nCompletedSharedAccessCount > 0)
	{
	  rwl->nSharedAccessCount -= rwl->nCompletedSharedAccessCount;
	  rwl->nCompletedSharedAccessCount = 0;
	}

      if (rwl->nSharedAccessCount > 0)
	{
	  rwl->nCompletedSharedAccessCount = -rwl->nSharedAccessCount;

	  /*
	   * This routine may be a cancelation point
	   * according to POSIX 1003.1j section 18.1.2.
	   */
#if defined(_MSC_VER) && _MSC_VER < 1400
#pragma inline_depth(0)
#endif
	  pthread_cleanup_push (ptw32_rwlock_cancelwrwait, (void *) rwl);

	  do
	    {
	      result =
		pthread_cond_timedwait (&(rwl->cndSharedAccessCompleted),
					&(rwl->mtxSharedAccessCompleted),
					abstime);
	    }
	  while (result == 0 && rwl->nCompletedSharedAccessCount < 0);

	  pthread_cleanup_pop ((result != 0) ? 1 : 0);
#if defined(_MSC_VER) && _MSC_VER < 1400
#pragma inline_depth()
#endif

	  if (result == 0)
	    {
	      rwl->nSharedAccessCount = 0;
	    }
	}
    }

  if (result == 0)
    {
      rwl->nExclusiveAccessCount++;
    }

  return result;
}

int
pthread_rwlock_unlock (pthread_rwlock_t * rwlock)
{
  int result, result1;
  pthread_rwlock_t rwl;

  if (rwlock == NULL || *rwlock == NULL)
    {
      return (EINVAL);
    }

  if (*rwlock == PTHREAD_RWLOCK_INITIALIZER)
    {
      /*
       * Assume any race condition here is harmless.
       */
      return 0;
    }

  rwl = *rwlock;

  if (rwl->nMagic != PTW32_RWLOCK_MAGIC)
    {
      return EINVAL;
    }

  if (rwl->nExclusiveAccessCount == 0)
    {
      if ((result =
	   pthread_mutex_lock (&(rwl->mtxSharedAccessCompleted))) != 0)
	{
	  return result;
	}

      if (++rwl->nCompletedSharedAccessCount == 0)
	{
	  result = pthread_cond_signal (&(rwl->cndSharedAccessCompleted));
	}

      result1 = pthread_mutex_unlock (&(rwl->mtxSharedAccessCompleted));
    }
  else
    {
      rwl->nExclusiveAccessCount--;

      result = pthread_mutex_unlock (&(rwl->mtxSharedAccessCompleted));
      result1 = pthread_mutex_unlock (&(rwl->mtxExclusiveAccess));

    }

  return ((result != 0) ? result : result1);
}

int
pthread_rwlock_tryrdlock (pthread_rwlock_t * rwlock)
{
  int result;
  pthread_rwlock_t rwl;

  if (rwlock == NULL || *rwlock == NULL)
    {
      return EINVAL;
    }

  /*
   * We do a quick check to see if we need to do more work
   * to initialise a static rwlock. We check
   * again inside the guarded section of ptw32_rwlock_check_need_init()
   * to avoid race conditions.
   */
  if (*rwlock == PTHREAD_RWLOCK_INITIALIZER)
    {
      result = ptw32_rwlock_check_need_init (rwlock);

      if (result != 0 && result != EBUSY)
	{
	  return result;
	}
    }

  rwl = *rwlock;

  if (rwl->nMagic != PTW32_RWLOCK_MAGIC)
    {
      return EINVAL;
    }

  if ((result = pthread_mutex_trylock (&(rwl->mtxExclusiveAccess))) != 0)
    {
      return result;
    }

  if (++rwl->nSharedAccessCount == INT_MAX)
    {
      if ((result =
	   pthread_mutex_lock (&(rwl->mtxSharedAccessCompleted))) != 0)
	{
	  (void) pthread_mutex_unlock (&(rwl->mtxExclusiveAccess));
	  return result;
	}

      rwl->nSharedAccessCount -= rwl->nCompletedSharedAccessCount;
      rwl->nCompletedSharedAccessCount = 0;

      if ((result =
	   pthread_mutex_unlock (&(rwl->mtxSharedAccessCompleted))) != 0)
	{
	  (void) pthread_mutex_unlock (&(rwl->mtxExclusiveAccess));
	  return result;
	}
    }

  return (pthread_mutex_unlock (&rwl->mtxExclusiveAccess));
}

int
pthread_rwlock_trywrlock (pthread_rwlock_t * rwlock)
{
  int result, result1;
  pthread_rwlock_t rwl;

  if (rwlock == NULL || *rwlock == NULL)
    {
      return EINVAL;
    }

  /*
   * We do a quick check to see if we need to do more work
   * to initialise a static rwlock. We check
   * again inside the guarded section of ptw32_rwlock_check_need_init()
   * to avoid race conditions.
   */
  if (*rwlock == PTHREAD_RWLOCK_INITIALIZER)
    {
      result = ptw32_rwlock_check_need_init (rwlock);

      if (result != 0 && result != EBUSY)
	{
	  return result;
	}
    }

  rwl = *rwlock;

  if (rwl->nMagic != PTW32_RWLOCK_MAGIC)
    {
      return EINVAL;
    }

  if ((result = pthread_mutex_trylock (&(rwl->mtxExclusiveAccess))) != 0)
    {
      return result;
    }

  if ((result =
       pthread_mutex_trylock (&(rwl->mtxSharedAccessCompleted))) != 0)
    {
      result1 = pthread_mutex_unlock (&(rwl->mtxExclusiveAccess));
      return ((result1 != 0) ? result1 : result);
    }

  if (rwl->nExclusiveAccessCount == 0)
    {
      if (rwl->nCompletedSharedAccessCount > 0)
	{
	  rwl->nSharedAccessCount -= rwl->nCompletedSharedAccessCount;
	  rwl->nCompletedSharedAccessCount = 0;
	}

      if (rwl->nSharedAccessCount > 0)
	{
	  if ((result =
	       pthread_mutex_unlock (&(rwl->mtxSharedAccessCompleted))) != 0)
	    {
	      (void) pthread_mutex_unlock (&(rwl->mtxExclusiveAccess));
	      return result;
	    }

	  if ((result =
	       pthread_mutex_unlock (&(rwl->mtxExclusiveAccess))) == 0)
	    {
	      result = EBUSY;
	    }
	}
      else
	{
	  rwl->nExclusiveAccessCount = 1;
	}
    }
  else
    {
      result = EBUSY;
    }

  return result;
}

