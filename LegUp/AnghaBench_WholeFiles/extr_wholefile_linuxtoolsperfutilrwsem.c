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
struct rw_semaphore {int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 void* calloc (int,size_t) ; 
 scalar_t__ perf_singlethreaded ; 
 int pthread_rwlock_destroy (int /*<<< orphan*/ *) ; 
 int pthread_rwlock_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int pthread_rwlock_rdlock (int /*<<< orphan*/ *) ; 
 int pthread_rwlock_unlock (int /*<<< orphan*/ *) ; 
 int pthread_rwlock_wrlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void *zalloc(size_t size)
{
	return calloc(1, size);
}

int init_rwsem(struct rw_semaphore *sem)
{
	return pthread_rwlock_init(&sem->lock, NULL);
}

int exit_rwsem(struct rw_semaphore *sem)
{
	return pthread_rwlock_destroy(&sem->lock);
}

int down_read(struct rw_semaphore *sem)
{
	return perf_singlethreaded ? 0 : pthread_rwlock_rdlock(&sem->lock);
}

int up_read(struct rw_semaphore *sem)
{
	return perf_singlethreaded ? 0 : pthread_rwlock_unlock(&sem->lock);
}

int down_write(struct rw_semaphore *sem)
{
	return perf_singlethreaded ? 0 : pthread_rwlock_wrlock(&sem->lock);
}

int up_write(struct rw_semaphore *sem)
{
	return perf_singlethreaded ? 0 : pthread_rwlock_unlock(&sem->lock);
}

