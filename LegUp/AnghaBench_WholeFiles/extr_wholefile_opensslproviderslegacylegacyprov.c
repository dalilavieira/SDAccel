#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {int function_id; } ;
typedef  int /*<<< orphan*/  OSSL_PROVIDER ;
typedef  int /*<<< orphan*/  OSSL_PARAM ;
typedef  int /*<<< orphan*/  OSSL_ITEM ;
typedef  TYPE_1__ OSSL_DISPATCH ;
typedef  int /*<<< orphan*/  OSSL_ALGORITHM ;

/* Variables and functions */
 char* OPENSSL_FULL_VERSION_STR ; 
 char* OPENSSL_VERSION_STR ; 
#define  OSSL_FUNC_CORE_GET_PARAMS 130 
#define  OSSL_FUNC_CORE_GET_PARAM_TYPES 129 
#define  OSSL_OP_DIGEST 128 
 int /*<<< orphan*/ * OSSL_PARAM_locate (int /*<<< orphan*/  const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  OSSL_PARAM_set_utf8_ptr (int /*<<< orphan*/  const*,char*) ; 
 int /*<<< orphan*/  OSSL_PROV_PARAM_BUILDINFO ; 
 int /*<<< orphan*/  OSSL_PROV_PARAM_NAME ; 
 int /*<<< orphan*/  OSSL_PROV_PARAM_VERSION ; 
 int /*<<< orphan*/  OSSL_get_core_get_param_types (TYPE_1__ const*) ; 
 int /*<<< orphan*/  OSSL_get_core_get_params (TYPE_1__ const*) ; 
 int /*<<< orphan*/  c_get_param_types ; 
 int /*<<< orphan*/  c_get_params ; 
 int /*<<< orphan*/  const* legacy_digests ; 
 TYPE_1__* legacy_dispatch_table ; 
 int /*<<< orphan*/  const* legacy_param_types ; 

__attribute__((used)) static const OSSL_ITEM *legacy_get_param_types(const OSSL_PROVIDER *prov)
{
    return legacy_param_types;
}

__attribute__((used)) static int legacy_get_params(const OSSL_PROVIDER *prov,
                            const OSSL_PARAM params[])
{
    const OSSL_PARAM *p;

    p = OSSL_PARAM_locate(params, OSSL_PROV_PARAM_NAME);
    if (p != NULL && !OSSL_PARAM_set_utf8_ptr(p, "OpenSSL Legacy Provider"))
        return 0;
    p = OSSL_PARAM_locate(params, OSSL_PROV_PARAM_VERSION);
    if (p != NULL && !OSSL_PARAM_set_utf8_ptr(p, OPENSSL_VERSION_STR))
        return 0;
    p = OSSL_PARAM_locate(params, OSSL_PROV_PARAM_BUILDINFO);
    if (p != NULL && !OSSL_PARAM_set_utf8_ptr(p, OPENSSL_FULL_VERSION_STR))
        return 0;

    return 1;
}

__attribute__((used)) static const OSSL_ALGORITHM *legacy_query(OSSL_PROVIDER *prov,
                                          int operation_id,
                                          int *no_cache)
{
    *no_cache = 0;
    switch (operation_id) {
    case OSSL_OP_DIGEST:
        return legacy_digests;
    }
    return NULL;
}

int OSSL_provider_init(const OSSL_PROVIDER *provider,
                       const OSSL_DISPATCH *in,
                       const OSSL_DISPATCH **out,
                       void **provctx)
{
    for (; in->function_id != 0; in++) {
        switch (in->function_id) {
        case OSSL_FUNC_CORE_GET_PARAM_TYPES:
            c_get_param_types = OSSL_get_core_get_param_types(in);
            break;
        case OSSL_FUNC_CORE_GET_PARAMS:
            c_get_params = OSSL_get_core_get_params(in);
            break;
        /* Just ignore anything we don't understand */
        default:
            break;
        }
    }

    *out = legacy_dispatch_table;
    return 1;
}

