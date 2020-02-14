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
struct stat {scalar_t__ st_size; } ;
typedef  scalar_t__ off_t ;
typedef  int /*<<< orphan*/  decompressedData ;
typedef  int /*<<< orphan*/  dataToCompress ;
typedef  int /*<<< orphan*/  compressedData ;
struct TYPE_8__ {char* member_0; int member_1; size_t pos; int /*<<< orphan*/  member_2; } ;
typedef  TYPE_1__ ZSTD_outBuffer ;
struct TYPE_9__ {char const* member_0; int member_1; int /*<<< orphan*/  member_2; } ;
typedef  TYPE_2__ ZSTD_inBuffer ;
typedef  int /*<<< orphan*/  ZSTD_DCtx ;
typedef  int /*<<< orphan*/  ZSTD_CCtx_params ;
typedef  int /*<<< orphan*/  ZSTD_CCtx ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int /*<<< orphan*/  CHECK (int,char*,...) ; 
 int /*<<< orphan*/  CHECK_ZSTD (size_t const) ; 
 int /*<<< orphan*/  ERROR_fclose ; 
 int /*<<< orphan*/  ERROR_fopen ; 
 int /*<<< orphan*/  ERROR_fread ; 
 int /*<<< orphan*/  ERROR_fsize ; 
 int /*<<< orphan*/  ERROR_fwrite ; 
 int /*<<< orphan*/  ERROR_largeFile ; 
 int /*<<< orphan*/  ERROR_malloc ; 
 int MAX_TESTED_LEVEL ; 
 size_t const ZSTD_CCtxParams_setParameter (int /*<<< orphan*/ * const,int /*<<< orphan*/ ,unsigned int) ; 
 size_t const ZSTD_CCtx_setParametersUsingCCtxParams (int /*<<< orphan*/ * const,int /*<<< orphan*/ * const) ; 
 size_t const ZSTD_DCtx_setParameter (int /*<<< orphan*/ * const,int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  ZSTD_c_compressionLevel ; 
 int /*<<< orphan*/  ZSTD_c_windowLog ; 
 size_t const ZSTD_compressStream (int /*<<< orphan*/ * const,TYPE_1__*,TYPE_2__*) ; 
 int /*<<< orphan*/ * ZSTD_createCCtx () ; 
 int /*<<< orphan*/ * ZSTD_createCCtxParams () ; 
 int /*<<< orphan*/ * ZSTD_createDCtx () ; 
 int /*<<< orphan*/  ZSTD_d_windowLogMax ; 
 size_t ZSTD_decompressStream (int /*<<< orphan*/ * const,TYPE_1__*,TYPE_2__*) ; 
 size_t ZSTD_endStream (int /*<<< orphan*/ * const,TYPE_1__*) ; 
 size_t ZSTD_estimateCStreamSize_usingCCtxParams (int /*<<< orphan*/ * const) ; 
 size_t ZSTD_estimateDStreamSize_fromFrame (char*,size_t) ; 
 int /*<<< orphan*/  ZSTD_freeCCtx (int /*<<< orphan*/ * const) ; 
 int /*<<< orphan*/  ZSTD_freeCCtxParams (int /*<<< orphan*/ * const) ; 
 int /*<<< orphan*/  ZSTD_freeDCtx (int /*<<< orphan*/ * const) ; 
 size_t ZSTD_sizeof_CStream (int /*<<< orphan*/ * const) ; 
 size_t ZSTD_sizeof_DStream (int /*<<< orphan*/ * const) ; 
 char* ZSTD_versionString () ; 
 int /*<<< orphan*/  errno ; 
 int /*<<< orphan*/  exit (int /*<<< orphan*/ ) ; 
 scalar_t__ fclose (int /*<<< orphan*/ * const) ; 
 scalar_t__ feof (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * fopen (char const*,char const*) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char const*,...) ; 
 size_t fread (void*,int,size_t const,int /*<<< orphan*/ * const) ; 
 size_t fwrite (void const*,int,size_t,int /*<<< orphan*/ * const) ; 
 void* malloc (size_t) ; 
 int /*<<< orphan*/  perror (char const*) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 scalar_t__ stat (char const*,struct stat*) ; 
 int /*<<< orphan*/  stderr ; 
 char* strerror (int /*<<< orphan*/ ) ; 

__attribute__((used)) static size_t fsize_orDie(const char *filename)
{
    struct stat st;
    if (stat(filename, &st) != 0) {
        /* error */
        perror(filename);
        exit(ERROR_fsize);
    }

    off_t const fileSize = st.st_size;
    size_t const size = (size_t)fileSize;
    /* 1. fileSize should be non-negative,
     * 2. if off_t -> size_t type conversion results in discrepancy,
     *    the file size is too large for type size_t.
     */
    if ((fileSize < 0) || (fileSize != (off_t)size)) {
        fprintf(stderr, "%s : filesize too large \n", filename);
        exit(ERROR_largeFile);
    }
    return size;
}

__attribute__((used)) static FILE* fopen_orDie(const char *filename, const char *instruction)
{
    FILE* const inFile = fopen(filename, instruction);
    if (inFile) return inFile;
    /* error */
    perror(filename);
    exit(ERROR_fopen);
}

__attribute__((used)) static void fclose_orDie(FILE* file)
{
    if (!fclose(file)) { return; };
    /* error */
    perror("fclose");
    exit(ERROR_fclose);
}

__attribute__((used)) static size_t fread_orDie(void* buffer, size_t sizeToRead, FILE* file)
{
    size_t const readSize = fread(buffer, 1, sizeToRead, file);
    if (readSize == sizeToRead) return readSize;   /* good */
    if (feof(file)) return readSize;   /* good, reached end of file */
    /* error */
    perror("fread");
    exit(ERROR_fread);
}

__attribute__((used)) static size_t fwrite_orDie(const void* buffer, size_t sizeToWrite, FILE* file)
{
    size_t const writtenSize = fwrite(buffer, 1, sizeToWrite, file);
    if (writtenSize == sizeToWrite) return sizeToWrite;   /* good */
    /* error */
    perror("fwrite");
    exit(ERROR_fwrite);
}

__attribute__((used)) static void* malloc_orDie(size_t size)
{
    void* const buff = malloc(size);
    if (buff) return buff;
    /* error */
    perror("malloc");
    exit(ERROR_malloc);
}

__attribute__((used)) static size_t loadFile_orDie(const char* fileName, void* buffer, size_t bufferSize)
{
    size_t const fileSize = fsize_orDie(fileName);
    CHECK(fileSize <= bufferSize, "File too large!");

    FILE* const inFile = fopen_orDie(fileName, "rb");
    size_t const readSize = fread(buffer, 1, fileSize, inFile);
    if (readSize != (size_t)fileSize) {
        fprintf(stderr, "fread: %s : %s \n", fileName, strerror(errno));
        exit(ERROR_fread);
    }
    fclose(inFile);  /* can't fail, read only */
    return fileSize;
}

__attribute__((used)) static void* mallocAndLoadFile_orDie(const char* fileName, size_t* bufferSize) {
    size_t const fileSize = fsize_orDie(fileName);
    *bufferSize = fileSize;
    void* const buffer = malloc_orDie(*bufferSize);
    loadFile_orDie(fileName, buffer, *bufferSize);
    return buffer;
}

__attribute__((used)) static void saveFile_orDie(const char* fileName, const void* buff, size_t buffSize)
{
    FILE* const oFile = fopen_orDie(fileName, "wb");
    size_t const wSize = fwrite(buff, 1, buffSize, oFile);
    if (wSize != (size_t)buffSize) {
        fprintf(stderr, "fwrite: %s : %s \n", fileName, strerror(errno));
        exit(ERROR_fwrite);
    }
    if (fclose(oFile)) {
        perror(fileName);
        exit(ERROR_fclose);
    }
}

__attribute__((used)) static unsigned readU32FromChar(const char** stringPtr)
{
    unsigned result = 0;
    while ((**stringPtr >='0') && (**stringPtr <='9'))
        result *= 10, result += **stringPtr - '0', (*stringPtr)++ ;
    if ((**stringPtr=='K') || (**stringPtr=='M')) {
        result <<= 10;
        if (**stringPtr=='M') result <<= 10;
        (*stringPtr)++ ;
        if (**stringPtr=='i') (*stringPtr)++;
        if (**stringPtr=='B') (*stringPtr)++;
    }
    return result;
}

int main(int argc, char const *argv[]) {

    printf("\n Zstandard (v%s) memory usage for streaming : \n\n", ZSTD_versionString());

    unsigned wLog = 0;
    if (argc > 1) {
        const char* valStr = argv[1];
        wLog = readU32FromChar(&valStr);
    }

    int compressionLevel;
    for (compressionLevel = 1; compressionLevel <= MAX_TESTED_LEVEL; compressionLevel++) {
#define INPUT_SIZE 5
#define COMPRESSED_SIZE 128
        char const dataToCompress[INPUT_SIZE] = "abcde";
        char compressedData[COMPRESSED_SIZE];
        char decompressedData[INPUT_SIZE];
        /* the ZSTD_CCtx_params structure is a way to save parameters and use
         * them across multiple contexts. We use them here so we can call the
         * function ZSTD_estimateCStreamSize_usingCCtxParams().
         */
        ZSTD_CCtx_params* const cctxParams = ZSTD_createCCtxParams();
        CHECK(cctxParams != NULL, "ZSTD_createCCtxParams() failed!");

        /* Set the compression level. */
        CHECK_ZSTD( ZSTD_CCtxParams_setParameter(cctxParams, ZSTD_c_compressionLevel, compressionLevel) );
        /* Set the window log.
         * The value 0 means use the default window log, which is equivalent to
         * not setting it.
         */
        CHECK_ZSTD( ZSTD_CCtxParams_setParameter(cctxParams, ZSTD_c_windowLog, wLog) );

        /* Force the compressor to allocate the maximum memory size for a given
         * level by not providing the pledged source size, or calling
         * ZSTD_compressStream2() with ZSTD_e_end.
         */
        ZSTD_CCtx* const cctx = ZSTD_createCCtx();
        CHECK(cctx != NULL, "ZSTD_createCCtx() failed!");
        CHECK_ZSTD( ZSTD_CCtx_setParametersUsingCCtxParams(cctx, cctxParams) );
        size_t compressedSize;
        {
            ZSTD_inBuffer inBuff = { dataToCompress, sizeof(dataToCompress), 0 };
            ZSTD_outBuffer outBuff = { compressedData, sizeof(compressedData), 0 };
            CHECK_ZSTD( ZSTD_compressStream(cctx, &outBuff, &inBuff) );
            size_t const remaining = ZSTD_endStream(cctx, &outBuff);
            CHECK_ZSTD(remaining);
            CHECK(remaining == 0, "Frame not flushed!");
            compressedSize = outBuff.pos;
        }

        ZSTD_DCtx* const dctx = ZSTD_createDCtx();
        CHECK(dctx != NULL, "ZSTD_createDCtx() failed!");
        /* Set the maximum allowed window log.
         * The value 0 means use the default window log, which is equivalent to
         * not setting it.
         */
        CHECK_ZSTD( ZSTD_DCtx_setParameter(dctx, ZSTD_d_windowLogMax, wLog) );
        /* forces decompressor to use maximum memory size, since the
         * decompressed size is not stored in the frame header.
         */
        {   ZSTD_inBuffer inBuff = { compressedData, compressedSize, 0 };
            ZSTD_outBuffer outBuff = { decompressedData, sizeof(decompressedData), 0 };
            size_t const remaining = ZSTD_decompressStream(dctx, &outBuff, &inBuff);
            CHECK_ZSTD(remaining);
            CHECK(remaining == 0, "Frame not complete!");
            CHECK(outBuff.pos == sizeof(dataToCompress), "Bad decompression!");
        }

        size_t const cstreamSize = ZSTD_sizeof_CStream(cctx);
        size_t const cstreamEstimatedSize = ZSTD_estimateCStreamSize_usingCCtxParams(cctxParams);
        size_t const dstreamSize = ZSTD_sizeof_DStream(dctx);
        size_t const dstreamEstimatedSize = ZSTD_estimateDStreamSize_fromFrame(compressedData, compressedSize);

        CHECK(cstreamSize <= cstreamEstimatedSize, "Compression mem (%u) > estimated (%u)",
                (unsigned)cstreamSize, (unsigned)cstreamEstimatedSize);
        CHECK(dstreamSize <= dstreamEstimatedSize, "Decompression mem (%u) > estimated (%u)",
                (unsigned)dstreamSize, (unsigned)dstreamEstimatedSize);

        printf("Level %2i : Compression Mem = %5u KB (estimated : %5u KB) ; Decompression Mem = %4u KB (estimated : %5u KB)\n",
                compressionLevel,
                (unsigned)(cstreamSize>>10), (unsigned)(cstreamEstimatedSize>>10),
                (unsigned)(dstreamSize>>10), (unsigned)(dstreamEstimatedSize>>10));

        ZSTD_freeDCtx(dctx);
        ZSTD_freeCCtx(cctx);
        ZSTD_freeCCtxParams(cctxParams);
        if (wLog) break;  /* single test */
    }
    return 0;
}

