#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_8__ {scalar_t__ length; int /*<<< orphan*/  pointer; } ;
struct TYPE_7__ {int value; } ;
struct TYPE_6__ {int type; } ;
struct TYPE_5__ {union acpi_operand_object* object; int /*<<< orphan*/  class; } ;
union acpi_operand_object {TYPE_4__ buffer; TYPE_3__ integer; TYPE_2__ common; TYPE_1__ reference; } ;
typedef  int /*<<< orphan*/  u8 ;
typedef  int u64 ;
typedef  scalar_t__ u32 ;
typedef  int u16 ;
struct acpi_walk_state {int dummy; } ;
typedef  int /*<<< orphan*/  acpi_status ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_DB_EXEC ; 
 int /*<<< orphan*/  ACPI_DEBUG_PRINT (int /*<<< orphan*/ ) ; 
#define  ACPI_DESC_TYPE_NAMED 150 
#define  ACPI_DESC_TYPE_OPERAND 149 
 int /*<<< orphan*/  ACPI_ERROR (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_ENTRY () ; 
 int /*<<< orphan*/  ACPI_FUNCTION_TRACE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_TRACE_PTR (int /*<<< orphan*/ ,union acpi_operand_object*) ; 
 int ACPI_GET_DESCRIPTOR_TYPE (union acpi_operand_object*) ; 
 int /*<<< orphan*/  ACPI_IMPLICIT_CONVERSION ; 
 int /*<<< orphan*/  ACPI_IMPLICIT_CONVERT_HEX ; 
#define  ACPI_REFCLASS_ARG 148 
#define  ACPI_REFCLASS_DEBUG 147 
#define  ACPI_REFCLASS_LOCAL 146 
 int /*<<< orphan*/  ACPI_REFCLASS_REFOF ; 
#define  ACPI_TYPE_BUFFER 145 
#define  ACPI_TYPE_INTEGER 144 
 int ACPI_TYPE_LOCAL_REFERENCE ; 
#define  ACPI_TYPE_STRING 143 
 int /*<<< orphan*/  AE_AML_INTERNAL ; 
 int /*<<< orphan*/  AE_AML_OPERAND_TYPE ; 
 int /*<<< orphan*/  AE_INFO ; 
 int /*<<< orphan*/  AE_NO_MEMORY ; 
 int /*<<< orphan*/  AE_OK ; 
 int /*<<< orphan*/  AE_TYPE ; 
#define  AML_ADD_OP 142 
#define  AML_BIT_AND_OP 141 
#define  AML_BIT_NAND_OP 140 
#define  AML_BIT_NOR_OP 139 
#define  AML_BIT_OR_OP 138 
#define  AML_BIT_XOR_OP 137 
#define  AML_LOGICAL_AND_OP 136 
#define  AML_LOGICAL_EQUAL_OP 135 
#define  AML_LOGICAL_GREATER_OP 134 
#define  AML_LOGICAL_LESS_OP 133 
#define  AML_LOGICAL_OR_OP 132 
#define  AML_MULTIPLY_OP 131 
#define  AML_SHIFT_LEFT_OP 130 
#define  AML_SHIFT_RIGHT_OP 129 
#define  AML_SUBTRACT_OP 128 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  acpi_ex_convert_to_buffer (union acpi_operand_object*,union acpi_operand_object**) ; 
 int /*<<< orphan*/  acpi_ex_convert_to_integer (union acpi_operand_object*,union acpi_operand_object**,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  acpi_ex_convert_to_string (union acpi_operand_object*,union acpi_operand_object**,int /*<<< orphan*/ ) ; 
 int acpi_gbl_integer_bit_width ; 
 union acpi_operand_object* acpi_ut_create_internal_object (int) ; 
 int /*<<< orphan*/  acpi_ut_get_object_type_name (union acpi_operand_object*) ; 
 int /*<<< orphan*/  acpi_ut_remove_reference (union acpi_operand_object*) ; 
 int /*<<< orphan*/  ex_do_logical_numeric_op ; 
 int /*<<< orphan*/  ex_do_logical_op ; 
 int /*<<< orphan*/  ex_get_object_reference ; 
 int memcmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  return_ACPI_STATUS (int /*<<< orphan*/ ) ; 

acpi_status
acpi_ex_get_object_reference(union acpi_operand_object *obj_desc,
			     union acpi_operand_object **return_desc,
			     struct acpi_walk_state *walk_state)
{
	union acpi_operand_object *reference_obj;
	union acpi_operand_object *referenced_obj;

	ACPI_FUNCTION_TRACE_PTR(ex_get_object_reference, obj_desc);

	*return_desc = NULL;

	switch (ACPI_GET_DESCRIPTOR_TYPE(obj_desc)) {
	case ACPI_DESC_TYPE_OPERAND:

		if (obj_desc->common.type != ACPI_TYPE_LOCAL_REFERENCE) {
			return_ACPI_STATUS(AE_AML_OPERAND_TYPE);
		}

		/*
		 * Must be a reference to a Local or Arg
		 */
		switch (obj_desc->reference.class) {
		case ACPI_REFCLASS_LOCAL:
		case ACPI_REFCLASS_ARG:
		case ACPI_REFCLASS_DEBUG:

			/* The referenced object is the pseudo-node for the local/arg */

			referenced_obj = obj_desc->reference.object;
			break;

		default:

			ACPI_ERROR((AE_INFO, "Invalid Reference Class 0x%2.2X",
				    obj_desc->reference.class));
			return_ACPI_STATUS(AE_AML_OPERAND_TYPE);
		}
		break;

	case ACPI_DESC_TYPE_NAMED:
		/*
		 * A named reference that has already been resolved to a Node
		 */
		referenced_obj = obj_desc;
		break;

	default:

		ACPI_ERROR((AE_INFO, "Invalid descriptor type 0x%X",
			    ACPI_GET_DESCRIPTOR_TYPE(obj_desc)));
		return_ACPI_STATUS(AE_TYPE);
	}

	/* Create a new reference object */

	reference_obj =
	    acpi_ut_create_internal_object(ACPI_TYPE_LOCAL_REFERENCE);
	if (!reference_obj) {
		return_ACPI_STATUS(AE_NO_MEMORY);
	}

	reference_obj->reference.class = ACPI_REFCLASS_REFOF;
	reference_obj->reference.object = referenced_obj;
	*return_desc = reference_obj;

	ACPI_DEBUG_PRINT((ACPI_DB_EXEC,
			  "Object %p Type [%s], returning Reference %p\n",
			  obj_desc, acpi_ut_get_object_type_name(obj_desc),
			  *return_desc));

	return_ACPI_STATUS(AE_OK);
}

u64 acpi_ex_do_math_op(u16 opcode, u64 integer0, u64 integer1)
{

	ACPI_FUNCTION_ENTRY();

	switch (opcode) {
	case AML_ADD_OP:	/* Add (Integer0, Integer1, Result) */

		return (integer0 + integer1);

	case AML_BIT_AND_OP:	/* And (Integer0, Integer1, Result) */

		return (integer0 & integer1);

	case AML_BIT_NAND_OP:	/* NAnd (Integer0, Integer1, Result) */

		return (~(integer0 & integer1));

	case AML_BIT_OR_OP:	/* Or (Integer0, Integer1, Result) */

		return (integer0 | integer1);

	case AML_BIT_NOR_OP:	/* NOr (Integer0, Integer1, Result) */

		return (~(integer0 | integer1));

	case AML_BIT_XOR_OP:	/* XOr (Integer0, Integer1, Result) */

		return (integer0 ^ integer1);

	case AML_MULTIPLY_OP:	/* Multiply (Integer0, Integer1, Result) */

		return (integer0 * integer1);

	case AML_SHIFT_LEFT_OP:	/* shift_left (Operand, shift_count, Result) */

		/*
		 * We need to check if the shiftcount is larger than the integer bit
		 * width since the behavior of this is not well-defined in the C language.
		 */
		if (integer1 >= acpi_gbl_integer_bit_width) {
			return (0);
		}
		return (integer0 << integer1);

	case AML_SHIFT_RIGHT_OP:	/* shift_right (Operand, shift_count, Result) */

		/*
		 * We need to check if the shiftcount is larger than the integer bit
		 * width since the behavior of this is not well-defined in the C language.
		 */
		if (integer1 >= acpi_gbl_integer_bit_width) {
			return (0);
		}
		return (integer0 >> integer1);

	case AML_SUBTRACT_OP:	/* Subtract (Integer0, Integer1, Result) */

		return (integer0 - integer1);

	default:

		return (0);
	}
}

acpi_status
acpi_ex_do_logical_numeric_op(u16 opcode,
			      u64 integer0, u64 integer1, u8 *logical_result)
{
	acpi_status status = AE_OK;
	u8 local_result = FALSE;

	ACPI_FUNCTION_TRACE(ex_do_logical_numeric_op);

	switch (opcode) {
	case AML_LOGICAL_AND_OP:	/* LAnd (Integer0, Integer1) */

		if (integer0 && integer1) {
			local_result = TRUE;
		}
		break;

	case AML_LOGICAL_OR_OP:	/* LOr (Integer0, Integer1) */

		if (integer0 || integer1) {
			local_result = TRUE;
		}
		break;

	default:

		ACPI_ERROR((AE_INFO,
			    "Invalid numeric logical opcode: %X", opcode));
		status = AE_AML_INTERNAL;
		break;
	}

	/* Return the logical result and status */

	*logical_result = local_result;
	return_ACPI_STATUS(status);
}

acpi_status
acpi_ex_do_logical_op(u16 opcode,
		      union acpi_operand_object *operand0,
		      union acpi_operand_object *operand1, u8 * logical_result)
{
	union acpi_operand_object *local_operand1 = operand1;
	u64 integer0;
	u64 integer1;
	u32 length0;
	u32 length1;
	acpi_status status = AE_OK;
	u8 local_result = FALSE;
	int compare;

	ACPI_FUNCTION_TRACE(ex_do_logical_op);

	/*
	 * Convert the second operand if necessary. The first operand
	 * determines the type of the second operand, (See the Data Types
	 * section of the ACPI 3.0+ specification.)  Both object types are
	 * guaranteed to be either Integer/String/Buffer by the operand
	 * resolution mechanism.
	 */
	switch (operand0->common.type) {
	case ACPI_TYPE_INTEGER:

		status = acpi_ex_convert_to_integer(operand1, &local_operand1,
						    ACPI_IMPLICIT_CONVERSION);
		break;

	case ACPI_TYPE_STRING:

		status =
		    acpi_ex_convert_to_string(operand1, &local_operand1,
					      ACPI_IMPLICIT_CONVERT_HEX);
		break;

	case ACPI_TYPE_BUFFER:

		status = acpi_ex_convert_to_buffer(operand1, &local_operand1);
		break;

	default:

		ACPI_ERROR((AE_INFO,
			    "Invalid object type for logical operator: %X",
			    operand0->common.type));
		status = AE_AML_INTERNAL;
		break;
	}

	if (ACPI_FAILURE(status)) {
		goto cleanup;
	}

	/*
	 * Two cases: 1) Both Integers, 2) Both Strings or Buffers
	 */
	if (operand0->common.type == ACPI_TYPE_INTEGER) {
		/*
		 * 1) Both operands are of type integer
		 *    Note: local_operand1 may have changed above
		 */
		integer0 = operand0->integer.value;
		integer1 = local_operand1->integer.value;

		switch (opcode) {
		case AML_LOGICAL_EQUAL_OP:	/* LEqual (Operand0, Operand1) */

			if (integer0 == integer1) {
				local_result = TRUE;
			}
			break;

		case AML_LOGICAL_GREATER_OP:	/* LGreater (Operand0, Operand1) */

			if (integer0 > integer1) {
				local_result = TRUE;
			}
			break;

		case AML_LOGICAL_LESS_OP:	/* LLess (Operand0, Operand1) */

			if (integer0 < integer1) {
				local_result = TRUE;
			}
			break;

		default:

			ACPI_ERROR((AE_INFO,
				    "Invalid comparison opcode: %X", opcode));
			status = AE_AML_INTERNAL;
			break;
		}
	} else {
		/*
		 * 2) Both operands are Strings or both are Buffers
		 *    Note: Code below takes advantage of common Buffer/String
		 *          object fields. local_operand1 may have changed above. Use
		 *          memcmp to handle nulls in buffers.
		 */
		length0 = operand0->buffer.length;
		length1 = local_operand1->buffer.length;

		/* Lexicographic compare: compare the data bytes */

		compare = memcmp(operand0->buffer.pointer,
				 local_operand1->buffer.pointer,
				 (length0 > length1) ? length1 : length0);

		switch (opcode) {
		case AML_LOGICAL_EQUAL_OP:	/* LEqual (Operand0, Operand1) */

			/* Length and all bytes must be equal */

			if ((length0 == length1) && (compare == 0)) {

				/* Length and all bytes match ==> TRUE */

				local_result = TRUE;
			}
			break;

		case AML_LOGICAL_GREATER_OP:	/* LGreater (Operand0, Operand1) */

			if (compare > 0) {
				local_result = TRUE;
				goto cleanup;	/* TRUE */
			}
			if (compare < 0) {
				goto cleanup;	/* FALSE */
			}

			/* Bytes match (to shortest length), compare lengths */

			if (length0 > length1) {
				local_result = TRUE;
			}
			break;

		case AML_LOGICAL_LESS_OP:	/* LLess (Operand0, Operand1) */

			if (compare > 0) {
				goto cleanup;	/* FALSE */
			}
			if (compare < 0) {
				local_result = TRUE;
				goto cleanup;	/* TRUE */
			}

			/* Bytes match (to shortest length), compare lengths */

			if (length0 < length1) {
				local_result = TRUE;
			}
			break;

		default:

			ACPI_ERROR((AE_INFO,
				    "Invalid comparison opcode: %X", opcode));
			status = AE_AML_INTERNAL;
			break;
		}
	}

cleanup:

	/* New object was created if implicit conversion performed - delete */

	if (local_operand1 != operand1) {
		acpi_ut_remove_reference(local_operand1);
	}

	/* Return the logical result and status */

	*logical_result = local_result;
	return_ACPI_STATUS(status);
}

