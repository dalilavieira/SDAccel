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
struct TYPE_6__ {int /*<<< orphan*/  hs; } ;
typedef  TYPE_1__ crypto_sign_ed25519ph_state ;

/* Variables and functions */
 int _crypto_sign_ed25519_detached (unsigned char*,unsigned long long*,unsigned char*,int,unsigned char const*,int) ; 
 int _crypto_sign_ed25519_verify_detached (unsigned char const*,unsigned char*,int,unsigned char const*,int) ; 
 int crypto_hash_sha512_BYTES ; 
 int /*<<< orphan*/  crypto_hash_sha512_final (int /*<<< orphan*/ *,unsigned char*) ; 
 int /*<<< orphan*/  crypto_hash_sha512_init (int /*<<< orphan*/ *) ; 
 int crypto_hash_sha512_update (int /*<<< orphan*/ *,unsigned char const*,unsigned long long) ; 
 size_t crypto_sign_ed25519_BYTES ; 
 size_t crypto_sign_ed25519_MESSAGEBYTES_MAX ; 
 size_t crypto_sign_ed25519_PUBLICKEYBYTES ; 
 size_t crypto_sign_ed25519_SECRETKEYBYTES ; 
 size_t crypto_sign_ed25519_SEEDBYTES ; 
 int /*<<< orphan*/  memmove (unsigned char*,unsigned char const*,size_t) ; 

size_t
crypto_sign_ed25519ph_statebytes(void)
{
    return sizeof(crypto_sign_ed25519ph_state);
}

size_t
crypto_sign_ed25519_bytes(void)
{
    return crypto_sign_ed25519_BYTES;
}

size_t
crypto_sign_ed25519_seedbytes(void)
{
    return crypto_sign_ed25519_SEEDBYTES;
}

size_t
crypto_sign_ed25519_publickeybytes(void)
{
    return crypto_sign_ed25519_PUBLICKEYBYTES;
}

size_t
crypto_sign_ed25519_secretkeybytes(void)
{
    return crypto_sign_ed25519_SECRETKEYBYTES;
}

size_t
crypto_sign_ed25519_messagebytes_max(void)
{
    return crypto_sign_ed25519_MESSAGEBYTES_MAX;
}

int
crypto_sign_ed25519_sk_to_seed(unsigned char *seed, const unsigned char *sk)
{
    memmove(seed, sk, crypto_sign_ed25519_SEEDBYTES);

    return 0;
}

int
crypto_sign_ed25519_sk_to_pk(unsigned char *pk, const unsigned char *sk)
{
    memmove(pk, sk + crypto_sign_ed25519_SEEDBYTES,
            crypto_sign_ed25519_PUBLICKEYBYTES);
    return 0;
}

int
crypto_sign_ed25519ph_init(crypto_sign_ed25519ph_state *state)
{
    crypto_hash_sha512_init(&state->hs);
    return 0;
}

int
crypto_sign_ed25519ph_update(crypto_sign_ed25519ph_state *state,
                             const unsigned char *m, unsigned long long mlen)
{
    return crypto_hash_sha512_update(&state->hs, m, mlen);
}

int
crypto_sign_ed25519ph_final_create(crypto_sign_ed25519ph_state *state,
                                   unsigned char               *sig,
                                   unsigned long long          *siglen_p,
                                   const unsigned char         *sk)
{
    unsigned char ph[crypto_hash_sha512_BYTES];

    crypto_hash_sha512_final(&state->hs, ph);

    return _crypto_sign_ed25519_detached(sig, siglen_p, ph, sizeof ph, sk, 1);
}

int
crypto_sign_ed25519ph_final_verify(crypto_sign_ed25519ph_state *state,
                                   const unsigned char         *sig,
                                   const unsigned char         *pk)
{
    unsigned char ph[crypto_hash_sha512_BYTES];

    crypto_hash_sha512_final(&state->hs, ph);

    return _crypto_sign_ed25519_verify_detached(sig, ph, sizeof ph, pk, 1);
}

