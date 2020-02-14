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
typedef  int /*<<< orphan*/  kauth_cred_t ;

/* Variables and functions */
 int /*<<< orphan*/  MAC_CHECK (int /*<<< orphan*/ ,int /*<<< orphan*/ ,...) ; 
 int /*<<< orphan*/  kext_check_load ; 
 int /*<<< orphan*/  kext_check_query ; 
 int /*<<< orphan*/  kext_check_unload ; 

int
mac_kext_check_load(kauth_cred_t cred, const char *identifier) {
	int error;

	MAC_CHECK(kext_check_load, cred, identifier);

	return (error);
}

int
mac_kext_check_unload(kauth_cred_t cred, const char *identifier) {
	int error;

	MAC_CHECK(kext_check_unload, cred, identifier);

	return (error);
}

int
mac_kext_check_query(kauth_cred_t cred) {
	int error;

	MAC_CHECK(kext_check_query, cred);

	return (error);
}

