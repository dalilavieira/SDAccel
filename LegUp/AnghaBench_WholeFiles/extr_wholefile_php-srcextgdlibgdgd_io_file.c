#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct gdIOCtx {int dummy; } ;
typedef  int /*<<< orphan*/  gdIOCtx ;
struct TYPE_3__ {int (* getC ) (int /*<<< orphan*/ *) ;void (* putC ) (int /*<<< orphan*/ *,int) ;int (* getBuf ) (int /*<<< orphan*/ *,void*,int) ;int (* putBuf ) (int /*<<< orphan*/ *,void const*,int) ;long (* tell ) (struct gdIOCtx*) ;int (* seek ) (struct gdIOCtx*,int const) ;void (* gd_free ) (int /*<<< orphan*/ *) ;} ;
struct TYPE_4__ {int /*<<< orphan*/ * f; TYPE_1__ ctx; } ;
typedef  TYPE_2__ fileIOCtx ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int /*<<< orphan*/  SEEK_SET ; 
static  int fileGetbuf (int /*<<< orphan*/ *,void*,int) ; 
static  int fileGetchar (int /*<<< orphan*/ *) ; 
static  int filePutbuf (int /*<<< orphan*/ *,void const*,int) ; 
static  void filePutchar (int /*<<< orphan*/ *,int) ; 
static  int fileSeek (struct gdIOCtx*,int const) ; 
static  long fileTell (struct gdIOCtx*) ; 
 int fread (void*,int,int,int /*<<< orphan*/ *) ; 
 scalar_t__ fseek (int /*<<< orphan*/ *,int const,int /*<<< orphan*/ ) ; 
 long ftell (int /*<<< orphan*/ *) ; 
 int fwrite (void const*,int,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  gdFree (int /*<<< orphan*/ *) ; 
static  void gdFreeFileCtx (int /*<<< orphan*/ *) ; 
 scalar_t__ gdMalloc (int) ; 
 int getc (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  putc (unsigned char,int /*<<< orphan*/ *) ; 

gdIOCtx * gdNewFileCtx (FILE * f)
{
	fileIOCtx *ctx;

	ctx = (fileIOCtx *) gdMalloc(sizeof (fileIOCtx));

	ctx->f = f;

	ctx->ctx.getC = fileGetchar;
	ctx->ctx.putC = filePutchar;

	ctx->ctx.getBuf = fileGetbuf;
	ctx->ctx.putBuf = filePutbuf;

	ctx->ctx.tell = fileTell;
	ctx->ctx.seek = fileSeek;

	ctx->ctx.gd_free = gdFreeFileCtx;

	return (gdIOCtx *) ctx;
}

__attribute__((used)) static void gdFreeFileCtx (gdIOCtx * ctx)
{
	gdFree(ctx);
}

__attribute__((used)) static int filePutbuf (gdIOCtx * ctx, const void *buf, int size)
{
	fileIOCtx *fctx;
	fctx = (fileIOCtx *) ctx;

	return fwrite(buf, 1, size, fctx->f);

}

__attribute__((used)) static int fileGetbuf (gdIOCtx * ctx, void *buf, int size)
{
	fileIOCtx *fctx;
	fctx = (fileIOCtx *) ctx;

	return fread(buf, 1, size, fctx->f);
}

__attribute__((used)) static void filePutchar (gdIOCtx * ctx, int a)
{
	unsigned char b;
	fileIOCtx *fctx;
	fctx = (fileIOCtx *) ctx;

	b = a;

	putc (b, fctx->f);
}

__attribute__((used)) static int fileGetchar (gdIOCtx * ctx)
{
	fileIOCtx *fctx;
	fctx = (fileIOCtx *) ctx;

	return getc (fctx->f);
}

__attribute__((used)) static int fileSeek (struct gdIOCtx *ctx, const int pos)
{
	fileIOCtx *fctx;
	fctx = (fileIOCtx *) ctx;

	return (fseek (fctx->f, pos, SEEK_SET) == 0);
}

__attribute__((used)) static long fileTell (struct gdIOCtx *ctx)
{
	fileIOCtx *fctx;
	fctx = (fileIOCtx *) ctx;

	return ftell (fctx->f);
}

