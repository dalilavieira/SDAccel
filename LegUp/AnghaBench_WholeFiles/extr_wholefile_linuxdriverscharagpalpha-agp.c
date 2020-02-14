#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_27__   TYPE_7__ ;
typedef  struct TYPE_26__   TYPE_6__ ;
typedef  struct TYPE_25__   TYPE_5__ ;
typedef  struct TYPE_24__   TYPE_4__ ;
typedef  struct TYPE_23__   TYPE_3__ ;
typedef  struct TYPE_22__   TYPE_2__ ;
typedef  struct TYPE_21__   TYPE_1__ ;
typedef  struct TYPE_20__   TYPE_16__ ;
typedef  struct TYPE_19__   TYPE_15__ ;
typedef  struct TYPE_18__   TYPE_14__ ;
typedef  struct TYPE_17__   TYPE_13__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  vm_fault_t ;
typedef  int /*<<< orphan*/  u32 ;
struct vm_fault {struct page* page; TYPE_1__* vma; scalar_t__ address; } ;
struct page {int dummy; } ;
struct agp_memory {int type; int page_count; int /*<<< orphan*/  pages; } ;
struct agp_bridge_data {TYPE_7__* dev_private_data; } ;
typedef  int off_t ;
typedef  scalar_t__ dma_addr_t ;
struct TYPE_24__ {int enable; } ;
struct TYPE_25__ {int /*<<< orphan*/  lw; TYPE_4__ bits; } ;
struct TYPE_23__ {int /*<<< orphan*/  lw; } ;
struct TYPE_22__ {scalar_t__ bus_base; } ;
struct TYPE_27__ {TYPE_6__* ops; TYPE_5__ mode; TYPE_3__ capability; int /*<<< orphan*/  hose; TYPE_2__ aperture; } ;
typedef  TYPE_7__ alpha_agp_info ;
struct TYPE_26__ {unsigned long (* translate ) (TYPE_7__*,scalar_t__) ;int (* bind ) (TYPE_7__*,int,struct agp_memory*) ;int (* unbind ) (TYPE_7__*,int,struct agp_memory*) ;int /*<<< orphan*/  (* configure ) (TYPE_7__*) ;int /*<<< orphan*/  (* cleanup ) (TYPE_7__*) ;} ;
struct TYPE_21__ {scalar_t__ vm_start; } ;
struct TYPE_20__ {int num_entries; } ;
struct TYPE_19__ {TYPE_7__* dev_private_data; void* current_size; scalar_t__ gart_bus_addr; } ;
struct TYPE_18__ {int size; } ;
struct TYPE_17__ {int /*<<< orphan*/  (* mv_pci_tbi ) (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ;} ;

/* Variables and functions */
 int AGP_USER_TYPES ; 
 TYPE_16__* A_SIZE_FIX (void*) ; 
 int EINVAL ; 
 int /*<<< orphan*/  VM_FAULT_SIGBUS ; 
 int /*<<< orphan*/  __va (unsigned long) ; 
 TYPE_15__* agp_bridge ; 
 int /*<<< orphan*/  agp_collect_device_status (struct agp_bridge_data*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  agp_device_command (int /*<<< orphan*/ ,int) ; 
 TYPE_14__* alpha_core_agp_sizes ; 
 TYPE_13__ alpha_mv ; 
 int /*<<< orphan*/  get_page (struct page*) ; 
 int /*<<< orphan*/  kvfree (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mb () ; 
 unsigned long stub1 (TYPE_7__*,scalar_t__) ; 
 int /*<<< orphan*/  stub2 (TYPE_7__*) ; 
 int /*<<< orphan*/  stub3 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub4 (TYPE_7__*) ; 
 int stub5 (TYPE_7__*,int,struct agp_memory*) ; 
 int stub6 (TYPE_7__*,int,struct agp_memory*) ; 
 struct page* virt_to_page (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void agp_free_page_array(struct agp_memory *mem)
{
	kvfree(mem->pages);
}

__attribute__((used)) static vm_fault_t alpha_core_agp_vm_fault(struct vm_fault *vmf)
{
	alpha_agp_info *agp = agp_bridge->dev_private_data;
	dma_addr_t dma_addr;
	unsigned long pa;
	struct page *page;

	dma_addr = vmf->address - vmf->vma->vm_start + agp->aperture.bus_base;
	pa = agp->ops->translate(agp, dma_addr);

	if (pa == (unsigned long)-EINVAL)
		return VM_FAULT_SIGBUS;	/* no translation */

	/*
	 * Get the page, inc the use count, and return it
	 */
	page = virt_to_page(__va(pa));
	get_page(page);
	vmf->page = page;
	return 0;
}

__attribute__((used)) static int alpha_core_agp_fetch_size(void)
{
	return alpha_core_agp_sizes[0].size;
}

__attribute__((used)) static int alpha_core_agp_configure(void)
{
	alpha_agp_info *agp = agp_bridge->dev_private_data;
	agp_bridge->gart_bus_addr = agp->aperture.bus_base;
	return 0;
}

__attribute__((used)) static void alpha_core_agp_cleanup(void)
{
	alpha_agp_info *agp = agp_bridge->dev_private_data;

	agp->ops->cleanup(agp);
}

__attribute__((used)) static void alpha_core_agp_tlbflush(struct agp_memory *mem)
{
	alpha_agp_info *agp = agp_bridge->dev_private_data;
	alpha_mv.mv_pci_tbi(agp->hose, 0, -1);
}

__attribute__((used)) static void alpha_core_agp_enable(struct agp_bridge_data *bridge, u32 mode)
{
	alpha_agp_info *agp = bridge->dev_private_data;

	agp->mode.lw = agp_collect_device_status(bridge, mode,
					agp->capability.lw);

	agp->mode.bits.enable = 1;
	agp->ops->configure(agp);

	agp_device_command(agp->mode.lw, false);
}

__attribute__((used)) static int alpha_core_agp_insert_memory(struct agp_memory *mem, off_t pg_start,
					int type)
{
	alpha_agp_info *agp = agp_bridge->dev_private_data;
	int num_entries, status;
	void *temp;

	if (type >= AGP_USER_TYPES || mem->type >= AGP_USER_TYPES)
		return -EINVAL;

	temp = agp_bridge->current_size;
	num_entries = A_SIZE_FIX(temp)->num_entries;
	if ((pg_start + mem->page_count) > num_entries)
		return -EINVAL;

	status = agp->ops->bind(agp, pg_start, mem);
	mb();
	alpha_core_agp_tlbflush(mem);

	return status;
}

__attribute__((used)) static int alpha_core_agp_remove_memory(struct agp_memory *mem, off_t pg_start,
					int type)
{
	alpha_agp_info *agp = agp_bridge->dev_private_data;
	int status;

	status = agp->ops->unbind(agp, pg_start, mem);
	alpha_core_agp_tlbflush(mem);
	return status;
}

__attribute__((used)) static int alpha_core_agp_create_free_gatt_table(struct agp_bridge_data *a)
{
	return 0;
}

