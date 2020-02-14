#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  ptw32_mcs_local_node_t ;
typedef  TYPE_1__* pthread_rwlock_t ;
struct TYPE_5__ {scalar_t__ nMagic; scalar_t__ nExclusiveAccessCount; scalar_t__ nSharedAccessCount; scalar_t__ nCompletedSharedAccessCount; int /*<<< orphan*/  mtxExclusiveAccess; int /*<<< orphan*/  mtxSharedAccessCompleted; int /*<<< orphan*/  cndSharedAccessCompleted; } ;

/* Variables and functions */
 int EBUSY ; 
 int EINVAL ; 
 TYPE_1__* PTHREAD_RWLOCK_INITIALIZER ; 
 scalar_t__ PTW32_RWLOCK_MAGIC ; 
 int /*<<< orphan*/  free (TYPE_1__*) ; 
 int pthread_cond_destroy (int /*<<< orphan*/ *) ; 
 int pthread_mutex_destroy (int /*<<< orphan*/ *) ; 
 int pthread_mutex_lock (int /*<<< orphan*/ *) ; 
 int pthread_mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ptw32_mcs_lock_acquire (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ptw32_mcs_lock_release (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ptw32_rwlock_test_init_lock ; 

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

