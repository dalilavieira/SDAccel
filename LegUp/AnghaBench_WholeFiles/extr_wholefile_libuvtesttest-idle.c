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
typedef  int /*<<< orphan*/  uv_check_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int check_cb_called ; 
 int /*<<< orphan*/  check_handle ; 
 int /*<<< orphan*/  close_cb_called ; 
 int /*<<< orphan*/  fflush (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,int) ; 
 int idle_cb_called ; 
 int /*<<< orphan*/  idle_handle ; 
 int /*<<< orphan*/  stderr ; 
 int timer_cb_called ; 
 int /*<<< orphan*/  timer_handle ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,...) ; 
 int /*<<< orphan*/  uv_is_closing (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static void close_cb(uv_handle_t* handle) {
  close_cb_called++;
}

__attribute__((used)) static void timer_cb(uv_timer_t* handle) {
  ASSERT(handle == &timer_handle);

  uv_close((uv_handle_t*) &idle_handle, close_cb);
  uv_close((uv_handle_t*) &check_handle, close_cb);
  uv_close((uv_handle_t*) &timer_handle, close_cb);

  timer_cb_called++;
  fprintf(stderr, "timer_cb %d\n", timer_cb_called);
  fflush(stderr);
}

__attribute__((used)) static void idle_cb(uv_idle_t* handle) {
  ASSERT(handle == &idle_handle);

  idle_cb_called++;
  fprintf(stderr, "idle_cb %d\n", idle_cb_called);
  fflush(stderr);
}

__attribute__((used)) static void check_cb(uv_check_t* handle) {
  ASSERT(handle == &check_handle);

  check_cb_called++;
  fprintf(stderr, "check_cb %d\n", check_cb_called);
  fflush(stderr);
}

