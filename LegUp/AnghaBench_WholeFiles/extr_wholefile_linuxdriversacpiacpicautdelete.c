#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_40__   TYPE_9__ ;
typedef  struct TYPE_39__   TYPE_8__ ;
typedef  struct TYPE_38__   TYPE_7__ ;
typedef  struct TYPE_37__   TYPE_6__ ;
typedef  struct TYPE_36__   TYPE_5__ ;
typedef  struct TYPE_35__   TYPE_4__ ;
typedef  struct TYPE_34__   TYPE_3__ ;
typedef  struct TYPE_33__   TYPE_2__ ;
typedef  struct TYPE_32__   TYPE_20__ ;
typedef  struct TYPE_31__   TYPE_1__ ;
typedef  struct TYPE_30__   TYPE_19__ ;
typedef  struct TYPE_29__   TYPE_18__ ;
typedef  struct TYPE_28__   TYPE_17__ ;
typedef  struct TYPE_27__   TYPE_16__ ;
typedef  struct TYPE_26__   TYPE_15__ ;
typedef  struct TYPE_25__   TYPE_14__ ;
typedef  struct TYPE_24__   TYPE_13__ ;
typedef  struct TYPE_23__   TYPE_12__ ;
typedef  struct TYPE_22__   TYPE_11__ ;
typedef  struct TYPE_21__   TYPE_10__ ;

/* Type definitions */
struct TYPE_25__ {int type; int flags; scalar_t__ reference_count; } ;
struct TYPE_22__ {union acpi_operand_object* object; int /*<<< orphan*/  class; } ;
struct TYPE_21__ {union acpi_operand_object* data_obj; union acpi_operand_object* index_obj; } ;
struct TYPE_40__ {union acpi_operand_object* region_obj; union acpi_operand_object* bank_obj; } ;
struct TYPE_39__ {union acpi_operand_object* region_obj; } ;
struct TYPE_38__ {union acpi_operand_object* buffer_obj; } ;
struct TYPE_27__ {int count; union acpi_operand_object** elements; } ;
struct TYPE_37__ {union acpi_operand_object** next; } ;
struct TYPE_29__ {union acpi_operand_object** notify_list; union acpi_operand_object* handler; } ;
struct TYPE_36__ {int /*<<< orphan*/  region_context; } ;
struct TYPE_30__ {int handler_flags; int /*<<< orphan*/  context; int /*<<< orphan*/  (* setup ) (union acpi_operand_object*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ;union acpi_operand_object* region_list; union acpi_operand_object* next; } ;
struct TYPE_35__ {union acpi_operand_object* next; union acpi_operand_object* handler; TYPE_20__* node; int /*<<< orphan*/  space_id; } ;
struct TYPE_34__ {int /*<<< orphan*/ * node; union acpi_operand_object* mutex; } ;
struct TYPE_33__ {int /*<<< orphan*/  os_mutex; } ;
struct TYPE_31__ {int /*<<< orphan*/ * os_semaphore; } ;
struct TYPE_28__ {int /*<<< orphan*/  gpe_block; } ;
struct TYPE_26__ {void* pointer; } ;
struct TYPE_24__ {void* pointer; } ;
union acpi_operand_object {TYPE_14__ common; TYPE_11__ reference; TYPE_10__ index_field; TYPE_9__ bank_field; TYPE_8__ field; TYPE_7__ buffer_field; TYPE_16__ package; TYPE_6__ notify; TYPE_18__ common_notify; TYPE_5__ extra; TYPE_19__ address_space; TYPE_4__ region; TYPE_3__ method; TYPE_2__ mutex; TYPE_1__ event; TYPE_17__ device; TYPE_15__ buffer; TYPE_13__ string; } ;
struct TYPE_23__ {union acpi_operand_object* object; } ;
union acpi_generic_state {TYPE_12__ update; } ;
typedef  int u32 ;
typedef  scalar_t__ u16 ;
typedef  void* acpi_status ;
typedef  int /*<<< orphan*/  acpi_cpu_flags ;
struct TYPE_32__ {int flags; } ;

/* Variables and functions */
 int ACPI_ADDR_HANDLER_DEFAULT_INSTALLED ; 
 int /*<<< orphan*/  ACPI_DB_ALLOCATIONS ; 
 int /*<<< orphan*/  ACPI_DEBUG_PRINT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_DEBUG_PRINT_RAW (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_DESC_TYPE_NAMED ; 
 int /*<<< orphan*/  ACPI_ERROR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_EXCEPTION (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FAILURE (void*) ; 
 int /*<<< orphan*/  ACPI_FREE (union acpi_operand_object**) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_ENTRY () ; 
 int /*<<< orphan*/  ACPI_FUNCTION_NAME (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_TRACE_PTR (int /*<<< orphan*/ ,union acpi_operand_object*) ; 
 scalar_t__ ACPI_GET_DESCRIPTOR_TYPE (union acpi_operand_object*) ; 
 int /*<<< orphan*/  ACPI_GET_FUNCTION_NAME ; 
 scalar_t__ ACPI_MAX_REFERENCE_COUNT ; 
 int ACPI_NUM_NOTIFY_TYPES ; 
 int /*<<< orphan*/  ACPI_REFCLASS_INDEX ; 
 int /*<<< orphan*/  ACPI_REFCLASS_NAME ; 
 int /*<<< orphan*/  ACPI_REGION_DEACTIVATE ; 
#define  ACPI_TYPE_BUFFER 146 
#define  ACPI_TYPE_BUFFER_FIELD 145 
#define  ACPI_TYPE_DEVICE 144 
#define  ACPI_TYPE_EVENT 143 
#define  ACPI_TYPE_INTEGER 142 
#define  ACPI_TYPE_LOCAL_BANK_FIELD 141 
#define  ACPI_TYPE_LOCAL_INDEX_FIELD 140 
#define  ACPI_TYPE_LOCAL_REFERENCE 139 
#define  ACPI_TYPE_LOCAL_REGION_FIELD 138 
#define  ACPI_TYPE_METHOD 137 
#define  ACPI_TYPE_MUTEX 136 
#define  ACPI_TYPE_PACKAGE 135 
#define  ACPI_TYPE_POWER 134 
#define  ACPI_TYPE_PROCESSOR 133 
#define  ACPI_TYPE_REGION 132 
#define  ACPI_TYPE_STRING 131 
#define  ACPI_TYPE_THERMAL 130 
 int /*<<< orphan*/  ACPI_WARNING (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AE_INFO ; 
 void* AE_OK ; 
 int ANOBJ_TEMPORARY ; 
 int AOPOBJ_STATIC_POINTER ; 
#define  REF_DECREMENT 129 
#define  REF_INCREMENT 128 
 int /*<<< orphan*/  acpi_ev_delete_gpe_block (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  acpi_ex_unlink_mutex (union acpi_operand_object*) ; 
 union acpi_operand_object* acpi_gbl_global_lock_mutex ; 
 int /*<<< orphan*/ * acpi_gbl_global_lock_semaphore ; 
 int /*<<< orphan*/  acpi_gbl_reference_count_lock ; 
 union acpi_operand_object* acpi_ns_get_secondary_object (union acpi_operand_object*) ; 
 int /*<<< orphan*/  acpi_os_acquire_lock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  acpi_os_delete_mutex (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  acpi_os_delete_semaphore (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  acpi_os_release_lock (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 void* acpi_ut_create_update_state_and_push (union acpi_operand_object*,scalar_t__,union acpi_generic_state**) ; 
 int /*<<< orphan*/  acpi_ut_delete_generic_state (union acpi_generic_state*) ; 
 int /*<<< orphan*/  acpi_ut_delete_object_desc (union acpi_operand_object*) ; 
 int /*<<< orphan*/  acpi_ut_get_object_type_name (union acpi_operand_object*) ; 
 union acpi_generic_state* acpi_ut_pop_generic_state (union acpi_generic_state**) ; 
 int /*<<< orphan*/  acpi_ut_remove_address_range (int /*<<< orphan*/ ,TYPE_20__*) ; 
 void acpi_ut_remove_reference (union acpi_operand_object*) ; 
 int /*<<< orphan*/  acpi_ut_valid_internal_object (union acpi_operand_object*) ; 
 int /*<<< orphan*/  return_VOID ; 
 int /*<<< orphan*/  stub1 (union acpi_operand_object*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ut_add_reference ; 
 int /*<<< orphan*/  ut_delete_internal_obj ; 
 int /*<<< orphan*/  ut_remove_reference ; 
 int /*<<< orphan*/  ut_update_object_reference ; 
 int /*<<< orphan*/  ut_update_ref_count ; 

__attribute__((used)) static void acpi_ut_delete_internal_obj(union acpi_operand_object *object)
{
	void *obj_pointer = NULL;
	union acpi_operand_object *handler_desc;
	union acpi_operand_object *second_desc;
	union acpi_operand_object *next_desc;
	union acpi_operand_object *start_desc;
	union acpi_operand_object **last_obj_ptr;

	ACPI_FUNCTION_TRACE_PTR(ut_delete_internal_obj, object);

	if (!object) {
		return_VOID;
	}

	/*
	 * Must delete or free any pointers within the object that are not
	 * actual ACPI objects (for example, a raw buffer pointer).
	 */
	switch (object->common.type) {
	case ACPI_TYPE_STRING:

		ACPI_DEBUG_PRINT((ACPI_DB_ALLOCATIONS,
				  "**** String %p, ptr %p\n", object,
				  object->string.pointer));

		/* Free the actual string buffer */

		if (!(object->common.flags & AOPOBJ_STATIC_POINTER)) {

			/* But only if it is NOT a pointer into an ACPI table */

			obj_pointer = object->string.pointer;
		}
		break;

	case ACPI_TYPE_BUFFER:

		ACPI_DEBUG_PRINT((ACPI_DB_ALLOCATIONS,
				  "**** Buffer %p, ptr %p\n", object,
				  object->buffer.pointer));

		/* Free the actual buffer */

		if (!(object->common.flags & AOPOBJ_STATIC_POINTER)) {

			/* But only if it is NOT a pointer into an ACPI table */

			obj_pointer = object->buffer.pointer;
		}
		break;

	case ACPI_TYPE_PACKAGE:

		ACPI_DEBUG_PRINT((ACPI_DB_ALLOCATIONS,
				  " **** Package of count %X\n",
				  object->package.count));

		/*
		 * Elements of the package are not handled here, they are deleted
		 * separately
		 */

		/* Free the (variable length) element pointer array */

		obj_pointer = object->package.elements;
		break;

		/*
		 * These objects have a possible list of notify handlers.
		 * Device object also may have a GPE block.
		 */
	case ACPI_TYPE_DEVICE:

		if (object->device.gpe_block) {
			(void)acpi_ev_delete_gpe_block(object->device.
						       gpe_block);
		}

		/*lint -fallthrough */

	case ACPI_TYPE_PROCESSOR:
	case ACPI_TYPE_THERMAL:

		/* Walk the address handler list for this object */

		handler_desc = object->common_notify.handler;
		while (handler_desc) {
			next_desc = handler_desc->address_space.next;
			acpi_ut_remove_reference(handler_desc);
			handler_desc = next_desc;
		}
		break;

	case ACPI_TYPE_MUTEX:

		ACPI_DEBUG_PRINT((ACPI_DB_ALLOCATIONS,
				  "***** Mutex %p, OS Mutex %p\n",
				  object, object->mutex.os_mutex));

		if (object == acpi_gbl_global_lock_mutex) {

			/* Global Lock has extra semaphore */

			(void)
			    acpi_os_delete_semaphore
			    (acpi_gbl_global_lock_semaphore);
			acpi_gbl_global_lock_semaphore = NULL;

			acpi_os_delete_mutex(object->mutex.os_mutex);
			acpi_gbl_global_lock_mutex = NULL;
		} else {
			acpi_ex_unlink_mutex(object);
			acpi_os_delete_mutex(object->mutex.os_mutex);
		}
		break;

	case ACPI_TYPE_EVENT:

		ACPI_DEBUG_PRINT((ACPI_DB_ALLOCATIONS,
				  "***** Event %p, OS Semaphore %p\n",
				  object, object->event.os_semaphore));

		(void)acpi_os_delete_semaphore(object->event.os_semaphore);
		object->event.os_semaphore = NULL;
		break;

	case ACPI_TYPE_METHOD:

		ACPI_DEBUG_PRINT((ACPI_DB_ALLOCATIONS,
				  "***** Method %p\n", object));

		/* Delete the method mutex if it exists */

		if (object->method.mutex) {
			acpi_os_delete_mutex(object->method.mutex->mutex.
					     os_mutex);
			acpi_ut_delete_object_desc(object->method.mutex);
			object->method.mutex = NULL;
		}

		if (object->method.node) {
			object->method.node = NULL;
		}
		break;

	case ACPI_TYPE_REGION:

		ACPI_DEBUG_PRINT((ACPI_DB_ALLOCATIONS,
				  "***** Region %p\n", object));

		/*
		 * Update address_range list. However, only permanent regions
		 * are installed in this list. (Not created within a method)
		 */
		if (!(object->region.node->flags & ANOBJ_TEMPORARY)) {
			acpi_ut_remove_address_range(object->region.space_id,
						     object->region.node);
		}

		second_desc = acpi_ns_get_secondary_object(object);
		if (second_desc) {
			/*
			 * Free the region_context if and only if the handler is one of the
			 * default handlers -- and therefore, we created the context object
			 * locally, it was not created by an external caller.
			 */
			handler_desc = object->region.handler;
			if (handler_desc) {
				next_desc =
				    handler_desc->address_space.region_list;
				start_desc = next_desc;
				last_obj_ptr =
				    &handler_desc->address_space.region_list;

				/* Remove the region object from the handler list */

				while (next_desc) {
					if (next_desc == object) {
						*last_obj_ptr =
						    next_desc->region.next;
						break;
					}

					/* Walk the linked list of handlers */

					last_obj_ptr = &next_desc->region.next;
					next_desc = next_desc->region.next;

					/* Prevent infinite loop if list is corrupted */

					if (next_desc == start_desc) {
						ACPI_ERROR((AE_INFO,
							    "Circular region list in address handler object %p",
							    handler_desc));
						return_VOID;
					}
				}

				if (handler_desc->address_space.handler_flags &
				    ACPI_ADDR_HANDLER_DEFAULT_INSTALLED) {

					/* Deactivate region and free region context */

					if (handler_desc->address_space.setup) {
						(void)handler_desc->
						    address_space.setup(object,
									ACPI_REGION_DEACTIVATE,
									handler_desc->
									address_space.
									context,
									&second_desc->
									extra.
									region_context);
					}
				}

				acpi_ut_remove_reference(handler_desc);
			}

			/* Now we can free the Extra object */

			acpi_ut_delete_object_desc(second_desc);
		}
		break;

	case ACPI_TYPE_BUFFER_FIELD:

		ACPI_DEBUG_PRINT((ACPI_DB_ALLOCATIONS,
				  "***** Buffer Field %p\n", object));

		second_desc = acpi_ns_get_secondary_object(object);
		if (second_desc) {
			acpi_ut_delete_object_desc(second_desc);
		}
		break;

	case ACPI_TYPE_LOCAL_BANK_FIELD:

		ACPI_DEBUG_PRINT((ACPI_DB_ALLOCATIONS,
				  "***** Bank Field %p\n", object));

		second_desc = acpi_ns_get_secondary_object(object);
		if (second_desc) {
			acpi_ut_delete_object_desc(second_desc);
		}
		break;

	default:

		break;
	}

	/* Free any allocated memory (pointer within the object) found above */

	if (obj_pointer) {
		ACPI_DEBUG_PRINT((ACPI_DB_ALLOCATIONS,
				  "Deleting Object Subptr %p\n", obj_pointer));
		ACPI_FREE(obj_pointer);
	}

	/* Now the object can be safely deleted */

	ACPI_DEBUG_PRINT_RAW((ACPI_DB_ALLOCATIONS,
			      "%s: Deleting Object %p [%s]\n",
			      ACPI_GET_FUNCTION_NAME, object,
			      acpi_ut_get_object_type_name(object)));

	acpi_ut_delete_object_desc(object);
	return_VOID;
}

void acpi_ut_delete_internal_object_list(union acpi_operand_object **obj_list)
{
	union acpi_operand_object **internal_obj;

	ACPI_FUNCTION_ENTRY();

	/* Walk the null-terminated internal list */

	for (internal_obj = obj_list; *internal_obj; internal_obj++) {
		acpi_ut_remove_reference(*internal_obj);
	}

	/* Free the combined parameter pointer list and object array */

	ACPI_FREE(obj_list);
	return;
}

__attribute__((used)) static void
acpi_ut_update_ref_count(union acpi_operand_object *object, u32 action)
{
	u16 original_count;
	u16 new_count = 0;
	acpi_cpu_flags lock_flags;
	char *message;

	ACPI_FUNCTION_NAME(ut_update_ref_count);

	if (!object) {
		return;
	}

	/*
	 * Always get the reference count lock. Note: Interpreter and/or
	 * Namespace is not always locked when this function is called.
	 */
	lock_flags = acpi_os_acquire_lock(acpi_gbl_reference_count_lock);
	original_count = object->common.reference_count;

	/* Perform the reference count action (increment, decrement) */

	switch (action) {
	case REF_INCREMENT:

		new_count = original_count + 1;
		object->common.reference_count = new_count;
		acpi_os_release_lock(acpi_gbl_reference_count_lock, lock_flags);

		/* The current reference count should never be zero here */

		if (!original_count) {
			ACPI_WARNING((AE_INFO,
				      "Obj %p, Reference Count was zero before increment\n",
				      object));
		}

		ACPI_DEBUG_PRINT((ACPI_DB_ALLOCATIONS,
				  "Obj %p Type %.2X [%s] Refs %.2X [Incremented]\n",
				  object, object->common.type,
				  acpi_ut_get_object_type_name(object),
				  new_count));
		message = "Incremement";
		break;

	case REF_DECREMENT:

		/* The current reference count must be non-zero */

		if (original_count) {
			new_count = original_count - 1;
			object->common.reference_count = new_count;
		}

		acpi_os_release_lock(acpi_gbl_reference_count_lock, lock_flags);

		if (!original_count) {
			ACPI_WARNING((AE_INFO,
				      "Obj %p, Reference Count is already zero, cannot decrement\n",
				      object));
		}

		ACPI_DEBUG_PRINT_RAW((ACPI_DB_ALLOCATIONS,
				      "%s: Obj %p Type %.2X Refs %.2X [Decremented]\n",
				      ACPI_GET_FUNCTION_NAME, object,
				      object->common.type, new_count));

		/* Actually delete the object on a reference count of zero */

		if (new_count == 0) {
			acpi_ut_delete_internal_obj(object);
		}
		message = "Decrement";
		break;

	default:

		acpi_os_release_lock(acpi_gbl_reference_count_lock, lock_flags);
		ACPI_ERROR((AE_INFO, "Unknown Reference Count action (0x%X)",
			    action));
		return;
	}

	/*
	 * Sanity check the reference count, for debug purposes only.
	 * (A deleted object will have a huge reference count)
	 */
	if (new_count > ACPI_MAX_REFERENCE_COUNT) {
		ACPI_WARNING((AE_INFO,
			      "Large Reference Count (0x%X) in object %p, Type=0x%.2X Operation=%s",
			      new_count, object, object->common.type, message));
	}
}

acpi_status
acpi_ut_update_object_reference(union acpi_operand_object *object, u16 action)
{
	acpi_status status = AE_OK;
	union acpi_generic_state *state_list = NULL;
	union acpi_operand_object *next_object = NULL;
	union acpi_operand_object *prev_object;
	union acpi_generic_state *state;
	u32 i;

	ACPI_FUNCTION_NAME(ut_update_object_reference);

	while (object) {

		/* Make sure that this isn't a namespace handle */

		if (ACPI_GET_DESCRIPTOR_TYPE(object) == ACPI_DESC_TYPE_NAMED) {
			ACPI_DEBUG_PRINT((ACPI_DB_ALLOCATIONS,
					  "Object %p is NS handle\n", object));
			return (AE_OK);
		}

		/*
		 * All sub-objects must have their reference count incremented
		 * also. Different object types have different subobjects.
		 */
		switch (object->common.type) {
		case ACPI_TYPE_DEVICE:
		case ACPI_TYPE_PROCESSOR:
		case ACPI_TYPE_POWER:
		case ACPI_TYPE_THERMAL:
			/*
			 * Update the notify objects for these types (if present)
			 * Two lists, system and device notify handlers.
			 */
			for (i = 0; i < ACPI_NUM_NOTIFY_TYPES; i++) {
				prev_object =
				    object->common_notify.notify_list[i];
				while (prev_object) {
					next_object =
					    prev_object->notify.next[i];
					acpi_ut_update_ref_count(prev_object,
								 action);
					prev_object = next_object;
				}
			}
			break;

		case ACPI_TYPE_PACKAGE:
			/*
			 * We must update all the sub-objects of the package,
			 * each of whom may have their own sub-objects.
			 */
			for (i = 0; i < object->package.count; i++) {
				/*
				 * Null package elements are legal and can be simply
				 * ignored.
				 */
				next_object = object->package.elements[i];
				if (!next_object) {
					continue;
				}

				switch (next_object->common.type) {
				case ACPI_TYPE_INTEGER:
				case ACPI_TYPE_STRING:
				case ACPI_TYPE_BUFFER:
					/*
					 * For these very simple sub-objects, we can just
					 * update the reference count here and continue.
					 * Greatly increases performance of this operation.
					 */
					acpi_ut_update_ref_count(next_object,
								 action);
					break;

				default:
					/*
					 * For complex sub-objects, push them onto the stack
					 * for later processing (this eliminates recursion.)
					 */
					status =
					    acpi_ut_create_update_state_and_push
					    (next_object, action, &state_list);
					if (ACPI_FAILURE(status)) {
						goto error_exit;
					}
					break;
				}
			}
			next_object = NULL;
			break;

		case ACPI_TYPE_BUFFER_FIELD:

			next_object = object->buffer_field.buffer_obj;
			break;

		case ACPI_TYPE_LOCAL_REGION_FIELD:

			next_object = object->field.region_obj;
			break;

		case ACPI_TYPE_LOCAL_BANK_FIELD:

			next_object = object->bank_field.bank_obj;
			status =
			    acpi_ut_create_update_state_and_push(object->
								 bank_field.
								 region_obj,
								 action,
								 &state_list);
			if (ACPI_FAILURE(status)) {
				goto error_exit;
			}
			break;

		case ACPI_TYPE_LOCAL_INDEX_FIELD:

			next_object = object->index_field.index_obj;
			status =
			    acpi_ut_create_update_state_and_push(object->
								 index_field.
								 data_obj,
								 action,
								 &state_list);
			if (ACPI_FAILURE(status)) {
				goto error_exit;
			}
			break;

		case ACPI_TYPE_LOCAL_REFERENCE:
			/*
			 * The target of an Index (a package, string, or buffer) or a named
			 * reference must track changes to the ref count of the index or
			 * target object.
			 */
			if ((object->reference.class == ACPI_REFCLASS_INDEX) ||
			    (object->reference.class == ACPI_REFCLASS_NAME)) {
				next_object = object->reference.object;
			}
			break;

		case ACPI_TYPE_REGION:
		default:

			break;	/* No subobjects for all other types */
		}

		/*
		 * Now we can update the count in the main object. This can only
		 * happen after we update the sub-objects in case this causes the
		 * main object to be deleted.
		 */
		acpi_ut_update_ref_count(object, action);
		object = NULL;

		/* Move on to the next object to be updated */

		if (next_object) {
			object = next_object;
			next_object = NULL;
		} else if (state_list) {
			state = acpi_ut_pop_generic_state(&state_list);
			object = state->update.object;
			acpi_ut_delete_generic_state(state);
		}
	}

	return (AE_OK);

error_exit:

	ACPI_EXCEPTION((AE_INFO, status,
			"Could not update object reference count"));

	/* Free any stacked Update State objects */

	while (state_list) {
		state = acpi_ut_pop_generic_state(&state_list);
		acpi_ut_delete_generic_state(state);
	}

	return (status);
}

void acpi_ut_add_reference(union acpi_operand_object *object)
{

	ACPI_FUNCTION_NAME(ut_add_reference);

	/* Ensure that we have a valid object */

	if (!acpi_ut_valid_internal_object(object)) {
		return;
	}

	ACPI_DEBUG_PRINT((ACPI_DB_ALLOCATIONS,
			  "Obj %p Current Refs=%X [To Be Incremented]\n",
			  object, object->common.reference_count));

	/* Increment the reference count */

	(void)acpi_ut_update_object_reference(object, REF_INCREMENT);
	return;
}

void acpi_ut_remove_reference(union acpi_operand_object *object)
{

	ACPI_FUNCTION_NAME(ut_remove_reference);

	/*
	 * Allow a NULL pointer to be passed in, just ignore it. This saves
	 * each caller from having to check. Also, ignore NS nodes.
	 */
	if (!object ||
	    (ACPI_GET_DESCRIPTOR_TYPE(object) == ACPI_DESC_TYPE_NAMED)) {
		return;
	}

	/* Ensure that we have a valid object */

	if (!acpi_ut_valid_internal_object(object)) {
		return;
	}

	ACPI_DEBUG_PRINT_RAW((ACPI_DB_ALLOCATIONS,
			      "%s: Obj %p Current Refs=%X [To Be Decremented]\n",
			      ACPI_GET_FUNCTION_NAME, object,
			      object->common.reference_count));

	/*
	 * Decrement the reference count, and only actually delete the object
	 * if the reference count becomes 0. (Must also decrement the ref count
	 * of all subobjects!)
	 */
	(void)acpi_ut_update_object_reference(object, REF_DECREMENT);
	return;
}

