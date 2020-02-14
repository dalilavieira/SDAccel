#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  void uint8_t ;
struct TYPE_8__ {size_t size; void* base; int /*<<< orphan*/ * aligned; } ;
typedef  TYPE_1__ escrypt_region_t ;
typedef  TYPE_1__ escrypt_local_t ;

/* Variables and functions */
 int /*<<< orphan*/  ENOMEM ; 
 int /*<<< orphan*/  errno ; 
 int /*<<< orphan*/  free (void*) ; 
 scalar_t__ malloc (size_t) ; 

void *
alloc_region(escrypt_region_t *region, size_t size)
{
    uint8_t *base, *aligned;
#if defined(MAP_ANON) && defined(HAVE_MMAP)
    if ((base = (uint8_t *) mmap(NULL, size, PROT_READ | PROT_WRITE,
                                 MAP_ANON | MAP_PRIVATE | MAP_NOCORE | MAP_POPULATE,
                                 -1, 0)) == MAP_FAILED) {
        base = NULL; /* LCOV_EXCL_LINE */
    }                /* LCOV_EXCL_LINE */
    aligned  = base;
#elif defined(HAVE_POSIX_MEMALIGN)
    if ((errno = posix_memalign((void **) &base, 64, size)) != 0) {
        base = NULL;
    }
    aligned = base;
#else
    base = aligned = NULL;
    if (size + 63 < size) {
        errno = ENOMEM;
    } else if ((base = (uint8_t *) malloc(size + 63)) != NULL) {
        aligned = base + 63;
        aligned -= (uintptr_t) aligned & 63;
    }
#endif
    region->base    = base;
    region->aligned = aligned;
    region->size    = base ? size : 0;

    return aligned;
}

__attribute__((used)) static inline void
init_region(escrypt_region_t *region)
{
    region->base = region->aligned = NULL;
    region->size                   = 0;
}

int
free_region(escrypt_region_t *region)
{
    if (region->base) {
#if defined(MAP_ANON) && defined(HAVE_MMAP)
        if (munmap(region->base, region->size)) {
            return -1; /* LCOV_EXCL_LINE */
        }
#else
        free(region->base);
#endif
    }
    init_region(region);

    return 0;
}

int
escrypt_init_local(escrypt_local_t *local)
{
    init_region(local);

    return 0;
}

int
escrypt_free_local(escrypt_local_t *local)
{
    return free_region(local);
}

