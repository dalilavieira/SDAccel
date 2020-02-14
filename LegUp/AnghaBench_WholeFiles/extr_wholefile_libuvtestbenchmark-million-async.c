#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uv_timer_t ;
typedef  int /*<<< orphan*/  uv_handle_t ;
struct TYPE_6__ {struct TYPE_6__* data; } ;
typedef  TYPE_1__ uv_async_t ;
struct TYPE_7__ {int /*<<< orphan*/  handles_seen; TYPE_1__* async_handles; int /*<<< orphan*/  async_events; } ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (TYPE_1__*) ; 
 int /*<<< orphan*/  ASSERT (int) ; 
 TYPE_3__* container ; 
 int done ; 
 int /*<<< orphan*/  thread_id ; 
 int /*<<< orphan*/  uv_async_send (TYPE_1__*) ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_is_closing (int /*<<< orphan*/ *) ; 
 scalar_t__ uv_thread_join (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static unsigned fastrand(void) {
  static unsigned g = 0;
  g = g * 214013 + 2531011;
  return g;
}

__attribute__((used)) static void thread_cb(void* arg) {
  unsigned i;

  while (done == 0) {
    i = fastrand() % ARRAY_SIZE(container->async_handles);
    uv_async_send(container->async_handles + i);
  }
}

__attribute__((used)) static void async_cb(uv_async_t* handle) {
  container->async_events++;
  handle->data = handle;
}

__attribute__((used)) static void timer_cb(uv_timer_t* handle) {
  unsigned i;

  done = 1;
  ASSERT(0 == uv_thread_join(&thread_id));

  for (i = 0; i < ARRAY_SIZE(container->async_handles); i++) {
    uv_async_t* handle = container->async_handles + i;

    if (handle->data != NULL)
      container->handles_seen++;

    uv_close((uv_handle_t*) handle, NULL);
  }

  uv_close((uv_handle_t*) handle, NULL);
}

