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
typedef  scalar_t__ vm_size_t ;
typedef  scalar_t__ vm_offset_t ;
typedef  scalar_t__ mach_vm_offset_t ;
typedef  scalar_t__ kern_return_t ;
typedef  scalar_t__ boolean_t ;

/* Variables and functions */
 scalar_t__ KERN_INVALID_ADDRESS ; 
 scalar_t__ KERN_SUCCESS ; 
 int VM_FLAGS_ANYWHERE ; 
 int VM_FLAGS_FIXED ; 
 int /*<<< orphan*/  VM_KERN_MEMORY_KEXT ; 
 scalar_t__ VM_MAX_KERNEL_ADDRESS ; 
 scalar_t__ VM_MIN_KERNEL_ADDRESS ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  g_kext_map ; 
 int /*<<< orphan*/  kernel_map ; 
 scalar_t__ kext_alloc_base ; 
 scalar_t__ kext_alloc_max ; 
 void kext_free (scalar_t__,scalar_t__) ; 
 scalar_t__ mach_vm_allocate_kernel (int /*<<< orphan*/ ,scalar_t__*,scalar_t__,int,int /*<<< orphan*/ ) ; 
 scalar_t__ mach_vm_deallocate (int /*<<< orphan*/ ,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  printf (char*,scalar_t__) ; 

void 
kext_alloc_init(void)
{
#if CONFIG_KEXT_BASEMENT
    kern_return_t rval = 0;
    kernel_segment_command_t *text = NULL;
    kernel_segment_command_t *prelinkTextSegment = NULL;
    mach_vm_offset_t text_end, text_start;
    mach_vm_size_t text_size;
    mach_vm_size_t kext_alloc_size;

    /* Determine the start of the kernel's __TEXT segment and determine the
     * lower bound of the allocated submap for kext allocations.
     */

    text = getsegbyname(SEG_TEXT);
    text_start = vm_map_trunc_page(text->vmaddr,
				   VM_MAP_PAGE_MASK(kernel_map));
    text_start &= ~((512ULL * 1024 * 1024 * 1024) - 1);
    text_end = vm_map_round_page(text->vmaddr + text->vmsize,
				 VM_MAP_PAGE_MASK(kernel_map));
    text_size = text_end - text_start;

    kext_alloc_base = KEXT_ALLOC_BASE(text_end);
    kext_alloc_size = KEXT_ALLOC_SIZE(text_size);
    kext_alloc_max = kext_alloc_base + kext_alloc_size;
    
    /* Post boot kext allocation will start after the prelinked kexts */
    prelinkTextSegment = getsegbyname("__PRELINK_TEXT");
    if (prelinkTextSegment) {
        /* use kext_post_boot_base to start allocations past all the prelinked 
         * kexts
         */
        kext_post_boot_base = 
		vm_map_round_page(kext_alloc_base + prelinkTextSegment->vmsize,
				  VM_MAP_PAGE_MASK(kernel_map));
    }
    else {
        kext_post_boot_base = kext_alloc_base;
    }

    /* Allocate the sub block of the kernel map */
    rval = kmem_suballoc(kernel_map, (vm_offset_t *) &kext_alloc_base, 
			 kext_alloc_size, /* pageable */ TRUE,
			 VM_FLAGS_FIXED|VM_FLAGS_OVERWRITE,
			 VM_MAP_KERNEL_FLAGS_NONE, VM_KERN_MEMORY_KEXT,
			 &g_kext_map);
    if (rval != KERN_SUCCESS) {
	    panic("kext_alloc_init: kmem_suballoc failed 0x%x\n", rval);
    }

    if ((kext_alloc_base + kext_alloc_size) > kext_alloc_max) {
        panic("kext_alloc_init: failed to get first 2GB\n");
    }

    if (kernel_map->min_offset > kext_alloc_base) {
	    kernel_map->min_offset = kext_alloc_base;
    }

    printf("kext submap [0x%lx - 0x%lx], kernel text [0x%lx - 0x%lx]\n",
	   VM_KERNEL_UNSLIDE(kext_alloc_base),
	   VM_KERNEL_UNSLIDE(kext_alloc_max),
	   VM_KERNEL_UNSLIDE(text->vmaddr),
	   VM_KERNEL_UNSLIDE(text->vmaddr + text->vmsize));

#else
    g_kext_map = kernel_map;
    kext_alloc_base = VM_MIN_KERNEL_ADDRESS;
    kext_alloc_max = VM_MAX_KERNEL_ADDRESS;
#endif /* CONFIG_KEXT_BASEMENT */
}

kern_return_t
kext_alloc(vm_offset_t *_addr, vm_size_t size, boolean_t fixed)
{
    kern_return_t rval = 0;
#if CONFIG_KEXT_BASEMENT
    mach_vm_offset_t addr = (fixed) ? *_addr : kext_post_boot_base;
#else
    mach_vm_offset_t addr = (fixed) ? *_addr : kext_alloc_base;
#endif
    int flags = (fixed) ? VM_FLAGS_FIXED : VM_FLAGS_ANYWHERE;
 
#if CONFIG_KEXT_BASEMENT
    /* Allocate the kext virtual memory
     * 10608884 - use mach_vm_map since we want VM_FLAGS_ANYWHERE allocated past
     * kext_post_boot_base (when possible).  mach_vm_allocate will always 
     * start at 0 into the map no matter what you pass in addr.  We want non 
     * fixed (post boot) kext allocations to start looking for free space 
     * just past where prelinked kexts have loaded.  
     */
    rval = mach_vm_map_kernel(g_kext_map,
                       &addr, 
                       size, 
                       0,
                       flags,
		       VM_MAP_KERNEL_FLAGS_NONE,
                       VM_KERN_MEMORY_KEXT,
                       MACH_PORT_NULL,
                       0,
                       TRUE,
                       VM_PROT_DEFAULT,
                       VM_PROT_ALL,
                       VM_INHERIT_DEFAULT);
    if (rval != KERN_SUCCESS) {
        printf("mach_vm_map failed - %d\n", rval);
        goto finish;
    }
#else
    rval = mach_vm_allocate_kernel(g_kext_map, &addr, size, flags, VM_KERN_MEMORY_KEXT);
    if (rval != KERN_SUCCESS) {
        printf("vm_allocate failed - %d\n", rval);
        goto finish;
    }
#endif

    /* Check that the memory is reachable by kernel text */
    if ((addr + size) > kext_alloc_max) {
        kext_free((vm_offset_t)addr, size);
        rval = KERN_INVALID_ADDRESS;
        goto finish;
    }

    *_addr = (vm_offset_t)addr;
    rval = KERN_SUCCESS;
#if KASAN
    kasan_notify_address(addr, size);
#endif

finish:
    return rval;
}

void 
kext_free(vm_offset_t addr, vm_size_t size)
{
    kern_return_t rval;

    rval = mach_vm_deallocate(g_kext_map, addr, size);
    assert(rval == KERN_SUCCESS);
}

