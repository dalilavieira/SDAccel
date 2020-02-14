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
typedef  int /*<<< orphan*/  uint64_t ;
typedef  int thread_destruct_special_reply_port_rights_t ;
typedef  int /*<<< orphan*/  natural_t ;
typedef  int /*<<< orphan*/  mach_voucher_attr_raw_recipe_t ;
typedef  int /*<<< orphan*/  mach_voucher_attr_key_t ;
typedef  scalar_t__ mach_vm_address_t ;
typedef  int /*<<< orphan*/  mach_port_urefs_t ;
typedef  int /*<<< orphan*/  mach_port_type_t ;
typedef  int /*<<< orphan*/  mach_port_type_array_t ;
typedef  scalar_t__ mach_port_t ;
typedef  int /*<<< orphan*/  mach_port_seqno_t ;
typedef  int /*<<< orphan*/  mach_port_rights_t ;
typedef  int /*<<< orphan*/  mach_port_right_t ;
typedef  int /*<<< orphan*/  mach_port_qos_t ;
typedef  int /*<<< orphan*/  mach_port_options_t ;
typedef  scalar_t__ mach_port_name_t ;
typedef  int /*<<< orphan*/  mach_port_name_array_t ;
typedef  int /*<<< orphan*/  mach_port_mscount_t ;
typedef  int /*<<< orphan*/  mach_port_info_t ;
typedef  int /*<<< orphan*/  mach_port_flavor_t ;
typedef  int mach_port_delta_t ;
typedef  scalar_t__ mach_port_context_t ;
typedef  int /*<<< orphan*/  mach_msg_type_number_t ;
typedef  int /*<<< orphan*/  mach_msg_type_name_t ;
typedef  int /*<<< orphan*/  mach_msg_trailer_type_t ;
typedef  int /*<<< orphan*/  mach_msg_trailer_info_t ;
typedef  int /*<<< orphan*/  mach_msg_size_t ;
typedef  int /*<<< orphan*/  mach_msg_id_t ;
typedef  int kern_return_t ;
typedef  int /*<<< orphan*/  ipc_space_t ;
typedef  int /*<<< orphan*/  ipc_info_tree_name_array_t ;
typedef  int /*<<< orphan*/  ipc_info_space_t ;
typedef  int /*<<< orphan*/  ipc_info_space_basic_t ;
typedef  int /*<<< orphan*/  ipc_info_name_array_t ;
typedef  int boolean_t ;

/* Variables and functions */
 int KERN_INVALID_ARGUMENT ; 
 int KERN_SUCCESS ; 
 scalar_t__ MACH_PORT_DEAD ; 
 scalar_t__ MACH_PORT_NULL ; 
 int /*<<< orphan*/  MACH_PORT_RIGHT_SEND ; 
 scalar_t__ MACH_PORT_VALID (scalar_t__) ; 
 int MACH_SEND_INVALID_DEST ; 
#define  THREAD_SPECIAL_REPLY_PORT_ALL 130 
#define  THREAD_SPECIAL_REPLY_PORT_RECEIVE_ONLY 129 
#define  THREAD_SPECIAL_REPLY_PORT_SEND_ONLY 128 
 int TRUE ; 
 int /*<<< orphan*/  __TSD_MACH_SPECIAL_REPLY ; 
 int _kernelrpc_mach_port_allocate (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__*) ; 
 int _kernelrpc_mach_port_allocate_full (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ *,scalar_t__*) ; 
 int _kernelrpc_mach_port_allocate_name (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__) ; 
 int _kernelrpc_mach_port_allocate_qos (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,scalar_t__*) ; 
 int _kernelrpc_mach_port_allocate_trap (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__*) ; 
 int _kernelrpc_mach_port_construct (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,scalar_t__*) ; 
 int _kernelrpc_mach_port_construct_trap (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,scalar_t__*) ; 
 int _kernelrpc_mach_port_deallocate (int /*<<< orphan*/ ,scalar_t__) ; 
 int _kernelrpc_mach_port_deallocate_trap (int /*<<< orphan*/ ,scalar_t__) ; 
 int _kernelrpc_mach_port_destroy (int /*<<< orphan*/ ,scalar_t__) ; 
 int _kernelrpc_mach_port_destroy_trap (int /*<<< orphan*/ ,scalar_t__) ; 
 int _kernelrpc_mach_port_destruct (int /*<<< orphan*/ ,scalar_t__,int,int /*<<< orphan*/ ) ; 
 int _kernelrpc_mach_port_destruct_trap (int /*<<< orphan*/ ,scalar_t__,int,int /*<<< orphan*/ ) ; 
 int _kernelrpc_mach_port_dnrequest_info (int /*<<< orphan*/ ,scalar_t__,unsigned int*,unsigned int*) ; 
 int _kernelrpc_mach_port_extract_member (int /*<<< orphan*/ ,scalar_t__,scalar_t__) ; 
 int _kernelrpc_mach_port_extract_member_trap (int /*<<< orphan*/ ,scalar_t__,scalar_t__) ; 
 int _kernelrpc_mach_port_extract_right (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ,scalar_t__*,int /*<<< orphan*/ *) ; 
 int _kernelrpc_mach_port_get_attributes (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int _kernelrpc_mach_port_get_attributes_trap (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int _kernelrpc_mach_port_get_context (int /*<<< orphan*/ ,scalar_t__,scalar_t__*) ; 
 int _kernelrpc_mach_port_get_refs (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int _kernelrpc_mach_port_get_set_status (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int _kernelrpc_mach_port_get_srights (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ *) ; 
 int _kernelrpc_mach_port_guard (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ,int) ; 
 int _kernelrpc_mach_port_guard_trap (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ,int) ; 
 int _kernelrpc_mach_port_insert_member (int /*<<< orphan*/ ,scalar_t__,scalar_t__) ; 
 int _kernelrpc_mach_port_insert_member_trap (int /*<<< orphan*/ ,scalar_t__,scalar_t__) ; 
 int _kernelrpc_mach_port_insert_right (int /*<<< orphan*/ ,scalar_t__,scalar_t__,int /*<<< orphan*/ ) ; 
 int _kernelrpc_mach_port_insert_right_trap (int /*<<< orphan*/ ,scalar_t__,scalar_t__,int /*<<< orphan*/ ) ; 
 int _kernelrpc_mach_port_kernel_object (int /*<<< orphan*/ ,scalar_t__,unsigned int*,unsigned int*) ; 
 int _kernelrpc_mach_port_kobject (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ *,scalar_t__*) ; 
 int _kernelrpc_mach_port_mod_refs (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ,int) ; 
 int _kernelrpc_mach_port_mod_refs_trap (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ,int) ; 
 int _kernelrpc_mach_port_move_member (int /*<<< orphan*/ ,scalar_t__,scalar_t__) ; 
 int _kernelrpc_mach_port_move_member_trap (int /*<<< orphan*/ ,scalar_t__,scalar_t__) ; 
 int _kernelrpc_mach_port_names (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int _kernelrpc_mach_port_peek (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int _kernelrpc_mach_port_rename (int /*<<< orphan*/ ,scalar_t__,scalar_t__) ; 
 int _kernelrpc_mach_port_request_notification (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ,scalar_t__*) ; 
 int _kernelrpc_mach_port_set_attributes (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int _kernelrpc_mach_port_set_context (int /*<<< orphan*/ ,scalar_t__,scalar_t__) ; 
 int _kernelrpc_mach_port_set_mscount (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ) ; 
 int _kernelrpc_mach_port_set_seqno (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ) ; 
 int _kernelrpc_mach_port_space_basic_info (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int _kernelrpc_mach_port_space_info (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int _kernelrpc_mach_port_special_reply_port_reset_link (int /*<<< orphan*/ ,scalar_t__,int*) ; 
 int _kernelrpc_mach_port_type (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ *) ; 
 int _kernelrpc_mach_port_unguard (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ) ; 
 int _kernelrpc_mach_port_unguard_trap (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ) ; 
 int _kernelrpc_mach_voucher_extract_attr_recipe (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int _kernelrpc_task_set_port_space (int /*<<< orphan*/ ,int) ; 
 scalar_t__ _os_tsd_get_direct (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  _os_tsd_set_direct (int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  mach_task_self () ; 
 int mach_voucher_extract_attr_recipe_trap (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int thread_destruct_special_reply_port (scalar_t__,int) ; 
 scalar_t__ thread_get_special_reply_port () ; 

kern_return_t
mach_port_names(
	ipc_space_t task,
	mach_port_name_array_t *names,
	mach_msg_type_number_t *namesCnt,
	mach_port_type_array_t *types,
	mach_msg_type_number_t *typesCnt)
{
	kern_return_t rv;

	rv = _kernelrpc_mach_port_names(task, names, namesCnt, types,
			typesCnt);

	return (rv);
}

kern_return_t
mach_port_type(
	ipc_space_t task,
	mach_port_name_t name,
	mach_port_type_t *ptype)
{
	kern_return_t rv;

	rv = _kernelrpc_mach_port_type(task, name, ptype);

	return (rv);
}

kern_return_t
mach_port_rename(
	ipc_space_t task,
	mach_port_name_t old_name,
	mach_port_name_t new_name)
{
	kern_return_t rv;

	rv = _kernelrpc_mach_port_rename(task, old_name, new_name);

	return (rv);
}

kern_return_t
mach_port_allocate_name(
	ipc_space_t task,
	mach_port_right_t right,
	mach_port_name_t name)
{
	kern_return_t rv;

	rv = _kernelrpc_mach_port_allocate_name(task, right, name);

	return (rv);
}

kern_return_t
mach_port_allocate(
	ipc_space_t task,
	mach_port_right_t right,
	mach_port_name_t *name)
{
	kern_return_t rv;

	rv = _kernelrpc_mach_port_allocate_trap(task, right, name);

	if (rv == MACH_SEND_INVALID_DEST)
		rv = _kernelrpc_mach_port_allocate(task, right, name);

	return (rv);
}

kern_return_t
mach_port_destroy(
	ipc_space_t task,
	mach_port_name_t name)
{
	kern_return_t rv;

	rv = _kernelrpc_mach_port_destroy_trap(task, name);

	if (rv == MACH_SEND_INVALID_DEST)
		rv = _kernelrpc_mach_port_destroy(task, name);

	return (rv);
}

kern_return_t
mach_port_deallocate(
	ipc_space_t task,
	mach_port_name_t name)
{
	kern_return_t rv;

	rv = _kernelrpc_mach_port_deallocate_trap(task, name); 

	if (rv == MACH_SEND_INVALID_DEST)
		rv = _kernelrpc_mach_port_deallocate(task,name);

	return (rv);
}

kern_return_t
mach_port_get_refs(
	ipc_space_t task,
	mach_port_name_t name,
	mach_port_right_t right,
	mach_port_urefs_t *refs)
{
	kern_return_t rv;

	rv = _kernelrpc_mach_port_get_refs(task, name, right, refs);

	return (rv);
}

kern_return_t
mach_port_mod_refs(
	ipc_space_t task,
	mach_port_name_t name,
	mach_port_right_t right,
	mach_port_delta_t delta)
{
	kern_return_t rv;

	rv = _kernelrpc_mach_port_mod_refs_trap(task, name, right, delta); 

	if (rv == MACH_SEND_INVALID_DEST)
		rv = _kernelrpc_mach_port_mod_refs(task, name, right, delta);

	return (rv);
}

kern_return_t
mach_port_peek(
	ipc_space_t		task,
	mach_port_name_t	name,
	mach_msg_trailer_type_t trailer_type,
	mach_port_seqno_t	*seqnop,
	mach_msg_size_t		*msg_sizep,
	mach_msg_id_t		*msg_idp,
	mach_msg_trailer_info_t trailer_infop,
	mach_msg_type_number_t	*trailer_sizep)
{
	kern_return_t rv;

	rv = _kernelrpc_mach_port_peek(task, name, trailer_type, 
				       seqnop, msg_sizep, msg_idp,
				       trailer_infop, trailer_sizep);

	return (rv);
}

kern_return_t
mach_port_set_mscount(
	ipc_space_t task,
	mach_port_name_t name,
	mach_port_mscount_t mscount)
{
	kern_return_t rv;

	rv = _kernelrpc_mach_port_set_mscount(task, name, mscount);

	return (rv);
}

kern_return_t
mach_port_get_set_status(
	ipc_space_t task,
	mach_port_name_t name,
	mach_port_name_array_t *members,
	mach_msg_type_number_t *membersCnt)
{
	kern_return_t rv;

	rv = _kernelrpc_mach_port_get_set_status(task, name, members,
			membersCnt);

	return (rv);
}

kern_return_t
mach_port_move_member(
	ipc_space_t task,
	mach_port_name_t member,
	mach_port_name_t after)
{
	kern_return_t rv;

	rv = _kernelrpc_mach_port_move_member_trap(task, member, after);

	if (rv == MACH_SEND_INVALID_DEST)
		rv = _kernelrpc_mach_port_move_member(task, member, after);

	return (rv);
}

kern_return_t
mach_port_request_notification(
	ipc_space_t task,
	mach_port_name_t name,
	mach_msg_id_t msgid,
	mach_port_mscount_t sync,
	mach_port_t notify,
	mach_msg_type_name_t notifyPoly,
	mach_port_t *previous)
{
	kern_return_t rv;

	rv = _kernelrpc_mach_port_request_notification(task, name, msgid,
		sync, notify, notifyPoly, previous);

	return (rv);
}

kern_return_t
mach_port_insert_right(
	ipc_space_t task,
	mach_port_name_t name,
	mach_port_t poly,
	mach_msg_type_name_t polyPoly)
{
	kern_return_t rv;

	rv = _kernelrpc_mach_port_insert_right_trap(task, name, poly, polyPoly); 

	if (rv == MACH_SEND_INVALID_DEST)
		rv = _kernelrpc_mach_port_insert_right(task, name, poly,
		    polyPoly);

	return (rv);
}

kern_return_t
mach_port_extract_right(
	ipc_space_t task,
	mach_port_name_t name,
	mach_msg_type_name_t msgt_name,
	mach_port_t *poly,
	mach_msg_type_name_t *polyPoly)
{
	kern_return_t rv;

	rv = _kernelrpc_mach_port_extract_right(task, name, msgt_name,
		poly, polyPoly);

	return (rv);
}

kern_return_t
mach_port_set_seqno(
	ipc_space_t task,
	mach_port_name_t name,
	mach_port_seqno_t seqno)
{
	kern_return_t rv;

	rv = _kernelrpc_mach_port_set_seqno(task, name, seqno);

	return (rv);
}

kern_return_t
mach_port_get_attributes(
	ipc_space_t task,
	mach_port_name_t name,
	mach_port_flavor_t flavor,
	mach_port_info_t port_info_out,
	mach_msg_type_number_t *port_info_outCnt)
{
	kern_return_t rv;

	rv = _kernelrpc_mach_port_get_attributes_trap(task, name, flavor,
			port_info_out, port_info_outCnt);

#ifdef __x86_64__
	/* REMOVE once XBS kernel has new trap */
	if (rv == ((1 << 24) | 40)) /* see mach/i386/syscall_sw.h */
		rv = MACH_SEND_INVALID_DEST;
#elif defined(__i386__)
	/* REMOVE once XBS kernel has new trap */
	if (rv == (kern_return_t)(-40))
		rv = MACH_SEND_INVALID_DEST;
#endif

	if (rv == MACH_SEND_INVALID_DEST)
		rv = _kernelrpc_mach_port_get_attributes(task, name, flavor,
				port_info_out, port_info_outCnt);

	return (rv);
}

kern_return_t
mach_port_set_attributes(
	ipc_space_t task,
	mach_port_name_t name,
	mach_port_flavor_t flavor,
	mach_port_info_t port_info,
	mach_msg_type_number_t port_infoCnt)
{
	kern_return_t rv;

	rv = _kernelrpc_mach_port_set_attributes(task, name, flavor,
			port_info, port_infoCnt);

	return (rv);
}

kern_return_t
mach_port_allocate_qos(
	ipc_space_t task,
	mach_port_right_t right,
	mach_port_qos_t *qos,
	mach_port_name_t *name)
{
	kern_return_t rv;

	rv = _kernelrpc_mach_port_allocate_qos(task, right, qos, name);

	return (rv);
}

kern_return_t
mach_port_allocate_full(
	ipc_space_t task,
	mach_port_right_t right,
	mach_port_t proto,
	mach_port_qos_t *qos,
	mach_port_name_t *name)
{
	kern_return_t rv;

	rv = _kernelrpc_mach_port_allocate_full(task, right, proto, qos, name);

	return (rv);
}

kern_return_t
task_set_port_space(
	ipc_space_t task,
	int table_entries)
{
	kern_return_t rv;

	rv = _kernelrpc_task_set_port_space(task, table_entries);

	return (rv);
}

kern_return_t
mach_port_get_srights(
	ipc_space_t task,
	mach_port_name_t name,
	mach_port_rights_t *srights)
{
	kern_return_t rv;

	rv = _kernelrpc_mach_port_get_srights(task, name, srights);

	return (rv);
}

kern_return_t
mach_port_space_info(
	ipc_space_t task,
	ipc_info_space_t *space_info,
	ipc_info_name_array_t *table_info,
	mach_msg_type_number_t *table_infoCnt,
	ipc_info_tree_name_array_t *tree_info,
	mach_msg_type_number_t *tree_infoCnt)
{
	kern_return_t rv;

	rv = _kernelrpc_mach_port_space_info(task, space_info, table_info,
			table_infoCnt, tree_info, tree_infoCnt);

	return (rv);
}

kern_return_t
mach_port_space_basic_info(
	ipc_space_t task,
	ipc_info_space_basic_t *space_basic_info)
{
	kern_return_t rv;

	rv = _kernelrpc_mach_port_space_basic_info(task, space_basic_info);

	return (rv);
}

__attribute__((used)) static inline mach_port_t
_tsd_get_special_reply_port()
{
	return (mach_port_t)(uintptr_t)_os_tsd_get_direct(__TSD_MACH_SPECIAL_REPLY);
}

__attribute__((used)) static inline void
_tsd_set_special_reply_port(mach_port_t port)
{
	_os_tsd_set_direct(__TSD_MACH_SPECIAL_REPLY, (void *)(uintptr_t)port);
}

mach_port_t
mig_get_special_reply_port(void)
{
	mach_port_t srp;

	srp = _tsd_get_special_reply_port();
	if (!MACH_PORT_VALID(srp)) {
		srp = thread_get_special_reply_port();
		_tsd_set_special_reply_port(srp);
	}

	return srp;
}

void
mig_dealloc_special_reply_port(mach_port_t migport)
{
	mach_port_t srp = _tsd_get_special_reply_port();
	if (MACH_PORT_VALID(srp)) {
		thread_destruct_special_reply_port(srp, THREAD_SPECIAL_REPLY_PORT_ALL);
		if (migport != srp) {
			mach_port_deallocate(mach_task_self(), migport);
		}
		_tsd_set_special_reply_port(MACH_PORT_NULL);
	}
}

kern_return_t
mach_sync_ipc_link_monitoring_start(mach_port_t *special_reply_port)
{
	mach_port_t srp;
	boolean_t link_broken;
	kern_return_t kr;

	*special_reply_port = MACH_PORT_DEAD;

	srp = mig_get_special_reply_port();

	kr = mach_port_mod_refs(mach_task_self(), srp, MACH_PORT_RIGHT_SEND, 1);

	if (kr != KERN_SUCCESS) {
		return kr;
	}

	kr = _kernelrpc_mach_port_special_reply_port_reset_link(mach_task_self(), srp, &link_broken);
	if (kr != KERN_SUCCESS) {
		mach_port_deallocate(mach_task_self(), srp);
		return kr;
	}

	*special_reply_port = srp;

	return kr;
}

kern_return_t
mach_sync_ipc_link_monitoring_stop(mach_port_t srp, boolean_t* in_effect)
{
	kern_return_t kr;
	boolean_t link_broken = TRUE;

	kr = _kernelrpc_mach_port_special_reply_port_reset_link(mach_task_self(), srp, &link_broken);

	/*
	 * We return if the sync IPC priority inversion avoidance facility took
	 * effect, so if the link was broken it didn't take effect.
	 * Flip the return.
	 */
	*in_effect = !link_broken;

	mach_port_deallocate(mach_task_self(), srp);

	return kr;
}

kern_return_t
mach_port_dnrequest_info(
	ipc_space_t task,
	mach_port_name_t name,
	unsigned *dnr_total,
	unsigned *dnr_used)
{
	kern_return_t rv;

	rv = _kernelrpc_mach_port_dnrequest_info(task, name, dnr_total,
			dnr_used);

	return (rv);
}

kern_return_t
mach_port_kernel_object(
	ipc_space_t task,
	mach_port_name_t name,
	unsigned *object_type,
	unsigned *object_addr)
{
	kern_return_t rv;

	rv = _kernelrpc_mach_port_kernel_object(task, name,
			object_type, object_addr);

	return (rv);
}

kern_return_t
mach_port_insert_member(
	ipc_space_t task,
	mach_port_name_t name,
	mach_port_name_t pset)
{
	kern_return_t rv;

	rv = _kernelrpc_mach_port_insert_member_trap(task, name, pset);

	if (rv == MACH_SEND_INVALID_DEST)
		rv = _kernelrpc_mach_port_insert_member(task, name, pset);

	return (rv);
}

kern_return_t
mach_port_extract_member(
	ipc_space_t task,
	mach_port_name_t name,
	mach_port_name_t pset)
{
	kern_return_t rv;

	rv = _kernelrpc_mach_port_extract_member_trap(task, name, pset); 

	if (rv == MACH_SEND_INVALID_DEST)
		rv = _kernelrpc_mach_port_extract_member(task, name, pset);

	return (rv);
}

kern_return_t
mach_port_get_context(
	ipc_space_t task,
	mach_port_name_t name,
	mach_port_context_t *context)
{
	kern_return_t rv;
	mach_vm_address_t wide_context;

	rv = _kernelrpc_mach_port_get_context(task, name, &wide_context);

	if (rv == KERN_SUCCESS) {
		*context = (mach_port_context_t)wide_context;
	}

	return (rv);
}

kern_return_t
mach_port_set_context(
	ipc_space_t task,
	mach_port_name_t name,
	mach_port_context_t context)
{
	kern_return_t rv;

	rv = _kernelrpc_mach_port_set_context(task, name, context);

	return (rv);
}

kern_return_t
mach_port_kobject(
	ipc_space_t task,
	mach_port_name_t name,
	natural_t *object_type,
	mach_vm_address_t *object_addr)
{
	kern_return_t rv;

	rv = _kernelrpc_mach_port_kobject(task, name, object_type, object_addr);

	return (rv);
}

kern_return_t
mach_port_construct(
	ipc_space_t		task,
	mach_port_options_t	*options,
	mach_port_context_t	context,
	mach_port_name_t	*name)
{
	kern_return_t rv;

	rv = _kernelrpc_mach_port_construct_trap(task, options, (uint64_t) context, name);

	if (rv == MACH_SEND_INVALID_DEST)
		rv = _kernelrpc_mach_port_construct(task, options, (uint64_t) context, name);

	return (rv);
}

kern_return_t
mach_port_destruct(
	ipc_space_t		task,
	mach_port_name_t	name,
	mach_port_delta_t	srdelta,
	mach_port_context_t	guard)
{
	kern_return_t rv;

	rv = _kernelrpc_mach_port_destruct_trap(task, name, srdelta, (uint64_t) guard);

	if (rv == MACH_SEND_INVALID_DEST)
		rv = _kernelrpc_mach_port_destruct(task, name, srdelta, (uint64_t) guard);

	return (rv);

}

kern_return_t
mach_port_guard(
	ipc_space_t		task,
	mach_port_name_t	name,
	mach_port_context_t	guard,
	boolean_t		strict)
{
	kern_return_t rv;

	rv = _kernelrpc_mach_port_guard_trap(task, name, (uint64_t) guard, strict);

	if (rv == MACH_SEND_INVALID_DEST)
		rv = _kernelrpc_mach_port_guard(task, name, (uint64_t) guard, strict);

	return (rv);

}

kern_return_t
mach_port_unguard(
	ipc_space_t		task,
	mach_port_name_t	name,
	mach_port_context_t	guard)
{
	kern_return_t rv;

	rv = _kernelrpc_mach_port_unguard_trap(task, name, (uint64_t) guard);

	if (rv == MACH_SEND_INVALID_DEST)
		rv = _kernelrpc_mach_port_unguard(task, name, (uint64_t) guard);

	return (rv);

}

kern_return_t
mach_voucher_extract_attr_recipe(
	mach_port_name_t voucher,
	mach_voucher_attr_key_t key,
	mach_voucher_attr_raw_recipe_t recipe,
	mach_msg_type_number_t *recipe_size)
{
	kern_return_t rv;

	rv = mach_voucher_extract_attr_recipe_trap(voucher, key, recipe, recipe_size);

	if (rv == MACH_SEND_INVALID_DEST)
		rv = _kernelrpc_mach_voucher_extract_attr_recipe(voucher, key, recipe, recipe_size);

	return rv;
}

kern_return_t
thread_destruct_special_reply_port(
		mach_port_name_t port,
		thread_destruct_special_reply_port_rights_t rights)
{
	switch (rights) {
	case THREAD_SPECIAL_REPLY_PORT_ALL:
		return mach_port_destruct(mach_task_self(), port, -1, 0);

	case THREAD_SPECIAL_REPLY_PORT_RECEIVE_ONLY:
		return mach_port_destruct(mach_task_self(), port, 0, 0);

	case THREAD_SPECIAL_REPLY_PORT_SEND_ONLY:
		return mach_port_deallocate(mach_task_self(), port);

	default:
		return KERN_INVALID_ARGUMENT;
	}
}

