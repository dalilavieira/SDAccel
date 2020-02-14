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
#define  __NR_execve 128 
 int audit_classify_compat_syscall (int,unsigned int) ; 
 scalar_t__ audit_is_compat (int) ; 

int audit_classify_arch(int arch)
{
	if (audit_is_compat(arch))
		return 1;
	else
		return 0;
}

int audit_classify_syscall(int abi, unsigned syscall)
{
	if (audit_is_compat(abi))
		return audit_classify_compat_syscall(abi, syscall);

	switch(syscall) {
#ifdef __NR_open
	case __NR_open:
		return 2;
#endif
#ifdef __NR_openat
	case __NR_openat:
		return 3;
#endif
#ifdef __NR_socketcall
	case __NR_socketcall:
		return 4;
#endif
#ifdef __NR_execveat
	case __NR_execveat:
#endif
	case __NR_execve:
		return 5;
	default:
		return 0;
	}
}

