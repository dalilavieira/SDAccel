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
struct ctx {int fd; int* filename; int amode; } ;
typedef  int /*<<< orphan*/  sigset_t ;
typedef  int pid_t ;

/* Variables and functions */
 int AT_EACCESS ; 
 int EBUSY ; 
 int EINVAL ; 
 int /*<<< orphan*/  SYS_exit ; 
 int /*<<< orphan*/  SYS_faccessat ; 
 int /*<<< orphan*/  SYS_getegid ; 
 int /*<<< orphan*/  SYS_geteuid ; 
 int /*<<< orphan*/  SYS_setregid ; 
 int /*<<< orphan*/  SYS_setreuid ; 
 int /*<<< orphan*/  SYS_wait4 ; 
 size_t WEXITSTATUS (int) ; 
 scalar_t__ WIFEXITED (int) ; 
 int /*<<< orphan*/  WIFSIGNALED (int) ; 
 int __WCLONE ; 
 int /*<<< orphan*/  __block_all_sigs (int /*<<< orphan*/ *) ; 
 int __clone (int (*) (void*),char*,int /*<<< orphan*/ ,struct ctx*) ; 
 int /*<<< orphan*/  __restore_sigs (int /*<<< orphan*/ *) ; 
 int __syscall (int /*<<< orphan*/ ,...) ; 
 int __syscall_ret (int) ; 
 int* errors ; 
 scalar_t__ getegid () ; 
 scalar_t__ geteuid () ; 
 scalar_t__ getgid () ; 
 scalar_t__ getuid () ; 
 int syscall (int /*<<< orphan*/ ,int,char const*,int,int) ; 

__attribute__((used)) static int checker(void *p)
{
	struct ctx *c = p;
	int ret;
	int i;
	if (__syscall(SYS_setregid, __syscall(SYS_getegid), -1)
	    || __syscall(SYS_setreuid, __syscall(SYS_geteuid), -1))
		__syscall(SYS_exit, 1);
	ret = __syscall(SYS_faccessat, c->fd, c->filename, c->amode, 0);
	for (i=0; i < sizeof errors/sizeof *errors - 1 && ret!=errors[i]; i++);
	return i;
}

int faccessat(int fd, const char *filename, int amode, int flag)
{
	if (!flag || (flag==AT_EACCESS && getuid()==geteuid() && getgid()==getegid()))
		return syscall(SYS_faccessat, fd, filename, amode, flag);

	if (flag != AT_EACCESS)
		return __syscall_ret(-EINVAL);

	char stack[1024];
	sigset_t set;
	pid_t pid;
	int ret = -EBUSY;
	struct ctx c = { .fd = fd, .filename = filename, .amode = amode };

	__block_all_sigs(&set);
	
	pid = __clone(checker, stack+sizeof stack, 0, &c);
	if (pid > 0) {
		int status;
		do {
			__syscall(SYS_wait4, pid, &status, __WCLONE, 0);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		if (WIFEXITED(status))
			ret = errors[WEXITSTATUS(status)];
	}

	__restore_sigs(&set);

	return __syscall_ret(ret);
}

