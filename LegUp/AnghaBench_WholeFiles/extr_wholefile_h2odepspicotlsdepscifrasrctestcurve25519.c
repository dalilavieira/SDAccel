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
 int /*<<< orphan*/  cf_curve25519_mul (char*,char*,char*) ; 
 int /*<<< orphan*/  cf_curve25519_mul_base (char*,char*) ; 
 scalar_t__ memcmp (char*,char*,int) ; 
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

__attribute__((used)) static void test_base_mul(void)
{
  uint8_t secret[32];
  uint8_t public[32];
  uint8_t expect[32];

  unhex(secret, 32, "77076d0a7318a57d3c16c17251b26645df4c2f87ebc0992ab177fba51db92c2a");
  unhex(expect, 32, "8520f0098930a754748b7ddcb43ef75a0dbf3a0d26381af4eba4a98eaa9b4e6a");
  cf_curve25519_mul_base(public, secret);
  TEST_CHECK(memcmp(expect, public, 32) == 0);
  
  unhex(secret, 32, "5dab087e624a8a4b79e17f8b83800ee66f3bb1292618b6fd1c2f8b27ff88e0eb");
  unhex(expect, 32, "de9edb7d7b7dc1b4d35b61c2ece435373f8343c85b78674dadfc7e146f882b4f");
  cf_curve25519_mul_base(public, secret);
  TEST_CHECK(memcmp(expect, public, 32) == 0);
}

__attribute__((used)) static void test_mul(void)
{
  uint8_t scalar[32];
  uint8_t public[32];
  uint8_t shared[32];
  uint8_t expect[32];

  unhex(scalar, 32, "77076d0a7318a57d3c16c17251b26645df4c2f87ebc0992ab177fba51db92c2a");
  unhex(public, 32, "de9edb7d7b7dc1b4d35b61c2ece435373f8343c85b78674dadfc7e146f882b4f");
  unhex(expect, 32, "4a5d9d5ba4ce2de1728e3bf480350f25e07e21c947d19e3376f09b3c1e161742");
  cf_curve25519_mul(shared, scalar, public);
  TEST_CHECK(memcmp(expect, shared, 32) == 0);
}

