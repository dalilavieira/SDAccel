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
struct sockaddr {int dummy; } ;
typedef  int /*<<< orphan*/  socklen_t ;

/* Variables and functions */
 int /*<<< orphan*/  FD_CLOEXEC ; 
 int /*<<< orphan*/  F_SETFD ; 
 int O_CLOEXEC ; 
 int SOCK_CLOEXEC ; 
 int accept (int,struct sockaddr*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cloexec_mutex ; 
 int /*<<< orphan*/  close (int) ; 
 int fcntl (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pthread_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_unlock (int /*<<< orphan*/ *) ; 
 int socket (int,int,int) ; 

__attribute__((used)) static int set_cloexec(int fd)
{
    return fcntl(fd, F_SETFD, FD_CLOEXEC) != -1 ? 0 : -1;
}

int cloexec_accept(int socket, struct sockaddr *addr, socklen_t *addrlen)
{
    int fd;
    pthread_mutex_lock(&cloexec_mutex);

    if ((fd = accept(socket, addr, addrlen)) == -1)
        goto Exit;
    if (set_cloexec(fd) != 0) {
        close(fd);
        fd = -1;
        goto Exit;
    }

Exit:
    pthread_mutex_unlock(&cloexec_mutex);
    return fd;
}

int cloexec_pipe(int fds[2])
{
#ifdef __linux__
#ifndef _GNU_SOURCE
    extern int pipe2(int pipefd[2], int flags);
#endif
    return pipe2(fds, O_CLOEXEC);
#else
    int ret = -1;
    pthread_mutex_lock(&cloexec_mutex);

    if (pipe(fds) != 0)
        goto Exit;
    if (set_cloexec(fds[0]) != 0 || set_cloexec(fds[1]) != 0)
        goto Exit;
    ret = 0;

Exit:
    pthread_mutex_unlock(&cloexec_mutex);
    return ret;
#endif
}

int cloexec_socket(int domain, int type, int protocol)
{
#ifdef __linux__
    return socket(domain, type | SOCK_CLOEXEC, protocol);
#else
    int fd = -1;
    pthread_mutex_lock(&cloexec_mutex);

    if ((fd = socket(domain, type, protocol)) == -1)
        goto Exit;
    if (set_cloexec(fd) != 0) {
        close(fd);
        fd = -1;
        goto Exit;
    }

Exit:
    pthread_mutex_unlock(&cloexec_mutex);
    return fd;
#endif
}

