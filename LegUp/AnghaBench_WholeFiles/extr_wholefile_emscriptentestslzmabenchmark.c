#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int int64_t ;
typedef  int int32_t ;
struct TYPE_5__ {size_t level; } ;
typedef  int SizeT ;
typedef  int /*<<< orphan*/  ELzmaStatus ;
typedef  TYPE_1__ CLzmaEncProps ;

/* Variables and functions */
 int /*<<< orphan*/  LZMA_FINISH_END ; 
 size_t LZMA_PROPS_SIZE ; 
 int LzmaDecode (int /*<<< orphan*/ *,int*,int /*<<< orphan*/ *,int*,int /*<<< orphan*/ *,size_t,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  LzmaEncProps_Init (TYPE_1__*) ; 
 int /*<<< orphan*/  LzmaEncProps_Normalize (TYPE_1__*) ; 
 int LzmaEncode (int /*<<< orphan*/ *,int*,int /*<<< orphan*/ *,size_t,TYPE_1__*,int /*<<< orphan*/ *,size_t*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 void* MyAlloc (size_t) ; 
 int /*<<< orphan*/  MyFree (void*) ; 
 int SZ_OK ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  g_Alloc ; 
 scalar_t__ malloc (int) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 scalar_t__ strcmp (char*,char*) ; 

__attribute__((used)) static void *SzAlloc(void *p, size_t size) { p = p; return MyAlloc(size); }

__attribute__((used)) static void SzFree(void *p, void *address) { p = p; MyFree(address); }

int64_t lzbench_lzma_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, size_t level, size_t x, char* y)
{
	CLzmaEncProps props;
	int res;
    size_t headerSize = LZMA_PROPS_SIZE;
	SizeT out_len = outsize - LZMA_PROPS_SIZE;
	
	LzmaEncProps_Init(&props);
	props.level = level;
	LzmaEncProps_Normalize(&props);
  /*
  p->level = 5;
  p->dictSize = p->mc = 0;
  p->reduceSize = (UInt64)(Int64)-1;
  p->lc = p->lp = p->pb = p->algo = p->fb = p->btMode = p->numHashBytes = p->numThreads = -1;
  p->writeEndMark = 0;
  */
  
  	res = LzmaEncode((uint8_t*)outbuf+LZMA_PROPS_SIZE, &out_len, (uint8_t*)inbuf, insize, &props, (uint8_t*)outbuf, &headerSize, 0/*int writeEndMark*/, NULL, &g_Alloc, &g_Alloc);
	if (res != SZ_OK) return 0;
	
//	printf("out_len=%u LZMA_PROPS_SIZE=%d headerSize=%d\n", (int)(out_len + LZMA_PROPS_SIZE), LZMA_PROPS_SIZE, (int)headerSize);
	return LZMA_PROPS_SIZE + out_len;
}

int64_t lzbench_lzma_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, size_t x, size_t y, char* z)
{
	int res;
	SizeT out_len = outsize;
	SizeT src_len = insize - LZMA_PROPS_SIZE;
	ELzmaStatus status;
	
//	SRes LzmaDecode(Byte *dest, SizeT *destLen, const Byte *src, SizeT *srcLen, const Byte *propData, unsigned propSize, ELzmaFinishMode finishMode, ELzmaStatus *status, ISzAlloc *alloc)
	res = LzmaDecode((uint8_t*)outbuf, &out_len, (uint8_t*)inbuf+LZMA_PROPS_SIZE, &src_len, (uint8_t*)inbuf, LZMA_PROPS_SIZE, LZMA_FINISH_END, &status, &g_Alloc);
	if (res != SZ_OK) return 0;
	
//	printf("out_len=%u\n", (int)(out_len + LZMA_PROPS_SIZE));	
    return out_len;
}

void __attribute__ ((noinline)) doit(char *buffer, int size, int i) {
  static char *buffer2 = NULL;
  static char *buffer3 = NULL;

  unsigned long maxCompressedSize = size * 2 + 10000; // whatever

  if (!buffer2) buffer2 = (char*)malloc(maxCompressedSize);
  if (!buffer3) buffer3 = (char*)malloc(size);

  int64_t compressedSize = lzbench_lzma_compress(buffer, size, buffer2, maxCompressedSize, 4 /*level*/, 0, NULL);

  if (i == 0) printf("sizes: %d,%d\n", size, (int32_t)compressedSize);

  int64_t roundTrip = lzbench_lzma_decompress(buffer2, compressedSize, buffer3, size, 0, 0, NULL);

  assert(roundTrip == size);
  if (i == 0) assert(strcmp(buffer, buffer3) == 0);
}

int main(int argc, char **argv) {
  int size, iters;
  int arg = argc > 1 ? argv[1][0] - '0' : 3;
  switch(arg) {
    case 0: return 0; break;
    case 1: size = 100000; iters = 4*1; break;
    case 2: size = 100000; iters = 4*10; break;
    case 3: size = 100000; iters = 4*22; break;
    case 4: size = 100000; iters = 4*125; break;
    case 5: size = 100000; iters = 4*225; break;
    default: printf("error: %d\\n", arg); return -1;
  }

  char *buffer = (char*)malloc(size);

  int i = 0;
  int run = 0;
  char runChar = 17;
  while (i < size) {
    if (run > 0) {
      run--;
    } else {
      if ((i & 7) == 0) {
        runChar = i & 7;
        run = i & 31;
      } else {
        runChar = (i*i) % 6714;
      }
    }
    buffer[i] = runChar;
    i++;
  }

  for (i = 0; i < iters; i++) {
    doit(buffer, size, i);
  }

  printf("ok.\n");

  return 0;
}

