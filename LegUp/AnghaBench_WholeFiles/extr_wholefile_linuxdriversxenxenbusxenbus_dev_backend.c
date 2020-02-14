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
struct vm_area_struct {size_t vm_end; size_t vm_start; scalar_t__ vm_pgoff; int /*<<< orphan*/  vm_page_prot; } ;
struct inode {int dummy; } ;
struct file {int dummy; } ;
struct evtchn_alloc_unbound {unsigned long remote_dom; scalar_t__ port; int /*<<< orphan*/  dom; } ;
typedef  unsigned long domid_t ;

/* Variables and functions */
 int /*<<< orphan*/  CAP_SYS_ADMIN ; 
 int /*<<< orphan*/  DOMID_SELF ; 
 int EAGAIN ; 
 int EEXIST ; 
 int EINVAL ; 
 long ENODEV ; 
 long ENOTTY ; 
 int EPERM ; 
 int /*<<< orphan*/  EVTCHNOP_alloc_unbound ; 
 int /*<<< orphan*/  GNTTAB_RESERVED_XENSTORE ; 
 int HYPERVISOR_event_channel_op (int /*<<< orphan*/ ,struct evtchn_alloc_unbound*) ; 
#define  IOCTL_XENBUS_BACKEND_EVTCHN 129 
#define  IOCTL_XENBUS_BACKEND_SETUP 128 
 size_t PAGE_SIZE ; 
 int /*<<< orphan*/  capable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gnttab_grant_foreign_access_ref (int /*<<< orphan*/ ,unsigned long,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int nonseekable_open (struct inode*,struct file*) ; 
 scalar_t__ remap_pfn_range (struct vm_area_struct*,size_t,int /*<<< orphan*/ ,size_t,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  virt_to_gfn (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  virt_to_pfn (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xb_deinit_comms () ; 
 scalar_t__ xen_store_evtchn ; 
 int /*<<< orphan*/  xen_store_interface ; 
 scalar_t__ xenstored_ready ; 
 int /*<<< orphan*/  xs_resume () ; 
 int /*<<< orphan*/  xs_suspend () ; 
 int /*<<< orphan*/  xs_suspend_cancel () ; 

__attribute__((used)) static int xenbus_backend_open(struct inode *inode, struct file *filp)
{
	if (!capable(CAP_SYS_ADMIN))
		return -EPERM;

	return nonseekable_open(inode, filp);
}

__attribute__((used)) static long xenbus_alloc(domid_t domid)
{
	struct evtchn_alloc_unbound arg;
	int err = -EEXIST;

	xs_suspend();

	/* If xenstored_ready is nonzero, that means we have already talked to
	 * xenstore and set up watches. These watches will be restored by
	 * xs_resume, but that requires communication over the port established
	 * below that is not visible to anyone until the ioctl returns.
	 *
	 * This can be resolved by splitting the ioctl into two parts
	 * (postponing the resume until xenstored is active) but this is
	 * unnecessarily complex for the intended use where xenstored is only
	 * started once - so return -EEXIST if it's already running.
	 */
	if (xenstored_ready)
		goto out_err;

	gnttab_grant_foreign_access_ref(GNTTAB_RESERVED_XENSTORE, domid,
			virt_to_gfn(xen_store_interface), 0 /* writable */);

	arg.dom = DOMID_SELF;
	arg.remote_dom = domid;

	err = HYPERVISOR_event_channel_op(EVTCHNOP_alloc_unbound, &arg);
	if (err)
		goto out_err;

	if (xen_store_evtchn > 0)
		xb_deinit_comms();

	xen_store_evtchn = arg.port;

	xs_resume();

	return arg.port;

 out_err:
	xs_suspend_cancel();
	return err;
}

__attribute__((used)) static long xenbus_backend_ioctl(struct file *file, unsigned int cmd,
				 unsigned long data)
{
	if (!capable(CAP_SYS_ADMIN))
		return -EPERM;

	switch (cmd) {
	case IOCTL_XENBUS_BACKEND_EVTCHN:
		if (xen_store_evtchn > 0)
			return xen_store_evtchn;
		return -ENODEV;
	case IOCTL_XENBUS_BACKEND_SETUP:
		return xenbus_alloc(data);
	default:
		return -ENOTTY;
	}
}

__attribute__((used)) static int xenbus_backend_mmap(struct file *file, struct vm_area_struct *vma)
{
	size_t size = vma->vm_end - vma->vm_start;

	if (!capable(CAP_SYS_ADMIN))
		return -EPERM;

	if ((size > PAGE_SIZE) || (vma->vm_pgoff != 0))
		return -EINVAL;

	if (remap_pfn_range(vma, vma->vm_start,
			    virt_to_pfn(xen_store_interface),
			    size, vma->vm_page_prot))
		return -EAGAIN;

	return 0;
}

