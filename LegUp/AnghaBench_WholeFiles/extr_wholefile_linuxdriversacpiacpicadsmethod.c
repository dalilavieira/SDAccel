#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_24__   TYPE_9__ ;
typedef  struct TYPE_23__   TYPE_8__ ;
typedef  struct TYPE_22__   TYPE_7__ ;
typedef  struct TYPE_21__   TYPE_6__ ;
typedef  struct TYPE_20__   TYPE_5__ ;
typedef  struct TYPE_19__   TYPE_4__ ;
typedef  struct TYPE_18__   TYPE_3__ ;
typedef  struct TYPE_17__   TYPE_2__ ;
typedef  struct TYPE_16__   TYPE_1__ ;
typedef  struct TYPE_15__   TYPE_12__ ;
typedef  struct TYPE_14__   TYPE_11__ ;
typedef  struct TYPE_13__   TYPE_10__ ;

/* Type definitions */
struct TYPE_16__ {struct acpi_walk_state* node; } ;
union acpi_parse_object {TYPE_1__ common; } ;
struct TYPE_23__ {int (* implementation ) (struct acpi_walk_state*) ;} ;
struct TYPE_15__ {scalar_t__ sync_level; scalar_t__ thread_count; int info_flags; size_t param_count; scalar_t__ node; int /*<<< orphan*/  owner_id; union acpi_operand_object* mutex; TYPE_8__ dispatch; int /*<<< orphan*/  aml_length; int /*<<< orphan*/  aml_start; } ;
struct TYPE_13__ {scalar_t__ sync_level; scalar_t__ thread_id; scalar_t__ original_sync_level; int /*<<< orphan*/  os_mutex; int /*<<< orphan*/  acquisition_depth; } ;
union acpi_operand_object {TYPE_12__ method; TYPE_10__ mutex; } ;
typedef  size_t u32 ;
struct TYPE_14__ {int /*<<< orphan*/  ascii; int /*<<< orphan*/  integer; } ;
struct TYPE_20__ {int /*<<< orphan*/  aml_start; } ;
struct acpi_walk_state {int (* descending_callback ) (struct acpi_walk_state*,union acpi_parse_object**) ;size_t num_operands; TYPE_11__ name; struct acpi_walk_state* method_node; TYPE_9__* thread; union acpi_operand_object* return_desc; scalar_t__ return_used; union acpi_operand_object* implicit_return_obj; int /*<<< orphan*/  results; int /*<<< orphan*/  method_call_op; union acpi_operand_object** operands; struct acpi_walk_state* method_call_node; int /*<<< orphan*/  prev_op; int /*<<< orphan*/  op; int /*<<< orphan*/  opcode; TYPE_7__* deferred_node; TYPE_5__ parser_state; int /*<<< orphan*/  aml; TYPE_4__* op_info; TYPE_3__* method_desc; int /*<<< orphan*/  owner_id; } ;
struct acpi_thread_state {int dummy; } ;
struct acpi_namespace_node {int (* descending_callback ) (struct acpi_walk_state*,union acpi_parse_object**) ;size_t num_operands; TYPE_11__ name; struct acpi_namespace_node* method_node; TYPE_9__* thread; union acpi_operand_object* return_desc; scalar_t__ return_used; union acpi_operand_object* implicit_return_obj; int /*<<< orphan*/  results; int /*<<< orphan*/  method_call_op; union acpi_operand_object** operands; struct acpi_namespace_node* method_call_node; int /*<<< orphan*/  prev_op; int /*<<< orphan*/  op; int /*<<< orphan*/  opcode; TYPE_7__* deferred_node; TYPE_5__ parser_state; int /*<<< orphan*/  aml; TYPE_4__* op_info; TYPE_3__* method_desc; int /*<<< orphan*/  owner_id; } ;
struct acpi_evaluate_info {union acpi_operand_object** parameters; } ;
typedef  int acpi_status ;
typedef  int /*<<< orphan*/  acpi_name ;
struct TYPE_24__ {scalar_t__ current_sync_level; scalar_t__ thread_id; } ;
struct TYPE_21__ {int /*<<< orphan*/  integer; } ;
struct TYPE_22__ {TYPE_6__ name; } ;
struct TYPE_19__ {int flags; int /*<<< orphan*/  name; } ;
struct TYPE_17__ {int info_flags; scalar_t__ sync_level; } ;
struct TYPE_18__ {TYPE_2__ method; } ;

/* Variables and functions */
 struct acpi_evaluate_info* ACPI_ALLOCATE_ZEROED (int) ; 
 int /*<<< orphan*/  ACPI_DB_DISPATCH ; 
 int /*<<< orphan*/  ACPI_DB_INFO ; 
 int /*<<< orphan*/  ACPI_DB_PARSE ; 
 int /*<<< orphan*/  ACPI_DEBUG_PRINT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_ERROR (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_FAILURE (int) ; 
 int /*<<< orphan*/  ACPI_FREE (struct acpi_evaluate_info*) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_ENTRY () ; 
 int /*<<< orphan*/  ACPI_FUNCTION_NAME (int (*) (struct acpi_walk_state*,union acpi_parse_object**)) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_TRACE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_TRACE_PTR (int /*<<< orphan*/ ,struct acpi_walk_state*) ; 
 int /*<<< orphan*/  ACPI_IMODE_EXECUTE ; 
 int /*<<< orphan*/  ACPI_INFO (char*) ; 
 int ACPI_METHOD_IGNORE_SYNC_LEVEL ; 
 int ACPI_METHOD_INTERNAL_ONLY ; 
 int ACPI_METHOD_MODIFIED_NAMESPACE ; 
 int ACPI_METHOD_MODULE_LEVEL ; 
 int ACPI_METHOD_SERIALIZED ; 
 int ACPI_METHOD_SERIALIZED_PENDING ; 
 scalar_t__ ACPI_PTR_DIFF (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_SUCCESS (int) ; 
 int /*<<< orphan*/  ACPI_TYPE_MUTEX ; 
 scalar_t__ ACPI_UINT8_MAX ; 
 int /*<<< orphan*/  ACPI_WAIT_FOREVER ; 
 int AE_AML_METHOD_LIMIT ; 
 int AE_AML_MUTEX_ORDER ; 
 int AE_CODE_CONTROL ; 
 int AE_CTRL_TERMINATE ; 
 int /*<<< orphan*/  AE_INFO ; 
 int AE_NO_MEMORY ; 
 int AE_NULL_ENTRY ; 
 int AE_NULL_OBJECT ; 
 int AE_OK ; 
 int AML_CREATE ; 
 int AML_FIELD ; 
 int /*<<< orphan*/  AML_METHOD_OP ; 
 int AML_NAMED ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  acpi_ds_clear_implicit_return (struct acpi_walk_state*) ; 
 struct acpi_walk_state* acpi_ds_create_walk_state (int /*<<< orphan*/ ,int /*<<< orphan*/ *,union acpi_operand_object*,struct acpi_thread_state*) ; 
 int /*<<< orphan*/  acpi_ds_delete_walk_state (struct acpi_walk_state*) ; 
static  int acpi_ds_detect_named_opcodes (struct acpi_walk_state*,union acpi_parse_object**) ; 
 int /*<<< orphan*/  acpi_ds_do_implicit_return (union acpi_operand_object*,struct acpi_walk_state*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  acpi_ds_dump_method_stack (int,struct acpi_walk_state*,int /*<<< orphan*/ ) ; 
 int acpi_ds_init_aml_walk (struct acpi_walk_state*,union acpi_parse_object*,struct acpi_walk_state*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct acpi_evaluate_info*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  acpi_ds_method_data_delete_all (struct acpi_walk_state*) ; 
 int acpi_ds_result_push (union acpi_operand_object*,struct acpi_walk_state*) ; 
 void acpi_ds_terminate_control_method (union acpi_operand_object*,struct acpi_walk_state*) ; 
 int /*<<< orphan*/  acpi_ex_enter_interpreter () ; 
 int /*<<< orphan*/  acpi_ex_exit_interpreter () ; 
 int /*<<< orphan*/  acpi_ex_start_trace_method (struct acpi_walk_state*,union acpi_operand_object*,struct acpi_walk_state*) ; 
 int /*<<< orphan*/  acpi_ex_stop_trace_method (struct acpi_walk_state*,union acpi_operand_object*,struct acpi_walk_state*) ; 
 int acpi_ex_system_wait_mutex (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int acpi_gbl_exception_handler (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,size_t,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  acpi_method_count ; 
 int /*<<< orphan*/  acpi_ns_delete_namespace_by_owner (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  acpi_ns_delete_namespace_subtree (struct acpi_walk_state*) ; 
 union acpi_operand_object* acpi_ns_get_attached_object (struct acpi_walk_state*) ; 
 int acpi_os_create_mutex (int /*<<< orphan*/ *) ; 
 scalar_t__ acpi_os_get_thread_id () ; 
 int /*<<< orphan*/  acpi_os_release_mutex (int /*<<< orphan*/ ) ; 
 union acpi_parse_object* acpi_ps_alloc_op (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  acpi_ps_delete_parse_tree (union acpi_parse_object*) ; 
 int /*<<< orphan*/  acpi_ps_free_op (union acpi_parse_object*) ; 
 int acpi_ps_parse_aml (struct acpi_walk_state*) ; 
 int /*<<< orphan*/  acpi_ps_set_name (union acpi_parse_object*,int /*<<< orphan*/ ) ; 
 int acpi_ut_allocate_owner_id (int /*<<< orphan*/ *) ; 
 union acpi_operand_object* acpi_ut_create_internal_object (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  acpi_ut_delete_object_desc (union acpi_operand_object*) ; 
 int /*<<< orphan*/  acpi_ut_get_node_name (struct acpi_walk_state*) ; 
 int /*<<< orphan*/  acpi_ut_release_owner_id (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  acpi_ut_remove_reference (union acpi_operand_object*) ; 
 int /*<<< orphan*/  ds_auto_serialize_method ; 
 int /*<<< orphan*/  ds_begin_method_execution ; 
 int /*<<< orphan*/  ds_call_control_method ; 
 int /*<<< orphan*/  ds_create_method_mutex ; 
 int /*<<< orphan*/  ds_restart_control_method ; 
 int /*<<< orphan*/  ds_terminate_control_method ; 
 int /*<<< orphan*/  return_ACPI_STATUS (int) ; 
 int /*<<< orphan*/  return_VOID ; 
 int stub1 (struct acpi_walk_state*) ; 

acpi_status
acpi_ds_auto_serialize_method(struct acpi_namespace_node *node,
			      union acpi_operand_object *obj_desc)
{
	acpi_status status;
	union acpi_parse_object *op = NULL;
	struct acpi_walk_state *walk_state;

	ACPI_FUNCTION_TRACE_PTR(ds_auto_serialize_method, node);

	ACPI_DEBUG_PRINT((ACPI_DB_PARSE,
			  "Method auto-serialization parse [%4.4s] %p\n",
			  acpi_ut_get_node_name(node), node));

	/* Create/Init a root op for the method parse tree */

	op = acpi_ps_alloc_op(AML_METHOD_OP, obj_desc->method.aml_start);
	if (!op) {
		return_ACPI_STATUS(AE_NO_MEMORY);
	}

	acpi_ps_set_name(op, node->name.integer);
	op->common.node = node;

	/* Create and initialize a new walk state */

	walk_state =
	    acpi_ds_create_walk_state(node->owner_id, NULL, NULL, NULL);
	if (!walk_state) {
		acpi_ps_free_op(op);
		return_ACPI_STATUS(AE_NO_MEMORY);
	}

	status = acpi_ds_init_aml_walk(walk_state, op, node,
				       obj_desc->method.aml_start,
				       obj_desc->method.aml_length, NULL, 0);
	if (ACPI_FAILURE(status)) {
		acpi_ds_delete_walk_state(walk_state);
		acpi_ps_free_op(op);
		return_ACPI_STATUS(status);
	}

	walk_state->descending_callback = acpi_ds_detect_named_opcodes;

	/* Parse the method, scan for creation of named objects */

	status = acpi_ps_parse_aml(walk_state);

	acpi_ps_delete_parse_tree(op);
	return_ACPI_STATUS(status);
}

__attribute__((used)) static acpi_status
acpi_ds_detect_named_opcodes(struct acpi_walk_state *walk_state,
			     union acpi_parse_object **out_op)
{

	ACPI_FUNCTION_NAME(acpi_ds_detect_named_opcodes);

	/* We are only interested in opcodes that create a new name */

	if (!
	    (walk_state->op_info->
	     flags & (AML_NAMED | AML_CREATE | AML_FIELD))) {
		return (AE_OK);
	}

	/*
	 * At this point, we know we have a Named object opcode.
	 * Mark the method as serialized. Later code will create a mutex for
	 * this method to enforce serialization.
	 *
	 * Note, ACPI_METHOD_IGNORE_SYNC_LEVEL flag means that we will ignore the
	 * Sync Level mechanism for this method, even though it is now serialized.
	 * Otherwise, there can be conflicts with existing ASL code that actually
	 * uses sync levels.
	 */
	walk_state->method_desc->method.sync_level = 0;
	walk_state->method_desc->method.info_flags |=
	    (ACPI_METHOD_SERIALIZED | ACPI_METHOD_IGNORE_SYNC_LEVEL);

	ACPI_DEBUG_PRINT((ACPI_DB_INFO,
			  "Method serialized [%4.4s] %p - [%s] (%4.4X)\n",
			  walk_state->method_node->name.ascii,
			  walk_state->method_node, walk_state->op_info->name,
			  walk_state->opcode));

	/* Abort the parse, no need to examine this method any further */

	return (AE_CTRL_TERMINATE);
}

acpi_status
acpi_ds_method_error(acpi_status status, struct acpi_walk_state *walk_state)
{
	u32 aml_offset;
	acpi_name name = 0;

	ACPI_FUNCTION_ENTRY();

	/* Ignore AE_OK and control exception codes */

	if (ACPI_SUCCESS(status) || (status & AE_CODE_CONTROL)) {
		return (status);
	}

	/* Invoke the global exception handler */

	if (acpi_gbl_exception_handler) {

		/* Exit the interpreter, allow handler to execute methods */

		acpi_ex_exit_interpreter();

		/*
		 * Handler can map the exception code to anything it wants, including
		 * AE_OK, in which case the executing method will not be aborted.
		 */
		aml_offset = (u32)ACPI_PTR_DIFF(walk_state->aml,
						walk_state->parser_state.
						aml_start);

		if (walk_state->method_node) {
			name = walk_state->method_node->name.integer;
		} else if (walk_state->deferred_node) {
			name = walk_state->deferred_node->name.integer;
		}

		status = acpi_gbl_exception_handler(status, name,
						    walk_state->opcode,
						    aml_offset, NULL);
		acpi_ex_enter_interpreter();
	}

	acpi_ds_clear_implicit_return(walk_state);

	if (ACPI_FAILURE(status)) {
		acpi_ds_dump_method_stack(status, walk_state, walk_state->op);

		/* Display method locals/args if debugger is present */

#ifdef ACPI_DEBUGGER
		acpi_db_dump_method_info(status, walk_state);
#endif
	}

	return (status);
}

__attribute__((used)) static acpi_status
acpi_ds_create_method_mutex(union acpi_operand_object *method_desc)
{
	union acpi_operand_object *mutex_desc;
	acpi_status status;

	ACPI_FUNCTION_TRACE(ds_create_method_mutex);

	/* Create the new mutex object */

	mutex_desc = acpi_ut_create_internal_object(ACPI_TYPE_MUTEX);
	if (!mutex_desc) {
		return_ACPI_STATUS(AE_NO_MEMORY);
	}

	/* Create the actual OS Mutex */

	status = acpi_os_create_mutex(&mutex_desc->mutex.os_mutex);
	if (ACPI_FAILURE(status)) {
		acpi_ut_delete_object_desc(mutex_desc);
		return_ACPI_STATUS(status);
	}

	mutex_desc->mutex.sync_level = method_desc->method.sync_level;
	method_desc->method.mutex = mutex_desc;
	return_ACPI_STATUS(AE_OK);
}

acpi_status
acpi_ds_begin_method_execution(struct acpi_namespace_node *method_node,
			       union acpi_operand_object *obj_desc,
			       struct acpi_walk_state *walk_state)
{
	acpi_status status = AE_OK;

	ACPI_FUNCTION_TRACE_PTR(ds_begin_method_execution, method_node);

	if (!method_node) {
		return_ACPI_STATUS(AE_NULL_ENTRY);
	}

	acpi_ex_start_trace_method(method_node, obj_desc, walk_state);

	/* Prevent wraparound of thread count */

	if (obj_desc->method.thread_count == ACPI_UINT8_MAX) {
		ACPI_ERROR((AE_INFO,
			    "Method reached maximum reentrancy limit (255)"));
		return_ACPI_STATUS(AE_AML_METHOD_LIMIT);
	}

	/*
	 * If this method is serialized, we need to acquire the method mutex.
	 */
	if (obj_desc->method.info_flags & ACPI_METHOD_SERIALIZED) {
		/*
		 * Create a mutex for the method if it is defined to be Serialized
		 * and a mutex has not already been created. We defer the mutex creation
		 * until a method is actually executed, to minimize the object count
		 */
		if (!obj_desc->method.mutex) {
			status = acpi_ds_create_method_mutex(obj_desc);
			if (ACPI_FAILURE(status)) {
				return_ACPI_STATUS(status);
			}
		}

		/*
		 * The current_sync_level (per-thread) must be less than or equal to
		 * the sync level of the method. This mechanism provides some
		 * deadlock prevention.
		 *
		 * If the method was auto-serialized, we just ignore the sync level
		 * mechanism, because auto-serialization of methods can interfere
		 * with ASL code that actually uses sync levels.
		 *
		 * Top-level method invocation has no walk state at this point
		 */
		if (walk_state &&
		    (!(obj_desc->method.
		       info_flags & ACPI_METHOD_IGNORE_SYNC_LEVEL))
		    && (walk_state->thread->current_sync_level >
			obj_desc->method.mutex->mutex.sync_level)) {
			ACPI_ERROR((AE_INFO,
				    "Cannot acquire Mutex for method [%4.4s]"
				    ", current SyncLevel is too large (%u)",
				    acpi_ut_get_node_name(method_node),
				    walk_state->thread->current_sync_level));

			return_ACPI_STATUS(AE_AML_MUTEX_ORDER);
		}

		/*
		 * Obtain the method mutex if necessary. Do not acquire mutex for a
		 * recursive call.
		 */
		if (!walk_state ||
		    !obj_desc->method.mutex->mutex.thread_id ||
		    (walk_state->thread->thread_id !=
		     obj_desc->method.mutex->mutex.thread_id)) {
			/*
			 * Acquire the method mutex. This releases the interpreter if we
			 * block (and reacquires it before it returns)
			 */
			status =
			    acpi_ex_system_wait_mutex(obj_desc->method.mutex->
						      mutex.os_mutex,
						      ACPI_WAIT_FOREVER);
			if (ACPI_FAILURE(status)) {
				return_ACPI_STATUS(status);
			}

			/* Update the mutex and walk info and save the original sync_level */

			if (walk_state) {
				obj_desc->method.mutex->mutex.
				    original_sync_level =
				    walk_state->thread->current_sync_level;

				obj_desc->method.mutex->mutex.thread_id =
				    walk_state->thread->thread_id;

				/*
				 * Update the current sync_level only if this is not an auto-
				 * serialized method. In the auto case, we have to ignore
				 * the sync level for the method mutex (created for the
				 * auto-serialization) because we have no idea of what the
				 * sync level should be. Therefore, just ignore it.
				 */
				if (!(obj_desc->method.info_flags &
				      ACPI_METHOD_IGNORE_SYNC_LEVEL)) {
					walk_state->thread->current_sync_level =
					    obj_desc->method.sync_level;
				}
			} else {
				obj_desc->method.mutex->mutex.
				    original_sync_level =
				    obj_desc->method.mutex->mutex.sync_level;

				obj_desc->method.mutex->mutex.thread_id =
				    acpi_os_get_thread_id();
			}
		}

		/* Always increase acquisition depth */

		obj_desc->method.mutex->mutex.acquisition_depth++;
	}

	/*
	 * Allocate an Owner ID for this method, only if this is the first thread
	 * to begin concurrent execution. We only need one owner_id, even if the
	 * method is invoked recursively.
	 */
	if (!obj_desc->method.owner_id) {
		status = acpi_ut_allocate_owner_id(&obj_desc->method.owner_id);
		if (ACPI_FAILURE(status)) {
			goto cleanup;
		}
	}

	/*
	 * Increment the method parse tree thread count since it has been
	 * reentered one more time (even if it is the same thread)
	 */
	obj_desc->method.thread_count++;
	acpi_method_count++;
	return_ACPI_STATUS(status);

cleanup:
	/* On error, must release the method mutex (if present) */

	if (obj_desc->method.mutex) {
		acpi_os_release_mutex(obj_desc->method.mutex->mutex.os_mutex);
	}
	return_ACPI_STATUS(status);
}

acpi_status
acpi_ds_call_control_method(struct acpi_thread_state *thread,
			    struct acpi_walk_state *this_walk_state,
			    union acpi_parse_object *op)
{
	acpi_status status;
	struct acpi_namespace_node *method_node;
	struct acpi_walk_state *next_walk_state = NULL;
	union acpi_operand_object *obj_desc;
	struct acpi_evaluate_info *info;
	u32 i;

	ACPI_FUNCTION_TRACE_PTR(ds_call_control_method, this_walk_state);

	ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH,
			  "Calling method %p, currentstate=%p\n",
			  this_walk_state->prev_op, this_walk_state));

	/*
	 * Get the namespace entry for the control method we are about to call
	 */
	method_node = this_walk_state->method_call_node;
	if (!method_node) {
		return_ACPI_STATUS(AE_NULL_ENTRY);
	}

	obj_desc = acpi_ns_get_attached_object(method_node);
	if (!obj_desc) {
		return_ACPI_STATUS(AE_NULL_OBJECT);
	}

	/* Init for new method, possibly wait on method mutex */

	status =
	    acpi_ds_begin_method_execution(method_node, obj_desc,
					   this_walk_state);
	if (ACPI_FAILURE(status)) {
		return_ACPI_STATUS(status);
	}

	/* Begin method parse/execution. Create a new walk state */

	next_walk_state =
	    acpi_ds_create_walk_state(obj_desc->method.owner_id, NULL, obj_desc,
				      thread);
	if (!next_walk_state) {
		status = AE_NO_MEMORY;
		goto cleanup;
	}

	/*
	 * The resolved arguments were put on the previous walk state's operand
	 * stack. Operands on the previous walk state stack always
	 * start at index 0. Also, null terminate the list of arguments
	 */
	this_walk_state->operands[this_walk_state->num_operands] = NULL;

	/*
	 * Allocate and initialize the evaluation information block
	 * TBD: this is somewhat inefficient, should change interface to
	 * ds_init_aml_walk. For now, keeps this struct off the CPU stack
	 */
	info = ACPI_ALLOCATE_ZEROED(sizeof(struct acpi_evaluate_info));
	if (!info) {
		status = AE_NO_MEMORY;
		goto cleanup;
	}

	info->parameters = &this_walk_state->operands[0];

	status = acpi_ds_init_aml_walk(next_walk_state, NULL, method_node,
				       obj_desc->method.aml_start,
				       obj_desc->method.aml_length, info,
				       ACPI_IMODE_EXECUTE);

	ACPI_FREE(info);
	if (ACPI_FAILURE(status)) {
		goto cleanup;
	}

	/*
	 * Delete the operands on the previous walkstate operand stack
	 * (they were copied to new objects)
	 */
	for (i = 0; i < obj_desc->method.param_count; i++) {
		acpi_ut_remove_reference(this_walk_state->operands[i]);
		this_walk_state->operands[i] = NULL;
	}

	/* Clear the operand stack */

	this_walk_state->num_operands = 0;

	ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH,
			  "**** Begin nested execution of [%4.4s] **** WalkState=%p\n",
			  method_node->name.ascii, next_walk_state));

	/* Invoke an internal method if necessary */

	if (obj_desc->method.info_flags & ACPI_METHOD_INTERNAL_ONLY) {
		status =
		    obj_desc->method.dispatch.implementation(next_walk_state);
		if (status == AE_OK) {
			status = AE_CTRL_TERMINATE;
		}
	}

	return_ACPI_STATUS(status);

cleanup:

	/* On error, we must terminate the method properly */

	acpi_ds_terminate_control_method(obj_desc, next_walk_state);
	acpi_ds_delete_walk_state(next_walk_state);

	return_ACPI_STATUS(status);
}

acpi_status
acpi_ds_restart_control_method(struct acpi_walk_state *walk_state,
			       union acpi_operand_object *return_desc)
{
	acpi_status status;
	int same_as_implicit_return;

	ACPI_FUNCTION_TRACE_PTR(ds_restart_control_method, walk_state);

	ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH,
			  "****Restart [%4.4s] Op %p ReturnValueFromCallee %p\n",
			  acpi_ut_get_node_name(walk_state->method_node),
			  walk_state->method_call_op, return_desc));

	ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH,
			  "    ReturnFromThisMethodUsed?=%X ResStack %p Walk %p\n",
			  walk_state->return_used,
			  walk_state->results, walk_state));

	/* Did the called method return a value? */

	if (return_desc) {

		/* Is the implicit return object the same as the return desc? */

		same_as_implicit_return =
		    (walk_state->implicit_return_obj == return_desc);

		/* Are we actually going to use the return value? */

		if (walk_state->return_used) {

			/* Save the return value from the previous method */

			status = acpi_ds_result_push(return_desc, walk_state);
			if (ACPI_FAILURE(status)) {
				acpi_ut_remove_reference(return_desc);
				return_ACPI_STATUS(status);
			}

			/*
			 * Save as THIS method's return value in case it is returned
			 * immediately to yet another method
			 */
			walk_state->return_desc = return_desc;
		}

		/*
		 * The following code is the optional support for the so-called
		 * "implicit return". Some AML code assumes that the last value of the
		 * method is "implicitly" returned to the caller, in the absence of an
		 * explicit return value.
		 *
		 * Just save the last result of the method as the return value.
		 *
		 * NOTE: this is optional because the ASL language does not actually
		 * support this behavior.
		 */
		else if (!acpi_ds_do_implicit_return
			 (return_desc, walk_state, FALSE)
			 || same_as_implicit_return) {
			/*
			 * Delete the return value if it will not be used by the
			 * calling method or remove one reference if the explicit return
			 * is the same as the implicit return value.
			 */
			acpi_ut_remove_reference(return_desc);
		}
	}

	return_ACPI_STATUS(AE_OK);
}

void
acpi_ds_terminate_control_method(union acpi_operand_object *method_desc,
				 struct acpi_walk_state *walk_state)
{

	ACPI_FUNCTION_TRACE_PTR(ds_terminate_control_method, walk_state);

	/* method_desc is required, walk_state is optional */

	if (!method_desc) {
		return_VOID;
	}

	if (walk_state) {

		/* Delete all arguments and locals */

		acpi_ds_method_data_delete_all(walk_state);

		/*
		 * Delete any namespace objects created anywhere within the
		 * namespace by the execution of this method. Unless:
		 * 1) This method is a module-level executable code method, in which
		 *    case we want make the objects permanent.
		 * 2) There are other threads executing the method, in which case we
		 *    will wait until the last thread has completed.
		 */
		if (!(method_desc->method.info_flags & ACPI_METHOD_MODULE_LEVEL)
		    && (method_desc->method.thread_count == 1)) {

			/* Delete any direct children of (created by) this method */

			(void)acpi_ex_exit_interpreter();
			acpi_ns_delete_namespace_subtree(walk_state->
							 method_node);
			(void)acpi_ex_enter_interpreter();

			/*
			 * Delete any objects that were created by this method
			 * elsewhere in the namespace (if any were created).
			 * Use of the ACPI_METHOD_MODIFIED_NAMESPACE optimizes the
			 * deletion such that we don't have to perform an entire
			 * namespace walk for every control method execution.
			 */
			if (method_desc->method.
			    info_flags & ACPI_METHOD_MODIFIED_NAMESPACE) {
				(void)acpi_ex_exit_interpreter();
				acpi_ns_delete_namespace_by_owner(method_desc->
								  method.
								  owner_id);
				(void)acpi_ex_enter_interpreter();
				method_desc->method.info_flags &=
				    ~ACPI_METHOD_MODIFIED_NAMESPACE;
			}
		}

		/*
		 * If method is serialized, release the mutex and restore the
		 * current sync level for this thread
		 */
		if (method_desc->method.mutex) {

			/* Acquisition Depth handles recursive calls */

			method_desc->method.mutex->mutex.acquisition_depth--;
			if (!method_desc->method.mutex->mutex.acquisition_depth) {
				walk_state->thread->current_sync_level =
				    method_desc->method.mutex->mutex.
				    original_sync_level;

				acpi_os_release_mutex(method_desc->method.
						      mutex->mutex.os_mutex);
				method_desc->method.mutex->mutex.thread_id = 0;
			}
		}
	}

	/* Decrement the thread count on the method */

	if (method_desc->method.thread_count) {
		method_desc->method.thread_count--;
	} else {
		ACPI_ERROR((AE_INFO, "Invalid zero thread count in method"));
	}

	/* Are there any other threads currently executing this method? */

	if (method_desc->method.thread_count) {
		/*
		 * Additional threads. Do not release the owner_id in this case,
		 * we immediately reuse it for the next thread executing this method
		 */
		ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH,
				  "*** Completed execution of one thread, %u threads remaining\n",
				  method_desc->method.thread_count));
	} else {
		/* This is the only executing thread for this method */

		/*
		 * Support to dynamically change a method from not_serialized to
		 * Serialized if it appears that the method is incorrectly written and
		 * does not support multiple thread execution. The best example of this
		 * is if such a method creates namespace objects and blocks. A second
		 * thread will fail with an AE_ALREADY_EXISTS exception.
		 *
		 * This code is here because we must wait until the last thread exits
		 * before marking the method as serialized.
		 */
		if (method_desc->method.
		    info_flags & ACPI_METHOD_SERIALIZED_PENDING) {
			if (walk_state) {
				ACPI_INFO(("Marking method %4.4s as Serialized "
					   "because of AE_ALREADY_EXISTS error",
					   walk_state->method_node->name.
					   ascii));
			}

			/*
			 * Method tried to create an object twice and was marked as
			 * "pending serialized". The probable cause is that the method
			 * cannot handle reentrancy.
			 *
			 * The method was created as not_serialized, but it tried to create
			 * a named object and then blocked, causing the second thread
			 * entrance to begin and then fail. Workaround this problem by
			 * marking the method permanently as Serialized when the last
			 * thread exits here.
			 */
			method_desc->method.info_flags &=
			    ~ACPI_METHOD_SERIALIZED_PENDING;

			method_desc->method.info_flags |=
			    (ACPI_METHOD_SERIALIZED |
			     ACPI_METHOD_IGNORE_SYNC_LEVEL);
			method_desc->method.sync_level = 0;
		}

		/* No more threads, we can free the owner_id */

		if (!
		    (method_desc->method.
		     info_flags & ACPI_METHOD_MODULE_LEVEL)) {
			acpi_ut_release_owner_id(&method_desc->method.owner_id);
		}
	}

	acpi_ex_stop_trace_method((struct acpi_namespace_node *)method_desc->
				  method.node, method_desc, walk_state);

	return_VOID;
}

