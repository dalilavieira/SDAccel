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
 int /*<<< orphan*/  APIC_DFR ; 
 unsigned long APIC_DFR_VALUE ; 
 int /*<<< orphan*/  APIC_LDR ; 
 unsigned long APIC_LDR_MASK ; 
 unsigned long SET_APIC_LOGICAL_ID (unsigned long) ; 
 unsigned long apic_read (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  apic_write (int /*<<< orphan*/ ,unsigned long) ; 
 int /*<<< orphan*/  phys_cpu_present_map ; 
 int physid_isset (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  read_apic_id () ; 
 unsigned long smp_processor_id () ; 

__attribute__((used)) static int default_x86_32_early_logical_apicid(int cpu)
{
	return 1 << cpu;
}

__attribute__((used)) static void setup_apic_flat_routing(void)
{
#ifdef CONFIG_X86_IO_APIC
	printk(KERN_INFO
		"Enabling APIC mode:  Flat.  Using %d I/O APICs\n",
		nr_ioapics);
#endif
}

__attribute__((used)) static int default_apic_id_registered(void)
{
	return physid_isset(read_apic_id(), phys_cpu_present_map);
}

__attribute__((used)) static void default_init_apic_ldr(void)
{
	unsigned long val;

	apic_write(APIC_DFR, APIC_DFR_VALUE);
	val = apic_read(APIC_LDR) & ~APIC_LDR_MASK;
	val |= SET_APIC_LOGICAL_ID(1UL << smp_processor_id());
	apic_write(APIC_LDR, val);
}

__attribute__((used)) static int default_phys_pkg_id(int cpuid_apic, int index_msb)
{
	return cpuid_apic >> index_msb;
}

__attribute__((used)) static int probe_default(void)
{
	return 1;
}

