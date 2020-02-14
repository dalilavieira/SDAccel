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
typedef  int xen_ulong_t ;
typedef  int xen_pfn_t ;
struct xen_remove_from_physmap {unsigned int size; int /*<<< orphan*/  errs; int /*<<< orphan*/  idxs; int /*<<< orphan*/  gpfns; int /*<<< orphan*/  space; int /*<<< orphan*/  domid; void* gpfn; } ;
struct xen_add_to_physmap_range {unsigned int size; int /*<<< orphan*/  errs; int /*<<< orphan*/  idxs; int /*<<< orphan*/  gpfns; int /*<<< orphan*/  space; int /*<<< orphan*/  domid; void* gpfn; } ;
struct resource {int /*<<< orphan*/  start; } ;
struct platform_device {scalar_t__ num_resources; int /*<<< orphan*/  name; int /*<<< orphan*/  dev; struct resource* resource; } ;
struct notifier_block {int dummy; } ;

/* Variables and functions */
#define  BUS_NOTIFY_ADD_DEVICE 129 
#define  BUS_NOTIFY_DEL_DEVICE 128 
 unsigned int DIV_ROUND_UP (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DOMID_SELF ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HYPERVISOR_memory_op (int /*<<< orphan*/ ,struct xen_remove_from_physmap*) ; 
 scalar_t__ IORESOURCE_MEM ; 
 int NOTIFY_DONE ; 
 int NOTIFY_OK ; 
 int /*<<< orphan*/  XENMAPSPACE_dev_mmio ; 
 int /*<<< orphan*/  XENMEM_add_to_physmap_range ; 
 int /*<<< orphan*/  XENMEM_remove_from_physmap ; 
 int /*<<< orphan*/  XEN_PAGE_SIZE ; 
 void* XEN_PFN_DOWN (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,char*,int /*<<< orphan*/ ) ; 
 int* kcalloc (unsigned int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (int*) ; 
 int /*<<< orphan*/  resource_size (struct resource const*) ; 
 scalar_t__ resource_type (struct resource const*) ; 
 int /*<<< orphan*/  set_xen_guest_handle (int /*<<< orphan*/ ,int*) ; 
 struct platform_device* to_platform_device (void*) ; 

__attribute__((used)) static int xen_unmap_device_mmio(const struct resource *resources,
				 unsigned int count)
{
	unsigned int i, j, nr;
	int rc = 0;
	const struct resource *r;
	struct xen_remove_from_physmap xrp;

	for (i = 0; i < count; i++) {
		r = &resources[i];
		nr = DIV_ROUND_UP(resource_size(r), XEN_PAGE_SIZE);
		if ((resource_type(r) != IORESOURCE_MEM) || (nr == 0))
			continue;

		for (j = 0; j < nr; j++) {
			xrp.domid = DOMID_SELF;
			xrp.gpfn = XEN_PFN_DOWN(r->start) + j;
			rc = HYPERVISOR_memory_op(XENMEM_remove_from_physmap,
						  &xrp);
			if (rc)
				return rc;
		}
	}

	return rc;
}

__attribute__((used)) static int xen_map_device_mmio(const struct resource *resources,
			       unsigned int count)
{
	unsigned int i, j, nr;
	int rc = 0;
	const struct resource *r;
	xen_pfn_t *gpfns;
	xen_ulong_t *idxs;
	int *errs;

	for (i = 0; i < count; i++) {
		struct xen_add_to_physmap_range xatp = {
			.domid = DOMID_SELF,
			.space = XENMAPSPACE_dev_mmio
		};

		r = &resources[i];
		nr = DIV_ROUND_UP(resource_size(r), XEN_PAGE_SIZE);
		if ((resource_type(r) != IORESOURCE_MEM) || (nr == 0))
			continue;

		gpfns = kcalloc(nr, sizeof(xen_pfn_t), GFP_KERNEL);
		idxs = kcalloc(nr, sizeof(xen_ulong_t), GFP_KERNEL);
		errs = kcalloc(nr, sizeof(int), GFP_KERNEL);
		if (!gpfns || !idxs || !errs) {
			kfree(gpfns);
			kfree(idxs);
			kfree(errs);
			rc = -ENOMEM;
			goto unmap;
		}

		for (j = 0; j < nr; j++) {
			/*
			 * The regions are always mapped 1:1 to DOM0 and this is
			 * fine because the memory map for DOM0 is the same as
			 * the host (except for the RAM).
			 */
			gpfns[j] = XEN_PFN_DOWN(r->start) + j;
			idxs[j] = XEN_PFN_DOWN(r->start) + j;
		}

		xatp.size = nr;

		set_xen_guest_handle(xatp.gpfns, gpfns);
		set_xen_guest_handle(xatp.idxs, idxs);
		set_xen_guest_handle(xatp.errs, errs);

		rc = HYPERVISOR_memory_op(XENMEM_add_to_physmap_range, &xatp);
		kfree(gpfns);
		kfree(idxs);
		kfree(errs);
		if (rc)
			goto unmap;
	}

	return rc;

unmap:
	xen_unmap_device_mmio(resources, i);
	return rc;
}

__attribute__((used)) static int xen_platform_notifier(struct notifier_block *nb,
				 unsigned long action, void *data)
{
	struct platform_device *pdev = to_platform_device(data);
	int r = 0;

	if (pdev->num_resources == 0 || pdev->resource == NULL)
		return NOTIFY_OK;

	switch (action) {
	case BUS_NOTIFY_ADD_DEVICE:
		r = xen_map_device_mmio(pdev->resource, pdev->num_resources);
		break;
	case BUS_NOTIFY_DEL_DEVICE:
		r = xen_unmap_device_mmio(pdev->resource, pdev->num_resources);
		break;
	default:
		return NOTIFY_DONE;
	}
	if (r)
		dev_err(&pdev->dev, "Platform: Failed to %s device %s MMIO!\n",
			action == BUS_NOTIFY_ADD_DEVICE ? "map" :
			(action == BUS_NOTIFY_DEL_DEVICE ? "unmap" : "?"),
			pdev->name);

	return NOTIFY_OK;
}

