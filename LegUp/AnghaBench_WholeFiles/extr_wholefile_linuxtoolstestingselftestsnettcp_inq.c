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
struct sockaddr_storage {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  s_addr; } ;
struct sockaddr_in6 {void* sin6_port; int /*<<< orphan*/  sin6_addr; int /*<<< orphan*/  sin6_family; void* sin_port; TYPE_1__ sin_addr; int /*<<< orphan*/  sin_family; } ;
struct sockaddr_in {void* sin6_port; int /*<<< orphan*/  sin6_addr; int /*<<< orphan*/  sin6_family; void* sin_port; TYPE_1__ sin_addr; int /*<<< orphan*/  sin_family; } ;
struct sockaddr {int dummy; } ;
struct msghdr {int msg_iovlen; char* msg_control; int msg_controllen; int msg_flags; struct iovec* msg_iov; scalar_t__ msg_namelen; int /*<<< orphan*/ * msg_name; } ;
struct iovec {char* iov_base; int iov_len; } ;
struct cmsghdr {scalar_t__ cmsg_level; scalar_t__ cmsg_type; } ;
typedef  int socklen_t ;
typedef  int /*<<< orphan*/  pthread_t ;
typedef  int /*<<< orphan*/  one ;
typedef  int /*<<< orphan*/  cmsgbuf ;
typedef  int /*<<< orphan*/  addr ;

/* Variables and functions */
 int /*<<< orphan*/  AF_INET ; 
 int /*<<< orphan*/  AF_INET6 ; 
 int BUF_SIZE ; 
 scalar_t__ CMSG_DATA (struct cmsghdr*) ; 
 struct cmsghdr* CMSG_FIRSTHDR (struct msghdr*) ; 
 struct cmsghdr* CMSG_NXTHDR (struct msghdr*,struct cmsghdr*) ; 
 int CMSG_SIZE ; 
 scalar_t__ EINTR ; 
 int /*<<< orphan*/  INADDR_LOOPBACK ; 
 int MSG_CTRUNC ; 
#define  PF_INET 129 
#define  PF_INET6 128 
 int /*<<< orphan*/  SOCK_STREAM ; 
 scalar_t__ SOL_SOCKET ; 
 scalar_t__ SOL_TCP ; 
 int /*<<< orphan*/  SO_REUSEADDR ; 
 scalar_t__ TCP_CM_INQ ; 
 int /*<<< orphan*/  TCP_INQ ; 
 int accept (int,struct sockaddr*,int*) ; 
 int addr_len ; 
 int /*<<< orphan*/  atoi (int /*<<< orphan*/ ) ; 
 int bind (int,struct sockaddr const*,int) ; 
 int /*<<< orphan*/  close (int) ; 
 int connect (int,struct sockaddr const*,int) ; 
 scalar_t__ errno ; 
 int /*<<< orphan*/  error (int,scalar_t__,char*) ; 
 int /*<<< orphan*/  exit (int) ; 
 int family ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  free (char*) ; 
 int getopt (int,char**,char*) ; 
 int /*<<< orphan*/  htonl (int /*<<< orphan*/ ) ; 
 void* htons (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  in6addr_loopback ; 
 int listen (int,int) ; 
 char* malloc (int) ; 
 int /*<<< orphan*/  memset (struct sockaddr_in6*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  optarg ; 
 int /*<<< orphan*/  perror (char*) ; 
 int /*<<< orphan*/  port ; 
 int /*<<< orphan*/  printf (char*) ; 
 scalar_t__ pthread_create (int /*<<< orphan*/ *,int /*<<< orphan*/ *,void* (*) (void*),void*) ; 
 int /*<<< orphan*/  pthread_exit (int /*<<< orphan*/ ) ; 
 int recvmsg (int,struct msghdr*,int /*<<< orphan*/ ) ; 
 int send (int,char*,int,int /*<<< orphan*/ ) ; 
 scalar_t__ setsockopt (int,scalar_t__,int /*<<< orphan*/ ,int*,int) ; 
 int /*<<< orphan*/  sleep (int) ; 
 int socket (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stderr ; 

__attribute__((used)) static void setup_loopback_addr(int family, struct sockaddr_storage *sockaddr)
{
	struct sockaddr_in6 *addr6 = (void *) sockaddr;
	struct sockaddr_in *addr4 = (void *) sockaddr;

	switch (family) {
	case PF_INET:
		memset(addr4, 0, sizeof(*addr4));
		addr4->sin_family = AF_INET;
		addr4->sin_addr.s_addr = htonl(INADDR_LOOPBACK);
		addr4->sin_port = htons(port);
		break;
	case PF_INET6:
		memset(addr6, 0, sizeof(*addr6));
		addr6->sin6_family = AF_INET6;
		addr6->sin6_addr = in6addr_loopback;
		addr6->sin6_port = htons(port);
		break;
	default:
		error(1, 0, "illegal family");
	}
}

void *start_server(void *arg)
{
	int server_fd = (int)(unsigned long)arg;
	struct sockaddr_in addr;
	socklen_t addrlen = sizeof(addr);
	char *buf;
	int fd;
	int r;

	buf = malloc(BUF_SIZE);

	for (;;) {
		fd = accept(server_fd, (struct sockaddr *)&addr, &addrlen);
		if (fd == -1) {
			perror("accept");
			break;
		}
		do {
			r = send(fd, buf, BUF_SIZE, 0);
		} while (r < 0 && errno == EINTR);
		if (r < 0)
			perror("send");
		if (r != BUF_SIZE)
			fprintf(stderr, "can only send %d bytes\n", r);
		/* TCP_INQ can overestimate in-queue by one byte if we send
		 * the FIN packet. Sleep for 1 second, so that the client
		 * likely invoked recvmsg().
		 */
		sleep(1);
		close(fd);
	}

	free(buf);
	close(server_fd);
	pthread_exit(0);
}

int main(int argc, char *argv[])
{
	struct sockaddr_storage listen_addr, addr;
	int c, one = 1, inq = -1;
	pthread_t server_thread;
	char cmsgbuf[CMSG_SIZE];
	struct iovec iov[1];
	struct cmsghdr *cm;
	struct msghdr msg;
	int server_fd, fd;
	char *buf;

	while ((c = getopt(argc, argv, "46p:")) != -1) {
		switch (c) {
		case '4':
			family = PF_INET;
			addr_len = sizeof(struct sockaddr_in);
			break;
		case '6':
			family = PF_INET6;
			addr_len = sizeof(struct sockaddr_in6);
			break;
		case 'p':
			port = atoi(optarg);
			break;
		}
	}

	server_fd = socket(family, SOCK_STREAM, 0);
	if (server_fd < 0)
		error(1, errno, "server socket");
	setup_loopback_addr(family, &listen_addr);
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR,
		       &one, sizeof(one)) != 0)
		error(1, errno, "setsockopt(SO_REUSEADDR)");
	if (bind(server_fd, (const struct sockaddr *)&listen_addr,
		 addr_len) == -1)
		error(1, errno, "bind");
	if (listen(server_fd, 128) == -1)
		error(1, errno, "listen");
	if (pthread_create(&server_thread, NULL, start_server,
			   (void *)(unsigned long)server_fd) != 0)
		error(1, errno, "pthread_create");

	fd = socket(family, SOCK_STREAM, 0);
	if (fd < 0)
		error(1, errno, "client socket");
	setup_loopback_addr(family, &addr);
	if (connect(fd, (const struct sockaddr *)&addr, addr_len) == -1)
		error(1, errno, "connect");
	if (setsockopt(fd, SOL_TCP, TCP_INQ, &one, sizeof(one)) != 0)
		error(1, errno, "setsockopt(TCP_INQ)");

	msg.msg_name = NULL;
	msg.msg_namelen = 0;
	msg.msg_iov = iov;
	msg.msg_iovlen = 1;
	msg.msg_control = cmsgbuf;
	msg.msg_controllen = sizeof(cmsgbuf);
	msg.msg_flags = 0;

	buf = malloc(BUF_SIZE);
	iov[0].iov_base = buf;
	iov[0].iov_len = BUF_SIZE / 2;

	if (recvmsg(fd, &msg, 0) != iov[0].iov_len)
		error(1, errno, "recvmsg");
	if (msg.msg_flags & MSG_CTRUNC)
		error(1, 0, "control message is truncated");

	for (cm = CMSG_FIRSTHDR(&msg); cm; cm = CMSG_NXTHDR(&msg, cm))
		if (cm->cmsg_level == SOL_TCP && cm->cmsg_type == TCP_CM_INQ)
			inq = *((int *) CMSG_DATA(cm));

	if (inq != BUF_SIZE - iov[0].iov_len) {
		fprintf(stderr, "unexpected inq: %d\n", inq);
		exit(1);
	}

	printf("PASSED\n");
	free(buf);
	close(fd);
	return 0;
}

