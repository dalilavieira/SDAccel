#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct timeval {int tv_sec; int tv_usec; } ;
typedef  int mp_uint_t ;
struct TYPE_8__ {char AsciiChar; } ;
struct TYPE_9__ {int /*<<< orphan*/  wVirtualKeyCode; TYPE_1__ uChar; int /*<<< orphan*/  bKeyDown; } ;
struct TYPE_10__ {TYPE_2__ KeyEvent; } ;
struct TYPE_12__ {scalar_t__ EventType; TYPE_3__ Event; } ;
struct TYPE_11__ {int LowPart; } ;
typedef  TYPE_4__ LARGE_INTEGER ;
typedef  TYPE_5__ INPUT_RECORD ;
typedef  int /*<<< orphan*/  DWORD ;

/* Variables and functions */
 int CHAR_CTRL_C ; 
 int /*<<< orphan*/  ENABLE_ECHO_INPUT ; 
 int /*<<< orphan*/  ENABLE_LINE_INPUT ; 
 int /*<<< orphan*/  ENABLE_PROCESSED_INPUT ; 
 int /*<<< orphan*/  GetConsoleMode (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ KEY_EVENT ; 
 int /*<<< orphan*/  QueryPerformanceCounter (TYPE_4__*) ; 
 int /*<<< orphan*/  ReadConsoleInput (int /*<<< orphan*/ ,TYPE_5__*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SetConsoleMode (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  assure_stdin_handle () ; 
 int esc_seq_chr () ; 
 int esc_seq_process_vk (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gettimeofday (struct timeval*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  orig_mode ; 
 int /*<<< orphan*/  std_in ; 
 size_t strlen (char const*) ; 
 int /*<<< orphan*/  write (int,char const*,size_t) ; 

void mp_hal_stdio_mode_raw(void) {
    assure_stdin_handle();
    GetConsoleMode(std_in, &orig_mode);
    DWORD mode = orig_mode;
    mode &= ~ENABLE_ECHO_INPUT;
    mode &= ~ENABLE_LINE_INPUT;
    mode &= ~ENABLE_PROCESSED_INPUT;
    SetConsoleMode(std_in, mode);
}

void mp_hal_stdio_mode_orig(void) {
    assure_stdin_handle();
    SetConsoleMode(std_in, orig_mode);
}

int mp_hal_stdin_rx_chr(void) {
    // currently processing escape seq?
    const int ret = esc_seq_chr();
    if (ret) {
        return ret;
    }

    // poll until key which we handle is pressed
    assure_stdin_handle();
    DWORD num_read;
    INPUT_RECORD rec;
    for (;;) {
      if (!ReadConsoleInput(std_in, &rec, 1, &num_read) || !num_read) {
          return CHAR_CTRL_C; // EOF, ctrl-D
      }
      if (rec.EventType != KEY_EVENT || !rec.Event.KeyEvent.bKeyDown) { // only want key down events
          continue;
      }
      const char c = rec.Event.KeyEvent.uChar.AsciiChar;
      if (c) { // plain ascii char, return it
          return c;
      }
      const int ret = esc_seq_process_vk(rec.Event.KeyEvent.wVirtualKeyCode);
      if (ret) {
          return ret;
      }
    }
}

void mp_hal_stdout_tx_strn(const char *str, size_t len) {
    write(1, str, len);
}

void mp_hal_stdout_tx_strn_cooked(const char *str, size_t len) {
    mp_hal_stdout_tx_strn(str, len);
}

void mp_hal_stdout_tx_str(const char *str) {
    mp_hal_stdout_tx_strn(str, strlen(str));
}

mp_uint_t mp_hal_ticks_ms(void) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

mp_uint_t mp_hal_ticks_us(void) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000 + tv.tv_usec;
}

mp_uint_t mp_hal_ticks_cpu(void) {
    LARGE_INTEGER value;
    QueryPerformanceCounter(&value);
#ifdef _WIN64
    return value.QuadPart;
#else
    return value.LowPart;
#endif
}

