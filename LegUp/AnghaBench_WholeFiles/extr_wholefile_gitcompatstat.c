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
struct stat {int st_mode; } ;
typedef  int mode_t ;

/* Variables and functions */
 scalar_t__ S_ISBLK (int) ; 
 scalar_t__ S_ISCHR (int) ; 
 scalar_t__ S_ISDIR (int) ; 
 scalar_t__ S_ISFIFO (int) ; 
 scalar_t__ S_ISLNK (int) ; 
 scalar_t__ S_ISREG (int) ; 
 scalar_t__ S_ISSOCK (int) ; 
 int fstat (int,struct stat*) ; 
 int lstat (char const*,struct stat*) ; 
 int stat (char const*,struct stat*) ; 

__attribute__((used)) static inline mode_t mode_native_to_git(mode_t native_mode)
{
	mode_t perm_bits = native_mode & 07777;
	if (S_ISREG(native_mode))
		return 0100000 | perm_bits;
	if (S_ISDIR(native_mode))
		return 0040000 | perm_bits;
	if (S_ISLNK(native_mode))
		return 0120000 | perm_bits;
	if (S_ISBLK(native_mode))
		return 0060000 | perm_bits;
	if (S_ISCHR(native_mode))
		return 0020000 | perm_bits;
	if (S_ISFIFO(native_mode))
		return 0010000 | perm_bits;
	if (S_ISSOCK(native_mode))
		return 0140000 | perm_bits;
	/* Non-standard type bits were given. */
	return perm_bits;
}

int git_stat(const char *path, struct stat *buf)
{
	int rc = stat(path, buf);
	if (rc == 0)
		buf->st_mode = mode_native_to_git(buf->st_mode);
	return rc;
}

int git_fstat(int fd, struct stat *buf)
{
	int rc = fstat(fd, buf);
	if (rc == 0)
		buf->st_mode = mode_native_to_git(buf->st_mode);
	return rc;
}

int git_lstat(const char *path, struct stat *buf)
{
	int rc = lstat(path, buf);
	if (rc == 0)
		buf->st_mode = mode_native_to_git(buf->st_mode);
	return rc;
}

