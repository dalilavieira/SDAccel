#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int git_off_t ;
struct TYPE_7__ {size_t len; int /*<<< orphan*/ * fmh; int /*<<< orphan*/ * data; } ;
typedef  TYPE_1__ git_map ;
struct TYPE_8__ {int dwPageSize; int dwAllocationGranularity; } ;
typedef  TYPE_2__ SYSTEM_INFO ;
typedef  int /*<<< orphan*/ * HANDLE ;
typedef  int DWORD ;

/* Variables and functions */
 int /*<<< orphan*/  CloseHandle (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * CreateFileMapping (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  EBADF ; 
 int /*<<< orphan*/  EINVAL ; 
 int FILE_MAP_READ ; 
 int FILE_MAP_WRITE ; 
 int /*<<< orphan*/  GIT_ERROR_OS ; 
 int /*<<< orphan*/  GIT_MMAP_VALIDATE (TYPE_1__*,size_t,int,int) ; 
 int GIT_PROT_READ ; 
 int GIT_PROT_WRITE ; 
 int /*<<< orphan*/  GetSystemInfo (TYPE_2__*) ; 
 int /*<<< orphan*/ * INVALID_HANDLE_VALUE ; 
 int /*<<< orphan*/ * MapViewOfFile (int /*<<< orphan*/ *,int,int,int,size_t) ; 
 int PAGE_READONLY ; 
 int PAGE_READWRITE ; 
 int /*<<< orphan*/  UnmapViewOfFile (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  _get_osfhandle (int) ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  errno ; 
 int /*<<< orphan*/  git_error_set (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static DWORD get_page_size(void)
{
	static DWORD page_size;
	SYSTEM_INFO sys;

	if (!page_size) {
		GetSystemInfo(&sys);
		page_size = sys.dwPageSize;
	}

	return page_size;
}

__attribute__((used)) static DWORD get_allocation_granularity(void)
{
	static DWORD granularity;
	SYSTEM_INFO sys;

	if (!granularity) {
		GetSystemInfo(&sys);
		granularity = sys.dwAllocationGranularity;
	}

	return granularity;
}

int git__page_size(size_t *page_size)
{
	*page_size = get_page_size();
	return 0;
}

int git__mmap_alignment(size_t *page_size)
{
	*page_size = get_allocation_granularity();
	return 0;
}

int p_mmap(git_map *out, size_t len, int prot, int flags, int fd, git_off_t offset)
{
	HANDLE fh = (HANDLE)_get_osfhandle(fd);
	DWORD alignment = get_allocation_granularity();
	DWORD fmap_prot = 0;
	DWORD view_prot = 0;
	DWORD off_low = 0;
	DWORD off_hi = 0;
	git_off_t page_start;
	git_off_t page_offset;

	GIT_MMAP_VALIDATE(out, len, prot, flags);

	out->data = NULL;
	out->len = 0;
	out->fmh = NULL;

	if (fh == INVALID_HANDLE_VALUE) {
		errno = EBADF;
		git_error_set(GIT_ERROR_OS, "failed to mmap. Invalid handle value");
		return -1;
	}

	if (prot & GIT_PROT_WRITE)
		fmap_prot |= PAGE_READWRITE;
	else if (prot & GIT_PROT_READ)
		fmap_prot |= PAGE_READONLY;

	if (prot & GIT_PROT_WRITE)
		view_prot |= FILE_MAP_WRITE;
	if (prot & GIT_PROT_READ)
		view_prot |= FILE_MAP_READ;

	page_start = (offset / alignment) * alignment;
	page_offset = offset - page_start;

	if (page_offset != 0) { /* offset must be multiple of the allocation granularity */
		errno = EINVAL;
		git_error_set(GIT_ERROR_OS, "failed to mmap. Offset must be multiple of allocation granularity");
		return -1;
	}

	out->fmh = CreateFileMapping(fh, NULL, fmap_prot, 0, 0, NULL);
	if (!out->fmh || out->fmh == INVALID_HANDLE_VALUE) {
		git_error_set(GIT_ERROR_OS, "failed to mmap. Invalid handle value");
		out->fmh = NULL;
		return -1;
	}

	assert(sizeof(git_off_t) == 8);

	off_low = (DWORD)(page_start);
	off_hi = (DWORD)(page_start >> 32);
	out->data = MapViewOfFile(out->fmh, view_prot, off_hi, off_low, len);
	if (!out->data) {
		git_error_set(GIT_ERROR_OS, "failed to mmap. No data written");
		CloseHandle(out->fmh);
		out->fmh = NULL;
		return -1;
	}
	out->len = len;

	return 0;
}

int p_munmap(git_map *map)
{
	int error = 0;

	assert(map != NULL);

	if (map->data) {
		if (!UnmapViewOfFile(map->data)) {
			git_error_set(GIT_ERROR_OS, "failed to munmap. Could not unmap view of file");
			error = -1;
		}
		map->data = NULL;
	}

	if (map->fmh) {
		if (!CloseHandle(map->fmh)) {
			git_error_set(GIT_ERROR_OS, "failed to munmap. Could not close handle");
			error = -1;
		}
		map->fmh = NULL;
	}

	return error;
}

