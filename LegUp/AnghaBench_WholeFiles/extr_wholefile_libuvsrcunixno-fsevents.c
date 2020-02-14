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
typedef  int /*<<< orphan*/  uv_loop_t ;
typedef  int /*<<< orphan*/  uv_fs_event_t ;
typedef  int /*<<< orphan*/  uv_fs_event_cb ;

/* Variables and functions */
 int /*<<< orphan*/  UNREACHABLE () ; 
 int UV_ENOSYS ; 

int uv_fs_event_init(uv_loop_t* loop, uv_fs_event_t* handle) {
  return UV_ENOSYS;
}

int uv_fs_event_start(uv_fs_event_t* handle, uv_fs_event_cb cb,
                      const char* filename, unsigned int flags) {
  return UV_ENOSYS;
}

int uv_fs_event_stop(uv_fs_event_t* handle) {
  return UV_ENOSYS;
}

void uv__fs_event_close(uv_fs_event_t* handle) {
  UNREACHABLE();
}

