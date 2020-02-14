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
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  AT_FDCWD ; 
 int /*<<< orphan*/  SYS_readlinkat ; 
 int /*<<< orphan*/  syscall (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char const*,char*,size_t) ; 

ssize_t readlink(const char *restrict path, char *restrict buf, size_t bufsize)
{
#ifdef SYS_readlink
	return syscall(SYS_readlink, path, buf, bufsize);
#else
	return syscall(SYS_readlinkat, AT_FDCWD, path, buf, bufsize);
#endif
}

