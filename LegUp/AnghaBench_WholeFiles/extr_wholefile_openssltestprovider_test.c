#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  expected_greeting ;
struct TYPE_3__ {char* data; int /*<<< orphan*/  data_size; } ;
typedef  char const OSSL_PROVIDER ;

/* Variables and functions */
 int /*<<< orphan*/  ADD_TEST (int (*) ()) ; 
 int /*<<< orphan*/  BIO_snprintf (char*,int,char*,int /*<<< orphan*/ ,char const*) ; 
 int /*<<< orphan*/  OPENSSL_VERSION_STR ; 
 int /*<<< orphan*/  OSSL_PROVIDER_add_builtin (int /*<<< orphan*/ *,char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  OSSL_PROVIDER_get_params (char const*,TYPE_1__*) ; 
 char* OSSL_PROVIDER_load (int /*<<< orphan*/ *,char const*) ; 
 int /*<<< orphan*/  OSSL_PROVIDER_unload (char const*) ; 
 int /*<<< orphan*/  PROVIDER_INIT_FUNCTION_NAME ; 
 scalar_t__ TEST_ptr (char const*) ; 
 scalar_t__ TEST_size_t_gt (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ TEST_str_eq (char const*,char*) ; 
 scalar_t__ TEST_true (int /*<<< orphan*/ ) ; 
 TYPE_1__* greeting_request ; 

__attribute__((used)) static int test_provider(const char *name)
{
    OSSL_PROVIDER *prov = NULL;
    const char *greeting = NULL;
    char expected_greeting[256];

    BIO_snprintf(expected_greeting, sizeof(expected_greeting),
                 "Hello OpenSSL %.20s, greetings from %s!",
                 OPENSSL_VERSION_STR, name);

    return
        TEST_ptr(prov = OSSL_PROVIDER_load(NULL, name))
        && TEST_true(OSSL_PROVIDER_get_params(prov, greeting_request))
        && TEST_ptr(greeting = greeting_request[0].data)
        && TEST_size_t_gt(greeting_request[0].data_size, 0)
        && TEST_str_eq(greeting, expected_greeting)
        && TEST_true(OSSL_PROVIDER_unload(prov));
}

__attribute__((used)) static int test_builtin_provider(void)
{
    const char *name = "p_test_builtin";

    return
        TEST_true(OSSL_PROVIDER_add_builtin(NULL, name,
                                            PROVIDER_INIT_FUNCTION_NAME))
        && test_provider(name);
}

__attribute__((used)) static int test_loaded_provider(void)
{
    const char *name = "p_test";

    return test_provider(name);
}

int setup_tests(void)
{
    ADD_TEST(test_builtin_provider);
#ifndef NO_PROVIDER_MODULE
    ADD_TEST(test_loaded_provider);
#endif
    return 1;
}

