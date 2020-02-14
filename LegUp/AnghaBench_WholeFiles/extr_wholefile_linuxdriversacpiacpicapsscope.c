#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
union acpi_parse_object {scalar_t__ aml; scalar_t__ aml_end; scalar_t__ pkg_end; union acpi_generic_state* scope; union acpi_parse_object* start_op; } ;
struct TYPE_4__ {scalar_t__ arg_end; scalar_t__ arg_count; scalar_t__ pkg_end; scalar_t__ arg_list; union acpi_parse_object* op; } ;
struct TYPE_3__ {scalar_t__ next; int /*<<< orphan*/  descriptor_type; } ;
union acpi_generic_state {TYPE_2__ parse_scope; TYPE_1__ common; } ;
typedef  int /*<<< orphan*/  u8 ;
typedef  scalar_t__ u32 ;
struct acpi_parse_state {scalar_t__ aml; scalar_t__ aml_end; scalar_t__ pkg_end; union acpi_generic_state* scope; struct acpi_parse_state* start_op; } ;
typedef  int /*<<< orphan*/  acpi_status ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_DB_PARSE ; 
 int /*<<< orphan*/  ACPI_DEBUG_PRINT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_DESC_TYPE_STATE_PSCOPE ; 
 int /*<<< orphan*/  ACPI_DESC_TYPE_STATE_RPSCOPE ; 
 int /*<<< orphan*/  ACPI_FUNCTION_TRACE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_TRACE_PTR (int /*<<< orphan*/ ,union acpi_parse_object*) ; 
 int /*<<< orphan*/  ACPI_MAX_PTR ; 
 scalar_t__ ACPI_TO_POINTER (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_VAR_ARGS ; 
 int /*<<< orphan*/  AE_NO_MEMORY ; 
 int /*<<< orphan*/  AE_OK ; 
 union acpi_generic_state* acpi_ut_create_generic_state () ; 
 int /*<<< orphan*/  acpi_ut_delete_generic_state (union acpi_generic_state*) ; 
 union acpi_generic_state* acpi_ut_pop_generic_state (union acpi_generic_state**) ; 
 int /*<<< orphan*/  acpi_ut_push_generic_state (union acpi_generic_state**,union acpi_generic_state*) ; 
 int /*<<< orphan*/  ps_cleanup_scope ; 
 int /*<<< orphan*/  ps_init_scope ; 
 int /*<<< orphan*/  ps_pop_scope ; 
 int /*<<< orphan*/  ps_push_scope ; 
 int /*<<< orphan*/  return_ACPI_STATUS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  return_VOID ; 

union acpi_parse_object *acpi_ps_get_parent_scope(struct acpi_parse_state
						  *parser_state)
{

	return (parser_state->scope->parse_scope.op);
}

u8 acpi_ps_has_completed_scope(struct acpi_parse_state * parser_state)
{

	return ((u8)
		((parser_state->aml >= parser_state->scope->parse_scope.arg_end
		  || !parser_state->scope->parse_scope.arg_count)));
}

acpi_status
acpi_ps_init_scope(struct acpi_parse_state * parser_state,
		   union acpi_parse_object * root_op)
{
	union acpi_generic_state *scope;

	ACPI_FUNCTION_TRACE_PTR(ps_init_scope, root_op);

	scope = acpi_ut_create_generic_state();
	if (!scope) {
		return_ACPI_STATUS(AE_NO_MEMORY);
	}

	scope->common.descriptor_type = ACPI_DESC_TYPE_STATE_RPSCOPE;
	scope->parse_scope.op = root_op;
	scope->parse_scope.arg_count = ACPI_VAR_ARGS;
	scope->parse_scope.arg_end = parser_state->aml_end;
	scope->parse_scope.pkg_end = parser_state->aml_end;

	parser_state->scope = scope;
	parser_state->start_op = root_op;

	return_ACPI_STATUS(AE_OK);
}

acpi_status
acpi_ps_push_scope(struct acpi_parse_state *parser_state,
		   union acpi_parse_object *op,
		   u32 remaining_args, u32 arg_count)
{
	union acpi_generic_state *scope;

	ACPI_FUNCTION_TRACE_PTR(ps_push_scope, op);

	scope = acpi_ut_create_generic_state();
	if (!scope) {
		return_ACPI_STATUS(AE_NO_MEMORY);
	}

	scope->common.descriptor_type = ACPI_DESC_TYPE_STATE_PSCOPE;
	scope->parse_scope.op = op;
	scope->parse_scope.arg_list = remaining_args;
	scope->parse_scope.arg_count = arg_count;
	scope->parse_scope.pkg_end = parser_state->pkg_end;

	/* Push onto scope stack */

	acpi_ut_push_generic_state(&parser_state->scope, scope);

	if (arg_count == ACPI_VAR_ARGS) {

		/* Multiple arguments */

		scope->parse_scope.arg_end = parser_state->pkg_end;
	} else {
		/* Single argument */

		scope->parse_scope.arg_end = ACPI_TO_POINTER(ACPI_MAX_PTR);
	}

	return_ACPI_STATUS(AE_OK);
}

void
acpi_ps_pop_scope(struct acpi_parse_state *parser_state,
		  union acpi_parse_object **op, u32 * arg_list, u32 * arg_count)
{
	union acpi_generic_state *scope = parser_state->scope;

	ACPI_FUNCTION_TRACE(ps_pop_scope);

	/* Only pop the scope if there is in fact a next scope */

	if (scope->common.next) {
		scope = acpi_ut_pop_generic_state(&parser_state->scope);

		/* Return to parsing previous op */

		*op = scope->parse_scope.op;
		*arg_list = scope->parse_scope.arg_list;
		*arg_count = scope->parse_scope.arg_count;
		parser_state->pkg_end = scope->parse_scope.pkg_end;

		/* All done with this scope state structure */

		acpi_ut_delete_generic_state(scope);
	} else {
		/* Empty parse stack, prepare to fetch next opcode */

		*op = NULL;
		*arg_list = 0;
		*arg_count = 0;
	}

	ACPI_DEBUG_PRINT((ACPI_DB_PARSE,
			  "Popped Op %p Args %X\n", *op, *arg_count));
	return_VOID;
}

void acpi_ps_cleanup_scope(struct acpi_parse_state *parser_state)
{
	union acpi_generic_state *scope;

	ACPI_FUNCTION_TRACE_PTR(ps_cleanup_scope, parser_state);

	if (!parser_state) {
		return_VOID;
	}

	/* Delete anything on the scope stack */

	while (parser_state->scope) {
		scope = acpi_ut_pop_generic_state(&parser_state->scope);
		acpi_ut_delete_generic_state(scope);
	}

	return_VOID;
}

