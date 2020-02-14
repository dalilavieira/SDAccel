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
typedef  int int32 ;
typedef  int /*<<< orphan*/  PGFunction ;

/* Variables and functions */
 int /*<<< orphan*/  BoolGetDatum (int) ; 
 int DatumGetBool (int /*<<< orphan*/ ) ; 
 int DatumGetInt32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DirectFunctionCall1 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ERRCODE_FEATURE_NOT_SUPPORTED ; 
 int /*<<< orphan*/  ERROR ; 
 int /*<<< orphan*/  EXTENSION_SO ; 
 int MIN_LOADER_API_VERSION ; 
 int /*<<< orphan*/  RENDEZVOUS_BGW_LOADER_API_VERSION ; 
 int /*<<< orphan*/  ereport (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  errcode (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  errhint (char*) ; 
 int /*<<< orphan*/  errmsg (char*) ; 
 void** find_rendezvous_variable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  load_external_function (int /*<<< orphan*/ ,char*,int,int /*<<< orphan*/ *) ; 

extern bool
ts_bgw_worker_reserve(void)
{
	PGFunction reserve = load_external_function(EXTENSION_SO, "ts_bgw_worker_reserve", true, NULL);

	return DatumGetBool(
		DirectFunctionCall1(reserve, BoolGetDatum(false))); /* no function call zero */
}

extern void
ts_bgw_worker_release(void)
{
	PGFunction release = load_external_function(EXTENSION_SO, "ts_bgw_worker_release", true, NULL);

	DirectFunctionCall1(release, BoolGetDatum(false)); /* no function call zero */
}

extern int
ts_bgw_num_unreserved(void)
{
	PGFunction unreserved =
		load_external_function(EXTENSION_SO, "ts_bgw_num_unreserved", true, NULL);

	return DatumGetInt32(
		DirectFunctionCall1(unreserved, BoolGetDatum(false))); /* no function call zero */
}

extern int
ts_bgw_loader_api_version(void)
{
	void **versionptr = find_rendezvous_variable(RENDEZVOUS_BGW_LOADER_API_VERSION);

	if (*versionptr == NULL)
		return 0;
	return *((int32 *) *versionptr);
}

extern void
ts_bgw_check_loader_api_version()
{
	int version = ts_bgw_loader_api_version();

	if (version < MIN_LOADER_API_VERSION)
		ereport(ERROR,
				(errcode(ERRCODE_FEATURE_NOT_SUPPORTED),
				 errmsg("loader version out-of-date"),
				 errhint("Please restart the database to upgrade the loader version.")));
}

