#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_48__   TYPE_5__ ;
typedef  struct TYPE_47__   TYPE_4__ ;
typedef  struct TYPE_46__   TYPE_2__ ;
typedef  struct TYPE_45__   TYPE_1__ ;
typedef  struct TYPE_44__   TYPE_16__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  tsdn_t ;
struct TYPE_45__ {TYPE_2__* root; int /*<<< orphan*/  init_lock; } ;
typedef  TYPE_1__ rtree_t ;
struct TYPE_46__ {int /*<<< orphan*/  child; } ;
typedef  TYPE_2__ rtree_node_elm_t ;
typedef  TYPE_2__ rtree_leaf_elm_t ;
struct TYPE_47__ {TYPE_5__* l2_cache; TYPE_5__* cache; } ;
typedef  TYPE_4__ rtree_ctx_t ;
struct TYPE_48__ {uintptr_t leafkey; TYPE_2__* leaf; } ;
typedef  TYPE_5__ rtree_ctx_cache_elm_t ;
typedef  int /*<<< orphan*/  atomic_p_t ;
struct TYPE_44__ {int bits; } ;

/* Variables and functions */
 int /*<<< orphan*/  ATOMIC_ACQUIRE ; 
 int /*<<< orphan*/  ATOMIC_RELAXED ; 
 int /*<<< orphan*/  ATOMIC_RELEASE ; 
 int /*<<< orphan*/  CACHELINE ; 
 unsigned int RTREE_CTX_NCACHE ; 
 unsigned int RTREE_CTX_NCACHE_L2 ; 
 int RTREE_HEIGHT ; 
 void* RTREE_LEAFKEY_INVALID ; 
 int /*<<< orphan*/  WITNESS_RANK_RTREE ; 
 int ZU (int) ; 
 int /*<<< orphan*/  assert (int) ; 
 TYPE_2__* atomic_load_p (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  atomic_store_p (int /*<<< orphan*/ *,TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  b0get () ; 
 scalar_t__ base_alloc (int /*<<< orphan*/ *,int /*<<< orphan*/ ,size_t,int /*<<< orphan*/ ) ; 
 scalar_t__ config_debug ; 
 scalar_t__ malloc_mutex_init (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  malloc_mutex_lock (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  malloc_mutex_rank_exclusive ; 
 int /*<<< orphan*/  malloc_mutex_unlock (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memmove (TYPE_5__*,TYPE_5__*,int) ; 
 int /*<<< orphan*/  not_reached () ; 
 size_t rtree_cache_direct_map (uintptr_t) ; 
 TYPE_2__* rtree_leaf_alloc (int /*<<< orphan*/ *,TYPE_1__*,int) ; 
 uintptr_t rtree_leafkey (uintptr_t) ; 
 TYPE_16__* rtree_levels ; 
 TYPE_2__* rtree_node_alloc (int /*<<< orphan*/ *,TYPE_1__*,int) ; 
 uintptr_t rtree_subkey (uintptr_t,int) ; 
 scalar_t__ unlikely (int) ; 

bool
rtree_new(rtree_t *rtree, bool zeroed) {
#ifdef JEMALLOC_JET
	if (!zeroed) {
		memset(rtree, 0, sizeof(rtree_t)); /* Clear root. */
	}
#else
	assert(zeroed);
#endif

	if (malloc_mutex_init(&rtree->init_lock, "rtree", WITNESS_RANK_RTREE,
	    malloc_mutex_rank_exclusive)) {
		return true;
	}

	return false;
}

__attribute__((used)) static rtree_node_elm_t *
rtree_node_alloc_impl(tsdn_t *tsdn, rtree_t *rtree, size_t nelms) {
	return (rtree_node_elm_t *)base_alloc(tsdn, b0get(), nelms *
	    sizeof(rtree_node_elm_t), CACHELINE);
}

__attribute__((used)) static void
rtree_node_dalloc_impl(tsdn_t *tsdn, rtree_t *rtree, rtree_node_elm_t *node) {
	/* Nodes are never deleted during normal operation. */
	not_reached();
}

__attribute__((used)) static rtree_leaf_elm_t *
rtree_leaf_alloc_impl(tsdn_t *tsdn, rtree_t *rtree, size_t nelms) {
	return (rtree_leaf_elm_t *)base_alloc(tsdn, b0get(), nelms *
	    sizeof(rtree_leaf_elm_t), CACHELINE);
}

__attribute__((used)) static void
rtree_leaf_dalloc_impl(tsdn_t *tsdn, rtree_t *rtree, rtree_leaf_elm_t *leaf) {
	/* Leaves are never deleted during normal operation. */
	not_reached();
}

__attribute__((used)) static rtree_node_elm_t *
rtree_node_init(tsdn_t *tsdn, rtree_t *rtree, unsigned level,
    atomic_p_t *elmp) {
	malloc_mutex_lock(tsdn, &rtree->init_lock);
	/*
	 * If *elmp is non-null, then it was initialized with the init lock
	 * held, so we can get by with 'relaxed' here.
	 */
	rtree_node_elm_t *node = atomic_load_p(elmp, ATOMIC_RELAXED);
	if (node == NULL) {
		node = rtree_node_alloc(tsdn, rtree, ZU(1) <<
		    rtree_levels[level].bits);
		if (node == NULL) {
			malloc_mutex_unlock(tsdn, &rtree->init_lock);
			return NULL;
		}
		/*
		 * Even though we hold the lock, a later reader might not; we
		 * need release semantics.
		 */
		atomic_store_p(elmp, node, ATOMIC_RELEASE);
	}
	malloc_mutex_unlock(tsdn, &rtree->init_lock);

	return node;
}

__attribute__((used)) static rtree_leaf_elm_t *
rtree_leaf_init(tsdn_t *tsdn, rtree_t *rtree, atomic_p_t *elmp) {
	malloc_mutex_lock(tsdn, &rtree->init_lock);
	/*
	 * If *elmp is non-null, then it was initialized with the init lock
	 * held, so we can get by with 'relaxed' here.
	 */
	rtree_leaf_elm_t *leaf = atomic_load_p(elmp, ATOMIC_RELAXED);
	if (leaf == NULL) {
		leaf = rtree_leaf_alloc(tsdn, rtree, ZU(1) <<
		    rtree_levels[RTREE_HEIGHT-1].bits);
		if (leaf == NULL) {
			malloc_mutex_unlock(tsdn, &rtree->init_lock);
			return NULL;
		}
		/*
		 * Even though we hold the lock, a later reader might not; we
		 * need release semantics.
		 */
		atomic_store_p(elmp, leaf, ATOMIC_RELEASE);
	}
	malloc_mutex_unlock(tsdn, &rtree->init_lock);

	return leaf;
}

__attribute__((used)) static bool
rtree_node_valid(rtree_node_elm_t *node) {
	return ((uintptr_t)node != (uintptr_t)0);
}

__attribute__((used)) static bool
rtree_leaf_valid(rtree_leaf_elm_t *leaf) {
	return ((uintptr_t)leaf != (uintptr_t)0);
}

__attribute__((used)) static rtree_node_elm_t *
rtree_child_node_tryread(rtree_node_elm_t *elm, bool dependent) {
	rtree_node_elm_t *node;

	if (dependent) {
		node = (rtree_node_elm_t *)atomic_load_p(&elm->child,
		    ATOMIC_RELAXED);
	} else {
		node = (rtree_node_elm_t *)atomic_load_p(&elm->child,
		    ATOMIC_ACQUIRE);
	}

	assert(!dependent || node != NULL);
	return node;
}

__attribute__((used)) static rtree_node_elm_t *
rtree_child_node_read(tsdn_t *tsdn, rtree_t *rtree, rtree_node_elm_t *elm,
    unsigned level, bool dependent) {
	rtree_node_elm_t *node;

	node = rtree_child_node_tryread(elm, dependent);
	if (!dependent && unlikely(!rtree_node_valid(node))) {
		node = rtree_node_init(tsdn, rtree, level + 1, &elm->child);
	}
	assert(!dependent || node != NULL);
	return node;
}

__attribute__((used)) static rtree_leaf_elm_t *
rtree_child_leaf_tryread(rtree_node_elm_t *elm, bool dependent) {
	rtree_leaf_elm_t *leaf;

	if (dependent) {
		leaf = (rtree_leaf_elm_t *)atomic_load_p(&elm->child,
		    ATOMIC_RELAXED);
	} else {
		leaf = (rtree_leaf_elm_t *)atomic_load_p(&elm->child,
		    ATOMIC_ACQUIRE);
	}

	assert(!dependent || leaf != NULL);
	return leaf;
}

__attribute__((used)) static rtree_leaf_elm_t *
rtree_child_leaf_read(tsdn_t *tsdn, rtree_t *rtree, rtree_node_elm_t *elm,
    unsigned level, bool dependent) {
	rtree_leaf_elm_t *leaf;

	leaf = rtree_child_leaf_tryread(elm, dependent);
	if (!dependent && unlikely(!rtree_leaf_valid(leaf))) {
		leaf = rtree_leaf_init(tsdn, rtree, &elm->child);
	}
	assert(!dependent || leaf != NULL);
	return leaf;
}

rtree_leaf_elm_t *
rtree_leaf_elm_lookup_hard(tsdn_t *tsdn, rtree_t *rtree, rtree_ctx_t *rtree_ctx,
    uintptr_t key, bool dependent, bool init_missing) {
	rtree_node_elm_t *node;
	rtree_leaf_elm_t *leaf;
#if RTREE_HEIGHT > 1
	node = rtree->root;
#else
	leaf = rtree->root;
#endif

	if (config_debug) {
		uintptr_t leafkey = rtree_leafkey(key);
		for (unsigned i = 0; i < RTREE_CTX_NCACHE; i++) {
			assert(rtree_ctx->cache[i].leafkey != leafkey);
		}
		for (unsigned i = 0; i < RTREE_CTX_NCACHE_L2; i++) {
			assert(rtree_ctx->l2_cache[i].leafkey != leafkey);
		}
	}

#define RTREE_GET_CHILD(level) {					\
		assert(level < RTREE_HEIGHT-1);				\
		if (level != 0 && !dependent &&				\
		    unlikely(!rtree_node_valid(node))) {		\
			return NULL;					\
		}							\
		uintptr_t subkey = rtree_subkey(key, level);		\
		if (level + 2 < RTREE_HEIGHT) {				\
			node = init_missing ?				\
			    rtree_child_node_read(tsdn, rtree,		\
			    &node[subkey], level, dependent) :		\
			    rtree_child_node_tryread(&node[subkey],	\
			    dependent);					\
		} else {						\
			leaf = init_missing ?				\
			    rtree_child_leaf_read(tsdn, rtree,		\
			    &node[subkey], level, dependent) :		\
			    rtree_child_leaf_tryread(&node[subkey],	\
			    dependent);					\
		}							\
	}
	/*
	 * Cache replacement upon hard lookup (i.e. L1 & L2 rtree cache miss):
	 * (1) evict last entry in L2 cache; (2) move the collision slot from L1
	 * cache down to L2; and 3) fill L1.
	 */
#define RTREE_GET_LEAF(level) {						\
		assert(level == RTREE_HEIGHT-1);			\
		if (!dependent && unlikely(!rtree_leaf_valid(leaf))) {	\
			return NULL;					\
		}							\
		if (RTREE_CTX_NCACHE_L2 > 1) {				\
			memmove(&rtree_ctx->l2_cache[1],		\
			    &rtree_ctx->l2_cache[0],			\
			    sizeof(rtree_ctx_cache_elm_t) *		\
			    (RTREE_CTX_NCACHE_L2 - 1));			\
		}							\
		size_t slot = rtree_cache_direct_map(key);		\
		rtree_ctx->l2_cache[0].leafkey =			\
		    rtree_ctx->cache[slot].leafkey;			\
		rtree_ctx->l2_cache[0].leaf =				\
		    rtree_ctx->cache[slot].leaf;			\
		uintptr_t leafkey = rtree_leafkey(key);			\
		rtree_ctx->cache[slot].leafkey = leafkey;		\
		rtree_ctx->cache[slot].leaf = leaf;			\
		uintptr_t subkey = rtree_subkey(key, level);		\
		return &leaf[subkey];					\
	}
	if (RTREE_HEIGHT > 1) {
		RTREE_GET_CHILD(0)
	}
	if (RTREE_HEIGHT > 2) {
		RTREE_GET_CHILD(1)
	}
	if (RTREE_HEIGHT > 3) {
		for (unsigned i = 2; i < RTREE_HEIGHT-1; i++) {
			RTREE_GET_CHILD(i)
		}
	}
	RTREE_GET_LEAF(RTREE_HEIGHT-1)
#undef RTREE_GET_CHILD
#undef RTREE_GET_LEAF
	not_reached();
}

void
rtree_ctx_data_init(rtree_ctx_t *ctx) {
	for (unsigned i = 0; i < RTREE_CTX_NCACHE; i++) {
		rtree_ctx_cache_elm_t *cache = &ctx->cache[i];
		cache->leafkey = RTREE_LEAFKEY_INVALID;
		cache->leaf = NULL;
	}
	for (unsigned i = 0; i < RTREE_CTX_NCACHE_L2; i++) {
		rtree_ctx_cache_elm_t *cache = &ctx->l2_cache[i];
		cache->leafkey = RTREE_LEAFKEY_INVALID;
		cache->leaf = NULL;
	}
}

