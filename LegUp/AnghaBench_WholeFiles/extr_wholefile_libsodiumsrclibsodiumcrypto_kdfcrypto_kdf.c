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
typedef  int /*<<< orphan*/  uint64_t ;

/* Variables and functions */
 size_t crypto_kdf_BYTES_MAX ; 
 size_t crypto_kdf_BYTES_MIN ; 
 size_t crypto_kdf_CONTEXTBYTES ; 
 size_t crypto_kdf_KEYBYTES ; 
 char const* crypto_kdf_PRIMITIVE ; 
 int crypto_kdf_blake2b_derive_from_key (unsigned char*,size_t,int /*<<< orphan*/ ,char const*,unsigned char const*) ; 
 int /*<<< orphan*/  randombytes_buf (unsigned char*,size_t) ; 

const char *
crypto_kdf_primitive(void)
{
    return crypto_kdf_PRIMITIVE;
}

size_t
crypto_kdf_bytes_min(void)
{
    return crypto_kdf_BYTES_MIN;
}

size_t
crypto_kdf_bytes_max(void)
{
    return crypto_kdf_BYTES_MAX;
}

size_t
crypto_kdf_contextbytes(void)
{
    return crypto_kdf_CONTEXTBYTES;
}

size_t
crypto_kdf_keybytes(void)
{
    return crypto_kdf_KEYBYTES;
}

int
crypto_kdf_derive_from_key(unsigned char *subkey, size_t subkey_len,
                           uint64_t subkey_id,
                           const char ctx[crypto_kdf_CONTEXTBYTES],
                           const unsigned char key[crypto_kdf_KEYBYTES])
{
    return crypto_kdf_blake2b_derive_from_key(subkey, subkey_len,
                                              subkey_id, ctx, key);
}

void
crypto_kdf_keygen(unsigned char k[crypto_kdf_KEYBYTES])
{
    randombytes_buf(k, crypto_kdf_KEYBYTES);
}

