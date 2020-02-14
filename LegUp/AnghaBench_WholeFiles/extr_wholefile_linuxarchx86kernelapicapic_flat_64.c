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
typedef  unsigned int u32 ;
struct cpumask {int dummy; } ;
struct TYPE_3__ {int /*<<< orphan*/  dest_logical; } ;

/* Variables and functions */
 int /*<<< orphan*/  APIC_DEST_ALLBUT ; 
 int /*<<< orphan*/  APIC_DEST_ALLINC ; 
 int /*<<< orphan*/  APIC_DFR ; 
 unsigned long APIC_DFR_FLAT ; 
 int /*<<< orphan*/  APIC_ID ; 
 int /*<<< orphan*/  APIC_LDR ; 
 unsigned long APIC_LDR_MASK ; 
 int BITS_PER_LONG ; 
 int /*<<< orphan*/  CONFIG_HOTPLUG_CPU ; 
 scalar_t__ IS_ENABLED (int /*<<< orphan*/ ) ; 
 int NMI_VECTOR ; 
 unsigned long SET_APIC_LOGICAL_ID (unsigned long) ; 
 int /*<<< orphan*/  __default_send_IPI_dest_field (unsigned long,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __default_send_IPI_shortcut (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 TYPE_1__* apic ; 
 TYPE_1__ apic_physflat ; 
 unsigned long apic_read (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  apic_write (int /*<<< orphan*/ ,unsigned long) ; 
 int /*<<< orphan*/  clear_bit (int,unsigned long*) ; 
 struct cpumask const* cpu_online_mask ; 
 unsigned long* cpumask_bits (struct cpumask const*) ; 
 int /*<<< orphan*/  cpumask_equal (struct cpumask const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpumask_of (int) ; 
 int /*<<< orphan*/  default_send_IPI_mask_allbutself_phys (struct cpumask const*,int) ; 
 int /*<<< orphan*/  default_send_IPI_mask_sequence_phys (struct cpumask const*,int) ; 
 scalar_t__ jailhouse_paravirt () ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 int num_online_cpus () ; 
 int num_possible_cpus () ; 
 int /*<<< orphan*/  phys_cpu_present_map ; 
 int physid_isset (unsigned int,int /*<<< orphan*/ ) ; 
 void* smp_processor_id () ; 

__attribute__((used)) static int flat_acpi_madt_oem_check(char *oem_id, char *oem_table_id)
{
	return 1;
}

void flat_init_apic_ldr(void)
{
	unsigned long val;
	unsigned long num, id;

	num = smp_processor_id();
	id = 1UL << num;
	apic_write(APIC_DFR, APIC_DFR_FLAT);
	val = apic_read(APIC_LDR) & ~APIC_LDR_MASK;
	val |= SET_APIC_LOGICAL_ID(id);
	apic_write(APIC_LDR, val);
}

__attribute__((used)) static void _flat_send_IPI_mask(unsigned long mask, int vector)
{
	unsigned long flags;

	local_irq_save(flags);
	__default_send_IPI_dest_field(mask, vector, apic->dest_logical);
	local_irq_restore(flags);
}

__attribute__((used)) static void flat_send_IPI_mask(const struct cpumask *cpumask, int vector)
{
	unsigned long mask = cpumask_bits(cpumask)[0];

	_flat_send_IPI_mask(mask, vector);
}

__attribute__((used)) static void
flat_send_IPI_mask_allbutself(const struct cpumask *cpumask, int vector)
{
	unsigned long mask = cpumask_bits(cpumask)[0];
	int cpu = smp_processor_id();

	if (cpu < BITS_PER_LONG)
		clear_bit(cpu, &mask);

	_flat_send_IPI_mask(mask, vector);
}

__attribute__((used)) static void flat_send_IPI_allbutself(int vector)
{
	int cpu = smp_processor_id();

	if (IS_ENABLED(CONFIG_HOTPLUG_CPU) || vector == NMI_VECTOR) {
		if (!cpumask_equal(cpu_online_mask, cpumask_of(cpu))) {
			unsigned long mask = cpumask_bits(cpu_online_mask)[0];

			if (cpu < BITS_PER_LONG)
				clear_bit(cpu, &mask);

			_flat_send_IPI_mask(mask, vector);
		}
	} else if (num_online_cpus() > 1) {
		__default_send_IPI_shortcut(APIC_DEST_ALLBUT,
					    vector, apic->dest_logical);
	}
}

__attribute__((used)) static void flat_send_IPI_all(int vector)
{
	if (vector == NMI_VECTOR) {
		flat_send_IPI_mask(cpu_online_mask, vector);
	} else {
		__default_send_IPI_shortcut(APIC_DEST_ALLINC,
					    vector, apic->dest_logical);
	}
}

__attribute__((used)) static unsigned int flat_get_apic_id(unsigned long x)
{
	return (x >> 24) & 0xFF;
}

__attribute__((used)) static u32 set_apic_id(unsigned int id)
{
	return (id & 0xFF) << 24;
}

__attribute__((used)) static unsigned int read_xapic_id(void)
{
	return flat_get_apic_id(apic_read(APIC_ID));
}

__attribute__((used)) static int flat_apic_id_registered(void)
{
	return physid_isset(read_xapic_id(), phys_cpu_present_map);
}

__attribute__((used)) static int flat_phys_pkg_id(int initial_apic_id, int index_msb)
{
	return initial_apic_id >> index_msb;
}

__attribute__((used)) static int flat_probe(void)
{
	return 1;
}

__attribute__((used)) static int physflat_acpi_madt_oem_check(char *oem_id, char *oem_table_id)
{
#ifdef CONFIG_ACPI
	/*
	 * Quirk: some x86_64 machines can only use physical APIC mode
	 * regardless of how many processors are present (x86_64 ES7000
	 * is an example).
	 */
	if (acpi_gbl_FADT.header.revision >= FADT2_REVISION_ID &&
		(acpi_gbl_FADT.flags & ACPI_FADT_APIC_PHYSICAL)) {
		printk(KERN_DEBUG "system APIC only can use physical flat");
		return 1;
	}

	if (!strncmp(oem_id, "IBM", 3) && !strncmp(oem_table_id, "EXA", 3)) {
		printk(KERN_DEBUG "IBM Summit detected, will use apic physical");
		return 1;
	}
#endif

	return 0;
}

__attribute__((used)) static void physflat_init_apic_ldr(void)
{
	/*
	 * LDR and DFR are not involved in physflat mode, rather:
	 * "In physical destination mode, the destination processor is
	 * specified by its local APIC ID [...]." (Intel SDM, 10.6.2.1)
	 */
}

__attribute__((used)) static void physflat_send_IPI_allbutself(int vector)
{
	default_send_IPI_mask_allbutself_phys(cpu_online_mask, vector);
}

__attribute__((used)) static void physflat_send_IPI_all(int vector)
{
	default_send_IPI_mask_sequence_phys(cpu_online_mask, vector);
}

__attribute__((used)) static int physflat_probe(void)
{
	if (apic == &apic_physflat || num_possible_cpus() > 8 ||
	    jailhouse_paravirt())
		return 1;

	return 0;
}

