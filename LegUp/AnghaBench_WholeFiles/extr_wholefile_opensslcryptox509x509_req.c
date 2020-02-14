#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_3__ ;
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
struct TYPE_15__ {int /*<<< orphan*/ * pubkey; TYPE_1__* version; } ;
typedef  TYPE_2__ X509_REQ_INFO ;
struct TYPE_16__ {TYPE_2__ req_info; } ;
typedef  TYPE_3__ X509_REQ ;
typedef  int /*<<< orphan*/  X509_PUBKEY ;
typedef  int /*<<< orphan*/  X509 ;
struct TYPE_14__ {int length; scalar_t__* data; } ;
typedef  int /*<<< orphan*/  EVP_PKEY ;
typedef  int /*<<< orphan*/  EVP_MD ;

/* Variables and functions */
 int /*<<< orphan*/  ERR_R_EC_LIB ; 
 int /*<<< orphan*/  ERR_R_MALLOC_FAILURE ; 
 int /*<<< orphan*/  EVP_PKEY_DH ; 
 int /*<<< orphan*/  EVP_PKEY_EC ; 
 int EVP_PKEY_cmp (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  EVP_PKEY_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  EVP_PKEY_id (int /*<<< orphan*/ *) ; 
 int NID_undef ; 
 scalar_t__* OPENSSL_malloc (int) ; 
 int /*<<< orphan*/  X509_F_X509_REQ_CHECK_PRIVATE_KEY ; 
 int /*<<< orphan*/  X509_F_X509_TO_X509_REQ ; 
 int /*<<< orphan*/ * X509_PUBKEY_get (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * X509_PUBKEY_get0 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  X509_REQ_free (TYPE_3__*) ; 
 TYPE_3__* X509_REQ_new () ; 
 int X509_REQ_set_pubkey (TYPE_3__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  X509_REQ_set_subject_name (TYPE_3__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  X509_REQ_sign (TYPE_3__*,int /*<<< orphan*/ *,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  X509_R_CANT_CHECK_DH_KEY ; 
 int /*<<< orphan*/  X509_R_KEY_TYPE_MISMATCH ; 
 int /*<<< orphan*/  X509_R_KEY_VALUES_MISMATCH ; 
 int /*<<< orphan*/  X509_R_UNKNOWN_KEY_TYPE ; 
 int /*<<< orphan*/ * X509_get0_pubkey (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  X509_get_subject_name (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  X509err (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int* ext_nids ; 

X509_REQ *X509_to_X509_REQ(X509 *x, EVP_PKEY *pkey, const EVP_MD *md)
{
    X509_REQ *ret;
    X509_REQ_INFO *ri;
    int i;
    EVP_PKEY *pktmp;

    ret = X509_REQ_new();
    if (ret == NULL) {
        X509err(X509_F_X509_TO_X509_REQ, ERR_R_MALLOC_FAILURE);
        goto err;
    }

    ri = &ret->req_info;

    ri->version->length = 1;
    ri->version->data = OPENSSL_malloc(1);
    if (ri->version->data == NULL)
        goto err;
    ri->version->data[0] = 0;   /* version == 0 */

    if (!X509_REQ_set_subject_name(ret, X509_get_subject_name(x)))
        goto err;

    pktmp = X509_get0_pubkey(x);
    if (pktmp == NULL)
        goto err;
    i = X509_REQ_set_pubkey(ret, pktmp);
    if (!i)
        goto err;

    if (pkey != NULL) {
        if (!X509_REQ_sign(ret, pkey, md))
            goto err;
    }
    return ret;
 err:
    X509_REQ_free(ret);
    return NULL;
}

EVP_PKEY *X509_REQ_get_pubkey(X509_REQ *req)
{
    if (req == NULL)
        return NULL;
    return X509_PUBKEY_get(req->req_info.pubkey);
}

EVP_PKEY *X509_REQ_get0_pubkey(X509_REQ *req)
{
    if (req == NULL)
        return NULL;
    return X509_PUBKEY_get0(req->req_info.pubkey);
}

X509_PUBKEY *X509_REQ_get_X509_PUBKEY(X509_REQ *req)
{
    return req->req_info.pubkey;
}

int X509_REQ_check_private_key(X509_REQ *x, EVP_PKEY *k)
{
    EVP_PKEY *xk = NULL;
    int ok = 0;

    xk = X509_REQ_get_pubkey(x);
    switch (EVP_PKEY_cmp(xk, k)) {
    case 1:
        ok = 1;
        break;
    case 0:
        X509err(X509_F_X509_REQ_CHECK_PRIVATE_KEY,
                X509_R_KEY_VALUES_MISMATCH);
        break;
    case -1:
        X509err(X509_F_X509_REQ_CHECK_PRIVATE_KEY, X509_R_KEY_TYPE_MISMATCH);
        break;
    case -2:
#ifndef OPENSSL_NO_EC
        if (EVP_PKEY_id(k) == EVP_PKEY_EC) {
            X509err(X509_F_X509_REQ_CHECK_PRIVATE_KEY, ERR_R_EC_LIB);
            break;
        }
#endif
#ifndef OPENSSL_NO_DH
        if (EVP_PKEY_id(k) == EVP_PKEY_DH) {
            /* No idea */
            X509err(X509_F_X509_REQ_CHECK_PRIVATE_KEY,
                    X509_R_CANT_CHECK_DH_KEY);
            break;
        }
#endif
        X509err(X509_F_X509_REQ_CHECK_PRIVATE_KEY, X509_R_UNKNOWN_KEY_TYPE);
    }

    EVP_PKEY_free(xk);
    return ok;
}

int X509_REQ_extension_nid(int req_nid)
{
    int i, nid;
    for (i = 0;; i++) {
        nid = ext_nids[i];
        if (nid == NID_undef)
            return 0;
        else if (req_nid == nid)
            return 1;
    }
}

int *X509_REQ_get_extension_nids(void)
{
    return ext_nids;
}

void X509_REQ_set_extension_nids(int *nids)
{
    ext_nids = nids;
}

