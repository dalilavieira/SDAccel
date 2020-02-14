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
struct TYPE_8__ {char* pointer; int length; } ;
struct TYPE_7__ {int length; char* pointer; } ;
struct TYPE_6__ {int type; } ;
struct TYPE_5__ {char value; } ;
union acpi_operand_object {TYPE_4__ buffer; TYPE_3__ string; TYPE_2__ common; TYPE_1__ integer; } ;
typedef  char u8 ;
struct aml_resource_end_tag {int dummy; } ;
struct acpi_walk_state {int dummy; } ;
typedef  int /*<<< orphan*/  acpi_status ;
typedef  int acpi_size ;
typedef  int acpi_object_type ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_ERROR (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_TRACE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_IMPLICIT_CONVERSION ; 
 int /*<<< orphan*/  ACPI_IMPLICIT_CONVERT_HEX ; 
 scalar_t__ ACPI_MUL_2 (int) ; 
 int ACPI_PTR_DIFF (char*,char*) ; 
 int ACPI_RESOURCE_NAME_END_TAG ; 
#define  ACPI_TYPE_BUFFER 130 
#define  ACPI_TYPE_INTEGER 129 
#define  ACPI_TYPE_STRING 128 
 int /*<<< orphan*/  AE_AML_INTERNAL ; 
 int /*<<< orphan*/  AE_INFO ; 
 int /*<<< orphan*/  AE_NO_MEMORY ; 
 int /*<<< orphan*/  AE_OK ; 
 int /*<<< orphan*/  acpi_ex_convert_to_buffer (union acpi_operand_object*,union acpi_operand_object**) ; 
 int /*<<< orphan*/  acpi_ex_convert_to_integer (union acpi_operand_object*,union acpi_operand_object**,int /*<<< orphan*/ ) ; 
static  int /*<<< orphan*/  acpi_ex_convert_to_object_type_string (union acpi_operand_object*,union acpi_operand_object**) ; 
 int /*<<< orphan*/  acpi_ex_convert_to_string (union acpi_operand_object*,union acpi_operand_object**,int /*<<< orphan*/ ) ; 
 int acpi_gbl_integer_byte_width ; 
 union acpi_operand_object* acpi_ut_create_buffer_object (int) ; 
 union acpi_operand_object* acpi_ut_create_string_object (int) ; 
 int /*<<< orphan*/  acpi_ut_get_resource_end_tag (union acpi_operand_object*,char**) ; 
 char* acpi_ut_get_type_name (int) ; 
 int /*<<< orphan*/  acpi_ut_remove_reference (union acpi_operand_object*) ; 
 int /*<<< orphan*/  ex_concat_template ; 
 int /*<<< orphan*/  ex_do_concatenate ; 
 int /*<<< orphan*/  memcpy (char*,char*,int) ; 
 int /*<<< orphan*/  return_ACPI_STATUS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strcat (char*,char const*) ; 
 int /*<<< orphan*/  strcpy (char*,char*) ; 
 scalar_t__ strlen (char const*) ; 

acpi_status
acpi_ex_do_concatenate(union acpi_operand_object *operand0,
		       union acpi_operand_object *operand1,
		       union acpi_operand_object **actual_return_desc,
		       struct acpi_walk_state *walk_state)
{
	union acpi_operand_object *local_operand0 = operand0;
	union acpi_operand_object *local_operand1 = operand1;
	union acpi_operand_object *temp_operand1 = NULL;
	union acpi_operand_object *return_desc;
	char *buffer;
	acpi_object_type operand0_type;
	acpi_object_type operand1_type;
	acpi_status status;

	ACPI_FUNCTION_TRACE(ex_do_concatenate);

	/* Operand 0 preprocessing */

	switch (operand0->common.type) {
	case ACPI_TYPE_INTEGER:
	case ACPI_TYPE_STRING:
	case ACPI_TYPE_BUFFER:

		operand0_type = operand0->common.type;
		break;

	default:

		/* For all other types, get the "object type" string */

		status =
		    acpi_ex_convert_to_object_type_string(operand0,
							  &local_operand0);
		if (ACPI_FAILURE(status)) {
			goto cleanup;
		}

		operand0_type = ACPI_TYPE_STRING;
		break;
	}

	/* Operand 1 preprocessing */

	switch (operand1->common.type) {
	case ACPI_TYPE_INTEGER:
	case ACPI_TYPE_STRING:
	case ACPI_TYPE_BUFFER:

		operand1_type = operand1->common.type;
		break;

	default:

		/* For all other types, get the "object type" string */

		status =
		    acpi_ex_convert_to_object_type_string(operand1,
							  &local_operand1);
		if (ACPI_FAILURE(status)) {
			goto cleanup;
		}

		operand1_type = ACPI_TYPE_STRING;
		break;
	}

	/*
	 * Convert the second operand if necessary. The first operand (0)
	 * determines the type of the second operand (1) (See the Data Types
	 * section of the ACPI specification). Both object types are
	 * guaranteed to be either Integer/String/Buffer by the operand
	 * resolution mechanism.
	 */
	switch (operand0_type) {
	case ACPI_TYPE_INTEGER:

		status =
		    acpi_ex_convert_to_integer(local_operand1, &temp_operand1,
					       ACPI_IMPLICIT_CONVERSION);
		break;

	case ACPI_TYPE_BUFFER:

		status =
		    acpi_ex_convert_to_buffer(local_operand1, &temp_operand1);
		break;

	case ACPI_TYPE_STRING:

		switch (operand1_type) {
		case ACPI_TYPE_INTEGER:
		case ACPI_TYPE_STRING:
		case ACPI_TYPE_BUFFER:

			/* Other types have already been converted to string */

			status =
			    acpi_ex_convert_to_string(local_operand1,
						      &temp_operand1,
						      ACPI_IMPLICIT_CONVERT_HEX);
			break;

		default:

			status = AE_OK;
			break;
		}
		break;

	default:

		ACPI_ERROR((AE_INFO, "Invalid object type: 0x%X",
			    operand0->common.type));
		status = AE_AML_INTERNAL;
	}

	if (ACPI_FAILURE(status)) {
		goto cleanup;
	}

	/* Take care with any newly created operand objects */

	if ((local_operand1 != operand1) && (local_operand1 != temp_operand1)) {
		acpi_ut_remove_reference(local_operand1);
	}

	local_operand1 = temp_operand1;

	/*
	 * Both operands are now known to be the same object type
	 * (Both are Integer, String, or Buffer), and we can now perform
	 * the concatenation.
	 *
	 * There are three cases to handle, as per the ACPI spec:
	 *
	 * 1) Two Integers concatenated to produce a new Buffer
	 * 2) Two Strings concatenated to produce a new String
	 * 3) Two Buffers concatenated to produce a new Buffer
	 */
	switch (operand0_type) {
	case ACPI_TYPE_INTEGER:

		/* Result of two Integers is a Buffer */
		/* Need enough buffer space for two integers */

		return_desc = acpi_ut_create_buffer_object((acpi_size)
							   ACPI_MUL_2
							   (acpi_gbl_integer_byte_width));
		if (!return_desc) {
			status = AE_NO_MEMORY;
			goto cleanup;
		}

		buffer = (char *)return_desc->buffer.pointer;

		/* Copy the first integer, LSB first */

		memcpy(buffer, &operand0->integer.value,
		       acpi_gbl_integer_byte_width);

		/* Copy the second integer (LSB first) after the first */

		memcpy(buffer + acpi_gbl_integer_byte_width,
		       &local_operand1->integer.value,
		       acpi_gbl_integer_byte_width);
		break;

	case ACPI_TYPE_STRING:

		/* Result of two Strings is a String */

		return_desc = acpi_ut_create_string_object(((acpi_size)
							    local_operand0->
							    string.length +
							    local_operand1->
							    string.length));
		if (!return_desc) {
			status = AE_NO_MEMORY;
			goto cleanup;
		}

		buffer = return_desc->string.pointer;

		/* Concatenate the strings */

		strcpy(buffer, local_operand0->string.pointer);
		strcat(buffer, local_operand1->string.pointer);
		break;

	case ACPI_TYPE_BUFFER:

		/* Result of two Buffers is a Buffer */

		return_desc = acpi_ut_create_buffer_object(((acpi_size)
							    operand0->buffer.
							    length +
							    local_operand1->
							    buffer.length));
		if (!return_desc) {
			status = AE_NO_MEMORY;
			goto cleanup;
		}

		buffer = (char *)return_desc->buffer.pointer;

		/* Concatenate the buffers */

		memcpy(buffer, operand0->buffer.pointer,
		       operand0->buffer.length);
		memcpy(buffer + operand0->buffer.length,
		       local_operand1->buffer.pointer,
		       local_operand1->buffer.length);
		break;

	default:

		/* Invalid object type, should not happen here */

		ACPI_ERROR((AE_INFO, "Invalid object type: 0x%X",
			    operand0->common.type));
		status = AE_AML_INTERNAL;
		goto cleanup;
	}

	*actual_return_desc = return_desc;

cleanup:
	if (local_operand0 != operand0) {
		acpi_ut_remove_reference(local_operand0);
	}

	if (local_operand1 != operand1) {
		acpi_ut_remove_reference(local_operand1);
	}

	return_ACPI_STATUS(status);
}

__attribute__((used)) static acpi_status
acpi_ex_convert_to_object_type_string(union acpi_operand_object *obj_desc,
				      union acpi_operand_object **result_desc)
{
	union acpi_operand_object *return_desc;
	const char *type_string;

	type_string = acpi_ut_get_type_name(obj_desc->common.type);

	return_desc = acpi_ut_create_string_object(((acpi_size)strlen(type_string) + 9));	/* 9 For "[ Object]" */
	if (!return_desc) {
		return (AE_NO_MEMORY);
	}

	strcpy(return_desc->string.pointer, "[");
	strcat(return_desc->string.pointer, type_string);
	strcat(return_desc->string.pointer, " Object]");

	*result_desc = return_desc;
	return (AE_OK);
}

acpi_status
acpi_ex_concat_template(union acpi_operand_object *operand0,
			union acpi_operand_object *operand1,
			union acpi_operand_object **actual_return_desc,
			struct acpi_walk_state *walk_state)
{
	acpi_status status;
	union acpi_operand_object *return_desc;
	u8 *new_buf;
	u8 *end_tag;
	acpi_size length0;
	acpi_size length1;
	acpi_size new_length;

	ACPI_FUNCTION_TRACE(ex_concat_template);

	/*
	 * Find the end_tag descriptor in each resource template.
	 * Note1: returned pointers point TO the end_tag, not past it.
	 * Note2: zero-length buffers are allowed; treated like one end_tag
	 */

	/* Get the length of the first resource template */

	status = acpi_ut_get_resource_end_tag(operand0, &end_tag);
	if (ACPI_FAILURE(status)) {
		return_ACPI_STATUS(status);
	}

	length0 = ACPI_PTR_DIFF(end_tag, operand0->buffer.pointer);

	/* Get the length of the second resource template */

	status = acpi_ut_get_resource_end_tag(operand1, &end_tag);
	if (ACPI_FAILURE(status)) {
		return_ACPI_STATUS(status);
	}

	length1 = ACPI_PTR_DIFF(end_tag, operand1->buffer.pointer);

	/* Combine both lengths, minimum size will be 2 for end_tag */

	new_length = length0 + length1 + sizeof(struct aml_resource_end_tag);

	/* Create a new buffer object for the result (with one end_tag) */

	return_desc = acpi_ut_create_buffer_object(new_length);
	if (!return_desc) {
		return_ACPI_STATUS(AE_NO_MEMORY);
	}

	/*
	 * Copy the templates to the new buffer, 0 first, then 1 follows. One
	 * end_tag descriptor is copied from Operand1.
	 */
	new_buf = return_desc->buffer.pointer;
	memcpy(new_buf, operand0->buffer.pointer, length0);
	memcpy(new_buf + length0, operand1->buffer.pointer, length1);

	/* Insert end_tag and set the checksum to zero, means "ignore checksum" */

	new_buf[new_length - 1] = 0;
	new_buf[new_length - 2] = ACPI_RESOURCE_NAME_END_TAG | 1;

	/* Return the completed resource template */

	*actual_return_desc = return_desc;
	return_ACPI_STATUS(AE_OK);
}

