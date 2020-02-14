#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_45__   TYPE_5__ ;
typedef  struct TYPE_44__   TYPE_3__ ;
typedef  struct TYPE_43__   TYPE_2__ ;
typedef  struct TYPE_42__   TYPE_1__ ;

/* Type definitions */
struct TYPE_45__ {TYPE_1__* ameth; } ;
struct TYPE_44__ {scalar_t__ operation; int (* pkey_gencb ) (TYPE_3__*) ;int* keygen_info; int keygen_info_count; TYPE_2__* pmeth; TYPE_5__* pkey; } ;
struct TYPE_43__ {int (* paramgen ) (TYPE_3__*,TYPE_5__*) ;int (* paramgen_init ) (TYPE_3__*) ;int (* keygen ) (TYPE_3__*,TYPE_5__*) ;int (* keygen_init ) (TYPE_3__*) ;int (* check ) (TYPE_5__*) ;int (* public_check ) (TYPE_5__*) ;int (* param_check ) (TYPE_5__*) ;} ;
struct TYPE_42__ {int (* pkey_check ) (TYPE_5__*) ;int (* pkey_public_check ) (TYPE_5__*) ;int (* pkey_param_check ) (TYPE_5__*) ;} ;
typedef  int (* EVP_PKEY_gen_cb ) (TYPE_3__*) ;
typedef  TYPE_3__ EVP_PKEY_CTX ;
typedef  TYPE_5__ EVP_PKEY ;
typedef  int /*<<< orphan*/  ENGINE ;
typedef  int /*<<< orphan*/  BN_GENCB ;

/* Variables and functions */
 TYPE_3__* BN_GENCB_get_arg (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  BN_GENCB_set (int /*<<< orphan*/ *,int (*) (int,int,int /*<<< orphan*/ *),TYPE_3__*) ; 
 int /*<<< orphan*/  ERR_R_MALLOC_FAILURE ; 
 int /*<<< orphan*/  EVP_F_EVP_PKEY_CHECK ; 
 int /*<<< orphan*/  EVP_F_EVP_PKEY_KEYGEN ; 
 int /*<<< orphan*/  EVP_F_EVP_PKEY_KEYGEN_INIT ; 
 int /*<<< orphan*/  EVP_F_EVP_PKEY_PARAMGEN ; 
 int /*<<< orphan*/  EVP_F_EVP_PKEY_PARAMGEN_INIT ; 
 int /*<<< orphan*/  EVP_F_EVP_PKEY_PARAM_CHECK ; 
 int /*<<< orphan*/  EVP_F_EVP_PKEY_PUBLIC_CHECK ; 
 int /*<<< orphan*/  EVP_PKEY_CTX_free (TYPE_3__*) ; 
 TYPE_3__* EVP_PKEY_CTX_new_id (int,int /*<<< orphan*/ *) ; 
 scalar_t__ EVP_PKEY_CTX_set_mac_key (TYPE_3__*,unsigned char const*,int) ; 
 scalar_t__ EVP_PKEY_OP_KEYGEN ; 
 scalar_t__ EVP_PKEY_OP_PARAMGEN ; 
 void* EVP_PKEY_OP_UNDEFINED ; 
 int /*<<< orphan*/  EVP_PKEY_free (TYPE_5__*) ; 
 TYPE_5__* EVP_PKEY_new () ; 
 int /*<<< orphan*/  EVP_R_NO_KEY_SET ; 
 int /*<<< orphan*/  EVP_R_OPERATION_NOT_SUPPORTED_FOR_THIS_KEYTYPE ; 
 int /*<<< orphan*/  EVP_R_OPERATON_NOT_INITIALIZED ; 
 int /*<<< orphan*/  EVPerr (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int stub1 (TYPE_3__*) ; 
 int stub10 (TYPE_5__*) ; 
 int stub11 (TYPE_5__*) ; 
 int stub2 (TYPE_3__*,TYPE_5__*) ; 
 int stub3 (TYPE_3__*) ; 
 int stub4 (TYPE_3__*,TYPE_5__*) ; 
 int stub5 (TYPE_3__*) ; 
 int stub6 (TYPE_5__*) ; 
 int stub7 (TYPE_5__*) ; 
 int stub8 (TYPE_5__*) ; 
 int stub9 (TYPE_5__*) ; 

int EVP_PKEY_paramgen_init(EVP_PKEY_CTX *ctx)
{
    int ret;
    if (!ctx || !ctx->pmeth || !ctx->pmeth->paramgen) {
        EVPerr(EVP_F_EVP_PKEY_PARAMGEN_INIT,
               EVP_R_OPERATION_NOT_SUPPORTED_FOR_THIS_KEYTYPE);
        return -2;
    }
    ctx->operation = EVP_PKEY_OP_PARAMGEN;
    if (!ctx->pmeth->paramgen_init)
        return 1;
    ret = ctx->pmeth->paramgen_init(ctx);
    if (ret <= 0)
        ctx->operation = EVP_PKEY_OP_UNDEFINED;
    return ret;
}

int EVP_PKEY_paramgen(EVP_PKEY_CTX *ctx, EVP_PKEY **ppkey)
{
    int ret;
    if (!ctx || !ctx->pmeth || !ctx->pmeth->paramgen) {
        EVPerr(EVP_F_EVP_PKEY_PARAMGEN,
               EVP_R_OPERATION_NOT_SUPPORTED_FOR_THIS_KEYTYPE);
        return -2;
    }

    if (ctx->operation != EVP_PKEY_OP_PARAMGEN) {
        EVPerr(EVP_F_EVP_PKEY_PARAMGEN, EVP_R_OPERATON_NOT_INITIALIZED);
        return -1;
    }

    if (ppkey == NULL)
        return -1;

    if (*ppkey == NULL)
        *ppkey = EVP_PKEY_new();

    if (*ppkey == NULL) {
        EVPerr(EVP_F_EVP_PKEY_PARAMGEN, ERR_R_MALLOC_FAILURE);
        return -1;
    }

    ret = ctx->pmeth->paramgen(ctx, *ppkey);
    if (ret <= 0) {
        EVP_PKEY_free(*ppkey);
        *ppkey = NULL;
    }
    return ret;
}

int EVP_PKEY_keygen_init(EVP_PKEY_CTX *ctx)
{
    int ret;
    if (!ctx || !ctx->pmeth || !ctx->pmeth->keygen) {
        EVPerr(EVP_F_EVP_PKEY_KEYGEN_INIT,
               EVP_R_OPERATION_NOT_SUPPORTED_FOR_THIS_KEYTYPE);
        return -2;
    }
    ctx->operation = EVP_PKEY_OP_KEYGEN;
    if (!ctx->pmeth->keygen_init)
        return 1;
    ret = ctx->pmeth->keygen_init(ctx);
    if (ret <= 0)
        ctx->operation = EVP_PKEY_OP_UNDEFINED;
    return ret;
}

int EVP_PKEY_keygen(EVP_PKEY_CTX *ctx, EVP_PKEY **ppkey)
{
    int ret;

    if (!ctx || !ctx->pmeth || !ctx->pmeth->keygen) {
        EVPerr(EVP_F_EVP_PKEY_KEYGEN,
               EVP_R_OPERATION_NOT_SUPPORTED_FOR_THIS_KEYTYPE);
        return -2;
    }
    if (ctx->operation != EVP_PKEY_OP_KEYGEN) {
        EVPerr(EVP_F_EVP_PKEY_KEYGEN, EVP_R_OPERATON_NOT_INITIALIZED);
        return -1;
    }

    if (ppkey == NULL)
        return -1;

    if (*ppkey == NULL)
        *ppkey = EVP_PKEY_new();
    if (*ppkey == NULL)
        return -1;

    ret = ctx->pmeth->keygen(ctx, *ppkey);
    if (ret <= 0) {
        EVP_PKEY_free(*ppkey);
        *ppkey = NULL;
    }
    return ret;
}

void EVP_PKEY_CTX_set_cb(EVP_PKEY_CTX *ctx, EVP_PKEY_gen_cb *cb)
{
    ctx->pkey_gencb = cb;
}

EVP_PKEY_gen_cb *EVP_PKEY_CTX_get_cb(EVP_PKEY_CTX *ctx)
{
    return ctx->pkey_gencb;
}

__attribute__((used)) static int trans_cb(int a, int b, BN_GENCB *gcb)
{
    EVP_PKEY_CTX *ctx = BN_GENCB_get_arg(gcb);
    ctx->keygen_info[0] = a;
    ctx->keygen_info[1] = b;
    return ctx->pkey_gencb(ctx);
}

void evp_pkey_set_cb_translate(BN_GENCB *cb, EVP_PKEY_CTX *ctx)
{
    BN_GENCB_set(cb, trans_cb, ctx);
}

int EVP_PKEY_CTX_get_keygen_info(EVP_PKEY_CTX *ctx, int idx)
{
    if (idx == -1)
        return ctx->keygen_info_count;
    if (idx < 0 || idx > ctx->keygen_info_count)
        return 0;
    return ctx->keygen_info[idx];
}

EVP_PKEY *EVP_PKEY_new_mac_key(int type, ENGINE *e,
                               const unsigned char *key, int keylen)
{
    EVP_PKEY_CTX *mac_ctx = NULL;
    EVP_PKEY *mac_key = NULL;
    mac_ctx = EVP_PKEY_CTX_new_id(type, e);
    if (!mac_ctx)
        return NULL;
    if (EVP_PKEY_keygen_init(mac_ctx) <= 0)
        goto merr;
    if (EVP_PKEY_CTX_set_mac_key(mac_ctx, key, keylen) <= 0)
        goto merr;
    if (EVP_PKEY_keygen(mac_ctx, &mac_key) <= 0)
        goto merr;
 merr:
    EVP_PKEY_CTX_free(mac_ctx);
    return mac_key;
}

int EVP_PKEY_check(EVP_PKEY_CTX *ctx)
{
    EVP_PKEY *pkey = ctx->pkey;

    if (pkey == NULL) {
        EVPerr(EVP_F_EVP_PKEY_CHECK, EVP_R_NO_KEY_SET);
        return 0;
    }

    /* call customized check function first */
    if (ctx->pmeth->check != NULL)
        return ctx->pmeth->check(pkey);

    /* use default check function in ameth */
    if (pkey->ameth == NULL || pkey->ameth->pkey_check == NULL) {
        EVPerr(EVP_F_EVP_PKEY_CHECK,
               EVP_R_OPERATION_NOT_SUPPORTED_FOR_THIS_KEYTYPE);
        return -2;
    }

    return pkey->ameth->pkey_check(pkey);
}

int EVP_PKEY_public_check(EVP_PKEY_CTX *ctx)
{
    EVP_PKEY *pkey = ctx->pkey;

    if (pkey == NULL) {
        EVPerr(EVP_F_EVP_PKEY_PUBLIC_CHECK, EVP_R_NO_KEY_SET);
        return 0;
    }

    /* call customized public key check function first */
    if (ctx->pmeth->public_check != NULL)
        return ctx->pmeth->public_check(pkey);

    /* use default public key check function in ameth */
    if (pkey->ameth == NULL || pkey->ameth->pkey_public_check == NULL) {
        EVPerr(EVP_F_EVP_PKEY_PUBLIC_CHECK,
               EVP_R_OPERATION_NOT_SUPPORTED_FOR_THIS_KEYTYPE);
        return -2;
    }

    return pkey->ameth->pkey_public_check(pkey);
}

int EVP_PKEY_param_check(EVP_PKEY_CTX *ctx)
{
    EVP_PKEY *pkey = ctx->pkey;

    if (pkey == NULL) {
        EVPerr(EVP_F_EVP_PKEY_PARAM_CHECK, EVP_R_NO_KEY_SET);
        return 0;
    }

    /* call customized param check function first */
    if (ctx->pmeth->param_check != NULL)
        return ctx->pmeth->param_check(pkey);

    /* use default param check function in ameth */
    if (pkey->ameth == NULL || pkey->ameth->pkey_param_check == NULL) {
        EVPerr(EVP_F_EVP_PKEY_PARAM_CHECK,
               EVP_R_OPERATION_NOT_SUPPORTED_FOR_THIS_KEYTYPE);
        return -2;
    }

    return pkey->ameth->pkey_param_check(pkey);
}

