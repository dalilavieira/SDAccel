#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct TYPE_8__ {size_t avail_out; char* msg; size_t total_out; void* avail_in; int /*<<< orphan*/ * next_in; int /*<<< orphan*/ * next_out; void* zfree; void* zalloc; void* opaque; } ;
typedef  TYPE_1__ z_stream ;
typedef  int /*<<< orphan*/  uint8_t ;
typedef  void* uInt ;
typedef  int /*<<< orphan*/  Byte ;

/* Variables and functions */
 void* ZLIB_CHUNK ; 
 int /*<<< orphan*/  Z_FINISH ; 
 int /*<<< orphan*/  Z_NO_FLUSH ; 
 void* Z_NULL ; 
 int Z_OK ; 
 int Z_STREAM_END ; 
 int /*<<< orphan*/  assert (int) ; 
 int deflate (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int deflateEnd (TYPE_1__*) ; 
 int deflateInit (TYPE_1__*,int) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char*) ; 
 int /*<<< orphan*/  free (int /*<<< orphan*/ *) ; 
 int inflate (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int inflateEnd (TYPE_1__*) ; 
 int inflateInit (TYPE_1__*) ; 
 int /*<<< orphan*/ * malloc (size_t) ; 
 int /*<<< orphan*/ * realloc (int /*<<< orphan*/ *,size_t) ; 
 int /*<<< orphan*/  stderr ; 

uint8_t *zlib_decompress(const uint8_t *buf, size_t *len)
{
	size_t output_size = ZLIB_CHUNK;
	uint8_t *output = malloc(output_size);
	int err;
	z_stream zst;

	/* Sanity check */
	if (output == NULL) return NULL;
	assert(buf != NULL);

	/* Set inflate state */
	zst.zalloc = Z_NULL;
	zst.zfree = Z_NULL;
	zst.opaque = Z_NULL;
	zst.next_out = (Byte *)output;
	zst.next_in = (Byte *)buf;
	zst.avail_out = ZLIB_CHUNK;

	if (inflateInit(&zst) != Z_OK) goto error;

	/* Decompress input buffer */
	do {
		if ((err = inflate(&zst, Z_NO_FLUSH)) == Z_OK) { /* Need more memory */
			zst.avail_out = (uInt)output_size;

			/* Double size each time to avoid calls to realloc() */
			output_size <<= 1;
			output = realloc(output, output_size + 1);
			if (output == NULL) return NULL;

			zst.next_out = (Byte *)(output + zst.avail_out);
		} else if (err != Z_STREAM_END) { /* Error decompressing */
			if (zst.msg != NULL) {
				fprintf(stderr, "Could not decompress data: %s\n", zst.msg);
			}
			inflateEnd(&zst);
			goto error;
		}
	} while (err != Z_STREAM_END);

	if (len != NULL) *len = zst.total_out;
	if (inflateEnd(&zst) != Z_OK) goto error;
	return output; /* To be free()'d by caller */

error:
	if (output != NULL) free(output);
	return NULL;
}

uint8_t *zlib_compress(const uint8_t *buf, const size_t buflen, int level,
                       size_t *len)
{
	z_stream zst;
	uint8_t *output = NULL;

	/* Sanity check */
	assert(buf != NULL);
	assert(len != NULL);
	assert(level <= 9 && level >= 0);

	zst.avail_out = (uInt)((buflen + (buflen / 10)) + 12);
	output = malloc(zst.avail_out);
	if (output == NULL) return NULL;

	/* Set deflate state */
	zst.zalloc = Z_NULL;
	zst.zfree = Z_NULL;
	zst.next_out = (Byte *)output;
	zst.next_in = (Byte *)buf;
	zst.avail_in = (uInt)buflen;

	if (deflateInit(&zst, level) != Z_OK) goto error;

	/* Compress input buffer */
	if (deflate(&zst, Z_FINISH) != Z_STREAM_END) {
		if (zst.msg != NULL) {
			fprintf(stderr, "Could not compress data: %s\n", zst.msg);
		}
		deflateEnd(&zst);
		goto error;
	}

	if (len != NULL) *len = zst.total_out;
	if (deflateEnd(&zst) != Z_OK) goto error;
	return output; /* To be free()'d by caller */

error:
	if (output != NULL) free(output);
	return NULL;
}

