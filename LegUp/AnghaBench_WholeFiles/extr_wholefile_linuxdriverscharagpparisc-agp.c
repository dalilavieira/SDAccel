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
typedef  int u32 ;
struct agp_memory {int type; int page_count; int is_flushed; int /*<<< orphan*/ * pages; } ;
struct agp_bridge_data {int gart_bus_addr; unsigned long scratch_page; TYPE_1__* driver; void* mode; scalar_t__ capndx; void* current_size; } ;
struct _parisc_agp_info {int gart_size; int gart_base; int gatt_entries; unsigned long* gatt; int io_pages_per_kpage; scalar_t__ lba_cap_offset; scalar_t__ lba_regs; scalar_t__ io_page_size; scalar_t__ ioc_regs; } ;
typedef  int off_t ;
typedef  unsigned long dma_addr_t ;
struct TYPE_4__ {int size; } ;
struct TYPE_3__ {int /*<<< orphan*/  (* tlb_flush ) (struct agp_memory*) ;scalar_t__ (* agp_type_to_mask_type ) (struct agp_bridge_data*,int) ;} ;

/* Variables and functions */
 int AGP8X_MODE ; 
 int EBUSY ; 
 int EINVAL ; 
 scalar_t__ IOC_PCOM ; 
 int MB (int) ; 
 scalar_t__ PCI_AGP_COMMAND ; 
 scalar_t__ PCI_AGP_STATUS ; 
 unsigned long SBA_AGPGART_COOKIE ; 
 unsigned long SBA_PDIR_VALID_BIT ; 
 struct agp_bridge_data* agp_bridge ; 
 int agp_collect_device_status (struct agp_bridge_data*,int,int) ; 
 int /*<<< orphan*/  agp_device_command (int,int) ; 
 int /*<<< orphan*/  global_cache_flush () ; 
 int ilog2 (int) ; 
 int /*<<< orphan*/  kvfree (int /*<<< orphan*/ *) ; 
 unsigned long page_to_phys (int /*<<< orphan*/ ) ; 
 struct _parisc_agp_info parisc_agp_info ; 
static  unsigned long parisc_agp_mask_memory (struct agp_bridge_data*,unsigned long,int) ; 
 TYPE_2__* parisc_agp_sizes ; 
 void* readl (scalar_t__) ; 
 int /*<<< orphan*/  readq (scalar_t__) ; 
 scalar_t__ stub1 (struct agp_bridge_data*,int) ; 
 int /*<<< orphan*/  stub2 (struct agp_memory*) ; 
 scalar_t__ stub3 (struct agp_bridge_data*,int) ; 
 int /*<<< orphan*/  stub4 (struct agp_memory*) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 
 int /*<<< orphan*/  writeq (int,scalar_t__) ; 

__attribute__((used)) static inline void agp_free_page_array(struct agp_memory *mem)
{
	kvfree(mem->pages);
}

__attribute__((used)) static int
parisc_agp_fetch_size(void)
{
	int size;

	size = parisc_agp_info.gart_size / MB(1);
	parisc_agp_sizes[0].size = size;
	agp_bridge->current_size = (void *) &parisc_agp_sizes[0];

	return size;
}

__attribute__((used)) static int
parisc_agp_configure(void)
{
	struct _parisc_agp_info *info = &parisc_agp_info;

	agp_bridge->gart_bus_addr = info->gart_base;
	agp_bridge->capndx = info->lba_cap_offset;
	agp_bridge->mode = readl(info->lba_regs+info->lba_cap_offset+PCI_AGP_STATUS);

	return 0;
}

__attribute__((used)) static void
parisc_agp_tlbflush(struct agp_memory *mem)
{
	struct _parisc_agp_info *info = &parisc_agp_info;

	writeq(info->gart_base | ilog2(info->gart_size), info->ioc_regs+IOC_PCOM);
	readq(info->ioc_regs+IOC_PCOM);	/* flush */
}

__attribute__((used)) static int
parisc_agp_create_gatt_table(struct agp_bridge_data *bridge)
{
	struct _parisc_agp_info *info = &parisc_agp_info;
	int i;

	for (i = 0; i < info->gatt_entries; i++) {
		info->gatt[i] = (unsigned long)agp_bridge->scratch_page;
	}

	return 0;
}

__attribute__((used)) static int
parisc_agp_free_gatt_table(struct agp_bridge_data *bridge)
{
	struct _parisc_agp_info *info = &parisc_agp_info;

	info->gatt[0] = SBA_AGPGART_COOKIE;

	return 0;
}

__attribute__((used)) static int
parisc_agp_insert_memory(struct agp_memory *mem, off_t pg_start, int type)
{
	struct _parisc_agp_info *info = &parisc_agp_info;
	int i, k;
	off_t j, io_pg_start;
	int io_pg_count;

	if (type != mem->type ||
		agp_bridge->driver->agp_type_to_mask_type(agp_bridge, type)) {
		return -EINVAL;
	}

	io_pg_start = info->io_pages_per_kpage * pg_start;
	io_pg_count = info->io_pages_per_kpage * mem->page_count;
	if ((io_pg_start + io_pg_count) > info->gatt_entries) {
		return -EINVAL;
	}

	j = io_pg_start;
	while (j < (io_pg_start + io_pg_count)) {
		if (info->gatt[j])
			return -EBUSY;
		j++;
	}

	if (!mem->is_flushed) {
		global_cache_flush();
		mem->is_flushed = true;
	}

	for (i = 0, j = io_pg_start; i < mem->page_count; i++) {
		unsigned long paddr;

		paddr = page_to_phys(mem->pages[i]);
		for (k = 0;
		     k < info->io_pages_per_kpage;
		     k++, j++, paddr += info->io_page_size) {
			info->gatt[j] =
				parisc_agp_mask_memory(agp_bridge,
					paddr, type);
		}
	}

	agp_bridge->driver->tlb_flush(mem);

	return 0;
}

__attribute__((used)) static int
parisc_agp_remove_memory(struct agp_memory *mem, off_t pg_start, int type)
{
	struct _parisc_agp_info *info = &parisc_agp_info;
	int i, io_pg_start, io_pg_count;

	if (type != mem->type ||
		agp_bridge->driver->agp_type_to_mask_type(agp_bridge, type)) {
		return -EINVAL;
	}

	io_pg_start = info->io_pages_per_kpage * pg_start;
	io_pg_count = info->io_pages_per_kpage * mem->page_count;
	for (i = io_pg_start; i < io_pg_count + io_pg_start; i++) {
		info->gatt[i] = agp_bridge->scratch_page;
	}

	agp_bridge->driver->tlb_flush(mem);
	return 0;
}

__attribute__((used)) static unsigned long
parisc_agp_mask_memory(struct agp_bridge_data *bridge, dma_addr_t addr,
		       int type)
{
	return SBA_PDIR_VALID_BIT | addr;
}

__attribute__((used)) static void
parisc_agp_enable(struct agp_bridge_data *bridge, u32 mode)
{
	struct _parisc_agp_info *info = &parisc_agp_info;
	u32 command;

	command = readl(info->lba_regs + info->lba_cap_offset + PCI_AGP_STATUS);

	command = agp_collect_device_status(bridge, mode, command);
	command |= 0x00000100;

	writel(command, info->lba_regs + info->lba_cap_offset + PCI_AGP_COMMAND);

	agp_device_command(command, (mode & AGP8X_MODE) != 0);
}

