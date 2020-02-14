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
typedef  int /*<<< orphan*/  mach_port_t ;
typedef  int /*<<< orphan*/  kern_return_t ;

/* Variables and functions */
 int /*<<< orphan*/  KERN_FAILURE ; 
 int /*<<< orphan*/  mach_host_self () ; 
 int /*<<< orphan*/  mach_task_self () ; 

kern_return_t
msg_rpc(void) {
	return KERN_FAILURE;
}

kern_return_t
msg_send(void) {
	return KERN_FAILURE;
}

kern_return_t
msg_receive(void) {
	return KERN_FAILURE;
}

mach_port_t
task_self_(void) {
	return mach_task_self();
}

mach_port_t
host_self(void) {
	return mach_host_self();
}

