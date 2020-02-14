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
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u32 ;
struct acpi_table_header {int dummy; } ;
struct acpi_predefined_names {int dummy; } ;
typedef  int /*<<< orphan*/ * acpi_string ;
typedef  int /*<<< orphan*/  acpi_status ;
typedef  int /*<<< orphan*/  acpi_physical_address ;

/* Variables and functions */
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AE_BAD_PARAMETER ; 
 int /*<<< orphan*/  AE_NO_ACPI_TABLES ; 
 int /*<<< orphan*/  AE_OK ; 
 int /*<<< orphan*/  AE_SUPPORT ; 
 void* acpi_gbl_output_file ; 
 int /*<<< orphan*/  acpi_gbl_print_lock ; 
 int /*<<< orphan*/  acpi_os_create_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  os_enter_line_edit_mode () ; 
 int /*<<< orphan*/  os_exit_line_edit_mode () ; 
 void* stdout ; 

acpi_status acpi_os_initialize(void)
{
	acpi_status status;

	acpi_gbl_output_file = stdout;

	os_enter_line_edit_mode();

	status = acpi_os_create_lock(&acpi_gbl_print_lock);
	if (ACPI_FAILURE(status)) {
		return (status);
	}

	return (AE_OK);
}

acpi_status acpi_os_terminate(void)
{

	os_exit_line_edit_mode();
	return (AE_OK);
}

acpi_physical_address acpi_os_get_root_pointer(void)
{

	return (0);
}

acpi_status
acpi_os_predefined_override(const struct acpi_predefined_names *init_val,
			    acpi_string *new_val)
{

	if (!init_val || !new_val) {
		return (AE_BAD_PARAMETER);
	}

	*new_val = NULL;
	return (AE_OK);
}

acpi_status
acpi_os_table_override(struct acpi_table_header *existing_table,
		       struct acpi_table_header **new_table)
{

	if (!existing_table || !new_table) {
		return (AE_BAD_PARAMETER);
	}

	*new_table = NULL;

#ifdef ACPI_EXEC_APP

	ae_table_override(existing_table, new_table);
	return (AE_OK);
#else

	return (AE_NO_ACPI_TABLES);
#endif
}

acpi_status
acpi_os_physical_table_override(struct acpi_table_header *existing_table,
				acpi_physical_address *new_address,
				u32 *new_table_length)
{

	return (AE_SUPPORT);
}

acpi_status acpi_os_enter_sleep(u8 sleep_state, u32 rega_value, u32 regb_value)
{

	return (AE_OK);
}

void acpi_os_redirect_output(void *destination)
{

	acpi_gbl_output_file = destination;
}

