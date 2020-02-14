#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int info_flags; } ;
union acpi_operand_object {TYPE_1__ method; } ;
typedef  int /*<<< orphan*/  u32 ;
struct acpi_table_header {int /*<<< orphan*/  oem_table_id; int /*<<< orphan*/  signature; } ;
struct acpi_namespace_node {scalar_t__ owner_id; } ;
struct acpi_init_walk_info {scalar_t__ owner_id; int /*<<< orphan*/  op_region_count; int /*<<< orphan*/  method_count; int /*<<< orphan*/  serialized_method_count; int /*<<< orphan*/  non_serial_method_count; int /*<<< orphan*/  serial_method_count; int /*<<< orphan*/  device_count; int /*<<< orphan*/  object_count; int /*<<< orphan*/  table_index; } ;
typedef  int /*<<< orphan*/  acpi_status ;
typedef  scalar_t__ acpi_owner_id ;
typedef  scalar_t__ acpi_handle ;

/* Variables and functions */
 scalar_t__ ACPI_COMPARE_NAME (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_DB_DISPATCH ; 
 int /*<<< orphan*/  ACPI_DB_INIT ; 
 int /*<<< orphan*/  ACPI_DEBUG_PRINT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_DEBUG_PRINT_RAW (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_EXCEPTION (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_ENTRY () ; 
 int /*<<< orphan*/  ACPI_FUNCTION_TRACE (int /*<<< orphan*/ ) ; 
 int ACPI_METHOD_SERIALIZED ; 
 int /*<<< orphan*/  ACPI_NS_WALK_NO_UNLOCK ; 
 int /*<<< orphan*/  ACPI_SIG_DSDT ; 
 int /*<<< orphan*/  ACPI_TYPE_ANY ; 
#define  ACPI_TYPE_DEVICE 130 
#define  ACPI_TYPE_METHOD 129 
#define  ACPI_TYPE_REGION 128 
 int /*<<< orphan*/  ACPI_UINT32_MAX ; 
 int /*<<< orphan*/  AE_INFO ; 
 int /*<<< orphan*/  AE_OK ; 
 int /*<<< orphan*/  acpi_ds_auto_serialize_method (struct acpi_namespace_node*,union acpi_operand_object*) ; 
 int /*<<< orphan*/  acpi_ds_initialize_region (scalar_t__) ; 
 int /*<<< orphan*/  acpi_gbl_auto_serialize_methods ; 
 int /*<<< orphan*/  acpi_get_table_by_index (int /*<<< orphan*/ ,struct acpi_table_header**) ; 
 union acpi_operand_object* acpi_ns_get_attached_object (struct acpi_namespace_node*) ; 
 int acpi_ns_get_type (scalar_t__) ; 
 int /*<<< orphan*/  acpi_ns_walk_namespace (int /*<<< orphan*/ ,struct acpi_namespace_node*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (scalar_t__,int /*<<< orphan*/ ,void*,void**),int /*<<< orphan*/ *,struct acpi_init_walk_info*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  acpi_tb_get_owner_id (int /*<<< orphan*/ ,scalar_t__*) ; 
 int /*<<< orphan*/  acpi_ut_get_node_name (scalar_t__) ; 
 int /*<<< orphan*/  ds_initialize_objects ; 
 int /*<<< orphan*/  memset (struct acpi_init_walk_info*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  return_ACPI_STATUS (int /*<<< orphan*/ ) ; 

__attribute__((used)) static acpi_status
acpi_ds_init_one_object(acpi_handle obj_handle,
			u32 level, void *context, void **return_value)
{
	struct acpi_init_walk_info *info =
	    (struct acpi_init_walk_info *)context;
	struct acpi_namespace_node *node =
	    (struct acpi_namespace_node *)obj_handle;
	acpi_status status;
	union acpi_operand_object *obj_desc;

	ACPI_FUNCTION_ENTRY();

	/*
	 * We are only interested in NS nodes owned by the table that
	 * was just loaded
	 */
	if (node->owner_id != info->owner_id) {
		return (AE_OK);
	}

	info->object_count++;

	/* And even then, we are only interested in a few object types */

	switch (acpi_ns_get_type(obj_handle)) {
	case ACPI_TYPE_REGION:

		status = acpi_ds_initialize_region(obj_handle);
		if (ACPI_FAILURE(status)) {
			ACPI_EXCEPTION((AE_INFO, status,
					"During Region initialization %p [%4.4s]",
					obj_handle,
					acpi_ut_get_node_name(obj_handle)));
		}

		info->op_region_count++;
		break;

	case ACPI_TYPE_METHOD:
		/*
		 * Auto-serialization support. We will examine each method that is
		 * not_serialized to determine if it creates any Named objects. If
		 * it does, it will be marked serialized to prevent problems if
		 * the method is entered by two or more threads and an attempt is
		 * made to create the same named object twice -- which results in
		 * an AE_ALREADY_EXISTS exception and method abort.
		 */
		info->method_count++;
		obj_desc = acpi_ns_get_attached_object(node);
		if (!obj_desc) {
			break;
		}

		/* Ignore if already serialized */

		if (obj_desc->method.info_flags & ACPI_METHOD_SERIALIZED) {
			info->serial_method_count++;
			break;
		}

		if (acpi_gbl_auto_serialize_methods) {

			/* Parse/scan method and serialize it if necessary */

			acpi_ds_auto_serialize_method(node, obj_desc);
			if (obj_desc->method.
			    info_flags & ACPI_METHOD_SERIALIZED) {

				/* Method was just converted to Serialized */

				info->serial_method_count++;
				info->serialized_method_count++;
				break;
			}
		}

		info->non_serial_method_count++;
		break;

	case ACPI_TYPE_DEVICE:

		info->device_count++;
		break;

	default:

		break;
	}

	/*
	 * We ignore errors from above, and always return OK, since
	 * we don't want to abort the walk on a single error.
	 */
	return (AE_OK);
}

acpi_status
acpi_ds_initialize_objects(u32 table_index,
			   struct acpi_namespace_node *start_node)
{
	acpi_status status;
	struct acpi_init_walk_info info;
	struct acpi_table_header *table;
	acpi_owner_id owner_id;

	ACPI_FUNCTION_TRACE(ds_initialize_objects);

	status = acpi_tb_get_owner_id(table_index, &owner_id);
	if (ACPI_FAILURE(status)) {
		return_ACPI_STATUS(status);
	}

	ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH,
			  "**** Starting initialization of namespace objects ****\n"));

	/* Set all init info to zero */

	memset(&info, 0, sizeof(struct acpi_init_walk_info));

	info.owner_id = owner_id;
	info.table_index = table_index;

	/* Walk entire namespace from the supplied root */

	/*
	 * We don't use acpi_walk_namespace since we do not want to acquire
	 * the namespace reader lock.
	 */
	status =
	    acpi_ns_walk_namespace(ACPI_TYPE_ANY, start_node, ACPI_UINT32_MAX,
				   ACPI_NS_WALK_NO_UNLOCK,
				   acpi_ds_init_one_object, NULL, &info, NULL);
	if (ACPI_FAILURE(status)) {
		ACPI_EXCEPTION((AE_INFO, status, "During WalkNamespace"));
	}

	status = acpi_get_table_by_index(table_index, &table);
	if (ACPI_FAILURE(status)) {
		return_ACPI_STATUS(status);
	}

	/* DSDT is always the first AML table */

	if (ACPI_COMPARE_NAME(table->signature, ACPI_SIG_DSDT)) {
		ACPI_DEBUG_PRINT_RAW((ACPI_DB_INIT,
				      "\nInitializing Namespace objects:\n"));
	}

	/* Summary of objects initialized */

	ACPI_DEBUG_PRINT_RAW((ACPI_DB_INIT,
			      "Table [%4.4s: %-8.8s] (id %.2X) - %4u Objects with %3u Devices, "
			      "%3u Regions, %4u Methods (%u/%u/%u Serial/Non/Cvt)\n",
			      table->signature, table->oem_table_id, owner_id,
			      info.object_count, info.device_count,
			      info.op_region_count, info.method_count,
			      info.serial_method_count,
			      info.non_serial_method_count,
			      info.serialized_method_count));

	ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH, "%u Methods, %u Regions\n",
			  info.method_count, info.op_region_count));

	return_ACPI_STATUS(AE_OK);
}

