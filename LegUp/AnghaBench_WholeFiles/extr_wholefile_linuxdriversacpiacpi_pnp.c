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
struct acpi_device_id {char* member_0; scalar_t__* id; } ;
struct acpi_device {int /*<<< orphan*/ * handler; } ;

/* Variables and functions */
 int /*<<< orphan*/  acpi_match_device_ids (struct acpi_device*,struct acpi_device_id const*) ; 
 struct acpi_device_id* acpi_pnp_device_ids ; 
 int /*<<< orphan*/  acpi_pnp_handler ; 
 int /*<<< orphan*/  isxdigit (char) ; 
 scalar_t__ memcmp (char const*,char const*,int) ; 
 char toupper (char const) ; 

__attribute__((used)) static bool matching_id(const char *idstr, const char *list_id)
{
	int i;

	if (memcmp(idstr, list_id, 3))
		return false;

	for (i = 3; i < 7; i++) {
		char c = toupper(idstr[i]);

		if (!isxdigit(c)
		    || (list_id[i] != 'X' && c != toupper(list_id[i])))
			return false;
	}
	return true;
}

__attribute__((used)) static bool acpi_pnp_match(const char *idstr, const struct acpi_device_id **matchid)
{
	const struct acpi_device_id *devid;

	for (devid = acpi_pnp_device_ids; devid->id[0]; devid++)
		if (matching_id(idstr, (char *)devid->id)) {
			if (matchid)
				*matchid = devid;

			return true;
		}

	return false;
}

__attribute__((used)) static int acpi_pnp_attach(struct acpi_device *adev,
			   const struct acpi_device_id *id)
{
	return 1;
}

__attribute__((used)) static int is_cmos_rtc_device(struct acpi_device *adev)
{
	static const struct acpi_device_id ids[] = {
		{ "PNP0B00" },
		{ "PNP0B01" },
		{ "PNP0B02" },
		{""},
	};
	return !acpi_match_device_ids(adev, ids);
}

bool acpi_is_pnp_device(struct acpi_device *adev)
{
	return adev->handler == &acpi_pnp_handler || is_cmos_rtc_device(adev);
}

