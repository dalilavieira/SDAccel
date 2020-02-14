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
typedef  int /*<<< orphan*/  op_t ;

/* Variables and functions */
 int /*<<< orphan*/  BYTE_COPY_FWD (unsigned long,unsigned long,unsigned int) ; 
 int /*<<< orphan*/  MERGE (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int) ; 
 int OPSIZ ; 
 size_t OP_T_THRES ; 
 int /*<<< orphan*/  WORD_COPY_FWD (unsigned long,unsigned long,size_t,size_t) ; 

__attribute__((used)) static void _wordcopy_fwd_aligned(long int dstp, long int srcp, size_t len)
{
	while (len > 7) {
		register op_t a0, a1, a2, a3, a4, a5, a6, a7;

		a0 = ((op_t *) srcp)[0];
		a1 = ((op_t *) srcp)[1];
		a2 = ((op_t *) srcp)[2];
		a3 = ((op_t *) srcp)[3];
		a4 = ((op_t *) srcp)[4];
		a5 = ((op_t *) srcp)[5];
		a6 = ((op_t *) srcp)[6];
		a7 = ((op_t *) srcp)[7];
		((op_t *) dstp)[0] = a0;
		((op_t *) dstp)[1] = a1;
		((op_t *) dstp)[2] = a2;
		((op_t *) dstp)[3] = a3;
		((op_t *) dstp)[4] = a4;
		((op_t *) dstp)[5] = a5;
		((op_t *) dstp)[6] = a6;
		((op_t *) dstp)[7] = a7;

		srcp += 8 * OPSIZ;
		dstp += 8 * OPSIZ;
		len -= 8;
	}
	while (len > 0) {
		*(op_t *)dstp = *(op_t *)srcp;

		srcp += OPSIZ;
		dstp += OPSIZ;
		len -= 1;
	}
}

__attribute__((used)) static void _wordcopy_fwd_dest_aligned(long int dstp, long int srcp,
					size_t len)
{
	op_t ap;
	int sh_1, sh_2;

	/* Calculate how to shift a word read at the memory operation
	aligned srcp to make it aligned for copy. */

	sh_1 = 8 * (srcp % OPSIZ);
	sh_2 = 8 * OPSIZ - sh_1;

	/* Make SRCP aligned by rounding it down to the beginning of the `op_t'
	it points in the middle of. */
	srcp &= -OPSIZ;
	ap = ((op_t *) srcp)[0];
	srcp += OPSIZ;

	while (len > 3) {
		op_t a0, a1, a2, a3;

		a0 = ((op_t *) srcp)[0];
		a1 = ((op_t *) srcp)[1];
		a2 = ((op_t *) srcp)[2];
		a3 = ((op_t *) srcp)[3];
		((op_t *) dstp)[0] = MERGE(ap, sh_1, a0, sh_2);
		((op_t *) dstp)[1] = MERGE(a0, sh_1, a1, sh_2);
		((op_t *) dstp)[2] = MERGE(a1, sh_1, a2, sh_2);
		((op_t *) dstp)[3] = MERGE(a2, sh_1, a3, sh_2);

		ap = a3;
		srcp += 4 * OPSIZ;
		dstp += 4 * OPSIZ;
		len -= 4;
	}
	while (len > 0) {
		register op_t a0;

		a0 = ((op_t *) srcp)[0];
		((op_t *) dstp)[0] = MERGE(ap, sh_1, a0, sh_2);

		ap = a0;
		srcp += OPSIZ;
		dstp += OPSIZ;
		len -= 1;
	}
}

void *memcpy(void *dstpp, const void *srcpp, size_t len)
{
	unsigned long int dstp = (long int) dstpp;
	unsigned long int srcp = (long int) srcpp;

	/* Copy from the beginning to the end.  */

	/* If there not too few bytes to copy, use word copy.  */
	if (len >= OP_T_THRES) {
		/* Copy just a few bytes to make DSTP aligned.  */
		len -= (-dstp) % OPSIZ;
		BYTE_COPY_FWD(dstp, srcp, (-dstp) % OPSIZ);

		/* Copy whole pages from SRCP to DSTP by virtual address
		   manipulation, as much as possible.  */

		/* PAGE_COPY_FWD_MAYBE (dstp, srcp, len, len); */

		/* Copy from SRCP to DSTP taking advantage of the known
		   alignment of DSTP. Number of bytes remaining is put in the
		   third argument, i.e. in LEN.  This number may vary from
		   machine to machine. */

		WORD_COPY_FWD(dstp, srcp, len, len);

		/* Fall out and copy the tail. */
	}

	/* There are just a few bytes to copy.  Use byte memory operations. */
	BYTE_COPY_FWD(dstp, srcp, len);

	return dstpp;
}

void *memcpyb(void *dstpp, const void *srcpp, unsigned len)
{
	unsigned long int dstp = (long int) dstpp;
	unsigned long int srcp = (long int) srcpp;

	BYTE_COPY_FWD(dstp, srcp, len);

	return dstpp;
}

