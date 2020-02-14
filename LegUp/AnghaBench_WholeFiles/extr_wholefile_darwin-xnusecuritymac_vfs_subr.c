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
typedef  int /*<<< orphan*/  vfs_context_t ;
typedef  int /*<<< orphan*/  uio_t ;
typedef  int /*<<< orphan*/  uio_buf ;
struct vnode {int v_lflag; int v_flag; int /*<<< orphan*/  v_mount; int /*<<< orphan*/  v_lock; int /*<<< orphan*/ * v_label; } ;
struct timespec {int tv_sec; scalar_t__ tv_nsec; } ;
struct mount {int dummy; } ;
struct componentname {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  CAST_USER_ADDR_T (char*) ; 
 int EROFS ; 
 int EWOULDBLOCK ; 
 int PDROP ; 
 int PVFS ; 
 int /*<<< orphan*/  UIO_READ ; 
 int UIO_SIZEOF (int) ; 
 int /*<<< orphan*/  UIO_SYSSPACE ; 
 int /*<<< orphan*/  UIO_WRITE ; 
 int VL_LABEL ; 
 int VL_LABELED ; 
 int VL_LABELWAIT ; 
 int VNCACHEABLE ; 
 int VNODE_LABEL_CREATE ; 
 int XATTR_NOSECURITY ; 
 scalar_t__ mac_label_vnodes ; 
 int /*<<< orphan*/ * mac_vnode_label_alloc () ; 
 int mac_vnode_label_associate (struct mount*,struct vnode*,int /*<<< orphan*/ ) ; 
 int mac_vnode_notify_create (int /*<<< orphan*/ ,struct mount*,struct vnode*,struct vnode*,struct componentname*) ; 
 int msleep (int /*<<< orphan*/ **,int /*<<< orphan*/ *,int,char*,struct timespec*) ; 
 int /*<<< orphan*/  uio_addiov (int /*<<< orphan*/ ,int /*<<< orphan*/ ,size_t) ; 
 int /*<<< orphan*/  uio_createwithbuffer (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,int) ; 
 size_t uio_resid (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vfs_context_current () ; 
 scalar_t__ vfs_isrdonly (int /*<<< orphan*/ ) ; 
 int vn_getxattr (struct vnode*,char const*,int /*<<< orphan*/ ,size_t*,int,int /*<<< orphan*/ ) ; 
 int vn_removexattr (struct vnode*,char const*,int,int /*<<< orphan*/ ) ; 
 int vn_setxattr (struct vnode*,char const*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vnode_lock_spin (struct vnode*) ; 
 int /*<<< orphan*/  vnode_unlock (struct vnode*) ; 
 int /*<<< orphan*/  vprint (char*,struct vnode*) ; 
 int /*<<< orphan*/  wakeup (int /*<<< orphan*/ **) ; 

int
vnode_label(struct mount *mp, struct vnode *dvp, struct vnode *vp,
	    struct componentname *cnp, int flags, vfs_context_t ctx)
{
	int error = 0;


	/* fast path checks... */

	/* are we labeling vnodes? If not still notify of create */
	if (mac_label_vnodes == 0) {
		if (flags & VNODE_LABEL_CREATE)
			error = mac_vnode_notify_create(ctx,
			    mp, dvp, vp, cnp);
		return 0;
	}

	/* if already VL_LABELED */
	if (vp->v_lflag & VL_LABELED)
		return (0);

	vnode_lock_spin(vp);

	/*
	 * must revalidate state once we hold the lock
	 * since we could have blocked and someone else
	 * has since labeled this vnode
	 */
	if (vp->v_lflag & VL_LABELED) {
		vnode_unlock(vp);
		return (0);
	}

	if ((vp->v_lflag & VL_LABEL) == 0) {
		vp->v_lflag |= VL_LABEL;

		/* Could sleep on disk I/O, drop lock. */
		vnode_unlock(vp);

		if (vp->v_label == NULL)
			vp->v_label = mac_vnode_label_alloc();

		if (flags & VNODE_LABEL_CREATE)
			error = mac_vnode_notify_create(ctx,
			    mp, dvp, vp, cnp);
		else
			error = mac_vnode_label_associate(mp, vp, ctx);

		vnode_lock_spin(vp);

		if ((error == 0) && (vp->v_flag & VNCACHEABLE))
			vp->v_lflag |= VL_LABELED;
		vp->v_lflag &= ~VL_LABEL;

		if (vp->v_lflag & VL_LABELWAIT) {
			vp->v_lflag &= ~VL_LABELWAIT;
			wakeup(&vp->v_label);
		}
	} else {
		struct timespec ts;

		ts.tv_sec = 10;
		ts.tv_nsec = 0;

		while (vp->v_lflag & VL_LABEL) {
			vp->v_lflag |= VL_LABELWAIT;

			error = msleep(&vp->v_label, &vp->v_lock, PVFS|PDROP,
				       "vnode_label", &ts);
			vnode_lock_spin(vp);

			if (error == EWOULDBLOCK) {
				vprint("vnode label timeout", vp);
				break;
			}
		}
		/* XXX: what should be done if labeling failed (above)? */
	}
	vnode_unlock(vp);

	return (error);
}

void
vnode_relabel(struct vnode *vp)
{

	/* Wait for any other labeling to complete. */
	while (vp->v_lflag & VL_LABEL) {
		vp->v_lflag |= VL_LABELWAIT;
		(void)msleep(&vp->v_label, &vp->v_lock, PVFS, "vnode_relabel", 0);
	}

	/* Clear labeled flag */
	vp->v_lflag &= ~VL_LABELED;

	return;
}

int
mac_vnop_setxattr (struct vnode *vp, const char *name, char *buf, size_t len)
{
	vfs_context_t ctx;
	int options = XATTR_NOSECURITY;
	char uio_buf[ UIO_SIZEOF(1) ];
        uio_t auio;
	int error;

	if (vfs_isrdonly(vp->v_mount))
		return (EROFS);

	ctx = vfs_context_current();
	auio = uio_createwithbuffer(1, 0, UIO_SYSSPACE, UIO_WRITE,
				    &uio_buf[0], sizeof(uio_buf));
	uio_addiov(auio, CAST_USER_ADDR_T(buf), len);

	error = vn_setxattr(vp, name, auio, options, ctx);
#if CONFIG_FSE
	if (error == 0) {
		add_fsevent(FSE_XATTR_MODIFIED, ctx,
		    FSE_ARG_VNODE, vp,
		    FSE_ARG_DONE);
	}
#endif

	return (error);
}

int
mac_vnop_getxattr (struct vnode *vp, const char *name, char *buf, size_t len,
		   size_t *attrlen)
{
	vfs_context_t ctx = vfs_context_current();
	int options = XATTR_NOSECURITY;
	char uio_buf[ UIO_SIZEOF(1) ];
        uio_t auio;
	int error;

	auio = uio_createwithbuffer(1, 0, UIO_SYSSPACE, UIO_READ,
				    &uio_buf[0], sizeof(uio_buf));
	uio_addiov(auio, CAST_USER_ADDR_T(buf), len);

	error = vn_getxattr(vp, name, auio, attrlen, options, ctx);
	*attrlen = len - uio_resid(auio);

	return (error);
}

int
mac_vnop_removexattr (struct vnode *vp, const char *name)
{
	vfs_context_t ctx = vfs_context_current();
	int options = XATTR_NOSECURITY;
	int error;

	if (vfs_isrdonly(vp->v_mount))
		return (EROFS);

	error = vn_removexattr(vp, name, options, ctx);
#if CONFIG_FSE
	if (error == 0) {
		add_fsevent(FSE_XATTR_REMOVED, ctx,
		    FSE_ARG_VNODE, vp,
		    FSE_ARG_DONE);
	}
#endif

	return (error);
}

