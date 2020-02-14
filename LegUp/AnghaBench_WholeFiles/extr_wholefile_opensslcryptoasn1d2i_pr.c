#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
struct TYPE_13__ {TYPE_1__* ameth; int /*<<< orphan*/ * engine; } ;
struct TYPE_12__ {scalar_t__ priv_decode; int /*<<< orphan*/  (* old_priv_decode ) (TYPE_2__*,unsigned char const**,long) ;} ;
typedef  int /*<<< orphan*/  PKCS8_PRIV_KEY_INFO ;
typedef  TYPE_2__ EVP_PKEY ;

/* Variables and functions */
 int /*<<< orphan*/  ASN1_F_D2I_AUTOPRIVATEKEY ; 
 int /*<<< orphan*/  ASN1_F_D2I_PRIVATEKEY ; 
 int /*<<< orphan*/  ASN1_R_UNKNOWN_PUBLIC_KEY_TYPE ; 
 int /*<<< orphan*/  ASN1_R_UNSUPPORTED_PUBLIC_KEY_TYPE ; 
 int /*<<< orphan*/  ASN1_TYPE ; 
 int /*<<< orphan*/  ASN1_TYPE_free ; 
 int /*<<< orphan*/  ASN1err (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ENGINE_finish (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ERR_R_ASN1_LIB ; 
 int /*<<< orphan*/  ERR_R_EVP_LIB ; 
 TYPE_2__* EVP_PKCS82PKEY (int /*<<< orphan*/ *) ; 
 int EVP_PKEY_DSA ; 
 int EVP_PKEY_EC ; 
 int EVP_PKEY_RSA ; 
 int /*<<< orphan*/  EVP_PKEY_free (TYPE_2__*) ; 
 TYPE_2__* EVP_PKEY_new () ; 
 int /*<<< orphan*/  EVP_PKEY_set_type (TYPE_2__*,int) ; 
 int /*<<< orphan*/  PKCS8_PRIV_KEY_INFO_free (int /*<<< orphan*/ *) ; 
 int STACK_OF (int /*<<< orphan*/ ) ; 
 int d2i_ASN1_SEQUENCE_ANY (int /*<<< orphan*/ *,unsigned char const**,long) ; 
 int /*<<< orphan*/ * d2i_PKCS8_PRIV_KEY_INFO (int /*<<< orphan*/ *,unsigned char const**,long) ; 
 int inkey ; 
 int sk_ASN1_TYPE_num (int) ; 
 int /*<<< orphan*/  sk_ASN1_TYPE_pop_free (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (TYPE_2__*,unsigned char const**,long) ; 

EVP_PKEY *d2i_PrivateKey(int type, EVP_PKEY **a, const unsigned char **pp,
                         long length)
{
    EVP_PKEY *ret;
    const unsigned char *p = *pp;

    if ((a == NULL) || (*a == NULL)) {
        if ((ret = EVP_PKEY_new()) == NULL) {
            ASN1err(ASN1_F_D2I_PRIVATEKEY, ERR_R_EVP_LIB);
            return NULL;
        }
    } else {
        ret = *a;
#ifndef OPENSSL_NO_ENGINE
        ENGINE_finish(ret->engine);
        ret->engine = NULL;
#endif
    }

    if (!EVP_PKEY_set_type(ret, type)) {
        ASN1err(ASN1_F_D2I_PRIVATEKEY, ASN1_R_UNKNOWN_PUBLIC_KEY_TYPE);
        goto err;
    }

    if (!ret->ameth->old_priv_decode ||
        !ret->ameth->old_priv_decode(ret, &p, length)) {
        if (ret->ameth->priv_decode) {
            EVP_PKEY *tmp;
            PKCS8_PRIV_KEY_INFO *p8 = NULL;
            p8 = d2i_PKCS8_PRIV_KEY_INFO(NULL, &p, length);
            if (!p8)
                goto err;
            tmp = EVP_PKCS82PKEY(p8);
            PKCS8_PRIV_KEY_INFO_free(p8);
            if (tmp == NULL)
                goto err;
            EVP_PKEY_free(ret);
            ret = tmp;
        } else {
            ASN1err(ASN1_F_D2I_PRIVATEKEY, ERR_R_ASN1_LIB);
            goto err;
        }
    }
    *pp = p;
    if (a != NULL)
        (*a) = ret;
    return ret;
 err:
    if (a == NULL || *a != ret)
        EVP_PKEY_free(ret);
    return NULL;
}

EVP_PKEY *d2i_AutoPrivateKey(EVP_PKEY **a, const unsigned char **pp,
                             long length)
{
    STACK_OF(ASN1_TYPE) *inkey;
    const unsigned char *p;
    int keytype;
    p = *pp;
    /*
     * Dirty trick: read in the ASN1 data into a STACK_OF(ASN1_TYPE): by
     * analyzing it we can determine the passed structure: this assumes the
     * input is surrounded by an ASN1 SEQUENCE.
     */
    inkey = d2i_ASN1_SEQUENCE_ANY(NULL, &p, length);
    p = *pp;
    /*
     * Since we only need to discern "traditional format" RSA and DSA keys we
     * can just count the elements.
     */
    if (sk_ASN1_TYPE_num(inkey) == 6)
        keytype = EVP_PKEY_DSA;
    else if (sk_ASN1_TYPE_num(inkey) == 4)
        keytype = EVP_PKEY_EC;
    else if (sk_ASN1_TYPE_num(inkey) == 3) { /* This seems to be PKCS8, not
                                              * traditional format */
        PKCS8_PRIV_KEY_INFO *p8 = d2i_PKCS8_PRIV_KEY_INFO(NULL, &p, length);
        EVP_PKEY *ret;

        sk_ASN1_TYPE_pop_free(inkey, ASN1_TYPE_free);
        if (!p8) {
            ASN1err(ASN1_F_D2I_AUTOPRIVATEKEY,
                    ASN1_R_UNSUPPORTED_PUBLIC_KEY_TYPE);
            return NULL;
        }
        ret = EVP_PKCS82PKEY(p8);
        PKCS8_PRIV_KEY_INFO_free(p8);
        if (ret == NULL)
            return NULL;
        *pp = p;
        if (a) {
            *a = ret;
        }
        return ret;
    } else
        keytype = EVP_PKEY_RSA;
    sk_ASN1_TYPE_pop_free(inkey, ASN1_TYPE_free);
    return d2i_PrivateKey(keytype, a, pp, length);
}

