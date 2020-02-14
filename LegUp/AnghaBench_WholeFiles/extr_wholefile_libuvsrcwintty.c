#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_20__   TYPE_6__ ;
typedef  struct TYPE_19__   TYPE_5__ ;
typedef  struct TYPE_18__   TYPE_4__ ;
typedef  struct TYPE_17__   TYPE_3__ ;
typedef  struct TYPE_16__   TYPE_2__ ;
typedef  struct TYPE_15__   TYPE_1__ ;

/* Type definitions */
struct TYPE_17__ {int /*<<< orphan*/  ansi_parser_state; scalar_t__ previous_eol; scalar_t__ utf8_codepoint; scalar_t__ utf8_bytes_left; } ;
struct TYPE_16__ {int /*<<< orphan*/  last_input_record; scalar_t__ last_utf16_high_surrogate; scalar_t__ last_key_offset; scalar_t__ last_key_len; int /*<<< orphan*/ * read_raw_wait; int /*<<< orphan*/  read_line_buffer; int /*<<< orphan*/ * unused_; } ;
struct TYPE_18__ {TYPE_3__ wr; TYPE_2__ rd; } ;
struct TYPE_15__ {int fd; } ;
struct TYPE_19__ {scalar_t__ handle; int flags; int /*<<< orphan*/ * read_cb; int /*<<< orphan*/ * alloc_cb; TYPE_4__ tty; scalar_t__ reqs_pending; TYPE_1__ u; } ;
typedef  TYPE_5__ uv_tty_t ;
typedef  int uv_tty_mode_t ;
typedef  int /*<<< orphan*/  uv_stream_t ;
typedef  int /*<<< orphan*/ * uv_read_cb ;
typedef  int /*<<< orphan*/  uv_loop_t ;
typedef  int uv_file ;
typedef  int /*<<< orphan*/ * uv_alloc_cb ;
struct TYPE_20__ {int wAttributes; } ;
typedef  scalar_t__ HANDLE ;
typedef  int DWORD ;
typedef  TYPE_6__ CONSOLE_SCREEN_BUFFER_INFO ;
typedef  scalar_t__ BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  ANSI_NORMAL ; 
 int BACKGROUND_BLUE ; 
 int BACKGROUND_GREEN ; 
 int BACKGROUND_INTENSITY ; 
 int BACKGROUND_RED ; 
 int COMMON_LVB_REVERSE_VIDEO ; 
 scalar_t__ CreateFileW (char*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DUPLICATE_SAME_ACCESS ; 
 int /*<<< orphan*/  DuplicateHandle (scalar_t__,scalar_t__,scalar_t__,scalar_t__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int ENABLE_ECHO_INPUT ; 
 int ENABLE_LINE_INPUT ; 
 int ENABLE_PROCESSED_INPUT ; 
 int ENABLE_WINDOW_INPUT ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  FILE_SHARE_WRITE ; 
 int FOREGROUND_BLUE ; 
 int FOREGROUND_GREEN ; 
 int FOREGROUND_INTENSITY ; 
 int FOREGROUND_RED ; 
 int GENERIC_READ ; 
 int GENERIC_WRITE ; 
 int /*<<< orphan*/  GetConsoleScreenBufferInfo (scalar_t__,TYPE_6__*) ; 
 int GetLastError () ; 
 scalar_t__ GetNumberOfConsoleInputEvents (scalar_t__,int*) ; 
 scalar_t__ INVALID_HANDLE_VALUE ; 
 int /*<<< orphan*/  OPEN_EXISTING ; 
 int /*<<< orphan*/  QueueUserWorkItem (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SetConsoleMode (scalar_t__,int) ; 
 int UV_EBADF ; 
 int UV_EINVAL ; 
 int UV_ENOTSUP ; 
 int UV_HANDLE_BOUND ; 
 int UV_HANDLE_READABLE ; 
 int UV_HANDLE_READING ; 
 int UV_HANDLE_TTY_RAW ; 
 int UV_HANDLE_TTY_READABLE ; 
 int UV_HANDLE_WRITABLE ; 
 int /*<<< orphan*/  UV_TTY ; 
#define  UV_TTY_MODE_IO 130 
#define  UV_TTY_MODE_NORMAL 129 
#define  UV_TTY_MODE_RAW 128 
 scalar_t__ UV_UNCHECKED ; 
 int /*<<< orphan*/  WT_EXECUTELONGFUNCTION ; 
 int /*<<< orphan*/  abort () ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  uv__determine_vterm_state (scalar_t__) ; 
 scalar_t__ uv__get_osfhandle (int) ; 
 int /*<<< orphan*/  uv__once_init () ; 
 scalar_t__ uv__tty_console_handle ; 
 int /*<<< orphan*/  uv__tty_console_resize_message_loop_thread ; 
 scalar_t__ uv__vterm_state ; 
 int /*<<< orphan*/  uv_connection_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_null_buf_ ; 
 scalar_t__ uv_sem_init (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  uv_sem_post (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_sem_wait (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_stream_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int uv_translate_sys_error (int) ; 
static  void uv_tty_capture_initial_style (TYPE_6__*) ; 
 int uv_tty_default_bg_bright ; 
 int uv_tty_default_bg_color ; 
 int uv_tty_default_fg_bright ; 
 int uv_tty_default_fg_color ; 
 int uv_tty_default_inverse ; 
 int uv_tty_default_text_attributes ; 
 int /*<<< orphan*/  uv_tty_output_lock ; 
 int uv_tty_read_start (TYPE_5__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int uv_tty_read_stop (TYPE_5__*) ; 
 int /*<<< orphan*/  uv_tty_update_virtual_window (TYPE_6__*) ; 
 int uv_tty_virtual_height ; 
 int uv_tty_virtual_width ; 

void uv_console_init(void) {
  if (uv_sem_init(&uv_tty_output_lock, 1))
    abort();
  uv__tty_console_handle = CreateFileW(L"CONOUT$",
                                       GENERIC_READ | GENERIC_WRITE,
                                       FILE_SHARE_WRITE,
                                       0,
                                       OPEN_EXISTING,
                                       0,
                                       0);
  if (uv__tty_console_handle != INVALID_HANDLE_VALUE) {
    QueueUserWorkItem(uv__tty_console_resize_message_loop_thread,
                      NULL,
                      WT_EXECUTELONGFUNCTION);
  }
}

int uv_tty_init(uv_loop_t* loop, uv_tty_t* tty, uv_file fd, int unused) {
  BOOL readable;
  DWORD NumberOfEvents;
  HANDLE handle;
  CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
  (void)unused;

  uv__once_init();
  handle = (HANDLE) uv__get_osfhandle(fd);
  if (handle == INVALID_HANDLE_VALUE)
    return UV_EBADF;

  if (fd <= 2) {
    /* In order to avoid closing a stdio file descriptor 0-2, duplicate the
     * underlying OS handle and forget about the original fd.
     * We could also opt to use the original OS handle and just never close it,
     * but then there would be no reliable way to cancel pending read operations
     * upon close.
     */
    if (!DuplicateHandle(INVALID_HANDLE_VALUE,
                         handle,
                         INVALID_HANDLE_VALUE,
                         &handle,
                         0,
                         FALSE,
                         DUPLICATE_SAME_ACCESS))
      return uv_translate_sys_error(GetLastError());
    fd = -1;
  }

  readable = GetNumberOfConsoleInputEvents(handle, &NumberOfEvents);
  if (!readable) {
    /* Obtain the screen buffer info with the output handle. */
    if (!GetConsoleScreenBufferInfo(handle, &screen_buffer_info)) {
      return uv_translate_sys_error(GetLastError());
    }

    /* Obtain the tty_output_lock because the virtual window state is shared
     * between all uv_tty_t handles. */
    uv_sem_wait(&uv_tty_output_lock);

    if (uv__vterm_state == UV_UNCHECKED)
      uv__determine_vterm_state(handle);

    /* Remember the original console text attributes. */
    uv_tty_capture_initial_style(&screen_buffer_info);

    uv_tty_update_virtual_window(&screen_buffer_info);

    uv_sem_post(&uv_tty_output_lock);
  }


  uv_stream_init(loop, (uv_stream_t*) tty, UV_TTY);
  uv_connection_init((uv_stream_t*) tty);

  tty->handle = handle;
  tty->u.fd = fd;
  tty->reqs_pending = 0;
  tty->flags |= UV_HANDLE_BOUND;

  if (readable) {
    /* Initialize TTY input specific fields. */
    tty->flags |= UV_HANDLE_TTY_READABLE | UV_HANDLE_READABLE;
    /* TODO: remove me in v2.x. */
    tty->tty.rd.unused_ = NULL;
    tty->tty.rd.read_line_buffer = uv_null_buf_;
    tty->tty.rd.read_raw_wait = NULL;

    /* Init keycode-to-vt100 mapper state. */
    tty->tty.rd.last_key_len = 0;
    tty->tty.rd.last_key_offset = 0;
    tty->tty.rd.last_utf16_high_surrogate = 0;
    memset(&tty->tty.rd.last_input_record, 0, sizeof tty->tty.rd.last_input_record);
  } else {
    /* TTY output specific fields. */
    tty->flags |= UV_HANDLE_WRITABLE;

    /* Init utf8-to-utf16 conversion state. */
    tty->tty.wr.utf8_bytes_left = 0;
    tty->tty.wr.utf8_codepoint = 0;

    /* Initialize eol conversion state */
    tty->tty.wr.previous_eol = 0;

    /* Init ANSI parser state. */
    tty->tty.wr.ansi_parser_state = ANSI_NORMAL;
  }

  return 0;
}

__attribute__((used)) static void uv_tty_capture_initial_style(CONSOLE_SCREEN_BUFFER_INFO* info) {
  static int style_captured = 0;

  /* Only do this once.
     Assumption: Caller has acquired uv_tty_output_lock. */
  if (style_captured)
    return;

  /* Save raw win32 attributes. */
  uv_tty_default_text_attributes = info->wAttributes;

  /* Convert black text on black background to use white text. */
  if (uv_tty_default_text_attributes == 0)
    uv_tty_default_text_attributes = 7;

  /* Convert Win32 attributes to ANSI colors. */
  uv_tty_default_fg_color = 0;
  uv_tty_default_bg_color = 0;
  uv_tty_default_fg_bright = 0;
  uv_tty_default_bg_bright = 0;
  uv_tty_default_inverse = 0;

  if (uv_tty_default_text_attributes & FOREGROUND_RED)
    uv_tty_default_fg_color |= 1;

  if (uv_tty_default_text_attributes & FOREGROUND_GREEN)
    uv_tty_default_fg_color |= 2;

  if (uv_tty_default_text_attributes & FOREGROUND_BLUE)
    uv_tty_default_fg_color |= 4;

  if (uv_tty_default_text_attributes & BACKGROUND_RED)
    uv_tty_default_bg_color |= 1;

  if (uv_tty_default_text_attributes & BACKGROUND_GREEN)
    uv_tty_default_bg_color |= 2;

  if (uv_tty_default_text_attributes & BACKGROUND_BLUE)
    uv_tty_default_bg_color |= 4;

  if (uv_tty_default_text_attributes & FOREGROUND_INTENSITY)
    uv_tty_default_fg_bright = 1;

  if (uv_tty_default_text_attributes & BACKGROUND_INTENSITY)
    uv_tty_default_bg_bright = 1;

  if (uv_tty_default_text_attributes & COMMON_LVB_REVERSE_VIDEO)
    uv_tty_default_inverse = 1;

  style_captured = 1;
}

int uv_tty_set_mode(uv_tty_t* tty, uv_tty_mode_t mode) {
  DWORD flags;
  unsigned char was_reading;
  uv_alloc_cb alloc_cb;
  uv_read_cb read_cb;
  int err;

  if (!(tty->flags & UV_HANDLE_TTY_READABLE)) {
    return UV_EINVAL;
  }

  if (!!mode == !!(tty->flags & UV_HANDLE_TTY_RAW)) {
    return 0;
  }

  switch (mode) {
    case UV_TTY_MODE_NORMAL:
      flags = ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT | ENABLE_PROCESSED_INPUT;
      break;
    case UV_TTY_MODE_RAW:
      flags = ENABLE_WINDOW_INPUT;
      break;
    case UV_TTY_MODE_IO:
      return UV_ENOTSUP;
    default:
      return UV_EINVAL;
  }

  /* If currently reading, stop, and restart reading. */
  if (tty->flags & UV_HANDLE_READING) {
    was_reading = 1;
    alloc_cb = tty->alloc_cb;
    read_cb = tty->read_cb;
    err = uv_tty_read_stop(tty);
    if (err) {
      return uv_translate_sys_error(err);
    }
  } else {
    was_reading = 0;
    alloc_cb = NULL;
    read_cb = NULL;
  }

  uv_sem_wait(&uv_tty_output_lock);
  if (!SetConsoleMode(tty->handle, flags)) {
    err = uv_translate_sys_error(GetLastError());
    uv_sem_post(&uv_tty_output_lock);
    return err;
  }
  uv_sem_post(&uv_tty_output_lock);

  /* Update flag. */
  tty->flags &= ~UV_HANDLE_TTY_RAW;
  tty->flags |= mode ? UV_HANDLE_TTY_RAW : 0;

  /* If we just stopped reading, restart. */
  if (was_reading) {
    err = uv_tty_read_start(tty, alloc_cb, read_cb);
    if (err) {
      return uv_translate_sys_error(err);
    }
  }

  return 0;
}

int uv_tty_get_winsize(uv_tty_t* tty, int* width, int* height) {
  CONSOLE_SCREEN_BUFFER_INFO info;

  if (!GetConsoleScreenBufferInfo(tty->handle, &info)) {
    return uv_translate_sys_error(GetLastError());
  }

  uv_sem_wait(&uv_tty_output_lock);
  uv_tty_update_virtual_window(&info);
  uv_sem_post(&uv_tty_output_lock);

  *width = uv_tty_virtual_width;
  *height = uv_tty_virtual_height;

  return 0;
}

