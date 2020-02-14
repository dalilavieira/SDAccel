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
struct TYPE_8__ {union acpi_operand_object* handler; } ;
struct TYPE_7__ {scalar_t__ space_id; int handler_flags; scalar_t__ handler; union acpi_operand_object* next; int /*<<< orphan*/ * setup; void* context; struct acpi_namespace_node* node; int /*<<< orphan*/ * region_list; } ;
struct TYPE_6__ {scalar_t__ type; } ;
struct TYPE_5__ {scalar_t__ space_id; } ;
union acpi_operand_object {TYPE_4__ common_notify; TYPE_3__ address_space; TYPE_2__ common; TYPE_1__ region; } ;
typedef  void* u8 ;
typedef  size_t u32 ;
struct acpi_namespace_node {scalar_t__ type; } ;
typedef  int acpi_status ;
typedef  scalar_t__ acpi_object_type ;
typedef  int /*<<< orphan*/  acpi_handle ;
typedef  scalar_t__ acpi_adr_space_type ;
typedef  int /*<<< orphan*/ * acpi_adr_space_setup ;
typedef  scalar_t__ acpi_adr_space_handler ;

/* Variables and functions */
 int ACPI_ADDR_HANDLER_DEFAULT_INSTALLED ; 
#define  ACPI_ADR_SPACE_CMOS 136 
#define  ACPI_ADR_SPACE_DATA_TABLE 135 
#define  ACPI_ADR_SPACE_PCI_BAR_TARGET 134 
#define  ACPI_ADR_SPACE_PCI_CONFIG 133 
#define  ACPI_ADR_SPACE_SYSTEM_IO 132 
#define  ACPI_ADR_SPACE_SYSTEM_MEMORY 131 
 int /*<<< orphan*/  ACPI_DB_OPREGION ; 
 int /*<<< orphan*/  ACPI_DEBUG_PRINT (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_DEFAULT_HANDLER ; 
 scalar_t__ ACPI_FAILURE (int) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_NAME (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_TRACE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_MTX_NAMESPACE ; 
 int /*<<< orphan*/  ACPI_NS_WALK_UNLOCK ; 
 size_t ACPI_NUM_DEFAULT_SPACES ; 
 scalar_t__ ACPI_TYPE_ANY ; 
 scalar_t__ ACPI_TYPE_DEVICE ; 
 scalar_t__ ACPI_TYPE_LOCAL_ADDRESS_HANDLER ; 
 scalar_t__ ACPI_TYPE_PROCESSOR ; 
 scalar_t__ ACPI_TYPE_REGION ; 
 scalar_t__ ACPI_TYPE_THERMAL ; 
 int /*<<< orphan*/  ACPI_UINT32_MAX ; 
#define  AE_ALREADY_EXISTS 130 
 int AE_BAD_PARAMETER ; 
 int AE_CTRL_DEPTH ; 
 int AE_NO_MEMORY ; 
#define  AE_OK 129 
#define  AE_SAME_HANDLER 128 
 void* FALSE ; 
 void* TRUE ; 
 int acpi_ev_attach_region (union acpi_operand_object*,union acpi_operand_object*,void*) ; 
 int /*<<< orphan*/ * acpi_ev_cmos_region_setup ; 
 int /*<<< orphan*/ * acpi_ev_default_region_setup ; 
 int /*<<< orphan*/  acpi_ev_detach_region (union acpi_operand_object*,void*) ; 
 union acpi_operand_object* acpi_ev_find_region_handler (scalar_t__,union acpi_operand_object*) ; 
 int acpi_ev_install_space_handler (struct acpi_namespace_node*,scalar_t__,scalar_t__,int /*<<< orphan*/ *,void*) ; 
 int /*<<< orphan*/ * acpi_ev_io_space_region_setup ; 
 int /*<<< orphan*/ * acpi_ev_pci_bar_region_setup ; 
 int /*<<< orphan*/ * acpi_ev_pci_config_region_setup ; 
 int /*<<< orphan*/ * acpi_ev_system_memory_region_setup ; 
 scalar_t__ acpi_ex_cmos_space_handler ; 
 scalar_t__ acpi_ex_data_table_space_handler ; 
 scalar_t__ acpi_ex_pci_bar_space_handler ; 
 scalar_t__ acpi_ex_pci_config_space_handler ; 
 scalar_t__ acpi_ex_system_io_space_handler ; 
 scalar_t__ acpi_ex_system_memory_space_handler ; 
 scalar_t__* acpi_gbl_default_address_spaces ; 
 struct acpi_namespace_node* acpi_gbl_root_node ; 
 int acpi_ns_attach_object (struct acpi_namespace_node*,union acpi_operand_object*,scalar_t__) ; 
 union acpi_operand_object* acpi_ns_get_attached_object (struct acpi_namespace_node*) ; 
 struct acpi_namespace_node* acpi_ns_validate_handle (int /*<<< orphan*/ ) ; 
 int acpi_ns_walk_namespace (scalar_t__,struct acpi_namespace_node*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int (*) (int /*<<< orphan*/ ,size_t,void*,void**),int /*<<< orphan*/ *,union acpi_operand_object*,int /*<<< orphan*/ *) ; 
 int acpi_ut_acquire_mutex (int /*<<< orphan*/ ) ; 
 union acpi_operand_object* acpi_ut_create_internal_object (scalar_t__) ; 
 int /*<<< orphan*/  acpi_ut_get_node_name (struct acpi_namespace_node*) ; 
 int /*<<< orphan*/  acpi_ut_get_region_name (scalar_t__) ; 
 int /*<<< orphan*/  acpi_ut_release_mutex (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  acpi_ut_remove_reference (union acpi_operand_object*) ; 
 int /*<<< orphan*/  ev_install_handler ; 
 int /*<<< orphan*/  ev_install_region_handlers ; 
 int /*<<< orphan*/  ev_install_space_handler ; 
 int /*<<< orphan*/  return_ACPI_STATUS (int) ; 

acpi_status acpi_ev_install_region_handlers(void)
{
	acpi_status status;
	u32 i;

	ACPI_FUNCTION_TRACE(ev_install_region_handlers);

	status = acpi_ut_acquire_mutex(ACPI_MTX_NAMESPACE);
	if (ACPI_FAILURE(status)) {
		return_ACPI_STATUS(status);
	}

	/*
	 * All address spaces (PCI Config, EC, SMBus) are scope dependent and
	 * registration must occur for a specific device.
	 *
	 * In the case of the system memory and IO address spaces there is
	 * currently no device associated with the address space. For these we
	 * use the root.
	 *
	 * We install the default PCI config space handler at the root so that
	 * this space is immediately available even though the we have not
	 * enumerated all the PCI Root Buses yet. This is to conform to the ACPI
	 * specification which states that the PCI config space must be always
	 * available -- even though we are nowhere near ready to find the PCI root
	 * buses at this point.
	 *
	 * NOTE: We ignore AE_ALREADY_EXISTS because this means that a handler
	 * has already been installed (via acpi_install_address_space_handler).
	 * Similar for AE_SAME_HANDLER.
	 */
	for (i = 0; i < ACPI_NUM_DEFAULT_SPACES; i++) {
		status = acpi_ev_install_space_handler(acpi_gbl_root_node,
						       acpi_gbl_default_address_spaces
						       [i],
						       ACPI_DEFAULT_HANDLER,
						       NULL, NULL);
		switch (status) {
		case AE_OK:
		case AE_SAME_HANDLER:
		case AE_ALREADY_EXISTS:

			/* These exceptions are all OK */

			status = AE_OK;
			break;

		default:

			goto unlock_and_exit;
		}
	}

unlock_and_exit:
	(void)acpi_ut_release_mutex(ACPI_MTX_NAMESPACE);
	return_ACPI_STATUS(status);
}

u8
acpi_ev_has_default_handler(struct acpi_namespace_node *node,
			    acpi_adr_space_type space_id)
{
	union acpi_operand_object *obj_desc;
	union acpi_operand_object *handler_obj;

	/* Must have an existing internal object */

	obj_desc = acpi_ns_get_attached_object(node);
	if (obj_desc) {
		handler_obj = obj_desc->common_notify.handler;

		/* Walk the linked list of handlers for this object */

		while (handler_obj) {
			if (handler_obj->address_space.space_id == space_id) {
				if (handler_obj->address_space.handler_flags &
				    ACPI_ADDR_HANDLER_DEFAULT_INSTALLED) {
					return (TRUE);
				}
			}

			handler_obj = handler_obj->address_space.next;
		}
	}

	return (FALSE);
}

__attribute__((used)) static acpi_status
acpi_ev_install_handler(acpi_handle obj_handle,
			u32 level, void *context, void **return_value)
{
	union acpi_operand_object *handler_obj;
	union acpi_operand_object *next_handler_obj;
	union acpi_operand_object *obj_desc;
	struct acpi_namespace_node *node;
	acpi_status status;

	ACPI_FUNCTION_NAME(ev_install_handler);

	handler_obj = (union acpi_operand_object *)context;

	/* Parameter validation */

	if (!handler_obj) {
		return (AE_OK);
	}

	/* Convert and validate the device handle */

	node = acpi_ns_validate_handle(obj_handle);
	if (!node) {
		return (AE_BAD_PARAMETER);
	}

	/*
	 * We only care about regions and objects that are allowed to have
	 * address space handlers
	 */
	if ((node->type != ACPI_TYPE_DEVICE) &&
	    (node->type != ACPI_TYPE_REGION) && (node != acpi_gbl_root_node)) {
		return (AE_OK);
	}

	/* Check for an existing internal object */

	obj_desc = acpi_ns_get_attached_object(node);
	if (!obj_desc) {

		/* No object, just exit */

		return (AE_OK);
	}

	/* Devices are handled different than regions */

	if (obj_desc->common.type == ACPI_TYPE_DEVICE) {

		/* Check if this Device already has a handler for this address space */

		next_handler_obj =
		    acpi_ev_find_region_handler(handler_obj->address_space.
						space_id,
						obj_desc->common_notify.
						handler);
		if (next_handler_obj) {

			/* Found a handler, is it for the same address space? */

			ACPI_DEBUG_PRINT((ACPI_DB_OPREGION,
					  "Found handler for region [%s] in device %p(%p) handler %p\n",
					  acpi_ut_get_region_name(handler_obj->
								  address_space.
								  space_id),
					  obj_desc, next_handler_obj,
					  handler_obj));

			/*
			 * Since the object we found it on was a device, then it means
			 * that someone has already installed a handler for the branch
			 * of the namespace from this device on. Just bail out telling
			 * the walk routine to not traverse this branch. This preserves
			 * the scoping rule for handlers.
			 */
			return (AE_CTRL_DEPTH);
		}

		/*
		 * As long as the device didn't have a handler for this space we
		 * don't care about it. We just ignore it and proceed.
		 */
		return (AE_OK);
	}

	/* Object is a Region */

	if (obj_desc->region.space_id != handler_obj->address_space.space_id) {

		/* This region is for a different address space, just ignore it */

		return (AE_OK);
	}

	/*
	 * Now we have a region and it is for the handler's address space type.
	 *
	 * First disconnect region for any previous handler (if any)
	 */
	acpi_ev_detach_region(obj_desc, FALSE);

	/* Connect the region to the new handler */

	status = acpi_ev_attach_region(handler_obj, obj_desc, FALSE);
	return (status);
}

union acpi_operand_object *acpi_ev_find_region_handler(acpi_adr_space_type
						       space_id,
						       union acpi_operand_object
						       *handler_obj)
{

	/* Walk the handler list for this device */

	while (handler_obj) {

		/* Same space_id indicates a handler is installed */

		if (handler_obj->address_space.space_id == space_id) {
			return (handler_obj);
		}

		/* Next handler object */

		handler_obj = handler_obj->address_space.next;
	}

	return (NULL);
}

acpi_status
acpi_ev_install_space_handler(struct acpi_namespace_node *node,
			      acpi_adr_space_type space_id,
			      acpi_adr_space_handler handler,
			      acpi_adr_space_setup setup, void *context)
{
	union acpi_operand_object *obj_desc;
	union acpi_operand_object *handler_obj;
	acpi_status status = AE_OK;
	acpi_object_type type;
	u8 flags = 0;

	ACPI_FUNCTION_TRACE(ev_install_space_handler);

	/*
	 * This registration is valid for only the types below and the root.
	 * The root node is where the default handlers get installed.
	 */
	if ((node->type != ACPI_TYPE_DEVICE) &&
	    (node->type != ACPI_TYPE_PROCESSOR) &&
	    (node->type != ACPI_TYPE_THERMAL) && (node != acpi_gbl_root_node)) {
		status = AE_BAD_PARAMETER;
		goto unlock_and_exit;
	}

	if (handler == ACPI_DEFAULT_HANDLER) {
		flags = ACPI_ADDR_HANDLER_DEFAULT_INSTALLED;

		switch (space_id) {
		case ACPI_ADR_SPACE_SYSTEM_MEMORY:

			handler = acpi_ex_system_memory_space_handler;
			setup = acpi_ev_system_memory_region_setup;
			break;

		case ACPI_ADR_SPACE_SYSTEM_IO:

			handler = acpi_ex_system_io_space_handler;
			setup = acpi_ev_io_space_region_setup;
			break;

		case ACPI_ADR_SPACE_PCI_CONFIG:

			handler = acpi_ex_pci_config_space_handler;
			setup = acpi_ev_pci_config_region_setup;
			break;

		case ACPI_ADR_SPACE_CMOS:

			handler = acpi_ex_cmos_space_handler;
			setup = acpi_ev_cmos_region_setup;
			break;

		case ACPI_ADR_SPACE_PCI_BAR_TARGET:

			handler = acpi_ex_pci_bar_space_handler;
			setup = acpi_ev_pci_bar_region_setup;
			break;

		case ACPI_ADR_SPACE_DATA_TABLE:

			handler = acpi_ex_data_table_space_handler;
			setup = NULL;
			break;

		default:

			status = AE_BAD_PARAMETER;
			goto unlock_and_exit;
		}
	}

	/* If the caller hasn't specified a setup routine, use the default */

	if (!setup) {
		setup = acpi_ev_default_region_setup;
	}

	/* Check for an existing internal object */

	obj_desc = acpi_ns_get_attached_object(node);
	if (obj_desc) {
		/*
		 * The attached device object already exists. Now make sure
		 * the handler is not already installed.
		 */
		handler_obj = acpi_ev_find_region_handler(space_id,
							  obj_desc->
							  common_notify.
							  handler);

		if (handler_obj) {
			if (handler_obj->address_space.handler == handler) {
				/*
				 * It is (relatively) OK to attempt to install the SAME
				 * handler twice. This can easily happen with the
				 * PCI_Config space.
				 */
				status = AE_SAME_HANDLER;
				goto unlock_and_exit;
			} else {
				/* A handler is already installed */

				status = AE_ALREADY_EXISTS;
			}

			goto unlock_and_exit;
		}
	} else {
		ACPI_DEBUG_PRINT((ACPI_DB_OPREGION,
				  "Creating object on Device %p while installing handler\n",
				  node));

		/* obj_desc does not exist, create one */

		if (node->type == ACPI_TYPE_ANY) {
			type = ACPI_TYPE_DEVICE;
		} else {
			type = node->type;
		}

		obj_desc = acpi_ut_create_internal_object(type);
		if (!obj_desc) {
			status = AE_NO_MEMORY;
			goto unlock_and_exit;
		}

		/* Init new descriptor */

		obj_desc->common.type = (u8)type;

		/* Attach the new object to the Node */

		status = acpi_ns_attach_object(node, obj_desc, type);

		/* Remove local reference to the object */

		acpi_ut_remove_reference(obj_desc);

		if (ACPI_FAILURE(status)) {
			goto unlock_and_exit;
		}
	}

	ACPI_DEBUG_PRINT((ACPI_DB_OPREGION,
			  "Installing address handler for region %s(%X) "
			  "on Device %4.4s %p(%p)\n",
			  acpi_ut_get_region_name(space_id), space_id,
			  acpi_ut_get_node_name(node), node, obj_desc));

	/*
	 * Install the handler
	 *
	 * At this point there is no existing handler. Just allocate the object
	 * for the handler and link it into the list.
	 */
	handler_obj =
	    acpi_ut_create_internal_object(ACPI_TYPE_LOCAL_ADDRESS_HANDLER);
	if (!handler_obj) {
		status = AE_NO_MEMORY;
		goto unlock_and_exit;
	}

	/* Init handler obj */

	handler_obj->address_space.space_id = (u8)space_id;
	handler_obj->address_space.handler_flags = flags;
	handler_obj->address_space.region_list = NULL;
	handler_obj->address_space.node = node;
	handler_obj->address_space.handler = handler;
	handler_obj->address_space.context = context;
	handler_obj->address_space.setup = setup;

	/* Install at head of Device.address_space list */

	handler_obj->address_space.next = obj_desc->common_notify.handler;

	/*
	 * The Device object is the first reference on the handler_obj.
	 * Each region that uses the handler adds a reference.
	 */
	obj_desc->common_notify.handler = handler_obj;

	/*
	 * Walk the namespace finding all of the regions this handler will
	 * manage.
	 *
	 * Start at the device and search the branch toward the leaf nodes
	 * until either the leaf is encountered or a device is detected that
	 * has an address handler of the same type.
	 *
	 * In either case, back up and search down the remainder of the branch
	 */
	status = acpi_ns_walk_namespace(ACPI_TYPE_ANY, node,
					ACPI_UINT32_MAX, ACPI_NS_WALK_UNLOCK,
					acpi_ev_install_handler, NULL,
					handler_obj, NULL);

unlock_and_exit:
	return_ACPI_STATUS(status);
}

