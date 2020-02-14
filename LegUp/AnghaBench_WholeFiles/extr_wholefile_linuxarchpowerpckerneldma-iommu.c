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
typedef  int u64 ;
struct scatterlist {int dummy; } ;
struct page {int dummy; } ;
struct iommu_table {int it_offset; int it_page_shift; int it_size; } ;
struct device {int /*<<< orphan*/  coherent_dma_mask; } ;
typedef  int /*<<< orphan*/  gfp_t ;
typedef  enum dma_data_direction { ____Placeholder_dma_data_direction } dma_data_direction ;
typedef  scalar_t__ dma_addr_t ;

/* Variables and functions */
 scalar_t__ IOMMU_MAPPING_ERROR ; 
 int /*<<< orphan*/  dev_info (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_to_node (struct device*) ; 
 int /*<<< orphan*/  device_to_mask (struct device*) ; 
 int fls_long (int) ; 
 struct iommu_table* get_iommu_table_base (struct device*) ; 
 void* iommu_alloc_coherent (struct device*,struct iommu_table*,size_t,scalar_t__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iommu_free_coherent (struct iommu_table*,size_t,void*,scalar_t__) ; 
 scalar_t__ iommu_map_page (struct device*,struct iommu_table*,struct page*,unsigned long,size_t,int /*<<< orphan*/ ,int,unsigned long) ; 
 int /*<<< orphan*/  iommu_unmap_page (struct iommu_table*,scalar_t__,size_t,int,unsigned long) ; 
 int ppc_iommu_map_sg (struct device*,struct iommu_table*,struct scatterlist*,int,int /*<<< orphan*/ ,int,unsigned long) ; 
 int /*<<< orphan*/  ppc_iommu_unmap_sg (struct iommu_table*,struct scatterlist*,int,int,unsigned long) ; 

__attribute__((used)) static void *dma_iommu_alloc_coherent(struct device *dev, size_t size,
				      dma_addr_t *dma_handle, gfp_t flag,
				      unsigned long attrs)
{
	return iommu_alloc_coherent(dev, get_iommu_table_base(dev), size,
				    dma_handle, dev->coherent_dma_mask, flag,
				    dev_to_node(dev));
}

__attribute__((used)) static void dma_iommu_free_coherent(struct device *dev, size_t size,
				    void *vaddr, dma_addr_t dma_handle,
				    unsigned long attrs)
{
	iommu_free_coherent(get_iommu_table_base(dev), size, vaddr, dma_handle);
}

__attribute__((used)) static dma_addr_t dma_iommu_map_page(struct device *dev, struct page *page,
				     unsigned long offset, size_t size,
				     enum dma_data_direction direction,
				     unsigned long attrs)
{
	return iommu_map_page(dev, get_iommu_table_base(dev), page, offset,
			      size, device_to_mask(dev), direction, attrs);
}

__attribute__((used)) static void dma_iommu_unmap_page(struct device *dev, dma_addr_t dma_handle,
				 size_t size, enum dma_data_direction direction,
				 unsigned long attrs)
{
	iommu_unmap_page(get_iommu_table_base(dev), dma_handle, size, direction,
			 attrs);
}

__attribute__((used)) static int dma_iommu_map_sg(struct device *dev, struct scatterlist *sglist,
			    int nelems, enum dma_data_direction direction,
			    unsigned long attrs)
{
	return ppc_iommu_map_sg(dev, get_iommu_table_base(dev), sglist, nelems,
				device_to_mask(dev), direction, attrs);
}

__attribute__((used)) static void dma_iommu_unmap_sg(struct device *dev, struct scatterlist *sglist,
		int nelems, enum dma_data_direction direction,
		unsigned long attrs)
{
	ppc_iommu_unmap_sg(get_iommu_table_base(dev), sglist, nelems,
			   direction, attrs);
}

int dma_iommu_dma_supported(struct device *dev, u64 mask)
{
	struct iommu_table *tbl = get_iommu_table_base(dev);

	if (!tbl) {
		dev_info(dev, "Warning: IOMMU dma not supported: mask 0x%08llx"
			", table unavailable\n", mask);
		return 0;
	}

	if (tbl->it_offset > (mask >> tbl->it_page_shift)) {
		dev_info(dev, "Warning: IOMMU offset too big for device mask\n");
		dev_info(dev, "mask: 0x%08llx, table offset: 0x%08lx\n",
				mask, tbl->it_offset << tbl->it_page_shift);
		return 0;
	} else
		return 1;
}

__attribute__((used)) static u64 dma_iommu_get_required_mask(struct device *dev)
{
	struct iommu_table *tbl = get_iommu_table_base(dev);
	u64 mask;
	if (!tbl)
		return 0;

	mask = 1ULL < (fls_long(tbl->it_offset + tbl->it_size) - 1);
	mask += mask - 1;

	return mask;
}

int dma_iommu_mapping_error(struct device *dev, dma_addr_t dma_addr)
{
	return dma_addr == IOMMU_MAPPING_ERROR;
}

