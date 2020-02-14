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
typedef  scalar_t__ int64 ;
struct TYPE_6__ {TYPE_1__* tables; } ;
struct TYPE_5__ {int /*<<< orphan*/ * index_ids; int /*<<< orphan*/  id; } ;
typedef  int /*<<< orphan*/  Oid ;
typedef  size_t CatalogTable ;
typedef  TYPE_2__ Catalog ;

/* Variables and functions */
 int INVALID_INDEXID ; 
 int /*<<< orphan*/  InvalidOid ; 
 int /*<<< orphan*/  TIMESCALEDB_VERSION_MOD ; 
 int /*<<< orphan*/  _cache_fini () ; 
 int /*<<< orphan*/  _cache_init () ; 
 int /*<<< orphan*/  _cache_invalidate_fini () ; 
 int /*<<< orphan*/  _cache_invalidate_init () ; 
 int /*<<< orphan*/  _conn_plain_fini () ; 
 int /*<<< orphan*/  _conn_plain_init () ; 
 int /*<<< orphan*/  _constraint_aware_append_init () ; 
 int /*<<< orphan*/  _event_trigger_fini () ; 
 int /*<<< orphan*/  _event_trigger_init () ; 
 int /*<<< orphan*/  _guc_fini () ; 
 int /*<<< orphan*/  _guc_init () ; 
 int /*<<< orphan*/  _hypertable_cache_fini () ; 
 int /*<<< orphan*/  _hypertable_cache_init () ; 
 int /*<<< orphan*/  _planner_fini () ; 
 int /*<<< orphan*/  _planner_init () ; 
 int /*<<< orphan*/  _process_utility_fini () ; 
 int /*<<< orphan*/  _process_utility_init () ; 
 int /*<<< orphan*/  ts_bgw_check_loader_api_version () ; 
 int /*<<< orphan*/  ts_extension_check_server_version () ; 
 int /*<<< orphan*/  ts_extension_check_version (int /*<<< orphan*/ ) ; 

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

void
_PG_init(void)
{
	/*
	 * Check extension_is loaded to catch certain errors such as calls to
	 * functions defined on the wrong extension version
	 */
	ts_extension_check_version(TIMESCALEDB_VERSION_MOD);
	ts_extension_check_server_version();
	ts_bgw_check_loader_api_version();

	_cache_init();
	_hypertable_cache_init();
	_cache_invalidate_init();
	_planner_init();
	_constraint_aware_append_init();
	_event_trigger_init();
	_process_utility_init();
	_guc_init();
	_conn_plain_init();
#ifdef TS_USE_OPENSSL
	_conn_ssl_init();
#endif
#ifdef TS_DEBUG
	_conn_mock_init();
#endif
}

void
_PG_fini(void)
{
	/*
	 * Order of items should be strict reverse order of _PG_init. Please
	 * document any exceptions.
	 */
#ifdef TS_DEBUG
	_conn_mock_fini();
#endif
#ifdef TS_USE_OPENSSL
	_conn_ssl_fini();
#endif
	_conn_plain_fini();
	_guc_fini();
	_process_utility_fini();
	_event_trigger_fini();
	_planner_fini();
	_cache_invalidate_fini();
	_hypertable_cache_fini();
	_cache_fini();
}

