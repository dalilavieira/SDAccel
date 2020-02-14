#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uv_stream_t ;
struct TYPE_10__ {int /*<<< orphan*/  loop; } ;
typedef  TYPE_1__ uv_pipe_t ;
typedef  int /*<<< orphan*/  uv_os_sock_t ;
typedef  scalar_t__ uv_handle_type ;
typedef  int /*<<< orphan*/  uv_handle_t ;
struct TYPE_11__ {char* base; int len; } ;
typedef  TYPE_2__ uv_buf_t ;
typedef  scalar_t__ ssize_t ;
typedef  int /*<<< orphan*/  base ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (TYPE_1__*) ; 
 int /*<<< orphan*/  ASSERT (int) ; 
 int /*<<< orphan*/  F_GETFL ; 
 int /*<<< orphan*/  F_SETFL ; 
 int O_NONBLOCK ; 
 scalar_t__ UV_NAMED_PIPE ; 
 int /*<<< orphan*/  close_called ; 
 int fcntl (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 TYPE_1__* incoming ; 
 unsigned int incoming_count ; 
 scalar_t__ uv_accept (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,...) ; 
 int /*<<< orphan*/  uv_is_closing (int /*<<< orphan*/ *) ; 
 scalar_t__ uv_pipe_init (int /*<<< orphan*/ ,TYPE_1__*,int /*<<< orphan*/ ) ; 
 scalar_t__ uv_pipe_pending_count (TYPE_1__*) ; 
 scalar_t__ uv_pipe_pending_type (TYPE_1__*) ; 
 scalar_t__ uv_read_stop (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static void set_nonblocking(uv_os_sock_t sock) {
  int r;
#ifdef _WIN32
  unsigned long on = 1;
  r = ioctlsocket(sock, FIONBIO, &on);
  ASSERT(r == 0);
#else
  int flags = fcntl(sock, F_GETFL, 0);
  ASSERT(flags >= 0);
  r = fcntl(sock, F_SETFL, flags | O_NONBLOCK);
  ASSERT(r >= 0);
#endif
}

__attribute__((used)) static void close_cb(uv_handle_t* handle) {
  close_called++;
}

__attribute__((used)) static void alloc_cb(uv_handle_t* handle, size_t size, uv_buf_t* buf) {
  static char base[1];

  buf->base = base;
  buf->len = sizeof(base);
}

__attribute__((used)) static void read_cb(uv_stream_t* handle,
                    ssize_t nread,
                    const uv_buf_t* buf) {
  uv_pipe_t* p;
  uv_pipe_t* inc;
  uv_handle_type pending;
  unsigned int i;

  p = (uv_pipe_t*) handle;
  ASSERT(nread >= 0);

  while (uv_pipe_pending_count(p) != 0) {
    pending = uv_pipe_pending_type(p);
    ASSERT(pending == UV_NAMED_PIPE);

    ASSERT(incoming_count < ARRAY_SIZE(incoming));
    inc = &incoming[incoming_count++];
    ASSERT(0 == uv_pipe_init(p->loop, inc, 0));
    ASSERT(0 == uv_accept(handle, (uv_stream_t*) inc));
  }

  if (incoming_count != ARRAY_SIZE(incoming))
    return;

  ASSERT(0 == uv_read_stop((uv_stream_t*) p));
  uv_close((uv_handle_t*) p, close_cb);
  for (i = 0; i < ARRAY_SIZE(incoming); i++)
    uv_close((uv_handle_t*) &incoming[i], close_cb);
}

