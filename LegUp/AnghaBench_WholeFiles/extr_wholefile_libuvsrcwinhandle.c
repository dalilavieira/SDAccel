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
typedef  int /*<<< orphan*/  uv_udp_t ;
typedef  int /*<<< orphan*/  uv_tty_t ;
typedef  int /*<<< orphan*/  uv_timer_t ;
typedef  int /*<<< orphan*/  uv_tcp_t ;
typedef  int /*<<< orphan*/  uv_signal_t ;
typedef  int /*<<< orphan*/  uv_process_t ;
typedef  int /*<<< orphan*/  uv_prepare_t ;
typedef  int /*<<< orphan*/  uv_poll_t ;
typedef  int /*<<< orphan*/  uv_pipe_t ;
typedef  scalar_t__ uv_os_fd_t ;
typedef  int /*<<< orphan*/  uv_loop_t ;
typedef  int /*<<< orphan*/  uv_idle_t ;
typedef  int uv_handle_type ;
struct TYPE_7__ {int flags; int type; int /*<<< orphan*/  close_cb; int /*<<< orphan*/ * loop; } ;
typedef  TYPE_1__ uv_handle_t ;
typedef  int /*<<< orphan*/  uv_fs_poll_t ;
typedef  int /*<<< orphan*/  uv_fs_event_t ;
typedef  scalar_t__ uv_file ;
typedef  int /*<<< orphan*/  uv_close_cb ;
typedef  int /*<<< orphan*/  uv_check_t ;
typedef  int /*<<< orphan*/  uv_async_t ;
typedef  scalar_t__ HANDLE ;
typedef  int /*<<< orphan*/  DWORD ;

/* Variables and functions */
#define  FILE_TYPE_CHAR 144 
#define  FILE_TYPE_DISK 143 
#define  FILE_TYPE_PIPE 142 
 int /*<<< orphan*/  GetConsoleMode (scalar_t__,int /*<<< orphan*/ *) ; 
 int GetFileType (scalar_t__) ; 
#define  UV_ASYNC 141 
#define  UV_CHECK 140 
 int UV_FILE ; 
#define  UV_FS_EVENT 139 
#define  UV_FS_POLL 138 
 int UV_HANDLE_ACTIVE ; 
 int UV_HANDLE_CLOSED ; 
 int UV_HANDLE_CLOSING ; 
#define  UV_IDLE 137 
#define  UV_NAMED_PIPE 136 
#define  UV_POLL 135 
#define  UV_PREPARE 134 
#define  UV_PROCESS 133 
#define  UV_SIGNAL 132 
#define  UV_TCP 131 
#define  UV_TIMER 130 
#define  UV_TTY 129 
#define  UV_UDP 128 
 int UV_UNKNOWN_HANDLE ; 
 int _open_osfhandle (intptr_t,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  abort () ; 
 int /*<<< orphan*/  assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uv__fs_poll_close (int /*<<< orphan*/ *) ; 
 scalar_t__ uv__get_osfhandle (int) ; 
 int /*<<< orphan*/  uv__handle_closing (TYPE_1__*) ; 
 int /*<<< orphan*/  uv_async_close (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_check_stop (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_fs_event_close (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_idle_stop (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_pipe_close (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_poll_close (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_prepare_stop (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_process_close (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_signal_close (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_tcp_close (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_timer_stop (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_tty_close (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_udp_close (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_want_endgame (int /*<<< orphan*/ *,TYPE_1__*) ; 

uv_handle_type uv_guess_handle(uv_file file) {
  HANDLE handle;
  DWORD mode;

  if (file < 0) {
    return UV_UNKNOWN_HANDLE;
  }

  handle = uv__get_osfhandle(file);

  switch (GetFileType(handle)) {
    case FILE_TYPE_CHAR:
      if (GetConsoleMode(handle, &mode)) {
        return UV_TTY;
      } else {
        return UV_FILE;
      }

    case FILE_TYPE_PIPE:
      return UV_NAMED_PIPE;

    case FILE_TYPE_DISK:
      return UV_FILE;

    default:
      return UV_UNKNOWN_HANDLE;
  }
}

int uv_is_active(const uv_handle_t* handle) {
  return (handle->flags & UV_HANDLE_ACTIVE) &&
        !(handle->flags & UV_HANDLE_CLOSING);
}

void uv_close(uv_handle_t* handle, uv_close_cb cb) {
  uv_loop_t* loop = handle->loop;

  if (handle->flags & UV_HANDLE_CLOSING) {
    assert(0);
    return;
  }

  handle->close_cb = cb;

  /* Handle-specific close actions */
  switch (handle->type) {
    case UV_TCP:
      uv_tcp_close(loop, (uv_tcp_t*)handle);
      return;

    case UV_NAMED_PIPE:
      uv_pipe_close(loop, (uv_pipe_t*) handle);
      return;

    case UV_TTY:
      uv_tty_close((uv_tty_t*) handle);
      return;

    case UV_UDP:
      uv_udp_close(loop, (uv_udp_t*) handle);
      return;

    case UV_POLL:
      uv_poll_close(loop, (uv_poll_t*) handle);
      return;

    case UV_TIMER:
      uv_timer_stop((uv_timer_t*)handle);
      uv__handle_closing(handle);
      uv_want_endgame(loop, handle);
      return;

    case UV_PREPARE:
      uv_prepare_stop((uv_prepare_t*)handle);
      uv__handle_closing(handle);
      uv_want_endgame(loop, handle);
      return;

    case UV_CHECK:
      uv_check_stop((uv_check_t*)handle);
      uv__handle_closing(handle);
      uv_want_endgame(loop, handle);
      return;

    case UV_IDLE:
      uv_idle_stop((uv_idle_t*)handle);
      uv__handle_closing(handle);
      uv_want_endgame(loop, handle);
      return;

    case UV_ASYNC:
      uv_async_close(loop, (uv_async_t*) handle);
      return;

    case UV_SIGNAL:
      uv_signal_close(loop, (uv_signal_t*) handle);
      return;

    case UV_PROCESS:
      uv_process_close(loop, (uv_process_t*) handle);
      return;

    case UV_FS_EVENT:
      uv_fs_event_close(loop, (uv_fs_event_t*) handle);
      return;

    case UV_FS_POLL:
      uv__fs_poll_close((uv_fs_poll_t*) handle);
      uv__handle_closing(handle);
      return;

    default:
      /* Not supported */
      abort();
  }
}

int uv_is_closing(const uv_handle_t* handle) {
  return !!(handle->flags & (UV_HANDLE_CLOSING | UV_HANDLE_CLOSED));
}

uv_os_fd_t uv_get_osfhandle(int fd) {
  return uv__get_osfhandle(fd);
}

int uv_open_osfhandle(uv_os_fd_t os_fd) {
  return _open_osfhandle((intptr_t) os_fd, 0);
}

