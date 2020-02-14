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
typedef  int /*<<< orphan*/  uv_timer_t ;
typedef  int /*<<< orphan*/  uv_prepare_t ;
typedef  int /*<<< orphan*/  uv_idle_t ;
typedef  int /*<<< orphan*/  uv_handle_t ;
typedef  int /*<<< orphan*/  uv_check_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int IDLE_COUNT ; 
 int ITERATIONS ; 
 int /*<<< orphan*/  check_cb_called ; 
 int /*<<< orphan*/  check_close_cb_called ; 
 int /*<<< orphan*/  check_handle ; 
 int /*<<< orphan*/  fflush (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char*) ; 
 int idle_1_cb_called ; 
 int /*<<< orphan*/  idle_1_close_cb_called ; 
 int /*<<< orphan*/ * idle_1_handles ; 
 int /*<<< orphan*/  idle_2_cb_called ; 
 int /*<<< orphan*/  idle_2_cb_started ; 
 int /*<<< orphan*/  idle_2_close_cb_called ; 
 int /*<<< orphan*/  idle_2_handle ; 
 int idle_2_is_active ; 
 scalar_t__ idles_1_active ; 
 int loop_iteration ; 
 int /*<<< orphan*/  prepare_1_cb_called ; 
 int /*<<< orphan*/  prepare_1_close_cb_called ; 
 int /*<<< orphan*/  prepare_1_handle ; 
 int /*<<< orphan*/  prepare_2_cb_called ; 
 int /*<<< orphan*/  prepare_2_close_cb_called ; 
 int /*<<< orphan*/  prepare_2_handle ; 
 int /*<<< orphan*/  printf (char*,int,int) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  timer_handle ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,...) ; 
 int /*<<< orphan*/  uv_default_loop () ; 
 int uv_idle_init (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int uv_idle_start (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *)) ; 
 int uv_idle_stop (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_is_closing (int /*<<< orphan*/ *) ; 
 int uv_prepare_start (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *)) ; 
 int uv_prepare_stop (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static void timer_cb(uv_timer_t* handle) {
  ASSERT(handle == &timer_handle);
}

__attribute__((used)) static void idle_2_close_cb(uv_handle_t* handle) {
  fprintf(stderr, "%s", "IDLE_2_CLOSE_CB\n");
  fflush(stderr);

  ASSERT(handle == (uv_handle_t*)&idle_2_handle);

  ASSERT(idle_2_is_active);

  idle_2_close_cb_called++;
  idle_2_is_active = 0;
}

__attribute__((used)) static void idle_2_cb(uv_idle_t* handle) {
  fprintf(stderr, "%s", "IDLE_2_CB\n");
  fflush(stderr);

  ASSERT(handle == &idle_2_handle);

  idle_2_cb_called++;

  uv_close((uv_handle_t*)handle, idle_2_close_cb);
}

__attribute__((used)) static void idle_1_cb(uv_idle_t* handle) {
  int r;

  fprintf(stderr, "%s", "IDLE_1_CB\n");
  fflush(stderr);

  ASSERT(handle != NULL);
  ASSERT(idles_1_active > 0);

  /* Init idle_2 and make it active */
  if (!idle_2_is_active && !uv_is_closing((uv_handle_t*)&idle_2_handle)) {
    r = uv_idle_init(uv_default_loop(), &idle_2_handle);
    ASSERT(r == 0);
    r = uv_idle_start(&idle_2_handle, idle_2_cb);
    ASSERT(r == 0);
    idle_2_is_active = 1;
    idle_2_cb_started++;
  }

  idle_1_cb_called++;

  if (idle_1_cb_called % 5 == 0) {
    r = uv_idle_stop((uv_idle_t*)handle);
    ASSERT(r == 0);
    idles_1_active--;
  }
}

__attribute__((used)) static void idle_1_close_cb(uv_handle_t* handle) {
  fprintf(stderr, "%s", "IDLE_1_CLOSE_CB\n");
  fflush(stderr);

  ASSERT(handle != NULL);

  idle_1_close_cb_called++;
}

__attribute__((used)) static void prepare_1_close_cb(uv_handle_t* handle) {
  fprintf(stderr, "%s", "PREPARE_1_CLOSE_CB");
  fflush(stderr);
  ASSERT(handle == (uv_handle_t*)&prepare_1_handle);

  prepare_1_close_cb_called++;
}

__attribute__((used)) static void check_close_cb(uv_handle_t* handle) {
  fprintf(stderr, "%s", "CHECK_CLOSE_CB\n");
  fflush(stderr);
  ASSERT(handle == (uv_handle_t*)&check_handle);

  check_close_cb_called++;
}

__attribute__((used)) static void prepare_2_close_cb(uv_handle_t* handle) {
  fprintf(stderr, "%s", "PREPARE_2_CLOSE_CB\n");
  fflush(stderr);
  ASSERT(handle == (uv_handle_t*)&prepare_2_handle);

  prepare_2_close_cb_called++;
}

__attribute__((used)) static void check_cb(uv_check_t* handle) {
  int i, r;

  fprintf(stderr, "%s", "CHECK_CB\n");
  fflush(stderr);
  ASSERT(handle == &check_handle);

  if (loop_iteration < ITERATIONS) {
    /* Make some idle watchers active */
    for (i = 0; i < 1 + (loop_iteration % IDLE_COUNT); i++) {
      r = uv_idle_start(&idle_1_handles[i], idle_1_cb);
      ASSERT(r == 0);
      idles_1_active++;
    }

  } else {
    /* End of the test - close all handles */
    uv_close((uv_handle_t*)&prepare_1_handle, prepare_1_close_cb);
    uv_close((uv_handle_t*)&check_handle, check_close_cb);
    uv_close((uv_handle_t*)&prepare_2_handle, prepare_2_close_cb);

    for (i = 0; i < IDLE_COUNT; i++) {
      uv_close((uv_handle_t*)&idle_1_handles[i], idle_1_close_cb);
    }

    /* This handle is closed/recreated every time, close it only if it is
     * active. */
    if (idle_2_is_active) {
      uv_close((uv_handle_t*)&idle_2_handle, idle_2_close_cb);
    }
  }

  check_cb_called++;
}

__attribute__((used)) static void prepare_2_cb(uv_prepare_t* handle) {
  int r;

  fprintf(stderr, "%s", "PREPARE_2_CB\n");
  fflush(stderr);
  ASSERT(handle == &prepare_2_handle);

  /* Prepare_2 gets started by prepare_1 when (loop_iteration % 2 == 0), and it
   * stops itself immediately. A started watcher is not queued until the next
   * round, so when this callback is made (loop_iteration % 2 == 0) cannot be
   * true. */
  ASSERT(loop_iteration % 2 != 0);

  r = uv_prepare_stop((uv_prepare_t*)handle);
  ASSERT(r == 0);

  prepare_2_cb_called++;
}

__attribute__((used)) static void prepare_1_cb(uv_prepare_t* handle) {
  int r;

  fprintf(stderr, "%s", "PREPARE_1_CB\n");
  fflush(stderr);
  ASSERT(handle == &prepare_1_handle);

  if (loop_iteration % 2 == 0) {
    r = uv_prepare_start(&prepare_2_handle, prepare_2_cb);
    ASSERT(r == 0);
  }

  prepare_1_cb_called++;
  loop_iteration++;

  printf("Loop iteration %d of %d.\n", loop_iteration, ITERATIONS);
}

