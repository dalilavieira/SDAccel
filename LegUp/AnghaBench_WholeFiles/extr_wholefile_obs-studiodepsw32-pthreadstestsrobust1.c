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
typedef  int /*<<< orphan*/  pthread_mutexattr_t ;

/* Variables and functions */
 scalar_t__ ENOTRECOVERABLE ; 
 scalar_t__ EOWNERDEAD ; 
 scalar_t__ EPERM ; 
 int /*<<< orphan*/  PTHREAD_MUTEX_ERRORCHECK ; 
 int /*<<< orphan*/  PTHREAD_MUTEX_NORMAL ; 
 int /*<<< orphan*/  PTHREAD_MUTEX_RECURSIVE ; 
 int /*<<< orphan*/  PTHREAD_MUTEX_ROBUST ; 
 int /*<<< orphan*/  assert (int) ; 
 int lockCount ; 
 int /*<<< orphan*/  mutex ; 
 scalar_t__ pthread_create (int /*<<< orphan*/ *,int /*<<< orphan*/ *,void* (*) (void*),int /*<<< orphan*/ *) ; 
 scalar_t__ pthread_join (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ pthread_mutex_destroy (int /*<<< orphan*/ *) ; 
 scalar_t__ pthread_mutex_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ pthread_mutex_lock (int /*<<< orphan*/ *) ; 
 scalar_t__ pthread_mutex_unlock (int /*<<< orphan*/ *) ; 
 scalar_t__ pthread_mutexattr_destroy (int /*<<< orphan*/ *) ; 
 scalar_t__ pthread_mutexattr_init (int /*<<< orphan*/ *) ; 
 scalar_t__ pthread_mutexattr_setrobust (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ pthread_mutexattr_settype (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

void * owner(void * arg)
{
  assert(pthread_mutex_lock(&mutex) == 0);
  lockCount++;

  return 0;
}

void * inheritor(void * arg)
{
  assert(pthread_mutex_lock(&mutex) == EOWNERDEAD);
  lockCount++;
  assert(pthread_mutex_unlock(&mutex) == 0);

  return 0;
}

int
main()
{
  pthread_t to, ti;
  pthread_mutexattr_t ma;

  assert(pthread_mutexattr_init(&ma) == 0);
  assert(pthread_mutexattr_setrobust(&ma, PTHREAD_MUTEX_ROBUST) == 0);

  /* Default (NORMAL) type */ 
  lockCount = 0;
  assert(pthread_mutex_init(&mutex, &ma) == 0);
  assert(pthread_create(&to, NULL, owner, NULL) == 0);
  assert(pthread_join(to, NULL) == 0);
  assert(pthread_create(&ti, NULL, inheritor, NULL) == 0);
  assert(pthread_join(ti, NULL) == 0);
  assert(lockCount == 2);
  assert(pthread_mutex_lock(&mutex) == ENOTRECOVERABLE);
  assert(pthread_mutex_unlock(&mutex) == EPERM);
  assert(pthread_mutex_destroy(&mutex) == 0);

  /* NORMAL type */ 
  lockCount = 0;
  assert(pthread_mutexattr_settype(&ma, PTHREAD_MUTEX_NORMAL) == 0);
  assert(pthread_mutex_init(&mutex, &ma) == 0);
  assert(pthread_create(&to, NULL, owner, NULL) == 0);
  assert(pthread_join(to, NULL) == 0);
  assert(pthread_create(&ti, NULL, inheritor, NULL) == 0);
  assert(pthread_join(ti, NULL) == 0);
  assert(lockCount == 2);
  assert(pthread_mutex_lock(&mutex) == ENOTRECOVERABLE);
  assert(pthread_mutex_unlock(&mutex) == EPERM);
  assert(pthread_mutex_destroy(&mutex) == 0);

  /* ERRORCHECK type */ 
  lockCount = 0;
  assert(pthread_mutexattr_settype(&ma, PTHREAD_MUTEX_ERRORCHECK) == 0);
  assert(pthread_mutex_init(&mutex, &ma) == 0);
  assert(pthread_create(&to, NULL, owner, NULL) == 0);
  assert(pthread_join(to, NULL) == 0);
  assert(pthread_create(&ti, NULL, inheritor, NULL) == 0);
  assert(pthread_join(ti, NULL) == 0);
  assert(lockCount == 2);
  assert(pthread_mutex_lock(&mutex) == ENOTRECOVERABLE);
  assert(pthread_mutex_unlock(&mutex) == EPERM);
  assert(pthread_mutex_destroy(&mutex) == 0);

  /* RECURSIVE type */ 
  lockCount = 0;
  assert(pthread_mutexattr_settype(&ma, PTHREAD_MUTEX_RECURSIVE) == 0);
  assert(pthread_mutex_init(&mutex, &ma) == 0);
  assert(pthread_create(&to, NULL, owner, NULL) == 0);
  assert(pthread_join(to, NULL) == 0);
  assert(pthread_create(&ti, NULL, inheritor, NULL) == 0);
  assert(pthread_join(ti, NULL) == 0);
  assert(lockCount == 2);
  assert(pthread_mutex_lock(&mutex) == ENOTRECOVERABLE);
  assert(pthread_mutex_unlock(&mutex) == EPERM);
  assert(pthread_mutex_destroy(&mutex) == 0);

  assert(pthread_mutexattr_destroy(&ma) == 0);

  return 0;
}

