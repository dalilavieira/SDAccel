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
typedef  int uint32_t ;

/* Variables and functions */
 int MAX_CPUS ; 
 int MAX_LAPICIDS ; 
 int /*<<< orphan*/  assert (int) ; 
 int* cpu_to_lapic ; 
 int* lapic_to_cpu ; 

void
lapic_cpu_map_init(void)
{
	int	i;

	for (i = 0; i < MAX_CPUS; i++)
		cpu_to_lapic[i] = -1;
	for (i = 0; i < MAX_LAPICIDS; i++)
		lapic_to_cpu[i] = -1;
}

void
lapic_cpu_map(int apic_id, int cpu)
{
	assert(apic_id < MAX_LAPICIDS);
	assert(cpu < MAX_CPUS);
	cpu_to_lapic[cpu] = apic_id;
	lapic_to_cpu[apic_id] = cpu;
}

uint32_t
ml_get_apicid(uint32_t cpu)
{
	if(cpu >= (uint32_t)MAX_CPUS)
		return 0xFFFFFFFF;	/* Return -1 if cpu too big */
	
	/* Return the apic ID (or -1 if not configured) */
	return (uint32_t)cpu_to_lapic[cpu];

}

uint32_t
ml_get_cpuid(uint32_t lapic_index)
{
	if(lapic_index >= (uint32_t)MAX_LAPICIDS)
		return 0xFFFFFFFF;	/* Return -1 if cpu too big */
	
	/* Return the cpu ID (or -1 if not configured) */
	return (uint32_t)lapic_to_cpu[lapic_index];

}

