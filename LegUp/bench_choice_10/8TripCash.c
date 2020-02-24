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
struct stat {int /*<<< orphan*/  st_mode; int /*<<< orphan*/  st_size; } ;
struct TYPE_5__ {void* member_0; size_t member_1; size_t const pos; int /*<<< orphan*/  member_2; } ;
typedef  TYPE_1__ ZSTD_outBuffer ;
struct TYPE_6__ {void const* member_0; size_t member_1; int /*<<< orphan*/  member_2; } ;
typedef  TYPE_2__ ZSTD_inBuffer ;
typedef  int /*<<< orphan*/  ZSTD_CCtx_params ;
typedef  int /*<<< orphan*/  ZSTD_CCtx ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int /*<<< orphan*/  CHECK_Z (int /*<<< orphan*/ ) ; 
 size_t MIN (int,size_t) ; 
 scalar_t__ S_ISDIR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  S_ISREG (int /*<<< orphan*/ ) ; 
 unsigned int XXH32 (void const*,size_t const,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ZSTD_CCtxParams_setParameter (int /*<<< orphan*/ * const,int /*<<< orphan*/ ,int const) ; 
 int /*<<< orphan*/  ZSTD_CCtx_setParametersUsingCCtxParams (int /*<<< orphan*/ * const,int /*<<< orphan*/ * const) ; 
 int /*<<< orphan*/  ZSTD_c_compressionLevel ; 
 int /*<<< orphan*/  ZSTD_c_nbWorkers ; 
 int /*<<< orphan*/  ZSTD_c_overlapLog ; 
 size_t ZSTD_compress (void*,size_t,void const*,size_t,int const) ; 
 size_t ZSTD_compressBound (size_t) ; 
 int /*<<< orphan*/  ZSTD_compressStream2 (int /*<<< orphan*/ * const,TYPE_1__*,TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * ZSTD_createCCtx () ; 
 int /*<<< orphan*/ * ZSTD_createCCtxParams () ; 
 size_t ZSTD_decompress (void*,size_t,void*,size_t const) ; 
 int /*<<< orphan*/  ZSTD_e_end ; 
 int /*<<< orphan*/  ZSTD_freeCCtx (int /*<<< orphan*/ * const) ; 
 int /*<<< orphan*/  ZSTD_freeCCtxParams (int /*<<< orphan*/ * const) ; 
 char* ZSTD_getErrorName (size_t const) ; 
 scalar_t__ ZSTD_isError (size_t const) ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ * const) ; 
 int /*<<< orphan*/ * fopen (char const*,char*) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 size_t fread (void*,int,size_t,int /*<<< orphan*/ * const) ; 
 int /*<<< orphan*/  free (void* const) ; 
 void* malloc (size_t const) ; 
 int stat (char const*,struct stat*) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  strcmp (char const*,char*) ; 

__attribute__((used)) static void crash(int errorCode){
    /* abort if AFL/libfuzzer, exit otherwise */
    #ifdef FUZZING_BUILD_MODE_UNSAFE_FOR_PRODUCTION /* could also use __AFL_COMPILER */
        abort();
    #else
        exit(errorCode);
    #endif
}

__attribute__((used)) static size_t roundTripTest(void* resultBuff, size_t resultBuffCapacity,
                            void* compressedBuff, size_t compressedBuffCapacity,
                      const void* srcBuff, size_t srcBuffSize)
{
    static const int maxClevel = 19;
    size_t const hashLength = MIN(128, srcBuffSize);
    unsigned const h32 = XXH32(srcBuff, hashLength, 0);
    int const cLevel = h32 % maxClevel;
    size_t const cSize = ZSTD_compress(compressedBuff, compressedBuffCapacity, srcBuff, srcBuffSize, cLevel);
    if (ZSTD_isError(cSize)) {
        fprintf(stderr, "Compression error : %s \n", ZSTD_getErrorName(cSize));
        return cSize;
    }
    return ZSTD_decompress(resultBuff, resultBuffCapacity, compressedBuff, cSize);
}

__attribute__((used)) static size_t cctxParamRoundTripTest(void* resultBuff, size_t resultBuffCapacity,
                            void* compressedBuff, size_t compressedBuffCapacity,
                      const void* srcBuff, size_t srcBuffSize)
{
    ZSTD_CCtx* const cctx = ZSTD_createCCtx();
    ZSTD_CCtx_params* const cctxParams = ZSTD_createCCtxParams();
    ZSTD_inBuffer inBuffer = { srcBuff, srcBuffSize, 0 };
    ZSTD_outBuffer outBuffer = { compressedBuff, compressedBuffCapacity, 0 };

    static const int maxClevel = 19;
    size_t const hashLength = MIN(128, srcBuffSize);
    unsigned const h32 = XXH32(srcBuff, hashLength, 0);
    int const cLevel = h32 % maxClevel;

    /* Set parameters */
    CHECK_Z( ZSTD_CCtxParams_setParameter(cctxParams, ZSTD_c_compressionLevel, cLevel) );
    CHECK_Z( ZSTD_CCtxParams_setParameter(cctxParams, ZSTD_c_nbWorkers, 2) );
    CHECK_Z( ZSTD_CCtxParams_setParameter(cctxParams, ZSTD_c_overlapLog, 5) );


    /* Apply parameters */
    CHECK_Z( ZSTD_CCtx_setParametersUsingCCtxParams(cctx, cctxParams) );

    CHECK_Z (ZSTD_compressStream2(cctx, &outBuffer, &inBuffer, ZSTD_e_end) );

    ZSTD_freeCCtxParams(cctxParams);
    ZSTD_freeCCtx(cctx);

    return ZSTD_decompress(resultBuff, resultBuffCapacity, compressedBuff, outBuffer.pos);
}

__attribute__((used)) static size_t checkBuffers(const void* buff1, const void* buff2, size_t buffSize)
{
    const char* ip1 = (const char*)buff1;
    const char* ip2 = (const char*)buff2;
    size_t pos;

    for (pos=0; pos<buffSize; pos++)
        if (ip1[pos]!=ip2[pos])
            break;

    return pos;
}

__attribute__((used)) static void roundTripCheck(const void* srcBuff, size_t srcBuffSize, int testCCtxParams)
{
    size_t const cBuffSize = ZSTD_compressBound(srcBuffSize);
    void* cBuff = malloc(cBuffSize);
    void* rBuff = malloc(cBuffSize);

    if (!cBuff || !rBuff) {
        fprintf(stderr, "not enough memory ! \n");
        exit (1);
    }

    {   size_t const result = testCCtxParams ?
                  cctxParamRoundTripTest(rBuff, cBuffSize, cBuff, cBuffSize, srcBuff, srcBuffSize)
                : roundTripTest(rBuff, cBuffSize, cBuff, cBuffSize, srcBuff, srcBuffSize);
        if (ZSTD_isError(result)) {
            fprintf(stderr, "roundTripTest error : %s \n", ZSTD_getErrorName(result));
            crash(1);
        }
        if (result != srcBuffSize) {
            fprintf(stderr, "Incorrect regenerated size : %u != %u\n", (unsigned)result, (unsigned)srcBuffSize);
            crash(1);
        }
        if (checkBuffers(srcBuff, rBuff, srcBuffSize) != srcBuffSize) {
            fprintf(stderr, "Silent decoding corruption !!!");
            crash(1);
        }
    }

    free(cBuff);
    free(rBuff);
}

__attribute__((used)) static size_t getFileSize(const char* infilename)
{
    int r;
#if defined(_MSC_VER)
    struct _stat64 statbuf;
    r = _stat64(infilename, &statbuf);
    if (r || !(statbuf.st_mode & S_IFREG)) return 0;   /* No good... */
#else
    struct stat statbuf;
    r = stat(infilename, &statbuf);
    if (r || !S_ISREG(statbuf.st_mode)) return 0;   /* No good... */
#endif
    return (size_t)statbuf.st_size;
}

__attribute__((used)) static int isDirectory(const char* infilename)
{
    int r;
#if defined(_MSC_VER)
    struct _stat64 statbuf;
    r = _stat64(infilename, &statbuf);
    if (!r && (statbuf.st_mode & _S_IFDIR)) return 1;
#else
    struct stat statbuf;
    r = stat(infilename, &statbuf);
    if (!r && S_ISDIR(statbuf.st_mode)) return 1;
#endif
    return 0;
}

__attribute__((used)) static void loadFile(void* buffer, const char* fileName, size_t fileSize)
{
    FILE* const f = fopen(fileName, "rb");
    if (isDirectory(fileName)) {
        fprintf(stderr, "Ignoring %s directory \n", fileName);
        exit(2);
    }
    if (f==NULL) {
        fprintf(stderr, "Impossible to open %s \n", fileName);
        exit(3);
    }
    {   size_t const readSize = fread(buffer, 1, fileSize, f);
        if (readSize != fileSize) {
            fprintf(stderr, "Error reading %s \n", fileName);
            exit(5);
    }   }
    fclose(f);
}

__attribute__((used)) static void fileCheck(const char* fileName, int testCCtxParams)
{
    size_t const fileSize = getFileSize(fileName);
    void* const buffer = malloc(fileSize + !fileSize /* avoid 0 */);
    if (!buffer) {
        fprintf(stderr, "not enough memory \n");
        exit(4);
    }
    loadFile(buffer, fileName, fileSize);
    roundTripCheck(buffer, fileSize, testCCtxParams);
    free (buffer);
}

int main(int argCount, const char** argv) {
    int argNb = 1;
    int testCCtxParams = 0;
    if (argCount < 2) {
        fprintf(stderr, "Error : no argument : need input file \n");
        exit(9);
    }

    if (!strcmp(argv[argNb], "--cctxParams")) {
      testCCtxParams = 1;
      argNb++;
    }

    fileCheck(argv[argNb], testCCtxParams);
    fprintf(stderr, "no pb detected\n");
    return 0;
}

