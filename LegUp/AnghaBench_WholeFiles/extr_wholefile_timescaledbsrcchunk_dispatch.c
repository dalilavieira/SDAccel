#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_34__   TYPE_8__ ;
typedef  struct TYPE_33__   TYPE_7__ ;
typedef  struct TYPE_32__   TYPE_6__ ;
typedef  struct TYPE_31__   TYPE_5__ ;
typedef  struct TYPE_30__   TYPE_4__ ;
typedef  struct TYPE_29__   TYPE_3__ ;
typedef  struct TYPE_28__   TYPE_2__ ;
typedef  struct TYPE_27__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  regproc ;
typedef  scalar_t__ int64 ;
struct TYPE_34__ {TYPE_1__* tables; } ;
struct TYPE_33__ {int /*<<< orphan*/  cube; } ;
struct TYPE_32__ {scalar_t__ prev_cis_oid; TYPE_5__* prev_cis; int /*<<< orphan*/  cache; TYPE_3__* hypertable; int /*<<< orphan*/  cmd_type; int /*<<< orphan*/  arbiter_indexes; int /*<<< orphan*/  on_conflict; int /*<<< orphan*/ * hypertable_result_rel_info; TYPE_4__* estate; } ;
struct TYPE_31__ {TYPE_2__* rel; } ;
struct TYPE_30__ {int /*<<< orphan*/  es_query_cxt; } ;
struct TYPE_29__ {int /*<<< orphan*/  space; } ;
struct TYPE_28__ {scalar_t__ rd_id; } ;
struct TYPE_27__ {scalar_t__ id; scalar_t__* index_ids; } ;
typedef  int /*<<< orphan*/  Point ;
typedef  scalar_t__ Oid ;
typedef  int /*<<< orphan*/  Name ;
typedef  TYPE_3__ Hypertable ;
typedef  TYPE_4__ EState ;
typedef  int /*<<< orphan*/  DimensionInfo ;
typedef  TYPE_5__ ChunkInsertState ;
typedef  TYPE_6__ ChunkDispatch ;
typedef  TYPE_7__ Chunk ;
typedef  size_t CatalogTable ;
typedef  TYPE_8__ Catalog ;

/* Variables and functions */
 int /*<<< orphan*/  Assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CMD_INSERT ; 
 int /*<<< orphan*/  ERROR ; 
 int /*<<< orphan*/  INT8OID ; 
 int INVALID_INDEXID ; 
 int /*<<< orphan*/  Int64GetDatum (scalar_t__) ; 
 scalar_t__ InvalidOid ; 
 int /*<<< orphan*/  NIL ; 
 int /*<<< orphan*/  ONCONFLICT_NONE ; 
 int /*<<< orphan*/  elog (int /*<<< orphan*/ ,char*) ; 
 TYPE_6__* palloc0 (int) ; 
 TYPE_5__* ts_chunk_insert_state_create (TYPE_7__*,TYPE_6__*) ; 
 int /*<<< orphan*/  ts_chunk_insert_state_destroy (TYPE_5__*) ; 
 int /*<<< orphan*/  ts_chunk_insert_state_switch (TYPE_5__*) ; 
 int /*<<< orphan*/ * ts_dimension_info_create_open (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ts_guc_max_open_chunks_per_insert ; 
 TYPE_7__* ts_hypertable_get_or_create_chunk (TYPE_3__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ts_subspace_store_add (int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_5__*,void (*) (void*)) ; 
 int /*<<< orphan*/  ts_subspace_store_free (int /*<<< orphan*/ ) ; 
 TYPE_5__* ts_subspace_store_get (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ts_subspace_store_init (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

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

ChunkDispatch *
ts_chunk_dispatch_create(Hypertable *ht, EState *estate)
{
	ChunkDispatch *cd = palloc0(sizeof(ChunkDispatch));

	cd->hypertable = ht;
	cd->estate = estate;
	cd->hypertable_result_rel_info = NULL;
	cd->on_conflict = ONCONFLICT_NONE;
	cd->arbiter_indexes = NIL;
	cd->cmd_type = CMD_INSERT;
	cd->cache =
		ts_subspace_store_init(ht->space, estate->es_query_cxt, ts_guc_max_open_chunks_per_insert);
	cd->prev_cis = NULL;
	cd->prev_cis_oid = InvalidOid;

	return cd;
}

void
ts_chunk_dispatch_destroy(ChunkDispatch *cd)
{
	ts_subspace_store_free(cd->cache);
}

__attribute__((used)) static void
destroy_chunk_insert_state(void *cis)
{
	ts_chunk_insert_state_destroy((ChunkInsertState *) cis);
}

extern ChunkInsertState *
ts_chunk_dispatch_get_chunk_insert_state(ChunkDispatch *dispatch, Point *point,
										 bool *cis_changed_out)
{
	ChunkInsertState *cis;

	Assert(cis_changed_out != NULL);
	cis = ts_subspace_store_get(dispatch->cache, point);
	*cis_changed_out = true;

	if (NULL == cis)
	{
		Chunk *new_chunk;

		new_chunk = ts_hypertable_get_or_create_chunk(dispatch->hypertable, point);

		if (NULL == new_chunk)
			elog(ERROR, "no chunk found or created");

		cis = ts_chunk_insert_state_create(new_chunk, dispatch);
		ts_subspace_store_add(dispatch->cache, new_chunk->cube, cis, destroy_chunk_insert_state);
	}
	else if (cis->rel->rd_id == dispatch->prev_cis_oid && cis == dispatch->prev_cis)
	{
		/* got the same item from cache as before */
		*cis_changed_out = false;
	}

	if (*cis_changed_out)
		ts_chunk_insert_state_switch(cis);

	Assert(cis != NULL);
	dispatch->prev_cis = cis;
	dispatch->prev_cis_oid = cis->rel->rd_id;
	return cis;
}

