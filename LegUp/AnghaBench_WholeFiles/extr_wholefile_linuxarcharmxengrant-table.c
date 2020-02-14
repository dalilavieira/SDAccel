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
typedef  int /*<<< orphan*/  xen_pfn_t ;
typedef  int /*<<< orphan*/  uint64_t ;
typedef  int /*<<< orphan*/  grant_status_t ;

/* Variables and functions */
 int ENOSYS ; 

int arch_gnttab_map_shared(xen_pfn_t *frames, unsigned long nr_gframes,
			   unsigned long max_nr_gframes,
			   void **__shared)
{
	return -ENOSYS;
}

void arch_gnttab_unmap(void *shared, unsigned long nr_gframes)
{
	return;
}

int arch_gnttab_map_status(uint64_t *frames, unsigned long nr_gframes,
			   unsigned long max_nr_gframes,
			   grant_status_t **__shared)
{
	return -ENOSYS;
}

int arch_gnttab_init(unsigned long nr_shared, unsigned long nr_status)
{
	return 0;
}

