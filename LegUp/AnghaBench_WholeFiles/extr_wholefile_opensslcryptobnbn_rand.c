#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_33__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  random_bytes ;
typedef  int /*<<< orphan*/  private_bytes ;
typedef  int /*<<< orphan*/  done ;
struct TYPE_33__ {int top; unsigned char* d; scalar_t__ neg; } ;
typedef  int /*<<< orphan*/  SHA512_CTX ;
typedef  int /*<<< orphan*/  BN_CTX ;
typedef  scalar_t__ BNRAND_FLAG ;
typedef  TYPE_1__ BIGNUM ;

/* Variables and functions */
 int /*<<< orphan*/  BN_F_BNRAND ; 
 int /*<<< orphan*/  BN_F_BNRAND_RANGE ; 
 int /*<<< orphan*/  BN_F_BN_GENERATE_DSA_NONCE ; 
 int BN_RAND_BOTTOM_ANY ; 
 int BN_RAND_TOP_ANY ; 
 int /*<<< orphan*/  BN_R_BITS_TOO_SMALL ; 
 int /*<<< orphan*/  BN_R_INVALID_RANGE ; 
 int /*<<< orphan*/  BN_R_PRIVATE_KEY_TOO_LARGE ; 
 int /*<<< orphan*/  BN_R_TOO_MANY_ITERATIONS ; 
 int /*<<< orphan*/  BN_bin2bn (unsigned char*,unsigned int const,TYPE_1__*) ; 
 scalar_t__ BN_cmp (TYPE_1__*,TYPE_1__ const*) ; 
 int /*<<< orphan*/  BN_is_bit_set (TYPE_1__ const*,int) ; 
 scalar_t__ BN_is_zero (TYPE_1__ const*) ; 
 int BN_mod (TYPE_1__*,TYPE_1__*,TYPE_1__ const*,int /*<<< orphan*/ *) ; 
 int BN_num_bits (TYPE_1__ const*) ; 
 int BN_num_bytes (TYPE_1__ const*) ; 
 int /*<<< orphan*/  BN_sub (TYPE_1__*,TYPE_1__*,TYPE_1__ const*) ; 
 int /*<<< orphan*/  BN_zero (TYPE_1__*) ; 
 int /*<<< orphan*/  BNerr (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ERR_R_MALLOC_FAILURE ; 
 scalar_t__ NORMAL ; 
 int /*<<< orphan*/  OPENSSL_cleanse (unsigned char*,int) ; 
 int /*<<< orphan*/  OPENSSL_clear_free (unsigned char*,int) ; 
 int /*<<< orphan*/  OPENSSL_free (unsigned char*) ; 
 unsigned char* OPENSSL_malloc (unsigned int const) ; 
 scalar_t__ PRIVATE ; 
 scalar_t__ RAND_bytes (unsigned char*,int) ; 
 int RAND_priv_bytes (unsigned char*,int) ; 
 int SHA512_DIGEST_LENGTH ; 
 int /*<<< orphan*/  SHA512_Final (unsigned char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SHA512_Init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SHA512_Update (int /*<<< orphan*/ *,...) ; 
 scalar_t__ TESTING ; 
 int /*<<< orphan*/  bn_check_top (TYPE_1__*) ; 
 int /*<<< orphan*/  memcpy (unsigned char*,unsigned char*,unsigned int) ; 
 int /*<<< orphan*/  memset (unsigned char*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int bnrand(BNRAND_FLAG flag, BIGNUM *rnd, int bits, int top, int bottom)
{
    unsigned char *buf = NULL;
    int b, ret = 0, bit, bytes, mask;

    if (bits == 0) {
        if (top != BN_RAND_TOP_ANY || bottom != BN_RAND_BOTTOM_ANY)
            goto toosmall;
        BN_zero(rnd);
        return 1;
    }
    if (bits < 0 || (bits == 1 && top > 0))
        goto toosmall;

    bytes = (bits + 7) / 8;
    bit = (bits - 1) % 8;
    mask = 0xff << (bit + 1);

    buf = OPENSSL_malloc(bytes);
    if (buf == NULL) {
        BNerr(BN_F_BNRAND, ERR_R_MALLOC_FAILURE);
        goto err;
    }

    /* make a random number and set the top and bottom bits */
    b = flag == NORMAL ? RAND_bytes(buf, bytes) : RAND_priv_bytes(buf, bytes);
    if (b <= 0)
        goto err;

    if (flag == TESTING) {
        /*
         * generate patterns that are more likely to trigger BN library bugs
         */
        int i;
        unsigned char c;

        for (i = 0; i < bytes; i++) {
            if (RAND_bytes(&c, 1) <= 0)
                goto err;
            if (c >= 128 && i > 0)
                buf[i] = buf[i - 1];
            else if (c < 42)
                buf[i] = 0;
            else if (c < 84)
                buf[i] = 255;
        }
    }

    if (top >= 0) {
        if (top) {
            if (bit == 0) {
                buf[0] = 1;
                buf[1] |= 0x80;
            } else {
                buf[0] |= (3 << (bit - 1));
            }
        } else {
            buf[0] |= (1 << bit);
        }
    }
    buf[0] &= ~mask;
    if (bottom)                 /* set bottom bit if requested */
        buf[bytes - 1] |= 1;
    if (!BN_bin2bn(buf, bytes, rnd))
        goto err;
    ret = 1;
 err:
    OPENSSL_clear_free(buf, bytes);
    bn_check_top(rnd);
    return ret;

toosmall:
    BNerr(BN_F_BNRAND, BN_R_BITS_TOO_SMALL);
    return 0;
}

int BN_rand(BIGNUM *rnd, int bits, int top, int bottom)
{
    return bnrand(NORMAL, rnd, bits, top, bottom);
}

int BN_bntest_rand(BIGNUM *rnd, int bits, int top, int bottom)
{
    return bnrand(TESTING, rnd, bits, top, bottom);
}

int BN_priv_rand(BIGNUM *rnd, int bits, int top, int bottom)
{
    return bnrand(PRIVATE, rnd, bits, top, bottom);
}

__attribute__((used)) static int bnrand_range(BNRAND_FLAG flag, BIGNUM *r, const BIGNUM *range)
{
    int n;
    int count = 100;

    if (range->neg || BN_is_zero(range)) {
        BNerr(BN_F_BNRAND_RANGE, BN_R_INVALID_RANGE);
        return 0;
    }

    n = BN_num_bits(range);     /* n > 0 */

    /* BN_is_bit_set(range, n - 1) always holds */

    if (n == 1)
        BN_zero(r);
    else if (!BN_is_bit_set(range, n - 2) && !BN_is_bit_set(range, n - 3)) {
        /*
         * range = 100..._2, so 3*range (= 11..._2) is exactly one bit longer
         * than range
         */
        do {
            if (!bnrand(flag, r, n + 1, BN_RAND_TOP_ANY, BN_RAND_BOTTOM_ANY))
                return 0;

            /*
             * If r < 3*range, use r := r MOD range (which is either r, r -
             * range, or r - 2*range). Otherwise, iterate once more. Since
             * 3*range = 11..._2, each iteration succeeds with probability >=
             * .75.
             */
            if (BN_cmp(r, range) >= 0) {
                if (!BN_sub(r, r, range))
                    return 0;
                if (BN_cmp(r, range) >= 0)
                    if (!BN_sub(r, r, range))
                        return 0;
            }

            if (!--count) {
                BNerr(BN_F_BNRAND_RANGE, BN_R_TOO_MANY_ITERATIONS);
                return 0;
            }

        }
        while (BN_cmp(r, range) >= 0);
    } else {
        do {
            /* range = 11..._2  or  range = 101..._2 */
            if (!bnrand(flag, r, n, BN_RAND_TOP_ANY, BN_RAND_BOTTOM_ANY))
                return 0;

            if (!--count) {
                BNerr(BN_F_BNRAND_RANGE, BN_R_TOO_MANY_ITERATIONS);
                return 0;
            }
        }
        while (BN_cmp(r, range) >= 0);
    }

    bn_check_top(r);
    return 1;
}

int BN_rand_range(BIGNUM *r, const BIGNUM *range)
{
    return bnrand_range(NORMAL, r, range);
}

int BN_priv_rand_range(BIGNUM *r, const BIGNUM *range)
{
    return bnrand_range(PRIVATE, r, range);
}

int BN_pseudo_rand(BIGNUM *rnd, int bits, int top, int bottom)
{
    return BN_rand(rnd, bits, top, bottom);
}

int BN_pseudo_rand_range(BIGNUM *r, const BIGNUM *range)
{
    return BN_rand_range(r, range);
}

int BN_generate_dsa_nonce(BIGNUM *out, const BIGNUM *range,
                          const BIGNUM *priv, const unsigned char *message,
                          size_t message_len, BN_CTX *ctx)
{
    SHA512_CTX sha;
    /*
     * We use 512 bits of random data per iteration to ensure that we have at
     * least |range| bits of randomness.
     */
    unsigned char random_bytes[64];
    unsigned char digest[SHA512_DIGEST_LENGTH];
    unsigned done, todo;
    /* We generate |range|+8 bytes of random output. */
    const unsigned num_k_bytes = BN_num_bytes(range) + 8;
    unsigned char private_bytes[96];
    unsigned char *k_bytes;
    int ret = 0;

    k_bytes = OPENSSL_malloc(num_k_bytes);
    if (k_bytes == NULL)
        goto err;

    /* We copy |priv| into a local buffer to avoid exposing its length. */
    todo = sizeof(priv->d[0]) * priv->top;
    if (todo > sizeof(private_bytes)) {
        /*
         * No reasonable DSA or ECDSA key should have a private key this
         * large and we don't handle this case in order to avoid leaking the
         * length of the private key.
         */
        BNerr(BN_F_BN_GENERATE_DSA_NONCE, BN_R_PRIVATE_KEY_TOO_LARGE);
        goto err;
    }
    memcpy(private_bytes, priv->d, todo);
    memset(private_bytes + todo, 0, sizeof(private_bytes) - todo);

    for (done = 0; done < num_k_bytes;) {
        if (RAND_priv_bytes(random_bytes, sizeof(random_bytes)) != 1)
            goto err;
        SHA512_Init(&sha);
        SHA512_Update(&sha, &done, sizeof(done));
        SHA512_Update(&sha, private_bytes, sizeof(private_bytes));
        SHA512_Update(&sha, message, message_len);
        SHA512_Update(&sha, random_bytes, sizeof(random_bytes));
        SHA512_Final(digest, &sha);

        todo = num_k_bytes - done;
        if (todo > SHA512_DIGEST_LENGTH)
            todo = SHA512_DIGEST_LENGTH;
        memcpy(k_bytes + done, digest, todo);
        done += todo;
    }

    if (!BN_bin2bn(k_bytes, num_k_bytes, out))
        goto err;
    if (BN_mod(out, out, range, ctx) != 1)
        goto err;
    ret = 1;

 err:
    OPENSSL_free(k_bytes);
    OPENSSL_cleanse(private_bytes, sizeof(private_bytes));
    return ret;
}

