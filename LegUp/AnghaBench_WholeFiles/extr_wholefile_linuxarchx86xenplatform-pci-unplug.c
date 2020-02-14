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

/* Variables and functions */

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

