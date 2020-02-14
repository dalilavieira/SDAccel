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
struct syscall_arg {int val; } ;

/* Variables and functions */
 int AT_EMPTY_PATH ; 
 int AT_NO_AUTOMOUNT ; 
 int AT_REMOVEDIR ; 
 int AT_STATX_DONT_SYNC ; 
 int AT_STATX_FORCE_SYNC ; 
 int AT_SYMLINK_FOLLOW ; 
 int AT_SYMLINK_NOFOLLOW ; 
 int STATX_ATIME ; 
 int STATX_BLOCKS ; 
 int STATX_BTIME ; 
 int STATX_CTIME ; 
 int STATX_GID ; 
 int STATX_INO ; 
 int STATX_MODE ; 
 int STATX_MTIME ; 
 int STATX_NLINK ; 
 int STATX_SIZE ; 
 int STATX_TYPE ; 
 int STATX_UID ; 
 size_t scnprintf (char*,size_t,char*,...) ; 

size_t syscall_arg__scnprintf_statx_flags(char *bf, size_t size, struct syscall_arg *arg)
{
	int printed = 0, flags = arg->val;

	if (flags == 0)
		return scnprintf(bf, size, "SYNC_AS_STAT");
#define	P_FLAG(n) \
	if (flags & AT_##n) { \
		printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
		flags &= ~AT_##n; \
	}

	P_FLAG(SYMLINK_NOFOLLOW);
	P_FLAG(REMOVEDIR);
	P_FLAG(SYMLINK_FOLLOW);
	P_FLAG(NO_AUTOMOUNT);
	P_FLAG(EMPTY_PATH);
	P_FLAG(STATX_FORCE_SYNC);
	P_FLAG(STATX_DONT_SYNC);

#undef P_FLAG

	if (flags)
		printed += scnprintf(bf + printed, size - printed, "%s%#x", printed ? "|" : "", flags);

	return printed;
}

size_t syscall_arg__scnprintf_statx_mask(char *bf, size_t size, struct syscall_arg *arg)
{
	int printed = 0, flags = arg->val;

#define	P_FLAG(n) \
	if (flags & STATX_##n) { \
		printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
		flags &= ~STATX_##n; \
	}

	P_FLAG(TYPE);
	P_FLAG(MODE);
	P_FLAG(NLINK);
	P_FLAG(UID);
	P_FLAG(GID);
	P_FLAG(ATIME);
	P_FLAG(MTIME);
	P_FLAG(CTIME);
	P_FLAG(INO);
	P_FLAG(SIZE);
	P_FLAG(BLOCKS);
	P_FLAG(BTIME);

#undef P_FLAG

	if (flags)
		printed += scnprintf(bf + printed, size - printed, "%s%#x", printed ? "|" : "", flags);

	return printed;
}

