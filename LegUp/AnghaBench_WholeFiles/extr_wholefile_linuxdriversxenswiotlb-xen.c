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
typedef  unsigned int phys_addr_t ;
typedef  enum xen_swiotlb_err { ____Placeholder_xen_swiotlb_err } xen_swiotlb_err ;
typedef  unsigned int dma_addr_t ;

/* Variables and functions */
 int ALIGN (int,int) ; 
 int IO_TLB_SEGSIZE ; 
 int IO_TLB_SHIFT ; 
 int PAGE_SHIFT ; 
 int /*<<< orphan*/  PFN_DOWN (unsigned int) ; 
 unsigned int XEN_PAGE_MASK ; 
 unsigned int XEN_PAGE_SHIFT ; 
 unsigned int XEN_PAGE_SIZE ; 
 unsigned long XEN_PFN_DOWN (unsigned int) ; 
 unsigned int XEN_PFN_PHYS (unsigned long) ; 
#define  XEN_SWIOTLB_EFIXUP 129 
#define  XEN_SWIOTLB_ENOMEM 128 
 unsigned long bfn_to_local_pfn (unsigned long) ; 
 unsigned long bfn_to_pfn (unsigned long) ; 
 int get_order (int) ; 
 int /*<<< orphan*/  max_dma_bits ; 
 int min (unsigned long,unsigned long) ; 
 unsigned long pfn_to_bfn (unsigned long) ; 
 scalar_t__ pfn_valid (int /*<<< orphan*/ ) ; 
 unsigned int virt_to_phys (void*) ; 
 int xen_create_contiguous_region (unsigned int,int,int,unsigned int*) ; 
 void* xen_io_tlb_end ; 
 int xen_io_tlb_nslabs ; 
 void* xen_io_tlb_start ; 

__attribute__((used)) static inline dma_addr_t xen_phys_to_bus(phys_addr_t paddr)
{
	unsigned long bfn = pfn_to_bfn(XEN_PFN_DOWN(paddr));
	dma_addr_t dma = (dma_addr_t)bfn << XEN_PAGE_SHIFT;

	dma |= paddr & ~XEN_PAGE_MASK;

	return dma;
}

__attribute__((used)) static inline phys_addr_t xen_bus_to_phys(dma_addr_t baddr)
{
	unsigned long xen_pfn = bfn_to_pfn(XEN_PFN_DOWN(baddr));
	dma_addr_t dma = (dma_addr_t)xen_pfn << XEN_PAGE_SHIFT;
	phys_addr_t paddr = dma;

	paddr |= baddr & ~XEN_PAGE_MASK;

	return paddr;
}

__attribute__((used)) static inline dma_addr_t xen_virt_to_bus(void *address)
{
	return xen_phys_to_bus(virt_to_phys(address));
}

__attribute__((used)) static int check_pages_physically_contiguous(unsigned long xen_pfn,
					     unsigned int offset,
					     size_t length)
{
	unsigned long next_bfn;
	int i;
	int nr_pages;

	next_bfn = pfn_to_bfn(xen_pfn);
	nr_pages = (offset + length + XEN_PAGE_SIZE-1) >> XEN_PAGE_SHIFT;

	for (i = 1; i < nr_pages; i++) {
		if (pfn_to_bfn(++xen_pfn) != ++next_bfn)
			return 0;
	}
	return 1;
}

__attribute__((used)) static inline int range_straddles_page_boundary(phys_addr_t p, size_t size)
{
	unsigned long xen_pfn = XEN_PFN_DOWN(p);
	unsigned int offset = p & ~XEN_PAGE_MASK;

	if (offset + size <= XEN_PAGE_SIZE)
		return 0;
	if (check_pages_physically_contiguous(xen_pfn, offset, size))
		return 0;
	return 1;
}

__attribute__((used)) static int is_xen_swiotlb_buffer(dma_addr_t dma_addr)
{
	unsigned long bfn = XEN_PFN_DOWN(dma_addr);
	unsigned long xen_pfn = bfn_to_local_pfn(bfn);
	phys_addr_t paddr = XEN_PFN_PHYS(xen_pfn);

	/* If the address is outside our domain, it CAN
	 * have the same virtual address as another address
	 * in our domain. Therefore _only_ check address within our domain.
	 */
	if (pfn_valid(PFN_DOWN(paddr))) {
		return paddr >= virt_to_phys(xen_io_tlb_start) &&
		       paddr < virt_to_phys(xen_io_tlb_end);
	}
	return 0;
}

__attribute__((used)) static int
xen_swiotlb_fixup(void *buf, size_t size, unsigned long nslabs)
{
	int i, rc;
	int dma_bits;
	dma_addr_t dma_handle;
	phys_addr_t p = virt_to_phys(buf);

	dma_bits = get_order(IO_TLB_SEGSIZE << IO_TLB_SHIFT) + PAGE_SHIFT;

	i = 0;
	do {
		int slabs = min(nslabs - i, (unsigned long)IO_TLB_SEGSIZE);

		do {
			rc = xen_create_contiguous_region(
				p + (i << IO_TLB_SHIFT),
				get_order(slabs << IO_TLB_SHIFT),
				dma_bits, &dma_handle);
		} while (rc && dma_bits++ < max_dma_bits);
		if (rc)
			return rc;

		i += slabs;
	} while (i < nslabs);
	return 0;
}

__attribute__((used)) static unsigned long xen_set_nslabs(unsigned long nr_tbl)
{
	if (!nr_tbl) {
		xen_io_tlb_nslabs = (64 * 1024 * 1024 >> IO_TLB_SHIFT);
		xen_io_tlb_nslabs = ALIGN(xen_io_tlb_nslabs, IO_TLB_SEGSIZE);
	} else
		xen_io_tlb_nslabs = nr_tbl;

	return xen_io_tlb_nslabs << IO_TLB_SHIFT;
}

__attribute__((used)) static const char *xen_swiotlb_error(enum xen_swiotlb_err err)
{
	switch (err) {
	case XEN_SWIOTLB_ENOMEM:
		return "Cannot allocate Xen-SWIOTLB buffer\n";
	case XEN_SWIOTLB_EFIXUP:
		return "Failed to get contiguous memory for DMA from Xen!\n"\
		    "You either: don't have the permissions, do not have"\
		    " enough free memory under 4GB, or the hypervisor memory"\
		    " is too fragmented!";
	default:
		break;
	}
	return "";
}

