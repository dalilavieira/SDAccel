#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_2__ ;
typedef  struct TYPE_15__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uv_write_t ;
struct TYPE_15__ {int /*<<< orphan*/  loop; } ;
typedef  TYPE_1__ uv_stream_t ;
typedef  int /*<<< orphan*/  uv_handle_t ;
typedef  int /*<<< orphan*/  uv_connect_t ;
struct TYPE_16__ {char* base; int len; } ;
typedef  TYPE_2__ uv_buf_t ;
typedef  scalar_t__ ssize_t ;
typedef  int /*<<< orphan*/  slab ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 scalar_t__ UV_ECONNRESET ; 
 scalar_t__ UV_EOF ; 
static  void alloc_cb (int /*<<< orphan*/ *,size_t,TYPE_2__*) ; 
 int /*<<< orphan*/  connect_req ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char*) ; 
static  void read_cb (TYPE_1__*,scalar_t__,TYPE_2__ const*) ; 
 int /*<<< orphan*/  read_cb_called ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  tcp_client ; 
 int /*<<< orphan*/  tcp_peer ; 
 int /*<<< orphan*/  tcp_server ; 
 int uv_accept (TYPE_1__*,TYPE_1__*) ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 char* uv_err_name (scalar_t__) ; 
 int /*<<< orphan*/  uv_is_closing (int /*<<< orphan*/ *) ; 
 int uv_read_start (TYPE_1__*,void (*) (int /*<<< orphan*/ *,size_t,TYPE_2__*),void (*) (TYPE_1__*,scalar_t__,TYPE_2__ const*)) ; 
 int uv_tcp_init (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int uv_write (int /*<<< orphan*/ *,TYPE_1__*,TYPE_2__*,int,void (*) (int /*<<< orphan*/ *,int)) ; 
static  void write_cb (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  write_cb_called ; 
 int /*<<< orphan*/  write_req ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static void connection_cb(uv_stream_t* server, int status) {
  int r;
  uv_buf_t buf;

  ASSERT(server == (uv_stream_t*)&tcp_server);
  ASSERT(status == 0);

  r = uv_tcp_init(server->loop, &tcp_peer);
  ASSERT(r == 0);

  r = uv_accept(server, (uv_stream_t*)&tcp_peer);
  ASSERT(r == 0);

  r = uv_read_start((uv_stream_t*)&tcp_peer, alloc_cb, read_cb);
  ASSERT(r == 0);

  buf.base = "hello\n";
  buf.len = 6;

  r = uv_write(&write_req, (uv_stream_t*)&tcp_peer, &buf, 1, write_cb);
  ASSERT(r == 0);
}

__attribute__((used)) static void alloc_cb(uv_handle_t* handle,
                     size_t suggested_size,
                     uv_buf_t* buf) {
  static char slab[1024];
  buf->base = slab;
  buf->len = sizeof(slab);
}

__attribute__((used)) static void read_cb(uv_stream_t* stream, ssize_t nread, const uv_buf_t* buf) {
  if (nread < 0) {
    fprintf(stderr, "read_cb error: %s\n", uv_err_name(nread));
    ASSERT(nread == UV_ECONNRESET || nread == UV_EOF);

    uv_close((uv_handle_t*)&tcp_server, NULL);
    uv_close((uv_handle_t*)&tcp_peer, NULL);
  }

  read_cb_called++;
}

__attribute__((used)) static void connect_cb(uv_connect_t* req, int status) {
  ASSERT(req == &connect_req);
  ASSERT(status == 0);

  /* Close the client. */
  uv_close((uv_handle_t*)&tcp_client, NULL);
}

__attribute__((used)) static void write_cb(uv_write_t* req, int status) {
  ASSERT(status == 0);
  write_cb_called++;
}

