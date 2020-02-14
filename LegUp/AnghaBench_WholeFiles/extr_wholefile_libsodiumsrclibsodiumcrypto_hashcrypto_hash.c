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

/* Variables and functions */
 size_t crypto_hash_BYTES ; 
 char const* crypto_hash_PRIMITIVE ; 
 int crypto_hash_sha512 (unsigned char*,unsigned char const*,unsigned long long) ; 

size_t
crypto_hash_bytes(void)
{
    return crypto_hash_BYTES;
}

int
crypto_hash(unsigned char *out, const unsigned char *in,
            unsigned long long inlen)
{
    return crypto_hash_sha512(out, in, inlen);
}

const char *
crypto_hash_primitive(void) {
    return crypto_hash_PRIMITIVE;
}

