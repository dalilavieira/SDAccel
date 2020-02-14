#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_49__   TYPE_5__ ;
typedef  struct TYPE_48__   TYPE_4__ ;
typedef  struct TYPE_47__   TYPE_3__ ;
typedef  struct TYPE_46__   TYPE_2__ ;
typedef  struct TYPE_45__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  regproc ;
typedef  scalar_t__ int64 ;
typedef  scalar_t__ int32 ;
struct TYPE_49__ {TYPE_1__* tables; } ;
struct TYPE_46__ {scalar_t__ dimension_id; scalar_t__ id; } ;
struct TYPE_48__ {TYPE_2__ fd; } ;
struct TYPE_47__ {scalar_t__ capacity; scalar_t__ num_slices; TYPE_4__** slices; } ;
struct TYPE_45__ {int /*<<< orphan*/ * index_ids; int /*<<< orphan*/  id; } ;
typedef  int /*<<< orphan*/  Oid ;
typedef  int /*<<< orphan*/  Name ;
typedef  TYPE_3__ DimensionVec ;
typedef  TYPE_4__ DimensionSlice ;
typedef  int /*<<< orphan*/  DimensionInfo ;
typedef  size_t CatalogTable ;
typedef  TYPE_5__ Catalog ;

/* Variables and functions */
 int /*<<< orphan*/  Assert (int) ; 
 int /*<<< orphan*/  DIMENSION_VEC_SIZE (scalar_t__) ; 
 int /*<<< orphan*/  INT8OID ; 
 int INVALID_INDEXID ; 
 int /*<<< orphan*/  Int64GetDatum (scalar_t__) ; 
 int /*<<< orphan*/  InvalidOid ; 
 TYPE_4__** bsearch (scalar_t__*,TYPE_4__**,scalar_t__,int,int (*) (void const*,void const*)) ; 
 int dimension_vec_is_sorted (TYPE_3__*) ; 
 int /*<<< orphan*/  memmove (TYPE_4__**,TYPE_4__**,int) ; 
 TYPE_3__* palloc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pfree (TYPE_3__*) ; 
 int /*<<< orphan*/  qsort (TYPE_4__**,scalar_t__,int,int (*) (void const*,void const*)) ; 
 TYPE_3__* repalloc (TYPE_3__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * ts_dimension_info_create_open (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int ts_dimension_slice_cmp (TYPE_4__ const*,TYPE_4__ const*) ; 
 int ts_dimension_slice_cmp_coordinate (TYPE_4__ const*,scalar_t__) ; 
 int /*<<< orphan*/  ts_dimension_slice_free (TYPE_4__*) ; 
 int ts_dimension_vec_find_slice_index (TYPE_3__*,scalar_t__) ; 

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

__attribute__((used)) static int
cmp_slices(const void *left, const void *right)
{
	const DimensionSlice *left_slice = *((DimensionSlice **) left);
	const DimensionSlice *right_slice = *((DimensionSlice **) right);

	return ts_dimension_slice_cmp(left_slice, right_slice);
}

__attribute__((used)) static int
cmp_slices_reverse(const void *left, const void *right)
{
	const DimensionSlice *left_slice = *((DimensionSlice **) left);
	const DimensionSlice *right_slice = *((DimensionSlice **) right);

	return ts_dimension_slice_cmp(right_slice, left_slice);
}

__attribute__((used)) static int
cmp_coordinate_and_slice(const void *left, const void *right)
{
	int64 coord = *((int64 *) left);
	const DimensionSlice *slice = *((DimensionSlice **) right);

	return ts_dimension_slice_cmp_coordinate(slice, coord);
}

__attribute__((used)) static DimensionVec *
dimension_vec_expand(DimensionVec *vec, int32 new_capacity)
{
	if (vec != NULL && vec->capacity >= new_capacity)
		return vec;

	if (NULL == vec)
		vec = palloc(DIMENSION_VEC_SIZE(new_capacity));
	else
		vec = repalloc(vec, DIMENSION_VEC_SIZE(new_capacity));

	vec->capacity = new_capacity;

	return vec;
}

DimensionVec *
ts_dimension_vec_create(int32 initial_num_slices)
{
	DimensionVec *vec = dimension_vec_expand(NULL, initial_num_slices);

	vec->capacity = initial_num_slices;
	vec->num_slices = 0;

	return vec;
}

DimensionVec *
ts_dimension_vec_sort(DimensionVec **vecptr)
{
	DimensionVec *vec = *vecptr;

	qsort(vec->slices, vec->num_slices, sizeof(DimensionSlice *), cmp_slices);

	return vec;
}

DimensionVec *
ts_dimension_vec_sort_reverse(DimensionVec **vecptr)
{
	DimensionVec *vec = *vecptr;

	qsort(vec->slices, vec->num_slices, sizeof(DimensionSlice *), cmp_slices_reverse);

	return vec;
}

DimensionVec *
ts_dimension_vec_add_slice(DimensionVec **vecptr, DimensionSlice *slice)
{
	DimensionVec *vec = *vecptr;

	/* Ensure consistent dimension */
	Assert(vec->num_slices == 0 || vec->slices[0]->fd.dimension_id == slice->fd.dimension_id);

	if (vec->num_slices + 1 > vec->capacity)
		*vecptr = vec = dimension_vec_expand(vec, vec->capacity + 10);

	vec->slices[vec->num_slices++] = slice;

	return vec;
}

DimensionVec *
ts_dimension_vec_add_unique_slice(DimensionVec **vecptr, DimensionSlice *slice)
{
	DimensionVec *vec = *vecptr;

	int32 existing_slice_index = ts_dimension_vec_find_slice_index(vec, slice->fd.id);

	if (existing_slice_index == -1)
	{
		return ts_dimension_vec_add_slice(vecptr, slice);
	}
	return vec;
}

DimensionVec *
ts_dimension_vec_add_slice_sort(DimensionVec **vecptr, DimensionSlice *slice)
{
	DimensionVec *vec;

	*vecptr = vec = ts_dimension_vec_add_slice(vecptr, slice);
	return ts_dimension_vec_sort(vecptr);
}

void
ts_dimension_vec_remove_slice(DimensionVec **vecptr, int32 index)
{
	DimensionVec *vec = *vecptr;

	ts_dimension_slice_free(vec->slices[index]);
	memmove(vec->slices + index,
			vec->slices + (index + 1),
			sizeof(DimensionSlice *) * (vec->num_slices - index - 1));
	vec->num_slices--;
}

DimensionSlice *
ts_dimension_vec_find_slice(DimensionVec *vec, int64 coordinate)
{
	DimensionSlice **res;

	if (vec->num_slices == 0)
		return NULL;

	Assert(dimension_vec_is_sorted(vec));

	res = bsearch(&coordinate,
				  vec->slices,
				  vec->num_slices,
				  sizeof(DimensionSlice *),
				  cmp_coordinate_and_slice);

	if (res == NULL)
		return NULL;

	return *res;
}

int
ts_dimension_vec_find_slice_index(DimensionVec *vec, int32 dimension_slice_id)
{
	int i;

	for (i = 0; i < vec->num_slices; i++)
		if (dimension_slice_id == vec->slices[i]->fd.id)
			return i;

	return -1;
}

DimensionSlice *
ts_dimension_vec_get(DimensionVec *vec, int32 index)
{
	if (index >= vec->num_slices)
		return NULL;

	return vec->slices[index];
}

void
ts_dimension_vec_free(DimensionVec *vec)
{
	int i;

	for (i = 0; i < vec->num_slices; i++)
		ts_dimension_slice_free(vec->slices[i]);
	pfree(vec);
}

