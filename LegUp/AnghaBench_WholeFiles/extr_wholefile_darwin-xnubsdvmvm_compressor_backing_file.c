#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  struct vnode* vnode_t ;
typedef  int /*<<< orphan*/ * vfs_context_t ;
typedef  int /*<<< orphan*/ * upl_t ;
typedef  scalar_t__ upl_size_t ;
typedef  int upl_control_flags_t ;
typedef  scalar_t__ uint64_t ;
typedef  scalar_t__ u_int64_t ;
typedef  int u_int32_t ;
struct vnode {TYPE_2__* v_mount; int /*<<< orphan*/  v_flag; } ;
struct trim_list {size_t tl_offset; size_t tl_length; struct trim_list* tl_next; } ;
typedef  size_t off_t ;
typedef  scalar_t__ kern_return_t ;
struct TYPE_11__ {int extentsCount; TYPE_4__* extents; int /*<<< orphan*/  options; } ;
typedef  TYPE_3__ dk_unmap_t ;
struct TYPE_12__ {size_t length; scalar_t__ offset; } ;
typedef  TYPE_4__ dk_extent_t ;
typedef  int daddr64_t ;
typedef  int /*<<< orphan*/ * caddr_t ;
typedef  int boolean_t ;
typedef  TYPE_3__ _dk_cs_unmap_t ;
struct TYPE_9__ {scalar_t__ f_iosize; } ;
struct TYPE_10__ {int mnt_kern_flag; int mnt_ioflags; int mnt_devblocksize; struct vnode* mnt_devvp; TYPE_1__ mnt_vfsstat; } ;

/* Variables and functions */
 int /*<<< orphan*/  CAST_USER_ADDR_T (scalar_t__) ; 
 int /*<<< orphan*/  DKIOCUNMAP ; 
 int ENOTSUP ; 
 int FALSE ; 
 int /*<<< orphan*/  FIOPINSWAP ; 
 int FREAD ; 
 int FWRITE ; 
 int /*<<< orphan*/  IO_NODELOCKED ; 
 int /*<<< orphan*/  IO_NOZEROFILL ; 
 scalar_t__ KERN_SUCCESS ; 
 int MAX_BATCH_TO_TRIM ; 
 int MNTK_NOSWAP ; 
 int MNT_IOFLAGS_CSUNMAP_SUPPORTED ; 
 int MNT_IOFLAGS_UNMAP_SUPPORTED ; 
 int /*<<< orphan*/  NULLVP ; 
 int O_CREAT ; 
 int O_TRUNC ; 
 int PAGE_SIZE_64 ; 
 int /*<<< orphan*/  ROUTE_ONLY ; 
 int /*<<< orphan*/  SET (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int SWAP_READ ; 
 int S_IRUSR ; 
 int S_IWUSR ; 
 int TRUE ; 
 int /*<<< orphan*/  UIO_SYSSPACE ; 
 int /*<<< orphan*/  UIO_WRITE ; 
 int UPL_COPYOUT_FROM ; 
 int UPL_IGNORE_VALID_PAGE_CHECK ; 
 int UPL_IOSYNC ; 
 int UPL_SET_INTERNAL ; 
 int UPL_SET_LITE ; 
 int /*<<< orphan*/  VM_KERN_MEMORY_OSFMK ; 
 int VNODE_BLOCKMAP_NO_TRACK ; 
 int VNODE_READ ; 
 int VNOP_BLOCKMAP (struct vnode*,size_t,size_t,int*,size_t*,int /*<<< orphan*/ *,int,int /*<<< orphan*/ *) ; 
 int VNOP_IOCTL (struct vnode*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  VSWAP ; 
 int /*<<< orphan*/  _DKIOCCSUNMAP ; 
 int /*<<< orphan*/  assert (int) ; 
 TYPE_4__* kalloc (int) ; 
 int /*<<< orphan*/  kernel_map ; 
 int /*<<< orphan*/  kfree (TYPE_4__*,int) ; 
 int /*<<< orphan*/  memset (TYPE_3__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  panic (char*,scalar_t__) ; 
 int /*<<< orphan*/  printf (char*,int,...) ; 
 int unlink1 (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  upl_set_iodone (int /*<<< orphan*/ *,void*) ; 
 int /*<<< orphan*/ * vfs_context_kernel () ; 
 int /*<<< orphan*/  vfs_context_proc (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  vfs_context_ucred (int /*<<< orphan*/ *) ; 
 scalar_t__ vfs_devblocksize (int /*<<< orphan*/ ) ; 
 scalar_t__ vm_map_create_upl (int /*<<< orphan*/ ,scalar_t__,scalar_t__*,int /*<<< orphan*/ **,int /*<<< orphan*/ *,unsigned int*,int*,int /*<<< orphan*/ ) ; 
 void vm_swapfile_close (scalar_t__,struct vnode*) ; 
 int vn_rdwr (int /*<<< orphan*/ ,struct vnode*,int /*<<< orphan*/ *,int,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vnode_close (struct vnode*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  vnode_getwithref (struct vnode*) ; 
 int /*<<< orphan*/  vnode_lock_spin (struct vnode*) ; 
 int /*<<< orphan*/  vnode_mount (struct vnode*) ; 
 int vnode_open (char const*,int,int,int /*<<< orphan*/ ,struct vnode**,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  vnode_pagein (struct vnode*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,scalar_t__,scalar_t__,int,int*) ; 
 int /*<<< orphan*/  vnode_pageout (struct vnode*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,scalar_t__,scalar_t__,int,int*) ; 
 int /*<<< orphan*/  vnode_put (struct vnode*) ; 
 int vnode_setsize (struct vnode*,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int vnode_size (struct vnode*,size_t*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  vnode_unlock (struct vnode*) ; 

void
vm_swapfile_open(const char *path, vnode_t *vp)
{
	int error = 0;
	vfs_context_t	ctx = vfs_context_kernel();

	if ((error = vnode_open(path, (O_CREAT | O_TRUNC | FREAD | FWRITE), S_IRUSR | S_IWUSR, 0, vp, ctx))) {
		printf("Failed to open swap file %d\n", error);
		*vp = NULL;
		return;
	}	

	/*
	 * If MNT_IOFLAGS_NOSWAP is set, opening the swap file should fail.
	 * To avoid a race on the mount we only make this check after creating the
	 * vnode.
	 */
	if ((*vp)->v_mount->mnt_kern_flag & MNTK_NOSWAP) {
		vnode_put(*vp);
		vm_swapfile_close((uint64_t)path, *vp);
		*vp = NULL;
		return;
	}

	vnode_put(*vp);
}

uint64_t
vm_swapfile_get_blksize(vnode_t vp)
{
	return ((uint64_t)vfs_devblocksize(vnode_mount(vp)));
}

uint64_t
vm_swapfile_get_transfer_size(vnode_t vp)
{
	return((uint64_t)vp->v_mount->mnt_vfsstat.f_iosize);
}

void
vm_swapfile_close(uint64_t path_addr, vnode_t vp)
{
	vfs_context_t context = vfs_context_kernel();
	int error;

	vnode_getwithref(vp);
	vnode_close(vp, 0, context);
	
	error = unlink1(context, NULLVP, CAST_USER_ADDR_T(path_addr),
	    UIO_SYSSPACE, 0);

#if DEVELOPMENT || DEBUG
	if (error)
		printf("%s : unlink of %s failed with error %d", __FUNCTION__,
		    (char *)path_addr, error);
#endif
}

int
vm_swapfile_preallocate(vnode_t vp, uint64_t *size, boolean_t *pin)
{
	int		error = 0;
	uint64_t	file_size = 0;
	vfs_context_t	ctx = NULL;
#if CONFIG_FREEZE
	struct vnode_attr va;
#endif /* CONFIG_FREEZE */

	ctx = vfs_context_kernel();

	error = vnode_setsize(vp, *size, IO_NOZEROFILL, ctx);

	if (error) {
		printf("vnode_setsize for swap files failed: %d\n", error);
		goto done;
	}

	error = vnode_size(vp, (off_t*) &file_size, ctx);

	if (error) {
		printf("vnode_size (new file) for swap file failed: %d\n", error);
		goto done;
	}	
	assert(file_size == *size);
	
	if (pin != NULL && *pin != FALSE) {
		error = VNOP_IOCTL(vp, FIOPINSWAP, NULL, 0, ctx);

		if (error) {
			printf("pin for swap files failed: %d,  file_size = %lld\n", error, file_size);
			/* this is not fatal, carry on with files wherever they landed */
			*pin = FALSE;
			error = 0;
		}
	}

	vnode_lock_spin(vp);
	SET(vp->v_flag, VSWAP);
	vnode_unlock(vp);

#if CONFIG_FREEZE
	VATTR_INIT(&va);
	VATTR_SET(&va, va_dataprotect_class, PROTECTION_CLASS_C);
	error = VNOP_SETATTR(vp, &va, ctx);

	if (error) {
		printf("setattr PROTECTION_CLASS_C for swap file failed: %d\n", error);
		goto done;
	}
#endif /* CONFIG_FREEZE */

done:
	return error;
}

int
vm_record_file_write(vnode_t vp, uint64_t offset, char *buf, int size)
{
	int error = 0;
	vfs_context_t ctx;

	ctx = vfs_context_kernel();
		
	error = vn_rdwr(UIO_WRITE, vp, (caddr_t)buf, size, offset,
		UIO_SYSSPACE, IO_NODELOCKED, vfs_context_ucred(ctx), (int *) 0, vfs_context_proc(ctx));

	return (error);
}

int
vm_swapfile_io(vnode_t vp, uint64_t offset, uint64_t start, int npages, int flags, void *upl_iodone)
{
	int error = 0;
	uint64_t io_size = npages * PAGE_SIZE_64;
#if 1
	kern_return_t	kr = KERN_SUCCESS;
	upl_t		upl = NULL;
	unsigned int	count = 0;
	upl_control_flags_t upl_create_flags = 0;
	int		upl_control_flags = 0;
	upl_size_t	upl_size = 0;

	upl_create_flags = UPL_SET_INTERNAL | UPL_SET_LITE;

	if (upl_iodone == NULL)
	        upl_control_flags = UPL_IOSYNC;

#if ENCRYPTED_SWAP
	upl_control_flags |= UPL_PAGING_ENCRYPTED;
#endif

	if ((flags & SWAP_READ) == FALSE) {
		upl_create_flags |= UPL_COPYOUT_FROM;
	}
 
	upl_size = io_size;
	kr = vm_map_create_upl( kernel_map,
				start,
				&upl_size,
				&upl,
				NULL,
				&count,
				&upl_create_flags,
				VM_KERN_MEMORY_OSFMK);

	if (kr != KERN_SUCCESS || (upl_size != io_size)) {
		panic("vm_map_create_upl failed with %d\n", kr);
	}

	if (flags & SWAP_READ) {
		vnode_pagein(vp,
			      upl,
			      0,
			      offset,
			      io_size,
			      upl_control_flags | UPL_IGNORE_VALID_PAGE_CHECK,
			      &error);
		if (error) {
#if DEBUG
			printf("vm_swapfile_io: vnode_pagein failed with %d (vp: %p, offset: 0x%llx, size:%llu)\n", error, vp, offset, io_size);
#else /* DEBUG */
			printf("vm_swapfile_io: vnode_pagein failed with %d.\n", error);
#endif /* DEBUG */
		}
	
	} else {
	        upl_set_iodone(upl, upl_iodone);

		vnode_pageout(vp,
			      upl,
			      0,
			      offset,
			      io_size,
			      upl_control_flags,
			      &error);
		if (error) {
#if DEBUG
			printf("vm_swapfile_io: vnode_pageout failed with %d (vp: %p, offset: 0x%llx, size:%llu)\n", error, vp, offset, io_size);
#else /* DEBUG */
			printf("vm_swapfile_io: vnode_pageout failed with %d.\n", error);
#endif /* DEBUG */
		}
	}
	return error;

#else /* 1 */
	vfs_context_t ctx;
	ctx = vfs_context_kernel();
		
	error = vn_rdwr((flags & SWAP_READ) ? UIO_READ : UIO_WRITE, vp, (caddr_t)start, io_size, offset,
		UIO_SYSSPACE, IO_SYNC | IO_NODELOCKED | IO_UNIT | IO_NOCACHE | IO_SWAP_DISPATCH, vfs_context_ucred(ctx), (int *) 0, vfs_context_proc(ctx));

	if (error) {
		printf("vn_rdwr: Swap I/O failed with %d\n", error);
	}
	return error;
#endif /* 1 */
}

u_int32_t vnode_trim_list (vnode_t vp, struct trim_list *tl, boolean_t route_only)
{
	int		error = 0;
	int		trim_index = 0;
	u_int32_t	blocksize = 0;
	struct vnode	*devvp;
	dk_extent_t	*extents;
	dk_unmap_t	unmap;
	_dk_cs_unmap_t	cs_unmap;

	if ( !(vp->v_mount->mnt_ioflags & MNT_IOFLAGS_UNMAP_SUPPORTED))
		return (ENOTSUP);

	if (tl == NULL)
		return (0);

	/*
	 * Get the underlying device vnode and physical block size
	 */
	devvp = vp->v_mount->mnt_devvp;
	blocksize = vp->v_mount->mnt_devblocksize;

	extents = kalloc(sizeof(dk_extent_t) * MAX_BATCH_TO_TRIM);

	if (vp->v_mount->mnt_ioflags & MNT_IOFLAGS_CSUNMAP_SUPPORTED) {
		memset (&cs_unmap, 0, sizeof(_dk_cs_unmap_t));
		cs_unmap.extents = extents;

		if (route_only == TRUE)
			cs_unmap.options = ROUTE_ONLY;
	} else {
		memset (&unmap, 0, sizeof(dk_unmap_t));
		unmap.extents = extents;
	}

	while (tl) {
		daddr64_t	io_blockno;	/* Block number corresponding to the start of the extent */
		size_t		io_bytecount;	/* Number of bytes in current extent for the specified range */
		size_t		trimmed;
		size_t		remaining_length;
		off_t		current_offset; 

		current_offset = tl->tl_offset;
		remaining_length = tl->tl_length;
		trimmed = 0;
		
		/* 
		 * We may not get the entire range from tl_offset -> tl_offset+tl_length in a single
		 * extent from the blockmap call.  Keep looping/going until we are sure we've hit
		 * the whole range or if we encounter an error.
		 */
		while (trimmed < tl->tl_length) {
			/*
			 * VNOP_BLOCKMAP will tell us the logical to physical block number mapping for the
			 * specified offset.  It returns blocks in contiguous chunks, so if the logical range is 
			 * broken into multiple extents, it must be called multiple times, increasing the offset
			 * in each call to ensure that the entire range is covered.
			 */
			error = VNOP_BLOCKMAP (vp, current_offset, remaining_length, 
					       &io_blockno, &io_bytecount, NULL, VNODE_READ | VNODE_BLOCKMAP_NO_TRACK, NULL);

			if (error) {
				goto trim_exit;
			}
			if (io_blockno != -1) {
			        extents[trim_index].offset = (uint64_t) io_blockno * (u_int64_t) blocksize;
				extents[trim_index].length = io_bytecount;

				trim_index++;
			}
			if (trim_index == MAX_BATCH_TO_TRIM) {

				if (vp->v_mount->mnt_ioflags & MNT_IOFLAGS_CSUNMAP_SUPPORTED) {
					cs_unmap.extentsCount = trim_index;
					error = VNOP_IOCTL(devvp, _DKIOCCSUNMAP, (caddr_t)&cs_unmap, 0, vfs_context_kernel());
				} else {
					unmap.extentsCount = trim_index;
					error = VNOP_IOCTL(devvp, DKIOCUNMAP, (caddr_t)&unmap, 0, vfs_context_kernel());
				}
				if (error) {
					goto trim_exit;
				}
				trim_index = 0;
			}
			trimmed += io_bytecount;
			current_offset += io_bytecount;
			remaining_length -= io_bytecount;
		}
		tl = tl->tl_next;
	}
	if (trim_index) {
		if (vp->v_mount->mnt_ioflags & MNT_IOFLAGS_CSUNMAP_SUPPORTED) {
			cs_unmap.extentsCount = trim_index;
			error = VNOP_IOCTL(devvp, _DKIOCCSUNMAP, (caddr_t)&cs_unmap, 0, vfs_context_kernel());
		} else {
			unmap.extentsCount = trim_index;
			error = VNOP_IOCTL(devvp, DKIOCUNMAP, (caddr_t)&unmap, 0, vfs_context_kernel());
		}
	}
trim_exit:
	kfree(extents, sizeof(dk_extent_t) * MAX_BATCH_TO_TRIM);

	return error;
}

