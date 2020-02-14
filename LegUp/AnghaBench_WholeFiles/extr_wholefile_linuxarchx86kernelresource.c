#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct resource {scalar_t__ end; scalar_t__ start; int flags; } ;
struct e820_entry {scalar_t__ addr; scalar_t__ size; } ;
typedef  scalar_t__ resource_size_t ;
struct TYPE_2__ {int nr_entries; struct e820_entry* entries; } ;

/* Variables and functions */
 scalar_t__ BIOS_ROM_BASE ; 
 scalar_t__ BIOS_ROM_END ; 
 int IORESOURCE_MEM ; 
 TYPE_1__* e820_table ; 

__attribute__((used)) static void resource_clip(struct resource *res, resource_size_t start,
			  resource_size_t end)
{
	resource_size_t low = 0, high = 0;

	if (res->end < start || res->start > end)
		return;		/* no conflict */

	if (res->start < start)
		low = start - res->start;

	if (res->end > end)
		high = res->end - end;

	/* Keep the area above or below the conflict, whichever is larger */
	if (low > high)
		res->end = start - 1;
	else
		res->start = end + 1;
}

__attribute__((used)) static void remove_e820_regions(struct resource *avail)
{
	int i;
	struct e820_entry *entry;

	for (i = 0; i < e820_table->nr_entries; i++) {
		entry = &e820_table->entries[i];

		resource_clip(avail, entry->addr,
			      entry->addr + entry->size - 1);
	}
}

void arch_remove_reservations(struct resource *avail)
{
	/*
	 * Trim out BIOS area (high 2MB) and E820 regions. We do not remove
	 * the low 1MB unconditionally, as this area is needed for some ISA
	 * cards requiring a memory range, e.g. the i82365 PCMCIA controller.
	 */
	if (avail->flags & IORESOURCE_MEM) {
		resource_clip(avail, BIOS_ROM_BASE, BIOS_ROM_END);

		remove_e820_regions(avail);
	}
}

