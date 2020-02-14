#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_20__   TYPE_2__ ;
typedef  struct TYPE_19__   TYPE_1__ ;

/* Type definitions */
struct TYPE_20__ {int compress_in; int compress_out; int expand_in; int expand_out; TYPE_1__ const* meth; } ;
struct TYPE_19__ {int type; char const* name; int (* compress ) (TYPE_2__*,unsigned char*,int,unsigned char*,int) ;int (* expand ) (TYPE_2__*,unsigned char*,int,unsigned char*,int) ;int /*<<< orphan*/  (* finish ) (TYPE_2__*) ;int /*<<< orphan*/  (* init ) (TYPE_2__*) ;} ;
typedef  TYPE_1__ const COMP_METHOD ;
typedef  TYPE_2__ COMP_CTX ;

/* Variables and functions */
 int /*<<< orphan*/  COMP_F_COMP_CTX_NEW ; 
 int /*<<< orphan*/  COMPerr (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ERR_R_MALLOC_FAILURE ; 
 int NID_undef ; 
 int /*<<< orphan*/  OPENSSL_free (TYPE_2__*) ; 
 TYPE_2__* OPENSSL_zalloc (int) ; 
 int /*<<< orphan*/  stub1 (TYPE_2__*) ; 
 int /*<<< orphan*/  stub2 (TYPE_2__*) ; 
 int stub3 (TYPE_2__*,unsigned char*,int,unsigned char*,int) ; 
 int stub4 (TYPE_2__*,unsigned char*,int,unsigned char*,int) ; 

COMP_CTX *COMP_CTX_new(COMP_METHOD *meth)
{
    COMP_CTX *ret;

    if ((ret = OPENSSL_zalloc(sizeof(*ret))) == NULL) {
        COMPerr(COMP_F_COMP_CTX_NEW, ERR_R_MALLOC_FAILURE);
        return NULL;
    }
    ret->meth = meth;
    if ((ret->meth->init != NULL) && !ret->meth->init(ret)) {
        OPENSSL_free(ret);
        ret = NULL;
    }
    return ret;
}

const COMP_METHOD *COMP_CTX_get_method(const COMP_CTX *ctx)
{
    return ctx->meth;
}

int COMP_get_type(const COMP_METHOD *meth)
{
    return meth->type;
}

const char *COMP_get_name(const COMP_METHOD *meth)
{
    return meth->name;
}

void COMP_CTX_free(COMP_CTX *ctx)
{
    if (ctx == NULL)
        return;
    if (ctx->meth->finish != NULL)
        ctx->meth->finish(ctx);

    OPENSSL_free(ctx);
}

int COMP_compress_block(COMP_CTX *ctx, unsigned char *out, int olen,
                        unsigned char *in, int ilen)
{
    int ret;
    if (ctx->meth->compress == NULL) {
        return -1;
    }
    ret = ctx->meth->compress(ctx, out, olen, in, ilen);
    if (ret > 0) {
        ctx->compress_in += ilen;
        ctx->compress_out += ret;
    }
    return ret;
}

int COMP_expand_block(COMP_CTX *ctx, unsigned char *out, int olen,
                      unsigned char *in, int ilen)
{
    int ret;

    if (ctx->meth->expand == NULL) {
        return -1;
    }
    ret = ctx->meth->expand(ctx, out, olen, in, ilen);
    if (ret > 0) {
        ctx->expand_in += ilen;
        ctx->expand_out += ret;
    }
    return ret;
}

int COMP_CTX_get_type(const COMP_CTX* comp)
{
    return comp->meth ? comp->meth->type : NID_undef;
}

