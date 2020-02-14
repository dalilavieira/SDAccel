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
typedef  int ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  SYS_fgetxattr ; 
 int /*<<< orphan*/  SYS_flistxattr ; 
 int /*<<< orphan*/  SYS_fremovexattr ; 
 int /*<<< orphan*/  SYS_fsetxattr ; 
 int /*<<< orphan*/  SYS_getxattr ; 
 int /*<<< orphan*/  SYS_lgetxattr ; 
 int /*<<< orphan*/  SYS_listxattr ; 
 int /*<<< orphan*/  SYS_llistxattr ; 
 int /*<<< orphan*/  SYS_lremovexattr ; 
 int /*<<< orphan*/  SYS_lsetxattr ; 
 int /*<<< orphan*/  SYS_removexattr ; 
 int /*<<< orphan*/  SYS_setxattr ; 
 int syscall (int /*<<< orphan*/ ,...) ; 

ssize_t getxattr(const char *path, const char *name, void *value, size_t size)
{
	return syscall(SYS_getxattr, path, name, value, size);
}

ssize_t lgetxattr(const char *path, const char *name, void *value, size_t size)
{
	return syscall(SYS_lgetxattr, path, name, value, size);
}

ssize_t fgetxattr(int filedes, const char *name, void *value, size_t size)
{
	return syscall(SYS_fgetxattr, filedes, name, value, size);
}

ssize_t listxattr(const char *path, char *list, size_t size)
{
	return syscall(SYS_listxattr, path, list, size);
}

ssize_t llistxattr(const char *path, char *list, size_t size)
{
	return syscall(SYS_llistxattr, path, list, size);
}

ssize_t flistxattr(int filedes, char *list, size_t size)
{
	return syscall(SYS_flistxattr, filedes, list, size);
}

int setxattr(const char *path, const char *name, const void *value, size_t size, int flags)
{
	return syscall(SYS_setxattr, path, name, value, size, flags);
}

int lsetxattr(const char *path, const char *name, const void *value, size_t size, int flags)
{
	return syscall(SYS_lsetxattr, path, name, value, size, flags);
}

int fsetxattr(int filedes, const char *name, const void *value, size_t size, int flags)
{
	return syscall(SYS_fsetxattr, filedes, name, value, size, flags);
}

int removexattr(const char *path, const char *name)
{
	return syscall(SYS_removexattr, path, name);
}

int lremovexattr(const char *path, const char *name)
{
	return syscall(SYS_lremovexattr, path, name);
}

int fremovexattr(int fd, const char *name)
{
	return syscall(SYS_fremovexattr, fd, name);
}

