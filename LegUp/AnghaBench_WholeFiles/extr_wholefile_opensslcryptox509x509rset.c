#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {int modified; } ;
struct TYPE_8__ {int /*<<< orphan*/  pubkey; TYPE_1__ enc; int /*<<< orphan*/  subject; int /*<<< orphan*/  version; } ;
struct TYPE_9__ {TYPE_2__ req_info; } ;
typedef  TYPE_3__ X509_REQ ;
typedef  int /*<<< orphan*/  X509_NAME ;
typedef  int /*<<< orphan*/  EVP_PKEY ;

/* Variables and functions */
 int ASN1_INTEGER_set (int /*<<< orphan*/ ,long) ; 
 int X509_NAME_set (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int X509_PUBKEY_set (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

int X509_REQ_set_version(X509_REQ *x, long version)
{
    if (x == NULL)
        return 0;
    x->req_info.enc.modified = 1;
    return ASN1_INTEGER_set(x->req_info.version, version);
}

int X509_REQ_set_subject_name(X509_REQ *x, X509_NAME *name)
{
    if (x == NULL)
        return 0;
    x->req_info.enc.modified = 1;
    return X509_NAME_set(&x->req_info.subject, name);
}

int X509_REQ_set_pubkey(X509_REQ *x, EVP_PKEY *pkey)
{
    if (x == NULL)
        return 0;
    x->req_info.enc.modified = 1;
    return X509_PUBKEY_set(&x->req_info.pubkey, pkey);
}

