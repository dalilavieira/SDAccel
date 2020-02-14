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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  uint64_t ;
typedef  int /*<<< orphan*/  crypto_generichash_blake2b_state ;
typedef  int /*<<< orphan*/  blake2b_state ;

/* Variables and functions */
 size_t BLAKE2B_KEYBYTES ; 
 size_t BLAKE2B_OUTBYTES ; 
 int /*<<< orphan*/  COMPILER_ASSERT (int) ; 
 unsigned long long UINT64_MAX ; 
 size_t UINT8_MAX ; 
 int /*<<< orphan*/  assert (int) ; 
 int blake2b (int /*<<< orphan*/ *,unsigned char const*,unsigned char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int blake2b_final (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ blake2b_init (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ blake2b_init_key (int /*<<< orphan*/ *,int /*<<< orphan*/ ,unsigned char const*,int /*<<< orphan*/ ) ; 
 scalar_t__ blake2b_init_key_salt_personal (int /*<<< orphan*/ *,int /*<<< orphan*/ ,unsigned char const*,int /*<<< orphan*/ ,unsigned char const*,unsigned char const*) ; 
 scalar_t__ blake2b_init_salt_personal (int /*<<< orphan*/ *,int /*<<< orphan*/ ,unsigned char const*,unsigned char const*) ; 
 int blake2b_pick_best_implementation () ; 
 int blake2b_salt_personal (int /*<<< orphan*/ *,unsigned char const*,unsigned char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned char const*,unsigned char const*) ; 
 int blake2b_update (int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int /*<<< orphan*/ ) ; 

int
crypto_generichash_blake2b(unsigned char *out, size_t outlen,
                           const unsigned char *in, unsigned long long inlen,
                           const unsigned char *key, size_t keylen)
{
    if (outlen <= 0U || outlen > BLAKE2B_OUTBYTES ||
        keylen > BLAKE2B_KEYBYTES || inlen > UINT64_MAX) {
        return -1;
    }
    assert(outlen <= UINT8_MAX);
    assert(keylen <= UINT8_MAX);

    return blake2b((uint8_t *) out, in, key, (uint8_t) outlen, (uint64_t) inlen,
                   (uint8_t) keylen);
}

int
crypto_generichash_blake2b_salt_personal(
    unsigned char *out, size_t outlen, const unsigned char *in,
    unsigned long long inlen, const unsigned char *key, size_t keylen,
    const unsigned char *salt, const unsigned char *personal)
{
    if (outlen <= 0U || outlen > BLAKE2B_OUTBYTES ||
        keylen > BLAKE2B_KEYBYTES || inlen > UINT64_MAX) {
        return -1;
    }
    assert(outlen <= UINT8_MAX);
    assert(keylen <= UINT8_MAX);

    return blake2b_salt_personal((uint8_t *) out, in, key, (uint8_t) outlen,
                                 (uint64_t) inlen, (uint8_t) keylen, salt,
                                 personal);
}

int
crypto_generichash_blake2b_init(crypto_generichash_blake2b_state *state,
                                const unsigned char *key, const size_t keylen,
                                const size_t outlen)
{
    if (outlen <= 0U || outlen > BLAKE2B_OUTBYTES ||
        keylen > BLAKE2B_KEYBYTES) {
        return -1;
    }
    assert(outlen <= UINT8_MAX);
    assert(keylen <= UINT8_MAX);
    COMPILER_ASSERT(sizeof(blake2b_state) <= sizeof *state);
    if (key == NULL || keylen <= 0U) {
        if (blake2b_init((blake2b_state *) (void *) state, (uint8_t) outlen) != 0) {
            return -1; /* LCOV_EXCL_LINE */
        }
    } else if (blake2b_init_key((blake2b_state *) (void *) state, (uint8_t) outlen, key,
                                (uint8_t) keylen) != 0) {
        return -1; /* LCOV_EXCL_LINE */
    }
    return 0;
}

int
crypto_generichash_blake2b_init_salt_personal(
    crypto_generichash_blake2b_state *state, const unsigned char *key,
    const size_t keylen, const size_t outlen, const unsigned char *salt,
    const unsigned char *personal)
{
    if (outlen <= 0U || outlen > BLAKE2B_OUTBYTES ||
        keylen > BLAKE2B_KEYBYTES) {
        return -1;
    }
    assert(outlen <= UINT8_MAX);
    assert(keylen <= UINT8_MAX);
    if (key == NULL || keylen <= 0U) {
        if (blake2b_init_salt_personal((blake2b_state *) (void *) state,
                                       (uint8_t) outlen, salt, personal) != 0) {
            return -1; /* LCOV_EXCL_LINE */
        }
    } else if (blake2b_init_key_salt_personal((blake2b_state *) (void *) state,
                                              (uint8_t) outlen, key,
                                              (uint8_t) keylen, salt,
                                              personal) != 0) {
        return -1; /* LCOV_EXCL_LINE */
    }
    return 0;
}

int
crypto_generichash_blake2b_update(crypto_generichash_blake2b_state *state,
                                  const unsigned char *in,
                                  unsigned long long inlen)
{
    return blake2b_update((blake2b_state *) (void *) state,
                          (const uint8_t *) in, (uint64_t) inlen);
}

int
crypto_generichash_blake2b_final(crypto_generichash_blake2b_state *state,
                                 unsigned char *out, const size_t outlen)
{
    assert(outlen <= UINT8_MAX);
    return blake2b_final((blake2b_state *) (void *) state,
                         (uint8_t *) out, (uint8_t) outlen);
}

int
_crypto_generichash_blake2b_pick_best_implementation(void)
{
    return blake2b_pick_best_implementation();
}

