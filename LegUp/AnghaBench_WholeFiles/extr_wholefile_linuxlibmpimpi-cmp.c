#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ mpi_size_t ;
typedef  scalar_t__ mpi_limb_t ;
struct TYPE_6__ {int nlimbs; scalar_t__* d; scalar_t__ sign; } ;
typedef  TYPE_1__* MPI ;

/* Variables and functions */
 int /*<<< orphan*/  mpi_normalize (TYPE_1__*) ; 
 int mpihelp_cmp (scalar_t__*,scalar_t__*,scalar_t__) ; 

int mpi_cmp_ui(MPI u, unsigned long v)
{
	mpi_limb_t limb = v;

	mpi_normalize(u);
	if (!u->nlimbs && !limb)
		return 0;
	if (u->sign)
		return -1;
	if (u->nlimbs > 1)
		return 1;

	if (u->d[0] == limb)
		return 0;
	else if (u->d[0] > limb)
		return 1;
	else
		return -1;
}

int mpi_cmp(MPI u, MPI v)
{
	mpi_size_t usize, vsize;
	int cmp;

	mpi_normalize(u);
	mpi_normalize(v);
	usize = u->nlimbs;
	vsize = v->nlimbs;
	if (!u->sign && v->sign)
		return 1;
	if (u->sign && !v->sign)
		return -1;
	if (usize != vsize && !u->sign && !v->sign)
		return usize - vsize;
	if (usize != vsize && u->sign && v->sign)
		return vsize - usize;
	if (!usize)
		return 0;
	cmp = mpihelp_cmp(u->d, v->d, usize);
	if (u->sign)
		return -cmp;
	return cmp;
}

