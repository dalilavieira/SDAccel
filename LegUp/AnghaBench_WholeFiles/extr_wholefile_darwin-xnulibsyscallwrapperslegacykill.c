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
typedef  int /*<<< orphan*/  pid_t ;

/* Variables and functions */
 int __kill (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 

int
kill(pid_t pid, int sig)
{
#if __DARWIN_UNIX03
	return(__kill(pid, sig, 1));
#else	/* !__DARWIN_UNIX03 */
	return(__kill(pid, sig, 0));
#endif	/* !__DARWIN_UNIX03 */
}

