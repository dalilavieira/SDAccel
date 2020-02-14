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
typedef  int /*<<< orphan*/  uv_timer_t ;
typedef  int /*<<< orphan*/  uv_prepare_t ;
typedef  int /*<<< orphan*/  uv_handle_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int num_ticks ; 
 int prepare_called ; 
 int /*<<< orphan*/  prepare_handle ; 
 int timer_called ; 
 int /*<<< orphan*/  timer_handle ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_default_loop () ; 
 int /*<<< orphan*/  uv_is_closing (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_prepare_stop (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_stop (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uv_timer_stop (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static void prepare_cb(uv_prepare_t* handle) {
  ASSERT(handle == &prepare_handle);
  prepare_called++;
  if (prepare_called == num_ticks)
    uv_prepare_stop(handle);
}

__attribute__((used)) static void timer_cb(uv_timer_t* handle) {
  ASSERT(handle == &timer_handle);
  timer_called++;
  if (timer_called == 1)
    uv_stop(uv_default_loop());
  else if (timer_called == num_ticks)
    uv_timer_stop(handle);
}

