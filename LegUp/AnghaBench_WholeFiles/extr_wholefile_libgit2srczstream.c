#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_27__   TYPE_5__ ;
typedef  struct TYPE_26__   TYPE_2__ ;
typedef  struct TYPE_25__   TYPE_1__ ;

/* Type definitions */
typedef  void* uInt ;
typedef  scalar_t__ git_zstream_t ;
struct TYPE_27__ {size_t avail_in; size_t avail_out; void* next_out; int /*<<< orphan*/ * next_in; } ;
struct TYPE_25__ {scalar_t__ type; scalar_t__ zerr; size_t in_len; scalar_t__ flush; TYPE_5__ z; int /*<<< orphan*/ * in; } ;
typedef  TYPE_1__ git_zstream ;
struct TYPE_26__ {size_t asize; size_t size; char* ptr; } ;
typedef  TYPE_2__ git_buf ;
typedef  int /*<<< orphan*/  Bytef ;

/* Variables and functions */
 int /*<<< orphan*/  GIT_ERROR_ZLIB ; 
 scalar_t__ GIT_ZSTREAM_DEFLATE ; 
 scalar_t__ GIT_ZSTREAM_INFLATE ; 
 TYPE_1__ GIT_ZSTREAM_INIT ; 
 scalar_t__ UINT_MAX ; 
 scalar_t__ ZSTREAM_BUFFER_MIN_EXTRA ; 
 scalar_t__ ZSTREAM_BUFFER_SIZE ; 
 int /*<<< orphan*/  Z_DEFAULT_COMPRESSION ; 
 scalar_t__ Z_FINISH ; 
 scalar_t__ Z_NO_FLUSH ; 
 scalar_t__ Z_OK ; 
 scalar_t__ Z_STREAM_END ; 
 int /*<<< orphan*/  assert (int) ; 
 scalar_t__ deflate (TYPE_5__*,scalar_t__) ; 
 int /*<<< orphan*/  deflateEnd (TYPE_5__*) ; 
 scalar_t__ deflateInit (TYPE_5__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  deflateReset (TYPE_5__*) ; 
 int git_buf_grow_by (TYPE_2__*,size_t) ; 
 int /*<<< orphan*/  git_error_set (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  git_zstream_done (TYPE_1__*) ; 
 scalar_t__ inflate (TYPE_5__*,scalar_t__) ; 
 int /*<<< orphan*/  inflateEnd (TYPE_5__*) ; 
 scalar_t__ inflateInit (TYPE_5__*) ; 
 int /*<<< orphan*/  inflateReset (TYPE_5__*) ; 
 int zstream_seterr (TYPE_1__*) ; 

int git_zstream_init(git_zstream *zstream, git_zstream_t type)
{
	zstream->type = type;

	if (zstream->type == GIT_ZSTREAM_INFLATE)
		zstream->zerr = inflateInit(&zstream->z);
	else
		zstream->zerr = deflateInit(&zstream->z, Z_DEFAULT_COMPRESSION);
	return zstream_seterr(zstream);
}

void git_zstream_free(git_zstream *zstream)
{
	if (zstream->type == GIT_ZSTREAM_INFLATE)
		inflateEnd(&zstream->z);
	else
		deflateEnd(&zstream->z);
}

void git_zstream_reset(git_zstream *zstream)
{
	if (zstream->type == GIT_ZSTREAM_INFLATE)
		inflateReset(&zstream->z);
	else
		deflateReset(&zstream->z);
	zstream->in = NULL;
	zstream->in_len = 0;
	zstream->zerr = Z_STREAM_END;
}

int git_zstream_set_input(git_zstream *zstream, const void *in, size_t in_len)
{
	zstream->in = in;
	zstream->in_len = in_len;
	zstream->zerr = Z_OK;
	return 0;
}

size_t git_zstream_suggest_output_len(git_zstream *zstream)
{
	if (zstream->in_len > ZSTREAM_BUFFER_SIZE)
		return ZSTREAM_BUFFER_SIZE;
	else if (zstream->in_len > ZSTREAM_BUFFER_MIN_EXTRA)
		return zstream->in_len;
	else
		return ZSTREAM_BUFFER_MIN_EXTRA;
}

int git_zstream_get_output_chunk(
	void *out, size_t *out_len, git_zstream *zstream)
{
	size_t in_queued, in_used, out_queued;

	/* set up input data */
	zstream->z.next_in = (Bytef *)zstream->in;

	/* feed as much data to zlib as it can consume, at most UINT_MAX */
	if (zstream->in_len > UINT_MAX) {
		zstream->z.avail_in = UINT_MAX;
		zstream->flush = Z_NO_FLUSH;
	} else {
		zstream->z.avail_in = (uInt)zstream->in_len;
		zstream->flush = Z_FINISH;
	}
	in_queued = (size_t)zstream->z.avail_in;

	/* set up output data */
	zstream->z.next_out = out;
	zstream->z.avail_out = (uInt)*out_len;

	if ((size_t)zstream->z.avail_out != *out_len)
		zstream->z.avail_out = UINT_MAX;
	out_queued = (size_t)zstream->z.avail_out;

	/* compress next chunk */
	if (zstream->type == GIT_ZSTREAM_INFLATE)
		zstream->zerr = inflate(&zstream->z, zstream->flush);
	else
		zstream->zerr = deflate(&zstream->z, zstream->flush);

	if (zstream_seterr(zstream))
		return -1;

	in_used = (in_queued - zstream->z.avail_in);
	zstream->in_len -= in_used;
	zstream->in += in_used;

	*out_len = (out_queued - zstream->z.avail_out);

	return 0;
}

int git_zstream_get_output(void *out, size_t *out_len, git_zstream *zstream)
{
	size_t out_remain = *out_len;

	if (zstream->in_len && zstream->zerr == Z_STREAM_END) {
		git_error_set(GIT_ERROR_ZLIB, "zlib input had trailing garbage");
		return -1;
	}

	while (out_remain > 0 && zstream->zerr != Z_STREAM_END) {
		size_t out_written = out_remain;

		if (git_zstream_get_output_chunk(out, &out_written, zstream) < 0)
			return -1;

		out_remain -= out_written;
		out = ((char *)out) + out_written;
	}

	/* either we finished the input or we did not flush the data */
	assert(zstream->in_len > 0 || zstream->flush == Z_FINISH);

	/* set out_size to number of bytes actually written to output */
	*out_len = *out_len - out_remain;

	return 0;
}

__attribute__((used)) static int zstream_buf(git_buf *out, const void *in, size_t in_len, git_zstream_t type)
{
	git_zstream zs = GIT_ZSTREAM_INIT;
	int error = 0;

	if ((error = git_zstream_init(&zs, type)) < 0)
		return error;

	if ((error = git_zstream_set_input(&zs, in, in_len)) < 0)
		goto done;

	while (!git_zstream_done(&zs)) {
		size_t step = git_zstream_suggest_output_len(&zs), written;

		if ((error = git_buf_grow_by(out, step)) < 0)
			goto done;

		written = out->asize - out->size;

		if ((error = git_zstream_get_output(
				out->ptr + out->size, &written, &zs)) < 0)
			goto done;

		out->size += written;
	}

	/* NULL terminate for consistency if possible */
	if (out->size < out->asize)
		out->ptr[out->size] = '\0';

done:
	git_zstream_free(&zs);
	return error;
}

int git_zstream_deflatebuf(git_buf *out, const void *in, size_t in_len)
{
	return zstream_buf(out, in, in_len, GIT_ZSTREAM_DEFLATE);
}

int git_zstream_inflatebuf(git_buf *out, const void *in, size_t in_len)
{
	return zstream_buf(out, in, in_len, GIT_ZSTREAM_INFLATE);
}

