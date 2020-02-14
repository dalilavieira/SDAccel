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
struct mac_module_data {int dummy; } ;
typedef  int /*<<< orphan*/  kauth_cred_t ;
typedef  int /*<<< orphan*/  io_object_t ;

/* Variables and functions */
 int /*<<< orphan*/  MAC_CHECK (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  iokit_check_device ; 
 int /*<<< orphan*/  iokit_check_filter_properties ; 
 int /*<<< orphan*/  iokit_check_get_property ; 
 int /*<<< orphan*/  iokit_check_hid_control ; 
 int /*<<< orphan*/  iokit_check_open ; 
 int /*<<< orphan*/  iokit_check_set_properties ; 

int
mac_iokit_check_device(char *devtype, struct mac_module_data *mdata)
{
	int error;

	MAC_CHECK(iokit_check_device, devtype, mdata);
	return (error);
}

int
mac_iokit_check_open(kauth_cred_t cred, io_object_t user_client, unsigned int user_client_type)
{
	int error;

	MAC_CHECK(iokit_check_open, cred, user_client, user_client_type);
	return (error);
}

int
mac_iokit_check_set_properties(kauth_cred_t cred, io_object_t registry_entry, io_object_t properties)
{
	int error;

	MAC_CHECK(iokit_check_set_properties, cred, registry_entry, properties);
	return (error);
}

int
mac_iokit_check_filter_properties(kauth_cred_t cred, io_object_t registry_entry)
{
	int error;

	MAC_CHECK(iokit_check_filter_properties, cred, registry_entry);
	return (error);
}

int
mac_iokit_check_get_property(kauth_cred_t cred, io_object_t registry_entry, const char *name)
{
	int error;

	MAC_CHECK(iokit_check_get_property, cred, registry_entry, name);
	return (error);
}

int
mac_iokit_check_hid_control(kauth_cred_t cred)
{
	int error;

	MAC_CHECK(iokit_check_hid_control, cred);
	return (error);
}

