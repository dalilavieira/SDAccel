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
typedef  int /*<<< orphan*/  socktype ;
typedef  int socklen_t ;
typedef  int /*<<< orphan*/  on ;
typedef  int /*<<< orphan*/  BIO_ADDR ;

/* Variables and functions */
 int /*<<< orphan*/  BIO_ADDR_sockaddr (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  BIO_ADDR_sockaddr_noconst (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  BIO_ADDR_sockaddr_size (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  BIO_F_BIO_ACCEPT_EX ; 
 int /*<<< orphan*/  BIO_F_BIO_BIND ; 
 int /*<<< orphan*/  BIO_F_BIO_CONNECT ; 
 int /*<<< orphan*/  BIO_F_BIO_LISTEN ; 
 int /*<<< orphan*/  BIO_F_BIO_SOCKET ; 
 int /*<<< orphan*/  BIO_R_ACCEPT_ERROR ; 
 int /*<<< orphan*/  BIO_R_CONNECT_ERROR ; 
 int /*<<< orphan*/  BIO_R_GETTING_SOCKTYPE ; 
 int /*<<< orphan*/  BIO_R_INVALID_SOCKET ; 
 int /*<<< orphan*/  BIO_R_UNABLE_TO_BIND_SOCKET ; 
 int /*<<< orphan*/  BIO_R_UNABLE_TO_CREATE_SOCKET ; 
 int /*<<< orphan*/  BIO_R_UNABLE_TO_KEEPALIVE ; 
 int /*<<< orphan*/  BIO_R_UNABLE_TO_LISTEN_SOCKET ; 
 int /*<<< orphan*/  BIO_R_UNABLE_TO_NODELAY ; 
 int /*<<< orphan*/  BIO_R_UNABLE_TO_REUSEADDR ; 
 int BIO_SOCK_KEEPALIVE ; 
 int BIO_SOCK_NODELAY ; 
 int BIO_SOCK_NONBLOCK ; 
 int BIO_SOCK_REUSEADDR ; 
 int BIO_sock_init () ; 
 int /*<<< orphan*/  BIO_sock_should_retry (int) ; 
 int /*<<< orphan*/  BIO_socket_nbio (int,int) ; 
 int /*<<< orphan*/  BIOerr (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int INVALID_SOCKET ; 
 int /*<<< orphan*/  IPPROTO_TCP ; 
 int /*<<< orphan*/  MAX_LISTEN ; 
 int SOCK_DGRAM ; 
 int /*<<< orphan*/  SOL_SOCKET ; 
 int /*<<< orphan*/  SO_KEEPALIVE ; 
 int /*<<< orphan*/  SO_REUSEADDR ; 
 int /*<<< orphan*/  SO_TYPE ; 
 int /*<<< orphan*/  SYS_F_ACCEPT ; 
 int /*<<< orphan*/  SYS_F_BIND ; 
 int /*<<< orphan*/  SYS_F_CONNECT ; 
 int /*<<< orphan*/  SYS_F_GETSOCKOPT ; 
 int /*<<< orphan*/  SYS_F_LISTEN ; 
 int /*<<< orphan*/  SYS_F_SETSOCKOPT ; 
 int /*<<< orphan*/  SYS_F_SOCKET ; 
 int /*<<< orphan*/  SYSerr (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TCP_NODELAY ; 
 int accept (int,int /*<<< orphan*/ ,int*) ; 
 scalar_t__ bind (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ closesocket (int) ; 
 int connect (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  get_last_socket_error () ; 
 scalar_t__ getsockopt (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*,int*) ; 
 int listen (int,int /*<<< orphan*/ ) ; 
 scalar_t__ setsockopt (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,void const*,int) ; 
 int socket (int,int,int) ; 

int BIO_socket(int domain, int socktype, int protocol, int options)
{
    int sock = -1;

    if (BIO_sock_init() != 1)
        return INVALID_SOCKET;

    sock = socket(domain, socktype, protocol);
    if (sock == -1) {
        SYSerr(SYS_F_SOCKET, get_last_socket_error());
        BIOerr(BIO_F_BIO_SOCKET, BIO_R_UNABLE_TO_CREATE_SOCKET);
        return INVALID_SOCKET;
    }

    return sock;
}

int BIO_connect(int sock, const BIO_ADDR *addr, int options)
{
    const int on = 1;

    if (sock == -1) {
        BIOerr(BIO_F_BIO_CONNECT, BIO_R_INVALID_SOCKET);
        return 0;
    }

    if (!BIO_socket_nbio(sock, (options & BIO_SOCK_NONBLOCK) != 0))
        return 0;

    if (options & BIO_SOCK_KEEPALIVE) {
        if (setsockopt(sock, SOL_SOCKET, SO_KEEPALIVE,
                       (const void *)&on, sizeof(on)) != 0) {
            SYSerr(SYS_F_SETSOCKOPT, get_last_socket_error());
            BIOerr(BIO_F_BIO_CONNECT, BIO_R_UNABLE_TO_KEEPALIVE);
            return 0;
        }
    }

    if (options & BIO_SOCK_NODELAY) {
        if (setsockopt(sock, IPPROTO_TCP, TCP_NODELAY,
                       (const void *)&on, sizeof(on)) != 0) {
            SYSerr(SYS_F_SETSOCKOPT, get_last_socket_error());
            BIOerr(BIO_F_BIO_CONNECT, BIO_R_UNABLE_TO_NODELAY);
            return 0;
        }
    }

    if (connect(sock, BIO_ADDR_sockaddr(addr),
                BIO_ADDR_sockaddr_size(addr)) == -1) {
        if (!BIO_sock_should_retry(-1)) {
            SYSerr(SYS_F_CONNECT, get_last_socket_error());
            BIOerr(BIO_F_BIO_CONNECT, BIO_R_CONNECT_ERROR);
        }
        return 0;
    }
    return 1;
}

int BIO_bind(int sock, const BIO_ADDR *addr, int options)
{
# ifndef OPENSSL_SYS_WINDOWS
    int on = 1;
# endif

    if (sock == -1) {
        BIOerr(BIO_F_BIO_BIND, BIO_R_INVALID_SOCKET);
        return 0;
    }

# ifndef OPENSSL_SYS_WINDOWS
    /*
     * SO_REUSEADDR has different behavior on Windows than on
     * other operating systems, don't set it there.
     */
    if (options & BIO_SOCK_REUSEADDR) {
        if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR,
                       (const void *)&on, sizeof(on)) != 0) {
            SYSerr(SYS_F_SETSOCKOPT, get_last_socket_error());
            BIOerr(BIO_F_BIO_BIND, BIO_R_UNABLE_TO_REUSEADDR);
            return 0;
        }
    }
# endif

    if (bind(sock, BIO_ADDR_sockaddr(addr), BIO_ADDR_sockaddr_size(addr)) != 0) {
        SYSerr(SYS_F_BIND, get_last_socket_error());
        BIOerr(BIO_F_BIO_BIND, BIO_R_UNABLE_TO_BIND_SOCKET);
        return 0;
    }

    return 1;
}

int BIO_listen(int sock, const BIO_ADDR *addr, int options)
{
    int on = 1;
    int socktype;
    socklen_t socktype_len = sizeof(socktype);

    if (sock == -1) {
        BIOerr(BIO_F_BIO_LISTEN, BIO_R_INVALID_SOCKET);
        return 0;
    }

    if (getsockopt(sock, SOL_SOCKET, SO_TYPE,
                   (void *)&socktype, &socktype_len) != 0
        || socktype_len != sizeof(socktype)) {
        SYSerr(SYS_F_GETSOCKOPT, get_last_socket_error());
        BIOerr(BIO_F_BIO_LISTEN, BIO_R_GETTING_SOCKTYPE);
        return 0;
    }

    if (!BIO_socket_nbio(sock, (options & BIO_SOCK_NONBLOCK) != 0))
        return 0;

    if (options & BIO_SOCK_KEEPALIVE) {
        if (setsockopt(sock, SOL_SOCKET, SO_KEEPALIVE,
                       (const void *)&on, sizeof(on)) != 0) {
            SYSerr(SYS_F_SETSOCKOPT, get_last_socket_error());
            BIOerr(BIO_F_BIO_LISTEN, BIO_R_UNABLE_TO_KEEPALIVE);
            return 0;
        }
    }

    if (options & BIO_SOCK_NODELAY) {
        if (setsockopt(sock, IPPROTO_TCP, TCP_NODELAY,
                       (const void *)&on, sizeof(on)) != 0) {
            SYSerr(SYS_F_SETSOCKOPT, get_last_socket_error());
            BIOerr(BIO_F_BIO_LISTEN, BIO_R_UNABLE_TO_NODELAY);
            return 0;
        }
    }

# ifdef IPV6_V6ONLY
    if (BIO_ADDR_family(addr) == AF_INET6) {
        /*
         * Note: Windows default of IPV6_V6ONLY is ON, and Linux is OFF.
         * Therefore we always have to use setsockopt here.
         */
        on = options & BIO_SOCK_V6_ONLY ? 1 : 0;
        if (setsockopt(sock, IPPROTO_IPV6, IPV6_V6ONLY,
                       (const void *)&on, sizeof(on)) != 0) {
            SYSerr(SYS_F_SETSOCKOPT, get_last_socket_error());
            BIOerr(BIO_F_BIO_LISTEN, BIO_R_LISTEN_V6_ONLY);
            return 0;
        }
    }
# endif

    if (!BIO_bind(sock, addr, options))
        return 0;

    if (socktype != SOCK_DGRAM && listen(sock, MAX_LISTEN) == -1) {
        SYSerr(SYS_F_LISTEN, get_last_socket_error());
        BIOerr(BIO_F_BIO_LISTEN, BIO_R_UNABLE_TO_LISTEN_SOCKET);
        return 0;
    }

    return 1;
}

int BIO_accept_ex(int accept_sock, BIO_ADDR *addr_, int options)
{
    socklen_t len;
    int accepted_sock;
    BIO_ADDR locaddr;
    BIO_ADDR *addr = addr_ == NULL ? &locaddr : addr_;

    len = sizeof(*addr);
    accepted_sock = accept(accept_sock,
                           BIO_ADDR_sockaddr_noconst(addr), &len);
    if (accepted_sock == -1) {
        if (!BIO_sock_should_retry(accepted_sock)) {
            SYSerr(SYS_F_ACCEPT, get_last_socket_error());
            BIOerr(BIO_F_BIO_ACCEPT_EX, BIO_R_ACCEPT_ERROR);
        }
        return INVALID_SOCKET;
    }

    if (!BIO_socket_nbio(accepted_sock, (options & BIO_SOCK_NONBLOCK) != 0)) {
        closesocket(accepted_sock);
        return INVALID_SOCKET;
    }

    return accepted_sock;
}

int BIO_closesocket(int sock)
{
    if (closesocket(sock) < 0)
        return 0;
    return 1;
}

