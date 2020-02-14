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
struct TYPE_3__ {union acpi_parse_object* arg; } ;
struct TYPE_4__ {union acpi_parse_object* parent; union acpi_parse_object* next; int /*<<< orphan*/  arg_list_length; TYPE_1__ value; int /*<<< orphan*/  aml_opcode; } ;
union acpi_parse_object {TYPE_2__ common; } ;
typedef  scalar_t__ u32 ;
struct acpi_opcode_info {scalar_t__ class; int flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_ERROR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_ENTRY () ; 
 int /*<<< orphan*/  ACPI_FUNCTION_TRACE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AE_INFO ; 
 scalar_t__ AML_CLASS_UNKNOWN ; 
 int AML_HAS_ARGS ; 
 int /*<<< orphan*/  ASL_CV_LABEL_FILENODE (union acpi_parse_object*) ; 
 struct acpi_opcode_info* acpi_ps_get_opcode_info (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ps_append_arg ; 
 int /*<<< orphan*/  return_VOID ; 

union acpi_parse_object *acpi_ps_get_arg(union acpi_parse_object *op, u32 argn)
{
	union acpi_parse_object *arg = NULL;
	const struct acpi_opcode_info *op_info;

	ACPI_FUNCTION_ENTRY();

/*
	if (Op->Common.aml_opcode == AML_INT_CONNECTION_OP)
	{
		return (Op->Common.Value.Arg);
	}
*/
	/* Get the info structure for this opcode */

	op_info = acpi_ps_get_opcode_info(op->common.aml_opcode);
	if (op_info->class == AML_CLASS_UNKNOWN) {

		/* Invalid opcode or ASCII character */

		return (NULL);
	}

	/* Check if this opcode requires argument sub-objects */

	if (!(op_info->flags & AML_HAS_ARGS)) {

		/* Has no linked argument objects */

		return (NULL);
	}

	/* Get the requested argument object */

	arg = op->common.value.arg;
	while (arg && argn) {
		argn--;
		arg = arg->common.next;
	}

	return (arg);
}

void
acpi_ps_append_arg(union acpi_parse_object *op, union acpi_parse_object *arg)
{
	union acpi_parse_object *prev_arg;
	const struct acpi_opcode_info *op_info;

	ACPI_FUNCTION_TRACE(ps_append_arg);

	if (!op) {
		return_VOID;
	}

	/* Get the info structure for this opcode */

	op_info = acpi_ps_get_opcode_info(op->common.aml_opcode);
	if (op_info->class == AML_CLASS_UNKNOWN) {

		/* Invalid opcode */

		ACPI_ERROR((AE_INFO, "Invalid AML Opcode: 0x%2.2X",
			    op->common.aml_opcode));
		return_VOID;
	}

	/* Check if this opcode requires argument sub-objects */

	if (!(op_info->flags & AML_HAS_ARGS)) {

		/* Has no linked argument objects */

		return_VOID;
	}

	/* Append the argument to the linked argument list */

	if (op->common.value.arg) {

		/* Append to existing argument list */

		prev_arg = op->common.value.arg;
		while (prev_arg->common.next) {
			prev_arg = prev_arg->common.next;
		}
		prev_arg->common.next = arg;
	} else {
		/* No argument list, this will be the first argument */

		op->common.value.arg = arg;
	}

	/* Set the parent in this arg and any args linked after it */

	while (arg) {
		arg->common.parent = op;
		arg = arg->common.next;

		op->common.arg_list_length++;
	}

	return_VOID;
}

union acpi_parse_object *acpi_ps_get_depth_next(union acpi_parse_object *origin,
						union acpi_parse_object *op)
{
	union acpi_parse_object *next = NULL;
	union acpi_parse_object *parent;
	union acpi_parse_object *arg;

	ACPI_FUNCTION_ENTRY();

	if (!op) {
		return (NULL);
	}

	/* Look for an argument or child */

	next = acpi_ps_get_arg(op, 0);
	if (next) {
		ASL_CV_LABEL_FILENODE(next);
		return (next);
	}

	/* Look for a sibling */

	next = op->common.next;
	if (next) {
		ASL_CV_LABEL_FILENODE(next);
		return (next);
	}

	/* Look for a sibling of parent */

	parent = op->common.parent;

	while (parent) {
		arg = acpi_ps_get_arg(parent, 0);
		while (arg && (arg != origin) && (arg != op)) {

			ASL_CV_LABEL_FILENODE(arg);
			arg = arg->common.next;
		}

		if (arg == origin) {

			/* Reached parent of origin, end search */

			return (NULL);
		}

		if (parent->common.next) {

			/* Found sibling of parent */

			ASL_CV_LABEL_FILENODE(parent->common.next);
			return (parent->common.next);
		}

		op = parent;
		parent = parent->common.parent;
	}

	ASL_CV_LABEL_FILENODE(next);
	return (next);
}

