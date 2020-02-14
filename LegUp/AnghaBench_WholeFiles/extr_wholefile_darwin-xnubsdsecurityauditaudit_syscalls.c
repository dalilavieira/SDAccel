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
struct setauid_args {int dummy; } ;
struct setaudit_addr_args {int dummy; } ;
struct getauid_args {int dummy; } ;
struct getaudit_addr_args {int dummy; } ;
struct auditon_args {int dummy; } ;
struct auditctl_args {int dummy; } ;
struct audit_args {int dummy; } ;
typedef  int /*<<< orphan*/  proc_t ;
typedef  int /*<<< orphan*/  int32_t ;

/* Variables and functions */
 int ENOSYS ; 

int
audit(proc_t p, struct audit_args *uap, int32_t *retval)
{
#pragma unused(p, uap, retval)

	return (ENOSYS);
}

int
auditon(proc_t p, struct auditon_args *uap, int32_t *retval)
{
#pragma unused(p, uap, retval)

	return (ENOSYS);
}

int
getauid(proc_t p, struct getauid_args *uap, int32_t *retval)
{
#pragma unused(p, uap, retval)

	return (ENOSYS);
}

int
setauid(proc_t p, struct setauid_args *uap, int32_t *retval)
{
#pragma unused(p, uap, retval)

	return (ENOSYS);
}

int
getaudit_addr(proc_t p, struct getaudit_addr_args *uap, int32_t *retval)
{
#pragma unused(p, uap, retval)

	return (ENOSYS);
}

int
setaudit_addr(proc_t p, struct setaudit_addr_args *uap, int32_t *retval)
{
#pragma unused(p, uap, retval)

	return (ENOSYS);
}

int
auditctl(proc_t p, struct auditctl_args *uap, int32_t *retval)
{
#pragma unused(p, uap, retval)

	return (ENOSYS);
}

