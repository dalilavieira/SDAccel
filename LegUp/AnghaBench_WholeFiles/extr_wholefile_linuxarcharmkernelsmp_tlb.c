#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct vm_area_struct {struct tlb_args* vm_mm; } ;
struct tlb_args {unsigned long ta_start; unsigned long ta_end; struct vm_area_struct* ta_vma; } ;
struct mm_struct {unsigned long ta_start; unsigned long ta_end; struct vm_area_struct* ta_vma; } ;
struct TYPE_4__ {int /*<<< orphan*/  member_0; } ;
typedef  TYPE_1__ cpumask_t ;

/* Variables and functions */
 int /*<<< orphan*/  CPU_BITS_NONE ; 
 int /*<<< orphan*/  __flush_bp_all () ; 
 int /*<<< orphan*/  __flush_tlb_all () ; 
 int /*<<< orphan*/  __flush_tlb_kernel_page (unsigned long) ; 
 int /*<<< orphan*/  __flush_tlb_mm (struct tlb_args*) ; 
 int /*<<< orphan*/  __flush_tlb_page (struct vm_area_struct*,unsigned long) ; 
 int /*<<< orphan*/  a15_erratum_get_cpumask (int,struct tlb_args*,TYPE_1__*) ; 
 int /*<<< orphan*/  dmb () ; 
 int /*<<< orphan*/  erratum_a15_798181 () ; 
 int get_cpu () ; 
 int /*<<< orphan*/  local_flush_bp_all () ; 
 int /*<<< orphan*/  local_flush_tlb_all () ; 
 int /*<<< orphan*/  local_flush_tlb_kernel_page (unsigned long) ; 
 int /*<<< orphan*/  local_flush_tlb_kernel_range (unsigned long,unsigned long) ; 
 int /*<<< orphan*/  local_flush_tlb_mm (struct tlb_args*) ; 
 int /*<<< orphan*/  local_flush_tlb_page (struct vm_area_struct*,unsigned long) ; 
 int /*<<< orphan*/  local_flush_tlb_range (struct vm_area_struct*,unsigned long,unsigned long) ; 
 int /*<<< orphan*/  mm_cpumask (struct tlb_args*) ; 
 int /*<<< orphan*/  on_each_cpu (void (*) (void*),struct tlb_args*,int) ; 
 int /*<<< orphan*/  on_each_cpu_mask (int /*<<< orphan*/ ,void (*) (void*),struct tlb_args*,int) ; 
 int /*<<< orphan*/  put_cpu () ; 
 int /*<<< orphan*/  smp_call_function (void (*) (void*),int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  smp_call_function_many (TYPE_1__*,void (*) (void*),int /*<<< orphan*/ *,int) ; 
 scalar_t__ tlb_ops_need_broadcast () ; 
 int /*<<< orphan*/  uaccess_restore (unsigned int) ; 
 unsigned int uaccess_save_and_enable () ; 

__attribute__((used)) static inline void ipi_flush_tlb_all(void *ignored)
{
	local_flush_tlb_all();
}

__attribute__((used)) static inline void ipi_flush_tlb_mm(void *arg)
{
	struct mm_struct *mm = (struct mm_struct *)arg;

	local_flush_tlb_mm(mm);
}

__attribute__((used)) static inline void ipi_flush_tlb_page(void *arg)
{
	struct tlb_args *ta = (struct tlb_args *)arg;
	unsigned int __ua_flags = uaccess_save_and_enable();

	local_flush_tlb_page(ta->ta_vma, ta->ta_start);

	uaccess_restore(__ua_flags);
}

__attribute__((used)) static inline void ipi_flush_tlb_kernel_page(void *arg)
{
	struct tlb_args *ta = (struct tlb_args *)arg;

	local_flush_tlb_kernel_page(ta->ta_start);
}

__attribute__((used)) static inline void ipi_flush_tlb_range(void *arg)
{
	struct tlb_args *ta = (struct tlb_args *)arg;
	unsigned int __ua_flags = uaccess_save_and_enable();

	local_flush_tlb_range(ta->ta_vma, ta->ta_start, ta->ta_end);

	uaccess_restore(__ua_flags);
}

__attribute__((used)) static inline void ipi_flush_tlb_kernel_range(void *arg)
{
	struct tlb_args *ta = (struct tlb_args *)arg;

	local_flush_tlb_kernel_range(ta->ta_start, ta->ta_end);
}

__attribute__((used)) static inline void ipi_flush_bp_all(void *ignored)
{
	local_flush_bp_all();
}

__attribute__((used)) static void ipi_flush_tlb_a15_erratum(void *arg)
{
	dmb();
}

__attribute__((used)) static void broadcast_tlb_a15_erratum(void)
{
	if (!erratum_a15_798181())
		return;

	smp_call_function(ipi_flush_tlb_a15_erratum, NULL, 1);
}

__attribute__((used)) static void broadcast_tlb_mm_a15_erratum(struct mm_struct *mm)
{
	int this_cpu;
	cpumask_t mask = { CPU_BITS_NONE };

	if (!erratum_a15_798181())
		return;

	this_cpu = get_cpu();
	a15_erratum_get_cpumask(this_cpu, mm, &mask);
	smp_call_function_many(&mask, ipi_flush_tlb_a15_erratum, NULL, 1);
	put_cpu();
}

void flush_tlb_all(void)
{
	if (tlb_ops_need_broadcast())
		on_each_cpu(ipi_flush_tlb_all, NULL, 1);
	else
		__flush_tlb_all();
	broadcast_tlb_a15_erratum();
}

void flush_tlb_mm(struct mm_struct *mm)
{
	if (tlb_ops_need_broadcast())
		on_each_cpu_mask(mm_cpumask(mm), ipi_flush_tlb_mm, mm, 1);
	else
		__flush_tlb_mm(mm);
	broadcast_tlb_mm_a15_erratum(mm);
}

void flush_tlb_page(struct vm_area_struct *vma, unsigned long uaddr)
{
	if (tlb_ops_need_broadcast()) {
		struct tlb_args ta;
		ta.ta_vma = vma;
		ta.ta_start = uaddr;
		on_each_cpu_mask(mm_cpumask(vma->vm_mm), ipi_flush_tlb_page,
					&ta, 1);
	} else
		__flush_tlb_page(vma, uaddr);
	broadcast_tlb_mm_a15_erratum(vma->vm_mm);
}

void flush_tlb_kernel_page(unsigned long kaddr)
{
	if (tlb_ops_need_broadcast()) {
		struct tlb_args ta;
		ta.ta_start = kaddr;
		on_each_cpu(ipi_flush_tlb_kernel_page, &ta, 1);
	} else
		__flush_tlb_kernel_page(kaddr);
	broadcast_tlb_a15_erratum();
}

void flush_tlb_range(struct vm_area_struct *vma,
                     unsigned long start, unsigned long end)
{
	if (tlb_ops_need_broadcast()) {
		struct tlb_args ta;
		ta.ta_vma = vma;
		ta.ta_start = start;
		ta.ta_end = end;
		on_each_cpu_mask(mm_cpumask(vma->vm_mm), ipi_flush_tlb_range,
					&ta, 1);
	} else
		local_flush_tlb_range(vma, start, end);
	broadcast_tlb_mm_a15_erratum(vma->vm_mm);
}

void flush_tlb_kernel_range(unsigned long start, unsigned long end)
{
	if (tlb_ops_need_broadcast()) {
		struct tlb_args ta;
		ta.ta_start = start;
		ta.ta_end = end;
		on_each_cpu(ipi_flush_tlb_kernel_range, &ta, 1);
	} else
		local_flush_tlb_kernel_range(start, end);
	broadcast_tlb_a15_erratum();
}

void flush_bp_all(void)
{
	if (tlb_ops_need_broadcast())
		on_each_cpu(ipi_flush_bp_all, NULL, 1);
	else
		__flush_bp_all();
}

