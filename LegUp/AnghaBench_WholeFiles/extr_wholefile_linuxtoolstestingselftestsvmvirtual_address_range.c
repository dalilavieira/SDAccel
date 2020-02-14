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
 unsigned long HIGH_ADDR_MARK ; 
 int HIGH_ADDR_SHIFT ; 
 int MAP_ANONYMOUS ; 
 int /*<<< orphan*/  MAP_CHUNK_SIZE ; 
 char* MAP_FAILED ; 
 int MAP_PRIVATE ; 
 int NR_CHUNKS_HIGH ; 
 int NR_CHUNKS_LOW ; 
 int PROT_READ ; 
 int PROT_WRITE ; 
 char* mmap (char*,int /*<<< orphan*/ ,int,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  munmap (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printf (char*,unsigned long) ; 
 int rand () ; 

__attribute__((used)) static char *hind_addr(void)
{
	int bits = HIGH_ADDR_SHIFT + rand() % (63 - HIGH_ADDR_SHIFT);

	return (char *) (1UL << bits);
}

__attribute__((used)) static int validate_addr(char *ptr, int high_addr)
{
	unsigned long addr = (unsigned long) ptr;

	if (high_addr) {
		if (addr < HIGH_ADDR_MARK) {
			printf("Bad address %lx\n", addr);
			return 1;
		}
		return 0;
	}

	if (addr > HIGH_ADDR_MARK) {
		printf("Bad address %lx\n", addr);
		return 1;
	}
	return 0;
}

__attribute__((used)) static int validate_lower_address_hint(void)
{
	char *ptr;

	ptr = mmap((void *) (1UL << 45), MAP_CHUNK_SIZE, PROT_READ |
			PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	if (ptr == MAP_FAILED)
		return 0;

	return 1;
}

int main(int argc, char *argv[])
{
	char *ptr[NR_CHUNKS_LOW];
	char *hptr[NR_CHUNKS_HIGH];
	char *hint;
	unsigned long i, lchunks, hchunks;

	for (i = 0; i < NR_CHUNKS_LOW; i++) {
		ptr[i] = mmap(NULL, MAP_CHUNK_SIZE, PROT_READ | PROT_WRITE,
					MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

		if (ptr[i] == MAP_FAILED) {
			if (validate_lower_address_hint())
				return 1;
			break;
		}

		if (validate_addr(ptr[i], 0))
			return 1;
	}
	lchunks = i;

	for (i = 0; i < NR_CHUNKS_HIGH; i++) {
		hint = hind_addr();
		hptr[i] = mmap(hint, MAP_CHUNK_SIZE, PROT_READ | PROT_WRITE,
					MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

		if (hptr[i] == MAP_FAILED)
			break;

		if (validate_addr(hptr[i], 1))
			return 1;
	}
	hchunks = i;

	for (i = 0; i < lchunks; i++)
		munmap(ptr[i], MAP_CHUNK_SIZE);

	for (i = 0; i < hchunks; i++)
		munmap(hptr[i], MAP_CHUNK_SIZE);

	return 0;
}

