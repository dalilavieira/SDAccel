#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  git_off_t ;
struct TYPE_5__ {size_t len; int /*<<< orphan*/ * data; } ;
typedef  TYPE_1__ git_map ;

/* Variables and functions */
 int /*<<< orphan*/  GIT_ERROR_OS ; 
 int GIT_MAP_PRIVATE ; 
 int GIT_MAP_SHARED ; 
 int GIT_MAP_TYPE ; 
 int /*<<< orphan*/  GIT_MMAP_VALIDATE (TYPE_1__*,size_t,int,int) ; 
 int GIT_PROT_WRITE ; 
 int /*<<< orphan*/ * MAP_FAILED ; 
 int MAP_PRIVATE ; 
 int MAP_SHARED ; 
 int PROT_READ ; 
 int PROT_WRITE ; 
 int /*<<< orphan*/  _SC_PAGE_SIZE ; 
 int /*<<< orphan*/  assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_error_set (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/ * mmap (int /*<<< orphan*/ *,size_t,int,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  munmap (int /*<<< orphan*/ *,size_t) ; 
 long sysconf (int /*<<< orphan*/ ) ; 

int git__page_size(size_t *page_size)
{
	long sc_page_size = sysconf(_SC_PAGE_SIZE);
	if (sc_page_size < 0) {
		git_error_set(GIT_ERROR_OS, "can't determine system page size");
		return -1;
	}
	*page_size = (size_t) sc_page_size;
	return 0;
}

int git__mmap_alignment(size_t *alignment)
{
  return git__page_size(alignment);
}

int p_mmap(git_map *out, size_t len, int prot, int flags, int fd, git_off_t offset)
{
	int mprot = PROT_READ;
	int mflag = 0;

	GIT_MMAP_VALIDATE(out, len, prot, flags);

	out->data = NULL;
	out->len = 0;

	if (prot & GIT_PROT_WRITE)
		mprot |= PROT_WRITE;

	if ((flags & GIT_MAP_TYPE) == GIT_MAP_SHARED)
		mflag = MAP_SHARED;
	else if ((flags & GIT_MAP_TYPE) == GIT_MAP_PRIVATE)
		mflag = MAP_PRIVATE;
	else
		mflag = MAP_SHARED;

	out->data = mmap(NULL, len, mprot, mflag, fd, offset);

	if (!out->data || out->data == MAP_FAILED) {
		git_error_set(GIT_ERROR_OS, "failed to mmap. Could not write data");
		return -1;
	}

	out->len = len;

	return 0;
}

int p_munmap(git_map *map)
{
	assert(map != NULL);
	munmap(map->data, map->len);

	return 0;
}

