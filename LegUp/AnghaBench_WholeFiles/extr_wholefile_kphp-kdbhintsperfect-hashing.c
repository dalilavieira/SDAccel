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
struct TYPE_8__ {int d; int mul0; int mul1; unsigned char* code; unsigned char* used; unsigned char* sums; } ;
typedef  TYPE_1__ perfect_hash ;

/* Variables and functions */
 int R (int,int) ; 
 int /*<<< orphan*/  READ_INT (unsigned char*,int) ; 
 int /*<<< orphan*/  WRITE_INT (unsigned char*,int) ; 
 int /*<<< orphan*/  assert (int) ; 
 int* bits_cnt_tbl ; 
 int* di ; 
 int /*<<< orphan*/  dl_free (int*,int) ; 
 int* dl_malloc (int) ; 
 void* dl_malloc0 (int) ; 
 int get_bit (int*,int) ; 
 int get_code_len (int) ; 
 int get_sums_len (int) ; 
 int get_used_len (int) ; 
 int /*<<< orphan*/  memcpy (unsigned char*,unsigned char*,int) ; 
 int /*<<< orphan*/  memset (int*,int,int) ; 
 int* ne ; 
 int /*<<< orphan*/  set_bit (int*,int) ; 
 int* st ; 
 int* va ; 
 int* was ; 

__attribute__((used)) static inline int get_char_utf8 (unsigned int *x, const char *s) {
#define CHECK(condition) if (!(condition)) {*x = 0xFFFFFFFF; return -1;}
  int a = (unsigned char)s[0];
  if ((a & 0x80) == 0) {
    *x = a;
    return (a != 0);
  }

  CHECK ((a & 0x40) != 0);

  int b = (unsigned char)s[1];
  CHECK((b & 0xc0) == 0x80);
  if ((a & 0x20) == 0) {
    CHECK((a & 0x1e) > 0);
    *x = (((a & 0x1f) << 6) | (b & 0x3f));
    return 2;
  }

  int c = (unsigned char)s[2];
  CHECK((c & 0xc0) == 0x80);
  if ((a & 0x10) == 0) {
    CHECK(((a & 0x0f) | (b & 0x20)) > 0);
    *x = (((a & 0x0f) << 12) | ((b & 0x3f) << 6) | (c & 0x3f));
    return 3;
  }

  int d = (unsigned char)s[3];
  CHECK((d & 0xc0) == 0x80);
  if ((a & 0x08) == 0) {
    CHECK(((a & 0x07) | (b & 0x30)) > 0);
    *x = (((a & 0x07) << 18) | ((b & 0x3f) << 12) | ((c & 0x3f) << 6) | (d & 0x3f));
    return 4;
  }
  
  int e = (unsigned char)s[4];
  CHECK((e & 0xc0) == 0x80);
  if ((a & 0x04) == 0) {
    CHECK(((a & 0x03) | (b & 0x38)) > 0);
    *x = (((a & 0x03) << 24) | ((b & 0x3f) << 18) | ((c & 0x3f) << 12) | ((d & 0x3f) << 6) | (e & 0x3f));
    return 5;
  }
  
  int f = (unsigned char)s[5];
  CHECK((f & 0xc0) == 0x80);
  if ((a & 0x02) == 0) {
    CHECK(((a & 0x01) | (b & 0x3c)) > 0);
    *x = (((a & 0x01) << 30) | ((b & 0x3f) << 24) | ((c & 0x3f) << 18) | ((d & 0x3f) << 12) | ((e & 0x3f) << 6) | (f & 0x3f));
    return 6;
  }

  CHECK(0);
#undef CHECK
}

__attribute__((used)) static inline int put_char_utf8 (unsigned int x, char *s) {
  if (x <= 0x7f) {
    s[0] = x;
    return 1;
  } else if (x <= 0x7ff) {
    s[0] = ((x >>  6) | 0xc0) & 0xdf;
    s[1] = ((x      ) | 0x80) & 0xbf;
    return 2;
  } else if (x <= 0xffff) {
    s[0] = ((x >> 12) | 0xe0) & 0xef;
    s[1] = ((x >>  6) | 0x80) & 0xbf;
    s[2] = ((x      ) | 0x80) & 0xbf;
    return 3;
  } else if (x <= 0x1fffff) {
    s[0] = ((x >> 18) | 0xf0) & 0xf7;
    s[1] = ((x >> 12) | 0x80) & 0xbf;
    s[2] = ((x >>  6) | 0x80) & 0xbf;
    s[3] = ((x      ) | 0x80) & 0xbf;
    return 4;
  } else {
    //ASSERT(0, "bad output");
  }
  return 0;
}

int ph_encode (perfect_hash *h, unsigned char *s) {
  unsigned char *st = s;

  WRITE_INT(s, h->d);
  WRITE_INT(s, h->mul0);
  WRITE_INT(s, h->mul1);

  memcpy (s, h->code, get_code_len (h->d));
  s += get_code_len (h->d);
  memcpy (s, h->used, get_used_len (h->d));
  s += get_used_len (h->d);
  memcpy (s, h->sums, get_sums_len (h->d));
  s += get_sums_len (h->d);

  return s - st;
}

int ph_decode (perfect_hash *h, unsigned char *s) {
  unsigned char *st = s;

  READ_INT(s, h->d);
  READ_INT(s, h->mul0);
  READ_INT(s, h->mul1);

  h->code = s;
  s += get_code_len (h->d);
  h->used = (int *)s;
  s += get_used_len (h->d);
  h->sums = (int *)s;
  s += get_sums_len (h->d);

  return s - st;
}

void init_bits_cnt_table() {
  static int f = 0;
  if (f) {
    return;
  }
  f = 1;

  int i;
  bits_cnt_tbl[0] = 0;
  for (i = 1; i < (1 << 16); i++) {
    bits_cnt_tbl[i] = 1 + bits_cnt_tbl[i & (i - 1)];
  }
}

inline int bits_cnt (int x) {
  return bits_cnt_tbl[x & 0xffff] + bits_cnt_tbl[(x >> 16) & 0xffff];
}

inline int poly_h (unsigned long long v, unsigned int mul, unsigned int mod) {
  unsigned long long res = 0;
  int i;
  for (i = 0; i < 4; i++) {
    res *= mul;
    res ^= (v >> (16 * i)) & (0xffff);
  }
  //res = v ^ (v * mul);

  return (res >> 32) % mod;
}

void ph_init (perfect_hash *h) {
  init_bits_cnt_table();
  h->code = NULL;
  h->used = NULL;
  h->sums = NULL;
  h->d = 0;
  h->mul0 = 0;
  h->mul1 = 0;
}

void ph_free (perfect_hash *h) {
  dl_free (h->code, get_code_len (h->d));
  dl_free (h->used, get_used_len (h->d));
  dl_free (h->sums, get_sums_len (h->d));
  ph_init (h);
}

int dfs (int v, int p, int d) {
  was[v] = 1;
  di[v] = d;
  int i;
  for (i = st[v]; i != -1; i = ne[i]) {
    if (va[i] != p) {
      if (was[va[i]] || !dfs (va[i], v, d + 1)) {
        return 0;
      }
    }
  }
  return 1;
}

void ph_generate (perfect_hash *h, long long *s, int n) {
//  fprintf (stderr, "gen %d\n", n);

  assert (h->code == NULL);
  int d = n * (1 + 0.1);

  h->d = d;
  h->code = dl_malloc0 (get_code_len (d));
  h->used = dl_malloc0 (get_used_len (d));
  assert (sizeof (int) == 4);
  h->sums = dl_malloc0 (get_sums_len (d));

  int en = 2 * d, vn = d * 2;

  va = dl_malloc (sizeof (int) * en),
  ne = dl_malloc (sizeof (int) * en);
  st = dl_malloc (sizeof (int) * (vn)),
  was = dl_malloc (sizeof (int) * (vn)),
  di = dl_malloc (sizeof (int) * (vn));


  int bad = 0;

  int mul0 = 301, mul1 = 303;
  while (1) {
    memset (st, -1, sizeof (int) * (2 * d));

//    fprintf (stderr, "try = %d\n", bad);

    int i;
    en = 0;
    for (i = 0; i < n; i++) {
      int h0 = poly_h (s[i], mul0, d), h1 = poly_h (s[i], mul1, d) + d;

  //    fprintf (stderr, "%d->%d\n", h0, h1);

      ne[en] = st[h0];
      st[h0] = en;
      va[en++] = h1;

      ne[en] = st[h1];
      st[h1] = en;
      va[en++] = h0;
    }

    memset (was, 0, sizeof (int) * vn);
    int f = 1;
    for (i = 0; i < d && f; i++) {
      if (!was[i]) {
        f &= dfs (i, -1, 0);
      }
    }


    if (f) {
      int un =0;
      for (i = 0; i < vn; i++) {
        if (was[i]) {
          if (di[i] % 4 == 1 || di[i] % 4 == 2) {
            set_bit (h->code, i);
          }
          if (di[i]) {
            set_bit (h->used, i);
            un++;
          }
        }
      }

//      fprintf (stderr, "used : %d / %d\n", un, n);
      int cur = 0;
      for (i = 0; i < vn; i++) {
        if ((i & 63) == 0) {
          h->sums[i >> 6] = cur;
        }
        if (get_bit (h->used, i)) {
          cur++;
        }
      }

      h->mul0 = mul0;
      h->mul1 = mul1;
      break;
    }
    bad++;

    mul0 = R(1, 1000000000);
    mul1 = R(1, 1000000000);
  }

  en = 2 * d;
  dl_free (va, sizeof (int) * en);
  dl_free (ne, sizeof (int) * en);
  dl_free (st, sizeof (int) * (vn));
  dl_free (was, sizeof (int) * (vn));
  dl_free (di, sizeof (int) * (vn));
//  fprintf (stderr, "return %d\n", bad);
}

int ph_h (perfect_hash *h, long long s) {
  int h0 = poly_h (s, h->mul0, h->d),
      h1 = poly_h (s, h->mul1, h->d);

  h1 += h->d;

  int i;
  if (get_bit (h->code, h0) ^ get_bit (h->code, h1)) {
    i = h1;
  } else {
    i = h0;
  }

//  int tt = i;

  int res = 0;//, j;
  res = h->sums[i >> 6];

  int left = (i & 63);
  i = (i >> 5) & -2;
  if (left >= 32) {
    res += bits_cnt (h->used[i++]);
    left -= 32;
  }

  res += bits_cnt (h->used[i] & ((1 << left) - 1));
/*
  int tres = 0;
  for (j = 0; j < tt; j++) {
    tres += get_bit (h->used, j);
  }
  fprintf (stderr, "%d : %d vs %d\n", tt, res, tres);
  assert (res == tres);
  */
  return res;
}

