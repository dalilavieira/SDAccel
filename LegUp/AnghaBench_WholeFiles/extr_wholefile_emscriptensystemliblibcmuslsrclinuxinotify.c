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
typedef  int /*<<< orphan*/  uint32_t ;

/* Variables and functions */
 int /*<<< orphan*/  SYS_inotify_add_watch ; 
 int /*<<< orphan*/  SYS_inotify_init1 ; 
 int /*<<< orphan*/  SYS_inotify_rm_watch ; 
 int __syscall (int /*<<< orphan*/ ,int) ; 
 int __syscall_ret (int) ; 
 int inotify_init1 (int) ; 
 int syscall (int /*<<< orphan*/ ,int,...) ; 

int inotify_init()
{
	return inotify_init1(0);
}

int inotify_init1(int flags)
{
	int r = __syscall(SYS_inotify_init1, flags);
#ifdef SYS_inotify_init
	if (r==-ENOSYS && !flags) r = __syscall(SYS_inotify_init);
#endif
	return __syscall_ret(r);
}

int inotify_add_watch(int fd, const char *pathname, uint32_t mask)
{
	return syscall(SYS_inotify_add_watch, fd, pathname, mask);
}

int inotify_rm_watch(int fd, int wd)
{
	return syscall(SYS_inotify_rm_watch, fd, wd);
}

