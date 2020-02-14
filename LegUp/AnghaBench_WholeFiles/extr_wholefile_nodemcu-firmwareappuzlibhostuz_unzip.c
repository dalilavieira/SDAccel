#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int uint ;
typedef  TYPE_1__* uchar ;
struct TYPE_12__ {scalar_t__ left; int len; int bytesRead; int ndx; int (* fullBlkCB ) () ;int crc; int written; int breakNdx; int /*<<< orphan*/ * fin; struct TYPE_12__** block; int /*<<< orphan*/ * fout; int /*<<< orphan*/ * byte; struct TYPE_12__** inPtr; } ;
typedef  TYPE_1__ outBlock ;

/* Variables and functions */
 int DICTIONARY_WINDOW ; 
 int /*<<< orphan*/  FREE (TYPE_1__*) ; 
 int READ_BLOCKSIZE ; 
 int /*<<< orphan*/  SEEK_END ; 
 int /*<<< orphan*/  SEEK_SET ; 
 int UZLIB_CHKSUM_ERROR ; 
 int /*<<< orphan*/  UZLIB_DATA_ERROR ; 
 int /*<<< orphan*/  UZLIB_DICT_ERROR ; 
 int /*<<< orphan*/  UZLIB_THROW (int /*<<< orphan*/ ) ; 
 int WRITE_BLOCKS ; 
 int WRITE_BLOCKSIZE ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ *) ; 
 void* fopen (char const*,char*) ; 
 int fread (TYPE_1__**,int,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  fseek (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int ftell (int /*<<< orphan*/ *) ; 
 int fwrite (TYPE_1__*,int,int,int /*<<< orphan*/ *) ; 
 TYPE_1__* in ; 
 int /*<<< orphan*/  memmove (TYPE_1__**,TYPE_1__**,int) ; 
 int /*<<< orphan*/  memset (TYPE_1__*,int /*<<< orphan*/ ,int) ; 
 TYPE_1__* out ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int stub1 () ; 
 void* uz_malloc (int) ; 
 int uzlib_crc32 (TYPE_1__*,int,int) ; 
 int uzlib_inflate (int /*<<< orphan*/  (*) (),void (*) (int /*<<< orphan*/ ),int /*<<< orphan*/  (*) (int),int,int*,void**) ; 

uint8_t get_byte (void) {
  if (--in->left < 0) {
    /* Read next input block */
    int remaining = in->len - in->bytesRead;
    int wanted    = remaining >= READ_BLOCKSIZE ? READ_BLOCKSIZE : remaining;

    if (fread(in->block, 1, wanted, in->fin) != wanted)
      UZLIB_THROW(UZLIB_DATA_ERROR);

    in->bytesRead += wanted;
    in->inPtr      = in->block;
    in->left       = wanted-1;
  }
  return *in->inPtr++;
}

void put_byte (uint8_t value) {
  int offset = out->ndx % WRITE_BLOCKSIZE;  /* counts from 0 */

  out->block[0]->byte[offset++] = value;
  out->ndx++;

  if (offset == WRITE_BLOCKSIZE || out->ndx == out->len) {
    if (out->fullBlkCB)
      out->fullBlkCB();
    /* circular shift the block pointers (redundant on last block, but so what) */
    outBlock *nextBlock  = out->block[WRITE_BLOCKS - 1];
    memmove(out->block+1, out->block, (WRITE_BLOCKS-1)*sizeof(void*));
    out->block[0] = nextBlock;
  }
}

uint8_t recall_byte (uint offset) {
  if(offset > DICTIONARY_WINDOW || offset >= out->ndx)
    UZLIB_THROW(UZLIB_DICT_ERROR);
  /* ndx starts at 1. Need relative to 0 */
  uint n   = out->ndx - offset;
  uint pos = n % WRITE_BLOCKSIZE;
  uint blockNo = out->ndx / WRITE_BLOCKSIZE - n  / WRITE_BLOCKSIZE;
  return out->block[blockNo]->byte[pos];
}

int processOutRec (void) {
  int len = (out->ndx % WRITE_BLOCKSIZE) ? out->ndx % WRITE_BLOCKSIZE :
                                           WRITE_BLOCKSIZE;
  if (fwrite(out->block[0], 1, len, out->fout) != len)
    UZLIB_THROW(UZLIB_DATA_ERROR);

  out->crc = uzlib_crc32(out->block[0], len, out->crc);

  out->written += len;
  if (out->written == out->len) {
    fclose(out->fout);
    out->fullBlkCB = NULL;
  }
  return 1;
}

int main(int argc, char *argv[]) {
  assert (argc==3);
  const char *inFile = argv[1], *outFile = argv[2];
  int i, n, res;
  uint crc;
  void *cxt_not_used;
  assert(sizeof(unsigned int) == 4);

  /* allocate and zero the in and out Blocks */
  assert((in  = uz_malloc(sizeof(*in))) != NULL);
  assert((out = uz_malloc(sizeof(*out))) != NULL);

  memset(in, 0, sizeof(*in));
  memset(out, 0, sizeof(*out));

  /* open input files and probe end to read the expanded length */
  assert((in->fin = fopen(inFile, "rb")) != NULL);
  fseek(in->fin, -4, SEEK_END);
  assert(fread((uchar*)&(out->len), 1, 4, in->fin) == 4);
  in->len = ftell(in->fin);
  fseek(in->fin, 0, SEEK_SET);

  assert((out->fout = fopen(outFile, "wb")) != NULL);

  printf ("Inflating in=%s out=%s\n", inFile, outFile);

  /* Allocate the out buffers (number depends on the unpacked length) */
  n = (out->len > DICTIONARY_WINDOW) ? WRITE_BLOCKS :
                                      1 + (out->len-1) / WRITE_BLOCKSIZE;
  for(i = WRITE_BLOCKS - n + 1;  i <= WRITE_BLOCKS; i++)
    assert((out->block[i % WRITE_BLOCKS] = uz_malloc(sizeof(outBlock))) != NULL);

  out->breakNdx  = (out->len < WRITE_BLOCKSIZE) ? out->len : WRITE_BLOCKSIZE;
  out->fullBlkCB = processOutRec;
  out->crc       = ~0;

  /* Call inflate to do the business */
  res = uzlib_inflate (get_byte, put_byte, recall_byte, in->len, &crc, &cxt_not_used);

  if (res > 0 && crc != ~out->crc)
    res = UZLIB_CHKSUM_ERROR;

  for (i = 0; i < WRITE_BLOCKS; i++)
    FREE(out->block[i]);

  fclose(in->fin);
  FREE(in);
  FREE(out);

  if (res < 0)
    printf("Error during decompression: %d\n", res);

  return (res != 0) ? 1: 0;
}

