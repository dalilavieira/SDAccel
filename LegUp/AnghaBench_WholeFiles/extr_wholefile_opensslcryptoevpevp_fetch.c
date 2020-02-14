#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct method_data_st {int nid; int (* refcnt_up_method ) (void*) ;int (* nid_method ) (void*) ;void (* destruct_method ) (void*) ;void* (* method_from_dispatch ) (int,int /*<<< orphan*/  const*,int /*<<< orphan*/ *) ;TYPE_1__* mcm; int /*<<< orphan*/  name; } ;
struct TYPE_6__ {int /*<<< orphan*/ * data; scalar_t__ length; int /*<<< orphan*/  flags; int /*<<< orphan*/  ln; int /*<<< orphan*/  sn; int /*<<< orphan*/  nid; } ;
struct TYPE_5__ {void* (* member_0 ) (int /*<<< orphan*/ *) ;void (* member_1 ) (void*) ;void* (* member_2 ) (int /*<<< orphan*/ *,void*,char const*,void*) ;int (* member_3 ) (int /*<<< orphan*/ *,void*,char const*,void*,void*) ;void* (* member_4 ) (char const*,int /*<<< orphan*/  const*,int /*<<< orphan*/ *,void*) ;void (* member_5 ) (void*,void*) ;} ;
typedef  int /*<<< orphan*/  OSSL_PROVIDER ;
typedef  int /*<<< orphan*/  OSSL_METHOD_STORE ;
typedef  TYPE_1__ OSSL_METHOD_CONSTRUCT_METHOD ;
typedef  int /*<<< orphan*/  OSSL_DISPATCH ;
typedef  int /*<<< orphan*/  OPENSSL_CTX ;
typedef  TYPE_2__ ASN1_OBJECT ;

/* Variables and functions */
 int /*<<< orphan*/  ASN1_OBJECT_FLAG_DYNAMIC ; 
 int /*<<< orphan*/  ERR_R_INTERNAL_ERROR ; 
 int /*<<< orphan*/  EVP_F_EVP_SET_DEFAULT_PROPERTIES ; 
 int /*<<< orphan*/  EVPerr (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int NID_undef ; 
 int OBJ_add_object (TYPE_2__*) ; 
 int /*<<< orphan*/  OBJ_new_nid (int) ; 
 int OBJ_sn2nid (char const*) ; 
 int /*<<< orphan*/  OPENSSL_CTX_DEFAULT_METHOD_STORE_INDEX ; 
 int /*<<< orphan*/  default_method_store_method ; 
 int /*<<< orphan*/ * openssl_ctx_get_data (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 void* ossl_method_construct (int /*<<< orphan*/ *,int,char const*,char const*,int /*<<< orphan*/ ,TYPE_1__*,struct method_data_st*) ; 
 scalar_t__ ossl_method_store_add (void*,int,char const*,void*,void (*) (void*)) ; 
 int /*<<< orphan*/  ossl_method_store_cache_get (int /*<<< orphan*/ *,int,char const*,void**) ; 
 int /*<<< orphan*/  ossl_method_store_cache_set (int /*<<< orphan*/ *,int,char const*,void*) ; 
 int /*<<< orphan*/  ossl_method_store_fetch (void*,int,char const*,void**) ; 
 int /*<<< orphan*/  ossl_method_store_free (void*) ; 
 void* ossl_method_store_new (int /*<<< orphan*/ *) ; 
 int ossl_method_store_set_global_properties (int /*<<< orphan*/ *,char const*) ; 
 int stub1 (void*) ; 
 int stub2 (void*) ; 
 int stub3 (void*) ; 
 void* stub4 (int,int /*<<< orphan*/  const*,int /*<<< orphan*/ *) ; 
 void stub5 (void*) ; 

__attribute__((used)) static void default_method_store_free(void *vstore)
{
    ossl_method_store_free(vstore);
}

__attribute__((used)) static void *default_method_store_new(OPENSSL_CTX *ctx)
{
    return ossl_method_store_new(ctx);
}

__attribute__((used)) static void *alloc_tmp_method_store(OPENSSL_CTX *ctx)
{
    return ossl_method_store_new(ctx);
}

__attribute__((used)) static void dealloc_tmp_method_store(void *store)
{
    if (store != NULL)
        ossl_method_store_free(store);
}

__attribute__((used)) static OSSL_METHOD_STORE *get_default_method_store(OPENSSL_CTX *libctx)
{
    return openssl_ctx_get_data(libctx, OPENSSL_CTX_DEFAULT_METHOD_STORE_INDEX,
                                &default_method_store_method);
}

__attribute__((used)) static void *get_method_from_store(OPENSSL_CTX *libctx, void *store,
                                   const char *propquery, void *data)
{
    struct method_data_st *methdata = data;
    void *method = NULL;

    if (store == NULL
        && (store = get_default_method_store(libctx)) == NULL)
        return NULL;

    (void)ossl_method_store_fetch(store, methdata->nid, propquery, &method);

    if (method != NULL
        && !methdata->refcnt_up_method(method)) {
        method = NULL;
    }
    return method;
}

__attribute__((used)) static int put_method_in_store(OPENSSL_CTX *libctx, void *store,
                               const char *propdef,
                               void *method, void *data)
{
    struct method_data_st *methdata = data;
    int nid = methdata->nid_method(method);

    if (nid == NID_undef)
        return 0;

    if (store == NULL
        && (store = get_default_method_store(libctx)) == NULL)
        return 0;

    if (methdata->refcnt_up_method(method)
        && ossl_method_store_add(store, nid, propdef, method,
                                 methdata->destruct_method))
        return 1;
    return 0;
}

__attribute__((used)) static void *construct_method(const char *algorithm_name,
                              const OSSL_DISPATCH *fns, OSSL_PROVIDER *prov,
                              void *data)
{
    struct method_data_st *methdata = data;
    void *method = NULL;
    int nid = OBJ_sn2nid(algorithm_name);

    if (nid == NID_undef) {
        /* Create a new NID for that name on the fly */
        ASN1_OBJECT tmpobj;

        /* This is the same as OBJ_create() but without requiring a OID */
        tmpobj.nid = OBJ_new_nid(1);
        tmpobj.sn = tmpobj.ln = methdata->name;
        tmpobj.flags = ASN1_OBJECT_FLAG_DYNAMIC;
        tmpobj.length = 0;
        tmpobj.data = NULL;

        nid = OBJ_add_object(&tmpobj);
    }

    if (nid == NID_undef)
        return NULL;

    method = methdata->method_from_dispatch(nid, fns, prov);
    if (method == NULL)
        return NULL;
    return method;
}

__attribute__((used)) static void destruct_method(void *method, void *data)
{
    struct method_data_st *methdata = data;

    methdata->destruct_method(method);
}

void *evp_generic_fetch(OPENSSL_CTX *libctx, int operation_id,
                        const char *algorithm, const char *properties,
                        void *(*new_method)(int nid, const OSSL_DISPATCH *fns,
                                            OSSL_PROVIDER *prov),
                        int (*upref_method)(void *),
                        void (*free_method)(void *),
                        int (*nid_method)(void *))
{
    OSSL_METHOD_STORE *store = get_default_method_store(libctx);
    int nid = OBJ_sn2nid(algorithm);
    void *method = NULL;

    if (store == NULL)
        return NULL;

    if (nid == NID_undef
        || !ossl_method_store_cache_get(store, nid, properties, &method)) {
        OSSL_METHOD_CONSTRUCT_METHOD mcm = {
            alloc_tmp_method_store,
            dealloc_tmp_method_store,
            get_method_from_store,
            put_method_in_store,
            construct_method,
            destruct_method
        };
        struct method_data_st mcmdata;

        mcmdata.nid = nid;
        mcmdata.mcm = &mcm;
        mcmdata.method_from_dispatch = new_method;
        mcmdata.destruct_method = free_method;
        mcmdata.refcnt_up_method = upref_method;
        mcmdata.destruct_method = free_method;
        mcmdata.nid_method = nid_method;
        method = ossl_method_construct(libctx, operation_id, algorithm,
                                       properties, 0 /* !force_cache */,
                                       &mcm, &mcmdata);
        ossl_method_store_cache_set(store, nid, properties, method);
    } else {
        upref_method(method);
    }

    return method;
}

int EVP_set_default_properties(OPENSSL_CTX *libctx, const char *propq)
{
    OSSL_METHOD_STORE *store = get_default_method_store(libctx);

    if (store != NULL)
        return ossl_method_store_set_global_properties(store, propq);
    EVPerr(EVP_F_EVP_SET_DEFAULT_PROPERTIES, ERR_R_INTERNAL_ERROR);
    return 0;
}

