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
struct __test_metadata {int passed; char* name; int termsig; struct __test_metadata* next; int /*<<< orphan*/  step; int /*<<< orphan*/  (* fn ) (struct __test_metadata*) ;scalar_t__ trigger; struct __test_metadata* prev; } ;
typedef  scalar_t__ pid_t ;
typedef  int /*<<< orphan*/  __u8 ;

/* Variables and functions */
 int SIGABRT ; 
 int /*<<< orphan*/  TH_LOG_STREAM ; 
 int WEXITSTATUS (int) ; 
 scalar_t__ WIFEXITED (int) ; 
 scalar_t__ WIFSIGNALED (int) ; 
 int WTERMSIG (int) ; 
 scalar_t__ _CONSTRUCTOR_ORDER_BACKWARD ; 
 scalar_t__ _CONSTRUCTOR_ORDER_FORWARD ; 
 scalar_t__ __constructor_order ; 
 int __fixture_count ; 
 int __test_count ; 
 struct __test_metadata* __test_list ; 
 int /*<<< orphan*/  _exit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  abort () ; 
 scalar_t__ fork () ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char*,...) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 char* rtc_file ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  stub1 (struct __test_metadata*) ; 
 int /*<<< orphan*/  waitpid (scalar_t__,int*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void __register_test(struct __test_metadata *t)
{
	__test_count++;
	/* Circular linked list where only prev is circular. */
	if (__test_list == NULL) {
		__test_list = t;
		t->next = NULL;
		t->prev = t;
		return;
	}
	if (__constructor_order == _CONSTRUCTOR_ORDER_FORWARD) {
		t->next = NULL;
		t->prev = __test_list->prev;
		t->prev->next = t;
		__test_list->prev = t;
	} else {
		t->next = __test_list;
		t->next->prev = t;
		t->prev = t;
		__test_list = t;
	}
}

__attribute__((used)) static inline int __bail(int for_realz, bool no_print, __u8 step)
{
	if (for_realz) {
		if (no_print)
			_exit(step);
		abort();
	}
	return 0;
}

void __run_test(struct __test_metadata *t)
{
	pid_t child_pid;
	int status;

	t->passed = 1;
	t->trigger = 0;
	printf("[ RUN      ] %s\n", t->name);
	child_pid = fork();
	if (child_pid < 0) {
		printf("ERROR SPAWNING TEST CHILD\n");
		t->passed = 0;
	} else if (child_pid == 0) {
		t->fn(t);
		/* return the step that failed or 0 */
		_exit(t->passed ? 0 : t->step);
	} else {
		/* TODO(wad) add timeout support. */
		waitpid(child_pid, &status, 0);
		if (WIFEXITED(status)) {
			t->passed = t->termsig == -1 ? !WEXITSTATUS(status) : 0;
			if (t->termsig != -1) {
				fprintf(TH_LOG_STREAM,
					"%s: Test exited normally "
					"instead of by signal (code: %d)\n",
					t->name,
					WEXITSTATUS(status));
			} else if (!t->passed) {
				fprintf(TH_LOG_STREAM,
					"%s: Test failed at step #%d\n",
					t->name,
					WEXITSTATUS(status));
			}
		} else if (WIFSIGNALED(status)) {
			t->passed = 0;
			if (WTERMSIG(status) == SIGABRT) {
				fprintf(TH_LOG_STREAM,
					"%s: Test terminated by assertion\n",
					t->name);
			} else if (WTERMSIG(status) == t->termsig) {
				t->passed = 1;
			} else {
				fprintf(TH_LOG_STREAM,
					"%s: Test terminated unexpectedly "
					"by signal %d\n",
					t->name,
					WTERMSIG(status));
			}
		} else {
			fprintf(TH_LOG_STREAM,
				"%s: Test ended in some other way [%u]\n",
				t->name,
				status);
		}
	}
	printf("[     %4s ] %s\n", (t->passed ? "OK" : "FAIL"), t->name);
}

__attribute__((used)) static int test_harness_run(int __attribute__((unused)) argc,
			    char __attribute__((unused)) **argv)
{
	struct __test_metadata *t;
	int ret = 0;
	unsigned int count = 0;
	unsigned int pass_count = 0;

	/* TODO(wad) add optional arguments similar to gtest. */
	printf("[==========] Running %u tests from %u test cases.\n",
	       __test_count, __fixture_count + 1);
	for (t = __test_list; t; t = t->next) {
		count++;
		__run_test(t);
		if (t->passed)
			pass_count++;
		else
			ret = 1;
	}
	printf("[==========] %u / %u tests passed.\n", pass_count, count);
	printf("[  %s  ]\n", (ret ? "FAILED" : "PASSED"));
	return ret;
}

__attribute__((used)) static void __attribute__((constructor)) __constructor_order_first(void)
{
	if (!__constructor_order)
		__constructor_order = _CONSTRUCTOR_ORDER_FORWARD;
}

__attribute__((used)) static void __attribute__((constructor))
__constructor_order_last(void)
{
	if (!__constructor_order)
		__constructor_order = _CONSTRUCTOR_ORDER_BACKWARD;
}

int main(int argc, char **argv)
{
	switch (argc) {
	case 2:
		rtc_file = argv[1];
		/* FALLTHROUGH */
	case 1:
		break;
	default:
		fprintf(stderr, "usage: %s [rtcdev]\n", argv[0]);
		return 1;
	}

	return test_harness_run(argc, argv);
}

