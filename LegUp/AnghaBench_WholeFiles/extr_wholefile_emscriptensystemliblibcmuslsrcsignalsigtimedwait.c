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
struct timespec {int dummy; } ;
typedef  int /*<<< orphan*/  sigset_t ;
typedef  int /*<<< orphan*/  siginfo_t ;

/* Variables and functions */
 scalar_t__ EINTR ; 
 int /*<<< orphan*/  SYS_rt_sigtimedwait ; 
 int _NSIG ; 
 scalar_t__ errno ; 
 int syscall_cp (int /*<<< orphan*/ ,int /*<<< orphan*/  const*,int /*<<< orphan*/ *,struct timespec const*,int) ; 

int sigtimedwait(const sigset_t *restrict mask, siginfo_t *restrict si, const struct timespec *restrict timeout)
{
	int ret;
	do ret = syscall_cp(SYS_rt_sigtimedwait, mask,
		si, timeout, _NSIG/8);
	while (ret<0 && errno==EINTR);
	return ret;
}

