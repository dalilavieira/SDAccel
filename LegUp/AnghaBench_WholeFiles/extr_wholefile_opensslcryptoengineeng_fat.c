#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_26__   TYPE_1__ ;

/* Type definitions */
struct TYPE_26__ {int flags; } ;
typedef  TYPE_1__ ENGINE ;

/* Variables and functions */
 int /*<<< orphan*/  CONF_parse_list (char const*,char,int,int (*) (char const*,int,void*),unsigned int*) ; 
 int ENGINE_FLAGS_NO_REGISTER_ALL ; 
 int /*<<< orphan*/  ENGINE_F_ENGINE_SET_DEFAULT_STRING ; 
 unsigned int ENGINE_METHOD_ALL ; 
 unsigned int ENGINE_METHOD_CIPHERS ; 
 unsigned int ENGINE_METHOD_DH ; 
 unsigned int ENGINE_METHOD_DIGESTS ; 
 unsigned int ENGINE_METHOD_DSA ; 
 unsigned int ENGINE_METHOD_EC ; 
 unsigned int ENGINE_METHOD_PKEY_ASN1_METHS ; 
 unsigned int ENGINE_METHOD_PKEY_METHS ; 
 unsigned int ENGINE_METHOD_RAND ; 
 unsigned int ENGINE_METHOD_RSA ; 
 int /*<<< orphan*/  ENGINE_R_INVALID_STRING ; 
 TYPE_1__* ENGINE_get_first () ; 
 TYPE_1__* ENGINE_get_next (TYPE_1__*) ; 
 int /*<<< orphan*/  ENGINE_register_DH (TYPE_1__*) ; 
 int /*<<< orphan*/  ENGINE_register_DSA (TYPE_1__*) ; 
 int /*<<< orphan*/  ENGINE_register_EC (TYPE_1__*) ; 
 int /*<<< orphan*/  ENGINE_register_RAND (TYPE_1__*) ; 
 int /*<<< orphan*/  ENGINE_register_RSA (TYPE_1__*) ; 
 int /*<<< orphan*/  ENGINE_register_ciphers (TYPE_1__*) ; 
 int /*<<< orphan*/  ENGINE_register_digests (TYPE_1__*) ; 
 int /*<<< orphan*/  ENGINE_register_pkey_asn1_meths (TYPE_1__*) ; 
 int /*<<< orphan*/  ENGINE_register_pkey_meths (TYPE_1__*) ; 
 int /*<<< orphan*/  ENGINE_set_default_DH (TYPE_1__*) ; 
 int /*<<< orphan*/  ENGINE_set_default_DSA (TYPE_1__*) ; 
 int /*<<< orphan*/  ENGINE_set_default_EC (TYPE_1__*) ; 
 int /*<<< orphan*/  ENGINE_set_default_RAND (TYPE_1__*) ; 
 int /*<<< orphan*/  ENGINE_set_default_RSA (TYPE_1__*) ; 
 int /*<<< orphan*/  ENGINE_set_default_ciphers (TYPE_1__*) ; 
 int /*<<< orphan*/  ENGINE_set_default_digests (TYPE_1__*) ; 
 int /*<<< orphan*/  ENGINE_set_default_pkey_asn1_meths (TYPE_1__*) ; 
 int /*<<< orphan*/  ENGINE_set_default_pkey_meths (TYPE_1__*) ; 
 int /*<<< orphan*/  ENGINEerr (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ERR_add_error_data (int,char*,char const*) ; 
 scalar_t__ strncmp (char const*,char*,int) ; 

int ENGINE_set_default(ENGINE *e, unsigned int flags)
{
    if ((flags & ENGINE_METHOD_CIPHERS) && !ENGINE_set_default_ciphers(e))
        return 0;
    if ((flags & ENGINE_METHOD_DIGESTS) && !ENGINE_set_default_digests(e))
        return 0;
#ifndef OPENSSL_NO_RSA
    if ((flags & ENGINE_METHOD_RSA) && !ENGINE_set_default_RSA(e))
        return 0;
#endif
#ifndef OPENSSL_NO_DSA
    if ((flags & ENGINE_METHOD_DSA) && !ENGINE_set_default_DSA(e))
        return 0;
#endif
#ifndef OPENSSL_NO_DH
    if ((flags & ENGINE_METHOD_DH) && !ENGINE_set_default_DH(e))
        return 0;
#endif
#ifndef OPENSSL_NO_EC
    if ((flags & ENGINE_METHOD_EC) && !ENGINE_set_default_EC(e))
        return 0;
#endif
    if ((flags & ENGINE_METHOD_RAND) && !ENGINE_set_default_RAND(e))
        return 0;
    if ((flags & ENGINE_METHOD_PKEY_METHS)
        && !ENGINE_set_default_pkey_meths(e))
        return 0;
    if ((flags & ENGINE_METHOD_PKEY_ASN1_METHS)
        && !ENGINE_set_default_pkey_asn1_meths(e))
        return 0;
    return 1;
}

__attribute__((used)) static int int_def_cb(const char *alg, int len, void *arg)
{
    unsigned int *pflags = arg;
    if (alg == NULL)
        return 0;
    if (strncmp(alg, "ALL", len) == 0)
        *pflags |= ENGINE_METHOD_ALL;
    else if (strncmp(alg, "RSA", len) == 0)
        *pflags |= ENGINE_METHOD_RSA;
    else if (strncmp(alg, "DSA", len) == 0)
        *pflags |= ENGINE_METHOD_DSA;
    else if (strncmp(alg, "DH", len) == 0)
        *pflags |= ENGINE_METHOD_DH;
    else if (strncmp(alg, "EC", len) == 0)
        *pflags |= ENGINE_METHOD_EC;
    else if (strncmp(alg, "RAND", len) == 0)
        *pflags |= ENGINE_METHOD_RAND;
    else if (strncmp(alg, "CIPHERS", len) == 0)
        *pflags |= ENGINE_METHOD_CIPHERS;
    else if (strncmp(alg, "DIGESTS", len) == 0)
        *pflags |= ENGINE_METHOD_DIGESTS;
    else if (strncmp(alg, "PKEY", len) == 0)
        *pflags |= ENGINE_METHOD_PKEY_METHS | ENGINE_METHOD_PKEY_ASN1_METHS;
    else if (strncmp(alg, "PKEY_CRYPTO", len) == 0)
        *pflags |= ENGINE_METHOD_PKEY_METHS;
    else if (strncmp(alg, "PKEY_ASN1", len) == 0)
        *pflags |= ENGINE_METHOD_PKEY_ASN1_METHS;
    else
        return 0;
    return 1;
}

int ENGINE_set_default_string(ENGINE *e, const char *def_list)
{
    unsigned int flags = 0;
    if (!CONF_parse_list(def_list, ',', 1, int_def_cb, &flags)) {
        ENGINEerr(ENGINE_F_ENGINE_SET_DEFAULT_STRING,
                  ENGINE_R_INVALID_STRING);
        ERR_add_error_data(2, "str=", def_list);
        return 0;
    }
    return ENGINE_set_default(e, flags);
}

int ENGINE_register_complete(ENGINE *e)
{
    ENGINE_register_ciphers(e);
    ENGINE_register_digests(e);
#ifndef OPENSSL_NO_RSA
    ENGINE_register_RSA(e);
#endif
#ifndef OPENSSL_NO_DSA
    ENGINE_register_DSA(e);
#endif
#ifndef OPENSSL_NO_DH
    ENGINE_register_DH(e);
#endif
#ifndef OPENSSL_NO_EC
    ENGINE_register_EC(e);
#endif
    ENGINE_register_RAND(e);
    ENGINE_register_pkey_meths(e);
    ENGINE_register_pkey_asn1_meths(e);
    return 1;
}

int ENGINE_register_all_complete(void)
{
    ENGINE *e;

    for (e = ENGINE_get_first(); e; e = ENGINE_get_next(e))
        if (!(e->flags & ENGINE_FLAGS_NO_REGISTER_ALL))
            ENGINE_register_complete(e);
    return 1;
}

