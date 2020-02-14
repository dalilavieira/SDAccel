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
struct TYPE_10__ {int count; union acpi_operand_object** elements; } ;
struct TYPE_7__ {int /*<<< orphan*/  reference_count; } ;
union acpi_operand_object {TYPE_5__ package; TYPE_2__ common; } ;
typedef  int u8 ;
typedef  int /*<<< orphan*/  u64 ;
typedef  int u32 ;
struct acpi_simple_repair_info {int unexpected_btypes; scalar_t__ package_index; int /*<<< orphan*/  name; int /*<<< orphan*/  (* object_converter ) (struct acpi_namespace_node*,union acpi_operand_object*,union acpi_operand_object**) ;} ;
struct TYPE_6__ {int /*<<< orphan*/  ascii; } ;
struct acpi_namespace_node {TYPE_1__ name; } ;
struct acpi_evaluate_info {int return_btype; int return_flags; int /*<<< orphan*/  full_pathname; TYPE_4__* parent_package; struct acpi_namespace_node* node; } ;
typedef  int /*<<< orphan*/  acpi_status ;
struct TYPE_8__ {int /*<<< orphan*/  reference_count; } ;
struct TYPE_9__ {TYPE_3__ common; } ;

/* Variables and functions */
 scalar_t__ ACPI_ALL_PACKAGE_ELEMENTS ; 
 scalar_t__ ACPI_COMPARE_NAME (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_DB_REPAIR ; 
 int /*<<< orphan*/  ACPI_DEBUG_PRINT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_EXCEPTION (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_NAME (int /*<<< orphan*/ ) ; 
 int ACPI_NOT_PACKAGE_ELEMENT ; 
 int ACPI_OBJECT_REPAIRED ; 
 int ACPI_OBJECT_WRAPPED ; 
#define  ACPI_PTYPE1_FIXED 138 
#define  ACPI_PTYPE1_OPTION 137 
#define  ACPI_PTYPE1_VAR 136 
#define  ACPI_PTYPE2 135 
#define  ACPI_PTYPE2_COUNT 134 
#define  ACPI_PTYPE2_FIXED 133 
#define  ACPI_PTYPE2_FIX_VAR 132 
#define  ACPI_PTYPE2_MIN 131 
#define  ACPI_PTYPE2_PKG_COUNT 130 
#define  ACPI_PTYPE2_REV_FIXED 129 
#define  ACPI_PTYPE2_VAR_VAR 128 
 int ACPI_RTYPE_BUFFER ; 
 int ACPI_RTYPE_INTEGER ; 
 int ACPI_RTYPE_NONE ; 
 int ACPI_RTYPE_PACKAGE ; 
 int ACPI_RTYPE_STRING ; 
 scalar_t__ ACPI_SUCCESS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_WARN_ALWAYS ; 
 int /*<<< orphan*/  ACPI_WARN_PREDEFINED (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AE_AML_NO_RETURN_VALUE ; 
 int /*<<< orphan*/  AE_AML_OPERAND_TYPE ; 
 int /*<<< orphan*/  AE_INFO ; 
 int /*<<< orphan*/  AE_NO_MEMORY ; 
 int /*<<< orphan*/  AE_OK ; 
 int /*<<< orphan*/  acpi_ns_convert_to_buffer (union acpi_operand_object*,union acpi_operand_object**) ; 
 int /*<<< orphan*/  acpi_ns_convert_to_integer (union acpi_operand_object*,union acpi_operand_object**) ; 
 int /*<<< orphan*/  acpi_ns_convert_to_string (union acpi_operand_object*,union acpi_operand_object**) ; 
static  struct acpi_simple_repair_info const* acpi_ns_match_simple_repair (struct acpi_namespace_node*,int,int) ; 
 int /*<<< orphan*/  acpi_ns_repair_null_element (struct acpi_evaluate_info*,int,int,union acpi_operand_object**) ; 
 int /*<<< orphan*/  acpi_ns_wrap_with_package (struct acpi_evaluate_info*,union acpi_operand_object*,union acpi_operand_object**) ; 
 struct acpi_simple_repair_info* acpi_object_repair_info ; 
 union acpi_operand_object* acpi_ut_create_buffer_object (int /*<<< orphan*/ ) ; 
 union acpi_operand_object* acpi_ut_create_integer_object (int /*<<< orphan*/ ) ; 
 union acpi_operand_object* acpi_ut_create_package_object (int) ; 
 union acpi_operand_object* acpi_ut_create_string_object (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  acpi_ut_get_object_type_name (union acpi_operand_object*) ; 
 int /*<<< orphan*/  acpi_ut_remove_reference (union acpi_operand_object*) ; 
 int /*<<< orphan*/  ns_remove_null_elements ; 
 int /*<<< orphan*/  ns_repair_null_element ; 
 int /*<<< orphan*/  ns_simple_repair ; 
 int /*<<< orphan*/  ns_wrap_with_package ; 
 int /*<<< orphan*/  stub1 (struct acpi_namespace_node*,union acpi_operand_object*,union acpi_operand_object**) ; 

acpi_status
acpi_ns_simple_repair(struct acpi_evaluate_info *info,
		      u32 expected_btypes,
		      u32 package_index,
		      union acpi_operand_object **return_object_ptr)
{
	union acpi_operand_object *return_object = *return_object_ptr;
	union acpi_operand_object *new_object = NULL;
	acpi_status status;
	const struct acpi_simple_repair_info *predefined;

	ACPI_FUNCTION_NAME(ns_simple_repair);

	/*
	 * Special repairs for certain names that are in the repair table.
	 * Check if this name is in the list of repairable names.
	 */
	predefined = acpi_ns_match_simple_repair(info->node,
						 info->return_btype,
						 package_index);
	if (predefined) {
		if (!return_object) {
			ACPI_WARN_PREDEFINED((AE_INFO, info->full_pathname,
					      ACPI_WARN_ALWAYS,
					      "Missing expected return value"));
		}

		status = predefined->object_converter(info->node, return_object,
						      &new_object);
		if (ACPI_FAILURE(status)) {

			/* A fatal error occurred during a conversion */

			ACPI_EXCEPTION((AE_INFO, status,
					"During return object analysis"));
			return (status);
		}
		if (new_object) {
			goto object_repaired;
		}
	}

	/*
	 * Do not perform simple object repair unless the return type is not
	 * expected.
	 */
	if (info->return_btype & expected_btypes) {
		return (AE_OK);
	}

	/*
	 * At this point, we know that the type of the returned object was not
	 * one of the expected types for this predefined name. Attempt to
	 * repair the object by converting it to one of the expected object
	 * types for this predefined name.
	 */

	/*
	 * If there is no return value, check if we require a return value for
	 * this predefined name. Either one return value is expected, or none,
	 * for both methods and other objects.
	 *
	 * Try to fix if there was no return object. Warning if failed to fix.
	 */
	if (!return_object) {
		if (expected_btypes && (!(expected_btypes & ACPI_RTYPE_NONE))) {
			if (package_index != ACPI_NOT_PACKAGE_ELEMENT) {
				ACPI_WARN_PREDEFINED((AE_INFO,
						      info->full_pathname,
						      ACPI_WARN_ALWAYS,
						      "Found unexpected NULL package element"));

				status =
				    acpi_ns_repair_null_element(info,
								expected_btypes,
								package_index,
								return_object_ptr);
				if (ACPI_SUCCESS(status)) {
					return (AE_OK);	/* Repair was successful */
				}
			} else {
				ACPI_WARN_PREDEFINED((AE_INFO,
						      info->full_pathname,
						      ACPI_WARN_ALWAYS,
						      "Missing expected return value"));
			}

			return (AE_AML_NO_RETURN_VALUE);
		}
	}

	if (expected_btypes & ACPI_RTYPE_INTEGER) {
		status = acpi_ns_convert_to_integer(return_object, &new_object);
		if (ACPI_SUCCESS(status)) {
			goto object_repaired;
		}
	}
	if (expected_btypes & ACPI_RTYPE_STRING) {
		status = acpi_ns_convert_to_string(return_object, &new_object);
		if (ACPI_SUCCESS(status)) {
			goto object_repaired;
		}
	}
	if (expected_btypes & ACPI_RTYPE_BUFFER) {
		status = acpi_ns_convert_to_buffer(return_object, &new_object);
		if (ACPI_SUCCESS(status)) {
			goto object_repaired;
		}
	}
	if (expected_btypes & ACPI_RTYPE_PACKAGE) {
		/*
		 * A package is expected. We will wrap the existing object with a
		 * new package object. It is often the case that if a variable-length
		 * package is required, but there is only a single object needed, the
		 * BIOS will return that object instead of wrapping it with a Package
		 * object. Note: after the wrapping, the package will be validated
		 * for correct contents (expected object type or types).
		 */
		status =
		    acpi_ns_wrap_with_package(info, return_object, &new_object);
		if (ACPI_SUCCESS(status)) {
			/*
			 * The original object just had its reference count
			 * incremented for being inserted into the new package.
			 */
			*return_object_ptr = new_object;	/* New Package object */
			info->return_flags |= ACPI_OBJECT_REPAIRED;
			return (AE_OK);
		}
	}

	/* We cannot repair this object */

	return (AE_AML_OPERAND_TYPE);

object_repaired:

	/* Object was successfully repaired */

	if (package_index != ACPI_NOT_PACKAGE_ELEMENT) {

		/* Update reference count of new object */

		if (!(info->return_flags & ACPI_OBJECT_WRAPPED)) {
			new_object->common.reference_count =
			    return_object->common.reference_count;
		}

		ACPI_DEBUG_PRINT((ACPI_DB_REPAIR,
				  "%s: Converted %s to expected %s at Package index %u\n",
				  info->full_pathname,
				  acpi_ut_get_object_type_name(return_object),
				  acpi_ut_get_object_type_name(new_object),
				  package_index));
	} else {
		ACPI_DEBUG_PRINT((ACPI_DB_REPAIR,
				  "%s: Converted %s to expected %s\n",
				  info->full_pathname,
				  acpi_ut_get_object_type_name(return_object),
				  acpi_ut_get_object_type_name(new_object)));
	}

	/* Delete old object, install the new return object */

	acpi_ut_remove_reference(return_object);
	*return_object_ptr = new_object;
	info->return_flags |= ACPI_OBJECT_REPAIRED;
	return (AE_OK);
}

__attribute__((used)) static const struct acpi_simple_repair_info *acpi_ns_match_simple_repair(struct
									 acpi_namespace_node
									 *node,
									 u32
									 return_btype,
									 u32
									 package_index)
{
	const struct acpi_simple_repair_info *this_name;

	/* Search info table for a repairable predefined method/object name */

	this_name = acpi_object_repair_info;
	while (this_name->object_converter) {
		if (ACPI_COMPARE_NAME(node->name.ascii, this_name->name)) {

			/* Check if we can actually repair this name/type combination */

			if ((return_btype & this_name->unexpected_btypes) &&
			    (this_name->package_index ==
			     ACPI_ALL_PACKAGE_ELEMENTS
			     || package_index == this_name->package_index)) {
				return (this_name);
			}

			return (NULL);
		}

		this_name++;
	}

	return (NULL);		/* Name was not found in the repair table */
}

acpi_status
acpi_ns_repair_null_element(struct acpi_evaluate_info *info,
			    u32 expected_btypes,
			    u32 package_index,
			    union acpi_operand_object **return_object_ptr)
{
	union acpi_operand_object *return_object = *return_object_ptr;
	union acpi_operand_object *new_object;

	ACPI_FUNCTION_NAME(ns_repair_null_element);

	/* No repair needed if return object is non-NULL */

	if (return_object) {
		return (AE_OK);
	}

	/*
	 * Attempt to repair a NULL element of a Package object. This applies to
	 * predefined names that return a fixed-length package and each element
	 * is required. It does not apply to variable-length packages where NULL
	 * elements are allowed, especially at the end of the package.
	 */
	if (expected_btypes & ACPI_RTYPE_INTEGER) {

		/* Need an integer - create a zero-value integer */

		new_object = acpi_ut_create_integer_object((u64)0);
	} else if (expected_btypes & ACPI_RTYPE_STRING) {

		/* Need a string - create a NULL string */

		new_object = acpi_ut_create_string_object(0);
	} else if (expected_btypes & ACPI_RTYPE_BUFFER) {

		/* Need a buffer - create a zero-length buffer */

		new_object = acpi_ut_create_buffer_object(0);
	} else {
		/* Error for all other expected types */

		return (AE_AML_OPERAND_TYPE);
	}

	if (!new_object) {
		return (AE_NO_MEMORY);
	}

	/* Set the reference count according to the parent Package object */

	new_object->common.reference_count =
	    info->parent_package->common.reference_count;

	ACPI_DEBUG_PRINT((ACPI_DB_REPAIR,
			  "%s: Converted NULL package element to expected %s at index %u\n",
			  info->full_pathname,
			  acpi_ut_get_object_type_name(new_object),
			  package_index));

	*return_object_ptr = new_object;
	info->return_flags |= ACPI_OBJECT_REPAIRED;
	return (AE_OK);
}

void
acpi_ns_remove_null_elements(struct acpi_evaluate_info *info,
			     u8 package_type,
			     union acpi_operand_object *obj_desc)
{
	union acpi_operand_object **source;
	union acpi_operand_object **dest;
	u32 count;
	u32 new_count;
	u32 i;

	ACPI_FUNCTION_NAME(ns_remove_null_elements);

	/*
	 * We can safely remove all NULL elements from these package types:
	 * PTYPE1_VAR packages contain a variable number of simple data types.
	 * PTYPE2 packages contain a variable number of subpackages.
	 */
	switch (package_type) {
	case ACPI_PTYPE1_VAR:
	case ACPI_PTYPE2:
	case ACPI_PTYPE2_COUNT:
	case ACPI_PTYPE2_PKG_COUNT:
	case ACPI_PTYPE2_FIXED:
	case ACPI_PTYPE2_MIN:
	case ACPI_PTYPE2_REV_FIXED:
	case ACPI_PTYPE2_FIX_VAR:
		break;

	default:
	case ACPI_PTYPE2_VAR_VAR:
	case ACPI_PTYPE1_FIXED:
	case ACPI_PTYPE1_OPTION:
		return;
	}

	count = obj_desc->package.count;
	new_count = count;

	source = obj_desc->package.elements;
	dest = source;

	/* Examine all elements of the package object, remove nulls */

	for (i = 0; i < count; i++) {
		if (!*source) {
			new_count--;
		} else {
			*dest = *source;
			dest++;
		}

		source++;
	}

	/* Update parent package if any null elements were removed */

	if (new_count < count) {
		ACPI_DEBUG_PRINT((ACPI_DB_REPAIR,
				  "%s: Found and removed %u NULL elements\n",
				  info->full_pathname, (count - new_count)));

		/* NULL terminate list and update the package count */

		*dest = NULL;
		obj_desc->package.count = new_count;
	}
}

acpi_status
acpi_ns_wrap_with_package(struct acpi_evaluate_info *info,
			  union acpi_operand_object *original_object,
			  union acpi_operand_object **obj_desc_ptr)
{
	union acpi_operand_object *pkg_obj_desc;

	ACPI_FUNCTION_NAME(ns_wrap_with_package);

	/*
	 * Create the new outer package and populate it. The new
	 * package will have a single element, the lone sub-object.
	 */
	pkg_obj_desc = acpi_ut_create_package_object(1);
	if (!pkg_obj_desc) {
		return (AE_NO_MEMORY);
	}

	pkg_obj_desc->package.elements[0] = original_object;

	ACPI_DEBUG_PRINT((ACPI_DB_REPAIR,
			  "%s: Wrapped %s with expected Package object\n",
			  info->full_pathname,
			  acpi_ut_get_object_type_name(original_object)));

	/* Return the new object in the object pointer */

	*obj_desc_ptr = pkg_obj_desc;
	info->return_flags |= ACPI_OBJECT_REPAIRED | ACPI_OBJECT_WRAPPED;
	return (AE_OK);
}

