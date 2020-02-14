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
typedef  enum ExtensionState { ____Placeholder_ExtensionState } ExtensionState ;
typedef  int /*<<< orphan*/  SysScanDesc ;
typedef  int /*<<< orphan*/  ScanKeyData ;
typedef  int /*<<< orphan*/  Relation ;
typedef  int /*<<< orphan*/  HeapTuple ;
typedef  int /*<<< orphan*/  Datum ;

/* Variables and functions */
 int /*<<< orphan*/  AccessShareLock ; 
 int /*<<< orphan*/  Anum_pg_extension_extname ; 
 int /*<<< orphan*/  Anum_pg_extension_extversion ; 
 int /*<<< orphan*/  Assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BTEqualStrategyNumber ; 
 int /*<<< orphan*/  CStringGetDatum (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DEFAULT_ROLE_READ_ALL_SETTINGS ; 
 int /*<<< orphan*/  DirectFunctionCall1 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ERROR ; 
 int /*<<< orphan*/  EXTENSION_NAME ; 
 int EXTENSION_STATE_CREATED ; 
 int EXTENSION_STATE_NOT_INSTALLED ; 
 int EXTENSION_STATE_TRANSITIONING ; 
 int EXTENSION_STATE_UNKNOWN ; 
 int /*<<< orphan*/  ExtensionNameIndexId ; 
 int /*<<< orphan*/  ExtensionRelationId ; 
 int /*<<< orphan*/  FATAL ; 
 int /*<<< orphan*/  F_NAMEEQ ; 
 char* GetConfigOptionByName (char*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  GetUserId () ; 
 scalar_t__ HeapTupleIsValid (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IsNormalProcessingMode () ; 
 int /*<<< orphan*/  IsTransactionState () ; 
 int /*<<< orphan*/  RelationGetDescr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ScanKeyInit (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TextDatumGetCString (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  elog (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  ereport (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  errhint (char*,...) ; 
 int /*<<< orphan*/  errmsg (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  extension_exists () ; 
 scalar_t__ extension_is_transitioning () ; 
 int /*<<< orphan*/  heap_close (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  heap_getattr (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  heap_open (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ is_member_of_role (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  namein ; 
 scalar_t__ proxy_table_exists () ; 
 char* pstrdup (int /*<<< orphan*/ ) ; 
 scalar_t__ strcmp (char*,char*) ; 
 int /*<<< orphan*/  systable_beginscan (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  systable_endscan (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  systable_getnext (int /*<<< orphan*/ ) ; 

__attribute__((used)) static char *
extension_version(void)
{
	Datum result;
	Relation rel;
	SysScanDesc scandesc;
	HeapTuple tuple;
	ScanKeyData entry[1];
	bool is_null = true;
	char *sql_version = NULL;

	rel = heap_open(ExtensionRelationId, AccessShareLock);

	ScanKeyInit(&entry[0],
				Anum_pg_extension_extname,
				BTEqualStrategyNumber,
				F_NAMEEQ,
				DirectFunctionCall1(namein, CStringGetDatum(EXTENSION_NAME)));

	scandesc = systable_beginscan(rel, ExtensionNameIndexId, true, NULL, 1, entry);

	tuple = systable_getnext(scandesc);

	/* We assume that there can be at most one matching tuple */
	if (HeapTupleIsValid(tuple))
	{
		result = heap_getattr(tuple, Anum_pg_extension_extversion, RelationGetDescr(rel), &is_null);

		if (!is_null)
		{
			sql_version = pstrdup(TextDatumGetCString(result));
		}
	}

	systable_endscan(scandesc);
	heap_close(rel, AccessShareLock);

	if (sql_version == NULL)
	{
		elog(ERROR, "extension not found while getting version");
	}
	return sql_version;
}

__attribute__((used)) static enum ExtensionState
extension_current_state()
{
	/*
	 * NormalProcessingMode necessary to avoid accessing cache before its
	 * ready (which may result in an infinite loop). More concretely we need
	 * RelationCacheInitializePhase3 to have been already called.
	 */
	if (!IsNormalProcessingMode() || !IsTransactionState())
		return EXTENSION_STATE_UNKNOWN;

	/*
	 * NOTE: do not check for proxy_table_exists here. Want to be in
	 * TRANSITIONING state even before the proxy table is created
	 */
	if (extension_is_transitioning())
		return EXTENSION_STATE_TRANSITIONING;

	/*
	 * proxy_table_exists uses syscache. Must come first. NOTE: during DROP
	 * EXTENSION proxy_table_exists() will return false right away, while
	 * extension_exists will return true until the end of the command
	 */
	if (proxy_table_exists())
	{
		Assert(extension_exists());
		return EXTENSION_STATE_CREATED;
	}

	return EXTENSION_STATE_NOT_INSTALLED;
}

__attribute__((used)) static void
extension_load_without_preload()
{
	/* cannot use GUC variable here since extension not yet loaded */
	char *allow_install_without_preload =
		GetConfigOptionByName("timescaledb.allow_install_without_preload", NULL, true);

	if (allow_install_without_preload == NULL || strcmp(allow_install_without_preload, "on") != 0)
	{
		/*
		 * These are FATAL because otherwise the loader ends up in a weird
		 * half-loaded state after an ERROR
		 */
		/* Only privileged users can get the value of `config file` */

#if PG96
		if (superuser())
#else
		if (is_member_of_role(GetUserId(), DEFAULT_ROLE_READ_ALL_SETTINGS))
#endif
		{
			char *config_file = GetConfigOptionByName("config_file", NULL, false);

			ereport(FATAL,
					(errmsg("extension \"%s\" must be preloaded", EXTENSION_NAME),
					 errhint("Please preload the timescaledb library via "
							 "shared_preload_libraries.\n\n"
							 "This can be done by editing the config file at: %1$s\n"
							 "and adding 'timescaledb' to the list in the shared_preload_libraries "
							 "config.\n"
							 "	# Modify postgresql.conf:\n	shared_preload_libraries = "
							 "'timescaledb'\n\n"
							 "Another way to do this, if not preloading other libraries, is with "
							 "the command:\n"
							 "	echo \"shared_preload_libraries = 'timescaledb'\" >> %1$s \n\n"
							 "(Will require a database restart.)\n\n"
							 "If you REALLY know what you are doing and would like to load the "
							 "library without preloading, you can disable this check with: \n"
							 "	SET timescaledb.allow_install_without_preload = 'on';",
							 config_file)));
		}
		else
		{
			ereport(FATAL,
					(errmsg("extension \"%s\" must be preloaded", EXTENSION_NAME),
					 errhint(
						 "Please preload the timescaledb library via shared_preload_libraries.\n\n"
						 "This can be done by editing the postgres config file \n"
						 "and adding 'timescaledb' to the list in the shared_preload_libraries "
						 "config.\n"
						 "	# Modify postgresql.conf:\n	shared_preload_libraries = "
						 "'timescaledb'\n\n"
						 "Another way to do this, if not preloading other libraries, is with the "
						 "command:\n"
						 "	echo \"shared_preload_libraries = 'timescaledb'\" >> "
						 "/path/to/config/file \n\n"
						 "(Will require a database restart.)\n\n"
						 "If you REALLY know what you are doing and would like to load the library "
						 "without preloading, you can disable this check with: \n"
						 "	SET timescaledb.allow_install_without_preload = 'on';")));
		}

		return;
	}
}

