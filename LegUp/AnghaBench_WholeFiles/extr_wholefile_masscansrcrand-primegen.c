#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_9__ ;
typedef  struct TYPE_14__   TYPE_1__ ;
typedef  struct TYPE_13__   TYPE_11__ ;
typedef  struct TYPE_12__   TYPE_10__ ;

/* Type definitions */
typedef  int uint64_t ;
typedef  int uint32_t ;
struct TYPE_14__ {int** buf; int L; int pos; int base; size_t num; int* p; } ;
typedef  TYPE_1__ primegen ;
typedef  int int64_t ;
struct TYPE_15__ {long f; long g; scalar_t__ k; } ;
struct TYPE_13__ {long f; long g; scalar_t__ k; } ;
struct TYPE_12__ {long f; long g; scalar_t__ k; } ;

/* Variables and functions */
 long B ; 
 int B32 ; 
 int PRIMEGEN_WORDS ; 
 int* deltainverse ; 
 TYPE_11__* for12 ; 
 TYPE_10__* for4 ; 
 TYPE_9__* for6 ; 
 int* pop ; 
 int* qq60tab ; 
 int* qqtab ; 
 int* two ; 

__attribute__((used)) static void clear(register uint32_t (*buf)[B32])
{
  register int i;
  register int j;

  for (j = 0;j < 16;++j) {
    for (i = 0;i < B32;++i)
      (*buf)[i] = (uint32_t)~0;
    ++buf;
  }
}

__attribute__((used)) static void doit4(register uint32_t *a,register long x,register long y,int64_t start)
{
  long i0;
  long y0;
  register long i;
  register uint32_t data;
  register uint32_t pos;
  register uint32_t bits;

  x += x; x += 15;
  y += 15;

  start += 1000000000;
  while (start < 0) { start += x; x += 30; }
  start -= 1000000000;
  i = start;

  while (i < B) { i += x; x += 30; }

  for (;;) {
    x -= 30;
    if (x <= 15) return;
    i -= x;

    while (i < 0) { i += y; y += 30; }

    i0 = i; y0 = y;
    while (i < B) {
      pos = (uint32_t)i; data = (uint32_t)i;
      pos >>= 5; data &= 31;
      i += y; y += 30;
      bits = a[pos]; data = two[data];
      bits ^= data;
      a[pos] = bits;
    }
    i = i0; y = y0;
  }
}

__attribute__((used)) static void doit6(register uint32_t *a,register long x,register long y,int64_t start)
{
  long i0;
  long y0;
  register long i;
  register uint32_t data;
  register uint32_t pos;
  register uint32_t bits;

  x += 5;
  y += 15;

  start += 1000000000;
  while (start < 0) { start += x; x += 10; }
  start -= 1000000000;
  i = start;
  while (i < B) { i += x; x += 10; }

  for (;;) {
    x -= 10;
    if (x <= 5) return;
    i -= x;

    while (i < 0) { i += y; y += 30; }

    i0 = i; y0 = y;
    while (i < B) {
      pos = (uint32_t)i; data = (uint32_t)i;
      pos >>= 5; data &= 31;
      i += y; y += 30;
      bits = a[pos]; data = two[data];
      bits ^= data;
      a[pos] = bits;
    }
    i = i0; y = y0;
  }
}

__attribute__((used)) static void doit12(register uint32_t *a,register long x,register long y,int64_t start)
{
  register long i;
  register uint32_t data;
  register uint32_t bits;

  x += 5;

  start += 1000000000;
  while (start < 0) { start += x; x += 10; }
  start -= 1000000000;
  i = start;
  while (i < 0) { i += x; x += 10; }

  y += 15;
  x += 10;

  for (;;) {
    long i0;
    long y0;
    while (i >= B) {
      if (x <= y) return;
      i -= y;
      y += 30;
    }
    i0 = i;
    y0 = y;
    while ((i >= 0) && (y < x)) {
      register uint32_t pos;
      pos = (uint32_t)i; data = (uint32_t)i;
      pos >>= 5; data &= 31;
      i -= y;
      y += 30;
      bits = a[pos]; data = two[data];
      bits ^= data;
      a[pos] = bits;
    }
    i = i0;
    y = y0;
    i += x - 10;
    x += 10;
  }
}

__attribute__((used)) static void squarefree1big(uint32_t (*buf)[B32],uint64_t base,uint32_t q,uint64_t qq)
{
  uint64_t i;
  uint32_t pos;
  int n;
  uint64_t bound = base + 60 * B;

  while (qq < bound) {
    if (bound < 2000000000)
      i = qq - (((uint32_t) base) % ((uint32_t) qq));
    else
      i = qq - (base % qq);
    if (!(i & 1)) i += qq;

    if (i < B * 60) {
      pos = (uint32_t)i;
      n = deltainverse[pos % 60];
      if (n >= 0) {
        pos /= 60;
        (*buf)[n + (pos >> 5)] |= two[pos & 31];
      }
    }

    qq += q; q += 1800;
  }
}

__attribute__((used)) static void squarefree1(register uint32_t (*buf)[B32],uint64_t L,uint32_t q)
{
  uint32_t qq;
  register uint32_t qqhigh;
  uint32_t i;
  register uint32_t ilow;
  register uint32_t ihigh;
  register int n;
  uint64_t base;

  base = 60 * L;
  qq = q * q;
  q = 60 * q + 900;

  while (qq < B * 60) {
    if (base < 2000000000)
      i = qq - (((uint32_t) base) % qq);
    else
      i = qq - (base % qq);
    if (!(i & 1)) i += qq;

    if (i < B * 60) {
      qqhigh = qq / 60;
      ilow = i % 60; ihigh = i / 60;

      qqhigh += qqhigh;
      while (ihigh < B) {
        n = deltainverse[ilow];
        if (n >= 0)
          (*buf)[n + (ihigh >> 5)] |= two[ihigh & 31];

        ilow += 2; ihigh += qqhigh;
        if (ilow >= 60) { ilow -= 60; ihigh += 1; }
      }
    }

    qq += q; q += 1800;
  }

  squarefree1big(buf,base,q,qq);
}

__attribute__((used)) static void squarefree49big(uint32_t (*buf)[B32],uint64_t base,uint32_t q,uint64_t qq)
{
  uint64_t i;
  uint32_t pos;
  int n;
  uint64_t bound = base + 60 * B;

  while (qq < bound) {
    if (bound < 2000000000)
      i = qq - (((uint32_t) base) % ((uint32_t) qq));
    else
      i = qq - (base % qq);
    if (!(i & 1)) i += qq;

    if (i < B * 60) {
      pos = (uint32_t)i;
      n = deltainverse[pos % 60];
      if (n >= 0) {
        pos /= 60;
        (*buf)[n + (pos >> 5)] |= two[pos & 31];
      }
    }

    qq += q; q += 1800;
  }
}

__attribute__((used)) static void squarefree49(register uint32_t (*buf)[B32],uint64_t L,uint32_t q)
{
  uint32_t qq;
  register uint32_t qqhigh;
  uint32_t i;
  register uint32_t ilow;
  register uint32_t ihigh;
  register int n;
  uint64_t base = 60 * L;

  qq = q * q;
  q = 60 * q + 900;

  while (qq < B * 60) {
    if (base < 2000000000)
      i = qq - (((uint32_t) base) % qq);
    else
      i = qq - (base % qq);
    if (!(i & 1)) i += qq;

    if (i < B * 60) {
      qqhigh = qq / 60;
      ilow = i % 60; ihigh = i / 60;

      qqhigh += qqhigh;
      qqhigh += 1;
      while (ihigh < B) {
        n = deltainverse[ilow];
        if (n >= 0)
          (*buf)[n + (ihigh >> 5)] |= two[ihigh & 31];

        ilow += 38; ihigh += qqhigh;
        if (ilow >= 60) { ilow -= 60; ihigh += 1; }
      }
    }

    qq += q; q += 1800;
  }

  squarefree49big(buf,base,q,qq);
}

__attribute__((used)) static void squarefreetiny(register uint32_t *a,uint32_t *Lmodqq,int d)
{
  int j;

  for (j = 0;j < 49;++j) {
    register uint32_t k;
    register uint32_t qq;
    qq = qqtab[j];
    k = qq - 1 - ((Lmodqq[j] + qq60tab[j] * d - 1) % qq);
    while (k < B) {
      register uint32_t pos;
      register uint32_t data;
      register uint32_t bits;
      pos = k;
      data = k;
      pos >>= 5;
      data &= 31;
      k += qq;
      bits = a[pos];
      data = two[data];
      bits |= data;
      a[pos] = bits;
    }
  }
}

void primegen_sieve(primegen *pg)
{
  uint32_t (*buf)[B32];
  uint64_t L;
  int i;
  uint32_t Lmodqq[49];

  buf = pg->buf;
  L = pg->L;

  if (L > 2000000000)
    for (i = 0;i < 49;++i)
      Lmodqq[i] = L % qqtab[i];
  else
    for (i = 0;i < 49;++i)
      Lmodqq[i] = ((uint32_t) L) % qqtab[i];

  clear(buf);

  for (i = 0;i < 16;++i)
    doit4(buf[0],for4[i].f,for4[i].g,(int64_t) for4[i].k - L);
  squarefreetiny(buf[0],Lmodqq,1);
  for (;i < 32;++i)
    doit4(buf[3],for4[i].f,for4[i].g,(int64_t) for4[i].k - L);
  squarefreetiny(buf[3],Lmodqq,13);
  for (;i < 48;++i)
    doit4(buf[4],for4[i].f,for4[i].g,(int64_t) for4[i].k - L);
  squarefreetiny(buf[4],Lmodqq,17);
  for (;i < 64;++i)
    doit4(buf[7],for4[i].f,for4[i].g,(int64_t) for4[i].k - L);
  squarefreetiny(buf[7],Lmodqq,29);
  for (;i < 80;++i)
    doit4(buf[9],for4[i].f,for4[i].g,(int64_t) for4[i].k - L);
  squarefreetiny(buf[9],Lmodqq,37);
  for (;i < 96;++i)
    doit4(buf[10],for4[i].f,for4[i].g,(int64_t) for4[i].k - L);
  squarefreetiny(buf[10],Lmodqq,41);
  for (;i < 112;++i)
    doit4(buf[13],for4[i].f,for4[i].g,(int64_t) for4[i].k - L);
  squarefreetiny(buf[13],Lmodqq,49);
  for (;i < 128;++i)
    doit4(buf[14],for4[i].f,for4[i].g,(int64_t) for4[i].k - L);
  squarefreetiny(buf[14],Lmodqq,53);

  for (i = 0;i < 12;++i)
    doit6(buf[1],for6[i].f,for6[i].g,(int64_t) for6[i].k - L);
  squarefreetiny(buf[1],Lmodqq,7);
  for (;i < 24;++i)
    doit6(buf[5],for6[i].f,for6[i].g,(int64_t) for6[i].k - L);
  squarefreetiny(buf[5],Lmodqq,19);
  for (;i < 36;++i)
    doit6(buf[8],for6[i].f,for6[i].g,(int64_t) for6[i].k - L);
  squarefreetiny(buf[8],Lmodqq,31);
  for (;i < 48;++i)
    doit6(buf[11],for6[i].f,for6[i].g,(int64_t) for6[i].k - L);
  squarefreetiny(buf[11],Lmodqq,43);

  for (i = 0;i < 24;++i)
    doit12(buf[2],for12[i].f,for12[i].g,(int64_t) for12[i].k - L);
  squarefreetiny(buf[2],Lmodqq,11);
  for (;i < 48;++i)
    doit12(buf[6],for12[i].f,for12[i].g,(int64_t) for12[i].k - L);
  squarefreetiny(buf[6],Lmodqq,23);
  for (;i < 72;++i)
    doit12(buf[12],for12[i].f,for12[i].g,(int64_t) for12[i].k - L);
  squarefreetiny(buf[12],Lmodqq,47);
  for (;i < 96;++i)
    doit12(buf[15],for12[i].f,for12[i].g,(int64_t) for12[i].k - L);
  squarefreetiny(buf[15],Lmodqq,59);

  squarefree49(buf,L,247);
  squarefree49(buf,L,253);
  squarefree49(buf,L,257);
  squarefree49(buf,L,263);
  squarefree1(buf,L,241);
  squarefree1(buf,L,251);
  squarefree1(buf,L,259);
  squarefree1(buf,L,269);
}

void primegen_fill(primegen *pg)
{
  int i;
  uint32_t mask;
  uint32_t bits0, bits1, bits2, bits3, bits4, bits5, bits6, bits7;
  uint32_t bits8, bits9, bits10, bits11, bits12, bits13, bits14, bits15;
  uint64_t base;

  i = pg->pos;
  if (i == B32) {
    primegen_sieve(pg);
    pg->L += B;
    i = 0;
  }
  pg->pos = i + 1;

  bits0 = ~pg->buf[0][i];
  bits1 = ~pg->buf[1][i];
  bits2 = ~pg->buf[2][i];
  bits3 = ~pg->buf[3][i];
  bits4 = ~pg->buf[4][i];
  bits5 = ~pg->buf[5][i];
  bits6 = ~pg->buf[6][i];
  bits7 = ~pg->buf[7][i];
  bits8 = ~pg->buf[8][i];
  bits9 = ~pg->buf[9][i];
  bits10 = ~pg->buf[10][i];
  bits11 = ~pg->buf[11][i];
  bits12 = ~pg->buf[12][i];
  bits13 = ~pg->buf[13][i];
  bits14 = ~pg->buf[14][i];
  bits15 = ~pg->buf[15][i];

  base = pg->base + 1920;
  pg->base = base;

  pg->num = 0;

  for (mask = 0x80000000;mask;mask >>= 1) {
    base -= 60;
    if (bits15 & mask) pg->p[pg->num++] = base + 59;
    if (bits14 & mask) pg->p[pg->num++] = base + 53;
    if (bits13 & mask) pg->p[pg->num++] = base + 49;
    if (bits12 & mask) pg->p[pg->num++] = base + 47;
    if (bits11 & mask) pg->p[pg->num++] = base + 43;
    if (bits10 & mask) pg->p[pg->num++] = base + 41;
    if (bits9 & mask) pg->p[pg->num++] = base + 37;
    if (bits8 & mask) pg->p[pg->num++] = base + 31;
    if (bits7 & mask) pg->p[pg->num++] = base + 29;
    if (bits6 & mask) pg->p[pg->num++] = base + 23;
    if (bits5 & mask) pg->p[pg->num++] = base + 19;
    if (bits4 & mask) pg->p[pg->num++] = base + 17;
    if (bits3 & mask) pg->p[pg->num++] = base + 13;
    if (bits2 & mask) pg->p[pg->num++] = base + 11;
    if (bits1 & mask) pg->p[pg->num++] = base + 7;
    if (bits0 & mask) pg->p[pg->num++] = base + 1;
  }
}

uint64_t primegen_next(primegen *pg)
{
  while (!pg->num)
    primegen_fill(pg);

  return pg->p[--pg->num];
}

uint64_t primegen_peek(primegen *pg)
{
  while (!pg->num)
    primegen_fill(pg);

  return pg->p[pg->num - 1];
}

void primegen_init(primegen *pg)
{
  pg->L = 1;
  pg->base = 60;

  pg->pos = PRIMEGEN_WORDS;

  pg->p[0] = 59;
  pg->p[1] = 53;
  pg->p[2] = 47;
  pg->p[3] = 43;
  pg->p[4] = 41;
  pg->p[5] = 37;
  pg->p[6] = 31;
  pg->p[7] = 29;
  pg->p[8] = 23;
  pg->p[9] = 19;
  pg->p[10] = 17;
  pg->p[11] = 13;
  pg->p[12] = 11;
  pg->p[13] = 7;
  pg->p[14] = 5;
  pg->p[15] = 3;
  pg->p[16] = 2;

  pg->num = 17;
}

uint64_t primegen_count(primegen *pg,uint64_t to)
{
  uint64_t count = 0;
  
  for (;;) {
    register int pos;
    register int j;
    register uint32_t bits;
    register uint32_t smallcount;
    while (pg->num) {
      if (pg->p[pg->num - 1] >= to) return count;
      ++count;
      --pg->num;
    }

    smallcount = 0;
    pos = pg->pos;
    while ((pos < B32) && (pg->base + 1920 < to)) {
      for (j = 0;j < 16;++j) {
    bits = ~pg->buf[j][pos];
    smallcount += pop[bits & 255]; bits >>= 8;
    smallcount += pop[bits & 255]; bits >>= 8;
    smallcount += pop[bits & 255]; bits >>= 8;
    smallcount += pop[bits & 255];
      }
      pg->base += 1920;
      ++pos;
    }
    pg->pos = pos;
    count += smallcount;

    if (pos == B32)
      while (pg->base + B * 60 < to) {
        primegen_sieve(pg);
        pg->L += B;

    smallcount = 0;
        for (j = 0;j < 16;++j)
      for (pos = 0;pos < B32;++pos) {
        bits = ~pg->buf[j][pos];
        smallcount += pop[bits & 255]; bits >>= 8;
        smallcount += pop[bits & 255]; bits >>= 8;
        smallcount += pop[bits & 255]; bits >>= 8;
        smallcount += pop[bits & 255];
      }
        count += smallcount;
        pg->base += B * 60;
      }

    primegen_fill(pg);
  }
}

void primegen_skipto(primegen *pg,uint64_t to)
{
  for (;;) {
    int pos;
    while (pg->num) {
      if (pg->p[pg->num - 1] >= to) return;
      --pg->num;
    }

    pos = pg->pos;
    while ((pos < B32) && (pg->base + 1920 < to)) {
      pg->base += 1920;
      ++pos;
    }
    pg->pos = pos;
    if (pos == B32)
      while (pg->base + B * 60 < to) {
        pg->L += B;
        pg->base += B * 60;
      }

    primegen_fill(pg);
  }
}

