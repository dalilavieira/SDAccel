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
typedef  int prime_t ;
typedef  int /*<<< orphan*/  BIGNUM ;

/* Variables and functions */
 int /*<<< orphan*/  ADD_ALL_TESTS (int (*) (int),int) ; 
 int /*<<< orphan*/  ADD_TEST (int (*) ()) ; 
 int /*<<< orphan*/  BN_CTX_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * BN_CTX_new () ; 
 int /*<<< orphan*/  BN_PRIMETEST_PROBABLY_PRIME ; 
 int /*<<< orphan*/  BN_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  BN_mul_word (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/ * BN_new () ; 
 int /*<<< orphan*/  BN_set_word (int /*<<< orphan*/ *,int) ; 
 int NUMPRIMES ; 
 scalar_t__ OSSL_NELEM (int*) ; 
 int TEST_BN_eq (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ TEST_int_eq (int,int /*<<< orphan*/ ) ; 
 scalar_t__ TEST_int_ne (int,int /*<<< orphan*/ ) ; 
 scalar_t__ TEST_ptr (int /*<<< orphan*/ *) ; 
 scalar_t__ TEST_true (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bn_get0_small_factors () ; 
 int /*<<< orphan*/  bn_miller_rabin_is_prime (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,int*) ; 
 int* composites ; 
 int /*<<< orphan*/ * ctx ; 
 int* primes ; 

__attribute__((used)) static int test_is_prime_enhanced(void)
{
    int ret;
    int status = 0;
    BIGNUM *bn = NULL;

    ret = TEST_ptr(bn = BN_new())
          /* test passing a prime returns the correct status */
          && TEST_true(BN_set_word(bn, 11))
          /* return extra parameters related to composite */
          && TEST_true(bn_miller_rabin_is_prime(bn, 10, ctx, NULL, 1, &status))
          && TEST_int_eq(status, BN_PRIMETEST_PROBABLY_PRIME);
    BN_free(bn);
    return ret;
}

__attribute__((used)) static int test_is_composite_enhanced(int id)
{
    int ret;
    int status = 0;
    BIGNUM *bn = NULL;

    ret = TEST_ptr(bn = BN_new())
          /* negative tests for different composite numbers */
          && TEST_true(BN_set_word(bn, composites[id]))
          && TEST_true(bn_miller_rabin_is_prime(bn, 10, ctx, NULL, 1, &status))
          && TEST_int_ne(status, BN_PRIMETEST_PROBABLY_PRIME);

    BN_free(bn);
    return ret;
}

__attribute__((used)) static int test_bn_small_factors(void)
{
    int ret = 0, i;
    BIGNUM *b = NULL;

    if (!(TEST_ptr(b = BN_new()) && TEST_true(BN_set_word(b, 3))))
        goto err;

    for (i = 1; i < NUMPRIMES; i++) {
        prime_t p = primes[i];
        if (p > 3 && p <= 751 && !BN_mul_word(b, p))
            goto err;
        if (p > 751)
            break;
    }
    ret = TEST_BN_eq(bn_get0_small_factors(), b);
err:
    BN_free(b);
    return ret;
}

int setup_tests(void)
{
    if (!TEST_ptr(ctx = BN_CTX_new()))
        return 0;

    ADD_TEST(test_is_prime_enhanced);
    ADD_ALL_TESTS(test_is_composite_enhanced, (int)OSSL_NELEM(composites));
    ADD_TEST(test_bn_small_factors);

    return 1;
}

void cleanup_tests(void)
{
    BN_CTX_free(ctx);
}

