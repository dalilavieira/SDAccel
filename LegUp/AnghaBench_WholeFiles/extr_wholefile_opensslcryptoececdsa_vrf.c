#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_8__ {TYPE_1__* meth; } ;
struct TYPE_7__ {int (* verify_sig ) (unsigned char const*,int,int /*<<< orphan*/  const*,TYPE_2__*) ;int (* verify ) (int,unsigned char const*,int,unsigned char const*,int,TYPE_2__*) ;} ;
typedef  TYPE_2__ EC_KEY ;
typedef  int /*<<< orphan*/  ECDSA_SIG ;

/* Variables and functions */
 int /*<<< orphan*/  EC_F_ECDSA_DO_VERIFY ; 
 int /*<<< orphan*/  EC_F_ECDSA_VERIFY ; 
 int /*<<< orphan*/  EC_R_OPERATION_NOT_SUPPORTED ; 
 int /*<<< orphan*/  ECerr (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int stub1 (unsigned char const*,int,int /*<<< orphan*/  const*,TYPE_2__*) ; 
 int stub2 (int,unsigned char const*,int,unsigned char const*,int,TYPE_2__*) ; 

int ECDSA_do_verify(const unsigned char *dgst, int dgst_len,
                    const ECDSA_SIG *sig, EC_KEY *eckey)
{
    if (eckey->meth->verify_sig != NULL)
        return eckey->meth->verify_sig(dgst, dgst_len, sig, eckey);
    ECerr(EC_F_ECDSA_DO_VERIFY, EC_R_OPERATION_NOT_SUPPORTED);
    return 0;
}

int ECDSA_verify(int type, const unsigned char *dgst, int dgst_len,
                 const unsigned char *sigbuf, int sig_len, EC_KEY *eckey)
{
    if (eckey->meth->verify != NULL)
        return eckey->meth->verify(type, dgst, dgst_len, sigbuf, sig_len,
                                   eckey);
    ECerr(EC_F_ECDSA_VERIFY, EC_R_OPERATION_NOT_SUPPORTED);
    return 0;
}

