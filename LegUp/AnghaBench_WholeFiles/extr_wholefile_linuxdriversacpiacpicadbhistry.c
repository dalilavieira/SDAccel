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
typedef  size_t u32 ;
typedef  scalar_t__ u16 ;
struct TYPE_2__ {char* command; size_t cmd_num; } ;

/* Variables and functions */
 size_t HISTORY_SIZE ; 
 char* acpi_db_get_history_by_index (size_t) ; 
 TYPE_1__* acpi_gbl_history_buffer ; 
 size_t acpi_gbl_lo_history ; 
 void* acpi_gbl_next_cmd_num ; 
 size_t acpi_gbl_next_history_index ; 
 size_t acpi_gbl_num_history ; 
 void* acpi_os_allocate (scalar_t__) ; 
 int /*<<< orphan*/  acpi_os_free (char*) ; 
 int /*<<< orphan*/  acpi_os_printf (char*,scalar_t__,...) ; 
 int /*<<< orphan*/  strcpy (char*,char*) ; 
 scalar_t__ strlen (char*) ; 
 size_t strtoul (char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

void acpi_db_add_to_history(char *command_line)
{
	u16 cmd_len;
	u16 buffer_len;

	/* Put command into the next available slot */

	cmd_len = (u16)strlen(command_line);
	if (!cmd_len) {
		return;
	}

	if (acpi_gbl_history_buffer[acpi_gbl_next_history_index].command !=
	    NULL) {
		buffer_len =
		    (u16)
		    strlen(acpi_gbl_history_buffer[acpi_gbl_next_history_index].
			   command);

		if (cmd_len > buffer_len) {
			acpi_os_free(acpi_gbl_history_buffer
				     [acpi_gbl_next_history_index].command);
			acpi_gbl_history_buffer[acpi_gbl_next_history_index].
			    command = acpi_os_allocate(cmd_len + 1);
		}
	} else {
		acpi_gbl_history_buffer[acpi_gbl_next_history_index].command =
		    acpi_os_allocate(cmd_len + 1);
	}

	strcpy(acpi_gbl_history_buffer[acpi_gbl_next_history_index].command,
	       command_line);

	acpi_gbl_history_buffer[acpi_gbl_next_history_index].cmd_num =
	    acpi_gbl_next_cmd_num;

	/* Adjust indexes */

	if ((acpi_gbl_num_history == HISTORY_SIZE) &&
	    (acpi_gbl_next_history_index == acpi_gbl_lo_history)) {
		acpi_gbl_lo_history++;
		if (acpi_gbl_lo_history >= HISTORY_SIZE) {
			acpi_gbl_lo_history = 0;
		}
	}

	acpi_gbl_next_history_index++;
	if (acpi_gbl_next_history_index >= HISTORY_SIZE) {
		acpi_gbl_next_history_index = 0;
	}

	acpi_gbl_next_cmd_num++;
	if (acpi_gbl_num_history < HISTORY_SIZE) {
		acpi_gbl_num_history++;
	}
}

void acpi_db_display_history(void)
{
	u32 i;
	u16 history_index;

	history_index = acpi_gbl_lo_history;

	/* Dump entire history buffer */

	for (i = 0; i < acpi_gbl_num_history; i++) {
		if (acpi_gbl_history_buffer[history_index].command) {
			acpi_os_printf("%3ld %s\n",
				       acpi_gbl_history_buffer[history_index].
				       cmd_num,
				       acpi_gbl_history_buffer[history_index].
				       command);
		}

		history_index++;
		if (history_index >= HISTORY_SIZE) {
			history_index = 0;
		}
	}
}

char *acpi_db_get_from_history(char *command_num_arg)
{
	u32 cmd_num;

	if (command_num_arg == NULL) {
		cmd_num = acpi_gbl_next_cmd_num - 1;
	}

	else {
		cmd_num = strtoul(command_num_arg, NULL, 0);
	}

	return (acpi_db_get_history_by_index(cmd_num));
}

char *acpi_db_get_history_by_index(u32 cmd_num)
{
	u32 i;
	u16 history_index;

	/* Search history buffer */

	history_index = acpi_gbl_lo_history;
	for (i = 0; i < acpi_gbl_num_history; i++) {
		if (acpi_gbl_history_buffer[history_index].cmd_num == cmd_num) {

			/* Found the command, return it */

			return (acpi_gbl_history_buffer[history_index].command);
		}

		/* History buffer is circular */

		history_index++;
		if (history_index >= HISTORY_SIZE) {
			history_index = 0;
		}
	}

	acpi_os_printf("Invalid history number: %u\n", history_index);
	return (NULL);
}

