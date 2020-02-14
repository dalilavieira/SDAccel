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
struct construct_data_st {int operation_id; int force_store; int /*<<< orphan*/ * store; void* mcm_data; TYPE_1__* mcm; int /*<<< orphan*/ * libctx; } ;
struct TYPE_6__ {int /*<<< orphan*/  property_definition; int /*<<< orphan*/  implementation; int /*<<< orphan*/ * algorithm_name; } ;
struct TYPE_5__ {int /*<<< orphan*/  (* dealloc_tmp_store ) (int /*<<< orphan*/ *) ;void* (* get ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char const*,void*) ;int /*<<< orphan*/ * (* alloc_tmp_store ) (int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* destruct ) (void*,void*) ;int /*<<< orphan*/  (* put ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,void*,void*) ;void* (* construct ) (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,void*) ;} ;
typedef  int /*<<< orphan*/  OSSL_PROVIDER ;
typedef  TYPE_1__ OSSL_METHOD_CONSTRUCT_METHOD ;
typedef  TYPE_2__ OSSL_ALGORITHM ;
typedef  int /*<<< orphan*/  OPENSSL_CTX ;

/* Variables and functions */
 int /*<<< orphan*/  ossl_provider_forall_loaded (int /*<<< orphan*/ *,int (*) (int /*<<< orphan*/ *,void*),struct construct_data_st*) ; 
 TYPE_2__* ossl_provider_query_operation (int /*<<< orphan*/ *,int,int*) ; 
 void* stub1 (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,void*) ; 
 int /*<<< orphan*/  stub2 (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,void*,void*) ; 
 int /*<<< orphan*/  stub3 (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,void*,void*) ; 
 int /*<<< orphan*/  stub4 (void*,void*) ; 
 void* stub5 (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char const*,void*) ; 
 int /*<<< orphan*/ * stub6 (int /*<<< orphan*/ *) ; 
 void* stub7 (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char const*,void*) ; 
 int /*<<< orphan*/  stub8 (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int ossl_method_construct_this(OSSL_PROVIDER *provider, void *cbdata)
{
    struct construct_data_st *data = cbdata;
    int no_store = 0;    /* Assume caching is ok */
    const OSSL_ALGORITHM *map =
        ossl_provider_query_operation(provider, data->operation_id, &no_store);

    while (map->algorithm_name != NULL) {
        const OSSL_ALGORITHM *thismap = map++;
        void *method = NULL;

        if ((method = data->mcm->construct(thismap->algorithm_name,
                                           thismap->implementation, provider,
                                           data->mcm_data)) == NULL)
            continue;

        /*
         * Note regarding putting the method in stores:
         *
         * we don't need to care if it actually got in or not here.
         * If it didn't get in, it will simply not be available when
         * ossl_method_construct() tries to get it from the store.
         *
         * It is *expected* that the put function increments the refcnt
         * of the passed method.
         */

        if (data->force_store || !no_store) {
            /*
             * If we haven't been told not to store,
             * add to the global store
             */
            data->mcm->put(data->libctx, NULL,
                           thismap->property_definition,
                           method, data->mcm_data);
        }

        data->mcm->put(data->libctx, data->store,
                       thismap->property_definition,
                       method, data->mcm_data);

        /* refcnt-- because we're dropping the reference */
        data->mcm->destruct(method, data->mcm_data);
    }

    return 1;
}

void *ossl_method_construct(OPENSSL_CTX *libctx, int operation_id,
                            const char *name, const char *propquery,
                            int force_store,
                            OSSL_METHOD_CONSTRUCT_METHOD *mcm, void *mcm_data)
{
    void *method = NULL;

    if ((method = mcm->get(libctx, NULL, propquery, mcm_data)) == NULL) {
        struct construct_data_st cbdata;

        /*
         * We have a temporary store to be able to easily search among new
         * items, or items that should find themselves in the global store.
         */
        if ((cbdata.store = mcm->alloc_tmp_store(libctx)) == NULL)
            goto fin;

        cbdata.libctx = libctx;
        cbdata.operation_id = operation_id;
        cbdata.force_store = force_store;
        cbdata.mcm = mcm;
        cbdata.mcm_data = mcm_data;
        ossl_provider_forall_loaded(libctx, ossl_method_construct_this,
                                    &cbdata);

        method = mcm->get(libctx, cbdata.store, propquery, mcm_data);
        mcm->dealloc_tmp_store(cbdata.store);
    }

 fin:
    return method;
}

