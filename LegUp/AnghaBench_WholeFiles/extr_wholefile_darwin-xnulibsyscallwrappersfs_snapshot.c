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
typedef  scalar_t__ uint32_t ;
struct attrlist {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  EINVAL ; 
 int /*<<< orphan*/  FSOPT_LIST_SNAPSHOT ; 
 int /*<<< orphan*/  SNAPSHOT_OP_CREATE ; 
 int /*<<< orphan*/  SNAPSHOT_OP_DELETE ; 
 int /*<<< orphan*/  SNAPSHOT_OP_MOUNT ; 
 int /*<<< orphan*/  SNAPSHOT_OP_RENAME ; 
 int /*<<< orphan*/  SNAPSHOT_OP_REVERT ; 
 int /*<<< orphan*/  SNAPSHOT_OP_ROOT ; 
 int __fs_snapshot (int /*<<< orphan*/ ,int,char const*,char const*,int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  errno ; 
 int getattrlistbulk (int,struct attrlist*,void*,size_t,int /*<<< orphan*/ ) ; 

int
fs_snapshot_create(int dirfd, const char *name, uint32_t flags)
{
	return __fs_snapshot(SNAPSHOT_OP_CREATE, dirfd, name, NULL, NULL, flags);
}

int
fs_snapshot_list(int dirfd, struct attrlist *alist, void *attrbuf, size_t bufsize,
    uint32_t flags)
{
	if (flags != 0) {
		errno = EINVAL;
		return (-1);
	}

	return (getattrlistbulk(dirfd, alist, attrbuf, bufsize,
	    FSOPT_LIST_SNAPSHOT));
}

int
fs_snapshot_delete(int dirfd, const char *name, uint32_t flags)
{
	return __fs_snapshot(SNAPSHOT_OP_DELETE, dirfd, name, NULL, NULL, flags);
}

int
fs_snapshot_rename(int dirfd, const char *old, const char *new, uint32_t flags)
{
	return __fs_snapshot(SNAPSHOT_OP_RENAME, dirfd, old, new, NULL, flags);
}

int
fs_snapshot_revert(int dirfd, const char *name, uint32_t flags)
{
    return __fs_snapshot(SNAPSHOT_OP_REVERT, dirfd, name, NULL, NULL, flags);
}

int
fs_snapshot_root(int dirfd, const char *name, uint32_t flags)
{
    return __fs_snapshot(SNAPSHOT_OP_ROOT, dirfd, name, NULL, NULL, flags);
}

int
fs_snapshot_mount(int dirfd, const char *dir, const char *snapshot,
    uint32_t flags)
{
	return (__fs_snapshot(SNAPSHOT_OP_MOUNT, dirfd, snapshot, dir,
	    NULL, flags));
}

