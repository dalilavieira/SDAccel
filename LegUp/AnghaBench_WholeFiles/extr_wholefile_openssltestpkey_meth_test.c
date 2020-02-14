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
typedef  int /*<<< orphan*/  EVP_PKEY_METHOD ;
typedef  int /*<<< orphan*/  EVP_PKEY_ASN1_METHOD ;

/* Variables and functions */
 int /*<<< orphan*/  ADD_TEST (int (*) ()) ; 
 int /*<<< orphan*/ * EVP_PKEY_asn1_get0 (int) ; 
 int /*<<< orphan*/  EVP_PKEY_asn1_get0_info (int*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,char const**,int /*<<< orphan*/ *,int /*<<< orphan*/  const*) ; 
 int EVP_PKEY_asn1_get_count () ; 
 int /*<<< orphan*/ * EVP_PKEY_meth_get0 (size_t) ; 
 int /*<<< orphan*/  EVP_PKEY_meth_get0_info (int*,int /*<<< orphan*/ *,int /*<<< orphan*/  const*) ; 
 size_t EVP_PKEY_meth_get_count () ; 
 int /*<<< orphan*/  OBJ_nid2ln (int) ; 
 int /*<<< orphan*/  TEST_error (char*) ; 
 int /*<<< orphan*/  TEST_note (char*,int,int /*<<< orphan*/ ,...) ; 

__attribute__((used)) static int test_asn1_meths(void)
{
    int i;
    int prev = -1;
    int good = 1;
    int pkey_id;
    const EVP_PKEY_ASN1_METHOD *ameth;

    for (i = 0; i < EVP_PKEY_asn1_get_count(); i++) {
        ameth = EVP_PKEY_asn1_get0(i);
        EVP_PKEY_asn1_get0_info(&pkey_id, NULL, NULL, NULL, NULL, ameth);
        if (pkey_id < prev)
            good = 0;
        prev = pkey_id;

    }
    if (!good) {
        TEST_error("EVP_PKEY_ASN1_METHOD table out of order");
        for (i = 0; i < EVP_PKEY_asn1_get_count(); i++) {
            const char *info;

            ameth = EVP_PKEY_asn1_get0(i);
            EVP_PKEY_asn1_get0_info(&pkey_id, NULL, NULL, &info, NULL, ameth);
            if (info == NULL)
                info = "<NO NAME>";
            TEST_note("%d : %s : %s", pkey_id, OBJ_nid2ln(pkey_id), info);
        }
    }
    return good;
}

__attribute__((used)) static int test_pkey_meths(void)
{
    size_t i;
    int prev = -1;
    int good = 1;
    int pkey_id;
    const EVP_PKEY_METHOD *pmeth;

    for (i = 0; i < EVP_PKEY_meth_get_count(); i++) {
        pmeth = EVP_PKEY_meth_get0(i);
        EVP_PKEY_meth_get0_info(&pkey_id, NULL, pmeth);
        if (pkey_id < prev)
            good = 0;
        prev = pkey_id;

    }
    if (!good) {
        TEST_error("EVP_PKEY_METHOD table out of order");
        for (i = 0; i < EVP_PKEY_meth_get_count(); i++) {
            pmeth = EVP_PKEY_meth_get0(i);
            EVP_PKEY_meth_get0_info(&pkey_id, NULL, pmeth);
            TEST_note("%d : %s", pkey_id, OBJ_nid2ln(pkey_id));
        }
    }
    return good;
}

int setup_tests(void)
{
    ADD_TEST(test_asn1_meths);
    ADD_TEST(test_pkey_meths);
    return 1;
}

