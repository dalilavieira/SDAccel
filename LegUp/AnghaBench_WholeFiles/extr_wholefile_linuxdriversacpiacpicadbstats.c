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
struct TYPE_15__ {union acpi_operand_object* handler; union acpi_operand_object** notify_list; } ;
struct TYPE_14__ {union acpi_operand_object* handler; union acpi_operand_object** notify_list; } ;
struct TYPE_13__ {union acpi_operand_object** notify_list; } ;
struct TYPE_12__ {union acpi_operand_object* handler; } ;
struct TYPE_11__ {union acpi_operand_object* handler; union acpi_operand_object** notify_list; } ;
struct TYPE_10__ {size_t count; union acpi_operand_object** elements; } ;
struct TYPE_9__ {size_t type; } ;
union acpi_operand_object {TYPE_7__ thermal_zone; TYPE_6__ processor; TYPE_5__ power_resource; TYPE_4__ region; TYPE_3__ device; TYPE_2__ package; TYPE_1__ common; } ;
typedef  union acpi_object {int dummy; } acpi_object ;
typedef  union acpi_generic_state {int dummy; } acpi_generic_state ;
typedef  size_t u32 ;
struct acpi_update_state {int dummy; } ;
struct acpi_thread_state {int dummy; } ;
struct acpi_scope_state {int dummy; } ;
struct acpi_result_values {int dummy; } ;
struct acpi_pscope_state {int dummy; } ;
struct acpi_pkg_state {int dummy; } ;
struct acpi_parse_obj_named {int dummy; } ;
struct acpi_parse_obj_common {int dummy; } ;
struct acpi_parse_obj_asl {int dummy; } ;
struct acpi_object_thermal_zone {int dummy; } ;
struct acpi_object_string {int dummy; } ;
struct acpi_object_region_field {int dummy; } ;
struct acpi_object_region {int dummy; } ;
struct acpi_object_reference {int dummy; } ;
struct acpi_object_processor {int dummy; } ;
struct acpi_object_power_resource {int dummy; } ;
struct acpi_object_package {int dummy; } ;
struct acpi_object_notify_handler {int dummy; } ;
struct acpi_object_mutex {int dummy; } ;
struct acpi_object_method {int dummy; } ;
struct acpi_object_integer {int dummy; } ;
struct acpi_object_index_field {int dummy; } ;
struct acpi_object_extra {int dummy; } ;
struct acpi_object_event {int dummy; } ;
struct acpi_object_device {int dummy; } ;
struct acpi_object_data {int dummy; } ;
struct acpi_object_common {int dummy; } ;
struct acpi_object_buffer_field {int dummy; } ;
struct acpi_object_buffer {int dummy; } ;
struct acpi_object_bank_field {int dummy; } ;
struct acpi_object_addr_handler {int dummy; } ;
struct acpi_notify_info {int dummy; } ;
struct acpi_namespace_node {size_t type; } ;
struct acpi_control_state {int dummy; } ;
struct acpi_common_state {int dummy; } ;
typedef  int /*<<< orphan*/  acpi_status ;
typedef  scalar_t__ acpi_handle ;
struct TYPE_16__ {int /*<<< orphan*/  use_count; } ;

/* Variables and functions */
 size_t ACPI_NUM_MUTEX ; 
 int /*<<< orphan*/  ACPI_ROOT_OBJECT ; 
 int /*<<< orphan*/  ACPI_TYPE_ANY ; 
#define  ACPI_TYPE_BUFFER_FIELD 141 
#define  ACPI_TYPE_DEVICE 140 
 size_t ACPI_TYPE_LOCAL_REGION_FIELD ; 
 size_t ACPI_TYPE_NOT_FOUND ; 
 size_t ACPI_TYPE_NS_NODE_MAX ; 
#define  ACPI_TYPE_PACKAGE 139 
#define  ACPI_TYPE_POWER 138 
#define  ACPI_TYPE_PROCESSOR 137 
#define  ACPI_TYPE_REGION 136 
#define  ACPI_TYPE_THERMAL 135 
 int /*<<< orphan*/  ACPI_UINT32_MAX ; 
 int /*<<< orphan*/  AE_OK ; 
#define  CMD_STAT_ALLOCATIONS 134 
#define  CMD_STAT_MEMORY 133 
#define  CMD_STAT_MISC 132 
#define  CMD_STAT_OBJECTS 131 
#define  CMD_STAT_SIZES 130 
#define  CMD_STAT_STACK 129 
#define  CMD_STAT_TABLES 128 
 int /*<<< orphan*/  FALSE ; 
 size_t acpi_db_match_argument (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  acpi_db_stat_types ; 
 TYPE_8__* acpi_gbl_mutex_info ; 
 scalar_t__* acpi_gbl_node_type_count ; 
 int /*<<< orphan*/  acpi_gbl_node_type_count_misc ; 
 int /*<<< orphan*/  acpi_gbl_ns_lookup_count ; 
 scalar_t__ acpi_gbl_num_nodes ; 
 scalar_t__ acpi_gbl_num_objects ; 
 scalar_t__* acpi_gbl_obj_type_count ; 
 scalar_t__ acpi_gbl_obj_type_count_misc ; 
 int /*<<< orphan*/  acpi_gbl_ps_find_count ; 
 union acpi_operand_object* acpi_ns_get_attached_object (struct acpi_namespace_node*) ; 
 int /*<<< orphan*/  acpi_ns_get_secondary_object (union acpi_operand_object*) ; 
 int /*<<< orphan*/  acpi_ns_walk_namespace (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (scalar_t__,size_t,void*,void**),int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  acpi_os_printf (char*,...) ; 
 int /*<<< orphan*/  acpi_ut_get_mutex_name (size_t) ; 
 int /*<<< orphan*/  acpi_ut_get_type_name (size_t) ; 
 int /*<<< orphan*/  acpi_ut_strupr (char*) ; 

__attribute__((used)) static void acpi_db_enumerate_object(union acpi_operand_object *obj_desc)
{
	u32 i;

	if (!obj_desc) {
		return;
	}

	/* Enumerate this object first */

	acpi_gbl_num_objects++;

	if (obj_desc->common.type > ACPI_TYPE_NS_NODE_MAX) {
		acpi_gbl_obj_type_count_misc++;
	} else {
		acpi_gbl_obj_type_count[obj_desc->common.type]++;
	}

	/* Count the sub-objects */

	switch (obj_desc->common.type) {
	case ACPI_TYPE_PACKAGE:

		for (i = 0; i < obj_desc->package.count; i++) {
			acpi_db_enumerate_object(obj_desc->package.elements[i]);
		}
		break;

	case ACPI_TYPE_DEVICE:

		acpi_db_enumerate_object(obj_desc->device.notify_list[0]);
		acpi_db_enumerate_object(obj_desc->device.notify_list[1]);
		acpi_db_enumerate_object(obj_desc->device.handler);
		break;

	case ACPI_TYPE_BUFFER_FIELD:

		if (acpi_ns_get_secondary_object(obj_desc)) {
			acpi_gbl_obj_type_count[ACPI_TYPE_BUFFER_FIELD]++;
		}
		break;

	case ACPI_TYPE_REGION:

		acpi_gbl_obj_type_count[ACPI_TYPE_LOCAL_REGION_FIELD]++;
		acpi_db_enumerate_object(obj_desc->region.handler);
		break;

	case ACPI_TYPE_POWER:

		acpi_db_enumerate_object(obj_desc->power_resource.
					 notify_list[0]);
		acpi_db_enumerate_object(obj_desc->power_resource.
					 notify_list[1]);
		break;

	case ACPI_TYPE_PROCESSOR:

		acpi_db_enumerate_object(obj_desc->processor.notify_list[0]);
		acpi_db_enumerate_object(obj_desc->processor.notify_list[1]);
		acpi_db_enumerate_object(obj_desc->processor.handler);
		break;

	case ACPI_TYPE_THERMAL:

		acpi_db_enumerate_object(obj_desc->thermal_zone.notify_list[0]);
		acpi_db_enumerate_object(obj_desc->thermal_zone.notify_list[1]);
		acpi_db_enumerate_object(obj_desc->thermal_zone.handler);
		break;

	default:

		break;
	}
}

__attribute__((used)) static acpi_status
acpi_db_classify_one_object(acpi_handle obj_handle,
			    u32 nesting_level,
			    void *context, void **return_value)
{
	struct acpi_namespace_node *node;
	union acpi_operand_object *obj_desc;
	u32 type;

	acpi_gbl_num_nodes++;

	node = (struct acpi_namespace_node *)obj_handle;
	obj_desc = acpi_ns_get_attached_object(node);

	acpi_db_enumerate_object(obj_desc);

	type = node->type;
	if (type > ACPI_TYPE_NS_NODE_MAX) {
		acpi_gbl_node_type_count_misc++;
	} else {
		acpi_gbl_node_type_count[type]++;
	}

	return (AE_OK);

#ifdef ACPI_FUTURE_IMPLEMENTATION

	/* TBD: These need to be counted during the initial parsing phase */

	if (acpi_ps_is_named_op(op->opcode)) {
		num_nodes++;
	}

	if (is_method) {
		num_method_elements++;
	}

	num_grammar_elements++;
	op = acpi_ps_get_depth_next(root, op);

	size_of_parse_tree = (num_grammar_elements - num_method_elements) *
	    (u32)sizeof(union acpi_parse_object);
	size_of_method_trees =
	    num_method_elements * (u32)sizeof(union acpi_parse_object);
	size_of_node_entries =
	    num_nodes * (u32)sizeof(struct acpi_namespace_node);
	size_of_acpi_objects =
	    num_nodes * (u32)sizeof(union acpi_operand_object);
#endif
}

__attribute__((used)) static void acpi_db_count_namespace_objects(void)
{
	u32 i;

	acpi_gbl_num_nodes = 0;
	acpi_gbl_num_objects = 0;

	acpi_gbl_obj_type_count_misc = 0;
	for (i = 0; i < (ACPI_TYPE_NS_NODE_MAX - 1); i++) {
		acpi_gbl_obj_type_count[i] = 0;
		acpi_gbl_node_type_count[i] = 0;
	}

	(void)acpi_ns_walk_namespace(ACPI_TYPE_ANY, ACPI_ROOT_OBJECT,
				     ACPI_UINT32_MAX, FALSE,
				     acpi_db_classify_one_object, NULL, NULL,
				     NULL);
}

acpi_status acpi_db_display_statistics(char *type_arg)
{
	u32 i;
	u32 temp;

	acpi_ut_strupr(type_arg);
	temp = acpi_db_match_argument(type_arg, acpi_db_stat_types);
	if (temp == ACPI_TYPE_NOT_FOUND) {
		acpi_os_printf("Invalid or unsupported argument\n");
		return (AE_OK);
	}

	switch (temp) {
	case CMD_STAT_ALLOCATIONS:

#ifdef ACPI_DBG_TRACK_ALLOCATIONS
		acpi_ut_dump_allocation_info();
#endif
		break;

	case CMD_STAT_TABLES:

		acpi_os_printf("ACPI Table Information (not implemented):\n\n");
		break;

	case CMD_STAT_OBJECTS:

		acpi_db_count_namespace_objects();

		acpi_os_printf
		    ("\nObjects defined in the current namespace:\n\n");

		acpi_os_printf("%16.16s %10.10s %10.10s\n",
			       "ACPI_TYPE", "NODES", "OBJECTS");

		for (i = 0; i < ACPI_TYPE_NS_NODE_MAX; i++) {
			acpi_os_printf("%16.16s % 10ld% 10ld\n",
				       acpi_ut_get_type_name(i),
				       acpi_gbl_node_type_count[i],
				       acpi_gbl_obj_type_count[i]);
		}

		acpi_os_printf("%16.16s % 10ld% 10ld\n", "Misc/Unknown",
			       acpi_gbl_node_type_count_misc,
			       acpi_gbl_obj_type_count_misc);

		acpi_os_printf("%16.16s % 10ld% 10ld\n", "TOTALS:",
			       acpi_gbl_num_nodes, acpi_gbl_num_objects);
		break;

	case CMD_STAT_MEMORY:

#ifdef ACPI_DBG_TRACK_ALLOCATIONS
		acpi_os_printf
		    ("\n----Object Statistics (all in hex)---------\n");

		acpi_db_list_info(acpi_gbl_global_list);
		acpi_db_list_info(acpi_gbl_ns_node_list);
#endif

#ifdef ACPI_USE_LOCAL_CACHE
		acpi_os_printf
		    ("\n----Cache Statistics (all in hex)---------\n");
		acpi_db_list_info(acpi_gbl_operand_cache);
		acpi_db_list_info(acpi_gbl_ps_node_cache);
		acpi_db_list_info(acpi_gbl_ps_node_ext_cache);
		acpi_db_list_info(acpi_gbl_state_cache);
#endif

		break;

	case CMD_STAT_MISC:

		acpi_os_printf("\nMiscellaneous Statistics:\n\n");
		acpi_os_printf("Calls to AcpiPsFind:.. ........% 7ld\n",
			       acpi_gbl_ps_find_count);
		acpi_os_printf("Calls to AcpiNsLookup:..........% 7ld\n",
			       acpi_gbl_ns_lookup_count);

		acpi_os_printf("\n");

		acpi_os_printf("Mutex usage:\n\n");
		for (i = 0; i < ACPI_NUM_MUTEX; i++) {
			acpi_os_printf("%-28s:     % 7ld\n",
				       acpi_ut_get_mutex_name(i),
				       acpi_gbl_mutex_info[i].use_count);
		}
		break;

	case CMD_STAT_SIZES:

		acpi_os_printf("\nInternal object sizes:\n\n");

		acpi_os_printf("Common         %3d\n",
			       sizeof(struct acpi_object_common));
		acpi_os_printf("Number         %3d\n",
			       sizeof(struct acpi_object_integer));
		acpi_os_printf("String         %3d\n",
			       sizeof(struct acpi_object_string));
		acpi_os_printf("Buffer         %3d\n",
			       sizeof(struct acpi_object_buffer));
		acpi_os_printf("Package        %3d\n",
			       sizeof(struct acpi_object_package));
		acpi_os_printf("BufferField    %3d\n",
			       sizeof(struct acpi_object_buffer_field));
		acpi_os_printf("Device         %3d\n",
			       sizeof(struct acpi_object_device));
		acpi_os_printf("Event          %3d\n",
			       sizeof(struct acpi_object_event));
		acpi_os_printf("Method         %3d\n",
			       sizeof(struct acpi_object_method));
		acpi_os_printf("Mutex          %3d\n",
			       sizeof(struct acpi_object_mutex));
		acpi_os_printf("Region         %3d\n",
			       sizeof(struct acpi_object_region));
		acpi_os_printf("PowerResource  %3d\n",
			       sizeof(struct acpi_object_power_resource));
		acpi_os_printf("Processor      %3d\n",
			       sizeof(struct acpi_object_processor));
		acpi_os_printf("ThermalZone    %3d\n",
			       sizeof(struct acpi_object_thermal_zone));
		acpi_os_printf("RegionField    %3d\n",
			       sizeof(struct acpi_object_region_field));
		acpi_os_printf("BankField      %3d\n",
			       sizeof(struct acpi_object_bank_field));
		acpi_os_printf("IndexField     %3d\n",
			       sizeof(struct acpi_object_index_field));
		acpi_os_printf("Reference      %3d\n",
			       sizeof(struct acpi_object_reference));
		acpi_os_printf("Notify         %3d\n",
			       sizeof(struct acpi_object_notify_handler));
		acpi_os_printf("AddressSpace   %3d\n",
			       sizeof(struct acpi_object_addr_handler));
		acpi_os_printf("Extra          %3d\n",
			       sizeof(struct acpi_object_extra));
		acpi_os_printf("Data           %3d\n",
			       sizeof(struct acpi_object_data));

		acpi_os_printf("\n");

		acpi_os_printf("ParseObject    %3d\n",
			       sizeof(struct acpi_parse_obj_common));
		acpi_os_printf("ParseObjectNamed %3d\n",
			       sizeof(struct acpi_parse_obj_named));
		acpi_os_printf("ParseObjectAsl %3d\n",
			       sizeof(struct acpi_parse_obj_asl));
		acpi_os_printf("OperandObject  %3d\n",
			       sizeof(union acpi_operand_object));
		acpi_os_printf("NamespaceNode  %3d\n",
			       sizeof(struct acpi_namespace_node));
		acpi_os_printf("AcpiObject     %3d\n",
			       sizeof(union acpi_object));

		acpi_os_printf("\n");

		acpi_os_printf("Generic State  %3d\n",
			       sizeof(union acpi_generic_state));
		acpi_os_printf("Common State   %3d\n",
			       sizeof(struct acpi_common_state));
		acpi_os_printf("Control State  %3d\n",
			       sizeof(struct acpi_control_state));
		acpi_os_printf("Update State   %3d\n",
			       sizeof(struct acpi_update_state));
		acpi_os_printf("Scope State    %3d\n",
			       sizeof(struct acpi_scope_state));
		acpi_os_printf("Parse Scope    %3d\n",
			       sizeof(struct acpi_pscope_state));
		acpi_os_printf("Package State  %3d\n",
			       sizeof(struct acpi_pkg_state));
		acpi_os_printf("Thread State   %3d\n",
			       sizeof(struct acpi_thread_state));
		acpi_os_printf("Result Values  %3d\n",
			       sizeof(struct acpi_result_values));
		acpi_os_printf("Notify Info    %3d\n",
			       sizeof(struct acpi_notify_info));
		break;

	case CMD_STAT_STACK:
#if defined(ACPI_DEBUG_OUTPUT)

		temp =
		    (u32)ACPI_PTR_DIFF(acpi_gbl_entry_stack_pointer,
				       acpi_gbl_lowest_stack_pointer);

		acpi_os_printf("\nSubsystem Stack Usage:\n\n");
		acpi_os_printf("Entry Stack Pointer        %p\n",
			       acpi_gbl_entry_stack_pointer);
		acpi_os_printf("Lowest Stack Pointer       %p\n",
			       acpi_gbl_lowest_stack_pointer);
		acpi_os_printf("Stack Use                  %X (%u)\n", temp,
			       temp);
		acpi_os_printf("Deepest Procedure Nesting  %u\n",
			       acpi_gbl_deepest_nesting);
#endif
		break;

	default:

		break;
	}

	acpi_os_printf("\n");
	return (AE_OK);
}

