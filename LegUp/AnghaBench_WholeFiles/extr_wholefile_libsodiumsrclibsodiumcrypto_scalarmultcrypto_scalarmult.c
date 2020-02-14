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
 size_t crypto_scalarmult_BYTES ; 
 char const* crypto_scalarmult_PRIMITIVE ; 
 size_t crypto_scalarmult_SCALARBYTES ; 
 int crypto_scalarmult_curve25519 (unsigned char*,unsigned char const*,unsigned char const*) ; 
 int crypto_scalarmult_curve25519_base (unsigned char*,unsigned char const*) ; 

const char *
crypto_scalarmult_primitive(void)
{
    return crypto_scalarmult_PRIMITIVE;
}

int
crypto_scalarmult_base(unsigned char *q, const unsigned char *n)
{
    return crypto_scalarmult_curve25519_base(q, n);
}

int
crypto_scalarmult(unsigned char *q, const unsigned char *n,
                  const unsigned char *p)
{
    return crypto_scalarmult_curve25519(q, n, p);
}

size_t
crypto_scalarmult_bytes(void)
{
    return crypto_scalarmult_BYTES;
}

size_t
crypto_scalarmult_scalarbytes(void)
{
    return crypto_scalarmult_SCALARBYTES;
}

