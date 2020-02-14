#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_65__   TYPE_3__ ;
typedef  struct TYPE_64__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  ossl_uintmax_t ;
struct TYPE_65__ {scalar_t__ nelem; TYPE_1__* store; int /*<<< orphan*/ * cache; } ;
struct TYPE_64__ {char const* query; void (* method_destruct ) (void const*) ;void const* method; int nid; scalar_t__ nelem; int nbits; int* rand_bits; int need_flush; char const* body; int /*<<< orphan*/ * cache; struct TYPE_64__* algs; int /*<<< orphan*/ * global_properties; int /*<<< orphan*/ * ctx; int /*<<< orphan*/ * properties; int /*<<< orphan*/ * impls; int /*<<< orphan*/ * lock; } ;
typedef  TYPE_1__ QUERY ;
typedef  int /*<<< orphan*/  OSSL_PROPERTY_LIST ;
typedef  TYPE_1__ OSSL_METHOD_STORE ;
typedef  int /*<<< orphan*/  OPENSSL_CTX ;
typedef  TYPE_3__ IMPL_CACHE_FLUSH ;
typedef  TYPE_1__ IMPLEMENTATION ;
typedef  TYPE_1__ ALGORITHM ;

/* Variables and functions */
 int /*<<< orphan*/  CRYPTO_THREAD_lock_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * CRYPTO_THREAD_lock_new () ; 
 int CRYPTO_THREAD_read_lock (int /*<<< orphan*/ *) ; 
 int CRYPTO_THREAD_unlock (int /*<<< orphan*/ *) ; 
 int CRYPTO_THREAD_write_lock (int /*<<< orphan*/ *) ; 
 scalar_t__ IMPL_CACHE_FLUSH_THRESHOLD ; 
 int /*<<< orphan*/  OPENSSL_CTX_METHOD_STORE_RUN_ONCE_INDEX ; 
 unsigned long OPENSSL_LH_strhash (char const*) ; 
 int /*<<< orphan*/  OPENSSL_free (TYPE_1__*) ; 
 TYPE_1__* OPENSSL_malloc (int) ; 
 TYPE_1__* OPENSSL_zalloc (int) ; 
 int /*<<< orphan*/  RAND_bytes (int*,int) ; 
 TYPE_1__* lh_QUERY_delete (int /*<<< orphan*/ *,TYPE_1__*) ; 
 int /*<<< orphan*/  lh_QUERY_doall (int /*<<< orphan*/ *,void (*) (TYPE_1__*)) ; 
 int /*<<< orphan*/  lh_QUERY_doall_IMPL_CACHE_FLUSH (int /*<<< orphan*/ *,void (*) (TYPE_1__*,TYPE_3__*),TYPE_3__*) ; 
 int /*<<< orphan*/  lh_QUERY_error (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lh_QUERY_flush (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lh_QUERY_free (int /*<<< orphan*/ *) ; 
 TYPE_1__* lh_QUERY_insert (int /*<<< orphan*/ *,TYPE_1__*) ; 
 int /*<<< orphan*/ * lh_QUERY_new (unsigned long (*) (TYPE_1__ const*),int (*) (TYPE_1__ const*,TYPE_1__ const*)) ; 
 scalar_t__ lh_QUERY_num_items (int /*<<< orphan*/ *) ; 
 TYPE_1__* lh_QUERY_retrieve (int /*<<< orphan*/ *,TYPE_1__*) ; 
 int /*<<< orphan*/  memcpy (char*,char const*,size_t) ; 
 int /*<<< orphan*/  openssl_ctx_run_once (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int (*) (int /*<<< orphan*/ *)) ; 
static  void ossl_method_cache_flush (TYPE_1__*,int) ; 
static  void ossl_method_cache_flush_all (TYPE_1__*) ; 
 int /*<<< orphan*/ * ossl_parse_property (int /*<<< orphan*/ *,char const*) ; 
 void* ossl_parse_query (int /*<<< orphan*/ *,char const*) ; 
 int /*<<< orphan*/ * ossl_prop_defn_get (int /*<<< orphan*/ *,char const*) ; 
 int /*<<< orphan*/  ossl_prop_defn_set (int /*<<< orphan*/ *,char const*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ossl_property_free (int /*<<< orphan*/ *) ; 
 scalar_t__ ossl_property_match (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * ossl_property_merge (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int ossl_property_parse_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ossl_sa_ALGORITHM_doall (TYPE_1__*,void (*) (int /*<<< orphan*/ ,TYPE_1__*)) ; 
 int /*<<< orphan*/  ossl_sa_ALGORITHM_doall_arg (TYPE_1__*,void (*) (int /*<<< orphan*/ ,TYPE_1__*,void*),TYPE_3__*) ; 
 int /*<<< orphan*/  ossl_sa_ALGORITHM_free (TYPE_1__*) ; 
 TYPE_1__* ossl_sa_ALGORITHM_get (TYPE_1__*,int) ; 
 TYPE_1__* ossl_sa_ALGORITHM_new () ; 
 int ossl_sa_ALGORITHM_set (TYPE_1__*,int,TYPE_1__*) ; 
 int /*<<< orphan*/  sk_IMPLEMENTATION_delete (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/ * sk_IMPLEMENTATION_new_null () ; 
 int sk_IMPLEMENTATION_num (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sk_IMPLEMENTATION_pop_free (int /*<<< orphan*/ *,void (*) (TYPE_1__*)) ; 
 scalar_t__ sk_IMPLEMENTATION_push (int /*<<< orphan*/ *,TYPE_1__*) ; 
 TYPE_1__* sk_IMPLEMENTATION_value (int /*<<< orphan*/ *,int) ; 
 int strcmp (char const*,char const*) ; 
 size_t strlen (char const*) ; 
 void stub1 (void const*) ; 

int ossl_property_read_lock(OSSL_METHOD_STORE *p)
{
    return p != NULL ? CRYPTO_THREAD_read_lock(p->lock) : 0;
}

int ossl_property_write_lock(OSSL_METHOD_STORE *p)
{
    return p != NULL ? CRYPTO_THREAD_write_lock(p->lock) : 0;
}

int ossl_property_unlock(OSSL_METHOD_STORE *p)
{
    return p != 0 ? CRYPTO_THREAD_unlock(p->lock) : 0;
}

int do_method_store_init(OPENSSL_CTX *ctx)
{
    return ossl_property_parse_init(ctx);
}

__attribute__((used)) static unsigned long query_hash(const QUERY *a)
{
    return OPENSSL_LH_strhash(a->query);
}

__attribute__((used)) static int query_cmp(const QUERY *a, const QUERY *b)
{
    return strcmp(a->query, b->query);
}

__attribute__((used)) static void impl_free(IMPLEMENTATION *impl)
{
    if (impl != NULL) {
        if (impl->method_destruct)
            impl->method_destruct(impl->method);
        OPENSSL_free(impl);
    }
}

__attribute__((used)) static void impl_cache_free(QUERY *elem)
{
    OPENSSL_free(elem);
}

__attribute__((used)) static void alg_cleanup(ossl_uintmax_t idx, ALGORITHM *a)
{
    if (a != NULL) {
        sk_IMPLEMENTATION_pop_free(a->impls, &impl_free);
        lh_QUERY_doall(a->cache, &impl_cache_free);
        lh_QUERY_free(a->cache);
        OPENSSL_free(a);
    }
}

OSSL_METHOD_STORE *ossl_method_store_new(OPENSSL_CTX *ctx)
{
    OSSL_METHOD_STORE *res;

    if (!openssl_ctx_run_once(ctx,
                              OPENSSL_CTX_METHOD_STORE_RUN_ONCE_INDEX,
                              do_method_store_init))
        return NULL;

    res = OPENSSL_zalloc(sizeof(*res));
    if (res != NULL) {
        res->ctx = ctx;
        if ((res->algs = ossl_sa_ALGORITHM_new()) == NULL) {
            OPENSSL_free(res);
            return NULL;
        }
        if ((res->lock = CRYPTO_THREAD_lock_new()) == NULL) {
            OPENSSL_free(res->algs);
            OPENSSL_free(res);
            return NULL;
        }
    }
    return res;
}

void ossl_method_store_free(OSSL_METHOD_STORE *store)
{
    if (store != NULL) {
        ossl_sa_ALGORITHM_doall(store->algs, &alg_cleanup);
        ossl_sa_ALGORITHM_free(store->algs);
        ossl_property_free(store->global_properties);
        CRYPTO_THREAD_lock_free(store->lock);
        OPENSSL_free(store);
    }
}

__attribute__((used)) static ALGORITHM *ossl_method_store_retrieve(OSSL_METHOD_STORE *store, int nid)
{
    return ossl_sa_ALGORITHM_get(store->algs, nid);
}

__attribute__((used)) static int ossl_method_store_insert(OSSL_METHOD_STORE *store, ALGORITHM *alg)
{
        return ossl_sa_ALGORITHM_set(store->algs, alg->nid, alg);
}

int ossl_method_store_add(OSSL_METHOD_STORE *store,
                          int nid, const char *properties,
                          void *method, void (*method_destruct)(void *))
{
    ALGORITHM *alg = NULL;
    IMPLEMENTATION *impl;
    int ret = 0;

    if (nid <= 0 || method == NULL || store == NULL)
        return 0;
    if (properties == NULL)
        properties = "";

    /* Create new entry */
    impl = OPENSSL_malloc(sizeof(*impl));
    if (impl == NULL)
        return 0;
    impl->method = method;
    impl->method_destruct = method_destruct;

    /*
     * Insert into the hash table if required.
     *
     * A write lock is used unconditionally because we wend our way down to the
     * property string code which isn't locking friendly.
     */
    ossl_property_write_lock(store);
    ossl_method_cache_flush(store, nid);
    if ((impl->properties = ossl_prop_defn_get(store->ctx, properties)) == NULL) {
        impl->properties = ossl_parse_property(store->ctx, properties);
        if (impl->properties == NULL)
            goto err;
        ossl_prop_defn_set(store->ctx, properties, impl->properties);
    }

    alg = ossl_method_store_retrieve(store, nid);
    if (alg == NULL) {
        if ((alg = OPENSSL_zalloc(sizeof(*alg))) == NULL
                || (alg->impls = sk_IMPLEMENTATION_new_null()) == NULL
                || (alg->cache = lh_QUERY_new(&query_hash, &query_cmp)) == NULL)
            goto err;
        alg->nid = nid;
        if (!ossl_method_store_insert(store, alg))
            goto err;
    }

    /* Push onto stack */
    if (sk_IMPLEMENTATION_push(alg->impls, impl))
        ret = 1;
    ossl_property_unlock(store);
    if (ret == 0)
        impl_free(impl);
    return ret;

err:
    ossl_property_unlock(store);
    alg_cleanup(0, alg);
    impl_free(impl);
    return 0;
}

int ossl_method_store_remove(OSSL_METHOD_STORE *store, int nid,
                             const void *method)
{
    ALGORITHM *alg = NULL;
    int i;

    if (nid <= 0 || method == NULL || store == NULL)
        return 0;

    ossl_property_write_lock(store);
    ossl_method_cache_flush(store, nid);
    alg = ossl_method_store_retrieve(store, nid);
    if (alg == NULL) {
        ossl_property_unlock(store);
        return 0;
    }

    /*
     * A sorting find then a delete could be faster but these stacks should be
     * relatively small, so we avoid the overhead.  Sorting could also surprise
     * users when result orderings change (even though they are not guaranteed).
     */
    for (i = 0; i < sk_IMPLEMENTATION_num(alg->impls); i++) {
        IMPLEMENTATION *impl = sk_IMPLEMENTATION_value(alg->impls, i);

        if (impl->method == method) {
            sk_IMPLEMENTATION_delete(alg->impls, i);
            ossl_property_unlock(store);
            impl_free(impl);
            return 1;
        }
    }
    ossl_property_unlock(store);
    return 0;
}

int ossl_method_store_fetch(OSSL_METHOD_STORE *store, int nid,
                            const char *prop_query, void **method)
{
    ALGORITHM *alg;
    IMPLEMENTATION *impl;
    OSSL_PROPERTY_LIST *pq = NULL, *p2;
    int ret = 0;
    int j;

    if (nid <= 0 || method == NULL || store == NULL)
        return 0;

    /*
     * This only needs to be a read lock, because queries never create property
     * names or value and thus don't modify any of the property string layer.
     */
    ossl_property_read_lock(store);
    alg = ossl_method_store_retrieve(store, nid);
    if (alg == NULL) {
        ossl_property_unlock(store);
        return 0;
    }

    if (prop_query == NULL) {
        if ((impl = sk_IMPLEMENTATION_value(alg->impls, 0)) != NULL) {
            *method = impl->method;
            ret = 1;
        }
        goto fin;
    }
    pq = ossl_parse_query(store->ctx, prop_query);
    if (pq == NULL)
        goto fin;
    if (store->global_properties != NULL) {
        p2 = ossl_property_merge(pq, store->global_properties);
        if (p2 == NULL)
            goto fin;
        ossl_property_free(pq);
        pq = p2;
    }
    for (j = 0; j < sk_IMPLEMENTATION_num(alg->impls); j++) {
        impl = sk_IMPLEMENTATION_value(alg->impls, j);

        if (ossl_property_match(pq, impl->properties)) {
            *method = impl->method;
            ret = 1;
            goto fin;
        }
    }
fin:
    ossl_property_unlock(store);
    ossl_property_free(pq);
    return ret;
}

int ossl_method_store_set_global_properties(OSSL_METHOD_STORE *store,
                                            const char *prop_query) {
    int ret = 0;

    if (store == NULL)
        return 1;

    ossl_property_write_lock(store);
    ossl_method_cache_flush_all(store);
    if (prop_query == NULL) {
        ossl_property_free(store->global_properties);
        store->global_properties = NULL;
        ossl_property_unlock(store);
        return 1;
    }
    store->global_properties = ossl_parse_query(store->ctx, prop_query);
    ret = store->global_properties != NULL;
    ossl_property_unlock(store);
    return ret;
}

__attribute__((used)) static void impl_cache_flush_alg(ossl_uintmax_t idx, ALGORITHM *alg)
{
    lh_QUERY_doall(alg->cache, &impl_cache_free);
    lh_QUERY_flush(alg->cache);
}

__attribute__((used)) static void ossl_method_cache_flush(OSSL_METHOD_STORE *store, int nid)
{
    ALGORITHM *alg = ossl_method_store_retrieve(store, nid);

    if (alg != NULL) {
        store->nelem -= lh_QUERY_num_items(alg->cache);
        impl_cache_flush_alg(0, alg);
    }
}

__attribute__((used)) static void ossl_method_cache_flush_all(OSSL_METHOD_STORE *store)
{
    ossl_sa_ALGORITHM_doall(store->algs, &impl_cache_flush_alg);
    store->nelem = 0;
}

__attribute__((used)) static void impl_cache_flush_cache(QUERY *c, IMPL_CACHE_FLUSH *state)
{
    OSSL_METHOD_STORE *store = state->store;
    unsigned int n;

    if (store->nbits == 0) {
        if (!RAND_bytes(store->rand_bits, sizeof(store->rand_bits)))
            return;
        store->nbits = sizeof(store->rand_bits) * 8;
    }
    n = --store->nbits;
    if ((store->rand_bits[n >> 3] & (1 << (n & 7))) != 0)
        OPENSSL_free(lh_QUERY_delete(state->cache, c));
    else
        state->nelem++;
}

__attribute__((used)) static void impl_cache_flush_one_alg(ossl_uintmax_t idx, ALGORITHM *alg,
                                     void *v)
{
    IMPL_CACHE_FLUSH *state = (IMPL_CACHE_FLUSH *)v;

    state->cache = alg->cache;
    lh_QUERY_doall_IMPL_CACHE_FLUSH(state->cache, &impl_cache_flush_cache,
                                    state);
}

__attribute__((used)) static void ossl_method_cache_flush_some(OSSL_METHOD_STORE *store)
{
    IMPL_CACHE_FLUSH state;

    state.nelem = 0;
    state.store = store;
    ossl_sa_ALGORITHM_doall_arg(store->algs, &impl_cache_flush_one_alg, &state);
    store->need_flush = 0;
    store->nelem = state.nelem;
}

int ossl_method_store_cache_get(OSSL_METHOD_STORE *store, int nid,
                                const char *prop_query, void **method)
{
    ALGORITHM *alg;
    QUERY elem, *r;

    if (nid <= 0 || store == NULL)
        return 0;

    ossl_property_read_lock(store);
    alg = ossl_method_store_retrieve(store, nid);
    if (alg == NULL) {
        ossl_property_unlock(store);
        return 0;
    }

    elem.query = prop_query != NULL ? prop_query : "";
    r = lh_QUERY_retrieve(alg->cache, &elem);
    if (r == NULL) {
        ossl_property_unlock(store);
        return 0;
    }
    *method = r->method;
    ossl_property_unlock(store);
    return 1;
}

int ossl_method_store_cache_set(OSSL_METHOD_STORE *store, int nid,
                                const char *prop_query, void *method)
{
    QUERY elem, *old, *p = NULL;
    ALGORITHM *alg;
    size_t len;

    if (nid <= 0 || store == NULL)
        return 0;
    if (prop_query == NULL)
        return 1;

    ossl_property_write_lock(store);
    if (store->need_flush)
        ossl_method_cache_flush_some(store);
    alg = ossl_method_store_retrieve(store, nid);
    if (alg == NULL) {
        ossl_property_unlock(store);
        return 0;
    }

    if (method == NULL) {
        elem.query = prop_query;
        lh_QUERY_delete(alg->cache, &elem);
        ossl_property_unlock(store);
        return 1;
    }
    p = OPENSSL_malloc(sizeof(*p) + (len = strlen(prop_query)));
    if (p != NULL) {
        p->query = p->body;
        p->method = method;
        memcpy((char *)p->query, prop_query, len + 1);
        if ((old = lh_QUERY_insert(alg->cache, p)) != NULL)
            OPENSSL_free(old);
        if (old != NULL || !lh_QUERY_error(alg->cache)) {
            store->nelem++;
            if (store->nelem >= IMPL_CACHE_FLUSH_THRESHOLD)
                store->need_flush = 1;
            ossl_property_unlock(store);
            return 1;
        }
    }
    ossl_property_unlock(store);
    OPENSSL_free(p);
    return 0;
}

