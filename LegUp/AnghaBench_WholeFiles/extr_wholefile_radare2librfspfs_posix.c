#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  ut64 ;
struct stat {scalar_t__ st_atime; int /*<<< orphan*/  st_mode; } ;
struct dirent {char const* d_name; } ;
typedef  int /*<<< orphan*/  fullpath ;
struct TYPE_15__ {float type; scalar_t__ time; int /*<<< orphan*/  name; void* data; int /*<<< orphan*/  size; int /*<<< orphan*/  p; int /*<<< orphan*/ * ptr; } ;
struct TYPE_14__ {int /*<<< orphan*/ * ptr; int /*<<< orphan*/  p; } ;
typedef  int /*<<< orphan*/  RList ;
typedef  TYPE_1__ RFSRoot ;
typedef  TYPE_2__ RFSFile ;
typedef  int /*<<< orphan*/  FILE ;
typedef  int /*<<< orphan*/  DIR ;

/* Variables and functions */
 int /*<<< orphan*/  SEEK_END ; 
 scalar_t__ S_ISDIR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  closedir (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  free (void*) ; 
 int /*<<< orphan*/  fseek (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ftell (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * opendir (char const*) ; 
 scalar_t__ r_file_slurp_range (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  r_fs_file_free (TYPE_2__*) ; 
 TYPE_2__* r_fs_file_new (TYPE_1__*,char const*) ; 
 int /*<<< orphan*/  r_list_append (int /*<<< orphan*/ *,TYPE_2__*) ; 
 int /*<<< orphan*/  r_list_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * r_list_new () ; 
 int /*<<< orphan*/ * r_sandbox_fopen (char const*,char*) ; 
 struct dirent* readdir (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,char const*,char const*) ; 
 int /*<<< orphan*/  stat (char*,struct stat*) ; 

__attribute__((used)) static RFSFile* fs_posix_open(RFSRoot *root, const char *path) {
	FILE *fd;
	RFSFile *file = r_fs_file_new (root, path);
	if (!file) {
		return NULL;
	}
	file->ptr = NULL;
	file->p = root->p;
	fd = r_sandbox_fopen (path, "r");
	if (fd) {
		fseek (fd, 0, SEEK_END);
		file->size = ftell (fd);
		fclose (fd);
	} else {
		r_fs_file_free (file);
		file = NULL;
	}
	return file;
}

__attribute__((used)) static bool fs_posix_read(RFSFile *file, ut64 addr, int len) {
	free (file->data);
	file->data = (void*)r_file_slurp_range (file->name, 0, len, NULL);
	return false;
}

__attribute__((used)) static void fs_posix_close(RFSFile *file) {
	//fclose (file->ptr);
}

__attribute__((used)) static RList *fs_posix_dir(RFSRoot *root, const char *path, int view /*ignored*/) {
	RList *list;
	char fullpath[4096];
	struct stat st;
#if __WINDOWS__
	WIN32_FIND_DATAW entry;
	HANDLE fh;
	wchar_t *wcpath;
	char *wctocbuff;
	wchar_t directory[MAX_PATH];
#else
	struct dirent *de;
	DIR *dir;
#endif
	list = r_list_new ();
	if (!list) {
		return NULL;
	}
#if __WINDOWS__
	wcpath = r_utf8_to_utf16 (path);
	if (!wcpath) {
		return NULL;
	}
	swprintf (directory, _countof (directory), L"%ls\\*.*", wcpath);
	fh = FindFirstFileW (directory, &entry);
	if (fh == INVALID_HANDLE_VALUE) {
		free (wcpath);
		return NULL;
	}
	do {
		if ((wctocbuff = r_utf16_to_utf8 (entry.cFileName))) {
			RFSFile *fsf = r_fs_file_new (NULL, wctocbuff);
			if (!fsf) {
				r_list_free (list);
				FindClose (fh);
				return NULL;
			}
			fsf->type = 'f';
			snprintf (fullpath, sizeof (fullpath)-1, "%s/%s", path, wctocbuff);
			if (!stat (fullpath, &st)) {
				fsf->type = S_ISDIR (st.st_mode)?'d':'f';
				fsf->time = st.st_atime;
			} else {
				fsf->type = 'f';
				fsf->time = 0;
			}
			r_list_append (list, fsf);
			free (wctocbuff);
		}

	} while (FindNextFileW (fh, &entry));
	FindClose (fh);
#else
	dir = opendir (path);
	if (!dir) {
		r_list_free (list);
		return NULL;
	}
	while ((de = readdir (dir))) {
		RFSFile *fsf = r_fs_file_new (NULL, de->d_name);
		if (!fsf) {
			r_list_free (list);
			closedir (dir);
			return NULL;
		}
		fsf->type = 'f';
		snprintf (fullpath, sizeof (fullpath)-1, "%s/%s", path, de->d_name);
		if (!stat (fullpath, &st)) {
			fsf->type = S_ISDIR (st.st_mode)?'d':'f';
			fsf->time = st.st_atime;
		} else {
			fsf->type = 'f';
			fsf->time = 0;
		}
		r_list_append (list, fsf);
	}
	closedir (dir);
#endif
	return list;
}

__attribute__((used)) static int fs_posix_mount(RFSRoot *root) {
	root->ptr = NULL; // XXX: TODO
	return true;
}

__attribute__((used)) static void fs_posix_umount(RFSRoot *root) {
	root->ptr = NULL;
}

