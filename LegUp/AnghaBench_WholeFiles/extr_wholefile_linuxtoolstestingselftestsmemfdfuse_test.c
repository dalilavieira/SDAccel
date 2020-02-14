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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  scalar_t__ pid_t ;
typedef  unsigned long loff_t ;
typedef  long __u64 ;

/* Variables and functions */
 int CLONE_FILES ; 
 int CLONE_FS ; 
 int CLONE_VM ; 
 scalar_t__ EBUSY ; 
 int /*<<< orphan*/  F_ADD_SEALS ; 
 int /*<<< orphan*/  F_GET_SEALS ; 
 long F_SEAL_WRITE ; 
 void* MAP_FAILED ; 
 int /*<<< orphan*/  MAP_PRIVATE ; 
 int /*<<< orphan*/  MAP_SHARED ; 
 unsigned int MFD_ALLOW_SEALING ; 
 unsigned int MFD_CLOEXEC ; 
 int O_CLOEXEC ; 
 int O_RDONLY ; 
 int PROT_READ ; 
 int PROT_WRITE ; 
 int SIGCHLD ; 
 int STACK_SIZE ; 
 int /*<<< orphan*/  abort () ; 
 char* calloc (int,unsigned long) ; 
 scalar_t__ clone (int (*) (void*),int /*<<< orphan*/ *,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  close (int) ; 
 unsigned long default_huge_page_size () ; 
 scalar_t__ errno ; 
 long fcntl (int,int /*<<< orphan*/ ,...) ; 
 int /*<<< orphan*/  free (char*) ; 
 int ftruncate (int,unsigned long) ; 
 int global_mfd ; 
 void* global_p ; 
 int hugetlbfs_test ; 
 int /*<<< orphan*/ * malloc (int) ; 
 scalar_t__ memcmp (void*,char*,unsigned long) ; 
 unsigned long mfd_def_size ; 
 void* mmap (int /*<<< orphan*/ *,unsigned long,int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  munmap (void*,unsigned long) ; 
 int open (char*,int) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int read (int,void*,unsigned long) ; 
 int /*<<< orphan*/  sleep (int) ; 
 int /*<<< orphan*/  strcmp (char*,char*) ; 
 int sys_memfd_create (char const*,unsigned int) ; 
 int /*<<< orphan*/  usleep (int) ; 
 int /*<<< orphan*/  waitpid (scalar_t__,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int mfd_assert_new(const char *name, loff_t sz, unsigned int flags)
{
	int r, fd;

	fd = sys_memfd_create(name, flags);
	if (fd < 0) {
		printf("memfd_create(\"%s\", %u) failed: %m\n",
		       name, flags);
		abort();
	}

	r = ftruncate(fd, sz);
	if (r < 0) {
		printf("ftruncate(%llu) failed: %m\n", (unsigned long long)sz);
		abort();
	}

	return fd;
}

__attribute__((used)) static __u64 mfd_assert_get_seals(int fd)
{
	long r;

	r = fcntl(fd, F_GET_SEALS);
	if (r < 0) {
		printf("GET_SEALS(%d) failed: %m\n", fd);
		abort();
	}

	return r;
}

__attribute__((used)) static void mfd_assert_has_seals(int fd, __u64 seals)
{
	__u64 s;

	s = mfd_assert_get_seals(fd);
	if (s != seals) {
		printf("%llu != %llu = GET_SEALS(%d)\n",
		       (unsigned long long)seals, (unsigned long long)s, fd);
		abort();
	}
}

__attribute__((used)) static void mfd_assert_add_seals(int fd, __u64 seals)
{
	long r;
	__u64 s;

	s = mfd_assert_get_seals(fd);
	r = fcntl(fd, F_ADD_SEALS, seals);
	if (r < 0) {
		printf("ADD_SEALS(%d, %llu -> %llu) failed: %m\n",
		       fd, (unsigned long long)s, (unsigned long long)seals);
		abort();
	}
}

__attribute__((used)) static int mfd_busy_add_seals(int fd, __u64 seals)
{
	long r;
	__u64 s;

	r = fcntl(fd, F_GET_SEALS);
	if (r < 0)
		s = 0;
	else
		s = r;

	r = fcntl(fd, F_ADD_SEALS, seals);
	if (r < 0 && errno != EBUSY) {
		printf("ADD_SEALS(%d, %llu -> %llu) didn't fail as expected with EBUSY: %m\n",
		       fd, (unsigned long long)s, (unsigned long long)seals);
		abort();
	}

	return r;
}

__attribute__((used)) static void *mfd_assert_mmap_shared(int fd)
{
	void *p;

	p = mmap(NULL,
		 mfd_def_size,
		 PROT_READ | PROT_WRITE,
		 MAP_SHARED,
		 fd,
		 0);
	if (p == MAP_FAILED) {
		printf("mmap() failed: %m\n");
		abort();
	}

	return p;
}

__attribute__((used)) static void *mfd_assert_mmap_private(int fd)
{
	void *p;

	p = mmap(NULL,
		 mfd_def_size,
		 PROT_READ | PROT_WRITE,
		 MAP_PRIVATE,
		 fd,
		 0);
	if (p == MAP_FAILED) {
		printf("mmap() failed: %m\n");
		abort();
	}

	return p;
}

__attribute__((used)) static int sealing_thread_fn(void *arg)
{
	int sig, r;

	/*
	 * This thread first waits 200ms so any pending operation in the parent
	 * is correctly started. After that, it tries to seal @global_mfd as
	 * SEAL_WRITE. This _must_ fail as the parent thread has a read() into
	 * that memory mapped object still ongoing.
	 * We then wait one more second and try sealing again. This time it
	 * must succeed as there shouldn't be anyone else pinning the pages.
	 */

	/* wait 200ms for FUSE-request to be active */
	usleep(200000);

	/* unmount mapping before sealing to avoid i_mmap_writable failures */
	munmap(global_p, mfd_def_size);

	/* Try sealing the global file; expect EBUSY or success. Current
	 * kernels will never succeed, but in the future, kernels might
	 * implement page-replacements or other fancy ways to avoid racing
	 * writes. */
	r = mfd_busy_add_seals(global_mfd, F_SEAL_WRITE);
	if (r >= 0) {
		printf("HURRAY! This kernel fixed GUP races!\n");
	} else {
		/* wait 1s more so the FUSE-request is done */
		sleep(1);

		/* try sealing the global file again */
		mfd_assert_add_seals(global_mfd, F_SEAL_WRITE);
	}

	return 0;
}

__attribute__((used)) static pid_t spawn_sealing_thread(void)
{
	uint8_t *stack;
	pid_t pid;

	stack = malloc(STACK_SIZE);
	if (!stack) {
		printf("malloc(STACK_SIZE) failed: %m\n");
		abort();
	}

	pid = clone(sealing_thread_fn,
		    stack + STACK_SIZE,
		    SIGCHLD | CLONE_FILES | CLONE_FS | CLONE_VM,
		    NULL);
	if (pid < 0) {
		printf("clone() failed: %m\n");
		abort();
	}

	return pid;
}

__attribute__((used)) static void join_sealing_thread(pid_t pid)
{
	waitpid(pid, NULL, 0);
}

int main(int argc, char **argv)
{
	char *zero;
	int fd, mfd, r;
	void *p;
	int was_sealed;
	pid_t pid;

	if (argc < 2) {
		printf("error: please pass path to file in fuse_mnt mount-point\n");
		abort();
	}

	if (argc >= 3) {
		if (!strcmp(argv[2], "hugetlbfs")) {
			unsigned long hpage_size = default_huge_page_size();

			if (!hpage_size) {
				printf("Unable to determine huge page size\n");
				abort();
			}

			hugetlbfs_test = 1;
			mfd_def_size = hpage_size * 2;
		} else {
			printf("Unknown option: %s\n", argv[2]);
			abort();
		}
	}

	zero = calloc(sizeof(*zero), mfd_def_size);

	/* open FUSE memfd file for GUP testing */
	printf("opening: %s\n", argv[1]);
	fd = open(argv[1], O_RDONLY | O_CLOEXEC);
	if (fd < 0) {
		printf("cannot open(\"%s\"): %m\n", argv[1]);
		abort();
	}

	/* create new memfd-object */
	mfd = mfd_assert_new("kern_memfd_fuse",
			     mfd_def_size,
			     MFD_CLOEXEC | MFD_ALLOW_SEALING);

	/* mmap memfd-object for writing */
	p = mfd_assert_mmap_shared(mfd);

	/* pass mfd+mapping to a separate sealing-thread which tries to seal
	 * the memfd objects with SEAL_WRITE while we write into it */
	global_mfd = mfd;
	global_p = p;
	pid = spawn_sealing_thread();

	/* Use read() on the FUSE file to read into our memory-mapped memfd
	 * object. This races the other thread which tries to seal the
	 * memfd-object.
	 * If @fd is on the memfd-fake-FUSE-FS, the read() is delayed by 1s.
	 * This guarantees that the receive-buffer is pinned for 1s until the
	 * data is written into it. The racing ADD_SEALS should thus fail as
	 * the pages are still pinned. */
	r = read(fd, p, mfd_def_size);
	if (r < 0) {
		printf("read() failed: %m\n");
		abort();
	} else if (!r) {
		printf("unexpected EOF on read()\n");
		abort();
	}

	was_sealed = mfd_assert_get_seals(mfd) & F_SEAL_WRITE;

	/* Wait for sealing-thread to finish and verify that it
	 * successfully sealed the file after the second try. */
	join_sealing_thread(pid);
	mfd_assert_has_seals(mfd, F_SEAL_WRITE);

	/* *IF* the memfd-object was sealed at the time our read() returned,
	 * then the kernel did a page-replacement or canceled the read() (or
	 * whatever magic it did..). In that case, the memfd object is still
	 * all zero.
	 * In case the memfd-object was *not* sealed, the read() was successfull
	 * and the memfd object must *not* be all zero.
	 * Note that in real scenarios, there might be a mixture of both, but
	 * in this test-cases, we have explicit 200ms delays which should be
	 * enough to avoid any in-flight writes. */

	p = mfd_assert_mmap_private(mfd);
	if (was_sealed && memcmp(p, zero, mfd_def_size)) {
		printf("memfd sealed during read() but data not discarded\n");
		abort();
	} else if (!was_sealed && !memcmp(p, zero, mfd_def_size)) {
		printf("memfd sealed after read() but data discarded\n");
		abort();
	}

	close(mfd);
	close(fd);

	printf("fuse: DONE\n");
	free(zero);

	return 0;
}

