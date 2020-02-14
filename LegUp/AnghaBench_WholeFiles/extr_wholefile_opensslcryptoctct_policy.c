#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
typedef  int uint64_t ;
typedef  int /*<<< orphan*/  X509 ;
struct TYPE_14__ {int epoch_time_in_ms; int /*<<< orphan*/  const* log_store; int /*<<< orphan*/ * issuer; int /*<<< orphan*/ * cert; } ;
typedef  TYPE_1__ CT_POLICY_EVAL_CTX ;
typedef  int /*<<< orphan*/  const CTLOG_STORE ;

/* Variables and functions */
 int /*<<< orphan*/  CT_F_CT_POLICY_EVAL_CTX_NEW ; 
 int /*<<< orphan*/  CTerr (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ERR_R_MALLOC_FAILURE ; 
 int /*<<< orphan*/  OPENSSL_free (TYPE_1__*) ; 
 TYPE_1__* OPENSSL_zalloc (int) ; 
 scalar_t__ SCT_CLOCK_DRIFT_TOLERANCE ; 
 int /*<<< orphan*/  X509_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  X509_up_ref (int /*<<< orphan*/ *) ; 
 scalar_t__ time (int /*<<< orphan*/ *) ; 

CT_POLICY_EVAL_CTX *CT_POLICY_EVAL_CTX_new(void)
{
    CT_POLICY_EVAL_CTX *ctx = OPENSSL_zalloc(sizeof(CT_POLICY_EVAL_CTX));

    if (ctx == NULL) {
        CTerr(CT_F_CT_POLICY_EVAL_CTX_NEW, ERR_R_MALLOC_FAILURE);
        return NULL;
    }

    /* time(NULL) shouldn't ever fail, so don't bother checking for -1. */
    ctx->epoch_time_in_ms = (uint64_t)(time(NULL) + SCT_CLOCK_DRIFT_TOLERANCE) *
            1000;

    return ctx;
}

void CT_POLICY_EVAL_CTX_free(CT_POLICY_EVAL_CTX *ctx)
{
    if (ctx == NULL)
        return;
    X509_free(ctx->cert);
    X509_free(ctx->issuer);
    OPENSSL_free(ctx);
}

int CT_POLICY_EVAL_CTX_set1_cert(CT_POLICY_EVAL_CTX *ctx, X509 *cert)
{
    if (!X509_up_ref(cert))
        return 0;
    ctx->cert = cert;
    return 1;
}

int CT_POLICY_EVAL_CTX_set1_issuer(CT_POLICY_EVAL_CTX *ctx, X509 *issuer)
{
    if (!X509_up_ref(issuer))
        return 0;
    ctx->issuer = issuer;
    return 1;
}

void CT_POLICY_EVAL_CTX_set_shared_CTLOG_STORE(CT_POLICY_EVAL_CTX *ctx,
                                               CTLOG_STORE *log_store)
{
    ctx->log_store = log_store;
}

void CT_POLICY_EVAL_CTX_set_time(CT_POLICY_EVAL_CTX *ctx, uint64_t time_in_ms)
{
    ctx->epoch_time_in_ms = time_in_ms;
}

X509* CT_POLICY_EVAL_CTX_get0_cert(const CT_POLICY_EVAL_CTX *ctx)
{
    return ctx->cert;
}

X509* CT_POLICY_EVAL_CTX_get0_issuer(const CT_POLICY_EVAL_CTX *ctx)
{
    return ctx->issuer;
}

const CTLOG_STORE *CT_POLICY_EVAL_CTX_get0_log_store(const CT_POLICY_EVAL_CTX *ctx)
{
    return ctx->log_store;
}

uint64_t CT_POLICY_EVAL_CTX_get_time(const CT_POLICY_EVAL_CTX *ctx)
{
    return ctx->epoch_time_in_ms;
}

