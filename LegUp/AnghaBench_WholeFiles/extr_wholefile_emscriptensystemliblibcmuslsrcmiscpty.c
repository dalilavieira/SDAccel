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

/* Variables and functions */
 int ERANGE ; 
 int /*<<< orphan*/  SYS_ioctl ; 
 int /*<<< orphan*/  TIOCGPTN ; 
 int /*<<< orphan*/  TIOCSPTLCK ; 
 int __syscall (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int*) ; 
 int ioctl (int,int /*<<< orphan*/ ,int*) ; 
 int open (char*,int) ; 
 size_t snprintf (char*,size_t,char*,int) ; 

int posix_openpt(int flags)
{
	return open("/dev/ptmx", flags);
}

int grantpt(int fd)
{
	return 0;
}

int unlockpt(int fd)
{
	int unlock = 0;
	return ioctl(fd, TIOCSPTLCK, &unlock);
}

int __ptsname_r(int fd, char *buf, size_t len)
{
	int pty, err;
	if (!buf) len = 0;
	if ((err = __syscall(SYS_ioctl, fd, TIOCGPTN, &pty))) return -err;
	if (snprintf(buf, len, "/dev/pts/%d", pty) >= len) return ERANGE;
	return 0;
}

