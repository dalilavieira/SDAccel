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
struct TYPE_4__ {char* aml_op_name; int /*<<< orphan*/ * aml; } ;
union acpi_parse_object {TYPE_2__ common; } ;
struct TYPE_3__ {int /*<<< orphan*/ * aml_start; } ;
union acpi_operand_object {TYPE_1__ method; } ;
typedef  void* u8 ;
struct acpi_walk_state {int dummy; } ;
struct acpi_namespace_node {int dummy; } ;
typedef  int /*<<< orphan*/  acpi_trace_event_type ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_DB_TRACE_POINT ; 
 int /*<<< orphan*/  ACPI_DEBUG_PRINT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FREE (char*) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_NAME (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_TRACE_AML_METHOD ; 
 int /*<<< orphan*/  ACPI_TRACE_AML_OPCODE ; 
 int ACPI_TRACE_ENABLED ; 
 scalar_t__ ACPI_TRACE_LAYER_ALL ; 
 scalar_t__ ACPI_TRACE_LEVEL_ALL ; 
 int ACPI_TRACE_ONESHOT ; 
 int ACPI_TRACE_OPCODE ; 
 int /*<<< orphan*/  ACPI_TRACE_POINT (int /*<<< orphan*/ ,void*,int /*<<< orphan*/ *,char*) ; 
 void* FALSE ; 
 void* TRUE ; 
 scalar_t__ acpi_dbg_layer ; 
 scalar_t__ acpi_dbg_level ; 
 int /*<<< orphan*/  acpi_ex_get_trace_event_name (int /*<<< orphan*/ ) ; 
 scalar_t__ acpi_gbl_original_dbg_layer ; 
 scalar_t__ acpi_gbl_original_dbg_level ; 
 scalar_t__ acpi_gbl_trace_dbg_layer ; 
 scalar_t__ acpi_gbl_trace_dbg_level ; 
 int acpi_gbl_trace_flags ; 
 int /*<<< orphan*/ * acpi_gbl_trace_method_name ; 
 union acpi_operand_object* acpi_gbl_trace_method_object ; 
 char* acpi_ns_get_normalized_pathname (struct acpi_namespace_node*,void*) ; 
 int /*<<< orphan*/  ex_start_trace_method ; 
 int /*<<< orphan*/  ex_start_trace_opcode ; 
 int /*<<< orphan*/  ex_stop_trace_method ; 
 int /*<<< orphan*/  ex_stop_trace_opcode ; 
 int /*<<< orphan*/  ex_trace_point ; 
 scalar_t__ strcmp (int /*<<< orphan*/ *,char*) ; 

__attribute__((used)) static u8 acpi_ex_interpreter_trace_enabled(char *name)
{

	/* Check if tracing is enabled */

	if (!(acpi_gbl_trace_flags & ACPI_TRACE_ENABLED)) {
		return (FALSE);
	}

	/*
	 * Check if tracing is filtered:
	 *
	 * 1. If the tracer is started, acpi_gbl_trace_method_object should have
	 *    been filled by the trace starter
	 * 2. If the tracer is not started, acpi_gbl_trace_method_name should be
	 *    matched if it is specified
	 * 3. If the tracer is oneshot style, acpi_gbl_trace_method_name should
	 *    not be cleared by the trace stopper during the first match
	 */
	if (acpi_gbl_trace_method_object) {
		return (TRUE);
	}

	if (name &&
	    (acpi_gbl_trace_method_name &&
	     strcmp(acpi_gbl_trace_method_name, name))) {
		return (FALSE);
	}

	if ((acpi_gbl_trace_flags & ACPI_TRACE_ONESHOT) &&
	    !acpi_gbl_trace_method_name) {
		return (FALSE);
	}

	return (TRUE);
}

void
acpi_ex_trace_point(acpi_trace_event_type type,
		    u8 begin, u8 *aml, char *pathname)
{

	ACPI_FUNCTION_NAME(ex_trace_point);

	if (pathname) {
		ACPI_DEBUG_PRINT((ACPI_DB_TRACE_POINT,
				  "%s %s [0x%p:%s] execution.\n",
				  acpi_ex_get_trace_event_name(type),
				  begin ? "Begin" : "End", aml, pathname));
	} else {
		ACPI_DEBUG_PRINT((ACPI_DB_TRACE_POINT,
				  "%s %s [0x%p] execution.\n",
				  acpi_ex_get_trace_event_name(type),
				  begin ? "Begin" : "End", aml));
	}
}

void
acpi_ex_start_trace_method(struct acpi_namespace_node *method_node,
			   union acpi_operand_object *obj_desc,
			   struct acpi_walk_state *walk_state)
{
	char *pathname = NULL;
	u8 enabled = FALSE;

	ACPI_FUNCTION_NAME(ex_start_trace_method);

	if (method_node) {
		pathname = acpi_ns_get_normalized_pathname(method_node, TRUE);
	}

	enabled = acpi_ex_interpreter_trace_enabled(pathname);
	if (enabled && !acpi_gbl_trace_method_object) {
		acpi_gbl_trace_method_object = obj_desc;
		acpi_gbl_original_dbg_level = acpi_dbg_level;
		acpi_gbl_original_dbg_layer = acpi_dbg_layer;
		acpi_dbg_level = ACPI_TRACE_LEVEL_ALL;
		acpi_dbg_layer = ACPI_TRACE_LAYER_ALL;

		if (acpi_gbl_trace_dbg_level) {
			acpi_dbg_level = acpi_gbl_trace_dbg_level;
		}

		if (acpi_gbl_trace_dbg_layer) {
			acpi_dbg_layer = acpi_gbl_trace_dbg_layer;
		}
	}

	if (enabled) {
		ACPI_TRACE_POINT(ACPI_TRACE_AML_METHOD, TRUE,
				 obj_desc ? obj_desc->method.aml_start : NULL,
				 pathname);
	}

	if (pathname) {
		ACPI_FREE(pathname);
	}
}

void
acpi_ex_stop_trace_method(struct acpi_namespace_node *method_node,
			  union acpi_operand_object *obj_desc,
			  struct acpi_walk_state *walk_state)
{
	char *pathname = NULL;
	u8 enabled;

	ACPI_FUNCTION_NAME(ex_stop_trace_method);

	if (method_node) {
		pathname = acpi_ns_get_normalized_pathname(method_node, TRUE);
	}

	enabled = acpi_ex_interpreter_trace_enabled(NULL);

	if (enabled) {
		ACPI_TRACE_POINT(ACPI_TRACE_AML_METHOD, FALSE,
				 obj_desc ? obj_desc->method.aml_start : NULL,
				 pathname);
	}

	/* Check whether the tracer should be stopped */

	if (acpi_gbl_trace_method_object == obj_desc) {

		/* Disable further tracing if type is one-shot */

		if (acpi_gbl_trace_flags & ACPI_TRACE_ONESHOT) {
			acpi_gbl_trace_method_name = NULL;
		}

		acpi_dbg_level = acpi_gbl_original_dbg_level;
		acpi_dbg_layer = acpi_gbl_original_dbg_layer;
		acpi_gbl_trace_method_object = NULL;
	}

	if (pathname) {
		ACPI_FREE(pathname);
	}
}

void
acpi_ex_start_trace_opcode(union acpi_parse_object *op,
			   struct acpi_walk_state *walk_state)
{

	ACPI_FUNCTION_NAME(ex_start_trace_opcode);

	if (acpi_ex_interpreter_trace_enabled(NULL) &&
	    (acpi_gbl_trace_flags & ACPI_TRACE_OPCODE)) {
		ACPI_TRACE_POINT(ACPI_TRACE_AML_OPCODE, TRUE,
				 op->common.aml, op->common.aml_op_name);
	}
}

void
acpi_ex_stop_trace_opcode(union acpi_parse_object *op,
			  struct acpi_walk_state *walk_state)
{

	ACPI_FUNCTION_NAME(ex_stop_trace_opcode);

	if (acpi_ex_interpreter_trace_enabled(NULL) &&
	    (acpi_gbl_trace_flags & ACPI_TRACE_OPCODE)) {
		ACPI_TRACE_POINT(ACPI_TRACE_AML_OPCODE, FALSE,
				 op->common.aml, op->common.aml_op_name);
	}
}

