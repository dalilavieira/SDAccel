#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */

/* Variables and functions */
 size_t ALIGNMENT_ADDR2OFFSET (void*,size_t) ; 
 uintptr_t ALIGNMENT_CEILING (uintptr_t,size_t) ; 
 size_t PAGE ; 
 int /*<<< orphan*/  assert (int) ; 
 size_t chunksize_mask ; 
 scalar_t__ config_munmap ; 
 int pages_decommit (void*,size_t) ; 
 void* pages_map (int /*<<< orphan*/ *,size_t) ; 
 void* pages_trim (void*,size_t,size_t,size_t) ; 
 int /*<<< orphan*/  pages_unmap (void*,size_t) ; 

__attribute__((used)) static void *
chunk_alloc_mmap_slow(size_t size, size_t alignment, bool *zero, bool *commit)
{
	void *ret;
	size_t alloc_size;

	alloc_size = size + alignment - PAGE;
	/* Beware size_t wrap-around. */
	if (alloc_size < size)
		return (NULL);
	do {
		void *pages;
		size_t leadsize;
		pages = pages_map(NULL, alloc_size);
		if (pages == NULL)
			return (NULL);
		leadsize = ALIGNMENT_CEILING((uintptr_t)pages, alignment) -
		    (uintptr_t)pages;
		ret = pages_trim(pages, alloc_size, leadsize, size);
	} while (ret == NULL);

	assert(ret != NULL);
	*zero = true;
	if (!*commit)
		*commit = pages_decommit(ret, size);
	return (ret);
}

void *
chunk_alloc_mmap(size_t size, size_t alignment, bool *zero, bool *commit)
{
	void *ret;
	size_t offset;

	/*
	 * Ideally, there would be a way to specify alignment to mmap() (like
	 * NetBSD has), but in the absence of such a feature, we have to work
	 * hard to efficiently create aligned mappings.  The reliable, but
	 * slow method is to create a mapping that is over-sized, then trim the
	 * excess.  However, that always results in one or two calls to
	 * pages_unmap().
	 *
	 * Optimistically try mapping precisely the right amount before falling
	 * back to the slow method, with the expectation that the optimistic
	 * approach works most of the time.
	 */

	assert(alignment != 0);
	assert((alignment & chunksize_mask) == 0);

	ret = pages_map(NULL, size);
	if (ret == NULL)
		return (NULL);
	offset = ALIGNMENT_ADDR2OFFSET(ret, alignment);
	if (offset != 0) {
		pages_unmap(ret, size);
		return (chunk_alloc_mmap_slow(size, alignment, zero, commit));
	}

	assert(ret != NULL);
	*zero = true;
	if (!*commit)
		*commit = pages_decommit(ret, size);
	return (ret);
}

bool
chunk_dalloc_mmap(void *chunk, size_t size)
{

	if (config_munmap)
		pages_unmap(chunk, size);

	return (!config_munmap);
}

