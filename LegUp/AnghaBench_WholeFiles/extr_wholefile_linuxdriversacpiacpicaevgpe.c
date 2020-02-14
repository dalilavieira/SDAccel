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
struct TYPE_2__ {struct acpi_gpe_block_info* gpe_block; } ;
union acpi_operand_object {TYPE_1__ device; } ;
typedef  int u8 ;
typedef  int u32 ;
struct acpi_namespace_node {int dummy; } ;
struct acpi_gpe_xrupt_info {struct acpi_gpe_block_info* gpe_block_list_head; } ;
struct acpi_gpe_register_info {int enable_for_run; int enable_mask; int mask_for_run; int enable_for_wake; int base_gpe_number; } ;
struct acpi_gpe_event_info {int runtime_count; int /*<<< orphan*/  disable_for_dispatch; struct acpi_gpe_register_info* register_info; } ;
struct acpi_gpe_block_info {int block_base_number; int gpe_count; int register_count; struct acpi_gpe_block_info* next; struct acpi_gpe_event_info* event_info; struct acpi_gpe_register_info* register_info; struct acpi_namespace_node* node; } ;
typedef  int /*<<< orphan*/  acpi_status ;
typedef  int acpi_size ;
typedef  scalar_t__ acpi_handle ;
typedef  int /*<<< orphan*/  acpi_cpu_flags ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_CLEAR_BIT (int,int) ; 
 int /*<<< orphan*/  ACPI_DB_INTERRUPTS ; 
 int /*<<< orphan*/  ACPI_DEBUG_PRINT (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_ENTRY () ; 
 int /*<<< orphan*/  ACPI_FUNCTION_NAME (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_TRACE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_GPE_DISABLE ; 
 int /*<<< orphan*/  ACPI_GPE_ENABLE ; 
 int ACPI_GPE_REGISTER_WIDTH ; 
 int ACPI_INTERRUPT_NOT_HANDLED ; 
 int ACPI_MAX_GPE_BLOCKS ; 
 int /*<<< orphan*/  ACPI_SET_BIT (int,int) ; 
 scalar_t__ ACPI_SUCCESS (int /*<<< orphan*/ ) ; 
 int ACPI_UINT8_MAX ; 
 int /*<<< orphan*/  AE_BAD_PARAMETER ; 
 int /*<<< orphan*/  AE_LIMIT ; 
 int /*<<< orphan*/  AE_NOT_EXIST ; 
 int /*<<< orphan*/  AE_OK ; 
 int acpi_ev_detect_gpe (struct acpi_namespace_node*,struct acpi_gpe_event_info*,int) ; 
 struct acpi_gpe_block_info** acpi_gbl_gpe_fadt_blocks ; 
 int /*<<< orphan*/  acpi_gbl_gpe_lock ; 
 int /*<<< orphan*/  acpi_hw_clear_gpe (struct acpi_gpe_event_info*) ; 
 int acpi_hw_get_gpe_register_bit (struct acpi_gpe_event_info*) ; 
 int /*<<< orphan*/  acpi_hw_low_set_gpe (struct acpi_gpe_event_info*,int /*<<< orphan*/ ) ; 
 union acpi_operand_object* acpi_ns_get_attached_object (struct acpi_namespace_node*) ; 
 int /*<<< orphan*/  acpi_os_acquire_lock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  acpi_os_release_lock (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ev_add_gpe_reference ; 
 int /*<<< orphan*/  ev_enable_gpe ; 
 int /*<<< orphan*/  ev_gpe_detect ; 
 int /*<<< orphan*/  ev_mask_gpe ; 
 int /*<<< orphan*/  ev_remove_gpe_reference ; 
 int /*<<< orphan*/  ev_update_gpe_enable_mask ; 
 int /*<<< orphan*/  return_ACPI_STATUS (int /*<<< orphan*/ ) ; 

acpi_status
acpi_ev_update_gpe_enable_mask(struct acpi_gpe_event_info *gpe_event_info)
{
	struct acpi_gpe_register_info *gpe_register_info;
	u32 register_bit;

	ACPI_FUNCTION_TRACE(ev_update_gpe_enable_mask);

	gpe_register_info = gpe_event_info->register_info;
	if (!gpe_register_info) {
		return_ACPI_STATUS(AE_NOT_EXIST);
	}

	register_bit = acpi_hw_get_gpe_register_bit(gpe_event_info);

	/* Clear the run bit up front */

	ACPI_CLEAR_BIT(gpe_register_info->enable_for_run, register_bit);

	/* Set the mask bit only if there are references to this GPE */

	if (gpe_event_info->runtime_count) {
		ACPI_SET_BIT(gpe_register_info->enable_for_run,
			     (u8)register_bit);
	}

	gpe_register_info->enable_mask = gpe_register_info->enable_for_run;
	return_ACPI_STATUS(AE_OK);
}

acpi_status acpi_ev_enable_gpe(struct acpi_gpe_event_info *gpe_event_info)
{
	acpi_status status;

	ACPI_FUNCTION_TRACE(ev_enable_gpe);

	/* Clear the GPE status */
	status = acpi_hw_clear_gpe(gpe_event_info);
	if (ACPI_FAILURE(status))
		return_ACPI_STATUS(status);

	/* Enable the requested GPE */
	status = acpi_hw_low_set_gpe(gpe_event_info, ACPI_GPE_ENABLE);
	return_ACPI_STATUS(status);
}

acpi_status
acpi_ev_mask_gpe(struct acpi_gpe_event_info *gpe_event_info, u8 is_masked)
{
	struct acpi_gpe_register_info *gpe_register_info;
	u32 register_bit;

	ACPI_FUNCTION_TRACE(ev_mask_gpe);

	gpe_register_info = gpe_event_info->register_info;
	if (!gpe_register_info) {
		return_ACPI_STATUS(AE_NOT_EXIST);
	}

	register_bit = acpi_hw_get_gpe_register_bit(gpe_event_info);

	/* Perform the action */

	if (is_masked) {
		if (register_bit & gpe_register_info->mask_for_run) {
			return_ACPI_STATUS(AE_BAD_PARAMETER);
		}

		(void)acpi_hw_low_set_gpe(gpe_event_info, ACPI_GPE_DISABLE);
		ACPI_SET_BIT(gpe_register_info->mask_for_run, (u8)register_bit);
	} else {
		if (!(register_bit & gpe_register_info->mask_for_run)) {
			return_ACPI_STATUS(AE_BAD_PARAMETER);
		}

		ACPI_CLEAR_BIT(gpe_register_info->mask_for_run,
			       (u8)register_bit);
		if (gpe_event_info->runtime_count
		    && !gpe_event_info->disable_for_dispatch) {
			(void)acpi_hw_low_set_gpe(gpe_event_info,
						  ACPI_GPE_ENABLE);
		}
	}

	return_ACPI_STATUS(AE_OK);
}

acpi_status
acpi_ev_add_gpe_reference(struct acpi_gpe_event_info *gpe_event_info)
{
	acpi_status status = AE_OK;

	ACPI_FUNCTION_TRACE(ev_add_gpe_reference);

	if (gpe_event_info->runtime_count == ACPI_UINT8_MAX) {
		return_ACPI_STATUS(AE_LIMIT);
	}

	gpe_event_info->runtime_count++;
	if (gpe_event_info->runtime_count == 1) {

		/* Enable on first reference */

		status = acpi_ev_update_gpe_enable_mask(gpe_event_info);
		if (ACPI_SUCCESS(status)) {
			status = acpi_ev_enable_gpe(gpe_event_info);
		}

		if (ACPI_FAILURE(status)) {
			gpe_event_info->runtime_count--;
		}
	}

	return_ACPI_STATUS(status);
}

acpi_status
acpi_ev_remove_gpe_reference(struct acpi_gpe_event_info *gpe_event_info)
{
	acpi_status status = AE_OK;

	ACPI_FUNCTION_TRACE(ev_remove_gpe_reference);

	if (!gpe_event_info->runtime_count) {
		return_ACPI_STATUS(AE_LIMIT);
	}

	gpe_event_info->runtime_count--;
	if (!gpe_event_info->runtime_count) {

		/* Disable on last reference */

		status = acpi_ev_update_gpe_enable_mask(gpe_event_info);
		if (ACPI_SUCCESS(status)) {
			status =
			    acpi_hw_low_set_gpe(gpe_event_info,
						ACPI_GPE_DISABLE);
		}

		if (ACPI_FAILURE(status)) {
			gpe_event_info->runtime_count++;
		}
	}

	return_ACPI_STATUS(status);
}

struct acpi_gpe_event_info *acpi_ev_low_get_gpe_info(u32 gpe_number,
						     struct acpi_gpe_block_info
						     *gpe_block)
{
	u32 gpe_index;

	/*
	 * Validate that the gpe_number is within the specified gpe_block.
	 * (Two steps)
	 */
	if (!gpe_block || (gpe_number < gpe_block->block_base_number)) {
		return (NULL);
	}

	gpe_index = gpe_number - gpe_block->block_base_number;
	if (gpe_index >= gpe_block->gpe_count) {
		return (NULL);
	}

	return (&gpe_block->event_info[gpe_index]);
}

struct acpi_gpe_event_info *acpi_ev_get_gpe_event_info(acpi_handle gpe_device,
						       u32 gpe_number)
{
	union acpi_operand_object *obj_desc;
	struct acpi_gpe_event_info *gpe_info;
	u32 i;

	ACPI_FUNCTION_ENTRY();

	/* A NULL gpe_device means use the FADT-defined GPE block(s) */

	if (!gpe_device) {

		/* Examine GPE Block 0 and 1 (These blocks are permanent) */

		for (i = 0; i < ACPI_MAX_GPE_BLOCKS; i++) {
			gpe_info = acpi_ev_low_get_gpe_info(gpe_number,
							    acpi_gbl_gpe_fadt_blocks
							    [i]);
			if (gpe_info) {
				return (gpe_info);
			}
		}

		/* The gpe_number was not in the range of either FADT GPE block */

		return (NULL);
	}

	/* A Non-NULL gpe_device means this is a GPE Block Device */

	obj_desc =
	    acpi_ns_get_attached_object((struct acpi_namespace_node *)
					       gpe_device);
	if (!obj_desc || !obj_desc->device.gpe_block) {
		return (NULL);
	}

	return (acpi_ev_low_get_gpe_info
		(gpe_number, obj_desc->device.gpe_block));
}

u32 acpi_ev_gpe_detect(struct acpi_gpe_xrupt_info *gpe_xrupt_list)
{
	struct acpi_gpe_block_info *gpe_block;
	struct acpi_namespace_node *gpe_device;
	struct acpi_gpe_register_info *gpe_register_info;
	struct acpi_gpe_event_info *gpe_event_info;
	u32 gpe_number;
	u32 int_status = ACPI_INTERRUPT_NOT_HANDLED;
	acpi_cpu_flags flags;
	u32 i;
	u32 j;

	ACPI_FUNCTION_NAME(ev_gpe_detect);

	/* Check for the case where there are no GPEs */

	if (!gpe_xrupt_list) {
		return (int_status);
	}

	/*
	 * We need to obtain the GPE lock for both the data structs and registers
	 * Note: Not necessary to obtain the hardware lock, since the GPE
	 * registers are owned by the gpe_lock.
	 */
	flags = acpi_os_acquire_lock(acpi_gbl_gpe_lock);

	/* Examine all GPE blocks attached to this interrupt level */

	gpe_block = gpe_xrupt_list->gpe_block_list_head;
	while (gpe_block) {
		gpe_device = gpe_block->node;

		/*
		 * Read all of the 8-bit GPE status and enable registers in this GPE
		 * block, saving all of them. Find all currently active GP events.
		 */
		for (i = 0; i < gpe_block->register_count; i++) {

			/* Get the next status/enable pair */

			gpe_register_info = &gpe_block->register_info[i];

			/*
			 * Optimization: If there are no GPEs enabled within this
			 * register, we can safely ignore the entire register.
			 */
			if (!(gpe_register_info->enable_for_run |
			      gpe_register_info->enable_for_wake)) {
				ACPI_DEBUG_PRINT((ACPI_DB_INTERRUPTS,
						  "Ignore disabled registers for GPE %02X-%02X: "
						  "RunEnable=%02X, WakeEnable=%02X\n",
						  gpe_register_info->
						  base_gpe_number,
						  gpe_register_info->
						  base_gpe_number +
						  (ACPI_GPE_REGISTER_WIDTH - 1),
						  gpe_register_info->
						  enable_for_run,
						  gpe_register_info->
						  enable_for_wake));
				continue;
			}

			/* Now look at the individual GPEs in this byte register */

			for (j = 0; j < ACPI_GPE_REGISTER_WIDTH; j++) {

				/* Detect and dispatch one GPE bit */

				gpe_event_info =
				    &gpe_block->
				    event_info[((acpi_size)i *
						ACPI_GPE_REGISTER_WIDTH) + j];
				gpe_number =
				    j + gpe_register_info->base_gpe_number;
				acpi_os_release_lock(acpi_gbl_gpe_lock, flags);
				int_status |=
				    acpi_ev_detect_gpe(gpe_device,
						       gpe_event_info,
						       gpe_number);
				flags = acpi_os_acquire_lock(acpi_gbl_gpe_lock);
			}
		}

		gpe_block = gpe_block->next;
	}

	acpi_os_release_lock(acpi_gbl_gpe_lock, flags);
	return (int_status);
}

