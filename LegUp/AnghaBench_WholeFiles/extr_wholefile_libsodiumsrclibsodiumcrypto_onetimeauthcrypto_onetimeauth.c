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
typedef  int /*<<< orphan*/  crypto_onetimeauth_state ;
typedef  int /*<<< orphan*/  crypto_onetimeauth_poly1305_state ;

/* Variables and functions */
 size_t crypto_onetimeauth_BYTES ; 
 size_t crypto_onetimeauth_KEYBYTES ; 
 char const* crypto_onetimeauth_PRIMITIVE ; 
 int crypto_onetimeauth_poly1305 (unsigned char*,unsigned char const*,unsigned long long,unsigned char const*) ; 
 int crypto_onetimeauth_poly1305_final (int /*<<< orphan*/ *,unsigned char*) ; 
 int crypto_onetimeauth_poly1305_init (int /*<<< orphan*/ *,unsigned char const*) ; 
 int crypto_onetimeauth_poly1305_update (int /*<<< orphan*/ *,unsigned char const*,unsigned long long) ; 
 int crypto_onetimeauth_poly1305_verify (unsigned char const*,unsigned char const*,unsigned long long,unsigned char const*) ; 
 int /*<<< orphan*/  randombytes_buf (unsigned char*,size_t) ; 

size_t
crypto_onetimeauth_statebytes(void)
{
    return sizeof(crypto_onetimeauth_state);
}

size_t
crypto_onetimeauth_bytes(void)
{
    return crypto_onetimeauth_BYTES;
}

size_t
crypto_onetimeauth_keybytes(void)
{
    return crypto_onetimeauth_KEYBYTES;
}

int
crypto_onetimeauth(unsigned char *out, const unsigned char *in,
                   unsigned long long inlen, const unsigned char *k)
{
    return crypto_onetimeauth_poly1305(out, in, inlen, k);
}

int
crypto_onetimeauth_verify(const unsigned char *h, const unsigned char *in,
                          unsigned long long inlen, const unsigned char *k)
{
    return crypto_onetimeauth_poly1305_verify(h, in, inlen, k);
}

int
crypto_onetimeauth_init(crypto_onetimeauth_state *state,
                        const unsigned char *key)
{
    return crypto_onetimeauth_poly1305_init
        ((crypto_onetimeauth_poly1305_state *) state, key);
}

int
crypto_onetimeauth_update(crypto_onetimeauth_state *state,
                          const unsigned char *in,
                          unsigned long long inlen)
{
    return crypto_onetimeauth_poly1305_update
        ((crypto_onetimeauth_poly1305_state *) state, in, inlen);
}

int
crypto_onetimeauth_final(crypto_onetimeauth_state *state,
                         unsigned char *out)
{
    return crypto_onetimeauth_poly1305_final
        ((crypto_onetimeauth_poly1305_state *) state, out);
}

const char *
crypto_onetimeauth_primitive(void)
{
    return crypto_onetimeauth_PRIMITIVE;
}

void crypto_onetimeauth_keygen(unsigned char k[crypto_onetimeauth_KEYBYTES])
{
    randombytes_buf(k, crypto_onetimeauth_KEYBYTES);
}

