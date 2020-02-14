#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int entry_number; } ;
typedef  TYPE_1__ user_desc_t ;

/* Variables and functions */
 int ARRAY_SIZE (int*) ; 
 int EINVAL ; 
 int ENOSYS ; 
 int GDT_ENTRY_TLS_MIN_I386 ; 
 int GDT_ENTRY_TLS_MIN_X86_64 ; 
 int /*<<< orphan*/  PTRACE_GET_THREAD_AREA ; 
 int /*<<< orphan*/  PTRACE_SET_THREAD_AREA ; 
 int /*<<< orphan*/  __NR_get_thread_area ; 
 int errno ; 
 int ptrace (int /*<<< orphan*/ ,int,int,unsigned long) ; 
 scalar_t__ syscall (int /*<<< orphan*/ ,TYPE_1__*) ; 

void check_host_supports_tls(int *supports_tls, int *tls_min)
{
	/* Values for x86 and x86_64.*/
	int val[] = {GDT_ENTRY_TLS_MIN_I386, GDT_ENTRY_TLS_MIN_X86_64};
	int i;

	for (i = 0; i < ARRAY_SIZE(val); i++) {
		user_desc_t info;
		info.entry_number = val[i];

		if (syscall(__NR_get_thread_area, &info) == 0) {
			*tls_min = val[i];
			*supports_tls = 1;
			return;
		} else {
			if (errno == EINVAL)
				continue;
			else if (errno == ENOSYS)
				*supports_tls = 0;
			return;
		}
	}

	*supports_tls = 0;
}

int os_set_thread_area(user_desc_t *info, int pid)
{
	int ret;

	ret = ptrace(PTRACE_SET_THREAD_AREA, pid, info->entry_number,
		     (unsigned long) info);
	if (ret < 0)
		ret = -errno;
	return ret;
}

int os_get_thread_area(user_desc_t *info, int pid)
{
	int ret;

	ret = ptrace(PTRACE_GET_THREAD_AREA, pid, info->entry_number,
		     (unsigned long) info);
	if (ret < 0)
		ret = -errno;
	return ret;
}

