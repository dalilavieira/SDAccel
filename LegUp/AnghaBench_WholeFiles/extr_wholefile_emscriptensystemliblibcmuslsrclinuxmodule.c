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
 int /*<<< orphan*/  SYS_delete_module ; 
 int /*<<< orphan*/  SYS_init_module ; 
 int syscall (int /*<<< orphan*/ ,char const*,unsigned int,...) ; 

int init_module(void *a, unsigned long b, const char *c)
{
	return syscall(SYS_init_module, a, b, c);
}

int delete_module(const char *a, unsigned b)
{
	return syscall(SYS_delete_module, a, b);
}

