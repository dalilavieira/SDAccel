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
static  void close_cb (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  close_cb_called ; 
 int /*<<< orphan*/  conn ; 
 int /*<<< orphan*/  connect_cb_called ; 
 int /*<<< orphan*/  connect_req ; 
 int /*<<< orphan*/  timer ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,...) ; 
 int /*<<< orphan*/  uv_is_closing (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static void connect_cb(uv_connect_t* req, int status) {
  ASSERT(req == &connect_req);
  ASSERT(status == UV_ECANCELED);
  connect_cb_called++;
}

__attribute__((used)) static void timer_cb(uv_timer_t* handle) {
  ASSERT(handle == &timer);
  uv_close((uv_handle_t*)&conn, close_cb);
  uv_close((uv_handle_t*)&timer, close_cb);
}

__attribute__((used)) static void close_cb(uv_handle_t* handle) {
  ASSERT(handle == (uv_handle_t*)&conn || handle == (uv_handle_t*)&timer);
  close_cb_called++;
}

