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
 scalar_t__ EWOULDBLOCK ; 
 int MAP_ANONYMOUS ; 
 int MAP_PRIVATE ; 
 int PROT_READ ; 
 int PROT_WRITE ; 
 void* RET_ERROR ; 
 int RET_FAIL ; 
 void* RET_PASS ; 
 int /*<<< orphan*/  TEST_NAME ; 
 int VCRITICAL ; 
 int VINFO ; 
 int VQUIET ; 
 int /*<<< orphan*/  WAIT_US ; 
 int /*<<< orphan*/  _SC_PAGESIZE ; 
 int /*<<< orphan*/  atoi (int /*<<< orphan*/ ) ; 
 char* basename (char*) ; 
 void* buf ; 
 scalar_t__ child_blocked ; 
 int child_ret ; 
 scalar_t__ errno ; 
 int /*<<< orphan*/  error (char*,scalar_t__) ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fail (char*) ; 
 int futex_wait (void*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int getopt (int,char**,char*) ; 
 int /*<<< orphan*/  info (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ksft_print_header () ; 
 int /*<<< orphan*/  ksft_print_msg (char*,char*) ; 
 int /*<<< orphan*/  log_color (int) ; 
 int /*<<< orphan*/  log_verbosity (int /*<<< orphan*/ ) ; 
 void* mmap (int /*<<< orphan*/ *,long,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  optarg ; 
 int /*<<< orphan*/  print_result (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int pthread_create (int /*<<< orphan*/ *,int /*<<< orphan*/ *,void* (*) (void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_exit (int /*<<< orphan*/ *) ; 
 long sysconf (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usleep (int /*<<< orphan*/ ) ; 

void usage(char *prog)
{
	printf("Usage: %s\n", prog);
	printf("  -c	Use color\n");
	printf("  -h	Display this help message\n");
	printf("  -v L	Verbosity level: %d=QUIET %d=CRITICAL %d=INFO\n",
	       VQUIET, VCRITICAL, VINFO);
}

void *wait_thread(void *arg)
{
	int res;

	child_ret = RET_PASS;
	res = futex_wait(buf, 1, NULL, 0);
	child_blocked = 0;

	if (res != 0 && errno != EWOULDBLOCK) {
		error("futex failure\n", errno);
		child_ret = RET_ERROR;
	}
	pthread_exit(NULL);
}

int main(int argc, char **argv)
{
	int c, ret = RET_PASS;
	long page_size;
	pthread_t thr;

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

	page_size = sysconf(_SC_PAGESIZE);

	buf = mmap(NULL, page_size, PROT_READ|PROT_WRITE,
		   MAP_PRIVATE|MAP_ANONYMOUS, 0, 0);
	if (buf == (void *)-1) {
		error("mmap\n", errno);
		exit(1);
	}

	ksft_print_header();
	ksft_print_msg("%s: Test the uninitialized futex value in FUTEX_WAIT\n",
	       basename(argv[0]));


	ret = pthread_create(&thr, NULL, wait_thread, NULL);
	if (ret) {
		error("pthread_create\n", errno);
		ret = RET_ERROR;
		goto out;
	}

	info("waiting %dus for child to return\n", WAIT_US);
	usleep(WAIT_US);

	ret = child_ret;
	if (child_blocked) {
		fail("child blocked in kernel\n");
		ret = RET_FAIL;
	}

 out:
	print_result(TEST_NAME, ret);
	return ret;
}

