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
 int /*<<< orphan*/  SYS_swapoff ; 
 int /*<<< orphan*/  SYS_swapon ; 
 int syscall (int /*<<< orphan*/ ,char const*,...) ; 

int swapon(const char *path, int flags)
{
	return syscall(SYS_swapon, path, flags);
}

int swapoff(const char *path)
{
	return syscall(SYS_swapoff, path);
}

