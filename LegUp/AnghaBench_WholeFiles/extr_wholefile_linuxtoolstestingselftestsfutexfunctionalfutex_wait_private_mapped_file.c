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
typedef  int /*<<< orphan*/  pthread_t ;

/* Variables and functions */
 scalar_t__ ETIMEDOUT ; 
 scalar_t__ EWOULDBLOCK ; 
 int RET_ERROR ; 
 int RET_FAIL ; 
 int RET_PASS ; 
 int /*<<< orphan*/  TEST_NAME ; 
 int VCRITICAL ; 
 int VINFO ; 
 int VQUIET ; 
 int /*<<< orphan*/  WAKE_WAIT_US ; 
 int /*<<< orphan*/  atoi (int /*<<< orphan*/ ) ; 
 char* basename (char*) ; 
 scalar_t__ errno ; 
 int /*<<< orphan*/  error (char*,scalar_t__) ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fail (char*) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*) ; 
 int futex_wait (int*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int futex_wake (int*,int,int /*<<< orphan*/ ) ; 
 int getopt (int,char**,char*) ; 
 int /*<<< orphan*/  info (char*,...) ; 
 int /*<<< orphan*/  ksft_print_header () ; 
 int /*<<< orphan*/  ksft_print_msg (char*,char*) ; 
 int /*<<< orphan*/  log_color (int) ; 
 int /*<<< orphan*/  log_verbosity (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  optarg ; 
 int /*<<< orphan*/  print_result (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int pthread_create (int /*<<< orphan*/ *,int /*<<< orphan*/ *,void* (*) (void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_join (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  usleep (int /*<<< orphan*/ ) ; 
 int val ; 
 int /*<<< orphan*/  wait_timeout ; 

void usage(char *prog)
{
	printf("Usage: %s\n", prog);
	printf("  -c	Use color\n");
	printf("  -h	Display this help message\n");
	printf("  -v L	Verbosity level: %d=QUIET %d=CRITICAL %d=INFO\n",
	       VQUIET, VCRITICAL, VINFO);
}

void *thr_futex_wait(void *arg)
{
	int ret;

	info("futex wait\n");
	ret = futex_wait(&val, 1, &wait_timeout, 0);
	if (ret && errno != EWOULDBLOCK && errno != ETIMEDOUT) {
		error("futex error.\n", errno);
		print_result(TEST_NAME, RET_ERROR);
		exit(RET_ERROR);
	}

	if (ret && errno == ETIMEDOUT)
		fail("waiter timedout\n");

	info("futex_wait: ret = %d, errno = %d\n", ret, errno);

	return NULL;
}

int main(int argc, char **argv)
{
	pthread_t thr;
	int ret = RET_PASS;
	int res;
	int c;

	while ((c = getopt(argc, argv, "chv:")) != -1) {
		switch (c) {
		case 'c':
			log_color(1);
			break;
		case 'h':
			usage(basename(argv[0]));
			exit(0);
		case 'v':
			log_verbosity(atoi(optarg));
			break;
		default:
			usage(basename(argv[0]));
			exit(1);
		}
	}

	ksft_print_header();
	ksft_print_msg(
		"%s: Test the futex value of private file mappings in FUTEX_WAIT\n",
		basename(argv[0]));

	ret = pthread_create(&thr, NULL, thr_futex_wait, NULL);
	if (ret < 0) {
		fprintf(stderr, "pthread_create error\n");
		ret = RET_ERROR;
		goto out;
	}

	info("wait a while\n");
	usleep(WAKE_WAIT_US);
	val = 2;
	res = futex_wake(&val, 1, 0);
	info("futex_wake %d\n", res);
	if (res != 1) {
		fail("FUTEX_WAKE didn't find the waiting thread.\n");
		ret = RET_FAIL;
	}

	info("join\n");
	pthread_join(thr, NULL);

 out:
	print_result(TEST_NAME, ret);
	return ret;
}

