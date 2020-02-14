#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_4__ ;
typedef  struct TYPE_14__   TYPE_3__ ;
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
struct TYPE_12__ {int /*<<< orphan*/  buf; int /*<<< orphan*/  req; } ;
typedef  TYPE_1__ write_req ;
typedef  int /*<<< orphan*/  uv_write_t ;
struct TYPE_13__ {scalar_t__ write_queue_size; } ;
typedef  TYPE_2__ uv_stream_t ;
struct TYPE_14__ {TYPE_2__* handle; } ;
typedef  TYPE_3__ uv_shutdown_t ;
typedef  int /*<<< orphan*/  uv_handle_t ;
struct TYPE_15__ {TYPE_2__* handle; } ;
typedef  TYPE_4__ uv_connect_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int NUM_WRITE_REQS ; 
static  void close_cb (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  close_cb_called ; 
 int /*<<< orphan*/  connect_cb_called ; 
 int /*<<< orphan*/  free (TYPE_1__*) ; 
static  void shutdown_cb (TYPE_3__*,int) ; 
 int /*<<< orphan*/  shutdown_cb_called ; 
 int /*<<< orphan*/  shutdown_req ; 
 int /*<<< orphan*/  tcp_client ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,...) ; 
 int /*<<< orphan*/  uv_is_closing (int /*<<< orphan*/ *) ; 
 int uv_shutdown (int /*<<< orphan*/ *,TYPE_2__*,void (*) (TYPE_3__*,int)) ; 
 int uv_write (int /*<<< orphan*/ *,TYPE_2__*,int /*<<< orphan*/ *,int,void (*) (int /*<<< orphan*/ *,int)) ; 
static  void write_cb (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  write_cb_called ; 
 TYPE_1__* write_reqs ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static void connect_cb(uv_connect_t* req, int status) {
  write_req* w;
  int i;
  int r;

  ASSERT(req->handle == (uv_stream_t*)&tcp_client);

  for (i = 0; i < NUM_WRITE_REQS; i++) {
    w = &write_reqs[i];
    r = uv_write(&w->req, req->handle, &w->buf, 1, write_cb);
    ASSERT(r == 0);
  }

  r = uv_shutdown(&shutdown_req, req->handle, shutdown_cb);
  ASSERT(r == 0);

  connect_cb_called++;
}

__attribute__((used)) static void write_cb(uv_write_t* req, int status) {
  ASSERT(req != NULL);
  ASSERT(status == 0);
  write_cb_called++;
}

__attribute__((used)) static void shutdown_cb(uv_shutdown_t* req, int status) {
  ASSERT(req->handle == (uv_stream_t*)&tcp_client);
  ASSERT(req->handle->write_queue_size == 0);

  uv_close((uv_handle_t*)req->handle, close_cb);
  free(write_reqs);

  shutdown_cb_called++;
}

__attribute__((used)) static void close_cb(uv_handle_t* handle) {
  ASSERT(handle == (uv_handle_t*)&tcp_client);
  close_cb_called++;
}

