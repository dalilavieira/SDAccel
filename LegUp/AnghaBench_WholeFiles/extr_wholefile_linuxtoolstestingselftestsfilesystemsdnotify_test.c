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
struct sigaction {void (* sa_sigaction ) (int,TYPE_1__*,void*) ;int /*<<< orphan*/  sa_flags; int /*<<< orphan*/  sa_mask; } ;
struct TYPE_3__ {int si_fd; } ;
typedef  TYPE_1__ siginfo_t ;

/* Variables and functions */
 int DN_CREATE ; 
 int DN_MODIFY ; 
 int DN_MULTISHOT ; 
 int /*<<< orphan*/  F_NOTIFY ; 
 int /*<<< orphan*/  F_SETSIG ; 
 int /*<<< orphan*/  O_RDONLY ; 
 int /*<<< orphan*/  SA_SIGINFO ; 
 int SIGRTMIN ; 
 int event_fd ; 
 int /*<<< orphan*/  fcntl (int,int /*<<< orphan*/ ,int) ; 
 int open (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pause () ; 
 int /*<<< orphan*/  printf (char*,int) ; 
 int /*<<< orphan*/  sigaction (int,struct sigaction*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sigemptyset (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void handler(int sig, siginfo_t *si, void *data)
{
	event_fd = si->si_fd;
}

int main(void)
{
	struct sigaction act;
	int fd;

	act.sa_sigaction = handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGRTMIN + 1, &act, NULL);

	fd = open(".", O_RDONLY);
	fcntl(fd, F_SETSIG, SIGRTMIN + 1);
	fcntl(fd, F_NOTIFY, DN_MODIFY|DN_CREATE|DN_MULTISHOT);
	/* we will now be notified if any of the files
	   in "." is modified or new files are created */
	while (1) {
		pause();
		printf("Got event on fd=%d\n", event_fd);
	}
}

