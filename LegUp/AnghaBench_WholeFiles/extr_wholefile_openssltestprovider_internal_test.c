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
 int /*<<< orphan*/  OPENSSL_INIT_LOAD_CONFIG ; 
 int /*<<< orphan*/  OPENSSL_VERSION_STR ; 
 scalar_t__ OPENSSL_init_crypto (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * PROVIDER_INIT_FUNCTION_NAME ; 
 int /*<<< orphan*/  TEST_info (char*,char const*) ; 
 scalar_t__ TEST_ptr (char const*) ; 
 scalar_t__ TEST_size_t_gt (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ TEST_str_eq (char const*,char const*) ; 
 scalar_t__ TEST_true (int /*<<< orphan*/ ) ; 
 TYPE_1__* greeting_request ; 
 int /*<<< orphan*/  ossl_provider_activate (char const*) ; 
 char* ossl_provider_find (int /*<<< orphan*/ *,char const*) ; 
 int /*<<< orphan*/  ossl_provider_free (char const*) ; 
 int /*<<< orphan*/  ossl_provider_get_params (char const*,TYPE_1__*) ; 
 char* ossl_provider_new (int /*<<< orphan*/ *,char const*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int test_provider(OSSL_PROVIDER *prov, const char *expected_greeting)
{
    const char *greeting = NULL;
    int ret = 0;

    ret =
        TEST_true(ossl_provider_activate(prov))
        && TEST_true(ossl_provider_get_params(prov, greeting_request))
        && TEST_ptr(greeting = greeting_request[0].data)
        && TEST_size_t_gt(greeting_request[0].data_size, 0)
        && TEST_str_eq(greeting, expected_greeting);

    TEST_info("Got this greeting: %s\n", greeting);
    ossl_provider_free(prov);
    return ret;
}

__attribute__((used)) static const char *expected_greeting1(const char *name)
{
    static char expected_greeting[256] = "";

    BIO_snprintf(expected_greeting, sizeof(expected_greeting),
                 "Hello OpenSSL %.20s, greetings from %s!",
                 OPENSSL_VERSION_STR, name);

    return expected_greeting;
}

__attribute__((used)) static int test_builtin_provider(void)
{
    const char *name = "p_test_builtin";
    OSSL_PROVIDER *prov = NULL;

    return
        TEST_ptr(prov =
                 ossl_provider_new(NULL, name, PROVIDER_INIT_FUNCTION_NAME))
        && test_provider(prov, expected_greeting1(name));
}

__attribute__((used)) static int test_loaded_provider(void)
{
    const char *name = "p_test";
    OSSL_PROVIDER *prov = NULL;

    return
        TEST_ptr(prov = ossl_provider_new(NULL, name, NULL))
        && test_provider(prov, expected_greeting1(name));
}

__attribute__((used)) static int test_configured_provider(void)
{
    const char *name = "p_test_configured";
    OSSL_PROVIDER *prov = NULL;
    /* This MUST match the config file */
    const char *expected_greeting =
        "Hello OpenSSL, greetings from Test Provider";

    return
        OPENSSL_init_crypto(OPENSSL_INIT_LOAD_CONFIG, NULL)
        && TEST_ptr(prov = ossl_provider_find(NULL, name))
        && test_provider(prov, expected_greeting);
}

int setup_tests(void)
{
    ADD_TEST(test_builtin_provider);
#ifndef NO_PROVIDER_MODULE
    ADD_TEST(test_loaded_provider);
    ADD_TEST(test_configured_provider);
#endif
    return 1;
}

