#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_7__ ;
typedef  struct TYPE_13__   TYPE_6__ ;
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct vm_area_struct {int vm_flags; struct mm_struct* vm_mm; } ;
struct page {int /*<<< orphan*/  flags; } ;
struct mm_struct {int dummy; } ;
struct flusher_data {unsigned long addr1; unsigned long addr2; struct vm_area_struct* vma; } ;
struct cache_info {scalar_t__ n_aliases; int ways; unsigned long way_incr; } ;
struct address_space {int dummy; } ;
typedef  int /*<<< orphan*/  pud_t ;
typedef  int /*<<< orphan*/  pte_t ;
typedef  int /*<<< orphan*/  pmd_t ;
typedef  int /*<<< orphan*/  pgd_t ;
struct TYPE_8__ {int n_aliases; } ;
struct TYPE_14__ {int flags; struct cache_info dcache; TYPE_1__ icache; } ;
struct TYPE_9__ {unsigned long entry_mask; int ways; scalar_t__ way_incr; } ;
struct TYPE_13__ {TYPE_2__ icache; } ;
struct TYPE_12__ {struct mm_struct* active_mm; } ;
struct TYPE_10__ {unsigned long sets; unsigned long entry_shift; unsigned long ways; scalar_t__ n_aliases; } ;
struct TYPE_11__ {TYPE_3__ dcache; } ;

/* Variables and functions */
 unsigned long CACHE_IC_ADDRESS_ARRAY ; 
 unsigned long CACHE_OC_ADDRESS_ARRAY ; 
 unsigned long CCR_CACHE_ICI ; 
 int CPU_HAS_P2_FLUSH_BUG ; 
 int L1_CACHE_BYTES ; 
 unsigned long MAX_ICACHE_PAGES ; 
 scalar_t__ NO_CONTEXT ; 
 unsigned long PAGE_MASK ; 
 unsigned long PAGE_SHIFT ; 
 int PAGE_SIZE ; 
 int /*<<< orphan*/  PG_dcache_clean ; 
 unsigned long SH_CCR ; 
 int VM_EXEC ; 
 int _PAGE_PRESENT ; 
static  void __flush_cache_one (unsigned long,unsigned long,unsigned long) ; 
 int /*<<< orphan*/  __ocbwb (unsigned long) ; 
 unsigned long __raw_readl (unsigned long) ; 
 int /*<<< orphan*/  __raw_writel (unsigned long,unsigned long) ; 
 int /*<<< orphan*/  back_to_cached () ; 
 TYPE_7__ boot_cpu_data ; 
 unsigned long cached_to_uncached ; 
 int /*<<< orphan*/  clear_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ cpu_context (int /*<<< orphan*/ ,struct mm_struct*) ; 
 TYPE_6__* cpu_data ; 
 TYPE_5__* current ; 
 TYPE_4__ current_cpu_data ; 
 int /*<<< orphan*/  jump_to_uncached () ; 
 void* kmap_atomic (struct page*) ; 
 void* kmap_coherent (struct page*,unsigned long) ; 
 int /*<<< orphan*/  kunmap_atomic (void*) ; 
 int /*<<< orphan*/  kunmap_coherent (void*) ; 
 int /*<<< orphan*/  local_flush_cache_all (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 int /*<<< orphan*/  mapping_mapped (struct address_space*) ; 
 scalar_t__ page_address (struct page*) ; 
 scalar_t__ page_mapcount (struct page*) ; 
 struct address_space* page_mapping_file (struct page*) ; 
 unsigned long page_to_phys (struct page*) ; 
 struct page* pfn_to_page (unsigned long) ; 
 int /*<<< orphan*/ * pgd_offset (struct mm_struct*,unsigned long) ; 
 int /*<<< orphan*/ * pmd_offset (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/ * pte_offset_kernel (int /*<<< orphan*/ *,unsigned long) ; 
 int pte_val (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * pud_offset (int /*<<< orphan*/ *,unsigned long) ; 
 unsigned long shm_align_mask ; 
 int /*<<< orphan*/  smp_processor_id () ; 
 scalar_t__ test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  wmb () ; 

__attribute__((used)) static void sh4_flush_icache_range(void *args)
{
	struct flusher_data *data = args;
	unsigned long start, end;
	unsigned long flags, v;
	int i;

	start = data->addr1;
	end = data->addr2;

	/* If there are too many pages then just blow away the caches */
	if (((end - start) >> PAGE_SHIFT) >= MAX_ICACHE_PAGES) {
		local_flush_cache_all(NULL);
		return;
	}

	/*
	 * Selectively flush d-cache then invalidate the i-cache.
	 * This is inefficient, so only use this for small ranges.
	 */
	start &= ~(L1_CACHE_BYTES-1);
	end += L1_CACHE_BYTES-1;
	end &= ~(L1_CACHE_BYTES-1);

	local_irq_save(flags);
	jump_to_uncached();

	for (v = start; v < end; v += L1_CACHE_BYTES) {
		unsigned long icacheaddr;
		int j, n;

		__ocbwb(v);

		icacheaddr = CACHE_IC_ADDRESS_ARRAY | (v &
				cpu_data->icache.entry_mask);

		/* Clear i-cache line valid-bit */
		n = boot_cpu_data.icache.n_aliases;
		for (i = 0; i < cpu_data->icache.ways; i++) {
			for (j = 0; j < n; j++)
				__raw_writel(0, icacheaddr + (j * PAGE_SIZE));
			icacheaddr += cpu_data->icache.way_incr;
		}
	}

	back_to_cached();
	local_irq_restore(flags);
}

__attribute__((used)) static inline void flush_cache_one(unsigned long start, unsigned long phys)
{
	unsigned long flags, exec_offset = 0;

	/*
	 * All types of SH-4 require PC to be uncached to operate on the I-cache.
	 * Some types of SH-4 require PC to be uncached to operate on the D-cache.
	 */
	if ((boot_cpu_data.flags & CPU_HAS_P2_FLUSH_BUG) ||
	    (start < CACHE_OC_ADDRESS_ARRAY))
		exec_offset = cached_to_uncached;

	local_irq_save(flags);
	__flush_cache_one(start, phys, exec_offset);
	local_irq_restore(flags);
}

__attribute__((used)) static void sh4_flush_dcache_page(void *arg)
{
	struct page *page = arg;
	unsigned long addr = (unsigned long)page_address(page);
#ifndef CONFIG_SMP
	struct address_space *mapping = page_mapping_file(page);

	if (mapping && !mapping_mapped(mapping))
		clear_bit(PG_dcache_clean, &page->flags);
	else
#endif
		flush_cache_one(CACHE_OC_ADDRESS_ARRAY |
				(addr & shm_align_mask), page_to_phys(page));

	wmb();
}

__attribute__((used)) static void flush_icache_all(void)
{
	unsigned long flags, ccr;

	local_irq_save(flags);
	jump_to_uncached();

	/* Flush I-cache */
	ccr = __raw_readl(SH_CCR);
	ccr |= CCR_CACHE_ICI;
	__raw_writel(ccr, SH_CCR);

	/*
	 * back_to_cached() will take care of the barrier for us, don't add
	 * another one!
	 */

	back_to_cached();
	local_irq_restore(flags);
}

__attribute__((used)) static void flush_dcache_all(void)
{
	unsigned long addr, end_addr, entry_offset;

	end_addr = CACHE_OC_ADDRESS_ARRAY +
		(current_cpu_data.dcache.sets <<
		 current_cpu_data.dcache.entry_shift) *
			current_cpu_data.dcache.ways;

	entry_offset = 1 << current_cpu_data.dcache.entry_shift;

	for (addr = CACHE_OC_ADDRESS_ARRAY; addr < end_addr; ) {
		__raw_writel(0, addr); addr += entry_offset;
		__raw_writel(0, addr); addr += entry_offset;
		__raw_writel(0, addr); addr += entry_offset;
		__raw_writel(0, addr); addr += entry_offset;
		__raw_writel(0, addr); addr += entry_offset;
		__raw_writel(0, addr); addr += entry_offset;
		__raw_writel(0, addr); addr += entry_offset;
		__raw_writel(0, addr); addr += entry_offset;
	}
}

__attribute__((used)) static void sh4_flush_cache_all(void *unused)
{
	flush_dcache_all();
	flush_icache_all();
}

__attribute__((used)) static void sh4_flush_cache_mm(void *arg)
{
	struct mm_struct *mm = arg;

	if (cpu_context(smp_processor_id(), mm) == NO_CONTEXT)
		return;

	flush_dcache_all();
}

__attribute__((used)) static void sh4_flush_cache_page(void *args)
{
	struct flusher_data *data = args;
	struct vm_area_struct *vma;
	struct page *page;
	unsigned long address, pfn, phys;
	int map_coherent = 0;
	pgd_t *pgd;
	pud_t *pud;
	pmd_t *pmd;
	pte_t *pte;
	void *vaddr;

	vma = data->vma;
	address = data->addr1 & PAGE_MASK;
	pfn = data->addr2;
	phys = pfn << PAGE_SHIFT;
	page = pfn_to_page(pfn);

	if (cpu_context(smp_processor_id(), vma->vm_mm) == NO_CONTEXT)
		return;

	pgd = pgd_offset(vma->vm_mm, address);
	pud = pud_offset(pgd, address);
	pmd = pmd_offset(pud, address);
	pte = pte_offset_kernel(pmd, address);

	/* If the page isn't present, there is nothing to do here. */
	if (!(pte_val(*pte) & _PAGE_PRESENT))
		return;

	if ((vma->vm_mm == current->active_mm))
		vaddr = NULL;
	else {
		/*
		 * Use kmap_coherent or kmap_atomic to do flushes for
		 * another ASID than the current one.
		 */
		map_coherent = (current_cpu_data.dcache.n_aliases &&
			test_bit(PG_dcache_clean, &page->flags) &&
			page_mapcount(page));
		if (map_coherent)
			vaddr = kmap_coherent(page, address);
		else
			vaddr = kmap_atomic(page);

		address = (unsigned long)vaddr;
	}

	flush_cache_one(CACHE_OC_ADDRESS_ARRAY |
			(address & shm_align_mask), phys);

	if (vma->vm_flags & VM_EXEC)
		flush_icache_all();

	if (vaddr) {
		if (map_coherent)
			kunmap_coherent(vaddr);
		else
			kunmap_atomic(vaddr);
	}
}

__attribute__((used)) static void sh4_flush_cache_range(void *args)
{
	struct flusher_data *data = args;
	struct vm_area_struct *vma;
	unsigned long start, end;

	vma = data->vma;
	start = data->addr1;
	end = data->addr2;

	if (cpu_context(smp_processor_id(), vma->vm_mm) == NO_CONTEXT)
		return;

	/*
	 * If cache is only 4k-per-way, there are never any 'aliases'.  Since
	 * the cache is physically tagged, the data can just be left in there.
	 */
	if (boot_cpu_data.dcache.n_aliases == 0)
		return;

	flush_dcache_all();

	if (vma->vm_flags & VM_EXEC)
		flush_icache_all();
}

__attribute__((used)) static void __flush_cache_one(unsigned long addr, unsigned long phys,
			       unsigned long exec_offset)
{
	int way_count;
	unsigned long base_addr = addr;
	struct cache_info *dcache;
	unsigned long way_incr;
	unsigned long a, ea, p;
	unsigned long temp_pc;

	dcache = &boot_cpu_data.dcache;
	/* Write this way for better assembly. */
	way_count = dcache->ways;
	way_incr = dcache->way_incr;

	/*
	 * Apply exec_offset (i.e. branch to P2 if required.).
	 *
	 * FIXME:
	 *
	 *	If I write "=r" for the (temp_pc), it puts this in r6 hence
	 *	trashing exec_offset before it's been added on - why?  Hence
	 *	"=&r" as a 'workaround'
	 */
	asm volatile("mov.l 1f, %0\n\t"
		     "add   %1, %0\n\t"
		     "jmp   @%0\n\t"
		     "nop\n\t"
		     ".balign 4\n\t"
		     "1:  .long 2f\n\t"
		     "2:\n" : "=&r" (temp_pc) : "r" (exec_offset));

	/*
	 * We know there will be >=1 iteration, so write as do-while to avoid
	 * pointless nead-of-loop check for 0 iterations.
	 */
	do {
		ea = base_addr + PAGE_SIZE;
		a = base_addr;
		p = phys;

		do {
			*(volatile unsigned long *)a = p;
			/*
			 * Next line: intentionally not p+32, saves an add, p
			 * will do since only the cache tag bits need to
			 * match.
			 */
			*(volatile unsigned long *)(a+32) = p;
			a += 64;
			p += 64;
		} while (a < ea);

		base_addr += way_incr;
	} while (--way_count != 0);
}

