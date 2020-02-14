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
typedef  int /*<<< orphan*/  u64 ;
typedef  int /*<<< orphan*/  u32 ;
struct cpumask {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  WARN_ON_ONCE (int) ; 
 int /*<<< orphan*/  X86_FEATURE_APIC ; 
 scalar_t__ boot_cpu_has (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  disable_apic ; 
 int /*<<< orphan*/  phys_cpu_present_map ; 
 int physid_isset (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void noop_init_apic_ldr(void) { }

__attribute__((used)) static void noop_send_IPI(int cpu, int vector) { }

__attribute__((used)) static void noop_send_IPI_mask(const struct cpumask *cpumask, int vector) { }

__attribute__((used)) static void noop_send_IPI_mask_allbutself(const struct cpumask *cpumask, int vector) { }

__attribute__((used)) static void noop_send_IPI_allbutself(int vector) { }

__attribute__((used)) static void noop_send_IPI_all(int vector) { }

__attribute__((used)) static void noop_send_IPI_self(int vector) { }

__attribute__((used)) static void noop_apic_wait_icr_idle(void) { }

__attribute__((used)) static void noop_apic_icr_write(u32 low, u32 id) { }

__attribute__((used)) static int noop_wakeup_secondary_cpu(int apicid, unsigned long start_eip)
{
	return -1;
}

__attribute__((used)) static u32 noop_safe_apic_wait_icr_idle(void)
{
	return 0;
}

__attribute__((used)) static u64 noop_apic_icr_read(void)
{
	return 0;
}

__attribute__((used)) static int noop_phys_pkg_id(int cpuid_apic, int index_msb)
{
	return 0;
}

__attribute__((used)) static unsigned int noop_get_apic_id(unsigned long x)
{
	return 0;
}

__attribute__((used)) static int noop_probe(void)
{
	/*
	 * NOOP apic should not ever be
	 * enabled via probe routine
	 */
	return 0;
}

__attribute__((used)) static int noop_apic_id_registered(void)
{
	/*
	 * if we would be really "pedantic"
	 * we should pass read_apic_id() here
	 * but since NOOP suppose APIC ID = 0
	 * lets save a few cycles
	 */
	return physid_isset(0, phys_cpu_present_map);
}

__attribute__((used)) static u32 noop_apic_read(u32 reg)
{
	WARN_ON_ONCE(boot_cpu_has(X86_FEATURE_APIC) && !disable_apic);
	return 0;
}

__attribute__((used)) static void noop_apic_write(u32 reg, u32 v)
{
	WARN_ON_ONCE(boot_cpu_has(X86_FEATURE_APIC) && !disable_apic);
}

