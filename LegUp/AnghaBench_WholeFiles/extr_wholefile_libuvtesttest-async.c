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
typedef  int /*<<< orphan*/  uv_prepare_t ;
typedef  int /*<<< orphan*/  uv_handle_t ;
typedef  int /*<<< orphan*/  uv_async_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int /*<<< orphan*/  async ; 
 int async_cb_called ; 
 int /*<<< orphan*/  close_cb_called ; 
 int /*<<< orphan*/  mutex ; 
 int /*<<< orphan*/  prepare ; 
 int /*<<< orphan*/  prepare_cb_called ; 
 int /*<<< orphan*/  thread ; 
 int uv_async_send (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,...) ; 
 int /*<<< orphan*/  uv_is_closing (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_sleep (int /*<<< orphan*/ ) ; 
 int uv_thread_create (int /*<<< orphan*/ *,void (*) (void*),int /*<<< orphan*/ *) ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static void thread_cb(void *arg) {
  int n;
  int r;

  for (;;) {
    uv_mutex_lock(&mutex);
    n = async_cb_called;
    uv_mutex_unlock(&mutex);

    if (n == 3) {
      break;
    }

    r = uv_async_send(&async);
    ASSERT(r == 0);

    /* Work around a bug in Valgrind.
     *
     * Valgrind runs threads not in parallel but sequentially, i.e. one after
     * the other. It also doesn't preempt them, instead it depends on threads
     * yielding voluntarily by making a syscall.
     *
     * That never happens here: the pipe that is associated with the async
     * handle is written to once but that's too early for Valgrind's scheduler
     * to kick in. Afterwards, the thread busy-loops, starving the main thread.
     * Therefore, we yield.
     *
     * This behavior has been observed with Valgrind 3.7.0 and 3.9.0.
     */
    uv_sleep(0);
  }
}

__attribute__((used)) static void close_cb(uv_handle_t* handle) {
  ASSERT(handle != NULL);
  close_cb_called++;
}

__attribute__((used)) static void async_cb(uv_async_t* handle) {
  int n;

  ASSERT(handle == &async);

  uv_mutex_lock(&mutex);
  n = ++async_cb_called;
  uv_mutex_unlock(&mutex);

  if (n == 3) {
    uv_close((uv_handle_t*)&async, close_cb);
    uv_close((uv_handle_t*)&prepare, close_cb);
  }
}

__attribute__((used)) static void prepare_cb(uv_prepare_t* handle) {
  int r;

  ASSERT(handle == &prepare);

  if (prepare_cb_called++)
    return;

  r = uv_thread_create(&thread, thread_cb, NULL);
  ASSERT(r == 0);
  uv_mutex_unlock(&mutex);
}

