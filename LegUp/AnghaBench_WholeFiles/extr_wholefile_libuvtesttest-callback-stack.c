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
typedef  int /*<<< orphan*/  uv_write_t ;
typedef  int /*<<< orphan*/  uv_timer_t ;
typedef  int /*<<< orphan*/  uv_stream_t ;
typedef  int /*<<< orphan*/  uv_shutdown_t ;
typedef  int /*<<< orphan*/  uv_handle_t ;
struct TYPE_9__ {scalar_t__ handle; } ;
typedef  TYPE_1__ uv_connect_t ;
struct TYPE_10__ {size_t len; char* base; } ;
typedef  TYPE_2__ uv_buf_t ;
typedef  scalar_t__ ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int /*<<< orphan*/  FATAL (char*) ; 
 int /*<<< orphan*/  MESSAGE ; 
 scalar_t__ UV_EOF ; 
 int bytes_received ; 
 int /*<<< orphan*/  client ; 
 int /*<<< orphan*/  close_cb_called ; 
 int /*<<< orphan*/  connect_cb_called ; 
 int /*<<< orphan*/  free (char*) ; 
 char* malloc (size_t) ; 
 scalar_t__ nested ; 
 int /*<<< orphan*/  printf (char*,int) ; 
 int /*<<< orphan*/  puts (char*) ; 
 int /*<<< orphan*/  shutdown_cb_called ; 
 int /*<<< orphan*/  shutdown_req ; 
 int /*<<< orphan*/  timer ; 
 int /*<<< orphan*/  timer_cb_called ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,...) ; 
 int /*<<< orphan*/  uv_default_loop () ; 
 int /*<<< orphan*/  uv_is_closing (int /*<<< orphan*/ *) ; 
 scalar_t__ uv_read_start (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,size_t,TYPE_2__*),void (*) (int /*<<< orphan*/ *,scalar_t__,TYPE_2__ const*)) ; 
 scalar_t__ uv_shutdown (int /*<<< orphan*/ *,int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,int)) ; 
 int uv_timer_init (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int uv_timer_start (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *),int,int /*<<< orphan*/ ) ; 
 scalar_t__ uv_write (int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_2__*,int,void (*) (int /*<<< orphan*/ *,int)) ; 
 int /*<<< orphan*/  write_cb_called ; 
 int /*<<< orphan*/  write_req ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static void alloc_cb(uv_handle_t* handle, size_t size, uv_buf_t* buf) {
  buf->len = size;
  buf->base = malloc(size);
  ASSERT(buf->base != NULL);
}

__attribute__((used)) static void close_cb(uv_handle_t* handle) {
  ASSERT(nested == 0 && "close_cb must be called from a fresh stack");

  close_cb_called++;
}

__attribute__((used)) static void shutdown_cb(uv_shutdown_t* req, int status) {
  ASSERT(status == 0);
  ASSERT(nested == 0 && "shutdown_cb must be called from a fresh stack");

  shutdown_cb_called++;
}

__attribute__((used)) static void read_cb(uv_stream_t* tcp, ssize_t nread, const uv_buf_t* buf) {
  ASSERT(nested == 0 && "read_cb must be called from a fresh stack");

  printf("Read. nread == %d\n", (int)nread);
  free(buf->base);

  if (nread == 0) {
    return;

  } else if (nread < 0) {
    ASSERT(nread == UV_EOF);

    nested++;
    uv_close((uv_handle_t*)tcp, close_cb);
    nested--;

    return;
  }

  bytes_received += nread;

  /* We call shutdown here because when bytes_received == sizeof MESSAGE there
   * will be no more data sent nor received, so here it would be possible for a
   * backend to call shutdown_cb immediately and *not* from a fresh stack. */
  if (bytes_received == sizeof MESSAGE) {
    nested++;

    puts("Shutdown");

    if (uv_shutdown(&shutdown_req, (uv_stream_t*)tcp, shutdown_cb)) {
      FATAL("uv_shutdown failed");
    }
    nested--;
  }
}

__attribute__((used)) static void timer_cb(uv_timer_t* handle) {
  ASSERT(handle == &timer);
  ASSERT(nested == 0 && "timer_cb must be called from a fresh stack");

  puts("Timeout complete. Now read data...");

  nested++;
  if (uv_read_start((uv_stream_t*)&client, alloc_cb, read_cb)) {
    FATAL("uv_read_start failed");
  }
  nested--;

  timer_cb_called++;

  uv_close((uv_handle_t*)handle, close_cb);
}

__attribute__((used)) static void write_cb(uv_write_t* req, int status) {
  int r;

  ASSERT(status == 0);
  ASSERT(nested == 0 && "write_cb must be called from a fresh stack");

  puts("Data written. 500ms timeout...");

  /* After the data has been sent, we're going to wait for a while, then start
   * reading. This makes us certain that the message has been echoed back to
   * our receive buffer when we start reading. This maximizes the temptation
   * for the backend to use dirty stack for calling read_cb. */
  nested++;
  r = uv_timer_init(uv_default_loop(), &timer);
  ASSERT(r == 0);
  r = uv_timer_start(&timer, timer_cb, 500, 0);
  ASSERT(r == 0);
  nested--;

  write_cb_called++;
}

__attribute__((used)) static void connect_cb(uv_connect_t* req, int status) {
  uv_buf_t buf;

  puts("Connected. Write some data to echo server...");

  ASSERT(status == 0);
  ASSERT(nested == 0 && "connect_cb must be called from a fresh stack");

  nested++;

  buf.base = (char*) &MESSAGE;
  buf.len = sizeof MESSAGE;

  if (uv_write(&write_req, (uv_stream_t*)req->handle, &buf, 1, write_cb)) {
    FATAL("uv_write failed");
  }

  nested--;

  connect_cb_called++;
}

