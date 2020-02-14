#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_65__   TYPE_9__ ;
typedef  struct TYPE_64__   TYPE_8__ ;
typedef  struct TYPE_63__   TYPE_7__ ;
typedef  struct TYPE_62__   TYPE_6__ ;
typedef  struct TYPE_61__   TYPE_5__ ;
typedef  struct TYPE_60__   TYPE_4__ ;
typedef  struct TYPE_59__   TYPE_3__ ;
typedef  struct TYPE_58__   TYPE_2__ ;
typedef  struct TYPE_57__   TYPE_1__ ;
typedef  struct TYPE_56__   TYPE_13__ ;
typedef  struct TYPE_55__   TYPE_12__ ;
typedef  struct TYPE_54__   TYPE_11__ ;
typedef  struct TYPE_53__   TYPE_10__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  regproc ;
typedef  scalar_t__ int64 ;
typedef  scalar_t__ int32 ;
typedef  int int16 ;
struct TYPE_59__ {scalar_t__ dimension_id; } ;
struct TYPE_65__ {TYPE_3__ fd; } ;
struct TYPE_64__ {scalar_t__ num_slices; TYPE_9__** slices; } ;
struct TYPE_63__ {int capacity; int num_slices; TYPE_9__** slices; } ;
struct TYPE_62__ {int num_dimensions; TYPE_10__* dimensions; } ;
struct TYPE_61__ {scalar_t__* coordinates; } ;
struct TYPE_60__ {int /*<<< orphan*/  dimension_slice_id; } ;
struct TYPE_58__ {int /*<<< orphan*/ * index_ids; int /*<<< orphan*/  id; } ;
struct TYPE_57__ {scalar_t__ id; scalar_t__ aligned; } ;
struct TYPE_56__ {TYPE_2__* tables; } ;
struct TYPE_55__ {TYPE_4__ fd; } ;
struct TYPE_54__ {int num_dimension_constraints; int num_constraints; } ;
struct TYPE_53__ {TYPE_1__ fd; } ;
typedef  TYPE_5__ Point ;
typedef  int /*<<< orphan*/  Oid ;
typedef  int /*<<< orphan*/  Name ;
typedef  int /*<<< orphan*/  MemoryContext ;
typedef  TYPE_6__ Hyperspace ;
typedef  TYPE_7__ Hypercube ;
typedef  TYPE_8__ DimensionVec ;
typedef  TYPE_9__ DimensionSlice ;
typedef  int /*<<< orphan*/  DimensionInfo ;
typedef  TYPE_10__ Dimension ;
typedef  TYPE_11__ ChunkConstraints ;
typedef  TYPE_12__ ChunkConstraint ;
typedef  size_t CatalogTable ;
typedef  TYPE_13__ Catalog ;

/* Variables and functions */
 int /*<<< orphan*/  Assert (int) ; 
 size_t HYPERCUBE_SIZE (int) ; 
 int /*<<< orphan*/  INT8OID ; 
 int INVALID_INDEXID ; 
 int /*<<< orphan*/  Int64GetDatum (scalar_t__) ; 
 int /*<<< orphan*/  InvalidOid ; 
 int /*<<< orphan*/  MemoryContextSwitchTo (int /*<<< orphan*/ ) ; 
 void* bsearch (void**,TYPE_9__**,int,int,int (*) (void const*,void const*)) ; 
 TYPE_12__* chunk_constraints_get (TYPE_11__*,int) ; 
 int hypercube_is_sorted (TYPE_7__*) ; 
 scalar_t__ is_dimension_constraint (TYPE_12__*) ; 
 int /*<<< orphan*/  memcpy (TYPE_7__*,TYPE_7__*,size_t) ; 
 TYPE_7__* palloc (size_t) ; 
 TYPE_7__* palloc0 (size_t) ; 
 int /*<<< orphan*/  pfree (TYPE_7__*) ; 
 int /*<<< orphan*/  qsort (TYPE_9__**,int,int,int (*) (void const*,void const*)) ; 
 TYPE_9__* ts_dimension_calculate_default_slice (TYPE_10__*,scalar_t__) ; 
 int /*<<< orphan*/ * ts_dimension_info_create_open (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_9__* ts_dimension_slice_copy (TYPE_9__*) ; 
 int /*<<< orphan*/  ts_dimension_slice_free (TYPE_9__*) ; 
 TYPE_9__* ts_dimension_slice_scan_by_id (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ts_dimension_slice_scan_for_existing (TYPE_9__*) ; 
 TYPE_8__* ts_dimension_slice_scan_limit (scalar_t__,scalar_t__,int) ; 
 int /*<<< orphan*/  ts_dimension_slices_collide (TYPE_9__*,TYPE_9__*) ; 
 void ts_hypercube_slice_sort (TYPE_7__*) ; 

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

Hypercube *
ts_hypercube_alloc(int16 num_dimensions)
{
	Hypercube *hc = palloc0(HYPERCUBE_SIZE(num_dimensions));

	hc->capacity = num_dimensions;
	return hc;
}

void
ts_hypercube_free(Hypercube *hc)
{
	int i;

	for (i = 0; i < hc->num_slices; i++)
		ts_dimension_slice_free(hc->slices[i]);

	pfree(hc);
}

Hypercube *
ts_hypercube_copy(Hypercube *hc)
{
	Hypercube *copy;
	size_t nbytes = HYPERCUBE_SIZE(hc->capacity);
	int i;

	copy = palloc(nbytes);
	memcpy(copy, hc, nbytes);

	for (i = 0; i < hc->num_slices; i++)
		copy->slices[i] = ts_dimension_slice_copy(hc->slices[i]);

	return copy;
}

__attribute__((used)) static int
cmp_slices_by_dimension_id(const void *left, const void *right)
{
	const DimensionSlice *left_slice = *((DimensionSlice **) left);
	const DimensionSlice *right_slice = *((DimensionSlice **) right);

	if (left_slice->fd.dimension_id == right_slice->fd.dimension_id)
		return 0;
	if (left_slice->fd.dimension_id < right_slice->fd.dimension_id)
		return -1;
	return 1;
}

void
ts_hypercube_add_slice(Hypercube *hc, DimensionSlice *slice)
{
	Assert(hc->capacity > hc->num_slices);

	hc->slices[hc->num_slices++] = slice;

	/* Check if we require a sort to maintain dimension order */
	if (hc->num_slices > 1 &&
		slice->fd.dimension_id < hc->slices[hc->num_slices - 2]->fd.dimension_id)
		ts_hypercube_slice_sort(hc);

	Assert(hypercube_is_sorted(hc));
}

void
ts_hypercube_slice_sort(Hypercube *hc)
{
	qsort(hc->slices, hc->num_slices, sizeof(DimensionSlice *), cmp_slices_by_dimension_id);
}

DimensionSlice *
ts_hypercube_get_slice_by_dimension_id(Hypercube *hc, int32 dimension_id)
{
	DimensionSlice slice = {
		.fd.dimension_id = dimension_id,
	};
	void *ptr = &slice;

	if (hc->num_slices == 0)
		return NULL;

	Assert(hypercube_is_sorted(hc));

	ptr = bsearch(&ptr,
				  hc->slices,
				  hc->num_slices,
				  sizeof(DimensionSlice *),
				  cmp_slices_by_dimension_id);

	if (NULL == ptr)
		return NULL;

	return *((DimensionSlice **) ptr);
}

Hypercube *
ts_hypercube_from_constraints(ChunkConstraints *constraints, MemoryContext mctx)
{
	Hypercube *hc;
	int i;
	MemoryContext old;

	old = MemoryContextSwitchTo(mctx);
	hc = ts_hypercube_alloc(constraints->num_dimension_constraints);
	MemoryContextSwitchTo(old);

	for (i = 0; i < constraints->num_constraints; i++)
	{
		ChunkConstraint *cc = chunk_constraints_get(constraints, i);

		if (is_dimension_constraint(cc))
		{
			DimensionSlice *slice;

			Assert(hc->num_slices < constraints->num_dimension_constraints);
			slice = ts_dimension_slice_scan_by_id(cc->fd.dimension_slice_id, mctx);
			Assert(slice != NULL);
			hc->slices[hc->num_slices++] = slice;
		}
	}

	ts_hypercube_slice_sort(hc);

	Assert(hypercube_is_sorted(hc));

	return hc;
}

Hypercube *
ts_hypercube_calculate_from_point(Hyperspace *hs, Point *p)
{
	Hypercube *cube;
	int i;

	cube = ts_hypercube_alloc(hs->num_dimensions);

	/* For each dimension, calculate the hypercube's slice in that dimension */
	for (i = 0; i < hs->num_dimensions; i++)
	{
		Dimension *dim = &hs->dimensions[i];
		int64 value = p->coordinates[i];
		bool found = false;

		/* Assert that dimensions are in ascending order */
		Assert(i == 0 || dim->fd.id > hs->dimensions[i - 1].fd.id);

		/*
		 * If this is an aligned dimension, we'd like to reuse any existing
		 * slice that covers the coordinate in the dimension
		 */
		if (dim->fd.aligned)
		{
			DimensionVec *vec;

			vec = ts_dimension_slice_scan_limit(dim->fd.id, value, 1);

			if (vec->num_slices > 0)
			{
				cube->slices[i] = vec->slices[0];
				found = true;
			}
		}

		if (!found)
		{
			/*
			 * No existing slice found, or we are not aligning, so calculate
			 * the range of a new slice
			 */
			cube->slices[i] = ts_dimension_calculate_default_slice(dim, value);

			/*
			 * Check if there's already an existing slice with the calculated
			 * range. If a slice already exists, use that slice's ID instead
			 * of a new one.
			 */
			ts_dimension_slice_scan_for_existing(cube->slices[i]);
		}
	}

	cube->num_slices = hs->num_dimensions;

	Assert(hypercube_is_sorted(cube));

	return cube;
}

bool
ts_hypercubes_collide(Hypercube *cube1, Hypercube *cube2)
{
	int i;

	Assert(cube1->num_slices == cube2->num_slices);

	for (i = 0; i < cube1->num_slices; i++)
		if (!ts_dimension_slices_collide(cube1->slices[i], cube2->slices[i]))
			return false;

	return true;
}

