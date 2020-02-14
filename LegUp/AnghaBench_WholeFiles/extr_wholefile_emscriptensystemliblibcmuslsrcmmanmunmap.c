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
 int /*<<< orphan*/  SYS_munmap ; 
 int /*<<< orphan*/  __vm_wait () ; 
 int syscall (int /*<<< orphan*/ ,void*,size_t) ; 

__attribute__((used)) static void dummy(void) { }

int __munmap(void *start, size_t len)
{
	__vm_wait();
	return syscall(SYS_munmap, start, len);
}

