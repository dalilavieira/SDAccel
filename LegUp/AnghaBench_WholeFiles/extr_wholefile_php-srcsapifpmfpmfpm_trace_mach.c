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
typedef  scalar_t__ vm_offset_t ;
typedef  int /*<<< orphan*/  pid_t ;
typedef  scalar_t__ kern_return_t ;
typedef  scalar_t__ addr ;

/* Variables and functions */
 int /*<<< orphan*/  FPM_PCTL_STOP ; 
 scalar_t__ KERN_FAILURE ; 
 scalar_t__ KERN_SUCCESS ; 
 int /*<<< orphan*/  ZLOG_ERROR ; 
 int /*<<< orphan*/  ZLOG_SYSERROR ; 
 uintptr_t fpm_pagesize ; 
 scalar_t__ fpm_pctl_kill (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ local_page ; 
 scalar_t__ local_size ; 
 int /*<<< orphan*/  mach_error_string (scalar_t__) ; 
 int /*<<< orphan*/  mach_task_self () ; 
 int /*<<< orphan*/  mach_vm_deallocate (int /*<<< orphan*/ ,scalar_t__,scalar_t__) ; 
 scalar_t__ mach_vm_read (scalar_t__,scalar_t__,uintptr_t,scalar_t__*,scalar_t__*) ; 
 scalar_t__ target ; 
 scalar_t__ target_page_base ; 
 scalar_t__ task_for_pid (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__*) ; 
 int /*<<< orphan*/  zlog (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,...) ; 

__attribute__((used)) static void fpm_mach_vm_deallocate() /* {{{ */
{
	if (local_page) {
		mach_vm_deallocate(mach_task_self(), local_page, local_size);
		target_page_base = 0;
		local_page = 0;
		local_size = 0;
	}
}

__attribute__((used)) static int fpm_mach_vm_read_page(vm_offset_t page) /* {{{ */
{
	kern_return_t kr;

	kr = mach_vm_read(target, page, fpm_pagesize, &local_page, &local_size);
	if (kr != KERN_SUCCESS) {
		zlog(ZLOG_ERROR, "failed to read vm page: mach_vm_read(): %s (%d)", mach_error_string(kr), kr);
		return -1;
	}
	return 0;
}

int fpm_trace_signal(pid_t pid) /* {{{ */
{
	if (0 > fpm_pctl_kill(pid, FPM_PCTL_STOP)) {
		zlog(ZLOG_SYSERROR, "failed to send SIGSTOP to %d", pid);
		return -1;
	}
	return 0;
}

int fpm_trace_ready(pid_t pid) /* {{{ */
{
	kern_return_t kr;

	kr = task_for_pid(mach_task_self(), pid, &target);
	if (kr != KERN_SUCCESS) {
		char *msg = "";

		if (kr == KERN_FAILURE) {
			msg = " It seems that master process does not have enough privileges to trace processes.";
		}
		zlog(ZLOG_ERROR, "task_for_pid() failed: %s (%d)%s", mach_error_string(kr), kr, msg);
		return -1;
	}
	return 0;
}

int fpm_trace_close(pid_t pid) /* {{{ */
{
	fpm_mach_vm_deallocate();
	target = 0;
	return 0;
}

int fpm_trace_get_long(long addr, long *data) /* {{{ */
{
	size_t offset = ((uintptr_t) (addr) % fpm_pagesize);
	vm_offset_t base = (uintptr_t) (addr) - offset;

	if (base != target_page_base) {
		fpm_mach_vm_deallocate();
		if (0 > fpm_mach_vm_read_page(base)) {
			return -1;
		}
	}
	*data = * (long *) (local_page + offset);
	return 0;
}

