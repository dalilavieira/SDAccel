#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uv_stream_t ;
typedef  int /*<<< orphan*/  uv_os_fd_t ;
typedef  int /*<<< orphan*/  uv_idle_t ;
typedef  int /*<<< orphan*/  uv_handle_t ;
struct TYPE_3__ {int /*<<< orphan*/ * handle; } ;
typedef  TYPE_1__ uv_connect_t ;
typedef  int /*<<< orphan*/  uv_buf_t ;
typedef  int /*<<< orphan*/  storage ;
typedef  scalar_t__ ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 scalar_t__ EINTR ; 
 int /*<<< orphan*/  MSG_OOB ; 
 int /*<<< orphan*/  client_handle ; 
 scalar_t__ errno ; 
 int /*<<< orphan*/  idle ; 
 scalar_t__ kMaxTicks ; 
 int /*<<< orphan*/  peer_handle ; 
 int send (int /*<<< orphan*/ ,char*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  server_handle ; 
 scalar_t__ ticks ; 
 scalar_t__ uv_accept (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_buf_init (char*,int) ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ uv_fileno (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ uv_idle_start (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *)) ; 
 int /*<<< orphan*/  uv_is_closing (int /*<<< orphan*/ *) ; 
 scalar_t__ uv_read_start (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,size_t,int /*<<< orphan*/ *),void (*) (int /*<<< orphan*/ *,scalar_t__,int /*<<< orphan*/  const*)) ; 
 scalar_t__ uv_stream_set_blocking (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static void alloc_cb(uv_handle_t* handle,
                     size_t suggested_size,
                     uv_buf_t* buf) {
  static char storage[1024];
  *buf = uv_buf_init(storage, sizeof(storage));
}

__attribute__((used)) static void idle_cb(uv_idle_t* idle) {
  if (++ticks < kMaxTicks)
    return;

  uv_close((uv_handle_t*) &server_handle, NULL);
  uv_close((uv_handle_t*) &client_handle, NULL);
  uv_close((uv_handle_t*) &peer_handle, NULL);
  uv_close((uv_handle_t*) idle, NULL);
}

__attribute__((used)) static void read_cb(uv_stream_t* handle, ssize_t nread, const uv_buf_t* buf) {
#ifdef __MVS__
  char lbuf[12];
#endif
  uv_os_fd_t fd;

  ASSERT(nread >= 0);
  ASSERT(0 == uv_fileno((uv_handle_t*)handle, &fd));
  ASSERT(0 == uv_idle_start(&idle, idle_cb));

#ifdef __MVS__
  /* Need to flush out the OOB data. Otherwise, this callback will get
   * triggered on every poll with nread = 0.
   */
  ASSERT(-1 != recv(fd, lbuf, sizeof(lbuf), MSG_OOB));
#endif
}

__attribute__((used)) static void connect_cb(uv_connect_t* req, int status) {
  ASSERT(req->handle == (uv_stream_t*) &client_handle);
  ASSERT(0 == status);
}

__attribute__((used)) static void connection_cb(uv_stream_t* handle, int status) {
  int r;
  uv_os_fd_t fd;

  ASSERT(0 == status);
  ASSERT(0 == uv_accept(handle, (uv_stream_t*) &peer_handle));
  ASSERT(0 == uv_read_start((uv_stream_t*) &peer_handle, alloc_cb, read_cb));

  /* Send some OOB data */
  ASSERT(0 == uv_fileno((uv_handle_t*) &client_handle, &fd));

  ASSERT(0 == uv_stream_set_blocking((uv_stream_t*) &client_handle, 1));

  /* The problem triggers only on a second message, it seem that xnu is not
   * triggering `kevent()` for the first one
   */
  do {
    r = send(fd, "hello", 5, MSG_OOB);
  } while (r < 0 && errno == EINTR);
  ASSERT(5 == r);

  do {
    r = send(fd, "hello", 5, MSG_OOB);
  } while (r < 0 && errno == EINTR);
  ASSERT(5 == r);

  ASSERT(0 == uv_stream_set_blocking((uv_stream_t*) &client_handle, 0));
}

