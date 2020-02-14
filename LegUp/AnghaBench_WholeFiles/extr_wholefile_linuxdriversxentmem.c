#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct tmem_pool_uuid {int /*<<< orphan*/  uuid_hi; int /*<<< orphan*/  uuid_lo; } ;
struct TYPE_5__ {int flags; int /*<<< orphan*/ * uuid; } ;
struct TYPE_4__ {int index; int tmem_offset; int pfn_offset; int len; int /*<<< orphan*/  gmfn; int /*<<< orphan*/ * oid; } ;
struct TYPE_6__ {TYPE_2__ new; TYPE_1__ gen; } ;
struct tmem_op {int cmd; int pool_id; TYPE_3__ u; } ;
struct tmem_oid {int /*<<< orphan*/ * oid; } ;
struct page {int dummy; } ;

/* Variables and functions */
 int HYPERVISOR_tmem_op (struct tmem_op*) ; 
 int TMEM_FLUSH_OBJECT ; 
 int TMEM_FLUSH_PAGE ; 
 int TMEM_GET_PAGE ; 
 int TMEM_NEW_POOL ; 
 int TMEM_POOL_PAGESIZE_SHIFT ; 
 int TMEM_PUT_PAGE ; 
 int TMEM_SPEC_VERSION ; 
 int TMEM_VERSION_SHIFT ; 
 int /*<<< orphan*/  set_xen_guest_handle (int /*<<< orphan*/ ,void*) ; 
 unsigned long xen_page_to_gfn (struct page*) ; 

__attribute__((used)) static inline int xen_tmem_op(u32 tmem_cmd, u32 tmem_pool, struct tmem_oid oid,
	u32 index, unsigned long gmfn, u32 tmem_offset, u32 pfn_offset, u32 len)
{
	struct tmem_op op;
	int rc = 0;

	op.cmd = tmem_cmd;
	op.pool_id = tmem_pool;
	op.u.gen.oid[0] = oid.oid[0];
	op.u.gen.oid[1] = oid.oid[1];
	op.u.gen.oid[2] = oid.oid[2];
	op.u.gen.index = index;
	op.u.gen.tmem_offset = tmem_offset;
	op.u.gen.pfn_offset = pfn_offset;
	op.u.gen.len = len;
	set_xen_guest_handle(op.u.gen.gmfn, (void *)gmfn);
	rc = HYPERVISOR_tmem_op(&op);
	return rc;
}

__attribute__((used)) static int xen_tmem_new_pool(struct tmem_pool_uuid uuid,
				u32 flags, unsigned long pagesize)
{
	struct tmem_op op;
	int rc = 0, pageshift;

	for (pageshift = 0; pagesize != 1; pageshift++)
		pagesize >>= 1;
	flags |= (pageshift - 12) << TMEM_POOL_PAGESIZE_SHIFT;
	flags |= TMEM_SPEC_VERSION << TMEM_VERSION_SHIFT;
	op.cmd = TMEM_NEW_POOL;
	op.u.new.uuid[0] = uuid.uuid_lo;
	op.u.new.uuid[1] = uuid.uuid_hi;
	op.u.new.flags = flags;
	rc = HYPERVISOR_tmem_op(&op);
	return rc;
}

__attribute__((used)) static int xen_tmem_put_page(u32 pool_id, struct tmem_oid oid,
			     u32 index, struct page *page)
{
	return xen_tmem_op(TMEM_PUT_PAGE, pool_id, oid, index,
			   xen_page_to_gfn(page), 0, 0, 0);
}

__attribute__((used)) static int xen_tmem_get_page(u32 pool_id, struct tmem_oid oid,
			     u32 index, struct page *page)
{
	return xen_tmem_op(TMEM_GET_PAGE, pool_id, oid, index,
			   xen_page_to_gfn(page), 0, 0, 0);
}

__attribute__((used)) static int xen_tmem_flush_page(u32 pool_id, struct tmem_oid oid, u32 index)
{
	return xen_tmem_op(TMEM_FLUSH_PAGE, pool_id, oid, index,
		0, 0, 0, 0);
}

__attribute__((used)) static int xen_tmem_flush_object(u32 pool_id, struct tmem_oid oid)
{
	return xen_tmem_op(TMEM_FLUSH_OBJECT, pool_id, oid, 0, 0, 0, 0, 0);
}

