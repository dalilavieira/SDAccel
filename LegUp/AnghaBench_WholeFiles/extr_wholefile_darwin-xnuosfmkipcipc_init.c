#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  vm_offset_t ;
struct ipc_space {int dummy; } ;
struct ipc_pset {int dummy; } ;
struct ipc_port {int dummy; } ;
typedef  scalar_t__ kern_return_t ;
struct TYPE_4__ {void* wait_for_space; void* no_zero_fill; } ;

/* Variables and functions */
 void* FALSE ; 
 int IKM_SAVED_KMSG_SIZE ; 
 size_t IOT_PORT ; 
 size_t IOT_PORT_SET ; 
 scalar_t__ KERN_SUCCESS ; 
 int MACH_PORT_QLIMIT_DEFAULT ; 
 scalar_t__ MSG_OOL_SIZE_SMALL_MAX ; 
 void* TRUE ; 
 int /*<<< orphan*/  VM_FLAGS_ANYWHERE ; 
 int /*<<< orphan*/  VM_KERN_MEMORY_IPC ; 
 int /*<<< orphan*/  VM_MAP_KERNEL_FLAGS_NONE ; 
 int /*<<< orphan*/  Z_CACHING_ENABLED ; 
 int /*<<< orphan*/  Z_CALLERACCT ; 
 int /*<<< orphan*/  Z_NOENCRYPT ; 
 int /*<<< orphan*/  assert (int) ; 
 scalar_t__ cpy_kdata_hdr_sz ; 
 int /*<<< orphan*/  host_notify_init () ; 
 int /*<<< orphan*/  ipc_host_init () ; 
 TYPE_1__* ipc_kernel_copy_map ; 
 int /*<<< orphan*/  ipc_kernel_copy_map_size ; 
 TYPE_1__* ipc_kernel_map ; 
 int /*<<< orphan*/  ipc_kernel_map_size ; 
 int /*<<< orphan*/  ipc_kmsg_zone ; 
 int /*<<< orphan*/  ipc_lck_attr ; 
 int /*<<< orphan*/  ipc_lck_grp ; 
 int /*<<< orphan*/  ipc_lck_grp_attr ; 
 int /*<<< orphan*/ * ipc_object_zones ; 
 int ipc_port_max ; 
 int /*<<< orphan*/  ipc_port_multiple_lock_init () ; 
 scalar_t__ ipc_port_timestamp_data ; 
 int ipc_pset_max ; 
 scalar_t__ ipc_space_create_special (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ipc_space_kernel ; 
 int ipc_space_max ; 
 int /*<<< orphan*/  ipc_space_reply ; 
 int /*<<< orphan*/  ipc_space_zone ; 
 int /*<<< orphan*/  ipc_table_init () ; 
 int /*<<< orphan*/  ipc_voucher_init () ; 
 scalar_t__ kalloc_max_prerounded ; 
 int /*<<< orphan*/  kernel_map ; 
 scalar_t__ kmem_suballoc (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,void*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_1__**) ; 
 int /*<<< orphan*/  lck_attr_setdefault (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lck_grp_attr_setdefault (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lck_grp_init (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mig_init () ; 
 int /*<<< orphan*/  mk_timer_init () ; 
 scalar_t__ msg_ool_size_small ; 
 int /*<<< orphan*/  panic (char*) ; 
 int /*<<< orphan*/  semaphore_init () ; 
 int /*<<< orphan*/  ux_handler_init () ; 
 int /*<<< orphan*/  zinit (int,int,int,char*) ; 
 int /*<<< orphan*/  zone_change (int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*) ; 

void
ipc_bootstrap(void)
{
	kern_return_t kr;
	
	lck_grp_attr_setdefault(&ipc_lck_grp_attr);
	lck_grp_init(&ipc_lck_grp, "ipc", &ipc_lck_grp_attr);
	lck_attr_setdefault(&ipc_lck_attr);
	
	ipc_port_multiple_lock_init();

	ipc_port_timestamp_data = 0;

	/* all IPC zones should be exhaustible */

	ipc_space_zone = zinit(sizeof(struct ipc_space),
			       ipc_space_max * sizeof(struct ipc_space),
			       sizeof(struct ipc_space),
			       "ipc spaces");
	zone_change(ipc_space_zone, Z_NOENCRYPT, TRUE);

	/*
	 * populate all port(set) zones
	 */
	ipc_object_zones[IOT_PORT] =
		zinit(sizeof(struct ipc_port),
		      ipc_port_max * sizeof(struct ipc_port),
		      sizeof(struct ipc_port),
		      "ipc ports");
	/* cant charge callers for port allocations (references passed) */
	zone_change(ipc_object_zones[IOT_PORT], Z_CALLERACCT, FALSE);
	zone_change(ipc_object_zones[IOT_PORT], Z_NOENCRYPT, TRUE);

	ipc_object_zones[IOT_PORT_SET] =
		zinit(sizeof(struct ipc_pset),
		      ipc_pset_max * sizeof(struct ipc_pset),
		      sizeof(struct ipc_pset),
		      "ipc port sets");
	zone_change(ipc_object_zones[IOT_PORT_SET], Z_NOENCRYPT, TRUE);

	/*
	 * Create the basic ipc_kmsg_t zone (the one we also cache)
	 * elements at the processor-level to avoid the locking.
	 */
	ipc_kmsg_zone = zinit(IKM_SAVED_KMSG_SIZE,
			      ipc_port_max * MACH_PORT_QLIMIT_DEFAULT *
			      IKM_SAVED_KMSG_SIZE,
			      IKM_SAVED_KMSG_SIZE,
			      "ipc kmsgs");
	zone_change(ipc_kmsg_zone, Z_CALLERACCT, FALSE);
	zone_change(ipc_kmsg_zone, Z_CACHING_ENABLED, TRUE);

	/* create special spaces */

	kr = ipc_space_create_special(&ipc_space_kernel);
	assert(kr == KERN_SUCCESS);


	kr = ipc_space_create_special(&ipc_space_reply);
	assert(kr == KERN_SUCCESS);

	/* initialize modules with hidden data structures */

#if	MACH_ASSERT
	ipc_port_debug_init();
#endif
	mig_init();
	ipc_table_init();
	ipc_voucher_init();

#if IMPORTANCE_INHERITANCE
	ipc_importance_init();
#endif

	semaphore_init();
	mk_timer_init();
	host_notify_init();
}

void
ipc_init(void)
{
	kern_return_t retval;
	vm_offset_t min;

	retval = kmem_suballoc(kernel_map, &min, ipc_kernel_map_size,
			       TRUE,
			       (VM_FLAGS_ANYWHERE),
			       VM_MAP_KERNEL_FLAGS_NONE,
			       VM_KERN_MEMORY_IPC,
			       &ipc_kernel_map);

	if (retval != KERN_SUCCESS)
		panic("ipc_init: kmem_suballoc of ipc_kernel_map failed");

	retval = kmem_suballoc(kernel_map, &min, ipc_kernel_copy_map_size,
			       TRUE,
			       (VM_FLAGS_ANYWHERE),
			       VM_MAP_KERNEL_FLAGS_NONE,
			       VM_KERN_MEMORY_IPC,
			       &ipc_kernel_copy_map);

	if (retval != KERN_SUCCESS)
		panic("ipc_init: kmem_suballoc of ipc_kernel_copy_map failed");

	ipc_kernel_copy_map->no_zero_fill = TRUE;
	ipc_kernel_copy_map->wait_for_space = TRUE;

	/*
	 * As an optimization, 'small' out of line data regions using a 
	 * physical copy strategy are copied into kalloc'ed buffers.
	 * The value of 'small' is determined here.  Requests kalloc()
	 * with sizes greater or equal to kalloc_max_prerounded may fail.
	 */
	if (kalloc_max_prerounded <=  MSG_OOL_SIZE_SMALL_MAX) {
		msg_ool_size_small = kalloc_max_prerounded;
	}
	else {
		msg_ool_size_small = MSG_OOL_SIZE_SMALL_MAX;
	}
	/* account for overhead to avoid spilling over a page */
	msg_ool_size_small -= cpy_kdata_hdr_sz;

	ipc_host_init();
	ux_handler_init();

}

void
ipc_thread_call_init(void)
{
#if IMPORTANCE_INHERITANCE
	ipc_importance_thread_call_init();
#endif
}

