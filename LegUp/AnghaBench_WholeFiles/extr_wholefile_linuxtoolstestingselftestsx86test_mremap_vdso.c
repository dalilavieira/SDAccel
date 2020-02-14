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
typedef  int pid_t ;

/* Variables and functions */
 int /*<<< orphan*/  AT_SYSINFO_EHDR ; 
 int EINVAL ; 
 unsigned long ENOENT ; 
 int MAP_ANONYMOUS ; 
 void* MAP_FAILED ; 
 int MAP_PRIVATE ; 
 int MREMAP_FIXED ; 
 int MREMAP_MAYMOVE ; 
 unsigned long PAGE_SIZE ; 
 int /*<<< orphan*/  PROT_NONE ; 
 int /*<<< orphan*/  SYS_exit ; 
 int WEXITSTATUS (int) ; 
 int /*<<< orphan*/  WIFEXITED (int) ; 
 int errno ; 
 int /*<<< orphan*/  fflush (int /*<<< orphan*/ ) ; 
 int fork () ; 
 unsigned long getauxval (int /*<<< orphan*/ ) ; 
 void* mmap (int /*<<< orphan*/ ,unsigned long,int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ) ; 
 void* mremap (void*,unsigned long,unsigned long,int,void*) ; 
 int /*<<< orphan*/  munmap (void*,unsigned long) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/  stdout ; 
 int /*<<< orphan*/  syscall (int /*<<< orphan*/ ,int) ; 
 int waitpid (int,int*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int try_to_remap(void *vdso_addr, unsigned long size)
{
	void *dest_addr, *new_addr;

	/* Searching for memory location where to remap */
	dest_addr = mmap(0, size, PROT_NONE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
	if (dest_addr == MAP_FAILED) {
		printf("[WARN]\tmmap failed (%d): %m\n", errno);
		return 0;
	}

	printf("[NOTE]\tMoving vDSO: [%p, %#lx] -> [%p, %#lx]\n",
		vdso_addr, (unsigned long)vdso_addr + size,
		dest_addr, (unsigned long)dest_addr + size);
	fflush(stdout);

	new_addr = mremap(vdso_addr, size, size,
			MREMAP_FIXED|MREMAP_MAYMOVE, dest_addr);
	if ((unsigned long)new_addr == (unsigned long)-1) {
		munmap(dest_addr, size);
		if (errno == EINVAL) {
			printf("[NOTE]\tvDSO partial move failed, will try with bigger size\n");
			return -1; /* Retry with larger */
		}
		printf("[FAIL]\tmremap failed (%d): %m\n", errno);
		return 1;
	}

	return 0;

}

int main(int argc, char **argv, char **envp)
{
	pid_t child;

	child = fork();
	if (child == -1) {
		printf("[WARN]\tfailed to fork (%d): %m\n", errno);
		return 1;
	}

	if (child == 0) {
		unsigned long vdso_size = PAGE_SIZE;
		unsigned long auxval;
		int ret = -1;

		auxval = getauxval(AT_SYSINFO_EHDR);
		printf("\tAT_SYSINFO_EHDR is %#lx\n", auxval);
		if (!auxval || auxval == -ENOENT) {
			printf("[WARN]\tgetauxval failed\n");
			return 0;
		}

		/* Simpler than parsing ELF header */
		while (ret < 0) {
			ret = try_to_remap((void *)auxval, vdso_size);
			vdso_size += PAGE_SIZE;
		}

#ifdef __i386__
		/* Glibc is likely to explode now - exit with raw syscall */
		asm volatile ("int $0x80" : : "a" (__NR_exit), "b" (!!ret));
#else /* __x86_64__ */
		syscall(SYS_exit, ret);
#endif
	} else {
		int status;

		if (waitpid(child, &status, 0) != child ||
			!WIFEXITED(status)) {
			printf("[FAIL]\tmremap() of the vDSO does not work on this kernel!\n");
			return 1;
		} else if (WEXITSTATUS(status) != 0) {
			printf("[FAIL]\tChild failed with %d\n",
					WEXITSTATUS(status));
			return 1;
		}
		printf("[OK]\n");
	}

	return 0;
}

