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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  uint64_t ;
struct sockaddr_un {scalar_t__* sun_path; int /*<<< orphan*/  sun_family; } ;
struct sockaddr {int dummy; } ;
typedef  int /*<<< orphan*/  fd_set ;

/* Variables and functions */
 int /*<<< orphan*/  AF_UNIX ; 
 scalar_t__ EINTR ; 
 scalar_t__ EPIPE ; 
 scalar_t__ FD_ISSET (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  FD_SET (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  FD_ZERO (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SOCK_STREAM ; 
 int close (int) ; 
 int connect (int,struct sockaddr*,int) ; 
 scalar_t__ errno ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  memset (struct sockaddr_un*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  perror (char*) ; 
 int /*<<< orphan*/  r_sys_perror (char*) ; 
 int recv (int,int /*<<< orphan*/ *,int /*<<< orphan*/  const,int /*<<< orphan*/ ) ; 
 int select (int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int send (int,int /*<<< orphan*/  const*,int /*<<< orphan*/  const,int /*<<< orphan*/ ) ; 
 int socket (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strncpy (scalar_t__*,char const*,int) ; 

__attribute__((used)) static void *iob_pipe_open(const char *path) {
	int sock;
	struct sockaddr_un sa;

	sock = socket (AF_UNIX, SOCK_STREAM, 0);
	if (sock == -1) {
		perror ("socket");
		return 0;
	}

	memset (&sa, 0, sizeof (struct sockaddr_un));

	sa.sun_family = AF_UNIX;
	strncpy (sa.sun_path, path, sizeof(sa.sun_path));
	sa.sun_path[sizeof (sa.sun_path) - 1] = 0;
	if (connect (sock, (struct sockaddr *) &sa, sizeof(struct sockaddr_un)) == -1) {
		perror ("connect");
		close (sock);
		return 0;
	}
	//struct timeval tv;
	//tv.tv_sec = 5;
	//tv.tv_usec = 0;
	//setsockopt (sock, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(struct timeval));
	return (void *) (size_t) sock;
}

__attribute__((used)) static int iob_pipe_close(void *p) {
	return close ((int) (size_t) p);
}

__attribute__((used)) static int iob_pipe_read(void *p, uint8_t *buf, const uint64_t count, const int timeout) {
	int result;
	fd_set readset;
	int fd = (int) (size_t) p;
	for (;;) {
		FD_ZERO (&readset);
		FD_SET (fd, &readset);
		result = select (fd + 1, &readset, NULL, NULL, NULL);
		if (result < 1) {
			if (errno == EINTR) continue;
			return -1;
		}
		if (FD_ISSET (fd, &readset)) {
			return  recv ((int) (size_t) p, buf, count, 0);
		}
	}
	return EINTR;
}

__attribute__((used)) static int iob_pipe_write(void *p, const uint8_t *buf, const uint64_t count, const int timeout) {
	int ret = send ((int) (size_t) p, buf, count, 0);
	if (ret < 1) {
		r_sys_perror ("iob_pipe_write, send");
		if (errno == EPIPE) {
			exit (1);
		}
	}
	return ret;
}

