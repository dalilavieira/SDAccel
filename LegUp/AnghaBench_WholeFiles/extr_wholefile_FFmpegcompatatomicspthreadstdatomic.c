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

/* Variables and functions */
 int /*<<< orphan*/  atomic_lock ; 
 void avpriv_atomic_lock () ; 
 void avpriv_atomic_unlock () ; 
 int /*<<< orphan*/  pthread_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void atomic_thread_fence(int order)
{
    avpriv_atomic_lock();
    avpriv_atomic_unlock();
}

__attribute__((used)) static inline void atomic_store(intptr_t *object, intptr_t desired)
{
    avpriv_atomic_lock();
    *object = desired;
    avpriv_atomic_unlock();
}

__attribute__((used)) static inline intptr_t atomic_load(intptr_t *object)
{
    intptr_t ret;
    avpriv_atomic_lock();
    ret = *object;
    avpriv_atomic_unlock();
    return ret;
}

__attribute__((used)) static inline intptr_t atomic_exchange(intptr_t *object, intptr_t desired)
{
    intptr_t ret;
    avpriv_atomic_lock();
    ret     = *object;
    *object = desired;
    avpriv_atomic_unlock();
    return ret;
}

__attribute__((used)) static inline int atomic_compare_exchange_strong(intptr_t *object, intptr_t *expected,
                                                 intptr_t desired)
{
    int ret;
    avpriv_atomic_lock();
    if (*object == *expected) {
        ret     = 1;
        *object = desired;
    } else {
        ret = 0;
        *expected = *object;
    }
    avpriv_atomic_unlock();
    return ret;
}

void avpriv_atomic_lock(void)
{
    pthread_mutex_lock(&atomic_lock);
}

void avpriv_atomic_unlock(void)
{
    pthread_mutex_unlock(&atomic_lock);
}

