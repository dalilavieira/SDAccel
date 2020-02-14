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
struct TYPE_2__ {int expected_btypes; scalar_t__* name; } ;
union acpi_predefined_info {TYPE_1__ info; } ;
typedef  int u32 ;

/* Variables and functions */
 scalar_t__ ACPI_COMPARE_NAME (char*,scalar_t__*) ; 
 int ACPI_NUM_RTYPES ; 
 int ACPI_RTYPE_ALL ; 
 int ACPI_RTYPE_INTEGER ; 
 int ACPI_RTYPE_PACKAGE ; 
 union acpi_predefined_info* acpi_gbl_predefined_methods ; 
 int /*<<< orphan*/  strcat (char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  strcpy (char*,char*) ; 
 int /*<<< orphan*/ ** ut_rtype_names ; 

const union acpi_predefined_info *acpi_ut_get_next_predefined_method(const union
								     acpi_predefined_info
								     *this_name)
{

	/*
	 * Skip next entry in the table if this name returns a Package
	 * (next entry contains the package info)
	 */
	if ((this_name->info.expected_btypes & ACPI_RTYPE_PACKAGE) &&
	    (this_name->info.expected_btypes != ACPI_RTYPE_ALL)) {
		this_name++;
	}

	this_name++;
	return (this_name);
}

const union acpi_predefined_info *acpi_ut_match_predefined_method(char *name)
{
	const union acpi_predefined_info *this_name;

	/* Quick check for a predefined name, first character must be underscore */

	if (name[0] != '_') {
		return (NULL);
	}

	/* Search info table for a predefined method/object name */

	this_name = acpi_gbl_predefined_methods;
	while (this_name->info.name[0]) {
		if (ACPI_COMPARE_NAME(name, this_name->info.name)) {
			return (this_name);
		}

		this_name = acpi_ut_get_next_predefined_method(this_name);
	}

	return (NULL);		/* Not found */
}

void acpi_ut_get_expected_return_types(char *buffer, u32 expected_btypes)
{
	u32 this_rtype;
	u32 i;
	u32 j;

	if (!expected_btypes) {
		strcpy(buffer, "NONE");
		return;
	}

	j = 1;
	buffer[0] = 0;
	this_rtype = ACPI_RTYPE_INTEGER;

	for (i = 0; i < ACPI_NUM_RTYPES; i++) {

		/* If one of the expected types, concatenate the name of this type */

		if (expected_btypes & this_rtype) {
			strcat(buffer, &ut_rtype_names[i][j]);
			j = 0;	/* Use name separator from now on */
		}

		this_rtype <<= 1;	/* Next Rtype */
	}
}

