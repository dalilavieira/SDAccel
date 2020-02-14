#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_23__   TYPE_4__ ;
typedef  struct TYPE_22__   TYPE_3__ ;
typedef  struct TYPE_21__   TYPE_2__ ;
typedef  struct TYPE_20__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  X509_PUBKEY ;
typedef  int /*<<< orphan*/  X509_NAME ;
struct TYPE_20__ {int /*<<< orphan*/  const* notAfter; int /*<<< orphan*/  const* notBefore; } ;
struct TYPE_22__ {int /*<<< orphan*/ * key; TYPE_1__ validity; int /*<<< orphan*/  version; int /*<<< orphan*/  subject; int /*<<< orphan*/  issuer; int /*<<< orphan*/  serialNumber; } ;
struct TYPE_21__ {int /*<<< orphan*/  algorithm; } ;
struct TYPE_23__ {TYPE_3__ cert_info; TYPE_2__ sig_alg; int /*<<< orphan*/  lock; int /*<<< orphan*/  references; } ;
typedef  TYPE_4__ X509 ;
typedef  int /*<<< orphan*/  EVP_PKEY ;
typedef  int /*<<< orphan*/  const ASN1_TIME ;
typedef  int /*<<< orphan*/  ASN1_INTEGER ;

/* Variables and functions */
 long ASN1_INTEGER_get (int /*<<< orphan*/ ) ; 
 int ASN1_STRING_copy (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  const* ASN1_STRING_dup (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  ASN1_TIME_free (int /*<<< orphan*/  const*) ; 
 scalar_t__ CRYPTO_UP_REF (int /*<<< orphan*/ *,int*,int /*<<< orphan*/ ) ; 
 int EVP_PKEY_type (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  OBJ_obj2nid (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  REF_ASSERT_ISNT (int) ; 
 int /*<<< orphan*/  REF_PRINT_COUNT (char*,TYPE_4__*) ; 
 int X509_NAME_set (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int X509_PUBKEY_set (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 

int X509_set_serialNumber(X509 *x, ASN1_INTEGER *serial)
{
    ASN1_INTEGER *in;

    if (x == NULL)
        return 0;
    in = &x->cert_info.serialNumber;
    if (in != serial)
        return ASN1_STRING_copy(in, serial);
    return 1;
}

int X509_set_issuer_name(X509 *x, X509_NAME *name)
{
    if (x == NULL)
        return 0;
    return X509_NAME_set(&x->cert_info.issuer, name);
}

int X509_set_subject_name(X509 *x, X509_NAME *name)
{
    if (x == NULL)
        return 0;
    return X509_NAME_set(&x->cert_info.subject, name);
}

int x509_set1_time(ASN1_TIME **ptm, const ASN1_TIME *tm)
{
    ASN1_TIME *in;
    in = *ptm;
    if (in != tm) {
        in = ASN1_STRING_dup(tm);
        if (in != NULL) {
            ASN1_TIME_free(*ptm);
            *ptm = in;
        }
    }
    return (in != NULL);
}

int X509_set1_notBefore(X509 *x, const ASN1_TIME *tm)
{
    if (x == NULL)
        return 0;
    return x509_set1_time(&x->cert_info.validity.notBefore, tm);
}

int X509_set1_notAfter(X509 *x, const ASN1_TIME *tm)
{
    if (x == NULL)
        return 0;
    return x509_set1_time(&x->cert_info.validity.notAfter, tm);
}

int X509_set_pubkey(X509 *x, EVP_PKEY *pkey)
{
    if (x == NULL)
        return 0;
    return X509_PUBKEY_set(&(x->cert_info.key), pkey);
}

int X509_up_ref(X509 *x)
{
    int i;

    if (CRYPTO_UP_REF(&x->references, &i, x->lock) <= 0)
        return 0;

    REF_PRINT_COUNT("X509", x);
    REF_ASSERT_ISNT(i < 2);
    return ((i > 1) ? 1 : 0);
}

long X509_get_version(const X509 *x)
{
    return ASN1_INTEGER_get(x->cert_info.version);
}

const ASN1_TIME *X509_get0_notBefore(const X509 *x)
{
    return x->cert_info.validity.notBefore;
}

const ASN1_TIME *X509_get0_notAfter(const X509 *x)
{
    return x->cert_info.validity.notAfter;
}

ASN1_TIME *X509_getm_notBefore(const X509 *x)
{
    return x->cert_info.validity.notBefore;
}

ASN1_TIME *X509_getm_notAfter(const X509 *x)
{
    return x->cert_info.validity.notAfter;
}

int X509_get_signature_type(const X509 *x)
{
    return EVP_PKEY_type(OBJ_obj2nid(x->sig_alg.algorithm));
}

X509_PUBKEY *X509_get_X509_PUBKEY(const X509 *x)
{
    return x->cert_info.key;
}

