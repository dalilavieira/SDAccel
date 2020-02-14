#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_22__   TYPE_9__ ;
typedef  struct TYPE_21__   TYPE_8__ ;
typedef  struct TYPE_20__   TYPE_7__ ;
typedef  struct TYPE_19__   TYPE_6__ ;
typedef  struct TYPE_18__   TYPE_5__ ;
typedef  struct TYPE_17__   TYPE_4__ ;
typedef  struct TYPE_16__   TYPE_3__ ;
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;
typedef  struct TYPE_13__   TYPE_10__ ;

/* Type definitions */
struct TYPE_16__ {int /*<<< orphan*/  arg; } ;
struct TYPE_17__ {int const aml_opcode; TYPE_3__ value; } ;
union acpi_parse_object {TYPE_4__ common; } ;
struct TYPE_22__ {int opcode; int /*<<< orphan*/  package_end; int /*<<< orphan*/  aml_predicate_start; scalar_t__ loop_timeout; } ;
struct TYPE_15__ {int /*<<< orphan*/  value; int /*<<< orphan*/  state; } ;
union acpi_generic_state {TYPE_9__ control; TYPE_2__ common; } ;
typedef  int /*<<< orphan*/  u8 ;
typedef  scalar_t__ u64 ;
struct TYPE_14__ {int /*<<< orphan*/  pkg_end; int /*<<< orphan*/  aml; } ;
struct acpi_walk_state {union acpi_generic_state* control_state; int /*<<< orphan*/  aml_last_while; TYPE_10__* return_desc; int /*<<< orphan*/  num_operands; TYPE_10__** operands; TYPE_8__* results; int /*<<< orphan*/  result_count; int /*<<< orphan*/  last_predicate; TYPE_1__ parser_state; } ;
typedef  int /*<<< orphan*/  acpi_status ;
struct TYPE_20__ {TYPE_10__** obj_desc; } ;
struct TYPE_21__ {TYPE_7__ results; } ;
struct TYPE_19__ {int /*<<< orphan*/  class; } ;
struct TYPE_18__ {int /*<<< orphan*/  type; } ;
struct TYPE_13__ {TYPE_6__ reference; TYPE_5__ common; } ;

/* Variables and functions */
 int ACPI_100NSEC_PER_SEC ; 
 int /*<<< orphan*/  ACPI_CONTROL_CONDITIONAL_EXECUTING ; 
 int /*<<< orphan*/  ACPI_DB_DISPATCH ; 
 int /*<<< orphan*/  ACPI_DEBUG_PRINT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_DESC_TYPE_OPERAND ; 
 int /*<<< orphan*/  ACPI_ERROR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_NAME (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_GET_DESCRIPTOR_TYPE (TYPE_10__*) ; 
 int /*<<< orphan*/  ACPI_REFCLASS_INDEX ; 
 int /*<<< orphan*/  ACPI_SIGNAL_BREAKPOINT ; 
 int /*<<< orphan*/  ACPI_TIME_AFTER (scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  ACPI_TYPE_LOCAL_REFERENCE ; 
 int /*<<< orphan*/  AE_AML_BAD_OPCODE ; 
 int /*<<< orphan*/  AE_AML_LOOP_TIMEOUT ; 
 int /*<<< orphan*/  AE_AML_NO_WHILE ; 
 int /*<<< orphan*/  AE_CTRL_BREAK ; 
 int /*<<< orphan*/  AE_CTRL_CONTINUE ; 
 int /*<<< orphan*/  AE_CTRL_PENDING ; 
 int /*<<< orphan*/  AE_CTRL_TERMINATE ; 
 int /*<<< orphan*/  AE_CTRL_TRUE ; 
 int /*<<< orphan*/  AE_INFO ; 
 int /*<<< orphan*/  AE_NO_MEMORY ; 
 int /*<<< orphan*/  AE_OK ; 
#define  AML_BREAKPOINT_OP 135 
#define  AML_BREAK_OP 134 
#define  AML_CONTINUE_OP 133 
#define  AML_ELSE_OP 132 
#define  AML_IF_OP 131 
#define  AML_NOOP_OP 130 
#define  AML_RETURN_OP 129 
#define  AML_WHILE_OP 128 
 int /*<<< orphan*/  acpi_db_signal_break_point (struct acpi_walk_state*) ; 
 int /*<<< orphan*/  acpi_ds_clear_implicit_return (struct acpi_walk_state*) ; 
 int /*<<< orphan*/  acpi_ds_create_operands (struct acpi_walk_state*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  acpi_ex_resolve_to_value (TYPE_10__**,struct acpi_walk_state*) ; 
 int acpi_gbl_max_loop_iterations ; 
 scalar_t__ acpi_os_get_timer () ; 
 int /*<<< orphan*/  acpi_os_signal (int /*<<< orphan*/ ,char*) ; 
 union acpi_generic_state* acpi_ut_create_control_state () ; 
 int /*<<< orphan*/  acpi_ut_delete_generic_state (union acpi_generic_state*) ; 
 union acpi_generic_state* acpi_ut_pop_generic_state (union acpi_generic_state**) ; 
 int /*<<< orphan*/  acpi_ut_push_generic_state (union acpi_generic_state**,union acpi_generic_state*) ; 
 int /*<<< orphan*/  acpi_ut_remove_reference (TYPE_10__*) ; 
 int /*<<< orphan*/  ds_exec_begin_control_op ; 
 int /*<<< orphan*/  ds_exec_end_control_op ; 

acpi_status
acpi_ds_exec_begin_control_op(struct acpi_walk_state *walk_state,
			      union acpi_parse_object *op)
{
	acpi_status status = AE_OK;
	union acpi_generic_state *control_state;

	ACPI_FUNCTION_NAME(ds_exec_begin_control_op);

	ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH, "Op=%p Opcode=%2.2X State=%p\n",
			  op, op->common.aml_opcode, walk_state));

	switch (op->common.aml_opcode) {
	case AML_WHILE_OP:
		/*
		 * If this is an additional iteration of a while loop, continue.
		 * There is no need to allocate a new control state.
		 */
		if (walk_state->control_state) {
			if (walk_state->control_state->control.
			    aml_predicate_start ==
			    (walk_state->parser_state.aml - 1)) {

				/* Reset the state to start-of-loop */

				walk_state->control_state->common.state =
				    ACPI_CONTROL_CONDITIONAL_EXECUTING;
				break;
			}
		}

		/*lint -fallthrough */

	case AML_IF_OP:
		/*
		 * IF/WHILE: Create a new control state to manage these
		 * constructs. We need to manage these as a stack, in order
		 * to handle nesting.
		 */
		control_state = acpi_ut_create_control_state();
		if (!control_state) {
			status = AE_NO_MEMORY;
			break;
		}
		/*
		 * Save a pointer to the predicate for multiple executions
		 * of a loop
		 */
		control_state->control.aml_predicate_start =
		    walk_state->parser_state.aml - 1;
		control_state->control.package_end =
		    walk_state->parser_state.pkg_end;
		control_state->control.opcode = op->common.aml_opcode;
		control_state->control.loop_timeout = acpi_os_get_timer() +
		    (u64)(acpi_gbl_max_loop_iterations * ACPI_100NSEC_PER_SEC);

		/* Push the control state on this walk's control stack */

		acpi_ut_push_generic_state(&walk_state->control_state,
					   control_state);
		break;

	case AML_ELSE_OP:

		/* Predicate is in the state object */
		/* If predicate is true, the IF was executed, ignore ELSE part */

		if (walk_state->last_predicate) {
			status = AE_CTRL_TRUE;
		}

		break;

	case AML_RETURN_OP:

		break;

	default:

		break;
	}

	return (status);
}

acpi_status
acpi_ds_exec_end_control_op(struct acpi_walk_state *walk_state,
			    union acpi_parse_object *op)
{
	acpi_status status = AE_OK;
	union acpi_generic_state *control_state;

	ACPI_FUNCTION_NAME(ds_exec_end_control_op);

	switch (op->common.aml_opcode) {
	case AML_IF_OP:

		ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH, "[IF_OP] Op=%p\n", op));

		/*
		 * Save the result of the predicate in case there is an
		 * ELSE to come
		 */
		walk_state->last_predicate =
		    (u8)walk_state->control_state->common.value;

		/*
		 * Pop the control state that was created at the start
		 * of the IF and free it
		 */
		control_state =
		    acpi_ut_pop_generic_state(&walk_state->control_state);
		acpi_ut_delete_generic_state(control_state);
		break;

	case AML_ELSE_OP:

		break;

	case AML_WHILE_OP:

		ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH, "[WHILE_OP] Op=%p\n", op));

		control_state = walk_state->control_state;
		if (control_state->common.value) {

			/* Predicate was true, the body of the loop was just executed */

			/*
			 * This infinite loop detection mechanism allows the interpreter
			 * to escape possibly infinite loops. This can occur in poorly
			 * written AML when the hardware does not respond within a while
			 * loop and the loop does not implement a timeout.
			 */
			if (ACPI_TIME_AFTER(acpi_os_get_timer(),
					    control_state->control.
					    loop_timeout)) {
				status = AE_AML_LOOP_TIMEOUT;
				break;
			}

			/*
			 * Go back and evaluate the predicate and maybe execute the loop
			 * another time
			 */
			status = AE_CTRL_PENDING;
			walk_state->aml_last_while =
			    control_state->control.aml_predicate_start;
			break;
		}

		/* Predicate was false, terminate this while loop */

		ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH,
				  "[WHILE_OP] termination! Op=%p\n", op));

		/* Pop this control state and free it */

		control_state =
		    acpi_ut_pop_generic_state(&walk_state->control_state);
		acpi_ut_delete_generic_state(control_state);
		break;

	case AML_RETURN_OP:

		ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH,
				  "[RETURN_OP] Op=%p Arg=%p\n", op,
				  op->common.value.arg));

		/*
		 * One optional operand -- the return value
		 * It can be either an immediate operand or a result that
		 * has been bubbled up the tree
		 */
		if (op->common.value.arg) {

			/* Since we have a real Return(), delete any implicit return */

			acpi_ds_clear_implicit_return(walk_state);

			/* Return statement has an immediate operand */

			status =
			    acpi_ds_create_operands(walk_state,
						    op->common.value.arg);
			if (ACPI_FAILURE(status)) {
				return (status);
			}

			/*
			 * If value being returned is a Reference (such as
			 * an arg or local), resolve it now because it may
			 * cease to exist at the end of the method.
			 */
			status =
			    acpi_ex_resolve_to_value(&walk_state->operands[0],
						     walk_state);
			if (ACPI_FAILURE(status)) {
				return (status);
			}

			/*
			 * Get the return value and save as the last result
			 * value. This is the only place where walk_state->return_desc
			 * is set to anything other than zero!
			 */
			walk_state->return_desc = walk_state->operands[0];
		} else if (walk_state->result_count) {

			/* Since we have a real Return(), delete any implicit return */

			acpi_ds_clear_implicit_return(walk_state);

			/*
			 * The return value has come from a previous calculation.
			 *
			 * If value being returned is a Reference (such as
			 * an arg or local), resolve it now because it may
			 * cease to exist at the end of the method.
			 *
			 * Allow references created by the Index operator to return
			 * unchanged.
			 */
			if ((ACPI_GET_DESCRIPTOR_TYPE
			     (walk_state->results->results.obj_desc[0]) ==
			     ACPI_DESC_TYPE_OPERAND)
			    && ((walk_state->results->results.obj_desc[0])->
				common.type == ACPI_TYPE_LOCAL_REFERENCE)
			    && ((walk_state->results->results.obj_desc[0])->
				reference.class != ACPI_REFCLASS_INDEX)) {
				status =
				    acpi_ex_resolve_to_value(&walk_state->
							     results->results.
							     obj_desc[0],
							     walk_state);
				if (ACPI_FAILURE(status)) {
					return (status);
				}
			}

			walk_state->return_desc =
			    walk_state->results->results.obj_desc[0];
		} else {
			/* No return operand */

			if (walk_state->num_operands) {
				acpi_ut_remove_reference(walk_state->
							 operands[0]);
			}

			walk_state->operands[0] = NULL;
			walk_state->num_operands = 0;
			walk_state->return_desc = NULL;
		}

		ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH,
				  "Completed RETURN_OP State=%p, RetVal=%p\n",
				  walk_state, walk_state->return_desc));

		/* End the control method execution right now */

		status = AE_CTRL_TERMINATE;
		break;

	case AML_NOOP_OP:

		/* Just do nothing! */

		break;

	case AML_BREAKPOINT_OP:

		acpi_db_signal_break_point(walk_state);

		/* Call to the OSL in case OS wants a piece of the action */

		status = acpi_os_signal(ACPI_SIGNAL_BREAKPOINT,
					"Executed AML Breakpoint opcode");
		break;

	case AML_BREAK_OP:
	case AML_CONTINUE_OP:	/* ACPI 2.0 */

		/* Pop and delete control states until we find a while */

		while (walk_state->control_state &&
		       (walk_state->control_state->control.opcode !=
			AML_WHILE_OP)) {
			control_state =
			    acpi_ut_pop_generic_state(&walk_state->
						      control_state);
			acpi_ut_delete_generic_state(control_state);
		}

		/* No while found? */

		if (!walk_state->control_state) {
			return (AE_AML_NO_WHILE);
		}

		/* Was: walk_state->aml_last_while = walk_state->control_state->Control.aml_predicate_start; */

		walk_state->aml_last_while =
		    walk_state->control_state->control.package_end;

		/* Return status depending on opcode */

		if (op->common.aml_opcode == AML_BREAK_OP) {
			status = AE_CTRL_BREAK;
		} else {
			status = AE_CTRL_CONTINUE;
		}
		break;

	default:

		ACPI_ERROR((AE_INFO, "Unknown control opcode=0x%X Op=%p",
			    op->common.aml_opcode, op));

		status = AE_AML_BAD_OPCODE;
		break;
	}

	return (status);
}

