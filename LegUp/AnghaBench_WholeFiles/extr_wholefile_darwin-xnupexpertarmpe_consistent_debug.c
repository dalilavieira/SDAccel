#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  void* uint64_t ;
typedef  int /*<<< orphan*/  uint32_t ;
struct TYPE_6__ {unsigned int num_records; } ;
struct TYPE_7__ {TYPE_3__* records; TYPE_1__ top_level_header; } ;
typedef  TYPE_2__ dbg_registry_t ;
struct TYPE_8__ {void* record_id; void* physaddr; void* length; } ;
typedef  TYPE_3__ dbg_record_header_t ;
typedef  int /*<<< orphan*/  DTEntry ;

/* Variables and functions */
 scalar_t__ DTGetProperty (int /*<<< orphan*/ ,char*,void**,int /*<<< orphan*/ *) ; 
 scalar_t__ DTLookupEntry (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *) ; 
 scalar_t__ OSCompareAndSwap64 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,void**) ; 
 TYPE_2__* consistent_debug_registry ; 
 int /*<<< orphan*/  kDbgIdReservedEntry ; 
 int /*<<< orphan*/  kDbgIdUnusedEntry ; 
 scalar_t__ kSuccess ; 
 scalar_t__ ml_map_high_window (uintptr_t,int) ; 

__attribute__((used)) static dbg_record_header_t* consistent_debug_allocate_entry(void) {
	unsigned int i;

	if (!consistent_debug_registry)
		return NULL;
	for (i = 0; i < consistent_debug_registry->top_level_header.num_records; i++) {
		dbg_record_header_t *record = &consistent_debug_registry->records[i];
		if (OSCompareAndSwap64(kDbgIdUnusedEntry, kDbgIdReservedEntry, &record->record_id)) {
			// Reserved an entry at position i.
			return (dbg_record_header_t*)record;
		}
	}
	return NULL;
}

int PE_consistent_debug_inherit(void)
{
	DTEntry		entryP;
	uintptr_t	*prop_data;
	uintptr_t	root_pointer = 0;
	uint32_t	size;

        if ((DTLookupEntry(NULL, "/chosen", &entryP) == kSuccess))
		if (DTGetProperty(entryP, "consistent-debug-root", (void **)&prop_data, &size) == kSuccess)
			root_pointer = prop_data[0];
	if (root_pointer == 0)
		return -1;
	consistent_debug_registry = (dbg_registry_t *)ml_map_high_window(root_pointer, sizeof(dbg_registry_t));
	return 0;
}

int PE_consistent_debug_register(uint64_t record_id, uint64_t physaddr, uint64_t length)
{
	dbg_record_header_t *allocated_header = consistent_debug_allocate_entry();
	if (allocated_header == NULL)
		return -1;
	allocated_header->length = length;
	allocated_header->physaddr = physaddr;
	// Make sure the hdr/length are visible before the record_id.
	__asm__ volatile("dmb ish" : : : "memory");
	allocated_header->record_id = record_id;
	return 0;
}

int PE_consistent_debug_enabled(void)
{
	return (consistent_debug_registry != NULL);
}

