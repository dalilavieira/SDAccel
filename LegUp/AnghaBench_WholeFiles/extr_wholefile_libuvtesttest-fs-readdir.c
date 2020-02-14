#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_27__   TYPE_2__ ;
typedef  struct TYPE_26__   TYPE_22__ ;
typedef  struct TYPE_25__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uv_handle_t ;
struct TYPE_25__ {scalar_t__ fs_type; scalar_t__ result; TYPE_2__* ptr; } ;
typedef  TYPE_1__ uv_fs_t ;
struct TYPE_27__ {void* nentries; TYPE_22__* dirents; } ;
typedef  TYPE_2__ uv_dir_t ;
struct TYPE_26__ {scalar_t__ type; int /*<<< orphan*/  name; } ;

/* Variables and functions */
 void* ARRAY_SIZE (TYPE_22__*) ; 
 int /*<<< orphan*/  ASSERT (int) ; 
 scalar_t__ UV_DIRENT_UNKNOWN ; 
 scalar_t__ UV_ENOENT ; 
 scalar_t__ UV_ENOTDIR ; 
 scalar_t__ UV_FS_CLOSEDIR ; 
 scalar_t__ UV_FS_OPENDIR ; 
 scalar_t__ UV_FS_READDIR ; 
 TYPE_1__ closedir_req ; 
 TYPE_22__* dirents ; 
 int /*<<< orphan*/  empty_closedir_cb_count ; 
 int /*<<< orphan*/  empty_opendir_cb_count ; 
 int /*<<< orphan*/  file_opendir_cb_count ; 
 int /*<<< orphan*/  non_empty_closedir_cb_count ; 
 int /*<<< orphan*/  non_empty_opendir_cb_count ; 
 int non_empty_readdir_cb_count ; 
 int /*<<< orphan*/  non_existing_opendir_cb_count ; 
 TYPE_1__ opendir_req ; 
 TYPE_1__ readdir_req ; 
 scalar_t__ strcmp (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_default_loop () ; 
 int uv_fs_closedir (int /*<<< orphan*/ ,TYPE_1__*,TYPE_2__*,void (*) (TYPE_1__*)) ; 
 int uv_fs_readdir (int /*<<< orphan*/ ,TYPE_1__*,TYPE_2__*,void (*) (TYPE_1__*)) ; 
 int /*<<< orphan*/  uv_fs_req_cleanup (TYPE_1__*) ; 
 int /*<<< orphan*/  uv_fs_rmdir (int /*<<< orphan*/ *,TYPE_1__*,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_fs_unlink (int /*<<< orphan*/ *,TYPE_1__*,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_is_closing (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static void cleanup_test_files(void) {
  uv_fs_t req;

  uv_fs_unlink(NULL, &req, "test_dir/file1", NULL);
  uv_fs_req_cleanup(&req);
  uv_fs_unlink(NULL, &req, "test_dir/file2", NULL);
  uv_fs_req_cleanup(&req);
  uv_fs_rmdir(NULL, &req, "test_dir/test_subdir", NULL);
  uv_fs_req_cleanup(&req);
  uv_fs_rmdir(NULL, &req, "test_dir", NULL);
  uv_fs_req_cleanup(&req);
}

__attribute__((used)) static void empty_closedir_cb(uv_fs_t* req) {
  ASSERT(req == &closedir_req);
  ASSERT(req->fs_type == UV_FS_CLOSEDIR);
  ASSERT(req->result == 0);
  ++empty_closedir_cb_count;
  uv_fs_req_cleanup(req);
}

__attribute__((used)) static void empty_readdir_cb(uv_fs_t* req) {
  uv_dir_t* dir;
  int r;

  ASSERT(req == &readdir_req);
  ASSERT(req->fs_type == UV_FS_READDIR);
  ASSERT(req->result == 0);
  dir = req->ptr;
  r = uv_fs_closedir(uv_default_loop(),
                     &closedir_req,
                     dir,
                     empty_closedir_cb);
  ASSERT(r == 0);
  uv_fs_req_cleanup(req);
}

__attribute__((used)) static void empty_opendir_cb(uv_fs_t* req) {
  uv_dir_t* dir;
  int r;

  ASSERT(req == &opendir_req);
  ASSERT(req->fs_type == UV_FS_OPENDIR);
  ASSERT(req->result == 0);
  ASSERT(req->ptr != NULL);
  dir = req->ptr;
  dir->dirents = dirents;
  dir->nentries = ARRAY_SIZE(dirents);
  r = uv_fs_readdir(uv_default_loop(),
                    &readdir_req,
                    dir,
                    empty_readdir_cb);
  ASSERT(r == 0);
  uv_fs_req_cleanup(req);
  ++empty_opendir_cb_count;
}

__attribute__((used)) static void non_existing_opendir_cb(uv_fs_t* req) {
  ASSERT(req == &opendir_req);
  ASSERT(req->fs_type == UV_FS_OPENDIR);
  ASSERT(req->result == UV_ENOENT);
  ASSERT(req->ptr == NULL);

  uv_fs_req_cleanup(req);
  ++non_existing_opendir_cb_count;
}

__attribute__((used)) static void file_opendir_cb(uv_fs_t* req) {
  ASSERT(req == &opendir_req);
  ASSERT(req->fs_type == UV_FS_OPENDIR);
  ASSERT(req->result == UV_ENOTDIR);
  ASSERT(req->ptr == NULL);

  uv_fs_req_cleanup(req);
  ++file_opendir_cb_count;
}

__attribute__((used)) static void non_empty_closedir_cb(uv_fs_t* req) {
  ASSERT(req == &closedir_req);
  ASSERT(req->result == 0);
  uv_fs_req_cleanup(req);
  ++non_empty_closedir_cb_count;
}

__attribute__((used)) static void non_empty_readdir_cb(uv_fs_t* req) {
  uv_dir_t* dir;

  ASSERT(req == &readdir_req);
  ASSERT(req->fs_type == UV_FS_READDIR);
  dir = req->ptr;

  if (req->result == 0) {
    uv_fs_req_cleanup(req);
    ASSERT(non_empty_readdir_cb_count == 3);
    uv_fs_closedir(uv_default_loop(),
                   &closedir_req,
                   dir,
                   non_empty_closedir_cb);
  } else {
    ASSERT(req->result == 1);
    ASSERT(dir->dirents == dirents);
    ASSERT(strcmp(dirents[0].name, "file1") == 0 ||
           strcmp(dirents[0].name, "file2") == 0 ||
           strcmp(dirents[0].name, "test_subdir") == 0);
#ifdef HAVE_DIRENT_TYPES
    if (!strcmp(dirents[0].name, "test_subdir"))
      ASSERT(dirents[0].type == UV_DIRENT_DIR);
    else
      ASSERT(dirents[0].type == UV_DIRENT_FILE);
#else
    ASSERT(dirents[0].type == UV_DIRENT_UNKNOWN);
#endif /* HAVE_DIRENT_TYPES */

    ++non_empty_readdir_cb_count;
    uv_fs_req_cleanup(req);
    dir->dirents = dirents;
    dir->nentries = ARRAY_SIZE(dirents);
    uv_fs_readdir(uv_default_loop(),
                  &readdir_req,
                  dir,
                  non_empty_readdir_cb);
  }
}

__attribute__((used)) static void non_empty_opendir_cb(uv_fs_t* req) {
  uv_dir_t* dir;
  int r;

  ASSERT(req == &opendir_req);
  ASSERT(req->fs_type == UV_FS_OPENDIR);
  ASSERT(req->result == 0);
  ASSERT(req->ptr != NULL);

  dir = req->ptr;
  dir->dirents = dirents;
  dir->nentries = ARRAY_SIZE(dirents);

  r = uv_fs_readdir(uv_default_loop(),
                    &readdir_req,
                    dir,
                    non_empty_readdir_cb);
  ASSERT(r == 0);
  uv_fs_req_cleanup(req);
  ++non_empty_opendir_cb_count;
}

