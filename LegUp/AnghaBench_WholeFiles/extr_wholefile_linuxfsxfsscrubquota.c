#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint ;
struct xfs_scrub {int has_quotaofflock; void* ilock_flags; int /*<<< orphan*/  ip; TYPE_1__* sm; struct xfs_mount* mp; } ;
struct xfs_quotainfo {int qi_dqperchunk; int /*<<< orphan*/  qi_quotaofflock; } ;
struct xfs_mount {struct xfs_quotainfo* m_quotainfo; } ;
struct xfs_inode {int dummy; } ;
struct xchk_quota_info {int last_id; struct xfs_scrub* sc; } ;
struct TYPE_2__ {int sm_type; int sm_flags; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOENT ; 
 int /*<<< orphan*/  XFS_DATA_FORK ; 
 scalar_t__ XFS_DQ_GROUP ; 
 scalar_t__ XFS_DQ_PROJ ; 
 scalar_t__ XFS_DQ_USER ; 
 void* XFS_ILOCK_EXCL ; 
 int /*<<< orphan*/  XFS_IS_QUOTA_ON (struct xfs_mount*) ; 
 int /*<<< orphan*/  XFS_IS_QUOTA_RUNNING (struct xfs_mount*) ; 
 int XFS_SCRUB_OFLAG_CORRUPT ; 
#define  XFS_SCRUB_TYPE_GQUOTA 130 
#define  XFS_SCRUB_TYPE_PQUOTA 129 
#define  XFS_SCRUB_TYPE_UQUOTA 128 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  xchk_fblock_process_error (struct xfs_scrub*,int /*<<< orphan*/ ,int,int*) ; 
 int xchk_quota_data_fork (struct xfs_scrub*) ; 
 int /*<<< orphan*/  xchk_quota_item ; 
 int xchk_setup_fs (struct xfs_scrub*,struct xfs_inode*) ; 
 int /*<<< orphan*/  xfs_ilock (int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  xfs_iunlock (int /*<<< orphan*/ ,void*) ; 
 int xfs_qm_dqiterate (struct xfs_mount*,scalar_t__,int /*<<< orphan*/ ,struct xchk_quota_info*) ; 
 int /*<<< orphan*/  xfs_quota_inode (struct xfs_mount*,scalar_t__) ; 
 int /*<<< orphan*/  xfs_this_quota_on (struct xfs_mount*,scalar_t__) ; 

__attribute__((used)) static inline uint
xchk_quota_to_dqtype(
	struct xfs_scrub	*sc)
{
	switch (sc->sm->sm_type) {
	case XFS_SCRUB_TYPE_UQUOTA:
		return XFS_DQ_USER;
	case XFS_SCRUB_TYPE_GQUOTA:
		return XFS_DQ_GROUP;
	case XFS_SCRUB_TYPE_PQUOTA:
		return XFS_DQ_PROJ;
	default:
		return 0;
	}
}

int
xchk_setup_quota(
	struct xfs_scrub	*sc,
	struct xfs_inode	*ip)
{
	uint			dqtype;
	int			error;

	if (!XFS_IS_QUOTA_RUNNING(sc->mp) || !XFS_IS_QUOTA_ON(sc->mp))
		return -ENOENT;

	dqtype = xchk_quota_to_dqtype(sc);
	if (dqtype == 0)
		return -EINVAL;
	sc->has_quotaofflock = true;
	mutex_lock(&sc->mp->m_quotainfo->qi_quotaofflock);
	if (!xfs_this_quota_on(sc->mp, dqtype))
		return -ENOENT;
	error = xchk_setup_fs(sc, ip);
	if (error)
		return error;
	sc->ip = xfs_quota_inode(sc->mp, dqtype);
	xfs_ilock(sc->ip, XFS_ILOCK_EXCL);
	sc->ilock_flags = XFS_ILOCK_EXCL;
	return 0;
}

int
xchk_quota(
	struct xfs_scrub	*sc)
{
	struct xchk_quota_info	sqi;
	struct xfs_mount	*mp = sc->mp;
	struct xfs_quotainfo	*qi = mp->m_quotainfo;
	uint			dqtype;
	int			error = 0;

	dqtype = xchk_quota_to_dqtype(sc);

	/* Look for problem extents. */
	error = xchk_quota_data_fork(sc);
	if (error)
		goto out;
	if (sc->sm->sm_flags & XFS_SCRUB_OFLAG_CORRUPT)
		goto out;

	/*
	 * Check all the quota items.  Now that we've checked the quota inode
	 * data fork we have to drop ILOCK_EXCL to use the regular dquot
	 * functions.
	 */
	xfs_iunlock(sc->ip, sc->ilock_flags);
	sc->ilock_flags = 0;
	sqi.sc = sc;
	sqi.last_id = 0;
	error = xfs_qm_dqiterate(mp, dqtype, xchk_quota_item, &sqi);
	sc->ilock_flags = XFS_ILOCK_EXCL;
	xfs_ilock(sc->ip, sc->ilock_flags);
	if (!xchk_fblock_process_error(sc, XFS_DATA_FORK,
			sqi.last_id * qi->qi_dqperchunk, &error))
		goto out;

out:
	return error;
}

