#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {scalar_t__ expected_btypes; } ;
union acpi_predefined_info {TYPE_1__ info; } ;
struct TYPE_10__ {scalar_t__ type; } ;
struct TYPE_9__ {scalar_t__ class; } ;
struct TYPE_7__ {int /*<<< orphan*/  ascii; } ;
struct TYPE_8__ {int /*<<< orphan*/  type; TYPE_2__ name; } ;
union acpi_operand_object {TYPE_5__ common; TYPE_4__ reference; TYPE_3__ node; } ;
typedef  scalar_t__ u32 ;
struct acpi_namespace_node {int /*<<< orphan*/  flags; } ;
struct acpi_evaluate_info {int return_flags; scalar_t__ return_btype; int /*<<< orphan*/  node_flags; int /*<<< orphan*/  full_pathname; union acpi_operand_object* parent_package; union acpi_predefined_info* predefined; } ;
typedef  scalar_t__ acpi_status ;

/* Variables and functions */
 scalar_t__ ACPI_DESC_TYPE_NAMED ; 
 scalar_t__ ACPI_FAILURE (scalar_t__) ; 
 scalar_t__ ACPI_GET_DESCRIPTOR_TYPE (union acpi_operand_object*) ; 
 scalar_t__ ACPI_NOT_PACKAGE_ELEMENT ; 
 int ACPI_OBJECT_REPAIRED ; 
 scalar_t__ ACPI_REFCLASS_NAME ; 
 scalar_t__ ACPI_RTYPE_ALL ; 
 scalar_t__ ACPI_RTYPE_ANY ; 
 scalar_t__ ACPI_RTYPE_BUFFER ; 
 scalar_t__ ACPI_RTYPE_INTEGER ; 
 scalar_t__ ACPI_RTYPE_NONE ; 
 scalar_t__ ACPI_RTYPE_PACKAGE ; 
 scalar_t__ ACPI_RTYPE_REFERENCE ; 
 scalar_t__ ACPI_RTYPE_STRING ; 
 scalar_t__ ACPI_SUCCESS (scalar_t__) ; 
#define  ACPI_TYPE_BUFFER 132 
#define  ACPI_TYPE_INTEGER 131 
#define  ACPI_TYPE_LOCAL_REFERENCE 130 
#define  ACPI_TYPE_PACKAGE 129 
#define  ACPI_TYPE_STRING 128 
 int /*<<< orphan*/  ACPI_WARN_PREDEFINED (int /*<<< orphan*/ ) ; 
 scalar_t__ AE_AML_OPERAND_TYPE ; 
 scalar_t__ AE_AML_OPERAND_VALUE ; 
 scalar_t__ AE_CTRL_RETURN_VALUE ; 
 int /*<<< orphan*/  AE_INFO ; 
 scalar_t__ AE_OK ; 
 int /*<<< orphan*/  ANOBJ_EVALUATED ; 
 scalar_t__ acpi_gbl_disable_auto_repair ; 
 scalar_t__ acpi_ns_check_object_type (struct acpi_evaluate_info*,union acpi_operand_object**,scalar_t__,scalar_t__) ; 
 scalar_t__ acpi_ns_check_package (struct acpi_evaluate_info*,union acpi_operand_object**) ; 
static  scalar_t__ acpi_ns_check_reference (struct acpi_evaluate_info*,union acpi_operand_object*) ; 
 scalar_t__ acpi_ns_complex_repairs (struct acpi_evaluate_info*,struct acpi_namespace_node*,scalar_t__,union acpi_operand_object**) ; 
static  scalar_t__ acpi_ns_get_bitmapped_type (union acpi_operand_object*) ; 
 scalar_t__ acpi_ns_simple_repair (struct acpi_evaluate_info*,scalar_t__,scalar_t__,union acpi_operand_object**) ; 
 int /*<<< orphan*/  acpi_ut_get_expected_return_types (char*,scalar_t__) ; 
 int /*<<< orphan*/  acpi_ut_get_object_type_name (union acpi_operand_object*) ; 
 int /*<<< orphan*/  acpi_ut_get_reference_name (union acpi_operand_object*) ; 
 int /*<<< orphan*/  acpi_ut_get_type_name (int /*<<< orphan*/ ) ; 

acpi_status
acpi_ns_check_return_value(struct acpi_namespace_node *node,
			   struct acpi_evaluate_info *info,
			   u32 user_param_count,
			   acpi_status return_status,
			   union acpi_operand_object **return_object_ptr)
{
	acpi_status status;
	const union acpi_predefined_info *predefined;

	/* If not a predefined name, we cannot validate the return object */

	predefined = info->predefined;
	if (!predefined) {
		return (AE_OK);
	}

	/*
	 * If the method failed or did not actually return an object, we cannot
	 * validate the return object
	 */
	if ((return_status != AE_OK) && (return_status != AE_CTRL_RETURN_VALUE)) {
		return (AE_OK);
	}

	/*
	 * Return value validation and possible repair.
	 *
	 * 1) Don't perform return value validation/repair if this feature
	 * has been disabled via a global option.
	 *
	 * 2) We have a return value, but if one wasn't expected, just exit,
	 * this is not a problem. For example, if the "Implicit Return"
	 * feature is enabled, methods will always return a value.
	 *
	 * 3) If the return value can be of any type, then we cannot perform
	 * any validation, just exit.
	 */
	if (acpi_gbl_disable_auto_repair ||
	    (!predefined->info.expected_btypes) ||
	    (predefined->info.expected_btypes == ACPI_RTYPE_ALL)) {
		return (AE_OK);
	}

	/*
	 * Check that the type of the main return object is what is expected
	 * for this predefined name
	 */
	status = acpi_ns_check_object_type(info, return_object_ptr,
					   predefined->info.expected_btypes,
					   ACPI_NOT_PACKAGE_ELEMENT);
	if (ACPI_FAILURE(status)) {
		goto exit;
	}

	/*
	 *
	 * 4) If there is no return value and it is optional, just return
	 * AE_OK (_WAK).
	 */
	if (!(*return_object_ptr)) {
		goto exit;
	}

	/*
	 * For returned Package objects, check the type of all sub-objects.
	 * Note: Package may have been newly created by call above.
	 */
	if ((*return_object_ptr)->common.type == ACPI_TYPE_PACKAGE) {
		info->parent_package = *return_object_ptr;
		status = acpi_ns_check_package(info, return_object_ptr);
		if (ACPI_FAILURE(status)) {

			/* We might be able to fix some errors */

			if ((status != AE_AML_OPERAND_TYPE) &&
			    (status != AE_AML_OPERAND_VALUE)) {
				goto exit;
			}
		}
	}

	/*
	 * The return object was OK, or it was successfully repaired above.
	 * Now make some additional checks such as verifying that package
	 * objects are sorted correctly (if required) or buffer objects have
	 * the correct data width (bytes vs. dwords). These repairs are
	 * performed on a per-name basis, i.e., the code is specific to
	 * particular predefined names.
	 */
	status = acpi_ns_complex_repairs(info, node, status, return_object_ptr);

exit:
	/*
	 * If the object validation failed or if we successfully repaired one
	 * or more objects, mark the parent node to suppress further warning
	 * messages during the next evaluation of the same method/object.
	 */
	if (ACPI_FAILURE(status) || (info->return_flags & ACPI_OBJECT_REPAIRED)) {
		node->flags |= ANOBJ_EVALUATED;
	}

	return (status);
}

acpi_status
acpi_ns_check_object_type(struct acpi_evaluate_info *info,
			  union acpi_operand_object **return_object_ptr,
			  u32 expected_btypes, u32 package_index)
{
	union acpi_operand_object *return_object = *return_object_ptr;
	acpi_status status = AE_OK;
	char type_buffer[96];	/* Room for 10 types */

	/* A Namespace node should not get here, but make sure */

	if (return_object &&
	    ACPI_GET_DESCRIPTOR_TYPE(return_object) == ACPI_DESC_TYPE_NAMED) {
		ACPI_WARN_PREDEFINED((AE_INFO, info->full_pathname,
				      info->node_flags,
				      "Invalid return type - Found a Namespace node [%4.4s] type %s",
				      return_object->node.name.ascii,
				      acpi_ut_get_type_name(return_object->node.
							    type)));
		return (AE_AML_OPERAND_TYPE);
	}

	/*
	 * Convert the object type (ACPI_TYPE_xxx) to a bitmapped object type.
	 * The bitmapped type allows multiple possible return types.
	 *
	 * Note, the cases below must handle all of the possible types returned
	 * from all of the predefined names (including elements of returned
	 * packages)
	 */
	info->return_btype = acpi_ns_get_bitmapped_type(return_object);
	if (info->return_btype == ACPI_RTYPE_ANY) {

		/* Not one of the supported objects, must be incorrect */
		goto type_error_exit;
	}

	/* For reference objects, check that the reference type is correct */

	if ((info->return_btype & expected_btypes) == ACPI_RTYPE_REFERENCE) {
		status = acpi_ns_check_reference(info, return_object);
		return (status);
	}

	/* Attempt simple repair of the returned object if necessary */

	status = acpi_ns_simple_repair(info, expected_btypes,
				       package_index, return_object_ptr);
	if (ACPI_SUCCESS(status)) {
		return (AE_OK);	/* Successful repair */
	}

type_error_exit:

	/* Create a string with all expected types for this predefined object */

	acpi_ut_get_expected_return_types(type_buffer, expected_btypes);

	if (!return_object) {
		ACPI_WARN_PREDEFINED((AE_INFO, info->full_pathname,
				      info->node_flags,
				      "Expected return object of type %s",
				      type_buffer));
	} else if (package_index == ACPI_NOT_PACKAGE_ELEMENT) {
		ACPI_WARN_PREDEFINED((AE_INFO, info->full_pathname,
				      info->node_flags,
				      "Return type mismatch - found %s, expected %s",
				      acpi_ut_get_object_type_name
				      (return_object), type_buffer));
	} else {
		ACPI_WARN_PREDEFINED((AE_INFO, info->full_pathname,
				      info->node_flags,
				      "Return Package type mismatch at index %u - "
				      "found %s, expected %s", package_index,
				      acpi_ut_get_object_type_name
				      (return_object), type_buffer));
	}

	return (AE_AML_OPERAND_TYPE);
}

__attribute__((used)) static acpi_status
acpi_ns_check_reference(struct acpi_evaluate_info *info,
			union acpi_operand_object *return_object)
{

	/*
	 * Check the reference object for the correct reference type (opcode).
	 * The only type of reference that can be converted to a union acpi_object is
	 * a reference to a named object (reference class: NAME)
	 */
	if (return_object->reference.class == ACPI_REFCLASS_NAME) {
		return (AE_OK);
	}

	ACPI_WARN_PREDEFINED((AE_INFO, info->full_pathname, info->node_flags,
			      "Return type mismatch - unexpected reference object type [%s] %2.2X",
			      acpi_ut_get_reference_name(return_object),
			      return_object->reference.class));

	return (AE_AML_OPERAND_TYPE);
}

__attribute__((used)) static u32 acpi_ns_get_bitmapped_type(union acpi_operand_object *return_object)
{
	u32 return_btype;

	if (!return_object) {
		return (ACPI_RTYPE_NONE);
	}

	/* Map acpi_object_type to internal bitmapped type */

	switch (return_object->common.type) {
	case ACPI_TYPE_INTEGER:

		return_btype = ACPI_RTYPE_INTEGER;
		break;

	case ACPI_TYPE_BUFFER:

		return_btype = ACPI_RTYPE_BUFFER;
		break;

	case ACPI_TYPE_STRING:

		return_btype = ACPI_RTYPE_STRING;
		break;

	case ACPI_TYPE_PACKAGE:

		return_btype = ACPI_RTYPE_PACKAGE;
		break;

	case ACPI_TYPE_LOCAL_REFERENCE:

		return_btype = ACPI_RTYPE_REFERENCE;
		break;

	default:

		/* Not one of the supported objects, must be incorrect */

		return_btype = ACPI_RTYPE_ANY;
		break;
	}

	return (return_btype);
}

