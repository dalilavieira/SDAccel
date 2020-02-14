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
struct pollfd {int fd; int /*<<< orphan*/  events; } ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  buf ;

/* Variables and functions */
 int /*<<< orphan*/  EVENT_WAIT_MSEC ; 
 int /*<<< orphan*/  EXIT_FAILURE ; 
 int HOST_MSG_SIZE ; 
 int /*<<< orphan*/  O_RDONLY ; 
 int /*<<< orphan*/  POLLIN ; 
 int /*<<< orphan*/  SIGINT ; 
 int /*<<< orphan*/  SIGQUIT ; 
 int /*<<< orphan*/  SIGTERM ; 
 void* calloc (int,size_t) ; 
 int /*<<< orphan*/  cond_wakeup ; 
 int /*<<< orphan*/  exit (int /*<<< orphan*/ ) ; 
 int global_run_operation ; 
 int global_sig_receive ; 
 int global_signal_val ; 
 int open (char const*,int /*<<< orphan*/ ) ; 
 int poll (struct pollfd*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_debug (char*) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int /*<<< orphan*/  pr_info (char*,...) ; 
 int /*<<< orphan*/  pthread_cond_broadcast (int /*<<< orphan*/ *) ; 
 int read (int,char*,int) ; 
 int /*<<< orphan*/  signal (int /*<<< orphan*/ ,void (*) (int)) ; 

__attribute__((used)) static inline void *zalloc(size_t size)
{
	return calloc(1, size);
}

__attribute__((used)) static void signal_handler(int sig)
{
	global_signal_val = sig;
}

int rw_ctl_init(const char *ctl_path)
{
	int ctl_fd;

	ctl_fd = open(ctl_path, O_RDONLY);
	if (ctl_fd == -1) {
		pr_err("Cannot open ctl_fd\n");
		goto error;
	}

	return ctl_fd;

error:
	exit(EXIT_FAILURE);
}

__attribute__((used)) static int wait_order(int ctl_fd)
{
	struct pollfd poll_fd;
	int ret = 0;

	while (!global_sig_receive) {
		poll_fd.fd = ctl_fd;
		poll_fd.events = POLLIN;

		ret = poll(&poll_fd, 1, EVENT_WAIT_MSEC);

		if (global_signal_val) {
			global_sig_receive = true;
			pr_info("Receive interrupt %d\n", global_signal_val);

			/* Wakes rw-threads when they are sleeping */
			if (!global_run_operation)
				pthread_cond_broadcast(&cond_wakeup);

			ret = -1;
			break;
		}

		if (ret < 0) {
			pr_err("Polling error\n");
			goto error;
		}

		if (ret)
			break;
	};

	return ret;

error:
	exit(EXIT_FAILURE);
}

void *rw_ctl_loop(int ctl_fd)
{
	ssize_t rlen;
	char buf[HOST_MSG_SIZE];
	int ret;

	/* Setup signal handlers */
	signal(SIGTERM, signal_handler);
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);

	while (!global_sig_receive) {

		ret = wait_order(ctl_fd);
		if (ret < 0)
			break;

		rlen = read(ctl_fd, buf, sizeof(buf));
		if (rlen < 0) {
			pr_err("read data error in ctl thread\n");
			goto error;
		}

		if (rlen == 2 && buf[0] == '1') {
			/*
			 * If host writes '1' to a control path,
			 * this controller wakes all read/write threads.
			 */
			global_run_operation = true;
			pthread_cond_broadcast(&cond_wakeup);
			pr_debug("Wake up all read/write threads\n");
		} else if (rlen == 2 && buf[0] == '0') {
			/*
			 * If host writes '0' to a control path, read/write
			 * threads will wait for notification from Host.
			 */
			global_run_operation = false;
			pr_debug("Stop all read/write threads\n");
		} else
			pr_info("Invalid host notification: %s\n", buf);
	}

	return NULL;

error:
	exit(EXIT_FAILURE);
}

