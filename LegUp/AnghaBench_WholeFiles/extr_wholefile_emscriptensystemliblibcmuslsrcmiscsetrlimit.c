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
typedef  struct rlimit {unsigned long rlim_cur; unsigned long rlim_max; } const rlimit ;
struct ctx {int err; int res; struct rlimit const* rlim; } ;

/* Variables and functions */
 int ENOSYS ; 
 int /*<<< orphan*/  FIX (unsigned long) ; 
 scalar_t__ MIN (unsigned long,scalar_t__) ; 
 scalar_t__ RLIM_INFINITY ; 
 scalar_t__ SYSCALL_RLIM_INFINITY ; 
 int /*<<< orphan*/  SYS_prlimit64 ; 
 int /*<<< orphan*/  SYS_setrlimit ; 
 int /*<<< orphan*/  __synccall (void (*) (void*),struct ctx*) ; 
 int __syscall (int /*<<< orphan*/ ,int,...) ; 
 scalar_t__ errno ; 

int __setrlimit(int resource, const struct rlimit *rlim)
{
	unsigned long k_rlim[2];
	struct rlimit tmp;
	if (SYSCALL_RLIM_INFINITY != RLIM_INFINITY) {
		tmp = *rlim;
		FIX(tmp.rlim_cur);
		FIX(tmp.rlim_max);
		rlim = &tmp;
	}
	int ret = __syscall(SYS_prlimit64, 0, resource, rlim, 0);
	if (ret != -ENOSYS) return ret;
	k_rlim[0] = MIN(rlim->rlim_cur, MIN(-1UL, SYSCALL_RLIM_INFINITY));
	k_rlim[1] = MIN(rlim->rlim_max, MIN(-1UL, SYSCALL_RLIM_INFINITY));
	return __syscall(SYS_setrlimit, resource, k_rlim);
}

__attribute__((used)) static void do_setrlimit(void *p)
{
	struct ctx *c = p;
	if (c->err>0) return;
	c->err = -__setrlimit(c->res, c->rlim);
}

int setrlimit(int resource, const struct rlimit *rlim)
{
	struct ctx c = { .res = resource, .rlim = rlim, .err = -1 };
	__synccall(do_setrlimit, &c);
	if (c.err) {
		if (c.err>0) errno = c.err;
		return -1;
	}
	return 0;
}

