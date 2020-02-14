#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uv_timer_t ;
typedef  int /*<<< orphan*/  uv_tcp_t ;
typedef  int /*<<< orphan*/  uv_stream_t ;
typedef  int /*<<< orphan*/  uv_shutdown_t ;
typedef  int /*<<< orphan*/  uv_handle_t ;
typedef  int /*<<< orphan*/  uv_connect_t ;
struct TYPE_6__ {char* base; size_t len; } ;
typedef  TYPE_1__ uv_buf_t ;
typedef  int ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int UV_EOF ; 
 int called_connect_cb ; 
 scalar_t__ called_shutdown_cb ; 
 scalar_t__ called_tcp_close_cb ; 
 int called_timer_cb ; 
 scalar_t__ called_timer_close_cb ; 
 int /*<<< orphan*/  connect_req ; 
 int /*<<< orphan*/  free (char*) ; 
 int got_eof ; 
 int got_q ; 
 char* malloc (size_t) ; 
 int /*<<< orphan*/  puts (char*) ; 
 int /*<<< orphan*/  qbuf ; 
 int /*<<< orphan*/  shutdown_req ; 
 int /*<<< orphan*/  tcp ; 
 int /*<<< orphan*/  timer ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,...) ; 
 int /*<<< orphan*/  uv_is_closing (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_read_start (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,size_t,TYPE_1__*),void (*) (int /*<<< orphan*/ *,int,TYPE_1__ const*)) ; 
 int /*<<< orphan*/  uv_shutdown (int /*<<< orphan*/ *,int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,int)) ; 
 int /*<<< orphan*/  uv_write (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  write_req ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static void alloc_cb(uv_handle_t* handle, size_t size, uv_buf_t* buf) {
  buf->base = malloc(size);
  buf->len = size;
}

__attribute__((used)) static void read_cb(uv_stream_t* t, ssize_t nread, const uv_buf_t* buf) {
  ASSERT((uv_tcp_t*)t == &tcp);

  if (nread == 0) {
    free(buf->base);
    return;
  }

  if (!got_q) {
    ASSERT(nread == 1);
    ASSERT(!got_eof);
    ASSERT(buf->base[0] == 'Q');
    free(buf->base);
    got_q = 1;
    puts("got Q");
  } else {
    ASSERT(nread == UV_EOF);
    if (buf->base) {
      free(buf->base);
    }
    got_eof = 1;
    puts("got EOF");
  }
}

__attribute__((used)) static void shutdown_cb(uv_shutdown_t *req, int status) {
  ASSERT(req == &shutdown_req);

  ASSERT(called_connect_cb == 1);
  ASSERT(!got_eof);
  ASSERT(called_tcp_close_cb == 0);
  ASSERT(called_timer_close_cb == 0);
  ASSERT(called_timer_cb == 0);

  called_shutdown_cb++;
}

__attribute__((used)) static void connect_cb(uv_connect_t *req, int status) {
  ASSERT(status == 0);
  ASSERT(req == &connect_req);

  /* Start reading from our connection so we can receive the EOF.  */
  uv_read_start((uv_stream_t*)&tcp, alloc_cb, read_cb);

  /*
   * Write the letter 'Q' to gracefully kill the echo-server. This will not
   * effect our connection.
   */
  uv_write(&write_req, (uv_stream_t*) &tcp, &qbuf, 1, NULL);

  /* Shutdown our end of the connection.  */
  uv_shutdown(&shutdown_req, (uv_stream_t*) &tcp, shutdown_cb);

  called_connect_cb++;
  ASSERT(called_shutdown_cb == 0);
}

__attribute__((used)) static void tcp_close_cb(uv_handle_t* handle) {
  ASSERT(handle == (uv_handle_t*) &tcp);

  ASSERT(called_connect_cb == 1);
  ASSERT(got_q);
  ASSERT(got_eof);
  ASSERT(called_timer_cb == 1);

  called_tcp_close_cb++;
}

__attribute__((used)) static void timer_close_cb(uv_handle_t* handle) {
  ASSERT(handle == (uv_handle_t*) &timer);
  called_timer_close_cb++;
}

__attribute__((used)) static void timer_cb(uv_timer_t* handle) {
  ASSERT(handle == &timer);
  uv_close((uv_handle_t*) handle, timer_close_cb);

  /*
   * The most important assert of the test: we have not received
   * tcp_close_cb yet.
   */
  ASSERT(called_tcp_close_cb == 0);
  uv_close((uv_handle_t*) &tcp, tcp_close_cb);

  called_timer_cb++;
}

