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
typedef  int /*<<< orphan*/  uv_connect_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int UV_ECANCELED ; 
 int UV_ENETUNREACH ; 
 int /*<<< orphan*/  close_cb_called ; 
 int /*<<< orphan*/  connect_cb_called ; 
 int /*<<< orphan*/  netunreach_errors ; 
 int /*<<< orphan*/  tcp_handle ; 
 int /*<<< orphan*/  timer1_cb_called ; 
 int /*<<< orphan*/  timer2_handle ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,...) ; 
 int /*<<< orphan*/  uv_is_closing (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_timer_stop (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static void close_cb(uv_handle_t* handle) {
  close_cb_called++;
}

__attribute__((used)) static void connect_cb(uv_connect_t* req, int status) {
  /* The expected error is UV_ECANCELED but the test tries to connect to what
   * is basically an arbitrary address in the expectation that no network path
   * exists, so UV_ENETUNREACH is an equally plausible outcome.
   */
  ASSERT(status == UV_ECANCELED || status == UV_ENETUNREACH);
  uv_timer_stop(&timer2_handle);
  connect_cb_called++;
  if (status == UV_ENETUNREACH)
    netunreach_errors++;
}

__attribute__((used)) static void timer1_cb(uv_timer_t* handle) {
  uv_close((uv_handle_t*)handle, close_cb);
  uv_close((uv_handle_t*)&tcp_handle, close_cb);
  timer1_cb_called++;
}

__attribute__((used)) static void timer2_cb(uv_timer_t* handle) {
  ASSERT(0 && "should not be called");
}

