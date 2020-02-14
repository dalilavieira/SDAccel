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
struct syscall_arg {int val; } ;

/* Variables and functions */
 int SECCOMP_FILTER_FLAG_TSYNC ; 
#define  SECCOMP_SET_MODE_FILTER 129 
#define  SECCOMP_SET_MODE_STRICT 128 
 size_t scnprintf (char*,size_t,char*,...) ; 

__attribute__((used)) static size_t syscall_arg__scnprintf_seccomp_op(char *bf, size_t size, struct syscall_arg *arg)
{
	int op = arg->val;
	size_t printed = 0;

	switch (op) {
#define	P_SECCOMP_SET_MODE_OP(n) case SECCOMP_SET_MODE_##n: printed = scnprintf(bf, size, #n); break
	P_SECCOMP_SET_MODE_OP(STRICT);
	P_SECCOMP_SET_MODE_OP(FILTER);
#undef P_SECCOMP_SET_MODE_OP
	default: printed = scnprintf(bf, size, "%#x", op);			  break;
	}

	return printed;
}

__attribute__((used)) static size_t syscall_arg__scnprintf_seccomp_flags(char *bf, size_t size,
						   struct syscall_arg *arg)
{
	int printed = 0, flags = arg->val;

#define	P_FLAG(n) \
	if (flags & SECCOMP_FILTER_FLAG_##n) { \
		printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
		flags &= ~SECCOMP_FILTER_FLAG_##n; \
	}

	P_FLAG(TSYNC);
#undef P_FLAG

	if (flags)
		printed += scnprintf(bf + printed, size - printed, "%s%#x", printed ? "|" : "", flags);

	return printed;
}

