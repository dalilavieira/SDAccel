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
typedef  size_t u32 ;

/* Variables and functions */
 size_t ACPI_NAME_SIZE ; 
 scalar_t__ FALSE ; 
 scalar_t__ TRUE ; 
 scalar_t__ acpi_ut_valid_name_char (char,size_t) ; 
 int /*<<< orphan*/  isprint (scalar_t__) ; 

u8 acpi_ut_valid_nameseg(char *name)
{
	u32 i;

	/* Validate each character in the signature */

	for (i = 0; i < ACPI_NAME_SIZE; i++) {
		if (!acpi_ut_valid_name_char(name[i], i)) {
			return (FALSE);
		}
	}

	return (TRUE);
}

u8 acpi_ut_valid_name_char(char character, u32 position)
{

	if (!((character >= 'A' && character <= 'Z') ||
	      (character >= '0' && character <= '9') || (character == '_'))) {

		/* Allow a '!' in the last position */

		if (character == '!' && position == 3) {
			return (TRUE);
		}

		return (FALSE);
	}

	return (TRUE);
}

void acpi_ut_check_and_repair_ascii(u8 *name, char *repaired_name, u32 count)
{
	u32 i;

	for (i = 0; i < count; i++) {
		repaired_name[i] = (char)name[i];

		if (!name[i]) {
			return;
		}
		if (!isprint(name[i])) {
			repaired_name[i] = ' ';
		}
	}
}

