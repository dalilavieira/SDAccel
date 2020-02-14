#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  regproc ;
typedef  scalar_t__ int64 ;
struct TYPE_6__ {TYPE_1__* tables; } ;
struct TYPE_5__ {int /*<<< orphan*/ * index_ids; int /*<<< orphan*/  id; } ;
typedef  int /*<<< orphan*/  Oid ;
typedef  int /*<<< orphan*/  Name ;
typedef  int /*<<< orphan*/  DimensionInfo ;
typedef  size_t CatalogTable ;
typedef  TYPE_2__ Catalog ;

/* Variables and functions */
 int /*<<< orphan*/  DefineCustomBoolVariable (char*,char*,char*,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  DefineCustomEnumVariable (char*,char*,char*,scalar_t__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  DefineCustomIntVariable (char*,char*,char*,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,...) ; 
 int /*<<< orphan*/  DefineCustomStringVariable (char*,char*,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  GUC_SUPERUSER_ONLY ; 
 int INT64CONST (int) ; 
 int /*<<< orphan*/  INT8OID ; 
 int INVALID_INDEXID ; 
 int /*<<< orphan*/  Int64GetDatum (scalar_t__) ; 
 int /*<<< orphan*/  InvalidOid ; 
 int Min (int,int) ; 
 int /*<<< orphan*/  PGC_SIGHUP ; 
 int /*<<< orphan*/  PGC_SUSET ; 
 int /*<<< orphan*/  PGC_USERSET ; 
 int PG_INT16_MAX ; 
 int /*<<< orphan*/  TELEMETRY_BASIC ; 
 int /*<<< orphan*/ * TS_DEFAULT_LICENSE ; 
 scalar_t__ on_level ; 
 int /*<<< orphan*/  telemetry_level_options ; 
 int /*<<< orphan*/ * ts_dimension_info_create_open (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ts_guc_constraint_aware_append ; 
 int /*<<< orphan*/  ts_guc_disable_optimizations ; 
 int /*<<< orphan*/  ts_guc_enable_constraint_exclusion ; 
 int /*<<< orphan*/  ts_guc_enable_ordered_append ; 
 int /*<<< orphan*/  ts_guc_license_key ; 
 int /*<<< orphan*/  ts_guc_max_cached_chunks_per_hypertable ; 
 int /*<<< orphan*/  ts_guc_max_open_chunks_per_insert ; 
 int /*<<< orphan*/  ts_guc_optimize_non_hypertables ; 
 int /*<<< orphan*/  ts_guc_restoring ; 
 scalar_t__ ts_guc_telemetry_level ; 
 int /*<<< orphan*/  ts_hypertable_cache_invalidate_callback () ; 
 int /*<<< orphan*/  ts_last_tune_time ; 
 int /*<<< orphan*/  ts_last_tune_version ; 
 int /*<<< orphan*/ * ts_license_on_assign ; 
 int /*<<< orphan*/ * ts_license_update_check ; 
 int /*<<< orphan*/  ts_telemetry_cloud ; 
 int work_mem ; 

__attribute__((used)) static inline int64
int64_min(int64 a, int64 b)
{
	if (a <= b)
		return a;
	return b;
}

__attribute__((used)) static inline Oid
catalog_get_table_id(Catalog *catalog, CatalogTable tableid)
{
	return catalog->tables[tableid].id;
}

__attribute__((used)) static inline Oid
catalog_get_index(Catalog *catalog, CatalogTable tableid, int indexid)
{
	return (indexid == INVALID_INDEXID) ? InvalidOid : catalog->tables[tableid].index_ids[indexid];
}

__attribute__((used)) static inline DimensionInfo *
ts_dimension_info_create_open_interval_usec(Oid table_relid, Name column_name, int64 interval_usec,
											regproc partitioning_func)
{
	return ts_dimension_info_create_open(table_relid,
										 column_name,
										 Int64GetDatum(interval_usec),
										 INT8OID,
										 partitioning_func);
}

bool
ts_telemetry_on()
{
	return ts_guc_telemetry_level == on_level;
}

__attribute__((used)) static void
assign_max_cached_chunks_per_hypertable_hook(int newval, void *extra)
{
	/* invalidate the hypertable cache to reset */
	ts_hypertable_cache_invalidate_callback();
}

void
_guc_init(void)
{
	/* Main database to connect to. */
	DefineCustomBoolVariable("timescaledb.disable_optimizations",
							 "Disable all timescale query optimizations",
							 NULL,
							 &ts_guc_disable_optimizations,
							 false,
							 PGC_USERSET,
							 0,
							 NULL,
							 NULL,
							 NULL);
	DefineCustomBoolVariable("timescaledb.optimize_non_hypertables",
							 "Apply timescale query optimization to plain tables",
							 "Apply timescale query optimization to plain tables in addition to "
							 "hypertables",
							 &ts_guc_optimize_non_hypertables,
							 false,
							 PGC_USERSET,
							 0,
							 NULL,
							 NULL,
							 NULL);

	DefineCustomBoolVariable("timescaledb.restoring",
							 "Install timescale in restoring mode",
							 "Used for running pg_restore",
							 &ts_guc_restoring,
							 false,
							 PGC_SUSET,
							 0,
							 NULL,
							 NULL,
							 NULL);

	DefineCustomBoolVariable("timescaledb.constraint_aware_append",
							 "Enable constraint-aware append scans",
							 "Enable constraint exclusion at execution time",
							 &ts_guc_constraint_aware_append,
							 true,
							 PGC_USERSET,
							 0,
							 NULL,
							 NULL,
							 NULL);

	DefineCustomBoolVariable("timescaledb.enable_ordered_append",
							 "Enable ordered append scans",
							 "Enable ordered append optimization for queries that are ordered by "
							 "the time dimension",
							 &ts_guc_enable_ordered_append,
							 true,
							 PGC_USERSET,
							 0,
							 NULL,
							 NULL,
							 NULL);

	DefineCustomBoolVariable("timescaledb.enable_constraint_exclusion",
							 "Enable constraint exclusion",
							 "Enable planner constraint exclusion",
							 &ts_guc_enable_constraint_exclusion,
							 true,
							 PGC_USERSET,
							 0,
							 NULL,
							 NULL,
							 NULL);

	DefineCustomIntVariable("timescaledb.max_open_chunks_per_insert",
							"Maximum open chunks per insert",
							"Maximum number of open chunk tables per insert",
							&ts_guc_max_open_chunks_per_insert,
							Min(work_mem * INT64CONST(1024) / INT64CONST(25000),
								PG_INT16_MAX), /* Measurements via
												* `MemoryContextStats(TopMemoryContext)`
												* show chunk insert
												* state memory context
												* takes up ~25K bytes
												* (work_mem is in
												* kbytes) */
							0,
							PG_INT16_MAX,
							PGC_USERSET,
							0,
							NULL,
							NULL,
							NULL);

	DefineCustomIntVariable("timescaledb.max_cached_chunks_per_hypertable",
							"Maximum cached chunks",
							"Maximum number of chunks stored in the cache",
							&ts_guc_max_cached_chunks_per_hypertable,
							100,
							0,
							65536,
							PGC_USERSET,
							0,
							NULL,
							assign_max_cached_chunks_per_hypertable_hook,
							NULL);
	DefineCustomEnumVariable("timescaledb.telemetry_level",
							 "Telemetry settings level",
							 "Level used to determine which telemetry to send",
							 &ts_guc_telemetry_level,
							 TELEMETRY_BASIC,
							 telemetry_level_options,
							 PGC_USERSET,
							 0,
							 NULL,
							 NULL,
							 NULL);

	DefineCustomStringVariable(/* name= */ "timescaledb.license_key",
							   /* short_dec= */ "TimescaleDB license key",
							   /* long_dec= */ "Determines which features are enabled",
							   /* valueAddr= */ &ts_guc_license_key,
							   /* bootValue= */ TS_DEFAULT_LICENSE,
							   /* context= */ PGC_SUSET,
							   /* flags= */ GUC_SUPERUSER_ONLY,
							   /* check_hook= */ ts_license_update_check,
							   /* assign_hook= */ ts_license_on_assign,
							   /* show_hook= */ NULL);

	DefineCustomStringVariable(/* name= */ "timescaledb.last_tuned",
							   /* short_dec= */ "last tune run",
							   /* long_dec= */ "records last time timescaledb-tune ran",
							   /* valueAddr= */ &ts_last_tune_time,
							   /* bootValue= */ NULL,
							   /* context= */ PGC_SIGHUP,
							   /* flags= */ 0,
							   /* check_hook= */ NULL,
							   /* assign_hook= */ NULL,
							   /* show_hook= */ NULL);

	DefineCustomStringVariable(/* name= */ "timescaledb.last_tuned_version",
							   /* short_dec= */ "version of timescaledb-tune",
							   /* long_dec= */ "version of timescaledb-tune used to tune",
							   /* valueAddr= */ &ts_last_tune_version,
							   /* bootValue= */ NULL,
							   /* context= */ PGC_SIGHUP,
							   /* flags= */ 0,
							   /* check_hook= */ NULL,
							   /* assign_hook= */ NULL,
							   /* show_hook= */ NULL);

	DefineCustomStringVariable(/* name= */ "timescaledb_telemetry.cloud",
							   /* short_dec= */ "cloud provider",
							   /* long_dec= */ "cloud provider used for this instance",
							   /* valueAddr= */ &ts_telemetry_cloud,
							   /* bootValue= */ NULL,
							   /* context= */ PGC_SIGHUP,
							   /* flags= */ 0,
							   /* check_hook= */ NULL,
							   /* assign_hook= */ NULL,
							   /* show_hook= */ NULL);

#ifdef TS_DEBUG
	DefineCustomBoolVariable(/* name= */ "timescaledb.shutdown_bgw_scheduler",
							 /* short_dec= */ "immediately shutdown the bgw scheduler",
							 /* long_dec= */ "this is for debugging purposes",
							 /* valueAddr= */ &ts_shutdown_bgw,
							 /* bootValue= */ false,
							 /* context= */ PGC_SIGHUP,
							 /* flags= */ 0,
							 /* check_hook= */ NULL,
							 /* assign_hook= */ NULL,
							 /* show_hook= */ NULL);
#endif
}

void
_guc_fini(void)
{
}

