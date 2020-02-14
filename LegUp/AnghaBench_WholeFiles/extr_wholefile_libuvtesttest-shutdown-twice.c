#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct TYPE_9__ {scalar_t__ handle; } ;
typedef  TYPE_1__ uv_shutdown_t ;
typedef  int /*<<< orphan*/  uv_handle_t ;
struct TYPE_10__ {int /*<<< orphan*/  handle; } ;
typedef  TYPE_2__ uv_connect_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 TYPE_1__ req1 ; 
 TYPE_1__ req2 ; 
 int /*<<< orphan*/  shutdown_cb_called ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,...) ; 
 int /*<<< orphan*/  uv_is_closing (int /*<<< orphan*/ *) ; 
 int uv_shutdown (TYPE_1__*,int /*<<< orphan*/ ,void (*) (TYPE_1__*,int)) ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static void close_cb(uv_handle_t* handle) {

}

__attribute__((used)) static void shutdown_cb(uv_shutdown_t* req, int status) {
  ASSERT(req == &req1);
  ASSERT(status == 0);
  shutdown_cb_called++;
  uv_close((uv_handle_t*) req->handle, close_cb);
}

__attribute__((used)) static void connect_cb(uv_connect_t* req, int status) {
  int r;

  ASSERT(status == 0);

  r = uv_shutdown(&req1, req->handle, shutdown_cb);
  ASSERT(r == 0);
  r = uv_shutdown(&req2, req->handle, shutdown_cb);
  ASSERT(r != 0);

}

