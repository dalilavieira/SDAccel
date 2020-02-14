#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned int vm_size_t ;
struct ipc_table_size {int dummy; } ;
struct ipc_port_request {int dummy; } ;
struct ipc_entry {int dummy; } ;
typedef  TYPE_1__* ipc_table_size_t ;
typedef  void* ipc_table_elems_t ;
struct TYPE_6__ {void* its_size; } ;

/* Variables and functions */
 TYPE_1__* ITS_NULL ; 
 unsigned int PAGE_MAX_SIZE ; 
 int /*<<< orphan*/  assert (int) ; 
 TYPE_1__* ipc_table_entries ; 
 int ipc_table_entries_size ; 
 TYPE_1__* ipc_table_requests ; 
 int ipc_table_requests_size ; 
 void* kalloc (unsigned int) ; 
 int /*<<< orphan*/  kfree (void*,unsigned int) ; 

__attribute__((used)) static void
ipc_table_fill(
	ipc_table_size_t	its,	     /* array to fill */
	unsigned int		num,	     /* size of array */
	unsigned int		min,	     /* at least this many elements */
	vm_size_t		elemsize)    /* size of elements */
{
	unsigned int index;
	vm_size_t minsize = min * elemsize;
	vm_size_t size;
	vm_size_t incrsize;

	/* first use powers of two, up to the page size */

	for (index = 0, size = 1;
	     (index < num) && (size < PAGE_MAX_SIZE);
	     size <<= 1) {
		if (size >= minsize) {
			its[index].its_size = (ipc_table_elems_t)(size / elemsize);
			index++;
		}
	}

	/* then increments of a page, then two pages, etc. */

	for (incrsize = PAGE_MAX_SIZE; index < num;) {
		unsigned int period;

		for (period = 0;
		     (period < 15) && (index < num);
		     period++, size += incrsize) {
			if (size >= minsize) {
				its[index].its_size = (ipc_table_elems_t)(size / elemsize);
				index++;
			}
		}
		if (incrsize < (vm_size_t)(PAGE_MAX_SIZE << 3))
			incrsize <<= 1;
	}
}

void
ipc_table_init(void)
{
	ipc_table_entries = (ipc_table_size_t)
		kalloc(sizeof(struct ipc_table_size) *
		       ipc_table_entries_size);
	assert(ipc_table_entries != ITS_NULL);

	ipc_table_fill(ipc_table_entries, ipc_table_entries_size - 1,
		       16, sizeof(struct ipc_entry));

	/* the last two elements should have the same size */

	ipc_table_entries[ipc_table_entries_size - 1].its_size =
		ipc_table_entries[ipc_table_entries_size - 2].its_size;


	ipc_table_requests = (ipc_table_size_t)
		kalloc(sizeof(struct ipc_table_size) *
		       ipc_table_requests_size);
	assert(ipc_table_requests != ITS_NULL);

	ipc_table_fill(ipc_table_requests, ipc_table_requests_size - 1,
		       2, sizeof(struct ipc_port_request));

	/* the last element should have zero size */

	ipc_table_requests[ipc_table_requests_size - 1].its_size = 0;
}

unsigned int
ipc_table_max_entries(void)
{
	if (!ipc_table_entries || ipc_table_entries_size < 2)
		return 0;
	return (unsigned int)ipc_table_entries[ipc_table_entries_size - 1].its_size;
}

unsigned int
ipc_table_max_requests(void)
{
	if (!ipc_table_requests || ipc_table_requests_size < 2)
		return 0;
	return (unsigned int)ipc_table_requests[ipc_table_requests_size - 2].its_size;
}

void *
ipc_table_alloc(
	vm_size_t	size)
{
	return kalloc(size);
}

void
ipc_table_free(
	vm_size_t	size,
	void *		table)
{
	kfree(table, size);
}

