#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct fpm_worker_pool_s {struct fpm_worker_pool_s* next; } ;
typedef  unsigned char atomic_uint_t ;
typedef  int /*<<< orphan*/  atomic_t ;
typedef  int /*<<< orphan*/  atomic_int_t ;
struct TYPE_2__ {int argc; char** argv; char* prefix; char* pid; int run_as_root; int force_stderr; int max_requests; int listening_socket; scalar_t__ parent_pid; scalar_t__ test_successful; int /*<<< orphan*/  config; } ;

/* Variables and functions */
 int /*<<< orphan*/  FPM_CLEANUP_CHILD ; 
 int /*<<< orphan*/  FPM_EXIT_OK ; 
 int /*<<< orphan*/  FPM_PCTL_ACTION_SET ; 
 int /*<<< orphan*/  FPM_PCTL_STATE_TERMINATING ; 
 int /*<<< orphan*/  F_GETFL ; 
 int /*<<< orphan*/  F_SETFL ; 
 int O_NONBLOCK ; 
 int /*<<< orphan*/  ZLOG_ERROR ; 
 int /*<<< orphan*/  ZLOG_NOTICE ; 
 int /*<<< orphan*/  exit (int /*<<< orphan*/ ) ; 
 int fcntl (int,int /*<<< orphan*/ ,...) ; 
 int fpm_children_create_initial (struct fpm_worker_pool_s*) ; 
 scalar_t__ fpm_children_init_main () ; 
 int /*<<< orphan*/  fpm_cleanups_run (int /*<<< orphan*/ ) ; 
 scalar_t__ fpm_conf_init_main (int,int) ; 
 scalar_t__ fpm_conf_write_pid () ; 
 scalar_t__ fpm_env_init_main () ; 
 scalar_t__ fpm_event_init_main () ; 
 int /*<<< orphan*/  fpm_event_loop (int) ; 
 TYPE_1__ fpm_globals ; 
 int /*<<< orphan*/  fpm_pctl (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ fpm_pctl_init_main () ; 
 scalar_t__ fpm_php_init_main () ; 
 scalar_t__ fpm_scoreboard_init_main () ; 
 scalar_t__ fpm_signals_init_main () ; 
 scalar_t__ fpm_sockets_init_main () ; 
 int /*<<< orphan*/  fpm_stdio_init_final () ; 
 scalar_t__ fpm_stdio_init_main () ; 
 scalar_t__ fpm_unix_init_main () ; 
 struct fpm_worker_pool_s* fpm_worker_all_pools ; 
 scalar_t__ fpm_worker_pool_init_main () ; 
 int /*<<< orphan*/  sched_yield () ; 
 int /*<<< orphan*/  strdup (char*) ; 
 int /*<<< orphan*/  zlog (int /*<<< orphan*/ ,char*,...) ; 

__attribute__((used)) static inline int fd_set_blocked(int fd, int blocked) /* {{{ */
{
	int flags = fcntl(fd, F_GETFL);

	if (flags < 0) {
		return -1;
	}

	if (blocked) {
		flags &= ~O_NONBLOCK;
	} else {
		flags |= O_NONBLOCK;
	}
	return fcntl(fd, F_SETFL, flags);
}

__attribute__((used)) static inline atomic_int_t atomic_fetch_add(atomic_t *value, atomic_int_t add) /* {{{ */
{
	__asm__ volatile ( "lock;" "xaddq %0, %1;" :
		"+r" (add) : "m" (*value) : "memory");

	return add;
}

__attribute__((used)) static inline atomic_uint_t atomic_cmp_set(atomic_t *lock, atomic_uint_t old, atomic_uint_t set) /* {{{ */
{
	unsigned char res;

	__asm__ volatile ( "lock;" "cmpxchgq %3, %1;" "sete %0;" :
		"=a" (res) : "m" (*lock), "a" (old), "r" (set) : "memory");

	return res;
}

__attribute__((used)) static inline int fpm_spinlock(atomic_t *lock, int try_once) /* {{{ */
{
	if (try_once) {
		return atomic_cmp_set(lock, 0, 1) ? 1 : 0;
	}

	for (;;) {

		if (atomic_cmp_set(lock, 0, 1)) {
			break;
		}

		sched_yield();
	}

	return 1;
}

int fpm_init(int argc, char **argv, char *config, char *prefix, char *pid, int test_conf, int run_as_root, int force_daemon, int force_stderr) /* {{{ */
{
	fpm_globals.argc = argc;
	fpm_globals.argv = argv;
	if (config && *config) {
		fpm_globals.config = strdup(config);
	}
	fpm_globals.prefix = prefix;
	fpm_globals.pid = pid;
	fpm_globals.run_as_root = run_as_root;
	fpm_globals.force_stderr = force_stderr;

	if (0 > fpm_php_init_main()           ||
	    0 > fpm_stdio_init_main()         ||
	    0 > fpm_conf_init_main(test_conf, force_daemon) ||
	    0 > fpm_unix_init_main()          ||
	    0 > fpm_scoreboard_init_main()    ||
	    0 > fpm_pctl_init_main()          ||
	    0 > fpm_env_init_main()           ||
	    0 > fpm_signals_init_main()       ||
	    0 > fpm_children_init_main()      ||
	    0 > fpm_sockets_init_main()       ||
	    0 > fpm_worker_pool_init_main()   ||
	    0 > fpm_event_init_main()) {

		if (fpm_globals.test_successful) {
			exit(FPM_EXIT_OK);
		} else {
			zlog(ZLOG_ERROR, "FPM initialization failed");
			return -1;
		}
	}

	if (0 > fpm_conf_write_pid()) {
		zlog(ZLOG_ERROR, "FPM initialization failed");
		return -1;
	}

	fpm_stdio_init_final();
	zlog(ZLOG_NOTICE, "fpm is running, pid %d", (int) fpm_globals.parent_pid);

	return 0;
}

int fpm_run(int *max_requests) /* {{{ */
{
	struct fpm_worker_pool_s *wp;

	/* create initial children in all pools */
	for (wp = fpm_worker_all_pools; wp; wp = wp->next) {
		int is_parent;

		is_parent = fpm_children_create_initial(wp);

		if (!is_parent) {
			goto run_child;
		}

		/* handle error */
		if (is_parent == 2) {
			fpm_pctl(FPM_PCTL_STATE_TERMINATING, FPM_PCTL_ACTION_SET);
			fpm_event_loop(1);
		}
	}

	/* run event loop forever */
	fpm_event_loop(0);

run_child: /* only workers reach this point */

	fpm_cleanups_run(FPM_CLEANUP_CHILD);

	*max_requests = fpm_globals.max_requests;
	return fpm_globals.listening_socket;
}

