#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uv_write_t ;
typedef  int /*<<< orphan*/  uv_timer_t ;
typedef  int /*<<< orphan*/  uv_stream_t ;
typedef  int /*<<< orphan*/  uv_shutdown_t ;
typedef  int /*<<< orphan*/  uv_handle_t ;
typedef  int /*<<< orphan*/  uv_connect_t ;
struct TYPE_8__ {char* base; int len; } ;
typedef  TYPE_1__ uv_buf_t ;
typedef  int /*<<< orphan*/  ssize_t ;
typedef  int /*<<< orphan*/  slab ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int /*<<< orphan*/  conn ; 
 int /*<<< orphan*/  conn_close_cb_called ; 
 int /*<<< orphan*/  connect_cb_called ; 
static  void shutdown_cb (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  shutdown_cb_called ; 
 int /*<<< orphan*/  shutdown_req ; 
 int /*<<< orphan*/  timer ; 
 int /*<<< orphan*/  timer_close_cb_called ; 
 TYPE_1__ uv_buf_init (char*,int) ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,...) ; 
 int /*<<< orphan*/  uv_is_closing (int /*<<< orphan*/ *) ; 
 int uv_read_start (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,size_t,TYPE_1__*),void (*) (int /*<<< orphan*/ *,int /*<<< orphan*/ ,TYPE_1__ const*)) ; 
 int uv_shutdown (int /*<<< orphan*/ *,int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,int)) ; 
 int uv_write (int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_1__*,int,void (*) (int /*<<< orphan*/ *,int)) ; 
static  void write_cb (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  write_cb_called ; 
 int /*<<< orphan*/  write_req ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static void close_cb(uv_handle_t* handle) {
  if (handle == (uv_handle_t*)&conn)
    conn_close_cb_called++;
  else if (handle == (uv_handle_t*)&timer)
    timer_close_cb_called++;
  else
    ASSERT(0 && "bad handle in close_cb");
}

__attribute__((used)) static void alloc_cb(uv_handle_t* handle,
                     size_t suggested_size,
                     uv_buf_t* buf) {
  static char slab[64];
  buf->base = slab;
  buf->len = sizeof(slab);
}

__attribute__((used)) static void timer_cb(uv_timer_t* handle) {
  uv_buf_t buf;
  int r;

  uv_close((uv_handle_t*)handle, close_cb);

  buf = uv_buf_init("TEST", 4);
  r = uv_write(&write_req, (uv_stream_t*)&conn, &buf, 1, write_cb);
  ASSERT(r == 0);

  r = uv_shutdown(&shutdown_req, (uv_stream_t*)&conn, shutdown_cb);
  ASSERT(r == 0);
}

__attribute__((used)) static void read_cb(uv_stream_t* handle, ssize_t nread, const uv_buf_t* buf) {
}

__attribute__((used)) static void connect_cb(uv_connect_t* req, int status) {
  int r;

  ASSERT(status == 0);
  connect_cb_called++;

  r = uv_read_start((uv_stream_t*)&conn, alloc_cb, read_cb);
  ASSERT(r == 0);
}

__attribute__((used)) static void write_cb(uv_write_t* req, int status) {
  ASSERT(status == 0);
  write_cb_called++;
}

__attribute__((used)) static void shutdown_cb(uv_shutdown_t* req, int status) {
  ASSERT(status == 0);
  shutdown_cb_called++;
  uv_close((uv_handle_t*)&conn, close_cb);
}

