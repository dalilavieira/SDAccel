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
struct page_change_data {void* clear_mask; void* set_mask; } ;
typedef  int /*<<< orphan*/  pte_t ;
typedef  int /*<<< orphan*/  pgtable_t ;
typedef  void* pgprot_t ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  L_PTE_RDONLY ; 
 int /*<<< orphan*/  L_PTE_XN ; 
 unsigned long MODULES_END ; 
 unsigned long MODULES_VADDR ; 
 int PAGE_ALIGN (unsigned long) ; 
 unsigned long PAGE_MASK ; 
 int PAGE_SIZE ; 
 unsigned long VMALLOC_END ; 
 unsigned long VMALLOC_START ; 
 int /*<<< orphan*/  WARN_ON_ONCE (int) ; 
 void* __pgprot (int /*<<< orphan*/ ) ; 
 int apply_to_page_range (int /*<<< orphan*/ *,unsigned long,unsigned long,int (*) (int /*<<< orphan*/ *,int /*<<< orphan*/ ,unsigned long,void*),struct page_change_data*) ; 
 int /*<<< orphan*/  clear_pte_bit (int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  flush_tlb_kernel_range (unsigned long,unsigned long) ; 
 int /*<<< orphan*/  init_mm ; 
 int /*<<< orphan*/  set_pte_bit (int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  set_pte_ext (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int change_page_range(pte_t *ptep, pgtable_t token, unsigned long addr,
			void *data)
{
	struct page_change_data *cdata = data;
	pte_t pte = *ptep;

	pte = clear_pte_bit(pte, cdata->clear_mask);
	pte = set_pte_bit(pte, cdata->set_mask);

	set_pte_ext(ptep, pte, 0);
	return 0;
}

__attribute__((used)) static bool in_range(unsigned long start, unsigned long size,
	unsigned long range_start, unsigned long range_end)
{
	return start >= range_start && start < range_end &&
		size <= range_end - start;
}

__attribute__((used)) static int change_memory_common(unsigned long addr, int numpages,
				pgprot_t set_mask, pgprot_t clear_mask)
{
	unsigned long start = addr & PAGE_MASK;
	unsigned long end = PAGE_ALIGN(addr) + numpages * PAGE_SIZE;
	unsigned long size = end - start;
	int ret;
	struct page_change_data data;

	WARN_ON_ONCE(start != addr);

	if (!size)
		return 0;

	if (!in_range(start, size, MODULES_VADDR, MODULES_END) &&
	    !in_range(start, size, VMALLOC_START, VMALLOC_END))
		return -EINVAL;

	data.set_mask = set_mask;
	data.clear_mask = clear_mask;

	ret = apply_to_page_range(&init_mm, start, size, change_page_range,
					&data);

	flush_tlb_kernel_range(start, end);
	return ret;
}

int set_memory_ro(unsigned long addr, int numpages)
{
	return change_memory_common(addr, numpages,
					__pgprot(L_PTE_RDONLY),
					__pgprot(0));
}

int set_memory_rw(unsigned long addr, int numpages)
{
	return change_memory_common(addr, numpages,
					__pgprot(0),
					__pgprot(L_PTE_RDONLY));
}

int set_memory_nx(unsigned long addr, int numpages)
{
	return change_memory_common(addr, numpages,
					__pgprot(L_PTE_XN),
					__pgprot(0));
}

int set_memory_x(unsigned long addr, int numpages)
{
	return change_memory_common(addr, numpages,
					__pgprot(0),
					__pgprot(L_PTE_XN));
}

