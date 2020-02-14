#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_28__   TYPE_4__ ;
typedef  struct TYPE_27__   TYPE_3__ ;
typedef  struct TYPE_26__   TYPE_2__ ;
typedef  struct TYPE_25__   TYPE_1__ ;
typedef  struct TYPE_24__   TYPE_14__ ;

/* Type definitions */
typedef  scalar_t__ int64 ;
struct TYPE_25__ {scalar_t__ count; int /*<<< orphan*/  tuple; int /*<<< orphan*/  ituple_desc; int /*<<< orphan*/  ituple; } ;
struct TYPE_27__ {TYPE_14__* index_scan; int /*<<< orphan*/  heap_scan; } ;
struct TYPE_28__ {TYPE_1__ tinfo; TYPE_2__* sctx; void* indexrel; void* tablerel; TYPE_3__ scan; } ;
struct TYPE_26__ {scalar_t__ limit; int /*<<< orphan*/  index; int /*<<< orphan*/  lockmode; int /*<<< orphan*/  scandirection; int /*<<< orphan*/  norderbys; int /*<<< orphan*/  nkeys; int /*<<< orphan*/  scankey; int /*<<< orphan*/  want_itup; int /*<<< orphan*/  table; } ;
struct TYPE_24__ {int /*<<< orphan*/  xs_itupdesc; int /*<<< orphan*/  xs_itup; int /*<<< orphan*/  xs_want_itup; } ;
typedef  TYPE_2__ ScannerCtx ;
typedef  int /*<<< orphan*/  Scanner ;
typedef  TYPE_3__ ScanDesc ;
typedef  void* Relation ;
typedef  TYPE_4__ InternalScannerCtx ;

/* Variables and functions */
 int HeapTupleIsValid (int /*<<< orphan*/ ) ; 
 scalar_t__ OidIsValid (int /*<<< orphan*/ ) ; 
 size_t ScannerTypeHeap ; 
 size_t ScannerTypeIndex ; 
 int /*<<< orphan*/  SnapshotSelf ; 
 int /*<<< orphan*/  heap_beginscan (void*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  heap_close (void*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  heap_endscan (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  heap_getnext (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 void* heap_open (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_14__* index_beginscan (void*,void*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  index_close (void*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  index_endscan (TYPE_14__*) ; 
 int /*<<< orphan*/  index_getnext (TYPE_14__*,int /*<<< orphan*/ ) ; 
 void* index_open (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  index_rescan (TYPE_14__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * scanners ; 

__attribute__((used)) static inline int64
int64_min(int64 a, int64 b)
{
	if (a <= b)
		return a;
	return b;
}

__attribute__((used)) static Relation
heap_scanner_open(InternalScannerCtx *ctx)
{
	ctx->tablerel = heap_open(ctx->sctx->table, ctx->sctx->lockmode);
	return ctx->tablerel;
}

__attribute__((used)) static ScanDesc
heap_scanner_beginscan(InternalScannerCtx *ctx)
{
	ScannerCtx *sctx = ctx->sctx;

	ctx->scan.heap_scan = heap_beginscan(ctx->tablerel, SnapshotSelf, sctx->nkeys, sctx->scankey);
	return ctx->scan;
}

__attribute__((used)) static bool
heap_scanner_getnext(InternalScannerCtx *ctx)
{
	ctx->tinfo.tuple = heap_getnext(ctx->scan.heap_scan, ctx->sctx->scandirection);
	return HeapTupleIsValid(ctx->tinfo.tuple);
}

__attribute__((used)) static void
heap_scanner_endscan(InternalScannerCtx *ctx)
{
	heap_endscan(ctx->scan.heap_scan);
}

__attribute__((used)) static void
heap_scanner_close(InternalScannerCtx *ctx)
{
	heap_close(ctx->tablerel, ctx->sctx->lockmode);
}

__attribute__((used)) static Relation
index_scanner_open(InternalScannerCtx *ctx)
{
	ctx->tablerel = heap_open(ctx->sctx->table, ctx->sctx->lockmode);
	ctx->indexrel = index_open(ctx->sctx->index, ctx->sctx->lockmode);
	return ctx->indexrel;
}

__attribute__((used)) static ScanDesc
index_scanner_beginscan(InternalScannerCtx *ctx)
{
	ScannerCtx *sctx = ctx->sctx;

	ctx->scan.index_scan =
		index_beginscan(ctx->tablerel, ctx->indexrel, SnapshotSelf, sctx->nkeys, sctx->norderbys);
	ctx->scan.index_scan->xs_want_itup = ctx->sctx->want_itup;
	index_rescan(ctx->scan.index_scan, sctx->scankey, sctx->nkeys, NULL, sctx->norderbys);
	return ctx->scan;
}

__attribute__((used)) static bool
index_scanner_getnext(InternalScannerCtx *ctx)
{
	ctx->tinfo.tuple = index_getnext(ctx->scan.index_scan, ctx->sctx->scandirection);
	ctx->tinfo.ituple = ctx->scan.index_scan->xs_itup;
	ctx->tinfo.ituple_desc = ctx->scan.index_scan->xs_itupdesc;
	return HeapTupleIsValid(ctx->tinfo.tuple);
}

__attribute__((used)) static void
index_scanner_endscan(InternalScannerCtx *ctx)
{
	index_endscan(ctx->scan.index_scan);
}

__attribute__((used)) static void
index_scanner_close(InternalScannerCtx *ctx)
{
	heap_close(ctx->tablerel, ctx->sctx->lockmode);
	index_close(ctx->indexrel, ctx->sctx->lockmode);
}

__attribute__((used)) static inline Scanner *
scanner_ctx_get_scanner(ScannerCtx *ctx)
{
	if (OidIsValid(ctx->index))
		return &scanners[ScannerTypeIndex];
	else
		return &scanners[ScannerTypeHeap];
}

__attribute__((used)) static inline bool
ts_scanner_limit_reached(ScannerCtx *ctx, InternalScannerCtx *ictx)
{
	return ctx->limit > 0 && ictx->tinfo.count >= ctx->limit;
}

