#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
struct TYPE_11__ {int /*<<< orphan*/  prime_infos; int /*<<< orphan*/ * q; int /*<<< orphan*/ * p; } ;
struct TYPE_10__ {int /*<<< orphan*/ * r; int /*<<< orphan*/ * pp; int /*<<< orphan*/ * t; int /*<<< orphan*/ * d; } ;
typedef  TYPE_1__ RSA_PRIME_INFO ;
typedef  TYPE_2__ RSA ;
typedef  int /*<<< orphan*/  BN_CTX ;
typedef  int /*<<< orphan*/  BIGNUM ;

/* Variables and functions */
 int /*<<< orphan*/  BN_CTX_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * BN_CTX_new () ; 
 int /*<<< orphan*/  BN_clear_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  BN_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  BN_mul (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 void* BN_secure_new () ; 
 int /*<<< orphan*/  ERR_R_MALLOC_FAILURE ; 
 int /*<<< orphan*/  OPENSSL_free (TYPE_1__*) ; 
 TYPE_1__* OPENSSL_zalloc (int) ; 
 int /*<<< orphan*/  RSA_F_RSA_MULTIP_INFO_NEW ; 
 int RSA_MAX_PRIME_NUM ; 
 int /*<<< orphan*/  RSAerr (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int sk_RSA_PRIME_INFO_num (int /*<<< orphan*/ ) ; 
 TYPE_1__* sk_RSA_PRIME_INFO_value (int /*<<< orphan*/ ,int) ; 

void rsa_multip_info_free_ex(RSA_PRIME_INFO *pinfo)
{
    /* free pp and pinfo only */
    BN_clear_free(pinfo->pp);
    OPENSSL_free(pinfo);
}

void rsa_multip_info_free(RSA_PRIME_INFO *pinfo)
{
    /* free a RSA_PRIME_INFO structure */
    BN_clear_free(pinfo->r);
    BN_clear_free(pinfo->d);
    BN_clear_free(pinfo->t);
    rsa_multip_info_free_ex(pinfo);
}

RSA_PRIME_INFO *rsa_multip_info_new(void)
{
    RSA_PRIME_INFO *pinfo;

    /* create a RSA_PRIME_INFO structure */
    if ((pinfo = OPENSSL_zalloc(sizeof(RSA_PRIME_INFO))) == NULL) {
        RSAerr(RSA_F_RSA_MULTIP_INFO_NEW, ERR_R_MALLOC_FAILURE);
        return NULL;
    }
    if ((pinfo->r = BN_secure_new()) == NULL)
        goto err;
    if ((pinfo->d = BN_secure_new()) == NULL)
        goto err;
    if ((pinfo->t = BN_secure_new()) == NULL)
        goto err;
    if ((pinfo->pp = BN_secure_new()) == NULL)
        goto err;

    return pinfo;

 err:
    BN_free(pinfo->r);
    BN_free(pinfo->d);
    BN_free(pinfo->t);
    BN_free(pinfo->pp);
    OPENSSL_free(pinfo);
    return NULL;
}

int rsa_multip_calc_product(RSA *rsa)
{
    RSA_PRIME_INFO *pinfo;
    BIGNUM *p1 = NULL, *p2 = NULL;
    BN_CTX *ctx = NULL;
    int i, rv = 0, ex_primes;

    if ((ex_primes = sk_RSA_PRIME_INFO_num(rsa->prime_infos)) <= 0) {
        /* invalid */
        goto err;
    }

    if ((ctx = BN_CTX_new()) == NULL)
        goto err;

    /* calculate pinfo->pp = p * q for first 'extra' prime */
    p1 = rsa->p;
    p2 = rsa->q;

    for (i = 0; i < ex_primes; i++) {
        pinfo = sk_RSA_PRIME_INFO_value(rsa->prime_infos, i);
        if (pinfo->pp == NULL) {
            pinfo->pp = BN_secure_new();
            if (pinfo->pp == NULL)
                goto err;
        }
        if (!BN_mul(pinfo->pp, p1, p2, ctx))
            goto err;
        /* save previous one */
        p1 = pinfo->pp;
        p2 = pinfo->r;
    }

    rv = 1;
 err:
    BN_CTX_free(ctx);
    return rv;
}

int rsa_multip_cap(int bits)
{
    int cap = 5;

    if (bits < 1024)
        cap = 2;
    else if (bits < 4096)
        cap = 3;
    else if (bits < 8192)
        cap = 4;

    if (cap > RSA_MAX_PRIME_NUM)
        cap = RSA_MAX_PRIME_NUM;

    return cap;
}

