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
typedef  int uint8_t ;
typedef  int /*<<< orphan*/  EVP_MD_CTX ;
typedef  int /*<<< orphan*/  EVP_MD ;

/* Variables and functions */
 int /*<<< orphan*/  EVP_DigestFinal (int /*<<< orphan*/ *,int*,unsigned int*) ; 
 int /*<<< orphan*/  EVP_DigestInit (int /*<<< orphan*/ *,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  EVP_DigestUpdate (int /*<<< orphan*/ *,int*,unsigned int) ; 
 int EVP_MAX_MD_SIZE ; 
 int /*<<< orphan*/ * EVP_sha1 () ; 
 int /*<<< orphan*/ * EVP_sha224 () ; 
 int /*<<< orphan*/ * EVP_sha256 () ; 
 int /*<<< orphan*/ * EVP_sha384 () ; 
 int /*<<< orphan*/ * EVP_sha512 () ; 
 size_t MAX_LENGTH ; 
 int /*<<< orphan*/  printf (char*,...) ; 

__attribute__((used)) static void printhex(const uint8_t *buf, size_t len)
{
  for (size_t i = 0; i < len; i++)
    printf("%02x", buf[i]);
}

__attribute__((used)) static void emit_length_test(const char *name, const EVP_MD *h, size_t max)
{
  EVP_MD_CTX outer, inner;
  EVP_DigestInit(&outer, h);
  uint8_t digest[EVP_MAX_MD_SIZE];
  unsigned int digestlen;

  for (size_t n = 0; n < max; n++)
  {
    EVP_DigestInit(&inner, h);
    for (size_t i = 0; i < n; i++)
    {
      uint8_t byte = n & 0xff;
      EVP_DigestUpdate(&inner, &byte, 1);
    }
    digestlen = sizeof digest;
    EVP_DigestFinal(&inner, digest, &digestlen);

    EVP_DigestUpdate(&outer, digest, digestlen);
  }

  digestlen = sizeof digest;
  EVP_DigestFinal(&outer, digest, &digestlen);

  printf("%s(%zu) = ", name, max);
  printhex(digest, (size_t) digestlen);
  printf("\n");
}

int main(void)
{
  emit_length_test("SHA1", EVP_sha1(), MAX_LENGTH);
  emit_length_test("SHA224", EVP_sha224(), MAX_LENGTH);
  emit_length_test("SHA256", EVP_sha256(), MAX_LENGTH);
  emit_length_test("SHA384", EVP_sha384(), MAX_LENGTH);
  emit_length_test("SHA512", EVP_sha512(), MAX_LENGTH);
  return 0;
}

