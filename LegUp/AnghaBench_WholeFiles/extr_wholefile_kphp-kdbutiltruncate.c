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
struct stat {long long st_size; int /*<<< orphan*/  st_mode; } ;
struct flock {int l_type; scalar_t__ l_len; scalar_t__ l_start; int /*<<< orphan*/  l_whence; } ;

/* Variables and functions */
 int /*<<< orphan*/  F_SETLK ; 
 int F_WRLCK ; 
 int /*<<< orphan*/  O_WRONLY ; 
 int /*<<< orphan*/  SEEK_SET ; 
 int /*<<< orphan*/  S_ISREG (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  close (int) ; 
 int /*<<< orphan*/  exit (int) ; 
 scalar_t__ fcntl (int,int /*<<< orphan*/ ,struct flock*) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 scalar_t__ fstat (int,struct stat*) ; 
 scalar_t__ ftruncate (int,long long) ; 
 int open (char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stderr ; 
 long long strtoll (char const*,char**,int /*<<< orphan*/ ) ; 

int lock_whole_file (int fd, int mode) {
  static struct flock L;
  L.l_type = mode;
  L.l_whence = SEEK_SET;
  L.l_start = 0;
  L.l_len = 0;
  if (fcntl (fd, F_SETLK, &L) < 0) {
    fprintf (stderr, "cannot lock file %d: %m\n", fd);
    return -1;
  }
  return 1;
}

void usage (void) {
  fprintf (stderr, "usage: truncate <filename> <truncate-position>\n");
  exit (2);
}

int main (int argc, const char *argv[]) {
  char *end;
  struct stat st;
  int fd;
     
  if (argc != 3) {
    usage();
    return 2;
  }
  long long pos = strtoll (argv[2], &end, 0);
  if (!end || *end || !*argv[2]) {
    usage();
    return 2;
  }
  fd = open (argv[1], O_WRONLY);
  if (fd < 0) {
    fprintf (stderr, "cannot open file %s: %m\n", argv[1]);
    return 1;
  }
  if (fstat (fd, &st) < 0) {
    fprintf (stderr, "cannot stat file %s: %m\n", argv[1]);
    return 1;
  }
  if (!S_ISREG(st.st_mode)) {
    fprintf (stderr, "%s is not a regular file\n", argv[1]);
    return 1;
  }
  if (pos >= st.st_size) {
    fprintf (stderr, "truncate position %lld after end of file\n", pos);
    return 2;
  }
  if (pos < -st.st_size) {
    fprintf (stderr, "truncate position %lld before start of file\n", pos);
    return 2;
  }
  if (pos < 0) {
    pos += st.st_size;
  }
  if (lock_whole_file (fd, F_WRLCK) <= 0) {
    return 1;
  }
  if (ftruncate (fd, pos) < 0) {
    fprintf (stderr, "cannot truncate file %s at position %lld: %m\n", argv[1], pos);
  }
  close (fd);
  return 0;
}

