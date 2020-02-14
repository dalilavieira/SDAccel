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
 int EACCES ; 
 int EPERM ; 
 int /*<<< orphan*/  SYS_mq_unlink ; 
 int __syscall (int /*<<< orphan*/ ,char const*) ; 
 int errno ; 

int mq_unlink(const char *name)
{
	int ret;
	if (*name == '/') name++;
	ret = __syscall(SYS_mq_unlink, name);
	if (ret < 0) {
		if (ret == -EPERM) ret = -EACCES;
		errno = -ret;
		return -1;
	}
	return ret;
}

