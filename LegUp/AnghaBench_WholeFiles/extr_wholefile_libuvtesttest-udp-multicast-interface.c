#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/ * handle; } ;
typedef  TYPE_1__ uv_udp_send_t ;
typedef  int /*<<< orphan*/  uv_handle_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int /*<<< orphan*/  CHECK_HANDLE (int /*<<< orphan*/ *) ; 
 int UV_ENETUNREACH ; 
 int UV_EPERM ; 
 int /*<<< orphan*/  close_cb_called ; 
 int /*<<< orphan*/  sv_send_cb_called ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,...) ; 
 int /*<<< orphan*/  uv_is_closing (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static void close_cb(uv_handle_t* handle) {
  CHECK_HANDLE(handle);
  close_cb_called++;
}

__attribute__((used)) static void sv_send_cb(uv_udp_send_t* req, int status) {
  ASSERT(req != NULL);
  ASSERT(status == 0 || status == UV_ENETUNREACH || status == UV_EPERM);
  CHECK_HANDLE(req->handle);

  sv_send_cb_called++;

  uv_close((uv_handle_t*) req->handle, close_cb);
}

