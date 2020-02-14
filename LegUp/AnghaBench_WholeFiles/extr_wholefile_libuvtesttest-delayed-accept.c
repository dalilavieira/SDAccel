#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_25__   TYPE_4__ ;
typedef  struct TYPE_24__   TYPE_2__ ;
typedef  struct TYPE_23__   TYPE_1__ ;

/* Type definitions */
struct TYPE_23__ {int /*<<< orphan*/ * data; } ;
typedef  TYPE_1__ uv_timer_t ;
typedef  int /*<<< orphan*/  uv_tcp_t ;
typedef  int /*<<< orphan*/  uv_stream_t ;
struct TYPE_24__ {scalar_t__ handle; } ;
typedef  TYPE_2__ uv_handle_t ;
typedef  TYPE_2__ uv_connect_t ;
struct TYPE_25__ {size_t len; TYPE_2__* base; } ;
typedef  TYPE_4__ uv_buf_t ;
struct sockaddr_in {int dummy; } ;
struct sockaddr {int dummy; } ;
typedef  scalar_t__ ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int /*<<< orphan*/  TEST_PORT ; 
 scalar_t__ UV_EOF ; 
 int /*<<< orphan*/  close_cb_called ; 
 int /*<<< orphan*/  connect_cb_called ; 
 int /*<<< orphan*/  connection_cb_called ; 
 int do_accept_called ; 
 int /*<<< orphan*/  free (TYPE_2__*) ; 
 void* malloc (int) ; 
 int uv_accept (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_close (TYPE_2__*,...) ; 
 int /*<<< orphan*/  uv_default_loop () ; 
 scalar_t__ uv_ip4_addr (char*,int /*<<< orphan*/ ,struct sockaddr_in*) ; 
 int /*<<< orphan*/  uv_is_closing (TYPE_2__*) ; 
 int uv_listen (int /*<<< orphan*/ *,int,void (*) (int /*<<< orphan*/ *,int)) ; 
 int uv_read_start (int /*<<< orphan*/ *,void (*) (TYPE_2__*,size_t,TYPE_4__*),void (*) (int /*<<< orphan*/ *,scalar_t__,TYPE_4__ const*)) ; 
 int uv_tcp_bind (int /*<<< orphan*/ *,struct sockaddr const*,int /*<<< orphan*/ ) ; 
 int uv_tcp_connect (TYPE_2__*,int /*<<< orphan*/ *,struct sockaddr const*,void (*) (TYPE_2__*,int)) ; 
 int uv_tcp_init (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int uv_timer_init (int /*<<< orphan*/ ,TYPE_1__*) ; 
 int uv_timer_start (TYPE_1__*,void (*) (TYPE_1__*),int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static void alloc_cb(uv_handle_t* handle, size_t size, uv_buf_t* buf) {
  buf->base = malloc(size);
  buf->len = size;
}

__attribute__((used)) static void close_cb(uv_handle_t* handle) {
  ASSERT(handle != NULL);

  free(handle);

  close_cb_called++;
}

__attribute__((used)) static void do_accept(uv_timer_t* timer_handle) {
  uv_tcp_t* server;
  uv_tcp_t* accepted_handle = (uv_tcp_t*)malloc(sizeof *accepted_handle);
  int r;

  ASSERT(timer_handle != NULL);
  ASSERT(accepted_handle != NULL);

  r = uv_tcp_init(uv_default_loop(), accepted_handle);
  ASSERT(r == 0);

  server = (uv_tcp_t*)timer_handle->data;
  r = uv_accept((uv_stream_t*)server, (uv_stream_t*)accepted_handle);
  ASSERT(r == 0);

  do_accept_called++;

  /* Immediately close the accepted handle. */
  uv_close((uv_handle_t*)accepted_handle, close_cb);

  /* After accepting the two clients close the server handle */
  if (do_accept_called == 2) {
    uv_close((uv_handle_t*)server, close_cb);
  }

  /* Dispose the timer. */
  uv_close((uv_handle_t*)timer_handle, close_cb);
}

__attribute__((used)) static void connection_cb(uv_stream_t* tcp, int status) {
  int r;
  uv_timer_t* timer_handle;

  ASSERT(status == 0);

  timer_handle = (uv_timer_t*)malloc(sizeof *timer_handle);
  ASSERT(timer_handle != NULL);

  /* Accept the client after 1 second */
  r = uv_timer_init(uv_default_loop(), timer_handle);
  ASSERT(r == 0);

  timer_handle->data = tcp;

  r = uv_timer_start(timer_handle, do_accept, 1000, 0);
  ASSERT(r == 0);

  connection_cb_called++;
}

__attribute__((used)) static void start_server(void) {
  struct sockaddr_in addr;
  uv_tcp_t* server = (uv_tcp_t*)malloc(sizeof *server);
  int r;

  ASSERT(0 == uv_ip4_addr("0.0.0.0", TEST_PORT, &addr));
  ASSERT(server != NULL);

  r = uv_tcp_init(uv_default_loop(), server);
  ASSERT(r == 0);
  r = uv_tcp_bind(server, (const struct sockaddr*) &addr, 0);
  ASSERT(r == 0);

  r = uv_listen((uv_stream_t*)server, 128, connection_cb);
  ASSERT(r == 0);
}

__attribute__((used)) static void read_cb(uv_stream_t* tcp, ssize_t nread, const uv_buf_t* buf) {
  /* The server will not send anything, it should close gracefully. */

  if (buf->base) {
    free(buf->base);
  }

  if (nread >= 0) {
    ASSERT(nread == 0);
  } else {
    ASSERT(tcp != NULL);
    ASSERT(nread == UV_EOF);
    uv_close((uv_handle_t*)tcp, close_cb);
  }
}

__attribute__((used)) static void connect_cb(uv_connect_t* req, int status) {
  int r;

  ASSERT(req != NULL);
  ASSERT(status == 0);

  /* Not that the server will send anything, but otherwise we'll never know
   * when the server closes the connection. */
  r = uv_read_start((uv_stream_t*)(req->handle), alloc_cb, read_cb);
  ASSERT(r == 0);

  connect_cb_called++;

  free(req);
}

__attribute__((used)) static void client_connect(void) {
  struct sockaddr_in addr;
  uv_tcp_t* client = (uv_tcp_t*)malloc(sizeof *client);
  uv_connect_t* connect_req = malloc(sizeof *connect_req);
  int r;

  ASSERT(0 == uv_ip4_addr("127.0.0.1", TEST_PORT, &addr));
  ASSERT(client != NULL);
  ASSERT(connect_req != NULL);

  r = uv_tcp_init(uv_default_loop(), client);
  ASSERT(r == 0);

  r = uv_tcp_connect(connect_req,
                     client,
                     (const struct sockaddr*) &addr,
                     connect_cb);
  ASSERT(r == 0);
}

