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
struct page {int dummy; } ;
typedef  int /*<<< orphan*/  pte_t ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int /*<<< orphan*/ ) ; 
 scalar_t__ FIXADDR_START ; 
 scalar_t__ FIX_KMAP_BEGIN ; 
 int KM_TYPE_NR ; 
 int /*<<< orphan*/  NDS32_SR_TLB_VPN ; 
 unsigned long PAGE_KERNEL ; 
 unsigned long PAGE_SHIFT ; 
 int /*<<< orphan*/  PageHighMem (struct page*) ; 
 unsigned long __fix_to_virt (scalar_t__) ; 
 int /*<<< orphan*/  __nds32__isb () ; 
 int /*<<< orphan*/  __nds32__mtsr_dsb (unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __nds32__tlbop_inv (unsigned long) ; 
 int /*<<< orphan*/  __nds32__tlbop_rwr (unsigned long) ; 
 int /*<<< orphan*/  in_interrupt () ; 
 int /*<<< orphan*/  kmap_atomic_idx_pop () ; 
 int kmap_atomic_idx_push () ; 
 scalar_t__ kmap_high (struct page*) ; 
 int /*<<< orphan*/  kunmap_high (struct page*) ; 
 int /*<<< orphan*/  might_sleep () ; 
 void* page_address (struct page*) ; 
 unsigned long page_to_pfn (struct page*) ; 
 int /*<<< orphan*/  pagefault_disable () ; 
 int /*<<< orphan*/  pagefault_enable () ; 
 int /*<<< orphan*/  pmd_off_k (unsigned long) ; 
 int /*<<< orphan*/  preempt_disable () ; 
 int /*<<< orphan*/  preempt_enable () ; 
 int /*<<< orphan*/ * pte_offset_kernel (int /*<<< orphan*/ ,unsigned long) ; 
 int /*<<< orphan*/  set_pte (int /*<<< orphan*/ *,unsigned long) ; 
 int smp_processor_id () ; 

void *kmap(struct page *page)
{
	unsigned long vaddr;
	might_sleep();
	if (!PageHighMem(page))
		return page_address(page);
	vaddr = (unsigned long)kmap_high(page);
	return (void *)vaddr;
}

void kunmap(struct page *page)
{
	BUG_ON(in_interrupt());
	if (!PageHighMem(page))
		return;
	kunmap_high(page);
}

void *kmap_atomic(struct page *page)
{
	unsigned int idx;
	unsigned long vaddr, pte;
	int type;
	pte_t *ptep;

	preempt_disable();
	pagefault_disable();
	if (!PageHighMem(page))
		return page_address(page);

	type = kmap_atomic_idx_push();

	idx = type + KM_TYPE_NR * smp_processor_id();
	vaddr = __fix_to_virt(FIX_KMAP_BEGIN + idx);
	pte = (page_to_pfn(page) << PAGE_SHIFT) | (PAGE_KERNEL);
	ptep = pte_offset_kernel(pmd_off_k(vaddr), vaddr);
	set_pte(ptep, pte);

	__nds32__tlbop_inv(vaddr);
	__nds32__mtsr_dsb(vaddr, NDS32_SR_TLB_VPN);
	__nds32__tlbop_rwr(pte);
	__nds32__isb();
	return (void *)vaddr;
}

void __kunmap_atomic(void *kvaddr)
{
	if (kvaddr >= (void *)FIXADDR_START) {
		unsigned long vaddr = (unsigned long)kvaddr;
		pte_t *ptep;
		kmap_atomic_idx_pop();
		__nds32__tlbop_inv(vaddr);
		__nds32__isb();
		ptep = pte_offset_kernel(pmd_off_k(vaddr), vaddr);
		set_pte(ptep, 0);
	}
	pagefault_enable();
	preempt_enable();
}

