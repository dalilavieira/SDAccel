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
typedef  int /*<<< orphan*/  sigset_t ;
struct TYPE_3__ {int si_signo; } ;
typedef  TYPE_1__ siginfo_t ;

/* Variables and functions */
 scalar_t__ sigtimedwait (int /*<<< orphan*/  const*,TYPE_1__*,int /*<<< orphan*/ ) ; 

int sigwait(const sigset_t *restrict mask, int *restrict sig)
{
	siginfo_t si;
	if (sigtimedwait(mask, &si, 0) < 0)
		return -1;
	*sig = si.si_signo;
	return 0;
}

