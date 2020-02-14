#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uv_timer_t ;
typedef  int /*<<< orphan*/  uv_loop_t ;
struct TYPE_6__ {int /*<<< orphan*/ * loop; } ;
typedef  TYPE_1__ uv_idle_t ;
typedef  int /*<<< orphan*/  uv_handle_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int idle_cb_called ; 
 int /*<<< orphan*/  idle_handle ; 
 scalar_t__ timer_cb_called ; 
 int /*<<< orphan*/  timer_handle ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_idle_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_idle_start (int /*<<< orphan*/ *,void (*) (TYPE_1__*)) ; 
 int /*<<< orphan*/  uv_idle_stop (TYPE_1__*) ; 
 int /*<<< orphan*/  uv_is_closing (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_timer_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_timer_start (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *),int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uv_timer_stop (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static void idle_cb(uv_idle_t* handle) {
  ASSERT(idle_cb_called == 0);
  ASSERT(timer_cb_called == 0);
  uv_idle_stop(handle);
  idle_cb_called++;
}

__attribute__((used)) static void timer_cb(uv_timer_t* handle) {
  ASSERT(idle_cb_called == 1);
  ASSERT(timer_cb_called == 0);
  uv_timer_stop(handle);
  timer_cb_called++;
}

__attribute__((used)) static void next_tick(uv_idle_t* handle) {
  uv_loop_t* loop = handle->loop;
  uv_idle_stop(handle);
  uv_idle_init(loop, &idle_handle);
  uv_idle_start(&idle_handle, idle_cb);
  uv_timer_init(loop, &timer_handle);
  uv_timer_start(&timer_handle, timer_cb, 0, 0);
}

