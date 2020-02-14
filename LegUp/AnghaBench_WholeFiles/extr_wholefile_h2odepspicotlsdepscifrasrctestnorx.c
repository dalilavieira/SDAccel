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
typedef  char uint8_t ;

/* Variables and functions */
 int /*<<< orphan*/  TEST_CHECK (int) ; 
 int /*<<< orphan*/  assert (size_t) ; 
 scalar_t__ cf_norx32_decrypt (char*,char*,char*,size_t,char*,size_t,char*,int,char*,char*) ; 
 int /*<<< orphan*/  cf_norx32_encrypt (char*,char*,char*,size_t,char*,size_t,char*,int,char*,char*) ; 
 char* kat_data ; 
 scalar_t__ memcmp (char const*,char*,size_t) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int strlen (char const*) ; 

__attribute__((used)) static inline uint8_t unhex_chr(char a)
{
  if (a >= '0' && a <= '9')
    return a - '0';
  else if (a >= 'a' && a <= 'f')
    return a - 'a' + 10;
  else if (a >= 'A' && a <= 'F')
    return a - 'A' + 10;
  return 0;
}

__attribute__((used)) static inline size_t unhex(uint8_t *buf, size_t len, const char *str)
{
  size_t used = 0;

  assert(strlen(str) % 2 == 0);
  assert(strlen(str) / 2 <= len);

  while (*str)
  {
    assert(len);
    *buf = unhex_chr(str[0]) << 4 | unhex_chr(str[1]);
    buf++;
    used++;
    str += 2;
    len--;
  }

  return used;
}

__attribute__((used)) static inline void dump(const char *label, const uint8_t *buf, size_t len)
{
  printf("%s: ", label);
  for (size_t i = 0; i < len; i++)
    printf("%02x", buf[i]);
  printf("\n");
}

__attribute__((used)) static void test_vector(void)
{
  uint8_t K[16], N[8], A[128], M[128], Z[128], C[128], T[16];

  /* This is from the v2.0 paper, section A.2. */

  unhex(K, sizeof K, "000102030405060708090a0b0c0d0e0f");
  unhex(N, sizeof N, "f0e0d0c0b0a09080");

  for (unsigned i = 0; i < 128; i++)
  {
    A[i] = M[i] = Z[i] = i;
  }

  cf_norx32_encrypt(K, N,
                    A, sizeof A,
                    M, sizeof M,
                    Z, sizeof Z,
                    C, T);

  uint8_t expect_C[128], expect_T[16];

  unhex(expect_C, sizeof expect_C, "f4afc8e66d2d80de0a7f719c899624c9ad896ec7c61739d5376d0648c7bcb204e57db05c6f83b3ff4315e8a4ef2f2c855f21ea4c51ac6de575773ba548f36e636a13b979d953bb91298ea4a6e2aa27402991e0da541997825407b2f12441de3ae6c5dbfe41b12f1480d234832765111e4c09deef9fe3971618d2217c4b77921e");
  unhex(expect_T, sizeof expect_T, "7810131eea2eab1e5da05d23d4e3cb99");

  TEST_CHECK(memcmp(C, expect_C, sizeof C) == 0);
  TEST_CHECK(memcmp(T, expect_T, sizeof T) == 0);

  uint8_t M2[128];
  TEST_CHECK(0 ==
             cf_norx32_decrypt(K, N,
                               A, sizeof A,
                               C, sizeof C,
                               Z, sizeof Z,
                               T,
                               M2));

  TEST_CHECK(memcmp(M, M2, sizeof M) == 0);
  T[0] ^= 0xff;

  TEST_CHECK(cf_norx32_decrypt(K, N,
                               A, sizeof A,
                               C, sizeof C,
                               Z, sizeof Z,
                               T,
                               M2));
}

__attribute__((used)) static void test_kat(void)
{
  uint8_t K[16], N[16], H[256], W[256];
  const uint8_t *kats = kat_data;

#define FILL(arr, c) \
  do { \
    for (size_t i = 0; i < sizeof arr; i++) \
      arr[i] = (i * c + 123) & 0xff; \
  } while (0)
  FILL(N, 181);
  FILL(K, 191);
  FILL(H, 193);
  FILL(W, 197);
#undef FILL

  for (size_t i = 0; i < sizeof W; i++)
  {
    uint8_t C[256];
    uint8_t A[16];

    cf_norx32_encrypt(K, N,
                      H, i,
                      W, i,
                      NULL, 0,
                      C, A);

    TEST_CHECK(memcmp(kats, C, i) == 0);
    kats += i;
    TEST_CHECK(memcmp(kats, A, sizeof A) == 0);
    kats += sizeof A;

    uint8_t M[256] = { 0 };
    TEST_CHECK(0 == cf_norx32_decrypt(K, N,
                                      H, i,
                                      C, i,
                                      NULL, 0,
                                      A, M));

    TEST_CHECK(0 == memcmp(M, W, i));
  }
}

