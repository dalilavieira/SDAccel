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
 int /*<<< orphan*/  SYS_mount ; 
 int /*<<< orphan*/  SYS_umount2 ; 
 int syscall (int /*<<< orphan*/ ,char const*,...) ; 

int mount(const char *special, const char *dir, const char *fstype, unsigned long flags, const void *data)
{
	return syscall(SYS_mount, special, dir, fstype, flags, data);
}

int umount(const char *special)
{
	return syscall(SYS_umount2, special, 0);
}

int umount2(const char *special, int flags)
{
	return syscall(SYS_umount2, special, flags);
}

