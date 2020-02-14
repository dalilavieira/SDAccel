#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_3__ ;
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
struct TYPE_13__ {unsigned char* K; size_t blocklen; unsigned char const* V; int /*<<< orphan*/  const* md; int /*<<< orphan*/ * ctx; } ;
struct TYPE_12__ {TYPE_2__ hmac; } ;
struct TYPE_14__ {int strength; int seedlen; int min_entropylen; int min_noncelen; int max_request; void* max_adinlen; void* max_perslen; void* max_noncelen; void* max_entropylen; int /*<<< orphan*/ * meth; int /*<<< orphan*/  type; TYPE_1__ data; } ;
typedef  TYPE_2__ RAND_DRBG_HMAC ;
typedef  TYPE_3__ RAND_DRBG ;
typedef  int /*<<< orphan*/  HMAC_CTX ;
typedef  int /*<<< orphan*/  EVP_MD ;

/* Variables and functions */
 void* DRBG_MAX_LENGTH ; 
 size_t EVP_MD_size (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/ * EVP_get_digestbynid (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  HMAC_CTX_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * HMAC_CTX_new () ; 
 scalar_t__ HMAC_Final (int /*<<< orphan*/ *,unsigned char*,int /*<<< orphan*/ *) ; 
 scalar_t__ HMAC_Init_ex (int /*<<< orphan*/ *,unsigned char*,size_t,int /*<<< orphan*/  const*,int /*<<< orphan*/ *) ; 
 scalar_t__ HMAC_Update (int /*<<< orphan*/ *,unsigned char const*,size_t) ; 
 int /*<<< orphan*/  OPENSSL_cleanse (TYPE_2__*,int) ; 
 int /*<<< orphan*/  drbg_hmac_meth ; 
 int /*<<< orphan*/  memcpy (unsigned char*,unsigned char*,size_t) ; 
 int /*<<< orphan*/  memset (unsigned char*,int,size_t) ; 

__attribute__((used)) static int do_hmac(RAND_DRBG_HMAC *hmac, unsigned char inbyte,
                   const unsigned char *in1, size_t in1len,
                   const unsigned char *in2, size_t in2len,
                   const unsigned char *in3, size_t in3len)
{
    HMAC_CTX *ctx = hmac->ctx;

    return HMAC_Init_ex(ctx, hmac->K, hmac->blocklen, hmac->md, NULL)
           /* K = HMAC(K, V || inbyte || [in1] || [in2] || [in3]) */
           && HMAC_Update(ctx, hmac->V, hmac->blocklen)
           && HMAC_Update(ctx, &inbyte, 1)
           && (in1 == NULL || in1len == 0 || HMAC_Update(ctx, in1, in1len))
           && (in2 == NULL || in2len == 0 || HMAC_Update(ctx, in2, in2len))
           && (in3 == NULL || in3len == 0 || HMAC_Update(ctx, in3, in3len))
           && HMAC_Final(ctx, hmac->K, NULL)
           /* V = HMAC(K, V) */
           && HMAC_Init_ex(ctx, hmac->K, hmac->blocklen, hmac->md, NULL)
           && HMAC_Update(ctx, hmac->V, hmac->blocklen)
           && HMAC_Final(ctx, hmac->V, NULL);
}

__attribute__((used)) static int drbg_hmac_update(RAND_DRBG *drbg,
                            const unsigned char *in1, size_t in1len,
                            const unsigned char *in2, size_t in2len,
                            const unsigned char *in3, size_t in3len)
{
    RAND_DRBG_HMAC *hmac = &drbg->data.hmac;

    /* (Steps 1-2) K = HMAC(K, V||0x00||provided_data). V = HMAC(K,V) */
    if (!do_hmac(hmac, 0x00, in1, in1len, in2, in2len, in3, in3len))
        return 0;
    /* (Step 3) If provided_data == NULL then return (K,V) */
    if (in1len == 0 && in2len == 0 && in3len == 0)
        return 1;
    /* (Steps 4-5) K = HMAC(K, V||0x01||provided_data). V = HMAC(K,V) */
    return do_hmac(hmac, 0x01, in1, in1len, in2, in2len, in3, in3len);
}

__attribute__((used)) static int drbg_hmac_instantiate(RAND_DRBG *drbg,
                                 const unsigned char *ent, size_t ent_len,
                                 const unsigned char *nonce, size_t nonce_len,
                                 const unsigned char *pstr, size_t pstr_len)
{
    RAND_DRBG_HMAC *hmac = &drbg->data.hmac;

    /* (Step 2) Key = 0x00 00...00 */
    memset(hmac->K, 0x00, hmac->blocklen);
    /* (Step 3) V = 0x01 01...01 */
    memset(hmac->V, 0x01, hmac->blocklen);
    /* (Step 4) (K,V) = HMAC_DRBG_Update(entropy||nonce||pers string, K, V) */
    return drbg_hmac_update(drbg, ent, ent_len, nonce, nonce_len, pstr,
                            pstr_len);
}

__attribute__((used)) static int drbg_hmac_reseed(RAND_DRBG *drbg,
                            const unsigned char *ent, size_t ent_len,
                            const unsigned char *adin, size_t adin_len)
{
    /* (Step 2) (K,V) = HMAC_DRBG_Update(entropy||additional_input, K, V) */
    return drbg_hmac_update(drbg, ent, ent_len, adin, adin_len, NULL, 0);
}

__attribute__((used)) static int drbg_hmac_generate(RAND_DRBG *drbg,
                              unsigned char *out, size_t outlen,
                              const unsigned char *adin, size_t adin_len)
{
    RAND_DRBG_HMAC *hmac = &drbg->data.hmac;
    HMAC_CTX *ctx = hmac->ctx;
    const unsigned char *temp = hmac->V;

    /* (Step 2) if adin != NULL then (K,V) = HMAC_DRBG_Update(adin, K, V) */
    if (adin != NULL
            && adin_len > 0
            && !drbg_hmac_update(drbg, adin, adin_len, NULL, 0, NULL, 0))
        return 0;

    /*
     * (Steps 3-5) temp = NULL
     *             while (len(temp) < outlen) {
     *                 V = HMAC(K, V)
     *                 temp = temp || V
     *             }
     */
    for (;;) {
        if (!HMAC_Init_ex(ctx, hmac->K, hmac->blocklen, hmac->md, NULL)
                || !HMAC_Update(ctx, temp, hmac->blocklen))
            return 0;

        if (outlen > hmac->blocklen) {
            if (!HMAC_Final(ctx, out, NULL))
                return 0;
            temp = out;
        } else {
            if (!HMAC_Final(ctx, hmac->V, NULL))
                return 0;
            memcpy(out, hmac->V, outlen);
            break;
        }
        out += hmac->blocklen;
        outlen -= hmac->blocklen;
    }
    /* (Step 6) (K,V) = HMAC_DRBG_Update(adin, K, V) */
    if (!drbg_hmac_update(drbg, adin, adin_len, NULL, 0, NULL, 0))
        return 0;

    return 1;
}

__attribute__((used)) static int drbg_hmac_uninstantiate(RAND_DRBG *drbg)
{
    HMAC_CTX_free(drbg->data.hmac.ctx);
    OPENSSL_cleanse(&drbg->data.hmac, sizeof(drbg->data.hmac));
    return 1;
}

int drbg_hmac_init(RAND_DRBG *drbg)
{
    const EVP_MD *md = NULL;
    RAND_DRBG_HMAC *hmac = &drbg->data.hmac;

    /* Any approved digest is allowed - assume we pass digest (not NID_hmac*) */
    md = EVP_get_digestbynid(drbg->type);
    if (md == NULL)
        return 0;

    drbg->meth = &drbg_hmac_meth;

    if (hmac->ctx == NULL) {
        hmac->ctx = HMAC_CTX_new();
        if (hmac->ctx == NULL)
            return 0;
    }

    /* These are taken from SP 800-90 10.1 Table 2 */
    hmac->md = md;
    hmac->blocklen = EVP_MD_size(md);
    /* See SP800-57 Part1 Rev4 5.6.1 Table 3 */
    drbg->strength = 64 * (int)(hmac->blocklen >> 3);
    if (drbg->strength > 256)
        drbg->strength = 256;
    drbg->seedlen = hmac->blocklen;

    drbg->min_entropylen = drbg->strength / 8;
    drbg->max_entropylen = DRBG_MAX_LENGTH;

    drbg->min_noncelen = drbg->min_entropylen / 2;
    drbg->max_noncelen = DRBG_MAX_LENGTH;

    drbg->max_perslen = DRBG_MAX_LENGTH;
    drbg->max_adinlen = DRBG_MAX_LENGTH;

    /* Maximum number of bits per request = 2^19 = 2^16 bytes*/
    drbg->max_request = 1 << 16;

    return 1;
}

