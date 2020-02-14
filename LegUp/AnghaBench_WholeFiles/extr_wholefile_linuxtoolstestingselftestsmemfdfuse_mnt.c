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
struct stat {int st_mode; int st_nlink; void* st_size; } ;
struct fuse_file_info {int flags; int direct_io; } ;
typedef  size_t off_t ;
typedef  int /*<<< orphan*/  (* fuse_fill_dir_t ) (void*,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ;

/* Variables and functions */
 int EACCES ; 
 int ENOENT ; 
 int O_RDONLY ; 
 int S_IFDIR ; 
 int S_IFREG ; 
 int fuse_main (int,char**,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memcpy (char*,scalar_t__,size_t) ; 
 scalar_t__ memfd_content ; 
 int /*<<< orphan*/  memfd_ops ; 
 char* memfd_path ; 
 int /*<<< orphan*/  memset (struct stat*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  sleep (int) ; 
 scalar_t__ strcmp (char const*,char*) ; 
 void* strlen (scalar_t__) ; 

__attribute__((used)) static int memfd_getattr(const char *path, struct stat *st)
{
	memset(st, 0, sizeof(*st));

	if (!strcmp(path, "/")) {
		st->st_mode = S_IFDIR | 0755;
		st->st_nlink = 2;
	} else if (!strcmp(path, memfd_path)) {
		st->st_mode = S_IFREG | 0444;
		st->st_nlink = 1;
		st->st_size = strlen(memfd_content);
	} else {
		return -ENOENT;
	}

	return 0;
}

__attribute__((used)) static int memfd_readdir(const char *path,
			 void *buf,
			 fuse_fill_dir_t filler,
			 off_t offset,
			 struct fuse_file_info *fi)
{
	if (strcmp(path, "/"))
		return -ENOENT;

	filler(buf, ".", NULL, 0);
	filler(buf, "..", NULL, 0);
	filler(buf, memfd_path + 1, NULL, 0);

	return 0;
}

__attribute__((used)) static int memfd_open(const char *path, struct fuse_file_info *fi)
{
	if (strcmp(path, memfd_path))
		return -ENOENT;

	if ((fi->flags & 3) != O_RDONLY)
		return -EACCES;

	/* force direct-IO */
	fi->direct_io = 1;

	return 0;
}

__attribute__((used)) static int memfd_read(const char *path,
		      char *buf,
		      size_t size,
		      off_t offset,
		      struct fuse_file_info *fi)
{
	size_t len;

	if (strcmp(path, memfd_path) != 0)
		return -ENOENT;

	sleep(1);

	len = strlen(memfd_content);
	if (offset < len) {
		if (offset + size > len)
			size = len - offset;

		memcpy(buf, memfd_content + offset, size);
	} else {
		size = 0;
	}

	return size;
}

int main(int argc, char *argv[])
{
	return fuse_main(argc, argv, &memfd_ops, NULL);
}

