#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_37__   TYPE_5__ ;
typedef  struct TYPE_36__   TYPE_4__ ;
typedef  struct TYPE_35__   TYPE_3__ ;
typedef  struct TYPE_34__   TYPE_2__ ;
typedef  struct TYPE_33__   TYPE_1__ ;

/* Type definitions */
struct TYPE_35__ {int /*<<< orphan*/  extensions; } ;
typedef  TYPE_3__ X509_REVOKED ;
typedef  int /*<<< orphan*/  X509_EXTENSION ;
struct TYPE_33__ {int /*<<< orphan*/  extensions; } ;
struct TYPE_36__ {TYPE_1__ crl; } ;
typedef  TYPE_4__ X509_CRL ;
struct TYPE_34__ {int /*<<< orphan*/  extensions; } ;
struct TYPE_37__ {TYPE_2__ cert_info; } ;
typedef  TYPE_5__ X509 ;
typedef  int /*<<< orphan*/  ASN1_OBJECT ;

/* Variables and functions */
 int X509V3_add1_i2d (int /*<<< orphan*/ *,int,void*,int,unsigned long) ; 
 void* X509V3_get_d2i (int /*<<< orphan*/ ,int,int*,int*) ; 
 int /*<<< orphan*/ * X509v3_add_ext (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/ * X509v3_delete_ext (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/ * X509v3_get_ext (int /*<<< orphan*/ ,int) ; 
 int X509v3_get_ext_by_NID (int /*<<< orphan*/ ,int,int) ; 
 int X509v3_get_ext_by_OBJ (int /*<<< orphan*/ ,int /*<<< orphan*/  const*,int) ; 
 int X509v3_get_ext_by_critical (int /*<<< orphan*/ ,int,int) ; 
 int X509v3_get_ext_count (int /*<<< orphan*/ ) ; 

int X509_CRL_get_ext_count(const X509_CRL *x)
{
    return X509v3_get_ext_count(x->crl.extensions);
}

int X509_CRL_get_ext_by_NID(const X509_CRL *x, int nid, int lastpos)
{
    return X509v3_get_ext_by_NID(x->crl.extensions, nid, lastpos);
}

int X509_CRL_get_ext_by_OBJ(const X509_CRL *x, const ASN1_OBJECT *obj,
                            int lastpos)
{
    return X509v3_get_ext_by_OBJ(x->crl.extensions, obj, lastpos);
}

int X509_CRL_get_ext_by_critical(const X509_CRL *x, int crit, int lastpos)
{
    return X509v3_get_ext_by_critical(x->crl.extensions, crit, lastpos);
}

X509_EXTENSION *X509_CRL_get_ext(const X509_CRL *x, int loc)
{
    return X509v3_get_ext(x->crl.extensions, loc);
}

X509_EXTENSION *X509_CRL_delete_ext(X509_CRL *x, int loc)
{
    return X509v3_delete_ext(x->crl.extensions, loc);
}

void *X509_CRL_get_ext_d2i(const X509_CRL *x, int nid, int *crit, int *idx)
{
    return X509V3_get_d2i(x->crl.extensions, nid, crit, idx);
}

int X509_CRL_add1_ext_i2d(X509_CRL *x, int nid, void *value, int crit,
                          unsigned long flags)
{
    return X509V3_add1_i2d(&x->crl.extensions, nid, value, crit, flags);
}

int X509_CRL_add_ext(X509_CRL *x, X509_EXTENSION *ex, int loc)
{
    return (X509v3_add_ext(&(x->crl.extensions), ex, loc) != NULL);
}

int X509_get_ext_count(const X509 *x)
{
    return X509v3_get_ext_count(x->cert_info.extensions);
}

int X509_get_ext_by_NID(const X509 *x, int nid, int lastpos)
{
    return X509v3_get_ext_by_NID(x->cert_info.extensions, nid, lastpos);
}

int X509_get_ext_by_OBJ(const X509 *x, const ASN1_OBJECT *obj, int lastpos)
{
    return X509v3_get_ext_by_OBJ(x->cert_info.extensions, obj, lastpos);
}

int X509_get_ext_by_critical(const X509 *x, int crit, int lastpos)
{
    return (X509v3_get_ext_by_critical
            (x->cert_info.extensions, crit, lastpos));
}

X509_EXTENSION *X509_get_ext(const X509 *x, int loc)
{
    return X509v3_get_ext(x->cert_info.extensions, loc);
}

X509_EXTENSION *X509_delete_ext(X509 *x, int loc)
{
    return X509v3_delete_ext(x->cert_info.extensions, loc);
}

int X509_add_ext(X509 *x, X509_EXTENSION *ex, int loc)
{
    return (X509v3_add_ext(&(x->cert_info.extensions), ex, loc) != NULL);
}

void *X509_get_ext_d2i(const X509 *x, int nid, int *crit, int *idx)
{
    return X509V3_get_d2i(x->cert_info.extensions, nid, crit, idx);
}

int X509_add1_ext_i2d(X509 *x, int nid, void *value, int crit,
                      unsigned long flags)
{
    return X509V3_add1_i2d(&x->cert_info.extensions, nid, value, crit,
                           flags);
}

int X509_REVOKED_get_ext_count(const X509_REVOKED *x)
{
    return X509v3_get_ext_count(x->extensions);
}

int X509_REVOKED_get_ext_by_NID(const X509_REVOKED *x, int nid, int lastpos)
{
    return X509v3_get_ext_by_NID(x->extensions, nid, lastpos);
}

int X509_REVOKED_get_ext_by_OBJ(const X509_REVOKED *x, const ASN1_OBJECT *obj,
                                int lastpos)
{
    return X509v3_get_ext_by_OBJ(x->extensions, obj, lastpos);
}

int X509_REVOKED_get_ext_by_critical(const X509_REVOKED *x, int crit, int lastpos)
{
    return X509v3_get_ext_by_critical(x->extensions, crit, lastpos);
}

X509_EXTENSION *X509_REVOKED_get_ext(const X509_REVOKED *x, int loc)
{
    return X509v3_get_ext(x->extensions, loc);
}

X509_EXTENSION *X509_REVOKED_delete_ext(X509_REVOKED *x, int loc)
{
    return X509v3_delete_ext(x->extensions, loc);
}

int X509_REVOKED_add_ext(X509_REVOKED *x, X509_EXTENSION *ex, int loc)
{
    return (X509v3_add_ext(&(x->extensions), ex, loc) != NULL);
}

void *X509_REVOKED_get_ext_d2i(const X509_REVOKED *x, int nid, int *crit, int *idx)
{
    return X509V3_get_d2i(x->extensions, nid, crit, idx);
}

int X509_REVOKED_add1_ext_i2d(X509_REVOKED *x, int nid, void *value, int crit,
                              unsigned long flags)
{
    return X509V3_add1_i2d(&x->extensions, nid, value, crit, flags);
}

