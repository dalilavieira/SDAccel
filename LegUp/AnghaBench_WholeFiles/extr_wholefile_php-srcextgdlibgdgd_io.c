#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_44__   TYPE_1__ ;

/* Type definitions */
struct TYPE_44__ {int (* putBuf ) (TYPE_1__*,char*,int) ;int (* getC ) (TYPE_1__*) ;int (* getBuf ) (TYPE_1__*,void*,int) ;int (* seek ) (TYPE_1__*,int const) ;long (* tell ) (TYPE_1__*) ;int /*<<< orphan*/  (* putC ) (TYPE_1__*,unsigned char) ;} ;
typedef  TYPE_1__ gdIOCtx ;

/* Variables and functions */
 int EOF ; 
 int /*<<< orphan*/  GD_IO_EOF_CHK (int) ; 
 int /*<<< orphan*/  IO_DBG (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gd_error (char*) ; 
 int stub1 (TYPE_1__*,char*,int) ; 
 int stub10 (TYPE_1__*) ; 
 int stub11 (TYPE_1__*) ; 
 int stub12 (TYPE_1__*) ; 
 int stub13 (TYPE_1__*) ; 
 int stub14 (TYPE_1__*) ; 
 int stub15 (TYPE_1__*) ; 
 int stub16 (TYPE_1__*) ; 
 int stub17 (TYPE_1__*) ; 
 int stub18 (TYPE_1__*) ; 
 int stub19 (TYPE_1__*) ; 
 int /*<<< orphan*/  stub2 (TYPE_1__*,int) ; 
 int stub20 (TYPE_1__*) ; 
 int stub21 (TYPE_1__*) ; 
 int stub22 (TYPE_1__*) ; 
 int stub23 (TYPE_1__*) ; 
 int stub24 (TYPE_1__*,void const*,int) ; 
 int stub25 (TYPE_1__*,void*,int) ; 
 int stub26 (TYPE_1__*,int const) ; 
 long stub27 (TYPE_1__*) ; 
 int /*<<< orphan*/  stub3 (TYPE_1__*,unsigned char const) ; 
 int /*<<< orphan*/  stub4 (TYPE_1__*,unsigned char) ; 
 int /*<<< orphan*/  stub5 (TYPE_1__*,unsigned char) ; 
 int /*<<< orphan*/  stub6 (TYPE_1__*,unsigned char) ; 
 int /*<<< orphan*/  stub7 (TYPE_1__*,unsigned char) ; 
 int /*<<< orphan*/  stub8 (TYPE_1__*,unsigned char) ; 
 int /*<<< orphan*/  stub9 (TYPE_1__*,unsigned char) ; 

void Putword (int w, gdIOCtx * ctx)
{
	unsigned char buf[2];

	buf[0] = w & 0xff;
	buf[1] = (w / 256) & 0xff;
	(ctx->putBuf) (ctx, (char *) buf, 2);
}

void Putchar (int c, gdIOCtx * ctx)
{
	(ctx->putC) (ctx, c & 0xff);
}

void gdPutC (const unsigned char c, gdIOCtx * ctx)
{
	(ctx->putC) (ctx, c);
}

void gdPutWord (int w, gdIOCtx * ctx)
{
	IO_DBG (gd_error("Putting word..."));
	(ctx->putC) (ctx, (unsigned char) (w >> 8));
	(ctx->putC) (ctx, (unsigned char) (w & 0xFF));
	IO_DBG (gd_error("put."));
}

void gdPutInt (int w, gdIOCtx * ctx)
{
	IO_DBG (gd_error("Putting int..."));
	(ctx->putC) (ctx, (unsigned char) (w >> 24));
	(ctx->putC) (ctx, (unsigned char) ((w >> 16) & 0xFF));
	(ctx->putC) (ctx, (unsigned char) ((w >> 8) & 0xFF));
	(ctx->putC) (ctx, (unsigned char) (w & 0xFF));
	IO_DBG (gd_error("put."));
}

int gdGetC (gdIOCtx * ctx)
{
	return ((ctx->getC) (ctx));
}

int gdGetByte (int *result, gdIOCtx * ctx)
{
	int r;
	r = (ctx->getC) (ctx);
	GD_IO_EOF_CHK(r);
	*result = r;
	return 1;
}

int gdGetWord (int *result, gdIOCtx * ctx)
{
	int r;
	r = (ctx->getC) (ctx);
	GD_IO_EOF_CHK(r);
	*result = r << 8;
	r = (ctx->getC) (ctx);
	GD_IO_EOF_CHK(r);
	*result += r;
	return 1;
}

int gdGetWordLSB(signed short int *result, gdIOCtx *ctx)
{
	int high = 0, low = 0;
	low = (ctx->getC) (ctx);
	if (low == EOF) {
		return 0;
	}

	high = (ctx->getC) (ctx);
	if (high == EOF) {
		return 0;
	}

	if (result) {
		*result = (high << 8) | low;
	}

	return 1;
}

int gdGetInt (int *result, gdIOCtx * ctx)
{
	int r;
	r = (ctx->getC) (ctx);
	GD_IO_EOF_CHK(r);
	*result = r << 24;

	r = (ctx->getC) (ctx);
	GD_IO_EOF_CHK(r);
	*result += r << 16;

	r = (ctx->getC) (ctx);
	if (r == EOF) {
		return 0;
	}
	*result += r << 8;

	r = (ctx->getC) (ctx);
	GD_IO_EOF_CHK(r);
	*result += r;

	return 1;
}

int gdGetIntLSB(signed int *result, gdIOCtx *ctx)
{
	int c = 0;
	unsigned int r = 0;

	c = (ctx->getC) (ctx);
	if (c == EOF) {
		return 0;
	}
	r |= (c << 24);
	r >>= 8;

	c = (ctx->getC) (ctx);
	if (c == EOF) {
		return 0;
	}
	r |= (c << 24);
	r >>= 8;

	c = (ctx->getC) (ctx);
	if (c == EOF) {
		return 0;
	}
	r |= (c << 24);
	r >>= 8;

	c = (ctx->getC) (ctx);
	if (c == EOF) {
		return 0;
	}
	r |= (c << 24);

	if (result) {
		*result = (signed int)r;
	}

	return 1;
}

int gdPutBuf (const void *buf, int size, gdIOCtx * ctx)
{
	IO_DBG (gd_error("Putting buf..."));
	return (ctx->putBuf) (ctx, buf, size);
	IO_DBG (gd_error("put."));
}

int gdGetBuf (void *buf, int size, gdIOCtx * ctx)
{
	return (ctx->getBuf) (ctx, buf, size);
}

int gdSeek (gdIOCtx * ctx, const int pos)
{
	IO_DBG (gd_error("Seeking..."));
	return ((ctx->seek) (ctx, pos));
	IO_DBG (gd_error("Done."));
}

long gdTell (gdIOCtx * ctx)
{
	IO_DBG (gd_error("Telling..."));
	return ((ctx->tell) (ctx));
	IO_DBG (gd_error ("told."));
}

