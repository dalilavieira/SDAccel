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
struct xen_add_to_physmap {int /*<<< orphan*/  gpfn; int /*<<< orphan*/  space; scalar_t__ idx; int /*<<< orphan*/  domid; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG () ; 
 int /*<<< orphan*/  DOMID_SELF ; 
 scalar_t__ HYPERVISOR_memory_op (int /*<<< orphan*/ ,struct xen_add_to_physmap*) ; 
 int /*<<< orphan*/  XENFEAT_hvm_pirqs ; 
 int /*<<< orphan*/  XENMAPSPACE_shared_info ; 
 int /*<<< orphan*/  XENMEM_add_to_physmap ; 
 int /*<<< orphan*/  shared_info_pfn ; 
 scalar_t__ xen_feature (int /*<<< orphan*/ ) ; 
 scalar_t__ xen_have_vector_callback ; 
 int /*<<< orphan*/  xen_hvm_domain () ; 
 scalar_t__ xen_nopv ; 
 scalar_t__ xen_pv_domain () ; 

__attribute__((used)) static inline void xen_smp_init(void) {}

__attribute__((used)) static inline void xen_hvm_smp_init(void) {}

__attribute__((used)) static inline void xen_init_spinlocks(void)
{
}

__attribute__((used)) static inline void xen_init_lock_cpu(int cpu)
{
}

__attribute__((used)) static inline void xen_uninit_lock_cpu(int cpu)
{
}

__attribute__((used)) static inline void xen_pv_pre_suspend(void) {}

__attribute__((used)) static inline void xen_pv_post_suspend(int suspend_cancelled) {}

__attribute__((used)) static inline void xen_hvm_post_suspend(int suspend_cancelled) {}

__attribute__((used)) static inline int xen_smp_intr_init(unsigned int cpu)
{
	return 0;
}

__attribute__((used)) static inline void xen_smp_intr_free(unsigned int cpu) {}

__attribute__((used)) static inline int xen_smp_intr_init_pv(unsigned int cpu)
{
	return 0;
}

__attribute__((used)) static inline void xen_smp_intr_free_pv(unsigned int cpu) {}

void xen_hvm_init_shared_info(void)
{
	struct xen_add_to_physmap xatp;

	xatp.domid = DOMID_SELF;
	xatp.idx = 0;
	xatp.space = XENMAPSPACE_shared_info;
	xatp.gpfn = shared_info_pfn;
	if (HYPERVISOR_memory_op(XENMEM_add_to_physmap, &xatp))
		BUG();
}

bool xen_hvm_need_lapic(void)
{
	if (xen_nopv)
		return false;
	if (xen_pv_domain())
		return false;
	if (!xen_hvm_domain())
		return false;
	if (xen_feature(XENFEAT_hvm_pirqs) && xen_have_vector_callback)
		return false;
	return true;
}

