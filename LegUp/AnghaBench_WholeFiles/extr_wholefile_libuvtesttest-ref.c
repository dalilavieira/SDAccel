#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
struct TYPE_10__ {int /*<<< orphan*/  handle; } ;
typedef  TYPE_1__ uv_write_t ;
typedef  int /*<<< orphan*/  uv_shutdown_t ;
typedef  int /*<<< orphan*/  uv_prepare_t ;
typedef  int /*<<< orphan*/  uv_handle_t ;
struct TYPE_11__ {int /*<<< orphan*/  handle; } ;
typedef  TYPE_2__ uv_connect_t ;
typedef  int /*<<< orphan*/  uv_buf_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int /*<<< orphan*/  FATAL (char*) ; 
 int /*<<< orphan*/  UV_RUN_DEFAULT ; 
 int /*<<< orphan*/  buffer ; 
 int close_cb_called ; 
 int /*<<< orphan*/  connect_cb_called ; 
 TYPE_2__ connect_req ; 
 int /*<<< orphan*/  req_cb_called ; 
 int /*<<< orphan*/  shutdown_cb_called ; 
 int /*<<< orphan*/  shutdown_req ; 
 int /*<<< orphan*/  uv_buf_init (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,...) ; 
 int /*<<< orphan*/  uv_default_loop () ; 
 int /*<<< orphan*/  uv_is_closing (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_run (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uv_shutdown (int /*<<< orphan*/ *,int /*<<< orphan*/ ,void (*) (int /*<<< orphan*/ *,int)) ; 
 int /*<<< orphan*/  uv_unref (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_write (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,void (*) (TYPE_1__*,int)) ; 
 int /*<<< orphan*/  write_cb_called ; 
 TYPE_1__ write_req ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static void close_cb(uv_handle_t* handle) {
  close_cb_called++;
}

__attribute__((used)) static void do_close(void* handle) {
  close_cb_called = 0;
  uv_close((uv_handle_t*)handle, close_cb);
  ASSERT(close_cb_called == 0);
  uv_run(uv_default_loop(), UV_RUN_DEFAULT);
  ASSERT(close_cb_called == 1);
}

__attribute__((used)) static void fail_cb(void) {
  FATAL("fail_cb should not have been called");
}

__attribute__((used)) static void fail_cb2(void) {
  ASSERT(0 && "fail_cb2 should not have been called");
}

__attribute__((used)) static void req_cb(uv_handle_t* req, int status) {
  req_cb_called++;
}

__attribute__((used)) static void shutdown_cb(uv_shutdown_t* req, int status) {
  ASSERT(req == &shutdown_req);
  shutdown_cb_called++;
}

__attribute__((used)) static void write_cb(uv_write_t* req, int status) {
  ASSERT(req == &write_req);
  uv_shutdown(&shutdown_req, req->handle, shutdown_cb);
  write_cb_called++;
}

__attribute__((used)) static void connect_and_write(uv_connect_t* req, int status) {
  uv_buf_t buf = uv_buf_init(buffer, sizeof buffer);
  ASSERT(req == &connect_req);
  ASSERT(status == 0);
  uv_write(&write_req, req->handle, &buf, 1, write_cb);
  connect_cb_called++;
}

__attribute__((used)) static void connect_and_shutdown(uv_connect_t* req, int status) {
  ASSERT(req == &connect_req);
  ASSERT(status == 0);
  uv_shutdown(&shutdown_req, req->handle, shutdown_cb);
  connect_cb_called++;
}

__attribute__((used)) static void prepare_cb(uv_prepare_t* h) {
  ASSERT(h != NULL);
  uv_unref((uv_handle_t*)h);
}

