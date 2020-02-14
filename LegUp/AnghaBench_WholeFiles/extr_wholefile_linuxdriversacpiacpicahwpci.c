#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  scalar_t__ u8 ;
typedef  scalar_t__ u64 ;
typedef  void* u16 ;
struct acpi_pci_id {void* bus; int /*<<< orphan*/  function; int /*<<< orphan*/  device; int /*<<< orphan*/  segment; } ;
struct acpi_pci_device {scalar_t__ device; struct acpi_pci_device* next; } ;
typedef  int /*<<< orphan*/  acpi_status ;
typedef  scalar_t__ acpi_object_type ;
typedef  scalar_t__ acpi_handle ;

/* Variables and functions */
 struct acpi_pci_device* ACPI_ALLOCATE (int) ; 
 int /*<<< orphan*/  ACPI_DB_OPREGION ; 
 int /*<<< orphan*/  ACPI_DEBUG_PRINT (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FREE (struct acpi_pci_device*) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_NAME (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_TRACE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_HIWORD (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_LODWORD (scalar_t__) ; 
 int /*<<< orphan*/  ACPI_LOWORD (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_SUCCESS (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_TYPE_DEVICE ; 
 int /*<<< orphan*/  AE_BAD_PARAMETER ; 
 int /*<<< orphan*/  AE_NO_MEMORY ; 
 int /*<<< orphan*/  AE_OK ; 
 scalar_t__ FALSE ; 
 int /*<<< orphan*/  METHOD_NAME__ADR ; 
 int /*<<< orphan*/  PCI_CFG_HEADER_TYPE_REG ; 
 int /*<<< orphan*/  PCI_CFG_PRIMARY_BUS_NUMBER_REG ; 
 int /*<<< orphan*/  PCI_CFG_SECONDARY_BUS_NUMBER_REG ; 
 scalar_t__ PCI_HEADER_TYPE_MASK ; 
 scalar_t__ PCI_TYPE_BRIDGE ; 
 scalar_t__ PCI_TYPE_CARDBUS_BRIDGE ; 
 scalar_t__ TRUE ; 
 int /*<<< orphan*/  acpi_get_parent (scalar_t__,scalar_t__*) ; 
 int /*<<< orphan*/  acpi_get_type (scalar_t__,scalar_t__*) ; 
static  int /*<<< orphan*/  acpi_hw_build_pci_list (scalar_t__,scalar_t__,struct acpi_pci_device**) ; 
static  void acpi_hw_delete_pci_list (struct acpi_pci_device*) ; 
static  int /*<<< orphan*/  acpi_hw_get_pci_device_info (struct acpi_pci_id*,scalar_t__,void**,scalar_t__*) ; 
static  int /*<<< orphan*/  acpi_hw_process_pci_list (struct acpi_pci_id*,struct acpi_pci_device*) ; 
 int /*<<< orphan*/  acpi_os_read_pci_configuration (struct acpi_pci_id*,int /*<<< orphan*/ ,scalar_t__*,int) ; 
 int /*<<< orphan*/  acpi_ut_evaluate_numeric_object (int /*<<< orphan*/ ,scalar_t__,scalar_t__*) ; 
 int /*<<< orphan*/  hw_derive_pci_id ; 
 int /*<<< orphan*/  hw_process_pci_list ; 
 int /*<<< orphan*/  return_ACPI_STATUS (int /*<<< orphan*/ ) ; 

acpi_status
acpi_hw_derive_pci_id(struct acpi_pci_id *pci_id,
		      acpi_handle root_pci_device, acpi_handle pci_region)
{
	acpi_status status;
	struct acpi_pci_device *list_head;

	ACPI_FUNCTION_TRACE(hw_derive_pci_id);

	if (!pci_id) {
		return_ACPI_STATUS(AE_BAD_PARAMETER);
	}

	/* Build a list of PCI devices, from pci_region up to root_pci_device */

	status =
	    acpi_hw_build_pci_list(root_pci_device, pci_region, &list_head);
	if (ACPI_SUCCESS(status)) {

		/* Walk the list, updating the PCI device/function/bus numbers */

		status = acpi_hw_process_pci_list(pci_id, list_head);

		/* Delete the list */

		acpi_hw_delete_pci_list(list_head);
	}

	return_ACPI_STATUS(status);
}

__attribute__((used)) static acpi_status
acpi_hw_build_pci_list(acpi_handle root_pci_device,
		       acpi_handle pci_region,
		       struct acpi_pci_device **return_list_head)
{
	acpi_handle current_device;
	acpi_handle parent_device;
	acpi_status status;
	struct acpi_pci_device *list_element;

	/*
	 * Ascend namespace branch until the root_pci_device is reached, building
	 * a list of device nodes. Loop will exit when either the PCI device is
	 * found, or the root of the namespace is reached.
	 */
	*return_list_head = NULL;
	current_device = pci_region;
	while (1) {
		status = acpi_get_parent(current_device, &parent_device);
		if (ACPI_FAILURE(status)) {

			/* Must delete the list before exit */

			acpi_hw_delete_pci_list(*return_list_head);
			return (status);
		}

		/* Finished when we reach the PCI root device (PNP0A03 or PNP0A08) */

		if (parent_device == root_pci_device) {
			return (AE_OK);
		}

		list_element = ACPI_ALLOCATE(sizeof(struct acpi_pci_device));
		if (!list_element) {

			/* Must delete the list before exit */

			acpi_hw_delete_pci_list(*return_list_head);
			return (AE_NO_MEMORY);
		}

		/* Put new element at the head of the list */

		list_element->next = *return_list_head;
		list_element->device = parent_device;
		*return_list_head = list_element;

		current_device = parent_device;
	}
}

__attribute__((used)) static acpi_status
acpi_hw_process_pci_list(struct acpi_pci_id *pci_id,
			 struct acpi_pci_device *list_head)
{
	acpi_status status = AE_OK;
	struct acpi_pci_device *info;
	u16 bus_number;
	u8 is_bridge = TRUE;

	ACPI_FUNCTION_NAME(hw_process_pci_list);

	ACPI_DEBUG_PRINT((ACPI_DB_OPREGION,
			  "Input PciId:  Seg %4.4X Bus %4.4X Dev %4.4X Func %4.4X\n",
			  pci_id->segment, pci_id->bus, pci_id->device,
			  pci_id->function));

	bus_number = pci_id->bus;

	/*
	 * Descend down the namespace tree, collecting PCI device, function,
	 * and bus numbers. bus_number is only important for PCI bridges.
	 * Algorithm: As we descend the tree, use the last valid PCI device,
	 * function, and bus numbers that are discovered, and assign them
	 * to the PCI ID for the target device.
	 */
	info = list_head;
	while (info) {
		status = acpi_hw_get_pci_device_info(pci_id, info->device,
						     &bus_number, &is_bridge);
		if (ACPI_FAILURE(status)) {
			return (status);
		}

		info = info->next;
	}

	ACPI_DEBUG_PRINT((ACPI_DB_OPREGION,
			  "Output PciId: Seg %4.4X Bus %4.4X Dev %4.4X Func %4.4X "
			  "Status %X BusNumber %X IsBridge %X\n",
			  pci_id->segment, pci_id->bus, pci_id->device,
			  pci_id->function, status, bus_number, is_bridge));

	return (AE_OK);
}

__attribute__((used)) static void acpi_hw_delete_pci_list(struct acpi_pci_device *list_head)
{
	struct acpi_pci_device *next;
	struct acpi_pci_device *previous;

	next = list_head;
	while (next) {
		previous = next;
		next = previous->next;
		ACPI_FREE(previous);
	}
}

__attribute__((used)) static acpi_status
acpi_hw_get_pci_device_info(struct acpi_pci_id *pci_id,
			    acpi_handle pci_device,
			    u16 *bus_number, u8 *is_bridge)
{
	acpi_status status;
	acpi_object_type object_type;
	u64 return_value;
	u64 pci_value;

	/* We only care about objects of type Device */

	status = acpi_get_type(pci_device, &object_type);
	if (ACPI_FAILURE(status)) {
		return (status);
	}

	if (object_type != ACPI_TYPE_DEVICE) {
		return (AE_OK);
	}

	/* We need an _ADR. Ignore device if not present */

	status = acpi_ut_evaluate_numeric_object(METHOD_NAME__ADR,
						 pci_device, &return_value);
	if (ACPI_FAILURE(status)) {
		return (AE_OK);
	}

	/*
	 * From _ADR, get the PCI Device and Function and
	 * update the PCI ID.
	 */
	pci_id->device = ACPI_HIWORD(ACPI_LODWORD(return_value));
	pci_id->function = ACPI_LOWORD(ACPI_LODWORD(return_value));

	/*
	 * If the previous device was a bridge, use the previous
	 * device bus number
	 */
	if (*is_bridge) {
		pci_id->bus = *bus_number;
	}

	/*
	 * Get the bus numbers from PCI Config space:
	 *
	 * First, get the PCI header_type
	 */
	*is_bridge = FALSE;
	status = acpi_os_read_pci_configuration(pci_id,
						PCI_CFG_HEADER_TYPE_REG,
						&pci_value, 8);
	if (ACPI_FAILURE(status)) {
		return (status);
	}

	/* We only care about bridges (1=pci_bridge, 2=card_bus_bridge) */

	pci_value &= PCI_HEADER_TYPE_MASK;

	if ((pci_value != PCI_TYPE_BRIDGE) &&
	    (pci_value != PCI_TYPE_CARDBUS_BRIDGE)) {
		return (AE_OK);
	}

	/* Bridge: Get the Primary bus_number */

	status = acpi_os_read_pci_configuration(pci_id,
						PCI_CFG_PRIMARY_BUS_NUMBER_REG,
						&pci_value, 8);
	if (ACPI_FAILURE(status)) {
		return (status);
	}

	*is_bridge = TRUE;
	pci_id->bus = (u16)pci_value;

	/* Bridge: Get the Secondary bus_number */

	status = acpi_os_read_pci_configuration(pci_id,
						PCI_CFG_SECONDARY_BUS_NUMBER_REG,
						&pci_value, 8);
	if (ACPI_FAILURE(status)) {
		return (status);
	}

	*bus_number = (u16)pci_value;
	return (AE_OK);
}

