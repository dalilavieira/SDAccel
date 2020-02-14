#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  TYPE_2__* ssIOCtxPtr ;
struct TYPE_8__ {int (* getC ) (int /*<<< orphan*/ *) ;int (* getBuf ) (int /*<<< orphan*/ *,void*,int) ;void (* putC ) (int /*<<< orphan*/ *,int) ;int (* putBuf ) (int /*<<< orphan*/ *,void const*,int) ;void (* gd_free ) (int /*<<< orphan*/ *) ;int /*<<< orphan*/ * seek; int /*<<< orphan*/ * tell; } ;
struct TYPE_9__ {TYPE_5__* snk; TYPE_4__* src; TYPE_1__ ctx; } ;
typedef  TYPE_2__ ssIOCtx ;
typedef  TYPE_4__* gdSourcePtr ;
typedef  TYPE_5__* gdSinkPtr ;
typedef  int /*<<< orphan*/  gdIOCtx ;
struct TYPE_11__ {int (* sink ) (int /*<<< orphan*/ ,void const*,int) ;int /*<<< orphan*/  context; } ;
struct TYPE_10__ {int (* source ) (int /*<<< orphan*/ ,void*,int) ;int /*<<< orphan*/  context; } ;

/* Variables and functions */
 int EOF ; 
 int /*<<< orphan*/  gdFree (int /*<<< orphan*/ *) ; 
static  void gdFreeSsCtx (int /*<<< orphan*/ *) ; 
 scalar_t__ gdMalloc (int) ; 
static  int sinkPutbuf (int /*<<< orphan*/ *,void const*,int) ; 
static  void sinkPutchar (int /*<<< orphan*/ *,int) ; 
static  int sourceGetbuf (int /*<<< orphan*/ *,void*,int) ; 
static  int sourceGetchar (int /*<<< orphan*/ *) ; 
 int stub1 (int /*<<< orphan*/ ,void*,int) ; 
 int stub2 (int /*<<< orphan*/ ,void const*,int) ; 

gdIOCtx * gdNewSSCtx (gdSourcePtr src, gdSinkPtr snk)
{
	ssIOCtxPtr ctx;

	ctx = (ssIOCtxPtr) gdMalloc (sizeof (ssIOCtx));

	ctx->src = src;
	ctx->snk = snk;

	ctx->ctx.getC = sourceGetchar;
	ctx->ctx.getBuf = sourceGetbuf;

	ctx->ctx.putC = sinkPutchar;
	ctx->ctx.putBuf = sinkPutbuf;

	ctx->ctx.tell = NULL;
	ctx->ctx.seek = NULL;

	ctx->ctx.gd_free = gdFreeSsCtx;

	return (gdIOCtx *) ctx;
}

__attribute__((used)) static void gdFreeSsCtx (gdIOCtx * ctx)
{
	gdFree(ctx);
}

__attribute__((used)) static int sourceGetbuf (gdIOCtx * ctx, void *buf, int size)
{
	ssIOCtx *lctx;
	int res;

	lctx = (ssIOCtx *) ctx;

	res = ((lctx->src->source) (lctx->src->context, buf, size));

	/*
	 * Translate the return values from the Source object:
	 * 0 is EOF, -1 is error
	 */

	if (res == 0) {
		return EOF;
	} else if (res < 0) {
		return 0;
	} else {
		return res;
	}
}

__attribute__((used)) static int sourceGetchar (gdIOCtx * ctx)
{
	int res;
	unsigned char buf;

	res = sourceGetbuf (ctx, &buf, 1);

	if (res == 1) {
		return buf;
	} else {
		return EOF;
	}
}

__attribute__((used)) static int sinkPutbuf (gdIOCtx * ctx, const void *buf, int size)
{
	ssIOCtxPtr lctx;
	int res;

	lctx = (ssIOCtx *) ctx;

	res = (lctx->snk->sink) (lctx->snk->context, buf, size);

	if (res <= 0) {
		return 0;
	} else {
		return res;
	}
}

__attribute__((used)) static void sinkPutchar (gdIOCtx * ctx, int a)
{
	unsigned char b;

	b = a;
	sinkPutbuf (ctx, &b, 1);
}

