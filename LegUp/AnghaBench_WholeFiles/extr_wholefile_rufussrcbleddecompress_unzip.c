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
typedef  int /*<<< orphan*/  uid_t ;
typedef  int /*<<< orphan*/  time_t ;
struct tm {int dummy; } ;
struct timeval {int dummy; } ;
typedef  int pid_t ;
typedef  scalar_t__ off_t ;
typedef  int /*<<< orphan*/  mode_t ;
typedef  int /*<<< orphan*/  gid_t ;
typedef  int /*<<< orphan*/  dev_t ;

/* Variables and functions */
 int /*<<< orphan*/  EBADF ; 
 int /*<<< orphan*/  EFAULT ; 
 int /*<<< orphan*/  EINTR ; 
 int /*<<< orphan*/  ENOSYS ; 
 scalar_t__ PathMatchSpecA (char const*,char const*) ; 
 int /*<<< orphan*/  SEEK_CUR ; 
 int _read (int,void*,int) ; 
 int /*<<< orphan*/  bb_copyfd_exact_size (int,int,scalar_t__) ; 
 int bb_total_rb ; 
 int /*<<< orphan*/ * bb_virtual_buf ; 
 int bb_virtual_fd ; 
 size_t bb_virtual_len ; 
 size_t bb_virtual_pos ; 
 scalar_t__* bled_cancel_request ; 
 int /*<<< orphan*/  bled_progress (int) ; 
 int /*<<< orphan*/  errno ; 
 int /*<<< orphan*/  free (void*) ; 
 scalar_t__ localtime_s (struct tm*,int /*<<< orphan*/  const*) ; 
 scalar_t__ lseek (int,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (void*,int /*<<< orphan*/ *,size_t) ; 
 void* realloc (void*,size_t) ; 

__attribute__((used)) static inline void *xrealloc(void *ptr, size_t size) {
	void *ret = realloc(ptr, size);
	if (!ret)
		free(ptr);
	return ret;
}

__attribute__((used)) static inline int link(const char *oldpath, const char *newpath) {errno = ENOSYS; return -1;}

__attribute__((used)) static inline int symlink(const char *oldpath, const char *newpath) {errno = ENOSYS; return -1;}

__attribute__((used)) static inline int chown(const char *path, uid_t owner, gid_t group) {errno = ENOSYS; return -1;}

__attribute__((used)) static inline int mknod(const char *pathname, mode_t mode, dev_t dev) {errno = ENOSYS; return -1;}

__attribute__((used)) static inline int utimes(const char *filename, const struct timeval times[2]) {errno = ENOSYS; return -1;}

__attribute__((used)) static inline int fnmatch(const char *pattern, const char *string, int flags) {return PathMatchSpecA(string, pattern)?0:1;}

__attribute__((used)) static inline pid_t wait(int* status) { *status = 4; return -1; }

__attribute__((used)) static inline int full_read(int fd, void *buf, size_t count) {
	int rb;

	if (fd < 0) {
		errno = EBADF;
		return -1;
	}
	if (buf == NULL) {
		errno = EFAULT;
		return -1;
	}
	if ((bled_cancel_request != NULL) && (*bled_cancel_request != 0)) {
		errno = EINTR;
		return -1;
	}

	if (fd == bb_virtual_fd) {
		if (bb_virtual_pos + count > bb_virtual_len)
			count = bb_virtual_len - bb_virtual_pos;
		memcpy(buf, &bb_virtual_buf[bb_virtual_pos], count);
		bb_virtual_pos += count;
		rb = (int)count;
	} else {
		rb = _read(fd, buf, (int)count);
	}
	if (rb > 0) {
		bb_total_rb += rb;
		if (bled_progress != NULL)
			bled_progress(bb_total_rb);
	}
	return rb;
}

__attribute__((used)) static inline struct tm *localtime_r(const time_t *timep, struct tm *result) {
	if (localtime_s(result, timep) != 0)
		result = NULL;
	return result;
}

__attribute__((used)) static void unzip_skip(int zip_fd, off_t skip)
{
	if (skip != 0)
		if (lseek(zip_fd, skip, SEEK_CUR) == (off_t)-1)
			bb_copyfd_exact_size(zip_fd, -1, skip);
}

