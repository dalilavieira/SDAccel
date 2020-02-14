#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {scalar_t__ handle; } ;
typedef  TYPE_1__ uv_write_t ;
typedef  int /*<<< orphan*/  uv_tcp_t ;
typedef  int /*<<< orphan*/  uv_stream_t ;
typedef  int /*<<< orphan*/  uv_os_fd_t ;
typedef  int /*<<< orphan*/  uv_handle_t ;
struct TYPE_8__ {int /*<<< orphan*/ * handle; } ;
typedef  TYPE_2__ uv_connect_t ;
typedef  int /*<<< orphan*/  uv_buf_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int close (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  close_cb_called ; 
 int /*<<< orphan*/  connect_cb_called ; 
 TYPE_2__ connect_req ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char*) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  uv_buf_init (char*,int) ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,...) ; 
 int uv_fileno (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_is_closing (int /*<<< orphan*/ *) ; 
 char* uv_strerror (int) ; 
 int uv_write (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,void (*) (TYPE_1__*,int)) ; 
 int /*<<< orphan*/  write_cb_called ; 
 int /*<<< orphan*/  write_req ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static void close_socket(uv_tcp_t* sock) {
  uv_os_fd_t fd;
  int r;

  r = uv_fileno((uv_handle_t*)sock, &fd);
  ASSERT(r == 0);
#ifdef _WIN32
  r = closesocket((uv_os_sock_t)fd);
#else
  r = close(fd);
#endif
  ASSERT(r == 0);
}

__attribute__((used)) static void close_cb(uv_handle_t* handle) {
  ASSERT(handle != NULL);
  close_cb_called++;
}

__attribute__((used)) static void write_cb(uv_write_t* req, int status) {
  ASSERT(req != NULL);

  ASSERT(status != 0);
  fprintf(stderr, "uv_write error: %s\n", uv_strerror(status));
  write_cb_called++;

  uv_close((uv_handle_t*)(req->handle), close_cb);
}

__attribute__((used)) static void connect_cb(uv_connect_t* req, int status) {
  uv_buf_t buf;
  uv_stream_t* stream;
  int r;

  ASSERT(req == &connect_req);
  ASSERT(status == 0);

  stream = req->handle;
  connect_cb_called++;

  /* close the socket, the hard way */
  close_socket((uv_tcp_t*)stream);

  buf = uv_buf_init("hello\n", 6);
  r = uv_write(&write_req, stream, &buf, 1, write_cb);
  ASSERT(r == 0);
}

