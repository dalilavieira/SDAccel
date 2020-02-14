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
typedef  int /*<<< orphan*/  uv_check_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int check_cb_called ; 
 int /*<<< orphan*/  check_handle ; 
 int prepare_cb_called ; 
 int /*<<< orphan*/  prepare_handle ; 
 scalar_t__ timer_cb_called ; 
 int /*<<< orphan*/  timer_handle ; 
 scalar_t__ uv_check_stop (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_is_closing (int /*<<< orphan*/ *) ; 
 scalar_t__ uv_prepare_start (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *)) ; 
 scalar_t__ uv_prepare_stop (int /*<<< orphan*/ *) ; 
 scalar_t__ uv_timer_start (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *),int,int /*<<< orphan*/ ) ; 
 scalar_t__ uv_timer_stop (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static void prepare_cb(uv_prepare_t* handle) {
  ASSERT(0 == uv_prepare_stop(&prepare_handle));
  ASSERT(0 == prepare_cb_called);
  ASSERT(1 == check_cb_called);
  ASSERT(0 == timer_cb_called);
  prepare_cb_called++;
}

__attribute__((used)) static void timer_cb(uv_timer_t* handle) {
  ASSERT(0 == uv_timer_stop(&timer_handle));
  ASSERT(1 == prepare_cb_called);
  ASSERT(1 == check_cb_called);
  ASSERT(0 == timer_cb_called);
  timer_cb_called++;
}

__attribute__((used)) static void check_cb(uv_check_t* handle) {
  ASSERT(0 == uv_check_stop(&check_handle));
  ASSERT(0 == uv_timer_stop(&timer_handle));  /* Runs before timer_cb. */
  ASSERT(0 == uv_timer_start(&timer_handle, timer_cb, 50, 0));
  ASSERT(0 == uv_prepare_start(&prepare_handle, prepare_cb));
  ASSERT(0 == prepare_cb_called);
  ASSERT(0 == check_cb_called);
  ASSERT(0 == timer_cb_called);
  check_cb_called++;
}

