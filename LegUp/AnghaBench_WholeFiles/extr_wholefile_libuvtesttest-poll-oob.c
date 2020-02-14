#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int /*<<< orphan*/  uv_stream_t ;
typedef  int /*<<< orphan*/  uv_poll_t ;
typedef  int /*<<< orphan*/  uv_idle_t ;
typedef  int /*<<< orphan*/  uv_handle_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 scalar_t__ EAGAIN ; 
 scalar_t__ EINPROGRESS ; 
 scalar_t__ EINTR ; 
 scalar_t__ EINVAL ; 
 int /*<<< orphan*/  MSG_OOB ; 
 int UV_PRIORITIZED ; 
 int UV_READABLE ; 
 int UV_WRITABLE ; 
 int cli_pr_check ; 
 int cli_rd_check ; 
 int client_fd ; 
 int /*<<< orphan*/  client_handle ; 
 scalar_t__ errno ; 
 int /*<<< orphan*/  idle ; 
 scalar_t__ kMaxTicks ; 
 int /*<<< orphan*/  memset (char*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  peer_handle ; 
 int /*<<< orphan*/ * poll_req ; 
 int recv (int,char**,int,int /*<<< orphan*/ ) ; 
 int send (int,char*,int,int /*<<< orphan*/ ) ; 
 int server_fd ; 
 int /*<<< orphan*/  server_handle ; 
 int srv_rd_check ; 
 scalar_t__ strncmp (char*,char*,int) ; 
 scalar_t__ ticks ; 
 scalar_t__ uv_accept (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_default_loop () ; 
 scalar_t__ uv_fileno (int /*<<< orphan*/ *,int*) ; 
 scalar_t__ uv_idle_start (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *)) ; 
 int /*<<< orphan*/  uv_is_closing (int /*<<< orphan*/ *) ; 
 scalar_t__ uv_poll_init_socket (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 scalar_t__ uv_poll_start (int /*<<< orphan*/ *,int,void (*) (int /*<<< orphan*/ *,int,int)) ; 
 scalar_t__ uv_poll_stop (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_sleep (int) ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static int got_eagain(void) {
  return errno == EAGAIN
      || errno == EINPROGRESS
#ifdef EWOULDBLOCK
      || errno == EWOULDBLOCK
#endif
      ;
}

__attribute__((used)) static void idle_cb(uv_idle_t* idle) {
  uv_sleep(100);
  if (++ticks < kMaxTicks)
    return;

  uv_poll_stop(&poll_req[0]);
  uv_poll_stop(&poll_req[1]);
  uv_close((uv_handle_t*) &server_handle, NULL);
  uv_close((uv_handle_t*) &client_handle, NULL);
  uv_close((uv_handle_t*) &peer_handle, NULL);
  uv_close((uv_handle_t*) idle, NULL);
}

__attribute__((used)) static void poll_cb(uv_poll_t* handle, int status, int events) {
  char buffer[5];
  int n;
  int fd;

  ASSERT(0 == uv_fileno((uv_handle_t*)handle, &fd));
  memset(buffer, 0, 5);

  if (events & UV_PRIORITIZED) {
    do
      n = recv(client_fd, &buffer, 5, MSG_OOB);
    while (n == -1 && errno == EINTR);
    ASSERT(n >= 0 || errno != EINVAL);
    cli_pr_check = 1;
    ASSERT(0 == uv_poll_stop(&poll_req[0]));
    ASSERT(0 == uv_poll_start(&poll_req[0],
                              UV_READABLE | UV_WRITABLE,
                              poll_cb));
  }
  if (events & UV_READABLE) {
    if (fd == client_fd) {
      do
        n = recv(client_fd, &buffer, 5, 0);
      while (n == -1 && errno == EINTR);
      ASSERT(n >= 0 || errno != EINVAL);
      if (cli_rd_check == 1) {
        ASSERT(strncmp(buffer, "world", n) == 0);
        ASSERT(5 == n);
        cli_rd_check = 2;
      }
      if (cli_rd_check == 0) {
        ASSERT(n == 4);
        ASSERT(strncmp(buffer, "hello", n) == 0);
        cli_rd_check = 1;
        do {
          do
            n = recv(server_fd, &buffer, 5, 0);
          while (n == -1 && errno == EINTR);
          if (n > 0) {
            ASSERT(n == 5);
            ASSERT(strncmp(buffer, "world", n) == 0);
            cli_rd_check = 2;
          }
        } while (n > 0);

        ASSERT(got_eagain());
      }
    }
    if (fd == server_fd) {
      do
        n = recv(server_fd, &buffer, 3, 0);
      while (n == -1 && errno == EINTR);
      ASSERT(n >= 0 || errno != EINVAL);
      ASSERT(3 == n);
      ASSERT(strncmp(buffer, "foo", n) == 0);
      srv_rd_check = 1;
      uv_poll_stop(&poll_req[1]);
    }
  }
  if (events & UV_WRITABLE) {
    do {
      n = send(client_fd, "foo", 3, 0);
    } while (n < 0 && errno == EINTR);
    ASSERT(3 == n);
  }
}

__attribute__((used)) static void connection_cb(uv_stream_t* handle, int status) {
  int r;

  ASSERT(0 == status);
  ASSERT(0 == uv_accept(handle, (uv_stream_t*) &peer_handle));
  ASSERT(0 == uv_fileno((uv_handle_t*) &peer_handle, &server_fd));
  ASSERT(0 == uv_poll_init_socket(uv_default_loop(), &poll_req[0], client_fd));
  ASSERT(0 == uv_poll_init_socket(uv_default_loop(), &poll_req[1], server_fd));
  ASSERT(0 == uv_poll_start(&poll_req[0],
                            UV_PRIORITIZED | UV_READABLE | UV_WRITABLE,
                            poll_cb));
  ASSERT(0 == uv_poll_start(&poll_req[1],
                            UV_READABLE,
                            poll_cb));
  do {
    r = send(server_fd, "hello", 5, MSG_OOB);
  } while (r < 0 && errno == EINTR);
  ASSERT(5 == r);

  do {
    r = send(server_fd, "world", 5, 0);
  } while (r < 0 && errno == EINTR);
  ASSERT(5 == r);

  ASSERT(0 == uv_idle_start(&idle, idle_cb));
}

