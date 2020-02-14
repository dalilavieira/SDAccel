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
struct vm_area_struct {unsigned long vm_pgoff; int /*<<< orphan*/  vm_page_prot; int /*<<< orphan*/  vm_start; } ;
struct page {int dummy; } ;
struct device {int dummy; } ;
typedef  unsigned long phys_addr_t ;
typedef  int /*<<< orphan*/  gfp_t ;
typedef  enum dma_data_direction { ____Placeholder_dma_data_direction } dma_data_direction ;
typedef  int /*<<< orphan*/  dma_addr_t ;

/* Variables and functions */
 int /*<<< orphan*/  BUG () ; 
 int /*<<< orphan*/  BUG_ON (int) ; 
 unsigned long CAC_ADDR (unsigned long) ; 
#define  CPU_BMIPS5000 136 
#define  CPU_R10000 135 
#define  CPU_R12000 134 
 unsigned long DMA_ATTR_NON_CONSISTENT ; 
 unsigned long DMA_ATTR_WRITE_COMBINE ; 
#define  DMA_BIDIRECTIONAL 133 
#define  DMA_FROM_DEVICE 132 
 int DMA_NONE ; 
#define  DMA_TO_DEVICE 131 
 int ENXIO ; 
#define  IO_COHERENCE_DEFAULT 130 
#define  IO_COHERENCE_DISABLED 129 
#define  IO_COHERENCE_ENABLED 128 
 unsigned long PAGE_ALIGN (size_t) ; 
 unsigned long PAGE_MASK ; 
 unsigned long PAGE_SHIFT ; 
 unsigned long PAGE_SIZE ; 
 scalar_t__ PageHighMem (struct page*) ; 
 scalar_t__ UNCAC_ADDR (void*) ; 
 int boot_cpu_type () ; 
 int coherentio ; 
 int cpu_has_maar ; 
 int /*<<< orphan*/  dma_cache_inv (unsigned long,size_t) ; 
 int /*<<< orphan*/  dma_cache_wback (unsigned long,size_t) ; 
 int /*<<< orphan*/  dma_cache_wback_inv (unsigned long,size_t) ; 
 void* dma_direct_alloc (struct device*,size_t,int /*<<< orphan*/ *,int /*<<< orphan*/ ,unsigned long) ; 
 int /*<<< orphan*/  dma_direct_free (struct device*,size_t,void*,int /*<<< orphan*/ ,unsigned long) ; 
 scalar_t__ dma_mmap_from_dev_coherent (struct device*,struct vm_area_struct*,void*,size_t,int*) ; 
 int hw_coherentio ; 
 void* kmap_atomic (struct page*) ; 
 int /*<<< orphan*/  kunmap_atomic (void*) ; 
 void* page_address (struct page*) ; 
 unsigned long page_to_pfn (int /*<<< orphan*/ ) ; 
 struct page* pfn_to_page (unsigned long) ; 
 int /*<<< orphan*/  pgprot_noncached (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pgprot_writecombine (int /*<<< orphan*/ ) ; 
 int remap_pfn_range (struct vm_area_struct*,int /*<<< orphan*/ ,unsigned long,unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  virt_to_page (void*) ; 
 unsigned long vma_pages (struct vm_area_struct*) ; 

__attribute__((used)) static inline int dev_is_coherent(struct device *dev)
{
	switch (coherentio) {
	default:
	case IO_COHERENCE_DEFAULT:
		return hw_coherentio;
	case IO_COHERENCE_ENABLED:
		return 1;
	case IO_COHERENCE_DISABLED:
		return 0;
	}
}

__attribute__((used)) static inline bool cpu_needs_post_dma_flush(struct device *dev)
{
	if (dev_is_coherent(dev))
		return false;

	switch (boot_cpu_type()) {
	case CPU_R10000:
	case CPU_R12000:
	case CPU_BMIPS5000:
		return true;
	default:
		/*
		 * Presence of MAARs suggests that the CPU supports
		 * speculatively prefetching data, and therefore requires
		 * the post-DMA flush/invalidate.
		 */
		return cpu_has_maar;
	}
}

void *arch_dma_alloc(struct device *dev, size_t size,
		dma_addr_t *dma_handle, gfp_t gfp, unsigned long attrs)
{
	void *ret;

	ret = dma_direct_alloc(dev, size, dma_handle, gfp, attrs);
	if (!ret)
		return NULL;

	if (!dev_is_coherent(dev) && !(attrs & DMA_ATTR_NON_CONSISTENT)) {
		dma_cache_wback_inv((unsigned long) ret, size);
		ret = (void *)UNCAC_ADDR(ret);
	}

	return ret;
}

void arch_dma_free(struct device *dev, size_t size, void *cpu_addr,
		dma_addr_t dma_addr, unsigned long attrs)
{
	if (!(attrs & DMA_ATTR_NON_CONSISTENT) && !dev_is_coherent(dev))
		cpu_addr = (void *)CAC_ADDR((unsigned long)cpu_addr);
	dma_direct_free(dev, size, cpu_addr, dma_addr, attrs);
}

int arch_dma_mmap(struct device *dev, struct vm_area_struct *vma,
		void *cpu_addr, dma_addr_t dma_addr, size_t size,
		unsigned long attrs)
{
	unsigned long user_count = vma_pages(vma);
	unsigned long count = PAGE_ALIGN(size) >> PAGE_SHIFT;
	unsigned long addr = (unsigned long)cpu_addr;
	unsigned long off = vma->vm_pgoff;
	unsigned long pfn;
	int ret = -ENXIO;

	if (!dev_is_coherent(dev))
		addr = CAC_ADDR(addr);

	pfn = page_to_pfn(virt_to_page((void *)addr));

	if (attrs & DMA_ATTR_WRITE_COMBINE)
		vma->vm_page_prot = pgprot_writecombine(vma->vm_page_prot);
	else
		vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);

	if (dma_mmap_from_dev_coherent(dev, vma, cpu_addr, size, &ret))
		return ret;

	if (off < count && user_count <= (count - off)) {
		ret = remap_pfn_range(vma, vma->vm_start,
				      pfn + off,
				      user_count << PAGE_SHIFT,
				      vma->vm_page_prot);
	}

	return ret;
}

__attribute__((used)) static inline void dma_sync_virt(void *addr, size_t size,
		enum dma_data_direction dir)
{
	switch (dir) {
	case DMA_TO_DEVICE:
		dma_cache_wback((unsigned long)addr, size);
		break;

	case DMA_FROM_DEVICE:
		dma_cache_inv((unsigned long)addr, size);
		break;

	case DMA_BIDIRECTIONAL:
		dma_cache_wback_inv((unsigned long)addr, size);
		break;

	default:
		BUG();
	}
}

__attribute__((used)) static inline void dma_sync_phys(phys_addr_t paddr, size_t size,
		enum dma_data_direction dir)
{
	struct page *page = pfn_to_page(paddr >> PAGE_SHIFT);
	unsigned long offset = paddr & ~PAGE_MASK;
	size_t left = size;

	do {
		size_t len = left;

		if (PageHighMem(page)) {
			void *addr;

			if (offset + len > PAGE_SIZE) {
				if (offset >= PAGE_SIZE) {
					page += offset >> PAGE_SHIFT;
					offset &= ~PAGE_MASK;
				}
				len = PAGE_SIZE - offset;
			}

			addr = kmap_atomic(page);
			dma_sync_virt(addr + offset, len, dir);
			kunmap_atomic(addr);
		} else
			dma_sync_virt(page_address(page) + offset, size, dir);
		offset = 0;
		page++;
		left -= len;
	} while (left);
}

void arch_sync_dma_for_device(struct device *dev, phys_addr_t paddr,
		size_t size, enum dma_data_direction dir)
{
	if (!dev_is_coherent(dev))
		dma_sync_phys(paddr, size, dir);
}

void arch_sync_dma_for_cpu(struct device *dev, phys_addr_t paddr,
		size_t size, enum dma_data_direction dir)
{
	if (cpu_needs_post_dma_flush(dev))
		dma_sync_phys(paddr, size, dir);
}

void arch_dma_cache_sync(struct device *dev, void *vaddr, size_t size,
		enum dma_data_direction direction)
{
	BUG_ON(direction == DMA_NONE);

	if (!dev_is_coherent(dev))
		dma_sync_virt(vaddr, size, direction);
}

