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
struct sched_param {int dummy; } ;
typedef  int /*<<< orphan*/  pid_t ;

/* Variables and functions */
 int /*<<< orphan*/  ENOSYS ; 
 int __syscall_ret (int /*<<< orphan*/ ) ; 

int sched_setscheduler(pid_t pid, int sched, const struct sched_param *param)
{
	return __syscall_ret(-ENOSYS);
}

