#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {struct TYPE_6__* enc_data; int /*<<< orphan*/  x_pkey; int /*<<< orphan*/  crl; int /*<<< orphan*/  x509; } ;
typedef  TYPE_1__ X509_INFO ;

/* Variables and functions */
 int /*<<< orphan*/  ASN1_F_X509_INFO_NEW ; 
 int /*<<< orphan*/  ASN1err (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ERR_R_MALLOC_FAILURE ; 
 int /*<<< orphan*/  OPENSSL_free (TYPE_1__*) ; 
 TYPE_1__* OPENSSL_zalloc (int) ; 
 int /*<<< orphan*/  X509_CRL_free (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  X509_PKEY_free (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  X509_free (int /*<<< orphan*/ ) ; 

X509_INFO *X509_INFO_new(void)
{
    X509_INFO *ret;

    ret = OPENSSL_zalloc(sizeof(*ret));
    if (ret == NULL) {
        ASN1err(ASN1_F_X509_INFO_NEW, ERR_R_MALLOC_FAILURE);
        return NULL;
    }

    return ret;
}

void X509_INFO_free(X509_INFO *x)
{
    if (x == NULL)
        return;

    X509_free(x->x509);
    X509_CRL_free(x->crl);
    X509_PKEY_free(x->x_pkey);
    OPENSSL_free(x->enc_data);
    OPENSSL_free(x);
}

