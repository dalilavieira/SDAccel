#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct fcb_table_entry {scalar_t__ p; scalar_t__ i; } ;
typedef  int /*<<< orphan*/  T ;

/* Variables and functions */
 unsigned int GROUP_SWAP (unsigned int,int,int) ; 
 unsigned int __builtin_bswap32 (unsigned int) ; 
 int /*<<< orphan*/  assert (int) ; 
 struct fcb_table_entry* calloc (int,int) ; 
 unsigned int* crc32_table ; 
 unsigned int* crc32_table0 ; 
 unsigned int* crc32_table1 ; 
 unsigned int* crc32_table2 ; 
 unsigned long long* crc64_table ; 
 int /*<<< orphan*/  free (struct fcb_table_entry*) ; 
 int /*<<< orphan*/  qsort (struct fcb_table_entry*,int,int,int (*) (void const*,void const*)) ; 
 scalar_t__ sqrt (int) ; 

unsigned crc32_partial_old (const void *data, int len, unsigned crc) {
  const char *p = data;
  for (; len > 0; len--) {
    crc = crc32_table[(crc ^ *p++) & 0xff] ^ (crc >> 8);
  }
  return crc;    
}

unsigned crc32_partial (const void *data, int len, unsigned crc) {
  const int *p = (const int *) data;
  int x;
#define DO_ONE(v) crc ^= v; crc = crc32_table0[crc & 0xff] ^ crc32_table1[(crc & 0xff00) >> 8] ^ crc32_table2[(crc & 0xff0000) >> 16] ^ crc32_table[crc >> 24];
#define DO_FOUR(p) DO_ONE((p)[0]); DO_ONE((p)[1]); DO_ONE((p)[2]); DO_ONE((p)[3]);

  for (x = (len >> 5); x > 0; x--) {
    DO_FOUR (p);
    DO_FOUR (p + 4);
    p += 8;
  }
  if (len & 16) {
    DO_FOUR (p);
    p += 4;
  }
  if (len & 8) {
    DO_ONE (p[0]);
    DO_ONE (p[1]);
    p += 2;
  }
  if (len & 4) {
    DO_ONE (*p++);
  }
  /*
  for (x = (len >> 2) & 7; x > 0; x--) {
    DO_ONE (*p++);
  }
  */
#undef DO_ONE
  const char *q = (const char *) p;
  if (len & 2) {
    crc = crc32_table[(crc ^ q[0]) & 0xff] ^ (crc >> 8);
    crc = crc32_table[(crc ^ q[1]) & 0xff] ^ (crc >> 8);
    q += 2;
  }
  if (len & 1) {
    crc = crc32_table[(crc ^ *q++) & 0xff] ^ (crc >> 8);
  }
  return crc;
}

unsigned compute_crc32 (const void *data, int len) {
  return crc32_partial (data, len, -1) ^ -1;
}

unsigned long long crc64_partial (const void *data, int len, unsigned long long crc) {
  const char *p = data;
  for (; len > 0; len--) {
    crc = crc64_table[(crc ^ *p++) & 0xff] ^ (crc >> 8);
  }
  return crc;    
}

unsigned long long crc64 (const void *data, int len) {
  return crc64_partial (data, len, -1LL) ^ -1LL;
}

__attribute__((used)) static unsigned gf32_matrix_times (unsigned *matrix, unsigned vector) {
  unsigned sum = 0;
  while (vector) {
    if (vector & 1) {
      sum ^= *matrix;
    }
    vector >>= 1;
    matrix++;
  }
  return sum;
}

__attribute__((used)) static void gf32_matrix_square (unsigned *square, unsigned *matrix) {
  int n = 0;
  do {
    square[n] = gf32_matrix_times (matrix, matrix[n]);
  } while (++n < 32);
}

unsigned compute_crc32_combine (unsigned crc1, unsigned crc2, int len2) {
  static int power_buf_initialized = 0;
  static unsigned power_buf[1024];
  int n;
  /* degenerate case (also disallow negative lengths) */
  if (len2 <= 0) {
    return crc1;
  }
  if (!power_buf_initialized) {
    power_buf[0] = 0xedb88320UL;
    for (n = 0; n < 31; n++) {
      power_buf[n+1] = 1U << n;
    }
    for (n = 1; n < 32; n++) {
      gf32_matrix_square (power_buf + (n << 5), power_buf + ((n - 1) << 5));
    }
    power_buf_initialized = 1;
  }

  unsigned int *p = power_buf + 64;
  do {
    p += 32;
    if (len2 & 1) {
      crc1 = gf32_matrix_times (p, crc1);
    }
    len2 >>= 1;
  } while (len2);
  return crc1 ^ crc2;
}

__attribute__((used)) static inline unsigned gf32_mod (unsigned long long r, int high_bit) {
  int j = high_bit;
  for (j = high_bit; j >= 32; j--) {
    if ((1ULL << j) & r) {
      r ^= 0x04C11DB7ULL << (j - 32);
    }
  }
  return (unsigned) r;
}

__attribute__((used)) static unsigned gf32_mult (unsigned a, unsigned b) {
  int i;
  const unsigned long long m = b;
  unsigned long long r = 0;
  for (i = 0; i < 32; i++) {
    if (a & (1U << i)) {
      r ^= m << i;
    }
  }
  return gf32_mod (r, 62);
}

__attribute__((used)) static unsigned gf32_shl (unsigned int a, int shift) {
  unsigned long long r = a;
  r <<= shift;
  return gf32_mod (r, 31 + shift);
}

__attribute__((used)) static unsigned gf32_pow (unsigned a, int k) {
  if (!k) { return 1; }
  unsigned x = gf32_pow (gf32_mult (a, a), k >> 1);
  if (k & 1) {
    x = gf32_mult (x, a);
  }
  return x;
}

__attribute__((used)) static int cmp_fcb_table_entry (const void *a, const void *b) {
  const struct fcb_table_entry *x = a;
  const struct fcb_table_entry *y = b;
  if (x->p < y->p) { return -1; }
  if (x->p > y->p) { return  1; }
  if (x->i < y->i) { return -1; }
  if (x->i > y->i) { return  1; }
  return 0;
}

__attribute__((used)) static unsigned revbin (unsigned x) {
  x = GROUP_SWAP(x,0x55555555U,1);
  x = GROUP_SWAP(x,0x33333333U,2);
  x = GROUP_SWAP(x,0x0f0f0f0fU,4);
  x = __builtin_bswap32 (x);
  return x;
}

__attribute__((used)) static inline unsigned xmult (unsigned a) {
  unsigned r = a << 1;
  if (a & (1U<<31)) {
    r ^= 0x04C11DB7U;
  }
  return r;
}

__attribute__((used)) static int find_corrupted_bit (int size, unsigned d) {
  int i, j;
  size += 4;
  d = revbin (d);
  int n = size << 3;
  int r = (int) (sqrt (n) + 0.5);
//  vkprintf (3, "n = %d, r = %d\n", n, r);
  struct fcb_table_entry *T = calloc (r, sizeof (struct fcb_table_entry));
  assert (T != NULL);
  T[0].i = 0;
  T[0].p = 1;
  for (i = 1; i < r; i++) {
    T[i].i = i;
    T[i].p = xmult (T[i-1].p);
  }
  assert (xmult (0x82608EDB) == 1);
  qsort (T, r, sizeof (T[0]), cmp_fcb_table_entry);
  unsigned q = gf32_pow (0x82608EDB, r);

  unsigned A[32];
  for (i = 0; i < 32; i++) {
    A[i] = gf32_shl (q, i);
  }

  unsigned x = d;
  int max_j = n / r, res = -1;
  for (j = 0; j <= max_j; j++) {
    int a = -1, b = r;
    while (b - a > 1) {
      int c = ((a + b) >> 1);
      if (T[c].p <= x) { a = c; } else { b = c; }
    }
    if (a >= 0 && T[a].p == x) {
      res = T[a].i + r * j;
      break;
    }
    x = gf32_matrix_times (A, x);
  }
  free (T);
  return res;
}

__attribute__((used)) static int repair_bit (unsigned char *input, int l, int k) {
  if (k < 0) {
    return -1;
  }
  int idx = k >> 5, bit = k & 31, i = (l - 1) - (idx - 1) * 4;
  while (bit >= 8) {
    i--;
    bit -= 8;
  }
  if (i < 0) {
    return -2;
  }
  if (i >= l) {
    return -3;
  }
  int j = 7 - bit;
  input[i] ^= 1 << j;
  return 0;
}

int crc32_check_and_repair (void *input, int l, unsigned *input_crc32, int force_exit) {
  unsigned computed_crc32 = compute_crc32 (input, l);
  const unsigned crc32_diff = computed_crc32 ^ (*input_crc32);
  if (!crc32_diff) {
    return 0;
  }
  int k = find_corrupted_bit (l, crc32_diff);
//  vkprintf (3, "find_corrupted_bit returns %d.\n", k);
  int r = repair_bit (input, l, k);
//  vkprintf (3, "repair_bit returns %d.\n", r);
  if (!r) {
    assert (compute_crc32 (input, l) == *input_crc32);
    if (force_exit) {
//      kprintf ("crc32_check_and_repair successfully repair one bit in %d bytes block.\n", l);
    }
    return 1;
  }
  if (!(crc32_diff & (crc32_diff - 1))) { /* crc32_diff is power of 2 */
    *input_crc32 = computed_crc32;
    if (force_exit) {
//      kprintf ("crc32_check_and_repair successfully repair one bit in crc32 (%d bytes block).\n", l);
    }
    return 2;
  }
  assert (!force_exit);
  *input_crc32 = computed_crc32;
  return -1;
}

