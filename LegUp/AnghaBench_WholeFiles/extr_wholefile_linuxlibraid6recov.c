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
typedef  size_t u8 ;
struct TYPE_2__ {int /*<<< orphan*/  (* gen_syndrome ) (int,size_t,void**) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  raid6_2data_recov (int,size_t,int,int,void**) ; 
 TYPE_1__ raid6_call ; 
 int /*<<< orphan*/  raid6_datap_recov (int,size_t,int,void**) ; 
 scalar_t__ raid6_empty_zero_page ; 
 size_t* raid6_gfexi ; 
 size_t* raid6_gfexp ; 
 size_t* raid6_gfinv ; 
 size_t** raid6_gfmul ; 
 int /*<<< orphan*/  stub1 (int,size_t,void**) ; 
 int /*<<< orphan*/  stub2 (int,size_t,void**) ; 
 int /*<<< orphan*/  stub3 (int,size_t,void**) ; 

__attribute__((used)) static void raid6_2data_recov_intx1(int disks, size_t bytes, int faila,
		int failb, void **ptrs)
{
	u8 *p, *q, *dp, *dq;
	u8 px, qx, db;
	const u8 *pbmul;	/* P multiplier table for B data */
	const u8 *qmul;		/* Q multiplier table (for both) */

	p = (u8 *)ptrs[disks-2];
	q = (u8 *)ptrs[disks-1];

	/* Compute syndrome with zero for the missing data pages
	   Use the dead data pages as temporary storage for
	   delta p and delta q */
	dp = (u8 *)ptrs[faila];
	ptrs[faila] = (void *)raid6_empty_zero_page;
	ptrs[disks-2] = dp;
	dq = (u8 *)ptrs[failb];
	ptrs[failb] = (void *)raid6_empty_zero_page;
	ptrs[disks-1] = dq;

	raid6_call.gen_syndrome(disks, bytes, ptrs);

	/* Restore pointer table */
	ptrs[faila]   = dp;
	ptrs[failb]   = dq;
	ptrs[disks-2] = p;
	ptrs[disks-1] = q;

	/* Now, pick the proper data tables */
	pbmul = raid6_gfmul[raid6_gfexi[failb-faila]];
	qmul  = raid6_gfmul[raid6_gfinv[raid6_gfexp[faila]^raid6_gfexp[failb]]];

	/* Now do it... */
	while ( bytes-- ) {
		px    = *p ^ *dp;
		qx    = qmul[*q ^ *dq];
		*dq++ = db = pbmul[px] ^ qx; /* Reconstructed B */
		*dp++ = db ^ px; /* Reconstructed A */
		p++; q++;
	}
}

__attribute__((used)) static void raid6_datap_recov_intx1(int disks, size_t bytes, int faila,
		void **ptrs)
{
	u8 *p, *q, *dq;
	const u8 *qmul;		/* Q multiplier table */

	p = (u8 *)ptrs[disks-2];
	q = (u8 *)ptrs[disks-1];

	/* Compute syndrome with zero for the missing data page
	   Use the dead data page as temporary storage for delta q */
	dq = (u8 *)ptrs[faila];
	ptrs[faila] = (void *)raid6_empty_zero_page;
	ptrs[disks-1] = dq;

	raid6_call.gen_syndrome(disks, bytes, ptrs);

	/* Restore pointer table */
	ptrs[faila]   = dq;
	ptrs[disks-1] = q;

	/* Now, pick the proper data tables */
	qmul  = raid6_gfmul[raid6_gfinv[raid6_gfexp[faila]]];

	/* Now do it... */
	while ( bytes-- ) {
		*p++ ^= *dq = qmul[*q ^ *dq];
		q++; dq++;
	}
}

void raid6_dual_recov(int disks, size_t bytes, int faila, int failb, void **ptrs)
{
	if ( faila > failb ) {
		int tmp = faila;
		faila = failb;
		failb = tmp;
	}

	if ( failb == disks-1 ) {
		if ( faila == disks-2 ) {
			/* P+Q failure.  Just rebuild the syndrome. */
			raid6_call.gen_syndrome(disks, bytes, ptrs);
		} else {
			/* data+Q failure.  Reconstruct data from P,
			   then rebuild syndrome. */
			/* NOT IMPLEMENTED - equivalent to RAID-5 */
		}
	} else {
		if ( failb == disks-2 ) {
			/* data+P failure. */
			raid6_datap_recov(disks, bytes, faila, ptrs);
		} else {
			/* data+data failure. */
			raid6_2data_recov(disks, bytes, faila, failb, ptrs);
		}
	}
}

