#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct vm_area_struct {unsigned long vm_pgoff; int /*<<< orphan*/  vm_page_prot; int /*<<< orphan*/  vm_start; } ;
struct sg_table {int /*<<< orphan*/  sgl; } ;
struct page {int dummy; } ;
struct dma_devres {scalar_t__ size; scalar_t__ vaddr; scalar_t__ dma_handle; unsigned long attrs; size_t member_0; void* member_1; void* member_2; } ;
struct device {TYPE_1__* bus; } ;
typedef  int /*<<< orphan*/  gfp_t ;
typedef  void* dma_addr_t ;
struct TYPE_2__ {int (* dma_configure ) (struct device*) ;} ;

/* Variables and functions */
 int ENXIO ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 unsigned long PAGE_ALIGN (size_t) ; 
 unsigned long PAGE_SHIFT ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int /*<<< orphan*/  acpi_dma_deconfigure (struct device*) ; 
 int /*<<< orphan*/  devres_add (struct device*,struct dma_devres*) ; 
 struct dma_devres* devres_alloc (void (*) (struct device*,void*),int,int /*<<< orphan*/ ) ; 
 int devres_destroy (struct device*,void (*) (struct device*,void*),int (*) (struct device*,void*,void*),struct dma_devres*) ; 
 int /*<<< orphan*/  devres_free (struct dma_devres*) ; 
 void* dma_alloc_attrs (struct device*,size_t,void**,int /*<<< orphan*/ ,unsigned long) ; 
 void* dma_alloc_coherent (struct device*,size_t,void**,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dma_free_attrs (struct device*,scalar_t__,scalar_t__,scalar_t__,unsigned long) ; 
 int /*<<< orphan*/  dma_free_coherent (struct device*,size_t,void*,void*) ; 
 scalar_t__ dma_mmap_from_dev_coherent (struct device*,struct vm_area_struct*,void*,size_t,int*) ; 
 int /*<<< orphan*/  of_dma_deconfigure (struct device*) ; 
 scalar_t__ page_to_pfn (struct page*) ; 
 int /*<<< orphan*/  pgprot_noncached (int /*<<< orphan*/ ) ; 
 int remap_pfn_range (struct vm_area_struct*,int /*<<< orphan*/ ,scalar_t__,unsigned long,int /*<<< orphan*/ ) ; 
 int sg_alloc_table (struct sg_table*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sg_set_page (int /*<<< orphan*/ ,struct page*,unsigned long,int /*<<< orphan*/ ) ; 
 int stub1 (struct device*) ; 
 scalar_t__ unlikely (int) ; 
 struct page* virt_to_page (void*) ; 
 unsigned long vma_pages (struct vm_area_struct*) ; 

__attribute__((used)) static void dmam_release(struct device *dev, void *res)
{
	struct dma_devres *this = res;

	dma_free_attrs(dev, this->size, this->vaddr, this->dma_handle,
			this->attrs);
}

__attribute__((used)) static int dmam_match(struct device *dev, void *res, void *match_data)
{
	struct dma_devres *this = res, *match = match_data;

	if (this->vaddr == match->vaddr) {
		WARN_ON(this->size != match->size ||
			this->dma_handle != match->dma_handle);
		return 1;
	}
	return 0;
}

void *dmam_alloc_coherent(struct device *dev, size_t size,
			   dma_addr_t *dma_handle, gfp_t gfp)
{
	struct dma_devres *dr;
	void *vaddr;

	dr = devres_alloc(dmam_release, sizeof(*dr), gfp);
	if (!dr)
		return NULL;

	vaddr = dma_alloc_coherent(dev, size, dma_handle, gfp);
	if (!vaddr) {
		devres_free(dr);
		return NULL;
	}

	dr->vaddr = vaddr;
	dr->dma_handle = *dma_handle;
	dr->size = size;

	devres_add(dev, dr);

	return vaddr;
}

void dmam_free_coherent(struct device *dev, size_t size, void *vaddr,
			dma_addr_t dma_handle)
{
	struct dma_devres match_data = { size, vaddr, dma_handle };

	dma_free_coherent(dev, size, vaddr, dma_handle);
	WARN_ON(devres_destroy(dev, dmam_release, dmam_match, &match_data));
}

void *dmam_alloc_attrs(struct device *dev, size_t size, dma_addr_t *dma_handle,
		gfp_t gfp, unsigned long attrs)
{
	struct dma_devres *dr;
	void *vaddr;

	dr = devres_alloc(dmam_release, sizeof(*dr), gfp);
	if (!dr)
		return NULL;

	vaddr = dma_alloc_attrs(dev, size, dma_handle, gfp, attrs);
	if (!vaddr) {
		devres_free(dr);
		return NULL;
	}

	dr->vaddr = vaddr;
	dr->dma_handle = *dma_handle;
	dr->size = size;
	dr->attrs = attrs;

	devres_add(dev, dr);

	return vaddr;
}

int dma_common_get_sgtable(struct device *dev, struct sg_table *sgt,
		 void *cpu_addr, dma_addr_t handle, size_t size)
{
	struct page *page = virt_to_page(cpu_addr);
	int ret;

	ret = sg_alloc_table(sgt, 1, GFP_KERNEL);
	if (unlikely(ret))
		return ret;

	sg_set_page(sgt->sgl, page, PAGE_ALIGN(size), 0);
	return 0;
}

int dma_common_mmap(struct device *dev, struct vm_area_struct *vma,
		    void *cpu_addr, dma_addr_t dma_addr, size_t size)
{
	int ret = -ENXIO;
#ifndef CONFIG_ARCH_NO_COHERENT_DMA_MMAP
	unsigned long user_count = vma_pages(vma);
	unsigned long count = PAGE_ALIGN(size) >> PAGE_SHIFT;
	unsigned long off = vma->vm_pgoff;

	vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);

	if (dma_mmap_from_dev_coherent(dev, vma, cpu_addr, size, &ret))
		return ret;

	if (off < count && user_count <= (count - off))
		ret = remap_pfn_range(vma, vma->vm_start,
				      page_to_pfn(virt_to_page(cpu_addr)) + off,
				      user_count << PAGE_SHIFT,
				      vma->vm_page_prot);
#endif	/* !CONFIG_ARCH_NO_COHERENT_DMA_MMAP */

	return ret;
}

int dma_configure(struct device *dev)
{
	if (dev->bus->dma_configure)
		return dev->bus->dma_configure(dev);
	return 0;
}

void dma_deconfigure(struct device *dev)
{
	of_dma_deconfigure(dev);
	acpi_dma_deconfigure(dev);
}

