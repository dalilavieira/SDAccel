#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ xfs_fileoff_t ;
typedef  int /*<<< orphan*/  xfs_agblock_t ;
typedef  int /*<<< orphan*/  uint64_t ;
struct xfs_scrub {int ilock_flags; int /*<<< orphan*/  ip; TYPE_1__* sm; } ;
struct xfs_rmap_irec {int dummy; } ;
struct xfs_inode {int dummy; } ;
struct xfs_bmbt_irec {scalar_t__ br_startoff; } ;
struct xchk_bmap_info {scalar_t__ whichfork; TYPE_3__* sc; scalar_t__ is_shared; } ;
struct TYPE_10__ {int /*<<< orphan*/  i_mapping; int /*<<< orphan*/  i_mode; } ;
struct TYPE_8__ {int /*<<< orphan*/  rmap_cur; } ;
struct TYPE_9__ {TYPE_2__ sa; } ;
struct TYPE_7__ {scalar_t__ sm_type; } ;

/* Variables and functions */
 int ENOENT ; 
 scalar_t__ S_ISREG (int /*<<< orphan*/ ) ; 
 TYPE_5__* VFS_I (int /*<<< orphan*/ ) ; 
 scalar_t__ XFS_ATTR_FORK ; 
 scalar_t__ XFS_COW_FORK ; 
 scalar_t__ XFS_DATA_FORK ; 
 int XFS_ILOCK_EXCL ; 
 int XFS_IOLOCK_EXCL ; 
 int XFS_MMAPLOCK_EXCL ; 
 unsigned int XFS_RMAP_ATTR_FORK ; 
 scalar_t__ XFS_SCRUB_TYPE_BMBTD ; 
 int filemap_write_and_wait (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  inode_dio_wait (TYPE_5__*) ; 
 int xchk_bmap (struct xfs_scrub*,scalar_t__) ; 
 int /*<<< orphan*/  xchk_fblock_xref_set_corrupt (TYPE_3__*,scalar_t__,scalar_t__) ; 
 int xchk_get_inode (struct xfs_scrub*,struct xfs_inode*) ; 
 int /*<<< orphan*/  xchk_should_check_xref (TYPE_3__*,int*,int /*<<< orphan*/ *) ; 
 int xchk_trans_alloc (struct xfs_scrub*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xfs_ilock (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  xfs_is_reflink_inode (int /*<<< orphan*/ ) ; 
 int xfs_rmap_get_rec (int /*<<< orphan*/ ,struct xfs_rmap_irec*,int*) ; 
 int xfs_rmap_lookup_le (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__,unsigned int,int*) ; 
 int xfs_rmap_lookup_le_range (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__,unsigned int,struct xfs_rmap_irec*,int*) ; 

int
xchk_setup_inode_bmap(
	struct xfs_scrub	*sc,
	struct xfs_inode	*ip)
{
	int			error;

	error = xchk_get_inode(sc, ip);
	if (error)
		goto out;

	sc->ilock_flags = XFS_IOLOCK_EXCL | XFS_MMAPLOCK_EXCL;
	xfs_ilock(sc->ip, sc->ilock_flags);

	/*
	 * We don't want any ephemeral data fork updates sitting around
	 * while we inspect block mappings, so wait for directio to finish
	 * and flush dirty data if we have delalloc reservations.
	 */
	if (S_ISREG(VFS_I(sc->ip)->i_mode) &&
	    sc->sm->sm_type == XFS_SCRUB_TYPE_BMBTD) {
		inode_dio_wait(VFS_I(sc->ip));
		error = filemap_write_and_wait(VFS_I(sc->ip)->i_mapping);
		if (error)
			goto out;
	}

	/* Got the inode, lock it and we're ready to go. */
	error = xchk_trans_alloc(sc, 0);
	if (error)
		goto out;
	sc->ilock_flags |= XFS_ILOCK_EXCL;
	xfs_ilock(sc->ip, XFS_ILOCK_EXCL);

out:
	/* scrub teardown will unlock and release the inode */
	return error;
}

__attribute__((used)) static inline bool
xchk_bmap_get_rmap(
	struct xchk_bmap_info	*info,
	struct xfs_bmbt_irec	*irec,
	xfs_agblock_t		agbno,
	uint64_t		owner,
	struct xfs_rmap_irec	*rmap)
{
	xfs_fileoff_t		offset;
	unsigned int		rflags = 0;
	int			has_rmap;
	int			error;

	if (info->whichfork == XFS_ATTR_FORK)
		rflags |= XFS_RMAP_ATTR_FORK;

	/*
	 * CoW staging extents are owned (on disk) by the refcountbt, so
	 * their rmaps do not have offsets.
	 */
	if (info->whichfork == XFS_COW_FORK)
		offset = 0;
	else
		offset = irec->br_startoff;

	/*
	 * If the caller thinks this could be a shared bmbt extent (IOWs,
	 * any data fork extent of a reflink inode) then we have to use the
	 * range rmap lookup to make sure we get the correct owner/offset.
	 */
	if (info->is_shared) {
		error = xfs_rmap_lookup_le_range(info->sc->sa.rmap_cur, agbno,
				owner, offset, rflags, rmap, &has_rmap);
		if (!xchk_should_check_xref(info->sc, &error,
				&info->sc->sa.rmap_cur))
			return false;
		goto out;
	}

	/*
	 * Otherwise, use the (faster) regular lookup.
	 */
	error = xfs_rmap_lookup_le(info->sc->sa.rmap_cur, agbno, 0, owner,
			offset, rflags, &has_rmap);
	if (!xchk_should_check_xref(info->sc, &error,
			&info->sc->sa.rmap_cur))
		return false;
	if (!has_rmap)
		goto out;

	error = xfs_rmap_get_rec(info->sc->sa.rmap_cur, rmap, &has_rmap);
	if (!xchk_should_check_xref(info->sc, &error,
			&info->sc->sa.rmap_cur))
		return false;

out:
	if (!has_rmap)
		xchk_fblock_xref_set_corrupt(info->sc, info->whichfork,
			irec->br_startoff);
	return has_rmap;
}

int
xchk_bmap_data(
	struct xfs_scrub	*sc)
{
	return xchk_bmap(sc, XFS_DATA_FORK);
}

int
xchk_bmap_attr(
	struct xfs_scrub	*sc)
{
	return xchk_bmap(sc, XFS_ATTR_FORK);
}

int
xchk_bmap_cow(
	struct xfs_scrub	*sc)
{
	if (!xfs_is_reflink_inode(sc->ip))
		return -ENOENT;

	return xchk_bmap(sc, XFS_COW_FORK);
}

