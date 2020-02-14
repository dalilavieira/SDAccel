#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_32__   TYPE_5__ ;
typedef  struct TYPE_31__   TYPE_4__ ;
typedef  struct TYPE_30__   TYPE_3__ ;
typedef  struct TYPE_29__   TYPE_2__ ;
typedef  struct TYPE_28__   TYPE_22__ ;
typedef  struct TYPE_27__   TYPE_1__ ;

/* Type definitions */
struct TYPE_32__ {int nbits; int qbits; int /*<<< orphan*/ * pmd; int /*<<< orphan*/ * md; int /*<<< orphan*/  gentmp; } ;
struct TYPE_27__ {int /*<<< orphan*/  dsa; } ;
struct TYPE_31__ {TYPE_1__ pkey; } ;
struct TYPE_30__ {int keygen_info_count; TYPE_22__* pkey; scalar_t__ pkey_gencb; TYPE_5__* data; int /*<<< orphan*/  keygen_info; } ;
struct TYPE_29__ {int /*<<< orphan*/ * dsa; } ;
struct TYPE_28__ {TYPE_2__ pkey; } ;
typedef  TYPE_3__ EVP_PKEY_CTX ;
typedef  TYPE_4__ EVP_PKEY ;
typedef  int /*<<< orphan*/  EVP_MD ;
typedef  TYPE_5__ DSA_PKEY_CTX ;
typedef  int /*<<< orphan*/  DSA ;
typedef  int /*<<< orphan*/  BN_GENCB ;

/* Variables and functions */
 int /*<<< orphan*/  BN_GENCB_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * BN_GENCB_new () ; 
 int /*<<< orphan*/  DSA_F_PKEY_DSA_CTRL ; 
 int /*<<< orphan*/  DSA_F_PKEY_DSA_CTRL_STR ; 
 int /*<<< orphan*/  DSA_F_PKEY_DSA_KEYGEN ; 
 int /*<<< orphan*/  DSA_R_INVALID_DIGEST_TYPE ; 
 int /*<<< orphan*/  DSA_R_NO_PARAMETERS_SET ; 
 int /*<<< orphan*/  DSA_free (int /*<<< orphan*/ *) ; 
 int DSA_generate_key (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * DSA_new () ; 
 int DSA_sign (int /*<<< orphan*/ ,unsigned char const*,size_t,unsigned char*,unsigned int*,int /*<<< orphan*/ *) ; 
 int DSA_verify (int /*<<< orphan*/ ,unsigned char const*,size_t,unsigned char const*,size_t,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  DSAerr (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ EVP_MD_size (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  EVP_MD_type (int /*<<< orphan*/  const*) ; 
#define  EVP_PKEY_CTRL_CMS_SIGN 136 
#define  EVP_PKEY_CTRL_DIGESTINIT 135 
#define  EVP_PKEY_CTRL_DSA_PARAMGEN_BITS 134 
#define  EVP_PKEY_CTRL_DSA_PARAMGEN_MD 133 
#define  EVP_PKEY_CTRL_DSA_PARAMGEN_Q_BITS 132 
#define  EVP_PKEY_CTRL_GET_MD 131 
#define  EVP_PKEY_CTRL_MD 130 
#define  EVP_PKEY_CTRL_PEER_KEY 129 
#define  EVP_PKEY_CTRL_PKCS7_SIGN 128 
 int EVP_PKEY_CTX_set_dsa_paramgen_bits (TYPE_3__*,int) ; 
 int EVP_PKEY_CTX_set_dsa_paramgen_md (TYPE_3__*,int /*<<< orphan*/  const*) ; 
 int EVP_PKEY_CTX_set_dsa_paramgen_q_bits (TYPE_3__*,int) ; 
 int /*<<< orphan*/  EVP_PKEY_assign_DSA (TYPE_4__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  EVP_PKEY_copy_parameters (TYPE_4__*,TYPE_22__*) ; 
 int /*<<< orphan*/  EVP_R_OPERATION_NOT_SUPPORTED_FOR_THIS_KEYTYPE ; 
 int /*<<< orphan*/ * EVP_get_digestbyname (char const*) ; 
 int /*<<< orphan*/  NID_dsa ; 
 int /*<<< orphan*/  NID_dsaWithSHA ; 
 int /*<<< orphan*/  NID_sha1 ; 
 int /*<<< orphan*/  NID_sha224 ; 
 int /*<<< orphan*/  NID_sha256 ; 
 int /*<<< orphan*/  NID_sha384 ; 
 int /*<<< orphan*/  NID_sha512 ; 
 int /*<<< orphan*/  OPENSSL_free (TYPE_5__*) ; 
 TYPE_5__* OPENSSL_malloc (int) ; 
 int atoi (char const*) ; 
 int dsa_builtin_paramgen (int /*<<< orphan*/ *,int,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  evp_pkey_set_cb_translate (int /*<<< orphan*/ *,TYPE_3__*) ; 
 scalar_t__ strcmp (char const*,char*) ; 

__attribute__((used)) static int pkey_dsa_init(EVP_PKEY_CTX *ctx)
{
    DSA_PKEY_CTX *dctx = OPENSSL_malloc(sizeof(*dctx));

    if (dctx == NULL)
        return 0;
    dctx->nbits = 1024;
    dctx->qbits = 160;
    dctx->pmd = NULL;
    dctx->md = NULL;

    ctx->data = dctx;
    ctx->keygen_info = dctx->gentmp;
    ctx->keygen_info_count = 2;

    return 1;
}

__attribute__((used)) static int pkey_dsa_copy(EVP_PKEY_CTX *dst, const EVP_PKEY_CTX *src)
{
    DSA_PKEY_CTX *dctx, *sctx;

    if (!pkey_dsa_init(dst))
        return 0;
    sctx = src->data;
    dctx = dst->data;
    dctx->nbits = sctx->nbits;
    dctx->qbits = sctx->qbits;
    dctx->pmd = sctx->pmd;
    dctx->md = sctx->md;
    return 1;
}

__attribute__((used)) static void pkey_dsa_cleanup(EVP_PKEY_CTX *ctx)
{
    DSA_PKEY_CTX *dctx = ctx->data;
    OPENSSL_free(dctx);
}

__attribute__((used)) static int pkey_dsa_sign(EVP_PKEY_CTX *ctx, unsigned char *sig,
                         size_t *siglen, const unsigned char *tbs,
                         size_t tbslen)
{
    int ret;
    unsigned int sltmp;
    DSA_PKEY_CTX *dctx = ctx->data;
    DSA *dsa = ctx->pkey->pkey.dsa;

    if (dctx->md != NULL && tbslen != (size_t)EVP_MD_size(dctx->md))
        return 0;

    ret = DSA_sign(0, tbs, tbslen, sig, &sltmp, dsa);

    if (ret <= 0)
        return ret;
    *siglen = sltmp;
    return 1;
}

__attribute__((used)) static int pkey_dsa_verify(EVP_PKEY_CTX *ctx,
                           const unsigned char *sig, size_t siglen,
                           const unsigned char *tbs, size_t tbslen)
{
    int ret;
    DSA_PKEY_CTX *dctx = ctx->data;
    DSA *dsa = ctx->pkey->pkey.dsa;

    if (dctx->md != NULL && tbslen != (size_t)EVP_MD_size(dctx->md))
        return 0;

    ret = DSA_verify(0, tbs, tbslen, sig, siglen, dsa);

    return ret;
}

__attribute__((used)) static int pkey_dsa_ctrl(EVP_PKEY_CTX *ctx, int type, int p1, void *p2)
{
    DSA_PKEY_CTX *dctx = ctx->data;

    switch (type) {
    case EVP_PKEY_CTRL_DSA_PARAMGEN_BITS:
        if (p1 < 256)
            return -2;
        dctx->nbits = p1;
        return 1;

    case EVP_PKEY_CTRL_DSA_PARAMGEN_Q_BITS:
        if (p1 != 160 && p1 != 224 && p1 && p1 != 256)
            return -2;
        dctx->qbits = p1;
        return 1;

    case EVP_PKEY_CTRL_DSA_PARAMGEN_MD:
        if (EVP_MD_type((const EVP_MD *)p2) != NID_sha1 &&
            EVP_MD_type((const EVP_MD *)p2) != NID_sha224 &&
            EVP_MD_type((const EVP_MD *)p2) != NID_sha256) {
            DSAerr(DSA_F_PKEY_DSA_CTRL, DSA_R_INVALID_DIGEST_TYPE);
            return 0;
        }
        dctx->pmd = p2;
        return 1;

    case EVP_PKEY_CTRL_MD:
        if (EVP_MD_type((const EVP_MD *)p2) != NID_sha1 &&
            EVP_MD_type((const EVP_MD *)p2) != NID_dsa &&
            EVP_MD_type((const EVP_MD *)p2) != NID_dsaWithSHA &&
            EVP_MD_type((const EVP_MD *)p2) != NID_sha224 &&
            EVP_MD_type((const EVP_MD *)p2) != NID_sha256 &&
            EVP_MD_type((const EVP_MD *)p2) != NID_sha384 &&
            EVP_MD_type((const EVP_MD *)p2) != NID_sha512) {
            DSAerr(DSA_F_PKEY_DSA_CTRL, DSA_R_INVALID_DIGEST_TYPE);
            return 0;
        }
        dctx->md = p2;
        return 1;

    case EVP_PKEY_CTRL_GET_MD:
        *(const EVP_MD **)p2 = dctx->md;
        return 1;

    case EVP_PKEY_CTRL_DIGESTINIT:
    case EVP_PKEY_CTRL_PKCS7_SIGN:
    case EVP_PKEY_CTRL_CMS_SIGN:
        return 1;

    case EVP_PKEY_CTRL_PEER_KEY:
        DSAerr(DSA_F_PKEY_DSA_CTRL,
               EVP_R_OPERATION_NOT_SUPPORTED_FOR_THIS_KEYTYPE);
        return -2;
    default:
        return -2;

    }
}

__attribute__((used)) static int pkey_dsa_ctrl_str(EVP_PKEY_CTX *ctx,
                             const char *type, const char *value)
{
    if (strcmp(type, "dsa_paramgen_bits") == 0) {
        int nbits;
        nbits = atoi(value);
        return EVP_PKEY_CTX_set_dsa_paramgen_bits(ctx, nbits);
    }
    if (strcmp(type, "dsa_paramgen_q_bits") == 0) {
        int qbits = atoi(value);
        return EVP_PKEY_CTX_set_dsa_paramgen_q_bits(ctx, qbits);
    }
    if (strcmp(type, "dsa_paramgen_md") == 0) {
        const EVP_MD *md = EVP_get_digestbyname(value);

        if (md == NULL) {
            DSAerr(DSA_F_PKEY_DSA_CTRL_STR, DSA_R_INVALID_DIGEST_TYPE);
            return 0;
        }
        return EVP_PKEY_CTX_set_dsa_paramgen_md(ctx, md);
    }
    return -2;
}

__attribute__((used)) static int pkey_dsa_paramgen(EVP_PKEY_CTX *ctx, EVP_PKEY *pkey)
{
    DSA *dsa = NULL;
    DSA_PKEY_CTX *dctx = ctx->data;
    BN_GENCB *pcb;
    int ret;

    if (ctx->pkey_gencb) {
        pcb = BN_GENCB_new();
        if (pcb == NULL)
            return 0;
        evp_pkey_set_cb_translate(pcb, ctx);
    } else
        pcb = NULL;
    dsa = DSA_new();
    if (dsa == NULL) {
        BN_GENCB_free(pcb);
        return 0;
    }
    ret = dsa_builtin_paramgen(dsa, dctx->nbits, dctx->qbits, dctx->pmd,
                               NULL, 0, NULL, NULL, NULL, pcb);
    BN_GENCB_free(pcb);
    if (ret)
        EVP_PKEY_assign_DSA(pkey, dsa);
    else
        DSA_free(dsa);
    return ret;
}

__attribute__((used)) static int pkey_dsa_keygen(EVP_PKEY_CTX *ctx, EVP_PKEY *pkey)
{
    DSA *dsa = NULL;

    if (ctx->pkey == NULL) {
        DSAerr(DSA_F_PKEY_DSA_KEYGEN, DSA_R_NO_PARAMETERS_SET);
        return 0;
    }
    dsa = DSA_new();
    if (dsa == NULL)
        return 0;
    EVP_PKEY_assign_DSA(pkey, dsa);
    /* Note: if error return, pkey is freed by parent routine */
    if (!EVP_PKEY_copy_parameters(pkey, ctx->pkey))
        return 0;
    return DSA_generate_key(pkey->pkey.dsa);
}

