#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_37__   TYPE_3__ ;
typedef  struct TYPE_36__   TYPE_2__ ;
typedef  struct TYPE_35__   TYPE_1__ ;

/* Type definitions */
struct ipc_entry {int dummy; } ;
typedef  scalar_t__ mach_port_type_t ;
typedef  int /*<<< orphan*/  mach_port_name_t ;
typedef  scalar_t__ mach_port_index_t ;
typedef  int /*<<< orphan*/  kern_return_t ;
typedef  TYPE_1__* ipc_table_size_t ;
typedef  TYPE_2__* ipc_space_t ;
typedef  TYPE_3__* ipc_entry_t ;
typedef  int ipc_entry_num_t ;
typedef  int ipc_entry_bits_t ;
struct TYPE_37__ {void* ie_bits; scalar_t__ ie_index; void* ie_object; scalar_t__ ie_next; } ;
struct TYPE_36__ {int is_bits; int is_table_size; int is_table_free; int is_low_mod; TYPE_1__* is_table_next; TYPE_3__* is_table; void* is_node_id; scalar_t__ is_high_mod; int /*<<< orphan*/ * is_task; int /*<<< orphan*/  bool_gen; int /*<<< orphan*/ * is_entropy; } ;
struct TYPE_35__ {int its_size; } ;

/* Variables and functions */
 int /*<<< orphan*/  FALSE ; 
 void* HOST_LOCAL_NODE ; 
 int /*<<< orphan*/  IE_BITS_GEN (void*) ; 
 void* IE_BITS_GEN_MASK ; 
 int IE_BITS_ROLL_BITS ; 
 scalar_t__ IE_BITS_TYPE (void*) ; 
 TYPE_3__* IE_NULL ; 
 void* IO_NULL ; 
 int /*<<< orphan*/  IS_ENTROPY_CNT ; 
 int IS_INACTIVE ; 
 TYPE_2__* IS_NULL ; 
 int /*<<< orphan*/  KERN_RESOURCE_SHORTAGE ; 
 int /*<<< orphan*/  KERN_SUCCESS ; 
 int /*<<< orphan*/  MACH_PORT_MAKE (scalar_t__,int /*<<< orphan*/ ) ; 
 scalar_t__ MACH_PORT_TYPE_NONE ; 
 int /*<<< orphan*/ * TASK_NULL ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  ipc_right_destroy (TYPE_2__*,int /*<<< orphan*/ ,TYPE_3__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ipc_right_terminate (TYPE_2__*,int /*<<< orphan*/ ,TYPE_3__*) ; 
 int /*<<< orphan*/  is_active (TYPE_2__*) ; 
 TYPE_2__* is_alloc () ; 
 int /*<<< orphan*/  is_free (TYPE_2__*) ; 
 scalar_t__ is_growing (TYPE_2__*) ; 
 int /*<<< orphan*/  is_lock_init (TYPE_2__*) ; 
 int /*<<< orphan*/  is_mark_inactive (TYPE_2__*) ; 
 int /*<<< orphan*/  is_reference (TYPE_2__*) ; 
 int /*<<< orphan*/  is_release (TYPE_2__*) ; 
 int /*<<< orphan*/  is_write_lock (TYPE_2__*) ; 
 int /*<<< orphan*/  is_write_sleep (TYPE_2__*) ; 
 int /*<<< orphan*/  is_write_unlock (TYPE_2__*) ; 
 TYPE_3__* it_entries_alloc (TYPE_1__*) ; 
 int /*<<< orphan*/  it_entries_free (TYPE_1__*,TYPE_3__*) ; 
 int /*<<< orphan*/  memset (void*,int /*<<< orphan*/ ,int) ; 
 int random_bool_gen_bits (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  random_bool_init (int /*<<< orphan*/ *) ; 

void
ipc_space_reference(
	ipc_space_t	space)
{
	is_reference(space);
}

void
ipc_space_release(
	ipc_space_t	space)
{
	is_release(space);
}

ipc_entry_bits_t
ipc_space_get_rollpoint(
	ipc_space_t	space)
{
	return random_bool_gen_bits(
			&space->bool_gen,
			&space->is_entropy[0],
			IS_ENTROPY_CNT,
			IE_BITS_ROLL_BITS);
}

void
ipc_space_rand_freelist(
	ipc_space_t		space,
	ipc_entry_t		table,
	mach_port_index_t	bottom,
	mach_port_index_t	top)
{
	int at_start = (bottom == 0);
#ifdef CONFIG_SEMI_RANDOM_ENTRIES
	/*
	 * Only make sequential entries at the start of the table, and not when
	 * we're growing the space.
	 */
	ipc_entry_num_t total = 0;
#endif

	/* First entry in the free list is always free, and is the start of the free list. */
	mach_port_index_t curr = bottom;
	bottom++;
	top--;

	/*
	 *	Initialize the free list in the table.
	 *	Add the entries in pseudo-random order and randomly set the generation
	 *	number, in order to frustrate attacks involving port name reuse.
	 */
	while (bottom <= top) {
		ipc_entry_t entry = &table[curr];
		int which;
#ifdef CONFIG_SEMI_RANDOM_ENTRIES
		/*
		 * XXX: This is a horrible hack to make sure that randomizing the port
		 * doesn't break programs that might have (sad) hard-coded values for
		 * certain port names.
		 */
		if (at_start && total++ < NUM_SEQ_ENTRIES)
			which = 0;
		else
#endif
			which = random_bool_gen_bits(
						&space->bool_gen,
						&space->is_entropy[0],
						IS_ENTROPY_CNT,
						1);

		mach_port_index_t next;
		if (which) {
			next = top;
			top--;
		} else {
			next = bottom;
			bottom++;
		}

		/*
		 * The entry's gencount will roll over on its first allocation, at which
		 * point a random rollover will be set for the entry.
		 */
		entry->ie_bits = IE_BITS_GEN_MASK;
		entry->ie_next   = next;
		entry->ie_object = IO_NULL;
		entry->ie_index  = 0;
		curr = next;
	}
	table[curr].ie_next   = 0;
	table[curr].ie_object = IO_NULL;
	table[curr].ie_index  = 0;
	table[curr].ie_bits   = IE_BITS_GEN_MASK;

	/* The freelist head should always have generation number set to 0 */
	if (at_start) {
		table[0].ie_bits = 0;
	}
}

kern_return_t
ipc_space_create(
	ipc_table_size_t	initial,
	ipc_space_t		*spacep)
{
	ipc_space_t space;
	ipc_entry_t table;
	ipc_entry_num_t new_size;

	space = is_alloc();
	if (space == IS_NULL)
		return KERN_RESOURCE_SHORTAGE;

	table = it_entries_alloc(initial);
	if (table == IE_NULL) {
		is_free(space);
		return KERN_RESOURCE_SHORTAGE;
	}

	new_size = initial->its_size;
	memset((void *) table, 0, new_size * sizeof(struct ipc_entry));

	/* Set to 0 so entropy pool refills */
	memset((void *) space->is_entropy, 0, sizeof(space->is_entropy));

	random_bool_init(&space->bool_gen);
	ipc_space_rand_freelist(space, table, 0, new_size);

	is_lock_init(space);
	space->is_bits = 2; /* 2 refs, active, not growing */
	space->is_table_size = new_size;
	space->is_table_free = new_size - 1;
	space->is_table = table;
	space->is_table_next = initial+1;
	space->is_task = NULL;
	space->is_low_mod = new_size;
	space->is_high_mod = 0;
	space->is_node_id = HOST_LOCAL_NODE; /* HOST_LOCAL_NODE, except proxy spaces */

	*spacep = space;
	return KERN_SUCCESS;
}

kern_return_t
ipc_space_create_special(
	ipc_space_t	*spacep)
{
	ipc_space_t space;

	space = is_alloc();
	if (space == IS_NULL)
		return KERN_RESOURCE_SHORTAGE;

	is_lock_init(space);

	space->is_bits       = IS_INACTIVE | 1; /* 1 ref, not active, not growing */
	space->is_table      = IE_NULL;
	space->is_task       = TASK_NULL;
	space->is_table_next = 0;
	space->is_low_mod    = 0;
	space->is_high_mod   = 0;
	space->is_node_id = HOST_LOCAL_NODE; /* HOST_LOCAL_NODE, except proxy spaces */

	*spacep = space;
	return KERN_SUCCESS;
}

void
ipc_space_clean(
	ipc_space_t space)
{
	ipc_entry_t table;
	ipc_entry_num_t size;
	mach_port_index_t index;

	/*
	 *	If somebody is trying to grow the table,
	 *	we must wait until they finish and figure
	 *	out the space died.
	 */
 retry:
	is_write_lock(space);
	while (is_growing(space))
		is_write_sleep(space);

	if (!is_active(space)) {
		is_write_unlock(space);
		return;
	}

	/*
	 *	Now we can futz with it	since we have the write lock.
	 */

	table = space->is_table;
	size = space->is_table_size;

	for (index = 0; index < size; index++) {
		ipc_entry_t entry = &table[index];
		mach_port_type_t type;

		type = IE_BITS_TYPE(entry->ie_bits);
		if (type != MACH_PORT_TYPE_NONE) {
			mach_port_name_t name =	MACH_PORT_MAKE(index,
						IE_BITS_GEN(entry->ie_bits));
			ipc_right_destroy(space, name, entry, FALSE, 0); /* unlocks space */
			goto retry;
		}
	}

        /*
	 * JMM - Now the table is cleaned out.  We don't bother shrinking the
	 * size of the table at this point, but we probably should if it is
	 * really large.
	 */
	
	is_write_unlock(space);
}

void
ipc_space_terminate(
	ipc_space_t	space)
{
	ipc_entry_t table;
	ipc_entry_num_t size;
	mach_port_index_t index;

	assert(space != IS_NULL);

	is_write_lock(space);
	if (!is_active(space)) {
		is_write_unlock(space);
		return;
	}
	is_mark_inactive(space);

	/*
	 *	If somebody is trying to grow the table,
	 *	we must wait until they finish and figure
	 *	out the space died.
	 */
	while (is_growing(space))
		is_write_sleep(space);

	is_write_unlock(space);


	/*
	 *	Now we can futz with it	unlocked.
	 */

	table = space->is_table;
	size = space->is_table_size;

	for (index = 0; index < size; index++) {
		ipc_entry_t entry = &table[index];
		mach_port_type_t type;

		type = IE_BITS_TYPE(entry->ie_bits);
		if (type != MACH_PORT_TYPE_NONE) {
			mach_port_name_t name;

			name = MACH_PORT_MAKE(index,
					      IE_BITS_GEN(entry->ie_bits));
			ipc_right_terminate(space, name, entry);
		}
	}

	it_entries_free(space->is_table_next-1, table);
	space->is_table_size = 0;
	space->is_table_free = 0;

	/*
	 *	Because the space is now dead,
	 *	we must release the "active" reference for it.
	 *	Our caller still has his reference.
	 */
	is_release(space);
}

