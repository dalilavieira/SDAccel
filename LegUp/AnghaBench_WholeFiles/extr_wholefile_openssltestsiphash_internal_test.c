#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  key ;
typedef  int /*<<< orphan*/  in ;
struct TYPE_12__ {int /*<<< orphan*/  member_0; } ;
struct TYPE_10__ {unsigned char* data; size_t size; } ;
struct TYPE_11__ {size_t idx; TYPE_1__ expected; } ;
typedef  TYPE_2__ TESTDATA ;
typedef  TYPE_3__ SIPHASH ;

/* Variables and functions */
 int /*<<< orphan*/  ADD_ALL_TESTS (int (*) (int),int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ADD_TEST (int (*) ()) ; 
 int /*<<< orphan*/  OSSL_NELEM (TYPE_2__*) ; 
 int SIPHASH_KEY_SIZE ; 
 int SIPHASH_MAX_DIGEST_SIZE ; 
 size_t SIPHASH_MIN_DIGEST_SIZE ; 
 int /*<<< orphan*/  SipHash_Final (TYPE_3__*,unsigned char*,int) ; 
 int /*<<< orphan*/  SipHash_Init (TYPE_3__*,unsigned char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SipHash_Update (TYPE_3__*,unsigned char*,size_t) ; 
 int /*<<< orphan*/  SipHash_set_hash_size (TYPE_3__*,int) ; 
 int /*<<< orphan*/  TEST_info (char*,int,...) ; 
 scalar_t__ TEST_int_eq (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TEST_int_le (size_t,int) ; 
 int /*<<< orphan*/  TEST_mem_eq (unsigned char*,size_t,unsigned char*,size_t) ; 
 scalar_t__ TEST_true (int /*<<< orphan*/ ) ; 
 TYPE_2__* tests ; 

__attribute__((used)) static int test_siphash(int idx)
{
    SIPHASH siphash = { 0, };
    TESTDATA test = tests[idx];
    unsigned char key[SIPHASH_KEY_SIZE];
    unsigned char in[64];
    size_t inlen = test.idx;
    unsigned char *expected = test.expected.data;
    size_t expectedlen = test.expected.size;
    unsigned char out[SIPHASH_MAX_DIGEST_SIZE];
    size_t i;

    if (expectedlen != SIPHASH_MIN_DIGEST_SIZE &&
        expectedlen != SIPHASH_MAX_DIGEST_SIZE) {
        TEST_info("size %zu vs %d and %d", expectedlen,
                  SIPHASH_MIN_DIGEST_SIZE, SIPHASH_MAX_DIGEST_SIZE);
        return 0;
    }

    if (!TEST_int_le(inlen, sizeof(in)))
        return 0;

    /* key and in data are 00 01 02 ... */
    for (i = 0; i < sizeof(key); i++)
        key[i] = (unsigned char)i;

    for (i = 0; i < inlen; i++)
        in[i] = (unsigned char)i;

    if (!TEST_true(SipHash_set_hash_size(&siphash, expectedlen))
        || !TEST_true(SipHash_Init(&siphash, key, 0, 0)))
        return 0;
    SipHash_Update(&siphash, in, inlen);
    if (!TEST_true(SipHash_Final(&siphash, out, expectedlen))
        || !TEST_mem_eq(out, expectedlen, expected, expectedlen))
        return 0;

    if (inlen > 16) {
        if (!TEST_true(SipHash_set_hash_size(&siphash, expectedlen))
            || !TEST_true(SipHash_Init(&siphash, key, 0, 0)))
            return 0;
        SipHash_Update(&siphash, in, 1);
        SipHash_Update(&siphash, in+1, inlen-1);
        if (!TEST_true(SipHash_Final(&siphash, out, expectedlen)))
            return 0;

        if (!TEST_mem_eq(out, expectedlen, expected, expectedlen)) {
            TEST_info("SipHash test #%d/1+(N-1) failed.", idx);
            return 0;
        }
    }

    if (inlen > 32) {
        size_t half = inlen / 2;

        if (!TEST_true(SipHash_set_hash_size(&siphash, expectedlen))
            || !TEST_true(SipHash_Init(&siphash, key, 0, 0)))
            return 0;
        SipHash_Update(&siphash, in, half);
        SipHash_Update(&siphash, in+half, inlen-half);
        if (!TEST_true(SipHash_Final(&siphash, out, expectedlen)))
            return 0;

        if (!TEST_mem_eq(out, expectedlen, expected, expectedlen)) {
            TEST_info("SipHash test #%d/2 failed.", idx);
            return 0;
        }

        for (half = 16; half < inlen; half += 16) {
            if (!TEST_true(SipHash_set_hash_size(&siphash, expectedlen))
                || !TEST_true(SipHash_Init(&siphash, key, 0, 0)))
                return 0;
            SipHash_Update(&siphash, in, half);
            SipHash_Update(&siphash, in+half, inlen-half);
            if (!TEST_true(SipHash_Final(&siphash, out, expectedlen)))
                return 0;

            if (!TEST_mem_eq(out, expectedlen, expected, expectedlen)) {
                TEST_info("SipHash test #%d/%zu+%zu failed.",
                          idx, half, inlen-half);
                return 0;
            }
        }
    }

    return 1;
}

__attribute__((used)) static int test_siphash_basic(void)
{
    SIPHASH siphash = { 0, };
    unsigned char key[SIPHASH_KEY_SIZE];
    unsigned char output[SIPHASH_MAX_DIGEST_SIZE];

    /* Use invalid hash size */
    return TEST_int_eq(SipHash_set_hash_size(&siphash, 4), 0)
           /* Use hash size = 8 */
           && TEST_true(SipHash_set_hash_size(&siphash, 8))
           && TEST_true(SipHash_Init(&siphash, key, 0, 0))
           && TEST_true(SipHash_Final(&siphash, output, 8))
           && TEST_int_eq(SipHash_Final(&siphash, output, 16), 0)

           /* Use hash size = 16 */
           && TEST_true(SipHash_set_hash_size(&siphash, 16))
           && TEST_true(SipHash_Init(&siphash, key, 0, 0))
           && TEST_int_eq(SipHash_Final(&siphash, output, 8), 0)
           && TEST_true(SipHash_Final(&siphash, output, 16))

           /* Use hash size = 0 (default = 16) */
           && TEST_true(SipHash_set_hash_size(&siphash, 0))
           && TEST_true(SipHash_Init(&siphash, key, 0, 0))
           && TEST_int_eq(SipHash_Final(&siphash, output, 8), 0)
           && TEST_true(SipHash_Final(&siphash, output, 16));
}

int setup_tests(void)
{
    ADD_TEST(test_siphash_basic);
    ADD_ALL_TESTS(test_siphash, OSSL_NELEM(tests));
    return 1;
}

