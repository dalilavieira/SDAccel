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
typedef  int /*<<< orphan*/  uint32_t ;
struct uv__statx {int dummy; } ;
struct uv__mmsghdr {int dummy; } ;
struct timespec {int dummy; } ;
struct sockaddr {int dummy; } ;
struct iovec {int dummy; } ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  socklen_t ;
typedef  int /*<<< orphan*/  int64_t ;
typedef  int /*<<< orphan*/  int32_t ;

/* Variables and functions */
 int ENOSYS ; 
 int errno ; 

int uv__accept4(int fd, struct sockaddr* addr, socklen_t* addrlen, int flags) {
#if defined(__i386__)
  unsigned long args[4];
  int r;

  args[0] = (unsigned long) fd;
  args[1] = (unsigned long) addr;
  args[2] = (unsigned long) addrlen;
  args[3] = (unsigned long) flags;

  r = syscall(__NR_socketcall, 18 /* SYS_ACCEPT4 */, args);

  /* socketcall() raises EINVAL when SYS_ACCEPT4 is not supported but so does
   * a bad flags argument. Try to distinguish between the two cases.
   */
  if (r == -1)
    if (errno == EINVAL)
      if ((flags & ~(UV__SOCK_CLOEXEC|UV__SOCK_NONBLOCK)) == 0)
        errno = ENOSYS;

  return r;
#elif defined(__NR_accept4)
  return syscall(__NR_accept4, fd, addr, addrlen, flags);
#else
  return errno = ENOSYS, -1;
#endif
}

int uv__eventfd(unsigned int count) {
#if defined(__NR_eventfd)
  return syscall(__NR_eventfd, count);
#else
  return errno = ENOSYS, -1;
#endif
}

int uv__eventfd2(unsigned int count, int flags) {
#if defined(__NR_eventfd2)
  return syscall(__NR_eventfd2, count, flags);
#else
  return errno = ENOSYS, -1;
#endif
}

int uv__inotify_init(void) {
#if defined(__NR_inotify_init)
  return syscall(__NR_inotify_init);
#else
  return errno = ENOSYS, -1;
#endif
}

int uv__inotify_init1(int flags) {
#if defined(__NR_inotify_init1)
  return syscall(__NR_inotify_init1, flags);
#else
  return errno = ENOSYS, -1;
#endif
}

int uv__inotify_add_watch(int fd, const char* path, uint32_t mask) {
#if defined(__NR_inotify_add_watch)
  return syscall(__NR_inotify_add_watch, fd, path, mask);
#else
  return errno = ENOSYS, -1;
#endif
}

int uv__inotify_rm_watch(int fd, int32_t wd) {
#if defined(__NR_inotify_rm_watch)
  return syscall(__NR_inotify_rm_watch, fd, wd);
#else
  return errno = ENOSYS, -1;
#endif
}

int uv__pipe2(int pipefd[2], int flags) {
#if defined(__NR_pipe2)
  int result;
  result = syscall(__NR_pipe2, pipefd, flags);
#if MSAN_ACTIVE
  if (!result)
    __msan_unpoison(pipefd, sizeof(int[2]));
#endif
  return result;
#else
  return errno = ENOSYS, -1;
#endif
}

int uv__sendmmsg(int fd,
                 struct uv__mmsghdr* mmsg,
                 unsigned int vlen,
                 unsigned int flags) {
#if defined(__NR_sendmmsg)
  return syscall(__NR_sendmmsg, fd, mmsg, vlen, flags);
#else
  return errno = ENOSYS, -1;
#endif
}

int uv__recvmmsg(int fd,
                 struct uv__mmsghdr* mmsg,
                 unsigned int vlen,
                 unsigned int flags,
                 struct timespec* timeout) {
#if defined(__NR_recvmmsg)
  return syscall(__NR_recvmmsg, fd, mmsg, vlen, flags, timeout);
#else
  return errno = ENOSYS, -1;
#endif
}

ssize_t uv__preadv(int fd, const struct iovec *iov, int iovcnt, int64_t offset) {
#if defined(__NR_preadv)
  return syscall(__NR_preadv, fd, iov, iovcnt, (long)offset, (long)(offset >> 32));
#else
  return errno = ENOSYS, -1;
#endif
}

ssize_t uv__pwritev(int fd, const struct iovec *iov, int iovcnt, int64_t offset) {
#if defined(__NR_pwritev)
  return syscall(__NR_pwritev, fd, iov, iovcnt, (long)offset, (long)(offset >> 32));
#else
  return errno = ENOSYS, -1;
#endif
}

int uv__dup3(int oldfd, int newfd, int flags) {
#if defined(__NR_dup3)
  return syscall(__NR_dup3, oldfd, newfd, flags);
#else
  return errno = ENOSYS, -1;
#endif
}

int uv__statx(int dirfd,
              const char* path,
              int flags,
              unsigned int mask,
              struct uv__statx* statxbuf) {
#if defined(__NR_statx)
  return syscall(__NR_statx, dirfd, path, flags, mask, statxbuf);
#else
  return errno = ENOSYS, -1;
#endif
}

