#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  TYPE_1__* pthread_t ;
typedef  int /*<<< orphan*/  pid_t ;
typedef  int /*<<< orphan*/  const cpu_set_t ;
struct TYPE_4__ {int /*<<< orphan*/  tid; } ;

/* Variables and functions */
 int /*<<< orphan*/  SYS_sched_getaffinity ; 
 int /*<<< orphan*/  SYS_sched_setaffinity ; 
 int __syscall (int /*<<< orphan*/ ,int /*<<< orphan*/ ,size_t,int /*<<< orphan*/  const*) ; 
 int __syscall_ret (int) ; 
 int /*<<< orphan*/  memset (char*,int /*<<< orphan*/ ,size_t) ; 
 int syscall (int /*<<< orphan*/ ,int /*<<< orphan*/ ,size_t,int /*<<< orphan*/  const*) ; 

int sched_setaffinity(pid_t tid, size_t size, const cpu_set_t *set)
{
	return syscall(SYS_sched_setaffinity, tid, size, set);
}

int pthread_setaffinity_np(pthread_t td, size_t size, const cpu_set_t *set)
{
	return -__syscall(SYS_sched_setaffinity, td->tid, size, set);
}

__attribute__((used)) static int do_getaffinity(pid_t tid, size_t size, cpu_set_t *set)
{
	long ret = __syscall(SYS_sched_getaffinity, tid, size, set);
	if (ret < 0) return ret;
	if (ret < size) memset((char *)set+ret, 0, size-ret);
	return 0;
}

int sched_getaffinity(pid_t tid, size_t size, cpu_set_t *set)
{
	return __syscall_ret(do_getaffinity(tid, size, set));
}

int pthread_getaffinity_np(pthread_t td, size_t size, cpu_set_t *set)
{
	return -do_getaffinity(td->tid, size, set);
}

