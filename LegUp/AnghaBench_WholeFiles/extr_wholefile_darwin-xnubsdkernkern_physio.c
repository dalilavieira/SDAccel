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
typedef  int /*<<< orphan*/  vnode_t ;
typedef  int /*<<< orphan*/  user_size_t ;
typedef  int /*<<< orphan*/  user_addr_t ;
typedef  int u_int ;
struct uio {int uio_iovcnt; int /*<<< orphan*/  uio_segflg; } ;
struct proc {int dummy; } ;
struct buf {int b_lflags; struct proc* b_proc; int /*<<< orphan*/  b_dev; } ;
typedef  int int64_t ;
typedef  int /*<<< orphan*/  dev_t ;
typedef  struct buf* buf_t ;

/* Variables and functions */
 int BL_BUSY ; 
 int B_PHYS ; 
 int B_RAW ; 
 int B_READ ; 
 int B_WRITE ; 
 scalar_t__ CAST_DOWN (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CAST_USER_ADDR_T (int /*<<< orphan*/ ) ; 
 int EFAULT ; 
 int /*<<< orphan*/  MAXPHYS ; 
 int MAXPHYSIO_WIRED ; 
 scalar_t__ UIO_SEG_IS_USER_SPACE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  assert (int) ; 
 struct buf* buf_alloc (int /*<<< orphan*/ ) ; 
 scalar_t__ buf_biowait (struct buf*) ; 
 int buf_count (struct buf*) ; 
 int /*<<< orphan*/  buf_dataptr (struct buf*) ; 
 int buf_flags (struct buf*) ; 
 int /*<<< orphan*/  buf_free (struct buf*) ; 
 int /*<<< orphan*/  buf_reset (struct buf*,int) ; 
 int buf_resid (struct buf*) ; 
 int /*<<< orphan*/  buf_setblkno (struct buf*,int) ; 
 int /*<<< orphan*/  buf_setcount (struct buf*,int) ; 
 int /*<<< orphan*/  buf_setdataptr (struct buf*,uintptr_t) ; 
 int /*<<< orphan*/  buf_setflags (struct buf*,int) ; 
 int /*<<< orphan*/  caddr_t ; 
 struct proc* current_proc () ; 
 int min (int /*<<< orphan*/ ,int) ; 
 u_int stub1 (struct buf*) ; 
 void stub2 (struct buf*) ; 
 int /*<<< orphan*/  uio_curriovbase (struct uio*) ; 
 int uio_curriovlen (struct uio*) ; 
 scalar_t__ uio_getiov (struct uio*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int uio_offset (struct uio*) ; 
 scalar_t__ uio_resid (struct uio*) ; 
 int /*<<< orphan*/  uio_update (struct uio*,int) ; 
 int /*<<< orphan*/  useracc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int vslock (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vsunlock (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

int
physio( void (*f_strategy)(buf_t), 
	buf_t bp,
	dev_t dev,
	int flags,
	u_int (*f_minphys)(buf_t),
	struct uio *uio,
	int blocksize)
{
	struct proc *p = current_proc();
	int error, i, buf_allocated, todo, iosize;
	int orig_bflags = 0;
	int64_t done;

	error = 0;
	flags &= B_READ | B_WRITE;
	buf_allocated = 0;

	/*
	 * [check user read/write access to the data buffer]
	 *
	 * Check each iov one by one.  Note that we know if we're reading or
	 * writing, so we ignore the uio's rw parameter.  Also note that if
	 * we're doing a read, that's a *write* to user-space.
	 */
	for (i = 0; i < uio->uio_iovcnt; i++) {
		if (UIO_SEG_IS_USER_SPACE(uio->uio_segflg)) {
			user_addr_t base;
			user_size_t len;
			
			if (uio_getiov(uio, i, &base, &len) ||
				!useracc(base,
					len,
		    		(flags == B_READ) ? B_WRITE : B_READ))
			return (EFAULT);
		}
	}
	/*
	 * Make sure we have a buffer, creating one if necessary.
	 */
	if (bp == NULL) {
		bp = buf_alloc((vnode_t)0);
		buf_allocated = 1;
	} else
	        orig_bflags = buf_flags(bp);
	/*
	 * at this point we should have a buffer
	 * that is marked BL_BUSY... we either 
	 * acquired it via buf_alloc, or it was
	 * passed into us... if it was passed
	 * in, it needs to already be owned by
	 * the caller (i.e. BL_BUSY is set)
	 */
	assert(bp->b_lflags & BL_BUSY);

	/*
	 * [set up the fixed part of the buffer for a transfer]
	 */
	bp->b_dev = dev;
	bp->b_proc = p;

	/*
	 * [mark the buffer busy for physical I/O]
	 * (i.e. set B_PHYS (because it's an I/O to user
	 * memory, and B_RAW, because B_RAW is to be
	 * "Set by physio for raw transfers.", in addition
	 * to the read/write flag.)
	 */
        buf_setflags(bp, B_PHYS | B_RAW);

	/*
	 * [while there is data to transfer and no I/O error]
	 * Note that I/O errors are handled with a 'goto' at the bottom
	 * of the 'while' loop.
	 */
	while (uio_resid(uio) > 0) {
			
			if ( (iosize = uio_curriovlen(uio)) > MAXPHYSIO_WIRED)
			        iosize = MAXPHYSIO_WIRED;
			/*
			 * make sure we're set to issue a fresh I/O
			 * in the right direction
			 */
			buf_reset(bp, flags);

			/* [set up the buffer for a maximum-sized transfer] */
 			buf_setblkno(bp, uio_offset(uio) / blocksize);
			buf_setcount(bp, iosize);
			buf_setdataptr(bp, (uintptr_t)CAST_DOWN(caddr_t, uio_curriovbase(uio)));
			
			/*
			 * [call f_minphys to bound the tranfer size]
			 * and remember the amount of data to transfer,
			 * for later comparison.
			 */
			(*f_minphys)(bp);
			todo = buf_count(bp);

			/*
			 * [lock the part of the user address space involved
			 *    in the transfer]
			 */

			if(UIO_SEG_IS_USER_SPACE(uio->uio_segflg)) {
				error = vslock(CAST_USER_ADDR_T(buf_dataptr(bp)),
					       (user_size_t)todo);
				if (error)
					goto done;
			}
			
			/* [call f_strategy to start the transfer] */
			(*f_strategy)(bp);


			/* [wait for the transfer to complete] */
			error = (int)buf_biowait(bp);

			/*
			 * [unlock the part of the address space previously
			 *    locked]
			 */
			if(UIO_SEG_IS_USER_SPACE(uio->uio_segflg))
				vsunlock(CAST_USER_ADDR_T(buf_dataptr(bp)),
					 (user_size_t)todo,
					 (flags & B_READ));

			/*
			 * [deduct the transfer size from the total number
			 *    of data to transfer]
			 */
			done = buf_count(bp) - buf_resid(bp);
			uio_update(uio, done);

			/*
			 * Now, check for an error.
			 * Also, handle weird end-of-disk semantics.
			 */
			if (error || done < todo)
				goto done;
	}

done:
	if (buf_allocated)
	        buf_free(bp);
	else
		buf_setflags(bp, orig_bflags);

	return (error);
}

u_int
minphys(struct buf *bp)
{

	buf_setcount(bp, min(MAXPHYS, buf_count(bp)));
        return buf_count(bp);
}

