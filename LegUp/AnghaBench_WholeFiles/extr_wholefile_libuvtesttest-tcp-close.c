#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {int /*<<< orphan*/ * handle; } ;
typedef  TYPE_1__ uv_write_t ;
typedef  int /*<<< orphan*/  uv_tcp_t ;
typedef  int /*<<< orphan*/  uv_stream_t ;
typedef  int /*<<< orphan*/  uv_loop_t ;
typedef  int /*<<< orphan*/  uv_handle_t ;
typedef  int /*<<< orphan*/  uv_connect_t ;
typedef  int /*<<< orphan*/  uv_buf_t ;
struct sockaddr_in {int dummy; } ;
struct sockaddr {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int NUM_WRITE_REQS ; 
 int /*<<< orphan*/  TEST_PORT ; 
static  void close_cb (int /*<<< orphan*/ *) ; 
 scalar_t__ close_cb_called ; 
 int /*<<< orphan*/  free (TYPE_1__*) ; 
 TYPE_1__* malloc (int) ; 
 int /*<<< orphan*/  tcp_handle ; 
 int /*<<< orphan*/  uv_buf_init (char*,int) ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,...) ; 
 scalar_t__ uv_ip4_addr (char*,int /*<<< orphan*/ ,struct sockaddr_in*) ; 
 int /*<<< orphan*/  uv_is_closing (int /*<<< orphan*/ *) ; 
 int uv_listen (int /*<<< orphan*/ *,int,void (*) (int /*<<< orphan*/ *,int)) ; 
 int uv_tcp_bind (int /*<<< orphan*/ *,struct sockaddr const*,int /*<<< orphan*/ ) ; 
 int uv_tcp_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_unref (int /*<<< orphan*/ *) ; 
 int uv_write (TYPE_1__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,void (*) (TYPE_1__*,int)) ; 
static  void write_cb (TYPE_1__*,int) ; 
 int /*<<< orphan*/  write_cb_called ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static void connect_cb(uv_connect_t* conn_req, int status) {
  uv_write_t* req;
  uv_buf_t buf;
  int i, r;

  buf = uv_buf_init("PING", 4);
  for (i = 0; i < NUM_WRITE_REQS; i++) {
    req = malloc(sizeof *req);
    ASSERT(req != NULL);

    r = uv_write(req, (uv_stream_t*)&tcp_handle, &buf, 1, write_cb);
    ASSERT(r == 0);
  }

  uv_close((uv_handle_t*)&tcp_handle, close_cb);
}

__attribute__((used)) static void write_cb(uv_write_t* req, int status) {
  /* write callbacks should run before the close callback */
  ASSERT(close_cb_called == 0);
  ASSERT(req->handle == (uv_stream_t*)&tcp_handle);
  write_cb_called++;
  free(req);
}

__attribute__((used)) static void close_cb(uv_handle_t* handle) {
  ASSERT(handle == (uv_handle_t*)&tcp_handle);
  close_cb_called++;
}

__attribute__((used)) static void connection_cb(uv_stream_t* server, int status) {
  ASSERT(status == 0);
}

__attribute__((used)) static void start_server(uv_loop_t* loop, uv_tcp_t* handle) {
  struct sockaddr_in addr;
  int r;

  ASSERT(0 == uv_ip4_addr("127.0.0.1", TEST_PORT, &addr));

  r = uv_tcp_init(loop, handle);
  ASSERT(r == 0);

  r = uv_tcp_bind(handle, (const struct sockaddr*) &addr, 0);
  ASSERT(r == 0);

  r = uv_listen((uv_stream_t*)handle, 128, connection_cb);
  ASSERT(r == 0);

  uv_unref((uv_handle_t*)handle);
}

