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
struct TYPE_4__ {char name; } ;
struct TYPE_3__ {scalar_t__ aml_opcode; int* aml; int flags; int /*<<< orphan*/  aml_op_name; int /*<<< orphan*/  descriptor_type; } ;
union acpi_parse_object {TYPE_2__ named; TYPE_1__ common; } ;
typedef  int u8 ;
typedef  char u32 ;
typedef  scalar_t__ u16 ;
struct acpi_opcode_info {int flags; int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_DB_ALLOCATIONS ; 
 int /*<<< orphan*/  ACPI_DEBUG_PRINT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_DESC_TYPE_PARSER ; 
 int /*<<< orphan*/  ACPI_DISASM_ONLY_MEMBERS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_ENTRY () ; 
 int /*<<< orphan*/  ACPI_FUNCTION_NAME (int /*<<< orphan*/ ) ; 
 int ACPI_PARSEOP_BYTELIST ; 
 int ACPI_PARSEOP_DEFERRED ; 
 int ACPI_PARSEOP_GENERIC ; 
 int ACPI_PARSEOP_NAMED_OBJECT ; 
 char ACPI_ROOT_NAME ; 
 int AML_DEFER ; 
 scalar_t__ AML_INT_BYTELIST_OP ; 
 scalar_t__ AML_INT_RETURN_VALUE_OP ; 
 int AML_NAMED ; 
 scalar_t__ AML_SCOPE_OP ; 
 int /*<<< orphan*/  ASL_CV_CLEAR_OP_COMMENTS (union acpi_parse_object*) ; 
 int /*<<< orphan*/  ASL_CV_TRANSFER_COMMENTS (union acpi_parse_object*) ; 
 scalar_t__ acpi_gbl_capture_comments ; 
 union acpi_parse_object* acpi_gbl_current_scope ; 
 int /*<<< orphan*/  acpi_gbl_ps_node_cache ; 
 int /*<<< orphan*/  acpi_gbl_ps_node_ext_cache ; 
 union acpi_parse_object* acpi_os_acquire_object (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  acpi_os_release_object (int /*<<< orphan*/ ,union acpi_parse_object*) ; 
 union acpi_parse_object* acpi_ps_alloc_op (scalar_t__,int*) ; 
 struct acpi_opcode_info* acpi_ps_get_opcode_info (scalar_t__) ; 
 int /*<<< orphan*/  acpi_ut_safe_strncpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ps_free_op ; 

union acpi_parse_object *acpi_ps_create_scope_op(u8 *aml)
{
	union acpi_parse_object *scope_op;

	scope_op = acpi_ps_alloc_op(AML_SCOPE_OP, aml);
	if (!scope_op) {
		return (NULL);
	}

	scope_op->named.name = ACPI_ROOT_NAME;
	return (scope_op);
}

void acpi_ps_init_op(union acpi_parse_object *op, u16 opcode)
{
	ACPI_FUNCTION_ENTRY();

	op->common.descriptor_type = ACPI_DESC_TYPE_PARSER;
	op->common.aml_opcode = opcode;

	ACPI_DISASM_ONLY_MEMBERS(acpi_ut_safe_strncpy(op->common.aml_op_name,
						      (acpi_ps_get_opcode_info
						       (opcode))->name,
						      sizeof(op->common.
							     aml_op_name)));
}

union acpi_parse_object *acpi_ps_alloc_op(u16 opcode, u8 *aml)
{
	union acpi_parse_object *op;
	const struct acpi_opcode_info *op_info;
	u8 flags = ACPI_PARSEOP_GENERIC;

	ACPI_FUNCTION_ENTRY();

	op_info = acpi_ps_get_opcode_info(opcode);

	/* Determine type of parse_op required */

	if (op_info->flags & AML_DEFER) {
		flags = ACPI_PARSEOP_DEFERRED;
	} else if (op_info->flags & AML_NAMED) {
		flags = ACPI_PARSEOP_NAMED_OBJECT;
	} else if (opcode == AML_INT_BYTELIST_OP) {
		flags = ACPI_PARSEOP_BYTELIST;
	}

	/* Allocate the minimum required size object */

	if (flags == ACPI_PARSEOP_GENERIC) {

		/* The generic op (default) is by far the most common (16 to 1) */

		op = acpi_os_acquire_object(acpi_gbl_ps_node_cache);
	} else {
		/* Extended parseop */

		op = acpi_os_acquire_object(acpi_gbl_ps_node_ext_cache);
	}

	/* Initialize the Op */

	if (op) {
		acpi_ps_init_op(op, opcode);
		op->common.aml = aml;
		op->common.flags = flags;
		ASL_CV_CLEAR_OP_COMMENTS(op);

		if (opcode == AML_SCOPE_OP) {
			acpi_gbl_current_scope = op;
		}

		if (acpi_gbl_capture_comments) {
			ASL_CV_TRANSFER_COMMENTS(op);
		}
	}

	return (op);
}

void acpi_ps_free_op(union acpi_parse_object *op)
{
	ACPI_FUNCTION_NAME(ps_free_op);

	ASL_CV_CLEAR_OP_COMMENTS(op);
	if (op->common.aml_opcode == AML_INT_RETURN_VALUE_OP) {
		ACPI_DEBUG_PRINT((ACPI_DB_ALLOCATIONS,
				  "Free retval op: %p\n", op));
	}

	if (op->common.flags & ACPI_PARSEOP_GENERIC) {
		(void)acpi_os_release_object(acpi_gbl_ps_node_cache, op);
	} else {
		(void)acpi_os_release_object(acpi_gbl_ps_node_ext_cache, op);
	}
}

u8 acpi_ps_is_leading_char(u32 c)
{
	return ((u8) (c == '_' || (c >= 'A' && c <= 'Z')));
}

u32 acpi_ps_get_name(union acpi_parse_object * op)
{

	/* The "generic" object has no name associated with it */

	if (op->common.flags & ACPI_PARSEOP_GENERIC) {
		return (0);
	}

	/* Only the "Extended" parse objects have a name */

	return (op->named.name);
}

void acpi_ps_set_name(union acpi_parse_object *op, u32 name)
{

	/* The "generic" object has no name associated with it */

	if (op->common.flags & ACPI_PARSEOP_GENERIC) {
		return;
	}

	op->named.name = name;
}

