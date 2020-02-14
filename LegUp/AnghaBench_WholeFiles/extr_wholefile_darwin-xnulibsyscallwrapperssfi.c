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
typedef  int /*<<< orphan*/  uint64_t ;
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  sfi_class_id_t ;
typedef  int /*<<< orphan*/  pid_t ;

/* Variables and functions */
 int /*<<< orphan*/  SFI_CTL_OPERATION_GET_CLASS_OFFTIME ; 
 int /*<<< orphan*/  SFI_CTL_OPERATION_SET_CLASS_OFFTIME ; 
 int /*<<< orphan*/  SFI_CTL_OPERATION_SFI_GET_WINDOW ; 
 int /*<<< orphan*/  SFI_CTL_OPERATION_SFI_SET_WINDOW ; 
 int /*<<< orphan*/  SFI_PIDCTL_OPERATION_PID_GET_FLAGS ; 
 int /*<<< orphan*/  SFI_PIDCTL_OPERATION_PID_SET_FLAGS ; 
 int __sfi_ctl (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int __sfi_pidctl (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

int system_set_sfi_window(uint64_t sfi_window_usec)
{
	return __sfi_ctl(SFI_CTL_OPERATION_SFI_SET_WINDOW, 0, sfi_window_usec, NULL);
}

int system_get_sfi_window(uint64_t *sfi_window_usec)
{
	return __sfi_ctl(SFI_CTL_OPERATION_SFI_GET_WINDOW, 0, 0, sfi_window_usec);
}

int sfi_set_class_offtime(sfi_class_id_t class_id, uint64_t offtime_usec)
{
	return __sfi_ctl(SFI_CTL_OPERATION_SET_CLASS_OFFTIME, class_id, offtime_usec, NULL);
}

int sfi_get_class_offtime(sfi_class_id_t class_id, uint64_t *offtime_usec)
{
	return __sfi_ctl(SFI_CTL_OPERATION_GET_CLASS_OFFTIME, class_id, 0, offtime_usec);
}

int sfi_process_set_flags(pid_t pid, uint32_t flags)
{
	return __sfi_pidctl(SFI_PIDCTL_OPERATION_PID_SET_FLAGS, pid, flags, NULL);
}

int sfi_process_get_flags(pid_t pid, uint32_t *flags)
{
	return __sfi_pidctl(SFI_PIDCTL_OPERATION_PID_GET_FLAGS, pid, 0, flags);
}

