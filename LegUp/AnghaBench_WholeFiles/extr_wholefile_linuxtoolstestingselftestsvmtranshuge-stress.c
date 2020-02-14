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
typedef  int uint8_t ;
typedef  int /*<<< orphan*/  uint64_t ;
struct timespec {int tv_sec; int tv_nsec; } ;
typedef  int int64_t ;
typedef  int /*<<< orphan*/  ent ;

/* Variables and functions */
 int /*<<< orphan*/  CLOCK_MONOTONIC ; 
 int HPAGE_SHIFT ; 
 size_t HPAGE_SIZE ; 
 int /*<<< orphan*/  MADV_DONTNEED ; 
 int /*<<< orphan*/  MADV_HUGEPAGE ; 
 int MAP_ANONYMOUS ; 
 void* MAP_FAILED ; 
 int MAP_FIXED ; 
 int MAP_NORESERVE ; 
 int MAP_PRIVATE ; 
 int /*<<< orphan*/  O_RDONLY ; 
 int PAGEMAP_PFN (int /*<<< orphan*/ ) ; 
 scalar_t__ PAGEMAP_PRESENT (int /*<<< orphan*/ ) ; 
 int PAGE_SHIFT ; 
 size_t PAGE_SIZE ; 
 int PROT_READ ; 
 int PROT_WRITE ; 
 int SIZE_MAX ; 
 int /*<<< orphan*/  _SC_PAGESIZE ; 
 int /*<<< orphan*/  _SC_PHYS_PAGES ; 
 int atoll (char*) ; 
 int /*<<< orphan*/  clock_gettime (int /*<<< orphan*/ ,struct timespec*) ; 
 int /*<<< orphan*/  err (int,char*) ; 
 int /*<<< orphan*/  errx (int,char*,...) ; 
 scalar_t__ madvise (void*,size_t,int /*<<< orphan*/ ) ; 
 int* malloc (size_t) ; 
 int /*<<< orphan*/  memset (int*,int /*<<< orphan*/ ,size_t) ; 
 void* mmap (void*,size_t,int,int,int,int /*<<< orphan*/ ) ; 
 scalar_t__ open (char*,int /*<<< orphan*/ ) ; 
 scalar_t__ pagemap_fd ; 
 int pread (scalar_t__,int /*<<< orphan*/ *,int,uintptr_t) ; 
 int* realloc (int*,size_t) ; 
 int /*<<< orphan*/  strcmp (char*,char*) ; 
 size_t sysconf (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  warnx (char*,double,double,size_t,...) ; 

int64_t allocate_transhuge(void *ptr)
{
	uint64_t ent[2];

	/* drop pmd */
	if (mmap(ptr, HPAGE_SIZE, PROT_READ | PROT_WRITE,
				MAP_FIXED | MAP_ANONYMOUS |
				MAP_NORESERVE | MAP_PRIVATE, -1, 0) != ptr)
		errx(2, "mmap transhuge");

	if (madvise(ptr, HPAGE_SIZE, MADV_HUGEPAGE))
		err(2, "MADV_HUGEPAGE");

	/* allocate transparent huge page */
	*(volatile void **)ptr = ptr;

	if (pread(pagemap_fd, ent, sizeof(ent),
			(uintptr_t)ptr >> (PAGE_SHIFT - 3)) != sizeof(ent))
		err(2, "read pagemap");

	if (PAGEMAP_PRESENT(ent[0]) && PAGEMAP_PRESENT(ent[1]) &&
	    PAGEMAP_PFN(ent[0]) + 1 == PAGEMAP_PFN(ent[1]) &&
	    !(PAGEMAP_PFN(ent[0]) & ((1 << (HPAGE_SHIFT - PAGE_SHIFT)) - 1)))
		return PAGEMAP_PFN(ent[0]);

	return -1;
}

int main(int argc, char **argv)
{
	size_t ram, len;
	void *ptr, *p;
	struct timespec a, b;
	double s;
	uint8_t *map;
	size_t map_len;

	ram = sysconf(_SC_PHYS_PAGES);
	if (ram > SIZE_MAX / sysconf(_SC_PAGESIZE) / 4)
		ram = SIZE_MAX / 4;
	else
		ram *= sysconf(_SC_PAGESIZE);

	if (argc == 1)
		len = ram;
	else if (!strcmp(argv[1], "-h"))
		errx(1, "usage: %s [size in MiB]", argv[0]);
	else
		len = atoll(argv[1]) << 20;

	warnx("allocate %zd transhuge pages, using %zd MiB virtual memory"
	      " and %zd MiB of ram", len >> HPAGE_SHIFT, len >> 20,
	      len >> (20 + HPAGE_SHIFT - PAGE_SHIFT - 1));

	pagemap_fd = open("/proc/self/pagemap", O_RDONLY);
	if (pagemap_fd < 0)
		err(2, "open pagemap");

	len -= len % HPAGE_SIZE;
	ptr = mmap(NULL, len + HPAGE_SIZE, PROT_READ | PROT_WRITE,
			MAP_ANONYMOUS | MAP_NORESERVE | MAP_PRIVATE, -1, 0);
	if (ptr == MAP_FAILED)
		err(2, "initial mmap");
	ptr += HPAGE_SIZE - (uintptr_t)ptr % HPAGE_SIZE;

	if (madvise(ptr, len, MADV_HUGEPAGE))
		err(2, "MADV_HUGEPAGE");

	map_len = ram >> (HPAGE_SHIFT - 1);
	map = malloc(map_len);
	if (!map)
		errx(2, "map malloc");

	while (1) {
		int nr_succeed = 0, nr_failed = 0, nr_pages = 0;

		memset(map, 0, map_len);

		clock_gettime(CLOCK_MONOTONIC, &a);
		for (p = ptr; p < ptr + len; p += HPAGE_SIZE) {
			int64_t pfn;

			pfn = allocate_transhuge(p);

			if (pfn < 0) {
				nr_failed++;
			} else {
				size_t idx = pfn >> (HPAGE_SHIFT - PAGE_SHIFT);

				nr_succeed++;
				if (idx >= map_len) {
					map = realloc(map, idx + 1);
					if (!map)
						errx(2, "map realloc");
					memset(map + map_len, 0, idx + 1 - map_len);
					map_len = idx + 1;
				}
				if (!map[idx])
					nr_pages++;
				map[idx] = 1;
			}

			/* split transhuge page, keep last page */
			if (madvise(p, HPAGE_SIZE - PAGE_SIZE, MADV_DONTNEED))
				err(2, "MADV_DONTNEED");
		}
		clock_gettime(CLOCK_MONOTONIC, &b);
		s = b.tv_sec - a.tv_sec + (b.tv_nsec - a.tv_nsec) / 1000000000.;

		warnx("%.3f s/loop, %.3f ms/page, %10.3f MiB/s\t"
		      "%4d succeed, %4d failed, %4d different pages",
		      s, s * 1000 / (len >> HPAGE_SHIFT), len / s / (1 << 20),
		      nr_succeed, nr_failed, nr_pages);
	}
}

