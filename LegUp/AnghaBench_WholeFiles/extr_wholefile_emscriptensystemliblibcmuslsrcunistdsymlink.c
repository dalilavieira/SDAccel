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
 int /*<<< orphan*/  AT_FDCWD ; 
 int /*<<< orphan*/  SYS_symlinkat ; 
 int syscall (int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ ,char const*) ; 

int symlink(const char *existing, const char *new)
{
#ifdef SYS_symlink
	return syscall(SYS_symlink, existing, new);
#else
	return syscall(SYS_symlinkat, existing, AT_FDCWD, new);
#endif
}

