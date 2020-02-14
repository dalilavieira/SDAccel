#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  vm_fault_t ;
struct vm_special_mapping {int dummy; } ;
struct vm_fault {unsigned long pgoff; struct page* page; } ;
struct vm_area_struct {unsigned long vm_end; unsigned long vm_start; TYPE_2__* vm_mm; } ;
struct page {int dummy; } ;
struct TYPE_6__ {TYPE_2__* mm; } ;
struct TYPE_4__ {unsigned long vdso_base; } ;
struct TYPE_5__ {TYPE_1__ context; } ;

/* Variables and functions */
 int EFAULT ; 
 int EINVAL ; 
 unsigned long PAGE_SHIFT ; 
 int /*<<< orphan*/  VM_FAULT_SIGBUS ; 
 scalar_t__ WARN_ON_ONCE (int) ; 
 TYPE_3__* current ; 
 int /*<<< orphan*/  get_page (struct page*) ; 
 struct page** vdso64_pagelist ; 
 unsigned long vdso64_pages ; 

__attribute__((used)) static vm_fault_t vdso_fault(const struct vm_special_mapping *sm,
		      struct vm_area_struct *vma, struct vm_fault *vmf)
{
	struct page **vdso_pagelist;
	unsigned long vdso_pages;

	vdso_pagelist = vdso64_pagelist;
	vdso_pages = vdso64_pages;
#ifdef CONFIG_COMPAT
	if (is_compat_task()) {
		vdso_pagelist = vdso32_pagelist;
		vdso_pages = vdso32_pages;
	}
#endif

	if (vmf->pgoff >= vdso_pages)
		return VM_FAULT_SIGBUS;

	vmf->page = vdso_pagelist[vmf->pgoff];
	get_page(vmf->page);
	return 0;
}

__attribute__((used)) static int vdso_mremap(const struct vm_special_mapping *sm,
		       struct vm_area_struct *vma)
{
	unsigned long vdso_pages;

	vdso_pages = vdso64_pages;
#ifdef CONFIG_COMPAT
	if (is_compat_task())
		vdso_pages = vdso32_pages;
#endif

	if ((vdso_pages << PAGE_SHIFT) != vma->vm_end - vma->vm_start)
		return -EINVAL;

	if (WARN_ON_ONCE(current->mm != vma->vm_mm))
		return -EFAULT;

	current->mm->context.vdso_base = vma->vm_start;
	return 0;
}

