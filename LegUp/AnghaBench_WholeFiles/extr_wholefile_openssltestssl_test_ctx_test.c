#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_35__   TYPE_5__ ;
typedef  struct TYPE_34__   TYPE_3__ ;
typedef  struct TYPE_33__   TYPE_2__ ;
typedef  struct TYPE_32__   TYPE_1__ ;

/* Type definitions */
struct TYPE_35__ {int verify_callback; int servername; int ct_validation; int max_fragment_len_mode; TYPE_3__* npn_protocols; TYPE_3__* alpn_protocols; } ;
struct TYPE_32__ {int servername_callback; int broken_session_ticket; int cert_status; TYPE_3__* alpn_protocols; TYPE_3__* session_ticket_app_data; TYPE_3__* npn_protocols; } ;
struct TYPE_33__ {TYPE_5__ client; TYPE_1__ server2; TYPE_1__ server; } ;
struct TYPE_34__ {int method; int handshake_mode; int app_data_size; int max_fragment_size; int expected_result; int expected_client_alert; int expected_server_alert; int expected_protocol; int expected_servername; int session_ticket_expected; int compression_expected; int resumption_expected; int session_id_expected; char* test_case_name; char* test_section; TYPE_2__ resume_extra; struct TYPE_34__* expected_ctx; TYPE_2__ extra; struct TYPE_34__* expected_session_ticket_app_data; struct TYPE_34__* expected_cipher; struct TYPE_34__* expected_alpn_protocol; struct TYPE_34__* expected_npn_protocol; } ;
typedef  TYPE_1__ SSL_TEST_SERVER_CONF ;
typedef  TYPE_2__ SSL_TEST_EXTRA_CONF ;
typedef  TYPE_3__ SSL_TEST_CTX_TEST_FIXTURE ;
typedef  TYPE_3__ SSL_TEST_CTX ;
typedef  TYPE_5__ SSL_TEST_CLIENT_CONF ;

/* Variables and functions */
 int /*<<< orphan*/  ADD_ALL_TESTS (int (*) (int),int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ADD_TEST (int (*) ()) ; 
 int /*<<< orphan*/  EXECUTE_SSL_TEST_CTX_TEST () ; 
 int /*<<< orphan*/  NCONF_free (TYPE_3__*) ; 
 int /*<<< orphan*/  NCONF_load (TYPE_3__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 TYPE_3__* NCONF_new (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  OPENSSL_free (TYPE_3__*) ; 
 void* OPENSSL_strdup (char*) ; 
 TYPE_3__* OPENSSL_zalloc (int) ; 
 int /*<<< orphan*/  OSSL_NELEM (char**) ; 
 int /*<<< orphan*/  SETUP_SSL_TEST_CTX_TEST_FIXTURE () ; 
 int SSL_AD_UNKNOWN_CA ; 
 int SSL_TEST_COMPRESSION_NO ; 
 TYPE_3__* SSL_TEST_CTX_create (TYPE_3__*,char*) ; 
 int /*<<< orphan*/  SSL_TEST_CTX_free (TYPE_3__*) ; 
 TYPE_3__* SSL_TEST_CTX_new () ; 
 int SSL_TEST_CT_VALIDATION_STRICT ; 
 int SSL_TEST_HANDSHAKE_RESUME ; 
 int SSL_TEST_METHOD_DTLS ; 
 int SSL_TEST_SERVERNAME_IGNORE_MISMATCH ; 
 void* SSL_TEST_SERVERNAME_SERVER2 ; 
 int SSL_TEST_SERVER_FAIL ; 
 int SSL_TEST_SESSION_ID_IGNORE ; 
 int SSL_TEST_SESSION_TICKET_YES ; 
 int SSL_TEST_SUCCESS ; 
 int SSL_TEST_VERIFY_REJECT_ALL ; 
 int /*<<< orphan*/  TEST_int_eq (int,int) ; 
 int /*<<< orphan*/  TEST_int_gt (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TEST_ptr (TYPE_3__*) ; 
 int /*<<< orphan*/  TEST_ptr_null (TYPE_3__*) ; 
 int /*<<< orphan*/  TEST_str_eq (TYPE_3__*,TYPE_3__*) ; 
 int /*<<< orphan*/  TEST_true (int) ; 
 int TLS1_1_VERSION ; 
 char** bad_configurations ; 
 TYPE_3__* conf ; 
 TYPE_3__* fixture ; 
 int result ; 
 int /*<<< orphan*/  test_get_argument (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int clientconf_eq(SSL_TEST_CLIENT_CONF *conf1,
                         SSL_TEST_CLIENT_CONF *conf2)
{
    if (!TEST_int_eq(conf1->verify_callback, conf2->verify_callback)
            || !TEST_int_eq(conf1->servername, conf2->servername)
            || !TEST_str_eq(conf1->npn_protocols, conf2->npn_protocols)
            || !TEST_str_eq(conf1->alpn_protocols, conf2->alpn_protocols)
            || !TEST_int_eq(conf1->ct_validation, conf2->ct_validation)
            || !TEST_int_eq(conf1->max_fragment_len_mode,
                            conf2->max_fragment_len_mode))
        return 0;
    return 1;
}

__attribute__((used)) static int serverconf_eq(SSL_TEST_SERVER_CONF *serv,
                         SSL_TEST_SERVER_CONF *serv2)
{
    if (!TEST_int_eq(serv->servername_callback, serv2->servername_callback)
            || !TEST_str_eq(serv->npn_protocols, serv2->npn_protocols)
            || !TEST_str_eq(serv->alpn_protocols, serv2->alpn_protocols)
            || !TEST_int_eq(serv->broken_session_ticket,
                            serv2->broken_session_ticket)
            || !TEST_str_eq(serv->session_ticket_app_data,
                            serv2->session_ticket_app_data)
            || !TEST_int_eq(serv->cert_status, serv2->cert_status))
        return 0;
    return 1;
}

__attribute__((used)) static int extraconf_eq(SSL_TEST_EXTRA_CONF *extra,
                        SSL_TEST_EXTRA_CONF *extra2)
{
    if (!TEST_true(clientconf_eq(&extra->client, &extra2->client))
            || !TEST_true(serverconf_eq(&extra->server, &extra2->server))
            || !TEST_true(serverconf_eq(&extra->server2, &extra2->server2)))
        return 0;
    return 1;
}

__attribute__((used)) static int testctx_eq(SSL_TEST_CTX *ctx, SSL_TEST_CTX *ctx2)
{
    if (!TEST_int_eq(ctx->method, ctx2->method)
            || !TEST_int_eq(ctx->handshake_mode, ctx2->handshake_mode)
            || !TEST_int_eq(ctx->app_data_size, ctx2->app_data_size)
            || !TEST_int_eq(ctx->max_fragment_size, ctx2->max_fragment_size)
            || !extraconf_eq(&ctx->extra, &ctx2->extra)
            || !extraconf_eq(&ctx->resume_extra, &ctx2->resume_extra)
            || !TEST_int_eq(ctx->expected_result, ctx2->expected_result)
            || !TEST_int_eq(ctx->expected_client_alert,
                            ctx2->expected_client_alert)
            || !TEST_int_eq(ctx->expected_server_alert,
                            ctx2->expected_server_alert)
            || !TEST_int_eq(ctx->expected_protocol, ctx2->expected_protocol)
            || !TEST_int_eq(ctx->expected_servername, ctx2->expected_servername)
            || !TEST_int_eq(ctx->session_ticket_expected,
                            ctx2->session_ticket_expected)
            || !TEST_int_eq(ctx->compression_expected,
                            ctx2->compression_expected)
            || !TEST_str_eq(ctx->expected_npn_protocol,
                            ctx2->expected_npn_protocol)
            || !TEST_str_eq(ctx->expected_alpn_protocol,
                            ctx2->expected_alpn_protocol)
            || !TEST_str_eq(ctx->expected_cipher,
                            ctx2->expected_cipher)
            || !TEST_str_eq(ctx->expected_session_ticket_app_data,
                            ctx2->expected_session_ticket_app_data)
            || !TEST_int_eq(ctx->resumption_expected,
                            ctx2->resumption_expected)
            || !TEST_int_eq(ctx->session_id_expected,
                            ctx2->session_id_expected))
        return 0;
    return 1;
}

__attribute__((used)) static SSL_TEST_CTX_TEST_FIXTURE *set_up(const char *const test_case_name)
{
    SSL_TEST_CTX_TEST_FIXTURE *fixture;

    if (!TEST_ptr(fixture = OPENSSL_zalloc(sizeof(*fixture))))
        return NULL;
    fixture->test_case_name = test_case_name;
    if (!TEST_ptr(fixture->expected_ctx = SSL_TEST_CTX_new())) {
        OPENSSL_free(fixture);
        return NULL;
    }
    return fixture;
}

__attribute__((used)) static int execute_test(SSL_TEST_CTX_TEST_FIXTURE *fixture)
{
    int success = 0;
    SSL_TEST_CTX *ctx;

    if (!TEST_ptr(ctx = SSL_TEST_CTX_create(conf, fixture->test_section))
            || !testctx_eq(ctx, fixture->expected_ctx))
        goto err;

    success = 1;
 err:
    SSL_TEST_CTX_free(ctx);
    return success;
}

__attribute__((used)) static void tear_down(SSL_TEST_CTX_TEST_FIXTURE *fixture)
{
    SSL_TEST_CTX_free(fixture->expected_ctx);
    OPENSSL_free(fixture);
}

__attribute__((used)) static int test_empty_configuration(void)
{
    SETUP_SSL_TEST_CTX_TEST_FIXTURE();
    if (fixture == NULL)
        return 0;
    fixture->test_section = "ssltest_default";
    fixture->expected_ctx->expected_result = SSL_TEST_SUCCESS;
    EXECUTE_SSL_TEST_CTX_TEST();
    return result;
}

__attribute__((used)) static int test_good_configuration(void)
{
    SETUP_SSL_TEST_CTX_TEST_FIXTURE();
    if (fixture == NULL)
        return 0;
    fixture->test_section = "ssltest_good";
    fixture->expected_ctx->method = SSL_TEST_METHOD_DTLS;
    fixture->expected_ctx->handshake_mode = SSL_TEST_HANDSHAKE_RESUME;
    fixture->expected_ctx->app_data_size = 1024;
    fixture->expected_ctx->max_fragment_size = 2048;

    fixture->expected_ctx->expected_result = SSL_TEST_SERVER_FAIL;
    fixture->expected_ctx->expected_client_alert = SSL_AD_UNKNOWN_CA;
    fixture->expected_ctx->expected_server_alert = 0;  /* No alert. */
    fixture->expected_ctx->expected_protocol = TLS1_1_VERSION;
    fixture->expected_ctx->expected_servername = SSL_TEST_SERVERNAME_SERVER2;
    fixture->expected_ctx->session_ticket_expected = SSL_TEST_SESSION_TICKET_YES;
    fixture->expected_ctx->compression_expected = SSL_TEST_COMPRESSION_NO;
    fixture->expected_ctx->session_id_expected = SSL_TEST_SESSION_ID_IGNORE;
    fixture->expected_ctx->resumption_expected = 1;

    fixture->expected_ctx->extra.client.verify_callback =
        SSL_TEST_VERIFY_REJECT_ALL;
    fixture->expected_ctx->extra.client.servername = SSL_TEST_SERVERNAME_SERVER2;
    fixture->expected_ctx->extra.client.npn_protocols =
        OPENSSL_strdup("foo,bar");
    if (!TEST_ptr(fixture->expected_ctx->extra.client.npn_protocols))
        goto err;
    fixture->expected_ctx->extra.client.max_fragment_len_mode = 0;

    fixture->expected_ctx->extra.server.servername_callback =
        SSL_TEST_SERVERNAME_IGNORE_MISMATCH;
    fixture->expected_ctx->extra.server.broken_session_ticket = 1;

    fixture->expected_ctx->resume_extra.server2.alpn_protocols =
        OPENSSL_strdup("baz");
    if (!TEST_ptr(fixture->expected_ctx->resume_extra.server2.alpn_protocols))
        goto err;

    fixture->expected_ctx->resume_extra.client.ct_validation =
        SSL_TEST_CT_VALIDATION_STRICT;

    EXECUTE_SSL_TEST_CTX_TEST();
    return result;

err:
    tear_down(fixture);
    return 0;
}

__attribute__((used)) static int test_bad_configuration(int idx)
{
    SSL_TEST_CTX *ctx;

    if (!TEST_ptr_null(ctx = SSL_TEST_CTX_create(conf,
                                                 bad_configurations[idx]))) {
        SSL_TEST_CTX_free(ctx);
        return 0;
    }

    return 1;
}

int setup_tests(void)
{
    if (!TEST_ptr(conf = NCONF_new(NULL)))
        return 0;
    /* argument should point to test/ssl_test_ctx_test.conf */
    if (!TEST_int_gt(NCONF_load(conf, test_get_argument(0), NULL), 0))
        return 0;

    ADD_TEST(test_empty_configuration);
    ADD_TEST(test_good_configuration);
    ADD_ALL_TESTS(test_bad_configuration, OSSL_NELEM(bad_configurations));
    return 1;
}

void cleanup_tests(void)
{
    NCONF_free(conf);
}

