#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct timespec {scalar_t__ tv_sec; scalar_t__ tv_nsec; } ;
struct TYPE_6__ {int val_n; int rand_n; int hash_st; int hash_mul; int* perm_first; int* perm_middle; int* perm_last; } ;
typedef  TYPE_1__ dl_crypto ;

/* Variables and functions */
 int /*<<< orphan*/  CLOCK_REALTIME ; 
 char N ; 
 int /*<<< orphan*/  assert (int) ; 
 scalar_t__ clock_gettime (int /*<<< orphan*/ ,struct timespec*) ; 
 int /*<<< orphan*/  dbg (char*,char*,int*,int) ; 
 int /*<<< orphan*/  dl_free (int*,int) ; 
 int* dl_malloc (size_t) ; 
 int rand () ; 
 int /*<<< orphan*/  srand (unsigned int) ; 
 int /*<<< orphan*/  usleep (int) ; 

__attribute__((used)) static __inline__ unsigned long long dl_rdtsc(void) {
  unsigned hi, lo;
  __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
  return ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
}

inline char encode_char (char c) {
  if ('A' <= c && c <= 'Z') {
    return (char)(c - 'A');
  }
  if ('a' <= c && c <= 'z') {
    return (char)(c - 'a' + 26);
  }
  if ('0' <= c && c <= '9') {
    return (char)(c - '0' + 26 + 26);
  }
  if (c == '_') {
    return (char)(10 + 26 + 26);
  }
  assert (0);
}

inline char decode_char (char c) {
  assert (0 <= c && c < N);
  if (c < 26) {
    return (char)(c + 'A');
  }
  c = (char)(c - 26);
  if (c < 26) {
    return (char)(c + 'a');
  }
  c = (char)(c - 26);
  if (c < 10) {
    return (char)(c + '0');
  }
  return '_';
}

inline void encode_str (char *s, int sn) {
  int i;
  for (i = 0; i < sn; i++) {
    s[i] = encode_char (s[i]);
  }
}

inline void decode_str (char *s, int sn) {
  int i;
  for (i = 0; i < sn; i++) {
    s[i] = decode_char (s[i]);
  }
}

void apply_perm (char *s, int *perm, int n) {
  dbg ("In apply_perm s = %p, perm = %p, n = %d\n", s, perm, n);
  int i;
  for (i = 0; i < n; i++) {
    int j = perm[i];
    char t = s[i];
    s[i] = s[j];
    s[j] = t;
  }
  dbg ("After apply_perm s = %p, perm = %p, n = %d\n", s, perm, n);
}

void apply_perm_rev (char *s, int *perm, int n) {
  dbg ("In apply_perm_rev s = %p, perm = %p, n = %d\n", s, perm, n);
  int i;
  for (i = n - 1; i >= 0; i--) {
    int j = perm[i];
    char t = s[i];
    s[i] = s[j];
    s[j] = t;
  }
  dbg ("After apply_perm_rev s = %p, perm = %p, n = %d\n", s, perm, n);
}

int *rand_perm (int n) {
  int *v = dl_malloc ((size_t)n * sizeof (int)), i;

  usleep (1);
  struct timespec tv;
  assert (clock_gettime (CLOCK_REALTIME, &tv) >= 0);
  srand ((unsigned int)tv.tv_nsec * 123456789u + (unsigned int)tv.tv_sec * 987654321u);

  for (i = 0; i < n; i++) {
    v[i] = rand() % (i + 1);
  }

  return v;
}

void dl_crypto_init (dl_crypto *cr, int val_n, int rand_n, int hash_st, int hash_mul, int seed) {
  assert ((N & 1) == 1);

  cr->val_n = val_n;
  cr->rand_n = rand_n;
  cr->hash_st = hash_st;
  cr->hash_mul = hash_mul;

  srand ((unsigned int)seed);
  int n = val_n + rand_n;
  cr->perm_first = rand_perm (val_n);
  cr->perm_middle = rand_perm (n);
  cr->perm_last = rand_perm (n);
}

void dl_crypto_encode (dl_crypto *cr, char *s, char *t) {
  encode_str (s, cr->val_n);
  apply_perm (s, cr->perm_first, cr->val_n);

  int i;
  unsigned int h = cr->hash_st;
  for (i = 0; i < cr->rand_n; i++) {
    t[i] = (char)((unsigned int)rand() % N);
    h = h * cr->hash_mul + t[i];
  }

  for (i = 0; i < cr->val_n; i++) {
    t[i + cr->rand_n] = (char)((s[i] + N - h % N) % N);
    h = h * cr->hash_mul + s[i];
  }

  int n = cr->val_n + cr->rand_n;

  apply_perm (t, cr->perm_middle, n);

  h = 0;
  for (i = 0; i < n; i++) {
    char c = t[i];
    t[i] = (char)((t[i] + N - h % N) % N);
    h += c;
  }
  
  apply_perm (t, cr->perm_last, n);
  decode_str (t, n);
}

void dl_crypto_decode (dl_crypto *cr, char *s, char *t) {
  int n = cr->val_n + cr->rand_n;
  encode_str (s, n);
  apply_perm_rev (s, cr->perm_last, n);

  int i;
  unsigned int h = 0;
  for (i = 0; i < n; i++) {
    s[i] = (char)((s[i] + h) % N);
    h += s[i];
  }

  apply_perm_rev (s, cr->perm_middle, n);

  h = cr->hash_st;
  for (i = 0; i < cr->rand_n; i++) {
    h = h * cr->hash_mul + s[i];
  }

  for (i = 0; i < cr->val_n; i++) {
    t[i] = (char)((s[i + cr->rand_n] + N + h % N) % N);
    h = h * cr->hash_mul + t[i];
  }

  apply_perm_rev (t, cr->perm_first, cr->val_n);
  decode_str (t, cr->val_n);
}

void dl_crypto_free (dl_crypto *cr) {
  dl_free (cr->perm_first, sizeof (int) * (size_t)cr->val_n);
  dl_free (cr->perm_middle, sizeof (int) * (size_t)(cr->val_n + cr->rand_n));
  dl_free (cr->perm_last, sizeof (int) * (size_t)(cr->val_n + cr->rand_n));
}

