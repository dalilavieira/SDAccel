#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int vm_size_t ;
typedef  scalar_t__ vm_offset_t ;
typedef  scalar_t__ vm_address_t ;
typedef  int uint64_t ;
struct TYPE_3__ {scalar_t__ physBase; scalar_t__ topOfKernelData; scalar_t__ virtBase; int memSize; } ;
typedef  TYPE_1__ boot_args ;

/* Variables and functions */
 int /*<<< orphan*/  AP_RONA ; 
 int /*<<< orphan*/  AP_RWNA ; 
 uintptr_t ARM_PGBYTES ; 
 int /*<<< orphan*/  ARM_PGMASK ; 
 int ARM_PTE_AF ; 
 scalar_t__ ARM_PTE_AP (int /*<<< orphan*/ ) ; 
 int ARM_PTE_APMASK ; 
 int ARM_PTE_ATTRINDX (int /*<<< orphan*/ ) ; 
 int ARM_PTE_NX ; 
 int ARM_PTE_PNX ; 
 int ARM_PTE_SH (int /*<<< orphan*/ ) ; 
 int ARM_PTE_TYPE ; 
 int ARM_PTE_TYPE_VALID ; 
 int ARM_TTE_TABLE_MASK ; 
 int ARM_TTE_TYPE_MASK ; 
 int ARM_TTE_TYPE_TABLE ; 
 int ARM_TTE_VALID ; 
 scalar_t__ ARM_TT_L1_INDEX_MASK ; 
 scalar_t__ ARM_TT_L1_SHIFT ; 
 scalar_t__ ARM_TT_L2_INDEX_MASK ; 
 scalar_t__ ARM_TT_L2_SHIFT ; 
 scalar_t__ ARM_TT_L3_INDEX_MASK ; 
 scalar_t__ ARM_TT_L3_SHIFT ; 
 int /*<<< orphan*/  CACHE_ATTRINDX_DEFAULT ; 
 scalar_t__ KASAN_SHADOW_MAX ; 
 scalar_t__ KASAN_SHADOW_MIN ; 
 scalar_t__ SHADOW_FOR_ADDRESS (scalar_t__) ; 
 int /*<<< orphan*/  SH_OUTER_MEMORY ; 
 int STOLEN_MEM_BYTES ; 
 int STOLEN_MEM_PERCENT ; 
 int /*<<< orphan*/  _mh_execute_header ; 
 int /*<<< orphan*/  assert (int) ; 
 int bcmp (void const*,void const*,size_t) ; 
 void bcopy (void const*,void*,size_t) ; 
 scalar_t__ bootstrap_pgtable_phys ; 
 void bzero (void*,size_t) ; 
 int* cpu_tte ; 
 int /*<<< orphan*/  excepstack ; 
 int /*<<< orphan*/  excepstack_top ; 
 int /*<<< orphan*/  flush_mmu_tlb () ; 
 int /*<<< orphan*/  intstack ; 
 int /*<<< orphan*/  intstack_top ; 
 scalar_t__ kernel_vbase ; 
 scalar_t__ kernel_vtop ; 
 int memcmp (void const*,void const*,size_t) ; 
 void* memcpy (void*,void const*,size_t) ; 
 void* memmove (void*,void const*,size_t) ; 
 void* memset (void*,int,size_t) ; 
 int /*<<< orphan*/  panic (char*) ; 
 scalar_t__ physmap_vtop ; 
 scalar_t__ phystokv (int) ; 
 long shadow_pages_total ; 
 int /*<<< orphan*/  shadow_pages_used ; 
 uintptr_t shadow_pbase ; 
 uintptr_t shadow_pnext ; 
 uintptr_t shadow_ptop ; 
 size_t strlcat (char*,char const*,size_t) ; 
 size_t strlcpy (char*,char const*,size_t) ; 
 size_t strlen (char const*) ; 
 char* strncat (char*,char const*,size_t) ; 
 char* strncpy (char*,char const*,size_t) ; 
 size_t strnlen (char const*,size_t) ; 
 scalar_t__ vm_map_round_page (scalar_t__,int /*<<< orphan*/ ) ; 
 void* vm_map_trunc_page (uintptr_t,int /*<<< orphan*/ ) ; 
 uintptr_t zero_page_phys ; 

__attribute__((used)) static inline void *__nosan_memcpy(void *dst, const void *src, size_t sz)   { return memcpy(dst, src, sz); }

__attribute__((used)) static inline void *__nosan_memset(void *src, int c, size_t sz)             { return memset(src, c, sz); }

__attribute__((used)) static inline void *__nosan_memmove(void *src, const void *dst, size_t sz)  { return memmove(src, dst, sz); }

__attribute__((used)) static inline int   __nosan_bcmp(const void *a, const void *b, size_t sz)   { return bcmp(a, b, sz); }

__attribute__((used)) static inline void  __nosan_bcopy(const void *src, void *dst, size_t sz)    { return bcopy(src, dst, sz); }

__attribute__((used)) static inline int   __nosan_memcmp(const void *a, const void *b, size_t sz) { return memcmp(a, b, sz); }

__attribute__((used)) static inline void  __nosan_bzero(void *dst, size_t sz)                     { return bzero(dst, sz); }

__attribute__((used)) static inline size_t __nosan_strlcpy(char *dst, const char *src, size_t sz) { return strlcpy(dst, src, sz); }

__attribute__((used)) static inline char  *__nosan_strncpy(char *dst, const char *src, size_t sz) { return strncpy(dst, src, sz); }

__attribute__((used)) static inline size_t __nosan_strlcat(char *dst, const char *src, size_t sz) { return strlcat(dst, src, sz); }

__attribute__((used)) static inline char  *__nosan_strncat(char *dst, const char *src, size_t sz) { return strncat(dst, src, sz); }

__attribute__((used)) static inline size_t __nosan_strnlen(const char *src, size_t sz)            { return strnlen(src, sz); }

__attribute__((used)) static inline size_t __nosan_strlen(const char *src)                        { return strlen(src); }

__attribute__((used)) static uintptr_t
alloc_page(void)
{
	if (shadow_pnext + ARM_PGBYTES >= shadow_ptop) {
		panic("KASAN: OOM");
	}

	uintptr_t mem = shadow_pnext;
	shadow_pnext += ARM_PGBYTES;
	shadow_pages_used++;

	return mem;
}

__attribute__((used)) static uintptr_t
alloc_zero_page(void)
{
	uintptr_t mem = alloc_page();
	__nosan_bzero((void *)phystokv(mem), ARM_PGBYTES);
	return mem;
}

__attribute__((used)) static void
align_to_page(vm_offset_t *addrp, vm_offset_t *sizep)
{
	vm_offset_t addr_aligned = vm_map_trunc_page(*addrp, ARM_PGMASK);
	*sizep = vm_map_round_page(*sizep + (*addrp - addr_aligned), ARM_PGMASK);
	*addrp = addr_aligned;
}

__attribute__((used)) static void
kasan_map_shadow_internal(vm_offset_t address, vm_size_t size, bool is_zero, bool back_page)
{
	size = (size + 0x7UL) & ~0x7UL;
	vm_offset_t shadow_base = vm_map_trunc_page(SHADOW_FOR_ADDRESS(address), ARM_PGMASK);
	vm_offset_t shadow_top = vm_map_round_page(SHADOW_FOR_ADDRESS(address + size), ARM_PGMASK);

	assert(shadow_base >= KASAN_SHADOW_MIN && shadow_top <= KASAN_SHADOW_MAX);
	assert((size & 0x7) == 0);

	for (; shadow_base < shadow_top; shadow_base += ARM_PGBYTES) {
		uint64_t *base = cpu_tte;
		uint64_t *pte;

#if !__ARM64_TWO_LEVEL_PMAP__
		/* lookup L1 entry */
		pte = base + ((shadow_base & ARM_TT_L1_INDEX_MASK) >> ARM_TT_L1_SHIFT);
		if (*pte & ARM_TTE_VALID) {
			assert((*pte & ARM_TTE_TYPE_MASK) == ARM_TTE_TYPE_TABLE);
		} else {
			/* create new L1 table */
			*pte = ((uint64_t)alloc_zero_page() & ARM_TTE_TABLE_MASK) | ARM_TTE_VALID | ARM_TTE_TYPE_TABLE;
		}
		base = (uint64_t *)phystokv(*pte & ARM_TTE_TABLE_MASK);
#endif

		/* lookup L2 entry */
		pte = base + ((shadow_base & ARM_TT_L2_INDEX_MASK) >> ARM_TT_L2_SHIFT);
		if (*pte & ARM_TTE_VALID) {
			assert((*pte & ARM_TTE_TYPE_MASK) == ARM_TTE_TYPE_TABLE);
		} else {
			/* create new L3 table */
			*pte = ((uint64_t)alloc_zero_page() & ARM_TTE_TABLE_MASK) | ARM_TTE_VALID | ARM_TTE_TYPE_TABLE;
		}
		base = (uint64_t *)phystokv(*pte & ARM_TTE_TABLE_MASK);

		if (!back_page) {
			continue;
		}

		/* lookup L3 entry */
		pte = base + ((shadow_base & ARM_TT_L3_INDEX_MASK) >> ARM_TT_L3_SHIFT);
		if ((*pte & ARM_PTE_TYPE_VALID) &&
		    ((((*pte) & ARM_PTE_APMASK) != ARM_PTE_AP(AP_RONA)) || is_zero)) {
			/* nothing to do - page already mapped and we are not
			 * upgrading */
		} else {
			/* create new L3 entry */
			uint64_t newpte;
			if (is_zero) {
				/* map the zero page RO */
				newpte = (uint64_t)zero_page_phys | ARM_PTE_AP(AP_RONA);
			} else {
				/* map a fresh page RW */
				newpte = (uint64_t)alloc_zero_page() | ARM_PTE_AP(AP_RWNA);
			}
			newpte |= ARM_PTE_TYPE_VALID
				| ARM_PTE_AF
				| ARM_PTE_SH(SH_OUTER_MEMORY)
				| ARM_PTE_ATTRINDX(CACHE_ATTRINDX_DEFAULT)
				| ARM_PTE_NX
				| ARM_PTE_PNX;
			*pte = newpte;
		}
	}

	flush_mmu_tlb();
}

void
kasan_map_shadow(vm_offset_t address, vm_size_t size, bool is_zero)
{
	kasan_map_shadow_internal(address, size, is_zero, true);
}

__attribute__((used)) static void
kasan_map_shadow_early(vm_offset_t address, vm_size_t size, bool is_zero)
{
	align_to_page(&address, &size);

	vm_size_t j;
	uint64_t *pte;

	for (j = 0; j < size; j += ARM_PGBYTES) {
		vm_offset_t virt_shadow_target = (vm_offset_t)SHADOW_FOR_ADDRESS(address + j);

		assert(virt_shadow_target >= KASAN_SHADOW_MIN);
		assert(virt_shadow_target < KASAN_SHADOW_MAX);

		uint64_t *base = (uint64_t *)bootstrap_pgtable_phys;

#if !__ARM64_TWO_LEVEL_PMAP__
		/* lookup L1 entry */
		pte = base + ((virt_shadow_target & ARM_TT_L1_INDEX_MASK) >> ARM_TT_L1_SHIFT);
		if (*pte & ARM_TTE_VALID) {
			assert((*pte & ARM_TTE_TYPE_MASK) == ARM_TTE_TYPE_TABLE);
		} else {
			/* create new L1 table */
			vm_address_t pg = alloc_page();
			__nosan_bzero((void *)pg, ARM_PGBYTES);
			*pte = ((uint64_t)pg & ARM_TTE_TABLE_MASK) | ARM_TTE_VALID | ARM_TTE_TYPE_TABLE;
		}
		base = (uint64_t *)(*pte & ARM_TTE_TABLE_MASK);
#endif

		/* lookup L2 entry */
		pte = base + ((virt_shadow_target & ARM_TT_L2_INDEX_MASK) >> ARM_TT_L2_SHIFT);
		if (*pte & ARM_TTE_VALID) {
			assert((*pte & ARM_TTE_TYPE_MASK) == ARM_TTE_TYPE_TABLE);
		} else {
			/* create new L3 table */
			vm_address_t pg = alloc_page();
			__nosan_bzero((void *)pg, ARM_PGBYTES);
			*pte = ((uint64_t)pg & ARM_TTE_TABLE_MASK) | ARM_TTE_VALID | ARM_TTE_TYPE_TABLE;
		}
		base = (uint64_t *)(*pte & ARM_TTE_TABLE_MASK);

		/* lookup L3 entry */
		pte = base + ((virt_shadow_target & ARM_TT_L3_INDEX_MASK) >> ARM_TT_L3_SHIFT);

		if ((*pte & (ARM_PTE_TYPE|ARM_PTE_APMASK)) == (ARM_PTE_TYPE_VALID|ARM_PTE_AP(AP_RWNA))) {
			/* L3 entry valid and mapped RW - do nothing */
		} else {
			/* Not mapped, or mapped RO - create new L3 entry or upgrade to RW */

			uint64_t newpte;
			if (is_zero) {
				/* map the zero page RO */
				newpte = (uint64_t)zero_page_phys | ARM_PTE_AP(AP_RONA);
			} else {
				/* map a fresh page RW */
				vm_address_t pg = alloc_page();
				__nosan_bzero((void *)pg, ARM_PGBYTES);
				newpte = pg | ARM_PTE_AP(AP_RWNA);
			}

			/* add the default attributes */
			newpte |= ARM_PTE_TYPE_VALID
				| ARM_PTE_AF
				| ARM_PTE_SH(SH_OUTER_MEMORY)
				| ARM_PTE_ATTRINDX(CACHE_ATTRINDX_DEFAULT)
				| ARM_PTE_NX
				| ARM_PTE_PNX;

			*pte = newpte;
		}
	}

	flush_mmu_tlb();
}

void
kasan_arch_init(void)
{
	/* Map the physical aperture */
	kasan_map_shadow(kernel_vtop, physmap_vtop - kernel_vtop, true);

#if defined(KERNEL_INTEGRITY_KTRR)
	/* Pre-allocate all the L3 page table pages to avoid triggering KTRR */
	kasan_map_shadow_internal(VM_MIN_KERNEL_ADDRESS, VM_MAX_KERNEL_ADDRESS - VM_MIN_KERNEL_ADDRESS + 1, false, false);
#endif
}

void
kasan_bootstrap(boot_args *args, vm_offset_t pgtable)
{
	uintptr_t tosteal;

	vm_address_t pbase = args->physBase;
	vm_address_t ptop = args->topOfKernelData;
	vm_offset_t extra = (vm_offset_t)&_mh_execute_header - pbase;

	kernel_vbase = args->virtBase;
	kernel_vtop = args->virtBase + ptop - pbase;

	tosteal = (args->memSize * STOLEN_MEM_PERCENT) / 100 + STOLEN_MEM_BYTES;
	tosteal = vm_map_trunc_page(tosteal, ARM_PGMASK);

	args->memSize -= tosteal;

	/* Initialize the page allocator */
	shadow_pbase = vm_map_round_page(pbase + args->memSize, ARM_PGMASK);
	shadow_ptop = shadow_pbase + tosteal;
	shadow_pnext = shadow_pbase;
	shadow_pages_total = (long)((shadow_ptop - shadow_pbase) / ARM_PGBYTES);

	/* Set aside a page of zeros we can use for dummy shadow mappings */
	zero_page_phys = alloc_page();
	__nosan_bzero((void *)zero_page_phys, ARM_PGBYTES);

	/* Shadow the KVA bootstrap mapping: start of kernel Mach-O to end of physical */
	bootstrap_pgtable_phys = pgtable;
	kasan_map_shadow_early(kernel_vbase + extra, args->memSize - extra, true);

	/* Shadow the early stacks */
	vm_offset_t p2v = args->virtBase - args->physBase;

	vm_offset_t intstack_virt = (vm_offset_t)&intstack + p2v;
	vm_offset_t excepstack_virt = (vm_offset_t)&excepstack + p2v;
	vm_offset_t intstack_size = (vm_offset_t)&intstack_top - (vm_offset_t)&intstack;
	vm_offset_t excepstack_size = (vm_offset_t)&excepstack_top - (vm_offset_t)&excepstack;

	kasan_map_shadow_early(intstack_virt, intstack_size, false);
	kasan_map_shadow_early(excepstack_virt, excepstack_size, false);
}

