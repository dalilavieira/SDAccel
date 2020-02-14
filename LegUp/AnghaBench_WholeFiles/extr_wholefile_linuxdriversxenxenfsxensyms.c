#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint64_t ;
struct xenpf_symdata {scalar_t__ namelen; scalar_t__ symnum; int /*<<< orphan*/  name; int /*<<< orphan*/  type; int /*<<< orphan*/  address; } ;
struct TYPE_3__ {struct xenpf_symdata symdata; } ;
struct TYPE_4__ {TYPE_1__ u; int /*<<< orphan*/  cmd; } ;
struct xensyms {scalar_t__ namelen; void* name; TYPE_2__ op; } ;
struct seq_file {void* private; } ;
struct inode {int dummy; } ;
struct file {struct seq_file* private_data; } ;
typedef  void* loff_t ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HYPERVISOR_platform_op (TYPE_2__*) ; 
 int /*<<< orphan*/  XENPF_get_symbol ; 
 scalar_t__ XEN_KSYM_NAME_LEN ; 
 int /*<<< orphan*/  kfree (void*) ; 
 void* kzalloc (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (void*,int /*<<< orphan*/ ,scalar_t__) ; 
 int seq_open_private (struct file*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  seq_printf (struct seq_file*,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*) ; 
 int seq_release_private (struct inode*,struct file*) ; 
 int /*<<< orphan*/  set_xen_guest_handle (int /*<<< orphan*/ ,void*) ; 
 scalar_t__ unlikely (int) ; 
 int /*<<< orphan*/  xensyms_seq_ops ; 

__attribute__((used)) static int xensyms_next_sym(struct xensyms *xs)
{
	int ret;
	struct xenpf_symdata *symdata = &xs->op.u.symdata;
	uint64_t symnum;

	memset(xs->name, 0, xs->namelen);
	symdata->namelen = xs->namelen;

	symnum = symdata->symnum;

	ret = HYPERVISOR_platform_op(&xs->op);
	if (ret < 0)
		return ret;

	/*
	 * If hypervisor's symbol didn't fit into the buffer then allocate
	 * a larger buffer and try again.
	 */
	if (unlikely(symdata->namelen > xs->namelen)) {
		kfree(xs->name);

		xs->namelen = symdata->namelen;
		xs->name = kzalloc(xs->namelen, GFP_KERNEL);
		if (!xs->name)
			return -ENOMEM;

		set_xen_guest_handle(symdata->name, xs->name);
		symdata->symnum--; /* Rewind */

		ret = HYPERVISOR_platform_op(&xs->op);
		if (ret < 0)
			return ret;
	}

	if (symdata->symnum == symnum)
		/* End of symbols */
		return 1;

	return 0;
}

__attribute__((used)) static void *xensyms_start(struct seq_file *m, loff_t *pos)
{
	struct xensyms *xs = (struct xensyms *)m->private;

	xs->op.u.symdata.symnum = *pos;

	if (xensyms_next_sym(xs))
		return NULL;

	return m->private;
}

__attribute__((used)) static void *xensyms_next(struct seq_file *m, void *p, loff_t *pos)
{
	struct xensyms *xs = (struct xensyms *)m->private;

	xs->op.u.symdata.symnum = ++(*pos);

	if (xensyms_next_sym(xs))
		return NULL;

	return p;
}

__attribute__((used)) static int xensyms_show(struct seq_file *m, void *p)
{
	struct xensyms *xs = (struct xensyms *)m->private;
	struct xenpf_symdata *symdata = &xs->op.u.symdata;

	seq_printf(m, "%016llx %c %s\n", symdata->address,
		   symdata->type, xs->name);

	return 0;
}

__attribute__((used)) static void xensyms_stop(struct seq_file *m, void *p)
{
}

__attribute__((used)) static int xensyms_open(struct inode *inode, struct file *file)
{
	struct seq_file *m;
	struct xensyms *xs;
	int ret;

	ret = seq_open_private(file, &xensyms_seq_ops,
			       sizeof(struct xensyms));
	if (ret)
		return ret;

	m = file->private_data;
	xs = (struct xensyms *)m->private;

	xs->namelen = XEN_KSYM_NAME_LEN + 1;
	xs->name = kzalloc(xs->namelen, GFP_KERNEL);
	if (!xs->name) {
		seq_release_private(inode, file);
		return -ENOMEM;
	}
	set_xen_guest_handle(xs->op.u.symdata.name, xs->name);
	xs->op.cmd = XENPF_get_symbol;
	xs->op.u.symdata.namelen = xs->namelen;

	return 0;
}

__attribute__((used)) static int xensyms_release(struct inode *inode, struct file *file)
{
	struct seq_file *m = file->private_data;
	struct xensyms *xs = (struct xensyms *)m->private;

	kfree(xs->name);
	return seq_release_private(inode, file);
}

