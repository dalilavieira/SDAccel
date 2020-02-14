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
typedef  int /*<<< orphan*/  u32 ;
struct vm_area_struct {scalar_t__ vm_end; scalar_t__ vm_start; int vm_flags; int /*<<< orphan*/  vm_page_prot; } ;
struct kfd_process {int dummy; } ;
struct TYPE_4__ {int doorbell_start_offset; int /*<<< orphan*/  doorbell_aperture_size; scalar_t__ doorbell_physical_address; } ;
struct kfd_dev {size_t doorbell_id_offset; scalar_t__ doorbell_kernel_ptr; TYPE_2__ shared_resources; scalar_t__ doorbell_base; TYPE_1__* device_info; } ;
typedef  int phys_addr_t ;
struct TYPE_3__ {int doorbell_size; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int ENOSPC ; 
 int KFD_MAX_NUM_OF_QUEUES_PER_PROCESS ; 
 int PAGE_SHIFT ; 
 size_t PAGE_SIZE ; 
 int VM_DONTCOPY ; 
 int VM_DONTDUMP ; 
 int VM_DONTEXPAND ; 
 int VM_IO ; 
 int VM_NORESERVE ; 
 int VM_PFNMAP ; 
 int io_remap_pfn_range (struct vm_area_struct*,scalar_t__,int,size_t,int /*<<< orphan*/ ) ; 
 scalar_t__ ioremap (scalar_t__,size_t) ; 
 int /*<<< orphan*/  iounmap (scalar_t__) ; 
 int kfd_get_process_doorbells (struct kfd_dev*,struct kfd_process*) ; 
 size_t max_doorbell_slices ; 
 int /*<<< orphan*/  pgprot_noncached (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_debug (char*,...) ; 
 size_t rounddown (int /*<<< orphan*/ ,size_t) ; 
 size_t roundup (int,size_t) ; 

__attribute__((used)) static inline void kfd_debugfs_init(void) {}

__attribute__((used)) static inline void kfd_debugfs_fini(void) {}

size_t kfd_doorbell_process_slice(struct kfd_dev *kfd)
{
	return roundup(kfd->device_info->doorbell_size *
			KFD_MAX_NUM_OF_QUEUES_PER_PROCESS,
			PAGE_SIZE);
}

int kfd_doorbell_init(struct kfd_dev *kfd)
{
	size_t doorbell_start_offset;
	size_t doorbell_aperture_size;
	size_t doorbell_process_limit;

	/*
	 * We start with calculations in bytes because the input data might
	 * only be byte-aligned.
	 * Only after we have done the rounding can we assume any alignment.
	 */

	doorbell_start_offset =
			roundup(kfd->shared_resources.doorbell_start_offset,
					kfd_doorbell_process_slice(kfd));

	doorbell_aperture_size =
			rounddown(kfd->shared_resources.doorbell_aperture_size,
					kfd_doorbell_process_slice(kfd));

	if (doorbell_aperture_size > doorbell_start_offset)
		doorbell_process_limit =
			(doorbell_aperture_size - doorbell_start_offset) /
						kfd_doorbell_process_slice(kfd);
	else
		return -ENOSPC;

	if (!max_doorbell_slices ||
	    doorbell_process_limit < max_doorbell_slices)
		max_doorbell_slices = doorbell_process_limit;

	kfd->doorbell_base = kfd->shared_resources.doorbell_physical_address +
				doorbell_start_offset;

	kfd->doorbell_id_offset = doorbell_start_offset / sizeof(u32);

	kfd->doorbell_kernel_ptr = ioremap(kfd->doorbell_base,
					   kfd_doorbell_process_slice(kfd));

	if (!kfd->doorbell_kernel_ptr)
		return -ENOMEM;

	pr_debug("Doorbell initialization:\n");
	pr_debug("doorbell base           == 0x%08lX\n",
			(uintptr_t)kfd->doorbell_base);

	pr_debug("doorbell_id_offset      == 0x%08lX\n",
			kfd->doorbell_id_offset);

	pr_debug("doorbell_process_limit  == 0x%08lX\n",
			doorbell_process_limit);

	pr_debug("doorbell_kernel_offset  == 0x%08lX\n",
			(uintptr_t)kfd->doorbell_base);

	pr_debug("doorbell aperture size  == 0x%08lX\n",
			kfd->shared_resources.doorbell_aperture_size);

	pr_debug("doorbell kernel address == %p\n", kfd->doorbell_kernel_ptr);

	return 0;
}

void kfd_doorbell_fini(struct kfd_dev *kfd)
{
	if (kfd->doorbell_kernel_ptr)
		iounmap(kfd->doorbell_kernel_ptr);
}

int kfd_doorbell_mmap(struct kfd_dev *dev, struct kfd_process *process,
		      struct vm_area_struct *vma)
{
	phys_addr_t address;

	/*
	 * For simplicitly we only allow mapping of the entire doorbell
	 * allocation of a single device & process.
	 */
	if (vma->vm_end - vma->vm_start != kfd_doorbell_process_slice(dev))
		return -EINVAL;

	/* Calculate physical address of doorbell */
	address = kfd_get_process_doorbells(dev, process);

	vma->vm_flags |= VM_IO | VM_DONTCOPY | VM_DONTEXPAND | VM_NORESERVE |
				VM_DONTDUMP | VM_PFNMAP;

	vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);

	pr_debug("Mapping doorbell page\n"
		 "     target user address == 0x%08llX\n"
		 "     physical address    == 0x%08llX\n"
		 "     vm_flags            == 0x%04lX\n"
		 "     size                == 0x%04lX\n",
		 (unsigned long long) vma->vm_start, address, vma->vm_flags,
		 kfd_doorbell_process_slice(dev));


	return io_remap_pfn_range(vma,
				vma->vm_start,
				address >> PAGE_SHIFT,
				kfd_doorbell_process_slice(dev),
				vma->vm_page_prot);
}

