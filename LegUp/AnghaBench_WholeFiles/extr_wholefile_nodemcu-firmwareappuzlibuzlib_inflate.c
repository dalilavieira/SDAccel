#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_24__   TYPE_2__ ;
typedef  struct TYPE_23__   TYPE_1__ ;

/* Type definitions */
typedef  int ushort ;
typedef  int uint16_t ;
typedef  int uint ;
typedef  int uchar ;
struct TYPE_23__ {int* table; int* trans; } ;
typedef  TYPE_1__ UZLIB_TREE ;
struct TYPE_24__ {int (* get_byte ) () ;int bitcount; int tag; size_t* clcidx; int curLen; void (* put_byte ) (int) ;int* lengthBits; int* lengthBase; int lzOffs; int* distBits; int* distBase; int (* recall_byte ) (int) ;int destSize; int bType; int bFinal; int checksum; TYPE_1__ dtree; TYPE_1__ ltree; } ;
typedef  TYPE_2__ UZLIB_DATA ;

/* Variables and functions */
 int /*<<< orphan*/  CLCIDX_INIT ; 
 int /*<<< orphan*/  DBG_PRINT (char*,int,int,...) ; 
 int SIZE (int*) ; 
 int UZLIB_DATA_ERROR ; 
 int UZLIB_DONE ; 
 int UZLIB_FCOMMENT ; 
 int UZLIB_FEXTRA ; 
 int UZLIB_FHCRC ; 
 int UZLIB_FNAME ; 
 int UZLIB_MEMORY_ERROR ; 
 int UZLIB_OK ; 
 int UZLIB_SETJMP (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  UZLIB_THROW (int) ; 
 int /*<<< orphan*/  memcpy (size_t*,int /*<<< orphan*/ ,int) ; 
 int stub1 () ; 
 void stub10 (int) ; 
 int stub11 () ; 
 int stub12 () ; 
 int stub13 () ; 
 int stub14 () ; 
 int stub15 () ; 
 int stub2 () ; 
 int stub3 () ; 
 int stub4 () ; 
 int stub5 () ; 
 int stub6 () ; 
 void stub7 (int) ; 
 int stub8 (int) ; 
 void stub9 (int) ; 
 int /*<<< orphan*/  unwindAddr ; 
 int /*<<< orphan*/  uz_free (TYPE_2__*) ; 
 scalar_t__ uz_malloc (int) ; 

int dbg_break(void) {return 1;}

__attribute__((used)) static void skip_bytes(UZLIB_DATA *d, int num) {
  if (num)             /* Skip a fixed number of bytes */
    while (num--) (void) d->get_byte();
  else                 /* Skip to next nullchar */
    while (d->get_byte()) {}
}

__attribute__((used)) static uint16_t get_uint16(UZLIB_DATA *d) {
  uint16_t v = d->get_byte();
  return v | (d->get_byte() << 8);
}

__attribute__((used)) static uint get_le_uint32 (UZLIB_DATA *d) {
  uint v = get_uint16(d);
  return  v | ((uint) get_uint16(d) << 16);
}

__attribute__((used)) static int getbit (UZLIB_DATA *d) {
  uint bit;

  /* check if tag is empty */
  if (!d->bitcount--) {
    /* load next tag */
    d->tag = d->get_byte();
    d->bitcount = 7;
  }

  /* shift bit out of tag */
  bit = d->tag & 0x01;
  d->tag >>= 1;

  return bit;
}

__attribute__((used)) static uint read_bits (UZLIB_DATA *d, int num, int base) {
 /* This is an optimised version which doesn't call getbit num times */
  if (!num)
    return base;

  uint i, n = (((uint)-1)<<num);
  for (i = d->bitcount; i < num; i +=8)
    d->tag |= ((uint)d->get_byte()) << i;

  n = d->tag & ~n;
  d->tag >>= num;
  d->bitcount = i - num;
  return base + n;
}

__attribute__((used)) static void build_bits_base (uchar *bits, ushort *base,
                             int delta, int first) {
  int i, sum;

  /* build bits table */
  for (i = 0; i < delta; ++i) bits[i] = 0;
  for (i = 0; i < 30 - delta; ++i) bits[i + delta] = i / delta;

  /* build base table */
  for (sum = first, i = 0; i < 30; ++i) {
    base[i] = sum;
    sum += 1 << bits[i];
  }
}

__attribute__((used)) static void build_fixed_trees (UZLIB_TREE *lt, UZLIB_TREE *dt) {
  int i;

  /* build fixed length tree */
  for (i = 0; i < 7; ++i) lt->table[i] = 0;

  lt->table[7] = 24;
  lt->table[8] = 152;
  lt->table[9] = 112;

  for (i = 0; i < 24; ++i)  lt->trans[i] = 256 + i;
  for (i = 0; i < 144; ++i) lt->trans[24 + i] = i;
  for (i = 0; i < 8; ++i)   lt->trans[24 + 144 + i] = 280 + i;
  for (i = 0; i < 112; ++i) lt->trans[24 + 144 + 8 + i] = 144 + i;

  /* build fixed distance tree */
  for (i = 0; i < 5; ++i)   dt->table[i] = 0;
  dt->table[5] = 32;

  for (i = 0; i < 32; ++i)  dt->trans[i] = i;
}

__attribute__((used)) static void build_tree (UZLIB_TREE *t, const uchar *lengths, uint num) {
  ushort offs[16];
  uint i, sum;

  /* clear code length count table */
  for (i = 0; i < 16; ++i)
    t->table[i] = 0;

  /* scan symbol lengths, and sum code length counts */
  for (i = 0; i < num; ++i)
    t->table[lengths[i]]++;
  t->table[0] = 0;

  /* compute offset table for distribution sort */
  for (sum = 0, i = 0; i < 16; ++i) {
    offs[i] = sum;
    sum += t->table[i];
  }

  /* create code->symbol translation table (symbols sorted by code) */
  for (i = 0; i < num; ++i) {
    if (lengths[i])
      t->trans[offs[lengths[i]]++] = i;
  }
}

__attribute__((used)) static int decode_symbol (UZLIB_DATA *d, UZLIB_TREE *t) {
  int sum = 0, cur = 0, len = 0;

  /* get more bits while code value is above sum */
  do {
    cur = 2*cur + getbit(d);

    if (++len == SIZE(t->table))
      return UZLIB_DATA_ERROR;

    sum += t->table[len];
    cur -= t->table[len];

  } while (cur >= 0);

  sum += cur;
  if (sum < 0 || sum >= SIZE(t->trans))
    return UZLIB_DATA_ERROR;

  return t->trans[sum];
}

__attribute__((used)) static int decode_trees (UZLIB_DATA *d, UZLIB_TREE *lt, UZLIB_TREE *dt) {
  uchar lengths[288+32];
  uint hlit, hdist, hclen, hlimit;
  uint i, num, length;

  /* get 5 bits HLIT (257-286) */
  hlit = read_bits(d, 5, 257);

  /* get 5 bits HDIST (1-32) */
  hdist = read_bits(d, 5, 1);

  /* get 4 bits HCLEN (4-19) */
  hclen = read_bits(d, 4, 4);

  for (i = 0; i < 19; ++i) lengths[i] = 0;

  /* read code lengths for code length alphabet */
  for (i = 0; i < hclen; ++i) {
    /* get 3 bits code length (0-7) */
    uint clen = read_bits(d, 3, 0);
    lengths[d->clcidx[i]] = clen;
  }

  /* build code length tree, temporarily use length tree */
  build_tree(lt, lengths, 19);

  /* decode code lengths for the dynamic trees */
  hlimit = hlit + hdist;
  for (num = 0; num < hlimit; ) {
    int sym = decode_symbol(d, lt);
    uchar fill_value = 0;
    int lbits, lbase = 3;

    /* error decoding */
    if (sym < 0)
      return sym;

    switch (sym) {
    case 16:
      /* copy previous code length 3-6 times (read 2 bits) */
      fill_value = lengths[num - 1];
      lbits = 2;
      break;
    case 17:
      /* repeat code length 0 for 3-10 times (read 3 bits) */
      lbits = 3;
      break;
    case 18:
      /* repeat code length 0 for 11-138 times (read 7 bits) */
      lbits = 7;
      lbase = 11;
      break;
    default:
      /* values 0-15 represent the actual code lengths */
      lengths[num++] = sym;
      /* continue the for loop */
      continue;
    }

    /* special code length 16-18 are handled here */
    length = read_bits(d, lbits, lbase);
    if (num + length > hlimit)
      return UZLIB_DATA_ERROR;

    for (; length; --length)
      lengths[num++] = fill_value;
  }

  /* build dynamic trees */
  build_tree(lt, lengths, hlit);
  build_tree(dt, lengths + hlit, hdist);

  return UZLIB_OK;
}

__attribute__((used)) static int inflate_block_data (UZLIB_DATA *d, UZLIB_TREE *lt, UZLIB_TREE *dt) {
  if (d->curLen == 0) {
    int dist;
    int sym = decode_symbol(d, lt);

    /* literal byte */
    if (sym < 256) {
       DBG_PRINT("huff sym: %02x   %c\n", sym, sym);
       d->put_byte(sym);
       return UZLIB_OK;
    }

    /* end of block */
    if (sym == 256)
       return UZLIB_DONE;

    /* substring from sliding dictionary */
    sym -= 257;
    /* possibly get more bits from length code */
    d->curLen = read_bits(d, d->lengthBits[sym], d->lengthBase[sym]);
    dist = decode_symbol(d, dt);
    /* possibly get more bits from distance code */
    d->lzOffs = read_bits(d, d->distBits[dist], d->distBase[dist]);
    DBG_PRINT("huff dict: -%u for %u\n", d->lzOffs, d->curLen);
  }

  /* copy next byte from dict substring */
  uchar b = d->recall_byte(d->lzOffs);
  DBG_PRINT("huff dict byte(%u): -%u -  %02x   %c\n\n",
          d->curLen, d->lzOffs, b, b);
  d->put_byte(b);
  d->curLen--;
  return UZLIB_OK;
}

__attribute__((used)) static int inflate_uncompressed_block (UZLIB_DATA *d) {
  if (d->curLen == 0) {
    uint length    = get_uint16(d);
    uint invlength = get_uint16(d);

    /* check length */
    if (length != (~invlength & 0x0000ffff))
      return UZLIB_DATA_ERROR;

    /* increment length to properly return UZLIB_DONE below, without
       producing data at the same time */
    d->curLen = length + 1;

    /* make sure we start next block on a byte boundary */
    d->bitcount = 0;
  }

  if (--d->curLen == 0) {
    return UZLIB_DONE;
  }

  d->put_byte(d->get_byte());
  return UZLIB_OK;
}

__attribute__((used)) static int parse_gzip_header(UZLIB_DATA *d) {

  /* check id bytes */
  if (d->get_byte() != 0x1f || d->get_byte() != 0x8b)
    return UZLIB_DATA_ERROR;

  if (d->get_byte() != 8) /* check method is deflate */
    return UZLIB_DATA_ERROR;

  uchar flg = d->get_byte();/* get flag byte */

  if (flg & 0xe0)/* check that reserved bits are zero */
    return UZLIB_DATA_ERROR;

  skip_bytes(d, 6);            /* skip rest of base header of 10 bytes */

  if (flg & UZLIB_FEXTRA)            /* skip extra data if present */
     skip_bytes(d, get_uint16(d));

  if (flg & UZLIB_FNAME)             /* skip file name if present */
    skip_bytes(d,0);

  if (flg & UZLIB_FCOMMENT)          /* skip file comment if present */
    skip_bytes(d,0);

  if (flg & UZLIB_FHCRC)             /* ignore header crc if present */
    skip_bytes(d,2);

  return UZLIB_OK;
}

__attribute__((used)) static int uncompress_stream (UZLIB_DATA *d) {
  do {
    int res;

    /* start a new block */
    if (d->bType == -1) {
      next_blk:
      /* read final block flag */
      d->bFinal = getbit(d);
      /* read block type (2 bits) */
      d->bType = read_bits(d, 2, 0);

      DBG_PRINT("Started new block: type=%d final=%d\n", d->bType, d->bFinal);

      if (d->bType == 1) {
        /* build fixed huffman trees */
        build_fixed_trees(&d->ltree, &d->dtree);
      } else if (d->bType == 2) {
        /* decode trees from stream */
        res = decode_trees(d, &d->ltree, &d->dtree);
        if (res != UZLIB_OK)
          return res;
      }
    }

    /* process current block */
    switch (d->bType) {
    case 0:
      /* decompress uncompressed block */
      res = inflate_uncompressed_block(d);
      break;
    case 1:
    case 2:
      /* decompress block with fixed or dynamic huffman trees.  These */
      /* trees were decoded previously, so it's the same routine for both */
      res = inflate_block_data(d, &d->ltree, &d->dtree);
      break;
    default:
      return UZLIB_DATA_ERROR;
    }

    if (res == UZLIB_DONE && !d->bFinal) {
      /* the block has ended (without producing more data), but we
         can't return without data, so start procesing next block */
      goto next_blk;
    }

    if (res != UZLIB_OK)
      return res;

  } while (--d->destSize);

  return UZLIB_OK;
}

int uzlib_inflate (
     uchar (*get_byte)(void),
     void (*put_byte)(uchar v),
     uchar (*recall_byte)(uint offset),
     uint len, uint *crc, void **state) {
  int res;

  /* initialize decompression structure */
  UZLIB_DATA *d = (UZLIB_DATA *) uz_malloc(sizeof(*d));
  if (!d)
    return UZLIB_MEMORY_ERROR;
  *state = d;

  d->bitcount    = 0;
  d->bFinal      = 0;
  d->bType       = -1;
  d->curLen      = 0;
  d->destSize    = len;
  d->get_byte    = get_byte;
  d->put_byte    = put_byte;
  d->recall_byte = recall_byte;

  if ((res = UZLIB_SETJMP(unwindAddr)) != 0) {
    if (crc)
      *crc = d->checksum;
    /* handle long jump */
    if (d) {
      uz_free(d);
      *state = NULL;
    }
    return res;
  }

  /* create RAM copy of clcidx byte array */
  memcpy(d->clcidx, CLCIDX_INIT, sizeof(d->clcidx));

  /* build extra bits and base tables */
  build_bits_base(d->lengthBits, d->lengthBase, 4, 3);
  build_bits_base(d->distBits, d->distBase, 2, 1);
  d->lengthBits[28] = 0;              /* fix a special case */
  d->lengthBase[28] = 258;

  if ((res = parse_gzip_header(d))== UZLIB_OK)
    while ((res = uncompress_stream(d)) == UZLIB_OK)
      {}

  if (res == UZLIB_DONE) {
    d->checksum = get_le_uint32(d);
    (void) get_le_uint32(d);         /* already got length so ignore */
  }

  UZLIB_THROW(res);
}

