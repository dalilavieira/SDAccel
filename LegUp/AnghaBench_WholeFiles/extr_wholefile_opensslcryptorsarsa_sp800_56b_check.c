#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {int /*<<< orphan*/  const* q; int /*<<< orphan*/  const* p; int /*<<< orphan*/  const* e; int /*<<< orphan*/  const* n; int /*<<< orphan*/  const* d; int /*<<< orphan*/  const* iqmp; int /*<<< orphan*/  const* dmq1; int /*<<< orphan*/  const* dmp1; } ;
typedef  TYPE_1__ RSA ;
typedef  int /*<<< orphan*/  BN_CTX ;
typedef  int /*<<< orphan*/  const BIGNUM ;

/* Variables and functions */
 int /*<<< orphan*/  BN_CTX_end (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  BN_CTX_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  const* BN_CTX_get (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * BN_CTX_new () ; 
 int /*<<< orphan*/  BN_CTX_start (int /*<<< orphan*/ *) ; 
 int BN_PRIMETEST_COMPOSITE_NOT_POWER_OF_PRIME ; 
 int /*<<< orphan*/  BN_clear (int /*<<< orphan*/  const*) ; 
 scalar_t__ BN_cmp (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/ * BN_copy (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 
 scalar_t__ BN_div (int /*<<< orphan*/  const*,int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  BN_free (int /*<<< orphan*/  const*) ; 
 scalar_t__ BN_gcd (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/ *) ; 
 scalar_t__ BN_is_odd (int /*<<< orphan*/  const*) ; 
 scalar_t__ BN_is_one (int /*<<< orphan*/  const*) ; 
 int BN_is_prime_fasttest_ex (int /*<<< orphan*/  const*,int,int /*<<< orphan*/ *,int,int /*<<< orphan*/ *) ; 
 scalar_t__ BN_is_zero (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  BN_lshift (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int) ; 
 scalar_t__ BN_mod_mul (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/ *) ; 
 scalar_t__ BN_mul (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  const* BN_new () ; 
 int BN_num_bits (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  BN_rshift (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int) ; 
 int /*<<< orphan*/  BN_set_negative (int /*<<< orphan*/  const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BN_set_word (int /*<<< orphan*/  const*,int) ; 
 scalar_t__ BN_sub (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 
 scalar_t__ BN_sub_word (int /*<<< orphan*/  const*,int) ; 
 int /*<<< orphan*/  const* BN_value_one () ; 
 int /*<<< orphan*/  RSA_F_RSA_SP800_56B_CHECK_KEYPAIR ; 
 int /*<<< orphan*/  RSA_F_RSA_SP800_56B_CHECK_PUBLIC ; 
 int /*<<< orphan*/  RSA_R_INVALID_KEYPAIR ; 
 int /*<<< orphan*/  RSA_R_INVALID_KEY_LENGTH ; 
 int /*<<< orphan*/  RSA_R_INVALID_MODULUS ; 
 int /*<<< orphan*/  RSA_R_INVALID_REQUEST ; 
 int /*<<< orphan*/  RSA_R_PUB_EXPONENT_OUT_OF_RANGE ; 
 int /*<<< orphan*/  RSAerr (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  const* bn_get0_small_factors () ; 
 int bn_miller_rabin_is_prime (int /*<<< orphan*/  const*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,int*) ; 
 int bn_rsa_fips186_4_prime_MR_min_checks (int) ; 
 int rsa_get_lcm (int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  rsa_sp800_56b_validate_strength (int,int) ; 

int rsa_check_crt_components(const RSA *rsa, BN_CTX *ctx)
{
    int ret = 0;
    BIGNUM *r = NULL, *p1 = NULL, *q1 = NULL;

    /* check if only some of the crt components are set */
    if (rsa->dmp1 == NULL || rsa->dmq1 == NULL || rsa->iqmp == NULL) {
        if (rsa->dmp1 != NULL || rsa->dmq1 != NULL || rsa->iqmp != NULL)
            return 0;
        return 1; /* return ok if all components are NULL */
    }

    BN_CTX_start(ctx);
    r = BN_CTX_get(ctx);
    p1 = BN_CTX_get(ctx);
    q1 = BN_CTX_get(ctx);
    ret = (q1 != NULL)
          /* p1 = p -1 */
          && (BN_copy(p1, rsa->p) != NULL)
          && BN_sub_word(p1, 1)
          /* q1 = q - 1 */
          && (BN_copy(q1, rsa->q) != NULL)
          && BN_sub_word(q1, 1)
          /* (a) 1 < dP < (p – 1). */
          && (BN_cmp(rsa->dmp1, BN_value_one()) > 0)
          && (BN_cmp(rsa->dmp1, p1) < 0)
          /* (b) 1 < dQ < (q - 1). */
          && (BN_cmp(rsa->dmq1, BN_value_one()) > 0)
          && (BN_cmp(rsa->dmq1, q1) < 0)
          /* (c) 1 < qInv < p */
          && (BN_cmp(rsa->iqmp, BN_value_one()) > 0)
          && (BN_cmp(rsa->iqmp, rsa->p) < 0)
          /* (d) 1 = (dP . e) mod (p - 1)*/
          && BN_mod_mul(r, rsa->dmp1, rsa->e, p1, ctx)
          && BN_is_one(r)
          /* (e) 1 = (dQ . e) mod (q - 1) */
          && BN_mod_mul(r, rsa->dmq1, rsa->e, q1, ctx)
          && BN_is_one(r)
          /* (f) 1 = (qInv . q) mod p */
          && BN_mod_mul(r, rsa->iqmp, rsa->q, rsa->p, ctx)
          && BN_is_one(r);
    BN_clear(p1);
    BN_clear(q1);
    BN_CTX_end(ctx);
    return ret;
}

int rsa_check_prime_factor_range(const BIGNUM *p, int nbits, BN_CTX *ctx)
{
    int ret = 0;
    BIGNUM *tmp, *low;

    nbits >>= 1;

    /* Upper bound check */
    if (BN_num_bits(p) != nbits)
        return 0;

    BN_CTX_start(ctx);
    tmp = BN_CTX_get(ctx);
    low = BN_CTX_get(ctx);

    /* set low = (√2)(2^(nbits/2 - 1) */
    if (low == NULL || !BN_set_word(tmp, 0xB504F334))
        goto err;

    if (nbits >= 32) {
        if (!BN_lshift(low, tmp, nbits - 32))
            goto err;
    } else if (!BN_rshift(low, tmp, 32 - nbits)) {
        goto err;
    }
    if (BN_cmp(p, low) < 0)
        goto err;
    ret = 1;
err:
    BN_CTX_end(ctx);
    return ret;
}

int rsa_check_prime_factor(BIGNUM *p, BIGNUM *e, int nbits, BN_CTX *ctx)
{
    int checks = bn_rsa_fips186_4_prime_MR_min_checks(nbits);
    int ret = 0;
    BIGNUM *p1 = NULL, *gcd = NULL;

    /* (Steps 5 a-b) prime test */
    if (BN_is_prime_fasttest_ex(p, checks, ctx, 1, NULL) != 1
            /* (Step 5c) (√2)(2^(nbits/2 - 1) <= p <= 2^(nbits/2 - 1) */
            || rsa_check_prime_factor_range(p, nbits, ctx) != 1)
        return 0;

    BN_CTX_start(ctx);
    p1 = BN_CTX_get(ctx);
    gcd = BN_CTX_get(ctx);
    ret = (gcd != NULL)
          /* (Step 5d) GCD(p-1, e) = 1 */
          && (BN_copy(p1, p) != NULL)
          && BN_sub_word(p1, 1)
          && BN_gcd(gcd, p1, e, ctx)
          && BN_is_one(gcd);

    BN_clear(p1);
    BN_CTX_end(ctx);
    return ret;
}

int rsa_check_private_exponent(const RSA *rsa, int nbits, BN_CTX *ctx)
{
    int ret;
    BIGNUM *r, *p1, *q1, *lcm, *p1q1, *gcd;

    /* (Step 6a) 2^(nbits/2) < d */
    if (BN_num_bits(rsa->d) <= (nbits >> 1))
        return 0;

    BN_CTX_start(ctx);
    r = BN_CTX_get(ctx);
    p1 = BN_CTX_get(ctx);
    q1 = BN_CTX_get(ctx);
    lcm = BN_CTX_get(ctx);
    p1q1 = BN_CTX_get(ctx);
    gcd = BN_CTX_get(ctx);
    ret = (gcd != NULL
          /* LCM(p - 1, q - 1) */
          && (rsa_get_lcm(ctx, rsa->p, rsa->q, lcm, gcd, p1, q1, p1q1) == 1)
          /* (Step 6a) d < LCM(p - 1, q - 1) */
          && (BN_cmp(rsa->d, lcm) < 0)
          /* (Step 6b) 1 = (e . d) mod LCM(p - 1, q - 1) */
          && BN_mod_mul(r, rsa->e, rsa->d, lcm, ctx)
          && BN_is_one(r));

    BN_clear(p1);
    BN_clear(q1);
    BN_clear(lcm);
    BN_clear(gcd);
    BN_CTX_end(ctx);
    return ret;
}

int rsa_check_public_exponent(const BIGNUM *e)
{
    int bitlen = BN_num_bits(e);

    return (BN_is_odd(e) &&  bitlen > 16 && bitlen < 257);
}

int rsa_check_pminusq_diff(BIGNUM *diff, const BIGNUM *p, const BIGNUM *q,
                           int nbits)
{
    int bitlen = (nbits >> 1) - 100;

    if (!BN_sub(diff, p, q))
        return -1;
    BN_set_negative(diff, 0);

    if (BN_is_zero(diff))
        return 0;

    if (!BN_sub_word(diff, 1))
        return -1;
    return (BN_num_bits(diff) > bitlen);
}

int rsa_get_lcm(BN_CTX *ctx, const BIGNUM *p, const BIGNUM *q,
                BIGNUM *lcm, BIGNUM *gcd, BIGNUM *p1, BIGNUM *q1,
                BIGNUM *p1q1)
{
    return BN_sub(p1, p, BN_value_one())    /* p-1 */
           && BN_sub(q1, q, BN_value_one()) /* q-1 */
           && BN_mul(p1q1, p1, q1, ctx)     /* (p-1)(q-1) */
           && BN_gcd(gcd, p1, q1, ctx)
           && BN_div(lcm, NULL, p1q1, gcd, ctx); /* LCM((p-1, q-1)) */
}

int rsa_sp800_56b_check_public(const RSA *rsa)
{
    int ret = 0, nbits, iterations, status;
    BN_CTX *ctx = NULL;
    BIGNUM *gcd = NULL;

    if (rsa->n == NULL || rsa->e == NULL)
        return 0;

    /*
     * (Step a): modulus must be 2048 or 3072 (caveat from SP800-56Br1)
     * NOTE: changed to allow keys >= 2048
     */
    nbits = BN_num_bits(rsa->n);
    if (!rsa_sp800_56b_validate_strength(nbits, -1)) {
        RSAerr(RSA_F_RSA_SP800_56B_CHECK_PUBLIC, RSA_R_INVALID_KEY_LENGTH);
        return 0;
    }
    if (!BN_is_odd(rsa->n)) {
        RSAerr(RSA_F_RSA_SP800_56B_CHECK_PUBLIC, RSA_R_INVALID_MODULUS);
        return 0;
    }

    /* (Steps b-c): 2^16 < e < 2^256, n and e must be odd */
    if (!rsa_check_public_exponent(rsa->e)) {
        RSAerr(RSA_F_RSA_SP800_56B_CHECK_PUBLIC,
               RSA_R_PUB_EXPONENT_OUT_OF_RANGE);
        return 0;
    }

    ctx = BN_CTX_new();
    gcd = BN_new();
    if (ctx == NULL || gcd == NULL)
        goto err;

    iterations = bn_rsa_fips186_4_prime_MR_min_checks(nbits);
    /* (Steps d-f):
     * The modulus is composite, but not a power of a prime.
     * The modulus has no factors smaller than 752.
     */
    if (!BN_gcd(gcd, rsa->n, bn_get0_small_factors(), ctx) || !BN_is_one(gcd)) {
        RSAerr(RSA_F_RSA_SP800_56B_CHECK_PUBLIC, RSA_R_INVALID_MODULUS);
        goto err;
    }

    ret = bn_miller_rabin_is_prime(rsa->n, iterations, ctx, NULL, 1, &status);
    if (ret != 1 || status != BN_PRIMETEST_COMPOSITE_NOT_POWER_OF_PRIME) {
        RSAerr(RSA_F_RSA_SP800_56B_CHECK_PUBLIC, RSA_R_INVALID_MODULUS);
        ret = 0;
        goto err;
    }

    ret = 1;
err:
    BN_free(gcd);
    BN_CTX_free(ctx);
    return ret;
}

int rsa_sp800_56b_check_private(const RSA *rsa)
{
    if (rsa->d == NULL || rsa->n == NULL)
        return 0;
    return BN_cmp(rsa->d, BN_value_one()) >= 0 && BN_cmp(rsa->d, rsa->n) < 0;
}

int rsa_sp800_56b_check_keypair(const RSA *rsa, const BIGNUM *efixed,
                                int strength, int nbits)
{
    int ret = 0;
    BN_CTX *ctx = NULL;
    BIGNUM *r = NULL;

    if (rsa->p == NULL
            || rsa->q == NULL
            || rsa->e == NULL
            || rsa->d == NULL
            || rsa->n == NULL) {
        RSAerr(RSA_F_RSA_SP800_56B_CHECK_KEYPAIR, RSA_R_INVALID_REQUEST);
        return 0;
    }
    /* (Step 1): Check Ranges */
    if (!rsa_sp800_56b_validate_strength(nbits, strength))
        return 0;

    /* If the exponent is known */
    if (efixed != NULL) {
        /* (2): Check fixed exponent matches public exponent. */
        if (BN_cmp(efixed, rsa->e) != 0) {
            RSAerr(RSA_F_RSA_SP800_56B_CHECK_KEYPAIR, RSA_R_INVALID_REQUEST);
            return 0;
        }
    }
    /* (Step 1.c): e is odd integer 65537 <= e < 2^256 */
    if (!rsa_check_public_exponent(rsa->e)) {
        /* exponent out of range */
        RSAerr(RSA_F_RSA_SP800_56B_CHECK_KEYPAIR,
               RSA_R_PUB_EXPONENT_OUT_OF_RANGE);
        return 0;
    }
    /* (Step 3.b): check the modulus */
    if (nbits != BN_num_bits(rsa->n)) {
        RSAerr(RSA_F_RSA_SP800_56B_CHECK_KEYPAIR, RSA_R_INVALID_KEYPAIR);
        return 0;
    }

    ctx = BN_CTX_new();
    if (ctx == NULL)
        return 0;

    BN_CTX_start(ctx);
    r = BN_CTX_get(ctx);
    if (r == NULL || !BN_mul(r, rsa->p, rsa->q, ctx))
        goto err;
    /* (Step 4.c): Check n = pq */
    if (BN_cmp(rsa->n, r) != 0) {
        RSAerr(RSA_F_RSA_SP800_56B_CHECK_KEYPAIR, RSA_R_INVALID_REQUEST);
        goto err;
    }

    /* (Step 5): check prime factors p & q */
    ret = rsa_check_prime_factor(rsa->p, rsa->e, nbits, ctx)
          && rsa_check_prime_factor(rsa->q, rsa->e, nbits, ctx)
          && (rsa_check_pminusq_diff(r, rsa->p, rsa->q, nbits) > 0)
          /* (Step 6): Check the private exponent d */
          && rsa_check_private_exponent(rsa, nbits, ctx)
          /* 6.4.1.2.3 (Step 7): Check the CRT components */
          && rsa_check_crt_components(rsa, ctx);
    if (ret != 1)
        RSAerr(RSA_F_RSA_SP800_56B_CHECK_KEYPAIR, RSA_R_INVALID_KEYPAIR);

err:
    BN_clear(r);
    BN_CTX_end(ctx);
    BN_CTX_free(ctx);
    return ret;
}

