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
typedef  int /*<<< orphan*/  uv_handle_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 scalar_t__ UV_EBUSY ; 
 int /*<<< orphan*/  condvar ; 
 int /*<<< orphan*/  mutex ; 
 int /*<<< orphan*/  rwlock ; 
 int step ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_cond_signal (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_cond_wait (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_is_closing (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_rwlock_rdunlock (int /*<<< orphan*/ *) ; 
 scalar_t__ uv_rwlock_tryrdlock (int /*<<< orphan*/ *) ; 
 scalar_t__ uv_rwlock_trywrlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_rwlock_wrunlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static void synchronize_nowait(void) {
  step += 1;
  uv_cond_signal(&condvar);
}

__attribute__((used)) static void synchronize(void) {
  int current;

  synchronize_nowait();
  /* Wait for the other thread.  Guard against spurious wakeups. */
  for (current = step; current == step; uv_cond_wait(&condvar, &mutex));
  ASSERT(step == current + 1);
}

__attribute__((used)) static void thread_rwlock_trylock_peer(void* unused) {
  (void) &unused;

  uv_mutex_lock(&mutex);

  /* Write lock held by other thread. */
  ASSERT(UV_EBUSY == uv_rwlock_tryrdlock(&rwlock));
  ASSERT(UV_EBUSY == uv_rwlock_trywrlock(&rwlock));
  synchronize();

  /* Read lock held by other thread. */
  ASSERT(0 == uv_rwlock_tryrdlock(&rwlock));
  uv_rwlock_rdunlock(&rwlock);
  ASSERT(UV_EBUSY == uv_rwlock_trywrlock(&rwlock));
  synchronize();

  /* Acquire write lock. */
  ASSERT(0 == uv_rwlock_trywrlock(&rwlock));
  synchronize();

  /* Release write lock and acquire read lock. */
  uv_rwlock_wrunlock(&rwlock);
  ASSERT(0 == uv_rwlock_tryrdlock(&rwlock));
  synchronize();

  uv_rwlock_rdunlock(&rwlock);
  synchronize_nowait();  /* Signal main thread we're going away. */
  uv_mutex_unlock(&mutex);
}

