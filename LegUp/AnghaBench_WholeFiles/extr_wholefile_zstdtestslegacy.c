#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {char* const member_0; size_t const member_1; size_t const pos; size_t size; int /*<<< orphan*/  member_2; } ;
typedef  TYPE_1__ ZSTD_outBuffer ;
struct TYPE_6__ {char* member_0; size_t member_1; scalar_t__ pos; scalar_t__ size; int /*<<< orphan*/  member_2; } ;
typedef  TYPE_2__ ZSTD_inBuffer ;
typedef  int /*<<< orphan*/  ZSTD_DStream ;

/* Variables and functions */
 char* COMPRESSED ; 
 size_t COMPRESSED_SIZE ; 
 int /*<<< orphan*/  DISPLAY (char*,...) ; 
 char* const EXPECTED ; 
 size_t ZSTD_DStreamOutSize () ; 
 int /*<<< orphan*/ * ZSTD_createDStream () ; 
 size_t ZSTD_decompress (char* const,size_t const,char*,size_t) ; 
 size_t ZSTD_decompressBound (char*,size_t) ; 
 size_t ZSTD_decompressStream (int /*<<< orphan*/ * const,TYPE_1__*,TYPE_2__*) ; 
 size_t const ZSTD_error_prefix_unknown ; 
 size_t ZSTD_findFrameCompressedSize (char const*,size_t) ; 
 int /*<<< orphan*/  ZSTD_freeDStream (int /*<<< orphan*/ * const) ; 
 int /*<<< orphan*/  ZSTD_getErrorName (size_t const) ; 
 size_t ZSTD_initDStream (int /*<<< orphan*/ * const) ; 
 scalar_t__ ZSTD_isError (size_t const) ; 
 int /*<<< orphan*/  free (char* const) ; 
 char* malloc (size_t const) ; 
 scalar_t__ memcmp (char* const,char* const,size_t const) ; 
 size_t strlen (char* const) ; 

__attribute__((used)) static int testSimpleAPI(void)
{
    size_t const size = strlen(EXPECTED);
    char* const output = malloc(size);

    if (!output) {
        DISPLAY("ERROR: Not enough memory!\n");
        return 1;
    }

    {
        size_t const ret = ZSTD_decompress(output, size, COMPRESSED, COMPRESSED_SIZE);
        if (ZSTD_isError(ret)) {
            if (ret == ZSTD_error_prefix_unknown) {
                DISPLAY("ERROR: Invalid frame magic number, was this compiled "
                        "without legacy support?\n");
            } else {
                DISPLAY("ERROR: %s\n", ZSTD_getErrorName(ret));
            }
            return 1;
        }
        if (ret != size) {
            DISPLAY("ERROR: Wrong decoded size\n");
        }
    }
    if (memcmp(EXPECTED, output, size) != 0) {
        DISPLAY("ERROR: Wrong decoded output produced\n");
        return 1;
    }

    free(output);
    DISPLAY("Simple API OK\n");
    return 0;
}

__attribute__((used)) static int testStreamingAPI(void)
{
    int error_code = 0;
    size_t const outBuffSize = ZSTD_DStreamOutSize();
    char* const outBuff = malloc(outBuffSize);
    ZSTD_DStream* const stream = ZSTD_createDStream();
    ZSTD_inBuffer input = { COMPRESSED, COMPRESSED_SIZE, 0 };
    size_t outputPos = 0;
    int needsInit = 1;

    if (outBuff == NULL) {
        DISPLAY("ERROR: Could not allocate memory\n");
        return 1;
    }
    if (stream == NULL) {
        DISPLAY("ERROR: Could not create dstream\n");
        free(outBuff);
        return 1;
    }

    while (1) {
        ZSTD_outBuffer output = {outBuff, outBuffSize, 0};
        if (needsInit) {
            size_t const ret = ZSTD_initDStream(stream);
            if (ZSTD_isError(ret)) {
                DISPLAY("ERROR: ZSTD_initDStream: %s\n", ZSTD_getErrorName(ret));
                error_code = 1;
                break;
        }   }

        {   size_t const ret = ZSTD_decompressStream(stream, &output, &input);
            if (ZSTD_isError(ret)) {
                DISPLAY("ERROR: ZSTD_decompressStream: %s\n", ZSTD_getErrorName(ret));
                error_code = 1;
                break;
            }

            if (ret == 0) {
                needsInit = 1;
        }   }

        if (memcmp(outBuff, EXPECTED + outputPos, output.pos) != 0) {
            DISPLAY("ERROR: Wrong decoded output produced\n");
            error_code = 1;
            break;
        }
        outputPos += output.pos;
        if (input.pos == input.size && output.pos < output.size) {
            break;
        }
    }

    free(outBuff);
    ZSTD_freeDStream(stream);
    if (error_code == 0) DISPLAY("Streaming API OK\n");
    return error_code;
}

__attribute__((used)) static int testFrameDecoding(void)
{
    if (strlen(EXPECTED) > ZSTD_decompressBound(COMPRESSED, COMPRESSED_SIZE)) {
        DISPLAY("ERROR: ZSTD_decompressBound: decompressed bound too small\n");
        return 1;
    }
    {   const char* ip = COMPRESSED;
        size_t remainingSize = COMPRESSED_SIZE;
        while (1) {
            size_t frameSize = ZSTD_findFrameCompressedSize(ip, remainingSize);
            if (ZSTD_isError(frameSize)) {
                DISPLAY("ERROR: ZSTD_findFrameCompressedSize: %s\n", ZSTD_getErrorName(frameSize));
                return 1;
            }
            if (frameSize > remainingSize) {
                DISPLAY("ERROR: ZSTD_findFrameCompressedSize: expected frameSize to align with src buffer");
                return 1;
            }
            ip += frameSize;
            remainingSize -= frameSize;
            if (remainingSize == 0) break;
        }
    }
    DISPLAY("Frame Decoding OK\n");
    return 0;
}

int main(void)
{
    {   int const ret = testSimpleAPI();
        if (ret) return ret; }
    {   int const ret = testStreamingAPI();
        if (ret) return ret; }
    {   int const ret = testFrameDecoding();
        if (ret) return ret; }

    DISPLAY("OK\n");
    return 0;
}

