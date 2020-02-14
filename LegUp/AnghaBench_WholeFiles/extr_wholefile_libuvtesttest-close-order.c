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
typedef  int /*<<< orphan*/  uv_handle_t ;
typedef  int /*<<< orphan*/  uv_check_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 scalar_t__ check_cb_called ; 
 scalar_t__ close_cb_called ; 
 int timer_cb_called ; 
 int /*<<< orphan*/  timer_handle2 ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,...) ; 
 int /*<<< orphan*/  uv_is_closing (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static void close_cb(uv_handle_t* handle) {
  ASSERT(handle != NULL);
  close_cb_called++;
}

__attribute__((used)) static void check_cb(uv_check_t* handle) {
  ASSERT(check_cb_called == 0);
  ASSERT(timer_cb_called == 1);
  ASSERT(close_cb_called == 0);
  uv_close((uv_handle_t*) handle, close_cb);
  uv_close((uv_handle_t*) &timer_handle2, close_cb);
  check_cb_called++;
}

__attribute__((used)) static void timer_cb(uv_timer_t* handle) {
  uv_close((uv_handle_t*) handle, close_cb);
  timer_cb_called++;
}

