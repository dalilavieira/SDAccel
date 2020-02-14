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
typedef  scalar_t__ uv_uid_t ;
typedef  int /*<<< orphan*/  uv_handle_t ;
typedef  scalar_t__ uv_gid_t ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  out ;
typedef  int /*<<< orphan*/  fd ;
typedef  int /*<<< orphan*/  buffer ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 scalar_t__ EINTR ; 
 int EXIT_FAILURE ; 
 int EXIT_SUCCESS ; 
 scalar_t__ atoi (char*) ; 
 scalar_t__ errno ; 
 int /*<<< orphan*/  fflush (int /*<<< orphan*/ ) ; 
 char* fgets (char*,int,int /*<<< orphan*/ ) ; 
 int fprintf (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  fputs (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fsync (int) ; 
 char* getenv (char*) ; 
 scalar_t__ getgid () ; 
 scalar_t__ getuid () ; 
 int ipc_helper (int) ; 
 int ipc_helper_bind_twice () ; 
 int ipc_helper_closed_handle () ; 
 int ipc_helper_heavy_traffic_deadlock_bug () ; 
 int ipc_helper_send_zero () ; 
 int ipc_helper_tcp_connection () ; 
 int ipc_send_recv_helper () ; 
static  int maybe_run_test (int,char**) ; 
 int /*<<< orphan*/  notify_parent_process () ; 
 scalar_t__ platform_init (int,char**) ; 
 int /*<<< orphan*/  print_tests (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printf (char*) ; 
 int read (int /*<<< orphan*/ ,int*,int) ; 
 int run_test (char*,int /*<<< orphan*/ ,int) ; 
 int run_test_part (char*,char*) ; 
 int run_tests (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spawn_stdin_stdout () ; 
 int spawn_tcp_server_helper () ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  stdin ; 
 int stdio_over_pipes_helper () ; 
 int /*<<< orphan*/  stdout ; 
 scalar_t__ strcmp (char*,char*) ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_is_closing (int /*<<< orphan*/ *) ; 
 char** uv_setup_args (int,char**) ; 
 int /*<<< orphan*/  uv_sleep (int) ; 
 int write (int,char const*,int) ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

int main(int argc, char **argv) {
  if (platform_init(argc, argv))
    return EXIT_FAILURE;

  argv = uv_setup_args(argc, argv);

  switch (argc) {
  case 1: return run_tests(0);
  case 2: return maybe_run_test(argc, argv);
  case 3: return run_test_part(argv[1], argv[2]);
  case 4: return maybe_run_test(argc, argv);
  default:
    fprintf(stderr, "Too many arguments.\n");
    fflush(stderr);
    return EXIT_FAILURE;
  }

#ifndef __SUNPRO_C
  return EXIT_SUCCESS;
#endif
}

__attribute__((used)) static int maybe_run_test(int argc, char **argv) {
  if (strcmp(argv[1], "--list") == 0) {
    print_tests(stdout);
    return 0;
  }

  if (strcmp(argv[1], "ipc_helper_listen_before_write") == 0) {
    return ipc_helper(0);
  }

  if (strcmp(argv[1], "ipc_helper_listen_after_write") == 0) {
    return ipc_helper(1);
  }

  if (strcmp(argv[1], "ipc_helper_heavy_traffic_deadlock_bug") == 0) {
    return ipc_helper_heavy_traffic_deadlock_bug();
  }

  if (strcmp(argv[1], "ipc_send_recv_helper") == 0) {
    return ipc_send_recv_helper();
  }

  if (strcmp(argv[1], "ipc_helper_tcp_connection") == 0) {
    return ipc_helper_tcp_connection();
  }

  if (strcmp(argv[1], "ipc_helper_closed_handle") == 0) {
    return ipc_helper_closed_handle();
  }

  if (strcmp(argv[1], "ipc_helper_bind_twice") == 0) {
    return ipc_helper_bind_twice();
  }

  if (strcmp(argv[1], "ipc_helper_send_zero") == 0) {
    return ipc_helper_send_zero();
  }

  if (strcmp(argv[1], "stdio_over_pipes_helper") == 0) {
    return stdio_over_pipes_helper();
  }

  if (strcmp(argv[1], "spawn_helper1") == 0) {
    notify_parent_process();
    return 1;
  }

  if (strcmp(argv[1], "spawn_helper2") == 0) {
    notify_parent_process();
    printf("hello world\n");
    return 1;
  }

  if (strcmp(argv[1], "spawn_tcp_server_helper") == 0) {
    notify_parent_process();
    return spawn_tcp_server_helper();
  }

  if (strcmp(argv[1], "spawn_helper3") == 0) {
    char buffer[256];
    notify_parent_process();
    ASSERT(buffer == fgets(buffer, sizeof(buffer) - 1, stdin));
    buffer[sizeof(buffer) - 1] = '\0';
    fputs(buffer, stdout);
    return 1;
  }

  if (strcmp(argv[1], "spawn_helper4") == 0) {
    notify_parent_process();
    /* Never surrender, never return! */
    while (1) uv_sleep(10000);
  }

  if (strcmp(argv[1], "spawn_helper5") == 0) {
    const char out[] = "fourth stdio!\n";
    notify_parent_process();
    {
#ifdef _WIN32
      DWORD bytes;
      WriteFile((HANDLE) _get_osfhandle(3), out, sizeof(out) - 1, &bytes, NULL);
#else
      ssize_t r;

      do
        r = write(3, out, sizeof(out) - 1);
      while (r == -1 && errno == EINTR);

      fsync(3);
#endif
    }
    return 1;
  }

  if (strcmp(argv[1], "spawn_helper6") == 0) {
    int r;

    notify_parent_process();

    r = fprintf(stdout, "hello world\n");
    ASSERT(r > 0);

    r = fprintf(stderr, "hello errworld\n");
    ASSERT(r > 0);

    return 1;
  }

  if (strcmp(argv[1], "spawn_helper7") == 0) {
    int r;
    char *test;

    notify_parent_process();

    /* Test if the test value from the parent is still set */
    test = getenv("ENV_TEST");
    ASSERT(test != NULL);

    r = fprintf(stdout, "%s", test);
    ASSERT(r > 0);

    return 1;
  }

#ifndef _WIN32
  if (strcmp(argv[1], "spawn_helper8") == 0) {
    int fd;

    notify_parent_process();
    ASSERT(sizeof(fd) == read(0, &fd, sizeof(fd)));
    ASSERT(fd > 2);
    ASSERT(-1 == write(fd, "x", 1));

    return 1;
  }
#endif  /* !_WIN32 */

  if (strcmp(argv[1], "spawn_helper9") == 0) {
    notify_parent_process();
    spawn_stdin_stdout();
    return 1;
  }

#ifndef _WIN32
  if (strcmp(argv[1], "spawn_helper_setuid_setgid") == 0) {
    uv_uid_t uid = atoi(argv[2]);
    uv_gid_t gid = atoi(argv[3]);

    ASSERT(uid == getuid());
    ASSERT(gid == getgid());
    notify_parent_process();

    return 1;
  }
#endif  /* !_WIN32 */

  return run_test(argv[1], 0, 1);
}

