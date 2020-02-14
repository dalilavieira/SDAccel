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
typedef  int /*<<< orphan*/  uv_idle_t ;
typedef  int /*<<< orphan*/  uv_handle_t ;

/* Variables and functions */
 scalar_t__ NUM_TICKS ; 
 int /*<<< orphan*/  idle_handle ; 
 scalar_t__ ticks ; 
 int /*<<< orphan*/  timer_handle ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_idle_stop (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_is_closing (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_timer_stop (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static void idle_cb(uv_idle_t* handle) {
  if (++ticks == NUM_TICKS)
    uv_idle_stop(handle);
}

__attribute__((used)) static void idle2_cb(uv_idle_t* handle) {
  ticks++;
}

__attribute__((used)) static void timer_cb(uv_timer_t* handle) {
  uv_idle_stop(&idle_handle);
  uv_timer_stop(&timer_handle);
}

