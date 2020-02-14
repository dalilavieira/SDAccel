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
typedef  scalar_t__ u64 ;
struct device_node {int dummy; } ;

/* Variables and functions */
 int get_hard_smp_processor_id (int) ; 
 struct device_node* of_get_cpu_node (int,int /*<<< orphan*/ *) ; 
 int of_get_ibm_chip_id (struct device_node*) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 

__attribute__((used)) static inline int overlaps_initrd(unsigned long start, unsigned long size)
{
#ifdef CONFIG_BLK_DEV_INITRD
	if (!initrd_start)
		return 0;

	return	(start + size) > _ALIGN_DOWN(initrd_start, PAGE_SIZE) &&
			start <= _ALIGN_UP(initrd_end, PAGE_SIZE);
#else
	return 0;
#endif
}

int cpu_to_chip_id(int cpu)
{
	struct device_node *np;

	np = of_get_cpu_node(cpu, NULL);
	if (!np)
		return -1;

	of_node_put(np);
	return of_get_ibm_chip_id(np);
}

bool arch_match_cpu_phys_id(int cpu, u64 phys_id)
{
#ifdef CONFIG_SMP
	/*
	 * Early firmware scanning must use this rather than
	 * get_hard_smp_processor_id because we don't have pacas allocated
	 * until memory topology is discovered.
	 */
	if (cpu_to_phys_id != NULL)
		return (int)phys_id == cpu_to_phys_id[cpu];
#endif

	return (int)phys_id == get_hard_smp_processor_id(cpu);
}

