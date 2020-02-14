#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {int /*<<< orphan*/  loop; } ;
typedef  TYPE_1__ uv_timer_t ;
typedef  int /*<<< orphan*/  uv_loop_t ;
typedef  int /*<<< orphan*/  uv_handle_t ;
struct TYPE_7__ {scalar_t__ result; scalar_t__ fs_type; int /*<<< orphan*/  path; } ;
typedef  TYPE_2__ uv_fs_t ;
typedef  int /*<<< orphan*/  uv_fs_event_cb ;

/* Variables and functions */
 size_t ARRAY_SIZE (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ASSERT (int) ; 
 scalar_t__ UV_FS_UTIME ; 
 int /*<<< orphan*/ * fs_event ; 
 scalar_t__* fs_event_cbs ; 
 int /*<<< orphan*/  helper_timer_cb_calls ; 
 scalar_t__ strcmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int uv_fs_event_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int uv_fs_event_start (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uv_fs_req_cleanup (TYPE_2__*) ; 
 int uv_fs_utime (int /*<<< orphan*/ ,TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_is_closing (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  watched_dir ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static void init_and_start_fs_events(uv_loop_t* loop) {
  size_t i;
  for (i = 0; i < ARRAY_SIZE(fs_event); i++) {
    int r;
    r = uv_fs_event_init(loop, &fs_event[i]);
    ASSERT(r == 0);

    r = uv_fs_event_start(&fs_event[i],
                          (uv_fs_event_cb)fs_event_cbs[i],
                          watched_dir,
                          0);
    ASSERT(r == 0);
  }
}

__attribute__((used)) static void helper_timer_cb(uv_timer_t* thandle) {
  int r;
  uv_fs_t fs_req;

  /* fire all fs_events */
  r = uv_fs_utime(thandle->loop, &fs_req, watched_dir, 0, 0, NULL);
  ASSERT(r == 0);
  ASSERT(fs_req.result == 0);
  ASSERT(fs_req.fs_type == UV_FS_UTIME);
  ASSERT(strcmp(fs_req.path, watched_dir) == 0);
  uv_fs_req_cleanup(&fs_req);

  helper_timer_cb_calls++;
}

