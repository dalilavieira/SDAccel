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
struct termios {int dummy; } ;

/* Variables and functions */
 int ENOTTY ; 
 int EXIT_SUCCESS ; 
 int O_CREAT ; 
 int O_EXCL ; 
 int /*<<< orphan*/  O_RDONLY ; 
 int O_WRONLY ; 
 int /*<<< orphan*/  SIGABRT ; 
 int STDIN_FILENO ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  atexit (void (*) ()) ; 
 int /*<<< orphan*/  close (int) ; 
 int errno ; 
 int open (char const*,int,...) ; 
 int /*<<< orphan*/  puts (char*) ; 
 int /*<<< orphan*/  signal (int /*<<< orphan*/ ,void (*) ()) ; 
 int strlen (char const*) ; 
 int tcgetattr (int,struct termios*) ; 
 int tcsetattr (int,int /*<<< orphan*/ ,struct termios*) ; 
 int /*<<< orphan*/  unlink (char*) ; 
 int write (int,char const*,int) ; 

__attribute__((used)) static void create_file(const char *path, const char *buffer, int mode) {
  int fd = open(path, O_WRONLY | O_CREAT | O_EXCL, mode);
  assert(fd >= 0);

  int err = write(fd, buffer, sizeof(char) * strlen(buffer));
  assert(err ==  (sizeof(char) * strlen(buffer)));

  close(fd);
}

void setup() {
	create_file("test.txt", "abcdefg", 0666);
}

void cleanup() {
	unlink("test.txt");
}

void test() {
	struct termios tc;
	int ret;
	int fd;

	fd = open("test.txt", O_RDONLY);

	ret = tcgetattr(fd, &tc);
	assert(ret == -1);
	assert(errno = ENOTTY);

	ret = tcgetattr(STDIN_FILENO, &tc);
	assert(!ret);

	ret = tcsetattr(fd, 0, &tc);
	assert(ret == -1);
	assert(errno = ENOTTY);

	ret = tcsetattr(STDIN_FILENO, 0, &tc);
	assert(!ret);

	close(fd);

	puts("success");
}

int main() {
  atexit(cleanup);
  signal(SIGABRT, cleanup);
  setup();
  test();
  return EXIT_SUCCESS;
}

