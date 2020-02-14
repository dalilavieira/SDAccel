#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_20__   TYPE_9__ ;
typedef  struct TYPE_19__   TYPE_8__ ;
typedef  struct TYPE_18__   TYPE_7__ ;
typedef  struct TYPE_17__   TYPE_6__ ;
typedef  struct TYPE_16__   TYPE_5__ ;
typedef  struct TYPE_15__   TYPE_4__ ;
typedef  struct TYPE_14__   TYPE_3__ ;
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;
typedef  struct TYPE_11__   TYPE_10__ ;

/* Type definitions */
struct TYPE_18__ {union acpi_parse_object* arg; } ;
struct TYPE_11__ {scalar_t__ type; int reference_count; int aml_opcode; union acpi_parse_object* next; struct acpi_namespace_node* node; TYPE_7__ value; TYPE_6__* parent; } ;
struct TYPE_20__ {scalar_t__ value; } ;
struct TYPE_19__ {int value; } ;
struct TYPE_15__ {int length; int /*<<< orphan*/  flags; scalar_t__ address; int /*<<< orphan*/  space_id; } ;
struct TYPE_14__ {int /*<<< orphan*/  pointer; } ;
struct TYPE_13__ {int /*<<< orphan*/  flags; union acpi_parse_object* buffer_obj; } ;
struct TYPE_12__ {scalar_t__ length; } ;
union acpi_parse_object {TYPE_10__ common; TYPE_9__ integer; TYPE_8__ bank_field; TYPE_4__ region; TYPE_3__ string; TYPE_2__ buffer_field; TYPE_1__ buffer; } ;
union acpi_operand_object {TYPE_10__ common; TYPE_9__ integer; TYPE_8__ bank_field; TYPE_4__ region; TYPE_3__ string; TYPE_2__ buffer_field; TYPE_1__ buffer; } ;
typedef  int /*<<< orphan*/  u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct acpi_walk_state {int num_operands; int operand_index; int opcode; union acpi_parse_object** operands; union acpi_parse_object* result_obj; } ;
struct acpi_table_header {int length; } ;
struct acpi_namespace_node {int dummy; } ;
typedef  scalar_t__ acpi_status ;
typedef  scalar_t__ acpi_physical_address ;
typedef  struct acpi_namespace_node* acpi_handle ;
struct TYPE_16__ {int const aml_opcode; } ;
struct TYPE_17__ {TYPE_5__ common; } ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_DB_EXEC ; 
 int /*<<< orphan*/  ACPI_DEBUG_PRINT (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_DESC_TYPE_NAMED ; 
 int /*<<< orphan*/  ACPI_DUMP_OPERANDS (union acpi_parse_object**,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ACPI_ERROR (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_FAILURE (scalar_t__) ; 
 int /*<<< orphan*/  ACPI_FORMAT_UINT64 (scalar_t__) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_TRACE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_TRACE_PTR (int /*<<< orphan*/ ,union acpi_parse_object*) ; 
 scalar_t__ ACPI_GET_DESCRIPTOR_TYPE (union acpi_parse_object*) ; 
 scalar_t__ ACPI_PTR_TO_PHYSADDR (struct acpi_table_header*) ; 
 scalar_t__ ACPI_SUCCESS (scalar_t__) ; 
 scalar_t__ ACPI_TYPE_BUFFER ; 
 union acpi_parse_object** ACPI_WALK_OPERANDS ; 
 scalar_t__ AE_AML_BAD_OPCODE ; 
 scalar_t__ AE_AML_BUFFER_LIMIT ; 
 scalar_t__ AE_AML_OPERAND_TYPE ; 
 scalar_t__ AE_AML_OPERAND_VALUE ; 
 int /*<<< orphan*/  AE_INFO ; 
 scalar_t__ AE_NOT_EXIST ; 
 scalar_t__ AE_NOT_FOUND ; 
 scalar_t__ AE_OK ; 
#define  AML_BUFFER_OP 136 
#define  AML_CREATE_BIT_FIELD_OP 135 
#define  AML_CREATE_BYTE_FIELD_OP 134 
#define  AML_CREATE_DWORD_FIELD_OP 133 
#define  AML_CREATE_FIELD_OP 132 
#define  AML_CREATE_QWORD_FIELD_OP 131 
#define  AML_CREATE_WORD_FIELD_OP 130 
 int /*<<< orphan*/  AML_FIELD_ACCESS_BYTE ; 
 int /*<<< orphan*/  AML_FIELD_ACCESS_DWORD ; 
 int /*<<< orphan*/  AML_FIELD_ACCESS_QWORD ; 
 int /*<<< orphan*/  AML_FIELD_ACCESS_WORD ; 
 scalar_t__ AML_INT_NAMEDFIELD_OP ; 
 scalar_t__ AML_NAME_OP ; 
#define  AML_PACKAGE_OP 129 
#define  AML_VARIABLE_PACKAGE_OP 128 
 int /*<<< orphan*/  AOPOBJ_DATA_VALID ; 
 scalar_t__ acpi_ds_build_internal_buffer_obj (struct acpi_walk_state*,union acpi_parse_object*,int,union acpi_parse_object**) ; 
 scalar_t__ acpi_ds_build_internal_package_obj (struct acpi_walk_state*,union acpi_parse_object*,int,union acpi_parse_object**) ; 
 scalar_t__ acpi_ds_create_operand (struct acpi_walk_state*,union acpi_parse_object*,int) ; 
 scalar_t__ acpi_ds_create_operands (struct acpi_walk_state*,union acpi_parse_object*) ; 
 scalar_t__ acpi_ds_obj_stack_pop (int,struct acpi_walk_state*) ; 
 scalar_t__ acpi_ev_initialize_region (union acpi_parse_object*) ; 
 scalar_t__ acpi_ex_prep_common_field_object (union acpi_parse_object*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 scalar_t__ acpi_ex_resolve_operands (int,union acpi_parse_object**,struct acpi_walk_state*) ; 
 scalar_t__ acpi_ex_resolve_to_value (union acpi_parse_object**,struct acpi_walk_state*) ; 
 scalar_t__ acpi_get_table_by_index (int,struct acpi_table_header**) ; 
 union acpi_parse_object* acpi_ns_get_attached_object (struct acpi_namespace_node*) ; 
 union acpi_parse_object* acpi_ps_get_arg (union acpi_parse_object*,int) ; 
 int /*<<< orphan*/  acpi_ps_get_opcode_name (int) ; 
 scalar_t__ acpi_tb_find_table (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 scalar_t__ acpi_ut_add_address_range (int /*<<< orphan*/ ,scalar_t__,int,struct acpi_namespace_node*) ; 
 int /*<<< orphan*/  acpi_ut_get_descriptor_name (union acpi_parse_object*) ; 
 int /*<<< orphan*/  acpi_ut_get_node_name (union acpi_parse_object*) ; 
 int /*<<< orphan*/  acpi_ut_get_object_type_name (union acpi_parse_object*) ; 
 int /*<<< orphan*/  acpi_ut_remove_reference (union acpi_parse_object*) ; 
 int /*<<< orphan*/  ds_eval_bank_field_operands ; 
 int /*<<< orphan*/  ds_eval_buffer_field_operands ; 
 int /*<<< orphan*/  ds_eval_data_object_operands ; 
 int /*<<< orphan*/  ds_eval_region_operands ; 
 int /*<<< orphan*/  ds_eval_table_region_operands ; 
 int /*<<< orphan*/  ds_init_buffer_field ; 
 int /*<<< orphan*/  return_ACPI_STATUS (scalar_t__) ; 

acpi_status acpi_ds_initialize_region(acpi_handle obj_handle)
{
	union acpi_operand_object *obj_desc;
	acpi_status status;

	obj_desc = acpi_ns_get_attached_object(obj_handle);

	/* Namespace is NOT locked */

	status = acpi_ev_initialize_region(obj_desc);
	return (status);
}

__attribute__((used)) static acpi_status
acpi_ds_init_buffer_field(u16 aml_opcode,
			  union acpi_operand_object *obj_desc,
			  union acpi_operand_object *buffer_desc,
			  union acpi_operand_object *offset_desc,
			  union acpi_operand_object *length_desc,
			  union acpi_operand_object *result_desc)
{
	u32 offset;
	u32 bit_offset;
	u32 bit_count;
	u8 field_flags;
	acpi_status status;

	ACPI_FUNCTION_TRACE_PTR(ds_init_buffer_field, obj_desc);

	/* Host object must be a Buffer */

	if (buffer_desc->common.type != ACPI_TYPE_BUFFER) {
		ACPI_ERROR((AE_INFO,
			    "Target of Create Field is not a Buffer object - %s",
			    acpi_ut_get_object_type_name(buffer_desc)));

		status = AE_AML_OPERAND_TYPE;
		goto cleanup;
	}

	/*
	 * The last parameter to all of these opcodes (result_desc) started
	 * out as a name_string, and should therefore now be a NS node
	 * after resolution in acpi_ex_resolve_operands().
	 */
	if (ACPI_GET_DESCRIPTOR_TYPE(result_desc) != ACPI_DESC_TYPE_NAMED) {
		ACPI_ERROR((AE_INFO,
			    "(%s) destination not a NS Node [%s]",
			    acpi_ps_get_opcode_name(aml_opcode),
			    acpi_ut_get_descriptor_name(result_desc)));

		status = AE_AML_OPERAND_TYPE;
		goto cleanup;
	}

	offset = (u32) offset_desc->integer.value;

	/*
	 * Setup the Bit offsets and counts, according to the opcode
	 */
	switch (aml_opcode) {
	case AML_CREATE_FIELD_OP:

		/* Offset is in bits, count is in bits */

		field_flags = AML_FIELD_ACCESS_BYTE;
		bit_offset = offset;
		bit_count = (u32) length_desc->integer.value;

		/* Must have a valid (>0) bit count */

		if (bit_count == 0) {
			ACPI_ERROR((AE_INFO,
				    "Attempt to CreateField of length zero"));
			status = AE_AML_OPERAND_VALUE;
			goto cleanup;
		}
		break;

	case AML_CREATE_BIT_FIELD_OP:

		/* Offset is in bits, Field is one bit */

		bit_offset = offset;
		bit_count = 1;
		field_flags = AML_FIELD_ACCESS_BYTE;
		break;

	case AML_CREATE_BYTE_FIELD_OP:

		/* Offset is in bytes, field is one byte */

		bit_offset = 8 * offset;
		bit_count = 8;
		field_flags = AML_FIELD_ACCESS_BYTE;
		break;

	case AML_CREATE_WORD_FIELD_OP:

		/* Offset is in bytes, field is one word */

		bit_offset = 8 * offset;
		bit_count = 16;
		field_flags = AML_FIELD_ACCESS_WORD;
		break;

	case AML_CREATE_DWORD_FIELD_OP:

		/* Offset is in bytes, field is one dword */

		bit_offset = 8 * offset;
		bit_count = 32;
		field_flags = AML_FIELD_ACCESS_DWORD;
		break;

	case AML_CREATE_QWORD_FIELD_OP:

		/* Offset is in bytes, field is one qword */

		bit_offset = 8 * offset;
		bit_count = 64;
		field_flags = AML_FIELD_ACCESS_QWORD;
		break;

	default:

		ACPI_ERROR((AE_INFO,
			    "Unknown field creation opcode 0x%02X",
			    aml_opcode));
		status = AE_AML_BAD_OPCODE;
		goto cleanup;
	}

	/* Entire field must fit within the current length of the buffer */

	if ((bit_offset + bit_count) > (8 * (u32)buffer_desc->buffer.length)) {
		ACPI_ERROR((AE_INFO,
			    "Field [%4.4s] at bit offset/length %u/%u "
			    "exceeds size of target Buffer (%u bits)",
			    acpi_ut_get_node_name(result_desc), bit_offset,
			    bit_count, 8 * (u32)buffer_desc->buffer.length));
		status = AE_AML_BUFFER_LIMIT;
		goto cleanup;
	}

	/*
	 * Initialize areas of the field object that are common to all fields
	 * For field_flags, use LOCK_RULE = 0 (NO_LOCK),
	 * UPDATE_RULE = 0 (UPDATE_PRESERVE)
	 */
	status =
	    acpi_ex_prep_common_field_object(obj_desc, field_flags, 0,
					     bit_offset, bit_count);
	if (ACPI_FAILURE(status)) {
		goto cleanup;
	}

	obj_desc->buffer_field.buffer_obj = buffer_desc;

	/* Reference count for buffer_desc inherits obj_desc count */

	buffer_desc->common.reference_count = (u16)
	    (buffer_desc->common.reference_count +
	     obj_desc->common.reference_count);

cleanup:

	/* Always delete the operands */

	acpi_ut_remove_reference(offset_desc);
	acpi_ut_remove_reference(buffer_desc);

	if (aml_opcode == AML_CREATE_FIELD_OP) {
		acpi_ut_remove_reference(length_desc);
	}

	/* On failure, delete the result descriptor */

	if (ACPI_FAILURE(status)) {
		acpi_ut_remove_reference(result_desc);	/* Result descriptor */
	} else {
		/* Now the address and length are valid for this buffer_field */

		obj_desc->buffer_field.flags |= AOPOBJ_DATA_VALID;
	}

	return_ACPI_STATUS(status);
}

acpi_status
acpi_ds_eval_buffer_field_operands(struct acpi_walk_state *walk_state,
				   union acpi_parse_object *op)
{
	acpi_status status;
	union acpi_operand_object *obj_desc;
	struct acpi_namespace_node *node;
	union acpi_parse_object *next_op;

	ACPI_FUNCTION_TRACE_PTR(ds_eval_buffer_field_operands, op);

	/*
	 * This is where we evaluate the address and length fields of the
	 * create_xxx_field declaration
	 */
	node = op->common.node;

	/* next_op points to the op that holds the Buffer */

	next_op = op->common.value.arg;

	/* Evaluate/create the address and length operands */

	status = acpi_ds_create_operands(walk_state, next_op);
	if (ACPI_FAILURE(status)) {
		return_ACPI_STATUS(status);
	}

	obj_desc = acpi_ns_get_attached_object(node);
	if (!obj_desc) {
		return_ACPI_STATUS(AE_NOT_EXIST);
	}

	/* Resolve the operands */

	status =
	    acpi_ex_resolve_operands(op->common.aml_opcode, ACPI_WALK_OPERANDS,
				     walk_state);
	if (ACPI_FAILURE(status)) {
		ACPI_ERROR((AE_INFO, "(%s) bad operand(s), status 0x%X",
			    acpi_ps_get_opcode_name(op->common.aml_opcode),
			    status));

		return_ACPI_STATUS(status);
	}

	/* Initialize the Buffer Field */

	if (op->common.aml_opcode == AML_CREATE_FIELD_OP) {

		/* NOTE: Slightly different operands for this opcode */

		status =
		    acpi_ds_init_buffer_field(op->common.aml_opcode, obj_desc,
					      walk_state->operands[0],
					      walk_state->operands[1],
					      walk_state->operands[2],
					      walk_state->operands[3]);
	} else {
		/* All other, create_xxx_field opcodes */

		status =
		    acpi_ds_init_buffer_field(op->common.aml_opcode, obj_desc,
					      walk_state->operands[0],
					      walk_state->operands[1], NULL,
					      walk_state->operands[2]);
	}

	return_ACPI_STATUS(status);
}

acpi_status
acpi_ds_eval_region_operands(struct acpi_walk_state *walk_state,
			     union acpi_parse_object *op)
{
	acpi_status status;
	union acpi_operand_object *obj_desc;
	union acpi_operand_object *operand_desc;
	struct acpi_namespace_node *node;
	union acpi_parse_object *next_op;

	ACPI_FUNCTION_TRACE_PTR(ds_eval_region_operands, op);

	/*
	 * This is where we evaluate the address and length fields of the
	 * op_region declaration
	 */
	node = op->common.node;

	/* next_op points to the op that holds the space_ID */

	next_op = op->common.value.arg;

	/* next_op points to address op */

	next_op = next_op->common.next;

	/* Evaluate/create the address and length operands */

	status = acpi_ds_create_operands(walk_state, next_op);
	if (ACPI_FAILURE(status)) {
		return_ACPI_STATUS(status);
	}

	/* Resolve the length and address operands to numbers */

	status =
	    acpi_ex_resolve_operands(op->common.aml_opcode, ACPI_WALK_OPERANDS,
				     walk_state);
	if (ACPI_FAILURE(status)) {
		return_ACPI_STATUS(status);
	}

	obj_desc = acpi_ns_get_attached_object(node);
	if (!obj_desc) {
		return_ACPI_STATUS(AE_NOT_EXIST);
	}

	/*
	 * Get the length operand and save it
	 * (at Top of stack)
	 */
	operand_desc = walk_state->operands[walk_state->num_operands - 1];

	obj_desc->region.length = (u32) operand_desc->integer.value;
	acpi_ut_remove_reference(operand_desc);

	/*
	 * Get the address and save it
	 * (at top of stack - 1)
	 */
	operand_desc = walk_state->operands[walk_state->num_operands - 2];

	obj_desc->region.address = (acpi_physical_address)
	    operand_desc->integer.value;
	acpi_ut_remove_reference(operand_desc);

	ACPI_DEBUG_PRINT((ACPI_DB_EXEC, "RgnObj %p Addr %8.8X%8.8X Len %X\n",
			  obj_desc,
			  ACPI_FORMAT_UINT64(obj_desc->region.address),
			  obj_desc->region.length));

	status = acpi_ut_add_address_range(obj_desc->region.space_id,
					   obj_desc->region.address,
					   obj_desc->region.length, node);

	/* Now the address and length are valid for this opregion */

	obj_desc->region.flags |= AOPOBJ_DATA_VALID;
	return_ACPI_STATUS(status);
}

acpi_status
acpi_ds_eval_table_region_operands(struct acpi_walk_state *walk_state,
				   union acpi_parse_object *op)
{
	acpi_status status;
	union acpi_operand_object *obj_desc;
	union acpi_operand_object **operand;
	struct acpi_namespace_node *node;
	union acpi_parse_object *next_op;
	struct acpi_table_header *table;
	u32 table_index;

	ACPI_FUNCTION_TRACE_PTR(ds_eval_table_region_operands, op);

	/*
	 * This is where we evaluate the Signature string, oem_id string,
	 * and oem_table_id string of the Data Table Region declaration
	 */
	node = op->common.node;

	/* next_op points to Signature string op */

	next_op = op->common.value.arg;

	/*
	 * Evaluate/create the Signature string, oem_id string,
	 * and oem_table_id string operands
	 */
	status = acpi_ds_create_operands(walk_state, next_op);
	if (ACPI_FAILURE(status)) {
		return_ACPI_STATUS(status);
	}

	operand = &walk_state->operands[0];

	/*
	 * Resolve the Signature string, oem_id string,
	 * and oem_table_id string operands
	 */
	status =
	    acpi_ex_resolve_operands(op->common.aml_opcode, ACPI_WALK_OPERANDS,
				     walk_state);
	if (ACPI_FAILURE(status)) {
		goto cleanup;
	}

	/* Find the ACPI table */

	status = acpi_tb_find_table(operand[0]->string.pointer,
				    operand[1]->string.pointer,
				    operand[2]->string.pointer, &table_index);
	if (ACPI_FAILURE(status)) {
		if (status == AE_NOT_FOUND) {
			ACPI_ERROR((AE_INFO,
				    "ACPI Table [%4.4s] OEM:(%s, %s) not found in RSDT/XSDT",
				    operand[0]->string.pointer,
				    operand[1]->string.pointer,
				    operand[2]->string.pointer));
		}
		goto cleanup;
	}

	status = acpi_get_table_by_index(table_index, &table);
	if (ACPI_FAILURE(status)) {
		goto cleanup;
	}

	obj_desc = acpi_ns_get_attached_object(node);
	if (!obj_desc) {
		status = AE_NOT_EXIST;
		goto cleanup;
	}

	obj_desc->region.address = ACPI_PTR_TO_PHYSADDR(table);
	obj_desc->region.length = table->length;

	ACPI_DEBUG_PRINT((ACPI_DB_EXEC, "RgnObj %p Addr %8.8X%8.8X Len %X\n",
			  obj_desc,
			  ACPI_FORMAT_UINT64(obj_desc->region.address),
			  obj_desc->region.length));

	status = acpi_ut_add_address_range(obj_desc->region.space_id,
					   obj_desc->region.address,
					   obj_desc->region.length, node);

	/* Now the address and length are valid for this opregion */

	obj_desc->region.flags |= AOPOBJ_DATA_VALID;

cleanup:
	acpi_ut_remove_reference(operand[0]);
	acpi_ut_remove_reference(operand[1]);
	acpi_ut_remove_reference(operand[2]);

	return_ACPI_STATUS(status);
}

acpi_status
acpi_ds_eval_data_object_operands(struct acpi_walk_state *walk_state,
				  union acpi_parse_object *op,
				  union acpi_operand_object *obj_desc)
{
	acpi_status status;
	union acpi_operand_object *arg_desc;
	u32 length;

	ACPI_FUNCTION_TRACE(ds_eval_data_object_operands);

	/* The first operand (for all of these data objects) is the length */

	/*
	 * Set proper index into operand stack for acpi_ds_obj_stack_push
	 * invoked inside acpi_ds_create_operand.
	 */
	walk_state->operand_index = walk_state->num_operands;

	/* Ignore if child is not valid */

	if (!op->common.value.arg) {
		ACPI_ERROR((AE_INFO,
			    "Missing child while evaluating opcode %4.4X, Op %p",
			    op->common.aml_opcode, op));
		return_ACPI_STATUS(AE_OK);
	}

	status = acpi_ds_create_operand(walk_state, op->common.value.arg, 1);
	if (ACPI_FAILURE(status)) {
		return_ACPI_STATUS(status);
	}

	status = acpi_ex_resolve_operands(walk_state->opcode,
					  &(walk_state->
					    operands[walk_state->num_operands -
						     1]), walk_state);
	if (ACPI_FAILURE(status)) {
		return_ACPI_STATUS(status);
	}

	/* Extract length operand */

	arg_desc = walk_state->operands[walk_state->num_operands - 1];
	length = (u32) arg_desc->integer.value;

	/* Cleanup for length operand */

	status = acpi_ds_obj_stack_pop(1, walk_state);
	if (ACPI_FAILURE(status)) {
		return_ACPI_STATUS(status);
	}

	acpi_ut_remove_reference(arg_desc);

	/*
	 * Create the actual data object
	 */
	switch (op->common.aml_opcode) {
	case AML_BUFFER_OP:

		status =
		    acpi_ds_build_internal_buffer_obj(walk_state, op, length,
						      &obj_desc);
		break;

	case AML_PACKAGE_OP:
	case AML_VARIABLE_PACKAGE_OP:

		status =
		    acpi_ds_build_internal_package_obj(walk_state, op, length,
						       &obj_desc);
		break;

	default:

		return_ACPI_STATUS(AE_AML_BAD_OPCODE);
	}

	if (ACPI_SUCCESS(status)) {
		/*
		 * Return the object in the walk_state, unless the parent is a package -
		 * in this case, the return object will be stored in the parse tree
		 * for the package.
		 */
		if ((!op->common.parent) ||
		    ((op->common.parent->common.aml_opcode != AML_PACKAGE_OP) &&
		     (op->common.parent->common.aml_opcode !=
		      AML_VARIABLE_PACKAGE_OP)
		     && (op->common.parent->common.aml_opcode !=
			 AML_NAME_OP))) {
			walk_state->result_obj = obj_desc;
		}
	}

	return_ACPI_STATUS(status);
}

acpi_status
acpi_ds_eval_bank_field_operands(struct acpi_walk_state *walk_state,
				 union acpi_parse_object *op)
{
	acpi_status status;
	union acpi_operand_object *obj_desc;
	union acpi_operand_object *operand_desc;
	struct acpi_namespace_node *node;
	union acpi_parse_object *next_op;
	union acpi_parse_object *arg;

	ACPI_FUNCTION_TRACE_PTR(ds_eval_bank_field_operands, op);

	/*
	 * This is where we evaluate the bank_value field of the
	 * bank_field declaration
	 */

	/* next_op points to the op that holds the Region */

	next_op = op->common.value.arg;

	/* next_op points to the op that holds the Bank Register */

	next_op = next_op->common.next;

	/* next_op points to the op that holds the Bank Value */

	next_op = next_op->common.next;

	/*
	 * Set proper index into operand stack for acpi_ds_obj_stack_push
	 * invoked inside acpi_ds_create_operand.
	 *
	 * We use walk_state->Operands[0] to store the evaluated bank_value
	 */
	walk_state->operand_index = 0;

	status = acpi_ds_create_operand(walk_state, next_op, 0);
	if (ACPI_FAILURE(status)) {
		return_ACPI_STATUS(status);
	}

	status = acpi_ex_resolve_to_value(&walk_state->operands[0], walk_state);
	if (ACPI_FAILURE(status)) {
		return_ACPI_STATUS(status);
	}

	ACPI_DUMP_OPERANDS(ACPI_WALK_OPERANDS,
			   acpi_ps_get_opcode_name(op->common.aml_opcode), 1);
	/*
	 * Get the bank_value operand and save it
	 * (at Top of stack)
	 */
	operand_desc = walk_state->operands[0];

	/* Arg points to the start Bank Field */

	arg = acpi_ps_get_arg(op, 4);
	while (arg) {

		/* Ignore OFFSET and ACCESSAS terms here */

		if (arg->common.aml_opcode == AML_INT_NAMEDFIELD_OP) {
			node = arg->common.node;

			obj_desc = acpi_ns_get_attached_object(node);
			if (!obj_desc) {
				return_ACPI_STATUS(AE_NOT_EXIST);
			}

			obj_desc->bank_field.value =
			    (u32) operand_desc->integer.value;
		}

		/* Move to next field in the list */

		arg = arg->common.next;
	}

	acpi_ut_remove_reference(operand_desc);
	return_ACPI_STATUS(status);
}

