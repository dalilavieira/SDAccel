#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_24__   TYPE_2__ ;
typedef  struct TYPE_23__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  tsd_t ;
typedef  int /*<<< orphan*/  tcache_t ;
typedef  int /*<<< orphan*/  prof_tctx_t ;
typedef  int /*<<< orphan*/  extent_node_t ;
struct TYPE_23__ {scalar_t__ (* split ) (void*,scalar_t__,scalar_t__,size_t,int,int /*<<< orphan*/ ) ;} ;
typedef  TYPE_1__ chunk_hooks_t ;
struct TYPE_24__ {int /*<<< orphan*/  huge_mtx; int /*<<< orphan*/  huge; int /*<<< orphan*/  ind; } ;
typedef  TYPE_2__ arena_t ;

/* Variables and functions */
 int /*<<< orphan*/  CACHELINE ; 
 int /*<<< orphan*/  CACHELINE_CEILING (int) ; 
 void* CHUNK_ADDR2BASE (uintptr_t) ; 
 size_t CHUNK_ADDR2OFFSET (uintptr_t) ; 
 scalar_t__ CHUNK_CEILING (size_t) ; 
 TYPE_1__ CHUNK_HOOKS_INITIALIZER ; 
 TYPE_2__* arena_choose (int /*<<< orphan*/ *,TYPE_2__*) ; 
 void* arena_chunk_alloc_huge (TYPE_2__*,size_t,size_t,int*) ; 
 int /*<<< orphan*/  arena_chunk_dalloc_huge (TYPE_2__*,void*,size_t) ; 
 scalar_t__ arena_chunk_ralloc_huge_expand (TYPE_2__*,void*,size_t,size_t,int*) ; 
 int /*<<< orphan*/  arena_chunk_ralloc_huge_shrink (TYPE_2__*,void*,size_t,size_t) ; 
 int /*<<< orphan*/  arena_chunk_ralloc_huge_similar (TYPE_2__*,void*,size_t,size_t) ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  chunk_deregister (void const*,int /*<<< orphan*/  const*) ; 
 TYPE_1__ chunk_hooks_get (TYPE_2__*) ; 
 scalar_t__ chunk_in_dss (void*) ; 
 int /*<<< orphan*/ * chunk_lookup (void const*,int) ; 
 int /*<<< orphan*/  chunk_purge_wrapper (TYPE_2__*,TYPE_1__*,void*,scalar_t__,size_t,size_t) ; 
 int chunk_register (void const*,int /*<<< orphan*/ *) ; 
 size_t chunksize ; 
 scalar_t__ config_fill ; 
 int /*<<< orphan*/  config_munmap ; 
 int /*<<< orphan*/  extent_node_achunk_get (int /*<<< orphan*/ *) ; 
 void* extent_node_addr_get (int /*<<< orphan*/ *) ; 
 TYPE_2__* extent_node_arena_get (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  extent_node_init (int /*<<< orphan*/ *,TYPE_2__*,void*,size_t,int,int) ; 
 int /*<<< orphan*/ * extent_node_prof_tctx_get (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  extent_node_prof_tctx_set (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 size_t extent_node_size_get (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  extent_node_size_set (int /*<<< orphan*/ *,size_t) ; 
 int extent_node_zeroed_get (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  extent_node_zeroed_set (int /*<<< orphan*/ *,int) ; 
 scalar_t__ have_dss ; 
 void* huge_palloc (int /*<<< orphan*/ *,TYPE_2__*,size_t,size_t,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  idalloctm (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/ * ipallocztm (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,int,TYPE_2__*) ; 
 int /*<<< orphan*/  isqalloc (int /*<<< orphan*/ *,void*,size_t,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  malloc_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  malloc_mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memcpy (void*,void*,size_t) ; 
 int /*<<< orphan*/  memset (void*,int,size_t) ; 
 int opt_junk_alloc ; 
 int opt_junk_free ; 
 int opt_zero ; 
 int /*<<< orphan*/  ql_elm_new (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ql_link ; 
 int /*<<< orphan*/  ql_remove (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ql_tail_insert (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 size_t s2u (size_t) ; 
 size_t sa2u (size_t,size_t) ; 
 scalar_t__ stub1 (void*,scalar_t__,scalar_t__,size_t,int,int /*<<< orphan*/ ) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static extent_node_t *
huge_node_get(const void *ptr)
{
	extent_node_t *node;

	node = chunk_lookup(ptr, true);
	assert(!extent_node_achunk_get(node));

	return (node);
}

__attribute__((used)) static bool
huge_node_set(const void *ptr, extent_node_t *node)
{

	assert(extent_node_addr_get(node) == ptr);
	assert(!extent_node_achunk_get(node));
	return (chunk_register(ptr, node));
}

__attribute__((used)) static void
huge_node_unset(const void *ptr, const extent_node_t *node)
{

	chunk_deregister(ptr, node);
}

void *
huge_malloc(tsd_t *tsd, arena_t *arena, size_t size, bool zero,
    tcache_t *tcache)
{
	size_t usize;

	usize = s2u(size);
	if (usize == 0) {
		/* size_t overflow. */
		return (NULL);
	}

	return (huge_palloc(tsd, arena, usize, chunksize, zero, tcache));
}

void *
huge_palloc(tsd_t *tsd, arena_t *arena, size_t size, size_t alignment,
    bool zero, tcache_t *tcache)
{
	void *ret;
	size_t usize;
	extent_node_t *node;
	bool is_zeroed;

	/* Allocate one or more contiguous chunks for this request. */

	usize = sa2u(size, alignment);
	if (unlikely(usize == 0))
		return (NULL);
	assert(usize >= chunksize);

	/* Allocate an extent node with which to track the chunk. */
	node = ipallocztm(tsd, CACHELINE_CEILING(sizeof(extent_node_t)),
	    CACHELINE, false, tcache, true, arena);
	if (node == NULL)
		return (NULL);

	/*
	 * Copy zero into is_zeroed and pass the copy to chunk_alloc(), so that
	 * it is possible to make correct junk/zero fill decisions below.
	 */
	is_zeroed = zero;
	arena = arena_choose(tsd, arena);
	if (unlikely(arena == NULL) || (ret = arena_chunk_alloc_huge(arena,
	    size, alignment, &is_zeroed)) == NULL) {
		idalloctm(tsd, node, tcache, true);
		return (NULL);
	}

	extent_node_init(node, arena, ret, size, is_zeroed, true);

	if (huge_node_set(ret, node)) {
		arena_chunk_dalloc_huge(arena, ret, size);
		idalloctm(tsd, node, tcache, true);
		return (NULL);
	}

	/* Insert node into huge. */
	malloc_mutex_lock(&arena->huge_mtx);
	ql_elm_new(node, ql_link);
	ql_tail_insert(&arena->huge, node, ql_link);
	malloc_mutex_unlock(&arena->huge_mtx);

	if (zero || (config_fill && unlikely(opt_zero))) {
		if (!is_zeroed)
			memset(ret, 0, size);
	} else if (config_fill && unlikely(opt_junk_alloc))
		memset(ret, 0xa5, size);

	return (ret);
}

__attribute__((used)) static void
huge_dalloc_junk(void *ptr, size_t usize)
{

	if (config_fill && have_dss && unlikely(opt_junk_free)) {
		/*
		 * Only bother junk filling if the chunk isn't about to be
		 * unmapped.
		 */
		if (!config_munmap || (have_dss && chunk_in_dss(ptr)))
			memset(ptr, 0x5a, usize);
	}
}

__attribute__((used)) static void
huge_ralloc_no_move_similar(void *ptr, size_t oldsize, size_t usize_min,
    size_t usize_max, bool zero)
{
	size_t usize, usize_next;
	extent_node_t *node;
	arena_t *arena;
	chunk_hooks_t chunk_hooks = CHUNK_HOOKS_INITIALIZER;
	bool pre_zeroed, post_zeroed;

	/* Increase usize to incorporate extra. */
	for (usize = usize_min; usize < usize_max && (usize_next = s2u(usize+1))
	    <= oldsize; usize = usize_next)
		; /* Do nothing. */

	if (oldsize == usize)
		return;

	node = huge_node_get(ptr);
	arena = extent_node_arena_get(node);
	pre_zeroed = extent_node_zeroed_get(node);

	/* Fill if necessary (shrinking). */
	if (oldsize > usize) {
		size_t sdiff = oldsize - usize;
		if (config_fill && unlikely(opt_junk_free)) {
			memset((void *)((uintptr_t)ptr + usize), 0x5a, sdiff);
			post_zeroed = false;
		} else {
			post_zeroed = !chunk_purge_wrapper(arena, &chunk_hooks,
			    ptr, CHUNK_CEILING(oldsize), usize, sdiff);
		}
	} else
		post_zeroed = pre_zeroed;

	malloc_mutex_lock(&arena->huge_mtx);
	/* Update the size of the huge allocation. */
	assert(extent_node_size_get(node) != usize);
	extent_node_size_set(node, usize);
	/* Update zeroed. */
	extent_node_zeroed_set(node, post_zeroed);
	malloc_mutex_unlock(&arena->huge_mtx);

	arena_chunk_ralloc_huge_similar(arena, ptr, oldsize, usize);

	/* Fill if necessary (growing). */
	if (oldsize < usize) {
		if (zero || (config_fill && unlikely(opt_zero))) {
			if (!pre_zeroed) {
				memset((void *)((uintptr_t)ptr + oldsize), 0,
				    usize - oldsize);
			}
		} else if (config_fill && unlikely(opt_junk_alloc)) {
			memset((void *)((uintptr_t)ptr + oldsize), 0xa5, usize -
			    oldsize);
		}
	}
}

__attribute__((used)) static bool
huge_ralloc_no_move_shrink(void *ptr, size_t oldsize, size_t usize)
{
	extent_node_t *node;
	arena_t *arena;
	chunk_hooks_t chunk_hooks;
	size_t cdiff;
	bool pre_zeroed, post_zeroed;

	node = huge_node_get(ptr);
	arena = extent_node_arena_get(node);
	pre_zeroed = extent_node_zeroed_get(node);
	chunk_hooks = chunk_hooks_get(arena);

	assert(oldsize > usize);

	/* Split excess chunks. */
	cdiff = CHUNK_CEILING(oldsize) - CHUNK_CEILING(usize);
	if (cdiff != 0 && chunk_hooks.split(ptr, CHUNK_CEILING(oldsize),
	    CHUNK_CEILING(usize), cdiff, true, arena->ind))
		return (true);

	if (oldsize > usize) {
		size_t sdiff = oldsize - usize;
		if (config_fill && unlikely(opt_junk_free)) {
			huge_dalloc_junk((void *)((uintptr_t)ptr + usize),
			    sdiff);
			post_zeroed = false;
		} else {
			post_zeroed = !chunk_purge_wrapper(arena, &chunk_hooks,
			    CHUNK_ADDR2BASE((uintptr_t)ptr + usize),
			    CHUNK_CEILING(oldsize),
			    CHUNK_ADDR2OFFSET((uintptr_t)ptr + usize), sdiff);
		}
	} else
		post_zeroed = pre_zeroed;

	malloc_mutex_lock(&arena->huge_mtx);
	/* Update the size of the huge allocation. */
	extent_node_size_set(node, usize);
	/* Update zeroed. */
	extent_node_zeroed_set(node, post_zeroed);
	malloc_mutex_unlock(&arena->huge_mtx);

	/* Zap the excess chunks. */
	arena_chunk_ralloc_huge_shrink(arena, ptr, oldsize, usize);

	return (false);
}

__attribute__((used)) static bool
huge_ralloc_no_move_expand(void *ptr, size_t oldsize, size_t usize, bool zero) {
	extent_node_t *node;
	arena_t *arena;
	bool is_zeroed_subchunk, is_zeroed_chunk;

	node = huge_node_get(ptr);
	arena = extent_node_arena_get(node);
	malloc_mutex_lock(&arena->huge_mtx);
	is_zeroed_subchunk = extent_node_zeroed_get(node);
	malloc_mutex_unlock(&arena->huge_mtx);

	/*
	 * Copy zero into is_zeroed_chunk and pass the copy to chunk_alloc(), so
	 * that it is possible to make correct junk/zero fill decisions below.
	 */
	is_zeroed_chunk = zero;

	if (arena_chunk_ralloc_huge_expand(arena, ptr, oldsize, usize,
	     &is_zeroed_chunk))
		return (true);

	malloc_mutex_lock(&arena->huge_mtx);
	/* Update the size of the huge allocation. */
	extent_node_size_set(node, usize);
	malloc_mutex_unlock(&arena->huge_mtx);

	if (zero || (config_fill && unlikely(opt_zero))) {
		if (!is_zeroed_subchunk) {
			memset((void *)((uintptr_t)ptr + oldsize), 0,
			    CHUNK_CEILING(oldsize) - oldsize);
		}
		if (!is_zeroed_chunk) {
			memset((void *)((uintptr_t)ptr +
			    CHUNK_CEILING(oldsize)), 0, usize -
			    CHUNK_CEILING(oldsize));
		}
	} else if (config_fill && unlikely(opt_junk_alloc)) {
		memset((void *)((uintptr_t)ptr + oldsize), 0xa5, usize -
		    oldsize);
	}

	return (false);
}

bool
huge_ralloc_no_move(void *ptr, size_t oldsize, size_t usize_min,
    size_t usize_max, bool zero)
{

	assert(s2u(oldsize) == oldsize);

	/* Both allocations must be huge to avoid a move. */
	if (oldsize < chunksize || usize_max < chunksize)
		return (true);

	if (CHUNK_CEILING(usize_max) > CHUNK_CEILING(oldsize)) {
		/* Attempt to expand the allocation in-place. */
		if (!huge_ralloc_no_move_expand(ptr, oldsize, usize_max, zero))
			return (false);
		/* Try again, this time with usize_min. */
		if (usize_min < usize_max && CHUNK_CEILING(usize_min) >
		    CHUNK_CEILING(oldsize) && huge_ralloc_no_move_expand(ptr,
		    oldsize, usize_min, zero))
			return (false);
	}

	/*
	 * Avoid moving the allocation if the existing chunk size accommodates
	 * the new size.
	 */
	if (CHUNK_CEILING(oldsize) >= CHUNK_CEILING(usize_min)
	    && CHUNK_CEILING(oldsize) <= CHUNK_CEILING(usize_max)) {
		huge_ralloc_no_move_similar(ptr, oldsize, usize_min, usize_max,
		    zero);
		return (false);
	}

	/* Attempt to shrink the allocation in-place. */
	if (CHUNK_CEILING(oldsize) > CHUNK_CEILING(usize_max))
		return (huge_ralloc_no_move_shrink(ptr, oldsize, usize_max));
	return (true);
}

__attribute__((used)) static void *
huge_ralloc_move_helper(tsd_t *tsd, arena_t *arena, size_t usize,
    size_t alignment, bool zero, tcache_t *tcache)
{

	if (alignment <= chunksize)
		return (huge_malloc(tsd, arena, usize, zero, tcache));
	return (huge_palloc(tsd, arena, usize, alignment, zero, tcache));
}

void *
huge_ralloc(tsd_t *tsd, arena_t *arena, void *ptr, size_t oldsize, size_t usize,
    size_t alignment, bool zero, tcache_t *tcache)
{
	void *ret;
	size_t copysize;

	/* Try to avoid moving the allocation. */
	if (!huge_ralloc_no_move(ptr, oldsize, usize, usize, zero))
		return (ptr);

	/*
	 * usize and oldsize are different enough that we need to use a
	 * different size class.  In that case, fall back to allocating new
	 * space and copying.
	 */
	ret = huge_ralloc_move_helper(tsd, arena, usize, alignment, zero,
	    tcache);
	if (ret == NULL)
		return (NULL);

	copysize = (usize < oldsize) ? usize : oldsize;
	memcpy(ret, ptr, copysize);
	isqalloc(tsd, ptr, oldsize, tcache);
	return (ret);
}

void
huge_dalloc(tsd_t *tsd, void *ptr, tcache_t *tcache)
{
	extent_node_t *node;
	arena_t *arena;

	node = huge_node_get(ptr);
	arena = extent_node_arena_get(node);
	huge_node_unset(ptr, node);
	malloc_mutex_lock(&arena->huge_mtx);
	ql_remove(&arena->huge, node, ql_link);
	malloc_mutex_unlock(&arena->huge_mtx);

	huge_dalloc_junk(extent_node_addr_get(node),
	    extent_node_size_get(node));
	arena_chunk_dalloc_huge(extent_node_arena_get(node),
	    extent_node_addr_get(node), extent_node_size_get(node));
	idalloctm(tsd, node, tcache, true);
}

arena_t *
huge_aalloc(const void *ptr)
{

	return (extent_node_arena_get(huge_node_get(ptr)));
}

size_t
huge_salloc(const void *ptr)
{
	size_t size;
	extent_node_t *node;
	arena_t *arena;

	node = huge_node_get(ptr);
	arena = extent_node_arena_get(node);
	malloc_mutex_lock(&arena->huge_mtx);
	size = extent_node_size_get(node);
	malloc_mutex_unlock(&arena->huge_mtx);

	return (size);
}

prof_tctx_t *
huge_prof_tctx_get(const void *ptr)
{
	prof_tctx_t *tctx;
	extent_node_t *node;
	arena_t *arena;

	node = huge_node_get(ptr);
	arena = extent_node_arena_get(node);
	malloc_mutex_lock(&arena->huge_mtx);
	tctx = extent_node_prof_tctx_get(node);
	malloc_mutex_unlock(&arena->huge_mtx);

	return (tctx);
}

void
huge_prof_tctx_set(const void *ptr, prof_tctx_t *tctx)
{
	extent_node_t *node;
	arena_t *arena;

	node = huge_node_get(ptr);
	arena = extent_node_arena_get(node);
	malloc_mutex_lock(&arena->huge_mtx);
	extent_node_prof_tctx_set(node, tctx);
	malloc_mutex_unlock(&arena->huge_mtx);
}

void
huge_prof_tctx_reset(const void *ptr)
{

	huge_prof_tctx_set(ptr, (prof_tctx_t *)(uintptr_t)1U);
}

