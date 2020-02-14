#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_30__   TYPE_7__ ;
typedef  struct TYPE_29__   TYPE_6__ ;
typedef  struct TYPE_28__   TYPE_5__ ;
typedef  struct TYPE_27__   TYPE_4__ ;
typedef  struct TYPE_26__   TYPE_3__ ;
typedef  struct TYPE_25__   TYPE_2__ ;
typedef  struct TYPE_24__   TYPE_22__ ;
typedef  struct TYPE_23__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ int64 ;
typedef  int /*<<< orphan*/  TupleDesc ;
struct TYPE_30__ {int /*<<< orphan*/  args; } ;
struct TYPE_25__ {scalar_t__ typid; int /*<<< orphan*/  typlen; int /*<<< orphan*/  typbyval; } ;
struct TYPE_28__ {int isnull; scalar_t__ time; void* value; } ;
struct TYPE_29__ {TYPE_2__ base; TYPE_5__ next; TYPE_5__ prev; int /*<<< orphan*/ * lookup_after; int /*<<< orphan*/ * lookup_before; } ;
struct TYPE_27__ {size_t time_index; scalar_t__ gapfill_start; scalar_t__ state; int /*<<< orphan*/  gapfill_typid; TYPE_1__** columns; } ;
struct TYPE_26__ {int /*<<< orphan*/  t_data; int /*<<< orphan*/  t_tableOid; int /*<<< orphan*/  t_self; int /*<<< orphan*/  t_len; } ;
struct TYPE_24__ {scalar_t__ atttypid; } ;
struct TYPE_23__ {scalar_t__ typid; } ;
typedef  int /*<<< orphan*/  HeapTupleHeader ;
typedef  TYPE_3__ HeapTupleData ;
typedef  TYPE_4__ GapFillState ;
typedef  TYPE_5__ GapFillInterpolateSample ;
typedef  TYPE_6__ GapFillInterpolateColumnState ;
typedef  TYPE_7__ FuncExpr ;
typedef  int /*<<< orphan*/  Expr ;
typedef  void* Datum ;

/* Variables and functions */
 int /*<<< orphan*/  Assert (int) ; 
 int /*<<< orphan*/  DatumGetFloat4 (void*) ; 
 int /*<<< orphan*/  DatumGetFloat8 (void*) ; 
 int /*<<< orphan*/  DatumGetHeapTupleHeader (void*) ; 
 int /*<<< orphan*/  DatumGetInt16 (void*) ; 
 int /*<<< orphan*/  DatumGetInt32 (void*) ; 
 int /*<<< orphan*/  DatumGetInt64 (void*) ; 
 int /*<<< orphan*/  DecrTupleDescRefCount (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ERRCODE_FEATURE_NOT_SUPPORTED ; 
 int /*<<< orphan*/  ERRCODE_INVALID_PARAMETER_VALUE ; 
 int /*<<< orphan*/  ERROR ; 
 scalar_t__ FETCHED_LAST ; 
 scalar_t__ FETCHED_NEXT_GROUP ; 
#define  FLOAT4OID 132 
#define  FLOAT8OID 131 
 void* Float4GetDatum (int /*<<< orphan*/ ) ; 
 void* Float8GetDatum (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  HeapTupleHeaderGetDatumLength (int /*<<< orphan*/ ) ; 
 int HeapTupleHeaderGetNatts (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  HeapTupleHeaderGetTypMod (int /*<<< orphan*/ ) ; 
 scalar_t__ HeapTupleHeaderGetTypeId (int /*<<< orphan*/ ) ; 
#define  INT2OID 130 
#define  INT4OID 129 
#define  INT8OID 128 
 int /*<<< orphan*/  INTERPOLATE (scalar_t__,scalar_t__,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 void* Int16GetDatum (int /*<<< orphan*/ ) ; 
 void* Int32GetDatum (int /*<<< orphan*/ ) ; 
 void* Int64GetDatum (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  InvalidOid ; 
 int /*<<< orphan*/  ItemPointerSetInvalid (int /*<<< orphan*/ *) ; 
 scalar_t__ RECORDOID ; 
 TYPE_22__* TupleDescAttr (int /*<<< orphan*/ ,int) ; 
 void* datumCopy (void*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ereport (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  errcode (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  errmsg (char*,...) ; 
 int /*<<< orphan*/  format_type_be (int) ; 
 void* gapfill_adjust_varnos (TYPE_4__*,int /*<<< orphan*/ ) ; 
 scalar_t__ gapfill_datum_get_internal (void*,int /*<<< orphan*/ ) ; 
 void* gapfill_exec_expr (TYPE_4__*,int /*<<< orphan*/ *,int*) ; 
 void* heap_getattr (TYPE_3__*,int,int /*<<< orphan*/ ,int*) ; 
 int list_length (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lookup_rowtype_tupdesc (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lsecond (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lthird (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pg_unreachable () ; 

void
gapfill_interpolate_initialize(GapFillInterpolateColumnState *interpolate, GapFillState *state,
							   FuncExpr *function)
{
	interpolate->prev.isnull = true;
	interpolate->next.isnull = true;
	if (list_length(((FuncExpr *) function)->args) > 1)
		interpolate->lookup_before =
			gapfill_adjust_varnos(state, lsecond(((FuncExpr *) function)->args));
	if (list_length(((FuncExpr *) function)->args) > 2)
		interpolate->lookup_after =
			gapfill_adjust_varnos(state, lthird(((FuncExpr *) function)->args));
}

void
gapfill_interpolate_group_change(GapFillInterpolateColumnState *column, int64 time, Datum value,
								 bool isnull)
{
	column->prev.isnull = true;
	column->next.isnull = isnull;
	if (!isnull)
	{
		column->next.time = time;
		column->next.value = datumCopy(value, column->base.typbyval, column->base.typlen);
	}
}

void
gapfill_interpolate_tuple_fetched(GapFillInterpolateColumnState *column, int64 time, Datum value,
								  bool isnull)
{
	column->next.isnull = isnull;
	if (!isnull)
	{
		column->next.time = time;
		column->next.value = datumCopy(value, column->base.typbyval, column->base.typlen);
	}
}

void
gapfill_interpolate_tuple_returned(GapFillInterpolateColumnState *column, int64 time, Datum value,
								   bool isnull)
{
	column->next.isnull = true;
	column->prev.isnull = isnull;
	if (!isnull)
	{
		column->prev.time = time;
		column->prev.value = datumCopy(value, column->base.typbyval, column->base.typlen);
	}
}

__attribute__((used)) static void
gapfill_fetch_sample(GapFillState *state, GapFillInterpolateColumnState *column,
					 GapFillInterpolateSample *sample, Expr *lookup)
{
	HeapTupleHeader th;
	HeapTupleData tuple;
	TupleDesc tupdesc;
	Datum value;
	bool isnull;
	Datum datum = gapfill_exec_expr(state, lookup, &isnull);

	if (isnull)
	{
		sample->isnull = true;
		return;
	}

	th = DatumGetHeapTupleHeader(datum);
	if (HeapTupleHeaderGetNatts(th) != 2)
		ereport(ERROR,
				(errcode(ERRCODE_INVALID_PARAMETER_VALUE),
				 errmsg("interpolate RECORD arguments must have 2 elements")));

	/* Extract type information from the tuple itself */
	Assert(RECORDOID == HeapTupleHeaderGetTypeId(th));
	tupdesc = lookup_rowtype_tupdesc(HeapTupleHeaderGetTypeId(th), HeapTupleHeaderGetTypMod(th));

	/* Build a temporary HeapTuple control structure */
	tuple.t_len = HeapTupleHeaderGetDatumLength(th);
	ItemPointerSetInvalid(&(tuple.t_self));
	tuple.t_tableOid = InvalidOid;
	tuple.t_data = th;

	/* check first element in record matches timestamp datatype */
	if (TupleDescAttr(tupdesc, 0)->atttypid != state->columns[state->time_index]->typid)
		ereport(ERROR,
				(errcode(ERRCODE_INVALID_PARAMETER_VALUE),
				 errmsg("first argument of interpolate returned record must match used timestamp "
						"datatype")));

	/* check second element in record matches interpolate datatype */
	if (TupleDescAttr(tupdesc, 1)->atttypid != column->base.typid)
		ereport(ERROR,
				(errcode(ERRCODE_INVALID_PARAMETER_VALUE),
				 errmsg("second argument of interpolate returned record must match used "
						"interpolate datatype")));

	value = heap_getattr(&tuple, 1, tupdesc, &sample->isnull);
	if (!sample->isnull)
	{
		sample->time = gapfill_datum_get_internal(value, state->gapfill_typid);

		value = heap_getattr(&tuple, 2, tupdesc, &sample->isnull);
		if (!sample->isnull)
			sample->value = datumCopy(value, column->base.typbyval, column->base.typlen);
	}

	DecrTupleDescRefCount(tupdesc);
}

void
gapfill_interpolate_calculate(GapFillInterpolateColumnState *column, GapFillState *state,
							  int64 time, Datum *value, bool *isnull)
{
	int64 x, x0, x1;
	Datum y0, y1;

	/* only evaluate expr for first tuple */
	if (column->prev.isnull && column->lookup_before && time == state->gapfill_start)
		gapfill_fetch_sample(state, column, &column->prev, column->lookup_before);

	if (column->next.isnull && column->lookup_after &&
		(FETCHED_LAST == state->state || FETCHED_NEXT_GROUP == state->state))
		gapfill_fetch_sample(state, column, &column->next, column->lookup_after);

	*isnull = column->prev.isnull || column->next.isnull;
	if (*isnull)
		return;

	y0 = column->prev.value;
	y1 = column->next.value;

	x = time;
	x0 = column->prev.time;
	x1 = column->next.time;

	switch (column->base.typid)
	{
		case INT2OID:
			*value = Int16GetDatum(INTERPOLATE(x, x0, x1, DatumGetInt16(y0), DatumGetInt16(y1)));
			break;
		case INT4OID:
			*value = Int32GetDatum(INTERPOLATE(x, x0, x1, DatumGetInt32(y0), DatumGetInt32(y1)));
			break;
		case INT8OID:
			*value = Int64GetDatum(INTERPOLATE(x, x0, x1, DatumGetInt64(y0), DatumGetInt64(y1)));
			break;
		case FLOAT4OID:
			*value = Float4GetDatum(INTERPOLATE(x, x0, x1, DatumGetFloat4(y0), DatumGetFloat4(y1)));
			break;
		case FLOAT8OID:
			*value = Float8GetDatum(INTERPOLATE(x, x0, x1, DatumGetFloat8(y0), DatumGetFloat8(y1)));
			break;
		default:

			/*
			 * should never happen since interpolate is not defined for other
			 * datatypes
			 */
			ereport(ERROR,
					(errcode(ERRCODE_FEATURE_NOT_SUPPORTED),
					 errmsg("unsupported datatype for interpolate: %s",
							format_type_be(column->base.typid))));
			pg_unreachable();
			break;
	}
}

