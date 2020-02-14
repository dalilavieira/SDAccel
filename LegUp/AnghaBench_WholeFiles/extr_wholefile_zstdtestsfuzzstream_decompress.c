#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
struct TYPE_7__ {int size; int /*<<< orphan*/  member_2; int /*<<< orphan*/  member_1; int /*<<< orphan*/ * member_0; } ;
typedef  TYPE_1__ ZSTD_outBuffer ;
struct TYPE_8__ {size_t size; scalar_t__ pos; int /*<<< orphan*/  member_2; int /*<<< orphan*/  member_1; int /*<<< orphan*/  const* member_0; } ;
typedef  TYPE_2__ ZSTD_inBuffer ;

/* Variables and functions */
 int /*<<< orphan*/  FUZZ_ASSERT (int) ; 
 int /*<<< orphan*/  FUZZ_ZASSERT (int /*<<< orphan*/ ) ; 
 size_t FUZZ_rand (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  FUZZ_seed (int /*<<< orphan*/  const**,size_t*) ; 
 int /*<<< orphan*/  ZSTD_DCtx_reset (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * ZSTD_createDStream () ; 
 size_t ZSTD_decompressStream (int /*<<< orphan*/ *,TYPE_1__*,TYPE_2__*) ; 
 int /*<<< orphan*/  ZSTD_freeDStream (int /*<<< orphan*/ *) ; 
 scalar_t__ ZSTD_isError (size_t const) ; 
 int /*<<< orphan*/  ZSTD_reset_session_only ; 
 int /*<<< orphan*/ * buf ; 
 int /*<<< orphan*/ * dstream ; 
 int kBufSize ; 
 int /*<<< orphan*/ * malloc (int) ; 
 int /*<<< orphan*/  seed ; 

__attribute__((used)) static ZSTD_outBuffer makeOutBuffer(void)
{
  ZSTD_outBuffer buffer = { buf, 0, 0 };

  buffer.size = (FUZZ_rand(&seed) % kBufSize) + 1;
  FUZZ_ASSERT(buffer.size <= kBufSize);

  return buffer;
}

__attribute__((used)) static ZSTD_inBuffer makeInBuffer(const uint8_t **src, size_t *size)
{
  ZSTD_inBuffer buffer = { *src, 0, 0 };

  FUZZ_ASSERT(*size > 0);
  buffer.size = (FUZZ_rand(&seed) % *size) + 1;
  FUZZ_ASSERT(buffer.size <= *size);
  *src += buffer.size;
  *size -= buffer.size;

  return buffer;
}

int LLVMFuzzerTestOneInput(const uint8_t *src, size_t size)
{
    seed = FUZZ_seed(&src, &size);

    /* Allocate all buffers and contexts if not already allocated */
    if (!buf) {
      buf = malloc(kBufSize);
      FUZZ_ASSERT(buf);
    }

    if (!dstream) {
        dstream = ZSTD_createDStream();
        FUZZ_ASSERT(dstream);
    } else {
        FUZZ_ZASSERT(ZSTD_DCtx_reset(dstream, ZSTD_reset_session_only));
    }

    while (size > 0) {
        ZSTD_inBuffer in = makeInBuffer(&src, &size);
        while (in.pos != in.size) {
            ZSTD_outBuffer out = makeOutBuffer();
            size_t const rc = ZSTD_decompressStream(dstream, &out, &in);
            if (ZSTD_isError(rc)) goto error;
        }
    }

error:
#ifndef STATEFUL_FUZZING
    ZSTD_freeDStream(dstream); dstream = NULL;
#endif
    return 0;
}

