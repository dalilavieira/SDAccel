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
typedef  unsigned int u32 ;
typedef  int /*<<< orphan*/  physid_mask_t ;

/* Variables and functions */
 int BAD_APICID ; 
 scalar_t__ cpu_present (int) ; 
 int nr_cpu_ids ; 
 unsigned int per_cpu (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  phys_cpu_present_map ; 
 int physid_isset (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  x86_bios_cpu_apicid ; 
 int /*<<< orphan*/  x86_cpu_to_apicid ; 

u32 apic_default_calc_apicid(unsigned int cpu)
{
	return per_cpu(x86_cpu_to_apicid, cpu);
}

u32 apic_flat_calc_apicid(unsigned int cpu)
{
	return 1U << cpu;
}

bool default_check_apicid_used(physid_mask_t *map, int apicid)
{
	return physid_isset(apicid, *map);
}

void default_ioapic_phys_id_map(physid_mask_t *phys_map, physid_mask_t *retmap)
{
	*retmap = *phys_map;
}

int default_cpu_present_to_apicid(int mps_cpu)
{
	if (mps_cpu < nr_cpu_ids && cpu_present(mps_cpu))
		return (int)per_cpu(x86_bios_cpu_apicid, mps_cpu);
	else
		return BAD_APICID;
}

int default_check_phys_apicid_present(int phys_apicid)
{
	return physid_isset(phys_apicid, phys_cpu_present_map);
}

int default_apic_id_valid(u32 apicid)
{
	return (apicid < 255);
}

