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
 int /*<<< orphan*/  ADD_ALL_TESTS (int (*) (int),int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  EVP_Digest (unsigned char*,int /*<<< orphan*/ ,unsigned char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  EVP_md2 () ; 
 int MD2_DIGEST_LENGTH ; 
 int /*<<< orphan*/  OSSL_NELEM (scalar_t__*) ; 
 int /*<<< orphan*/ * OSSL_PROVIDER_load (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  OSSL_PROVIDER_unload (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  TEST_str_eq (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TEST_true (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * prov ; 
 int /*<<< orphan*/ * ret ; 
 int /*<<< orphan*/  sprintf (char*,char*,unsigned char) ; 
 int /*<<< orphan*/  strlen (scalar_t__) ; 
 scalar_t__* test ; 

__attribute__((used)) static int test_md2(int n)
{
    char buf[80];
    unsigned char md[MD2_DIGEST_LENGTH];
    int i;

    if (!TEST_true(EVP_Digest((unsigned char *)test[n], strlen(test[n]),
                                 md, NULL, EVP_md2(), NULL)))
        return 0;

    for (i = 0; i < MD2_DIGEST_LENGTH; i++)
        sprintf(&(buf[i * 2]), "%02x", md[i]);
    if (!TEST_str_eq(buf, ret[n]))
        return 0;
    return 1;
}

int global_init(void)
{
    prov = OSSL_PROVIDER_load(NULL, "legacy");

    return prov != NULL;
}

void cleanup_tests(void)
{
    OSSL_PROVIDER_unload(prov);
}

int setup_tests(void)
{
#ifndef OPENSSL_NO_MD2
    ADD_ALL_TESTS(test_md2, OSSL_NELEM(test));
#endif
    return 1;
}

