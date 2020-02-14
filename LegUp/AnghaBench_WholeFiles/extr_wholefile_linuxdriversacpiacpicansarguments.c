#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_8__ ;
typedef  struct TYPE_15__   TYPE_7__ ;
typedef  struct TYPE_14__   TYPE_6__ ;
typedef  struct TYPE_13__   TYPE_5__ ;
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct TYPE_16__ {int argument_list; int /*<<< orphan*/  expected_btypes; } ;
union acpi_predefined_info {TYPE_8__ info; } ;
typedef  size_t u8 ;
typedef  size_t u32 ;
typedef  int u16 ;
struct acpi_namespace_node {int flags; scalar_t__ type; TYPE_7__* object; } ;
struct acpi_evaluate_info {size_t param_count; TYPE_5__* node; int /*<<< orphan*/  full_pathname; TYPE_4__** parameters; TYPE_2__* predefined; } ;
struct TYPE_14__ {size_t param_count; } ;
struct TYPE_15__ {TYPE_6__ method; } ;
struct TYPE_13__ {int flags; } ;
struct TYPE_11__ {size_t type; } ;
struct TYPE_12__ {TYPE_3__ common; } ;
struct TYPE_9__ {int argument_list; } ;
struct TYPE_10__ {TYPE_1__ info; } ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_BIOS_ERROR_PREDEFINED (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_INFO_PREDEFINED (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_TYPE_METHOD ; 
 int /*<<< orphan*/  ACPI_WARN_ALWAYS ; 
 int /*<<< orphan*/  ACPI_WARN_PREDEFINED (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AE_INFO ; 
 int ANOBJ_EVALUATED ; 
 int ARG_COUNT_IS_MINIMUM ; 
 size_t METHOD_GET_ARG_COUNT (int) ; 
 size_t METHOD_GET_NEXT_TYPE (int) ; 
 int /*<<< orphan*/  acpi_ut_get_type_name (size_t) ; 

void acpi_ns_check_argument_types(struct acpi_evaluate_info *info)
{
	u16 arg_type_list;
	u8 arg_count;
	u8 arg_type;
	u8 user_arg_type;
	u32 i;

	/*
	 * If not a predefined name, cannot typecheck args, because
	 * we have no idea what argument types are expected.
	 * Also, ignore typecheck if warnings/errors if this method
	 * has already been evaluated at least once -- in order
	 * to suppress repetitive messages.
	 */
	if (!info->predefined || (info->node->flags & ANOBJ_EVALUATED)) {
		return;
	}

	arg_type_list = info->predefined->info.argument_list;
	arg_count = METHOD_GET_ARG_COUNT(arg_type_list);

	/* Typecheck all arguments */

	for (i = 0; ((i < arg_count) && (i < info->param_count)); i++) {
		arg_type = METHOD_GET_NEXT_TYPE(arg_type_list);
		user_arg_type = info->parameters[i]->common.type;

		if (user_arg_type != arg_type) {
			ACPI_WARN_PREDEFINED((AE_INFO, info->full_pathname,
					      ACPI_WARN_ALWAYS,
					      "Argument #%u type mismatch - "
					      "Found [%s], ACPI requires [%s]",
					      (i + 1),
					      acpi_ut_get_type_name
					      (user_arg_type),
					      acpi_ut_get_type_name(arg_type)));

			/* Prevent any additional typechecking for this method */

			info->node->flags |= ANOBJ_EVALUATED;
		}
	}
}

void
acpi_ns_check_acpi_compliance(char *pathname,
			      struct acpi_namespace_node *node,
			      const union acpi_predefined_info *predefined)
{
	u32 aml_param_count;
	u32 required_param_count;

	if (!predefined || (node->flags & ANOBJ_EVALUATED)) {
		return;
	}

	/* Get the ACPI-required arg count from the predefined info table */

	required_param_count =
	    METHOD_GET_ARG_COUNT(predefined->info.argument_list);

	/*
	 * If this object is not a control method, we can check if the ACPI
	 * spec requires that it be a method.
	 */
	if (node->type != ACPI_TYPE_METHOD) {
		if (required_param_count > 0) {

			/* Object requires args, must be implemented as a method */

			ACPI_BIOS_ERROR_PREDEFINED((AE_INFO, pathname,
						    ACPI_WARN_ALWAYS,
						    "Object (%s) must be a control method with %u arguments",
						    acpi_ut_get_type_name(node->
									  type),
						    required_param_count));
		} else if (!required_param_count
			   && !predefined->info.expected_btypes) {

			/* Object requires no args and no return value, must be a method */

			ACPI_BIOS_ERROR_PREDEFINED((AE_INFO, pathname,
						    ACPI_WARN_ALWAYS,
						    "Object (%s) must be a control method "
						    "with no arguments and no return value",
						    acpi_ut_get_type_name(node->
									  type)));
		}

		return;
	}

	/*
	 * This is a control method.
	 * Check that the ASL/AML-defined parameter count for this method
	 * matches the ACPI-required parameter count
	 *
	 * Some methods are allowed to have a "minimum" number of args (_SCP)
	 * because their definition in ACPI has changed over time.
	 *
	 * Note: These are BIOS errors in the declaration of the object
	 */
	aml_param_count = node->object->method.param_count;

	if (aml_param_count < required_param_count) {
		ACPI_BIOS_ERROR_PREDEFINED((AE_INFO, pathname, ACPI_WARN_ALWAYS,
					    "Insufficient arguments - "
					    "ASL declared %u, ACPI requires %u",
					    aml_param_count,
					    required_param_count));
	} else if ((aml_param_count > required_param_count)
		   && !(predefined->info.
			argument_list & ARG_COUNT_IS_MINIMUM)) {
		ACPI_BIOS_ERROR_PREDEFINED((AE_INFO, pathname, ACPI_WARN_ALWAYS,
					    "Excess arguments - "
					    "ASL declared %u, ACPI requires %u",
					    aml_param_count,
					    required_param_count));
	}
}

void
acpi_ns_check_argument_count(char *pathname,
			     struct acpi_namespace_node *node,
			     u32 user_param_count,
			     const union acpi_predefined_info *predefined)
{
	u32 aml_param_count;
	u32 required_param_count;

	if (node->flags & ANOBJ_EVALUATED) {
		return;
	}

	if (!predefined) {
		/*
		 * Not a predefined name. Check the incoming user argument count
		 * against the count that is specified in the method/object.
		 */
		if (node->type != ACPI_TYPE_METHOD) {
			if (user_param_count) {
				ACPI_INFO_PREDEFINED((AE_INFO, pathname,
						      ACPI_WARN_ALWAYS,
						      "%u arguments were passed to a non-method ACPI object (%s)",
						      user_param_count,
						      acpi_ut_get_type_name
						      (node->type)));
			}

			return;
		}

		/*
		 * This is a control method. Check the parameter count.
		 * We can only check the incoming argument count against the
		 * argument count declared for the method in the ASL/AML.
		 *
		 * Emit a message if too few or too many arguments have been passed
		 * by the caller.
		 *
		 * Note: Too many arguments will not cause the method to
		 * fail. However, the method will fail if there are too few
		 * arguments and the method attempts to use one of the missing ones.
		 */
		aml_param_count = node->object->method.param_count;

		if (user_param_count < aml_param_count) {
			ACPI_WARN_PREDEFINED((AE_INFO, pathname,
					      ACPI_WARN_ALWAYS,
					      "Insufficient arguments - "
					      "Caller passed %u, method requires %u",
					      user_param_count,
					      aml_param_count));
		} else if (user_param_count > aml_param_count) {
			ACPI_INFO_PREDEFINED((AE_INFO, pathname,
					      ACPI_WARN_ALWAYS,
					      "Excess arguments - "
					      "Caller passed %u, method requires %u",
					      user_param_count,
					      aml_param_count));
		}

		return;
	}

	/*
	 * This is a predefined name. Validate the user-supplied parameter
	 * count against the ACPI specification. We don't validate against
	 * the method itself because what is important here is that the
	 * caller is in conformance with the spec. (The arg count for the
	 * method was checked against the ACPI spec earlier.)
	 *
	 * Some methods are allowed to have a "minimum" number of args (_SCP)
	 * because their definition in ACPI has changed over time.
	 */
	required_param_count =
	    METHOD_GET_ARG_COUNT(predefined->info.argument_list);

	if (user_param_count < required_param_count) {
		ACPI_WARN_PREDEFINED((AE_INFO, pathname, ACPI_WARN_ALWAYS,
				      "Insufficient arguments - "
				      "Caller passed %u, ACPI requires %u",
				      user_param_count, required_param_count));
	} else if ((user_param_count > required_param_count) &&
		   !(predefined->info.argument_list & ARG_COUNT_IS_MINIMUM)) {
		ACPI_INFO_PREDEFINED((AE_INFO, pathname, ACPI_WARN_ALWAYS,
				      "Excess arguments - "
				      "Caller passed %u, ACPI requires %u",
				      user_param_count, required_param_count));
	}
}

