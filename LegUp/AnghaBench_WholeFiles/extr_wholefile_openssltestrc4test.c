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
typedef  int /*<<< orphan*/  obuf ;
typedef  int /*<<< orphan*/  md ;
typedef  int /*<<< orphan*/  expected ;
typedef  int /*<<< orphan*/  buf ;
typedef  int /*<<< orphan*/  SHA_CTX ;
typedef  int /*<<< orphan*/  RC4_KEY ;

/* Variables and functions */
 int /*<<< orphan*/  ADD_ALL_TESTS (int (*) (int const),int const) ; 
 int /*<<< orphan*/  ADD_TEST (int (*) ()) ; 
 int const OSSL_NELEM (int const*) ; 
 int /*<<< orphan*/  RC4 (int /*<<< orphan*/ *,int const,unsigned char*,unsigned char*) ; 
 int /*<<< orphan*/  RC4_set_key (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SHA1_Final (unsigned char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SHA1_Init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SHA1_Update (int /*<<< orphan*/ *,unsigned char*,int) ; 
 int SHA_DIGEST_LENGTH ; 
 int TEST_mem_eq (unsigned char*,int const,unsigned char*,int const) ; 
 int TEST_uchar_eq (unsigned char,int /*<<< orphan*/ ) ; 
 unsigned char** data ; 
 int const* data_len ; 
 int /*<<< orphan*/ ** keys ; 
 int /*<<< orphan*/  memset (unsigned char*,int /*<<< orphan*/ ,int) ; 
 unsigned char** output ; 

__attribute__((used)) static int test_rc4_encrypt(const int i)
{
    unsigned char obuf[512];
    RC4_KEY key;

    RC4_set_key(&key, keys[i][0], &(keys[i][1]));
    memset(obuf, 0, sizeof(obuf));
    RC4(&key, data_len[i], &(data[i][0]), obuf);
    return TEST_mem_eq(obuf, data_len[i] + 1, output[i], data_len[i] + 1);
}

__attribute__((used)) static int test_rc4_end_processing(const int i)
{
    unsigned char obuf[512];
    RC4_KEY key;

    RC4_set_key(&key, keys[3][0], &(keys[3][1]));
    memset(obuf, 0, sizeof(obuf));
    RC4(&key, i, &(data[3][0]), obuf);
    if (!TEST_mem_eq(obuf, i, output[3], i))
        return 0;
    return TEST_uchar_eq(obuf[i], 0);
}

__attribute__((used)) static int test_rc4_multi_call(const int i)
{
    unsigned char obuf[512];
    RC4_KEY key;

    RC4_set_key(&key, keys[3][0], &(keys[3][1]));
    memset(obuf, 0, sizeof(obuf));
    RC4(&key, i, &(data[3][0]), obuf);
    RC4(&key, data_len[3] - i, &(data[3][i]), &(obuf[i]));
    return TEST_mem_eq(obuf, data_len[3] + 1, output[3], data_len[3] + 1);
}

__attribute__((used)) static int test_rc_bulk(void)
{
    RC4_KEY key;
    unsigned char buf[513];
    SHA_CTX c;
    unsigned char md[SHA_DIGEST_LENGTH];
    int i;
    static unsigned char expected[] = {
        0xa4, 0x7b, 0xcc, 0x00, 0x3d, 0xd0, 0xbd, 0xe1, 0xac, 0x5f,
        0x12, 0x1e, 0x45, 0xbc, 0xfb, 0x1a, 0xa1, 0xf2, 0x7f, 0xc5
    };

    RC4_set_key(&key, keys[0][0], &(keys[3][1]));
    memset(buf, 0, sizeof(buf));
    SHA1_Init(&c);
    for (i = 0; i < 2571; i++) {
        RC4(&key, sizeof(buf), buf, buf);
        SHA1_Update(&c, buf, sizeof(buf));
    }
    SHA1_Final(md, &c);

    return TEST_mem_eq(md, sizeof(md), expected, sizeof(expected));
}

int setup_tests(void)
{
#ifndef OPENSSL_NO_RC4
    ADD_ALL_TESTS(test_rc4_encrypt, OSSL_NELEM(data_len));
    ADD_ALL_TESTS(test_rc4_end_processing, data_len[3]);
    ADD_ALL_TESTS(test_rc4_multi_call, data_len[3]);
    ADD_TEST(test_rc_bulk);
#endif
    return 1;
}

