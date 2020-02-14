#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
struct TYPE_12__ {int (* scan_cb ) (TYPE_1__*) ;unsigned long flags; void* app_data; int /*<<< orphan*/  const* tt; int /*<<< orphan*/  const* it; } ;
typedef  int /*<<< orphan*/  ASN1_TEMPLATE ;
typedef  TYPE_1__ ASN1_SCTX ;
typedef  int /*<<< orphan*/  ASN1_ITEM ;

/* Variables and functions */
 int /*<<< orphan*/  ASN1_F_ASN1_SCTX_NEW ; 
 int /*<<< orphan*/  ASN1err (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ERR_R_MALLOC_FAILURE ; 
 int /*<<< orphan*/  OPENSSL_free (TYPE_1__*) ; 
 TYPE_1__* OPENSSL_zalloc (int) ; 

ASN1_SCTX *ASN1_SCTX_new(int (*scan_cb) (ASN1_SCTX *ctx))
{
    ASN1_SCTX *ret = OPENSSL_zalloc(sizeof(*ret));

    if (ret == NULL) {
        ASN1err(ASN1_F_ASN1_SCTX_NEW, ERR_R_MALLOC_FAILURE);
        return NULL;
    }
    ret->scan_cb = scan_cb;
    return ret;
}

void ASN1_SCTX_free(ASN1_SCTX *p)
{
    OPENSSL_free(p);
}

const ASN1_ITEM *ASN1_SCTX_get_item(ASN1_SCTX *p)
{
    return p->it;
}

const ASN1_TEMPLATE *ASN1_SCTX_get_template(ASN1_SCTX *p)
{
    return p->tt;
}

unsigned long ASN1_SCTX_get_flags(ASN1_SCTX *p)
{
    return p->flags;
}

void ASN1_SCTX_set_app_data(ASN1_SCTX *p, void *data)
{
    p->app_data = data;
}

void *ASN1_SCTX_get_app_data(ASN1_SCTX *p)
{
    return p->app_data;
}

