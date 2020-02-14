#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ int64 ;
struct TYPE_8__ {int /*<<< orphan*/  desc; int /*<<< orphan*/  tuple; } ;
typedef  TYPE_1__ TupleInfo ;
typedef  int /*<<< orphan*/  TupleDesc ;
struct TYPE_9__ {int /*<<< orphan*/  ictx; int /*<<< orphan*/  ctx; TYPE_1__* tinfo; } ;
typedef  TYPE_2__ ScanIterator ;
typedef  int /*<<< orphan*/  HeapTuple ;

/* Variables and functions */
 int /*<<< orphan*/  ts_scanner_end_scan (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline int64
int64_min(int64 a, int64 b)
{
	if (a <= b)
		return a;
	return b;
}

__attribute__((used)) static inline TupleInfo *
ts_scan_iterator_tuple_info(ScanIterator *iterator)
{
	return iterator->tinfo;
}

__attribute__((used)) static inline HeapTuple
ts_scan_iterator_tuple(ScanIterator *iterator)
{
	return iterator->tinfo->tuple;
}

__attribute__((used)) static inline TupleDesc
ts_scan_iterator_tupledesc(ScanIterator *iterator)
{
	return iterator->tinfo->desc;
}

void
ts_scan_iterator_close(ScanIterator *iterator)
{
	ts_scanner_end_scan(&iterator->ctx, &iterator->ictx);
}

