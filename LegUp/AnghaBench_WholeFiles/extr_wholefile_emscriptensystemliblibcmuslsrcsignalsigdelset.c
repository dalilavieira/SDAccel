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
struct TYPE_3__ {unsigned long* __bits; } ;
typedef  TYPE_1__ sigset_t ;

/* Variables and functions */
 int /*<<< orphan*/  EINVAL ; 
 int _NSIG ; 
 int /*<<< orphan*/  errno ; 

int sigdelset(sigset_t *set, int sig)
{
	unsigned s = sig-1;
	if (s >= _NSIG-1 || sig-32U < 3) {
		errno = EINVAL;
		return -1;
	}
	set->__bits[s/8/sizeof *set->__bits] &=~(1UL<<(s&8*sizeof *set->__bits-1));
	return 0;
}

