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
struct utimbuf {int member_0; int member_1; } ;
struct stat {int st_dev; int st_ino; int st_nlink; scalar_t__ st_rdev; int st_size; int st_atime; int st_mtime; int st_ctime; int /*<<< orphan*/  st_mode; } ;
typedef  int /*<<< orphan*/  s ;

/* Variables and functions */
 int EXIT_SUCCESS ; 
 int O_CREAT ; 
 int O_EXCL ; 
 int /*<<< orphan*/  O_RDONLY ; 
 int O_WRONLY ; 
 int /*<<< orphan*/  SIGABRT ; 
 int S_ISCHR (int /*<<< orphan*/ ) ; 
 int S_ISDIR (int /*<<< orphan*/ ) ; 
 int S_ISLNK (int /*<<< orphan*/ ) ; 
 int S_ISREG (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  atexit (void (*) ()) ; 
 int /*<<< orphan*/  close (int) ; 
 int fstat (int,struct stat*) ; 
 int lstat (char*,struct stat*) ; 
 scalar_t__ makedev (int,int) ; 
 int /*<<< orphan*/  memset (struct stat*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mkdir (char*,int) ; 
 int open (char const*,int,...) ; 
 int /*<<< orphan*/  puts (char*) ; 
 int /*<<< orphan*/  rmdir (char*) ; 
 int /*<<< orphan*/  signal (int /*<<< orphan*/ ,void (*) ()) ; 
 int stat (char*,struct stat*) ; 
 int strlen (char const*) ; 
 int /*<<< orphan*/  symlink (char*,char*) ; 
 int /*<<< orphan*/  unlink (char*) ; 
 int /*<<< orphan*/  utime (char*,struct utimbuf*) ; 
 int write (int,char const*,int) ; 

void create_file(const char *path, const char *buffer, int mode) {
  int fd = open(path, O_WRONLY | O_CREAT | O_EXCL, mode);
  assert(fd >= 0);

  int err = write(fd, buffer, sizeof(char) * strlen(buffer));
  assert(err ==  (sizeof(char) * strlen(buffer)));

  close(fd);
}

void setup() {
  struct utimbuf t = {1200000000, 1200000000};
  
  mkdir("folder", 0777);
  create_file("folder/file", "abcdef", 0777);
  symlink("file", "folder/file-link");

  utime("folder/file", &t);
  utime("folder", &t);
}

void cleanup() {
  unlink("folder/file");
  unlink("folder/file-link");
  rmdir("folder");
}

void test() {
  int err;
  struct stat s;

  // stat a folder
  memset(&s, 0, sizeof(s));
  err = stat("folder", &s);
  assert(!err);
  assert(s.st_dev);
  assert(s.st_ino);
  assert(S_ISDIR(s.st_mode));
  assert(s.st_nlink);
  assert(s.st_rdev == 0);
  assert(s.st_size);
  assert(s.st_atime == 1200000000);
  assert(s.st_mtime == 1200000000);
  assert(s.st_ctime);
#ifdef __EMSCRIPTEN__
  assert(s.st_blksize == 4096);
  assert(s.st_blocks == 1);
#endif

  // stat a file
  memset(&s, 0, sizeof(s));
  err = stat("folder/file", &s);
  assert(!err);
  assert(s.st_dev);
  assert(s.st_ino);
  assert(S_ISREG(s.st_mode));
  assert(s.st_nlink);
  assert(s.st_rdev == 0);
  assert(s.st_size == 6);
  assert(s.st_atime == 1200000000);
  assert(s.st_mtime == 1200000000);
  assert(s.st_ctime);
#ifdef __EMSCRIPTEN__
  assert(s.st_blksize == 4096);
  assert(s.st_blocks == 1);
#endif

  // fstat a file (should match file stat from above)
  memset(&s, 0, sizeof(s));
  err = fstat(open("folder/file", O_RDONLY), &s);
  assert(!err);
  assert(s.st_dev);
  assert(s.st_ino);
  assert(S_ISREG(s.st_mode));
  assert(s.st_nlink);
  assert(s.st_rdev == 0);
  assert(s.st_size == 6);
  assert(s.st_atime == 1200000000);
  assert(s.st_mtime == 1200000000);
  assert(s.st_ctime);
#ifdef __EMSCRIPTEN__
  assert(s.st_blksize == 4096);
  assert(s.st_blocks == 1);
#endif

  // stat a device
  memset(&s, 0, sizeof(s));
  err = stat("/dev/null", &s);
  assert(!err);
  assert(s.st_dev);
  assert(s.st_ino);
  assert(S_ISCHR(s.st_mode));
  assert(s.st_nlink);
#ifndef __APPLE__
  // mac uses makedev(3, 2) for /dev/null
  assert(s.st_rdev == makedev(1, 3));
#endif
  assert(!s.st_size);
  assert(s.st_atime);
  assert(s.st_mtime);
  assert(s.st_ctime);
#ifdef __EMSCRIPTEN__
  assert(s.st_blksize == 4096);
  assert(s.st_blocks == 0);
#endif

  // stat a link (should match the file stat from above)
  memset(&s, 0, sizeof(s));
  err = stat("folder/file-link", &s);
  assert(!err);
  assert(s.st_dev);
  assert(s.st_ino);
  assert(S_ISREG(s.st_mode));
  assert(s.st_nlink);
  assert(s.st_rdev == 0);
  assert(s.st_size == 6);
  assert(s.st_atime == 1200000000);
  assert(s.st_mtime == 1200000000);
  assert(s.st_ctime);
#ifdef __EMSCRIPTEN__
  assert(s.st_blksize == 4096);
  assert(s.st_blocks == 1);
#endif

  // lstat a link (should NOT match the file stat from above)
  memset(&s, 0, sizeof(s));
  err = lstat("folder/file-link", &s);
  assert(!err);
  assert(s.st_dev);
  assert(s.st_ino);
  assert(S_ISLNK(s.st_mode));
  assert(s.st_nlink);
  assert(s.st_rdev == 0);
  assert(s.st_size == 4);  // strlen("file")
  assert(s.st_atime != 1200000000);  // should NOT match the utime call we did for dir/file
  assert(s.st_mtime != 1200000000);
  assert(s.st_ctime);
#ifdef __EMSCRIPTEN__
  assert(s.st_blksize == 4096);
  assert(s.st_blocks == 1);
#endif

  puts("success");
}

int main() {
  atexit(cleanup);
  signal(SIGABRT, cleanup);
  setup();
  test();
  return EXIT_SUCCESS;
}

