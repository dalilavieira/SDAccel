#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uv_shutdown_t ;
typedef  int /*<<< orphan*/  uv_handle_t ;
struct TYPE_4__ {scalar_t__ handle; } ;
typedef  TYPE_1__ uv_connect_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int UV_ECANCELED ; 
 int /*<<< orphan*/  close_cb_called ; 
 int /*<<< orphan*/  connect_cb_called ; 
 TYPE_1__ connect_req ; 
 int /*<<< orphan*/  shutdown_cb_called ; 
 int /*<<< orphan*/  shutdown_req ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,...) ; 
 int uv_is_closing (int /*<<< orphan*/ *) ; 
 int uv_shutdown (int /*<<< orphan*/ *,scalar_t__,void (*) (int /*<<< orphan*/ *,int)) ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static void shutdown_cb(uv_shutdown_t* req, int status) {
  ASSERT(req == &shutdown_req);
  ASSERT(status == 0 || status == UV_ECANCELED);
  shutdown_cb_called++;
}

__attribute__((used)) static void close_cb(uv_handle_t* handle) {
  close_cb_called++;
}

__attribute__((used)) static void connect_cb(uv_connect_t* req, int status) {
  int r;

  ASSERT(req == &connect_req);
  ASSERT(status == 0);

  r = uv_shutdown(&shutdown_req, req->handle, shutdown_cb);
  ASSERT(r == 0);
  ASSERT(0 == uv_is_closing((uv_handle_t*) req->handle));
  uv_close((uv_handle_t*) req->handle, close_cb);
  ASSERT(1 == uv_is_closing((uv_handle_t*) req->handle));

  connect_cb_called++;
}

