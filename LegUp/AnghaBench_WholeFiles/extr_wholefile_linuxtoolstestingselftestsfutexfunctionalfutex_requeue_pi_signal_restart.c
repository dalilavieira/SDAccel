#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct sigaction {void (* sa_handler ) (int) ;scalar_t__ sa_flags; int /*<<< orphan*/  sa_mask; } ;
struct sched_param {int sched_priority; } ;
typedef  int /*<<< orphan*/  schedp ;
typedef  int /*<<< orphan*/  pthread_t ;
typedef  int /*<<< orphan*/  pthread_attr_t ;
struct TYPE_3__ {scalar_t__ val; } ;

/* Variables and functions */
 int /*<<< orphan*/  DELAY_US ; 
 int EWOULDBLOCK ; 
 int /*<<< orphan*/  FUTEX_PRIVATE_FLAG ; 
 int /*<<< orphan*/  PTHREAD_EXPLICIT_SCHED ; 
 int RET_ERROR ; 
 char* RET_FAIL ; 
 int RET_PASS ; 
 int SCHED_FIFO ; 
 int /*<<< orphan*/  SIGUSR1 ; 
 int /*<<< orphan*/  TEST_NAME ; 
 int VCRITICAL ; 
 int VINFO ; 
 int VQUIET ; 
 int /*<<< orphan*/  atoi (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  atomic_set (TYPE_1__*,int) ; 
 char* basename (char*) ; 
 int errno ; 
 int /*<<< orphan*/  error (char*,int) ; 
 int /*<<< orphan*/  exit (int) ; 
 unsigned int f1 ; 
 char* f2 ; 
 int /*<<< orphan*/  fail (char*,int,int /*<<< orphan*/ ) ; 
 int futex_cmp_requeue_pi (unsigned int*,unsigned int,char**,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  futex_lock_pi (char**,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  futex_unlock_pi (char**,int /*<<< orphan*/ ) ; 
 int futex_wait_requeue_pi (unsigned int*,unsigned int,char**,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int getopt (int,char**,char*) ; 
 int /*<<< orphan*/  info (char*,...) ; 
 int /*<<< orphan*/  ksft_print_header () ; 
 int /*<<< orphan*/  ksft_print_msg (char*,...) ; 
 int /*<<< orphan*/  log_color (int) ; 
 int /*<<< orphan*/  log_verbosity (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (struct sched_param*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  optarg ; 
 int /*<<< orphan*/  print_result (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/  pthread_attr_init (int /*<<< orphan*/ *) ; 
 int pthread_attr_setinheritsched (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int pthread_attr_setschedparam (int /*<<< orphan*/ *,struct sched_param*) ; 
 int pthread_attr_setschedpolicy (int /*<<< orphan*/ *,int) ; 
 int pthread_create (int /*<<< orphan*/ *,int /*<<< orphan*/ *,void* (*) (void*),void*) ; 
 int /*<<< orphan*/  pthread_exit (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_join (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_kill (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_1__ requeued ; 
 scalar_t__ sigaction (int /*<<< orphan*/ ,struct sigaction*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sigemptyset (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  strerror (int) ; 
 int /*<<< orphan*/  usleep (int /*<<< orphan*/ ) ; 
 char* waiter_ret ; 

void usage(char *prog)
{
	printf("Usage: %s\n", prog);
	printf("  -c	Use color\n");
	printf("  -h	Display this help message\n");
	printf("  -v L	Verbosity level: %d=QUIET %d=CRITICAL %d=INFO\n",
	       VQUIET, VCRITICAL, VINFO);
}

int create_rt_thread(pthread_t *pth, void*(*func)(void *), void *arg,
		     int policy, int prio)
{
	struct sched_param schedp;
	pthread_attr_t attr;
	int ret;

	pthread_attr_init(&attr);
	memset(&schedp, 0, sizeof(schedp));

	ret = pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
	if (ret) {
		error("pthread_attr_setinheritsched\n", ret);
		return -1;
	}

	ret = pthread_attr_setschedpolicy(&attr, policy);
	if (ret) {
		error("pthread_attr_setschedpolicy\n", ret);
		return -1;
	}

	schedp.sched_priority = prio;
	ret = pthread_attr_setschedparam(&attr, &schedp);
	if (ret) {
		error("pthread_attr_setschedparam\n", ret);
		return -1;
	}

	ret = pthread_create(pth, &attr, func, arg);
	if (ret) {
		error("pthread_create\n", ret);
		return -1;
	}
	return 0;
}

void handle_signal(int signo)
{
	info("signal received %s requeue\n",
	     requeued.val ? "after" : "prior to");
}

void *waiterfn(void *arg)
{
	unsigned int old_val;
	int res;

	waiter_ret = RET_PASS;

	info("Waiter running\n");
	info("Calling FUTEX_LOCK_PI on f2=%x @ %p\n", f2, &f2);
	old_val = f1;
	res = futex_wait_requeue_pi(&f1, old_val, &(f2), NULL,
				    FUTEX_PRIVATE_FLAG);
	if (!requeued.val || errno != EWOULDBLOCK) {
		fail("unexpected return from futex_wait_requeue_pi: %d (%s)\n",
		     res, strerror(errno));
		info("w2:futex: %x\n", f2);
		if (!res)
			futex_unlock_pi(&f2, FUTEX_PRIVATE_FLAG);
		waiter_ret = RET_FAIL;
	}

	info("Waiter exiting with %d\n", waiter_ret);
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	unsigned int old_val;
	struct sigaction sa;
	pthread_t waiter;
	int c, res, ret = RET_PASS;

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
	ksft_print_msg("%s: Test signal handling during requeue_pi\n",
	       basename(argv[0]));
	ksft_print_msg("\tArguments: <none>\n");

	sa.sa_handler = handle_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL)) {
		error("sigaction\n", errno);
		exit(1);
	}

	info("m1:f2: %x\n", f2);
	info("Creating waiter\n");
	res = create_rt_thread(&waiter, waiterfn, NULL, SCHED_FIFO, 1);
	if (res) {
		error("Creating waiting thread failed", res);
		ret = RET_ERROR;
		goto out;
	}

	info("Calling FUTEX_LOCK_PI on f2=%x @ %p\n", f2, &f2);
	info("m2:f2: %x\n", f2);
	futex_lock_pi(&f2, 0, 0, FUTEX_PRIVATE_FLAG);
	info("m3:f2: %x\n", f2);

	while (1) {
		/*
		 * signal the waiter before requeue, waiter should automatically
		 * restart futex_wait_requeue_pi() in the kernel. Wait for the
		 * waiter to block on f1 again.
		 */
		info("Issuing SIGUSR1 to waiter\n");
		pthread_kill(waiter, SIGUSR1);
		usleep(DELAY_US);

		info("Requeueing waiter via FUTEX_CMP_REQUEUE_PI\n");
		old_val = f1;
		res = futex_cmp_requeue_pi(&f1, old_val, &(f2), 1, 0,
					   FUTEX_PRIVATE_FLAG);
		/*
		 * If res is non-zero, we either requeued the waiter or hit an
		 * error, break out and handle it. If it is zero, then the
		 * signal may have hit before the the waiter was blocked on f1.
		 * Try again.
		 */
		if (res > 0) {
			atomic_set(&requeued, 1);
			break;
		} else if (res < 0) {
			error("FUTEX_CMP_REQUEUE_PI failed\n", errno);
			ret = RET_ERROR;
			break;
		}
	}
	info("m4:f2: %x\n", f2);

	/*
	 * Signal the waiter after requeue, waiter should return from
	 * futex_wait_requeue_pi() with EWOULDBLOCK. Join the thread here so the
	 * futex_unlock_pi() can't happen before the signal wakeup is detected
	 * in the kernel.
	 */
	info("Issuing SIGUSR1 to waiter\n");
	pthread_kill(waiter, SIGUSR1);
	info("Waiting for waiter to return\n");
	pthread_join(waiter, NULL);

	info("Calling FUTEX_UNLOCK_PI on mutex=%x @ %p\n", f2, &f2);
	futex_unlock_pi(&f2, FUTEX_PRIVATE_FLAG);
	info("m5:f2: %x\n", f2);

 out:
	if (ret == RET_PASS && waiter_ret)
		ret = waiter_ret;

	print_result(TEST_NAME, ret);
	return ret;
}

