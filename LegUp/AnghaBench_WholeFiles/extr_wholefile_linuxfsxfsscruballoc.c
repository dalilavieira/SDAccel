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
typedef  int /*<<< orphan*/  xfs_extlen_t ;
typedef  int /*<<< orphan*/  xfs_agblock_t ;
struct TYPE_2__ {int /*<<< orphan*/  bno_cur; } ;
struct xfs_scrub {TYPE_1__ sa; int /*<<< orphan*/  sm; } ;
struct xfs_inode {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  XFS_BTNUM_BNO ; 
 int /*<<< orphan*/  XFS_BTNUM_CNT ; 
 int xchk_allocbt (struct xfs_scrub*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xchk_btree_xref_set_corrupt (struct xfs_scrub*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int xchk_setup_ag_btree (struct xfs_scrub*,struct xfs_inode*,int) ; 
 int /*<<< orphan*/  xchk_should_check_xref (struct xfs_scrub*,int*,int /*<<< orphan*/ *) ; 
 scalar_t__ xchk_skip_xref (int /*<<< orphan*/ ) ; 
 int xfs_alloc_has_record (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 

int
xchk_setup_ag_allocbt(
	struct xfs_scrub	*sc,
	struct xfs_inode	*ip)
{
	return xchk_setup_ag_btree(sc, ip, false);
}

int
xchk_bnobt(
	struct xfs_scrub	*sc)
{
	return xchk_allocbt(sc, XFS_BTNUM_BNO);
}

int
xchk_cntbt(
	struct xfs_scrub	*sc)
{
	return xchk_allocbt(sc, XFS_BTNUM_CNT);
}

void
xchk_xref_is_used_space(
	struct xfs_scrub	*sc,
	xfs_agblock_t		agbno,
	xfs_extlen_t		len)
{
	bool			is_freesp;
	int			error;

	if (!sc->sa.bno_cur || xchk_skip_xref(sc->sm))
		return;

	error = xfs_alloc_has_record(sc->sa.bno_cur, agbno, len, &is_freesp);
	if (!xchk_should_check_xref(sc, &error, &sc->sa.bno_cur))
		return;
	if (is_freesp)
		xchk_btree_xref_set_corrupt(sc, sc->sa.bno_cur, 0);
}

