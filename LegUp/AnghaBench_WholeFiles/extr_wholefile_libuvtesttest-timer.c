#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
struct TYPE_13__ {scalar_t__ data; } ;
typedef  TYPE_1__ uv_timer_t ;
typedef  int /*<<< orphan*/  uv_handle_t ;
typedef  scalar_t__ uint64_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int /*<<< orphan*/  FATAL (char*) ; 
 TYPE_1__ huge_timer1 ; 
 int /*<<< orphan*/  huge_timer2 ; 
 int once_cb_called ; 
 int /*<<< orphan*/  once_close_cb_called ; 
 int /*<<< orphan*/  order_cb_called ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int repeat_cb_called ; 
 int /*<<< orphan*/  repeat_close_cb_called ; 
 scalar_t__ timer_early_check_expected_time ; 
 int /*<<< orphan*/  timer_run_once_timer_cb_called ; 
 TYPE_1__ tiny_timer ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *)) ; 
 int /*<<< orphan*/  uv_default_loop () ; 
 int uv_hrtime () ; 
 int uv_is_active (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_is_closing (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_update_time (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static void once_close_cb(uv_handle_t* handle) {
  printf("ONCE_CLOSE_CB\n");

  ASSERT(handle != NULL);
  ASSERT(0 == uv_is_active(handle));

  once_close_cb_called++;
}

__attribute__((used)) static void once_cb(uv_timer_t* handle) {
  printf("ONCE_CB %d\n", once_cb_called);

  ASSERT(handle != NULL);
  ASSERT(0 == uv_is_active((uv_handle_t*) handle));

  once_cb_called++;

  uv_close((uv_handle_t*)handle, once_close_cb);

  /* Just call this randomly for the code coverage. */
  uv_update_time(uv_default_loop());
}

__attribute__((used)) static void repeat_close_cb(uv_handle_t* handle) {
  printf("REPEAT_CLOSE_CB\n");

  ASSERT(handle != NULL);

  repeat_close_cb_called++;
}

__attribute__((used)) static void repeat_cb(uv_timer_t* handle) {
  printf("REPEAT_CB\n");

  ASSERT(handle != NULL);
  ASSERT(1 == uv_is_active((uv_handle_t*) handle));

  repeat_cb_called++;

  if (repeat_cb_called == 5) {
    uv_close((uv_handle_t*)handle, repeat_close_cb);
  }
}

__attribute__((used)) static void never_cb(uv_timer_t* handle) {
  FATAL("never_cb should never be called");
}

__attribute__((used)) static void order_cb_a(uv_timer_t *handle) {
  ASSERT(order_cb_called++ == *(int*)handle->data);
}

__attribute__((used)) static void order_cb_b(uv_timer_t *handle) {
  ASSERT(order_cb_called++ == *(int*)handle->data);
}

__attribute__((used)) static void tiny_timer_cb(uv_timer_t* handle) {
  ASSERT(handle == &tiny_timer);
  uv_close((uv_handle_t*) &tiny_timer, NULL);
  uv_close((uv_handle_t*) &huge_timer1, NULL);
  uv_close((uv_handle_t*) &huge_timer2, NULL);
}

__attribute__((used)) static void huge_repeat_cb(uv_timer_t* handle) {
  static int ncalls;

  if (ncalls == 0)
    ASSERT(handle == &huge_timer1);
  else
    ASSERT(handle == &tiny_timer);

  if (++ncalls == 10) {
    uv_close((uv_handle_t*) &tiny_timer, NULL);
    uv_close((uv_handle_t*) &huge_timer1, NULL);
  }
}

__attribute__((used)) static void timer_run_once_timer_cb(uv_timer_t* handle) {
  timer_run_once_timer_cb_called++;
}

__attribute__((used)) static void timer_early_check_cb(uv_timer_t* handle) {
  uint64_t hrtime = uv_hrtime() / 1000000;
  ASSERT(hrtime >= timer_early_check_expected_time);
}

