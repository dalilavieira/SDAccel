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

/* Variables and functions */
 int /*<<< orphan*/  ACPI_FUNCTION_ENTRY () ; 
 int tolower (int) ; 
 scalar_t__ toupper (int) ; 

void acpi_ut_strlwr(char *src_string)
{
	char *string;

	ACPI_FUNCTION_ENTRY();

	if (!src_string) {
		return;
	}

	/* Walk entire string, lowercasing the letters */

	for (string = src_string; *string; string++) {
		*string = (char)tolower((int)*string);
	}
}

void acpi_ut_strupr(char *src_string)
{
	char *string;

	ACPI_FUNCTION_ENTRY();

	if (!src_string) {
		return;
	}

	/* Walk entire string, uppercasing the letters */

	for (string = src_string; *string; string++) {
		*string = (char)toupper((int)*string);
	}
}

int acpi_ut_stricmp(char *string1, char *string2)
{
	int c1;
	int c2;

	do {
		c1 = tolower((int)*string1);
		c2 = tolower((int)*string2);

		string1++;
		string2++;
	}
	while ((c1 == c2) && (c1));

	return (c1 - c2);
}

