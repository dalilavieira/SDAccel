#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int const uint16_t ;
struct sockaddr_storage {int dummy; } ;
struct sockaddr_in6 {int sin6_family; void* sin6_port; int /*<<< orphan*/  sin6_addr; } ;
struct TYPE_3__ {void* s_addr; } ;
struct sockaddr_in {int sin_family; void* sin_port; TYPE_1__ sin_addr; } ;
struct sockaddr {int dummy; } ;
struct TYPE_4__ {int fd; } ;
struct epoll_event {TYPE_2__ data; int /*<<< orphan*/  events; } ;
typedef  int /*<<< orphan*/  socklen_t ;
typedef  int /*<<< orphan*/  saddr ;
typedef  int /*<<< orphan*/  opt ;
typedef  int /*<<< orphan*/  daddr ;
typedef  int /*<<< orphan*/  buf ;
typedef  int /*<<< orphan*/  addr ;

/* Variables and functions */
#define  AF_INET 129 
#define  AF_INET6 128 
 int /*<<< orphan*/  EPOLLIN ; 
 int /*<<< orphan*/  EPOLL_CTL_ADD ; 
 int /*<<< orphan*/  INADDR_ANY ; 
 int /*<<< orphan*/  INADDR_LOOPBACK ; 
 int /*<<< orphan*/  PORT ; 
 int SOCK_DGRAM ; 
 int SOCK_STREAM ; 
 int /*<<< orphan*/  SOL_SOCKET ; 
 int /*<<< orphan*/  SO_DOMAIN ; 
 int /*<<< orphan*/  SO_REUSEPORT ; 
 int accept (int,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ bind (int,struct sockaddr*,int) ; 
 int /*<<< orphan*/  close (int) ; 
 scalar_t__ connect (int,struct sockaddr*,int) ; 
 int epoll_create (int) ; 
 scalar_t__ epoll_ctl (int,int /*<<< orphan*/ ,int,struct epoll_event*) ; 
 int epoll_wait (int,struct epoll_event*,int,int) ; 
 int /*<<< orphan*/  errno ; 
 int /*<<< orphan*/  error (int,int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*) ; 
 scalar_t__ getsockopt (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int const*,int /*<<< orphan*/ *) ; 
 void* htonl (int /*<<< orphan*/ ) ; 
 void* htons (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  in6addr_any ; 
 scalar_t__ listen (int,int) ; 
 int recv (int,char*,int,int /*<<< orphan*/ ) ; 
 scalar_t__ send (int,char*,int,int /*<<< orphan*/ ) ; 
 scalar_t__ setsockopt (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*,int) ; 
 int socket (int const,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stderr ; 

__attribute__((used)) static void build_rcv_fd(int family, int proto, int *rcv_fds, int count)
{
	struct sockaddr_storage addr;
	struct sockaddr_in  *addr4;
	struct sockaddr_in6 *addr6;
	int opt, i;

	switch (family) {
	case AF_INET:
		addr4 = (struct sockaddr_in *)&addr;
		addr4->sin_family = AF_INET;
		addr4->sin_addr.s_addr = htonl(INADDR_ANY);
		addr4->sin_port = htons(PORT);
		break;
	case AF_INET6:
		addr6 = (struct sockaddr_in6 *)&addr;
		addr6->sin6_family = AF_INET6;
		addr6->sin6_addr = in6addr_any;
		addr6->sin6_port = htons(PORT);
		break;
	default:
		error(1, 0, "Unsupported family %d", family);
	}

	for (i = 0; i < count; ++i) {
		rcv_fds[i] = socket(family, proto, 0);
		if (rcv_fds[i] < 0)
			error(1, errno, "failed to create receive socket");

		opt = 1;
		if (setsockopt(rcv_fds[i], SOL_SOCKET, SO_REUSEPORT, &opt,
			       sizeof(opt)))
			error(1, errno, "failed to set SO_REUSEPORT");

		if (bind(rcv_fds[i], (struct sockaddr *)&addr, sizeof(addr)))
			error(1, errno, "failed to bind receive socket");

		if (proto == SOCK_STREAM && listen(rcv_fds[i], 10))
			error(1, errno, "failed to listen on receive port");
	}
}

__attribute__((used)) static void send_from_v4(int proto)
{
	struct sockaddr_in  saddr, daddr;
	int fd;

	saddr.sin_family = AF_INET;
	saddr.sin_addr.s_addr = htonl(INADDR_ANY);
	saddr.sin_port = 0;

	daddr.sin_family = AF_INET;
	daddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	daddr.sin_port = htons(PORT);

	fd = socket(AF_INET, proto, 0);
	if (fd < 0)
		error(1, errno, "failed to create send socket");

	if (bind(fd, (struct sockaddr *)&saddr, sizeof(saddr)))
		error(1, errno, "failed to bind send socket");

	if (connect(fd, (struct sockaddr *)&daddr, sizeof(daddr)))
		error(1, errno, "failed to connect send socket");

	if (send(fd, "a", 1, 0) < 0)
		error(1, errno, "failed to send message");

	close(fd);
}

__attribute__((used)) static int receive_once(int epfd, int proto)
{
	struct epoll_event ev;
	int i, fd;
	char buf[8];

	i = epoll_wait(epfd, &ev, 1, -1);
	if (i < 0)
		error(1, errno, "epoll_wait failed");

	if (proto == SOCK_STREAM) {
		fd = accept(ev.data.fd, NULL, NULL);
		if (fd < 0)
			error(1, errno, "failed to accept");
		i = recv(fd, buf, sizeof(buf), 0);
		close(fd);
	} else {
		i = recv(ev.data.fd, buf, sizeof(buf), 0);
	}

	if (i < 0)
		error(1, errno, "failed to recv");

	return ev.data.fd;
}

__attribute__((used)) static void test(int *rcv_fds, int count, int proto)
{
	struct epoll_event ev;
	int epfd, i, test_fd;
	uint16_t test_family;
	socklen_t len;

	epfd = epoll_create(1);
	if (epfd < 0)
		error(1, errno, "failed to create epoll");

	ev.events = EPOLLIN;
	for (i = 0; i < count; ++i) {
		ev.data.fd = rcv_fds[i];
		if (epoll_ctl(epfd, EPOLL_CTL_ADD, rcv_fds[i], &ev))
			error(1, errno, "failed to register sock epoll");
	}

	send_from_v4(proto);

	test_fd = receive_once(epfd, proto);
	if (getsockopt(test_fd, SOL_SOCKET, SO_DOMAIN, &test_family, &len))
		error(1, errno, "failed to read socket domain");
	if (test_family != AF_INET)
		error(1, 0, "expected to receive on v4 socket but got v6 (%d)",
		      test_family);

	close(epfd);
}

int main(void)
{
	int rcv_fds[32], i;

	fprintf(stderr, "---- UDP IPv4 created before IPv6 ----\n");
	build_rcv_fd(AF_INET, SOCK_DGRAM, rcv_fds, 5);
	build_rcv_fd(AF_INET6, SOCK_DGRAM, &(rcv_fds[5]), 5);
	test(rcv_fds, 10, SOCK_DGRAM);
	for (i = 0; i < 10; ++i)
		close(rcv_fds[i]);

	fprintf(stderr, "---- UDP IPv6 created before IPv4 ----\n");
	build_rcv_fd(AF_INET6, SOCK_DGRAM, rcv_fds, 5);
	build_rcv_fd(AF_INET, SOCK_DGRAM, &(rcv_fds[5]), 5);
	test(rcv_fds, 10, SOCK_DGRAM);
	for (i = 0; i < 10; ++i)
		close(rcv_fds[i]);

	/* NOTE: UDP socket lookups traverse a different code path when there
	 * are > 10 sockets in a group.
	 */
	fprintf(stderr, "---- UDP IPv4 created before IPv6 (large) ----\n");
	build_rcv_fd(AF_INET, SOCK_DGRAM, rcv_fds, 16);
	build_rcv_fd(AF_INET6, SOCK_DGRAM, &(rcv_fds[16]), 16);
	test(rcv_fds, 32, SOCK_DGRAM);
	for (i = 0; i < 32; ++i)
		close(rcv_fds[i]);

	fprintf(stderr, "---- UDP IPv6 created before IPv4 (large) ----\n");
	build_rcv_fd(AF_INET6, SOCK_DGRAM, rcv_fds, 16);
	build_rcv_fd(AF_INET, SOCK_DGRAM, &(rcv_fds[16]), 16);
	test(rcv_fds, 32, SOCK_DGRAM);
	for (i = 0; i < 32; ++i)
		close(rcv_fds[i]);

	fprintf(stderr, "---- TCP IPv4 created before IPv6 ----\n");
	build_rcv_fd(AF_INET, SOCK_STREAM, rcv_fds, 5);
	build_rcv_fd(AF_INET6, SOCK_STREAM, &(rcv_fds[5]), 5);
	test(rcv_fds, 10, SOCK_STREAM);
	for (i = 0; i < 10; ++i)
		close(rcv_fds[i]);

	fprintf(stderr, "---- TCP IPv6 created before IPv4 ----\n");
	build_rcv_fd(AF_INET6, SOCK_STREAM, rcv_fds, 5);
	build_rcv_fd(AF_INET, SOCK_STREAM, &(rcv_fds[5]), 5);
	test(rcv_fds, 10, SOCK_STREAM);
	for (i = 0; i < 10; ++i)
		close(rcv_fds[i]);

	fprintf(stderr, "SUCCESS\n");
	return 0;
}

