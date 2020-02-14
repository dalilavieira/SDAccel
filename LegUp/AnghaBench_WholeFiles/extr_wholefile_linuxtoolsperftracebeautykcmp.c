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
struct syscall_arg {unsigned long val; int idx; int mask; int /*<<< orphan*/  trace; } ;
typedef  void* pid_t ;
typedef  int /*<<< orphan*/  DEFINE_STRARRAY ;

/* Variables and functions */
 int KCMP_FILE ; 
 size_t pid__scnprintf_fd (int /*<<< orphan*/ ,void*,unsigned long,char*,size_t) ; 
 int /*<<< orphan*/  strarray__kcmp_types ; 
 size_t strarray__scnprintf (int /*<<< orphan*/ *,char*,size_t,char*,int) ; 
 size_t syscall_arg__scnprintf_long (char*,size_t,struct syscall_arg*) ; 
 void* syscall_arg__val (struct syscall_arg*,int) ; 

size_t syscall_arg__scnprintf_kcmp_idx(char *bf, size_t size, struct syscall_arg *arg)
{
	unsigned long fd = arg->val;
	int type = syscall_arg__val(arg, 2);
	pid_t pid;

	if (type != KCMP_FILE)
		return syscall_arg__scnprintf_long(bf, size, arg);

	pid = syscall_arg__val(arg, arg->idx == 3 ? 0 : 1); /* idx1 -> pid1, idx2 -> pid2 */
	return pid__scnprintf_fd(arg->trace, pid, fd, bf, size);
}

__attribute__((used)) static size_t kcmp__scnprintf_type(int type, char *bf, size_t size)
{
	static DEFINE_STRARRAY(kcmp_types);
	return strarray__scnprintf(&strarray__kcmp_types, bf, size, "%d", type);
}

size_t syscall_arg__scnprintf_kcmp_type(char *bf, size_t size, struct syscall_arg *arg)
{
	unsigned long type = arg->val;

	if (type != KCMP_FILE)
		arg->mask |= (1 << 3) | (1 << 4); /* Ignore idx1 and idx2 */

	return kcmp__scnprintf_type(type, bf, size);
}

