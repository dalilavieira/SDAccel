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
typedef  int /*<<< orphan*/  out ;
typedef  int /*<<< orphan*/  expected ;
typedef  int /*<<< orphan*/  EVP_PKEY_CTX ;

/* Variables and functions */
 int /*<<< orphan*/  ADD_TEST (int (*) ()) ; 
 scalar_t__ EVP_PKEY_CTX_add1_hkdf_info (int /*<<< orphan*/ *,char*,int) ; 
 scalar_t__ EVP_PKEY_CTX_add1_tls1_prf_seed (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  EVP_PKEY_CTX_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * EVP_PKEY_CTX_new_id (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ EVP_PKEY_CTX_set1_hkdf_key (int /*<<< orphan*/ *,char*,int) ; 
 scalar_t__ EVP_PKEY_CTX_set1_hkdf_salt (int /*<<< orphan*/ *,char*,int) ; 
 scalar_t__ EVP_PKEY_CTX_set1_pbe_pass (int /*<<< orphan*/ *,char*,int) ; 
 scalar_t__ EVP_PKEY_CTX_set1_scrypt_salt (int /*<<< orphan*/ *,char*,int) ; 
 scalar_t__ EVP_PKEY_CTX_set1_tls1_prf_secret (int /*<<< orphan*/ *,char*,int) ; 
 scalar_t__ EVP_PKEY_CTX_set_hkdf_md (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ EVP_PKEY_CTX_set_scrypt_N (int /*<<< orphan*/ *,int) ; 
 scalar_t__ EVP_PKEY_CTX_set_scrypt_maxmem_bytes (int /*<<< orphan*/ *,int) ; 
 scalar_t__ EVP_PKEY_CTX_set_scrypt_p (int /*<<< orphan*/ *,int) ; 
 scalar_t__ EVP_PKEY_CTX_set_scrypt_r (int /*<<< orphan*/ *,int) ; 
 scalar_t__ EVP_PKEY_CTX_set_tls1_prf_md (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  EVP_PKEY_HKDF ; 
 int /*<<< orphan*/  EVP_PKEY_SCRYPT ; 
 int /*<<< orphan*/  EVP_PKEY_TLS1_PRF ; 
 scalar_t__ EVP_PKEY_derive (int /*<<< orphan*/ *,unsigned char*,size_t*) ; 
 scalar_t__ EVP_PKEY_derive_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  EVP_sha256 () ; 
 int /*<<< orphan*/  TEST_error (char*) ; 
 int /*<<< orphan*/  TEST_mem_eq (unsigned char*,int,unsigned char const*,int) ; 

__attribute__((used)) static int test_kdf_tls1_prf(void)
{
    int ret = 0;
    EVP_PKEY_CTX *pctx;
    unsigned char out[16];
    size_t outlen = sizeof(out);

    if ((pctx = EVP_PKEY_CTX_new_id(EVP_PKEY_TLS1_PRF, NULL)) == NULL) {
        TEST_error("EVP_PKEY_TLS1_PRF");
        goto err;
    }
    if (EVP_PKEY_derive_init(pctx) <= 0) {
        TEST_error("EVP_PKEY_derive_init");
        goto err;
    }
    if (EVP_PKEY_CTX_set_tls1_prf_md(pctx, EVP_sha256()) <= 0) {
        TEST_error("EVP_PKEY_CTX_set_tls1_prf_md");
        goto err;
    }
    if (EVP_PKEY_CTX_set1_tls1_prf_secret(pctx, "secret", 6) <= 0) {
        TEST_error("EVP_PKEY_CTX_set1_tls1_prf_secret");
        goto err;
    }
    if (EVP_PKEY_CTX_add1_tls1_prf_seed(pctx, "seed", 4) <= 0) {
        TEST_error("EVP_PKEY_CTX_add1_tls1_prf_seed");
        goto err;
    }
    if (EVP_PKEY_derive(pctx, out, &outlen) <= 0) {
        TEST_error("EVP_PKEY_derive");
        goto err;
    }

    {
        const unsigned char expected[sizeof(out)] = {
            0x8e, 0x4d, 0x93, 0x25, 0x30, 0xd7, 0x65, 0xa0,
            0xaa, 0xe9, 0x74, 0xc3, 0x04, 0x73, 0x5e, 0xcc
        };
        if (!TEST_mem_eq(out, sizeof(out), expected, sizeof(expected))) {
            goto err;
        }
    }
    ret = 1;
err:
    EVP_PKEY_CTX_free(pctx);
    return ret;
}

__attribute__((used)) static int test_kdf_hkdf(void)
{
    int ret = 0;
    EVP_PKEY_CTX *pctx;
    unsigned char out[10];
    size_t outlen = sizeof(out);

    if ((pctx = EVP_PKEY_CTX_new_id(EVP_PKEY_HKDF, NULL)) == NULL) {
        TEST_error("EVP_PKEY_HKDF");
        goto err;
    }
    if (EVP_PKEY_derive_init(pctx) <= 0) {
        TEST_error("EVP_PKEY_derive_init");
        goto err;
    }
    if (EVP_PKEY_CTX_set_hkdf_md(pctx, EVP_sha256()) <= 0) {
        TEST_error("EVP_PKEY_CTX_set_hkdf_md");
        goto err;
    }
    if (EVP_PKEY_CTX_set1_hkdf_salt(pctx, "salt", 4) <= 0) {
        TEST_error("EVP_PKEY_CTX_set1_hkdf_salt");
        goto err;
    }
    if (EVP_PKEY_CTX_set1_hkdf_key(pctx, "secret", 6) <= 0) {
        TEST_error("EVP_PKEY_CTX_set1_hkdf_key");
        goto err;
    }
    if (EVP_PKEY_CTX_add1_hkdf_info(pctx, "label", 5) <= 0) {
        TEST_error("EVP_PKEY_CTX_set1_hkdf_info");
        goto err;
    }
    if (EVP_PKEY_derive(pctx, out, &outlen) <= 0) {
        TEST_error("EVP_PKEY_derive");
        goto err;
    }

    {
        const unsigned char expected[sizeof(out)] = {
            0x2a, 0xc4, 0x36, 0x9f, 0x52, 0x59, 0x96, 0xf8, 0xde, 0x13
        };
        if (!TEST_mem_eq(out, sizeof(out), expected, sizeof(expected))) {
            goto err;
        }
    }
    ret = 1;
err:
    EVP_PKEY_CTX_free(pctx);
    return ret;
}

__attribute__((used)) static int test_kdf_scrypt(void)
{
    int ret = 0;
    EVP_PKEY_CTX *pctx;
    unsigned char out[64];
    size_t outlen = sizeof(out);

    if ((pctx = EVP_PKEY_CTX_new_id(EVP_PKEY_SCRYPT, NULL)) == NULL) {
        TEST_error("EVP_PKEY_SCRYPT");
        goto err;
    }
    if (EVP_PKEY_derive_init(pctx) <= 0) {
        TEST_error("EVP_PKEY_derive_init");
        goto err;
    }
    if (EVP_PKEY_CTX_set1_pbe_pass(pctx, "password", 8) <= 0) {
        TEST_error("EVP_PKEY_CTX_set1_pbe_pass");
        goto err;
    }
    if (EVP_PKEY_CTX_set1_scrypt_salt(pctx, "NaCl", 4) <= 0) {
        TEST_error("EVP_PKEY_CTX_set1_scrypt_salt");
        goto err;
    }
    if (EVP_PKEY_CTX_set_scrypt_N(pctx, 1024) <= 0) {
        TEST_error("EVP_PKEY_CTX_set_scrypt_N");
        goto err;
    }
    if (EVP_PKEY_CTX_set_scrypt_r(pctx, 8) <= 0) {
        TEST_error("EVP_PKEY_CTX_set_scrypt_r");
        goto err;
    }
    if (EVP_PKEY_CTX_set_scrypt_p(pctx, 16) <= 0) {
        TEST_error("EVP_PKEY_CTX_set_scrypt_p");
        goto err;
    }
    if (EVP_PKEY_CTX_set_scrypt_maxmem_bytes(pctx, 16) <= 0) {
        TEST_error("EVP_PKEY_CTX_set_maxmem_bytes");
        goto err;
    }
    if (EVP_PKEY_derive(pctx, out, &outlen) > 0) {
        TEST_error("EVP_PKEY_derive should have failed");
        goto err;
    }
    if (EVP_PKEY_CTX_set_scrypt_maxmem_bytes(pctx, 10 * 1024 * 1024) <= 0) {
        TEST_error("EVP_PKEY_CTX_set_maxmem_bytes");
        goto err;
    }
    if (EVP_PKEY_derive(pctx, out, &outlen) <= 0) {
        TEST_error("EVP_PKEY_derive");
        goto err;
    }

    {
        const unsigned char expected[sizeof(out)] = {
            0xfd, 0xba, 0xbe, 0x1c, 0x9d, 0x34, 0x72, 0x00,
            0x78, 0x56, 0xe7, 0x19, 0x0d, 0x01, 0xe9, 0xfe,
            0x7c, 0x6a, 0xd7, 0xcb, 0xc8, 0x23, 0x78, 0x30,
            0xe7, 0x73, 0x76, 0x63, 0x4b, 0x37, 0x31, 0x62,
            0x2e, 0xaf, 0x30, 0xd9, 0x2e, 0x22, 0xa3, 0x88,
            0x6f, 0xf1, 0x09, 0x27, 0x9d, 0x98, 0x30, 0xda,
            0xc7, 0x27, 0xaf, 0xb9, 0x4a, 0x83, 0xee, 0x6d,
            0x83, 0x60, 0xcb, 0xdf, 0xa2, 0xcc, 0x06, 0x40
        };
        if (!TEST_mem_eq(out, sizeof(out), expected, sizeof(expected))) {
            goto err;
        }
    }
    ret = 1;
err:
    EVP_PKEY_CTX_free(pctx);
    return ret;
}

int setup_tests(void)
{
    ADD_TEST(test_kdf_tls1_prf);
    ADD_TEST(test_kdf_hkdf);
#ifndef OPENSSL_NO_SCRYPT
    ADD_TEST(test_kdf_scrypt);
#endif
    return 1;
}

