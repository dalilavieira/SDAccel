#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_5__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct vm_area_struct {int vm_start; unsigned long vm_end; int vm_flags; int /*<<< orphan*/  vm_page_prot; } ;
struct page {int /*<<< orphan*/  flags; } ;
struct mm_struct {int dummy; } ;
typedef  int /*<<< orphan*/  pte_t ;
struct TYPE_6__ {int rbs_bot; } ;
struct TYPE_9__ {int personality; TYPE_2__* mm; TYPE_1__ thread; } ;
struct TYPE_8__ {unsigned long unimpl_va_mask; } ;
struct TYPE_7__ {unsigned long start_stack; int /*<<< orphan*/  mmap_sem; } ;

/* Variables and functions */
 unsigned long FIXADDR_USER_END ; 
 unsigned long FIXADDR_USER_START ; 
 unsigned long MAX_USER_STACK_SIZE ; 
 int MMAP_PAGE_ZERO ; 
 void* PAGE_ALIGN (unsigned long) ; 
 int PAGE_MASK ; 
 int /*<<< orphan*/  PAGE_READONLY ; 
 int PAGE_SHIFT ; 
 unsigned long PAGE_SIZE ; 
 int /*<<< orphan*/  PG_arch_1 ; 
 int /*<<< orphan*/  RLIMIT_STACK ; 
 int VM_ACCOUNT ; 
 int VM_DATA_DEFAULT_FLAGS ; 
 int VM_DONTDUMP ; 
 int VM_DONTEXPAND ; 
 int VM_GROWSUP ; 
 int VM_IO ; 
 int VM_MAYREAD ; 
 int VM_READ ; 
 int _PAGE_MA_NAT ; 
 int /*<<< orphan*/  __init_begin ; 
 int /*<<< orphan*/  __init_end ; 
 int /*<<< orphan*/  __pgprot (int) ; 
 unsigned long compound_order (struct page*) ; 
 TYPE_5__* current ; 
 int /*<<< orphan*/  down_write (int /*<<< orphan*/ *) ; 
 unsigned long ffz (unsigned long) ; 
 int /*<<< orphan*/  flush_icache_range (unsigned long,unsigned long) ; 
 int /*<<< orphan*/  free_reserved_area (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,char*) ; 
 struct vm_area_struct gate_vma ; 
 int /*<<< orphan*/  ia64_imva (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ia64_set_pta (unsigned long) ; 
 int /*<<< orphan*/  ia64_tlb_init () ; 
 scalar_t__ insert_vm_struct (TYPE_2__*,struct vm_area_struct*) ; 
 TYPE_3__* local_cpu_data ; 
 scalar_t__ page_address (struct page*) ; 
 int /*<<< orphan*/  panic (char*,...) ; 
 int pgprot_val (int /*<<< orphan*/ ) ; 
 struct page* pte_page (int /*<<< orphan*/ ) ; 
 int rlimit_max (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  up_write (int /*<<< orphan*/ *) ; 
 struct page* virt_to_page (unsigned long) ; 
 struct vm_area_struct* vm_area_alloc (TYPE_2__*) ; 
 int /*<<< orphan*/  vm_area_free (struct vm_area_struct*) ; 
 int /*<<< orphan*/  vm_get_page_prot (int) ; 
 int /*<<< orphan*/  vma_set_anonymous (struct vm_area_struct*) ; 

void
__ia64_sync_icache_dcache (pte_t pte)
{
	unsigned long addr;
	struct page *page;

	page = pte_page(pte);
	addr = (unsigned long) page_address(page);

	if (test_bit(PG_arch_1, &page->flags))
		return;				/* i-cache is already coherent with d-cache */

	flush_icache_range(addr, addr + (PAGE_SIZE << compound_order(page)));
	set_bit(PG_arch_1, &page->flags);	/* mark page as clean */
}

void
dma_mark_clean(void *addr, size_t size)
{
	unsigned long pg_addr, end;

	pg_addr = PAGE_ALIGN((unsigned long) addr);
	end = (unsigned long) addr + size;
	while (pg_addr + PAGE_SIZE <= end) {
		struct page *page = virt_to_page(pg_addr);
		set_bit(PG_arch_1, &page->flags);
		pg_addr += PAGE_SIZE;
	}
}

inline void
ia64_set_rbs_bot (void)
{
	unsigned long stack_size = rlimit_max(RLIMIT_STACK) & -16;

	if (stack_size > MAX_USER_STACK_SIZE)
		stack_size = MAX_USER_STACK_SIZE;
	current->thread.rbs_bot = PAGE_ALIGN(current->mm->start_stack - stack_size);
}

void
ia64_init_addr_space (void)
{
	struct vm_area_struct *vma;

	ia64_set_rbs_bot();

	/*
	 * If we're out of memory and kmem_cache_alloc() returns NULL, we simply ignore
	 * the problem.  When the process attempts to write to the register backing store
	 * for the first time, it will get a SEGFAULT in this case.
	 */
	vma = vm_area_alloc(current->mm);
	if (vma) {
		vma_set_anonymous(vma);
		vma->vm_start = current->thread.rbs_bot & PAGE_MASK;
		vma->vm_end = vma->vm_start + PAGE_SIZE;
		vma->vm_flags = VM_DATA_DEFAULT_FLAGS|VM_GROWSUP|VM_ACCOUNT;
		vma->vm_page_prot = vm_get_page_prot(vma->vm_flags);
		down_write(&current->mm->mmap_sem);
		if (insert_vm_struct(current->mm, vma)) {
			up_write(&current->mm->mmap_sem);
			vm_area_free(vma);
			return;
		}
		up_write(&current->mm->mmap_sem);
	}

	/* map NaT-page at address zero to speed up speculative dereferencing of NULL: */
	if (!(current->personality & MMAP_PAGE_ZERO)) {
		vma = vm_area_alloc(current->mm);
		if (vma) {
			vma_set_anonymous(vma);
			vma->vm_end = PAGE_SIZE;
			vma->vm_page_prot = __pgprot(pgprot_val(PAGE_READONLY) | _PAGE_MA_NAT);
			vma->vm_flags = VM_READ | VM_MAYREAD | VM_IO |
					VM_DONTEXPAND | VM_DONTDUMP;
			down_write(&current->mm->mmap_sem);
			if (insert_vm_struct(current->mm, vma)) {
				up_write(&current->mm->mmap_sem);
				vm_area_free(vma);
				return;
			}
			up_write(&current->mm->mmap_sem);
		}
	}
}

void
free_initmem (void)
{
	free_reserved_area(ia64_imva(__init_begin), ia64_imva(__init_end),
			   -1, "unused kernel");
}

struct vm_area_struct *get_gate_vma(struct mm_struct *mm)
{
	return &gate_vma;
}

int in_gate_area_no_mm(unsigned long addr)
{
	if ((addr >= FIXADDR_USER_START) && (addr < FIXADDR_USER_END))
		return 1;
	return 0;
}

int in_gate_area(struct mm_struct *mm, unsigned long addr)
{
	return in_gate_area_no_mm(addr);
}

void ia64_mmu_init(void *my_cpu_data)
{
	unsigned long pta, impl_va_bits;
	extern void tlb_init(void);

#ifdef CONFIG_DISABLE_VHPT
#	define VHPT_ENABLE_BIT	0
#else
#	define VHPT_ENABLE_BIT	1
#endif

	/*
	 * Check if the virtually mapped linear page table (VMLPT) overlaps with a mapped
	 * address space.  The IA-64 architecture guarantees that at least 50 bits of
	 * virtual address space are implemented but if we pick a large enough page size
	 * (e.g., 64KB), the mapped address space is big enough that it will overlap with
	 * VMLPT.  I assume that once we run on machines big enough to warrant 64KB pages,
	 * IMPL_VA_MSB will be significantly bigger, so this is unlikely to become a
	 * problem in practice.  Alternatively, we could truncate the top of the mapped
	 * address space to not permit mappings that would overlap with the VMLPT.
	 * --davidm 00/12/06
	 */
#	define pte_bits			3
#	define mapped_space_bits	(3*(PAGE_SHIFT - pte_bits) + PAGE_SHIFT)
	/*
	 * The virtual page table has to cover the entire implemented address space within
	 * a region even though not all of this space may be mappable.  The reason for
	 * this is that the Access bit and Dirty bit fault handlers perform
	 * non-speculative accesses to the virtual page table, so the address range of the
	 * virtual page table itself needs to be covered by virtual page table.
	 */
#	define vmlpt_bits		(impl_va_bits - PAGE_SHIFT + pte_bits)
#	define POW2(n)			(1ULL << (n))

	impl_va_bits = ffz(~(local_cpu_data->unimpl_va_mask | (7UL << 61)));

	if (impl_va_bits < 51 || impl_va_bits > 61)
		panic("CPU has bogus IMPL_VA_MSB value of %lu!\n", impl_va_bits - 1);
	/*
	 * mapped_space_bits - PAGE_SHIFT is the total number of ptes we need,
	 * which must fit into "vmlpt_bits - pte_bits" slots. Second half of
	 * the test makes sure that our mapped space doesn't overlap the
	 * unimplemented hole in the middle of the region.
	 */
	if ((mapped_space_bits - PAGE_SHIFT > vmlpt_bits - pte_bits) ||
	    (mapped_space_bits > impl_va_bits - 1))
		panic("Cannot build a big enough virtual-linear page table"
		      " to cover mapped address space.\n"
		      " Try using a smaller page size.\n");


	/* place the VMLPT at the end of each page-table mapped region: */
	pta = POW2(61) - POW2(vmlpt_bits);

	/*
	 * Set the (virtually mapped linear) page table address.  Bit
	 * 8 selects between the short and long format, bits 2-7 the
	 * size of the table, and bit 0 whether the VHPT walker is
	 * enabled.
	 */
	ia64_set_pta(pta | (0 << 8) | (vmlpt_bits << 2) | VHPT_ENABLE_BIT);

	ia64_tlb_init();

#ifdef	CONFIG_HUGETLB_PAGE
	ia64_set_rr(HPAGE_REGION_BASE, HPAGE_SHIFT << 2);
	ia64_srlz_d();
#endif
}

