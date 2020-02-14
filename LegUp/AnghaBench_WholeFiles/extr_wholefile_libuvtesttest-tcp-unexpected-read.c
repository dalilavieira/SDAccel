#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {int /*<<< orphan*/ * handle; } ;
typedef  TYPE_1__ uv_write_t ;
typedef  int /*<<< orphan*/  uv_timer_t ;
typedef  int /*<<< orphan*/  uv_stream_t ;
typedef  int /*<<< orphan*/  uv_handle_t ;
struct TYPE_7__ {int /*<<< orphan*/ * handle; } ;
typedef  TYPE_2__ uv_connect_t ;
typedef  int /*<<< orphan*/  uv_check_t ;
typedef  int /*<<< orphan*/  uv_buf_t ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int /*<<< orphan*/  check_handle ; 
 int /*<<< orphan*/  client_handle ; 
 int /*<<< orphan*/  peer_handle ; 
 int /*<<< orphan*/  server_handle ; 
 int /*<<< orphan*/  ticks ; 
 int /*<<< orphan*/  timer_handle ; 
 scalar_t__ uv_accept (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_buf_init (char*,int) ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_is_closing (int /*<<< orphan*/ *) ; 
 scalar_t__ uv_read_start (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,size_t,int /*<<< orphan*/ *),void (*) (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/  const*)) ; 
 scalar_t__ uv_write (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,void (*) (TYPE_1__*,int)) ; 
 int /*<<< orphan*/  write_req ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static void check_cb(uv_check_t* handle) {
  ticks++;
}

__attribute__((used)) static void timer_cb(uv_timer_t* handle) {
  uv_close((uv_handle_t*) &check_handle, NULL);
  uv_close((uv_handle_t*) &timer_handle, NULL);
  uv_close((uv_handle_t*) &server_handle, NULL);
  uv_close((uv_handle_t*) &client_handle, NULL);
  uv_close((uv_handle_t*) &peer_handle, NULL);
}

__attribute__((used)) static void alloc_cb(uv_handle_t* handle,
                     size_t suggested_size,
                     uv_buf_t* buf) {
  ASSERT(0 && "alloc_cb should not have been called");
}

__attribute__((used)) static void read_cb(uv_stream_t* handle, ssize_t nread, const uv_buf_t* buf) {
  ASSERT(0 && "read_cb should not have been called");
}

__attribute__((used)) static void connect_cb(uv_connect_t* req, int status) {
  ASSERT(req->handle == (uv_stream_t*) &client_handle);
  ASSERT(0 == status);
}

__attribute__((used)) static void write_cb(uv_write_t* req, int status) {
  ASSERT(req->handle == (uv_stream_t*) &peer_handle);
  ASSERT(0 == status);
}

__attribute__((used)) static void connection_cb(uv_stream_t* handle, int status) {
  uv_buf_t buf;

  buf = uv_buf_init("PING", 4);

  ASSERT(0 == status);
  ASSERT(0 == uv_accept(handle, (uv_stream_t*) &peer_handle));
  ASSERT(0 == uv_read_start((uv_stream_t*) &peer_handle, alloc_cb, read_cb));
  ASSERT(0 == uv_write(&write_req, (uv_stream_t*) &peer_handle,
                       &buf, 1, write_cb));
}

