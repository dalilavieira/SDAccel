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
struct vm_area_struct {int vm_flags; } ;
struct page {int /*<<< orphan*/  flags; } ;
struct mm_struct {int dummy; } ;
struct flusher_data {unsigned long addr1; unsigned long addr2; struct vm_area_struct* vma; } ;
struct cache_info {int alias_mask; int n_aliases; } ;
typedef  int /*<<< orphan*/  pte_t ;
struct TYPE_3__ {scalar_t__ n_aliases; } ;
struct TYPE_4__ {TYPE_1__ dcache; } ;

/* Variables and functions */
 unsigned long PAGE_MASK ; 
 int PAGE_SHIFT ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 int /*<<< orphan*/  PG_dcache_clean ; 
 int VM_EXEC ; 
 int /*<<< orphan*/  __flush_purge_region (void*,int /*<<< orphan*/ ) ; 
 TYPE_2__ boot_cpu_data ; 
 int /*<<< orphan*/  clear_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  clear_page (void*) ; 
 int /*<<< orphan*/  copy_page (void*,void*) ; 
 void flush_cache_page (struct vm_area_struct*,unsigned long,unsigned long) ; 
 void* kmap_atomic (struct page*) ; 
 void* kmap_coherent (struct page*,unsigned long) ; 
 int /*<<< orphan*/  kunmap_atomic (void*) ; 
 int /*<<< orphan*/  kunmap_coherent (void*) ; 
 void local_flush_cache_all (void*) ; 
 void local_flush_cache_dup_mm (void*) ; 
 void local_flush_cache_mm (void*) ; 
 void local_flush_cache_page (void*) ; 
 void local_flush_cache_range (void*) ; 
 void local_flush_cache_sigtramp (void*) ; 
 void local_flush_dcache_page (void*) ; 
 void local_flush_icache_page (void*) ; 
 void local_flush_icache_range (void*) ; 
 int /*<<< orphan*/  memcpy (void*,void const*,unsigned long) ; 
 void* page_address (struct page*) ; 
 scalar_t__ page_mapcount (struct page*) ; 
 unsigned long page_to_pfn (struct page*) ; 
 scalar_t__ pages_do_alias (unsigned long,unsigned long) ; 
 struct page* pfn_to_page (unsigned long) ; 
 scalar_t__ pfn_valid (unsigned long) ; 
 int /*<<< orphan*/  preempt_disable () ; 
 int /*<<< orphan*/  preempt_enable () ; 
 unsigned long pte_pfn (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  smp_wmb () ; 
 int /*<<< orphan*/  test_and_set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void noop__flush_region(void *start, int size)
{
}

__attribute__((used)) static inline void cacheop_on_each_cpu(void (*func) (void *info), void *info,
                                   int wait)
{
	preempt_disable();

	/* Needing IPI for cross-core flush is SHX3-specific. */
#ifdef CONFIG_CPU_SHX3
	/*
	 * It's possible that this gets called early on when IRQs are
	 * still disabled due to ioremapping by the boot CPU, so don't
	 * even attempt IPIs unless there are other CPUs online.
	 */
	if (num_online_cpus() > 1)
		smp_call_function(func, info, wait);
#endif

	func(info);

	preempt_enable();
}

void copy_to_user_page(struct vm_area_struct *vma, struct page *page,
		       unsigned long vaddr, void *dst, const void *src,
		       unsigned long len)
{
	if (boot_cpu_data.dcache.n_aliases && page_mapcount(page) &&
	    test_bit(PG_dcache_clean, &page->flags)) {
		void *vto = kmap_coherent(page, vaddr) + (vaddr & ~PAGE_MASK);
		memcpy(vto, src, len);
		kunmap_coherent(vto);
	} else {
		memcpy(dst, src, len);
		if (boot_cpu_data.dcache.n_aliases)
			clear_bit(PG_dcache_clean, &page->flags);
	}

	if (vma->vm_flags & VM_EXEC)
		flush_cache_page(vma, vaddr, page_to_pfn(page));
}

void copy_from_user_page(struct vm_area_struct *vma, struct page *page,
			 unsigned long vaddr, void *dst, const void *src,
			 unsigned long len)
{
	if (boot_cpu_data.dcache.n_aliases && page_mapcount(page) &&
	    test_bit(PG_dcache_clean, &page->flags)) {
		void *vfrom = kmap_coherent(page, vaddr) + (vaddr & ~PAGE_MASK);
		memcpy(dst, vfrom, len);
		kunmap_coherent(vfrom);
	} else {
		memcpy(dst, src, len);
		if (boot_cpu_data.dcache.n_aliases)
			clear_bit(PG_dcache_clean, &page->flags);
	}
}

void copy_user_highpage(struct page *to, struct page *from,
			unsigned long vaddr, struct vm_area_struct *vma)
{
	void *vfrom, *vto;

	vto = kmap_atomic(to);

	if (boot_cpu_data.dcache.n_aliases && page_mapcount(from) &&
	    test_bit(PG_dcache_clean, &from->flags)) {
		vfrom = kmap_coherent(from, vaddr);
		copy_page(vto, vfrom);
		kunmap_coherent(vfrom);
	} else {
		vfrom = kmap_atomic(from);
		copy_page(vto, vfrom);
		kunmap_atomic(vfrom);
	}

	if (pages_do_alias((unsigned long)vto, vaddr & PAGE_MASK) ||
	    (vma->vm_flags & VM_EXEC))
		__flush_purge_region(vto, PAGE_SIZE);

	kunmap_atomic(vto);
	/* Make sure this page is cleared on other CPU's too before using it */
	smp_wmb();
}

void clear_user_highpage(struct page *page, unsigned long vaddr)
{
	void *kaddr = kmap_atomic(page);

	clear_page(kaddr);

	if (pages_do_alias((unsigned long)kaddr, vaddr & PAGE_MASK))
		__flush_purge_region(kaddr, PAGE_SIZE);

	kunmap_atomic(kaddr);
}

void __update_cache(struct vm_area_struct *vma,
		    unsigned long address, pte_t pte)
{
	struct page *page;
	unsigned long pfn = pte_pfn(pte);

	if (!boot_cpu_data.dcache.n_aliases)
		return;

	page = pfn_to_page(pfn);
	if (pfn_valid(pfn)) {
		int dirty = !test_and_set_bit(PG_dcache_clean, &page->flags);
		if (dirty)
			__flush_purge_region(page_address(page), PAGE_SIZE);
	}
}

void __flush_anon_page(struct page *page, unsigned long vmaddr)
{
	unsigned long addr = (unsigned long) page_address(page);

	if (pages_do_alias(addr, vmaddr)) {
		if (boot_cpu_data.dcache.n_aliases && page_mapcount(page) &&
		    test_bit(PG_dcache_clean, &page->flags)) {
			void *kaddr;

			kaddr = kmap_coherent(page, vmaddr);
			/* XXX.. For now kunmap_coherent() does a purge */
			/* __flush_purge_region((void *)kaddr, PAGE_SIZE); */
			kunmap_coherent(kaddr);
		} else
			__flush_purge_region((void *)addr, PAGE_SIZE);
	}
}

void flush_cache_all(void)
{
	cacheop_on_each_cpu(local_flush_cache_all, NULL, 1);
}

void flush_cache_mm(struct mm_struct *mm)
{
	if (boot_cpu_data.dcache.n_aliases == 0)
		return;

	cacheop_on_each_cpu(local_flush_cache_mm, mm, 1);
}

void flush_cache_dup_mm(struct mm_struct *mm)
{
	if (boot_cpu_data.dcache.n_aliases == 0)
		return;

	cacheop_on_each_cpu(local_flush_cache_dup_mm, mm, 1);
}

void flush_cache_page(struct vm_area_struct *vma, unsigned long addr,
		      unsigned long pfn)
{
	struct flusher_data data;

	data.vma = vma;
	data.addr1 = addr;
	data.addr2 = pfn;

	cacheop_on_each_cpu(local_flush_cache_page, (void *)&data, 1);
}

void flush_cache_range(struct vm_area_struct *vma, unsigned long start,
		       unsigned long end)
{
	struct flusher_data data;

	data.vma = vma;
	data.addr1 = start;
	data.addr2 = end;

	cacheop_on_each_cpu(local_flush_cache_range, (void *)&data, 1);
}

void flush_dcache_page(struct page *page)
{
	cacheop_on_each_cpu(local_flush_dcache_page, page, 1);
}

void flush_icache_range(unsigned long start, unsigned long end)
{
	struct flusher_data data;

	data.vma = NULL;
	data.addr1 = start;
	data.addr2 = end;

	cacheop_on_each_cpu(local_flush_icache_range, (void *)&data, 1);
}

void flush_icache_page(struct vm_area_struct *vma, struct page *page)
{
	/* Nothing uses the VMA, so just pass the struct page along */
	cacheop_on_each_cpu(local_flush_icache_page, page, 1);
}

void flush_cache_sigtramp(unsigned long address)
{
	cacheop_on_each_cpu(local_flush_cache_sigtramp, (void *)address, 1);
}

__attribute__((used)) static void compute_alias(struct cache_info *c)
{
#ifdef CONFIG_MMU
	c->alias_mask = ((c->sets - 1) << c->entry_shift) & ~(PAGE_SIZE - 1);
#else
	c->alias_mask = 0;
#endif
	c->n_aliases = c->alias_mask ? (c->alias_mask >> PAGE_SHIFT) + 1 : 0;
}

