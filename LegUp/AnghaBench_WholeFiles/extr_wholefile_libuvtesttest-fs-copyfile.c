#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uv_handle_t ;
struct TYPE_10__ {scalar_t__ st_size; scalar_t__ st_mode; } ;
struct TYPE_11__ {scalar_t__ fs_type; scalar_t__ result; TYPE_1__ statbuf; int /*<<< orphan*/  path; } ;
typedef  TYPE_2__ uv_fs_t ;
typedef  int uv_file ;
typedef  int /*<<< orphan*/  uv_buf_t ;
typedef  scalar_t__ uint64_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int /*<<< orphan*/  FATAL (char*) ; 
 int O_CREAT ; 
 int O_TRUNC ; 
 int O_WRONLY ; 
 int S_IRUSR ; 
 int S_IWUSR ; 
 scalar_t__ UV_FS_COPYFILE ; 
 int /*<<< orphan*/  dst ; 
 int /*<<< orphan*/  result_check_count ; 
 int /*<<< orphan*/  uv_buf_init (char*,int) ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int uv_fs_close (int /*<<< orphan*/ *,TYPE_2__*,int,int /*<<< orphan*/ *) ; 
 int uv_fs_open (int /*<<< orphan*/ *,TYPE_2__*,char const*,int,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_fs_req_cleanup (TYPE_2__*) ; 
 int uv_fs_stat (int /*<<< orphan*/ *,TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int uv_fs_write (int /*<<< orphan*/ *,TYPE_2__*,int,int /*<<< orphan*/ *,int,unsigned int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_is_closing (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static void fail_cb(uv_fs_t* req) {
  FATAL("fail_cb should not have been called");
}

__attribute__((used)) static void handle_result(uv_fs_t* req) {
  uv_fs_t stat_req;
  uint64_t size;
  uint64_t mode;
  int r;

  ASSERT(req->fs_type == UV_FS_COPYFILE);
  ASSERT(req->result == 0);

  /* Verify that the file size and mode are the same. */
  r = uv_fs_stat(NULL, &stat_req, req->path, NULL);
  ASSERT(r == 0);
  size = stat_req.statbuf.st_size;
  mode = stat_req.statbuf.st_mode;
  uv_fs_req_cleanup(&stat_req);
  r = uv_fs_stat(NULL, &stat_req, dst, NULL);
  ASSERT(r == 0);
  ASSERT(stat_req.statbuf.st_size == size);
  ASSERT(stat_req.statbuf.st_mode == mode);
  uv_fs_req_cleanup(&stat_req);
  uv_fs_req_cleanup(req);
  result_check_count++;
}

__attribute__((used)) static void touch_file(const char* name, unsigned int size) {
  uv_file file;
  uv_fs_t req;
  uv_buf_t buf;
  int r;
  unsigned int i;

  r = uv_fs_open(NULL, &req, name, O_WRONLY | O_CREAT | O_TRUNC,
                 S_IWUSR | S_IRUSR, NULL);
  uv_fs_req_cleanup(&req);
  ASSERT(r >= 0);
  file = r;

  buf = uv_buf_init("a", 1);

  /* Inefficient but simple. */
  for (i = 0; i < size; i++) {
    r = uv_fs_write(NULL, &req, file, &buf, 1, i, NULL);
    uv_fs_req_cleanup(&req);
    ASSERT(r >= 0);
  }

  r = uv_fs_close(NULL, &req, file, NULL);
  uv_fs_req_cleanup(&req);
  ASSERT(r == 0);
}

