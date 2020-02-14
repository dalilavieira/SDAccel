#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_9__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
struct git__dirent {scalar_t__ d_ino; int /*<<< orphan*/  d_name; } ;
typedef  int /*<<< orphan*/  git_win32_path ;
struct TYPE_12__ {int dwFileAttributes; int /*<<< orphan*/  cFileName; } ;
struct TYPE_11__ {char const* dir; scalar_t__ h; int first; TYPE_9__ f; struct git__dirent entry; } ;
typedef  TYPE_1__ git__DIR ;

/* Variables and functions */
 scalar_t__ ERROR_NO_MORE_FILES ; 
 int FILE_ATTRIBUTE_DIRECTORY ; 
 int /*<<< orphan*/  FindClose (scalar_t__) ; 
 void* FindFirstFileW (int /*<<< orphan*/ ,TYPE_9__*) ; 
 int /*<<< orphan*/  FindNextFileW (scalar_t__,TYPE_9__*) ; 
 scalar_t__ GIT_ADD_SIZET_OVERFLOW (size_t*,size_t,int) ; 
 int /*<<< orphan*/  GIT_ERROR_OS ; 
 scalar_t__ GetLastError () ; 
 scalar_t__ INVALID_HANDLE_VALUE ; 
 TYPE_1__* git__calloc (int,size_t) ; 
 int /*<<< orphan*/  git__free (TYPE_1__*) ; 
 int /*<<< orphan*/  git_error_set (int /*<<< orphan*/ ,char*,char const*) ; 
 int /*<<< orphan*/  git_win32__findfirstfile_filter (int /*<<< orphan*/ ,char const*) ; 
 scalar_t__ git_win32_path_to_utf8 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (char const*,char const*,size_t) ; 
 size_t strlen (char const*) ; 

git__DIR *git__opendir(const char *dir)
{
	git_win32_path filter_w;
	git__DIR *new = NULL;
	size_t dirlen, alloclen;

	if (!dir || !git_win32__findfirstfile_filter(filter_w, dir))
		return NULL;

	dirlen = strlen(dir);

	if (GIT_ADD_SIZET_OVERFLOW(&alloclen, sizeof(*new), dirlen) ||
		GIT_ADD_SIZET_OVERFLOW(&alloclen, alloclen, 1) ||
		!(new = git__calloc(1, alloclen)))
		return NULL;

	memcpy(new->dir, dir, dirlen);

	new->h = FindFirstFileW(filter_w, &new->f);

	if (new->h == INVALID_HANDLE_VALUE) {
		git_error_set(GIT_ERROR_OS, "could not open directory '%s'", dir);
		git__free(new);
		return NULL;
	}

	new->first = 1;
	return new;
}

int git__readdir_ext(
	git__DIR *d,
	struct git__dirent *entry,
	struct git__dirent **result,
	int *is_dir)
{
	if (!d || !entry || !result || d->h == INVALID_HANDLE_VALUE)
		return -1;

	*result = NULL;

	if (d->first)
		d->first = 0;
	else if (!FindNextFileW(d->h, &d->f)) {
		if (GetLastError() == ERROR_NO_MORE_FILES)
			return 0;
		git_error_set(GIT_ERROR_OS, "could not read from directory '%s'", d->dir);
		return -1;
	}

	/* Convert the path to UTF-8 */
	if (git_win32_path_to_utf8(entry->d_name, d->f.cFileName) < 0)
		return -1;

	entry->d_ino = 0;

	*result = entry;

	if (is_dir != NULL)
		*is_dir = ((d->f.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0);

	return 0;
}

struct git__dirent *git__readdir(git__DIR *d)
{
	struct git__dirent *result;
	if (git__readdir_ext(d, &d->entry, &result, NULL) < 0)
		return NULL;
	return result;
}

void git__rewinddir(git__DIR *d)
{
	git_win32_path filter_w;

	if (!d)
		return;

	if (d->h != INVALID_HANDLE_VALUE) {
		FindClose(d->h);
		d->h = INVALID_HANDLE_VALUE;
		d->first = 0;
	}

	if (!git_win32__findfirstfile_filter(filter_w, d->dir))
		return;

	d->h = FindFirstFileW(filter_w, &d->f);

	if (d->h == INVALID_HANDLE_VALUE)
		git_error_set(GIT_ERROR_OS, "could not open directory '%s'", d->dir);
	else
		d->first = 1;
}

int git__closedir(git__DIR *d)
{
	if (!d)
		return 0;

	if (d->h != INVALID_HANDLE_VALUE) {
		FindClose(d->h);
		d->h = INVALID_HANDLE_VALUE;
	}

	git__free(d);
	return 0;
}

