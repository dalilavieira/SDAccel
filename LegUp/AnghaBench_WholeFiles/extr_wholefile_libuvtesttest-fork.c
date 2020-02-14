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
typedef  int /*<<< orphan*/  uv_work_t ;
typedef  int /*<<< orphan*/  uv_timer_t ;
typedef  int /*<<< orphan*/  uv_signal_t ;
typedef  int /*<<< orphan*/  uv_poll_t ;
typedef  int /*<<< orphan*/  uv_loop_t ;
typedef  int /*<<< orphan*/  uv_handle_t ;
typedef  int /*<<< orphan*/  uv_fs_t ;
typedef  int /*<<< orphan*/  uv_fs_event_t ;
typedef  int uv_file ;
typedef  int /*<<< orphan*/  uv_buf_t ;
typedef  scalar_t__ ssize_t ;
typedef  int pid_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int /*<<< orphan*/  MAKE_VALGRIND_HAPPY () ; 
 int O_CREAT ; 
 int O_RDWR ; 
 int O_WRONLY ; 
 int S_IRUSR ; 
 int S_IWUSR ; 
 int UV_READABLE ; 
 int /*<<< orphan*/  UV_RUN_DEFAULT ; 
 scalar_t__ WEXITSTATUS (int) ; 
 int WIFEXITED (int) ; 
 int /*<<< orphan*/  WIFSIGNALED (int) ; 
 int after_work_cb_count ; 
 int fork () ; 
 int fork_signal_cb_called ; 
 int fs_event_cb_called ; 
 int getpid () ; 
 int /*<<< orphan*/  perror (char*) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 scalar_t__ read (scalar_t__,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  remove (char*) ; 
 int /*<<< orphan*/  socket_cb_called ; 
 int /*<<< orphan*/  socket_cb_read_buf ; 
 scalar_t__ socket_cb_read_fd ; 
 scalar_t__ socket_cb_read_size ; 
 scalar_t__ strcmp (char const*,char*) ; 
 int timer_cb_called ; 
 int timer_cb_touch_called ; 
 int /*<<< orphan*/  uv_buf_init (char*,int) ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * uv_default_loop () ; 
 int uv_fs_close (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,int /*<<< orphan*/ *) ; 
 int uv_fs_event_init (int /*<<< orphan*/ * const,int /*<<< orphan*/ *) ; 
 int uv_fs_event_start (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,char const*,int,int),char*,int /*<<< orphan*/ ) ; 
 int uv_fs_open (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char const*,int,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_fs_req_cleanup (int /*<<< orphan*/ *) ; 
 int uv_fs_write (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,int /*<<< orphan*/ *,int,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_is_closing (int /*<<< orphan*/ *) ; 
 scalar_t__ uv_loop_close (int /*<<< orphan*/ *) ; 
 scalar_t__ uv_loop_fork (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_loop_init (int /*<<< orphan*/ *) ; 
 int uv_queue_work (int /*<<< orphan*/ * const,int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *),void (*) (int /*<<< orphan*/ *,int)) ; 
 scalar_t__ uv_run (int /*<<< orphan*/ * const,int /*<<< orphan*/ ) ; 
 scalar_t__ uv_timer_init (int /*<<< orphan*/ * const,int /*<<< orphan*/ *) ; 
 int uv_timer_start (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *),int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uv_update_time (int /*<<< orphan*/ *) ; 
 int waitpid (int,int*,int /*<<< orphan*/ ) ; 
 int work_cb_count ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static void timer_cb(uv_timer_t* timer) {
  timer_cb_called++;
  uv_close((uv_handle_t*) timer, NULL);
}

__attribute__((used)) static void socket_cb(uv_poll_t* poll, int status, int events) {
  ssize_t cnt;
  socket_cb_called++;
  ASSERT(0 == status);
  printf("Socket cb got events %d\n", events);
  ASSERT(UV_READABLE == (events & UV_READABLE));
  if (socket_cb_read_fd) {
    cnt = read(socket_cb_read_fd, socket_cb_read_buf, socket_cb_read_size);
    ASSERT(cnt == socket_cb_read_size);
  }
  uv_close((uv_handle_t*) poll, NULL);
}

__attribute__((used)) static void run_timer_loop_once(void) {
  uv_loop_t* loop;
  uv_timer_t timer_handle;

  loop = uv_default_loop();

  timer_cb_called = 0; /* Reset for the child. */

  ASSERT(0 == uv_timer_init(loop, &timer_handle));
  ASSERT(0 == uv_timer_start(&timer_handle, timer_cb, 1, 0));
  ASSERT(0 == uv_run(loop, UV_RUN_DEFAULT));
  ASSERT(1 == timer_cb_called);
}

__attribute__((used)) static void assert_wait_child(pid_t child_pid) {
  pid_t waited_pid;
  int child_stat;

  waited_pid = waitpid(child_pid, &child_stat, 0);
  printf("Waited pid is %d with status %d\n", waited_pid, child_stat);
  if (waited_pid == -1) {
    perror("Failed to wait");
  }
  ASSERT(child_pid == waited_pid);
  ASSERT(WIFEXITED(child_stat)); /* Clean exit, not a signal. */
  ASSERT(!WIFSIGNALED(child_stat));
  ASSERT(0 == WEXITSTATUS(child_stat));
}

void fork_signal_to_child_cb(uv_signal_t* handle, int signum)
{
  fork_signal_cb_called = signum;
  uv_close((uv_handle_t*)handle, NULL);
}

__attribute__((used)) static void create_file(const char* name) {
  int r;
  uv_file file;
  uv_fs_t req;

  r = uv_fs_open(NULL, &req, name, O_WRONLY | O_CREAT, S_IWUSR | S_IRUSR, NULL);
  ASSERT(r >= 0);
  file = r;
  uv_fs_req_cleanup(&req);
  r = uv_fs_close(NULL, &req, file, NULL);
  ASSERT(r == 0);
  uv_fs_req_cleanup(&req);
}

__attribute__((used)) static void touch_file(const char* name) {
  int r;
  uv_file file;
  uv_fs_t req;
  uv_buf_t buf;

  r = uv_fs_open(NULL, &req, name, O_RDWR, 0, NULL);
  ASSERT(r >= 0);
  file = r;
  uv_fs_req_cleanup(&req);

  buf = uv_buf_init("foo", 4);
  r = uv_fs_write(NULL, &req, file, &buf, 1, -1, NULL);
  ASSERT(r >= 0);
  uv_fs_req_cleanup(&req);

  r = uv_fs_close(NULL, &req, file, NULL);
  ASSERT(r == 0);
  uv_fs_req_cleanup(&req);
}

__attribute__((used)) static void timer_cb_touch(uv_timer_t* timer) {
  uv_close((uv_handle_t*)timer, NULL);
  touch_file("watch_file");
  timer_cb_touch_called++;
}

__attribute__((used)) static void fs_event_cb_file_current_dir(uv_fs_event_t* handle,
                                         const char* filename,
                                         int events,
                                         int status) {
  ASSERT(fs_event_cb_called == 0);
  ++fs_event_cb_called;
  ASSERT(status == 0);
#if defined(__APPLE__) || defined(__linux__)
  ASSERT(strcmp(filename, "watch_file") == 0);
#else
  ASSERT(filename == NULL || strcmp(filename, "watch_file") == 0);
#endif
  uv_close((uv_handle_t*)handle, NULL);
}

__attribute__((used)) static void assert_watch_file_current_dir(uv_loop_t* const loop, int file_or_dir) {
  uv_timer_t timer;
  uv_fs_event_t fs_event;
  int r;

  /* Setup */
  remove("watch_file");
  create_file("watch_file");

  r = uv_fs_event_init(loop, &fs_event);
  ASSERT(r == 0);
  /* watching a dir is the only way to get fsevents involved on apple
     platforms */
  r = uv_fs_event_start(&fs_event,
                        fs_event_cb_file_current_dir,
                        file_or_dir == 1 ? "." : "watch_file",
                        0);
  ASSERT(r == 0);

  r = uv_timer_init(loop, &timer);
  ASSERT(r == 0);

  r = uv_timer_start(&timer, timer_cb_touch, 100, 0);
  ASSERT(r == 0);

  ASSERT(timer_cb_touch_called == 0);
  ASSERT(fs_event_cb_called == 0);

  uv_run(loop, UV_RUN_DEFAULT);

  ASSERT(timer_cb_touch_called == 1);
  ASSERT(fs_event_cb_called == 1);

  /* Cleanup */
  remove("watch_file");
  fs_event_cb_called = 0;
  timer_cb_touch_called = 0;
  uv_run(loop, UV_RUN_DEFAULT); /* flush pending closes */
}

__attribute__((used)) static int _do_fork_fs_events_child(int file_or_dir) {
  /* basic fsevents work in the child after a fork */
  pid_t child_pid;
  uv_loop_t loop;

  /* Watch in the parent, prime the loop and/or threads. */
  assert_watch_file_current_dir(uv_default_loop(), file_or_dir);
  child_pid = fork();
  ASSERT(child_pid != -1);

  if (child_pid != 0) {
    /* parent */
    assert_wait_child(child_pid);
  } else {
    /* child */
    /* Ee can watch in a new loop, but dirs only work
       if we're on linux. */
#if defined(__APPLE__)
    file_or_dir = FS_TEST_FILE;
#endif
    printf("Running child\n");
    uv_loop_init(&loop);
    printf("Child first watch\n");
    assert_watch_file_current_dir(&loop, file_or_dir);
    ASSERT(0 == uv_loop_close(&loop));
    printf("Child second watch default loop\n");
    /* Ee can watch in the default loop. */
    ASSERT(0 == uv_loop_fork(uv_default_loop()));
    /* On some platforms (OS X), if we don't update the time now,
     * the timer cb fires before the event loop enters uv__io_poll,
     * instead of after, meaning we don't see the change! This may be
     * a general race.
     */
    uv_update_time(uv_default_loop());
    assert_watch_file_current_dir(uv_default_loop(), file_or_dir);

    /* We can close the parent loop successfully too. This is
       especially important on Apple platforms where if we're not
       careful trying to touch the CFRunLoop, even just to shut it
       down, that we allocated in the FS_TEST_DIR case would crash. */
    ASSERT(0 == uv_loop_close(uv_default_loop()));

    printf("Exiting child \n");
  }

  MAKE_VALGRIND_HAPPY();
  return 0;

}

__attribute__((used)) static void work_cb(uv_work_t* req) {
  work_cb_count++;
}

__attribute__((used)) static void after_work_cb(uv_work_t* req, int status) {
  ASSERT(status == 0);
  after_work_cb_count++;
}

__attribute__((used)) static void assert_run_work(uv_loop_t* const loop) {
  uv_work_t work_req;
  int r;

  ASSERT(work_cb_count == 0);
  ASSERT(after_work_cb_count == 0);
  printf("Queue in %d\n", getpid());
  r = uv_queue_work(loop, &work_req, work_cb, after_work_cb);
  ASSERT(r == 0);
  printf("Running in %d\n", getpid());
  uv_run(loop, UV_RUN_DEFAULT);

  ASSERT(work_cb_count == 1);
  ASSERT(after_work_cb_count == 1);

  /* cleanup  */
  work_cb_count = 0;
  after_work_cb_count = 0;
}

