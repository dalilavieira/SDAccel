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
typedef  int uint32_t ;
typedef  int /*<<< orphan*/  buf ;

/* Variables and functions */
 int EXIT_FAILURE ; 
 int EXIT_SUCCESS ; 
 unsigned int FS_IMMUTABLE_FL ; 
 int /*<<< orphan*/  FS_IOC_GETFLAGS ; 
 int /*<<< orphan*/  FS_IOC_SETFLAGS ; 
 int O_CREAT ; 
 int /*<<< orphan*/  O_RDONLY ; 
 int O_WRONLY ; 
 int /*<<< orphan*/  close (int) ; 
 int errno ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 int ioctl (int,int /*<<< orphan*/ ,unsigned int*) ; 
 int open (char const*,int,...) ; 
 int /*<<< orphan*/  perror (char*) ; 
 int read (int,char*,int) ; 
 int /*<<< orphan*/  stderr ; 
 scalar_t__ unlink (char const*) ; 
 int write (int,char*,int) ; 

__attribute__((used)) static int set_immutable(const char *path, int immutable)
{
	unsigned int flags;
	int fd;
	int rc;
	int error;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return fd;

	rc = ioctl(fd, FS_IOC_GETFLAGS, &flags);
	if (rc < 0) {
		error = errno;
		close(fd);
		errno = error;
		return rc;
	}

	if (immutable)
		flags |= FS_IMMUTABLE_FL;
	else
		flags &= ~FS_IMMUTABLE_FL;

	rc = ioctl(fd, FS_IOC_SETFLAGS, &flags);
	error = errno;
	close(fd);
	errno = error;
	return rc;
}

__attribute__((used)) static int get_immutable(const char *path)
{
	unsigned int flags;
	int fd;
	int rc;
	int error;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return fd;

	rc = ioctl(fd, FS_IOC_GETFLAGS, &flags);
	if (rc < 0) {
		error = errno;
		close(fd);
		errno = error;
		return rc;
	}
	close(fd);
	if (flags & FS_IMMUTABLE_FL)
		return 1;
	return 0;
}

int main(int argc, char **argv)
{
	const char *path;
	char buf[5];
	int fd, rc;

	if (argc < 2) {
		fprintf(stderr, "usage: %s <path>\n", argv[0]);
		return EXIT_FAILURE;
	}

	path = argv[1];

	/* attributes: EFI_VARIABLE_NON_VOLATILE |
	 *		EFI_VARIABLE_BOOTSERVICE_ACCESS |
	 *		EFI_VARIABLE_RUNTIME_ACCESS
	 */
	*(uint32_t *)buf = 0x7;
	buf[4] = 0;

	/* create a test variable */
	fd = open(path, O_WRONLY | O_CREAT, 0600);
	if (fd < 0) {
		perror("open(O_WRONLY)");
		return EXIT_FAILURE;
	}

	rc = write(fd, buf, sizeof(buf));
	if (rc != sizeof(buf)) {
		perror("write");
		return EXIT_FAILURE;
	}

	close(fd);

	rc = get_immutable(path);
	if (rc < 0) {
		perror("ioctl(FS_IOC_GETFLAGS)");
		return EXIT_FAILURE;
	} else if (rc) {
		rc = set_immutable(path, 0);
		if (rc < 0) {
			perror("ioctl(FS_IOC_SETFLAGS)");
			return EXIT_FAILURE;
		}
	}

	fd = open(path, O_RDONLY);
	if (fd < 0) {
		perror("open");
		return EXIT_FAILURE;
	}

	if (unlink(path) < 0) {
		perror("unlink");
		return EXIT_FAILURE;
	}

	rc = read(fd, buf, sizeof(buf));
	if (rc > 0) {
		fprintf(stderr, "reading from an unlinked variable "
				"shouldn't be possible\n");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

