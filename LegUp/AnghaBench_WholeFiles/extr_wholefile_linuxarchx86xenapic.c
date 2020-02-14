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
typedef  int /*<<< orphan*/  u64 ;
typedef  unsigned int u32 ;
struct TYPE_4__ {int apic_id; int /*<<< orphan*/  xen_cpuid; } ;
struct TYPE_5__ {TYPE_1__ pcpu_info; } ;
struct xen_platform_op {TYPE_2__ u; int /*<<< orphan*/  interface_version; int /*<<< orphan*/  cmd; } ;
struct physdev_apic {unsigned int reg; unsigned int value; int /*<<< orphan*/  apic_physbase; } ;
struct TYPE_6__ {int apicid; } ;

/* Variables and functions */
 unsigned int APIC_ID ; 
 unsigned int APIC_LVR ; 
 unsigned int APIC_LVTPC ; 
 int BAD_APICID ; 
 int HYPERVISOR_physdev_op (int /*<<< orphan*/ ,struct physdev_apic*) ; 
 int HYPERVISOR_platform_op (struct xen_platform_op*) ; 
 int /*<<< orphan*/  PHYSDEVOP_apic_read ; 
 int /*<<< orphan*/  WARN (int,char*,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int /*<<< orphan*/  XENPF_INTERFACE_VERSION ; 
 int /*<<< orphan*/  XENPF_get_cpuinfo ; 
 TYPE_3__ cpu_data (int) ; 
 scalar_t__ cpu_present (int) ; 
 int /*<<< orphan*/  mpc_ioapic_addr (unsigned int) ; 
 int /*<<< orphan*/  pmu_apic_update (unsigned int) ; 
 scalar_t__ smp_processor_id () ; 
 int /*<<< orphan*/  xen_initial_domain () ; 
 int xen_pv_domain () ; 

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

__attribute__((used)) static inline void xen_pmu_init(int cpu) {}

__attribute__((used)) static inline void xen_pmu_finish(int cpu) {}

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

__attribute__((used)) static unsigned int xen_io_apic_read(unsigned apic, unsigned reg)
{
	struct physdev_apic apic_op;
	int ret;

	apic_op.apic_physbase = mpc_ioapic_addr(apic);
	apic_op.reg = reg;
	ret = HYPERVISOR_physdev_op(PHYSDEVOP_apic_read, &apic_op);
	if (!ret)
		return apic_op.value;

	/* fallback to return an emulated IO_APIC values */
	if (reg == 0x1)
		return 0x00170020;
	else if (reg == 0x0)
		return apic << 24;

	return 0xfd;
}

__attribute__((used)) static u32 xen_set_apic_id(unsigned int x)
{
	WARN_ON(1);
	return x;
}

__attribute__((used)) static unsigned int xen_get_apic_id(unsigned long x)
{
	return ((x)>>24) & 0xFFu;
}

__attribute__((used)) static u32 xen_apic_read(u32 reg)
{
	struct xen_platform_op op = {
		.cmd = XENPF_get_cpuinfo,
		.interface_version = XENPF_INTERFACE_VERSION,
		.u.pcpu_info.xen_cpuid = 0,
	};
	int ret = 0;

	/* Shouldn't need this as APIC is turned off for PV, and we only
	 * get called on the bootup processor. But just in case. */
	if (!xen_initial_domain() || smp_processor_id())
		return 0;

	if (reg == APIC_LVR)
		return 0x14;
#ifdef CONFIG_X86_32
	if (reg == APIC_LDR)
		return SET_APIC_LOGICAL_ID(1UL << smp_processor_id());
#endif
	if (reg != APIC_ID)
		return 0;

	ret = HYPERVISOR_platform_op(&op);
	if (ret)
		op.u.pcpu_info.apic_id = BAD_APICID;

	return op.u.pcpu_info.apic_id << 24;
}

__attribute__((used)) static void xen_apic_write(u32 reg, u32 val)
{
	if (reg == APIC_LVTPC) {
		(void)pmu_apic_update(reg);
		return;
	}

	/* Warn to see if there's any stray references */
	WARN(1,"register: %x, value: %x\n", reg, val);
}

__attribute__((used)) static u64 xen_apic_icr_read(void)
{
	return 0;
}

__attribute__((used)) static void xen_apic_icr_write(u32 low, u32 id)
{
	/* Warn to see if there's any stray references */
	WARN_ON(1);
}

__attribute__((used)) static u32 xen_safe_apic_wait_icr_idle(void)
{
        return 0;
}

__attribute__((used)) static int xen_apic_probe_pv(void)
{
	if (xen_pv_domain())
		return 1;

	return 0;
}

__attribute__((used)) static int xen_madt_oem_check(char *oem_id, char *oem_table_id)
{
	return xen_pv_domain();
}

__attribute__((used)) static int xen_id_always_valid(u32 apicid)
{
	return 1;
}

__attribute__((used)) static int xen_id_always_registered(void)
{
	return 1;
}

__attribute__((used)) static int xen_phys_pkg_id(int initial_apic_id, int index_msb)
{
	return initial_apic_id >> index_msb;
}

__attribute__((used)) static void xen_noop(void)
{
}

__attribute__((used)) static void xen_silent_inquire(int apicid)
{
}

__attribute__((used)) static int xen_cpu_present_to_apicid(int cpu)
{
	if (cpu_present(cpu))
		return cpu_data(cpu).apicid;
	else
		return BAD_APICID;
}

