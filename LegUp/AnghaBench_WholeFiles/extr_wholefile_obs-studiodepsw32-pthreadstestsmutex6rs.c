#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int /*<<< orphan*/  pthread_t ;

/* Variables and functions */
 scalar_t__ PTHREAD_RECURSIVE_MUTEX_INITIALIZER ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  exit (int /*<<< orphan*/ ) ; 
 int lockCount ; 
 scalar_t__ mutex ; 
 scalar_t__ pthread_create (int /*<<< orphan*/ *,int /*<<< orphan*/ *,void* (*) (void*),int /*<<< orphan*/ *) ; 
 scalar_t__ pthread_join (int /*<<< orphan*/ ,void**) ; 
 scalar_t__ pthread_mutex_destroy (scalar_t__*) ; 
 scalar_t__ pthread_mutex_lock (scalar_t__*) ; 
 scalar_t__ pthread_mutex_unlock (scalar_t__*) ; 

void * locker(void * arg)
{
  assert(pthread_mutex_lock(&mutex) == 0);
  lockCount++;
  assert(pthread_mutex_lock(&mutex) == 0);
  lockCount++;
  assert(pthread_mutex_unlock(&mutex) == 0);
  assert(pthread_mutex_unlock(&mutex) == 0);

  return (void *) 555;
}

int
main()
{
  pthread_t t;
  void* result = (void*)0;

  assert(mutex == PTHREAD_RECURSIVE_MUTEX_INITIALIZER);

  assert(pthread_create(&t, NULL, locker, NULL) == 0);

  assert(pthread_join(t, &result) == 0);
  assert((int)(size_t)result == 555);

  assert(lockCount == 2);

  assert(pthread_mutex_destroy(&mutex) == 0);

  exit(0);

  /* Never reached */
  return 0;
}

