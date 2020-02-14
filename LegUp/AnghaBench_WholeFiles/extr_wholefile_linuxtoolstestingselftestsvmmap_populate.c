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
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int,char*) ; 
 unsigned long* MAP_FAILED ; 
 int MAP_POPULATE ; 
 int MAP_PRIVATE ; 
 int MAP_SHARED ; 
 int /*<<< orphan*/  MMAP_SZ ; 
 int /*<<< orphan*/  MS_SYNC ; 
 int /*<<< orphan*/  PF_LOCAL ; 
 int PROT_READ ; 
 int PROT_WRITE ; 
 int /*<<< orphan*/  SOCK_SEQPACKET ; 
 int WEXITSTATUS (int) ; 
 int /*<<< orphan*/  WIFEXITED (int) ; 
 int close (int) ; 
 int fileno (int /*<<< orphan*/ *) ; 
 int fork () ; 
 int ftruncate (int,int /*<<< orphan*/ ) ; 
 unsigned long* mmap (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int,int /*<<< orphan*/ ) ; 
 int msync (unsigned long*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int read (int,int*,int) ; 
 int socketpair (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/ * tmpfile () ; 
 int /*<<< orphan*/  waitpid (int,int*,int /*<<< orphan*/ ) ; 
 int write (int,int*,int) ; 

__attribute__((used)) static int parent_f(int sock, unsigned long *smap, int child)
{
	int status, ret;

	ret = read(sock, &status, sizeof(int));
	BUG_ON(ret <= 0, "read(sock)");

	*smap = 0x22222BAD;
	ret = msync(smap, MMAP_SZ, MS_SYNC);
	BUG_ON(ret, "msync()");

	ret = write(sock, &status, sizeof(int));
	BUG_ON(ret <= 0, "write(sock)");

	waitpid(child, &status, 0);
	BUG_ON(!WIFEXITED(status), "child in unexpected state");

	return WEXITSTATUS(status);
}

__attribute__((used)) static int child_f(int sock, unsigned long *smap, int fd)
{
	int ret, buf = 0;

	smap = mmap(0, MMAP_SZ, PROT_READ | PROT_WRITE,
			MAP_PRIVATE | MAP_POPULATE, fd, 0);
	BUG_ON(smap == MAP_FAILED, "mmap()");

	BUG_ON(*smap != 0xdeadbabe, "MAP_PRIVATE | MAP_POPULATE changed file");

	ret = write(sock, &buf, sizeof(int));
	BUG_ON(ret <= 0, "write(sock)");

	ret = read(sock, &buf, sizeof(int));
	BUG_ON(ret <= 0, "read(sock)");

	BUG_ON(*smap == 0x22222BAD, "MAP_POPULATE didn't COW private page");
	BUG_ON(*smap != 0xdeadbabe, "mapping was corrupted");

	return 0;
}

int main(int argc, char **argv)
{
	int sock[2], child, ret;
	FILE *ftmp;
	unsigned long *smap;

	ftmp = tmpfile();
	BUG_ON(ftmp == 0, "tmpfile()");

	ret = ftruncate(fileno(ftmp), MMAP_SZ);
	BUG_ON(ret, "ftruncate()");

	smap = mmap(0, MMAP_SZ, PROT_READ | PROT_WRITE,
			MAP_SHARED, fileno(ftmp), 0);
	BUG_ON(smap == MAP_FAILED, "mmap()");

	*smap = 0xdeadbabe;
	/* Probably unnecessary, but let it be. */
	ret = msync(smap, MMAP_SZ, MS_SYNC);
	BUG_ON(ret, "msync()");

	ret = socketpair(PF_LOCAL, SOCK_SEQPACKET, 0, sock);
	BUG_ON(ret, "socketpair()");

	child = fork();
	BUG_ON(child == -1, "fork()");

	if (child) {
		ret = close(sock[0]);
		BUG_ON(ret, "close()");

		return parent_f(sock[1], smap, child);
	}

	ret = close(sock[1]);
	BUG_ON(ret, "close()");

	return child_f(sock[0], smap, fileno(ftmp));
}

