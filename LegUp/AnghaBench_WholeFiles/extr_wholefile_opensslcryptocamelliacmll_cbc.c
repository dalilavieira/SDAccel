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
typedef  int /*<<< orphan*/  block128_f ;
typedef  int /*<<< orphan*/  CAMELLIA_KEY ;

/* Variables and functions */
 int /*<<< orphan*/  CRYPTO_cbc128_decrypt (unsigned char const*,unsigned char*,size_t,int /*<<< orphan*/  const*,unsigned char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CRYPTO_cbc128_encrypt (unsigned char const*,unsigned char*,size_t,int /*<<< orphan*/  const*,unsigned char*,int /*<<< orphan*/ ) ; 
 scalar_t__ Camellia_decrypt ; 
 scalar_t__ Camellia_encrypt ; 

void Camellia_cbc_encrypt(const unsigned char *in, unsigned char *out,
                          size_t len, const CAMELLIA_KEY *key,
                          unsigned char *ivec, const int enc)
{

    if (enc)
        CRYPTO_cbc128_encrypt(in, out, len, key, ivec,
                              (block128_f) Camellia_encrypt);
    else
        CRYPTO_cbc128_decrypt(in, out, len, key, ivec,
                              (block128_f) Camellia_decrypt);
}

