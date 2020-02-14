#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_41__   TYPE_9__ ;
typedef  struct TYPE_40__   TYPE_8__ ;
typedef  struct TYPE_39__   TYPE_7__ ;
typedef  struct TYPE_38__   TYPE_6__ ;
typedef  struct TYPE_37__   TYPE_5__ ;
typedef  struct TYPE_36__   TYPE_4__ ;
typedef  struct TYPE_35__   TYPE_3__ ;
typedef  struct TYPE_34__   TYPE_2__ ;
typedef  struct TYPE_33__   TYPE_24__ ;
typedef  struct TYPE_32__   TYPE_1__ ;
typedef  struct TYPE_31__   TYPE_17__ ;
typedef  struct TYPE_30__   TYPE_16__ ;

/* Type definitions */
typedef  scalar_t__ int64 ;
struct TYPE_35__ {int /*<<< orphan*/  schema_name; int /*<<< orphan*/  table_name; } ;
typedef  TYPE_3__ TableInfoDef ;
struct TYPE_36__ {scalar_t__ length; int /*<<< orphan*/ * names; } ;
typedef  TYPE_4__ TableIndexDef ;
struct TYPE_41__ {TYPE_2__* caches; TYPE_1__* tables; scalar_t__ initialized; } ;
struct TYPE_40__ {scalar_t__ schema_id; scalar_t__ owner_uid; int /*<<< orphan*/  database_name; int /*<<< orphan*/  database_id; } ;
struct TYPE_39__ {scalar_t__ serial_relid; int /*<<< orphan*/  schema_name; int /*<<< orphan*/  name; scalar_t__* index_ids; scalar_t__ id; } ;
struct TYPE_38__ {scalar_t__ nspowner; } ;
struct TYPE_37__ {int /*<<< orphan*/  t_self; } ;
struct TYPE_34__ {scalar_t__ inval_proxy_id; } ;
struct TYPE_33__ {int initialized; } ;
struct TYPE_32__ {scalar_t__ id; scalar_t__* index_ids; } ;
struct TYPE_31__ {char const* table_name; char const* schema_name; } ;
struct TYPE_30__ {scalar_t__ database_id; } ;
typedef  scalar_t__ Size ;
typedef  int /*<<< orphan*/  Relation ;
typedef  int /*<<< orphan*/  RangeVar ;
typedef  scalar_t__ Oid ;
typedef  int /*<<< orphan*/ * ItemPointer ;
typedef  TYPE_5__* HeapTuple ;
typedef  TYPE_6__* Form_pg_namespace ;
typedef  int /*<<< orphan*/  CmdType ;
typedef  TYPE_7__ CatalogTableInfo ;
typedef  size_t CatalogTable ;
typedef  TYPE_8__ CatalogDatabaseInfo ;
typedef  TYPE_9__ Catalog ;
typedef  size_t CacheType ;

/* Variables and functions */
 int /*<<< orphan*/  Assert (int) ; 
#define  BGW_JOB 134 
 int /*<<< orphan*/  CACHE_SCHEMA_NAME ; 
 size_t CACHE_TYPE_BGW_JOB ; 
 size_t CACHE_TYPE_HYPERTABLE ; 
 int /*<<< orphan*/  CATALOG_SCHEMA_NAME ; 
#define  CHUNK 133 
#define  CHUNK_CONSTRAINT 132 
#define  CHUNK_INDEX 131 
 int /*<<< orphan*/  CMD_DELETE ; 
 int /*<<< orphan*/  CMD_INSERT ; 
 int /*<<< orphan*/  CMD_UPDATE ; 
 int /*<<< orphan*/  CacheInvalidateRelcacheByRelid (scalar_t__) ; 
 int /*<<< orphan*/  CatalogTupleDelete (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  CatalogTupleInsert (int /*<<< orphan*/ ,TYPE_5__*) ; 
 int /*<<< orphan*/  CommandCounterIncrement () ; 
#define  DIMENSION 130 
#define  DIMENSION_SLICE 129 
 int /*<<< orphan*/  ERRCODE_UNDEFINED_SCHEMA ; 
 int /*<<< orphan*/  ERROR ; 
 scalar_t__ GETSTRUCT (TYPE_5__*) ; 
#define  HYPERTABLE 128 
 int /*<<< orphan*/  HeapTupleIsValid (TYPE_5__*) ; 
 size_t INVALID_CATALOG_TABLE ; 
 int INVALID_INDEXID ; 
 scalar_t__ InvalidOid ; 
 int /*<<< orphan*/  IsTransactionState () ; 
 int /*<<< orphan*/  MyDatabaseId ; 
 int /*<<< orphan*/  NAMEDATALEN ; 
 int /*<<< orphan*/  NAMESPACEOID ; 
 int /*<<< orphan*/  NoLock ; 
 int /*<<< orphan*/  ObjectIdGetDatum (scalar_t__) ; 
 int /*<<< orphan*/  OidIsValid (scalar_t__) ; 
 scalar_t__ RangeVarGetRelid (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 scalar_t__ RelationGetRelid (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ReleaseSysCache (TYPE_5__*) ; 
 TYPE_5__* SearchSysCache1 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  StrNCpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 unsigned int _MAX_CATALOG_TABLES ; 
 scalar_t__ _MAX_TABLE_INDEXES ; 
 int /*<<< orphan*/ * cache_proxy_table_names ; 
 TYPE_24__ catalog ; 
 TYPE_17__* catalog_table_names ; 
 TYPE_16__ database_info ; 
 int /*<<< orphan*/  elog (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,...) ; 
 int /*<<< orphan*/  ereport (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  errcode (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  errmsg (char*,scalar_t__) ; 
 int /*<<< orphan*/  get_database_name (int /*<<< orphan*/ ) ; 
 char* get_namespace_name (int /*<<< orphan*/ ) ; 
 void* get_namespace_oid (int /*<<< orphan*/ ,int) ; 
 char* get_rel_name (scalar_t__) ; 
 int /*<<< orphan*/  get_rel_namespace (scalar_t__) ; 
 scalar_t__ get_relname_relid (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/ * makeRangeVarFromNameList (int /*<<< orphan*/ ) ; 
 scalar_t__ strcmp (char const*,char const*) ; 
 int /*<<< orphan*/  stringToQualifiedNameList (char const*) ; 
 TYPE_9__* ts_catalog_get () ; 
 void ts_catalog_invalidate_cache (scalar_t__,int /*<<< orphan*/ ) ; 

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

__attribute__((used)) static bool
catalog_is_valid(Catalog *catalog)
{
	return catalog != NULL && catalog->initialized;
}

__attribute__((used)) static Oid
catalog_owner(void)
{
	HeapTuple tuple;
	Oid owner_oid;
	Oid nsp_oid = get_namespace_oid(CATALOG_SCHEMA_NAME, false);

	tuple = SearchSysCache1(NAMESPACEOID, ObjectIdGetDatum(nsp_oid));

	if (!HeapTupleIsValid(tuple))
		ereport(ERROR,
				(errcode(ERRCODE_UNDEFINED_SCHEMA),
				 errmsg("schema with OID %u does not exist", nsp_oid)));

	owner_oid = ((Form_pg_namespace) GETSTRUCT(tuple))->nspowner;

	ReleaseSysCache(tuple);

	return owner_oid;
}

__attribute__((used)) static const char *
catalog_table_name(CatalogTable table)
{
	return catalog_table_names[table].table_name;
}

__attribute__((used)) static void
catalog_database_info_init(CatalogDatabaseInfo *info)
{
	info->database_id = MyDatabaseId;
	StrNCpy(info->database_name, get_database_name(MyDatabaseId), NAMEDATALEN);
	info->schema_id = get_namespace_oid(CATALOG_SCHEMA_NAME, false);
	info->owner_uid = catalog_owner();

	if (info->schema_id == InvalidOid)
		elog(ERROR, "OID lookup failed for schema \"%s\"", CATALOG_SCHEMA_NAME);
}

void
ts_catalog_table_info_init(CatalogTableInfo *tables_info, int max_tables,
						   const TableInfoDef *table_ary, const TableIndexDef *index_ary,
						   const char **serial_id_ary)
{
	int i;

	for (i = 0; i < max_tables; i++)
	{
		Oid schema_oid;
		Oid id;
		const char *sequence_name;
		Size number_indexes, j;

		schema_oid = get_namespace_oid(table_ary[i].schema_name, false);
		id = get_relname_relid(table_ary[i].table_name, schema_oid);

		if (id == InvalidOid)
			elog(ERROR,
				 "OID lookup failed for table \"%s.%s\"",
				 table_ary[i].schema_name,
				 table_ary[i].table_name);

		tables_info[i].id = id;

		number_indexes = index_ary[i].length;
		Assert(number_indexes <= _MAX_TABLE_INDEXES);

		for (j = 0; j < number_indexes; j++)
		{
			id = get_relname_relid(index_ary[i].names[j], schema_oid);

			if (id == InvalidOid)
				elog(ERROR, "OID lookup failed for table index \"%s\"", index_ary[i].names[j]);

			tables_info[i].index_ids[j] = id;
		}

		tables_info[i].name = table_ary[i].table_name;
		tables_info[i].schema_name = table_ary[i].schema_name;
		sequence_name = serial_id_ary[i];

		if (NULL != sequence_name)
		{
			RangeVar *sequence;

			sequence = makeRangeVarFromNameList(stringToQualifiedNameList(sequence_name));
			tables_info[i].serial_relid = RangeVarGetRelid(sequence, NoLock, false);
		}
		else
			tables_info[i].serial_relid = InvalidOid;
	}
}

void
ts_catalog_reset(void)
{
	catalog.initialized = false;
	database_info.database_id = InvalidOid;
}

__attribute__((used)) static CatalogTable
catalog_get_table(Catalog *catalog, Oid relid)
{
	unsigned int i;

	if (!catalog_is_valid(catalog))
	{
		const char *schema_name = get_namespace_name(get_rel_namespace(relid));
		const char *relname = get_rel_name(relid);

		for (i = 0; i < _MAX_CATALOG_TABLES; i++)
			if (strcmp(catalog_table_names[i].schema_name, schema_name) == 0 &&
				strcmp(catalog_table_name(i), relname) == 0)
				return (CatalogTable) i;

		return INVALID_CATALOG_TABLE;
	}

	for (i = 0; i < _MAX_CATALOG_TABLES; i++)
		if (catalog->tables[i].id == relid)
			return (CatalogTable) i;

	return INVALID_CATALOG_TABLE;
}

Oid
ts_catalog_get_cache_proxy_id(Catalog *catalog, CacheType type)
{
	if (!catalog_is_valid(catalog))
	{
		Oid schema;

		/*
		 * The catalog can be invalid during upgrade scripts. Try a non-cached
		 * relation lookup, but we need to be in a transaction for
		 * get_namespace_oid() to work.
		 */
		if (!IsTransactionState())
			return InvalidOid;

		schema = get_namespace_oid(CACHE_SCHEMA_NAME, true);

		if (!OidIsValid(schema))
			return InvalidOid;

		return get_relname_relid(cache_proxy_table_names[type], schema);
	}

	return catalog->caches[type].inval_proxy_id;
}

__attribute__((used)) static void
catalog_insert(Relation rel, HeapTuple tuple)
{
	CatalogTupleInsert(rel, tuple);
	ts_catalog_invalidate_cache(RelationGetRelid(rel), CMD_INSERT);
	/* Make changes visible */
	CommandCounterIncrement();
}

void
ts_catalog_delete_tid(Relation rel, ItemPointer tid)
{
	CatalogTupleDelete(rel, tid);
	ts_catalog_invalidate_cache(RelationGetRelid(rel), CMD_DELETE);
	CommandCounterIncrement();
}

void
ts_catalog_delete_only(Relation rel, HeapTuple tuple)
{
	CatalogTupleDelete(rel, &tuple->t_self);
}

void
ts_catalog_invalidate_cache(Oid catalog_relid, CmdType operation)
{
	Catalog *catalog = ts_catalog_get();
	CatalogTable table = catalog_get_table(catalog, catalog_relid);
	Oid relid;

	switch (table)
	{
		case CHUNK:
		case CHUNK_CONSTRAINT:
		case DIMENSION_SLICE:
			if (operation == CMD_UPDATE || operation == CMD_DELETE)
			{
				relid = ts_catalog_get_cache_proxy_id(catalog, CACHE_TYPE_HYPERTABLE);
				CacheInvalidateRelcacheByRelid(relid);
			}
			break;
		case HYPERTABLE:
		case DIMENSION:
			relid = ts_catalog_get_cache_proxy_id(catalog, CACHE_TYPE_HYPERTABLE);
			CacheInvalidateRelcacheByRelid(relid);
			break;
		case BGW_JOB:
			relid = ts_catalog_get_cache_proxy_id(catalog, CACHE_TYPE_BGW_JOB);
			CacheInvalidateRelcacheByRelid(relid);
			break;
		case CHUNK_INDEX:
		default:
			break;
	}
}

