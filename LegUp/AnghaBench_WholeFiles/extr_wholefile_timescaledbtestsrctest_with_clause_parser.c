#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  TYPE_1__* TupleDesc ;
struct TYPE_13__ {int /*<<< orphan*/  typalign; int /*<<< orphan*/  typbyval; int /*<<< orphan*/  typlen; int /*<<< orphan*/  element_type; } ;
struct TYPE_12__ {int /*<<< orphan*/ * arg; int /*<<< orphan*/ * defname; int /*<<< orphan*/ * defnamespace; } ;
struct TYPE_11__ {int natts; } ;
typedef  int /*<<< orphan*/  Node ;
typedef  int /*<<< orphan*/  List ;
typedef  int /*<<< orphan*/  HeapTuple ;
typedef  TYPE_2__ DefElem ;
typedef  int /*<<< orphan*/  Datum ;
typedef  int /*<<< orphan*/  ArrayType ;
typedef  TYPE_3__ ArrayMetaState ;
typedef  int /*<<< orphan*/  ArrayIterator ;

/* Variables and functions */
 int /*<<< orphan*/  Assert (int) ; 
 int /*<<< orphan*/  BoolGetDatum (int) ; 
 int /*<<< orphan*/  CStringGetTextDatum (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * DatumGetArrayTypeP (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DatumGetTextP (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ERROR ; 
 int /*<<< orphan*/ * NIL ; 
 int /*<<< orphan*/  TEXTOID ; 
 int /*<<< orphan*/  array_create_iterator (int /*<<< orphan*/ *,int,TYPE_3__*) ; 
 scalar_t__ array_iterate (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int*) ; 
 int /*<<< orphan*/  deconstruct_array (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ **,int /*<<< orphan*/ *,int*) ; 
 int /*<<< orphan*/ * defGetString (TYPE_2__*) ; 
 int /*<<< orphan*/  elog (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  get_typlenbyvalalign (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  heap_form_tuple (TYPE_1__*,int /*<<< orphan*/ *,int*) ; 
 int /*<<< orphan*/ * lappend (int /*<<< orphan*/ *,TYPE_2__*) ; 
 scalar_t__ makeString (void*) ; 
 void* palloc0 (int) ; 
 void* text_to_cstring (int /*<<< orphan*/ ) ; 

__attribute__((used)) static DefElem *
def_elem_from_texts(Datum *texts, int nelems)
{
	DefElem *elem = palloc0(sizeof(*elem));
	switch (nelems)
	{
		case 1:
			elem->defname = text_to_cstring(DatumGetTextP(texts[0]));
			break;
		case 3:
			elem->arg = (Node *) makeString(text_to_cstring(DatumGetTextP(texts[2])));
		case 2:
			elem->defname = text_to_cstring(DatumGetTextP(texts[1]));
			elem->defnamespace = text_to_cstring(DatumGetTextP(texts[0]));
			break;
		default:
			elog(ERROR, "%d elements invalid for defelem", nelems);
	}
	return elem;
}

__attribute__((used)) static List *
def_elems_from_array(ArrayType *with_clause_array)
{
	ArrayMetaState with_clause_meta = { .element_type = TEXTOID };
	ArrayIterator with_clause_iter;
	Datum with_clause_datum;
	bool with_clause_null;
	List *def_elems = NIL;

	get_typlenbyvalalign(with_clause_meta.element_type,
						 &with_clause_meta.typlen,
						 &with_clause_meta.typbyval,
						 &with_clause_meta.typalign);
	with_clause_iter = array_create_iterator(with_clause_array, 1, &with_clause_meta);

	while (array_iterate(with_clause_iter, &with_clause_datum, &with_clause_null))
	{
		Datum *with_clause_fields;
		int with_clause_elems;
		ArrayType *with_clause = DatumGetArrayTypeP(with_clause_datum);
		Assert(!with_clause_null);
		deconstruct_array(with_clause,
						  TEXTOID,
						  with_clause_meta.typlen,
						  with_clause_meta.typbyval,
						  with_clause_meta.typalign,
						  &with_clause_fields,
						  NULL,
						  &with_clause_elems);
		def_elems = lappend(def_elems, def_elem_from_texts(with_clause_fields, with_clause_elems));
	}
	return def_elems;
}

__attribute__((used)) static HeapTuple
create_filter_tuple(TupleDesc tuple_desc, DefElem *d, bool within)
{
	Datum *values = palloc0(sizeof(*values) * tuple_desc->natts);
	bool *nulls = palloc0(sizeof(*nulls) * tuple_desc->natts);

	Assert(tuple_desc->natts >= 4);

	if (d->defnamespace != NULL)
		values[0] = CStringGetTextDatum(d->defnamespace);
	else
		nulls[0] = true;

	if (d->defname != NULL)
		values[1] = CStringGetTextDatum(d->defname);
	else
		nulls[1] = true;

	if (d->arg != NULL)
		values[2] = CStringGetTextDatum(defGetString(d));
	else
		nulls[2] = true;

	values[3] = BoolGetDatum(within);
	return heap_form_tuple(tuple_desc, values, nulls);
}

