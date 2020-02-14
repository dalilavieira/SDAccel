#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_22__   TYPE_4__ ;
typedef  struct TYPE_21__   TYPE_3__ ;
typedef  struct TYPE_20__   TYPE_2__ ;
typedef  struct TYPE_19__   TYPE_1__ ;

/* Type definitions */
struct TYPE_21__ {int sequence; } ;
typedef  TYPE_3__ X509_REVOKED ;
typedef  int /*<<< orphan*/  X509_NAME ;
struct TYPE_19__ {int modified; } ;
struct TYPE_20__ {int /*<<< orphan*/ * issuer; int /*<<< orphan*/  const* nextUpdate; int /*<<< orphan*/  const* lastUpdate; int /*<<< orphan*/ * version; TYPE_1__ enc; int /*<<< orphan*/  revoked; } ;
struct TYPE_22__ {TYPE_2__ crl; int /*<<< orphan*/  lock; int /*<<< orphan*/  references; } ;
typedef  TYPE_4__ X509_CRL ;
typedef  int /*<<< orphan*/  const ASN1_TIME ;

/* Variables and functions */
 long ASN1_INTEGER_get (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * ASN1_INTEGER_new () ; 
 int ASN1_INTEGER_set (int /*<<< orphan*/ *,long) ; 
 scalar_t__ CRYPTO_UP_REF (int /*<<< orphan*/ *,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  REF_ASSERT_ISNT (int) ; 
 int /*<<< orphan*/  REF_PRINT_COUNT (char*,TYPE_4__*) ; 
 int X509_NAME_set (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int sk_X509_REVOKED_num (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sk_X509_REVOKED_sort (int /*<<< orphan*/ ) ; 
 TYPE_3__* sk_X509_REVOKED_value (int /*<<< orphan*/ ,int) ; 
 int x509_set1_time (int /*<<< orphan*/  const**,int /*<<< orphan*/  const*) ; 

int X509_CRL_set_version(X509_CRL *x, long version)
{
    if (x == NULL)
        return 0;
    if (x->crl.version == NULL) {
        if ((x->crl.version = ASN1_INTEGER_new()) == NULL)
            return 0;
    }
    return ASN1_INTEGER_set(x->crl.version, version);
}

int X509_CRL_set_issuer_name(X509_CRL *x, X509_NAME *name)
{
    if (x == NULL)
        return 0;
    return X509_NAME_set(&x->crl.issuer, name);
}

int X509_CRL_set1_lastUpdate(X509_CRL *x, const ASN1_TIME *tm)
{
    if (x == NULL)
        return 0;
    return x509_set1_time(&x->crl.lastUpdate, tm);
}

int X509_CRL_set1_nextUpdate(X509_CRL *x, const ASN1_TIME *tm)
{
    if (x == NULL)
        return 0;
    return x509_set1_time(&x->crl.nextUpdate, tm);
}

int X509_CRL_sort(X509_CRL *c)
{
    int i;
    X509_REVOKED *r;
    /*
     * sort the data so it will be written in serial number order
     */
    sk_X509_REVOKED_sort(c->crl.revoked);
    for (i = 0; i < sk_X509_REVOKED_num(c->crl.revoked); i++) {
        r = sk_X509_REVOKED_value(c->crl.revoked, i);
        r->sequence = i;
    }
    c->crl.enc.modified = 1;
    return 1;
}

int X509_CRL_up_ref(X509_CRL *crl)
{
    int i;

    if (CRYPTO_UP_REF(&crl->references, &i, crl->lock) <= 0)
        return 0;

    REF_PRINT_COUNT("X509_CRL", crl);
    REF_ASSERT_ISNT(i < 2);
    return ((i > 1) ? 1 : 0);
}

long X509_CRL_get_version(const X509_CRL *crl)
{
    return ASN1_INTEGER_get(crl->crl.version);
}

const ASN1_TIME *X509_CRL_get0_lastUpdate(const X509_CRL *crl)
{
    return crl->crl.lastUpdate;
}

const ASN1_TIME *X509_CRL_get0_nextUpdate(const X509_CRL *crl)
{
    return crl->crl.nextUpdate;
}

ASN1_TIME *X509_CRL_get_lastUpdate(X509_CRL *crl)
{
    return crl->crl.lastUpdate;
}

ASN1_TIME *X509_CRL_get_nextUpdate(X509_CRL *crl)
{
    return crl->crl.nextUpdate;
}

X509_NAME *X509_CRL_get_issuer(const X509_CRL *crl)
{
    return crl->crl.issuer;
}

