#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
struct TYPE_12__ {TYPE_1__* meth; } ;
struct TYPE_11__ {int (* sign ) (int,unsigned char const*,int,unsigned char*,unsigned int*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,TYPE_2__*) ;int (* sign_setup ) (TYPE_2__*,int /*<<< orphan*/ *,int /*<<< orphan*/ **,int /*<<< orphan*/ **) ;int /*<<< orphan*/ * (* sign_sig ) (unsigned char const*,int,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,TYPE_2__*) ;} ;
typedef  TYPE_2__ EC_KEY ;
typedef  int /*<<< orphan*/  ECDSA_SIG ;
typedef  int /*<<< orphan*/  BN_CTX ;
typedef  int /*<<< orphan*/  BIGNUM ;

/* Variables and functions */
 int /*<<< orphan*/ * ECDSA_do_sign_ex (unsigned char const*,int,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,TYPE_2__*) ; 
 int ECDSA_sign_ex (int,unsigned char const*,int,unsigned char*,unsigned int*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,TYPE_2__*) ; 
 int /*<<< orphan*/  EC_F_ECDSA_DO_SIGN_EX ; 
 int /*<<< orphan*/  EC_F_ECDSA_SIGN_EX ; 
 int /*<<< orphan*/  EC_F_ECDSA_SIGN_SETUP ; 
 int /*<<< orphan*/  EC_R_OPERATION_NOT_SUPPORTED ; 
 int /*<<< orphan*/  ECerr (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * stub1 (unsigned char const*,int,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,TYPE_2__*) ; 
 int stub2 (int,unsigned char const*,int,unsigned char*,unsigned int*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,TYPE_2__*) ; 
 int stub3 (TYPE_2__*,int /*<<< orphan*/ *,int /*<<< orphan*/ **,int /*<<< orphan*/ **) ; 

ECDSA_SIG *ECDSA_do_sign(const unsigned char *dgst, int dlen, EC_KEY *eckey)
{
    return ECDSA_do_sign_ex(dgst, dlen, NULL, NULL, eckey);
}

ECDSA_SIG *ECDSA_do_sign_ex(const unsigned char *dgst, int dlen,
                            const BIGNUM *kinv, const BIGNUM *rp,
                            EC_KEY *eckey)
{
    if (eckey->meth->sign_sig != NULL)
        return eckey->meth->sign_sig(dgst, dlen, kinv, rp, eckey);
    ECerr(EC_F_ECDSA_DO_SIGN_EX, EC_R_OPERATION_NOT_SUPPORTED);
    return NULL;
}

int ECDSA_sign(int type, const unsigned char *dgst, int dlen, unsigned char
               *sig, unsigned int *siglen, EC_KEY *eckey)
{
    return ECDSA_sign_ex(type, dgst, dlen, sig, siglen, NULL, NULL, eckey);
}

int ECDSA_sign_ex(int type, const unsigned char *dgst, int dlen,
                  unsigned char *sig, unsigned int *siglen, const BIGNUM *kinv,
                  const BIGNUM *r, EC_KEY *eckey)
{
    if (eckey->meth->sign != NULL)
        return eckey->meth->sign(type, dgst, dlen, sig, siglen, kinv, r, eckey);
    ECerr(EC_F_ECDSA_SIGN_EX, EC_R_OPERATION_NOT_SUPPORTED);
    return 0;
}

int ECDSA_sign_setup(EC_KEY *eckey, BN_CTX *ctx_in, BIGNUM **kinvp,
                     BIGNUM **rp)
{
    if (eckey->meth->sign_setup != NULL)
        return eckey->meth->sign_setup(eckey, ctx_in, kinvp, rp);
    ECerr(EC_F_ECDSA_SIGN_SETUP, EC_R_OPERATION_NOT_SUPPORTED);
    return 0;
}

