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
typedef  int /*<<< orphan*/  uint64_t ;
typedef  int pid_t ;

/* Variables and functions */
 scalar_t__ EINTR ; 
 int /*<<< orphan*/  GIT_VERSION ; 
 int /*<<< orphan*/  KILL_TIMEOUT ; 
 int MAGIC_SKIP_RETURN_VALUE ; 
 int /*<<< orphan*/  SIGALRM ; 
 int /*<<< orphan*/  SIGINT ; 
 int /*<<< orphan*/  SIGKILL ; 
 int /*<<< orphan*/  SIGTERM ; 
 int WEXITSTATUS (int) ; 
 scalar_t__ WIFEXITED (int) ; 
 scalar_t__ WIFSIGNALED (int) ; 
 int WTERMSIG (int) ; 
 int /*<<< orphan*/  alarm (int /*<<< orphan*/ ) ; 
 scalar_t__ errno ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fflush (int /*<<< orphan*/ ) ; 
 int fork () ; 
 int /*<<< orphan*/  kill (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  perror (char*) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/  setpgid (int,int) ; 
 int /*<<< orphan*/  sig_action ; 
 scalar_t__ sigaction (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stdout ; 
 int /*<<< orphan*/  test_error (char*) ; 
 int /*<<< orphan*/  test_finish (char*,int) ; 
 int /*<<< orphan*/  test_set_git_version (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  test_skip (char*) ; 
 int /*<<< orphan*/  test_start (char*) ; 
 int /*<<< orphan*/  timeout ; 
 int waitpid (int,int*,int /*<<< orphan*/ ) ; 

int run_test(int (test_function)(void), char *name)
{
	bool terminated;
	int rc, status;
	pid_t pid;

	/* Make sure output is flushed before forking */
	fflush(stdout);

	pid = fork();
	if (pid == 0) {
		setpgid(0, 0);
		exit(test_function());
	} else if (pid == -1) {
		perror("fork");
		return 1;
	}

	setpgid(pid, pid);

	/* Wake us up in timeout seconds */
	alarm(timeout);
	terminated = false;

wait:
	rc = waitpid(pid, &status, 0);
	if (rc == -1) {
		if (errno != EINTR) {
			printf("unknown error from waitpid\n");
			return 1;
		}

		if (terminated) {
			printf("!! force killing %s\n", name);
			kill(-pid, SIGKILL);
			return 1;
		} else {
			printf("!! killing %s\n", name);
			kill(-pid, SIGTERM);
			terminated = true;
			alarm(KILL_TIMEOUT);
			goto wait;
		}
	}

	/* Kill anything else in the process group that is still running */
	kill(-pid, SIGTERM);

	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	else {
		if (WIFSIGNALED(status))
			printf("!! child died by signal %d\n", WTERMSIG(status));
		else
			printf("!! child died by unknown cause\n");

		status = 1; /* Signal or other */
	}

	return status;
}

__attribute__((used)) static void sig_handler(int signum)
{
	/* Just wake us up from waitpid */
}

void test_harness_set_timeout(uint64_t time)
{
	timeout = time;
}

int test_harness(int (test_function)(void), char *name)
{
	int rc;

	test_start(name);
	test_set_git_version(GIT_VERSION);

	if (sigaction(SIGINT, &sig_action, NULL)) {
		perror("sigaction (sigint)");
		test_error(name);
		return 1;
	}

	if (sigaction(SIGALRM, &sig_action, NULL)) {
		perror("sigaction (sigalrm)");
		test_error(name);
		return 1;
	}

	rc = run_test(test_function, name);

	if (rc == MAGIC_SKIP_RETURN_VALUE) {
		test_skip(name);
		/* so that skipped test is not marked as failed */
		rc = 0;
	} else
		test_finish(name, rc);

	return rc;
}

